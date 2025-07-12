#include "stdafx.h"
#include "PyDbSection.h"
#include "PyDbObjectId.h"

using namespace boost::python;

//-----------------------------------------------------------------------------------
//PyDbSectionManager
void makePyDbSectionManagerWrapper()
{
    PyDocString DS("PyDb.SectionManager");
    class_<PyDbSectionManager, bases<PyDbObject>>("SectionManager", boost::python::no_init)
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.ARGS({ "id: PyDb.ObjectId", "mode: PyDb.OpenMode = PyDb.OpenMode.kForRead", "erased: bool=False" }, 8325)))
        .def("getSection", &PyDbSectionManager::getSection, DS.ARGS(8338))
        .def("getLiveSection", &PyDbSectionManager::getLiveSection, DS.ARGS(8339))
        .def("numSections", &PyDbSectionManager::numSections, DS.ARGS(8342))
        .def("getUniqueSectionName", &PyDbSectionManager::getUniqueSectionName, DS.ARGS(8340))
        .def("objectIds", &PyDbSectionManager::objectIds, DS.ARGS())
        .def("className", &PyDbSectionManager::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbSectionManager::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyDbSectionManager::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbSectionManager::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyDbSectionManager::PyDbSectionManager(const PyDbObjectId& id)
    : PyDbSectionManager(openAcDbObject<AcDbSectionManager>(id, AcDb::OpenMode::kForRead), false)
{
}

PyDbSectionManager::PyDbSectionManager(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbSectionManager(openAcDbObject<AcDbSectionManager>(id, mode), false)
{
}

PyDbSectionManager::PyDbSectionManager(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbSectionManager(openAcDbObject<AcDbSectionManager>(id, mode, erased), false)
{
}

PyDbSectionManager::PyDbSectionManager(AcDbSectionManager* ptr, bool autoDelete)
    : PyDbObject(ptr, autoDelete)
{
}

PyDbObjectId PyDbSectionManager::getSection(const std::string& name) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    PyDbObjectId id;
    PyThrowBadEs(impObj()->getSection(utf8_to_wstr(name).c_str(), id.m_id));
    return id;
#endif
}

PyDbObjectId PyDbSectionManager::getLiveSection() const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    PyDbObjectId id;
    PyThrowBadEs(impObj()->getLiveSection(id.m_id));
    return id;
#endif
}

int PyDbSectionManager::numSections(void) const
{
    return impObj()->numSections();
}

std::string PyDbSectionManager::getUniqueSectionName(const std::string& pszBaseName) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    AcString val;
    PyThrowBadEs(impObj()->getUniqueSectionName(utf8_to_wstr(pszBaseName).c_str(), val));
    return wstr_to_utf8(val);
#endif
}

boost::python::list PyDbSectionManager::objectIds() const
{
    PyAutoLockGIL lock;
    boost::python::list ids;
    AcDbSectionManagerIterator* _iter = nullptr;
    PyThrowBadEs(impObj()->newIterator(_iter));
    std::unique_ptr<AcDbSectionManagerIterator> iter(_iter);
    for (iter->start(); !iter->done(); iter->step())
        ids.append(PyDbObjectId(iter->getSection()));
    return ids;
}

PyRxClass PyDbSectionManager::desc()
{
    return PyRxClass(AcDbEntity::desc(), false);
}

std::string PyDbSectionManager::className()
{
    return "AcDbSectionManager";
}

PyDbSectionManager PyDbSectionManager::cloneFrom(const PyRxObject& src)
{
    return PyDbObjectCloneFrom<PyDbSectionManager, AcDbSectionManager>(src);
}

PyDbSectionManager PyDbSectionManager::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbSectionManager>(src);
}

