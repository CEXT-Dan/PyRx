#include "stdafx.h"
#include "PyDbViewport.h"
#include "PyDbObjectId.h"
#include "PyDbObjectContext.h"

using namespace boost::python;

void makePyDbViewportWrapper()
{
    constexpr const std::string_view setUcsOverloads = "Overloads:\n"
        "- origin: PyGe.Point3d, xAxis: PyGe.Vector3d, yAxis: PyGe.Vector3d\n"
        "- view: PyDb.OrthographicView\n"
        "- ucsId: PyDb.ObjectId";

    constexpr const std::string_view setViewDirectionOverloads = "Overloads:\n"
        "- view: PyDb.OrthographicView\n"
        "- dir: PyGe.Vector3d";


    PyDocString DS("Viewport");
    class_<PyDbViewport, bases<PyDbEntity>>("Viewport")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.ARGS({ "id: PyDb.ObjectId", "mode: OpenMode=kForRead", "erased: bool=False" })))
        .def("annotationScale", &PyDbViewport::annotationScale, DS.ARGS())
        .def("setAnnotationScale", &PyDbViewport::setAnnotationScale)
        .def("setModelView", &PyDbViewport::setModelView, DS.ARGS({ "val: PyDb.XrefObjectId" }))
        .def("getModelView", &PyDbViewport::getModelView, DS.ARGS())
        .def("removeModelView", &PyDbViewport::removeModelView, DS.ARGS())
        .def("setSheetView", &PyDbViewport::setSheetView, DS.ARGS({ "val : PyDb.ObjectId" }))
        .def("getSheetView", &PyDbViewport::getSheetView, DS.ARGS())
        .def("removeSheetView", &PyDbViewport::removeSheetView, DS.ARGS())
        .def("setLabelBlock", &PyDbViewport::setLabelBlock, DS.ARGS({ "val : PyDb.ObjectId" }))
        .def("getLabelBlock", &PyDbViewport::getLabelBlock, DS.ARGS())
        .def("removeLabelBlock", &PyDbViewport::removeLabelBlock, DS.ARGS())
        .def("syncModelView", &PyDbViewport::syncModelView, DS.ARGS())
        .def("height", &PyDbViewport::height, DS.ARGS())
        .def("setHeight", &PyDbViewport::setHeight, DS.ARGS({ "val : float" }))
        .def("width", &PyDbViewport::width, DS.ARGS())
        .def("setWidth", &PyDbViewport::setWidth, DS.ARGS({ "val : float" }))
        .def("centerPoint", &PyDbViewport::centerPoint, DS.ARGS())
        .def("setCenterPoint", &PyDbViewport::setCenterPoint, DS.ARGS({ "val : PyGe.Point3d" }))
        .def("number", &PyDbViewport::number, DS.ARGS())
        .def("isOn", &PyDbViewport::isOn, DS.ARGS())
        .def("setOn", &PyDbViewport::setOn, DS.ARGS())
        .def("setOff", &PyDbViewport::setOff, DS.ARGS())
        .def("setIsOn", &PyDbViewport::setIsOn, DS.ARGS({ "val : bool" }))
        .def("viewTarget", &PyDbViewport::viewTarget, DS.ARGS())
        .def("setViewTarget", &PyDbViewport::setViewTarget, DS.ARGS({ "val : PyGe.Point3d" }))
        .def("viewDirection", &PyDbViewport::viewDirection, DS.ARGS())
        .def("setViewDirection", &PyDbViewport::setViewDirection1)
        .def("viewHeight", &PyDbViewport::viewHeight, DS.ARGS())
        .def("setViewHeight", &PyDbViewport::setViewHeight, DS.ARGS({ "val : float" }))
        .def("viewCenter", &PyDbViewport::viewCenter, DS.ARGS())
        .def("setViewCenter", &PyDbViewport::setViewCenter, DS.ARGS({ "val : PyGe.Point2d" }))
        .def("twistAngle", &PyDbViewport::twistAngle, DS.ARGS())
        .def("setTwistAngle", &PyDbViewport::setTwistAngle, DS.ARGS({ "val : float" }))
        .def("lensLength", &PyDbViewport::lensLength, DS.ARGS())
        .def("setLensLength", &PyDbViewport::setLensLength, DS.ARGS({ "val : float" }))
        .def("isFrontClipOn", &PyDbViewport::isFrontClipOn, DS.ARGS())
        .def("setFrontClipOn", &PyDbViewport::setFrontClipOn1)
        .def("setFrontClipOff", &PyDbViewport::setFrontClipOff, DS.ARGS())
        .def("setFrontClipOn", &PyDbViewport::setFrontClipOn2)
        .def("isBackClipOn", &PyDbViewport::isBackClipOn, DS.ARGS())
        .def("setBackClipOn", &PyDbViewport::setBackClipOn1)
        .def("setBackClipOff", &PyDbViewport::setBackClipOff, DS.ARGS())
        .def("setBackClipOn", &PyDbViewport::setBackClipOn2, DS.ARGS({ "val: bool=True" }))
        .def("isFrontClipAtEyeOn", &PyDbViewport::isFrontClipAtEyeOn, DS.ARGS())
        .def("setFrontClipAtEyeOn", &PyDbViewport::setFrontClipAtEyeOn1)
        .def("setFrontClipAtEyeOff", &PyDbViewport::setFrontClipAtEyeOff, DS.ARGS())
        .def("setFrontClipAtEyeOn", &PyDbViewport::setFrontClipAtEyeOn2, DS.ARGS({ "val: bool=True" }))
        .def("frontClipDistance", &PyDbViewport::frontClipDistance, DS.ARGS())
        .def("setFrontClipDistance", &PyDbViewport::setFrontClipDistance)
        .def("backClipDistance", &PyDbViewport::backClipDistance, DS.ARGS())
        .def("setBackClipDistance", &PyDbViewport::setBackClipDistance, DS.ARGS({ "val: float" }))
        .def("isPerspectiveOn", &PyDbViewport::isPerspectiveOn, DS.ARGS())
        .def("setPerspectiveOn", &PyDbViewport::setPerspectiveOn1)
        .def("setPerspectiveOff", &PyDbViewport::setPerspectiveOff)
        .def("setPerspectiveOn", &PyDbViewport::setPerspectiveOn2, DS.ARGS({ "val: bool=True" }))
        .def("isUcsFollowModeOn", &PyDbViewport::isUcsFollowModeOn, DS.ARGS())
        .def("setUcsFollowModeOn", &PyDbViewport::setUcsFollowModeOn1)
        .def("setUcsFollowModeOff", &PyDbViewport::setUcsFollowModeOff, DS.ARGS())
        .def("setUcsFollowModeOn", &PyDbViewport::setUcsFollowModeOn2, DS.ARGS({ "val: bool=True" }))
        .def("isUcsIconVisible", &PyDbViewport::isUcsIconVisible, DS.ARGS())
        .def("setUcsIconVisible", &PyDbViewport::setUcsIconVisible1)
        .def("setUcsIconInvisible", &PyDbViewport::setUcsIconInvisible, DS.ARGS())
        .def("setUcsIconVisible", &PyDbViewport::setUcsIconVisible2, DS.ARGS({ "val: bool=True" }))
        .def("isUcsIconAtOrigin", &PyDbViewport::isUcsIconAtOrigin, DS.ARGS())
        .def("setUcsIconAtOrigin", &PyDbViewport::setUcsIconAtOrigin1)
        .def("setUcsIconAtCorner", &PyDbViewport::setUcsIconAtCorner, DS.ARGS())
        .def("setUcsIconAtOrigin", &PyDbViewport::setUcsIconAtOrigin2, DS.ARGS({ "val: bool=True" }))
        .def("isFastZoomOn", &PyDbViewport::isFastZoomOn, DS.ARGS())
        .def("setFastZoomOn", &PyDbViewport::setFastZoomOn1)
        .def("setFastZoomOff", &PyDbViewport::setFastZoomOff, DS.ARGS())
        .def("setFastZoomOn", &PyDbViewport::setFastZoomOn2, DS.ARGS({ "val: bool=True" }))
        .def("circleSides", &PyDbViewport::circleSides, DS.ARGS())
        .def("setCircleSides", &PyDbViewport::setCircleSides, DS.ARGS({ "val : int" }))
        .def("isSnapOn", &PyDbViewport::isSnapOn, DS.ARGS())
        .def("setSnapOn", &PyDbViewport::setSnapOn1)
        .def("setSnapOff", &PyDbViewport::setSnapOff, DS.ARGS())
        .def("setSnapOn", &PyDbViewport::setSnapOn2, DS.ARGS({ "val: bool=True" }))
        .def("isSnapIsometric", &PyDbViewport::isSnapIsometric, DS.ARGS())
        .def("setSnapIsometric", &PyDbViewport::setSnapIsometric1)
        .def("setSnapStandard", &PyDbViewport::setSnapStandard, DS.ARGS())
        .def("setSnapIsometric", &PyDbViewport::setSnapIsometric2, DS.ARGS({ "val: bool=True" }))
        .def("snapAngle", &PyDbViewport::snapAngle, DS.ARGS())
        .def("setSnapAngle", &PyDbViewport::setSnapAngle, DS.ARGS({ "val : float" }))
        .def("snapBasePoint", &PyDbViewport::snapBasePoint, DS.ARGS())
        .def("setSnapBasePoint", &PyDbViewport::setSnapBasePoint, DS.ARGS({ "val : PyGe.Point2d" }))
        .def("snapIncrement", &PyDbViewport::snapIncrement, DS.ARGS())
        .def("setSnapIncrement", &PyDbViewport::setSnapIncrement, DS.ARGS({ "val : PyGe.Vector2d" }))
        .def("snapIsoPair", &PyDbViewport::snapIsoPair, DS.ARGS())
        .def("setSnapIsoPair", &PyDbViewport::setSnapIsoPair, DS.ARGS({ "val : int" }))
        .def("isGridOn", &PyDbViewport::isGridOn, DS.ARGS())
        .def("setGridOn", &PyDbViewport::setGridOn1)
        .def("setGridOff", &PyDbViewport::setGridOff, DS.ARGS())
        .def("setGridOn", &PyDbViewport::setGridOn2, DS.ARGS({ "val: bool=True" }))
        .def("isGridBoundToLimits", &PyDbViewport::isGridBoundToLimits, DS.ARGS())
        .def("setGridBoundToLimits", &PyDbViewport::setGridBoundToLimits, DS.ARGS({ "val : bool" }))
        .def("isGridAdaptive", &PyDbViewport::isGridAdaptive, DS.ARGS())
        .def("setGridAdaptive", &PyDbViewport::setGridAdaptive, DS.ARGS({ "val : bool" }))
        .def("isGridSubdivisionRestricted", &PyDbViewport::isGridSubdivisionRestricted, DS.ARGS())
        .def("setGridSubdivisionRestricted", &PyDbViewport::setGridSubdivisionRestricted, DS.ARGS({ "val : bool" }))
        .def("isGridFollow", &PyDbViewport::isGridFollow, DS.ARGS())
        .def("setGridFollow", &PyDbViewport::setGridFollow, DS.ARGS({ "val : bool" }))
        .def("gridMajor", &PyDbViewport::gridMajor, DS.ARGS())
        .def("setGridMajor", &PyDbViewport::setGridMajor, DS.ARGS({ "val : int" }))
        .def("gridIncrement", &PyDbViewport::gridIncrement, DS.ARGS())
        .def("setGridIncrement", &PyDbViewport::setGridIncrement, DS.ARGS({ "val : PyGe.Vector2d" }))
        .def("hiddenLinesRemoved", &PyDbViewport::hiddenLinesRemoved, DS.ARGS())
        .def("showHiddenLines", &PyDbViewport::showHiddenLines, DS.ARGS())
        .def("removeHiddenLines", &PyDbViewport::removeHiddenLines1)
        .def("removeHiddenLines", &PyDbViewport::removeHiddenLines2, DS.ARGS({ "val: bool=True" }))
        .def("freezeLayersInViewport", &PyDbViewport::freezeLayersInViewport, DS.ARGS({ "ids : List[PyDb.ObjectId]" }))
        .def("thawLayersInViewport", &PyDbViewport::thawLayersInViewport, DS.ARGS({ "ids : List[PyDb.ObjectId]" }))
        .def("thawAllLayersInViewport", &PyDbViewport::thawAllLayersInViewport, DS.ARGS())
        .def("isLayerFrozenInViewport", &PyDbViewport::isLayerFrozenInViewport, DS.ARGS({ "val : PyDb.ObjectId" }))
        .def("getFrozenLayerList", &PyDbViewport::getFrozenLayerList, DS.ARGS())
        .def("updateDisplay", &PyDbViewport::updateDisplay, DS.ARGS())
        .def("background", &PyDbViewport::background, DS.ARGS())
        .def("setBackground", &PyDbViewport::setBackground, DS.ARGS({ "val : PyDb.ObjectId" }))
        .def("previousBackground", &PyDbViewport::previousBackground1)
        .def("previousBackground", &PyDbViewport::previousBackground2, DS.ARGS({ "type: PyGi.DrawableType = 'AcGiDrawable::kGeometry'" }))
        .def("setPreviousBackground", &PyDbViewport::setPreviousBackground1)
        .def("setPreviousBackground", &PyDbViewport::setPreviousBackground2)
        .def("setPreviousBackground", &PyDbViewport::setPreviousBackground3, DS.ARGS({ "id : PyDb.ObjectId","type: PyGi.DrawableType = 'AcGiDrawable::kGeometry'","force: bool=True" }))
        .def("previousBackgroundForcedSwitch", &PyDbViewport::previousBackgroundForcedSwitch, DS.ARGS())
        .def("visualStyle", &PyDbViewport::visualStyle, DS.ARGS())
        .def("setVisualStyle", &PyDbViewport::setVisualStyle, DS.ARGS({ "val : PyDb.ObjectId" }))
        .def("isDefaultLightingOn", &PyDbViewport::isDefaultLightingOn, DS.ARGS())
        .def("setDefaultLightingOn", &PyDbViewport::setDefaultLightingOn, DS.ARGS({ "val : bool" }))
        .def("defaultLightingType", &PyDbViewport::defaultLightingType, DS.ARGS())
        .def("setDefaultLightingType", &PyDbViewport::setDefaultLightingType)
        .def("brightness", &PyDbViewport::brightness, DS.ARGS())
        .def("setBrightness", &PyDbViewport::setBrightness, DS.ARGS({ "val : float" }))
        .def("contrast", &PyDbViewport::contrast, DS.ARGS())
        .def("setContrast", &PyDbViewport::setContrast, DS.ARGS({ "val : float" }))
        .def("ambientLightColor", &PyDbViewport::ambientLightColor, DS.ARGS())
        .def("setAmbientLightColor", &PyDbViewport::setAmbientLightColor, DS.ARGS({ "clr: PyDb.AcCmColor" }))
        .def("sunId", &PyDbViewport::sunId, DS.ARGS())
        .def("setSun", &PyDbViewport::setSun1)
        .def("setSun", &PyDbViewport::setSun2, DS.ARGS({ "retid: PyDb.ObjectId","sun: PyDb.Object","erase: bool=True" }))
        .def("isLocked", &PyDbViewport::isLocked, DS.ARGS())
        .def("setLocked", &PyDbViewport::setLocked1)
        .def("setUnlocked", &PyDbViewport::setUnlocked, DS.ARGS())
        .def("setLocked", &PyDbViewport::setLocked2, DS.ARGS({ "val : bool=True" }))
        .def("isTransparent", &PyDbViewport::isTransparent, DS.ARGS())
        .def("setTransparent", &PyDbViewport::setTransparent1)
        .def("setOpaque", &PyDbViewport::setOpaque, DS.ARGS())
        .def("setTransparent", &PyDbViewport::setTransparent2, DS.ARGS({ "val : bool=True" }))
        .def("customScale", &PyDbViewport::customScale, DS.ARGS())
        .def("setCustomScale", &PyDbViewport::setCustomScale, DS.ARGS({ "val: float" }))
        .def("standardScale", &PyDbViewport::standardScale, DS.ARGS())
        .def("setStandardScale", &PyDbViewport::setStandardScale, DS.ARGS({ "val: PyDb.StandardScaleType" }))
        .def("plotStyleSheet", &PyDbViewport::plotStyleSheet, DS.ARGS())
        .def("effectivePlotStyleSheet", &PyDbViewport::effectivePlotStyleSheet, DS.ARGS())
        .def("setPlotStyleSheet", &PyDbViewport::setPlotStyleSheet, DS.ARGS({ "val : str" }))
        .def("isNonRectClipOn", &PyDbViewport::isNonRectClipOn, DS.ARGS())
        .def("setNonRectClipOn", &PyDbViewport::setNonRectClipOn1)
        .def("setNonRectClipOff", &PyDbViewport::setNonRectClipOff, DS.ARGS())
        .def("setNonRectClipOn", &PyDbViewport::setNonRectClipOn2, DS.ARGS({ "val: bool=True" }))
        .def("nonRectClipEntityId", &PyDbViewport::nonRectClipEntityId, DS.ARGS())
        .def("setNonRectClipEntityId", &PyDbViewport::setNonRectClipEntityId, DS.ARGS({ "id: PyDb.ObjectId" }))
        .def("erased", &PyDbViewport::erased, DS.ARGS({ "obj: PyDb.Object","val: bool" }))
        .def("modified", &PyDbViewport::modified, DS.ARGS({ "obj: PyDb.Object" }))
        .def("copied", &PyDbViewport::copied, DS.ARGS({ "obj: PyDb.Object","newobj: PyDb.Object" }))
        .def("subObjModified", &PyDbViewport::subObjModified, DS.ARGS({ "obj: PyDb.Object","subobj: PyDb.Object" }))
        .def("getUcs", &PyDbViewport::getUcs, DS.ARGS())
        .def("isUcsOrthographic", &PyDbViewport::isUcsOrthographic, DS.ARGS())
        .def("ucsName", &PyDbViewport::ucsName, DS.ARGS())
        .def("elevation", &PyDbViewport::elevation, DS.ARGS())
        .def("setUcs", &PyDbViewport::setUcs1)
        .def("setUcs", &PyDbViewport::setUcs2)
        .def("setUcs", &PyDbViewport::setUcs3, DS.OVRL(setUcsOverloads))
        .def("setUcsToWorld", &PyDbViewport::setUcsToWorld, DS.ARGS())
        .def("setElevation", &PyDbViewport::setElevation, DS.ARGS({ "val: float" }))
        .def("isViewOrthographic", &PyDbViewport::isViewOrthographic, DS.ARGS())
        .def("setViewDirection", &PyDbViewport::setViewDirection2, DS.OVRL(setViewDirectionOverloads))
        .def("isUcsSavedWithViewport", &PyDbViewport::isUcsSavedWithViewport, DS.ARGS())
        .def("setUcsPerViewport", &PyDbViewport::setUcsPerViewport, DS.ARGS({ "val: bool" }))
        .def("shadePlot", &PyDbViewport::shadePlot, DS.ARGS())
        .def("setShadePlot", &PyDbViewport::setShadePlot1)
        .def("shadePlotId", &PyDbViewport::shadePlotId, DS.ARGS())
        .def("setShadePlot", &PyDbViewport::setShadePlot2, DS.ARGS({ "type: PyDb.VpShadePlotType","id: PyDb.ObjectId=None" }))
        .def("plotWireframe", &PyDbViewport::plotWireframe, DS.ARGS())
        .def("plotAsRaster", &PyDbViewport::plotAsRaster, DS.ARGS())
        .def("className", &PyDbViewport::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbViewport::desc, DS.SARGS()).staticmethod("desc")
        .def("cloneFrom", &PyDbViewport::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbViewport::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;

    enum_<AcDbViewport::StandardScaleType>("StandardScaleType")
        .value("kScaleToFit", AcDbViewport::StandardScaleType::kScaleToFit)
        .value("kCustomScale", AcDbViewport::StandardScaleType::kCustomScale)
        .value("k1_1", AcDbViewport::StandardScaleType::k1_1)
        .value("k1_2", AcDbViewport::StandardScaleType::k1_2)
        .value("k1_4", AcDbViewport::StandardScaleType::k1_4)
        .value("k1_5", AcDbViewport::StandardScaleType::k1_5)
        .value("k1_8", AcDbViewport::StandardScaleType::k1_8)
        .value("k1_10", AcDbViewport::StandardScaleType::k1_10)
        .value("k1_16", AcDbViewport::StandardScaleType::k1_16)
        .value("k1_20", AcDbViewport::StandardScaleType::k1_20)
        .value("k1_30", AcDbViewport::StandardScaleType::k1_30)
        .value("k1_40", AcDbViewport::StandardScaleType::k1_40)
        .value("k1_50", AcDbViewport::StandardScaleType::k1_50)
        .value("k1_100", AcDbViewport::StandardScaleType::k1_100)
        .value("k2_1", AcDbViewport::StandardScaleType::k2_1)
        .value("k4_1", AcDbViewport::StandardScaleType::k4_1)
        .value("k8_1", AcDbViewport::StandardScaleType::k8_1)
        .value("k10_1", AcDbViewport::StandardScaleType::k10_1)
        .value("k100_1", AcDbViewport::StandardScaleType::k100_1)
        .value("k1_128in_1ft", AcDbViewport::StandardScaleType::k1_128in_1ft)
        .value("k1_64in_1ft", AcDbViewport::StandardScaleType::k1_64in_1ft)
        .value("k1_32in_1ft", AcDbViewport::StandardScaleType::k1_32in_1ft)
        .value("k1_16in_1ft", AcDbViewport::StandardScaleType::k1_16in_1ft)
        .value("k3_32in_1ft", AcDbViewport::StandardScaleType::k3_32in_1ft)
        .value("k1_8in_1ft", AcDbViewport::StandardScaleType::k1_8in_1ft)
        .value("k3_16in_1ft", AcDbViewport::StandardScaleType::k3_16in_1ft)
        .value("k1_4in_1ft", AcDbViewport::StandardScaleType::k1_4in_1ft)
        .value("k3_8in_1ft", AcDbViewport::StandardScaleType::k3_8in_1ft)
        .value("k1_2in_1ft", AcDbViewport::StandardScaleType::k1_2in_1ft)
        .value("k3_4in_1ft", AcDbViewport::StandardScaleType::k3_4in_1ft)
        .value("k1in_1ft", AcDbViewport::StandardScaleType::k1in_1ft)
        .value("k1and1_2in_1ft", AcDbViewport::StandardScaleType::k1and1_2in_1ft)
        .value("k3in_1ft", AcDbViewport::StandardScaleType::k3in_1ft)
        .value("k6in_1ft", AcDbViewport::StandardScaleType::k6in_1ft)
        .value("k1ft_1ft", AcDbViewport::StandardScaleType::k1ft_1ft)
        .export_values()
        ;

    enum_<AcDbViewport::ShadePlotType>("VpShadePlotType")
        .value("kAsDisplayed", AcDbViewport::ShadePlotType::kAsDisplayed)
        .value("kWireframe", AcDbViewport::ShadePlotType::kWireframe)
        .value("kHidden", AcDbViewport::ShadePlotType::kHidden)
        .value("kRendered", AcDbViewport::ShadePlotType::kRendered)
        .value("kVisualStyle", AcDbViewport::ShadePlotType::kVisualStyle)
        .value("kRenderPreset", AcDbViewport::ShadePlotType::kRenderPreset)
        .export_values()
        ;
}

