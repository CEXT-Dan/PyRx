
class AcGiArcType:

class AcGiFillType:

class AcGiOrientationTransformBehavior:

class AcGiOrientationType:

class AcGiPositionTransformBehavior:

class AcGiScaleTransformBehavior:

class AcGiVisibility:

class CommonDraw:
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
    def __eq__ (self, *args, **kwargs):
      '''
__eq__( (RxObject)arg1, (RxObject)arg2) -> bool :

    C++ signature :
        bool __eq__(class PyRxObject {lvalue},class PyRxObject)'''
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
    def __ne__ (self, *args, **kwargs):
      '''
__ne__( (RxObject)arg1, (RxObject)arg2) -> bool :

    C++ signature :
        bool __ne__(class PyRxObject {lvalue},class PyRxObject)'''
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
    def className (self, *args, **kwargs):
      '''
className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def desc (self, *args, **kwargs):
      '''
desc() -> RxClass :

    C++ signature :
        class PyRxClass desc()'''
    ...
    def isA (self, *args, **kwargs):
      '''
isA( (RxObject)arg1) -> RxClass :

    C++ signature :
        class PyRxClass isA(class PyRxObject {lvalue})'''
    ...
    def isNull (self, *args, **kwargs):
      '''
isNull( (RxObject)arg1) -> bool :

    C++ signature :
        bool isNull(class PyRxObject {lvalue})'''
    ...
    def refCount (self, *args, **kwargs):
      '''
refCount( (RxObject)arg1) -> int :

    C++ signature :
        int refCount(class PyRxObject {lvalue})'''
    ...
    def subEntityTraits (self, *args, **kwargs):
      '''
subEntityTraits( (CommonDraw)arg1) -> SubEntityTraits :

    C++ signature :
        class PyGiSubEntityTraits subEntityTraits(class PyGiCommonDraw {lvalue})'''
    ...

class DrawFlags:

class Drawable:
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
    def __eq__ (self, *args, **kwargs):
      '''
__eq__( (RxObject)arg1, (RxObject)arg2) -> bool :

    C++ signature :
        bool __eq__(class PyRxObject {lvalue},class PyRxObject)'''
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
    def __ne__ (self, *args, **kwargs):
      '''
__ne__( (RxObject)arg1, (RxObject)arg2) -> bool :

    C++ signature :
        bool __ne__(class PyRxObject {lvalue},class PyRxObject)'''
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
    def className (self, *args, **kwargs):
      '''
className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def desc (self, *args, **kwargs):
      '''
desc() -> RxClass :

    C++ signature :
        class PyRxClass desc()'''
    ...
    def isA (self, *args, **kwargs):
      '''
isA( (Drawable)arg1) -> RxClass :

    C++ signature :
        class PyRxClass isA(class PyGiDrawable {lvalue})'''
    ...
    def isNull (self, *args, **kwargs):
      '''
isNull( (RxObject)arg1) -> bool :

    C++ signature :
        bool isNull(class PyRxObject {lvalue})'''
    ...
    def refCount (self, *args, **kwargs):
      '''
refCount( (RxObject)arg1) -> int :

    C++ signature :
        int refCount(class PyRxObject {lvalue})'''
    ...

class DrawableOverrule:
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
    def __eq__ (self, *args, **kwargs):
      '''
__eq__( (RxObject)arg1, (RxObject)arg2) -> bool :

    C++ signature :
        bool __eq__(class PyRxObject {lvalue},class PyRxObject)'''
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
    def __ne__ (self, *args, **kwargs):
      '''
__ne__( (RxObject)arg1, (RxObject)arg2) -> bool :

    C++ signature :
        bool __ne__(class PyRxObject {lvalue},class PyRxObject)'''
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
    def addOverrule (self, *args, **kwargs):
      '''
addOverrule( (RxClass)arg1, (Overrule)arg2) -> ErrorStatus :

    C++ signature :
        enum Acad::ErrorStatus addOverrule(class PyRxClass {lvalue},class PyRxOverrule {lvalue})'''
    ...
    def addOverruleLast (self, *args, **kwargs):
      '''
addOverruleLast( (RxClass)arg1, (Overrule)arg2, (bool)arg3) -> ErrorStatus :

    C++ signature :
        enum Acad::ErrorStatus addOverruleLast(class PyRxClass {lvalue},class PyRxOverrule {lvalue},bool)'''
    ...
    def baseViewportDraw (self, *args, **kwargs):
      '''
baseViewportDraw( (DrawableOverrule)arg1, (Drawable)arg2, (ViewportDraw)arg3) -> None :

    C++ signature :
        void baseViewportDraw(class PyGiDrawableOverrule {lvalue},class PyGiDrawable {lvalue},class PyGiViewportDraw {lvalue})'''
    ...
    def baseViewportDrawLogicalFlags (self, *args, **kwargs):
      '''
baseViewportDrawLogicalFlags( (DrawableOverrule)arg1, (Drawable)arg2, (ViewportDraw)arg3) -> None :

    C++ signature :
        void baseViewportDrawLogicalFlags(class PyGiDrawableOverrule {lvalue},class PyGiDrawable {lvalue},class PyGiViewportDraw {lvalue})'''
    ...
    def baseWorldDraw (self, *args, **kwargs):
      '''
baseWorldDraw( (DrawableOverrule)arg1, (Drawable)arg2, (WorldDraw)arg3) -> bool :

    C++ signature :
        bool baseWorldDraw(class PyGiDrawableOverrule {lvalue},class PyGiDrawable {lvalue},class PyGiWorldDraw {lvalue})'''
    ...
    def className (self, *args, **kwargs):
      '''
className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def desc (self, *args, **kwargs):
      '''
desc() -> RxClass :

    C++ signature :
        class PyRxClass desc()'''
    ...
    def hasOverrule (self, *args, **kwargs):
      '''
hasOverrule( (RxObject)arg1, (RxClass)arg2) -> bool :

    C++ signature :
        bool hasOverrule(class PyRxObject {lvalue},class PyRxClass {lvalue})'''
    ...
    def isA (self, *args, **kwargs):
      '''
isA( (RxObject)arg1) -> RxClass :

    C++ signature :
        class PyRxClass isA(class PyRxObject {lvalue})'''
    ...
    def isApplicable (self, *args, **kwargs):
      '''
isApplicable( (DrawableOverrule)arg1, (RxObject)arg2) -> bool :

    C++ signature :
        bool isApplicable(class PyGiDrawableOverrule {lvalue},class PyRxObject {lvalue})'''
    ...
    def isNull (self, *args, **kwargs):
      '''
isNull( (RxObject)arg1) -> bool :

    C++ signature :
        bool isNull(class PyRxObject {lvalue})'''
    ...
    def isOverruling (self, *args, **kwargs):
      '''
isOverruling() -> bool :

    C++ signature :
        bool isOverruling()'''
    ...
    def refCount (self, *args, **kwargs):
      '''
refCount( (RxObject)arg1) -> int :

    C++ signature :
        int refCount(class PyRxObject {lvalue})'''
    ...
    def removeOverrule (self, *args, **kwargs):
      '''
removeOverrule( (RxClass)arg1, (Overrule)arg2) -> ErrorStatus :

    C++ signature :
        enum Acad::ErrorStatus removeOverrule(class PyRxClass {lvalue},class PyRxOverrule {lvalue})'''
    ...
    def setIsOverruling (self, *args, **kwargs):
      '''
setIsOverruling( (bool)arg1) -> None :

    C++ signature :
        void setIsOverruling(bool)'''
    ...
    def viewportDraw (self, *args, **kwargs):
      '''
viewportDraw( (DrawableOverrule)arg1, (Drawable)arg2, (ViewportDraw)arg3) -> None :

    C++ signature :
        void viewportDraw(class PyGiDrawableOverrule {lvalue},class PyGiDrawable {lvalue},class PyGiViewportDraw {lvalue})'''
    ...
    def viewportDrawLogicalFlags (self, *args, **kwargs):
      '''
