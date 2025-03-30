from __future__ import annotations

import os

from pyrx import command, reload
from pyrx.PyRxDebug import startListener

reload("pyrx")


command(startListener, name="PYDEBUG")

if os.getenv("PYRX_LOAD_REPL", None) == "1":
    import pyrx.repl.repl_cmds  # noqa
