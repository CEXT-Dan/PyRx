#include "stdafx.h"
#include "PyDbViewport.h"
#include "PyDbObjectId.h"
#include "PyDbObjectContext.h"

using namespace boost::python;

void makePyDbViewportWrapper()
{
    constexpr const std::string_view ctords = "Overloads:\n"
        "- None: Any\n"
        "- id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode, erased: bool\n";

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
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.CTOR(ctords, 9953)))
        .def("annotationScale", &PyDbViewport::annotationScale, DS.ARGS(10021))
        .def("setAnnotationScale", &PyDbViewport::setAnnotationScale, DS.ARGS({ "val: PyDb.AnnotationScale" }, 10084))
        .def("setModelView", &PyDbViewport::setModelView, DS.ARGS({ "val: PyDb.XrefObjectId" }, 10117))
        .def("getModelView", &PyDbViewport::getModelView, DS.ARGS(10038))
        .def("removeModelView", &PyDbViewport::removeModelView, DS.ARGS(10081))
        .def("setSheetView", &PyDbViewport::setSheetView, DS.ARGS({ "val : PyDb.ObjectId" }, 10130))
        .def("getSheetView", &PyDbViewport::getSheetView, DS.ARGS(10040))
        .def("removeSheetView", &PyDbViewport::removeSheetView, DS.ARGS(10082))
        .def("setLabelBlock", &PyDbViewport::setLabelBlock, DS.ARGS({ "val : PyDb.ObjectId" }, 10114))
        .def("getLabelBlock", &PyDbViewport::getLabelBlock, DS.ARGS(10037))
        .def("removeLabelBlock", &PyDbViewport::removeLabelBlock, DS.ARGS(10080))
        .def("syncModelView", &PyDbViewport::syncModelView, DS.ARGS(10174))
        .def("height", &PyDbViewport::height, DS.ARGS(10045))
        .def("setHeight", &PyDbViewport::setHeight, DS.ARGS({ "val : float" }, 10112))
        .def("width", &PyDbViewport::width, DS.ARGS(10186))
        .def("setWidth", &PyDbViewport::setWidth, DS.ARGS({ "val : float" }, 10160))
        .def("centerPoint", &PyDbViewport::centerPoint, DS.ARGS(10025))
        .def("setCenterPoint", &PyDbViewport::setCenterPoint, DS.ARGS({ "val : PyGe.Point3d" }, 10090))
        .def("number", &PyDbViewport::number, DS.ARGS(10073))
        .def("isOn", &PyDbViewport::isOn, DS.ARGS(10060))
        .def("setOn", &PyDbViewport::setOn, DS.ARGS(10122))
        .def("setOff", &PyDbViewport::setOff, DS.ARGS(10121))
        .def("setIsOn", &PyDbViewport::setIsOn, DS.ARGS({ "val : bool" }, 10113))
        .def("viewTarget", &PyDbViewport::viewTarget, DS.ARGS(10184))
        .def("setViewTarget", &PyDbViewport::setViewTarget, DS.ARGS({ "val : PyGe.Point3d" }, 10158))
        .def("viewDirection", &PyDbViewport::viewDirection, DS.ARGS(10182))
        .def("viewHeight", &PyDbViewport::viewHeight, DS.ARGS(10183))
        .def("setViewHeight", &PyDbViewport::setViewHeight, DS.ARGS({ "val : float" }, 10157))
        .def("viewCenter", &PyDbViewport::viewCenter, DS.ARGS(10181))
        .def("setViewCenter", &PyDbViewport::setViewCenter, DS.ARGS({ "val : PyGe.Point2d" }, 10155))
        .def("twistAngle", &PyDbViewport::twistAngle, DS.ARGS(10178))
        .def("setTwistAngle", &PyDbViewport::setTwistAngle, DS.ARGS({ "val : float" }, 10144))
        .def("lensLength", &PyDbViewport::lensLength, DS.ARGS(10071))
        .def("setLensLength", &PyDbViewport::setLensLength, DS.ARGS({ "val : float" }, 10115))
        .def("isFrontClipOn", &PyDbViewport::isFrontClipOn, DS.ARGS(10051))
        .def("setFrontClipOn", &PyDbViewport::setFrontClipOn1)
        .def("setFrontClipOn", &PyDbViewport::setFrontClipOn2, DS.ARGS({ "val: bool=True" }, 10103))
        .def("setFrontClipOff", &PyDbViewport::setFrontClipOff, DS.ARGS(10102))
        .def("isBackClipOn", &PyDbViewport::isBackClipOn, DS.ARGS(10047))
        .def("setBackClipOff", &PyDbViewport::setBackClipOff, DS.ARGS(10086))
        .def("setBackClipOn", &PyDbViewport::setBackClipOn1)
        .def("setBackClipOn", &PyDbViewport::setBackClipOn2, DS.ARGS({ "val: bool=True" }, 10087))
        .def("isFrontClipAtEyeOn", &PyDbViewport::isFrontClipAtEyeOn, DS.ARGS(10050))
        .def("setFrontClipAtEyeOff", &PyDbViewport::setFrontClipAtEyeOff, DS.ARGS(10099))
        .def("setFrontClipAtEyeOn", &PyDbViewport::setFrontClipAtEyeOn1)
        .def("setFrontClipAtEyeOn", &PyDbViewport::setFrontClipAtEyeOn2, DS.ARGS({ "val: bool=True" }, 10100))
        .def("frontClipDistance", &PyDbViewport::frontClipDistance, DS.ARGS(10035))
        .def("setFrontClipDistance", &PyDbViewport::setFrontClipDistance, DS.ARGS({ "val: float" }, 10101))
        .def("backClipDistance", &PyDbViewport::backClipDistance, DS.ARGS(10022))
        .def("setBackClipDistance", &PyDbViewport::setBackClipDistance, DS.ARGS({ "val: float" }, 10085))
        .def("isPerspectiveOn", &PyDbViewport::isPerspectiveOn, DS.ARGS(10061))
        .def("setPerspectiveOn", &PyDbViewport::setPerspectiveOn1)
        .def("setPerspectiveOn", &PyDbViewport::setPerspectiveOn2, DS.ARGS({ "val: bool=True" }, 10125))
        .def("setPerspectiveOff", &PyDbViewport::setPerspectiveOff, DS.ARGS(10124))
        .def("isUcsFollowModeOn", &PyDbViewport::isUcsFollowModeOn, DS.ARGS(10065))
        .def("setUcsFollowModeOn", &PyDbViewport::setUcsFollowModeOn1)
        .def("setUcsFollowModeOn", &PyDbViewport::setUcsFollowModeOn2, DS.ARGS({ "val: bool=True" }, 10147))
        .def("setUcsFollowModeOff", &PyDbViewport::setUcsFollowModeOff, DS.ARGS(10146))
        .def("isUcsIconVisible", &PyDbViewport::isUcsIconVisible, DS.ARGS(10067))
        .def("setUcsIconInvisible", &PyDbViewport::setUcsIconInvisible, DS.ARGS(10150))
        .def("setUcsIconVisible", &PyDbViewport::setUcsIconVisible1)
        .def("setUcsIconVisible", &PyDbViewport::setUcsIconVisible2, DS.ARGS({ "val: bool=True" }, 10151))
        .def("isUcsIconAtOrigin", &PyDbViewport::isUcsIconAtOrigin, DS.ARGS(10066))
        .def("setUcsIconAtCorner", &PyDbViewport::setUcsIconAtCorner, DS.ARGS(10148))
        .def("setUcsIconAtOrigin", &PyDbViewport::setUcsIconAtOrigin1)
        .def("setUcsIconAtOrigin", &PyDbViewport::setUcsIconAtOrigin2, DS.ARGS({ "val: bool=True" }, 10149))
        .def("isFastZoomOn", &PyDbViewport::isFastZoomOn, DS.ARGS(10049))
        .def("setFastZoomOff", &PyDbViewport::setFastZoomOff, DS.ARGS(10097))
        .def("setFastZoomOn", &PyDbViewport::setFastZoomOn1)
        .def("setFastZoomOn", &PyDbViewport::setFastZoomOn2, DS.ARGS({ "val: bool=True" }, 10098))
        .def("circleSides", &PyDbViewport::circleSides, DS.ARGS(10026))
        .def("setCircleSides", &PyDbViewport::setCircleSides, DS.ARGS({ "val : int" }, 10091))
        .def("isSnapOn", &PyDbViewport::isSnapOn, DS.ARGS(10063))
        .def("setSnapOff", &PyDbViewport::setSnapOff, DS.ARGS(10136))
        .def("setSnapOn", &PyDbViewport::setSnapOn1)
        .def("setSnapOn", &PyDbViewport::setSnapOn2, DS.ARGS({ "val: bool=True" }, 10137))
        .def("isSnapIsometric", &PyDbViewport::isSnapIsometric, DS.ARGS(10062))
        .def("setSnapStandard", &PyDbViewport::setSnapStandard, DS.ARGS(10138))
        .def("setSnapIsometric", &PyDbViewport::setSnapIsometric1)
        .def("setSnapIsometric", &PyDbViewport::setSnapIsometric2, DS.ARGS({ "val: bool=True" }, 10134))
        .def("snapAngle", &PyDbViewport::snapAngle, DS.ARGS(10165))
        .def("setSnapAngle", &PyDbViewport::setSnapAngle, DS.ARGS({ "val : float" }, 10131))
        .def("snapBasePoint", &PyDbViewport::snapBasePoint, DS.ARGS(10166))
        .def("setSnapBasePoint", &PyDbViewport::setSnapBasePoint, DS.ARGS({ "val : PyGe.Point2d" }, 10132))
        .def("snapIncrement", &PyDbViewport::snapIncrement, DS.ARGS(10167))
        .def("setSnapIncrement", &PyDbViewport::setSnapIncrement, DS.ARGS({ "val : PyGe.Vector2d" }, 10133))
        .def("snapIsoPair", &PyDbViewport::snapIsoPair, DS.ARGS(10168))
        .def("setSnapIsoPair", &PyDbViewport::setSnapIsoPair, DS.ARGS({ "val : int" }, 10135))
        .def("isGridOn", &PyDbViewport::isGridOn, DS.ARGS(10055))
        .def("setGridOff", &PyDbViewport::setGridOff, DS.ARGS(10109))
        .def("setGridOn", &PyDbViewport::setGridOn1)
        .def("setGridOn", &PyDbViewport::setGridOn2, DS.ARGS({ "val: bool=True" }, 10110))
        .def("isGridBoundToLimits", &PyDbViewport::isGridBoundToLimits, DS.ARGS(10053))
        .def("setGridBoundToLimits", &PyDbViewport::setGridBoundToLimits, DS.ARGS({ "val : bool" }, 10105))
        .def("isGridAdaptive", &PyDbViewport::isGridAdaptive, DS.ARGS(10052))
        .def("setGridAdaptive", &PyDbViewport::setGridAdaptive, DS.ARGS({ "val : bool" }, 10104))
        .def("isGridSubdivisionRestricted", &PyDbViewport::isGridSubdivisionRestricted, DS.ARGS(10056))
        .def("setGridSubdivisionRestricted", &PyDbViewport::setGridSubdivisionRestricted, DS.ARGS({ "val : bool" }, 10111))
        .def("isGridFollow", &PyDbViewport::isGridFollow, DS.ARGS(10054))
        .def("setGridFollow", &PyDbViewport::setGridFollow, DS.ARGS({ "val : bool" }, 10106))
        .def("gridMajor", &PyDbViewport::gridMajor, DS.ARGS(10044))
        .def("setGridMajor", &PyDbViewport::setGridMajor, DS.ARGS({ "val : int" }, 10108))
        .def("gridIncrement", &PyDbViewport::gridIncrement, DS.ARGS(10043))
        .def("setGridIncrement", &PyDbViewport::setGridIncrement, DS.ARGS({ "val : PyGe.Vector2d" }, 10107))
        .def("hiddenLinesRemoved", &PyDbViewport::hiddenLinesRemoved, DS.ARGS(10046))
        .def("showHiddenLines", &PyDbViewport::showHiddenLines, DS.ARGS(10164))
        .def("removeHiddenLines", &PyDbViewport::removeHiddenLines1)
        .def("removeHiddenLines", &PyDbViewport::removeHiddenLines2, DS.ARGS({ "val: bool=True" }, 10079))
        .def("freezeLayersInViewport", &PyDbViewport::freezeLayersInViewport, DS.ARGS({ "ids : list[PyDb.ObjectId]" }, 10034))
        .def("thawLayersInViewport", &PyDbViewport::thawLayersInViewport, DS.ARGS({ "ids : list[PyDb.ObjectId]" }, 10176))
        .def("thawAllLayersInViewport", &PyDbViewport::thawAllLayersInViewport, DS.ARGS(10175))
        .def("isLayerFrozenInViewport", &PyDbViewport::isLayerFrozenInViewport, DS.ARGS({ "val : PyDb.ObjectId" }, 10057))
        .def("getFrozenLayerList", &PyDbViewport::getFrozenLayerList, DS.ARGS(10036))
        .def("updateDisplay", &PyDbViewport::updateDisplay, DS.ARGS(10180))
        .def("background", &PyDbViewport::background, DS.ARGS(10023))
        .def("setBackground", &PyDbViewport::setBackground, DS.ARGS({ "val : PyDb.ObjectId" }, 10088))
        .def("previousBackground", &PyDbViewport::previousBackground1)
        .def("previousBackground", &PyDbViewport::previousBackground2, DS.ARGS({ "type: PyGi.DrawableType = 'AcGiDrawable::kGeometry'" }, 10077))
        .def("setPreviousBackground", &PyDbViewport::setPreviousBackground1)
        .def("setPreviousBackground", &PyDbViewport::setPreviousBackground2)
        .def("setPreviousBackground", &PyDbViewport::setPreviousBackground3, DS.ARGS({ "id : PyDb.ObjectId","type: PyGi.DrawableType = 'AcGiDrawable::kGeometry'","force: bool=True" }, 10128))
        .def("previousBackgroundForcedSwitch", &PyDbViewport::previousBackgroundForcedSwitch, DS.ARGS(10078))
        .def("visualStyle", &PyDbViewport::visualStyle, DS.ARGS(10185))
        .def("setVisualStyle", &PyDbViewport::setVisualStyle, DS.ARGS({ "val : PyDb.ObjectId" }, 10159))
        .def("isDefaultLightingOn", &PyDbViewport::isDefaultLightingOn, DS.ARGS(10048))
        .def("setDefaultLightingOn", &PyDbViewport::setDefaultLightingOn, DS.ARGS({ "val : bool" }, 10094))
        .def("defaultLightingType", &PyDbViewport::defaultLightingType, DS.ARGS(10030))
        .def("setDefaultLightingType", &PyDbViewport::setDefaultLightingType, DS.ARGS({ "val: PyGi.DefaultLightingType" }, 10095))
        .def("brightness", &PyDbViewport::brightness, DS.ARGS(10024))
        .def("setBrightness", &PyDbViewport::setBrightness, DS.ARGS({ "val : float" }, 10089))
        .def("contrast", &PyDbViewport::contrast, DS.ARGS(10027))
        .def("setContrast", &PyDbViewport::setContrast, DS.ARGS({ "val : float" }, 10092))
        .def("ambientLightColor", &PyDbViewport::ambientLightColor, DS.ARGS(10020))
        .def("setAmbientLightColor", &PyDbViewport::setAmbientLightColor, DS.ARGS({ "clr: PyDb.AcCmColor" }, 10083))
        .def("sunId", &PyDbViewport::sunId, DS.ARGS(10173))
        .def("setSun", &PyDbViewport::setSun1)
        .def("setSun", &PyDbViewport::setSun2, DS.ARGS({ "retid: PyDb.ObjectId","sun: PyDb.Object","erase: bool=True" }, 10140))
        .def("isLocked", &PyDbViewport::isLocked, DS.ARGS(10058))
        .def("setUnlocked", &PyDbViewport::setUnlocked, DS.ARGS(10154))
        .def("setLocked", &PyDbViewport::setLocked1)
        .def("setLocked", &PyDbViewport::setLocked2, DS.ARGS({ "val : bool=True" }, 10116))
        .def("isTransparent", &PyDbViewport::isTransparent, DS.ARGS(10064))
        .def("setOpaque", &PyDbViewport::setOpaque, DS.ARGS(10123))
        .def("setTransparent", &PyDbViewport::setTransparent1)
        .def("setTransparent", &PyDbViewport::setTransparent2, DS.ARGS({ "val : bool=True" }, 10143))
        .def("customScale", &PyDbViewport::customScale, DS.ARGS(10029))
        .def("setCustomScale", &PyDbViewport::setCustomScale, DS.ARGS({ "val: float" }, 10093))
        .def("standardScale", &PyDbViewport::standardScale, DS.ARGS(10169))
        .def("setStandardScale", &PyDbViewport::setStandardScale, DS.ARGS({ "val: PyDb.StandardScaleType" }, 10139))
        .def("plotStyleSheet", &PyDbViewport::plotStyleSheet, DS.ARGS(10075))
        .def("effectivePlotStyleSheet", &PyDbViewport::effectivePlotStyleSheet, DS.ARGS(10031))
        .def("setPlotStyleSheet", &PyDbViewport::setPlotStyleSheet, DS.ARGS({ "val : str" }, 10126))
        .def("isNonRectClipOn", &PyDbViewport::isNonRectClipOn, DS.ARGS(10059))
        .def("setNonRectClipOff", &PyDbViewport::setNonRectClipOff, DS.ARGS(10119))
        .def("setNonRectClipOn", &PyDbViewport::setNonRectClipOn1)
        .def("setNonRectClipOn", &PyDbViewport::setNonRectClipOn2, DS.ARGS({ "val: bool=True" }, 10120))
        .def("nonRectClipEntityId", &PyDbViewport::nonRectClipEntityId, DS.ARGS())
        .def("setNonRectClipEntityId", &PyDbViewport::setNonRectClipEntityId, DS.ARGS({ "id: PyDb.ObjectId" }, 10072))
        .def("erased", &PyDbViewport::erased, DS.ARGS({ "obj: PyDb.Object","val: bool" }, 10033))
        .def("modified", &PyDbViewport::modified, DS.ARGS({ "obj: PyDb.Object" }))
        .def("copied", &PyDbViewport::copied, DS.ARGS({ "obj: PyDb.Object","newObj: PyDb.Object" }, 10028))
        .def("subObjModified", &PyDbViewport::subObjModified, DS.ARGS({ "obj: PyDb.Object","subObj: PyDb.Object" }, 10172))
        .def("getUcs", &PyDbViewport::getUcs, DS.ARGS(10042))
        .def("isUcsOrthographic", &PyDbViewport::isUcsOrthographic, DS.ARGS(10068))
        .def("ucsName", &PyDbViewport::ucsName, DS.ARGS(10179))
        .def("elevation", &PyDbViewport::elevation, DS.ARGS(10032))
        .def("setUcs", &PyDbViewport::setUcs1)
        .def("setUcs", &PyDbViewport::setUcs2)
        .def("setUcs", &PyDbViewport::setUcs3, DS.OVRL(setUcsOverloads, 10145))
        .def("setUcsToWorld", &PyDbViewport::setUcsToWorld, DS.ARGS(10153))
        .def("setElevation", &PyDbViewport::setElevation, DS.ARGS({ "val: float" }, 10096))
        .def("isViewOrthographic", &PyDbViewport::isViewOrthographic, DS.ARGS(10070))
        .def("setViewDirection", &PyDbViewport::setViewDirection1)
        .def("setViewDirection", &PyDbViewport::setViewDirection2, DS.OVRL(setViewDirectionOverloads, 10156))
        .def("isUcsSavedWithViewport", &PyDbViewport::isUcsSavedWithViewport, DS.ARGS(10156))
        .def("setUcsPerViewport", &PyDbViewport::setUcsPerViewport, DS.ARGS({ "val: bool" }, 10152))
        .def("shadePlot", &PyDbViewport::shadePlot, DS.ARGS(10161))
        .def("shadePlotId", &PyDbViewport::shadePlotId, DS.ARGS(10162))
        .def("setShadePlot", &PyDbViewport::setShadePlot1)
        .def("setShadePlot", &PyDbViewport::setShadePlot2, DS.ARGS({ "type: PyDb.VpShadePlotType","id: PyDb.ObjectId = ..." }, 10129))
        .def("plotWireframe", &PyDbViewport::plotWireframe, DS.ARGS(10076))
        .def("plotAsRaster", &PyDbViewport::plotAsRaster, DS.ARGS(10074))
        .def("className", &PyDbViewport::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbViewport::desc, DS.SARGS(15560)).staticmethod("desc")
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

