#include "stdafx.h"
#include "PyDbPointCloudEx.h"
#include "PyDbObjectId.h"
#include "PyDbDatabase.h"
#include "PyGePlane.h"


#if !defined(_BRXTARGET260)

using namespace boost::python;

//-----------------------------------------------------------------------------------
//PyDbPointCloudCrop
void makePyDbPointCloudCropWrapper()
{
    PyDocString DS("PointCloudCrop");
    class_<PyDbPointCloudCrop>("PointCloudCrop")
        .def(init<>(DS.ARGS(7547)))
        .def("clear", &PyDbPointCloudCrop::clear, DS.ARGS())
        .def("isValid", &PyDbPointCloudCrop::isValid, DS.ARGS())
        .def("type", &PyDbPointCloudCrop::type, DS.ARGS())
        .def("setCropType", &PyDbPointCloudCrop::setCropType, DS.ARGS({ "val: PointCloudCropType" }))
        .def("isInside", &PyDbPointCloudCrop::isInside, DS.ARGS())
        .def("setInside", &PyDbPointCloudCrop::setInside, DS.ARGS({ "val: bool" }))
        .def("isInverted", &PyDbPointCloudCrop::isInverted, DS.ARGS())
        .def("setInvert", &PyDbPointCloudCrop::setInvert, DS.ARGS({ "val: bool" }))
        .def("getCropPlane", &PyDbPointCloudCrop::getCropPlane, DS.ARGS())
        .def("setCropPlane", &PyDbPointCloudCrop::setCropPlane, DS.ARGS({ "plane: PyGe.Plane" }))
        .def("length", &PyDbPointCloudCrop::length, DS.ARGS())
        .def("set", &PyDbPointCloudCrop::set, DS.ARGS({ "pts: list[PyGe.Point3d]" }))
        .def("get", &PyDbPointCloudCrop::get, DS.ARGS())
        .def("className", &PyDbPointCloudCrop::className, DS.SARGS()).staticmethod("className")
        ;
}

PyDbPointCloudCrop::PyDbPointCloudCrop()
    : m_pyImp(new AcDbPointCloudCrop())
{
}

PyDbPointCloudCrop::PyDbPointCloudCrop(const AcDbPointCloudCrop& other)
    : m_pyImp(new AcDbPointCloudCrop(other))
{
}

void PyDbPointCloudCrop::clear() const
{
    impObj()->clear();
}

bool PyDbPointCloudCrop::isValid() const
{
    return impObj()->isValid();
}

AcDbPointCloudCrop::CropType PyDbPointCloudCrop::type() const
{
    return impObj()->type();
}

void PyDbPointCloudCrop::setCropType(AcDbPointCloudCrop::CropType type) const
{
    impObj()->setCropType(type);
}

bool PyDbPointCloudCrop::isInside() const
{
    return impObj()->isInside();
}

void PyDbPointCloudCrop::setInside(bool bInside) const
{
    impObj()->setInside(bInside);
}

bool PyDbPointCloudCrop::isInverted() const
{
    return impObj()->isInverted();
}

void PyDbPointCloudCrop::setInvert(bool toInvert) const
{
    impObj()->setInvert(toInvert);
}

boost::python::tuple PyDbPointCloudCrop::getCropPlane() const
{
    PyAutoLockGIL lock;
    AcGePlane plane;
    auto flag = impObj()->getCropPlane(plane);
    return boost::python::make_tuple(flag, PyGePlane(plane));
}

void PyDbPointCloudCrop::setCropPlane(const PyGePlane& plane) const
{
    impObj()->setCropPlane(*plane.impObj());
}

int PyDbPointCloudCrop::length() const
{
    return impObj()->length();
}

void PyDbPointCloudCrop::set(const boost::python::list& points) const
{
    impObj()->set(PyListToPoint3dArray(points));
}

boost::python::list PyDbPointCloudCrop::get() const
{
    return Point3dArrayToPyList(impObj()->get());
}

std::string PyDbPointCloudCrop::className()
{
    return "AcDbPointCloudCrop";
}

AcDbPointCloudCrop* PyDbPointCloudCrop::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return m_pyImp.get();
}

//-----------------------------------------------------------------------------------
//PyDbPointCloudColorRamp
void makePyDbPointCloudClassificationColorRampWrapper()
{
    PyDocString DS("PointCloudClassificationColorRamp");
    class_<PyDbPointCloudClassificationColorRamp>("PointCloudClassificationColorRamp")
        .def(init<>(DS.ARGS(7494)))
        .def("numColors", &PyDbPointCloudClassificationColorRamp::numColors, DS.ARGS())
        .def("color", &PyDbPointCloudClassificationColorRamp::color, DS.ARGS({ "val: int" }))
        .def("setColor", &PyDbPointCloudClassificationColorRamp::setColor, DS.ARGS({ "val: int", "clr: PyDb.EntityColor" }))
        .def("visibility", &PyDbPointCloudClassificationColorRamp::visibility, DS.ARGS({ "val: int" }))
        .def("setVisibility", &PyDbPointCloudClassificationColorRamp::setVisibility, DS.ARGS({ "val: int" ,"visibility: bool" }))
        .def("setFrom", &PyDbPointCloudClassificationColorRamp::setFrom, DS.ARGS({ "val: PyDb.PointCloudClassificationColorRamp" }))
        .def("name", &PyDbPointCloudClassificationColorRamp::name, DS.ARGS())
        .def("setName", &PyDbPointCloudClassificationColorRamp::setName, DS.ARGS({ "val: str" }))
        .def("className", &PyDbPointCloudClassificationColorRamp::className, DS.SARGS()).staticmethod("className")
        ;
}

PyDbPointCloudClassificationColorRamp::PyDbPointCloudClassificationColorRamp()
    : m_pyImp(new AcDbPointCloudClassificationColorRamp())
{
}

Adesk::Int32 PyDbPointCloudClassificationColorRamp::numColors() const
{
    return impObj()->numColors();
}

AcCmEntityColor PyDbPointCloudClassificationColorRamp::color(int c) const
{
    return impObj()->color(c);
}

void PyDbPointCloudClassificationColorRamp::setColor(int c, const AcCmEntityColor& color) const
{
    return impObj()->setColor(c, color);
}

bool PyDbPointCloudClassificationColorRamp::visibility(int c) const
{
    return impObj()->visibility(c);
}

void PyDbPointCloudClassificationColorRamp::setVisibility(int c, bool visibility) const
{
    return impObj()->setVisibility(c, visibility);
}

void PyDbPointCloudClassificationColorRamp::setFrom(const PyDbPointCloudClassificationColorRamp& source) const
{
    return impObj()->setFrom(source.impObj());
}

