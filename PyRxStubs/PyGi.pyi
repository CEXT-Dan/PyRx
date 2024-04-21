import PyRx
import PyGe
import PyGi
import PyGs
import PyDb
import PyAp
import PyEd
import PyPl
from typing import overload

class ArcType(object):
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
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
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
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
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
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
    def color (self, *args, **kwargs)-> int :
      '''color( (SubEntityTraits)arg1) -> int :

    C++ signature :
        unsigned short color(class PyGiSubEntityTraits {lvalue})'''
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
    def drawFlags (self, *args, **kwargs)-> int :
      '''drawFlags( (SubEntityTraits)arg1) -> int :

    C++ signature :
        unsigned int drawFlags(class PyGiSubEntityTraits {lvalue})'''
    ...
    def fillType (self, *args, **kwargs)-> PyGi.FillType :
      '''fillType( (SubEntityTraits)arg1) -> FillType :

    C++ signature :
        enum AcGiFillType fillType(class PyGiSubEntityTraits {lvalue})'''
    ...
    def getPlotStyleNameId (self, *args, **kwargs)-> PyDb.ObjectId :
      '''getPlotStyleNameId( (SubEntityTraits)arg1) -> ObjectId :

    C++ signature :
        class PyDbObjectId getPlotStyleNameId(class PyGiSubEntityTraits {lvalue})'''
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
    def layerId (self, *args, **kwargs)-> PyDb.ObjectId :
      '''layerId( (SubEntityTraits)arg1) -> ObjectId :

    C++ signature :
        class PyDbObjectId layerId(class PyGiSubEntityTraits {lvalue})'''
    ...
    def lineTypeId (self, *args, **kwargs)-> PyDb.ObjectId :
      '''lineTypeId( (SubEntityTraits)arg1) -> ObjectId :

    C++ signature :
        class PyDbObjectId lineTypeId(class PyGiSubEntityTraits {lvalue})'''
    ...
    def lineTypeScale (self, *args, **kwargs)-> float :
      '''lineTypeScale( (SubEntityTraits)arg1) -> float :

    C++ signature :
        double lineTypeScale(class PyGiSubEntityTraits {lvalue})'''
    ...
    def lineWeight (self, *args, **kwargs)-> PyDb.LineWeight :
      '''lineWeight( (SubEntityTraits)arg1) -> LineWeight :

    C++ signature :
        enum AcDb::LineWeight lineWeight(class PyGiSubEntityTraits {lvalue})'''
    ...
    def materialId (self, *args, **kwargs)-> PyDb.ObjectId :
      '''materialId( (SubEntityTraits)arg1) -> ObjectId :

    C++ signature :
        class PyDbObjectId materialId(class PyGiSubEntityTraits {lvalue})'''
    ...
    def queryX (self, rhs: PyRx.RxClass)-> PyRx.RxObject :
      '''This method searches for a protocol extension object associated with this object.The method begins the search by examining the AcRxClass object associated with this object, and if no protocol extension object is found, the search continues in the base class of the object's class and so on up the inheritance tree for the class. This procedure provides a form of protocol extension inheritance. An object's AcRxClass member may be found by using the class's isA() method.If the search for a protocol extension object is unsuccessful, then NULL is returned.'''
    ...
    def sectionable (self, *args, **kwargs)-> bool :
      '''sectionable( (SubEntityTraits)arg1) -> bool :

    C++ signature :
        bool sectionable(class PyGiSubEntityTraits {lvalue})'''
    ...
    def selectionGeom (self, *args, **kwargs)-> bool :
      '''selectionGeom( (SubEntityTraits)arg1) -> bool :

    C++ signature :
        bool selectionGeom(class PyGiSubEntityTraits {lvalue})'''
    ...
    def setColor (self, *args, **kwargs)-> None :
      '''setColor( (SubEntityTraits)arg1, (int)arg2) -> None :

    C++ signature :
        void setColor(class PyGiSubEntityTraits {lvalue},unsigned short)'''
    ...
    def setDrawFlags (self, *args, **kwargs)-> None :
      '''setDrawFlags( (SubEntityTraits)arg1, (SubentType)arg2) -> None :

    C++ signature :
        void setDrawFlags(class PyGiSubEntityTraits {lvalue},unsigned int)'''
    ...
    def setFillType (self, *args, **kwargs)-> None :
      '''setFillType( (SubEntityTraits)arg1, (FillType)arg2) -> None :

    C++ signature :
        void setFillType(class PyGiSubEntityTraits {lvalue},enum AcGiFillType)'''
    ...
    def setLayer (self, *args, **kwargs)-> None :
      '''setLayer( (SubEntityTraits)arg1, (ObjectId)arg2) -> None :

    C++ signature :
        void setLayer(class PyGiSubEntityTraits {lvalue},class PyDbObjectId)'''
    ...
    def setLineType (self, *args, **kwargs)-> None :
      '''setLineType( (SubEntityTraits)arg1, (ObjectId)arg2) -> None :

    C++ signature :
        void setLineType(class PyGiSubEntityTraits {lvalue},class PyDbObjectId)'''
    ...
    def setLineTypeScale (self, *args, **kwargs)-> None :
      '''setLineTypeScale( (SubEntityTraits)arg1) -> None :

    C++ signature :
        void setLineTypeScale(class PyGiSubEntityTraits {lvalue})

setLineTypeScale( (SubEntityTraits)arg1, (float)arg2) -> None :

    C++ signature :
        void setLineTypeScale(class PyGiSubEntityTraits {lvalue},double)'''
    ...
    def setLineWeight (self, *args, **kwargs)-> None :
      '''setLineWeight( (SubEntityTraits)arg1, (LineWeight)arg2) -> None :

    C++ signature :
        void setLineWeight(class PyGiSubEntityTraits {lvalue},enum AcDb::LineWeight)'''
    ...
    def setMaterial (self, *args, **kwargs)-> None :
      '''setMaterial( (SubEntityTraits)arg1, (ObjectId)arg2) -> None :

    C++ signature :
        void setMaterial(class PyGiSubEntityTraits {lvalue},class PyDbObjectId)'''
    ...
    def setPlotStyleName (self, *args, **kwargs)-> None :
      '''setPlotStyleName( (SubEntityTraits)arg1, (PlotStyleNameType)arg2) -> None :

    C++ signature :
        void setPlotStyleName(class PyGiSubEntityTraits {lvalue},enum AcDb::PlotStyleNameType)

setPlotStyleName( (SubEntityTraits)arg1, (PlotStyleNameType)arg2, (ObjectId)arg3) -> None :

    C++ signature :
        void setPlotStyleName(class PyGiSubEntityTraits {lvalue},enum AcDb::PlotStyleNameType,class PyDbObjectId)'''
    ...
    def setSectionable (self, *args, **kwargs)-> None :
      '''setSectionable( (SubEntityTraits)arg1, (bool)arg2) -> None :

    C++ signature :
        void setSectionable(class PyGiSubEntityTraits {lvalue},bool)'''
    ...
    def setSelectionGeom (self, *args, **kwargs)-> None :
      '''setSelectionGeom( (SubEntityTraits)arg1, (bool)arg2) -> None :

    C++ signature :
        void setSelectionGeom(class PyGiSubEntityTraits {lvalue},bool)'''
    ...
    def setSelectionMarker (self, *args, **kwargs)-> None :
      '''setSelectionMarker( (SubEntityTraits)arg1, (int)arg2) -> None :

    C++ signature :
        void setSelectionMarker(class PyGiSubEntityTraits {lvalue},__int64)'''
    ...
    def setShadowFlags (self, *args, **kwargs)-> None :
      '''setShadowFlags( (SubEntityTraits)arg1, (ShadowFlags)arg2) -> None :

    C++ signature :
        void setShadowFlags(class PyGiSubEntityTraits {lvalue},enum AcGiSubEntityTraits::ShadowFlags)'''
    ...
    def setThickness (self, *args, **kwargs)-> None :
      '''setThickness( (SubEntityTraits)arg1, (float)arg2) -> None :

    C++ signature :
        void setThickness(class PyGiSubEntityTraits {lvalue},double)'''
    ...
    def setTransparency (self, *args, **kwargs)-> None :
      '''setTransparency( (SubEntityTraits)arg1, (Transparency)arg2) -> None :

    C++ signature :
        void setTransparency(class PyGiSubEntityTraits {lvalue},class AcCmTransparency)'''
    ...
    def setTrueColor (self, *args, **kwargs)-> None :
      '''setTrueColor( (SubEntityTraits)arg1, (EntityColor)arg2) -> None :

    C++ signature :
        void setTrueColor(class PyGiSubEntityTraits {lvalue},class AcCmEntityColor)'''
    ...
    def setVisualStyle (self, *args, **kwargs)-> None :
      '''setVisualStyle( (SubEntityTraits)arg1, (ObjectId)arg2) -> None :

    C++ signature :
        void setVisualStyle(class PyGiSubEntityTraits {lvalue},class PyDbObjectId)'''
    ...
    def shadowFlags (self, *args, **kwargs)-> PyGi.ShadowFlags :
      '''shadowFlags( (SubEntityTraits)arg1) -> ShadowFlags :

    C++ signature :
        enum AcGiSubEntityTraits::ShadowFlags shadowFlags(class PyGiSubEntityTraits {lvalue})'''
    ...
    def thickness (self, *args, **kwargs)-> float :
      '''thickness( (SubEntityTraits)arg1) -> float :

    C++ signature :
        double thickness(class PyGiSubEntityTraits {lvalue})'''
    ...
    def transparency (self, *args, **kwargs)-> PyDb.Transparency :
      '''transparency( (SubEntityTraits)arg1) -> Transparency :

    C++ signature :
        class AcCmTransparency transparency(class PyGiSubEntityTraits {lvalue})'''
    ...
    def trueColor (self, *args, **kwargs)-> PyDb.EntityColor :
      '''trueColor( (SubEntityTraits)arg1) -> EntityColor :

    C++ signature :
        class AcCmEntityColor trueColor(class PyGiSubEntityTraits {lvalue})'''
    ...
    def visualStyle (self, *args, **kwargs)-> PyDb.ObjectId :
      '''visualStyle( (SubEntityTraits)arg1) -> ObjectId :

    C++ signature :
        class PyDbObjectId visualStyle(class PyGiSubEntityTraits {lvalue})'''
    ...

