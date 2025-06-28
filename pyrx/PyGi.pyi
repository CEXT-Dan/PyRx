from __future__ import annotations

from typing import Any, ClassVar, Self, overload

import wx

from pyrx import Db as PyDb
from pyrx import Ge as PyGe
from pyrx import Gi as PyGi
from pyrx import Rx as PyRx
from pyrx.doc_utils.boost_meta import _BoostPythonEnum

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
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /) -> Any: ...
    @staticmethod
    def className() -> str: ...
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def isDragging(self, /) -> bool:
        """
        Returns Adesk::kTrue if the entity is currently being dragged; otherwise, returns
        Adesk::kFalse. Graphically complex entities might find that using a simpler graphical
        representation during dragging enhances performance with little or no loss of
        functionality.
        """
    def regenAbort(self, /) -> bool:
        """
        Provides a means to find out if an immediate termination of the graphics regeneration is
        requested by the system. If the return value is Adesk::kFalse, then all is well. But, if
        the return value is Adesk::kTrue, then an immediate clean up and return should be
        accomplished.
        """
    def regenType(self, /) -> RegenType:
        """
        Returns the current elaboration mode. The current elaboration modes of type AcGiRegenType
        are: kAcGiStandardDisplay The display you normally see is being generated (REGEN).
        kAcGiHideOrShadeCommand The HIDE or SHADE command is being executed. kAcGRenderCommand The
        RENDER command is being executed. kAcGiSaveWorldDrawForProxy The graphics will be going
        into the entity's graphics metafile in case the entity is a proxy when next loaded, so
        provide graphics for proxy representation. This information allows the user to take special
        action for the four different situations. Normally, you may not need to consider which mode
        is in effect. However, if RENDER is running, then only geometry with filled area is
        accepted (filled polygon, etc.); other geometry (polyline, unfilled polygon, etc.) is
        ignored.
        """
    def subEntityTraits(self, /) -> SubEntityTraits:
        """
        Returns a reference to the AcGiSubEntityTraits object. The subEntityTraits object gives the
        user control of, and access to, the attribute (color, layer, linetype, etc.) settings of
        the current geometry. For a description of this object, see class AcGiSubEntityTraits.
        """

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
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /) -> Any: ...
    def bounds(self, ext: PyDb.Extents, /) -> bool:
        """
        This method returns reasonable, but not necessarily precise, bounds for the drawable. In
        the case of nested drawables, the bounds of any child drawables are included as well. In
        the case of view-dependent geometries, or other drawables with potentially varying bounds,
        the union of all possible representations is returned. In the case of uncertain extents or
        infinite extents (such as an infinite line or ray), the method returns False to indicate
        the bounds are not available. The behavior of the drawable is undefined if the geometry
        created by the drawable in its viewportDraw() and/or worldDraw() implementation extends
        outside the bounds returned by AcGiDrawable::bounds().
        """
    @staticmethod
    def className() -> str: ...
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def drawableType(self, /) -> GiDrawableType:
        """
        Returns the type of the current drawable.
        """
    def id(self, /) -> PyDb.ObjectId:
        """
        This function returns the database ID that corresponds to this drawable (if the drawable is
        persistent).
        """
    def isPersistent(self, /) -> bool:
        """
        This function will determine if the calling AcGiDrawable object is persistent (stored in a
        database). Returns Adesk::kTrue if the AcGiDrawable object is database resident (belongs to
        an AcGsModel that requires the use of open and close functions). Returns Adesk::kFalse if
        the AcGiDrawable object is non-persistent (pointer-based); these drawables are accessed
        directly through their AcGiDrawable pointer.
        """
    def rolloverHit(self, nSubentId: int, nMouseFlags: int, bReset: bool, /) -> bool:
        """
        For internal use only.
        """
    def setAttributes(self, traits: PyGi.DrawableTraits, /) -> int:
        """
        This function will take the input AcGiDrawableTraits object and set the values for the
        current object's subentity traits. The setAttributes() method is called by the GS to setup
        a drawable's default attributes. The current rendering state will employ these ambient
        attributes before worldDraw() and viewportDraw() are executed (and for the 3D GS before
        their cached geometry is drawn).
        """
    def viewportDraw(self, vpdraw: PyGi.ViewportDraw, /) -> None:
        """
        In response to viewportDraw(), a drawable uses the passed in AcGiViewportDraw interface to
        describe its view-dependent geometry. This function is called per view; the results may be
        cached, but the 3D GS guarantees it will call viewportDraw() (if specified by the return
        value from worldDraw()) for each view and whenever the view parameters are modified. See
        AcGsView for more information.
        """
    def viewportDrawLogicalFlags(self, vpdraw: PyGi.ViewportDraw, /) -> int:
        """
        Entity implementers who desire view-independent viewportDraw caching must provide a
        meaningful response to this API -- the return value is a combination of the
        AcGiDrawablesetAttributes flags. In particular, the graphic system is watching for the
        kDrawableRegenTypeDependantGeometry flag which indicates that the entity in this logical
        set employs isolines. The passed in AcGiViewportDraw context can be used by the drawable to
        help determine which logical set is being regenerated.
        """
    def worldDraw(self, wdraw: PyGi.WorldDraw, /) -> bool:
        """
        In response to worldDraw(), a drawable uses the passed-in AcGiWorldDraw interface to
        describe its geometry that is sharable across viewports. The 3D GS guarantees that this
        function will be called at least once, but subsequent display updates may be cached. Use
        AcGsModel::onModified() to invalidate any cache that the GS has associated with a drawable
        so that worldDraw() will again be called upon the next display update. A return value of
        Adesk::kFalse indicates that the 3D GS must call viewportDraw() in order to obtain the
        complete geometry and attribute set for this drawable.
        """

