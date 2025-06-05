#include "stdafx.h"
#include "PyDbLayout.h"
#include "PyDbObjectId.h"

using namespace boost::python;

void makePyDbPlotSettingsWrapper()
{
    constexpr const std::string_view ctords = "Overloads:\n"
        "- None: Any\n"
        "- ModelType: bool\n"
        "- id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode, erased: bool\n";

    constexpr const std::string_view setShadePlotOverloads = "Overloads:\n"
        "- givenPoint\n"
        "- val: PyDb.ShadePlotType, id: PyDb.ObjectId\n";


    PyDocString DS("PyDb.PlotSettings");
    class_<PyDbPlotSettings, bases<PyDbObject>>("PlotSettings")
        .def(init<>())
        .def(init<bool>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.CTOR(ctords, 7416)))
        .def("addToPlotSettingsDict", &PyDbPlotSettings::addToPlotSettingsDict, DS.ARGS({ "db: PyDb.Database" }))
        .def("getPlotSettingsName", &PyDbPlotSettings::getPlotSettingsName, DS.ARGS())
        .def("setPlotSettingsName", &PyDbPlotSettings::setPlotSettingsName, DS.ARGS({ "val: str" }))
        .def("getPlotCfgName", &PyDbPlotSettings::getPlotCfgName, DS.ARGS())
        .def("getPlotPaperMargins", &PyDbPlotSettings::getPlotPaperMargins, DS.ARGS())
        .def("getPlotPaperSize", &PyDbPlotSettings::getPlotPaperSize, DS.ARGS())
        .def("getCanonicalMediaName", &PyDbPlotSettings::getCanonicalMediaName, DS.ARGS())
        .def("getPlotOrigin", &PyDbPlotSettings::getPlotOrigin, DS.ARGS())
        .def("plotPaperUnits", &PyDbPlotSettings::plotPaperUnits, DS.ARGS())
        .def("plotViewportBorders", &PyDbPlotSettings::plotViewportBorders, DS.ARGS())
        .def("setPlotViewportBorders", &PyDbPlotSettings::setPlotViewportBorders, DS.ARGS({ "val: bool" }))
        .def("plotTransparency", &PyDbPlotSettings::plotTransparency, DS.ARGS())
        .def("setPlotTransparency", &PyDbPlotSettings::setPlotTransparency, DS.ARGS({ "val: bool" }))
        .def("plotPlotStyles", &PyDbPlotSettings::plotPlotStyles, DS.ARGS())
        .def("setPlotPlotStyles", &PyDbPlotSettings::setPlotPlotStyles, DS.ARGS({ "val: bool" }))
        .def("showPlotStyles", &PyDbPlotSettings::showPlotStyles, DS.ARGS())
        .def("setShowPlotStyles", &PyDbPlotSettings::setShowPlotStyles, DS.ARGS({ "val: bool" }))
        .def("plotRotation", &PyDbPlotSettings::plotRotation, DS.ARGS())
        .def("plotCentered", &PyDbPlotSettings::plotCentered, DS.ARGS())
        .def("plotHidden", &PyDbPlotSettings::plotHidden, DS.ARGS())
        .def("setPlotHidden", &PyDbPlotSettings::setPlotHidden, DS.ARGS({ "val: bool" }))
        .def("shadePlot", &PyDbPlotSettings::shadePlot, DS.ARGS())
        .def("shadePlotId", &PyDbPlotSettings::shadePlotId, DS.ARGS())
        .def("setShadePlot", &PyDbPlotSettings::setShadePlot1)
        .def("setShadePlot", &PyDbPlotSettings::setShadePlot2, DS.OVRL(setShadePlotOverloads))
        .def("shadePlotResLevel", &PyDbPlotSettings::shadePlotResLevel, DS.ARGS())
        .def("setShadePlotResLevel", &PyDbPlotSettings::setShadePlotResLevel, DS.ARGS({ "val: PyDb.ShadePlotResLevel" }))
        .def("shadePlotCustomDPI", &PyDbPlotSettings::shadePlotCustomDPI, DS.ARGS())
        .def("setShadePlotCustomDPI", &PyDbPlotSettings::setShadePlotCustomDPI, DS.ARGS({ "val: int" }))
        .def("plotType", &PyDbPlotSettings::plotType, DS.ARGS())
        .def("getPlotWindowArea", &PyDbPlotSettings::getPlotWindowArea, DS.ARGS())
        .def("getPlotViewName", &PyDbPlotSettings::getPlotViewName, DS.ARGS())
        .def("useStandardScale", &PyDbPlotSettings::useStandardScale, DS.ARGS())
        .def("getCustomPrintScale", &PyDbPlotSettings::getCustomPrintScale, DS.ARGS())
        .def("getCurrentStyleSheet", &PyDbPlotSettings::getCurrentStyleSheet, DS.ARGS())
        .def("stdScaleType", &PyDbPlotSettings::stdScaleType, DS.ARGS())
        .def("getStdScale", &PyDbPlotSettings::getStdScale, DS.ARGS())
        .def("scaleLineweights", &PyDbPlotSettings::scaleLineweights, DS.ARGS())
        .def("setScaleLineweights", &PyDbPlotSettings::setScaleLineweights, DS.ARGS({ "val: bool" }))
        .def("printLineweights", &PyDbPlotSettings::printLineweights, DS.ARGS())
        .def("setPrintLineweights", &PyDbPlotSettings::setPrintLineweights, DS.ARGS({ "val: bool" }))
        .def("drawViewportsFirst", &PyDbPlotSettings::drawViewportsFirst, DS.ARGS())
        .def("setDrawViewportsFirst", &PyDbPlotSettings::setDrawViewportsFirst, DS.ARGS({ "val: bool" }))
        .def("modelType", &PyDbPlotSettings::modelType, DS.ARGS())
        .def("plotWireframe", &PyDbPlotSettings::plotWireframe, DS.ARGS())
        .def("plotAsRaster", &PyDbPlotSettings::plotAsRaster, DS.ARGS())
        .def("className", &PyDbPlotSettings::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbPlotSettings::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyDbPlotSettings::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbPlotSettings::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
    enum_<AcDbPlotSettings::PlotPaperUnits>("PlotPaperUnits")
        .value("kInches", AcDbPlotSettings::PlotPaperUnits::kInches)
        .value("kMillimeters", AcDbPlotSettings::PlotPaperUnits::kMillimeters)
        .value("kPixels", AcDbPlotSettings::PlotPaperUnits::kPixels)
        .export_values()
        ;
    enum_<AcDbPlotSettings::PlotRotation>("PlotRotation")
        .value("k0degrees", AcDbPlotSettings::PlotRotation::k0degrees)
        .value("k90degrees", AcDbPlotSettings::PlotRotation::k90degrees)
        .value("k180degrees", AcDbPlotSettings::PlotRotation::k180degrees)
        .value("k270degrees", AcDbPlotSettings::PlotRotation::k270degrees)
        .export_values()
        ;
    enum_<AcDbPlotSettings::PlotType>("PlotType")
        .value("kDisplay", AcDbPlotSettings::PlotType::kDisplay)
        .value("kExtents", AcDbPlotSettings::PlotType::kExtents)
        .value("kLimits", AcDbPlotSettings::PlotType::kLimits)
        .value("kView", AcDbPlotSettings::PlotType::kView)
        .value("kWindow", AcDbPlotSettings::PlotType::kWindow)
        .value("kLayout", AcDbPlotSettings::PlotType::kLayout)
        .export_values()
        ;
    enum_<AcDbPlotSettings::StdScaleType>("StdScaleType")
        .value("kScaleToFit", AcDbPlotSettings::StdScaleType::kScaleToFit)
        .value("k1_128in_1ft", AcDbPlotSettings::StdScaleType::k1_128in_1ft)
        .value("k1_64in_1ft", AcDbPlotSettings::StdScaleType::k1_64in_1ft)
        .value("k1_32in_1ft", AcDbPlotSettings::StdScaleType::k1_32in_1ft)
        .value("k1_16in_1ft", AcDbPlotSettings::StdScaleType::k1_16in_1ft)
        .value("k3_32in_1ft", AcDbPlotSettings::StdScaleType::k3_32in_1ft)
        .value("k1_8in_1ft", AcDbPlotSettings::StdScaleType::k1_8in_1ft)
        .value("k3_16in_1ft", AcDbPlotSettings::StdScaleType::k3_16in_1ft)
        .value("k1_4in_1ft", AcDbPlotSettings::StdScaleType::k1_4in_1ft)
        .value("k3_8in_1ft", AcDbPlotSettings::StdScaleType::k3_8in_1ft)
        .value("k1_2in_1ft", AcDbPlotSettings::StdScaleType::k1_2in_1ft)
        .value("k3_4in_1ft", AcDbPlotSettings::StdScaleType::k3_4in_1ft)
        .value("k1in_1ft", AcDbPlotSettings::StdScaleType::k1in_1ft)
        .value("k3in_1ft", AcDbPlotSettings::StdScaleType::k3in_1ft)
        .value("k6in_1ft", AcDbPlotSettings::StdScaleType::k6in_1ft)
        .value("k1ft_1ft", AcDbPlotSettings::StdScaleType::k1ft_1ft)
        .value("k1_1", AcDbPlotSettings::StdScaleType::k1_1)
        .value("k1_2", AcDbPlotSettings::StdScaleType::k1_2)
        .value("k1_4", AcDbPlotSettings::StdScaleType::k1_4)
        .value("k1_5", AcDbPlotSettings::StdScaleType::k1_5)
        .value("k1_8", AcDbPlotSettings::StdScaleType::k1_8)
        .value("k1_10", AcDbPlotSettings::StdScaleType::k1_10)
        .value("k1_16", AcDbPlotSettings::StdScaleType::k1_16)
        .value("k1_20", AcDbPlotSettings::StdScaleType::k1_20)
        .value("k1_30", AcDbPlotSettings::StdScaleType::k1_30)
        .value("k1_40", AcDbPlotSettings::StdScaleType::k1_40)
        .value("k1_50", AcDbPlotSettings::StdScaleType::k1_50)
        .value("k1_100", AcDbPlotSettings::StdScaleType::k1_100)
        .value("k2_1", AcDbPlotSettings::StdScaleType::k2_1)
        .value("k4_1", AcDbPlotSettings::StdScaleType::k4_1)
        .value("k8_1", AcDbPlotSettings::StdScaleType::k8_1)
        .value("k10_1", AcDbPlotSettings::StdScaleType::k10_1)
        .value("k100_1", AcDbPlotSettings::StdScaleType::k100_1)
        .value("k1000_1", AcDbPlotSettings::StdScaleType::k1000_1)
        .value("k1and1_2in_1ft", AcDbPlotSettings::StdScaleType::k1and1_2in_1ft)
        .export_values()
        ;
    enum_<AcDbPlotSettings::ShadePlotType>("ShadePlotType")
        .value("kAsDisplayed", AcDbPlotSettings::ShadePlotType::kAsDisplayed)
        .value("kWireframe", AcDbPlotSettings::ShadePlotType::kWireframe)
        .value("kHidden", AcDbPlotSettings::ShadePlotType::kHidden)
        .value("kRendered", AcDbPlotSettings::ShadePlotType::kRendered)
        .value("kVisualStyle", AcDbPlotSettings::ShadePlotType::kVisualStyle)
        .value("kRenderPreset", AcDbPlotSettings::ShadePlotType::kRenderPreset)
        .export_values()
        ;
    enum_<AcDbPlotSettings::ShadePlotResLevel>("ShadePlotResLevel")
        .value("kAsDisplayed", AcDbPlotSettings::ShadePlotResLevel::kDraft)
        .value("kPreview", AcDbPlotSettings::ShadePlotResLevel::kPreview)
        .value("kNormal", AcDbPlotSettings::ShadePlotResLevel::kNormal)
        .value("kPresentation", AcDbPlotSettings::ShadePlotResLevel::kPresentation)
        .value("kMaximum", AcDbPlotSettings::ShadePlotResLevel::kMaximum)
        .value("kCustom", AcDbPlotSettings::ShadePlotResLevel::kCustom)
        .export_values()
        ;
}

