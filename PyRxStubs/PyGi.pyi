
class CommonDraw:
    def __eq__ (self, *args, **kwargs):
      '''
__eq__( (RxObject)arg1, (RxObject)arg2) -> bool :

    C++ signature :
        bool __eq__(class PyRxObject {lvalue},class PyRxObject)'''
    ...
    def __init__ (self, *args, **kwargs):
      '''Raises an exception
This class cannot be instantiated from Python
'''
    ...
    def __ne__ (self, *args, **kwargs):
      '''
__ne__( (RxObject)arg1, (RxObject)arg2) -> bool :

    C++ signature :
        bool __ne__(class PyRxObject {lvalue},class PyRxObject)'''
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

class Drawable:
    def __eq__ (self, *args, **kwargs):
      '''
__eq__( (RxObject)arg1, (RxObject)arg2) -> bool :

    C++ signature :
        bool __eq__(class PyRxObject {lvalue},class PyRxObject)'''
    ...
    def __init__ (self, *args, **kwargs):
      '''Raises an exception
This class cannot be instantiated from Python
'''
    ...
    def __ne__ (self, *args, **kwargs):
      '''
__ne__( (RxObject)arg1, (RxObject)arg2) -> bool :

    C++ signature :
        bool __ne__(class PyRxObject {lvalue},class PyRxObject)'''
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

class DrawableOverrule:
    def __eq__ (self, *args, **kwargs):
      '''
__eq__( (RxObject)arg1, (RxObject)arg2) -> bool :

    C++ signature :
        bool __eq__(class PyRxObject {lvalue},class PyRxObject)'''
    ...
    def __init__ (self, *args, **kwargs):
      '''
__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
    ...
    def __ne__ (self, *args, **kwargs):
      '''
__ne__( (RxObject)arg1, (RxObject)arg2) -> bool :

    C++ signature :
        bool __ne__(class PyRxObject {lvalue},class PyRxObject)'''
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

class Geometry:
    def __eq__ (self, *args, **kwargs):
      '''
__eq__( (RxObject)arg1, (RxObject)arg2) -> bool :

    C++ signature :
        bool __eq__(class PyRxObject {lvalue},class PyRxObject)'''
    ...
    def __init__ (self, *args, **kwargs):
      '''Raises an exception
This class cannot be instantiated from Python
'''
    ...
    def __ne__ (self, *args, **kwargs):
      '''
__ne__( (RxObject)arg1, (RxObject)arg2) -> bool :

    C++ signature :
        bool __ne__(class PyRxObject {lvalue},class PyRxObject)'''
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

class ViewportDraw:
    def __eq__ (self, *args, **kwargs):
      '''
__eq__( (RxObject)arg1, (RxObject)arg2) -> bool :

    C++ signature :
        bool __eq__(class PyRxObject {lvalue},class PyRxObject)'''
    ...
    def __init__ (self, *args, **kwargs):
      '''Raises an exception
This class cannot be instantiated from Python
'''
    ...
    def __ne__ (self, *args, **kwargs):
      '''
__ne__( (RxObject)arg1, (RxObject)arg2) -> bool :

    C++ signature :
        bool __ne__(class PyRxObject {lvalue},class PyRxObject)'''
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
    def viewportGeometry (self, *args, **kwargs):
      '''
viewportGeometry( (ViewportDraw)arg1) -> ViewportGeometry :

    C++ signature :
        class PyGiViewportGeometry viewportGeometry(class PyGiViewportDraw {lvalue})'''
    ...

class ViewportGeometry:
    def __eq__ (self, *args, **kwargs):
      '''
__eq__( (RxObject)arg1, (RxObject)arg2) -> bool :

    C++ signature :
        bool __eq__(class PyRxObject {lvalue},class PyRxObject)'''
    ...
    def __init__ (self, *args, **kwargs):
      '''Raises an exception
This class cannot be instantiated from Python
'''
    ...
    def __ne__ (self, *args, **kwargs):
      '''
__ne__( (RxObject)arg1, (RxObject)arg2) -> bool :

    C++ signature :
        bool __ne__(class PyRxObject {lvalue},class PyRxObject)'''
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

class WorldDraw:
    def __eq__ (self, *args, **kwargs):
      '''
__eq__( (RxObject)arg1, (RxObject)arg2) -> bool :

    C++ signature :
        bool __eq__(class PyRxObject {lvalue},class PyRxObject)'''
    ...
    def __init__ (self, *args, **kwargs):
      '''Raises an exception
This class cannot be instantiated from Python
'''
    ...
    def __ne__ (self, *args, **kwargs):
      '''
__ne__( (RxObject)arg1, (RxObject)arg2) -> bool :

    C++ signature :
        bool __ne__(class PyRxObject {lvalue},class PyRxObject)'''
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
    def worldGeometry (self, *args, **kwargs):
      '''
worldGeometry( (WorldDraw)arg1) -> WorldGeometry :

    C++ signature :
        class PyGiWorldGeometry worldGeometry(class PyGiWorldDraw {lvalue})'''
    ...

class WorldGeometry:
    def __eq__ (self, *args, **kwargs):
      '''
__eq__( (RxObject)arg1, (RxObject)arg2) -> bool :

    C++ signature :
        bool __eq__(class PyRxObject {lvalue},class PyRxObject)'''
    ...
    def __init__ (self, *args, **kwargs):
      '''Raises an exception
This class cannot be instantiated from Python
'''
    ...
    def __ne__ (self, *args, **kwargs):
      '''
__ne__( (RxObject)arg1, (RxObject)arg2) -> bool :

    C++ signature :
        bool __ne__(class PyRxObject {lvalue},class PyRxObject)'''
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