void PyDbViewport::setModelView(const PyDbXrefObjectId& xrefObjId) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setModelView(xrefObjId.m_imp));
#endif
}

PyDbXrefObjectId PyDbViewport::getModelView() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    PyDbXrefObjectId id;
    PyThrowBadEs(impObj()->getModelView(id.m_imp));
    return id;
#endif
}

void PyDbViewport::removeModelView(void) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->removeModelView());
#endif
}

void PyDbViewport::setSheetView(PyDbObjectId objId) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setSheetView(objId.m_id));
#endif
}

PyDbObjectId PyDbViewport::getSheetView() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    PyDbObjectId id;
    PyThrowBadEs(impObj()->getSheetView(id.m_id));
    return id;
#endif
}

void PyDbViewport::removeSheetView(void) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->removeSheetView());
#endif
}

void PyDbViewport::setLabelBlock(PyDbObjectId& objId) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setLabelBlock(objId.m_id));
#endif
}

PyDbObjectId PyDbViewport::getLabelBlock() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    PyDbObjectId id;
    PyThrowBadEs(impObj()->getLabelBlock(id.m_id));
    return id;
#endif
}

void PyDbViewport::removeLabelBlock(void) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->removeLabelBlock());
#endif
}

void PyDbViewport::syncModelView(void) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->syncModelView());
#endif
}