class DrawableOverrule(PyRx.Overrule):
    def __init__(self, /) -> None: ...
    def __reduce__(self, /) -> Any: ...
    def baseViewportDraw(self, /) -> None: ...
    def baseViewportDrawLogicalFlags(self, /) -> int: ...
    def baseWorldDraw(self, /) -> bool: ...
    @staticmethod
    def className() -> str: ...
    @staticmethod
    def desc() -> PyRx.RxClass: ...
    def isApplicable(self, /) -> bool: ...
    def setAttributes(self, /) -> int: ...
    def viewportDraw(self, /) -> None: ...
    def viewportDrawLogicalFlags(self, /) -> int: ...
    def worldDraw(self, /) -> bool: ...

class DrawableTraits(PyGi.SubEntityTraits):
    def __init__(self) -> None:
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /) -> Any: ...
    @staticmethod
    def className() -> str: ...
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def setupForEntity(self, entity: PyDb.Entity, /) -> None:
        """
        This call initializes the entire AcGiSubEntityTraits and AcGiDrawableTraits from the
        entity. This is more efficient than setting each property individually. The default
        implemetation of AcDbEntity::setAttributes() uses this method. If you are implementing AcGi
        you need not implement this method since and implementation is supplied which delegates to
        the setXXX methods in AcGiSubEntityTraits.
        """

class FillType(_BoostPythonEnum):
    kAcGiFillAlways: ClassVar[Self]  # 1
    kAcGiFillNever: ClassVar[Self]  # 2