PyDbPlotSettings::PyDbPlotSettings()
    : PyDbObject(new AcDbPlotSettings(), true)
{
}

PyDbPlotSettings::PyDbPlotSettings(bool ModelType)
    : PyDbObject(new AcDbPlotSettings(ModelType), true)
{
}

PyDbPlotSettings::PyDbPlotSettings(AcDbPlotSettings* ptr, bool autoDelete)
    : PyDbObject(ptr, autoDelete)
{
}

PyDbPlotSettings::PyDbPlotSettings(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbObject(openAcDbObject<AcDbPlotSettings>(id, mode), false)
{
}

PyDbPlotSettings::PyDbPlotSettings(const PyDbObjectId& id)
    : PyDbPlotSettings(id, AcDb::OpenMode::kForRead)
{
}

PyDbPlotSettings::PyDbPlotSettings(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbObject(openAcDbObject<AcDbPlotSettings>(id, mode, erased), false)
{
}

void PyDbPlotSettings::addToPlotSettingsDict(PyDbDatabase& towhichDb) const
{
    return PyThrowBadEs(impObj()->addToPlotSettingsDict(towhichDb.impObj()));
}

std::string PyDbPlotSettings::getPlotSettingsName() const
{
    const wchar_t* plotSettingsName = nullptr;
    PyThrowBadEs(impObj()->getPlotSettingsName(plotSettingsName));
    return wstr_to_utf8(plotSettingsName);
}

void PyDbPlotSettings::setPlotSettingsName(const std::string& plotSettingsName) const
{
    return PyThrowBadEs(impObj()->setPlotSettingsName(utf8_to_wstr(plotSettingsName).c_str()));
}

std::string PyDbPlotSettings::getPlotCfgName() const
{
    const wchar_t* plotCfgName = nullptr;
    PyThrowBadEs(impObj()->getPlotCfgName(plotCfgName));
    return wstr_to_utf8(plotCfgName);
}

boost::python::tuple PyDbPlotSettings::getPlotPaperMargins() const
{
    PyAutoLockGIL lock;
    double printableXmin = 0;
    double printableYmin = 0;
    double printableXmax = 0;
    double printableYmax = 0;
    PyThrowBadEs(impObj()->getPlotPaperMargins(printableXmin, printableYmin, printableXmax, printableYmax));
    return boost::python::make_tuple(printableXmin, printableYmin, printableXmax, printableYmax);
}

boost::python::tuple PyDbPlotSettings::getPlotPaperSize() const
{
    PyAutoLockGIL lock;
    double paperWidth = 0;
    double paperHeight = 0;
    PyThrowBadEs(impObj()->getPlotPaperSize(paperWidth, paperHeight));
    return boost::python::make_tuple(paperWidth, paperHeight);
}

std::string PyDbPlotSettings::getCanonicalMediaName() const
{
    const wchar_t* mediaName = nullptr;
    PyThrowBadEs(impObj()->getCanonicalMediaName(mediaName));
    return wstr_to_utf8(mediaName);
}

boost::python::tuple PyDbPlotSettings::getPlotOrigin() const
{
    PyAutoLockGIL lock;
    double x = 0;
    double y = 0;
    PyThrowBadEs(impObj()->getPlotOrigin(x, y));
    return boost::python::make_tuple(x, y);
}

AcDbPlotSettings::PlotPaperUnits PyDbPlotSettings::plotPaperUnits() const
{
    return impObj()->plotPaperUnits();
}

Adesk::Boolean PyDbPlotSettings::plotViewportBorders() const
{
    return impObj()->plotViewportBorders();
}

void PyDbPlotSettings::setPlotViewportBorders(Adesk::Boolean plotViewportBorders) const
{
    impObj()->setPlotViewportBorders(plotViewportBorders);
}

Adesk::Boolean PyDbPlotSettings::plotTransparency() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return impObj()->plotTransparency();
#endif
}

void PyDbPlotSettings::setPlotTransparency(Adesk::Boolean plotTransparency) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    impObj()->setPlotTransparency(plotTransparency);
#endif
}

