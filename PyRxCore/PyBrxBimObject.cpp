#include "stdafx.h"
#include "PyBrxBimObject.h"

#ifdef BRXAPP
#include "PyDbDatabase.h"
#include "PyDbObjectId.h"
#include "AnchorFeature.h"
#include "Blockify.h"
#include "IfcExportReactor.h"
#include "IfcImportReactor.h"

using namespace boost::python;


//---------------------------------------------------------------------------------------- -
//PyBrxBimPolicies
void makePyBrxBimPoliciesWrapper()
{
    PyDocString DS("BimPolicies");
    class_<BrxBimPolicies>("BimPolicies", boost::python::no_init)
        .def("getPolicy", &PyBrxBimPolicies::getPolicy, DS.SARGS({ "option: PyBrxBim.BimPolicyOptions" })).staticmethod("getPolicy")
        .def("setPolicy", &PyBrxBimPolicies::setPolicy, DS.SARGS({ "option: PyBrxBim.BimPolicyOptions", "enable: bool" })).staticmethod("setPolicy")
        .def("className", &PyBrxBimPolicies::className, DS.SARGS()).staticmethod("className")
        ;
}

void PyBrxBimPolicies::setPolicy(BrxBimPolicies::EPolicyOptions option, bool enable)
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    BrxBimPolicies::setPolicy(option, enable);
#endif
}

bool PyBrxBimPolicies::getPolicy(BrxBimPolicies::EPolicyOptions option)
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return BrxBimPolicies::getPolicy(option);
#endif
}

std::string PyBrxBimPolicies::className()
{
    return "BrxBimPolicies";
}

//---------------------------------------------------------------------------------------- -
//PyBrxBimObject
void makePyBrxBimObjectWrapper()
{
    PyDocString DS("BimObject");
    class_<PyBrxBimObject>("BimObject", boost::python::no_init)
        .def("typeDesc", &PyBrxBimObject::typeDesc, DS.ARGS())
        .def("typeName", &PyBrxBimObject::typeName, DS.ARGS())
        .def("isNull", &PyBrxBimObject::isNull, DS.ARGS())
        .def("setNull", &PyBrxBimObject::setNull, DS.ARGS())
        .def("name", &PyBrxBimObject::name, DS.ARGS())
        .def("description", &PyBrxBimObject::description, DS.ARGS())
        .def("setName", &PyBrxBimObject::setName, DS.ARGS({ "val: str" }))
        .def("setDescription", &PyBrxBimObject::setDescription, DS.ARGS({ "val: str" }))
        .def("cast", &PyBrxBimObject::cast, DS.SARGS({ "otherObject: PyBrxBim.BimObject" })).staticmethod("cast")
        .def("className", &PyBrxBimObject::className, DS.SARGS()).staticmethod("className")
        ;
}

PyBrxBimObject::PyBrxBimObject(const BrxBimObject* pObject)
    :PyBrxBimObject(const_cast<BrxBimObject*>(pObject), false)
{
}

PyBrxBimObject::PyBrxBimObject(BrxBimObject* pObject, bool autoDelete)
    : m_pyImp(pObject, PySharedObjectDeleter<BrxBimObject>(autoDelete))
{
}

BimApi::BimObjectType PyBrxBimObject::typeDesc()
{
    return impObj()->typeDesc();
}

std::string PyBrxBimObject::typeName()
{
    return wstr_to_utf8(impObj()->typeName());
}

bool PyBrxBimObject::isNull() const
{
    return m_pyImp == nullptr;
}

void PyBrxBimObject::setNull()
{
    m_pyImp.reset();
}

std::string PyBrxBimObject::name() const
{
    return wstr_to_utf8(impObj()->name());
}

std::string PyBrxBimObject::description() const
{
    return wstr_to_utf8(impObj()->description());
}

void PyBrxBimObject::setName(const std::string& szNewName) const
{
    PyThrowBadBim(impObj()->setName(utf8_to_wstr(szNewName).c_str()));
}

void PyBrxBimObject::setDescription(const std::string& szInfo) const
{
    PyThrowBadBim(impObj()->setDescription(utf8_to_wstr(szInfo).c_str()));
}

PyBrxBimObject PyBrxBimObject::cast(const PyBrxBimObject& src)
{
    return PyBrxBimObjectCast<PyBrxBimObject>(src);
}

std::string PyBrxBimObject::className()
{
    return "BrxBimObject";
}

BrxBimObject* PyBrxBimObject::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<BrxBimObject*>(m_pyImp.get());
}