AcDbSectionManager* PyDbSectionManager::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbSectionManager*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//PyDbSectionSettings
void makePyDbSectionSettingsWrapper()
{
    constexpr const std::string_view resetOverloads = "Overloads:\n"
        "- None: Any\n"
        "- nSecType: PyDb.SectionType\n";


    PyDocString DS("PyDb.SectionSettings");
    class_<PyDbSectionSettings, bases<PyDbObject>>("SectionSettings")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.ARGS({ "id: PyDb.ObjectId", "mode: PyDb.OpenMode = PyDb.OpenMode.kForRead", "erased: bool=False" }, 8345)))

        .def("reset", &PyDbSectionSettings::reset1)
        .def("reset", &PyDbSectionSettings::reset2, DS.OVRL(resetOverloads))
        .def("currentSectionType", &PyDbSectionSettings::currentSectionType, DS.ARGS())
        .def("setCurrentSectionType", &PyDbSectionSettings::setCurrentSectionType, DS.ARGS({ "nSecType: PyDb.SectionType" }))
        .def("generationOptions", &PyDbSectionSettings::generationOptions, DS.ARGS({ "nSecType: PyDb.SectionType" }))
        .def("setGenerationOptions", &PyDbSectionSettings::setGenerationOptions, DS.ARGS({ "nSecType: PyDb.SectionType", "opts: PyDb.SectionGeneration" }))
        .def("getSourceObjects", &PyDbSectionSettings::getSourceObjects, DS.ARGS({ "nSecType: PyDb.SectionType" }))
        .def("setSourceObjects", &PyDbSectionSettings::setSourceObjects, DS.ARGS({ "nSecType: PyDb.SectionType","ids: list[PyDb.ObjectId]" }))
        .def("destinationBlock", &PyDbSectionSettings::destinationBlock, DS.ARGS({ "nSecType: PyDb.SectionType" }))
        .def("setDestinationBlock", &PyDbSectionSettings::setDestinationBlock, DS.ARGS({ "nSecType: PyDb.SectionType","id: PyDb.ObjectId" }))
        .def("destinationFile", &PyDbSectionSettings::destinationFile, DS.ARGS({ "nSecType: PyDb.SectionType" }))
        .def("setDestinationFile", &PyDbSectionSettings::setDestinationFile, DS.ARGS({ "nSecType: PyDb.SectionType","fileName: str" }))
        .def("visibility", &PyDbSectionSettings::visibility, DS.ARGS({ "nSecType: PyDb.SectionType","nGeometry: PyDb.SectionGeometry" }))
        .def("setVisibility", &PyDbSectionSettings::setVisibility, DS.ARGS({ "nSecType: PyDb.SectionType","nGeometry: PyDb.SectionGeometry", "flag: bool" }))
        .def("color", &PyDbSectionSettings::color, DS.ARGS({ "nSecType: PyDb.SectionType","nGeometry: PyDb.SectionGeometry" }))
        .def("setColor", &PyDbSectionSettings::setColor, DS.ARGS({ "nSecType: PyDb.SectionType","nGeometry: PyDb.SectionGeometry","clr: PyDb.Color" }))
        .def("layer", &PyDbSectionSettings::layer, DS.ARGS({ "nSecType: PyDb.SectionType","nGeometry: PyDb.SectionGeometry" }))
        .def("setLayer", &PyDbSectionSettings::setLayer, DS.ARGS({ "nSecType: PyDb.SectionType","nGeometry: PyDb.SectionGeometry","name: str" }))
        .def("linetype", &PyDbSectionSettings::linetype, DS.ARGS({ "nSecType: PyDb.SectionType","nGeometry: PyDb.SectionGeometry" }))
        .def("setLinetype", &PyDbSectionSettings::setLinetype, DS.ARGS({ "nSecType: PyDb.SectionType","nGeometry: PyDb.SectionGeometry","lineType: str" }))
        .def("linetypeScale", &PyDbSectionSettings::linetypeScale, DS.ARGS({ "nSecType: PyDb.SectionType","nGeometry: PyDb.SectionGeometry" }))
        .def("setLinetypeScale", &PyDbSectionSettings::setLinetypeScale, DS.ARGS({ "nSecType: PyDb.SectionType","nGeometry: PyDb.SectionGeometry","val: float" }))
        .def("plotStyleName", &PyDbSectionSettings::plotStyleName, DS.ARGS({ "nSecType: PyDb.SectionType","nGeometry: PyDb.SectionGeometry" }))
        .def("setPlotStyleName", &PyDbSectionSettings::setPlotStyleName, DS.ARGS({ "nSecType: PyDb.SectionType","nGeometry: PyDb.SectionGeometry","val: str" }))
        .def("lineWeight", &PyDbSectionSettings::lineWeight, DS.ARGS({ "nSecType: PyDb.SectionType","nGeometry: PyDb.SectionGeometry" }))
        .def("setLineWeight", &PyDbSectionSettings::setLineWeight, DS.ARGS({ "nSecType: PyDb.SectionType","nGeometry: PyDb.SectionGeometry","val: PyDb.LineWeight" }))
        .def("faceTransparency", &PyDbSectionSettings::faceTransparency, DS.ARGS({ "nSecType: PyDb.SectionType","nGeometry: PyDb.SectionGeometry" }))
        .def("setFaceTransparency", &PyDbSectionSettings::setFaceTransparency, DS.ARGS({ "nSecType: PyDb.SectionType","nGeometry: PyDb.SectionGeometry","val: int" }))
        .def("edgeTransparency", &PyDbSectionSettings::edgeTransparency, DS.ARGS({ "nSecType: PyDb.SectionType","nGeometry: PyDb.SectionGeometry" }))
        .def("setEdgeTransparency", &PyDbSectionSettings::setEdgeTransparency, DS.ARGS({ "nSecType: PyDb.SectionType","nGeometry: PyDb.SectionGeometry","val: int" }))
        .def("hatchVisibility", &PyDbSectionSettings::hatchVisibility, DS.ARGS({ "nSecType: PyDb.SectionType","nGeometry: PyDb.SectionGeometry" }))
        .def("setHatchVisibility", &PyDbSectionSettings::setHatchVisibility, DS.ARGS({ "nSecType: PyDb.SectionType","nGeometry: PyDb.SectionGeometry","val: bool" }))
        .def("getHatchPattern", &PyDbSectionSettings::getHatchPattern, DS.ARGS({ "nSecType: PyDb.SectionType","nGeometry: PyDb.SectionGeometry" }))
        .def("setHatchPattern", &PyDbSectionSettings::setHatchPattern, DS.ARGS({ "nSecType: PyDb.SectionType","nGeometry: PyDb.SectionGeometry","pattern: PyDb.HatchPatternType", "name: str" }))
        .def("hatchAngle", &PyDbSectionSettings::hatchAngle, DS.ARGS({ "nSecType: PyDb.SectionType","nGeometry: PyDb.SectionGeometry" }))
        .def("setHatchAngle", &PyDbSectionSettings::setHatchAngle, DS.ARGS({ "nSecType: PyDb.SectionType","nGeometry: PyDb.SectionGeometry","val: float" }))
        .def("hatchSpacing", &PyDbSectionSettings::hatchSpacing, DS.ARGS({ "nSecType: PyDb.SectionType","nGeometry: PyDb.SectionGeometry" }))
        .def("setHatchSpacing", &PyDbSectionSettings::setHatchSpacing, DS.ARGS({ "nSecType: PyDb.SectionType","nGeometry: PyDb.SectionGeometry","val: float" }))
        .def("hatchScale", &PyDbSectionSettings::hatchScale, DS.ARGS({ "nSecType: PyDb.SectionType","nGeometry: PyDb.SectionGeometry" }))
        .def("setHatchScale", &PyDbSectionSettings::setHatchScale, DS.ARGS({ "nSecType: PyDb.SectionType","nGeometry: PyDb.SectionGeometry","val: float" }))
        .def("hiddenLine", &PyDbSectionSettings::hiddenLine, DS.ARGS({ "nSecType: PyDb.SectionType","nGeometry: PyDb.SectionGeometry" }))
        .def("setHiddenLine", &PyDbSectionSettings::setHiddenLine, DS.ARGS({ "nSecType: PyDb.SectionType","nGeometry: PyDb.SectionGeometry","val: bool" }))
        .def("divisionLines", &PyDbSectionSettings::divisionLines, DS.ARGS({ "nSecType: PyDb.SectionType","nGeometry: PyDb.SectionGeometry" }))
        .def("setDivisionLines", &PyDbSectionSettings::setDivisionLines, DS.ARGS({ "nSecType: PyDb.SectionType","nGeometry: PyDb.SectionGeometry","show: bool" }))

        .def("className", &PyDbSectionSettings::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbSectionSettings::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyDbSectionSettings::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbSectionSettings::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
    enum_<AcDbSectionSettings::SectionType>("SectionType")
        .value("kLiveSection", AcDbSectionSettings::SectionType::kLiveSection)
        .value("k2dSection", AcDbSectionSettings::SectionType::k2dSection)
        .value("k3dSection", AcDbSectionSettings::SectionType::k3dSection)
        .export_values()
        ;
    enum_<AcDbSectionSettings::Geometry>("SectionGeometry")
        .value("kIntersectionBoundary", AcDbSectionSettings::Geometry::kIntersectionBoundary)
        .value("kIntersectionFill", AcDbSectionSettings::Geometry::kIntersectionFill)
        .value("kBackgroundGeometry", AcDbSectionSettings::Geometry::kBackgroundGeometry)
        .value("kForegroundGeometry", AcDbSectionSettings::Geometry::kForegroundGeometry)
        .value("kCurveTangencyLines", AcDbSectionSettings::Geometry::kCurveTangencyLines)
        .export_values()
        ;
    enum_<AcDbSectionSettings::Generation>("SectionGeneration")
        .value("kSourceAllObjects", AcDbSectionSettings::Generation::kSourceAllObjects)
        .value("kSourceSelectedObjects", AcDbSectionSettings::Generation::kSourceSelectedObjects)
        .value("kDestinationNewBlock", AcDbSectionSettings::Generation::kDestinationNewBlock)
        .value("kDestinationReplaceBlock", AcDbSectionSettings::Generation::kDestinationReplaceBlock)
        .value("kDestinationFile", AcDbSectionSettings::Generation::kDestinationFile)
        .export_values()
        ;
}

