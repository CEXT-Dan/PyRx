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

class Complex(Entity):
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

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def isEqualTo (self, otherObject: PyRx.RxObject)-> bool :
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

class Hit(PyRx.RxObject):
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
    def isEqualTo (self, otherObject: PyRx.RxObject)-> bool :
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
    def momInertia (self)-> tuple[Any,...] :
        '''                             '''
        ...
    def prinAxes (self)-> tuple[Any,...] :
        '''                             '''
        ...
    def prinMoments (self)-> tuple[Any,...] :
        '''                             '''
        ...
    def prodInertia (self)-> tuple[Any,...] :
        '''                             '''
        ...
    def radiiGyration (self)-> tuple[Any,...] :
        '''                             '''
        ...
    def volume (self)-> float :
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

class ValidationLevel(object):
    def kFullValidation (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kNoValidation (self, *args, **kwargs)-> None :
        '''None'''
        ...
