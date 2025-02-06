import logging
import traceback
from pathlib import Path

from pyrx import Ap, Ax, Br, Db, Ed, Ge, Gi, Gs, Pl, Rx, Sm
from pyrx.doc_utils.misc import DocstringsManager, ReturnTypesManager
from pyrx.doc_utils.pyi_gen import gen_pyi

if "BRX" in Ap.Application.hostAPI():
    from pyrx import Cv
    from pyrx import Bim
    from pyrx import Brx


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


def runBRX():
    logging.basicConfig(filename="gen_pyi_brx.log", filemode="w", force=True)
    PYI_DIR = Path(__file__).parent / "pyrx"
    for module in (Ap, Br, Db, Ed, Ge, Gi, Gs, Pl, Rx, Sm, Ax, Cv, Bim, Brx):
        res = gen_pyi(
            module=module,
            all_modules=(Ap, Br, Db, Ed, Ge, Gi, Gs, Pl, Rx, Sm, Ax, Cv, Bim, Brx),
            docstrings=DocstringsManager.from_json(),
            return_types=ReturnTypesManager.from_json(),
        ).gen()
        with open(PYI_DIR / f"{module.__name__}.pyi", "w", encoding="utf-8") as f:
            f.write(res)


def runARX():
    logging.basicConfig(filename="gen_pyi.log", filemode="w", force=True)
    PYI_DIR = Path(__file__).parent / "pyrx"
    for module in (Ap, Ax, Br, Db, Ed, Ge, Gi, Gs, Pl, Rx, Sm):
        res = gen_pyi(
            module=module,
            all_modules=(Ap, Br, Db, Ed, Ge, Gi, Gs, Pl, Rx, Sm, Ax),
            docstrings=DocstringsManager.from_json(),
            return_types=ReturnTypesManager.from_json(),
        ).gen()
        with open(PYI_DIR / f"{module.__name__}.pyi", "w", encoding="utf-8") as f:
            f.write(res)


def OnPyReload():
    try:
        import sys

        to_remove = tuple(name for name in sys.modules if name.startswith("pyrx"))
        for name in to_remove:
            sys.modules.pop(name)
    except Exception:
        traceback.print_exc()