PyDbSectionSettings::PyDbSectionSettings()
    : PyDbSectionSettings(new AcDbSectionSettings(), true)
{
}

PyDbSectionSettings::PyDbSectionSettings(const PyDbObjectId& id)
    : PyDbSectionSettings(openAcDbObject<AcDbSectionSettings>(id, AcDb::OpenMode::kForRead), false)
{
}

PyDbSectionSettings::PyDbSectionSettings(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbSectionSettings(openAcDbObject<AcDbSectionSettings>(id, mode), false)
{
}

PyDbSectionSettings::PyDbSectionSettings(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbSectionSettings(openAcDbObject<AcDbSectionSettings>(id, mode, erased), false)
{
}

PyDbSectionSettings::PyDbSectionSettings(AcDbSectionSettings* ptr, bool autoDelete)
    : PyDbObject(ptr, autoDelete)
{
}

void PyDbSectionSettings::reset1(void) const
{
    PyThrowBadEs(impObj()->reset());
}

void PyDbSectionSettings::reset2(AcDbSectionSettings::SectionType nSecType) const
{
    PyThrowBadEs(impObj()->reset(nSecType));
}

AcDbSectionSettings::SectionType PyDbSectionSettings::currentSectionType(void) const
{
    return impObj()->currentSectionType();
}

void PyDbSectionSettings::setCurrentSectionType(AcDbSectionSettings::SectionType nSecType) const
{
    PyThrowBadEs(impObj()->setCurrentSectionType(nSecType));
}

AcDbSectionSettings::Generation PyDbSectionSettings::generationOptions(AcDbSectionSettings::SectionType nSecType) const
{
    return impObj()->generationOptions(nSecType);
}

void PyDbSectionSettings::setGenerationOptions(AcDbSectionSettings::SectionType nSecType, AcDbSectionSettings::Generation nOptions) const
{
    PyThrowBadEs(impObj()->setGenerationOptions(nSecType, nOptions));
}

boost::python::list PyDbSectionSettings::getSourceObjects(AcDbSectionSettings::SectionType nSecType) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    PyAutoLockGIL lock;
    AcDbObjectIdArray ids;
    PyThrowBadEs(impObj()->getSourceObjects(nSecType, ids));
    return ObjectIdArrayToPyList(ids);
#endif
}

void PyDbSectionSettings::setSourceObjects(AcDbSectionSettings::SectionType nSecType, const boost::python::list& ids) const
{
    PyThrowBadEs(impObj()->setSourceObjects(nSecType, PyListToObjectIdArray(ids)));
}

PyDbObjectId PyDbSectionSettings::destinationBlock(AcDbSectionSettings::SectionType nSecType) const
{
    return PyDbObjectId(impObj()->destinationBlock(nSecType));
}

void PyDbSectionSettings::setDestinationBlock(AcDbSectionSettings::SectionType nSecType, const PyDbObjectId& id) const
{
    PyThrowBadEs(impObj()->setDestinationBlock(nSecType, id.m_id));
}

std::string PyDbSectionSettings::destinationFile(AcDbSectionSettings::SectionType nSecType) const
{
    return wstr_to_utf8(impObj()->destinationFile(nSecType));
}

void PyDbSectionSettings::setDestinationFile(AcDbSectionSettings::SectionType nSecType, const std::string& pszFileName) const
{
    PyThrowBadEs(impObj()->setDestinationFile(nSecType, utf8_to_wstr(pszFileName).c_str()));
}

bool PyDbSectionSettings::visibility(AcDbSectionSettings::SectionType nSecType, AcDbSectionSettings::Geometry nGeometry) const
{
    return impObj()->visibility(nSecType, nGeometry);
}

void PyDbSectionSettings::setVisibility(AcDbSectionSettings::SectionType nSecType, AcDbSectionSettings::Geometry nGeometry, bool bVisible) const
{
    PyThrowBadEs(impObj()->setVisibility(nSecType, nGeometry, bVisible));
}

AcCmColor PyDbSectionSettings::color(AcDbSectionSettings::SectionType nSecType, AcDbSectionSettings::Geometry nGeometry) const
{
    return impObj()->color(nSecType, nGeometry);
}

void PyDbSectionSettings::setColor(AcDbSectionSettings::SectionType nSecType, AcDbSectionSettings::Geometry nGeometry, const AcCmColor& color) const
{
    PyThrowBadEs(impObj()->setColor(nSecType, nGeometry, color));
}

std::string PyDbSectionSettings::layer(AcDbSectionSettings::SectionType nSecType, AcDbSectionSettings::Geometry nGeometry) const
{
    return wstr_to_utf8(impObj()->layer(nSecType, nGeometry));
}

void PyDbSectionSettings::setLayer(AcDbSectionSettings::SectionType nSecType, AcDbSectionSettings::Geometry nGeometry, const std::string& pszLayer) const
{
    PyThrowBadEs(impObj()->setLayer(nSecType, nGeometry, utf8_to_wstr(pszLayer).c_str()));
}

std::string PyDbSectionSettings::linetype(AcDbSectionSettings::SectionType nSecType, AcDbSectionSettings::Geometry nGeometry) const
{
    return wstr_to_utf8(impObj()->linetype(nSecType, nGeometry));
}

void PyDbSectionSettings::setLinetype(AcDbSectionSettings::SectionType nSecType, AcDbSectionSettings::Geometry nGeometry, const std::string& pszLinetype) const
{
    PyThrowBadEs(impObj()->setLinetype(nSecType, nGeometry, utf8_to_wstr(pszLinetype).c_str()));
}

double PyDbSectionSettings::linetypeScale(AcDbSectionSettings::SectionType nSecType, AcDbSectionSettings::Geometry nGeometry) const
{
    return impObj()->linetypeScale(nSecType, nGeometry);
}

void PyDbSectionSettings::setLinetypeScale(AcDbSectionSettings::SectionType nSecType, AcDbSectionSettings::Geometry nGeometry, double fScale) const
{
    PyThrowBadEs(impObj()->setLinetypeScale(nSecType, nGeometry, fScale));
}

std::string PyDbSectionSettings::plotStyleName(AcDbSectionSettings::SectionType nSecType, AcDbSectionSettings::Geometry nGeometry) const
{
    return wstr_to_utf8(impObj()->plotStyleName(nSecType, nGeometry));
}

void PyDbSectionSettings::setPlotStyleName(AcDbSectionSettings::SectionType nSecType, AcDbSectionSettings::Geometry nGeometry, const std::string& pszPlotStyleName) const
{
    PyThrowBadEs(impObj()->setPlotStyleName(nSecType, nGeometry, utf8_to_wstr(pszPlotStyleName).c_str()));
}

AcDb::LineWeight PyDbSectionSettings::lineWeight(AcDbSectionSettings::SectionType nSecType, AcDbSectionSettings::Geometry nGeometry) const
{
    return impObj()->lineWeight(nSecType, nGeometry);
}

void PyDbSectionSettings::setLineWeight(AcDbSectionSettings::SectionType nSecType, AcDbSectionSettings::Geometry nGeometry, AcDb::LineWeight nLineWeight) const
{
    PyThrowBadEs(impObj()->setLineWeight(nSecType, nGeometry, nLineWeight));
}

int PyDbSectionSettings::faceTransparency(AcDbSectionSettings::SectionType nSecType, AcDbSectionSettings::Geometry nGeometry) const
{
    return impObj()->faceTransparency(nSecType, nGeometry);
}

void PyDbSectionSettings::setFaceTransparency(AcDbSectionSettings::SectionType nSecType, AcDbSectionSettings::Geometry nGeometry, int nTransparency) const
{
    PyThrowBadEs(impObj()->setFaceTransparency(nSecType, nGeometry, nTransparency));
}

int PyDbSectionSettings::edgeTransparency(AcDbSectionSettings::SectionType nSecType, AcDbSectionSettings::Geometry nGeometry) const
{
    return impObj()->edgeTransparency(nSecType, nGeometry);
}

void PyDbSectionSettings::setEdgeTransparency(AcDbSectionSettings::SectionType nSecType, AcDbSectionSettings::Geometry nGeometry, int nTransparency) const
{
    PyThrowBadEs(impObj()->setEdgeTransparency(nSecType, nGeometry, nTransparency));
}

bool PyDbSectionSettings::hatchVisibility(AcDbSectionSettings::SectionType nSecType, AcDbSectionSettings::Geometry nGeometry) const
{
    return impObj()->hatchVisibility(nSecType, nGeometry);
}

void PyDbSectionSettings::setHatchVisibility(AcDbSectionSettings::SectionType nSecType, AcDbSectionSettings::Geometry nGeometry, bool bVisible) const
{
    PyThrowBadEs(impObj()->setHatchVisibility(nSecType, nGeometry, bVisible));
}

boost::python::tuple PyDbSectionSettings::getHatchPattern(AcDbSectionSettings::SectionType nSecType, AcDbSectionSettings::Geometry nGeometry) const
{
    PyAutoLockGIL lock;
    AcDbHatch::HatchPatternType nPatternType = AcDbHatch::kUserDefined;
    const TCHAR* val = nullptr;
    PyThrowBadEs(impObj()->getHatchPattern(nSecType, nGeometry, nPatternType, val));
    return boost::python::make_tuple(nPatternType, wstr_to_utf8(val));
}

void PyDbSectionSettings::setHatchPattern(AcDbSectionSettings::SectionType nSecType, AcDbSectionSettings::Geometry nGeometry, AcDbHatch::HatchPatternType nPatternType, const std::string& pszPatternName) const
{
    PyThrowBadEs(impObj()->setHatchPattern(nSecType, nGeometry, nPatternType, utf8_to_wstr(pszPatternName).c_str()));
}

double PyDbSectionSettings::hatchAngle(AcDbSectionSettings::SectionType nSecType, AcDbSectionSettings::Geometry nGeometry) const
{
    return impObj()->hatchAngle(nSecType, nGeometry);
}

void PyDbSectionSettings::setHatchAngle(AcDbSectionSettings::SectionType nSecType, AcDbSectionSettings::Geometry nGeometry, double fAngle) const
{
    PyThrowBadEs(impObj()->setHatchAngle(nSecType, nGeometry, fAngle));
}

double PyDbSectionSettings::hatchSpacing(AcDbSectionSettings::SectionType nSecType, AcDbSectionSettings::Geometry nGeometry) const
{
    return impObj()->hatchSpacing(nSecType, nGeometry);
}

void PyDbSectionSettings::setHatchSpacing(AcDbSectionSettings::SectionType nSecType, AcDbSectionSettings::Geometry nGeometry, double fSpacing) const
{
    PyThrowBadEs(impObj()->setHatchSpacing(nSecType, nGeometry, fSpacing));
}

double PyDbSectionSettings::hatchScale(AcDbSectionSettings::SectionType nSecType, AcDbSectionSettings::Geometry nGeometry) const
{
    return impObj()->hatchScale(nSecType, nGeometry);
}

void PyDbSectionSettings::setHatchScale(AcDbSectionSettings::SectionType nSecType, AcDbSectionSettings::Geometry nGeometry, double fScale) const
{
    PyThrowBadEs(impObj()->setHatchScale(nSecType, nGeometry, fScale));
}

bool PyDbSectionSettings::hiddenLine(AcDbSectionSettings::SectionType nSecType, AcDbSectionSettings::Geometry nGeometry) const
{
    return impObj()->hiddenLine(nSecType, nGeometry);
}

void PyDbSectionSettings::setHiddenLine(AcDbSectionSettings::SectionType nSecType, AcDbSectionSettings::Geometry nGeometry, bool bHiddenLine) const
{
    PyThrowBadEs(impObj()->setHiddenLine(nSecType, nGeometry, bHiddenLine));
}

bool PyDbSectionSettings::divisionLines(AcDbSectionSettings::SectionType nSecType, AcDbSectionSettings::Geometry nGeometry) const
{
    return impObj()->divisionLines(nSecType, nGeometry);
}

void PyDbSectionSettings::setDivisionLines(AcDbSectionSettings::SectionType nSecType, AcDbSectionSettings::Geometry nGeometry, bool bShow) const
{
    PyThrowBadEs(impObj()->setDivisionLines(nSecType, nGeometry, bShow));
}

PyRxClass PyDbSectionSettings::desc()
{
    return PyRxClass(AcDbSectionSettings::desc(), false);
}

std::string PyDbSectionSettings::className()
{
    return "AcDbSectionSettings";
}

PyDbSectionSettings PyDbSectionSettings::cloneFrom(const PyRxObject& src)
{
    return PyDbObjectCloneFrom<PyDbSectionSettings, AcDbSectionSettings>(src);
}

PyDbSectionSettings PyDbSectionSettings::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbSectionSettings>(src);
}

