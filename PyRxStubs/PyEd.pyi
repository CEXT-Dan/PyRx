
class CursorType:
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
    def kCrosshair (self, *args, **kwargs):
      '''None'''
    ...
    def kCrosshairDashed (self, *args, **kwargs):
      '''None'''
    ...
    def kCrosshairNoRotate (self, *args, **kwargs):
      '''None'''
    ...
    def kEntitySelect (self, *args, **kwargs):
      '''None'''
    ...
    def kEntitySelectNoPersp (self, *args, **kwargs):
      '''None'''
    ...
    def kInvisible (self, *args, **kwargs):
      '''None'''
    ...
    def kNoSpecialCursor (self, *args, **kwargs):
      '''None'''
    ...
    def kNotRotated (self, *args, **kwargs):
      '''None'''
    ...
    def kParallelogram (self, *args, **kwargs):
      '''None'''
    ...
    def kPkfirstOrGrips (self, *args, **kwargs):
      '''None'''
    ...
    def kRectCursor (self, *args, **kwargs):
      '''None'''
    ...
    def kRotatedCrosshair (self, *args, **kwargs):
      '''None'''
    ...
    def kRubberBand (self, *args, **kwargs):
      '''None'''
    ...
    def kTargetBox (self, *args, **kwargs):
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

class DragStatus:
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
    def eNormal (self, *args, **kwargs):
      '''None'''
    ...
    def eOk (self, *args, **kwargs):
      '''None'''
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
    def kCancel (self, *args, **kwargs):
      '''None'''
    ...
    def kKW1 (self, *args, **kwargs):
      '''None'''
    ...
    def kKW2 (self, *args, **kwargs):
      '''None'''
    ...
    def kKW3 (self, *args, **kwargs):
      '''None'''
    ...
    def kKW4 (self, *args, **kwargs):
      '''None'''
    ...
    def kKW5 (self, *args, **kwargs):
      '''None'''
    ...
    def kKW6 (self, *args, **kwargs):
      '''None'''
    ...
    def kKW7 (self, *args, **kwargs):
      '''None'''
    ...
    def kKW8 (self, *args, **kwargs):
      '''None'''
    ...
    def kKW9 (self, *args, **kwargs):
      '''None'''
    ...
    def kModeless (self, *args, **kwargs):
      '''None'''
    ...
    def kNoChange (self, *args, **kwargs):
      '''None'''
    ...
    def kNormal (self, *args, **kwargs):
      '''None'''
    ...
    def kNull (self, *args, **kwargs):
      '''None'''
    ...
    def kOther (self, *args, **kwargs):
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

class DragStyle:
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
        void __init__(struct _object * __ptr64)

__init__( (object)arg1, (DragStyleType)arg2, (DragStyleType)arg3) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,enum AcEdDragStyle::StyleType,enum AcEdDragStyle::StyleType)'''
    ...
    def __ne__ (self, value, /):
      '''Return self!=value.'''
    ...
    def setStyleTypeForDragged (self, *args, **kwargs):
      '''
setStyleTypeForDragged( (DragStyle)arg1, (DragStyleType)arg2) -> ErrorStatus :

    C++ signature :
        enum Acad::ErrorStatus setStyleTypeForDragged(class AcEdDragStyle {lvalue},enum AcEdDragStyle::StyleType)'''
    ...
    def setStyleTypeForOriginal (self, *args, **kwargs):
      '''
setStyleTypeForOriginal( (DragStyle)arg1, (DragStyleType)arg2) -> ErrorStatus :

    C++ signature :
        enum Acad::ErrorStatus setStyleTypeForOriginal(class AcEdDragStyle {lvalue},enum AcEdDragStyle::StyleType)'''
    ...
    def styleTypeForDragged (self, *args, **kwargs):
      '''
styleTypeForDragged( (DragStyle)arg1) -> DragStyleType :

    C++ signature :
        enum AcEdDragStyle::StyleType styleTypeForDragged(class AcEdDragStyle {lvalue})'''
    ...
    def styleTypeForOriginal (self, *args, **kwargs):
      '''
styleTypeForOriginal( (DragStyle)arg1) -> DragStyleType :

    C++ signature :
        enum AcEdDragStyle::StyleType styleTypeForOriginal(class AcEdDragStyle {lvalue})'''
    ...

class DragStyleType:
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
    def kDeletedEffect (self, *args, **kwargs):
      '''None'''
    ...
    def kHide (self, *args, **kwargs):
      '''None'''
    ...
    def kHighlight (self, *args, **kwargs):
      '''None'''
    ...
    def kNone (self, *args, **kwargs):
      '''None'''
    ...
    def kNotSet (self, *args, **kwargs):
      '''None'''
    ...
    def kTransparent25 (self, *args, **kwargs):
      '''None'''
    ...
    def kTransparent75 (self, *args, **kwargs):
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

class DrawJig:
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
    def acquireAngle (self, *args, **kwargs):
      '''