Adesk::Boolean PyDbPlotSettings::plotPlotStyles() const
{
    return impObj()->plotPlotStyles();
}

void PyDbPlotSettings::setPlotPlotStyles(Adesk::Boolean plotPlotStyles) const
{
    impObj()->setPlotPlotStyles(plotPlotStyles);
}

Adesk::Boolean PyDbPlotSettings::showPlotStyles() const
{
    return impObj()->showPlotStyles();
}

void PyDbPlotSettings::setShowPlotStyles(Adesk::Boolean showPlotStyles) const
{
    impObj()->setShowPlotStyles(showPlotStyles);
}

AcDbPlotSettings::PlotRotation PyDbPlotSettings::plotRotation() const
{
    return impObj()->plotRotation();
}

Adesk::Boolean PyDbPlotSettings::plotCentered() const
{
    return impObj()->plotCentered();
}

Adesk::Boolean PyDbPlotSettings::plotHidden() const
{
    return impObj()->plotHidden();
}

void PyDbPlotSettings::setPlotHidden(Adesk::Boolean plotHidden) const
{
    impObj()->setPlotHidden(plotHidden);
}

AcDbPlotSettings::ShadePlotType PyDbPlotSettings::shadePlot() const
{
    return impObj()->shadePlot();
}

void PyDbPlotSettings::setShadePlot1(AcDbPlotSettings::ShadePlotType shadePlot) const
{
    return PyThrowBadEs(impObj()->setShadePlot(shadePlot));
}

