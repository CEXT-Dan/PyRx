
class Core:
    def __class__ (self, *args, **kwargs):
      '''None'''
    ...
    def __delattr__ (self, name, /):
      '''Implement delattr(self, name).'''
    ...
    def __dict__ (self, *args, **kwargs):
      '''None'''
    ...
    def __dir__ (self, /):
      '''Default dir() implementation.'''
    ...
    def __doc__ (self, *args, **kwargs):
      '''None'''
    ...
    def __eq__ (self, value, /):
      '''Return self==value.'''
    ...
    def __format__ (self, format_spec, /):
      '''Default object formatter.'''
    ...
    def __ge__ (self, value, /):
      '''Return self>=value.'''
    ...
    def __getattribute__ (self, name, /):
      '''Return getattr(self, name).'''
    ...
    def __gt__ (self, value, /):
      '''Return self>value.'''
    ...
    def __hash__ (self, /):
      '''Return hash(self).'''
    ...
    def __init__ (self, *args, **kwargs):
      '''
__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
    ...
    def __init_subclass__ (self, *args, **kwargs):
      '''This method is called when a class is subclassed.

The default implementation does nothing. It may be
overridden to extend subclasses.
'''
    ...
    def __instance_size__ (self, *args, **kwargs):
      '''int([x]) -> integer
int(x, base=10) -> integer

Convert a number or string to an integer, or return 0 if no arguments
are given.  If x is a number, return x.__int__().  For floating point
numbers, this truncates towards zero.

If x is not a number or if base is given, then x must be a string,
bytes, or bytearray instance representing an integer literal in the
given base.  The literal can be preceded by '+' or '-' and be surrounded
by whitespace.  The base defaults to 10.  Valid bases are 0 and 2-36.
Base 0 means to interpret the base from the string as an integer literal.
>>> int('0b100', base=0)
4'''
    ...
    def __le__ (self, value, /):
      '''Return self<=value.'''
    ...
    def __lt__ (self, value, /):
      '''Return self<value.'''
    ...
    def __module__ (self, *args, **kwargs):
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
    def __ne__ (self, value, /):
      '''Return self!=value.'''
    ...
    def __new__ (*args, **kwargs):
      '''Create and return a new object.  See help(type) for accurate signature.'''
    ...
    def __reduce__ (self, *args, **kwargs):
      '''None'''
    ...
    def __reduce_ex__ (self, protocol, /):
      '''Helper for pickle.'''
    ...
    def __repr__ (self, /):
      '''Return repr(self).'''
    ...
    def __setattr__ (self, name, value, /):
      '''Implement setattr(self, name, value).'''
    ...
    def __sizeof__ (self, /):
      '''Size of object in memory, in bytes.'''
    ...
    def __str__ (self, /):
      '''Return str(self).'''
    ...
    def __subclasshook__ (self, *args, **kwargs):
      '''Abstract classes can override this to customize issubclass().

This is invoked early on by abc.ABCMeta.__subclasscheck__().
It should return True, False or NotImplemented.  If it returns
NotImplemented, the normal algorithm is used.  Otherwise, it
overrides the normal algorithm (and the outcome is cached).
'''
    ...
    def __weakref__ (self, *args, **kwargs):
      '''None'''
    ...
    def activeViewportId (self, *args, **kwargs):
      '''
activeViewportId() -> ObjectId :

    C++ signature :
        class PyDbObjectId activeViewportId()'''
    ...
    def alert (self, *args, **kwargs):
      '''