PyDbViewport::PyDbViewport()
    : PyDbViewport(new AcDbViewport(), true)
{
}

PyDbViewport::PyDbViewport(AcDbViewport* ptr, bool autoDelete)
    : PyDbEntity(ptr, autoDelete)
{
}

PyDbViewport::PyDbViewport(const PyDbObjectId& id)
    : PyDbViewport(id, AcDb::OpenMode::kForRead)
{
}

PyDbViewport::PyDbViewport(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbEntity(openAcDbObject<AcDbViewport>(id, mode), false)
{
}

PyDbViewport::PyDbViewport(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbEntity(openAcDbObject<AcDbViewport>(id, mode, erased), false)
{
}

void PyDbViewport::setModelView(const PyDbXrefObjectId& xrefObjId)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setModelView(xrefObjId.m_imp));
#endif
}

PyDbXrefObjectId PyDbViewport::getModelView() const
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    PyDbXrefObjectId id;
    PyThrowBadEs(impObj()->getModelView(id.m_imp));
    return id;
#endif
}


void PyDbViewport::removeModelView(void)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->removeModelView());
#endif
}

void PyDbViewport::setSheetView(PyDbObjectId objId)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setSheetView(objId.m_id));
#endif
}

PyDbObjectId PyDbViewport::getSheetView() const
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    PyDbObjectId id;
    PyThrowBadEs(impObj()->getSheetView(id.m_id));
    return id;
