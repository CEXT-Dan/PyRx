# PyGi

```PY




eAcGiRegenTypeInvalid: RegenType  # 0
kAcGiArcChord: ArcType  # 2
kAcGiArcSector: ArcType  # 1
kAcGiArcSimple: ArcType  # 0
kAcGiClockwise: OrientationType  # 1
kAcGiContrast: TransientDrawingMode  # 5
kAcGiCounterClockwise: OrientationType  # -1
kAcGiDirectShortTerm: TransientDrawingMode  # 2
kAcGiDirectTopmost: TransientDrawingMode  # 4
kAcGiDrawingModeCount: TransientDrawingMode  # 6
kAcGiFillAlways: FillType  # 1
kAcGiFillNever: FillType  # 2
kAcGiForExplode: RegenType  # 5
kAcGiHideOrShadeCommand: RegenType  # 3
kAcGiHighlight: TransientDrawingMode  # 3
kAcGiInvisible: Visibility  # 0
kAcGiMain: TransientDrawingMode  # 0
kAcGiNoOrientation: OrientationType  # 0
kAcGiSaveWorldDrawForProxy: RegenType  # 6
kAcGiScreenLocalOriginPosition: PositionTransformBehavior  # 3
kAcGiScreenLocalOriginScale: ScaleTransformBehavior  # 4
kAcGiScreenOrientation: OrientationTransformBehavior  # 1
kAcGiScreenPosition: PositionTransformBehavior  # 2
kAcGiScreenScale: ScaleTransformBehavior  # 2
kAcGiShadedDisplay: RegenType  # 4
kAcGiSilhouette: Visibility  # 2
kAcGiSprite: TransientDrawingMode  # 1
kAcGiStandardDisplay: RegenType  # 2
kAcGiViewportLocalOriginScale: ScaleTransformBehavior  # 3
kAcGiViewportPosition: PositionTransformBehavior  # 1
kAcGiViewportScale: ScaleTransformBehavior  # 1
kAcGiVisible: Visibility  # 1
kAcGiWorldOrientation: OrientationTransformBehavior  # 0
kAcGiWorldPosition: PositionTransformBehavior  # 0
kAcGiWorldScale: ScaleTransformBehavior  # 0
kAcGiWorldWithScreenOffsetPosition: PositionTransformBehavior  # 4
kAcGiZAxisOrientation: OrientationTransformBehavior  # 2
kAmbientLight: GiDrawableType  # 4
kBackLighting: DefaultLightingType  # 2
kDistantLight: GiDrawableType  # 1
kDrawFillSelectionWindow: DrawFlags  # 1024
kDrawFillTextBoundaryEnd: DrawFlags  # 512
kDrawFillTextBoundaryStart: DrawFlags  # 256
kDrawFrontfacesOnly: DrawFlags  # 4
kDrawGradientFill: DrawFlags  # 8
kDrawHatchGroup: DrawFlags  # 2
kDrawIsInWCS: DrawFlags  # 4096
kDrawNoForceByLayer: DrawFlags  # 2048
kDrawNoImageFrame: DrawFlags  # 8192
kDrawNoLineWeight: DrawFlags  # 32
kDrawNoOptimization: DrawFlags  # 64
kDrawSolidFill: DrawFlags  # 16
kDrawUseAcGiEntityForDgnLineType: DrawFlags  # 128
kDrawableBlockDependentViewportDraw: GiAttributesFlags  # 4096
kDrawableHasAttributes: GiAttributesFlags  # 32
kDrawableIsAnEntity: GiAttributesFlags  # 1
kDrawableIsCompoundObject: GiAttributesFlags  # 4
kDrawableIsDimension: GiAttributesFlags  # 133
kDrawableIsExternalReference: GiAttributesFlags  # 8192
kDrawableIsInvisible: GiAttributesFlags  # 16
kDrawableMergeControlOff: GiAttributesFlags  # 65536
kDrawableNone: GiAttributesFlags  # 0
kDrawableNotAllowLCS: GiAttributesFlags  # 32768
kDrawableNotPlottable: GiAttributesFlags  # 16384
kDrawableRegenDraw: GiAttributesFlags  # 256
kDrawableRegenTypeDependentGeometry: GiAttributesFlags  # 64
kDrawableShadedDisplaySingleLOD: GiAttributesFlags  # 1024
kDrawableStandardDisplaySingleLOD: GiAttributesFlags  # 512
kDrawableUsesNesting: GiAttributesFlags  # 2
kDrawableViewDependentViewportDraw: GiAttributesFlags  # 2048
kDrawableViewIndependentViewportDraw: GiAttributesFlags  # 8
kGeometry: GiDrawableType  # 0
kGradientBackground: GiDrawableType  # 6
kGroundPlaneBackground: GiDrawableType  # 8
kImageBackground: GiDrawableType  # 7
kImageBasedLightingBackground: GiDrawableType  # 12
kNoDrawFlags: ShadowFlags  # 0
kNoSelectionFlags: SelectionFlags  # 0
kOneDistantLight: DefaultLightingType  # 0
kPointLight: GiDrawableType  # 2
kSelectionIgnore: SelectionFlags  # 1
kShadowsDoesNotCast: ShadowFlags  # 1
kShadowsDoesNotReceive: ShadowFlags  # 2
kShadowsIgnore: ShadowFlags  # 3
kSkyBackground: GiDrawableType  # 11
kSolidBackground: GiDrawableType  # 5
kSpotLight: GiDrawableType  # 3
kThreadedWorldDrawViewportDraw: GiAttributesFlags  # 131072
kTransparency1Bit: TransparencyMode  # 1
kTransparency8Bit: TransparencyMode  # 2
kTransparencyOff: TransparencyMode  # 0
kTwoDistantLights: DefaultLightingType  # 1
kViewport: GiDrawableType  # 9
kWebLight: GiDrawableType  # 10

class ArcType(_BoostPythonEnum):
    kAcGiArcSimple: ClassVar[Self]  # 0
    kAcGiArcSector: ClassVar[Self]  # 1
    kAcGiArcChord: ClassVar[Self]  # 2

class CommonDraw(PyRx.RxObject):
    def __init__(self) -> None:
    @staticmethod
    def className() -> str:  
    @staticmethod
    def desc() -> PyRx.RxClass:
    def isDragging(self, /) -> bool:
    def regenAbort(self, /) -> bool:
    def regenType(self, /) -> RegenType:
    def subEntityTraits(self, /) -> SubEntityTraits:

class DefaultLightingType(_BoostPythonEnum):
    kOneDistantLight: ClassVar[Self]  # 0
    kTwoDistantLights: ClassVar[Self]  # 1
    kBackLighting: ClassVar[Self]  # 2

class DrawFlags(_BoostPythonEnum):
    kNoDrawFlags: ClassVar[Self]  # 0
    kDrawHatchGroup: ClassVar[Self]  # 2
    kDrawFrontfacesOnly: ClassVar[Self]  # 4
    kDrawGradientFill: ClassVar[Self]  # 8
    kDrawSolidFill: ClassVar[Self]  # 16
    kDrawNoLineWeight: ClassVar[Self]  # 32
    kDrawNoOptimization: ClassVar[Self]  # 64
    kDrawUseAcGiEntityForDgnLineType: ClassVar[Self]  # 128
    kDrawFillTextBoundaryStart: ClassVar[Self]  # 256
    kDrawFillTextBoundaryEnd: ClassVar[Self]  # 512
    kDrawFillSelectionWindow: ClassVar[Self]  # 1024
    kDrawNoForceByLayer: ClassVar[Self]  # 2048
    kDrawIsInWCS: ClassVar[Self]  # 4096
    kDrawNoImageFrame: ClassVar[Self]  # 8192

class Drawable(PyRx.RxObject):
    def __init__(self) -> None:
    def bounds(self, ext: PyDb.Extents, /) -> bool:
    @staticmethod
    def className() -> str:  
    @staticmethod
    def desc() -> PyRx.RxClass:
    def drawableType(self, /) -> GiDrawableType:
    def id(self, /) -> PyDb.ObjectId:
    def isPersistent(self, /) -> bool:
    def rolloverHit(self, nSubentId: int, nMouseFlags: int, bReset: bool, /) -> bool:
    def setAttributes(self, traits: PyGi.DrawableTraits, /) -> int:
    def viewportDraw(self, vpdraw: PyGi.ViewportDraw, /) -> None:
    def viewportDrawLogicalFlags(self, vpdraw: PyGi.ViewportDraw, /) -> int:
    def worldDraw(self, wdraw: PyGi.WorldDraw, /) -> bool:

class DrawableOverrule(PyRx.Overrule):
    def __init__(self, /) -> None:  
    def baseViewportDraw(self, /) -> None:  
    def baseViewportDrawLogicalFlags(self, /) -> int:  
    def baseWorldDraw(self, /) -> bool:  
    @staticmethod
    def className() -> str:  
    @staticmethod
    def desc() -> PyRx.RxClass:  
    def isApplicable(self, /) -> bool:  
    def setAttributes(self, /) -> int:  
    def viewportDraw(self, /) -> None:  
    def viewportDrawLogicalFlags(self, /) -> int:  
    def worldDraw(self, /) -> bool:  

class DrawableTraits(PyGi.SubEntityTraits):
    def __init__(self) -> None:
    @staticmethod
    def className() -> str:  
    @staticmethod
    def desc() -> PyRx.RxClass:
    def setupForEntity(self, entity: PyDb.Entity, /) -> None:

class FillType(_BoostPythonEnum):
    kAcGiFillAlways: ClassVar[Self]  # 1
    kAcGiFillNever: ClassVar[Self]  # 2

class Geometry(PyRx.RxObject):
    def __init__(self) -> None:
    @overload
    def circle(self, center: PyGe.Point3d, radius: float, normal: PyGe.Vector3d, /) -> bool:
    @overload
    def circle(self, p1: PyGe.Point3d, p2: PyGe.Point3d, p3: PyGe.Point3d, /) -> bool:
    @overload
    def circle(self, *args) -> bool:
    @overload
    def circularArc(
        self,
        center: PyGe.Point3d,
        radius: float,
        normal: PyGe.Vector3d,
        startVector: PyGe.Vector3d,
        sweepAngle: float,
        /,
    ) -> bool:
    @overload
    def circularArc(
        self,
        center: PyGe.Point3d,
        radius: float,
        normal: PyGe.Vector3d,
        startVector: PyGe.Vector3d,
        sweepAngle: float,
        arcType: PyGi.ArcType,
        /,
    ) -> bool:
    @overload
    def circularArc(self, p1: PyGe.Point3d, p2: PyGe.Point3d, p3: PyGe.Point3d, /) -> bool:
    @overload
    def circularArc(
        self, p1: PyGe.Point3d, p2: PyGe.Point3d, p3: PyGe.Point3d, arcType: PyGe.ArcType, /
    ) -> bool:
    @overload
    def circularArc(self, *args) -> bool:
    @staticmethod
    def className() -> str:  
    @staticmethod
    def desc() -> PyRx.RxClass:  
    def draw(self, drawable: PyGi.Drawable, /) -> bool:
    def edge(self, edgeList: list[PyGe.Curve2d], /) -> bool:
    def ellipticalArc(
        self,
        center: PyGe.Point3d,
        norm: PyGe.Vector3d,
        majAxisLen: float,
        minAxisLen: float,
        startDeg: float,
        endDeg: float,
        tilt: float,
        arcType: ArcType = kAcGiArcSimple,
        /,
    ) -> bool:
    def getModelToWorldTransform(self, /) -> PyGe.Matrix3d:
    def getWorldToModelTransform(self, /) -> PyGe.Matrix3d:
    @overload
    def image(
        self, image: wx.Image, position: PyGe.Point3d, u: PyGe.Vector3d, v: PyGe.Vector3d, /
    ) -> bool:
    @overload
    def image(
        self,
        image: PyGi.PixelBGRA32Array,
        width: int,
        height: int,
        position: PyGe.Point3d,
        u: PyGe.Vector3d,
        v: PyGe.Vector3d,
        /,
    ) -> bool:
    @overload
    def image(self, *args) -> bool:
    def pline(self, p1: PyDb.Polyline, fromIndex: int = 0, numSegs: int = 0, /) -> bool:
    def polygon(self, vertexList: list[PyGe.Point3d], /) -> bool:
    def polyline(
        self,
        vertexList: list[PyGe.Point3d],
        normal: PyGe.Vector3d = PyGe.Vector3d.kZAxis,
        marker: int = -1,
        /,
    ) -> bool:
    def popModelTransform(self, /) -> bool:
    def pushModelTransform(self, val: PyGe.Vector3d | PyGe.Matrix3d, /) -> bool:
    def pushOrientationTransform(
        self, behavior: PyGi.AcGiOrientationTransformBehavior, /
    ) -> PyGe.Matrix3d:
    def pushPositionTransform(
        self, behavior: PyGi.AcGiPositionTransformBehavior, offset: PyGe.Point2d | PyGe.Point2d, /
    ) -> PyGe.Matrix3d:
    def pushScaleTransform(
        self, behavior: PyGi.AcGiScaleTransformBehavior, extents: PyGe.Point2d | PyGe.Point2d, /
    ) -> PyGe.Matrix3d:
    def ray(self, p1: PyGe.Point3d, p2: PyGe.Point3d, /) -> bool:
    def rowOfDots(self, count: int, start: PyGe.Point3d, step: PyGe.Vector3d, /) -> bool:
    def text(
        self,
        pos: PyGe.Point3d,
        normal: PyGe.Vector3d,
        direction: PyGe.Vector3d,
        height: float,
        width: float,
        oblique: float,
        msg: str,
        /,
    ) -> bool:
    def worldLine(self, p1: PyGe.Point3d, p2: PyGe.Point3d, /) -> bool:
    def xline(self, p1: PyGe.Point3d, p2: PyGe.Point3d, /) -> bool:

class GiAttributesFlags(_BoostPythonEnum):
    kDrawableNone: ClassVar[Self]  # 0
    kDrawableIsAnEntity: ClassVar[Self]  # 1
    kDrawableUsesNesting: ClassVar[Self]  # 2
    kDrawableIsCompoundObject: ClassVar[Self]  # 4
    kDrawableViewIndependentViewportDraw: ClassVar[Self]  # 8
    kDrawableIsInvisible: ClassVar[Self]  # 16
    kDrawableHasAttributes: ClassVar[Self]  # 32
    kDrawableRegenTypeDependentGeometry: ClassVar[Self]  # 64
    kDrawableIsDimension: ClassVar[Self]  # 133
    kDrawableRegenDraw: ClassVar[Self]  # 256
    kDrawableStandardDisplaySingleLOD: ClassVar[Self]  # 512
    kDrawableShadedDisplaySingleLOD: ClassVar[Self]  # 1024
    kDrawableViewDependentViewportDraw: ClassVar[Self]  # 2048
    kDrawableBlockDependentViewportDraw: ClassVar[Self]  # 4096
    kDrawableIsExternalReference: ClassVar[Self]  # 8192
    kDrawableNotPlottable: ClassVar[Self]  # 16384
    kDrawableNotAllowLCS: ClassVar[Self]  # 32768
    kDrawableMergeControlOff: ClassVar[Self]  # 65536
    kThreadedWorldDrawViewportDraw: ClassVar[Self]  # 131072

class GiDrawableType(_BoostPythonEnum):
    kGeometry: ClassVar[Self]  # 0
    kDistantLight: ClassVar[Self]  # 1
    kPointLight: ClassVar[Self]  # 2
    kSpotLight: ClassVar[Self]  # 3
    kAmbientLight: ClassVar[Self]  # 4
    kSolidBackground: ClassVar[Self]  # 5
    kGradientBackground: ClassVar[Self]  # 6
    kImageBackground: ClassVar[Self]  # 7
    kGroundPlaneBackground: ClassVar[Self]  # 8
    kViewport: ClassVar[Self]  # 9
    kWebLight: ClassVar[Self]  # 10
    kSkyBackground: ClassVar[Self]  # 11
    kImageBasedLightingBackground: ClassVar[Self]  # 12

class GiGraphicsKernel:
    def __init__(self) -> None:
    @staticmethod
    def className() -> str:  
    def getDescriptor(self, /) -> GiKernelDescriptor:

class GiKernelDescriptor:
    def __init__(self) -> None:
    @staticmethod
    def className() -> str:  
    def supports(self, /) -> bool:

class OrientationTransformBehavior(_BoostPythonEnum):
    kAcGiWorldOrientation: ClassVar[Self]  # 0
    kAcGiScreenOrientation: ClassVar[Self]  # 1
    kAcGiZAxisOrientation: ClassVar[Self]  # 2

class OrientationType(_BoostPythonEnum):
    kAcGiCounterClockwise: ClassVar[Self]  # -1
    kAcGiNoOrientation: ClassVar[Self]  # 0
    kAcGiClockwise: ClassVar[Self]  # 1

class PixelBGRA32Array:
    def __contains__(self, /) -> bool:  
    def __delitem__(self, /) -> None:  
    def __getitem__(self, /) -> object:  
    def __init__(self, /) -> None:  
    def __iter__(self, /) -> object:  
    def __len__(self, /) -> int:  
    def __setitem__(self, /) -> None:  
    def append(self, /) -> None:  
    @staticmethod
    def createFromWxImage(image: wx.Image, alpha: int = 255, /) -> PixelBGRA32Array:  
    def extend(self, /) -> None:  

class PositionTransformBehavior(_BoostPythonEnum):
    kAcGiWorldPosition: ClassVar[Self]  # 0
    kAcGiViewportPosition: ClassVar[Self]  # 1
    kAcGiScreenPosition: ClassVar[Self]  # 2
    kAcGiScreenLocalOriginPosition: ClassVar[Self]  # 3
    kAcGiWorldWithScreenOffsetPosition: ClassVar[Self]  # 4

class RegenType(_BoostPythonEnum):
    eAcGiRegenTypeInvalid: ClassVar[Self]  # 0
    kAcGiStandardDisplay: ClassVar[Self]  # 2
    kAcGiHideOrShadeCommand: ClassVar[Self]  # 3
    kAcGiShadedDisplay: ClassVar[Self]  # 4
    kAcGiForExplode: ClassVar[Self]  # 5
    kAcGiSaveWorldDrawForProxy: ClassVar[Self]  # 6

class ScaleTransformBehavior(_BoostPythonEnum):
    kAcGiWorldScale: ClassVar[Self]  # 0
    kAcGiViewportScale: ClassVar[Self]  # 1
    kAcGiScreenScale: ClassVar[Self]  # 2
    kAcGiViewportLocalOriginScale: ClassVar[Self]  # 3
    kAcGiScreenLocalOriginScale: ClassVar[Self]  # 4

class SelectionFlags(_BoostPythonEnum):
    kNoSelectionFlags: ClassVar[Self]  # 0
    kSelectionIgnore: ClassVar[Self]  # 1

class ShadowFlags(_BoostPythonEnum):
    kNoDrawFlags: ClassVar[Self]  # 0
    kShadowsDoesNotCast: ClassVar[Self]  # 1
    kShadowsDoesNotReceive: ClassVar[Self]  # 2
    kShadowsIgnore: ClassVar[Self]  # 3

class SubEntityTraits(PyRx.RxObject):
    def __init__(self) -> None:
    @staticmethod
    def className() -> str:  
    def color(self, /) -> int:  
    @staticmethod
    def desc() -> PyRx.RxClass:
    def drawFlags(self, /) -> int:  
    def fillType(self, /) -> FillType:  
    def getPlotStyleNameId(self, /) -> PyDb.ObjectId:  
    def layerId(self, /) -> PyDb.ObjectId:  
    def lineTypeId(self, /) -> PyDb.ObjectId:  
    def lineTypeScale(self, /) -> float:  
    def lineWeight(self, /) -> PyDb.LineWeight:  
    def materialId(self, /) -> PyDb.ObjectId:  
    def sectionable(self, /) -> bool:  
    def selectionGeom(self, /) -> bool:  
    def setColor(self, val: int, /) -> None:  
    def setDrawFlags(self, flags: int, /) -> None:  
    def setFillType(self, val: PyGi.FillType, /) -> None:  
    def setLayer(self, id: PyDb.ObjectId, /) -> None:  
    def setLineType(self, id: PyDb.ObjectId, /) -> None:  
    def setLineTypeScale(self, val: float = 1.0, /) -> None:  
    def setLineWeight(self, val: PyDb.LineWeight, /) -> None:  
    def setMaterial(self, id: PyDb.ObjectId, /) -> None:  
    def setPlotStyleName(
        self, val: PyDb.PlotStyleNameType, id: PyDb.ObjectId =  , /
    ) -> None:  
    def setSectionable(self, val: bool, /) -> None:  
    def setSelectionGeom(self, val: bool, /) -> None:  
    def setSelectionMarker(self, val: int, /) -> None:  
    def setShadowFlags(self, val: PyGi.ShadowFlags, /) -> None:  
    def setThickness(self, val: float, /) -> None:  
    def setTransparency(self, val: PyDb.Transparency, /) -> None:  
    def setTrueColor(self, clr: PyDb.EntityColor, /) -> None:  
    def setVisualStyle(self, id: PyDb.ObjectId, /) -> None:  
    def shadowFlags(self, /) -> ShadowFlags:  
    def thickness(self, /) -> float:  
    def transparency(self, /) -> PyDb.Transparency:  
    def trueColor(self, /) -> PyDb.EntityColor:  
    def visualStyle(self, /) -> PyDb.ObjectId:  

class TransientDrawingMode(_BoostPythonEnum):
    kAcGiMain: ClassVar[Self]  # 0
    kAcGiSprite: ClassVar[Self]  # 1
    kAcGiDirectShortTerm: ClassVar[Self]  # 2
    kAcGiHighlight: ClassVar[Self]  # 3
    kAcGiDirectTopmost: ClassVar[Self]  # 4
    kAcGiContrast: ClassVar[Self]  # 5
    kAcGiDrawingModeCount: ClassVar[Self]  # 6

class TransientManager:
    def __init__(self, /) -> None:  
    def addChildTransient(self, drawable: PyGi.Drawable, parentDrawable: PyGi.Drawable, /) -> bool:
    def addTransient(
        self,
        drawable: PyGi.Drawable,
        mode: PyGi.TransientDrawingMode,
        subDrawingMode: int,
        viewportNumbers: list[int],
        /,
    ) -> bool:
    @staticmethod
    def current() -> TransientManager:  
    def eraseChildTransient(
        self, drawable: PyGi.Drawable, parentDrawable: PyGi.Drawable, /
    ) -> bool:
    def eraseTransient(self, drawable: PyGi.Drawable, viewportNumbers: list[int], /) -> bool:
    def eraseTransients(
        self, mode: PyGi.TransientDrawingMode, subDrawingMode: int, viewportNumbers: list[int], /
    ) -> bool:
    def getFreeSubDrawingMode(
        self, mode: PyGi.TransientDrawingMode, subDrawingMode: int, viewportNumbers: list[int], /
    ) -> tuple[int, int]:
    def updateChildTransient(
        self, drawable: PyGi.Drawable, parentDrawable: PyGi.Drawable, /
    ) -> None:
    def updateTransient(self, drawable: PyGi.Drawable, viewportNumbers: list[int], /) -> None:

class TransparencyMode(_BoostPythonEnum):
    kTransparencyOff: ClassVar[Self]  # 0
    kTransparency1Bit: ClassVar[Self]  # 1
    kTransparency8Bit: ClassVar[Self]  # 2

class ViewportDraw(PyGi.CommonDraw):
    def __init__(self) -> None:
    @staticmethod
    def className() -> str:  
    @staticmethod
    def desc() -> PyRx.RxClass:
    def geometry(self, /) -> ViewportGeometry:

class ViewportGeometry(PyGi.Geometry):
    def __init__(self) -> None:
    @staticmethod
    def className() -> str:  
    @staticmethod
    def desc() -> PyRx.RxClass:

class Visibility(_BoostPythonEnum):
    kAcGiInvisible: ClassVar[Self]  # 0
    kAcGiVisible: ClassVar[Self]  # 1
    kAcGiSilhouette: ClassVar[Self]  # 2

class WorldDraw(PyGi.CommonDraw):
    def __init__(self) -> None:
    @staticmethod
    def className() -> str:  
    @staticmethod
    def desc() -> PyRx.RxClass:
    def geometry(self, /) -> WorldGeometry:

class WorldGeometry(PyGi.Geometry):
    def __init__(self) -> None:
    @staticmethod
    def className() -> str:  
    @staticmethod
    def desc() -> PyRx.RxClass:
```
