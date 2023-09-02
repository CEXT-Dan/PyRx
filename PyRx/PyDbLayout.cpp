#include "stdafx.h"
#include "PyDbLayout.h"
#include "PyDbObjectId.h"

using namespace boost::python;

void makePyDbPlotSettingsWrapper()
{
    class_<PyDbPlotSettings, bases<PyDbObject>>("PlotSettings")
        .def(init<>())
        .def(init<bool>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("addToPlotSettingsDict", &PyDbPlotSettings::addToPlotSettingsDict)
        .def("getPlotSettingsName", &PyDbPlotSettings::getPlotSettingsName)
        .def("setPlotSettingsName", &PyDbPlotSettings::setPlotSettingsName)
        .def("getPlotCfgName", &PyDbPlotSettings::getPlotCfgName)
        .def("getPlotPaperMargins", &PyDbPlotSettings::getPlotPaperMargins)
        .def("getPlotPaperSize", &PyDbPlotSettings::getPlotPaperSize)
        .def("getCanonicalMediaName", &PyDbPlotSettings::getCanonicalMediaName)
        .def("getPlotOrigin", &PyDbPlotSettings::getPlotOrigin)
        .def("plotPaperUnits", &PyDbPlotSettings::plotPaperUnits)
        .def("plotViewportBorders", &PyDbPlotSettings::plotViewportBorders)
        .def("setPlotViewportBorders", &PyDbPlotSettings::setPlotViewportBorders)
        .def("plotTransparency", &PyDbPlotSettings::plotTransparency)
        .def("setPlotTransparency", &PyDbPlotSettings::setPlotTransparency)
        .def("plotPlotStyles", &PyDbPlotSettings::plotPlotStyles)
        .def("setPlotPlotStyles", &PyDbPlotSettings::setPlotPlotStyles)
        .def("showPlotStyles", &PyDbPlotSettings::showPlotStyles)
        .def("setShowPlotStyles", &PyDbPlotSettings::setShowPlotStyles)
        .def("plotRotation", &PyDbPlotSettings::plotRotation)
        .def("plotCentered", &PyDbPlotSettings::plotCentered)
        .def("plotHidden", &PyDbPlotSettings::plotHidden)
        .def("setPlotHidden", &PyDbPlotSettings::setPlotHidden)
        .def("shadePlot", &PyDbPlotSettings::shadePlot)
        .def("shadePlotId", &PyDbPlotSettings::shadePlotId)
        .def("setShadePlot", &PyDbPlotSettings::setShadePlot1)
        .def("setShadePlot", &PyDbPlotSettings::setShadePlot2)
        .def("shadePlotResLevel", &PyDbPlotSettings::shadePlotResLevel)
        .def("setShadePlotResLevel", &PyDbPlotSettings::setShadePlotResLevel)
        .def("shadePlotCustomDPI", &PyDbPlotSettings::shadePlotCustomDPI)
        .def("setShadePlotCustomDPI", &PyDbPlotSettings::setShadePlotCustomDPI)
        .def("plotType", &PyDbPlotSettings::plotType)
        .def("getPlotWindowArea", &PyDbPlotSettings::getPlotWindowArea)
        .def("getPlotViewName", &PyDbPlotSettings::getPlotViewName)
        .def("useStandardScale", &PyDbPlotSettings::useStandardScale)
        .def("getCustomPrintScale", &PyDbPlotSettings::getCustomPrintScale)
        .def("getCurrentStyleSheet", &PyDbPlotSettings::getCurrentStyleSheet)
        .def("stdScaleType", &PyDbPlotSettings::stdScaleType)
        .def("getStdScale", &PyDbPlotSettings::getStdScale)
        .def("scaleLineweights", &PyDbPlotSettings::scaleLineweights)
        .def("setScaleLineweights", &PyDbPlotSettings::setScaleLineweights)
        .def("printLineweights", &PyDbPlotSettings::printLineweights)
        .def("setPrintLineweights", &PyDbPlotSettings::setPrintLineweights)
        .def("drawViewportsFirst", &PyDbPlotSettings::drawViewportsFirst)
        .def("setDrawViewportsFirst", &PyDbPlotSettings::setDrawViewportsFirst)
        .def("modelType", &PyDbPlotSettings::modelType)
        .def("plotWireframe", &PyDbPlotSettings::plotWireframe)
        .def("plotAsRaster", &PyDbPlotSettings::plotAsRaster)
        .def("className", &PyDbPlotSettings::className).staticmethod("className")
        .def("desc", &PyDbPlotSettings::desc).staticmethod("desc")
        .def("cloneFrom", &PyDbPlotSettings::cloneFrom).staticmethod("cloneFrom")
        .def("cast", &PyDbPlotSettings::cast).staticmethod("cast")
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
    : PyDbObject(openAcDbObject<AcDbPlotSettings>(id,mode), false)
{
}

PyDbPlotSettings::PyDbPlotSettings(const PyDbObjectId& id)
    : PyDbPlotSettings(id, AcDb::OpenMode::kForRead)
{
}

PyDbPlotSettings::PyDbPlotSettings(const AcDbPlotSettings* ptr)
    : PyDbObject(ptr)
{
}

void PyDbPlotSettings::addToPlotSettingsDict(PyDbDatabase& towhichDb)
{
    return PyThrowBadEs(impObj()->addToPlotSettingsDict(towhichDb.impObj()));
}

std::string PyDbPlotSettings::getPlotSettingsName() const
{
    const wchar_t* plotSettingsName = nullptr;
    PyThrowBadEs(impObj()->getPlotSettingsName(plotSettingsName));
    return wstr_to_utf8(plotSettingsName);
}

void PyDbPlotSettings::setPlotSettingsName(const std::string& plotSettingsName)
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

void PyDbPlotSettings::setPlotViewportBorders(Adesk::Boolean plotViewportBorders)
{
    impObj()->setPlotViewportBorders(plotViewportBorders);
}

Adesk::Boolean PyDbPlotSettings::plotTransparency() const
{
    return impObj()->plotTransparency();
}

void PyDbPlotSettings::setPlotTransparency(Adesk::Boolean plotTransparency)
{
    impObj()->setPlotTransparency(plotTransparency);
}

Adesk::Boolean PyDbPlotSettings::plotPlotStyles() const
{
    return impObj()->plotPlotStyles();
}

void PyDbPlotSettings::setPlotPlotStyles(Adesk::Boolean plotPlotStyles)
{
    impObj()->setPlotPlotStyles(plotPlotStyles);
}

Adesk::Boolean PyDbPlotSettings::showPlotStyles() const
{
    return impObj()->showPlotStyles();
}

void PyDbPlotSettings::setShowPlotStyles(Adesk::Boolean showPlotStyles)
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

void PyDbPlotSettings::setPlotHidden(Adesk::Boolean plotHidden)
{
    impObj()->setPlotHidden(plotHidden);
}

AcDbPlotSettings::ShadePlotType PyDbPlotSettings::shadePlot() const
{
    return impObj()->shadePlot();
}

void PyDbPlotSettings::setShadePlot1(AcDbPlotSettings::ShadePlotType shadePlot)
{
    return PyThrowBadEs(impObj()->setShadePlot(shadePlot));
}

void PyDbPlotSettings::setShadePlot2(AcDbPlotSettings::ShadePlotType type, const PyDbObjectId& shadePlotId)
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

void PyDbPlotSettings::setShadePlotResLevel(AcDbPlotSettings::ShadePlotResLevel resLevel)
{
    return PyThrowBadEs(impObj()->setShadePlotResLevel(resLevel));
}

Adesk::Int16 PyDbPlotSettings::shadePlotCustomDPI() const
{
    return impObj()->shadePlotCustomDPI();
}

void PyDbPlotSettings::setShadePlotCustomDPI(Adesk::Int16 val)
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

void PyDbPlotSettings::setScaleLineweights(Adesk::Boolean scaleLineweights)
{
    return impObj()->setScaleLineweights(scaleLineweights);
}

Adesk::Boolean PyDbPlotSettings::printLineweights() const
{
    return impObj()->printLineweights();
}

void PyDbPlotSettings::setPrintLineweights(Adesk::Boolean printLineweights)
{
    impObj()->setPrintLineweights(printLineweights);
}

Adesk::Boolean PyDbPlotSettings::drawViewportsFirst() const
{
    return impObj()->drawViewportsFirst();
}

void PyDbPlotSettings::setDrawViewportsFirst(Adesk::Boolean drawViewportsFirst)
{
    impObj()->setDrawViewportsFirst(drawViewportsFirst);
}

Adesk::Boolean PyDbPlotSettings::modelType() const
{
    return impObj()->modelType();
}

PyDbObjectId PyDbPlotSettings::shadePlotId() const
{
    return PyDbObjectId(impObj()->shadePlotId());
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
    if (!src.impObj()->isKindOf(AcDbPlotSettings::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbPlotSettings(static_cast<AcDbPlotSettings*>(src.impObj()->clone()), true);
}

PyDbPlotSettings PyDbPlotSettings::cast(const PyRxObject& src)
{
    PyDbPlotSettings dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

AcDbPlotSettings* PyDbPlotSettings::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]]
        throw PyNullObject(src);
    return static_cast<AcDbPlotSettings*>(m_pyImp.get());
}

//---------------------------------------------------------------------------------------- -
//PyDbLayout
void makePyDbLayoutWrapper()
{
    class_<PyDbLayout, bases<PyDbPlotSettings>>("Layout")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("getBlockTableRecordId", &PyDbLayout::getBlockTableRecordId)
        .def("setBlockTableRecordId", &PyDbLayout::setBlockTableRecordId)
        .def("addToLayoutDict", &PyDbLayout::addToLayoutDict)
        .def("getLayoutName", &PyDbLayout::getLayoutName)
        .def("setLayoutName", &PyDbLayout::setLayoutName)
        .def("getTabOrder", &PyDbLayout::getTabOrder)
        .def("setTabOrder", &PyDbLayout::setTabOrder)
        .def("getTabSelected", &PyDbLayout::getTabSelected)
        .def("setTabSelected", &PyDbLayout::setTabSelected)
        .def("getViewportArray", &PyDbLayout::getViewportArray)
        .def("getLimits", &PyDbLayout::getLimits)
        .def("getExtents", &PyDbLayout::getExtents)
        .def("initialize", &PyDbLayout::initialize1)
        .def("initialize", &PyDbLayout::initialize2)
        .def("annoAllVisible", &PyDbLayout::annoAllVisible)
        .def("setAnnoAllVisible", &PyDbLayout::setAnnoAllVisible)
        .def("className", &PyDbLayout::className).staticmethod("className")
        .def("desc", &PyDbLayout::desc).staticmethod("desc")
        .def("cloneFrom", &PyDbLayout::cloneFrom).staticmethod("cloneFrom")
        .def("cast", &PyDbLayout::cast).staticmethod("cast")
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
    : PyDbPlotSettings(openAcDbObject<AcDbLayout>(id,mode), false)
{
}

PyDbLayout::PyDbLayout(const PyDbObjectId& id)
    : PyDbLayout(id, AcDb::OpenMode::kForRead)
{
}

PyDbObjectId PyDbLayout::getBlockTableRecordId() const
{
    return PyDbObjectId(impObj()->getBlockTableRecordId());
}

void PyDbLayout::setBlockTableRecordId(PyDbObjectId& BlockTableRecordId)
{
    return PyThrowBadEs(impObj()->setBlockTableRecordId(BlockTableRecordId.m_id));
}

void PyDbLayout::addToLayoutDict(PyDbDatabase& towhichDb, PyDbObjectId BlockTableRecordId)
{
    return PyThrowBadEs(impObj()->addToLayoutDict(towhichDb.impObj(), BlockTableRecordId.m_id));
}

std::string PyDbLayout::getLayoutName() const
{
    const ACHAR* layoutName = nullptr;
    PyThrowBadEs(impObj()->getLayoutName(layoutName));
    return wstr_to_utf8(layoutName);
}

void PyDbLayout::setLayoutName(const std::string& layoutName)
{
    return PyThrowBadEs(impObj()->setLayoutName(utf8_to_wstr(layoutName).c_str()));
}

int PyDbLayout::getTabOrder() const
{
    return impObj()->getTabOrder();
}

void PyDbLayout::setTabOrder(int newOrder)
{
    impObj()->setTabOrder(newOrder);
}

bool PyDbLayout::getTabSelected() const
{
    return impObj()->getTabSelected();
}

void PyDbLayout::setTabSelected(Adesk::Boolean tabSelected)
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
    PyAutoLockGIL lock;
    AcGePoint3d extMin;
    AcGePoint3d extMax;
    impObj()->getExtents(extMin, extMax);
    return boost::python::make_tuple(extMin, extMax);
}

void PyDbLayout::initialize1()
{
    return PyThrowBadEs(impObj()->initialize());
}

void PyDbLayout::initialize2(PyDbObjectId& paperVportId)
{
    return PyThrowBadEs(impObj()->initialize(&paperVportId.m_id));
}

bool PyDbLayout::annoAllVisible() const
{
    return impObj()->annoAllVisible();
}

void PyDbLayout::setAnnoAllVisible(bool newVal)
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
    if (!src.impObj()->isKindOf(AcDbLayout::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbLayout(static_cast<AcDbLayout*>(src.impObj()->clone()), true);
}

PyDbLayout PyDbLayout::cast(const PyRxObject& src)
{
    PyDbLayout dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

AcDbLayout* PyDbLayout::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]]
        throw PyNullObject(src);
    return static_cast<AcDbLayout*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
//PyDbLayoutManager
void makePyDbLayoutManagerWrapper()
{
    class_<PyDbLayoutManager, bases<PyRxObject>>("LayoutManager")
        .def("setCurrentLayout", &PyDbLayoutManager::setCurrentLayout1)
        .def("setCurrentLayout", &PyDbLayoutManager::setCurrentLayout2)
        .def("setCurrentLayoutId", &PyDbLayoutManager::setCurrentLayoutId)
        .def("getActiveLayoutName", &PyDbLayoutManager::getActiveLayoutName1)
        .def("getActiveLayoutName", &PyDbLayoutManager::getActiveLayoutName2)
        .def("getActiveLayoutBTRId", &PyDbLayoutManager::getActiveLayoutBTRId1)
        .def("getActiveLayoutBTRId", &PyDbLayoutManager::getActiveLayoutBTRId2)
        .def("findLayoutNamed", &PyDbLayoutManager::findLayoutNamed1)
        .def("findLayoutNamed", &PyDbLayoutManager::findLayoutNamed2)
        .def("layoutExists", &PyDbLayoutManager::layoutExists1)
        .def("layoutExists", &PyDbLayoutManager::layoutExists2)
        .def("copyLayout", &PyDbLayoutManager::copyLayout1)
        .def("copyLayout", &PyDbLayoutManager::copyLayout2)
        .def("deleteLayout", &PyDbLayoutManager::deleteLayout1)
        .def("deleteLayout", &PyDbLayoutManager::deleteLayout2)
        .def("createLayout", &PyDbLayoutManager::createLayout1)
        .def("createLayout", &PyDbLayoutManager::createLayout2)
        .def("renameLayout", &PyDbLayoutManager::renameLayout1)
        .def("renameLayout", &PyDbLayoutManager::renameLayout2)
        .def("cloneLayout", &PyDbLayoutManager::cloneLayout1)
        .def("cloneLayout", &PyDbLayoutManager::cloneLayout2)
        .def("getNonRectVPIdFromClipId", &PyDbLayoutManager::getNonRectVPIdFromClipId)
        .def("isVpnumClipped", &PyDbLayoutManager::isVpnumClipped1)
        .def("isVpnumClipped", &PyDbLayoutManager::isVpnumClipped2)
        .def("countLayouts", &PyDbLayoutManager::countLayouts1)
        .def("countLayouts", &PyDbLayoutManager::countLayouts2)
        .def("setupForLayouts", &PyDbLayoutManager::setupForLayouts).staticmethod("setupForLayouts")
        .def("clearSetupForLayouts", &PyDbLayoutManager::clearSetupForLayouts).staticmethod("clearSetupForLayouts")
        .def("desc", &PyDbLayoutManager::desc).staticmethod("desc")
        .def("className", &PyDbLayoutManager::className).staticmethod("className")
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

void PyDbLayoutManager::setCurrentLayout1(const std::string& newname)
{
    return PyThrowBadEs(impObj()->setCurrentLayout(utf8_to_wstr(newname).c_str()));
}

void PyDbLayoutManager::setCurrentLayout2(const std::string& newname, PyDbDatabase& pDb)
{
    return PyThrowBadEs(impObj()->setCurrentLayout(utf8_to_wstr(newname).c_str(), pDb.impObj()));
}

void PyDbLayoutManager::setCurrentLayoutId(const PyDbObjectId& layoutId)
{
    return PyThrowBadEs(impObj()->setCurrentLayoutId(layoutId.m_id));
}

std::string PyDbLayoutManager::getActiveLayoutName1(bool allowModel)
{
    AcString sName;
    PyThrowBadEs(impObj()->getActiveLayoutName(sName, allowModel));
    return wstr_to_utf8(sName);
}

std::string PyDbLayoutManager::getActiveLayoutName2(bool allowModel, PyDbDatabase& pDb)
{
    AcString sName;
    PyThrowBadEs(impObj()->getActiveLayoutName(sName, allowModel, pDb.impObj()));
    return wstr_to_utf8(sName);
}

PyDbObjectId PyDbLayoutManager::getActiveLayoutBTRId1()
{
    return PyDbObjectId(impObj()->getActiveLayoutBTRId());
}

PyDbObjectId PyDbLayoutManager::getActiveLayoutBTRId2(const PyDbDatabase& pDb)
{
    return PyDbObjectId(impObj()->getActiveLayoutBTRId(pDb.impObj()));
}

PyDbObjectId PyDbLayoutManager::findLayoutNamed1(const std::string& name)
{
    return PyDbObjectId(impObj()->findLayoutNamed(utf8_to_wstr(name).c_str()));
}

PyDbObjectId PyDbLayoutManager::findLayoutNamed2(const std::string& name, const PyDbDatabase& pDb)
{
    return PyDbObjectId(impObj()->findLayoutNamed(utf8_to_wstr(name).c_str(), pDb.impObj()));
}

bool PyDbLayoutManager::layoutExists1(const std::string& name)
{
    return impObj()->layoutExists(utf8_to_wstr(name).c_str());
}

bool PyDbLayoutManager::layoutExists2(const std::string& name, const PyDbDatabase& pDb)
{
    return impObj()->layoutExists(utf8_to_wstr(name).c_str(), pDb.impObj());
}

void PyDbLayoutManager::copyLayout1(const std::string& copyname, const std::string& newname)
{
    return PyThrowBadEs(impObj()->copyLayout(utf8_to_wstr(copyname).c_str(), utf8_to_wstr(newname).c_str()));
}

void PyDbLayoutManager::copyLayout2(const std::string& copyname, const std::string& newname, const PyDbDatabase& pDb)
{
    return PyThrowBadEs(impObj()->copyLayout(utf8_to_wstr(copyname).c_str(), utf8_to_wstr(newname).c_str(), pDb.impObj()));
}

void PyDbLayoutManager::deleteLayout1(const std::string& delname)
{
    return PyThrowBadEs(impObj()->deleteLayout(utf8_to_wstr(delname).c_str()));
}

void PyDbLayoutManager::deleteLayout2(const std::string& delname, PyDbDatabase& pDb)
{
    return PyThrowBadEs(impObj()->deleteLayout(utf8_to_wstr(delname).c_str(), pDb.impObj()));
}

void PyDbLayoutManager::createLayout1(const std::string& newname, PyDbObjectId& layoutId, PyDbObjectId& blockTableRecId)
{
    return PyThrowBadEs(impObj()->createLayout(utf8_to_wstr(newname).c_str(), layoutId.m_id, blockTableRecId.m_id));
}

void PyDbLayoutManager::createLayout2(const std::string& newname, PyDbObjectId& layoutId, PyDbObjectId& blockTableRecId, PyDbDatabase& pDb)
{
    return PyThrowBadEs(impObj()->createLayout(utf8_to_wstr(newname).c_str(), layoutId.m_id, blockTableRecId.m_id, pDb.impObj()));
}

void PyDbLayoutManager::renameLayout1(const std::string& oldname, const std::string& newname)
{
    return PyThrowBadEs(impObj()->renameLayout(utf8_to_wstr(oldname).c_str(), utf8_to_wstr(newname).c_str()));
}

void PyDbLayoutManager::renameLayout2(const std::string& oldname, const std::string& newname, PyDbDatabase& pDb)
{
    return PyThrowBadEs(impObj()->renameLayout(utf8_to_wstr(oldname).c_str(), utf8_to_wstr(newname).c_str(), pDb.impObj()));
}

void PyDbLayoutManager::cloneLayout1(PyDbLayout& pLBTR, const std::string& newname)
{
    return PyThrowBadEs(impObj()->cloneLayout(pLBTR.impObj(), utf8_to_wstr(newname).c_str()));
}

void PyDbLayoutManager::cloneLayout2(PyDbLayout& pLBTR, const std::string& newname, int newTabOrder, PyDbDatabase& pDb)
{
    return PyThrowBadEs(impObj()->cloneLayout(pLBTR.impObj(), utf8_to_wstr(newname).c_str(), newTabOrder, pDb.impObj()));
}

PyDbObjectId PyDbLayoutManager::getNonRectVPIdFromClipId(PyDbObjectId& clipId)
{
    return PyDbObjectId(impObj()->getNonRectVPIdFromClipId(clipId.m_id));
}

bool PyDbLayoutManager::isVpnumClipped1(int index)
{
    return impObj()->isVpnumClipped(index);
}

bool PyDbLayoutManager::isVpnumClipped2(int index, const PyDbDatabase& pDb)
{
    return impObj()->isVpnumClipped(index, pDb.impObj());
}

int PyDbLayoutManager::countLayouts1()
{
    return impObj()->countLayouts();
}

int PyDbLayoutManager::countLayouts2(PyDbDatabase& pDb)
{
    return impObj()->countLayouts(pDb.impObj());
}

Adesk::ULongPtr PyDbLayoutManager::setupForLayouts(PyDbDatabase& pDb)
{
    Adesk::ULongPtr contextHandle = 0;
    PyThrowBadEs(acdbDoSetupForLayouts(pDb.impObj(), contextHandle));
    return contextHandle;
}

void PyDbLayoutManager::clearSetupForLayouts(Adesk::ULongPtr contextHandle)
{
    return PyThrowBadEs(acdbClearSetupForLayouts(contextHandle));
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
    if (m_pyImp == nullptr) [[unlikely]]
        throw PyNullObject(src);
    return static_cast<AcDbLayoutManager*>(m_pyImp.get());
}