#endif
}

void PyDbViewport::removeSheetView(void)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->removeSheetView());
#endif
}

void PyDbViewport::setLabelBlock(PyDbObjectId& objId)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setLabelBlock(objId.m_id));
#endif
}

PyDbObjectId PyDbViewport::getLabelBlock() const
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    PyDbObjectId id;
    PyThrowBadEs(impObj()->getLabelBlock(id.m_id));
    return id;
#endif
}

void PyDbViewport::removeLabelBlock(void)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->removeLabelBlock());
#endif
}

void PyDbViewport::syncModelView(void)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->syncModelView());
#endif
}

double PyDbViewport::height() const
{
    return impObj()->height();
}

void PyDbViewport::setHeight(double val)
{
    return PyThrowBadEs(impObj()->setHeight(val));
}

double PyDbViewport::width() const
{
    return impObj()->width();
}

void PyDbViewport::setWidth(double val)
{
    return PyThrowBadEs(impObj()->setWidth(val));
}

AcGePoint3d PyDbViewport::centerPoint() const
{
    return impObj()->centerPoint();
}

void PyDbViewport::setCenterPoint(const AcGePoint3d& val)
{
    return PyThrowBadEs(impObj()->setCenterPoint(val));
}

Adesk::Int16 PyDbViewport::number() const
{
    return impObj()->number();
}

