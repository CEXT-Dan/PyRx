from __future__ import annotations

import collections.abc as c
import logging
import os
import traceback
from pathlib import Path

from pyrx import Ap, Ed, command, reload
from pyrx.config import get_pyrx_settings
from pyrx.PyRxDebug import startListener

logger = logging.getLogger(__name__)


class _PyRxOnload:
    """Helper class to load PyRx onload files"""

    def find_pyrx_base_onload(self) -> c.Generator[Path, None, None]:
        if (appdata := os.getenv("APPDATA", None)) is not None:
            appdata_path = Path(appdata) / "pyrx"
            yield appdata_path / "pyrx_base_onload.pyc"
            yield appdata_path / "pyrx_base_onload.py"
        else:
            logger.warning("APPDATA environment variable not found. Skipping base onload path.")

    def find_pyrx_onload_debug(self) -> c.Generator[Path, None, None]:
        pyrx_module_dir = Path(Ap.Application.getPyRxModulePath())
        yield pyrx_module_dir / "pyrx_onload.py"  # only .py for debug

    def find_pyrx_onload(self) -> c.Generator[Path, None, None]:
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

    def load_module(self, onload_path: Path) -> None:
        Ap.Application.loadPythonModule(str(onload_path.absolute()))

    def try_load_pyrx_onload(self, onload_path: Path) -> bool:
        if not onload_path.exists():
            return False
        if not onload_path.is_file():
            logger.warning(f"Skipping pyrx onload path {onload_path} as it is not a file")
        else:
            logger.info(f"Loading pyrx onload file {onload_path}")
            try:
                self.load_module(onload_path)
            except BaseException:
                logger.exception(f"Failed to load pyrx onload file {onload_path}")
        return True

    def load(self) -> None:
        pyrx_settings = get_pyrx_settings()
        if pyrx_settings.disable_onload:
            logger.debug("pyrx onload is disabled")
        else:
            for onload_path in self.find_pyrx_base_onload():
                if self.try_load_pyrx_onload(onload_path):
                    break
        for onload_path in self.find_pyrx_onload_debug():
            if self.try_load_pyrx_onload(onload_path):
                # debug onload is always loading, if exists
                return  # if debug onload is found, stop searching
        # pyrx_settings can be modified by onload file so there is no cached
        pyrx_settings = get_pyrx_settings()
        if pyrx_settings.disable_onload:
            logger.debug("pyrx onload is disabled")
        else:
            for onload_path in self.find_pyrx_onload():
                if self.try_load_pyrx_onload(onload_path):
                    break


def pyrx_onload() -> None:
    """Load pyrx onload files"""
    onload = _PyRxOnload()
    onload.load()


def main() -> None:
    try:
        # reload all pyrx modules if this module is reloaded
        reload("pyrx")
        # add PYDEBUG command
        command(startListener, name="PYDEBUG")
        # load pyrx onload files
        pyrx_onload()
        # pyrx_settings can be modified by onload file so there is getting it again
        pyrx_settings = get_pyrx_settings()
        if (title := pyrx_settings.top_window_title) is not None:
            from pyrx.utils.wx import set_top_window_title

            set_top_window_title(title)

        # load PyRx commands
        import pyrx._commands  # noqa: F401

        # load REPLs
        import pyrx.repl.repl_cmds  # noqa: F401

    except Exception as e:
        if e.__traceback__ is None:
            traceback.print_exception(e)
        else:
            traceback.print_exception(e.with_traceback(e.__traceback__.tb_next))


if __name__ == "_host_init":  # loaded by PyRxCore
    main()
else:
    import warnings

    warnings.warn(
        "pyrx._host_init should not be imported directly. It is loaded internally by PyRxCore.",
    )
