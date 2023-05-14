
class AcGeError:
    def __add__ (self, value, /):
      '''Return self+value.'''
    ...
    def __eq__ (self, value, /):
      '''Return self==value.'''
    ...
    def __init__ (self, /, *args, **kwargs):
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
    def __mul__ (self, value, /):
      '''Return self*value.'''
    ...
    def __ne__ (self, value, /):
      '''Return self!=value.'''
    ...
    def __sub__ (self, value, /):
      '''Return self-value.'''
    ...
    def __truediv__ (self, value, /):
      '''Return self/value.'''
    ...
    def as_integer_ratio (self, /):
      '''Return integer ratio.

Return a pair of integers, whose ratio is exactly equal to the original int
and with a positive denominator.

>>> (10).as_integer_ratio()
(10, 1)
>>> (-10).as_integer_ratio()
(-10, 1)
>>> (0).as_integer_ratio()
(0, 1)'''
    ...
    def bit_count (self, /):
      '''Number of ones in the binary representation of the absolute value of self.

Also known as the population count.

>>> bin(13)
'0b1101'
>>> (13).bit_count()
3'''
    ...
    def bit_length (self, /):
      '''Number of bits necessary to represent self in binary.

>>> bin(37)
'0b100101'
>>> (37).bit_length()
6'''
    ...
    def conjugate (self, *args, **kwargs):
      '''Returns self, the complex conjugate of any int.'''
    ...
    def denominator (self, *args, **kwargs):
      '''the denominator of a rational number in lowest terms'''
    ...
    def from_bytes (bytes, byteorder, *, signed=False):
      '''Return the integer represented by the given array of bytes.

  bytes
    Holds the array of bytes to convert.  The argument must either
    support the buffer protocol or be an iterable object producing bytes.
    Bytes and bytearray are examples of built-in objects that support the
    buffer protocol.
  byteorder
    The byte order used to represent the integer.  If byteorder is 'big',
    the most significant byte is at the beginning of the byte array.  If
    byteorder is 'little', the most significant byte is at the end of the
    byte array.  To request the native byte order of the host system, use
    `sys.byteorder' as the byte order value.
  signed
    Indicates whether two's complement is used to represent the integer.'''
    ...
    def imag (self, *args, **kwargs):
      '''the imaginary part of a complex number'''
    ...
    def k0Arg1 (self, *args, **kwargs):
      '''None'''
    ...
    def k0Arg2 (self, *args, **kwargs):
      '''None'''
    ...
    def k0This (self, *args, **kwargs):
      '''None'''
    ...
    def kArg1InsideThis (self, *args, **kwargs):
      '''None'''
    ...
    def kArg1OnThis (self, *args, **kwargs):
      '''None'''
    ...
    def kArg1TooBig (self, *args, **kwargs):
      '''None'''
    ...
    def kEqualArg1Arg2 (self, *args, **kwargs):
      '''None'''
    ...
    def kEqualArg1Arg3 (self, *args, **kwargs):
      '''None'''
    ...
    def kEqualArg2Arg3 (self, *args, **kwargs):
      '''None'''
    ...
    def kLinearlyDependentArg1Arg2Arg3 (self, *args, **kwargs):
      '''None'''
    ...
    def kOk (self, *args, **kwargs):
      '''None'''
    ...
    def kPerpendicularArg1Arg2 (self, *args, **kwargs):
      '''None'''
    ...
    def name (self, *args, **kwargs):
      '''None'''
    ...
    def names (self, *args, **kwargs):
      '''dict() -> new empty dictionary
dict(mapping) -> new dictionary initialized from a mapping object's
    (key, value) pairs
dict(iterable) -> new dictionary initialized as if via:
    d = {}
    for k, v in iterable:
        d[k] = v
dict(**kwargs) -> new dictionary initialized with the name=value pairs
    in the keyword argument list.  For example:  dict(one=1, two=2)'''
    ...
    def numerator (self, *args, **kwargs):
      '''the numerator of a rational number in lowest terms'''
    ...
    def real (self, *args, **kwargs):
      '''the real part of a complex number'''
    ...
    def to_bytes (self, /, length, byteorder, *, signed=False):
      '''Return an array of bytes representing an integer.

  length
    Length of bytes object to use.  An OverflowError is raised if the
    integer is not representable with the given number of bytes.
  byteorder
    The byte order used to represent the integer.  If byteorder is 'big',
    the most significant byte is at the beginning of the byte array.  If
    byteorder is 'little', the most significant byte is at the end of the
    byte array.  To request the native byte order of the host system, use
    `sys.byteorder' as the byte order value.
  signed
    Determines whether two's complement is used to represent the integer.
    If signed is False and a negative integer is given, an OverflowError
    is raised.'''
    ...
    def values (self, *args, **kwargs):
      '''dict() -> new empty dictionary
dict(mapping) -> new dictionary initialized from a mapping object's
    (key, value) pairs
dict(iterable) -> new dictionary initialized as if via:
    d = {}
    for k, v in iterable:
        d[k] = v
dict(**kwargs) -> new dictionary initialized with the name=value pairs
    in the keyword argument list.  For example:  dict(one=1, two=2)'''
    ...

class BoundBlock2d:
    def __eq__ (self, *args, **kwargs):
      '''
__eq__( (Entity2d)arg1, (Entity2d)arg2) -> bool :

    C++ signature :
        bool __eq__(class PyGeEntity2d {lvalue},class PyGeEntity2d)'''
    ...
    def __init__ (self, *args, **kwargs):
      '''
__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1, (Point2d)arg2, (Point2d)arg3) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class AcGePoint2d,class AcGePoint2d)

__init__( (object)arg1, (Point2d)arg2, (Vector2d)arg3, (Vector2d)arg4) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class AcGePoint2d,class AcGeVector2d,class AcGeVector2d)'''
    ...
    def __ne__ (self, *args, **kwargs):
      '''
__ne__( (Entity2d)arg1, (Entity2d)arg2) -> bool :

    C++ signature :
        bool __ne__(class PyGeEntity2d {lvalue},class PyGeEntity2d)'''
    ...
    def className (self, *args, **kwargs):
      '''
className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def contains (self, *args, **kwargs):
      '''
contains( (BoundBlock2d)arg1, (Point2d)arg2) -> bool :

    C++ signature :
        bool contains(class PyGeBoundBlock2d {lvalue},class AcGePoint2d)'''
    ...
    def copy (self, *args, **kwargs):
      '''
copy( (Entity2d)arg1) -> Entity2d :

    C++ signature :
        class PyGeEntity2d copy(class PyGeEntity2d {lvalue})'''
    ...
    def extend (self, *args, **kwargs):
      '''
extend( (BoundBlock2d)arg1, (Point2d)arg2) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d {lvalue} extend(class PyGeBoundBlock2d {lvalue},class AcGePoint2d)'''
    ...
    def getBasePoint (self, *args, **kwargs):
      '''
getBasePoint( (BoundBlock2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d getBasePoint(class PyGeBoundBlock2d {lvalue})'''
    ...
    def getDirection1 (self, *args, **kwargs):
      '''
getDirection1( (BoundBlock2d)arg1) -> Vector2d :

    C++ signature :
        class AcGeVector2d getDirection1(class PyGeBoundBlock2d {lvalue})'''
    ...
    def getDirection2 (self, *args, **kwargs):
      '''
getDirection2( (BoundBlock2d)arg1) -> Vector2d :

    C++ signature :
        class AcGeVector2d getDirection2(class PyGeBoundBlock2d {lvalue})'''
    ...
    def getMaxPoint (self, *args, **kwargs):
      '''
getMaxPoint( (BoundBlock2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d getMaxPoint(class PyGeBoundBlock2d {lvalue})'''
    ...
    def getMinPoint (self, *args, **kwargs):
      '''
getMinPoint( (BoundBlock2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d getMinPoint(class PyGeBoundBlock2d {lvalue})'''
    ...
    def isBox (self, *args, **kwargs):
      '''
isBox( (BoundBlock2d)arg1) -> bool :

    C++ signature :
        bool isBox(class PyGeBoundBlock2d {lvalue})'''
    ...
    def isDisjoint (self, *args, **kwargs):
      '''
isDisjoint( (BoundBlock2d)arg1, (BoundBlock2d)arg2) -> bool :

    C++ signature :
        bool isDisjoint(class PyGeBoundBlock2d {lvalue},class PyGeBoundBlock2d)'''
    ...
    def isEqualTo (self, *args, **kwargs):
      '''
isEqualTo( (Entity2d)arg1, (Entity2d)arg2) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity2d {lvalue},class PyGeEntity2d)

isEqualTo( (Entity2d)arg1, (Entity2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity2d {lvalue},class PyGeEntity2d,class AcGeTol)'''
    ...
    def isKindOf (self, *args, **kwargs):
      '''
isKindOf( (Entity2d)arg1, (EntityId)arg2) -> bool :

    C++ signature :
        bool isKindOf(class PyGeEntity2d {lvalue},enum AcGe::EntityId)'''
    ...
    def isNull (self, *args, **kwargs):
      '''
isNull( (Entity2d)arg1) -> bool :

    C++ signature :
        bool isNull(class PyGeEntity2d {lvalue})'''
    ...
    def isOn (self, *args, **kwargs):
      '''
isOn( (Entity2d)arg1, (Point2d)arg2) -> bool :

    C++ signature :
        bool isOn(class PyGeEntity2d {lvalue},class AcGePoint2d)

isOn( (Entity2d)arg1, (Point2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeEntity2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def mirror (self, *args, **kwargs):
      '''
mirror( (Entity2d)arg1, (Line2d)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} mirror(class PyGeEntity2d {lvalue},class PyGeLine2d)'''
    ...
    def rotateBy (self, *args, **kwargs):
      '''
rotateBy( (Entity2d)arg1, (float)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} rotateBy(class PyGeEntity2d {lvalue},double)

rotateBy( (Entity2d)arg1, (float)arg2, (Point2d)arg3) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} rotateBy(class PyGeEntity2d {lvalue},double,class AcGePoint2d)'''
    ...
    def scaleBy (self, *args, **kwargs):
      '''
scaleBy( (Entity2d)arg1, (float)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} scaleBy(class PyGeEntity2d {lvalue},double)

scaleBy( (Entity2d)arg1, (float)arg2, (Point2d)arg3) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} scaleBy(class PyGeEntity2d {lvalue},double,class AcGePoint2d)'''
    ...
    def set (self, *args, **kwargs):
      '''
set( (BoundBlock2d)arg1, (Point2d)arg2, (Point2d)arg3) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d {lvalue} set(class PyGeBoundBlock2d {lvalue},class AcGePoint2d,class AcGePoint2d)

set( (BoundBlock2d)arg1, (Point2d)arg2, (Vector2d)arg3, (Vector2d)arg4) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d {lvalue} set(class PyGeBoundBlock2d {lvalue},class AcGePoint2d,class AcGeVector2d,class AcGeVector2d)'''
    ...
    def setToBox (self, *args, **kwargs):
      '''
setToBox( (BoundBlock2d)arg1, (bool)arg2) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d {lvalue} setToBox(class PyGeBoundBlock2d {lvalue},bool)'''
    ...
    def swell (self, *args, **kwargs):
      '''
swell( (BoundBlock2d)arg1, (float)arg2) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d {lvalue} swell(class PyGeBoundBlock2d {lvalue},double)'''
    ...
    def transformBy (self, *args, **kwargs):
      '''
transformBy( (Entity2d)arg1, (Matrix2d)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} transformBy(class PyGeEntity2d {lvalue},class AcGeMatrix2d)'''
    ...
    def translateBy (self, *args, **kwargs):
      '''
translateBy( (Entity2d)arg1, (Vector2d)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} translateBy(class PyGeEntity2d {lvalue},class AcGeVector2d)'''
    ...
    def type (self, *args, **kwargs):
      '''
type( (Entity2d)arg1) -> EntityId :

    C++ signature :
        enum AcGe::EntityId type(class PyGeEntity2d {lvalue})'''
    ...

class BoundBlock3d:
    def __eq__ (self, *args, **kwargs):
      '''
__eq__( (Entity3d)arg1, (Entity3d)arg2) -> bool :

    C++ signature :
        bool __eq__(class PyGeEntity3d {lvalue},class PyGeEntity3d)'''
    ...
    def __init__ (self, *args, **kwargs):
      '''
__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1, (Point3d)arg2, (Vector3d)arg3, (Vector3d)arg4, (Vector3d)arg5) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class AcGePoint3d,class AcGeVector3d,class AcGeVector3d,class AcGeVector3d)'''
    ...
    def __ne__ (self, *args, **kwargs):
      '''
__ne__( (Entity3d)arg1, (Entity3d)arg2) -> bool :

    C++ signature :
        bool __ne__(class PyGeEntity3d {lvalue},class PyGeEntity3d)'''
    ...
    def className (self, *args, **kwargs):
      '''
className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def contains (self, *args, **kwargs):
      '''
contains( (BoundBlock3d)arg1, (Point3d)arg2) -> bool :

    C++ signature :
        bool contains(class PyGeBoundBlock3d {lvalue},class AcGePoint3d)'''
    ...
    def copy (self, *args, **kwargs):
      '''
copy( (Entity3d)arg1) -> Entity3d :

    C++ signature :
        class PyGeEntity3d copy(class PyGeEntity3d {lvalue})'''
    ...
    def extend (self, *args, **kwargs):
      '''
extend( (BoundBlock3d)arg1, (Point3d)arg2) -> BoundBlock3d :

    C++ signature :
        class PyGeBoundBlock3d {lvalue} extend(class PyGeBoundBlock3d {lvalue},class AcGePoint3d)'''
    ...
    def getBasePoint (self, *args, **kwargs):
      '''
getBasePoint( (BoundBlock3d)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d getBasePoint(class PyGeBoundBlock3d {lvalue})'''
    ...
    def getDirection1 (self, *args, **kwargs):
      '''
getDirection1( (BoundBlock3d)arg1) -> Vector3d :

    C++ signature :
        class AcGeVector3d getDirection1(class PyGeBoundBlock3d {lvalue})'''
    ...
    def getDirection3 (self, *args, **kwargs):
      '''
getDirection3( (BoundBlock3d)arg1) -> Vector3d :

    C++ signature :
        class AcGeVector3d getDirection3(class PyGeBoundBlock3d {lvalue})

getDirection3( (BoundBlock3d)arg1) -> Vector3d :

    C++ signature :
        class AcGeVector3d getDirection3(class PyGeBoundBlock3d {lvalue})'''
    ...
    def getMaxPoint (self, *args, **kwargs):
      '''
getMaxPoint( (BoundBlock3d)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d getMaxPoint(class PyGeBoundBlock3d {lvalue})'''
    ...
    def getMinPoint (self, *args, **kwargs):
      '''
getMinPoint( (BoundBlock3d)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d getMinPoint(class PyGeBoundBlock3d {lvalue})'''
    ...
    def isBox (self, *args, **kwargs):
      '''
isBox( (BoundBlock3d)arg1) -> bool :

    C++ signature :
        bool isBox(class PyGeBoundBlock3d {lvalue})'''
    ...
    def isDisjoint (self, *args, **kwargs):
      '''
isDisjoint( (BoundBlock3d)arg1, (BoundBlock3d)arg2) -> bool :

    C++ signature :
        bool isDisjoint(class PyGeBoundBlock3d {lvalue},class PyGeBoundBlock3d)'''
    ...
    def isEqualTo (self, *args, **kwargs):
      '''
isEqualTo( (Entity3d)arg1, (Entity3d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity3d {lvalue},class PyGeEntity3d,class AcGeTol)'''
    ...
    def isKindOf (self, *args, **kwargs):
      '''
isKindOf( (Entity3d)arg1, (EntityId)arg2) -> bool :

    C++ signature :
        bool isKindOf(class PyGeEntity3d {lvalue},enum AcGe::EntityId)'''
    ...
    def isNull (self, *args, **kwargs):
      '''
isNull( (Entity3d)arg1) -> bool :

    C++ signature :
        bool isNull(class PyGeEntity3d {lvalue})'''
    ...
    def isOn (self, *args, **kwargs):
      '''
isOn( (Entity3d)arg1, (Point3d)arg2) -> bool :

    C++ signature :
        bool isOn(class PyGeEntity3d {lvalue},class AcGePoint3d)

isOn( (Entity3d)arg1, (Point3d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeEntity3d {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def mirror (self, *args, **kwargs):
      '''
mirror( (Entity3d)arg1, (Plane)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} mirror(class PyGeEntity3d {lvalue},class PyGePlane)'''
    ...
    def rotateBy (self, *args, **kwargs):
      '''
rotateBy( (Entity3d)arg1, (float)arg2, (Vector3d)arg3) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} rotateBy(class PyGeEntity3d {lvalue},double,class AcGeVector3d)

rotateBy( (Entity3d)arg1, (float)arg2, (Vector3d)arg3, (Point3d)arg4) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} rotateBy(class PyGeEntity3d {lvalue},double,class AcGeVector3d,class AcGePoint3d)'''
    ...
    def scaleBy (self, *args, **kwargs):
      '''
scaleBy( (Entity3d)arg1, (float)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} scaleBy(class PyGeEntity3d {lvalue},double)

scaleBy( (Entity3d)arg1, (float)arg2, (Point3d)arg3) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} scaleBy(class PyGeEntity3d {lvalue},double,class AcGePoint3d)'''
    ...
    def set (self, *args, **kwargs):
      '''
set( (BoundBlock3d)arg1, (Point3d)arg2, (Point3d)arg3) -> BoundBlock3d :

    C++ signature :
        class PyGeBoundBlock3d {lvalue} set(class PyGeBoundBlock3d {lvalue},class AcGePoint3d,class AcGePoint3d)

set( (BoundBlock3d)arg1, (Point3d)arg2, (Vector3d)arg3, (Vector3d)arg4, (Vector3d)arg5) -> BoundBlock3d :

    C++ signature :
        class PyGeBoundBlock3d {lvalue} set(class PyGeBoundBlock3d {lvalue},class AcGePoint3d,class AcGeVector3d,class AcGeVector3d,class AcGeVector3d)'''
    ...
    def setToBox (self, *args, **kwargs):
      '''
setToBox( (BoundBlock3d)arg1, (bool)arg2) -> BoundBlock3d :

    C++ signature :
        class PyGeBoundBlock3d {lvalue} setToBox(class PyGeBoundBlock3d {lvalue},bool)'''
    ...
    def swell (self, *args, **kwargs):
      '''
swell( (BoundBlock3d)arg1, (float)arg2) -> BoundBlock3d :

    C++ signature :
        class PyGeBoundBlock3d {lvalue} swell(class PyGeBoundBlock3d {lvalue},double)'''
    ...
    def transformBy (self, *args, **kwargs):
      '''
transformBy( (Entity3d)arg1, (Matrix3d)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} transformBy(class PyGeEntity3d {lvalue},class AcGeMatrix3d)'''
    ...
    def translateBy (self, *args, **kwargs):
      '''
translateBy( (Entity3d)arg1, (Vector3d)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} translateBy(class PyGeEntity3d {lvalue},class AcGeVector3d)'''
    ...
    def type (self, *args, **kwargs):
      '''
type( (Entity3d)arg1) -> EntityId :

    C++ signature :
        enum AcGe::EntityId type(class PyGeEntity3d {lvalue})'''
    ...

class CircArc2d:
    def __eq__ (self, *args, **kwargs):
      '''
__eq__( (Entity2d)arg1, (Entity2d)arg2) -> bool :

    C++ signature :
        bool __eq__(class PyGeEntity2d {lvalue},class PyGeEntity2d)'''
    ...
    def __init__ (self, *args, **kwargs):
      '''
__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1, (Point2d)arg2, (float)arg3) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class AcGePoint2d,double)

__init__( (object)arg1, (Point2d)arg2, (float)arg3, (float)arg4, (float)arg5) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class AcGePoint2d,double,double,double)

__init__( (object)arg1, (Point2d)arg2, (float)arg3, (float)arg4, (float)arg5, (Vector2d)arg6, (bool)arg7) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class AcGePoint2d,double,double,double,class AcGeVector2d,bool)

__init__( (object)arg1, (Point2d)arg2, (Point2d)arg3, (Point2d)arg4) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class AcGePoint2d,class AcGePoint2d,class AcGePoint2d)

__init__( (object)arg1, (Point2d)arg2, (Point2d)arg3, (float)arg4, (bool)arg5) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class AcGePoint2d,class AcGePoint2d,double,bool)'''
    ...
    def __ne__ (self, *args, **kwargs):
      '''
__ne__( (Entity2d)arg1, (Entity2d)arg2) -> bool :

    C++ signature :
        bool __ne__(class PyGeEntity2d {lvalue},class PyGeEntity2d)'''
    ...
    def area (self, *args, **kwargs):
      '''
area( (Curve2d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double area(class PyGeCurve2d {lvalue},double,double)

area( (Curve2d)arg1, (float)arg2, (float)arg3, (Tol)arg4) -> float :

    C++ signature :
        double area(class PyGeCurve2d {lvalue},double,double,class AcGeTol)'''
    ...
    def boundBlock (self, *args, **kwargs):
      '''
boundBlock( (Curve2d)arg1) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d boundBlock(class PyGeCurve2d {lvalue})

boundBlock( (Curve2d)arg1, (Interval)arg2) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d boundBlock(class PyGeCurve2d {lvalue},class PyGeInterval)'''
    ...
    def center (self, *args, **kwargs):
      '''
center( (CircArc2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d center(class PyGeCircArc2d {lvalue})'''
    ...
    def className (self, *args, **kwargs):
      '''
className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def closestPointTo (self, *args, **kwargs):
      '''
closestPointTo( (Curve2d)arg1, (Point2d)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d closestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d)

closestPointTo( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> Point2d :

    C++ signature :
        class AcGePoint2d closestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)

closestPointTo( (Curve2d)arg1, (Curve2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointTo(class PyGeCurve2d {lvalue},class PyGeCurve2d)

closestPointTo( (Curve2d)arg1, (Curve2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointTo(class PyGeCurve2d {lvalue},class PyGeCurve2d,class AcGeTol)'''
    ...
    def copy (self, *args, **kwargs):
      '''
copy( (Entity2d)arg1) -> Entity2d :

    C++ signature :
        class PyGeEntity2d copy(class PyGeEntity2d {lvalue})'''
    ...
    def distanceTo (self, *args, **kwargs):
      '''
distanceTo( (Curve2d)arg1, (Point2d)arg2) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class AcGePoint2d)

distanceTo( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)

distanceTo( (Curve2d)arg1, (Curve2d)arg2) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class PyGeCurve2d)

distanceTo( (Curve2d)arg1, (Curve2d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class PyGeCurve2d,class AcGeTol)'''
    ...
    def endAng (self, *args, **kwargs):
      '''
endAng( (CircArc2d)arg1) -> float :

    C++ signature :
        double endAng(class PyGeCircArc2d {lvalue})'''
    ...
    def endPoint (self, *args, **kwargs):
      '''
endPoint( (CircArc2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d endPoint(class PyGeCircArc2d {lvalue})'''
    ...
    def evalPoint (self, *args, **kwargs):
      '''
evalPoint( (Curve2d)arg1, (float)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d evalPoint(class PyGeCurve2d {lvalue},double)

evalPoint( (Curve2d)arg1, (float)arg2, (int)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple evalPoint(class PyGeCurve2d {lvalue},double,int)'''
    ...
    def explode (self, *args, **kwargs):
      '''
explode( (Curve2d)arg1) -> list :

    C++ signature :
        class boost::python::list explode(class PyGeCurve2d {lvalue})

explode( (Curve2d)arg1, (Interval)arg2) -> list :

    C++ signature :
        class boost::python::list explode(class PyGeCurve2d {lvalue},class PyGeInterval)'''
    ...
    def getClosestPointTo (self, *args, **kwargs):
      '''
getClosestPointTo( (Curve2d)arg1, (Point2d)arg2) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getClosestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d)

getClosestPointTo( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getClosestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def getClosestPointsTo (self, *args, **kwargs):
      '''
getClosestPointsTo( (Curve2d)arg1, (Curve2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getClosestPointsTo(class PyGeCurve2d {lvalue},class PyGeCurve2d)

getClosestPointsTo( (Curve2d)arg1, (Curve2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple getClosestPointsTo(class PyGeCurve2d {lvalue},class PyGeCurve2d,class AcGeTol)'''
    ...
    def getEndPoint (self, *args, **kwargs):
      '''
getEndPoint( (Curve2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d getEndPoint(class PyGeCurve2d {lvalue})'''
    ...
    def getInterval (self, *args, **kwargs):
      '''
getInterval( (Curve2d)arg1) -> Interval :

    C++ signature :
        class PyGeInterval getInterval(class PyGeCurve2d {lvalue})'''
    ...
    def getNormalPoint (self, *args, **kwargs):
      '''
getNormalPoint( (Curve2d)arg1, (Point2d)arg2) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getNormalPoint(class PyGeCurve2d {lvalue},class AcGePoint2d)

getNormalPoint( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getNormalPoint(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def getSamplePoints (self, *args, **kwargs):
      '''
getSamplePoints( (Curve2d)arg1, (int)arg2) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve2d {lvalue},int)

getSamplePoints( (Curve2d)arg1, (float)arg2, (float)arg3, (float)arg4) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve2d {lvalue},double,double,double)'''
    ...
    def getSplitCurves (self, *args, **kwargs):
      '''
getSplitCurves( (Curve2d)arg1, (float)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getSplitCurves(class PyGeCurve2d {lvalue},double)'''
    ...
    def getStartPoint (self, *args, **kwargs):
      '''
getStartPoint( (Curve2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d getStartPoint(class PyGeCurve2d {lvalue})'''
    ...
    def getTrimmedOffset (self, *args, **kwargs):
      '''
getTrimmedOffset( (Curve2d)arg1, (float)arg2, (OffsetCrvExtType)arg3) -> list :

    C++ signature :
        class boost::python::list getTrimmedOffset(class PyGeCurve2d {lvalue},double,enum AcGe::OffsetCrvExtType)

getTrimmedOffset( (Curve2d)arg1, (float)arg2, (OffsetCrvExtType)arg3, (Tol)arg4) -> list :

    C++ signature :
        class boost::python::list getTrimmedOffset(class PyGeCurve2d {lvalue},double,enum AcGe::OffsetCrvExtType,class AcGeTol)'''
    ...
    def hasEndPoint (self, *args, **kwargs):
      '''
hasEndPoint( (Curve2d)arg1) -> bool :

    C++ signature :
        bool hasEndPoint(class PyGeCurve2d {lvalue})'''
    ...
    def hasStartPoint (self, *args, **kwargs):
      '''
hasStartPoint( (Curve2d)arg1) -> bool :

    C++ signature :
        bool hasStartPoint(class PyGeCurve2d {lvalue})'''
    ...
    def intersectWith (self, *args, **kwargs):
      '''
intersectWith( (CircArc2d)arg1, (LinearEnt2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple intersectWith(class PyGeCircArc2d {lvalue},class PyGeLinearEnt2d)

intersectWith( (CircArc2d)arg1, (LinearEnt2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple intersectWith(class PyGeCircArc2d {lvalue},class PyGeLinearEnt2d,class AcGeTol)

intersectWith( (CircArc2d)arg1, (CircArc2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple intersectWith(class PyGeCircArc2d {lvalue},class PyGeCircArc2d)

intersectWith( (CircArc2d)arg1, (CircArc2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple intersectWith(class PyGeCircArc2d {lvalue},class PyGeCircArc2d,class AcGeTol)'''
    ...
    def isClockWise (self, *args, **kwargs):
      '''
isClockWise( (CircArc2d)arg1) -> bool :

    C++ signature :
        bool isClockWise(class PyGeCircArc2d {lvalue})'''
    ...
    def isClosed (self, *args, **kwargs):
      '''
isClosed( (Curve2d)arg1) -> bool :

    C++ signature :
        bool isClosed(class PyGeCurve2d {lvalue})

isClosed( (Curve2d)arg1, (Tol)arg2) -> bool :

    C++ signature :
        bool isClosed(class PyGeCurve2d {lvalue},class AcGeTol)'''
    ...
    def isDegenerate (self, *args, **kwargs):
      '''
isDegenerate( (Curve2d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isDegenerate(class PyGeCurve2d {lvalue})

isDegenerate( (Curve2d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isDegenerate(class PyGeCurve2d {lvalue},class AcGeTol)'''
    ...
    def isEqualTo (self, *args, **kwargs):
      '''
isEqualTo( (Entity2d)arg1, (Entity2d)arg2) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity2d {lvalue},class PyGeEntity2d)

isEqualTo( (Entity2d)arg1, (Entity2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity2d {lvalue},class PyGeEntity2d,class AcGeTol)'''
    ...
    def isInside (self, *args, **kwargs):
      '''
isInside( (CircArc2d)arg1, (Point2d)arg2) -> bool :

    C++ signature :
        bool isInside(class PyGeCircArc2d {lvalue},class AcGePoint2d)

isInside( (CircArc2d)arg1, (Point2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isInside(class PyGeCircArc2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def isKindOf (self, *args, **kwargs):
      '''
isKindOf( (Entity2d)arg1, (EntityId)arg2) -> bool :

    C++ signature :
        bool isKindOf(class PyGeEntity2d {lvalue},enum AcGe::EntityId)'''
    ...
    def isLinear (self, *args, **kwargs):
      '''
isLinear( (Curve2d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isLinear(class PyGeCurve2d {lvalue})

isLinear( (Curve2d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isLinear(class PyGeCurve2d {lvalue},class AcGeTol)'''
    ...
    def isNull (self, *args, **kwargs):
      '''
isNull( (Entity2d)arg1) -> bool :

    C++ signature :
        bool isNull(class PyGeEntity2d {lvalue})'''
    ...
    def isOn (self, *args, **kwargs):
      '''
isOn( (Curve2d)arg1, (Point2d)arg2) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve2d {lvalue},class AcGePoint2d)

isOn( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)

isOn( (Curve2d)arg1, (Point2d)arg2, (float)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve2d {lvalue},class AcGePoint2d,double {lvalue})

isOn( (Curve2d)arg1, (Point2d)arg2, (float)arg3, (Tol)arg4) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve2d {lvalue},class AcGePoint2d,double {lvalue},class AcGeTol)

isOn( (Curve2d)arg1, (float)arg2) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve2d {lvalue},double)

isOn( (Curve2d)arg1, (float)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve2d {lvalue},double,class AcGeTol)'''
    ...
    def isPeriodic (self, *args, **kwargs):
      '''
isPeriodic( (Curve2d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isPeriodic(class PyGeCurve2d {lvalue})'''
    ...
    def length (self, *args, **kwargs):
      '''
length( (Curve2d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double length(class PyGeCurve2d {lvalue},double,double)

length( (Curve2d)arg1, (float)arg2, (float)arg3, (float)arg4) -> float :

    C++ signature :
        double length(class PyGeCurve2d {lvalue},double,double,double)'''
    ...
    def mirror (self, *args, **kwargs):
      '''
mirror( (Entity2d)arg1, (Line2d)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} mirror(class PyGeEntity2d {lvalue},class PyGeLine2d)'''
    ...
    def orthoBoundBlock (self, *args, **kwargs):
      '''
orthoBoundBlock( (Curve2d)arg1) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d orthoBoundBlock(class PyGeCurve2d {lvalue})

orthoBoundBlock( (Curve2d)arg1, (Interval)arg2) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d orthoBoundBlock(class PyGeCurve2d {lvalue},class PyGeInterval)'''
    ...
    def paramAtLength (self, *args, **kwargs):
      '''
paramAtLength( (Curve2d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double paramAtLength(class PyGeCurve2d {lvalue},double,double)

paramAtLength( (Curve2d)arg1, (float)arg2, (float)arg3, (bool)arg4, (float)arg5) -> float :

    C++ signature :
        double paramAtLength(class PyGeCurve2d {lvalue},double,double,bool,double)'''
    ...
    def paramOf (self, *args, **kwargs):
      '''
paramOf( (Curve2d)arg1, (Point2d)arg2) -> float :

    C++ signature :
        double paramOf(class PyGeCurve2d {lvalue},class AcGePoint2d)

paramOf( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double paramOf(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def radius (self, *args, **kwargs):
      '''
radius( (CircArc2d)arg1) -> float :

    C++ signature :
        double radius(class PyGeCircArc2d {lvalue})'''
    ...
    def refVec (self, *args, **kwargs):
      '''
refVec( (CircArc2d)arg1) -> Vector2d :

    C++ signature :
        class AcGeVector2d refVec(class PyGeCircArc2d {lvalue})'''
    ...
    def reverseParam (self, *args, **kwargs):
      '''
reverseParam( (Curve2d)arg1) -> Curve2d :

    C++ signature :
        class PyGeCurve2d {lvalue} reverseParam(class PyGeCurve2d {lvalue})'''
    ...
    def rotateBy (self, *args, **kwargs):
      '''
rotateBy( (Entity2d)arg1, (float)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} rotateBy(class PyGeEntity2d {lvalue},double)

rotateBy( (Entity2d)arg1, (float)arg2, (Point2d)arg3) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} rotateBy(class PyGeEntity2d {lvalue},double,class AcGePoint2d)'''
    ...
    def scaleBy (self, *args, **kwargs):
      '''
scaleBy( (Entity2d)arg1, (float)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} scaleBy(class PyGeEntity2d {lvalue},double)

scaleBy( (Entity2d)arg1, (float)arg2, (Point2d)arg3) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} scaleBy(class PyGeEntity2d {lvalue},double,class AcGePoint2d)'''
    ...
    def set (self, *args, **kwargs):
      '''
set( (CircArc2d)arg1, (Point2d)arg2, (float)arg3) -> CircArc2d :

    C++ signature :
        class PyGeCircArc2d {lvalue} set(class PyGeCircArc2d {lvalue},class AcGePoint2d,double)

set( (CircArc2d)arg1, (Point2d)arg2, (float)arg3, (float)arg4, (float)arg5, (Vector2d)arg6, (bool)arg7) -> CircArc2d :

    C++ signature :
        class PyGeCircArc2d {lvalue} set(class PyGeCircArc2d {lvalue},class AcGePoint2d,double,double,double,class AcGeVector2d,bool)

set( (CircArc2d)arg1, (Point2d)arg2, (Point2d)arg3, (Point2d)arg4) -> CircArc2d :

    C++ signature :
        class PyGeCircArc2d {lvalue} set(class PyGeCircArc2d {lvalue},class AcGePoint2d,class AcGePoint2d,class AcGePoint2d)

set( (CircArc2d)arg1, (Point2d)arg2, (Point2d)arg3, (float)arg4, (bool)arg5) -> CircArc2d :

    C++ signature :
        class PyGeCircArc2d {lvalue} set(class PyGeCircArc2d {lvalue},class AcGePoint2d,class AcGePoint2d,double,bool)

set( (CircArc2d)arg1, (Curve2d)arg2, (Curve2d)arg3, (float)arg4) -> CircArc2d :

    C++ signature :
        class PyGeCircArc2d {lvalue} set(class PyGeCircArc2d {lvalue},class PyGeCurve2d,class PyGeCurve2d,double)

set( (CircArc2d)arg1, (Curve2d)arg2, (Curve2d)arg3, (Curve2d)arg4) -> CircArc2d :

    C++ signature :
        class PyGeCircArc2d {lvalue} set(class PyGeCircArc2d {lvalue},class PyGeCurve2d,class PyGeCurve2d,class PyGeCurve2d)'''
    ...
    def setAngles (self, *args, **kwargs):
      '''
setAngles( (CircArc2d)arg1, (float)arg2, (float)arg3) -> CircArc2d :

    C++ signature :
        class PyGeCircArc2d {lvalue} setAngles(class PyGeCircArc2d {lvalue},double,double)'''
    ...
    def setCenter (self, *args, **kwargs):
      '''
setCenter( (CircArc2d)arg1, (Point2d)arg2) -> CircArc2d :

    C++ signature :
        class PyGeCircArc2d {lvalue} setCenter(class PyGeCircArc2d {lvalue},class AcGePoint2d)'''
    ...
    def setInterval (self, *args, **kwargs):
      '''
setInterval( (Curve2d)arg1) -> Curve2d :

    C++ signature :
        class PyGeCurve2d {lvalue} setInterval(class PyGeCurve2d {lvalue})

setInterval( (Curve2d)arg1, (Interval)arg2) -> bool :

    C++ signature :
        bool setInterval(class PyGeCurve2d {lvalue},class PyGeInterval)'''
    ...
    def setRadius (self, *args, **kwargs):
      '''
setRadius( (CircArc2d)arg1, (float)arg2) -> CircArc2d :

    C++ signature :
        class PyGeCircArc2d {lvalue} setRadius(class PyGeCircArc2d {lvalue},double)'''
    ...
    def setRefVec (self, *args, **kwargs):
      '''
setRefVec( (CircArc2d)arg1, (Vector2d)arg2) -> CircArc2d :

    C++ signature :
        class PyGeCircArc2d {lvalue} setRefVec(class PyGeCircArc2d {lvalue},class AcGeVector2d)'''
    ...
    def setToComplement (self, *args, **kwargs):
      '''
setToComplement( (CircArc2d)arg1) -> CircArc2d :

    C++ signature :
        class PyGeCircArc2d {lvalue} setToComplement(class PyGeCircArc2d {lvalue})'''
    ...
    def startAng (self, *args, **kwargs):
      '''
startAng( (CircArc2d)arg1) -> float :

    C++ signature :
        double startAng(class PyGeCircArc2d {lvalue})'''
    ...
    def startPoint (self, *args, **kwargs):
      '''
startPoint( (CircArc2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d startPoint(class PyGeCircArc2d {lvalue})'''
    ...
    def tangent (self, *args, **kwargs):
      '''
tangent( (CircArc2d)arg1, (Point2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple tangent(class PyGeCircArc2d {lvalue},class AcGePoint2d)

tangent( (CircArc2d)arg1, (Point2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple tangent(class PyGeCircArc2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def transformBy (self, *args, **kwargs):
      '''
transformBy( (Entity2d)arg1, (Matrix2d)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} transformBy(class PyGeEntity2d {lvalue},class AcGeMatrix2d)'''
    ...
    def translateBy (self, *args, **kwargs):
      '''
translateBy( (Entity2d)arg1, (Vector2d)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} translateBy(class PyGeEntity2d {lvalue},class AcGeVector2d)'''
    ...
    def type (self, *args, **kwargs):
      '''
type( (Entity2d)arg1) -> EntityId :

    C++ signature :
        enum AcGe::EntityId type(class PyGeEntity2d {lvalue})'''
    ...

class CircArc3d:
    def __eq__ (self, *args, **kwargs):
      '''
__eq__( (Entity3d)arg1, (Entity3d)arg2) -> bool :

    C++ signature :
        bool __eq__(class PyGeEntity3d {lvalue},class PyGeEntity3d)'''
    ...
    def __init__ (self, *args, **kwargs):
      '''
__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1, (Point3d)arg2, (Vector3d)arg3, (float)arg4) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class AcGePoint3d,class AcGeVector3d,double)

__init__( (object)arg1, (Point3d)arg2, (Vector3d)arg3, (Vector3d)arg4, (float)arg5, (float)arg6, (float)arg7) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class AcGePoint3d,class AcGeVector3d,class AcGeVector3d,double,double,double)

__init__( (object)arg1, (Point3d)arg2, (Point3d)arg3, (Point3d)arg4) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class AcGePoint3d,class AcGePoint3d,class AcGePoint3d)'''
    ...
    def __ne__ (self, *args, **kwargs):
      '''
__ne__( (Entity3d)arg1, (Entity3d)arg2) -> bool :

    C++ signature :
        bool __ne__(class PyGeEntity3d {lvalue},class PyGeEntity3d)'''
    ...
    def area (self, *args, **kwargs):
      '''
area( (Curve3d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double area(class PyGeCurve3d {lvalue},double,double)

area( (Curve3d)arg1, (float)arg2, (float)arg3, (Tol)arg4) -> float :

    C++ signature :
        double area(class PyGeCurve3d {lvalue},double,double,class AcGeTol)'''
    ...
    def boundBlock (self, *args, **kwargs):
      '''
boundBlock( (Curve3d)arg1) -> BoundBlock3d :

    C++ signature :
        class PyGeBoundBlock3d boundBlock(class PyGeCurve3d {lvalue})

boundBlock( (Curve3d)arg1, (Interval)arg2) -> BoundBlock3d :

    C++ signature :
        class PyGeBoundBlock3d boundBlock(class PyGeCurve3d {lvalue},class PyGeInterval)'''
    ...
    def center (self, *args, **kwargs):
      '''
center( (CircArc3d)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d center(class PyGeCircArc3d {lvalue})'''
    ...
    def className (self, *args, **kwargs):
      '''
className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def closestPointTo (self, *args, **kwargs):
      '''
closestPointTo( (Curve3d)arg1, (Point3d)arg2) -> Point3d :

    C++ signature :
        class AcGePoint3d closestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d)

closestPointTo( (Curve3d)arg1, (Point3d)arg2, (Tol)arg3) -> Point3d :

    C++ signature :
        class AcGePoint3d closestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeTol)

closestPointTo( (Curve3d)arg1, (Curve3d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointTo(class PyGeCurve3d {lvalue},class PyGeCurve3d)

closestPointTo( (Curve3d)arg1, (Curve3d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointTo(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeTol)'''
    ...
    def closestPointToPlane (self, *args, **kwargs):
      '''
closestPointToPlane( (CircArc3d)arg1, (PlanarEnt)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointToPlane(class PyGeCircArc3d {lvalue},class PyGePlanarEnt)

closestPointToPlane( (CircArc3d)arg1, (PlanarEnt)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointToPlane(class PyGeCircArc3d {lvalue},class PyGePlanarEnt,class AcGeTol)'''
    ...
    def copy (self, *args, **kwargs):
      '''
copy( (Entity3d)arg1) -> Entity3d :

    C++ signature :
        class PyGeEntity3d copy(class PyGeEntity3d {lvalue})'''
    ...
    def distanceTo (self, *args, **kwargs):
      '''
distanceTo( (Curve3d)arg1, (Point3d)arg2) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve3d {lvalue},class AcGePoint3d)

distanceTo( (Curve3d)arg1, (Point3d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeTol)

distanceTo( (Curve3d)arg1, (Curve3d)arg2) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve3d {lvalue},class PyGeCurve3d)

distanceTo( (Curve3d)arg1, (Curve3d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeTol)'''
    ...
    def endAng (self, *args, **kwargs):
      '''
endAng( (CircArc3d)arg1) -> float :

    C++ signature :
        double endAng(class PyGeCircArc3d {lvalue})'''
    ...
    def endPoint (self, *args, **kwargs):
      '''
endPoint( (CircArc3d)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d endPoint(class PyGeCircArc3d {lvalue})'''
    ...
    def evalPoint (self, *args, **kwargs):
      '''
evalPoint( (Curve3d)arg1, (float)arg2) -> Point3d :

    C++ signature :
        class AcGePoint3d evalPoint(class PyGeCurve3d {lvalue},double)

evalPoint( (Curve3d)arg1, (float)arg2, (int)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple evalPoint(class PyGeCurve3d {lvalue},double,int)'''
    ...
    def explode (self, *args, **kwargs):
      '''
explode( (Curve3d)arg1) -> list :

    C++ signature :
        class boost::python::list explode(class PyGeCurve3d {lvalue})

explode( (Curve3d)arg1, (Interval)arg2) -> list :

    C++ signature :
        class boost::python::list explode(class PyGeCurve3d {lvalue},class PyGeInterval)'''
    ...
    def getClosestPointTo (self, *args, **kwargs):
      '''
getClosestPointTo( (Curve3d)arg1, (Point3d)arg2) -> PointOnCurve3d :

    C++ signature :
        class PyGePointOnCurve3d getClosestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d)

getClosestPointTo( (Curve3d)arg1, (Point3d)arg2, (Tol)arg3) -> PointOnCurve3d :

    C++ signature :
        class PyGePointOnCurve3d getClosestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def getClosestPointsTo (self, *args, **kwargs):
      '''
getClosestPointsTo( (Curve3d)arg1, (Curve3d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getClosestPointsTo(class PyGeCurve3d {lvalue},class PyGeCurve3d)

getClosestPointsTo( (Curve3d)arg1, (Curve3d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple getClosestPointsTo(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeTol)'''
    ...
    def getEndPoint (self, *args, **kwargs):
      '''
getEndPoint( (Curve3d)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d getEndPoint(class PyGeCurve3d {lvalue})'''
    ...
    def getInterval (self, *args, **kwargs):
      '''
getInterval( (Curve3d)arg1) -> Interval :

    C++ signature :
        class PyGeInterval getInterval(class PyGeCurve3d {lvalue})'''
    ...
    def getNormalPoint (self, *args, **kwargs):
      '''
getNormalPoint( (Curve3d)arg1, (Point3d)arg2) -> PointOnCurve3d :

    C++ signature :
        class PyGePointOnCurve3d getNormalPoint(class PyGeCurve3d {lvalue},class AcGePoint3d)

getNormalPoint( (Curve3d)arg1, (Point3d)arg2, (Tol)arg3) -> PointOnCurve3d :

    C++ signature :
        class PyGePointOnCurve3d getNormalPoint(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def getPlane (self, *args, **kwargs):
      '''
getPlane( (CircArc3d)arg1) -> Plane :

    C++ signature :
        class PyGePlane getPlane(class PyGeCircArc3d {lvalue})'''
    ...
    def getProjClosestPointTo (self, *args, **kwargs):
      '''
getProjClosestPointTo( (Curve3d)arg1, (Point3d)arg2, (Vector3d)arg3) -> PointOnCurve3d :

    C++ signature :
        class PyGePointOnCurve3d getProjClosestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeVector3d)

getProjClosestPointTo( (Curve3d)arg1, (Point3d)arg2, (Vector3d)arg3, (Tol)arg4) -> PointOnCurve3d :

    C++ signature :
        class PyGePointOnCurve3d getProjClosestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeVector3d,class AcGeTol)'''
    ...
    def getProjClosestPointsTo (self, *args, **kwargs):
      '''
getProjClosestPointsTo( (Curve3d)arg1, (Curve3d)arg2, (Vector3d)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple getProjClosestPointsTo(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeVector3d)

getProjClosestPointsTo( (Curve3d)arg1, (Curve3d)arg2, (Vector3d)arg3, (Tol)arg4) -> tuple :

    C++ signature :
        class boost::python::tuple getProjClosestPointsTo(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeVector3d,class AcGeTol)'''
    ...
    def getSamplePoints (self, *args, **kwargs):
      '''
getSamplePoints( (Curve3d)arg1, (int)arg2) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve3d {lvalue},int)

getSamplePoints( (Curve3d)arg1, (float)arg2, (float)arg3, (float)arg4) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve3d {lvalue},double,double,double)'''
    ...
    def getSplitCurves (self, *args, **kwargs):
      '''
getSplitCurves( (Curve3d)arg1, (float)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getSplitCurves(class PyGeCurve3d {lvalue},double)'''
    ...
    def getStartPoint (self, *args, **kwargs):
      '''
getStartPoint( (Curve3d)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d getStartPoint(class PyGeCurve3d {lvalue})'''
    ...
    def getTrimmedOffset (self, *args, **kwargs):
      '''
getTrimmedOffset( (Curve3d)arg1, (float)arg2, (Vector3d)arg3, (OffsetCrvExtType)arg4) -> list :

    C++ signature :
        class boost::python::list getTrimmedOffset(class PyGeCurve3d {lvalue},double,class AcGeVector3d,enum AcGe::OffsetCrvExtType)

getTrimmedOffset( (Curve3d)arg1, (float)arg2, (Vector3d)arg3, (OffsetCrvExtType)arg4, (Tol)arg5) -> list :

    C++ signature :
        class boost::python::list getTrimmedOffset(class PyGeCurve3d {lvalue},double,class AcGeVector3d,enum AcGe::OffsetCrvExtType,class AcGeTol)'''
    ...
    def hasEndPoint (self, *args, **kwargs):
      '''
hasEndPoint( (Curve3d)arg1) -> bool :

    C++ signature :
        bool hasEndPoint(class PyGeCurve3d {lvalue})'''
    ...
    def hasStartPoint (self, *args, **kwargs):
      '''
hasStartPoint( (Curve3d)arg1) -> bool :

    C++ signature :
        bool hasStartPoint(class PyGeCurve3d {lvalue})'''
    ...
    def intersectWith (self, *args, **kwargs):
      '''
intersectWith( (CircArc3d)arg1, (LinearEnt3d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple intersectWith(class PyGeCircArc3d {lvalue},class PyGeLinearEnt3d)

intersectWith( (CircArc3d)arg1, (LinearEnt3d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple intersectWith(class PyGeCircArc3d {lvalue},class PyGeLinearEnt3d,class AcGeTol)

intersectWith( (CircArc3d)arg1, (CircArc3d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple intersectWith(class PyGeCircArc3d {lvalue},class PyGeCircArc3d)

intersectWith( (CircArc3d)arg1, (CircArc3d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple intersectWith(class PyGeCircArc3d {lvalue},class PyGeCircArc3d,class AcGeTol)

intersectWith( (CircArc3d)arg1, (PlanarEnt)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple intersectWith(class PyGeCircArc3d {lvalue},class PyGePlanarEnt)

intersectWith( (CircArc3d)arg1, (PlanarEnt)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple intersectWith(class PyGeCircArc3d {lvalue},class PyGePlanarEnt,class AcGeTol)'''
    ...
    def isClosed (self, *args, **kwargs):
      '''
isClosed( (Curve3d)arg1) -> bool :

    C++ signature :
        bool isClosed(class PyGeCurve3d {lvalue})

isClosed( (Curve3d)arg1, (Tol)arg2) -> bool :

    C++ signature :
        bool isClosed(class PyGeCurve3d {lvalue},class AcGeTol)'''
    ...
    def isCoplanarWith (self, *args, **kwargs):
      '''
isCoplanarWith( (Curve3d)arg1, (Curve3d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isCoplanarWith(class PyGeCurve3d {lvalue},class PyGeCurve3d)

isCoplanarWith( (Curve3d)arg1, (Curve3d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple isCoplanarWith(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeTol)'''
    ...
    def isDegenerate (self, *args, **kwargs):
      '''
isDegenerate( (Curve3d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isDegenerate(class PyGeCurve3d {lvalue})

isDegenerate( (Curve3d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isDegenerate(class PyGeCurve3d {lvalue},class AcGeTol)'''
    ...
    def isEqualTo (self, *args, **kwargs):
      '''
isEqualTo( (Entity3d)arg1, (Entity3d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity3d {lvalue},class PyGeEntity3d,class AcGeTol)'''
    ...
    def isInside (self, *args, **kwargs):
      '''
isInside( (CircArc3d)arg1, (Point3d)arg2) -> bool :

    C++ signature :
        bool isInside(class PyGeCircArc3d {lvalue},class AcGePoint3d)

isInside( (CircArc3d)arg1, (Point3d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isInside(class PyGeCircArc3d {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def isKindOf (self, *args, **kwargs):
      '''
isKindOf( (Entity3d)arg1, (EntityId)arg2) -> bool :

    C++ signature :
        bool isKindOf(class PyGeEntity3d {lvalue},enum AcGe::EntityId)'''
    ...
    def isLinear (self, *args, **kwargs):
      '''
isLinear( (Curve3d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isLinear(class PyGeCurve3d {lvalue})

isLinear( (Curve3d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isLinear(class PyGeCurve3d {lvalue},class AcGeTol)'''
    ...
    def isNull (self, *args, **kwargs):
      '''
isNull( (Entity3d)arg1) -> bool :

    C++ signature :
        bool isNull(class PyGeEntity3d {lvalue})'''
    ...
    def isOn (self, *args, **kwargs):
      '''
isOn( (Curve3d)arg1, (Point3d)arg2) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve3d {lvalue},class AcGePoint3d)

isOn( (Curve3d)arg1, (Point3d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeTol)

isOn( (Curve3d)arg1, (Point3d)arg2, (float)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve3d {lvalue},class AcGePoint3d,double {lvalue})

isOn( (Curve3d)arg1, (Point3d)arg2, (float)arg3, (Tol)arg4) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve3d {lvalue},class AcGePoint3d,double {lvalue},class AcGeTol)

isOn( (Curve3d)arg1, (float)arg2) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve3d {lvalue},double)

isOn( (Curve3d)arg1, (float)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve3d {lvalue},double,class AcGeTol)'''
    ...
    def isPeriodic (self, *args, **kwargs):
      '''
isPeriodic( (Curve3d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isPeriodic(class PyGeCurve3d {lvalue})'''
    ...
    def isPlanar (self, *args, **kwargs):
      '''
isPlanar( (Curve3d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isPlanar(class PyGeCurve3d {lvalue})

isPlanar( (Curve3d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isPlanar(class PyGeCurve3d {lvalue},class AcGeTol)'''
    ...
    def length (self, *args, **kwargs):
      '''
length( (Curve3d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double length(class PyGeCurve3d {lvalue},double,double)

length( (Curve3d)arg1, (float)arg2, (float)arg3, (float)arg4) -> float :

    C++ signature :
        double length(class PyGeCurve3d {lvalue},double,double,double)'''
    ...
    def mirror (self, *args, **kwargs):
      '''
mirror( (Entity3d)arg1, (Plane)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} mirror(class PyGeEntity3d {lvalue},class PyGePlane)'''
    ...
    def normal (self, *args, **kwargs):
      '''
normal( (CircArc3d)arg1) -> Vector3d :

    C++ signature :
        class AcGeVector3d normal(class PyGeCircArc3d {lvalue})'''
    ...
    def orthoBoundBlock (self, *args, **kwargs):
      '''
orthoBoundBlock( (Curve3d)arg1) -> BoundBlock3d :

    C++ signature :
        class PyGeBoundBlock3d orthoBoundBlock(class PyGeCurve3d {lvalue})

orthoBoundBlock( (Curve3d)arg1, (Interval)arg2) -> BoundBlock3d :

    C++ signature :
        class PyGeBoundBlock3d orthoBoundBlock(class PyGeCurve3d {lvalue},class PyGeInterval)'''
    ...
    def orthoProject (self, *args, **kwargs):
      '''
orthoProject( (Curve3d)arg1, (Plane)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d orthoProject(class PyGeCurve3d {lvalue},class PyGePlane)

orthoProject( (Curve3d)arg1, (Plane)arg2, (Tol)arg3) -> Entity3d :

    C++ signature :
        class PyGeEntity3d orthoProject(class PyGeCurve3d {lvalue},class PyGePlane,class AcGeTol)'''
    ...
    def paramAtLength (self, *args, **kwargs):
      '''
paramAtLength( (Curve3d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double paramAtLength(class PyGeCurve3d {lvalue},double,double)

paramAtLength( (Curve3d)arg1, (float)arg2, (float)arg3, (bool)arg4, (float)arg5) -> float :

    C++ signature :
        double paramAtLength(class PyGeCurve3d {lvalue},double,double,bool,double)'''
    ...
    def paramOf (self, *args, **kwargs):
      '''
paramOf( (Curve3d)arg1, (Point3d)arg2) -> float :

    C++ signature :
        double paramOf(class PyGeCurve3d {lvalue},class AcGePoint3d)

paramOf( (Curve3d)arg1, (Point3d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double paramOf(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def projClosestPointTo (self, *args, **kwargs):
      '''
projClosestPointTo( (Curve3d)arg1, (Point3d)arg2, (Vector3d)arg3) -> Point3d :

    C++ signature :
        class AcGePoint3d projClosestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeVector3d)

projClosestPointTo( (Curve3d)arg1, (Point3d)arg2, (Vector3d)arg3, (Tol)arg4) -> Point3d :

    C++ signature :
        class AcGePoint3d projClosestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeVector3d,class AcGeTol)'''
    ...
    def projClosestPointsTo (self, *args, **kwargs):
      '''
projClosestPointsTo( (Curve3d)arg1, (Curve3d)arg2, (Vector3d)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple projClosestPointsTo(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeVector3d)

projClosestPointsTo( (Curve3d)arg1, (Curve3d)arg2, (Vector3d)arg3, (Tol)arg4) -> tuple :

    C++ signature :
        class boost::python::tuple projClosestPointsTo(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeVector3d,class AcGeTol)'''
    ...
    def projIntersectWith (self, *args, **kwargs):
      '''
projIntersectWith( (CircArc3d)arg1, (LinearEnt3d)arg2, (Vector3d)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple projIntersectWith(class PyGeCircArc3d {lvalue},class PyGeLinearEnt3d,class AcGeVector3d)

projIntersectWith( (CircArc3d)arg1, (LinearEnt3d)arg2, (Vector3d)arg3, (Tol)arg4) -> tuple :

    C++ signature :
        class boost::python::tuple projIntersectWith(class PyGeCircArc3d {lvalue},class PyGeLinearEnt3d,class AcGeVector3d,class AcGeTol)'''
    ...
    def project (self, *args, **kwargs):
      '''
project( (Curve3d)arg1, (Plane)arg2, (Vector3d)arg3) -> Entity3d :

    C++ signature :
        class PyGeEntity3d project(class PyGeCurve3d {lvalue},class PyGePlane,class AcGeVector3d)

project( (Curve3d)arg1, (Plane)arg2, (Vector3d)arg3, (Tol)arg4) -> Entity3d :

    C++ signature :
        class PyGeEntity3d project(class PyGeCurve3d {lvalue},class PyGePlane,class AcGeVector3d,class AcGeTol)'''
    ...
    def radius (self, *args, **kwargs):
      '''
radius( (CircArc3d)arg1) -> float :

    C++ signature :
        double radius(class PyGeCircArc3d {lvalue})'''
    ...
    def refVec (self, *args, **kwargs):
      '''
refVec( (CircArc3d)arg1) -> Vector3d :

    C++ signature :
        class AcGeVector3d refVec(class PyGeCircArc3d {lvalue})'''
    ...
    def reverseParam (self, *args, **kwargs):
      '''
reverseParam( (Curve3d)arg1) -> Curve3d :

    C++ signature :
        class PyGeCurve3d {lvalue} reverseParam(class PyGeCurve3d {lvalue})'''
    ...
    def rotateBy (self, *args, **kwargs):
      '''
rotateBy( (Entity3d)arg1, (float)arg2, (Vector3d)arg3) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} rotateBy(class PyGeEntity3d {lvalue},double,class AcGeVector3d)

rotateBy( (Entity3d)arg1, (float)arg2, (Vector3d)arg3, (Point3d)arg4) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} rotateBy(class PyGeEntity3d {lvalue},double,class AcGeVector3d,class AcGePoint3d)'''
    ...
    def scaleBy (self, *args, **kwargs):
      '''
scaleBy( (Entity3d)arg1, (float)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} scaleBy(class PyGeEntity3d {lvalue},double)

scaleBy( (Entity3d)arg1, (float)arg2, (Point3d)arg3) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} scaleBy(class PyGeEntity3d {lvalue},double,class AcGePoint3d)'''
    ...
    def set (self, *args, **kwargs):
      '''
set( (CircArc3d)arg1, (Point3d)arg2, (Vector3d)arg3, (float)arg4) -> CircArc3d :

    C++ signature :
        class PyGeCircArc3d {lvalue} set(class PyGeCircArc3d {lvalue},class AcGePoint3d,class AcGeVector3d,double)

set( (CircArc3d)arg1, (Point3d)arg2, (Vector3d)arg3, (Vector3d)arg4, (float)arg5, (float)arg6, (float)arg7) -> CircArc3d :

    C++ signature :
        class PyGeCircArc3d {lvalue} set(class PyGeCircArc3d {lvalue},class AcGePoint3d,class AcGeVector3d,class AcGeVector3d,double,double,double)

set( (CircArc3d)arg1, (Point3d)arg2, (Point3d)arg3, (Point3d)arg4) -> CircArc3d :

    C++ signature :
        class PyGeCircArc3d {lvalue} set(class PyGeCircArc3d {lvalue},class AcGePoint3d,class AcGePoint3d,class AcGePoint3d)

set( (CircArc3d)arg1, (Curve3d)arg2, (Curve3d)arg3, (float)arg4) -> CircArc3d :

    C++ signature :
        class PyGeCircArc3d {lvalue} set(class PyGeCircArc3d {lvalue},class PyGeCurve3d,class PyGeCurve3d,double)

set( (CircArc3d)arg1, (Curve3d)arg2, (Curve3d)arg3, (Curve3d)arg4) -> CircArc3d :

    C++ signature :
        class PyGeCircArc3d {lvalue} set(class PyGeCircArc3d {lvalue},class PyGeCurve3d,class PyGeCurve3d,class PyGeCurve3d)'''
    ...
    def setAngles (self, *args, **kwargs):
      '''
setAngles( (CircArc3d)arg1, (float)arg2, (float)arg3) -> CircArc3d :

    C++ signature :
        class PyGeCircArc3d {lvalue} setAngles(class PyGeCircArc3d {lvalue},double,double)'''
    ...
    def setAxes (self, *args, **kwargs):
      '''
setAxes( (CircArc3d)arg1, (Vector3d)arg2, (Vector3d)arg3) -> CircArc3d :

    C++ signature :
        class PyGeCircArc3d {lvalue} setAxes(class PyGeCircArc3d {lvalue},class AcGeVector3d,class AcGeVector3d)'''
    ...
    def setCenter (self, *args, **kwargs):
      '''
setCenter( (CircArc3d)arg1, (Point3d)arg2) -> CircArc3d :

    C++ signature :
        class PyGeCircArc3d {lvalue} setCenter(class PyGeCircArc3d {lvalue},class AcGePoint3d)'''
    ...
    def setInterval (self, *args, **kwargs):
      '''
setInterval( (Curve3d)arg1) -> Curve3d :

    C++ signature :
        class PyGeCurve3d {lvalue} setInterval(class PyGeCurve3d {lvalue})

setInterval( (Curve3d)arg1, (Interval)arg2) -> bool :

    C++ signature :
        bool setInterval(class PyGeCurve3d {lvalue},class PyGeInterval)'''
    ...
    def setRadius (self, *args, **kwargs):
      '''
setRadius( (CircArc3d)arg1, (float)arg2) -> CircArc3d :

    C++ signature :
        class PyGeCircArc3d {lvalue} setRadius(class PyGeCircArc3d {lvalue},double)'''
    ...
    def startAng (self, *args, **kwargs):
      '''
startAng( (CircArc3d)arg1) -> float :

    C++ signature :
        double startAng(class PyGeCircArc3d {lvalue})'''
    ...
    def startPoint (self, *args, **kwargs):
      '''
startPoint( (CircArc3d)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d startPoint(class PyGeCircArc3d {lvalue})'''
    ...
    def tangent (self, *args, **kwargs):
      '''
tangent( (CircArc3d)arg1, (Point3d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple tangent(class PyGeCircArc3d {lvalue},class AcGePoint3d)

tangent( (CircArc3d)arg1, (Point3d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple tangent(class PyGeCircArc3d {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def transformBy (self, *args, **kwargs):
      '''
transformBy( (Entity3d)arg1, (Matrix3d)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} transformBy(class PyGeEntity3d {lvalue},class AcGeMatrix3d)'''
    ...
    def translateBy (self, *args, **kwargs):
      '''
translateBy( (Entity3d)arg1, (Vector3d)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} translateBy(class PyGeEntity3d {lvalue},class AcGeVector3d)'''
    ...
    def type (self, *args, **kwargs):
      '''
type( (Entity3d)arg1) -> EntityId :

    C++ signature :
        enum AcGe::EntityId type(class PyGeEntity3d {lvalue})'''
    ...

class ClipBoundary2d:
    def __eq__ (self, *args, **kwargs):
      '''
__eq__( (Entity2d)arg1, (Entity2d)arg2) -> bool :

    C++ signature :
        bool __eq__(class PyGeEntity2d {lvalue},class PyGeEntity2d)'''
    ...
    def __init__ (self, *args, **kwargs):
      '''
__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1, (Point2d)arg2, (Point2d)arg3) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class AcGePoint2d,class AcGePoint2d)

__init__( (object)arg1, (list)arg2) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class boost::python::list)'''
    ...
    def __ne__ (self, *args, **kwargs):
      '''
__ne__( (Entity2d)arg1, (Entity2d)arg2) -> bool :

    C++ signature :
        bool __ne__(class PyGeEntity2d {lvalue},class PyGeEntity2d)'''
    ...
    def className (self, *args, **kwargs):
      '''
className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def copy (self, *args, **kwargs):
      '''
copy( (Entity2d)arg1) -> Entity2d :

    C++ signature :
        class PyGeEntity2d copy(class PyGeEntity2d {lvalue})'''
    ...
    def isEqualTo (self, *args, **kwargs):
      '''
isEqualTo( (Entity2d)arg1, (Entity2d)arg2) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity2d {lvalue},class PyGeEntity2d)

isEqualTo( (Entity2d)arg1, (Entity2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity2d {lvalue},class PyGeEntity2d,class AcGeTol)'''
    ...
    def isKindOf (self, *args, **kwargs):
      '''
isKindOf( (Entity2d)arg1, (EntityId)arg2) -> bool :

    C++ signature :
        bool isKindOf(class PyGeEntity2d {lvalue},enum AcGe::EntityId)'''
    ...
    def isNull (self, *args, **kwargs):
      '''
isNull( (Entity2d)arg1) -> bool :

    C++ signature :
        bool isNull(class PyGeEntity2d {lvalue})'''
    ...
    def isOn (self, *args, **kwargs):
      '''
isOn( (Entity2d)arg1, (Point2d)arg2) -> bool :

    C++ signature :
        bool isOn(class PyGeEntity2d {lvalue},class AcGePoint2d)

isOn( (Entity2d)arg1, (Point2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeEntity2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def mirror (self, *args, **kwargs):
      '''
mirror( (Entity2d)arg1, (Line2d)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} mirror(class PyGeEntity2d {lvalue},class PyGeLine2d)'''
    ...
    def rotateBy (self, *args, **kwargs):
      '''
rotateBy( (Entity2d)arg1, (float)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} rotateBy(class PyGeEntity2d {lvalue},double)

rotateBy( (Entity2d)arg1, (float)arg2, (Point2d)arg3) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} rotateBy(class PyGeEntity2d {lvalue},double,class AcGePoint2d)'''
    ...
    def scaleBy (self, *args, **kwargs):
      '''
scaleBy( (Entity2d)arg1, (float)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} scaleBy(class PyGeEntity2d {lvalue},double)

scaleBy( (Entity2d)arg1, (float)arg2, (Point2d)arg3) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} scaleBy(class PyGeEntity2d {lvalue},double,class AcGePoint2d)'''
    ...
    def transformBy (self, *args, **kwargs):
      '''
transformBy( (Entity2d)arg1, (Matrix2d)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} transformBy(class PyGeEntity2d {lvalue},class AcGeMatrix2d)'''
    ...
    def translateBy (self, *args, **kwargs):
      '''
translateBy( (Entity2d)arg1, (Vector2d)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} translateBy(class PyGeEntity2d {lvalue},class AcGeVector2d)'''
    ...
    def type (self, *args, **kwargs):
      '''
type( (Entity2d)arg1) -> EntityId :

    C++ signature :
        enum AcGe::EntityId type(class PyGeEntity2d {lvalue})'''
    ...

class CompositeCurve2d:
    def __eq__ (self, *args, **kwargs):
      '''
__eq__( (Entity2d)arg1, (Entity2d)arg2) -> bool :

    C++ signature :
        bool __eq__(class PyGeEntity2d {lvalue},class PyGeEntity2d)'''
    ...
    def __init__ (self, *args, **kwargs):
      '''
__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
    ...
    def __ne__ (self, *args, **kwargs):
      '''
__ne__( (Entity2d)arg1, (Entity2d)arg2) -> bool :

    C++ signature :
        bool __ne__(class PyGeEntity2d {lvalue},class PyGeEntity2d)'''
    ...
    def area (self, *args, **kwargs):
      '''
area( (Curve2d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double area(class PyGeCurve2d {lvalue},double,double)

area( (Curve2d)arg1, (float)arg2, (float)arg3, (Tol)arg4) -> float :

    C++ signature :
        double area(class PyGeCurve2d {lvalue},double,double,class AcGeTol)'''
    ...
    def boundBlock (self, *args, **kwargs):
      '''
boundBlock( (Curve2d)arg1) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d boundBlock(class PyGeCurve2d {lvalue})

boundBlock( (Curve2d)arg1, (Interval)arg2) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d boundBlock(class PyGeCurve2d {lvalue},class PyGeInterval)'''
    ...
    def className (self, *args, **kwargs):
      '''
className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def closestPointTo (self, *args, **kwargs):
      '''
closestPointTo( (Curve2d)arg1, (Point2d)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d closestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d)

closestPointTo( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> Point2d :

    C++ signature :
        class AcGePoint2d closestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)

closestPointTo( (Curve2d)arg1, (Curve2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointTo(class PyGeCurve2d {lvalue},class PyGeCurve2d)

closestPointTo( (Curve2d)arg1, (Curve2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointTo(class PyGeCurve2d {lvalue},class PyGeCurve2d,class AcGeTol)'''
    ...
    def copy (self, *args, **kwargs):
      '''
copy( (Entity2d)arg1) -> Entity2d :

    C++ signature :
        class PyGeEntity2d copy(class PyGeEntity2d {lvalue})'''
    ...
    def distanceTo (self, *args, **kwargs):
      '''
distanceTo( (Curve2d)arg1, (Point2d)arg2) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class AcGePoint2d)

distanceTo( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)

distanceTo( (Curve2d)arg1, (Curve2d)arg2) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class PyGeCurve2d)

distanceTo( (Curve2d)arg1, (Curve2d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class PyGeCurve2d,class AcGeTol)'''
    ...
    def evalPoint (self, *args, **kwargs):
      '''
evalPoint( (Curve2d)arg1, (float)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d evalPoint(class PyGeCurve2d {lvalue},double)

evalPoint( (Curve2d)arg1, (float)arg2, (int)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple evalPoint(class PyGeCurve2d {lvalue},double,int)'''
    ...
    def explode (self, *args, **kwargs):
      '''
explode( (Curve2d)arg1) -> list :

    C++ signature :
        class boost::python::list explode(class PyGeCurve2d {lvalue})

explode( (Curve2d)arg1, (Interval)arg2) -> list :

    C++ signature :
        class boost::python::list explode(class PyGeCurve2d {lvalue},class PyGeInterval)'''
    ...
    def getClosestPointTo (self, *args, **kwargs):
      '''
getClosestPointTo( (Curve2d)arg1, (Point2d)arg2) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getClosestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d)

getClosestPointTo( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getClosestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def getClosestPointsTo (self, *args, **kwargs):
      '''
getClosestPointsTo( (Curve2d)arg1, (Curve2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getClosestPointsTo(class PyGeCurve2d {lvalue},class PyGeCurve2d)

getClosestPointsTo( (Curve2d)arg1, (Curve2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple getClosestPointsTo(class PyGeCurve2d {lvalue},class PyGeCurve2d,class AcGeTol)'''
    ...
    def getEndPoint (self, *args, **kwargs):
      '''
getEndPoint( (Curve2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d getEndPoint(class PyGeCurve2d {lvalue})'''
    ...
    def getInterval (self, *args, **kwargs):
      '''
getInterval( (Curve2d)arg1) -> Interval :

    C++ signature :
        class PyGeInterval getInterval(class PyGeCurve2d {lvalue})'''
    ...
    def getNormalPoint (self, *args, **kwargs):
      '''
getNormalPoint( (Curve2d)arg1, (Point2d)arg2) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getNormalPoint(class PyGeCurve2d {lvalue},class AcGePoint2d)

getNormalPoint( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getNormalPoint(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def getSamplePoints (self, *args, **kwargs):
      '''
getSamplePoints( (Curve2d)arg1, (int)arg2) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve2d {lvalue},int)

getSamplePoints( (Curve2d)arg1, (float)arg2, (float)arg3, (float)arg4) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve2d {lvalue},double,double,double)'''
    ...
    def getSplitCurves (self, *args, **kwargs):
      '''
getSplitCurves( (Curve2d)arg1, (float)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getSplitCurves(class PyGeCurve2d {lvalue},double)'''
    ...
    def getStartPoint (self, *args, **kwargs):
      '''
getStartPoint( (Curve2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d getStartPoint(class PyGeCurve2d {lvalue})'''
    ...
    def getTrimmedOffset (self, *args, **kwargs):
      '''
getTrimmedOffset( (Curve2d)arg1, (float)arg2, (OffsetCrvExtType)arg3) -> list :

    C++ signature :
        class boost::python::list getTrimmedOffset(class PyGeCurve2d {lvalue},double,enum AcGe::OffsetCrvExtType)

getTrimmedOffset( (Curve2d)arg1, (float)arg2, (OffsetCrvExtType)arg3, (Tol)arg4) -> list :

    C++ signature :
        class boost::python::list getTrimmedOffset(class PyGeCurve2d {lvalue},double,enum AcGe::OffsetCrvExtType,class AcGeTol)'''
    ...
    def hasEndPoint (self, *args, **kwargs):
      '''
hasEndPoint( (Curve2d)arg1) -> bool :

    C++ signature :
        bool hasEndPoint(class PyGeCurve2d {lvalue})'''
    ...
    def hasStartPoint (self, *args, **kwargs):
      '''
hasStartPoint( (Curve2d)arg1) -> bool :

    C++ signature :
        bool hasStartPoint(class PyGeCurve2d {lvalue})'''
    ...
    def isClosed (self, *args, **kwargs):
      '''
isClosed( (Curve2d)arg1) -> bool :

    C++ signature :
        bool isClosed(class PyGeCurve2d {lvalue})

isClosed( (Curve2d)arg1, (Tol)arg2) -> bool :

    C++ signature :
        bool isClosed(class PyGeCurve2d {lvalue},class AcGeTol)'''
    ...
    def isDegenerate (self, *args, **kwargs):
      '''
isDegenerate( (Curve2d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isDegenerate(class PyGeCurve2d {lvalue})

isDegenerate( (Curve2d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isDegenerate(class PyGeCurve2d {lvalue},class AcGeTol)'''
    ...
    def isEqualTo (self, *args, **kwargs):
      '''
isEqualTo( (Entity2d)arg1, (Entity2d)arg2) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity2d {lvalue},class PyGeEntity2d)

isEqualTo( (Entity2d)arg1, (Entity2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity2d {lvalue},class PyGeEntity2d,class AcGeTol)'''
    ...
    def isKindOf (self, *args, **kwargs):
      '''
isKindOf( (Entity2d)arg1, (EntityId)arg2) -> bool :

    C++ signature :
        bool isKindOf(class PyGeEntity2d {lvalue},enum AcGe::EntityId)'''
    ...
    def isLinear (self, *args, **kwargs):
      '''
isLinear( (Curve2d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isLinear(class PyGeCurve2d {lvalue})

isLinear( (Curve2d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isLinear(class PyGeCurve2d {lvalue},class AcGeTol)'''
    ...
    def isNull (self, *args, **kwargs):
      '''
isNull( (Entity2d)arg1) -> bool :

    C++ signature :
        bool isNull(class PyGeEntity2d {lvalue})'''
    ...
    def isOn (self, *args, **kwargs):
      '''
isOn( (Curve2d)arg1, (Point2d)arg2) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve2d {lvalue},class AcGePoint2d)

isOn( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)

isOn( (Curve2d)arg1, (Point2d)arg2, (float)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve2d {lvalue},class AcGePoint2d,double {lvalue})

isOn( (Curve2d)arg1, (Point2d)arg2, (float)arg3, (Tol)arg4) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve2d {lvalue},class AcGePoint2d,double {lvalue},class AcGeTol)

isOn( (Curve2d)arg1, (float)arg2) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve2d {lvalue},double)

isOn( (Curve2d)arg1, (float)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve2d {lvalue},double,class AcGeTol)'''
    ...
    def isPeriodic (self, *args, **kwargs):
      '''
isPeriodic( (Curve2d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isPeriodic(class PyGeCurve2d {lvalue})'''
    ...
    def length (self, *args, **kwargs):
      '''
length( (Curve2d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double length(class PyGeCurve2d {lvalue},double,double)

length( (Curve2d)arg1, (float)arg2, (float)arg3, (float)arg4) -> float :

    C++ signature :
        double length(class PyGeCurve2d {lvalue},double,double,double)'''
    ...
    def mirror (self, *args, **kwargs):
      '''
mirror( (Entity2d)arg1, (Line2d)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} mirror(class PyGeEntity2d {lvalue},class PyGeLine2d)'''
    ...
    def orthoBoundBlock (self, *args, **kwargs):
      '''
orthoBoundBlock( (Curve2d)arg1) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d orthoBoundBlock(class PyGeCurve2d {lvalue})

orthoBoundBlock( (Curve2d)arg1, (Interval)arg2) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d orthoBoundBlock(class PyGeCurve2d {lvalue},class PyGeInterval)'''
    ...
    def paramAtLength (self, *args, **kwargs):
      '''
paramAtLength( (Curve2d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double paramAtLength(class PyGeCurve2d {lvalue},double,double)

paramAtLength( (Curve2d)arg1, (float)arg2, (float)arg3, (bool)arg4, (float)arg5) -> float :

    C++ signature :
        double paramAtLength(class PyGeCurve2d {lvalue},double,double,bool,double)'''
    ...
    def paramOf (self, *args, **kwargs):
      '''
paramOf( (Curve2d)arg1, (Point2d)arg2) -> float :

    C++ signature :
        double paramOf(class PyGeCurve2d {lvalue},class AcGePoint2d)

paramOf( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double paramOf(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def reverseParam (self, *args, **kwargs):
      '''
reverseParam( (Curve2d)arg1) -> Curve2d :

    C++ signature :
        class PyGeCurve2d {lvalue} reverseParam(class PyGeCurve2d {lvalue})'''
    ...
    def rotateBy (self, *args, **kwargs):
      '''
rotateBy( (Entity2d)arg1, (float)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} rotateBy(class PyGeEntity2d {lvalue},double)

rotateBy( (Entity2d)arg1, (float)arg2, (Point2d)arg3) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} rotateBy(class PyGeEntity2d {lvalue},double,class AcGePoint2d)'''
    ...
    def scaleBy (self, *args, **kwargs):
      '''
scaleBy( (Entity2d)arg1, (float)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} scaleBy(class PyGeEntity2d {lvalue},double)

scaleBy( (Entity2d)arg1, (float)arg2, (Point2d)arg3) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} scaleBy(class PyGeEntity2d {lvalue},double,class AcGePoint2d)'''
    ...
    def setInterval (self, *args, **kwargs):
      '''
setInterval( (Curve2d)arg1) -> Curve2d :

    C++ signature :
        class PyGeCurve2d {lvalue} setInterval(class PyGeCurve2d {lvalue})

setInterval( (Curve2d)arg1, (Interval)arg2) -> bool :

    C++ signature :
        bool setInterval(class PyGeCurve2d {lvalue},class PyGeInterval)'''
    ...
    def transformBy (self, *args, **kwargs):
      '''
transformBy( (Entity2d)arg1, (Matrix2d)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} transformBy(class PyGeEntity2d {lvalue},class AcGeMatrix2d)'''
    ...
    def translateBy (self, *args, **kwargs):
      '''
translateBy( (Entity2d)arg1, (Vector2d)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} translateBy(class PyGeEntity2d {lvalue},class AcGeVector2d)'''
    ...
    def type (self, *args, **kwargs):
      '''
type( (Entity2d)arg1) -> EntityId :

    C++ signature :
        enum AcGe::EntityId type(class PyGeEntity2d {lvalue})'''
    ...

class CompositeCurve3d:
    def __eq__ (self, *args, **kwargs):
      '''
__eq__( (Entity3d)arg1, (Entity3d)arg2) -> bool :

    C++ signature :
        bool __eq__(class PyGeEntity3d {lvalue},class PyGeEntity3d)'''
    ...
    def __init__ (self, *args, **kwargs):
      '''
__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
    ...
    def __ne__ (self, *args, **kwargs):
      '''
__ne__( (Entity3d)arg1, (Entity3d)arg2) -> bool :

    C++ signature :
        bool __ne__(class PyGeEntity3d {lvalue},class PyGeEntity3d)'''
    ...
    def area (self, *args, **kwargs):
      '''
area( (Curve3d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double area(class PyGeCurve3d {lvalue},double,double)

area( (Curve3d)arg1, (float)arg2, (float)arg3, (Tol)arg4) -> float :

    C++ signature :
        double area(class PyGeCurve3d {lvalue},double,double,class AcGeTol)'''
    ...
    def boundBlock (self, *args, **kwargs):
      '''
boundBlock( (Curve3d)arg1) -> BoundBlock3d :

    C++ signature :
        class PyGeBoundBlock3d boundBlock(class PyGeCurve3d {lvalue})

boundBlock( (Curve3d)arg1, (Interval)arg2) -> BoundBlock3d :

    C++ signature :
        class PyGeBoundBlock3d boundBlock(class PyGeCurve3d {lvalue},class PyGeInterval)'''
    ...
    def className (self, *args, **kwargs):
      '''
className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def closestPointTo (self, *args, **kwargs):
      '''
closestPointTo( (Curve3d)arg1, (Point3d)arg2) -> Point3d :

    C++ signature :
        class AcGePoint3d closestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d)

closestPointTo( (Curve3d)arg1, (Point3d)arg2, (Tol)arg3) -> Point3d :

    C++ signature :
        class AcGePoint3d closestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeTol)

closestPointTo( (Curve3d)arg1, (Curve3d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointTo(class PyGeCurve3d {lvalue},class PyGeCurve3d)

closestPointTo( (Curve3d)arg1, (Curve3d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointTo(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeTol)'''
    ...
    def copy (self, *args, **kwargs):
      '''
copy( (Entity3d)arg1) -> Entity3d :

    C++ signature :
        class PyGeEntity3d copy(class PyGeEntity3d {lvalue})'''
    ...
    def distanceTo (self, *args, **kwargs):
      '''
distanceTo( (Curve3d)arg1, (Point3d)arg2) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve3d {lvalue},class AcGePoint3d)

distanceTo( (Curve3d)arg1, (Point3d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeTol)

distanceTo( (Curve3d)arg1, (Curve3d)arg2) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve3d {lvalue},class PyGeCurve3d)

distanceTo( (Curve3d)arg1, (Curve3d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeTol)'''
    ...
    def evalPoint (self, *args, **kwargs):
      '''
evalPoint( (Curve3d)arg1, (float)arg2) -> Point3d :

    C++ signature :
        class AcGePoint3d evalPoint(class PyGeCurve3d {lvalue},double)

evalPoint( (Curve3d)arg1, (float)arg2, (int)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple evalPoint(class PyGeCurve3d {lvalue},double,int)'''
    ...
    def explode (self, *args, **kwargs):
      '''
explode( (Curve3d)arg1) -> list :

    C++ signature :
        class boost::python::list explode(class PyGeCurve3d {lvalue})

explode( (Curve3d)arg1, (Interval)arg2) -> list :

    C++ signature :
        class boost::python::list explode(class PyGeCurve3d {lvalue},class PyGeInterval)'''
    ...
    def getClosestPointTo (self, *args, **kwargs):
      '''
getClosestPointTo( (Curve3d)arg1, (Point3d)arg2) -> PointOnCurve3d :

    C++ signature :
        class PyGePointOnCurve3d getClosestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d)

getClosestPointTo( (Curve3d)arg1, (Point3d)arg2, (Tol)arg3) -> PointOnCurve3d :

    C++ signature :
        class PyGePointOnCurve3d getClosestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def getClosestPointsTo (self, *args, **kwargs):
      '''
getClosestPointsTo( (Curve3d)arg1, (Curve3d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getClosestPointsTo(class PyGeCurve3d {lvalue},class PyGeCurve3d)

getClosestPointsTo( (Curve3d)arg1, (Curve3d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple getClosestPointsTo(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeTol)'''
    ...
    def getEndPoint (self, *args, **kwargs):
      '''
getEndPoint( (Curve3d)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d getEndPoint(class PyGeCurve3d {lvalue})'''
    ...
    def getInterval (self, *args, **kwargs):
      '''
getInterval( (Curve3d)arg1) -> Interval :

    C++ signature :
        class PyGeInterval getInterval(class PyGeCurve3d {lvalue})'''
    ...
    def getNormalPoint (self, *args, **kwargs):
      '''
getNormalPoint( (Curve3d)arg1, (Point3d)arg2) -> PointOnCurve3d :

    C++ signature :
        class PyGePointOnCurve3d getNormalPoint(class PyGeCurve3d {lvalue},class AcGePoint3d)

getNormalPoint( (Curve3d)arg1, (Point3d)arg2, (Tol)arg3) -> PointOnCurve3d :

    C++ signature :
        class PyGePointOnCurve3d getNormalPoint(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def getProjClosestPointTo (self, *args, **kwargs):
      '''
getProjClosestPointTo( (Curve3d)arg1, (Point3d)arg2, (Vector3d)arg3) -> PointOnCurve3d :

    C++ signature :
        class PyGePointOnCurve3d getProjClosestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeVector3d)

getProjClosestPointTo( (Curve3d)arg1, (Point3d)arg2, (Vector3d)arg3, (Tol)arg4) -> PointOnCurve3d :

    C++ signature :
        class PyGePointOnCurve3d getProjClosestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeVector3d,class AcGeTol)'''
    ...
    def getProjClosestPointsTo (self, *args, **kwargs):
      '''
getProjClosestPointsTo( (Curve3d)arg1, (Curve3d)arg2, (Vector3d)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple getProjClosestPointsTo(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeVector3d)

getProjClosestPointsTo( (Curve3d)arg1, (Curve3d)arg2, (Vector3d)arg3, (Tol)arg4) -> tuple :

    C++ signature :
        class boost::python::tuple getProjClosestPointsTo(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeVector3d,class AcGeTol)'''
    ...
    def getSamplePoints (self, *args, **kwargs):
      '''
getSamplePoints( (Curve3d)arg1, (int)arg2) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve3d {lvalue},int)

getSamplePoints( (Curve3d)arg1, (float)arg2, (float)arg3, (float)arg4) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve3d {lvalue},double,double,double)'''
    ...
    def getSplitCurves (self, *args, **kwargs):
      '''
getSplitCurves( (Curve3d)arg1, (float)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getSplitCurves(class PyGeCurve3d {lvalue},double)'''
    ...
    def getStartPoint (self, *args, **kwargs):
      '''
getStartPoint( (Curve3d)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d getStartPoint(class PyGeCurve3d {lvalue})'''
    ...
    def getTrimmedOffset (self, *args, **kwargs):
      '''
getTrimmedOffset( (Curve3d)arg1, (float)arg2, (Vector3d)arg3, (OffsetCrvExtType)arg4) -> list :

    C++ signature :
        class boost::python::list getTrimmedOffset(class PyGeCurve3d {lvalue},double,class AcGeVector3d,enum AcGe::OffsetCrvExtType)

getTrimmedOffset( (Curve3d)arg1, (float)arg2, (Vector3d)arg3, (OffsetCrvExtType)arg4, (Tol)arg5) -> list :

    C++ signature :
        class boost::python::list getTrimmedOffset(class PyGeCurve3d {lvalue},double,class AcGeVector3d,enum AcGe::OffsetCrvExtType,class AcGeTol)'''
    ...
    def hasEndPoint (self, *args, **kwargs):
      '''
hasEndPoint( (Curve3d)arg1) -> bool :

    C++ signature :
        bool hasEndPoint(class PyGeCurve3d {lvalue})'''
    ...
    def hasStartPoint (self, *args, **kwargs):
      '''
hasStartPoint( (Curve3d)arg1) -> bool :

    C++ signature :
        bool hasStartPoint(class PyGeCurve3d {lvalue})'''
    ...
    def isClosed (self, *args, **kwargs):
      '''
isClosed( (Curve3d)arg1) -> bool :

    C++ signature :
        bool isClosed(class PyGeCurve3d {lvalue})

isClosed( (Curve3d)arg1, (Tol)arg2) -> bool :

    C++ signature :
        bool isClosed(class PyGeCurve3d {lvalue},class AcGeTol)'''
    ...
    def isCoplanarWith (self, *args, **kwargs):
      '''
isCoplanarWith( (Curve3d)arg1, (Curve3d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isCoplanarWith(class PyGeCurve3d {lvalue},class PyGeCurve3d)

isCoplanarWith( (Curve3d)arg1, (Curve3d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple isCoplanarWith(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeTol)'''
    ...
    def isDegenerate (self, *args, **kwargs):
      '''
isDegenerate( (Curve3d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isDegenerate(class PyGeCurve3d {lvalue})

isDegenerate( (Curve3d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isDegenerate(class PyGeCurve3d {lvalue},class AcGeTol)'''
    ...
    def isEqualTo (self, *args, **kwargs):
      '''
isEqualTo( (Entity3d)arg1, (Entity3d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity3d {lvalue},class PyGeEntity3d,class AcGeTol)'''
    ...
    def isKindOf (self, *args, **kwargs):
      '''
isKindOf( (Entity3d)arg1, (EntityId)arg2) -> bool :

    C++ signature :
        bool isKindOf(class PyGeEntity3d {lvalue},enum AcGe::EntityId)'''
    ...
    def isLinear (self, *args, **kwargs):
      '''
isLinear( (Curve3d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isLinear(class PyGeCurve3d {lvalue})

isLinear( (Curve3d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isLinear(class PyGeCurve3d {lvalue},class AcGeTol)'''
    ...
    def isNull (self, *args, **kwargs):
      '''
isNull( (Entity3d)arg1) -> bool :

    C++ signature :
        bool isNull(class PyGeEntity3d {lvalue})'''
    ...
    def isOn (self, *args, **kwargs):
      '''
isOn( (Curve3d)arg1, (Point3d)arg2) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve3d {lvalue},class AcGePoint3d)

isOn( (Curve3d)arg1, (Point3d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeTol)

isOn( (Curve3d)arg1, (Point3d)arg2, (float)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve3d {lvalue},class AcGePoint3d,double {lvalue})

isOn( (Curve3d)arg1, (Point3d)arg2, (float)arg3, (Tol)arg4) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve3d {lvalue},class AcGePoint3d,double {lvalue},class AcGeTol)

isOn( (Curve3d)arg1, (float)arg2) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve3d {lvalue},double)

isOn( (Curve3d)arg1, (float)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve3d {lvalue},double,class AcGeTol)'''
    ...
    def isPeriodic (self, *args, **kwargs):
      '''
isPeriodic( (Curve3d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isPeriodic(class PyGeCurve3d {lvalue})'''
    ...
    def isPlanar (self, *args, **kwargs):
      '''
isPlanar( (Curve3d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isPlanar(class PyGeCurve3d {lvalue})

isPlanar( (Curve3d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isPlanar(class PyGeCurve3d {lvalue},class AcGeTol)'''
    ...
    def length (self, *args, **kwargs):
      '''
length( (Curve3d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double length(class PyGeCurve3d {lvalue},double,double)

length( (Curve3d)arg1, (float)arg2, (float)arg3, (float)arg4) -> float :

    C++ signature :
        double length(class PyGeCurve3d {lvalue},double,double,double)'''
    ...
    def mirror (self, *args, **kwargs):
      '''
mirror( (Entity3d)arg1, (Plane)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} mirror(class PyGeEntity3d {lvalue},class PyGePlane)'''
    ...
    def orthoBoundBlock (self, *args, **kwargs):
      '''
orthoBoundBlock( (Curve3d)arg1) -> BoundBlock3d :

    C++ signature :
        class PyGeBoundBlock3d orthoBoundBlock(class PyGeCurve3d {lvalue})

orthoBoundBlock( (Curve3d)arg1, (Interval)arg2) -> BoundBlock3d :

    C++ signature :
        class PyGeBoundBlock3d orthoBoundBlock(class PyGeCurve3d {lvalue},class PyGeInterval)'''
    ...
    def orthoProject (self, *args, **kwargs):
      '''
orthoProject( (Curve3d)arg1, (Plane)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d orthoProject(class PyGeCurve3d {lvalue},class PyGePlane)

orthoProject( (Curve3d)arg1, (Plane)arg2, (Tol)arg3) -> Entity3d :

    C++ signature :
        class PyGeEntity3d orthoProject(class PyGeCurve3d {lvalue},class PyGePlane,class AcGeTol)'''
    ...
    def paramAtLength (self, *args, **kwargs):
      '''
paramAtLength( (Curve3d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double paramAtLength(class PyGeCurve3d {lvalue},double,double)

paramAtLength( (Curve3d)arg1, (float)arg2, (float)arg3, (bool)arg4, (float)arg5) -> float :

    C++ signature :
        double paramAtLength(class PyGeCurve3d {lvalue},double,double,bool,double)'''
    ...
    def paramOf (self, *args, **kwargs):
      '''
paramOf( (Curve3d)arg1, (Point3d)arg2) -> float :

    C++ signature :
        double paramOf(class PyGeCurve3d {lvalue},class AcGePoint3d)

paramOf( (Curve3d)arg1, (Point3d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double paramOf(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def projClosestPointTo (self, *args, **kwargs):
      '''
projClosestPointTo( (Curve3d)arg1, (Point3d)arg2, (Vector3d)arg3) -> Point3d :

    C++ signature :
        class AcGePoint3d projClosestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeVector3d)

projClosestPointTo( (Curve3d)arg1, (Point3d)arg2, (Vector3d)arg3, (Tol)arg4) -> Point3d :

    C++ signature :
        class AcGePoint3d projClosestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeVector3d,class AcGeTol)'''
    ...
    def projClosestPointsTo (self, *args, **kwargs):
      '''
projClosestPointsTo( (Curve3d)arg1, (Curve3d)arg2, (Vector3d)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple projClosestPointsTo(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeVector3d)

projClosestPointsTo( (Curve3d)arg1, (Curve3d)arg2, (Vector3d)arg3, (Tol)arg4) -> tuple :

    C++ signature :
        class boost::python::tuple projClosestPointsTo(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeVector3d,class AcGeTol)'''
    ...
    def project (self, *args, **kwargs):
      '''
project( (Curve3d)arg1, (Plane)arg2, (Vector3d)arg3) -> Entity3d :

    C++ signature :
        class PyGeEntity3d project(class PyGeCurve3d {lvalue},class PyGePlane,class AcGeVector3d)

project( (Curve3d)arg1, (Plane)arg2, (Vector3d)arg3, (Tol)arg4) -> Entity3d :

    C++ signature :
        class PyGeEntity3d project(class PyGeCurve3d {lvalue},class PyGePlane,class AcGeVector3d,class AcGeTol)'''
    ...
    def reverseParam (self, *args, **kwargs):
      '''
reverseParam( (Curve3d)arg1) -> Curve3d :

    C++ signature :
        class PyGeCurve3d {lvalue} reverseParam(class PyGeCurve3d {lvalue})'''
    ...
    def rotateBy (self, *args, **kwargs):
      '''
rotateBy( (Entity3d)arg1, (float)arg2, (Vector3d)arg3) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} rotateBy(class PyGeEntity3d {lvalue},double,class AcGeVector3d)

rotateBy( (Entity3d)arg1, (float)arg2, (Vector3d)arg3, (Point3d)arg4) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} rotateBy(class PyGeEntity3d {lvalue},double,class AcGeVector3d,class AcGePoint3d)'''
    ...
    def scaleBy (self, *args, **kwargs):
      '''
scaleBy( (Entity3d)arg1, (float)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} scaleBy(class PyGeEntity3d {lvalue},double)

scaleBy( (Entity3d)arg1, (float)arg2, (Point3d)arg3) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} scaleBy(class PyGeEntity3d {lvalue},double,class AcGePoint3d)'''
    ...
    def setInterval (self, *args, **kwargs):
      '''
setInterval( (Curve3d)arg1) -> Curve3d :

    C++ signature :
        class PyGeCurve3d {lvalue} setInterval(class PyGeCurve3d {lvalue})

setInterval( (Curve3d)arg1, (Interval)arg2) -> bool :

    C++ signature :
        bool setInterval(class PyGeCurve3d {lvalue},class PyGeInterval)'''
    ...
    def transformBy (self, *args, **kwargs):
      '''
transformBy( (Entity3d)arg1, (Matrix3d)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} transformBy(class PyGeEntity3d {lvalue},class AcGeMatrix3d)'''
    ...
    def translateBy (self, *args, **kwargs):
      '''
translateBy( (Entity3d)arg1, (Vector3d)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} translateBy(class PyGeEntity3d {lvalue},class AcGeVector3d)'''
    ...
    def type (self, *args, **kwargs):
      '''
type( (Entity3d)arg1) -> EntityId :

    C++ signature :
        enum AcGe::EntityId type(class PyGeEntity3d {lvalue})'''
    ...

class CubicSplineCurve2d:
    def __eq__ (self, *args, **kwargs):
      '''
__eq__( (Entity2d)arg1, (Entity2d)arg2) -> bool :

    C++ signature :
        bool __eq__(class PyGeEntity2d {lvalue},class PyGeEntity2d)'''
    ...
    def __init__ (self, *args, **kwargs):
      '''
__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
    ...
    def __ne__ (self, *args, **kwargs):
      '''
__ne__( (Entity2d)arg1, (Entity2d)arg2) -> bool :

    C++ signature :
        bool __ne__(class PyGeEntity2d {lvalue},class PyGeEntity2d)'''
    ...
    def area (self, *args, **kwargs):
      '''
area( (Curve2d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double area(class PyGeCurve2d {lvalue},double,double)

area( (Curve2d)arg1, (float)arg2, (float)arg3, (Tol)arg4) -> float :

    C++ signature :
        double area(class PyGeCurve2d {lvalue},double,double,class AcGeTol)'''
    ...
    def boundBlock (self, *args, **kwargs):
      '''
boundBlock( (Curve2d)arg1) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d boundBlock(class PyGeCurve2d {lvalue})

boundBlock( (Curve2d)arg1, (Interval)arg2) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d boundBlock(class PyGeCurve2d {lvalue},class PyGeInterval)'''
    ...
    def className (self, *args, **kwargs):
      '''
className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def closestPointTo (self, *args, **kwargs):
      '''
closestPointTo( (Curve2d)arg1, (Point2d)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d closestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d)

closestPointTo( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> Point2d :

    C++ signature :
        class AcGePoint2d closestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)

closestPointTo( (Curve2d)arg1, (Curve2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointTo(class PyGeCurve2d {lvalue},class PyGeCurve2d)

closestPointTo( (Curve2d)arg1, (Curve2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointTo(class PyGeCurve2d {lvalue},class PyGeCurve2d,class AcGeTol)'''
    ...
    def continuityAtKnot (self, *args, **kwargs):
      '''
continuityAtKnot( (SplineEnt2d)arg1, (int)arg2) -> int :

    C++ signature :
        int continuityAtKnot(class PyGeSplineEnt2d {lvalue},int)

continuityAtKnot( (SplineEnt2d)arg1, (int)arg2, (Tol)arg3) -> int :

    C++ signature :
        int continuityAtKnot(class PyGeSplineEnt2d {lvalue},int,class AcGeTol)'''
    ...
    def controlPointAt (self, *args, **kwargs):
      '''
controlPointAt( (SplineEnt2d)arg1, (int)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d controlPointAt(class PyGeSplineEnt2d {lvalue},int)'''
    ...
    def copy (self, *args, **kwargs):
      '''
copy( (Entity2d)arg1) -> Entity2d :

    C++ signature :
        class PyGeEntity2d copy(class PyGeEntity2d {lvalue})'''
    ...
    def degree (self, *args, **kwargs):
      '''
degree( (SplineEnt2d)arg1) -> int :

    C++ signature :
        int degree(class PyGeSplineEnt2d {lvalue})'''
    ...
    def distanceTo (self, *args, **kwargs):
      '''
distanceTo( (Curve2d)arg1, (Point2d)arg2) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class AcGePoint2d)

distanceTo( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)

distanceTo( (Curve2d)arg1, (Curve2d)arg2) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class PyGeCurve2d)

distanceTo( (Curve2d)arg1, (Curve2d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class PyGeCurve2d,class AcGeTol)'''
    ...
    def endParam (self, *args, **kwargs):
      '''
endParam( (SplineEnt2d)arg1) -> float :

    C++ signature :
        double endParam(class PyGeSplineEnt2d {lvalue})'''
    ...
    def endPoint (self, *args, **kwargs):
      '''
endPoint( (SplineEnt2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d endPoint(class PyGeSplineEnt2d {lvalue})'''
    ...
    def evalPoint (self, *args, **kwargs):
      '''
evalPoint( (Curve2d)arg1, (float)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d evalPoint(class PyGeCurve2d {lvalue},double)

evalPoint( (Curve2d)arg1, (float)arg2, (int)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple evalPoint(class PyGeCurve2d {lvalue},double,int)'''
    ...
    def explode (self, *args, **kwargs):
      '''
explode( (Curve2d)arg1) -> list :

    C++ signature :
        class boost::python::list explode(class PyGeCurve2d {lvalue})

explode( (Curve2d)arg1, (Interval)arg2) -> list :

    C++ signature :
        class boost::python::list explode(class PyGeCurve2d {lvalue},class PyGeInterval)'''
    ...
    def getClosestPointTo (self, *args, **kwargs):
      '''
getClosestPointTo( (Curve2d)arg1, (Point2d)arg2) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getClosestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d)

getClosestPointTo( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getClosestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def getClosestPointsTo (self, *args, **kwargs):
      '''
getClosestPointsTo( (Curve2d)arg1, (Curve2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getClosestPointsTo(class PyGeCurve2d {lvalue},class PyGeCurve2d)

getClosestPointsTo( (Curve2d)arg1, (Curve2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple getClosestPointsTo(class PyGeCurve2d {lvalue},class PyGeCurve2d,class AcGeTol)'''
    ...
    def getEndPoint (self, *args, **kwargs):
      '''
getEndPoint( (Curve2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d getEndPoint(class PyGeCurve2d {lvalue})'''
    ...
    def getInterval (self, *args, **kwargs):
      '''
getInterval( (Curve2d)arg1) -> Interval :

    C++ signature :
        class PyGeInterval getInterval(class PyGeCurve2d {lvalue})'''
    ...
    def getNormalPoint (self, *args, **kwargs):
      '''
getNormalPoint( (Curve2d)arg1, (Point2d)arg2) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getNormalPoint(class PyGeCurve2d {lvalue},class AcGePoint2d)

getNormalPoint( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getNormalPoint(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def getSamplePoints (self, *args, **kwargs):
      '''
getSamplePoints( (Curve2d)arg1, (int)arg2) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve2d {lvalue},int)

getSamplePoints( (Curve2d)arg1, (float)arg2, (float)arg3, (float)arg4) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve2d {lvalue},double,double,double)'''
    ...
    def getSplitCurves (self, *args, **kwargs):
      '''
getSplitCurves( (Curve2d)arg1, (float)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getSplitCurves(class PyGeCurve2d {lvalue},double)'''
    ...
    def getStartPoint (self, *args, **kwargs):
      '''
getStartPoint( (Curve2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d getStartPoint(class PyGeCurve2d {lvalue})'''
    ...
    def getTrimmedOffset (self, *args, **kwargs):
      '''
getTrimmedOffset( (Curve2d)arg1, (float)arg2, (OffsetCrvExtType)arg3) -> list :

    C++ signature :
        class boost::python::list getTrimmedOffset(class PyGeCurve2d {lvalue},double,enum AcGe::OffsetCrvExtType)

getTrimmedOffset( (Curve2d)arg1, (float)arg2, (OffsetCrvExtType)arg3, (Tol)arg4) -> list :

    C++ signature :
        class boost::python::list getTrimmedOffset(class PyGeCurve2d {lvalue},double,enum AcGe::OffsetCrvExtType,class AcGeTol)'''
    ...
    def hasEndPoint (self, *args, **kwargs):
      '''
hasEndPoint( (Curve2d)arg1) -> bool :

    C++ signature :
        bool hasEndPoint(class PyGeCurve2d {lvalue})'''
    ...
    def hasFitData (self, *args, **kwargs):
      '''
hasFitData( (SplineEnt2d)arg1) -> bool :

    C++ signature :
        bool hasFitData(class PyGeSplineEnt2d {lvalue})'''
    ...
    def hasStartPoint (self, *args, **kwargs):
      '''
hasStartPoint( (Curve2d)arg1) -> bool :

    C++ signature :
        bool hasStartPoint(class PyGeCurve2d {lvalue})'''
    ...
    def isClosed (self, *args, **kwargs):
      '''
isClosed( (Curve2d)arg1) -> bool :

    C++ signature :
        bool isClosed(class PyGeCurve2d {lvalue})

isClosed( (Curve2d)arg1, (Tol)arg2) -> bool :

    C++ signature :
        bool isClosed(class PyGeCurve2d {lvalue},class AcGeTol)'''
    ...
    def isDegenerate (self, *args, **kwargs):
      '''
isDegenerate( (Curve2d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isDegenerate(class PyGeCurve2d {lvalue})

isDegenerate( (Curve2d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isDegenerate(class PyGeCurve2d {lvalue},class AcGeTol)'''
    ...
    def isEqualTo (self, *args, **kwargs):
      '''
isEqualTo( (Entity2d)arg1, (Entity2d)arg2) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity2d {lvalue},class PyGeEntity2d)

isEqualTo( (Entity2d)arg1, (Entity2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity2d {lvalue},class PyGeEntity2d,class AcGeTol)'''
    ...
    def isKindOf (self, *args, **kwargs):
      '''
isKindOf( (Entity2d)arg1, (EntityId)arg2) -> bool :

    C++ signature :
        bool isKindOf(class PyGeEntity2d {lvalue},enum AcGe::EntityId)'''
    ...
    def isLinear (self, *args, **kwargs):
      '''
isLinear( (Curve2d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isLinear(class PyGeCurve2d {lvalue})

isLinear( (Curve2d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isLinear(class PyGeCurve2d {lvalue},class AcGeTol)'''
    ...
    def isNull (self, *args, **kwargs):
      '''
isNull( (Entity2d)arg1) -> bool :

    C++ signature :
        bool isNull(class PyGeEntity2d {lvalue})'''
    ...
    def isOn (self, *args, **kwargs):
      '''
isOn( (Curve2d)arg1, (Point2d)arg2) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve2d {lvalue},class AcGePoint2d)

isOn( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)

isOn( (Curve2d)arg1, (Point2d)arg2, (float)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve2d {lvalue},class AcGePoint2d,double {lvalue})

isOn( (Curve2d)arg1, (Point2d)arg2, (float)arg3, (Tol)arg4) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve2d {lvalue},class AcGePoint2d,double {lvalue},class AcGeTol)

isOn( (Curve2d)arg1, (float)arg2) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve2d {lvalue},double)

isOn( (Curve2d)arg1, (float)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve2d {lvalue},double,class AcGeTol)'''
    ...
    def isPeriodic (self, *args, **kwargs):
      '''
isPeriodic( (Curve2d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isPeriodic(class PyGeCurve2d {lvalue})'''
    ...
    def isRational (self, *args, **kwargs):
      '''
isRational( (SplineEnt2d)arg1) -> bool :

    C++ signature :
        bool isRational(class PyGeSplineEnt2d {lvalue})'''
    ...
    def knotAt (self, *args, **kwargs):
      '''
knotAt( (SplineEnt2d)arg1, (int)arg2) -> float :

    C++ signature :
        double knotAt(class PyGeSplineEnt2d {lvalue},int)'''
    ...
    def knots (self, *args, **kwargs):
      '''
knots( (SplineEnt2d)arg1) -> KnotVector :

    C++ signature :
        class PyGeKnotVector knots(class PyGeSplineEnt2d {lvalue})'''
    ...
    def length (self, *args, **kwargs):
      '''
length( (Curve2d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double length(class PyGeCurve2d {lvalue},double,double)

length( (Curve2d)arg1, (float)arg2, (float)arg3, (float)arg4) -> float :

    C++ signature :
        double length(class PyGeCurve2d {lvalue},double,double,double)'''
    ...
    def mirror (self, *args, **kwargs):
      '''
mirror( (Entity2d)arg1, (Line2d)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} mirror(class PyGeEntity2d {lvalue},class PyGeLine2d)'''
    ...
    def numControlPoints (self, *args, **kwargs):
      '''
numControlPoints( (SplineEnt2d)arg1) -> int :

    C++ signature :
        int numControlPoints(class PyGeSplineEnt2d {lvalue})'''
    ...
    def numKnots (self, *args, **kwargs):
      '''
numKnots( (SplineEnt2d)arg1) -> int :

    C++ signature :
        int numKnots(class PyGeSplineEnt2d {lvalue})'''
    ...
    def order (self, *args, **kwargs):
      '''
order( (SplineEnt2d)arg1) -> int :

    C++ signature :
        int order(class PyGeSplineEnt2d {lvalue})'''
    ...
    def orthoBoundBlock (self, *args, **kwargs):
      '''
orthoBoundBlock( (Curve2d)arg1) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d orthoBoundBlock(class PyGeCurve2d {lvalue})

orthoBoundBlock( (Curve2d)arg1, (Interval)arg2) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d orthoBoundBlock(class PyGeCurve2d {lvalue},class PyGeInterval)'''
    ...
    def paramAtLength (self, *args, **kwargs):
      '''
paramAtLength( (Curve2d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double paramAtLength(class PyGeCurve2d {lvalue},double,double)

paramAtLength( (Curve2d)arg1, (float)arg2, (float)arg3, (bool)arg4, (float)arg5) -> float :

    C++ signature :
        double paramAtLength(class PyGeCurve2d {lvalue},double,double,bool,double)'''
    ...
    def paramOf (self, *args, **kwargs):
      '''
paramOf( (Curve2d)arg1, (Point2d)arg2) -> float :

    C++ signature :
        double paramOf(class PyGeCurve2d {lvalue},class AcGePoint2d)

paramOf( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double paramOf(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def reverseParam (self, *args, **kwargs):
      '''
reverseParam( (Curve2d)arg1) -> Curve2d :

    C++ signature :
        class PyGeCurve2d {lvalue} reverseParam(class PyGeCurve2d {lvalue})'''
    ...
    def rotateBy (self, *args, **kwargs):
      '''
rotateBy( (Entity2d)arg1, (float)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} rotateBy(class PyGeEntity2d {lvalue},double)

rotateBy( (Entity2d)arg1, (float)arg2, (Point2d)arg3) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} rotateBy(class PyGeEntity2d {lvalue},double,class AcGePoint2d)'''
    ...
    def scaleBy (self, *args, **kwargs):
      '''
scaleBy( (Entity2d)arg1, (float)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} scaleBy(class PyGeEntity2d {lvalue},double)

scaleBy( (Entity2d)arg1, (float)arg2, (Point2d)arg3) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} scaleBy(class PyGeEntity2d {lvalue},double,class AcGePoint2d)'''
    ...
    def setControlPointAt (self, *args, **kwargs):
      '''
setControlPointAt( (SplineEnt2d)arg1, (int)arg2, (Point2d)arg3) -> SplineEnt2d :

    C++ signature :
        class PyGeSplineEnt2d {lvalue} setControlPointAt(class PyGeSplineEnt2d {lvalue},int,class AcGePoint2d)'''
    ...
    def setInterval (self, *args, **kwargs):
      '''
setInterval( (Curve2d)arg1) -> Curve2d :

    C++ signature :
        class PyGeCurve2d {lvalue} setInterval(class PyGeCurve2d {lvalue})

setInterval( (Curve2d)arg1, (Interval)arg2) -> bool :

    C++ signature :
        bool setInterval(class PyGeCurve2d {lvalue},class PyGeInterval)'''
    ...
    def setKnotAt (self, *args, **kwargs):
      '''
setKnotAt( (SplineEnt2d)arg1, (int)arg2, (float)arg3) -> SplineEnt2d :

    C++ signature :
        class PyGeSplineEnt2d {lvalue} setKnotAt(class PyGeSplineEnt2d {lvalue},int,double)'''
    ...
    def startParam (self, *args, **kwargs):
      '''
startParam( (SplineEnt2d)arg1) -> float :

    C++ signature :
        double startParam(class PyGeSplineEnt2d {lvalue})'''
    ...
    def startPoint (self, *args, **kwargs):
      '''
startPoint( (SplineEnt2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d startPoint(class PyGeSplineEnt2d {lvalue})'''
    ...
    def transformBy (self, *args, **kwargs):
      '''
transformBy( (Entity2d)arg1, (Matrix2d)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} transformBy(class PyGeEntity2d {lvalue},class AcGeMatrix2d)'''
    ...
    def translateBy (self, *args, **kwargs):
      '''
translateBy( (Entity2d)arg1, (Vector2d)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} translateBy(class PyGeEntity2d {lvalue},class AcGeVector2d)'''
    ...
    def type (self, *args, **kwargs):
      '''
type( (Entity2d)arg1) -> EntityId :

    C++ signature :
        enum AcGe::EntityId type(class PyGeEntity2d {lvalue})'''
    ...

class CubicSplineCurve3d:
    def __eq__ (self, *args, **kwargs):
      '''
__eq__( (Entity3d)arg1, (Entity3d)arg2) -> bool :

    C++ signature :
        bool __eq__(class PyGeEntity3d {lvalue},class PyGeEntity3d)'''
    ...
    def __init__ (self, *args, **kwargs):
      '''
__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
    ...
    def __ne__ (self, *args, **kwargs):
      '''
__ne__( (Entity3d)arg1, (Entity3d)arg2) -> bool :

    C++ signature :
        bool __ne__(class PyGeEntity3d {lvalue},class PyGeEntity3d)'''
    ...
    def area (self, *args, **kwargs):
      '''
area( (Curve3d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double area(class PyGeCurve3d {lvalue},double,double)

area( (Curve3d)arg1, (float)arg2, (float)arg3, (Tol)arg4) -> float :

    C++ signature :
        double area(class PyGeCurve3d {lvalue},double,double,class AcGeTol)'''
    ...
    def boundBlock (self, *args, **kwargs):
      '''
boundBlock( (Curve3d)arg1) -> BoundBlock3d :

    C++ signature :
        class PyGeBoundBlock3d boundBlock(class PyGeCurve3d {lvalue})

boundBlock( (Curve3d)arg1, (Interval)arg2) -> BoundBlock3d :

    C++ signature :
        class PyGeBoundBlock3d boundBlock(class PyGeCurve3d {lvalue},class PyGeInterval)'''
    ...
    def className (self, *args, **kwargs):
      '''
className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def closestPointTo (self, *args, **kwargs):
      '''
closestPointTo( (Curve3d)arg1, (Point3d)arg2) -> Point3d :

    C++ signature :
        class AcGePoint3d closestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d)

closestPointTo( (Curve3d)arg1, (Point3d)arg2, (Tol)arg3) -> Point3d :

    C++ signature :
        class AcGePoint3d closestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeTol)

closestPointTo( (Curve3d)arg1, (Curve3d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointTo(class PyGeCurve3d {lvalue},class PyGeCurve3d)

closestPointTo( (Curve3d)arg1, (Curve3d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointTo(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeTol)'''
    ...
    def continuityAtKnot (self, *args, **kwargs):
      '''
continuityAtKnot( (SplineEnt3d)arg1, (int)arg2) -> int :

    C++ signature :
        int continuityAtKnot(class PyGeSplineEnt3d {lvalue},int)

continuityAtKnot( (SplineEnt3d)arg1, (int)arg2, (Tol)arg3) -> int :

    C++ signature :
        int continuityAtKnot(class PyGeSplineEnt3d {lvalue},int,class AcGeTol)'''
    ...
    def controlPointAt (self, *args, **kwargs):
      '''
controlPointAt( (SplineEnt3d)arg1, (int)arg2) -> Point3d :

    C++ signature :
        class AcGePoint3d controlPointAt(class PyGeSplineEnt3d {lvalue},int)'''
    ...
    def copy (self, *args, **kwargs):
      '''
copy( (Entity3d)arg1) -> Entity3d :

    C++ signature :
        class PyGeEntity3d copy(class PyGeEntity3d {lvalue})'''
    ...
    def degree (self, *args, **kwargs):
      '''
degree( (SplineEnt3d)arg1) -> int :

    C++ signature :
        int degree(class PyGeSplineEnt3d {lvalue})'''
    ...
    def distanceTo (self, *args, **kwargs):
      '''
distanceTo( (Curve3d)arg1, (Point3d)arg2) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve3d {lvalue},class AcGePoint3d)

distanceTo( (Curve3d)arg1, (Point3d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeTol)

distanceTo( (Curve3d)arg1, (Curve3d)arg2) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve3d {lvalue},class PyGeCurve3d)

distanceTo( (Curve3d)arg1, (Curve3d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeTol)'''
    ...
    def endParam (self, *args, **kwargs):
      '''
endParam( (SplineEnt3d)arg1) -> float :

    C++ signature :
        double endParam(class PyGeSplineEnt3d {lvalue})'''
    ...
    def endPoint (self, *args, **kwargs):
      '''
endPoint( (SplineEnt3d)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d endPoint(class PyGeSplineEnt3d {lvalue})'''
    ...
    def evalPoint (self, *args, **kwargs):
      '''
evalPoint( (Curve3d)arg1, (float)arg2) -> Point3d :

    C++ signature :
        class AcGePoint3d evalPoint(class PyGeCurve3d {lvalue},double)

evalPoint( (Curve3d)arg1, (float)arg2, (int)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple evalPoint(class PyGeCurve3d {lvalue},double,int)'''
    ...
    def explode (self, *args, **kwargs):
      '''
explode( (Curve3d)arg1) -> list :

    C++ signature :
        class boost::python::list explode(class PyGeCurve3d {lvalue})

explode( (Curve3d)arg1, (Interval)arg2) -> list :

    C++ signature :
        class boost::python::list explode(class PyGeCurve3d {lvalue},class PyGeInterval)'''
    ...
    def getClosestPointTo (self, *args, **kwargs):
      '''
getClosestPointTo( (Curve3d)arg1, (Point3d)arg2) -> PointOnCurve3d :

    C++ signature :
        class PyGePointOnCurve3d getClosestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d)

getClosestPointTo( (Curve3d)arg1, (Point3d)arg2, (Tol)arg3) -> PointOnCurve3d :

    C++ signature :
        class PyGePointOnCurve3d getClosestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def getClosestPointsTo (self, *args, **kwargs):
      '''
getClosestPointsTo( (Curve3d)arg1, (Curve3d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getClosestPointsTo(class PyGeCurve3d {lvalue},class PyGeCurve3d)

getClosestPointsTo( (Curve3d)arg1, (Curve3d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple getClosestPointsTo(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeTol)'''
    ...
    def getEndPoint (self, *args, **kwargs):
      '''
getEndPoint( (Curve3d)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d getEndPoint(class PyGeCurve3d {lvalue})'''
    ...
    def getInterval (self, *args, **kwargs):
      '''
getInterval( (Curve3d)arg1) -> Interval :

    C++ signature :
        class PyGeInterval getInterval(class PyGeCurve3d {lvalue})'''
    ...
    def getNormalPoint (self, *args, **kwargs):
      '''
getNormalPoint( (Curve3d)arg1, (Point3d)arg2) -> PointOnCurve3d :

    C++ signature :
        class PyGePointOnCurve3d getNormalPoint(class PyGeCurve3d {lvalue},class AcGePoint3d)

getNormalPoint( (Curve3d)arg1, (Point3d)arg2, (Tol)arg3) -> PointOnCurve3d :

    C++ signature :
        class PyGePointOnCurve3d getNormalPoint(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def getProjClosestPointTo (self, *args, **kwargs):
      '''
getProjClosestPointTo( (Curve3d)arg1, (Point3d)arg2, (Vector3d)arg3) -> PointOnCurve3d :

    C++ signature :
        class PyGePointOnCurve3d getProjClosestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeVector3d)

getProjClosestPointTo( (Curve3d)arg1, (Point3d)arg2, (Vector3d)arg3, (Tol)arg4) -> PointOnCurve3d :

    C++ signature :
        class PyGePointOnCurve3d getProjClosestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeVector3d,class AcGeTol)'''
    ...
    def getProjClosestPointsTo (self, *args, **kwargs):
      '''
getProjClosestPointsTo( (Curve3d)arg1, (Curve3d)arg2, (Vector3d)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple getProjClosestPointsTo(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeVector3d)

getProjClosestPointsTo( (Curve3d)arg1, (Curve3d)arg2, (Vector3d)arg3, (Tol)arg4) -> tuple :

    C++ signature :
        class boost::python::tuple getProjClosestPointsTo(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeVector3d,class AcGeTol)'''
    ...
    def getSamplePoints (self, *args, **kwargs):
      '''
getSamplePoints( (Curve3d)arg1, (int)arg2) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve3d {lvalue},int)

getSamplePoints( (Curve3d)arg1, (float)arg2, (float)arg3, (float)arg4) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve3d {lvalue},double,double,double)'''
    ...
    def getSplitCurves (self, *args, **kwargs):
      '''
getSplitCurves( (Curve3d)arg1, (float)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getSplitCurves(class PyGeCurve3d {lvalue},double)'''
    ...
    def getStartPoint (self, *args, **kwargs):
      '''
getStartPoint( (Curve3d)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d getStartPoint(class PyGeCurve3d {lvalue})'''
    ...
    def getTrimmedOffset (self, *args, **kwargs):
      '''
getTrimmedOffset( (Curve3d)arg1, (float)arg2, (Vector3d)arg3, (OffsetCrvExtType)arg4) -> list :

    C++ signature :
        class boost::python::list getTrimmedOffset(class PyGeCurve3d {lvalue},double,class AcGeVector3d,enum AcGe::OffsetCrvExtType)

getTrimmedOffset( (Curve3d)arg1, (float)arg2, (Vector3d)arg3, (OffsetCrvExtType)arg4, (Tol)arg5) -> list :

    C++ signature :
        class boost::python::list getTrimmedOffset(class PyGeCurve3d {lvalue},double,class AcGeVector3d,enum AcGe::OffsetCrvExtType,class AcGeTol)'''
    ...
    def hasEndPoint (self, *args, **kwargs):
      '''
hasEndPoint( (Curve3d)arg1) -> bool :

    C++ signature :
        bool hasEndPoint(class PyGeCurve3d {lvalue})'''
    ...
    def hasFitData (self, *args, **kwargs):
      '''
hasFitData( (SplineEnt3d)arg1) -> bool :

    C++ signature :
        bool hasFitData(class PyGeSplineEnt3d {lvalue})'''
    ...
    def hasStartPoint (self, *args, **kwargs):
      '''
hasStartPoint( (Curve3d)arg1) -> bool :

    C++ signature :
        bool hasStartPoint(class PyGeCurve3d {lvalue})'''
    ...
    def isClosed (self, *args, **kwargs):
      '''
isClosed( (Curve3d)arg1) -> bool :

    C++ signature :
        bool isClosed(class PyGeCurve3d {lvalue})

isClosed( (Curve3d)arg1, (Tol)arg2) -> bool :

    C++ signature :
        bool isClosed(class PyGeCurve3d {lvalue},class AcGeTol)'''
    ...
    def isCoplanarWith (self, *args, **kwargs):
      '''
isCoplanarWith( (Curve3d)arg1, (Curve3d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isCoplanarWith(class PyGeCurve3d {lvalue},class PyGeCurve3d)

isCoplanarWith( (Curve3d)arg1, (Curve3d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple isCoplanarWith(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeTol)'''
    ...
    def isDegenerate (self, *args, **kwargs):
      '''
isDegenerate( (Curve3d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isDegenerate(class PyGeCurve3d {lvalue})

isDegenerate( (Curve3d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isDegenerate(class PyGeCurve3d {lvalue},class AcGeTol)'''
    ...
    def isEqualTo (self, *args, **kwargs):
      '''
isEqualTo( (Entity3d)arg1, (Entity3d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity3d {lvalue},class PyGeEntity3d,class AcGeTol)'''
    ...
    def isKindOf (self, *args, **kwargs):
      '''
isKindOf( (Entity3d)arg1, (EntityId)arg2) -> bool :

    C++ signature :
        bool isKindOf(class PyGeEntity3d {lvalue},enum AcGe::EntityId)'''
    ...
    def isLinear (self, *args, **kwargs):
      '''
isLinear( (Curve3d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isLinear(class PyGeCurve3d {lvalue})

isLinear( (Curve3d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isLinear(class PyGeCurve3d {lvalue},class AcGeTol)'''
    ...
    def isNull (self, *args, **kwargs):
      '''
isNull( (Entity3d)arg1) -> bool :

    C++ signature :
        bool isNull(class PyGeEntity3d {lvalue})'''
    ...
    def isOn (self, *args, **kwargs):
      '''
isOn( (Curve3d)arg1, (Point3d)arg2) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve3d {lvalue},class AcGePoint3d)

isOn( (Curve3d)arg1, (Point3d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeTol)

isOn( (Curve3d)arg1, (Point3d)arg2, (float)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve3d {lvalue},class AcGePoint3d,double {lvalue})

isOn( (Curve3d)arg1, (Point3d)arg2, (float)arg3, (Tol)arg4) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve3d {lvalue},class AcGePoint3d,double {lvalue},class AcGeTol)

isOn( (Curve3d)arg1, (float)arg2) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve3d {lvalue},double)

isOn( (Curve3d)arg1, (float)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve3d {lvalue},double,class AcGeTol)'''
    ...
    def isPeriodic (self, *args, **kwargs):
      '''
isPeriodic( (Curve3d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isPeriodic(class PyGeCurve3d {lvalue})'''
    ...
    def isPlanar (self, *args, **kwargs):
      '''
isPlanar( (Curve3d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isPlanar(class PyGeCurve3d {lvalue})

isPlanar( (Curve3d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isPlanar(class PyGeCurve3d {lvalue},class AcGeTol)'''
    ...
    def isRational (self, *args, **kwargs):
      '''
isRational( (SplineEnt3d)arg1) -> bool :

    C++ signature :
        bool isRational(class PyGeSplineEnt3d {lvalue})'''
    ...
    def knotAt (self, *args, **kwargs):
      '''
knotAt( (SplineEnt3d)arg1, (int)arg2) -> float :

    C++ signature :
        double knotAt(class PyGeSplineEnt3d {lvalue},int)'''
    ...
    def knots (self, *args, **kwargs):
      '''
knots( (SplineEnt3d)arg1) -> KnotVector :

    C++ signature :
        class PyGeKnotVector knots(class PyGeSplineEnt3d {lvalue})'''
    ...
    def length (self, *args, **kwargs):
      '''
length( (Curve3d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double length(class PyGeCurve3d {lvalue},double,double)

length( (Curve3d)arg1, (float)arg2, (float)arg3, (float)arg4) -> float :

    C++ signature :
        double length(class PyGeCurve3d {lvalue},double,double,double)'''
    ...
    def mirror (self, *args, **kwargs):
      '''
mirror( (Entity3d)arg1, (Plane)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} mirror(class PyGeEntity3d {lvalue},class PyGePlane)'''
    ...
    def numControlPoints (self, *args, **kwargs):
      '''
numControlPoints( (SplineEnt3d)arg1) -> int :

    C++ signature :
        int numControlPoints(class PyGeSplineEnt3d {lvalue})'''
    ...
    def numKnots (self, *args, **kwargs):
      '''
numKnots( (SplineEnt3d)arg1) -> int :

    C++ signature :
        int numKnots(class PyGeSplineEnt3d {lvalue})'''
    ...
    def order (self, *args, **kwargs):
      '''
order( (SplineEnt3d)arg1) -> int :

    C++ signature :
        int order(class PyGeSplineEnt3d {lvalue})'''
    ...
    def orthoBoundBlock (self, *args, **kwargs):
      '''
orthoBoundBlock( (Curve3d)arg1) -> BoundBlock3d :

    C++ signature :
        class PyGeBoundBlock3d orthoBoundBlock(class PyGeCurve3d {lvalue})

orthoBoundBlock( (Curve3d)arg1, (Interval)arg2) -> BoundBlock3d :

    C++ signature :
        class PyGeBoundBlock3d orthoBoundBlock(class PyGeCurve3d {lvalue},class PyGeInterval)'''
    ...
    def orthoProject (self, *args, **kwargs):
      '''
orthoProject( (Curve3d)arg1, (Plane)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d orthoProject(class PyGeCurve3d {lvalue},class PyGePlane)

orthoProject( (Curve3d)arg1, (Plane)arg2, (Tol)arg3) -> Entity3d :

    C++ signature :
        class PyGeEntity3d orthoProject(class PyGeCurve3d {lvalue},class PyGePlane,class AcGeTol)'''
    ...
    def paramAtLength (self, *args, **kwargs):
      '''
paramAtLength( (Curve3d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double paramAtLength(class PyGeCurve3d {lvalue},double,double)

paramAtLength( (Curve3d)arg1, (float)arg2, (float)arg3, (bool)arg4, (float)arg5) -> float :

    C++ signature :
        double paramAtLength(class PyGeCurve3d {lvalue},double,double,bool,double)'''
    ...
    def paramOf (self, *args, **kwargs):
      '''
paramOf( (Curve3d)arg1, (Point3d)arg2) -> float :

    C++ signature :
        double paramOf(class PyGeCurve3d {lvalue},class AcGePoint3d)

paramOf( (Curve3d)arg1, (Point3d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double paramOf(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def projClosestPointTo (self, *args, **kwargs):
      '''
projClosestPointTo( (Curve3d)arg1, (Point3d)arg2, (Vector3d)arg3) -> Point3d :

    C++ signature :
        class AcGePoint3d projClosestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeVector3d)

projClosestPointTo( (Curve3d)arg1, (Point3d)arg2, (Vector3d)arg3, (Tol)arg4) -> Point3d :

    C++ signature :
        class AcGePoint3d projClosestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeVector3d,class AcGeTol)'''
    ...
    def projClosestPointsTo (self, *args, **kwargs):
      '''
projClosestPointsTo( (Curve3d)arg1, (Curve3d)arg2, (Vector3d)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple projClosestPointsTo(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeVector3d)

projClosestPointsTo( (Curve3d)arg1, (Curve3d)arg2, (Vector3d)arg3, (Tol)arg4) -> tuple :

    C++ signature :
        class boost::python::tuple projClosestPointsTo(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeVector3d,class AcGeTol)'''
    ...
    def project (self, *args, **kwargs):
      '''
project( (Curve3d)arg1, (Plane)arg2, (Vector3d)arg3) -> Entity3d :

    C++ signature :
        class PyGeEntity3d project(class PyGeCurve3d {lvalue},class PyGePlane,class AcGeVector3d)

project( (Curve3d)arg1, (Plane)arg2, (Vector3d)arg3, (Tol)arg4) -> Entity3d :

    C++ signature :
        class PyGeEntity3d project(class PyGeCurve3d {lvalue},class PyGePlane,class AcGeVector3d,class AcGeTol)'''
    ...
    def reverseParam (self, *args, **kwargs):
      '''
reverseParam( (Curve3d)arg1) -> Curve3d :

    C++ signature :
        class PyGeCurve3d {lvalue} reverseParam(class PyGeCurve3d {lvalue})'''
    ...
    def rotateBy (self, *args, **kwargs):
      '''
rotateBy( (Entity3d)arg1, (float)arg2, (Vector3d)arg3) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} rotateBy(class PyGeEntity3d {lvalue},double,class AcGeVector3d)

rotateBy( (Entity3d)arg1, (float)arg2, (Vector3d)arg3, (Point3d)arg4) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} rotateBy(class PyGeEntity3d {lvalue},double,class AcGeVector3d,class AcGePoint3d)'''
    ...
    def scaleBy (self, *args, **kwargs):
      '''
scaleBy( (Entity3d)arg1, (float)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} scaleBy(class PyGeEntity3d {lvalue},double)

scaleBy( (Entity3d)arg1, (float)arg2, (Point3d)arg3) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} scaleBy(class PyGeEntity3d {lvalue},double,class AcGePoint3d)'''
    ...
    def setControlPointAt (self, *args, **kwargs):
      '''
setControlPointAt( (SplineEnt3d)arg1, (int)arg2, (Point3d)arg3) -> SplineEnt3d :

    C++ signature :
        class PyGeSplineEnt3d {lvalue} setControlPointAt(class PyGeSplineEnt3d {lvalue},int,class AcGePoint3d)'''
    ...
    def setInterval (self, *args, **kwargs):
      '''
setInterval( (Curve3d)arg1) -> Curve3d :

    C++ signature :
        class PyGeCurve3d {lvalue} setInterval(class PyGeCurve3d {lvalue})

setInterval( (Curve3d)arg1, (Interval)arg2) -> bool :

    C++ signature :
        bool setInterval(class PyGeCurve3d {lvalue},class PyGeInterval)'''
    ...
    def setKnotAt (self, *args, **kwargs):
      '''
setKnotAt( (SplineEnt3d)arg1, (int)arg2, (float)arg3) -> SplineEnt3d :

    C++ signature :
        class PyGeSplineEnt3d {lvalue} setKnotAt(class PyGeSplineEnt3d {lvalue},int,double)'''
    ...
    def startParam (self, *args, **kwargs):
      '''
startParam( (SplineEnt3d)arg1) -> float :

    C++ signature :
        double startParam(class PyGeSplineEnt3d {lvalue})'''
    ...
    def startPoint (self, *args, **kwargs):
      '''
startPoint( (SplineEnt3d)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d startPoint(class PyGeSplineEnt3d {lvalue})'''
    ...
    def transformBy (self, *args, **kwargs):
      '''
transformBy( (Entity3d)arg1, (Matrix3d)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} transformBy(class PyGeEntity3d {lvalue},class AcGeMatrix3d)'''
    ...
    def translateBy (self, *args, **kwargs):
      '''
translateBy( (Entity3d)arg1, (Vector3d)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} translateBy(class PyGeEntity3d {lvalue},class AcGeVector3d)'''
    ...
    def type (self, *args, **kwargs):
      '''
type( (Entity3d)arg1) -> EntityId :

    C++ signature :
        enum AcGe::EntityId type(class PyGeEntity3d {lvalue})'''
    ...

class Curve2d:
    def __eq__ (self, *args, **kwargs):
      '''
__eq__( (Entity2d)arg1, (Entity2d)arg2) -> bool :

    C++ signature :
        bool __eq__(class PyGeEntity2d {lvalue},class PyGeEntity2d)'''
    ...
    def __init__ (self, *args, **kwargs):
      '''Raises an exception
This class cannot be instantiated from Python
'''
    ...
    def __ne__ (self, *args, **kwargs):
      '''
__ne__( (Entity2d)arg1, (Entity2d)arg2) -> bool :

    C++ signature :
        bool __ne__(class PyGeEntity2d {lvalue},class PyGeEntity2d)'''
    ...
    def area (self, *args, **kwargs):
      '''
area( (Curve2d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double area(class PyGeCurve2d {lvalue},double,double)

area( (Curve2d)arg1, (float)arg2, (float)arg3, (Tol)arg4) -> float :

    C++ signature :
        double area(class PyGeCurve2d {lvalue},double,double,class AcGeTol)'''
    ...
    def boundBlock (self, *args, **kwargs):
      '''
boundBlock( (Curve2d)arg1) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d boundBlock(class PyGeCurve2d {lvalue})

boundBlock( (Curve2d)arg1, (Interval)arg2) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d boundBlock(class PyGeCurve2d {lvalue},class PyGeInterval)'''
    ...
    def className (self, *args, **kwargs):
      '''
className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def closestPointTo (self, *args, **kwargs):
      '''
closestPointTo( (Curve2d)arg1, (Point2d)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d closestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d)

closestPointTo( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> Point2d :

    C++ signature :
        class AcGePoint2d closestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)

closestPointTo( (Curve2d)arg1, (Curve2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointTo(class PyGeCurve2d {lvalue},class PyGeCurve2d)

closestPointTo( (Curve2d)arg1, (Curve2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointTo(class PyGeCurve2d {lvalue},class PyGeCurve2d,class AcGeTol)'''
    ...
    def copy (self, *args, **kwargs):
      '''
copy( (Entity2d)arg1) -> Entity2d :

    C++ signature :
        class PyGeEntity2d copy(class PyGeEntity2d {lvalue})'''
    ...
    def distanceTo (self, *args, **kwargs):
      '''
distanceTo( (Curve2d)arg1, (Point2d)arg2) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class AcGePoint2d)

distanceTo( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)

distanceTo( (Curve2d)arg1, (Curve2d)arg2) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class PyGeCurve2d)

distanceTo( (Curve2d)arg1, (Curve2d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class PyGeCurve2d,class AcGeTol)'''
    ...
    def evalPoint (self, *args, **kwargs):
      '''
evalPoint( (Curve2d)arg1, (float)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d evalPoint(class PyGeCurve2d {lvalue},double)

evalPoint( (Curve2d)arg1, (float)arg2, (int)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple evalPoint(class PyGeCurve2d {lvalue},double,int)'''
    ...
    def explode (self, *args, **kwargs):
      '''
explode( (Curve2d)arg1) -> list :

    C++ signature :
        class boost::python::list explode(class PyGeCurve2d {lvalue})

explode( (Curve2d)arg1, (Interval)arg2) -> list :

    C++ signature :
        class boost::python::list explode(class PyGeCurve2d {lvalue},class PyGeInterval)'''
    ...
    def getClosestPointTo (self, *args, **kwargs):
      '''
getClosestPointTo( (Curve2d)arg1, (Point2d)arg2) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getClosestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d)

getClosestPointTo( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getClosestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def getClosestPointsTo (self, *args, **kwargs):
      '''
getClosestPointsTo( (Curve2d)arg1, (Curve2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getClosestPointsTo(class PyGeCurve2d {lvalue},class PyGeCurve2d)

getClosestPointsTo( (Curve2d)arg1, (Curve2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple getClosestPointsTo(class PyGeCurve2d {lvalue},class PyGeCurve2d,class AcGeTol)'''
    ...
    def getEndPoint (self, *args, **kwargs):
      '''
getEndPoint( (Curve2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d getEndPoint(class PyGeCurve2d {lvalue})'''
    ...
    def getInterval (self, *args, **kwargs):
      '''
getInterval( (Curve2d)arg1) -> Interval :

    C++ signature :
        class PyGeInterval getInterval(class PyGeCurve2d {lvalue})'''
    ...
    def getNormalPoint (self, *args, **kwargs):
      '''
getNormalPoint( (Curve2d)arg1, (Point2d)arg2) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getNormalPoint(class PyGeCurve2d {lvalue},class AcGePoint2d)

getNormalPoint( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getNormalPoint(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def getSamplePoints (self, *args, **kwargs):
      '''
getSamplePoints( (Curve2d)arg1, (int)arg2) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve2d {lvalue},int)

getSamplePoints( (Curve2d)arg1, (float)arg2, (float)arg3, (float)arg4) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve2d {lvalue},double,double,double)'''
    ...
    def getSplitCurves (self, *args, **kwargs):
      '''
getSplitCurves( (Curve2d)arg1, (float)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getSplitCurves(class PyGeCurve2d {lvalue},double)'''
    ...
    def getStartPoint (self, *args, **kwargs):
      '''
getStartPoint( (Curve2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d getStartPoint(class PyGeCurve2d {lvalue})'''
    ...
    def getTrimmedOffset (self, *args, **kwargs):
      '''
getTrimmedOffset( (Curve2d)arg1, (float)arg2, (OffsetCrvExtType)arg3) -> list :

    C++ signature :
        class boost::python::list getTrimmedOffset(class PyGeCurve2d {lvalue},double,enum AcGe::OffsetCrvExtType)

getTrimmedOffset( (Curve2d)arg1, (float)arg2, (OffsetCrvExtType)arg3, (Tol)arg4) -> list :

    C++ signature :
        class boost::python::list getTrimmedOffset(class PyGeCurve2d {lvalue},double,enum AcGe::OffsetCrvExtType,class AcGeTol)'''
    ...
    def hasEndPoint (self, *args, **kwargs):
      '''
hasEndPoint( (Curve2d)arg1) -> bool :

    C++ signature :
        bool hasEndPoint(class PyGeCurve2d {lvalue})'''
    ...
    def hasStartPoint (self, *args, **kwargs):
      '''
hasStartPoint( (Curve2d)arg1) -> bool :

    C++ signature :
        bool hasStartPoint(class PyGeCurve2d {lvalue})'''
    ...
    def isClosed (self, *args, **kwargs):
      '''
isClosed( (Curve2d)arg1) -> bool :

    C++ signature :
        bool isClosed(class PyGeCurve2d {lvalue})

isClosed( (Curve2d)arg1, (Tol)arg2) -> bool :

    C++ signature :
        bool isClosed(class PyGeCurve2d {lvalue},class AcGeTol)'''
    ...
    def isDegenerate (self, *args, **kwargs):
      '''
isDegenerate( (Curve2d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isDegenerate(class PyGeCurve2d {lvalue})

isDegenerate( (Curve2d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isDegenerate(class PyGeCurve2d {lvalue},class AcGeTol)'''
    ...
    def isEqualTo (self, *args, **kwargs):
      '''
isEqualTo( (Entity2d)arg1, (Entity2d)arg2) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity2d {lvalue},class PyGeEntity2d)

isEqualTo( (Entity2d)arg1, (Entity2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity2d {lvalue},class PyGeEntity2d,class AcGeTol)'''
    ...
    def isKindOf (self, *args, **kwargs):
      '''
isKindOf( (Entity2d)arg1, (EntityId)arg2) -> bool :

    C++ signature :
        bool isKindOf(class PyGeEntity2d {lvalue},enum AcGe::EntityId)'''
    ...
    def isLinear (self, *args, **kwargs):
      '''
isLinear( (Curve2d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isLinear(class PyGeCurve2d {lvalue})

isLinear( (Curve2d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isLinear(class PyGeCurve2d {lvalue},class AcGeTol)'''
    ...
    def isNull (self, *args, **kwargs):
      '''
isNull( (Entity2d)arg1) -> bool :

    C++ signature :
        bool isNull(class PyGeEntity2d {lvalue})'''
    ...
    def isOn (self, *args, **kwargs):
      '''
isOn( (Curve2d)arg1, (Point2d)arg2) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve2d {lvalue},class AcGePoint2d)

isOn( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)

isOn( (Curve2d)arg1, (Point2d)arg2, (float)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve2d {lvalue},class AcGePoint2d,double {lvalue})

isOn( (Curve2d)arg1, (Point2d)arg2, (float)arg3, (Tol)arg4) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve2d {lvalue},class AcGePoint2d,double {lvalue},class AcGeTol)

isOn( (Curve2d)arg1, (float)arg2) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve2d {lvalue},double)

isOn( (Curve2d)arg1, (float)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve2d {lvalue},double,class AcGeTol)'''
    ...
    def isPeriodic (self, *args, **kwargs):
      '''
isPeriodic( (Curve2d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isPeriodic(class PyGeCurve2d {lvalue})'''
    ...
    def length (self, *args, **kwargs):
      '''
length( (Curve2d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double length(class PyGeCurve2d {lvalue},double,double)

length( (Curve2d)arg1, (float)arg2, (float)arg3, (float)arg4) -> float :

    C++ signature :
        double length(class PyGeCurve2d {lvalue},double,double,double)'''
    ...
    def mirror (self, *args, **kwargs):
      '''
mirror( (Entity2d)arg1, (Line2d)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} mirror(class PyGeEntity2d {lvalue},class PyGeLine2d)'''
    ...
    def orthoBoundBlock (self, *args, **kwargs):
      '''
orthoBoundBlock( (Curve2d)arg1) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d orthoBoundBlock(class PyGeCurve2d {lvalue})

orthoBoundBlock( (Curve2d)arg1, (Interval)arg2) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d orthoBoundBlock(class PyGeCurve2d {lvalue},class PyGeInterval)'''
    ...
    def paramAtLength (self, *args, **kwargs):
      '''
paramAtLength( (Curve2d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double paramAtLength(class PyGeCurve2d {lvalue},double,double)

paramAtLength( (Curve2d)arg1, (float)arg2, (float)arg3, (bool)arg4, (float)arg5) -> float :

    C++ signature :
        double paramAtLength(class PyGeCurve2d {lvalue},double,double,bool,double)'''
    ...
    def paramOf (self, *args, **kwargs):
      '''
paramOf( (Curve2d)arg1, (Point2d)arg2) -> float :

    C++ signature :
        double paramOf(class PyGeCurve2d {lvalue},class AcGePoint2d)

paramOf( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double paramOf(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def reverseParam (self, *args, **kwargs):
      '''
reverseParam( (Curve2d)arg1) -> Curve2d :

    C++ signature :
        class PyGeCurve2d {lvalue} reverseParam(class PyGeCurve2d {lvalue})'''
    ...
    def rotateBy (self, *args, **kwargs):
      '''
rotateBy( (Entity2d)arg1, (float)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} rotateBy(class PyGeEntity2d {lvalue},double)

rotateBy( (Entity2d)arg1, (float)arg2, (Point2d)arg3) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} rotateBy(class PyGeEntity2d {lvalue},double,class AcGePoint2d)'''
    ...
    def scaleBy (self, *args, **kwargs):
      '''
scaleBy( (Entity2d)arg1, (float)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} scaleBy(class PyGeEntity2d {lvalue},double)

scaleBy( (Entity2d)arg1, (float)arg2, (Point2d)arg3) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} scaleBy(class PyGeEntity2d {lvalue},double,class AcGePoint2d)'''
    ...
    def setInterval (self, *args, **kwargs):
      '''
setInterval( (Curve2d)arg1) -> Curve2d :

    C++ signature :
        class PyGeCurve2d {lvalue} setInterval(class PyGeCurve2d {lvalue})

setInterval( (Curve2d)arg1, (Interval)arg2) -> bool :

    C++ signature :
        bool setInterval(class PyGeCurve2d {lvalue},class PyGeInterval)'''
    ...
    def transformBy (self, *args, **kwargs):
      '''
transformBy( (Entity2d)arg1, (Matrix2d)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} transformBy(class PyGeEntity2d {lvalue},class AcGeMatrix2d)'''
    ...
    def translateBy (self, *args, **kwargs):
      '''
translateBy( (Entity2d)arg1, (Vector2d)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} translateBy(class PyGeEntity2d {lvalue},class AcGeVector2d)'''
    ...
    def type (self, *args, **kwargs):
      '''
type( (Entity2d)arg1) -> EntityId :

    C++ signature :
        enum AcGe::EntityId type(class PyGeEntity2d {lvalue})'''
    ...

class Curve3d:
    def __eq__ (self, *args, **kwargs):
      '''
__eq__( (Entity3d)arg1, (Entity3d)arg2) -> bool :

    C++ signature :
        bool __eq__(class PyGeEntity3d {lvalue},class PyGeEntity3d)'''
    ...
    def __init__ (self, *args, **kwargs):
      '''Raises an exception
This class cannot be instantiated from Python
'''
    ...
    def __ne__ (self, *args, **kwargs):
      '''
__ne__( (Entity3d)arg1, (Entity3d)arg2) -> bool :

    C++ signature :
        bool __ne__(class PyGeEntity3d {lvalue},class PyGeEntity3d)'''
    ...
    def area (self, *args, **kwargs):
      '''
area( (Curve3d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double area(class PyGeCurve3d {lvalue},double,double)

area( (Curve3d)arg1, (float)arg2, (float)arg3, (Tol)arg4) -> float :

    C++ signature :
        double area(class PyGeCurve3d {lvalue},double,double,class AcGeTol)'''
    ...
    def boundBlock (self, *args, **kwargs):
      '''
boundBlock( (Curve3d)arg1) -> BoundBlock3d :

    C++ signature :
        class PyGeBoundBlock3d boundBlock(class PyGeCurve3d {lvalue})

boundBlock( (Curve3d)arg1, (Interval)arg2) -> BoundBlock3d :

    C++ signature :
        class PyGeBoundBlock3d boundBlock(class PyGeCurve3d {lvalue},class PyGeInterval)'''
    ...
    def className (self, *args, **kwargs):
      '''
className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def closestPointTo (self, *args, **kwargs):
      '''
closestPointTo( (Curve3d)arg1, (Point3d)arg2) -> Point3d :

    C++ signature :
        class AcGePoint3d closestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d)

closestPointTo( (Curve3d)arg1, (Point3d)arg2, (Tol)arg3) -> Point3d :

    C++ signature :
        class AcGePoint3d closestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeTol)

closestPointTo( (Curve3d)arg1, (Curve3d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointTo(class PyGeCurve3d {lvalue},class PyGeCurve3d)

closestPointTo( (Curve3d)arg1, (Curve3d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointTo(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeTol)'''
    ...
    def copy (self, *args, **kwargs):
      '''
copy( (Entity3d)arg1) -> Entity3d :

    C++ signature :
        class PyGeEntity3d copy(class PyGeEntity3d {lvalue})'''
    ...
    def distanceTo (self, *args, **kwargs):
      '''
distanceTo( (Curve3d)arg1, (Point3d)arg2) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve3d {lvalue},class AcGePoint3d)

distanceTo( (Curve3d)arg1, (Point3d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeTol)

distanceTo( (Curve3d)arg1, (Curve3d)arg2) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve3d {lvalue},class PyGeCurve3d)

distanceTo( (Curve3d)arg1, (Curve3d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeTol)'''
    ...
    def evalPoint (self, *args, **kwargs):
      '''
evalPoint( (Curve3d)arg1, (float)arg2) -> Point3d :

    C++ signature :
        class AcGePoint3d evalPoint(class PyGeCurve3d {lvalue},double)

evalPoint( (Curve3d)arg1, (float)arg2, (int)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple evalPoint(class PyGeCurve3d {lvalue},double,int)'''
    ...
    def explode (self, *args, **kwargs):
      '''
explode( (Curve3d)arg1) -> list :

    C++ signature :
        class boost::python::list explode(class PyGeCurve3d {lvalue})

explode( (Curve3d)arg1, (Interval)arg2) -> list :

    C++ signature :
        class boost::python::list explode(class PyGeCurve3d {lvalue},class PyGeInterval)'''
    ...
    def getClosestPointTo (self, *args, **kwargs):
      '''
getClosestPointTo( (Curve3d)arg1, (Point3d)arg2) -> PointOnCurve3d :

    C++ signature :
        class PyGePointOnCurve3d getClosestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d)

getClosestPointTo( (Curve3d)arg1, (Point3d)arg2, (Tol)arg3) -> PointOnCurve3d :

    C++ signature :
        class PyGePointOnCurve3d getClosestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def getClosestPointsTo (self, *args, **kwargs):
      '''
getClosestPointsTo( (Curve3d)arg1, (Curve3d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getClosestPointsTo(class PyGeCurve3d {lvalue},class PyGeCurve3d)

getClosestPointsTo( (Curve3d)arg1, (Curve3d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple getClosestPointsTo(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeTol)'''
    ...
    def getEndPoint (self, *args, **kwargs):
      '''
getEndPoint( (Curve3d)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d getEndPoint(class PyGeCurve3d {lvalue})'''
    ...
    def getInterval (self, *args, **kwargs):
      '''
getInterval( (Curve3d)arg1) -> Interval :

    C++ signature :
        class PyGeInterval getInterval(class PyGeCurve3d {lvalue})'''
    ...
    def getNormalPoint (self, *args, **kwargs):
      '''
getNormalPoint( (Curve3d)arg1, (Point3d)arg2) -> PointOnCurve3d :

    C++ signature :
        class PyGePointOnCurve3d getNormalPoint(class PyGeCurve3d {lvalue},class AcGePoint3d)

getNormalPoint( (Curve3d)arg1, (Point3d)arg2, (Tol)arg3) -> PointOnCurve3d :

    C++ signature :
        class PyGePointOnCurve3d getNormalPoint(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def getProjClosestPointTo (self, *args, **kwargs):
      '''
getProjClosestPointTo( (Curve3d)arg1, (Point3d)arg2, (Vector3d)arg3) -> PointOnCurve3d :

    C++ signature :
        class PyGePointOnCurve3d getProjClosestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeVector3d)

getProjClosestPointTo( (Curve3d)arg1, (Point3d)arg2, (Vector3d)arg3, (Tol)arg4) -> PointOnCurve3d :

    C++ signature :
        class PyGePointOnCurve3d getProjClosestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeVector3d,class AcGeTol)'''
    ...
    def getProjClosestPointsTo (self, *args, **kwargs):
      '''
getProjClosestPointsTo( (Curve3d)arg1, (Curve3d)arg2, (Vector3d)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple getProjClosestPointsTo(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeVector3d)

getProjClosestPointsTo( (Curve3d)arg1, (Curve3d)arg2, (Vector3d)arg3, (Tol)arg4) -> tuple :

    C++ signature :
        class boost::python::tuple getProjClosestPointsTo(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeVector3d,class AcGeTol)'''
    ...
    def getSamplePoints (self, *args, **kwargs):
      '''
getSamplePoints( (Curve3d)arg1, (int)arg2) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve3d {lvalue},int)

getSamplePoints( (Curve3d)arg1, (float)arg2, (float)arg3, (float)arg4) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve3d {lvalue},double,double,double)'''
    ...
    def getSplitCurves (self, *args, **kwargs):
      '''
getSplitCurves( (Curve3d)arg1, (float)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getSplitCurves(class PyGeCurve3d {lvalue},double)'''
    ...
    def getStartPoint (self, *args, **kwargs):
      '''
getStartPoint( (Curve3d)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d getStartPoint(class PyGeCurve3d {lvalue})'''
    ...
    def getTrimmedOffset (self, *args, **kwargs):
      '''
getTrimmedOffset( (Curve3d)arg1, (float)arg2, (Vector3d)arg3, (OffsetCrvExtType)arg4) -> list :

    C++ signature :
        class boost::python::list getTrimmedOffset(class PyGeCurve3d {lvalue},double,class AcGeVector3d,enum AcGe::OffsetCrvExtType)

getTrimmedOffset( (Curve3d)arg1, (float)arg2, (Vector3d)arg3, (OffsetCrvExtType)arg4, (Tol)arg5) -> list :

    C++ signature :
        class boost::python::list getTrimmedOffset(class PyGeCurve3d {lvalue},double,class AcGeVector3d,enum AcGe::OffsetCrvExtType,class AcGeTol)'''
    ...
    def hasEndPoint (self, *args, **kwargs):
      '''
hasEndPoint( (Curve3d)arg1) -> bool :

    C++ signature :
        bool hasEndPoint(class PyGeCurve3d {lvalue})'''
    ...
    def hasStartPoint (self, *args, **kwargs):
      '''
hasStartPoint( (Curve3d)arg1) -> bool :

    C++ signature :
        bool hasStartPoint(class PyGeCurve3d {lvalue})'''
    ...
    def isClosed (self, *args, **kwargs):
      '''
isClosed( (Curve3d)arg1) -> bool :

    C++ signature :
        bool isClosed(class PyGeCurve3d {lvalue})

isClosed( (Curve3d)arg1, (Tol)arg2) -> bool :

    C++ signature :
        bool isClosed(class PyGeCurve3d {lvalue},class AcGeTol)'''
    ...
    def isCoplanarWith (self, *args, **kwargs):
      '''
isCoplanarWith( (Curve3d)arg1, (Curve3d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isCoplanarWith(class PyGeCurve3d {lvalue},class PyGeCurve3d)

isCoplanarWith( (Curve3d)arg1, (Curve3d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple isCoplanarWith(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeTol)'''
    ...
    def isDegenerate (self, *args, **kwargs):
      '''
isDegenerate( (Curve3d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isDegenerate(class PyGeCurve3d {lvalue})

isDegenerate( (Curve3d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isDegenerate(class PyGeCurve3d {lvalue},class AcGeTol)'''
    ...
    def isEqualTo (self, *args, **kwargs):
      '''
isEqualTo( (Entity3d)arg1, (Entity3d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity3d {lvalue},class PyGeEntity3d,class AcGeTol)'''
    ...
    def isKindOf (self, *args, **kwargs):
      '''
isKindOf( (Entity3d)arg1, (EntityId)arg2) -> bool :

    C++ signature :
        bool isKindOf(class PyGeEntity3d {lvalue},enum AcGe::EntityId)'''
    ...
    def isLinear (self, *args, **kwargs):
      '''
isLinear( (Curve3d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isLinear(class PyGeCurve3d {lvalue})

isLinear( (Curve3d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isLinear(class PyGeCurve3d {lvalue},class AcGeTol)'''
    ...
    def isNull (self, *args, **kwargs):
      '''
isNull( (Entity3d)arg1) -> bool :

    C++ signature :
        bool isNull(class PyGeEntity3d {lvalue})'''
    ...
    def isOn (self, *args, **kwargs):
      '''
isOn( (Curve3d)arg1, (Point3d)arg2) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve3d {lvalue},class AcGePoint3d)

isOn( (Curve3d)arg1, (Point3d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeTol)

isOn( (Curve3d)arg1, (Point3d)arg2, (float)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve3d {lvalue},class AcGePoint3d,double {lvalue})

isOn( (Curve3d)arg1, (Point3d)arg2, (float)arg3, (Tol)arg4) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve3d {lvalue},class AcGePoint3d,double {lvalue},class AcGeTol)

isOn( (Curve3d)arg1, (float)arg2) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve3d {lvalue},double)

isOn( (Curve3d)arg1, (float)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve3d {lvalue},double,class AcGeTol)'''
    ...
    def isPeriodic (self, *args, **kwargs):
      '''
isPeriodic( (Curve3d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isPeriodic(class PyGeCurve3d {lvalue})'''
    ...
    def isPlanar (self, *args, **kwargs):
      '''
isPlanar( (Curve3d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isPlanar(class PyGeCurve3d {lvalue})

isPlanar( (Curve3d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isPlanar(class PyGeCurve3d {lvalue},class AcGeTol)'''
    ...
    def length (self, *args, **kwargs):
      '''
length( (Curve3d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double length(class PyGeCurve3d {lvalue},double,double)

length( (Curve3d)arg1, (float)arg2, (float)arg3, (float)arg4) -> float :

    C++ signature :
        double length(class PyGeCurve3d {lvalue},double,double,double)'''
    ...
    def mirror (self, *args, **kwargs):
      '''
mirror( (Entity3d)arg1, (Plane)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} mirror(class PyGeEntity3d {lvalue},class PyGePlane)'''
    ...
    def orthoBoundBlock (self, *args, **kwargs):
      '''
orthoBoundBlock( (Curve3d)arg1) -> BoundBlock3d :

    C++ signature :
        class PyGeBoundBlock3d orthoBoundBlock(class PyGeCurve3d {lvalue})

orthoBoundBlock( (Curve3d)arg1, (Interval)arg2) -> BoundBlock3d :

    C++ signature :
        class PyGeBoundBlock3d orthoBoundBlock(class PyGeCurve3d {lvalue},class PyGeInterval)'''
    ...
    def orthoProject (self, *args, **kwargs):
      '''
orthoProject( (Curve3d)arg1, (Plane)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d orthoProject(class PyGeCurve3d {lvalue},class PyGePlane)

orthoProject( (Curve3d)arg1, (Plane)arg2, (Tol)arg3) -> Entity3d :

    C++ signature :
        class PyGeEntity3d orthoProject(class PyGeCurve3d {lvalue},class PyGePlane,class AcGeTol)'''
    ...
    def paramAtLength (self, *args, **kwargs):
      '''
paramAtLength( (Curve3d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double paramAtLength(class PyGeCurve3d {lvalue},double,double)

paramAtLength( (Curve3d)arg1, (float)arg2, (float)arg3, (bool)arg4, (float)arg5) -> float :

    C++ signature :
        double paramAtLength(class PyGeCurve3d {lvalue},double,double,bool,double)'''
    ...
    def paramOf (self, *args, **kwargs):
      '''
paramOf( (Curve3d)arg1, (Point3d)arg2) -> float :

    C++ signature :
        double paramOf(class PyGeCurve3d {lvalue},class AcGePoint3d)

paramOf( (Curve3d)arg1, (Point3d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double paramOf(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def projClosestPointTo (self, *args, **kwargs):
      '''
projClosestPointTo( (Curve3d)arg1, (Point3d)arg2, (Vector3d)arg3) -> Point3d :

    C++ signature :
        class AcGePoint3d projClosestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeVector3d)

projClosestPointTo( (Curve3d)arg1, (Point3d)arg2, (Vector3d)arg3, (Tol)arg4) -> Point3d :

    C++ signature :
        class AcGePoint3d projClosestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeVector3d,class AcGeTol)'''
    ...
    def projClosestPointsTo (self, *args, **kwargs):
      '''
projClosestPointsTo( (Curve3d)arg1, (Curve3d)arg2, (Vector3d)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple projClosestPointsTo(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeVector3d)

projClosestPointsTo( (Curve3d)arg1, (Curve3d)arg2, (Vector3d)arg3, (Tol)arg4) -> tuple :

    C++ signature :
        class boost::python::tuple projClosestPointsTo(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeVector3d,class AcGeTol)'''
    ...
    def project (self, *args, **kwargs):
      '''
project( (Curve3d)arg1, (Plane)arg2, (Vector3d)arg3) -> Entity3d :

    C++ signature :
        class PyGeEntity3d project(class PyGeCurve3d {lvalue},class PyGePlane,class AcGeVector3d)

project( (Curve3d)arg1, (Plane)arg2, (Vector3d)arg3, (Tol)arg4) -> Entity3d :

    C++ signature :
        class PyGeEntity3d project(class PyGeCurve3d {lvalue},class PyGePlane,class AcGeVector3d,class AcGeTol)'''
    ...
    def reverseParam (self, *args, **kwargs):
      '''
reverseParam( (Curve3d)arg1) -> Curve3d :

    C++ signature :
        class PyGeCurve3d {lvalue} reverseParam(class PyGeCurve3d {lvalue})'''
    ...
    def rotateBy (self, *args, **kwargs):
      '''
rotateBy( (Entity3d)arg1, (float)arg2, (Vector3d)arg3) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} rotateBy(class PyGeEntity3d {lvalue},double,class AcGeVector3d)

rotateBy( (Entity3d)arg1, (float)arg2, (Vector3d)arg3, (Point3d)arg4) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} rotateBy(class PyGeEntity3d {lvalue},double,class AcGeVector3d,class AcGePoint3d)'''
    ...
    def scaleBy (self, *args, **kwargs):
      '''
scaleBy( (Entity3d)arg1, (float)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} scaleBy(class PyGeEntity3d {lvalue},double)

scaleBy( (Entity3d)arg1, (float)arg2, (Point3d)arg3) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} scaleBy(class PyGeEntity3d {lvalue},double,class AcGePoint3d)'''
    ...
    def setInterval (self, *args, **kwargs):
      '''
setInterval( (Curve3d)arg1) -> Curve3d :

    C++ signature :
        class PyGeCurve3d {lvalue} setInterval(class PyGeCurve3d {lvalue})

setInterval( (Curve3d)arg1, (Interval)arg2) -> bool :

    C++ signature :
        bool setInterval(class PyGeCurve3d {lvalue},class PyGeInterval)'''
    ...
    def transformBy (self, *args, **kwargs):
      '''
transformBy( (Entity3d)arg1, (Matrix3d)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} transformBy(class PyGeEntity3d {lvalue},class AcGeMatrix3d)'''
    ...
    def translateBy (self, *args, **kwargs):
      '''
translateBy( (Entity3d)arg1, (Vector3d)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} translateBy(class PyGeEntity3d {lvalue},class AcGeVector3d)'''
    ...
    def type (self, *args, **kwargs):
      '''
type( (Entity3d)arg1) -> EntityId :

    C++ signature :
        enum AcGe::EntityId type(class PyGeEntity3d {lvalue})'''
    ...

class CurveCurveInt2d:
    def __eq__ (self, *args, **kwargs):
      '''
__eq__( (Entity2d)arg1, (Entity2d)arg2) -> bool :

    C++ signature :
        bool __eq__(class PyGeEntity2d {lvalue},class PyGeEntity2d)'''
    ...
    def __init__ (self, *args, **kwargs):
      '''
__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1, (object)arg2, (object)arg3) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class AcGeCurve2d,class AcGeCurve2d)

__init__( (object)arg1, (object)arg2, (object)arg3, (Tol)arg4) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class AcGeCurve2d,class AcGeCurve2d,class AcGeTol)

__init__( (object)arg1, (object)arg2, (object)arg3, (Interval)arg4, (Interval)arg5) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class AcGeCurve2d,class AcGeCurve2d,class PyGeInterval,class PyGeInterval)

__init__( (object)arg1, (object)arg2, (object)arg3, (Interval)arg4, (Interval)arg5, (Tol)arg6) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class AcGeCurve2d,class AcGeCurve2d,class PyGeInterval,class PyGeInterval,class AcGeTol)'''
    ...
    def __ne__ (self, *args, **kwargs):
      '''
__ne__( (Entity2d)arg1, (Entity2d)arg2) -> bool :

    C++ signature :
        bool __ne__(class PyGeEntity2d {lvalue},class PyGeEntity2d)'''
    ...
    def className (self, *args, **kwargs):
      '''
className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def copy (self, *args, **kwargs):
      '''
copy( (Entity2d)arg1) -> Entity2d :

    C++ signature :
        class PyGeEntity2d copy(class PyGeEntity2d {lvalue})'''
    ...
    def isEqualTo (self, *args, **kwargs):
      '''
isEqualTo( (Entity2d)arg1, (Entity2d)arg2) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity2d {lvalue},class PyGeEntity2d)

isEqualTo( (Entity2d)arg1, (Entity2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity2d {lvalue},class PyGeEntity2d,class AcGeTol)'''
    ...
    def isKindOf (self, *args, **kwargs):
      '''
isKindOf( (Entity2d)arg1, (EntityId)arg2) -> bool :

    C++ signature :
        bool isKindOf(class PyGeEntity2d {lvalue},enum AcGe::EntityId)'''
    ...
    def isNull (self, *args, **kwargs):
      '''
isNull( (Entity2d)arg1) -> bool :

    C++ signature :
        bool isNull(class PyGeEntity2d {lvalue})'''
    ...
    def isOn (self, *args, **kwargs):
      '''
isOn( (Entity2d)arg1, (Point2d)arg2) -> bool :

    C++ signature :
        bool isOn(class PyGeEntity2d {lvalue},class AcGePoint2d)

isOn( (Entity2d)arg1, (Point2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeEntity2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def mirror (self, *args, **kwargs):
      '''
mirror( (Entity2d)arg1, (Line2d)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} mirror(class PyGeEntity2d {lvalue},class PyGeLine2d)'''
    ...
    def rotateBy (self, *args, **kwargs):
      '''
rotateBy( (Entity2d)arg1, (float)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} rotateBy(class PyGeEntity2d {lvalue},double)

rotateBy( (Entity2d)arg1, (float)arg2, (Point2d)arg3) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} rotateBy(class PyGeEntity2d {lvalue},double,class AcGePoint2d)'''
    ...
    def scaleBy (self, *args, **kwargs):
      '''
scaleBy( (Entity2d)arg1, (float)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} scaleBy(class PyGeEntity2d {lvalue},double)

scaleBy( (Entity2d)arg1, (float)arg2, (Point2d)arg3) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} scaleBy(class PyGeEntity2d {lvalue},double,class AcGePoint2d)'''
    ...
    def transformBy (self, *args, **kwargs):
      '''
transformBy( (Entity2d)arg1, (Matrix2d)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} transformBy(class PyGeEntity2d {lvalue},class AcGeMatrix2d)'''
    ...
    def translateBy (self, *args, **kwargs):
      '''
translateBy( (Entity2d)arg1, (Vector2d)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} translateBy(class PyGeEntity2d {lvalue},class AcGeVector2d)'''
    ...
    def type (self, *args, **kwargs):
      '''
type( (Entity2d)arg1) -> EntityId :

    C++ signature :
        enum AcGe::EntityId type(class PyGeEntity2d {lvalue})'''
    ...

class CurveCurveInt3d:
    def __eq__ (self, *args, **kwargs):
      '''
__eq__( (Entity3d)arg1, (Entity3d)arg2) -> bool :

    C++ signature :
        bool __eq__(class PyGeEntity3d {lvalue},class PyGeEntity3d)'''
    ...
    def __init__ (self, *args, **kwargs):
      '''
__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
    ...
    def __ne__ (self, *args, **kwargs):
      '''
__ne__( (Entity3d)arg1, (Entity3d)arg2) -> bool :

    C++ signature :
        bool __ne__(class PyGeEntity3d {lvalue},class PyGeEntity3d)'''
    ...
    def className (self, *args, **kwargs):
      '''
className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def copy (self, *args, **kwargs):
      '''
copy( (Entity3d)arg1) -> Entity3d :

    C++ signature :
        class PyGeEntity3d copy(class PyGeEntity3d {lvalue})'''
    ...
    def isEqualTo (self, *args, **kwargs):
      '''
isEqualTo( (Entity3d)arg1, (Entity3d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity3d {lvalue},class PyGeEntity3d,class AcGeTol)'''
    ...
    def isKindOf (self, *args, **kwargs):
      '''
isKindOf( (Entity3d)arg1, (EntityId)arg2) -> bool :

    C++ signature :
        bool isKindOf(class PyGeEntity3d {lvalue},enum AcGe::EntityId)'''
    ...
    def isNull (self, *args, **kwargs):
      '''
isNull( (Entity3d)arg1) -> bool :

    C++ signature :
        bool isNull(class PyGeEntity3d {lvalue})'''
    ...
    def isOn (self, *args, **kwargs):
      '''
isOn( (Entity3d)arg1, (Point3d)arg2) -> bool :

    C++ signature :
        bool isOn(class PyGeEntity3d {lvalue},class AcGePoint3d)

isOn( (Entity3d)arg1, (Point3d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeEntity3d {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def mirror (self, *args, **kwargs):
      '''
mirror( (Entity3d)arg1, (Plane)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} mirror(class PyGeEntity3d {lvalue},class PyGePlane)'''
    ...
    def rotateBy (self, *args, **kwargs):
      '''
rotateBy( (Entity3d)arg1, (float)arg2, (Vector3d)arg3) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} rotateBy(class PyGeEntity3d {lvalue},double,class AcGeVector3d)

rotateBy( (Entity3d)arg1, (float)arg2, (Vector3d)arg3, (Point3d)arg4) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} rotateBy(class PyGeEntity3d {lvalue},double,class AcGeVector3d,class AcGePoint3d)'''
    ...
    def scaleBy (self, *args, **kwargs):
      '''
scaleBy( (Entity3d)arg1, (float)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} scaleBy(class PyGeEntity3d {lvalue},double)

scaleBy( (Entity3d)arg1, (float)arg2, (Point3d)arg3) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} scaleBy(class PyGeEntity3d {lvalue},double,class AcGePoint3d)'''
    ...
    def transformBy (self, *args, **kwargs):
      '''
transformBy( (Entity3d)arg1, (Matrix3d)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} transformBy(class PyGeEntity3d {lvalue},class AcGeMatrix3d)'''
    ...
    def translateBy (self, *args, **kwargs):
      '''
translateBy( (Entity3d)arg1, (Vector3d)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} translateBy(class PyGeEntity3d {lvalue},class AcGeVector3d)'''
    ...
    def type (self, *args, **kwargs):
      '''
type( (Entity3d)arg1) -> EntityId :

    C++ signature :
        enum AcGe::EntityId type(class PyGeEntity3d {lvalue})'''
    ...

class CurveSurfInt:
    def __eq__ (self, *args, **kwargs):
      '''
__eq__( (Entity3d)arg1, (Entity3d)arg2) -> bool :

    C++ signature :
        bool __eq__(class PyGeEntity3d {lvalue},class PyGeEntity3d)'''
    ...
    def __init__ (self, *args, **kwargs):
      '''Raises an exception
This class cannot be instantiated from Python
'''
    ...
    def __ne__ (self, *args, **kwargs):
      '''
__ne__( (Entity3d)arg1, (Entity3d)arg2) -> bool :

    C++ signature :
        bool __ne__(class PyGeEntity3d {lvalue},class PyGeEntity3d)'''
    ...
    def className (self, *args, **kwargs):
      '''
className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def copy (self, *args, **kwargs):
      '''
copy( (Entity3d)arg1) -> Entity3d :

    C++ signature :
        class PyGeEntity3d copy(class PyGeEntity3d {lvalue})'''
    ...
    def isEqualTo (self, *args, **kwargs):
      '''
isEqualTo( (Entity3d)arg1, (Entity3d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity3d {lvalue},class PyGeEntity3d,class AcGeTol)'''
    ...
    def isKindOf (self, *args, **kwargs):
      '''
isKindOf( (Entity3d)arg1, (EntityId)arg2) -> bool :

    C++ signature :
        bool isKindOf(class PyGeEntity3d {lvalue},enum AcGe::EntityId)'''
    ...
    def isNull (self, *args, **kwargs):
      '''
isNull( (Entity3d)arg1) -> bool :

    C++ signature :
        bool isNull(class PyGeEntity3d {lvalue})'''
    ...
    def isOn (self, *args, **kwargs):
      '''
isOn( (Entity3d)arg1, (Point3d)arg2) -> bool :

    C++ signature :
        bool isOn(class PyGeEntity3d {lvalue},class AcGePoint3d)

isOn( (Entity3d)arg1, (Point3d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeEntity3d {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def mirror (self, *args, **kwargs):
      '''
mirror( (Entity3d)arg1, (Plane)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} mirror(class PyGeEntity3d {lvalue},class PyGePlane)'''
    ...
    def rotateBy (self, *args, **kwargs):
      '''
rotateBy( (Entity3d)arg1, (float)arg2, (Vector3d)arg3) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} rotateBy(class PyGeEntity3d {lvalue},double,class AcGeVector3d)

rotateBy( (Entity3d)arg1, (float)arg2, (Vector3d)arg3, (Point3d)arg4) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} rotateBy(class PyGeEntity3d {lvalue},double,class AcGeVector3d,class AcGePoint3d)'''
    ...
    def scaleBy (self, *args, **kwargs):
      '''
scaleBy( (Entity3d)arg1, (float)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} scaleBy(class PyGeEntity3d {lvalue},double)

scaleBy( (Entity3d)arg1, (float)arg2, (Point3d)arg3) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} scaleBy(class PyGeEntity3d {lvalue},double,class AcGePoint3d)'''
    ...
    def transformBy (self, *args, **kwargs):
      '''
transformBy( (Entity3d)arg1, (Matrix3d)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} transformBy(class PyGeEntity3d {lvalue},class AcGeMatrix3d)'''
    ...
    def translateBy (self, *args, **kwargs):
      '''
translateBy( (Entity3d)arg1, (Vector3d)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} translateBy(class PyGeEntity3d {lvalue},class AcGeVector3d)'''
    ...
    def type (self, *args, **kwargs):
      '''
type( (Entity3d)arg1) -> EntityId :

    C++ signature :
        enum AcGe::EntityId type(class PyGeEntity3d {lvalue})'''
    ...

class EllipArc2d:
    def __eq__ (self, *args, **kwargs):
      '''
__eq__( (Entity2d)arg1, (Entity2d)arg2) -> bool :

    C++ signature :
        bool __eq__(class PyGeEntity2d {lvalue},class PyGeEntity2d)'''
    ...
    def __init__ (self, *args, **kwargs):
      '''
__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1, (CircArc2d)arg2) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class PyGeCircArc2d)

__init__( (object)arg1, (Point2d)arg2, (Vector2d)arg3, (Vector2d)arg4, (float)arg5, (float)arg6) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class AcGePoint2d,class AcGeVector2d,class AcGeVector2d,double,double)

__init__( (object)arg1, (Point2d)arg2, (Vector2d)arg3, (Vector2d)arg4, (float)arg5, (float)arg6, (float)arg7, (float)arg8) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class AcGePoint2d,class AcGeVector2d,class AcGeVector2d,double,double,double,double)'''
    ...
    def __ne__ (self, *args, **kwargs):
      '''
__ne__( (Entity2d)arg1, (Entity2d)arg2) -> bool :

    C++ signature :
        bool __ne__(class PyGeEntity2d {lvalue},class PyGeEntity2d)'''
    ...
    def area (self, *args, **kwargs):
      '''
area( (Curve2d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double area(class PyGeCurve2d {lvalue},double,double)

area( (Curve2d)arg1, (float)arg2, (float)arg3, (Tol)arg4) -> float :

    C++ signature :
        double area(class PyGeCurve2d {lvalue},double,double,class AcGeTol)'''
    ...
    def boundBlock (self, *args, **kwargs):
      '''
boundBlock( (Curve2d)arg1) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d boundBlock(class PyGeCurve2d {lvalue})

boundBlock( (Curve2d)arg1, (Interval)arg2) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d boundBlock(class PyGeCurve2d {lvalue},class PyGeInterval)'''
    ...
    def center (self, *args, **kwargs):
      '''
center( (EllipArc2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d center(class PyGeEllipArc2d {lvalue})'''
    ...
    def className (self, *args, **kwargs):
      '''
className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def closestPointTo (self, *args, **kwargs):
      '''
closestPointTo( (Curve2d)arg1, (Point2d)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d closestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d)

closestPointTo( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> Point2d :

    C++ signature :
        class AcGePoint2d closestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)

closestPointTo( (Curve2d)arg1, (Curve2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointTo(class PyGeCurve2d {lvalue},class PyGeCurve2d)

closestPointTo( (Curve2d)arg1, (Curve2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointTo(class PyGeCurve2d {lvalue},class PyGeCurve2d,class AcGeTol)'''
    ...
    def copy (self, *args, **kwargs):
      '''
copy( (Entity2d)arg1) -> Entity2d :

    C++ signature :
        class PyGeEntity2d copy(class PyGeEntity2d {lvalue})'''
    ...
    def distanceTo (self, *args, **kwargs):
      '''
distanceTo( (Curve2d)arg1, (Point2d)arg2) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class AcGePoint2d)

distanceTo( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)

distanceTo( (Curve2d)arg1, (Curve2d)arg2) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class PyGeCurve2d)

distanceTo( (Curve2d)arg1, (Curve2d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class PyGeCurve2d,class AcGeTol)'''
    ...
    def endAng (self, *args, **kwargs):
      '''
endAng( (EllipArc2d)arg1) -> float :

    C++ signature :
        double endAng(class PyGeEllipArc2d {lvalue})'''
    ...
    def endPoint (self, *args, **kwargs):
      '''
endPoint( (EllipArc2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d endPoint(class PyGeEllipArc2d {lvalue})'''
    ...
    def evalPoint (self, *args, **kwargs):
      '''
evalPoint( (Curve2d)arg1, (float)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d evalPoint(class PyGeCurve2d {lvalue},double)

evalPoint( (Curve2d)arg1, (float)arg2, (int)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple evalPoint(class PyGeCurve2d {lvalue},double,int)'''
    ...
    def explode (self, *args, **kwargs):
      '''
explode( (Curve2d)arg1) -> list :

    C++ signature :
        class boost::python::list explode(class PyGeCurve2d {lvalue})

explode( (Curve2d)arg1, (Interval)arg2) -> list :

    C++ signature :
        class boost::python::list explode(class PyGeCurve2d {lvalue},class PyGeInterval)'''
    ...
    def getClosestPointTo (self, *args, **kwargs):
      '''
getClosestPointTo( (Curve2d)arg1, (Point2d)arg2) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getClosestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d)

getClosestPointTo( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getClosestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def getClosestPointsTo (self, *args, **kwargs):
      '''
getClosestPointsTo( (Curve2d)arg1, (Curve2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getClosestPointsTo(class PyGeCurve2d {lvalue},class PyGeCurve2d)

getClosestPointsTo( (Curve2d)arg1, (Curve2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple getClosestPointsTo(class PyGeCurve2d {lvalue},class PyGeCurve2d,class AcGeTol)'''
    ...
    def getEndPoint (self, *args, **kwargs):
      '''
getEndPoint( (Curve2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d getEndPoint(class PyGeCurve2d {lvalue})'''
    ...
    def getInterval (self, *args, **kwargs):
      '''
getInterval( (Curve2d)arg1) -> Interval :

    C++ signature :
        class PyGeInterval getInterval(class PyGeCurve2d {lvalue})'''
    ...
    def getNormalPoint (self, *args, **kwargs):
      '''
getNormalPoint( (Curve2d)arg1, (Point2d)arg2) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getNormalPoint(class PyGeCurve2d {lvalue},class AcGePoint2d)

getNormalPoint( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getNormalPoint(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def getSamplePoints (self, *args, **kwargs):
      '''
getSamplePoints( (Curve2d)arg1, (int)arg2) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve2d {lvalue},int)

getSamplePoints( (Curve2d)arg1, (float)arg2, (float)arg3, (float)arg4) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve2d {lvalue},double,double,double)'''
    ...
    def getSplitCurves (self, *args, **kwargs):
      '''
getSplitCurves( (Curve2d)arg1, (float)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getSplitCurves(class PyGeCurve2d {lvalue},double)'''
    ...
    def getStartPoint (self, *args, **kwargs):
      '''
getStartPoint( (Curve2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d getStartPoint(class PyGeCurve2d {lvalue})'''
    ...
    def getTrimmedOffset (self, *args, **kwargs):
      '''
getTrimmedOffset( (Curve2d)arg1, (float)arg2, (OffsetCrvExtType)arg3) -> list :

    C++ signature :
        class boost::python::list getTrimmedOffset(class PyGeCurve2d {lvalue},double,enum AcGe::OffsetCrvExtType)

getTrimmedOffset( (Curve2d)arg1, (float)arg2, (OffsetCrvExtType)arg3, (Tol)arg4) -> list :

    C++ signature :
        class boost::python::list getTrimmedOffset(class PyGeCurve2d {lvalue},double,enum AcGe::OffsetCrvExtType,class AcGeTol)'''
    ...
    def hasEndPoint (self, *args, **kwargs):
      '''
hasEndPoint( (Curve2d)arg1) -> bool :

    C++ signature :
        bool hasEndPoint(class PyGeCurve2d {lvalue})'''
    ...
    def hasStartPoint (self, *args, **kwargs):
      '''
hasStartPoint( (Curve2d)arg1) -> bool :

    C++ signature :
        bool hasStartPoint(class PyGeCurve2d {lvalue})'''
    ...
    def intersectWith (self, *args, **kwargs):
      '''
intersectWith( (EllipArc2d)arg1, (LinearEnt2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple intersectWith(class PyGeEllipArc2d {lvalue},class PyGeLinearEnt2d)

intersectWith( (EllipArc2d)arg1, (LinearEnt2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple intersectWith(class PyGeEllipArc2d {lvalue},class PyGeLinearEnt2d,class AcGeTol)'''
    ...
    def isCircular (self, *args, **kwargs):
      '''
isCircular( (EllipArc2d)arg1) -> bool :

    C++ signature :
        bool isCircular(class PyGeEllipArc2d {lvalue})

isCircular( (EllipArc2d)arg1, (Tol)arg2) -> bool :

    C++ signature :
        bool isCircular(class PyGeEllipArc2d {lvalue},class AcGeTol)'''
    ...
    def isClockWise (self, *args, **kwargs):
      '''
isClockWise( (EllipArc2d)arg1) -> bool :

    C++ signature :
        bool isClockWise(class PyGeEllipArc2d {lvalue})'''
    ...
    def isClosed (self, *args, **kwargs):
      '''
isClosed( (Curve2d)arg1) -> bool :

    C++ signature :
        bool isClosed(class PyGeCurve2d {lvalue})

isClosed( (Curve2d)arg1, (Tol)arg2) -> bool :

    C++ signature :
        bool isClosed(class PyGeCurve2d {lvalue},class AcGeTol)'''
    ...
    def isDegenerate (self, *args, **kwargs):
      '''
isDegenerate( (Curve2d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isDegenerate(class PyGeCurve2d {lvalue})

isDegenerate( (Curve2d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isDegenerate(class PyGeCurve2d {lvalue},class AcGeTol)'''
    ...
    def isEqualTo (self, *args, **kwargs):
      '''
isEqualTo( (Entity2d)arg1, (Entity2d)arg2) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity2d {lvalue},class PyGeEntity2d)

isEqualTo( (Entity2d)arg1, (Entity2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity2d {lvalue},class PyGeEntity2d,class AcGeTol)'''
    ...
    def isInside (self, *args, **kwargs):
      '''
isInside( (EllipArc2d)arg1, (Point2d)arg2) -> bool :

    C++ signature :
        bool isInside(class PyGeEllipArc2d {lvalue},class AcGePoint2d)

isInside( (EllipArc2d)arg1, (Point2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isInside(class PyGeEllipArc2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def isKindOf (self, *args, **kwargs):
      '''
isKindOf( (Entity2d)arg1, (EntityId)arg2) -> bool :

    C++ signature :
        bool isKindOf(class PyGeEntity2d {lvalue},enum AcGe::EntityId)'''
    ...
    def isLinear (self, *args, **kwargs):
      '''
isLinear( (Curve2d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isLinear(class PyGeCurve2d {lvalue})

isLinear( (Curve2d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isLinear(class PyGeCurve2d {lvalue},class AcGeTol)'''
    ...
    def isNull (self, *args, **kwargs):
      '''
isNull( (Entity2d)arg1) -> bool :

    C++ signature :
        bool isNull(class PyGeEntity2d {lvalue})'''
    ...
    def isOn (self, *args, **kwargs):
      '''
isOn( (Curve2d)arg1, (Point2d)arg2) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve2d {lvalue},class AcGePoint2d)

isOn( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)

isOn( (Curve2d)arg1, (Point2d)arg2, (float)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve2d {lvalue},class AcGePoint2d,double {lvalue})

isOn( (Curve2d)arg1, (Point2d)arg2, (float)arg3, (Tol)arg4) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve2d {lvalue},class AcGePoint2d,double {lvalue},class AcGeTol)

isOn( (Curve2d)arg1, (float)arg2) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve2d {lvalue},double)

isOn( (Curve2d)arg1, (float)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve2d {lvalue},double,class AcGeTol)'''
    ...
    def isPeriodic (self, *args, **kwargs):
      '''
isPeriodic( (Curve2d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isPeriodic(class PyGeCurve2d {lvalue})'''
    ...
    def length (self, *args, **kwargs):
      '''
length( (Curve2d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double length(class PyGeCurve2d {lvalue},double,double)

length( (Curve2d)arg1, (float)arg2, (float)arg3, (float)arg4) -> float :

    C++ signature :
        double length(class PyGeCurve2d {lvalue},double,double,double)'''
    ...
    def majorAxis (self, *args, **kwargs):
      '''
majorAxis( (EllipArc2d)arg1) -> Vector2d :

    C++ signature :
        class AcGeVector2d majorAxis(class PyGeEllipArc2d {lvalue})'''
    ...
    def majorRadius (self, *args, **kwargs):
      '''
majorRadius( (EllipArc2d)arg1) -> float :

    C++ signature :
        double majorRadius(class PyGeEllipArc2d {lvalue})'''
    ...
    def minorAxis (self, *args, **kwargs):
      '''
minorAxis( (EllipArc2d)arg1) -> Vector2d :

    C++ signature :
        class AcGeVector2d minorAxis(class PyGeEllipArc2d {lvalue})'''
    ...
    def minorRadius (self, *args, **kwargs):
      '''
minorRadius( (EllipArc2d)arg1) -> float :

    C++ signature :
        double minorRadius(class PyGeEllipArc2d {lvalue})'''
    ...
    def mirror (self, *args, **kwargs):
      '''
mirror( (Entity2d)arg1, (Line2d)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} mirror(class PyGeEntity2d {lvalue},class PyGeLine2d)'''
    ...
    def orthoBoundBlock (self, *args, **kwargs):
      '''
orthoBoundBlock( (Curve2d)arg1) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d orthoBoundBlock(class PyGeCurve2d {lvalue})

orthoBoundBlock( (Curve2d)arg1, (Interval)arg2) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d orthoBoundBlock(class PyGeCurve2d {lvalue},class PyGeInterval)'''
    ...
    def paramAtLength (self, *args, **kwargs):
      '''
paramAtLength( (Curve2d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double paramAtLength(class PyGeCurve2d {lvalue},double,double)

paramAtLength( (Curve2d)arg1, (float)arg2, (float)arg3, (bool)arg4, (float)arg5) -> float :

    C++ signature :
        double paramAtLength(class PyGeCurve2d {lvalue},double,double,bool,double)'''
    ...
    def paramOf (self, *args, **kwargs):
      '''
paramOf( (Curve2d)arg1, (Point2d)arg2) -> float :

    C++ signature :
        double paramOf(class PyGeCurve2d {lvalue},class AcGePoint2d)

paramOf( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double paramOf(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def reverseParam (self, *args, **kwargs):
      '''
reverseParam( (Curve2d)arg1) -> Curve2d :

    C++ signature :
        class PyGeCurve2d {lvalue} reverseParam(class PyGeCurve2d {lvalue})'''
    ...
    def rotateBy (self, *args, **kwargs):
      '''
rotateBy( (Entity2d)arg1, (float)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} rotateBy(class PyGeEntity2d {lvalue},double)

rotateBy( (Entity2d)arg1, (float)arg2, (Point2d)arg3) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} rotateBy(class PyGeEntity2d {lvalue},double,class AcGePoint2d)'''
    ...
    def scaleBy (self, *args, **kwargs):
      '''
scaleBy( (Entity2d)arg1, (float)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} scaleBy(class PyGeEntity2d {lvalue},double)

scaleBy( (Entity2d)arg1, (float)arg2, (Point2d)arg3) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} scaleBy(class PyGeEntity2d {lvalue},double,class AcGePoint2d)'''
    ...
    def set (self, *args, **kwargs):
      '''
set( (EllipArc2d)arg1, (Point2d)arg2, (Vector2d)arg3, (Vector2d)arg4, (float)arg5, (float)arg6) -> EllipArc2d :

    C++ signature :
        class PyGeEllipArc2d {lvalue} set(class PyGeEllipArc2d {lvalue},class AcGePoint2d,class AcGeVector2d,class AcGeVector2d,double,double)

set( (EllipArc2d)arg1, (Point2d)arg2, (Vector2d)arg3, (Vector2d)arg4, (float)arg5, (float)arg6, (float)arg7, (float)arg8) -> EllipArc2d :

    C++ signature :
        class PyGeEllipArc2d {lvalue} set(class PyGeEllipArc2d {lvalue},class AcGePoint2d,class AcGeVector2d,class AcGeVector2d,double,double,double,double)

set( (EllipArc2d)arg1, (CircArc2d)arg2) -> EllipArc2d :

    C++ signature :
        class PyGeEllipArc2d {lvalue} set(class PyGeEllipArc2d {lvalue},class PyGeCircArc2d)'''
    ...
    def setAngles (self, *args, **kwargs):
      '''
setAngles( (EllipArc2d)arg1, (float)arg2, (float)arg3) -> EllipArc2d :

    C++ signature :
        class PyGeEllipArc2d {lvalue} setAngles(class PyGeEllipArc2d {lvalue},double,double)'''
    ...
    def setAxes (self, *args, **kwargs):
      '''
setAxes( (EllipArc2d)arg1, (Vector2d)arg2, (Vector2d)arg3) -> EllipArc2d :

    C++ signature :
        class PyGeEllipArc2d {lvalue} setAxes(class PyGeEllipArc2d {lvalue},class AcGeVector2d,class AcGeVector2d)'''
    ...
    def setCenter (self, *args, **kwargs):
      '''
setCenter( (EllipArc2d)arg1, (Point2d)arg2) -> EllipArc2d :

    C++ signature :
        class PyGeEllipArc2d {lvalue} setCenter(class PyGeEllipArc2d {lvalue},class AcGePoint2d)'''
    ...
    def setInterval (self, *args, **kwargs):
      '''
setInterval( (Curve2d)arg1) -> Curve2d :

    C++ signature :
        class PyGeCurve2d {lvalue} setInterval(class PyGeCurve2d {lvalue})

setInterval( (Curve2d)arg1, (Interval)arg2) -> bool :

    C++ signature :
        bool setInterval(class PyGeCurve2d {lvalue},class PyGeInterval)'''
    ...
    def setMajorRadius (self, *args, **kwargs):
      '''
setMajorRadius( (EllipArc2d)arg1, (float)arg2) -> EllipArc2d :

    C++ signature :
        class PyGeEllipArc2d {lvalue} setMajorRadius(class PyGeEllipArc2d {lvalue},double)'''
    ...
    def setMinorRadius (self, *args, **kwargs):
      '''
setMinorRadius( (EllipArc2d)arg1, (float)arg2) -> EllipArc2d :

    C++ signature :
        class PyGeEllipArc2d {lvalue} setMinorRadius(class PyGeEllipArc2d {lvalue},double)'''
    ...
    def startAng (self, *args, **kwargs):
      '''
startAng( (EllipArc2d)arg1) -> float :

    C++ signature :
        double startAng(class PyGeEllipArc2d {lvalue})'''
    ...
    def startPoint (self, *args, **kwargs):
      '''
startPoint( (EllipArc2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d startPoint(class PyGeEllipArc2d {lvalue})'''
    ...
    def transformBy (self, *args, **kwargs):
      '''
transformBy( (Entity2d)arg1, (Matrix2d)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} transformBy(class PyGeEntity2d {lvalue},class AcGeMatrix2d)'''
    ...
    def translateBy (self, *args, **kwargs):
      '''
translateBy( (Entity2d)arg1, (Vector2d)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} translateBy(class PyGeEntity2d {lvalue},class AcGeVector2d)'''
    ...
    def type (self, *args, **kwargs):
      '''
type( (Entity2d)arg1) -> EntityId :

    C++ signature :
        enum AcGe::EntityId type(class PyGeEntity2d {lvalue})'''
    ...

class EllipArc3d:
    def __eq__ (self, *args, **kwargs):
      '''
__eq__( (Entity3d)arg1, (Entity3d)arg2) -> bool :

    C++ signature :
        bool __eq__(class PyGeEntity3d {lvalue},class PyGeEntity3d)'''
    ...
    def __init__ (self, *args, **kwargs):
      '''
__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1, (CircArc3d)arg2) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class PyGeCircArc3d)

__init__( (object)arg1, (Point3d)arg2, (Vector3d)arg3, (Vector3d)arg4, (float)arg5, (float)arg6) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class AcGePoint3d,class AcGeVector3d,class AcGeVector3d,double,double)

__init__( (object)arg1, (Point3d)arg2, (Vector3d)arg3, (Vector3d)arg4, (float)arg5, (float)arg6, (float)arg7, (float)arg8) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class AcGePoint3d,class AcGeVector3d,class AcGeVector3d,double,double,double,double)'''
    ...
    def __ne__ (self, *args, **kwargs):
      '''
__ne__( (Entity3d)arg1, (Entity3d)arg2) -> bool :

    C++ signature :
        bool __ne__(class PyGeEntity3d {lvalue},class PyGeEntity3d)'''
    ...
    def area (self, *args, **kwargs):
      '''
area( (Curve3d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double area(class PyGeCurve3d {lvalue},double,double)

area( (Curve3d)arg1, (float)arg2, (float)arg3, (Tol)arg4) -> float :

    C++ signature :
        double area(class PyGeCurve3d {lvalue},double,double,class AcGeTol)'''
    ...
    def boundBlock (self, *args, **kwargs):
      '''
boundBlock( (Curve3d)arg1) -> BoundBlock3d :

    C++ signature :
        class PyGeBoundBlock3d boundBlock(class PyGeCurve3d {lvalue})

boundBlock( (Curve3d)arg1, (Interval)arg2) -> BoundBlock3d :

    C++ signature :
        class PyGeBoundBlock3d boundBlock(class PyGeCurve3d {lvalue},class PyGeInterval)'''
    ...
    def center (self, *args, **kwargs):
      '''
center( (EllipArc3d)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d center(class PyGeEllipArc3d {lvalue})'''
    ...
    def className (self, *args, **kwargs):
      '''
className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def closestPointTo (self, *args, **kwargs):
      '''
closestPointTo( (Curve3d)arg1, (Point3d)arg2) -> Point3d :

    C++ signature :
        class AcGePoint3d closestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d)

closestPointTo( (Curve3d)arg1, (Point3d)arg2, (Tol)arg3) -> Point3d :

    C++ signature :
        class AcGePoint3d closestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeTol)

closestPointTo( (Curve3d)arg1, (Curve3d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointTo(class PyGeCurve3d {lvalue},class PyGeCurve3d)

closestPointTo( (Curve3d)arg1, (Curve3d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointTo(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeTol)'''
    ...
    def closestPointToPlane (self, *args, **kwargs):
      '''
closestPointToPlane( (EllipArc3d)arg1, (PlanarEnt)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointToPlane(class PyGeEllipArc3d {lvalue},class PyGePlanarEnt)

closestPointToPlane( (EllipArc3d)arg1, (PlanarEnt)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointToPlane(class PyGeEllipArc3d {lvalue},class PyGePlanarEnt,class AcGeTol)'''
    ...
    def copy (self, *args, **kwargs):
      '''
copy( (Entity3d)arg1) -> Entity3d :

    C++ signature :
        class PyGeEntity3d copy(class PyGeEntity3d {lvalue})'''
    ...
    def distanceTo (self, *args, **kwargs):
      '''
distanceTo( (Curve3d)arg1, (Point3d)arg2) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve3d {lvalue},class AcGePoint3d)

distanceTo( (Curve3d)arg1, (Point3d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeTol)

distanceTo( (Curve3d)arg1, (Curve3d)arg2) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve3d {lvalue},class PyGeCurve3d)

distanceTo( (Curve3d)arg1, (Curve3d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeTol)'''
    ...
    def endAng (self, *args, **kwargs):
      '''
endAng( (EllipArc3d)arg1) -> float :

    C++ signature :
        double endAng(class PyGeEllipArc3d {lvalue})'''
    ...
    def endPoint (self, *args, **kwargs):
      '''
endPoint( (EllipArc3d)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d endPoint(class PyGeEllipArc3d {lvalue})'''
    ...
    def evalPoint (self, *args, **kwargs):
      '''
evalPoint( (Curve3d)arg1, (float)arg2) -> Point3d :

    C++ signature :
        class AcGePoint3d evalPoint(class PyGeCurve3d {lvalue},double)

evalPoint( (Curve3d)arg1, (float)arg2, (int)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple evalPoint(class PyGeCurve3d {lvalue},double,int)'''
    ...
    def explode (self, *args, **kwargs):
      '''
explode( (Curve3d)arg1) -> list :

    C++ signature :
        class boost::python::list explode(class PyGeCurve3d {lvalue})

explode( (Curve3d)arg1, (Interval)arg2) -> list :

    C++ signature :
        class boost::python::list explode(class PyGeCurve3d {lvalue},class PyGeInterval)'''
    ...
    def getClosestPointTo (self, *args, **kwargs):
      '''
getClosestPointTo( (Curve3d)arg1, (Point3d)arg2) -> PointOnCurve3d :

    C++ signature :
        class PyGePointOnCurve3d getClosestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d)

getClosestPointTo( (Curve3d)arg1, (Point3d)arg2, (Tol)arg3) -> PointOnCurve3d :

    C++ signature :
        class PyGePointOnCurve3d getClosestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def getClosestPointsTo (self, *args, **kwargs):
      '''
getClosestPointsTo( (Curve3d)arg1, (Curve3d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getClosestPointsTo(class PyGeCurve3d {lvalue},class PyGeCurve3d)

getClosestPointsTo( (Curve3d)arg1, (Curve3d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple getClosestPointsTo(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeTol)'''
    ...
    def getEndPoint (self, *args, **kwargs):
      '''
getEndPoint( (Curve3d)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d getEndPoint(class PyGeCurve3d {lvalue})'''
    ...
    def getInterval (self, *args, **kwargs):
      '''
getInterval( (Curve3d)arg1) -> Interval :

    C++ signature :
        class PyGeInterval getInterval(class PyGeCurve3d {lvalue})'''
    ...
    def getNormalPoint (self, *args, **kwargs):
      '''
getNormalPoint( (Curve3d)arg1, (Point3d)arg2) -> PointOnCurve3d :

    C++ signature :
        class PyGePointOnCurve3d getNormalPoint(class PyGeCurve3d {lvalue},class AcGePoint3d)

getNormalPoint( (Curve3d)arg1, (Point3d)arg2, (Tol)arg3) -> PointOnCurve3d :

    C++ signature :
        class PyGePointOnCurve3d getNormalPoint(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def getPlane (self, *args, **kwargs):
      '''
getPlane( (EllipArc3d)arg1) -> Plane :

    C++ signature :
        class PyGePlane getPlane(class PyGeEllipArc3d {lvalue})'''
    ...
    def getProjClosestPointTo (self, *args, **kwargs):
      '''
getProjClosestPointTo( (Curve3d)arg1, (Point3d)arg2, (Vector3d)arg3) -> PointOnCurve3d :

    C++ signature :
        class PyGePointOnCurve3d getProjClosestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeVector3d)

getProjClosestPointTo( (Curve3d)arg1, (Point3d)arg2, (Vector3d)arg3, (Tol)arg4) -> PointOnCurve3d :

    C++ signature :
        class PyGePointOnCurve3d getProjClosestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeVector3d,class AcGeTol)'''
    ...
    def getProjClosestPointsTo (self, *args, **kwargs):
      '''
getProjClosestPointsTo( (Curve3d)arg1, (Curve3d)arg2, (Vector3d)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple getProjClosestPointsTo(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeVector3d)

getProjClosestPointsTo( (Curve3d)arg1, (Curve3d)arg2, (Vector3d)arg3, (Tol)arg4) -> tuple :

    C++ signature :
        class boost::python::tuple getProjClosestPointsTo(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeVector3d,class AcGeTol)'''
    ...
    def getSamplePoints (self, *args, **kwargs):
      '''
getSamplePoints( (Curve3d)arg1, (int)arg2) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve3d {lvalue},int)

getSamplePoints( (Curve3d)arg1, (float)arg2, (float)arg3, (float)arg4) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve3d {lvalue},double,double,double)'''
    ...
    def getSplitCurves (self, *args, **kwargs):
      '''
getSplitCurves( (Curve3d)arg1, (float)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getSplitCurves(class PyGeCurve3d {lvalue},double)'''
    ...
    def getStartPoint (self, *args, **kwargs):
      '''
getStartPoint( (Curve3d)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d getStartPoint(class PyGeCurve3d {lvalue})'''
    ...
    def getTrimmedOffset (self, *args, **kwargs):
      '''
getTrimmedOffset( (Curve3d)arg1, (float)arg2, (Vector3d)arg3, (OffsetCrvExtType)arg4) -> list :

    C++ signature :
        class boost::python::list getTrimmedOffset(class PyGeCurve3d {lvalue},double,class AcGeVector3d,enum AcGe::OffsetCrvExtType)

getTrimmedOffset( (Curve3d)arg1, (float)arg2, (Vector3d)arg3, (OffsetCrvExtType)arg4, (Tol)arg5) -> list :

    C++ signature :
        class boost::python::list getTrimmedOffset(class PyGeCurve3d {lvalue},double,class AcGeVector3d,enum AcGe::OffsetCrvExtType,class AcGeTol)'''
    ...
    def hasEndPoint (self, *args, **kwargs):
      '''
hasEndPoint( (Curve3d)arg1) -> bool :

    C++ signature :
        bool hasEndPoint(class PyGeCurve3d {lvalue})'''
    ...
    def hasStartPoint (self, *args, **kwargs):
      '''
hasStartPoint( (Curve3d)arg1) -> bool :

    C++ signature :
        bool hasStartPoint(class PyGeCurve3d {lvalue})'''
    ...
    def intersectWith (self, *args, **kwargs):
      '''
intersectWith( (EllipArc3d)arg1, (LinearEnt3d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple intersectWith(class PyGeEllipArc3d {lvalue},class PyGeLinearEnt3d)

intersectWith( (EllipArc3d)arg1, (LinearEnt3d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple intersectWith(class PyGeEllipArc3d {lvalue},class PyGeLinearEnt3d,class AcGeTol)

intersectWith( (EllipArc3d)arg1, (PlanarEnt)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple intersectWith(class PyGeEllipArc3d {lvalue},class PyGePlanarEnt)

intersectWith( (EllipArc3d)arg1, (PlanarEnt)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple intersectWith(class PyGeEllipArc3d {lvalue},class PyGePlanarEnt,class AcGeTol)'''
    ...
    def isCircular (self, *args, **kwargs):
      '''
isCircular( (EllipArc3d)arg1) -> bool :

    C++ signature :
        bool isCircular(class PyGeEllipArc3d {lvalue})

isCircular( (EllipArc3d)arg1, (Tol)arg2) -> bool :

    C++ signature :
        bool isCircular(class PyGeEllipArc3d {lvalue},class AcGeTol)'''
    ...
    def isClosed (self, *args, **kwargs):
      '''
isClosed( (Curve3d)arg1) -> bool :

    C++ signature :
        bool isClosed(class PyGeCurve3d {lvalue})

isClosed( (Curve3d)arg1, (Tol)arg2) -> bool :

    C++ signature :
        bool isClosed(class PyGeCurve3d {lvalue},class AcGeTol)'''
    ...
    def isCoplanarWith (self, *args, **kwargs):
      '''
isCoplanarWith( (Curve3d)arg1, (Curve3d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isCoplanarWith(class PyGeCurve3d {lvalue},class PyGeCurve3d)

isCoplanarWith( (Curve3d)arg1, (Curve3d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple isCoplanarWith(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeTol)'''
    ...
    def isDegenerate (self, *args, **kwargs):
      '''
isDegenerate( (Curve3d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isDegenerate(class PyGeCurve3d {lvalue})

isDegenerate( (Curve3d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isDegenerate(class PyGeCurve3d {lvalue},class AcGeTol)'''
    ...
    def isEqualTo (self, *args, **kwargs):
      '''
isEqualTo( (Entity3d)arg1, (Entity3d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity3d {lvalue},class PyGeEntity3d,class AcGeTol)'''
    ...
    def isInside (self, *args, **kwargs):
      '''
isInside( (EllipArc3d)arg1, (Point3d)arg2) -> bool :

    C++ signature :
        bool isInside(class PyGeEllipArc3d {lvalue},class AcGePoint3d)

isInside( (EllipArc3d)arg1, (Point3d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isInside(class PyGeEllipArc3d {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def isKindOf (self, *args, **kwargs):
      '''
isKindOf( (Entity3d)arg1, (EntityId)arg2) -> bool :

    C++ signature :
        bool isKindOf(class PyGeEntity3d {lvalue},enum AcGe::EntityId)'''
    ...
    def isLinear (self, *args, **kwargs):
      '''
isLinear( (Curve3d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isLinear(class PyGeCurve3d {lvalue})

isLinear( (Curve3d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isLinear(class PyGeCurve3d {lvalue},class AcGeTol)'''
    ...
    def isNull (self, *args, **kwargs):
      '''
isNull( (Entity3d)arg1) -> bool :

    C++ signature :
        bool isNull(class PyGeEntity3d {lvalue})'''
    ...
    def isOn (self, *args, **kwargs):
      '''
isOn( (Curve3d)arg1, (Point3d)arg2) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve3d {lvalue},class AcGePoint3d)

isOn( (Curve3d)arg1, (Point3d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeTol)

isOn( (Curve3d)arg1, (Point3d)arg2, (float)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve3d {lvalue},class AcGePoint3d,double {lvalue})

isOn( (Curve3d)arg1, (Point3d)arg2, (float)arg3, (Tol)arg4) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve3d {lvalue},class AcGePoint3d,double {lvalue},class AcGeTol)

isOn( (Curve3d)arg1, (float)arg2) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve3d {lvalue},double)

isOn( (Curve3d)arg1, (float)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve3d {lvalue},double,class AcGeTol)'''
    ...
    def isPeriodic (self, *args, **kwargs):
      '''
isPeriodic( (Curve3d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isPeriodic(class PyGeCurve3d {lvalue})'''
    ...
    def isPlanar (self, *args, **kwargs):
      '''
isPlanar( (Curve3d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isPlanar(class PyGeCurve3d {lvalue})

isPlanar( (Curve3d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isPlanar(class PyGeCurve3d {lvalue},class AcGeTol)'''
    ...
    def length (self, *args, **kwargs):
      '''
length( (Curve3d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double length(class PyGeCurve3d {lvalue},double,double)

length( (Curve3d)arg1, (float)arg2, (float)arg3, (float)arg4) -> float :

    C++ signature :
        double length(class PyGeCurve3d {lvalue},double,double,double)'''
    ...
    def majorAxis (self, *args, **kwargs):
      '''
majorAxis( (EllipArc3d)arg1) -> Vector3d :

    C++ signature :
        class AcGeVector3d majorAxis(class PyGeEllipArc3d {lvalue})'''
    ...
    def majorRadius (self, *args, **kwargs):
      '''
majorRadius( (EllipArc3d)arg1) -> float :

    C++ signature :
        double majorRadius(class PyGeEllipArc3d {lvalue})'''
    ...
    def minorAxis (self, *args, **kwargs):
      '''
minorAxis( (EllipArc3d)arg1) -> Vector3d :

    C++ signature :
        class AcGeVector3d minorAxis(class PyGeEllipArc3d {lvalue})'''
    ...
    def minorRadius (self, *args, **kwargs):
      '''
minorRadius( (EllipArc3d)arg1) -> float :

    C++ signature :
        double minorRadius(class PyGeEllipArc3d {lvalue})'''
    ...
    def mirror (self, *args, **kwargs):
      '''
mirror( (Entity3d)arg1, (Plane)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} mirror(class PyGeEntity3d {lvalue},class PyGePlane)'''
    ...
    def normal (self, *args, **kwargs):
      '''
normal( (EllipArc3d)arg1) -> Vector3d :

    C++ signature :
        class AcGeVector3d normal(class PyGeEllipArc3d {lvalue})'''
    ...
    def orthoBoundBlock (self, *args, **kwargs):
      '''
orthoBoundBlock( (Curve3d)arg1) -> BoundBlock3d :

    C++ signature :
        class PyGeBoundBlock3d orthoBoundBlock(class PyGeCurve3d {lvalue})

orthoBoundBlock( (Curve3d)arg1, (Interval)arg2) -> BoundBlock3d :

    C++ signature :
        class PyGeBoundBlock3d orthoBoundBlock(class PyGeCurve3d {lvalue},class PyGeInterval)'''
    ...
    def orthoProject (self, *args, **kwargs):
      '''
orthoProject( (Curve3d)arg1, (Plane)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d orthoProject(class PyGeCurve3d {lvalue},class PyGePlane)

orthoProject( (Curve3d)arg1, (Plane)arg2, (Tol)arg3) -> Entity3d :

    C++ signature :
        class PyGeEntity3d orthoProject(class PyGeCurve3d {lvalue},class PyGePlane,class AcGeTol)'''
    ...
    def paramAtLength (self, *args, **kwargs):
      '''
paramAtLength( (Curve3d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double paramAtLength(class PyGeCurve3d {lvalue},double,double)

paramAtLength( (Curve3d)arg1, (float)arg2, (float)arg3, (bool)arg4, (float)arg5) -> float :

    C++ signature :
        double paramAtLength(class PyGeCurve3d {lvalue},double,double,bool,double)'''
    ...
    def paramOf (self, *args, **kwargs):
      '''
paramOf( (Curve3d)arg1, (Point3d)arg2) -> float :

    C++ signature :
        double paramOf(class PyGeCurve3d {lvalue},class AcGePoint3d)

paramOf( (Curve3d)arg1, (Point3d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double paramOf(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def projClosestPointTo (self, *args, **kwargs):
      '''
projClosestPointTo( (Curve3d)arg1, (Point3d)arg2, (Vector3d)arg3) -> Point3d :

    C++ signature :
        class AcGePoint3d projClosestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeVector3d)

projClosestPointTo( (Curve3d)arg1, (Point3d)arg2, (Vector3d)arg3, (Tol)arg4) -> Point3d :

    C++ signature :
        class AcGePoint3d projClosestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeVector3d,class AcGeTol)'''
    ...
    def projClosestPointsTo (self, *args, **kwargs):
      '''
projClosestPointsTo( (Curve3d)arg1, (Curve3d)arg2, (Vector3d)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple projClosestPointsTo(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeVector3d)

projClosestPointsTo( (Curve3d)arg1, (Curve3d)arg2, (Vector3d)arg3, (Tol)arg4) -> tuple :

    C++ signature :
        class boost::python::tuple projClosestPointsTo(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeVector3d,class AcGeTol)'''
    ...
    def projIntersectWith (self, *args, **kwargs):
      '''
projIntersectWith( (EllipArc3d)arg1, (LinearEnt3d)arg2, (Vector3d)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple projIntersectWith(class PyGeEllipArc3d {lvalue},class PyGeLinearEnt3d,class AcGeVector3d)

projIntersectWith( (EllipArc3d)arg1, (LinearEnt3d)arg2, (Vector3d)arg3, (Tol)arg4) -> tuple :

    C++ signature :
        class boost::python::tuple projIntersectWith(class PyGeEllipArc3d {lvalue},class PyGeLinearEnt3d,class AcGeVector3d,class AcGeTol)'''
    ...
    def project (self, *args, **kwargs):
      '''
project( (Curve3d)arg1, (Plane)arg2, (Vector3d)arg3) -> Entity3d :

    C++ signature :
        class PyGeEntity3d project(class PyGeCurve3d {lvalue},class PyGePlane,class AcGeVector3d)

project( (Curve3d)arg1, (Plane)arg2, (Vector3d)arg3, (Tol)arg4) -> Entity3d :

    C++ signature :
        class PyGeEntity3d project(class PyGeCurve3d {lvalue},class PyGePlane,class AcGeVector3d,class AcGeTol)'''
    ...
    def reverseParam (self, *args, **kwargs):
      '''
reverseParam( (Curve3d)arg1) -> Curve3d :

    C++ signature :
        class PyGeCurve3d {lvalue} reverseParam(class PyGeCurve3d {lvalue})'''
    ...
    def rotateBy (self, *args, **kwargs):
      '''
rotateBy( (Entity3d)arg1, (float)arg2, (Vector3d)arg3) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} rotateBy(class PyGeEntity3d {lvalue},double,class AcGeVector3d)

rotateBy( (Entity3d)arg1, (float)arg2, (Vector3d)arg3, (Point3d)arg4) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} rotateBy(class PyGeEntity3d {lvalue},double,class AcGeVector3d,class AcGePoint3d)'''
    ...
    def scaleBy (self, *args, **kwargs):
      '''
scaleBy( (Entity3d)arg1, (float)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} scaleBy(class PyGeEntity3d {lvalue},double)

scaleBy( (Entity3d)arg1, (float)arg2, (Point3d)arg3) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} scaleBy(class PyGeEntity3d {lvalue},double,class AcGePoint3d)'''
    ...
    def set (self, *args, **kwargs):
      '''
set( (EllipArc3d)arg1, (Point3d)arg2, (Vector3d)arg3, (Vector3d)arg4, (float)arg5, (float)arg6) -> EllipArc3d :

    C++ signature :
        class PyGeEllipArc3d {lvalue} set(class PyGeEllipArc3d {lvalue},class AcGePoint3d,class AcGeVector3d,class AcGeVector3d,double,double)

set( (EllipArc3d)arg1, (Point3d)arg2, (Vector3d)arg3, (Vector3d)arg4, (float)arg5, (float)arg6, (float)arg7, (float)arg8) -> EllipArc3d :

    C++ signature :
        class PyGeEllipArc3d {lvalue} set(class PyGeEllipArc3d {lvalue},class AcGePoint3d,class AcGeVector3d,class AcGeVector3d,double,double,double,double)

set( (EllipArc3d)arg1, (CircArc3d)arg2) -> EllipArc3d :

    C++ signature :
        class PyGeEllipArc3d {lvalue} set(class PyGeEllipArc3d {lvalue},class PyGeCircArc3d)'''
    ...
    def setAngles (self, *args, **kwargs):
      '''
setAngles( (EllipArc3d)arg1, (float)arg2, (float)arg3) -> EllipArc3d :

    C++ signature :
        class PyGeEllipArc3d {lvalue} setAngles(class PyGeEllipArc3d {lvalue},double,double)'''
    ...
    def setAxes (self, *args, **kwargs):
      '''
setAxes( (EllipArc3d)arg1, (Vector3d)arg2, (Vector3d)arg3) -> EllipArc3d :

    C++ signature :
        class PyGeEllipArc3d {lvalue} setAxes(class PyGeEllipArc3d {lvalue},class AcGeVector3d,class AcGeVector3d)'''
    ...
    def setCenter (self, *args, **kwargs):
      '''
setCenter( (EllipArc3d)arg1, (Point3d)arg2) -> EllipArc3d :

    C++ signature :
        class PyGeEllipArc3d {lvalue} setCenter(class PyGeEllipArc3d {lvalue},class AcGePoint3d)'''
    ...
    def setInterval (self, *args, **kwargs):
      '''
setInterval( (Curve3d)arg1) -> Curve3d :

    C++ signature :
        class PyGeCurve3d {lvalue} setInterval(class PyGeCurve3d {lvalue})

setInterval( (Curve3d)arg1, (Interval)arg2) -> bool :

    C++ signature :
        bool setInterval(class PyGeCurve3d {lvalue},class PyGeInterval)'''
    ...
    def setMajorRadius (self, *args, **kwargs):
      '''
setMajorRadius( (EllipArc3d)arg1, (float)arg2) -> EllipArc3d :

    C++ signature :
        class PyGeEllipArc3d {lvalue} setMajorRadius(class PyGeEllipArc3d {lvalue},double)'''
    ...
    def setMinorRadius (self, *args, **kwargs):
      '''
setMinorRadius( (EllipArc3d)arg1, (float)arg2) -> EllipArc3d :

    C++ signature :
        class PyGeEllipArc3d {lvalue} setMinorRadius(class PyGeEllipArc3d {lvalue},double)'''
    ...
    def startAng (self, *args, **kwargs):
      '''
startAng( (EllipArc3d)arg1) -> float :

    C++ signature :
        double startAng(class PyGeEllipArc3d {lvalue})'''
    ...
    def startPoint (self, *args, **kwargs):
      '''
startPoint( (EllipArc3d)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d startPoint(class PyGeEllipArc3d {lvalue})'''
    ...
    def transformBy (self, *args, **kwargs):
      '''
transformBy( (Entity3d)arg1, (Matrix3d)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} transformBy(class PyGeEntity3d {lvalue},class AcGeMatrix3d)'''
    ...
    def translateBy (self, *args, **kwargs):
      '''
translateBy( (Entity3d)arg1, (Vector3d)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} translateBy(class PyGeEntity3d {lvalue},class AcGeVector3d)'''
    ...
    def type (self, *args, **kwargs):
      '''
type( (Entity3d)arg1) -> EntityId :

    C++ signature :
        enum AcGe::EntityId type(class PyGeEntity3d {lvalue})'''
    ...

class Entity2d:
    def __eq__ (self, *args, **kwargs):
      '''
__eq__( (Entity2d)arg1, (Entity2d)arg2) -> bool :

    C++ signature :
        bool __eq__(class PyGeEntity2d {lvalue},class PyGeEntity2d)'''
    ...
    def __init__ (self, *args, **kwargs):
      '''Raises an exception
This class cannot be instantiated from Python
'''
    ...
    def __ne__ (self, *args, **kwargs):
      '''
__ne__( (Entity2d)arg1, (Entity2d)arg2) -> bool :

    C++ signature :
        bool __ne__(class PyGeEntity2d {lvalue},class PyGeEntity2d)'''
    ...
    def className (self, *args, **kwargs):
      '''
className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def copy (self, *args, **kwargs):
      '''
copy( (Entity2d)arg1) -> Entity2d :

    C++ signature :
        class PyGeEntity2d copy(class PyGeEntity2d {lvalue})'''
    ...
    def isEqualTo (self, *args, **kwargs):
      '''
isEqualTo( (Entity2d)arg1, (Entity2d)arg2) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity2d {lvalue},class PyGeEntity2d)

isEqualTo( (Entity2d)arg1, (Entity2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity2d {lvalue},class PyGeEntity2d,class AcGeTol)'''
    ...
    def isKindOf (self, *args, **kwargs):
      '''
isKindOf( (Entity2d)arg1, (EntityId)arg2) -> bool :

    C++ signature :
        bool isKindOf(class PyGeEntity2d {lvalue},enum AcGe::EntityId)'''
    ...
    def isNull (self, *args, **kwargs):
      '''
isNull( (Entity2d)arg1) -> bool :

    C++ signature :
        bool isNull(class PyGeEntity2d {lvalue})'''
    ...
    def isOn (self, *args, **kwargs):
      '''
isOn( (Entity2d)arg1, (Point2d)arg2) -> bool :

    C++ signature :
        bool isOn(class PyGeEntity2d {lvalue},class AcGePoint2d)

isOn( (Entity2d)arg1, (Point2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeEntity2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def mirror (self, *args, **kwargs):
      '''
mirror( (Entity2d)arg1, (Line2d)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} mirror(class PyGeEntity2d {lvalue},class PyGeLine2d)'''
    ...
    def rotateBy (self, *args, **kwargs):
      '''
rotateBy( (Entity2d)arg1, (float)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} rotateBy(class PyGeEntity2d {lvalue},double)

rotateBy( (Entity2d)arg1, (float)arg2, (Point2d)arg3) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} rotateBy(class PyGeEntity2d {lvalue},double,class AcGePoint2d)'''
    ...
    def scaleBy (self, *args, **kwargs):
      '''
scaleBy( (Entity2d)arg1, (float)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} scaleBy(class PyGeEntity2d {lvalue},double)

scaleBy( (Entity2d)arg1, (float)arg2, (Point2d)arg3) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} scaleBy(class PyGeEntity2d {lvalue},double,class AcGePoint2d)'''
    ...
    def transformBy (self, *args, **kwargs):
      '''
transformBy( (Entity2d)arg1, (Matrix2d)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} transformBy(class PyGeEntity2d {lvalue},class AcGeMatrix2d)'''
    ...
    def translateBy (self, *args, **kwargs):
      '''
translateBy( (Entity2d)arg1, (Vector2d)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} translateBy(class PyGeEntity2d {lvalue},class AcGeVector2d)'''
    ...
    def type (self, *args, **kwargs):
      '''
type( (Entity2d)arg1) -> EntityId :

    C++ signature :
        enum AcGe::EntityId type(class PyGeEntity2d {lvalue})'''
    ...

class Entity3d:
    def __eq__ (self, *args, **kwargs):
      '''
__eq__( (Entity3d)arg1, (Entity3d)arg2) -> bool :

    C++ signature :
        bool __eq__(class PyGeEntity3d {lvalue},class PyGeEntity3d)'''
    ...
    def __init__ (self, *args, **kwargs):
      '''Raises an exception
This class cannot be instantiated from Python
'''
    ...
    def __ne__ (self, *args, **kwargs):
      '''
__ne__( (Entity3d)arg1, (Entity3d)arg2) -> bool :

    C++ signature :
        bool __ne__(class PyGeEntity3d {lvalue},class PyGeEntity3d)'''
    ...
    def className (self, *args, **kwargs):
      '''
className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def copy (self, *args, **kwargs):
      '''
copy( (Entity3d)arg1) -> Entity3d :

    C++ signature :
        class PyGeEntity3d copy(class PyGeEntity3d {lvalue})'''
    ...
    def isEqualTo (self, *args, **kwargs):
      '''
isEqualTo( (Entity3d)arg1, (Entity3d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity3d {lvalue},class PyGeEntity3d,class AcGeTol)'''
    ...
    def isKindOf (self, *args, **kwargs):
      '''
isKindOf( (Entity3d)arg1, (EntityId)arg2) -> bool :

    C++ signature :
        bool isKindOf(class PyGeEntity3d {lvalue},enum AcGe::EntityId)'''
    ...
    def isNull (self, *args, **kwargs):
      '''
isNull( (Entity3d)arg1) -> bool :

    C++ signature :
        bool isNull(class PyGeEntity3d {lvalue})'''
    ...
    def isOn (self, *args, **kwargs):
      '''
isOn( (Entity3d)arg1, (Point3d)arg2) -> bool :

    C++ signature :
        bool isOn(class PyGeEntity3d {lvalue},class AcGePoint3d)

isOn( (Entity3d)arg1, (Point3d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeEntity3d {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def mirror (self, *args, **kwargs):
      '''
mirror( (Entity3d)arg1, (Plane)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} mirror(class PyGeEntity3d {lvalue},class PyGePlane)'''
    ...
    def rotateBy (self, *args, **kwargs):
      '''
rotateBy( (Entity3d)arg1, (float)arg2, (Vector3d)arg3) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} rotateBy(class PyGeEntity3d {lvalue},double,class AcGeVector3d)

rotateBy( (Entity3d)arg1, (float)arg2, (Vector3d)arg3, (Point3d)arg4) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} rotateBy(class PyGeEntity3d {lvalue},double,class AcGeVector3d,class AcGePoint3d)'''
    ...
    def scaleBy (self, *args, **kwargs):
      '''
scaleBy( (Entity3d)arg1, (float)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} scaleBy(class PyGeEntity3d {lvalue},double)

scaleBy( (Entity3d)arg1, (float)arg2, (Point3d)arg3) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} scaleBy(class PyGeEntity3d {lvalue},double,class AcGePoint3d)'''
    ...
    def transformBy (self, *args, **kwargs):
      '''
transformBy( (Entity3d)arg1, (Matrix3d)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} transformBy(class PyGeEntity3d {lvalue},class AcGeMatrix3d)'''
    ...
    def translateBy (self, *args, **kwargs):
      '''
translateBy( (Entity3d)arg1, (Vector3d)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} translateBy(class PyGeEntity3d {lvalue},class AcGeVector3d)'''
    ...
    def type (self, *args, **kwargs):
      '''
type( (Entity3d)arg1) -> EntityId :

    C++ signature :
        enum AcGe::EntityId type(class PyGeEntity3d {lvalue})'''
    ...

class EntityId:
    def Helix (self, *args, **kwargs):
      '''None'''
    ...
    def __add__ (self, value, /):
      '''Return self+value.'''
    ...
    def __eq__ (self, value, /):
      '''Return self==value.'''
    ...
    def __init__ (self, /, *args, **kwargs):
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
    def __mul__ (self, value, /):
      '''Return self*value.'''
    ...
    def __ne__ (self, value, /):
      '''Return self!=value.'''
    ...
    def __sub__ (self, value, /):
      '''Return self-value.'''
    ...
    def __truediv__ (self, value, /):
      '''Return self/value.'''
    ...
    def as_integer_ratio (self, /):
      '''Return integer ratio.

Return a pair of integers, whose ratio is exactly equal to the original int
and with a positive denominator.

>>> (10).as_integer_ratio()
(10, 1)
>>> (-10).as_integer_ratio()
(-10, 1)
>>> (0).as_integer_ratio()
(0, 1)'''
    ...
    def bit_count (self, /):
      '''Number of ones in the binary representation of the absolute value of self.

Also known as the population count.

>>> bin(13)
'0b1101'
>>> (13).bit_count()
3'''
    ...
    def bit_length (self, /):
      '''Number of bits necessary to represent self in binary.

>>> bin(37)
'0b100101'
>>> (37).bit_length()
6'''
    ...
    def conjugate (self, *args, **kwargs):
      '''Returns self, the complex conjugate of any int.'''
    ...
    def denominator (self, *args, **kwargs):
      '''the denominator of a rational number in lowest terms'''
    ...
    def from_bytes (bytes, byteorder, *, signed=False):
      '''Return the integer represented by the given array of bytes.

  bytes
    Holds the array of bytes to convert.  The argument must either
    support the buffer protocol or be an iterable object producing bytes.
    Bytes and bytearray are examples of built-in objects that support the
    buffer protocol.
  byteorder
    The byte order used to represent the integer.  If byteorder is 'big',
    the most significant byte is at the beginning of the byte array.  If
    byteorder is 'little', the most significant byte is at the end of the
    byte array.  To request the native byte order of the host system, use
    `sys.byteorder' as the byte order value.
  signed
    Indicates whether two's complement is used to represent the integer.'''
    ...
    def imag (self, *args, **kwargs):
      '''the imaginary part of a complex number'''
    ...
    def kAugPolyline2d (self, *args, **kwargs):
      '''None'''
    ...
    def kAugPolyline3d (self, *args, **kwargs):
      '''None'''
    ...
    def kBezierCurve3d (self, *args, **kwargs):
      '''None'''
    ...
    def kBoundBlock2d (self, *args, **kwargs):
      '''None'''
    ...
    def kBoundBlock3d (self, *args, **kwargs):
      '''None'''
    ...
    def kBoundedPlane (self, *args, **kwargs):
      '''None'''
    ...
    def kCircArc2d (self, *args, **kwargs):
      '''None'''
    ...
    def kCircArc3d (self, *args, **kwargs):
      '''None'''
    ...
    def kClipBoundary2d (self, *args, **kwargs):
      '''None'''
    ...
    def kCompositeCrv2d (self, *args, **kwargs):
      '''None'''
    ...
    def kCompositeCrv3d (self, *args, **kwargs):
      '''None'''
    ...
    def kCone (self, *args, **kwargs):
      '''None'''
    ...
    def kConic2d (self, *args, **kwargs):
      '''None'''
    ...
    def kConic3d (self, *args, **kwargs):
      '''None'''
    ...
    def kCubicSplineCurve2d (self, *args, **kwargs):
      '''None'''
    ...
    def kCubicSplineCurve3d (self, *args, **kwargs):
      '''None'''
    ...
    def kCurve2d (self, *args, **kwargs):
      '''None'''
    ...
    def kCurve3d (self, *args, **kwargs):
      '''None'''
    ...
    def kCurveBoundedSurface (self, *args, **kwargs):
      '''None'''
    ...
    def kCurveCurveInt2d (self, *args, **kwargs):
      '''None'''
    ...
    def kCurveCurveInt3d (self, *args, **kwargs):
      '''None'''
    ...
    def kCurveSampleData (self, *args, **kwargs):
      '''None'''
    ...
    def kCurveSurfaceInt (self, *args, **kwargs):
      '''None'''
    ...
    def kCylinder (self, *args, **kwargs):
      '''None'''
    ...
    def kDSpline2d (self, *args, **kwargs):
      '''None'''
    ...
    def kDSpline3d (self, *args, **kwargs):
      '''None'''
    ...
    def kEllipArc2d (self, *args, **kwargs):
      '''None'''
    ...
    def kEllipArc3d (self, *args, **kwargs):
      '''None'''
    ...
    def kEllipCone (self, *args, **kwargs):
      '''None'''
    ...
    def kEllipCylinder (self, *args, **kwargs):
      '''None'''
    ...
    def kEntity2d (self, *args, **kwargs):
      '''None'''
    ...
    def kEntity3d (self, *args, **kwargs):
      '''None'''
    ...
    def kEnvelope2d (self, *args, **kwargs):
      '''None'''
    ...
    def kExternalBoundedSurface (self, *args, **kwargs):
      '''None'''
    ...
    def kExternalCurve2d (self, *args, **kwargs):
      '''None'''
    ...
    def kExternalCurve3d (self, *args, **kwargs):
      '''None'''
    ...
    def kExternalObject (self, *args, **kwargs):
      '''None'''
    ...
    def kExternalSurface (self, *args, **kwargs):
      '''None'''
    ...
    def kFitData3d (self, *args, **kwargs):
      '''None'''
    ...
    def kHatch (self, *args, **kwargs):
      '''None'''
    ...
    def kIntervalBoundBlock (self, *args, **kwargs):
      '''None'''
    ...
    def kLine2d (self, *args, **kwargs):
      '''None'''
    ...
    def kLine3d (self, *args, **kwargs):
      '''None'''
    ...
    def kLineSeg2d (self, *args, **kwargs):
      '''None'''
    ...
    def kLineSeg3d (self, *args, **kwargs):
      '''None'''
    ...
    def kLinearEnt2d (self, *args, **kwargs):
      '''None'''
    ...
    def kLinearEnt3d (self, *args, **kwargs):
      '''None'''
    ...
    def kNurbCurve2d (self, *args, **kwargs):
      '''None'''
    ...
    def kNurbCurve3d (self, *args, **kwargs):
      '''None'''
    ...
    def kNurbSurface (self, *args, **kwargs):
      '''None'''
    ...
    def kObject (self, *args, **kwargs):
      '''None'''
    ...
    def kOffsetCurve2d (self, *args, **kwargs):
      '''None'''
    ...
    def kOffsetCurve3d (self, *args, **kwargs):
      '''None'''
    ...
    def kOffsetSurface (self, *args, **kwargs):
      '''None'''
    ...
    def kPlanarEnt (self, *args, **kwargs):
      '''None'''
    ...
    def kPlane (self, *args, **kwargs):
      '''None'''
    ...
    def kPointEnt2d (self, *args, **kwargs):
      '''None'''
    ...
    def kPointEnt3d (self, *args, **kwargs):
      '''None'''
    ...
    def kPointOnCurve2d (self, *args, **kwargs):
      '''None'''
    ...
    def kPointOnCurve3d (self, *args, **kwargs):
      '''None'''
    ...
    def kPointOnSurface (self, *args, **kwargs):
      '''None'''
    ...
    def kPolyline2d (self, *args, **kwargs):
      '''None'''
    ...
    def kPolyline3d (self, *args, **kwargs):
      '''None'''
    ...
    def kPolynomCurve3d (self, *args, **kwargs):
      '''None'''
    ...
    def kPosition2d (self, *args, **kwargs):
      '''None'''
    ...
    def kPosition3d (self, *args, **kwargs):
      '''None'''
    ...
    def kRay2d (self, *args, **kwargs):
      '''None'''
    ...
    def kRay3d (self, *args, **kwargs):
      '''None'''
    ...
    def kSphere (self, *args, **kwargs):
      '''None'''
    ...
    def kSplineEnt2d (self, *args, **kwargs):
      '''None'''
    ...
    def kSplineEnt3d (self, *args, **kwargs):
      '''None'''
    ...
    def kSurface (self, *args, **kwargs):
      '''None'''
    ...
    def kSurfaceCurve2dTo3d (self, *args, **kwargs):
      '''None'''
    ...
    def kSurfaceCurve3dTo2d (self, *args, **kwargs):
      '''None'''
    ...
    def kSurfaceSurfaceInt (self, *args, **kwargs):
      '''None'''
    ...
    def kTorus (self, *args, **kwargs):
      '''None'''
    ...
    def kTrimmedCrv2d (self, *args, **kwargs):
      '''None'''
    ...
    def kTrimmedCurve2d (self, *args, **kwargs):
      '''None'''
    ...
    def kTrimmedCurve3d (self, *args, **kwargs):
      '''None'''
    ...
    def kTrimmedSurface (self, *args, **kwargs):
      '''None'''
    ...
    def name (self, *args, **kwargs):
      '''None'''
    ...
    def names (self, *args, **kwargs):
      '''dict() -> new empty dictionary
dict(mapping) -> new dictionary initialized from a mapping object's
    (key, value) pairs
dict(iterable) -> new dictionary initialized as if via:
    d = {}
    for k, v in iterable:
        d[k] = v
dict(**kwargs) -> new dictionary initialized with the name=value pairs
    in the keyword argument list.  For example:  dict(one=1, two=2)'''
    ...
    def numerator (self, *args, **kwargs):
      '''the numerator of a rational number in lowest terms'''
    ...
    def real (self, *args, **kwargs):
      '''the real part of a complex number'''
    ...
    def to_bytes (self, /, length, byteorder, *, signed=False):
      '''Return an array of bytes representing an integer.

  length
    Length of bytes object to use.  An OverflowError is raised if the
    integer is not representable with the given number of bytes.
  byteorder
    The byte order used to represent the integer.  If byteorder is 'big',
    the most significant byte is at the beginning of the byte array.  If
    byteorder is 'little', the most significant byte is at the end of the
    byte array.  To request the native byte order of the host system, use
    `sys.byteorder' as the byte order value.
  signed
    Determines whether two's complement is used to represent the integer.
    If signed is False and a negative integer is given, an OverflowError
    is raised.'''
    ...
    def values (self, *args, **kwargs):
      '''dict() -> new empty dictionary
dict(mapping) -> new dictionary initialized from a mapping object's
    (key, value) pairs
dict(iterable) -> new dictionary initialized as if via:
    d = {}
    for k, v in iterable:
        d[k] = v
dict(**kwargs) -> new dictionary initialized with the name=value pairs
    in the keyword argument list.  For example:  dict(one=1, two=2)'''
    ...

class ExternalCurve2d:
    def __eq__ (self, *args, **kwargs):
      '''
__eq__( (Entity2d)arg1, (Entity2d)arg2) -> bool :

    C++ signature :
        bool __eq__(class PyGeEntity2d {lvalue},class PyGeEntity2d)'''
    ...
    def __init__ (self, *args, **kwargs):
      '''Raises an exception
This class cannot be instantiated from Python
'''
    ...
    def __ne__ (self, *args, **kwargs):
      '''
__ne__( (Entity2d)arg1, (Entity2d)arg2) -> bool :

    C++ signature :
        bool __ne__(class PyGeEntity2d {lvalue},class PyGeEntity2d)'''
    ...
    def area (self, *args, **kwargs):
      '''
area( (Curve2d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double area(class PyGeCurve2d {lvalue},double,double)

area( (Curve2d)arg1, (float)arg2, (float)arg3, (Tol)arg4) -> float :

    C++ signature :
        double area(class PyGeCurve2d {lvalue},double,double,class AcGeTol)'''
    ...
    def boundBlock (self, *args, **kwargs):
      '''
boundBlock( (Curve2d)arg1) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d boundBlock(class PyGeCurve2d {lvalue})

boundBlock( (Curve2d)arg1, (Interval)arg2) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d boundBlock(class PyGeCurve2d {lvalue},class PyGeInterval)'''
    ...
    def className (self, *args, **kwargs):
      '''
className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def closestPointTo (self, *args, **kwargs):
      '''
closestPointTo( (Curve2d)arg1, (Point2d)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d closestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d)

closestPointTo( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> Point2d :

    C++ signature :
        class AcGePoint2d closestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)

closestPointTo( (Curve2d)arg1, (Curve2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointTo(class PyGeCurve2d {lvalue},class PyGeCurve2d)

closestPointTo( (Curve2d)arg1, (Curve2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointTo(class PyGeCurve2d {lvalue},class PyGeCurve2d,class AcGeTol)'''
    ...
    def copy (self, *args, **kwargs):
      '''
copy( (Entity2d)arg1) -> Entity2d :

    C++ signature :
        class PyGeEntity2d copy(class PyGeEntity2d {lvalue})'''
    ...
    def distanceTo (self, *args, **kwargs):
      '''
distanceTo( (Curve2d)arg1, (Point2d)arg2) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class AcGePoint2d)

distanceTo( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)

distanceTo( (Curve2d)arg1, (Curve2d)arg2) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class PyGeCurve2d)

distanceTo( (Curve2d)arg1, (Curve2d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class PyGeCurve2d,class AcGeTol)'''
    ...
    def evalPoint (self, *args, **kwargs):
      '''
evalPoint( (Curve2d)arg1, (float)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d evalPoint(class PyGeCurve2d {lvalue},double)

evalPoint( (Curve2d)arg1, (float)arg2, (int)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple evalPoint(class PyGeCurve2d {lvalue},double,int)'''
    ...
    def explode (self, *args, **kwargs):
      '''
explode( (Curve2d)arg1) -> list :

    C++ signature :
        class boost::python::list explode(class PyGeCurve2d {lvalue})

explode( (Curve2d)arg1, (Interval)arg2) -> list :

    C++ signature :
        class boost::python::list explode(class PyGeCurve2d {lvalue},class PyGeInterval)'''
    ...
    def getClosestPointTo (self, *args, **kwargs):
      '''
getClosestPointTo( (Curve2d)arg1, (Point2d)arg2) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getClosestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d)

getClosestPointTo( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getClosestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def getClosestPointsTo (self, *args, **kwargs):
      '''
getClosestPointsTo( (Curve2d)arg1, (Curve2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getClosestPointsTo(class PyGeCurve2d {lvalue},class PyGeCurve2d)

getClosestPointsTo( (Curve2d)arg1, (Curve2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple getClosestPointsTo(class PyGeCurve2d {lvalue},class PyGeCurve2d,class AcGeTol)'''
    ...
    def getEndPoint (self, *args, **kwargs):
      '''
getEndPoint( (Curve2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d getEndPoint(class PyGeCurve2d {lvalue})'''
    ...
    def getInterval (self, *args, **kwargs):
      '''
getInterval( (Curve2d)arg1) -> Interval :

    C++ signature :
        class PyGeInterval getInterval(class PyGeCurve2d {lvalue})'''
    ...
    def getNormalPoint (self, *args, **kwargs):
      '''
getNormalPoint( (Curve2d)arg1, (Point2d)arg2) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getNormalPoint(class PyGeCurve2d {lvalue},class AcGePoint2d)

getNormalPoint( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getNormalPoint(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def getSamplePoints (self, *args, **kwargs):
      '''
getSamplePoints( (Curve2d)arg1, (int)arg2) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve2d {lvalue},int)

getSamplePoints( (Curve2d)arg1, (float)arg2, (float)arg3, (float)arg4) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve2d {lvalue},double,double,double)'''
    ...
    def getSplitCurves (self, *args, **kwargs):
      '''
getSplitCurves( (Curve2d)arg1, (float)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getSplitCurves(class PyGeCurve2d {lvalue},double)'''
    ...
    def getStartPoint (self, *args, **kwargs):
      '''
getStartPoint( (Curve2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d getStartPoint(class PyGeCurve2d {lvalue})'''
    ...
    def getTrimmedOffset (self, *args, **kwargs):
      '''
getTrimmedOffset( (Curve2d)arg1, (float)arg2, (OffsetCrvExtType)arg3) -> list :

    C++ signature :
        class boost::python::list getTrimmedOffset(class PyGeCurve2d {lvalue},double,enum AcGe::OffsetCrvExtType)

getTrimmedOffset( (Curve2d)arg1, (float)arg2, (OffsetCrvExtType)arg3, (Tol)arg4) -> list :

    C++ signature :
        class boost::python::list getTrimmedOffset(class PyGeCurve2d {lvalue},double,enum AcGe::OffsetCrvExtType,class AcGeTol)'''
    ...
    def hasEndPoint (self, *args, **kwargs):
      '''
hasEndPoint( (Curve2d)arg1) -> bool :

    C++ signature :
        bool hasEndPoint(class PyGeCurve2d {lvalue})'''
    ...
    def hasStartPoint (self, *args, **kwargs):
      '''
hasStartPoint( (Curve2d)arg1) -> bool :

    C++ signature :
        bool hasStartPoint(class PyGeCurve2d {lvalue})'''
    ...
    def isClosed (self, *args, **kwargs):
      '''
isClosed( (Curve2d)arg1) -> bool :

    C++ signature :
        bool isClosed(class PyGeCurve2d {lvalue})

isClosed( (Curve2d)arg1, (Tol)arg2) -> bool :

    C++ signature :
        bool isClosed(class PyGeCurve2d {lvalue},class AcGeTol)'''
    ...
    def isDegenerate (self, *args, **kwargs):
      '''
isDegenerate( (Curve2d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isDegenerate(class PyGeCurve2d {lvalue})

isDegenerate( (Curve2d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isDegenerate(class PyGeCurve2d {lvalue},class AcGeTol)'''
    ...
    def isEqualTo (self, *args, **kwargs):
      '''
isEqualTo( (Entity2d)arg1, (Entity2d)arg2) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity2d {lvalue},class PyGeEntity2d)

isEqualTo( (Entity2d)arg1, (Entity2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity2d {lvalue},class PyGeEntity2d,class AcGeTol)'''
    ...
    def isKindOf (self, *args, **kwargs):
      '''
isKindOf( (Entity2d)arg1, (EntityId)arg2) -> bool :

    C++ signature :
        bool isKindOf(class PyGeEntity2d {lvalue},enum AcGe::EntityId)'''
    ...
    def isLinear (self, *args, **kwargs):
      '''
isLinear( (Curve2d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isLinear(class PyGeCurve2d {lvalue})

isLinear( (Curve2d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isLinear(class PyGeCurve2d {lvalue},class AcGeTol)'''
    ...
    def isNull (self, *args, **kwargs):
      '''
isNull( (Entity2d)arg1) -> bool :

    C++ signature :
        bool isNull(class PyGeEntity2d {lvalue})'''
    ...
    def isOn (self, *args, **kwargs):
      '''
isOn( (Curve2d)arg1, (Point2d)arg2) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve2d {lvalue},class AcGePoint2d)

isOn( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)

isOn( (Curve2d)arg1, (Point2d)arg2, (float)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve2d {lvalue},class AcGePoint2d,double {lvalue})

isOn( (Curve2d)arg1, (Point2d)arg2, (float)arg3, (Tol)arg4) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve2d {lvalue},class AcGePoint2d,double {lvalue},class AcGeTol)

isOn( (Curve2d)arg1, (float)arg2) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve2d {lvalue},double)

isOn( (Curve2d)arg1, (float)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve2d {lvalue},double,class AcGeTol)'''
    ...
    def isPeriodic (self, *args, **kwargs):
      '''
isPeriodic( (Curve2d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isPeriodic(class PyGeCurve2d {lvalue})'''
    ...
    def length (self, *args, **kwargs):
      '''
length( (Curve2d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double length(class PyGeCurve2d {lvalue},double,double)

length( (Curve2d)arg1, (float)arg2, (float)arg3, (float)arg4) -> float :

    C++ signature :
        double length(class PyGeCurve2d {lvalue},double,double,double)'''
    ...
    def mirror (self, *args, **kwargs):
      '''
mirror( (Entity2d)arg1, (Line2d)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} mirror(class PyGeEntity2d {lvalue},class PyGeLine2d)'''
    ...
    def orthoBoundBlock (self, *args, **kwargs):
      '''
orthoBoundBlock( (Curve2d)arg1) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d orthoBoundBlock(class PyGeCurve2d {lvalue})

orthoBoundBlock( (Curve2d)arg1, (Interval)arg2) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d orthoBoundBlock(class PyGeCurve2d {lvalue},class PyGeInterval)'''
    ...
    def paramAtLength (self, *args, **kwargs):
      '''
paramAtLength( (Curve2d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double paramAtLength(class PyGeCurve2d {lvalue},double,double)

paramAtLength( (Curve2d)arg1, (float)arg2, (float)arg3, (bool)arg4, (float)arg5) -> float :

    C++ signature :
        double paramAtLength(class PyGeCurve2d {lvalue},double,double,bool,double)'''
    ...
    def paramOf (self, *args, **kwargs):
      '''
paramOf( (Curve2d)arg1, (Point2d)arg2) -> float :

    C++ signature :
        double paramOf(class PyGeCurve2d {lvalue},class AcGePoint2d)

paramOf( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double paramOf(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def reverseParam (self, *args, **kwargs):
      '''
reverseParam( (Curve2d)arg1) -> Curve2d :

    C++ signature :
        class PyGeCurve2d {lvalue} reverseParam(class PyGeCurve2d {lvalue})'''
    ...
    def rotateBy (self, *args, **kwargs):
      '''
rotateBy( (Entity2d)arg1, (float)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} rotateBy(class PyGeEntity2d {lvalue},double)

rotateBy( (Entity2d)arg1, (float)arg2, (Point2d)arg3) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} rotateBy(class PyGeEntity2d {lvalue},double,class AcGePoint2d)'''
    ...
    def scaleBy (self, *args, **kwargs):
      '''
scaleBy( (Entity2d)arg1, (float)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} scaleBy(class PyGeEntity2d {lvalue},double)

scaleBy( (Entity2d)arg1, (float)arg2, (Point2d)arg3) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} scaleBy(class PyGeEntity2d {lvalue},double,class AcGePoint2d)'''
    ...
    def setInterval (self, *args, **kwargs):
      '''
setInterval( (Curve2d)arg1) -> Curve2d :

    C++ signature :
        class PyGeCurve2d {lvalue} setInterval(class PyGeCurve2d {lvalue})

setInterval( (Curve2d)arg1, (Interval)arg2) -> bool :

    C++ signature :
        bool setInterval(class PyGeCurve2d {lvalue},class PyGeInterval)'''
    ...
    def transformBy (self, *args, **kwargs):
      '''
transformBy( (Entity2d)arg1, (Matrix2d)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} transformBy(class PyGeEntity2d {lvalue},class AcGeMatrix2d)'''
    ...
    def translateBy (self, *args, **kwargs):
      '''
translateBy( (Entity2d)arg1, (Vector2d)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} translateBy(class PyGeEntity2d {lvalue},class AcGeVector2d)'''
    ...
    def type (self, *args, **kwargs):
      '''
type( (Entity2d)arg1) -> EntityId :

    C++ signature :
        enum AcGe::EntityId type(class PyGeEntity2d {lvalue})'''
    ...

class ExternalCurve3d:
    def __eq__ (self, *args, **kwargs):
      '''
__eq__( (Entity3d)arg1, (Entity3d)arg2) -> bool :

    C++ signature :
        bool __eq__(class PyGeEntity3d {lvalue},class PyGeEntity3d)'''
    ...
    def __init__ (self, *args, **kwargs):
      '''Raises an exception
This class cannot be instantiated from Python
'''
    ...
    def __ne__ (self, *args, **kwargs):
      '''
__ne__( (Entity3d)arg1, (Entity3d)arg2) -> bool :

    C++ signature :
        bool __ne__(class PyGeEntity3d {lvalue},class PyGeEntity3d)'''
    ...
    def area (self, *args, **kwargs):
      '''
area( (Curve3d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double area(class PyGeCurve3d {lvalue},double,double)

area( (Curve3d)arg1, (float)arg2, (float)arg3, (Tol)arg4) -> float :

    C++ signature :
        double area(class PyGeCurve3d {lvalue},double,double,class AcGeTol)'''
    ...
    def boundBlock (self, *args, **kwargs):
      '''
boundBlock( (Curve3d)arg1) -> BoundBlock3d :

    C++ signature :
        class PyGeBoundBlock3d boundBlock(class PyGeCurve3d {lvalue})

boundBlock( (Curve3d)arg1, (Interval)arg2) -> BoundBlock3d :

    C++ signature :
        class PyGeBoundBlock3d boundBlock(class PyGeCurve3d {lvalue},class PyGeInterval)'''
    ...
    def className (self, *args, **kwargs):
      '''
className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def closestPointTo (self, *args, **kwargs):
      '''
closestPointTo( (Curve3d)arg1, (Point3d)arg2) -> Point3d :

    C++ signature :
        class AcGePoint3d closestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d)

closestPointTo( (Curve3d)arg1, (Point3d)arg2, (Tol)arg3) -> Point3d :

    C++ signature :
        class AcGePoint3d closestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeTol)

closestPointTo( (Curve3d)arg1, (Curve3d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointTo(class PyGeCurve3d {lvalue},class PyGeCurve3d)

closestPointTo( (Curve3d)arg1, (Curve3d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointTo(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeTol)'''
    ...
    def copy (self, *args, **kwargs):
      '''
copy( (Entity3d)arg1) -> Entity3d :

    C++ signature :
        class PyGeEntity3d copy(class PyGeEntity3d {lvalue})'''
    ...
    def distanceTo (self, *args, **kwargs):
      '''
distanceTo( (Curve3d)arg1, (Point3d)arg2) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve3d {lvalue},class AcGePoint3d)

distanceTo( (Curve3d)arg1, (Point3d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeTol)

distanceTo( (Curve3d)arg1, (Curve3d)arg2) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve3d {lvalue},class PyGeCurve3d)

distanceTo( (Curve3d)arg1, (Curve3d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeTol)'''
    ...
    def evalPoint (self, *args, **kwargs):
      '''
evalPoint( (Curve3d)arg1, (float)arg2) -> Point3d :

    C++ signature :
        class AcGePoint3d evalPoint(class PyGeCurve3d {lvalue},double)

evalPoint( (Curve3d)arg1, (float)arg2, (int)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple evalPoint(class PyGeCurve3d {lvalue},double,int)'''
    ...
    def explode (self, *args, **kwargs):
      '''
explode( (Curve3d)arg1) -> list :

    C++ signature :
        class boost::python::list explode(class PyGeCurve3d {lvalue})

explode( (Curve3d)arg1, (Interval)arg2) -> list :

    C++ signature :
        class boost::python::list explode(class PyGeCurve3d {lvalue},class PyGeInterval)'''
    ...
    def getClosestPointTo (self, *args, **kwargs):
      '''
getClosestPointTo( (Curve3d)arg1, (Point3d)arg2) -> PointOnCurve3d :

    C++ signature :
        class PyGePointOnCurve3d getClosestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d)

getClosestPointTo( (Curve3d)arg1, (Point3d)arg2, (Tol)arg3) -> PointOnCurve3d :

    C++ signature :
        class PyGePointOnCurve3d getClosestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def getClosestPointsTo (self, *args, **kwargs):
      '''
getClosestPointsTo( (Curve3d)arg1, (Curve3d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getClosestPointsTo(class PyGeCurve3d {lvalue},class PyGeCurve3d)

getClosestPointsTo( (Curve3d)arg1, (Curve3d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple getClosestPointsTo(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeTol)'''
    ...
    def getEndPoint (self, *args, **kwargs):
      '''
getEndPoint( (Curve3d)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d getEndPoint(class PyGeCurve3d {lvalue})'''
    ...
    def getInterval (self, *args, **kwargs):
      '''
getInterval( (Curve3d)arg1) -> Interval :

    C++ signature :
        class PyGeInterval getInterval(class PyGeCurve3d {lvalue})'''
    ...
    def getNormalPoint (self, *args, **kwargs):
      '''
getNormalPoint( (Curve3d)arg1, (Point3d)arg2) -> PointOnCurve3d :

    C++ signature :
        class PyGePointOnCurve3d getNormalPoint(class PyGeCurve3d {lvalue},class AcGePoint3d)

getNormalPoint( (Curve3d)arg1, (Point3d)arg2, (Tol)arg3) -> PointOnCurve3d :

    C++ signature :
        class PyGePointOnCurve3d getNormalPoint(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def getProjClosestPointTo (self, *args, **kwargs):
      '''
getProjClosestPointTo( (Curve3d)arg1, (Point3d)arg2, (Vector3d)arg3) -> PointOnCurve3d :

    C++ signature :
        class PyGePointOnCurve3d getProjClosestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeVector3d)

getProjClosestPointTo( (Curve3d)arg1, (Point3d)arg2, (Vector3d)arg3, (Tol)arg4) -> PointOnCurve3d :

    C++ signature :
        class PyGePointOnCurve3d getProjClosestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeVector3d,class AcGeTol)'''
    ...
    def getProjClosestPointsTo (self, *args, **kwargs):
      '''
getProjClosestPointsTo( (Curve3d)arg1, (Curve3d)arg2, (Vector3d)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple getProjClosestPointsTo(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeVector3d)

getProjClosestPointsTo( (Curve3d)arg1, (Curve3d)arg2, (Vector3d)arg3, (Tol)arg4) -> tuple :

    C++ signature :
        class boost::python::tuple getProjClosestPointsTo(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeVector3d,class AcGeTol)'''
    ...
    def getSamplePoints (self, *args, **kwargs):
      '''
getSamplePoints( (Curve3d)arg1, (int)arg2) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve3d {lvalue},int)

getSamplePoints( (Curve3d)arg1, (float)arg2, (float)arg3, (float)arg4) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve3d {lvalue},double,double,double)'''
    ...
    def getSplitCurves (self, *args, **kwargs):
      '''
getSplitCurves( (Curve3d)arg1, (float)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getSplitCurves(class PyGeCurve3d {lvalue},double)'''
    ...
    def getStartPoint (self, *args, **kwargs):
      '''
getStartPoint( (Curve3d)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d getStartPoint(class PyGeCurve3d {lvalue})'''
    ...
    def getTrimmedOffset (self, *args, **kwargs):
      '''
getTrimmedOffset( (Curve3d)arg1, (float)arg2, (Vector3d)arg3, (OffsetCrvExtType)arg4) -> list :

    C++ signature :
        class boost::python::list getTrimmedOffset(class PyGeCurve3d {lvalue},double,class AcGeVector3d,enum AcGe::OffsetCrvExtType)

getTrimmedOffset( (Curve3d)arg1, (float)arg2, (Vector3d)arg3, (OffsetCrvExtType)arg4, (Tol)arg5) -> list :

    C++ signature :
        class boost::python::list getTrimmedOffset(class PyGeCurve3d {lvalue},double,class AcGeVector3d,enum AcGe::OffsetCrvExtType,class AcGeTol)'''
    ...
    def hasEndPoint (self, *args, **kwargs):
      '''
hasEndPoint( (Curve3d)arg1) -> bool :

    C++ signature :
        bool hasEndPoint(class PyGeCurve3d {lvalue})'''
    ...
    def hasStartPoint (self, *args, **kwargs):
      '''
hasStartPoint( (Curve3d)arg1) -> bool :

    C++ signature :
        bool hasStartPoint(class PyGeCurve3d {lvalue})'''
    ...
    def isClosed (self, *args, **kwargs):
      '''
isClosed( (Curve3d)arg1) -> bool :

    C++ signature :
        bool isClosed(class PyGeCurve3d {lvalue})

isClosed( (Curve3d)arg1, (Tol)arg2) -> bool :

    C++ signature :
        bool isClosed(class PyGeCurve3d {lvalue},class AcGeTol)'''
    ...
    def isCoplanarWith (self, *args, **kwargs):
      '''
isCoplanarWith( (Curve3d)arg1, (Curve3d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isCoplanarWith(class PyGeCurve3d {lvalue},class PyGeCurve3d)

isCoplanarWith( (Curve3d)arg1, (Curve3d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple isCoplanarWith(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeTol)'''
    ...
    def isDegenerate (self, *args, **kwargs):
      '''
isDegenerate( (Curve3d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isDegenerate(class PyGeCurve3d {lvalue})

isDegenerate( (Curve3d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isDegenerate(class PyGeCurve3d {lvalue},class AcGeTol)'''
    ...
    def isEqualTo (self, *args, **kwargs):
      '''
isEqualTo( (Entity3d)arg1, (Entity3d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity3d {lvalue},class PyGeEntity3d,class AcGeTol)'''
    ...
    def isKindOf (self, *args, **kwargs):
      '''
isKindOf( (Entity3d)arg1, (EntityId)arg2) -> bool :

    C++ signature :
        bool isKindOf(class PyGeEntity3d {lvalue},enum AcGe::EntityId)'''
    ...
    def isLinear (self, *args, **kwargs):
      '''
isLinear( (Curve3d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isLinear(class PyGeCurve3d {lvalue})

isLinear( (Curve3d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isLinear(class PyGeCurve3d {lvalue},class AcGeTol)'''
    ...
    def isNull (self, *args, **kwargs):
      '''
isNull( (Entity3d)arg1) -> bool :

    C++ signature :
        bool isNull(class PyGeEntity3d {lvalue})'''
    ...
    def isOn (self, *args, **kwargs):
      '''
isOn( (Curve3d)arg1, (Point3d)arg2) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve3d {lvalue},class AcGePoint3d)

isOn( (Curve3d)arg1, (Point3d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeTol)

isOn( (Curve3d)arg1, (Point3d)arg2, (float)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve3d {lvalue},class AcGePoint3d,double {lvalue})

isOn( (Curve3d)arg1, (Point3d)arg2, (float)arg3, (Tol)arg4) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve3d {lvalue},class AcGePoint3d,double {lvalue},class AcGeTol)

isOn( (Curve3d)arg1, (float)arg2) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve3d {lvalue},double)

isOn( (Curve3d)arg1, (float)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve3d {lvalue},double,class AcGeTol)'''
    ...
    def isPeriodic (self, *args, **kwargs):
      '''
isPeriodic( (Curve3d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isPeriodic(class PyGeCurve3d {lvalue})'''
    ...
    def isPlanar (self, *args, **kwargs):
      '''
isPlanar( (Curve3d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isPlanar(class PyGeCurve3d {lvalue})

isPlanar( (Curve3d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isPlanar(class PyGeCurve3d {lvalue},class AcGeTol)'''
    ...
    def length (self, *args, **kwargs):
      '''
length( (Curve3d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double length(class PyGeCurve3d {lvalue},double,double)

length( (Curve3d)arg1, (float)arg2, (float)arg3, (float)arg4) -> float :

    C++ signature :
        double length(class PyGeCurve3d {lvalue},double,double,double)'''
    ...
    def mirror (self, *args, **kwargs):
      '''
mirror( (Entity3d)arg1, (Plane)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} mirror(class PyGeEntity3d {lvalue},class PyGePlane)'''
    ...
    def orthoBoundBlock (self, *args, **kwargs):
      '''
orthoBoundBlock( (Curve3d)arg1) -> BoundBlock3d :

    C++ signature :
        class PyGeBoundBlock3d orthoBoundBlock(class PyGeCurve3d {lvalue})

orthoBoundBlock( (Curve3d)arg1, (Interval)arg2) -> BoundBlock3d :

    C++ signature :
        class PyGeBoundBlock3d orthoBoundBlock(class PyGeCurve3d {lvalue},class PyGeInterval)'''
    ...
    def orthoProject (self, *args, **kwargs):
      '''
orthoProject( (Curve3d)arg1, (Plane)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d orthoProject(class PyGeCurve3d {lvalue},class PyGePlane)

orthoProject( (Curve3d)arg1, (Plane)arg2, (Tol)arg3) -> Entity3d :

    C++ signature :
        class PyGeEntity3d orthoProject(class PyGeCurve3d {lvalue},class PyGePlane,class AcGeTol)'''
    ...
    def paramAtLength (self, *args, **kwargs):
      '''
paramAtLength( (Curve3d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double paramAtLength(class PyGeCurve3d {lvalue},double,double)

paramAtLength( (Curve3d)arg1, (float)arg2, (float)arg3, (bool)arg4, (float)arg5) -> float :

    C++ signature :
        double paramAtLength(class PyGeCurve3d {lvalue},double,double,bool,double)'''
    ...
    def paramOf (self, *args, **kwargs):
      '''
paramOf( (Curve3d)arg1, (Point3d)arg2) -> float :

    C++ signature :
        double paramOf(class PyGeCurve3d {lvalue},class AcGePoint3d)

paramOf( (Curve3d)arg1, (Point3d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double paramOf(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def projClosestPointTo (self, *args, **kwargs):
      '''
projClosestPointTo( (Curve3d)arg1, (Point3d)arg2, (Vector3d)arg3) -> Point3d :

    C++ signature :
        class AcGePoint3d projClosestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeVector3d)

projClosestPointTo( (Curve3d)arg1, (Point3d)arg2, (Vector3d)arg3, (Tol)arg4) -> Point3d :

    C++ signature :
        class AcGePoint3d projClosestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeVector3d,class AcGeTol)'''
    ...
    def projClosestPointsTo (self, *args, **kwargs):
      '''
projClosestPointsTo( (Curve3d)arg1, (Curve3d)arg2, (Vector3d)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple projClosestPointsTo(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeVector3d)

projClosestPointsTo( (Curve3d)arg1, (Curve3d)arg2, (Vector3d)arg3, (Tol)arg4) -> tuple :

    C++ signature :
        class boost::python::tuple projClosestPointsTo(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeVector3d,class AcGeTol)'''
    ...
    def project (self, *args, **kwargs):
      '''
project( (Curve3d)arg1, (Plane)arg2, (Vector3d)arg3) -> Entity3d :

    C++ signature :
        class PyGeEntity3d project(class PyGeCurve3d {lvalue},class PyGePlane,class AcGeVector3d)

project( (Curve3d)arg1, (Plane)arg2, (Vector3d)arg3, (Tol)arg4) -> Entity3d :

    C++ signature :
        class PyGeEntity3d project(class PyGeCurve3d {lvalue},class PyGePlane,class AcGeVector3d,class AcGeTol)'''
    ...
    def reverseParam (self, *args, **kwargs):
      '''
reverseParam( (Curve3d)arg1) -> Curve3d :

    C++ signature :
        class PyGeCurve3d {lvalue} reverseParam(class PyGeCurve3d {lvalue})'''
    ...
    def rotateBy (self, *args, **kwargs):
      '''
rotateBy( (Entity3d)arg1, (float)arg2, (Vector3d)arg3) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} rotateBy(class PyGeEntity3d {lvalue},double,class AcGeVector3d)

rotateBy( (Entity3d)arg1, (float)arg2, (Vector3d)arg3, (Point3d)arg4) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} rotateBy(class PyGeEntity3d {lvalue},double,class AcGeVector3d,class AcGePoint3d)'''
    ...
    def scaleBy (self, *args, **kwargs):
      '''
scaleBy( (Entity3d)arg1, (float)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} scaleBy(class PyGeEntity3d {lvalue},double)

scaleBy( (Entity3d)arg1, (float)arg2, (Point3d)arg3) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} scaleBy(class PyGeEntity3d {lvalue},double,class AcGePoint3d)'''
    ...
    def setInterval (self, *args, **kwargs):
      '''
setInterval( (Curve3d)arg1) -> Curve3d :

    C++ signature :
        class PyGeCurve3d {lvalue} setInterval(class PyGeCurve3d {lvalue})

setInterval( (Curve3d)arg1, (Interval)arg2) -> bool :

    C++ signature :
        bool setInterval(class PyGeCurve3d {lvalue},class PyGeInterval)'''
    ...
    def transformBy (self, *args, **kwargs):
      '''
transformBy( (Entity3d)arg1, (Matrix3d)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} transformBy(class PyGeEntity3d {lvalue},class AcGeMatrix3d)'''
    ...
    def translateBy (self, *args, **kwargs):
      '''
translateBy( (Entity3d)arg1, (Vector3d)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} translateBy(class PyGeEntity3d {lvalue},class AcGeVector3d)'''
    ...
    def type (self, *args, **kwargs):
      '''
type( (Entity3d)arg1) -> EntityId :

    C++ signature :
        enum AcGe::EntityId type(class PyGeEntity3d {lvalue})'''
    ...

class Interval:
    def __eq__ (self, value, /):
      '''Return self==value.'''
    ...
    def __init__ (self, *args, **kwargs):
      '''
__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
    ...
    def __ne__ (self, value, /):
      '''Return self!=value.'''
    ...
    def className (self, *args, **kwargs):
      '''
className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...

class KnotVector:
    def __eq__ (self, value, /):
      '''Return self==value.'''
    ...
    def __init__ (self, *args, **kwargs):
      '''
__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
    ...
    def __ne__ (self, value, /):
      '''Return self!=value.'''
    ...
    def className (self, *args, **kwargs):
      '''
className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...

class Line2d:
    def __eq__ (self, *args, **kwargs):
      '''
__eq__( (Entity2d)arg1, (Entity2d)arg2) -> bool :

    C++ signature :
        bool __eq__(class PyGeEntity2d {lvalue},class PyGeEntity2d)'''
    ...
    def __init__ (self, *args, **kwargs):
      '''
__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1, (Point2d)arg2, (Vector2d)arg3) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class AcGePoint2d,class AcGeVector2d)

__init__( (object)arg1, (Point2d)arg2, (Point2d)arg3) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class AcGePoint2d,class AcGePoint2d)'''
    ...
    def __ne__ (self, *args, **kwargs):
      '''
__ne__( (Entity2d)arg1, (Entity2d)arg2) -> bool :

    C++ signature :
        bool __ne__(class PyGeEntity2d {lvalue},class PyGeEntity2d)'''
    ...
    def area (self, *args, **kwargs):
      '''
area( (Curve2d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double area(class PyGeCurve2d {lvalue},double,double)

area( (Curve2d)arg1, (float)arg2, (float)arg3, (Tol)arg4) -> float :

    C++ signature :
        double area(class PyGeCurve2d {lvalue},double,double,class AcGeTol)'''
    ...
    def boundBlock (self, *args, **kwargs):
      '''
boundBlock( (Curve2d)arg1) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d boundBlock(class PyGeCurve2d {lvalue})

boundBlock( (Curve2d)arg1, (Interval)arg2) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d boundBlock(class PyGeCurve2d {lvalue},class PyGeInterval)'''
    ...
    def className (self, *args, **kwargs):
      '''
className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def closestPointTo (self, *args, **kwargs):
      '''
closestPointTo( (Curve2d)arg1, (Point2d)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d closestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d)

closestPointTo( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> Point2d :

    C++ signature :
        class AcGePoint2d closestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)

closestPointTo( (Curve2d)arg1, (Curve2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointTo(class PyGeCurve2d {lvalue},class PyGeCurve2d)

closestPointTo( (Curve2d)arg1, (Curve2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointTo(class PyGeCurve2d {lvalue},class PyGeCurve2d,class AcGeTol)'''
    ...
    def copy (self, *args, **kwargs):
      '''
copy( (Entity2d)arg1) -> Entity2d :

    C++ signature :
        class PyGeEntity2d copy(class PyGeEntity2d {lvalue})'''
    ...
    def direction (self, *args, **kwargs):
      '''
direction( (LinearEnt2d)arg1) -> Vector2d :

    C++ signature :
        class AcGeVector2d direction(class PyGeLinearEnt2d {lvalue})'''
    ...
    def distanceTo (self, *args, **kwargs):
      '''
distanceTo( (Curve2d)arg1, (Point2d)arg2) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class AcGePoint2d)

distanceTo( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)

distanceTo( (Curve2d)arg1, (Curve2d)arg2) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class PyGeCurve2d)

distanceTo( (Curve2d)arg1, (Curve2d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class PyGeCurve2d,class AcGeTol)'''
    ...
    def evalPoint (self, *args, **kwargs):
      '''
evalPoint( (Curve2d)arg1, (float)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d evalPoint(class PyGeCurve2d {lvalue},double)

evalPoint( (Curve2d)arg1, (float)arg2, (int)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple evalPoint(class PyGeCurve2d {lvalue},double,int)'''
    ...
    def explode (self, *args, **kwargs):
      '''
explode( (Curve2d)arg1) -> list :

    C++ signature :
        class boost::python::list explode(class PyGeCurve2d {lvalue})

explode( (Curve2d)arg1, (Interval)arg2) -> list :

    C++ signature :
        class boost::python::list explode(class PyGeCurve2d {lvalue},class PyGeInterval)'''
    ...
    def getClosestPointTo (self, *args, **kwargs):
      '''
getClosestPointTo( (Curve2d)arg1, (Point2d)arg2) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getClosestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d)

getClosestPointTo( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getClosestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def getClosestPointsTo (self, *args, **kwargs):
      '''
getClosestPointsTo( (Curve2d)arg1, (Curve2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getClosestPointsTo(class PyGeCurve2d {lvalue},class PyGeCurve2d)

getClosestPointsTo( (Curve2d)arg1, (Curve2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple getClosestPointsTo(class PyGeCurve2d {lvalue},class PyGeCurve2d,class AcGeTol)'''
    ...
    def getEndPoint (self, *args, **kwargs):
      '''
getEndPoint( (Curve2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d getEndPoint(class PyGeCurve2d {lvalue})'''
    ...
    def getInterval (self, *args, **kwargs):
      '''
getInterval( (Curve2d)arg1) -> Interval :

    C++ signature :
        class PyGeInterval getInterval(class PyGeCurve2d {lvalue})'''
    ...
    def getLine (self, *args, **kwargs):
      '''
getLine( (LinearEnt2d)arg1) -> Line2d :

    C++ signature :
        class PyGeLine2d getLine(class PyGeLinearEnt2d {lvalue})'''
    ...
    def getNormalPoint (self, *args, **kwargs):
      '''
getNormalPoint( (Curve2d)arg1, (Point2d)arg2) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getNormalPoint(class PyGeCurve2d {lvalue},class AcGePoint2d)

getNormalPoint( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getNormalPoint(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def getPerpLine (self, *args, **kwargs):
      '''
getPerpLine( (LinearEnt2d)arg1, (Point2d)arg2) -> Line2d :

    C++ signature :
        class PyGeLine2d getPerpLine(class PyGeLinearEnt2d {lvalue},class AcGePoint2d)'''
    ...
    def getSamplePoints (self, *args, **kwargs):
      '''
getSamplePoints( (Curve2d)arg1, (int)arg2) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve2d {lvalue},int)

getSamplePoints( (Curve2d)arg1, (float)arg2, (float)arg3, (float)arg4) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve2d {lvalue},double,double,double)'''
    ...
    def getSplitCurves (self, *args, **kwargs):
      '''
getSplitCurves( (Curve2d)arg1, (float)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getSplitCurves(class PyGeCurve2d {lvalue},double)'''
    ...
    def getStartPoint (self, *args, **kwargs):
      '''
getStartPoint( (Curve2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d getStartPoint(class PyGeCurve2d {lvalue})'''
    ...
    def getTrimmedOffset (self, *args, **kwargs):
      '''
getTrimmedOffset( (Curve2d)arg1, (float)arg2, (OffsetCrvExtType)arg3) -> list :

    C++ signature :
        class boost::python::list getTrimmedOffset(class PyGeCurve2d {lvalue},double,enum AcGe::OffsetCrvExtType)

getTrimmedOffset( (Curve2d)arg1, (float)arg2, (OffsetCrvExtType)arg3, (Tol)arg4) -> list :

    C++ signature :
        class boost::python::list getTrimmedOffset(class PyGeCurve2d {lvalue},double,enum AcGe::OffsetCrvExtType,class AcGeTol)'''
    ...
    def hasEndPoint (self, *args, **kwargs):
      '''
hasEndPoint( (Curve2d)arg1) -> bool :

    C++ signature :
        bool hasEndPoint(class PyGeCurve2d {lvalue})'''
    ...
    def hasStartPoint (self, *args, **kwargs):
      '''
hasStartPoint( (Curve2d)arg1) -> bool :

    C++ signature :
        bool hasStartPoint(class PyGeCurve2d {lvalue})'''
    ...
    def intersectWith (self, *args, **kwargs):
      '''
intersectWith( (LinearEnt2d)arg1, (LinearEnt2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple intersectWith(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d)

intersectWith( (LinearEnt2d)arg1, (LinearEnt2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple intersectWith(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d,class AcGeTol)'''
    ...
    def isClosed (self, *args, **kwargs):
      '''
isClosed( (Curve2d)arg1) -> bool :

    C++ signature :
        bool isClosed(class PyGeCurve2d {lvalue})

isClosed( (Curve2d)arg1, (Tol)arg2) -> bool :

    C++ signature :
        bool isClosed(class PyGeCurve2d {lvalue},class AcGeTol)'''
    ...
    def isColinearTo (self, *args, **kwargs):
      '''
isColinearTo( (LinearEnt2d)arg1, (LinearEnt2d)arg2) -> bool :

    C++ signature :
        bool isColinearTo(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d)

isColinearTo( (LinearEnt2d)arg1, (LinearEnt2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isColinearTo(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d,class AcGeTol)'''
    ...
    def isDegenerate (self, *args, **kwargs):
      '''
isDegenerate( (Curve2d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isDegenerate(class PyGeCurve2d {lvalue})

isDegenerate( (Curve2d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isDegenerate(class PyGeCurve2d {lvalue},class AcGeTol)'''
    ...
    def isEqualTo (self, *args, **kwargs):
      '''
isEqualTo( (Entity2d)arg1, (Entity2d)arg2) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity2d {lvalue},class PyGeEntity2d)

isEqualTo( (Entity2d)arg1, (Entity2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity2d {lvalue},class PyGeEntity2d,class AcGeTol)'''
    ...
    def isKindOf (self, *args, **kwargs):
      '''
isKindOf( (Entity2d)arg1, (EntityId)arg2) -> bool :

    C++ signature :
        bool isKindOf(class PyGeEntity2d {lvalue},enum AcGe::EntityId)'''
    ...
    def isLinear (self, *args, **kwargs):
      '''
isLinear( (Curve2d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isLinear(class PyGeCurve2d {lvalue})

isLinear( (Curve2d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isLinear(class PyGeCurve2d {lvalue},class AcGeTol)'''
    ...
    def isNull (self, *args, **kwargs):
      '''
isNull( (Entity2d)arg1) -> bool :

    C++ signature :
        bool isNull(class PyGeEntity2d {lvalue})'''
    ...
    def isOn (self, *args, **kwargs):
      '''
isOn( (Curve2d)arg1, (Point2d)arg2) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve2d {lvalue},class AcGePoint2d)

isOn( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)

isOn( (Curve2d)arg1, (Point2d)arg2, (float)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve2d {lvalue},class AcGePoint2d,double {lvalue})

isOn( (Curve2d)arg1, (Point2d)arg2, (float)arg3, (Tol)arg4) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve2d {lvalue},class AcGePoint2d,double {lvalue},class AcGeTol)

isOn( (Curve2d)arg1, (float)arg2) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve2d {lvalue},double)

isOn( (Curve2d)arg1, (float)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve2d {lvalue},double,class AcGeTol)'''
    ...
    def isParallelTo (self, *args, **kwargs):
      '''
isParallelTo( (LinearEnt2d)arg1, (LinearEnt2d)arg2) -> bool :

    C++ signature :
        bool isParallelTo(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d)

isParallelTo( (LinearEnt2d)arg1, (LinearEnt2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isParallelTo(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d,class AcGeTol)'''
    ...
    def isPeriodic (self, *args, **kwargs):
      '''
isPeriodic( (Curve2d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isPeriodic(class PyGeCurve2d {lvalue})'''
    ...
    def isPerpendicularTo (self, *args, **kwargs):
      '''
isPerpendicularTo( (LinearEnt2d)arg1, (LinearEnt2d)arg2) -> bool :

    C++ signature :
        bool isPerpendicularTo(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d)

isPerpendicularTo( (LinearEnt2d)arg1, (LinearEnt2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isPerpendicularTo(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d,class AcGeTol)'''
    ...
    def kXAxis (self, *args, **kwargs):
      '''None'''
    ...
    def kYAxis (self, *args, **kwargs):
      '''None'''
    ...
    def length (self, *args, **kwargs):
      '''
length( (Curve2d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double length(class PyGeCurve2d {lvalue},double,double)

length( (Curve2d)arg1, (float)arg2, (float)arg3, (float)arg4) -> float :

    C++ signature :
        double length(class PyGeCurve2d {lvalue},double,double,double)'''
    ...
    def mirror (self, *args, **kwargs):
      '''
mirror( (Entity2d)arg1, (Line2d)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} mirror(class PyGeEntity2d {lvalue},class PyGeLine2d)'''
    ...
    def orthoBoundBlock (self, *args, **kwargs):
      '''
orthoBoundBlock( (Curve2d)arg1) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d orthoBoundBlock(class PyGeCurve2d {lvalue})

orthoBoundBlock( (Curve2d)arg1, (Interval)arg2) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d orthoBoundBlock(class PyGeCurve2d {lvalue},class PyGeInterval)'''
    ...
    def overlap (self, *args, **kwargs):
      '''
overlap( (LinearEnt2d)arg1, (LinearEnt2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple overlap(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d)

overlap( (LinearEnt2d)arg1, (LinearEnt2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple overlap(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d,class AcGeTol)'''
    ...
    def paramAtLength (self, *args, **kwargs):
      '''
paramAtLength( (Curve2d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double paramAtLength(class PyGeCurve2d {lvalue},double,double)

paramAtLength( (Curve2d)arg1, (float)arg2, (float)arg3, (bool)arg4, (float)arg5) -> float :

    C++ signature :
        double paramAtLength(class PyGeCurve2d {lvalue},double,double,bool,double)'''
    ...
    def paramOf (self, *args, **kwargs):
      '''
paramOf( (Curve2d)arg1, (Point2d)arg2) -> float :

    C++ signature :
        double paramOf(class PyGeCurve2d {lvalue},class AcGePoint2d)

paramOf( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double paramOf(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def pointOnLine (self, *args, **kwargs):
      '''
pointOnLine( (LinearEnt2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d pointOnLine(class PyGeLinearEnt2d {lvalue})'''
    ...
    def reverseParam (self, *args, **kwargs):
      '''
reverseParam( (Curve2d)arg1) -> Curve2d :

    C++ signature :
        class PyGeCurve2d {lvalue} reverseParam(class PyGeCurve2d {lvalue})'''
    ...
    def rotateBy (self, *args, **kwargs):
      '''
rotateBy( (Entity2d)arg1, (float)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} rotateBy(class PyGeEntity2d {lvalue},double)

rotateBy( (Entity2d)arg1, (float)arg2, (Point2d)arg3) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} rotateBy(class PyGeEntity2d {lvalue},double,class AcGePoint2d)'''
    ...
    def scaleBy (self, *args, **kwargs):
      '''
scaleBy( (Entity2d)arg1, (float)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} scaleBy(class PyGeEntity2d {lvalue},double)

scaleBy( (Entity2d)arg1, (float)arg2, (Point2d)arg3) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} scaleBy(class PyGeEntity2d {lvalue},double,class AcGePoint2d)'''
    ...
    def set (self, *args, **kwargs):
      '''
set( (Line2d)arg1, (Point2d)arg2, (Vector2d)arg3) -> Line2d :

    C++ signature :
        class PyGeLine2d {lvalue} set(class PyGeLine2d {lvalue},class AcGePoint2d,class AcGeVector2d)

set( (Line2d)arg1, (Point2d)arg2, (Point2d)arg3) -> Line2d :

    C++ signature :
        class PyGeLine2d {lvalue} set(class PyGeLine2d {lvalue},class AcGePoint2d,class AcGePoint2d)'''
    ...
    def setInterval (self, *args, **kwargs):
      '''
setInterval( (Curve2d)arg1) -> Curve2d :

    C++ signature :
        class PyGeCurve2d {lvalue} setInterval(class PyGeCurve2d {lvalue})

setInterval( (Curve2d)arg1, (Interval)arg2) -> bool :

    C++ signature :
        bool setInterval(class PyGeCurve2d {lvalue},class PyGeInterval)'''
    ...
    def transformBy (self, *args, **kwargs):
      '''
transformBy( (Entity2d)arg1, (Matrix2d)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} transformBy(class PyGeEntity2d {lvalue},class AcGeMatrix2d)'''
    ...
    def translateBy (self, *args, **kwargs):
      '''
translateBy( (Entity2d)arg1, (Vector2d)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} translateBy(class PyGeEntity2d {lvalue},class AcGeVector2d)'''
    ...
    def type (self, *args, **kwargs):
      '''
type( (Entity2d)arg1) -> EntityId :

    C++ signature :
        enum AcGe::EntityId type(class PyGeEntity2d {lvalue})'''
    ...

class Line3d:
    def __eq__ (self, *args, **kwargs):
      '''
__eq__( (Entity3d)arg1, (Entity3d)arg2) -> bool :

    C++ signature :
        bool __eq__(class PyGeEntity3d {lvalue},class PyGeEntity3d)'''
    ...
    def __init__ (self, *args, **kwargs):
      '''
__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1, (Point3d)arg2, (Vector3d)arg3) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class AcGePoint3d,class AcGeVector3d)

__init__( (object)arg1, (Point3d)arg2, (Point3d)arg3) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class AcGePoint3d,class AcGePoint3d)'''
    ...
    def __ne__ (self, *args, **kwargs):
      '''
__ne__( (Entity3d)arg1, (Entity3d)arg2) -> bool :

    C++ signature :
        bool __ne__(class PyGeEntity3d {lvalue},class PyGeEntity3d)'''
    ...
    def area (self, *args, **kwargs):
      '''
area( (Curve3d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double area(class PyGeCurve3d {lvalue},double,double)

area( (Curve3d)arg1, (float)arg2, (float)arg3, (Tol)arg4) -> float :

    C++ signature :
        double area(class PyGeCurve3d {lvalue},double,double,class AcGeTol)'''
    ...
    def boundBlock (self, *args, **kwargs):
      '''
boundBlock( (Curve3d)arg1) -> BoundBlock3d :

    C++ signature :
        class PyGeBoundBlock3d boundBlock(class PyGeCurve3d {lvalue})

boundBlock( (Curve3d)arg1, (Interval)arg2) -> BoundBlock3d :

    C++ signature :
        class PyGeBoundBlock3d boundBlock(class PyGeCurve3d {lvalue},class PyGeInterval)'''
    ...
    def className (self, *args, **kwargs):
      '''
className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def closestPointTo (self, *args, **kwargs):
      '''
closestPointTo( (Curve3d)arg1, (Point3d)arg2) -> Point3d :

    C++ signature :
        class AcGePoint3d closestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d)

closestPointTo( (Curve3d)arg1, (Point3d)arg2, (Tol)arg3) -> Point3d :

    C++ signature :
        class AcGePoint3d closestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeTol)

closestPointTo( (Curve3d)arg1, (Curve3d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointTo(class PyGeCurve3d {lvalue},class PyGeCurve3d)

closestPointTo( (Curve3d)arg1, (Curve3d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointTo(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeTol)'''
    ...
    def copy (self, *args, **kwargs):
      '''
copy( (Entity3d)arg1) -> Entity3d :

    C++ signature :
        class PyGeEntity3d copy(class PyGeEntity3d {lvalue})'''
    ...
    def direction (self, *args, **kwargs):
      '''
direction( (LinearEnt3d)arg1) -> Vector3d :

    C++ signature :
        class AcGeVector3d direction(class PyGeLinearEnt3d {lvalue})'''
    ...
    def distanceTo (self, *args, **kwargs):
      '''
distanceTo( (Curve3d)arg1, (Point3d)arg2) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve3d {lvalue},class AcGePoint3d)

distanceTo( (Curve3d)arg1, (Point3d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeTol)

distanceTo( (Curve3d)arg1, (Curve3d)arg2) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve3d {lvalue},class PyGeCurve3d)

distanceTo( (Curve3d)arg1, (Curve3d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeTol)'''
    ...
    def evalPoint (self, *args, **kwargs):
      '''
evalPoint( (Curve3d)arg1, (float)arg2) -> Point3d :

    C++ signature :
        class AcGePoint3d evalPoint(class PyGeCurve3d {lvalue},double)

evalPoint( (Curve3d)arg1, (float)arg2, (int)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple evalPoint(class PyGeCurve3d {lvalue},double,int)'''
    ...
    def explode (self, *args, **kwargs):
      '''
explode( (Curve3d)arg1) -> list :

    C++ signature :
        class boost::python::list explode(class PyGeCurve3d {lvalue})

explode( (Curve3d)arg1, (Interval)arg2) -> list :

    C++ signature :
        class boost::python::list explode(class PyGeCurve3d {lvalue},class PyGeInterval)'''
    ...
    def getClosestPointTo (self, *args, **kwargs):
      '''
getClosestPointTo( (Curve3d)arg1, (Point3d)arg2) -> PointOnCurve3d :

    C++ signature :
        class PyGePointOnCurve3d getClosestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d)

getClosestPointTo( (Curve3d)arg1, (Point3d)arg2, (Tol)arg3) -> PointOnCurve3d :

    C++ signature :
        class PyGePointOnCurve3d getClosestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def getClosestPointsTo (self, *args, **kwargs):
      '''
getClosestPointsTo( (Curve3d)arg1, (Curve3d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getClosestPointsTo(class PyGeCurve3d {lvalue},class PyGeCurve3d)

getClosestPointsTo( (Curve3d)arg1, (Curve3d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple getClosestPointsTo(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeTol)'''
    ...
    def getEndPoint (self, *args, **kwargs):
      '''
getEndPoint( (Curve3d)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d getEndPoint(class PyGeCurve3d {lvalue})'''
    ...
    def getInterval (self, *args, **kwargs):
      '''
getInterval( (Curve3d)arg1) -> Interval :

    C++ signature :
        class PyGeInterval getInterval(class PyGeCurve3d {lvalue})'''
    ...
    def getLine (self, *args, **kwargs):
      '''
getLine( (LinearEnt3d)arg1) -> Line3d :

    C++ signature :
        class PyGeLine3d getLine(class PyGeLinearEnt3d {lvalue})'''
    ...
    def getNormalPoint (self, *args, **kwargs):
      '''
getNormalPoint( (Curve3d)arg1, (Point3d)arg2) -> PointOnCurve3d :

    C++ signature :
        class PyGePointOnCurve3d getNormalPoint(class PyGeCurve3d {lvalue},class AcGePoint3d)

getNormalPoint( (Curve3d)arg1, (Point3d)arg2, (Tol)arg3) -> PointOnCurve3d :

    C++ signature :
        class PyGePointOnCurve3d getNormalPoint(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def getPerpPlane (self, *args, **kwargs):
      '''
getPerpPlane( (LinearEnt3d)arg1, (Point3d)arg2) -> Plane :

    C++ signature :
        class PyGePlane getPerpPlane(class PyGeLinearEnt3d {lvalue},class AcGePoint3d)'''
    ...
    def getProjClosestPointTo (self, *args, **kwargs):
      '''
getProjClosestPointTo( (Curve3d)arg1, (Point3d)arg2, (Vector3d)arg3) -> PointOnCurve3d :

    C++ signature :
        class PyGePointOnCurve3d getProjClosestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeVector3d)

getProjClosestPointTo( (Curve3d)arg1, (Point3d)arg2, (Vector3d)arg3, (Tol)arg4) -> PointOnCurve3d :

    C++ signature :
        class PyGePointOnCurve3d getProjClosestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeVector3d,class AcGeTol)'''
    ...
    def getProjClosestPointsTo (self, *args, **kwargs):
      '''
getProjClosestPointsTo( (Curve3d)arg1, (Curve3d)arg2, (Vector3d)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple getProjClosestPointsTo(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeVector3d)

getProjClosestPointsTo( (Curve3d)arg1, (Curve3d)arg2, (Vector3d)arg3, (Tol)arg4) -> tuple :

    C++ signature :
        class boost::python::tuple getProjClosestPointsTo(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeVector3d,class AcGeTol)'''
    ...
    def getSamplePoints (self, *args, **kwargs):
      '''
getSamplePoints( (Curve3d)arg1, (int)arg2) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve3d {lvalue},int)

getSamplePoints( (Curve3d)arg1, (float)arg2, (float)arg3, (float)arg4) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve3d {lvalue},double,double,double)'''
    ...
    def getSplitCurves (self, *args, **kwargs):
      '''
getSplitCurves( (Curve3d)arg1, (float)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getSplitCurves(class PyGeCurve3d {lvalue},double)'''
    ...
    def getStartPoint (self, *args, **kwargs):
      '''
getStartPoint( (Curve3d)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d getStartPoint(class PyGeCurve3d {lvalue})'''
    ...
    def getTrimmedOffset (self, *args, **kwargs):
      '''
getTrimmedOffset( (Curve3d)arg1, (float)arg2, (Vector3d)arg3, (OffsetCrvExtType)arg4) -> list :

    C++ signature :
        class boost::python::list getTrimmedOffset(class PyGeCurve3d {lvalue},double,class AcGeVector3d,enum AcGe::OffsetCrvExtType)

getTrimmedOffset( (Curve3d)arg1, (float)arg2, (Vector3d)arg3, (OffsetCrvExtType)arg4, (Tol)arg5) -> list :

    C++ signature :
        class boost::python::list getTrimmedOffset(class PyGeCurve3d {lvalue},double,class AcGeVector3d,enum AcGe::OffsetCrvExtType,class AcGeTol)'''
    ...
    def hasEndPoint (self, *args, **kwargs):
      '''
hasEndPoint( (Curve3d)arg1) -> bool :

    C++ signature :
        bool hasEndPoint(class PyGeCurve3d {lvalue})'''
    ...
    def hasStartPoint (self, *args, **kwargs):
      '''
hasStartPoint( (Curve3d)arg1) -> bool :

    C++ signature :
        bool hasStartPoint(class PyGeCurve3d {lvalue})'''
    ...
    def intersectWith (self, *args, **kwargs):
      '''
intersectWith( (LinearEnt3d)arg1, (LinearEnt3d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple intersectWith(class PyGeLinearEnt3d {lvalue},class PyGeLinearEnt3d)

intersectWith( (LinearEnt3d)arg1, (LinearEnt3d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple intersectWith(class PyGeLinearEnt3d {lvalue},class PyGeLinearEnt3d,class AcGeTol)

intersectWith( (LinearEnt3d)arg1, (PlanarEnt)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple intersectWith(class PyGeLinearEnt3d {lvalue},class PyGePlanarEnt)

intersectWith( (LinearEnt3d)arg1, (PlanarEnt)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple intersectWith(class PyGeLinearEnt3d {lvalue},class PyGePlanarEnt,class AcGeTol)'''
    ...
    def isClosed (self, *args, **kwargs):
      '''
isClosed( (Curve3d)arg1) -> bool :

    C++ signature :
        bool isClosed(class PyGeCurve3d {lvalue})

isClosed( (Curve3d)arg1, (Tol)arg2) -> bool :

    C++ signature :
        bool isClosed(class PyGeCurve3d {lvalue},class AcGeTol)'''
    ...
    def isColinearTo (self, *args, **kwargs):
      '''
isColinearTo( (LinearEnt3d)arg1, (LinearEnt3d)arg2) -> bool :

    C++ signature :
        bool isColinearTo(class PyGeLinearEnt3d {lvalue},class PyGeLinearEnt3d)

isColinearTo( (LinearEnt3d)arg1, (LinearEnt3d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isColinearTo(class PyGeLinearEnt3d {lvalue},class PyGeLinearEnt3d,class AcGeTol)'''
    ...
    def isCoplanarWith (self, *args, **kwargs):
      '''
isCoplanarWith( (Curve3d)arg1, (Curve3d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isCoplanarWith(class PyGeCurve3d {lvalue},class PyGeCurve3d)

isCoplanarWith( (Curve3d)arg1, (Curve3d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple isCoplanarWith(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeTol)'''
    ...
    def isDegenerate (self, *args, **kwargs):
      '''
isDegenerate( (Curve3d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isDegenerate(class PyGeCurve3d {lvalue})

isDegenerate( (Curve3d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isDegenerate(class PyGeCurve3d {lvalue},class AcGeTol)'''
    ...
    def isEqualTo (self, *args, **kwargs):
      '''
isEqualTo( (Entity3d)arg1, (Entity3d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity3d {lvalue},class PyGeEntity3d,class AcGeTol)'''
    ...
    def isKindOf (self, *args, **kwargs):
      '''
isKindOf( (Entity3d)arg1, (EntityId)arg2) -> bool :

    C++ signature :
        bool isKindOf(class PyGeEntity3d {lvalue},enum AcGe::EntityId)'''
    ...
    def isLinear (self, *args, **kwargs):
      '''
isLinear( (Curve3d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isLinear(class PyGeCurve3d {lvalue})

isLinear( (Curve3d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isLinear(class PyGeCurve3d {lvalue},class AcGeTol)'''
    ...
    def isNull (self, *args, **kwargs):
      '''
isNull( (Entity3d)arg1) -> bool :

    C++ signature :
        bool isNull(class PyGeEntity3d {lvalue})'''
    ...
    def isOn (self, *args, **kwargs):
      '''
isOn( (LinearEnt3d)arg1, (Point3d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isOn(class PyGeLinearEnt3d {lvalue},class AcGePoint3d)

isOn( (LinearEnt3d)arg1, (Point3d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple isOn(class PyGeLinearEnt3d {lvalue},class AcGePoint3d,class AcGeTol)

isOn( (LinearEnt3d)arg1, (float)arg2) -> bool :

    C++ signature :
        bool isOn(class PyGeLinearEnt3d {lvalue},double)

isOn( (LinearEnt3d)arg1, (float)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeLinearEnt3d {lvalue},double,class AcGeTol)

isOn( (LinearEnt3d)arg1, (Plane)arg2) -> bool :

    C++ signature :
        bool isOn(class PyGeLinearEnt3d {lvalue},class PyGePlane)

isOn( (LinearEnt3d)arg1, (Plane)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeLinearEnt3d {lvalue},class PyGePlane,class AcGeTol)'''
    ...
    def isParallelTo (self, *args, **kwargs):
      '''
isParallelTo( (LinearEnt3d)arg1, (LinearEnt3d)arg2) -> bool :

    C++ signature :
        bool isParallelTo(class PyGeLinearEnt3d {lvalue},class PyGeLinearEnt3d)

isParallelTo( (LinearEnt3d)arg1, (LinearEnt3d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isParallelTo(class PyGeLinearEnt3d {lvalue},class PyGeLinearEnt3d,class AcGeTol)

isParallelTo( (LinearEnt3d)arg1, (PlanarEnt)arg2) -> bool :

    C++ signature :
        bool isParallelTo(class PyGeLinearEnt3d {lvalue},class PyGePlanarEnt)

isParallelTo( (LinearEnt3d)arg1, (PlanarEnt)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isParallelTo(class PyGeLinearEnt3d {lvalue},class PyGePlanarEnt,class AcGeTol)'''
    ...
    def isPeriodic (self, *args, **kwargs):
      '''
isPeriodic( (Curve3d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isPeriodic(class PyGeCurve3d {lvalue})'''
    ...
    def isPerpendicularTo (self, *args, **kwargs):
      '''
isPerpendicularTo( (LinearEnt3d)arg1, (LinearEnt3d)arg2) -> bool :

    C++ signature :
        bool isPerpendicularTo(class PyGeLinearEnt3d {lvalue},class PyGeLinearEnt3d)

isPerpendicularTo( (LinearEnt3d)arg1, (LinearEnt3d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isPerpendicularTo(class PyGeLinearEnt3d {lvalue},class PyGeLinearEnt3d,class AcGeTol)

isPerpendicularTo( (LinearEnt3d)arg1, (PlanarEnt)arg2) -> bool :

    C++ signature :
        bool isPerpendicularTo(class PyGeLinearEnt3d {lvalue},class PyGePlanarEnt)

isPerpendicularTo( (LinearEnt3d)arg1, (PlanarEnt)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isPerpendicularTo(class PyGeLinearEnt3d {lvalue},class PyGePlanarEnt,class AcGeTol)'''
    ...
    def isPlanar (self, *args, **kwargs):
      '''
isPlanar( (Curve3d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isPlanar(class PyGeCurve3d {lvalue})

isPlanar( (Curve3d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isPlanar(class PyGeCurve3d {lvalue},class AcGeTol)'''
    ...
    def kXAxis (self, *args, **kwargs):
      '''None'''
    ...
    def kYAxis (self, *args, **kwargs):
      '''None'''
    ...
    def kZAxis (self, *args, **kwargs):
      '''None'''
    ...
    def length (self, *args, **kwargs):
      '''
length( (Curve3d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double length(class PyGeCurve3d {lvalue},double,double)

length( (Curve3d)arg1, (float)arg2, (float)arg3, (float)arg4) -> float :

    C++ signature :
        double length(class PyGeCurve3d {lvalue},double,double,double)'''
    ...
    def mirror (self, *args, **kwargs):
      '''
mirror( (Entity3d)arg1, (Plane)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} mirror(class PyGeEntity3d {lvalue},class PyGePlane)'''
    ...
    def orthoBoundBlock (self, *args, **kwargs):
      '''
orthoBoundBlock( (Curve3d)arg1) -> BoundBlock3d :

    C++ signature :
        class PyGeBoundBlock3d orthoBoundBlock(class PyGeCurve3d {lvalue})

orthoBoundBlock( (Curve3d)arg1, (Interval)arg2) -> BoundBlock3d :

    C++ signature :
        class PyGeBoundBlock3d orthoBoundBlock(class PyGeCurve3d {lvalue},class PyGeInterval)'''
    ...
    def orthoProject (self, *args, **kwargs):
      '''
orthoProject( (Curve3d)arg1, (Plane)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d orthoProject(class PyGeCurve3d {lvalue},class PyGePlane)

orthoProject( (Curve3d)arg1, (Plane)arg2, (Tol)arg3) -> Entity3d :

    C++ signature :
        class PyGeEntity3d orthoProject(class PyGeCurve3d {lvalue},class PyGePlane,class AcGeTol)'''
    ...
    def overlap (self, *args, **kwargs):
      '''
overlap( (LinearEnt3d)arg1, (LinearEnt3d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple overlap(class PyGeLinearEnt3d {lvalue},class PyGeLinearEnt3d)

overlap( (LinearEnt3d)arg1, (LinearEnt3d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple overlap(class PyGeLinearEnt3d {lvalue},class PyGeLinearEnt3d,class AcGeTol)'''
    ...
    def paramAtLength (self, *args, **kwargs):
      '''
paramAtLength( (Curve3d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double paramAtLength(class PyGeCurve3d {lvalue},double,double)

paramAtLength( (Curve3d)arg1, (float)arg2, (float)arg3, (bool)arg4, (float)arg5) -> float :

    C++ signature :
        double paramAtLength(class PyGeCurve3d {lvalue},double,double,bool,double)'''
    ...
    def paramOf (self, *args, **kwargs):
      '''
paramOf( (Curve3d)arg1, (Point3d)arg2) -> float :

    C++ signature :
        double paramOf(class PyGeCurve3d {lvalue},class AcGePoint3d)

paramOf( (Curve3d)arg1, (Point3d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double paramOf(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def pointOnLine (self, *args, **kwargs):
      '''
pointOnLine( (LinearEnt3d)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d pointOnLine(class PyGeLinearEnt3d {lvalue})'''
    ...
    def projClosestPointTo (self, *args, **kwargs):
      '''
projClosestPointTo( (Curve3d)arg1, (Point3d)arg2, (Vector3d)arg3) -> Point3d :

    C++ signature :
        class AcGePoint3d projClosestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeVector3d)

projClosestPointTo( (Curve3d)arg1, (Point3d)arg2, (Vector3d)arg3, (Tol)arg4) -> Point3d :

    C++ signature :
        class AcGePoint3d projClosestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeVector3d,class AcGeTol)'''
    ...
    def projClosestPointsTo (self, *args, **kwargs):
      '''
projClosestPointsTo( (Curve3d)arg1, (Curve3d)arg2, (Vector3d)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple projClosestPointsTo(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeVector3d)

projClosestPointsTo( (Curve3d)arg1, (Curve3d)arg2, (Vector3d)arg3, (Tol)arg4) -> tuple :

    C++ signature :
        class boost::python::tuple projClosestPointsTo(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeVector3d,class AcGeTol)'''
    ...
    def projIntersectWith (self, *args, **kwargs):
      '''
projIntersectWith( (LinearEnt3d)arg1, (LinearEnt3d)arg2, (Vector3d)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple projIntersectWith(class PyGeLinearEnt3d {lvalue},class PyGeLinearEnt3d,class AcGeVector3d)

projIntersectWith( (LinearEnt3d)arg1, (LinearEnt3d)arg2, (Vector3d)arg3, (Tol)arg4) -> tuple :

    C++ signature :
        class boost::python::tuple projIntersectWith(class PyGeLinearEnt3d {lvalue},class PyGeLinearEnt3d,class AcGeVector3d,class AcGeTol)'''
    ...
    def project (self, *args, **kwargs):
      '''
project( (Curve3d)arg1, (Plane)arg2, (Vector3d)arg3) -> Entity3d :

    C++ signature :
        class PyGeEntity3d project(class PyGeCurve3d {lvalue},class PyGePlane,class AcGeVector3d)

project( (Curve3d)arg1, (Plane)arg2, (Vector3d)arg3, (Tol)arg4) -> Entity3d :

    C++ signature :
        class PyGeEntity3d project(class PyGeCurve3d {lvalue},class PyGePlane,class AcGeVector3d,class AcGeTol)'''
    ...
    def reverseParam (self, *args, **kwargs):
      '''
reverseParam( (Curve3d)arg1) -> Curve3d :

    C++ signature :
        class PyGeCurve3d {lvalue} reverseParam(class PyGeCurve3d {lvalue})'''
    ...
    def rotateBy (self, *args, **kwargs):
      '''
rotateBy( (Entity3d)arg1, (float)arg2, (Vector3d)arg3) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} rotateBy(class PyGeEntity3d {lvalue},double,class AcGeVector3d)

rotateBy( (Entity3d)arg1, (float)arg2, (Vector3d)arg3, (Point3d)arg4) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} rotateBy(class PyGeEntity3d {lvalue},double,class AcGeVector3d,class AcGePoint3d)'''
    ...
    def scaleBy (self, *args, **kwargs):
      '''
scaleBy( (Entity3d)arg1, (float)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} scaleBy(class PyGeEntity3d {lvalue},double)

scaleBy( (Entity3d)arg1, (float)arg2, (Point3d)arg3) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} scaleBy(class PyGeEntity3d {lvalue},double,class AcGePoint3d)'''
    ...
    def set (self, *args, **kwargs):
      '''
set( (Line3d)arg1, (Point3d)arg2, (Vector3d)arg3) -> Line3d :

    C++ signature :
        class PyGeLine3d {lvalue} set(class PyGeLine3d {lvalue},class AcGePoint3d,class AcGeVector3d)

set( (Line3d)arg1, (Point3d)arg2, (Point3d)arg3) -> Line3d :

    C++ signature :
        class PyGeLine3d {lvalue} set(class PyGeLine3d {lvalue},class AcGePoint3d,class AcGePoint3d)'''
    ...
    def setInterval (self, *args, **kwargs):
      '''
setInterval( (Curve3d)arg1) -> Curve3d :

    C++ signature :
        class PyGeCurve3d {lvalue} setInterval(class PyGeCurve3d {lvalue})

setInterval( (Curve3d)arg1, (Interval)arg2) -> bool :

    C++ signature :
        bool setInterval(class PyGeCurve3d {lvalue},class PyGeInterval)'''
    ...
    def transformBy (self, *args, **kwargs):
      '''
transformBy( (Entity3d)arg1, (Matrix3d)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} transformBy(class PyGeEntity3d {lvalue},class AcGeMatrix3d)'''
    ...
    def translateBy (self, *args, **kwargs):
      '''
translateBy( (Entity3d)arg1, (Vector3d)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} translateBy(class PyGeEntity3d {lvalue},class AcGeVector3d)'''
    ...
    def type (self, *args, **kwargs):
      '''
type( (Entity3d)arg1) -> EntityId :

    C++ signature :
        enum AcGe::EntityId type(class PyGeEntity3d {lvalue})'''
    ...

class LineSeg2d:
    def __eq__ (self, *args, **kwargs):
      '''
__eq__( (Entity2d)arg1, (Entity2d)arg2) -> bool :

    C++ signature :
        bool __eq__(class PyGeEntity2d {lvalue},class PyGeEntity2d)'''
    ...
    def __init__ (self, *args, **kwargs):
      '''
__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1, (Point2d)arg2, (Vector2d)arg3) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class AcGePoint2d,class AcGeVector2d)

__init__( (object)arg1, (Point2d)arg2, (Point2d)arg3) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class AcGePoint2d,class AcGePoint2d)'''
    ...
    def __ne__ (self, *args, **kwargs):
      '''
__ne__( (Entity2d)arg1, (Entity2d)arg2) -> bool :

    C++ signature :
        bool __ne__(class PyGeEntity2d {lvalue},class PyGeEntity2d)'''
    ...
    def area (self, *args, **kwargs):
      '''
area( (Curve2d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double area(class PyGeCurve2d {lvalue},double,double)

area( (Curve2d)arg1, (float)arg2, (float)arg3, (Tol)arg4) -> float :

    C++ signature :
        double area(class PyGeCurve2d {lvalue},double,double,class AcGeTol)'''
    ...
    def baryComb (self, *args, **kwargs):
      '''
baryComb( (LineSeg2d)arg1, (float)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d baryComb(class PyGeLineSeg2d {lvalue},double)'''
    ...
    def boundBlock (self, *args, **kwargs):
      '''
boundBlock( (Curve2d)arg1) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d boundBlock(class PyGeCurve2d {lvalue})

boundBlock( (Curve2d)arg1, (Interval)arg2) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d boundBlock(class PyGeCurve2d {lvalue},class PyGeInterval)'''
    ...
    def className (self, *args, **kwargs):
      '''
className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def closestPointTo (self, *args, **kwargs):
      '''
closestPointTo( (Curve2d)arg1, (Point2d)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d closestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d)

closestPointTo( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> Point2d :

    C++ signature :
        class AcGePoint2d closestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)

closestPointTo( (Curve2d)arg1, (Curve2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointTo(class PyGeCurve2d {lvalue},class PyGeCurve2d)

closestPointTo( (Curve2d)arg1, (Curve2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointTo(class PyGeCurve2d {lvalue},class PyGeCurve2d,class AcGeTol)'''
    ...
    def copy (self, *args, **kwargs):
      '''
copy( (Entity2d)arg1) -> Entity2d :

    C++ signature :
        class PyGeEntity2d copy(class PyGeEntity2d {lvalue})'''
    ...
    def direction (self, *args, **kwargs):
      '''
direction( (LinearEnt2d)arg1) -> Vector2d :

    C++ signature :
        class AcGeVector2d direction(class PyGeLinearEnt2d {lvalue})'''
    ...
    def distanceTo (self, *args, **kwargs):
      '''
distanceTo( (Curve2d)arg1, (Point2d)arg2) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class AcGePoint2d)

distanceTo( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)

distanceTo( (Curve2d)arg1, (Curve2d)arg2) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class PyGeCurve2d)

distanceTo( (Curve2d)arg1, (Curve2d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class PyGeCurve2d,class AcGeTol)'''
    ...
    def endPoint (self, *args, **kwargs):
      '''
endPoint( (LineSeg2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d endPoint(class PyGeLineSeg2d {lvalue})'''
    ...
    def evalPoint (self, *args, **kwargs):
      '''
evalPoint( (Curve2d)arg1, (float)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d evalPoint(class PyGeCurve2d {lvalue},double)

evalPoint( (Curve2d)arg1, (float)arg2, (int)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple evalPoint(class PyGeCurve2d {lvalue},double,int)'''
    ...
    def explode (self, *args, **kwargs):
      '''
explode( (Curve2d)arg1) -> list :

    C++ signature :
        class boost::python::list explode(class PyGeCurve2d {lvalue})

explode( (Curve2d)arg1, (Interval)arg2) -> list :

    C++ signature :
        class boost::python::list explode(class PyGeCurve2d {lvalue},class PyGeInterval)'''
    ...
    def getBisector (self, *args, **kwargs):
      '''
getBisector( (LineSeg2d)arg1) -> Line2d :

    C++ signature :
        class PyGeLine2d getBisector(class PyGeLineSeg2d {lvalue})'''
    ...
    def getClosestPointTo (self, *args, **kwargs):
      '''
getClosestPointTo( (Curve2d)arg1, (Point2d)arg2) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getClosestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d)

getClosestPointTo( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getClosestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def getClosestPointsTo (self, *args, **kwargs):
      '''
getClosestPointsTo( (Curve2d)arg1, (Curve2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getClosestPointsTo(class PyGeCurve2d {lvalue},class PyGeCurve2d)

getClosestPointsTo( (Curve2d)arg1, (Curve2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple getClosestPointsTo(class PyGeCurve2d {lvalue},class PyGeCurve2d,class AcGeTol)'''
    ...
    def getEndPoint (self, *args, **kwargs):
      '''
getEndPoint( (Curve2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d getEndPoint(class PyGeCurve2d {lvalue})'''
    ...
    def getInterval (self, *args, **kwargs):
      '''
getInterval( (Curve2d)arg1) -> Interval :

    C++ signature :
        class PyGeInterval getInterval(class PyGeCurve2d {lvalue})'''
    ...
    def getLine (self, *args, **kwargs):
      '''
getLine( (LinearEnt2d)arg1) -> Line2d :

    C++ signature :
        class PyGeLine2d getLine(class PyGeLinearEnt2d {lvalue})'''
    ...
    def getNormalPoint (self, *args, **kwargs):
      '''
getNormalPoint( (Curve2d)arg1, (Point2d)arg2) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getNormalPoint(class PyGeCurve2d {lvalue},class AcGePoint2d)

getNormalPoint( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getNormalPoint(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def getPerpLine (self, *args, **kwargs):
      '''
getPerpLine( (LinearEnt2d)arg1, (Point2d)arg2) -> Line2d :

    C++ signature :
        class PyGeLine2d getPerpLine(class PyGeLinearEnt2d {lvalue},class AcGePoint2d)'''
    ...
    def getSamplePoints (self, *args, **kwargs):
      '''
getSamplePoints( (Curve2d)arg1, (int)arg2) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve2d {lvalue},int)

getSamplePoints( (Curve2d)arg1, (float)arg2, (float)arg3, (float)arg4) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve2d {lvalue},double,double,double)'''
    ...
    def getSplitCurves (self, *args, **kwargs):
      '''
getSplitCurves( (Curve2d)arg1, (float)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getSplitCurves(class PyGeCurve2d {lvalue},double)'''
    ...
    def getStartPoint (self, *args, **kwargs):
      '''
getStartPoint( (Curve2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d getStartPoint(class PyGeCurve2d {lvalue})'''
    ...
    def getTrimmedOffset (self, *args, **kwargs):
      '''
getTrimmedOffset( (Curve2d)arg1, (float)arg2, (OffsetCrvExtType)arg3) -> list :

    C++ signature :
        class boost::python::list getTrimmedOffset(class PyGeCurve2d {lvalue},double,enum AcGe::OffsetCrvExtType)

getTrimmedOffset( (Curve2d)arg1, (float)arg2, (OffsetCrvExtType)arg3, (Tol)arg4) -> list :

    C++ signature :
        class boost::python::list getTrimmedOffset(class PyGeCurve2d {lvalue},double,enum AcGe::OffsetCrvExtType,class AcGeTol)'''
    ...
    def hasEndPoint (self, *args, **kwargs):
      '''
hasEndPoint( (Curve2d)arg1) -> bool :

    C++ signature :
        bool hasEndPoint(class PyGeCurve2d {lvalue})'''
    ...
    def hasStartPoint (self, *args, **kwargs):
      '''
hasStartPoint( (Curve2d)arg1) -> bool :

    C++ signature :
        bool hasStartPoint(class PyGeCurve2d {lvalue})'''
    ...
    def intersectWith (self, *args, **kwargs):
      '''
intersectWith( (LinearEnt2d)arg1, (LinearEnt2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple intersectWith(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d)

intersectWith( (LinearEnt2d)arg1, (LinearEnt2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple intersectWith(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d,class AcGeTol)'''
    ...
    def isClosed (self, *args, **kwargs):
      '''
isClosed( (Curve2d)arg1) -> bool :

    C++ signature :
        bool isClosed(class PyGeCurve2d {lvalue})

isClosed( (Curve2d)arg1, (Tol)arg2) -> bool :

    C++ signature :
        bool isClosed(class PyGeCurve2d {lvalue},class AcGeTol)'''
    ...
    def isColinearTo (self, *args, **kwargs):
      '''
isColinearTo( (LinearEnt2d)arg1, (LinearEnt2d)arg2) -> bool :

    C++ signature :
        bool isColinearTo(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d)

isColinearTo( (LinearEnt2d)arg1, (LinearEnt2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isColinearTo(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d,class AcGeTol)'''
    ...
    def isDegenerate (self, *args, **kwargs):
      '''
isDegenerate( (Curve2d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isDegenerate(class PyGeCurve2d {lvalue})

isDegenerate( (Curve2d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isDegenerate(class PyGeCurve2d {lvalue},class AcGeTol)'''
    ...
    def isEqualTo (self, *args, **kwargs):
      '''
isEqualTo( (Entity2d)arg1, (Entity2d)arg2) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity2d {lvalue},class PyGeEntity2d)

isEqualTo( (Entity2d)arg1, (Entity2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity2d {lvalue},class PyGeEntity2d,class AcGeTol)'''
    ...
    def isKindOf (self, *args, **kwargs):
      '''
isKindOf( (Entity2d)arg1, (EntityId)arg2) -> bool :

    C++ signature :
        bool isKindOf(class PyGeEntity2d {lvalue},enum AcGe::EntityId)'''
    ...
    def isLinear (self, *args, **kwargs):
      '''
isLinear( (Curve2d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isLinear(class PyGeCurve2d {lvalue})

isLinear( (Curve2d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isLinear(class PyGeCurve2d {lvalue},class AcGeTol)'''
    ...
    def isNull (self, *args, **kwargs):
      '''
isNull( (Entity2d)arg1) -> bool :

    C++ signature :
        bool isNull(class PyGeEntity2d {lvalue})'''
    ...
    def isOn (self, *args, **kwargs):
      '''
isOn( (Curve2d)arg1, (Point2d)arg2) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve2d {lvalue},class AcGePoint2d)

isOn( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)

isOn( (Curve2d)arg1, (Point2d)arg2, (float)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve2d {lvalue},class AcGePoint2d,double {lvalue})

isOn( (Curve2d)arg1, (Point2d)arg2, (float)arg3, (Tol)arg4) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve2d {lvalue},class AcGePoint2d,double {lvalue},class AcGeTol)

isOn( (Curve2d)arg1, (float)arg2) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve2d {lvalue},double)

isOn( (Curve2d)arg1, (float)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve2d {lvalue},double,class AcGeTol)'''
    ...
    def isParallelTo (self, *args, **kwargs):
      '''
isParallelTo( (LinearEnt2d)arg1, (LinearEnt2d)arg2) -> bool :

    C++ signature :
        bool isParallelTo(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d)

isParallelTo( (LinearEnt2d)arg1, (LinearEnt2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isParallelTo(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d,class AcGeTol)'''
    ...
    def isPeriodic (self, *args, **kwargs):
      '''
isPeriodic( (Curve2d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isPeriodic(class PyGeCurve2d {lvalue})'''
    ...
    def isPerpendicularTo (self, *args, **kwargs):
      '''
isPerpendicularTo( (LinearEnt2d)arg1, (LinearEnt2d)arg2) -> bool :

    C++ signature :
        bool isPerpendicularTo(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d)

isPerpendicularTo( (LinearEnt2d)arg1, (LinearEnt2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isPerpendicularTo(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d,class AcGeTol)'''
    ...
    def length (self, *args, **kwargs):
      '''
length( (LineSeg2d)arg1) -> float :

    C++ signature :
        double length(class PyGeLineSeg2d {lvalue})

length( (LineSeg2d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double length(class PyGeLineSeg2d {lvalue},double,double)

length( (LineSeg2d)arg1, (float)arg2, (float)arg3, (float)arg4) -> float :

    C++ signature :
        double length(class PyGeLineSeg2d {lvalue},double,double,double)'''
    ...
    def midPoint (self, *args, **kwargs):
      '''
midPoint( (LineSeg2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d midPoint(class PyGeLineSeg2d {lvalue})'''
    ...
    def mirror (self, *args, **kwargs):
      '''
mirror( (Entity2d)arg1, (Line2d)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} mirror(class PyGeEntity2d {lvalue},class PyGeLine2d)'''
    ...
    def orthoBoundBlock (self, *args, **kwargs):
      '''
orthoBoundBlock( (Curve2d)arg1) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d orthoBoundBlock(class PyGeCurve2d {lvalue})

orthoBoundBlock( (Curve2d)arg1, (Interval)arg2) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d orthoBoundBlock(class PyGeCurve2d {lvalue},class PyGeInterval)'''
    ...
    def overlap (self, *args, **kwargs):
      '''
overlap( (LinearEnt2d)arg1, (LinearEnt2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple overlap(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d)

overlap( (LinearEnt2d)arg1, (LinearEnt2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple overlap(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d,class AcGeTol)'''
    ...
    def paramAtLength (self, *args, **kwargs):
      '''
paramAtLength( (Curve2d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double paramAtLength(class PyGeCurve2d {lvalue},double,double)

paramAtLength( (Curve2d)arg1, (float)arg2, (float)arg3, (bool)arg4, (float)arg5) -> float :

    C++ signature :
        double paramAtLength(class PyGeCurve2d {lvalue},double,double,bool,double)'''
    ...
    def paramOf (self, *args, **kwargs):
      '''
paramOf( (Curve2d)arg1, (Point2d)arg2) -> float :

    C++ signature :
        double paramOf(class PyGeCurve2d {lvalue},class AcGePoint2d)

paramOf( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double paramOf(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def pointOnLine (self, *args, **kwargs):
      '''
pointOnLine( (LinearEnt2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d pointOnLine(class PyGeLinearEnt2d {lvalue})'''
    ...
    def reverseParam (self, *args, **kwargs):
      '''
reverseParam( (Curve2d)arg1) -> Curve2d :

    C++ signature :
        class PyGeCurve2d {lvalue} reverseParam(class PyGeCurve2d {lvalue})'''
    ...
    def rotateBy (self, *args, **kwargs):
      '''
rotateBy( (Entity2d)arg1, (float)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} rotateBy(class PyGeEntity2d {lvalue},double)

rotateBy( (Entity2d)arg1, (float)arg2, (Point2d)arg3) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} rotateBy(class PyGeEntity2d {lvalue},double,class AcGePoint2d)'''
    ...
    def scaleBy (self, *args, **kwargs):
      '''
scaleBy( (Entity2d)arg1, (float)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} scaleBy(class PyGeEntity2d {lvalue},double)

scaleBy( (Entity2d)arg1, (float)arg2, (Point2d)arg3) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} scaleBy(class PyGeEntity2d {lvalue},double,class AcGePoint2d)'''
    ...
    def set (self, *args, **kwargs):
      '''
set( (LineSeg2d)arg1, (Point2d)arg2, (Vector2d)arg3) -> LineSeg2d :

    C++ signature :
        class PyGeLineSeg2d {lvalue} set(class PyGeLineSeg2d {lvalue},class AcGePoint2d,class AcGeVector2d)

set( (LineSeg2d)arg1, (Point2d)arg2, (Point2d)arg3) -> LineSeg2d :

    C++ signature :
        class PyGeLineSeg2d {lvalue} set(class PyGeLineSeg2d {lvalue},class AcGePoint2d,class AcGePoint2d)

set( (LineSeg2d)arg1, (Curve2d)arg2, (Curve2d)arg3) -> LineSeg2d :

    C++ signature :
        class PyGeLineSeg2d {lvalue} set(class PyGeLineSeg2d {lvalue},class PyGeCurve2d,class PyGeCurve2d)

set( (LineSeg2d)arg1, (Curve2d)arg2, (Point2d)arg3) -> LineSeg2d :

    C++ signature :
        class PyGeLineSeg2d {lvalue} set(class PyGeLineSeg2d {lvalue},class PyGeCurve2d,class AcGePoint2d)'''
    ...
    def setInterval (self, *args, **kwargs):
      '''
setInterval( (Curve2d)arg1) -> Curve2d :

    C++ signature :
        class PyGeCurve2d {lvalue} setInterval(class PyGeCurve2d {lvalue})

setInterval( (Curve2d)arg1, (Interval)arg2) -> bool :

    C++ signature :
        bool setInterval(class PyGeCurve2d {lvalue},class PyGeInterval)'''
    ...
    def startPoint (self, *args, **kwargs):
      '''
startPoint( (LineSeg2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d startPoint(class PyGeLineSeg2d {lvalue})'''
    ...
    def transformBy (self, *args, **kwargs):
      '''
transformBy( (Entity2d)arg1, (Matrix2d)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} transformBy(class PyGeEntity2d {lvalue},class AcGeMatrix2d)'''
    ...
    def translateBy (self, *args, **kwargs):
      '''
translateBy( (Entity2d)arg1, (Vector2d)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} translateBy(class PyGeEntity2d {lvalue},class AcGeVector2d)'''
    ...
    def type (self, *args, **kwargs):
      '''
type( (Entity2d)arg1) -> EntityId :

    C++ signature :
        enum AcGe::EntityId type(class PyGeEntity2d {lvalue})'''
    ...

class LineSeg3d:
    def __eq__ (self, *args, **kwargs):
      '''
__eq__( (Entity3d)arg1, (Entity3d)arg2) -> bool :

    C++ signature :
        bool __eq__(class PyGeEntity3d {lvalue},class PyGeEntity3d)'''
    ...
    def __init__ (self, *args, **kwargs):
      '''
__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1, (Point3d)arg2, (Vector3d)arg3) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class AcGePoint3d,class AcGeVector3d)

__init__( (object)arg1, (Point3d)arg2, (Point3d)arg3) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class AcGePoint3d,class AcGePoint3d)'''
    ...
    def __ne__ (self, *args, **kwargs):
      '''
__ne__( (Entity3d)arg1, (Entity3d)arg2) -> bool :

    C++ signature :
        bool __ne__(class PyGeEntity3d {lvalue},class PyGeEntity3d)'''
    ...
    def area (self, *args, **kwargs):
      '''
area( (Curve3d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double area(class PyGeCurve3d {lvalue},double,double)

area( (Curve3d)arg1, (float)arg2, (float)arg3, (Tol)arg4) -> float :

    C++ signature :
        double area(class PyGeCurve3d {lvalue},double,double,class AcGeTol)'''
    ...
    def baryComb (self, *args, **kwargs):
      '''
baryComb( (LineSeg3d)arg1, (float)arg2) -> Point3d :

    C++ signature :
        class AcGePoint3d baryComb(class PyGeLineSeg3d {lvalue},double)'''
    ...
    def boundBlock (self, *args, **kwargs):
      '''
boundBlock( (Curve3d)arg1) -> BoundBlock3d :

    C++ signature :
        class PyGeBoundBlock3d boundBlock(class PyGeCurve3d {lvalue})

boundBlock( (Curve3d)arg1, (Interval)arg2) -> BoundBlock3d :

    C++ signature :
        class PyGeBoundBlock3d boundBlock(class PyGeCurve3d {lvalue},class PyGeInterval)'''
    ...
    def className (self, *args, **kwargs):
      '''
className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def closestPointTo (self, *args, **kwargs):
      '''
closestPointTo( (Curve3d)arg1, (Point3d)arg2) -> Point3d :

    C++ signature :
        class AcGePoint3d closestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d)

closestPointTo( (Curve3d)arg1, (Point3d)arg2, (Tol)arg3) -> Point3d :

    C++ signature :
        class AcGePoint3d closestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeTol)

closestPointTo( (Curve3d)arg1, (Curve3d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointTo(class PyGeCurve3d {lvalue},class PyGeCurve3d)

closestPointTo( (Curve3d)arg1, (Curve3d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointTo(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeTol)'''
    ...
    def copy (self, *args, **kwargs):
      '''
copy( (Entity3d)arg1) -> Entity3d :

    C++ signature :
        class PyGeEntity3d copy(class PyGeEntity3d {lvalue})'''
    ...
    def direction (self, *args, **kwargs):
      '''
direction( (LinearEnt3d)arg1) -> Vector3d :

    C++ signature :
        class AcGeVector3d direction(class PyGeLinearEnt3d {lvalue})'''
    ...
    def distanceTo (self, *args, **kwargs):
      '''
distanceTo( (Curve3d)arg1, (Point3d)arg2) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve3d {lvalue},class AcGePoint3d)

distanceTo( (Curve3d)arg1, (Point3d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeTol)

distanceTo( (Curve3d)arg1, (Curve3d)arg2) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve3d {lvalue},class PyGeCurve3d)

distanceTo( (Curve3d)arg1, (Curve3d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeTol)'''
    ...
    def endPoint (self, *args, **kwargs):
      '''
endPoint( (LineSeg3d)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d endPoint(class PyGeLineSeg3d {lvalue})'''
    ...
    def evalPoint (self, *args, **kwargs):
      '''
evalPoint( (Curve3d)arg1, (float)arg2) -> Point3d :

    C++ signature :
        class AcGePoint3d evalPoint(class PyGeCurve3d {lvalue},double)

evalPoint( (Curve3d)arg1, (float)arg2, (int)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple evalPoint(class PyGeCurve3d {lvalue},double,int)'''
    ...
    def explode (self, *args, **kwargs):
      '''
explode( (Curve3d)arg1) -> list :

    C++ signature :
        class boost::python::list explode(class PyGeCurve3d {lvalue})

explode( (Curve3d)arg1, (Interval)arg2) -> list :

    C++ signature :
        class boost::python::list explode(class PyGeCurve3d {lvalue},class PyGeInterval)'''
    ...
    def getBisector (self, *args, **kwargs):
      '''
getBisector( (LineSeg3d)arg1) -> Plane :

    C++ signature :
        class PyGePlane getBisector(class PyGeLineSeg3d {lvalue})'''
    ...
    def getClosestPointTo (self, *args, **kwargs):
      '''
getClosestPointTo( (Curve3d)arg1, (Point3d)arg2) -> PointOnCurve3d :

    C++ signature :
        class PyGePointOnCurve3d getClosestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d)

getClosestPointTo( (Curve3d)arg1, (Point3d)arg2, (Tol)arg3) -> PointOnCurve3d :

    C++ signature :
        class PyGePointOnCurve3d getClosestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def getClosestPointsTo (self, *args, **kwargs):
      '''
getClosestPointsTo( (Curve3d)arg1, (Curve3d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getClosestPointsTo(class PyGeCurve3d {lvalue},class PyGeCurve3d)

getClosestPointsTo( (Curve3d)arg1, (Curve3d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple getClosestPointsTo(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeTol)'''
    ...
    def getEndPoint (self, *args, **kwargs):
      '''
getEndPoint( (Curve3d)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d getEndPoint(class PyGeCurve3d {lvalue})'''
    ...
    def getInterval (self, *args, **kwargs):
      '''
getInterval( (Curve3d)arg1) -> Interval :

    C++ signature :
        class PyGeInterval getInterval(class PyGeCurve3d {lvalue})'''
    ...
    def getLine (self, *args, **kwargs):
      '''
getLine( (LinearEnt3d)arg1) -> Line3d :

    C++ signature :
        class PyGeLine3d getLine(class PyGeLinearEnt3d {lvalue})'''
    ...
    def getNormalPoint (self, *args, **kwargs):
      '''
getNormalPoint( (Curve3d)arg1, (Point3d)arg2) -> PointOnCurve3d :

    C++ signature :
        class PyGePointOnCurve3d getNormalPoint(class PyGeCurve3d {lvalue},class AcGePoint3d)

getNormalPoint( (Curve3d)arg1, (Point3d)arg2, (Tol)arg3) -> PointOnCurve3d :

    C++ signature :
        class PyGePointOnCurve3d getNormalPoint(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def getPerpPlane (self, *args, **kwargs):
      '''
getPerpPlane( (LinearEnt3d)arg1, (Point3d)arg2) -> Plane :

    C++ signature :
        class PyGePlane getPerpPlane(class PyGeLinearEnt3d {lvalue},class AcGePoint3d)'''
    ...
    def getProjClosestPointTo (self, *args, **kwargs):
      '''
getProjClosestPointTo( (Curve3d)arg1, (Point3d)arg2, (Vector3d)arg3) -> PointOnCurve3d :

    C++ signature :
        class PyGePointOnCurve3d getProjClosestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeVector3d)

getProjClosestPointTo( (Curve3d)arg1, (Point3d)arg2, (Vector3d)arg3, (Tol)arg4) -> PointOnCurve3d :

    C++ signature :
        class PyGePointOnCurve3d getProjClosestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeVector3d,class AcGeTol)'''
    ...
    def getProjClosestPointsTo (self, *args, **kwargs):
      '''
getProjClosestPointsTo( (Curve3d)arg1, (Curve3d)arg2, (Vector3d)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple getProjClosestPointsTo(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeVector3d)

getProjClosestPointsTo( (Curve3d)arg1, (Curve3d)arg2, (Vector3d)arg3, (Tol)arg4) -> tuple :

    C++ signature :
        class boost::python::tuple getProjClosestPointsTo(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeVector3d,class AcGeTol)'''
    ...
    def getSamplePoints (self, *args, **kwargs):
      '''
getSamplePoints( (Curve3d)arg1, (int)arg2) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve3d {lvalue},int)

getSamplePoints( (Curve3d)arg1, (float)arg2, (float)arg3, (float)arg4) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve3d {lvalue},double,double,double)'''
    ...
    def getSplitCurves (self, *args, **kwargs):
      '''
getSplitCurves( (Curve3d)arg1, (float)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getSplitCurves(class PyGeCurve3d {lvalue},double)'''
    ...
    def getStartPoint (self, *args, **kwargs):
      '''
getStartPoint( (Curve3d)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d getStartPoint(class PyGeCurve3d {lvalue})'''
    ...
    def getTrimmedOffset (self, *args, **kwargs):
      '''
getTrimmedOffset( (Curve3d)arg1, (float)arg2, (Vector3d)arg3, (OffsetCrvExtType)arg4) -> list :

    C++ signature :
        class boost::python::list getTrimmedOffset(class PyGeCurve3d {lvalue},double,class AcGeVector3d,enum AcGe::OffsetCrvExtType)

getTrimmedOffset( (Curve3d)arg1, (float)arg2, (Vector3d)arg3, (OffsetCrvExtType)arg4, (Tol)arg5) -> list :

    C++ signature :
        class boost::python::list getTrimmedOffset(class PyGeCurve3d {lvalue},double,class AcGeVector3d,enum AcGe::OffsetCrvExtType,class AcGeTol)'''
    ...
    def hasEndPoint (self, *args, **kwargs):
      '''
hasEndPoint( (Curve3d)arg1) -> bool :

    C++ signature :
        bool hasEndPoint(class PyGeCurve3d {lvalue})'''
    ...
    def hasStartPoint (self, *args, **kwargs):
      '''
hasStartPoint( (Curve3d)arg1) -> bool :

    C++ signature :
        bool hasStartPoint(class PyGeCurve3d {lvalue})'''
    ...
    def intersectWith (self, *args, **kwargs):
      '''
intersectWith( (LinearEnt3d)arg1, (LinearEnt3d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple intersectWith(class PyGeLinearEnt3d {lvalue},class PyGeLinearEnt3d)

intersectWith( (LinearEnt3d)arg1, (LinearEnt3d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple intersectWith(class PyGeLinearEnt3d {lvalue},class PyGeLinearEnt3d,class AcGeTol)

intersectWith( (LinearEnt3d)arg1, (PlanarEnt)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple intersectWith(class PyGeLinearEnt3d {lvalue},class PyGePlanarEnt)

intersectWith( (LinearEnt3d)arg1, (PlanarEnt)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple intersectWith(class PyGeLinearEnt3d {lvalue},class PyGePlanarEnt,class AcGeTol)'''
    ...
    def isClosed (self, *args, **kwargs):
      '''
isClosed( (Curve3d)arg1) -> bool :

    C++ signature :
        bool isClosed(class PyGeCurve3d {lvalue})

isClosed( (Curve3d)arg1, (Tol)arg2) -> bool :

    C++ signature :
        bool isClosed(class PyGeCurve3d {lvalue},class AcGeTol)'''
    ...
    def isColinearTo (self, *args, **kwargs):
      '''
isColinearTo( (LinearEnt3d)arg1, (LinearEnt3d)arg2) -> bool :

    C++ signature :
        bool isColinearTo(class PyGeLinearEnt3d {lvalue},class PyGeLinearEnt3d)

isColinearTo( (LinearEnt3d)arg1, (LinearEnt3d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isColinearTo(class PyGeLinearEnt3d {lvalue},class PyGeLinearEnt3d,class AcGeTol)'''
    ...
    def isCoplanarWith (self, *args, **kwargs):
      '''
isCoplanarWith( (Curve3d)arg1, (Curve3d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isCoplanarWith(class PyGeCurve3d {lvalue},class PyGeCurve3d)

isCoplanarWith( (Curve3d)arg1, (Curve3d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple isCoplanarWith(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeTol)'''
    ...
    def isDegenerate (self, *args, **kwargs):
      '''
isDegenerate( (Curve3d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isDegenerate(class PyGeCurve3d {lvalue})

isDegenerate( (Curve3d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isDegenerate(class PyGeCurve3d {lvalue},class AcGeTol)'''
    ...
    def isEqualTo (self, *args, **kwargs):
      '''
isEqualTo( (Entity3d)arg1, (Entity3d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity3d {lvalue},class PyGeEntity3d,class AcGeTol)'''
    ...
    def isKindOf (self, *args, **kwargs):
      '''
isKindOf( (Entity3d)arg1, (EntityId)arg2) -> bool :

    C++ signature :
        bool isKindOf(class PyGeEntity3d {lvalue},enum AcGe::EntityId)'''
    ...
    def isLinear (self, *args, **kwargs):
      '''
isLinear( (Curve3d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isLinear(class PyGeCurve3d {lvalue})

isLinear( (Curve3d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isLinear(class PyGeCurve3d {lvalue},class AcGeTol)'''
    ...
    def isNull (self, *args, **kwargs):
      '''
isNull( (Entity3d)arg1) -> bool :

    C++ signature :
        bool isNull(class PyGeEntity3d {lvalue})'''
    ...
    def isOn (self, *args, **kwargs):
      '''
isOn( (LinearEnt3d)arg1, (Point3d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isOn(class PyGeLinearEnt3d {lvalue},class AcGePoint3d)

isOn( (LinearEnt3d)arg1, (Point3d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple isOn(class PyGeLinearEnt3d {lvalue},class AcGePoint3d,class AcGeTol)

isOn( (LinearEnt3d)arg1, (float)arg2) -> bool :

    C++ signature :
        bool isOn(class PyGeLinearEnt3d {lvalue},double)

isOn( (LinearEnt3d)arg1, (float)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeLinearEnt3d {lvalue},double,class AcGeTol)

isOn( (LinearEnt3d)arg1, (Plane)arg2) -> bool :

    C++ signature :
        bool isOn(class PyGeLinearEnt3d {lvalue},class PyGePlane)

isOn( (LinearEnt3d)arg1, (Plane)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeLinearEnt3d {lvalue},class PyGePlane,class AcGeTol)'''
    ...
    def isParallelTo (self, *args, **kwargs):
      '''
isParallelTo( (LinearEnt3d)arg1, (LinearEnt3d)arg2) -> bool :

    C++ signature :
        bool isParallelTo(class PyGeLinearEnt3d {lvalue},class PyGeLinearEnt3d)

isParallelTo( (LinearEnt3d)arg1, (LinearEnt3d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isParallelTo(class PyGeLinearEnt3d {lvalue},class PyGeLinearEnt3d,class AcGeTol)

isParallelTo( (LinearEnt3d)arg1, (PlanarEnt)arg2) -> bool :

    C++ signature :
        bool isParallelTo(class PyGeLinearEnt3d {lvalue},class PyGePlanarEnt)

isParallelTo( (LinearEnt3d)arg1, (PlanarEnt)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isParallelTo(class PyGeLinearEnt3d {lvalue},class PyGePlanarEnt,class AcGeTol)'''
    ...
    def isPeriodic (self, *args, **kwargs):
      '''
isPeriodic( (Curve3d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isPeriodic(class PyGeCurve3d {lvalue})'''
    ...
    def isPerpendicularTo (self, *args, **kwargs):
      '''
isPerpendicularTo( (LinearEnt3d)arg1, (LinearEnt3d)arg2) -> bool :

    C++ signature :
        bool isPerpendicularTo(class PyGeLinearEnt3d {lvalue},class PyGeLinearEnt3d)

isPerpendicularTo( (LinearEnt3d)arg1, (LinearEnt3d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isPerpendicularTo(class PyGeLinearEnt3d {lvalue},class PyGeLinearEnt3d,class AcGeTol)

isPerpendicularTo( (LinearEnt3d)arg1, (PlanarEnt)arg2) -> bool :

    C++ signature :
        bool isPerpendicularTo(class PyGeLinearEnt3d {lvalue},class PyGePlanarEnt)

isPerpendicularTo( (LinearEnt3d)arg1, (PlanarEnt)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isPerpendicularTo(class PyGeLinearEnt3d {lvalue},class PyGePlanarEnt,class AcGeTol)'''
    ...
    def isPlanar (self, *args, **kwargs):
      '''
isPlanar( (Curve3d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isPlanar(class PyGeCurve3d {lvalue})

isPlanar( (Curve3d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isPlanar(class PyGeCurve3d {lvalue},class AcGeTol)'''
    ...
    def length (self, *args, **kwargs):
      '''
length( (LineSeg3d)arg1) -> float :

    C++ signature :
        double length(class PyGeLineSeg3d {lvalue})

length( (LineSeg3d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double length(class PyGeLineSeg3d {lvalue},double,double)

length( (LineSeg3d)arg1, (float)arg2, (float)arg3, (float)arg4) -> float :

    C++ signature :
        double length(class PyGeLineSeg3d {lvalue},double,double,double)'''
    ...
    def midPoint (self, *args, **kwargs):
      '''
midPoint( (LineSeg3d)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d midPoint(class PyGeLineSeg3d {lvalue})'''
    ...
    def mirror (self, *args, **kwargs):
      '''
mirror( (Entity3d)arg1, (Plane)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} mirror(class PyGeEntity3d {lvalue},class PyGePlane)'''
    ...
    def orthoBoundBlock (self, *args, **kwargs):
      '''
orthoBoundBlock( (Curve3d)arg1) -> BoundBlock3d :

    C++ signature :
        class PyGeBoundBlock3d orthoBoundBlock(class PyGeCurve3d {lvalue})

orthoBoundBlock( (Curve3d)arg1, (Interval)arg2) -> BoundBlock3d :

    C++ signature :
        class PyGeBoundBlock3d orthoBoundBlock(class PyGeCurve3d {lvalue},class PyGeInterval)'''
    ...
    def orthoProject (self, *args, **kwargs):
      '''
orthoProject( (Curve3d)arg1, (Plane)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d orthoProject(class PyGeCurve3d {lvalue},class PyGePlane)

orthoProject( (Curve3d)arg1, (Plane)arg2, (Tol)arg3) -> Entity3d :

    C++ signature :
        class PyGeEntity3d orthoProject(class PyGeCurve3d {lvalue},class PyGePlane,class AcGeTol)'''
    ...
    def overlap (self, *args, **kwargs):
      '''
overlap( (LinearEnt3d)arg1, (LinearEnt3d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple overlap(class PyGeLinearEnt3d {lvalue},class PyGeLinearEnt3d)

overlap( (LinearEnt3d)arg1, (LinearEnt3d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple overlap(class PyGeLinearEnt3d {lvalue},class PyGeLinearEnt3d,class AcGeTol)'''
    ...
    def paramAtLength (self, *args, **kwargs):
      '''
paramAtLength( (Curve3d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double paramAtLength(class PyGeCurve3d {lvalue},double,double)

paramAtLength( (Curve3d)arg1, (float)arg2, (float)arg3, (bool)arg4, (float)arg5) -> float :

    C++ signature :
        double paramAtLength(class PyGeCurve3d {lvalue},double,double,bool,double)'''
    ...
    def paramOf (self, *args, **kwargs):
      '''
paramOf( (Curve3d)arg1, (Point3d)arg2) -> float :

    C++ signature :
        double paramOf(class PyGeCurve3d {lvalue},class AcGePoint3d)

paramOf( (Curve3d)arg1, (Point3d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double paramOf(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def pointOnLine (self, *args, **kwargs):
      '''
pointOnLine( (LinearEnt3d)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d pointOnLine(class PyGeLinearEnt3d {lvalue})'''
    ...
    def projClosestPointTo (self, *args, **kwargs):
      '''
projClosestPointTo( (Curve3d)arg1, (Point3d)arg2, (Vector3d)arg3) -> Point3d :

    C++ signature :
        class AcGePoint3d projClosestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeVector3d)

projClosestPointTo( (Curve3d)arg1, (Point3d)arg2, (Vector3d)arg3, (Tol)arg4) -> Point3d :

    C++ signature :
        class AcGePoint3d projClosestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeVector3d,class AcGeTol)'''
    ...
    def projClosestPointsTo (self, *args, **kwargs):
      '''
projClosestPointsTo( (Curve3d)arg1, (Curve3d)arg2, (Vector3d)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple projClosestPointsTo(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeVector3d)

projClosestPointsTo( (Curve3d)arg1, (Curve3d)arg2, (Vector3d)arg3, (Tol)arg4) -> tuple :

    C++ signature :
        class boost::python::tuple projClosestPointsTo(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeVector3d,class AcGeTol)'''
    ...
    def projIntersectWith (self, *args, **kwargs):
      '''
projIntersectWith( (LinearEnt3d)arg1, (LinearEnt3d)arg2, (Vector3d)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple projIntersectWith(class PyGeLinearEnt3d {lvalue},class PyGeLinearEnt3d,class AcGeVector3d)

projIntersectWith( (LinearEnt3d)arg1, (LinearEnt3d)arg2, (Vector3d)arg3, (Tol)arg4) -> tuple :

    C++ signature :
        class boost::python::tuple projIntersectWith(class PyGeLinearEnt3d {lvalue},class PyGeLinearEnt3d,class AcGeVector3d,class AcGeTol)'''
    ...
    def project (self, *args, **kwargs):
      '''
project( (Curve3d)arg1, (Plane)arg2, (Vector3d)arg3) -> Entity3d :

    C++ signature :
        class PyGeEntity3d project(class PyGeCurve3d {lvalue},class PyGePlane,class AcGeVector3d)

project( (Curve3d)arg1, (Plane)arg2, (Vector3d)arg3, (Tol)arg4) -> Entity3d :

    C++ signature :
        class PyGeEntity3d project(class PyGeCurve3d {lvalue},class PyGePlane,class AcGeVector3d,class AcGeTol)'''
    ...
    def reverseParam (self, *args, **kwargs):
      '''
reverseParam( (Curve3d)arg1) -> Curve3d :

    C++ signature :
        class PyGeCurve3d {lvalue} reverseParam(class PyGeCurve3d {lvalue})'''
    ...
    def rotateBy (self, *args, **kwargs):
      '''
rotateBy( (Entity3d)arg1, (float)arg2, (Vector3d)arg3) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} rotateBy(class PyGeEntity3d {lvalue},double,class AcGeVector3d)

rotateBy( (Entity3d)arg1, (float)arg2, (Vector3d)arg3, (Point3d)arg4) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} rotateBy(class PyGeEntity3d {lvalue},double,class AcGeVector3d,class AcGePoint3d)'''
    ...
    def scaleBy (self, *args, **kwargs):
      '''
scaleBy( (Entity3d)arg1, (float)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} scaleBy(class PyGeEntity3d {lvalue},double)

scaleBy( (Entity3d)arg1, (float)arg2, (Point3d)arg3) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} scaleBy(class PyGeEntity3d {lvalue},double,class AcGePoint3d)'''
    ...
    def set (self, *args, **kwargs):
      '''
set( (LineSeg3d)arg1, (Point3d)arg2, (Vector3d)arg3) -> LineSeg3d :

    C++ signature :
        class PyGeLineSeg3d {lvalue} set(class PyGeLineSeg3d {lvalue},class AcGePoint3d,class AcGeVector3d)

set( (LineSeg3d)arg1, (Point3d)arg2, (Point3d)arg3) -> LineSeg3d :

    C++ signature :
        class PyGeLineSeg3d {lvalue} set(class PyGeLineSeg3d {lvalue},class AcGePoint3d,class AcGePoint3d)'''
    ...
    def setInterval (self, *args, **kwargs):
      '''
setInterval( (Curve3d)arg1) -> Curve3d :

    C++ signature :
        class PyGeCurve3d {lvalue} setInterval(class PyGeCurve3d {lvalue})

setInterval( (Curve3d)arg1, (Interval)arg2) -> bool :

    C++ signature :
        bool setInterval(class PyGeCurve3d {lvalue},class PyGeInterval)'''
    ...
    def startPoint (self, *args, **kwargs):
      '''
startPoint( (LineSeg3d)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d startPoint(class PyGeLineSeg3d {lvalue})'''
    ...
    def transformBy (self, *args, **kwargs):
      '''
transformBy( (Entity3d)arg1, (Matrix3d)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} transformBy(class PyGeEntity3d {lvalue},class AcGeMatrix3d)'''
    ...
    def translateBy (self, *args, **kwargs):
      '''
translateBy( (Entity3d)arg1, (Vector3d)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} translateBy(class PyGeEntity3d {lvalue},class AcGeVector3d)'''
    ...
    def type (self, *args, **kwargs):
      '''
type( (Entity3d)arg1) -> EntityId :

    C++ signature :
        enum AcGe::EntityId type(class PyGeEntity3d {lvalue})'''
    ...

class LinearEnt2d:
    def __eq__ (self, *args, **kwargs):
      '''
__eq__( (Entity2d)arg1, (Entity2d)arg2) -> bool :

    C++ signature :
        bool __eq__(class PyGeEntity2d {lvalue},class PyGeEntity2d)'''
    ...
    def __init__ (self, *args, **kwargs):
      '''Raises an exception
This class cannot be instantiated from Python
'''
    ...
    def __ne__ (self, *args, **kwargs):
      '''
__ne__( (Entity2d)arg1, (Entity2d)arg2) -> bool :

    C++ signature :
        bool __ne__(class PyGeEntity2d {lvalue},class PyGeEntity2d)'''
    ...
    def area (self, *args, **kwargs):
      '''
area( (Curve2d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double area(class PyGeCurve2d {lvalue},double,double)

area( (Curve2d)arg1, (float)arg2, (float)arg3, (Tol)arg4) -> float :

    C++ signature :
        double area(class PyGeCurve2d {lvalue},double,double,class AcGeTol)'''
    ...
    def boundBlock (self, *args, **kwargs):
      '''
boundBlock( (Curve2d)arg1) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d boundBlock(class PyGeCurve2d {lvalue})

boundBlock( (Curve2d)arg1, (Interval)arg2) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d boundBlock(class PyGeCurve2d {lvalue},class PyGeInterval)'''
    ...
    def className (self, *args, **kwargs):
      '''
className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def closestPointTo (self, *args, **kwargs):
      '''
closestPointTo( (Curve2d)arg1, (Point2d)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d closestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d)

closestPointTo( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> Point2d :

    C++ signature :
        class AcGePoint2d closestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)

closestPointTo( (Curve2d)arg1, (Curve2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointTo(class PyGeCurve2d {lvalue},class PyGeCurve2d)

closestPointTo( (Curve2d)arg1, (Curve2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointTo(class PyGeCurve2d {lvalue},class PyGeCurve2d,class AcGeTol)'''
    ...
    def copy (self, *args, **kwargs):
      '''
copy( (Entity2d)arg1) -> Entity2d :

    C++ signature :
        class PyGeEntity2d copy(class PyGeEntity2d {lvalue})'''
    ...
    def direction (self, *args, **kwargs):
      '''
direction( (LinearEnt2d)arg1) -> Vector2d :

    C++ signature :
        class AcGeVector2d direction(class PyGeLinearEnt2d {lvalue})'''
    ...
    def distanceTo (self, *args, **kwargs):
      '''
distanceTo( (Curve2d)arg1, (Point2d)arg2) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class AcGePoint2d)

distanceTo( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)

distanceTo( (Curve2d)arg1, (Curve2d)arg2) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class PyGeCurve2d)

distanceTo( (Curve2d)arg1, (Curve2d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class PyGeCurve2d,class AcGeTol)'''
    ...
    def evalPoint (self, *args, **kwargs):
      '''
evalPoint( (Curve2d)arg1, (float)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d evalPoint(class PyGeCurve2d {lvalue},double)

evalPoint( (Curve2d)arg1, (float)arg2, (int)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple evalPoint(class PyGeCurve2d {lvalue},double,int)'''
    ...
    def explode (self, *args, **kwargs):
      '''
explode( (Curve2d)arg1) -> list :

    C++ signature :
        class boost::python::list explode(class PyGeCurve2d {lvalue})

explode( (Curve2d)arg1, (Interval)arg2) -> list :

    C++ signature :
        class boost::python::list explode(class PyGeCurve2d {lvalue},class PyGeInterval)'''
    ...
    def getClosestPointTo (self, *args, **kwargs):
      '''
getClosestPointTo( (Curve2d)arg1, (Point2d)arg2) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getClosestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d)

getClosestPointTo( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getClosestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def getClosestPointsTo (self, *args, **kwargs):
      '''
getClosestPointsTo( (Curve2d)arg1, (Curve2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getClosestPointsTo(class PyGeCurve2d {lvalue},class PyGeCurve2d)

getClosestPointsTo( (Curve2d)arg1, (Curve2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple getClosestPointsTo(class PyGeCurve2d {lvalue},class PyGeCurve2d,class AcGeTol)'''
    ...
    def getEndPoint (self, *args, **kwargs):
      '''
getEndPoint( (Curve2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d getEndPoint(class PyGeCurve2d {lvalue})'''
    ...
    def getInterval (self, *args, **kwargs):
      '''
getInterval( (Curve2d)arg1) -> Interval :

    C++ signature :
        class PyGeInterval getInterval(class PyGeCurve2d {lvalue})'''
    ...
    def getLine (self, *args, **kwargs):
      '''
getLine( (LinearEnt2d)arg1) -> Line2d :

    C++ signature :
        class PyGeLine2d getLine(class PyGeLinearEnt2d {lvalue})'''
    ...
    def getNormalPoint (self, *args, **kwargs):
      '''
getNormalPoint( (Curve2d)arg1, (Point2d)arg2) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getNormalPoint(class PyGeCurve2d {lvalue},class AcGePoint2d)

getNormalPoint( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getNormalPoint(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def getPerpLine (self, *args, **kwargs):
      '''
getPerpLine( (LinearEnt2d)arg1, (Point2d)arg2) -> Line2d :

    C++ signature :
        class PyGeLine2d getPerpLine(class PyGeLinearEnt2d {lvalue},class AcGePoint2d)'''
    ...
    def getSamplePoints (self, *args, **kwargs):
      '''
getSamplePoints( (Curve2d)arg1, (int)arg2) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve2d {lvalue},int)

getSamplePoints( (Curve2d)arg1, (float)arg2, (float)arg3, (float)arg4) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve2d {lvalue},double,double,double)'''
    ...
    def getSplitCurves (self, *args, **kwargs):
      '''
getSplitCurves( (Curve2d)arg1, (float)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getSplitCurves(class PyGeCurve2d {lvalue},double)'''
    ...
    def getStartPoint (self, *args, **kwargs):
      '''
getStartPoint( (Curve2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d getStartPoint(class PyGeCurve2d {lvalue})'''
    ...
    def getTrimmedOffset (self, *args, **kwargs):
      '''
getTrimmedOffset( (Curve2d)arg1, (float)arg2, (OffsetCrvExtType)arg3) -> list :

    C++ signature :
        class boost::python::list getTrimmedOffset(class PyGeCurve2d {lvalue},double,enum AcGe::OffsetCrvExtType)

getTrimmedOffset( (Curve2d)arg1, (float)arg2, (OffsetCrvExtType)arg3, (Tol)arg4) -> list :

    C++ signature :
        class boost::python::list getTrimmedOffset(class PyGeCurve2d {lvalue},double,enum AcGe::OffsetCrvExtType,class AcGeTol)'''
    ...
    def hasEndPoint (self, *args, **kwargs):
      '''
hasEndPoint( (Curve2d)arg1) -> bool :

    C++ signature :
        bool hasEndPoint(class PyGeCurve2d {lvalue})'''
    ...
    def hasStartPoint (self, *args, **kwargs):
      '''
hasStartPoint( (Curve2d)arg1) -> bool :

    C++ signature :
        bool hasStartPoint(class PyGeCurve2d {lvalue})'''
    ...
    def intersectWith (self, *args, **kwargs):
      '''
intersectWith( (LinearEnt2d)arg1, (LinearEnt2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple intersectWith(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d)

intersectWith( (LinearEnt2d)arg1, (LinearEnt2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple intersectWith(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d,class AcGeTol)'''
    ...
    def isClosed (self, *args, **kwargs):
      '''
isClosed( (Curve2d)arg1) -> bool :

    C++ signature :
        bool isClosed(class PyGeCurve2d {lvalue})

isClosed( (Curve2d)arg1, (Tol)arg2) -> bool :

    C++ signature :
        bool isClosed(class PyGeCurve2d {lvalue},class AcGeTol)'''
    ...
    def isColinearTo (self, *args, **kwargs):
      '''
isColinearTo( (LinearEnt2d)arg1, (LinearEnt2d)arg2) -> bool :

    C++ signature :
        bool isColinearTo(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d)

isColinearTo( (LinearEnt2d)arg1, (LinearEnt2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isColinearTo(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d,class AcGeTol)'''
    ...
    def isDegenerate (self, *args, **kwargs):
      '''
isDegenerate( (Curve2d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isDegenerate(class PyGeCurve2d {lvalue})

isDegenerate( (Curve2d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isDegenerate(class PyGeCurve2d {lvalue},class AcGeTol)'''
    ...
    def isEqualTo (self, *args, **kwargs):
      '''
isEqualTo( (Entity2d)arg1, (Entity2d)arg2) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity2d {lvalue},class PyGeEntity2d)

isEqualTo( (Entity2d)arg1, (Entity2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity2d {lvalue},class PyGeEntity2d,class AcGeTol)'''
    ...
    def isKindOf (self, *args, **kwargs):
      '''
isKindOf( (Entity2d)arg1, (EntityId)arg2) -> bool :

    C++ signature :
        bool isKindOf(class PyGeEntity2d {lvalue},enum AcGe::EntityId)'''
    ...
    def isLinear (self, *args, **kwargs):
      '''
isLinear( (Curve2d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isLinear(class PyGeCurve2d {lvalue})

isLinear( (Curve2d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isLinear(class PyGeCurve2d {lvalue},class AcGeTol)'''
    ...
    def isNull (self, *args, **kwargs):
      '''
isNull( (Entity2d)arg1) -> bool :

    C++ signature :
        bool isNull(class PyGeEntity2d {lvalue})'''
    ...
    def isOn (self, *args, **kwargs):
      '''
isOn( (Curve2d)arg1, (Point2d)arg2) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve2d {lvalue},class AcGePoint2d)

isOn( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)

isOn( (Curve2d)arg1, (Point2d)arg2, (float)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve2d {lvalue},class AcGePoint2d,double {lvalue})

isOn( (Curve2d)arg1, (Point2d)arg2, (float)arg3, (Tol)arg4) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve2d {lvalue},class AcGePoint2d,double {lvalue},class AcGeTol)

isOn( (Curve2d)arg1, (float)arg2) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve2d {lvalue},double)

isOn( (Curve2d)arg1, (float)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve2d {lvalue},double,class AcGeTol)'''
    ...
    def isParallelTo (self, *args, **kwargs):
      '''
isParallelTo( (LinearEnt2d)arg1, (LinearEnt2d)arg2) -> bool :

    C++ signature :
        bool isParallelTo(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d)

isParallelTo( (LinearEnt2d)arg1, (LinearEnt2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isParallelTo(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d,class AcGeTol)'''
    ...
    def isPeriodic (self, *args, **kwargs):
      '''
isPeriodic( (Curve2d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isPeriodic(class PyGeCurve2d {lvalue})'''
    ...
    def isPerpendicularTo (self, *args, **kwargs):
      '''
isPerpendicularTo( (LinearEnt2d)arg1, (LinearEnt2d)arg2) -> bool :

    C++ signature :
        bool isPerpendicularTo(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d)

isPerpendicularTo( (LinearEnt2d)arg1, (LinearEnt2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isPerpendicularTo(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d,class AcGeTol)'''
    ...
    def length (self, *args, **kwargs):
      '''
length( (Curve2d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double length(class PyGeCurve2d {lvalue},double,double)

length( (Curve2d)arg1, (float)arg2, (float)arg3, (float)arg4) -> float :

    C++ signature :
        double length(class PyGeCurve2d {lvalue},double,double,double)'''
    ...
    def mirror (self, *args, **kwargs):
      '''
mirror( (Entity2d)arg1, (Line2d)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} mirror(class PyGeEntity2d {lvalue},class PyGeLine2d)'''
    ...
    def orthoBoundBlock (self, *args, **kwargs):
      '''
orthoBoundBlock( (Curve2d)arg1) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d orthoBoundBlock(class PyGeCurve2d {lvalue})

orthoBoundBlock( (Curve2d)arg1, (Interval)arg2) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d orthoBoundBlock(class PyGeCurve2d {lvalue},class PyGeInterval)'''
    ...
    def overlap (self, *args, **kwargs):
      '''
overlap( (LinearEnt2d)arg1, (LinearEnt2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple overlap(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d)

overlap( (LinearEnt2d)arg1, (LinearEnt2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple overlap(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d,class AcGeTol)'''
    ...
    def paramAtLength (self, *args, **kwargs):
      '''
paramAtLength( (Curve2d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double paramAtLength(class PyGeCurve2d {lvalue},double,double)

paramAtLength( (Curve2d)arg1, (float)arg2, (float)arg3, (bool)arg4, (float)arg5) -> float :

    C++ signature :
        double paramAtLength(class PyGeCurve2d {lvalue},double,double,bool,double)'''
    ...
    def paramOf (self, *args, **kwargs):
      '''
paramOf( (Curve2d)arg1, (Point2d)arg2) -> float :

    C++ signature :
        double paramOf(class PyGeCurve2d {lvalue},class AcGePoint2d)

paramOf( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double paramOf(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def pointOnLine (self, *args, **kwargs):
      '''
pointOnLine( (LinearEnt2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d pointOnLine(class PyGeLinearEnt2d {lvalue})'''
    ...
    def reverseParam (self, *args, **kwargs):
      '''
reverseParam( (Curve2d)arg1) -> Curve2d :

    C++ signature :
        class PyGeCurve2d {lvalue} reverseParam(class PyGeCurve2d {lvalue})'''
    ...
    def rotateBy (self, *args, **kwargs):
      '''
rotateBy( (Entity2d)arg1, (float)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} rotateBy(class PyGeEntity2d {lvalue},double)

rotateBy( (Entity2d)arg1, (float)arg2, (Point2d)arg3) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} rotateBy(class PyGeEntity2d {lvalue},double,class AcGePoint2d)'''
    ...
    def scaleBy (self, *args, **kwargs):
      '''
scaleBy( (Entity2d)arg1, (float)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} scaleBy(class PyGeEntity2d {lvalue},double)

scaleBy( (Entity2d)arg1, (float)arg2, (Point2d)arg3) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} scaleBy(class PyGeEntity2d {lvalue},double,class AcGePoint2d)'''
    ...
    def setInterval (self, *args, **kwargs):
      '''
setInterval( (Curve2d)arg1) -> Curve2d :

    C++ signature :
        class PyGeCurve2d {lvalue} setInterval(class PyGeCurve2d {lvalue})

setInterval( (Curve2d)arg1, (Interval)arg2) -> bool :

    C++ signature :
        bool setInterval(class PyGeCurve2d {lvalue},class PyGeInterval)'''
    ...
    def transformBy (self, *args, **kwargs):
      '''
transformBy( (Entity2d)arg1, (Matrix2d)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} transformBy(class PyGeEntity2d {lvalue},class AcGeMatrix2d)'''
    ...
    def translateBy (self, *args, **kwargs):
      '''
translateBy( (Entity2d)arg1, (Vector2d)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} translateBy(class PyGeEntity2d {lvalue},class AcGeVector2d)'''
    ...
    def type (self, *args, **kwargs):
      '''
type( (Entity2d)arg1) -> EntityId :

    C++ signature :
        enum AcGe::EntityId type(class PyGeEntity2d {lvalue})'''
    ...

class LinearEnt3d:
    def __eq__ (self, *args, **kwargs):
      '''
__eq__( (Entity3d)arg1, (Entity3d)arg2) -> bool :

    C++ signature :
        bool __eq__(class PyGeEntity3d {lvalue},class PyGeEntity3d)'''
    ...
    def __init__ (self, *args, **kwargs):
      '''Raises an exception
This class cannot be instantiated from Python
'''
    ...
    def __ne__ (self, *args, **kwargs):
      '''
__ne__( (Entity3d)arg1, (Entity3d)arg2) -> bool :

    C++ signature :
        bool __ne__(class PyGeEntity3d {lvalue},class PyGeEntity3d)'''
    ...
    def area (self, *args, **kwargs):
      '''
area( (Curve3d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double area(class PyGeCurve3d {lvalue},double,double)

area( (Curve3d)arg1, (float)arg2, (float)arg3, (Tol)arg4) -> float :

    C++ signature :
        double area(class PyGeCurve3d {lvalue},double,double,class AcGeTol)'''
    ...
    def boundBlock (self, *args, **kwargs):
      '''
boundBlock( (Curve3d)arg1) -> BoundBlock3d :

    C++ signature :
        class PyGeBoundBlock3d boundBlock(class PyGeCurve3d {lvalue})

boundBlock( (Curve3d)arg1, (Interval)arg2) -> BoundBlock3d :

    C++ signature :
        class PyGeBoundBlock3d boundBlock(class PyGeCurve3d {lvalue},class PyGeInterval)'''
    ...
    def className (self, *args, **kwargs):
      '''
className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def closestPointTo (self, *args, **kwargs):
      '''
closestPointTo( (Curve3d)arg1, (Point3d)arg2) -> Point3d :

    C++ signature :
        class AcGePoint3d closestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d)

closestPointTo( (Curve3d)arg1, (Point3d)arg2, (Tol)arg3) -> Point3d :

    C++ signature :
        class AcGePoint3d closestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeTol)

closestPointTo( (Curve3d)arg1, (Curve3d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointTo(class PyGeCurve3d {lvalue},class PyGeCurve3d)

closestPointTo( (Curve3d)arg1, (Curve3d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointTo(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeTol)'''
    ...
    def copy (self, *args, **kwargs):
      '''
copy( (Entity3d)arg1) -> Entity3d :

    C++ signature :
        class PyGeEntity3d copy(class PyGeEntity3d {lvalue})'''
    ...
    def direction (self, *args, **kwargs):
      '''
direction( (LinearEnt3d)arg1) -> Vector3d :

    C++ signature :
        class AcGeVector3d direction(class PyGeLinearEnt3d {lvalue})'''
    ...
    def distanceTo (self, *args, **kwargs):
      '''
distanceTo( (Curve3d)arg1, (Point3d)arg2) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve3d {lvalue},class AcGePoint3d)

distanceTo( (Curve3d)arg1, (Point3d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeTol)

distanceTo( (Curve3d)arg1, (Curve3d)arg2) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve3d {lvalue},class PyGeCurve3d)

distanceTo( (Curve3d)arg1, (Curve3d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeTol)'''
    ...
    def evalPoint (self, *args, **kwargs):
      '''
evalPoint( (Curve3d)arg1, (float)arg2) -> Point3d :

    C++ signature :
        class AcGePoint3d evalPoint(class PyGeCurve3d {lvalue},double)

evalPoint( (Curve3d)arg1, (float)arg2, (int)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple evalPoint(class PyGeCurve3d {lvalue},double,int)'''
    ...
    def explode (self, *args, **kwargs):
      '''
explode( (Curve3d)arg1) -> list :

    C++ signature :
        class boost::python::list explode(class PyGeCurve3d {lvalue})

explode( (Curve3d)arg1, (Interval)arg2) -> list :

    C++ signature :
        class boost::python::list explode(class PyGeCurve3d {lvalue},class PyGeInterval)'''
    ...
    def getClosestPointTo (self, *args, **kwargs):
      '''
getClosestPointTo( (Curve3d)arg1, (Point3d)arg2) -> PointOnCurve3d :

    C++ signature :
        class PyGePointOnCurve3d getClosestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d)

getClosestPointTo( (Curve3d)arg1, (Point3d)arg2, (Tol)arg3) -> PointOnCurve3d :

    C++ signature :
        class PyGePointOnCurve3d getClosestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def getClosestPointsTo (self, *args, **kwargs):
      '''
getClosestPointsTo( (Curve3d)arg1, (Curve3d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getClosestPointsTo(class PyGeCurve3d {lvalue},class PyGeCurve3d)

getClosestPointsTo( (Curve3d)arg1, (Curve3d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple getClosestPointsTo(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeTol)'''
    ...
    def getEndPoint (self, *args, **kwargs):
      '''
getEndPoint( (Curve3d)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d getEndPoint(class PyGeCurve3d {lvalue})'''
    ...
    def getInterval (self, *args, **kwargs):
      '''
getInterval( (Curve3d)arg1) -> Interval :

    C++ signature :
        class PyGeInterval getInterval(class PyGeCurve3d {lvalue})'''
    ...
    def getLine (self, *args, **kwargs):
      '''
getLine( (LinearEnt3d)arg1) -> Line3d :

    C++ signature :
        class PyGeLine3d getLine(class PyGeLinearEnt3d {lvalue})'''
    ...
    def getNormalPoint (self, *args, **kwargs):
      '''
getNormalPoint( (Curve3d)arg1, (Point3d)arg2) -> PointOnCurve3d :

    C++ signature :
        class PyGePointOnCurve3d getNormalPoint(class PyGeCurve3d {lvalue},class AcGePoint3d)

getNormalPoint( (Curve3d)arg1, (Point3d)arg2, (Tol)arg3) -> PointOnCurve3d :

    C++ signature :
        class PyGePointOnCurve3d getNormalPoint(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def getPerpPlane (self, *args, **kwargs):
      '''
getPerpPlane( (LinearEnt3d)arg1, (Point3d)arg2) -> Plane :

    C++ signature :
        class PyGePlane getPerpPlane(class PyGeLinearEnt3d {lvalue},class AcGePoint3d)'''
    ...
    def getProjClosestPointTo (self, *args, **kwargs):
      '''
getProjClosestPointTo( (Curve3d)arg1, (Point3d)arg2, (Vector3d)arg3) -> PointOnCurve3d :

    C++ signature :
        class PyGePointOnCurve3d getProjClosestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeVector3d)

getProjClosestPointTo( (Curve3d)arg1, (Point3d)arg2, (Vector3d)arg3, (Tol)arg4) -> PointOnCurve3d :

    C++ signature :
        class PyGePointOnCurve3d getProjClosestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeVector3d,class AcGeTol)'''
    ...
    def getProjClosestPointsTo (self, *args, **kwargs):
      '''
getProjClosestPointsTo( (Curve3d)arg1, (Curve3d)arg2, (Vector3d)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple getProjClosestPointsTo(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeVector3d)

getProjClosestPointsTo( (Curve3d)arg1, (Curve3d)arg2, (Vector3d)arg3, (Tol)arg4) -> tuple :

    C++ signature :
        class boost::python::tuple getProjClosestPointsTo(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeVector3d,class AcGeTol)'''
    ...
    def getSamplePoints (self, *args, **kwargs):
      '''
getSamplePoints( (Curve3d)arg1, (int)arg2) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve3d {lvalue},int)

getSamplePoints( (Curve3d)arg1, (float)arg2, (float)arg3, (float)arg4) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve3d {lvalue},double,double,double)'''
    ...
    def getSplitCurves (self, *args, **kwargs):
      '''
getSplitCurves( (Curve3d)arg1, (float)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getSplitCurves(class PyGeCurve3d {lvalue},double)'''
    ...
    def getStartPoint (self, *args, **kwargs):
      '''
getStartPoint( (Curve3d)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d getStartPoint(class PyGeCurve3d {lvalue})'''
    ...
    def getTrimmedOffset (self, *args, **kwargs):
      '''
getTrimmedOffset( (Curve3d)arg1, (float)arg2, (Vector3d)arg3, (OffsetCrvExtType)arg4) -> list :

    C++ signature :
        class boost::python::list getTrimmedOffset(class PyGeCurve3d {lvalue},double,class AcGeVector3d,enum AcGe::OffsetCrvExtType)

getTrimmedOffset( (Curve3d)arg1, (float)arg2, (Vector3d)arg3, (OffsetCrvExtType)arg4, (Tol)arg5) -> list :

    C++ signature :
        class boost::python::list getTrimmedOffset(class PyGeCurve3d {lvalue},double,class AcGeVector3d,enum AcGe::OffsetCrvExtType,class AcGeTol)'''
    ...
    def hasEndPoint (self, *args, **kwargs):
      '''
hasEndPoint( (Curve3d)arg1) -> bool :

    C++ signature :
        bool hasEndPoint(class PyGeCurve3d {lvalue})'''
    ...
    def hasStartPoint (self, *args, **kwargs):
      '''
hasStartPoint( (Curve3d)arg1) -> bool :

    C++ signature :
        bool hasStartPoint(class PyGeCurve3d {lvalue})'''
    ...
    def intersectWith (self, *args, **kwargs):
      '''
intersectWith( (LinearEnt3d)arg1, (LinearEnt3d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple intersectWith(class PyGeLinearEnt3d {lvalue},class PyGeLinearEnt3d)

intersectWith( (LinearEnt3d)arg1, (LinearEnt3d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple intersectWith(class PyGeLinearEnt3d {lvalue},class PyGeLinearEnt3d,class AcGeTol)

intersectWith( (LinearEnt3d)arg1, (PlanarEnt)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple intersectWith(class PyGeLinearEnt3d {lvalue},class PyGePlanarEnt)

intersectWith( (LinearEnt3d)arg1, (PlanarEnt)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple intersectWith(class PyGeLinearEnt3d {lvalue},class PyGePlanarEnt,class AcGeTol)'''
    ...
    def isClosed (self, *args, **kwargs):
      '''
isClosed( (Curve3d)arg1) -> bool :

    C++ signature :
        bool isClosed(class PyGeCurve3d {lvalue})

isClosed( (Curve3d)arg1, (Tol)arg2) -> bool :

    C++ signature :
        bool isClosed(class PyGeCurve3d {lvalue},class AcGeTol)'''
    ...
    def isColinearTo (self, *args, **kwargs):
      '''
isColinearTo( (LinearEnt3d)arg1, (LinearEnt3d)arg2) -> bool :

    C++ signature :
        bool isColinearTo(class PyGeLinearEnt3d {lvalue},class PyGeLinearEnt3d)

isColinearTo( (LinearEnt3d)arg1, (LinearEnt3d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isColinearTo(class PyGeLinearEnt3d {lvalue},class PyGeLinearEnt3d,class AcGeTol)'''
    ...
    def isCoplanarWith (self, *args, **kwargs):
      '''
isCoplanarWith( (Curve3d)arg1, (Curve3d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isCoplanarWith(class PyGeCurve3d {lvalue},class PyGeCurve3d)

isCoplanarWith( (Curve3d)arg1, (Curve3d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple isCoplanarWith(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeTol)'''
    ...
    def isDegenerate (self, *args, **kwargs):
      '''
isDegenerate( (Curve3d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isDegenerate(class PyGeCurve3d {lvalue})

isDegenerate( (Curve3d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isDegenerate(class PyGeCurve3d {lvalue},class AcGeTol)'''
    ...
    def isEqualTo (self, *args, **kwargs):
      '''
isEqualTo( (Entity3d)arg1, (Entity3d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity3d {lvalue},class PyGeEntity3d,class AcGeTol)'''
    ...
    def isKindOf (self, *args, **kwargs):
      '''
isKindOf( (Entity3d)arg1, (EntityId)arg2) -> bool :

    C++ signature :
        bool isKindOf(class PyGeEntity3d {lvalue},enum AcGe::EntityId)'''
    ...
    def isLinear (self, *args, **kwargs):
      '''
isLinear( (Curve3d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isLinear(class PyGeCurve3d {lvalue})

isLinear( (Curve3d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isLinear(class PyGeCurve3d {lvalue},class AcGeTol)'''
    ...
    def isNull (self, *args, **kwargs):
      '''
isNull( (Entity3d)arg1) -> bool :

    C++ signature :
        bool isNull(class PyGeEntity3d {lvalue})'''
    ...
    def isOn (self, *args, **kwargs):
      '''
isOn( (LinearEnt3d)arg1, (Point3d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isOn(class PyGeLinearEnt3d {lvalue},class AcGePoint3d)

isOn( (LinearEnt3d)arg1, (Point3d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple isOn(class PyGeLinearEnt3d {lvalue},class AcGePoint3d,class AcGeTol)

isOn( (LinearEnt3d)arg1, (float)arg2) -> bool :

    C++ signature :
        bool isOn(class PyGeLinearEnt3d {lvalue},double)

isOn( (LinearEnt3d)arg1, (float)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeLinearEnt3d {lvalue},double,class AcGeTol)

isOn( (LinearEnt3d)arg1, (Plane)arg2) -> bool :

    C++ signature :
        bool isOn(class PyGeLinearEnt3d {lvalue},class PyGePlane)

isOn( (LinearEnt3d)arg1, (Plane)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeLinearEnt3d {lvalue},class PyGePlane,class AcGeTol)'''
    ...
    def isParallelTo (self, *args, **kwargs):
      '''
isParallelTo( (LinearEnt3d)arg1, (LinearEnt3d)arg2) -> bool :

    C++ signature :
        bool isParallelTo(class PyGeLinearEnt3d {lvalue},class PyGeLinearEnt3d)

isParallelTo( (LinearEnt3d)arg1, (LinearEnt3d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isParallelTo(class PyGeLinearEnt3d {lvalue},class PyGeLinearEnt3d,class AcGeTol)

isParallelTo( (LinearEnt3d)arg1, (PlanarEnt)arg2) -> bool :

    C++ signature :
        bool isParallelTo(class PyGeLinearEnt3d {lvalue},class PyGePlanarEnt)

isParallelTo( (LinearEnt3d)arg1, (PlanarEnt)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isParallelTo(class PyGeLinearEnt3d {lvalue},class PyGePlanarEnt,class AcGeTol)'''
    ...
    def isPeriodic (self, *args, **kwargs):
      '''
isPeriodic( (Curve3d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isPeriodic(class PyGeCurve3d {lvalue})'''
    ...
    def isPerpendicularTo (self, *args, **kwargs):
      '''
isPerpendicularTo( (LinearEnt3d)arg1, (LinearEnt3d)arg2) -> bool :

    C++ signature :
        bool isPerpendicularTo(class PyGeLinearEnt3d {lvalue},class PyGeLinearEnt3d)

isPerpendicularTo( (LinearEnt3d)arg1, (LinearEnt3d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isPerpendicularTo(class PyGeLinearEnt3d {lvalue},class PyGeLinearEnt3d,class AcGeTol)

isPerpendicularTo( (LinearEnt3d)arg1, (PlanarEnt)arg2) -> bool :

    C++ signature :
        bool isPerpendicularTo(class PyGeLinearEnt3d {lvalue},class PyGePlanarEnt)

isPerpendicularTo( (LinearEnt3d)arg1, (PlanarEnt)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isPerpendicularTo(class PyGeLinearEnt3d {lvalue},class PyGePlanarEnt,class AcGeTol)'''
    ...
    def isPlanar (self, *args, **kwargs):
      '''
isPlanar( (Curve3d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isPlanar(class PyGeCurve3d {lvalue})

isPlanar( (Curve3d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isPlanar(class PyGeCurve3d {lvalue},class AcGeTol)'''
    ...
    def length (self, *args, **kwargs):
      '''
length( (Curve3d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double length(class PyGeCurve3d {lvalue},double,double)

length( (Curve3d)arg1, (float)arg2, (float)arg3, (float)arg4) -> float :

    C++ signature :
        double length(class PyGeCurve3d {lvalue},double,double,double)'''
    ...
    def mirror (self, *args, **kwargs):
      '''
mirror( (Entity3d)arg1, (Plane)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} mirror(class PyGeEntity3d {lvalue},class PyGePlane)'''
    ...
    def orthoBoundBlock (self, *args, **kwargs):
      '''
orthoBoundBlock( (Curve3d)arg1) -> BoundBlock3d :

    C++ signature :
        class PyGeBoundBlock3d orthoBoundBlock(class PyGeCurve3d {lvalue})

orthoBoundBlock( (Curve3d)arg1, (Interval)arg2) -> BoundBlock3d :

    C++ signature :
        class PyGeBoundBlock3d orthoBoundBlock(class PyGeCurve3d {lvalue},class PyGeInterval)'''
    ...
    def orthoProject (self, *args, **kwargs):
      '''
orthoProject( (Curve3d)arg1, (Plane)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d orthoProject(class PyGeCurve3d {lvalue},class PyGePlane)

orthoProject( (Curve3d)arg1, (Plane)arg2, (Tol)arg3) -> Entity3d :

    C++ signature :
        class PyGeEntity3d orthoProject(class PyGeCurve3d {lvalue},class PyGePlane,class AcGeTol)'''
    ...
    def overlap (self, *args, **kwargs):
      '''
overlap( (LinearEnt3d)arg1, (LinearEnt3d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple overlap(class PyGeLinearEnt3d {lvalue},class PyGeLinearEnt3d)

overlap( (LinearEnt3d)arg1, (LinearEnt3d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple overlap(class PyGeLinearEnt3d {lvalue},class PyGeLinearEnt3d,class AcGeTol)'''
    ...
    def paramAtLength (self, *args, **kwargs):
      '''
paramAtLength( (Curve3d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double paramAtLength(class PyGeCurve3d {lvalue},double,double)

paramAtLength( (Curve3d)arg1, (float)arg2, (float)arg3, (bool)arg4, (float)arg5) -> float :

    C++ signature :
        double paramAtLength(class PyGeCurve3d {lvalue},double,double,bool,double)'''
    ...
    def paramOf (self, *args, **kwargs):
      '''
paramOf( (Curve3d)arg1, (Point3d)arg2) -> float :

    C++ signature :
        double paramOf(class PyGeCurve3d {lvalue},class AcGePoint3d)

paramOf( (Curve3d)arg1, (Point3d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double paramOf(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def pointOnLine (self, *args, **kwargs):
      '''
pointOnLine( (LinearEnt3d)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d pointOnLine(class PyGeLinearEnt3d {lvalue})'''
    ...
    def projClosestPointTo (self, *args, **kwargs):
      '''
projClosestPointTo( (Curve3d)arg1, (Point3d)arg2, (Vector3d)arg3) -> Point3d :

    C++ signature :
        class AcGePoint3d projClosestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeVector3d)

projClosestPointTo( (Curve3d)arg1, (Point3d)arg2, (Vector3d)arg3, (Tol)arg4) -> Point3d :

    C++ signature :
        class AcGePoint3d projClosestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeVector3d,class AcGeTol)'''
    ...
    def projClosestPointsTo (self, *args, **kwargs):
      '''
projClosestPointsTo( (Curve3d)arg1, (Curve3d)arg2, (Vector3d)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple projClosestPointsTo(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeVector3d)

projClosestPointsTo( (Curve3d)arg1, (Curve3d)arg2, (Vector3d)arg3, (Tol)arg4) -> tuple :

    C++ signature :
        class boost::python::tuple projClosestPointsTo(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeVector3d,class AcGeTol)'''
    ...
    def projIntersectWith (self, *args, **kwargs):
      '''
projIntersectWith( (LinearEnt3d)arg1, (LinearEnt3d)arg2, (Vector3d)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple projIntersectWith(class PyGeLinearEnt3d {lvalue},class PyGeLinearEnt3d,class AcGeVector3d)

projIntersectWith( (LinearEnt3d)arg1, (LinearEnt3d)arg2, (Vector3d)arg3, (Tol)arg4) -> tuple :

    C++ signature :
        class boost::python::tuple projIntersectWith(class PyGeLinearEnt3d {lvalue},class PyGeLinearEnt3d,class AcGeVector3d,class AcGeTol)'''
    ...
    def project (self, *args, **kwargs):
      '''
project( (Curve3d)arg1, (Plane)arg2, (Vector3d)arg3) -> Entity3d :

    C++ signature :
        class PyGeEntity3d project(class PyGeCurve3d {lvalue},class PyGePlane,class AcGeVector3d)

project( (Curve3d)arg1, (Plane)arg2, (Vector3d)arg3, (Tol)arg4) -> Entity3d :

    C++ signature :
        class PyGeEntity3d project(class PyGeCurve3d {lvalue},class PyGePlane,class AcGeVector3d,class AcGeTol)'''
    ...
    def reverseParam (self, *args, **kwargs):
      '''
reverseParam( (Curve3d)arg1) -> Curve3d :

    C++ signature :
        class PyGeCurve3d {lvalue} reverseParam(class PyGeCurve3d {lvalue})'''
    ...
    def rotateBy (self, *args, **kwargs):
      '''
rotateBy( (Entity3d)arg1, (float)arg2, (Vector3d)arg3) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} rotateBy(class PyGeEntity3d {lvalue},double,class AcGeVector3d)

rotateBy( (Entity3d)arg1, (float)arg2, (Vector3d)arg3, (Point3d)arg4) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} rotateBy(class PyGeEntity3d {lvalue},double,class AcGeVector3d,class AcGePoint3d)'''
    ...
    def scaleBy (self, *args, **kwargs):
      '''
scaleBy( (Entity3d)arg1, (float)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} scaleBy(class PyGeEntity3d {lvalue},double)

scaleBy( (Entity3d)arg1, (float)arg2, (Point3d)arg3) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} scaleBy(class PyGeEntity3d {lvalue},double,class AcGePoint3d)'''
    ...
    def setInterval (self, *args, **kwargs):
      '''
setInterval( (Curve3d)arg1) -> Curve3d :

    C++ signature :
        class PyGeCurve3d {lvalue} setInterval(class PyGeCurve3d {lvalue})

setInterval( (Curve3d)arg1, (Interval)arg2) -> bool :

    C++ signature :
        bool setInterval(class PyGeCurve3d {lvalue},class PyGeInterval)'''
    ...
    def transformBy (self, *args, **kwargs):
      '''
transformBy( (Entity3d)arg1, (Matrix3d)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} transformBy(class PyGeEntity3d {lvalue},class AcGeMatrix3d)'''
    ...
    def translateBy (self, *args, **kwargs):
      '''
translateBy( (Entity3d)arg1, (Vector3d)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} translateBy(class PyGeEntity3d {lvalue},class AcGeVector3d)'''
    ...
    def type (self, *args, **kwargs):
      '''
type( (Entity3d)arg1) -> EntityId :

    C++ signature :
        enum AcGe::EntityId type(class PyGeEntity3d {lvalue})'''
    ...

class Matrix2d:
    def __eq__ (self, *args, **kwargs):
      '''
__eq__( (Matrix2d)arg1, (Matrix2d)arg2) -> bool :

    C++ signature :
        bool __eq__(class AcGeMatrix2d {lvalue},class AcGeMatrix2d)'''
    ...
    def __imul__ (self, *args, **kwargs):
      '''
__imul__( (Matrix2d)arg1, (Matrix2d)arg2) -> Matrix2d :

    C++ signature :
        class AcGeMatrix2d {lvalue} __imul__(class AcGeMatrix2d {lvalue},class AcGeMatrix2d)'''
    ...
    def __init__ (self, *args, **kwargs):
      '''
__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
    ...
    def __matmul__ (self, *args, **kwargs):
      '''
__matmul__( (Matrix2d)arg1, (Matrix2d)arg2) -> Matrix2d :

    C++ signature :
        class AcGeMatrix2d __matmul__(class AcGeMatrix2d {lvalue},class AcGeMatrix2d)'''
    ...
    def __mul__ (self, *args, **kwargs):
      '''
__mul__( (Matrix2d)arg1, (Matrix2d)arg2) -> Matrix2d :

    C++ signature :
        class AcGeMatrix2d __mul__(class AcGeMatrix2d {lvalue},class AcGeMatrix2d)'''
    ...
    def __ne__ (self, *args, **kwargs):
      '''
__ne__( (Matrix2d)arg1, (Matrix2d)arg2) -> bool :

    C++ signature :
        bool __ne__(class AcGeMatrix2d {lvalue},class AcGeMatrix2d)'''
    ...
    def alignCoordSys (self, *args, **kwargs):
      '''
alignCoordSys( (Point2d)arg1, (Vector2d)arg2, (Vector2d)arg3, (Point2d)arg4, (Vector2d)arg5, (Vector2d)arg6) -> Matrix2d :

    C++ signature :
        class AcGeMatrix2d alignCoordSys(class AcGePoint2d,class AcGeVector2d,class AcGeVector2d,class AcGePoint2d,class AcGeVector2d,class AcGeVector2d)'''
    ...
    def det (self, *args, **kwargs):
      '''
det( (Matrix2d)arg1) -> float :

    C++ signature :
        double det(class AcGeMatrix2d {lvalue})'''
    ...
    def elementAt (self, *args, **kwargs):
      '''
elementAt( (Matrix2d)arg1, (int)arg2, (int)arg3) -> float :

    C++ signature :
        double elementAt(class AcGeMatrix2d {lvalue},unsigned int,unsigned int)'''
    ...
    def getCoordSystem (self, *args, **kwargs):
      '''
getCoordSystem( (Matrix2d)arg1, (Point2d)arg2, (Vector2d)arg3, (Vector2d)arg4) -> None :

    C++ signature :
        void getCoordSystem(class AcGeMatrix2d {lvalue},class AcGePoint2d {lvalue},class AcGeVector2d {lvalue},class AcGeVector2d {lvalue})'''
    ...
    def inverse (self, *args, **kwargs):
      '''
inverse( (Matrix2d)arg1) -> Matrix2d :

    C++ signature :
        class AcGeMatrix2d inverse(class AcGeMatrix2d {lvalue})'''
    ...
    def invert (self, *args, **kwargs):
      '''
invert( (Matrix2d)arg1) -> Matrix2d :

    C++ signature :
        class AcGeMatrix2d {lvalue} invert(class AcGeMatrix2d {lvalue})'''
    ...
    def isConformal (self, *args, **kwargs):
      '''
isConformal( (Matrix2d)arg1, (float)arg2, (float)arg3, (bool)arg4, (Vector2d)arg5) -> bool :

    C++ signature :
        bool isConformal(class AcGeMatrix2d {lvalue},double {lvalue},double {lvalue},bool {lvalue},class AcGeVector2d {lvalue})'''
    ...
    def isEqualTo (self, *args, **kwargs):
      '''
isEqualTo( (Matrix2d)arg1, (Matrix2d)arg2 [, (Tol)AcGeTol=<PyGe.Tol object at 0x0000020CE5B192D0>]) -> bool :

    C++ signature :
        bool isEqualTo(class AcGeMatrix2d {lvalue},class AcGeMatrix2d [,class AcGeTol=<PyGe.Tol object at 0x0000020CE5B192D0>])'''
    ...
    def isScaledOrtho (self, *args, **kwargs):
      '''
isScaledOrtho( (Matrix2d)arg1 [, (Tol)AcGeTol=<PyGe.Tol object at 0x0000020CE5B193F0>]) -> bool :

    C++ signature :
        bool isScaledOrtho(class AcGeMatrix2d {lvalue} [,class AcGeTol=<PyGe.Tol object at 0x0000020CE5B193F0>])'''
    ...
    def isSingular (self, *args, **kwargs):
      '''
isSingular( (Matrix2d)arg1, (Tol)arg2) -> bool :

    C++ signature :
        bool isSingular(class AcGeMatrix2d {lvalue},class AcGeTol)'''
    ...
    def isUniScaledOrtho (self, *args, **kwargs):
      '''
isUniScaledOrtho( (Matrix2d)arg1 [, (Tol)AcGeTol=<PyGe.Tol object at 0x0000020CE5B19360>]) -> bool :

    C++ signature :
        bool isUniScaledOrtho(class AcGeMatrix2d {lvalue} [,class AcGeTol=<PyGe.Tol object at 0x0000020CE5B19360>])'''
    ...
    def kIdentity (self, *args, **kwargs):
      '''None'''
    ...
    def mirroring (self, *args, **kwargs):
      '''
mirroring( (Point2d)arg1) -> Matrix2d :

    C++ signature :
        class AcGeMatrix2d mirroring(class AcGePoint2d)

mirroring( (object)arg1) -> Matrix2d :

    C++ signature :
        class AcGeMatrix2d mirroring(class AcGeLine2d)'''
    ...
    def postMultBy (self, *args, **kwargs):
      '''
postMultBy( (Matrix2d)arg1, (Matrix2d)arg2) -> Matrix2d :

    C++ signature :
        class AcGeMatrix2d {lvalue} postMultBy(class AcGeMatrix2d {lvalue},class AcGeMatrix2d)'''
    ...
    def preMultBy (self, *args, **kwargs):
      '''
preMultBy( (Matrix2d)arg1, (Matrix2d)arg2) -> Matrix2d :

    C++ signature :
        class AcGeMatrix2d {lvalue} preMultBy(class AcGeMatrix2d {lvalue},class AcGeMatrix2d)'''
    ...
    def rotation (self, *args, **kwargs):
      '''
rotation( (float)arg1, (Point2d)arg2) -> Matrix2d :

    C++ signature :
        class AcGeMatrix2d rotation(double,class AcGePoint2d)'''
    ...
    def scale (self, *args, **kwargs):
      '''
scale( (Matrix2d)arg1) -> float :

    C++ signature :
        double scale(class AcGeMatrix2d {lvalue})'''
    ...
    def scaling (self, *args, **kwargs):
      '''staticmethod(function) -> method

Convert a function to be a static method.

A static method does not receive an implicit first argument.
To declare a static method, use this idiom:

     class C:
         @staticmethod
         def f(arg1, arg2, ...):
             ...

It can be called either on the class (e.g. C.f()) or on an instance
(e.g. C().f()). Both the class and the instance are ignored, and
neither is passed implicitly as the first argument to the method.

Static methods in Python are similar to those found in Java or C++.
For a more advanced concept, see the classmethod builtin.'''
    ...
    def setCoordSystem (self, *args, **kwargs):
      '''
setCoordSystem( (Matrix2d)arg1, (Point2d)arg2, (Vector2d)arg3, (Vector2d)arg4) -> Matrix2d :

    C++ signature :
        class AcGeMatrix2d {lvalue} setCoordSystem(class AcGeMatrix2d {lvalue},class AcGePoint2d,class AcGeVector2d,class AcGeVector2d)'''
    ...
    def setToAlignCoordSys (self, *args, **kwargs):
      '''
setToAlignCoordSys( (Matrix2d)arg1, (Point2d)arg2, (Vector2d)arg3, (Vector2d)arg4, (Point2d)arg5, (Vector2d)arg6, (Vector2d)arg7) -> Matrix2d :

    C++ signature :
        class AcGeMatrix2d {lvalue} setToAlignCoordSys(class AcGeMatrix2d {lvalue},class AcGePoint2d,class AcGeVector2d,class AcGeVector2d,class AcGePoint2d,class AcGeVector2d,class AcGeVector2d)'''
    ...
    def setToIdentity (self, *args, **kwargs):
      '''
setToIdentity( (Matrix2d)arg1) -> Matrix2d :

    C++ signature :
        class AcGeMatrix2d {lvalue} setToIdentity(class AcGeMatrix2d {lvalue})'''
    ...
    def setToMirroring (self, *args, **kwargs):
      '''
setToMirroring( (Matrix2d)arg1, (Point2d)arg2) -> Matrix2d :

    C++ signature :
        class AcGeMatrix2d {lvalue} setToMirroring(class AcGeMatrix2d {lvalue},class AcGePoint2d)

setToMirroring( (Matrix2d)arg1, (object)arg2) -> Matrix2d :

    C++ signature :
        class AcGeMatrix2d {lvalue} setToMirroring(class AcGeMatrix2d {lvalue},class AcGeLine2d)'''
    ...
    def setToProduct (self, *args, **kwargs):
      '''
setToProduct( (Matrix2d)arg1, (Matrix2d)arg2, (Matrix2d)arg3) -> Matrix2d :

    C++ signature :
        class AcGeMatrix2d {lvalue} setToProduct(class AcGeMatrix2d {lvalue},class AcGeMatrix2d,class AcGeMatrix2d)'''
    ...
    def setToRotation (self, *args, **kwargs):
      '''
setToRotation( (Matrix2d)arg1, (float)arg2 [, (Point2d)AcGePoint2d=<PyGe.Point2d object at 0x0000020CE5AC6880>]) -> Matrix2d :

    C++ signature :
        class AcGeMatrix2d {lvalue} setToRotation(class AcGeMatrix2d {lvalue},double [,class AcGePoint2d=<PyGe.Point2d object at 0x0000020CE5AC6880>])'''
    ...
    def setToScaling (self, *args, **kwargs):
      '''
setToScaling( (Matrix2d)arg1, (float)arg2, (Point2d)arg3) -> Matrix2d :

    C++ signature :
        class AcGeMatrix2d {lvalue} setToScaling(class AcGeMatrix2d {lvalue},double,class AcGePoint2d)'''
    ...
    def setToTranslation (self, *args, **kwargs):
      '''
setToTranslation( (Matrix2d)arg1, (Vector2d)arg2) -> Matrix2d :

    C++ signature :
        class AcGeMatrix2d {lvalue} setToTranslation(class AcGeMatrix2d {lvalue},class AcGeVector2d)'''
    ...
    def setTranslation (self, *args, **kwargs):
      '''
setTranslation( (Matrix2d)arg1, (Vector2d)arg2) -> Matrix2d :

    C++ signature :
        class AcGeMatrix2d {lvalue} setTranslation(class AcGeMatrix2d {lvalue},class AcGeVector2d)'''
    ...
    def toString (self, *args, **kwargs):
      '''
toString( (Matrix2d)arg1) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > toString(class AcGeMatrix2d)'''
    ...
    def translation (self, *args, **kwargs):
      '''
translation( (Matrix2d)arg1) -> Vector2d :

    C++ signature :
        class AcGeVector2d translation(class AcGeMatrix2d {lvalue})

translation( (Vector2d)arg1) -> Matrix2d :

    C++ signature :
        class AcGeMatrix2d translation(class AcGeVector2d)'''
    ...
    def transpose (self, *args, **kwargs):
      '''
transpose( (Matrix2d)arg1) -> Matrix2d :

    C++ signature :
        class AcGeMatrix2d transpose(class AcGeMatrix2d {lvalue})'''
    ...
    def transposeIt (self, *args, **kwargs):
      '''
transposeIt( (Matrix2d)arg1) -> Matrix2d :

    C++ signature :
        class AcGeMatrix2d {lvalue} transposeIt(class AcGeMatrix2d {lvalue})'''
    ...

class Matrix3d:
    def __eq__ (self, *args, **kwargs):
      '''
__eq__( (Matrix3d)arg1, (Matrix3d)arg2) -> bool :

    C++ signature :
        bool __eq__(class AcGeMatrix3d {lvalue},class AcGeMatrix3d)'''
    ...
    def __imul__ (self, *args, **kwargs):
      '''
__imul__( (Matrix3d)arg1, (Matrix3d)arg2) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d {lvalue} __imul__(class AcGeMatrix3d {lvalue},class AcGeMatrix3d)'''
    ...
    def __init__ (self, *args, **kwargs):
      '''
__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1, (Matrix3d)arg2) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class AcGeMatrix3d)'''
    ...
    def __matmul__ (self, *args, **kwargs):
      '''
__matmul__( (Matrix3d)arg1, (Matrix3d)arg2) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d __matmul__(class AcGeMatrix3d {lvalue},class AcGeMatrix3d)'''
    ...
    def __mul__ (self, *args, **kwargs):
      '''
__mul__( (Matrix3d)arg1, (Matrix3d)arg2) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d __mul__(class AcGeMatrix3d {lvalue},class AcGeMatrix3d)'''
    ...
    def __ne__ (self, *args, **kwargs):
      '''
__ne__( (Matrix3d)arg1, (Matrix3d)arg2) -> bool :

    C++ signature :
        bool __ne__(class AcGeMatrix3d {lvalue},class AcGeMatrix3d)'''
    ...
    def alignCoordSys (self, *args, **kwargs):
      '''
alignCoordSys( (Point3d)arg1, (Vector3d)arg2, (Vector3d)arg3, (Vector3d)arg4, (Point3d)arg5, (Vector3d)arg6, (Vector3d)arg7, (Vector3d)arg8) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d alignCoordSys(class AcGePoint3d,class AcGeVector3d,class AcGeVector3d,class AcGeVector3d,class AcGePoint3d,class AcGeVector3d,class AcGeVector3d,class AcGeVector3d)'''
    ...
    def convertToLocal (self, *args, **kwargs):
      '''
convertToLocal( (Matrix3d)arg1, (Vector3d)arg2, (float)arg3) -> Matrix2d :

    C++ signature :
        class AcGeMatrix2d convertToLocal(class AcGeMatrix3d {lvalue},class AcGeVector3d {lvalue},double {lvalue})'''
    ...
    def det (self, *args, **kwargs):
      '''
det( (Matrix3d)arg1) -> float :

    C++ signature :
        double det(class AcGeMatrix3d {lvalue})'''
    ...
    def elementAt (self, *args, **kwargs):
      '''
elementAt( (Matrix3d)arg1, (int)arg2, (int)arg3) -> float :

    C++ signature :
        double elementAt(class AcGeMatrix3d {lvalue},unsigned int,unsigned int)'''
    ...
    def getCoordSystem (self, *args, **kwargs):
      '''
getCoordSystem( (Matrix3d)arg1, (Point3d)arg2, (Vector3d)arg3, (Vector3d)arg4, (Vector3d)arg5) -> None :

    C++ signature :
        void getCoordSystem(class AcGeMatrix3d {lvalue},class AcGePoint3d {lvalue},class AcGeVector3d {lvalue},class AcGeVector3d {lvalue},class AcGeVector3d {lvalue})'''
    ...
    def inverse (self, *args, **kwargs):
      '''
inverse( (Matrix3d)arg1) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d inverse(class AcGeMatrix3d {lvalue})

inverse( (Matrix3d)arg1, (Tol)arg2) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d inverse(class AcGeMatrix3d {lvalue},class AcGeTol)

inverse( (Matrix3d)arg1, (Matrix3d)arg2, (float)arg3) -> bool :

    C++ signature :
        bool inverse(class AcGeMatrix3d {lvalue},class AcGeMatrix3d {lvalue},double)'''
    ...
    def invert (self, *args, **kwargs):
      '''
invert( (Matrix3d)arg1) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d {lvalue} invert(class AcGeMatrix3d {lvalue})'''
    ...
    def isEqualTo (self, *args, **kwargs):
      '''
isEqualTo( (Matrix3d)arg1, (Matrix3d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isEqualTo(class AcGeMatrix3d {lvalue},class AcGeMatrix3d,class AcGeTol)'''
    ...
    def isScaledOrtho (self, *args, **kwargs):
      '''
isScaledOrtho( (Matrix3d)arg1, (Tol)arg2) -> bool :

    C++ signature :
        bool isScaledOrtho(class AcGeMatrix3d {lvalue},class AcGeTol)'''
    ...
    def isSingular (self, *args, **kwargs):
      '''
isSingular( (Matrix3d)arg1, (Tol)arg2) -> bool :

    C++ signature :
        bool isSingular(class AcGeMatrix3d {lvalue},class AcGeTol)'''
    ...
    def isUniScaledOrtho (self, *args, **kwargs):
      '''
isUniScaledOrtho( (Matrix3d)arg1, (Tol)arg2) -> bool :

    C++ signature :
        bool isUniScaledOrtho(class AcGeMatrix3d {lvalue},class AcGeTol)'''
    ...
    def kIdentity (self, *args, **kwargs):
      '''None'''
    ...
    def mirroring (self, *args, **kwargs):
      '''
mirroring( (object)arg1) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d mirroring(class AcGePlane)

mirroring( (Point3d)arg1) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d mirroring(class AcGePoint3d)

mirroring( (object)arg1) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d mirroring(class AcGeLine3d)'''
    ...
    def norm (self, *args, **kwargs):
      '''
norm( (Matrix3d)arg1) -> float :

    C++ signature :
        double norm(class AcGeMatrix3d {lvalue})'''
    ...
    def planeToWorld (self, *args, **kwargs):
      '''
planeToWorld( (Vector3d)arg1) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d planeToWorld(class AcGeVector3d)

planeToWorld( (object)arg1) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d planeToWorld(class AcGePlane)'''
    ...
    def postMultBy (self, *args, **kwargs):
      '''
postMultBy( (Matrix3d)arg1, (Matrix3d)arg2) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d {lvalue} postMultBy(class AcGeMatrix3d {lvalue},class AcGeMatrix3d)'''
    ...
    def preMultBy (self, *args, **kwargs):
      '''
preMultBy( (Matrix3d)arg1, (Matrix3d)arg2) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d {lvalue} preMultBy(class AcGeMatrix3d {lvalue},class AcGeMatrix3d)'''
    ...
    def projection (self, *args, **kwargs):
      '''
projection( (object)arg1, (Vector3d)arg2) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d projection(class AcGePlane,class AcGeVector3d)'''
    ...
    def rotation (self, *args, **kwargs):
      '''
rotation( (float)arg1, (Vector3d)arg2, (Point3d)arg3) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d rotation(double,class AcGeVector3d,class AcGePoint3d)'''
    ...
    def scale (self, *args, **kwargs):
      '''
scale( (Matrix3d)arg1) -> float :

    C++ signature :
        double scale(class AcGeMatrix3d {lvalue})'''
    ...
    def scaling (self, *args, **kwargs):
      '''
scaling( (float)arg1, (Point3d)arg2) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d scaling(double,class AcGePoint3d)'''
    ...
    def setCoordSystem (self, *args, **kwargs):
      '''
setCoordSystem( (Matrix3d)arg1, (Point3d)arg2, (Vector3d)arg3, (Vector3d)arg4, (Vector3d)arg5) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d {lvalue} setCoordSystem(class AcGeMatrix3d {lvalue},class AcGePoint3d,class AcGeVector3d,class AcGeVector3d,class AcGeVector3d)'''
    ...
    def setToAlignCoordSys (self, *args, **kwargs):
      '''
setToAlignCoordSys( (Matrix3d)arg1, (Point3d)arg2, (Vector3d)arg3, (Vector3d)arg4, (Vector3d)arg5, (Point3d)arg6, (Vector3d)arg7, (Vector3d)arg8, (Vector3d)arg9) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d {lvalue} setToAlignCoordSys(class AcGeMatrix3d {lvalue},class AcGePoint3d,class AcGeVector3d,class AcGeVector3d,class AcGeVector3d,class AcGePoint3d,class AcGeVector3d,class AcGeVector3d,class AcGeVector3d)'''
    ...
    def setToIdentity (self, *args, **kwargs):
      '''
setToIdentity( (Matrix3d)arg1) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d {lvalue} setToIdentity(class AcGeMatrix3d {lvalue})'''
    ...
    def setToMirroring (self, *args, **kwargs):
      '''
setToMirroring( (Matrix3d)arg1, (object)arg2) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d {lvalue} setToMirroring(class AcGeMatrix3d {lvalue},class AcGePlane)

setToMirroring( (Matrix3d)arg1, (object)arg2) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d {lvalue} setToMirroring(class AcGeMatrix3d {lvalue},class AcGeLine3d)

setToMirroring( (Matrix3d)arg1, (Point3d)arg2) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d {lvalue} setToMirroring(class AcGeMatrix3d {lvalue},class AcGePoint3d)'''
    ...
    def setToPlaneToWorld (self, *args, **kwargs):
      '''
setToPlaneToWorld( (Matrix3d)arg1, (object)arg2) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d {lvalue} setToPlaneToWorld(class AcGeMatrix3d {lvalue},class AcGePlane)

setToPlaneToWorld( (Matrix3d)arg1, (Vector3d)arg2) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d {lvalue} setToPlaneToWorld(class AcGeMatrix3d {lvalue},class AcGeVector3d)'''
    ...
    def setToProduct (self, *args, **kwargs):
      '''
setToProduct( (Matrix3d)arg1, (Matrix3d)arg2, (Matrix3d)arg3) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d {lvalue} setToProduct(class AcGeMatrix3d {lvalue},class AcGeMatrix3d,class AcGeMatrix3d)'''
    ...
    def setToProjection (self, *args, **kwargs):
      '''
setToProjection( (Matrix3d)arg1, (object)arg2, (Vector3d)arg3) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d {lvalue} setToProjection(class AcGeMatrix3d {lvalue},class AcGePlane,class AcGeVector3d)'''
    ...
    def setToRotation (self, *args, **kwargs):
      '''
setToRotation( (Matrix3d)arg1, (float)arg2, (Vector3d)arg3, (Point3d)arg4) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d {lvalue} setToRotation(class AcGeMatrix3d {lvalue},double,class AcGeVector3d,class AcGePoint3d)'''
    ...
    def setToScaling (self, *args, **kwargs):
      '''
setToScaling( (Matrix3d)arg1, (float)arg2, (Point3d)arg3) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d {lvalue} setToScaling(class AcGeMatrix3d {lvalue},double,class AcGePoint3d)'''
    ...
    def setToTranslation (self, *args, **kwargs):
      '''
setToTranslation( (Matrix3d)arg1, (Vector3d)arg2) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d {lvalue} setToTranslation(class AcGeMatrix3d {lvalue},class AcGeVector3d)'''
    ...
    def setToWorldToPlane (self, *args, **kwargs):
      '''
setToWorldToPlane( (Matrix3d)arg1, (object)arg2) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d {lvalue} setToWorldToPlane(class AcGeMatrix3d {lvalue},class AcGePlane)

setToWorldToPlane( (Matrix3d)arg1, (Vector3d)arg2) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d {lvalue} setToWorldToPlane(class AcGeMatrix3d {lvalue},class AcGeVector3d)'''
    ...
    def setTranslation (self, *args, **kwargs):
      '''
setTranslation( (Matrix3d)arg1, (Vector3d)arg2) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d {lvalue} setTranslation(class AcGeMatrix3d {lvalue},class AcGeVector3d)'''
    ...
    def toString (self, *args, **kwargs):
      '''
toString( (Matrix3d)arg1) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > toString(class AcGeMatrix3d)'''
    ...
    def translation (self, *args, **kwargs):
      '''
translation( (Matrix3d)arg1) -> Vector3d :

    C++ signature :
        class AcGeVector3d translation(class AcGeMatrix3d {lvalue})

translation( (Vector3d)arg1) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d translation(class AcGeVector3d)'''
    ...
    def transpose (self, *args, **kwargs):
      '''
transpose( (Matrix3d)arg1) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d transpose(class AcGeMatrix3d {lvalue})'''
    ...
    def transposeIt (self, *args, **kwargs):
      '''
transposeIt( (Matrix3d)arg1) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d {lvalue} transposeIt(class AcGeMatrix3d {lvalue})'''
    ...
    def worldToPlane (self, *args, **kwargs):
      '''
worldToPlane( (Vector3d)arg1) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d worldToPlane(class AcGeVector3d)

worldToPlane( (object)arg1) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d worldToPlane(class AcGePlane)'''
    ...

class NurbCurve2d:
    def __eq__ (self, *args, **kwargs):
      '''
__eq__( (Entity2d)arg1, (Entity2d)arg2) -> bool :

    C++ signature :
        bool __eq__(class PyGeEntity2d {lvalue},class PyGeEntity2d)'''
    ...
    def __init__ (self, *args, **kwargs):
      '''
__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
    ...
    def __ne__ (self, *args, **kwargs):
      '''
__ne__( (Entity2d)arg1, (Entity2d)arg2) -> bool :

    C++ signature :
        bool __ne__(class PyGeEntity2d {lvalue},class PyGeEntity2d)'''
    ...
    def area (self, *args, **kwargs):
      '''
area( (Curve2d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double area(class PyGeCurve2d {lvalue},double,double)

area( (Curve2d)arg1, (float)arg2, (float)arg3, (Tol)arg4) -> float :

    C++ signature :
        double area(class PyGeCurve2d {lvalue},double,double,class AcGeTol)'''
    ...
    def boundBlock (self, *args, **kwargs):
      '''
boundBlock( (Curve2d)arg1) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d boundBlock(class PyGeCurve2d {lvalue})

boundBlock( (Curve2d)arg1, (Interval)arg2) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d boundBlock(class PyGeCurve2d {lvalue},class PyGeInterval)'''
    ...
    def className (self, *args, **kwargs):
      '''
className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def closestPointTo (self, *args, **kwargs):
      '''
closestPointTo( (Curve2d)arg1, (Point2d)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d closestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d)

closestPointTo( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> Point2d :

    C++ signature :
        class AcGePoint2d closestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)

closestPointTo( (Curve2d)arg1, (Curve2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointTo(class PyGeCurve2d {lvalue},class PyGeCurve2d)

closestPointTo( (Curve2d)arg1, (Curve2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointTo(class PyGeCurve2d {lvalue},class PyGeCurve2d,class AcGeTol)'''
    ...
    def continuityAtKnot (self, *args, **kwargs):
      '''
continuityAtKnot( (SplineEnt2d)arg1, (int)arg2) -> int :

    C++ signature :
        int continuityAtKnot(class PyGeSplineEnt2d {lvalue},int)

continuityAtKnot( (SplineEnt2d)arg1, (int)arg2, (Tol)arg3) -> int :

    C++ signature :
        int continuityAtKnot(class PyGeSplineEnt2d {lvalue},int,class AcGeTol)'''
    ...
    def controlPointAt (self, *args, **kwargs):
      '''
controlPointAt( (SplineEnt2d)arg1, (int)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d controlPointAt(class PyGeSplineEnt2d {lvalue},int)'''
    ...
    def copy (self, *args, **kwargs):
      '''
copy( (Entity2d)arg1) -> Entity2d :

    C++ signature :
        class PyGeEntity2d copy(class PyGeEntity2d {lvalue})'''
    ...
    def degree (self, *args, **kwargs):
      '''
degree( (SplineEnt2d)arg1) -> int :

    C++ signature :
        int degree(class PyGeSplineEnt2d {lvalue})'''
    ...
    def distanceTo (self, *args, **kwargs):
      '''
distanceTo( (Curve2d)arg1, (Point2d)arg2) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class AcGePoint2d)

distanceTo( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)

distanceTo( (Curve2d)arg1, (Curve2d)arg2) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class PyGeCurve2d)

distanceTo( (Curve2d)arg1, (Curve2d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class PyGeCurve2d,class AcGeTol)'''
    ...
    def endParam (self, *args, **kwargs):
      '''
endParam( (SplineEnt2d)arg1) -> float :

    C++ signature :
        double endParam(class PyGeSplineEnt2d {lvalue})'''
    ...
    def endPoint (self, *args, **kwargs):
      '''
endPoint( (SplineEnt2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d endPoint(class PyGeSplineEnt2d {lvalue})'''
    ...
    def evalPoint (self, *args, **kwargs):
      '''
evalPoint( (Curve2d)arg1, (float)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d evalPoint(class PyGeCurve2d {lvalue},double)

evalPoint( (Curve2d)arg1, (float)arg2, (int)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple evalPoint(class PyGeCurve2d {lvalue},double,int)'''
    ...
    def explode (self, *args, **kwargs):
      '''
explode( (Curve2d)arg1) -> list :

    C++ signature :
        class boost::python::list explode(class PyGeCurve2d {lvalue})

explode( (Curve2d)arg1, (Interval)arg2) -> list :

    C++ signature :
        class boost::python::list explode(class PyGeCurve2d {lvalue},class PyGeInterval)'''
    ...
    def getClosestPointTo (self, *args, **kwargs):
      '''
getClosestPointTo( (Curve2d)arg1, (Point2d)arg2) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getClosestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d)

getClosestPointTo( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getClosestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def getClosestPointsTo (self, *args, **kwargs):
      '''
getClosestPointsTo( (Curve2d)arg1, (Curve2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getClosestPointsTo(class PyGeCurve2d {lvalue},class PyGeCurve2d)

getClosestPointsTo( (Curve2d)arg1, (Curve2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple getClosestPointsTo(class PyGeCurve2d {lvalue},class PyGeCurve2d,class AcGeTol)'''
    ...
    def getEndPoint (self, *args, **kwargs):
      '''
getEndPoint( (Curve2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d getEndPoint(class PyGeCurve2d {lvalue})'''
    ...
    def getInterval (self, *args, **kwargs):
      '''
getInterval( (Curve2d)arg1) -> Interval :

    C++ signature :
        class PyGeInterval getInterval(class PyGeCurve2d {lvalue})'''
    ...
    def getNormalPoint (self, *args, **kwargs):
      '''
getNormalPoint( (Curve2d)arg1, (Point2d)arg2) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getNormalPoint(class PyGeCurve2d {lvalue},class AcGePoint2d)

getNormalPoint( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getNormalPoint(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def getSamplePoints (self, *args, **kwargs):
      '''
getSamplePoints( (Curve2d)arg1, (int)arg2) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve2d {lvalue},int)

getSamplePoints( (Curve2d)arg1, (float)arg2, (float)arg3, (float)arg4) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve2d {lvalue},double,double,double)'''
    ...
    def getSplitCurves (self, *args, **kwargs):
      '''
getSplitCurves( (Curve2d)arg1, (float)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getSplitCurves(class PyGeCurve2d {lvalue},double)'''
    ...
    def getStartPoint (self, *args, **kwargs):
      '''
getStartPoint( (Curve2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d getStartPoint(class PyGeCurve2d {lvalue})'''
    ...
    def getTrimmedOffset (self, *args, **kwargs):
      '''
getTrimmedOffset( (Curve2d)arg1, (float)arg2, (OffsetCrvExtType)arg3) -> list :

    C++ signature :
        class boost::python::list getTrimmedOffset(class PyGeCurve2d {lvalue},double,enum AcGe::OffsetCrvExtType)

getTrimmedOffset( (Curve2d)arg1, (float)arg2, (OffsetCrvExtType)arg3, (Tol)arg4) -> list :

    C++ signature :
        class boost::python::list getTrimmedOffset(class PyGeCurve2d {lvalue},double,enum AcGe::OffsetCrvExtType,class AcGeTol)'''
    ...
    def hasEndPoint (self, *args, **kwargs):
      '''
hasEndPoint( (Curve2d)arg1) -> bool :

    C++ signature :
        bool hasEndPoint(class PyGeCurve2d {lvalue})'''
    ...
    def hasFitData (self, *args, **kwargs):
      '''
hasFitData( (SplineEnt2d)arg1) -> bool :

    C++ signature :
        bool hasFitData(class PyGeSplineEnt2d {lvalue})'''
    ...
    def hasStartPoint (self, *args, **kwargs):
      '''
hasStartPoint( (Curve2d)arg1) -> bool :

    C++ signature :
        bool hasStartPoint(class PyGeCurve2d {lvalue})'''
    ...
    def isClosed (self, *args, **kwargs):
      '''
isClosed( (Curve2d)arg1) -> bool :

    C++ signature :
        bool isClosed(class PyGeCurve2d {lvalue})

isClosed( (Curve2d)arg1, (Tol)arg2) -> bool :

    C++ signature :
        bool isClosed(class PyGeCurve2d {lvalue},class AcGeTol)'''
    ...
    def isDegenerate (self, *args, **kwargs):
      '''
isDegenerate( (Curve2d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isDegenerate(class PyGeCurve2d {lvalue})

isDegenerate( (Curve2d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isDegenerate(class PyGeCurve2d {lvalue},class AcGeTol)'''
    ...
    def isEqualTo (self, *args, **kwargs):
      '''
isEqualTo( (Entity2d)arg1, (Entity2d)arg2) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity2d {lvalue},class PyGeEntity2d)

isEqualTo( (Entity2d)arg1, (Entity2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity2d {lvalue},class PyGeEntity2d,class AcGeTol)'''
    ...
    def isKindOf (self, *args, **kwargs):
      '''
isKindOf( (Entity2d)arg1, (EntityId)arg2) -> bool :

    C++ signature :
        bool isKindOf(class PyGeEntity2d {lvalue},enum AcGe::EntityId)'''
    ...
    def isLinear (self, *args, **kwargs):
      '''
isLinear( (Curve2d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isLinear(class PyGeCurve2d {lvalue})

isLinear( (Curve2d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isLinear(class PyGeCurve2d {lvalue},class AcGeTol)'''
    ...
    def isNull (self, *args, **kwargs):
      '''
isNull( (Entity2d)arg1) -> bool :

    C++ signature :
        bool isNull(class PyGeEntity2d {lvalue})'''
    ...
    def isOn (self, *args, **kwargs):
      '''
isOn( (Curve2d)arg1, (Point2d)arg2) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve2d {lvalue},class AcGePoint2d)

isOn( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)

isOn( (Curve2d)arg1, (Point2d)arg2, (float)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve2d {lvalue},class AcGePoint2d,double {lvalue})

isOn( (Curve2d)arg1, (Point2d)arg2, (float)arg3, (Tol)arg4) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve2d {lvalue},class AcGePoint2d,double {lvalue},class AcGeTol)

isOn( (Curve2d)arg1, (float)arg2) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve2d {lvalue},double)

isOn( (Curve2d)arg1, (float)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve2d {lvalue},double,class AcGeTol)'''
    ...
    def isPeriodic (self, *args, **kwargs):
      '''
isPeriodic( (Curve2d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isPeriodic(class PyGeCurve2d {lvalue})'''
    ...
    def isRational (self, *args, **kwargs):
      '''
isRational( (SplineEnt2d)arg1) -> bool :

    C++ signature :
        bool isRational(class PyGeSplineEnt2d {lvalue})'''
    ...
    def knotAt (self, *args, **kwargs):
      '''
knotAt( (SplineEnt2d)arg1, (int)arg2) -> float :

    C++ signature :
        double knotAt(class PyGeSplineEnt2d {lvalue},int)'''
    ...
    def knots (self, *args, **kwargs):
      '''
knots( (SplineEnt2d)arg1) -> KnotVector :

    C++ signature :
        class PyGeKnotVector knots(class PyGeSplineEnt2d {lvalue})'''
    ...
    def length (self, *args, **kwargs):
      '''
length( (Curve2d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double length(class PyGeCurve2d {lvalue},double,double)

length( (Curve2d)arg1, (float)arg2, (float)arg3, (float)arg4) -> float :

    C++ signature :
        double length(class PyGeCurve2d {lvalue},double,double,double)'''
    ...
    def mirror (self, *args, **kwargs):
      '''
mirror( (Entity2d)arg1, (Line2d)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} mirror(class PyGeEntity2d {lvalue},class PyGeLine2d)'''
    ...
    def numControlPoints (self, *args, **kwargs):
      '''
numControlPoints( (SplineEnt2d)arg1) -> int :

    C++ signature :
        int numControlPoints(class PyGeSplineEnt2d {lvalue})'''
    ...
    def numKnots (self, *args, **kwargs):
      '''
numKnots( (SplineEnt2d)arg1) -> int :

    C++ signature :
        int numKnots(class PyGeSplineEnt2d {lvalue})'''
    ...
    def order (self, *args, **kwargs):
      '''
order( (SplineEnt2d)arg1) -> int :

    C++ signature :
        int order(class PyGeSplineEnt2d {lvalue})'''
    ...
    def orthoBoundBlock (self, *args, **kwargs):
      '''
orthoBoundBlock( (Curve2d)arg1) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d orthoBoundBlock(class PyGeCurve2d {lvalue})

orthoBoundBlock( (Curve2d)arg1, (Interval)arg2) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d orthoBoundBlock(class PyGeCurve2d {lvalue},class PyGeInterval)'''
    ...
    def paramAtLength (self, *args, **kwargs):
      '''
paramAtLength( (Curve2d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double paramAtLength(class PyGeCurve2d {lvalue},double,double)

paramAtLength( (Curve2d)arg1, (float)arg2, (float)arg3, (bool)arg4, (float)arg5) -> float :

    C++ signature :
        double paramAtLength(class PyGeCurve2d {lvalue},double,double,bool,double)'''
    ...
    def paramOf (self, *args, **kwargs):
      '''
paramOf( (Curve2d)arg1, (Point2d)arg2) -> float :

    C++ signature :
        double paramOf(class PyGeCurve2d {lvalue},class AcGePoint2d)

paramOf( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double paramOf(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def reverseParam (self, *args, **kwargs):
      '''
reverseParam( (Curve2d)arg1) -> Curve2d :

    C++ signature :
        class PyGeCurve2d {lvalue} reverseParam(class PyGeCurve2d {lvalue})'''
    ...
    def rotateBy (self, *args, **kwargs):
      '''
rotateBy( (Entity2d)arg1, (float)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} rotateBy(class PyGeEntity2d {lvalue},double)

rotateBy( (Entity2d)arg1, (float)arg2, (Point2d)arg3) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} rotateBy(class PyGeEntity2d {lvalue},double,class AcGePoint2d)'''
    ...
    def scaleBy (self, *args, **kwargs):
      '''
scaleBy( (Entity2d)arg1, (float)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} scaleBy(class PyGeEntity2d {lvalue},double)

scaleBy( (Entity2d)arg1, (float)arg2, (Point2d)arg3) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} scaleBy(class PyGeEntity2d {lvalue},double,class AcGePoint2d)'''
    ...
    def setControlPointAt (self, *args, **kwargs):
      '''
setControlPointAt( (SplineEnt2d)arg1, (int)arg2, (Point2d)arg3) -> SplineEnt2d :

    C++ signature :
        class PyGeSplineEnt2d {lvalue} setControlPointAt(class PyGeSplineEnt2d {lvalue},int,class AcGePoint2d)'''
    ...
    def setInterval (self, *args, **kwargs):
      '''
setInterval( (Curve2d)arg1) -> Curve2d :

    C++ signature :
        class PyGeCurve2d {lvalue} setInterval(class PyGeCurve2d {lvalue})

setInterval( (Curve2d)arg1, (Interval)arg2) -> bool :

    C++ signature :
        bool setInterval(class PyGeCurve2d {lvalue},class PyGeInterval)'''
    ...
    def setKnotAt (self, *args, **kwargs):
      '''
setKnotAt( (SplineEnt2d)arg1, (int)arg2, (float)arg3) -> SplineEnt2d :

    C++ signature :
        class PyGeSplineEnt2d {lvalue} setKnotAt(class PyGeSplineEnt2d {lvalue},int,double)'''
    ...
    def startParam (self, *args, **kwargs):
      '''
startParam( (SplineEnt2d)arg1) -> float :

    C++ signature :
        double startParam(class PyGeSplineEnt2d {lvalue})'''
    ...
    def startPoint (self, *args, **kwargs):
      '''
startPoint( (SplineEnt2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d startPoint(class PyGeSplineEnt2d {lvalue})'''
    ...
    def transformBy (self, *args, **kwargs):
      '''
transformBy( (Entity2d)arg1, (Matrix2d)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} transformBy(class PyGeEntity2d {lvalue},class AcGeMatrix2d)'''
    ...
    def translateBy (self, *args, **kwargs):
      '''
translateBy( (Entity2d)arg1, (Vector2d)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} translateBy(class PyGeEntity2d {lvalue},class AcGeVector2d)'''
    ...
    def type (self, *args, **kwargs):
      '''
type( (Entity2d)arg1) -> EntityId :

    C++ signature :
        enum AcGe::EntityId type(class PyGeEntity2d {lvalue})'''
    ...

class NurbCurve3d:
    def __eq__ (self, *args, **kwargs):
      '''
__eq__( (Entity3d)arg1, (Entity3d)arg2) -> bool :

    C++ signature :
        bool __eq__(class PyGeEntity3d {lvalue},class PyGeEntity3d)'''
    ...
    def __init__ (self, *args, **kwargs):
      '''
__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
    ...
    def __ne__ (self, *args, **kwargs):
      '''
__ne__( (Entity3d)arg1, (Entity3d)arg2) -> bool :

    C++ signature :
        bool __ne__(class PyGeEntity3d {lvalue},class PyGeEntity3d)'''
    ...
    def area (self, *args, **kwargs):
      '''
area( (Curve3d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double area(class PyGeCurve3d {lvalue},double,double)

area( (Curve3d)arg1, (float)arg2, (float)arg3, (Tol)arg4) -> float :

    C++ signature :
        double area(class PyGeCurve3d {lvalue},double,double,class AcGeTol)'''
    ...
    def boundBlock (self, *args, **kwargs):
      '''
boundBlock( (Curve3d)arg1) -> BoundBlock3d :

    C++ signature :
        class PyGeBoundBlock3d boundBlock(class PyGeCurve3d {lvalue})

boundBlock( (Curve3d)arg1, (Interval)arg2) -> BoundBlock3d :

    C++ signature :
        class PyGeBoundBlock3d boundBlock(class PyGeCurve3d {lvalue},class PyGeInterval)'''
    ...
    def className (self, *args, **kwargs):
      '''
className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def closestPointTo (self, *args, **kwargs):
      '''
closestPointTo( (Curve3d)arg1, (Point3d)arg2) -> Point3d :

    C++ signature :
        class AcGePoint3d closestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d)

closestPointTo( (Curve3d)arg1, (Point3d)arg2, (Tol)arg3) -> Point3d :

    C++ signature :
        class AcGePoint3d closestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeTol)

closestPointTo( (Curve3d)arg1, (Curve3d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointTo(class PyGeCurve3d {lvalue},class PyGeCurve3d)

closestPointTo( (Curve3d)arg1, (Curve3d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointTo(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeTol)'''
    ...
    def continuityAtKnot (self, *args, **kwargs):
      '''
continuityAtKnot( (SplineEnt3d)arg1, (int)arg2) -> int :

    C++ signature :
        int continuityAtKnot(class PyGeSplineEnt3d {lvalue},int)

continuityAtKnot( (SplineEnt3d)arg1, (int)arg2, (Tol)arg3) -> int :

    C++ signature :
        int continuityAtKnot(class PyGeSplineEnt3d {lvalue},int,class AcGeTol)'''
    ...
    def controlPointAt (self, *args, **kwargs):
      '''
controlPointAt( (SplineEnt3d)arg1, (int)arg2) -> Point3d :

    C++ signature :
        class AcGePoint3d controlPointAt(class PyGeSplineEnt3d {lvalue},int)'''
    ...
    def copy (self, *args, **kwargs):
      '''
copy( (Entity3d)arg1) -> Entity3d :

    C++ signature :
        class PyGeEntity3d copy(class PyGeEntity3d {lvalue})'''
    ...
    def degree (self, *args, **kwargs):
      '''
degree( (SplineEnt3d)arg1) -> int :

    C++ signature :
        int degree(class PyGeSplineEnt3d {lvalue})'''
    ...
    def distanceTo (self, *args, **kwargs):
      '''
distanceTo( (Curve3d)arg1, (Point3d)arg2) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve3d {lvalue},class AcGePoint3d)

distanceTo( (Curve3d)arg1, (Point3d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeTol)

distanceTo( (Curve3d)arg1, (Curve3d)arg2) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve3d {lvalue},class PyGeCurve3d)

distanceTo( (Curve3d)arg1, (Curve3d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeTol)'''
    ...
    def endParam (self, *args, **kwargs):
      '''
endParam( (SplineEnt3d)arg1) -> float :

    C++ signature :
        double endParam(class PyGeSplineEnt3d {lvalue})'''
    ...
    def endPoint (self, *args, **kwargs):
      '''
endPoint( (SplineEnt3d)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d endPoint(class PyGeSplineEnt3d {lvalue})'''
    ...
    def evalPoint (self, *args, **kwargs):
      '''
evalPoint( (Curve3d)arg1, (float)arg2) -> Point3d :

    C++ signature :
        class AcGePoint3d evalPoint(class PyGeCurve3d {lvalue},double)

evalPoint( (Curve3d)arg1, (float)arg2, (int)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple evalPoint(class PyGeCurve3d {lvalue},double,int)'''
    ...
    def explode (self, *args, **kwargs):
      '''
explode( (Curve3d)arg1) -> list :

    C++ signature :
        class boost::python::list explode(class PyGeCurve3d {lvalue})

explode( (Curve3d)arg1, (Interval)arg2) -> list :

    C++ signature :
        class boost::python::list explode(class PyGeCurve3d {lvalue},class PyGeInterval)'''
    ...
    def getClosestPointTo (self, *args, **kwargs):
      '''
getClosestPointTo( (Curve3d)arg1, (Point3d)arg2) -> PointOnCurve3d :

    C++ signature :
        class PyGePointOnCurve3d getClosestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d)

getClosestPointTo( (Curve3d)arg1, (Point3d)arg2, (Tol)arg3) -> PointOnCurve3d :

    C++ signature :
        class PyGePointOnCurve3d getClosestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def getClosestPointsTo (self, *args, **kwargs):
      '''
getClosestPointsTo( (Curve3d)arg1, (Curve3d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getClosestPointsTo(class PyGeCurve3d {lvalue},class PyGeCurve3d)

getClosestPointsTo( (Curve3d)arg1, (Curve3d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple getClosestPointsTo(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeTol)'''
    ...
    def getEndPoint (self, *args, **kwargs):
      '''
getEndPoint( (Curve3d)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d getEndPoint(class PyGeCurve3d {lvalue})'''
    ...
    def getInterval (self, *args, **kwargs):
      '''
getInterval( (Curve3d)arg1) -> Interval :

    C++ signature :
        class PyGeInterval getInterval(class PyGeCurve3d {lvalue})'''
    ...
    def getNormalPoint (self, *args, **kwargs):
      '''
getNormalPoint( (Curve3d)arg1, (Point3d)arg2) -> PointOnCurve3d :

    C++ signature :
        class PyGePointOnCurve3d getNormalPoint(class PyGeCurve3d {lvalue},class AcGePoint3d)

getNormalPoint( (Curve3d)arg1, (Point3d)arg2, (Tol)arg3) -> PointOnCurve3d :

    C++ signature :
        class PyGePointOnCurve3d getNormalPoint(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def getProjClosestPointTo (self, *args, **kwargs):
      '''
getProjClosestPointTo( (Curve3d)arg1, (Point3d)arg2, (Vector3d)arg3) -> PointOnCurve3d :

    C++ signature :
        class PyGePointOnCurve3d getProjClosestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeVector3d)

getProjClosestPointTo( (Curve3d)arg1, (Point3d)arg2, (Vector3d)arg3, (Tol)arg4) -> PointOnCurve3d :

    C++ signature :
        class PyGePointOnCurve3d getProjClosestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeVector3d,class AcGeTol)'''
    ...
    def getProjClosestPointsTo (self, *args, **kwargs):
      '''
getProjClosestPointsTo( (Curve3d)arg1, (Curve3d)arg2, (Vector3d)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple getProjClosestPointsTo(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeVector3d)

getProjClosestPointsTo( (Curve3d)arg1, (Curve3d)arg2, (Vector3d)arg3, (Tol)arg4) -> tuple :

    C++ signature :
        class boost::python::tuple getProjClosestPointsTo(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeVector3d,class AcGeTol)'''
    ...
    def getSamplePoints (self, *args, **kwargs):
      '''
getSamplePoints( (Curve3d)arg1, (int)arg2) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve3d {lvalue},int)

getSamplePoints( (Curve3d)arg1, (float)arg2, (float)arg3, (float)arg4) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve3d {lvalue},double,double,double)'''
    ...
    def getSplitCurves (self, *args, **kwargs):
      '''
getSplitCurves( (Curve3d)arg1, (float)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getSplitCurves(class PyGeCurve3d {lvalue},double)'''
    ...
    def getStartPoint (self, *args, **kwargs):
      '''
getStartPoint( (Curve3d)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d getStartPoint(class PyGeCurve3d {lvalue})'''
    ...
    def getTrimmedOffset (self, *args, **kwargs):
      '''
getTrimmedOffset( (Curve3d)arg1, (float)arg2, (Vector3d)arg3, (OffsetCrvExtType)arg4) -> list :

    C++ signature :
        class boost::python::list getTrimmedOffset(class PyGeCurve3d {lvalue},double,class AcGeVector3d,enum AcGe::OffsetCrvExtType)

getTrimmedOffset( (Curve3d)arg1, (float)arg2, (Vector3d)arg3, (OffsetCrvExtType)arg4, (Tol)arg5) -> list :

    C++ signature :
        class boost::python::list getTrimmedOffset(class PyGeCurve3d {lvalue},double,class AcGeVector3d,enum AcGe::OffsetCrvExtType,class AcGeTol)'''
    ...
    def hasEndPoint (self, *args, **kwargs):
      '''
hasEndPoint( (Curve3d)arg1) -> bool :

    C++ signature :
        bool hasEndPoint(class PyGeCurve3d {lvalue})'''
    ...
    def hasFitData (self, *args, **kwargs):
      '''
hasFitData( (SplineEnt3d)arg1) -> bool :

    C++ signature :
        bool hasFitData(class PyGeSplineEnt3d {lvalue})'''
    ...
    def hasStartPoint (self, *args, **kwargs):
      '''
hasStartPoint( (Curve3d)arg1) -> bool :

    C++ signature :
        bool hasStartPoint(class PyGeCurve3d {lvalue})'''
    ...
    def isClosed (self, *args, **kwargs):
      '''
isClosed( (Curve3d)arg1) -> bool :

    C++ signature :
        bool isClosed(class PyGeCurve3d {lvalue})

isClosed( (Curve3d)arg1, (Tol)arg2) -> bool :

    C++ signature :
        bool isClosed(class PyGeCurve3d {lvalue},class AcGeTol)'''
    ...
    def isCoplanarWith (self, *args, **kwargs):
      '''
isCoplanarWith( (Curve3d)arg1, (Curve3d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isCoplanarWith(class PyGeCurve3d {lvalue},class PyGeCurve3d)

isCoplanarWith( (Curve3d)arg1, (Curve3d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple isCoplanarWith(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeTol)'''
    ...
    def isDegenerate (self, *args, **kwargs):
      '''
isDegenerate( (Curve3d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isDegenerate(class PyGeCurve3d {lvalue})

isDegenerate( (Curve3d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isDegenerate(class PyGeCurve3d {lvalue},class AcGeTol)'''
    ...
    def isEqualTo (self, *args, **kwargs):
      '''
isEqualTo( (Entity3d)arg1, (Entity3d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity3d {lvalue},class PyGeEntity3d,class AcGeTol)'''
    ...
    def isKindOf (self, *args, **kwargs):
      '''
isKindOf( (Entity3d)arg1, (EntityId)arg2) -> bool :

    C++ signature :
        bool isKindOf(class PyGeEntity3d {lvalue},enum AcGe::EntityId)'''
    ...
    def isLinear (self, *args, **kwargs):
      '''
isLinear( (Curve3d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isLinear(class PyGeCurve3d {lvalue})

isLinear( (Curve3d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isLinear(class PyGeCurve3d {lvalue},class AcGeTol)'''
    ...
    def isNull (self, *args, **kwargs):
      '''
isNull( (Entity3d)arg1) -> bool :

    C++ signature :
        bool isNull(class PyGeEntity3d {lvalue})'''
    ...
    def isOn (self, *args, **kwargs):
      '''
isOn( (Curve3d)arg1, (Point3d)arg2) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve3d {lvalue},class AcGePoint3d)

isOn( (Curve3d)arg1, (Point3d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeTol)

isOn( (Curve3d)arg1, (Point3d)arg2, (float)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve3d {lvalue},class AcGePoint3d,double {lvalue})

isOn( (Curve3d)arg1, (Point3d)arg2, (float)arg3, (Tol)arg4) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve3d {lvalue},class AcGePoint3d,double {lvalue},class AcGeTol)

isOn( (Curve3d)arg1, (float)arg2) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve3d {lvalue},double)

isOn( (Curve3d)arg1, (float)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve3d {lvalue},double,class AcGeTol)'''
    ...
    def isPeriodic (self, *args, **kwargs):
      '''
isPeriodic( (Curve3d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isPeriodic(class PyGeCurve3d {lvalue})'''
    ...
    def isPlanar (self, *args, **kwargs):
      '''
isPlanar( (Curve3d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isPlanar(class PyGeCurve3d {lvalue})

isPlanar( (Curve3d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isPlanar(class PyGeCurve3d {lvalue},class AcGeTol)'''
    ...
    def isRational (self, *args, **kwargs):
      '''
isRational( (SplineEnt3d)arg1) -> bool :

    C++ signature :
        bool isRational(class PyGeSplineEnt3d {lvalue})'''
    ...
    def knotAt (self, *args, **kwargs):
      '''
knotAt( (SplineEnt3d)arg1, (int)arg2) -> float :

    C++ signature :
        double knotAt(class PyGeSplineEnt3d {lvalue},int)'''
    ...
    def knots (self, *args, **kwargs):
      '''
knots( (SplineEnt3d)arg1) -> KnotVector :

    C++ signature :
        class PyGeKnotVector knots(class PyGeSplineEnt3d {lvalue})'''
    ...
    def length (self, *args, **kwargs):
      '''
length( (Curve3d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double length(class PyGeCurve3d {lvalue},double,double)

length( (Curve3d)arg1, (float)arg2, (float)arg3, (float)arg4) -> float :

    C++ signature :
        double length(class PyGeCurve3d {lvalue},double,double,double)'''
    ...
    def mirror (self, *args, **kwargs):
      '''
mirror( (Entity3d)arg1, (Plane)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} mirror(class PyGeEntity3d {lvalue},class PyGePlane)'''
    ...
    def numControlPoints (self, *args, **kwargs):
      '''
numControlPoints( (SplineEnt3d)arg1) -> int :

    C++ signature :
        int numControlPoints(class PyGeSplineEnt3d {lvalue})'''
    ...
    def numKnots (self, *args, **kwargs):
      '''
numKnots( (SplineEnt3d)arg1) -> int :

    C++ signature :
        int numKnots(class PyGeSplineEnt3d {lvalue})'''
    ...
    def order (self, *args, **kwargs):
      '''
order( (SplineEnt3d)arg1) -> int :

    C++ signature :
        int order(class PyGeSplineEnt3d {lvalue})'''
    ...
    def orthoBoundBlock (self, *args, **kwargs):
      '''
orthoBoundBlock( (Curve3d)arg1) -> BoundBlock3d :

    C++ signature :
        class PyGeBoundBlock3d orthoBoundBlock(class PyGeCurve3d {lvalue})

orthoBoundBlock( (Curve3d)arg1, (Interval)arg2) -> BoundBlock3d :

    C++ signature :
        class PyGeBoundBlock3d orthoBoundBlock(class PyGeCurve3d {lvalue},class PyGeInterval)'''
    ...
    def orthoProject (self, *args, **kwargs):
      '''
orthoProject( (Curve3d)arg1, (Plane)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d orthoProject(class PyGeCurve3d {lvalue},class PyGePlane)

orthoProject( (Curve3d)arg1, (Plane)arg2, (Tol)arg3) -> Entity3d :

    C++ signature :
        class PyGeEntity3d orthoProject(class PyGeCurve3d {lvalue},class PyGePlane,class AcGeTol)'''
    ...
    def paramAtLength (self, *args, **kwargs):
      '''
paramAtLength( (Curve3d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double paramAtLength(class PyGeCurve3d {lvalue},double,double)

paramAtLength( (Curve3d)arg1, (float)arg2, (float)arg3, (bool)arg4, (float)arg5) -> float :

    C++ signature :
        double paramAtLength(class PyGeCurve3d {lvalue},double,double,bool,double)'''
    ...
    def paramOf (self, *args, **kwargs):
      '''
paramOf( (Curve3d)arg1, (Point3d)arg2) -> float :

    C++ signature :
        double paramOf(class PyGeCurve3d {lvalue},class AcGePoint3d)

paramOf( (Curve3d)arg1, (Point3d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double paramOf(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def projClosestPointTo (self, *args, **kwargs):
      '''
projClosestPointTo( (Curve3d)arg1, (Point3d)arg2, (Vector3d)arg3) -> Point3d :

    C++ signature :
        class AcGePoint3d projClosestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeVector3d)

projClosestPointTo( (Curve3d)arg1, (Point3d)arg2, (Vector3d)arg3, (Tol)arg4) -> Point3d :

    C++ signature :
        class AcGePoint3d projClosestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeVector3d,class AcGeTol)'''
    ...
    def projClosestPointsTo (self, *args, **kwargs):
      '''
projClosestPointsTo( (Curve3d)arg1, (Curve3d)arg2, (Vector3d)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple projClosestPointsTo(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeVector3d)

projClosestPointsTo( (Curve3d)arg1, (Curve3d)arg2, (Vector3d)arg3, (Tol)arg4) -> tuple :

    C++ signature :
        class boost::python::tuple projClosestPointsTo(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeVector3d,class AcGeTol)'''
    ...
    def project (self, *args, **kwargs):
      '''
project( (Curve3d)arg1, (Plane)arg2, (Vector3d)arg3) -> Entity3d :

    C++ signature :
        class PyGeEntity3d project(class PyGeCurve3d {lvalue},class PyGePlane,class AcGeVector3d)

project( (Curve3d)arg1, (Plane)arg2, (Vector3d)arg3, (Tol)arg4) -> Entity3d :

    C++ signature :
        class PyGeEntity3d project(class PyGeCurve3d {lvalue},class PyGePlane,class AcGeVector3d,class AcGeTol)'''
    ...
    def reverseParam (self, *args, **kwargs):
      '''
reverseParam( (Curve3d)arg1) -> Curve3d :

    C++ signature :
        class PyGeCurve3d {lvalue} reverseParam(class PyGeCurve3d {lvalue})'''
    ...
    def rotateBy (self, *args, **kwargs):
      '''
rotateBy( (Entity3d)arg1, (float)arg2, (Vector3d)arg3) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} rotateBy(class PyGeEntity3d {lvalue},double,class AcGeVector3d)

rotateBy( (Entity3d)arg1, (float)arg2, (Vector3d)arg3, (Point3d)arg4) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} rotateBy(class PyGeEntity3d {lvalue},double,class AcGeVector3d,class AcGePoint3d)'''
    ...
    def scaleBy (self, *args, **kwargs):
      '''
scaleBy( (Entity3d)arg1, (float)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} scaleBy(class PyGeEntity3d {lvalue},double)

scaleBy( (Entity3d)arg1, (float)arg2, (Point3d)arg3) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} scaleBy(class PyGeEntity3d {lvalue},double,class AcGePoint3d)'''
    ...
    def setControlPointAt (self, *args, **kwargs):
      '''
setControlPointAt( (SplineEnt3d)arg1, (int)arg2, (Point3d)arg3) -> SplineEnt3d :

    C++ signature :
        class PyGeSplineEnt3d {lvalue} setControlPointAt(class PyGeSplineEnt3d {lvalue},int,class AcGePoint3d)'''
    ...
    def setInterval (self, *args, **kwargs):
      '''
setInterval( (Curve3d)arg1) -> Curve3d :

    C++ signature :
        class PyGeCurve3d {lvalue} setInterval(class PyGeCurve3d {lvalue})

setInterval( (Curve3d)arg1, (Interval)arg2) -> bool :

    C++ signature :
        bool setInterval(class PyGeCurve3d {lvalue},class PyGeInterval)'''
    ...
    def setKnotAt (self, *args, **kwargs):
      '''
setKnotAt( (SplineEnt3d)arg1, (int)arg2, (float)arg3) -> SplineEnt3d :

    C++ signature :
        class PyGeSplineEnt3d {lvalue} setKnotAt(class PyGeSplineEnt3d {lvalue},int,double)'''
    ...
    def startParam (self, *args, **kwargs):
      '''
startParam( (SplineEnt3d)arg1) -> float :

    C++ signature :
        double startParam(class PyGeSplineEnt3d {lvalue})'''
    ...
    def startPoint (self, *args, **kwargs):
      '''
startPoint( (SplineEnt3d)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d startPoint(class PyGeSplineEnt3d {lvalue})'''
    ...
    def transformBy (self, *args, **kwargs):
      '''
transformBy( (Entity3d)arg1, (Matrix3d)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} transformBy(class PyGeEntity3d {lvalue},class AcGeMatrix3d)'''
    ...
    def translateBy (self, *args, **kwargs):
      '''
translateBy( (Entity3d)arg1, (Vector3d)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} translateBy(class PyGeEntity3d {lvalue},class AcGeVector3d)'''
    ...
    def type (self, *args, **kwargs):
      '''
type( (Entity3d)arg1) -> EntityId :

    C++ signature :
        enum AcGe::EntityId type(class PyGeEntity3d {lvalue})'''
    ...

class OffsetCrvExtType:
    def __add__ (self, value, /):
      '''Return self+value.'''
    ...
    def __eq__ (self, value, /):
      '''Return self==value.'''
    ...
    def __init__ (self, /, *args, **kwargs):
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
    def __mul__ (self, value, /):
      '''Return self*value.'''
    ...
    def __ne__ (self, value, /):
      '''Return self!=value.'''
    ...
    def __sub__ (self, value, /):
      '''Return self-value.'''
    ...
    def __truediv__ (self, value, /):
      '''Return self/value.'''
    ...
    def as_integer_ratio (self, /):
      '''Return integer ratio.

Return a pair of integers, whose ratio is exactly equal to the original int
and with a positive denominator.

>>> (10).as_integer_ratio()
(10, 1)
>>> (-10).as_integer_ratio()
(-10, 1)
>>> (0).as_integer_ratio()
(0, 1)'''
    ...
    def bit_count (self, /):
      '''Number of ones in the binary representation of the absolute value of self.

Also known as the population count.

>>> bin(13)
'0b1101'
>>> (13).bit_count()
3'''
    ...
    def bit_length (self, /):
      '''Number of bits necessary to represent self in binary.

>>> bin(37)
'0b100101'
>>> (37).bit_length()
6'''
    ...
    def conjugate (self, *args, **kwargs):
      '''Returns self, the complex conjugate of any int.'''
    ...
    def denominator (self, *args, **kwargs):
      '''the denominator of a rational number in lowest terms'''
    ...
    def from_bytes (bytes, byteorder, *, signed=False):
      '''Return the integer represented by the given array of bytes.

  bytes
    Holds the array of bytes to convert.  The argument must either
    support the buffer protocol or be an iterable object producing bytes.
    Bytes and bytearray are examples of built-in objects that support the
    buffer protocol.
  byteorder
    The byte order used to represent the integer.  If byteorder is 'big',
    the most significant byte is at the beginning of the byte array.  If
    byteorder is 'little', the most significant byte is at the end of the
    byte array.  To request the native byte order of the host system, use
    `sys.byteorder' as the byte order value.
  signed
    Indicates whether two's complement is used to represent the integer.'''
    ...
    def imag (self, *args, **kwargs):
      '''the imaginary part of a complex number'''
    ...
    def kChamfer (self, *args, **kwargs):
      '''None'''
    ...
    def kExtend (self, *args, **kwargs):
      '''None'''
    ...
    def kFillet (self, *args, **kwargs):
      '''None'''
    ...
    def name (self, *args, **kwargs):
      '''None'''
    ...
    def names (self, *args, **kwargs):
      '''dict() -> new empty dictionary
dict(mapping) -> new dictionary initialized from a mapping object's
    (key, value) pairs
dict(iterable) -> new dictionary initialized as if via:
    d = {}
    for k, v in iterable:
        d[k] = v
dict(**kwargs) -> new dictionary initialized with the name=value pairs
    in the keyword argument list.  For example:  dict(one=1, two=2)'''
    ...
    def numerator (self, *args, **kwargs):
      '''the numerator of a rational number in lowest terms'''
    ...
    def real (self, *args, **kwargs):
      '''the real part of a complex number'''
    ...
    def to_bytes (self, /, length, byteorder, *, signed=False):
      '''Return an array of bytes representing an integer.

  length
    Length of bytes object to use.  An OverflowError is raised if the
    integer is not representable with the given number of bytes.
  byteorder
    The byte order used to represent the integer.  If byteorder is 'big',
    the most significant byte is at the beginning of the byte array.  If
    byteorder is 'little', the most significant byte is at the end of the
    byte array.  To request the native byte order of the host system, use
    `sys.byteorder' as the byte order value.
  signed
    Determines whether two's complement is used to represent the integer.
    If signed is False and a negative integer is given, an OverflowError
    is raised.'''
    ...
    def values (self, *args, **kwargs):
      '''dict() -> new empty dictionary
dict(mapping) -> new dictionary initialized from a mapping object's
    (key, value) pairs
dict(iterable) -> new dictionary initialized as if via:
    d = {}
    for k, v in iterable:
        d[k] = v
dict(**kwargs) -> new dictionary initialized with the name=value pairs
    in the keyword argument list.  For example:  dict(one=1, two=2)'''
    ...

class OffsetCurve2d:
    def __eq__ (self, *args, **kwargs):
      '''
__eq__( (Entity2d)arg1, (Entity2d)arg2) -> bool :

    C++ signature :
        bool __eq__(class PyGeEntity2d {lvalue},class PyGeEntity2d)'''
    ...
    def __init__ (self, *args, **kwargs):
      '''
__init__( (object)arg1, (Curve2d)arg2, (float)arg3) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class PyGeCurve2d,double)'''
    ...
    def __ne__ (self, *args, **kwargs):
      '''
__ne__( (Entity2d)arg1, (Entity2d)arg2) -> bool :

    C++ signature :
        bool __ne__(class PyGeEntity2d {lvalue},class PyGeEntity2d)'''
    ...
    def area (self, *args, **kwargs):
      '''
area( (Curve2d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double area(class PyGeCurve2d {lvalue},double,double)

area( (Curve2d)arg1, (float)arg2, (float)arg3, (Tol)arg4) -> float :

    C++ signature :
        double area(class PyGeCurve2d {lvalue},double,double,class AcGeTol)'''
    ...
    def boundBlock (self, *args, **kwargs):
      '''
boundBlock( (Curve2d)arg1) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d boundBlock(class PyGeCurve2d {lvalue})

boundBlock( (Curve2d)arg1, (Interval)arg2) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d boundBlock(class PyGeCurve2d {lvalue},class PyGeInterval)'''
    ...
    def className (self, *args, **kwargs):
      '''
className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def closestPointTo (self, *args, **kwargs):
      '''
closestPointTo( (Curve2d)arg1, (Point2d)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d closestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d)

closestPointTo( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> Point2d :

    C++ signature :
        class AcGePoint2d closestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)

closestPointTo( (Curve2d)arg1, (Curve2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointTo(class PyGeCurve2d {lvalue},class PyGeCurve2d)

closestPointTo( (Curve2d)arg1, (Curve2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointTo(class PyGeCurve2d {lvalue},class PyGeCurve2d,class AcGeTol)'''
    ...
    def copy (self, *args, **kwargs):
      '''
copy( (Entity2d)arg1) -> Entity2d :

    C++ signature :
        class PyGeEntity2d copy(class PyGeEntity2d {lvalue})'''
    ...
    def distanceTo (self, *args, **kwargs):
      '''
distanceTo( (Curve2d)arg1, (Point2d)arg2) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class AcGePoint2d)

distanceTo( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)

distanceTo( (Curve2d)arg1, (Curve2d)arg2) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class PyGeCurve2d)

distanceTo( (Curve2d)arg1, (Curve2d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class PyGeCurve2d,class AcGeTol)'''
    ...
    def evalPoint (self, *args, **kwargs):
      '''
evalPoint( (Curve2d)arg1, (float)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d evalPoint(class PyGeCurve2d {lvalue},double)

evalPoint( (Curve2d)arg1, (float)arg2, (int)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple evalPoint(class PyGeCurve2d {lvalue},double,int)'''
    ...
    def explode (self, *args, **kwargs):
      '''
explode( (Curve2d)arg1) -> list :

    C++ signature :
        class boost::python::list explode(class PyGeCurve2d {lvalue})

explode( (Curve2d)arg1, (Interval)arg2) -> list :

    C++ signature :
        class boost::python::list explode(class PyGeCurve2d {lvalue},class PyGeInterval)'''
    ...
    def getClosestPointTo (self, *args, **kwargs):
      '''
getClosestPointTo( (Curve2d)arg1, (Point2d)arg2) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getClosestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d)

getClosestPointTo( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getClosestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def getClosestPointsTo (self, *args, **kwargs):
      '''
getClosestPointsTo( (Curve2d)arg1, (Curve2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getClosestPointsTo(class PyGeCurve2d {lvalue},class PyGeCurve2d)

getClosestPointsTo( (Curve2d)arg1, (Curve2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple getClosestPointsTo(class PyGeCurve2d {lvalue},class PyGeCurve2d,class AcGeTol)'''
    ...
    def getEndPoint (self, *args, **kwargs):
      '''
getEndPoint( (Curve2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d getEndPoint(class PyGeCurve2d {lvalue})'''
    ...
    def getInterval (self, *args, **kwargs):
      '''
getInterval( (Curve2d)arg1) -> Interval :

    C++ signature :
        class PyGeInterval getInterval(class PyGeCurve2d {lvalue})'''
    ...
    def getNormalPoint (self, *args, **kwargs):
      '''
getNormalPoint( (Curve2d)arg1, (Point2d)arg2) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getNormalPoint(class PyGeCurve2d {lvalue},class AcGePoint2d)

getNormalPoint( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getNormalPoint(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def getSamplePoints (self, *args, **kwargs):
      '''
getSamplePoints( (Curve2d)arg1, (int)arg2) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve2d {lvalue},int)

getSamplePoints( (Curve2d)arg1, (float)arg2, (float)arg3, (float)arg4) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve2d {lvalue},double,double,double)'''
    ...
    def getSplitCurves (self, *args, **kwargs):
      '''
getSplitCurves( (Curve2d)arg1, (float)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getSplitCurves(class PyGeCurve2d {lvalue},double)'''
    ...
    def getStartPoint (self, *args, **kwargs):
      '''
getStartPoint( (Curve2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d getStartPoint(class PyGeCurve2d {lvalue})'''
    ...
    def getTrimmedOffset (self, *args, **kwargs):
      '''
getTrimmedOffset( (Curve2d)arg1, (float)arg2, (OffsetCrvExtType)arg3) -> list :

    C++ signature :
        class boost::python::list getTrimmedOffset(class PyGeCurve2d {lvalue},double,enum AcGe::OffsetCrvExtType)

getTrimmedOffset( (Curve2d)arg1, (float)arg2, (OffsetCrvExtType)arg3, (Tol)arg4) -> list :

    C++ signature :
        class boost::python::list getTrimmedOffset(class PyGeCurve2d {lvalue},double,enum AcGe::OffsetCrvExtType,class AcGeTol)'''
    ...
    def hasEndPoint (self, *args, **kwargs):
      '''
hasEndPoint( (Curve2d)arg1) -> bool :

    C++ signature :
        bool hasEndPoint(class PyGeCurve2d {lvalue})'''
    ...
    def hasStartPoint (self, *args, **kwargs):
      '''
hasStartPoint( (Curve2d)arg1) -> bool :

    C++ signature :
        bool hasStartPoint(class PyGeCurve2d {lvalue})'''
    ...
    def isClosed (self, *args, **kwargs):
      '''
isClosed( (Curve2d)arg1) -> bool :

    C++ signature :
        bool isClosed(class PyGeCurve2d {lvalue})

isClosed( (Curve2d)arg1, (Tol)arg2) -> bool :

    C++ signature :
        bool isClosed(class PyGeCurve2d {lvalue},class AcGeTol)'''
    ...
    def isDegenerate (self, *args, **kwargs):
      '''
isDegenerate( (Curve2d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isDegenerate(class PyGeCurve2d {lvalue})

isDegenerate( (Curve2d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isDegenerate(class PyGeCurve2d {lvalue},class AcGeTol)'''
    ...
    def isEqualTo (self, *args, **kwargs):
      '''
isEqualTo( (Entity2d)arg1, (Entity2d)arg2) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity2d {lvalue},class PyGeEntity2d)

isEqualTo( (Entity2d)arg1, (Entity2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity2d {lvalue},class PyGeEntity2d,class AcGeTol)'''
    ...
    def isKindOf (self, *args, **kwargs):
      '''
isKindOf( (Entity2d)arg1, (EntityId)arg2) -> bool :

    C++ signature :
        bool isKindOf(class PyGeEntity2d {lvalue},enum AcGe::EntityId)'''
    ...
    def isLinear (self, *args, **kwargs):
      '''
isLinear( (Curve2d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isLinear(class PyGeCurve2d {lvalue})

isLinear( (Curve2d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isLinear(class PyGeCurve2d {lvalue},class AcGeTol)'''
    ...
    def isNull (self, *args, **kwargs):
      '''
isNull( (Entity2d)arg1) -> bool :

    C++ signature :
        bool isNull(class PyGeEntity2d {lvalue})'''
    ...
    def isOn (self, *args, **kwargs):
      '''
isOn( (Curve2d)arg1, (Point2d)arg2) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve2d {lvalue},class AcGePoint2d)

isOn( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)

isOn( (Curve2d)arg1, (Point2d)arg2, (float)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve2d {lvalue},class AcGePoint2d,double {lvalue})

isOn( (Curve2d)arg1, (Point2d)arg2, (float)arg3, (Tol)arg4) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve2d {lvalue},class AcGePoint2d,double {lvalue},class AcGeTol)

isOn( (Curve2d)arg1, (float)arg2) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve2d {lvalue},double)

isOn( (Curve2d)arg1, (float)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve2d {lvalue},double,class AcGeTol)'''
    ...
    def isPeriodic (self, *args, **kwargs):
      '''
isPeriodic( (Curve2d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isPeriodic(class PyGeCurve2d {lvalue})'''
    ...
    def length (self, *args, **kwargs):
      '''
length( (Curve2d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double length(class PyGeCurve2d {lvalue},double,double)

length( (Curve2d)arg1, (float)arg2, (float)arg3, (float)arg4) -> float :

    C++ signature :
        double length(class PyGeCurve2d {lvalue},double,double,double)'''
    ...
    def mirror (self, *args, **kwargs):
      '''
mirror( (Entity2d)arg1, (Line2d)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} mirror(class PyGeEntity2d {lvalue},class PyGeLine2d)'''
    ...
    def orthoBoundBlock (self, *args, **kwargs):
      '''
orthoBoundBlock( (Curve2d)arg1) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d orthoBoundBlock(class PyGeCurve2d {lvalue})

orthoBoundBlock( (Curve2d)arg1, (Interval)arg2) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d orthoBoundBlock(class PyGeCurve2d {lvalue},class PyGeInterval)'''
    ...
    def paramAtLength (self, *args, **kwargs):
      '''
paramAtLength( (Curve2d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double paramAtLength(class PyGeCurve2d {lvalue},double,double)

paramAtLength( (Curve2d)arg1, (float)arg2, (float)arg3, (bool)arg4, (float)arg5) -> float :

    C++ signature :
        double paramAtLength(class PyGeCurve2d {lvalue},double,double,bool,double)'''
    ...
    def paramOf (self, *args, **kwargs):
      '''
paramOf( (Curve2d)arg1, (Point2d)arg2) -> float :

    C++ signature :
        double paramOf(class PyGeCurve2d {lvalue},class AcGePoint2d)

paramOf( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double paramOf(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def reverseParam (self, *args, **kwargs):
      '''
reverseParam( (Curve2d)arg1) -> Curve2d :

    C++ signature :
        class PyGeCurve2d {lvalue} reverseParam(class PyGeCurve2d {lvalue})'''
    ...
    def rotateBy (self, *args, **kwargs):
      '''
rotateBy( (Entity2d)arg1, (float)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} rotateBy(class PyGeEntity2d {lvalue},double)

rotateBy( (Entity2d)arg1, (float)arg2, (Point2d)arg3) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} rotateBy(class PyGeEntity2d {lvalue},double,class AcGePoint2d)'''
    ...
    def scaleBy (self, *args, **kwargs):
      '''
scaleBy( (Entity2d)arg1, (float)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} scaleBy(class PyGeEntity2d {lvalue},double)

scaleBy( (Entity2d)arg1, (float)arg2, (Point2d)arg3) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} scaleBy(class PyGeEntity2d {lvalue},double,class AcGePoint2d)'''
    ...
    def setInterval (self, *args, **kwargs):
      '''
setInterval( (Curve2d)arg1) -> Curve2d :

    C++ signature :
        class PyGeCurve2d {lvalue} setInterval(class PyGeCurve2d {lvalue})

setInterval( (Curve2d)arg1, (Interval)arg2) -> bool :

    C++ signature :
        bool setInterval(class PyGeCurve2d {lvalue},class PyGeInterval)'''
    ...
    def transformBy (self, *args, **kwargs):
      '''
transformBy( (Entity2d)arg1, (Matrix2d)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} transformBy(class PyGeEntity2d {lvalue},class AcGeMatrix2d)'''
    ...
    def translateBy (self, *args, **kwargs):
      '''
translateBy( (Entity2d)arg1, (Vector2d)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} translateBy(class PyGeEntity2d {lvalue},class AcGeVector2d)'''
    ...
    def type (self, *args, **kwargs):
      '''
type( (Entity2d)arg1) -> EntityId :

    C++ signature :
        enum AcGe::EntityId type(class PyGeEntity2d {lvalue})'''
    ...

class OffsetCurve3d:
    def __eq__ (self, *args, **kwargs):
      '''
__eq__( (Entity3d)arg1, (Entity3d)arg2) -> bool :

    C++ signature :
        bool __eq__(class PyGeEntity3d {lvalue},class PyGeEntity3d)'''
    ...
    def __init__ (self, *args, **kwargs):
      '''
__init__( (object)arg1, (Curve3d)arg2, (Vector3d)arg3, (float)arg4) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class PyGeCurve3d,class AcGeVector3d,double)'''
    ...
    def __ne__ (self, *args, **kwargs):
      '''
__ne__( (Entity3d)arg1, (Entity3d)arg2) -> bool :

    C++ signature :
        bool __ne__(class PyGeEntity3d {lvalue},class PyGeEntity3d)'''
    ...
    def area (self, *args, **kwargs):
      '''
area( (Curve3d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double area(class PyGeCurve3d {lvalue},double,double)

area( (Curve3d)arg1, (float)arg2, (float)arg3, (Tol)arg4) -> float :

    C++ signature :
        double area(class PyGeCurve3d {lvalue},double,double,class AcGeTol)'''
    ...
    def boundBlock (self, *args, **kwargs):
      '''
boundBlock( (Curve3d)arg1) -> BoundBlock3d :

    C++ signature :
        class PyGeBoundBlock3d boundBlock(class PyGeCurve3d {lvalue})

boundBlock( (Curve3d)arg1, (Interval)arg2) -> BoundBlock3d :

    C++ signature :
        class PyGeBoundBlock3d boundBlock(class PyGeCurve3d {lvalue},class PyGeInterval)'''
    ...
    def className (self, *args, **kwargs):
      '''
className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def closestPointTo (self, *args, **kwargs):
      '''
closestPointTo( (Curve3d)arg1, (Point3d)arg2) -> Point3d :

    C++ signature :
        class AcGePoint3d closestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d)

closestPointTo( (Curve3d)arg1, (Point3d)arg2, (Tol)arg3) -> Point3d :

    C++ signature :
        class AcGePoint3d closestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeTol)

closestPointTo( (Curve3d)arg1, (Curve3d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointTo(class PyGeCurve3d {lvalue},class PyGeCurve3d)

closestPointTo( (Curve3d)arg1, (Curve3d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointTo(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeTol)'''
    ...
    def copy (self, *args, **kwargs):
      '''
copy( (Entity3d)arg1) -> Entity3d :

    C++ signature :
        class PyGeEntity3d copy(class PyGeEntity3d {lvalue})'''
    ...
    def distanceTo (self, *args, **kwargs):
      '''
distanceTo( (Curve3d)arg1, (Point3d)arg2) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve3d {lvalue},class AcGePoint3d)

distanceTo( (Curve3d)arg1, (Point3d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeTol)

distanceTo( (Curve3d)arg1, (Curve3d)arg2) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve3d {lvalue},class PyGeCurve3d)

distanceTo( (Curve3d)arg1, (Curve3d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeTol)'''
    ...
    def evalPoint (self, *args, **kwargs):
      '''
evalPoint( (Curve3d)arg1, (float)arg2) -> Point3d :

    C++ signature :
        class AcGePoint3d evalPoint(class PyGeCurve3d {lvalue},double)

evalPoint( (Curve3d)arg1, (float)arg2, (int)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple evalPoint(class PyGeCurve3d {lvalue},double,int)'''
    ...
    def explode (self, *args, **kwargs):
      '''
explode( (Curve3d)arg1) -> list :

    C++ signature :
        class boost::python::list explode(class PyGeCurve3d {lvalue})

explode( (Curve3d)arg1, (Interval)arg2) -> list :

    C++ signature :
        class boost::python::list explode(class PyGeCurve3d {lvalue},class PyGeInterval)'''
    ...
    def getClosestPointTo (self, *args, **kwargs):
      '''
getClosestPointTo( (Curve3d)arg1, (Point3d)arg2) -> PointOnCurve3d :

    C++ signature :
        class PyGePointOnCurve3d getClosestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d)

getClosestPointTo( (Curve3d)arg1, (Point3d)arg2, (Tol)arg3) -> PointOnCurve3d :

    C++ signature :
        class PyGePointOnCurve3d getClosestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def getClosestPointsTo (self, *args, **kwargs):
      '''
getClosestPointsTo( (Curve3d)arg1, (Curve3d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getClosestPointsTo(class PyGeCurve3d {lvalue},class PyGeCurve3d)

getClosestPointsTo( (Curve3d)arg1, (Curve3d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple getClosestPointsTo(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeTol)'''
    ...
    def getEndPoint (self, *args, **kwargs):
      '''
getEndPoint( (Curve3d)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d getEndPoint(class PyGeCurve3d {lvalue})'''
    ...
    def getInterval (self, *args, **kwargs):
      '''
getInterval( (Curve3d)arg1) -> Interval :

    C++ signature :
        class PyGeInterval getInterval(class PyGeCurve3d {lvalue})'''
    ...
    def getNormalPoint (self, *args, **kwargs):
      '''
getNormalPoint( (Curve3d)arg1, (Point3d)arg2) -> PointOnCurve3d :

    C++ signature :
        class PyGePointOnCurve3d getNormalPoint(class PyGeCurve3d {lvalue},class AcGePoint3d)

getNormalPoint( (Curve3d)arg1, (Point3d)arg2, (Tol)arg3) -> PointOnCurve3d :

    C++ signature :
        class PyGePointOnCurve3d getNormalPoint(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def getProjClosestPointTo (self, *args, **kwargs):
      '''
getProjClosestPointTo( (Curve3d)arg1, (Point3d)arg2, (Vector3d)arg3) -> PointOnCurve3d :

    C++ signature :
        class PyGePointOnCurve3d getProjClosestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeVector3d)

getProjClosestPointTo( (Curve3d)arg1, (Point3d)arg2, (Vector3d)arg3, (Tol)arg4) -> PointOnCurve3d :

    C++ signature :
        class PyGePointOnCurve3d getProjClosestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeVector3d,class AcGeTol)'''
    ...
    def getProjClosestPointsTo (self, *args, **kwargs):
      '''
getProjClosestPointsTo( (Curve3d)arg1, (Curve3d)arg2, (Vector3d)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple getProjClosestPointsTo(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeVector3d)

getProjClosestPointsTo( (Curve3d)arg1, (Curve3d)arg2, (Vector3d)arg3, (Tol)arg4) -> tuple :

    C++ signature :
        class boost::python::tuple getProjClosestPointsTo(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeVector3d,class AcGeTol)'''
    ...
    def getSamplePoints (self, *args, **kwargs):
      '''
getSamplePoints( (Curve3d)arg1, (int)arg2) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve3d {lvalue},int)

getSamplePoints( (Curve3d)arg1, (float)arg2, (float)arg3, (float)arg4) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve3d {lvalue},double,double,double)'''
    ...
    def getSplitCurves (self, *args, **kwargs):
      '''
getSplitCurves( (Curve3d)arg1, (float)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getSplitCurves(class PyGeCurve3d {lvalue},double)'''
    ...
    def getStartPoint (self, *args, **kwargs):
      '''
getStartPoint( (Curve3d)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d getStartPoint(class PyGeCurve3d {lvalue})'''
    ...
    def getTrimmedOffset (self, *args, **kwargs):
      '''
getTrimmedOffset( (Curve3d)arg1, (float)arg2, (Vector3d)arg3, (OffsetCrvExtType)arg4) -> list :

    C++ signature :
        class boost::python::list getTrimmedOffset(class PyGeCurve3d {lvalue},double,class AcGeVector3d,enum AcGe::OffsetCrvExtType)

getTrimmedOffset( (Curve3d)arg1, (float)arg2, (Vector3d)arg3, (OffsetCrvExtType)arg4, (Tol)arg5) -> list :

    C++ signature :
        class boost::python::list getTrimmedOffset(class PyGeCurve3d {lvalue},double,class AcGeVector3d,enum AcGe::OffsetCrvExtType,class AcGeTol)'''
    ...
    def hasEndPoint (self, *args, **kwargs):
      '''
hasEndPoint( (Curve3d)arg1) -> bool :

    C++ signature :
        bool hasEndPoint(class PyGeCurve3d {lvalue})'''
    ...
    def hasStartPoint (self, *args, **kwargs):
      '''
hasStartPoint( (Curve3d)arg1) -> bool :

    C++ signature :
        bool hasStartPoint(class PyGeCurve3d {lvalue})'''
    ...
    def isClosed (self, *args, **kwargs):
      '''
isClosed( (Curve3d)arg1) -> bool :

    C++ signature :
        bool isClosed(class PyGeCurve3d {lvalue})

isClosed( (Curve3d)arg1, (Tol)arg2) -> bool :

    C++ signature :
        bool isClosed(class PyGeCurve3d {lvalue},class AcGeTol)'''
    ...
    def isCoplanarWith (self, *args, **kwargs):
      '''
isCoplanarWith( (Curve3d)arg1, (Curve3d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isCoplanarWith(class PyGeCurve3d {lvalue},class PyGeCurve3d)

isCoplanarWith( (Curve3d)arg1, (Curve3d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple isCoplanarWith(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeTol)'''
    ...
    def isDegenerate (self, *args, **kwargs):
      '''
isDegenerate( (Curve3d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isDegenerate(class PyGeCurve3d {lvalue})

isDegenerate( (Curve3d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isDegenerate(class PyGeCurve3d {lvalue},class AcGeTol)'''
    ...
    def isEqualTo (self, *args, **kwargs):
      '''
isEqualTo( (Entity3d)arg1, (Entity3d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity3d {lvalue},class PyGeEntity3d,class AcGeTol)'''
    ...
    def isKindOf (self, *args, **kwargs):
      '''
isKindOf( (Entity3d)arg1, (EntityId)arg2) -> bool :

    C++ signature :
        bool isKindOf(class PyGeEntity3d {lvalue},enum AcGe::EntityId)'''
    ...
    def isLinear (self, *args, **kwargs):
      '''
isLinear( (Curve3d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isLinear(class PyGeCurve3d {lvalue})

isLinear( (Curve3d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isLinear(class PyGeCurve3d {lvalue},class AcGeTol)'''
    ...
    def isNull (self, *args, **kwargs):
      '''
isNull( (Entity3d)arg1) -> bool :

    C++ signature :
        bool isNull(class PyGeEntity3d {lvalue})'''
    ...
    def isOn (self, *args, **kwargs):
      '''
isOn( (Curve3d)arg1, (Point3d)arg2) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve3d {lvalue},class AcGePoint3d)

isOn( (Curve3d)arg1, (Point3d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeTol)

isOn( (Curve3d)arg1, (Point3d)arg2, (float)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve3d {lvalue},class AcGePoint3d,double {lvalue})

isOn( (Curve3d)arg1, (Point3d)arg2, (float)arg3, (Tol)arg4) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve3d {lvalue},class AcGePoint3d,double {lvalue},class AcGeTol)

isOn( (Curve3d)arg1, (float)arg2) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve3d {lvalue},double)

isOn( (Curve3d)arg1, (float)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve3d {lvalue},double,class AcGeTol)'''
    ...
    def isPeriodic (self, *args, **kwargs):
      '''
isPeriodic( (Curve3d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isPeriodic(class PyGeCurve3d {lvalue})'''
    ...
    def isPlanar (self, *args, **kwargs):
      '''
isPlanar( (Curve3d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isPlanar(class PyGeCurve3d {lvalue})

isPlanar( (Curve3d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isPlanar(class PyGeCurve3d {lvalue},class AcGeTol)'''
    ...
    def length (self, *args, **kwargs):
      '''
length( (Curve3d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double length(class PyGeCurve3d {lvalue},double,double)

length( (Curve3d)arg1, (float)arg2, (float)arg3, (float)arg4) -> float :

    C++ signature :
        double length(class PyGeCurve3d {lvalue},double,double,double)'''
    ...
    def mirror (self, *args, **kwargs):
      '''
mirror( (Entity3d)arg1, (Plane)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} mirror(class PyGeEntity3d {lvalue},class PyGePlane)'''
    ...
    def orthoBoundBlock (self, *args, **kwargs):
      '''
orthoBoundBlock( (Curve3d)arg1) -> BoundBlock3d :

    C++ signature :
        class PyGeBoundBlock3d orthoBoundBlock(class PyGeCurve3d {lvalue})

orthoBoundBlock( (Curve3d)arg1, (Interval)arg2) -> BoundBlock3d :

    C++ signature :
        class PyGeBoundBlock3d orthoBoundBlock(class PyGeCurve3d {lvalue},class PyGeInterval)'''
    ...
    def orthoProject (self, *args, **kwargs):
      '''
orthoProject( (Curve3d)arg1, (Plane)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d orthoProject(class PyGeCurve3d {lvalue},class PyGePlane)

orthoProject( (Curve3d)arg1, (Plane)arg2, (Tol)arg3) -> Entity3d :

    C++ signature :
        class PyGeEntity3d orthoProject(class PyGeCurve3d {lvalue},class PyGePlane,class AcGeTol)'''
    ...
    def paramAtLength (self, *args, **kwargs):
      '''
paramAtLength( (Curve3d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double paramAtLength(class PyGeCurve3d {lvalue},double,double)

paramAtLength( (Curve3d)arg1, (float)arg2, (float)arg3, (bool)arg4, (float)arg5) -> float :

    C++ signature :
        double paramAtLength(class PyGeCurve3d {lvalue},double,double,bool,double)'''
    ...
    def paramOf (self, *args, **kwargs):
      '''
paramOf( (Curve3d)arg1, (Point3d)arg2) -> float :

    C++ signature :
        double paramOf(class PyGeCurve3d {lvalue},class AcGePoint3d)

paramOf( (Curve3d)arg1, (Point3d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double paramOf(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def projClosestPointTo (self, *args, **kwargs):
      '''
projClosestPointTo( (Curve3d)arg1, (Point3d)arg2, (Vector3d)arg3) -> Point3d :

    C++ signature :
        class AcGePoint3d projClosestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeVector3d)

projClosestPointTo( (Curve3d)arg1, (Point3d)arg2, (Vector3d)arg3, (Tol)arg4) -> Point3d :

    C++ signature :
        class AcGePoint3d projClosestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeVector3d,class AcGeTol)'''
    ...
    def projClosestPointsTo (self, *args, **kwargs):
      '''
projClosestPointsTo( (Curve3d)arg1, (Curve3d)arg2, (Vector3d)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple projClosestPointsTo(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeVector3d)

projClosestPointsTo( (Curve3d)arg1, (Curve3d)arg2, (Vector3d)arg3, (Tol)arg4) -> tuple :

    C++ signature :
        class boost::python::tuple projClosestPointsTo(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeVector3d,class AcGeTol)'''
    ...
    def project (self, *args, **kwargs):
      '''
project( (Curve3d)arg1, (Plane)arg2, (Vector3d)arg3) -> Entity3d :

    C++ signature :
        class PyGeEntity3d project(class PyGeCurve3d {lvalue},class PyGePlane,class AcGeVector3d)

project( (Curve3d)arg1, (Plane)arg2, (Vector3d)arg3, (Tol)arg4) -> Entity3d :

    C++ signature :
        class PyGeEntity3d project(class PyGeCurve3d {lvalue},class PyGePlane,class AcGeVector3d,class AcGeTol)'''
    ...
    def reverseParam (self, *args, **kwargs):
      '''
reverseParam( (Curve3d)arg1) -> Curve3d :

    C++ signature :
        class PyGeCurve3d {lvalue} reverseParam(class PyGeCurve3d {lvalue})'''
    ...
    def rotateBy (self, *args, **kwargs):
      '''
rotateBy( (Entity3d)arg1, (float)arg2, (Vector3d)arg3) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} rotateBy(class PyGeEntity3d {lvalue},double,class AcGeVector3d)

rotateBy( (Entity3d)arg1, (float)arg2, (Vector3d)arg3, (Point3d)arg4) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} rotateBy(class PyGeEntity3d {lvalue},double,class AcGeVector3d,class AcGePoint3d)'''
    ...
    def scaleBy (self, *args, **kwargs):
      '''
scaleBy( (Entity3d)arg1, (float)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} scaleBy(class PyGeEntity3d {lvalue},double)

scaleBy( (Entity3d)arg1, (float)arg2, (Point3d)arg3) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} scaleBy(class PyGeEntity3d {lvalue},double,class AcGePoint3d)'''
    ...
    def setInterval (self, *args, **kwargs):
      '''
setInterval( (Curve3d)arg1) -> Curve3d :

    C++ signature :
        class PyGeCurve3d {lvalue} setInterval(class PyGeCurve3d {lvalue})

setInterval( (Curve3d)arg1, (Interval)arg2) -> bool :

    C++ signature :
        bool setInterval(class PyGeCurve3d {lvalue},class PyGeInterval)'''
    ...
    def transformBy (self, *args, **kwargs):
      '''
transformBy( (Entity3d)arg1, (Matrix3d)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} transformBy(class PyGeEntity3d {lvalue},class AcGeMatrix3d)'''
    ...
    def translateBy (self, *args, **kwargs):
      '''
translateBy( (Entity3d)arg1, (Vector3d)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} translateBy(class PyGeEntity3d {lvalue},class AcGeVector3d)'''
    ...
    def type (self, *args, **kwargs):
      '''
type( (Entity3d)arg1) -> EntityId :

    C++ signature :
        enum AcGe::EntityId type(class PyGeEntity3d {lvalue})'''
    ...

class PlanarEnt:
    def __eq__ (self, *args, **kwargs):
      '''
__eq__( (Entity3d)arg1, (Entity3d)arg2) -> bool :

    C++ signature :
        bool __eq__(class PyGeEntity3d {lvalue},class PyGeEntity3d)'''
    ...
    def __init__ (self, *args, **kwargs):
      '''Raises an exception
This class cannot be instantiated from Python
'''
    ...
    def __ne__ (self, *args, **kwargs):
      '''
__ne__( (Entity3d)arg1, (Entity3d)arg2) -> bool :

    C++ signature :
        bool __ne__(class PyGeEntity3d {lvalue},class PyGeEntity3d)'''
    ...
    def className (self, *args, **kwargs):
      '''
className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def closestPointTo (self, *args, **kwargs):
      '''
closestPointTo( (Surface)arg1, (Point3d)arg2) -> Point3d :

    C++ signature :
        class AcGePoint3d closestPointTo(class PyAcGeSurface {lvalue},class AcGePoint3d)

closestPointTo( (Surface)arg1, (Point3d)arg2, (Tol)arg3) -> Point3d :

    C++ signature :
        class AcGePoint3d closestPointTo(class PyAcGeSurface {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def closestPointToLinearEnt (self, *args, **kwargs):
      '''
closestPointToLinearEnt( (PlanarEnt)arg1, (LinearEnt3d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointToLinearEnt(class PyGePlanarEnt {lvalue},class PyGeLinearEnt3d)

closestPointToLinearEnt( (PlanarEnt)arg1, (LinearEnt3d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointToLinearEnt(class PyGePlanarEnt {lvalue},class PyGeLinearEnt3d,class AcGeTol)'''
    ...
    def closestPointToPlanarEnt (self, *args, **kwargs):
      '''
closestPointToPlanarEnt( (PlanarEnt)arg1, (PlanarEnt)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointToPlanarEnt(class PyGePlanarEnt {lvalue},class PyGePlanarEnt)

closestPointToPlanarEnt( (PlanarEnt)arg1, (PlanarEnt)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointToPlanarEnt(class PyGePlanarEnt {lvalue},class PyGePlanarEnt,class AcGeTol)'''
    ...
    def copy (self, *args, **kwargs):
      '''
copy( (Entity3d)arg1) -> Entity3d :

    C++ signature :
        class PyGeEntity3d copy(class PyGeEntity3d {lvalue})'''
    ...
    def distanceTo (self, *args, **kwargs):
      '''
distanceTo( (Surface)arg1, (Point3d)arg2) -> float :

    C++ signature :
        double distanceTo(class PyAcGeSurface {lvalue},class AcGePoint3d)

distanceTo( (Surface)arg1, (Point3d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double distanceTo(class PyAcGeSurface {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def evalPoint (self, *args, **kwargs):
      '''
evalPoint( (Surface)arg1, (Point2d)arg2) -> Point3d :

    C++ signature :
        class AcGePoint3d evalPoint(class PyAcGeSurface {lvalue},class AcGePoint2d)

evalPoint( (Surface)arg1, (Point2d)arg2, (int)arg3, (list)arg4) -> Point3d :

    C++ signature :
        class AcGePoint3d evalPoint(class PyAcGeSurface {lvalue},class AcGePoint2d,int,class boost::python::list {lvalue})

evalPoint( (Surface)arg1, (Point2d)arg2, (int)arg3, (list)arg4, (Vector3d)arg5) -> Point3d :

    C++ signature :
        class AcGePoint3d evalPoint(class PyAcGeSurface {lvalue},class AcGePoint2d,int,class boost::python::list {lvalue},class AcGeVector3d {lvalue})'''
    ...
    def getCoefficients (self, *args, **kwargs):
      '''
getCoefficients( (PlanarEnt)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple getCoefficients(class PyGePlanarEnt {lvalue})'''
    ...
    def getCoordSystem (self, *args, **kwargs):
      '''
getCoordSystem( (PlanarEnt)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple getCoordSystem(class PyGePlanarEnt {lvalue})'''
    ...
    def intersectWith (self, *args, **kwargs):
      '''
intersectWith( (PlanarEnt)arg1, (LinearEnt3d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple intersectWith(class PyGePlanarEnt {lvalue},class PyGeLinearEnt3d)

intersectWith( (PlanarEnt)arg1, (LinearEnt3d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple intersectWith(class PyGePlanarEnt {lvalue},class PyGeLinearEnt3d,class AcGeTol)'''
    ...
    def isClosedInU (self, *args, **kwargs):
      '''
isClosedInU( (Surface)arg1) -> bool :

    C++ signature :
        bool isClosedInU(class PyAcGeSurface {lvalue})

isClosedInU( (Surface)arg1, (Tol)arg2) -> bool :

    C++ signature :
        bool isClosedInU(class PyAcGeSurface {lvalue},class AcGeTol)'''
    ...
    def isClosedInV (self, *args, **kwargs):
      '''
isClosedInV( (Surface)arg1) -> bool :

    C++ signature :
        bool isClosedInV(class PyAcGeSurface {lvalue})

isClosedInV( (Surface)arg1, (Tol)arg2) -> bool :

    C++ signature :
        bool isClosedInV(class PyAcGeSurface {lvalue},class AcGeTol)'''
    ...
    def isCoplanarTo (self, *args, **kwargs):
      '''
isCoplanarTo( (PlanarEnt)arg1, (PlanarEnt)arg2) -> bool :

    C++ signature :
        bool isCoplanarTo(class PyGePlanarEnt {lvalue},class PyGePlanarEnt)

isCoplanarTo( (PlanarEnt)arg1, (PlanarEnt)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isCoplanarTo(class PyGePlanarEnt {lvalue},class PyGePlanarEnt,class AcGeTol)'''
    ...
    def isEqualTo (self, *args, **kwargs):
      '''
isEqualTo( (Entity3d)arg1, (Entity3d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity3d {lvalue},class PyGeEntity3d,class AcGeTol)'''
    ...
    def isKindOf (self, *args, **kwargs):
      '''
isKindOf( (Entity3d)arg1, (EntityId)arg2) -> bool :

    C++ signature :
        bool isKindOf(class PyGeEntity3d {lvalue},enum AcGe::EntityId)'''
    ...
    def isNormalReversed (self, *args, **kwargs):
      '''
isNormalReversed( (Surface)arg1) -> bool :

    C++ signature :
        bool isNormalReversed(class PyAcGeSurface {lvalue})'''
    ...
    def isNull (self, *args, **kwargs):
      '''
isNull( (Entity3d)arg1) -> bool :

    C++ signature :
        bool isNull(class PyGeEntity3d {lvalue})'''
    ...
    def isOn (self, *args, **kwargs):
      '''
isOn( (Surface)arg1, (Point3d)arg2) -> bool :

    C++ signature :
        bool isOn(class PyAcGeSurface {lvalue},class AcGePoint3d)

isOn( (Surface)arg1, (Point3d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isOn(class PyAcGeSurface {lvalue},class AcGePoint3d,class AcGeTol)

isOn( (Surface)arg1, (Point3d)arg2, (Point2d)arg3) -> bool :

    C++ signature :
        bool isOn(class PyAcGeSurface {lvalue},class AcGePoint3d,class AcGePoint2d {lvalue})

isOn( (Surface)arg1, (Point3d)arg2, (Point2d)arg3, (Tol)arg4) -> bool :

    C++ signature :
        bool isOn(class PyAcGeSurface {lvalue},class AcGePoint3d,class AcGePoint2d {lvalue},class AcGeTol)'''
    ...
    def isParallelTo (self, *args, **kwargs):
      '''
isParallelTo( (PlanarEnt)arg1, (LinearEnt3d)arg2) -> bool :

    C++ signature :
        bool isParallelTo(class PyGePlanarEnt {lvalue},class PyGeLinearEnt3d)

isParallelTo( (PlanarEnt)arg1, (LinearEnt3d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isParallelTo(class PyGePlanarEnt {lvalue},class PyGeLinearEnt3d,class AcGeTol)

isParallelTo( (PlanarEnt)arg1, (PlanarEnt)arg2) -> bool :

    C++ signature :
        bool isParallelTo(class PyGePlanarEnt {lvalue},class PyGePlanarEnt)

isParallelTo( (PlanarEnt)arg1, (PlanarEnt)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isParallelTo(class PyGePlanarEnt {lvalue},class PyGePlanarEnt,class AcGeTol)'''
    ...
    def isPerpendicularTo (self, *args, **kwargs):
      '''
isPerpendicularTo( (PlanarEnt)arg1, (LinearEnt3d)arg2) -> bool :

    C++ signature :
        bool isPerpendicularTo(class PyGePlanarEnt {lvalue},class PyGeLinearEnt3d)

isPerpendicularTo( (PlanarEnt)arg1, (LinearEnt3d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isPerpendicularTo(class PyGePlanarEnt {lvalue},class PyGeLinearEnt3d,class AcGeTol)

isPerpendicularTo( (PlanarEnt)arg1, (PlanarEnt)arg2) -> bool :

    C++ signature :
        bool isPerpendicularTo(class PyGePlanarEnt {lvalue},class PyGePlanarEnt)

isPerpendicularTo( (PlanarEnt)arg1, (PlanarEnt)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isPerpendicularTo(class PyGePlanarEnt {lvalue},class PyGePlanarEnt,class AcGeTol)'''
    ...
    def mirror (self, *args, **kwargs):
      '''
mirror( (Entity3d)arg1, (Plane)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} mirror(class PyGeEntity3d {lvalue},class PyGePlane)'''
    ...
    def normal (self, *args, **kwargs):
      '''
normal( (PlanarEnt)arg1) -> Vector3d :

    C++ signature :
        class AcGeVector3d normal(class PyGePlanarEnt {lvalue})'''
    ...
    def paramOf (self, *args, **kwargs):
      '''
paramOf( (Surface)arg1, (Point3d)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d paramOf(class PyAcGeSurface {lvalue},class AcGePoint3d)

paramOf( (Surface)arg1, (Point3d)arg2, (Tol)arg3) -> Point2d :

    C++ signature :
        class AcGePoint2d paramOf(class PyAcGeSurface {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def pointOnPlane (self, *args, **kwargs):
      '''
pointOnPlane( (PlanarEnt)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d pointOnPlane(class PyGePlanarEnt {lvalue})'''
    ...
    def reverseNormal (self, *args, **kwargs):
      '''
reverseNormal( (Surface)arg1) -> Surface :

    C++ signature :
        class PyAcGeSurface {lvalue} reverseNormal(class PyAcGeSurface {lvalue})'''
    ...
    def rotateBy (self, *args, **kwargs):
      '''
rotateBy( (Entity3d)arg1, (float)arg2, (Vector3d)arg3) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} rotateBy(class PyGeEntity3d {lvalue},double,class AcGeVector3d)

rotateBy( (Entity3d)arg1, (float)arg2, (Vector3d)arg3, (Point3d)arg4) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} rotateBy(class PyGeEntity3d {lvalue},double,class AcGeVector3d,class AcGePoint3d)'''
    ...
    def scaleBy (self, *args, **kwargs):
      '''
scaleBy( (Entity3d)arg1, (float)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} scaleBy(class PyGeEntity3d {lvalue},double)

scaleBy( (Entity3d)arg1, (float)arg2, (Point3d)arg3) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} scaleBy(class PyGeEntity3d {lvalue},double,class AcGePoint3d)'''
    ...
    def transformBy (self, *args, **kwargs):
      '''
transformBy( (Entity3d)arg1, (Matrix3d)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} transformBy(class PyGeEntity3d {lvalue},class AcGeMatrix3d)'''
    ...
    def translateBy (self, *args, **kwargs):
      '''
translateBy( (Entity3d)arg1, (Vector3d)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} translateBy(class PyGeEntity3d {lvalue},class AcGeVector3d)'''
    ...
    def type (self, *args, **kwargs):
      '''
type( (Entity3d)arg1) -> EntityId :

    C++ signature :
        enum AcGe::EntityId type(class PyGeEntity3d {lvalue})'''
    ...

class Plane:
    def __eq__ (self, *args, **kwargs):
      '''
__eq__( (Entity3d)arg1, (Entity3d)arg2) -> bool :

    C++ signature :
        bool __eq__(class PyGeEntity3d {lvalue},class PyGeEntity3d)'''
    ...
    def __init__ (self, *args, **kwargs):
      '''
__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1, (Point3d)arg2, (Vector3d)arg3, (Vector3d)arg4) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class AcGePoint3d,class AcGeVector3d,class AcGeVector3d)

__init__( (object)arg1, (Point3d)arg2, (Point3d)arg3, (Point3d)arg4) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class AcGePoint3d,class AcGePoint3d,class AcGePoint3d)'''
    ...
    def __ne__ (self, *args, **kwargs):
      '''
__ne__( (Entity3d)arg1, (Entity3d)arg2) -> bool :

    C++ signature :
        bool __ne__(class PyGeEntity3d {lvalue},class PyGeEntity3d)'''
    ...
    def className (self, *args, **kwargs):
      '''
className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def closestPointTo (self, *args, **kwargs):
      '''
closestPointTo( (Surface)arg1, (Point3d)arg2) -> Point3d :

    C++ signature :
        class AcGePoint3d closestPointTo(class PyAcGeSurface {lvalue},class AcGePoint3d)

closestPointTo( (Surface)arg1, (Point3d)arg2, (Tol)arg3) -> Point3d :

    C++ signature :
        class AcGePoint3d closestPointTo(class PyAcGeSurface {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def closestPointToLinearEnt (self, *args, **kwargs):
      '''
closestPointToLinearEnt( (PlanarEnt)arg1, (LinearEnt3d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointToLinearEnt(class PyGePlanarEnt {lvalue},class PyGeLinearEnt3d)

closestPointToLinearEnt( (PlanarEnt)arg1, (LinearEnt3d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointToLinearEnt(class PyGePlanarEnt {lvalue},class PyGeLinearEnt3d,class AcGeTol)'''
    ...
    def closestPointToPlanarEnt (self, *args, **kwargs):
      '''
closestPointToPlanarEnt( (PlanarEnt)arg1, (PlanarEnt)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointToPlanarEnt(class PyGePlanarEnt {lvalue},class PyGePlanarEnt)

closestPointToPlanarEnt( (PlanarEnt)arg1, (PlanarEnt)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointToPlanarEnt(class PyGePlanarEnt {lvalue},class PyGePlanarEnt,class AcGeTol)'''
    ...
    def copy (self, *args, **kwargs):
      '''
copy( (Entity3d)arg1) -> Entity3d :

    C++ signature :
        class PyGeEntity3d copy(class PyGeEntity3d {lvalue})'''
    ...
    def distanceTo (self, *args, **kwargs):
      '''
distanceTo( (Surface)arg1, (Point3d)arg2) -> float :

    C++ signature :
        double distanceTo(class PyAcGeSurface {lvalue},class AcGePoint3d)

distanceTo( (Surface)arg1, (Point3d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double distanceTo(class PyAcGeSurface {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def evalPoint (self, *args, **kwargs):
      '''
evalPoint( (Surface)arg1, (Point2d)arg2) -> Point3d :

    C++ signature :
        class AcGePoint3d evalPoint(class PyAcGeSurface {lvalue},class AcGePoint2d)

evalPoint( (Surface)arg1, (Point2d)arg2, (int)arg3, (list)arg4) -> Point3d :

    C++ signature :
        class AcGePoint3d evalPoint(class PyAcGeSurface {lvalue},class AcGePoint2d,int,class boost::python::list {lvalue})

evalPoint( (Surface)arg1, (Point2d)arg2, (int)arg3, (list)arg4, (Vector3d)arg5) -> Point3d :

    C++ signature :
        class AcGePoint3d evalPoint(class PyAcGeSurface {lvalue},class AcGePoint2d,int,class boost::python::list {lvalue},class AcGeVector3d {lvalue})'''
    ...
    def getCoefficients (self, *args, **kwargs):
      '''
getCoefficients( (PlanarEnt)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple getCoefficients(class PyGePlanarEnt {lvalue})'''
    ...
    def getCoordSystem (self, *args, **kwargs):
      '''
getCoordSystem( (PlanarEnt)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple getCoordSystem(class PyGePlanarEnt {lvalue})'''
    ...
    def intersectWith (self, *args, **kwargs):
      '''
intersectWith( (Plane)arg1, (LinearEnt3d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple intersectWith(class PyGeBoundedPlane {lvalue},class PyGeLinearEnt3d)

intersectWith( (Plane)arg1, (LinearEnt3d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple intersectWith(class PyGeBoundedPlane {lvalue},class PyGeLinearEnt3d,class AcGeTol)

intersectWith( (Plane)arg1, (Plane)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple intersectWith(class PyGeBoundedPlane {lvalue},class PyGePlane)

intersectWith( (Plane)arg1, (Plane)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple intersectWith(class PyGeBoundedPlane {lvalue},class PyGePlane,class AcGeTol)

intersectWith( (Plane)arg1, (Plane)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple intersectWith(class PyGeBoundedPlane {lvalue},class PyGeBoundedPlane)

intersectWith( (Plane)arg1, (Plane)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple intersectWith(class PyGeBoundedPlane {lvalue},class PyGeBoundedPlane,class AcGeTol)'''
    ...
    def isClosedInU (self, *args, **kwargs):
      '''
isClosedInU( (Surface)arg1) -> bool :

    C++ signature :
        bool isClosedInU(class PyAcGeSurface {lvalue})

isClosedInU( (Surface)arg1, (Tol)arg2) -> bool :

    C++ signature :
        bool isClosedInU(class PyAcGeSurface {lvalue},class AcGeTol)'''
    ...
    def isClosedInV (self, *args, **kwargs):
      '''
isClosedInV( (Surface)arg1) -> bool :

    C++ signature :
        bool isClosedInV(class PyAcGeSurface {lvalue})

isClosedInV( (Surface)arg1, (Tol)arg2) -> bool :

    C++ signature :
        bool isClosedInV(class PyAcGeSurface {lvalue},class AcGeTol)'''
    ...
    def isCoplanarTo (self, *args, **kwargs):
      '''
isCoplanarTo( (PlanarEnt)arg1, (PlanarEnt)arg2) -> bool :

    C++ signature :
        bool isCoplanarTo(class PyGePlanarEnt {lvalue},class PyGePlanarEnt)

isCoplanarTo( (PlanarEnt)arg1, (PlanarEnt)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isCoplanarTo(class PyGePlanarEnt {lvalue},class PyGePlanarEnt,class AcGeTol)'''
    ...
    def isEqualTo (self, *args, **kwargs):
      '''
isEqualTo( (Entity3d)arg1, (Entity3d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity3d {lvalue},class PyGeEntity3d,class AcGeTol)'''
    ...
    def isKindOf (self, *args, **kwargs):
      '''
isKindOf( (Entity3d)arg1, (EntityId)arg2) -> bool :

    C++ signature :
        bool isKindOf(class PyGeEntity3d {lvalue},enum AcGe::EntityId)'''
    ...
    def isNormalReversed (self, *args, **kwargs):
      '''
isNormalReversed( (Surface)arg1) -> bool :

    C++ signature :
        bool isNormalReversed(class PyAcGeSurface {lvalue})'''
    ...
    def isNull (self, *args, **kwargs):
      '''
isNull( (Entity3d)arg1) -> bool :

    C++ signature :
        bool isNull(class PyGeEntity3d {lvalue})'''
    ...
    def isOn (self, *args, **kwargs):
      '''
isOn( (Surface)arg1, (Point3d)arg2) -> bool :

    C++ signature :
        bool isOn(class PyAcGeSurface {lvalue},class AcGePoint3d)

isOn( (Surface)arg1, (Point3d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isOn(class PyAcGeSurface {lvalue},class AcGePoint3d,class AcGeTol)

isOn( (Surface)arg1, (Point3d)arg2, (Point2d)arg3) -> bool :

    C++ signature :
        bool isOn(class PyAcGeSurface {lvalue},class AcGePoint3d,class AcGePoint2d {lvalue})

isOn( (Surface)arg1, (Point3d)arg2, (Point2d)arg3, (Tol)arg4) -> bool :

    C++ signature :
        bool isOn(class PyAcGeSurface {lvalue},class AcGePoint3d,class AcGePoint2d {lvalue},class AcGeTol)'''
    ...
    def isParallelTo (self, *args, **kwargs):
      '''
isParallelTo( (PlanarEnt)arg1, (LinearEnt3d)arg2) -> bool :

    C++ signature :
        bool isParallelTo(class PyGePlanarEnt {lvalue},class PyGeLinearEnt3d)

isParallelTo( (PlanarEnt)arg1, (LinearEnt3d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isParallelTo(class PyGePlanarEnt {lvalue},class PyGeLinearEnt3d,class AcGeTol)

isParallelTo( (PlanarEnt)arg1, (PlanarEnt)arg2) -> bool :

    C++ signature :
        bool isParallelTo(class PyGePlanarEnt {lvalue},class PyGePlanarEnt)

isParallelTo( (PlanarEnt)arg1, (PlanarEnt)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isParallelTo(class PyGePlanarEnt {lvalue},class PyGePlanarEnt,class AcGeTol)'''
    ...
    def isPerpendicularTo (self, *args, **kwargs):
      '''
isPerpendicularTo( (PlanarEnt)arg1, (LinearEnt3d)arg2) -> bool :

    C++ signature :
        bool isPerpendicularTo(class PyGePlanarEnt {lvalue},class PyGeLinearEnt3d)

isPerpendicularTo( (PlanarEnt)arg1, (LinearEnt3d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isPerpendicularTo(class PyGePlanarEnt {lvalue},class PyGeLinearEnt3d,class AcGeTol)

isPerpendicularTo( (PlanarEnt)arg1, (PlanarEnt)arg2) -> bool :

    C++ signature :
        bool isPerpendicularTo(class PyGePlanarEnt {lvalue},class PyGePlanarEnt)

isPerpendicularTo( (PlanarEnt)arg1, (PlanarEnt)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isPerpendicularTo(class PyGePlanarEnt {lvalue},class PyGePlanarEnt,class AcGeTol)'''
    ...
    def mirror (self, *args, **kwargs):
      '''
mirror( (Entity3d)arg1, (Plane)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} mirror(class PyGeEntity3d {lvalue},class PyGePlane)'''
    ...
    def normal (self, *args, **kwargs):
      '''
normal( (PlanarEnt)arg1) -> Vector3d :

    C++ signature :
        class AcGeVector3d normal(class PyGePlanarEnt {lvalue})'''
    ...
    def paramOf (self, *args, **kwargs):
      '''
paramOf( (Surface)arg1, (Point3d)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d paramOf(class PyAcGeSurface {lvalue},class AcGePoint3d)

paramOf( (Surface)arg1, (Point3d)arg2, (Tol)arg3) -> Point2d :

    C++ signature :
        class AcGePoint2d paramOf(class PyAcGeSurface {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def pointOnPlane (self, *args, **kwargs):
      '''
pointOnPlane( (PlanarEnt)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d pointOnPlane(class PyGePlanarEnt {lvalue})'''
    ...
    def reverseNormal (self, *args, **kwargs):
      '''
reverseNormal( (Surface)arg1) -> Surface :

    C++ signature :
        class PyAcGeSurface {lvalue} reverseNormal(class PyAcGeSurface {lvalue})'''
    ...
    def rotateBy (self, *args, **kwargs):
      '''
rotateBy( (Entity3d)arg1, (float)arg2, (Vector3d)arg3) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} rotateBy(class PyGeEntity3d {lvalue},double,class AcGeVector3d)

rotateBy( (Entity3d)arg1, (float)arg2, (Vector3d)arg3, (Point3d)arg4) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} rotateBy(class PyGeEntity3d {lvalue},double,class AcGeVector3d,class AcGePoint3d)'''
    ...
    def scaleBy (self, *args, **kwargs):
      '''
scaleBy( (Entity3d)arg1, (float)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} scaleBy(class PyGeEntity3d {lvalue},double)

scaleBy( (Entity3d)arg1, (float)arg2, (Point3d)arg3) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} scaleBy(class PyGeEntity3d {lvalue},double,class AcGePoint3d)'''
    ...
    def set (self, *args, **kwargs):
      '''
set( (Plane)arg1, (Point3d)arg2, (Vector3d)arg3, (Vector3d)arg4) -> Plane :

    C++ signature :
        class PyGeBoundedPlane {lvalue} set(class PyGeBoundedPlane {lvalue},class AcGePoint3d,class AcGeVector3d,class AcGeVector3d)

set( (Plane)arg1, (Point3d)arg2, (Point3d)arg3, (Point3d)arg4) -> Plane :

    C++ signature :
        class PyGeBoundedPlane {lvalue} set(class PyGeBoundedPlane {lvalue},class AcGePoint3d,class AcGePoint3d,class AcGePoint3d)'''
    ...
    def transformBy (self, *args, **kwargs):
      '''
transformBy( (Entity3d)arg1, (Matrix3d)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} transformBy(class PyGeEntity3d {lvalue},class AcGeMatrix3d)'''
    ...
    def translateBy (self, *args, **kwargs):
      '''
translateBy( (Entity3d)arg1, (Vector3d)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} translateBy(class PyGeEntity3d {lvalue},class AcGeVector3d)'''
    ...
    def type (self, *args, **kwargs):
      '''
type( (Entity3d)arg1) -> EntityId :

    C++ signature :
        enum AcGe::EntityId type(class PyGeEntity3d {lvalue})'''
    ...

class Point2d:
    def __add__ (self, *args, **kwargs):
      '''
__add__( (Point2d)arg1, (Vector2d)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d __add__(class AcGePoint2d {lvalue},class AcGeVector2d)'''
    ...
    def __eq__ (self, *args, **kwargs):
      '''
__eq__( (Point2d)arg1, (Point2d)arg2) -> bool :

    C++ signature :
        bool __eq__(class AcGePoint2d {lvalue},class AcGePoint2d)'''
    ...
    def __iadd__ (self, *args, **kwargs):
      '''
__iadd__( (Point2d)arg1, (Vector2d)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d {lvalue} __iadd__(class AcGePoint2d {lvalue},class AcGeVector2d)'''
    ...
    def __imul__ (self, *args, **kwargs):
      '''
__imul__( (Point2d)arg1, (float)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d {lvalue} __imul__(class AcGePoint2d {lvalue},double)'''
    ...
    def __init__ (self, *args, **kwargs):
      '''
__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1, (Point2d)arg2) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class AcGePoint2d)

__init__( (object)arg1, (float)arg2, (float)arg3) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,double,double)'''
    ...
    def __isub__ (self, *args, **kwargs):
      '''
__isub__( (Point2d)arg1, (Vector2d)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d {lvalue} __isub__(class AcGePoint2d {lvalue},class AcGeVector2d)'''
    ...
    def __itruediv__ (self, *args, **kwargs):
      '''
__itruediv__( (Point2d)arg1, (float)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d {lvalue} __itruediv__(class AcGePoint2d {lvalue},double)'''
    ...
    def __mul__ (self, *args, **kwargs):
      '''
__mul__( (Point2d)arg1, (float)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d __mul__(class AcGePoint2d {lvalue},double)'''
    ...
    def __ne__ (self, *args, **kwargs):
      '''
__ne__( (Point2d)arg1, (Point2d)arg2) -> bool :

    C++ signature :
        bool __ne__(class AcGePoint2d {lvalue},class AcGePoint2d)'''
    ...
    def __sub__ (self, *args, **kwargs):
      '''
__sub__( (Point2d)arg1, (Vector2d)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d __sub__(class AcGePoint2d {lvalue},class AcGeVector2d)

__sub__( (Point2d)arg1, (Point2d)arg2) -> Vector2d :

    C++ signature :
        class AcGeVector2d __sub__(class AcGePoint2d {lvalue},class AcGePoint2d)'''
    ...
    def __truediv__ (self, *args, **kwargs):
      '''
__truediv__( (Point2d)arg1, (float)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d __truediv__(class AcGePoint2d {lvalue},double)'''
    ...
    def asVector (self, *args, **kwargs):
      '''
asVector( (Point2d)arg1) -> Vector2d :

    C++ signature :
        class AcGeVector2d asVector(class AcGePoint2d {lvalue})'''
    ...
    def distanceTo (self, *args, **kwargs):
      '''
distanceTo( (Point2d)arg1, (Point2d)arg2) -> float :

    C++ signature :
        double distanceTo(class AcGePoint2d {lvalue},class AcGePoint2d)'''
    ...
    def isEqualTo (self, *args, **kwargs):
      '''
isEqualTo( (Point2d)arg1, (Point2d)arg2 [, (Tol)AcGeTol=<PyGe.Tol object at 0x0000020CE5B18DC0>]) -> bool :

    C++ signature :
        bool isEqualTo(class AcGePoint2d {lvalue},class AcGePoint2d [,class AcGeTol=<PyGe.Tol object at 0x0000020CE5B18DC0>])'''
    ...
    def kOrigin (self, *args, **kwargs):
      '''None'''
    ...
    def mirror (self, *args, **kwargs):
      '''
mirror( (Point2d)arg1, (object)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d {lvalue} mirror(class AcGePoint2d {lvalue},class AcGeLine2d)'''
    ...
    def rotateBy (self, *args, **kwargs):
      '''
rotateBy( (Point2d)arg1, (float)arg2 [, (Point2d)AcGePoint2d=<PyGe.Point2d object at 0x0000020CE5AC6960>]) -> Point2d :

    C++ signature :
        class AcGePoint2d {lvalue} rotateBy(class AcGePoint2d {lvalue},double [,class AcGePoint2d=<PyGe.Point2d object at 0x0000020CE5AC6960>])'''
    ...
    def scaleBy (self, *args, **kwargs):
      '''
scaleBy( (Point2d)arg1, (float)arg2 [, (Point2d)AcGePoint2d=<PyGe.Point2d object at 0x0000020CE5AC67A0>]) -> Point2d :

    C++ signature :
        class AcGePoint2d {lvalue} scaleBy(class AcGePoint2d {lvalue},double [,class AcGePoint2d=<PyGe.Point2d object at 0x0000020CE5AC67A0>])'''
    ...
    def set (self, *args, **kwargs):
      '''
set( (Point2d)arg1, (float)arg2, (float)arg3) -> Point2d :

    C++ signature :
        class AcGePoint2d {lvalue} set(class AcGePoint2d {lvalue},double,double)'''
    ...
    def setToProduct (self, *args, **kwargs):
      '''
setToProduct( (Point2d)arg1, (Matrix2d)arg2, (Point2d)arg3) -> Point2d :

    C++ signature :
        class AcGePoint2d {lvalue} setToProduct(class AcGePoint2d {lvalue},class AcGeMatrix2d,class AcGePoint2d)'''
    ...
    def setToSum (self, *args, **kwargs):
      '''
setToSum( (Point2d)arg1, (Point2d)arg2, (Vector2d)arg3) -> Point2d :

    C++ signature :
        class AcGePoint2d {lvalue} setToSum(class AcGePoint2d {lvalue},class AcGePoint2d,class AcGeVector2d)'''
    ...
    def toString (self, *args, **kwargs):
      '''
toString( (Point2d)arg1) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > toString(class AcGePoint2d)'''
    ...
    def transformBy (self, *args, **kwargs):
      '''
transformBy( (Point2d)arg1, (Matrix2d)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d {lvalue} transformBy(class AcGePoint2d {lvalue},class AcGeMatrix2d)'''
    ...
    def x (self, *args, **kwargs):
      '''None'''
    ...
    def y (self, *args, **kwargs):
      '''None'''
    ...

class Point3d:
    def __add__ (self, *args, **kwargs):
      '''
__add__( (Point3d)arg1, (Vector3d)arg2) -> Point3d :

    C++ signature :
        class AcGePoint3d __add__(class AcGePoint3d {lvalue},class AcGeVector3d)'''
    ...
    def __eq__ (self, *args, **kwargs):
      '''
__eq__( (Point3d)arg1, (Point3d)arg2) -> bool :

    C++ signature :
        bool __eq__(class AcGePoint3d {lvalue},class AcGePoint3d)'''
    ...
    def __iadd__ (self, *args, **kwargs):
      '''
__iadd__( (Point3d)arg1, (Vector3d)arg2) -> Point3d :

    C++ signature :
        class AcGePoint3d {lvalue} __iadd__(class AcGePoint3d {lvalue},class AcGeVector3d)'''
    ...
    def __imul__ (self, *args, **kwargs):
      '''
__imul__( (Point3d)arg1, (float)arg2) -> Point3d :

    C++ signature :
        class AcGePoint3d {lvalue} __imul__(class AcGePoint3d {lvalue},double)'''
    ...
    def __init__ (self, *args, **kwargs):
      '''
__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1, (Point3d)arg2) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class AcGePoint3d)

__init__( (object)arg1, (float)arg2, (float)arg3, (float)arg4) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,double,double,double)

__init__( (object)arg1, (object)arg2, (Point2d)arg3) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class AcGePlanarEnt,class AcGePoint2d)'''
    ...
    def __isub__ (self, *args, **kwargs):
      '''
__isub__( (Point3d)arg1, (Vector3d)arg2) -> Point3d :

    C++ signature :
        class AcGePoint3d {lvalue} __isub__(class AcGePoint3d {lvalue},class AcGeVector3d)'''
    ...
    def __itruediv__ (self, *args, **kwargs):
      '''
__itruediv__( (Point3d)arg1, (float)arg2) -> Point3d :

    C++ signature :
        class AcGePoint3d {lvalue} __itruediv__(class AcGePoint3d {lvalue},double)'''
    ...
    def __matmul__ (self, *args, **kwargs):
      '''
__matmul__( (Matrix3d)arg1, (Point3d)arg2) -> Point3d :

    C++ signature :
        class AcGePoint3d __matmul__(class AcGeMatrix3d,class AcGePoint3d)'''
    ...
    def __mul__ (self, *args, **kwargs):
      '''
__mul__( (Point3d)arg1, (float)arg2) -> Point3d :

    C++ signature :
        class AcGePoint3d __mul__(class AcGePoint3d {lvalue},double)

__mul__( (float)arg1, (Point3d)arg2) -> Point3d :

    C++ signature :
        class AcGePoint3d __mul__(double,class AcGePoint3d)

__mul__( (Matrix3d)arg1, (Point3d)arg2) -> Point3d :

    C++ signature :
        class AcGePoint3d __mul__(class AcGeMatrix3d,class AcGePoint3d)'''
    ...
    def __ne__ (self, *args, **kwargs):
      '''
__ne__( (Point3d)arg1, (Point3d)arg2) -> bool :

    C++ signature :
        bool __ne__(class AcGePoint3d {lvalue},class AcGePoint3d)'''
    ...
    def __sub__ (self, *args, **kwargs):
      '''
__sub__( (Point3d)arg1, (Vector3d)arg2) -> Point3d :

    C++ signature :
        class AcGePoint3d __sub__(class AcGePoint3d {lvalue},class AcGeVector3d)

__sub__( (Point3d)arg1, (Point3d)arg2) -> Vector3d :

    C++ signature :
        class AcGeVector3d __sub__(class AcGePoint3d {lvalue},class AcGePoint3d)'''
    ...
    def __truediv__ (self, *args, **kwargs):
      '''
__truediv__( (Point3d)arg1, (float)arg2) -> Point3d :

    C++ signature :
        class AcGePoint3d __truediv__(class AcGePoint3d {lvalue},double)'''
    ...
    def asVector (self, *args, **kwargs):
      '''
asVector( (Point3d)arg1) -> Vector3d :

    C++ signature :
        class AcGeVector3d asVector(class AcGePoint3d {lvalue})'''
    ...
    def convert2d (self, *args, **kwargs):
      '''
convert2d( (Point3d)arg1, (object)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d convert2d(class AcGePoint3d {lvalue},class AcGePlanarEnt)'''
    ...
    def distanceTo (self, *args, **kwargs):
      '''
distanceTo( (Point3d)arg1, (Point3d)arg2) -> float :

    C++ signature :
        double distanceTo(class AcGePoint3d {lvalue},class AcGePoint3d)'''
    ...
    def isEqualTo (self, *args, **kwargs):
      '''
isEqualTo( (Point3d)arg1, (Point3d)arg2 [, (Tol)AcGeTol=<PyGe.Tol object at 0x0000020CE5B19480>]) -> bool :

    C++ signature :
        bool isEqualTo(class AcGePoint3d {lvalue},class AcGePoint3d [,class AcGeTol=<PyGe.Tol object at 0x0000020CE5B19480>])'''
    ...
    def kOrigin (self, *args, **kwargs):
      '''None'''
    ...
    def mirror (self, *args, **kwargs):
      '''
mirror( (Point3d)arg1, (object)arg2) -> Point3d :

    C++ signature :
        class AcGePoint3d {lvalue} mirror(class AcGePoint3d {lvalue},class AcGePlane)'''
    ...
    def orthoProject (self, *args, **kwargs):
      '''
orthoProject( (Point3d)arg1, (object)arg2) -> Point3d :

    C++ signature :
        class AcGePoint3d orthoProject(class AcGePoint3d {lvalue},class AcGePlane)'''
    ...
    def project (self, *args, **kwargs):
      '''
project( (Point3d)arg1, (object)arg2, (Vector3d)arg3) -> Point3d :

    C++ signature :
        class AcGePoint3d project(class AcGePoint3d {lvalue},class AcGePlane,class AcGeVector3d)'''
    ...
    def rotateBy (self, *args, **kwargs):
      '''
rotateBy( (Point3d)arg1, (float)arg2, (Vector3d)arg3 [, (Point3d)AcGePoint3d=<PyGe.Point3d object at 0x0000020CE5A6F8C0>]) -> Point3d :

    C++ signature :
        class AcGePoint3d {lvalue} rotateBy(class AcGePoint3d {lvalue},double,class AcGeVector3d [,class AcGePoint3d=<PyGe.Point3d object at 0x0000020CE5A6F8C0>])'''
    ...
    def scaleBy (self, *args, **kwargs):
      '''
scaleBy( (Point3d)arg1, (float)arg2 [, (Point3d)AcGePoint3d=<PyGe.Point3d object at 0x0000020CE5A6FAC0>]) -> Point3d :

    C++ signature :
        class AcGePoint3d {lvalue} scaleBy(class AcGePoint3d {lvalue},double [,class AcGePoint3d=<PyGe.Point3d object at 0x0000020CE5A6FAC0>])'''
    ...
    def set (self, *args, **kwargs):
      '''
set( (Point3d)arg1, (float)arg2, (float)arg3, (float)arg4) -> Point3d :

    C++ signature :
        class AcGePoint3d {lvalue} set(class AcGePoint3d {lvalue},double,double,double)

set( (Point3d)arg1, (object)arg2, (Point2d)arg3) -> Point3d :

    C++ signature :
        class AcGePoint3d {lvalue} set(class AcGePoint3d {lvalue},class AcGePlanarEnt,class AcGePoint2d)'''
    ...
    def setToProduct (self, *args, **kwargs):
      '''
setToProduct( (Point3d)arg1, (Matrix3d)arg2, (Point3d)arg3) -> Point3d :

    C++ signature :
        class AcGePoint3d {lvalue} setToProduct(class AcGePoint3d {lvalue},class AcGeMatrix3d,class AcGePoint3d)'''
    ...
    def setToSum (self, *args, **kwargs):
      '''
setToSum( (Point3d)arg1, (Point3d)arg2, (Vector3d)arg3) -> Point3d :

    C++ signature :
        class AcGePoint3d {lvalue} setToSum(class AcGePoint3d {lvalue},class AcGePoint3d,class AcGeVector3d)'''
    ...
    def toString (self, *args, **kwargs):
      '''
toString( (Point3d)arg1) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > toString(class AcGePoint3d)'''
    ...
    def transformBy (self, *args, **kwargs):
      '''
transformBy( (Point3d)arg1, (Matrix3d)arg2) -> Point3d :

    C++ signature :
        class AcGePoint3d {lvalue} transformBy(class AcGePoint3d {lvalue},class AcGeMatrix3d)'''
    ...
    def x (self, *args, **kwargs):
      '''None'''
    ...
    def y (self, *args, **kwargs):
      '''None'''
    ...
    def z (self, *args, **kwargs):
      '''None'''
    ...

class PointEnt2d:
    def __eq__ (self, *args, **kwargs):
      '''
__eq__( (Entity2d)arg1, (Entity2d)arg2) -> bool :

    C++ signature :
        bool __eq__(class PyGeEntity2d {lvalue},class PyGeEntity2d)'''
    ...
    def __init__ (self, *args, **kwargs):
      '''Raises an exception
This class cannot be instantiated from Python
'''
    ...
    def __ne__ (self, *args, **kwargs):
      '''
__ne__( (Entity2d)arg1, (Entity2d)arg2) -> bool :

    C++ signature :
        bool __ne__(class PyGeEntity2d {lvalue},class PyGeEntity2d)'''
    ...
    def className (self, *args, **kwargs):
      '''
className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def copy (self, *args, **kwargs):
      '''
copy( (Entity2d)arg1) -> Entity2d :

    C++ signature :
        class PyGeEntity2d copy(class PyGeEntity2d {lvalue})'''
    ...
    def isEqualTo (self, *args, **kwargs):
      '''
isEqualTo( (Entity2d)arg1, (Entity2d)arg2) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity2d {lvalue},class PyGeEntity2d)

isEqualTo( (Entity2d)arg1, (Entity2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity2d {lvalue},class PyGeEntity2d,class AcGeTol)'''
    ...
    def isKindOf (self, *args, **kwargs):
      '''
isKindOf( (Entity2d)arg1, (EntityId)arg2) -> bool :

    C++ signature :
        bool isKindOf(class PyGeEntity2d {lvalue},enum AcGe::EntityId)'''
    ...
    def isNull (self, *args, **kwargs):
      '''
isNull( (Entity2d)arg1) -> bool :

    C++ signature :
        bool isNull(class PyGeEntity2d {lvalue})'''
    ...
    def isOn (self, *args, **kwargs):
      '''
isOn( (Entity2d)arg1, (Point2d)arg2) -> bool :

    C++ signature :
        bool isOn(class PyGeEntity2d {lvalue},class AcGePoint2d)

isOn( (Entity2d)arg1, (Point2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeEntity2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def mirror (self, *args, **kwargs):
      '''
mirror( (Entity2d)arg1, (Line2d)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} mirror(class PyGeEntity2d {lvalue},class PyGeLine2d)'''
    ...
    def point2d (self, *args, **kwargs):
      '''
point2d( (PointEnt2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d point2d(class PyGePointEnt2d {lvalue})'''
    ...
    def rotateBy (self, *args, **kwargs):
      '''
rotateBy( (Entity2d)arg1, (float)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} rotateBy(class PyGeEntity2d {lvalue},double)

rotateBy( (Entity2d)arg1, (float)arg2, (Point2d)arg3) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} rotateBy(class PyGeEntity2d {lvalue},double,class AcGePoint2d)'''
    ...
    def scaleBy (self, *args, **kwargs):
      '''
scaleBy( (Entity2d)arg1, (float)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} scaleBy(class PyGeEntity2d {lvalue},double)

scaleBy( (Entity2d)arg1, (float)arg2, (Point2d)arg3) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} scaleBy(class PyGeEntity2d {lvalue},double,class AcGePoint2d)'''
    ...
    def transformBy (self, *args, **kwargs):
      '''
transformBy( (Entity2d)arg1, (Matrix2d)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} transformBy(class PyGeEntity2d {lvalue},class AcGeMatrix2d)'''
    ...
    def translateBy (self, *args, **kwargs):
      '''
translateBy( (Entity2d)arg1, (Vector2d)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} translateBy(class PyGeEntity2d {lvalue},class AcGeVector2d)'''
    ...
    def type (self, *args, **kwargs):
      '''
type( (Entity2d)arg1) -> EntityId :

    C++ signature :
        enum AcGe::EntityId type(class PyGeEntity2d {lvalue})'''
    ...

class PointEnt3d:
    def __eq__ (self, *args, **kwargs):
      '''
__eq__( (Entity3d)arg1, (Entity3d)arg2) -> bool :

    C++ signature :
        bool __eq__(class PyGeEntity3d {lvalue},class PyGeEntity3d)'''
    ...
    def __init__ (self, *args, **kwargs):
      '''Raises an exception
This class cannot be instantiated from Python
'''
    ...
    def __ne__ (self, *args, **kwargs):
      '''
__ne__( (Entity3d)arg1, (Entity3d)arg2) -> bool :

    C++ signature :
        bool __ne__(class PyGeEntity3d {lvalue},class PyGeEntity3d)'''
    ...
    def className (self, *args, **kwargs):
      '''
className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def copy (self, *args, **kwargs):
      '''
copy( (Entity3d)arg1) -> Entity3d :

    C++ signature :
        class PyGeEntity3d copy(class PyGeEntity3d {lvalue})'''
    ...
    def isEqualTo (self, *args, **kwargs):
      '''
isEqualTo( (Entity3d)arg1, (Entity3d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity3d {lvalue},class PyGeEntity3d,class AcGeTol)'''
    ...
    def isKindOf (self, *args, **kwargs):
      '''
isKindOf( (Entity3d)arg1, (EntityId)arg2) -> bool :

    C++ signature :
        bool isKindOf(class PyGeEntity3d {lvalue},enum AcGe::EntityId)'''
    ...
    def isNull (self, *args, **kwargs):
      '''
isNull( (Entity3d)arg1) -> bool :

    C++ signature :
        bool isNull(class PyGeEntity3d {lvalue})'''
    ...
    def isOn (self, *args, **kwargs):
      '''
isOn( (Entity3d)arg1, (Point3d)arg2) -> bool :

    C++ signature :
        bool isOn(class PyGeEntity3d {lvalue},class AcGePoint3d)

isOn( (Entity3d)arg1, (Point3d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeEntity3d {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def mirror (self, *args, **kwargs):
      '''
mirror( (Entity3d)arg1, (Plane)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} mirror(class PyGeEntity3d {lvalue},class PyGePlane)'''
    ...
    def rotateBy (self, *args, **kwargs):
      '''
rotateBy( (Entity3d)arg1, (float)arg2, (Vector3d)arg3) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} rotateBy(class PyGeEntity3d {lvalue},double,class AcGeVector3d)

rotateBy( (Entity3d)arg1, (float)arg2, (Vector3d)arg3, (Point3d)arg4) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} rotateBy(class PyGeEntity3d {lvalue},double,class AcGeVector3d,class AcGePoint3d)'''
    ...
    def scaleBy (self, *args, **kwargs):
      '''
scaleBy( (Entity3d)arg1, (float)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} scaleBy(class PyGeEntity3d {lvalue},double)

scaleBy( (Entity3d)arg1, (float)arg2, (Point3d)arg3) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} scaleBy(class PyGeEntity3d {lvalue},double,class AcGePoint3d)'''
    ...
    def transformBy (self, *args, **kwargs):
      '''
transformBy( (Entity3d)arg1, (Matrix3d)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} transformBy(class PyGeEntity3d {lvalue},class AcGeMatrix3d)'''
    ...
    def translateBy (self, *args, **kwargs):
      '''
translateBy( (Entity3d)arg1, (Vector3d)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} translateBy(class PyGeEntity3d {lvalue},class AcGeVector3d)'''
    ...
    def type (self, *args, **kwargs):
      '''
type( (Entity3d)arg1) -> EntityId :

    C++ signature :
        enum AcGe::EntityId type(class PyGeEntity3d {lvalue})'''
    ...

class PointOnCurve2d:
    def __eq__ (self, *args, **kwargs):
      '''
__eq__( (Entity2d)arg1, (Entity2d)arg2) -> bool :

    C++ signature :
        bool __eq__(class PyGeEntity2d {lvalue},class PyGeEntity2d)'''
    ...
    def __init__ (self, *args, **kwargs):
      '''
__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1, (Curve2d)arg2) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class PyGeCurve2d)

__init__( (object)arg1, (Curve2d)arg2, (float)arg3) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class PyGeCurve2d,double)'''
    ...
    def __ne__ (self, *args, **kwargs):
      '''
__ne__( (Entity2d)arg1, (Entity2d)arg2) -> bool :

    C++ signature :
        bool __ne__(class PyGeEntity2d {lvalue},class PyGeEntity2d)'''
    ...
    def className (self, *args, **kwargs):
      '''
className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def copy (self, *args, **kwargs):
      '''
copy( (Entity2d)arg1) -> Entity2d :

    C++ signature :
        class PyGeEntity2d copy(class PyGeEntity2d {lvalue})'''
    ...
    def curve (self, *args, **kwargs):
      '''
curve( (PointOnCurve2d)arg1) -> Curve2d :

    C++ signature :
        class PyGeCurve2d curve(class PyGePointOnCurve2d {lvalue})'''
    ...
    def deriv (self, *args, **kwargs):
      '''
deriv( (PointOnCurve2d)arg1, (int)arg2) -> Vector2d :

    C++ signature :
        class AcGeVector2d deriv(class PyGePointOnCurve2d {lvalue},int)

deriv( (PointOnCurve2d)arg1, (int)arg2, (float)arg3) -> Vector2d :

    C++ signature :
        class AcGeVector2d deriv(class PyGePointOnCurve2d {lvalue},int,double)

deriv( (PointOnCurve2d)arg1, (int)arg2, (Curve2d)arg3, (float)arg4) -> Vector2d :

    C++ signature :
        class AcGeVector2d deriv(class PyGePointOnCurve2d {lvalue},int,class PyGeCurve2d,double)'''
    ...
    def isEqualTo (self, *args, **kwargs):
      '''
isEqualTo( (Entity2d)arg1, (Entity2d)arg2) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity2d {lvalue},class PyGeEntity2d)

isEqualTo( (Entity2d)arg1, (Entity2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity2d {lvalue},class PyGeEntity2d,class AcGeTol)'''
    ...
    def isKindOf (self, *args, **kwargs):
      '''
isKindOf( (Entity2d)arg1, (EntityId)arg2) -> bool :

    C++ signature :
        bool isKindOf(class PyGeEntity2d {lvalue},enum AcGe::EntityId)'''
    ...
    def isNull (self, *args, **kwargs):
      '''
isNull( (Entity2d)arg1) -> bool :

    C++ signature :
        bool isNull(class PyGeEntity2d {lvalue})'''
    ...
    def isOn (self, *args, **kwargs):
      '''
isOn( (Entity2d)arg1, (Point2d)arg2) -> bool :

    C++ signature :
        bool isOn(class PyGeEntity2d {lvalue},class AcGePoint2d)

isOn( (Entity2d)arg1, (Point2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeEntity2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def mirror (self, *args, **kwargs):
      '''
mirror( (Entity2d)arg1, (Line2d)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} mirror(class PyGeEntity2d {lvalue},class PyGeLine2d)'''
    ...
    def parameter (self, *args, **kwargs):
      '''
parameter( (PointOnCurve2d)arg1) -> float :

    C++ signature :
        double parameter(class PyGePointOnCurve2d {lvalue})'''
    ...
    def point (self, *args, **kwargs):
      '''
point( (PointOnCurve2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d point(class PyGePointOnCurve2d {lvalue})

point( (PointOnCurve2d)arg1, (float)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d point(class PyGePointOnCurve2d {lvalue},double)

point( (PointOnCurve2d)arg1, (Curve2d)arg2, (float)arg3) -> Point2d :

    C++ signature :
        class AcGePoint2d point(class PyGePointOnCurve2d {lvalue},class PyGeCurve2d,double)'''
    ...
    def point2d (self, *args, **kwargs):
      '''
point2d( (PointEnt2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d point2d(class PyGePointEnt2d {lvalue})'''
    ...
    def rotateBy (self, *args, **kwargs):
      '''
rotateBy( (Entity2d)arg1, (float)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} rotateBy(class PyGeEntity2d {lvalue},double)

rotateBy( (Entity2d)arg1, (float)arg2, (Point2d)arg3) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} rotateBy(class PyGeEntity2d {lvalue},double,class AcGePoint2d)'''
    ...
    def scaleBy (self, *args, **kwargs):
      '''
scaleBy( (Entity2d)arg1, (float)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} scaleBy(class PyGeEntity2d {lvalue},double)

scaleBy( (Entity2d)arg1, (float)arg2, (Point2d)arg3) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} scaleBy(class PyGeEntity2d {lvalue},double,class AcGePoint2d)'''
    ...
    def setCurve (self, *args, **kwargs):
      '''
setCurve( (PointOnCurve2d)arg1, (Curve2d)arg2) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d {lvalue} setCurve(class PyGePointOnCurve2d {lvalue},class PyGeCurve2d)'''
    ...
    def setParameter (self, *args, **kwargs):
      '''
setParameter( (PointOnCurve2d)arg1, (float)arg2) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d {lvalue} setParameter(class PyGePointOnCurve2d {lvalue},double)'''
    ...
    def transformBy (self, *args, **kwargs):
      '''
transformBy( (Entity2d)arg1, (Matrix2d)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} transformBy(class PyGeEntity2d {lvalue},class AcGeMatrix2d)'''
    ...
    def translateBy (self, *args, **kwargs):
      '''
translateBy( (Entity2d)arg1, (Vector2d)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} translateBy(class PyGeEntity2d {lvalue},class AcGeVector2d)'''
    ...
    def type (self, *args, **kwargs):
      '''
type( (Entity2d)arg1) -> EntityId :

    C++ signature :
        enum AcGe::EntityId type(class PyGeEntity2d {lvalue})'''
    ...

class PointOnCurve3d:
    def __eq__ (self, *args, **kwargs):
      '''
__eq__( (Entity3d)arg1, (Entity3d)arg2) -> bool :

    C++ signature :
        bool __eq__(class PyGeEntity3d {lvalue},class PyGeEntity3d)'''
    ...
    def __init__ (self, *args, **kwargs):
      '''
__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
    ...
    def __ne__ (self, *args, **kwargs):
      '''
__ne__( (Entity3d)arg1, (Entity3d)arg2) -> bool :

    C++ signature :
        bool __ne__(class PyGeEntity3d {lvalue},class PyGeEntity3d)'''
    ...
    def className (self, *args, **kwargs):
      '''
className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def copy (self, *args, **kwargs):
      '''
copy( (Entity3d)arg1) -> Entity3d :

    C++ signature :
        class PyGeEntity3d copy(class PyGeEntity3d {lvalue})'''
    ...
    def isEqualTo (self, *args, **kwargs):
      '''
isEqualTo( (Entity3d)arg1, (Entity3d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity3d {lvalue},class PyGeEntity3d,class AcGeTol)'''
    ...
    def isKindOf (self, *args, **kwargs):
      '''
isKindOf( (Entity3d)arg1, (EntityId)arg2) -> bool :

    C++ signature :
        bool isKindOf(class PyGeEntity3d {lvalue},enum AcGe::EntityId)'''
    ...
    def isNull (self, *args, **kwargs):
      '''
isNull( (Entity3d)arg1) -> bool :

    C++ signature :
        bool isNull(class PyGeEntity3d {lvalue})'''
    ...
    def isOn (self, *args, **kwargs):
      '''
isOn( (Entity3d)arg1, (Point3d)arg2) -> bool :

    C++ signature :
        bool isOn(class PyGeEntity3d {lvalue},class AcGePoint3d)

isOn( (Entity3d)arg1, (Point3d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeEntity3d {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def mirror (self, *args, **kwargs):
      '''
mirror( (Entity3d)arg1, (Plane)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} mirror(class PyGeEntity3d {lvalue},class PyGePlane)'''
    ...
    def rotateBy (self, *args, **kwargs):
      '''
rotateBy( (Entity3d)arg1, (float)arg2, (Vector3d)arg3) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} rotateBy(class PyGeEntity3d {lvalue},double,class AcGeVector3d)

rotateBy( (Entity3d)arg1, (float)arg2, (Vector3d)arg3, (Point3d)arg4) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} rotateBy(class PyGeEntity3d {lvalue},double,class AcGeVector3d,class AcGePoint3d)'''
    ...
    def scaleBy (self, *args, **kwargs):
      '''
scaleBy( (Entity3d)arg1, (float)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} scaleBy(class PyGeEntity3d {lvalue},double)

scaleBy( (Entity3d)arg1, (float)arg2, (Point3d)arg3) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} scaleBy(class PyGeEntity3d {lvalue},double,class AcGePoint3d)'''
    ...
    def transformBy (self, *args, **kwargs):
      '''
transformBy( (Entity3d)arg1, (Matrix3d)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} transformBy(class PyGeEntity3d {lvalue},class AcGeMatrix3d)'''
    ...
    def translateBy (self, *args, **kwargs):
      '''
translateBy( (Entity3d)arg1, (Vector3d)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} translateBy(class PyGeEntity3d {lvalue},class AcGeVector3d)'''
    ...
    def type (self, *args, **kwargs):
      '''
type( (Entity3d)arg1) -> EntityId :

    C++ signature :
        enum AcGe::EntityId type(class PyGeEntity3d {lvalue})'''
    ...

class Polyline2d:
    def __eq__ (self, *args, **kwargs):
      '''
__eq__( (Entity2d)arg1, (Entity2d)arg2) -> bool :

    C++ signature :
        bool __eq__(class PyGeEntity2d {lvalue},class PyGeEntity2d)'''
    ...
    def __init__ (self, *args, **kwargs):
      '''
__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1, (list)arg2) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class boost::python::list)

__init__( (object)arg1, (KnotVector)arg2, (list)arg3) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class PyGeKnotVector,class boost::python::list)

__init__( (object)arg1, (Curve2d)arg2, (float)arg3) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class PyGeCurve2d,double)'''
    ...
    def __ne__ (self, *args, **kwargs):
      '''
__ne__( (Entity2d)arg1, (Entity2d)arg2) -> bool :

    C++ signature :
        bool __ne__(class PyGeEntity2d {lvalue},class PyGeEntity2d)'''
    ...
    def area (self, *args, **kwargs):
      '''
area( (Curve2d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double area(class PyGeCurve2d {lvalue},double,double)

area( (Curve2d)arg1, (float)arg2, (float)arg3, (Tol)arg4) -> float :

    C++ signature :
        double area(class PyGeCurve2d {lvalue},double,double,class AcGeTol)'''
    ...
    def boundBlock (self, *args, **kwargs):
      '''
boundBlock( (Curve2d)arg1) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d boundBlock(class PyGeCurve2d {lvalue})

boundBlock( (Curve2d)arg1, (Interval)arg2) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d boundBlock(class PyGeCurve2d {lvalue},class PyGeInterval)'''
    ...
    def className (self, *args, **kwargs):
      '''
className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def closestPointTo (self, *args, **kwargs):
      '''
closestPointTo( (Curve2d)arg1, (Point2d)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d closestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d)

closestPointTo( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> Point2d :

    C++ signature :
        class AcGePoint2d closestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)

closestPointTo( (Curve2d)arg1, (Curve2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointTo(class PyGeCurve2d {lvalue},class PyGeCurve2d)

closestPointTo( (Curve2d)arg1, (Curve2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointTo(class PyGeCurve2d {lvalue},class PyGeCurve2d,class AcGeTol)'''
    ...
    def continuityAtKnot (self, *args, **kwargs):
      '''
continuityAtKnot( (SplineEnt2d)arg1, (int)arg2) -> int :

    C++ signature :
        int continuityAtKnot(class PyGeSplineEnt2d {lvalue},int)

continuityAtKnot( (SplineEnt2d)arg1, (int)arg2, (Tol)arg3) -> int :

    C++ signature :
        int continuityAtKnot(class PyGeSplineEnt2d {lvalue},int,class AcGeTol)'''
    ...
    def controlPointAt (self, *args, **kwargs):
      '''
controlPointAt( (SplineEnt2d)arg1, (int)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d controlPointAt(class PyGeSplineEnt2d {lvalue},int)'''
    ...
    def copy (self, *args, **kwargs):
      '''
copy( (Entity2d)arg1) -> Entity2d :

    C++ signature :
        class PyGeEntity2d copy(class PyGeEntity2d {lvalue})'''
    ...
    def degree (self, *args, **kwargs):
      '''
degree( (SplineEnt2d)arg1) -> int :

    C++ signature :
        int degree(class PyGeSplineEnt2d {lvalue})'''
    ...
    def distanceTo (self, *args, **kwargs):
      '''
distanceTo( (Curve2d)arg1, (Point2d)arg2) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class AcGePoint2d)

distanceTo( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)

distanceTo( (Curve2d)arg1, (Curve2d)arg2) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class PyGeCurve2d)

distanceTo( (Curve2d)arg1, (Curve2d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class PyGeCurve2d,class AcGeTol)'''
    ...
    def endParam (self, *args, **kwargs):
      '''
endParam( (SplineEnt2d)arg1) -> float :

    C++ signature :
        double endParam(class PyGeSplineEnt2d {lvalue})'''
    ...
    def endPoint (self, *args, **kwargs):
      '''
endPoint( (SplineEnt2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d endPoint(class PyGeSplineEnt2d {lvalue})'''
    ...
    def evalPoint (self, *args, **kwargs):
      '''
evalPoint( (Curve2d)arg1, (float)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d evalPoint(class PyGeCurve2d {lvalue},double)

evalPoint( (Curve2d)arg1, (float)arg2, (int)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple evalPoint(class PyGeCurve2d {lvalue},double,int)'''
    ...
    def explode (self, *args, **kwargs):
      '''
explode( (Curve2d)arg1) -> list :

    C++ signature :
        class boost::python::list explode(class PyGeCurve2d {lvalue})

explode( (Curve2d)arg1, (Interval)arg2) -> list :

    C++ signature :
        class boost::python::list explode(class PyGeCurve2d {lvalue},class PyGeInterval)'''
    ...
    def fitPointAt (self, *args, **kwargs):
      '''
fitPointAt( (Polyline2d)arg1, (int)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d fitPointAt(class PyGePolyline2d {lvalue},int)'''
    ...
    def getClosestPointTo (self, *args, **kwargs):
      '''
getClosestPointTo( (Curve2d)arg1, (Point2d)arg2) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getClosestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d)

getClosestPointTo( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getClosestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def getClosestPointsTo (self, *args, **kwargs):
      '''
getClosestPointsTo( (Curve2d)arg1, (Curve2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getClosestPointsTo(class PyGeCurve2d {lvalue},class PyGeCurve2d)

getClosestPointsTo( (Curve2d)arg1, (Curve2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple getClosestPointsTo(class PyGeCurve2d {lvalue},class PyGeCurve2d,class AcGeTol)'''
    ...
    def getEndPoint (self, *args, **kwargs):
      '''
getEndPoint( (Curve2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d getEndPoint(class PyGeCurve2d {lvalue})'''
    ...
    def getInterval (self, *args, **kwargs):
      '''
getInterval( (Curve2d)arg1) -> Interval :

    C++ signature :
        class PyGeInterval getInterval(class PyGeCurve2d {lvalue})'''
    ...
    def getNormalPoint (self, *args, **kwargs):
      '''
getNormalPoint( (Curve2d)arg1, (Point2d)arg2) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getNormalPoint(class PyGeCurve2d {lvalue},class AcGePoint2d)

getNormalPoint( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getNormalPoint(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def getSamplePoints (self, *args, **kwargs):
      '''
getSamplePoints( (Curve2d)arg1, (int)arg2) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve2d {lvalue},int)

getSamplePoints( (Curve2d)arg1, (float)arg2, (float)arg3, (float)arg4) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve2d {lvalue},double,double,double)'''
    ...
    def getSplitCurves (self, *args, **kwargs):
      '''
getSplitCurves( (Curve2d)arg1, (float)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getSplitCurves(class PyGeCurve2d {lvalue},double)'''
    ...
    def getStartPoint (self, *args, **kwargs):
      '''
getStartPoint( (Curve2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d getStartPoint(class PyGeCurve2d {lvalue})'''
    ...
    def getTrimmedOffset (self, *args, **kwargs):
      '''
getTrimmedOffset( (Curve2d)arg1, (float)arg2, (OffsetCrvExtType)arg3) -> list :

    C++ signature :
        class boost::python::list getTrimmedOffset(class PyGeCurve2d {lvalue},double,enum AcGe::OffsetCrvExtType)

getTrimmedOffset( (Curve2d)arg1, (float)arg2, (OffsetCrvExtType)arg3, (Tol)arg4) -> list :

    C++ signature :
        class boost::python::list getTrimmedOffset(class PyGeCurve2d {lvalue},double,enum AcGe::OffsetCrvExtType,class AcGeTol)'''
    ...
    def hasEndPoint (self, *args, **kwargs):
      '''
hasEndPoint( (Curve2d)arg1) -> bool :

    C++ signature :
        bool hasEndPoint(class PyGeCurve2d {lvalue})'''
    ...
    def hasFitData (self, *args, **kwargs):
      '''
hasFitData( (SplineEnt2d)arg1) -> bool :

    C++ signature :
        bool hasFitData(class PyGeSplineEnt2d {lvalue})'''
    ...
    def hasStartPoint (self, *args, **kwargs):
      '''
hasStartPoint( (Curve2d)arg1) -> bool :

    C++ signature :
        bool hasStartPoint(class PyGeCurve2d {lvalue})'''
    ...
    def isClosed (self, *args, **kwargs):
      '''
isClosed( (Curve2d)arg1) -> bool :

    C++ signature :
        bool isClosed(class PyGeCurve2d {lvalue})

isClosed( (Curve2d)arg1, (Tol)arg2) -> bool :

    C++ signature :
        bool isClosed(class PyGeCurve2d {lvalue},class AcGeTol)'''
    ...
    def isDegenerate (self, *args, **kwargs):
      '''
isDegenerate( (Curve2d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isDegenerate(class PyGeCurve2d {lvalue})

isDegenerate( (Curve2d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isDegenerate(class PyGeCurve2d {lvalue},class AcGeTol)'''
    ...
    def isEqualTo (self, *args, **kwargs):
      '''
isEqualTo( (Entity2d)arg1, (Entity2d)arg2) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity2d {lvalue},class PyGeEntity2d)

isEqualTo( (Entity2d)arg1, (Entity2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity2d {lvalue},class PyGeEntity2d,class AcGeTol)'''
    ...
    def isKindOf (self, *args, **kwargs):
      '''
isKindOf( (Entity2d)arg1, (EntityId)arg2) -> bool :

    C++ signature :
        bool isKindOf(class PyGeEntity2d {lvalue},enum AcGe::EntityId)'''
    ...
    def isLinear (self, *args, **kwargs):
      '''
isLinear( (Curve2d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isLinear(class PyGeCurve2d {lvalue})

isLinear( (Curve2d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isLinear(class PyGeCurve2d {lvalue},class AcGeTol)'''
    ...
    def isNull (self, *args, **kwargs):
      '''
isNull( (Entity2d)arg1) -> bool :

    C++ signature :
        bool isNull(class PyGeEntity2d {lvalue})'''
    ...
    def isOn (self, *args, **kwargs):
      '''
isOn( (Curve2d)arg1, (Point2d)arg2) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve2d {lvalue},class AcGePoint2d)

isOn( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)

isOn( (Curve2d)arg1, (Point2d)arg2, (float)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve2d {lvalue},class AcGePoint2d,double {lvalue})

isOn( (Curve2d)arg1, (Point2d)arg2, (float)arg3, (Tol)arg4) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve2d {lvalue},class AcGePoint2d,double {lvalue},class AcGeTol)

isOn( (Curve2d)arg1, (float)arg2) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve2d {lvalue},double)

isOn( (Curve2d)arg1, (float)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve2d {lvalue},double,class AcGeTol)'''
    ...
    def isPeriodic (self, *args, **kwargs):
      '''
isPeriodic( (Curve2d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isPeriodic(class PyGeCurve2d {lvalue})'''
    ...
    def isRational (self, *args, **kwargs):
      '''
isRational( (SplineEnt2d)arg1) -> bool :

    C++ signature :
        bool isRational(class PyGeSplineEnt2d {lvalue})'''
    ...
    def knotAt (self, *args, **kwargs):
      '''
knotAt( (SplineEnt2d)arg1, (int)arg2) -> float :

    C++ signature :
        double knotAt(class PyGeSplineEnt2d {lvalue},int)'''
    ...
    def knots (self, *args, **kwargs):
      '''
knots( (SplineEnt2d)arg1) -> KnotVector :

    C++ signature :
        class PyGeKnotVector knots(class PyGeSplineEnt2d {lvalue})'''
    ...
    def length (self, *args, **kwargs):
      '''
length( (Curve2d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double length(class PyGeCurve2d {lvalue},double,double)

length( (Curve2d)arg1, (float)arg2, (float)arg3, (float)arg4) -> float :

    C++ signature :
        double length(class PyGeCurve2d {lvalue},double,double,double)'''
    ...
    def mirror (self, *args, **kwargs):
      '''
mirror( (Entity2d)arg1, (Line2d)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} mirror(class PyGeEntity2d {lvalue},class PyGeLine2d)'''
    ...
    def numControlPoints (self, *args, **kwargs):
      '''
numControlPoints( (SplineEnt2d)arg1) -> int :

    C++ signature :
        int numControlPoints(class PyGeSplineEnt2d {lvalue})'''
    ...
    def numFitPoints (self, *args, **kwargs):
      '''
numFitPoints( (Polyline2d)arg1) -> int :

    C++ signature :
        int numFitPoints(class PyGePolyline2d {lvalue})'''
    ...
    def numKnots (self, *args, **kwargs):
      '''
numKnots( (SplineEnt2d)arg1) -> int :

    C++ signature :
        int numKnots(class PyGeSplineEnt2d {lvalue})'''
    ...
    def order (self, *args, **kwargs):
      '''
order( (SplineEnt2d)arg1) -> int :

    C++ signature :
        int order(class PyGeSplineEnt2d {lvalue})'''
    ...
    def orthoBoundBlock (self, *args, **kwargs):
      '''
orthoBoundBlock( (Curve2d)arg1) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d orthoBoundBlock(class PyGeCurve2d {lvalue})

orthoBoundBlock( (Curve2d)arg1, (Interval)arg2) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d orthoBoundBlock(class PyGeCurve2d {lvalue},class PyGeInterval)'''
    ...
    def paramAtLength (self, *args, **kwargs):
      '''
paramAtLength( (Curve2d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double paramAtLength(class PyGeCurve2d {lvalue},double,double)

paramAtLength( (Curve2d)arg1, (float)arg2, (float)arg3, (bool)arg4, (float)arg5) -> float :

    C++ signature :
        double paramAtLength(class PyGeCurve2d {lvalue},double,double,bool,double)'''
    ...
    def paramOf (self, *args, **kwargs):
      '''
paramOf( (Curve2d)arg1, (Point2d)arg2) -> float :

    C++ signature :
        double paramOf(class PyGeCurve2d {lvalue},class AcGePoint2d)

paramOf( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double paramOf(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def reverseParam (self, *args, **kwargs):
      '''
reverseParam( (Curve2d)arg1) -> Curve2d :

    C++ signature :
        class PyGeCurve2d {lvalue} reverseParam(class PyGeCurve2d {lvalue})'''
    ...
    def rotateBy (self, *args, **kwargs):
      '''
rotateBy( (Entity2d)arg1, (float)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} rotateBy(class PyGeEntity2d {lvalue},double)

rotateBy( (Entity2d)arg1, (float)arg2, (Point2d)arg3) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} rotateBy(class PyGeEntity2d {lvalue},double,class AcGePoint2d)'''
    ...
    def scaleBy (self, *args, **kwargs):
      '''
scaleBy( (Entity2d)arg1, (float)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} scaleBy(class PyGeEntity2d {lvalue},double)

scaleBy( (Entity2d)arg1, (float)arg2, (Point2d)arg3) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} scaleBy(class PyGeEntity2d {lvalue},double,class AcGePoint2d)'''
    ...
    def setControlPointAt (self, *args, **kwargs):
      '''
setControlPointAt( (SplineEnt2d)arg1, (int)arg2, (Point2d)arg3) -> SplineEnt2d :

    C++ signature :
        class PyGeSplineEnt2d {lvalue} setControlPointAt(class PyGeSplineEnt2d {lvalue},int,class AcGePoint2d)'''
    ...
    def setFitPointAt (self, *args, **kwargs):
      '''
setFitPointAt( (Polyline2d)arg1, (int)arg2, (Point2d)arg3) -> Polyline2d :

    C++ signature :
        class PyGePolyline2d {lvalue} setFitPointAt(class PyGePolyline2d {lvalue},int,class AcGePoint2d)'''
    ...
    def setInterval (self, *args, **kwargs):
      '''
setInterval( (Curve2d)arg1) -> Curve2d :

    C++ signature :
        class PyGeCurve2d {lvalue} setInterval(class PyGeCurve2d {lvalue})

setInterval( (Curve2d)arg1, (Interval)arg2) -> bool :

    C++ signature :
        bool setInterval(class PyGeCurve2d {lvalue},class PyGeInterval)'''
    ...
    def setKnotAt (self, *args, **kwargs):
      '''
setKnotAt( (SplineEnt2d)arg1, (int)arg2, (float)arg3) -> SplineEnt2d :

    C++ signature :
        class PyGeSplineEnt2d {lvalue} setKnotAt(class PyGeSplineEnt2d {lvalue},int,double)'''
    ...
    def startParam (self, *args, **kwargs):
      '''
startParam( (SplineEnt2d)arg1) -> float :

    C++ signature :
        double startParam(class PyGeSplineEnt2d {lvalue})'''
    ...
    def startPoint (self, *args, **kwargs):
      '''
startPoint( (SplineEnt2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d startPoint(class PyGeSplineEnt2d {lvalue})'''
    ...
    def transformBy (self, *args, **kwargs):
      '''
transformBy( (Entity2d)arg1, (Matrix2d)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} transformBy(class PyGeEntity2d {lvalue},class AcGeMatrix2d)'''
    ...
    def translateBy (self, *args, **kwargs):
      '''
translateBy( (Entity2d)arg1, (Vector2d)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} translateBy(class PyGeEntity2d {lvalue},class AcGeVector2d)'''
    ...
    def type (self, *args, **kwargs):
      '''
type( (Entity2d)arg1) -> EntityId :

    C++ signature :
        enum AcGe::EntityId type(class PyGeEntity2d {lvalue})'''
    ...

class Polyline3d:
    def __eq__ (self, *args, **kwargs):
      '''
__eq__( (Entity3d)arg1, (Entity3d)arg2) -> bool :

    C++ signature :
        bool __eq__(class PyGeEntity3d {lvalue},class PyGeEntity3d)'''
    ...
    def __init__ (self, *args, **kwargs):
      '''
__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1, (list)arg2) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class boost::python::list)

__init__( (object)arg1, (KnotVector)arg2, (list)arg3) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class PyGeKnotVector,class boost::python::list)

__init__( (object)arg1, (Curve3d)arg2, (float)arg3) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class PyGeCurve3d,double)'''
    ...
    def __ne__ (self, *args, **kwargs):
      '''
__ne__( (Entity3d)arg1, (Entity3d)arg2) -> bool :

    C++ signature :
        bool __ne__(class PyGeEntity3d {lvalue},class PyGeEntity3d)'''
    ...
    def area (self, *args, **kwargs):
      '''
area( (Curve3d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double area(class PyGeCurve3d {lvalue},double,double)

area( (Curve3d)arg1, (float)arg2, (float)arg3, (Tol)arg4) -> float :

    C++ signature :
        double area(class PyGeCurve3d {lvalue},double,double,class AcGeTol)'''
    ...
    def boundBlock (self, *args, **kwargs):
      '''
boundBlock( (Curve3d)arg1) -> BoundBlock3d :

    C++ signature :
        class PyGeBoundBlock3d boundBlock(class PyGeCurve3d {lvalue})

boundBlock( (Curve3d)arg1, (Interval)arg2) -> BoundBlock3d :

    C++ signature :
        class PyGeBoundBlock3d boundBlock(class PyGeCurve3d {lvalue},class PyGeInterval)'''
    ...
    def className (self, *args, **kwargs):
      '''
className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def closestPointTo (self, *args, **kwargs):
      '''
closestPointTo( (Curve3d)arg1, (Point3d)arg2) -> Point3d :

    C++ signature :
        class AcGePoint3d closestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d)

closestPointTo( (Curve3d)arg1, (Point3d)arg2, (Tol)arg3) -> Point3d :

    C++ signature :
        class AcGePoint3d closestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeTol)

closestPointTo( (Curve3d)arg1, (Curve3d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointTo(class PyGeCurve3d {lvalue},class PyGeCurve3d)

closestPointTo( (Curve3d)arg1, (Curve3d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointTo(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeTol)'''
    ...
    def continuityAtKnot (self, *args, **kwargs):
      '''
continuityAtKnot( (SplineEnt3d)arg1, (int)arg2) -> int :

    C++ signature :
        int continuityAtKnot(class PyGeSplineEnt3d {lvalue},int)

continuityAtKnot( (SplineEnt3d)arg1, (int)arg2, (Tol)arg3) -> int :

    C++ signature :
        int continuityAtKnot(class PyGeSplineEnt3d {lvalue},int,class AcGeTol)'''
    ...
    def controlPointAt (self, *args, **kwargs):
      '''
controlPointAt( (SplineEnt3d)arg1, (int)arg2) -> Point3d :

    C++ signature :
        class AcGePoint3d controlPointAt(class PyGeSplineEnt3d {lvalue},int)'''
    ...
    def copy (self, *args, **kwargs):
      '''
copy( (Entity3d)arg1) -> Entity3d :

    C++ signature :
        class PyGeEntity3d copy(class PyGeEntity3d {lvalue})'''
    ...
    def degree (self, *args, **kwargs):
      '''
degree( (SplineEnt3d)arg1) -> int :

    C++ signature :
        int degree(class PyGeSplineEnt3d {lvalue})'''
    ...
    def distanceTo (self, *args, **kwargs):
      '''
distanceTo( (Curve3d)arg1, (Point3d)arg2) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve3d {lvalue},class AcGePoint3d)

distanceTo( (Curve3d)arg1, (Point3d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeTol)

distanceTo( (Curve3d)arg1, (Curve3d)arg2) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve3d {lvalue},class PyGeCurve3d)

distanceTo( (Curve3d)arg1, (Curve3d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeTol)'''
    ...
    def endParam (self, *args, **kwargs):
      '''
endParam( (SplineEnt3d)arg1) -> float :

    C++ signature :
        double endParam(class PyGeSplineEnt3d {lvalue})'''
    ...
    def endPoint (self, *args, **kwargs):
      '''
endPoint( (SplineEnt3d)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d endPoint(class PyGeSplineEnt3d {lvalue})'''
    ...
    def evalPoint (self, *args, **kwargs):
      '''
evalPoint( (Curve3d)arg1, (float)arg2) -> Point3d :

    C++ signature :
        class AcGePoint3d evalPoint(class PyGeCurve3d {lvalue},double)

evalPoint( (Curve3d)arg1, (float)arg2, (int)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple evalPoint(class PyGeCurve3d {lvalue},double,int)'''
    ...
    def explode (self, *args, **kwargs):
      '''
explode( (Curve3d)arg1) -> list :

    C++ signature :
        class boost::python::list explode(class PyGeCurve3d {lvalue})

explode( (Curve3d)arg1, (Interval)arg2) -> list :

    C++ signature :
        class boost::python::list explode(class PyGeCurve3d {lvalue},class PyGeInterval)'''
    ...
    def fitPointAt (self, *args, **kwargs):
      '''
fitPointAt( (Polyline3d)arg1, (int)arg2) -> Point3d :

    C++ signature :
        class AcGePoint3d fitPointAt(class PyGePolyline3d {lvalue},int)'''
    ...
    def getClosestPointTo (self, *args, **kwargs):
      '''
getClosestPointTo( (Curve3d)arg1, (Point3d)arg2) -> PointOnCurve3d :

    C++ signature :
        class PyGePointOnCurve3d getClosestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d)

getClosestPointTo( (Curve3d)arg1, (Point3d)arg2, (Tol)arg3) -> PointOnCurve3d :

    C++ signature :
        class PyGePointOnCurve3d getClosestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def getClosestPointsTo (self, *args, **kwargs):
      '''
getClosestPointsTo( (Curve3d)arg1, (Curve3d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getClosestPointsTo(class PyGeCurve3d {lvalue},class PyGeCurve3d)

getClosestPointsTo( (Curve3d)arg1, (Curve3d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple getClosestPointsTo(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeTol)'''
    ...
    def getEndPoint (self, *args, **kwargs):
      '''
getEndPoint( (Curve3d)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d getEndPoint(class PyGeCurve3d {lvalue})'''
    ...
    def getInterval (self, *args, **kwargs):
      '''
getInterval( (Curve3d)arg1) -> Interval :

    C++ signature :
        class PyGeInterval getInterval(class PyGeCurve3d {lvalue})'''
    ...
    def getNormalPoint (self, *args, **kwargs):
      '''
getNormalPoint( (Curve3d)arg1, (Point3d)arg2) -> PointOnCurve3d :

    C++ signature :
        class PyGePointOnCurve3d getNormalPoint(class PyGeCurve3d {lvalue},class AcGePoint3d)

getNormalPoint( (Curve3d)arg1, (Point3d)arg2, (Tol)arg3) -> PointOnCurve3d :

    C++ signature :
        class PyGePointOnCurve3d getNormalPoint(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def getProjClosestPointTo (self, *args, **kwargs):
      '''
getProjClosestPointTo( (Curve3d)arg1, (Point3d)arg2, (Vector3d)arg3) -> PointOnCurve3d :

    C++ signature :
        class PyGePointOnCurve3d getProjClosestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeVector3d)

getProjClosestPointTo( (Curve3d)arg1, (Point3d)arg2, (Vector3d)arg3, (Tol)arg4) -> PointOnCurve3d :

    C++ signature :
        class PyGePointOnCurve3d getProjClosestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeVector3d,class AcGeTol)'''
    ...
    def getProjClosestPointsTo (self, *args, **kwargs):
      '''
getProjClosestPointsTo( (Curve3d)arg1, (Curve3d)arg2, (Vector3d)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple getProjClosestPointsTo(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeVector3d)

getProjClosestPointsTo( (Curve3d)arg1, (Curve3d)arg2, (Vector3d)arg3, (Tol)arg4) -> tuple :

    C++ signature :
        class boost::python::tuple getProjClosestPointsTo(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeVector3d,class AcGeTol)'''
    ...
    def getSamplePoints (self, *args, **kwargs):
      '''
getSamplePoints( (Curve3d)arg1, (int)arg2) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve3d {lvalue},int)

getSamplePoints( (Curve3d)arg1, (float)arg2, (float)arg3, (float)arg4) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve3d {lvalue},double,double,double)'''
    ...
    def getSplitCurves (self, *args, **kwargs):
      '''
getSplitCurves( (Curve3d)arg1, (float)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getSplitCurves(class PyGeCurve3d {lvalue},double)'''
    ...
    def getStartPoint (self, *args, **kwargs):
      '''
getStartPoint( (Curve3d)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d getStartPoint(class PyGeCurve3d {lvalue})'''
    ...
    def getTrimmedOffset (self, *args, **kwargs):
      '''
getTrimmedOffset( (Curve3d)arg1, (float)arg2, (Vector3d)arg3, (OffsetCrvExtType)arg4) -> list :

    C++ signature :
        class boost::python::list getTrimmedOffset(class PyGeCurve3d {lvalue},double,class AcGeVector3d,enum AcGe::OffsetCrvExtType)

getTrimmedOffset( (Curve3d)arg1, (float)arg2, (Vector3d)arg3, (OffsetCrvExtType)arg4, (Tol)arg5) -> list :

    C++ signature :
        class boost::python::list getTrimmedOffset(class PyGeCurve3d {lvalue},double,class AcGeVector3d,enum AcGe::OffsetCrvExtType,class AcGeTol)'''
    ...
    def hasEndPoint (self, *args, **kwargs):
      '''
hasEndPoint( (Curve3d)arg1) -> bool :

    C++ signature :
        bool hasEndPoint(class PyGeCurve3d {lvalue})'''
    ...
    def hasFitData (self, *args, **kwargs):
      '''
hasFitData( (SplineEnt3d)arg1) -> bool :

    C++ signature :
        bool hasFitData(class PyGeSplineEnt3d {lvalue})'''
    ...
    def hasStartPoint (self, *args, **kwargs):
      '''
hasStartPoint( (Curve3d)arg1) -> bool :

    C++ signature :
        bool hasStartPoint(class PyGeCurve3d {lvalue})'''
    ...
    def isClosed (self, *args, **kwargs):
      '''
isClosed( (Curve3d)arg1) -> bool :

    C++ signature :
        bool isClosed(class PyGeCurve3d {lvalue})

isClosed( (Curve3d)arg1, (Tol)arg2) -> bool :

    C++ signature :
        bool isClosed(class PyGeCurve3d {lvalue},class AcGeTol)'''
    ...
    def isCoplanarWith (self, *args, **kwargs):
      '''
isCoplanarWith( (Curve3d)arg1, (Curve3d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isCoplanarWith(class PyGeCurve3d {lvalue},class PyGeCurve3d)

isCoplanarWith( (Curve3d)arg1, (Curve3d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple isCoplanarWith(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeTol)'''
    ...
    def isDegenerate (self, *args, **kwargs):
      '''
isDegenerate( (Curve3d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isDegenerate(class PyGeCurve3d {lvalue})

isDegenerate( (Curve3d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isDegenerate(class PyGeCurve3d {lvalue},class AcGeTol)'''
    ...
    def isEqualTo (self, *args, **kwargs):
      '''
isEqualTo( (Entity3d)arg1, (Entity3d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity3d {lvalue},class PyGeEntity3d,class AcGeTol)'''
    ...
    def isKindOf (self, *args, **kwargs):
      '''
isKindOf( (Entity3d)arg1, (EntityId)arg2) -> bool :

    C++ signature :
        bool isKindOf(class PyGeEntity3d {lvalue},enum AcGe::EntityId)'''
    ...
    def isLinear (self, *args, **kwargs):
      '''
isLinear( (Curve3d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isLinear(class PyGeCurve3d {lvalue})

isLinear( (Curve3d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isLinear(class PyGeCurve3d {lvalue},class AcGeTol)'''
    ...
    def isNull (self, *args, **kwargs):
      '''
isNull( (Entity3d)arg1) -> bool :

    C++ signature :
        bool isNull(class PyGeEntity3d {lvalue})'''
    ...
    def isOn (self, *args, **kwargs):
      '''
isOn( (Curve3d)arg1, (Point3d)arg2) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve3d {lvalue},class AcGePoint3d)

isOn( (Curve3d)arg1, (Point3d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeTol)

isOn( (Curve3d)arg1, (Point3d)arg2, (float)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve3d {lvalue},class AcGePoint3d,double {lvalue})

isOn( (Curve3d)arg1, (Point3d)arg2, (float)arg3, (Tol)arg4) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve3d {lvalue},class AcGePoint3d,double {lvalue},class AcGeTol)

isOn( (Curve3d)arg1, (float)arg2) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve3d {lvalue},double)

isOn( (Curve3d)arg1, (float)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve3d {lvalue},double,class AcGeTol)'''
    ...
    def isPeriodic (self, *args, **kwargs):
      '''
isPeriodic( (Curve3d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isPeriodic(class PyGeCurve3d {lvalue})'''
    ...
    def isPlanar (self, *args, **kwargs):
      '''
isPlanar( (Curve3d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isPlanar(class PyGeCurve3d {lvalue})

isPlanar( (Curve3d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isPlanar(class PyGeCurve3d {lvalue},class AcGeTol)'''
    ...
    def isRational (self, *args, **kwargs):
      '''
isRational( (SplineEnt3d)arg1) -> bool :

    C++ signature :
        bool isRational(class PyGeSplineEnt3d {lvalue})'''
    ...
    def knotAt (self, *args, **kwargs):
      '''
knotAt( (SplineEnt3d)arg1, (int)arg2) -> float :

    C++ signature :
        double knotAt(class PyGeSplineEnt3d {lvalue},int)'''
    ...
    def knots (self, *args, **kwargs):
      '''
knots( (SplineEnt3d)arg1) -> KnotVector :

    C++ signature :
        class PyGeKnotVector knots(class PyGeSplineEnt3d {lvalue})'''
    ...
    def length (self, *args, **kwargs):
      '''
length( (Curve3d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double length(class PyGeCurve3d {lvalue},double,double)

length( (Curve3d)arg1, (float)arg2, (float)arg3, (float)arg4) -> float :

    C++ signature :
        double length(class PyGeCurve3d {lvalue},double,double,double)'''
    ...
    def mirror (self, *args, **kwargs):
      '''
mirror( (Entity3d)arg1, (Plane)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} mirror(class PyGeEntity3d {lvalue},class PyGePlane)'''
    ...
    def numControlPoints (self, *args, **kwargs):
      '''
numControlPoints( (SplineEnt3d)arg1) -> int :

    C++ signature :
        int numControlPoints(class PyGeSplineEnt3d {lvalue})'''
    ...
    def numFitPoints (self, *args, **kwargs):
      '''
numFitPoints( (Polyline3d)arg1) -> int :

    C++ signature :
        int numFitPoints(class PyGePolyline3d {lvalue})'''
    ...
    def numKnots (self, *args, **kwargs):
      '''
numKnots( (SplineEnt3d)arg1) -> int :

    C++ signature :
        int numKnots(class PyGeSplineEnt3d {lvalue})'''
    ...
    def order (self, *args, **kwargs):
      '''
order( (SplineEnt3d)arg1) -> int :

    C++ signature :
        int order(class PyGeSplineEnt3d {lvalue})'''
    ...
    def orthoBoundBlock (self, *args, **kwargs):
      '''
orthoBoundBlock( (Curve3d)arg1) -> BoundBlock3d :

    C++ signature :
        class PyGeBoundBlock3d orthoBoundBlock(class PyGeCurve3d {lvalue})

orthoBoundBlock( (Curve3d)arg1, (Interval)arg2) -> BoundBlock3d :

    C++ signature :
        class PyGeBoundBlock3d orthoBoundBlock(class PyGeCurve3d {lvalue},class PyGeInterval)'''
    ...
    def orthoProject (self, *args, **kwargs):
      '''
orthoProject( (Curve3d)arg1, (Plane)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d orthoProject(class PyGeCurve3d {lvalue},class PyGePlane)

orthoProject( (Curve3d)arg1, (Plane)arg2, (Tol)arg3) -> Entity3d :

    C++ signature :
        class PyGeEntity3d orthoProject(class PyGeCurve3d {lvalue},class PyGePlane,class AcGeTol)'''
    ...
    def paramAtLength (self, *args, **kwargs):
      '''
paramAtLength( (Curve3d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double paramAtLength(class PyGeCurve3d {lvalue},double,double)

paramAtLength( (Curve3d)arg1, (float)arg2, (float)arg3, (bool)arg4, (float)arg5) -> float :

    C++ signature :
        double paramAtLength(class PyGeCurve3d {lvalue},double,double,bool,double)'''
    ...
    def paramOf (self, *args, **kwargs):
      '''
paramOf( (Curve3d)arg1, (Point3d)arg2) -> float :

    C++ signature :
        double paramOf(class PyGeCurve3d {lvalue},class AcGePoint3d)

paramOf( (Curve3d)arg1, (Point3d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double paramOf(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def projClosestPointTo (self, *args, **kwargs):
      '''
projClosestPointTo( (Curve3d)arg1, (Point3d)arg2, (Vector3d)arg3) -> Point3d :

    C++ signature :
        class AcGePoint3d projClosestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeVector3d)

projClosestPointTo( (Curve3d)arg1, (Point3d)arg2, (Vector3d)arg3, (Tol)arg4) -> Point3d :

    C++ signature :
        class AcGePoint3d projClosestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeVector3d,class AcGeTol)'''
    ...
    def projClosestPointsTo (self, *args, **kwargs):
      '''
projClosestPointsTo( (Curve3d)arg1, (Curve3d)arg2, (Vector3d)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple projClosestPointsTo(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeVector3d)

projClosestPointsTo( (Curve3d)arg1, (Curve3d)arg2, (Vector3d)arg3, (Tol)arg4) -> tuple :

    C++ signature :
        class boost::python::tuple projClosestPointsTo(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeVector3d,class AcGeTol)'''
    ...
    def project (self, *args, **kwargs):
      '''
project( (Curve3d)arg1, (Plane)arg2, (Vector3d)arg3) -> Entity3d :

    C++ signature :
        class PyGeEntity3d project(class PyGeCurve3d {lvalue},class PyGePlane,class AcGeVector3d)

project( (Curve3d)arg1, (Plane)arg2, (Vector3d)arg3, (Tol)arg4) -> Entity3d :

    C++ signature :
        class PyGeEntity3d project(class PyGeCurve3d {lvalue},class PyGePlane,class AcGeVector3d,class AcGeTol)'''
    ...
    def reverseParam (self, *args, **kwargs):
      '''
reverseParam( (Curve3d)arg1) -> Curve3d :

    C++ signature :
        class PyGeCurve3d {lvalue} reverseParam(class PyGeCurve3d {lvalue})'''
    ...
    def rotateBy (self, *args, **kwargs):
      '''
rotateBy( (Entity3d)arg1, (float)arg2, (Vector3d)arg3) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} rotateBy(class PyGeEntity3d {lvalue},double,class AcGeVector3d)

rotateBy( (Entity3d)arg1, (float)arg2, (Vector3d)arg3, (Point3d)arg4) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} rotateBy(class PyGeEntity3d {lvalue},double,class AcGeVector3d,class AcGePoint3d)'''
    ...
    def scaleBy (self, *args, **kwargs):
      '''
scaleBy( (Entity3d)arg1, (float)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} scaleBy(class PyGeEntity3d {lvalue},double)

scaleBy( (Entity3d)arg1, (float)arg2, (Point3d)arg3) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} scaleBy(class PyGeEntity3d {lvalue},double,class AcGePoint3d)'''
    ...
    def setControlPointAt (self, *args, **kwargs):
      '''
setControlPointAt( (SplineEnt3d)arg1, (int)arg2, (Point3d)arg3) -> SplineEnt3d :

    C++ signature :
        class PyGeSplineEnt3d {lvalue} setControlPointAt(class PyGeSplineEnt3d {lvalue},int,class AcGePoint3d)'''
    ...
    def setFitPointAt (self, *args, **kwargs):
      '''
setFitPointAt( (Polyline3d)arg1, (int)arg2, (Point3d)arg3) -> Polyline3d :

    C++ signature :
        class PyGePolyline3d {lvalue} setFitPointAt(class PyGePolyline3d {lvalue},int,class AcGePoint3d)'''
    ...
    def setInterval (self, *args, **kwargs):
      '''
setInterval( (Curve3d)arg1) -> Curve3d :

    C++ signature :
        class PyGeCurve3d {lvalue} setInterval(class PyGeCurve3d {lvalue})

setInterval( (Curve3d)arg1, (Interval)arg2) -> bool :

    C++ signature :
        bool setInterval(class PyGeCurve3d {lvalue},class PyGeInterval)'''
    ...
    def setKnotAt (self, *args, **kwargs):
      '''
setKnotAt( (SplineEnt3d)arg1, (int)arg2, (float)arg3) -> SplineEnt3d :

    C++ signature :
        class PyGeSplineEnt3d {lvalue} setKnotAt(class PyGeSplineEnt3d {lvalue},int,double)'''
    ...
    def startParam (self, *args, **kwargs):
      '''
startParam( (SplineEnt3d)arg1) -> float :

    C++ signature :
        double startParam(class PyGeSplineEnt3d {lvalue})'''
    ...
    def startPoint (self, *args, **kwargs):
      '''
startPoint( (SplineEnt3d)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d startPoint(class PyGeSplineEnt3d {lvalue})'''
    ...
    def transformBy (self, *args, **kwargs):
      '''
transformBy( (Entity3d)arg1, (Matrix3d)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} transformBy(class PyGeEntity3d {lvalue},class AcGeMatrix3d)'''
    ...
    def translateBy (self, *args, **kwargs):
      '''
translateBy( (Entity3d)arg1, (Vector3d)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} translateBy(class PyGeEntity3d {lvalue},class AcGeVector3d)'''
    ...
    def type (self, *args, **kwargs):
      '''
type( (Entity3d)arg1) -> EntityId :

    C++ signature :
        enum AcGe::EntityId type(class PyGeEntity3d {lvalue})'''
    ...

class Position2d:
    def __eq__ (self, *args, **kwargs):
      '''
__eq__( (Entity2d)arg1, (Entity2d)arg2) -> bool :

    C++ signature :
        bool __eq__(class PyGeEntity2d {lvalue},class PyGeEntity2d)'''
    ...
    def __init__ (self, *args, **kwargs):
      '''
__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1, (Point2d)arg2) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class AcGePoint2d)

__init__( (object)arg1, (float)arg2, (float)arg3) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,double,double)'''
    ...
    def __ne__ (self, *args, **kwargs):
      '''
__ne__( (Entity2d)arg1, (Entity2d)arg2) -> bool :

    C++ signature :
        bool __ne__(class PyGeEntity2d {lvalue},class PyGeEntity2d)'''
    ...
    def className (self, *args, **kwargs):
      '''
className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def copy (self, *args, **kwargs):
      '''
copy( (Entity2d)arg1) -> Entity2d :

    C++ signature :
        class PyGeEntity2d copy(class PyGeEntity2d {lvalue})'''
    ...
    def isEqualTo (self, *args, **kwargs):
      '''
isEqualTo( (Entity2d)arg1, (Entity2d)arg2) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity2d {lvalue},class PyGeEntity2d)

isEqualTo( (Entity2d)arg1, (Entity2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity2d {lvalue},class PyGeEntity2d,class AcGeTol)'''
    ...
    def isKindOf (self, *args, **kwargs):
      '''
isKindOf( (Entity2d)arg1, (EntityId)arg2) -> bool :

    C++ signature :
        bool isKindOf(class PyGeEntity2d {lvalue},enum AcGe::EntityId)'''
    ...
    def isNull (self, *args, **kwargs):
      '''
isNull( (Entity2d)arg1) -> bool :

    C++ signature :
        bool isNull(class PyGeEntity2d {lvalue})'''
    ...
    def isOn (self, *args, **kwargs):
      '''
isOn( (Entity2d)arg1, (Point2d)arg2) -> bool :

    C++ signature :
        bool isOn(class PyGeEntity2d {lvalue},class AcGePoint2d)

isOn( (Entity2d)arg1, (Point2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeEntity2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def mirror (self, *args, **kwargs):
      '''
mirror( (Entity2d)arg1, (Line2d)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} mirror(class PyGeEntity2d {lvalue},class PyGeLine2d)'''
    ...
    def point2d (self, *args, **kwargs):
      '''
point2d( (PointEnt2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d point2d(class PyGePointEnt2d {lvalue})'''
    ...
    def rotateBy (self, *args, **kwargs):
      '''
rotateBy( (Entity2d)arg1, (float)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} rotateBy(class PyGeEntity2d {lvalue},double)

rotateBy( (Entity2d)arg1, (float)arg2, (Point2d)arg3) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} rotateBy(class PyGeEntity2d {lvalue},double,class AcGePoint2d)'''
    ...
    def scaleBy (self, *args, **kwargs):
      '''
scaleBy( (Entity2d)arg1, (float)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} scaleBy(class PyGeEntity2d {lvalue},double)

scaleBy( (Entity2d)arg1, (float)arg2, (Point2d)arg3) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} scaleBy(class PyGeEntity2d {lvalue},double,class AcGePoint2d)'''
    ...
    def set (self, *args, **kwargs):
      '''
set( (Position2d)arg1, (Point2d)arg2) -> Position2d :

    C++ signature :
        class PyGePosition2d {lvalue} set(class PyGePosition2d {lvalue},class AcGePoint2d)

set( (Position2d)arg1, (float)arg2, (float)arg3) -> Position2d :

    C++ signature :
        class PyGePosition2d {lvalue} set(class PyGePosition2d {lvalue},double,double)'''
    ...
    def transformBy (self, *args, **kwargs):
      '''
transformBy( (Entity2d)arg1, (Matrix2d)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} transformBy(class PyGeEntity2d {lvalue},class AcGeMatrix2d)'''
    ...
    def translateBy (self, *args, **kwargs):
      '''
translateBy( (Entity2d)arg1, (Vector2d)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} translateBy(class PyGeEntity2d {lvalue},class AcGeVector2d)'''
    ...
    def type (self, *args, **kwargs):
      '''
type( (Entity2d)arg1) -> EntityId :

    C++ signature :
        enum AcGe::EntityId type(class PyGeEntity2d {lvalue})'''
    ...

class Position3d:
    def __eq__ (self, *args, **kwargs):
      '''
__eq__( (Entity3d)arg1, (Entity3d)arg2) -> bool :

    C++ signature :
        bool __eq__(class PyGeEntity3d {lvalue},class PyGeEntity3d)'''
    ...
    def __init__ (self, *args, **kwargs):
      '''
__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
    ...
    def __ne__ (self, *args, **kwargs):
      '''
__ne__( (Entity3d)arg1, (Entity3d)arg2) -> bool :

    C++ signature :
        bool __ne__(class PyGeEntity3d {lvalue},class PyGeEntity3d)'''
    ...
    def className (self, *args, **kwargs):
      '''
className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def copy (self, *args, **kwargs):
      '''
copy( (Entity3d)arg1) -> Entity3d :

    C++ signature :
        class PyGeEntity3d copy(class PyGeEntity3d {lvalue})'''
    ...
    def isEqualTo (self, *args, **kwargs):
      '''
isEqualTo( (Entity3d)arg1, (Entity3d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity3d {lvalue},class PyGeEntity3d,class AcGeTol)'''
    ...
    def isKindOf (self, *args, **kwargs):
      '''
isKindOf( (Entity3d)arg1, (EntityId)arg2) -> bool :

    C++ signature :
        bool isKindOf(class PyGeEntity3d {lvalue},enum AcGe::EntityId)'''
    ...
    def isNull (self, *args, **kwargs):
      '''
isNull( (Entity3d)arg1) -> bool :

    C++ signature :
        bool isNull(class PyGeEntity3d {lvalue})'''
    ...
    def isOn (self, *args, **kwargs):
      '''
isOn( (Entity3d)arg1, (Point3d)arg2) -> bool :

    C++ signature :
        bool isOn(class PyGeEntity3d {lvalue},class AcGePoint3d)

isOn( (Entity3d)arg1, (Point3d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeEntity3d {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def mirror (self, *args, **kwargs):
      '''
mirror( (Entity3d)arg1, (Plane)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} mirror(class PyGeEntity3d {lvalue},class PyGePlane)'''
    ...
    def rotateBy (self, *args, **kwargs):
      '''
rotateBy( (Entity3d)arg1, (float)arg2, (Vector3d)arg3) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} rotateBy(class PyGeEntity3d {lvalue},double,class AcGeVector3d)

rotateBy( (Entity3d)arg1, (float)arg2, (Vector3d)arg3, (Point3d)arg4) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} rotateBy(class PyGeEntity3d {lvalue},double,class AcGeVector3d,class AcGePoint3d)'''
    ...
    def scaleBy (self, *args, **kwargs):
      '''
scaleBy( (Entity3d)arg1, (float)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} scaleBy(class PyGeEntity3d {lvalue},double)

scaleBy( (Entity3d)arg1, (float)arg2, (Point3d)arg3) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} scaleBy(class PyGeEntity3d {lvalue},double,class AcGePoint3d)'''
    ...
    def transformBy (self, *args, **kwargs):
      '''
transformBy( (Entity3d)arg1, (Matrix3d)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} transformBy(class PyGeEntity3d {lvalue},class AcGeMatrix3d)'''
    ...
    def translateBy (self, *args, **kwargs):
      '''
translateBy( (Entity3d)arg1, (Vector3d)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} translateBy(class PyGeEntity3d {lvalue},class AcGeVector3d)'''
    ...
    def type (self, *args, **kwargs):
      '''
type( (Entity3d)arg1) -> EntityId :

    C++ signature :
        enum AcGe::EntityId type(class PyGeEntity3d {lvalue})'''
    ...

class Ray2d:
    def __eq__ (self, *args, **kwargs):
      '''
__eq__( (Entity2d)arg1, (Entity2d)arg2) -> bool :

    C++ signature :
        bool __eq__(class PyGeEntity2d {lvalue},class PyGeEntity2d)'''
    ...
    def __init__ (self, *args, **kwargs):
      '''
__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1, (Point2d)arg2, (Vector2d)arg3) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class AcGePoint2d,class AcGeVector2d)

__init__( (object)arg1, (Point2d)arg2, (Point2d)arg3) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class AcGePoint2d,class AcGePoint2d)'''
    ...
    def __ne__ (self, *args, **kwargs):
      '''
__ne__( (Entity2d)arg1, (Entity2d)arg2) -> bool :

    C++ signature :
        bool __ne__(class PyGeEntity2d {lvalue},class PyGeEntity2d)'''
    ...
    def area (self, *args, **kwargs):
      '''
area( (Curve2d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double area(class PyGeCurve2d {lvalue},double,double)

area( (Curve2d)arg1, (float)arg2, (float)arg3, (Tol)arg4) -> float :

    C++ signature :
        double area(class PyGeCurve2d {lvalue},double,double,class AcGeTol)'''
    ...
    def boundBlock (self, *args, **kwargs):
      '''
boundBlock( (Curve2d)arg1) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d boundBlock(class PyGeCurve2d {lvalue})

boundBlock( (Curve2d)arg1, (Interval)arg2) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d boundBlock(class PyGeCurve2d {lvalue},class PyGeInterval)'''
    ...
    def className (self, *args, **kwargs):
      '''
className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def closestPointTo (self, *args, **kwargs):
      '''
closestPointTo( (Curve2d)arg1, (Point2d)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d closestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d)

closestPointTo( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> Point2d :

    C++ signature :
        class AcGePoint2d closestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)

closestPointTo( (Curve2d)arg1, (Curve2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointTo(class PyGeCurve2d {lvalue},class PyGeCurve2d)

closestPointTo( (Curve2d)arg1, (Curve2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointTo(class PyGeCurve2d {lvalue},class PyGeCurve2d,class AcGeTol)'''
    ...
    def copy (self, *args, **kwargs):
      '''
copy( (Entity2d)arg1) -> Entity2d :

    C++ signature :
        class PyGeEntity2d copy(class PyGeEntity2d {lvalue})'''
    ...
    def direction (self, *args, **kwargs):
      '''
direction( (LinearEnt2d)arg1) -> Vector2d :

    C++ signature :
        class AcGeVector2d direction(class PyGeLinearEnt2d {lvalue})'''
    ...
    def distanceTo (self, *args, **kwargs):
      '''
distanceTo( (Curve2d)arg1, (Point2d)arg2) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class AcGePoint2d)

distanceTo( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)

distanceTo( (Curve2d)arg1, (Curve2d)arg2) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class PyGeCurve2d)

distanceTo( (Curve2d)arg1, (Curve2d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class PyGeCurve2d,class AcGeTol)'''
    ...
    def evalPoint (self, *args, **kwargs):
      '''
evalPoint( (Curve2d)arg1, (float)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d evalPoint(class PyGeCurve2d {lvalue},double)

evalPoint( (Curve2d)arg1, (float)arg2, (int)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple evalPoint(class PyGeCurve2d {lvalue},double,int)'''
    ...
    def explode (self, *args, **kwargs):
      '''
explode( (Curve2d)arg1) -> list :

    C++ signature :
        class boost::python::list explode(class PyGeCurve2d {lvalue})

explode( (Curve2d)arg1, (Interval)arg2) -> list :

    C++ signature :
        class boost::python::list explode(class PyGeCurve2d {lvalue},class PyGeInterval)'''
    ...
    def getClosestPointTo (self, *args, **kwargs):
      '''
getClosestPointTo( (Curve2d)arg1, (Point2d)arg2) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getClosestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d)

getClosestPointTo( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getClosestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def getClosestPointsTo (self, *args, **kwargs):
      '''
getClosestPointsTo( (Curve2d)arg1, (Curve2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getClosestPointsTo(class PyGeCurve2d {lvalue},class PyGeCurve2d)

getClosestPointsTo( (Curve2d)arg1, (Curve2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple getClosestPointsTo(class PyGeCurve2d {lvalue},class PyGeCurve2d,class AcGeTol)'''
    ...
    def getEndPoint (self, *args, **kwargs):
      '''
getEndPoint( (Curve2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d getEndPoint(class PyGeCurve2d {lvalue})'''
    ...
    def getInterval (self, *args, **kwargs):
      '''
getInterval( (Curve2d)arg1) -> Interval :

    C++ signature :
        class PyGeInterval getInterval(class PyGeCurve2d {lvalue})'''
    ...
    def getLine (self, *args, **kwargs):
      '''
getLine( (LinearEnt2d)arg1) -> Line2d :

    C++ signature :
        class PyGeLine2d getLine(class PyGeLinearEnt2d {lvalue})'''
    ...
    def getNormalPoint (self, *args, **kwargs):
      '''
getNormalPoint( (Curve2d)arg1, (Point2d)arg2) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getNormalPoint(class PyGeCurve2d {lvalue},class AcGePoint2d)

getNormalPoint( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getNormalPoint(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def getPerpLine (self, *args, **kwargs):
      '''
getPerpLine( (LinearEnt2d)arg1, (Point2d)arg2) -> Line2d :

    C++ signature :
        class PyGeLine2d getPerpLine(class PyGeLinearEnt2d {lvalue},class AcGePoint2d)'''
    ...
    def getSamplePoints (self, *args, **kwargs):
      '''
getSamplePoints( (Curve2d)arg1, (int)arg2) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve2d {lvalue},int)

getSamplePoints( (Curve2d)arg1, (float)arg2, (float)arg3, (float)arg4) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve2d {lvalue},double,double,double)'''
    ...
    def getSplitCurves (self, *args, **kwargs):
      '''
getSplitCurves( (Curve2d)arg1, (float)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getSplitCurves(class PyGeCurve2d {lvalue},double)'''
    ...
    def getStartPoint (self, *args, **kwargs):
      '''
getStartPoint( (Curve2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d getStartPoint(class PyGeCurve2d {lvalue})'''
    ...
    def getTrimmedOffset (self, *args, **kwargs):
      '''
getTrimmedOffset( (Curve2d)arg1, (float)arg2, (OffsetCrvExtType)arg3) -> list :

    C++ signature :
        class boost::python::list getTrimmedOffset(class PyGeCurve2d {lvalue},double,enum AcGe::OffsetCrvExtType)

getTrimmedOffset( (Curve2d)arg1, (float)arg2, (OffsetCrvExtType)arg3, (Tol)arg4) -> list :

    C++ signature :
        class boost::python::list getTrimmedOffset(class PyGeCurve2d {lvalue},double,enum AcGe::OffsetCrvExtType,class AcGeTol)'''
    ...
    def hasEndPoint (self, *args, **kwargs):
      '''
hasEndPoint( (Curve2d)arg1) -> bool :

    C++ signature :
        bool hasEndPoint(class PyGeCurve2d {lvalue})'''
    ...
    def hasStartPoint (self, *args, **kwargs):
      '''
hasStartPoint( (Curve2d)arg1) -> bool :

    C++ signature :
        bool hasStartPoint(class PyGeCurve2d {lvalue})'''
    ...
    def intersectWith (self, *args, **kwargs):
      '''
intersectWith( (LinearEnt2d)arg1, (LinearEnt2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple intersectWith(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d)

intersectWith( (LinearEnt2d)arg1, (LinearEnt2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple intersectWith(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d,class AcGeTol)'''
    ...
    def isClosed (self, *args, **kwargs):
      '''
isClosed( (Curve2d)arg1) -> bool :

    C++ signature :
        bool isClosed(class PyGeCurve2d {lvalue})

isClosed( (Curve2d)arg1, (Tol)arg2) -> bool :

    C++ signature :
        bool isClosed(class PyGeCurve2d {lvalue},class AcGeTol)'''
    ...
    def isColinearTo (self, *args, **kwargs):
      '''
isColinearTo( (LinearEnt2d)arg1, (LinearEnt2d)arg2) -> bool :

    C++ signature :
        bool isColinearTo(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d)

isColinearTo( (LinearEnt2d)arg1, (LinearEnt2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isColinearTo(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d,class AcGeTol)'''
    ...
    def isDegenerate (self, *args, **kwargs):
      '''
isDegenerate( (Curve2d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isDegenerate(class PyGeCurve2d {lvalue})

isDegenerate( (Curve2d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isDegenerate(class PyGeCurve2d {lvalue},class AcGeTol)'''
    ...
    def isEqualTo (self, *args, **kwargs):
      '''
isEqualTo( (Entity2d)arg1, (Entity2d)arg2) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity2d {lvalue},class PyGeEntity2d)

isEqualTo( (Entity2d)arg1, (Entity2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity2d {lvalue},class PyGeEntity2d,class AcGeTol)'''
    ...
    def isKindOf (self, *args, **kwargs):
      '''
isKindOf( (Entity2d)arg1, (EntityId)arg2) -> bool :

    C++ signature :
        bool isKindOf(class PyGeEntity2d {lvalue},enum AcGe::EntityId)'''
    ...
    def isLinear (self, *args, **kwargs):
      '''
isLinear( (Curve2d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isLinear(class PyGeCurve2d {lvalue})

isLinear( (Curve2d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isLinear(class PyGeCurve2d {lvalue},class AcGeTol)'''
    ...
    def isNull (self, *args, **kwargs):
      '''
isNull( (Entity2d)arg1) -> bool :

    C++ signature :
        bool isNull(class PyGeEntity2d {lvalue})'''
    ...
    def isOn (self, *args, **kwargs):
      '''
isOn( (Curve2d)arg1, (Point2d)arg2) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve2d {lvalue},class AcGePoint2d)

isOn( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)

isOn( (Curve2d)arg1, (Point2d)arg2, (float)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve2d {lvalue},class AcGePoint2d,double {lvalue})

isOn( (Curve2d)arg1, (Point2d)arg2, (float)arg3, (Tol)arg4) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve2d {lvalue},class AcGePoint2d,double {lvalue},class AcGeTol)

isOn( (Curve2d)arg1, (float)arg2) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve2d {lvalue},double)

isOn( (Curve2d)arg1, (float)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve2d {lvalue},double,class AcGeTol)'''
    ...
    def isParallelTo (self, *args, **kwargs):
      '''
isParallelTo( (LinearEnt2d)arg1, (LinearEnt2d)arg2) -> bool :

    C++ signature :
        bool isParallelTo(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d)

isParallelTo( (LinearEnt2d)arg1, (LinearEnt2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isParallelTo(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d,class AcGeTol)'''
    ...
    def isPeriodic (self, *args, **kwargs):
      '''
isPeriodic( (Curve2d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isPeriodic(class PyGeCurve2d {lvalue})'''
    ...
    def isPerpendicularTo (self, *args, **kwargs):
      '''
isPerpendicularTo( (LinearEnt2d)arg1, (LinearEnt2d)arg2) -> bool :

    C++ signature :
        bool isPerpendicularTo(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d)

isPerpendicularTo( (LinearEnt2d)arg1, (LinearEnt2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isPerpendicularTo(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d,class AcGeTol)'''
    ...
    def length (self, *args, **kwargs):
      '''
length( (Curve2d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double length(class PyGeCurve2d {lvalue},double,double)

length( (Curve2d)arg1, (float)arg2, (float)arg3, (float)arg4) -> float :

    C++ signature :
        double length(class PyGeCurve2d {lvalue},double,double,double)'''
    ...
    def mirror (self, *args, **kwargs):
      '''
mirror( (Entity2d)arg1, (Line2d)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} mirror(class PyGeEntity2d {lvalue},class PyGeLine2d)'''
    ...
    def orthoBoundBlock (self, *args, **kwargs):
      '''
orthoBoundBlock( (Curve2d)arg1) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d orthoBoundBlock(class PyGeCurve2d {lvalue})

orthoBoundBlock( (Curve2d)arg1, (Interval)arg2) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d orthoBoundBlock(class PyGeCurve2d {lvalue},class PyGeInterval)'''
    ...
    def overlap (self, *args, **kwargs):
      '''
overlap( (LinearEnt2d)arg1, (LinearEnt2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple overlap(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d)

overlap( (LinearEnt2d)arg1, (LinearEnt2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple overlap(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d,class AcGeTol)'''
    ...
    def paramAtLength (self, *args, **kwargs):
      '''
paramAtLength( (Curve2d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double paramAtLength(class PyGeCurve2d {lvalue},double,double)

paramAtLength( (Curve2d)arg1, (float)arg2, (float)arg3, (bool)arg4, (float)arg5) -> float :

    C++ signature :
        double paramAtLength(class PyGeCurve2d {lvalue},double,double,bool,double)'''
    ...
    def paramOf (self, *args, **kwargs):
      '''
paramOf( (Curve2d)arg1, (Point2d)arg2) -> float :

    C++ signature :
        double paramOf(class PyGeCurve2d {lvalue},class AcGePoint2d)

paramOf( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double paramOf(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def pointOnLine (self, *args, **kwargs):
      '''
pointOnLine( (LinearEnt2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d pointOnLine(class PyGeLinearEnt2d {lvalue})'''
    ...
    def reverseParam (self, *args, **kwargs):
      '''
reverseParam( (Curve2d)arg1) -> Curve2d :

    C++ signature :
        class PyGeCurve2d {lvalue} reverseParam(class PyGeCurve2d {lvalue})'''
    ...
    def rotateBy (self, *args, **kwargs):
      '''
rotateBy( (Entity2d)arg1, (float)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} rotateBy(class PyGeEntity2d {lvalue},double)

rotateBy( (Entity2d)arg1, (float)arg2, (Point2d)arg3) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} rotateBy(class PyGeEntity2d {lvalue},double,class AcGePoint2d)'''
    ...
    def scaleBy (self, *args, **kwargs):
      '''
scaleBy( (Entity2d)arg1, (float)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} scaleBy(class PyGeEntity2d {lvalue},double)

scaleBy( (Entity2d)arg1, (float)arg2, (Point2d)arg3) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} scaleBy(class PyGeEntity2d {lvalue},double,class AcGePoint2d)'''
    ...
    def set (self, *args, **kwargs):
      '''
set( (Ray2d)arg1, (Point2d)arg2, (Vector2d)arg3) -> Ray2d :

    C++ signature :
        class PyGeRay2d {lvalue} set(class PyGeRay2d {lvalue},class AcGePoint2d,class AcGeVector2d)

set( (Ray2d)arg1, (Point2d)arg2, (Point2d)arg3) -> Ray2d :

    C++ signature :
        class PyGeRay2d {lvalue} set(class PyGeRay2d {lvalue},class AcGePoint2d,class AcGePoint2d)'''
    ...
    def setInterval (self, *args, **kwargs):
      '''
setInterval( (Curve2d)arg1) -> Curve2d :

    C++ signature :
        class PyGeCurve2d {lvalue} setInterval(class PyGeCurve2d {lvalue})

setInterval( (Curve2d)arg1, (Interval)arg2) -> bool :

    C++ signature :
        bool setInterval(class PyGeCurve2d {lvalue},class PyGeInterval)'''
    ...
    def transformBy (self, *args, **kwargs):
      '''
transformBy( (Entity2d)arg1, (Matrix2d)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} transformBy(class PyGeEntity2d {lvalue},class AcGeMatrix2d)'''
    ...
    def translateBy (self, *args, **kwargs):
      '''
translateBy( (Entity2d)arg1, (Vector2d)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} translateBy(class PyGeEntity2d {lvalue},class AcGeVector2d)'''
    ...
    def type (self, *args, **kwargs):
      '''
type( (Entity2d)arg1) -> EntityId :

    C++ signature :
        enum AcGe::EntityId type(class PyGeEntity2d {lvalue})'''
    ...

class Ray3d:
    def __eq__ (self, *args, **kwargs):
      '''
__eq__( (Entity3d)arg1, (Entity3d)arg2) -> bool :

    C++ signature :
        bool __eq__(class PyGeEntity3d {lvalue},class PyGeEntity3d)'''
    ...
    def __init__ (self, *args, **kwargs):
      '''
__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1, (Point3d)arg2, (Vector3d)arg3) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class AcGePoint3d,class AcGeVector3d)

__init__( (object)arg1, (Point3d)arg2, (Point3d)arg3) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class AcGePoint3d,class AcGePoint3d)'''
    ...
    def __ne__ (self, *args, **kwargs):
      '''
__ne__( (Entity3d)arg1, (Entity3d)arg2) -> bool :

    C++ signature :
        bool __ne__(class PyGeEntity3d {lvalue},class PyGeEntity3d)'''
    ...
    def area (self, *args, **kwargs):
      '''
area( (Curve3d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double area(class PyGeCurve3d {lvalue},double,double)

area( (Curve3d)arg1, (float)arg2, (float)arg3, (Tol)arg4) -> float :

    C++ signature :
        double area(class PyGeCurve3d {lvalue},double,double,class AcGeTol)'''
    ...
    def boundBlock (self, *args, **kwargs):
      '''
boundBlock( (Curve3d)arg1) -> BoundBlock3d :

    C++ signature :
        class PyGeBoundBlock3d boundBlock(class PyGeCurve3d {lvalue})

boundBlock( (Curve3d)arg1, (Interval)arg2) -> BoundBlock3d :

    C++ signature :
        class PyGeBoundBlock3d boundBlock(class PyGeCurve3d {lvalue},class PyGeInterval)'''
    ...
    def className (self, *args, **kwargs):
      '''
className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def closestPointTo (self, *args, **kwargs):
      '''
closestPointTo( (Curve3d)arg1, (Point3d)arg2) -> Point3d :

    C++ signature :
        class AcGePoint3d closestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d)

closestPointTo( (Curve3d)arg1, (Point3d)arg2, (Tol)arg3) -> Point3d :

    C++ signature :
        class AcGePoint3d closestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeTol)

closestPointTo( (Curve3d)arg1, (Curve3d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointTo(class PyGeCurve3d {lvalue},class PyGeCurve3d)

closestPointTo( (Curve3d)arg1, (Curve3d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointTo(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeTol)'''
    ...
    def copy (self, *args, **kwargs):
      '''
copy( (Entity3d)arg1) -> Entity3d :

    C++ signature :
        class PyGeEntity3d copy(class PyGeEntity3d {lvalue})'''
    ...
    def direction (self, *args, **kwargs):
      '''
direction( (LinearEnt3d)arg1) -> Vector3d :

    C++ signature :
        class AcGeVector3d direction(class PyGeLinearEnt3d {lvalue})'''
    ...
    def distanceTo (self, *args, **kwargs):
      '''
distanceTo( (Curve3d)arg1, (Point3d)arg2) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve3d {lvalue},class AcGePoint3d)

distanceTo( (Curve3d)arg1, (Point3d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeTol)

distanceTo( (Curve3d)arg1, (Curve3d)arg2) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve3d {lvalue},class PyGeCurve3d)

distanceTo( (Curve3d)arg1, (Curve3d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeTol)'''
    ...
    def evalPoint (self, *args, **kwargs):
      '''
evalPoint( (Curve3d)arg1, (float)arg2) -> Point3d :

    C++ signature :
        class AcGePoint3d evalPoint(class PyGeCurve3d {lvalue},double)

evalPoint( (Curve3d)arg1, (float)arg2, (int)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple evalPoint(class PyGeCurve3d {lvalue},double,int)'''
    ...
    def explode (self, *args, **kwargs):
      '''
explode( (Curve3d)arg1) -> list :

    C++ signature :
        class boost::python::list explode(class PyGeCurve3d {lvalue})

explode( (Curve3d)arg1, (Interval)arg2) -> list :

    C++ signature :
        class boost::python::list explode(class PyGeCurve3d {lvalue},class PyGeInterval)'''
    ...
    def getClosestPointTo (self, *args, **kwargs):
      '''
getClosestPointTo( (Curve3d)arg1, (Point3d)arg2) -> PointOnCurve3d :

    C++ signature :
        class PyGePointOnCurve3d getClosestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d)

getClosestPointTo( (Curve3d)arg1, (Point3d)arg2, (Tol)arg3) -> PointOnCurve3d :

    C++ signature :
        class PyGePointOnCurve3d getClosestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def getClosestPointsTo (self, *args, **kwargs):
      '''
getClosestPointsTo( (Curve3d)arg1, (Curve3d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getClosestPointsTo(class PyGeCurve3d {lvalue},class PyGeCurve3d)

getClosestPointsTo( (Curve3d)arg1, (Curve3d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple getClosestPointsTo(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeTol)'''
    ...
    def getEndPoint (self, *args, **kwargs):
      '''
getEndPoint( (Curve3d)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d getEndPoint(class PyGeCurve3d {lvalue})'''
    ...
    def getInterval (self, *args, **kwargs):
      '''
getInterval( (Curve3d)arg1) -> Interval :

    C++ signature :
        class PyGeInterval getInterval(class PyGeCurve3d {lvalue})'''
    ...
    def getLine (self, *args, **kwargs):
      '''
getLine( (LinearEnt3d)arg1) -> Line3d :

    C++ signature :
        class PyGeLine3d getLine(class PyGeLinearEnt3d {lvalue})'''
    ...
    def getNormalPoint (self, *args, **kwargs):
      '''
getNormalPoint( (Curve3d)arg1, (Point3d)arg2) -> PointOnCurve3d :

    C++ signature :
        class PyGePointOnCurve3d getNormalPoint(class PyGeCurve3d {lvalue},class AcGePoint3d)

getNormalPoint( (Curve3d)arg1, (Point3d)arg2, (Tol)arg3) -> PointOnCurve3d :

    C++ signature :
        class PyGePointOnCurve3d getNormalPoint(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def getPerpPlane (self, *args, **kwargs):
      '''
getPerpPlane( (LinearEnt3d)arg1, (Point3d)arg2) -> Plane :

    C++ signature :
        class PyGePlane getPerpPlane(class PyGeLinearEnt3d {lvalue},class AcGePoint3d)'''
    ...
    def getProjClosestPointTo (self, *args, **kwargs):
      '''
getProjClosestPointTo( (Curve3d)arg1, (Point3d)arg2, (Vector3d)arg3) -> PointOnCurve3d :

    C++ signature :
        class PyGePointOnCurve3d getProjClosestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeVector3d)

getProjClosestPointTo( (Curve3d)arg1, (Point3d)arg2, (Vector3d)arg3, (Tol)arg4) -> PointOnCurve3d :

    C++ signature :
        class PyGePointOnCurve3d getProjClosestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeVector3d,class AcGeTol)'''
    ...
    def getProjClosestPointsTo (self, *args, **kwargs):
      '''
getProjClosestPointsTo( (Curve3d)arg1, (Curve3d)arg2, (Vector3d)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple getProjClosestPointsTo(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeVector3d)

getProjClosestPointsTo( (Curve3d)arg1, (Curve3d)arg2, (Vector3d)arg3, (Tol)arg4) -> tuple :

    C++ signature :
        class boost::python::tuple getProjClosestPointsTo(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeVector3d,class AcGeTol)'''
    ...
    def getSamplePoints (self, *args, **kwargs):
      '''
getSamplePoints( (Curve3d)arg1, (int)arg2) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve3d {lvalue},int)

getSamplePoints( (Curve3d)arg1, (float)arg2, (float)arg3, (float)arg4) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve3d {lvalue},double,double,double)'''
    ...
    def getSplitCurves (self, *args, **kwargs):
      '''
getSplitCurves( (Curve3d)arg1, (float)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getSplitCurves(class PyGeCurve3d {lvalue},double)'''
    ...
    def getStartPoint (self, *args, **kwargs):
      '''
getStartPoint( (Curve3d)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d getStartPoint(class PyGeCurve3d {lvalue})'''
    ...
    def getTrimmedOffset (self, *args, **kwargs):
      '''
getTrimmedOffset( (Curve3d)arg1, (float)arg2, (Vector3d)arg3, (OffsetCrvExtType)arg4) -> list :

    C++ signature :
        class boost::python::list getTrimmedOffset(class PyGeCurve3d {lvalue},double,class AcGeVector3d,enum AcGe::OffsetCrvExtType)

getTrimmedOffset( (Curve3d)arg1, (float)arg2, (Vector3d)arg3, (OffsetCrvExtType)arg4, (Tol)arg5) -> list :

    C++ signature :
        class boost::python::list getTrimmedOffset(class PyGeCurve3d {lvalue},double,class AcGeVector3d,enum AcGe::OffsetCrvExtType,class AcGeTol)'''
    ...
    def hasEndPoint (self, *args, **kwargs):
      '''
hasEndPoint( (Curve3d)arg1) -> bool :

    C++ signature :
        bool hasEndPoint(class PyGeCurve3d {lvalue})'''
    ...
    def hasStartPoint (self, *args, **kwargs):
      '''
hasStartPoint( (Curve3d)arg1) -> bool :

    C++ signature :
        bool hasStartPoint(class PyGeCurve3d {lvalue})'''
    ...
    def intersectWith (self, *args, **kwargs):
      '''
intersectWith( (LinearEnt3d)arg1, (LinearEnt3d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple intersectWith(class PyGeLinearEnt3d {lvalue},class PyGeLinearEnt3d)

intersectWith( (LinearEnt3d)arg1, (LinearEnt3d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple intersectWith(class PyGeLinearEnt3d {lvalue},class PyGeLinearEnt3d,class AcGeTol)

intersectWith( (LinearEnt3d)arg1, (PlanarEnt)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple intersectWith(class PyGeLinearEnt3d {lvalue},class PyGePlanarEnt)

intersectWith( (LinearEnt3d)arg1, (PlanarEnt)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple intersectWith(class PyGeLinearEnt3d {lvalue},class PyGePlanarEnt,class AcGeTol)'''
    ...
    def isClosed (self, *args, **kwargs):
      '''
isClosed( (Curve3d)arg1) -> bool :

    C++ signature :
        bool isClosed(class PyGeCurve3d {lvalue})

isClosed( (Curve3d)arg1, (Tol)arg2) -> bool :

    C++ signature :
        bool isClosed(class PyGeCurve3d {lvalue},class AcGeTol)'''
    ...
    def isColinearTo (self, *args, **kwargs):
      '''
isColinearTo( (LinearEnt3d)arg1, (LinearEnt3d)arg2) -> bool :

    C++ signature :
        bool isColinearTo(class PyGeLinearEnt3d {lvalue},class PyGeLinearEnt3d)

isColinearTo( (LinearEnt3d)arg1, (LinearEnt3d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isColinearTo(class PyGeLinearEnt3d {lvalue},class PyGeLinearEnt3d,class AcGeTol)'''
    ...
    def isCoplanarWith (self, *args, **kwargs):
      '''
isCoplanarWith( (Curve3d)arg1, (Curve3d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isCoplanarWith(class PyGeCurve3d {lvalue},class PyGeCurve3d)

isCoplanarWith( (Curve3d)arg1, (Curve3d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple isCoplanarWith(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeTol)'''
    ...
    def isDegenerate (self, *args, **kwargs):
      '''
isDegenerate( (Curve3d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isDegenerate(class PyGeCurve3d {lvalue})

isDegenerate( (Curve3d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isDegenerate(class PyGeCurve3d {lvalue},class AcGeTol)'''
    ...
    def isEqualTo (self, *args, **kwargs):
      '''
isEqualTo( (Entity3d)arg1, (Entity3d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity3d {lvalue},class PyGeEntity3d,class AcGeTol)'''
    ...
    def isKindOf (self, *args, **kwargs):
      '''
isKindOf( (Entity3d)arg1, (EntityId)arg2) -> bool :

    C++ signature :
        bool isKindOf(class PyGeEntity3d {lvalue},enum AcGe::EntityId)'''
    ...
    def isLinear (self, *args, **kwargs):
      '''
isLinear( (Curve3d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isLinear(class PyGeCurve3d {lvalue})

isLinear( (Curve3d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isLinear(class PyGeCurve3d {lvalue},class AcGeTol)'''
    ...
    def isNull (self, *args, **kwargs):
      '''
isNull( (Entity3d)arg1) -> bool :

    C++ signature :
        bool isNull(class PyGeEntity3d {lvalue})'''
    ...
    def isOn (self, *args, **kwargs):
      '''
isOn( (LinearEnt3d)arg1, (Point3d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isOn(class PyGeLinearEnt3d {lvalue},class AcGePoint3d)

isOn( (LinearEnt3d)arg1, (Point3d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple isOn(class PyGeLinearEnt3d {lvalue},class AcGePoint3d,class AcGeTol)

isOn( (LinearEnt3d)arg1, (float)arg2) -> bool :

    C++ signature :
        bool isOn(class PyGeLinearEnt3d {lvalue},double)

isOn( (LinearEnt3d)arg1, (float)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeLinearEnt3d {lvalue},double,class AcGeTol)

isOn( (LinearEnt3d)arg1, (Plane)arg2) -> bool :

    C++ signature :
        bool isOn(class PyGeLinearEnt3d {lvalue},class PyGePlane)

isOn( (LinearEnt3d)arg1, (Plane)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeLinearEnt3d {lvalue},class PyGePlane,class AcGeTol)'''
    ...
    def isParallelTo (self, *args, **kwargs):
      '''
isParallelTo( (LinearEnt3d)arg1, (LinearEnt3d)arg2) -> bool :

    C++ signature :
        bool isParallelTo(class PyGeLinearEnt3d {lvalue},class PyGeLinearEnt3d)

isParallelTo( (LinearEnt3d)arg1, (LinearEnt3d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isParallelTo(class PyGeLinearEnt3d {lvalue},class PyGeLinearEnt3d,class AcGeTol)

isParallelTo( (LinearEnt3d)arg1, (PlanarEnt)arg2) -> bool :

    C++ signature :
        bool isParallelTo(class PyGeLinearEnt3d {lvalue},class PyGePlanarEnt)

isParallelTo( (LinearEnt3d)arg1, (PlanarEnt)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isParallelTo(class PyGeLinearEnt3d {lvalue},class PyGePlanarEnt,class AcGeTol)'''
    ...
    def isPeriodic (self, *args, **kwargs):
      '''
isPeriodic( (Curve3d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isPeriodic(class PyGeCurve3d {lvalue})'''
    ...
    def isPerpendicularTo (self, *args, **kwargs):
      '''
isPerpendicularTo( (LinearEnt3d)arg1, (LinearEnt3d)arg2) -> bool :

    C++ signature :
        bool isPerpendicularTo(class PyGeLinearEnt3d {lvalue},class PyGeLinearEnt3d)

isPerpendicularTo( (LinearEnt3d)arg1, (LinearEnt3d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isPerpendicularTo(class PyGeLinearEnt3d {lvalue},class PyGeLinearEnt3d,class AcGeTol)

isPerpendicularTo( (LinearEnt3d)arg1, (PlanarEnt)arg2) -> bool :

    C++ signature :
        bool isPerpendicularTo(class PyGeLinearEnt3d {lvalue},class PyGePlanarEnt)

isPerpendicularTo( (LinearEnt3d)arg1, (PlanarEnt)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isPerpendicularTo(class PyGeLinearEnt3d {lvalue},class PyGePlanarEnt,class AcGeTol)'''
    ...
    def isPlanar (self, *args, **kwargs):
      '''
isPlanar( (Curve3d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isPlanar(class PyGeCurve3d {lvalue})

isPlanar( (Curve3d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isPlanar(class PyGeCurve3d {lvalue},class AcGeTol)'''
    ...
    def length (self, *args, **kwargs):
      '''
length( (Curve3d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double length(class PyGeCurve3d {lvalue},double,double)

length( (Curve3d)arg1, (float)arg2, (float)arg3, (float)arg4) -> float :

    C++ signature :
        double length(class PyGeCurve3d {lvalue},double,double,double)'''
    ...
    def mirror (self, *args, **kwargs):
      '''
mirror( (Entity3d)arg1, (Plane)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} mirror(class PyGeEntity3d {lvalue},class PyGePlane)'''
    ...
    def orthoBoundBlock (self, *args, **kwargs):
      '''
orthoBoundBlock( (Curve3d)arg1) -> BoundBlock3d :

    C++ signature :
        class PyGeBoundBlock3d orthoBoundBlock(class PyGeCurve3d {lvalue})

orthoBoundBlock( (Curve3d)arg1, (Interval)arg2) -> BoundBlock3d :

    C++ signature :
        class PyGeBoundBlock3d orthoBoundBlock(class PyGeCurve3d {lvalue},class PyGeInterval)'''
    ...
    def orthoProject (self, *args, **kwargs):
      '''
orthoProject( (Curve3d)arg1, (Plane)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d orthoProject(class PyGeCurve3d {lvalue},class PyGePlane)

orthoProject( (Curve3d)arg1, (Plane)arg2, (Tol)arg3) -> Entity3d :

    C++ signature :
        class PyGeEntity3d orthoProject(class PyGeCurve3d {lvalue},class PyGePlane,class AcGeTol)'''
    ...
    def overlap (self, *args, **kwargs):
      '''
overlap( (LinearEnt3d)arg1, (LinearEnt3d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple overlap(class PyGeLinearEnt3d {lvalue},class PyGeLinearEnt3d)

overlap( (LinearEnt3d)arg1, (LinearEnt3d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple overlap(class PyGeLinearEnt3d {lvalue},class PyGeLinearEnt3d,class AcGeTol)'''
    ...
    def paramAtLength (self, *args, **kwargs):
      '''
paramAtLength( (Curve3d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double paramAtLength(class PyGeCurve3d {lvalue},double,double)

paramAtLength( (Curve3d)arg1, (float)arg2, (float)arg3, (bool)arg4, (float)arg5) -> float :

    C++ signature :
        double paramAtLength(class PyGeCurve3d {lvalue},double,double,bool,double)'''
    ...
    def paramOf (self, *args, **kwargs):
      '''
paramOf( (Curve3d)arg1, (Point3d)arg2) -> float :

    C++ signature :
        double paramOf(class PyGeCurve3d {lvalue},class AcGePoint3d)

paramOf( (Curve3d)arg1, (Point3d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double paramOf(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def pointOnLine (self, *args, **kwargs):
      '''
pointOnLine( (LinearEnt3d)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d pointOnLine(class PyGeLinearEnt3d {lvalue})'''
    ...
    def projClosestPointTo (self, *args, **kwargs):
      '''
projClosestPointTo( (Curve3d)arg1, (Point3d)arg2, (Vector3d)arg3) -> Point3d :

    C++ signature :
        class AcGePoint3d projClosestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeVector3d)

projClosestPointTo( (Curve3d)arg1, (Point3d)arg2, (Vector3d)arg3, (Tol)arg4) -> Point3d :

    C++ signature :
        class AcGePoint3d projClosestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeVector3d,class AcGeTol)'''
    ...
    def projClosestPointsTo (self, *args, **kwargs):
      '''
projClosestPointsTo( (Curve3d)arg1, (Curve3d)arg2, (Vector3d)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple projClosestPointsTo(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeVector3d)

projClosestPointsTo( (Curve3d)arg1, (Curve3d)arg2, (Vector3d)arg3, (Tol)arg4) -> tuple :

    C++ signature :
        class boost::python::tuple projClosestPointsTo(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeVector3d,class AcGeTol)'''
    ...
    def projIntersectWith (self, *args, **kwargs):
      '''
projIntersectWith( (LinearEnt3d)arg1, (LinearEnt3d)arg2, (Vector3d)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple projIntersectWith(class PyGeLinearEnt3d {lvalue},class PyGeLinearEnt3d,class AcGeVector3d)

projIntersectWith( (LinearEnt3d)arg1, (LinearEnt3d)arg2, (Vector3d)arg3, (Tol)arg4) -> tuple :

    C++ signature :
        class boost::python::tuple projIntersectWith(class PyGeLinearEnt3d {lvalue},class PyGeLinearEnt3d,class AcGeVector3d,class AcGeTol)'''
    ...
    def project (self, *args, **kwargs):
      '''
project( (Curve3d)arg1, (Plane)arg2, (Vector3d)arg3) -> Entity3d :

    C++ signature :
        class PyGeEntity3d project(class PyGeCurve3d {lvalue},class PyGePlane,class AcGeVector3d)

project( (Curve3d)arg1, (Plane)arg2, (Vector3d)arg3, (Tol)arg4) -> Entity3d :

    C++ signature :
        class PyGeEntity3d project(class PyGeCurve3d {lvalue},class PyGePlane,class AcGeVector3d,class AcGeTol)'''
    ...
    def reverseParam (self, *args, **kwargs):
      '''
reverseParam( (Curve3d)arg1) -> Curve3d :

    C++ signature :
        class PyGeCurve3d {lvalue} reverseParam(class PyGeCurve3d {lvalue})'''
    ...
    def rotateBy (self, *args, **kwargs):
      '''
rotateBy( (Entity3d)arg1, (float)arg2, (Vector3d)arg3) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} rotateBy(class PyGeEntity3d {lvalue},double,class AcGeVector3d)

rotateBy( (Entity3d)arg1, (float)arg2, (Vector3d)arg3, (Point3d)arg4) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} rotateBy(class PyGeEntity3d {lvalue},double,class AcGeVector3d,class AcGePoint3d)'''
    ...
    def scaleBy (self, *args, **kwargs):
      '''
scaleBy( (Entity3d)arg1, (float)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} scaleBy(class PyGeEntity3d {lvalue},double)

scaleBy( (Entity3d)arg1, (float)arg2, (Point3d)arg3) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} scaleBy(class PyGeEntity3d {lvalue},double,class AcGePoint3d)'''
    ...
    def set (self, *args, **kwargs):
      '''
set( (Ray3d)arg1, (Point3d)arg2, (Vector3d)arg3) -> Ray3d :

    C++ signature :
        class PyGeRay3d {lvalue} set(class PyGeRay3d {lvalue},class AcGePoint3d,class AcGeVector3d)

set( (Ray3d)arg1, (Point3d)arg2, (Point3d)arg3) -> Ray3d :

    C++ signature :
        class PyGeRay3d {lvalue} set(class PyGeRay3d {lvalue},class AcGePoint3d,class AcGePoint3d)'''
    ...
    def setInterval (self, *args, **kwargs):
      '''
setInterval( (Curve3d)arg1) -> Curve3d :

    C++ signature :
        class PyGeCurve3d {lvalue} setInterval(class PyGeCurve3d {lvalue})

setInterval( (Curve3d)arg1, (Interval)arg2) -> bool :

    C++ signature :
        bool setInterval(class PyGeCurve3d {lvalue},class PyGeInterval)'''
    ...
    def transformBy (self, *args, **kwargs):
      '''
transformBy( (Entity3d)arg1, (Matrix3d)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} transformBy(class PyGeEntity3d {lvalue},class AcGeMatrix3d)'''
    ...
    def translateBy (self, *args, **kwargs):
      '''
translateBy( (Entity3d)arg1, (Vector3d)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} translateBy(class PyGeEntity3d {lvalue},class AcGeVector3d)'''
    ...
    def type (self, *args, **kwargs):
      '''
type( (Entity3d)arg1) -> EntityId :

    C++ signature :
        enum AcGe::EntityId type(class PyGeEntity3d {lvalue})'''
    ...

class Scale2d:
    def __eq__ (self, *args, **kwargs):
      '''
__eq__( (Scale2d)arg1, (Scale2d)arg2) -> bool :

    C++ signature :
        bool __eq__(class AcGeScale2d {lvalue},class AcGeScale2d)'''
    ...
    def __imul__ (self, *args, **kwargs):
      '''
__imul__( (Scale2d)arg1, (float)arg2) -> Scale2d :

    C++ signature :
        class AcGeScale2d {lvalue} __imul__(class AcGeScale2d {lvalue},double)

__imul__( (Scale2d)arg1, (Scale2d)arg2) -> Scale2d :

    C++ signature :
        class AcGeScale2d {lvalue} __imul__(class AcGeScale2d {lvalue},class AcGeScale2d)'''
    ...
    def __init__ (self, *args, **kwargs):
      '''
__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
    ...
    def __mul__ (self, *args, **kwargs):
      '''
__mul__( (Scale2d)arg1, (float)arg2) -> Scale2d :

    C++ signature :
        class AcGeScale2d __mul__(class AcGeScale2d {lvalue},double)

__mul__( (Scale2d)arg1, (Scale2d)arg2) -> Scale2d :

    C++ signature :
        class AcGeScale2d __mul__(class AcGeScale2d {lvalue},class AcGeScale2d)'''
    ...
    def __ne__ (self, *args, **kwargs):
      '''
__ne__( (Scale2d)arg1, (Scale2d)arg2) -> bool :

    C++ signature :
        bool __ne__(class AcGeScale2d {lvalue},class AcGeScale2d)'''
    ...
    def postMultBy (self, *args, **kwargs):
      '''
postMultBy( (Scale2d)arg1, (Scale2d)arg2) -> Scale2d :

    C++ signature :
        class AcGeScale2d {lvalue} postMultBy(class AcGeScale2d {lvalue},class AcGeScale2d)'''
    ...
    def preMultBy (self, *args, **kwargs):
      '''
preMultBy( (Scale2d)arg1, (Scale2d)arg2) -> Scale2d :

    C++ signature :
        class AcGeScale2d {lvalue} preMultBy(class AcGeScale2d {lvalue},class AcGeScale2d)'''
    ...
    def setToProduct (self, *args, **kwargs):
      '''
setToProduct( (Scale2d)arg1, (Scale2d)arg2, (float)arg3) -> Scale2d :

    C++ signature :
        class AcGeScale2d {lvalue} setToProduct(class AcGeScale2d {lvalue},class AcGeScale2d,double)

setToProduct( (Scale2d)arg1, (Scale2d)arg2, (Scale2d)arg3) -> Scale2d :

    C++ signature :
        class AcGeScale2d {lvalue} setToProduct(class AcGeScale2d {lvalue},class AcGeScale2d,class AcGeScale2d)'''
    ...
    def sx (self, *args, **kwargs):
      '''None'''
    ...
    def sy (self, *args, **kwargs):
      '''None'''
    ...
    def toString (self, *args, **kwargs):
      '''
toString( (Scale2d)arg1) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > toString(class AcGeScale2d)'''
    ...

class Scale3d:
    def __eq__ (self, *args, **kwargs):
      '''
__eq__( (Scale3d)arg1, (Scale3d)arg2) -> bool :

    C++ signature :
        bool __eq__(class AcGeScale3d {lvalue},class AcGeScale3d)'''
    ...
    def __imul__ (self, *args, **kwargs):
      '''
__imul__( (Scale3d)arg1, (float)arg2) -> Scale3d :

    C++ signature :
        class AcGeScale3d {lvalue} __imul__(class AcGeScale3d {lvalue},double)

__imul__( (Scale3d)arg1, (Scale3d)arg2) -> Scale3d :

    C++ signature :
        class AcGeScale3d {lvalue} __imul__(class AcGeScale3d {lvalue},class AcGeScale3d)'''
    ...
    def __init__ (self, *args, **kwargs):
      '''
__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
    ...
    def __mul__ (self, *args, **kwargs):
      '''
__mul__( (Scale3d)arg1, (float)arg2) -> Scale3d :

    C++ signature :
        class AcGeScale3d __mul__(class AcGeScale3d {lvalue},double)

__mul__( (Scale3d)arg1, (Scale3d)arg2) -> Scale3d :

    C++ signature :
        class AcGeScale3d __mul__(class AcGeScale3d {lvalue},class AcGeScale3d)'''
    ...
    def __ne__ (self, *args, **kwargs):
      '''
__ne__( (Scale3d)arg1, (Scale3d)arg2) -> bool :

    C++ signature :
        bool __ne__(class AcGeScale3d {lvalue},class AcGeScale3d)'''
    ...
    def postMultBy (self, *args, **kwargs):
      '''
postMultBy( (Scale3d)arg1, (Scale3d)arg2) -> Scale3d :

    C++ signature :
        class AcGeScale3d {lvalue} postMultBy(class AcGeScale3d {lvalue},class AcGeScale3d)'''
    ...
    def preMultBy (self, *args, **kwargs):
      '''
preMultBy( (Scale3d)arg1, (Scale3d)arg2) -> Scale3d :

    C++ signature :
        class AcGeScale3d {lvalue} preMultBy(class AcGeScale3d {lvalue},class AcGeScale3d)'''
    ...
    def setToProduct (self, *args, **kwargs):
      '''
setToProduct( (Scale3d)arg1, (Scale3d)arg2, (float)arg3) -> Scale3d :

    C++ signature :
        class AcGeScale3d {lvalue} setToProduct(class AcGeScale3d {lvalue},class AcGeScale3d,double)

setToProduct( (Scale3d)arg1, (Scale3d)arg2, (Scale3d)arg3) -> Scale3d :

    C++ signature :
        class AcGeScale3d {lvalue} setToProduct(class AcGeScale3d {lvalue},class AcGeScale3d,class AcGeScale3d)'''
    ...
    def sx (self, *args, **kwargs):
      '''None'''
    ...
    def sy (self, *args, **kwargs):
      '''None'''
    ...
    def sz (self, *args, **kwargs):
      '''None'''
    ...
    def toString (self, *args, **kwargs):
      '''
toString( (Scale3d)arg1) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > toString(class AcGeScale3d)'''
    ...

class SplineEnt2d:
    def __eq__ (self, *args, **kwargs):
      '''
__eq__( (Entity2d)arg1, (Entity2d)arg2) -> bool :

    C++ signature :
        bool __eq__(class PyGeEntity2d {lvalue},class PyGeEntity2d)'''
    ...
    def __init__ (self, *args, **kwargs):
      '''Raises an exception
This class cannot be instantiated from Python
'''
    ...
    def __ne__ (self, *args, **kwargs):
      '''
__ne__( (Entity2d)arg1, (Entity2d)arg2) -> bool :

    C++ signature :
        bool __ne__(class PyGeEntity2d {lvalue},class PyGeEntity2d)'''
    ...
    def area (self, *args, **kwargs):
      '''
area( (Curve2d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double area(class PyGeCurve2d {lvalue},double,double)

area( (Curve2d)arg1, (float)arg2, (float)arg3, (Tol)arg4) -> float :

    C++ signature :
        double area(class PyGeCurve2d {lvalue},double,double,class AcGeTol)'''
    ...
    def boundBlock (self, *args, **kwargs):
      '''
boundBlock( (Curve2d)arg1) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d boundBlock(class PyGeCurve2d {lvalue})

boundBlock( (Curve2d)arg1, (Interval)arg2) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d boundBlock(class PyGeCurve2d {lvalue},class PyGeInterval)'''
    ...
    def className (self, *args, **kwargs):
      '''
className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def closestPointTo (self, *args, **kwargs):
      '''
closestPointTo( (Curve2d)arg1, (Point2d)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d closestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d)

closestPointTo( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> Point2d :

    C++ signature :
        class AcGePoint2d closestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)

closestPointTo( (Curve2d)arg1, (Curve2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointTo(class PyGeCurve2d {lvalue},class PyGeCurve2d)

closestPointTo( (Curve2d)arg1, (Curve2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointTo(class PyGeCurve2d {lvalue},class PyGeCurve2d,class AcGeTol)'''
    ...
    def continuityAtKnot (self, *args, **kwargs):
      '''
continuityAtKnot( (SplineEnt2d)arg1, (int)arg2) -> int :

    C++ signature :
        int continuityAtKnot(class PyGeSplineEnt2d {lvalue},int)

continuityAtKnot( (SplineEnt2d)arg1, (int)arg2, (Tol)arg3) -> int :

    C++ signature :
        int continuityAtKnot(class PyGeSplineEnt2d {lvalue},int,class AcGeTol)'''
    ...
    def controlPointAt (self, *args, **kwargs):
      '''
controlPointAt( (SplineEnt2d)arg1, (int)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d controlPointAt(class PyGeSplineEnt2d {lvalue},int)'''
    ...
    def copy (self, *args, **kwargs):
      '''
copy( (Entity2d)arg1) -> Entity2d :

    C++ signature :
        class PyGeEntity2d copy(class PyGeEntity2d {lvalue})'''
    ...
    def degree (self, *args, **kwargs):
      '''
degree( (SplineEnt2d)arg1) -> int :

    C++ signature :
        int degree(class PyGeSplineEnt2d {lvalue})'''
    ...
    def distanceTo (self, *args, **kwargs):
      '''
distanceTo( (Curve2d)arg1, (Point2d)arg2) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class AcGePoint2d)

distanceTo( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)

distanceTo( (Curve2d)arg1, (Curve2d)arg2) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class PyGeCurve2d)

distanceTo( (Curve2d)arg1, (Curve2d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class PyGeCurve2d,class AcGeTol)'''
    ...
    def endParam (self, *args, **kwargs):
      '''
endParam( (SplineEnt2d)arg1) -> float :

    C++ signature :
        double endParam(class PyGeSplineEnt2d {lvalue})'''
    ...
    def endPoint (self, *args, **kwargs):
      '''
endPoint( (SplineEnt2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d endPoint(class PyGeSplineEnt2d {lvalue})'''
    ...
    def evalPoint (self, *args, **kwargs):
      '''
evalPoint( (Curve2d)arg1, (float)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d evalPoint(class PyGeCurve2d {lvalue},double)

evalPoint( (Curve2d)arg1, (float)arg2, (int)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple evalPoint(class PyGeCurve2d {lvalue},double,int)'''
    ...
    def explode (self, *args, **kwargs):
      '''
explode( (Curve2d)arg1) -> list :

    C++ signature :
        class boost::python::list explode(class PyGeCurve2d {lvalue})

explode( (Curve2d)arg1, (Interval)arg2) -> list :

    C++ signature :
        class boost::python::list explode(class PyGeCurve2d {lvalue},class PyGeInterval)'''
    ...
    def getClosestPointTo (self, *args, **kwargs):
      '''
getClosestPointTo( (Curve2d)arg1, (Point2d)arg2) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getClosestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d)

getClosestPointTo( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getClosestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def getClosestPointsTo (self, *args, **kwargs):
      '''
getClosestPointsTo( (Curve2d)arg1, (Curve2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getClosestPointsTo(class PyGeCurve2d {lvalue},class PyGeCurve2d)

getClosestPointsTo( (Curve2d)arg1, (Curve2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple getClosestPointsTo(class PyGeCurve2d {lvalue},class PyGeCurve2d,class AcGeTol)'''
    ...
    def getEndPoint (self, *args, **kwargs):
      '''
getEndPoint( (Curve2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d getEndPoint(class PyGeCurve2d {lvalue})'''
    ...
    def getInterval (self, *args, **kwargs):
      '''
getInterval( (Curve2d)arg1) -> Interval :

    C++ signature :
        class PyGeInterval getInterval(class PyGeCurve2d {lvalue})'''
    ...
    def getNormalPoint (self, *args, **kwargs):
      '''
getNormalPoint( (Curve2d)arg1, (Point2d)arg2) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getNormalPoint(class PyGeCurve2d {lvalue},class AcGePoint2d)

getNormalPoint( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getNormalPoint(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def getSamplePoints (self, *args, **kwargs):
      '''
getSamplePoints( (Curve2d)arg1, (int)arg2) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve2d {lvalue},int)

getSamplePoints( (Curve2d)arg1, (float)arg2, (float)arg3, (float)arg4) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve2d {lvalue},double,double,double)'''
    ...
    def getSplitCurves (self, *args, **kwargs):
      '''
getSplitCurves( (Curve2d)arg1, (float)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getSplitCurves(class PyGeCurve2d {lvalue},double)'''
    ...
    def getStartPoint (self, *args, **kwargs):
      '''
getStartPoint( (Curve2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d getStartPoint(class PyGeCurve2d {lvalue})'''
    ...
    def getTrimmedOffset (self, *args, **kwargs):
      '''
getTrimmedOffset( (Curve2d)arg1, (float)arg2, (OffsetCrvExtType)arg3) -> list :

    C++ signature :
        class boost::python::list getTrimmedOffset(class PyGeCurve2d {lvalue},double,enum AcGe::OffsetCrvExtType)

getTrimmedOffset( (Curve2d)arg1, (float)arg2, (OffsetCrvExtType)arg3, (Tol)arg4) -> list :

    C++ signature :
        class boost::python::list getTrimmedOffset(class PyGeCurve2d {lvalue},double,enum AcGe::OffsetCrvExtType,class AcGeTol)'''
    ...
    def hasEndPoint (self, *args, **kwargs):
      '''
hasEndPoint( (Curve2d)arg1) -> bool :

    C++ signature :
        bool hasEndPoint(class PyGeCurve2d {lvalue})'''
    ...
    def hasFitData (self, *args, **kwargs):
      '''
hasFitData( (SplineEnt2d)arg1) -> bool :

    C++ signature :
        bool hasFitData(class PyGeSplineEnt2d {lvalue})'''
    ...
    def hasStartPoint (self, *args, **kwargs):
      '''
hasStartPoint( (Curve2d)arg1) -> bool :

    C++ signature :
        bool hasStartPoint(class PyGeCurve2d {lvalue})'''
    ...
    def isClosed (self, *args, **kwargs):
      '''
isClosed( (Curve2d)arg1) -> bool :

    C++ signature :
        bool isClosed(class PyGeCurve2d {lvalue})

isClosed( (Curve2d)arg1, (Tol)arg2) -> bool :

    C++ signature :
        bool isClosed(class PyGeCurve2d {lvalue},class AcGeTol)'''
    ...
    def isDegenerate (self, *args, **kwargs):
      '''
isDegenerate( (Curve2d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isDegenerate(class PyGeCurve2d {lvalue})

isDegenerate( (Curve2d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isDegenerate(class PyGeCurve2d {lvalue},class AcGeTol)'''
    ...
    def isEqualTo (self, *args, **kwargs):
      '''
isEqualTo( (Entity2d)arg1, (Entity2d)arg2) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity2d {lvalue},class PyGeEntity2d)

isEqualTo( (Entity2d)arg1, (Entity2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity2d {lvalue},class PyGeEntity2d,class AcGeTol)'''
    ...
    def isKindOf (self, *args, **kwargs):
      '''
isKindOf( (Entity2d)arg1, (EntityId)arg2) -> bool :

    C++ signature :
        bool isKindOf(class PyGeEntity2d {lvalue},enum AcGe::EntityId)'''
    ...
    def isLinear (self, *args, **kwargs):
      '''
isLinear( (Curve2d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isLinear(class PyGeCurve2d {lvalue})

isLinear( (Curve2d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isLinear(class PyGeCurve2d {lvalue},class AcGeTol)'''
    ...
    def isNull (self, *args, **kwargs):
      '''
isNull( (Entity2d)arg1) -> bool :

    C++ signature :
        bool isNull(class PyGeEntity2d {lvalue})'''
    ...
    def isOn (self, *args, **kwargs):
      '''
isOn( (Curve2d)arg1, (Point2d)arg2) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve2d {lvalue},class AcGePoint2d)

isOn( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)

isOn( (Curve2d)arg1, (Point2d)arg2, (float)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve2d {lvalue},class AcGePoint2d,double {lvalue})

isOn( (Curve2d)arg1, (Point2d)arg2, (float)arg3, (Tol)arg4) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve2d {lvalue},class AcGePoint2d,double {lvalue},class AcGeTol)

isOn( (Curve2d)arg1, (float)arg2) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve2d {lvalue},double)

isOn( (Curve2d)arg1, (float)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve2d {lvalue},double,class AcGeTol)'''
    ...
    def isPeriodic (self, *args, **kwargs):
      '''
isPeriodic( (Curve2d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isPeriodic(class PyGeCurve2d {lvalue})'''
    ...
    def isRational (self, *args, **kwargs):
      '''
isRational( (SplineEnt2d)arg1) -> bool :

    C++ signature :
        bool isRational(class PyGeSplineEnt2d {lvalue})'''
    ...
    def knotAt (self, *args, **kwargs):
      '''
knotAt( (SplineEnt2d)arg1, (int)arg2) -> float :

    C++ signature :
        double knotAt(class PyGeSplineEnt2d {lvalue},int)'''
    ...
    def knots (self, *args, **kwargs):
      '''
knots( (SplineEnt2d)arg1) -> KnotVector :

    C++ signature :
        class PyGeKnotVector knots(class PyGeSplineEnt2d {lvalue})'''
    ...
    def length (self, *args, **kwargs):
      '''
length( (Curve2d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double length(class PyGeCurve2d {lvalue},double,double)

length( (Curve2d)arg1, (float)arg2, (float)arg3, (float)arg4) -> float :

    C++ signature :
        double length(class PyGeCurve2d {lvalue},double,double,double)'''
    ...
    def mirror (self, *args, **kwargs):
      '''
mirror( (Entity2d)arg1, (Line2d)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} mirror(class PyGeEntity2d {lvalue},class PyGeLine2d)'''
    ...
    def numControlPoints (self, *args, **kwargs):
      '''
numControlPoints( (SplineEnt2d)arg1) -> int :

    C++ signature :
        int numControlPoints(class PyGeSplineEnt2d {lvalue})'''
    ...
    def numKnots (self, *args, **kwargs):
      '''
numKnots( (SplineEnt2d)arg1) -> int :

    C++ signature :
        int numKnots(class PyGeSplineEnt2d {lvalue})'''
    ...
    def order (self, *args, **kwargs):
      '''
order( (SplineEnt2d)arg1) -> int :

    C++ signature :
        int order(class PyGeSplineEnt2d {lvalue})'''
    ...
    def orthoBoundBlock (self, *args, **kwargs):
      '''
orthoBoundBlock( (Curve2d)arg1) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d orthoBoundBlock(class PyGeCurve2d {lvalue})

orthoBoundBlock( (Curve2d)arg1, (Interval)arg2) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d orthoBoundBlock(class PyGeCurve2d {lvalue},class PyGeInterval)'''
    ...
    def paramAtLength (self, *args, **kwargs):
      '''
paramAtLength( (Curve2d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double paramAtLength(class PyGeCurve2d {lvalue},double,double)

paramAtLength( (Curve2d)arg1, (float)arg2, (float)arg3, (bool)arg4, (float)arg5) -> float :

    C++ signature :
        double paramAtLength(class PyGeCurve2d {lvalue},double,double,bool,double)'''
    ...
    def paramOf (self, *args, **kwargs):
      '''
paramOf( (Curve2d)arg1, (Point2d)arg2) -> float :

    C++ signature :
        double paramOf(class PyGeCurve2d {lvalue},class AcGePoint2d)

paramOf( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double paramOf(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def reverseParam (self, *args, **kwargs):
      '''
reverseParam( (Curve2d)arg1) -> Curve2d :

    C++ signature :
        class PyGeCurve2d {lvalue} reverseParam(class PyGeCurve2d {lvalue})'''
    ...
    def rotateBy (self, *args, **kwargs):
      '''
rotateBy( (Entity2d)arg1, (float)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} rotateBy(class PyGeEntity2d {lvalue},double)

rotateBy( (Entity2d)arg1, (float)arg2, (Point2d)arg3) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} rotateBy(class PyGeEntity2d {lvalue},double,class AcGePoint2d)'''
    ...
    def scaleBy (self, *args, **kwargs):
      '''
scaleBy( (Entity2d)arg1, (float)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} scaleBy(class PyGeEntity2d {lvalue},double)

scaleBy( (Entity2d)arg1, (float)arg2, (Point2d)arg3) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} scaleBy(class PyGeEntity2d {lvalue},double,class AcGePoint2d)'''
    ...
    def setControlPointAt (self, *args, **kwargs):
      '''
setControlPointAt( (SplineEnt2d)arg1, (int)arg2, (Point2d)arg3) -> SplineEnt2d :

    C++ signature :
        class PyGeSplineEnt2d {lvalue} setControlPointAt(class PyGeSplineEnt2d {lvalue},int,class AcGePoint2d)'''
    ...
    def setInterval (self, *args, **kwargs):
      '''
setInterval( (Curve2d)arg1) -> Curve2d :

    C++ signature :
        class PyGeCurve2d {lvalue} setInterval(class PyGeCurve2d {lvalue})

setInterval( (Curve2d)arg1, (Interval)arg2) -> bool :

    C++ signature :
        bool setInterval(class PyGeCurve2d {lvalue},class PyGeInterval)'''
    ...
    def setKnotAt (self, *args, **kwargs):
      '''
setKnotAt( (SplineEnt2d)arg1, (int)arg2, (float)arg3) -> SplineEnt2d :

    C++ signature :
        class PyGeSplineEnt2d {lvalue} setKnotAt(class PyGeSplineEnt2d {lvalue},int,double)'''
    ...
    def startParam (self, *args, **kwargs):
      '''
startParam( (SplineEnt2d)arg1) -> float :

    C++ signature :
        double startParam(class PyGeSplineEnt2d {lvalue})'''
    ...
    def startPoint (self, *args, **kwargs):
      '''
startPoint( (SplineEnt2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d startPoint(class PyGeSplineEnt2d {lvalue})'''
    ...
    def transformBy (self, *args, **kwargs):
      '''
transformBy( (Entity2d)arg1, (Matrix2d)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} transformBy(class PyGeEntity2d {lvalue},class AcGeMatrix2d)'''
    ...
    def translateBy (self, *args, **kwargs):
      '''
translateBy( (Entity2d)arg1, (Vector2d)arg2) -> Entity2d :

    C++ signature :
        class PyGeEntity2d {lvalue} translateBy(class PyGeEntity2d {lvalue},class AcGeVector2d)'''
    ...
    def type (self, *args, **kwargs):
      '''
type( (Entity2d)arg1) -> EntityId :

    C++ signature :
        enum AcGe::EntityId type(class PyGeEntity2d {lvalue})'''
    ...

class SplineEnt3d:
    def __eq__ (self, *args, **kwargs):
      '''
__eq__( (Entity3d)arg1, (Entity3d)arg2) -> bool :

    C++ signature :
        bool __eq__(class PyGeEntity3d {lvalue},class PyGeEntity3d)'''
    ...
    def __init__ (self, *args, **kwargs):
      '''Raises an exception
This class cannot be instantiated from Python
'''
    ...
    def __ne__ (self, *args, **kwargs):
      '''
__ne__( (Entity3d)arg1, (Entity3d)arg2) -> bool :

    C++ signature :
        bool __ne__(class PyGeEntity3d {lvalue},class PyGeEntity3d)'''
    ...
    def area (self, *args, **kwargs):
      '''
area( (Curve3d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double area(class PyGeCurve3d {lvalue},double,double)

area( (Curve3d)arg1, (float)arg2, (float)arg3, (Tol)arg4) -> float :

    C++ signature :
        double area(class PyGeCurve3d {lvalue},double,double,class AcGeTol)'''
    ...
    def boundBlock (self, *args, **kwargs):
      '''
boundBlock( (Curve3d)arg1) -> BoundBlock3d :

    C++ signature :
        class PyGeBoundBlock3d boundBlock(class PyGeCurve3d {lvalue})

boundBlock( (Curve3d)arg1, (Interval)arg2) -> BoundBlock3d :

    C++ signature :
        class PyGeBoundBlock3d boundBlock(class PyGeCurve3d {lvalue},class PyGeInterval)'''
    ...
    def className (self, *args, **kwargs):
      '''
className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def closestPointTo (self, *args, **kwargs):
      '''
closestPointTo( (Curve3d)arg1, (Point3d)arg2) -> Point3d :

    C++ signature :
        class AcGePoint3d closestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d)

closestPointTo( (Curve3d)arg1, (Point3d)arg2, (Tol)arg3) -> Point3d :

    C++ signature :
        class AcGePoint3d closestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeTol)

closestPointTo( (Curve3d)arg1, (Curve3d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointTo(class PyGeCurve3d {lvalue},class PyGeCurve3d)

closestPointTo( (Curve3d)arg1, (Curve3d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointTo(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeTol)'''
    ...
    def continuityAtKnot (self, *args, **kwargs):
      '''
continuityAtKnot( (SplineEnt3d)arg1, (int)arg2) -> int :

    C++ signature :
        int continuityAtKnot(class PyGeSplineEnt3d {lvalue},int)

continuityAtKnot( (SplineEnt3d)arg1, (int)arg2, (Tol)arg3) -> int :

    C++ signature :
        int continuityAtKnot(class PyGeSplineEnt3d {lvalue},int,class AcGeTol)'''
    ...
    def controlPointAt (self, *args, **kwargs):
      '''
controlPointAt( (SplineEnt3d)arg1, (int)arg2) -> Point3d :

    C++ signature :
        class AcGePoint3d controlPointAt(class PyGeSplineEnt3d {lvalue},int)'''
    ...
    def copy (self, *args, **kwargs):
      '''
copy( (Entity3d)arg1) -> Entity3d :

    C++ signature :
        class PyGeEntity3d copy(class PyGeEntity3d {lvalue})'''
    ...
    def degree (self, *args, **kwargs):
      '''
degree( (SplineEnt3d)arg1) -> int :

    C++ signature :
        int degree(class PyGeSplineEnt3d {lvalue})'''
    ...
    def distanceTo (self, *args, **kwargs):
      '''
distanceTo( (Curve3d)arg1, (Point3d)arg2) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve3d {lvalue},class AcGePoint3d)

distanceTo( (Curve3d)arg1, (Point3d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeTol)

distanceTo( (Curve3d)arg1, (Curve3d)arg2) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve3d {lvalue},class PyGeCurve3d)

distanceTo( (Curve3d)arg1, (Curve3d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeTol)'''
    ...
    def endParam (self, *args, **kwargs):
      '''
endParam( (SplineEnt3d)arg1) -> float :

    C++ signature :
        double endParam(class PyGeSplineEnt3d {lvalue})'''
    ...
    def endPoint (self, *args, **kwargs):
      '''
endPoint( (SplineEnt3d)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d endPoint(class PyGeSplineEnt3d {lvalue})'''
    ...
    def evalPoint (self, *args, **kwargs):
      '''
evalPoint( (Curve3d)arg1, (float)arg2) -> Point3d :

    C++ signature :
        class AcGePoint3d evalPoint(class PyGeCurve3d {lvalue},double)

evalPoint( (Curve3d)arg1, (float)arg2, (int)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple evalPoint(class PyGeCurve3d {lvalue},double,int)'''
    ...
    def explode (self, *args, **kwargs):
      '''
explode( (Curve3d)arg1) -> list :

    C++ signature :
        class boost::python::list explode(class PyGeCurve3d {lvalue})

explode( (Curve3d)arg1, (Interval)arg2) -> list :

    C++ signature :
        class boost::python::list explode(class PyGeCurve3d {lvalue},class PyGeInterval)'''
    ...
    def getClosestPointTo (self, *args, **kwargs):
      '''
getClosestPointTo( (Curve3d)arg1, (Point3d)arg2) -> PointOnCurve3d :

    C++ signature :
        class PyGePointOnCurve3d getClosestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d)

getClosestPointTo( (Curve3d)arg1, (Point3d)arg2, (Tol)arg3) -> PointOnCurve3d :

    C++ signature :
        class PyGePointOnCurve3d getClosestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def getClosestPointsTo (self, *args, **kwargs):
      '''
getClosestPointsTo( (Curve3d)arg1, (Curve3d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getClosestPointsTo(class PyGeCurve3d {lvalue},class PyGeCurve3d)

getClosestPointsTo( (Curve3d)arg1, (Curve3d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple getClosestPointsTo(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeTol)'''
    ...
    def getEndPoint (self, *args, **kwargs):
      '''
getEndPoint( (Curve3d)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d getEndPoint(class PyGeCurve3d {lvalue})'''
    ...
    def getInterval (self, *args, **kwargs):
      '''
getInterval( (Curve3d)arg1) -> Interval :

    C++ signature :
        class PyGeInterval getInterval(class PyGeCurve3d {lvalue})'''
    ...
    def getNormalPoint (self, *args, **kwargs):
      '''
getNormalPoint( (Curve3d)arg1, (Point3d)arg2) -> PointOnCurve3d :

    C++ signature :
        class PyGePointOnCurve3d getNormalPoint(class PyGeCurve3d {lvalue},class AcGePoint3d)

getNormalPoint( (Curve3d)arg1, (Point3d)arg2, (Tol)arg3) -> PointOnCurve3d :

    C++ signature :
        class PyGePointOnCurve3d getNormalPoint(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def getProjClosestPointTo (self, *args, **kwargs):
      '''
getProjClosestPointTo( (Curve3d)arg1, (Point3d)arg2, (Vector3d)arg3) -> PointOnCurve3d :

    C++ signature :
        class PyGePointOnCurve3d getProjClosestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeVector3d)

getProjClosestPointTo( (Curve3d)arg1, (Point3d)arg2, (Vector3d)arg3, (Tol)arg4) -> PointOnCurve3d :

    C++ signature :
        class PyGePointOnCurve3d getProjClosestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeVector3d,class AcGeTol)'''
    ...
    def getProjClosestPointsTo (self, *args, **kwargs):
      '''
getProjClosestPointsTo( (Curve3d)arg1, (Curve3d)arg2, (Vector3d)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple getProjClosestPointsTo(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeVector3d)

getProjClosestPointsTo( (Curve3d)arg1, (Curve3d)arg2, (Vector3d)arg3, (Tol)arg4) -> tuple :

    C++ signature :
        class boost::python::tuple getProjClosestPointsTo(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeVector3d,class AcGeTol)'''
    ...
    def getSamplePoints (self, *args, **kwargs):
      '''
getSamplePoints( (Curve3d)arg1, (int)arg2) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve3d {lvalue},int)

getSamplePoints( (Curve3d)arg1, (float)arg2, (float)arg3, (float)arg4) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve3d {lvalue},double,double,double)'''
    ...
    def getSplitCurves (self, *args, **kwargs):
      '''
getSplitCurves( (Curve3d)arg1, (float)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getSplitCurves(class PyGeCurve3d {lvalue},double)'''
    ...
    def getStartPoint (self, *args, **kwargs):
      '''
getStartPoint( (Curve3d)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d getStartPoint(class PyGeCurve3d {lvalue})'''
    ...
    def getTrimmedOffset (self, *args, **kwargs):
      '''
getTrimmedOffset( (Curve3d)arg1, (float)arg2, (Vector3d)arg3, (OffsetCrvExtType)arg4) -> list :

    C++ signature :
        class boost::python::list getTrimmedOffset(class PyGeCurve3d {lvalue},double,class AcGeVector3d,enum AcGe::OffsetCrvExtType)

getTrimmedOffset( (Curve3d)arg1, (float)arg2, (Vector3d)arg3, (OffsetCrvExtType)arg4, (Tol)arg5) -> list :

    C++ signature :
        class boost::python::list getTrimmedOffset(class PyGeCurve3d {lvalue},double,class AcGeVector3d,enum AcGe::OffsetCrvExtType,class AcGeTol)'''
    ...
    def hasEndPoint (self, *args, **kwargs):
      '''
hasEndPoint( (Curve3d)arg1) -> bool :

    C++ signature :
        bool hasEndPoint(class PyGeCurve3d {lvalue})'''
    ...
    def hasFitData (self, *args, **kwargs):
      '''
hasFitData( (SplineEnt3d)arg1) -> bool :

    C++ signature :
        bool hasFitData(class PyGeSplineEnt3d {lvalue})'''
    ...
    def hasStartPoint (self, *args, **kwargs):
      '''
hasStartPoint( (Curve3d)arg1) -> bool :

    C++ signature :
        bool hasStartPoint(class PyGeCurve3d {lvalue})'''
    ...
    def isClosed (self, *args, **kwargs):
      '''
isClosed( (Curve3d)arg1) -> bool :

    C++ signature :
        bool isClosed(class PyGeCurve3d {lvalue})

isClosed( (Curve3d)arg1, (Tol)arg2) -> bool :

    C++ signature :
        bool isClosed(class PyGeCurve3d {lvalue},class AcGeTol)'''
    ...
    def isCoplanarWith (self, *args, **kwargs):
      '''
isCoplanarWith( (Curve3d)arg1, (Curve3d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isCoplanarWith(class PyGeCurve3d {lvalue},class PyGeCurve3d)

isCoplanarWith( (Curve3d)arg1, (Curve3d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple isCoplanarWith(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeTol)'''
    ...
    def isDegenerate (self, *args, **kwargs):
      '''
isDegenerate( (Curve3d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isDegenerate(class PyGeCurve3d {lvalue})

isDegenerate( (Curve3d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isDegenerate(class PyGeCurve3d {lvalue},class AcGeTol)'''
    ...
    def isEqualTo (self, *args, **kwargs):
      '''
isEqualTo( (Entity3d)arg1, (Entity3d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity3d {lvalue},class PyGeEntity3d,class AcGeTol)'''
    ...
    def isKindOf (self, *args, **kwargs):
      '''
isKindOf( (Entity3d)arg1, (EntityId)arg2) -> bool :

    C++ signature :
        bool isKindOf(class PyGeEntity3d {lvalue},enum AcGe::EntityId)'''
    ...
    def isLinear (self, *args, **kwargs):
      '''
isLinear( (Curve3d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isLinear(class PyGeCurve3d {lvalue})

isLinear( (Curve3d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isLinear(class PyGeCurve3d {lvalue},class AcGeTol)'''
    ...
    def isNull (self, *args, **kwargs):
      '''
isNull( (Entity3d)arg1) -> bool :

    C++ signature :
        bool isNull(class PyGeEntity3d {lvalue})'''
    ...
    def isOn (self, *args, **kwargs):
      '''
isOn( (Curve3d)arg1, (Point3d)arg2) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve3d {lvalue},class AcGePoint3d)

isOn( (Curve3d)arg1, (Point3d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeTol)

isOn( (Curve3d)arg1, (Point3d)arg2, (float)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve3d {lvalue},class AcGePoint3d,double {lvalue})

isOn( (Curve3d)arg1, (Point3d)arg2, (float)arg3, (Tol)arg4) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve3d {lvalue},class AcGePoint3d,double {lvalue},class AcGeTol)

isOn( (Curve3d)arg1, (float)arg2) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve3d {lvalue},double)

isOn( (Curve3d)arg1, (float)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeCurve3d {lvalue},double,class AcGeTol)'''
    ...
    def isPeriodic (self, *args, **kwargs):
      '''
isPeriodic( (Curve3d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isPeriodic(class PyGeCurve3d {lvalue})'''
    ...
    def isPlanar (self, *args, **kwargs):
      '''
isPlanar( (Curve3d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isPlanar(class PyGeCurve3d {lvalue})

isPlanar( (Curve3d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isPlanar(class PyGeCurve3d {lvalue},class AcGeTol)'''
    ...
    def isRational (self, *args, **kwargs):
      '''
isRational( (SplineEnt3d)arg1) -> bool :

    C++ signature :
        bool isRational(class PyGeSplineEnt3d {lvalue})'''
    ...
    def knotAt (self, *args, **kwargs):
      '''
knotAt( (SplineEnt3d)arg1, (int)arg2) -> float :

    C++ signature :
        double knotAt(class PyGeSplineEnt3d {lvalue},int)'''
    ...
    def knots (self, *args, **kwargs):
      '''
knots( (SplineEnt3d)arg1) -> KnotVector :

    C++ signature :
        class PyGeKnotVector knots(class PyGeSplineEnt3d {lvalue})'''
    ...
    def length (self, *args, **kwargs):
      '''
length( (Curve3d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double length(class PyGeCurve3d {lvalue},double,double)

length( (Curve3d)arg1, (float)arg2, (float)arg3, (float)arg4) -> float :

    C++ signature :
        double length(class PyGeCurve3d {lvalue},double,double,double)'''
    ...
    def mirror (self, *args, **kwargs):
      '''
mirror( (Entity3d)arg1, (Plane)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} mirror(class PyGeEntity3d {lvalue},class PyGePlane)'''
    ...
    def numControlPoints (self, *args, **kwargs):
      '''
numControlPoints( (SplineEnt3d)arg1) -> int :

    C++ signature :
        int numControlPoints(class PyGeSplineEnt3d {lvalue})'''
    ...
    def numKnots (self, *args, **kwargs):
      '''
numKnots( (SplineEnt3d)arg1) -> int :

    C++ signature :
        int numKnots(class PyGeSplineEnt3d {lvalue})'''
    ...
    def order (self, *args, **kwargs):
      '''
order( (SplineEnt3d)arg1) -> int :

    C++ signature :
        int order(class PyGeSplineEnt3d {lvalue})'''
    ...
    def orthoBoundBlock (self, *args, **kwargs):
      '''
orthoBoundBlock( (Curve3d)arg1) -> BoundBlock3d :

    C++ signature :
        class PyGeBoundBlock3d orthoBoundBlock(class PyGeCurve3d {lvalue})

orthoBoundBlock( (Curve3d)arg1, (Interval)arg2) -> BoundBlock3d :

    C++ signature :
        class PyGeBoundBlock3d orthoBoundBlock(class PyGeCurve3d {lvalue},class PyGeInterval)'''
    ...
    def orthoProject (self, *args, **kwargs):
      '''
orthoProject( (Curve3d)arg1, (Plane)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d orthoProject(class PyGeCurve3d {lvalue},class PyGePlane)

orthoProject( (Curve3d)arg1, (Plane)arg2, (Tol)arg3) -> Entity3d :

    C++ signature :
        class PyGeEntity3d orthoProject(class PyGeCurve3d {lvalue},class PyGePlane,class AcGeTol)'''
    ...
    def paramAtLength (self, *args, **kwargs):
      '''
paramAtLength( (Curve3d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double paramAtLength(class PyGeCurve3d {lvalue},double,double)

paramAtLength( (Curve3d)arg1, (float)arg2, (float)arg3, (bool)arg4, (float)arg5) -> float :

    C++ signature :
        double paramAtLength(class PyGeCurve3d {lvalue},double,double,bool,double)'''
    ...
    def paramOf (self, *args, **kwargs):
      '''
paramOf( (Curve3d)arg1, (Point3d)arg2) -> float :

    C++ signature :
        double paramOf(class PyGeCurve3d {lvalue},class AcGePoint3d)

paramOf( (Curve3d)arg1, (Point3d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double paramOf(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def projClosestPointTo (self, *args, **kwargs):
      '''
projClosestPointTo( (Curve3d)arg1, (Point3d)arg2, (Vector3d)arg3) -> Point3d :

    C++ signature :
        class AcGePoint3d projClosestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeVector3d)

projClosestPointTo( (Curve3d)arg1, (Point3d)arg2, (Vector3d)arg3, (Tol)arg4) -> Point3d :

    C++ signature :
        class AcGePoint3d projClosestPointTo(class PyGeCurve3d {lvalue},class AcGePoint3d,class AcGeVector3d,class AcGeTol)'''
    ...
    def projClosestPointsTo (self, *args, **kwargs):
      '''
projClosestPointsTo( (Curve3d)arg1, (Curve3d)arg2, (Vector3d)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple projClosestPointsTo(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeVector3d)

projClosestPointsTo( (Curve3d)arg1, (Curve3d)arg2, (Vector3d)arg3, (Tol)arg4) -> tuple :

    C++ signature :
        class boost::python::tuple projClosestPointsTo(class PyGeCurve3d {lvalue},class PyGeCurve3d,class AcGeVector3d,class AcGeTol)'''
    ...
    def project (self, *args, **kwargs):
      '''
project( (Curve3d)arg1, (Plane)arg2, (Vector3d)arg3) -> Entity3d :

    C++ signature :
        class PyGeEntity3d project(class PyGeCurve3d {lvalue},class PyGePlane,class AcGeVector3d)

project( (Curve3d)arg1, (Plane)arg2, (Vector3d)arg3, (Tol)arg4) -> Entity3d :

    C++ signature :
        class PyGeEntity3d project(class PyGeCurve3d {lvalue},class PyGePlane,class AcGeVector3d,class AcGeTol)'''
    ...
    def reverseParam (self, *args, **kwargs):
      '''
reverseParam( (Curve3d)arg1) -> Curve3d :

    C++ signature :
        class PyGeCurve3d {lvalue} reverseParam(class PyGeCurve3d {lvalue})'''
    ...
    def rotateBy (self, *args, **kwargs):
      '''
rotateBy( (Entity3d)arg1, (float)arg2, (Vector3d)arg3) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} rotateBy(class PyGeEntity3d {lvalue},double,class AcGeVector3d)

rotateBy( (Entity3d)arg1, (float)arg2, (Vector3d)arg3, (Point3d)arg4) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} rotateBy(class PyGeEntity3d {lvalue},double,class AcGeVector3d,class AcGePoint3d)'''
    ...
    def scaleBy (self, *args, **kwargs):
      '''
scaleBy( (Entity3d)arg1, (float)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} scaleBy(class PyGeEntity3d {lvalue},double)

scaleBy( (Entity3d)arg1, (float)arg2, (Point3d)arg3) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} scaleBy(class PyGeEntity3d {lvalue},double,class AcGePoint3d)'''
    ...
    def setControlPointAt (self, *args, **kwargs):
      '''
setControlPointAt( (SplineEnt3d)arg1, (int)arg2, (Point3d)arg3) -> SplineEnt3d :

    C++ signature :
        class PyGeSplineEnt3d {lvalue} setControlPointAt(class PyGeSplineEnt3d {lvalue},int,class AcGePoint3d)'''
    ...
    def setInterval (self, *args, **kwargs):
      '''
setInterval( (Curve3d)arg1) -> Curve3d :

    C++ signature :
        class PyGeCurve3d {lvalue} setInterval(class PyGeCurve3d {lvalue})

setInterval( (Curve3d)arg1, (Interval)arg2) -> bool :

    C++ signature :
        bool setInterval(class PyGeCurve3d {lvalue},class PyGeInterval)'''
    ...
    def setKnotAt (self, *args, **kwargs):
      '''
setKnotAt( (SplineEnt3d)arg1, (int)arg2, (float)arg3) -> SplineEnt3d :

    C++ signature :
        class PyGeSplineEnt3d {lvalue} setKnotAt(class PyGeSplineEnt3d {lvalue},int,double)'''
    ...
    def startParam (self, *args, **kwargs):
      '''
startParam( (SplineEnt3d)arg1) -> float :

    C++ signature :
        double startParam(class PyGeSplineEnt3d {lvalue})'''
    ...
    def startPoint (self, *args, **kwargs):
      '''
startPoint( (SplineEnt3d)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d startPoint(class PyGeSplineEnt3d {lvalue})'''
    ...
    def transformBy (self, *args, **kwargs):
      '''
transformBy( (Entity3d)arg1, (Matrix3d)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} transformBy(class PyGeEntity3d {lvalue},class AcGeMatrix3d)'''
    ...
    def translateBy (self, *args, **kwargs):
      '''
translateBy( (Entity3d)arg1, (Vector3d)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} translateBy(class PyGeEntity3d {lvalue},class AcGeVector3d)'''
    ...
    def type (self, *args, **kwargs):
      '''
type( (Entity3d)arg1) -> EntityId :

    C++ signature :
        enum AcGe::EntityId type(class PyGeEntity3d {lvalue})'''
    ...

class SurfSurfInt:
    def __eq__ (self, *args, **kwargs):
      '''
__eq__( (Entity3d)arg1, (Entity3d)arg2) -> bool :

    C++ signature :
        bool __eq__(class PyGeEntity3d {lvalue},class PyGeEntity3d)'''
    ...
    def __init__ (self, *args, **kwargs):
      '''Raises an exception
This class cannot be instantiated from Python
'''
    ...
    def __ne__ (self, *args, **kwargs):
      '''
__ne__( (Entity3d)arg1, (Entity3d)arg2) -> bool :

    C++ signature :
        bool __ne__(class PyGeEntity3d {lvalue},class PyGeEntity3d)'''
    ...
    def className (self, *args, **kwargs):
      '''
className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def copy (self, *args, **kwargs):
      '''
copy( (Entity3d)arg1) -> Entity3d :

    C++ signature :
        class PyGeEntity3d copy(class PyGeEntity3d {lvalue})'''
    ...
    def isEqualTo (self, *args, **kwargs):
      '''
isEqualTo( (Entity3d)arg1, (Entity3d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity3d {lvalue},class PyGeEntity3d,class AcGeTol)'''
    ...
    def isKindOf (self, *args, **kwargs):
      '''
isKindOf( (Entity3d)arg1, (EntityId)arg2) -> bool :

    C++ signature :
        bool isKindOf(class PyGeEntity3d {lvalue},enum AcGe::EntityId)'''
    ...
    def isNull (self, *args, **kwargs):
      '''
isNull( (Entity3d)arg1) -> bool :

    C++ signature :
        bool isNull(class PyGeEntity3d {lvalue})'''
    ...
    def isOn (self, *args, **kwargs):
      '''
isOn( (Entity3d)arg1, (Point3d)arg2) -> bool :

    C++ signature :
        bool isOn(class PyGeEntity3d {lvalue},class AcGePoint3d)

isOn( (Entity3d)arg1, (Point3d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeEntity3d {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def mirror (self, *args, **kwargs):
      '''
mirror( (Entity3d)arg1, (Plane)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} mirror(class PyGeEntity3d {lvalue},class PyGePlane)'''
    ...
    def rotateBy (self, *args, **kwargs):
      '''
rotateBy( (Entity3d)arg1, (float)arg2, (Vector3d)arg3) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} rotateBy(class PyGeEntity3d {lvalue},double,class AcGeVector3d)

rotateBy( (Entity3d)arg1, (float)arg2, (Vector3d)arg3, (Point3d)arg4) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} rotateBy(class PyGeEntity3d {lvalue},double,class AcGeVector3d,class AcGePoint3d)'''
    ...
    def scaleBy (self, *args, **kwargs):
      '''
scaleBy( (Entity3d)arg1, (float)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} scaleBy(class PyGeEntity3d {lvalue},double)

scaleBy( (Entity3d)arg1, (float)arg2, (Point3d)arg3) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} scaleBy(class PyGeEntity3d {lvalue},double,class AcGePoint3d)'''
    ...
    def transformBy (self, *args, **kwargs):
      '''
transformBy( (Entity3d)arg1, (Matrix3d)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} transformBy(class PyGeEntity3d {lvalue},class AcGeMatrix3d)'''
    ...
    def translateBy (self, *args, **kwargs):
      '''
translateBy( (Entity3d)arg1, (Vector3d)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} translateBy(class PyGeEntity3d {lvalue},class AcGeVector3d)'''
    ...
    def type (self, *args, **kwargs):
      '''
type( (Entity3d)arg1) -> EntityId :

    C++ signature :
        enum AcGe::EntityId type(class PyGeEntity3d {lvalue})'''
    ...

class Surface:
    def __eq__ (self, *args, **kwargs):
      '''
__eq__( (Entity3d)arg1, (Entity3d)arg2) -> bool :

    C++ signature :
        bool __eq__(class PyGeEntity3d {lvalue},class PyGeEntity3d)'''
    ...
    def __init__ (self, *args, **kwargs):
      '''Raises an exception
This class cannot be instantiated from Python
'''
    ...
    def __ne__ (self, *args, **kwargs):
      '''
__ne__( (Entity3d)arg1, (Entity3d)arg2) -> bool :

    C++ signature :
        bool __ne__(class PyGeEntity3d {lvalue},class PyGeEntity3d)'''
    ...
    def className (self, *args, **kwargs):
      '''
className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def closestPointTo (self, *args, **kwargs):
      '''
closestPointTo( (Surface)arg1, (Point3d)arg2) -> Point3d :

    C++ signature :
        class AcGePoint3d closestPointTo(class PyAcGeSurface {lvalue},class AcGePoint3d)

closestPointTo( (Surface)arg1, (Point3d)arg2, (Tol)arg3) -> Point3d :

    C++ signature :
        class AcGePoint3d closestPointTo(class PyAcGeSurface {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def copy (self, *args, **kwargs):
      '''
copy( (Entity3d)arg1) -> Entity3d :

    C++ signature :
        class PyGeEntity3d copy(class PyGeEntity3d {lvalue})'''
    ...
    def distanceTo (self, *args, **kwargs):
      '''
distanceTo( (Surface)arg1, (Point3d)arg2) -> float :

    C++ signature :
        double distanceTo(class PyAcGeSurface {lvalue},class AcGePoint3d)

distanceTo( (Surface)arg1, (Point3d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double distanceTo(class PyAcGeSurface {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def evalPoint (self, *args, **kwargs):
      '''
evalPoint( (Surface)arg1, (Point2d)arg2) -> Point3d :

    C++ signature :
        class AcGePoint3d evalPoint(class PyAcGeSurface {lvalue},class AcGePoint2d)

evalPoint( (Surface)arg1, (Point2d)arg2, (int)arg3, (list)arg4) -> Point3d :

    C++ signature :
        class AcGePoint3d evalPoint(class PyAcGeSurface {lvalue},class AcGePoint2d,int,class boost::python::list {lvalue})

evalPoint( (Surface)arg1, (Point2d)arg2, (int)arg3, (list)arg4, (Vector3d)arg5) -> Point3d :

    C++ signature :
        class AcGePoint3d evalPoint(class PyAcGeSurface {lvalue},class AcGePoint2d,int,class boost::python::list {lvalue},class AcGeVector3d {lvalue})'''
    ...
    def isClosedInU (self, *args, **kwargs):
      '''
isClosedInU( (Surface)arg1) -> bool :

    C++ signature :
        bool isClosedInU(class PyAcGeSurface {lvalue})

isClosedInU( (Surface)arg1, (Tol)arg2) -> bool :

    C++ signature :
        bool isClosedInU(class PyAcGeSurface {lvalue},class AcGeTol)'''
    ...
    def isClosedInV (self, *args, **kwargs):
      '''
isClosedInV( (Surface)arg1) -> bool :

    C++ signature :
        bool isClosedInV(class PyAcGeSurface {lvalue})

isClosedInV( (Surface)arg1, (Tol)arg2) -> bool :

    C++ signature :
        bool isClosedInV(class PyAcGeSurface {lvalue},class AcGeTol)'''
    ...
    def isEqualTo (self, *args, **kwargs):
      '''
isEqualTo( (Entity3d)arg1, (Entity3d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity3d {lvalue},class PyGeEntity3d,class AcGeTol)'''
    ...
    def isKindOf (self, *args, **kwargs):
      '''
isKindOf( (Entity3d)arg1, (EntityId)arg2) -> bool :

    C++ signature :
        bool isKindOf(class PyGeEntity3d {lvalue},enum AcGe::EntityId)'''
    ...
    def isNormalReversed (self, *args, **kwargs):
      '''
isNormalReversed( (Surface)arg1) -> bool :

    C++ signature :
        bool isNormalReversed(class PyAcGeSurface {lvalue})'''
    ...
    def isNull (self, *args, **kwargs):
      '''
isNull( (Entity3d)arg1) -> bool :

    C++ signature :
        bool isNull(class PyGeEntity3d {lvalue})'''
    ...
    def isOn (self, *args, **kwargs):
      '''
isOn( (Surface)arg1, (Point3d)arg2) -> bool :

    C++ signature :
        bool isOn(class PyAcGeSurface {lvalue},class AcGePoint3d)

isOn( (Surface)arg1, (Point3d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isOn(class PyAcGeSurface {lvalue},class AcGePoint3d,class AcGeTol)

isOn( (Surface)arg1, (Point3d)arg2, (Point2d)arg3) -> bool :

    C++ signature :
        bool isOn(class PyAcGeSurface {lvalue},class AcGePoint3d,class AcGePoint2d {lvalue})

isOn( (Surface)arg1, (Point3d)arg2, (Point2d)arg3, (Tol)arg4) -> bool :

    C++ signature :
        bool isOn(class PyAcGeSurface {lvalue},class AcGePoint3d,class AcGePoint2d {lvalue},class AcGeTol)'''
    ...
    def mirror (self, *args, **kwargs):
      '''
mirror( (Entity3d)arg1, (Plane)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} mirror(class PyGeEntity3d {lvalue},class PyGePlane)'''
    ...
    def paramOf (self, *args, **kwargs):
      '''
paramOf( (Surface)arg1, (Point3d)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d paramOf(class PyAcGeSurface {lvalue},class AcGePoint3d)

paramOf( (Surface)arg1, (Point3d)arg2, (Tol)arg3) -> Point2d :

    C++ signature :
        class AcGePoint2d paramOf(class PyAcGeSurface {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def reverseNormal (self, *args, **kwargs):
      '''
reverseNormal( (Surface)arg1) -> Surface :

    C++ signature :
        class PyAcGeSurface {lvalue} reverseNormal(class PyAcGeSurface {lvalue})'''
    ...
    def rotateBy (self, *args, **kwargs):
      '''
rotateBy( (Entity3d)arg1, (float)arg2, (Vector3d)arg3) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} rotateBy(class PyGeEntity3d {lvalue},double,class AcGeVector3d)

rotateBy( (Entity3d)arg1, (float)arg2, (Vector3d)arg3, (Point3d)arg4) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} rotateBy(class PyGeEntity3d {lvalue},double,class AcGeVector3d,class AcGePoint3d)'''
    ...
    def scaleBy (self, *args, **kwargs):
      '''
scaleBy( (Entity3d)arg1, (float)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} scaleBy(class PyGeEntity3d {lvalue},double)

scaleBy( (Entity3d)arg1, (float)arg2, (Point3d)arg3) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} scaleBy(class PyGeEntity3d {lvalue},double,class AcGePoint3d)'''
    ...
    def transformBy (self, *args, **kwargs):
      '''
transformBy( (Entity3d)arg1, (Matrix3d)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} transformBy(class PyGeEntity3d {lvalue},class AcGeMatrix3d)'''
    ...
    def translateBy (self, *args, **kwargs):
      '''
translateBy( (Entity3d)arg1, (Vector3d)arg2) -> Entity3d :

    C++ signature :
        class PyGeEntity3d {lvalue} translateBy(class PyGeEntity3d {lvalue},class AcGeVector3d)'''
    ...
    def type (self, *args, **kwargs):
      '''
type( (Entity3d)arg1) -> EntityId :

    C++ signature :
        enum AcGe::EntityId type(class PyGeEntity3d {lvalue})'''
    ...

class Tol:
    def __eq__ (self, value, /):
      '''Return self==value.'''
    ...
    def __init__ (self, *args, **kwargs):
      '''
__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
    ...
    def __ne__ (self, value, /):
      '''Return self!=value.'''
    ...
    def current (self, *args, **kwargs):
      '''None'''
    ...
    def equalPoint (self, *args, **kwargs):
      '''
equalPoint( (Tol)arg1) -> float :

    C++ signature :
        double equalPoint(class AcGeTol {lvalue})'''
    ...
    def equalVector (self, *args, **kwargs):
      '''
equalVector( (Tol)arg1) -> float :

    C++ signature :
        double equalVector(class AcGeTol {lvalue})'''
    ...
    def setEqualPoint (self, *args, **kwargs):
      '''
setEqualPoint( (Tol)arg1, (float)arg2) -> None :

    C++ signature :
        void setEqualPoint(class AcGeTol {lvalue},double)'''
    ...
    def setEqualVector (self, *args, **kwargs):
      '''
setEqualVector( (Tol)arg1, (float)arg2) -> None :

    C++ signature :
        void setEqualVector(class AcGeTol {lvalue},double)'''
    ...

class Vector2d:
    def __add__ (self, *args, **kwargs):
      '''
__add__( (Vector2d)arg1, (Vector2d)arg2) -> Vector2d :

    C++ signature :
        class AcGeVector2d __add__(class AcGeVector2d {lvalue},class AcGeVector2d)'''
    ...
    def __eq__ (self, *args, **kwargs):
      '''
__eq__( (Vector2d)arg1, (Vector2d)arg2) -> bool :

    C++ signature :
        bool __eq__(class AcGeVector2d {lvalue},class AcGeVector2d)'''
    ...
    def __iadd__ (self, *args, **kwargs):
      '''
__iadd__( (Vector2d)arg1, (Vector2d)arg2) -> Vector2d :

    C++ signature :
        class AcGeVector2d {lvalue} __iadd__(class AcGeVector2d {lvalue},class AcGeVector2d)'''
    ...
    def __imul__ (self, *args, **kwargs):
      '''
__imul__( (Vector2d)arg1, (float)arg2) -> Vector2d :

    C++ signature :
        class AcGeVector2d {lvalue} __imul__(class AcGeVector2d {lvalue},double)'''
    ...
    def __init__ (self, *args, **kwargs):
      '''
__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1, (Vector2d)arg2) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class AcGeVector2d)

__init__( (object)arg1, (float)arg2, (float)arg3) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,double,double)'''
    ...
    def __isub__ (self, *args, **kwargs):
      '''
__isub__( (Vector2d)arg1, (Vector2d)arg2) -> Vector2d :

    C++ signature :
        class AcGeVector2d {lvalue} __isub__(class AcGeVector2d {lvalue},class AcGeVector2d)'''
    ...
    def __itruediv__ (self, *args, **kwargs):
      '''
__itruediv__( (Vector2d)arg1, (float)arg2) -> Vector2d :

    C++ signature :
        class AcGeVector2d {lvalue} __itruediv__(class AcGeVector2d {lvalue},double)'''
    ...
    def __matmul__ (self, *args, **kwargs):
      '''
__matmul__( (Vector2d)arg1, (Matrix2d)arg2) -> Vector2d :

    C++ signature :
        class AcGeVector2d __matmul__(class AcGeVector2d,class AcGeMatrix2d)'''
    ...
    def __mul__ (self, *args, **kwargs):
      '''
__mul__( (Vector2d)arg1, (float)arg2) -> Vector2d :

    C++ signature :
        class AcGeVector2d __mul__(class AcGeVector2d {lvalue},double)

__mul__( (float)arg1, (Vector2d)arg2) -> Vector2d :

    C++ signature :
        class AcGeVector2d __mul__(double,class AcGeVector2d)

__mul__( (Vector2d)arg1, (Matrix2d)arg2) -> Vector2d :

    C++ signature :
        class AcGeVector2d __mul__(class AcGeVector2d,class AcGeMatrix2d)'''
    ...
    def __ne__ (self, *args, **kwargs):
      '''
__ne__( (Vector2d)arg1, (Vector2d)arg2) -> bool :

    C++ signature :
        bool __ne__(class AcGeVector2d {lvalue},class AcGeVector2d)'''
    ...
    def __sub__ (self, *args, **kwargs):
      '''
__sub__( (Vector2d)arg1) -> Vector2d :

    C++ signature :
        class AcGeVector2d __sub__(class AcGeVector2d {lvalue})

__sub__( (Vector2d)arg1, (Vector2d)arg2) -> Vector2d :

    C++ signature :
        class AcGeVector2d __sub__(class AcGeVector2d {lvalue},class AcGeVector2d)'''
    ...
    def __truediv__ (self, *args, **kwargs):
      '''
__truediv__( (Vector2d)arg1, (float)arg2) -> Vector2d :

    C++ signature :
        class AcGeVector2d __truediv__(class AcGeVector2d {lvalue},double)'''
    ...
    def angle (self, *args, **kwargs):
      '''
angle( (Vector2d)arg1) -> float :

    C++ signature :
        double angle(class AcGeVector2d {lvalue})'''
    ...
    def angleTo (self, *args, **kwargs):
      '''
angleTo( (Vector2d)arg1, (Vector2d)arg2) -> float :

    C++ signature :
        double angleTo(class AcGeVector2d {lvalue},class AcGeVector2d)'''
    ...
    def dotProduct (self, *args, **kwargs):
      '''
dotProduct( (Vector2d)arg1, (Vector2d)arg2) -> float :

    C++ signature :
        double dotProduct(class AcGeVector2d {lvalue},class AcGeVector2d)'''
    ...
    def isCodirectionalTo (self, *args, **kwargs):
      '''
isCodirectionalTo( (Vector2d)arg1, (Vector2d)arg2 [, (Tol)AcGeTol=<PyGe.Tol object at 0x0000020CE5B19120>]) -> bool :

    C++ signature :
        bool isCodirectionalTo(class AcGeVector2d {lvalue},class AcGeVector2d [,class AcGeTol=<PyGe.Tol object at 0x0000020CE5B19120>])'''
    ...
    def isEqualTo (self, *args, **kwargs):
      '''
isEqualTo( (Vector2d)arg1, (Vector2d)arg2 [, (Tol)AcGeTol=<PyGe.Tol object at 0x0000020CE5B19240>]) -> bool :

    C++ signature :
        bool isEqualTo(class AcGeVector2d {lvalue},class AcGeVector2d [,class AcGeTol=<PyGe.Tol object at 0x0000020CE5B19240>])'''
    ...
    def isParallelTo (self, *args, **kwargs):
      '''
isParallelTo( (Vector2d)arg1, (Vector2d)arg2 [, (Tol)AcGeTol=<PyGe.Tol object at 0x0000020CE5B19090>]) -> bool :

    C++ signature :
        bool isParallelTo(class AcGeVector2d {lvalue},class AcGeVector2d [,class AcGeTol=<PyGe.Tol object at 0x0000020CE5B19090>])'''
    ...
    def isPerpendicularTo (self, *args, **kwargs):
      '''
isPerpendicularTo( (Vector2d)arg1, (Vector2d)arg2 [, (Tol)AcGeTol=<PyGe.Tol object at 0x0000020CE5B191B0>]) -> bool :

    C++ signature :
        bool isPerpendicularTo(class AcGeVector2d {lvalue},class AcGeVector2d [,class AcGeTol=<PyGe.Tol object at 0x0000020CE5B191B0>])'''
    ...
    def isUnitLength (self, *args, **kwargs):
      '''
isUnitLength( (Vector2d)arg1 [, (Tol)AcGeTol=<PyGe.Tol object at 0x0000020CE5B18F70>]) -> bool :

    C++ signature :
        bool isUnitLength(class AcGeVector2d {lvalue} [,class AcGeTol=<PyGe.Tol object at 0x0000020CE5B18F70>])'''
    ...
    def isZeroLength (self, *args, **kwargs):
      '''
isZeroLength( (Vector2d)arg1 [, (Tol)AcGeTol=<PyGe.Tol object at 0x0000020CE5B19000>]) -> bool :

    C++ signature :
        bool isZeroLength(class AcGeVector2d {lvalue} [,class AcGeTol=<PyGe.Tol object at 0x0000020CE5B19000>])'''
    ...
    def kIdentity (self, *args, **kwargs):
      '''None'''
    ...
    def kXAxis (self, *args, **kwargs):
      '''None'''
    ...
    def kYAxis (self, *args, **kwargs):
      '''None'''
    ...
    def length (self, *args, **kwargs):
      '''
length( (Vector2d)arg1) -> float :

    C++ signature :
        double length(class AcGeVector2d {lvalue})'''
    ...
    def lengthSqrd (self, *args, **kwargs):
      '''
lengthSqrd( (Vector2d)arg1) -> float :

    C++ signature :
        double lengthSqrd(class AcGeVector2d {lvalue})'''
    ...
    def mirror (self, *args, **kwargs):
      '''
mirror( (Vector2d)arg1, (Vector2d)arg2) -> Vector2d :

    C++ signature :
        class AcGeVector2d {lvalue} mirror(class AcGeVector2d {lvalue},class AcGeVector2d)'''
    ...
    def negate (self, *args, **kwargs):
      '''
negate( (Vector2d)arg1) -> Vector2d :

    C++ signature :
        class AcGeVector2d {lvalue} negate(class AcGeVector2d {lvalue})'''
    ...
    def normal (self, *args, **kwargs):
      '''
normal( (Vector2d)arg1 [, (Tol)AcGeTol=<PyGe.Tol object at 0x0000020CE5B18E50>]) -> Vector2d :

    C++ signature :
        class AcGeVector2d normal(class AcGeVector2d {lvalue} [,class AcGeTol=<PyGe.Tol object at 0x0000020CE5B18E50>])'''
    ...
    def normalize (self, *args, **kwargs):
      '''
normalize( (Vector2d)arg1 [, (Tol)AcGeTol=<PyGe.Tol object at 0x0000020CE5B18EE0>]) -> Vector2d :

    C++ signature :
        class AcGeVector2d {lvalue} normalize(class AcGeVector2d {lvalue} [,class AcGeTol=<PyGe.Tol object at 0x0000020CE5B18EE0>])'''
    ...
    def rotateBy (self, *args, **kwargs):
      '''
rotateBy( (Vector2d)arg1, (float)arg2) -> Vector2d :

    C++ signature :
        class AcGeVector2d {lvalue} rotateBy(class AcGeVector2d {lvalue},double)'''
    ...
    def set (self, *args, **kwargs):
      '''
set( (Vector2d)arg1, (float)arg2, (float)arg3) -> Vector2d :

    C++ signature :
        class AcGeVector2d {lvalue} set(class AcGeVector2d {lvalue},double,double)'''
    ...
    def setToProduct (self, *args, **kwargs):
      '''
setToProduct( (Vector2d)arg1, (Vector2d)arg2, (float)arg3) -> Vector2d :

    C++ signature :
        class AcGeVector2d {lvalue} setToProduct(class AcGeVector2d {lvalue},class AcGeVector2d,double)

setToProduct( (Vector2d)arg1, (Matrix2d)arg2, (Vector2d)arg3) -> Vector2d :

    C++ signature :
        class AcGeVector2d {lvalue} setToProduct(class AcGeVector2d {lvalue},class AcGeMatrix2d,class AcGeVector2d)'''
    ...
    def setToSum (self, *args, **kwargs):
      '''
setToSum( (Vector2d)arg1, (Vector2d)arg2, (Vector2d)arg3) -> Vector2d :

    C++ signature :
        class AcGeVector2d {lvalue} setToSum(class AcGeVector2d {lvalue},class AcGeVector2d,class AcGeVector2d)'''
    ...
    def toString (self, *args, **kwargs):
      '''
toString( (Vector2d)arg1) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > toString(class AcGeVector2d)'''
    ...
    def transformBy (self, *args, **kwargs):
      '''
transformBy( (Vector2d)arg1, (Matrix2d)arg2) -> Vector2d :

    C++ signature :
        class AcGeVector2d {lvalue} transformBy(class AcGeVector2d {lvalue},class AcGeMatrix2d)'''
    ...
    def x (self, *args, **kwargs):
      '''None'''
    ...
    def y (self, *args, **kwargs):
      '''None'''
    ...

class Vector3d:
    def __add__ (self, *args, **kwargs):
      '''
__add__( (Vector3d)arg1, (Vector3d)arg2) -> Vector3d :

    C++ signature :
        class AcGeVector3d __add__(class AcGeVector3d {lvalue},class AcGeVector3d)'''
    ...
    def __eq__ (self, *args, **kwargs):
      '''
__eq__( (Vector3d)arg1, (Vector3d)arg2) -> bool :

    C++ signature :
        bool __eq__(class AcGeVector3d {lvalue},class AcGeVector3d)'''
    ...
    def __iadd__ (self, *args, **kwargs):
      '''
__iadd__( (Vector3d)arg1, (Vector3d)arg2) -> Vector3d :

    C++ signature :
        class AcGeVector3d {lvalue} __iadd__(class AcGeVector3d {lvalue},class AcGeVector3d)'''
    ...
    def __imul__ (self, *args, **kwargs):
      '''
__imul__( (Vector3d)arg1, (float)arg2) -> Vector3d :

    C++ signature :
        class AcGeVector3d {lvalue} __imul__(class AcGeVector3d {lvalue},double)'''
    ...
    def __init__ (self, *args, **kwargs):
      '''
__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1, (Vector3d)arg2) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class AcGeVector3d)

__init__( (object)arg1, (float)arg2, (float)arg3, (float)arg4) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,double,double,double)

__init__( (object)arg1, (object)arg2, (Vector2d)arg3) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class AcGePlanarEnt,class AcGeVector2d)'''
    ...
    def __isub__ (self, *args, **kwargs):
      '''
__isub__( (Vector3d)arg1, (Vector3d)arg2) -> Vector3d :

    C++ signature :
        class AcGeVector3d {lvalue} __isub__(class AcGeVector3d {lvalue},class AcGeVector3d)'''
    ...
    def __itruediv__ (self, *args, **kwargs):
      '''
__itruediv__( (Vector3d)arg1, (float)arg2) -> Vector3d :

    C++ signature :
        class AcGeVector3d {lvalue} __itruediv__(class AcGeVector3d {lvalue},double)'''
    ...
    def __matmul__ (self, *args, **kwargs):
      '''
__matmul__( (Matrix3d)arg1, (Point3d)arg2) -> Point3d :

    C++ signature :
        class AcGePoint3d __matmul__(class AcGeMatrix3d,class AcGePoint3d)'''
    ...
    def __mul__ (self, *args, **kwargs):
      '''
__mul__( (Vector3d)arg1, (float)arg2) -> Vector3d :

    C++ signature :
        class AcGeVector3d __mul__(class AcGeVector3d {lvalue},double)

__mul__( (float)arg1, (Point3d)arg2) -> Point3d :

    C++ signature :
        class AcGePoint3d __mul__(double,class AcGePoint3d)

__mul__( (Matrix3d)arg1, (Point3d)arg2) -> Point3d :

    C++ signature :
        class AcGePoint3d __mul__(class AcGeMatrix3d,class AcGePoint3d)'''
    ...
    def __ne__ (self, *args, **kwargs):
      '''
__ne__( (Vector3d)arg1, (Vector3d)arg2) -> bool :

    C++ signature :
        bool __ne__(class AcGeVector3d {lvalue},class AcGeVector3d)'''
    ...
    def __sub__ (self, *args, **kwargs):
      '''
__sub__( (Vector3d)arg1, (Vector3d)arg2) -> Vector3d :

    C++ signature :
        class AcGeVector3d __sub__(class AcGeVector3d {lvalue},class AcGeVector3d)'''
    ...
    def __truediv__ (self, *args, **kwargs):
      '''
__truediv__( (Vector3d)arg1, (float)arg2) -> Vector3d :

    C++ signature :
        class AcGeVector3d __truediv__(class AcGeVector3d {lvalue},double)'''
    ...
    def angleOnPlane (self, *args, **kwargs):
      '''
angleOnPlane( (Vector3d)arg1, (object)arg2) -> float :

    C++ signature :
        double angleOnPlane(class AcGeVector3d {lvalue},class AcGePlanarEnt)'''
    ...
    def angleTo (self, *args, **kwargs):
      '''
angleTo( (Vector3d)arg1, (Vector3d)arg2) -> float :

    C++ signature :
        double angleTo(class AcGeVector3d {lvalue},class AcGeVector3d)

angleTo( (Vector3d)arg1, (Vector3d)arg2, (Vector3d)arg3) -> float :

    C++ signature :
        double angleTo(class AcGeVector3d {lvalue},class AcGeVector3d,class AcGeVector3d)'''
    ...
    def convert2d (self, *args, **kwargs):
      '''
convert2d( (Vector3d)arg1, (object)arg2) -> Vector2d :

    C++ signature :
        class AcGeVector2d convert2d(class AcGeVector3d {lvalue},class AcGePlanarEnt)'''
    ...
    def crossProduct (self, *args, **kwargs):
      '''
crossProduct( (Vector3d)arg1, (Vector3d)arg2) -> Vector3d :

    C++ signature :
        class AcGeVector3d crossProduct(class AcGeVector3d {lvalue},class AcGeVector3d)'''
    ...
    def dotProduct (self, *args, **kwargs):
      '''
dotProduct( (Vector3d)arg1, (Vector3d)arg2) -> float :

    C++ signature :
        double dotProduct(class AcGeVector3d {lvalue},class AcGeVector3d)'''
    ...
    def isCodirectionalTo (self, *args, **kwargs):
      '''
isCodirectionalTo( (Vector3d)arg1, (Vector3d)arg2 [, (Tol)AcGeTol=<PyGe.Tol object at 0x0000020CE5B19750>]) -> bool :

    C++ signature :
        bool isCodirectionalTo(class AcGeVector3d {lvalue},class AcGeVector3d [,class AcGeTol=<PyGe.Tol object at 0x0000020CE5B19750>])'''
    ...
    def isEqualTo (self, *args, **kwargs):
      '''
isEqualTo( (Vector3d)arg1, (Vector3d)arg2 [, (Tol)AcGeTol=<PyGe.Tol object at 0x0000020CE5B19870>]) -> bool :

    C++ signature :
        bool isEqualTo(class AcGeVector3d {lvalue},class AcGeVector3d [,class AcGeTol=<PyGe.Tol object at 0x0000020CE5B19870>])'''
    ...
    def isParallelTo (self, *args, **kwargs):
      '''
isParallelTo( (Vector3d)arg1, (Vector3d)arg2 [, (Tol)AcGeTol=<PyGe.Tol object at 0x0000020CE5B196C0>]) -> bool :

    C++ signature :
        bool isParallelTo(class AcGeVector3d {lvalue},class AcGeVector3d [,class AcGeTol=<PyGe.Tol object at 0x0000020CE5B196C0>])'''
    ...
    def isPerpendicularTo (self, *args, **kwargs):
      '''
isPerpendicularTo( (Vector3d)arg1, (Vector3d)arg2 [, (Tol)AcGeTol=<PyGe.Tol object at 0x0000020CE5B197E0>]) -> bool :

    C++ signature :
        bool isPerpendicularTo(class AcGeVector3d {lvalue},class AcGeVector3d [,class AcGeTol=<PyGe.Tol object at 0x0000020CE5B197E0>])'''
    ...
    def isUnitLength (self, *args, **kwargs):
      '''
isUnitLength( (Vector3d)arg1 [, (Tol)AcGeTol=<PyGe.Tol object at 0x0000020CE5B195A0>]) -> bool :

    C++ signature :
        bool isUnitLength(class AcGeVector3d {lvalue} [,class AcGeTol=<PyGe.Tol object at 0x0000020CE5B195A0>])'''
    ...
    def isZeroLength (self, *args, **kwargs):
      '''
isZeroLength( (Vector3d)arg1 [, (Tol)AcGeTol=<PyGe.Tol object at 0x0000020CE5B19630>]) -> bool :

    C++ signature :
        bool isZeroLength(class AcGeVector3d {lvalue} [,class AcGeTol=<PyGe.Tol object at 0x0000020CE5B19630>])'''
    ...
    def kIdentity (self, *args, **kwargs):
      '''None'''
    ...
    def kXAxis (self, *args, **kwargs):
      '''None'''
    ...
    def kYAxis (self, *args, **kwargs):
      '''None'''
    ...
    def kZAxis (self, *args, **kwargs):
      '''None'''
    ...
    def largestElement (self, *args, **kwargs):
      '''
largestElement( (Vector3d)arg1) -> int :

    C++ signature :
        unsigned int largestElement(class AcGeVector3d {lvalue})'''
    ...
    def length (self, *args, **kwargs):
      '''
length( (Vector3d)arg1) -> float :

    C++ signature :
        double length(class AcGeVector3d {lvalue})'''
    ...
    def lengthSqrd (self, *args, **kwargs):
      '''
lengthSqrd( (Vector3d)arg1) -> float :

    C++ signature :
        double lengthSqrd(class AcGeVector3d {lvalue})'''
    ...
    def mirror (self, *args, **kwargs):
      '''
mirror( (Vector3d)arg1, (Vector3d)arg2) -> Vector3d :

    C++ signature :
        class AcGeVector3d {lvalue} mirror(class AcGeVector3d {lvalue},class AcGeVector3d)'''
    ...
    def negate (self, *args, **kwargs):
      '''
negate( (Vector3d)arg1) -> Vector3d :

    C++ signature :
        class AcGeVector3d {lvalue} negate(class AcGeVector3d {lvalue})'''
    ...
    def normal (self, *args, **kwargs):
      '''
normal( (Vector3d)arg1 [, (Tol)AcGeTol=<PyGe.Tol object at 0x0000020CE5B19510>]) -> Vector3d :

    C++ signature :
        class AcGeVector3d normal(class AcGeVector3d {lvalue} [,class AcGeTol=<PyGe.Tol object at 0x0000020CE5B19510>])'''
    ...
    def normalize (self, *args, **kwargs):
      '''
normalize( (Vector3d)arg1, (Tol)arg2) -> Vector3d :

    C++ signature :
        class AcGeVector3d {lvalue} normalize(class AcGeVector3d {lvalue},class AcGeTol)

normalize( (Vector3d)arg1, (Tol)arg2, (AcGeError)arg3) -> Vector3d :

    C++ signature :
        class AcGeVector3d {lvalue} normalize(class AcGeVector3d {lvalue},class AcGeTol,enum AcGe::ErrorCondition {lvalue})'''
    ...
    def orthoProject (self, *args, **kwargs):
      '''
orthoProject( (Vector3d)arg1, (Vector3d)arg2) -> Vector3d :

    C++ signature :
        class AcGeVector3d orthoProject(class AcGeVector3d {lvalue},class AcGeVector3d)

orthoProject( (Vector3d)arg1, (Vector3d)arg2, (Tol)arg3, (AcGeError)arg4) -> Vector3d :

    C++ signature :
        class AcGeVector3d orthoProject(class AcGeVector3d {lvalue},class AcGeVector3d,class AcGeTol,enum AcGe::ErrorCondition {lvalue})'''
    ...
    def perpVector (self, *args, **kwargs):
      '''
perpVector( (Vector3d)arg1) -> Vector3d :

    C++ signature :
        class AcGeVector3d perpVector(class AcGeVector3d {lvalue})'''
    ...
    def project (self, *args, **kwargs):
      '''
project( (Vector3d)arg1, (Vector3d)arg2, (Vector3d)arg3) -> Vector3d :

    C++ signature :
        class AcGeVector3d project(class AcGeVector3d {lvalue},class AcGeVector3d,class AcGeVector3d)

project( (Vector3d)arg1, (Vector3d)arg2, (Vector3d)arg3, (Tol)arg4, (AcGeError)arg5) -> Vector3d :

    C++ signature :
        class AcGeVector3d project(class AcGeVector3d {lvalue},class AcGeVector3d,class AcGeVector3d,class AcGeTol,enum AcGe::ErrorCondition {lvalue})'''
    ...
    def rotateBy (self, *args, **kwargs):
      '''
rotateBy( (Vector3d)arg1, (float)arg2, (Vector3d)arg3) -> Vector3d :

    C++ signature :
        class AcGeVector3d {lvalue} rotateBy(class AcGeVector3d {lvalue},double,class AcGeVector3d)'''
    ...
    def rotateTo (self, *args, **kwargs):
      '''
rotateTo( (Vector3d)arg1, (Vector3d)arg2, (Vector3d)arg3) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d rotateTo(class AcGeVector3d {lvalue},class AcGeVector3d,class AcGeVector3d)'''
    ...
    def set (self, *args, **kwargs):
      '''
set( (Vector3d)arg1, (float)arg2, (float)arg3, (float)arg4) -> Vector3d :

    C++ signature :
        class AcGeVector3d {lvalue} set(class AcGeVector3d {lvalue},double,double,double)

set( (Vector3d)arg1, (object)arg2, (Vector2d)arg3) -> Vector3d :

    C++ signature :
        class AcGeVector3d {lvalue} set(class AcGeVector3d {lvalue},class AcGePlanarEnt,class AcGeVector2d)'''
    ...
    def setToProduct (self, *args, **kwargs):
      '''
setToProduct( (Vector3d)arg1, (Vector3d)arg2, (float)arg3) -> Vector3d :

    C++ signature :
        class AcGeVector3d {lvalue} setToProduct(class AcGeVector3d {lvalue},class AcGeVector3d,double)

setToProduct( (Vector3d)arg1, (Matrix3d)arg2, (Vector3d)arg3) -> Vector3d :

    C++ signature :
        class AcGeVector3d {lvalue} setToProduct(class AcGeVector3d {lvalue},class AcGeMatrix3d,class AcGeVector3d)'''
    ...
    def setToSum (self, *args, **kwargs):
      '''
setToSum( (Vector3d)arg1, (Vector3d)arg2, (Vector3d)arg3) -> Vector3d :

    C++ signature :
        class AcGeVector3d {lvalue} setToSum(class AcGeVector3d {lvalue},class AcGeVector3d,class AcGeVector3d)'''
    ...
    def toString (self, *args, **kwargs):
      '''
toString( (Vector3d)arg1) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > toString(class AcGeVector3d)'''
    ...
    def transformBy (self, *args, **kwargs):
      '''
transformBy( (Vector3d)arg1, (Matrix3d)arg2) -> Vector3d :

    C++ signature :
        class AcGeVector3d {lvalue} transformBy(class AcGeVector3d {lvalue},class AcGeMatrix3d)'''
    ...
    def x (self, *args, **kwargs):
      '''None'''
    ...
    def y (self, *args, **kwargs):
      '''None'''
    ...
    def z (self, *args, **kwargs):
      '''None'''
    ...

class __loader__:
    def _ORIGIN (self, *args, **kwargs):
      '''str(object='') -> str
str(bytes_or_buffer[, encoding[, errors]]) -> str

Create a new string object from the given object. If encoding or
errors is specified, then the object must expose a data buffer
that will be decoded using the given encoding and error handler.
Otherwise, returns the result of object.__str__() (if defined)
or repr(object).
encoding defaults to sys.getdefaultencoding().
errors defaults to 'strict'.'''
    ...
    def __eq__ (self, value, /):
      '''Return self==value.'''
    ...
    def __init__ (self, /, *args, **kwargs):
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
    def __ne__ (self, value, /):
      '''Return self!=value.'''
    ...
    def create_module (spec):
      '''Create a built-in module'''
    ...
    def exec_module (module):
      '''Exec a built-in module'''
    ...
    def find_module (fullname, path=None):
      '''Find the built-in module.

        If 'path' is ever specified then the search is considered a failure.

        This method is deprecated.  Use find_spec() instead.

        '''
    ...
    def find_spec (fullname, path=None, target=None):
      '''None'''
    ...
    def get_code (fullname):
      '''Return None as built-in modules do not have code objects.'''
    ...
    def get_source (fullname):
      '''Return None as built-in modules do not have source code.'''
    ...
    def is_package (fullname):
      '''Return False as built-in modules are never packages.'''
    ...
    def load_module (fullname):
      '''Load the specified module into sys.modules and return it.

    This method is deprecated.  Use loader.exec_module() instead.

    '''
    ...
    def module_repr (module):
      '''Return repr for the module.

        The method is deprecated.  The import machinery does the job itself.

        '''
    ...