bool PyDbViewport::isOn() const
{
    return impObj()->isOn();
}

void PyDbViewport::setOn()
{
    return PyThrowBadEs(impObj()->setOn());
}

void PyDbViewport::setOff()
{
    return PyThrowBadEs(impObj()->setOff());
}

void PyDbViewport::setIsOn(bool bOn)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setIsOn(bOn));
#endif
}

AcGePoint3d PyDbViewport::viewTarget() const
{
    return impObj()->viewTarget();
}

void PyDbViewport::setViewTarget(const AcGePoint3d& val)
{
    return PyThrowBadEs(impObj()->setViewTarget(val));
}

AcGeVector3d PyDbViewport::viewDirection() const
{
    return impObj()->viewDirection();
}

void PyDbViewport::setViewDirection1(const AcGeVector3d& val)
{
    return PyThrowBadEs(impObj()->setViewDirection(val));
}

void PyDbViewport::setViewDirection2(AcDb::OrthographicView view)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setViewDirection(view));
#endif
}

bool PyDbViewport::isUcsSavedWithViewport() const
{
    return impObj()->isUcsSavedWithViewport();
}

void PyDbViewport::setUcsPerViewport(bool ucsvp)
{
    return impObj()->setUcsPerViewport(ucsvp);
}

AcDbViewport::ShadePlotType PyDbViewport::shadePlot() const
{
    return impObj()->shadePlot();
}

