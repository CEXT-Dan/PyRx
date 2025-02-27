from __future__ import annotations
from typing import *
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
kAerial: ViewProjection  # 1
kNoMap: ViewProjection  # 0
class Core:
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def getBlockImage(blkid: PyDb.ObjectId,sx: int,sy: int,zoomFactor: float,bkrgb: list[int]=None, /) -> object:
        pass
    @staticmethod
    def getCurrent3DAcGsView(vpNum : int, /) -> GsView:
        pass
    @staticmethod
    def getCurrentAcGsView(vpNum : int, /) -> GsView:
        pass
    @staticmethod
    def getViewParameters(vpNum : int,view : PyGs.View, /) -> bool:
        pass
    @staticmethod
    def setViewParameters(vpNum : int,view : PyGs.View,bRegen: bool,bRescale: bool,bSync: bool=False, /) -> bool:
        pass
class GraphicsKernel:
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    def addRef(self, /) -> None:
        pass
    @staticmethod
    def className() -> str:
        pass
    def delRef(self, /) -> bool:
        pass
class GsManager:
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def className() -> str:
        pass
class GsView:
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    def backClip(self, /) -> float:
        pass
    @staticmethod
    def className() -> str:
        pass
    def fieldHeight(self, /) -> float:
        pass
    def fieldWidth(self, /) -> float:
        pass
    def frontClip(self, /) -> float:
        pass
    def getViewport(self, /) -> tuple[PyGe.Point2d,PyGe.Point2d]:
        pass
    def graphicsKernel(self, /) -> GraphicsKernel:
        pass
    def isBackClipped(self, /) -> bool:
        pass
    def isFrontClipped(self, /) -> bool:
        pass
    def isNullObj(self, /) -> bool:
        pass
    def isPerspective(self, /) -> bool:
        pass
    def isViewportBorderVisible(self, /) -> bool:
        pass
    def objectToDeviceMatrix(self, /) -> PyGe.Matrix3d:
        pass
    def position(self, /) -> PyGe.Point3d:
        pass
    def projectionMatrix(self, /) -> PyGe.Matrix3d:
        pass
    def screenMatrix(self, /) -> PyGe.Matrix3d:
        pass
    def setBackClip(self, val: float, /) -> None:
        pass
    def setEnableBackClip(self, val: bool, /) -> None:
        pass
    def setEnableFrontClip(self, val: bool, /) -> None:
        pass
    def setFrontClip(self, val: float, /) -> None:
        pass
    def setView(self, pos: PyGe.Point3d, target: PyGe.Point3d, upVector: PyGe.Vector3d, fWidth: float, fHeight: float, projection: PyGs.ViewProjection = PyGs.ViewProjection.kParallel, /) -> None:
        pass
    def setViewport(self, lowerLeft: PyGe.Point2d, upperRight: PyGe.Point2d, /) -> None:
        pass
    def setViewportBorderVisibility(self, val: bool, /) -> None:
        pass
    def target(self, /) -> PyGe.Point3d:
        pass
    def upVector(self, /) -> PyGe.Vector3d:
        pass
    def viewingMatrix(self, /) -> PyGe.Matrix3d:
        pass
    def worldToDeviceMatrix(self, /) -> PyGe.Matrix3d:
        pass
class KernelDescriptor:
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    def addSupport(self, /) -> None:
        pass
    @staticmethod
    def className() -> str:
        pass
class ViewProjection(_BoostPythonEnum):
    kNoMap: ClassVar[Self]  # 0
    kAerial: ClassVar[Self]  # 1
