#include "stdafx.h"
#include "PyDbViewport.h"
#include "PyDbObjectId.h"
#include "PyDbObjectContext.h"

using namespace boost::python;

void makePyDbViewportWrapper()
{
    class_<PyDbViewport, bases<PyDbEntity>>("Viewport")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("annotationScale", &PyDbViewport::annotationScale)
        .def("setAnnotationScale", &PyDbViewport::setAnnotationScale)
        .def("setModelView", &PyDbViewport::setModelView)
        .def("getModelView", &PyDbViewport::getModelView)
        .def("removeModelView", &PyDbViewport::removeModelView)
        .def("setSheetView", &PyDbViewport::setSheetView)
        .def("getSheetView", &PyDbViewport::getSheetView)
        .def("removeSheetView", &PyDbViewport::removeSheetView)
        .def("setLabelBlock", &PyDbViewport::setLabelBlock)
        .def("getLabelBlock", &PyDbViewport::getLabelBlock)
        .def("removeLabelBlock", &PyDbViewport::removeLabelBlock)
        .def("syncModelView", &PyDbViewport::syncModelView)
        .def("height", &PyDbViewport::height)
        .def("setHeight", &PyDbViewport::setHeight)
        .def("width", &PyDbViewport::width)
        .def("setWidth", &PyDbViewport::setWidth)
        .def("centerPoint", &PyDbViewport::centerPoint)
        .def("setCenterPoint", &PyDbViewport::setCenterPoint)
        .def("number", &PyDbViewport::number)
        .def("isOn", &PyDbViewport::isOn)
        .def("setOn", &PyDbViewport::setOn)
        .def("setOff", &PyDbViewport::setOff)
        .def("setOff", &PyDbViewport::setOff)
        .def("setIsOn", &PyDbViewport::setIsOn)
        .def("viewTarget", &PyDbViewport::viewTarget)
        .def("setViewTarget", &PyDbViewport::setViewTarget)
        .def("viewDirection", &PyDbViewport::viewDirection)
        .def("setViewDirection1", &PyDbViewport::setViewDirection1)
        .def("viewHeight", &PyDbViewport::viewHeight)
        .def("setViewHeight", &PyDbViewport::setViewHeight)
        .def("viewCenter", &PyDbViewport::viewCenter)
        .def("setViewCenter", &PyDbViewport::setViewCenter)
        .def("twistAngle", &PyDbViewport::twistAngle)
        .def("setTwistAngle", &PyDbViewport::setTwistAngle)
        .def("lensLength", &PyDbViewport::lensLength)
        .def("setLensLength", &PyDbViewport::setLensLength)
        .def("isFrontClipOn", &PyDbViewport::isFrontClipOn)
        .def("setFrontClipOn", &PyDbViewport::setFrontClipOn1)
        .def("setFrontClipOff", &PyDbViewport::setFrontClipOff)
        .def("setFrontClipOn", &PyDbViewport::setFrontClipOn2)
        .def("isBackClipOn", &PyDbViewport::isBackClipOn)
        .def("setBackClipOn", &PyDbViewport::setBackClipOn1)
        .def("setBackClipOff", &PyDbViewport::setBackClipOff)
        .def("setBackClipOn", &PyDbViewport::setBackClipOn2)
        .def("isFrontClipAtEyeOn", &PyDbViewport::isFrontClipAtEyeOn)
        .def("setFrontClipAtEyeOn", &PyDbViewport::setFrontClipAtEyeOn1)
        .def("setFrontClipAtEyeOff", &PyDbViewport::setFrontClipAtEyeOff)
        .def("setFrontClipAtEyeOn", &PyDbViewport::setFrontClipAtEyeOn2)
        .def("frontClipDistance", &PyDbViewport::frontClipDistance)
        .def("setFrontClipDistance", &PyDbViewport::setFrontClipDistance)
        .def("backClipDistance", &PyDbViewport::backClipDistance)
        .def("setBackClipDistance", &PyDbViewport::setBackClipDistance)
        .def("isPerspectiveOn", &PyDbViewport::isPerspectiveOn)
        .def("setPerspectiveOn", &PyDbViewport::setPerspectiveOn1)
        .def("setPerspectiveOff", &PyDbViewport::setPerspectiveOff)
        .def("setPerspectiveOn", &PyDbViewport::setPerspectiveOn2)
        .def("isUcsFollowModeOn", &PyDbViewport::isUcsFollowModeOn)
        .def("setUcsFollowModeOn", &PyDbViewport::setUcsFollowModeOn1)
        .def("setUcsFollowModeOff", &PyDbViewport::setUcsFollowModeOff)
        .def("setUcsFollowModeOn", &PyDbViewport::setUcsFollowModeOn2)
        .def("isUcsIconVisible", &PyDbViewport::isUcsIconVisible)
        .def("setUcsIconVisible", &PyDbViewport::setUcsIconVisible1)
        .def("setUcsIconInvisible", &PyDbViewport::setUcsIconInvisible)
        .def("setUcsIconVisible", &PyDbViewport::setUcsIconVisible2)
        .def("isUcsIconAtOrigin", &PyDbViewport::isUcsIconAtOrigin)
        .def("setUcsIconAtOrigin", &PyDbViewport::setUcsIconAtOrigin1)
        .def("setUcsIconAtCorner", &PyDbViewport::setUcsIconAtCorner)
        .def("setUcsIconAtOrigin", &PyDbViewport::setUcsIconAtOrigin2)
        .def("isFastZoomOn", &PyDbViewport::isFastZoomOn)
        .def("setFastZoomOn", &PyDbViewport::setFastZoomOn1)
        .def("setFastZoomOff", &PyDbViewport::setFastZoomOff)
        .def("setFastZoomOn", &PyDbViewport::setFastZoomOn2)
        .def("circleSides", &PyDbViewport::circleSides)
        .def("setCircleSides", &PyDbViewport::setCircleSides)
        .def("isSnapOn", &PyDbViewport::isSnapOn)
        .def("setSnapOn", &PyDbViewport::setSnapOn1)
        .def("setSnapOff", &PyDbViewport::setSnapOff)
        .def("setSnapOn", &PyDbViewport::setSnapOn2)
        .def("isSnapIsometric", &PyDbViewport::isSnapIsometric)
        .def("setSnapIsometric", &PyDbViewport::setSnapIsometric1)
        .def("setSnapStandard", &PyDbViewport::setSnapStandard)
        .def("setSnapIsometric", &PyDbViewport::setSnapIsometric2)
        .def("snapAngle", &PyDbViewport::snapAngle)
        .def("setSnapAngle", &PyDbViewport::setSnapAngle)
        .def("snapBasePoint", &PyDbViewport::snapBasePoint)
        .def("setSnapBasePoint", &PyDbViewport::setSnapBasePoint)
        .def("snapIncrement", &PyDbViewport::snapIncrement)
        .def("setSnapIncrement", &PyDbViewport::setSnapIncrement)
        .def("snapIsoPair", &PyDbViewport::snapIsoPair)
        .def("setSnapIsoPair", &PyDbViewport::setSnapIsoPair)
        .def("isGridOn", &PyDbViewport::isGridOn)
        .def("setGridOn", &PyDbViewport::setGridOn1)
        .def("setGridOff", &PyDbViewport::setGridOff)
        .def("setGridOn", &PyDbViewport::setGridOn2)
        .def("isGridBoundToLimits", &PyDbViewport::isGridBoundToLimits)
        .def("setGridBoundToLimits", &PyDbViewport::setGridBoundToLimits)
        .def("isGridAdaptive", &PyDbViewport::isGridAdaptive)
        .def("setGridAdaptive", &PyDbViewport::setGridAdaptive)
        .def("isGridSubdivisionRestricted", &PyDbViewport::isGridSubdivisionRestricted)
        .def("setGridSubdivisionRestricted", &PyDbViewport::setGridSubdivisionRestricted)
        .def("isGridFollow", &PyDbViewport::isGridFollow)
        .def("setGridFollow", &PyDbViewport::setGridFollow)
        .def("gridMajor", &PyDbViewport::gridMajor)
        .def("setGridMajor", &PyDbViewport::setGridMajor)
        .def("gridIncrement", &PyDbViewport::gridIncrement)
        .def("setGridIncrement", &PyDbViewport::setGridIncrement)
        .def("hiddenLinesRemoved", &PyDbViewport::hiddenLinesRemoved)
        .def("showHiddenLines", &PyDbViewport::showHiddenLines)
        .def("removeHiddenLines", &PyDbViewport::removeHiddenLines1)
        .def("removeHiddenLines", &PyDbViewport::removeHiddenLines2)
        .def("freezeLayersInViewport", &PyDbViewport::freezeLayersInViewport)
        .def("thawLayersInViewport", &PyDbViewport::thawLayersInViewport)
        .def("thawAllLayersInViewport", &PyDbViewport::thawAllLayersInViewport)
        .def("isLayerFrozenInViewport", &PyDbViewport::isLayerFrozenInViewport)
        .def("getFrozenLayerList", &PyDbViewport::getFrozenLayerList)
        .def("updateDisplay", &PyDbViewport::updateDisplay)
        .def("background", &PyDbViewport::background)
        .def("setBackground", &PyDbViewport::setBackground)
        .def("previousBackground", &PyDbViewport::previousBackground1)
        .def("previousBackground", &PyDbViewport::previousBackground2)
        .def("setPreviousBackground", &PyDbViewport::setPreviousBackground1)
        .def("setPreviousBackground", &PyDbViewport::setPreviousBackground2)
        .def("setPreviousBackground", &PyDbViewport::setPreviousBackground3)
        .def("previousBackgroundForcedSwitch", &PyDbViewport::previousBackgroundForcedSwitch)
        .def("visualStyle", &PyDbViewport::visualStyle)
        .def("setVisualStyle", &PyDbViewport::setVisualStyle)
        .def("isDefaultLightingOn", &PyDbViewport::isDefaultLightingOn)
        .def("setDefaultLightingOn", &PyDbViewport::setDefaultLightingOn)
        .def("defaultLightingType", &PyDbViewport::defaultLightingType)
        .def("setDefaultLightingType", &PyDbViewport::setDefaultLightingType)
        .def("brightness", &PyDbViewport::brightness)
        .def("setBrightness", &PyDbViewport::setBrightness)
        .def("contrast", &PyDbViewport::contrast)
        .def("setContrast", &PyDbViewport::setContrast)
        .def("ambientLightColor", &PyDbViewport::ambientLightColor)
        .def("setAmbientLightColor", &PyDbViewport::setAmbientLightColor)
        .def("sunId", &PyDbViewport::sunId)
        .def("setSun", &PyDbViewport::setSun1)
        .def("setSun", &PyDbViewport::setSun2)
        .def("isLocked", &PyDbViewport::isLocked)
        .def("setLocked", &PyDbViewport::setLocked1)
        .def("setUnlocked", &PyDbViewport::setUnlocked)
        .def("setLocked", &PyDbViewport::setLocked2)
        .def("isTransparent", &PyDbViewport::isTransparent)
        .def("setTransparent", &PyDbViewport::setTransparent1)
        .def("setOpaque", &PyDbViewport::setOpaque)
        .def("setTransparent", &PyDbViewport::setTransparent2)
        .def("customScale", &PyDbViewport::customScale)
        .def("setCustomScale", &PyDbViewport::setCustomScale)
        .def("standardScale", &PyDbViewport::standardScale)
        .def("setStandardScale", &PyDbViewport::setStandardScale)
        .def("plotStyleSheet", &PyDbViewport::plotStyleSheet)
        .def("effectivePlotStyleSheet", &PyDbViewport::effectivePlotStyleSheet)
        .def("setPlotStyleSheet", &PyDbViewport::setPlotStyleSheet)
        .def("isNonRectClipOn", &PyDbViewport::isNonRectClipOn)
        .def("setNonRectClipOn", &PyDbViewport::setNonRectClipOn1)
        .def("setNonRectClipOff", &PyDbViewport::setNonRectClipOff)
        .def("setNonRectClipOn", &PyDbViewport::setNonRectClipOn2)
        .def("nonRectClipEntityId", &PyDbViewport::nonRectClipEntityId)
        .def("setNonRectClipEntityId", &PyDbViewport::setNonRectClipEntityId)
        .def("erased", &PyDbViewport::erased)
        .def("modified", &PyDbViewport::modified)
        .def("copied", &PyDbViewport::copied)
        .def("subObjModified", &PyDbViewport::subObjModified)
        .def("getUcs", &PyDbViewport::getUcs)
        .def("isUcsOrthographic", &PyDbViewport::isUcsOrthographic)
        .def("ucsName", &PyDbViewport::ucsName)
        .def("elevation", &PyDbViewport::elevation)
        .def("setUcs", &PyDbViewport::setUcs1)
        .def("setUcs", &PyDbViewport::setUcs2)
        .def("setUcs", &PyDbViewport::setUcs3)
        .def("setUcsToWorld", &PyDbViewport::setUcsToWorld)
        .def("setElevation", &PyDbViewport::setElevation)
        .def("isViewOrthographic", &PyDbViewport::isViewOrthographic)
        .def("setViewDirection", &PyDbViewport::setViewDirection2)
        .def("isUcsSavedWithViewport", &PyDbViewport::isUcsSavedWithViewport)
        .def("setUcsPerViewport", &PyDbViewport::setUcsPerViewport)
        .def("shadePlot", &PyDbViewport::shadePlot)
        .def("setShadePlot", &PyDbViewport::setShadePlot1)
        .def("shadePlotId", &PyDbViewport::shadePlotId)
        .def("setShadePlot", &PyDbViewport::setShadePlot2)
        .def("plotWireframe", &PyDbViewport::plotWireframe)
        .def("plotAsRaster", &PyDbViewport::plotAsRaster)
        .def("className", &PyDbViewport::className).staticmethod("className")
        .def("desc", &PyDbViewport::desc).staticmethod("desc")
        .def("cloneFrom", &PyDbViewport::cloneFrom).staticmethod("cloneFrom")
        .def("cast", &PyDbViewport::cast).staticmethod("cast")
        ;

    enum_<AcDbViewport::StandardScaleType>("StandardScaleType")
        .value("kScaleToFit", AcDbViewport::StandardScaleType::kScaleToFit)
        .value("kCustomScale", AcDbViewport::StandardScaleType::kCustomScale)
        .value("k1_1", AcDbViewport::StandardScaleType::k1_1)
        .value("k1_2", AcDbViewport::StandardScaleType::k1_2)
        .value("k1_4", AcDbViewport::StandardScaleType::k1_4)
#if !defined(_BRXTARGET) && (_BRXTARGET <= 23)
        .value("k1_5", AcDbViewport::StandardScaleType::k1_5)
#endif // !BRXAPP
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

PyDbViewport::PyDbViewport(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbEntity(openAcDbObject<AcDbViewport>(id, mode), false)
{
}

PyDbViewport::PyDbViewport(const PyDbObjectId& id)
    : PyDbViewport(id, AcDb::OpenMode::kForRead)
{
}

void PyDbViewport::setModelView(const PyDbXrefObjectId& xrefObjId)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setModelView(xrefObjId.m_imp));
#endif
}

