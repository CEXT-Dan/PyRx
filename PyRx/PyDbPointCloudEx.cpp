#include "stdafx.h"
#include "PyDbPointCloudEx.h"
#include "PyDbObjectId.h"
#include "PyDbDatabase.h"

using namespace boost::python;

//-----------------------------------------------------------------------------------
//PyDbPointCloudDefEx
void makePyDbPointCloudDefExWrapper()
{
    PyDocString DS("PointCloudDefEx");
    class_<PyDbPointCloudDefEx, bases<PyDbObject>>("PointCloudDefEx", boost::python::no_init)
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.ARGS({ "id: ObjectId", "mode: OpenMode=kForRead", "erased: bool=False" })))

        .def("load", &PyDbPointCloudDefEx::load)
        .def("unload", &PyDbPointCloudDefEx::unload)
        .def("isLoaded", &PyDbPointCloudDefEx::isLoaded)
        .def("entityCount", &PyDbPointCloudDefEx::entityCount)
        .def("setSourceFileName", &PyDbPointCloudDefEx::setSourceFileName)
        .def("sourceFileName", &PyDbPointCloudDefEx::sourceFileName)
        .def("setActiveFileName", &PyDbPointCloudDefEx::setActiveFileName)
        .def("activeFileName", &PyDbPointCloudDefEx::activeFileName)
        .def("fileType", &PyDbPointCloudDefEx::fileType)
        .def("totalPointsCount", &PyDbPointCloudDefEx::totalPointsCount)
        .def("totalRegionsCount", &PyDbPointCloudDefEx::totalRegionsCount)
        .def("totalScansCount", &PyDbPointCloudDefEx::totalScansCount)
        .def("defaultWidth", &PyDbPointCloudDefEx::defaultWidth)
        .def("defaultLength", &PyDbPointCloudDefEx::defaultLength)
        .def("defaultHeight", &PyDbPointCloudDefEx::defaultHeight)
        .def("hasProperty", &PyDbPointCloudDefEx::hasProperty)
        .def("extents", &PyDbPointCloudDefEx::extents)
        .def("coordinateSystemName", &PyDbPointCloudDefEx::coordinateSystemName)
        .def("getRcsFilePath", &PyDbPointCloudDefEx::getRcsFilePath)
        .def("getAllRcsFilePaths", &PyDbPointCloudDefEx::getAllRcsFilePaths)
        .def("pointCloudExDictionary", &PyDbPointCloudDefEx::pointCloudExDictionary).staticmethod("pointCloudExDictionary")
        .def("createPointCloudExDictionary", &PyDbPointCloudDefEx::createPointCloudExDictionary).staticmethod("createPointCloudExDictionary")
        .def("classVersion", &PyDbPointCloudDefEx::classVersion).staticmethod("classVersion")

        .def("className", &PyDbPointCloudDefEx::className).staticmethod("className")
        .def("desc", &PyDbPointCloudDefEx::desc).staticmethod("desc")
        .def("cloneFrom", &PyDbPointCloudDefEx::cloneFrom).staticmethod("cloneFrom")
        .def("cast", &PyDbPointCloudDefEx::cast).staticmethod("cast")
        ;

    enum_<AcDbPointCloudDefEx::PropState>("PointCloudPropertyState")
        .value("kNone", AcDbPointCloudDefEx::PropState::kNone)
        .value("kSome", AcDbPointCloudDefEx::PropState::kSome)
        .value("kAll", AcDbPointCloudDefEx::PropState::kAll)
        .export_values()
        ;

    enum_<AcDbPointCloudDefEx::Property>("PointCloudProperty")
        .value("kColor", AcDbPointCloudDefEx::Property::kColor)
        .value("kIntensity", AcDbPointCloudDefEx::Property::kIntensity)
        .value("kClassification", AcDbPointCloudDefEx::Property::kClassification)
        .value("kNormal", AcDbPointCloudDefEx::Property::kNormal)
        .value("kSegmentation", AcDbPointCloudDefEx::Property::kSegmentation)
        .value("kGeoGraphic", AcDbPointCloudDefEx::Property::kGeoGraphic)
        .export_values()
        ;
}