class Geometry(PyRx.RxObject):
    def __init__(self) -> None:
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /) -> Any: ...
    @overload
    def circle(self, center: PyGe.Point3d, radius: float, normal: PyGe.Vector3d, /) -> bool:
        """
        Displays a circle primitive with center at center and a radius of radius. The circle is on
        the plane defined by the normal vector normal and the point center. A return value of
        Adesk::kFalse (that is, 0) indicates that the primitive has been successfully stored in the
        graphics database. A return value of Adesk::kTrue indicates that the operation has been
        terminated and the application wants to get control back as soon as possible.
        """
    @overload
    def circle(self, p1: PyGe.Point3d, p2: PyGe.Point3d, p3: PyGe.Point3d, /) -> bool:
        """
        Displays a circle primitive with center at center and a radius of radius. The circle is on
        the plane defined by the normal vector normal and the point center. A return value of
        Adesk::kFalse (that is, 0) indicates that the primitive has been successfully stored in the
        graphics database. A return value of Adesk::kTrue indicates that the operation has been
        terminated and the application wants to get control back as soon as possible.
        """
    @overload
    def circle(self, *args) -> bool:
        """
        Displays a circle primitive with center at center and a radius of radius. The circle is on
        the plane defined by the normal vector normal and the point center. A return value of
        Adesk::kFalse (that is, 0) indicates that the primitive has been successfully stored in the
        graphics database. A return value of Adesk::kTrue indicates that the operation has been
        terminated and the application wants to get control back as soon as possible.
        """
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
        """
        Displays an arc primitive defined by the arc's center of curvature center, the radius of
        curvature radius, the containment plane's normal vector normal, the vector from the center
        of curvature to the arc start point startVector, the angle that the arc spans sweepAngle,
        and the arc type arcType. A return value of Adesk::kFalse (that is, 0) indicates that the
        primitive has been successfully stored in the graphics database. A return value of
        Adesk::kTrue indicates that the operation has been terminated and the application wants to
        get control back as soon as possible.
        """
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
        """
        Displays an arc primitive defined by the arc's center of curvature center, the radius of
        curvature radius, the containment plane's normal vector normal, the vector from the center
        of curvature to the arc start point startVector, the angle that the arc spans sweepAngle,
        and the arc type arcType. A return value of Adesk::kFalse (that is, 0) indicates that the
        primitive has been successfully stored in the graphics database. A return value of
        Adesk::kTrue indicates that the operation has been terminated and the application wants to
        get control back as soon as possible.
        """
    @overload
    def circularArc(self, p1: PyGe.Point3d, p2: PyGe.Point3d, p3: PyGe.Point3d, /) -> bool:
        """
        Displays an arc primitive defined by the arc's center of curvature center, the radius of
        curvature radius, the containment plane's normal vector normal, the vector from the center
        of curvature to the arc start point startVector, the angle that the arc spans sweepAngle,
        and the arc type arcType. A return value of Adesk::kFalse (that is, 0) indicates that the
        primitive has been successfully stored in the graphics database. A return value of
        Adesk::kTrue indicates that the operation has been terminated and the application wants to
        get control back as soon as possible.
        """
    @overload
    def circularArc(
        self, p1: PyGe.Point3d, p2: PyGe.Point3d, p3: PyGe.Point3d, arcType: PyGe.ArcType, /
    ) -> bool:
        """
        Displays an arc primitive defined by the arc's center of curvature center, the radius of
        curvature radius, the containment plane's normal vector normal, the vector from the center
        of curvature to the arc start point startVector, the angle that the arc spans sweepAngle,
        and the arc type arcType. A return value of Adesk::kFalse (that is, 0) indicates that the
        primitive has been successfully stored in the graphics database. A return value of
        Adesk::kTrue indicates that the operation has been terminated and the application wants to
        get control back as soon as possible.
        """
    @overload
    def circularArc(self, *args) -> bool:
        """
        Displays an arc primitive defined by the arc's center of curvature center, the radius of
        curvature radius, the containment plane's normal vector normal, the vector from the center
        of curvature to the arc start point startVector, the angle that the arc spans sweepAngle,
        and the arc type arcType. A return value of Adesk::kFalse (that is, 0) indicates that the
        primitive has been successfully stored in the graphics database. A return value of
        Adesk::kTrue indicates that the operation has been terminated and the application wants to
        get control back as soon as possible.
        """
    @staticmethod
    def className() -> str: ...
    @staticmethod
    def desc() -> PyRx.RxClass: ...
    def draw(self, drawable: PyGi.Drawable, /) -> bool:
        """
        Instructs the graphics system to regenerate pDrawable as a component of this object. For
        example, a Block Definition (AcDbBlockTableRecord) uses it to draw its contained objects.
        Any object that owns another AcDb object should use this method to have that subentity draw
        itself (as opposed to directly calling its worldDraw() method). This allows a graphics
        system to cache the graphics of the object. Calling worldDraw directly would prevent this
        type of caching. To implement this method: Set up linetype, layer, color, and fill type for
        the AcGiDrawable using a call to setAttributes(), passing in your implementation of
        AcGiSubEntityTraits. Call worldDraw() on the drawable and record the return value. If false
        is returned, call viewportDraw() once for each viewport. Returning false to the caller
        indicates that you did not process the request.
        """
    def edge(self, edgeList: list[PyGe.Curve2d], /) -> bool:
        """
        Define the boundary of the fill.
        """
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
        """
        This method draws an elliptical arc or full ellipse, filled or unfilled.
        """
    def getModelToWorldTransform(self, /) -> PyGe.Matrix3d:
        """
        This gets the net block insert transform; that is, the model-to-world coordinate transform.
        The main purpose of the BLOCK entity is to transform an entity--whether to stretch, rotate,
        or move it. It is possible that during the current worldDraw(), the entity is in one or
        more BLOCKs. In this case, to determine the end result of the entity being transformed by
        one or more BLOCKs, use the net block insert transform (model-to-world coordinate
        transform) on your entity's model coordinate geometry. This will determine the location in
        world coordinate space that it occupies.
        """
    def getWorldToModelTransform(self, /) -> PyGe.Matrix3d:
        """
        This gets the inverse of the net block insert transform. This can transform an entity's
        world coordinate representation back into the original model coordinates.
        """
    @overload
    def image(
        self, image: wx.Image, position: PyGe.Point3d, u: PyGe.Vector3d, v: PyGe.Vector3d, /
    ) -> bool:
        """
        This method uses the basic transparent image parameters provided to determine where and
        what size image to paint. It will stretch the image if its size is not equal to specified
        size.
        """
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
        """
        This method uses the basic transparent image parameters provided to determine where and
        what size image to paint. It will stretch the image if its size is not equal to specified
        size.
        """
    @overload
    def image(self, *args) -> bool:
        """
        This method uses the basic transparent image parameters provided to determine where and
        what size image to paint. It will stretch the image if its size is not equal to specified
        size.
        """
    def pline(self, p1: PyDb.Polyline, fromIndex: int = 0, numSegs: int = 0, /) -> bool:
        """
        This function uses the AcDbPolylinelwBuf as the template for the geometry it draws. It
        generates display geometry that duplicates the geometry of the polyline's segments.
        """
    def polygon(self, vertexList: list[PyGe.Point3d], /) -> bool:
        """
        Draws a filled or unfilled polygon, depending on AcGiSubEntityTraits::fillType(). An edge
        between the last vertex and the first vertex is automatically created in order to generate
        a closed polygon. The caller is responsible for the memory used by the pVertexList array.
        """
    def polyline(
        self,
        vertexList: list[PyGe.Point3d],
        normal: PyGe.Vector3d = PyGe.Vector3d.kZAxis,
        marker: int = -1,
        /,
    ) -> bool:
        """
        Walks down the list of vertex points pVertexList drawing line segments from point to point
        (hence the requirement for a minimum of two points). If a thickness is currently specified
        it will be applied to the segments of this polyline. The caller is responsible for the
        memory used by the pVertexList array. The lBaseSubEntMarker argument has been added to
        allow the caller to specify sequential sub-entity markers for the segments of the polyline.
        If lBaseSubEntMarker'n' is greater than zero then the segments of the polyline will be
        assigned markers beginning with 'n' incrementing by 1 for each segment.
        """
    def popModelTransform(self, /) -> bool:
        """
        The method must be called to restore the model transform after a call to
        pushModelTransform(). Returns Adesk::kTrue if successful; otherwise, returns Adesk::kFalse.
        """
    def pushModelTransform(self, val: PyGe.Vector3d | PyGe.Matrix3d, /) -> bool:
        """
        This function pushes a new transform onto the transform stack. It generates the input
        matrix using the arbitrary axis algorithm and the supplied vector. When you have finished
        with the transform, you must call popModelTransform() to leave the pipe in the same state
        as before. Returns Adesk::kTrue if successful; otherwise, returns Adesk::kFalse.
        """
    def pushOrientationTransform(
        self, behavior: PyGi.AcGiOrientationTransformBehavior, /
    ) -> PyGe.Matrix3d:
        """
        This method places orientation transform behavior onto the current transform stack
        """
    def pushPositionTransform(
        self, behavior: PyGi.AcGiPositionTransformBehavior, offset: PyGe.Point2d | PyGe.Point2d, /
    ) -> PyGe.Matrix3d:
        """
        This method places position transform behavior onto the current transform stack.This method
        ignores z for position if behavior implies a 2D coordinate system, such as
        kAcGiViewportPosition, kAcGiScreenPosition , kAcGiScreenLocalOriginPosition, or
        kAcGiWorldWithScreenOffsetPosition .
        """
    def pushScaleTransform(
        self, behavior: PyGi.AcGiScaleTransformBehavior, extents: PyGe.Point2d | PyGe.Point2d, /
    ) -> PyGe.Matrix3d:
        """
        This method places scale transform behavior onto the current transform stack.This method
        ignores z for scale if behavior implies a 2D coordinate system, such as kAcGiViewportScale,
        kAcGiScreenScale, kAcGiViewportLocalOriginScale, or kAcGiScreenLocalOriginScale.
        """
    def ray(self, p1: PyGe.Point3d, p2: PyGe.Point3d, /) -> bool:
        """
        This function displays a ray that starts at raysStartingPoint and passes through
        aDifferentRayPoint. A return value of Adesk::kFalse (that is, 0) indicates that the
        primitive has been successfully stored in the graphics database. A return value of
        Adesk::kTrue indicates that the operation has been terminated and the application wants to
        get control back as soon as possible.
        """
    def rowOfDots(self, count: int, start: PyGe.Point3d, step: PyGe.Vector3d, /) -> bool:
        """
        This method draws a row of dots.
        """
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
        """
        This method uses the current AcGiTextStyle when generating the text graphics primitive.
        When worldDraw() is first entered, the AcGiTextStyle is set to the STANDARD text style
        that's built into the acad.exe file (not the STANDARD text style in the drawing). The
        position, normal, and direction can be thought of as the foundation for a coordinate system
        that orients the text in 3D world space, where the position is the origin, the direction is
        the X axis, and the normal is the Z axis. The obliquing angle for oblique is the angular
        slant from vertical of each character, much the way italic text is angled. A copy of the
        text string is used in pMsg, so the calling application is responsible for the memory of
        the string passed in. WarningThe direction and normal vectors must be mutually
        perpendicular or the results will be unpredictable. Here is an example of some text drawing
        code: Adesk::Boolean someEntity::worldDraw(AcGiWorldDraw *pWd){ // Position this text to
        start at 'origin', draw parallel // to the XY-plane at an upward slant of 45 degrees. //
        AcGePoint3d origin(2.0, 2.0, 3.0); AcGeVector3d direction(1.0, 1.0, 0.0); AcGeVector3d
        normal(0.0, 0.0, 1.0); pWd->geometry().text(origin, normal, direction, 1.0, 1.0, 0.0, 'some
        text'); return Adesk:kTrue;}A return value of Adesk::kFalse (that is, 0) indicates that the
        primitive has been successfully stored in the graphics database. A return value of
        Adesk::kTrue indicates that the operation has been terminated and the application wants to
        get control back as soon as possible.
        """
    def worldLine(self, p1: PyGe.Point3d, p2: PyGe.Point3d, /) -> bool:
        """
        This function draws a line between the two points in the pnts array. The points must be in
        world coordinates. A return value of Adesk::kFalse (that is, 0) indicates that the
        primitive has been successfully stored in the graphics database. A return value of
        Adesk::kTrue indicates that the operation has been terminated, and the application wants to
        get control back as soon as possible.
        """
    def xline(self, p1: PyGe.Point3d, p2: PyGe.Point3d, /) -> bool:
        """
        An xline passing oneXlinePoint and a DifferentXlinePoint is displayed. A return value of
        Adesk::kFalse (that is, 0) indicates that the primitive has been successfully stored in the
        graphics database. A return value of Adesk::kTrue indicates that the operation has been
        terminated and the application wants to get control back as soon as possible.
        """

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
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /) -> Any: ...
    @staticmethod
    def className() -> str: ...
    def getDescriptor(self, /) -> GiKernelDescriptor:
        """
        This method returns the kernel descriptor for the graphics kernel. A given kernel only has
        one descriptor, but it's possible for multiple kernels to have the same descriptor.
        """