PyDbXrefObjectId PyDbViewport::getModelView() const
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    PyDbXrefObjectId id;
    if (auto es = impObj()->getModelView(id.m_imp); es != eOk)
        throw PyAcadErrorStatus(es);
    return id;
#endif
}

void PyDbViewport::removeModelView(void)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->removeModelView());
#endif
}

void PyDbViewport::setSheetView(PyDbObjectId objId)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setSheetView(objId.m_id));
#endif
}

PyDbObjectId PyDbViewport::getSheetView() const
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    PyDbObjectId id;
    if (auto es = impObj()->getSheetView(id.m_id); es != eOk)
        throw PyAcadErrorStatus(es);
    return id;
#endif
}

void PyDbViewport::removeSheetView(void)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->removeSheetView());
#endif
}

void PyDbViewport::setLabelBlock(PyDbObjectId& objId)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setLabelBlock(objId.m_id));
#endif
}

PyDbObjectId PyDbViewport::getLabelBlock() const
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    PyDbObjectId id;
    if (auto es = impObj()->getLabelBlock(id.m_id); es != eOk)
        throw PyAcadErrorStatus(es);
    return id;
#endif
}

void PyDbViewport::removeLabelBlock(void)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->removeLabelBlock());
#endif
}

void PyDbViewport::syncModelView(void)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
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
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
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
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
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
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return impObj()->plotWireframe();
#endif
}