acquireAngle( (DrawJig)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple acquireAngle(class PyDrawJig {lvalue})

acquireAngle( (DrawJig)arg1, (Point3d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple acquireAngle(class PyDrawJig {lvalue},class AcGePoint3d)'''
    ...
    def acquireDist (self, *args, **kwargs):
      '''
acquireDist( (DrawJig)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple acquireDist(class PyDrawJig {lvalue})

acquireDist( (DrawJig)arg1, (Point3d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple acquireDist(class PyDrawJig {lvalue},class AcGePoint3d)'''
    ...
    def acquirePoint (self, *args, **kwargs):
      '''
acquirePoint( (DrawJig)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple acquirePoint(class PyDrawJig {lvalue})

acquirePoint( (DrawJig)arg1, (Point3d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple acquirePoint(class PyDrawJig {lvalue},class AcGePoint3d)'''
    ...
    def acquireString (self, *args, **kwargs):
      '''
acquireString( (DrawJig)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple acquireString(class PyDrawJig {lvalue})'''
    ...
    def className (self, *args, **kwargs):
      '''
className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def dispPrompt (self, *args, **kwargs):
      '''
dispPrompt( (DrawJig)arg1) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > dispPrompt(class PyDrawJig {lvalue})'''
    ...
    def drag (self, *args, **kwargs):
      '''
drag( (DrawJig)arg1) -> DragStatus :

    C++ signature :
        enum AcEdJig::DragStatus drag(class PyDrawJig {lvalue})

drag( (DrawJig)arg1, (DragStyle)arg2) -> DragStatus :

    C++ signature :
        enum AcEdJig::DragStatus drag(class PyDrawJig {lvalue},class AcEdDragStyle)'''
    ...
    def keywordList (self, *args, **kwargs):
      '''
keywordList( (DrawJig)arg1) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > keywordList(class PyDrawJig {lvalue})'''
    ...
    def sampler (self, *args, **kwargs):
      '''
sampler( (DrawJig)arg1) -> DragStatus :

    C++ signature :
        enum AcEdJig::DragStatus sampler(class PyDrawJig {lvalue})'''
    ...
    def setDispPrompt (self, *args, **kwargs):
      '''
setDispPrompt( (DrawJig)arg1, (str)arg2) -> None :

    C++ signature :
        void setDispPrompt(class PyDrawJig {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def setKeywordList (self, *args, **kwargs):
      '''
setKeywordList( (DrawJig)arg1, (str)arg2) -> None :

    C++ signature :
        void setKeywordList(class PyDrawJig {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def setSpecialCursorType (self, *args, **kwargs):
      '''
setSpecialCursorType( (DrawJig)arg1, (CursorType)arg2) -> None :

    C++ signature :
        void setSpecialCursorType(class PyDrawJig {lvalue},enum AcEdJig::CursorType)'''
    ...
    def setUserInputControls (self, *args, **kwargs):
      '''
setUserInputControls( (DrawJig)arg1, (UserInputControls)arg2) -> None :

    C++ signature :
        void setUserInputControls(class PyDrawJig {lvalue},enum AcEdJig::UserInputControls)'''
    ...
    def specialCursorType (self, *args, **kwargs):
      '''
specialCursorType( (DrawJig)arg1) -> CursorType :

    C++ signature :
        enum AcEdJig::CursorType specialCursorType(class PyDrawJig {lvalue})'''
    ...
    def update (self, *args, **kwargs):
      '''
update( (DrawJig)arg1) -> bool :

    C++ signature :
        bool update(class PyDrawJig {lvalue})'''
    ...
    def userInputControls (self, *args, **kwargs):
      '''
userInputControls( (DrawJig)arg1) -> UserInputControls :

    C++ signature :
        enum AcEdJig::UserInputControls userInputControls(class PyDrawJig {lvalue})'''
    ...
    def viewportDraw (self, *args, **kwargs):
      '''
viewportDraw( (DrawJig)arg1, (ViewportDraw)arg2) -> None :

    C++ signature :
        void viewportDraw(class PyDrawJig {lvalue},class PyGiViewportDraw {lvalue})'''
    ...
    def worldDraw (self, *args, **kwargs):
      '''
worldDraw( (DrawJig)arg1, (WorldDraw)arg2) -> bool :

    C++ signature :
        bool worldDraw(class PyDrawJig {lvalue},class PyGiWorldDraw {lvalue})'''
    ...

class Editor:
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
    def activeViewportId (self, *args, **kwargs):
      '''
activeViewportId( (Editor)arg1) -> ObjectId :

    C++ signature :
        class PyDbObjectId activeViewportId(class PyAcEditor {lvalue})'''
    ...
    def alert (self, *args, **kwargs):
      '''
alert( (Editor)arg1, (str)arg2) -> None :

    C++ signature :
        void alert(class PyAcEditor {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def arxLoad (self, *args, **kwargs):
      '''
arxLoad( (Editor)arg1, (str)arg2) -> bool :

    C++ signature :
        bool arxLoad(class PyAcEditor {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def arxLoaded (self, *args, **kwargs):
      '''
arxLoaded( (Editor)arg1) -> list :

    C++ signature :
        class boost::python::list arxLoaded(class PyAcEditor {lvalue})'''
    ...
    def arxUnload (self, *args, **kwargs):
      '''
arxUnload( (Editor)arg1, (str)arg2) -> bool :

    C++ signature :
        bool arxUnload(class PyAcEditor {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def audit (self, *args, **kwargs):
      '''
audit( (Editor)arg1, (Database)arg2, (bool)arg3, (bool)arg4) -> ErrorStatus :

    C++ signature :
        enum Acad::ErrorStatus audit(class PyAcEditor {lvalue},class PyDbDatabase,bool,bool)'''
    ...
    def className (self, *args, **kwargs):
      '''
className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def cmdS (self, *args, **kwargs):
      '''
cmdS( (Editor)arg1, (list)arg2) -> bool :

    C++ signature :
        bool cmdS(class PyAcEditor {lvalue},class boost::python::list)'''
    ...
    def entSel (self, *args, **kwargs):
      '''
entSel( (Editor)arg1, (str)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple entSel(class PyAcEditor {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def findFile (self, *args, **kwargs):
      '''
findFile( (Editor)arg1, (str)arg2) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > findFile(class PyAcEditor {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def findTrustedFile (self, *args, **kwargs):
      '''
findTrustedFile( (Editor)arg1, (str)arg2) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > findTrustedFile(class PyAcEditor {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def getAngle (self, *args, **kwargs):
      '''
getAngle( (Editor)arg1, (Point3d)arg2, (str)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple getAngle(class PyAcEditor {lvalue},class AcGePoint3d,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def getCurrentUCS (self, *args, **kwargs):
      '''
getCurrentUCS( (Editor)arg1) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d getCurrentUCS(class PyAcEditor {lvalue})'''
    ...
    def getDist (self, *args, **kwargs):
      '''
getDist( (Editor)arg1, (str)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getDist(class PyAcEditor {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)

getDist( (Editor)arg1, (Point3d)arg2, (str)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple getDist(class PyAcEditor {lvalue},class AcGePoint3d,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def getDouble (self, *args, **kwargs):
      '''
getDouble( (Editor)arg1, (str)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getDouble(class PyAcEditor {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def getInteger (self, *args, **kwargs):
      '''
getInteger( (Editor)arg1, (str)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getInteger(class PyAcEditor {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def getKword (self, *args, **kwargs):
      '''
getKword( (Editor)arg1, (str)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getKword(class PyAcEditor {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def getPoint (self, *args, **kwargs):
      '''
getPoint( (Editor)arg1, (str)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getPoint(class PyAcEditor {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)

getPoint( (Editor)arg1, (Point3d)arg2, (str)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple getPoint(class PyAcEditor {lvalue},class AcGePoint3d,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def getReal (self, *args, **kwargs):
      '''
getReal( (Editor)arg1, (str)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getReal(class PyAcEditor {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def getString (self, *args, **kwargs):
      '''
getString( (Editor)arg1, (int)arg2, (str)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple getString(class PyAcEditor {lvalue},int,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def getVar (self, *args, **kwargs):
      '''
getVar( (Editor)arg1, (str)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getVar(class PyAcEditor {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def initGet (self, *args, **kwargs):
      '''
initGet( (Editor)arg1, (int)arg2, (str)arg3) -> PromptStatus :

    C++ signature :
        enum Acad::PromptStatus initGet(class PyAcEditor {lvalue},int,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def select (self, *args, **kwargs):
      '''
select( (Editor)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple select(class PyAcEditor {lvalue})

select( (Editor)arg1, (list)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple select(class PyAcEditor {lvalue},class boost::python::list)

select( (Editor)arg1, (str)arg2, (str)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple select(class PyAcEditor {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)

select( (Editor)arg1, (str)arg2, (str)arg3, (list)arg4) -> tuple :

    C++ signature :
        class boost::python::tuple select(class PyAcEditor {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,class boost::python::list)'''
    ...
    def selectAll (self, *args, **kwargs):
      '''
selectAll( (Editor)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple selectAll(class PyAcEditor {lvalue})

selectAll( (Editor)arg1, (list)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple selectAll(class PyAcEditor {lvalue},class boost::python::list)'''
    ...
    def selectCrossingWindow (self, *args, **kwargs):
      '''
selectCrossingWindow( (Editor)arg1, (Point3d)arg2, (Point3d)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple selectCrossingWindow(class PyAcEditor {lvalue},class AcGePoint3d,class AcGePoint3d)

selectCrossingWindow( (Editor)arg1, (Point3d)arg2, (Point3d)arg3, (list)arg4) -> tuple :

    C++ signature :
        class boost::python::tuple selectCrossingWindow(class PyAcEditor {lvalue},class AcGePoint3d,class AcGePoint3d,class boost::python::list)'''
    ...
    def setCurrentUCS (self, *args, **kwargs):
      '''
setCurrentUCS( (Editor)arg1, (Matrix3d)arg2) -> ErrorStatus :

    C++ signature :
        enum Acad::ErrorStatus setCurrentUCS(class PyAcEditor {lvalue},class AcGeMatrix3d)'''
    ...
    def setVar (self, *args, **kwargs):
      '''
setVar( (Editor)arg1, (str)arg2, (tuple)arg3) -> bool :

    C++ signature :
        bool setVar(class PyAcEditor {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,class boost::python::tuple)'''
    ...

class EditorReactor:
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
    def abortAttach (self, *args, **kwargs):
      '''
abortAttach( (EditorReactor)arg1, (Database)arg2) -> None :

    C++ signature :
        void abortAttach(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue})'''
    ...
    def abortDeepClone (self, *args, **kwargs):
      '''
abortDeepClone( (EditorReactor)arg1, (IdMapping)arg2) -> None :

    C++ signature :
        void abortDeepClone(class PyEditorReactor {lvalue},class PyDbIdMapping {lvalue})'''
    ...
    def abortDxfIn (self, *args, **kwargs):
      '''
abortDxfIn( (EditorReactor)arg1, (Database)arg2) -> None :

    C++ signature :
        void abortDxfIn(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue})'''
    ...
    def abortDxfOut (self, *args, **kwargs):
      '''
abortDxfOut( (EditorReactor)arg1, (Database)arg2) -> None :

    C++ signature :
        void abortDxfOut(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue})'''
    ...
    def abortInsert (self, *args, **kwargs):
      '''
abortInsert( (EditorReactor)arg1, (Database)arg2) -> None :

    C++ signature :
        void abortInsert(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue})'''
    ...
    def abortRestore (self, *args, **kwargs):
      '''
abortRestore( (EditorReactor)arg1, (Database)arg2) -> None :

    C++ signature :
        void abortRestore(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue})'''
    ...
    def abortSave (self, *args, **kwargs):
      '''
abortSave( (EditorReactor)arg1, (Database)arg2) -> None :

    C++ signature :
        void abortSave(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue})'''
    ...
    def abortWblock (self, *args, **kwargs):
      '''
abortWblock( (EditorReactor)arg1, (Database)arg2) -> None :

    C++ signature :
        void abortWblock(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue})'''
    ...
    def addReactor (self, *args, **kwargs):
      '''
addReactor( (EditorReactor)arg1) -> None :

    C++ signature :
        void addReactor(class PyEditorReactor {lvalue})'''
    ...
    def beginAttach (self, *args, **kwargs):
      '''
beginAttach( (EditorReactor)arg1, (Database)arg2, (str)arg3, (Database)arg4) -> None :

    C++ signature :
        void beginAttach(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,class PyDbDatabase {lvalue})'''
    ...
    def beginCloseAll (self, *args, **kwargs):
      '''
beginCloseAll( (EditorReactor)arg1) -> None :

    C++ signature :
        void beginCloseAll(class PyEditorReactor {lvalue})'''
    ...
    def beginDeepClone (self, *args, **kwargs):
      '''
beginDeepClone( (EditorReactor)arg1, (Database)arg2, (IdMapping)arg3) -> None :

    C++ signature :
        void beginDeepClone(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue},class PyDbIdMapping {lvalue})'''
    ...
    def beginDeepCloneXlation (self, *args, **kwargs):
      '''
beginDeepCloneXlation( (EditorReactor)arg1, (IdMapping)arg2) -> ErrorStatus :

    C++ signature :
        enum Acad::ErrorStatus beginDeepCloneXlation(class PyEditorReactor {lvalue},class PyDbIdMapping {lvalue})'''
    ...
    def beginDocClose (self, *args, **kwargs):
      '''
beginDocClose( (EditorReactor)arg1, (Database)arg2) -> None :

    C++ signature :
        void beginDocClose(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue})'''
    ...
    def beginDoubleClick (self, *args, **kwargs):
      '''
beginDoubleClick( (EditorReactor)arg1, (Point3d)arg2) -> None :

    C++ signature :
        void beginDoubleClick(class PyEditorReactor {lvalue},class AcGePoint3d)'''
    ...
    def beginDwgOpen (self, *args, **kwargs):
      '''
beginDwgOpen( (EditorReactor)arg1, (str)arg2) -> None :

    C++ signature :
        void beginDwgOpen(class PyEditorReactor {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def beginDxfIn (self, *args, **kwargs):
      '''
beginDxfIn( (EditorReactor)arg1, (Database)arg2) -> None :

    C++ signature :
        void beginDxfIn(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue})'''
    ...
    def beginDxfOut (self, *args, **kwargs):
      '''
beginDxfOut( (EditorReactor)arg1, (Database)arg2) -> None :

    C++ signature :
        void beginDxfOut(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue})'''
    ...
    def beginInsert (self, *args, **kwargs):
      '''
beginInsert( (EditorReactor)arg1, (Database)arg2, (str)arg3, (Database)arg4) -> None :

    C++ signature :
        void beginInsert(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,class PyDbDatabase {lvalue})

beginInsert( (EditorReactor)arg1, (Database)arg2, (Matrix3d)arg3, (Database)arg4) -> None :

    C++ signature :
        void beginInsert(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue},class AcGeMatrix3d,class PyDbDatabase {lvalue})'''
    ...
    def beginQuit (self, *args, **kwargs):
      '''
beginQuit( (EditorReactor)arg1) -> None :

    C++ signature :
        void beginQuit(class PyEditorReactor {lvalue})'''
    ...
    def beginRestore (self, *args, **kwargs):
      '''
beginRestore( (EditorReactor)arg1, (Database)arg2, (str)arg3, (Database)arg4) -> None :

    C++ signature :
        void beginRestore(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,class PyDbDatabase {lvalue})'''
    ...
    def beginRightClick (self, *args, **kwargs):
      '''
beginRightClick( (EditorReactor)arg1, (Point3d)arg2) -> None :

    C++ signature :
        void beginRightClick(class PyEditorReactor {lvalue},class AcGePoint3d)'''
    ...
    def beginSave (self, *args, **kwargs):
      '''
beginSave( (EditorReactor)arg1, (Database)arg2, (str)arg3) -> None :

    C++ signature :
        void beginSave(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def beginWblock (self, *args, **kwargs):
      '''
beginWblock( (EditorReactor)arg1, (Database)arg2, (Database)arg3, (ObjectId)arg4) -> None :

    C++ signature :
        void beginWblock(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue},class PyDbDatabase {lvalue},class PyDbObjectId {lvalue})'''
    ...
    def beginWblockObjects (self, *args, **kwargs):
      '''
beginWblockObjects( (EditorReactor)arg1, (Database)arg2, (IdMapping)arg3) -> None :

    C++ signature :
        void beginWblockObjects(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue},class PyDbIdMapping {lvalue})'''
    ...
    def cmdIUnkModified (self, *args, **kwargs):
      '''
cmdIUnkModified( (EditorReactor)arg1, (str)arg2) -> None :

    C++ signature :
        void cmdIUnkModified(class PyEditorReactor {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def comandeered (self, *args, **kwargs):
      '''
comandeered( (EditorReactor)arg1, (Database)arg2, (ObjectId)arg3, (Database)arg4) -> None :

    C++ signature :
        void comandeered(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue},class PyDbObjectId {lvalue},class PyDbDatabase {lvalue})'''
    ...
    def commandCancelled (self, *args, **kwargs):
      '''
commandCancelled( (EditorReactor)arg1, (str)arg2) -> None :

    C++ signature :
        void commandCancelled(class PyEditorReactor {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def commandEnded (self, *args, **kwargs):
      '''
commandEnded( (EditorReactor)arg1, (str)arg2) -> None :

    C++ signature :
        void commandEnded(class PyEditorReactor {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def commandFailed (self, *args, **kwargs):
      '''
commandFailed( (EditorReactor)arg1, (str)arg2) -> None :

    C++ signature :
        void commandFailed(class PyEditorReactor {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def commandWillStart (self, *args, **kwargs):
      '''
commandWillStart( (EditorReactor)arg1, (str)arg2) -> None :

    C++ signature :
        void commandWillStart(class PyEditorReactor {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def databaseConstructed (self, *args, **kwargs):
      '''
databaseConstructed( (EditorReactor)arg1, (Database)arg2) -> None :

    C++ signature :
        void databaseConstructed(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue})'''
    ...
    def databaseToBeDestroyed (self, *args, **kwargs):
      '''
databaseToBeDestroyed( (EditorReactor)arg1, (Database)arg2) -> None :

    C++ signature :
        void databaseToBeDestroyed(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue})'''
    ...
    def docCloseAborted (self, *args, **kwargs):
      '''
docCloseAborted( (EditorReactor)arg1, (Database)arg2) -> None :

    C++ signature :
        void docCloseAborted(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue})'''
    ...
    def docCloseWillStart (self, *args, **kwargs):
      '''
docCloseWillStart( (EditorReactor)arg1, (Database)arg2) -> None :

    C++ signature :
        void docCloseWillStart(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue})'''
    ...
    def docFrameMovedOrResized (self, *args, **kwargs):
      '''
docFrameMovedOrResized( (EditorReactor)arg1, (int)arg2, (bool)arg3) -> None :

    C++ signature :
        void docFrameMovedOrResized(class PyEditorReactor {lvalue},__int64,bool)'''
    ...
    def dwgViewResized (self, *args, **kwargs):
      '''
dwgViewResized( (EditorReactor)arg1, (int)arg2) -> None :

    C++ signature :
        void dwgViewResized(class PyEditorReactor {lvalue},__int64)'''
    ...
    def dxfInComplete (self, *args, **kwargs):
      '''
dxfInComplete( (EditorReactor)arg1, (Database)arg2) -> None :

    C++ signature :
        void dxfInComplete(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue})'''
    ...
    def dxfOutComplete (self, *args, **kwargs):
      '''
dxfOutComplete( (EditorReactor)arg1, (Database)arg2) -> None :

    C++ signature :
        void dxfOutComplete(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue})'''
    ...
    def endAttach (self, *args, **kwargs):
      '''
endAttach( (EditorReactor)arg1, (Database)arg2) -> None :

    C++ signature :
        void endAttach(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue})'''
    ...
    def endDeepClone (self, *args, **kwargs):
      '''
endDeepClone( (EditorReactor)arg1, (IdMapping)arg2) -> None :

    C++ signature :
        void endDeepClone(class PyEditorReactor {lvalue},class PyDbIdMapping {lvalue})'''
    ...
    def endDwgOpen (self, *args, **kwargs):
      '''
endDwgOpen( (EditorReactor)arg1, (str)arg2, (Database)arg3) -> None :

    C++ signature :
        void endDwgOpen(class PyEditorReactor {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,class PyDbDatabase {lvalue})'''
    ...
    def endInsert (self, *args, **kwargs):
      '''
endInsert( (EditorReactor)arg1, (Database)arg2) -> None :

    C++ signature :
        void endInsert(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue})'''
    ...
    def endRestore (self, *args, **kwargs):
      '''
endRestore( (EditorReactor)arg1, (Database)arg2) -> None :

    C++ signature :
        void endRestore(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue})'''
    ...
    def endWblock (self, *args, **kwargs):
      '''
endWblock( (EditorReactor)arg1, (Database)arg2) -> None :

    C++ signature :
        void endWblock(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue})'''
    ...
    def fullRegenEnded (self, *args, **kwargs):
      '''
fullRegenEnded( (EditorReactor)arg1, (Database)arg2, (list)arg3) -> None :

    C++ signature :
        void fullRegenEnded(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue},class boost::python::list)'''
    ...
    def fullRegenWillStart (self, *args, **kwargs):
      '''
fullRegenWillStart( (EditorReactor)arg1, (Database)arg2) -> None :

    C++ signature :
        void fullRegenWillStart(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue})'''
    ...
    def initialDwgFileOpenComplete (self, *args, **kwargs):
      '''
initialDwgFileOpenComplete( (EditorReactor)arg1, (Database)arg2) -> None :

    C++ signature :
        void initialDwgFileOpenComplete(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue})'''
    ...
    def layoutSwitched (self, *args, **kwargs):
      '''
layoutSwitched( (EditorReactor)arg1, (str)arg2) -> None :

    C++ signature :
        void layoutSwitched(class PyEditorReactor {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def layoutToBeSwitched (self, *args, **kwargs):
      '''
layoutToBeSwitched( (EditorReactor)arg1, (str)arg2, (str)arg3) -> None :

    C++ signature :
        void layoutToBeSwitched(class PyEditorReactor {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def lispCancelled (self, *args, **kwargs):
      '''
lispCancelled( (EditorReactor)arg1) -> None :

    C++ signature :
        void lispCancelled(class PyEditorReactor {lvalue})'''
    ...
    def lispEnded (self, *args, **kwargs):
      '''
lispEnded( (EditorReactor)arg1) -> None :

    C++ signature :
        void lispEnded(class PyEditorReactor {lvalue})'''
    ...
    def lispWillStart (self, *args, **kwargs):
      '''
lispWillStart( (EditorReactor)arg1, (str)arg2) -> None :

    C++ signature :
        void lispWillStart(class PyEditorReactor {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def mainFrameMovedOrResized (self, *args, **kwargs):
      '''
mainFrameMovedOrResized( (EditorReactor)arg1, (int)arg2, (bool)arg3) -> None :

    C++ signature :
        void mainFrameMovedOrResized(class PyEditorReactor {lvalue},__int64,bool)'''
    ...
    def modelessOperationEnded (self, *args, **kwargs):
      '''
modelessOperationEnded( (EditorReactor)arg1, (str)arg2) -> None :

    C++ signature :
        void modelessOperationEnded(class PyEditorReactor {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def modelessOperationWillStart (self, *args, **kwargs):
      '''
modelessOperationWillStart( (EditorReactor)arg1, (str)arg2) -> None :

    C++ signature :
        void modelessOperationWillStart(class PyEditorReactor {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def objectsLazyLoaded (self, *args, **kwargs):
      '''
objectsLazyLoaded( (EditorReactor)arg1, (list)arg2) -> None :

    C++ signature :
        void objectsLazyLoaded(class PyEditorReactor {lvalue},class boost::python::list)'''
    ...
    def otherAttach (self, *args, **kwargs):
      '''
otherAttach( (EditorReactor)arg1, (Database)arg2, (Database)arg3) -> None :

    C++ signature :
        void otherAttach(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue},class PyDbDatabase {lvalue})'''
    ...
    def otherInsert (self, *args, **kwargs):
      '''
otherInsert( (EditorReactor)arg1, (Database)arg2, (IdMapping)arg3, (Database)arg4) -> None :

    C++ signature :
        void otherInsert(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue},class PyDbIdMapping {lvalue},class PyDbDatabase {lvalue})'''
    ...
    def otherWblock (self, *args, **kwargs):
      '''
otherWblock( (EditorReactor)arg1, (Database)arg2, (IdMapping)arg3, (Database)arg4) -> None :

    C++ signature :
        void otherWblock(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue},class PyDbIdMapping {lvalue},class PyDbDatabase {lvalue})'''
    ...
    def partialOpenNotice (self, *args, **kwargs):
      '''
partialOpenNotice( (EditorReactor)arg1, (Database)arg2) -> None :

    C++ signature :
        void partialOpenNotice(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue})'''
    ...
    def pickfirstModified (self, *args, **kwargs):
      '''
pickfirstModified( (EditorReactor)arg1) -> None :

    C++ signature :
        void pickfirstModified(class PyEditorReactor {lvalue})'''
    ...
    def preXrefLockFile (self, *args, **kwargs):
      '''
preXrefLockFile( (EditorReactor)arg1, (ObjectId)arg2) -> None :

    C++ signature :
        void preXrefLockFile(class PyEditorReactor {lvalue},class PyDbObjectId {lvalue})'''
    ...
    def quitAborted (self, *args, **kwargs):
      '''
quitAborted( (EditorReactor)arg1) -> None :

    C++ signature :
        void quitAborted(class PyEditorReactor {lvalue})'''
    ...
    def quitWillStart (self, *args, **kwargs):
      '''
quitWillStart( (EditorReactor)arg1) -> None :

    C++ signature :
        void quitWillStart(class PyEditorReactor {lvalue})'''
    ...
    def redirected (self, *args, **kwargs):
      '''
redirected( (EditorReactor)arg1, (ObjectId)arg2, (ObjectId)arg3) -> None :

    C++ signature :
        void redirected(class PyEditorReactor {lvalue},class PyDbObjectId {lvalue},class PyDbObjectId {lvalue})'''
    ...
    def removeReactor (self, *args, **kwargs):
      '''
removeReactor( (EditorReactor)arg1) -> None :

    C++ signature :
        void removeReactor(class PyEditorReactor {lvalue})'''
    ...
    def saveComplete (self, *args, **kwargs):
      '''
saveComplete( (EditorReactor)arg1, (Database)arg2, (str)arg3) -> None :

    C++ signature :
        void saveComplete(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def sysVarChanged (self, *args, **kwargs):
      '''
sysVarChanged( (EditorReactor)arg1, (str)arg2, (bool)arg3) -> None :

    C++ signature :
        void sysVarChanged(class PyEditorReactor {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,bool)'''
    ...
    def sysVarWillChange (self, *args, **kwargs):
      '''
sysVarWillChange( (EditorReactor)arg1, (str)arg2) -> None :

    C++ signature :
        void sysVarWillChange(class PyEditorReactor {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def toolbarBitmapSizeChanged (self, *args, **kwargs):
      '''
toolbarBitmapSizeChanged( (EditorReactor)arg1, (bool)arg2) -> None :

    C++ signature :
        void toolbarBitmapSizeChanged(class PyEditorReactor {lvalue},bool)'''
    ...
    def toolbarBitmapSizeWillChange (self, *args, **kwargs):
      '''
toolbarBitmapSizeWillChange( (EditorReactor)arg1, (bool)arg2) -> None :

    C++ signature :
        void toolbarBitmapSizeWillChange(class PyEditorReactor {lvalue},bool)'''
    ...
    def undoSubcommandAuto (self, *args, **kwargs):
      '''
undoSubcommandAuto( (EditorReactor)arg1, (int)arg2, (bool)arg3) -> None :

    C++ signature :
        void undoSubcommandAuto(class PyEditorReactor {lvalue},int,bool)'''
    ...
    def undoSubcommandBack (self, *args, **kwargs):
      '''
undoSubcommandBack( (EditorReactor)arg1, (int)arg2) -> None :

    C++ signature :
        void undoSubcommandBack(class PyEditorReactor {lvalue},int)'''
    ...
    def undoSubcommandBegin (self, *args, **kwargs):
      '''
undoSubcommandBegin( (EditorReactor)arg1, (int)arg2) -> None :

    C++ signature :
        void undoSubcommandBegin(class PyEditorReactor {lvalue},int)'''
    ...
    def undoSubcommandControl (self, *args, **kwargs):
      '''
undoSubcommandControl( (EditorReactor)arg1, (int)arg2, (int)arg3) -> None :

    C++ signature :
        void undoSubcommandControl(class PyEditorReactor {lvalue},int,int)'''
    ...
    def undoSubcommandEnd (self, *args, **kwargs):
      '''
undoSubcommandEnd( (EditorReactor)arg1, (int)arg2) -> None :

    C++ signature :
        void undoSubcommandEnd(class PyEditorReactor {lvalue},int)'''
    ...
    def undoSubcommandMark (self, *args, **kwargs):
      '''
undoSubcommandMark( (EditorReactor)arg1, (int)arg2) -> None :

    C++ signature :
        void undoSubcommandMark(class PyEditorReactor {lvalue},int)'''
    ...
    def undoSubcommandNumber (self, *args, **kwargs):
      '''
undoSubcommandNumber( (EditorReactor)arg1, (int)arg2, (int)arg3) -> None :

    C++ signature :
        void undoSubcommandNumber(class PyEditorReactor {lvalue},int,int)'''
    ...
    def veto (self, *args, **kwargs):
      '''
veto( (EditorReactor)arg1) -> ErrorStatus :

    C++ signature :
        enum Acad::ErrorStatus veto(class PyEditorReactor {lvalue})'''
    ...
    def viewChanged (self, *args, **kwargs):
      '''
viewChanged( (EditorReactor)arg1) -> None :

    C++ signature :
        void viewChanged(class PyEditorReactor {lvalue})'''
    ...
    def wblockNotice (self, *args, **kwargs):
      '''
wblockNotice( (EditorReactor)arg1, (Database)arg2) -> None :

    C++ signature :
        void wblockNotice(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue})'''
    ...
    def xrefSubcommandAttachItem (self, *args, **kwargs):
      '''
xrefSubcommandAttachItem( (EditorReactor)arg1, (Database)arg2, (int)arg3, (str)arg4) -> None :

    C++ signature :
        void xrefSubcommandAttachItem(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue},int,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def xrefSubcommandBindItem (self, *args, **kwargs):
      '''
xrefSubcommandBindItem( (EditorReactor)arg1, (Database)arg2, (int)arg3, (ObjectId)arg4) -> None :

    C++ signature :
        void xrefSubcommandBindItem(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue},int,class PyDbObjectId {lvalue})'''
    ...
    def xrefSubcommandDetachItem (self, *args, **kwargs):
      '''
xrefSubcommandDetachItem( (EditorReactor)arg1, (Database)arg2, (int)arg3, (ObjectId)arg4) -> None :

    C++ signature :
        void xrefSubcommandDetachItem(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue},int,class PyDbObjectId {lvalue})'''
    ...
    def xrefSubcommandOverlayItem (self, *args, **kwargs):
      '''
xrefSubcommandOverlayItem( (EditorReactor)arg1, (Database)arg2, (int)arg3, (str)arg4) -> None :

    C++ signature :
        void xrefSubcommandOverlayItem(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue},int,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def xrefSubcommandPathItem (self, *args, **kwargs):
      '''
xrefSubcommandPathItem( (EditorReactor)arg1, (int)arg2, (ObjectId)arg3, (str)arg4) -> None :

    C++ signature :
        void xrefSubcommandPathItem(class PyEditorReactor {lvalue},int,class PyDbObjectId {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def xrefSubcommandReloadItem (self, *args, **kwargs):
      '''
xrefSubcommandReloadItem( (EditorReactor)arg1, (Database)arg2, (int)arg3, (ObjectId)arg4) -> None :

    C++ signature :
        void xrefSubcommandReloadItem(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue},int,class PyDbObjectId {lvalue})'''
    ...
    def xrefSubcommandUnloadItem (self, *args, **kwargs):
      '''
xrefSubcommandUnloadItem( (EditorReactor)arg1, (Database)arg2, (int)arg3, (ObjectId)arg4) -> None :

    C++ signature :
        void xrefSubcommandUnloadItem(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue},int,class PyDbObjectId {lvalue})'''
    ...

class Jig:
    def __eq__ (self, value, /):
      '''Return self==value.'''
    ...
    def __init__ (self, *args, **kwargs):
      '''
__init__( (object)arg1, (Entity)arg2) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class PyDbEntity)'''
    ...
    def __ne__ (self, value, /):
      '''Return self!=value.'''
    ...
    def acquireAngle (self, *args, **kwargs):
      '''
acquireAngle( (Jig)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple acquireAngle(class PyJig {lvalue})

acquireAngle( (Jig)arg1, (Point3d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple acquireAngle(class PyJig {lvalue},class AcGePoint3d)'''
    ...
    def acquireDist (self, *args, **kwargs):
      '''
acquireDist( (Jig)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple acquireDist(class PyJig {lvalue})

acquireDist( (Jig)arg1, (Point3d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple acquireDist(class PyJig {lvalue},class AcGePoint3d)'''
    ...
    def acquirePoint (self, *args, **kwargs):
      '''
acquirePoint( (Jig)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple acquirePoint(class PyJig {lvalue})

acquirePoint( (Jig)arg1, (Point3d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple acquirePoint(class PyJig {lvalue},class AcGePoint3d)'''
    ...
    def acquireString (self, *args, **kwargs):
      '''
acquireString( (Jig)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple acquireString(class PyJig {lvalue})'''
    ...
    def append (self, *args, **kwargs):
      '''
append( (Jig)arg1) -> ObjectId :

    C++ signature :
        class PyDbObjectId append(class PyJig {lvalue})'''
    ...
    def className (self, *args, **kwargs):
      '''
className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def dispPrompt (self, *args, **kwargs):
      '''
dispPrompt( (Jig)arg1) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > dispPrompt(class PyJig {lvalue})'''
    ...
    def drag (self, *args, **kwargs):
      '''
drag( (Jig)arg1) -> DragStatus :

    C++ signature :
        enum AcEdJig::DragStatus drag(class PyJig {lvalue})

drag( (Jig)arg1, (DragStyle)arg2) -> DragStatus :

    C++ signature :
        enum AcEdJig::DragStatus drag(class PyJig {lvalue},class AcEdDragStyle)'''
    ...
    def keywordList (self, *args, **kwargs):
      '''
keywordList( (Jig)arg1) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > keywordList(class PyJig {lvalue})'''
    ...
    def sampler (self, *args, **kwargs):
      '''
sampler( (Jig)arg1) -> DragStatus :

    C++ signature :
        enum AcEdJig::DragStatus sampler(class PyJig {lvalue})'''
    ...
    def setDispPrompt (self, *args, **kwargs):
      '''
setDispPrompt( (Jig)arg1, (str)arg2) -> None :

    C++ signature :
        void setDispPrompt(class PyJig {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def setKeywordList (self, *args, **kwargs):
      '''
setKeywordList( (Jig)arg1, (str)arg2) -> None :

    C++ signature :
        void setKeywordList(class PyJig {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def setSpecialCursorType (self, *args, **kwargs):
      '''
setSpecialCursorType( (Jig)arg1, (CursorType)arg2) -> None :

    C++ signature :
        void setSpecialCursorType(class PyJig {lvalue},enum AcEdJig::CursorType)'''
    ...
    def setUserInputControls (self, *args, **kwargs):
      '''
setUserInputControls( (Jig)arg1, (UserInputControls)arg2) -> None :

    C++ signature :
        void setUserInputControls(class PyJig {lvalue},enum AcEdJig::UserInputControls)'''
    ...
    def specialCursorType (self, *args, **kwargs):
      '''
specialCursorType( (Jig)arg1) -> CursorType :

    C++ signature :
        enum AcEdJig::CursorType specialCursorType(class PyJig {lvalue})'''
    ...
    def update (self, *args, **kwargs):
      '''
update( (Jig)arg1) -> bool :

    C++ signature :
        bool update(class PyJig {lvalue})'''
    ...
    def userInputControls (self, *args, **kwargs):
      '''
userInputControls( (Jig)arg1) -> UserInputControls :

    C++ signature :
        enum AcEdJig::UserInputControls userInputControls(class PyJig {lvalue})'''
    ...

class PromptStatus:
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
    def eCancel (self, *args, **kwargs):
      '''None'''
    ...
    def eDirect (self, *args, **kwargs):
      '''None'''
    ...
    def eError (self, *args, **kwargs):
      '''None'''
    ...
    def eFailed (self, *args, **kwargs):
      '''None'''
    ...
    def eKeyword (self, *args, **kwargs):
      '''None'''
    ...
    def eModeless (self, *args, **kwargs):
      '''None'''
    ...
    def eNone (self, *args, **kwargs):
      '''None'''
    ...
    def eNormal (self, *args, **kwargs):
      '''None'''
    ...
    def eOk (self, *args, **kwargs):
      '''None'''
    ...
    def eRejected (self, *args, **kwargs):
      '''None'''
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
    def kNormal (self, *args, **kwargs):
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

class UserInputControls:
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
    def kAccept3dCoordinates (self, *args, **kwargs):
      '''None'''
    ...
    def kAcceptMouseUpAsPoint (self, *args, **kwargs):
      '''None'''
    ...
    def kAcceptOtherInputString (self, *args, **kwargs):
      '''None'''
    ...
    def kAnyBlankTerminatesInput (self, *args, **kwargs):
      '''None'''
    ...
    def kDisableDirectDistanceInput (self, *args, **kwargs):
      '''None'''
    ...
    def kDontEchoCancelForCtrlC (self, *args, **kwargs):
      '''None'''
    ...
    def kDontUpdateLastPoint (self, *args, **kwargs):
      '''None'''
    ...
    def kGovernedByOrthoMode (self, *args, **kwargs):
      '''None'''
    ...
    def kGovernedByUCSDetect (self, *args, **kwargs):
      '''None'''
    ...
    def kImpliedFaceForUCSChange (self, *args, **kwargs):
      '''None'''
    ...
    def kInitialBlankTerminatesInput (self, *args, **kwargs):
      '''None'''
    ...
    def kNoDwgLimitsChecking (self, *args, **kwargs):
      '''None'''
    ...
    def kNoNegativeResponseAccepted (self, *args, **kwargs):
      '''None'''
    ...
    def kNoZDirectionOrtho (self, *args, **kwargs):
      '''None'''
    ...
    def kNoZeroResponseAccepted (self, *args, **kwargs):
      '''None'''
    ...
    def kNullResponseAccepted (self, *args, **kwargs):
      '''None'''
    ...
    def kUseBasePointElevation (self, *args, **kwargs):
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