AcDbSectionSettings* PyDbSectionSettings::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbSectionSettings*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//PyDbSection
void makePyDbSectionWrapper()
{
    constexpr const std::string_view ctords = "Overloads:\n"
        "- None: Any\n"
        "- pts: list[PyGe.Point3d], verticalDir: PyGe.Vector3d\n"
        "- pts: list[PyGe.Point3d], verticalDir: PyGe.Vector3d, vecViewingDir: PyGe.Vector3d\n"
        "- id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode, erased: bool\n";

    PyDocString DS("PyDb.Section");
    class_<PyDbSection, bases<PyDbEntity>>("Section")
        .def(init<>())
        .def(init<const boost::python::list&, const AcGeVector3d&>())
        .def(init<const boost::python::list&, const AcGeVector3d&, const AcGeVector3d&>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.CTOR(ctords, 8495)))
        .def("state", &PyDbSection::state, DS.ARGS())
        .def("setState", &PyDbSection::setState, DS.ARGS({ "state: PyDb.SectionState" }))
        .def("getName", &PyDbSection::getName, DS.ARGS())
        .def("setName", &PyDbSection::setName, DS.ARGS({ "name: str" }))
        .def("viewingDirection", &PyDbSection::viewingDirection, DS.ARGS())
        .def("setViewingDirection", &PyDbSection::setViewingDirection, DS.ARGS({ "vec: PyGe.Vector3d" }))
        .def("verticalDirection", &PyDbSection::verticalDirection, DS.ARGS())
        .def("setVerticalDirection", &PyDbSection::setVerticalDirection, DS.ARGS({ "vec: PyGe.Vector3d" }))
        .def("normal", &PyDbSection::normal, DS.ARGS())
        .def("plane", &PyDbSection::plane, DS.ARGS())
        .def("indicatorTransparency", &PyDbSection::indicatorTransparency, DS.ARGS())
        .def("setIndicatorTransparency", &PyDbSection::setIndicatorTransparency, DS.ARGS({ "val: int" }))
        .def("indicatorFillColor", &PyDbSection::indicatorFillColor, DS.ARGS())
        .def("setIndicatorFillColor", &PyDbSection::setIndicatorFillColor, DS.ARGS({ "clr: PyDb.Color" }))
        .def("numVertices", &PyDbSection::numVertices, DS.ARGS())
        .def("getVertex", &PyDbSection::getVertex, DS.ARGS({ "val: int" }))
        .def("setVertex", &PyDbSection::setVertex, DS.ARGS({ "val: int","pt: PyGe.Point3d" }))
        .def("addVertex", &PyDbSection::addVertex, DS.ARGS({ "val: int","pt: PyGe.Point3d" }))
        .def("removeVertex", &PyDbSection::removeVertex, DS.ARGS({ "val: int" }))
        .def("getVertices", &PyDbSection::getVertices, DS.ARGS())
        .def("setVertices", &PyDbSection::setVertices, DS.ARGS({ "ids: list[PyDb.ObjectId]" }))
        .def("height", &PyDbSection::height, DS.ARGS())
        .def("setHeight", &PyDbSection::setHeight, DS.ARGS({ "nHeightType: PyDb.SectionHeight","val: float" }))
        .def("hitTest", &PyDbSection::hitTest, DS.ARGS({ "pt: PyGe.Point3d" }))
        .def("createJog", &PyDbSection::createJog, DS.ARGS({ "pt: PyGe.Point3d" }))
        .def("getSettings", &PyDbSection::getSettings, DS.ARGS())
        .def("isLiveSectionEnabled", &PyDbSection::isLiveSectionEnabled, DS.ARGS())
        .def("enableLiveSection", &PyDbSection::enableLiveSection, DS.ARGS({ "val: bool" }))
        .def("generateSectionGeometry", &PyDbSection::generateSectionGeometry, DS.ARGS({ "entity: PyDb.Entity" }))
        .def("elevation", &PyDbSection::elevation, DS.ARGS())
        .def("setElevation", &PyDbSection::setElevation, DS.ARGS({ "val: float" }))
        .def("topPlane", &PyDbSection::topPlane, DS.ARGS())
        .def("setTopPlane", &PyDbSection::setTopPlane, DS.ARGS({ "val: float" }))
        .def("bottomPlane", &PyDbSection::bottomPlane, DS.ARGS())
        .def("setBottomPlane", &PyDbSection::setBottomPlane, DS.ARGS({ "val: float" }))
        .def("isSlice", &PyDbSection::isSlice, DS.ARGS())
        .def("setIsSlice", &PyDbSection::setIsSlice, DS.ARGS({ "val: bool" }))
        .def("thicknessDepth", &PyDbSection::thicknessDepth, DS.ARGS({ "val: bool" }))
        .def("setThicknessDepth", &PyDbSection::setThicknessDepth, DS.ARGS({ "val: float" }))
        .def("hasJogs", &PyDbSection::hasJogs, DS.ARGS())
        .def("sectionPlaneOffset", &PyDbSection::sectionPlaneOffset, DS.ARGS())
        .def("setSectionPlaneOffset", &PyDbSection::setSectionPlaneOffset, DS.ARGS({ "val: float" }))
        .def("className", &PyDbSection::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbSection::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyDbSection::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbSection::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;

    enum_<AcDbSection::State>("SectionState")
        .value("kPlane", AcDbSection::State::kPlane)
        .value("kBoundary", AcDbSection::State::kBoundary)
        .value("kVolume", AcDbSection::State::kVolume)
        .export_values()
        ;
    enum_<AcDbSection::SubItem>("SectionSubItem")
        .value("kNone", AcDbSection::SubItem::kNone)
        .value("kSectionLine", AcDbSection::SubItem::kSectionLine)
        .value("kSectionLineTop", AcDbSection::SubItem::kSectionLineTop)
        .value("kSectionLineBottom", AcDbSection::SubItem::kSectionLineBottom)
        .value("kBackLine", AcDbSection::SubItem::kBackLine)
        .value("kBackLineTop", AcDbSection::SubItem::kBackLineTop)
        .value("kBackLineBottom", AcDbSection::SubItem::kBackLineBottom)
        .value("kVerticalLineTop", AcDbSection::SubItem::kVerticalLineTop)
        .value("kVerticalLineBottom", AcDbSection::SubItem::kVerticalLineBottom)
        .export_values()
        ;
    enum_<AcDbSection::Height>("SectionHeight")
        .value("kHeightAboveSectionLine", AcDbSection::Height::kHeightAboveSectionLine)
        .value("kHeightBelowSectionLine", AcDbSection::Height::kHeightBelowSectionLine)
        .export_values()
        ;
}