double PyDbViewport::height() const
{
    return impObj()->height();
}

void PyDbViewport::setHeight(double val) const
{
    return PyThrowBadEs(impObj()->setHeight(val));
}

double PyDbViewport::width() const
{
    return impObj()->width();
}

void PyDbViewport::setWidth(double val) const
{
    return PyThrowBadEs(impObj()->setWidth(val));
}

AcGePoint3d PyDbViewport::centerPoint() const
{
    return impObj()->centerPoint();
}

void PyDbViewport::setCenterPoint(const AcGePoint3d& val) const
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

void PyDbViewport::setOn() const
{
    return PyThrowBadEs(impObj()->setOn());
}

void PyDbViewport::setOff() const
{
    return PyThrowBadEs(impObj()->setOff());
}

void PyDbViewport::setIsOn(bool bOn) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setIsOn(bOn));
#endif
}

AcGePoint3d PyDbViewport::viewTarget() const
{
    return impObj()->viewTarget();
}

void PyDbViewport::setViewTarget(const AcGePoint3d& val) const
{
    return PyThrowBadEs(impObj()->setViewTarget(val));
}

AcGeVector3d PyDbViewport::viewDirection() const
{
    return impObj()->viewDirection();
}

void PyDbViewport::setViewDirection1(const AcGeVector3d& val) const
{
    return PyThrowBadEs(impObj()->setViewDirection(val));
}