viewportDrawLogicalFlags( (DrawableOverrule)arg1, (Drawable)arg2, (ViewportDraw)arg3) -> int :

    C++ signature :
        unsigned int viewportDrawLogicalFlags(class PyGiDrawableOverrule {lvalue},class PyGiDrawable {lvalue},class PyGiViewportDraw {lvalue})'''
    ...
    def worldDraw (self, *args, **kwargs):
      '''
worldDraw( (DrawableOverrule)arg1, (Drawable)arg2, (WorldDraw)arg3) -> bool :

    C++ signature :
        bool worldDraw(class PyGiDrawableOverrule {lvalue},class PyGiDrawable {lvalue},class PyGiWorldDraw {lvalue})'''
    ...

class DrawableTraits:
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
    def __eq__ (self, *args, **kwargs):
      '''
__eq__( (RxObject)arg1, (RxObject)arg2) -> bool :

    C++ signature :
        bool __eq__(class PyRxObject {lvalue},class PyRxObject)'''
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
    def __ne__ (self, *args, **kwargs):
      '''
__ne__( (RxObject)arg1, (RxObject)arg2) -> bool :

    C++ signature :
        bool __ne__(class PyRxObject {lvalue},class PyRxObject)'''
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
    def className (self, *args, **kwargs):
      '''
className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def color (self, *args, **kwargs):
      '''
color( (SubEntityTraits)arg1) -> int :

    C++ signature :
        unsigned short color(class PyGiSubEntityTraits {lvalue})'''
    ...
    def desc (self, *args, **kwargs):
      '''
desc() -> RxClass :

    C++ signature :
        class PyRxClass desc()'''
    ...
    def drawFlags (self, *args, **kwargs):
      '''
drawFlags( (SubEntityTraits)arg1) -> int :

    C++ signature :
        unsigned int drawFlags(class PyGiSubEntityTraits {lvalue})'''
    ...
    def fillType (self, *args, **kwargs):
      '''
fillType( (SubEntityTraits)arg1) -> AcGiFillType :

    C++ signature :
        enum AcGiFillType fillType(class PyGiSubEntityTraits {lvalue})'''
    ...
    def getPlotStyleNameId (self, *args, **kwargs):
      '''
getPlotStyleNameId( (SubEntityTraits)arg1) -> ObjectId :

    C++ signature :
        class PyDbObjectId getPlotStyleNameId(class PyGiSubEntityTraits {lvalue})'''
    ...
    def isA (self, *args, **kwargs):
      '''
isA( (RxObject)arg1) -> RxClass :

    C++ signature :
        class PyRxClass isA(class PyRxObject {lvalue})'''
    ...
    def isNull (self, *args, **kwargs):
      '''
isNull( (RxObject)arg1) -> bool :

    C++ signature :
        bool isNull(class PyRxObject {lvalue})'''
    ...
    def layerId (self, *args, **kwargs):
      '''
layerId( (SubEntityTraits)arg1) -> ObjectId :

    C++ signature :
        class PyDbObjectId layerId(class PyGiSubEntityTraits {lvalue})'''
    ...
    def lineTypeId (self, *args, **kwargs):
      '''
lineTypeId( (SubEntityTraits)arg1) -> ObjectId :

    C++ signature :
        class PyDbObjectId lineTypeId(class PyGiSubEntityTraits {lvalue})'''
    ...
    def lineTypeScale (self, *args, **kwargs):
      '''
lineTypeScale( (SubEntityTraits)arg1) -> float :

    C++ signature :
        double lineTypeScale(class PyGiSubEntityTraits {lvalue})'''
    ...
    def lineWeight (self, *args, **kwargs):
      '''
lineWeight( (SubEntityTraits)arg1) -> LineWeight :

    C++ signature :
        enum AcDb::LineWeight lineWeight(class PyGiSubEntityTraits {lvalue})'''
    ...
    def materialId (self, *args, **kwargs):
      '''
materialId( (SubEntityTraits)arg1) -> ObjectId :

    C++ signature :
        class PyDbObjectId materialId(class PyGiSubEntityTraits {lvalue})'''
    ...
    def refCount (self, *args, **kwargs):
      '''
refCount( (RxObject)arg1) -> int :

    C++ signature :
        int refCount(class PyRxObject {lvalue})'''
    ...
    def sectionable (self, *args, **kwargs):
      '''
sectionable( (SubEntityTraits)arg1) -> bool :

    C++ signature :
        bool sectionable(class PyGiSubEntityTraits {lvalue})'''
    ...
    def selectionGeom (self, *args, **kwargs):
      '''
selectionGeom( (SubEntityTraits)arg1) -> bool :

    C++ signature :
        bool selectionGeom(class PyGiSubEntityTraits {lvalue})'''
    ...
    def setColor (self, *args, **kwargs):
      '''
setColor( (SubEntityTraits)arg1, (int)arg2) -> None :

    C++ signature :
        void setColor(class PyGiSubEntityTraits {lvalue},unsigned short)'''
    ...
    def setDrawFlags (self, *args, **kwargs):
      '''
setDrawFlags( (SubEntityTraits)arg1, (int)arg2) -> ErrorStatus :

    C++ signature :
        enum Acad::ErrorStatus setDrawFlags(class PyGiSubEntityTraits {lvalue},unsigned int)'''
    ...
    def setFillType (self, *args, **kwargs):
      '''
setFillType( (SubEntityTraits)arg1, (AcGiFillType)arg2) -> None :

    C++ signature :
        void setFillType(class PyGiSubEntityTraits {lvalue},enum AcGiFillType)'''
    ...
    def setLayer (self, *args, **kwargs):
      '''
setLayer( (SubEntityTraits)arg1, (ObjectId)arg2) -> None :

    C++ signature :
        void setLayer(class PyGiSubEntityTraits {lvalue},class PyDbObjectId)'''
    ...
    def setLineType (self, *args, **kwargs):
      '''
setLineType( (SubEntityTraits)arg1, (ObjectId)arg2) -> None :

    C++ signature :
        void setLineType(class PyGiSubEntityTraits {lvalue},class PyDbObjectId)'''
    ...
    def setLineTypeScale (self, *args, **kwargs):
      '''
setLineTypeScale( (SubEntityTraits)arg1) -> None :

    C++ signature :
        void setLineTypeScale(class PyGiSubEntityTraits {lvalue})

setLineTypeScale( (SubEntityTraits)arg1, (float)arg2) -> None :

    C++ signature :
        void setLineTypeScale(class PyGiSubEntityTraits {lvalue},double)'''
    ...
    def setLineWeight (self, *args, **kwargs):
      '''
setLineWeight( (SubEntityTraits)arg1, (LineWeight)arg2) -> None :

    C++ signature :
        void setLineWeight(class PyGiSubEntityTraits {lvalue},enum AcDb::LineWeight)'''
    ...
    def setMaterial (self, *args, **kwargs):
      '''
setMaterial( (SubEntityTraits)arg1, (ObjectId)arg2) -> None :

    C++ signature :
        void setMaterial(class PyGiSubEntityTraits {lvalue},class PyDbObjectId)'''
    ...
    def setPlotStyleName (self, *args, **kwargs):
      '''
setPlotStyleName( (SubEntityTraits)arg1, (PlotStyleNameType)arg2) -> None :

    C++ signature :
        void setPlotStyleName(class PyGiSubEntityTraits {lvalue},enum AcDb::PlotStyleNameType)

setPlotStyleName( (SubEntityTraits)arg1, (PlotStyleNameType)arg2, (ObjectId)arg3) -> None :

    C++ signature :
        void setPlotStyleName(class PyGiSubEntityTraits {lvalue},enum AcDb::PlotStyleNameType,class PyDbObjectId)'''
    ...
    def setSectionable (self, *args, **kwargs):
      '''
setSectionable( (SubEntityTraits)arg1, (bool)arg2) -> None :

    C++ signature :
        void setSectionable(class PyGiSubEntityTraits {lvalue},bool)'''
    ...
    def setSelectionGeom (self, *args, **kwargs):
      '''
setSelectionGeom( (SubEntityTraits)arg1, (bool)arg2) -> None :

    C++ signature :
        void setSelectionGeom(class PyGiSubEntityTraits {lvalue},bool)'''
    ...
    def setSelectionMarker (self, *args, **kwargs):
      '''
setSelectionMarker( (SubEntityTraits)arg1, (int)arg2) -> None :

    C++ signature :
        void setSelectionMarker(class PyGiSubEntityTraits {lvalue},__int64)'''
    ...
    def setShadowFlags (self, *args, **kwargs):
      '''
setShadowFlags( (SubEntityTraits)arg1, (ShadowFlags)arg2) -> ErrorStatus :

    C++ signature :
        enum Acad::ErrorStatus setShadowFlags(class PyGiSubEntityTraits {lvalue},enum AcGiSubEntityTraits::ShadowFlags)'''
    ...
    def setThickness (self, *args, **kwargs):
      '''
setThickness( (SubEntityTraits)arg1, (float)arg2) -> None :

    C++ signature :
        void setThickness(class PyGiSubEntityTraits {lvalue},double)'''
    ...
    def setTransparency (self, *args, **kwargs):
      '''
setTransparency( (SubEntityTraits)arg1, (Transparency)arg2) -> None :

    C++ signature :
        void setTransparency(class PyGiSubEntityTraits {lvalue},class AcCmTransparency)'''
    ...
    def setTrueColor (self, *args, **kwargs):
      '''
setTrueColor( (SubEntityTraits)arg1, (EntityColor)arg2) -> None :

    C++ signature :
        void setTrueColor(class PyGiSubEntityTraits {lvalue},class AcCmEntityColor)'''
    ...
    def setVisualStyle (self, *args, **kwargs):
      '''
setVisualStyle( (SubEntityTraits)arg1, (ObjectId)arg2) -> None :

    C++ signature :
        void setVisualStyle(class PyGiSubEntityTraits {lvalue},class PyDbObjectId)'''
    ...
    def shadowFlags (self, *args, **kwargs):
      '''
shadowFlags( (SubEntityTraits)arg1) -> ShadowFlags :

    C++ signature :
        enum AcGiSubEntityTraits::ShadowFlags shadowFlags(class PyGiSubEntityTraits {lvalue})'''
    ...
    def thickness (self, *args, **kwargs):
      '''
thickness( (SubEntityTraits)arg1) -> float :

    C++ signature :
        double thickness(class PyGiSubEntityTraits {lvalue})'''
    ...
    def transparency (self, *args, **kwargs):
      '''
transparency( (SubEntityTraits)arg1) -> Transparency :

    C++ signature :
        class AcCmTransparency transparency(class PyGiSubEntityTraits {lvalue})'''
    ...
    def trueColor (self, *args, **kwargs):
      '''
trueColor( (SubEntityTraits)arg1) -> EntityColor :

    C++ signature :
        class AcCmEntityColor trueColor(class PyGiSubEntityTraits {lvalue})'''
    ...
    def visualStyle (self, *args, **kwargs):
      '''
visualStyle( (SubEntityTraits)arg1) -> ObjectId :

    C++ signature :
        class PyDbObjectId visualStyle(class PyGiSubEntityTraits {lvalue})'''
    ...