class GiKernelDescriptor:
    def __init__(self) -> None:
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /) -> Any: ...
    @staticmethod
    def className() -> str: ...
    def supports(self, /) -> bool:
        """
        This used by a consumer of an AcGsGraphicsKernel to determine which features are supported
        by the kernel.
        """

class OrientationTransformBehavior(_BoostPythonEnum):
    kAcGiWorldOrientation: ClassVar[Self]  # 0
    kAcGiScreenOrientation: ClassVar[Self]  # 1
    kAcGiZAxisOrientation: ClassVar[Self]  # 2

class OrientationType(_BoostPythonEnum):
    kAcGiCounterClockwise: ClassVar[Self]  # -1
    kAcGiNoOrientation: ClassVar[Self]  # 0
    kAcGiClockwise: ClassVar[Self]  # 1

class PixelBGRA32Array:
    def __contains__(self, /) -> bool: ...
    def __delitem__(self, /) -> None: ...
    def __getitem__(self, /) -> object: ...
    def __init__(self, /) -> None: ...
    def __iter__(self, /) -> object: ...
    def __len__(self, /) -> int: ...
    def __reduce__(self, /) -> Any: ...
    def __setitem__(self, /) -> None: ...
    def append(self, /) -> None: ...
    @staticmethod
    def createFromWxImage(image: wx.Image, alpha: int = 255, /) -> PixelBGRA32Array: ...
    def extend(self, /) -> None: ...

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
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /) -> Any: ...
    @staticmethod
    def className() -> str: ...
    def color(self, /) -> int: ...
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def drawFlags(self, /) -> int: ...
    def fillType(self, /) -> FillType: ...
    def getPlotStyleNameId(self, /) -> PyDb.ObjectId: ...
    def layerId(self, /) -> PyDb.ObjectId: ...
    def lineTypeId(self, /) -> PyDb.ObjectId: ...
    def lineTypeScale(self, /) -> float: ...
    def lineWeight(self, /) -> PyDb.LineWeight: ...
    def materialId(self, /) -> PyDb.ObjectId: ...
    def sectionable(self, /) -> bool: ...
    def selectionGeom(self, /) -> bool: ...
    def setColor(self, val: int, /) -> None: ...
    def setDrawFlags(self, flags: int, /) -> None: ...
    def setFillType(self, val: PyGi.FillType, /) -> None: ...
    def setLayer(self, id: PyDb.ObjectId, /) -> None: ...
    def setLineType(self, id: PyDb.ObjectId, /) -> None: ...
    def setLineTypeScale(self, val: float = 1.0, /) -> None: ...
    def setLineWeight(self, val: PyDb.LineWeight, /) -> None: ...
    def setMaterial(self, id: PyDb.ObjectId, /) -> None: ...
    def setPlotStyleName(
        self, val: PyDb.PlotStyleNameType, id: PyDb.ObjectId = ..., /
    ) -> None: ...
    def setSectionable(self, val: bool, /) -> None: ...
    def setSelectionGeom(self, val: bool, /) -> None: ...
    def setSelectionMarker(self, val: int, /) -> None: ...
    def setShadowFlags(self, val: PyGi.ShadowFlags, /) -> None: ...
    def setThickness(self, val: float, /) -> None: ...
    def setTransparency(self, val: PyDb.Transparency, /) -> None: ...
    def setTrueColor(self, clr: PyDb.EntityColor, /) -> None: ...
    def setVisualStyle(self, id: PyDb.ObjectId, /) -> None: ...
    def shadowFlags(self, /) -> ShadowFlags: ...
    def thickness(self, /) -> float: ...
    def transparency(self, /) -> PyDb.Transparency: ...
    def trueColor(self, /) -> PyDb.EntityColor: ...
    def visualStyle(self, /) -> PyDb.ObjectId: ...

