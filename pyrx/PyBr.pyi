from __future__ import annotations

from typing import Any, ClassVar, Self

from pyrx import Br as PyBr
from pyrx import Db as PyDb
from pyrx import Ge as PyGe
from pyrx import Rx as PyRx
from pyrx.doc_utils.boost_meta import _BoostPythonEnum

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
    def __init__(self, entity: PyDb.Entity = ..., /) -> None: ...
    def __reduce__(self, /) -> Any: ...
    @staticmethod
    def className() -> str: ...
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
    def getSolid(self, /) -> PyDb.Solid3d: ...
    def getSurface(self, /) -> PyGe.Surface: ...
    def set(self, entity: PyDb.Entity, /) -> None: ...

class Complex(PyBr.Entity):
    def __init__(self, /) -> None: ...
    def __reduce__(self, /) -> Any: ...
    @staticmethod
    def className() -> str: ...
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
    def __init__(self, /) -> None: ...
    def __reduce__(self, /) -> Any: ...
    @staticmethod
    def className() -> str: ...
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
    def getComplex(self, /) -> Complex: ...
    def getShell(self, /) -> Shell: ...
    def setComplex(self, val: PyBr.Complex, /) -> None: ...
    def setComplexAndShell(self, val: PyBr.Shell, /) -> None: ...
    def setComplexTraverser(self, val: PyBr.BrepComplexTraverser, /) -> None: ...
    def setShell(self, val: PyBr.Shell, /) -> None: ...

class ComplexTraverser(PyBr.Traverser):
    def __init__(self, val: PyBr.Brep = ..., /) -> None: ...
    def __reduce__(self, /) -> Any: ...
    @staticmethod
    def className() -> str: ...
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
    def getBrep(self, /) -> Brep: ...
    def getComplex(self, /) -> Complex: ...
    def getComplexs(self, /) -> list[PyBr.Complex]: ...
    def setBrep(self, val: PyBr.Brep, /) -> None: ...
    def setBrepAndComplex(self, val: PyBr.Complex, /) -> None: ...
    def setComplex(self, val: PyBr.Complex, /) -> None: ...

class Edge(PyBr.Entity):
    def __init__(self, /) -> None: ...
    def __reduce__(self, /) -> Any: ...
    @staticmethod
    def className() -> str: ...
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
    def getCurve(self, /) -> PyGe.ExternalCurve3d: ...
    def getCurveType(self, /) -> PyGe.EntityId: ...
    def getOrientToCurve(self, /) -> bool: ...
    def getVertex1(self, /) -> PyBr.Vertex: ...
    def getVertex2(self, /) -> PyBr.Vertex: ...

class EdgeLoopTraverser(PyBr.Traverser):
    def __init__(self, /) -> None: ...
    def __reduce__(self, /) -> Any: ...
    @staticmethod
    def className() -> str: ...
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
    def getEdge(self, /) -> Edge: ...
    def getLoop(self, /) -> Loop: ...
    def setEdge(self, val: PyBr.Edge, /) -> None: ...
    def setEdgeAndLoop(self, val: PyBr.LoopEdgeTraverser, /) -> None: ...
    def setLoop(self, val: PyBr.Loop, /) -> None: ...
    def setVertexAndEdge(self, val: PyBr.VertexEdgeTraverser, /) -> None: ...

class EdgeTraverser(PyBr.Traverser):
    def __init__(self, val: PyBr.Brep = ..., /) -> None: ...
    def __reduce__(self, /) -> Any: ...
    @staticmethod
    def className() -> str: ...
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
    def getBrep(self, /) -> Brep: ...
    def getEdge(self, /) -> Edge: ...
    def getEdges(self, /) -> list[PyBr.Edge]: ...
    def setBrep(self, val: PyBr.Brep, /) -> None: ...
    def setBrepAndEdge(self, val: PyBr.Edge, /) -> None: ...
    def setEdge(self, val: PyBr.Edge, /) -> None: ...

class Element(PyBr.MeshEntity):
    def __init__(self) -> None:
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /) -> Any: ...
    @staticmethod
    def className() -> str: ...
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
    def __init__(self, /) -> None: ...
    def __reduce__(self, /) -> Any: ...
    @staticmethod
    def className() -> str: ...
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
    def getNormal(self, /) -> PyGe.Vector3d: ...

class Element2dNodeTraverser(PyBr.Traverser):
    def __init__(self, /) -> None: ...
    def __reduce__(self, /) -> Any: ...
    @staticmethod
    def className() -> str: ...
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
    def getElement(self, /) -> Element2d: ...
    def getNode(self, /) -> Node: ...
    def getParamPoint(self, /) -> PyGe.Point2d: ...
    def getSurfaceNormal(self, /) -> PyGe.Vector3d: ...
    def setElement(self, val: PyBr.Element2d, /) -> None: ...
    def setElementTraverser(self, val: PyBr.Mesh2dElement2dTraverser, /) -> None: ...
    def setNode(self, val: PyBr.Node, /) -> None: ...

