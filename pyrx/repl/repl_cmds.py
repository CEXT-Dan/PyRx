from __future__ import annotations

import threading

from pyrx import Ap, command, reload
from pyrx.repl.stdlibrepl import run_stdlib_repl

reload("pyrx")


@command
def pystdrepl():
    thread = threading.Thread(target=run_stdlib_repl)
    thread.start()
    if not Ap.fireOnbeginConsole():
        raise

@command
def pyptrepl():
    try:
        from pyrx.repl.ptrepl import run_ptpython_repl
    except ImportError:
        import importlib.util

        if importlib.util.find_spec("ptpython") is not None:
            raise
        print("\nptpython is not installed. Please run `pip install ptpython`.\n")
    else:
        thread = threading.Thread(target=run_ptpython_repl)
        thread.start()
        if not Ap.fireOnbeginConsole():
            raise