class TransientDrawingMode(_BoostPythonEnum):
    kAcGiMain: ClassVar[Self]  # 0
    kAcGiSprite: ClassVar[Self]  # 1
    kAcGiDirectShortTerm: ClassVar[Self]  # 2
    kAcGiHighlight: ClassVar[Self]  # 3
    kAcGiDirectTopmost: ClassVar[Self]  # 4
    kAcGiContrast: ClassVar[Self]  # 5
    kAcGiDrawingModeCount: ClassVar[Self]  # 6

class TransientManager:
    def __init__(self, /) -> None: ...
    def __reduce__(self, /) -> Any: ...
    def addChildTransient(self, drawable: PyGi.Drawable, parentDrawable: PyGi.Drawable, /) -> bool:
        """
        This function adds a child transient to specified parent transient. This allows for partial
        updates of the parent drawable. Returns true if successful. This function doesn't need to
        specify a drawing mode, subDrawingMode or viewportNumber; these properties of the child
        transient will be the same as parent transient
        """
    def addTransient(
        self,
        drawable: PyGi.Drawable,
        mode: PyGi.TransientDrawingMode,
        subDrawingMode: int,
        viewportNumbers: list[int],
        /,
    ) -> bool:
        """
        This function adds a transient to a list of viewports. Returns true if successful.
        """
    @staticmethod
    def current() -> TransientManager: ...
    def eraseChildTransient(
        self, drawable: PyGi.Drawable, parentDrawable: PyGi.Drawable, /
    ) -> bool:
        """
        This function erases a child transient from specified parent transient. Returns true if
        successful.
        """
    def eraseTransient(self, drawable: PyGi.Drawable, viewportNumbers: list[int], /) -> bool:
        """
        This function erases a transient from a list of viewports. Returns true if successful. This
        function erases a specified drawable which has been added by addTransient().
        """
    def eraseTransients(
        self, mode: PyGi.TransientDrawingMode, subDrawingMode: int, viewportNumbers: list[int], /
    ) -> bool:
        """
        This function erases all transients in the specified subDrawingMode from a list of
        viewports. Returns true if successful.
        """
    def getFreeSubDrawingMode(
        self, mode: PyGi.TransientDrawingMode, subDrawingMode: int, viewportNumbers: list[int], /
    ) -> tuple[int, int]:
        """
        Get the free draw order in a certain transient drawing mode. Returns 0 if the input draw
        order is not free and transient manager also could not get a free draw order. Returns 1 if
        the inputting draw order is available. Returns 2 if the inputting draw order is
        unavailable, but transient manager could return a free draw order.
        """
    def updateChildTransient(
        self, drawable: PyGi.Drawable, parentDrawable: PyGi.Drawable, /
    ) -> None:
        """
        This function only updates a child transient of the specified parent transient. This means
        partial updates of parent drawable.
        """
    def updateTransient(self, drawable: PyGi.Drawable, viewportNumbers: list[int], /) -> None:
        """
        Update a transient via the transient manager.
        """

