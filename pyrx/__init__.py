__version__ = "2.1.11"

import warnings
from typing import TYPE_CHECKING

try:
    import PyRx as Rx  # isort: skip  # type: ignore
    import PyGe as Ge  # isort: skip  # type: ignore
    import PyGi as Gi  # isort: skip  # type: ignore
    import PyGs as Gs  # isort: skip  # type: ignore
    import PyDb as Db  # isort: skip  # type: ignore
    import PyAp as Ap  # isort: skip  # type: ignore
    import PyEd as Ed  # isort: skip  # type: ignore
    import PyPl as Pl  # isort: skip  # type: ignore
    import PySm as Sm  # isort: skip  # type: ignore
    import PyBr as Br  # isort: skip  # type: ignore
    import PyAx as Ax  # isort: skip  # type: ignore
except ModuleNotFoundError:
    warnings.warn("PyRx modules are not available, they must be invoked from a CAD application.")
    Ap = Br = Db = Ed = Ge = Gi = Gs = Pl = Rx = Sm = None

if TYPE_CHECKING:
    from . import PyAp as Ap  # noqa: F811  # type: ignore
    from . import PyBr as Br  # noqa: F811  # type: ignore
    from . import PyDb as Db  # noqa: F811  # type: ignore
    from . import PyEd as Ed  # noqa: F811  # type: ignore
    from . import PyGe as Ge  # noqa: F811  # type: ignore
    from . import PyGi as Gi  # noqa: F811  # type: ignore
    from . import PyGs as Gs  # noqa: F811  # type: ignore
    from . import PyPl as Pl  # noqa: F811  # type: ignore
    from . import PyRx as Rx  # noqa: F811  # type: ignore
    from . import PySm as Sm  # noqa: F811  # type: ignore
    from . import PyAx as Ax  # noqa: F811  # type: ignore

import importlib.util

if importlib.util.find_spec("win32com") is not None and Ap is not None:
    host = Ap.Application.hostAPI()
    ax_module_name = {
        "BRX24": "BxApp24",
        "BRX25": "BxApp25",
        "GRX24": "GxApp24",
        "GRX25": "GxApp25",
        "ZRX24": "ZxApp24",
        "ZRX25": "ZxApp25",
        "ARX24": "AxApp24",
        "ARX25": "AxApp25",
    }.get(host, None)
    if ax_module_name is not None:
        AxGen = importlib.import_module(ax_module_name)
    else:
        raise RuntimeError(f"Unrecognized host API: {host}")
else:
    AxGen = None
# TODO: TEST (Ax is ModuleType or None)

__all__ = ("Ap", "Br", "Db", "Ed", "Ge", "Gi", "Gs", "Pl", "Rx", "Sm", "Ax")
