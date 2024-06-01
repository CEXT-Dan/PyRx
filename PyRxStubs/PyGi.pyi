import PyRx
import PyGe
import PyGi
import PyGs
import PyDb
import PyAp
import PyEd
import PyPl
from typing import overload
from typing import Any

class ArcType(object):
    def __add__ (self, value, /) :
      '''Return self+value.'''
    ...
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
    def __mul__ (self, value, /) :
      '''Return self*value.'''
    ...
    def __rmul__ (self, value, /) :
      '''Return value*self.'''
    ...
    def __sub__ (self, value, /) :
      '''Return self-value.'''
    ...
    def __truediv__ (self, value, /) :
      '''Return self/value.'''
    ...
    def kAcGiArcChord (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kAcGiArcSector (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kAcGiArcSimple (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def name (self, *args, **kwargs)-> None :
      '''None'''
    ...

class CommonDraw(PyRx.RxObject):
    def __init__ (self, *args, **kwargs)-> None :
      '''Raises an exception
This class cannot be instantiated from Python'''
    ...

    @staticmethod
    def className ()-> str :
      '''                             '''
    ...
    def comparedTo (self, other: PyRx.RxObject)-> PyRx.Ordering :
      '''Function usage:This function is intended to allow classes to provide a means to compare class objects much the way strcmp() compares character strings.The object pointed to by other is compared with this object. The result of the comparison is returned.The possible AcRx::Ordering types are:AcRx::kLessThanAcRx::kEqualAcRx::kGreaterThanAcRx::kNotOrderableThe AcRx::kNotOrderable type is there because C++ classes often cannot support object value comparison.Function implementation in derived classes:There are no restrictions or expectations on how this function is implemented. Each class will have its own requirements for comparison.Default implementation:Simply returns AcRx::kNotOrderable since many C++ classes cannot support object value comparison.'''
    ...
    def copyFrom (self, other: PyRx.RxObject)-> None :
      '''Function usage:Copies the contents of other into the messaged object, whenever feasible. Function implementation in derived classes:If implemented, this function needs to be able to read the data in the object pointed to by other and copy any or all data as appropriate into this object. There is no requirement that the object pointed to by other and this object be of the same class, but that is the generally assumed condition.Default implementation: Because this function must be overridden to have any meaning, a fatal error will be caused when calling the default implementation. '''
    ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
      '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
    ...
    def dispose (self)-> None :
      '''                             '''
    ...
    def implRefCount (self)-> int :
      '''                             '''
    ...
    def isA (self)-> PyRx.RxClass :
      '''Function usage:For each class registered with ObjectARX, the implementation of this function is to return a pointer to the AcRxClass object for the class of the object in which this method is called. For classes not registered with ObjectARX, this method has no meaning.Function implementation in derived classes:This function is overridden in all derived classes. The AcRx macros declare and define this function, so that the override is taken care of as part of using the macros. The implementation of this function is simply to return ::desc(). For example. the implementation for AcDbLine would be:return AcDbLine::desc();Default implementation for AcRxObject:  { return AcRxObject::desc(); }'''
    ...
    def isDragging (self)-> bool :
      '''                             '''
    ...
    def isKindOf (self, rhs: PyRx.RxClass)-> bool :
      '''Returns true if "this" object is of a member of either the class represented by aClass, or a class derived from aClass. '''
    ...
    def isNullObj (self)-> bool :
      '''                             '''
    ...
    def keepAlive (self, flag: bool)-> None :
      '''                             '''
    ...
    def queryX (self, rhs: PyRx.RxClass)-> PyRx.RxObject :
      '''This method searches for a protocol extension object associated with this object.The method begins the search by examining the AcRxClass object associated with this object, and if no protocol extension object is found, the search continues in the base class of the object's class and so on up the inheritance tree for the class. This procedure provides a form of protocol extension inheritance. An object's AcRxClass member may be found by using the class's isA() method.If the search for a protocol extension object is unsuccessful, then NULL is returned.'''
    ...
    def regenAbort (self)-> bool :
      '''                             '''
    ...
    def regenType (self)-> PyGi.RegenType :
      '''                             '''
    ...
    def subEntityTraits (self)-> PyGi.SubEntityTraits :
      '''                             '''
    ...

class DefaultLightingType(object):
    def __add__ (self, value, /) :
      '''Return self+value.'''
    ...
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
    def __mul__ (self, value, /) :
      '''Return self*value.'''
    ...
    def __rmul__ (self, value, /) :
      '''Return value*self.'''
    ...
    def __sub__ (self, value, /) :
      '''Return self-value.'''
    ...
    def __truediv__ (self, value, /) :
      '''Return self/value.'''
    ...
    def kBackLighting (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kOneDistantLight (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kTwoDistantLights (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def name (self, *args, **kwargs)-> None :
      '''None'''
    ...

class DrawFlags(object):
    def __add__ (self, value, /) :
      '''Return self+value.'''
    ...
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
    def __mul__ (self, value, /) :
      '''Return self*value.'''
    ...
    def __rmul__ (self, value, /) :
      '''Return value*self.'''
    ...
    def __sub__ (self, value, /) :
      '''Return self-value.'''
    ...
    def __truediv__ (self, value, /) :
      '''Return self/value.'''
    ...
    def kDrawFillSelectionWindow (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kDrawFillTextBoundaryEnd (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kDrawFillTextBoundaryStart (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kDrawFrontfacesOnly (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kDrawGradientFill (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kDrawHatchGroup (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kDrawIsInWCS (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kDrawNoForceByLayer (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kDrawNoImageFrame (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kDrawNoLineWeight (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kDrawNoOptimization (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kDrawSolidFill (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kDrawUseAcGiEntityForDgnLineType (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kNoDrawFlags (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def name (self, *args, **kwargs)-> None :
      '''None'''
    ...

class Drawable(PyRx.RxObject):
    def __init__ (self, *args, **kwargs)-> None :
      '''Raises an exception
This class cannot be instantiated from Python'''
    ...
    def bounds (self, ext: PyDb.Extents)-> bool :
      '''                             '''
    ...

    @staticmethod
    def className ()-> str :
      '''                             '''
    ...
    def comparedTo (self, other: PyRx.RxObject)-> PyRx.Ordering :
      '''Function usage:This function is intended to allow classes to provide a means to compare class objects much the way strcmp() compares character strings.The object pointed to by other is compared with this object. The result of the comparison is returned.The possible AcRx::Ordering types are:AcRx::kLessThanAcRx::kEqualAcRx::kGreaterThanAcRx::kNotOrderableThe AcRx::kNotOrderable type is there because C++ classes often cannot support object value comparison.Function implementation in derived classes:There are no restrictions or expectations on how this function is implemented. Each class will have its own requirements for comparison.Default implementation:Simply returns AcRx::kNotOrderable since many C++ classes cannot support object value comparison.'''
    ...
    def copyFrom (self, other: PyRx.RxObject)-> None :
      '''Function usage:Copies the contents of other into the messaged object, whenever feasible. Function implementation in derived classes:If implemented, this function needs to be able to read the data in the object pointed to by other and copy any or all data as appropriate into this object. There is no requirement that the object pointed to by other and this object be of the same class, but that is the generally assumed condition.Default implementation: Because this function must be overridden to have any meaning, a fatal error will be caused when calling the default implementation. '''
    ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
      '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
    ...
    def dispose (self)-> None :
      '''                             '''
    ...
    def drawableType (self)-> PyGi.GiDrawableType :
      '''                             '''
    ...
    def id (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def implRefCount (self)-> int :
      '''                             '''
    ...
    def isA (self)-> PyRx.RxClass :
      '''Function usage:For each class registered with ObjectARX, the implementation of this function is to return a pointer to the AcRxClass object for the class of the object in which this method is called. For classes not registered with ObjectARX, this method has no meaning.Function implementation in derived classes:This function is overridden in all derived classes. The AcRx macros declare and define this function, so that the override is taken care of as part of using the macros. The implementation of this function is simply to return ::desc(). For example. the implementation for AcDbLine would be:return AcDbLine::desc();Default implementation for AcRxObject:  { return AcRxObject::desc(); }'''
    ...
    def isKindOf (self, rhs: PyRx.RxClass)-> bool :
      '''Returns true if "this" object is of a member of either the class represented by aClass, or a class derived from aClass. '''
    ...
    def isNullObj (self)-> bool :
      '''                             '''
    ...
    def isPersistent (self)-> bool :
      '''                             '''
    ...
    def keepAlive (self, flag: bool)-> None :
      '''                             '''
    ...
    def queryX (self, rhs: PyRx.RxClass)-> PyRx.RxObject :
      '''This method searches for a protocol extension object associated with this object.The method begins the search by examining the AcRxClass object associated with this object, and if no protocol extension object is found, the search continues in the base class of the object's class and so on up the inheritance tree for the class. This procedure provides a form of protocol extension inheritance. An object's AcRxClass member may be found by using the class's isA() method.If the search for a protocol extension object is unsuccessful, then NULL is returned.'''
    ...
    def rolloverHit (self, nSubentId: int, nMouseFlags: int, bReset: bool)-> bool :
      '''                             '''
    ...
    def setAttributes (self, traits: PyGi.DrawableTraits)-> int :
      '''                             '''
    ...
    def viewportDraw (self, vpdraw: PyGi.ViewportDraw)-> None :
      '''                             '''
    ...
    def viewportDrawLogicalFlags (self, vpdraw: PyGi.ViewportDraw)-> int :
      '''                             '''
    ...
    def worldDraw (self, wdraw: PyGi.WorldDraw)-> bool :
      '''                             '''
    ...

class DrawableOverrule(PyRx.Overrule):
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
    ...

    @staticmethod
    def addOverrule (rxClass: PyRx.RxClass,overrule: PyRx.Overrule)-> None :
      '''                             '''
    ...

    @staticmethod
    def addOverruleLast (rxClass: PyRx.RxClass,overrule: PyRx.Overrule,addLast: bool)-> None :
      '''                             '''
    ...
    def baseViewportDraw (self, *args, **kwargs)-> None :
      '''baseViewportDraw( (DrawableOverrule)arg1, (Drawable)arg2, (ViewportDraw)arg3) -> None :

    C++ signature :
        void baseViewportDraw(class PyGiDrawableOverrule {lvalue},class PyGiDrawable {lvalue},class PyGiViewportDraw {lvalue})'''
    ...
    def baseViewportDrawLogicalFlags (self, *args, **kwargs)-> int :
      '''baseViewportDrawLogicalFlags( (DrawableOverrule)arg1, (Drawable)arg2, (ViewportDraw)arg3) -> int :

    C++ signature :
        unsigned int baseViewportDrawLogicalFlags(class PyGiDrawableOverrule {lvalue},class PyGiDrawable {lvalue},class PyGiViewportDraw {lvalue})'''
    ...
    def baseWorldDraw (self, *args, **kwargs)-> bool :
      '''baseWorldDraw( (DrawableOverrule)arg1, (Drawable)arg2, (WorldDraw)arg3) -> bool :

    C++ signature :
        bool baseWorldDraw(class PyGiDrawableOverrule {lvalue},class PyGiDrawable {lvalue},class PyGiWorldDraw {lvalue})'''
    ...
    def className (self, *args, **kwargs)-> str :
      '''className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def comparedTo (self, other: PyRx.RxObject)-> PyRx.Ordering :
      '''Function usage:This function is intended to allow classes to provide a means to compare class objects much the way strcmp() compares character strings.The object pointed to by other is compared with this object. The result of the comparison is returned.The possible AcRx::Ordering types are:AcRx::kLessThanAcRx::kEqualAcRx::kGreaterThanAcRx::kNotOrderableThe AcRx::kNotOrderable type is there because C++ classes often cannot support object value comparison.Function implementation in derived classes:There are no restrictions or expectations on how this function is implemented. Each class will have its own requirements for comparison.Default implementation:Simply returns AcRx::kNotOrderable since many C++ classes cannot support object value comparison.'''
    ...
    def copyFrom (self, other: PyRx.RxObject)-> None :
      '''Function usage:Copies the contents of other into the messaged object, whenever feasible. Function implementation in derived classes:If implemented, this function needs to be able to read the data in the object pointed to by other and copy any or all data as appropriate into this object. There is no requirement that the object pointed to by other and this object be of the same class, but that is the generally assumed condition.Default implementation: Because this function must be overridden to have any meaning, a fatal error will be caused when calling the default implementation. '''
    ...
    def desc (self, *args, **kwargs)-> PyRx.RxClass :
      '''desc() -> RxClass :

    C++ signature :
        class PyRxClass desc()'''
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
      '''Function usage:For each class registered with ObjectARX, the implementation of this function is to return a pointer to the AcRxClass object for the class of the object in which this method is called. For classes not registered with ObjectARX, this method has no meaning.Function implementation in derived classes:This function is overridden in all derived classes. The AcRx macros declare and define this function, so that the override is taken care of as part of using the macros. The implementation of this function is simply to return ::desc(). For example. the implementation for AcDbLine would be:return AcDbLine::desc();Default implementation for AcRxObject:  { return AcRxObject::desc(); }'''
    ...
    def isApplicable (self, *args, **kwargs)-> bool :
      '''isApplicable( (DrawableOverrule)arg1, (RxObject)arg2) -> bool :

    C++ signature :
        bool isApplicable(class PyGiDrawableOverrule {lvalue},class PyRxObject {lvalue})'''
    ...
    def isKindOf (self, rhs: PyRx.RxClass)-> bool :
      '''Returns true if "this" object is of a member of either the class represented by aClass, or a class derived from aClass. '''
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
      '''This method searches for a protocol extension object associated with this object.The method begins the search by examining the AcRxClass object associated with this object, and if no protocol extension object is found, the search continues in the base class of the object's class and so on up the inheritance tree for the class. This procedure provides a form of protocol extension inheritance. An object's AcRxClass member may be found by using the class's isA() method.If the search for a protocol extension object is unsuccessful, then NULL is returned.'''
    ...

    @staticmethod
    def removeOverrule (rxClass: PyRx.RxClass,overrule: PyRx.Overrule)-> None :
      '''                             '''
    ...
    def setAttributes (self, *args, **kwargs)-> int :
      '''setAttributes( (DrawableOverrule)arg1, (Drawable)arg2, (DrawableTraits)arg3) -> int :

    C++ signature :
        unsigned int setAttributes(class PyGiDrawableOverrule {lvalue},class PyGiDrawable {lvalue},class PyGiDrawableTraits {lvalue})'''
    ...
    def setIsOverruling (self, flag: bool)-> None :
      '''                             '''
    ...
    def viewportDraw (self, *args, **kwargs)-> None :
      '''viewportDraw( (DrawableOverrule)arg1, (Drawable)arg2, (ViewportDraw)arg3) -> None :

    C++ signature :
        void viewportDraw(class PyGiDrawableOverrule {lvalue},class PyGiDrawable {lvalue},class PyGiViewportDraw {lvalue})'''
    ...
    def viewportDrawLogicalFlags (self, *args, **kwargs)-> int :
      '''viewportDrawLogicalFlags( (DrawableOverrule)arg1, (Drawable)arg2, (ViewportDraw)arg3) -> int :

    C++ signature :
        unsigned int viewportDrawLogicalFlags(class PyGiDrawableOverrule {lvalue},class PyGiDrawable {lvalue},class PyGiViewportDraw {lvalue})'''
    ...
    def worldDraw (self, *args, **kwargs)-> bool :
      '''worldDraw( (DrawableOverrule)arg1, (Drawable)arg2, (WorldDraw)arg3) -> bool :

    C++ signature :
        bool worldDraw(class PyGiDrawableOverrule {lvalue},class PyGiDrawable {lvalue},class PyGiWorldDraw {lvalue})'''
    ...

class DrawableTraits(SubEntityTraits):
    def __init__ (self, *args, **kwargs)-> None :
      '''Raises an exception
This class cannot be instantiated from Python'''
    ...
    def className (self, *args, **kwargs)-> str :
      '''className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def color (self)-> int :
      '''                             '''
    ...
    def comparedTo (self, other: PyRx.RxObject)-> PyRx.Ordering :
      '''Function usage:This function is intended to allow classes to provide a means to compare class objects much the way strcmp() compares character strings.The object pointed to by other is compared with this object. The result of the comparison is returned.The possible AcRx::Ordering types are:AcRx::kLessThanAcRx::kEqualAcRx::kGreaterThanAcRx::kNotOrderableThe AcRx::kNotOrderable type is there because C++ classes often cannot support object value comparison.Function implementation in derived classes:There are no restrictions or expectations on how this function is implemented. Each class will have its own requirements for comparison.Default implementation:Simply returns AcRx::kNotOrderable since many C++ classes cannot support object value comparison.'''
    ...
    def copyFrom (self, other: PyRx.RxObject)-> None :
      '''Function usage:Copies the contents of other into the messaged object, whenever feasible. Function implementation in derived classes:If implemented, this function needs to be able to read the data in the object pointed to by other and copy any or all data as appropriate into this object. There is no requirement that the object pointed to by other and this object be of the same class, but that is the generally assumed condition.Default implementation: Because this function must be overridden to have any meaning, a fatal error will be caused when calling the default implementation. '''
    ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
      '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
    ...
    def dispose (self)-> None :
      '''                             '''
    ...
    def drawFlags (self)-> int :
      '''                             '''
    ...
    def fillType (self)-> PyGi.FillType :
      '''                             '''
    ...
    def getPlotStyleNameId (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def implRefCount (self)-> int :
      '''                             '''
    ...
    def isA (self)-> PyRx.RxClass :
      '''Function usage:For each class registered with ObjectARX, the implementation of this function is to return a pointer to the AcRxClass object for the class of the object in which this method is called. For classes not registered with ObjectARX, this method has no meaning.Function implementation in derived classes:This function is overridden in all derived classes. The AcRx macros declare and define this function, so that the override is taken care of as part of using the macros. The implementation of this function is simply to return ::desc(). For example. the implementation for AcDbLine would be:return AcDbLine::desc();Default implementation for AcRxObject:  { return AcRxObject::desc(); }'''
    ...
    def isKindOf (self, rhs: PyRx.RxClass)-> bool :
      '''Returns true if "this" object is of a member of either the class represented by aClass, or a class derived from aClass. '''
    ...
    def isNullObj (self)-> bool :
      '''                             '''
    ...
    def keepAlive (self, flag: bool)-> None :
      '''                             '''
    ...
    def layerId (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def lineTypeId (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def lineTypeScale (self)-> float :
      '''                             '''
    ...
    def lineWeight (self)-> PyDb.LineWeight :
      '''                             '''
    ...
    def materialId (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def queryX (self, rhs: PyRx.RxClass)-> PyRx.RxObject :
      '''This method searches for a protocol extension object associated with this object.The method begins the search by examining the AcRxClass object associated with this object, and if no protocol extension object is found, the search continues in the base class of the object's class and so on up the inheritance tree for the class. This procedure provides a form of protocol extension inheritance. An object's AcRxClass member may be found by using the class's isA() method.If the search for a protocol extension object is unsuccessful, then NULL is returned.'''
    ...
    def sectionable (self)-> bool :
      '''                             '''
    ...
    def selectionGeom (self)-> bool :
      '''                             '''
    ...
    def setColor (self, val: int)-> None :
      '''                             '''
    ...
    def setDrawFlags (self, flags: int)-> None :
      '''                             '''
    ...
    def setFillType (self, val: PyGi.FillType)-> None :
      '''                             '''
    ...
    def setLayer (self, id: PyDb.ObjectId)-> None :
      '''                             '''
    ...
    def setLineType (self, id: PyDb.ObjectId)-> None :
      '''                             '''
    ...
    def setLineTypeScale (self, val: float=1.0)-> None :
      '''                             '''
    ...
    def setLineWeight (self, val: PyDb.LineWeight)-> None :
      '''                             '''
    ...
    def setMaterial (self, id: PyDb.ObjectId)-> None :
      '''                             '''
    ...
    def setPlotStyleName (self, val: PyDb.PlotStyleNameType, id: PyDb.ObjectId=None)-> None :
      '''                             '''
    ...
    def setSectionable (self, val: bool)-> None :
      '''                             '''
    ...
    def setSelectionGeom (self, val: bool)-> None :
      '''                             '''
    ...
    def setSelectionMarker (self, val: int)-> None :
      '''                             '''
    ...
    def setShadowFlags (self, val: PyGi.ShadowFlags)-> None :
      '''                             '''
    ...
    def setThickness (self, val: float)-> None :
      '''                             '''
    ...
    def setTransparency (self, val: PyDb.Transparency)-> None :
      '''                             '''
    ...
    def setTrueColor (self, clr: PyDb.EntityColor)-> None :
      '''                             '''
    ...
    def setVisualStyle (self, id: PyDb.ObjectId)-> None :
      '''                             '''
    ...
    def setupForEntity (self, entity: PyDb.Entity)-> None :
      '''This call initializes the entire AcGiSubEntityTraits and AcGiDrawableTraits from the entity. This is more efficient than setting each property individually. The default implemetation of AcDbEntity::setAttributes() uses this method.If you are implementing AcGi you need not implement this method since and implementation is supplied which delegates to the setXXX methods in AcGiSubEntityTraits.'''
    ...
    def shadowFlags (self)-> PyGi.ShadowFlags :
      '''                             '''
    ...
    def thickness (self)-> float :
      '''                             '''
    ...
    def transparency (self)-> PyDb.Transparency :
      '''                             '''
    ...
    def trueColor (self)-> PyDb.EntityColor :
      '''                             '''
    ...
    def visualStyle (self)-> PyDb.ObjectId :
      '''                             '''
    ...

class FillType(object):
    def __add__ (self, value, /) :
      '''Return self+value.'''
    ...
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
    def __mul__ (self, value, /) :
      '''Return self*value.'''
    ...
    def __rmul__ (self, value, /) :
      '''Return value*self.'''
    ...
    def __sub__ (self, value, /) :
      '''Return self-value.'''
    ...
    def __truediv__ (self, value, /) :
      '''Return self/value.'''
    ...
    def kAcGiFillAlways (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kAcGiFillNever (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def name (self, *args, **kwargs)-> None :
      '''None'''
    ...

class Geometry(PyRx.RxObject):
    def __init__ (self, *args, **kwargs)-> None :
      '''Raises an exception
This class cannot be instantiated from Python'''
    ...

    @overload
    def circle (self, center: PyGe.Point3d, radius: float, normal: PyGe.Vector3d)-> bool : ...
    @overload
    def circle (self, p1: PyGe.Point3d, p2: PyGe.Point3d, p3: PyGe.Point3d)-> bool : ...
    def circle (self, *args, **kwargs)-> bool :
      '''Overloads:
    - center: PyGe.Point3d, radius: float, normal: PyGe.Vector3d
    - p1: PyGe.Point3d, p2: PyGe.Point3d, p3: PyGe.Point3d
    '''
    ...

    @overload
    def circularArc (self, center: PyGe.Point3d, radius: float, normal: PyGe.Vector3d, startVector: PyGe.Vector3d, sweepAngle: float)-> bool : ...
    @overload
    def circularArc (self, center: PyGe.Point3d, radius: float, normal: PyGe.Vector3d, startVector: PyGe.Vector3d, sweepAngle: float, arcType: PyGe.ArcType)-> bool : ...
    @overload
    def circularArc (self, p1: PyGe.Point3d, p2: PyGe.Point3d, p3: PyGe.Point3d)-> bool : ...
    @overload
    def circularArc (self, p1: PyGe.Point3d, p2: PyGe.Point3d, p3: PyGe.Point3d, arcType: PyGe.ArcType)-> bool : ...
    def circularArc (self, *args, **kwargs)-> bool :
      '''Overloads:
    - center: PyGe.Point3d, radius: float, normal: PyGe.Vector3d, startVector: PyGe.Vector3d, sweepAngle: float
    - center: PyGe.Point3d, radius: float, normal: PyGe.Vector3d, startVector: PyGe.Vector3d, sweepAngle: float, arcType: PyGe.ArcType
    - p1: PyGe.Point3d, p2: PyGe.Point3d, p3: PyGe.Point3d
    - p1: PyGe.Point3d, p2: PyGe.Point3d, p3: PyGe.Point3d, arcType: PyGe.ArcType
    '''
    ...
    def className (self, *args, **kwargs)-> str :
      '''className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def comparedTo (self, other: PyRx.RxObject)-> PyRx.Ordering :
      '''Function usage:This function is intended to allow classes to provide a means to compare class objects much the way strcmp() compares character strings.The object pointed to by other is compared with this object. The result of the comparison is returned.The possible AcRx::Ordering types are:AcRx::kLessThanAcRx::kEqualAcRx::kGreaterThanAcRx::kNotOrderableThe AcRx::kNotOrderable type is there because C++ classes often cannot support object value comparison.Function implementation in derived classes:There are no restrictions or expectations on how this function is implemented. Each class will have its own requirements for comparison.Default implementation:Simply returns AcRx::kNotOrderable since many C++ classes cannot support object value comparison.'''
    ...
    def copyFrom (self, other: PyRx.RxObject)-> None :
      '''Function usage:Copies the contents of other into the messaged object, whenever feasible. Function implementation in derived classes:If implemented, this function needs to be able to read the data in the object pointed to by other and copy any or all data as appropriate into this object. There is no requirement that the object pointed to by other and this object be of the same class, but that is the generally assumed condition.Default implementation: Because this function must be overridden to have any meaning, a fatal error will be caused when calling the default implementation. '''
    ...
    def desc (self, *args, **kwargs)-> PyRx.RxClass :
      '''desc() -> RxClass :

    C++ signature :
        class PyRxClass desc()'''
    ...
    def dispose (self)-> None :
      '''                             '''
    ...
    def draw (self, drawable : PyGi.Drawable)-> bool :
      '''                             '''
    ...
    def edge (self, edgeList : list[PyGe.Curve2d])-> bool :
      '''                             '''
    ...
    def ellipticalArc (self, center:PyGe.Point3d, norm:PyGe.Vector3d, majAxisLen:float, minAxisLen:float, startDeg:float, endDeg:float, tilt:float, arcType:ArcType=kAcGiArcSimple)-> bool :
      '''                             '''
    ...
    def getModelToWorldTransform (self)-> PyGe.Matrix3d :
      '''                             '''
    ...
    def getWorldToModelTransform (self)-> PyGe.Matrix3d :
      '''                             '''
    ...
    def implRefCount (self)-> int :
      '''                             '''
    ...
    def isA (self)-> PyRx.RxClass :
      '''Function usage:For each class registered with ObjectARX, the implementation of this function is to return a pointer to the AcRxClass object for the class of the object in which this method is called. For classes not registered with ObjectARX, this method has no meaning.Function implementation in derived classes:This function is overridden in all derived classes. The AcRx macros declare and define this function, so that the override is taken care of as part of using the macros. The implementation of this function is simply to return ::desc(). For example. the implementation for AcDbLine would be:return AcDbLine::desc();Default implementation for AcRxObject:  { return AcRxObject::desc(); }'''
    ...
    def isKindOf (self, rhs: PyRx.RxClass)-> bool :
      '''Returns true if "this" object is of a member of either the class represented by aClass, or a class derived from aClass. '''
    ...
    def isNullObj (self)-> bool :
      '''                             '''
    ...
    def keepAlive (self, flag: bool)-> None :
      '''                             '''
    ...
    def pline (self, p1 : PyDb.Polyline, fromIndex : int, numSegs : int)-> bool :
      '''                             '''
    ...
    def polygon (self, vertexList : list[PyGe.Point3d])-> bool :
      '''                             '''
    ...
    def polyline (self, vertexList : list[PyGe.Point3d], normal : PyGe.Vector3d=default, marker : int=default)-> bool :
      '''                             '''
    ...
    def popModelTransform (self)-> bool :
      '''                             '''
    ...
    def pushModelTransform (self, val : PyGe.Vector3d|PyGe.Matrix3d)-> bool :
      '''                             '''
    ...
    def pushOrientationTransform (self,  behavior : PyGi.AcGiOrientationTransformBehavior)-> PyGe.Matrix3d :
      '''                             '''
    ...
    def pushPositionTransform (self, behavior : PyGi.AcGiPositionTransformBehavior,  offset : PyGe.Point2d|PyGe.Point2d)-> PyGe.Matrix3d :
      '''                             '''
    ...
    def pushScaleTransform (self, behavior : PyGi.AcGiScaleTransformBehavior,  extents : PyGe.Point2d|PyGe.Point2d)-> PyGe.Matrix3d :
      '''                             '''
    ...
    def queryX (self, rhs: PyRx.RxClass)-> PyRx.RxObject :
      '''This method searches for a protocol extension object associated with this object.The method begins the search by examining the AcRxClass object associated with this object, and if no protocol extension object is found, the search continues in the base class of the object's class and so on up the inheritance tree for the class. This procedure provides a form of protocol extension inheritance. An object's AcRxClass member may be found by using the class's isA() method.If the search for a protocol extension object is unsuccessful, then NULL is returned.'''
    ...
    def ray (self, p1 : PyGe.Point3d, p2 : PyGe.Point3d)-> bool :
      '''                             '''
    ...
    def rowOfDots (self, count : int, start: PyGe.Point3d, step : PyGe.Vector3d)-> bool :
      '''                             '''
    ...
    def text (self, pos : PyGe.Point3d, normal : PyGe.Vector3d, direction : PyGe.Vector3d, height : float, width : float, oblique : float, msg : str)-> bool :
      '''                             '''
    ...
    def worldLine (self, p1 : PyGe.Point3d, p2 : PyGe.Point3d)-> bool :
      '''                             '''
    ...
    def xline (self, p1 : PyGe.Point3d, p2 : PyGe.Point3d)-> bool :
      '''                             '''
    ...

class GiAttributesFlags(object):
    def __add__ (self, value, /) :
      '''Return self+value.'''
    ...
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
    def __mul__ (self, value, /) :
      '''Return self*value.'''
    ...
    def __rmul__ (self, value, /) :
      '''Return value*self.'''
    ...
    def __sub__ (self, value, /) :
      '''Return self-value.'''
    ...
    def __truediv__ (self, value, /) :
      '''Return self/value.'''
    ...
    def kDrawableBlockDependentViewportDraw (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kDrawableHasAttributes (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kDrawableIsAnEntity (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kDrawableIsCompoundObject (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kDrawableIsDimension (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kDrawableIsExternalReference (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kDrawableIsInvisible (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kDrawableMergeControlOff (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kDrawableNone (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kDrawableNotAllowLCS (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kDrawableNotPlottable (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kDrawableRegenDraw (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kDrawableRegenTypeDependentGeometry (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kDrawableShadedDisplaySingleLOD (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kDrawableStandardDisplaySingleLOD (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kDrawableUsesNesting (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kDrawableViewDependentViewportDraw (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kDrawableViewIndependentViewportDraw (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kThreadedWorldDrawViewportDraw (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def name (self, *args, **kwargs)-> None :
      '''None'''
    ...

class GiDrawableType(object):
    def __add__ (self, value, /) :
      '''Return self+value.'''
    ...
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
    def __mul__ (self, value, /) :
      '''Return self*value.'''
    ...
    def __rmul__ (self, value, /) :
      '''Return value*self.'''
    ...
    def __sub__ (self, value, /) :
      '''Return self-value.'''
    ...
    def __truediv__ (self, value, /) :
      '''Return self/value.'''
    ...
    def kAmbientLight (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kDistantLight (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kGeometry (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kGradientBackground (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kGroundPlaneBackground (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kImageBackground (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kImageBasedLightingBackground (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kPointLight (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kSkyBackground (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kSolidBackground (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kSpotLight (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kViewport (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kWebLight (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def name (self, *args, **kwargs)-> None :
      '''None'''
    ...

class GiGraphicsKernel(object):
    def __init__ (self, *args, **kwargs)-> None :
      '''Raises an exception
This class cannot be instantiated from Python'''
    ...
    def className (self, *args, **kwargs)-> str :
      '''className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def getDescriptor (self, *args, **kwargs)-> PyGi.GiKernelDescriptor :
      '''getDescriptor( (GiGraphicsKernel)arg1) -> GiKernelDescriptor :

    C++ signature :
        class PyGiKernelDescriptor getDescriptor(class PyGiGraphicsKernel {lvalue})'''
    ...

class GiKernelDescriptor(object):
    def __init__ (self, *args, **kwargs)-> None :
      '''Raises an exception
This class cannot be instantiated from Python'''
    ...
    def className (self, *args, **kwargs)-> str :
      '''className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...

class OrientationTransformBehavior(object):
    def __add__ (self, value, /) :
      '''Return self+value.'''
    ...
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
    def __mul__ (self, value, /) :
      '''Return self*value.'''
    ...
    def __rmul__ (self, value, /) :
      '''Return value*self.'''
    ...
    def __sub__ (self, value, /) :
      '''Return self-value.'''
    ...
    def __truediv__ (self, value, /) :
      '''Return self/value.'''
    ...
    def kAcGiScreenOrientation (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kAcGiWorldOrientation (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kAcGiZAxisOrientation (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def name (self, *args, **kwargs)-> None :
      '''None'''
    ...

class OrientationType(object):
    def __add__ (self, value, /) :
      '''Return self+value.'''
    ...
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
    def __mul__ (self, value, /) :
      '''Return self*value.'''
    ...
    def __rmul__ (self, value, /) :
      '''Return value*self.'''
    ...
    def __sub__ (self, value, /) :
      '''Return self-value.'''
    ...
    def __truediv__ (self, value, /) :
      '''Return self/value.'''
    ...
    def kAcGiClockwise (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kAcGiCounterClockwise (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kAcGiNoOrientation (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def name (self, *args, **kwargs)-> None :
      '''None'''
    ...

class PositionTransformBehavior(object):
    def __add__ (self, value, /) :
      '''Return self+value.'''
    ...
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
    def __mul__ (self, value, /) :
      '''Return self*value.'''
    ...
    def __rmul__ (self, value, /) :
      '''Return value*self.'''
    ...
    def __sub__ (self, value, /) :
      '''Return self-value.'''
    ...
    def __truediv__ (self, value, /) :
      '''Return self/value.'''
    ...
    def kAcGiScreenLocalOriginPosition (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kAcGiScreenPosition (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kAcGiViewportPosition (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kAcGiWorldPosition (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kAcGiWorldWithScreenOffsetPosition (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def name (self, *args, **kwargs)-> None :
      '''None'''
    ...

class RegenType(object):
    def __add__ (self, value, /) :
      '''Return self+value.'''
    ...
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
    def __mul__ (self, value, /) :
      '''Return self*value.'''
    ...
    def __rmul__ (self, value, /) :
      '''Return value*self.'''
    ...
    def __sub__ (self, value, /) :
      '''Return self-value.'''
    ...
    def __truediv__ (self, value, /) :
      '''Return self/value.'''
    ...
    def eAcGiRegenTypeInvalid (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kAcGiForExplode (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kAcGiHideOrShadeCommand (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kAcGiSaveWorldDrawForProxy (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kAcGiShadedDisplay (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kAcGiStandardDisplay (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def name (self, *args, **kwargs)-> None :
      '''None'''
    ...

class ScaleTransformBehavior(object):
    def __add__ (self, value, /) :
      '''Return self+value.'''
    ...
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
    def __mul__ (self, value, /) :
      '''Return self*value.'''
    ...
    def __rmul__ (self, value, /) :
      '''Return value*self.'''
    ...
    def __sub__ (self, value, /) :
      '''Return self-value.'''
    ...
    def __truediv__ (self, value, /) :
      '''Return self/value.'''
    ...
    def kAcGiScreenLocalOriginScale (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kAcGiScreenScale (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kAcGiViewportLocalOriginScale (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kAcGiViewportScale (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kAcGiWorldScale (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def name (self, *args, **kwargs)-> None :
      '''None'''
    ...

class SelectionFlags(object):
    def __add__ (self, value, /) :
      '''Return self+value.'''
    ...
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
    def __mul__ (self, value, /) :
      '''Return self*value.'''
    ...
    def __rmul__ (self, value, /) :
      '''Return value*self.'''
    ...
    def __sub__ (self, value, /) :
      '''Return self-value.'''
    ...
    def __truediv__ (self, value, /) :
      '''Return self/value.'''
    ...
    def kNoSelectionFlags (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kSelectionIgnore (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def name (self, *args, **kwargs)-> None :
      '''None'''
    ...

class ShadowFlags(object):
    def __add__ (self, value, /) :
      '''Return self+value.'''
    ...
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
    def __mul__ (self, value, /) :
      '''Return self*value.'''
    ...
    def __rmul__ (self, value, /) :
      '''Return value*self.'''
    ...
    def __sub__ (self, value, /) :
      '''Return self-value.'''
    ...
    def __truediv__ (self, value, /) :
      '''Return self/value.'''
    ...
    def kNoDrawFlags (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kShadowsDoesNotCast (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kShadowsDoesNotReceive (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kShadowsIgnore (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def name (self, *args, **kwargs)-> None :
      '''None'''
    ...

class SubEntityTraits(PyRx.RxObject):
    def __init__ (self, *args, **kwargs)-> None :
      '''Raises an exception
This class cannot be instantiated from Python'''
    ...
    def className (self, *args, **kwargs)-> str :
      '''className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def color (self)-> int :
      '''                             '''
    ...
    def comparedTo (self, other: PyRx.RxObject)-> PyRx.Ordering :
      '''Function usage:This function is intended to allow classes to provide a means to compare class objects much the way strcmp() compares character strings.The object pointed to by other is compared with this object. The result of the comparison is returned.The possible AcRx::Ordering types are:AcRx::kLessThanAcRx::kEqualAcRx::kGreaterThanAcRx::kNotOrderableThe AcRx::kNotOrderable type is there because C++ classes often cannot support object value comparison.Function implementation in derived classes:There are no restrictions or expectations on how this function is implemented. Each class will have its own requirements for comparison.Default implementation:Simply returns AcRx::kNotOrderable since many C++ classes cannot support object value comparison.'''
    ...
    def copyFrom (self, other: PyRx.RxObject)-> None :
      '''Function usage:Copies the contents of other into the messaged object, whenever feasible. Function implementation in derived classes:If implemented, this function needs to be able to read the data in the object pointed to by other and copy any or all data as appropriate into this object. There is no requirement that the object pointed to by other and this object be of the same class, but that is the generally assumed condition.Default implementation: Because this function must be overridden to have any meaning, a fatal error will be caused when calling the default implementation. '''
    ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
      '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
    ...
    def dispose (self)-> None :
      '''                             '''
    ...
    def drawFlags (self)-> int :
      '''                             '''
    ...
    def fillType (self)-> PyGi.FillType :
      '''                             '''
    ...
    def getPlotStyleNameId (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def implRefCount (self)-> int :
      '''                             '''
    ...
    def isA (self)-> PyRx.RxClass :
      '''Function usage:For each class registered with ObjectARX, the implementation of this function is to return a pointer to the AcRxClass object for the class of the object in which this method is called. For classes not registered with ObjectARX, this method has no meaning.Function implementation in derived classes:This function is overridden in all derived classes. The AcRx macros declare and define this function, so that the override is taken care of as part of using the macros. The implementation of this function is simply to return ::desc(). For example. the implementation for AcDbLine would be:return AcDbLine::desc();Default implementation for AcRxObject:  { return AcRxObject::desc(); }'''
    ...
    def isKindOf (self, rhs: PyRx.RxClass)-> bool :
      '''Returns true if "this" object is of a member of either the class represented by aClass, or a class derived from aClass. '''
    ...
    def isNullObj (self)-> bool :
      '''                             '''
    ...
    def keepAlive (self, flag: bool)-> None :
      '''                             '''
    ...
    def layerId (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def lineTypeId (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def lineTypeScale (self)-> float :
      '''                             '''
    ...
    def lineWeight (self)-> PyDb.LineWeight :
      '''                             '''
    ...
    def materialId (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def queryX (self, rhs: PyRx.RxClass)-> PyRx.RxObject :
      '''This method searches for a protocol extension object associated with this object.The method begins the search by examining the AcRxClass object associated with this object, and if no protocol extension object is found, the search continues in the base class of the object's class and so on up the inheritance tree for the class. This procedure provides a form of protocol extension inheritance. An object's AcRxClass member may be found by using the class's isA() method.If the search for a protocol extension object is unsuccessful, then NULL is returned.'''
    ...
    def sectionable (self)-> bool :
      '''                             '''
    ...
    def selectionGeom (self)-> bool :
      '''                             '''
    ...
    def setColor (self, val: int)-> None :
      '''                             '''
    ...
    def setDrawFlags (self, flags: int)-> None :
      '''                             '''
    ...
    def setFillType (self, val: PyGi.FillType)-> None :
      '''                             '''
    ...
    def setLayer (self, id: PyDb.ObjectId)-> None :
      '''                             '''
    ...
    def setLineType (self, id: PyDb.ObjectId)-> None :
      '''                             '''
    ...
    def setLineTypeScale (self, val: float=1.0)-> None :
      '''                             '''
    ...
    def setLineWeight (self, val: PyDb.LineWeight)-> None :
      '''                             '''
    ...
    def setMaterial (self, id: PyDb.ObjectId)-> None :
      '''                             '''
    ...
    def setPlotStyleName (self, val: PyDb.PlotStyleNameType, id: PyDb.ObjectId=None)-> None :
      '''                             '''
    ...
    def setSectionable (self, val: bool)-> None :
      '''                             '''
    ...
    def setSelectionGeom (self, val: bool)-> None :
      '''                             '''
    ...
    def setSelectionMarker (self, val: int)-> None :
      '''                             '''
    ...
    def setShadowFlags (self, val: PyGi.ShadowFlags)-> None :
      '''                             '''
    ...
    def setThickness (self, val: float)-> None :
      '''                             '''
    ...
    def setTransparency (self, val: PyDb.Transparency)-> None :
      '''                             '''
    ...
    def setTrueColor (self, clr: PyDb.EntityColor)-> None :
      '''                             '''
    ...
    def setVisualStyle (self, id: PyDb.ObjectId)-> None :
      '''                             '''
    ...
    def shadowFlags (self)-> PyGi.ShadowFlags :
      '''                             '''
    ...
    def thickness (self)-> float :
      '''                             '''
    ...
    def transparency (self)-> PyDb.Transparency :
      '''                             '''
    ...
    def trueColor (self)-> PyDb.EntityColor :
      '''                             '''
    ...
    def visualStyle (self)-> PyDb.ObjectId :
      '''                             '''
    ...

class TransientDrawingMode(object):
    def __add__ (self, value, /) :
      '''Return self+value.'''
    ...
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
    def __mul__ (self, value, /) :
      '''Return self*value.'''
    ...
    def __rmul__ (self, value, /) :
      '''Return value*self.'''
    ...
    def __sub__ (self, value, /) :
      '''Return self-value.'''
    ...
    def __truediv__ (self, value, /) :
      '''Return self/value.'''
    ...
    def kAcGiContrast (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kAcGiDirectShortTerm (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kAcGiDirectTopmost (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kAcGiDrawingModeCount (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kAcGiHighlight (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kAcGiMain (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kAcGiSprite (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def name (self, *args, **kwargs)-> None :
      '''None'''
    ...

class TransientManager(object):
    def __init__ (self)-> None :
      '''                             '''
    ...
    def addChildTransient (self, drawable: PyGi.Drawable, parentDrawable: PyGi.Drawable)-> bool :
      '''This function adds a child transient to specified parent transient. This allows for partial updates of the parent drawable.Returns true if successful. This function doesn't need to specify a drawing mode, subDrawingMode or viewportNumber; these properties of the child transient will be the same as parent transient'''
    ...
    def addTransient (self, drawable: PyGi.Drawable, mode: PyGi.TransientDrawingMode, subDrawingMode: int, viewportNumbers: list[int])-> bool :
      '''This function adds a transient to a list of viewports.Returns true if successful.'''
    ...

    @staticmethod
    def current ()-> PyGi.TransientManager :
      '''                             '''
    ...
    def eraseChildTransient (self, drawable: PyGi.Drawable, parentDrawable: PyGi.Drawable)-> bool :
      '''This function erases a child transient from specified parent transient.Returns true if successful.'''
    ...
    def eraseTransient (self, drawable: PyGi.Drawable, viewportNumbers: list[int])-> bool :
      '''This function erases a transient from a list of viewports.Returns true if successful. This function erases a specified drawable which has been added by addTransient().'''
    ...
    def eraseTransients (self, mode: PyGi.TransientDrawingMode, subDrawingMode: int, viewportNumbers: list[int])-> bool :
      '''This function erases all transients in the specified subDrawingMode from a list of viewports.Returns true if successful.'''
    ...
    def getFreeSubDrawingMode (self, mode: PyGi.TransientDrawingMode, subDrawingMode: int, viewportNumbers: list[int])-> tuple[Any,...] :
      '''Get the free draw order in a certain transient drawing mode.Returns 0 if the input draw order is not free and transient manager also could not get a free draw order.Returns 1 if the inputting draw order is available.Returns 2 if the inputting draw order is unavailable, but transient manager could return a free draw order.'''
    ...
    def updateChildTransient (self, drawable: PyGi.Drawable, parentDrawable: PyGi.Drawable)-> None :
      '''This function only updates a child transient of the specified parent transient. This means partial updates of parent drawable.'''
    ...
    def updateTransient (self, drawable: PyGi.Drawable, viewportNumbers: list[int])-> None :
      '''Update a transient via the transient manager.'''
    ...

class TransparencyMode(object):
    def __add__ (self, value, /) :
      '''Return self+value.'''
    ...
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
    def __mul__ (self, value, /) :
      '''Return self*value.'''
    ...
    def __rmul__ (self, value, /) :
      '''Return value*self.'''
    ...
    def __sub__ (self, value, /) :
      '''Return self-value.'''
    ...
    def __truediv__ (self, value, /) :
      '''Return self/value.'''
    ...
    def kTransparency1Bit (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kTransparency8Bit (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kTransparencyOff (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def name (self, *args, **kwargs)-> None :
      '''None'''
    ...

class ViewportDraw(CommonDraw):
    def __init__ (self, *args, **kwargs)-> None :
      '''Raises an exception
This class cannot be instantiated from Python'''
    ...

    @staticmethod
    def className ()-> str :
      '''                             '''
    ...
    def comparedTo (self, other: PyRx.RxObject)-> PyRx.Ordering :
      '''Function usage:This function is intended to allow classes to provide a means to compare class objects much the way strcmp() compares character strings.The object pointed to by other is compared with this object. The result of the comparison is returned.The possible AcRx::Ordering types are:AcRx::kLessThanAcRx::kEqualAcRx::kGreaterThanAcRx::kNotOrderableThe AcRx::kNotOrderable type is there because C++ classes often cannot support object value comparison.Function implementation in derived classes:There are no restrictions or expectations on how this function is implemented. Each class will have its own requirements for comparison.Default implementation:Simply returns AcRx::kNotOrderable since many C++ classes cannot support object value comparison.'''
    ...
    def copyFrom (self, other: PyRx.RxObject)-> None :
      '''Function usage:Copies the contents of other into the messaged object, whenever feasible. Function implementation in derived classes:If implemented, this function needs to be able to read the data in the object pointed to by other and copy any or all data as appropriate into this object. There is no requirement that the object pointed to by other and this object be of the same class, but that is the generally assumed condition.Default implementation: Because this function must be overridden to have any meaning, a fatal error will be caused when calling the default implementation. '''
    ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
      '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
    ...
    def dispose (self)-> None :
      '''                             '''
    ...
    def geometry (self)-> PyGi.ViewportGeometry :
      '''                             '''
    ...
    def implRefCount (self)-> int :
      '''                             '''
    ...
    def isA (self)-> PyRx.RxClass :
      '''Function usage:For each class registered with ObjectARX, the implementation of this function is to return a pointer to the AcRxClass object for the class of the object in which this method is called. For classes not registered with ObjectARX, this method has no meaning.Function implementation in derived classes:This function is overridden in all derived classes. The AcRx macros declare and define this function, so that the override is taken care of as part of using the macros. The implementation of this function is simply to return ::desc(). For example. the implementation for AcDbLine would be:return AcDbLine::desc();Default implementation for AcRxObject:  { return AcRxObject::desc(); }'''
    ...
    def isDragging (self)-> bool :
      '''                             '''
    ...
    def isKindOf (self, rhs: PyRx.RxClass)-> bool :
      '''Returns true if "this" object is of a member of either the class represented by aClass, or a class derived from aClass. '''
    ...
    def isNullObj (self)-> bool :
      '''                             '''
    ...
    def keepAlive (self, flag: bool)-> None :
      '''                             '''
    ...
    def queryX (self, rhs: PyRx.RxClass)-> PyRx.RxObject :
      '''This method searches for a protocol extension object associated with this object.The method begins the search by examining the AcRxClass object associated with this object, and if no protocol extension object is found, the search continues in the base class of the object's class and so on up the inheritance tree for the class. This procedure provides a form of protocol extension inheritance. An object's AcRxClass member may be found by using the class's isA() method.If the search for a protocol extension object is unsuccessful, then NULL is returned.'''
    ...
    def regenAbort (self)-> bool :
      '''                             '''
    ...
    def regenType (self)-> PyGi.RegenType :
      '''                             '''
    ...
    def subEntityTraits (self)-> PyGi.SubEntityTraits :
      '''                             '''
    ...

class ViewportGeometry(Geometry):
    def __init__ (self, *args, **kwargs)-> None :
      '''Raises an exception
This class cannot be instantiated from Python'''
    ...

    @overload
    def circle (self, center: PyGe.Point3d, radius: float, normal: PyGe.Vector3d)-> bool : ...
    @overload
    def circle (self, p1: PyGe.Point3d, p2: PyGe.Point3d, p3: PyGe.Point3d)-> bool : ...
    def circle (self, *args, **kwargs)-> bool :
      '''Overloads:
    - center: PyGe.Point3d, radius: float, normal: PyGe.Vector3d
    - p1: PyGe.Point3d, p2: PyGe.Point3d, p3: PyGe.Point3d
    '''
    ...

    @overload
    def circularArc (self, center: PyGe.Point3d, radius: float, normal: PyGe.Vector3d, startVector: PyGe.Vector3d, sweepAngle: float)-> bool : ...
    @overload
    def circularArc (self, center: PyGe.Point3d, radius: float, normal: PyGe.Vector3d, startVector: PyGe.Vector3d, sweepAngle: float, arcType: PyGe.ArcType)-> bool : ...
    @overload
    def circularArc (self, p1: PyGe.Point3d, p2: PyGe.Point3d, p3: PyGe.Point3d)-> bool : ...
    @overload
    def circularArc (self, p1: PyGe.Point3d, p2: PyGe.Point3d, p3: PyGe.Point3d, arcType: PyGe.ArcType)-> bool : ...
    def circularArc (self, *args, **kwargs)-> bool :
      '''Overloads:
    - center: PyGe.Point3d, radius: float, normal: PyGe.Vector3d, startVector: PyGe.Vector3d, sweepAngle: float
    - center: PyGe.Point3d, radius: float, normal: PyGe.Vector3d, startVector: PyGe.Vector3d, sweepAngle: float, arcType: PyGe.ArcType
    - p1: PyGe.Point3d, p2: PyGe.Point3d, p3: PyGe.Point3d
    - p1: PyGe.Point3d, p2: PyGe.Point3d, p3: PyGe.Point3d, arcType: PyGe.ArcType
    '''
    ...

    @staticmethod
    def className ()-> str :
      '''                             '''
    ...
    def comparedTo (self, other: PyRx.RxObject)-> PyRx.Ordering :
      '''Function usage:This function is intended to allow classes to provide a means to compare class objects much the way strcmp() compares character strings.The object pointed to by other is compared with this object. The result of the comparison is returned.The possible AcRx::Ordering types are:AcRx::kLessThanAcRx::kEqualAcRx::kGreaterThanAcRx::kNotOrderableThe AcRx::kNotOrderable type is there because C++ classes often cannot support object value comparison.Function implementation in derived classes:There are no restrictions or expectations on how this function is implemented. Each class will have its own requirements for comparison.Default implementation:Simply returns AcRx::kNotOrderable since many C++ classes cannot support object value comparison.'''
    ...
    def copyFrom (self, other: PyRx.RxObject)-> None :
      '''Function usage:Copies the contents of other into the messaged object, whenever feasible. Function implementation in derived classes:If implemented, this function needs to be able to read the data in the object pointed to by other and copy any or all data as appropriate into this object. There is no requirement that the object pointed to by other and this object be of the same class, but that is the generally assumed condition.Default implementation: Because this function must be overridden to have any meaning, a fatal error will be caused when calling the default implementation. '''
    ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
      '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
    ...
    def dispose (self)-> None :
      '''                             '''
    ...
    def draw (self, drawable : PyGi.Drawable)-> bool :
      '''                             '''
    ...
    def edge (self, edgeList : list[PyGe.Curve2d])-> bool :
      '''                             '''
    ...
    def ellipticalArc (self, center:PyGe.Point3d, norm:PyGe.Vector3d, majAxisLen:float, minAxisLen:float, startDeg:float, endDeg:float, tilt:float, arcType:ArcType=kAcGiArcSimple)-> bool :
      '''                             '''
    ...
    def getModelToWorldTransform (self)-> PyGe.Matrix3d :
      '''                             '''
    ...
    def getWorldToModelTransform (self)-> PyGe.Matrix3d :
      '''                             '''
    ...
    def implRefCount (self)-> int :
      '''                             '''
    ...
    def isA (self)-> PyRx.RxClass :
      '''Function usage:For each class registered with ObjectARX, the implementation of this function is to return a pointer to the AcRxClass object for the class of the object in which this method is called. For classes not registered with ObjectARX, this method has no meaning.Function implementation in derived classes:This function is overridden in all derived classes. The AcRx macros declare and define this function, so that the override is taken care of as part of using the macros. The implementation of this function is simply to return ::desc(). For example. the implementation for AcDbLine would be:return AcDbLine::desc();Default implementation for AcRxObject:  { return AcRxObject::desc(); }'''
    ...
    def isKindOf (self, rhs: PyRx.RxClass)-> bool :
      '''Returns true if "this" object is of a member of either the class represented by aClass, or a class derived from aClass. '''
    ...
    def isNullObj (self)-> bool :
      '''                             '''
    ...
    def keepAlive (self, flag: bool)-> None :
      '''                             '''
    ...
    def pline (self, p1 : PyDb.Polyline, fromIndex : int, numSegs : int)-> bool :
      '''                             '''
    ...
    def polygon (self, vertexList : list[PyGe.Point3d])-> bool :
      '''                             '''
    ...
    def polyline (self, vertexList : list[PyGe.Point3d], normal : PyGe.Vector3d=default, marker : int=default)-> bool :
      '''                             '''
    ...
    def popModelTransform (self)-> bool :
      '''                             '''
    ...
    def pushModelTransform (self, val : PyGe.Vector3d|PyGe.Matrix3d)-> bool :
      '''                             '''
    ...
    def pushOrientationTransform (self,  behavior : PyGi.AcGiOrientationTransformBehavior)-> PyGe.Matrix3d :
      '''                             '''
    ...
    def pushPositionTransform (self, behavior : PyGi.AcGiPositionTransformBehavior,  offset : PyGe.Point2d|PyGe.Point2d)-> PyGe.Matrix3d :
      '''                             '''
    ...
    def pushScaleTransform (self, behavior : PyGi.AcGiScaleTransformBehavior,  extents : PyGe.Point2d|PyGe.Point2d)-> PyGe.Matrix3d :
      '''                             '''
    ...
    def queryX (self, rhs: PyRx.RxClass)-> PyRx.RxObject :
      '''This method searches for a protocol extension object associated with this object.The method begins the search by examining the AcRxClass object associated with this object, and if no protocol extension object is found, the search continues in the base class of the object's class and so on up the inheritance tree for the class. This procedure provides a form of protocol extension inheritance. An object's AcRxClass member may be found by using the class's isA() method.If the search for a protocol extension object is unsuccessful, then NULL is returned.'''
    ...
    def ray (self, p1 : PyGe.Point3d, p2 : PyGe.Point3d)-> bool :
      '''                             '''
    ...
    def rowOfDots (self, count : int, start: PyGe.Point3d, step : PyGe.Vector3d)-> bool :
      '''                             '''
    ...
    def text (self, pos : PyGe.Point3d, normal : PyGe.Vector3d, direction : PyGe.Vector3d, height : float, width : float, oblique : float, msg : str)-> bool :
      '''                             '''
    ...
    def worldLine (self, p1 : PyGe.Point3d, p2 : PyGe.Point3d)-> bool :
      '''                             '''
    ...
    def xline (self, p1 : PyGe.Point3d, p2 : PyGe.Point3d)-> bool :
      '''                             '''
    ...

class Visibility(object):
    def __add__ (self, value, /) :
      '''Return self+value.'''
    ...
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
    def __mul__ (self, value, /) :
      '''Return self*value.'''
    ...
    def __rmul__ (self, value, /) :
      '''Return value*self.'''
    ...
    def __sub__ (self, value, /) :
      '''Return self-value.'''
    ...
    def __truediv__ (self, value, /) :
      '''Return self/value.'''
    ...
    def kAcGiInvisible (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kAcGiSilhouette (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kAcGiVisible (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def name (self, *args, **kwargs)-> None :
      '''None'''
    ...

class WorldDraw(CommonDraw):
    def __init__ (self, *args, **kwargs)-> None :
      '''Raises an exception
This class cannot be instantiated from Python'''
    ...

    @staticmethod
    def className ()-> str :
      '''                             '''
    ...
    def comparedTo (self, other: PyRx.RxObject)-> PyRx.Ordering :
      '''Function usage:This function is intended to allow classes to provide a means to compare class objects much the way strcmp() compares character strings.The object pointed to by other is compared with this object. The result of the comparison is returned.The possible AcRx::Ordering types are:AcRx::kLessThanAcRx::kEqualAcRx::kGreaterThanAcRx::kNotOrderableThe AcRx::kNotOrderable type is there because C++ classes often cannot support object value comparison.Function implementation in derived classes:There are no restrictions or expectations on how this function is implemented. Each class will have its own requirements for comparison.Default implementation:Simply returns AcRx::kNotOrderable since many C++ classes cannot support object value comparison.'''
    ...
    def copyFrom (self, other: PyRx.RxObject)-> None :
      '''Function usage:Copies the contents of other into the messaged object, whenever feasible. Function implementation in derived classes:If implemented, this function needs to be able to read the data in the object pointed to by other and copy any or all data as appropriate into this object. There is no requirement that the object pointed to by other and this object be of the same class, but that is the generally assumed condition.Default implementation: Because this function must be overridden to have any meaning, a fatal error will be caused when calling the default implementation. '''
    ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
      '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
    ...
    def dispose (self)-> None :
      '''                             '''
    ...
    def geometry (self)-> PyGi.WorldGeometry :
      '''                             '''
    ...
    def implRefCount (self)-> int :
      '''                             '''
    ...
    def isA (self)-> PyRx.RxClass :
      '''Function usage:For each class registered with ObjectARX, the implementation of this function is to return a pointer to the AcRxClass object for the class of the object in which this method is called. For classes not registered with ObjectARX, this method has no meaning.Function implementation in derived classes:This function is overridden in all derived classes. The AcRx macros declare and define this function, so that the override is taken care of as part of using the macros. The implementation of this function is simply to return ::desc(). For example. the implementation for AcDbLine would be:return AcDbLine::desc();Default implementation for AcRxObject:  { return AcRxObject::desc(); }'''
    ...
    def isDragging (self)-> bool :
      '''                             '''
    ...
    def isKindOf (self, rhs: PyRx.RxClass)-> bool :
      '''Returns true if "this" object is of a member of either the class represented by aClass, or a class derived from aClass. '''
    ...
    def isNullObj (self)-> bool :
      '''                             '''
    ...
    def keepAlive (self, flag: bool)-> None :
      '''                             '''
    ...
    def queryX (self, rhs: PyRx.RxClass)-> PyRx.RxObject :
      '''This method searches for a protocol extension object associated with this object.The method begins the search by examining the AcRxClass object associated with this object, and if no protocol extension object is found, the search continues in the base class of the object's class and so on up the inheritance tree for the class. This procedure provides a form of protocol extension inheritance. An object's AcRxClass member may be found by using the class's isA() method.If the search for a protocol extension object is unsuccessful, then NULL is returned.'''
    ...
    def regenAbort (self)-> bool :
      '''                             '''
    ...
    def regenType (self)-> PyGi.RegenType :
      '''                             '''
    ...
    def subEntityTraits (self)-> PyGi.SubEntityTraits :
      '''                             '''
    ...

class WorldGeometry(Geometry):
    def __init__ (self, *args, **kwargs)-> None :
      '''Raises an exception
This class cannot be instantiated from Python'''
    ...

    @overload
    def circle (self, center: PyGe.Point3d, radius: float, normal: PyGe.Vector3d)-> bool : ...
    @overload
    def circle (self, p1: PyGe.Point3d, p2: PyGe.Point3d, p3: PyGe.Point3d)-> bool : ...
    def circle (self, *args, **kwargs)-> bool :
      '''Overloads:
    - center: PyGe.Point3d, radius: float, normal: PyGe.Vector3d
    - p1: PyGe.Point3d, p2: PyGe.Point3d, p3: PyGe.Point3d
    '''
    ...

    @overload
    def circularArc (self, center: PyGe.Point3d, radius: float, normal: PyGe.Vector3d, startVector: PyGe.Vector3d, sweepAngle: float)-> bool : ...
    @overload
    def circularArc (self, center: PyGe.Point3d, radius: float, normal: PyGe.Vector3d, startVector: PyGe.Vector3d, sweepAngle: float, arcType: PyGe.ArcType)-> bool : ...
    @overload
    def circularArc (self, p1: PyGe.Point3d, p2: PyGe.Point3d, p3: PyGe.Point3d)-> bool : ...
    @overload
    def circularArc (self, p1: PyGe.Point3d, p2: PyGe.Point3d, p3: PyGe.Point3d, arcType: PyGe.ArcType)-> bool : ...
    def circularArc (self, *args, **kwargs)-> bool :
      '''Overloads:
    - center: PyGe.Point3d, radius: float, normal: PyGe.Vector3d, startVector: PyGe.Vector3d, sweepAngle: float
    - center: PyGe.Point3d, radius: float, normal: PyGe.Vector3d, startVector: PyGe.Vector3d, sweepAngle: float, arcType: PyGe.ArcType
    - p1: PyGe.Point3d, p2: PyGe.Point3d, p3: PyGe.Point3d
    - p1: PyGe.Point3d, p2: PyGe.Point3d, p3: PyGe.Point3d, arcType: PyGe.ArcType
    '''
    ...

    @staticmethod
    def className ()-> str :
      '''                             '''
    ...
    def comparedTo (self, other: PyRx.RxObject)-> PyRx.Ordering :
      '''Function usage:This function is intended to allow classes to provide a means to compare class objects much the way strcmp() compares character strings.The object pointed to by other is compared with this object. The result of the comparison is returned.The possible AcRx::Ordering types are:AcRx::kLessThanAcRx::kEqualAcRx::kGreaterThanAcRx::kNotOrderableThe AcRx::kNotOrderable type is there because C++ classes often cannot support object value comparison.Function implementation in derived classes:There are no restrictions or expectations on how this function is implemented. Each class will have its own requirements for comparison.Default implementation:Simply returns AcRx::kNotOrderable since many C++ classes cannot support object value comparison.'''
    ...
    def copyFrom (self, other: PyRx.RxObject)-> None :
      '''Function usage:Copies the contents of other into the messaged object, whenever feasible. Function implementation in derived classes:If implemented, this function needs to be able to read the data in the object pointed to by other and copy any or all data as appropriate into this object. There is no requirement that the object pointed to by other and this object be of the same class, but that is the generally assumed condition.Default implementation: Because this function must be overridden to have any meaning, a fatal error will be caused when calling the default implementation. '''
    ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
      '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
    ...
    def dispose (self)-> None :
      '''                             '''
    ...
    def draw (self, drawable : PyGi.Drawable)-> bool :
      '''                             '''
    ...
    def edge (self, edgeList : list[PyGe.Curve2d])-> bool :
      '''                             '''
    ...
    def ellipticalArc (self, center:PyGe.Point3d, norm:PyGe.Vector3d, majAxisLen:float, minAxisLen:float, startDeg:float, endDeg:float, tilt:float, arcType:ArcType=kAcGiArcSimple)-> bool :
      '''                             '''
    ...
    def getModelToWorldTransform (self)-> PyGe.Matrix3d :
      '''                             '''
    ...
    def getWorldToModelTransform (self)-> PyGe.Matrix3d :
      '''                             '''
    ...
    def implRefCount (self)-> int :
      '''                             '''
    ...
    def isA (self)-> PyRx.RxClass :
      '''Function usage:For each class registered with ObjectARX, the implementation of this function is to return a pointer to the AcRxClass object for the class of the object in which this method is called. For classes not registered with ObjectARX, this method has no meaning.Function implementation in derived classes:This function is overridden in all derived classes. The AcRx macros declare and define this function, so that the override is taken care of as part of using the macros. The implementation of this function is simply to return ::desc(). For example. the implementation for AcDbLine would be:return AcDbLine::desc();Default implementation for AcRxObject:  { return AcRxObject::desc(); }'''
    ...
    def isKindOf (self, rhs: PyRx.RxClass)-> bool :
      '''Returns true if "this" object is of a member of either the class represented by aClass, or a class derived from aClass. '''
    ...
    def isNullObj (self)-> bool :
      '''                             '''
    ...
    def keepAlive (self, flag: bool)-> None :
      '''                             '''
    ...
    def pline (self, p1 : PyDb.Polyline, fromIndex : int, numSegs : int)-> bool :
      '''                             '''
    ...
    def polygon (self, vertexList : list[PyGe.Point3d])-> bool :
      '''                             '''
    ...
    def polyline (self, vertexList : list[PyGe.Point3d], normal : PyGe.Vector3d=default, marker : int=default)-> bool :
      '''                             '''
    ...
    def popModelTransform (self)-> bool :
      '''                             '''
    ...
    def pushModelTransform (self, val : PyGe.Vector3d|PyGe.Matrix3d)-> bool :
      '''                             '''
    ...
    def pushOrientationTransform (self,  behavior : PyGi.AcGiOrientationTransformBehavior)-> PyGe.Matrix3d :
      '''                             '''
    ...
    def pushPositionTransform (self, behavior : PyGi.AcGiPositionTransformBehavior,  offset : PyGe.Point2d|PyGe.Point2d)-> PyGe.Matrix3d :
      '''                             '''
    ...
    def pushScaleTransform (self, behavior : PyGi.AcGiScaleTransformBehavior,  extents : PyGe.Point2d|PyGe.Point2d)-> PyGe.Matrix3d :
      '''                             '''
    ...
    def queryX (self, rhs: PyRx.RxClass)-> PyRx.RxObject :
      '''This method searches for a protocol extension object associated with this object.The method begins the search by examining the AcRxClass object associated with this object, and if no protocol extension object is found, the search continues in the base class of the object's class and so on up the inheritance tree for the class. This procedure provides a form of protocol extension inheritance. An object's AcRxClass member may be found by using the class's isA() method.If the search for a protocol extension object is unsuccessful, then NULL is returned.'''
    ...
    def ray (self, p1 : PyGe.Point3d, p2 : PyGe.Point3d)-> bool :
      '''                             '''
    ...
    def rowOfDots (self, count : int, start: PyGe.Point3d, step : PyGe.Vector3d)-> bool :
      '''                             '''
    ...
    def text (self, pos : PyGe.Point3d, normal : PyGe.Vector3d, direction : PyGe.Vector3d, height : float, width : float, oblique : float, msg : str)-> bool :
      '''                             '''
    ...
    def worldLine (self, p1 : PyGe.Point3d, p2 : PyGe.Point3d)-> bool :
      '''                             '''
    ...
    def xline (self, p1 : PyGe.Point3d, p2 : PyGe.Point3d)-> bool :
      '''                             '''
    ...
