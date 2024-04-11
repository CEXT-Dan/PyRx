#include "stdafx.h"
#include "PyDbPointCloudEx.h"
#include "PyDbObjectId.h"
#include "PyDbDatabase.h"
#include "PyGePlane.h"


#if !defined(_BRXTARGET240)

using namespace boost::python;

//-----------------------------------------------------------------------------------
//PyDbPointCloudCrop
void makePyDbPointCloudCropWrapper()
{
    PyDocString DS("PointCloudCrop");
    class_<PyDbPointCloudCrop>("PointCloudCrop")
        .def(init<>())
        .def("clear", &PyDbPointCloudCrop::clear)
        .def("isValid", &PyDbPointCloudCrop::isValid)
        .def("type", &PyDbPointCloudCrop::type)
        .def("setCropType", &PyDbPointCloudCrop::setCropType)
        .def("isInside", &PyDbPointCloudCrop::isInside)
        .def("setInside", &PyDbPointCloudCrop::setInside)
        .def("isInverted", &PyDbPointCloudCrop::isInverted)
        .def("setInvert", &PyDbPointCloudCrop::setInvert)
        .def("getCropPlane", &PyDbPointCloudCrop::getCropPlane)
        .def("setCropPlane", &PyDbPointCloudCrop::setCropPlane)
        .def("length", &PyDbPointCloudCrop::length)
        .def("set", &PyDbPointCloudCrop::set)
        .def("get", &PyDbPointCloudCrop::get)
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

void PyDbPointCloudCrop::clear()
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

void PyDbPointCloudCrop::setCropType(AcDbPointCloudCrop::CropType type)
{
    impObj()->setCropType(type);
}

bool PyDbPointCloudCrop::isInside() const
{
    return impObj()->isInside();
}

void PyDbPointCloudCrop::setInside(bool bInside)
{
    impObj()->setInside(bInside);
}

bool PyDbPointCloudCrop::isInverted() const
{
    return impObj()->isInverted();
}

void PyDbPointCloudCrop::setInvert(bool toInvert)
{
    impObj()->setInvert(toInvert);
}

boost::python::tuple PyDbPointCloudCrop::getCropPlane()
{
    PyAutoLockGIL lock;
    AcGePlane plane;
    auto flag = impObj()->getCropPlane(plane);
    return boost::python::make_tuple(flag, PyGePlane(plane));
}

void PyDbPointCloudCrop::setCropPlane(const PyGePlane& plane)
{
    impObj()->setCropPlane(*plane.impObj());
}

int PyDbPointCloudCrop::length() const
{
    return impObj()->length();
}

void PyDbPointCloudCrop::set(const boost::python::list& points)
{
    impObj()->set(PyListToPoint3dArray(points));
}

boost::python::list PyDbPointCloudCrop::get()
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
        .def(init<>())
        .def("numColors", &PyDbPointCloudClassificationColorRamp::numColors)
        .def("color", &PyDbPointCloudClassificationColorRamp::color)
        .def("setColor", &PyDbPointCloudClassificationColorRamp::setColor)
        .def("visibility", &PyDbPointCloudClassificationColorRamp::visibility)
        .def("setVisibility", &PyDbPointCloudClassificationColorRamp::setVisibility)
        .def("setFrom", &PyDbPointCloudClassificationColorRamp::setFrom)
        .def("name", &PyDbPointCloudClassificationColorRamp::name)
        .def("setName", &PyDbPointCloudClassificationColorRamp::setName)
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

void PyDbPointCloudClassificationColorRamp::setColor(int c, const AcCmEntityColor& color)
{
    return impObj()->setColor(c, color);
}

bool PyDbPointCloudClassificationColorRamp::visibility(int c) const
{
    return impObj()->visibility(c);
}

void PyDbPointCloudClassificationColorRamp::setVisibility(int c, bool visibility)
{
    return impObj()->setVisibility(c, visibility);
}

void PyDbPointCloudClassificationColorRamp::setFrom(const PyDbPointCloudClassificationColorRamp& source)
{
    return impObj()->setFrom(source.impObj());
}

std::string PyDbPointCloudClassificationColorRamp::name() const
{
    return wstr_to_utf8(impObj()->name());
}

void PyDbPointCloudClassificationColorRamp::setName(const std::string& name)
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
        .def(init<>())
        .def("numColors", &PyDbPointCloudColorRamp::numColors)
        .def("setNumColors", &PyDbPointCloudColorRamp::setNumColors)
        .def("color", &PyDbPointCloudColorRamp::color)
        .def("setColor", &PyDbPointCloudColorRamp::setColor)
        .def("visibility", &PyDbPointCloudColorRamp::visibility)
        .def("setVisibility", &PyDbPointCloudColorRamp::setVisibility)
        .def("setFrom", &PyDbPointCloudColorRamp::setFrom)
        .def("name", &PyDbPointCloudColorRamp::name)
        .def("setName", &PyDbPointCloudColorRamp::setName)
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

void PyDbPointCloudColorRamp::setNumColors(Adesk::Int32 count)
{
    PyThrowBadEs(impObj()->setNumColors(count));
}

AcCmEntityColor PyDbPointCloudColorRamp::color(int c) const
{
    return impObj()->color(c);
}

void PyDbPointCloudColorRamp::setColor(int c, const AcCmEntityColor& color)
{
    return impObj()->setColor(c, color);
}

bool PyDbPointCloudColorRamp::visibility(int c) const
{
    return impObj()->visibility(c);
}

void PyDbPointCloudColorRamp::setVisibility(int c, bool visibility)
{
    return impObj()->setVisibility(c, visibility);
}

void PyDbPointCloudColorRamp::setFrom(const PyDbPointCloudColorRamp& source)
{
    return impObj()->setFrom(source.impObj());
}

std::string PyDbPointCloudColorRamp::name() const
{
    return wstr_to_utf8(impObj()->name());
}

void PyDbPointCloudColorRamp::setName(const std::string& name)
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
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.ARGS({ "id: ObjectId", "mode: PyDb.OpenMode.kForRead", "erased: bool=False" })))

        .def("defaultIntensityColorScheme", &PyDbPointCloudColorMap::defaultIntensityColorScheme)
        .def("setDefaultIntensityColorScheme", &PyDbPointCloudColorMap::setDefaultIntensityColorScheme)
        .def("defaultElevationColorScheme", &PyDbPointCloudColorMap::defaultElevationColorScheme)
        .def("setDefaultElevationColorScheme", &PyDbPointCloudColorMap::setDefaultElevationColorScheme)
        .def("defaultClassificationColorScheme", &PyDbPointCloudColorMap::defaultClassificationColorScheme)
        .def("setDefaultClassificationColorScheme", &PyDbPointCloudColorMap::setDefaultClassificationColorScheme)
        .def("colorSchemeGUIDs", &PyDbPointCloudColorMap::colorSchemeGUIDs)
        .def("hasColorScheme", &PyDbPointCloudColorMap::hasColorScheme)
        .def("deleteColorScheme", &PyDbPointCloudColorMap::deleteColorScheme)
        .def("classificationSchemeGUIDs", &PyDbPointCloudColorMap::classificationSchemeGUIDs)
        .def("hasClassificationScheme", &PyDbPointCloudColorMap::hasClassificationScheme)
        .def("deleteClassificationScheme", &PyDbPointCloudColorMap::deleteClassificationScheme)
        .def("getColorSchemeInUse", &PyDbPointCloudColorMap::getColorSchemeInUse)
        .def("getClassificationColorSchemeInUse", &PyDbPointCloudColorMap::getClassificationColorSchemeInUse)

        .def("colorScheme", &PyDbPointCloudColorMap::colorScheme)
        .def("setColorScheme", &PyDbPointCloudColorMap::setColorScheme)
        .def("classificationScheme", &PyDbPointCloudColorMap::classificationScheme)
        .def("setClassificationScheme", &PyDbPointCloudColorMap::setClassificationScheme)

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

