import PyRx
import PyGe
import PyGi
import PyGs
import PyDb
import PyAp
import PyEd
import PyPl
import PySm
import PyBr
from typing import overload
from typing import Any

class Brep(Entity):
    def __init__ (self, entity: PyDb.Entity=None)-> None :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def getSolid (self)-> PyDb.Solid3d :
        '''                             '''
        ...
    def getSurface (self)-> PyGe.Surface :
        '''                             '''
        ...
    def set (self, entity: PyDb.Entity)-> None :
        '''                             '''
        ...

class Complex(Entity):
    def __init__ (self)-> None :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...

class ComplexShellTraverser(Traverser):
    def __init__ (self)-> None :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def getComplex (self)-> PyBr.Complex :
        '''                             '''
        ...
    def getShell (self)-> PyBr.Shell :
        '''                             '''
        ...
    def setComplex (self, val: PyBr.Complex)-> None :
        '''                             '''
        ...
    def setComplexAndShell (self, val: PyBr.Shell)-> None :
        '''                             '''
        ...
    def setComplexTraverser (self, val: PyBr.BrepComplexTraverser)-> None :
        '''                             '''
        ...
    def setShell (self, val: PyBr.Shell)-> None :
        '''                             '''
        ...

class ComplexTraverser(Traverser):
    def __init__ (self, val: PyBr.Brep=None)-> None :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def getBrep (self)-> PyBr.Brep :
        '''                             '''
        ...
    def getComplex (self)-> PyBr.Complex :
        '''                             '''
        ...
    def getComplexs (self)-> list[PyBr.Complex] :
        '''                             '''
        ...
    def setBrep (self, val: PyBr.Brep)-> None :
        '''                             '''
        ...
    def setBrepAndComplex (self, val: PyBr.Complex)-> None :
        '''                             '''
        ...
    def setComplex (self, val: PyBr.Complex)-> None :
        '''                             '''
        ...

class Edge(Entity):
    def __init__ (self, *args, **kwargs)-> None :
        '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def getCurve (self)-> PyGe.ExternalCurve3d :
        '''                             '''
        ...
    def getCurveType (self)-> PyGe.EntityId :
        '''                             '''
        ...
    def getOrientToCurve (self)-> bool :
        '''                             '''
        ...
    def getVertex1 (self)-> PyBr.Vertex :
        '''                             '''
        ...
    def getVertex2 (self)-> PyBr.Vertex :
        '''                             '''
        ...

class EdgeLoopTraverser(Traverser):
    def __init__ (self)-> None :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def getEdge (self)-> PyBr.Edge :
        '''                             '''
        ...
    def getLoop (self)-> PyBr.Loop :
        '''                             '''
        ...
    def setEdge (self, val: PyBr.Edge)-> None :
        '''                             '''
        ...
    def setEdgeAndLoop (self, val: PyBr.LoopEdgeTraverser)-> None :
        '''                             '''
        ...
    def setLoop (self, val: PyBr.Loop)-> None :
        '''                             '''
        ...
    def setVertexAndEdge (self, val: PyBr.VertexEdgeTraverser)-> None :
        '''                             '''
        ...

class EdgeTraverser(Traverser):
    def __init__ (self, val: PyBr.Brep=None)-> None :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def getBrep (self)-> PyBr.Brep :
        '''                             '''
        ...
    def getEdge (self)-> PyBr.Edge :
        '''                             '''
        ...
    def getEdges (self)-> list[PyBr.Edge] :
        '''                             '''
        ...
    def setBrep (self, val: PyBr.Brep)-> None :
        '''                             '''
        ...
    def setBrepAndEdge (self, val: PyBr.Edge)-> None :
        '''                             '''
        ...
    def setEdge (self, val: PyBr.Edge)-> None :
        '''                             '''
        ...

class Element(MeshEntity):
    def __init__ (self, *args, **kwargs)-> None :
        '''Raises an exception
This class cannot be instantiated from Python'''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...

class Element2d(Element):
    def __init__ (self)-> None :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def getNormal (self)-> PyGe.Vector3d :
        '''                             '''
        ...

class Element2dNodeTraverser(Traverser):
    def __init__ (self)-> None :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def getElement (self)-> PyBr.Element2d :
        '''                             '''
        ...
    def getNode (self)-> PyBr.Node :
        '''                             '''
        ...
    def getParamPoint (self)-> PyGe.Point2d :
        '''                             '''
        ...
    def getSurfaceNormal (self)-> PyGe.Vector3d :
        '''                             '''
        ...
    def setElement (self, val: PyBr.Element2d)-> None :
        '''                             '''
        ...
    def setElementTraverser (self, val: PyBr.Mesh2dElement2dTraverser)-> None :
        '''                             '''
        ...
    def setNode (self, val: PyBr.Node)-> None :
        '''                             '''
        ...