class Element2dShape(_BoostPythonEnum):
    kDefault: ClassVar[Self]  # 0
    kAllPolygons: ClassVar[Self]  # 1
    kAllQuadrilaterals: ClassVar[Self]  # 2
    kAllTriangles: ClassVar[Self]  # 3

class Entity(PyRx.RxObject):
    def __init__(self) -> None:
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /) -> Any: ...
    def brepChanged(self, /) -> bool: ...
    def checkEntity(self, /) -> bool: ...
    @staticmethod
    def className() -> str: ...
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
    def getBoundBlock(self, /) -> PyGe.BoundBlock3d: ...
    def getBrep(self, /) -> Brep: ...
    def getLineContainment(
        self, line: PyGe.LinearEnt3d, numHitsWanted: int, /
    ) -> list[PyBr.Hit]: ...
    def getMassProps(self, density: float = ..., tolRequired: float = ..., /) -> tuple: ...
    def getPerimeterLength(self, tolRequired: float = ..., /) -> tuple[float, float]: ...
    def getPointContainment(
        self, pt: PyGe.Point3d, /
    ) -> tuple[PyBr.Entity, PyGe.PointContainment]: ...
    def getSubentPath(self, /) -> PyDb.FullSubentPath: ...
    def getSurfaceArea(self, tolRequired: float = ..., /) -> tuple[float, float]: ...
    def getValidationLevel(self, /) -> ValidationLevel: ...
    def getVolume(self, tolRequired: float = ..., /) -> tuple[float, float]: ...
    def isEqualTo(self, otherObject: PyRx.RxObject, /) -> bool: ...
    def isNull(self, /) -> bool: ...
    def setSubentPath(self, val: PyDb.FullSubentPath, /) -> None: ...
    def setValidationLevel(self, val: PyBr.ValidationLevel, /) -> None: ...

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
    def __init__(self, /) -> None: ...
    def __reduce__(self, /) -> Any: ...
    @staticmethod
    def className() -> str: ...
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
    def getArea(self, /) -> float: ...
    def getAreaWithTol(self, tolRequired: float, /) -> tuple[float, float]: ...
    def getOrientToSurface(self, /) -> bool: ...
    def getShell(self, /) -> Shell: ...
    def getSurface(self, /) -> PyGe.Surface: ...
    def getSurfaceType(self, /) -> PyGe.EntityId: ...

class FaceLoopTraverser(PyBr.Traverser):
    def __init__(self, /) -> None: ...
    def __reduce__(self, /) -> Any: ...
    @staticmethod
    def className() -> str: ...
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
    def getFace(self, /) -> Face: ...
    def getLoop(self, /) -> Loop: ...
    def setFace(self, val: PyBr.Face, /) -> None: ...
    def setFaceAndLoop(self, val: PyBr.Loop, /) -> None: ...
    def setFaceTraverser(self, val: PyBr.ShellFaceTraverser, /) -> None: ...
    def setLoop(self, val: PyBr.Loop, /) -> None: ...

class FaceTraverser(PyBr.Traverser):
    def __init__(self, val: PyBr.Brep = ..., /) -> None: ...
    def __reduce__(self, /) -> Any: ...
    @staticmethod
    def className() -> str: ...
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
    def getBrep(self, /) -> Brep: ...
    def getFace(self, /) -> Face: ...
    def getFaces(self, /) -> list[PyBr.Face]: ...
    def setBrep(self, val: PyBr.Brep, /) -> None: ...
    def setBrepAndFace(self, val: PyBr.Face, /) -> None: ...
    def setFace(self, val: PyBr.Face, /) -> None: ...

class Hit(PyRx.RxObject):
    def __init__(self, /) -> None: ...
    def __reduce__(self, /) -> Any: ...
    def brepChanged(self, /) -> bool: ...
    @staticmethod
    def className() -> str: ...
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
    def getEntityAssociated(self, /) -> Entity: ...
    def getEntityEntered(self, /) -> Entity: ...
    def getEntityHit(self, /) -> Entity: ...
    def getPoint(self, /) -> PyGe.Point3d: ...
    def getValidationLevel(self, /) -> ValidationLevel: ...
    def isEqualTo(self, otherObject: PyRx.RxObject, /) -> bool: ...
    def isNull(self, /) -> bool: ...
    def setValidationLevel(self, val: PyBr.ValidationLevel, /) -> None: ...