bool PyDbPointCloudColorMap::setDefaultIntensityColorScheme(const std::string& GUID)
{
    return impObj()->setDefaultIntensityColorScheme(utf8_to_wstr(GUID).c_str());
}

std::string PyDbPointCloudColorMap::defaultElevationColorScheme() const
{
    return wstr_to_utf8(impObj()->defaultElevationColorScheme());
}

bool PyDbPointCloudColorMap::setDefaultElevationColorScheme(const std::string& GUID)
{
    return impObj()->setDefaultElevationColorScheme(utf8_to_wstr(GUID).c_str());
}

std::string PyDbPointCloudColorMap::defaultClassificationColorScheme() const
{
    return wstr_to_utf8(impObj()->defaultClassificationColorScheme());
}

bool PyDbPointCloudColorMap::setDefaultClassificationColorScheme(const std::string& GUID)
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

bool PyDbPointCloudColorMap::deleteColorScheme(const std::string& GUID)
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

bool PyDbPointCloudColorMap::deleteClassificationScheme(const std::string& GUID)
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

boost::python::tuple PyDbPointCloudColorMap::colorScheme(const std::string& GUID)
{
    PyAutoLockGIL lock;
    PyDbPointCloudColorRamp pyramp;
    AcDbPointCloudColorRamp acramp;
    auto flag = impObj()->colorScheme(utf8_to_wstr(GUID).c_str(), acramp);
    pyramp.impObj()->setFrom(&acramp);
    return boost::python::make_tuple(flag, pyramp);
}