void PyDbPlotSettings::setShadePlot2(AcDbPlotSettings::ShadePlotType type, const PyDbObjectId& shadePlotId) const
{
    return PyThrowBadEs(impObj()->setShadePlot(type, shadePlotId.m_id));
}

bool PyDbPlotSettings::plotWireframe() const
{
    return impObj()->plotWireframe();
}

bool PyDbPlotSettings::plotAsRaster() const
{
    return impObj()->plotAsRaster();
}

AcDbPlotSettings::ShadePlotResLevel PyDbPlotSettings::shadePlotResLevel() const
{
    return impObj()->shadePlotResLevel();
}

void PyDbPlotSettings::setShadePlotResLevel(AcDbPlotSettings::ShadePlotResLevel resLevel) const
{
    return PyThrowBadEs(impObj()->setShadePlotResLevel(resLevel));
}

Adesk::Int16 PyDbPlotSettings::shadePlotCustomDPI() const
{
    return impObj()->shadePlotCustomDPI();
}

void PyDbPlotSettings::setShadePlotCustomDPI(Adesk::Int16 val) const
{
    return PyThrowBadEs(impObj()->setShadePlotCustomDPI(val));
}

AcDbPlotSettings::PlotType PyDbPlotSettings::plotType() const
{
    return impObj()->plotType();
}

boost::python::tuple PyDbPlotSettings::getPlotWindowArea() const
{
    PyAutoLockGIL lock;
    double printableXmin = 0;
    double printableYmin = 0;
    double printableXmax = 0;
    double printableYmax = 0;
    PyThrowBadEs(impObj()->getPlotWindowArea(printableXmin, printableYmin, printableXmax, printableYmax));
    return boost::python::make_tuple(printableXmin, printableYmin, printableXmax, printableYmax);
}

std::string PyDbPlotSettings::getPlotViewName() const
{
    const ACHAR* viewName = nullptr;
    PyThrowBadEs(impObj()->getPlotViewName(viewName));
    return wstr_to_utf8(viewName);
}

Adesk::Boolean PyDbPlotSettings::useStandardScale() const
{
    return impObj()->useStandardScale();
}

boost::python::tuple PyDbPlotSettings::getCustomPrintScale() const
{
    PyAutoLockGIL lock;
    double x = 0;
    double y = 0;
    PyThrowBadEs(impObj()->getCustomPrintScale(x, y));
    return boost::python::make_tuple(x, y);
}

std::string PyDbPlotSettings::getCurrentStyleSheet() const
{
    const ACHAR* styleSheetName = nullptr;
    PyThrowBadEs(impObj()->getCurrentStyleSheet(styleSheetName));
    return wstr_to_utf8(styleSheetName);
}

AcDbPlotSettings::StdScaleType PyDbPlotSettings::stdScaleType() const
{
    return impObj()->stdScaleType();
}

double PyDbPlotSettings::getStdScale() const
{
    double scale = 0;
    PyThrowBadEs(impObj()->getStdScale(scale));
    return scale;
}

Adesk::Boolean PyDbPlotSettings::scaleLineweights() const
{
    return impObj()->scaleLineweights();
}

void PyDbPlotSettings::setScaleLineweights(Adesk::Boolean scaleLineweights) const
{
    return impObj()->setScaleLineweights(scaleLineweights);
}

Adesk::Boolean PyDbPlotSettings::printLineweights() const
{
    return impObj()->printLineweights();
}

void PyDbPlotSettings::setPrintLineweights(Adesk::Boolean printLineweights) const
{
    impObj()->setPrintLineweights(printLineweights);
}

Adesk::Boolean PyDbPlotSettings::drawViewportsFirst() const
{
    return impObj()->drawViewportsFirst();
}