class FillType(object):
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
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
    def circle (self, *args, **kwargs)-> bool :
      '''circle( (Geometry)arg1, (Point3d)arg2, (float)arg3, (Vector3d)arg4) -> bool :

    C++ signature :
        bool circle(class PyGiGeometry {lvalue},class AcGePoint3d,double,class AcGeVector3d)

circle( (Geometry)arg1, (Point3d)arg2, (Point3d)arg3, (Point3d)arg4) -> bool :

    C++ signature :
        bool circle(class PyGiGeometry {lvalue},class AcGePoint3d,class AcGePoint3d,class AcGePoint3d)'''
    ...
    def circularArc (self, *args, **kwargs)-> bool :
      '''circularArc( (Geometry)arg1, (Point3d)arg2, (float)arg3, (Vector3d)arg4, (Vector3d)arg5, (float)arg6) -> bool :

    C++ signature :
        bool circularArc(class PyGiGeometry {lvalue},class AcGePoint3d,double,class AcGeVector3d,class AcGeVector3d,double)

circularArc( (Geometry)arg1, (Point3d)arg2, (float)arg3, (Vector3d)arg4, (Vector3d)arg5, (float)arg6, (ArcType)arg7) -> bool :

    C++ signature :
        bool circularArc(class PyGiGeometry {lvalue},class AcGePoint3d,double,class AcGeVector3d,class AcGeVector3d,double,enum AcGiArcType)

circularArc( (Geometry)arg1, (Point3d)arg2, (Point3d)arg3, (Point3d)arg4) -> bool :

    C++ signature :
        bool circularArc(class PyGiGeometry {lvalue},class AcGePoint3d,class AcGePoint3d,class AcGePoint3d)

circularArc( (Geometry)arg1, (Point3d)arg2, (Point3d)arg3, (Point3d)arg4, (ArcType)arg5) -> bool :

    C++ signature :
        bool circularArc(class PyGiGeometry {lvalue},class AcGePoint3d,class AcGePoint3d,class AcGePoint3d,enum AcGiArcType)'''
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
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
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
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
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
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
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
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
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
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
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
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
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
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
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
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
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
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
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
    def color (self, *args, **kwargs)-> int :
      '''color( (SubEntityTraits)arg1) -> int :

    C++ signature :
        unsigned short color(class PyGiSubEntityTraits {lvalue})'''
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
    def drawFlags (self, *args, **kwargs)-> int :
      '''drawFlags( (SubEntityTraits)arg1) -> int :

    C++ signature :
        unsigned int drawFlags(class PyGiSubEntityTraits {lvalue})'''
    ...
    def fillType (self, *args, **kwargs)-> PyGi.FillType :
      '''fillType( (SubEntityTraits)arg1) -> FillType :

    C++ signature :
        enum AcGiFillType fillType(class PyGiSubEntityTraits {lvalue})'''
    ...
    def getPlotStyleNameId (self, *args, **kwargs)-> PyDb.ObjectId :
      '''getPlotStyleNameId( (SubEntityTraits)arg1) -> ObjectId :

    C++ signature :
        class PyDbObjectId getPlotStyleNameId(class PyGiSubEntityTraits {lvalue})'''
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
    def layerId (self, *args, **kwargs)-> PyDb.ObjectId :
      '''layerId( (SubEntityTraits)arg1) -> ObjectId :

    C++ signature :
        class PyDbObjectId layerId(class PyGiSubEntityTraits {lvalue})'''
    ...
    def lineTypeId (self, *args, **kwargs)-> PyDb.ObjectId :
      '''lineTypeId( (SubEntityTraits)arg1) -> ObjectId :

    C++ signature :
        class PyDbObjectId lineTypeId(class PyGiSubEntityTraits {lvalue})'''
    ...
    def lineTypeScale (self, *args, **kwargs)-> float :
      '''lineTypeScale( (SubEntityTraits)arg1) -> float :

    C++ signature :
        double lineTypeScale(class PyGiSubEntityTraits {lvalue})'''
    ...
    def lineWeight (self, *args, **kwargs)-> PyDb.LineWeight :
      '''lineWeight( (SubEntityTraits)arg1) -> LineWeight :

    C++ signature :
        enum AcDb::LineWeight lineWeight(class PyGiSubEntityTraits {lvalue})'''
    ...
    def materialId (self, *args, **kwargs)-> PyDb.ObjectId :
      '''materialId( (SubEntityTraits)arg1) -> ObjectId :

    C++ signature :
        class PyDbObjectId materialId(class PyGiSubEntityTraits {lvalue})'''
    ...
    def queryX (self, rhs: PyRx.RxClass)-> PyRx.RxObject :
      '''This method searches for a protocol extension object associated with this object.The method begins the search by examining the AcRxClass object associated with this object, and if no protocol extension object is found, the search continues in the base class of the object's class and so on up the inheritance tree for the class. This procedure provides a form of protocol extension inheritance. An object's AcRxClass member may be found by using the class's isA() method.If the search for a protocol extension object is unsuccessful, then NULL is returned.'''
    ...
    def sectionable (self, *args, **kwargs)-> bool :
      '''sectionable( (SubEntityTraits)arg1) -> bool :

    C++ signature :
        bool sectionable(class PyGiSubEntityTraits {lvalue})'''
    ...
    def selectionGeom (self, *args, **kwargs)-> bool :
      '''selectionGeom( (SubEntityTraits)arg1) -> bool :

    C++ signature :
        bool selectionGeom(class PyGiSubEntityTraits {lvalue})'''
    ...
    def setColor (self, *args, **kwargs)-> None :
      '''setColor( (SubEntityTraits)arg1, (int)arg2) -> None :

    C++ signature :
        void setColor(class PyGiSubEntityTraits {lvalue},unsigned short)'''
    ...
    def setDrawFlags (self, *args, **kwargs)-> None :
      '''setDrawFlags( (SubEntityTraits)arg1, (SubentType)arg2) -> None :

    C++ signature :
        void setDrawFlags(class PyGiSubEntityTraits {lvalue},unsigned int)'''
    ...
    def setFillType (self, *args, **kwargs)-> None :
      '''setFillType( (SubEntityTraits)arg1, (FillType)arg2) -> None :

    C++ signature :
        void setFillType(class PyGiSubEntityTraits {lvalue},enum AcGiFillType)'''
    ...
    def setLayer (self, *args, **kwargs)-> None :
      '''setLayer( (SubEntityTraits)arg1, (ObjectId)arg2) -> None :

    C++ signature :
        void setLayer(class PyGiSubEntityTraits {lvalue},class PyDbObjectId)'''
    ...
    def setLineType (self, *args, **kwargs)-> None :
      '''setLineType( (SubEntityTraits)arg1, (ObjectId)arg2) -> None :

    C++ signature :
        void setLineType(class PyGiSubEntityTraits {lvalue},class PyDbObjectId)'''
    ...
    def setLineTypeScale (self, *args, **kwargs)-> None :
      '''setLineTypeScale( (SubEntityTraits)arg1) -> None :

    C++ signature :
        void setLineTypeScale(class PyGiSubEntityTraits {lvalue})

setLineTypeScale( (SubEntityTraits)arg1, (float)arg2) -> None :

    C++ signature :
        void setLineTypeScale(class PyGiSubEntityTraits {lvalue},double)'''
    ...
    def setLineWeight (self, *args, **kwargs)-> None :
      '''setLineWeight( (SubEntityTraits)arg1, (LineWeight)arg2) -> None :

    C++ signature :
        void setLineWeight(class PyGiSubEntityTraits {lvalue},enum AcDb::LineWeight)'''
    ...
    def setMaterial (self, *args, **kwargs)-> None :
      '''setMaterial( (SubEntityTraits)arg1, (ObjectId)arg2) -> None :

    C++ signature :
        void setMaterial(class PyGiSubEntityTraits {lvalue},class PyDbObjectId)'''
    ...
    def setPlotStyleName (self, *args, **kwargs)-> None :
      '''setPlotStyleName( (SubEntityTraits)arg1, (PlotStyleNameType)arg2) -> None :

    C++ signature :
        void setPlotStyleName(class PyGiSubEntityTraits {lvalue},enum AcDb::PlotStyleNameType)

setPlotStyleName( (SubEntityTraits)arg1, (PlotStyleNameType)arg2, (ObjectId)arg3) -> None :

    C++ signature :
        void setPlotStyleName(class PyGiSubEntityTraits {lvalue},enum AcDb::PlotStyleNameType,class PyDbObjectId)'''
    ...
    def setSectionable (self, *args, **kwargs)-> None :
      '''setSectionable( (SubEntityTraits)arg1, (bool)arg2) -> None :

    C++ signature :
        void setSectionable(class PyGiSubEntityTraits {lvalue},bool)'''
    ...
    def setSelectionGeom (self, *args, **kwargs)-> None :
      '''setSelectionGeom( (SubEntityTraits)arg1, (bool)arg2) -> None :

    C++ signature :
        void setSelectionGeom(class PyGiSubEntityTraits {lvalue},bool)'''
    ...
    def setSelectionMarker (self, *args, **kwargs)-> None :
      '''setSelectionMarker( (SubEntityTraits)arg1, (int)arg2) -> None :

    C++ signature :
        void setSelectionMarker(class PyGiSubEntityTraits {lvalue},__int64)'''
    ...
    def setShadowFlags (self, *args, **kwargs)-> None :
      '''setShadowFlags( (SubEntityTraits)arg1, (ShadowFlags)arg2) -> None :

    C++ signature :
        void setShadowFlags(class PyGiSubEntityTraits {lvalue},enum AcGiSubEntityTraits::ShadowFlags)'''
    ...
    def setThickness (self, *args, **kwargs)-> None :
      '''setThickness( (SubEntityTraits)arg1, (float)arg2) -> None :

    C++ signature :
        void setThickness(class PyGiSubEntityTraits {lvalue},double)'''
    ...
    def setTransparency (self, *args, **kwargs)-> None :
      '''setTransparency( (SubEntityTraits)arg1, (Transparency)arg2) -> None :

    C++ signature :
        void setTransparency(class PyGiSubEntityTraits {lvalue},class AcCmTransparency)'''
    ...
    def setTrueColor (self, *args, **kwargs)-> None :
      '''setTrueColor( (SubEntityTraits)arg1, (EntityColor)arg2) -> None :

    C++ signature :
        void setTrueColor(class PyGiSubEntityTraits {lvalue},class AcCmEntityColor)'''
    ...
    def setVisualStyle (self, *args, **kwargs)-> None :
      '''setVisualStyle( (SubEntityTraits)arg1, (ObjectId)arg2) -> None :

    C++ signature :
        void setVisualStyle(class PyGiSubEntityTraits {lvalue},class PyDbObjectId)'''
    ...
    def shadowFlags (self, *args, **kwargs)-> PyGi.ShadowFlags :
      '''shadowFlags( (SubEntityTraits)arg1) -> ShadowFlags :

    C++ signature :
        enum AcGiSubEntityTraits::ShadowFlags shadowFlags(class PyGiSubEntityTraits {lvalue})'''
    ...
    def thickness (self, *args, **kwargs)-> float :
      '''thickness( (SubEntityTraits)arg1) -> float :

    C++ signature :
        double thickness(class PyGiSubEntityTraits {lvalue})'''
    ...
    def transparency (self, *args, **kwargs)-> PyDb.Transparency :
      '''transparency( (SubEntityTraits)arg1) -> Transparency :

    C++ signature :
        class AcCmTransparency transparency(class PyGiSubEntityTraits {lvalue})'''
    ...
    def trueColor (self, *args, **kwargs)-> PyDb.EntityColor :
      '''trueColor( (SubEntityTraits)arg1) -> EntityColor :

    C++ signature :
        class AcCmEntityColor trueColor(class PyGiSubEntityTraits {lvalue})'''
    ...
    def visualStyle (self, *args, **kwargs)-> PyDb.ObjectId :
      '''visualStyle( (SubEntityTraits)arg1) -> ObjectId :

    C++ signature :
        class PyDbObjectId visualStyle(class PyGiSubEntityTraits {lvalue})'''
    ...

