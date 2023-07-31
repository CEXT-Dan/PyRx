import PyRx
import PyGe
import PyGi
import PyGs
import PyDb
import PyAp
import PyEd

class AcEdDrawOrderCmdType:
    def __init__ (self, /, *args, **kwargs):
      '''Initialize self.  See help(type(self)) for accurate signature.'''
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
    def conjugate (self, *args, **kwargs)-> None:
      '''Returns self, the complex conjugate of any int.'''
    ...
    def denominator (self, *args, **kwargs)-> None:
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
    def imag (self, *args, **kwargs)-> None:
      '''the imaginary part of a complex number'''
    ...
    def kDrawOrderAbove (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kDrawOrderBelow (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kDrawOrderBottom (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kDrawOrderNone (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kDrawOrderTop (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def name (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def names (self, *args, **kwargs)-> new empty dictionary
dict(mapping) -> new dictionary initialized from a mapping object's
    (key, value) pairs
dict(iterable) -> new dictionary initialized as if via:
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
    def numerator (self, *args, **kwargs)-> None:
      '''the numerator of a rational number in lowest terms'''
    ...
    def real (self, *args, **kwargs)-> None:
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
    def values (self, *args, **kwargs)-> new empty dictionary
dict(mapping) -> new dictionary initialized from a mapping object's
    (key, value) pairs
dict(iterable) -> new dictionary initialized as if via:
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

class Core:
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
    ...
    def alert (self, *args, **kwargs)-> int :
      '''alert( (str)arg1) -> int :

    C++ signature :
        int alert(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def arxLoad (self, *args, **kwargs)-> int :
      '''arxLoad( (str)arg1) -> int :

    C++ signature :
        int arxLoad(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def arxLoaded (self, *args, **kwargs)-> list :
      '''arxLoaded() -> list :

    C++ signature :
        class boost::python::list arxLoaded()'''
    ...
    def arxUnload (self, *args, **kwargs)-> int :
      '''arxUnload( (str)arg1) -> int :

    C++ signature :
        int arxUnload(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def audit (self, *args, **kwargs)-> None :
      '''audit( (Database)arg1, (bool)arg2) -> None :

    C++ signature :
        void audit(class PyDbDatabase {lvalue},bool)

audit( (Database)arg1, (bool)arg2, (bool)arg3) -> None :

    C++ signature :
        void audit(class PyDbDatabase {lvalue},bool,bool)'''
    ...
    def callBackOnCancel (self, *args, **kwargs)-> None :
      '''callBackOnCancel() -> None :

    C++ signature :
        void callBackOnCancel()'''
    ...
    def clearOLELock (self, *args, **kwargs)-> bool :
      '''clearOLELock( (int)arg1) -> bool :

    C++ signature :
        bool clearOLELock(int)'''
    ...
    def clipFormatName (self, *args, **kwargs)-> str :
      '''clipFormatName() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > clipFormatName()'''
    ...
    def cmdCWasCancelled (self, *args, **kwargs)-> bool :
      '''cmdCWasCancelled() -> bool :

    C++ signature :
        bool cmdCWasCancelled()'''
    ...
    def cmdS (self, *args, **kwargs)-> bool :
      '''cmdS( (list)arg1) -> bool :

    C++ signature :
        bool cmdS(class boost::python::list)'''
    ...
    def cmdUndefine (self, *args, **kwargs)-> int :
      '''cmdUndefine( (str)arg1, (int)arg2) -> int :

    C++ signature :
        int cmdUndefine(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,int)'''
    ...
    def coordFromPixelToWorld (self, *args, **kwargs)-> bool :
      '''coordFromPixelToWorld( (list)arg1, (Point3d)arg2) -> bool :

    C++ signature :
        bool coordFromPixelToWorld(class boost::python::list,class AcGePoint3d {lvalue})

coordFromPixelToWorld( (int)arg1, (list)arg2, (Point3d)arg3) -> bool :

    C++ signature :
        bool coordFromPixelToWorld(int,class boost::python::list,class AcGePoint3d {lvalue})'''
    ...
    def coordFromWorldToPixel (self, *args, **kwargs)-> bool :
      '''coordFromWorldToPixel( (int)arg1, (Point3d)arg2, (list)arg3) -> bool :

    C++ signature :
        bool coordFromWorldToPixel(int,class AcGePoint3d,class boost::python::list {lvalue})'''
    ...
    def createInternetShortcut (self, *args, **kwargs)-> bool :
      '''createInternetShortcut( (str)arg1, (str)arg2) -> bool :

    C++ signature :
        bool createInternetShortcut(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def createViewportByView (self, *args, **kwargs)-> ObjectId :
      '''createViewportByView( (Database)arg1, (ObjectId)arg2, (Point2d)arg3, (float)arg4) -> ObjectId :

    C++ signature :
        class PyDbObjectId createViewportByView(class PyDbDatabase {lvalue},class PyDbObjectId {lvalue},class AcGePoint2d,double)'''
    ...
    def defun (self, *args, **kwargs)-> int :
      '''defun( (str)arg1, (int)arg2) -> int :

    C++ signature :
        int defun(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,int)'''
    ...
    def defunEx (self, *args, **kwargs)-> int :
      '''defunEx( (str)arg1, (str)arg2, (int)arg3) -> int :

    C++ signature :
        int defunEx(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,int)'''
    ...
    def disableDefaultARXExceptionHandler (self, *args, **kwargs)-> None :
      '''disableDefaultARXExceptionHandler( (bool)arg1) -> None :

    C++ signature :
        void disableDefaultARXExceptionHandler(bool)'''
    ...
    def disableUsrbrk (self, *args, **kwargs)-> None :
      '''disableUsrbrk() -> None :

    C++ signature :
        void disableUsrbrk()'''
    ...
    def displayBorder (self, *args, **kwargs)-> bool :
      '''displayBorder( (bool)arg1) -> bool :

    C++ signature :
        bool displayBorder(bool)'''
    ...
    def drawOrderInherit (self, *args, **kwargs)-> None :
      '''drawOrderInherit( (ObjectId)arg1, (list)arg2, (AcEdDrawOrderCmdType)arg3) -> None :

    C++ signature :
        void drawOrderInherit(class PyDbObjectId {lvalue},class boost::python::list,enum AcEdDrawOrderCmdType)'''
    ...
    def drawingStatusBarsVisible (self, *args, **kwargs)-> bool :
      '''drawingStatusBarsVisible() -> bool :

    C++ signature :
        bool drawingStatusBarsVisible()'''
    ...
    def eatCommandThroat (self, *args, **kwargs)-> int :
      '''eatCommandThroat() -> int :

    C++ signature :
        int eatCommandThroat()'''
    ...
    def editMTextInteractive (self, *args, **kwargs)-> int :
      '''editMTextInteractive( (MText)arg1, (bool)arg2, (bool)arg3) -> int :

    C++ signature :
        int editMTextInteractive(class PyDbMText {lvalue},bool,bool)'''
    ...
    def enableUsrbrk (self, *args, **kwargs)-> None :
      '''enableUsrbrk() -> None :

    C++ signature :
        void enableUsrbrk()'''
    ...
    def findFile (self, *args, **kwargs)-> str :
      '''findFile( (str)arg1) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > findFile(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def findTrustedFile (self, *args, **kwargs)-> str :
      '''findTrustedFile( (str)arg1) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > findTrustedFile(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def getCommandPromptString (self, *args, **kwargs)-> str :
      '''getCommandPromptString() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > getCommandPromptString()'''
    ...
    def getFileD (self, *args, **kwargs)-> str :
      '''getFileD( (str)arg1, (str)arg2, (str)arg3, (int)arg4) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > getFileD(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,int)'''
    ...
    def getFileNavDialog (self, *args, **kwargs)-> list :
      '''getFileNavDialog( (str)arg1, (str)arg2, (str)arg3, (str)arg4, (int)arg5) -> list :

    C++ signature :
        class boost::python::list getFileNavDialog(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,int)'''
    ...
    def getPredefinedHatchPatterns (self, *args, **kwargs)-> list :
      '''getPredefinedHatchPatterns() -> list :

    C++ signature :
        class boost::python::list getPredefinedHatchPatterns()'''
    ...
    def getSysVars (self, *args, **kwargs)-> dict :
      '''getSysVars() -> dict :

    C++ signature :
        class boost::python::dict getSysVars()'''
    ...
    def getVar (self, *args, **kwargs)-> object :
      '''getVar( (str)arg1) -> object :

    C++ signature :
        class boost::python::api::object getVar(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def grDraw (self, *args, **kwargs)-> int :
      '''grDraw( (Point3d)arg1, (Point3d)arg2, (int)arg3, (int)arg4) -> int :

    C++ signature :
        int grDraw(class AcGePoint3d,class AcGePoint3d,int,int)'''
    ...
    def invoke (self, *args, **kwargs)-> list :
      '''invoke( (list)arg1) -> list :

    C++ signature :
        class boost::python::list invoke(class boost::python::list)'''
    ...
    def mSpace (self, *args, **kwargs)-> None :
      '''mSpace() -> None :

    C++ signature :
        void mSpace()'''
    ...
    def pSpace (self, *args, **kwargs)-> None :
      '''pSpace() -> None :

    C++ signature :
        void pSpace()'''
    ...
    def setUndoMark (self, *args, **kwargs)-> None :
      '''setUndoMark( (bool)arg1) -> None :

    C++ signature :
        void setUndoMark(bool)'''
    ...
    def setVar (self, *args, **kwargs)-> bool :
      '''setVar( (str)arg1, (object)arg2) -> bool :

    C++ signature :
        bool setVar(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,class boost::python::api::object)'''
    ...
    def showHTMLModalWindow (self, *args, **kwargs)-> bool :
      '''showHTMLModalWindow( (int)arg1, (str)arg2) -> bool :

    C++ signature :
        bool showHTMLModalWindow(unsigned __int64,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)

showHTMLModalWindow( (int)arg1, (str)arg2, (bool)arg3) -> bool :

    C++ signature :
        bool showHTMLModalWindow(unsigned __int64,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,bool)'''
    ...
    def showHTMLModelessWindow (self, *args, **kwargs)-> int :
      '''showHTMLModelessWindow( (int)arg1, (str)arg2) -> int :

    C++ signature :
        unsigned __int64 showHTMLModelessWindow(unsigned __int64,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)

showHTMLModelessWindow( (int)arg1, (str)arg2, (bool)arg3) -> int :

    C++ signature :
        unsigned __int64 showHTMLModelessWindow(unsigned __int64,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,bool)'''
    ...
    def update (self, *args, **kwargs)-> int :
      '''update( (int)arg1, (Point2d)arg2, (Point2d)arg3) -> int :

    C++ signature :
        int update(int,class AcGePoint2d,class AcGePoint2d)'''
    ...
    def updateDisplay (self, *args, **kwargs)-> None :
      '''updateDisplay() -> None :

    C++ signature :
        void updateDisplay()'''
    ...
    def updateDisplayPause (self, *args, **kwargs)-> None :
      '''updateDisplayPause( (bool)arg1) -> None :

    C++ signature :
        void updateDisplayPause(bool)'''
    ...
    def usrBrk (self, *args, **kwargs)-> bool :
      '''usrBrk() -> bool :

    C++ signature :
        bool usrBrk()'''
    ...
    def viewportIdFromNumber (self, *args, **kwargs)-> ObjectId :
      '''viewportIdFromNumber( (int)arg1) -> ObjectId :

    C++ signature :
        class PyDbObjectId viewportIdFromNumber(int)'''
    ...
    def vpLayer (self, *args, **kwargs)-> None :
      '''vpLayer( (ObjectId)arg1, (list)arg2, (VpFreezeOps)arg3) -> None :

    C++ signature :
        void vpLayer(class PyDbObjectId,class boost::python::list,enum AcDb::VpFreezeOps)'''
    ...
    def vportTableRecords2Vports (self, *args, **kwargs)-> None :
      '''vportTableRecords2Vports() -> None :

    C++ signature :
        void vportTableRecords2Vports()'''
    ...
    def vports (self, *args, **kwargs)-> list :
      '''vports() -> list :

    C++ signature :
        class boost::python::list vports()'''
    ...
    def vports2VportTableRecords (self, *args, **kwargs)-> None :
      '''vports2VportTableRecords() -> None :

    C++ signature :
        void vports2VportTableRecords()'''
    ...
    def xrefAttach (self, *args, **kwargs)-> None :
      '''xrefAttach( (str)arg1, (str)arg2) -> None :

    C++ signature :
        void xrefAttach(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)

xrefAttach( (str)arg1, (str)arg2, (ObjectId)arg3, (ObjectId)arg4, (Point3d)arg5, (Scale3d)arg6, (float)arg7, (bool)arg8, (Database)arg9, (str)arg10) -> None :

    C++ signature :
        void xrefAttach(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,class PyDbObjectId {lvalue},class PyDbObjectId {lvalue},class AcGePoint3d {lvalue},class AcGeScale3d {lvalue},double,bool,class PyDbDatabase {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def xrefBind (self, *args, **kwargs)-> None :
      '''xrefBind( (str)arg1) -> None :

    C++ signature :
        void xrefBind(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)

xrefBind( (str)arg1, (bool)arg2, (bool)arg3, (Database)arg4) -> None :

    C++ signature :
        void xrefBind(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,bool,bool,class PyDbDatabase {lvalue})'''
    ...
    def xrefCreateBlockname (self, *args, **kwargs)-> str :
      '''xrefCreateBlockname( (str)arg1) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > xrefCreateBlockname(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def xrefDetach (self, *args, **kwargs)-> None :
      '''xrefDetach( (str)arg1) -> None :

    C++ signature :
        void xrefDetach(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)

xrefDetach( (str)arg1, (bool)arg2, (Database)arg3) -> None :

    C++ signature :
        void xrefDetach(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,bool,class PyDbDatabase {lvalue})'''
    ...
    def xrefNotifyCheckFileChanged (self, *args, **kwargs)-> bool :
      '''xrefNotifyCheckFileChanged( (ObjectId)arg1) -> bool :

    C++ signature :
        bool xrefNotifyCheckFileChanged(class PyDbObjectId)'''
    ...
    def xrefOverlay (self, *args, **kwargs)-> None :
      '''xrefOverlay( (str)arg1, (str)arg2) -> None :

    C++ signature :
        void xrefOverlay(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)

xrefOverlay( (str)arg1, (str)arg2, (ObjectId)arg3, (ObjectId)arg4, (Point3d)arg5, (Scale3d)arg6, (float)arg7, (bool)arg8, (Database)arg9, (str)arg10) -> None :

    C++ signature :
        void xrefOverlay(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,class PyDbObjectId {lvalue},class PyDbObjectId {lvalue},class AcGePoint3d {lvalue},class AcGeScale3d {lvalue},double,bool,class PyDbDatabase {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def xrefReload (self, *args, **kwargs)-> None :
      '''xrefReload( (list)arg1) -> None :

    C++ signature :
        void xrefReload(class boost::python::list)

xrefReload( (list)arg1, (bool)arg2, (Database)arg3) -> None :

    C++ signature :
        void xrefReload(class boost::python::list,bool,class PyDbDatabase {lvalue})

xrefReload( (str)arg1) -> None :

    C++ signature :
        void xrefReload(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)

xrefReload( (str)arg1, (bool)arg2, (Database)arg3) -> None :

    C++ signature :
        void xrefReload(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,bool,class PyDbDatabase {lvalue})'''
    ...
    def xrefResolve (self, *args, **kwargs)-> None :
      '''xrefResolve( (Database)arg1) -> None :

    C++ signature :
        void xrefResolve(class PyDbDatabase {lvalue})

xrefResolve( (Database)arg1, (bool)arg2) -> None :

    C++ signature :
        void xrefResolve(class PyDbDatabase {lvalue},bool)'''
    ...
    def xrefUnload (self, *args, **kwargs)-> None :
      '''xrefUnload( (str)arg1) -> None :

    C++ signature :
        void xrefUnload(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)

xrefUnload( (str)arg1, (bool)arg2, (Database)arg3) -> None :

    C++ signature :
        void xrefUnload(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,bool,class PyDbDatabase {lvalue})'''
    ...
    def xrefXBind (self, *args, **kwargs)-> None :
      '''xrefXBind( (list)arg1) -> None :

    C++ signature :
        void xrefXBind(class boost::python::list)

xrefXBind( (list)arg1, (bool)arg2, (Database)arg3) -> None :

    C++ signature :
        void xrefXBind(class boost::python::list,bool,class PyDbDatabase {lvalue})'''
    ...

class CursorType:
    def __init__ (self, /, *args, **kwargs):
      '''Initialize self.  See help(type(self)) for accurate signature.'''
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
    def conjugate (self, *args, **kwargs)-> None:
      '''Returns self, the complex conjugate of any int.'''
    ...
    def denominator (self, *args, **kwargs)-> None:
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
    def imag (self, *args, **kwargs)-> None:
      '''the imaginary part of a complex number'''
    ...
    def kCrosshair (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kCrosshairDashed (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kCrosshairNoRotate (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kEntitySelect (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kEntitySelectNoPersp (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kInvisible (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kNoSpecialCursor (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kNotRotated (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kParallelogram (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kPkfirstOrGrips (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kRectCursor (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kRotatedCrosshair (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kRubberBand (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kTargetBox (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def name (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def names (self, *args, **kwargs)-> new empty dictionary
dict(mapping) -> new dictionary initialized from a mapping object's
    (key, value) pairs
dict(iterable) -> new dictionary initialized as if via:
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
    def numerator (self, *args, **kwargs)-> None:
      '''the numerator of a rational number in lowest terms'''
    ...
    def real (self, *args, **kwargs)-> None:
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
    def values (self, *args, **kwargs)-> new empty dictionary
dict(mapping) -> new dictionary initialized from a mapping object's
    (key, value) pairs
dict(iterable) -> new dictionary initialized as if via:
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
    def __init__ (self, /, *args, **kwargs):
      '''Initialize self.  See help(type(self)) for accurate signature.'''
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
    def conjugate (self, *args, **kwargs)-> None:
      '''Returns self, the complex conjugate of any int.'''
    ...
    def denominator (self, *args, **kwargs)-> None:
      '''the denominator of a rational number in lowest terms'''
    ...
    def eNormal (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def eOk (self, *args, **kwargs)-> None:
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
    def imag (self, *args, **kwargs)-> None:
      '''the imaginary part of a complex number'''
    ...
    def kCancel (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kKW1 (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kKW2 (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kKW3 (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kKW4 (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kKW5 (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kKW6 (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kKW7 (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kKW8 (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kKW9 (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kModeless (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kNoChange (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kNormal (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kNull (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kOther (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def name (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def names (self, *args, **kwargs)-> new empty dictionary
dict(mapping) -> new dictionary initialized from a mapping object's
    (key, value) pairs
dict(iterable) -> new dictionary initialized as if via:
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
    def numerator (self, *args, **kwargs)-> None:
      '''the numerator of a rational number in lowest terms'''
    ...
    def real (self, *args, **kwargs)-> None:
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
    def values (self, *args, **kwargs)-> new empty dictionary
dict(mapping) -> new dictionary initialized from a mapping object's
    (key, value) pairs
dict(iterable) -> new dictionary initialized as if via:
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
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1, (DragStyleType)arg2, (DragStyleType)arg3) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,enum AcEdDragStyle::StyleType,enum AcEdDragStyle::StyleType)'''
    ...
    def setStyleTypeForDragged (self, *args, **kwargs)-> ErrorStatus :
      '''setStyleTypeForDragged( (DragStyle)arg1, (DragStyleType)arg2) -> ErrorStatus :

    C++ signature :
        enum Acad::ErrorStatus setStyleTypeForDragged(class AcEdDragStyle {lvalue},enum AcEdDragStyle::StyleType)'''
    ...
    def setStyleTypeForOriginal (self, *args, **kwargs)-> ErrorStatus :
      '''setStyleTypeForOriginal( (DragStyle)arg1, (DragStyleType)arg2) -> ErrorStatus :

    C++ signature :
        enum Acad::ErrorStatus setStyleTypeForOriginal(class AcEdDragStyle {lvalue},enum AcEdDragStyle::StyleType)'''
    ...
    def styleTypeForDragged (self, *args, **kwargs)-> DragStyleType :
      '''styleTypeForDragged( (DragStyle)arg1) -> DragStyleType :

    C++ signature :
        enum AcEdDragStyle::StyleType styleTypeForDragged(class AcEdDragStyle {lvalue})'''
    ...
    def styleTypeForOriginal (self, *args, **kwargs)-> DragStyleType :
      '''styleTypeForOriginal( (DragStyle)arg1) -> DragStyleType :

    C++ signature :
        enum AcEdDragStyle::StyleType styleTypeForOriginal(class AcEdDragStyle {lvalue})'''
    ...

class DragStyleType:
    def __init__ (self, /, *args, **kwargs):
      '''Initialize self.  See help(type(self)) for accurate signature.'''
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
    def conjugate (self, *args, **kwargs)-> None:
      '''Returns self, the complex conjugate of any int.'''
    ...
    def denominator (self, *args, **kwargs)-> None:
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
    def imag (self, *args, **kwargs)-> None:
      '''the imaginary part of a complex number'''
    ...
    def kDeletedEffect (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kHide (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kHighlight (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kNone (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kNotSet (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kTransparent25 (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kTransparent75 (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def name (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def names (self, *args, **kwargs)-> new empty dictionary
dict(mapping) -> new dictionary initialized from a mapping object's
    (key, value) pairs
dict(iterable) -> new dictionary initialized as if via:
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
    def numerator (self, *args, **kwargs)-> None:
      '''the numerator of a rational number in lowest terms'''
    ...
    def real (self, *args, **kwargs)-> None:
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
    def values (self, *args, **kwargs)-> new empty dictionary
dict(mapping) -> new dictionary initialized from a mapping object's
    (key, value) pairs
dict(iterable) -> new dictionary initialized as if via:
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
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
    ...
    def acquireAngle (self, *args, **kwargs)-> tuple :
      '''acquireAngle( (DrawJig)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple acquireAngle(class PyDrawJig {lvalue})

acquireAngle( (DrawJig)arg1, (Point3d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple acquireAngle(class PyDrawJig {lvalue},class AcGePoint3d)'''
    ...
    def acquireDist (self, *args, **kwargs)-> tuple :
      '''acquireDist( (DrawJig)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple acquireDist(class PyDrawJig {lvalue})

acquireDist( (DrawJig)arg1, (Point3d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple acquireDist(class PyDrawJig {lvalue},class AcGePoint3d)'''
    ...
    def acquirePoint (self, *args, **kwargs)-> tuple :
      '''acquirePoint( (DrawJig)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple acquirePoint(class PyDrawJig {lvalue})

acquirePoint( (DrawJig)arg1, (Point3d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple acquirePoint(class PyDrawJig {lvalue},class AcGePoint3d)'''
    ...
    def acquireString (self, *args, **kwargs)-> tuple :
      '''acquireString( (DrawJig)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple acquireString(class PyDrawJig {lvalue})'''
    ...
    def className (self, *args, **kwargs)-> str :
      '''className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def dispPrompt (self, *args, **kwargs)-> str :
      '''dispPrompt( (DrawJig)arg1) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > dispPrompt(class PyDrawJig {lvalue})'''
    ...
    def drag (self, *args, **kwargs)-> DragStatus :
      '''drag( (DrawJig)arg1) -> DragStatus :

    C++ signature :
        enum AcEdJig::DragStatus drag(class PyDrawJig {lvalue})

drag( (DrawJig)arg1, (DragStyle)arg2) -> DragStatus :

    C++ signature :
        enum AcEdJig::DragStatus drag(class PyDrawJig {lvalue},class AcEdDragStyle)'''
    ...
    def keywordList (self, *args, **kwargs)-> str :
      '''keywordList( (DrawJig)arg1) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > keywordList(class PyDrawJig {lvalue})'''
    ...
    def sampler (self, *args, **kwargs)-> DragStatus :
      '''sampler( (DrawJig)arg1) -> DragStatus :

    C++ signature :
        enum AcEdJig::DragStatus sampler(class PyDrawJig {lvalue})'''
    ...
    def setDispPrompt (self, *args, **kwargs)-> None :
      '''setDispPrompt( (DrawJig)arg1, (str)arg2) -> None :

    C++ signature :
        void setDispPrompt(class PyDrawJig {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def setKeywordList (self, *args, **kwargs)-> None :
      '''setKeywordList( (DrawJig)arg1, (str)arg2) -> None :

    C++ signature :
        void setKeywordList(class PyDrawJig {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def setSpecialCursorType (self, *args, **kwargs)-> None :
      '''setSpecialCursorType( (DrawJig)arg1, (CursorType)arg2) -> None :

    C++ signature :
        void setSpecialCursorType(class PyDrawJig {lvalue},enum AcEdJig::CursorType)'''
    ...
    def setUserInputControls (self, *args, **kwargs)-> None :
      '''setUserInputControls( (DrawJig)arg1, (UserInputControls)arg2) -> None :

    C++ signature :
        void setUserInputControls(class PyDrawJig {lvalue},enum AcEdJig::UserInputControls)'''
    ...
    def specialCursorType (self, *args, **kwargs)-> CursorType :
      '''specialCursorType( (DrawJig)arg1) -> CursorType :

    C++ signature :
        enum AcEdJig::CursorType specialCursorType(class PyDrawJig {lvalue})'''
    ...
    def update (self, *args, **kwargs)-> bool :
      '''update( (DrawJig)arg1) -> bool :

    C++ signature :
        bool update(class PyDrawJig {lvalue})'''
    ...
    def userInputControls (self, *args, **kwargs)-> UserInputControls :
      '''userInputControls( (DrawJig)arg1) -> UserInputControls :

    C++ signature :
        enum AcEdJig::UserInputControls userInputControls(class PyDrawJig {lvalue})'''
    ...
    def viewportDraw (self, *args, **kwargs)-> None :
      '''viewportDraw( (DrawJig)arg1, (ViewportDraw)arg2) -> None :

    C++ signature :
        void viewportDraw(class PyDrawJig {lvalue},class PyGiViewportDraw {lvalue})'''
    ...
    def worldDraw (self, *args, **kwargs)-> bool :
      '''worldDraw( (DrawJig)arg1, (WorldDraw)arg2) -> bool :

    C++ signature :
        bool worldDraw(class PyDrawJig {lvalue},class PyGiWorldDraw {lvalue})'''
    ...

class Editor:
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
    ...
    def activeViewportId (self, *args, **kwargs)-> ObjectId :
      '''activeViewportId() -> ObjectId :

    C++ signature :
        class PyDbObjectId activeViewportId()'''
    ...
    def className (self, *args, **kwargs)-> str :
      '''className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def curViewportObjectId (self, *args, **kwargs)-> ObjectId :
      '''curViewportObjectId() -> ObjectId :

    C++ signature :
        class PyDbObjectId curViewportObjectId()'''
    ...
    def entSel (prompt:str)-> tuple :
      '''                             '''
    ...
    def getAngle (basePt:PyGe.Point3d,prompt:str)-> tuple :
      '''                             '''
    ...
    def getCorner (basePt:PyGe.Point3d,prompt:str)-> tuple :
      '''                             '''
    ...
    def getCurrentUCS (self, *args, **kwargs)-> Matrix3d :
      '''getCurrentUCS() -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d getCurrentUCS()'''
    ...
    def getDist (basePt:PyGe.Point3d=None,prompt:str)-> tuple :
      '''                             '''
    ...
    def getDouble (prompt:str)-> tuple :
      '''                             '''
    ...
    def getInteger (prompt:str)-> tuple :
      '''                             '''
    ...
    def getKword (keyword:str)-> tuple :
      '''                             '''
    ...
    def getPoint (basePt:PyGe.Point3d=None,prompt:str)-> tuple :
      '''                             '''
    ...
    def getReal (prompt:str)-> tuple :
      '''                             '''
    ...
    def getString (cronly:int,prompt:str)-> tuple :
      '''                             '''
    ...
    def initGet (val:int,keyword:str)-> PromptStatus :
      '''                             '''
    ...
    def nEntSelP (prompt:str,selpt:PyGe.Point3d=None)-> tuple :
      '''                             '''
    ...
    def nEntSelPEx (self, *args, **kwargs)-> tuple :
      '''nEntSelPEx( (str)arg1, (int)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple nEntSelPEx(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,int)

nEntSelPEx( (str)arg1, (Point3d)arg2, (int)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple nEntSelPEx(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,class AcGePoint3d,int)'''
    ...
    def select (filer:list=None)-> tuple :
      '''                             '''
    ...
    def selectAll (filer:list=None)-> tuple :
      '''                             '''
    ...
    def selectFence (points:list[PyGe.Point3d],filer:list=None)-> tuple :
      '''                             '''
    ...
    def selectLast (filer:list=None)-> tuple :
      '''                             '''
    ...
    def selectPrevious (filer:list=None)-> tuple :
      '''                             '''
    ...
    def selectPrompt (addPromt:str,remPromt:str,filer:list=None)-> tuple :
      '''                             '''
    ...
    def selectWindow (pt1:PyGe.Point3d,pt2:PyGe.Point3d,filer:list=None)-> tuple :
      '''                             '''
    ...
    def selectWindowPolygon (points:list[PyGe.Point3d],filer:list=None)-> tuple :
      '''                             '''
    ...
    def setCurrentUCS (ucs:PyGe.Matrix3d)-> None :
      '''                             '''
    ...
    def ssget (mode:str,arg1:any,arg2:any,filer:list=None)-> tuple :
      '''                             '''
    ...
    def traceBoundary (point:PyGe.Point3d,detectIslands : bool)-> list :
      '''                             '''
    ...

class EditorReactor:
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
    ...
    def abortAttach (self, *args, **kwargs)-> None :
      '''abortAttach( (EditorReactor)arg1, (Database)arg2) -> None :

    C++ signature :
        void abortAttach(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue})'''
    ...
    def abortDeepClone (self, *args, **kwargs)-> None :
      '''abortDeepClone( (EditorReactor)arg1, (IdMapping)arg2) -> None :

    C++ signature :
        void abortDeepClone(class PyEditorReactor {lvalue},class PyDbIdMapping {lvalue})'''
    ...
    def abortDxfIn (self, *args, **kwargs)-> None :
      '''abortDxfIn( (EditorReactor)arg1, (Database)arg2) -> None :

    C++ signature :
        void abortDxfIn(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue})'''
    ...
    def abortDxfOut (self, *args, **kwargs)-> None :
      '''abortDxfOut( (EditorReactor)arg1, (Database)arg2) -> None :

    C++ signature :
        void abortDxfOut(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue})'''
    ...
    def abortInsert (self, *args, **kwargs)-> None :
      '''abortInsert( (EditorReactor)arg1, (Database)arg2) -> None :

    C++ signature :
        void abortInsert(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue})'''
    ...
    def abortRestore (self, *args, **kwargs)-> None :
      '''abortRestore( (EditorReactor)arg1, (Database)arg2) -> None :

    C++ signature :
        void abortRestore(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue})'''
    ...
    def abortSave (self, *args, **kwargs)-> None :
      '''abortSave( (EditorReactor)arg1, (Database)arg2) -> None :

    C++ signature :
        void abortSave(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue})'''
    ...
    def abortWblock (self, *args, **kwargs)-> None :
      '''abortWblock( (EditorReactor)arg1, (Database)arg2) -> None :

    C++ signature :
        void abortWblock(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue})'''
    ...
    def addReactor (self, *args, **kwargs)-> None :
      '''addReactor( (EditorReactor)arg1) -> None :

    C++ signature :
        void addReactor(class PyEditorReactor {lvalue})'''
    ...
    def beginAttach (self, *args, **kwargs)-> None :
      '''beginAttach( (EditorReactor)arg1, (Database)arg2, (str)arg3, (Database)arg4) -> None :

    C++ signature :
        void beginAttach(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,class PyDbDatabase {lvalue})'''
    ...
    def beginCloseAll (self, *args, **kwargs)-> None :
      '''beginCloseAll( (EditorReactor)arg1) -> None :

    C++ signature :
        void beginCloseAll(class PyEditorReactor {lvalue})'''
    ...
    def beginDeepClone (self, *args, **kwargs)-> None :
      '''beginDeepClone( (EditorReactor)arg1, (Database)arg2, (IdMapping)arg3) -> None :

    C++ signature :
        void beginDeepClone(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue},class PyDbIdMapping {lvalue})'''
    ...
    def beginDeepCloneXlation (self, *args, **kwargs)-> ErrorStatus :
      '''beginDeepCloneXlation( (EditorReactor)arg1, (IdMapping)arg2) -> ErrorStatus :

    C++ signature :
        enum Acad::ErrorStatus beginDeepCloneXlation(class PyEditorReactor {lvalue},class PyDbIdMapping {lvalue})'''
    ...
    def beginDocClose (self, *args, **kwargs)-> None :
      '''beginDocClose( (EditorReactor)arg1, (Database)arg2) -> None :

    C++ signature :
        void beginDocClose(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue})'''
    ...
    def beginDoubleClick (self, *args, **kwargs)-> None :
      '''beginDoubleClick( (EditorReactor)arg1, (Point3d)arg2) -> None :

    C++ signature :
        void beginDoubleClick(class PyEditorReactor {lvalue},class AcGePoint3d)'''
    ...
    def beginDwgOpen (self, *args, **kwargs)-> None :
      '''beginDwgOpen( (EditorReactor)arg1, (str)arg2) -> None :

    C++ signature :
        void beginDwgOpen(class PyEditorReactor {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def beginDxfIn (self, *args, **kwargs)-> None :
      '''beginDxfIn( (EditorReactor)arg1, (Database)arg2) -> None :

    C++ signature :
        void beginDxfIn(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue})'''
    ...
    def beginDxfOut (self, *args, **kwargs)-> None :
      '''beginDxfOut( (EditorReactor)arg1, (Database)arg2) -> None :

    C++ signature :
        void beginDxfOut(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue})'''
    ...
    def beginInsert (self, *args, **kwargs)-> None :
      '''beginInsert( (EditorReactor)arg1, (Database)arg2, (str)arg3, (Database)arg4) -> None :

    C++ signature :
        void beginInsert(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,class PyDbDatabase {lvalue})

beginInsert( (EditorReactor)arg1, (Database)arg2, (Matrix3d)arg3, (Database)arg4) -> None :

    C++ signature :
        void beginInsert(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue},class AcGeMatrix3d,class PyDbDatabase {lvalue})'''
    ...
    def beginQuit (self, *args, **kwargs)-> None :
      '''beginQuit( (EditorReactor)arg1) -> None :

    C++ signature :
        void beginQuit(class PyEditorReactor {lvalue})'''
    ...
    def beginRestore (self, *args, **kwargs)-> None :
      '''beginRestore( (EditorReactor)arg1, (Database)arg2, (str)arg3, (Database)arg4) -> None :

    C++ signature :
        void beginRestore(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,class PyDbDatabase {lvalue})'''
    ...
    def beginRightClick (self, *args, **kwargs)-> None :
      '''beginRightClick( (EditorReactor)arg1, (Point3d)arg2) -> None :

    C++ signature :
        void beginRightClick(class PyEditorReactor {lvalue},class AcGePoint3d)'''
    ...
    def beginSave (self, *args, **kwargs)-> None :
      '''beginSave( (EditorReactor)arg1, (Database)arg2, (str)arg3) -> None :

    C++ signature :
        void beginSave(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def beginWblock (self, *args, **kwargs)-> None :
      '''beginWblock( (EditorReactor)arg1, (Database)arg2, (Database)arg3, (ObjectId)arg4) -> None :

    C++ signature :
        void beginWblock(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue},class PyDbDatabase {lvalue},class PyDbObjectId {lvalue})'''
    ...
    def beginWblockObjects (self, *args, **kwargs)-> None :
      '''beginWblockObjects( (EditorReactor)arg1, (Database)arg2, (IdMapping)arg3) -> None :

    C++ signature :
        void beginWblockObjects(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue},class PyDbIdMapping {lvalue})'''
    ...
    def cmdIUnkModified (self, *args, **kwargs)-> None :
      '''cmdIUnkModified( (EditorReactor)arg1, (str)arg2) -> None :

    C++ signature :
        void cmdIUnkModified(class PyEditorReactor {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def comandeered (self, *args, **kwargs)-> None :
      '''comandeered( (EditorReactor)arg1, (Database)arg2, (ObjectId)arg3, (Database)arg4) -> None :

    C++ signature :
        void comandeered(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue},class PyDbObjectId {lvalue},class PyDbDatabase {lvalue})'''
    ...
    def commandCancelled (self, *args, **kwargs)-> None :
      '''commandCancelled( (EditorReactor)arg1, (str)arg2) -> None :

    C++ signature :
        void commandCancelled(class PyEditorReactor {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def commandEnded (self, *args, **kwargs)-> None :
      '''commandEnded( (EditorReactor)arg1, (str)arg2) -> None :

    C++ signature :
        void commandEnded(class PyEditorReactor {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def commandFailed (self, *args, **kwargs)-> None :
      '''commandFailed( (EditorReactor)arg1, (str)arg2) -> None :

    C++ signature :
        void commandFailed(class PyEditorReactor {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def commandWillStart (self, *args, **kwargs)-> None :
      '''commandWillStart( (EditorReactor)arg1, (str)arg2) -> None :

    C++ signature :
        void commandWillStart(class PyEditorReactor {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def databaseConstructed (self, *args, **kwargs)-> None :
      '''databaseConstructed( (EditorReactor)arg1, (Database)arg2) -> None :

    C++ signature :
        void databaseConstructed(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue})'''
    ...
    def databaseToBeDestroyed (self, *args, **kwargs)-> None :
      '''databaseToBeDestroyed( (EditorReactor)arg1, (Database)arg2) -> None :

    C++ signature :
        void databaseToBeDestroyed(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue})'''
    ...
    def docCloseAborted (self, *args, **kwargs)-> None :
      '''docCloseAborted( (EditorReactor)arg1, (Database)arg2) -> None :

    C++ signature :
        void docCloseAborted(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue})'''
    ...
    def docCloseWillStart (self, *args, **kwargs)-> None :
      '''docCloseWillStart( (EditorReactor)arg1, (Database)arg2) -> None :

    C++ signature :
        void docCloseWillStart(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue})'''
    ...
    def docFrameMovedOrResized (self, *args, **kwargs)-> None :
      '''docFrameMovedOrResized( (EditorReactor)arg1, (int)arg2, (bool)arg3) -> None :

    C++ signature :
        void docFrameMovedOrResized(class PyEditorReactor {lvalue},__int64,bool)'''
    ...
    def dwgViewResized (self, *args, **kwargs)-> None :
      '''dwgViewResized( (EditorReactor)arg1, (int)arg2) -> None :

    C++ signature :
        void dwgViewResized(class PyEditorReactor {lvalue},__int64)'''
    ...
    def dxfInComplete (self, *args, **kwargs)-> None :
      '''dxfInComplete( (EditorReactor)arg1, (Database)arg2) -> None :

    C++ signature :
        void dxfInComplete(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue})'''
    ...
    def dxfOutComplete (self, *args, **kwargs)-> None :
      '''dxfOutComplete( (EditorReactor)arg1, (Database)arg2) -> None :

    C++ signature :
        void dxfOutComplete(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue})'''
    ...
    def endAttach (self, *args, **kwargs)-> None :
      '''endAttach( (EditorReactor)arg1, (Database)arg2) -> None :

    C++ signature :
        void endAttach(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue})'''
    ...
    def endDeepClone (self, *args, **kwargs)-> None :
      '''endDeepClone( (EditorReactor)arg1, (IdMapping)arg2) -> None :

    C++ signature :
        void endDeepClone(class PyEditorReactor {lvalue},class PyDbIdMapping {lvalue})'''
    ...
    def endDwgOpen (self, *args, **kwargs)-> None :
      '''endDwgOpen( (EditorReactor)arg1, (str)arg2, (Database)arg3) -> None :

    C++ signature :
        void endDwgOpen(class PyEditorReactor {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,class PyDbDatabase {lvalue})'''
    ...
    def endInsert (self, *args, **kwargs)-> None :
      '''endInsert( (EditorReactor)arg1, (Database)arg2) -> None :

    C++ signature :
        void endInsert(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue})'''
    ...
    def endRestore (self, *args, **kwargs)-> None :
      '''endRestore( (EditorReactor)arg1, (Database)arg2) -> None :

    C++ signature :
        void endRestore(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue})'''
    ...
    def endWblock (self, *args, **kwargs)-> None :
      '''endWblock( (EditorReactor)arg1, (Database)arg2) -> None :

    C++ signature :
        void endWblock(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue})'''
    ...
    def fullRegenEnded (self, *args, **kwargs)-> None :
      '''fullRegenEnded( (EditorReactor)arg1, (Database)arg2, (list)arg3) -> None :

    C++ signature :
        void fullRegenEnded(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue},class boost::python::list)'''
    ...
    def fullRegenWillStart (self, *args, **kwargs)-> None :
      '''fullRegenWillStart( (EditorReactor)arg1, (Database)arg2) -> None :

    C++ signature :
        void fullRegenWillStart(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue})'''
    ...
    def initialDwgFileOpenComplete (self, *args, **kwargs)-> None :
      '''initialDwgFileOpenComplete( (EditorReactor)arg1, (Database)arg2) -> None :

    C++ signature :
        void initialDwgFileOpenComplete(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue})'''
    ...
    def layoutSwitched (self, *args, **kwargs)-> None :
      '''layoutSwitched( (EditorReactor)arg1, (str)arg2) -> None :

    C++ signature :
        void layoutSwitched(class PyEditorReactor {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def layoutToBeSwitched (self, *args, **kwargs)-> None :
      '''layoutToBeSwitched( (EditorReactor)arg1, (str)arg2, (str)arg3) -> None :

    C++ signature :
        void layoutToBeSwitched(class PyEditorReactor {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def lispCancelled (self, *args, **kwargs)-> None :
      '''lispCancelled( (EditorReactor)arg1) -> None :

    C++ signature :
        void lispCancelled(class PyEditorReactor {lvalue})'''
    ...
    def lispEnded (self, *args, **kwargs)-> None :
      '''lispEnded( (EditorReactor)arg1) -> None :

    C++ signature :
        void lispEnded(class PyEditorReactor {lvalue})'''
    ...
    def lispWillStart (self, *args, **kwargs)-> None :
      '''lispWillStart( (EditorReactor)arg1, (str)arg2) -> None :

    C++ signature :
        void lispWillStart(class PyEditorReactor {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def mainFrameMovedOrResized (self, *args, **kwargs)-> None :
      '''mainFrameMovedOrResized( (EditorReactor)arg1, (int)arg2, (bool)arg3) -> None :

    C++ signature :
        void mainFrameMovedOrResized(class PyEditorReactor {lvalue},__int64,bool)'''
    ...
    def modelessOperationEnded (self, *args, **kwargs)-> None :
      '''modelessOperationEnded( (EditorReactor)arg1, (str)arg2) -> None :

    C++ signature :
        void modelessOperationEnded(class PyEditorReactor {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def modelessOperationWillStart (self, *args, **kwargs)-> None :
      '''modelessOperationWillStart( (EditorReactor)arg1, (str)arg2) -> None :

    C++ signature :
        void modelessOperationWillStart(class PyEditorReactor {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def objectsLazyLoaded (self, *args, **kwargs)-> None :
      '''objectsLazyLoaded( (EditorReactor)arg1, (list)arg2) -> None :

    C++ signature :
        void objectsLazyLoaded(class PyEditorReactor {lvalue},class boost::python::list)'''
    ...
    def otherAttach (self, *args, **kwargs)-> None :
      '''otherAttach( (EditorReactor)arg1, (Database)arg2, (Database)arg3) -> None :

    C++ signature :
        void otherAttach(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue},class PyDbDatabase {lvalue})'''
    ...
    def otherInsert (self, *args, **kwargs)-> None :
      '''otherInsert( (EditorReactor)arg1, (Database)arg2, (IdMapping)arg3, (Database)arg4) -> None :

    C++ signature :
        void otherInsert(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue},class PyDbIdMapping {lvalue},class PyDbDatabase {lvalue})'''
    ...
    def otherWblock (self, *args, **kwargs)-> None :
      '''otherWblock( (EditorReactor)arg1, (Database)arg2, (IdMapping)arg3, (Database)arg4) -> None :

    C++ signature :
        void otherWblock(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue},class PyDbIdMapping {lvalue},class PyDbDatabase {lvalue})'''
    ...
    def partialOpenNotice (self, *args, **kwargs)-> None :
      '''partialOpenNotice( (EditorReactor)arg1, (Database)arg2) -> None :

    C++ signature :
        void partialOpenNotice(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue})'''
    ...
    def pickfirstModified (self, *args, **kwargs)-> None :
      '''pickfirstModified( (EditorReactor)arg1) -> None :

    C++ signature :
        void pickfirstModified(class PyEditorReactor {lvalue})'''
    ...
    def preXrefLockFile (self, *args, **kwargs)-> None :
      '''preXrefLockFile( (EditorReactor)arg1, (ObjectId)arg2) -> None :

    C++ signature :
        void preXrefLockFile(class PyEditorReactor {lvalue},class PyDbObjectId {lvalue})'''
    ...
    def quitAborted (self, *args, **kwargs)-> None :
      '''quitAborted( (EditorReactor)arg1) -> None :

    C++ signature :
        void quitAborted(class PyEditorReactor {lvalue})'''
    ...
    def quitWillStart (self, *args, **kwargs)-> None :
      '''quitWillStart( (EditorReactor)arg1) -> None :

    C++ signature :
        void quitWillStart(class PyEditorReactor {lvalue})'''
    ...
    def redirected (self, *args, **kwargs)-> None :
      '''redirected( (EditorReactor)arg1, (ObjectId)arg2, (ObjectId)arg3) -> None :

    C++ signature :
        void redirected(class PyEditorReactor {lvalue},class PyDbObjectId {lvalue},class PyDbObjectId {lvalue})'''
    ...
    def removeReactor (self, *args, **kwargs)-> None :
      '''removeReactor( (EditorReactor)arg1) -> None :

    C++ signature :
        void removeReactor(class PyEditorReactor {lvalue})'''
    ...
    def saveComplete (self, *args, **kwargs)-> None :
      '''saveComplete( (EditorReactor)arg1, (Database)arg2, (str)arg3) -> None :

    C++ signature :
        void saveComplete(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def sysVarChanged (self, *args, **kwargs)-> None :
      '''sysVarChanged( (EditorReactor)arg1, (str)arg2, (bool)arg3) -> None :

    C++ signature :
        void sysVarChanged(class PyEditorReactor {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,bool)'''
    ...
    def sysVarWillChange (self, *args, **kwargs)-> None :
      '''sysVarWillChange( (EditorReactor)arg1, (str)arg2) -> None :

    C++ signature :
        void sysVarWillChange(class PyEditorReactor {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def toolbarBitmapSizeChanged (self, *args, **kwargs)-> None :
      '''toolbarBitmapSizeChanged( (EditorReactor)arg1, (bool)arg2) -> None :

    C++ signature :
        void toolbarBitmapSizeChanged(class PyEditorReactor {lvalue},bool)'''
    ...
    def toolbarBitmapSizeWillChange (self, *args, **kwargs)-> None :
      '''toolbarBitmapSizeWillChange( (EditorReactor)arg1, (bool)arg2) -> None :

    C++ signature :
        void toolbarBitmapSizeWillChange(class PyEditorReactor {lvalue},bool)'''
    ...
    def undoSubcommandAuto (self, *args, **kwargs)-> None :
      '''undoSubcommandAuto( (EditorReactor)arg1, (int)arg2, (bool)arg3) -> None :

    C++ signature :
        void undoSubcommandAuto(class PyEditorReactor {lvalue},int,bool)'''
    ...
    def undoSubcommandBack (self, *args, **kwargs)-> None :
      '''undoSubcommandBack( (EditorReactor)arg1, (int)arg2) -> None :

    C++ signature :
        void undoSubcommandBack(class PyEditorReactor {lvalue},int)'''
    ...
    def undoSubcommandBegin (self, *args, **kwargs)-> None :
      '''undoSubcommandBegin( (EditorReactor)arg1, (int)arg2) -> None :

    C++ signature :
        void undoSubcommandBegin(class PyEditorReactor {lvalue},int)'''
    ...
    def undoSubcommandControl (self, *args, **kwargs)-> None :
      '''undoSubcommandControl( (EditorReactor)arg1, (int)arg2, (int)arg3) -> None :

    C++ signature :
        void undoSubcommandControl(class PyEditorReactor {lvalue},int,int)'''
    ...
    def undoSubcommandEnd (self, *args, **kwargs)-> None :
      '''undoSubcommandEnd( (EditorReactor)arg1, (int)arg2) -> None :

    C++ signature :
        void undoSubcommandEnd(class PyEditorReactor {lvalue},int)'''
    ...
    def undoSubcommandMark (self, *args, **kwargs)-> None :
      '''undoSubcommandMark( (EditorReactor)arg1, (int)arg2) -> None :

    C++ signature :
        void undoSubcommandMark(class PyEditorReactor {lvalue},int)'''
    ...
    def undoSubcommandNumber (self, *args, **kwargs)-> None :
      '''undoSubcommandNumber( (EditorReactor)arg1, (int)arg2, (int)arg3) -> None :

    C++ signature :
        void undoSubcommandNumber(class PyEditorReactor {lvalue},int,int)'''
    ...
    def veto (self, *args, **kwargs)-> ErrorStatus :
      '''veto( (EditorReactor)arg1) -> ErrorStatus :

    C++ signature :
        enum Acad::ErrorStatus veto(class PyEditorReactor {lvalue})'''
    ...
    def viewChanged (self, *args, **kwargs)-> None :
      '''viewChanged( (EditorReactor)arg1) -> None :

    C++ signature :
        void viewChanged(class PyEditorReactor {lvalue})'''
    ...
    def wblockNotice (self, *args, **kwargs)-> None :
      '''wblockNotice( (EditorReactor)arg1, (Database)arg2) -> None :

    C++ signature :
        void wblockNotice(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue})'''
    ...
    def xrefSubcommandAttachItem (self, *args, **kwargs)-> None :
      '''xrefSubcommandAttachItem( (EditorReactor)arg1, (Database)arg2, (int)arg3, (str)arg4) -> None :

    C++ signature :
        void xrefSubcommandAttachItem(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue},int,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def xrefSubcommandBindItem (self, *args, **kwargs)-> None :
      '''xrefSubcommandBindItem( (EditorReactor)arg1, (Database)arg2, (int)arg3, (ObjectId)arg4) -> None :

    C++ signature :
        void xrefSubcommandBindItem(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue},int,class PyDbObjectId {lvalue})'''
    ...
    def xrefSubcommandDetachItem (self, *args, **kwargs)-> None :
      '''xrefSubcommandDetachItem( (EditorReactor)arg1, (Database)arg2, (int)arg3, (ObjectId)arg4) -> None :

    C++ signature :
        void xrefSubcommandDetachItem(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue},int,class PyDbObjectId {lvalue})'''
    ...
    def xrefSubcommandOverlayItem (self, *args, **kwargs)-> None :
      '''xrefSubcommandOverlayItem( (EditorReactor)arg1, (Database)arg2, (int)arg3, (str)arg4) -> None :

    C++ signature :
        void xrefSubcommandOverlayItem(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue},int,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def xrefSubcommandPathItem (self, *args, **kwargs)-> None :
      '''xrefSubcommandPathItem( (EditorReactor)arg1, (int)arg2, (ObjectId)arg3, (str)arg4) -> None :

    C++ signature :
        void xrefSubcommandPathItem(class PyEditorReactor {lvalue},int,class PyDbObjectId {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def xrefSubcommandReloadItem (self, *args, **kwargs)-> None :
      '''xrefSubcommandReloadItem( (EditorReactor)arg1, (Database)arg2, (int)arg3, (ObjectId)arg4) -> None :

    C++ signature :
        void xrefSubcommandReloadItem(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue},int,class PyDbObjectId {lvalue})'''
    ...
    def xrefSubcommandUnloadItem (self, *args, **kwargs)-> None :
      '''xrefSubcommandUnloadItem( (EditorReactor)arg1, (Database)arg2, (int)arg3, (ObjectId)arg4) -> None :

    C++ signature :
        void xrefSubcommandUnloadItem(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue},int,class PyDbObjectId {lvalue})'''
    ...

class InputPoint:
    def __init__ (self, *args, **kwargs)-> None:
      '''Raises an exception
This class cannot be instantiated from Python'''
    ...
    def alignmentPaths (self, *args, **kwargs)-> list :
      '''alignmentPaths( (InputPoint)arg1) -> list :

    C++ signature :
        class boost::python::list alignmentPaths(class PyEdInputPoint {lvalue})'''
    ...
    def cartesianSnappedPoint (self, *args, **kwargs)-> Point3d :
      '''cartesianSnappedPoint( (InputPoint)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d cartesianSnappedPoint(class PyEdInputPoint {lvalue})'''
    ...
    def computedPoint (self, *args, **kwargs)-> Point3d :
      '''computedPoint( (InputPoint)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d computedPoint(class PyEdInputPoint {lvalue})'''
    ...
    def document (self, *args, **kwargs)-> Document :
      '''document( (InputPoint)arg1) -> Document :

    C++ signature :
        class PyApDocument document(class PyEdInputPoint {lvalue})'''
    ...
    def drawContext (self, *args, **kwargs)-> ViewportDraw :
      '''drawContext( (InputPoint)arg1) -> ViewportDraw :

    C++ signature :
        class PyGiViewportDraw drawContext(class PyEdInputPoint {lvalue})'''
    ...
    def grippedPoint (self, *args, **kwargs)-> Point3d :
      '''grippedPoint( (InputPoint)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d grippedPoint(class PyEdInputPoint {lvalue})'''
    ...
    def gsSelectionMark (self, *args, **kwargs)-> list :
      '''gsSelectionMark( (InputPoint)arg1) -> list :

    C++ signature :
        class boost::python::list gsSelectionMark(class PyEdInputPoint {lvalue})'''
    ...
    def history (self, *args, **kwargs)-> int :
      '''history( (InputPoint)arg1) -> int :

    C++ signature :
        int history(class PyEdInputPoint {lvalue})'''
    ...
    def keyPointEntities (self, *args, **kwargs)-> list :
      '''keyPointEntities( (InputPoint)arg1) -> list :

    C++ signature :
        class boost::python::list keyPointEntities(class PyEdInputPoint {lvalue})'''
    ...
    def keyPointGsSelectionMark (self, *args, **kwargs)-> list :
      '''keyPointGsSelectionMark( (InputPoint)arg1) -> list :

    C++ signature :
        class boost::python::list keyPointGsSelectionMark(class PyEdInputPoint {lvalue})'''
    ...
    def lastPoint (self, *args, **kwargs)-> Point3d :
      '''lastPoint( (InputPoint)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d lastPoint(class PyEdInputPoint {lvalue})'''
    ...
    def nestedKeyPointEntities (self, *args, **kwargs)-> list :
      '''nestedKeyPointEntities( (InputPoint)arg1) -> list :

    C++ signature :
        class boost::python::list nestedKeyPointEntities(class PyEdInputPoint {lvalue})'''
    ...
    def nestedPickedEntities (self, *args, **kwargs)-> list :
      '''nestedPickedEntities( (InputPoint)arg1) -> list :

    C++ signature :
        class boost::python::list nestedPickedEntities(class PyEdInputPoint {lvalue})'''
    ...
    def osnapMask (self, *args, **kwargs)-> OsnapMask :
      '''osnapMask( (InputPoint)arg1) -> OsnapMask :

    C++ signature :
        enum AcDb::OsnapMask osnapMask(class PyEdInputPoint {lvalue})'''
    ...
    def osnapOverrides (self, *args, **kwargs)-> OsnapMask :
      '''osnapOverrides( (InputPoint)arg1) -> OsnapMask :

    C++ signature :
        enum AcDb::OsnapMask osnapOverrides(class PyEdInputPoint {lvalue})'''
    ...
    def osnappedPoint (self, *args, **kwargs)-> Point3d :
      '''osnappedPoint( (InputPoint)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d osnappedPoint(class PyEdInputPoint {lvalue})'''
    ...
    def pickedEntities (self, *args, **kwargs)-> list :
      '''pickedEntities( (InputPoint)arg1) -> list :

    C++ signature :
        class boost::python::list pickedEntities(class PyEdInputPoint {lvalue})'''
    ...
    def pointComputed (self, *args, **kwargs)-> bool :
      '''pointComputed( (InputPoint)arg1) -> bool :

    C++ signature :
        bool pointComputed(class PyEdInputPoint {lvalue})'''
    ...
    def rawPoint (self, *args, **kwargs)-> Point3d :
      '''rawPoint( (InputPoint)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d rawPoint(class PyEdInputPoint {lvalue})'''
    ...
    def tooltipString (self, *args, **kwargs)-> str :
      '''tooltipString( (InputPoint)arg1) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > tooltipString(class PyEdInputPoint {lvalue})'''
    ...

class InputPointFilter:
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
    ...
    def processInputPoint (self, *args, **kwargs)-> ErrorStatus :
      '''processInputPoint( (InputPointFilter)arg1, (InputPoint)arg2, (InputPointFilterResult)arg3) -> ErrorStatus :

    C++ signature :
        enum Acad::ErrorStatus processInputPoint(class PyEdInputPointFilter {lvalue},class PyEdInputPoint,class PyEdInputPointFilterResult {lvalue})'''
    ...

class InputPointFilterResult:
    def __init__ (self, *args, **kwargs)-> None:
      '''Raises an exception
This class cannot be instantiated from Python'''
    ...
    def displayOsnapGlyph (self, *args, **kwargs)-> bool :
      '''displayOsnapGlyph( (InputPointFilterResult)arg1) -> bool :

    C++ signature :
        bool displayOsnapGlyph(class PyEdInputPointFilterResult {lvalue})'''
    ...
    def newPoint (self, *args, **kwargs)-> Point3d :
      '''newPoint( (InputPointFilterResult)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d newPoint(class PyEdInputPointFilterResult {lvalue})'''
    ...
    def newTooltipString (self, *args, **kwargs)-> str :
      '''newTooltipString( (InputPointFilterResult)arg1) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > newTooltipString(class PyEdInputPointFilterResult {lvalue})'''
    ...
    def retry (self, *args, **kwargs)-> bool :
      '''retry( (InputPointFilterResult)arg1) -> bool :

    C++ signature :
        bool retry(class PyEdInputPointFilterResult {lvalue})'''
    ...
    def setDisplayOsnapGlyph (self, *args, **kwargs)-> None :
      '''setDisplayOsnapGlyph( (InputPointFilterResult)arg1, (bool)arg2) -> None :

    C++ signature :
        void setDisplayOsnapGlyph(class PyEdInputPointFilterResult {lvalue},bool)'''
    ...
    def setNewPoint (self, *args, **kwargs)-> None :
      '''setNewPoint( (InputPointFilterResult)arg1, (Point3d)arg2) -> None :

    C++ signature :
        void setNewPoint(class PyEdInputPointFilterResult {lvalue},class AcGePoint3d)'''
    ...
    def setNewTooltipString (self, *args, **kwargs)-> None :
      '''setNewTooltipString( (InputPointFilterResult)arg1, (str)arg2) -> None :

    C++ signature :
        void setNewTooltipString(class PyEdInputPointFilterResult {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def setRetry (self, *args, **kwargs)-> None :
      '''setRetry( (InputPointFilterResult)arg1, (bool)arg2) -> None :

    C++ signature :
        void setRetry(class PyEdInputPointFilterResult {lvalue},bool)'''
    ...

class InputPointManager:
    def __init__ (self, *args, **kwargs)-> None:
      '''Raises an exception
This class cannot be instantiated from Python'''
    ...
    def addPointMonitor (self, *args, **kwargs)-> None :
      '''addPointMonitor( (InputPointManager)arg1, (InputPointMonitor)arg2) -> None :

    C++ signature :
        void addPointMonitor(class PyEdInputPointManager {lvalue},class PyEdInputPointMonitor {lvalue})'''
    ...
    def disableSystemCursorGraphics (self, *args, **kwargs)-> bool :
      '''disableSystemCursorGraphics( (InputPointManager)arg1) -> bool :

    C++ signature :
        bool disableSystemCursorGraphics(class PyEdInputPointManager {lvalue})'''
    ...
    def enableMultiSubentPathSelection (self, *args, **kwargs)-> None :
      '''enableMultiSubentPathSelection( (InputPointManager)arg1, (bool)arg2) -> None :

    C++ signature :
        void enableMultiSubentPathSelection(class PyEdInputPointManager {lvalue},bool)'''
    ...
    def enableSystemCursorGraphics (self, *args, **kwargs)-> bool :
      '''enableSystemCursorGraphics( (InputPointManager)arg1) -> bool :

    C++ signature :
        bool enableSystemCursorGraphics(class PyEdInputPointManager {lvalue})'''
    ...
    def forcedPickCount (self, *args, **kwargs)-> int :
      '''forcedPickCount( (InputPointManager)arg1) -> int :

    C++ signature :
        int forcedPickCount(class PyEdInputPointManager {lvalue})'''
    ...
    def hasFilter (self, *args, **kwargs)-> bool :
      '''hasFilter( (InputPointManager)arg1) -> bool :

    C++ signature :
        bool hasFilter(class PyEdInputPointManager {lvalue})'''
    ...
    def mouseHasMoved (self, *args, **kwargs)-> int :
      '''mouseHasMoved( (InputPointManager)arg1) -> int :

    C++ signature :
        int mouseHasMoved(class PyEdInputPointManager {lvalue})'''
    ...
    def registerPointFilter (self, *args, **kwargs)-> None :
      '''registerPointFilter( (InputPointManager)arg1, (InputPointFilter)arg2) -> None :

    C++ signature :
        void registerPointFilter(class PyEdInputPointManager {lvalue},class PyEdInputPointFilter {lvalue})'''
    ...
    def removePointMonitor (self, *args, **kwargs)-> None :
      '''removePointMonitor( (InputPointManager)arg1, (InputPointMonitor)arg2) -> None :

    C++ signature :
        void removePointMonitor(class PyEdInputPointManager {lvalue},class PyEdInputPointMonitor {lvalue})'''
    ...
    def revokePointFilter (self, *args, **kwargs)-> None :
      '''revokePointFilter( (InputPointManager)arg1) -> None :

    C++ signature :
        void revokePointFilter(class PyEdInputPointManager {lvalue})'''
    ...
    def systemCursorDisableCount (self, *args, **kwargs)-> int :
      '''systemCursorDisableCount( (InputPointManager)arg1) -> int :

    C++ signature :
        int systemCursorDisableCount(class PyEdInputPointManager {lvalue})'''
    ...
    def turnOffForcedPick (self, *args, **kwargs)-> bool :
      '''turnOffForcedPick( (InputPointManager)arg1) -> bool :

    C++ signature :
        bool turnOffForcedPick(class PyEdInputPointManager {lvalue})'''
    ...
    def turnOffSubentityWindowSelection (self, *args, **kwargs)-> bool :
      '''turnOffSubentityWindowSelection( (InputPointManager)arg1) -> bool :

    C++ signature :
        bool turnOffSubentityWindowSelection(class PyEdInputPointManager {lvalue})'''
    ...
    def turnOnSubentityWindowSelection (self, *args, **kwargs)-> bool :
      '''turnOnSubentityWindowSelection( (InputPointManager)arg1) -> bool :

    C++ signature :
        bool turnOnSubentityWindowSelection(class PyEdInputPointManager {lvalue})'''
    ...

class InputPointMonitor:
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
    ...
    def monitorInputPoint (self, *args, **kwargs)-> ErrorStatus :
      '''monitorInputPoint( (InputPointMonitor)arg1, (InputPoint)arg2, (InputPointMonitorResult)arg3) -> ErrorStatus :

    C++ signature :
        enum Acad::ErrorStatus monitorInputPoint(class PyEdInputPointMonitor {lvalue},class PyEdInputPoint,class PyEdInputPointMonitorResult {lvalue})'''
    ...

class InputPointMonitorResult:
    def __init__ (self, *args, **kwargs)-> None:
      '''Raises an exception
This class cannot be instantiated from Python'''
    ...
    def additionalTooltipString (self, *args, **kwargs)-> str :
      '''additionalTooltipString( (InputPointMonitorResult)arg1) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > additionalTooltipString(class PyEdInputPointMonitorResult {lvalue})'''
    ...
    def appendToTooltipStr (self, *args, **kwargs)-> bool :
      '''appendToTooltipStr( (InputPointMonitorResult)arg1) -> bool :

    C++ signature :
        bool appendToTooltipStr(class PyEdInputPointMonitorResult {lvalue})'''
    ...
    def setAdditionalTooltipString (self, *args, **kwargs)-> None :
      '''setAdditionalTooltipString( (InputPointMonitorResult)arg1, (str)arg2) -> None :

    C++ signature :
        void setAdditionalTooltipString(class PyEdInputPointMonitorResult {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...

class Jig:
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1, (Entity)arg2) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class PyDbEntity)'''
    ...
    def acquireAngle (self, *args, **kwargs)-> tuple :
      '''acquireAngle( (Jig)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple acquireAngle(class PyJig {lvalue})

acquireAngle( (Jig)arg1, (Point3d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple acquireAngle(class PyJig {lvalue},class AcGePoint3d)'''
    ...
    def acquireDist (self, *args, **kwargs)-> tuple :
      '''acquireDist( (Jig)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple acquireDist(class PyJig {lvalue})

acquireDist( (Jig)arg1, (Point3d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple acquireDist(class PyJig {lvalue},class AcGePoint3d)'''
    ...
    def acquirePoint (self, *args, **kwargs)-> tuple :
      '''acquirePoint( (Jig)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple acquirePoint(class PyJig {lvalue})

acquirePoint( (Jig)arg1, (Point3d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple acquirePoint(class PyJig {lvalue},class AcGePoint3d)'''
    ...
    def acquireString (self, *args, **kwargs)-> tuple :
      '''acquireString( (Jig)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple acquireString(class PyJig {lvalue})'''
    ...
    def append (self, *args, **kwargs)-> ObjectId :
      '''append( (Jig)arg1) -> ObjectId :

    C++ signature :
        class PyDbObjectId append(class PyJig {lvalue})'''
    ...
    def className (self, *args, **kwargs)-> str :
      '''className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def dispPrompt (self, *args, **kwargs)-> str :
      '''dispPrompt( (Jig)arg1) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > dispPrompt(class PyJig {lvalue})'''
    ...
    def drag (self, *args, **kwargs)-> DragStatus :
      '''drag( (Jig)arg1) -> DragStatus :

    C++ signature :
        enum AcEdJig::DragStatus drag(class PyJig {lvalue})

drag( (Jig)arg1, (DragStyle)arg2) -> DragStatus :

    C++ signature :
        enum AcEdJig::DragStatus drag(class PyJig {lvalue},class AcEdDragStyle)'''
    ...
    def keywordList (self, *args, **kwargs)-> str :
      '''keywordList( (Jig)arg1) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > keywordList(class PyJig {lvalue})'''
    ...
    def sampler (self, *args, **kwargs)-> DragStatus :
      '''sampler( (Jig)arg1) -> DragStatus :

    C++ signature :
        enum AcEdJig::DragStatus sampler(class PyJig {lvalue})'''
    ...
    def setDispPrompt (self, *args, **kwargs)-> None :
      '''setDispPrompt( (Jig)arg1, (str)arg2) -> None :

    C++ signature :
        void setDispPrompt(class PyJig {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def setKeywordList (self, *args, **kwargs)-> None :
      '''setKeywordList( (Jig)arg1, (str)arg2) -> None :

    C++ signature :
        void setKeywordList(class PyJig {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def setSpecialCursorType (self, *args, **kwargs)-> None :
      '''setSpecialCursorType( (Jig)arg1, (CursorType)arg2) -> None :

    C++ signature :
        void setSpecialCursorType(class PyJig {lvalue},enum AcEdJig::CursorType)'''
    ...
    def setUserInputControls (self, *args, **kwargs)-> None :
      '''setUserInputControls( (Jig)arg1, (UserInputControls)arg2) -> None :

    C++ signature :
        void setUserInputControls(class PyJig {lvalue},enum AcEdJig::UserInputControls)'''
    ...
    def specialCursorType (self, *args, **kwargs)-> CursorType :
      '''specialCursorType( (Jig)arg1) -> CursorType :

    C++ signature :
        enum AcEdJig::CursorType specialCursorType(class PyJig {lvalue})'''
    ...
    def update (self, *args, **kwargs)-> bool :
      '''update( (Jig)arg1) -> bool :

    C++ signature :
        bool update(class PyJig {lvalue})'''
    ...
    def userInputControls (self, *args, **kwargs)-> UserInputControls :
      '''userInputControls( (Jig)arg1) -> UserInputControls :

    C++ signature :
        enum AcEdJig::UserInputControls userInputControls(class PyJig {lvalue})'''
    ...

class PromptStatus:
    def __init__ (self, /, *args, **kwargs):
      '''Initialize self.  See help(type(self)) for accurate signature.'''
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
    def conjugate (self, *args, **kwargs)-> None:
      '''Returns self, the complex conjugate of any int.'''
    ...
    def denominator (self, *args, **kwargs)-> None:
      '''the denominator of a rational number in lowest terms'''
    ...
    def eCancel (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def eDirect (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def eError (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def eFailed (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def eKeyword (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def eModeless (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def eNone (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def eNormal (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def eOk (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def eRejected (self, *args, **kwargs)-> None:
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
    def imag (self, *args, **kwargs)-> None:
      '''the imaginary part of a complex number'''
    ...
    def kNormal (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def name (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def names (self, *args, **kwargs)-> new empty dictionary
dict(mapping) -> new dictionary initialized from a mapping object's
    (key, value) pairs
dict(iterable) -> new dictionary initialized as if via:
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
    def numerator (self, *args, **kwargs)-> None:
      '''the numerator of a rational number in lowest terms'''
    ...
    def real (self, *args, **kwargs)-> None:
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
    def values (self, *args, **kwargs)-> new empty dictionary
dict(mapping) -> new dictionary initialized from a mapping object's
    (key, value) pairs
dict(iterable) -> new dictionary initialized as if via:
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

class SelectionSet:
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
    ...
    def add (self, *args, **kwargs)-> None :
      '''add( (SelectionSet)arg1, (ObjectId)arg2) -> None :

    C++ signature :
        void add(class PyEdSelectionSet {lvalue},class PyDbObjectId)'''
    ...
    def adsname (self, *args, **kwargs)-> AdsName :
      '''adsname( (SelectionSet)arg1) -> AdsName :

    C++ signature :
        class AdsName adsname(class PyEdSelectionSet {lvalue})'''
    ...
    def clear (self, *args, **kwargs)-> None :
      '''clear( (SelectionSet)arg1) -> None :

    C++ signature :
        void clear(class PyEdSelectionSet {lvalue})'''
    ...
    def hasMember (self, *args, **kwargs)-> bool :
      '''hasMember( (SelectionSet)arg1, (ObjectId)arg2) -> bool :

    C++ signature :
        bool hasMember(class PyEdSelectionSet {lvalue},class PyDbObjectId)'''
    ...
    def isInitialized (self, *args, **kwargs)-> bool :
      '''isInitialized( (SelectionSet)arg1) -> bool :

    C++ signature :
        bool isInitialized(class PyEdSelectionSet {lvalue})'''
    ...
    def remove (self, *args, **kwargs)-> None :
      '''remove( (SelectionSet)arg1, (ObjectId)arg2) -> None :

    C++ signature :
        void remove(class PyEdSelectionSet {lvalue},class PyDbObjectId)'''
    ...
    def size (self, *args, **kwargs)-> int :
      '''size( (SelectionSet)arg1) -> int :

    C++ signature :
        unsigned __int64 size(class PyEdSelectionSet {lvalue})'''
    ...
    def ssNameX (self, *args, **kwargs)-> list :
      '''ssNameX( (SelectionSet)arg1) -> list :

    C++ signature :
        class boost::python::list ssNameX(class PyEdSelectionSet {lvalue})

ssNameX( (SelectionSet)arg1, (int)arg2) -> list :

    C++ signature :
        class boost::python::list ssNameX(class PyEdSelectionSet {lvalue},int)'''
    ...
    def ssSetFirst (self, *args, **kwargs)-> bool :
      '''ssSetFirst( (SelectionSet)arg1) -> bool :

    C++ signature :
        bool ssSetFirst(class PyEdSelectionSet {lvalue})'''
    ...
    def ssXform (self, *args, **kwargs)-> PromptStatus :
      '''ssXform( (SelectionSet)arg1, (Matrix3d)arg2) -> PromptStatus :

    C++ signature :
        enum Acad::PromptStatus ssXform(class PyEdSelectionSet {lvalue},class AcGeMatrix3d)'''
    ...
    def toList (self, *args, **kwargs)-> list :
      '''toList( (SelectionSet)arg1) -> list :

    C++ signature :
        class boost::python::list toList(class PyEdSelectionSet {lvalue})'''
    ...

class UIContext:
    def OnUpdateMenu (self, *args, **kwargs)-> None :
      '''OnUpdateMenu( (UIContext)arg1) -> None :

    C++ signature :
        void OnUpdateMenu(class PyEdUIContext {lvalue})'''
    ...
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
    ...
    def addDefaultContextMenu (self, *args, **kwargs)-> bool :
      '''addDefaultContextMenu( (UIContext)arg1) -> bool :

    C++ signature :
        bool addDefaultContextMenu(class PyEdUIContext {lvalue})

addDefaultContextMenu( (UIContext)arg1, (str)arg2) -> bool :

    C++ signature :
        bool addDefaultContextMenu(class PyEdUIContext {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def addObjectContextMenu (self, *args, **kwargs)-> bool :
      '''addObjectContextMenu( (RxClass)arg1, (UIContext)arg2) -> bool :

    C++ signature :
        bool addObjectContextMenu(class PyRxClass {lvalue},class PyEdUIContext {lvalue})'''
    ...
    def getMenuContext (self, *args, **kwargs)-> object :
      '''getMenuContext( (UIContext)arg1, (RxClass)arg2, (list)arg3) -> object :

    C++ signature :
        class boost::python::api::object getMenuContext(class PyEdUIContext {lvalue},class PyRxClass,class boost::python::list)'''
    ...
    def hitPoint (self, *args, **kwargs)-> Point3d :
      '''hitPoint( (UIContext)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d hitPoint(class PyEdUIContext {lvalue})'''
    ...
    def onCommand (self, *args, **kwargs)-> None :
      '''onCommand( (UIContext)arg1, (SubentType)arg2) -> None :

    C++ signature :
        void onCommand(class PyEdUIContext {lvalue},unsigned int)'''
    ...
    def removeDefaultContextMenu (self, *args, **kwargs)-> bool :
      '''removeDefaultContextMenu( (UIContext)arg1) -> bool :

    C++ signature :
        bool removeDefaultContextMenu(class PyEdUIContext {lvalue})'''
    ...
    def removeObjectContextMenu (self, *args, **kwargs)-> bool :
      '''removeObjectContextMenu( (RxClass)arg1, (UIContext)arg2) -> bool :

    C++ signature :
        bool removeObjectContextMenu(class PyRxClass {lvalue},class PyEdUIContext {lvalue})'''
    ...

class UserInputControls:
    def __init__ (self, /, *args, **kwargs):
      '''Initialize self.  See help(type(self)) for accurate signature.'''
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
    def conjugate (self, *args, **kwargs)-> None:
      '''Returns self, the complex conjugate of any int.'''
    ...
    def denominator (self, *args, **kwargs)-> None:
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
    def imag (self, *args, **kwargs)-> None:
      '''the imaginary part of a complex number'''
    ...
    def kAccept3dCoordinates (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kAcceptMouseUpAsPoint (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kAcceptOtherInputString (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kAnyBlankTerminatesInput (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kDisableDirectDistanceInput (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kDontEchoCancelForCtrlC (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kDontUpdateLastPoint (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kGovernedByOrthoMode (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kGovernedByUCSDetect (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kImpliedFaceForUCSChange (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kInitialBlankTerminatesInput (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kNoDwgLimitsChecking (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kNoNegativeResponseAccepted (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kNoZDirectionOrtho (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kNoZeroResponseAccepted (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kNullResponseAccepted (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kUseBasePointElevation (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def name (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def names (self, *args, **kwargs)-> new empty dictionary
dict(mapping) -> new dictionary initialized from a mapping object's
    (key, value) pairs
dict(iterable) -> new dictionary initialized as if via:
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
    def numerator (self, *args, **kwargs)-> None:
      '''the numerator of a rational number in lowest terms'''
    ...
    def real (self, *args, **kwargs)-> None:
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
    def values (self, *args, **kwargs)-> new empty dictionary
dict(mapping) -> new dictionary initialized from a mapping object's
    (key, value) pairs
dict(iterable) -> new dictionary initialized as if via:
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
    def _ORIGIN (self, *args, **kwargs)-> str
str(bytes_or_buffer[, encoding[, errors]]) -> str

Create a new string object from the given object. If encoding or
errors is specified, then the object must expose a data buffer
that will be decoded using the given encoding and error handler.
Otherwise, returns the result of object.__str__() (if defined)
or repr(object).
encoding defaults to sys.getdefaultencoding().
errors defaults to 'strict':
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
    def __init__ (self, /, *args, **kwargs):
      '''Initialize self.  See help(type(self)) for accurate signature.'''
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

function print:
    def print (*args, **kwargs)-> None :
      '''print( (object)arg1) -> None :

    C++ signature :
        void print(class boost::python::api::object)'''
    ...