//---------------------------------------------------------------------------------------- -
//PyBrxBimSpatialLocation
void makePyBrxBimSpatialLocationWrapper()
{
    PyDocString DS("BimSpatialLocation");
    class_<PyBrxBimSpatialLocation, bases<PyBrxBimObject>>("BimSpatialLocation")
        //TODO check if other constructors are useful 
        .def("longName", &PyBrxBimSpatialLocation::longName, DS.ARGS())
        .def("setLongName", &PyBrxBimSpatialLocation::setLongName)
        .def("isStory", &PyBrxBimSpatialLocation::isStory, DS.ARGS())
        .def("isBuilding", &PyBrxBimSpatialLocation::isBuilding, DS.ARGS())
        .def("hasStory", &PyBrxBimSpatialLocation::hasStory, DS.ARGS())
        .def("hasBuilding", &PyBrxBimSpatialLocation::hasBuilding, DS.ARGS())
        .def("assignedObjects", &PyBrxBimSpatialLocation::assignedObjects, DS.ARGS({ "id: PyDb.ObjectId" }))
        .def("assignToEntity", &PyBrxBimSpatialLocation::assignToEntity, DS.ARGS({ "id: PyDb.ObjectId" }))
        .def("assignedSpatialLocation", &PyBrxBimSpatialLocation::assignedSpatialLocation, DS.SARGS({ "id: PyDb.ObjectId" })).staticmethod("assignedSpatialLocation")
        .def("removeSpatialLocationFrom", &PyBrxBimSpatialLocation::removeSpatialLocationFrom, DS.SARGS({ "id: PyDb.ObjectId" })).staticmethod("removeSpatialLocationFrom")
        .def("cast", &PyBrxBimSpatialLocation::cast, DS.SARGS({ "otherObject: PyBrxBim.BimObject" })).staticmethod("cast")
        .def("className", &PyBrxBimSpatialLocation::className, DS.SARGS()).staticmethod("className")
        ;
}

PyBrxBimSpatialLocation::PyBrxBimSpatialLocation()
    : PyBrxBimSpatialLocation(new BrxBimSpatialLocation(), true)
{
}

PyBrxBimSpatialLocation::PyBrxBimSpatialLocation(const BrxBimSpatialLocation* pObject)
    : PyBrxBimObject(pObject)
{
}

PyBrxBimSpatialLocation::PyBrxBimSpatialLocation(BrxBimSpatialLocation* pObject, bool autoDelete)
    : PyBrxBimObject(pObject, autoDelete)
{
}

PyBrxBimSpatialLocation::PyBrxBimSpatialLocation(const BrxBimSpatialLocation& r)
    : PyBrxBimSpatialLocation(new BrxBimSpatialLocation(r), true)
{
}

std::string PyBrxBimSpatialLocation::longName() const
{
    return wstr_to_utf8(impObj()->longName());
}

void PyBrxBimSpatialLocation::setLongName(const std::string& szLongName) const
{
    PyThrowBadBim(impObj()->setLongName(utf8_to_wstr(szLongName).c_str()));
}

bool PyBrxBimSpatialLocation::isStory() const
{
    return impObj()->isStory();
}

bool PyBrxBimSpatialLocation::isBuilding() const
{
    return impObj()->isBuilding();
}

bool PyBrxBimSpatialLocation::hasStory() const
{
    return impObj()->hasStory();
}

bool PyBrxBimSpatialLocation::hasBuilding() const
{
    return impObj()->hasBuilding();
}

boost::python::list PyBrxBimSpatialLocation::assignedObjects(const PyDbDatabase& database) const
{
    AcDbObjectIdArray ids;
    PyThrowBadBim(impObj()->assignedObjects(ids, database.impObj()));
    return ObjectIdArrayToPyList(ids);
}

void PyBrxBimSpatialLocation::assignToEntity(const PyDbObjectId& id) const
{
    PyThrowBadBim(impObj()->assignToEntity(id.m_id));
}

PyBrxBimSpatialLocation PyBrxBimSpatialLocation::assignedSpatialLocation(const PyDbObjectId& id)
{
    BrxBimSpatialLocation spatialLocation;
    PyThrowBadBim(BrxBimSpatialLocation::assignedSpatialLocation(spatialLocation, id.m_id));
    return PyBrxBimSpatialLocation{ spatialLocation };
}

void PyBrxBimSpatialLocation::removeSpatialLocationFrom(const PyDbObjectId& id)
{
    PyThrowBadBim(BrxBimSpatialLocation::removeSpatialLocationFrom(id.m_id));
}

PyBrxBimSpatialLocation PyBrxBimSpatialLocation::cast(const PyBrxBimObject& src)
{
    return PyBrxBimObjectCast<PyBrxBimSpatialLocation>(src);
}

std::string PyBrxBimSpatialLocation::className()
{
    return "BrxBimSpatialLocation";
}

BrxBimSpatialLocation* PyBrxBimSpatialLocation::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<BrxBimSpatialLocation*>(m_pyImp.get());
}

//---------------------------------------------------------------------------------------- -
//PyBrxBimStory
void makeBrxBimStorynWrapper()
{
    PyDocString DS("BimStory");
    class_<PyBrxBimStory, bases<PyBrxBimSpatialLocation>>("BimStory")
        .def("createStory", &PyBrxBimStory::createStory, DS.ARGS({ "szName: str", "building: PyBrxBim.Building"}))
        .def("deleteStory", &PyBrxBimStory::deleteStory, DS.ARGS())
        .def("elevation", &PyBrxBimStory::elevation, DS.ARGS())
        .def("setElevation", &PyBrxBimStory::setElevation, DS.ARGS({ "val: float" }))
        .def("getBuilding", &PyBrxBimStory::getBuilding, DS.ARGS())
        .def("createNewStory", &PyBrxBimStory::createNewStory, DS.ARGS({ "db: PyDb.Database","buildingName: str","storyName: str" })).staticmethod("createNewStory")
        .def("deleteStoryFromDatabase", &PyBrxBimStory::deleteStoryFromDatabase, DS.ARGS({ "db: PyDb.Database","buildingName: str","storyName: str" })).staticmethod("deleteStoryFromDatabase")
        .def("getStory", &PyBrxBimStory::getStory, DS.ARGS({ "db: PyDb.Database","buildingName: str","storyName: str" })).staticmethod("getStory")
        .def("assignedStory", &PyBrxBimStory::assignedStory, DS.SARGS({ "id: PyDb.ObjectId" })).staticmethod("assignedStory")
        .def("allStories", &PyBrxBimStory::allStories, DS.SARGS({ "db: PyDb.Database" })).staticmethod("allStories")
        .def("allStoryNames", &PyBrxBimStory::allStoryNames, DS.SARGS({ "db: PyDb.Database" })).staticmethod("allStoryNames")
        .def("cast", &PyBrxBimStory::cast, DS.SARGS({ "otherObject: PyBrxBim.BimObject" })).staticmethod("cast")
        .def("className", &PyBrxBimStory::className, DS.SARGS()).staticmethod("className")
        ;
}