void PyDbViewport::setShadePlot1(const AcDbViewport::ShadePlotType val)
{
    return PyThrowBadEs(impObj()->setShadePlot(val));
}

void PyDbViewport::setShadePlot2(const AcDbViewport::ShadePlotType type, const PyDbObjectId shadePlotId)
{
    return PyThrowBadEs(impObj()->setShadePlot(type, shadePlotId.m_id));
}

bool PyDbViewport::plotWireframe() const
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return impObj()->plotWireframe();
#endif
}

bool PyDbViewport::plotAsRaster() const
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return impObj()->plotAsRaster();
#endif
}

PyDbObjectId PyDbViewport::shadePlotId() const
{
    return PyDbObjectId(impObj()->shadePlotId());
}

double PyDbViewport::viewHeight() const
{
    return impObj()->viewHeight();
}

void PyDbViewport::setViewHeight(double ht)
{
    return PyThrowBadEs(impObj()->setViewHeight(ht));
}

AcGePoint2d PyDbViewport::viewCenter() const
{
    return impObj()->viewCenter();
}

void PyDbViewport::setViewCenter(const AcGePoint2d& pt)
{
    return PyThrowBadEs(impObj()->setViewCenter(pt));
}

double PyDbViewport::twistAngle() const
{
    return impObj()->twistAngle();
}

void PyDbViewport::setTwistAngle(double val)
{
    return PyThrowBadEs(impObj()->setTwistAngle(val));
}

double PyDbViewport::lensLength() const
{
    return impObj()->lensLength();
}

void PyDbViewport::setLensLength(double val)
{
    return PyThrowBadEs(impObj()->setLensLength(val));
}

bool PyDbViewport::isFrontClipOn() const
{
    return impObj()->isFrontClipOn();
}

void PyDbViewport::setFrontClipOn1()
{
    return PyThrowBadEs(impObj()->setFrontClipOn());
}

void PyDbViewport::setFrontClipOn2(bool bOn)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setFrontClipOn(bOn));
#endif
}

bool PyDbViewport::isBackClipOn() const
{
    return impObj()->isBackClipOn();
}

void PyDbViewport::setFrontClipOff()
{
    return PyThrowBadEs(impObj()->setFrontClipOff());
}

void PyDbViewport::setBackClipOn1()
{
    return PyThrowBadEs(impObj()->setBackClipOn());
}

void PyDbViewport::setBackClipOn2(bool bOn)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setBackClipOn(bOn));
#endif
}

bool PyDbViewport::isFrontClipAtEyeOn() const
{
    return impObj()->isFrontClipAtEyeOn();
}

void PyDbViewport::setFrontClipAtEyeOn1()
{
    return PyThrowBadEs(impObj()->setFrontClipAtEyeOn());
}

void PyDbViewport::setFrontClipAtEyeOff()
{
    return PyThrowBadEs(impObj()->setFrontClipAtEyeOff());
}

void PyDbViewport::setFrontClipAtEyeOn2(bool bOn)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setFrontClipAtEyeOn(bOn));
#endif
}

