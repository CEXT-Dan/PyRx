from pyrx.doc_utils.pyi_gen import PyBoostModule

__isbrx__ = False
from pyrx import Ap, Ax, Br, Db, Ed, Ge, Gi, Gs, Pl, Rx, Sm

if "BRX" in Ap.Application.hostAPI():
    from pyrx import Bim, Brx, Cv

    __isbrx__ = True


class PyRxModule(PyBoostModule):
    Ap = "Ap", Ap, "PyAp"
    Br = "Br", Br, "PyBr"
    Db = "Db", Db, "PyDb"
    Ed = "Ed", Ed, "PyEd"
    Ge = "Ge", Ge, "PyGe"
    Gi = "Gi", Gi, "PyGi"
    Gs = "Gs", Gs, "PyGs"
    Pl = "Pl", Pl, "PyPl"
    Rx = "Rx", Rx, "PyRx"
    Sm = "Sm", Sm, "PySm"
    Ax = "Ax", Ax, "PyAx"
    if __isbrx__:
        Cv = "Cv", Cv, "PyBrxCv"
        Bim = "Bim", Bim, "PyBrxBim"
        Brx = "Brx", Brx, "PyBrx"