PyBrxBimStory::PyBrxBimStory()
    : PyBrxBimStory(new BrxBimStory(), true)
{
}

PyBrxBimStory::PyBrxBimStory(const BrxBimStory& r)
    : PyBrxBimStory(new BrxBimStory(r), true)
{
}

PyBrxBimStory::PyBrxBimStory(const BrxBimStory* ptr)
    : PyBrxBimSpatialLocation(ptr)
{
}

PyBrxBimStory::PyBrxBimStory(BrxBimStory* pObject, bool autoDelete)
    : PyBrxBimSpatialLocation(pObject, autoDelete)
{
}

void PyBrxBimStory::createStory(const std::string& szName, const PyBrxBimBuilding& building)
{
    PyThrowBadBim(impObj()->createStory(utf8_to_wstr(szName).c_str(), *building.impObj()));
}

PyBrxBimStory PyBrxBimStory::createNewStory(const PyDbDatabase& database, const std::string& buildingName, const std::string& storyName)
{
    BrxBimStory obj;
    PyThrowBadBim(BrxBimStory::createStory(obj, database.impObj(), utf8_to_wstr(buildingName).c_str(), utf8_to_wstr(storyName).c_str()));
    return PyBrxBimStory(obj);
}

void PyBrxBimStory::deleteStoryFromDatabase(const PyDbDatabase& database, const std::string& buildingName, const std::string& storyName)
{
    PyThrowBadBim(BrxBimStory::deleteStory(database.impObj(), utf8_to_wstr(buildingName).c_str(), utf8_to_wstr(storyName).c_str()));
}

PyBrxBimStory PyBrxBimStory::getStory(const PyDbDatabase& database, const std::string& buildingName, const std::string& storyName)
{
    BrxBimStory obj;
    PyThrowBadBim(BrxBimStory::getStory(obj, database.impObj(), utf8_to_wstr(buildingName).c_str(), utf8_to_wstr(storyName).c_str()));
    return PyBrxBimStory(obj);
}

PyBrxBimStory PyBrxBimStory::assignedStory(const PyDbObjectId& id)
{
    BrxBimStory obj;
    PyThrowBadBim(BrxBimStory::assignedStory(obj,id.m_id));
    return PyBrxBimStory(obj);
}

boost::python::list PyBrxBimStory::allStories(const PyDbDatabase& database)
{
    PyAutoLockGIL lock;
    BimApi::BimStories stories;
    PyThrowBadBim(BrxBimStory::allStories(stories, database.impObj()));
    boost::python::list pylist;
    for (const auto& obj : stories)
        pylist.append(PyBrxBimStory(obj));
    return pylist;
}

boost::python::list PyBrxBimStory::allStoryNames(const PyDbDatabase& database)
{
    PyAutoLockGIL lock;
    AcStringArray stories;
    PyThrowBadBim(BrxBimStory::allStories(stories, database.impObj()));
    boost::python::list pylist;
    for (const auto& obj : stories)
        pylist.append(wstr_to_utf8(obj));
    return pylist;
}

void PyBrxBimStory::deleteStory()
{
    PyThrowBadBim(impObj()->deleteStory());
}

double PyBrxBimStory::elevation() const
{
    return impObj()->elevation();
}

void PyBrxBimStory::setElevation(double elevation) const
{
    PyThrowBadBim(impObj()->setElevation(elevation));
}

PyBrxBimBuilding PyBrxBimStory::getBuilding() const
{
    BrxBimBuilding obj;
    PyThrowBadBim(impObj()->getBuilding(obj));
    return PyBrxBimBuilding(obj);
}

PyBrxBimStory PyBrxBimStory::cast(const PyBrxBimObject& src)
{
    return PyBrxBimObjectCast<PyBrxBimStory>(src);
}

std::string PyBrxBimStory::className()
{
    return "BrxBimStory";
}

BrxBimStory* PyBrxBimStory::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<BrxBimStory*>(m_pyImp.get());
}

//---------------------------------------------------------------------------------------- -
//PyBrxBimBuilding
void makeBrxBimBuildingWrapper()
{
    PyDocString DS("BimBuilding");
    class_<PyBrxBimBuilding, bases<PyBrxBimSpatialLocation>>("BimBuilding")
        .def("cast", &PyBrxBimBuilding::cast, DS.SARGS({ "otherObject: PyBrxBim.BimObject" })).staticmethod("cast")
        .def("className", &PyBrxBimBuilding::className, DS.SARGS()).staticmethod("className")
        ;
}

