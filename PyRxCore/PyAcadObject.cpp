#include "stdafx.h"
#include "PyAcadObject.h"
#include "PyAcadObjectImpl.h"
#include "PyDbEval.h"
#include "PyAcadApplication.h"
#include "PyAcadApplicationImpl.h"

using namespace boost::python;

//----------------------------------------------------------------------------------------
//PyAcadAcCmColor
void makePyAcadAcCmColorWrapper()
{
    constexpr const std::string_view initOverloads = "Overloads:\n"
        "- None: Any\n"
        "- r: int, g: int, b: int\n";

    PyDocString DS("AcadAcCmColor");
    class_<PyAcadAcCmColor>("AcadAcCmColor")
        .def(init<>())
        .def(init<Adesk::UInt8, Adesk::UInt8, Adesk::UInt8>(DS.CTOR(initOverloads)))
        .def("setEntityColor", &PyAcadAcCmColor::setEntityColor, DS.ARGS({ "val:int" }))
        .def("entityColor", &PyAcadAcCmColor::entityColor, DS.ARGS())
        .def("colorName", &PyAcadAcCmColor::colorName, DS.ARGS())
        .def("bookName", &PyAcadAcCmColor::bookName, DS.ARGS())
        .def("setNames", &PyAcadAcCmColor::setNames, DS.ARGS({ "colorName:str","bookName:str" }))
        .def("clear", &PyAcadAcCmColor::clear, DS.ARGS())
        .def("red", &PyAcadAcCmColor::red, DS.ARGS())
        .def("green", &PyAcadAcCmColor::green, DS.ARGS())
        .def("blue", &PyAcadAcCmColor::blue, DS.ARGS())
        .def("setRGB", &PyAcadAcCmColor::setRGB, DS.ARGS({ "red:int", "green:int", "blue:int" }))
        .def("colorMethod", &PyAcadAcCmColor::colorMethod, DS.ARGS())
        .def("setColorMethod", &PyAcadAcCmColor::setColorMethod, DS.ARGS({ "flags:PyAx.AcColorMethod" }))
        .def("colorIndex", &PyAcadAcCmColor::colorIndex, DS.ARGS())
        .def("setColorIndex", &PyAcadAcCmColor::setColorIndex, DS.ARGS({ "flags:PyAx.AcColor" }))
        .def("setColorBookColor", &PyAcadAcCmColor::setColorBookColor, DS.ARGS({ "colorName:str","bookName:str" }))
        .def("className", &PyAcadAcCmColor::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadAcCmColor::PyAcadAcCmColor()
    : m_pyImp(PyIAcadAcCmColorImpl::CreateInstance())
{
}

PyAcadAcCmColor::PyAcadAcCmColor(Adesk::UInt8 r, Adesk::UInt8 g, Adesk::UInt8 b)
    : m_pyImp(PyIAcadAcCmColorImpl::CreateInstance())
{
    this->setRGB(r, g, b);
}

PyAcadAcCmColor::PyAcadAcCmColor(std::shared_ptr<PyIAcadAcCmColorImpl> ptr)
    : m_pyImp(ptr)
{
}

void PyAcadAcCmColor::setEntityColor(long val) const
{
    impObj()->SetEntityColor(val);
}

long PyAcadAcCmColor::entityColor() const
{
    return impObj()->GetEntityColor();
}

std::string PyAcadAcCmColor::colorName() const
{
    return wstr_to_utf8(impObj()->GetColorName());
}

std::string PyAcadAcCmColor::bookName() const
{
    return wstr_to_utf8(impObj()->GetBookName());
}

void PyAcadAcCmColor::setNames(const std::string& colorName, const std::string& bookName) const
{
    impObj()->SetNames(utf8_to_wstr(colorName).c_str(), utf8_to_wstr(bookName).c_str());
}

void PyAcadAcCmColor::clear() const
{
    impObj()->Delete();
}

long PyAcadAcCmColor::red() const
{
    return impObj()->GetRed();
}

long PyAcadAcCmColor::green() const
{
    return impObj()->GetGreen();
}

long PyAcadAcCmColor::blue() const
{
    return impObj()->GetBlue();
}

void PyAcadAcCmColor::setRGB(long red, long green, long blue) const
{
    impObj()->SetRGB(red, green, blue);
}

PyAcColorMethod PyAcadAcCmColor::colorMethod() const
{
    return impObj()->GetColorMethod();
}

void PyAcadAcCmColor::setColorMethod(PyAcColorMethod flags) const
{
    impObj()->SetColorMethod(flags);
}

PyAcColor PyAcadAcCmColor::colorIndex() const
{
    return impObj()->GetColorIndex();
}

void PyAcadAcCmColor::setColorIndex(PyAcColor val) const
{
    impObj()->SetColorIndex(val);
}

void PyAcadAcCmColor::setColorBookColor(const std::string& colorName, const std::string& bookName) const
{
    impObj()->SetColorBookColor(utf8_to_wstr(colorName).c_str(), utf8_to_wstr(bookName).c_str());
}

std::string PyAcadAcCmColor::className()
{
    return "AcadAcCmColor";
}

PyIAcadAcCmColorImpl* PyAcadAcCmColor::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return m_pyImp.get();
}

//----------------------------------------------------------------------------------------
//PyAcadHyperlink
void makePyAcadHyperlinkWrapper()
{
    PyDocString DS("AcadHyperlink");
    class_<PyAcadHyperlink>("AcadHyperlink", boost::python::no_init)
        .def("url", &PyAcadHyperlink::url, DS.ARGS())
        .def("setURL", &PyAcadHyperlink::setURL, DS.ARGS({ "url_val:str" }))
        .def("urlDescription", &PyAcadHyperlink::urlDescription, DS.ARGS())
        .def("setURLDescription", &PyAcadHyperlink::setURLDescription, DS.ARGS({ "description:str" }))
        .def("clear", &PyAcadHyperlink::clear, DS.ARGS())
        .def("urlNamedLocation", &PyAcadHyperlink::urlNamedLocation, DS.ARGS())
        .def("setURLNamedLocation", &PyAcadHyperlink::setURLNamedLocation, DS.ARGS({ "named_location:str" }))
        .def("className", &PyAcadHyperlink::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadHyperlink::PyAcadHyperlink(std::shared_ptr<PyIAcadHyperlinkImpl> ptr)
    : m_pyImp(ptr)
{
}

std::string PyAcadHyperlink::url() const
{
    return wstr_to_utf8(impObj()->GetURL());
}

void PyAcadHyperlink::setURL(const std::string& val) const
{
    impObj()->SetURL(utf8_to_wstr(val).c_str());
}

std::string PyAcadHyperlink::urlDescription() const
{
    return wstr_to_utf8(impObj()->GetURLDescription());
}

void PyAcadHyperlink::setURLDescription(const std::string& val) const
{
    impObj()->SetURLDescription(utf8_to_wstr(val).c_str());
}

void PyAcadHyperlink::clear() const
{
    impObj()->Delete();
}

std::string PyAcadHyperlink::urlNamedLocation() const
{
    return wstr_to_utf8(impObj()->GetURLNamedLocation());
}

void PyAcadHyperlink::setURLNamedLocation(const std::string& val) const
{
    impObj()->SetURLNamedLocation(utf8_to_wstr(val).c_str());
}

std::string PyAcadHyperlink::className()
{
    return "AcadHyperlink";
}

PyIAcadHyperlinkImpl* PyAcadHyperlink::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return m_pyImp.get();
}

//----------------------------------------------------------------------------------------
//PyAcadHyperlinks
void makePyAcadHyperlinksWrapper()
{
    PyDocString DS("AcadHyperlinks");
    class_<PyAcadHyperlinks>("AcadHyperlinks", boost::python::no_init)
        .def("count", &PyAcadHyperlinks::count, DS.ARGS())
        .def("item", &PyAcadHyperlinks::item, DS.ARGS({ "index: int" }))
        .def("add", &PyAcadHyperlinks::add, DS.ARGS({ "name: str", "description: str","namedLocation: str" }))
        .def("__getitem__", &PyAcadHyperlinks::item, DS.ARGS({ "index: int" }))
        .def("className", &PyAcadHyperlinks::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadHyperlinks::PyAcadHyperlinks(std::shared_ptr<PyIAcadHyperlinksImpl> ptr)
    : m_pyImp(ptr)
{
}

PyAcadHyperlink PyAcadHyperlinks::item(long val) const
{
    if (val >= count())
        throw std::out_of_range{ "IndexError " };
    return PyAcadHyperlink{ impObj()->GetItem(val) };
}

long PyAcadHyperlinks::count() const
{
    return impObj()->GetCount();
}

PyAcadHyperlink PyAcadHyperlinks::add(const std::string& name, const std::string& description, const std::string& namedLocation) const
{
    return PyAcadHyperlink(impObj()->Add(utf8_to_wstr(name).c_str(), utf8_to_wstr(description).c_str(), utf8_to_wstr(namedLocation).c_str()));
}

std::string PyAcadHyperlinks::className()
{
    return "AcadHyperlinks";
}

PyIAcadHyperlinksImpl* PyAcadHyperlinks::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return m_pyImp.get();
}

//----------------------------------------------------------------------------------------
//PyAcadSectionTypeSettings
void makePyAcadSectionTypeSettingsWrapper()
{
    PyDocString DS("AcadSectionTypeSettings");
    class_<PyAcadSectionTypeSettings>("AcadSectionTypeSettings", boost::python::no_init)
        .def("generationOptions", &PyAcadSectionTypeSettings::generationOptions, DS.ARGS())
        .def("setGenerationOptions", &PyAcadSectionTypeSettings::setGenerationOptions, DS.ARGS({ "val:PyAx.AcSectionGeneration" }))
        .def("sourceObjects", &PyAcadSectionTypeSettings::sourceObjects, DS.ARGS())
        .def("setSourceObjects", &PyAcadSectionTypeSettings::setSourceObjects, DS.ARGS({ "ids:list[PyDb.ObjectId]" }))
        .def("destinationBlock", &PyAcadSectionTypeSettings::destinationBlock, DS.ARGS())
        .def("setDestinationBlock", &PyAcadSectionTypeSettings::setDestinationBlock, DS.ARGS({ "val:PyAx.AcadBlock" }))
        .def("destinationFile", &PyAcadSectionTypeSettings::destinationFile, DS.ARGS())
        .def("setDestinationFile", &PyAcadSectionTypeSettings::setDestinationFile, DS.ARGS({ "val:str" }))
        .def("intersectionBoundaryColor", &PyAcadSectionTypeSettings::intersectionBoundaryColor, DS.ARGS())
        .def("setIntersectionBoundaryColor", &PyAcadSectionTypeSettings::setIntersectionBoundaryColor, DS.ARGS({ "val:PyAx.AcadAcCmColor" }))
        .def("intersectionBoundaryLayer", &PyAcadSectionTypeSettings::intersectionBoundaryLayer, DS.ARGS())
        .def("setIntersectionBoundaryLayer", &PyAcadSectionTypeSettings::setIntersectionBoundaryLayer, DS.ARGS({ "val:str" }))
        .def("intersectionBoundaryLinetype", &PyAcadSectionTypeSettings::intersectionBoundaryLinetype, DS.ARGS())
        .def("setIntersectionBoundaryLinetype", &PyAcadSectionTypeSettings::setIntersectionBoundaryLinetype, DS.ARGS({ "val:str" }))
        .def("intersectionBoundaryLinetypeScale", &PyAcadSectionTypeSettings::intersectionBoundaryLinetypeScale, DS.ARGS())
        .def("setIntersectionBoundaryLinetypeScale", &PyAcadSectionTypeSettings::setIntersectionBoundaryLinetypeScale, DS.ARGS({ "val:float" }))
        .def("intersectionBoundaryPlotStyleName", &PyAcadSectionTypeSettings::intersectionBoundaryPlotStyleName, DS.ARGS())
        .def("setIntersectionBoundaryPlotStyleName", &PyAcadSectionTypeSettings::setIntersectionBoundaryPlotStyleName, DS.ARGS({ "val:str" }))
        .def("intersectionBoundaryLineweight", &PyAcadSectionTypeSettings::intersectionBoundaryLineweight, DS.ARGS())
        .def("setIntersectionBoundaryLineweight", &PyAcadSectionTypeSettings::setIntersectionBoundaryLineweight, DS.ARGS({ "val:PyAx.AcLineWeight" }))
        .def("intersectionBoundaryDivisionLines", &PyAcadSectionTypeSettings::intersectionBoundaryDivisionLines, DS.ARGS())
        .def("setIntersectionBoundaryDivisionLines", &PyAcadSectionTypeSettings::setIntersectionBoundaryDivisionLines, DS.ARGS({ "val:bool" }))
        .def("intersectionFillVisible", &PyAcadSectionTypeSettings::intersectionFillVisible, DS.ARGS())
        .def("setIntersectionFillVisible", &PyAcadSectionTypeSettings::setIntersectionFillVisible, DS.ARGS({ "val:bool" }))
        .def("intersectionFillHatchPatternType", &PyAcadSectionTypeSettings::intersectionFillHatchPatternType, DS.ARGS())
        .def("setIntersectionFillHatchPatternType", &PyAcadSectionTypeSettings::setIntersectionFillHatchPatternType, DS.ARGS({ "val:PyAx.AcPatternType" }))
        .def("intersectionFillHatchPatternName", &PyAcadSectionTypeSettings::intersectionFillHatchPatternName, DS.ARGS())
        .def("setIntersectionFillHatchPatternName", &PyAcadSectionTypeSettings::setIntersectionFillHatchPatternName, DS.ARGS({ "val:str" }))
        .def("intersectionFillHatchAngle", &PyAcadSectionTypeSettings::intersectionFillHatchAngle, DS.ARGS())
        .def("setIntersectionFillHatchAngle", &PyAcadSectionTypeSettings::setIntersectionFillHatchAngle, DS.ARGS({ "val:float" }))
        .def("intersectionFillHatchScale", &PyAcadSectionTypeSettings::intersectionFillHatchScale, DS.ARGS())
        .def("setIntersectionFillHatchScale", &PyAcadSectionTypeSettings::setIntersectionFillHatchScale, DS.ARGS({ "val:float" }))
        .def("intersectionFillHatchSpacing", &PyAcadSectionTypeSettings::intersectionFillHatchSpacing, DS.ARGS())
        .def("setIntersectionFillHatchSpacing", &PyAcadSectionTypeSettings::setIntersectionFillHatchSpacing, DS.ARGS({ "val:float" }))
        .def("intersectionFillColor", &PyAcadSectionTypeSettings::intersectionFillColor, DS.ARGS())
        .def("setIntersectionFillColor", &PyAcadSectionTypeSettings::setIntersectionFillColor, DS.ARGS({ "val:PyAx.AcadAcCmColor" }))
        .def("intersectionFillLayer", &PyAcadSectionTypeSettings::intersectionFillLayer, DS.ARGS())
        .def("setIntersectionFillLayer", &PyAcadSectionTypeSettings::setIntersectionFillLayer, DS.ARGS({ "val:str" }))
        .def("intersectionFillLinetype", &PyAcadSectionTypeSettings::intersectionFillLinetype, DS.ARGS())
        .def("setIntersectionFillLinetype", &PyAcadSectionTypeSettings::setIntersectionFillLinetype, DS.ARGS({ "val:str" }))
        .def("intersectionFillLinetypeScale", &PyAcadSectionTypeSettings::intersectionFillLinetypeScale, DS.ARGS())
        .def("setIntersectionFillLinetypeScale", &PyAcadSectionTypeSettings::setIntersectionFillLinetypeScale, DS.ARGS({ "val:float" }))
        .def("intersectionFillPlotStyleName", &PyAcadSectionTypeSettings::intersectionFillPlotStyleName, DS.ARGS())
        .def("setIntersectionFillPlotStyleName", &PyAcadSectionTypeSettings::setIntersectionFillPlotStyleName, DS.ARGS({ "val:str" }))
        .def("intersectionFillLineweight", &PyAcadSectionTypeSettings::intersectionFillLineweight, DS.ARGS())
        .def("setIntersectionFillLineweight", &PyAcadSectionTypeSettings::setIntersectionFillLineweight, DS.ARGS({ "val:PyAx.AcLineWeight" }))
        .def("intersectionFillFaceTransparency", &PyAcadSectionTypeSettings::intersectionFillFaceTransparency, DS.ARGS())
        .def("setIntersectionFillFaceTransparency", &PyAcadSectionTypeSettings::setIntersectionFillFaceTransparency, DS.ARGS({ "val:int" }))
        .def("backgroundLinesVisible", &PyAcadSectionTypeSettings::backgroundLinesVisible, DS.ARGS())
        .def("setBackgroundLinesVisible", &PyAcadSectionTypeSettings::setBackgroundLinesVisible, DS.ARGS({ "val:bool" }))
        .def("backgroundLinesHiddenLine", &PyAcadSectionTypeSettings::backgroundLinesHiddenLine, DS.ARGS())
        .def("setBackgroundLinesHiddenLine", &PyAcadSectionTypeSettings::setBackgroundLinesHiddenLine, DS.ARGS({ "val:bool" }))
        .def("backgroundLinesColor", &PyAcadSectionTypeSettings::backgroundLinesColor, DS.ARGS())
        .def("setBackgroundLinesColor", &PyAcadSectionTypeSettings::setBackgroundLinesColor, DS.ARGS({ "val:PyAx.AcadAcCmColor" }))
        .def("backgroundLinesLayer", &PyAcadSectionTypeSettings::backgroundLinesLayer, DS.ARGS())
        .def("setBackgroundLinesLayer", &PyAcadSectionTypeSettings::setBackgroundLinesLayer, DS.ARGS({ "val:str" }))
        .def("backgroundLinesLinetype", &PyAcadSectionTypeSettings::backgroundLinesLinetype, DS.ARGS())
        .def("setBackgroundLinesLinetype", &PyAcadSectionTypeSettings::setBackgroundLinesLinetype, DS.ARGS({ "val:str" }))
        .def("backgroundLinesLinetypeScale", &PyAcadSectionTypeSettings::backgroundLinesLinetypeScale, DS.ARGS())
        .def("setBackgroundLinesLinetypeScale", &PyAcadSectionTypeSettings::setBackgroundLinesLinetypeScale, DS.ARGS({ "val:float" }))
        .def("backgroundLinesPlotStyleName", &PyAcadSectionTypeSettings::backgroundLinesPlotStyleName, DS.ARGS())
        .def("setBackgroundLinesPlotStyleName", &PyAcadSectionTypeSettings::setBackgroundLinesPlotStyleName, DS.ARGS({ "val:str" }))
        .def("backgroundLinesLineweight", &PyAcadSectionTypeSettings::backgroundLinesLineweight, DS.ARGS())
        .def("setBackgroundLinesLineweight", &PyAcadSectionTypeSettings::setBackgroundLinesLineweight, DS.ARGS({ "val:PyAx.AcLineWeight" }))
        .def("foregroundLinesVisible", &PyAcadSectionTypeSettings::foregroundLinesVisible, DS.ARGS())
        .def("setForegroundLinesVisible", &PyAcadSectionTypeSettings::setForegroundLinesVisible, DS.ARGS({ "val:bool" }))
        .def("foregroundLinesHiddenLine", &PyAcadSectionTypeSettings::foregroundLinesHiddenLine, DS.ARGS())
        .def("setForegroundLinesHiddenLine", &PyAcadSectionTypeSettings::setForegroundLinesHiddenLine, DS.ARGS({ "val:bool" }))
        .def("foregroundLinesColor", &PyAcadSectionTypeSettings::foregroundLinesColor, DS.ARGS())
        .def("setForegroundLinesColor", &PyAcadSectionTypeSettings::setForegroundLinesColor, DS.ARGS({ "val:PyAx.AcadAcCmColor" }))
        .def("foregroundLinesLayer", &PyAcadSectionTypeSettings::foregroundLinesLayer, DS.ARGS())
        .def("setForegroundLinesLayer", &PyAcadSectionTypeSettings::setForegroundLinesLayer, DS.ARGS({ "val:str" }))
        .def("foregroundLinesLinetype", &PyAcadSectionTypeSettings::foregroundLinesLinetype, DS.ARGS())
        .def("setForegroundLinesLinetype", &PyAcadSectionTypeSettings::setForegroundLinesLinetype, DS.ARGS({ "val:str" }))
        .def("foregroundLinesLinetypeScale", &PyAcadSectionTypeSettings::foregroundLinesLinetypeScale, DS.ARGS())
        .def("setForegroundLinesLinetypeScale", &PyAcadSectionTypeSettings::setForegroundLinesLinetypeScale, DS.ARGS({ "val:float" }))
        .def("foregroundLinesPlotStyleName", &PyAcadSectionTypeSettings::foregroundLinesPlotStyleName, DS.ARGS())
        .def("setForegroundLinesPlotStyleName", &PyAcadSectionTypeSettings::setForegroundLinesPlotStyleName, DS.ARGS({ "val:str" }))
        .def("foregroundLinesLineweight", &PyAcadSectionTypeSettings::foregroundLinesLineweight, DS.ARGS())
        .def("setForegroundLinesLineweight", &PyAcadSectionTypeSettings::setForegroundLinesLineweight, DS.ARGS({ "val:PyAx.AcLineWeight" }))
        .def("foregroundLinesFaceTransparency", &PyAcadSectionTypeSettings::foregroundLinesFaceTransparency, DS.ARGS())
        .def("setForegroundLinesFaceTransparency", &PyAcadSectionTypeSettings::setForegroundLinesFaceTransparency, DS.ARGS({ "val:int" }))
        .def("foregroundLinesEdgeTransparency", &PyAcadSectionTypeSettings::foregroundLinesEdgeTransparency, DS.ARGS())
        .def("setForegroundLinesEdgeTransparency", &PyAcadSectionTypeSettings::setForegroundLinesEdgeTransparency, DS.ARGS({ "val:int" }))
        .def("curveTangencyLinesVisible", &PyAcadSectionTypeSettings::curveTangencyLinesVisible, DS.ARGS())
        .def("setCurveTangencyLinesVisible", &PyAcadSectionTypeSettings::setCurveTangencyLinesVisible, DS.ARGS({ "val:bool" }))
        .def("curveTangencyLinesColor", &PyAcadSectionTypeSettings::curveTangencyLinesColor, DS.ARGS())
        .def("setCurveTangencyLinesColor", &PyAcadSectionTypeSettings::setCurveTangencyLinesColor, DS.ARGS({ "val:PyAx.AcadAcCmColor" }))
        .def("curveTangencyLinesLayer", &PyAcadSectionTypeSettings::curveTangencyLinesLayer, DS.ARGS())
        .def("setCurveTangencyLinesLayer", &PyAcadSectionTypeSettings::setCurveTangencyLinesLayer, DS.ARGS({ "val:str" }))
        .def("curveTangencyLinesLinetype", &PyAcadSectionTypeSettings::curveTangencyLinesLinetype, DS.ARGS())
        .def("setCurveTangencyLinesLinetype", &PyAcadSectionTypeSettings::setCurveTangencyLinesLinetype, DS.ARGS({ "val:str" }))
        .def("curveTangencyLinesLinetypeScale", &PyAcadSectionTypeSettings::curveTangencyLinesLinetypeScale, DS.ARGS())
        .def("setCurveTangencyLinesLinetypeScale", &PyAcadSectionTypeSettings::setCurveTangencyLinesLinetypeScale, DS.ARGS({ "val:float" }))
        .def("curveTangencyLinesPlotStyleName", &PyAcadSectionTypeSettings::curveTangencyLinesPlotStyleName, DS.ARGS())
        .def("setCurveTangencyLinesPlotStyleName", &PyAcadSectionTypeSettings::setCurveTangencyLinesPlotStyleName, DS.ARGS({ "val:str" }))
        .def("curveTangencyLinesLineweight", &PyAcadSectionTypeSettings::curveTangencyLinesLineweight, DS.ARGS())
        .def("setCurveTangencyLinesLineweight", &PyAcadSectionTypeSettings::setCurveTangencyLinesLineweight, DS.ARGS({ "val:PyAx.AcLineWeight" }))
        .def("className", &PyAcadSectionTypeSettings::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadSectionTypeSettings::PyAcadSectionTypeSettings(std::shared_ptr<PyIAcadSectionTypeSettingsImpl> ptr)
    : m_pyImp(ptr)
{
}

PyAcSectionGeneration PyAcadSectionTypeSettings::generationOptions() const
{
    return impObj()->GetGenerationOptions();
}

void PyAcadSectionTypeSettings::setGenerationOptions(PyAcSectionGeneration val) const
{
    impObj()->SetGenerationOptions(val);
}

boost::python::list PyAcadSectionTypeSettings::sourceObjects() const
{
    return ObjectIdArrayToPyList(impObj()->GetSourceObjects());
}

void PyAcadSectionTypeSettings::setSourceObjects(const boost::python::list& ids) const
{
    impObj()->SetSourceObjects(PyListToObjectIdArray(ids));
}

PyAcadBlock PyAcadSectionTypeSettings::destinationBlock() const
{
    return PyAcadBlock{ impObj()->GetDestinationBlock() };
}

void PyAcadSectionTypeSettings::setDestinationBlock(const PyAcadBlock& val) const
{
    impObj()->SetDestinationBlock(*val.impObj());
}

std::string PyAcadSectionTypeSettings::destinationFile() const
{
    return wstr_to_utf8(impObj()->GetDestinationFile());
}

void PyAcadSectionTypeSettings::setDestinationFile(const std::string& val) const
{
    impObj()->SetDestinationFile(utf8_to_wstr(val).c_str());
}

PyAcadAcCmColor PyAcadSectionTypeSettings::intersectionBoundaryColor() const
{
    return PyAcadAcCmColor(impObj()->GetIntersectionBoundaryColor());
}

void PyAcadSectionTypeSettings::setIntersectionBoundaryColor(const PyAcadAcCmColor& val) const
{
    impObj()->SetIntersectionBoundaryColor(*val.impObj());
}

std::string PyAcadSectionTypeSettings::intersectionBoundaryLayer() const
{
    return wstr_to_utf8(impObj()->GetIntersectionBoundaryLayer());
}

void PyAcadSectionTypeSettings::setIntersectionBoundaryLayer(const std::string& val) const
{
    impObj()->SetIntersectionBoundaryLayer(utf8_to_wstr(val).c_str());
}

std::string PyAcadSectionTypeSettings::intersectionBoundaryLinetype() const
{
    return wstr_to_utf8(impObj()->GetIntersectionBoundaryLinetype());
}

void PyAcadSectionTypeSettings::setIntersectionBoundaryLinetype(const std::string& val) const
{
    impObj()->SetIntersectionBoundaryLinetype(utf8_to_wstr(val).c_str());
}

double PyAcadSectionTypeSettings::intersectionBoundaryLinetypeScale() const
{
    return impObj()->GetIntersectionBoundaryLinetypeScale();
}

void PyAcadSectionTypeSettings::setIntersectionBoundaryLinetypeScale(double val) const
{
    impObj()->SetIntersectionBoundaryLinetypeScale(val);
}

std::string PyAcadSectionTypeSettings::intersectionBoundaryPlotStyleName() const
{
    return wstr_to_utf8(impObj()->GetIntersectionBoundaryPlotStyleName());
}

void PyAcadSectionTypeSettings::setIntersectionBoundaryPlotStyleName(const std::string& val) const
{
    impObj()->SetIntersectionBoundaryPlotStyleName(utf8_to_wstr(val).c_str());
}

PyAcLineWeight PyAcadSectionTypeSettings::intersectionBoundaryLineweight() const
{
    return impObj()->GetIntersectionBoundaryLineweight();
}

void PyAcadSectionTypeSettings::setIntersectionBoundaryLineweight(PyAcLineWeight val) const
{
    impObj()->SetIntersectionBoundaryLineweight(val);
}

bool PyAcadSectionTypeSettings::intersectionBoundaryDivisionLines() const
{
    return impObj()->GetIntersectionBoundaryDivisionLines();
}

void PyAcadSectionTypeSettings::setIntersectionBoundaryDivisionLines(bool val) const
{
    impObj()->SetIntersectionBoundaryDivisionLines(val);
}

bool PyAcadSectionTypeSettings::intersectionFillVisible() const
{
    return impObj()->GetIntersectionFillVisible();
}

void PyAcadSectionTypeSettings::setIntersectionFillVisible(bool val) const
{
    impObj()->SetIntersectionFillVisible(val);
}

PyAcPatternType PyAcadSectionTypeSettings::intersectionFillHatchPatternType() const
{
    return impObj()->GetIntersectionFillHatchPatternType();
}

void PyAcadSectionTypeSettings::setIntersectionFillHatchPatternType(PyAcPatternType val) const
{
    impObj()->SetIntersectionFillHatchPatternType(val);
}

std::string PyAcadSectionTypeSettings::intersectionFillHatchPatternName() const
{
    return wstr_to_utf8(impObj()->GetIntersectionFillHatchPatternName());
}

void PyAcadSectionTypeSettings::setIntersectionFillHatchPatternName(const std::string& val) const
{
    impObj()->SetIntersectionFillHatchPatternName(utf8_to_wstr(val).c_str());
}

double PyAcadSectionTypeSettings::intersectionFillHatchAngle() const
{
    return impObj()->GetIntersectionFillHatchAngle();
}

void PyAcadSectionTypeSettings::setIntersectionFillHatchAngle(double val) const
{
    impObj()->SetIntersectionFillHatchAngle(val);
}

double PyAcadSectionTypeSettings::intersectionFillHatchScale() const
{
    return impObj()->GetIntersectionFillHatchScale();
}

void PyAcadSectionTypeSettings::setIntersectionFillHatchScale(double val) const
{
    impObj()->SetIntersectionFillHatchScale(val);
}

double PyAcadSectionTypeSettings::intersectionFillHatchSpacing() const
{
    return impObj()->GetIntersectionFillHatchSpacing();
}

void PyAcadSectionTypeSettings::setIntersectionFillHatchSpacing(double val) const
{
    impObj()->SetIntersectionFillHatchSpacing(val);
}

PyAcadAcCmColor PyAcadSectionTypeSettings::intersectionFillColor() const
{
    return PyAcadAcCmColor(impObj()->GetIntersectionFillColor());
}

void PyAcadSectionTypeSettings::setIntersectionFillColor(const PyAcadAcCmColor& val) const
{
    impObj()->SetIntersectionFillColor(*val.impObj());
}

std::string PyAcadSectionTypeSettings::intersectionFillLayer() const
{
    return wstr_to_utf8(impObj()->GetIntersectionFillLayer());
}

void PyAcadSectionTypeSettings::setIntersectionFillLayer(const std::string& val) const
{
    impObj()->SetIntersectionFillLayer(utf8_to_wstr(val).c_str());
}

std::string PyAcadSectionTypeSettings::intersectionFillLinetype() const
{
    return wstr_to_utf8(impObj()->GetIntersectionFillLinetype());
}

void PyAcadSectionTypeSettings::setIntersectionFillLinetype(const std::string& val) const
{
    impObj()->SetIntersectionFillLinetype(utf8_to_wstr(val).c_str());
}

double PyAcadSectionTypeSettings::intersectionFillLinetypeScale() const
{
    return impObj()->GetIntersectionFillLinetypeScale();
}

void PyAcadSectionTypeSettings::setIntersectionFillLinetypeScale(double val) const
{
    impObj()->SetIntersectionFillLinetypeScale(val);
}

void PyAcadSectionTypeSettings::setIntersectionFillPlotStyleName(const std::string& val) const
{
    impObj()->SetIntersectionFillPlotStyleName(utf8_to_wstr(val).c_str());
}

std::string PyAcadSectionTypeSettings::intersectionFillPlotStyleName() const
{
    return wstr_to_utf8(impObj()->GetIntersectionFillPlotStyleName());
}

PyAcLineWeight PyAcadSectionTypeSettings::intersectionFillLineweight() const
{
    return impObj()->GetIntersectionFillLineweight();
}

void PyAcadSectionTypeSettings::setIntersectionFillLineweight(PyAcLineWeight val) const
{
    impObj()->SetIntersectionFillLineweight(val);
}

long PyAcadSectionTypeSettings::intersectionFillFaceTransparency() const
{
    return impObj()->GetIntersectionFillFaceTransparency();
}

void PyAcadSectionTypeSettings::setIntersectionFillFaceTransparency(long val) const
{
    impObj()->SetIntersectionFillFaceTransparency(val);
}

bool PyAcadSectionTypeSettings::backgroundLinesVisible() const
{
    return impObj()->GetBackgroundLinesVisible();
}

void PyAcadSectionTypeSettings::setBackgroundLinesVisible(bool val) const
{
    impObj()->SetBackgroundLinesVisible(val);
}

bool PyAcadSectionTypeSettings::backgroundLinesHiddenLine() const
{
    return impObj()->GetBackgroundLinesHiddenLine();
}

void PyAcadSectionTypeSettings::setBackgroundLinesHiddenLine(bool val) const
{
    impObj()->SetBackgroundLinesHiddenLine(val);
}

PyAcadAcCmColor PyAcadSectionTypeSettings::backgroundLinesColor() const
{
    return PyAcadAcCmColor(impObj()->GetBackgroundLinesColor());
}

void PyAcadSectionTypeSettings::setBackgroundLinesColor(const PyAcadAcCmColor& val) const
{
    impObj()->SetBackgroundLinesColor(*val.impObj());
}

std::string PyAcadSectionTypeSettings::backgroundLinesLayer() const
{
    return wstr_to_utf8(impObj()->GetBackgroundLinesLayer());
}

void PyAcadSectionTypeSettings::setBackgroundLinesLayer(const std::string& val) const
{
    impObj()->SetBackgroundLinesLayer(utf8_to_wstr(val).c_str());
}

std::string PyAcadSectionTypeSettings::backgroundLinesLinetype() const
{
    return wstr_to_utf8(impObj()->GetBackgroundLinesLinetype());
}

void PyAcadSectionTypeSettings::setBackgroundLinesLinetype(const std::string& val) const
{
    impObj()->SetBackgroundLinesLinetype(utf8_to_wstr(val).c_str());
}

double PyAcadSectionTypeSettings::backgroundLinesLinetypeScale() const
{
    return impObj()->GetBackgroundLinesLinetypeScale();
}

void PyAcadSectionTypeSettings::setBackgroundLinesLinetypeScale(double val) const
{
    impObj()->SetBackgroundLinesLinetypeScale(val);
}

std::string PyAcadSectionTypeSettings::backgroundLinesPlotStyleName() const
{
    return wstr_to_utf8(impObj()->GetBackgroundLinesPlotStyleName());
}

void PyAcadSectionTypeSettings::setBackgroundLinesPlotStyleName(const std::string& val) const
{
    impObj()->SetBackgroundLinesPlotStyleName(utf8_to_wstr(val).c_str());
}

PyAcLineWeight PyAcadSectionTypeSettings::backgroundLinesLineweight() const
{
    return impObj()->GetBackgroundLinesLineweight();
}

void PyAcadSectionTypeSettings::setBackgroundLinesLineweight(PyAcLineWeight val) const
{
    impObj()->SetBackgroundLinesLineweight(val);
}

bool PyAcadSectionTypeSettings::foregroundLinesVisible() const
{
    return impObj()->GetForegroundLinesVisible();
}

void PyAcadSectionTypeSettings::setForegroundLinesVisible(bool val) const
{
    impObj()->SetForegroundLinesVisible(val);
}

bool PyAcadSectionTypeSettings::foregroundLinesHiddenLine() const
{
    return impObj()->GetForegroundLinesHiddenLine();
}

void PyAcadSectionTypeSettings::setForegroundLinesHiddenLine(bool val) const
{
    impObj()->SetForegroundLinesHiddenLine(val);
}

PyAcadAcCmColor PyAcadSectionTypeSettings::foregroundLinesColor() const
{
    return PyAcadAcCmColor(impObj()->GetForegroundLinesColor());
}

void PyAcadSectionTypeSettings::setForegroundLinesColor(const PyAcadAcCmColor& val) const
{
    impObj()->SetForegroundLinesColor(*val.impObj());
}

std::string PyAcadSectionTypeSettings::foregroundLinesLayer() const
{
    return wstr_to_utf8(impObj()->GetForegroundLinesLayer());
}

void PyAcadSectionTypeSettings::setForegroundLinesLayer(const std::string& val) const
{
    impObj()->SetForegroundLinesLayer(utf8_to_wstr(val).c_str());
}

std::string PyAcadSectionTypeSettings::foregroundLinesLinetype() const
{
    return wstr_to_utf8(impObj()->GetForegroundLinesLinetype());
}

void PyAcadSectionTypeSettings::setForegroundLinesLinetype(const std::string& val) const
{
    impObj()->SetForegroundLinesLinetype(utf8_to_wstr(val).c_str());
}

double PyAcadSectionTypeSettings::foregroundLinesLinetypeScale() const
{
    return impObj()->GetForegroundLinesLinetypeScale();
}

void PyAcadSectionTypeSettings::setForegroundLinesLinetypeScale(double val) const
{
    impObj()->SetForegroundLinesLinetypeScale(val);
}

std::string PyAcadSectionTypeSettings::foregroundLinesPlotStyleName() const
{
    return wstr_to_utf8(impObj()->GetForegroundLinesPlotStyleName());
}

void PyAcadSectionTypeSettings::setForegroundLinesPlotStyleName(const std::string& val) const
{
    impObj()->SetForegroundLinesPlotStyleName(utf8_to_wstr(val).c_str());
}

PyAcLineWeight PyAcadSectionTypeSettings::foregroundLinesLineweight() const
{
    return impObj()->GetForegroundLinesLineweight();
}

void PyAcadSectionTypeSettings::setForegroundLinesLineweight(PyAcLineWeight val) const
{
    impObj()->SetForegroundLinesLineweight(val);
}

long PyAcadSectionTypeSettings::foregroundLinesFaceTransparency() const
{
    return impObj()->GetForegroundLinesFaceTransparency();
}

void PyAcadSectionTypeSettings::setForegroundLinesFaceTransparency(long val) const
{
    impObj()->SetForegroundLinesFaceTransparency(val);
}

long PyAcadSectionTypeSettings::foregroundLinesEdgeTransparency() const
{
    return impObj()->GetForegroundLinesEdgeTransparency();
}

void PyAcadSectionTypeSettings::setForegroundLinesEdgeTransparency(long val) const
{
    impObj()->SetForegroundLinesEdgeTransparency(val);
}

bool PyAcadSectionTypeSettings::curveTangencyLinesVisible() const
{
    return impObj()->GetCurveTangencyLinesVisible();
}

void PyAcadSectionTypeSettings::setCurveTangencyLinesVisible(bool val) const
{
    impObj()->SetCurveTangencyLinesVisible(val);
}

PyAcadAcCmColor PyAcadSectionTypeSettings::curveTangencyLinesColor() const
{
    return PyAcadAcCmColor(impObj()->GetCurveTangencyLinesColor());
}

void PyAcadSectionTypeSettings::setCurveTangencyLinesColor(const PyAcadAcCmColor& val) const
{
    impObj()->SetCurveTangencyLinesColor(*val.impObj());
}

std::string PyAcadSectionTypeSettings::curveTangencyLinesLayer() const
{
    return wstr_to_utf8(impObj()->GetCurveTangencyLinesLayer());
}

void PyAcadSectionTypeSettings::setCurveTangencyLinesLayer(const std::string& val) const
{
    impObj()->SetCurveTangencyLinesLayer(utf8_to_wstr(val).c_str());
}

std::string PyAcadSectionTypeSettings::curveTangencyLinesLinetype() const
{
    return wstr_to_utf8(impObj()->GetCurveTangencyLinesLinetype());
}

void PyAcadSectionTypeSettings::setCurveTangencyLinesLinetype(const std::string& val) const
{
    impObj()->SetCurveTangencyLinesLinetype(utf8_to_wstr(val).c_str());
}

double PyAcadSectionTypeSettings::curveTangencyLinesLinetypeScale() const
{
    return impObj()->GetCurveTangencyLinesLinetypeScale();
}

void PyAcadSectionTypeSettings::setCurveTangencyLinesLinetypeScale(double val) const
{
    impObj()->SetCurveTangencyLinesLinetypeScale(val);
}

std::string PyAcadSectionTypeSettings::curveTangencyLinesPlotStyleName() const
{
    return wstr_to_utf8(impObj()->GetCurveTangencyLinesPlotStyleName());
}

void PyAcadSectionTypeSettings::setCurveTangencyLinesPlotStyleName(const std::string& val) const
{
    impObj()->SetCurveTangencyLinesPlotStyleName(utf8_to_wstr(val).c_str());
}

PyAcLineWeight PyAcadSectionTypeSettings::curveTangencyLinesLineweight() const
{
    return impObj()->GetCurveTangencyLinesLineweight();
}

void PyAcadSectionTypeSettings::setCurveTangencyLinesLineweight(PyAcLineWeight val) const
{
    impObj()->SetCurveTangencyLinesLineweight(val);
}

std::string PyAcadSectionTypeSettings::className()
{
    return "AcadSectionTypeSettings";
}

PyIAcadSectionTypeSettingsImpl* PyAcadSectionTypeSettings::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return m_pyImp.get();
}

//----------------------------------------------------------------------------------------
//PyAcadDatabasePreferences
void makePyAcadDatabasePreferencesWrapper()
{
    PyDocString DS("AcadDatabasePreferences");
    class_<PyAcadDatabasePreferences>("AcadDatabasePreferences", boost::python::no_init)
        .def("solidFill", &PyAcadDatabasePreferences::solidFill, DS.ARGS())
        .def("setSolidFill", &PyAcadDatabasePreferences::setSolidFill, DS.ARGS({ "val:bool" }))
        .def("xrefEdit", &PyAcadDatabasePreferences::xrefEdit, DS.ARGS())
        .def("setXRefEdit", &PyAcadDatabasePreferences::setXRefEdit, DS.ARGS({ "val:bool" }))
        .def("xrefLayerVisibility", &PyAcadDatabasePreferences::xrefLayerVisibility, DS.ARGS())
        .def("setXRefLayerVisibility", &PyAcadDatabasePreferences::setXRefLayerVisibility, DS.ARGS({ "val:bool" }))
        .def("oleLaunch", &PyAcadDatabasePreferences::oleLaunch, DS.ARGS())
        .def("setOLELaunch", &PyAcadDatabasePreferences::setOLELaunch, DS.ARGS({ "val:bool" }))
        .def("allowLongSymbolNames", &PyAcadDatabasePreferences::allowLongSymbolNames, DS.ARGS())
        .def("setAllowLongSymbolNames", &PyAcadDatabasePreferences::setAllowLongSymbolNames, DS.ARGS({ "val:bool" }))
        .def("objectSortBySelection", &PyAcadDatabasePreferences::objectSortBySelection, DS.ARGS())
        .def("setObjectSortBySelection", &PyAcadDatabasePreferences::setObjectSortBySelection, DS.ARGS({ "val:bool" }))
        .def("objectSortBySnap", &PyAcadDatabasePreferences::objectSortBySnap, DS.ARGS())
        .def("setObjectSortBySnap", &PyAcadDatabasePreferences::setObjectSortBySnap, DS.ARGS({ "val:bool" }))
        .def("objectSortByRedraws", &PyAcadDatabasePreferences::objectSortByRedraws, DS.ARGS())
        .def("setObjectSortByRedraws", &PyAcadDatabasePreferences::setObjectSortByRedraws, DS.ARGS({ "val:bool" }))
        .def("objectSortByRegens", &PyAcadDatabasePreferences::objectSortByRegens, DS.ARGS())
        .def("setObjectSortByRegens", &PyAcadDatabasePreferences::setObjectSortByRegens, DS.ARGS({ "val:bool" }))
        .def("objectSortByPlotting", &PyAcadDatabasePreferences::objectSortByPlotting, DS.ARGS())
        .def("setObjectSortByPlotting", &PyAcadDatabasePreferences::setObjectSortByPlotting, DS.ARGS({ "val:bool" }))
        .def("objectSortByPSOutput", &PyAcadDatabasePreferences::objectSortByPSOutput, DS.ARGS())
        .def("setObjectSortByPSOutput", &PyAcadDatabasePreferences::setObjectSortByPSOutput, DS.ARGS({ "val:bool" }))
        .def("setContourLinesPerSurface", &PyAcadDatabasePreferences::setContourLinesPerSurface, DS.ARGS({ "val:int" }))
        .def("contourLinesPerSurface", &PyAcadDatabasePreferences::contourLinesPerSurface, DS.ARGS())
        .def("setDisplaySilhouette", &PyAcadDatabasePreferences::setDisplaySilhouette, DS.ARGS({ "val:bool" }))
        .def("displaySilhouette", &PyAcadDatabasePreferences::displaySilhouette, DS.ARGS())
        .def("setMaxActiveViewports", &PyAcadDatabasePreferences::setMaxActiveViewports, DS.ARGS({ "val:int" }))
        .def("maxActiveViewports", &PyAcadDatabasePreferences::maxActiveViewports, DS.ARGS())
        .def("setRenderSmoothness", &PyAcadDatabasePreferences::setRenderSmoothness, DS.ARGS({ "val:float" }))
        .def("renderSmoothness", &PyAcadDatabasePreferences::renderSmoothness, DS.ARGS())
        .def("setSegmentPerPolyline", &PyAcadDatabasePreferences::setSegmentPerPolyline, DS.ARGS({ "val:int" }))
        .def("segmentPerPolyline", &PyAcadDatabasePreferences::segmentPerPolyline, DS.ARGS())
        .def("setTextFrameDisplay", &PyAcadDatabasePreferences::setTextFrameDisplay, DS.ARGS({ "val:bool" }))
        .def("textFrameDisplay", &PyAcadDatabasePreferences::textFrameDisplay, DS.ARGS())
        .def("setLineweight", &PyAcadDatabasePreferences::setLineweight, DS.ARGS({ "val:PyAx.AcLineWeight" }))
        .def("lineweight", &PyAcadDatabasePreferences::lineweight, DS.ARGS())
        .def("setLineWeightDisplay", &PyAcadDatabasePreferences::setLineWeightDisplay, DS.ARGS({ "val:bool" }))
        .def("lineWeightDisplay", &PyAcadDatabasePreferences::lineWeightDisplay, DS.ARGS())
        .def("className", &PyAcadDatabasePreferences::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadDatabasePreferences::PyAcadDatabasePreferences(std::shared_ptr<PyIAcadDatabasePreferencesImpl> ptr)
    : m_pyImp(ptr)
{
}

bool PyAcadDatabasePreferences::solidFill() const
{
    return impObj()->GetSolidFill();
}

void PyAcadDatabasePreferences::setSolidFill(bool val) const
{
    impObj()->SetSolidFill(val);
}

bool PyAcadDatabasePreferences::xrefEdit() const
{
    return impObj()->GetXRefEdit();
}

void PyAcadDatabasePreferences::setXRefEdit(bool val) const
{
    impObj()->SetXRefEdit(val);
}

bool PyAcadDatabasePreferences::xrefLayerVisibility() const
{
    return impObj()->GetXRefLayerVisibility();
}

void PyAcadDatabasePreferences::setXRefLayerVisibility(bool val) const
{
    impObj()->SetXRefLayerVisibility(val);
}

bool PyAcadDatabasePreferences::oleLaunch() const
{
    return impObj()->GetOLELaunch();
}

void PyAcadDatabasePreferences::setOLELaunch(bool val) const
{
    impObj()->SetOLELaunch(val);
}

bool PyAcadDatabasePreferences::allowLongSymbolNames() const
{
    return impObj()->GetAllowLongSymbolNames();
}

void PyAcadDatabasePreferences::setAllowLongSymbolNames(bool val) const
{
    impObj()->SetAllowLongSymbolNames(val);
}

bool PyAcadDatabasePreferences::objectSortBySelection() const
{
    return impObj()->GetObjectSortBySelection();
}

void PyAcadDatabasePreferences::setObjectSortBySelection(bool val) const
{
    impObj()->SetObjectSortBySelection(val);
}

bool PyAcadDatabasePreferences::objectSortBySnap() const
{
    return impObj()->GetObjectSortBySnap();
}

void PyAcadDatabasePreferences::setObjectSortBySnap(bool val) const
{
    impObj()->SetObjectSortBySnap(val);
}

bool PyAcadDatabasePreferences::objectSortByRedraws() const
{
    return impObj()->GetObjectSortByRedraws();
}

void PyAcadDatabasePreferences::setObjectSortByRedraws(bool val) const
{
    impObj()->SetObjectSortByRedraws(val);
}

bool PyAcadDatabasePreferences::objectSortByRegens() const
{
    return impObj()->GetObjectSortByRegens();
}

void PyAcadDatabasePreferences::setObjectSortByRegens(bool val) const
{
    impObj()->SetObjectSortByRegens(val);
}

bool PyAcadDatabasePreferences::objectSortByPlotting() const
{
    return impObj()->GetObjectSortByPlotting();
}

void PyAcadDatabasePreferences::setObjectSortByPlotting(bool val) const
{
    impObj()->SetObjectSortByPlotting(val);
}

bool PyAcadDatabasePreferences::objectSortByPSOutput() const
{
    return impObj()->GetObjectSortByPSOutput();
}

void PyAcadDatabasePreferences::setObjectSortByPSOutput(bool val) const
{
    impObj()->SetObjectSortByPSOutput(val);
}

void PyAcadDatabasePreferences::setContourLinesPerSurface(long val) const
{
    impObj()->SetContourLinesPerSurface(val);
}

long PyAcadDatabasePreferences::contourLinesPerSurface() const
{
    return impObj()->GetContourLinesPerSurface();
}

void PyAcadDatabasePreferences::setDisplaySilhouette(bool val) const
{
    impObj()->SetDisplaySilhouette(val);
}

bool PyAcadDatabasePreferences::displaySilhouette() const
{
    return impObj()->GetDisplaySilhouette();
}

void PyAcadDatabasePreferences::setMaxActiveViewports(long val) const
{
    impObj()->SetMaxActiveViewports(val);
}

long PyAcadDatabasePreferences::maxActiveViewports() const
{
    return impObj()->GetMaxActiveViewports();
}

void PyAcadDatabasePreferences::setRenderSmoothness(double val) const
{
    impObj()->SetRenderSmoothness(val);
}

double PyAcadDatabasePreferences::renderSmoothness() const
{
    return impObj()->GetRenderSmoothness();
}

void PyAcadDatabasePreferences::setSegmentPerPolyline(long val) const
{
    impObj()->SetSegmentPerPolyline(val);
}

long PyAcadDatabasePreferences::segmentPerPolyline() const
{
    return impObj()->GetSegmentPerPolyline();
}

void PyAcadDatabasePreferences::setTextFrameDisplay(bool val) const
{
    impObj()->SetTextFrameDisplay(val);
}

bool PyAcadDatabasePreferences::textFrameDisplay() const
{
    return impObj()->GetTextFrameDisplay();
}

void PyAcadDatabasePreferences::setLineweight(PyAcLineWeight val) const
{
    impObj()->SetLineweight(val);
}

PyAcLineWeight PyAcadDatabasePreferences::lineweight() const
{
    return impObj()->GetLineweight();
}

void PyAcadDatabasePreferences::setLineWeightDisplay(bool val) const
{
    impObj()->SetLineWeightDisplay(val);
}

bool PyAcadDatabasePreferences::lineWeightDisplay() const
{
    return impObj()->GetLineWeightDisplay();
}

std::string PyAcadDatabasePreferences::className()
{
    return "AcadDatabasePreferences";
}

PyIAcadDatabasePreferencesImpl* PyAcadDatabasePreferences::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return m_pyImp.get();
}

//----------------------------------------------------------------------------------------
//PyAcadPreferencesFiles
void makePyAcadPreferencesFilesWrapper()
{
    PyDocString DS("AcadPreferencesFiles");
    class_<PyAcadPreferencesFiles>("AcadPreferencesFiles", boost::python::no_init)
        .def("setSupportPath", &PyAcadPreferencesFiles::setSupportPath, DS.ARGS({ "val:str" }))
        .def("supportPath", &PyAcadPreferencesFiles::supportPath, DS.ARGS())
        .def("setDriversPath", &PyAcadPreferencesFiles::setDriversPath, DS.ARGS({ "val:str" }))
        .def("driversPath", &PyAcadPreferencesFiles::driversPath, DS.ARGS())
        .def("setMenuFile", &PyAcadPreferencesFiles::setMenuFile, DS.ARGS({ "val:str" }))
        .def("menuFile", &PyAcadPreferencesFiles::menuFile, DS.ARGS())
        .def("setEnterpriseMenuFile", &PyAcadPreferencesFiles::setEnterpriseMenuFile, DS.ARGS({ "val:str" }))
        .def("enterpriseMenuFile", &PyAcadPreferencesFiles::enterpriseMenuFile, DS.ARGS())
        .def("setCustomIconPath", &PyAcadPreferencesFiles::setCustomIconPath, DS.ARGS({ "val:str" }))
        .def("customIconPath", &PyAcadPreferencesFiles::customIconPath, DS.ARGS())
        .def("setHelpFilePath", &PyAcadPreferencesFiles::setHelpFilePath, DS.ARGS({ "val:str" }))
        .def("helpFilePath", &PyAcadPreferencesFiles::helpFilePath, DS.ARGS())
        .def("setDefaultInternetURL", &PyAcadPreferencesFiles::setDefaultInternetURL, DS.ARGS({ "val:str" }))
        .def("defaultInternetURL", &PyAcadPreferencesFiles::defaultInternetURL, DS.ARGS())
        .def("configFile", &PyAcadPreferencesFiles::configFile, DS.ARGS())
        .def("licenseServer", &PyAcadPreferencesFiles::licenseServer, DS.ARGS())
        .def("setTextEditor", &PyAcadPreferencesFiles::setTextEditor, DS.ARGS({ "val:str" }))
        .def("textEditor", &PyAcadPreferencesFiles::textEditor, DS.ARGS())
        .def("setMainDictionary", &PyAcadPreferencesFiles::setMainDictionary, DS.ARGS({ "val:str" }))
        .def("mainDictionary", &PyAcadPreferencesFiles::mainDictionary, DS.ARGS())
        .def("setCustomDictionary", &PyAcadPreferencesFiles::setCustomDictionary, DS.ARGS({ "val:str" }))
        .def("customDictionary", &PyAcadPreferencesFiles::customDictionary, DS.ARGS())
        .def("setAltFontFile", &PyAcadPreferencesFiles::setAltFontFile, DS.ARGS({ "val:str" }))
        .def("altFontFile", &PyAcadPreferencesFiles::altFontFile, DS.ARGS())
        .def("setFontFileMap", &PyAcadPreferencesFiles::setFontFileMap, DS.ARGS({ "val:str" }))
        .def("fontFileMap", &PyAcadPreferencesFiles::fontFileMap, DS.ARGS())
        .def("setPrintFile", &PyAcadPreferencesFiles::setPrintFile, DS.ARGS({ "val:str" }))
        .def("printFile", &PyAcadPreferencesFiles::printFile, DS.ARGS())
        .def("setPrintSpoolExecutable", &PyAcadPreferencesFiles::setPrintSpoolExecutable, DS.ARGS({ "val:str" }))
        .def("printSpoolExecutable", &PyAcadPreferencesFiles::printSpoolExecutable, DS.ARGS())
        .def("setPostScriptPrologFile", &PyAcadPreferencesFiles::setPostScriptPrologFile, DS.ARGS({ "val:str" }))
        .def("postScriptPrologFile", &PyAcadPreferencesFiles::postScriptPrologFile, DS.ARGS())
        .def("setPrintSpoolerPath", &PyAcadPreferencesFiles::setPrintSpoolerPath, DS.ARGS({ "val:str" }))
        .def("printSpoolerPath", &PyAcadPreferencesFiles::printSpoolerPath, DS.ARGS())
        .def("setAutoSavePath", &PyAcadPreferencesFiles::setAutoSavePath, DS.ARGS({ "val:str" }))
        .def("autoSavePath", &PyAcadPreferencesFiles::autoSavePath, DS.ARGS())
        .def("setTemplateDwgPath", &PyAcadPreferencesFiles::setTemplateDwgPath, DS.ARGS({ "val:str" }))
        .def("templateDwgPath", &PyAcadPreferencesFiles::templateDwgPath, DS.ARGS())
        .def("setLogFilePath", &PyAcadPreferencesFiles::setLogFilePath, DS.ARGS({ "val:str" }))
        .def("logFilePath", &PyAcadPreferencesFiles::logFilePath, DS.ARGS())
        .def("setTempFilePath", &PyAcadPreferencesFiles::setTempFilePath, DS.ARGS({ "val:str" }))
        .def("tempFilePath", &PyAcadPreferencesFiles::tempFilePath, DS.ARGS())
        .def("setTempXrefPath", &PyAcadPreferencesFiles::setTempXrefPath, DS.ARGS({ "val:str" }))
        .def("tempXrefPath", &PyAcadPreferencesFiles::tempXrefPath, DS.ARGS())
        .def("setTextureMapPath", &PyAcadPreferencesFiles::setTextureMapPath, DS.ARGS({ "val:str" }))
        .def("textureMapPath", &PyAcadPreferencesFiles::textureMapPath, DS.ARGS())
        .def("setAltTabletMenuFile", &PyAcadPreferencesFiles::setAltTabletMenuFile, DS.ARGS({ "val:str" }))
        .def("altTabletMenuFile", &PyAcadPreferencesFiles::altTabletMenuFile, DS.ARGS())
        .def("setProjectFilePath", &PyAcadPreferencesFiles::setProjectFilePath, DS.ARGS({ "projectName:str","projectFilePath:str" }))
        .def("projectFilePath", &PyAcadPreferencesFiles::projectFilePath, DS.ARGS({ "projectName:str" }))
        .def("setPrinterConfigPath", &PyAcadPreferencesFiles::setPrinterConfigPath, DS.ARGS({ "val:str" }))
        .def("printerConfigPath", &PyAcadPreferencesFiles::printerConfigPath, DS.ARGS())
        .def("setPrinterDescPath", &PyAcadPreferencesFiles::setPrinterDescPath, DS.ARGS({ "val:str" }))
        .def("printerDescPath", &PyAcadPreferencesFiles::printerDescPath, DS.ARGS())
        .def("setPrinterStyleSheetPath", &PyAcadPreferencesFiles::setPrinterStyleSheetPath, DS.ARGS({ "val:str" }))
        .def("printerStyleSheetPath", &PyAcadPreferencesFiles::printerStyleSheetPath, DS.ARGS())
        .def("setWorkspacePath", &PyAcadPreferencesFiles::setWorkspacePath, DS.ARGS({ "val:str" }))
        .def("workspacePath", &PyAcadPreferencesFiles::workspacePath, DS.ARGS())
        .def("setObjectARXPath", &PyAcadPreferencesFiles::setObjectARXPath, DS.ARGS({ "val:str" }))
        .def("objectARXPath", &PyAcadPreferencesFiles::objectARXPath, DS.ARGS())
        .def("setColorBookPath", &PyAcadPreferencesFiles::setColorBookPath, DS.ARGS({ "val:str" }))
        .def("colorBookPath", &PyAcadPreferencesFiles::colorBookPath, DS.ARGS())
        .def("setToolPalettePath", &PyAcadPreferencesFiles::setToolPalettePath, DS.ARGS({ "val:str" }))
        .def("toolPalettePath", &PyAcadPreferencesFiles::toolPalettePath, DS.ARGS())
        .def("setQNewTemplateFile", &PyAcadPreferencesFiles::setQNewTemplateFile, DS.ARGS({ "val:str" }))
        .def("qnewTemplateFile", &PyAcadPreferencesFiles::qnewTemplateFile, DS.ARGS())
        .def("setPlotLogFilePath", &PyAcadPreferencesFiles::setPlotLogFilePath, DS.ARGS({ "val:str" }))
        .def("plotLogFilePath", &PyAcadPreferencesFiles::plotLogFilePath, DS.ARGS())
        .def("setPageSetupOverridesTemplateFile", &PyAcadPreferencesFiles::setPageSetupOverridesTemplateFile, DS.ARGS({ "val:str" }))
        .def("pageSetupOverridesTemplateFile", &PyAcadPreferencesFiles::pageSetupOverridesTemplateFile, DS.ARGS())
        .def("setActiveInvProject", &PyAcadPreferencesFiles::setActiveInvProject, DS.ARGS({ "val:str" }))
        .def("activeInvProject", &PyAcadPreferencesFiles::activeInvProject, DS.ARGS())
        .def("className", &PyAcadPreferencesFiles::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadPreferencesFiles::PyAcadPreferencesFiles(std::shared_ptr<PyIAcadPreferencesFilesImpl> ptr)
    : m_pyImp(ptr)
{
}

void PyAcadPreferencesFiles::setSupportPath(const std::string& val) const
{
    impObj()->SetSupportPath(utf8_to_wstr(val).c_str());
}

std::string PyAcadPreferencesFiles::supportPath() const
{
    return wstr_to_utf8(impObj()->GetSupportPath());
}

void PyAcadPreferencesFiles::setDriversPath(const std::string& val) const
{
    impObj()->SetDriversPath(utf8_to_wstr(val).c_str());
}

std::string PyAcadPreferencesFiles::driversPath() const
{
    return wstr_to_utf8(impObj()->GetDriversPath());
}

void PyAcadPreferencesFiles::setMenuFile(const std::string& val) const
{
    impObj()->SetMenuFile(utf8_to_wstr(val).c_str());
}

std::string PyAcadPreferencesFiles::menuFile() const
{
    return wstr_to_utf8(impObj()->GetMenuFile());
}

void PyAcadPreferencesFiles::setEnterpriseMenuFile(const std::string& val) const
{
    impObj()->SetEnterpriseMenuFile(utf8_to_wstr(val).c_str());
}

std::string PyAcadPreferencesFiles::enterpriseMenuFile() const
{
    return wstr_to_utf8(impObj()->GetEnterpriseMenuFile());
}

void PyAcadPreferencesFiles::setCustomIconPath(const std::string& val) const
{
    impObj()->SetCustomIconPath(utf8_to_wstr(val).c_str());
}

std::string PyAcadPreferencesFiles::customIconPath() const
{
    return wstr_to_utf8(impObj()->GetCustomIconPath());
}

void PyAcadPreferencesFiles::setHelpFilePath(const std::string& val) const
{
    impObj()->SetHelpFilePath(utf8_to_wstr(val).c_str());
}

std::string PyAcadPreferencesFiles::helpFilePath() const
{
    return wstr_to_utf8(impObj()->GetHelpFilePath());
}

void PyAcadPreferencesFiles::setDefaultInternetURL(const std::string& val) const
{
    impObj()->SetDefaultInternetURL(utf8_to_wstr(val).c_str());
}

std::string PyAcadPreferencesFiles::defaultInternetURL() const
{
    return wstr_to_utf8(impObj()->GetDefaultInternetURL());
}

std::string PyAcadPreferencesFiles::configFile() const
{
    return wstr_to_utf8(impObj()->GetConfigFile());
}

std::string PyAcadPreferencesFiles::licenseServer() const
{
    return wstr_to_utf8(impObj()->GetLicenseServer());
}

void PyAcadPreferencesFiles::setTextEditor(const std::string& val) const
{
    impObj()->SetTextEditor(utf8_to_wstr(val).c_str());
}

std::string PyAcadPreferencesFiles::textEditor() const
{
    return wstr_to_utf8(impObj()->GetTextEditor());
}

void PyAcadPreferencesFiles::setMainDictionary(const std::string& val) const
{
    impObj()->SetMainDictionary(utf8_to_wstr(val).c_str());
}

std::string PyAcadPreferencesFiles::mainDictionary() const
{
    return wstr_to_utf8(impObj()->GetMainDictionary());
}

void PyAcadPreferencesFiles::setCustomDictionary(const std::string& val) const
{
    impObj()->SetCustomDictionary(utf8_to_wstr(val).c_str());
}

std::string PyAcadPreferencesFiles::customDictionary() const
{
    return wstr_to_utf8(impObj()->GetCustomDictionary());
}

void PyAcadPreferencesFiles::setAltFontFile(const std::string& val) const
{
    impObj()->SetAltFontFile(utf8_to_wstr(val).c_str());
}

std::string PyAcadPreferencesFiles::altFontFile() const
{
    return wstr_to_utf8(impObj()->GetAltFontFile());
}

void PyAcadPreferencesFiles::setFontFileMap(const std::string& val) const
{
    impObj()->SetFontFileMap(utf8_to_wstr(val).c_str());
}

std::string PyAcadPreferencesFiles::fontFileMap() const
{
    return wstr_to_utf8(impObj()->GetFontFileMap());
}

void PyAcadPreferencesFiles::setPrintFile(const std::string& val) const
{
    impObj()->SetPrintFile(utf8_to_wstr(val).c_str());
}

std::string PyAcadPreferencesFiles::printFile() const
{
    return wstr_to_utf8(impObj()->GetPrintFile());
}

void PyAcadPreferencesFiles::setPrintSpoolExecutable(const std::string& val) const
{
    impObj()->SetPrintSpoolExecutable(utf8_to_wstr(val).c_str());
}

std::string PyAcadPreferencesFiles::printSpoolExecutable() const
{
    return wstr_to_utf8(impObj()->GetPrintSpoolExecutable());
}

void PyAcadPreferencesFiles::setPostScriptPrologFile(const std::string& val) const
{
    impObj()->SetPostScriptPrologFile(utf8_to_wstr(val).c_str());
}

std::string PyAcadPreferencesFiles::postScriptPrologFile() const
{
    return wstr_to_utf8(impObj()->GetPostScriptPrologFile());
}

void PyAcadPreferencesFiles::setPrintSpoolerPath(const std::string& val) const
{
    impObj()->SetPrintSpoolerPath(utf8_to_wstr(val).c_str());
}

std::string PyAcadPreferencesFiles::printSpoolerPath() const
{
    return wstr_to_utf8(impObj()->GetPrintSpoolerPath());
}

void PyAcadPreferencesFiles::setAutoSavePath(const std::string& val) const
{
    impObj()->SetAutoSavePath(utf8_to_wstr(val).c_str());
}

std::string PyAcadPreferencesFiles::autoSavePath() const
{
    return wstr_to_utf8(impObj()->GetAutoSavePath());
}

void PyAcadPreferencesFiles::setTemplateDwgPath(const std::string& val) const
{
    impObj()->SetTemplateDwgPath(utf8_to_wstr(val).c_str());
}

std::string PyAcadPreferencesFiles::templateDwgPath() const
{
    return wstr_to_utf8(impObj()->GetTemplateDwgPath());
}

void PyAcadPreferencesFiles::setLogFilePath(const std::string& val) const
{
    impObj()->SetLogFilePath(utf8_to_wstr(val).c_str());
}

std::string PyAcadPreferencesFiles::logFilePath() const
{
    return wstr_to_utf8(impObj()->GetLogFilePath());
}

void PyAcadPreferencesFiles::setTempFilePath(const std::string& val) const
{
    impObj()->SetTempFilePath(utf8_to_wstr(val).c_str());
}

std::string PyAcadPreferencesFiles::tempFilePath() const
{
    return wstr_to_utf8(impObj()->GetTempFilePath());
}

void PyAcadPreferencesFiles::setTempXrefPath(const std::string& val) const
{
    impObj()->SetTempXrefPath(utf8_to_wstr(val).c_str());
}

std::string PyAcadPreferencesFiles::tempXrefPath() const
{
    return wstr_to_utf8(impObj()->GetTempXrefPath());
}

void PyAcadPreferencesFiles::setTextureMapPath(const std::string& val) const
{
    impObj()->SetTextureMapPath(utf8_to_wstr(val).c_str());
}

std::string PyAcadPreferencesFiles::textureMapPath() const
{
    return wstr_to_utf8(impObj()->GetTextureMapPath());
}

void PyAcadPreferencesFiles::setAltTabletMenuFile(const std::string& val) const
{
    impObj()->SetAltTabletMenuFile(utf8_to_wstr(val).c_str());
}

std::string PyAcadPreferencesFiles::altTabletMenuFile() const
{
    return wstr_to_utf8(impObj()->GetAltTabletMenuFile());
}

void PyAcadPreferencesFiles::setProjectFilePath(const std::string& projectName, const std::string& projectFilePath) const
{
    impObj()->SetProjectFilePath(utf8_to_wstr(projectName).c_str(), utf8_to_wstr(projectFilePath).c_str());
}

std::string PyAcadPreferencesFiles::projectFilePath(const std::string& projectName) const
{
    return wstr_to_utf8(impObj()->GetProjectFilePath(utf8_to_wstr(projectName).c_str()));
}

void PyAcadPreferencesFiles::setPrinterConfigPath(const std::string& val) const
{
    impObj()->SetPrinterConfigPath(utf8_to_wstr(val).c_str());
}

std::string PyAcadPreferencesFiles::printerConfigPath() const
{
    return wstr_to_utf8(impObj()->GetPrinterConfigPath());
}

void PyAcadPreferencesFiles::setPrinterDescPath(const std::string& val) const
{
    impObj()->SetPrinterDescPath(utf8_to_wstr(val).c_str());
}

std::string PyAcadPreferencesFiles::printerDescPath() const
{
    return wstr_to_utf8(impObj()->GetPrinterDescPath());
}

void PyAcadPreferencesFiles::setPrinterStyleSheetPath(const std::string& val) const
{
    impObj()->SetPrinterStyleSheetPath(utf8_to_wstr(val).c_str());
}

std::string PyAcadPreferencesFiles::printerStyleSheetPath() const
{
    return wstr_to_utf8(impObj()->GetPrinterStyleSheetPath());
}

void PyAcadPreferencesFiles::setWorkspacePath(const std::string& val) const
{
    impObj()->SetWorkspacePath(utf8_to_wstr(val).c_str());
}

std::string PyAcadPreferencesFiles::workspacePath() const
{
    return wstr_to_utf8(impObj()->GetWorkspacePath());
}

void PyAcadPreferencesFiles::setObjectARXPath(const std::string& val) const
{
    impObj()->SetObjectARXPath(utf8_to_wstr(val).c_str());
}

std::string PyAcadPreferencesFiles::objectARXPath() const
{
    return wstr_to_utf8(impObj()->GetObjectARXPath());
}

void PyAcadPreferencesFiles::setColorBookPath(const std::string& val) const
{
    impObj()->SetColorBookPath(utf8_to_wstr(val).c_str());
}

std::string PyAcadPreferencesFiles::colorBookPath() const
{
    return wstr_to_utf8(impObj()->GetColorBookPath());
}

void PyAcadPreferencesFiles::setToolPalettePath(const std::string& val) const
{
    impObj()->SetToolPalettePath(utf8_to_wstr(val).c_str());
}

std::string PyAcadPreferencesFiles::toolPalettePath() const
{
    return wstr_to_utf8(impObj()->GetToolPalettePath());
}

void PyAcadPreferencesFiles::setQNewTemplateFile(const std::string& val) const
{
    impObj()->SetQNewTemplateFile(utf8_to_wstr(val).c_str());
}

std::string PyAcadPreferencesFiles::qnewTemplateFile() const
{
    return wstr_to_utf8(impObj()->GetQNewTemplateFile());
}

void PyAcadPreferencesFiles::setPlotLogFilePath(const std::string& val) const
{
    impObj()->SetPlotLogFilePath(utf8_to_wstr(val).c_str());
}

std::string PyAcadPreferencesFiles::plotLogFilePath() const
{
    return wstr_to_utf8(impObj()->GetPlotLogFilePath());
}

void PyAcadPreferencesFiles::setPageSetupOverridesTemplateFile(const std::string& val) const
{
    impObj()->SetPageSetupOverridesTemplateFile(utf8_to_wstr(val).c_str());
}

std::string PyAcadPreferencesFiles::pageSetupOverridesTemplateFile() const
{
    return wstr_to_utf8(impObj()->GetPageSetupOverridesTemplateFile());
}

void PyAcadPreferencesFiles::setActiveInvProject(const std::string& val) const
{
    impObj()->SetActiveInvProject(utf8_to_wstr(val).c_str());
}

std::string PyAcadPreferencesFiles::activeInvProject() const
{
    return wstr_to_utf8(impObj()->GetActiveInvProject());
}

std::string PyAcadPreferencesFiles::className()
{
    return "AcadPreferencesFiles";
}

PyIAcadPreferencesFilesImpl* PyAcadPreferencesFiles::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return m_pyImp.get();
}

//----------------------------------------------------------------------------------------
//PyAcadPreferencesDisplay
void makePyAcadPreferencesDisplayWrapper()
{
    PyDocString DS("AcadPreferencesDisplay");
    class_<PyAcadPreferencesDisplay>("AcadPreferencesDisplay", boost::python::no_init)
        .def("setLayoutDisplayMargins", &PyAcadPreferencesDisplay::setLayoutDisplayMargins, DS.ARGS({ "val:bool" }))
        .def("layoutDisplayMargins", &PyAcadPreferencesDisplay::layoutDisplayMargins, DS.ARGS())
        .def("setLayoutDisplayPaper", &PyAcadPreferencesDisplay::setLayoutDisplayPaper, DS.ARGS({ "val:bool" }))
        .def("layoutDisplayPaper", &PyAcadPreferencesDisplay::layoutDisplayPaper, DS.ARGS())
        .def("setLayoutDisplayPaperShadow", &PyAcadPreferencesDisplay::setLayoutDisplayPaperShadow, DS.ARGS({ "val:bool" }))
        .def("layoutDisplayPaperShadow", &PyAcadPreferencesDisplay::layoutDisplayPaperShadow, DS.ARGS())
        .def("setLayoutShowPlotSetup", &PyAcadPreferencesDisplay::setLayoutShowPlotSetup, DS.ARGS({ "val:bool" }))
        .def("layoutShowPlotSetup", &PyAcadPreferencesDisplay::layoutShowPlotSetup, DS.ARGS())
        .def("setLayoutCreateViewport", &PyAcadPreferencesDisplay::setLayoutCreateViewport, DS.ARGS({ "val:bool" }))
        .def("layoutCreateViewport", &PyAcadPreferencesDisplay::layoutCreateViewport, DS.ARGS())
        .def("setDisplayScrollBars", &PyAcadPreferencesDisplay::setDisplayScrollBars, DS.ARGS({ "val:bool" }))
        .def("displayScrollBars", &PyAcadPreferencesDisplay::displayScrollBars, DS.ARGS())
        .def("setDisplayScreenMenu", &PyAcadPreferencesDisplay::setDisplayScreenMenu, DS.ARGS({ "val:bool" }))
        .def("displayScreenMenu", &PyAcadPreferencesDisplay::displayScreenMenu, DS.ARGS())
        .def("setCursorSize", &PyAcadPreferencesDisplay::setCursorSize, DS.ARGS({ "val:int" }))
        .def("cursorSize", &PyAcadPreferencesDisplay::cursorSize, DS.ARGS())
        .def("setDockedVisibleLines", &PyAcadPreferencesDisplay::setDockedVisibleLines, DS.ARGS({ "val:int" }))
        .def("dockedVisibleLines", &PyAcadPreferencesDisplay::dockedVisibleLines, DS.ARGS())
        .def("setShowRasterImage", &PyAcadPreferencesDisplay::setShowRasterImage, DS.ARGS({ "val:bool" }))
        .def("showRasterImage", &PyAcadPreferencesDisplay::showRasterImage, DS.ARGS())
        .def("setGraphicsWinModelBackgrndColor", &PyAcadPreferencesDisplay::setGraphicsWinModelBackgrndColor, DS.ARGS({ "rgb:tuple[int,int,int]" }))
        .def("graphicsWinModelBackgrndColor", &PyAcadPreferencesDisplay::graphicsWinModelBackgrndColor, DS.ARGS())
        .def("setModelCrosshairColor", &PyAcadPreferencesDisplay::setModelCrosshairColor, DS.ARGS({ "rgb:tuple[int,int,int]" }))
        .def("modelCrosshairColor", &PyAcadPreferencesDisplay::modelCrosshairColor, DS.ARGS())
        .def("setGraphicsWinLayoutBackgrndColor", &PyAcadPreferencesDisplay::setGraphicsWinLayoutBackgrndColor, DS.ARGS({ "rgb:tuple[int,int,int]" }))
        .def("graphicsWinLayoutBackgrndColor", &PyAcadPreferencesDisplay::graphicsWinLayoutBackgrndColor, DS.ARGS())
        .def("setTextWinBackgrndColor", &PyAcadPreferencesDisplay::setTextWinBackgrndColor, DS.ARGS({ "rgb:tuple[int,int,int]" }))
        .def("textWinBackgrndColor", &PyAcadPreferencesDisplay::textWinBackgrndColor, DS.ARGS())
        .def("setTextWinTextColor", &PyAcadPreferencesDisplay::setTextWinTextColor, DS.ARGS({ "rgb:tuple[int,int,int]" }))
        .def("textWinTextColor", &PyAcadPreferencesDisplay::textWinTextColor, DS.ARGS())
        .def("setLayoutCrosshairColor", &PyAcadPreferencesDisplay::setLayoutCrosshairColor, DS.ARGS({ "rgb:tuple[int,int,int]" }))
        .def("layoutCrosshairColor", &PyAcadPreferencesDisplay::layoutCrosshairColor, DS.ARGS())
        .def("setAutoTrackingVecColor", &PyAcadPreferencesDisplay::setAutoTrackingVecColor, DS.ARGS({ "rgb:tuple[int,int,int]" }))
        .def("autoTrackingVecColor", &PyAcadPreferencesDisplay::autoTrackingVecColor, DS.ARGS())
        .def("setTextFont", &PyAcadPreferencesDisplay::setTextFont, DS.ARGS({ "val:str" }))
        .def("textFont", &PyAcadPreferencesDisplay::textFont, DS.ARGS())
        .def("setTextFontStyle", &PyAcadPreferencesDisplay::setTextFontStyle, DS.ARGS({ "val:PyAx.AcTextFontStyle" }))
        .def("textFontStyle", &PyAcadPreferencesDisplay::textFontStyle, DS.ARGS())
        .def("setTextFontSize", &PyAcadPreferencesDisplay::setTextFontSize, DS.ARGS({ "val:int" }))
        .def("textFontSize", &PyAcadPreferencesDisplay::textFontSize, DS.ARGS())
        .def("setHistoryLines", &PyAcadPreferencesDisplay::setHistoryLines, DS.ARGS({ "val:int" }))
        .def("historyLines", &PyAcadPreferencesDisplay::historyLines, DS.ARGS())
        .def("setMaxAutoCADWindow", &PyAcadPreferencesDisplay::setMaxAutoCADWindow, DS.ARGS({ "val:bool" }))
        .def("maxAutoCADWindow", &PyAcadPreferencesDisplay::maxAutoCADWindow, DS.ARGS())
        .def("setDisplayLayoutTabs", &PyAcadPreferencesDisplay::setDisplayLayoutTabs, DS.ARGS({ "val:bool" }))
        .def("displayLayoutTabs", &PyAcadPreferencesDisplay::displayLayoutTabs, DS.ARGS())
        .def("setImageFrameHighlight", &PyAcadPreferencesDisplay::setImageFrameHighlight, DS.ARGS({ "val:bool" }))
        .def("imageFrameHighlight", &PyAcadPreferencesDisplay::imageFrameHighlight, DS.ARGS())
        .def("setTrueColorImages", &PyAcadPreferencesDisplay::setTrueColorImages, DS.ARGS({ "val:bool" }))
        .def("trueColorImages", &PyAcadPreferencesDisplay::trueColorImages, DS.ARGS())
        .def("setXRefFadeIntensity", &PyAcadPreferencesDisplay::setXRefFadeIntensity, DS.ARGS({ "val:bool" }))
        .def("xrefFadeIntensity", &PyAcadPreferencesDisplay::xrefFadeIntensity, DS.ARGS())
        .def("className", &PyAcadPreferencesDisplay::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadPreferencesDisplay::PyAcadPreferencesDisplay(std::shared_ptr<PyIAcadPreferencesDisplayImpl> ptr)
    : m_pyImp(ptr)
{
}

void PyAcadPreferencesDisplay::setLayoutDisplayMargins(bool val) const
{
    impObj()->SetLayoutDisplayMargins(val);
}

bool PyAcadPreferencesDisplay::layoutDisplayMargins() const
{
    return impObj()->GetLayoutDisplayMargins();
}

void PyAcadPreferencesDisplay::setLayoutDisplayPaper(bool val) const
{
    impObj()->SetLayoutDisplayPaper(val);
}

bool PyAcadPreferencesDisplay::layoutDisplayPaper() const
{
    return impObj()->GetLayoutDisplayPaper();
}

void PyAcadPreferencesDisplay::setLayoutDisplayPaperShadow(bool val) const
{
    impObj()->SetLayoutDisplayPaperShadow(val);
}

bool PyAcadPreferencesDisplay::layoutDisplayPaperShadow() const
{
    return impObj()->GetLayoutDisplayPaperShadow();
}

void PyAcadPreferencesDisplay::setLayoutShowPlotSetup(bool val) const
{
    impObj()->SetLayoutShowPlotSetup(val);
}

bool PyAcadPreferencesDisplay::layoutShowPlotSetup() const
{
    return impObj()->GetLayoutShowPlotSetup();
}

void PyAcadPreferencesDisplay::setLayoutCreateViewport(bool val) const
{
    impObj()->SetLayoutCreateViewport(val);
}

bool PyAcadPreferencesDisplay::layoutCreateViewport() const
{
    return impObj()->GetLayoutCreateViewport();
}

void PyAcadPreferencesDisplay::setDisplayScrollBars(bool val) const
{
    impObj()->SetDisplayScrollBars(val);
}

bool PyAcadPreferencesDisplay::displayScrollBars() const
{
    return impObj()->GetDisplayScrollBars();
}

void PyAcadPreferencesDisplay::setDisplayScreenMenu(bool val) const
{
    impObj()->SetDisplayScreenMenu(val);
}

bool PyAcadPreferencesDisplay::displayScreenMenu() const
{
    return impObj()->GetDisplayScreenMenu();
}

void PyAcadPreferencesDisplay::setCursorSize(int val) const
{
    impObj()->SetCursorSize(val);
}

int PyAcadPreferencesDisplay::cursorSize() const
{
    return impObj()->GetCursorSize();
}

void PyAcadPreferencesDisplay::setDockedVisibleLines(int val) const
{
    impObj()->SetDockedVisibleLines(val);
}

int PyAcadPreferencesDisplay::dockedVisibleLines() const
{
    return impObj()->GetDockedVisibleLines();
}

void PyAcadPreferencesDisplay::setShowRasterImage(bool val) const
{
    impObj()->SetShowRasterImage(val);
}

bool PyAcadPreferencesDisplay::showRasterImage() const
{
    return impObj()->GetDockedVisibleLines();
}

void PyAcadPreferencesDisplay::setGraphicsWinModelBackgrndColor(const boost::python::tuple& val) const
{
    impObj()->SetGraphicsWinModelBackgrndColor(PyTupleToColorRef(val));
}

boost::python::tuple PyAcadPreferencesDisplay::graphicsWinModelBackgrndColor() const
{
    return ColorRefToPyTuple(impObj()->GetGraphicsWinModelBackgrndColor());
}

void PyAcadPreferencesDisplay::setModelCrosshairColor(const boost::python::tuple& val) const
{
    impObj()->SetModelCrosshairColor(PyTupleToColorRef(val));
}

boost::python::tuple PyAcadPreferencesDisplay::modelCrosshairColor() const
{
    return ColorRefToPyTuple(impObj()->GetModelCrosshairColor());
}

void PyAcadPreferencesDisplay::setGraphicsWinLayoutBackgrndColor(const boost::python::tuple& val) const
{
    impObj()->SetGraphicsWinLayoutBackgrndColor(PyTupleToColorRef(val));
}

boost::python::tuple PyAcadPreferencesDisplay::graphicsWinLayoutBackgrndColor() const
{
    return ColorRefToPyTuple(impObj()->GetGraphicsWinLayoutBackgrndColor());
}

void PyAcadPreferencesDisplay::setTextWinBackgrndColor(const boost::python::tuple& val) const
{
    impObj()->SetTextWinBackgrndColor(PyTupleToColorRef(val));
}

boost::python::tuple PyAcadPreferencesDisplay::textWinBackgrndColor() const
{
    return ColorRefToPyTuple(impObj()->GetTextWinBackgrndColor());
}

void PyAcadPreferencesDisplay::setTextWinTextColor(const boost::python::tuple& val) const
{
    impObj()->SetTextWinTextColor(PyTupleToColorRef(val));
}

boost::python::tuple PyAcadPreferencesDisplay::textWinTextColor() const
{
    return ColorRefToPyTuple(impObj()->GetTextWinTextColor());
}

void PyAcadPreferencesDisplay::setLayoutCrosshairColor(const boost::python::tuple& val) const
{
    impObj()->SetLayoutCrosshairColor(PyTupleToColorRef(val));
}

boost::python::tuple PyAcadPreferencesDisplay::layoutCrosshairColor() const
{
    return ColorRefToPyTuple(impObj()->GetLayoutCrosshairColor());
}

void PyAcadPreferencesDisplay::setAutoTrackingVecColor(const boost::python::tuple& val) const
{
    impObj()->SetAutoTrackingVecColor(PyTupleToColorRef(val));
}

boost::python::tuple PyAcadPreferencesDisplay::autoTrackingVecColor() const
{
    return ColorRefToPyTuple(impObj()->GetAutoTrackingVecColor());
}

void PyAcadPreferencesDisplay::setTextFont(const std::string& val) const
{
    impObj()->SetTextFont(utf8_to_wstr(val).c_str());
}

std::string PyAcadPreferencesDisplay::textFont() const
{
    return wstr_to_utf8(impObj()->GetTextFont());
}

void PyAcadPreferencesDisplay::setTextFontStyle(const PyAcTextFontStyle& val) const
{
    impObj()->SetTextFontStyle(val);
}

PyAcTextFontStyle PyAcadPreferencesDisplay::textFontStyle() const
{
    return impObj()->GetTextFontStyle();
}

void PyAcadPreferencesDisplay::setTextFontSize(int val) const
{
    impObj()->SetTextFontSize(val);
}

int PyAcadPreferencesDisplay::textFontSize() const
{
    return impObj()->GetTextFontSize();
}

void PyAcadPreferencesDisplay::setHistoryLines(int val) const
{
    impObj()->SetHistoryLines(val);
}

int PyAcadPreferencesDisplay::historyLines() const
{
    return impObj()->GetHistoryLines();
}

void PyAcadPreferencesDisplay::setMaxAutoCADWindow(bool val) const
{
    impObj()->SetMaxAutoCADWindow(val);
}

bool PyAcadPreferencesDisplay::maxAutoCADWindow() const
{
    return impObj()->GetMaxAutoCADWindow();
}

void PyAcadPreferencesDisplay::setDisplayLayoutTabs(bool val) const
{
    impObj()->SetDisplayLayoutTabs(val);
}

bool PyAcadPreferencesDisplay::displayLayoutTabs() const
{
    return impObj()->GetDisplayLayoutTabs();
}

void PyAcadPreferencesDisplay::setImageFrameHighlight(bool val) const
{
    impObj()->SetImageFrameHighlight(val);
}

bool PyAcadPreferencesDisplay::imageFrameHighlight() const
{
    return impObj()->GetImageFrameHighlight();
}

void PyAcadPreferencesDisplay::setTrueColorImages(bool val) const
{
    impObj()->SetTrueColorImages(val);
}

bool PyAcadPreferencesDisplay::trueColorImages() const
{
    return impObj()->GetTrueColorImages();
}

void PyAcadPreferencesDisplay::setXRefFadeIntensity(long val) const
{
    impObj()->SetXRefFadeIntensity(val);
}

long PyAcadPreferencesDisplay::xrefFadeIntensity() const
{
    return impObj()->GetXRefFadeIntensity();
}

std::string PyAcadPreferencesDisplay::className()
{
    return "AcadPreferencesDisplay";
}

PyIAcadPreferencesDisplayImpl* PyAcadPreferencesDisplay::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return m_pyImp.get();
}

//----------------------------------------------------------------------------------------
//PyAcadPreferencesOpenSave
void makePyAcadPreferencesOpenSaveWrapper()
{
    PyDocString DS("AcadPreferencesOpenSave");
    class_<PyAcadPreferencesOpenSave>("AcadPreferencesOpenSave", boost::python::no_init)
        .def("setSavePreviewThumbnail", &PyAcadPreferencesOpenSave::setSavePreviewThumbnail, DS.ARGS({ "val:bool" }))
        .def("savePreviewThumbnail", &PyAcadPreferencesOpenSave::savePreviewThumbnail, DS.ARGS())
        .def("setIncrementalSavePercent", &PyAcadPreferencesOpenSave::setIncrementalSavePercent, DS.ARGS({ "val:int" }))
        .def("incrementalSavePercent", &PyAcadPreferencesOpenSave::incrementalSavePercent, DS.ARGS())
        .def("setAutoSaveInterval", &PyAcadPreferencesOpenSave::setAutoSaveInterval, DS.ARGS({ "val:int" }))
        .def("autoSaveInterval", &PyAcadPreferencesOpenSave::autoSaveInterval, DS.ARGS())
        .def("setCreateBackup", &PyAcadPreferencesOpenSave::setCreateBackup, DS.ARGS({ "val:bool" }))
        .def("createBackup", &PyAcadPreferencesOpenSave::createBackup, DS.ARGS())
        .def("setFullCRCValidation", &PyAcadPreferencesOpenSave::setFullCRCValidation, DS.ARGS({ "val:bool" }))
        .def("fullCRCValidation", &PyAcadPreferencesOpenSave::fullCRCValidation, DS.ARGS())
        .def("setLogFileOn", &PyAcadPreferencesOpenSave::setLogFileOn, DS.ARGS({ "val:bool" }))
        .def("logFileOn", &PyAcadPreferencesOpenSave::logFileOn, DS.ARGS())
        .def("setTempFileExtension", &PyAcadPreferencesOpenSave::setTempFileExtension, DS.ARGS({ "val:str" }))
        .def("tempFileExtension", &PyAcadPreferencesOpenSave::tempFileExtension, DS.ARGS())
        .def("setXrefDemandLoad", &PyAcadPreferencesOpenSave::setXrefDemandLoad, DS.ARGS({ "val:PyAx.AcXRefDemandLoad" }))
        .def("xrefDemandLoad", &PyAcadPreferencesOpenSave::xrefDemandLoad, DS.ARGS())
        .def("setDemandLoadARXApp", &PyAcadPreferencesOpenSave::setDemandLoadARXApp, DS.ARGS({ "val:PyAx.AcARXDemandLoad" }))
        .def("demandLoadARXApp", &PyAcadPreferencesOpenSave::demandLoadARXApp, DS.ARGS())
        .def("setProxyImage", &PyAcadPreferencesOpenSave::setProxyImage, DS.ARGS({ "val:PyAx.AcProxyImage" }))
        .def("proxyImage", &PyAcadPreferencesOpenSave::proxyImage, DS.ARGS())
        .def("setShowProxyDialogBox", &PyAcadPreferencesOpenSave::setShowProxyDialogBox, DS.ARGS({ "val:bool" }))
        .def("showProxyDialogBox", &PyAcadPreferencesOpenSave::showProxyDialogBox, DS.ARGS())
        .def("setAutoAudit", &PyAcadPreferencesOpenSave::setAutoAudit, DS.ARGS({ "val:bool" }))
        .def("autoAudit", &PyAcadPreferencesOpenSave::autoAudit, DS.ARGS())
        .def("setSaveAsType", &PyAcadPreferencesOpenSave::setSaveAsType, DS.ARGS({ "val:PyAx.AcSaveAsType" }))
        .def("saveAsType", &PyAcadPreferencesOpenSave::saveAsType, DS.ARGS())
        .def("mruNumber", &PyAcadPreferencesOpenSave::mruNumber, DS.ARGS())
        .def("className", &PyAcadPreferencesOpenSave::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadPreferencesOpenSave::PyAcadPreferencesOpenSave(std::shared_ptr<PyIAcadPreferencesOpenSaveImpl> ptr)
    : m_pyImp(ptr)
{
}

void PyAcadPreferencesOpenSave::setSavePreviewThumbnail(bool val) const
{
    impObj()->SetSavePreviewThumbnail(val);
}

bool PyAcadPreferencesOpenSave::savePreviewThumbnail() const
{
    return impObj()->GetSavePreviewThumbnail();
}

void PyAcadPreferencesOpenSave::setIncrementalSavePercent(int val) const
{
    impObj()->SetIncrementalSavePercent(val);
}

int PyAcadPreferencesOpenSave::incrementalSavePercent() const
{
    return impObj()->GetIncrementalSavePercent();
}

void PyAcadPreferencesOpenSave::setAutoSaveInterval(int val) const
{
    impObj()->SetAutoSaveInterval(val);
}

int PyAcadPreferencesOpenSave::autoSaveInterval() const
{
    return impObj()->GetAutoSaveInterval();
}

void PyAcadPreferencesOpenSave::setCreateBackup(bool val) const
{
    impObj()->SetCreateBackup(val);
}

bool PyAcadPreferencesOpenSave::createBackup() const
{
    return impObj()->GetCreateBackup();
}

void PyAcadPreferencesOpenSave::setFullCRCValidation(bool val) const
{
    impObj()->SetFullCRCValidation(val);
}

bool PyAcadPreferencesOpenSave::fullCRCValidation() const
{
    return impObj()->GetFullCRCValidation();
}

void PyAcadPreferencesOpenSave::setLogFileOn(bool val) const
{
    impObj()->SetLogFileOn(val);
}

bool PyAcadPreferencesOpenSave::logFileOn() const
{
    return impObj()->GetLogFileOn();
}

void PyAcadPreferencesOpenSave::setTempFileExtension(const std::string& val) const
{
    impObj()->SetTempFileExtension(utf8_to_wstr(val).c_str());
}

std::string PyAcadPreferencesOpenSave::tempFileExtension() const
{
    return wstr_to_utf8(impObj()->GetTempFileExtension());
}

void PyAcadPreferencesOpenSave::setXrefDemandLoad(PyAcXRefDemandLoad val) const
{
    impObj()->SetXrefDemandLoad(val);
}

PyAcXRefDemandLoad PyAcadPreferencesOpenSave::xrefDemandLoad() const
{
    return impObj()->GetXrefDemandLoad();
}

void PyAcadPreferencesOpenSave::setDemandLoadARXApp(PyAcARXDemandLoad val) const
{
    impObj()->SetDemandLoadARXApp(val);
}

PyAcARXDemandLoad PyAcadPreferencesOpenSave::demandLoadARXApp() const
{
    return impObj()->GetDemandLoadARXApp();
}

void PyAcadPreferencesOpenSave::setProxyImage(PyAcProxyImage val) const
{
    impObj()->SetProxyImage(val);
}

PyAcProxyImage PyAcadPreferencesOpenSave::proxyImage() const
{
    return impObj()->GetProxyImage();
}

void PyAcadPreferencesOpenSave::setShowProxyDialogBox(bool val) const
{
    impObj()->SetShowProxyDialogBox(val);
}

bool PyAcadPreferencesOpenSave::showProxyDialogBox() const
{
    return impObj()->GetShowProxyDialogBox();
}

void PyAcadPreferencesOpenSave::setAutoAudit(bool val) const
{
    impObj()->SetAutoAudit(val);
}

bool PyAcadPreferencesOpenSave::autoAudit() const
{
    return impObj()->GetAutoAudit();
}

void PyAcadPreferencesOpenSave::setSaveAsType(PyAcSaveAsType val) const
{
    impObj()->SetSaveAsType(val);
}

PyAcSaveAsType PyAcadPreferencesOpenSave::saveAsType() const
{
    return impObj()->GetSaveAsType();
}

long PyAcadPreferencesOpenSave::mruNumber() const
{
    return impObj()->GetMRUNumber();
}

std::string PyAcadPreferencesOpenSave::className()
{
    return "AcadPreferencesOpenSave";
}

PyIAcadPreferencesOpenSaveImpl* PyAcadPreferencesOpenSave::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return m_pyImp.get();
}

//----------------------------------------------------------------------------------------
//PyAcadPreferencesOutput
void makePyAcadPreferencesOutputWrapper()
{
    PyDocString DS("AcadPreferencesOutput");
    class_<PyAcadPreferencesOutput>("AcadPreferencesOutput", boost::python::no_init)
        .def("setDefaultOutputDevice", &PyAcadPreferencesOutput::setDefaultOutputDevice, DS.ARGS({ "val:str" }))
        .def("defaultOutputDevice", &PyAcadPreferencesOutput::defaultOutputDevice, DS.ARGS())
        .def("setPrinterSpoolAlert", &PyAcadPreferencesOutput::setPrinterSpoolAlert, DS.ARGS({ "val:PyAx.AcPrinterSpoolAlert" }))
        .def("printerSpoolAlert", &PyAcadPreferencesOutput::printerSpoolAlert, DS.ARGS())
        .def("setPrinterPaperSizeAlert", &PyAcadPreferencesOutput::setPrinterPaperSizeAlert, DS.ARGS({ "val:bool" }))
        .def("printerPaperSizeAlert", &PyAcadPreferencesOutput::printerPaperSizeAlert, DS.ARGS())
        .def("setPlotLegacy", &PyAcadPreferencesOutput::setPlotLegacy, DS.ARGS({ "val:bool" }))
        .def("plotLegacy", &PyAcadPreferencesOutput::plotLegacy, DS.ARGS())
        .def("setOLEQuality", &PyAcadPreferencesOutput::setOLEQuality, DS.ARGS({ "val:PyAx.AcOleQuality" }))
        .def("oleQuality", &PyAcadPreferencesOutput::oleQuality, DS.ARGS())
        .def("setUseLastPlotSettings", &PyAcadPreferencesOutput::setUseLastPlotSettings, DS.ARGS({ "val:bool" }))
        .def("useLastPlotSettings", &PyAcadPreferencesOutput::useLastPlotSettings, DS.ARGS())
        .def("setPlotPolicy", &PyAcadPreferencesOutput::setPlotPolicy, DS.ARGS({ "val:PyAx.AcPlotPolicy" }))
        .def("plotPolicy", &PyAcadPreferencesOutput::plotPolicy, DS.ARGS())
        .def("setDefaultPlotStyleTable", &PyAcadPreferencesOutput::setDefaultPlotStyleTable, DS.ARGS({ "val:str" }))
        .def("defaultPlotStyleTable", &PyAcadPreferencesOutput::defaultPlotStyleTable, DS.ARGS())
        .def("setDefaultPlotStyleForObjects", &PyAcadPreferencesOutput::setDefaultPlotStyleForObjects, DS.ARGS({ "val:str" }))
        .def("defaultPlotStyleForObjects", &PyAcadPreferencesOutput::defaultPlotStyleForObjects, DS.ARGS())
        .def("setDefaultPlotStyleForLayer", &PyAcadPreferencesOutput::setDefaultPlotStyleForLayer, DS.ARGS({ "val:str" }))
        .def("defaultPlotStyleForLayer", &PyAcadPreferencesOutput::defaultPlotStyleForLayer, DS.ARGS())
        .def("setContinuousPlotLog", &PyAcadPreferencesOutput::setContinuousPlotLog, DS.ARGS({ "val:bool" }))
        .def("continuousPlotLog", &PyAcadPreferencesOutput::continuousPlotLog, DS.ARGS())
        .def("setAutomaticPlotLog", &PyAcadPreferencesOutput::setAutomaticPlotLog, DS.ARGS({ "val:bool" }))
        .def("automaticPlotLog", &PyAcadPreferencesOutput::automaticPlotLog, DS.ARGS())
        .def("setDefaultPlotToFilePath", &PyAcadPreferencesOutput::setDefaultPlotToFilePath, DS.ARGS({ "val:str" }))
        .def("defaultPlotToFilePath", &PyAcadPreferencesOutput::defaultPlotToFilePath, DS.ARGS())
        .def("className", &PyAcadPreferencesOutput::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadPreferencesOutput::PyAcadPreferencesOutput(std::shared_ptr<PyIAcadPreferencesOutputImpl> ptr)
    : m_pyImp(ptr)
{
}

void PyAcadPreferencesOutput::setDefaultOutputDevice(const std::string& val) const
{
    impObj()->SetDefaultOutputDevice(utf8_to_wstr(val).c_str());
}

std::string PyAcadPreferencesOutput::defaultOutputDevice() const
{
    return wstr_to_utf8(impObj()->GetDefaultOutputDevice());
}

void PyAcadPreferencesOutput::setPrinterSpoolAlert(PyAcPrinterSpoolAlert val) const
{
    impObj()->SetPrinterSpoolAlert(val);
}

PyAcPrinterSpoolAlert PyAcadPreferencesOutput::printerSpoolAlert() const
{
    return impObj()->GetPrinterSpoolAlert();
}

void PyAcadPreferencesOutput::setPrinterPaperSizeAlert(bool val) const
{
    impObj()->SetPrinterPaperSizeAlert(val);
}

bool PyAcadPreferencesOutput::printerPaperSizeAlert() const
{
    return impObj()->GetPrinterPaperSizeAlert();
}

void PyAcadPreferencesOutput::setPlotLegacy(bool val) const
{
    impObj()->SetPlotLegacy(val);
}

bool PyAcadPreferencesOutput::plotLegacy() const
{
    return impObj()->GetPlotLegacy();
}

void PyAcadPreferencesOutput::setOLEQuality(PyAcOleQuality val) const
{
    impObj()->SetOLEQuality(val);
}

PyAcOleQuality PyAcadPreferencesOutput::oleQuality() const
{
    return impObj()->GetOLEQuality();
}

void PyAcadPreferencesOutput::setUseLastPlotSettings(bool val) const
{
    impObj()->SetUseLastPlotSettings(val);
}

bool PyAcadPreferencesOutput::useLastPlotSettings() const
{
    return impObj()->GetUseLastPlotSettings();
}

void PyAcadPreferencesOutput::setPlotPolicy(PyAcPlotPolicy val) const
{
    impObj()->SetPlotPolicy(val);
}

PyAcPlotPolicy PyAcadPreferencesOutput::plotPolicy() const
{
    return impObj()->GetPlotPolicy();
}

void PyAcadPreferencesOutput::setDefaultPlotStyleTable(const std::string& val) const
{
    impObj()->SetDefaultPlotStyleTable(utf8_to_wstr(val).c_str());
}

std::string PyAcadPreferencesOutput::defaultPlotStyleTable() const
{
    return wstr_to_utf8(impObj()->GetDefaultPlotStyleTable());
}

void PyAcadPreferencesOutput::setDefaultPlotStyleForObjects(const std::string& val) const
{
    impObj()->SetDefaultPlotStyleForObjects(utf8_to_wstr(val).c_str());
}

std::string PyAcadPreferencesOutput::defaultPlotStyleForObjects() const
{
    return wstr_to_utf8(impObj()->GetDefaultPlotStyleForObjects());
}

void PyAcadPreferencesOutput::setDefaultPlotStyleForLayer(const std::string& val) const
{
    impObj()->SetDefaultPlotStyleForLayer(utf8_to_wstr(val).c_str());
}

std::string PyAcadPreferencesOutput::defaultPlotStyleForLayer() const
{
    return wstr_to_utf8(impObj()->GetDefaultPlotStyleForLayer());
}

void PyAcadPreferencesOutput::setContinuousPlotLog(bool val) const
{
    impObj()->SetContinuousPlotLog(val);
}

bool PyAcadPreferencesOutput::continuousPlotLog() const
{
    return impObj()->GetContinuousPlotLog();
}

void PyAcadPreferencesOutput::setAutomaticPlotLog(bool val) const
{
    impObj()->SetAutomaticPlotLog(val);
}

bool PyAcadPreferencesOutput::automaticPlotLog() const
{
    return impObj()->GetAutomaticPlotLog();
}

void PyAcadPreferencesOutput::setDefaultPlotToFilePath(const std::string& val) const
{
    impObj()->SetDefaultPlotToFilePath(utf8_to_wstr(val).c_str());
}

std::string PyAcadPreferencesOutput::defaultPlotToFilePath() const
{
    return wstr_to_utf8(impObj()->GetDefaultPlotToFilePath());
}

std::string PyAcadPreferencesOutput::className()
{
    return "AcadPreferencesOutput";
}

PyIAcadPreferencesOutputImpl* PyAcadPreferencesOutput::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return m_pyImp.get();
}

//----------------------------------------------------------------------------------------
//PyAcadPreferencesSystem
void makePyAcadPreferencesSystemWrapper()
{
    PyDocString DS("AcadPreferencesSystem");
    class_<PyAcadPreferencesSystem>("AcadPreferencesSystem", boost::python::no_init)
        .def("setSingleDocumentMode", &PyAcadPreferencesSystem::setSingleDocumentMode, DS.ARGS({ "val:bool" }))
        .def("singleDocumentMode", &PyAcadPreferencesSystem::singleDocumentMode, DS.ARGS())
        .def("setDisplayOLEScale", &PyAcadPreferencesSystem::setDisplayOLEScale, DS.ARGS({ "val:bool" }))
        .def("displayOLEScale", &PyAcadPreferencesSystem::displayOLEScale, DS.ARGS())
        .def("setStoreSQLIndex", &PyAcadPreferencesSystem::setStoreSQLIndex, DS.ARGS({ "val:bool" }))
        .def("storeSQLIndex", &PyAcadPreferencesSystem::storeSQLIndex, DS.ARGS())
        .def("setTablesReadOnly", &PyAcadPreferencesSystem::setTablesReadOnly, DS.ARGS({ "val:bool" }))
        .def("tablesReadOnly", &PyAcadPreferencesSystem::tablesReadOnly, DS.ARGS())
        .def("setEnableStartupDialog", &PyAcadPreferencesSystem::setEnableStartupDialog, DS.ARGS({ "val:bool" }))
        .def("enableStartupDialog", &PyAcadPreferencesSystem::enableStartupDialog, DS.ARGS())
        .def("setBeepOnError", &PyAcadPreferencesSystem::setBeepOnError, DS.ARGS({ "val:bool" }))
        .def("beepOnError", &PyAcadPreferencesSystem::beepOnError, DS.ARGS())
        .def("setShowWarningMessages", &PyAcadPreferencesSystem::setShowWarningMessages, DS.ARGS({ "val:bool" }))
        .def("showWarningMessages", &PyAcadPreferencesSystem::showWarningMessages, DS.ARGS())
        .def("setLoadAcadLspInAllDocuments", &PyAcadPreferencesSystem::setLoadAcadLspInAllDocuments, DS.ARGS({ "val:bool" }))
        .def("loadAcadLspInAllDocuments", &PyAcadPreferencesSystem::loadAcadLspInAllDocuments, DS.ARGS())
        .def("className", &PyAcadPreferencesSystem::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadPreferencesSystem::PyAcadPreferencesSystem(std::shared_ptr<PyIAcadPreferencesSystemImpl> ptr)
    : m_pyImp(ptr)
{
}

void PyAcadPreferencesSystem::setSingleDocumentMode(bool val) const
{
    impObj()->SetSingleDocumentMode(val);
}

bool PyAcadPreferencesSystem::singleDocumentMode() const
{
    return impObj()->GetSingleDocumentMode();
}

void PyAcadPreferencesSystem::setDisplayOLEScale(bool val) const
{
    impObj()->SetDisplayOLEScale(val);
}

bool PyAcadPreferencesSystem::displayOLEScale() const
{
    return impObj()->GetDisplayOLEScale();
}

void PyAcadPreferencesSystem::setStoreSQLIndex(bool val) const
{
    impObj()->SetStoreSQLIndex(val);
}

bool PyAcadPreferencesSystem::storeSQLIndex() const
{
    return impObj()->GetStoreSQLIndex();
}

void PyAcadPreferencesSystem::setTablesReadOnly(bool val) const
{
    impObj()->SetTablesReadOnly(val);
}

bool PyAcadPreferencesSystem::tablesReadOnly() const
{
    return impObj()->GetTablesReadOnly();
}

void PyAcadPreferencesSystem::setEnableStartupDialog(bool val) const
{
    impObj()->SetEnableStartupDialog(val);
}

bool PyAcadPreferencesSystem::enableStartupDialog() const
{
    return impObj()->GetEnableStartupDialog();
}

void PyAcadPreferencesSystem::setBeepOnError(bool val) const
{
    impObj()->SetBeepOnError(val);
}

bool PyAcadPreferencesSystem::beepOnError() const
{
    return impObj()->GetBeepOnError();
}

void PyAcadPreferencesSystem::setShowWarningMessages(bool val) const
{
    impObj()->SetShowWarningMessages(val);
}

bool PyAcadPreferencesSystem::showWarningMessages() const
{
    return impObj()->GetShowWarningMessages();
}

void PyAcadPreferencesSystem::setLoadAcadLspInAllDocuments(bool val) const
{
    impObj()->SetLoadAcadLspInAllDocuments(val);
}

bool PyAcadPreferencesSystem::loadAcadLspInAllDocuments() const
{
    return impObj()->GetLoadAcadLspInAllDocuments();
}

std::string PyAcadPreferencesSystem::className()
{
    return "AcadPreferencesSystem";
}

PyIAcadPreferencesSystemImpl* PyAcadPreferencesSystem::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return m_pyImp.get();
}

//----------------------------------------------------------------------------------------
//PyAcadPreferencesUser
void makePyAcadPreferencesUserWrapper()
{
    PyDocString DS("AcadPreferencesUser");
    class_<PyAcadPreferencesUser>("AcadPreferencesUser", boost::python::no_init)
        .def("setKeyboardAccelerator", &PyAcadPreferencesUser::setKeyboardAccelerator, DS.ARGS({ "val:PyAx.AcKeyboardAccelerator" }))
        .def("keyboardAccelerator", &PyAcadPreferencesUser::keyboardAccelerator, DS.ARGS())
        .def("setKeyboardPriority", &PyAcadPreferencesUser::setKeyboardPriority, DS.ARGS({ "val:PyAx.AcKeyboardPriority" }))
        .def("keyboardPriority", &PyAcadPreferencesUser::keyboardPriority, DS.ARGS())
        .def("setHyperlinkDisplayCursor", &PyAcadPreferencesUser::setHyperlinkDisplayCursor, DS.ARGS({ "val:bool" }))
        .def("hyperlinkDisplayCursor", &PyAcadPreferencesUser::hyperlinkDisplayCursor, DS.ARGS())
        .def("setADCInsertUnitsDefaultSource", &PyAcadPreferencesUser::setADCInsertUnitsDefaultSource, DS.ARGS({ "val:PyAx.AcInsertUnits" }))
        .def("adcInsertUnitsDefaultSource", &PyAcadPreferencesUser::adcInsertUnitsDefaultSource, DS.ARGS())
        .def("setADCInsertUnitsDefaultTarget", &PyAcadPreferencesUser::setADCInsertUnitsDefaultTarget, DS.ARGS({ "val:PyAx.AcInsertUnits" }))
        .def("adcInsertUnitsDefaultTarget", &PyAcadPreferencesUser::adcInsertUnitsDefaultTarget, DS.ARGS())
        .def("setShortCutMenuDisplay", &PyAcadPreferencesUser::setShortCutMenuDisplay, DS.ARGS({ "val:bool" }))
        .def("shortCutMenuDisplay", &PyAcadPreferencesUser::shortCutMenuDisplay, DS.ARGS())
        .def("setSCMDefaultMode", &PyAcadPreferencesUser::setSCMDefaultMode, DS.ARGS({ "val:PyAx.AcDrawingAreaSCMDefault" }))
        .def("scmDefaultMode", &PyAcadPreferencesUser::scmDefaultMode, DS.ARGS())
        .def("setSCMEditMode", &PyAcadPreferencesUser::setSCMEditMode, DS.ARGS({ "val:PyAx.AcDrawingAreaSCMEdit" }))
        .def("acmEditMode", &PyAcadPreferencesUser::acmEditMode, DS.ARGS())
        .def("setSCMCommandMode", &PyAcadPreferencesUser::setSCMCommandMode, DS.ARGS({ "val:PyAx.AcDrawingAreaSCMCommand" }))
        .def("scmCommandMode", &PyAcadPreferencesUser::scmCommandMode, DS.ARGS())
        .def("setSCMTimeMode", &PyAcadPreferencesUser::setSCMTimeMode, DS.ARGS({ "val:bool" }))
        .def("scmTimeMode", &PyAcadPreferencesUser::scmTimeMode, DS.ARGS())
        .def("setSCMTimeValue", &PyAcadPreferencesUser::setSCMTimeValue, DS.ARGS({ "val:int" }))
        .def("scmTimeValue", &PyAcadPreferencesUser::scmTimeValue, DS.ARGS())
        .def("className", &PyAcadPreferencesUser::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadPreferencesUser::PyAcadPreferencesUser(std::shared_ptr<PyIAcadPreferencesUserImpl> ptr)
    : m_pyImp(ptr)
{
}

void PyAcadPreferencesUser::setKeyboardAccelerator(PyAcKeyboardAccelerator val) const
{
    impObj()->SetKeyboardAccelerator(val);
}

PyAcKeyboardAccelerator PyAcadPreferencesUser::keyboardAccelerator() const
{
    return impObj()->GetKeyboardAccelerator();
}

void PyAcadPreferencesUser::setKeyboardPriority(PyAcKeyboardPriority val) const
{
    impObj()->SetKeyboardPriority(val);
}

PyAcKeyboardPriority PyAcadPreferencesUser::keyboardPriority() const
{
    return impObj()->GetKeyboardPriority();
}

void PyAcadPreferencesUser::setHyperlinkDisplayCursor(bool val) const
{
    impObj()->SetHyperlinkDisplayCursor(val);
}

bool PyAcadPreferencesUser::hyperlinkDisplayCursor() const
{
    return impObj()->GetHyperlinkDisplayCursor();
}

void PyAcadPreferencesUser::setADCInsertUnitsDefaultSource(PyAcInsertUnits val) const
{
    impObj()->SetADCInsertUnitsDefaultSource(val);
}

PyAcInsertUnits PyAcadPreferencesUser::adcInsertUnitsDefaultSource() const
{
    return impObj()->GetADCInsertUnitsDefaultSource();
}

void PyAcadPreferencesUser::setADCInsertUnitsDefaultTarget(PyAcInsertUnits val) const
{
    impObj()->SetADCInsertUnitsDefaultTarget(val);
}

PyAcInsertUnits PyAcadPreferencesUser::adcInsertUnitsDefaultTarget() const
{
    return impObj()->GetADCInsertUnitsDefaultTarget();
}

void PyAcadPreferencesUser::setShortCutMenuDisplay(bool val) const
{
    impObj()->SetShortCutMenuDisplay(val);
}

bool PyAcadPreferencesUser::shortCutMenuDisplay() const
{
    return impObj()->GetShortCutMenuDisplay();
}

void PyAcadPreferencesUser::setSCMDefaultMode(PyAcDrawingAreaSCMDefault val) const
{
    impObj()->SetSCMDefaultMode(val);
}

PyAcDrawingAreaSCMDefault PyAcadPreferencesUser::scmDefaultMode() const
{
    return impObj()->GetSCMDefaultMode();
}

void PyAcadPreferencesUser::setSCMEditMode(PyAcDrawingAreaSCMEdit val) const
{
    impObj()->SetSCMEditMode(val);
}

PyAcDrawingAreaSCMEdit PyAcadPreferencesUser::acmEditMode() const
{
    return impObj()->GetSCMEditMode();
}

void PyAcadPreferencesUser::setSCMCommandMode(PyAcDrawingAreaSCMCommand val) const
{
    impObj()->SetSCMCommandMode(val);
}

PyAcDrawingAreaSCMCommand PyAcadPreferencesUser::scmCommandMode() const
{
    return impObj()->GetSCMCommandMode();
}

void PyAcadPreferencesUser::setSCMTimeMode(bool val) const
{
    impObj()->SetSCMTimeMode(val);
}

bool PyAcadPreferencesUser::scmTimeMode() const
{
    return impObj()->GetSCMTimeMode();
}

void PyAcadPreferencesUser::setSCMTimeValue(int val) const
{
    impObj()->SetSCMTimeValue(val);
}

int PyAcadPreferencesUser::scmTimeValue() const
{
    return impObj()->GetSCMTimeValue();
}

std::string PyAcadPreferencesUser::className()
{
    return "AcadPreferencesUser";
}

PyIAcadPreferencesUserImpl* PyAcadPreferencesUser::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return m_pyImp.get();
}

//----------------------------------------------------------------------------------------
//PyAcadPreferencesDrafting
void makePyAcadPreferencesDraftingWrapper()
{
    PyDocString DS("AcadPreferencesDrafting");
    class_<PyAcadPreferencesDrafting>("AcadPreferencesDrafting", boost::python::no_init)
        .def("setAutoSnapMarker", &PyAcadPreferencesDrafting::setAutoSnapMarker, DS.ARGS({ "flag:bool" }))
        .def("autoSnapMarker", &PyAcadPreferencesDrafting::autoSnapMarker, DS.ARGS())
        .def("setAutoSnapMagnet", &PyAcadPreferencesDrafting::setAutoSnapMagnet, DS.ARGS({ "flag:bool" }))
        .def("autoSnapMagnet", &PyAcadPreferencesDrafting::autoSnapMagnet, DS.ARGS())
        .def("setAutoSnapTooltip", &PyAcadPreferencesDrafting::setAutoSnapTooltip, DS.ARGS({ "flag:bool" }))
        .def("autoSnapTooltip", &PyAcadPreferencesDrafting::autoSnapTooltip, DS.ARGS())
        .def("setAutoSnapAperture", &PyAcadPreferencesDrafting::setAutoSnapAperture, DS.ARGS({ "flag:bool" }))
        .def("autoSnapAperture", &PyAcadPreferencesDrafting::autoSnapAperture, DS.ARGS())
        .def("setAutoSnapApertureSize", &PyAcadPreferencesDrafting::setAutoSnapApertureSize, DS.ARGS({ "flag:int" }))
        .def("autoSnapApertureSize", &PyAcadPreferencesDrafting::autoSnapApertureSize, DS.ARGS())
        .def("setAutoSnapMarkerColor", &PyAcadPreferencesDrafting::setAutoSnapMarkerColor, DS.ARGS({ "flag:PyAx.AcColor" }))
        .def("autoSnapMarkerColor", &PyAcadPreferencesDrafting::autoSnapMarkerColor, DS.ARGS())
        .def("setAutoSnapMarkerSize", &PyAcadPreferencesDrafting::setAutoSnapMarkerSize, DS.ARGS({ "flag:int" }))
        .def("autoSnapMarkerSize", &PyAcadPreferencesDrafting::autoSnapMarkerSize, DS.ARGS())
        .def("setPolarTrackingVector", &PyAcadPreferencesDrafting::setPolarTrackingVector, DS.ARGS({ "flag:bool" }))
        .def("polarTrackingVector", &PyAcadPreferencesDrafting::polarTrackingVector, DS.ARGS())
        .def("setFullScreenTrackingVector", &PyAcadPreferencesDrafting::setFullScreenTrackingVector, DS.ARGS({ "flag:bool" }))
        .def("fullScreenTrackingVector", &PyAcadPreferencesDrafting::fullScreenTrackingVector, DS.ARGS())
        .def("setAutoTrackTooltip", &PyAcadPreferencesDrafting::setAutoTrackTooltip, DS.ARGS({ "flag:bool" }))
        .def("autoTrackTooltip", &PyAcadPreferencesDrafting::autoTrackTooltip, DS.ARGS())
        .def("setAlignmentPointAcquisition", &PyAcadPreferencesDrafting::setAlignmentPointAcquisition, DS.ARGS({ "flag:PyAx.AcAlignmentPointAcquisition" }))
        .def("alignmentPointAcquisition", &PyAcadPreferencesDrafting::alignmentPointAcquisition, DS.ARGS())
        .def("className", &PyAcadPreferencesDrafting::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadPreferencesDrafting::PyAcadPreferencesDrafting(std::shared_ptr<PyIAcadPreferencesDraftingImpl> ptr)
    : m_pyImp(ptr)
{
}

void PyAcadPreferencesDrafting::setAutoSnapMarker(bool val) const
{
    impObj()->SetAutoSnapMarker(val);
}

bool PyAcadPreferencesDrafting::autoSnapMarker() const
{
    return impObj()->GetAutoSnapMarker();
}

void PyAcadPreferencesDrafting::setAutoSnapMagnet(bool val) const
{
    impObj()->SetAutoSnapMagnet(val);
}

bool PyAcadPreferencesDrafting::autoSnapMagnet() const
{
    return impObj()->GetAutoSnapMagnet();
}

void PyAcadPreferencesDrafting::setAutoSnapTooltip(bool val) const
{
    impObj()->SetAutoSnapTooltip(val);
}

bool PyAcadPreferencesDrafting::autoSnapTooltip() const
{
    return impObj()->GetAutoSnapTooltip();
}

void PyAcadPreferencesDrafting::setAutoSnapAperture(bool val) const
{
    impObj()->SetAutoSnapAperture(val);
}

bool PyAcadPreferencesDrafting::autoSnapAperture() const
{
    return impObj()->GetAutoSnapAperture();
}

void PyAcadPreferencesDrafting::setAutoSnapApertureSize(long val) const
{
    impObj()->SetAutoSnapApertureSize(val);
}

long PyAcadPreferencesDrafting::autoSnapApertureSize() const
{
    return impObj()->GetAutoSnapApertureSize();
}

void PyAcadPreferencesDrafting::setAutoSnapMarkerColor(PyAcColor val) const
{
    impObj()->SetAutoSnapMarkerColor(val);
}

PyAcColor PyAcadPreferencesDrafting::autoSnapMarkerColor() const
{
    return impObj()->GetAutoSnapMarkerColor();
}

void PyAcadPreferencesDrafting::setAutoSnapMarkerSize(long val) const
{
    impObj()->SetAutoSnapMarkerSize(val);
}

long PyAcadPreferencesDrafting::autoSnapMarkerSize() const
{
    return impObj()->GetAutoSnapMarkerSize();
}

void PyAcadPreferencesDrafting::setPolarTrackingVector(bool val) const
{
    impObj()->SetPolarTrackingVector(val);
}

bool PyAcadPreferencesDrafting::polarTrackingVector() const
{
    return impObj()->GetPolarTrackingVector();
}

void PyAcadPreferencesDrafting::setFullScreenTrackingVector(bool val) const
{
    impObj()->SetFullScreenTrackingVector(val);
}

bool PyAcadPreferencesDrafting::fullScreenTrackingVector() const
{
    return impObj()->GetFullScreenTrackingVector();
}

void PyAcadPreferencesDrafting::setAutoTrackTooltip(bool val) const
{
    impObj()->SetAutoTrackTooltip(val);
}

bool PyAcadPreferencesDrafting::autoTrackTooltip() const
{
    return impObj()->GetAutoTrackTooltip();
}

void PyAcadPreferencesDrafting::setAlignmentPointAcquisition(PyAcAlignmentPointAcquisition val) const
{
    impObj()->SetAlignmentPointAcquisition(val);
}

PyAcAlignmentPointAcquisition PyAcadPreferencesDrafting::alignmentPointAcquisition() const
{
    return impObj()->GetAlignmentPointAcquisition();
}

std::string PyAcadPreferencesDrafting::className()
{
    return "AcadPreferencesDrafting";
}

PyIAcadPreferencesDraftingImpl* PyAcadPreferencesDrafting::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return m_pyImp.get();
}

//----------------------------------------------------------------------------------------
//PyAcadPreferencesSelection
void makePyAcadPreferencesSelectionWrapper()
{
    PyDocString DS("AcadPreferencesSelection");
    class_<PyAcadPreferencesSelection>("AcadPreferencesSelection", boost::python::no_init)
        .def("setPickFirst", &PyAcadPreferencesSelection::setPickFirst, DS.ARGS({ "flag:bool" }))
        .def("pickFirst", &PyAcadPreferencesSelection::pickFirst, DS.ARGS())
        .def("setPickAdd", &PyAcadPreferencesSelection::setPickAdd, DS.ARGS({ "flag:bool" }))
        .def("pickAdd", &PyAcadPreferencesSelection::pickAdd, DS.ARGS())
        .def("setPickDrag", &PyAcadPreferencesSelection::setPickDrag, DS.ARGS({ "flag:bool" }))
        .def("pickDrag", &PyAcadPreferencesSelection::pickDrag, DS.ARGS())
        .def("setPickAuto", &PyAcadPreferencesSelection::setPickAuto, DS.ARGS({ "flag:bool" }))
        .def("pickAuto", &PyAcadPreferencesSelection::pickAuto, DS.ARGS())
        .def("setPickBoxSize", &PyAcadPreferencesSelection::setPickBoxSize, DS.ARGS({ "flag:int" }))
        .def("pickBoxSize", &PyAcadPreferencesSelection::pickBoxSize, DS.ARGS())
        .def("setDisplayGrips", &PyAcadPreferencesSelection::setDisplayGrips, DS.ARGS({ "flag:bool" }))
        .def("displayGrips", &PyAcadPreferencesSelection::displayGrips, DS.ARGS())
        .def("setDisplayGripsWithinBlocks", &PyAcadPreferencesSelection::setDisplayGripsWithinBlocks, DS.ARGS({ "flag:bool" }))
        .def("displayGripsWithinBlocks", &PyAcadPreferencesSelection::displayGripsWithinBlocks, DS.ARGS())
        .def("setGripColorSelected", &PyAcadPreferencesSelection::setGripColorSelected, DS.ARGS({ "clr:PyAx.AcColor" }))
        .def("gripColorSelected", &PyAcadPreferencesSelection::gripColorSelected, DS.ARGS())
        .def("setGripColorUnselected", &PyAcadPreferencesSelection::setGripColorUnselected, DS.ARGS({ "clr:PyAx.AcColor" }))
        .def("gripColorUnselected", &PyAcadPreferencesSelection::gripColorUnselected, DS.ARGS())
        .def("setGripSize", &PyAcadPreferencesSelection::setGripSize, DS.ARGS({ "flag:int" }))
        .def("gripSize", &PyAcadPreferencesSelection::gripSize, DS.ARGS())
        .def("setPickGroup", &PyAcadPreferencesSelection::setPickGroup, DS.ARGS({ "flag:bool" }))
        .def("pickGroup", &PyAcadPreferencesSelection::pickGroup, DS.ARGS())
        .def("className", &PyAcadPreferencesSelection::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadPreferencesSelection::PyAcadPreferencesSelection(std::shared_ptr<PyIAcadPreferencesSelectionImpl> ptr)
    : m_pyImp(ptr)
{
}

void PyAcadPreferencesSelection::setPickFirst(bool val) const
{
    impObj()->SetPickFirst(val);
}

bool PyAcadPreferencesSelection::pickFirst() const
{
    return impObj()->GetPickFirst();
}

void PyAcadPreferencesSelection::setPickAdd(bool val) const
{
    impObj()->SetPickAdd(val);
}

bool PyAcadPreferencesSelection::pickAdd() const
{
    return impObj()->GetPickAdd();
}

void PyAcadPreferencesSelection::setPickDrag(bool val) const
{
    impObj()->SetPickDrag(val);
}

bool PyAcadPreferencesSelection::pickDrag() const
{
    return impObj()->GetPickDrag();
}

void PyAcadPreferencesSelection::setPickAuto(bool val) const
{
    impObj()->SetPickAuto(val);
}

bool PyAcadPreferencesSelection::pickAuto() const
{
    return impObj()->GetPickAuto();
}

void PyAcadPreferencesSelection::setPickBoxSize(long val) const
{
    impObj()->SetPickBoxSize(val);
}

long PyAcadPreferencesSelection::pickBoxSize() const
{
    return impObj()->GetPickBoxSize();
}

void PyAcadPreferencesSelection::setDisplayGrips(bool val) const
{
    impObj()->SetDisplayGrips(val);
}

bool PyAcadPreferencesSelection::displayGrips() const
{
    return impObj()->GetDisplayGrips();
}

void PyAcadPreferencesSelection::setDisplayGripsWithinBlocks(bool val) const
{
    impObj()->SetDisplayGripsWithinBlocks(val);
}

bool PyAcadPreferencesSelection::displayGripsWithinBlocks() const
{
    return impObj()->GetDisplayGripsWithinBlocks();
}

void PyAcadPreferencesSelection::setGripColorSelected(PyAcColor val) const
{
    impObj()->SetGripColorSelected(val);
}

PyAcColor PyAcadPreferencesSelection::gripColorSelected() const
{
    return impObj()->GetGripColorSelected();
}

void PyAcadPreferencesSelection::setGripColorUnselected(PyAcColor val) const
{
    impObj()->SetGripColorUnselected(val);
}

PyAcColor PyAcadPreferencesSelection::gripColorUnselected() const
{
    return impObj()->GetGripColorUnselected();
}

void PyAcadPreferencesSelection::setGripSize(long val) const
{
    impObj()->SetGripSize(val);
}

long PyAcadPreferencesSelection::gripSize() const
{
    return impObj()->GetGripSize();
}

void PyAcadPreferencesSelection::setPickGroup(bool val) const
{
    impObj()->SetPickGroup(val);
}

bool PyAcadPreferencesSelection::pickGroup() const
{
    return impObj()->GetPickGroup();
}

std::string PyAcadPreferencesSelection::className()
{
    return "AcadPreferencesSelection";
}

PyIAcadPreferencesSelectionImpl* PyAcadPreferencesSelection::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return m_pyImp.get();
}

//----------------------------------------------------------------------------------------
//PyAcadPreferencesProfiles
void makePyAcadPreferencesProfilesWrapper()
{
    PyDocString DS("AcadPreferencesProfiles");
    class_<PyAcadPreferencesProfiles>("AcadPreferencesProfiles", boost::python::no_init)
        .def("activeProfile", &PyAcadPreferencesProfiles::activeProfile, DS.ARGS())
        .def("setActiveProfile", &PyAcadPreferencesProfiles::setActiveProfile, DS.ARGS({ "activeProfile:str" }))
        .def("importProfile", &PyAcadPreferencesProfiles::importProfile, DS.ARGS({ "profileName:str","regFile:str","IncludePathInfo:bool" }))
        .def("exportProfile", &PyAcadPreferencesProfiles::exportProfile, DS.ARGS({ "profileName:str","regFile:str" }))
        .def("deleteProfile", &PyAcadPreferencesProfiles::deleteProfile, DS.ARGS({ "profileName:str" }))
        .def("resetProfile", &PyAcadPreferencesProfiles::resetProfile, DS.ARGS({ "profile:str" }))
        .def("renameProfile", &PyAcadPreferencesProfiles::renameProfile, DS.ARGS({ "origProfileName:str", "newProfileName:str" }))
        .def("copyProfile", &PyAcadPreferencesProfiles::copyProfile, DS.ARGS({ "oldProfileName:str", "newProfileName:str" }))
        .def("getAllProfileNames", &PyAcadPreferencesProfiles::getAllProfileNames, DS.ARGS())
        .def("className", &PyAcadPreferencesProfiles::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadPreferencesProfiles::PyAcadPreferencesProfiles(std::shared_ptr<PyIAcadPreferencesProfilesImpl> ptr)
    : m_pyImp(ptr)
{
}

std::string PyAcadPreferencesProfiles::activeProfile() const
{
    return wstr_to_utf8(impObj()->GetActiveProfile());
}

void PyAcadPreferencesProfiles::setActiveProfile(const std::string& str) const
{
    impObj()->SetActiveProfile(utf8_to_wstr(str).c_str());
}

void PyAcadPreferencesProfiles::importProfile(const std::string& ProfileName, const std::string& RegFile, bool IncludePathInfo) const
{
    impObj()->ImportProfile(utf8_to_wstr(ProfileName).c_str(), utf8_to_wstr(RegFile).c_str(), IncludePathInfo);
}

void PyAcadPreferencesProfiles::exportProfile(const std::string& ProfileName, const std::string& RegFile) const
{
    impObj()->ExportProfile(utf8_to_wstr(ProfileName).c_str(), utf8_to_wstr(RegFile).c_str());
}

void PyAcadPreferencesProfiles::deleteProfile(const std::string& ProfileName) const
{
    impObj()->DeleteProfile(utf8_to_wstr(ProfileName).c_str());
}

void PyAcadPreferencesProfiles::resetProfile(const std::string& Profile) const
{
    impObj()->ResetProfile(utf8_to_wstr(Profile).c_str());
}

void PyAcadPreferencesProfiles::renameProfile(const std::string& origProfileName, const std::string& newProfileName) const
{
    impObj()->RenameProfile(utf8_to_wstr(origProfileName).c_str(), utf8_to_wstr(newProfileName).c_str());
}

void PyAcadPreferencesProfiles::copyProfile(const std::string& oldProfileName, const std::string& newProfileName) const
{
    impObj()->CopyProfile(utf8_to_wstr(oldProfileName).c_str(), utf8_to_wstr(newProfileName).c_str());
}

boost::python::list PyAcadPreferencesProfiles::getAllProfileNames() const
{
    const auto& items = impObj()->GetAllProfileNames();
    PyAutoLockGIL lock;
    boost::python::list pyList;
    for (const auto& item : items)
        pyList.append(wstr_to_utf8(item));
    return pyList;
}

std::string PyAcadPreferencesProfiles::className()
{
    return "AcadPreferencesProfiles";
}

PyIAcadPreferencesProfilesImpl* PyAcadPreferencesProfiles::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return m_pyImp.get();
}

//----------------------------------------------------------------------------------------
//PyAcadPreferences
void makePyAcadPreferencesWrapper()
{
    PyDocString DS("AcadPreferences");
    class_<PyAcadPreferences>("AcadPreferences", boost::python::no_init)
        .def("files", &PyAcadPreferences::files, DS.ARGS())
        .def("display", &PyAcadPreferences::display, DS.ARGS())
        .def("openSave", &PyAcadPreferences::openSave, DS.ARGS())
        .def("output", &PyAcadPreferences::output, DS.ARGS())
        .def("system", &PyAcadPreferences::system, DS.ARGS())
        .def("user", &PyAcadPreferences::user, DS.ARGS())
        .def("drafting", &PyAcadPreferences::drafting, DS.ARGS())
        .def("selection", &PyAcadPreferences::selection, DS.ARGS())
        .def("profiles", &PyAcadPreferences::profiles, DS.ARGS())
        .def("className", &PyAcadPreferences::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadPreferences::PyAcadPreferences(std::shared_ptr<PyIAcadPreferencesImpl> ptr)
    : m_pyImp(ptr)
{
}

PyAcadPreferencesFiles PyAcadPreferences::files() const
{
    return PyAcadPreferencesFiles{ impObj()->GetFiles() };
}

PyAcadPreferencesDisplay PyAcadPreferences::display() const
{
    return PyAcadPreferencesDisplay{ impObj()->GetDisplay() };
}

PyAcadPreferencesOpenSave PyAcadPreferences::openSave() const
{
    return PyAcadPreferencesOpenSave{ impObj()->GetOpenSave() };
}

PyAcadPreferencesOutput PyAcadPreferences::output() const
{
    return PyAcadPreferencesOutput{ impObj()->GetOutput() };
}

PyAcadPreferencesSystem PyAcadPreferences::system() const
{
    return PyAcadPreferencesSystem{ impObj()->GetSystem() };
}

PyAcadPreferencesUser PyAcadPreferences::user() const
{
    return PyAcadPreferencesUser{ impObj()->GetUser() };
}

PyAcadPreferencesDrafting PyAcadPreferences::drafting() const
{
    return PyAcadPreferencesDrafting{ impObj()->GetDrafting() };
}

PyAcadPreferencesSelection PyAcadPreferences::selection() const
{
    return PyAcadPreferencesSelection{ impObj()->GetSelection() };
}

PyAcadPreferencesProfiles PyAcadPreferences::profiles() const
{
    return PyAcadPreferencesProfiles{ impObj()->GetProfiles() };
}

std::string PyAcadPreferences::className()
{
    return "AcadPreferences";
}

PyIAcadPreferencesImpl* PyAcadPreferences::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return m_pyImp.get();
}

//----------------------------------------------------------------------------------------
//PyAcadSummaryInfo
void makePyAcadSummaryInfoWrapper()
{
    PyDocString DS("AcadSummaryInfo");
    class_<PyAcadSummaryInfo>("AcadSummaryInfo", boost::python::no_init)
        .def("author", &PyAcadSummaryInfo::author, DS.ARGS())
        .def("setAuthor", &PyAcadSummaryInfo::setAuthor, DS.ARGS({ "val:str" }))
        .def("comments", &PyAcadSummaryInfo::comments, DS.ARGS())
        .def("setComments", &PyAcadSummaryInfo::setComments, DS.ARGS({ "val:str" }))
        .def("hyperlinkBase", &PyAcadSummaryInfo::hyperlinkBase, DS.ARGS())
        .def("setHyperlinkBase", &PyAcadSummaryInfo::setHyperlinkBase, DS.ARGS({ "val:str" }))
        .def("keywords", &PyAcadSummaryInfo::keywords, DS.ARGS())
        .def("setKeywords", &PyAcadSummaryInfo::setKeywords, DS.ARGS({ "val:str" }))
        .def("lastSavedBy", &PyAcadSummaryInfo::lastSavedBy, DS.ARGS())
        .def("setLastSavedBy", &PyAcadSummaryInfo::setLastSavedBy, DS.ARGS({ "val:str" }))
        .def("revisionNumber", &PyAcadSummaryInfo::revisionNumber, DS.ARGS())
        .def("setRevisionNumber", &PyAcadSummaryInfo::setRevisionNumber, DS.ARGS({ "val:str" }))
        .def("subject", &PyAcadSummaryInfo::subject, DS.ARGS())
        .def("setSubject", &PyAcadSummaryInfo::setSubject, DS.ARGS({ "val:str" }))
        .def("title", &PyAcadSummaryInfo::title, DS.ARGS())
        .def("setTitle", &PyAcadSummaryInfo::setTitle, DS.ARGS({ "val:str" }))
        .def("numCustomInfo", &PyAcadSummaryInfo::numCustomInfo, DS.ARGS())
        .def("customByIndex", &PyAcadSummaryInfo::customByIndex, DS.ARGS({ "index:int" }))
        .def("setCustomByIndex", &PyAcadSummaryInfo::setCustomByIndex, DS.ARGS({ "index:int" ,"key:str", "val:str" }))
        .def("customByKey", &PyAcadSummaryInfo::customByKey, DS.ARGS({ "key:str" }))
        .def("setCustomByKey", &PyAcadSummaryInfo::setCustomByKey, DS.ARGS({ "key:str","val:str" }))
        .def("addCustomInfo", &PyAcadSummaryInfo::addCustomInfo, DS.ARGS({ "key:str","val:str" }))
        .def("removeCustomByIndex", &PyAcadSummaryInfo::removeCustomByIndex, DS.ARGS({ "index:int" }))
        .def("removeCustomByKey", &PyAcadSummaryInfo::removeCustomByKey, DS.ARGS({ "key:str" }))
        .def("__getitem__", &PyAcadSummaryInfo::customByIndex, DS.ARGS({ "index: int" }))
        .def("className", &PyAcadSummaryInfo::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadSummaryInfo::PyAcadSummaryInfo(std::shared_ptr<PyIAcadSummaryInfoImpl> ptr)
    : m_pyImp(ptr)
{
}

std::string PyAcadSummaryInfo::author() const
{
    return wstr_to_utf8(impObj()->GetAuthor());
}

void PyAcadSummaryInfo::setAuthor(const std::string& str) const
{
    impObj()->SetAuthor(utf8_to_wstr(str).c_str());
}

std::string PyAcadSummaryInfo::comments() const
{
    return wstr_to_utf8(impObj()->GetComments());
}

void PyAcadSummaryInfo::setComments(const std::string& str) const
{
    impObj()->SetComments(utf8_to_wstr(str).c_str());
}

std::string PyAcadSummaryInfo::hyperlinkBase() const
{
    return wstr_to_utf8(impObj()->GetHyperlinkBase());
}

void PyAcadSummaryInfo::setHyperlinkBase(const std::string& str) const
{
    impObj()->SetHyperlinkBase(utf8_to_wstr(str).c_str());
}

std::string PyAcadSummaryInfo::keywords() const
{
    return wstr_to_utf8(impObj()->GetKeywords());
}

void PyAcadSummaryInfo::setKeywords(const std::string& str) const
{
    impObj()->SetKeywords(utf8_to_wstr(str).c_str());
}

std::string PyAcadSummaryInfo::lastSavedBy() const
{
    return wstr_to_utf8(impObj()->GetLastSavedBy());
}

void PyAcadSummaryInfo::setLastSavedBy(const std::string& str) const
{
    impObj()->SetLastSavedBy(utf8_to_wstr(str).c_str());
}

std::string PyAcadSummaryInfo::revisionNumber() const
{
    return wstr_to_utf8(impObj()->GetRevisionNumber());
}

void PyAcadSummaryInfo::setRevisionNumber(const std::string& str) const
{
    impObj()->SetRevisionNumber(utf8_to_wstr(str).c_str());
}

std::string PyAcadSummaryInfo::subject() const
{
    return wstr_to_utf8(impObj()->GetSubject());
}

void PyAcadSummaryInfo::setSubject(const std::string& str) const
{
    impObj()->SetSubject(utf8_to_wstr(str).c_str());
}

std::string PyAcadSummaryInfo::title() const
{
    return wstr_to_utf8(impObj()->GetTitle());
}

void PyAcadSummaryInfo::setTitle(const std::string& str) const
{
    impObj()->SetTitle(utf8_to_wstr(str).c_str());
}

int PyAcadSummaryInfo::numCustomInfo() const
{
    return impObj()->NumCustomInfo();
}

boost::python::tuple PyAcadSummaryInfo::customByIndex(int ind) const
{
    if (ind >= numCustomInfo())
        throw std::out_of_range{ "IndexError " };
    PyAutoLockGIL lock;
    const auto [key, val] = impObj()->GetCustomByIndex(ind);
    return boost::python::make_tuple(wstr_to_utf8(key), wstr_to_utf8(val));
}

void PyAcadSummaryInfo::setCustomByIndex(int ind, const std::string& key, const std::string& val) const
{
    if (ind >= numCustomInfo())
        throw std::out_of_range{ "IndexError " };
    impObj()->SetCustomByIndex(ind, utf8_to_wstr(key).c_str(), utf8_to_wstr(val).c_str());
}

std::string PyAcadSummaryInfo::customByKey(const std::string& str) const
{
    return wstr_to_utf8(impObj()->GetCustomByKey(utf8_to_wstr(str).c_str()));
}

void PyAcadSummaryInfo::setCustomByKey(const std::string& key, const std::string& val) const
{
    impObj()->SetCustomByKey(utf8_to_wstr(key).c_str(), utf8_to_wstr(val).c_str());
}

void PyAcadSummaryInfo::addCustomInfo(const std::string& key, const std::string& val) const
{
    impObj()->AddCustomInfo(utf8_to_wstr(key).c_str(), utf8_to_wstr(val).c_str());
}

void PyAcadSummaryInfo::removeCustomByIndex(int ind) const
{
    impObj()->RemoveCustomByIndex(ind);
}

void PyAcadSummaryInfo::removeCustomByKey(const std::string& str) const
{
    impObj()->RemoveCustomByKey(utf8_to_wstr(str).c_str());
}

std::string PyAcadSummaryInfo::className()
{
    return "AcadSummaryInfo";
}

PyIAcadSummaryInfoImpl* PyAcadSummaryInfo::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return m_pyImp.get();
}

//----------------------------------------------------------------------------------------
//PyAcadDynamicBlockReferenceProperty
void makePyAcadDynamicBlockReferencePropertyWrapper()
{
    PyDocString DS("AcadDynamicBlockReferenceProperty");
    class_<PyAcadDynamicBlockReferenceProperty>("AcadDynamicBlockReferenceProperty", boost::python::no_init)
        .def("propertyName", &PyAcadDynamicBlockReferenceProperty::propertyName, DS.ARGS())
        .def("isReadOnly", &PyAcadDynamicBlockReferenceProperty::isReadOnly, DS.ARGS())
        .def("isShown", &PyAcadDynamicBlockReferenceProperty::isShown, DS.ARGS())
        .def("description", &PyAcadDynamicBlockReferenceProperty::description, DS.ARGS())
        .def("allowedValues", &PyAcadDynamicBlockReferenceProperty::allowedValues, DS.ARGS())
        .def("value", &PyAcadDynamicBlockReferenceProperty::value, DS.ARGS())
        .def("setValue", &PyAcadDynamicBlockReferenceProperty::setValue, DS.ARGS({ "val:PyDb.EvalVariant" }))
        .def("unitsType", &PyAcadDynamicBlockReferenceProperty::unitsType, DS.ARGS())
        .def("className", &PyAcadDynamicBlockReferenceProperty::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadDynamicBlockReferenceProperty::PyAcadDynamicBlockReferenceProperty(std::shared_ptr<PyIAcadDynamicBlockReferencePropertyImpl> ptr)
    : m_pyImp(ptr)
{
}

std::string PyAcadDynamicBlockReferenceProperty::propertyName() const
{
    return wstr_to_utf8(impObj()->GetPropertyName());
}

bool PyAcadDynamicBlockReferenceProperty::isReadOnly() const
{
    return impObj()->GetReadOnly();
}

bool PyAcadDynamicBlockReferenceProperty::isShown() const
{
    return impObj()->GetShow();
}

std::string PyAcadDynamicBlockReferenceProperty::description() const
{
    return wstr_to_utf8(impObj()->GetDescription());
}

boost::python::list PyAcadDynamicBlockReferenceProperty::allowedValues() const
{
    PyAutoLockGIL lock;
    boost::python::list pyList;
    AcDbEvalVariantArray values = impObj()->GetAllowedValues();
    for (const auto& item : values)
        pyList.append(PyDbEvalVariant(item));
    return pyList;
}

PyDbEvalVariant PyAcadDynamicBlockReferenceProperty::value() const
{
    return PyDbEvalVariant{ impObj()->GetValue() };
}

void PyAcadDynamicBlockReferenceProperty::setValue(const PyDbEvalVariant& variant) const
{
    impObj()->SetValue(*variant.impObj());
}

PyAcDynamicBlockReferencePropertyUnitsType PyAcadDynamicBlockReferenceProperty::unitsType() const
{
    return impObj()->GetUnitsType();
}

std::string PyAcadDynamicBlockReferenceProperty::className()
{
    return "AcadDynamicBlockReferenceProperty";
}

PyIAcadDynamicBlockReferencePropertyImpl* PyAcadDynamicBlockReferenceProperty::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return m_pyImp.get();
}

//----------------------------------------------------------------------------------------
//PyAcadIdPair
void makePyAcadIdPairWrapper()
{
    PyDocString DS("AcadIdPair");
    class_<PyAcadIdPair>("AcadIdPair", boost::python::no_init)
        .def("isCloned", &PyAcadIdPair::isCloned, DS.ARGS())
        .def("isOwnerXlated", &PyAcadIdPair::isOwnerXlated, DS.ARGS())
        .def("isPrimary", &PyAcadIdPair::isPrimary, DS.ARGS())
        .def("key", &PyAcadIdPair::key, DS.ARGS())
        .def("value", &PyAcadIdPair::value, DS.ARGS())
        .def("className", &PyAcadIdPair::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadIdPair::PyAcadIdPair(std::shared_ptr<PyIAcadIdPairImpl> ptr)
    : m_pyImp(ptr)
{
}

bool PyAcadIdPair::isCloned() const
{
    return impObj()->GetIsCloned();
}

bool PyAcadIdPair::isOwnerXlated() const
{
    return impObj()->GetIsOwnerXlated();
}

bool PyAcadIdPair::isPrimary() const
{
    return impObj()->GetIsPrimary();
}

PyDbObjectId PyAcadIdPair::key() const
{
    return PyDbObjectId{ impObj()->GetKey() };
}

PyDbObjectId PyAcadIdPair::value() const
{
    return PyDbObjectId{ impObj()->GetValue() };
}

std::string PyAcadIdPair::className()
{
    return "AcadIdPair";
}

PyIAcadIdPairImpl* PyAcadIdPair::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return m_pyImp.get();
}

//----------------------------------------------------------------------------------------
//PyAcadShadowDisplay
#ifndef _BRXTARGET
void makePyAcadShadowDisplayWrapper()
{
    PyDocString DS("AcadShadowDisplay");
    class_<PyAcadShadowDisplay>("AcadShadowDisplay", boost::python::no_init)
        .def("className", &PyAcadShadowDisplay::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadShadowDisplay::PyAcadShadowDisplay(std::shared_ptr<PyIAcadShadowDisplayImpl> ptr)
    : m_pyImp(ptr)
{
}

std::string PyAcadShadowDisplay::className()
{
    return "AcadShadowDisplay";
}

PyIAcadShadowDisplayImpl* PyAcadShadowDisplay::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return m_pyImp.get();
}
#endif

//----------------------------------------------------------------------------------------
//PyAcadPlot
void makePyAcadPlotWrapper()
{
    PyDocString DS("AcadPlot");
    class_<PyAcadPlot>("AcadPlot", boost::python::no_init)
        .def("quietErrorMode", &PyAcadPlot::quietErrorMode, DS.ARGS())
        .def("setQuietErrorMode", &PyAcadPlot::setQuietErrorMode, DS.ARGS({ "val:bool" }))
        .def("numberOfCopies", &PyAcadPlot::numberOfCopies, DS.ARGS())
        .def("setNumberOfCopies", &PyAcadPlot::setNumberOfCopies, DS.ARGS({ "val:int" }))
        .def("batchPlotProgress", &PyAcadPlot::batchPlotProgress, DS.ARGS())
        .def("setBatchPlotProgress", &PyAcadPlot::setBatchPlotProgress, DS.ARGS({ "val:bool" }))
        .def("setDisplayPlotPreview", &PyAcadPlot::setDisplayPlotPreview, DS.ARGS({ "val:PyAx.AcPreviewMode" }))
        .def("setLayoutsToPlot", &PyAcadPlot::setLayoutsToPlot, DS.ARGS({ "layouts:list[str]" }))
        .def("startBatchMode", &PyAcadPlot::startBatchMode, DS.ARGS({ "val:bool" }))
        .def("className", &PyAcadPlot::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadPlot::PyAcadPlot(std::shared_ptr<PyIAcadPlotImpl> ptr)
    : m_pyImp(ptr)
{
}

bool PyAcadPlot::quietErrorMode() const
{
    return impObj()->GetQuietErrorMode();
}

void PyAcadPlot::setQuietErrorMode(bool val) const
{
    impObj()->SetQuietErrorMode(val);
}

long PyAcadPlot::numberOfCopies() const
{
    return impObj()->GetNumberOfCopies();
}

void PyAcadPlot::setNumberOfCopies(long val) const
{
    impObj()->SetNumberOfCopies(val);
}

bool PyAcadPlot::batchPlotProgress() const
{
    return impObj()->GetBatchPlotProgress();
}

void PyAcadPlot::setBatchPlotProgress(bool val) const
{
    impObj()->SetBatchPlotProgress(val);
}

void PyAcadPlot::setDisplayPlotPreview(PyAcPreviewMode mode) const
{
    impObj()->SetDisplayPlotPreview(mode);
}

void PyAcadPlot::setLayoutsToPlot(const boost::python::list& layouts) const
{
    auto vec = py_list_to_std_vector<std::string>(layouts);
    wstringArray wvec;
    wvec.reserve(vec.size());
    for (const auto& val : vec)
        wvec.push_back(utf8_to_wstr(val));
    impObj()->SetLayoutsToPlot(wvec);
}

void PyAcadPlot::startBatchMode(long val) const
{
    impObj()->StartBatchMode(val);
}

std::string PyAcadPlot::className()
{
    return "AcadPlot";
}

PyIAcadPlotImpl* PyAcadPlot::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return m_pyImp.get();
}

//----------------------------------------------------------------------------------------
//PyAcadMenuBar
void makePyAcadMenuBarWrapper()
{
    PyDocString DS("AcadMenuBar");
    class_<PyAcadMenuBar>("AcadMenuBar", boost::python::no_init)
        .def("count", &PyAcadMenuBar::count, DS.ARGS())
        .def("item", &PyAcadMenuBar::item, DS.ARGS({ "index" }))
        .def("__getitem__", &PyAcadMenuBar::item, DS.ARGS({ "index: int" }))
        .def("className", &PyAcadMenuBar::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadMenuBar::PyAcadMenuBar(std::shared_ptr<PyIAcadMenuBarImpl> ptr)
    : m_pyImp(ptr)
{
}

long PyAcadMenuBar::count() const
{
    return impObj()->GetCount();
}

PyAcadPopupMenu PyAcadMenuBar::item(long index) const
{
    if (index >= count())
        throw std::out_of_range{ "IndexError " };
    return PyAcadPopupMenu{ impObj()->GetItem(index) };
}

std::string PyAcadMenuBar::className()
{
    return "AcadMenuBar";
}

PyIAcadMenuBarImpl* PyAcadMenuBar::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return m_pyImp.get();
}

//----------------------------------------------------------------------------------------
//PyAcadMenuGroup
void makePyAcadMenuGroupWrapper()
{
    PyDocString DS("AcadMenuGroup");
    class_<PyAcadMenuGroup>("AcadMenuGroup", boost::python::no_init)
        .def("parent", &PyAcadMenuGroup::parent, DS.ARGS())
        .def("name", &PyAcadMenuGroup::name, DS.ARGS())
        .def("menuType", &PyAcadMenuGroup::menuType, DS.ARGS())
        .def("fileName", &PyAcadMenuGroup::fileName, DS.ARGS())
        .def("menus", &PyAcadMenuGroup::menus, DS.ARGS())
        .def("toolbars", &PyAcadMenuGroup::toolbars, DS.ARGS())
        .def("save", &PyAcadMenuGroup::save, DS.ARGS({ "menuType: PyAx.AcadMenuGroup" }))
        .def("saveAs", &PyAcadMenuGroup::save, DS.ARGS({ "menuFileName: str", "menuType: PyAx.AcadMenuGroup" }))
        .def("unload", &PyAcadMenuGroup::unload, DS.ARGS())
        .def("className", &PyAcadMenuGroup::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadMenuGroup::PyAcadMenuGroup(std::shared_ptr<PyIAcadMenuGroupImpl> ptr)
    : m_pyImp(ptr)
{
}

PyAcadMenuGroups PyAcadMenuGroup::parent() const
{
    return PyAcadMenuGroups{ impObj()->GetParent() };
}

std::string PyAcadMenuGroup::name() const
{
    return wstr_to_utf8(impObj()->GetName());
}

PyAcMenuGroupType PyAcadMenuGroup::menuType() const
{
    return impObj()->GetType();
}

std::string PyAcadMenuGroup::fileName() const
{
    return wstr_to_utf8(impObj()->GetMenuFileName());
}

PyAcadPopupMenus PyAcadMenuGroup::menus() const
{
    return PyAcadPopupMenus{ impObj()->GetMenus() };
}

PyAcadToolbars PyAcadMenuGroup::toolbars() const
{
    return PyAcadToolbars{ impObj()->GetToolbars() };
}

void PyAcadMenuGroup::save(PyAcMenuFileType menuType) const
{
    impObj()->Save(menuType);
}

void PyAcadMenuGroup::saveAs(const std::string& menuFileName, PyAcMenuFileType menuType) const
{
    impObj()->SaveAs(utf8_to_wstr(menuFileName).c_str(), menuType);
}

void PyAcadMenuGroup::unload() const
{
    impObj()->Unload();
}

std::string PyAcadMenuGroup::className()
{
    return "AcadMenuGroup";
}

PyIAcadMenuGroupImpl* PyAcadMenuGroup::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return m_pyImp.get();
}

//----------------------------------------------------------------------------------------
//PyAcadMenuGroups
void makePyAcadMenuGroupsWrapper()
{
    PyDocString DS("AcadMenuGroups");
    class_<PyAcadMenuGroups>("AcadMenuGroups", boost::python::no_init)
        .def("count", &PyAcadMenuGroups::count, DS.ARGS())
        .def("item", &PyAcadMenuGroups::item, DS.ARGS({ "idx : int" }))
        .def("load", &PyAcadMenuGroups::load1)
        .def("load", &PyAcadMenuGroups::load2, DS.ARGS({ "menuFileName : str","baseMenu : PyAx.AcadMenuGroup = ..." }))
        .def("__getitem__", &PyAcadMenuGroups::item, DS.ARGS({ "index: int" }))
        .def("className", &PyAcadMenuGroups::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadMenuGroups::PyAcadMenuGroups(std::shared_ptr<PyIAcadMenuGroupsImpl> ptr)
    : m_pyImp(ptr)
{
}

long PyAcadMenuGroups::count() const
{
    return impObj()->GetCount();
}

PyAcadMenuGroup PyAcadMenuGroups::item(long index) const
{
    if (index >= count())
        throw std::out_of_range{ "IndexError " };
    return PyAcadMenuGroup{ impObj()->GetItem(index) };
}

PyAcadMenuGroup PyAcadMenuGroups::load1(const std::string& menuFileName) const
{
    return PyAcadMenuGroup{ impObj()->Load(utf8_to_wstr(menuFileName).c_str()) };
}

PyAcadMenuGroup PyAcadMenuGroups::load2(const std::string& menuFileName, const PyAcadMenuGroup& baseMenu) const
{
    return PyAcadMenuGroup{ impObj()->Load(utf8_to_wstr(menuFileName).c_str(),*baseMenu.impObj()) };
}

std::string PyAcadMenuGroups::className()
{
    return "AcadMenuGroups";
}

PyIAcadMenuGroupsImpl* PyAcadMenuGroups::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return m_pyImp.get();
}

//----------------------------------------------------------------------------------------
//PyAcadPopupMenuItem
void makePyAcadPopupMenuItemWrapper()
{
    PyDocString DS("AcadPopupMenuItem");
    class_<PyAcadPopupMenuItem>("AcadPopupMenuItem", boost::python::no_init)
        .def("parent", &PyAcadPopupMenuItem::parent, DS.ARGS())
        .def("label", &PyAcadPopupMenuItem::label, DS.ARGS())
        .def("setLabel", &PyAcadPopupMenuItem::setLabel, DS.ARGS({ "label: str" }))
        .def("tagString", &PyAcadPopupMenuItem::tagString, DS.ARGS())
        .def("setTagString", &PyAcadPopupMenuItem::setTagString, DS.ARGS({ "tag: str" }))
        .def("enable", &PyAcadPopupMenuItem::enable, DS.ARGS())
        .def("setEnable", &PyAcadPopupMenuItem::setEnable, DS.ARGS({ "enable: bool" }))
        .def("check", &PyAcadPopupMenuItem::check, DS.ARGS())
        .def("setCheck", &PyAcadPopupMenuItem::setCheck, DS.ARGS({ "enable: bool" }))
        .def("getType", &PyAcadPopupMenuItem::getType, DS.ARGS())
        .def("subMenu", &PyAcadPopupMenuItem::subMenu, DS.ARGS())
        .def("macro", &PyAcadPopupMenuItem::macro, DS.ARGS())
        .def("setMacro", &PyAcadPopupMenuItem::setMacro, DS.ARGS({ "macro: str" }))
        .def("index", &PyAcadPopupMenuItem::index, DS.ARGS())
        .def("caption", &PyAcadPopupMenuItem::caption, DS.ARGS())
        .def("helpString", &PyAcadPopupMenuItem::helpString, DS.ARGS())
        .def("setHelpString", &PyAcadPopupMenuItem::setHelpString, DS.ARGS({ "helpString: str" }))
        .def("clear", &PyAcadPopupMenuItem::clear, DS.ARGS())
        .def("endSubMenuLevel", &PyAcadPopupMenuItem::endSubMenuLevel, DS.ARGS())
        .def("setEndSubMenuLevel", &PyAcadPopupMenuItem::setEndSubMenuLevel, DS.ARGS({ "val: int" }))
        .def("className", &PyAcadPopupMenuItem::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadPopupMenuItem::PyAcadPopupMenuItem(std::shared_ptr<PyIAcadPopupMenuItemImpl> ptr)
    : m_pyImp(ptr)
{
}

PyAcadPopupMenu PyAcadPopupMenuItem::parent() const
{
    return PyAcadPopupMenu{ impObj()->GetParent() };
}

std::string PyAcadPopupMenuItem::label() const
{
    return wstr_to_utf8(impObj()->GetLabel());
}

void PyAcadPopupMenuItem::setLabel(const std::string& val) const
{
    impObj()->SetLabel(utf8_to_wstr(val).c_str());
}

std::string PyAcadPopupMenuItem::tagString() const
{
    return wstr_to_utf8(impObj()->GetTagString());
}

void PyAcadPopupMenuItem::setTagString(const std::string& val) const
{
    impObj()->SetTagString(utf8_to_wstr(val).c_str());
}

bool PyAcadPopupMenuItem::enable() const
{
    return impObj()->GetEnable();
}

void PyAcadPopupMenuItem::setEnable(bool val) const
{
    impObj()->SetEnable(val);
}

bool PyAcadPopupMenuItem::check() const
{
    return impObj()->GetCheck();
}

void PyAcadPopupMenuItem::setCheck(bool val) const
{
    impObj()->SetCheck(val);
}

PyAcMenuItemType PyAcadPopupMenuItem::getType() const
{
    return impObj()->GetType();
}

PyAcadPopupMenu PyAcadPopupMenuItem::subMenu() const
{
    return PyAcadPopupMenu{ impObj()->GetSubMenu() };
}

std::string PyAcadPopupMenuItem::macro() const
{
    return wstr_to_utf8(impObj()->GetMacro());
}

void PyAcadPopupMenuItem::setMacro(const std::string& val) const
{
    impObj()->SetMacro(utf8_to_wstr(val).c_str());
}

int PyAcadPopupMenuItem::index() const
{
    return impObj()->GetIndex();
}

std::string PyAcadPopupMenuItem::caption() const
{
    return wstr_to_utf8(impObj()->GetCaption());
}

std::string PyAcadPopupMenuItem::helpString() const
{
    return wstr_to_utf8(impObj()->GetHelpString());
}

void PyAcadPopupMenuItem::setHelpString(const std::string& val) const
{
    impObj()->SetHelpString(utf8_to_wstr(val).c_str());
}

void PyAcadPopupMenuItem::clear() const
{
    impObj()->Delete();
}

int PyAcadPopupMenuItem::endSubMenuLevel() const
{
    return impObj()->GetEndSubMenuLevel();
}

void PyAcadPopupMenuItem::setEndSubMenuLevel(int idx) const
{
    impObj()->SetEndSubMenuLevel(idx);
}

std::string PyAcadPopupMenuItem::className()
{
    return "AcadPopupMenuItem";
}

PyIAcadPopupMenuItemImpl* PyAcadPopupMenuItem::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return m_pyImp.get();
}

//----------------------------------------------------------------------------------------
//PyAcadPopupMenu
void makePyAcadPopupMenuWrapper()
{
    PyDocString DS("AcadPopupMenu");
    class_<PyAcadPopupMenu>("AcadPopupMenu", boost::python::no_init)
        .def("count", &PyAcadPopupMenu::count, DS.ARGS())
        .def("item", &PyAcadPopupMenu::item, DS.ARGS({ "idx : int" }))
        .def("parent", &PyAcadPopupMenu::parent, DS.ARGS())
        .def("name", &PyAcadPopupMenu::name, DS.ARGS())
        .def("setName", &PyAcadPopupMenu::setName, DS.ARGS({ "name: str" }))
        .def("nameNoMnemonic", &PyAcadPopupMenu::nameNoMnemonic, DS.ARGS())
        .def("isShortcutMenu", &PyAcadPopupMenu::isShortcutMenu, DS.ARGS())
        .def("isOnMenuBar", &PyAcadPopupMenu::isOnMenuBar, DS.ARGS())
        .def("addMenuItem", &PyAcadPopupMenu::addMenuItem, DS.ARGS({ "idx : int","label : str","macro : str" }))
        .def("addSubMenu", &PyAcadPopupMenu::addMenuItem, DS.ARGS({ "idx : int","label : str" }))
        .def("addSeparator", &PyAcadPopupMenu::addSeparator, DS.ARGS({ "idx : int" }))
        .def("insertInMenuBar", &PyAcadPopupMenu::insertInMenuBar, DS.ARGS({ "idx : int" }))
        .def("removeFromMenuBar", &PyAcadPopupMenu::removeFromMenuBar, DS.ARGS())
        .def("tagString", &PyAcadPopupMenu::tagString, DS.ARGS())
        .def("__getitem__", &PyAcadPopupMenu::item, DS.ARGS({ "index: int" }))
        .def("className", &PyAcadPopupMenu::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadPopupMenu::PyAcadPopupMenu(std::shared_ptr<PyIAcadPopupMenuImpl> ptr)
    : m_pyImp(ptr)
{
}

long PyAcadPopupMenu::count() const
{
    return impObj()->GetCount();
}

PyAcadPopupMenuItem PyAcadPopupMenu::item(long index) const
{
    if (index >= count())
        throw std::out_of_range{ "IndexError " };
    return PyAcadPopupMenuItem{ impObj()->GetItem(index) };
}

PyAcadPopupMenus PyAcadPopupMenu::parent() const
{
    return PyAcadPopupMenus{ impObj()->GetParent() };
}

std::string PyAcadPopupMenu::name() const
{
    return wstr_to_utf8(impObj()->GetName());
}

void PyAcadPopupMenu::setName(const std::string& val) const
{
    impObj()->SetName(utf8_to_wstr(val).c_str());
}

std::string PyAcadPopupMenu::nameNoMnemonic() const
{
    return wstr_to_utf8(impObj()->GetNameNoMnemonic());
}

bool PyAcadPopupMenu::isShortcutMenu() const
{
    return impObj()->GetShortcutMenu();
}

bool PyAcadPopupMenu::isOnMenuBar() const
{
    return impObj()->GetOnMenuBar();
}

PyAcadPopupMenuItem PyAcadPopupMenu::addMenuItem(long index, const std::string& label, const std::string& macro) const
{
    return PyAcadPopupMenuItem{ impObj()->AddMenuItem(index, utf8_to_wstr(label).c_str(), utf8_to_wstr(macro).c_str()) };
}

PyAcadPopupMenu PyAcadPopupMenu::addSubMenu(long index, const std::string& label) const
{
    return PyAcadPopupMenu{ impObj()->AddSubMenu(index, utf8_to_wstr(label).c_str()) };
}

PyAcadPopupMenuItem PyAcadPopupMenu::addSeparator(long index) const
{
    return PyAcadPopupMenuItem{ impObj()->AddSeparator(index) };
}

void PyAcadPopupMenu::insertInMenuBar(long index) const
{
    impObj()->InsertInMenuBar(index);
}

void PyAcadPopupMenu::removeFromMenuBar() const
{
    impObj()->RemoveFromMenuBar();
}

std::string PyAcadPopupMenu::tagString() const
{
    return wstr_to_utf8(impObj()->GetTagString());
}

std::string PyAcadPopupMenu::className()
{
    return "AcadPopupMenu";
}

PyIAcadPopupMenuImpl* PyAcadPopupMenu::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return m_pyImp.get();
}

//----------------------------------------------------------------------------------------
//PyAcadPopupMenus
void makePyAcadPopupMenusWrapper()
{
    PyDocString DS("AcadPopupMenus");
    class_<PyAcadPopupMenus>("AcadPopupMenus", boost::python::no_init)
        .def("count", &PyAcadPopupMenus::count, DS.ARGS())
        .def("item", &PyAcadPopupMenus::item, DS.ARGS({ "idx : int" }))
        .def("parent", &PyAcadPopupMenus::parent, DS.ARGS())
        .def("add", &PyAcadPopupMenus::add, DS.ARGS({ "toolbarName: str" }))
        .def("insertMenuInMenuBar", &PyAcadPopupMenus::insertMenuInMenuBar, DS.ARGS({ "insertMenuInMenuBar: str","idx : int" }))
        .def("removeMenuFromMenuBar", &PyAcadPopupMenus::removeMenuFromMenuBar, DS.ARGS({ "idx : int" }))
        .def("__getitem__", &PyAcadPopupMenus::item, DS.ARGS({ "index: int" }))
        .def("className", &PyAcadPopupMenus::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadPopupMenus::PyAcadPopupMenus(std::shared_ptr<PyIAcadPopupMenusImpl> ptr)
    : m_pyImp(ptr)
{
}

long PyAcadPopupMenus::count() const
{
    return impObj()->GetCount();
}

PyAcadPopupMenu PyAcadPopupMenus::item(long index) const
{
    if (index >= count())
        throw std::out_of_range{ "IndexError " };
    return PyAcadPopupMenu{ impObj()->GetItem(index) };
}

PyAcadMenuGroup PyAcadPopupMenus::parent() const
{
    return PyAcadMenuGroup{ impObj()->GetParent() };
}

PyAcadPopupMenu PyAcadPopupMenus::add(const std::string& toolbarName) const
{
    return PyAcadPopupMenu{ impObj()->Add(utf8_to_wstr(toolbarName).c_str()) };
}

void PyAcadPopupMenus::insertMenuInMenuBar(const std::string& menuName, long index) const
{
    impObj()->InsertMenuInMenuBar(utf8_to_wstr(menuName).c_str(), index);
}

void PyAcadPopupMenus::removeMenuFromMenuBar(long index) const
{
    impObj()->RemoveMenuFromMenuBar(index);
}

std::string PyAcadPopupMenus::className()
{
    return "AcadPopupMenus";
}

PyIAcadPopupMenusImpl* PyAcadPopupMenus::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return m_pyImp.get();
}

//----------------------------------------------------------------------------------------
//PyAcadToolbarItem
void makePyAcadToolbarItemWrapper()
{
    PyDocString DS("AcadToolbarItem");
    class_<PyAcadToolbarItem>("AcadToolbarItem", boost::python::no_init)
        .def("parent", &PyAcadToolbarItem::parent, DS.ARGS())
        .def("name", &PyAcadToolbarItem::name, DS.ARGS())
        .def("setName", &PyAcadToolbarItem::setName, DS.ARGS({ "name: str" }))
        .def("tagString", &PyAcadToolbarItem::tagString, DS.ARGS())
        .def("setTagString", &PyAcadToolbarItem::setTagString, DS.ARGS({ "tag: str" }))
        .def("getType", &PyAcadToolbarItem::getType, DS.ARGS())
        .def("macro", &PyAcadToolbarItem::macro, DS.ARGS())
        .def("setMacro", &PyAcadToolbarItem::setMacro, DS.ARGS({ "macro: str" }))
        .def("index", &PyAcadToolbarItem::index, DS.ARGS())
        .def("helpString", &PyAcadToolbarItem::helpString, DS.ARGS())
        .def("setHelpString", &PyAcadToolbarItem::setHelpString, DS.ARGS({ "helpString: str" }))
        .def("bitmaps", &PyAcadToolbarItem::bitmaps, DS.ARGS())
        .def("setBitmaps", &PyAcadToolbarItem::setBitmaps, DS.ARGS({ "smallIconName: str", "largeIconName: str" }))
        .def("attachToolbarToFlyout", &PyAcadToolbarItem::attachToolbarToFlyout, DS.ARGS({ "menuGroupName: str", "toolbarGroupName: str" }))
        .def("clear", &PyAcadToolbarItem::clear, DS.ARGS())
        .def("commandDisplayName", &PyAcadToolbarItem::commandDisplayName, DS.ARGS())
        .def("setCommandDisplayName", &PyAcadToolbarItem::setCommandDisplayName, DS.ARGS({ "commandDisplayName: str" }))
        .def("className", &PyAcadToolbarItem::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadToolbarItem::PyAcadToolbarItem(std::shared_ptr<PyIAcadToolbarItemImpl> ptr)
    : m_pyImp(ptr)
{
}

PyAcadToolbar PyAcadToolbarItem::parent() const
{
    return PyAcadToolbar{ impObj()->GetParent() };
}

std::string PyAcadToolbarItem::name() const
{
    return wstr_to_utf8(impObj()->GetName());
}

void PyAcadToolbarItem::setName(const std::string& val) const
{
    impObj()->SetName(utf8_to_wstr(val).c_str());
}

std::string PyAcadToolbarItem::tagString() const
{
    return wstr_to_utf8(impObj()->GetTagString());
}

void PyAcadToolbarItem::setTagString(const std::string& val) const
{
    impObj()->SetTagString(utf8_to_wstr(val).c_str());
}

PyAcToolbarItemType PyAcadToolbarItem::getType() const
{
    return impObj()->GetType();
}

std::string PyAcadToolbarItem::macro() const
{
    return wstr_to_utf8(impObj()->GetMacro());
}

void PyAcadToolbarItem::setMacro(const std::string& val) const
{
    impObj()->SetMacro(utf8_to_wstr(val).c_str());
}

int PyAcadToolbarItem::index() const
{
    return impObj()->GetIndex();
}

std::string PyAcadToolbarItem::helpString() const
{
    return wstr_to_utf8(impObj()->GetHelpString());
}

void PyAcadToolbarItem::setHelpString(const std::string& val) const
{
    impObj()->SetHelpString(utf8_to_wstr(val).c_str());
}

boost::python::tuple PyAcadToolbarItem::bitmaps() const
{
    PyAutoLockGIL lock;
    const auto& val = impObj()->GetBitmaps();
    return boost::python::make_tuple(wstr_to_utf8(val.first), wstr_to_utf8(val.second));
}

void PyAcadToolbarItem::setBitmaps(const std::string& smallIconName, const std::string& largeIconName) const
{
    impObj()->SetBitmaps(utf8_to_wstr(smallIconName).c_str(), utf8_to_wstr(largeIconName).c_str());
}

void PyAcadToolbarItem::attachToolbarToFlyout(const std::string& menuGroupName, const std::string& toolbarName) const
{
    impObj()->AttachToolbarToFlyout(utf8_to_wstr(menuGroupName).c_str(), utf8_to_wstr(toolbarName).c_str());
}

void PyAcadToolbarItem::clear() const
{
    impObj()->Delete();
}

std::string PyAcadToolbarItem::commandDisplayName() const
{
    return wstr_to_utf8(impObj()->GetCommandDisplayName());
}

void PyAcadToolbarItem::setCommandDisplayName(const std::string& val) const
{
    impObj()->SetCommandDisplayName(utf8_to_wstr(val).c_str());
}

std::string PyAcadToolbarItem::className()
{
    return "AcadToolbarItem";
}

PyIAcadToolbarItemImpl* PyAcadToolbarItem::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return m_pyImp.get();
}

//----------------------------------------------------------------------------------------
//PyAcadToolbar
void makePyAcadToolbarWrapper()
{
    PyDocString DS("AcadToolbar");
    class_<PyAcadToolbar>("AcadToolbar", boost::python::no_init)
        .def("count", &PyAcadToolbar::count, DS.ARGS())
        .def("item", &PyAcadToolbar::item, DS.ARGS({ "idx : int" }))
        .def("parent", &PyAcadToolbar::parent, DS.ARGS())
        .def("name", &PyAcadToolbar::name, DS.ARGS())
        .def("setName", &PyAcadToolbar::setName, DS.ARGS({ "name:str" }))
        .def("isVisible", &PyAcadToolbar::isVisible, DS.ARGS())
        .def("setVisible", &PyAcadToolbar::setVisible, DS.ARGS({ "visible:bool" }))
        .def("dockStatus", &PyAcadToolbar::dockStatus, DS.ARGS())
        .def("largeButtons", &PyAcadToolbar::largeButtons, DS.ARGS())
        .def("left", &PyAcadToolbar::left, DS.ARGS())
        .def("setLeft", &PyAcadToolbar::setLeft, DS.ARGS({ "left:int" }))
        .def("top", &PyAcadToolbar::top, DS.ARGS())
        .def("setTop", &PyAcadToolbar::setTop, DS.ARGS({ "top:int" }))
        .def("width", &PyAcadToolbar::width, DS.ARGS())
        .def("height", &PyAcadToolbar::height, DS.ARGS())
        .def("floatingRows", &PyAcadToolbar::floatingRows, DS.ARGS())
        .def("setFloatingRows", &PyAcadToolbar::setFloatingRows, DS.ARGS({ "nRows:int" }))
        .def("helpString", &PyAcadToolbar::helpString, DS.ARGS())
        .def("setHelpString", &PyAcadToolbar::setHelpString, DS.ARGS({ "helpString: str" }))
        .def("addToolbarButton", &PyAcadToolbar::addToolbarButton, DS.ARGS({ "index: int", "name: str", "helpstr: str","macro: str","flyoutButton:bool" }))
        .def("dock", &PyAcadToolbar::dock, DS.ARGS({ "val: PyAx.AcToolbarDockStatus" }))
        .def("setFloat", &PyAcadToolbar::setFloat, DS.ARGS({ "top:int","left:int","numberFloatRows:int" }))
        .def("clear", &PyAcadToolbar::clear, DS.ARGS())
        .def("tagString", &PyAcadToolbar::tagString, DS.ARGS())
        .def("__getitem__", &PyAcadToolbar::item, DS.ARGS({ "index: int" }))
        .def("className", &PyAcadToolbar::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadToolbar::PyAcadToolbar(std::shared_ptr<PyIAcadToolbarImpl> ptr)
    : m_pyImp(ptr)
{
}

long PyAcadToolbar::count() const
{
    return impObj()->GetCount();
}

PyAcadToolbarItem PyAcadToolbar::item(long index) const
{
    if (index >= count())
        throw std::out_of_range{ "IndexError " };
    return PyAcadToolbarItem{ impObj()->GetItem(index) };
}

PyAcadToolbars PyAcadToolbar::parent() const
{
    return PyAcadToolbars{ impObj()->GetParent() };
}

std::string PyAcadToolbar::name() const
{
    return wstr_to_utf8(impObj()->GetName());
}

void PyAcadToolbar::setName(const std::string& name) const
{
    impObj()->SetName(utf8_to_wstr(name).c_str());
}

bool PyAcadToolbar::isVisible() const
{
    return impObj()->GetVisible();
}

void PyAcadToolbar::setVisible(bool val) const
{
    impObj()->SetVisible(val);
}

PyAcToolbarDockStatus PyAcadToolbar::dockStatus() const
{
    return impObj()->GetDockStatus();
}

bool PyAcadToolbar::largeButtons() const
{
    return impObj()->GetLargeButtons();
}

int PyAcadToolbar::left() const
{
    return impObj()->GetLeft();
}

void PyAcadToolbar::setLeft(int val) const
{
    return impObj()->SetLeft(val);
}

int PyAcadToolbar::top() const
{
    return impObj()->GetTop();
}

void PyAcadToolbar::setTop(int val) const
{
    return impObj()->SetTop(val);
}

int PyAcadToolbar::width() const
{
    return impObj()->GetWidth();
}

int PyAcadToolbar::height() const
{
    return impObj()->GetHeight();
}

int PyAcadToolbar::floatingRows() const
{
    return impObj()->GetFloatingRows();
}

void PyAcadToolbar::setFloatingRows(int val) const
{
    return impObj()->SetFloatingRows(val);
}

std::string PyAcadToolbar::helpString() const
{
    return wstr_to_utf8(impObj()->GetHelpString());
}

void PyAcadToolbar::setHelpString(const std::string& val) const
{
    impObj()->SetHelpString(utf8_to_wstr(val).c_str());
}

PyAcadToolbarItem PyAcadToolbar::addToolbarButton(int index, const std::string& name, const std::string& helpstr, const std::string& macro, bool flyoutButton) const
{
    return PyAcadToolbarItem{ impObj()->AddToolbarButton(index,utf8_to_wstr(name).c_str(),utf8_to_wstr(helpstr).c_str(),utf8_to_wstr(macro).c_str(), flyoutButton) };
}

void PyAcadToolbar::dock(PyAcToolbarDockStatus val) const
{
    impObj()->Dock(val);
}

void PyAcadToolbar::setFloat(int itop, int ileft, int numberFloatRows) const
{
    impObj()->Float(itop, ileft, numberFloatRows);
}

void PyAcadToolbar::clear() const
{
    impObj()->Delete();
}

std::string PyAcadToolbar::tagString() const
{
    return wstr_to_utf8(impObj()->GetTagString());
}

std::string PyAcadToolbar::className()
{
    return "AcadToolbar";
}

PyIAcadToolbarImpl* PyAcadToolbar::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return m_pyImp.get();
}

//----------------------------------------------------------------------------------------
//PyAcadToolbars
void makePyAcadToolbarsWrapper()
{
    PyDocString DS("AcadToolbars");
    class_<PyAcadToolbars>("AcadToolbars", boost::python::no_init)
        .def("count", &PyAcadToolbars::count, DS.ARGS())
        .def("item", &PyAcadToolbars::item, DS.ARGS({ "idx : int" }))
        .def("parent", &PyAcadToolbars::parent, DS.ARGS())
        .def("largeButtons", &PyAcadToolbars::largeButtons, DS.ARGS())
        .def("setLargeButtons", &PyAcadToolbars::setLargeButtons, DS.ARGS({ "largeButtons:bool" }))
        .def("add", &PyAcadToolbars::add, DS.ARGS({ "toolbarName:str" }))
        .def("__getitem__", &PyAcadToolbars::item, DS.ARGS({ "index: int" }))
        .def("className", &PyAcadToolbars::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadToolbars::PyAcadToolbars(std::shared_ptr<PyIAcadToolbarsImpl> ptr)
    : m_pyImp(ptr)
{
}

long PyAcadToolbars::count() const
{
    return impObj()->GetCount();
}

PyAcadToolbar PyAcadToolbars::item(long index) const
{
    if (index >= count())
        throw std::out_of_range{ "IndexError " };
    return PyAcadToolbar{ impObj()->GetItem(index) };
}

PyAcadMenuGroup PyAcadToolbars::parent() const
{
    return PyAcadMenuGroup{ impObj()->GetParent() };
}

bool PyAcadToolbars::largeButtons() const
{
    return impObj()->GetLargeButtons();
}

void PyAcadToolbars::setLargeButtons(bool val) const
{
    impObj()->SetLargeButtons(val);
}

PyAcadToolbar PyAcadToolbars::add(const std::string& toolbarName) const
{
    return  PyAcadToolbar{ impObj()->Add(utf8_to_wstr(toolbarName).c_str()) };
}

std::string PyAcadToolbars::className()
{
    return "AcadToolbars";
}

PyIAcadToolbarsImpl* PyAcadToolbars::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return m_pyImp.get();
}