class Geometry:
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
    def __eq__ (self, *args, **kwargs):
      '''
__eq__( (RxObject)arg1, (RxObject)arg2) -> bool :

    C++ signature :
        bool __eq__(class PyRxObject {lvalue},class PyRxObject)'''
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
    def __ne__ (self, *args, **kwargs):
      '''
__ne__( (RxObject)arg1, (RxObject)arg2) -> bool :

    C++ signature :
        bool __ne__(class PyRxObject {lvalue},class PyRxObject)'''
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
    def circle (self, *args, **kwargs):
      '''
circle( (Geometry)arg1, (Point3d)arg2, (float)arg3, (Vector3d)arg4) -> bool :

    C++ signature :
        bool circle(class PyGiGeometry {lvalue},class AcGePoint3d,double,class AcGeVector3d)

circle( (Geometry)arg1, (Point3d)arg2, (Point3d)arg3, (Point3d)arg4) -> bool :

    C++ signature :
        bool circle(class PyGiGeometry {lvalue},class AcGePoint3d,class AcGePoint3d,class AcGePoint3d)'''
    ...
    def circularArc (self, *args, **kwargs):
      '''
circularArc( (Geometry)arg1, (Point3d)arg2, (float)arg3, (Vector3d)arg4, (Vector3d)arg5, (float)arg6) -> bool :

    C++ signature :
        bool circularArc(class PyGiGeometry {lvalue},class AcGePoint3d,double,class AcGeVector3d,class AcGeVector3d,double)

circularArc( (Geometry)arg1, (Point3d)arg2, (float)arg3, (Vector3d)arg4, (Vector3d)arg5, (float)arg6, (AcGiArcType)arg7) -> bool :

    C++ signature :
        bool circularArc(class PyGiGeometry {lvalue},class AcGePoint3d,double,class AcGeVector3d,class AcGeVector3d,double,enum AcGiArcType)

circularArc( (Geometry)arg1, (Point3d)arg2, (Point3d)arg3, (Point3d)arg4) -> bool :

    C++ signature :
        bool circularArc(class PyGiGeometry {lvalue},class AcGePoint3d,class AcGePoint3d,class AcGePoint3d)

circularArc( (Geometry)arg1, (Point3d)arg2, (Point3d)arg3, (Point3d)arg4, (AcGiArcType)arg5) -> bool :

    C++ signature :
        bool circularArc(class PyGiGeometry {lvalue},class AcGePoint3d,class AcGePoint3d,class AcGePoint3d,enum AcGiArcType)'''
    ...
    def className (self, *args, **kwargs):
      '''
className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def desc (self, *args, **kwargs):
      '''
desc() -> RxClass :

    C++ signature :
        class PyRxClass desc()'''
    ...
    def draw (self, *args, **kwargs):
      '''
draw( (Geometry)arg1, (Drawable)arg2) -> bool :

    C++ signature :
        bool draw(class PyGiGeometry {lvalue},class PyGiDrawable {lvalue})'''
    ...
    def edge (self, *args, **kwargs):
      '''
edge( (Geometry)arg1, (list)arg2) -> bool :

    C++ signature :
        bool edge(class PyGiGeometry {lvalue},class boost::python::list)'''
    ...
    def ellipticalArc (self, *args, **kwargs):
      '''
ellipticalArc( (Geometry)arg1, (Point3d)arg2, (Vector3d)arg3, (float)arg4, (float)arg5, (float)arg6, (float)arg7, (float)arg8) -> bool :

    C++ signature :
        bool ellipticalArc(class PyGiGeometry {lvalue},class AcGePoint3d,class AcGeVector3d,double,double,double,double,double)

ellipticalArc( (Geometry)arg1, (Point3d)arg2, (Vector3d)arg3, (float)arg4, (float)arg5, (float)arg6, (float)arg7, (float)arg8, (AcGiArcType)arg9) -> bool :

    C++ signature :
        bool ellipticalArc(class PyGiGeometry {lvalue},class AcGePoint3d,class AcGeVector3d,double,double,double,double,double,enum AcGiArcType)'''
    ...
    def getModelToWorldTransform (self, *args, **kwargs):
      '''
getModelToWorldTransform( (Geometry)arg1) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d getModelToWorldTransform(class PyGiGeometry {lvalue})'''
    ...
    def getWorldToModelTransform (self, *args, **kwargs):
      '''
getWorldToModelTransform( (Geometry)arg1) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d getWorldToModelTransform(class PyGiGeometry {lvalue})'''
    ...
    def isA (self, *args, **kwargs):
      '''
isA( (RxObject)arg1) -> RxClass :

    C++ signature :
        class PyRxClass isA(class PyRxObject {lvalue})'''
    ...
    def isNull (self, *args, **kwargs):
      '''
