from __future__ import annotations

import threading

from pyrx import command, reload
from pyrx.repl.stdlibrepl import run_stdlib_repl

reload("pyrx")


@command
def pystdrepl():
    thread = threading.Thread(target=run_stdlib_repl)
    thread.start()


try:
    from pyrx.repl.ptrepl import run_ptpython_repl
except ImportError:
    import importlib.util

    if importlib.util.find_spec("ptpython") is not None:
        raise

    @command
    def pyptrepl():
        print("\nptpython is not installed. Please run `pip install ptpython`.\n")
else:

    @command
    def pyptrepl():
        thread = threading.Thread(target=run_ptpython_repl)
        thread.start()
