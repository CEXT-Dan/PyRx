import importlib.util

import PyAp as Ap  # noqa: F401
import PyAx as Ax  # noqa: F401
import PyBr as Br  # noqa: F401
import PyDb as Db  # noqa: F401
import PyEd as Ed  # noqa: F401
import PyGe as Ge  # noqa: F401
import PyGi as Gi  # noqa: F401
import PyGs as Gs  # noqa: F401
import PyPl as Pl  # noqa: F401
import PySm as Sm  # noqa: F401

import PyRx as Rx  # noqa: F401

if importlib.util.find_spec("PyBrxCv") is not None:
    import PyBrxCv as Cv  # noqa: F401

if importlib.util.find_spec("PyBrxBim") is not None:
    import PyBrxBim as Bim  # noqa: F401

if importlib.util.find_spec("PyBrx") is not None:
    import PyBrx as Brx  # noqa: F401

# this module is to hide Pylance 'module not found' warnings
# Pylance cant read Python embedded in C++