void PyDbViewport::setViewDirection2(AcDb::OrthographicView view) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setViewDirection(view));
#endif
}

bool PyDbViewport::isUcsSavedWithViewport() const
{
    return impObj()->isUcsSavedWithViewport();
}

void PyDbViewport::setUcsPerViewport(bool ucsvp) const
{
    return impObj()->setUcsPerViewport(ucsvp);
}

AcDbViewport::ShadePlotType PyDbViewport::shadePlot() const
{
    return impObj()->shadePlot();
}

void PyDbViewport::setShadePlot1(const AcDbViewport::ShadePlotType val) const
{
    return PyThrowBadEs(impObj()->setShadePlot(val));
}

void PyDbViewport::setShadePlot2(const AcDbViewport::ShadePlotType type, const PyDbObjectId shadePlotId) const
{
    return PyThrowBadEs(impObj()->setShadePlot(type, shadePlotId.m_id));
}

bool PyDbViewport::plotWireframe() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return impObj()->plotWireframe();
#endif
}

bool PyDbViewport::plotAsRaster() const
{
#if defined(_BRXTARGET250)
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

void PyDbViewport::setViewHeight(double ht) const
{
    return PyThrowBadEs(impObj()->setViewHeight(ht));
}

AcGePoint2d PyDbViewport::viewCenter() const
{
    return impObj()->viewCenter();
}

void PyDbViewport::setViewCenter(const AcGePoint2d& pt) const
{
    return PyThrowBadEs(impObj()->setViewCenter(pt));
}

double PyDbViewport::twistAngle() const
{
    return impObj()->twistAngle();
}

void PyDbViewport::setTwistAngle(double val) const
{
    return PyThrowBadEs(impObj()->setTwistAngle(val));
}

double PyDbViewport::lensLength() const
{
    return impObj()->lensLength();
}

void PyDbViewport::setLensLength(double val) const
{
    return PyThrowBadEs(impObj()->setLensLength(val));
}

bool PyDbViewport::isFrontClipOn() const
{
    return impObj()->isFrontClipOn();
}

void PyDbViewport::setFrontClipOn1() const
{
    return PyThrowBadEs(impObj()->setFrontClipOn());
}

void PyDbViewport::setFrontClipOn2(bool bOn) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setFrontClipOn(bOn));
#endif
}

