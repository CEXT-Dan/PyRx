import PyRx
import PyGe
import PyGi
import PyGs
import PyDb
import PyAp
import PyEd
import PyPl
from typing import overload

class AcGiArcType:
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

class AcGiFillType:
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

class AcGiOrientationTransformBehavior:
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

class AcGiOrientationType:
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

class AcGiPositionTransformBehavior:
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

class AcGiRegenType:
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

class AcGiScaleTransformBehavior:
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

class AcGiTransientDrawingMode:
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

class AcGiVisibility:
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

class CommonDraw:
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
    def isDragging (self)-> bool :
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
    def regenAbort (self)-> bool :
      '''                             '''
    ...
    def regenType (self)-> PyGi.AcGiRegenType :
      '''                             '''
    ...
    def subEntityTraits (self)-> PyGi.SubEntityTraits :
      '''                             '''
    ...

class DrawFlags:
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

class Drawable:
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
      '''                             '''
    ...
    def isKindOf (self, rhs: PyRx.RxClass)-> bool :
      '''                             '''
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
      '''                             '''
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

class DrawableOverrule:
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
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
      '''                             '''
    ...
    def copyFrom (self, other: PyRx.RxObject)-> None :
      '''                             '''
    ...
    def desc (self, *args, **kwargs)-> PyRx.RxClass :
      '''desc() -> RxClass :

    C++ signature :
        class PyRxClass desc()'''
    ...
    def dispose (self)-> None :
      '''                             '''
    ...
    def hasOverrule (self, *args, **kwargs)-> bool :
      '''hasOverrule( (RxObject)arg1, (RxClass)arg2) -> bool :

    C++ signature :
        bool hasOverrule(class PyRxObject {lvalue},class PyRxClass {lvalue})'''
    ...
    def implRefCount (self)-> int :
      '''                             '''
    ...
    def isA (self)-> PyRx.RxClass :
      '''                             '''
    ...
    def isApplicable (self, *args, **kwargs)-> bool :
      '''isApplicable( (DrawableOverrule)arg1, (RxObject)arg2) -> bool :

    C++ signature :
        bool isApplicable(class PyGiDrawableOverrule {lvalue},class PyRxObject {lvalue})'''
    ...
    def isKindOf (self, rhs: PyRx.RxClass)-> bool :
      '''                             '''
    ...
    def isNullObj (self)-> bool :
      '''                             '''
    ...
    def isOverruling (self, *args, **kwargs)-> bool :
      '''isOverruling() -> bool :

    C++ signature :
        bool isOverruling()'''
    ...
    def keepAlive (self, flag: bool)-> None :
      '''                             '''
    ...
    def queryX (self, rhs: PyRx.RxClass)-> PyRx.RxObject :
      '''                             '''
    ...
    def removeOverrule (self, *args, **kwargs)-> None :
      '''removeOverrule( (RxClass)arg1, (Overrule)arg2) -> None :

    C++ signature :
        void removeOverrule(class PyRxClass {lvalue},class PyRxOverrule {lvalue})'''
    ...
    def setAttributes (self, *args, **kwargs)-> int :
      '''setAttributes( (DrawableOverrule)arg1, (Drawable)arg2, (DrawableTraits)arg3) -> int :

    C++ signature :
        unsigned int setAttributes(class PyGiDrawableOverrule {lvalue},class PyGiDrawable {lvalue},class PyGiDrawableTraits {lvalue})'''
    ...
    def setIsOverruling (self, *args, **kwargs)-> None :
      '''setIsOverruling( (bool)arg1) -> None :

    C++ signature :
        void setIsOverruling(bool)'''
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

class DrawableTraits:
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
      '''                             '''
    ...
    def copyFrom (self, other: PyRx.RxObject)-> None :
      '''                             '''
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
    def fillType (self, *args, **kwargs)-> PyGi.AcGiFillType :
      '''fillType( (SubEntityTraits)arg1) -> AcGiFillType :

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
      '''                             '''
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
      '''setFillType( (SubEntityTraits)arg1, (AcGiFillType)arg2) -> None :

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

class Geometry:
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
    def className (self, *args, **kwargs)-> str :
      '''className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def comparedTo (self, other: PyRx.RxObject)-> PyRx.Ordering :
      '''                             '''
    ...
    def copyFrom (self, other: PyRx.RxObject)-> None :
      '''                             '''
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
      '''                             '''
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

class GiAttributesFlags:
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
    def name (self, *args, **kwargs)-> None :
      '''None'''
    ...

class GiDrawableType:
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

class GiGraphicsKernel:
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

class GiKernelDescriptor:
    def __init__ (self, *args, **kwargs)-> None :
      '''Raises an exception
This class cannot be instantiated from Python'''
    ...
    def className (self, *args, **kwargs)-> str :
      '''className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...

class SelectionFlags:
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

class ShadowFlags:
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

class SubEntityTraits:
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
      '''                             '''
    ...
    def copyFrom (self, other: PyRx.RxObject)-> None :
      '''                             '''
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
    def fillType (self, *args, **kwargs)-> PyGi.AcGiFillType :
      '''fillType( (SubEntityTraits)arg1) -> AcGiFillType :

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
      '''                             '''
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
      '''setFillType( (SubEntityTraits)arg1, (AcGiFillType)arg2) -> None :

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

class TransientManager:
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
      '''addTransient( (TransientManager)arg1, (Drawable)arg2, (AcGiTransientDrawingMode)arg3, (int)arg4, (list)arg5) -> bool :

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
      '''eraseTransients( (TransientManager)arg1, (AcGiTransientDrawingMode)arg2, (int)arg3, (list)arg4) -> bool :

    C++ signature :
        bool eraseTransients(class PyGiTransientManager {lvalue},enum AcGiTransientDrawingMode,int,class boost::python::list)'''
    ...
    def getFreeSubDrawingMode (self, *args, **kwargs)-> tuple :
      '''getFreeSubDrawingMode( (TransientManager)arg1, (AcGiTransientDrawingMode)arg2, (int)arg3, (list)arg4) -> tuple :

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

class TransparencyMode:
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

class ViewportDraw:
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
    def geometry (self)-> PyGi.ViewportGeometry :
      '''                             '''
    ...
    def implRefCount (self)-> int :
      '''                             '''
    ...
    def isA (self)-> PyRx.RxClass :
      '''                             '''
    ...
    def isDragging (self)-> bool :
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
    def regenAbort (self)-> bool :
      '''                             '''
    ...
    def regenType (self)-> PyGi.AcGiRegenType :
      '''                             '''
    ...
    def subEntityTraits (self)-> PyGi.SubEntityTraits :
      '''                             '''
    ...

class ViewportGeometry:
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
      '''                             '''
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

class WorldDraw:
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
    def geometry (self)-> PyGi.WorldGeometry :
      '''                             '''
    ...
    def implRefCount (self)-> int :
      '''                             '''
    ...
    def isA (self)-> PyRx.RxClass :
      '''                             '''
    ...
    def isDragging (self)-> bool :
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
    def regenAbort (self)-> bool :
      '''                             '''
    ...
    def regenType (self)-> PyGi.AcGiRegenType :
      '''                             '''
    ...
    def subEntityTraits (self)-> PyGi.SubEntityTraits :
      '''                             '''
    ...

class WorldGeometry:
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
      '''                             '''
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