std::string PyDbPointCloudClassificationColorRamp::name() const
{
    return wstr_to_utf8(impObj()->name());
}

void PyDbPointCloudClassificationColorRamp::setName(const std::string& name) const
{
    PyThrowBadEs(impObj()->setName(utf8_to_wstr(name).c_str()));
}

std::string PyDbPointCloudClassificationColorRamp::className()
{
    return "AcDbPointCloudClassificationColorRamp";
}

AcDbPointCloudClassificationColorRamp* PyDbPointCloudClassificationColorRamp::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return m_pyImp.get();
}

//-----------------------------------------------------------------------------------
//PyDbPointCloudColorRamp
void makePyDbPointCloudColorRampWrapper()
{
    PyDocString DS("PointCloudColorRamp");
    class_<PyDbPointCloudColorRamp>("PointCloudColorRamp")
        .def(init<>(DS.ARGS(7535)))
        .def("numColors", &PyDbPointCloudColorRamp::numColors, DS.ARGS())
        .def("setNumColors", &PyDbPointCloudColorRamp::setNumColors, DS.ARGS({ "val: int" }))
        .def("color", &PyDbPointCloudColorRamp::color, DS.ARGS({ "val: int" }))
        .def("setColor", &PyDbPointCloudColorRamp::setColor, DS.ARGS({ "val: int", "clr: PyDb.EntityColor" }))
        .def("visibility", &PyDbPointCloudColorRamp::visibility, DS.ARGS({ "val: int" }))
        .def("setVisibility", &PyDbPointCloudColorRamp::setVisibility, DS.ARGS({ "val: int" ,"visibility: bool" }))
        .def("setFrom", &PyDbPointCloudColorRamp::setFrom, DS.ARGS({ "val: PyDb.PointCloudColorRamp" }))
        .def("name", &PyDbPointCloudColorRamp::name, DS.ARGS())
        .def("setName", &PyDbPointCloudColorRamp::setName, DS.ARGS({ "val: str" }))
        .def("className", &PyDbPointCloudColorRamp::className, DS.SARGS()).staticmethod("className")
        ;
}

PyDbPointCloudColorRamp::PyDbPointCloudColorRamp()
    : m_pyImp(new AcDbPointCloudColorRamp())
{
}

Adesk::Int32 PyDbPointCloudColorRamp::numColors() const
{
    return impObj()->numColors();
}

void PyDbPointCloudColorRamp::setNumColors(Adesk::Int32 count) const
{
    PyThrowBadEs(impObj()->setNumColors(count));
}

AcCmEntityColor PyDbPointCloudColorRamp::color(int c) const
{
    return impObj()->color(c);
}

void PyDbPointCloudColorRamp::setColor(int c, const AcCmEntityColor& color) const
{
    return impObj()->setColor(c, color);
}

bool PyDbPointCloudColorRamp::visibility(int c) const
{
    return impObj()->visibility(c);
}

void PyDbPointCloudColorRamp::setVisibility(int c, bool visibility) const
{
    return impObj()->setVisibility(c, visibility);
}

void PyDbPointCloudColorRamp::setFrom(const PyDbPointCloudColorRamp& source) const
{
    return impObj()->setFrom(source.impObj());
}

std::string PyDbPointCloudColorRamp::name() const
{
    return wstr_to_utf8(impObj()->name());
}

void PyDbPointCloudColorRamp::setName(const std::string& name) const
{
    PyThrowBadEs(impObj()->setName(utf8_to_wstr(name).c_str()));
}

std::string PyDbPointCloudColorRamp::className()
{
    return "AcDbPointCloudColorRamp";
}

AcDbPointCloudColorRamp* PyDbPointCloudColorRamp::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return m_pyImp.get();
}

