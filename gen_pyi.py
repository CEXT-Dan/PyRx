from __future__ import annotations

import logging
import subprocess
import traceback
from pathlib import Path
from types import ModuleType
from typing import Iterable

from pyrx import Ap, Ax, Br, Db, Ed, Ge, Gi, Gs, Pl, Rx, Sm
from pyrx.doc_utils.misc import DocstringsManager, ReturnTypesManager
from pyrx.doc_utils.pyi_gen import gen_pyi
from pyrx.doc_utils.rx_meta import PyRxModule

if "BRX" in Ap.Application.hostAPI():
    from pyrx import Bim, Brx, Cv


def PyRxCmd_gen_pyi_brx():
    try:
        runBRX()
    except Exception:
        traceback.print_exc()


def PyRxCmd_gen_pyi():
    try:
        runARX()
    except Exception:
        traceback.print_exc()


def _run(all_modules: Iterable[ModuleType], log_filename: str = "gen_pyi.log") -> None:
    logging.basicConfig(filename=log_filename, filemode="w", force=True)
    PYI_DIR = Path(__file__).parent / "pyrx"
    all_py_rx_modules = [PyRxModule(module) for module in all_modules]
    for module in all_modules:
        res = gen_pyi(
            module=module,
            all_modules=all_py_rx_modules,
            docstrings=DocstringsManager.from_json(),
            return_types=ReturnTypesManager.from_json(),
        ).gen()
        with open(PYI_DIR / f"{module.__name__}.pyi", "w", encoding="utf-8") as f:
            f.write(res)

    subprocess.run(["ruff", "check", "--fix", "pyrx"], check=True)


def runBRX() -> None:
    _run(all_modules=(Ap, Br, Db, Ed, Ge, Gi, Gs, Pl, Rx, Sm, Ax, Cv, Bim, Brx), log_filename="gen_pyi_brx.log")


def runARX() -> None:
    _run(all_modules=(Ap, Ax, Br, Db, Ed, Ge, Gi, Gs, Pl, Rx, Sm))


def OnPyReload():
    try:
        import sys

        to_remove = tuple(name for name in sys.modules if name.startswith("pyrx"))
        for name in to_remove:
            sys.modules.pop(name)
    except Exception:
        traceback.print_exc()
