import PyRx
import PyGe
import PyGi
import PyGs
import PyDb
import PyAp
import PyEd
import PyPl
import PySm
import PyBr
from typing import overload
from typing import Any

class ArcType(object):
    def kAcGiArcChord (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kAcGiArcSector (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kAcGiArcSimple (self, *args, **kwargs)-> None :
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

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def isDragging (self)-> bool :
        '''Returns Adesk::kTrue if the entity is currently being dragged; otherwise, returns Adesk::kFalse.Graphically complex entities might find that using a simpler graphical representation during dragging enhances performance with little or no loss of functionality.'''
        ...
    def regenAbort (self)-> bool :
        '''Provides a means to find out if an immediate termination of the graphics regeneration is requested by the system. If the return value is Adesk::kFalse, then all is well. But, if the return value is Adesk::kTrue, then an immediate clean up and return should be accomplished.'''
        ...
    def regenType (self)-> PyGi.RegenType :
        '''Returns the current elaboration mode. The current elaboration modes of type AcGiRegenType are:kAcGiStandardDisplayThe display you normally see is being generated (REGEN).kAcGiHideOrShadeCommandThe HIDE or SHADE command is being executed.kAcGRenderCommandThe RENDER command is being executed.kAcGiSaveWorldDrawForProxyThe graphics will be going into the entity's graphics metafile in case the entity is a proxy when next loaded, so provide graphics for proxy representation.This information allows the user to take special action for the four different situations. Normally, you may not need to consider which mode is in effect. However, if RENDER is running, then only geometry with filled area is accepted (filled polygon, etc.); other geometry (polyline, unfilled polygon, etc.) is ignored.'''
        ...
    def subEntityTraits (self)-> PyGi.SubEntityTraits :
        '''Returns a reference to the AcGiSubEntityTraits object.The subEntityTraits object gives the user control of, and access to, the attribute (color, layer, linetype, etc.) settings of the current geometry. For a description of this object, see class AcGiSubEntityTraits.'''
        ...

class DefaultLightingType(object):
    def kBackLighting (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kOneDistantLight (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kTwoDistantLights (self, *args, **kwargs)-> None :
        '''None'''
        ...

class DrawFlags(object):
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

class Drawable(PyRx.RxObject):
    def __init__ (self, *args, **kwargs)-> None :
        '''Raises an exception
This class cannot be instantiated from Python'''
        ...
    def bounds (self, ext: PyDb.Extents)-> bool :
        '''This method returns reasonable, but not necessarily precise, bounds for the drawable. In the case of nested drawables, the bounds of any child drawables are included as well. In the case of view-dependent geometries, or other drawables with potentially varying bounds, the union of all possible representations is returned.In the case of uncertain extents or infinite extents (such as an infinite line or ray), the method returns False to indicate the bounds are not available.The behavior of the drawable is undefined if the geometry created by the drawable in its viewportDraw() and/or worldDraw() implementation extends outside the bounds returned by AcGiDrawable::bounds().'''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def drawableType (self)-> PyGi.GiDrawableType :
        '''Returns the type of the current drawable.'''
        ...
    def id (self)-> PyDb.ObjectId :
        '''This function returns the database ID that corresponds to this drawable (if the drawable is persistent).'''
        ...
    def isPersistent (self)-> bool :
        '''This function will determine if the calling AcGiDrawable object is persistent (stored in a database).Returns Adesk::kTrue if the AcGiDrawable object is database resident (belongs to an AcGsModel that requires the use of open and close functions). Returns Adesk::kFalse if the AcGiDrawable object is non-persistent (pointer-based); these drawables are accessed directly through their AcGiDrawable pointer.'''
        ...
    def rolloverHit (self, nSubentId: int, nMouseFlags: int, bReset: bool)-> bool :
        '''For internal use only.'''
        ...
    def setAttributes (self, traits: PyGi.DrawableTraits)-> int :
        '''This function will take the input AcGiDrawableTraits object and set the values for the current object's subentity traits.The setAttributes() method is called by the GS to setup a drawable's default attributes. The current rendering state will employ these ambient attributes before worldDraw() and viewportDraw() are executed (and for the 3D GS before their cached geometry is drawn).'''
        ...
    def viewportDraw (self, vpdraw: PyGi.ViewportDraw)-> None :
        '''In response to viewportDraw(), a drawable uses the passed in AcGiViewportDraw interface to describe its view-dependent geometry. This function is called per view; the results may be cached, but the 3D GS guarantees it will call viewportDraw() (if specified by the return value from worldDraw()) for each view and whenever the view parameters are modified. See AcGsView for more information.'''
        ...
    def viewportDrawLogicalFlags (self, vpdraw: PyGi.ViewportDraw)-> int :
        '''Entity implementers who desire view-independent viewportDraw caching must provide a meaningful response to this API -- the return value is a combination of the AcGiDrawablesetAttributes flags. In particular, the graphic system is watching for the kDrawableRegenTypeDependantGeometry flag which indicates that the entity in this logical set employs isolines. The passed in AcGiViewportDraw context can be used by the drawable to help determine which logical set is being regenerated.'''
        ...
    def worldDraw (self, wdraw: PyGi.WorldDraw)-> bool :
        '''In response to worldDraw(), a drawable uses the passed-in AcGiWorldDraw interface to describe its geometry that is sharable across viewports.The 3D GS guarantees that this function will be called at least once, but subsequent display updates may be cached. Use AcGsModel::onModified() to invalidate any cache that the GS has associated with a drawable so that worldDraw() will again be called upon the next display update.A return value of Adesk::kFalse indicates that the 3D GS must call viewportDraw() in order to obtain the complete geometry and attribute set for this drawable.'''
        ...

class DrawableOverrule(PyRx.Overrule):
    def __init__ (self, *args, **kwargs)-> None :
        '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
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
    def desc (self, *args, **kwargs)-> PyRx.RxClass :
        '''desc() -> RxClass :

    C++ signature :
        class PyRxClass desc()'''
        ...
    def isApplicable (self, *args, **kwargs)-> bool :
        '''isApplicable( (DrawableOverrule)arg1, (RxObject)arg2) -> bool :

    C++ signature :
        bool isApplicable(class PyGiDrawableOverrule {lvalue},class PyRxObject {lvalue})'''
        ...
    def setAttributes (self, *args, **kwargs)-> int :
        '''setAttributes( (DrawableOverrule)arg1, (Drawable)arg2, (DrawableTraits)arg3) -> int :

    C++ signature :
        unsigned int setAttributes(class PyGiDrawableOverrule {lvalue},class PyGiDrawable {lvalue},class PyGiDrawableTraits {lvalue})'''
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

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def setupForEntity (self, entity: PyDb.Entity)-> None :
        '''This call initializes the entire AcGiSubEntityTraits and AcGiDrawableTraits from the entity. This is more efficient than setting each property individually. The default implemetation of AcDbEntity::setAttributes() uses this method.If you are implementing AcGi you need not implement this method since and implementation is supplied which delegates to the setXXX methods in AcGiSubEntityTraits.'''
        ...

class FillType(object):
    def kAcGiFillAlways (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kAcGiFillNever (self, *args, **kwargs)-> None :
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
    
	-Displays a circle primitive with center at center and a radius of radius. The circle is on the plane defined by the normal vector normal and the point center.A return value of Adesk::kFalse (that is, 0) indicates that the primitive has been successfully stored in the graphics database. A return value of Adesk::kTrue indicates that the operation has been terminated and the application wants to get control back as soon as possible.-'''
        ...

    @overload
    def circularArc (self, center: PyGe.Point3d, radius: float, normal: PyGe.Vector3d, startVector: PyGe.Vector3d, sweepAngle: float)-> bool : ...
    @overload
    def circularArc (self, center: PyGe.Point3d, radius: float, normal: PyGe.Vector3d, startVector: PyGe.Vector3d, sweepAngle: float, arcType: PyGi.ArcType)-> bool : ...
    @overload
    def circularArc (self, p1: PyGe.Point3d, p2: PyGe.Point3d, p3: PyGe.Point3d)-> bool : ...
    @overload
    def circularArc (self, p1: PyGe.Point3d, p2: PyGe.Point3d, p3: PyGe.Point3d, arcType: PyGe.ArcType)-> bool : ...
    def circularArc (self, *args, **kwargs)-> bool :
        '''Overloads:
    - center: PyGe.Point3d, radius: float, normal: PyGe.Vector3d, startVector: PyGe.Vector3d, sweepAngle: float
    - center: PyGe.Point3d, radius: float, normal: PyGe.Vector3d, startVector: PyGe.Vector3d, sweepAngle: float, arcType: PyGi.ArcType
    - p1: PyGe.Point3d, p2: PyGe.Point3d, p3: PyGe.Point3d
    - p1: PyGe.Point3d, p2: PyGe.Point3d, p3: PyGe.Point3d, arcType: PyGe.ArcType
    
	-Displays an arc primitive defined by the arc's center of curvature center, the radius of curvature radius, the containment plane's normal vector normal, the vector from the center of curvature to the arc start point startVector, the angle that the arc spans sweepAngle, and the arc type arcType.A return value of Adesk::kFalse (that is, 0) indicates that the primitive has been successfully stored in the graphics database. A return value of Adesk::kTrue indicates that the operation has been terminated and the application wants to get control back as soon as possible.-'''
        ...
    def className (self, *args, **kwargs)-> str :
        '''className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
        ...
    def desc (self, *args, **kwargs)-> PyRx.RxClass :
        '''desc() -> RxClass :

    C++ signature :
        class PyRxClass desc()'''
        ...
    def draw (self, drawable : PyGi.Drawable)-> bool :
        '''Instructs the graphics system to regenerate pDrawable as a component of this object.For example, a Block Definition (AcDbBlockTableRecord) uses it to draw its contained objects. Any object that owns another AcDb object should use this method to have that subentity draw itself (as opposed to directly calling its worldDraw() method).This allows a graphics system to cache the graphics of the object. Calling worldDraw directly would prevent this type of caching.To implement this method:Set up linetype, layer, color, and fill type for the AcGiDrawable using a call to setAttributes(), passing in your implementation of AcGiSubEntityTraits.Call worldDraw() on the drawable and record the return value.If false is returned, call viewportDraw() once for each viewport.Returning false to the caller indicates that you did not process the request.'''
        ...
    def edge (self, edgeList : list[PyGe.Curve2d])-> bool :
        '''Define the boundary of the fill.'''
        ...
    def ellipticalArc (self, center:PyGe.Point3d, norm:PyGe.Vector3d, majAxisLen:float, minAxisLen:float, startDeg:float, endDeg:float, tilt:float, arcType:ArcType=kAcGiArcSimple)-> bool :
        '''This method draws an elliptical arc or full ellipse, filled or unfilled.'''
        ...
    def getModelToWorldTransform (self)-> PyGe.Matrix3d :
        '''This gets the net block insert transform; that is, the model-to-world coordinate transform. The main purpose of the BLOCK entity is to transform an entity--whether to stretch, rotate, or move it. It is possible that during the current worldDraw(), the entity is in one or more BLOCKs. In this case, to determine the end result of the entity being transformed by one or more BLOCKs, use the net block insert transform (model-to-world coordinate transform) on your entity's model coordinate geometry. This will determine the location in world coordinate space that it occupies.'''
        ...
    def getWorldToModelTransform (self)-> PyGe.Matrix3d :
        '''This gets the inverse of the net block insert transform. This can transform an entity's world coordinate representation back into the original model coordinates.'''
        ...
    def pline (self, p1 : PyDb.Polyline, fromIndex : int=0, numSegs : int=0)-> bool :
        '''This function uses the AcDbPolylinelwBuf as the template for the geometry it draws. It generates display geometry that duplicates the geometry of the polyline's segments.'''
        ...
    def polygon (self, vertexList : list[PyGe.Point3d])-> bool :
        '''Draws a filled or unfilled polygon, depending on AcGiSubEntityTraits::fillType(). An edge between the last vertex and the first vertex is automatically created in order to generate a closed polygon.The caller is responsible for the memory used by the pVertexList array.'''
        ...
    def polyline (self, vertexList : list[PyGe.Point3d], normal : PyGe.Vector3d=PyGe.Vector3d.kZAxis, marker : int=-1)-> bool :
        '''Walks down the list of vertex points pVertexList drawing line segments from point to point (hence the requirement for a minimum of two points). If a thickness is currently specified it will be applied to the segments of this polyline. The caller is responsible for the memory used by the pVertexList array.The lBaseSubEntMarker argument has been added to allow the caller to specify sequential sub-entity markers for the segments of the polyline. If lBaseSubEntMarker'n' is greater than zero then the segments of the polyline will be assigned markers beginning with 'n' incrementing by 1 for each segment.'''
        ...
    def popModelTransform (self)-> bool :
        '''The method must be called to restore the model transform after a call to pushModelTransform().Returns Adesk::kTrue if successful; otherwise, returns Adesk::kFalse.'''
        ...
    def pushModelTransform (self, val : PyGe.Vector3d|PyGe.Matrix3d)-> bool :
        '''This function pushes a new transform onto the transform stack. It generates the input matrix using the arbitrary axis algorithm and the supplied vector.When you have finished with the transform, you must call popModelTransform() to leave the pipe in the same state as before.Returns Adesk::kTrue if successful; otherwise, returns Adesk::kFalse.'''
        ...
    def pushOrientationTransform (self,  behavior : PyGi.AcGiOrientationTransformBehavior)-> PyGe.Matrix3d :
        '''This method places orientation transform behavior onto the current transform stack'''
        ...
    def pushPositionTransform (self, behavior : PyGi.AcGiPositionTransformBehavior,  offset : PyGe.Point2d|PyGe.Point2d)-> PyGe.Matrix3d :
        '''This method places position transform behavior onto the current transform stack.This method ignores z for position if behavior implies a 2D coordinate system, such as kAcGiViewportPosition, kAcGiScreenPosition , kAcGiScreenLocalOriginPosition, or kAcGiWorldWithScreenOffsetPosition .'''
        ...
    def pushScaleTransform (self, behavior : PyGi.AcGiScaleTransformBehavior,  extents : PyGe.Point2d|PyGe.Point2d)-> PyGe.Matrix3d :
        '''This method places scale transform behavior onto the current transform stack.This method ignores z for scale if behavior implies a 2D coordinate system, such as kAcGiViewportScale, kAcGiScreenScale, kAcGiViewportLocalOriginScale, or kAcGiScreenLocalOriginScale.'''
        ...
    def ray (self, p1 : PyGe.Point3d, p2 : PyGe.Point3d)-> bool :
        '''This function displays a ray that starts at raysStartingPoint and passes through aDifferentRayPoint.A return value of Adesk::kFalse (that is, 0) indicates that the primitive has been successfully stored in the graphics database. A return value of Adesk::kTrue indicates that the operation has been terminated and the application wants to get control back as soon as possible.'''
        ...
    def rowOfDots (self, count : int, start: PyGe.Point3d, step : PyGe.Vector3d)-> bool :
        '''This method draws a row of dots.'''
        ...
    def text (self, pos : PyGe.Point3d, normal : PyGe.Vector3d, direction : PyGe.Vector3d, height : float, width : float, oblique : float, msg : str)-> bool :
        '''This method uses the current AcGiTextStyle when generating the text graphics primitive. When worldDraw() is first entered, the AcGiTextStyle is set to the STANDARD text style that's built into the acad.exe file (not the STANDARD text style in the drawing).The position, normal, and direction can be thought of as the foundation for a coordinate system that orients the text in 3D world space, where the position is the origin, the direction is the X axis, and the normal is the Z axis.The obliquing angle for oblique is the angular slant from vertical of each character, much the way italic text is angled.A copy of the text string is used in pMsg, so the calling application is responsible for the memory of the string passed in.WarningThe direction and normal vectors must be mutually perpendicular or the results will be unpredictable.Here is an example of some text drawing code:Adesk::Boolean someEntity::worldDraw(AcGiWorldDraw *pWd){    // Position this text to start at 'origin', draw parallel    // to the XY-plane at an upward slant of 45 degrees.    //    AcGePoint3d origin(2.0, 2.0, 3.0);    AcGeVector3d direction(1.0, 1.0, 0.0);    AcGeVector3d normal(0.0, 0.0, 1.0);    pWd->geometry().text(origin, normal, direction, 1.0,        1.0, 0.0, "some text");    return Adesk:kTrue;}A return value of Adesk::kFalse (that is, 0) indicates that the primitive has been successfully stored in the graphics database. A return value of Adesk::kTrue indicates that the operation has been terminated and the application wants to get control back as soon as possible.'''
        ...
    def worldLine (self, p1 : PyGe.Point3d, p2 : PyGe.Point3d)-> bool :
        '''This function draws a line between the two points in the pnts array. The points must be in world coordinates.A return value of Adesk::kFalse (that is, 0) indicates that the primitive has been successfully stored in the graphics database. A return value of Adesk::kTrue indicates that the operation has been terminated, and the application wants to get control back as soon as possible.'''
        ...
    def xline (self, p1 : PyGe.Point3d, p2 : PyGe.Point3d)-> bool :
        '''An xline passing oneXlinePoint and a DifferentXlinePoint is displayed.A return value of Adesk::kFalse (that is, 0) indicates that the primitive has been successfully stored in the graphics database. A return value of Adesk::kTrue indicates that the operation has been terminated and the application wants to get control back as soon as possible.'''
        ...

class GiAttributesFlags(object):
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

class GiDrawableType(object):
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
    def getDescriptor (self)-> PyGi.GiKernelDescriptor :
        '''This method returns the kernel descriptor for the graphics kernel. A given kernel only has one descriptor, but it's possible for multiple kernels to have the same descriptor.'''
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
    def supports (self)-> bool :
        '''This used by a consumer of an AcGsGraphicsKernel to determine which features are supported by the kernel.'''
        ...

class OrientationTransformBehavior(object):
    def kAcGiScreenOrientation (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kAcGiWorldOrientation (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kAcGiZAxisOrientation (self, *args, **kwargs)-> None :
        '''None'''
        ...

class OrientationType(object):
    def kAcGiClockwise (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kAcGiCounterClockwise (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kAcGiNoOrientation (self, *args, **kwargs)-> None :
        '''None'''
        ...

class PositionTransformBehavior(object):
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

class RegenType(object):
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

class ScaleTransformBehavior(object):
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

class SelectionFlags(object):
    def kNoSelectionFlags (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kSelectionIgnore (self, *args, **kwargs)-> None :
        '''None'''
        ...

class ShadowFlags(object):
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

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
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
    def getFreeSubDrawingMode (self, mode: PyGi.TransientDrawingMode, subDrawingMode: int, viewportNumbers: list[int])-> tuple[int,int] :
        '''Get the free draw order in a certain transient drawing mode.Returns 0 if the input draw order is not free and transient manager also could not get a free draw order.Returns 1 if the inputting draw order is available.Returns 2 if the inputting draw order is unavailable, but transient manager could return a free draw order.'''
        ...
    def updateChildTransient (self, drawable: PyGi.Drawable, parentDrawable: PyGi.Drawable)-> None :
        '''This function only updates a child transient of the specified parent transient. This means partial updates of parent drawable.'''
        ...
    def updateTransient (self, drawable: PyGi.Drawable, viewportNumbers: list[int])-> None :
        '''Update a transient via the transient manager.'''
        ...

class TransparencyMode(object):
    def kTransparency1Bit (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kTransparency8Bit (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kTransparencyOff (self, *args, **kwargs)-> None :
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

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def geometry (self)-> PyGi.ViewportGeometry :
        '''Returns a reference to the AcGiViewportGeometry object. The viewportGeometry object allows the user to generate geometry (polylines, arcs, meshes, etc.). For a description of this object, see class AcGiViewportGeometry.'''
        ...

class ViewportGeometry(Geometry):
    def __init__ (self, *args, **kwargs)-> None :
        '''Raises an exception
This class cannot be instantiated from Python'''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...

class Visibility(object):
    def kAcGiInvisible (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kAcGiSilhouette (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kAcGiVisible (self, *args, **kwargs)-> None :
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

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def geometry (self)-> PyGi.WorldGeometry :
        '''Returns a reference to the AcGiWorldGeometry object. The AcGiWorldGeometry object allows the user to generate geometry (polylines, arcs, meshes, etc.). For a description of this object, see class AcGiWorldGeometry.'''
        ...

class WorldGeometry(Geometry):
    def __init__ (self, *args, **kwargs)-> None :
        '''Raises an exception
This class cannot be instantiated from Python'''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
