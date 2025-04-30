from __future__ import annotations

import logging
import subprocess
import traceback
from pathlib import Path
from types import ModuleType
from typing import Iterable

from pyrx import Ap, Ax, Br, Db, Ed, Ge, Gi, Gs, Pl, Rx, Sm, reload
from pyrx.doc_utils.misc import DocstringsManager, ReturnTypesManager
from pyrx.doc_utils.pyi_gen import gen_pyi
from pyrx.doc_utils.rx_meta import RX_BOOST_TYPES, build_py_boost_modules

if "BRX" in Ap.Application.hostAPI():
    from pyrx import Bim, Brx, Cv

reload("pyrx")


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
    all_py_rx_modules = build_py_boost_modules(all_modules)
    docstrings = DocstringsManager.from_json()
    return_types = ReturnTypesManager.from_json()
    for module in all_modules:
        res = gen_pyi(
            module=module,
            all_modules=all_py_rx_modules,
            docstrings=docstrings,
            return_types=return_types,
            boost_types=RX_BOOST_TYPES,
        ).gen()

        pyi_file = PYI_DIR / f"{module.__name__}.pyi"

        def write_pyi():
            with open(pyi_file, "w", encoding="utf-8") as f:
                f.write(res)

        write_pyi()

        try:
            subprocess.run(
                ["ruff", "check", "--fix", str(pyi_file)],
                check=True,
                capture_output=True,
                text=True,
                creationflags=subprocess.CREATE_NO_WINDOW,
            )
        except subprocess.CalledProcessError as e:
            logging.error(f"Ruff check failed:\n{e.stderr}\n{e.stdout}")
            write_pyi()

        try:
            subprocess.run(
                ["ruff", "format", str(pyi_file)],
                check=True,
                capture_output=True,
                text=True,
                creationflags=subprocess.CREATE_NO_WINDOW,
            )
        except subprocess.CalledProcessError as e:
            logging.error(f"Ruff format failed:\n{e.stderr}\n{e.stdout}")
            write_pyi()

        try:
            subprocess.run(
                [
                    "mypy",
                    str(pyi_file),
                    "--disallow-any-generics",
                    "--ignore-missing-imports",
                    "--disable-error-code",
                    "overload-cannot-match",  # TODO: we need to look into this, I think
                    # the signature ``def meth(self, *args) -> None: ...`` is unnecessary
                ],
                check=True,
                capture_output=True,
                text=True,
                creationflags=subprocess.CREATE_NO_WINDOW,
            )
        except subprocess.CalledProcessError as e:
            logging.error(f"Mypy check failed:\n{e.stderr}\n{e.stdout}")


def runBRX() -> None:
    _run(
        all_modules=(Ap, Ax, Br, Db, Ed, Ge, Gi, Gs, Pl, Rx, Sm, Cv, Bim, Brx),
        log_filename="gen_pyi_brx.log",
    )


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