bool PyDbPointCloudColorMap::setColorScheme(const std::string& GUID, const PyDbPointCloudColorRamp& source)
{
    return impObj()->colorScheme(utf8_to_wstr(GUID).c_str(), *source.impObj());
}

boost::python::tuple PyDbPointCloudColorMap::classificationScheme(const std::string& GUID)
{
    PyAutoLockGIL lock;
    PyDbPointCloudClassificationColorRamp pyramp;
    AcDbPointCloudClassificationColorRamp acramp;
    auto flag = impObj()->classificationScheme(utf8_to_wstr(GUID).c_str(), acramp);
    pyramp.impObj()->setFrom(&acramp);
    return boost::python::make_tuple(flag, pyramp);
}

bool PyDbPointCloudColorMap::setClassificationScheme(const std::string& GUID, const PyDbPointCloudClassificationColorRamp& source)
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
    if (!src.impObj()->isKindOf(AcDbPointCloudColorMap::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbPointCloudColorMap(static_cast<AcDbPointCloudColorMap*>(src.impObj()->clone()), true);
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
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.ARGS({ "id: ObjectId", "mode: PyDb.OpenMode.kForRead", "erased: bool=False" })))
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
    PyDocString DS("PointCloudEx");
    class_<PyDbPointCloudEx, bases<PyDbEntity>>("PointCloudEx")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.ARGS({ "id: ObjectId", "mode: PyDb.OpenMode.kForRead", "erased: bool=False" })))
        .def("setPointCloudDefExId", &PyDbPointCloudEx::setPointCloudDefExId, DS.ARGS({ "val : PyDb.ObjectId" }))
        .def("pointCloudDefExId", &PyDbPointCloudEx::pointCloudDefExId, DS.ARGS())
        .def("setReactorId", &PyDbPointCloudEx::setReactorId, DS.ARGS({ "val : PyDb.ObjectId" }))
        .def("reactorId", &PyDbPointCloudEx::reactorId, DS.ARGS())
        .def("locked", &PyDbPointCloudEx::locked, DS.ARGS())
        .def("setLocked", &PyDbPointCloudEx::setLocked, DS.ARGS({ "val : bool" }))
        .def("scale", &PyDbPointCloudEx::scale, DS.ARGS())
        .def("setScale", &PyDbPointCloudEx::setScale)
        .def("rotation", &PyDbPointCloudEx::rotation, DS.ARGS())
        .def("setRotation", &PyDbPointCloudEx::setRotation)
        .def("location", &PyDbPointCloudEx::location, DS.ARGS())
        .def("setLocation", &PyDbPointCloudEx::setLocation)
        .def("getNativeCloudExtent", &PyDbPointCloudEx::getNativeCloudExtent, DS.ARGS())
        .def("getVisiblePointCount", &PyDbPointCloudEx::getVisiblePointCount, DS.ARGS())
        .def("getLoadedVisiblePointCount", &PyDbPointCloudEx::getLoadedVisiblePointCount, DS.ARGS())
        .def("getDisplayedVisiblePointCount", &PyDbPointCloudEx::getDisplayedVisiblePointCount, DS.ARGS())
        .def("setActiveFileName", &PyDbPointCloudEx::setActiveFileName)
        .def("getActiveFileName", &PyDbPointCloudEx::getActiveFileName, DS.ARGS())
        .def("getPointCloudName", &PyDbPointCloudEx::getPointCloudName, DS.ARGS())
        .def("setPointCloudName", &PyDbPointCloudEx::setPointCloudName)
        .def("getCroppingCount", &PyDbPointCloudEx::getCroppingCount, DS.ARGS())
        .def("clearCropping", &PyDbPointCloudEx::clearCropping, DS.ARGS())
        .def("removeLastCropping", &PyDbPointCloudEx::removeLastCropping, DS.ARGS())
        .def("getCroppingInvert", &PyDbPointCloudEx::getCroppingInvert, DS.ARGS())
        .def("setCroppingInvert", &PyDbPointCloudEx::setCroppingInvert)
        .def("setInCreatingCroppingMode", &PyDbPointCloudEx::setInCreatingCroppingMode)
        .def("showCropped", &PyDbPointCloudEx::showCropped, DS.ARGS())
        .def("setStylizationType", &PyDbPointCloudEx::setStylizationType)
        .def("stylizationType", &PyDbPointCloudEx::stylizationType, DS.ARGS())
        .def("getCurrentColorScheme", &PyDbPointCloudEx::getCurrentColorScheme, DS.ARGS())
        .def("setCurrentColorScheme", &PyDbPointCloudEx::setCurrentColorScheme)
        .def("getColorSchemeForStylization", &PyDbPointCloudEx::getColorSchemeForStylization)
        .def("setColorSchemeForStylization", &PyDbPointCloudEx::setColorSchemeForStylization)
        .def("showIntensityAsGradient", &PyDbPointCloudEx::showIntensityAsGradient, DS.ARGS())
        .def("setShowIntensityAsGradient", &PyDbPointCloudEx::setShowIntensityAsGradient)
        .def("minIntensity", &PyDbPointCloudEx::minIntensity, DS.ARGS())
        .def("maxIntensity", &PyDbPointCloudEx::maxIntensity, DS.ARGS())
        .def("setMinMaxIntensity", &PyDbPointCloudEx::setMinMaxIntensity)
        .def("intensityOutOfRangeBehavior", &PyDbPointCloudEx::intensityOutOfRangeBehavior, DS.ARGS())
        .def("setIntensityOutOfRangeBehavior", &PyDbPointCloudEx::setIntensityOutOfRangeBehavior)
        .def("showElevationAsGradient", &PyDbPointCloudEx::showElevationAsGradient, DS.ARGS())
        .def("setShowElevationAsGradient", &PyDbPointCloudEx::setShowElevationAsGradient)
        .def("minElevation", &PyDbPointCloudEx::minElevation, DS.ARGS())
        .def("maxElevation", &PyDbPointCloudEx::maxElevation, DS.ARGS())
        .def("setMinMaxElevation", &PyDbPointCloudEx::setMinMaxElevation)
        .def("elevationApplyToFixedRange", &PyDbPointCloudEx::elevationApplyToFixedRange, DS.ARGS())
        .def("setElevationApplyToFixedRange", &PyDbPointCloudEx::setElevationApplyToFixedRange, DS.ARGS())
        .def("elevationOutOfRangeBehavior", &PyDbPointCloudEx::elevationOutOfRangeBehavior, DS.ARGS())
        .def("setElevationOutOfRangeBehavior", &PyDbPointCloudEx::setElevationOutOfRangeBehavior)
        .def("resetLimitBox", &PyDbPointCloudEx::resetLimitBox, DS.ARGS())
        .def("setHighlightLimitboxBoundary", &PyDbPointCloudEx::setHighlightLimitboxBoundary)
        .def("setScanVisibility", &PyDbPointCloudEx::setScanVisibility)
        .def("setAllScansVisibility", &PyDbPointCloudEx::setAllScansVisibility)
        .def("setRegionVisibility", &PyDbPointCloudEx::setRegionVisibility)
        .def("setAllRegionsVisibility", &PyDbPointCloudEx::setAllRegionsVisibility1)
        .def("setAllRegionsVisibility", &PyDbPointCloudEx::setAllRegionsVisibility2)
        .def("setAllScansVisibilityByRegion", &PyDbPointCloudEx::setAllScansVisibilityByRegion)
        .def("getScanViewInfo", &PyDbPointCloudEx::getScanViewInfo)
        .def("resetScanRegionVisibility", &PyDbPointCloudEx::resetScanRegionVisibility, DS.ARGS())
        .def("setAllScanHighlight", &PyDbPointCloudEx::setAllScanHighlight)
        .def("setAllRegionHighlight", &PyDbPointCloudEx::setAllRegionHighlight1)
        .def("setAllRegionHighlight", &PyDbPointCloudEx::setAllRegionHighlight2)
        .def("applyGeoLocation", &PyDbPointCloudEx::applyGeoLocation1)
        .def("applyGeoLocation", &PyDbPointCloudEx::applyGeoLocation2)
        .def("updateGeoLocation", &PyDbPointCloudEx::updateGeoLocation, DS.ARGS())
        .def("geolocate", &PyDbPointCloudEx::geolocate, DS.ARGS())
        .def("clearSpatialFilters", &PyDbPointCloudEx::clearSpatialFilters, DS.ARGS())
        .def("clearAttributeFilters", &PyDbPointCloudEx::clearAttributeFilters, DS.ARGS())
        .def("getPlaneOrPointAt", &PyDbPointCloudEx::getPlaneOrPointAt)
        .def("getPlaneBoundaryAt", &PyDbPointCloudEx::getPlaneBoundaryAt)
        .def("objectToWorldMatrix", &PyDbPointCloudEx::objectToWorldMatrix, DS.ARGS())
        .def("getCandidatePlane", &PyDbPointCloudEx::getCandidatePlane)
        .def("getCylinderAt", &PyDbPointCloudEx::getCylinderAt)
        .def("getMinDistPrecision", &PyDbPointCloudEx::getMinDistPrecision, DS.ARGS())
        .def("detectPointBelonger", &PyDbPointCloudEx::detectPointBelonger)
        .def("getCustomOsnapInfo", &PyDbPointCloudEx::getCustomOsnapInfo)
        .def("getPointCloudCropping", &PyDbPointCloudEx::getPointCloudCropping)
        .def("addCroppingBoundary", &PyDbPointCloudEx::addCroppingBoundary)
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