class TransientDrawingMode(object):
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
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
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
    ...
    def addChildTransient (self, *args, **kwargs)-> bool :
      '''addChildTransient( (TransientManager)arg1, (Drawable)arg2, (Drawable)arg3) -> bool :

    C++ signature :
        bool addChildTransient(class PyGiTransientManager {lvalue},class PyGiDrawable {lvalue},class PyGiDrawable {lvalue})'''
    ...
    def addTransient (self, *args, **kwargs)-> bool :
      '''addTransient( (TransientManager)arg1, (Drawable)arg2, (TransientDrawingMode)arg3, (int)arg4, (list)arg5) -> bool :

    C++ signature :
        bool addTransient(class PyGiTransientManager {lvalue},class PyGiDrawable {lvalue},enum AcGiTransientDrawingMode,int,class boost::python::list)'''
    ...
    def current (self, *args, **kwargs)-> PyGi.TransientManager :
      '''current() -> TransientManager :

    C++ signature :
        class PyGiTransientManager current()'''
    ...
    def eraseChildTransient (self, *args, **kwargs)-> bool :
      '''eraseChildTransient( (TransientManager)arg1, (Drawable)arg2, (Drawable)arg3) -> bool :

    C++ signature :
        bool eraseChildTransient(class PyGiTransientManager {lvalue},class PyGiDrawable {lvalue},class PyGiDrawable {lvalue})'''
    ...
    def eraseTransient (self, *args, **kwargs)-> bool :
      '''eraseTransient( (TransientManager)arg1, (Drawable)arg2, (list)arg3) -> bool :

    C++ signature :
        bool eraseTransient(class PyGiTransientManager {lvalue},class PyGiDrawable {lvalue},class boost::python::list)'''
    ...
    def eraseTransients (self, *args, **kwargs)-> bool :
      '''eraseTransients( (TransientManager)arg1, (TransientDrawingMode)arg2, (int)arg3, (list)arg4) -> bool :

    C++ signature :
        bool eraseTransients(class PyGiTransientManager {lvalue},enum AcGiTransientDrawingMode,int,class boost::python::list)'''
    ...
    def getFreeSubDrawingMode (self, *args, **kwargs)-> tuple :
      '''getFreeSubDrawingMode( (TransientManager)arg1, (TransientDrawingMode)arg2, (int)arg3, (list)arg4) -> tuple :

    C++ signature :
        class boost::python::tuple getFreeSubDrawingMode(class PyGiTransientManager {lvalue},enum AcGiTransientDrawingMode,int,class boost::python::list)'''
    ...
    def updateChildTransient (self, *args, **kwargs)-> None :
      '''updateChildTransient( (TransientManager)arg1, (Drawable)arg2, (Drawable)arg3) -> None :

    C++ signature :
        void updateChildTransient(class PyGiTransientManager {lvalue},class PyGiDrawable {lvalue},class PyGiDrawable {lvalue})'''
    ...
    def updateTransient (self, *args, **kwargs)-> None :
      '''updateTransient( (TransientManager)arg1, (Drawable)arg2, (list)arg3) -> None :

    C++ signature :
        void updateTransient(class PyGiTransientManager {lvalue},class PyGiDrawable {lvalue},class boost::python::list)'''
    ...