PyBrxBimBuilding::PyBrxBimBuilding()
    : PyBrxBimBuilding(new BrxBimBuilding(), true)
{
}

PyBrxBimBuilding::PyBrxBimBuilding(const BrxBimBuilding& r)
    : PyBrxBimBuilding(new BrxBimBuilding(r), true)
{
}

PyBrxBimBuilding::PyBrxBimBuilding(const BrxBimBuilding* ptr)
    : PyBrxBimSpatialLocation(ptr)
{
}

PyBrxBimBuilding::PyBrxBimBuilding(BrxBimBuilding* pObject, bool autoDelete)
    : PyBrxBimSpatialLocation(pObject, autoDelete)
{
}

PyBrxBimBuilding PyBrxBimBuilding::cast(const PyBrxBimObject& src)
{
    return PyBrxBimObjectCast<PyBrxBimBuilding>(src);
}

std::string PyBrxBimBuilding::className()
{
    return "BimBuilding";
}

BrxBimBuilding* PyBrxBimBuilding::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<BrxBimBuilding*>(m_pyImp.get());
}

//---------------------------------------------------------------------------------------- -
//PyBrxBimRoom
void makeBrxBimRoomWrapper()
{
    constexpr const std::string_view ctor = "Overloads:\n"
        "- None: Any\n"
        "- id: PyDb.ObjectId\n";

    PyDocString DS("BimRoom");
    class_<PyBrxBimRoom, bases<PyBrxBimObject>>("BimRoom")
        .def(init<>())
        .def(init<const PyDbObjectId&>(DS.CTOR(ctor)))
        .def("cast", &PyBrxBimRoom::cast, DS.SARGS({ "otherObject: PyBrxBim.BimObject" })).staticmethod("cast")
        .def("className", &PyBrxBimRoom::className, DS.SARGS()).staticmethod("className")
        ;
}

PyBrxBimRoom::PyBrxBimRoom()
    : PyBrxBimObject(new BrxBimRoom(), true)
{
}

PyBrxBimRoom::PyBrxBimRoom(const PyDbObjectId& id)
    : PyBrxBimObject(new BrxBimRoom(id.m_id), true)
{
}

PyBrxBimRoom::PyBrxBimRoom(const BrxBimRoom& r)
    : PyBrxBimObject(new BrxBimRoom(r), true)
{
}

PyBrxBimRoom::PyBrxBimRoom(const BrxBimRoom* ptr)
    : PyBrxBimObject(ptr)
{
}

PyBrxBimRoom::PyBrxBimRoom(BrxBimRoom* pObject, bool autoDelete)
    : PyBrxBimObject(pObject, autoDelete)
{
}

PyBrxBimRoom PyBrxBimRoom::cast(const PyBrxBimObject& src)
{
    return PyBrxBimObjectCast<PyBrxBimRoom>(src);
}

std::string PyBrxBimRoom::className()
{
    return "BrxBimRoom";
}

BrxBimRoom* PyBrxBimRoom::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<BrxBimRoom*>(m_pyImp.get());
}

//---------------------------------------------------------------------------------------- -
//PyBrxBimSpace
void makeBrxBimSpaceWrapper()
{
    PyDocString DS("BimSpace");
    class_<PyBrxBimSpace>("BimSpace")
        .def("className", &PyBrxBimSpace::className, DS.SARGS()).staticmethod("className")
        ;
}

std::string PyBrxBimSpace::className()
{
    return "BimSpace";
}

//---------------------------------------------------------------------------------------- -
//PyBrxBimMaterial
void makeBrxBimMaterialWrapper()
{
    constexpr const std::string_view ctor = "Overloads:\n"
        "- None: Any\n"
        "- name: str\n";

    PyDocString DS("BimMaterial");
    class_<PyBrxBimMaterial, bases<PyBrxBimObject>>("BimMaterial")
        .def(init<>())
        .def(init<const std::string&>(DS.CTOR(ctor)))
        .def("cast", &PyBrxBimMaterial::cast, DS.SARGS({ "otherObject: PyBrxBim.BimObject" })).staticmethod("cast")
        .def("className", &PyBrxBimMaterial::className, DS.SARGS()).staticmethod("className")
        ;
}

PyBrxBimMaterial::PyBrxBimMaterial()
    : PyBrxBimMaterial(new BrxBimMaterial(), true)
{
}

PyBrxBimMaterial::PyBrxBimMaterial(const std::string& id)
    : PyBrxBimMaterial(new BrxBimMaterial(utf8_to_wstr(id).c_str()), true)
{
}

PyBrxBimMaterial::PyBrxBimMaterial(const BrxBimMaterial& r)
    : PyBrxBimMaterial(new BrxBimMaterial(r), true)
{
}

PyBrxBimMaterial::PyBrxBimMaterial(const BrxBimMaterial* ptr)
    : PyBrxBimObject(ptr)
{
}

PyBrxBimMaterial::PyBrxBimMaterial(BrxBimMaterial* pObject, bool autoDelete)
    : PyBrxBimObject(pObject, autoDelete)
{
}

