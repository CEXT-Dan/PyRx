__version__ = "2.2.13.4419"

import importlib.util
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

    try:
        import PyBrxCv as Cv  # isort: skip  # type: ignore
    except ModuleNotFoundError:
        Cv = None
    try:
        import PyBrxBim as Bim  # isort: skip  # type: ignore
    except ModuleNotFoundError:
        Bim = None
    try:
        import PyBrx as Brx  # isort: skip  # type: ignore
    except ModuleNotFoundError:
        Brx = None

except ModuleNotFoundError:
    warnings.warn("PyRx modules are not available, they must be invoked from a CAD application.")
    Ap = Ax = Bim = Br = Brx = Cv = Db = Ed = Ge = Gi = Gs = Pl = Rx = Sm = None

if TYPE_CHECKING:
    from . import PyAp as Ap  # noqa: F811  # type: ignore
    from . import PyAx as Ax  # noqa: F811  # type: ignore
    from . import PyBr as Br  # noqa: F811  # type: ignore
    from . import PyDb as Db  # noqa: F811  # type: ignore
    from . import PyEd as Ed  # noqa: F811  # type: ignore
    from . import PyGe as Ge  # noqa: F811  # type: ignore
    from . import PyGi as Gi  # noqa: F811  # type: ignore
    from . import PyGs as Gs  # noqa: F811  # type: ignore
    from . import PyPl as Pl  # noqa: F811  # type: ignore
    from . import PyRx as Rx  # noqa: F811  # type: ignore
    from . import PySm as Sm  # noqa: F811  # type: ignore

    if importlib.util.find_spec("PyBrxCv") is not None:
        from . import PyBrxCv as Cv  # noqa: F811  # type: ignore
    if importlib.util.find_spec("PyBrxBim") is not None:
        from . import PyBrxBim as Bim  # noqa: F811  # type: ignore
    if importlib.util.find_spec("PyBrx") is not None:
        from . import PyBrx as Brx  # noqa: F811  # type: ignore

from .commands import command
from .utils.reload import reload

__all__ = (
    "Ap",
    "Ax",
    "Bim",
    "Br",
    "Brx",
    "Cv",
    "Db",
    "Ed",
    "Ge",
    "Gi",
    "Gs",
    "Pl",
    "Rx",
    "Sm",
    "command",
    "reload",
)