PyDbPointCloudDefEx::PyDbPointCloudDefEx()
    : PyDbPointCloudDefEx(new AcDbPointCloudDefEx(), true)
{
}

PyDbPointCloudDefEx::PyDbPointCloudDefEx(const PyDbObjectId& id)
    : PyDbPointCloudDefEx(openAcDbObject<AcDbPointCloudDefEx>(id, AcDb::OpenMode::kForRead), false)
{
}

PyDbPointCloudDefEx::PyDbPointCloudDefEx(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbPointCloudDefEx(openAcDbObject<AcDbPointCloudDefEx>(id, mode), false)
{
}

PyDbPointCloudDefEx::PyDbPointCloudDefEx(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbPointCloudDefEx(openAcDbObject<AcDbPointCloudDefEx>(id, mode, erased), false)
{
}

PyDbPointCloudDefEx::PyDbPointCloudDefEx(AcDbPointCloudDefEx* ptr, bool autoDelete)
    : PyDbObject(ptr, autoDelete)
{
}

void PyDbPointCloudDefEx::load()
{
    PyThrowBadEs(impObj()->load());
}

void PyDbPointCloudDefEx::unload()
{
    PyThrowBadEs(impObj()->unload());
}

Adesk::Boolean PyDbPointCloudDefEx::isLoaded() const
{
  return impObj()->isLoaded();
}

boost::python::tuple PyDbPointCloudDefEx::entityCount() const
{
    PyAutoLockGIL lock;
    Adesk::Boolean pbLocked = false;
    auto val = impObj()->entityCount(&pbLocked);
    return boost::python::make_tuple(val, pbLocked);
}

void PyDbPointCloudDefEx::setSourceFileName(const std::string& pPathName)
{
    PyThrowBadEs(impObj()->setSourceFileName(utf8_to_wstr(pPathName).c_str()));
}

std::string PyDbPointCloudDefEx::sourceFileName() const
{
    return wstr_to_utf8(impObj()->sourceFileName());
}

void PyDbPointCloudDefEx::setActiveFileName(const std::string& pPathName)
{
    PyThrowBadEs(impObj()->setActiveFileName(utf8_to_wstr(pPathName).c_str()));
}

std::string PyDbPointCloudDefEx::activeFileName() const
{
    return wstr_to_utf8(impObj()->activeFileName());
}

std::string PyDbPointCloudDefEx::fileType() const
{
    return wstr_to_utf8(impObj()->fileType());
}

unsigned long long PyDbPointCloudDefEx::totalPointsCount() const
{
    return impObj()->totalPointsCount();
}

int PyDbPointCloudDefEx::totalRegionsCount() const
{
    return impObj()->totalRegionsCount();
}

int PyDbPointCloudDefEx::totalScansCount() const
{
    return impObj()->totalScansCount();
}

double PyDbPointCloudDefEx::defaultWidth() const
{
    return impObj()->defaultWidth();
}

double PyDbPointCloudDefEx::defaultLength() const
{
    return impObj()->defaultLength();
}

double PyDbPointCloudDefEx::defaultHeight() const
{
    return impObj()->defaultHeight();
}

AcDbPointCloudDefEx::PropState PyDbPointCloudDefEx::hasProperty(AcDbPointCloudDefEx::Property prop) const
{
    return impObj()->hasProperty(prop);
}

AcDbExtents PyDbPointCloudDefEx::extents() const
{
    return impObj()->extents();
}

std::string PyDbPointCloudDefEx::coordinateSystemName() const
{
    return wstr_to_utf8(impObj()->coordinateSystemName());
}

std::string PyDbPointCloudDefEx::getRcsFilePath(const std::string& guid) const
{
    return wstr_to_utf8(impObj()->getRcsFilePath(utf8_to_wstr(guid).c_str()));
}

boost::python::list PyDbPointCloudDefEx::getAllRcsFilePaths() const
{
    PyAutoLockGIL lock;
    AcStringArray strlist;
    impObj()->getAllRcsFilePaths(strlist);
    boost::python::list pylist;
    for (const auto& item : strlist)
        pylist(wstr_to_utf8(item));
    return pylist;
}

PyDbObjectId PyDbPointCloudDefEx::pointCloudExDictionary(PyDbDatabase& pDb)
{
    return AcDbPointCloudDefEx::pointCloudExDictionary(pDb.impObj());
}

void PyDbPointCloudDefEx::createPointCloudExDictionary(PyDbDatabase& pDb, PyDbObjectId& dictId)
{
    PyThrowBadEs(AcDbPointCloudDefEx::createPointCloudExDictionary(pDb.impObj(), dictId.m_id));
}

int PyDbPointCloudDefEx::classVersion()
{
    return AcDbPointCloudDefEx::classVersion();
}

std::string PyDbPointCloudDefEx::className()
{
    return "AcDbPointCloudDefEx";
}

PyRxClass PyDbPointCloudDefEx::desc()
{
    return PyRxClass(AcDbPointCloudDefEx::desc(), false);
}

PyDbPointCloudDefEx PyDbPointCloudDefEx::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(AcDbPointCloudDefEx::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbPointCloudDefEx(static_cast<AcDbPointCloudDefEx*>(src.impObj()->clone()), true);
}

PyDbPointCloudDefEx PyDbPointCloudDefEx::cast(const PyRxObject& src)
{
    PyDbPointCloudDefEx dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

AcDbPointCloudDefEx* PyDbPointCloudDefEx::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<AcDbPointCloudDefEx*>(m_pyImp.get());
}


//-----------------------------------------------------------------------------------
//PyDbPointCloudEx
void makePyDbPointCloudExWrapper()
{
    PyDocString DS("PointCloudEx");
    class_<PyDbPointCloudEx, bases<PyDbEntity>>("PointCloudEx")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.ARGS({ "id: ObjectId", "mode: OpenMode=kForRead", "erased: bool=False" })))
        .def("className", &PyDbPointCloudEx::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbPointCloudEx::desc, DS.SARGS()).staticmethod("desc")
        .def("cloneFrom", &PyDbPointCloudEx::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbPointCloudEx::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}


PyDbPointCloudEx::PyDbPointCloudEx()
    : PyDbPointCloudEx(new AcDbPointCloudEx(), true)
{
}

PyDbPointCloudEx::PyDbPointCloudEx(AcDbPointCloudEx* ptr, bool autoDelete)
    : PyDbEntity(ptr, autoDelete)
{
}

PyDbPointCloudEx::PyDbPointCloudEx(const PyDbObjectId& id)
    : PyDbPointCloudEx(openAcDbObject<AcDbPointCloudEx>(id, AcDb::kForRead), false)
{
}

PyDbPointCloudEx::PyDbPointCloudEx(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbPointCloudEx(openAcDbObject<AcDbPointCloudEx>(id, mode), false)
{
}

PyDbPointCloudEx::PyDbPointCloudEx(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbPointCloudEx(openAcDbObject<AcDbPointCloudEx>(id, mode, erased), false)
{
}

std::string PyDbPointCloudEx::className()
{
    return "AcDbPointCloudEx";
}

PyRxClass PyDbPointCloudEx::desc()
{
    return PyRxClass(AcDbPointCloudEx::desc(), false);
}

PyDbPointCloudEx PyDbPointCloudEx::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(AcDbPointCloudEx::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbPointCloudEx(static_cast<AcDbPointCloudEx*>(src.impObj()->clone()), true);
}

PyDbPointCloudEx PyDbPointCloudEx::cast(const PyRxObject& src)
{
    PyDbPointCloudEx dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

AcDbPointCloudEx* PyDbPointCloudEx::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<AcDbPointCloudEx*>(m_pyImp.get());
}