PyBrxBimMaterial PyBrxBimMaterial::cast(const PyBrxBimObject& src)
{
    return PyBrxBimObjectCast<PyBrxBimMaterial>(src);
}

std::string PyBrxBimMaterial::className()
{
    return "BimMaterial";
}

BrxBimMaterial* PyBrxBimMaterial::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<BrxBimMaterial*>(m_pyImp.get());
}

//---------------------------------------------------------------------------------------- -
//PyBrxBimHatchPattern
void makeBrxBimHatchPatternWrapper()
{
    constexpr const std::string_view ctor = "Overloads:\n"
        "- None: Any\n"
        "- scaleOrSpacing: float,angle: float=0.0,cross: bool=False\n"
        "- hType: PyBrxBim.BimHatchType, name:str, scaleOrSpacing: float= 1.0, angle: float=0.0\n";

    PyDocString DS("BimHatchPattern");
    class_<PyBrxBimHatchPattern>("BimHatchPattern")
        .def(init<>())
        .def(init<double, double, bool>())
        .def(init<BrxBimMaterial::EHatchType, const std::string&, double, double>(DS.CTOR(ctor)))
        .def("className", &PyBrxBimHatchPattern::className, DS.SARGS()).staticmethod("className")
        ;
}

PyBrxBimHatchPattern::PyBrxBimHatchPattern()
    : PyBrxBimHatchPattern(new BrxBimMaterial::HatchPattern(), true)
{
}

PyBrxBimHatchPattern::PyBrxBimHatchPattern(double scaleOrSpacing, double angle /*= 0.0*/, bool cross /*= false*/)
    : PyBrxBimHatchPattern(new BrxBimMaterial::HatchPattern(scaleOrSpacing, angle, cross), true)
{
}

PyBrxBimHatchPattern::PyBrxBimHatchPattern(BrxBimMaterial::EHatchType type, const std::string& name, double scaleOrSpacing /*= 1.0*/, double angle /*= 0.0*/)
    : PyBrxBimHatchPattern(new BrxBimMaterial::HatchPattern(type, utf8_to_wstr(name).c_str(), scaleOrSpacing, angle), true)
{
}

PyBrxBimHatchPattern::PyBrxBimHatchPattern(const BrxBimMaterial::HatchPattern& r)
    : PyBrxBimHatchPattern(new BrxBimMaterial::HatchPattern(r), true)
{
}

PyBrxBimHatchPattern::PyBrxBimHatchPattern(const BrxBimMaterial::HatchPattern* ptr)
    :PyBrxBimHatchPattern(const_cast<BrxBimMaterial::HatchPattern*>(ptr), false)
{
}

PyBrxBimHatchPattern::PyBrxBimHatchPattern(BrxBimMaterial::HatchPattern* pObject, bool autoDelete)
    : m_pyImp(pObject, PySharedObjectDeleter<BrxBimMaterial::HatchPattern>(autoDelete))
{
}

std::string PyBrxBimHatchPattern::className()
{
    return "BimHatchPattern";
}

BrxBimMaterial::HatchPattern* PyBrxBimHatchPattern::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<BrxBimMaterial::HatchPattern*>(m_pyImp.get());
}

//---------------------------------------------------------------------------------------- -
//PyBrxBimInformationalAssets
void makeBrxBimInformationalAssetsWrapper()
{
    PyDocString DS("BimInformationalAssets");
    class_<PyBrxBimInformationalAssets>("BimInformationalAssets", boost::python::no_init)
        .def("className", &PyBrxBimInformationalAssets::className, DS.SARGS()).staticmethod("className")
        ;
}

PyBrxBimInformationalAssets::PyBrxBimInformationalAssets(const BrxBimMaterial::InformationalAssets& r)
    : PyBrxBimInformationalAssets(new BrxBimMaterial::InformationalAssets(r), true)
{
}

PyBrxBimInformationalAssets::PyBrxBimInformationalAssets(const BrxBimMaterial::InformationalAssets* ptr)
    :PyBrxBimInformationalAssets(const_cast<BrxBimMaterial::InformationalAssets*>(ptr), false)
{
}

PyBrxBimInformationalAssets::PyBrxBimInformationalAssets(BrxBimMaterial::InformationalAssets* pObject, bool autoDelete)
    : m_pyImp(pObject, PySharedObjectDeleter<BrxBimMaterial::InformationalAssets>(autoDelete))
{
}

std::string PyBrxBimInformationalAssets::className()
{
    return "BimInformationalAssets";
}

BrxBimMaterial::InformationalAssets* PyBrxBimInformationalAssets::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<BrxBimMaterial::InformationalAssets*>(m_pyImp.get());
}

//---------------------------------------------------------------------------------------- -
//PyBrxBimPhysicalAssets
void makeBrxBimPhysicalAssetsWrapper()
{
    PyDocString DS("BimPhysicalAssets");
    class_<PyBrxBimPhysicalAssets>("BimPhysicalAssets", boost::python::no_init)
        .def("className", &PyBrxBimPhysicalAssets::className, DS.SARGS()).staticmethod("className")
        ;
}

PyBrxBimPhysicalAssets::PyBrxBimPhysicalAssets(const BrxBimMaterial::PhysicalAssets& r)
    : PyBrxBimPhysicalAssets(new BrxBimMaterial::PhysicalAssets(r), true)
{
}