bool PyDbViewport::plotAsRaster() const
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
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
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
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
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
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
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
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
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
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
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
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
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
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
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
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
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
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
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
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
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
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
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setGridOn(val));
#endif
}

bool PyDbViewport::isGridBoundToLimits() const
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return impObj()->isGridBoundToLimits();
#endif
}

void PyDbViewport::setGridBoundToLimits(bool bNewVal)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setGridBoundToLimits(bNewVal));
#endif
}

bool PyDbViewport::isGridAdaptive() const
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return impObj()->isGridAdaptive();
#endif
}

void PyDbViewport::setGridAdaptive(bool bNewVal)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setGridAdaptive(bNewVal));
#endif
}

bool PyDbViewport::isGridSubdivisionRestricted() const
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return impObj()->isGridSubdivisionRestricted();
#endif
}

void PyDbViewport::setGridSubdivisionRestricted(bool bNewVal)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setGridSubdivisionRestricted(bNewVal));
#endif
}

bool PyDbViewport::isGridFollow() const
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return impObj()->isGridFollow();
#endif
}

void PyDbViewport::setGridFollow(bool bNewVal)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setGridFollow(bNewVal));
#endif
}

Adesk::UInt16 PyDbViewport::gridMajor() const
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return impObj()->gridMajor();
#endif
}

