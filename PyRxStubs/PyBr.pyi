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
    def kFullValidation (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kNoValidation (self, *args, **kwargs)-> None :
        '''None'''
        ...
