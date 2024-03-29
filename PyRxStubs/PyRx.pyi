import PyRx
import PyGe
import PyGi
import PyGs
import PyDb
import PyAp
import PyEd
import PyPl
from typing import overload

class LispType(object):
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
    def kAngle (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kDottedPair (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kDouble (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kInt16 (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kInt32 (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kListBegin (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kListEnd (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kNil (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kNone (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kObjectId (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kOrientation (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kPoint2d (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kPoint3d (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kT_atom (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kText (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kVector2d (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kVector3d (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kVoid (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def name (self, *args, **kwargs)-> None :
      '''None'''
    ...

class Ordering(object):
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
    def kEqual (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kGreaterThan (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kLessThan (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kNotOrderable (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def name (self, *args, **kwargs)-> None :
      '''None'''
    ...

class Overrule(RxObject):
    def __init__ (self, *args, **kwargs)-> None :
      '''Raises an exception
This class cannot be instantiated from Python'''
    ...

    @staticmethod
    def addOverrule (rxClass: PyRx.RxClass,overrule: PyRx.Overrule)-> None :
      '''                             '''
    ...

    @staticmethod
    def addOverruleLast (rxClass: PyRx.RxClass,overrule: PyRx.Overrule,addLast: bool)-> None :
      '''                             '''
    ...

    @staticmethod
    def className ()-> str :
      '''                             '''
    ...
    def comparedTo (self, other: PyRx.RxObject)-> PyRx.Ordering :
      '''                             '''
    ...
    def copyFrom (self, other: PyRx.RxObject)-> None :
      '''                             '''
    ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
      '''                             '''
    ...
    def dispose (self)-> None :
      '''                             '''
    ...

    @staticmethod
    def hasOverrule (subject: PyRx.RxObject,rxClass: PyRx.RxClass)-> bool :
      '''                             '''
    ...
    def implRefCount (self)-> int :
      '''                             '''
    ...
    def isA (self)-> PyRx.RxClass :
      '''                             '''
    ...
    def isKindOf (self, rhs: PyRx.RxClass)-> bool :
      '''                             '''
    ...
    def isNullObj (self)-> bool :
      '''                             '''
    ...
    def isOverruling (self)-> bool :
      '''                             '''
    ...
    def keepAlive (self, flag: bool)-> None :
      '''                             '''
    ...
    def queryX (self, rhs: PyRx.RxClass)-> PyRx.RxObject :
      '''                             '''
    ...

    @staticmethod
    def removeOverrule (rxClass: PyRx.RxClass,overrule: PyRx.Overrule)-> None :
      '''                             '''
    ...
    def setIsOverruling (self, flag: bool)-> None :
      '''                             '''
    ...

class RxClass(RxObject):
    def __init__ (self, *args, **kwargs)-> None :
      '''Raises an exception
This class cannot be instantiated from Python'''
    ...
    def appName (self)-> str :
      '''                             '''
    ...

    @staticmethod
    def className ()-> str :
      '''                             '''
    ...
    def comparedTo (self, other: PyRx.RxObject)-> PyRx.Ordering :
      '''                             '''
    ...
    def copyFrom (self, other: PyRx.RxObject)-> None :
      '''                             '''
    ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
      '''                             '''
    ...
    def dispose (self)-> None :
      '''                             '''
    ...
    def dxfName (self)-> str :
      '''                             '''
    ...
    def implRefCount (self)-> int :
      '''                             '''
    ...
    def isA (self)-> PyRx.RxClass :
      '''                             '''
    ...
    def isDerivedFrom (self, other : PyRx.RxClass)-> bool :
      '''                             '''
    ...
    def isKindOf (self, rhs: PyRx.RxClass)-> bool :
      '''                             '''
    ...
    def isNullObj (self)-> bool :
      '''                             '''
    ...
    def keepAlive (self, flag: bool)-> None :
      '''                             '''
    ...
    def myParent (self)-> PyRx.RxClass :
      '''                             '''
    ...
    def name (self)-> str :
      '''                             '''
    ...
    def queryX (self, rhs :  PyRx.RxClass)-> PyRx.RxObject :
      '''                             '''
    ...

class RxObject(object):
    def __init__ (self, *args, **kwargs)-> None :
      '''Raises an exception
This class cannot be instantiated from Python'''
    ...

    @staticmethod
    def className ()-> str :
      '''                             '''
    ...
    def comparedTo (self, other: PyRx.RxObject)-> PyRx.Ordering :
      '''                             '''
    ...
    def copyFrom (self, other: PyRx.RxObject)-> None :
      '''                             '''
    ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
      '''                             '''
    ...
    def dispose (self)-> None :
      '''                             '''
    ...
    def implRefCount (self)-> int :
      '''                             '''
    ...
    def isA (self)-> PyRx.RxClass :
      '''                             '''
    ...
    def isKindOf (self, rhs: PyRx.RxClass)-> bool :
      '''                             '''
    ...
    def isNullObj (self)-> bool :
      '''                             '''
    ...
    def keepAlive (self, flag: bool)-> None :
      '''                             '''
    ...
    def queryX (self, rhs: PyRx.RxClass)-> PyRx.RxObject :
      '''                             '''
    ...

class stderr(object):
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> object :

    C++ signature :
        void * __ptr64 __init__(class boost::python::api::object)'''
    ...
    def flush (self, *args, **kwargs)-> None :
      '''flush( (stderr)arg1) -> None :

    C++ signature :
        void flush(class py_redirector<2> {lvalue})'''
    ...
    def write (self, *args, **kwargs)-> None :
      '''write( (stderr)arg1, (str)arg2) -> None :

    C++ signature :
        void write(class py_redirector<2> {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...

class stdout(object):
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> object :

    C++ signature :
        void * __ptr64 __init__(class boost::python::api::object)'''
    ...
    def flush (self, *args, **kwargs)-> None :
      '''flush( (stdout)arg1) -> None :

    C++ signature :
        void flush(class py_redirector<1> {lvalue})'''
    ...
    def write (self, *args, **kwargs)-> None :
      '''write( (stdout)arg1, (str)arg2) -> None :

    C++ signature :
        void write(class py_redirector<1> {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