class Loop(PyBr.Entity):
    def __init__(self, /) -> None: ...
    def __reduce__(self, /) -> Any: ...
    @staticmethod
    def className() -> str: ...
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
    def getFace(self, /) -> Face: ...
    def getType(self, /) -> LoopType: ...

class LoopEdgeTraverser(PyBr.Traverser):
    def __init__(self, /) -> None: ...
    def __reduce__(self, /) -> Any: ...
    @staticmethod
    def className() -> str: ...
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
    def getEdge(self, /) -> Edge: ...
    def getEdgeOrientToLoop(self, /) -> bool: ...
    def getLoop(self, /) -> Loop: ...
    def getOrientedCurve(self, /) -> PyGe.Curve3d: ...
    def getParamCurve(self, /) -> PyGe.Curve2d: ...
    def setEdge(self, val: PyBr.Edge, /) -> None: ...
    def setLoop(self, val: PyBr.Loop, /) -> None: ...
    def setLoopAndEdge(self, val: PyBr.EdgeLoopTraverser, /) -> None: ...
    def setLoopTraverser(self, val: PyBr.FaceLoopTraverser, /) -> None: ...

class LoopType(_BoostPythonEnum):
    kUnclassified: ClassVar[Self]  # 0
    kExterior: ClassVar[Self]  # 1
    kInterior: ClassVar[Self]  # 2
    kWinding: ClassVar[Self]  # 3
    kLoopUnclassified: ClassVar[Self]  # 0
    kLoopExterior: ClassVar[Self]  # 1

class LoopVertexTraverser(PyBr.Traverser):
    def __init__(self, /) -> None: ...
    def __reduce__(self, /) -> Any: ...
    @staticmethod
    def className() -> str: ...
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
    def getLoop(self, /) -> Loop: ...
    def getParamPoint(self, /) -> PyGe.Point2d: ...
    def getVertex(self, /) -> PyBr.Vertex: ...
    def setLoop(self, val: PyBr.Loop, /) -> None: ...
    def setLoopAndVertex(self, val: PyBr.VertexLoopTraverser, /) -> None: ...
    def setLoopTraverser(self, val: PyBr.FaceLoopTraverser, /) -> None: ...
    def setVertex(self, val: PyBr.Vertex, /) -> None: ...

class MassProps:
    def __init__(self, /) -> None: ...
    def __reduce__(self, /) -> Any: ...
    def centroid(self, /) -> PyGe.Point3d: ...
    def mass(self, /) -> float: ...
    def momInertia(self, /) -> tuple: ...
    def prinAxes(self, /) -> tuple: ...
    def prinMoments(self, /) -> tuple: ...
    def prodInertia(self, /) -> tuple: ...
    def radiiGyration(self, /) -> tuple: ...
    def volume(self, /) -> float: ...

class Mesh(PyBr.MeshEntity):
    def __init__(self) -> None:
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /) -> Any: ...
    @staticmethod
    def className() -> str: ...
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
    def __init__(self, /) -> None: ...
    def __reduce__(self, /) -> Any: ...
    @staticmethod
    def className() -> str: ...
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
    def __init__(self, /) -> None: ...
    def __reduce__(self, /) -> Any: ...
    @staticmethod
    def className() -> str: ...
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
    def getElement(self, /) -> Element2d: ...
    def getMesh(self, /) -> Mesh2d: ...
    def setElement(self, val: PyBr.Element2d, /) -> None: ...
    def setMesh(self, val: PyBr.Mesh2d, /) -> None: ...
    def setMeshAndElement(self, val: PyBr.Element2d, /) -> None: ...

class MeshEntity(PyRx.RxObject):
    def __init__(self) -> None:
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /) -> Any: ...
    def brepChanged(self, /) -> bool: ...
    @staticmethod
    def className() -> str: ...
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
    def getEntityAssociated(self, /) -> Entity: ...
    def getValidationLevel(self, /) -> ValidationLevel: ...
    def isEqualTo(self, otherObject: PyRx.RxObject, /) -> bool: ...
    def isNull(self, /) -> bool: ...
    def setValidationLevel(self, val: PyBr.ValidationLevel, /) -> None: ...

class Node(PyBr.MeshEntity):
    def __init__(self, /) -> None: ...
    def __reduce__(self, /) -> Any: ...
    @staticmethod
    def className() -> str: ...
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
    def getPoint(self, /) -> PyGe.Point3d: ...

class Relation(_BoostPythonEnum):
    kUnknown: ClassVar[Self]  # 0
    kOutside: ClassVar[Self]  # 1
    kInside: ClassVar[Self]  # 2
    kBoundary: ClassVar[Self]  # 3
    kCoincident: ClassVar[Self]  # 4
    kTangent: ClassVar[Self]  # 5
    kIntersect: ClassVar[Self]  # 6

