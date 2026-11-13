"""PyRx module template with file logging (start your experiments from here).

Logs every PyRx callback (and the foo() hook) to a local file so the results
can be inspected without watching the AutoCAD command line.  The log path
comes from the AI_RUN_LOG environment variable (set by autocad_run.py),
falling back to ai_run.log next to this module.
"""
import datetime
import os
import traceback

from pyrx import Ap, Db, Ed, Ge

LOG_PATH = os.environ.get("AI_RUN_LOG") or os.path.join(
    os.path.dirname(os.path.abspath(__file__)), "ai_run.log"
)


def log(*args):
    """Write one line to the log file and also print it to the AutoCAD command line.

    Accepts any number of values (or a single pre-formatted string);
    multiple values are joined with ", ", e.g. log(1, 2.0) or log((1, 2.0)).
    """
    msg = ", ".join(str(a) for a in args)
    line = "[%s] %s" % (datetime.datetime.now().strftime("%H:%M:%S.%f")[:-3], msg)
    try:
        with open(LOG_PATH, "a", encoding="utf-8") as f:
            f.write(line + "\n")
            f.flush()
            os.fsync(f.fileno())
    except Exception:
        pass
    print(line)


try:
    log("module loaded: %s" % __file__)
except Exception:
    pass


def OnPyInitApp():
    log("OnPyInitApp")


def OnPyUnloadApp():
    log("OnPyUnloadApp")


def OnPyReload():
    log("OnPyReload")


def OnPyLoadDwg():
    log("OnPyLoadDwg")
    foo()


def OnPyUnloadDwg():
    log("OnPyUnloadDwg")


def foo():
    """Placeholder hook called from OnPyLoadDwg — just proves it was called."""
    try:
        log("foo")
    except Exception:
        log(traceback.format_exc())