//-----------------------------------------------------------------------------------
//PyDbPointCloudColorMap
void makePyDbPointCloudColorMapWrapper()
{
    PyDocString DS("PointCloudColorMap");
    class_<PyDbPointCloudColorMap, bases<PyDbObject>>("PointCloudColorMap", boost::python::no_init)
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.ARGS({ "id: PyDb.ObjectId", "mode: PyDb.OpenMode = PyDb.OpenMode.kForRead", "erased: bool=False" }, 7505)))
        .def("defaultIntensityColorScheme", &PyDbPointCloudColorMap::defaultIntensityColorScheme, DS.ARGS())
        .def("setDefaultIntensityColorScheme", &PyDbPointCloudColorMap::setDefaultIntensityColorScheme, DS.ARGS({ "guid: str" }))
        .def("defaultElevationColorScheme", &PyDbPointCloudColorMap::defaultElevationColorScheme, DS.ARGS())
        .def("setDefaultElevationColorScheme", &PyDbPointCloudColorMap::setDefaultElevationColorScheme, DS.ARGS({ "guid: str" }))
        .def("defaultClassificationColorScheme", &PyDbPointCloudColorMap::defaultClassificationColorScheme, DS.ARGS())
        .def("setDefaultClassificationColorScheme", &PyDbPointCloudColorMap::setDefaultClassificationColorScheme, DS.ARGS({ "guid: str" }))
        .def("colorSchemeGUIDs", &PyDbPointCloudColorMap::colorSchemeGUIDs, DS.ARGS())
        .def("hasColorScheme", &PyDbPointCloudColorMap::hasColorScheme, DS.ARGS({ "guid: str" }))
        .def("deleteColorScheme", &PyDbPointCloudColorMap::deleteColorScheme, DS.ARGS({ "guid: str" }))
        .def("classificationSchemeGUIDs", &PyDbPointCloudColorMap::classificationSchemeGUIDs, DS.ARGS())
        .def("hasClassificationScheme", &PyDbPointCloudColorMap::hasClassificationScheme, DS.ARGS({ "guid: str" }))
        .def("deleteClassificationScheme", &PyDbPointCloudColorMap::deleteClassificationScheme, DS.ARGS({ "guid: str" }))
        .def("getColorSchemeInUse", &PyDbPointCloudColorMap::getColorSchemeInUse, DS.ARGS())
        .def("getClassificationColorSchemeInUse", &PyDbPointCloudColorMap::getClassificationColorSchemeInUse, DS.ARGS())
        .def("colorScheme", &PyDbPointCloudColorMap::colorScheme, DS.ARGS({ "guid: str" }))
        .def("setColorScheme", &PyDbPointCloudColorMap::setColorScheme, DS.ARGS({ "guid: str","val: PyDb.PointCloudColorRamp" }))
        .def("classificationScheme", &PyDbPointCloudColorMap::classificationScheme, DS.ARGS({ "guid: str" }))
        .def("setClassificationScheme", &PyDbPointCloudColorMap::setClassificationScheme, DS.ARGS({ "guid: str","val: PyDb.PointCloudClassificationColorRamp" }))
        .def("getColorMap", &PyDbPointCloudColorMap::getColorMap, DS.SARGS({ "val : PyDb.Database" })).staticmethod("getColorMap")
        .def("className", &PyDbPointCloudColorMap::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbPointCloudColorMap::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyDbPointCloudColorMap::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbPointCloudColorMap::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyDbPointCloudColorMap::PyDbPointCloudColorMap(const PyDbObjectId& id)
    : PyDbPointCloudColorMap(openAcDbObject<AcDbPointCloudColorMap>(id, AcDb::OpenMode::kForRead), false)
{
}

PyDbPointCloudColorMap::PyDbPointCloudColorMap(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbPointCloudColorMap(openAcDbObject<AcDbPointCloudColorMap>(id, mode), false)
{
}

PyDbPointCloudColorMap::PyDbPointCloudColorMap(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbPointCloudColorMap(openAcDbObject<AcDbPointCloudColorMap>(id, mode, erased), false)
{
}

PyDbPointCloudColorMap::PyDbPointCloudColorMap(AcDbPointCloudColorMap* ptr, bool autoDelete)
    : PyDbObject(ptr, autoDelete)
{
}

std::string PyDbPointCloudColorMap::defaultIntensityColorScheme() const
{
    return wstr_to_utf8(impObj()->defaultIntensityColorScheme());
}

bool PyDbPointCloudColorMap::setDefaultIntensityColorScheme(const std::string& GUID) const
{
    return impObj()->setDefaultIntensityColorScheme(utf8_to_wstr(GUID).c_str());
}

std::string PyDbPointCloudColorMap::defaultElevationColorScheme() const
{
    return wstr_to_utf8(impObj()->defaultElevationColorScheme());
}

bool PyDbPointCloudColorMap::setDefaultElevationColorScheme(const std::string& GUID) const
{
    return impObj()->setDefaultElevationColorScheme(utf8_to_wstr(GUID).c_str());
}

std::string PyDbPointCloudColorMap::defaultClassificationColorScheme() const
{
    return wstr_to_utf8(impObj()->defaultClassificationColorScheme());
}

bool PyDbPointCloudColorMap::setDefaultClassificationColorScheme(const std::string& GUID) const
{
    return impObj()->setDefaultClassificationColorScheme(utf8_to_wstr(GUID).c_str());
}

boost::python::list PyDbPointCloudColorMap::colorSchemeGUIDs() const
{
    PyAutoLockGIL lock;
    boost::python::list pylist;
    for (const auto& item : impObj()->colorSchemeGUIDs())
        pylist.append(wstr_to_utf8(item));
    return pylist;
}

bool PyDbPointCloudColorMap::hasColorScheme(const std::string& GUID) const
{
    return impObj()->hasColorScheme(utf8_to_wstr(GUID).c_str());
}

bool PyDbPointCloudColorMap::deleteColorScheme(const std::string& GUID) const
{
    return impObj()->deleteColorScheme(utf8_to_wstr(GUID).c_str());
}

boost::python::list PyDbPointCloudColorMap::classificationSchemeGUIDs() const
{
    PyAutoLockGIL lock;
    boost::python::list pylist;
    for (const auto& item : impObj()->classificationSchemeGUIDs())
        pylist.append(wstr_to_utf8(item));
    return pylist;
}

bool PyDbPointCloudColorMap::hasClassificationScheme(const std::string& GUID) const
{
    return impObj()->hasClassificationScheme(utf8_to_wstr(GUID).c_str());
}

bool PyDbPointCloudColorMap::deleteClassificationScheme(const std::string& GUID) const
{
    return impObj()->deleteClassificationScheme(utf8_to_wstr(GUID).c_str());
}

boost::python::list PyDbPointCloudColorMap::getColorSchemeInUse() const
{
    PyAutoLockGIL lock;
    boost::python::list pylist;
    AcArray<AcString> GUIDs;
    impObj()->getColorSchemeInUse(GUIDs);
    for (const auto& item : GUIDs)
        pylist.append(wstr_to_utf8(item));
    return pylist;
}

boost::python::list PyDbPointCloudColorMap::getClassificationColorSchemeInUse() const
{
    PyAutoLockGIL lock;
    boost::python::list pylist;
    AcArray<AcString> GUIDs;
    impObj()->getClassificationColorSchemeInUse(GUIDs);
    for (const auto& item : GUIDs)
        pylist.append(wstr_to_utf8(item));
    return pylist;
}

boost::python::tuple PyDbPointCloudColorMap::colorScheme(const std::string& GUID) const
{
    PyAutoLockGIL lock;
    PyDbPointCloudColorRamp pyramp;
    AcDbPointCloudColorRamp acramp;
    auto flag = impObj()->colorScheme(utf8_to_wstr(GUID).c_str(), acramp);
    pyramp.impObj()->setFrom(&acramp);
    return boost::python::make_tuple(flag, pyramp);
}

bool PyDbPointCloudColorMap::setColorScheme(const std::string& GUID, const PyDbPointCloudColorRamp& source) const
{
    return impObj()->colorScheme(utf8_to_wstr(GUID).c_str(), *source.impObj());
}

boost::python::tuple PyDbPointCloudColorMap::classificationScheme(const std::string& GUID) const
{
    PyAutoLockGIL lock;
    PyDbPointCloudClassificationColorRamp pyramp;
    AcDbPointCloudClassificationColorRamp acramp;
    auto flag = impObj()->classificationScheme(utf8_to_wstr(GUID).c_str(), acramp);
    pyramp.impObj()->setFrom(&acramp);
    return boost::python::make_tuple(flag, pyramp);
}

bool PyDbPointCloudColorMap::setClassificationScheme(const std::string& GUID, const PyDbPointCloudClassificationColorRamp& source) const
{
    return impObj()->setClassificationScheme(utf8_to_wstr(GUID).c_str(), *source.impObj());
}

PyDbObjectId PyDbPointCloudColorMap::getColorMap(PyDbDatabase& pDb)
{
    PyDbObjectId id;
    PyThrowBadEs(AcDbPointCloudColorMap::getColorMap(id.m_id, pDb.impObj()));
    return id;
}

std::string PyDbPointCloudColorMap::className()
{
    return "AcDbPointCloudColorMap";
}

PyRxClass PyDbPointCloudColorMap::desc()
{
    return PyRxClass(AcDbPointCloudColorMap::desc(), false);
}

PyDbPointCloudColorMap PyDbPointCloudColorMap::cloneFrom(const PyRxObject& src)
{
    return PyDbObjectCloneFrom<PyDbPointCloudColorMap, AcDbPointCloudColorMap>(src);
}

PyDbPointCloudColorMap PyDbPointCloudColorMap::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbPointCloudColorMap>(src);
}

AcDbPointCloudColorMap* PyDbPointCloudColorMap::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbPointCloudColorMap*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//PyDbPointCloudDefEx
void makePyDbPointCloudDefExWrapper()
{
    PyDocString DS("PointCloudDefEx");
    class_<PyDbPointCloudDefEx, bases<PyDbObject>>("PointCloudDefEx")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.ARGS({ "id: PyDb.ObjectId", "mode: PyDb.OpenMode = PyDb.OpenMode.kForRead", "erased: bool=False" }, 7578)))
        .def("load", &PyDbPointCloudDefEx::load, DS.ARGS())
        .def("unload", &PyDbPointCloudDefEx::unload, DS.ARGS())
        .def("isLoaded", &PyDbPointCloudDefEx::isLoaded, DS.ARGS())
        .def("entityCount", &PyDbPointCloudDefEx::entityCount, DS.ARGS())
        .def("setSourceFileName", &PyDbPointCloudDefEx::setSourceFileName, DS.ARGS({ "path : str" }))
        .def("sourceFileName", &PyDbPointCloudDefEx::sourceFileName, DS.ARGS())
        .def("setActiveFileName", &PyDbPointCloudDefEx::setActiveFileName, DS.ARGS({ "path : str" }))
        .def("activeFileName", &PyDbPointCloudDefEx::activeFileName, DS.ARGS())
        .def("fileType", &PyDbPointCloudDefEx::fileType, DS.ARGS())
        .def("totalPointsCount", &PyDbPointCloudDefEx::totalPointsCount, DS.ARGS())
        .def("totalRegionsCount", &PyDbPointCloudDefEx::totalRegionsCount, DS.ARGS())
        .def("totalScansCount", &PyDbPointCloudDefEx::totalScansCount, DS.ARGS())
        .def("defaultWidth", &PyDbPointCloudDefEx::defaultWidth, DS.ARGS())
        .def("defaultLength", &PyDbPointCloudDefEx::defaultLength, DS.ARGS())
        .def("defaultHeight", &PyDbPointCloudDefEx::defaultHeight, DS.ARGS())
        .def("hasProperty", &PyDbPointCloudDefEx::hasProperty, DS.ARGS({ "prop : PyDb.PointCloudProperty" }))
        .def("extents", &PyDbPointCloudDefEx::extents, DS.ARGS())
        .def("coordinateSystemName", &PyDbPointCloudDefEx::coordinateSystemName, DS.ARGS())
        .def("getRcsFilePath", &PyDbPointCloudDefEx::getRcsFilePath, DS.ARGS({ "guid : str" }))
        .def("getAllRcsFilePaths", &PyDbPointCloudDefEx::getAllRcsFilePaths, DS.ARGS())
        .def("pointCloudExDictionary", &PyDbPointCloudDefEx::pointCloudExDictionary, DS.SARGS({ "val : PyDb.Database" })).staticmethod("pointCloudExDictionary")
        .def("createPointCloudExDictionary", &PyDbPointCloudDefEx::createPointCloudExDictionary, DS.SARGS({ "val : PyDb.Database","id : PyDb.ObjectId" })).staticmethod("createPointCloudExDictionary")
        .def("classVersion", &PyDbPointCloudDefEx::classVersion, DS.SARGS()).staticmethod("classVersion")
        .def("className", &PyDbPointCloudDefEx::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbPointCloudDefEx::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyDbPointCloudDefEx::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbPointCloudDefEx::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
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

    enum_<AcDbPointCloudCrop::CropType>("PointCloudCropType")
        .value("kInvalid", AcDbPointCloudCrop::CropType::kInvalid)
        .value("kRectangular", AcDbPointCloudCrop::CropType::kRectangular)
        .value("kPolygonal", AcDbPointCloudCrop::CropType::kPolygonal)
        .value("kCircular", AcDbPointCloudCrop::CropType::kCircular)
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

void PyDbPointCloudDefEx::load() const
{
    PyThrowBadEs(impObj()->load());
}

void PyDbPointCloudDefEx::unload() const
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

void PyDbPointCloudDefEx::setSourceFileName(const std::string& pPathName) const
{
    PyThrowBadEs(impObj()->setSourceFileName(utf8_to_wstr(pPathName).c_str()));
}

std::string PyDbPointCloudDefEx::sourceFileName() const
{
    return wstr_to_utf8(impObj()->sourceFileName());
}

void PyDbPointCloudDefEx::setActiveFileName(const std::string& pPathName) const
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
    return PyDbObjectCloneFrom<PyDbPointCloudDefEx, AcDbPointCloudDefEx>(src);
}

PyDbPointCloudDefEx PyDbPointCloudDefEx::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbPointCloudDefEx>(src);
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
    constexpr const std::string_view applyGeoLocationOverloads = "Overloads:\n"
        "- None: Any\n"
        "- useDrawingGeo: bool, geoCS: str\n";

    PyDocString DS("PointCloudEx");
    class_<PyDbPointCloudEx, bases<PyDbEntity>>("PointCloudEx")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.ARGS({ "id: PyDb.ObjectId", "mode: PyDb.OpenMode = PyDb.OpenMode.kForRead", "erased: bool=False" }, 7625)))
        .def("setPointCloudDefExId", &PyDbPointCloudEx::setPointCloudDefExId, DS.ARGS({ "val : PyDb.ObjectId" }))
        .def("pointCloudDefExId", &PyDbPointCloudEx::pointCloudDefExId, DS.ARGS())
        .def("setReactorId", &PyDbPointCloudEx::setReactorId, DS.ARGS({ "val : PyDb.ObjectId" }))
        .def("reactorId", &PyDbPointCloudEx::reactorId, DS.ARGS())
        .def("locked", &PyDbPointCloudEx::locked, DS.ARGS())
        .def("setLocked", &PyDbPointCloudEx::setLocked, DS.ARGS({ "val : bool" }))
        .def("scale", &PyDbPointCloudEx::scale, DS.ARGS())
        .def("setScale", &PyDbPointCloudEx::setScale, DS.ARGS({ "val: float" }))
        .def("rotation", &PyDbPointCloudEx::rotation, DS.ARGS())
        .def("setRotation", &PyDbPointCloudEx::setRotation, DS.ARGS({ "val: float" }))
        .def("location", &PyDbPointCloudEx::location, DS.ARGS())
        .def("setLocation", &PyDbPointCloudEx::setLocation, DS.ARGS({ "pt: PyGe.Point3d" }))
        .def("getNativeCloudExtent", &PyDbPointCloudEx::getNativeCloudExtent, DS.ARGS())
        .def("getVisiblePointCount", &PyDbPointCloudEx::getVisiblePointCount, DS.ARGS())
        .def("getLoadedVisiblePointCount", &PyDbPointCloudEx::getLoadedVisiblePointCount, DS.ARGS())
        .def("getDisplayedVisiblePointCount", &PyDbPointCloudEx::getDisplayedVisiblePointCount, DS.ARGS())
        .def("setActiveFileName", &PyDbPointCloudEx::setActiveFileName, DS.ARGS({ "val: str" }))
        .def("getActiveFileName", &PyDbPointCloudEx::getActiveFileName, DS.ARGS())
        .def("getPointCloudName", &PyDbPointCloudEx::getPointCloudName, DS.ARGS())
        .def("setPointCloudName", &PyDbPointCloudEx::setPointCloudName, DS.ARGS({ "val: str" }))
        .def("getCroppingCount", &PyDbPointCloudEx::getCroppingCount, DS.ARGS())
        .def("clearCropping", &PyDbPointCloudEx::clearCropping, DS.ARGS())
        .def("removeLastCropping", &PyDbPointCloudEx::removeLastCropping, DS.ARGS())
        .def("getCroppingInvert", &PyDbPointCloudEx::getCroppingInvert, DS.ARGS())
        .def("setCroppingInvert", &PyDbPointCloudEx::setCroppingInvert, DS.ARGS({ "val: bool" }))
        .def("setInCreatingCroppingMode", &PyDbPointCloudEx::setInCreatingCroppingMode, DS.ARGS({ "val: bool" }))
        .def("showCropped", &PyDbPointCloudEx::showCropped, DS.ARGS())
        .def("setStylizationType", &PyDbPointCloudEx::setStylizationType, DS.ARGS({ "val: PyDb.PointCloudStylizationType" }))
        .def("stylizationType", &PyDbPointCloudEx::stylizationType, DS.ARGS())
        .def("getCurrentColorScheme", &PyDbPointCloudEx::getCurrentColorScheme, DS.ARGS())
        .def("setCurrentColorScheme", &PyDbPointCloudEx::setCurrentColorScheme, DS.ARGS({ "guid: str" }))
        .def("getColorSchemeForStylization", &PyDbPointCloudEx::getColorSchemeForStylization, DS.ARGS({ "val: PyDb.PointCloudStylizationType" }))
        .def("setColorSchemeForStylization", &PyDbPointCloudEx::setColorSchemeForStylization, DS.ARGS({ "guid: str", "val: PyDb.PointCloudStylizationType" }))
        .def("showIntensityAsGradient", &PyDbPointCloudEx::showIntensityAsGradient, DS.ARGS())
        .def("setShowIntensityAsGradient", &PyDbPointCloudEx::setShowIntensityAsGradient, DS.ARGS({ "val: bool" }))
        .def("minIntensity", &PyDbPointCloudEx::minIntensity, DS.ARGS())
        .def("maxIntensity", &PyDbPointCloudEx::maxIntensity, DS.ARGS())
        .def("setMinMaxIntensity", &PyDbPointCloudEx::setMinMaxIntensity, DS.ARGS({ "min: int","max: int" }))
        .def("intensityOutOfRangeBehavior", &PyDbPointCloudEx::intensityOutOfRangeBehavior, DS.ARGS())
        .def("setIntensityOutOfRangeBehavior", &PyDbPointCloudEx::setIntensityOutOfRangeBehavior, DS.ARGS({ "val: PyDb.PointCloudDispOptionOutOfRange" }))
        .def("showElevationAsGradient", &PyDbPointCloudEx::showElevationAsGradient, DS.ARGS())
        .def("setShowElevationAsGradient", &PyDbPointCloudEx::setShowElevationAsGradient, DS.ARGS({ "val: bool" }))
        .def("minElevation", &PyDbPointCloudEx::minElevation, DS.ARGS())
        .def("maxElevation", &PyDbPointCloudEx::maxElevation, DS.ARGS())
        .def("setMinMaxElevation", &PyDbPointCloudEx::setMinMaxElevation, DS.ARGS({ "min: float","max: float" }))
        .def("elevationApplyToFixedRange", &PyDbPointCloudEx::elevationApplyToFixedRange, DS.ARGS())
        .def("setElevationApplyToFixedRange", &PyDbPointCloudEx::setElevationApplyToFixedRange, DS.ARGS())
        .def("elevationOutOfRangeBehavior", &PyDbPointCloudEx::elevationOutOfRangeBehavior, DS.ARGS())
        .def("setElevationOutOfRangeBehavior", &PyDbPointCloudEx::setElevationOutOfRangeBehavior, DS.ARGS({ "val: PyDb.PointCloudDispOptionOutOfRange" }))
        .def("resetLimitBox", &PyDbPointCloudEx::resetLimitBox, DS.ARGS())
        .def("setHighlightLimitboxBoundary", &PyDbPointCloudEx::setHighlightLimitboxBoundary, DS.ARGS({ "val: bool" }))
        .def("setScanVisibility", &PyDbPointCloudEx::setScanVisibility, DS.ARGS({ "scanGuid: str","bVisible: bool" }))
        .def("setAllScansVisibility", &PyDbPointCloudEx::setAllScansVisibility, DS.ARGS({ "bVisible: bool" }))
        .def("setRegionVisibility", &PyDbPointCloudEx::setRegionVisibility, DS.ARGS({ "regionId: int","bVisible: bool" }))
        .def("setAllRegionsVisibility", &PyDbPointCloudEx::setAllRegionsVisibility1)
        .def("setAllRegionsVisibility", &PyDbPointCloudEx::setAllRegionsVisibility2, DS.ARGS({ "bVisible: bool","includeUnassigned: bool=False" }))
        .def("setAllScansVisibilityByRegion", &PyDbPointCloudEx::setAllScansVisibilityByRegion, DS.ARGS({ "regionId: int","bVisible: bool" }))
        .def("getScanViewInfo", &PyDbPointCloudEx::getScanViewInfo, DS.ARGS({ "scanGuid: str" }))
        .def("resetScanRegionVisibility", &PyDbPointCloudEx::resetScanRegionVisibility, DS.ARGS())
        .def("setAllScanHighlight", &PyDbPointCloudEx::setAllScanHighlight, DS.ARGS({ "val: bool" }))
        .def("setAllRegionHighlight", &PyDbPointCloudEx::setAllRegionHighlight1)
        .def("setAllRegionHighlight", &PyDbPointCloudEx::setAllRegionHighlight2, DS.ARGS({ "bHighlight: bool","includeUnassigned: bool=False" }))
        .def("applyGeoLocation", &PyDbPointCloudEx::applyGeoLocation1)
        .def("applyGeoLocation", &PyDbPointCloudEx::applyGeoLocation2, DS.OVRL(applyGeoLocationOverloads))
        .def("updateGeoLocation", &PyDbPointCloudEx::updateGeoLocation, DS.ARGS())
        .def("geolocate", &PyDbPointCloudEx::geolocate, DS.ARGS())
        .def("clearSpatialFilters", &PyDbPointCloudEx::clearSpatialFilters, DS.ARGS())
        .def("clearAttributeFilters", &PyDbPointCloudEx::clearAttributeFilters, DS.ARGS())
        .def("getPlaneOrPointAt", &PyDbPointCloudEx::getPlaneOrPointAt, DS.ARGS({ "xform: PyGe.Matrix3d","pt: PyGe.Point3d" }))
        .def("getPlaneBoundaryAt", &PyDbPointCloudEx::getPlaneBoundaryAt, DS.ARGS({ "xform: PyGe.Matrix3d","pt: PyGe.Point3d" }))
        .def("objectToWorldMatrix", &PyDbPointCloudEx::objectToWorldMatrix, DS.ARGS())
        .def("getCandidatePlane", &PyDbPointCloudEx::getCandidatePlane, DS.ARGS({ "x: int","y: int" }))
        .def("getCylinderAt", &PyDbPointCloudEx::getCylinderAt, DS.ARGS({ "xform: PyGe.Matrix3d","pt: PyGe.Point3d" }))
        .def("getMinDistPrecision", &PyDbPointCloudEx::getMinDistPrecision, DS.ARGS())
        .def("detectPointBelonger", &PyDbPointCloudEx::detectPointBelonger, DS.ARGS({ "ptWCS: PyGe.Point3d" }))
        .def("getCustomOsnapInfo", &PyDbPointCloudEx::getCustomOsnapInfo, DS.ARGS({ "snapMode: PyDb.PointCloudOSnapMode","pickPoint: PyGe.Point3d","lastPoint: PyGe.Point3d","viewXform: PyGe.Matrix3d" }))
        .def("getPointCloudCropping", &PyDbPointCloudEx::getPointCloudCropping, DS.ARGS({ "index: int" }))
        .def("addCroppingBoundary", &PyDbPointCloudEx::addCroppingBoundary, DS.ARGS({ "val: PyDb.PointCloudCrop" }))
        .def("attachPointCloud", &PyDbPointCloudEx::attachPointCloud, DS.ARGS({ "path: str","pos: PyGe.Point3d","scale: float","rotation: float","db: PyDb.Database" })).staticmethod("attachPointCloud")
        .def("className", &PyDbPointCloudEx::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbPointCloudEx::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyDbPointCloudEx::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbPointCloudEx::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
    enum_<AcDbPointCloudEx::DispOptionOutOfRange>("PointCloudDispOptionOutOfRange")
        .value("kUseMinMaxColors", AcDbPointCloudEx::DispOptionOutOfRange::kUseMinMaxColors)
        .value("kUseRGBScanColors", AcDbPointCloudEx::DispOptionOutOfRange::kUseRGBScanColors)
        .value("kHidePoints", AcDbPointCloudEx::DispOptionOutOfRange::kHidePoints)
        .export_values()
        ;
    enum_<AcDbPointCloudEx::PointCloudOSnapMode>("PointCloudOSnapMode")
        .value("kOsModePNod", AcDbPointCloudEx::PointCloudOSnapMode::kOsModePNod)
        .value("kOsModePNea", AcDbPointCloudEx::PointCloudOSnapMode::kOsModePNea)
        .value("kOsModePPer", AcDbPointCloudEx::PointCloudOSnapMode::kOsModePPer)
        .value("kOsModePEdgeNea", AcDbPointCloudEx::PointCloudOSnapMode::kOsModePEdgeNea)
        .value("kOsModePEdgePer", AcDbPointCloudEx::PointCloudOSnapMode::kOsModePEdgePer)
        .value("kOsModePInt", AcDbPointCloudEx::PointCloudOSnapMode::kOsModePInt)
        .value("kOsModePCL", AcDbPointCloudEx::PointCloudOSnapMode::kOsModePCL)
        .value("kOsModePCorner", AcDbPointCloudEx::PointCloudOSnapMode::kOsModePCorner)
        .export_values()
        ;
    enum_<AcDbPointCloudEx::StylizationType>("PointCloudStylizationType")
        .value("kTrueColor", AcDbPointCloudEx::StylizationType::kTrueColor)
        .value("kSingleColor", AcDbPointCloudEx::StylizationType::kSingleColor)
        .value("kNormalRamp", AcDbPointCloudEx::StylizationType::kNormalRamp)
        .value("kHeightRamp", AcDbPointCloudEx::StylizationType::kHeightRamp)
        .value("kIntensityRamp", AcDbPointCloudEx::StylizationType::kIntensityRamp)
        .value("kClassificationRamp", AcDbPointCloudEx::StylizationType::kClassificationRamp)
        .export_values()
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

void PyDbPointCloudEx::setPointCloudDefExId(const PyDbObjectId& defExId) const
{
    impObj()->setPointCloudDefExId(defExId.m_id);
}

PyDbObjectId PyDbPointCloudEx::pointCloudDefExId() const
{
    return PyDbObjectId(impObj()->pointCloudDefExId());
}

void PyDbPointCloudEx::setReactorId(const PyDbObjectId& reactorId) const
{
    impObj()->setReactorId(reactorId.m_id);
}

PyDbObjectId PyDbPointCloudEx::reactorId() const
{
    return PyDbObjectId(impObj()->reactorId());
}

bool PyDbPointCloudEx::locked() const
{
    return impObj()->locked();
}

void PyDbPointCloudEx::setLocked(bool locked) const
{
    return impObj()->setLocked(locked);
}

double PyDbPointCloudEx::scale() const
{
    return impObj()->scale();
}

void PyDbPointCloudEx::setScale(double val) const
{
    PyThrowBadEs(impObj()->setScale(val));
}

double PyDbPointCloudEx::rotation() const
{
    return impObj()->rotation();
}

void PyDbPointCloudEx::setRotation(double val) const
{
    PyThrowBadEs(impObj()->setRotation(val));
}

AcGePoint3d PyDbPointCloudEx::location() const
{
    return impObj()->location();
}

void PyDbPointCloudEx::setLocation(const AcGePoint3d& pt) const
{
    PyThrowBadEs(impObj()->setLocation(pt));
}

AcDbExtents PyDbPointCloudEx::getNativeCloudExtent() const
{
    AcDbExtents extents;
    impObj()->getNativeCloudExtent(extents);
    return extents;
}

unsigned int PyDbPointCloudEx::getVisiblePointCount() const
{
    return impObj()->getVisiblePointCount();
}

unsigned int PyDbPointCloudEx::getLoadedVisiblePointCount() const
{
    return impObj()->getLoadedVisiblePointCount();
}

unsigned int PyDbPointCloudEx::getDisplayedVisiblePointCount() const
{
    return impObj()->getDisplayedVisiblePointCount();
}

bool PyDbPointCloudEx::setActiveFileName(const std::string& strActiveFileName) const
{
    return impObj()->setActiveFileName(utf8_to_wstr(strActiveFileName).c_str());
}

boost::python::tuple PyDbPointCloudEx::getActiveFileName() const
{
    PyAutoLockGIL lock;
    AcString strActiveFileName;
    auto val = impObj()->getActiveFileName(strActiveFileName);
    return boost::python::make_tuple(val, wstr_to_utf8(strActiveFileName));
}

std::string PyDbPointCloudEx::getPointCloudName() const
{
    return wstr_to_utf8(impObj()->getPointCloudName());
}

void PyDbPointCloudEx::setPointCloudName(const std::string& name) const
{
    PyThrowBadEs(impObj()->setPointCloudName((utf8_to_wstr(name).c_str())));
}

int PyDbPointCloudEx::getCroppingCount() const
{
    return impObj()->getCroppingCount();
}

PyDbPointCloudCrop PyDbPointCloudEx::getPointCloudCropping(int index) const
{
    return PyDbPointCloudCrop(*impObj()->getPointCloudCropping(index));
}

void PyDbPointCloudEx::addCroppingBoundary(const PyDbPointCloudCrop& cropping) const
{
    impObj()->addCroppingBoundary(*cropping.impObj());
}

void PyDbPointCloudEx::clearCropping() const
{
    PyThrowBadEs(impObj()->clearCropping());
}

void PyDbPointCloudEx::removeLastCropping() const
{
    PyThrowBadEs(impObj()->removeLastCropping());
}

bool PyDbPointCloudEx::getCroppingInvert() const
{
    return impObj()->getCroppingInvert();
}

void PyDbPointCloudEx::setCroppingInvert(bool invert) const
{
    PyThrowBadEs(impObj()->setCroppingInvert(invert));
}

void PyDbPointCloudEx::setInCreatingCroppingMode(bool bCreating) const
{
    impObj()->setInCreatingCroppingMode(bCreating);
}

bool PyDbPointCloudEx::showCropped() const
{
    return impObj()->showCropped();
}

void PyDbPointCloudEx::setStylizationType(AcDbPointCloudEx::StylizationType type) const
{
    PyThrowBadEs(impObj()->setStylizationType(type));
}

AcDbPointCloudEx::StylizationType PyDbPointCloudEx::stylizationType() const
{
    return impObj()->stylizationType();
}

std::string PyDbPointCloudEx::getCurrentColorScheme() const
{
    return wstr_to_utf8(impObj()->getCurrentColorScheme());
}

void PyDbPointCloudEx::setCurrentColorScheme(const std::string& guid) const
{
    PyThrowBadEs(impObj()->setCurrentColorScheme(utf8_to_wstr(guid).c_str()));
}

std::string PyDbPointCloudEx::getColorSchemeForStylization(AcDbPointCloudEx::StylizationType type) const
{
    return wstr_to_utf8(impObj()->getColorSchemeForStylization(type));
}

void PyDbPointCloudEx::setColorSchemeForStylization(const std::string& guid, AcDbPointCloudEx::StylizationType type) const
{
    PyThrowBadEs(impObj()->setColorSchemeForStylization(utf8_to_wstr(guid).c_str(), type));
}

bool PyDbPointCloudEx::showIntensityAsGradient() const
{
    return impObj()->showIntensityAsGradient();
}

void PyDbPointCloudEx::setShowIntensityAsGradient(bool b) const
{
    impObj()->setShowIntensityAsGradient(b);
}

Adesk::Int32 PyDbPointCloudEx::minIntensity() const
{
    return impObj()->minIntensity();
}

Adesk::Int32 PyDbPointCloudEx::maxIntensity() const
{
    return impObj()->maxIntensity();
}

void PyDbPointCloudEx::setMinMaxIntensity(int min, int max) const
{
    PyThrowBadEs(impObj()->setMinMaxIntensity(min, max));
}

AcDbPointCloudEx::DispOptionOutOfRange PyDbPointCloudEx::intensityOutOfRangeBehavior() const
{
    return impObj()->intensityOutOfRangeBehavior();
}

void PyDbPointCloudEx::setIntensityOutOfRangeBehavior(AcDbPointCloudEx::DispOptionOutOfRange dispOp) const
{
    impObj()->setIntensityOutOfRangeBehavior(dispOp);
}

bool PyDbPointCloudEx::showElevationAsGradient() const
{
    return impObj()->showElevationAsGradient();
}

void PyDbPointCloudEx::setShowElevationAsGradient(bool b) const
{
    impObj()->setShowElevationAsGradient(b);
}

double PyDbPointCloudEx::minElevation() const
{
    return impObj()->minElevation();
}

double PyDbPointCloudEx::maxElevation() const
{
    return impObj()->maxElevation();
}

void PyDbPointCloudEx::setMinMaxElevation(double min, double max) const
{
    PyThrowBadEs(impObj()->setMinMaxElevation(min, max));
}

bool PyDbPointCloudEx::elevationApplyToFixedRange() const
{
    return impObj()->elevationApplyToFixedRange();
}

void PyDbPointCloudEx::setElevationApplyToFixedRange(bool val) const
{
    impObj()->setElevationApplyToFixedRange(val);
}

AcDbPointCloudEx::DispOptionOutOfRange PyDbPointCloudEx::elevationOutOfRangeBehavior() const
{
    return impObj()->elevationOutOfRangeBehavior();
}

void PyDbPointCloudEx::setElevationOutOfRangeBehavior(AcDbPointCloudEx::DispOptionOutOfRange dispOp) const
{
    impObj()->setElevationOutOfRangeBehavior(dispOp);
}

void PyDbPointCloudEx::resetLimitBox() const
{
    impObj()->resetLimitBox();
}

void PyDbPointCloudEx::setHighlightLimitboxBoundary(bool val) const
{
    impObj()->setHighlightLimitboxBoundary(val);
}

void PyDbPointCloudEx::setScanVisibility(const std::string& scanGuid, bool bVisible) const
{
    impObj()->setScanVisibility(utf8_to_wstr(scanGuid).c_str(), bVisible);
}

void PyDbPointCloudEx::setAllScansVisibility(bool bVisible) const
{
    impObj()->setAllScansVisibility(bVisible);
}

void PyDbPointCloudEx::setRegionVisibility(int regionId, bool bVisible) const
{
    impObj()->setRegionVisibility(regionId, bVisible);
}

void PyDbPointCloudEx::setAllRegionsVisibility1(bool bVisible) const
{
    impObj()->setAllRegionsVisibility(bVisible);
}

void PyDbPointCloudEx::setAllRegionsVisibility2(bool bVisible, bool includeUnassigned) const
{
    impObj()->setAllRegionsVisibility(bVisible, includeUnassigned);
}

void PyDbPointCloudEx::setAllScansVisibilityByRegion(int regionId, bool bVisible) const
{
    impObj()->setAllScansVisibilityByRegion(regionId, bVisible);
}

boost::python::tuple PyDbPointCloudEx::getScanViewInfo(const std::string& scanGuid) const
{
    PyAutoLockGIL lock;
    AcGePoint3d origin;
    AcDbExtents extent;
    auto b = impObj()->getScanViewInfo(utf8_to_wstr(scanGuid).c_str(), origin, extent);
    return boost::python::make_tuple(b, origin, extent);
}

void PyDbPointCloudEx::resetScanRegionVisibility() const
{
    impObj()->resetScanRegionVisibility();
}

void PyDbPointCloudEx::setAllScanHighlight(bool bHighlight) const
{
    impObj()->setAllScanHighlight(bHighlight);
}

void PyDbPointCloudEx::setAllRegionHighlight1(bool bHighlight) const
{
    impObj()->setAllRegionHighlight(bHighlight);
}

void PyDbPointCloudEx::setAllRegionHighlight2(bool bHighlight, bool bIncludeUnassignedPoints) const
{
    impObj()->setAllRegionHighlight(bHighlight, bIncludeUnassignedPoints);
}

void PyDbPointCloudEx::applyGeoLocation1() const
{
    impObj()->applyGeoLocation();
}

void PyDbPointCloudEx::applyGeoLocation2(bool useDrawingGeo, const std::string& geoCS) const
{
    impObj()->applyGeoLocation(useDrawingGeo, utf8_to_wstr(geoCS).c_str());
}

void PyDbPointCloudEx::updateGeoLocation() const
{
    impObj()->updateGeoLocation();
}

bool PyDbPointCloudEx::geolocate() const
{
    return impObj()->geolocate();
}

void PyDbPointCloudEx::clearSpatialFilters() const
{
    impObj()->clearSpatialFilters();
}

void PyDbPointCloudEx::clearAttributeFilters() const
{
    impObj()->clearAttributeFilters();
}

boost::python::tuple PyDbPointCloudEx::getPlaneOrPointAt(const AcGeMatrix3d& viewXform, const AcGePoint3d& pickPt) const
{
    PyAutoLockGIL lock;
    AcGePoint3dArray points;
    auto val = impObj()->getPlaneOrPointAt(viewXform, pickPt, points);
    return boost::python::make_tuple(val, Point3dArrayToPyList(points));
}

boost::python::tuple PyDbPointCloudEx::getPlaneBoundaryAt(const AcGeMatrix3d& viewXform, const AcGePoint3d& pickPt) const
{
    PyAutoLockGIL lock;
    AcGePoint3dArray points;
    auto val = impObj()->getPlaneBoundaryAt(viewXform, pickPt, points);
    return boost::python::make_tuple(val, Point3dArrayToPyList(points));
}

AcGeMatrix3d PyDbPointCloudEx::objectToWorldMatrix() const
{
    AcGeMatrix3d mat;
    impObj()->objectToWorldMatrix(mat);
    return mat;
}

boost::python::tuple PyDbPointCloudEx::getCandidatePlane(int x, int y) const
{
    PyAutoLockGIL lock;
    CPoint p(x, y);
    AcGePlane result;
    double distToEdge = 0;
    double objWidth = 0;
    double objHeight = 0;
    void* context = 0;
    PyThrowBadEs(impObj()->getCandidatePlane(p, result, distToEdge, objWidth, objHeight, context));
    return boost::python::make_tuple(PyGePlane(result), distToEdge, objWidth, objHeight, intptr_t(context));
}

boost::python::tuple PyDbPointCloudEx::getCylinderAt(const AcGeMatrix3d& viewXform, const AcGePoint3d& pickPt) const
{
    PyAutoLockGIL lock;
    AcGePoint3d origin;
    AcGeVector3d axis;
    double height = 0;
    double radius = 0;
    PyThrowBadEs(impObj()->getCylinderAt(viewXform, pickPt, origin, axis, height, radius));
    return boost::python::make_tuple(origin, axis, height, radius);
}

double PyDbPointCloudEx::getMinDistPrecision() const
{
    double minDistPrecision = 0;
    PyThrowBadEs(impObj()->getMinDistPrecision(minDistPrecision));
    return minDistPrecision;
}

boost::python::tuple PyDbPointCloudEx::detectPointBelonger(const AcGePoint3d& ptInWCS) const
{
    PyAutoLockGIL lock;
    AcString scanGuid;
    Adesk::UInt16 segmentIndex;
    PyThrowBadEs(impObj()->detectPointBelonger(ptInWCS, scanGuid, segmentIndex));
    return boost::python::make_tuple(wstr_to_utf8(scanGuid), segmentIndex);
}

boost::python::list PyDbPointCloudEx::getCustomOsnapInfo(AcDbPointCloudEx::PointCloudOSnapMode snapMode, const AcGePoint3d& pickPoint, const AcGePoint3d& lastPoint, const AcGeMatrix3d& viewXform) const
{
    PyAutoLockGIL lock;
    AcGePoint3dArray snapPoints;
    PyThrowBadEs(impObj()->getCustomOsnapInfo(snapMode, pickPoint, lastPoint, viewXform, snapPoints));
    return Point3dArrayToPyList(snapPoints);
}

PyDbObjectId PyDbPointCloudEx::attachPointCloud(const std::string& pointCloudFile, AcGePoint3d& location, double scale, double rotation, PyDbDatabase& pDb)
{
    static bool sAcDbMPolygonLoaded = false;
    if (!sAcDbMPolygonLoaded)
    {
        sAcDbMPolygonLoaded = acrxLoadModule(_T("AcDbPointCloudObj.dbx"), false, false);
    }
    PyDbObjectId newPointCloudExId;
    AcString str = utf8_to_wstr(pointCloudFile).c_str();
    PyThrowBadEs(acdbAttachPointCloudExEntity(newPointCloudExId.m_id, str, location, scale, rotation, pDb.impObj()));
    return newPointCloudExId;
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
    return PyDbObjectCloneFrom<PyDbPointCloudEx, AcDbPointCloudEx>(src);
}

PyDbPointCloudEx PyDbPointCloudEx::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbPointCloudEx>(src);
}

AcDbPointCloudEx* PyDbPointCloudEx::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbPointCloudEx*>(m_pyImp.get());
}
#endif