bool PyDbViewport::isBackClipOn() const
{
    return impObj()->isBackClipOn();
}

void PyDbViewport::setFrontClipOff() const
{
    return PyThrowBadEs(impObj()->setFrontClipOff());
}

void PyDbViewport::setBackClipOn1() const
{
    return PyThrowBadEs(impObj()->setBackClipOn());
}

void PyDbViewport::setBackClipOn2(bool bOn) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setBackClipOn(bOn));
#endif
}

bool PyDbViewport::isFrontClipAtEyeOn() const
{
    return impObj()->isFrontClipAtEyeOn();
}

void PyDbViewport::setFrontClipAtEyeOn1() const
{
    return PyThrowBadEs(impObj()->setFrontClipAtEyeOn());
}

void PyDbViewport::setFrontClipAtEyeOff() const
{
    return PyThrowBadEs(impObj()->setFrontClipAtEyeOff());
}

void PyDbViewport::setFrontClipAtEyeOn2(bool bOn) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setFrontClipAtEyeOn(bOn));
#endif
}

double PyDbViewport::frontClipDistance() const
{
    return impObj()->frontClipDistance();
}

void PyDbViewport::setFrontClipDistance(double newVal) const
{
    return PyThrowBadEs(impObj()->setFrontClipDistance(newVal));
}