double PyDbViewport::frontClipDistance() const
{
    return impObj()->frontClipDistance();
}

void PyDbViewport::setFrontClipDistance(double newVal)
{
    return PyThrowBadEs(impObj()->setFrontClipDistance(newVal));
}

double PyDbViewport::backClipDistance() const
{
    return impObj()->backClipDistance();
}

void PyDbViewport::setBackClipDistance(double newVal)
{
    return PyThrowBadEs(impObj()->setBackClipDistance(newVal));
}

bool PyDbViewport::isPerspectiveOn() const
{
    return impObj()->isPerspectiveOn();
}

void PyDbViewport::setPerspectiveOn1()
{
    return PyThrowBadEs(impObj()->setPerspectiveOn());
}

void PyDbViewport::setPerspectiveOff()
{
    return PyThrowBadEs(impObj()->setPerspectiveOff());
}

void PyDbViewport::setPerspectiveOn2(bool bOn)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setPerspectiveOn(bOn));
#endif
}

bool PyDbViewport::isUcsFollowModeOn() const
{
    return impObj()->isUcsFollowModeOn();
}

void PyDbViewport::setUcsFollowModeOn1()
{
    return PyThrowBadEs(impObj()->setUcsFollowModeOn());
}

void PyDbViewport::setUcsFollowModeOff()
{
    return PyThrowBadEs(impObj()->setUcsFollowModeOff());
}

void PyDbViewport::setUcsFollowModeOn2(bool bOn)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setUcsFollowModeOn(bOn));
#endif
}

bool PyDbViewport::isUcsIconVisible() const
{
    return impObj()->isUcsIconVisible();
}

void PyDbViewport::setUcsIconVisible1()
{
    return PyThrowBadEs(impObj()->setUcsIconVisible());
}

void PyDbViewport::setUcsIconInvisible()
{
    return PyThrowBadEs(impObj()->setUcsIconInvisible());
}

void PyDbViewport::setUcsIconVisible2(bool bOn)
{

#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setUcsIconVisible(bOn));
#endif
}

bool PyDbViewport::isUcsIconAtOrigin() const
{
    return impObj()->isUcsIconAtOrigin();
}

void PyDbViewport::setUcsIconAtOrigin1()
{
    return PyThrowBadEs(impObj()->setUcsIconAtOrigin());
}

void PyDbViewport::setUcsIconAtCorner()
{
    return PyThrowBadEs(impObj()->setUcsIconAtCorner());
}

void PyDbViewport::setUcsIconAtOrigin2(bool bOn)
{

#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setUcsIconAtOrigin(bOn));
#endif
}

bool PyDbViewport::isFastZoomOn() const
{
    return impObj()->isFastZoomOn();
}

void PyDbViewport::setBackClipOff()
{
    return PyThrowBadEs(impObj()->setBackClipOff());
}

void PyDbViewport::setFastZoomOn1()
{
    return PyThrowBadEs(impObj()->setFastZoomOn());
}

void PyDbViewport::setFastZoomOff()
{
    return PyThrowBadEs(impObj()->setFastZoomOff());
}

void PyDbViewport::setFastZoomOn2(bool bOn)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setFastZoomOn(bOn));
#endif
}

Adesk::UInt16 PyDbViewport::circleSides() const
{
    return impObj()->circleSides();
}

void PyDbViewport::setCircleSides(Adesk::UInt16 val)
{
    return PyThrowBadEs(impObj()->setCircleSides(val));
}

bool PyDbViewport::isSnapOn() const
{
    return impObj()->isSnapOn();
}

void PyDbViewport::setSnapOn1()
{
    return PyThrowBadEs(impObj()->setSnapOn());
}

void PyDbViewport::setSnapOff()
{
    return PyThrowBadEs(impObj()->setSnapOff());
}

void PyDbViewport::setSnapOn2(bool bOn)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setSnapOn(bOn));
#endif
}

bool PyDbViewport::isSnapIsometric() const
{
    return impObj()->isSnapIsometric();
}

void PyDbViewport::setSnapIsometric1()
{
    return PyThrowBadEs(impObj()->setSnapIsometric());
}

void PyDbViewport::setSnapStandard()
{
    return PyThrowBadEs(impObj()->setSnapStandard());
}

void PyDbViewport::setSnapIsometric2(bool bOn)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setSnapIsometric(bOn));
#endif
}

double PyDbViewport::snapAngle() const
{
    return impObj()->snapAngle();
}

void PyDbViewport::setSnapAngle(double val)
{
    return PyThrowBadEs(impObj()->setSnapAngle(val));
}

AcGePoint2d PyDbViewport::snapBasePoint() const
{
    return impObj()->snapBasePoint();
}

void PyDbViewport::setSnapBasePoint(const AcGePoint2d& val)
{
    return PyThrowBadEs(impObj()->setSnapBasePoint(val));
}

AcGeVector2d PyDbViewport::snapIncrement() const
{
    return impObj()->snapIncrement();
}

void PyDbViewport::setSnapIncrement(const AcGeVector2d& val)
{
    return PyThrowBadEs(impObj()->setSnapIncrement(val));
}

Adesk::UInt16 PyDbViewport::snapIsoPair() const
{
    return impObj()->snapIsoPair();
}

void PyDbViewport::setSnapIsoPair(Adesk::UInt16 val)
{
    return PyThrowBadEs(impObj()->setSnapIsoPair(val));
}

bool PyDbViewport::isGridOn() const
{
    return impObj()->isGridOn();
}

void PyDbViewport::setGridOn1()
{
    return PyThrowBadEs(impObj()->setGridOn());
}

void PyDbViewport::setGridOff()
{
    return PyThrowBadEs(impObj()->setGridOff());
}

void PyDbViewport::setGridOn2(bool val)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setGridOn(val));
#endif
}

bool PyDbViewport::isGridBoundToLimits() const
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return impObj()->isGridBoundToLimits();
#endif
}

void PyDbViewport::setGridBoundToLimits(bool bNewVal)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setGridBoundToLimits(bNewVal));
#endif
}

bool PyDbViewport::isGridAdaptive() const
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return impObj()->isGridAdaptive();
#endif
}