class TransparencyMode(object):
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
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
    def circle (self, *args, **kwargs)-> bool :
      '''circle( (Geometry)arg1, (Point3d)arg2, (float)arg3, (Vector3d)arg4) -> bool :

    C++ signature :
        bool circle(class PyGiGeometry {lvalue},class AcGePoint3d,double,class AcGeVector3d)

circle( (Geometry)arg1, (Point3d)arg2, (Point3d)arg3, (Point3d)arg4) -> bool :

    C++ signature :
        bool circle(class PyGiGeometry {lvalue},class AcGePoint3d,class AcGePoint3d,class AcGePoint3d)'''
    ...
    def circularArc (self, *args, **kwargs)-> bool :
      '''circularArc( (Geometry)arg1, (Point3d)arg2, (float)arg3, (Vector3d)arg4, (Vector3d)arg5, (float)arg6) -> bool :

    C++ signature :
        bool circularArc(class PyGiGeometry {lvalue},class AcGePoint3d,double,class AcGeVector3d,class AcGeVector3d,double)

circularArc( (Geometry)arg1, (Point3d)arg2, (float)arg3, (Vector3d)arg4, (Vector3d)arg5, (float)arg6, (ArcType)arg7) -> bool :

    C++ signature :
        bool circularArc(class PyGiGeometry {lvalue},class AcGePoint3d,double,class AcGeVector3d,class AcGeVector3d,double,enum AcGiArcType)

circularArc( (Geometry)arg1, (Point3d)arg2, (Point3d)arg3, (Point3d)arg4) -> bool :

    C++ signature :
        bool circularArc(class PyGiGeometry {lvalue},class AcGePoint3d,class AcGePoint3d,class AcGePoint3d)

circularArc( (Geometry)arg1, (Point3d)arg2, (Point3d)arg3, (Point3d)arg4, (ArcType)arg5) -> bool :

    C++ signature :
        bool circularArc(class PyGiGeometry {lvalue},class AcGePoint3d,class AcGePoint3d,class AcGePoint3d,enum AcGiArcType)'''
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
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
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
    def circle (self, *args, **kwargs)-> bool :
      '''circle( (Geometry)arg1, (Point3d)arg2, (float)arg3, (Vector3d)arg4) -> bool :

    C++ signature :
        bool circle(class PyGiGeometry {lvalue},class AcGePoint3d,double,class AcGeVector3d)

circle( (Geometry)arg1, (Point3d)arg2, (Point3d)arg3, (Point3d)arg4) -> bool :

    C++ signature :
        bool circle(class PyGiGeometry {lvalue},class AcGePoint3d,class AcGePoint3d,class AcGePoint3d)'''
    ...
    def circularArc (self, *args, **kwargs)-> bool :
      '''circularArc( (Geometry)arg1, (Point3d)arg2, (float)arg3, (Vector3d)arg4, (Vector3d)arg5, (float)arg6) -> bool :

    C++ signature :
        bool circularArc(class PyGiGeometry {lvalue},class AcGePoint3d,double,class AcGeVector3d,class AcGeVector3d,double)

circularArc( (Geometry)arg1, (Point3d)arg2, (float)arg3, (Vector3d)arg4, (Vector3d)arg5, (float)arg6, (ArcType)arg7) -> bool :

    C++ signature :
        bool circularArc(class PyGiGeometry {lvalue},class AcGePoint3d,double,class AcGeVector3d,class AcGeVector3d,double,enum AcGiArcType)

circularArc( (Geometry)arg1, (Point3d)arg2, (Point3d)arg3, (Point3d)arg4) -> bool :

    C++ signature :
        bool circularArc(class PyGiGeometry {lvalue},class AcGePoint3d,class AcGePoint3d,class AcGePoint3d)

circularArc( (Geometry)arg1, (Point3d)arg2, (Point3d)arg3, (Point3d)arg4, (ArcType)arg5) -> bool :

    C++ signature :
        bool circularArc(class PyGiGeometry {lvalue},class AcGePoint3d,class AcGePoint3d,class AcGePoint3d,enum AcGiArcType)'''
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