double PyDbViewport::backClipDistance() const
{
    return impObj()->backClipDistance();
}

void PyDbViewport::setBackClipDistance(double newVal) const
{
    return PyThrowBadEs(impObj()->setBackClipDistance(newVal));
}

bool PyDbViewport::isPerspectiveOn() const
{
    return impObj()->isPerspectiveOn();
}

void PyDbViewport::setPerspectiveOn1() const
{
    return PyThrowBadEs(impObj()->setPerspectiveOn());
}

void PyDbViewport::setPerspectiveOff() const
{
    return PyThrowBadEs(impObj()->setPerspectiveOff());
}

void PyDbViewport::setPerspectiveOn2(bool bOn) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setPerspectiveOn(bOn));
#endif
}

bool PyDbViewport::isUcsFollowModeOn() const
{
    return impObj()->isUcsFollowModeOn();
}

void PyDbViewport::setUcsFollowModeOn1() const
{
    return PyThrowBadEs(impObj()->setUcsFollowModeOn());
}

void PyDbViewport::setUcsFollowModeOff() const
{
    return PyThrowBadEs(impObj()->setUcsFollowModeOff());
}

void PyDbViewport::setUcsFollowModeOn2(bool bOn) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setUcsFollowModeOn(bOn));
#endif
}

bool PyDbViewport::isUcsIconVisible() const
{
    return impObj()->isUcsIconVisible();
}

void PyDbViewport::setUcsIconVisible1() const
{
    return PyThrowBadEs(impObj()->setUcsIconVisible());
}

void PyDbViewport::setUcsIconInvisible() const
{
    return PyThrowBadEs(impObj()->setUcsIconInvisible());
}

void PyDbViewport::setUcsIconVisible2(bool bOn) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setUcsIconVisible(bOn));
#endif
}

bool PyDbViewport::isUcsIconAtOrigin() const
{
    return impObj()->isUcsIconAtOrigin();
}

void PyDbViewport::setUcsIconAtOrigin1() const
{
    return PyThrowBadEs(impObj()->setUcsIconAtOrigin());
}

void PyDbViewport::setUcsIconAtCorner() const
{
    return PyThrowBadEs(impObj()->setUcsIconAtCorner());
}

void PyDbViewport::setUcsIconAtOrigin2(bool bOn) const
{

#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setUcsIconAtOrigin(bOn));
#endif
}

bool PyDbViewport::isFastZoomOn() const
{
    return impObj()->isFastZoomOn();
}

void PyDbViewport::setBackClipOff() const
{
    return PyThrowBadEs(impObj()->setBackClipOff());
}

void PyDbViewport::setFastZoomOn1() const
{
    return PyThrowBadEs(impObj()->setFastZoomOn());
}

void PyDbViewport::setFastZoomOff() const
{
    return PyThrowBadEs(impObj()->setFastZoomOff());
}

void PyDbViewport::setFastZoomOn2(bool bOn) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setFastZoomOn(bOn));
#endif
}

Adesk::UInt16 PyDbViewport::circleSides() const
{
    return impObj()->circleSides();
}

void PyDbViewport::setCircleSides(Adesk::UInt16 val) const
{
    return PyThrowBadEs(impObj()->setCircleSides(val));
}

bool PyDbViewport::isSnapOn() const
{
    return impObj()->isSnapOn();
}

void PyDbViewport::setSnapOn1() const
{
    return PyThrowBadEs(impObj()->setSnapOn());
}

void PyDbViewport::setSnapOff() const
{
    return PyThrowBadEs(impObj()->setSnapOff());
}

void PyDbViewport::setSnapOn2(bool bOn) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setSnapOn(bOn));
#endif
}

bool PyDbViewport::isSnapIsometric() const
{
    return impObj()->isSnapIsometric();
}

void PyDbViewport::setSnapIsometric1() const
{
    return PyThrowBadEs(impObj()->setSnapIsometric());
}

void PyDbViewport::setSnapStandard() const
{
    return PyThrowBadEs(impObj()->setSnapStandard());
}

void PyDbViewport::setSnapIsometric2(bool bOn) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setSnapIsometric(bOn));
#endif
}

double PyDbViewport::snapAngle() const
{
    return impObj()->snapAngle();
}

void PyDbViewport::setSnapAngle(double val) const
{
    return PyThrowBadEs(impObj()->setSnapAngle(val));
}

AcGePoint2d PyDbViewport::snapBasePoint() const
{
    return impObj()->snapBasePoint();
}

void PyDbViewport::setSnapBasePoint(const AcGePoint2d& val) const
{
    return PyThrowBadEs(impObj()->setSnapBasePoint(val));
}

AcGeVector2d PyDbViewport::snapIncrement() const
{
    return impObj()->snapIncrement();
}

void PyDbViewport::setSnapIncrement(const AcGeVector2d& val) const
{
    return PyThrowBadEs(impObj()->setSnapIncrement(val));
}

Adesk::UInt16 PyDbViewport::snapIsoPair() const
{
    return impObj()->snapIsoPair();
}

void PyDbViewport::setSnapIsoPair(Adesk::UInt16 val) const
{
    return PyThrowBadEs(impObj()->setSnapIsoPair(val));
}