void PyDbViewport::setGridAdaptive(bool bNewVal)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setGridAdaptive(bNewVal));
#endif
}

bool PyDbViewport::isGridSubdivisionRestricted() const
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return impObj()->isGridSubdivisionRestricted();
#endif
}

void PyDbViewport::setGridSubdivisionRestricted(bool bNewVal)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setGridSubdivisionRestricted(bNewVal));
#endif
}

bool PyDbViewport::isGridFollow() const
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return impObj()->isGridFollow();
#endif
}

void PyDbViewport::setGridFollow(bool bNewVal)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setGridFollow(bNewVal));
#endif
}

Adesk::UInt16 PyDbViewport::gridMajor() const
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return impObj()->gridMajor();
#endif
}

void PyDbViewport::setGridMajor(Adesk::UInt16 val)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setGridMajor(val));
#endif
}

AcGeVector2d PyDbViewport::gridIncrement() const
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return impObj()->gridIncrement();
#endif
}

void PyDbViewport::setGridIncrement(const AcGeVector2d& val)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setGridIncrement(val));
#endif
}

bool PyDbViewport::hiddenLinesRemoved() const
{
    return impObj()->hiddenLinesRemoved();
}

void PyDbViewport::showHiddenLines()
{
    return PyThrowBadEs(impObj()->showHiddenLines());
}

void PyDbViewport::removeHiddenLines1()
{
    return PyThrowBadEs(impObj()->removeHiddenLines());
}

void PyDbViewport::removeHiddenLines2(bool val)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->removeHiddenLines(val));
#endif
}

void PyDbViewport::freezeLayersInViewport(const boost::python::list& pyids)
{
    AcDbObjectIdArray ids = PyListToObjectIdArray(pyids);
    return PyThrowBadEs(impObj()->freezeLayersInViewport(ids));
}

void PyDbViewport::thawLayersInViewport(const boost::python::list& pyids)
{
    AcDbObjectIdArray ids = PyListToObjectIdArray(pyids);
    return PyThrowBadEs(impObj()->thawLayersInViewport(ids));
}

void PyDbViewport::thawAllLayersInViewport()
{
    return PyThrowBadEs(impObj()->thawAllLayersInViewport());
}

bool PyDbViewport::isLayerFrozenInViewport(const PyDbObjectId& layerId) const
{
    return impObj()->isLayerFrozenInViewport(layerId.m_id);
}

boost::python::list PyDbViewport::getFrozenLayerList() const
{
    AcDbObjectIdArray ids;
    PyThrowBadEs(impObj()->getFrozenLayerList(ids));
    return ObjectIdArrayToPyList(ids);
}

void PyDbViewport::updateDisplay() const
{
    return PyThrowBadEs(impObj()->updateDisplay());
}

PyDbObjectId PyDbViewport::background() const
{
    return PyDbObjectId(impObj()->background());
}

void PyDbViewport::setBackground(PyDbObjectId& backgroundId)
{
    return PyThrowBadEs(impObj()->setBackground(backgroundId.m_id));
}

PyDbObjectId PyDbViewport::previousBackground1() const
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return PyDbObjectId(impObj()->previousBackground());
#endif
}

PyDbObjectId PyDbViewport::previousBackground2(AcGiDrawable::DrawableType type) const
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return PyDbObjectId(impObj()->previousBackground(type));
#endif
}

void PyDbViewport::setPreviousBackground1(PyDbObjectId& backgroundId)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setPreviousBackground(backgroundId.m_id));
#endif
}

void PyDbViewport::setPreviousBackground2(PyDbObjectId& backgroundId, AcGiDrawable::DrawableType type)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setPreviousBackground(backgroundId.m_id, type));
#endif
}

void PyDbViewport::setPreviousBackground3(PyDbObjectId& backgroundId, AcGiDrawable::DrawableType type, bool force)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setPreviousBackground(backgroundId.m_id, type, force));
#endif
}

bool PyDbViewport::previousBackgroundForcedSwitch(void) const
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return impObj()->previousBackgroundForcedSwitch();
#endif
}

PyDbObjectId PyDbViewport::visualStyle() const
{
    return PyDbObjectId(impObj()->visualStyle());
}

void PyDbViewport::setVisualStyle(const PyDbObjectId& oidVisualStyle)
{
    return PyThrowBadEs(impObj()->setVisualStyle(oidVisualStyle.m_id));
}

bool PyDbViewport::isDefaultLightingOn() const
{
    return impObj()->isDefaultLightingOn();
}

void PyDbViewport::setDefaultLightingOn(bool on)
{
    return PyThrowBadEs(impObj()->setDefaultLightingOn(on));
}

AcGiViewportTraits::DefaultLightingType PyDbViewport::defaultLightingType() const
{
    return impObj()->defaultLightingType();
}

void PyDbViewport::setDefaultLightingType(AcGiViewportTraits::DefaultLightingType typ)
{
    return PyThrowBadEs(impObj()->setDefaultLightingType(typ));
}

double PyDbViewport::brightness() const
{
    return impObj()->brightness();
}

void PyDbViewport::setBrightness(double val)
{
    return PyThrowBadEs(impObj()->setBrightness(val));
}

double PyDbViewport::contrast() const
{
    return impObj()->contrast();
}

void PyDbViewport::setContrast(double val)
{
    return PyThrowBadEs(impObj()->setContrast(val));
}

AcCmColor PyDbViewport::ambientLightColor() const
{
    return impObj()->ambientLightColor();
}

void PyDbViewport::setAmbientLightColor(const AcCmColor& clr)
{
    return PyThrowBadEs(impObj()->setAmbientLightColor(clr));
}

PyDbObjectId PyDbViewport::sunId() const
{
    return PyDbObjectId(impObj()->sunId());
}

void PyDbViewport::setSun1(PyDbObjectId& retId, PyDbObject& pSun)
{
    return PyThrowBadEs(impObj()->setSun(retId.m_id, pSun.impObj()));
}

void PyDbViewport::setSun2(PyDbObjectId& retId, PyDbObject& pSun, bool eraseOldSun)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setSun(retId.m_id, pSun.impObj(), eraseOldSun));
#endif
}

bool PyDbViewport::isLocked() const
{
    return impObj()->isLocked();
}

