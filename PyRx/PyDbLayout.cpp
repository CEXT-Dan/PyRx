#include "stdafx.h"
#include "PyDbLayout.h"
#include "PyDbObjectId.h"

using namespace boost::python;

void makePyDbPlotSettingsWrapper()
{
    class_<PyDbPlotSettings, bases<PyDbObject>>("PlotSettings")
        .def(init<>())
        .def(init<bool>())
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
    : PyDbObject(nullptr, false)
{
    AcDbPlotSettings* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbPlotSettings>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    this->resetImp(pobj, false, true);
}

Acad::ErrorStatus PyDbPlotSettings::addToPlotSettingsDict(PyDbDatabase& towhichDb)
{
    return impObj()->addToPlotSettingsDict(towhichDb.impObj());
}

std::string PyDbPlotSettings::getPlotSettingsName() const
{
    const wchar_t* plotSettingsName = nullptr;
    if (auto es = impObj()->getPlotSettingsName(plotSettingsName); es != eOk)
        throw PyAcadErrorStatus(es);
    return wstr_to_utf8(plotSettingsName);
}

Acad::ErrorStatus PyDbPlotSettings::setPlotSettingsName(const std::string& plotSettingsName)
{
    return impObj()->setPlotSettingsName(utf8_to_wstr(plotSettingsName).c_str());
}

std::string PyDbPlotSettings::getPlotCfgName() const
{
    const wchar_t* plotCfgName = nullptr;
    if (auto es = impObj()->getPlotCfgName(plotCfgName); es != eOk)
        throw PyAcadErrorStatus(es);
    return wstr_to_utf8(plotCfgName);
}

boost::python::tuple PyDbPlotSettings::getPlotPaperMargins() const
{
    PyAutoLockGIL lock;
    double printableXmin = 0;
    double printableYmin = 0;
    double printableXmax = 0;
    double printableYmax = 0;
    if (auto es = impObj()->getPlotPaperMargins(printableXmin, printableYmin, printableXmax, printableYmax); es != eOk)
        throw PyAcadErrorStatus(es);
    return boost::python::make_tuple(printableXmin, printableYmin, printableXmax, printableYmax);
}

boost::python::tuple PyDbPlotSettings::getPlotPaperSize() const
{
    PyAutoLockGIL lock;
    double paperWidth = 0;
    double paperHeight = 0;
    if (auto es = impObj()->getPlotPaperSize(paperWidth, paperHeight); es != eOk)
        throw PyAcadErrorStatus(es);
    return boost::python::make_tuple(paperWidth, paperHeight);
}

std::string PyDbPlotSettings::getCanonicalMediaName() const
{
    const wchar_t* mediaName = nullptr;
    if (auto es = impObj()->getCanonicalMediaName(mediaName); es != eOk)
        throw PyAcadErrorStatus(es);
    return wstr_to_utf8(mediaName);
}

boost::python::tuple PyDbPlotSettings::getPlotOrigin() const
{
    PyAutoLockGIL lock;
    double x = 0;
    double y = 0;
    if (auto es = impObj()->getPlotOrigin(x, y); es != eOk)
        throw PyAcadErrorStatus(es);
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
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->plotTransparency();
#endif
}

void PyDbPlotSettings::setPlotTransparency(Adesk::Boolean plotTransparency)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    impObj()->setPlotTransparency(plotTransparency);
#endif
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
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->shadePlot();
#endif
}

Acad::ErrorStatus PyDbPlotSettings::setShadePlot1(AcDbPlotSettings::ShadePlotType shadePlot)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setShadePlot(shadePlot);
#endif
}

Acad::ErrorStatus PyDbPlotSettings::setShadePlot2(AcDbPlotSettings::ShadePlotType type, const PyDbObjectId& shadePlotId)
{
    return impObj()->setShadePlot(type, shadePlotId.m_id);
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

Acad::ErrorStatus PyDbPlotSettings::setShadePlotResLevel(AcDbPlotSettings::ShadePlotResLevel resLevel)
{
    return impObj()->setShadePlotResLevel(resLevel);
}

Adesk::Int16 PyDbPlotSettings::shadePlotCustomDPI() const
{
    return impObj()->shadePlotCustomDPI();
}

Acad::ErrorStatus PyDbPlotSettings::setShadePlotCustomDPI(Adesk::Int16 val)
{
    return impObj()->setShadePlotCustomDPI(val);
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
    if (auto es = impObj()->getPlotWindowArea(printableXmin, printableYmin, printableXmax, printableYmax); es != eOk)
        throw PyAcadErrorStatus(es);
    return boost::python::make_tuple(printableXmin, printableYmin, printableXmax, printableYmax);
}

std::string PyDbPlotSettings::getPlotViewName() const
{
    const ACHAR* viewName = nullptr;
    if (auto es = impObj()->getPlotViewName(viewName); es != eOk)
        throw PyAcadErrorStatus(es);
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
    if (auto es = impObj()->getCustomPrintScale(x, y); es != eOk)
        throw PyAcadErrorStatus(es);
    return boost::python::make_tuple(x, y);
}

std::string PyDbPlotSettings::getCurrentStyleSheet() const
{
    const ACHAR* styleSheetName = nullptr;
    if (auto es = impObj()->getCurrentStyleSheet(styleSheetName); es != eOk)
        throw PyAcadErrorStatus(es);
    return wstr_to_utf8(styleSheetName);
}

AcDbPlotSettings::StdScaleType PyDbPlotSettings::stdScaleType() const
{
    return impObj()->stdScaleType();
}

double PyDbPlotSettings::getStdScale() const
{
    double scale = 0;
    if (auto es = impObj()->getStdScale(scale); es != eOk)
        throw PyAcadErrorStatus(es);
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
#ifdef BRXAPP
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
    if (m_pyImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcDbPlotSettings*>(m_pyImp.get());
}

//---------------------------------------------------------------------------------------- -
//PyDbLayout
void makePyDbLayoutWrapper()
{
    class_<PyDbLayout, bases<PyDbPlotSettings>>("Layout")
        .def(init<>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
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
{
    AcDbLayout* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbLayout>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    this->resetImp(pobj, false, true);
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
    if (m_pyImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcDbLayout*>(m_pyImp.get());
}