class TransparencyMode(_BoostPythonEnum):
    kTransparencyOff: ClassVar[Self]  # 0
    kTransparency1Bit: ClassVar[Self]  # 1
    kTransparency8Bit: ClassVar[Self]  # 2

class ViewportDraw(PyGi.CommonDraw):
    def __init__(self) -> None:
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /) -> Any: ...
    @staticmethod
    def className() -> str: ...
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def geometry(self, /) -> ViewportGeometry:
        """
        Returns a reference to the AcGiViewportGeometry object. The viewportGeometry object allows
        the user to generate geometry (polylines, arcs, meshes, etc.). For a description of this
        object, see class AcGiViewportGeometry.
        """

class ViewportGeometry(PyGi.Geometry):
    def __init__(self) -> None:
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /) -> Any: ...
    @staticmethod
    def className() -> str: ...
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """

class Visibility(_BoostPythonEnum):
    kAcGiInvisible: ClassVar[Self]  # 0
    kAcGiVisible: ClassVar[Self]  # 1
    kAcGiSilhouette: ClassVar[Self]  # 2

class WorldDraw(PyGi.CommonDraw):
    def __init__(self) -> None:
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /) -> Any: ...
    @staticmethod
    def className() -> str: ...
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def geometry(self, /) -> WorldGeometry:
        """
        Returns a reference to the AcGiWorldGeometry object. The AcGiWorldGeometry object allows
        the user to generate geometry (polylines, arcs, meshes, etc.). For a description of this
        object, see class AcGiWorldGeometry.
        """

class WorldGeometry(PyGi.Geometry):
    def __init__(self) -> None:
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /) -> Any: ...
    @staticmethod
    def className() -> str: ...
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