isNull( (RxObject)arg1) -> bool :

    C++ signature :
        bool isNull(class PyRxObject {lvalue})'''
    ...
    def pline (self, *args, **kwargs):
      '''
pline( (Geometry)arg1, (Polyline)arg2) -> bool :

    C++ signature :
        bool pline(class PyGiGeometry {lvalue},class PyDbPolyline)

pline( (Geometry)arg1, (Polyline)arg2, (int)arg3, (int)arg4) -> bool :

    C++ signature :
        bool pline(class PyGiGeometry {lvalue},class PyDbPolyline,unsigned int,unsigned int)'''
    ...
    def polygon (self, *args, **kwargs):
      '''
polygon( (Geometry)arg1, (list)arg2) -> bool :

    C++ signature :
        bool polygon(class PyGiGeometry {lvalue},class boost::python::list)'''
    ...
    def polyline (self, *args, **kwargs):
      '''
polyline( (Geometry)arg1, (list)arg2) -> bool :

    C++ signature :
        bool polyline(class PyGiGeometry {lvalue},class boost::python::list)

polyline( (Geometry)arg1, (list)arg2, (Vector3d)arg3, (int)arg4) -> bool :

    C++ signature :
        bool polyline(class PyGiGeometry {lvalue},class boost::python::list,class AcGeVector3d,__int64)'''
    ...
    def popModelTransform (self, *args, **kwargs):
      '''
popModelTransform( (Geometry)arg1) -> bool :

    C++ signature :
        bool popModelTransform(class PyGiGeometry {lvalue})'''
    ...
    def pushModelTransform (self, *args, **kwargs):
      '''
pushModelTransform( (Geometry)arg1, (Vector3d)arg2) -> bool :

    C++ signature :
        bool pushModelTransform(class PyGiGeometry {lvalue},class AcGeVector3d)

pushModelTransform( (Geometry)arg1, (Matrix3d)arg2) -> bool :

    C++ signature :
        bool pushModelTransform(class PyGiGeometry {lvalue},class AcGeMatrix3d)'''
    ...
    def pushOrientationTransform (self, *args, **kwargs):
      '''
pushOrientationTransform( (Geometry)arg1, (AcGiOrientationTransformBehavior)arg2) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d pushOrientationTransform(class PyGiGeometry {lvalue},enum AcGiOrientationTransformBehavior)'''
    ...
    def pushPositionTransform (self, *args, **kwargs):
      '''
pushPositionTransform( (Geometry)arg1, (AcGiPositionTransformBehavior)arg2, (Point3d)arg3) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d pushPositionTransform(class PyGiGeometry {lvalue},enum AcGiPositionTransformBehavior,class AcGePoint3d)

pushPositionTransform( (Geometry)arg1, (AcGiPositionTransformBehavior)arg2, (Point2d)arg3) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d pushPositionTransform(class PyGiGeometry {lvalue},enum AcGiPositionTransformBehavior,class AcGePoint2d)'''
    ...
    def pushScaleTransform (self, *args, **kwargs):
      '''
pushScaleTransform( (Geometry)arg1, (AcGiScaleTransformBehavior)arg2, (Point3d)arg3) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d pushScaleTransform(class PyGiGeometry {lvalue},enum AcGiScaleTransformBehavior,class AcGePoint3d)

pushScaleTransform( (Geometry)arg1, (AcGiScaleTransformBehavior)arg2, (Point2d)arg3) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d pushScaleTransform(class PyGiGeometry {lvalue},enum AcGiScaleTransformBehavior,class AcGePoint2d)'''
    ...
    def ray (self, *args, **kwargs):
      '''
ray( (Geometry)arg1, (Point3d)arg2, (Point3d)arg3) -> bool :

    C++ signature :
        bool ray(class PyGiGeometry {lvalue},class AcGePoint3d,class AcGePoint3d)'''
    ...
    def refCount (self, *args, **kwargs):
      '''
refCount( (RxObject)arg1) -> int :

    C++ signature :
        int refCount(class PyRxObject {lvalue})'''
    ...
    def rowOfDots (self, *args, **kwargs):
      '''
rowOfDots( (Geometry)arg1, (int)arg2, (Point3d)arg3, (Vector3d)arg4) -> bool :

    C++ signature :
        bool rowOfDots(class PyGiGeometry {lvalue},int,class AcGePoint3d,class AcGeVector3d)'''
    ...
    def text (self, *args, **kwargs):
      '''