PyDbSection::PyDbSection()
    : PyDbSection::PyDbSection(new AcDbSection(), true)
{
}

PyDbSection::PyDbSection(const boost::python::list& pts, const AcGeVector3d& verticalDir)
    : PyDbSection::PyDbSection(new AcDbSection(PyListToPoint3dArray(pts), verticalDir), true)
{
}

PyDbSection::PyDbSection(const boost::python::list& pts, const AcGeVector3d& verticalDir, const AcGeVector3d& vecViewingDir)
    : PyDbSection::PyDbSection(new AcDbSection(PyListToPoint3dArray(pts), verticalDir, vecViewingDir), true)
{
}

PyDbSection::PyDbSection(const PyDbObjectId& id)
    : PyDbSection(openAcDbObject<AcDbSection>(id, AcDb::OpenMode::kForRead), false)
{
}

PyDbSection::PyDbSection(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbSection(openAcDbObject<AcDbSection>(id, mode), false)
{
}

PyDbSection::PyDbSection(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbSection(openAcDbObject<AcDbSection>(id, mode, erased), false)
{
}

PyDbSection::PyDbSection(AcDbSection* ptr, bool autoDelete)
    : PyDbEntity(ptr, autoDelete)
{
}

AcDbSection::State PyDbSection::state(void) const
{
    return impObj()->state();
}

void PyDbSection::setState(AcDbSection::State nState) const
{
    PyThrowBadEs(impObj()->setState(nState));
}

std::string PyDbSection::getName() const
{
    return wstr_to_utf8(impObj()->getName());
}

void PyDbSection::setName(const std::string& name) const
{
    PyThrowBadEs(impObj()->setName(utf8_to_wstr(name).c_str()));
}

AcGeVector3d PyDbSection::viewingDirection(void) const
{
    return impObj()->viewingDirection();
}

void PyDbSection::setViewingDirection(const AcGeVector3d& dir) const
{
    PyThrowBadEs(impObj()->setViewingDirection(dir));
}

AcGeVector3d PyDbSection::verticalDirection(void) const
{
    return impObj()->verticalDirection();
}

void PyDbSection::setVerticalDirection(const AcGeVector3d& dir) const
{
    PyThrowBadEs(impObj()->setVerticalDirection(dir));
}

AcGeVector3d PyDbSection::normal(void) const
{
    return impObj()->normal();
}

boost::python::tuple PyDbSection::plane() const
{
    PyAutoLockGIL lock;
    AcGeVector3d uAxis;
    AcGeVector3d vAxis;
    PyThrowBadEs(impObj()->plane(uAxis, vAxis));
    return boost::python::make_tuple(uAxis, vAxis);
}

int PyDbSection::indicatorTransparency(void) const
{
    return impObj()->indicatorTransparency();
}

void PyDbSection::setIndicatorTransparency(int nTransparency) const
{
    PyThrowBadEs(impObj()->setIndicatorTransparency(nTransparency));
}

AcCmColor PyDbSection::indicatorFillColor(void) const
{
    return impObj()->indicatorFillColor();
}

void PyDbSection::setIndicatorFillColor(const AcCmColor& color) const
{
    PyThrowBadEs(impObj()->setIndicatorFillColor(color));
}

int PyDbSection::numVertices(void) const
{
    return impObj()->numVertices();
}

AcGePoint3d PyDbSection::getVertex(int nIndex) const
{
    AcGePoint3d pt;
    PyThrowBadEs(impObj()->getVertex(nIndex, pt));
    return pt;
}

void PyDbSection::setVertex(int nIndex, const AcGePoint3d& pt) const
{
    PyThrowBadEs(impObj()->setVertex(nIndex, pt));
}

void PyDbSection::addVertex(int nInsertAt, const AcGePoint3d& pt) const
{
    PyThrowBadEs(impObj()->addVertex(nInsertAt, pt));
}

void PyDbSection::removeVertex(int nIndex) const
{
    PyThrowBadEs(impObj()->removeVertex(nIndex));
}

boost::python::list PyDbSection::getVertices() const
{
    PyAutoLockGIL lock;
    AcGePoint3dArray pts;
    PyThrowBadEs(impObj()->getVertices(pts));
    return Point3dArrayToPyList(pts);
}

void PyDbSection::setVertices(const boost::python::list& pts) const
{
    PyThrowBadEs(impObj()->setVertices(PyListToPoint3dArray(pts)));
}

double PyDbSection::height(AcDbSection::Height nHeightType) const
{
    return impObj()->height(nHeightType);
}

void PyDbSection::setHeight(AcDbSection::Height nHeightType, double fHeight) const
{
    PyThrowBadEs(impObj()->setHeight(nHeightType, fHeight));
}

boost::python::tuple PyDbSection::hitTest(const AcGePoint3d& ptHit) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    PyAutoLockGIL lock;
    int pSegmentIndex = -1;
    AcGePoint3d ptOnSegment;
    AcDbSection::SubItem pSubItem = AcDbSection::SubItem::kNone;
    bool res = impObj()->hitTest(ptHit, &pSegmentIndex, &ptOnSegment, &pSubItem);
    return boost::python::make_tuple(res, pSegmentIndex, ptOnSegment, pSubItem);
#endif
}

void PyDbSection::createJog(const AcGePoint3d& ptOnSection) const
{
    PyThrowBadEs(impObj()->createJog(ptOnSection));
}

PyDbObjectId PyDbSection::getSettings(void) const
{
    return PyDbObjectId(impObj()->getSettings());
}

bool PyDbSection::isLiveSectionEnabled(void) const
{
    return impObj()->isLiveSectionEnabled();
}

void PyDbSection::enableLiveSection(bool bEnable) const
{
    PyThrowBadEs(impObj()->enableLiveSection(bEnable));
}

boost::python::tuple PyDbSection::generateSectionGeometry(const PyDbEntity& pEnt) const
{
    PyAutoLockGIL lock;
    AcArray<AcDbEntity*> intBoundaryEnts;
    AcArray<AcDbEntity*> intFillEnts;
    AcArray<AcDbEntity*> backgroundEnts;
    AcArray<AcDbEntity*> foregroundEnts;
    AcArray<AcDbEntity*> curveTangencyEnts;
    PyThrowBadEs(impObj()->generateSectionGeometry(pEnt.impObj(), intBoundaryEnts, intFillEnts, backgroundEnts, foregroundEnts, curveTangencyEnts));
    return boost::python::make_tuple(
        AcDbEntityArrayToPyList(intBoundaryEnts),
        AcDbEntityArrayToPyList(intFillEnts),
        AcDbEntityArrayToPyList(backgroundEnts),
        AcDbEntityArrayToPyList(foregroundEnts),
        AcDbEntityArrayToPyList(curveTangencyEnts));
}

double PyDbSection::elevation() const
{
    return impObj()->elevation();
}

void PyDbSection::setElevation(double elev) const
{
    PyThrowBadEs(impObj()->setElevation(elev));
}

double PyDbSection::topPlane() const
{
    return impObj()->topPlane();
}

void PyDbSection::setTopPlane(double val) const
{
    PyThrowBadEs(impObj()->setTopPlane(val));
}

double PyDbSection::bottomPlane() const
{
    return impObj()->bottomPlane();
}

void PyDbSection::setBottomPlane(double val) const
{
    PyThrowBadEs(impObj()->setBottomPlane(val));
}

bool PyDbSection::isSlice() const
{
    return impObj()->isSlice();
}

void PyDbSection::setIsSlice(bool value) const
{
    PyThrowBadEs(impObj()->setIsSlice(value));
}

double PyDbSection::thicknessDepth() const
{
    return impObj()->thicknessDepth();
}

void PyDbSection::setThicknessDepth(double fThickness) const
{
    PyThrowBadEs(impObj()->setThicknessDepth(fThickness));
}

bool PyDbSection::hasJogs() const
{
    return impObj()->hasJogs();
}

double PyDbSection::sectionPlaneOffset() const
{
    return impObj()->sectionPlaneOffset();
}

void PyDbSection::setSectionPlaneOffset(double offset) const
{
    PyThrowBadEs(impObj()->setSectionPlaneOffset(offset));
}

std::string PyDbSection::className()
{
    return "AcDbSection";
}

PyRxClass PyDbSection::desc()
{
    return PyRxClass(AcDbText::desc(), false);
}

PyDbSection PyDbSection::cloneFrom(const PyRxObject& src)
{
    return PyDbObjectCloneFrom<PyDbSection, AcDbSection>(src);
}

PyDbSection PyDbSection::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbSection>(src);
}

AcDbSection* PyDbSection::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbSection*>(m_pyImp.get());
}
