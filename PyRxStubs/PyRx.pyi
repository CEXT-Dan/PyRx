import PyRx
import PyGe
import PyGi
import PyGs
import PyDb
import PyAp
import PyEd
import PyPl

class LispType:
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
    def conjugate (self, *args, **kwargs)-> None :
      '''Returns self, the complex conjugate of any int.'''
    ...
    def denominator (self, *args, **kwargs)-> None :
      '''the denominator of a rational number in lowest terms'''
    ...
    def imag (self, *args, **kwargs)-> None :
      '''the imaginary part of a complex number'''
    ...
    def is_integer (self, /) :
      '''Returns True. Exists for duck type compatibility with float.is_integer.'''
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
    def numerator (self, *args, **kwargs)-> None :
      '''the numerator of a rational number in lowest terms'''
    ...
    def real (self, *args, **kwargs)-> None :
      '''the real part of a complex number'''
    ...

class Ordering:
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
    def conjugate (self, *args, **kwargs)-> None :
      '''Returns self, the complex conjugate of any int.'''
    ...
    def denominator (self, *args, **kwargs)-> None :
      '''the denominator of a rational number in lowest terms'''
    ...
    def imag (self, *args, **kwargs)-> None :
      '''the imaginary part of a complex number'''
    ...
    def is_integer (self, /) :
      '''Returns True. Exists for duck type compatibility with float.is_integer.'''
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
    def numerator (self, *args, **kwargs)-> None :
      '''the numerator of a rational number in lowest terms'''
    ...
    def real (self, *args, **kwargs)-> None :
      '''the real part of a complex number'''
    ...

class Overrule:
    def __init__ (self, *args, **kwargs)-> None :
      '''Raises an exception
This class cannot be instantiated from Python'''
    ...
    def addOverrule (self, *args, **kwargs)-> None :
      '''addOverrule( (RxClass)arg1, (Overrule)arg2) -> None :

    C++ signature :
        void addOverrule(class PyRxClass {lvalue},class PyRxOverrule {lvalue})'''
    ...
    def addOverruleLast (self, *args, **kwargs)-> None :
      '''addOverruleLast( (RxClass)arg1, (Overrule)arg2, (bool)arg3) -> None :

    C++ signature :
        void addOverruleLast(class PyRxClass {lvalue},class PyRxOverrule {lvalue},bool)'''
    ...
    def className (self, *args, **kwargs)-> str :
      '''className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def comparedTo (self: RxObject,other: PyRx.RxObject)-> PyRx.Ordering :
      '''                             '''
    ...
    def copyFrom (self: RxObject,other: PyRx.RxObject)-> None :
      '''                             '''
    ...
    def desc (self, *args, **kwargs)-> PyRx.RxClass :
      '''desc() -> RxClass :

    C++ signature :
        class PyRxClass desc()'''
    ...
    def dispose (self: RxObject)-> None :
      '''                             '''
    ...
    def hasOverrule (self, *args, **kwargs)-> bool :
      '''hasOverrule( (RxObject)arg1, (RxClass)arg2) -> bool :

    C++ signature :
        bool hasOverrule(class PyRxObject {lvalue},class PyRxClass {lvalue})'''
    ...
    def implRefCount (self: RxObject)-> int :
      '''                             '''
    ...
    def isA (self: RxObject)-> PyRx.RxClass :
      '''                             '''
    ...
    def isKindOf (self: RxObject,rhs: PyRx.RxClass)-> bool :
      '''                             '''
    ...
    def isNullObj (self: RxObject)-> bool :
      '''                             '''
    ...
    def isOverruling (self, *args, **kwargs)-> bool :
      '''isOverruling() -> bool :

    C++ signature :
        bool isOverruling()'''
    ...
    def keepAlive (self: RxObject,flag: bool)-> None :
      '''                             '''
    ...
    def queryX (self: RxObject,rhs: PyRx.RxClass)-> PyRx.RxObject :
      '''                             '''
    ...
    def removeOverrule (self, *args, **kwargs)-> None :
      '''removeOverrule( (RxClass)arg1, (Overrule)arg2) -> None :

    C++ signature :
        void removeOverrule(class PyRxClass {lvalue},class PyRxOverrule {lvalue})'''
    ...
    def setIsOverruling (self, *args, **kwargs)-> None :
      '''setIsOverruling( (bool)arg1) -> None :

    C++ signature :
        void setIsOverruling(bool)'''
    ...

class RxClass:
    def __init__ (self, *args, **kwargs)-> None :
      '''Raises an exception
This class cannot be instantiated from Python'''
    ...
    def appName (self: RxClass)-> str :
      '''                             '''
    ...

    @staticmethod
    def className ()-> str :
      '''                             '''
    ...
    def comparedTo (self: RxObject,other: PyRx.RxObject)-> PyRx.Ordering :
      '''                             '''
    ...
    def copyFrom (self: RxObject,other: PyRx.RxObject)-> None :
      '''                             '''
    ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
      '''                             '''
    ...
    def dispose (self: RxObject)-> None :
      '''                             '''
    ...
    def dxfName (self: RxClass)-> str :
      '''                             '''
    ...
    def implRefCount (self: RxObject)-> int :
      '''                             '''
    ...
    def isA (self: RxObject)-> PyRx.RxClass :
      '''                             '''
    ...
    def isDerivedFrom (self: RxClass,other : PyRx.RxClass)-> bool :
      '''                             '''
    ...
    def isKindOf (self: RxObject,rhs: PyRx.RxClass)-> bool :
      '''                             '''
    ...
    def isNullObj (self: RxObject)-> bool :
      '''                             '''
    ...
    def keepAlive (self: RxObject,flag: bool)-> None :
      '''                             '''
    ...
    def myParent (self: RxClass)-> PyRx.RxClass :
      '''                             '''
    ...
    def name (self: RxClass)-> str :
      '''                             '''
    ...
    def queryX (self: RxClass,rhs :  PyRx.RxClass)-> PyRx.RxObject :
      '''                             '''
    ...

class RxObject:
    def __init__ (self, *args, **kwargs)-> None :
      '''Raises an exception
This class cannot be instantiated from Python'''
    ...

    @staticmethod
    def className ()-> str :
      '''                             '''
    ...
    def comparedTo (self: RxObject,other: PyRx.RxObject)-> PyRx.Ordering :
      '''                             '''
    ...
    def copyFrom (self: RxObject,other: PyRx.RxObject)-> None :
      '''                             '''
    ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
      '''                             '''
    ...
    def dispose (self: RxObject)-> None :
      '''                             '''
    ...
    def implRefCount (self: RxObject)-> int :
      '''                             '''
    ...
    def isA (self: RxObject)-> PyRx.RxClass :
      '''                             '''
    ...
    def isKindOf (self: RxObject,rhs: PyRx.RxClass)-> bool :
      '''                             '''
    ...
    def isNullObj (self: RxObject)-> bool :
      '''                             '''
    ...
    def keepAlive (self: RxObject,flag: bool)-> None :
      '''                             '''
    ...
    def queryX (self: RxObject,rhs: PyRx.RxClass)-> PyRx.RxObject :
      '''                             '''
    ...

class stderr:
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

class stdout:
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