void PyDbViewport::setLocked1()
{
    return PyThrowBadEs(impObj()->setLocked());
}

void PyDbViewport::setUnlocked()
{
    return PyThrowBadEs(impObj()->setUnlocked());
}

void PyDbViewport::setLocked2(bool val)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setLocked(val));
#endif
}

PyDbAnnotationScale PyDbViewport::annotationScale() const
{
    return PyDbAnnotationScale(impObj()->annotationScale());
}

void PyDbViewport::setAnnotationScale(const PyDbAnnotationScale& pScaleObj)
{
    return PyThrowBadEs(impObj()->setAnnotationScale(pScaleObj.impObj()));
}

bool PyDbViewport::isTransparent() const
{
    return impObj()->isTransparent();
}

void PyDbViewport::setTransparent1()
{
    return PyThrowBadEs(impObj()->setTransparent());
}

void PyDbViewport::setOpaque()
{
    return PyThrowBadEs(impObj()->setOpaque());
}

void PyDbViewport::setTransparent2(bool val)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setTransparent(val));
#endif
}

double PyDbViewport::customScale() const
{
    return impObj()->customScale();
}

void PyDbViewport::setCustomScale(double val)
{
    return PyThrowBadEs(impObj()->setCustomScale(val));
}

AcDbViewport::StandardScaleType PyDbViewport::standardScale() const
{
    return impObj()->standardScale();
}

void PyDbViewport::setStandardScale(const AcDbViewport::StandardScaleType val)
{
    return PyThrowBadEs(impObj()->setStandardScale(val));
}

std::string PyDbViewport::plotStyleSheet() const
{
    const ACHAR* val = nullptr;
    PyThrowBadEs(impObj()->plotStyleSheet(val));
    return wstr_to_utf8(val);
}

std::string PyDbViewport::effectivePlotStyleSheet()
{
    const ACHAR* val = nullptr;
    PyThrowBadEs(impObj()->effectivePlotStyleSheet(val));
    return wstr_to_utf8(val);
}

void PyDbViewport::setPlotStyleSheet(const std::string& val)
{
    return PyThrowBadEs(impObj()->setPlotStyleSheet(utf8_to_wstr(val).c_str()));
}

bool PyDbViewport::isNonRectClipOn() const
{
    return impObj()->isNonRectClipOn();
}

void PyDbViewport::setNonRectClipOn1()
{
    return PyThrowBadEs(impObj()->setNonRectClipOn());
}

void PyDbViewport::setNonRectClipOff()
{
    return PyThrowBadEs(impObj()->setNonRectClipOff());
}

void PyDbViewport::setNonRectClipOn2(bool bOn)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setNonRectClipOn(bOn));
#endif
}

PyDbObjectId PyDbViewport::nonRectClipEntityId() const
{
    return PyDbObjectId(impObj()->nonRectClipEntityId());
}

void PyDbViewport::setNonRectClipEntityId(const PyDbObjectId& val)
{
    return PyThrowBadEs(impObj()->setNonRectClipEntityId(val.m_id));
}

void PyDbViewport::erased(const PyDbObject& id, Adesk::Boolean val)
{
    return impObj()->erased(id.impObj(), val);
}

void PyDbViewport::modified(const PyDbObject& obj)
{
    return impObj()->modified(obj.impObj());
}

void PyDbViewport::copied(const PyDbObject& pDbObj, const PyDbObject& pNewObj)
{
    return impObj()->copied(pDbObj.impObj(), pNewObj.impObj());
}

void PyDbViewport::subObjModified(const PyDbObject& pDbObj, const PyDbObject& pSubObj)
{
    return impObj()->subObjModified(pDbObj.impObj(), pSubObj.impObj());
}

boost::python::tuple PyDbViewport::getUcs() const
{
    PyAutoLockGIL lock;
    AcGePoint3d origin;
    AcGeVector3d xAxis;
    AcGeVector3d yAxis;
    PyThrowBadEs(impObj()->getUcs(origin, xAxis, yAxis));
    return boost::python::make_tuple(origin, xAxis, yAxis);
}

boost::python::tuple PyDbViewport::isUcsOrthographic() const
{
    PyAutoLockGIL lock;
    AcDb::OrthographicView view = AcDb::OrthographicView::kNonOrthoView;
    bool flag = impObj()->isUcsOrthographic(view);
    return boost::python::make_tuple(flag, view);
}

PyDbObjectId PyDbViewport::ucsName() const
{
    return PyDbObjectId(impObj()->ucsName());
}

double PyDbViewport::elevation() const
{
    return impObj()->elevation();
}

void PyDbViewport::setUcs1(const AcGePoint3d& origin, const AcGeVector3d& xAxis, const AcGeVector3d& yAxis)
{
    return PyThrowBadEs(impObj()->setUcs(origin, xAxis, yAxis));
}

void PyDbViewport::setUcs2(AcDb::OrthographicView view)
{
    return PyThrowBadEs(impObj()->setUcs(view));
}

void PyDbViewport::setUcs3(const PyDbObjectId& ucsId)
{
    return PyThrowBadEs(impObj()->setUcs(ucsId.m_id));
}

void PyDbViewport::setUcsToWorld()
{
    return PyThrowBadEs(impObj()->setUcsToWorld());
}

void PyDbViewport::setElevation(double elev)
{
    return PyThrowBadEs(impObj()->setElevation(elev));
}

boost::python::tuple PyDbViewport::isViewOrthographic() const
{
    PyAutoLockGIL lock;
    AcDb::OrthographicView view = AcDb::OrthographicView::kNonOrthoView;
    bool flag = impObj()->isViewOrthographic(view);
    return boost::python::make_tuple(flag, view);
}

std::string PyDbViewport::className()
{
    return "AcDbViewport";
}

PyRxClass PyDbViewport::desc()
{
    return PyRxClass(AcDbViewport::desc(), false);
}

PyDbViewport PyDbViewport::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(AcDbViewport::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbViewport(static_cast<AcDbViewport*>(src.impObj()->clone()), true);
}

PyDbViewport PyDbViewport::cast(const PyRxObject& src)
{
    PyDbViewport dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

AcDbViewport* PyDbViewport::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<AcDbViewport*>(m_pyImp.get());
}
