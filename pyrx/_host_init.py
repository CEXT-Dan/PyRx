from __future__ import annotations

import collections.abc as c
import logging
import os
import typing as t
from pathlib import Path

from pyrx import Ap, Ed, command, reload
from pyrx.config import get_pyrx_settings
from pyrx.PyRxDebug import startListener

logger = logging.getLogger(__name__)


def find_pyrx_onload_debug() -> c.Generator[Path, None, None]:
    pyrx_module_dir = Path(Ap.Application.getPyRxModulePath())
    yield pyrx_module_dir / "pyrx_onload.py"  # only .py for debug


def find_pyrx_onload_local() -> c.Generator[Path, None, None]:
    if (onload_path := get_pyrx_settings().onload_path) is not None:
        if onload_path.suffix in (".py", ".pyc"):
            yield onload_path
        else:
            logger.warning(
                f"Skipping pyrx onload path {onload_path} as it is not a .py or .pyc file"
            )
    if onload_path := Ed.Core.findFile("pyrx_onload.pyc"):
        yield Path(onload_path)
    if onload_path := Ed.Core.findFile("pyrx_onload.py"):
        yield Path(onload_path)


def find_pyrx_onload_user() -> c.Generator[Path, None, None]:
    if (appdata := os.getenv("APPDATA", None)) is not None:
        appdata_path = Path(appdata) / "pyrx"
        yield appdata_path / "pyrx_onload.pyc"
        yield appdata_path / "pyrx_onload.py"
    else:
        logger.warning("APPDATA environment variable not found. Skipping user onload path.")


def load_pyrx_onload(onload_path: Path) -> None:
    Ap.Application.loadPythonModule(str(onload_path))

def pyrx_onload() -> None:
    for onload_path in find_pyrx_onload_debug():
        if onload_path.exists():
            # debug onload is always loading, if exists
            load_pyrx_onload(onload_path)
            break
    for find_pyrx_onload in (find_pyrx_onload_local, find_pyrx_onload_user):
        # pyrx_settings can be modified by onload file so there is no cached
        pyrx_settings = get_pyrx_settings()
        if pyrx_settings.disable_onload:
            logger.debug("pyrx onload is disabled")
            return
        for onload_path in find_pyrx_onload():
            if onload_path.exists():
                if not onload_path.is_file():
                    logger.warning(f"Skipping pyrx onload path {onload_path} as it is not a file")
                else:
                    logger.info(f"Loading pyrx onload file {onload_path}")
                    try:
                        load_pyrx_onload(onload_path)
                    except BaseException:
                        logger.exception(f"Failed to load pyrx onload file {onload_path}")
                break

wxRxApp = None

def main() -> None:
    # init wxApp
    global wxRxApp
    wxRxApp = Ap.Application.wxApp()
    
    # reload all pyrx modules if this module is reloaded
    reload("pyrx")
    # add PYDEBUG command
    command(startListener, name="PYDEBUG")
    # load pyrx onload file
    pyrx_onload()
    # pyrx_settings can be modified by onload file so there is getting it again
    pyrx_settings = get_pyrx_settings()
    # load REPLs
    if pyrx_settings.load_repl:
        import pyrx.repl.repl_cmds  # noqa


if __name__ == "_host_init":  # loaded by PyRxCore
    main()
else:
    import warnings

    warnings.warn(
        "pyrx._host_init should not be imported directly. It is loaded internally by PyRxCore.",
    )