void PyDbPointCloudEx::setPointCloudDefExId(const PyDbObjectId& defExId)
{
    impObj()->setPointCloudDefExId(defExId.m_id);
}

PyDbObjectId PyDbPointCloudEx::pointCloudDefExId() const
{
    return PyDbObjectId(impObj()->pointCloudDefExId());
}

void PyDbPointCloudEx::setReactorId(const PyDbObjectId& reactorId)
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

void PyDbPointCloudEx::setLocked(bool locked)
{
    return impObj()->setLocked(locked);
}

double PyDbPointCloudEx::scale() const
{
    return impObj()->scale();
}

void PyDbPointCloudEx::setScale(double val)
{
    PyThrowBadEs(impObj()->setScale(val));
}

double PyDbPointCloudEx::rotation() const
{
    return impObj()->rotation();
}

void PyDbPointCloudEx::setRotation(double val)
{
    PyThrowBadEs(impObj()->setRotation(val));
}

AcGePoint3d PyDbPointCloudEx::location() const
{
    return impObj()->location();
}

void PyDbPointCloudEx::setLocation(const AcGePoint3d& pt)
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

bool PyDbPointCloudEx::setActiveFileName(const std::string& strActiveFileName)
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

void PyDbPointCloudEx::setPointCloudName(const std::string& name)
{
    PyThrowBadEs(impObj()->setPointCloudName((utf8_to_wstr(name).c_str())));
}

