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
eAmbiguousOutput: ErrorStatus  # 5
eBrepChanged: ErrorStatus  # 3008
eDegenerateTopology: ErrorStatus  # 3020
eInvalidInput: ErrorStatus  # 3
eInvalidObject: ErrorStatus  # 123
eMissingGeometry: ErrorStatus  # 153
eMissingSubentity: ErrorStatus  # 137
eNotApplicable: ErrorStatus  # 2
eNotImplementedYet: ErrorStatus  # 1
eNullObjectId: ErrorStatus  # 16
eNullObjectPointer: ErrorStatus  # 123
eNullSubentityId: ErrorStatus  # 24
eObjectIdMismatch: ErrorStatus  # 35
eOk: ErrorStatus  # 0
eOutOfMemory: ErrorStatus  # 6
eTopologyMismatch: ErrorStatus  # 35
eUninitialisedObject: ErrorStatus  # 3021
eUnsuitableGeometry: ErrorStatus  # 5
eUnsuitableTopology: ErrorStatus  # 3013
eWrongObjectType: ErrorStatus  # 34
eWrongSubentityType: ErrorStatus  # 230
kAllPolygons: Element2dShape  # 1
kAllQuadrilaterals: Element2dShape  # 2
kAllTriangles: Element2dShape  # 3
kBoundary: Relation  # 3
kCoincident: Relation  # 4
kDefault: Element2dShape  # 0
kExterior: LoopType  # 1
kFullValidation: ValidationLevel  # 0
kInside: Relation  # 2
kInterior: LoopType  # 2
kIntersect: Relation  # 6
kLoopExterior: LoopType  # 1
kLoopUnclassified: LoopType  # 0
kNoValidation: ValidationLevel  # 1
kOutside: Relation  # 1
kShellExterior: ShellType  # 1
kShellInterior: ShellType  # 2
kShellUnclassified: ShellType  # 0
kTangent: Relation  # 5
kUnclassified: LoopType  # 0
kUnknown: Relation  # 0
kWinding: LoopType  # 3
class Brep(PyBr.Entity):
    def __init__(self, entity: PyDb.Entity=None, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def getSolid(self, /) -> PyDb.Solid3d:
        pass
    def getSurface(self, /) -> PyGe.Surface:
        pass
    def set(self, entity: PyDb.Entity, /) -> None:
        pass
class Complex(PyBr.Entity):
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
class ComplexShellTraverser(PyBr.Traverser):
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def getComplex(self, /) -> Complex:
        pass
    def getShell(self, /) -> Shell:
        pass
    def setComplex(self, val: PyBr.Complex, /) -> None:
        pass
    def setComplexAndShell(self, val: PyBr.Shell, /) -> None:
        pass
    def setComplexTraverser(self, val: PyBr.BrepComplexTraverser, /) -> None:
        pass
    def setShell(self, val: PyBr.Shell, /) -> None:
        pass
class ComplexTraverser(PyBr.Traverser):
    def __init__(self, val: PyBr.Brep=None, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def getBrep(self, /) -> Brep:
        pass
    def getComplex(self, /) -> Complex:
        pass
    def getComplexs(self, /) -> list[PyBr.Complex]:
        pass
    def setBrep(self, val: PyBr.Brep, /) -> None:
        pass
    def setBrepAndComplex(self, val: PyBr.Complex, /) -> None:
        pass
    def setComplex(self, val: PyBr.Complex, /) -> None:
        pass
class Edge(PyBr.Entity):
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def getCurve(self, /) -> PyGe.ExternalCurve3d:
        pass
    def getCurveType(self, /) -> PyGe.EntityId:
        pass
    def getOrientToCurve(self, /) -> bool:
        pass
    def getVertex1(self, /) -> PyBr.Vertex:
        pass
    def getVertex2(self, /) -> PyBr.Vertex:
        pass
class EdgeLoopTraverser(PyBr.Traverser):
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def getEdge(self, /) -> Edge:
        pass
    def getLoop(self, /) -> Loop:
        pass
    def setEdge(self, val: PyBr.Edge, /) -> None:
        pass
    def setEdgeAndLoop(self, val: PyBr.LoopEdgeTraverser, /) -> None:
        pass
    def setLoop(self, val: PyBr.Loop, /) -> None:
        pass
    def setVertexAndEdge(self, val: PyBr.VertexEdgeTraverser, /) -> None:
        pass
class EdgeTraverser(PyBr.Traverser):
    def __init__(self, val: PyBr.Brep=None, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def getBrep(self, /) -> Brep:
        pass
    def getEdge(self, /) -> Edge:
        pass
    def getEdges(self, /) -> list[PyBr.Edge]:
        pass
    def setBrep(self, val: PyBr.Brep, /) -> None:
        pass
    def setBrepAndEdge(self, val: PyBr.Edge, /) -> None:
        pass
    def setEdge(self, val: PyBr.Edge, /) -> None:
        pass
class Element(PyBr.MeshEntity):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
class Element2d(PyBr.Element):
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def getNormal(self, /) -> PyGe.Vector3d:
        pass
class Element2dNodeTraverser(PyBr.Traverser):
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def getElement(self, /) -> Element2d:
        pass
    def getNode(self, /) -> Node:
        pass
    def getParamPoint(self, /) -> PyGe.Point2d:
        pass
    def getSurfaceNormal(self, /) -> PyGe.Vector3d:
        pass
    def setElement(self, val: PyBr.Element2d, /) -> None:
        pass
    def setElementTraverser(self, val: PyBr.Mesh2dElement2dTraverser, /) -> None:
        pass
    def setNode(self, val: PyBr.Node, /) -> None:
        pass
class Element2dShape(_BoostPythonEnum):
    kDefault: ClassVar[Self]  # 0
    kAllPolygons: ClassVar[Self]  # 1
    kAllQuadrilaterals: ClassVar[Self]  # 2
    kAllTriangles: ClassVar[Self]  # 3
class Entity(PyRx.RxObject):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    def brepChanged(self, /) -> bool:
        pass
    def checkEntity(self, /) -> bool:
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def getBoundBlock(self, /) -> PyGe.BoundBlock3d:
        pass
    def getBrep(self, /) -> Brep:
        pass
    def getLineContainment(self, line: PyGe.LinearEnt3d, numHitsWanted: int, /) -> list[PyBr.Hit]:
        pass
    def getMassProps(self, density: float = None, tolRequired: float = None, /) -> tuple:
        pass
    def getPerimeterLength(self, tolRequired: float = None, /) -> tuple[float,float]:
        pass
    def getPointContainment(self, pt: PyGe.Point3d, /) -> tuple[PyBr.Entity,PyGe.PointContainment]:
        pass
    def getSubentPath(self, /) -> PyDb.FullSubentPath:
        pass
    def getSurfaceArea(self, tolRequired: float = None, /) -> tuple[float,float]:
        pass
    def getValidationLevel(self, /) -> ValidationLevel:
        pass
    def getVolume(self, tolRequired: float = None, /) -> tuple[float,float]:
        pass
    def isEqualTo(self, otherObject: PyRx.RxObject, /) -> bool:
        pass
    def isNull(self, /) -> bool:
        pass
    def setSubentPath(self, val: PyDb.FullSubentPath, /) -> None:
        pass
    def setValidationLevel(self, val: PyBr.ValidationLevel, /) -> None:
        pass
class ErrorStatus(_BoostPythonEnum):
    eAmbiguousOutput: ClassVar[Self]  # 5
    eBrepChanged: ClassVar[Self]  # 3008
    eDegenerateTopology: ClassVar[Self]  # 3020
    eInvalidInput: ClassVar[Self]  # 3
    eInvalidObject: ClassVar[Self]  # 123
    eMissingGeometry: ClassVar[Self]  # 153
    eMissingSubentity: ClassVar[Self]  # 137
    eNotApplicable: ClassVar[Self]  # 2
    eNotImplementedYet: ClassVar[Self]  # 1
    eNullObjectId: ClassVar[Self]  # 16
    eNullObjectPointer: ClassVar[Self]  # 123
    eNullSubentityId: ClassVar[Self]  # 24
    eObjectIdMismatch: ClassVar[Self]  # 35
    eOk: ClassVar[Self]  # 0
    eOutOfMemory: ClassVar[Self]  # 6
    eTopologyMismatch: ClassVar[Self]  # 35
    eUninitialisedObject: ClassVar[Self]  # 3021
    eUnsuitableGeometry: ClassVar[Self]  # 5
    eUnsuitableTopology: ClassVar[Self]  # 3013
    eWrongObjectType: ClassVar[Self]  # 34
    eWrongSubentityType: ClassVar[Self]  # 230
class Face(PyBr.Entity):
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def getArea(self, /) -> float:
        pass
    def getAreaWithTol(self, tolRequired: float, /) -> tuple[float,float]:
        pass
    def getOrientToSurface(self, /) -> bool:
        pass
    def getShell(self, /) -> Shell:
        pass
    def getSurface(self, /) -> PyGe.Surface:
        pass
    def getSurfaceType(self, /) -> PyGe.EntityId:
        pass
class FaceLoopTraverser(PyBr.Traverser):
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def getFace(self, /) -> Face:
        pass
    def getLoop(self, /) -> Loop:
        pass
    def setFace(self, val: PyBr.Face, /) -> None:
        pass
    def setFaceAndLoop(self, val: PyBr.Loop, /) -> None:
        pass
    def setFaceTraverser(self, val: PyBr.ShellFaceTraverser, /) -> None:
        pass
    def setLoop(self, val: PyBr.Loop, /) -> None:
        pass
class FaceTraverser(PyBr.Traverser):
    def __init__(self, val: PyBr.Brep=None, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def getBrep(self, /) -> Brep:
        pass
    def getFace(self, /) -> Face:
        pass
    def getFaces(self, /) -> list[PyBr.Face]:
        pass
    def setBrep(self, val: PyBr.Brep, /) -> None:
        pass
    def setBrepAndFace(self, val: PyBr.Face, /) -> None:
        pass
    def setFace(self, val: PyBr.Face, /) -> None:
        pass
class Hit(PyRx.RxObject):
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    def brepChanged(self, /) -> bool:
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def getEntityAssociated(self, /) -> Entity:
        pass
    def getEntityEntered(self, /) -> Entity:
        pass
    def getEntityHit(self, /) -> Entity:
        pass
    def getPoint(self, /) -> PyGe.Point3d:
        pass
    def getValidationLevel(self, /) -> ValidationLevel:
        pass
    def isEqualTo(self, otherObject: PyRx.RxObject, /) -> bool:
        pass
    def isNull(self, /) -> bool:
        pass
    def setValidationLevel(self, val: PyBr.ValidationLevel, /) -> None:
        pass
class Loop(PyBr.Entity):
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def getFace(self, /) -> Face:
        pass
    def getType(self, /) -> LoopType:
        pass
class LoopEdgeTraverser(PyBr.Traverser):
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def getEdge(self, /) -> Edge:
        pass
    def getEdgeOrientToLoop(self, /) -> bool:
        pass
    def getLoop(self, /) -> Loop:
        pass
    def getOrientedCurve(self, /) -> PyGe.Curve3d:
        pass
    def getParamCurve(self, /) -> PyGe.Curve2d:
        pass
    def setEdge(self, val: PyBr.Edge, /) -> None:
        pass
    def setLoop(self, val: PyBr.Loop, /) -> None:
        pass
    def setLoopAndEdge(self, val: PyBr.EdgeLoopTraverser, /) -> None:
        pass
    def setLoopTraverser(self, val: PyBr.FaceLoopTraverser, /) -> None:
        pass
class LoopType(_BoostPythonEnum):
    kUnclassified: ClassVar[Self]  # 0
    kExterior: ClassVar[Self]  # 1
    kInterior: ClassVar[Self]  # 2
    kWinding: ClassVar[Self]  # 3
    kLoopUnclassified: ClassVar[Self]  # 0
    kLoopExterior: ClassVar[Self]  # 1
class LoopVertexTraverser(PyBr.Traverser):
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def getLoop(self, /) -> Loop:
        pass
    def getParamPoint(self, /) -> PyGe.Point2d:
        pass
    def getVertex(self, /) -> PyBr.Vertex:
        pass
    def setLoop(self, val: PyBr.Loop, /) -> None:
        pass
    def setLoopAndVertex(self, val: PyBr.VertexLoopTraverser, /) -> None:
        pass
    def setLoopTraverser(self, val: PyBr.FaceLoopTraverser, /) -> None:
        pass
    def setVertex(self, val: PyBr.Vertex, /) -> None:
        pass
class MassProps:
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    def centroid(self, /) -> PyGe.Point3d:
        pass
    def mass(self, /) -> float:
        pass
    def momInertia(self, /) -> tuple:
        pass
    def prinAxes(self, /) -> tuple:
        pass
    def prinMoments(self, /) -> tuple:
        pass
    def prodInertia(self, /) -> tuple:
        pass
    def radiiGyration(self, /) -> tuple:
        pass
    def volume(self, /) -> float:
        pass
class Mesh(PyBr.MeshEntity):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
class Mesh2d(PyBr.Mesh):
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
class Mesh2dElement2dTraverser(PyBr.Traverser):
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def getElement(self, /) -> Element2d:
        pass
    def getMesh(self, /) -> Mesh2d:
        pass
    def setElement(self, val: PyBr.Element2d, /) -> None:
        pass
    def setMesh(self, val: PyBr.Mesh2d, /) -> None:
        pass
    def setMeshAndElement(self, val: PyBr.Element2d, /) -> None:
        pass
class MeshEntity(PyRx.RxObject):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    def brepChanged(self, /) -> bool:
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def getEntityAssociated(self, /) -> Entity:
        pass
    def getValidationLevel(self, /) -> ValidationLevel:
        pass
    def isEqualTo(self, otherObject: PyRx.RxObject, /) -> bool:
        pass
    def isNull(self, /) -> bool:
        pass
    def setValidationLevel(self, val: PyBr.ValidationLevel, /) -> None:
        pass
class Node(PyBr.MeshEntity):
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def getPoint(self, /) -> PyGe.Point3d:
        pass
class Relation(_BoostPythonEnum):
    kUnknown: ClassVar[Self]  # 0
    kOutside: ClassVar[Self]  # 1
    kInside: ClassVar[Self]  # 2
    kBoundary: ClassVar[Self]  # 3
    kCoincident: ClassVar[Self]  # 4
    kTangent: ClassVar[Self]  # 5
    kIntersect: ClassVar[Self]  # 6
class Shell(PyBr.Entity):
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def getComplex(self, /) -> Complex:
        pass
    def getType(self, /) -> ShellType:
        pass
class ShellFaceTraverser(PyBr.Traverser):
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def getFace(self, /) -> Face:
        pass
    def getShell(self, /) -> Shell:
        pass
    def setFace(self, val: PyBr.Face, /) -> None:
        pass
    def setShell(self, val: PyBr.Shell, /) -> None:
        pass
    def setShellAndFace(self, val: PyBr.Face, /) -> None:
        pass
    def setShellTraverser(self, val: PyBr.ComplexShellTraverser, /) -> None:
        pass
class ShellTraverser(PyBr.Traverser):
    def __init__(self, val: PyBr.Brep=None, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def getBrep(self, /) -> Brep:
        pass
    def getShell(self, /) -> Shell:
        pass
    def getShells(self, /) -> list[PyBr.Shell]:
        pass
    def setBrep(self, val: PyBr.Brep, /) -> None:
        pass
    def setBrepAndShell(self, val: PyBr.Shell, /) -> None:
        pass
    def setShell(self, val: PyBr.Shell, /) -> None:
        pass
class ShellType(_BoostPythonEnum):
    kShellUnclassified: ClassVar[Self]  # 0
    kShellExterior: ClassVar[Self]  # 1
    kShellInterior: ClassVar[Self]  # 2
class Traverser(PyRx.RxObject):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    def brepChanged(self, /) -> bool:
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def done(self, /) -> bool:
        pass
    def getValidationLevel(self, /) -> ValidationLevel:
        pass
    def isEqualTo(self, otherObject: PyRx.RxObject, /) -> bool:
        pass
    def isNull(self, /) -> bool:
        pass
    def next(self, /) -> None:
        pass
    def restart(self, /) -> None:
        pass
    def setValidationLevel(self, val: PyBr.ValidationLevel, /) -> None:
        pass
class ValidationLevel(_BoostPythonEnum):
    kFullValidation: ClassVar[Self]  # 0
    kNoValidation: ClassVar[Self]  # 1
class Vertex(PyBr.Entity):
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def getPoint(self, /) -> PyGe.Point3d:
        pass
class VertexEdgeTraverser(PyBr.Traverser):
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def getEdge(self, /) -> Edge:
        pass
    def getVertex(self, /) -> PyBr.Vertex:
        pass
    def setEdge(self, val: PyBr.Edge, /) -> None:
        pass
    def setVertex(self, val: PyBr.Vertex, /) -> None:
        pass
class VertexLoopTraverser(PyBr.Traverser):
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def getLoop(self, /) -> Loop:
        pass
    def getVertex(self, /) -> PyBr.Vertex:
        pass
    def setLoop(self, val: PyBr.Loop, /) -> None:
        pass
    def setVertex(self, val: PyBr.Vertex, /) -> None:
        pass
    def setVertexAndLoop(self, val: PyBr.LoopVertexTraverser, /) -> None:
        pass
class VertexTraverser(PyBr.Traverser):
    def __init__(self, val: PyBr.Brep=None, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def getBrep(self, /) -> Brep:
        pass
    def getVertex(self, /) -> PyBr.Vertex:
        pass
    def getVertexs(self, /) -> list[PyBr.Vertex]:
        pass
    def setBrep(self, val: PyBr.Brep, /) -> None:
        pass
    def setBrepAndVertex(self, val: PyBr.Vertex, /) -> None:
        pass
    def setVertex(self, val: PyBr.Vertex, /) -> None:
        pass