alert( (str)arg1) -> int :

    C++ signature :
        int alert(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def arxLoad (self, *args, **kwargs):
      '''
arxLoad( (str)arg1) -> int :

    C++ signature :
        int arxLoad(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def arxLoaded (self, *args, **kwargs):
      '''
arxLoaded() -> list :

    C++ signature :
        class boost::python::list arxLoaded()'''
    ...
    def arxUnload (self, *args, **kwargs):
      '''
arxUnload( (str)arg1) -> int :

    C++ signature :
        int arxUnload(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def audit (self, *args, **kwargs):
      '''
audit( (Database)arg1, (bool)arg2) -> ErrorStatus :

    C++ signature :
        enum Acad::ErrorStatus audit(class PyDbDatabase {lvalue},bool)

audit( (Database)arg1, (bool)arg2, (bool)arg3) -> ErrorStatus :

    C++ signature :
        enum Acad::ErrorStatus audit(class PyDbDatabase {lvalue},bool,bool)'''
    ...
    def callBackOnCancel (self, *args, **kwargs):
      '''
callBackOnCancel() -> None :

    C++ signature :
        void callBackOnCancel()'''
    ...
    def clearOLELock (self, *args, **kwargs):
      '''
clearOLELock( (int)arg1) -> bool :

    C++ signature :
        bool clearOLELock(int)'''
    ...
    def xrefDetach (self, *args, **kwargs):
      '''
xrefDetach( (str)arg1) -> ErrorStatus :

    C++ signature :
        enum Acad::ErrorStatus xrefDetach(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)

xrefDetach( (str)arg1, (bool)arg2, (Database)arg3) -> ErrorStatus :

    C++ signature :
        enum Acad::ErrorStatus xrefDetach(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,bool,class PyDbDatabase {lvalue})'''
    ...

class CursorType:

class DragStatus:

class DragStyle:
    def __class__ (self, *args, **kwargs):
      '''None'''
    ...
    def __delattr__ (self, name, /):
      '''Implement delattr(self, name).'''
    ...
    def __dict__ (self, *args, **kwargs):
      '''None'''
    ...
    def __dir__ (self, /):
      '''Default dir() implementation.'''
    ...
    def __doc__ (self, *args, **kwargs):
      '''None'''
    ...
    def __eq__ (self, value, /):
      '''Return self==value.'''
    ...
    def __format__ (self, format_spec, /):
      '''Default object formatter.'''
    ...
    def __ge__ (self, value, /):
      '''Return self>=value.'''
    ...
    def __getattribute__ (self, name, /):
      '''Return getattr(self, name).'''
    ...
    def __gt__ (self, value, /):
      '''Return self>value.'''
    ...
    def __hash__ (self, /):
      '''Return hash(self).'''
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
    def __init_subclass__ (self, *args, **kwargs):
      '''This method is called when a class is subclassed.

The default implementation does nothing. It may be
overridden to extend subclasses.
'''
    ...
    def __instance_size__ (self, *args, **kwargs):
      '''int([x]) -> integer
int(x, base=10) -> integer

Convert a number or string to an integer, or return 0 if no arguments
are given.  If x is a number, return x.__int__().  For floating point
numbers, this truncates towards zero.

If x is not a number or if base is given, then x must be a string,
bytes, or bytearray instance representing an integer literal in the
given base.  The literal can be preceded by '+' or '-' and be surrounded
by whitespace.  The base defaults to 10.  Valid bases are 0 and 2-36.
Base 0 means to interpret the base from the string as an integer literal.
>>> int('0b100', base=0)
4'''
    ...
    def __le__ (self, value, /):
      '''Return self<=value.'''
    ...
    def __lt__ (self, value, /):
      '''Return self<value.'''
    ...
    def __module__ (self, *args, **kwargs):
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
    def __ne__ (self, value, /):
      '''Return self!=value.'''
    ...
    def __new__ (*args, **kwargs):
      '''Create and return a new object.  See help(type) for accurate signature.'''
    ...
    def __reduce__ (self, *args, **kwargs):
      '''None'''
    ...
    def __reduce_ex__ (self, protocol, /):
      '''Helper for pickle.'''
    ...
    def __repr__ (self, /):
      '''Return repr(self).'''
    ...
    def __setattr__ (self, name, value, /):
      '''Implement setattr(self, name, value).'''
    ...
    def __sizeof__ (self, /):
      '''Size of object in memory, in bytes.'''
    ...
    def __str__ (self, /):
      '''Return str(self).'''
    ...
    def __subclasshook__ (self, *args, **kwargs):
      '''Abstract classes can override this to customize issubclass().

This is invoked early on by abc.ABCMeta.__subclasscheck__().
It should return True, False or NotImplemented.  If it returns
NotImplemented, the normal algorithm is used.  Otherwise, it
overrides the normal algorithm (and the outcome is cached).
'''
    ...
    def __weakref__ (self, *args, **kwargs):
      '''None'''
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

class DrawJig:
    def __class__ (self, *args, **kwargs):
      '''None'''
    ...
    def __delattr__ (self, name, /):
      '''Implement delattr(self, name).'''
    ...
    def __dict__ (self, *args, **kwargs):
      '''None'''
    ...
    def __dir__ (self, /):
      '''Default dir() implementation.'''
    ...
    def __doc__ (self, *args, **kwargs):
      '''None'''
    ...
    def __eq__ (self, value, /):
      '''Return self==value.'''
    ...
    def __format__ (self, format_spec, /):
      '''Default object formatter.'''
    ...
    def __ge__ (self, value, /):
      '''Return self>=value.'''
    ...
    def __getattribute__ (self, name, /):
      '''Return getattr(self, name).'''
    ...
    def __gt__ (self, value, /):
      '''Return self>value.'''
    ...
    def __hash__ (self, /):
      '''Return hash(self).'''
    ...
    def __init__ (self, *args, **kwargs):
      '''
__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
    ...
    def __init_subclass__ (self, *args, **kwargs):
      '''This method is called when a class is subclassed.

The default implementation does nothing. It may be
overridden to extend subclasses.
'''
    ...
    def __instance_size__ (self, *args, **kwargs):
      '''int([x]) -> integer
int(x, base=10) -> integer

Convert a number or string to an integer, or return 0 if no arguments
are given.  If x is a number, return x.__int__().  For floating point
numbers, this truncates towards zero.

If x is not a number or if base is given, then x must be a string,
bytes, or bytearray instance representing an integer literal in the
given base.  The literal can be preceded by '+' or '-' and be surrounded
by whitespace.  The base defaults to 10.  Valid bases are 0 and 2-36.
Base 0 means to interpret the base from the string as an integer literal.
>>> int('0b100', base=0)
4'''
    ...
    def __le__ (self, value, /):
      '''Return self<=value.'''
    ...
    def __lt__ (self, value, /):
      '''Return self<value.'''
    ...
    def __module__ (self, *args, **kwargs):
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
    def __ne__ (self, value, /):
      '''Return self!=value.'''
    ...
    def __new__ (*args, **kwargs):
      '''Create and return a new object.  See help(type) for accurate signature.'''
    ...
    def __reduce__ (self, *args, **kwargs):
      '''None'''
    ...
    def __reduce_ex__ (self, protocol, /):
      '''Helper for pickle.'''
    ...
    def __repr__ (self, /):
      '''Return repr(self).'''
    ...
    def __setattr__ (self, name, value, /):
      '''Implement setattr(self, name, value).'''
    ...
    def __sizeof__ (self, /):
      '''Size of object in memory, in bytes.'''
    ...
    def __str__ (self, /):
      '''Return str(self).'''
    ...
    def __subclasshook__ (self, *args, **kwargs):
      '''Abstract classes can override this to customize issubclass().

This is invoked early on by abc.ABCMeta.__subclasscheck__().
It should return True, False or NotImplemented.  If it returns
NotImplemented, the normal algorithm is used.  Otherwise, it
overrides the normal algorithm (and the outcome is cached).
'''
    ...
    def __weakref__ (self, *args, **kwargs):
      '''None'''
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
    def __class__ (self, *args, **kwargs):
      '''None'''
    ...
    def __delattr__ (self, name, /):
      '''Implement delattr(self, name).'''
    ...
    def __dict__ (self, *args, **kwargs):
      '''None'''
    ...
    def __dir__ (self, /):
      '''Default dir() implementation.'''
    ...
    def __doc__ (self, *args, **kwargs):
      '''None'''
    ...
    def __eq__ (self, value, /):
      '''Return self==value.'''
    ...
    def __format__ (self, format_spec, /):
      '''Default object formatter.'''
    ...
    def __ge__ (self, value, /):
      '''Return self>=value.'''
    ...
    def __getattribute__ (self, name, /):
      '''Return getattr(self, name).'''
    ...
    def __gt__ (self, value, /):
      '''Return self>value.'''
    ...
    def __hash__ (self, /):
      '''Return hash(self).'''
    ...
    def __init__ (self, *args, **kwargs):
      '''
__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
    ...
    def __init_subclass__ (self, *args, **kwargs):
      '''This method is called when a class is subclassed.

The default implementation does nothing. It may be
overridden to extend subclasses.
'''
    ...
    def __instance_size__ (self, *args, **kwargs):
      '''int([x]) -> integer
int(x, base=10) -> integer

Convert a number or string to an integer, or return 0 if no arguments
are given.  If x is a number, return x.__int__().  For floating point
numbers, this truncates towards zero.

If x is not a number or if base is given, then x must be a string,
bytes, or bytearray instance representing an integer literal in the
given base.  The literal can be preceded by '+' or '-' and be surrounded
by whitespace.  The base defaults to 10.  Valid bases are 0 and 2-36.
Base 0 means to interpret the base from the string as an integer literal.
>>> int('0b100', base=0)
4'''
    ...
    def __le__ (self, value, /):
      '''Return self<=value.'''
    ...
    def __lt__ (self, value, /):
      '''Return self<value.'''
    ...
    def __module__ (self, *args, **kwargs):
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
    def __ne__ (self, value, /):
      '''Return self!=value.'''
    ...
    def __new__ (*args, **kwargs):
      '''Create and return a new object.  See help(type) for accurate signature.'''
    ...
    def __reduce__ (self, *args, **kwargs):
      '''None'''
    ...
    def __reduce_ex__ (self, protocol, /):
      '''Helper for pickle.'''
    ...
    def __repr__ (self, /):
      '''Return repr(self).'''
    ...
    def __setattr__ (self, name, value, /):
      '''Implement setattr(self, name, value).'''
    ...
    def __sizeof__ (self, /):
      '''Size of object in memory, in bytes.'''
    ...
    def __str__ (self, /):
      '''Return str(self).'''
    ...
    def __subclasshook__ (self, *args, **kwargs):
      '''Abstract classes can override this to customize issubclass().

This is invoked early on by abc.ABCMeta.__subclasscheck__().
It should return True, False or NotImplemented.  If it returns
NotImplemented, the normal algorithm is used.  Otherwise, it
overrides the normal algorithm (and the outcome is cached).
'''
    ...
    def __weakref__ (self, *args, **kwargs):
      '''None'''
    ...
    def activeViewportId (self, *args, **kwargs):
      '''
activeViewportId() -> ObjectId :

    C++ signature :
        class PyDbObjectId activeViewportId()'''
    ...
    def alert (self, *args, **kwargs):
      '''
alert( (str)arg1) -> None :

    C++ signature :
        void alert(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def arxLoad (self, *args, **kwargs):
      '''
arxLoad( (str)arg1) -> bool :

    C++ signature :
        bool arxLoad(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def arxLoaded (self, *args, **kwargs):
      '''
arxLoaded() -> list :

    C++ signature :
        class boost::python::list arxLoaded()'''
    ...
    def arxUnload (self, *args, **kwargs):
      '''
arxUnload( (str)arg1) -> bool :

    C++ signature :
        bool arxUnload(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def audit (self, *args, **kwargs):
      '''
audit( (Database)arg1, (bool)arg2) -> ErrorStatus :

    C++ signature :
        enum Acad::ErrorStatus audit(class PyDbDatabase,bool)

audit( (Database)arg1, (bool)arg2, (bool)arg3) -> ErrorStatus :

    C++ signature :
        enum Acad::ErrorStatus audit(class PyDbDatabase,bool,bool)'''
    ...
    def className (self, *args, **kwargs):
      '''
className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def cmdS (self, *args, **kwargs):
      '''
cmdS( (list)arg1) -> bool :

    C++ signature :
        bool cmdS(class boost::python::list)'''
    ...
    def entSel (self, *args, **kwargs):
      '''
entSel( (str)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple entSel(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def findFile (self, *args, **kwargs):
      '''
findFile( (str)arg1) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > findFile(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def findTrustedFile (self, *args, **kwargs):
      '''
findTrustedFile( (str)arg1) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > findTrustedFile(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def getAngle (self, *args, **kwargs):
      '''
getAngle( (Point3d)arg1, (str)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getAngle(class AcGePoint3d,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def getCurrentUCS (self, *args, **kwargs):
      '''
getCurrentUCS() -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d getCurrentUCS()'''
    ...
    def getDist (self, *args, **kwargs):
      '''
getDist( (str)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple getDist(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)

getDist( (Point3d)arg1, (str)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getDist(class AcGePoint3d,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def getDouble (self, *args, **kwargs):
      '''
getDouble( (str)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple getDouble(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def getInteger (self, *args, **kwargs):
      '''
getInteger( (str)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple getInteger(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def getKword (self, *args, **kwargs):
      '''
getKword( (str)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple getKword(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def getPoint (self, *args, **kwargs):
      '''
getPoint( (str)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple getPoint(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)

getPoint( (Point3d)arg1, (str)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getPoint(class AcGePoint3d,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def getReal (self, *args, **kwargs):
      '''
getReal( (str)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple getReal(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def getString (self, *args, **kwargs):
      '''
getString( (int)arg1, (str)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getString(int,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def getVar (self, *args, **kwargs):
      '''
getVar( (str)arg1) -> object :

    C++ signature :
        class boost::python::api::object getVar(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def initGet (self, *args, **kwargs):
      '''
initGet( (int)arg1, (str)arg2) -> PromptStatus :

    C++ signature :
        enum Acad::PromptStatus initGet(int,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def select (self, *args, **kwargs):
      '''
select() -> tuple :

    C++ signature :
        class boost::python::tuple select()

select( (list)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple select(class boost::python::list)

select( (str)arg1, (str)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple select(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)

select( (str)arg1, (str)arg2, (list)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple select(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,class boost::python::list)'''
    ...
    def selectAll (self, *args, **kwargs):
      '''
selectAll() -> tuple :

    C++ signature :
        class boost::python::tuple selectAll()

selectAll( (list)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple selectAll(class boost::python::list)'''
    ...
    def selectCrossingWindow (self, *args, **kwargs):
      '''
selectCrossingWindow( (Point3d)arg1, (Point3d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple selectCrossingWindow(class AcGePoint3d,class AcGePoint3d)

selectCrossingWindow( (Point3d)arg1, (Point3d)arg2, (list)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple selectCrossingWindow(class AcGePoint3d,class AcGePoint3d,class boost::python::list)'''
    ...
    def setCurrentUCS (self, *args, **kwargs):
      '''
setCurrentUCS( (Matrix3d)arg1) -> ErrorStatus :

    C++ signature :
        enum Acad::ErrorStatus setCurrentUCS(class AcGeMatrix3d)'''
    ...
    def setVar (self, *args, **kwargs):
      '''
setVar( (str)arg1, (object)arg2) -> bool :

    C++ signature :
        bool setVar(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,class boost::python::api::object)'''
    ...

class EditorReactor:
    def __class__ (self, *args, **kwargs):
      '''None'''
    ...
    def __delattr__ (self, name, /):
      '''Implement delattr(self, name).'''
    ...
    def __dict__ (self, *args, **kwargs):
      '''None'''
    ...
    def __dir__ (self, /):
      '''Default dir() implementation.'''
    ...
    def __doc__ (self, *args, **kwargs):
      '''None'''
    ...
    def __eq__ (self, value, /):
      '''Return self==value.'''
    ...
    def __format__ (self, format_spec, /):
      '''Default object formatter.'''
    ...
    def __ge__ (self, value, /):
      '''Return self>=value.'''
    ...
    def __getattribute__ (self, name, /):
      '''Return getattr(self, name).'''
    ...
    def __gt__ (self, value, /):
      '''Return self>value.'''
    ...
    def __hash__ (self, /):
      '''Return hash(self).'''
    ...
    def __init__ (self, *args, **kwargs):
      '''
__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
    ...
    def __init_subclass__ (self, *args, **kwargs):
      '''This method is called when a class is subclassed.

The default implementation does nothing. It may be
overridden to extend subclasses.
'''
    ...
    def __instance_size__ (self, *args, **kwargs):
      '''int([x]) -> integer
int(x, base=10) -> integer

Convert a number or string to an integer, or return 0 if no arguments
are given.  If x is a number, return x.__int__().  For floating point
numbers, this truncates towards zero.

If x is not a number or if base is given, then x must be a string,
bytes, or bytearray instance representing an integer literal in the
given base.  The literal can be preceded by '+' or '-' and be surrounded
by whitespace.  The base defaults to 10.  Valid bases are 0 and 2-36.
Base 0 means to interpret the base from the string as an integer literal.
>>> int('0b100', base=0)
4'''
    ...
    def __le__ (self, value, /):
      '''Return self<=value.'''
    ...
    def __lt__ (self, value, /):
      '''Return self<value.'''
    ...
    def __module__ (self, *args, **kwargs):
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
    def __ne__ (self, value, /):
      '''Return self!=value.'''
    ...
    def __new__ (*args, **kwargs):
      '''Create and return a new object.  See help(type) for accurate signature.'''
    ...
    def __reduce__ (self, *args, **kwargs):
      '''None'''
    ...
    def __reduce_ex__ (self, protocol, /):
      '''Helper for pickle.'''
    ...
    def __repr__ (self, /):
      '''Return repr(self).'''
    ...
    def __setattr__ (self, name, value, /):
      '''Implement setattr(self, name, value).'''
    ...
    def __sizeof__ (self, /):
      '''Size of object in memory, in bytes.'''
    ...
    def __str__ (self, /):
      '''Return str(self).'''
    ...
    def __subclasshook__ (self, *args, **kwargs):
      '''Abstract classes can override this to customize issubclass().

This is invoked early on by abc.ABCMeta.__subclasscheck__().
It should return True, False or NotImplemented.  If it returns
NotImplemented, the normal algorithm is used.  Otherwise, it
overrides the normal algorithm (and the outcome is cached).
'''
    ...
    def __weakref__ (self, *args, **kwargs):
      '''None'''
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
    def __class__ (self, *args, **kwargs):
      '''None'''
    ...
    def __delattr__ (self, name, /):
      '''Implement delattr(self, name).'''
    ...
    def __dict__ (self, *args, **kwargs):
      '''None'''
    ...
    def __dir__ (self, /):
      '''Default dir() implementation.'''
    ...
    def __doc__ (self, *args, **kwargs):
      '''None'''
    ...
    def __eq__ (self, value, /):
      '''Return self==value.'''
    ...
    def __format__ (self, format_spec, /):
      '''Default object formatter.'''
    ...
    def __ge__ (self, value, /):
      '''Return self>=value.'''
    ...
    def __getattribute__ (self, name, /):
      '''Return getattr(self, name).'''
    ...
    def __gt__ (self, value, /):
      '''Return self>value.'''
    ...
    def __hash__ (self, /):
      '''Return hash(self).'''
    ...
    def __init__ (self, *args, **kwargs):
      '''
__init__( (object)arg1, (Entity)arg2) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class PyDbEntity)'''
    ...
    def __init_subclass__ (self, *args, **kwargs):
      '''This method is called when a class is subclassed.

The default implementation does nothing. It may be
overridden to extend subclasses.
'''
    ...
    def __le__ (self, value, /):
      '''Return self<=value.'''
    ...
    def __lt__ (self, value, /):
      '''Return self<value.'''
    ...
    def __module__ (self, *args, **kwargs):
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
    def __ne__ (self, value, /):
      '''Return self!=value.'''
    ...
    def __new__ (*args, **kwargs):
      '''Create and return a new object.  See help(type) for accurate signature.'''
    ...
    def __reduce__ (self, *args, **kwargs):
      '''None'''
    ...
    def __reduce_ex__ (self, protocol, /):
      '''Helper for pickle.'''
    ...
    def __repr__ (self, /):
      '''Return repr(self).'''
    ...
    def __setattr__ (self, name, value, /):
      '''Implement setattr(self, name, value).'''
    ...
    def __sizeof__ (self, /):
      '''Size of object in memory, in bytes.'''
    ...
    def __str__ (self, /):
      '''Return str(self).'''
    ...
    def __subclasshook__ (self, *args, **kwargs):
      '''Abstract classes can override this to customize issubclass().

This is invoked early on by abc.ABCMeta.__subclasscheck__().
It should return True, False or NotImplemented.  If it returns
NotImplemented, the normal algorithm is used.  Otherwise, it
overrides the normal algorithm (and the outcome is cached).
'''
    ...
    def __weakref__ (self, *args, **kwargs):
      '''None'''
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

class SelectionSet:
    def __class__ (self, *args, **kwargs):
      '''None'''
    ...
    def __delattr__ (self, name, /):
      '''Implement delattr(self, name).'''
    ...
    def __dict__ (self, *args, **kwargs):
      '''None'''
    ...
    def __dir__ (self, /):
      '''Default dir() implementation.'''
    ...
    def __doc__ (self, *args, **kwargs):
      '''None'''
    ...
    def __eq__ (self, value, /):
      '''Return self==value.'''
    ...
    def __format__ (self, format_spec, /):
      '''Default object formatter.'''
    ...
    def __ge__ (self, value, /):
      '''Return self>=value.'''
    ...
    def __getattribute__ (self, name, /):
      '''Return getattr(self, name).'''
    ...
    def __gt__ (self, value, /):
      '''Return self>value.'''
    ...
    def __hash__ (self, /):
      '''Return hash(self).'''
    ...
    def __init__ (self, *args, **kwargs):
      '''Raises an exception
This class cannot be instantiated from Python
'''
    ...
    def __init_subclass__ (self, *args, **kwargs):
      '''This method is called when a class is subclassed.

The default implementation does nothing. It may be
overridden to extend subclasses.
'''
    ...
    def __le__ (self, value, /):
      '''Return self<=value.'''
    ...
    def __lt__ (self, value, /):
      '''Return self<value.'''
    ...
    def __module__ (self, *args, **kwargs):
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
    def __ne__ (self, value, /):
      '''Return self!=value.'''
    ...
    def __new__ (*args, **kwargs):
      '''Create and return a new object.  See help(type) for accurate signature.'''
    ...
    def __reduce__ (self, *args, **kwargs):
      '''None'''
    ...
    def __reduce_ex__ (self, protocol, /):
      '''Helper for pickle.'''
    ...
    def __repr__ (self, /):
      '''Return repr(self).'''
    ...
    def __setattr__ (self, name, value, /):
      '''Implement setattr(self, name, value).'''
    ...
    def __sizeof__ (self, /):
      '''Size of object in memory, in bytes.'''
    ...
    def __str__ (self, /):
      '''Return str(self).'''
    ...
    def __subclasshook__ (self, *args, **kwargs):
      '''Abstract classes can override this to customize issubclass().

This is invoked early on by abc.ABCMeta.__subclasscheck__().
It should return True, False or NotImplemented.  If it returns
NotImplemented, the normal algorithm is used.  Otherwise, it
overrides the normal algorithm (and the outcome is cached).
'''
    ...
    def __weakref__ (self, *args, **kwargs):
      '''None'''
    ...
    def add (self, *args, **kwargs):
      '''
add( (SelectionSet)arg1, (ObjectId)arg2) -> None :

    C++ signature :
        void add(class PyEdSelectionSet {lvalue},class PyDbObjectId)'''
    ...
    def clear (self, *args, **kwargs):
      '''
clear( (SelectionSet)arg1) -> None :

    C++ signature :
        void clear(class PyEdSelectionSet {lvalue})'''
    ...
    def hasMember (self, *args, **kwargs):
      '''
hasMember( (SelectionSet)arg1, (ObjectId)arg2) -> bool :

    C++ signature :
        bool hasMember(class PyEdSelectionSet {lvalue},class PyDbObjectId)'''
    ...
    def isInitialized (self, *args, **kwargs):
      '''
isInitialized( (SelectionSet)arg1) -> bool :

    C++ signature :
        bool isInitialized(class PyEdSelectionSet {lvalue})'''
    ...
    def remove (self, *args, **kwargs):
      '''
remove( (SelectionSet)arg1, (ObjectId)arg2) -> None :

    C++ signature :
        void remove(class PyEdSelectionSet {lvalue},class PyDbObjectId)'''
    ...
    def size (self, *args, **kwargs):
      '''
size( (SelectionSet)arg1) -> int :

    C++ signature :
        unsigned __int64 size(class PyEdSelectionSet {lvalue})'''
    ...
    def toList (self, *args, **kwargs):
      '''
toList( (SelectionSet)arg1) -> list :

    C++ signature :
        class boost::python::list toList(class PyEdSelectionSet {lvalue})'''
    ...

class UserInputControls:

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
    def __class__ (self, *args, **kwargs):
      '''type(object) -> the object's type
type(name, bases, dict, **kwds) -> a new type'''
    ...
    def __delattr__ (self, name, /):
      '''Implement delattr(self, name).'''
    ...
    def __dict__ (self, *args, **kwargs):
      '''None'''
    ...
    def __dir__ (self, /):
      '''Default dir() implementation.'''
    ...
    def __doc__ (self, *args, **kwargs):
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
    def __format__ (self, format_spec, /):
      '''Default object formatter.'''
    ...
    def __ge__ (self, value, /):
      '''Return self>=value.'''
    ...
    def __getattribute__ (self, name, /):
      '''Return getattr(self, name).'''
    ...
    def __gt__ (self, value, /):
      '''Return self>value.'''
    ...
    def __hash__ (self, /):
      '''Return hash(self).'''
    ...
    def __init__ (self, /, *args, **kwargs):
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
    def __init_subclass__ (self, *args, **kwargs):
      '''This method is called when a class is subclassed.

The default implementation does nothing. It may be
overridden to extend subclasses.
'''
    ...
    def __le__ (self, value, /):
      '''Return self<=value.'''
    ...
    def __lt__ (self, value, /):
      '''Return self<value.'''
    ...
    def __module__ (self, *args, **kwargs):
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
    def __ne__ (self, value, /):
      '''Return self!=value.'''
    ...
    def __new__ (*args, **kwargs):
      '''Create and return a new object.  See help(type) for accurate signature.'''
    ...
    def __reduce__ (self, /):
      '''Helper for pickle.'''
    ...
    def __reduce_ex__ (self, protocol, /):
      '''Helper for pickle.'''
    ...
    def __repr__ (self, /):
      '''Return repr(self).'''
    ...
    def __setattr__ (self, name, value, /):
      '''Implement setattr(self, name, value).'''
    ...
    def __sizeof__ (self, /):
      '''Size of object in memory, in bytes.'''
    ...
    def __str__ (self, /):
      '''Return str(self).'''
    ...
    def __subclasshook__ (self, *args, **kwargs):
      '''Abstract classes can override this to customize issubclass().

This is invoked early on by abc.ABCMeta.__subclasscheck__().
It should return True, False or NotImplemented.  If it returns
NotImplemented, the normal algorithm is used.  Otherwise, it
overrides the normal algorithm (and the outcome is cached).
'''
    ...
    def __weakref__ (self, *args, **kwargs):
      '''list of weak references to the object (if defined)'''
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