text( (Geometry)arg1, (Point3d)arg2, (Vector3d)arg3, (Vector3d)arg4, (float)arg5, (float)arg6, (float)arg7, (str)arg8) -> bool :

    C++ signature :
        bool text(class PyGiGeometry {lvalue},class AcGePoint3d,class AcGeVector3d,class AcGeVector3d,double,double,double,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def worldLine (self, *args, **kwargs):
      '''
worldLine( (Geometry)arg1, (Point3d)arg2, (Point3d)arg3) -> bool :

    C++ signature :
        bool worldLine(class PyGiGeometry {lvalue},class AcGePoint3d,class AcGePoint3d)'''
    ...
    def xline (self, *args, **kwargs):
      '''
xline( (Geometry)arg1, (Point3d)arg2, (Point3d)arg3) -> bool :

    C++ signature :
        bool xline(class PyGiGeometry {lvalue},class AcGePoint3d,class AcGePoint3d)'''
    ...

class SelectionFlags:

class ShadowFlags:

class SubEntityTraits:
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
    def __eq__ (self, *args, **kwargs):
      '''
__eq__( (RxObject)arg1, (RxObject)arg2) -> bool :

    C++ signature :
        bool __eq__(class PyRxObject {lvalue},class PyRxObject)'''
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
    def __ne__ (self, *args, **kwargs):
      '''
__ne__( (RxObject)arg1, (RxObject)arg2) -> bool :

    C++ signature :
        bool __ne__(class PyRxObject {lvalue},class PyRxObject)'''
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
    def className (self, *args, **kwargs):
      '''
className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def color (self, *args, **kwargs):
      '''
color( (SubEntityTraits)arg1) -> int :

    C++ signature :
        unsigned short color(class PyGiSubEntityTraits {lvalue})'''
    ...
    def desc (self, *args, **kwargs):
      '''
desc() -> RxClass :

    C++ signature :
        class PyRxClass desc()'''
    ...
    def drawFlags (self, *args, **kwargs):
      '''
drawFlags( (SubEntityTraits)arg1) -> int :

    C++ signature :
        unsigned int drawFlags(class PyGiSubEntityTraits {lvalue})'''
    ...
    def fillType (self, *args, **kwargs):
      '''
fillType( (SubEntityTraits)arg1) -> AcGiFillType :

    C++ signature :
        enum AcGiFillType fillType(class PyGiSubEntityTraits {lvalue})'''
    ...
    def getPlotStyleNameId (self, *args, **kwargs):
      '''
getPlotStyleNameId( (SubEntityTraits)arg1) -> ObjectId :

    C++ signature :
        class PyDbObjectId getPlotStyleNameId(class PyGiSubEntityTraits {lvalue})'''
    ...
    def isA (self, *args, **kwargs):
      '''
isA( (RxObject)arg1) -> RxClass :

    C++ signature :
        class PyRxClass isA(class PyRxObject {lvalue})'''
    ...
    def isNull (self, *args, **kwargs):
      '''
isNull( (RxObject)arg1) -> bool :

    C++ signature :
        bool isNull(class PyRxObject {lvalue})'''
    ...
    def layerId (self, *args, **kwargs):
      '''
layerId( (SubEntityTraits)arg1) -> ObjectId :

    C++ signature :
        class PyDbObjectId layerId(class PyGiSubEntityTraits {lvalue})'''
    ...
    def lineTypeId (self, *args, **kwargs):
      '''
lineTypeId( (SubEntityTraits)arg1) -> ObjectId :

    C++ signature :
        class PyDbObjectId lineTypeId(class PyGiSubEntityTraits {lvalue})'''
    ...
    def lineTypeScale (self, *args, **kwargs):
      '''
lineTypeScale( (SubEntityTraits)arg1) -> float :

    C++ signature :
        double lineTypeScale(class PyGiSubEntityTraits {lvalue})'''
    ...
    def lineWeight (self, *args, **kwargs):
      '''
lineWeight( (SubEntityTraits)arg1) -> LineWeight :

    C++ signature :
        enum AcDb::LineWeight lineWeight(class PyGiSubEntityTraits {lvalue})'''
    ...
    def materialId (self, *args, **kwargs):
      '''
materialId( (SubEntityTraits)arg1) -> ObjectId :

    C++ signature :
        class PyDbObjectId materialId(class PyGiSubEntityTraits {lvalue})'''
    ...
    def refCount (self, *args, **kwargs):
      '''
refCount( (RxObject)arg1) -> int :

    C++ signature :
        int refCount(class PyRxObject {lvalue})'''
    ...
    def sectionable (self, *args, **kwargs):
      '''
sectionable( (SubEntityTraits)arg1) -> bool :

    C++ signature :
        bool sectionable(class PyGiSubEntityTraits {lvalue})'''
    ...
    def selectionGeom (self, *args, **kwargs):
      '''
selectionGeom( (SubEntityTraits)arg1) -> bool :

    C++ signature :
        bool selectionGeom(class PyGiSubEntityTraits {lvalue})'''
    ...
    def setColor (self, *args, **kwargs):
      '''
setColor( (SubEntityTraits)arg1, (int)arg2) -> None :

    C++ signature :
        void setColor(class PyGiSubEntityTraits {lvalue},unsigned short)'''
    ...
    def setDrawFlags (self, *args, **kwargs):
      '''
setDrawFlags( (SubEntityTraits)arg1, (int)arg2) -> ErrorStatus :

    C++ signature :
        enum Acad::ErrorStatus setDrawFlags(class PyGiSubEntityTraits {lvalue},unsigned int)'''
    ...
    def setFillType (self, *args, **kwargs):
      '''
setFillType( (SubEntityTraits)arg1, (AcGiFillType)arg2) -> None :

    C++ signature :
        void setFillType(class PyGiSubEntityTraits {lvalue},enum AcGiFillType)'''
    ...
    def setLayer (self, *args, **kwargs):
      '''
setLayer( (SubEntityTraits)arg1, (ObjectId)arg2) -> None :

    C++ signature :
        void setLayer(class PyGiSubEntityTraits {lvalue},class PyDbObjectId)'''
    ...
    def setLineType (self, *args, **kwargs):
      '''
setLineType( (SubEntityTraits)arg1, (ObjectId)arg2) -> None :

    C++ signature :
        void setLineType(class PyGiSubEntityTraits {lvalue},class PyDbObjectId)'''
    ...
    def setLineTypeScale (self, *args, **kwargs):
      '''
setLineTypeScale( (SubEntityTraits)arg1) -> None :

    C++ signature :
        void setLineTypeScale(class PyGiSubEntityTraits {lvalue})

setLineTypeScale( (SubEntityTraits)arg1, (float)arg2) -> None :

    C++ signature :
        void setLineTypeScale(class PyGiSubEntityTraits {lvalue},double)'''
    ...
    def setLineWeight (self, *args, **kwargs):
      '''
setLineWeight( (SubEntityTraits)arg1, (LineWeight)arg2) -> None :

    C++ signature :
        void setLineWeight(class PyGiSubEntityTraits {lvalue},enum AcDb::LineWeight)'''
    ...
    def setMaterial (self, *args, **kwargs):
      '''
setMaterial( (SubEntityTraits)arg1, (ObjectId)arg2) -> None :

    C++ signature :
        void setMaterial(class PyGiSubEntityTraits {lvalue},class PyDbObjectId)'''
    ...
    def setPlotStyleName (self, *args, **kwargs):
      '''
setPlotStyleName( (SubEntityTraits)arg1, (PlotStyleNameType)arg2) -> None :

    C++ signature :
        void setPlotStyleName(class PyGiSubEntityTraits {lvalue},enum AcDb::PlotStyleNameType)

setPlotStyleName( (SubEntityTraits)arg1, (PlotStyleNameType)arg2, (ObjectId)arg3) -> None :

    C++ signature :
        void setPlotStyleName(class PyGiSubEntityTraits {lvalue},enum AcDb::PlotStyleNameType,class PyDbObjectId)'''
    ...
    def setSectionable (self, *args, **kwargs):
      '''
setSectionable( (SubEntityTraits)arg1, (bool)arg2) -> None :

    C++ signature :
        void setSectionable(class PyGiSubEntityTraits {lvalue},bool)'''
    ...
    def setSelectionGeom (self, *args, **kwargs):
      '''
setSelectionGeom( (SubEntityTraits)arg1, (bool)arg2) -> None :

    C++ signature :
        void setSelectionGeom(class PyGiSubEntityTraits {lvalue},bool)'''
    ...
    def setSelectionMarker (self, *args, **kwargs):
      '''
setSelectionMarker( (SubEntityTraits)arg1, (int)arg2) -> None :

    C++ signature :
        void setSelectionMarker(class PyGiSubEntityTraits {lvalue},__int64)'''
    ...
    def setShadowFlags (self, *args, **kwargs):
      '''
setShadowFlags( (SubEntityTraits)arg1, (ShadowFlags)arg2) -> ErrorStatus :

    C++ signature :
        enum Acad::ErrorStatus setShadowFlags(class PyGiSubEntityTraits {lvalue},enum AcGiSubEntityTraits::ShadowFlags)'''
    ...
    def setThickness (self, *args, **kwargs):
      '''
setThickness( (SubEntityTraits)arg1, (float)arg2) -> None :

    C++ signature :
        void setThickness(class PyGiSubEntityTraits {lvalue},double)'''
    ...
    def setTransparency (self, *args, **kwargs):
      '''
setTransparency( (SubEntityTraits)arg1, (Transparency)arg2) -> None :

    C++ signature :
        void setTransparency(class PyGiSubEntityTraits {lvalue},class AcCmTransparency)'''
    ...
    def setTrueColor (self, *args, **kwargs):
      '''
setTrueColor( (SubEntityTraits)arg1, (EntityColor)arg2) -> None :

    C++ signature :
        void setTrueColor(class PyGiSubEntityTraits {lvalue},class AcCmEntityColor)'''
    ...
    def setVisualStyle (self, *args, **kwargs):
      '''
setVisualStyle( (SubEntityTraits)arg1, (ObjectId)arg2) -> None :

    C++ signature :
        void setVisualStyle(class PyGiSubEntityTraits {lvalue},class PyDbObjectId)'''
    ...
    def shadowFlags (self, *args, **kwargs):
      '''
shadowFlags( (SubEntityTraits)arg1) -> ShadowFlags :

    C++ signature :
        enum AcGiSubEntityTraits::ShadowFlags shadowFlags(class PyGiSubEntityTraits {lvalue})'''
    ...
    def thickness (self, *args, **kwargs):
      '''
thickness( (SubEntityTraits)arg1) -> float :

    C++ signature :
        double thickness(class PyGiSubEntityTraits {lvalue})'''
    ...
    def transparency (self, *args, **kwargs):
      '''
transparency( (SubEntityTraits)arg1) -> Transparency :

    C++ signature :
        class AcCmTransparency transparency(class PyGiSubEntityTraits {lvalue})'''
    ...
    def trueColor (self, *args, **kwargs):
      '''
trueColor( (SubEntityTraits)arg1) -> EntityColor :

    C++ signature :
        class AcCmEntityColor trueColor(class PyGiSubEntityTraits {lvalue})'''
    ...
    def visualStyle (self, *args, **kwargs):
      '''
visualStyle( (SubEntityTraits)arg1) -> ObjectId :

    C++ signature :
        class PyDbObjectId visualStyle(class PyGiSubEntityTraits {lvalue})'''
    ...

class TransparencyMode:

class ViewportDraw:
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
    def __eq__ (self, *args, **kwargs):
      '''
__eq__( (RxObject)arg1, (RxObject)arg2) -> bool :

    C++ signature :
        bool __eq__(class PyRxObject {lvalue},class PyRxObject)'''
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
    def __ne__ (self, *args, **kwargs):
      '''
__ne__( (RxObject)arg1, (RxObject)arg2) -> bool :

    C++ signature :
        bool __ne__(class PyRxObject {lvalue},class PyRxObject)'''
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
    def className (self, *args, **kwargs):
      '''
className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def desc (self, *args, **kwargs):
      '''
desc() -> RxClass :

    C++ signature :
        class PyRxClass desc()'''
    ...
    def geometry (self, *args, **kwargs):
      '''
geometry( (ViewportDraw)arg1) -> ViewportGeometry :

    C++ signature :
        class PyGiViewportGeometry geometry(class PyGiViewportDraw {lvalue})'''
    ...
    def isA (self, *args, **kwargs):
      '''
isA( (RxObject)arg1) -> RxClass :

    C++ signature :
        class PyRxClass isA(class PyRxObject {lvalue})'''
    ...
    def isNull (self, *args, **kwargs):
      '''
isNull( (RxObject)arg1) -> bool :

    C++ signature :
        bool isNull(class PyRxObject {lvalue})'''
    ...
    def refCount (self, *args, **kwargs):
      '''
refCount( (RxObject)arg1) -> int :

    C++ signature :
        int refCount(class PyRxObject {lvalue})'''
    ...
    def subEntityTraits (self, *args, **kwargs):
      '''
subEntityTraits( (CommonDraw)arg1) -> SubEntityTraits :

    C++ signature :
        class PyGiSubEntityTraits subEntityTraits(class PyGiCommonDraw {lvalue})'''
    ...

class ViewportGeometry:
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
    def __eq__ (self, *args, **kwargs):
      '''
__eq__( (RxObject)arg1, (RxObject)arg2) -> bool :

    C++ signature :
        bool __eq__(class PyRxObject {lvalue},class PyRxObject)'''
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
    def __ne__ (self, *args, **kwargs):
      '''
__ne__( (RxObject)arg1, (RxObject)arg2) -> bool :

    C++ signature :
        bool __ne__(class PyRxObject {lvalue},class PyRxObject)'''
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
    def circle (self, *args, **kwargs):
      '''
circle( (Geometry)arg1, (Point3d)arg2, (float)arg3, (Vector3d)arg4) -> bool :

    C++ signature :
        bool circle(class PyGiGeometry {lvalue},class AcGePoint3d,double,class AcGeVector3d)

circle( (Geometry)arg1, (Point3d)arg2, (Point3d)arg3, (Point3d)arg4) -> bool :

    C++ signature :
        bool circle(class PyGiGeometry {lvalue},class AcGePoint3d,class AcGePoint3d,class AcGePoint3d)'''
    ...
    def circularArc (self, *args, **kwargs):
      '''
circularArc( (Geometry)arg1, (Point3d)arg2, (float)arg3, (Vector3d)arg4, (Vector3d)arg5, (float)arg6) -> bool :

    C++ signature :
        bool circularArc(class PyGiGeometry {lvalue},class AcGePoint3d,double,class AcGeVector3d,class AcGeVector3d,double)

circularArc( (Geometry)arg1, (Point3d)arg2, (float)arg3, (Vector3d)arg4, (Vector3d)arg5, (float)arg6, (AcGiArcType)arg7) -> bool :

    C++ signature :
        bool circularArc(class PyGiGeometry {lvalue},class AcGePoint3d,double,class AcGeVector3d,class AcGeVector3d,double,enum AcGiArcType)

circularArc( (Geometry)arg1, (Point3d)arg2, (Point3d)arg3, (Point3d)arg4) -> bool :

    C++ signature :
        bool circularArc(class PyGiGeometry {lvalue},class AcGePoint3d,class AcGePoint3d,class AcGePoint3d)

circularArc( (Geometry)arg1, (Point3d)arg2, (Point3d)arg3, (Point3d)arg4, (AcGiArcType)arg5) -> bool :

    C++ signature :
        bool circularArc(class PyGiGeometry {lvalue},class AcGePoint3d,class AcGePoint3d,class AcGePoint3d,enum AcGiArcType)'''
    ...
    def className (self, *args, **kwargs):
      '''
className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def desc (self, *args, **kwargs):
      '''
desc() -> RxClass :

    C++ signature :
        class PyRxClass desc()'''
    ...
    def draw (self, *args, **kwargs):
      '''
draw( (Geometry)arg1, (Drawable)arg2) -> bool :

    C++ signature :
        bool draw(class PyGiGeometry {lvalue},class PyGiDrawable {lvalue})'''
    ...
    def edge (self, *args, **kwargs):
      '''
edge( (Geometry)arg1, (list)arg2) -> bool :

    C++ signature :
        bool edge(class PyGiGeometry {lvalue},class boost::python::list)'''
    ...
    def ellipticalArc (self, *args, **kwargs):
      '''
ellipticalArc( (Geometry)arg1, (Point3d)arg2, (Vector3d)arg3, (float)arg4, (float)arg5, (float)arg6, (float)arg7, (float)arg8) -> bool :

    C++ signature :
        bool ellipticalArc(class PyGiGeometry {lvalue},class AcGePoint3d,class AcGeVector3d,double,double,double,double,double)

ellipticalArc( (Geometry)arg1, (Point3d)arg2, (Vector3d)arg3, (float)arg4, (float)arg5, (float)arg6, (float)arg7, (float)arg8, (AcGiArcType)arg9) -> bool :

    C++ signature :
        bool ellipticalArc(class PyGiGeometry {lvalue},class AcGePoint3d,class AcGeVector3d,double,double,double,double,double,enum AcGiArcType)'''
    ...
    def getModelToWorldTransform (self, *args, **kwargs):
      '''
getModelToWorldTransform( (Geometry)arg1) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d getModelToWorldTransform(class PyGiGeometry {lvalue})'''
    ...
    def getWorldToModelTransform (self, *args, **kwargs):
      '''
getWorldToModelTransform( (Geometry)arg1) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d getWorldToModelTransform(class PyGiGeometry {lvalue})'''
    ...
    def isA (self, *args, **kwargs):
      '''
isA( (RxObject)arg1) -> RxClass :

    C++ signature :
        class PyRxClass isA(class PyRxObject {lvalue})'''
    ...
    def isNull (self, *args, **kwargs):
      '''
isNull( (RxObject)arg1) -> bool :

    C++ signature :
        bool isNull(class PyRxObject {lvalue})'''
    ...
    def pline (self, *args, **kwargs):
      '''
pline( (Geometry)arg1, (Polyline)arg2) -> bool :

    C++ signature :
        bool pline(class PyGiGeometry {lvalue},class PyDbPolyline)

pline( (Geometry)arg1, (Polyline)arg2, (int)arg3, (int)arg4) -> bool :

    C++ signature :
        bool pline(class PyGiGeometry {lvalue},class PyDbPolyline,unsigned int,unsigned int)'''
    ...
    def polygon (self, *args, **kwargs):
      '''
polygon( (Geometry)arg1, (list)arg2) -> bool :

    C++ signature :
        bool polygon(class PyGiGeometry {lvalue},class boost::python::list)'''
    ...
    def polyline (self, *args, **kwargs):
      '''
polyline( (Geometry)arg1, (list)arg2) -> bool :

    C++ signature :
        bool polyline(class PyGiGeometry {lvalue},class boost::python::list)

polyline( (Geometry)arg1, (list)arg2, (Vector3d)arg3, (int)arg4) -> bool :

    C++ signature :
        bool polyline(class PyGiGeometry {lvalue},class boost::python::list,class AcGeVector3d,__int64)'''
    ...
    def popModelTransform (self, *args, **kwargs):
      '''
popModelTransform( (Geometry)arg1) -> bool :

    C++ signature :
        bool popModelTransform(class PyGiGeometry {lvalue})'''
    ...
    def pushModelTransform (self, *args, **kwargs):
      '''
pushModelTransform( (Geometry)arg1, (Vector3d)arg2) -> bool :

    C++ signature :
        bool pushModelTransform(class PyGiGeometry {lvalue},class AcGeVector3d)

pushModelTransform( (Geometry)arg1, (Matrix3d)arg2) -> bool :

    C++ signature :
        bool pushModelTransform(class PyGiGeometry {lvalue},class AcGeMatrix3d)'''
    ...
    def pushOrientationTransform (self, *args, **kwargs):
      '''
pushOrientationTransform( (Geometry)arg1, (AcGiOrientationTransformBehavior)arg2) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d pushOrientationTransform(class PyGiGeometry {lvalue},enum AcGiOrientationTransformBehavior)'''
    ...
    def pushPositionTransform (self, *args, **kwargs):
      '''
pushPositionTransform( (Geometry)arg1, (AcGiPositionTransformBehavior)arg2, (Point3d)arg3) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d pushPositionTransform(class PyGiGeometry {lvalue},enum AcGiPositionTransformBehavior,class AcGePoint3d)

pushPositionTransform( (Geometry)arg1, (AcGiPositionTransformBehavior)arg2, (Point2d)arg3) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d pushPositionTransform(class PyGiGeometry {lvalue},enum AcGiPositionTransformBehavior,class AcGePoint2d)'''
    ...
    def pushScaleTransform (self, *args, **kwargs):
      '''
pushScaleTransform( (Geometry)arg1, (AcGiScaleTransformBehavior)arg2, (Point3d)arg3) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d pushScaleTransform(class PyGiGeometry {lvalue},enum AcGiScaleTransformBehavior,class AcGePoint3d)

pushScaleTransform( (Geometry)arg1, (AcGiScaleTransformBehavior)arg2, (Point2d)arg3) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d pushScaleTransform(class PyGiGeometry {lvalue},enum AcGiScaleTransformBehavior,class AcGePoint2d)'''
    ...
    def ray (self, *args, **kwargs):
      '''
ray( (Geometry)arg1, (Point3d)arg2, (Point3d)arg3) -> bool :

    C++ signature :
        bool ray(class PyGiGeometry {lvalue},class AcGePoint3d,class AcGePoint3d)'''
    ...
    def refCount (self, *args, **kwargs):
      '''
refCount( (RxObject)arg1) -> int :

    C++ signature :
        int refCount(class PyRxObject {lvalue})'''
    ...
    def rowOfDots (self, *args, **kwargs):
      '''
rowOfDots( (Geometry)arg1, (int)arg2, (Point3d)arg3, (Vector3d)arg4) -> bool :

    C++ signature :
        bool rowOfDots(class PyGiGeometry {lvalue},int,class AcGePoint3d,class AcGeVector3d)'''
    ...
    def text (self, *args, **kwargs):
      '''
text( (Geometry)arg1, (Point3d)arg2, (Vector3d)arg3, (Vector3d)arg4, (float)arg5, (float)arg6, (float)arg7, (str)arg8) -> bool :

    C++ signature :
        bool text(class PyGiGeometry {lvalue},class AcGePoint3d,class AcGeVector3d,class AcGeVector3d,double,double,double,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def worldLine (self, *args, **kwargs):
      '''
worldLine( (Geometry)arg1, (Point3d)arg2, (Point3d)arg3) -> bool :

    C++ signature :
        bool worldLine(class PyGiGeometry {lvalue},class AcGePoint3d,class AcGePoint3d)'''
    ...
    def xline (self, *args, **kwargs):
      '''
xline( (Geometry)arg1, (Point3d)arg2, (Point3d)arg3) -> bool :

    C++ signature :
        bool xline(class PyGiGeometry {lvalue},class AcGePoint3d,class AcGePoint3d)'''
    ...

class WorldDraw:
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
    def __eq__ (self, *args, **kwargs):
      '''
__eq__( (RxObject)arg1, (RxObject)arg2) -> bool :

    C++ signature :
        bool __eq__(class PyRxObject {lvalue},class PyRxObject)'''
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
    def __ne__ (self, *args, **kwargs):
      '''
__ne__( (RxObject)arg1, (RxObject)arg2) -> bool :

    C++ signature :
        bool __ne__(class PyRxObject {lvalue},class PyRxObject)'''
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
    def className (self, *args, **kwargs):
      '''
className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def desc (self, *args, **kwargs):
      '''
desc() -> RxClass :

    C++ signature :
        class PyRxClass desc()'''
    ...
    def geometry (self, *args, **kwargs):
      '''
geometry( (WorldDraw)arg1) -> WorldGeometry :

    C++ signature :
        class PyGiWorldGeometry geometry(class PyGiWorldDraw {lvalue})'''
    ...
    def isA (self, *args, **kwargs):
      '''
isA( (RxObject)arg1) -> RxClass :

    C++ signature :
        class PyRxClass isA(class PyRxObject {lvalue})'''
    ...
    def isNull (self, *args, **kwargs):
      '''
isNull( (RxObject)arg1) -> bool :

    C++ signature :
        bool isNull(class PyRxObject {lvalue})'''
    ...
    def refCount (self, *args, **kwargs):
      '''
refCount( (RxObject)arg1) -> int :

    C++ signature :
        int refCount(class PyRxObject {lvalue})'''
    ...
    def subEntityTraits (self, *args, **kwargs):
      '''
subEntityTraits( (CommonDraw)arg1) -> SubEntityTraits :

    C++ signature :
        class PyGiSubEntityTraits subEntityTraits(class PyGiCommonDraw {lvalue})'''
    ...

class WorldGeometry:
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
    def __eq__ (self, *args, **kwargs):
      '''
__eq__( (RxObject)arg1, (RxObject)arg2) -> bool :

    C++ signature :
        bool __eq__(class PyRxObject {lvalue},class PyRxObject)'''
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
    def __ne__ (self, *args, **kwargs):
      '''
__ne__( (RxObject)arg1, (RxObject)arg2) -> bool :

    C++ signature :
        bool __ne__(class PyRxObject {lvalue},class PyRxObject)'''
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
    def circle (self, *args, **kwargs):
      '''
circle( (Geometry)arg1, (Point3d)arg2, (float)arg3, (Vector3d)arg4) -> bool :

    C++ signature :
        bool circle(class PyGiGeometry {lvalue},class AcGePoint3d,double,class AcGeVector3d)

circle( (Geometry)arg1, (Point3d)arg2, (Point3d)arg3, (Point3d)arg4) -> bool :

    C++ signature :
        bool circle(class PyGiGeometry {lvalue},class AcGePoint3d,class AcGePoint3d,class AcGePoint3d)'''
    ...
    def circularArc (self, *args, **kwargs):
      '''
circularArc( (Geometry)arg1, (Point3d)arg2, (float)arg3, (Vector3d)arg4, (Vector3d)arg5, (float)arg6) -> bool :

    C++ signature :
        bool circularArc(class PyGiGeometry {lvalue},class AcGePoint3d,double,class AcGeVector3d,class AcGeVector3d,double)

circularArc( (Geometry)arg1, (Point3d)arg2, (float)arg3, (Vector3d)arg4, (Vector3d)arg5, (float)arg6, (AcGiArcType)arg7) -> bool :

    C++ signature :
        bool circularArc(class PyGiGeometry {lvalue},class AcGePoint3d,double,class AcGeVector3d,class AcGeVector3d,double,enum AcGiArcType)

circularArc( (Geometry)arg1, (Point3d)arg2, (Point3d)arg3, (Point3d)arg4) -> bool :

    C++ signature :
        bool circularArc(class PyGiGeometry {lvalue},class AcGePoint3d,class AcGePoint3d,class AcGePoint3d)

circularArc( (Geometry)arg1, (Point3d)arg2, (Point3d)arg3, (Point3d)arg4, (AcGiArcType)arg5) -> bool :

    C++ signature :
        bool circularArc(class PyGiGeometry {lvalue},class AcGePoint3d,class AcGePoint3d,class AcGePoint3d,enum AcGiArcType)'''
    ...
    def className (self, *args, **kwargs):
      '''
className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def desc (self, *args, **kwargs):
      '''
desc() -> RxClass :

    C++ signature :
        class PyRxClass desc()'''
    ...
    def draw (self, *args, **kwargs):
      '''
draw( (Geometry)arg1, (Drawable)arg2) -> bool :

    C++ signature :
        bool draw(class PyGiGeometry {lvalue},class PyGiDrawable {lvalue})'''
    ...
    def edge (self, *args, **kwargs):
      '''
edge( (Geometry)arg1, (list)arg2) -> bool :

    C++ signature :
        bool edge(class PyGiGeometry {lvalue},class boost::python::list)'''
    ...
    def ellipticalArc (self, *args, **kwargs):
      '''
ellipticalArc( (Geometry)arg1, (Point3d)arg2, (Vector3d)arg3, (float)arg4, (float)arg5, (float)arg6, (float)arg7, (float)arg8) -> bool :

    C++ signature :
        bool ellipticalArc(class PyGiGeometry {lvalue},class AcGePoint3d,class AcGeVector3d,double,double,double,double,double)

ellipticalArc( (Geometry)arg1, (Point3d)arg2, (Vector3d)arg3, (float)arg4, (float)arg5, (float)arg6, (float)arg7, (float)arg8, (AcGiArcType)arg9) -> bool :

    C++ signature :
        bool ellipticalArc(class PyGiGeometry {lvalue},class AcGePoint3d,class AcGeVector3d,double,double,double,double,double,enum AcGiArcType)'''
    ...
    def getModelToWorldTransform (self, *args, **kwargs):
      '''
getModelToWorldTransform( (Geometry)arg1) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d getModelToWorldTransform(class PyGiGeometry {lvalue})'''
    ...
    def getWorldToModelTransform (self, *args, **kwargs):
      '''
getWorldToModelTransform( (Geometry)arg1) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d getWorldToModelTransform(class PyGiGeometry {lvalue})'''
    ...
    def isA (self, *args, **kwargs):
      '''
isA( (RxObject)arg1) -> RxClass :

    C++ signature :
        class PyRxClass isA(class PyRxObject {lvalue})'''
    ...
    def isNull (self, *args, **kwargs):
      '''
isNull( (RxObject)arg1) -> bool :

    C++ signature :
        bool isNull(class PyRxObject {lvalue})'''
    ...
    def pline (self, *args, **kwargs):
      '''
pline( (Geometry)arg1, (Polyline)arg2) -> bool :

    C++ signature :
        bool pline(class PyGiGeometry {lvalue},class PyDbPolyline)

pline( (Geometry)arg1, (Polyline)arg2, (int)arg3, (int)arg4) -> bool :

    C++ signature :
        bool pline(class PyGiGeometry {lvalue},class PyDbPolyline,unsigned int,unsigned int)'''
    ...
    def polygon (self, *args, **kwargs):
      '''
polygon( (Geometry)arg1, (list)arg2) -> bool :

    C++ signature :
        bool polygon(class PyGiGeometry {lvalue},class boost::python::list)'''
    ...
    def polyline (self, *args, **kwargs):
      '''
polyline( (Geometry)arg1, (list)arg2) -> bool :

    C++ signature :
        bool polyline(class PyGiGeometry {lvalue},class boost::python::list)

polyline( (Geometry)arg1, (list)arg2, (Vector3d)arg3, (int)arg4) -> bool :

    C++ signature :
        bool polyline(class PyGiGeometry {lvalue},class boost::python::list,class AcGeVector3d,__int64)'''
    ...
    def popModelTransform (self, *args, **kwargs):
      '''
popModelTransform( (Geometry)arg1) -> bool :

    C++ signature :
        bool popModelTransform(class PyGiGeometry {lvalue})'''
    ...
    def pushModelTransform (self, *args, **kwargs):
      '''
pushModelTransform( (Geometry)arg1, (Vector3d)arg2) -> bool :

    C++ signature :
        bool pushModelTransform(class PyGiGeometry {lvalue},class AcGeVector3d)

pushModelTransform( (Geometry)arg1, (Matrix3d)arg2) -> bool :

    C++ signature :
        bool pushModelTransform(class PyGiGeometry {lvalue},class AcGeMatrix3d)'''
    ...
    def pushOrientationTransform (self, *args, **kwargs):
      '''
pushOrientationTransform( (Geometry)arg1, (AcGiOrientationTransformBehavior)arg2) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d pushOrientationTransform(class PyGiGeometry {lvalue},enum AcGiOrientationTransformBehavior)'''
    ...
    def pushPositionTransform (self, *args, **kwargs):
      '''
pushPositionTransform( (Geometry)arg1, (AcGiPositionTransformBehavior)arg2, (Point3d)arg3) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d pushPositionTransform(class PyGiGeometry {lvalue},enum AcGiPositionTransformBehavior,class AcGePoint3d)

pushPositionTransform( (Geometry)arg1, (AcGiPositionTransformBehavior)arg2, (Point2d)arg3) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d pushPositionTransform(class PyGiGeometry {lvalue},enum AcGiPositionTransformBehavior,class AcGePoint2d)'''
    ...
    def pushScaleTransform (self, *args, **kwargs):
      '''
pushScaleTransform( (Geometry)arg1, (AcGiScaleTransformBehavior)arg2, (Point3d)arg3) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d pushScaleTransform(class PyGiGeometry {lvalue},enum AcGiScaleTransformBehavior,class AcGePoint3d)

pushScaleTransform( (Geometry)arg1, (AcGiScaleTransformBehavior)arg2, (Point2d)arg3) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d pushScaleTransform(class PyGiGeometry {lvalue},enum AcGiScaleTransformBehavior,class AcGePoint2d)'''
    ...
    def ray (self, *args, **kwargs):
      '''
ray( (Geometry)arg1, (Point3d)arg2, (Point3d)arg3) -> bool :

    C++ signature :
        bool ray(class PyGiGeometry {lvalue},class AcGePoint3d,class AcGePoint3d)'''
    ...
    def refCount (self, *args, **kwargs):
      '''
refCount( (RxObject)arg1) -> int :

    C++ signature :
        int refCount(class PyRxObject {lvalue})'''
    ...
    def rowOfDots (self, *args, **kwargs):
      '''
rowOfDots( (Geometry)arg1, (int)arg2, (Point3d)arg3, (Vector3d)arg4) -> bool :

    C++ signature :
        bool rowOfDots(class PyGiGeometry {lvalue},int,class AcGePoint3d,class AcGeVector3d)'''
    ...
    def text (self, *args, **kwargs):
      '''
text( (Geometry)arg1, (Point3d)arg2, (Vector3d)arg3, (Vector3d)arg4, (float)arg5, (float)arg6, (float)arg7, (str)arg8) -> bool :

    C++ signature :
        bool text(class PyGiGeometry {lvalue},class AcGePoint3d,class AcGeVector3d,class AcGeVector3d,double,double,double,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def worldLine (self, *args, **kwargs):
      '''
worldLine( (Geometry)arg1, (Point3d)arg2, (Point3d)arg3) -> bool :

    C++ signature :
        bool worldLine(class PyGiGeometry {lvalue},class AcGePoint3d,class AcGePoint3d)'''
    ...
    def xline (self, *args, **kwargs):
      '''
xline( (Geometry)arg1, (Point3d)arg2, (Point3d)arg3) -> bool :

    C++ signature :
        bool xline(class PyGiGeometry {lvalue},class AcGePoint3d,class AcGePoint3d)'''
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