class Shell(PyBr.Entity):
    def __init__(self, /) -> None: ...
    def __reduce__(self, /) -> Any: ...
    @staticmethod
    def className() -> str: ...
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
    def getComplex(self, /) -> Complex: ...
    def getType(self, /) -> ShellType: ...

class ShellFaceTraverser(PyBr.Traverser):
    def __init__(self, /) -> None: ...
    def __reduce__(self, /) -> Any: ...
    @staticmethod
    def className() -> str: ...
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
    def getFace(self, /) -> Face: ...
    def getShell(self, /) -> Shell: ...
    def setFace(self, val: PyBr.Face, /) -> None: ...
    def setShell(self, val: PyBr.Shell, /) -> None: ...
    def setShellAndFace(self, val: PyBr.Face, /) -> None: ...
    def setShellTraverser(self, val: PyBr.ComplexShellTraverser, /) -> None: ...

class ShellTraverser(PyBr.Traverser):
    def __init__(self, val: PyBr.Brep = ..., /) -> None: ...
    def __reduce__(self, /) -> Any: ...
    @staticmethod
    def className() -> str: ...
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
    def getBrep(self, /) -> Brep: ...
    def getShell(self, /) -> Shell: ...
    def getShells(self, /) -> list[PyBr.Shell]: ...
    def setBrep(self, val: PyBr.Brep, /) -> None: ...
    def setBrepAndShell(self, val: PyBr.Shell, /) -> None: ...
    def setShell(self, val: PyBr.Shell, /) -> None: ...

class ShellType(_BoostPythonEnum):
    kShellUnclassified: ClassVar[Self]  # 0
    kShellExterior: ClassVar[Self]  # 1
    kShellInterior: ClassVar[Self]  # 2

class Traverser(PyRx.RxObject):
    def __init__(self) -> None:
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /) -> Any: ...
    def brepChanged(self, /) -> bool: ...
    @staticmethod
    def className() -> str: ...
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
    def done(self, /) -> bool: ...
    def getValidationLevel(self, /) -> ValidationLevel: ...
    def isEqualTo(self, otherObject: PyRx.RxObject, /) -> bool: ...
    def isNull(self, /) -> bool: ...
    def next(self, /) -> None: ...
    def restart(self, /) -> None: ...
    def setValidationLevel(self, val: PyBr.ValidationLevel, /) -> None: ...

class ValidationLevel(_BoostPythonEnum):
    kFullValidation: ClassVar[Self]  # 0
    kNoValidation: ClassVar[Self]  # 1

class Vertex(PyBr.Entity):
    def __init__(self, /) -> None: ...
    def __reduce__(self, /) -> Any: ...
    @staticmethod
    def className() -> str: ...
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
    def getPoint(self, /) -> PyGe.Point3d: ...

class VertexEdgeTraverser(PyBr.Traverser):
    def __init__(self, /) -> None: ...
    def __reduce__(self, /) -> Any: ...
    @staticmethod
    def className() -> str: ...
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
    def getEdge(self, /) -> Edge: ...
    def getVertex(self, /) -> PyBr.Vertex: ...
    def setEdge(self, val: PyBr.Edge, /) -> None: ...
    def setVertex(self, val: PyBr.Vertex, /) -> None: ...

class VertexLoopTraverser(PyBr.Traverser):
    def __init__(self, /) -> None: ...
    def __reduce__(self, /) -> Any: ...
    @staticmethod
    def className() -> str: ...
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
    def getLoop(self, /) -> Loop: ...
    def getVertex(self, /) -> PyBr.Vertex: ...
    def setLoop(self, val: PyBr.Loop, /) -> None: ...
    def setVertex(self, val: PyBr.Vertex, /) -> None: ...
    def setVertexAndLoop(self, val: PyBr.LoopVertexTraverser, /) -> None: ...

class VertexTraverser(PyBr.Traverser):
    def __init__(self, val: PyBr.Brep = ..., /) -> None: ...
    def __reduce__(self, /) -> Any: ...
    @staticmethod
    def className() -> str: ...
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
    def getBrep(self, /) -> Brep: ...
    def getVertex(self, /) -> PyBr.Vertex: ...
    def getVertexs(self, /) -> list[PyBr.Vertex]: ...
    def setBrep(self, val: PyBr.Brep, /) -> None: ...
    def setBrepAndVertex(self, val: PyBr.Vertex, /) -> None: ...
    def setVertex(self, val: PyBr.Vertex, /) -> None: ...
