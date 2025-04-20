import types
from typing import Iterable

from pyrx.doc_utils.pyi_gen import BoostPythonTypes, PyBoostModule

__isbrx__ = False
from pyrx import Ap, Ax, Br, Db, Ed, Ge, Gi, Gs, Pl, Rx, Sm

if "BRX" in Ap.Application.hostAPI():
    from pyrx import Bim, Brx, Cv

    __isbrx__ = True


_ORIG_TO_ALIAS_MODULE_NAMES: dict[str, str] = {
    Ap.__name__: "Ap",
    Ax.__name__: "Ax",
    Br.__name__: "Br",
    Db.__name__: "Db",
    Ed.__name__: "Ed",
    Ge.__name__: "Ge",
    Gi.__name__: "Gi",
    Gs.__name__: "Gs",
    Pl.__name__: "Pl",
    Rx.__name__: "Rx",
    Sm.__name__: "Sm",
}
if __isbrx__:
    _ORIG_TO_ALIAS_MODULE_NAMES.update(
        {
            Cv.__name__: "Cv",
            Bim.__name__: "Bim",
            Brx.__name__: "Brx",
        }
    )


def build_py_boost_modules(modules: Iterable[types.ModuleType]) -> list[PyBoostModule]:
    return [
        PyBoostModule(name=_ORIG_TO_ALIAS_MODULE_NAMES[module.__name__], orig_name=module.__name__)
        for module in modules
    ]


RX_BOOST_TYPES = BoostPythonTypes(
    enum=Db.OpenMode.__base__,
    instance=Db.Database.__base__.__base__,
    function=type(Db.curDb),
    static_property=type(Ge.Point3d.__dict__["kOrigin"]),
)