void PyDbViewport::setGridMajor(Adesk::UInt16 val)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setGridMajor(val));
#endif
}

AcGeVector2d PyDbViewport::gridIncrement() const
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return impObj()->gridIncrement();
#endif
}

void PyDbViewport::setGridIncrement(const AcGeVector2d& val)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
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
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->removeHiddenLines(val));
#endif
}

void PyDbViewport::freezeLayersInViewport(const boost::python::list& pyids)
{
    AcDbObjectIdArray ids;
    auto vec = py_list_to_std_vector<PyDbObjectId>(pyids);
    for (auto& id : vec)
        ids.append(id.m_id);
    return PyThrowBadEs(impObj()->freezeLayersInViewport(ids));
}

void PyDbViewport::thawLayersInViewport(const boost::python::list& pyids)
{
    AcDbObjectIdArray ids;
    auto vec = py_list_to_std_vector<PyDbObjectId>(pyids);
    for (auto& id : vec)
        ids.append(id.m_id);
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
    PyAutoLockGIL lock;
    AcDbObjectIdArray ids;
    boost::python::list pyids;
    if (auto es = impObj()->getFrozenLayerList(ids); es != eOk)
        throw PyAcadErrorStatus(es);
    for (auto& id : ids)
        pyids.append(PyDbObjectId(id));
    return pyids;
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
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return PyDbObjectId(impObj()->previousBackground());
#endif
}