PyBrxBimPhysicalAssets::PyBrxBimPhysicalAssets(const BrxBimMaterial::PhysicalAssets* ptr)
    :PyBrxBimPhysicalAssets(const_cast<BrxBimMaterial::PhysicalAssets*>(ptr), false)
{
}

PyBrxBimPhysicalAssets::PyBrxBimPhysicalAssets(BrxBimMaterial::PhysicalAssets* pObject, bool autoDelete)
    : m_pyImp(pObject, PySharedObjectDeleter<BrxBimMaterial::PhysicalAssets>(autoDelete))
{
}

std::string PyBrxBimPhysicalAssets::className()
{
    return "BimPhysicalAssets";
}

BrxBimMaterial::PhysicalAssets* PyBrxBimPhysicalAssets::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<BrxBimMaterial::PhysicalAssets*>(m_pyImp.get());
}

//---------------------------------------------------------------------------------------- -
//PyBrxBimAssets
void makeBrxBimAssetsWrapper()
{
    PyDocString DS("BimAssets");
    class_<PyBrxBimAssets>("BimAssets", boost::python::no_init)
        .def("className", &PyBrxBimAssets::className, DS.SARGS()).staticmethod("className")
        ;
}

PyBrxBimAssets::PyBrxBimAssets(const BrxBimMaterial::BimAssets& r)
    : PyBrxBimAssets(new BrxBimMaterial::BimAssets(r), true)
{
}

PyBrxBimAssets::PyBrxBimAssets(const BrxBimMaterial::BimAssets* ptr)
    :PyBrxBimAssets(const_cast<BrxBimMaterial::BimAssets*>(ptr), false)
{
}

PyBrxBimAssets::PyBrxBimAssets(BrxBimMaterial::BimAssets* pObject, bool autoDelete)
    : m_pyImp(pObject, PySharedObjectDeleter<BrxBimMaterial::BimAssets>(autoDelete))
{
}

std::string PyBrxBimAssets::className()
{
    return "BimAssets";
}

BrxBimMaterial::BimAssets* PyBrxBimAssets::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<BrxBimMaterial::BimAssets*>(m_pyImp.get());
}

//---------------------------------------------------------------------------------------- -
//PyBrxBimPly
void makeBrxBimPlyWrapper()
{
    constexpr const std::string_view ctor = "Overloads:\n"
        "- None: Any\n"
        "- material: PyBrxBim.BimMaterial, function: PyBrxBim.MaterialFunction=PyBrxBim.MaterialFunction.eNone, thickness:float=1.0 \n";

    PyDocString DS("BimPly");
    class_<PyBrxBimPly, bases<PyBrxBimObject>>("BimPly")
        .def(init<>())
        .def(init<const PyBrxBimMaterial&, EMaterialFunction, double>(DS.CTOR(ctor)))
        .def("cast", &PyBrxBimPly::cast, DS.SARGS({ "otherObject: PyBrxBim.BimObject" })).staticmethod("cast")
        .def("className", &PyBrxBimPly::className, DS.SARGS()).staticmethod("className")
        ;
}

PyBrxBimPly::PyBrxBimPly()
    : PyBrxBimPly(new BrxBimPly(), true)
{
}

PyBrxBimPly::PyBrxBimPly(const PyBrxBimMaterial& material, EMaterialFunction function /*= eNone*/, double thickness /*= 1.0*/)
    : PyBrxBimPly(new BrxBimPly(*material.impObj(), function, thickness), true)
{
}

PyBrxBimPly::PyBrxBimPly(const BrxBimPly& r)
    : PyBrxBimPly(new BrxBimPly(r), true)
{
}

PyBrxBimPly::PyBrxBimPly(const BrxBimPly* ptr)
    : PyBrxBimObject(ptr)
{
}

PyBrxBimPly::PyBrxBimPly(BrxBimPly* pObject, bool autoDelete)
    : PyBrxBimObject(pObject, autoDelete)
{
}

PyBrxBimPly PyBrxBimPly::cast(const PyBrxBimObject& src)
{
    return PyBrxBimObjectCast<PyBrxBimPly>(src);
}

std::string PyBrxBimPly::className()
{
    return "BimPly";
}

BrxBimPly* PyBrxBimPly::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<BrxBimPly*>(m_pyImp.get());
}

//---------------------------------------------------------------------------------------- -
//PyBrxBimComposition
void makePyBrxBimCompositionWrapper()
{
    constexpr const std::string_view ctor = "Overloads:\n"
        "- None: Any\n"
        "- name: str\n";

    PyDocString DS("BimComposition");
    class_<PyBrxBimComposition, bases<PyBrxBimObject>>("BimComposition")
        .def(init<>())
        .def(init<const std::string&>(DS.CTOR(ctor)))
        .def("cast", &PyBrxBimComposition::cast, DS.SARGS({ "otherObject: PyBrxBim.BimObject" })).staticmethod("cast")
        .def("className", &PyBrxBimComposition::className, DS.SARGS()).staticmethod("className")
        ;
}

PyBrxBimComposition::PyBrxBimComposition()
    : PyBrxBimComposition(new BrxBimComposition(), true)
{
}

PyBrxBimComposition::PyBrxBimComposition(const std::string& name)
    : PyBrxBimComposition(new BrxBimComposition(utf8_to_wstr(name).c_str()), true)
{
}

