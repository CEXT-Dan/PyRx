import json
import queue
import threading
import traceback
from openai import OpenAI
from pyrx import Ap, Db, Ed, Ge

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


# --- CAD Tools ---

def get_drawing_info():
    db = Db.curDb()
    ms = Db.BlockTableRecord(db.modelSpaceId(), Db.OpenMode.kForRead)
    entity_counts = {}
    for obj_id in ms.objectIds():
        ent = Db.Entity(obj_id)
        etype = ent.isA().name()
        entity_counts[etype] = entity_counts.get(etype, 0) + 1
    return {"modelspace_entity_counts": entity_counts}


def create_circle(cx: float, cy: float, radius: float, layer: str = "0"):
    db = Db.curDb()
    ms = Db.BlockTableRecord(db.modelSpaceId(), Db.OpenMode.kForWrite)
    circle = Db.Circle(Ge.Point3d(cx, cy, 0.0), Ge.Vector3d.kZAxis, radius)
    circle.setLayer(layer)
    obj_id = ms.appendAcDbEntity(circle)
    return {"status": "created", "type": "Circle", "handle": str(obj_id.handle())}


def create_line(x1: float, y1: float, x2: float, y2: float, layer: str = "0"):
    db = Db.curDb()
    ms = Db.BlockTableRecord(db.modelSpaceId(), Db.OpenMode.kForWrite)
    line = Db.Line(Ge.Point3d(x1, y1, 0.0), Ge.Point3d(x2, y2, 0.0))
    line.setLayer(layer)
    obj_id = ms.appendAcDbEntity(line)
    return {"status": "created", "type": "Line", "handle": str(obj_id.handle())}


def create_cylinder(
    cx: float,
    cy: float,
    cz: float,
    radius: float,
    height: float,
    layer: str = "0",
):
    r = float(radius)
    h = float(height)
    if r <= 0.0 or h <= 0.0:
        raise ValueError("Radius and height must be positive.")

    db = Db.curDb()
    solid = Db.Solid3d()
    solid.setDatabaseDefaults(db)
    solid.createFrustum(h, r, r, r)

    # Translate from origin (0,0,0) to (cx, cy, cz)
    vec = Ge.Point3d(float(cx), float(cy), float(cz)) - Ge.Point3d.kOrigin
    solid.transformBy(Ge.Matrix3d.translation(vec))
    solid.setLayer(layer)

    obj_id = db.addToCurrentspace(solid)
    return {
        "status": "created",
        "type": "Solid3d",
        "handle": str(obj_id.handle()),
        "is_null": solid.isNull(),
    }


TOOL_FUNCTIONS = {
    "create_cylinder": create_cylinder,
    "get_drawing_info": get_drawing_info,
    "create_circle": create_circle,
    "create_line": create_line,
}

TOOL_SCHEMAS = [
    {
        "type": "function",
        "function": {
            "name": "create_cylinder",
            "description": (
                "Create a 3D solid cylinder aligned with the Z-axis. "
                "(cx, cy, cz) is the geometric center of the cylinder."
            ),
            "parameters": {
                "type": "object",
                "properties": {
                    "cx": {"type": "number"},
                    "cy": {"type": "number"},
                    "cz": {"type": "number"},
                    "radius": {"type": "number"},
                    "height": {"type": "number"},
                    "layer": {"type": "string"},
                },
                "required": ["cx", "cy", "cz", "radius", "height"],
            },
        },
    },
    {
        "type": "function",
        "function": {
            "name": "get_drawing_info",
            "description": "Inspect entity counts in the active AutoCAD modelspace.",
            "parameters": {"type": "object", "properties": {}, "required": []},
        },
    },
    {
        "type": "function",
        "function": {
            "name": "create_circle",
            "description": "Draw a 2D circle in AutoCAD modelspace.",
            "parameters": {
                "type": "object",
                "properties": {
                    "cx": {"type": "number", "description": "Center X coordinate"},
                    "cy": {"type": "number", "description": "Center Y coordinate"},
                    "radius": {"type": "number", "description": "Circle radius"},
                    "layer": {"type": "string", "description": "Target layer name"},
                },
                "required": ["cx", "cy", "radius"],
            },
        },
    },
    {
        "type": "function",
        "function": {
            "name": "create_line",
            "description": "Draw a 2D line segment between two points in AutoCAD.",
            "parameters": {
                "type": "object",
                "properties": {
                    "x1": {"type": "number"},
                    "y1": {"type": "number"},
                    "x2": {"type": "number"},
                    "y2": {"type": "number"},
                    "layer": {"type": "string"},
                },
                "required": ["x1", "y1", "x2", "y2"],
            },
        },
    },
]


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