bool PyDbViewport::isGridOn() const
{
    return impObj()->isGridOn();
}

void PyDbViewport::setGridOn1() const
{
    return PyThrowBadEs(impObj()->setGridOn());
}

void PyDbViewport::setGridOff() const
{
    return PyThrowBadEs(impObj()->setGridOff());
}

void PyDbViewport::setGridOn2(bool val) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setGridOn(val));
#endif
}

bool PyDbViewport::isGridBoundToLimits() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return impObj()->isGridBoundToLimits();
#endif
}

void PyDbViewport::setGridBoundToLimits(bool bNewVal) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setGridBoundToLimits(bNewVal));
#endif
}

bool PyDbViewport::isGridAdaptive() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return impObj()->isGridAdaptive();
#endif
}

void PyDbViewport::setGridAdaptive(bool bNewVal) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setGridAdaptive(bNewVal));
#endif
}

bool PyDbViewport::isGridSubdivisionRestricted() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return impObj()->isGridSubdivisionRestricted();
#endif
}

void PyDbViewport::setGridSubdivisionRestricted(bool bNewVal) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setGridSubdivisionRestricted(bNewVal));
#endif
}

bool PyDbViewport::isGridFollow() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return impObj()->isGridFollow();
#endif
}

void PyDbViewport::setGridFollow(bool bNewVal) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setGridFollow(bNewVal));
#endif
}

Adesk::UInt16 PyDbViewport::gridMajor() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return impObj()->gridMajor();
#endif
}

void PyDbViewport::setGridMajor(Adesk::UInt16 val) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setGridMajor(val));
#endif
}

AcGeVector2d PyDbViewport::gridIncrement() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return impObj()->gridIncrement();
#endif
}

void PyDbViewport::setGridIncrement(const AcGeVector2d& val) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setGridIncrement(val));
#endif
}

bool PyDbViewport::hiddenLinesRemoved() const
{
    return impObj()->hiddenLinesRemoved();
}

void PyDbViewport::showHiddenLines() const
{
    return PyThrowBadEs(impObj()->showHiddenLines());
}

void PyDbViewport::removeHiddenLines1() const
{
    return PyThrowBadEs(impObj()->removeHiddenLines());
}

void PyDbViewport::removeHiddenLines2(bool val) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->removeHiddenLines(val));
#endif
}

void PyDbViewport::freezeLayersInViewport(const boost::python::list& pyids) const
{
    AcDbObjectIdArray ids = PyListToObjectIdArray(pyids);
    return PyThrowBadEs(impObj()->freezeLayersInViewport(ids));
}

void PyDbViewport::thawLayersInViewport(const boost::python::list& pyids) const
{
    AcDbObjectIdArray ids = PyListToObjectIdArray(pyids);
    return PyThrowBadEs(impObj()->thawLayersInViewport(ids));
}

void PyDbViewport::thawAllLayersInViewport() const
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

void PyDbViewport::setBackground(PyDbObjectId& backgroundId) const
{
    return PyThrowBadEs(impObj()->setBackground(backgroundId.m_id));
}

PyDbObjectId PyDbViewport::previousBackground1() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyDbObjectId(impObj()->previousBackground());
#endif
}

PyDbObjectId PyDbViewport::previousBackground2(AcGiDrawable::DrawableType type) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyDbObjectId(impObj()->previousBackground(type));
#endif
}

void PyDbViewport::setPreviousBackground1(PyDbObjectId& backgroundId) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setPreviousBackground(backgroundId.m_id));
#endif
}

void PyDbViewport::setPreviousBackground2(PyDbObjectId& backgroundId, AcGiDrawable::DrawableType type) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setPreviousBackground(backgroundId.m_id, type));
#endif
}

void PyDbViewport::setPreviousBackground3(PyDbObjectId& backgroundId, AcGiDrawable::DrawableType type, bool force) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setPreviousBackground(backgroundId.m_id, type, force));
#endif
}

bool PyDbViewport::previousBackgroundForcedSwitch(void) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return impObj()->previousBackgroundForcedSwitch();
#endif
}

PyDbObjectId PyDbViewport::visualStyle() const
{
    return PyDbObjectId(impObj()->visualStyle());
}

void PyDbViewport::setVisualStyle(const PyDbObjectId& oidVisualStyle) const
{
    return PyThrowBadEs(impObj()->setVisualStyle(oidVisualStyle.m_id));
}

bool PyDbViewport::isDefaultLightingOn() const
{
    return impObj()->isDefaultLightingOn();
}

void PyDbViewport::setDefaultLightingOn(bool on) const
{
    return PyThrowBadEs(impObj()->setDefaultLightingOn(on));
}

AcGiViewportTraits::DefaultLightingType PyDbViewport::defaultLightingType() const
{
    return impObj()->defaultLightingType();
}

void PyDbViewport::setDefaultLightingType(AcGiViewportTraits::DefaultLightingType typ) const
{
    return PyThrowBadEs(impObj()->setDefaultLightingType(typ));
}

double PyDbViewport::brightness() const
{
    return impObj()->brightness();
}

void PyDbViewport::setBrightness(double val) const
{
    return PyThrowBadEs(impObj()->setBrightness(val));
}

double PyDbViewport::contrast() const
{
    return impObj()->contrast();
}

void PyDbViewport::setContrast(double val) const
{
    return PyThrowBadEs(impObj()->setContrast(val));
}

AcCmColor PyDbViewport::ambientLightColor() const
{
    return impObj()->ambientLightColor();
}