PyBrxBimComposition::PyBrxBimComposition(const BrxBimComposition& r)
    : PyBrxBimComposition(new BrxBimComposition(r), true)
{
}

PyBrxBimComposition::PyBrxBimComposition(const BrxBimComposition* ptr)
    : PyBrxBimObject(ptr)
{
}

PyBrxBimComposition::PyBrxBimComposition(BrxBimComposition* pObject, bool autoDelete)
    : PyBrxBimObject(pObject, autoDelete)
{
}

PyBrxBimComposition PyBrxBimComposition::cast(const PyBrxBimObject& src)
{
    return PyBrxBimObjectCast<PyBrxBimComposition>(src);
}

std::string PyBrxBimComposition::className()
{
    return "BimComposition";
}

BrxBimComposition* PyBrxBimComposition::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<BrxBimComposition*>(m_pyImp.get());
}


//---------------------------------------------------------------------------------------- -
//PyBrxBimProfile
void makePyBrxBimProfileWrapper()
{
    constexpr const std::string_view ctor = "Overloads:\n"
        "- None: Any\n"
        "- id: PyDb.ObjectId\n";

    PyDocString DS("BimProfile");
    class_<PyBrxBimProfile>("BimProfile")
        .def(init<>())
        .def(init<const PyDbObjectId&>(DS.CTOR(ctor)))
        .def("className", &PyBrxBimProfile::className, DS.SARGS()).staticmethod("className")
        ;
}

PyBrxBimProfile::PyBrxBimProfile()
    : PyBrxBimProfile(new BrxBimProfile(), true)
{
}

PyBrxBimProfile::PyBrxBimProfile(const PyDbObjectId& id)
    : PyBrxBimProfile(new BrxBimProfile(id.m_id), true)
{
}

PyBrxBimProfile::PyBrxBimProfile(const BrxBimProfile& r)
    : PyBrxBimProfile(new BrxBimProfile(r), true)
{
}

PyBrxBimProfile::PyBrxBimProfile(const BrxBimProfile* ptr)
    :PyBrxBimProfile(const_cast<BrxBimProfile*>(ptr), false)
{
}

PyBrxBimProfile::PyBrxBimProfile(BrxBimProfile* pObject, bool autoDelete)
    : m_pyImp(pObject, PySharedObjectDeleter<BrxBimProfile>(autoDelete))
{
}

std::string PyBrxBimProfile::className()
{
    return "BimProfile";
}

BrxBimProfile* PyBrxBimProfile::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<BrxBimProfile*>(m_pyImp.get());
}

//---------------------------------------------------------------------------------------- -
//PyBrxBimLinearGeometry
void makeBrxBimLinearGeometryWrapper()
{
    constexpr const std::string_view ctor = "Overloads:\n"
        "- None: Any\n"
        "- id: PyDb.ObjectId\n";

    PyDocString DS("BimLinearGeometry");
    class_<PyBrxBimLinearGeometry>("BimLinearGeometry")
        .def(init<>())
        .def(init<const PyDbObjectId&>(DS.CTOR(ctor)))
        .def("className", &PyBrxBimLinearGeometry::className, DS.SARGS()).staticmethod("className")
        ;
}

PyBrxBimLinearGeometry::PyBrxBimLinearGeometry()
    : PyBrxBimLinearGeometry(new BrxBimLinearGeometry(), true)
{
}

PyBrxBimLinearGeometry::PyBrxBimLinearGeometry(const PyDbObjectId& id)
    : PyBrxBimLinearGeometry(new BrxBimLinearGeometry(id.m_id), true)
{
}

PyBrxBimLinearGeometry::PyBrxBimLinearGeometry(const BrxBimLinearGeometry& r)
    : PyBrxBimLinearGeometry(new BrxBimLinearGeometry(r), true)
{
}

PyBrxBimLinearGeometry::PyBrxBimLinearGeometry(const BrxBimLinearGeometry* ptr)
    :PyBrxBimLinearGeometry(const_cast<BrxBimLinearGeometry*>(ptr), false)
{
}

PyBrxBimLinearGeometry::PyBrxBimLinearGeometry(BrxBimLinearGeometry* pObject, bool autoDelete)
    : m_pyImp(pObject, PySharedObjectDeleter<BrxBimLinearGeometry>(autoDelete))
{
}

std::string PyBrxBimLinearGeometry::className()
{
    return "BimLinearGeometry";
}

BrxBimLinearGeometry* PyBrxBimLinearGeometry::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<BrxBimLinearGeometry*>(m_pyImp.get());
}

//---------------------------------------------------------------------------------------- -
//PyBrxBimClassification
void makeBrxBimClassificationWrapper()
{
    PyDocString DS("BimClassification");
    class_<PyBrxBimClassification>("BimClassification")
        .def(init<>())
        .def("className", &PyBrxBimClassification::className, DS.SARGS()).staticmethod("className")
        ;
}

PyBrxBimClassification::PyBrxBimClassification()
    : PyBrxBimClassification(new BimClassification(), true)
{
}

PyBrxBimClassification::PyBrxBimClassification(const BimClassification* ptr)
    :PyBrxBimClassification(const_cast<BimClassification*>(ptr), false)
{
}

PyBrxBimClassification::PyBrxBimClassification(BimClassification* pObject, bool autoDelete)
    : m_pyImp(pObject, PySharedObjectDeleter<BimClassification>(autoDelete))
{
}