int PyDbPointCloudEx::getCroppingCount() const
{
    return impObj()->getCroppingCount();
}

PyDbPointCloudCrop PyDbPointCloudEx::getPointCloudCropping(int index)
{
    return PyDbPointCloudCrop(*impObj()->getPointCloudCropping(index));
}

void PyDbPointCloudEx::addCroppingBoundary(const PyDbPointCloudCrop& cropping)
{
    impObj()->addCroppingBoundary(*cropping.impObj());
}

void PyDbPointCloudEx::clearCropping()
{
    PyThrowBadEs(impObj()->clearCropping());
}

void PyDbPointCloudEx::removeLastCropping()
{
    PyThrowBadEs(impObj()->removeLastCropping());
}

bool PyDbPointCloudEx::getCroppingInvert() const
{
    return impObj()->getCroppingInvert();
}

void PyDbPointCloudEx::setCroppingInvert(bool invert)
{
    PyThrowBadEs(impObj()->setCroppingInvert(invert));
}

void PyDbPointCloudEx::setInCreatingCroppingMode(bool bCreating)
{
    impObj()->setInCreatingCroppingMode(bCreating);
}

bool PyDbPointCloudEx::showCropped() const
{
    return impObj()->showCropped();
}

void PyDbPointCloudEx::setStylizationType(AcDbPointCloudEx::StylizationType type)
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