void PyDbViewport::setAmbientLightColor(const AcCmColor& clr) const
{
    return PyThrowBadEs(impObj()->setAmbientLightColor(clr));
}

PyDbObjectId PyDbViewport::sunId() const
{
    return PyDbObjectId(impObj()->sunId());
}

void PyDbViewport::setSun1(PyDbObjectId& retId, PyDbObject& pSun) const
{
    return PyThrowBadEs(impObj()->setSun(retId.m_id, pSun.impObj()));
}

void PyDbViewport::setSun2(PyDbObjectId& retId, PyDbObject& pSun, bool eraseOldSun) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setSun(retId.m_id, pSun.impObj(), eraseOldSun));
#endif
}

bool PyDbViewport::isLocked() const
{
    return impObj()->isLocked();
}

void PyDbViewport::setLocked1() const
{
    return PyThrowBadEs(impObj()->setLocked());
}

void PyDbViewport::setUnlocked() const
{
    return PyThrowBadEs(impObj()->setUnlocked());
}

void PyDbViewport::setLocked2(bool val) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setLocked(val));
#endif
}

PyDbAnnotationScale PyDbViewport::annotationScale() const
{
    return PyDbAnnotationScale(impObj()->annotationScale());
}

void PyDbViewport::setAnnotationScale(const PyDbAnnotationScale& pScaleObj) const
{
    return PyThrowBadEs(impObj()->setAnnotationScale(pScaleObj.impObj()));
}

bool PyDbViewport::isTransparent() const
{
    return impObj()->isTransparent();
}

void PyDbViewport::setTransparent1() const
{
    return PyThrowBadEs(impObj()->setTransparent());
}

void PyDbViewport::setOpaque() const
{
    return PyThrowBadEs(impObj()->setOpaque());
}

void PyDbViewport::setTransparent2(bool val) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setTransparent(val));
#endif
}

double PyDbViewport::customScale() const
{
    return impObj()->customScale();
}

void PyDbViewport::setCustomScale(double val) const
{
    return PyThrowBadEs(impObj()->setCustomScale(val));
}

AcDbViewport::StandardScaleType PyDbViewport::standardScale() const
{
    return impObj()->standardScale();
}

void PyDbViewport::setStandardScale(const AcDbViewport::StandardScaleType val) const
{
    return PyThrowBadEs(impObj()->setStandardScale(val));
}

std::string PyDbViewport::plotStyleSheet() const
{
    const ACHAR* val = nullptr;
    PyThrowBadEs(impObj()->plotStyleSheet(val));
    return wstr_to_utf8(val);
}

std::string PyDbViewport::effectivePlotStyleSheet() const
{
    const ACHAR* val = nullptr;
    PyThrowBadEs(impObj()->effectivePlotStyleSheet(val));
    return wstr_to_utf8(val);
}

void PyDbViewport::setPlotStyleSheet(const std::string& val) const
{
    return PyThrowBadEs(impObj()->setPlotStyleSheet(utf8_to_wstr(val).c_str()));
}

bool PyDbViewport::isNonRectClipOn() const
{
    return impObj()->isNonRectClipOn();
}

void PyDbViewport::setNonRectClipOn1() const
{
    return PyThrowBadEs(impObj()->setNonRectClipOn());
}

void PyDbViewport::setNonRectClipOff() const
{
    return PyThrowBadEs(impObj()->setNonRectClipOff());
}

void PyDbViewport::setNonRectClipOn2(bool bOn) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setNonRectClipOn(bOn));
#endif
}

PyDbObjectId PyDbViewport::nonRectClipEntityId() const
{
    return PyDbObjectId(impObj()->nonRectClipEntityId());
}

void PyDbViewport::setNonRectClipEntityId(const PyDbObjectId& val) const
{
    return PyThrowBadEs(impObj()->setNonRectClipEntityId(val.m_id));
}

void PyDbViewport::erased(const PyDbObject& id, Adesk::Boolean val) const
{
    return impObj()->erased(id.impObj(), val);
}

void PyDbViewport::modified(const PyDbObject& obj) const
{
    return impObj()->modified(obj.impObj());
}

void PyDbViewport::copied(const PyDbObject& pDbObj, const PyDbObject& pNewObj) const
{
    return impObj()->copied(pDbObj.impObj(), pNewObj.impObj());
}

void PyDbViewport::subObjModified(const PyDbObject& pDbObj, const PyDbObject& pSubObj) const
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

void PyDbViewport::setUcs1(const AcGePoint3d& origin, const AcGeVector3d& xAxis, const AcGeVector3d& yAxis) const
{
    return PyThrowBadEs(impObj()->setUcs(origin, xAxis, yAxis));
}

void PyDbViewport::setUcs2(AcDb::OrthographicView view) const
{
    return PyThrowBadEs(impObj()->setUcs(view));
}

void PyDbViewport::setUcs3(const PyDbObjectId& ucsId) const
{
    return PyThrowBadEs(impObj()->setUcs(ucsId.m_id));
}

void PyDbViewport::setUcsToWorld() const
{
    return PyThrowBadEs(impObj()->setUcsToWorld());
}

void PyDbViewport::setElevation(double elev) const
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
    return PyDbObjectCloneFrom<PyDbViewport, AcDbViewport>(src);
}

PyDbViewport PyDbViewport::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbViewport>(src);
}

AcDbViewport* PyDbViewport::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbViewport*>(m_pyImp.get());
}