void PyDbPlotSettings::setDrawViewportsFirst(Adesk::Boolean drawViewportsFirst) const
{
    impObj()->setDrawViewportsFirst(drawViewportsFirst);
}

Adesk::Boolean PyDbPlotSettings::modelType() const
{
    return impObj()->modelType();
}

PyDbObjectId PyDbPlotSettings::shadePlotId() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyDbObjectId(impObj()->shadePlotId());
#endif
}

std::string PyDbPlotSettings::className()
{
    return "AcDbPlotSettings";
}

PyRxClass PyDbPlotSettings::desc()
{
    return PyRxClass(AcDbPlotSettings::desc(), false);
}

PyDbPlotSettings PyDbPlotSettings::cloneFrom(const PyRxObject& src)
{
    return PyDbObjectCloneFrom<PyDbPlotSettings, AcDbPlotSettings>(src);
}

PyDbPlotSettings PyDbPlotSettings::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbPlotSettings>(src);
}

AcDbPlotSettings* PyDbPlotSettings::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbPlotSettings*>(m_pyImp.get());
}

//---------------------------------------------------------------------------------------- -
//PyDbLayout
void makePyDbLayoutWrapper()
{
    constexpr const std::string_view ctords = "Overloads:\n"
        "- None: Any\n"
        "- id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode, erased: bool\n";

    PyDocString DS("PyDb.Layout");
    class_<PyDbLayout, bases<PyDbPlotSettings>>("Layout")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.CTOR(ctords , 5829)))
        .def("getBlockTableRecordId", &PyDbLayout::getBlockTableRecordId, DS.ARGS())
        .def("setBlockTableRecordId", &PyDbLayout::setBlockTableRecordId, DS.ARGS({ "id: PyDb.ObjectId" }))
        .def("addToLayoutDict", &PyDbLayout::addToLayoutDict, DS.ARGS({ "db: PyDb.Database","id: PyDb.ObjectId" }))
        .def("getLayoutName", &PyDbLayout::getLayoutName, DS.ARGS())
        .def("setLayoutName", &PyDbLayout::setLayoutName, DS.ARGS({ "val: str" }))
        .def("getTabOrder", &PyDbLayout::getTabOrder, DS.ARGS())
        .def("setTabOrder", &PyDbLayout::setTabOrder, DS.ARGS({ "val: int" }))
        .def("getTabSelected", &PyDbLayout::getTabSelected, DS.ARGS())
        .def("setTabSelected", &PyDbLayout::setTabSelected, DS.ARGS({ "val: bool" }))
        .def("getViewportArray", &PyDbLayout::getViewportArray, DS.ARGS())
        .def("getLimits", &PyDbLayout::getLimits, DS.ARGS())
        .def("getExtents", &PyDbLayout::getExtents, DS.ARGS())
        .def("initialize", &PyDbLayout::initialize1)
        .def("initialize", &PyDbLayout::initialize2, DS.ARGS({ "id: PyDb.ObjectId='default'" }))
        .def("annoAllVisible", &PyDbLayout::annoAllVisible, DS.ARGS())
        .def("setAnnoAllVisible", &PyDbLayout::setAnnoAllVisible, DS.ARGS({ "val: bool" }))
        .def("className", &PyDbLayout::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbLayout::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyDbLayout::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbLayout::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyDbLayout::PyDbLayout()
    :PyDbPlotSettings(new AcDbLayout(), true)
{
}

PyDbLayout::PyDbLayout(AcDbLayout* ptr, bool autoDelete)
    : PyDbPlotSettings(ptr, autoDelete)
{
}

PyDbLayout::PyDbLayout(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbPlotSettings(openAcDbObject<AcDbLayout>(id, mode), false)
{
}

PyDbLayout::PyDbLayout(const PyDbObjectId& id)
    : PyDbLayout(id, AcDb::OpenMode::kForRead)
{
}

PyDbLayout::PyDbLayout(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbPlotSettings(openAcDbObject<AcDbLayout>(id, mode, erased), false)
{
}

PyDbObjectId PyDbLayout::getBlockTableRecordId() const
{
    return PyDbObjectId(impObj()->getBlockTableRecordId());
}

void PyDbLayout::setBlockTableRecordId(PyDbObjectId& BlockTableRecordId) const
{
    return PyThrowBadEs(impObj()->setBlockTableRecordId(BlockTableRecordId.m_id));
}

void PyDbLayout::addToLayoutDict(PyDbDatabase& towhichDb, PyDbObjectId BlockTableRecordId) const
{
    return PyThrowBadEs(impObj()->addToLayoutDict(towhichDb.impObj(), BlockTableRecordId.m_id));
}

std::string PyDbLayout::getLayoutName() const
{
    const ACHAR* layoutName = nullptr;
    PyThrowBadEs(impObj()->getLayoutName(layoutName));
    return wstr_to_utf8(layoutName);
}

void PyDbLayout::setLayoutName(const std::string& layoutName) const
{
    return PyThrowBadEs(impObj()->setLayoutName(utf8_to_wstr(layoutName).c_str()));
}

int PyDbLayout::getTabOrder() const
{
    return impObj()->getTabOrder();
}

void PyDbLayout::setTabOrder(int newOrder) const
{
    impObj()->setTabOrder(newOrder);
}

bool PyDbLayout::getTabSelected() const
{
    return impObj()->getTabSelected();
}

void PyDbLayout::setTabSelected(Adesk::Boolean tabSelected) const
{
    impObj()->setTabSelected(tabSelected);
}

boost::python::list PyDbLayout::getViewportArray() const
{
    PyAutoLockGIL lock;
    AcDbObjectIdArray ids;
    boost::python::list pyids;
    ids = impObj()->getViewportArray();
    for (auto& id : ids)
        pyids.append(PyDbObjectId(id));
    return pyids;
}

boost::python::tuple PyDbLayout::getLimits() const
{
    PyAutoLockGIL lock;
    AcGePoint2d limMin;
    AcGePoint2d limMax;
    impObj()->getLimits(limMin, limMax);
    return boost::python::make_tuple(limMin, limMax);
}

boost::python::tuple PyDbLayout::getExtents() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    PyAutoLockGIL lock;
    AcGePoint3d extMin;
    AcGePoint3d extMax;
    impObj()->getExtents(extMin, extMax);
    return boost::python::make_tuple(extMin, extMax);
#endif
}

void PyDbLayout::initialize1() const
{
    return PyThrowBadEs(impObj()->initialize());
}

void PyDbLayout::initialize2(PyDbObjectId& paperVportId) const
{
    return PyThrowBadEs(impObj()->initialize(&paperVportId.m_id));
}

bool PyDbLayout::annoAllVisible() const
{
    return impObj()->annoAllVisible();
}

void PyDbLayout::setAnnoAllVisible(bool newVal) const
{
    return PyThrowBadEs(impObj()->setAnnoAllVisible(newVal));
}

std::string PyDbLayout::className()
{
    return "AcDbLayout";
}

PyRxClass PyDbLayout::desc()
{
    return PyRxClass(AcDbLayout::desc(), false);
}

PyDbLayout PyDbLayout::cloneFrom(const PyRxObject& src)
{
    return PyDbObjectCloneFrom<PyDbLayout, AcDbLayout>(src);
}

PyDbLayout PyDbLayout::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbLayout>(src);
}

AcDbLayout* PyDbLayout::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbLayout*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
//PyDbLayoutManager
void makePyDbLayoutManagerWrapper()
{
    PyDocString DS("LayoutManager");
    class_<PyDbLayoutManager, bases<PyRxObject>>("LayoutManager")
        .def(init<>(DS.ARGS()))
        .def("setCurrentLayout", &PyDbLayoutManager::setCurrentLayout1)
        .def("setCurrentLayout", &PyDbLayoutManager::setCurrentLayout2, DS.ARGS({ "name: str","db: PyDb.Database = ..." }))
        .def("setCurrentLayoutId", &PyDbLayoutManager::setCurrentLayoutId, DS.ARGS({ "id: PyDb.ObjectId" }))
        .def("getActiveLayoutName", &PyDbLayoutManager::getActiveLayoutName1)
        .def("getActiveLayoutName", &PyDbLayoutManager::getActiveLayoutName2, DS.ARGS({ "allowModel: bool","db: PyDb.Database = ..." }))
        .def("getActiveLayoutBTRId", &PyDbLayoutManager::getActiveLayoutBTRId1)
        .def("getActiveLayoutBTRId", &PyDbLayoutManager::getActiveLayoutBTRId2, DS.ARGS({ "db: PyDb.Database = ..." }))
        .def("findLayoutNamed", &PyDbLayoutManager::findLayoutNamed1)
        .def("findLayoutNamed", &PyDbLayoutManager::findLayoutNamed2, DS.ARGS({ "name: str","db: PyDb.Database = ..." }))
        .def("layoutExists", &PyDbLayoutManager::layoutExists1)
        .def("layoutExists", &PyDbLayoutManager::layoutExists2, DS.ARGS({ "name: str","db: PyDb.Database = ..." }))
        .def("copyLayout", &PyDbLayoutManager::copyLayout1)
        .def("copyLayout", &PyDbLayoutManager::copyLayout2, DS.ARGS({ "name: str", "newname: str", "db: PyDb.Database = ..." }))
        .def("deleteLayout", &PyDbLayoutManager::deleteLayout1)
        .def("deleteLayout", &PyDbLayoutManager::deleteLayout2, DS.ARGS({ "name: str","db: PyDb.Database = ..." }))
        .def("createLayout", &PyDbLayoutManager::createLayout1)
        .def("createLayout", &PyDbLayoutManager::createLayout2, DS.ARGS({ "name: str","db: PyDb.Database = ..." }))
        .def("renameLayout", &PyDbLayoutManager::renameLayout1)
        .def("renameLayout", &PyDbLayoutManager::renameLayout2, DS.ARGS({ "name: str", "newname: str", "db: PyDb.Database = ..." }))
        .def("cloneLayout", &PyDbLayoutManager::cloneLayout1)
        .def("cloneLayout", &PyDbLayoutManager::cloneLayout2, DS.ARGS({ "layout: PyDb.Layout","newname: str", "newTabOrder: int", "db: PyDb.Database = ..." }))
        .def("getNonRectVPIdFromClipId", &PyDbLayoutManager::getNonRectVPIdFromClipId, DS.ARGS({ "id: PyDb.ObjectId" }))
        .def("isVpnumClipped", &PyDbLayoutManager::isVpnumClipped1)
        .def("isVpnumClipped", &PyDbLayoutManager::isVpnumClipped2, DS.ARGS({ "idx: int","db: PyDb.Database = ..." }))
        .def("countLayouts", &PyDbLayoutManager::countLayouts1)
        .def("countLayouts", &PyDbLayoutManager::countLayouts2, DS.ARGS({ "db: PyDb.Database = ..." }))
        .def("getLayouts", &PyDbLayoutManager::getLayouts1)
        .def("getLayouts", &PyDbLayoutManager::getLayouts2, DS.ARGS({ "db: PyDb.Database = ..." }))
        .def("setupForLayouts", &PyDbLayoutManager::setupForLayouts, DS.SARGS({ "db: PyDb.Database" })).staticmethod("setupForLayouts")
        .def("clearSetupForLayouts", &PyDbLayoutManager::clearSetupForLayouts, DS.SARGS({ "handle: int" })).staticmethod("clearSetupForLayouts")
        .def("desc", &PyDbLayoutManager::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("className", &PyDbLayoutManager::className, DS.SARGS()).staticmethod("className")
        ;
}

PyDbLayoutManager::PyDbLayoutManager()
    : PyDbLayoutManager(acdbHostApplicationServices()->layoutManager(), false)
{
}

PyDbLayoutManager::PyDbLayoutManager(AcDbLayoutManager* ptr, bool autoDelete)
    : PyRxObject(ptr, autoDelete, false)
{
}

void PyDbLayoutManager::setCurrentLayout1(const std::string& newname) const
{
    return PyThrowBadEs(impObj()->setCurrentLayout(utf8_to_wstr(newname).c_str()));
}

void PyDbLayoutManager::setCurrentLayout2(const std::string& newname, PyDbDatabase& pDb) const
{
#ifdef ZRXAPP
    AutoWorkingDatabase autowb(pDb.impObj());
#endif // ZRXAPP
    return PyThrowBadEs(impObj()->setCurrentLayout(utf8_to_wstr(newname).c_str(), pDb.impObj()));
}

void PyDbLayoutManager::setCurrentLayoutId(const PyDbObjectId& layoutId) const
{
    return PyThrowBadEs(impObj()->setCurrentLayoutId(layoutId.m_id));
}

std::string PyDbLayoutManager::getActiveLayoutName1(bool allowModel) const
{
    AcString sName;
    PyThrowBadEs(impObj()->getActiveLayoutName(sName, allowModel));
    return wstr_to_utf8(sName);
}

std::string PyDbLayoutManager::getActiveLayoutName2(bool allowModel, PyDbDatabase& pDb) const
{
#ifdef ZRXAPP
    AutoWorkingDatabase autowb(pDb.impObj());
#endif // ZRXAPP
    AcString sName;
    PyThrowBadEs(impObj()->getActiveLayoutName(sName, allowModel, pDb.impObj()));
    return wstr_to_utf8(sName);
}

PyDbObjectId PyDbLayoutManager::getActiveLayoutBTRId1() const
{
    return PyDbObjectId(impObj()->getActiveLayoutBTRId());
}

PyDbObjectId PyDbLayoutManager::getActiveLayoutBTRId2(const PyDbDatabase& pDb) const
{
#ifdef ZRXAPP
    AutoWorkingDatabase autowb(pDb.impObj());
#endif // ZRXAPP
    return PyDbObjectId(impObj()->getActiveLayoutBTRId(pDb.impObj()));
}

PyDbObjectId PyDbLayoutManager::findLayoutNamed1(const std::string& name) const
{
    return PyDbObjectId(impObj()->findLayoutNamed(utf8_to_wstr(name).c_str()));
}

PyDbObjectId PyDbLayoutManager::findLayoutNamed2(const std::string& name, const PyDbDatabase& pDb) const
{
#ifdef ZRXAPP
    AutoWorkingDatabase autowb(pDb.impObj());
#endif // ZRXAPP
    return PyDbObjectId(impObj()->findLayoutNamed(utf8_to_wstr(name).c_str(), pDb.impObj()));
}

bool PyDbLayoutManager::layoutExists1(const std::string& name) const
{
    return impObj()->layoutExists(utf8_to_wstr(name).c_str());
}

bool PyDbLayoutManager::layoutExists2(const std::string& name, const PyDbDatabase& pDb) const
{
#ifdef ZRXAPP
    AutoWorkingDatabase autowb(pDb.impObj());
#endif // ZRXAPP
    return impObj()->layoutExists(utf8_to_wstr(name).c_str(), pDb.impObj());
}

void PyDbLayoutManager::copyLayout1(const std::string& copyname, const std::string& newname) const
{
    return PyThrowBadEs(impObj()->copyLayout(utf8_to_wstr(copyname).c_str(), utf8_to_wstr(newname).c_str()));
}

void PyDbLayoutManager::copyLayout2(const std::string& copyname, const std::string& newname, const PyDbDatabase& pDb) const
{
#ifdef ZRXAPP
    AutoWorkingDatabase autowb(pDb.impObj());
#endif // ZRXAPP
    return PyThrowBadEs(impObj()->copyLayout(utf8_to_wstr(copyname).c_str(), utf8_to_wstr(newname).c_str(), pDb.impObj()));
}

void PyDbLayoutManager::deleteLayout1(const std::string& delname) const
{
    return PyThrowBadEs(impObj()->deleteLayout(utf8_to_wstr(delname).c_str()));
}

void PyDbLayoutManager::deleteLayout2(const std::string& delname, PyDbDatabase& pDb) const
{
#ifdef ZRXAPP
    AutoWorkingDatabase autowb(pDb.impObj());
#endif // ZRXAPP
    return PyThrowBadEs(impObj()->deleteLayout(utf8_to_wstr(delname).c_str(), pDb.impObj()));
}

boost::python::tuple PyDbLayoutManager::createLayout1(const std::string& newname) const
{
    PyDbObjectId layoutId;
    PyDbObjectId blockTableRecId;
    PyThrowBadEs(impObj()->createLayout(utf8_to_wstr(newname).c_str(), layoutId.m_id, blockTableRecId.m_id));
    return boost::python::make_tuple(layoutId, blockTableRecId);
}

boost::python::tuple PyDbLayoutManager::createLayout2(const std::string& newname, PyDbDatabase& pDb) const
{
#ifdef ZRXAPP
    AutoWorkingDatabase autowb(pDb.impObj());
#endif // ZRXAPP
    PyDbObjectId layoutId;
    PyDbObjectId blockTableRecId;
    PyThrowBadEs(impObj()->createLayout(utf8_to_wstr(newname).c_str(), layoutId.m_id, blockTableRecId.m_id, pDb.impObj()));
    return boost::python::make_tuple(layoutId, blockTableRecId);
}

void PyDbLayoutManager::renameLayout1(const std::string& oldname, const std::string& newname) const
{
    return PyThrowBadEs(impObj()->renameLayout(utf8_to_wstr(oldname).c_str(), utf8_to_wstr(newname).c_str()));
}

void PyDbLayoutManager::renameLayout2(const std::string& oldname, const std::string& newname, PyDbDatabase& pDb) const
{
#ifdef ZRXAPP
    AutoWorkingDatabase autowb(pDb.impObj());
#endif // ZRXAPP
    return PyThrowBadEs(impObj()->renameLayout(utf8_to_wstr(oldname).c_str(), utf8_to_wstr(newname).c_str(), pDb.impObj()));
}

void PyDbLayoutManager::cloneLayout1(PyDbLayout& pLBTR, const std::string& newname) const
{
    return PyThrowBadEs(impObj()->cloneLayout(pLBTR.impObj(), utf8_to_wstr(newname).c_str()));
}

void PyDbLayoutManager::cloneLayout2(PyDbLayout& pLBTR, const std::string& newname, int newTabOrder, PyDbDatabase& pDb) const
{
#ifdef ZRXAPP
    AutoWorkingDatabase autowb(pDb.impObj());
#endif // ZRXAPP
    return PyThrowBadEs(impObj()->cloneLayout(pLBTR.impObj(), utf8_to_wstr(newname).c_str(), newTabOrder, pDb.impObj()));
}

PyDbObjectId PyDbLayoutManager::getNonRectVPIdFromClipId(PyDbObjectId& clipId) const
{
    return PyDbObjectId(impObj()->getNonRectVPIdFromClipId(clipId.m_id));
}

bool PyDbLayoutManager::isVpnumClipped1(int index) const
{
    return impObj()->isVpnumClipped(index);
}

bool PyDbLayoutManager::isVpnumClipped2(int index, const PyDbDatabase& pDb) const
{
#ifdef ZRXAPP
    AutoWorkingDatabase autowb(pDb.impObj());
#endif // ZRXAPP
    return impObj()->isVpnumClipped(index, pDb.impObj());
}

int PyDbLayoutManager::countLayouts1() const
{
    return impObj()->countLayouts();
}

int PyDbLayoutManager::countLayouts2(PyDbDatabase& pDb) const
{
#ifdef ZRXAPP
    AutoWorkingDatabase autowb(pDb.impObj());
#endif // ZRXAPP
    return impObj()->countLayouts(pDb.impObj());
}

static boost::python::dict getLayouts(AcDbDatabase* pDb)
{
    PyAutoLockGIL lock;
    boost::python::dict _items;
    if (pDb != nullptr)
    {
        AcDbDictionaryPointer pLayouts(pDb->layoutDictionaryId());
        for (std::unique_ptr<AcDbDictionaryIterator> iter(pLayouts->newIterator()); !iter->done(); iter->next())
        {
            const std::string& utf8name = wstr_to_utf8(iter->name());
            _items[utf8name] = PyDbObjectId(iter->objectId());

        }
    }
    return _items;
}

boost::python::dict PyDbLayoutManager::getLayouts1() const
{
    AcDbDatabase* pDb = acdbHostApplicationServices()->workingDatabase();
    return getLayouts(pDb);
}

boost::python::dict PyDbLayoutManager::getLayouts2(PyDbDatabase& pDb) const
{
#ifdef ZRXAPP
    AutoWorkingDatabase autowb(pDb.impObj());
#endif // ZRXAPP
    return getLayouts(pDb.impObj());
}

Adesk::ULongPtr PyDbLayoutManager::setupForLayouts(PyDbDatabase& pDb)
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    Adesk::ULongPtr contextHandle = 0;
    PyThrowBadEs(acdbDoSetupForLayouts(pDb.impObj(), contextHandle));
    return contextHandle;
#endif
}

void PyDbLayoutManager::clearSetupForLayouts(Adesk::ULongPtr contextHandle)
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(acdbClearSetupForLayouts(contextHandle));
#endif
}

PyRxClass PyDbLayoutManager::desc()
{
    return PyRxClass(AcDbLayoutManager::desc(), false);
}

std::string PyDbLayoutManager::className()
{
    return "AcDbLayoutManager";
}

AcDbLayoutManager* PyDbLayoutManager::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbLayoutManager*>(m_pyImp.get());
}