PyDbObjectId PyDbViewport::previousBackground2(AcGiDrawable::DrawableType type) const
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return PyDbObjectId(impObj()->previousBackground(type));
#endif
}

void PyDbViewport::setPreviousBackground1(PyDbObjectId& backgroundId)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setPreviousBackground(backgroundId.m_id));
#endif
}

void PyDbViewport::setPreviousBackground2(PyDbObjectId& backgroundId, AcGiDrawable::DrawableType type)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setPreviousBackground(backgroundId.m_id, type));
#endif
}

void PyDbViewport::setPreviousBackground3(PyDbObjectId& backgroundId, AcGiDrawable::DrawableType type, bool force)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setPreviousBackground(backgroundId.m_id, type, force));
#endif
}

bool PyDbViewport::previousBackgroundForcedSwitch(void) const
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
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
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
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
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setLocked(val));
#endif
}

PyDbAnnotationScale PyDbViewport::annotationScale() const
{
#ifdef ZRXAPP
    throw PyNotimplementedByHost();
#else
    return PyDbAnnotationScale(impObj()->annotationScale());
#endif
}

void PyDbViewport::setAnnotationScale(const PyDbAnnotationScale& pScaleObj)
{
#ifdef ZRXAPP
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setAnnotationScale(pScaleObj.impObj()));
#endif
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
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
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
    if (auto es = impObj()->plotStyleSheet(val); es != eOk)
        throw PyAcadErrorStatus(es);
    return wstr_to_utf8(val);
}

std::string PyDbViewport::effectivePlotStyleSheet()
{
    const ACHAR* val = nullptr;
    if (auto es = impObj()->effectivePlotStyleSheet(val); es != eOk)
        throw PyAcadErrorStatus(es);
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
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
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

void PyDbViewport::getUcs(AcGePoint3d& origin, AcGeVector3d& xAxis, AcGeVector3d& yAxis) const
{
    return PyThrowBadEs(impObj()->getUcs(origin, xAxis, yAxis));
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
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    PyAutoLockGIL lock;
    AcDb::OrthographicView view = AcDb::OrthographicView::kNonOrthoView;
    bool flag = impObj()->isViewOrthographic(view);
    return boost::python::make_tuple(flag, view);
#endif
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
    if (m_pyImp == nullptr) [[unlikely]]
        throw PyNullObject(src);
    return static_cast<AcDbViewport*>(m_pyImp.get());
}