void PyDbPointCloudEx::setCurrentColorScheme(const std::string& guid)
{
    PyThrowBadEs(impObj()->setCurrentColorScheme(utf8_to_wstr(guid).c_str()));
}

std::string PyDbPointCloudEx::getColorSchemeForStylization(AcDbPointCloudEx::StylizationType type) const
{
    return wstr_to_utf8(impObj()->getColorSchemeForStylization(type));
}

void PyDbPointCloudEx::setColorSchemeForStylization(const std::string& guid, AcDbPointCloudEx::StylizationType type)
{
    PyThrowBadEs(impObj()->setColorSchemeForStylization(utf8_to_wstr(guid).c_str(), type));
}

bool PyDbPointCloudEx::showIntensityAsGradient() const
{
    return impObj()->showIntensityAsGradient();
}

void PyDbPointCloudEx::setShowIntensityAsGradient(bool b)
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

void PyDbPointCloudEx::setMinMaxIntensity(int min, int max)
{
    PyThrowBadEs(impObj()->setMinMaxIntensity(min, max));
}

AcDbPointCloudEx::DispOptionOutOfRange PyDbPointCloudEx::intensityOutOfRangeBehavior() const
{
    return impObj()->intensityOutOfRangeBehavior();
}

void PyDbPointCloudEx::setIntensityOutOfRangeBehavior(AcDbPointCloudEx::DispOptionOutOfRange dispOp)
{
    impObj()->setIntensityOutOfRangeBehavior(dispOp);
}

bool PyDbPointCloudEx::showElevationAsGradient() const
{
    return impObj()->showElevationAsGradient();
}

void PyDbPointCloudEx::setShowElevationAsGradient(bool b)
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

void PyDbPointCloudEx::setMinMaxElevation(double min, double max)
{
    PyThrowBadEs(impObj()->setMinMaxElevation(min, max));
}

bool PyDbPointCloudEx::elevationApplyToFixedRange() const
{
    return impObj()->elevationApplyToFixedRange();
}

void PyDbPointCloudEx::setElevationApplyToFixedRange(bool val)
{
    impObj()->setElevationApplyToFixedRange(val);
}

AcDbPointCloudEx::DispOptionOutOfRange PyDbPointCloudEx::elevationOutOfRangeBehavior() const
{
    return impObj()->elevationOutOfRangeBehavior();
}

