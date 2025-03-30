from __future__ import annotations
from typing import overload, Any, ClassVar, Self, TypeVar
from pyrx import Ap as PyAp
from pyrx import Br as PyBr
from pyrx import Db as PyDb
from pyrx import Ed as PyEd
from pyrx import Ge as PyGe
from pyrx import Gi as PyGi
from pyrx import Gs as PyGs
from pyrx import Pl as PyPl
from pyrx import Rx as PyRx
from pyrx import Sm as PySm
from pyrx import Ax as PyAx
from pyrx import Cv as PyBrxCv
from pyrx import Bim as PyBrxBim
from pyrx import Brx as PyBrx
import wx

T = TypeVar("T")

class _BoostPythonEnumMeta(type):
    # This is not a real class, it is just for better type hints

    def __call__(cls: type[T], value: int) -> T: ...

class _BoostPythonEnum(int, metaclass=_BoostPythonEnumMeta):
    # This is not a real class, it is just for better type hints

    values: ClassVar[dict[int, Self]]
    names: ClassVar[dict[str, Self]]

    name: str
eBim: LicensedFeature  # 2
eCommunicator: LicensedFeature  # 1
eCore: LicensedFeature  # 0
eMechanical: LicensedFeature  # 3
class Core:
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    @staticmethod
    def getOpenObjects() -> list:
        pass
    @staticmethod
    def isLicenseAvailable(val: PyBrx.LicensedFeature, /) -> bool:
        pass
class DbProperties:
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    @staticmethod
    def dumpAll(id: PyDb.ObjectId, /) -> None:
        pass
    @staticmethod
    def getValue(id: PyDb.ObjectId,name: str, /) -> PyDb.AcValue:
        pass
    @staticmethod
    def isReadOnly(id: PyDb.ObjectId,name: str, /) -> tuple:
        pass
    @staticmethod
    def isValid(id: PyDb.ObjectId,name: str, /) -> tuple:
        pass
    @staticmethod
    def listAll(id: PyDb.ObjectId, /) -> list:
        pass
    @staticmethod
    def setValue(id: PyDb.ObjectId,name: str,val: PyDb.AcValue, /) -> None:
        pass
class LicensedFeature(_BoostPythonEnum):
    eCore: ClassVar[Self]  # 0
    eCommunicator: ClassVar[Self]  # 1
    eBim: ClassVar[Self]  # 2
    eMechanical: ClassVar[Self]  # 3
class PyBrxPanel:
    def __init__(self, name : str, configKey : str=None, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    def backgroundColor(self, /) -> int:
        pass
    def create(self, panel: wx.Panel, /) -> bool:
        pass
    def destroy(self, /) -> None:
        pass
    def isFloating(self, /) -> bool:
        pass
    def setIcon(self, imagePath: str, /) -> None:
        pass
    def tabTextColor(self, /) -> int:
        pass