std::string PyBrxBimClassification::className()
{
    return "BimClassification";
}

BimClassification* PyBrxBimClassification::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<BimClassification*>(m_pyImp.get());
}

//---------------------------------------------------------------------------------------- -
//PyBrxBimNameSpaces
void makeBrxBimNameSpacesWrapper()
{
    PyDocString DS("BimNameSpaces");
    class_<PyBrxBimNameSpaces>("BimNameSpaces")
        .def(init<>())
        .def("className", &PyBrxBimNameSpaces::className, DS.SARGS()).staticmethod("className")
        ;
}

PyBrxBimNameSpaces::PyBrxBimNameSpaces()
    : PyBrxBimNameSpaces(new BimNameSpaces(), true)
{
}

PyBrxBimNameSpaces::PyBrxBimNameSpaces(const BimNameSpaces* ptr)
    :PyBrxBimNameSpaces(const_cast<BimNameSpaces*>(ptr), false)
{
}

PyBrxBimNameSpaces::PyBrxBimNameSpaces(BimNameSpaces* pObject, bool autoDelete)
    : m_pyImp(pObject, PySharedObjectDeleter<BimNameSpaces>(autoDelete))
{
}

std::string PyBrxBimNameSpaces::className()
{
    return "BimNameSpaces";
}

BimNameSpaces* PyBrxBimNameSpaces::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<BimNameSpaces*>(m_pyImp.get());
}

//---------------------------------------------------------------------------------------- -
//PyBrxBimPropertyInfo
void makePyBrxBimPropertyInfoWrapper()
{
    PyDocString DS("BimPropertyInfo");
    class_<PyBrxBimPropertyInfo>("BimPropertyInfo")
        .def(init<>())
        .def("className", &PyBrxBimPropertyInfo::className, DS.SARGS()).staticmethod("className")
        ;
}

PyBrxBimPropertyInfo::PyBrxBimPropertyInfo()
    : PyBrxBimPropertyInfo(new BimPropertyInfo(), true)
{
}

PyBrxBimPropertyInfo::PyBrxBimPropertyInfo(const BimPropertyInfo* ptr)
    :PyBrxBimPropertyInfo(const_cast<BimPropertyInfo*>(ptr), false)
{
}

PyBrxBimPropertyInfo::PyBrxBimPropertyInfo(BimPropertyInfo* pObject, bool autoDelete)
    : m_pyImp(pObject, PySharedObjectDeleter<BimPropertyInfo>(autoDelete))
{
}

std::string PyBrxBimPropertyInfo::className()
{
    return "BimPropertyInfo";
}

BimPropertyInfo* PyBrxBimPropertyInfo::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<BimPropertyInfo*>(m_pyImp.get());
}

//---------------------------------------------------------------------------------------- -
//BrxBimAttributeSet
void makePyBrxBimAttributeSetWrapper()
{
    PyDocString DS("BrxBimAttributeSet");
    class_<PyBrxBimAttributeSet>("BrxBimAttributeSet")
        .def(init<>())
        .def("className", &PyBrxBimAttributeSet::className, DS.SARGS()).staticmethod("className")
        ;
}

PyBrxBimAttributeSet::PyBrxBimAttributeSet()
    : PyBrxBimAttributeSet(new BrxBimAttributeSet(), true)
{
}

PyBrxBimAttributeSet::PyBrxBimAttributeSet(const BrxBimAttributeSet* ptr)
    :PyBrxBimAttributeSet(const_cast<BrxBimAttributeSet*>(ptr), false)
{
}

PyBrxBimAttributeSet::PyBrxBimAttributeSet(BrxBimAttributeSet* pObject, bool autoDelete)
    : m_pyImp(pObject, PySharedObjectDeleter<BrxBimAttributeSet>(autoDelete))
{
}

std::string PyBrxBimAttributeSet::className()
{
    return "BrxBimAttributeSet";
}

BrxBimAttributeSet* PyBrxBimAttributeSet::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<BrxBimAttributeSet*>(m_pyImp.get());
}

//---------------------------------------------------------------------------------------- -
//BrxBimDialogs
void makePyBrxBimDialogsWrapper()
{
    PyDocString DS("BrxBimDialogs");
    class_<PyBrxBimDialogs>("BrxBimDialogs")
        .def(init<>())
        .def("className", &PyBrxBimDialogs::className, DS.SARGS()).staticmethod("className")
        ;
}

PyBrxBimDialogs::PyBrxBimDialogs()
    : PyBrxBimDialogs(new BrxBimDialogs(), true)
{
}

PyBrxBimDialogs::PyBrxBimDialogs(const BrxBimDialogs* ptr)
    :PyBrxBimDialogs(const_cast<BrxBimDialogs*>(ptr), false)
{
}

PyBrxBimDialogs::PyBrxBimDialogs(BrxBimDialogs* pObject, bool autoDelete)
    : m_pyImp(pObject, PySharedObjectDeleter<BrxBimDialogs>(autoDelete))
{
}

std::string PyBrxBimDialogs::className()
{
    return "BrxBimDialogs";
}

BrxBimDialogs* PyBrxBimDialogs::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<BrxBimDialogs*>(m_pyImp.get());
}

#endif//BRXAPP