void PyDbPointCloudEx::setElevationOutOfRangeBehavior(AcDbPointCloudEx::DispOptionOutOfRange dispOp)
{
    impObj()->setElevationOutOfRangeBehavior(dispOp);
}

void PyDbPointCloudEx::resetLimitBox()
{
    impObj()->resetLimitBox();
}

void PyDbPointCloudEx::setHighlightLimitboxBoundary(bool val)
{
    impObj()->setHighlightLimitboxBoundary(val);
}

void PyDbPointCloudEx::setScanVisibility(const std::string& scanGuid, bool bVisible)
{
    impObj()->setScanVisibility(utf8_to_wstr(scanGuid).c_str(), bVisible);
}

void PyDbPointCloudEx::setAllScansVisibility(bool bVisible)
{
    impObj()->setAllScansVisibility(bVisible);
}

void PyDbPointCloudEx::setRegionVisibility(int regionId, bool bVisible)
{
    impObj()->setRegionVisibility(regionId, bVisible);
}

void PyDbPointCloudEx::setAllRegionsVisibility1(bool bVisible)
{
    impObj()->setAllRegionsVisibility(bVisible);
}

void PyDbPointCloudEx::setAllRegionsVisibility2(bool bVisible, bool includeUnassigned)
{
    impObj()->setAllRegionsVisibility(bVisible, includeUnassigned);
}

void PyDbPointCloudEx::setAllScansVisibilityByRegion(int regionId, bool bVisible)
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

void PyDbPointCloudEx::resetScanRegionVisibility()
{
    impObj()->resetScanRegionVisibility();
}

void PyDbPointCloudEx::setAllScanHighlight(bool bHighlight)
{
    impObj()->setAllScanHighlight(bHighlight);
}

void PyDbPointCloudEx::setAllRegionHighlight1(bool bHighlight)
{
    impObj()->setAllRegionHighlight(bHighlight);
}

void PyDbPointCloudEx::setAllRegionHighlight2(bool bHighlight, bool bIncludeUnassignedPoints)
{
    impObj()->setAllRegionHighlight(bHighlight, bIncludeUnassignedPoints);
}

void PyDbPointCloudEx::applyGeoLocation1()
{
    impObj()->applyGeoLocation();
}

void PyDbPointCloudEx::applyGeoLocation2(bool useDrawingGeo, const std::string& geoCS)
{
    impObj()->applyGeoLocation(useDrawingGeo, utf8_to_wstr(geoCS).c_str());
}

void PyDbPointCloudEx::updateGeoLocation()
{
    impObj()->updateGeoLocation();
}

bool PyDbPointCloudEx::geolocate() const
{
    return impObj()->geolocate();
}

void PyDbPointCloudEx::clearSpatialFilters()
{
    impObj()->clearSpatialFilters();
}

void PyDbPointCloudEx::clearAttributeFilters()
{
    impObj()->clearAttributeFilters();
}

boost::python::tuple PyDbPointCloudEx::getPlaneOrPointAt(const AcGeMatrix3d& viewXform, const AcGePoint3d& pickPt)
{
    PyAutoLockGIL lock;
    AcGePoint3dArray points;
    auto val = impObj()->getPlaneOrPointAt(viewXform, pickPt, points);
    return boost::python::make_tuple(val, Point3dArrayToPyList(points));
}

boost::python::tuple PyDbPointCloudEx::getPlaneBoundaryAt(const AcGeMatrix3d& viewXform, const AcGePoint3d& pickPt)
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

boost::python::tuple PyDbPointCloudEx::getCylinderAt(const AcGeMatrix3d& viewXform, const AcGePoint3d& pickPt)
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

boost::python::list PyDbPointCloudEx::getCustomOsnapInfo(AcDbPointCloudEx::PointCloudOSnapMode snapMode, const AcGePoint3d& pickPoint, const AcGePoint3d& lastPoint, const AcGeMatrix3d& viewXform)
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
    if (!src.impObj()->isKindOf(AcDbPointCloudEx::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbPointCloudEx(static_cast<AcDbPointCloudEx*>(src.impObj()->clone()), true);
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