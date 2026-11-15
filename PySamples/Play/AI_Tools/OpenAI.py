import json
import os
import queue
import sys
import threading
import traceback
import importlib
from openai import OpenAI
from pyrx import Ap, Ed

import ai_tools
from ai_tools import TOOL_FUNCTIONS, TOOL_SCHEMAS

client = OpenAI(base_url="http://localhost:1234/v1", api_key="lm-studio")
LM_STUDIO_MODEL = "local-model"

_tool_queue: queue.Queue["ToolCallTask"] = queue.Queue()


class ToolCallTask:
    def __init__(self, func, args=(), kwargs=None):
        self.func = func
        self.args = args
        self.kwargs = kwargs or {}
        self.done = threading.Event()
        self.result = None
        self.error = None

    def execute(self):
        try:
            doc = Ap.DocManager().mdiActiveDocument()
            if doc is None:
                raise RuntimeError("No active AutoCAD document.")
            autolock = doc.autoLock()
            self.result = self.func(*self.args, **self.kwargs)
        except Exception as exc:
            self.error = exc
        finally:
            self.done.set()


def dispatch_to_acad(func, *args, **kwargs):
    task = ToolCallTask(func, args=args, kwargs=kwargs)
    _tool_queue.put(task)
    task.done.wait()
    if task.error:
        raise task.error
    return task.result


def _app_context_worker(task: ToolCallTask):
    if task is not None:
        task.execute()


def onIdle():
    if _tool_queue.empty():
        return
    try:
        man = Ap.DocManager()
        while not _tool_queue.empty():
            task = _tool_queue.get_nowait()
            man.executeInApplicationContext(_app_context_worker, task)
    except Exception as err:
        traceback.print_exception(err)


def OnPyInitApp():
    Ap.Application.registerOnIdleWinMsg(onIdle)


def OnPyUnloadApp():
    Ap.Application.removeOnIdleWinMsg(onIdle)


def OnPyReload():
    global TOOL_FUNCTIONS, TOOL_SCHEMAS
    importlib.reload(ai_tools)
    TOOL_FUNCTIONS = ai_tools.TOOL_FUNCTIONS
    TOOL_SCHEMAS = ai_tools.TOOL_SCHEMAS


# --- LM Studio Agent Loop ---
def _run_lm_studio_agent(user_prompt: str):
    messages = [
        {
            "role": "system",
            "content": "You are an AutoCAD 3D assistant. Use create_cylinder to build 3D cylinders.",
        },
        {"role": "user", "content": user_prompt},
    ]

    try:
        for _ in range(5):
            response = client.chat.completions.create(
                model=LM_STUDIO_MODEL,
                messages=messages,
                tools=TOOL_SCHEMAS,
                tool_choice="auto",
                temperature=0.1,
            )

            # Index [0] on response.choices
            msg = response.choices[0].message
            messages.append(msg)

            if not msg.tool_calls:
                print(f"\n[LM Studio] {msg.content}")
                return

            for tool_call in msg.tool_calls:
                fn_name = tool_call.function.name
                fn_args = json.loads(tool_call.function.arguments or "{}")
                print(f"\n[AI Tool Call] {fn_name}({fn_args})")

                if fn_name in TOOL_FUNCTIONS:
                    try:
                        output = dispatch_to_acad(TOOL_FUNCTIONS[fn_name], **fn_args)
                    except Exception as tool_err:
                        output = {"error": str(tool_err)}
                else:
                    output = {"error": f"Unknown tool: {fn_name}"}

                print(f"[AI Tool Output] {output}")
                messages.append(
                    {
                        "role": "tool",
                        "tool_call_id": tool_call.id,
                        "content": json.dumps(output),
                    }
                )
    except Exception:
        traceback.print_exc()


@Ap.Command("LMAI")
def cmd_lmai():
    ps, prompt = Ed.Editor.getString(1, "\nAsk LM Studio: ")
    if ps == Ed.PromptStatus.eOk and prompt:
        threading.Thread(target=_run_lm_studio_agent, args=(prompt,), daemon=True).start()