class Element2dShape(object):
    def kAllPolygons (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kAllQuadrilaterals (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kAllTriangles (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kDefault (self, *args, **kwargs)-> None :
        '''None'''
        ...

class Entity(PyRx.RxObject):
    def __init__ (self, *args, **kwargs)-> None :
        '''Raises an exception
This class cannot be instantiated from Python'''
        ...
    def brepChanged (self)-> bool :
        '''                             '''
        ...
    def checkEntity (self)-> bool :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def getBoundBlock (self)-> PyGe.BoundBlock3d :
        '''                             '''
        ...
    def getBrep (self)-> PyBr.Brep :
        '''                             '''
        ...
    def getLineContainment (self, line: PyGe.LinearEnt3d, numHitsWanted: int)-> list[PyBr.Hit] :
        '''                             '''
        ...
    def getMassProps (self, density: float = None, tolRequired: float = None)-> tuple :
        '''                             '''
        ...
    def getPerimeterLength (self, tolRequired: float = None)-> tuple[float,float] :
        '''                             '''
        ...
    def getPointContainment (self, pt: PyGe.Point3d)-> tuple[PyBr.Entity,PyGe.PointContainment] :
        '''                             '''
        ...
    def getSubentPath (self)-> PyDb.FullSubentPath :
        '''                             '''
        ...
    def getSurfaceArea (self, tolRequired: float = None)-> tuple[float,float] :
        '''                             '''
        ...
    def getValidationLevel (self)-> PyBr.ValidationLevel :
        '''                             '''
        ...
    def getVolume (self, tolRequired: float = None)-> tuple[float,float] :
        '''                             '''
        ...
    def isEqualTo (self, otherObject: PyRx.RxObject)-> bool :
        '''                             '''
        ...
    def isNull (self)-> bool :
        '''                             '''
        ...
    def setSubentPath (self, val: PyDb.FullSubentPath)-> None :
        '''                             '''
        ...
    def setValidationLevel (self, val: PyBr.ValidationLevel)-> None :
        '''                             '''
        ...

class ErrorStatus(object):
    def eAmbiguousOutput (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eBrepChanged (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eDegenerateTopology (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eInvalidInput (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eInvalidObject (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eMissingGeometry (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eMissingSubentity (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eNotApplicable (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eNotImplementedYet (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eNullObjectId (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eNullObjectPointer (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eNullSubentityId (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eObjectIdMismatch (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eOk (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eOutOfMemory (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eTopologyMismatch (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eUninitialisedObject (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eUnsuitableGeometry (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eUnsuitableTopology (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eWrongObjectType (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eWrongSubentityType (self, *args, **kwargs)-> None :
        '''None'''
        ...

class Face(Entity):
    def __init__ (self)-> None :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def getArea (self)-> float :
        '''                             '''
        ...
    def getAreaWithTol (self, tolRequired: float)-> tuple[float,float] :
        '''                             '''
        ...
    def getOrientToSurface (self)-> bool :
        '''                             '''
        ...
    def getShell (self)-> PyBr.Shell :
        '''                             '''
        ...
    def getSurface (self)-> PyGe.Surface :
        '''                             '''
        ...
    def getSurfaceType (self)-> PyGe.EntityId :
        '''                             '''
        ...

class FaceLoopTraverser(Traverser):
    def __init__ (self)-> None :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def getFace (self)-> PyBr.Face :
        '''                             '''
        ...
    def getLoop (self)-> PyBr.Loop :
        '''                             '''
        ...
    def setFace (self, val: PyBr.Face)-> None :
        '''                             '''
        ...
    def setFaceAndLoop (self, val: PyBr.Loop)-> None :
        '''                             '''
        ...
    def setFaceTraverser (self, val: PyBr.ShellFaceTraverser)-> None :
        '''                             '''
        ...
    def setLoop (self, val: PyBr.Loop)-> None :
        '''                             '''
        ...

class FaceTraverser(Traverser):
    def __init__ (self, val: PyBr.Brep=None)-> None :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def getBrep (self)-> PyBr.Brep :
        '''                             '''
        ...
    def getFace (self)-> PyBr.Face :
        '''                             '''
        ...
    def getFaces (self)-> list[PyBr.Face] :
        '''                             '''
        ...
    def setBrep (self, val: PyBr.Brep)-> None :
        '''                             '''
        ...
    def setBrepAndFace (self, val: PyBr.Face)-> None :
        '''                             '''
        ...
    def setFace (self, val: PyBr.Face)-> None :
        '''                             '''
        ...

class Hit(PyRx.RxObject):
    def __init__ (self)-> None :
        '''                             '''
        ...
    def brepChanged (self)-> bool :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def getEntityAssociated (self)-> PyBr.Entity :
        '''                             '''
        ...
    def getEntityEntered (self)-> PyBr.Entity :
        '''                             '''
        ...
    def getEntityHit (self)-> PyBr.Entity :
        '''                             '''
        ...
    def getPoint (self)-> PyGe.Point3d :
        '''                             '''
        ...
    def getValidationLevel (self)-> PyBr.ValidationLevel :
        '''                             '''
        ...
    def isEqualTo (self, otherObject: PyRx.RxObject)-> bool :
        '''                             '''
        ...
    def isNull (self)-> bool :
        '''                             '''
        ...
    def setValidationLevel (self, val: PyBr.ValidationLevel)-> None :
        '''                             '''
        ...

class Loop(Entity):
    def __init__ (self)-> None :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def getFace (self)-> PyBr.Face :
        '''                             '''
        ...
    def getType (self)-> PyBr.LoopType :
        '''                             '''
        ...

class LoopEdgeTraverser(Traverser):
    def __init__ (self)-> None :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def getEdge (self)-> PyBr.Edge :
        '''                             '''
        ...
    def getEdgeOrientToLoop (self)-> bool :
        '''                             '''
        ...
    def getLoop (self)-> PyBr.Loop :
        '''                             '''
        ...
    def getOrientedCurve (self)-> PyGe.Curve3d :
        '''                             '''
        ...
    def getParamCurve (self)-> PyGe.Curve2d :
        '''                             '''
        ...
    def setEdge (self, val: PyBr.Edge)-> None :
        '''                             '''
        ...
    def setLoop (self, val: PyBr.Loop)-> None :
        '''                             '''
        ...
    def setLoopAndEdge (self, val: PyBr.EdgeLoopTraverser)-> None :
        '''                             '''
        ...
    def setLoopTraverser (self, val: PyBr.FaceLoopTraverser)-> None :
        '''                             '''
        ...

class LoopType(object):
    def kExterior (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kInterior (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kLoopExterior (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kLoopUnclassified (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kUnclassified (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kWinding (self, *args, **kwargs)-> None :
        '''None'''
        ...

class LoopVertexTraverser(Traverser):
    def __init__ (self)-> None :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def getLoop (self)-> PyBr.Loop :
        '''                             '''
        ...
    def getParamPoint (self)-> PyGe.Point2d :
        '''                             '''
        ...
    def getVertex (self)-> PyBr.Vertex :
        '''                             '''
        ...
    def setLoop (self, val: PyBr.Loop)-> None :
        '''                             '''
        ...
    def setLoopAndVertex (self, val: PyBr.VertexLoopTraverser)-> None :
        '''                             '''
        ...
    def setLoopTraverser (self, val: PyBr.FaceLoopTraverser)-> None :
        '''                             '''
        ...
    def setVertex (self, val: PyBr.Vertex)-> None :
        '''                             '''
        ...

class MassProps(object):
    def __init__ (self, *args, **kwargs)-> None :
        '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
        ...
    def centroid (self)-> PyGe.Point3d :
        '''                             '''
        ...
    def mass (self)-> float :
        '''                             '''
        ...
    def momInertia (self)-> tuple :
        '''                             '''
        ...
    def prinAxes (self)-> tuple :
        '''                             '''
        ...
    def prinMoments (self)-> tuple :
        '''                             '''
        ...
    def prodInertia (self)-> tuple :
        '''                             '''
        ...
    def radiiGyration (self)-> tuple :
        '''                             '''
        ...
    def volume (self)-> float :
        '''                             '''
        ...

class Mesh(MeshEntity):
    def __init__ (self, *args, **kwargs)-> None :
        '''Raises an exception
This class cannot be instantiated from Python'''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...

class Mesh2d(Mesh):
    def __init__ (self)-> None :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...

class Mesh2dElement2dTraverser(Traverser):
    def __init__ (self)-> None :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def getElement (self)-> PyBr.Element2d :
        '''                             '''
        ...
    def getMesh (self)-> PyBr.Mesh2d :
        '''                             '''
        ...
    def setElement (self, val: PyBr.Element2d)-> None :
        '''                             '''
        ...
    def setMesh (self, val: PyBr.Mesh2d)-> None :
        '''                             '''
        ...
    def setMeshAndElement (self, val: PyBr.Element2d)-> None :
        '''                             '''
        ...

class MeshEntity(PyRx.RxObject):
    def __init__ (self, *args, **kwargs)-> None :
        '''Raises an exception
This class cannot be instantiated from Python'''
        ...
    def brepChanged (self)-> bool :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def getEntityAssociated (self)-> PyBr.Entity :
        '''                             '''
        ...
    def getValidationLevel (self)-> PyBr.ValidationLevel :
        '''                             '''
        ...
    def isEqualTo (self, otherObject: PyRx.RxObject)-> bool :
        '''                             '''
        ...
    def isNull (self)-> bool :
        '''                             '''
        ...
    def setValidationLevel (self, val: PyBr.ValidationLevel)-> None :
        '''                             '''
        ...

class Node(MeshEntity):
    def __init__ (self)-> None :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def getPoint (self)-> PyGe.Point3d :
        '''                             '''
        ...

class Relation(object):
    def kBoundary (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kCoincident (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kInside (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kIntersect (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kOutside (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kTangent (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kUnknown (self, *args, **kwargs)-> None :
        '''None'''
        ...

class Shell(Entity):
    def __init__ (self)-> None :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def getComplex (self)-> PyBr.Complex :
        '''                             '''
        ...
    def getType (self)-> PyBr.ShellType :
        '''                             '''
        ...

class ShellFaceTraverser(Traverser):
    def __init__ (self)-> None :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def getFace (self)-> PyBr.Face :
        '''                             '''
        ...
    def getShell (self)-> PyBr.Shell :
        '''                             '''
        ...
    def setFace (self, val: PyBr.Face)-> None :
        '''                             '''
        ...
    def setShell (self, val: PyBr.Shell)-> None :
        '''                             '''
        ...
    def setShellAndFace (self, val: PyBr.Face)-> None :
        '''                             '''
        ...
    def setShellTraverser (self, val: PyBr.ComplexShellTraverser)-> None :
        '''                             '''
        ...

class ShellTraverser(Traverser):
    def __init__ (self, val: PyBr.Brep=None)-> None :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def getBrep (self)-> PyBr.Brep :
        '''                             '''
        ...
    def getShell (self)-> PyBr.Shell :
        '''                             '''
        ...
    def getShells (self)-> list[PyBr.Shell] :
        '''                             '''
        ...
    def setBrep (self, val: PyBr.Brep)-> None :
        '''                             '''
        ...
    def setBrepAndShell (self, val: PyBr.Shell)-> None :
        '''                             '''
        ...
    def setShell (self, val: PyBr.Shell)-> None :
        '''                             '''
        ...

class ShellType(object):
    def kShellExterior (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kShellInterior (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kShellUnclassified (self, *args, **kwargs)-> None :
        '''None'''
        ...

class Traverser(PyRx.RxObject):
    def __init__ (self, *args, **kwargs)-> None :
        '''Raises an exception
This class cannot be instantiated from Python'''
        ...
    def brepChanged (self)-> bool :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def done (self)-> bool :
        '''                             '''
        ...
    def getValidationLevel (self)-> PyBr.ValidationLevel :
        '''                             '''
        ...
    def isEqualTo (self, otherObject: PyRx.RxObject)-> bool :
        '''                             '''
        ...
    def isNull (self)-> bool :
        '''                             '''
        ...
    def next (self)-> None :
        '''                             '''
        ...
    def restart (self)-> None :
        '''                             '''
        ...
    def setValidationLevel (self, val: PyBr.ValidationLevel)-> None :
        '''                             '''
        ...

class ValidationLevel(object):
    def kFullValidation (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kNoValidation (self, *args, **kwargs)-> None :
        '''None'''
        ...

class Vertex(Entity):
    def __init__ (self)-> None :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def getPoint (self)-> PyGe.Point3d :
        '''                             '''
        ...

class VertexEdgeTraverser(Traverser):
    def __init__ (self)-> None :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def getEdge (self)-> PyBr.Edge :
        '''                             '''
        ...
    def getVertex (self)-> PyBr.Vertex :
        '''                             '''
        ...
    def setEdge (self, val: PyBr.Edge)-> None :
        '''                             '''
        ...
    def setVertex (self, val: PyBr.Vertex)-> None :
        '''                             '''
        ...

class VertexLoopTraverser(Traverser):
    def __init__ (self)-> None :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def getLoop (self)-> PyBr.Loop :
        '''                             '''
        ...
    def getVertex (self)-> PyBr.Vertex :
        '''                             '''
        ...
    def setLoop (self, val: PyBr.Loop)-> None :
        '''                             '''
        ...
    def setVertex (self, val: PyBr.Vertex)-> None :
        '''                             '''
        ...
    def setVertexAndLoop (self, val: PyBr.LoopVertexTraverser)-> None :
        '''                             '''
        ...

class VertexTraverser(Traverser):
    def __init__ (self, val: PyBr.Brep=None)-> None :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def getBrep (self)-> PyBr.Brep :
        '''                             '''
        ...
    def getVertex (self)-> PyBr.Vertex :
        '''                             '''
        ...
    def getVertexs (self)-> list[PyBr.Vertex] :
        '''                             '''
        ...
    def setBrep (self, val: PyBr.Brep)-> None :
        '''                             '''
        ...
    def setBrepAndVertex (self, val: PyBr.Vertex)-> None :
        '''                             '''
        ...
    def setVertex (self, val: PyBr.Vertex)-> None :
        '''                             '''
        ...
