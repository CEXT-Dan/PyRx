from __future__ import annotations

import sys
import typing as t
from contextlib import contextmanager

import win32gui

from pyrx import Ap, Db, Ed
from pyrx.ap.utils import call_after, call_in_main_thread  # noqa
from pyrx.console import redirect_stderr, redirect_stdin, redirect_stdout

# Is it possible to handle the console close signal and prevent the host from closing?
WARNING_CLOSE_CONSOLE = (
    "**********************************************************************\n"
    "*  Warning: Do not close the console window, this will immediately   *\n"
    "*  close the host application. First exit the REPL.                  *\n"
    "**********************************************************************"
)


class ReplMixin:
    def __init__(
        self,
        stdin: t.TextIO | None = None,
        stdout: t.TextIO | None = None,
        stderr: t.TextIO | None = None,
    ) -> None:
        self.stdin = stdin or sys.stdin
        self.stdout = stdout or sys.stdout
        self.stderr = stderr or sys.stderr

    @contextmanager
    def redirect(self):
        with (
            redirect_stdin(self.stdin),
            redirect_stdout(self.stderr),
            redirect_stderr(self.stdout),
        ):
            yield

    @contextmanager
    def activate_host_window(self) -> t.Iterator[None]:
        active_hwnd = win32gui.GetForegroundWindow()
        host_hwnd = Ap.Application.mainWnd()
        change = not host_hwnd == active_hwnd
        if change:
            win32gui.SetForegroundWindow(host_hwnd)
        try:
            yield
        finally:
            if change:
                win32gui.SetForegroundWindow(active_hwnd)

    @property
    def default_namespace(self) -> dict[str, t.Any]:
        import builtins

        from pyrx import Ap, Ax, Bim, Br, Brx, Cv, Db, Ed, Ge, Gi, Gs, Pl, Rx, Sm

        return {
            "__name__": "__main__",
            "__package__": None,
            "__doc__": None,
            "__builtins__": builtins,
            "Ap": Ap,
            "Ax": Ax,
            "Bim": Bim,
            "Br": Br,
            "Brx": Brx,
            "Cv": Cv,
            "Db": Db,
            "Ed": Ed,
            "Ge": Ge,
            "Gi": Gi,
            "Gs": Gs,
            "Pl": Pl,
            "Rx": Rx,
            "Sm": Sm,
            "curdb": curdb,
            "entsel": entsel,
            "select": select,
        }


# shortcuts for the REPL

curdb = Db.curDb


def entsel() -> None | Db.ObjectId:
    status, id_, _ = Ed.Editor.entSel("Select: ")
    if not status == Ed.PromptStatus.eOk:
        return None
    return id_


def select() -> None | list[Db.ObjectId]:
    status, sset = Ed.Editor.select()
    if not status == Ed.PromptStatus.eOk:
        return None
    return sset.objectIds()
