#include "stdafx.h"
#include "PyBrxBimObject.h"

#ifdef BRXAPP
#include "PyDbDatabase.h"
#include "PyDbObjectId.h"
#include "AnchorFeature.h"
#include "Blockify.h"
#include "IfcExportReactor.h"
#include "IfcImportReactor.h"
#include "PyGePlane.h"
#include "PyDbEval.h"

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
#if defined(_BRXTARGET240)
    throw PyNotimplementedByHost();
#else
    BrxBimPolicies::setPolicy(option, enable);
#endif
}

bool PyBrxBimPolicies::getPolicy(BrxBimPolicies::EPolicyOptions option)
{
#if defined(_BRXTARGET240)
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
        .def("typeDesc", &PyBrxBimSpatialLocation::typeDesc, DS.ARGS())
        .def("typeName", &PyBrxBimSpatialLocation::typeName, DS.ARGS())
        .def("isNull", &PyBrxBimSpatialLocation::isNull, DS.ARGS())
        .def("setNull", &PyBrxBimSpatialLocation::setNull, DS.ARGS())
        .def("name", &PyBrxBimSpatialLocation::name, DS.ARGS())
        .def("setName", &PyBrxBimSpatialLocation::setName, DS.ARGS({ "name: str" }))
        .def("description", &PyBrxBimSpatialLocation::description, DS.ARGS())
        .def("setDescription", &PyBrxBimSpatialLocation::setDescription, DS.ARGS({ "desc: str" }))
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

BimApi::BimObjectType PyBrxBimSpatialLocation::typeDesc() const
{
    return impObj()->typeDesc();
}

std::string PyBrxBimSpatialLocation::typeName() const
{
    return wstr_to_utf8(impObj()->typeName());
}

bool PyBrxBimSpatialLocation::isNull() const
{
    return impObj()->isNull();
}

void PyBrxBimSpatialLocation::setNull()
{
    impObj()->setNull();
}

std::string PyBrxBimSpatialLocation::name() const
{
    return wstr_to_utf8(impObj()->name());
}

void PyBrxBimSpatialLocation::setName(const std::string& szNewName) const
{
    PyThrowBadBim(impObj()->setName(utf8_to_wstr(szNewName).c_str()));
}

std::string PyBrxBimSpatialLocation::description() const
{
    return wstr_to_utf8(impObj()->description());
}

void PyBrxBimSpatialLocation::setDescription(const std::string& szInfo) const
{
    PyThrowBadBim(impObj()->setDescription(utf8_to_wstr(szInfo).c_str()));
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
void makeBrxBimStoryWrapper()
{
    PyDocString DS("BimStory");
    class_<PyBrxBimStory, bases<PyBrxBimSpatialLocation>>("BimStory")
        .def(init<>(DS.ARGS()))
        .def("isNull", &PyBrxBimStory::isNull, DS.ARGS())
        .def("setNull", &PyBrxBimStory::setNull, DS.ARGS())
        .def("name", &PyBrxBimStory::name, DS.ARGS())
        .def("longName", &PyBrxBimStory::longName, DS.ARGS())
        .def("setName", &PyBrxBimStory::setName, DS.ARGS({ "name: str" }))
        .def("setLongName", &PyBrxBimStory::setLongName, DS.ARGS({ "name: str" }))
        .def("description", &PyBrxBimStory::description, DS.ARGS())
        .def("setDescription", &PyBrxBimStory::setDescription, DS.ARGS({ "desc: str" }))
        .def("assignedObjects", &PyBrxBimStory::assignedObjects, DS.ARGS({ "db: PyDb.Database" }))
        .def("assignToEntity", &PyBrxBimStory::assignToEntity, DS.ARGS({ "id: PyDb.ObjectId" }))
        .def("createStory", &PyBrxBimStory::createStory, DS.ARGS({ "szName: str", "building: PyBrxBim.BimBuilding" }))
        .def("deleteStory", &PyBrxBimStory::deleteStory, DS.ARGS())
        .def("elevation", &PyBrxBimStory::elevation, DS.ARGS())
        .def("setElevation", &PyBrxBimStory::setElevation, DS.ARGS({ "val: float" }))
        .def("getBuilding", &PyBrxBimStory::getBuilding, DS.ARGS())
        .def("createNewStory", &PyBrxBimStory::createNewStory, DS.SARGS({ "db: PyDb.Database","buildingName: str","storyName: str" })).staticmethod("createNewStory")
        .def("deleteStoryFromDatabase", &PyBrxBimStory::deleteStoryFromDatabase, DS.SARGS({ "db: PyDb.Database","buildingName: str","storyName: str" })).staticmethod("deleteStoryFromDatabase")
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

bool PyBrxBimStory::isNull() const
{
    return impObj()->isNull();
}

void PyBrxBimStory::setNull()
{
    return impObj()->setNull();
}

std::string PyBrxBimStory::name() const
{
    return wstr_to_utf8(impObj()->name());
}

std::string PyBrxBimStory::longName() const
{
    return wstr_to_utf8(impObj()->longName());
}

void PyBrxBimStory::setName(const std::string& szNewName) const
{
    PyThrowBadBim(impObj()->setName(utf8_to_wstr(szNewName).c_str()));
}

void PyBrxBimStory::setLongName(const std::string& szLongName) const
{
    PyThrowBadBim(impObj()->setLongName(utf8_to_wstr(szLongName).c_str()));
}

std::string PyBrxBimStory::description() const
{
    return wstr_to_utf8(impObj()->description());
}

void PyBrxBimStory::setDescription(const std::string& szInfo) const
{
    PyThrowBadBim(impObj()->setDescription(utf8_to_wstr(szInfo).c_str()));
}

boost::python::list PyBrxBimStory::assignedObjects(const PyDbDatabase& database) const
{
    AcDbObjectIdArray ids;
    PyThrowBadBim(impObj()->assignedObjects(ids, database.impObj()));
    return ObjectIdArrayToPyList(ids);
}

void PyBrxBimStory::assignToEntity(const PyDbObjectId& id) const
{
    PyThrowBadBim(impObj()->assignToEntity(id.m_id));
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
    PyThrowBadBim(BrxBimStory::assignedStory(obj, id.m_id));
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
        .def(init<>(DS.ARGS()))
        .def("typeDesc", &PyBrxBimBuilding::typeDesc, DS.ARGS())
        .def("typeName", &PyBrxBimBuilding::typeName, DS.ARGS())
        .def("createBuilding", &PyBrxBimBuilding::createBuilding, DS.ARGS({ "name: str", "db: PyDb.Database" }))
        .def("createBuilding", &PyBrxBimBuilding::deleteBuilding, DS.ARGS({ "db: PyDb.Database" }))
        .def("isNull", &PyBrxBimBuilding::isNull, DS.ARGS())
        .def("setNull", &PyBrxBimBuilding::setNull, DS.ARGS())
        .def("createStory", &PyBrxBimBuilding::createBuilding, DS.ARGS({ "name: str" }))
        .def("deleteStoryString", &PyBrxBimBuilding::deleteStory1, DS.ARGS({ "story: str" }))
        .def("deleteStoryObject", &PyBrxBimBuilding::deleteStory2, DS.ARGS({ "story: PyBrxBim.BimStory" }))
        .def("name", &PyBrxBimBuilding::name, DS.ARGS())
        .def("longName", &PyBrxBimBuilding::longName, DS.ARGS())
        .def("setName", &PyBrxBimBuilding::setName, DS.ARGS({ "name: str" }))
        .def("setLongName", &PyBrxBimBuilding::setLongName, DS.ARGS({ "name: str" }))
        .def("description", &PyBrxBimBuilding::description, DS.ARGS())
        .def("setDescription", &PyBrxBimBuilding::setDescription, DS.ARGS({ "desc: str" }))
        .def("getStory", &PyBrxBimBuilding::getStory, DS.ARGS({ "story: str" }))
        .def("allObjectStories", &PyBrxBimBuilding::allObjectStories, DS.ARGS())
        .def("allStringStories", &PyBrxBimBuilding::allStringStories, DS.ARGS())
        .def("assignedObjects", &PyBrxBimBuilding::assignedObjects, DS.ARGS({ "db: PyDb.Database" }))
        .def("assignToEntity", &PyBrxBimBuilding::assignToEntity, DS.ARGS({ "id: PyDb.ObjectId" }))
        .def("createNewBuilding", &PyBrxBimBuilding::createNewBuilding, DS.SARGS({ "db: PyDb.Database", "name: str" })).staticmethod("createNewBuilding")
        .def("deleteBuildingFromDb", &PyBrxBimBuilding::deleteBuildingFromDb, DS.SARGS({ "db: PyDb.Database", "name: str" })).staticmethod("deleteBuildingFromDb")
        .def("assignedBuilding", &PyBrxBimBuilding::assignedBuilding, DS.SARGS({ "building: PyBrxBim.BimBuilding", "id: PyDb.ObjectId" })).staticmethod("assignedBuilding")
        .def("getBuilding", &PyBrxBimBuilding::getBuilding, DS.SARGS({ "db: PyDb.Database", "name: str" })).staticmethod("getBuilding")
        .def("allObjectBuildings", &PyBrxBimBuilding::allObjectBuildings, DS.SARGS({ "db: PyDb.Database" })).staticmethod("allObjectBuildings")
        .def("allStringBuildings", &PyBrxBimBuilding::allStringBuildings, DS.SARGS({ "db: PyDb.Database" })).staticmethod("allStringBuildings")
        .def("allObjectStoriesFromDb", &PyBrxBimBuilding::allObjectStoriesFromDb1, DS.ARGS({ "db: PyDb.Database" }))
        //TODO alter argument type
        .def("allObjectStoriesFromDb", &PyBrxBimBuilding::allObjectStoriesFromDb2, DS.SARGS({ "db: PyDb.Database","building: str = None" })).staticmethod("allObjectStoriesFromDb")
        .def("allStringStoriesFromDb", &PyBrxBimBuilding::allStringStoriesFromDb1, DS.ARGS({ "db: PyDb.Database" }))
        .def("allStringStoriesFromDb", &PyBrxBimBuilding::allStringStoriesFromDb2, DS.SARGS({ "db: PyDb.Database","building: str = None" })).staticmethod("allStringStoriesFromDb")
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

BimApi::BimObjectType PyBrxBimBuilding::typeDesc() const
{
    return impObj()->typeDesc();
}

std::string PyBrxBimBuilding::typeName() const
{
    return wstr_to_utf8(impObj()->typeName());
}

void PyBrxBimBuilding::createBuilding(const std::string& szName, const PyDbDatabase& database)
{
    PyThrowBadBim(impObj()->createBuilding(utf8_to_wstr(szName).c_str(), database.impObj()));
}

PyBrxBimBuilding PyBrxBimBuilding::createNewBuilding(const PyDbDatabase& database, const std::string& name)
{
    BrxBimBuilding building;
    PyThrowBadBim(BrxBimBuilding::createBuilding(building, database.impObj(), utf8_to_wstr(name).c_str()));
    return PyBrxBimBuilding{ building };
}

void PyBrxBimBuilding::deleteBuildingFromDb(const PyDbDatabase& database, const std::string& buildingName)
{
    PyThrowBadBim(BrxBimBuilding::deleteBuilding(database.impObj(), utf8_to_wstr(buildingName).c_str()));
}

void PyBrxBimBuilding::assignedBuilding(PyBrxBimBuilding& building, const PyDbObjectId& id)
{
    PyThrowBadBim(BrxBimBuilding::assignedBuilding(*building.impObj(), id.m_id));
}

PyBrxBimBuilding PyBrxBimBuilding::getBuilding(const PyDbDatabase& database, const std::string& buildingName)
{
    BrxBimBuilding building;
    PyThrowBadBim(BrxBimBuilding::getBuilding(building, database.impObj(), utf8_to_wstr(buildingName).c_str()));
    return PyBrxBimBuilding{ building };
}

boost::python::list PyBrxBimBuilding::allObjectBuildings(const PyDbDatabase& database)
{
    BimApi::BimBuildings buildings;
    PyThrowBadBim(BrxBimBuilding::allBuildings(buildings, database.impObj()));
    PyAutoLockGIL lock;
    boost::python::list pylist;
    for (const auto& building : buildings)
        pylist.append(BrxBimBuilding{ building });
    return pylist;
}

boost::python::list PyBrxBimBuilding::allStringBuildings(const PyDbDatabase& database)
{
    AcStringArray buildings;
    PyThrowBadBim(BrxBimBuilding::allBuildings(buildings, database.impObj()));
    PyAutoLockGIL lock;
    boost::python::list pylist;
    for (const auto& building : buildings)
        pylist.append(wstr_to_utf8(building));
    return pylist;
}

boost::python::list PyBrxBimBuilding::allObjectStoriesFromDb1(const PyDbDatabase& database)
{
    BimApi::BimStories stories;
    PyThrowBadBim(BrxBimBuilding::allStories(stories, database.impObj()));
    PyAutoLockGIL lock;
    boost::python::list pylist;
    for (const auto& story : stories)
        pylist.append(PyBrxBimStory{ story });
    return pylist;
}

boost::python::list PyBrxBimBuilding::allObjectStoriesFromDb2(const PyDbDatabase& database, const std::string& building)
{
    BimApi::BimStories stories;
    PyThrowBadBim(BrxBimBuilding::allStories(stories, database.impObj(), utf8_to_wstr(building).c_str()));
    PyAutoLockGIL lock;
    boost::python::list pylist;
    for (const auto& story : stories)
        pylist.append(PyBrxBimStory{ story });
    return pylist;
}

boost::python::list PyBrxBimBuilding::allStringStoriesFromDb1(const PyDbDatabase& database)
{

    BimApi::BimStories stories;
    PyThrowBadBim(BrxBimBuilding::allStories(stories, database.impObj()));
    PyAutoLockGIL lock;
    boost::python::list pylist;
    for (const auto& story : stories)
        pylist.append(PyBrxBimStory{ story });
    return pylist;
}

boost::python::list PyBrxBimBuilding::allStringStoriesFromDb2(const PyDbDatabase& database, const std::string& building)
{
    AcStringArray stories;
    PyThrowBadBim(BrxBimBuilding::allStories(stories, database.impObj(), utf8_to_wstr(building).c_str()));
    PyAutoLockGIL lock;
    boost::python::list pylist;
    for (const auto& story : stories)
        pylist.append(wstr_to_utf8(story));
    return pylist;
}

void PyBrxBimBuilding::deleteBuilding(const PyDbDatabase& database)
{
    PyThrowBadBim(impObj()->deleteBuilding(database.impObj()));
}

bool PyBrxBimBuilding::isNull() const
{
    return impObj()->isNull();
}

void PyBrxBimBuilding::setNull()
{
    impObj()->setNull();
}

PyBrxBimStory PyBrxBimBuilding::createStory(const std::string& storyName) const
{
    BrxBimStory story;
    PyThrowBadBim(impObj()->createStory(story, utf8_to_wstr(storyName).c_str()));
    return PyBrxBimStory{ story };
}

void PyBrxBimBuilding::deleteStory1(const std::string& storyName) const
{
    PyThrowBadBim(impObj()->deleteStory(utf8_to_wstr(storyName).c_str()));
}

void PyBrxBimBuilding::deleteStory2(PyBrxBimStory& story) const
{
    PyThrowBadBim(impObj()->deleteStory(*story.impObj()));
}

std::string PyBrxBimBuilding::name() const
{
    return wstr_to_utf8(impObj()->name());
}

std::string PyBrxBimBuilding::longName() const
{
    return wstr_to_utf8(impObj()->longName());
}

void PyBrxBimBuilding::setName(const std::string& szNewName) const
{
    PyThrowBadBim(impObj()->setName(utf8_to_wstr(szNewName).c_str()));
}

void PyBrxBimBuilding::setLongName(const std::string& szLongName) const
{
    PyThrowBadBim(impObj()->setLongName(utf8_to_wstr(szLongName).c_str()));
}

std::string PyBrxBimBuilding::description() const
{
    return wstr_to_utf8(impObj()->description());
}

void PyBrxBimBuilding::setDescription(const std::string& szInfo) const
{
    PyThrowBadBim(impObj()->setDescription(utf8_to_wstr(szInfo).c_str()));
}

PyBrxBimStory PyBrxBimBuilding::getStory(const std::string& storyName) const
{
    BrxBimStory story;
    PyThrowBadBim(impObj()->getStory(story, utf8_to_wstr(storyName).c_str()));
    return PyBrxBimStory{ story };
}

boost::python::list PyBrxBimBuilding::allObjectStories() const
{
    BimApi::BimStories stories;
    PyThrowBadBim(impObj()->allStories(stories));
    PyAutoLockGIL lock;
    boost::python::list pylist;
    for (const auto& story : stories)
        pylist.append(PyBrxBimStory{ story });
    return pylist;
}

boost::python::list PyBrxBimBuilding::allStringStories() const
{
    AcStringArray stories;
    PyThrowBadBim(impObj()->allStories(stories));
    PyAutoLockGIL lock;
    boost::python::list pylist;
    for (const auto& story : stories)
        pylist.append(wstr_to_utf8(story));
    return pylist;
}

boost::python::list PyBrxBimBuilding::assignedObjects(const PyDbDatabase& database) const
{
    AcDbObjectIdArray ids;
    PyThrowBadBim(impObj()->assignedObjects(ids, database.impObj()));
    return ObjectIdArrayToPyList(ids);
}

void PyBrxBimBuilding::assignToEntity(const PyDbObjectId& id) const
{
    PyThrowBadBim(impObj()->assignToEntity(id.m_id));
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

    constexpr const std::string_view getAllRoomsOverLoads = "Overloads:\n"
        "- None: Any\n"
        "- db: PyDb.Database\n"
        "- val: PyBrxBim.BimStory\n"
        "- val: PyBrxBim.BimBuilding\n"
        "- val: PyBrxBim.BimStory, db: PyDb.Database\n"
        "- val: PyBrxBim.BimBuilding, db: PyDb.Database\n";

    PyDocString DS("BimRoom");
    class_<PyBrxBimRoom, bases<PyBrxBimObject>>("BimRoom")
        .def(init<>())
        .def(init<const PyDbObjectId&>(DS.CTOR(ctor)))

        .def("typeDesc", &PyBrxBimRoom::typeDesc, DS.ARGS())
        .def("typeName", &PyBrxBimRoom::typeName, DS.ARGS())
        .def("isRoomValid", &PyBrxBimRoom::isRoomValid, DS.ARGS())
        .def("createAssociativeRoom", &PyBrxBimRoom::createAssociativeRoom, DS.ARGS({ "insidePoint: PyGe.Point3d","basePlane: PyGe.Plane" }))
        .def("createNonAssociativeRoom", &PyBrxBimRoom::createNonAssociativeRoom, DS.ARGS({ "id: PyDb.ObjectId" }))
        .def("updateAssociativeRoom", &PyBrxBimRoom::updateAssociativeRoom, DS.ARGS())
        .def("isAssociativeRoom", &PyBrxBimRoom::isAssociativeRoom, DS.ARGS())
        .def("getBoundingElements", &PyBrxBimRoom::getBoundingElements, DS.ARGS())
        .def("getOpenings", &PyBrxBimRoom::getOpenings, DS.ARGS())
        .def("getRoomEntity", &PyBrxBimRoom::getRoomEntity, DS.ARGS())
        .def("getId", &PyBrxBimRoom::getId, DS.ARGS())
        .def("setId", &PyBrxBimRoom::setId, DS.ARGS({ "id: PyDb.ObjectId" }))
        .def("isNull", &PyBrxBimRoom::isNull, DS.ARGS())
        .def("setNull", &PyBrxBimRoom::setNull, DS.ARGS())
        .def("roomIdent", &PyBrxBimRoom::roomIdent, DS.ARGS())
        .def("name", &PyBrxBimRoom::name, DS.ARGS())
        .def("roomName", &PyBrxBimRoom::roomName, DS.ARGS())
        .def("roomNumber", &PyBrxBimRoom::roomNumber, DS.ARGS())
        .def("setName", &PyBrxBimRoom::setName, DS.ARGS({ "val: str" }))
        .def("setRoomName", &PyBrxBimRoom::setRoomName, DS.ARGS({ "val: str" }))
        .def("setRoomNumber", &PyBrxBimRoom::setRoomNumber, DS.ARGS({ "val: str" }))
        .def("description", &PyBrxBimRoom::description, DS.ARGS())
        .def("setDescription", &PyBrxBimRoom::setDescription, DS.ARGS({ "val: str" }))
        .def("roomArea", &PyBrxBimRoom::roomArea, DS.ARGS())
        .def("getRoomRepresentation", &PyBrxBimRoom::getRoomRepresentation, DS.ARGS())
        .def("setRoomRepresentation", &PyBrxBimRoom::setRoomRepresentation, DS.ARGS({ "val: str" }))
        .def("getRoomDepartment", &PyBrxBimRoom::getRoomDepartment, DS.ARGS())
        .def("setRoomDepartment", &PyBrxBimRoom::setRoomDepartment, DS.ARGS({ "val: str" }))
        .def("assignToStory", &PyBrxBimRoom::assignToStory, DS.ARGS({ "val: PyBrxBim.BimStory" }))
        .def("assignToBuilding", &PyBrxBimRoom::assignToBuilding, DS.ARGS({ "val: PyBrxBim.BimBuilding" }))
        .def("getAssignedLocation", &PyBrxBimRoom::getAssignedLocation, DS.ARGS())
        .def("getAssignedStory", &PyBrxBimRoom::getAssignedStory, DS.ARGS())
        .def("getAssignedBuilding", &PyBrxBimRoom::getAssignedBuilding, DS.ARGS())
        .def("unassignLocation", &PyBrxBimRoom::unassignLocation, DS.ARGS())
        //static
        .def("isRoomValidS", &PyBrxBimRoom::isRoomValidS, DS.SARGS({ "id: PyDb.ObjectId" })).staticmethod("isRoomValidS")
        .def("buildAssociativeRoomS", &PyBrxBimRoom::buildAssociativeRoomS, DS.SARGS({ "insidePoint: PyGe.Point3d","basePlane: PyGe.Plane" })).staticmethod("buildAssociativeRoomS")
        .def("buildNonAssociativeRoomS", &PyBrxBimRoom::buildNonAssociativeRoomS, DS.SARGS({ "id: PyDb.ObjectId" })).staticmethod("buildNonAssociativeRoomS")
        .def("assignToStoryS", &PyBrxBimRoom::assignToStoryS, DS.SARGS({ "id: PyDb.ObjectId","val: PyBrxBim.BimStory" })).staticmethod("assignToStoryS")
        .def("assignToBuildingS", &PyBrxBimRoom::assignToBuildingS, DS.SARGS({ "id: PyDb.ObjectId", "val: PyBrxBim.BimBuilding" })).staticmethod("assignToBuildingS")
        .def("getAssignedLocationS", &PyBrxBimRoom::getAssignedLocationS, DS.SARGS({ "id: PyDb.ObjectId" })).staticmethod("getAssignedLocationS")
        .def("getAssignedStoryS", &PyBrxBimRoom::getAssignedStoryS, DS.SARGS({ "id: PyDb.ObjectId" })).staticmethod("getAssignedStoryS")
        .def("getAssignedBuildingS", &PyBrxBimRoom::getAssignedBuildingS, DS.SARGS({ "id: PyDb.ObjectId" })).staticmethod("getAssignedBuildingS")
        .def("unassignLocationS", &PyBrxBimRoom::unassignLocationS, DS.SARGS({ "id: PyDb.ObjectId" })).staticmethod("unassignLocationS")
        .def("getAllRoomsS", &PyBrxBimRoom::getAllRooms1)
        .def("getAllRoomsS", &PyBrxBimRoom::getAllRooms2)
        .def("getAllRoomsS", &PyBrxBimRoom::getAllRooms3)
        .def("getAllRoomsS", &PyBrxBimRoom::getAllRooms4)
        .def("getAllRoomsS", &PyBrxBimRoom::getAllRooms5)
        .def("getAllRoomsS", &PyBrxBimRoom::getAllRooms6, DS.SOVRL(getAllRoomsOverLoads)).staticmethod("getAllRoomsS")
        .def("isAssociativeRoomS", &PyBrxBimRoom::isAssociativeRoomS, DS.SARGS({ "id: PyDb.ObjectId" })).staticmethod("isAssociativeRoomS")
        .def("updateAssociativeRoomS", &PyBrxBimRoom::updateAssociativeRoomS, DS.SARGS({ "id: PyDb.ObjectId" })).staticmethod("updateAssociativeRoomS")
        .def("getBoundingElementsS", &PyBrxBimRoom::getBoundingElementsS, DS.SARGS({ "id: PyDb.ObjectId" })).staticmethod("getBoundingElementsS")
        .def("getOpeningsS", &PyBrxBimRoom::getOpeningsS, DS.SARGS({ "id: PyDb.ObjectId" })).staticmethod("getOpeningsS")
        .def("getRoomEntityS", &PyBrxBimRoom::getRoomEntityS, DS.SARGS({ "val: PyBrxBim.BimRoom" })).staticmethod("getRoomEntityS")
        .def("roomIdentS", &PyBrxBimRoom::roomIdentS, DS.SARGS({ "id: PyDb.ObjectId" })).staticmethod("roomIdentS")
        .def("roomNameS", &PyBrxBimRoom::roomNameS, DS.SARGS({ "id: PyDb.ObjectId" })).staticmethod("roomNameS")
        .def("setRoomNameS", &PyBrxBimRoom::setRoomNameS, DS.SARGS({ "id: PyDb.ObjectId","val: str" })).staticmethod("setRoomNameS")
        .def("roomNumberS", &PyBrxBimRoom::roomNumberS, DS.SARGS({ "id: PyDb.ObjectId" })).staticmethod("roomNumberS")
        .def("setRoomNumberS", &PyBrxBimRoom::setRoomNumberS, DS.SARGS({ "id: PyDb.ObjectId","val: str" })).staticmethod("setRoomNumberS")
        .def("descriptionS", &PyBrxBimRoom::descriptionS, DS.SARGS({ "id: PyDb.ObjectId" })).staticmethod("descriptionS")
        .def("setDescriptionS", &PyBrxBimRoom::setDescriptionS, DS.SARGS({ "id: PyDb.ObjectId","val: str" })).staticmethod("setDescriptionS")
        .def("roomAreaS", &PyBrxBimRoom::roomAreaS, DS.SARGS({ "id: PyDb.ObjectId" })).staticmethod("roomAreaS")
        .def("getRoomRepresentationS", &PyBrxBimRoom::getRoomRepresentationS, DS.SARGS({ "id: PyDb.ObjectId" })).staticmethod("getRoomRepresentationS")
        .def("setRoomRepresentationS", &PyBrxBimRoom::setRoomRepresentationS, DS.SARGS({ "id: PyDb.ObjectId","val: str" })).staticmethod("setRoomRepresentationS")
        .def("getRoomDepartmentS", &PyBrxBimRoom::getRoomDepartmentS, DS.SARGS({ "id: PyDb.ObjectId" })).staticmethod("getRoomDepartmentS")
        .def("setRoomDepartmentS", &PyBrxBimRoom::setRoomDepartmentS, DS.SARGS({ "id: PyDb.ObjectId","val: str" })).staticmethod("setRoomDepartmentS")
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

BimApi::BimObjectType PyBrxBimRoom::typeDesc() const
{
    return impObj()->typeDesc();
}

std::string PyBrxBimRoom::typeName() const
{
    return wstr_to_utf8(impObj()->typeName());
}

bool PyBrxBimRoom::isRoomValid() const
{
    return impObj()->isRoomValid();
}

PyDbObjectId PyBrxBimRoom::createAssociativeRoom(const AcGePoint3d& insidePoint, const PyGePlane& basePlane)
{
    return PyDbObjectId{ impObj()->createAssociativeRoom(insidePoint, *basePlane.impObj()) };
}

PyDbObjectId PyBrxBimRoom::createNonAssociativeRoom(const PyDbObjectId& entityId)
{
    return PyDbObjectId{ impObj()->createNonAssociativeRoom(entityId.m_id) };
}

void PyBrxBimRoom::updateAssociativeRoom()
{
    PyThrowBadBim(impObj()->updateAssociativeRoom());
}

bool PyBrxBimRoom::isAssociativeRoom() const
{
    return impObj()->isAssociativeRoom();
}

boost::python::list PyBrxBimRoom::getBoundingElements() const
{
    AcDbObjectIdArray ids;
    PyThrowBadBim(impObj()->getBoundingElements(ids));
    return ObjectIdArrayToPyList(ids);
}


boost::python::list PyBrxBimRoom::getOpenings() const
{
    AcDbObjectIdArray ids;
    PyThrowBadBim(impObj()->getOpenings(ids));
    return ObjectIdArrayToPyList(ids);
}

PyDbObjectId PyBrxBimRoom::getRoomEntity() const
{
    PyDbObjectId id;
    PyThrowBadBim(impObj()->getRoomEntity(id.m_id));
    return id;
}

PyDbObjectId PyBrxBimRoom::getId() const
{
    return PyDbObjectId{ impObj()->getId() };
}

void PyBrxBimRoom::setId(const PyDbObjectId& id)
{
    PyThrowBadBim(impObj()->setId(id.m_id));
}

bool PyBrxBimRoom::isNull() const
{
    return impObj()->isNull();
}

void PyBrxBimRoom::setNull()
{
    impObj()->setNull();
}

std::string PyBrxBimRoom::roomIdent() const
{
    return wstr_to_utf8(impObj()->roomIdent());
}

std::string PyBrxBimRoom::name() const
{
    return wstr_to_utf8(impObj()->name());
}

std::string PyBrxBimRoom::roomName() const
{
    return wstr_to_utf8(impObj()->roomName());
}

std::string PyBrxBimRoom::roomNumber() const
{
    return wstr_to_utf8(impObj()->roomNumber());
}

void PyBrxBimRoom::setName(const std::string& szNewName) const
{
    PyThrowBadBim(impObj()->setName(utf8_to_wstr(szNewName).c_str()));
}

void PyBrxBimRoom::setRoomName(const std::string& szNewName) const
{
    PyThrowBadBim(impObj()->setRoomName(utf8_to_wstr(szNewName).c_str()));
}

void PyBrxBimRoom::setRoomNumber(const std::string& szNewNumber) const
{
    PyThrowBadBim(impObj()->setRoomNumber(utf8_to_wstr(szNewNumber).c_str()));
}

std::string PyBrxBimRoom::description() const
{
    return wstr_to_utf8(impObj()->description());
}

void PyBrxBimRoom::setDescription(const std::string& szInfo) const
{
    PyThrowBadBim(impObj()->setDescription(utf8_to_wstr(szInfo).c_str()));
}

double PyBrxBimRoom::roomArea() const
{
    double area = 0.0;
    PyThrowBadBim(impObj()->roomArea(area));
    return area;
}

std::string PyBrxBimRoom::getRoomRepresentation() const
{
    AcString rval;
    PyThrowBadBim(impObj()->getRoomRepresentation(rval));
    return wstr_to_utf8(rval);
}

void PyBrxBimRoom::setRoomRepresentation(const std::string& representation)
{
    PyThrowBadBim(impObj()->setRoomRepresentation(utf8_to_wstr(representation).c_str()));
}

std::string PyBrxBimRoom::getRoomDepartment() const
{
    AcString rval;
    PyThrowBadBim(impObj()->getRoomDepartment(rval));
    return wstr_to_utf8(rval);
}

void PyBrxBimRoom::setRoomDepartment(const std::string& department)
{
    PyThrowBadBim(impObj()->setRoomRepresentation(utf8_to_wstr(department).c_str()));
}

void PyBrxBimRoom::assignToStory(const PyBrxBimStory& story)
{
    PyThrowBadBim(impObj()->assignToStory(*story.impObj()));
}

void PyBrxBimRoom::assignToBuilding(const PyBrxBimBuilding& building)
{
    PyThrowBadBim(impObj()->assignToBuilding(*building.impObj()));
}

PyBrxBimSpatialLocation PyBrxBimRoom::getAssignedLocation() const
{
    BrxBimSpatialLocation rval;
    PyThrowBadBim(impObj()->getAssignedLocation(rval));
    return PyBrxBimSpatialLocation{ rval };
}

PyBrxBimStory PyBrxBimRoom::getAssignedStory() const
{
    BrxBimStory rval;
    PyThrowBadBim(impObj()->getAssignedStory(rval));
    return PyBrxBimStory{ rval };
}

PyBrxBimBuilding PyBrxBimRoom::getAssignedBuilding() const
{
    BrxBimBuilding rval;
    PyThrowBadBim(impObj()->getAssignedBuilding(rval));
    return PyBrxBimBuilding{ rval };
}

void PyBrxBimRoom::unassignLocation()
{
    PyThrowBadBim(impObj()->unassignLocation());
}

bool PyBrxBimRoom::isRoomValidS(const PyDbObjectId& id)
{
    return BrxBimRoom::isRoomValid(id.m_id);
}

PyDbObjectId PyBrxBimRoom::buildAssociativeRoomS(const AcGePoint3d& insidePoint, const PyGePlane& basePlane)
{
    return PyDbObjectId{ BrxBimRoom::buildAssociativeRoom(insidePoint,*basePlane.impObj()) };
}

PyDbObjectId PyBrxBimRoom::buildNonAssociativeRoomS(const PyDbObjectId& id)
{
    return PyDbObjectId{ BrxBimRoom::buildNonAssociativeRoom(id.m_id) };
}

void PyBrxBimRoom::assignToStoryS(const PyDbObjectId& id, const PyBrxBimStory& story)
{
    PyThrowBadBim(BrxBimRoom::assignToStory(id.m_id, *story.impObj()));
}

void PyBrxBimRoom::assignToBuildingS(const PyDbObjectId& id, const PyBrxBimBuilding& building)
{
    PyThrowBadBim(BrxBimRoom::assignToBuilding(id.m_id, *building.impObj()));
}

PyBrxBimSpatialLocation PyBrxBimRoom::getAssignedLocationS(const PyDbObjectId& id)
{
    BrxBimSpatialLocation rval;
    PyThrowBadBim(BrxBimRoom::getAssignedLocation(id.m_id, rval));
    return PyBrxBimSpatialLocation{ rval };
}

PyBrxBimStory PyBrxBimRoom::getAssignedStoryS(const PyDbObjectId& id)
{
    BrxBimStory rval;
    PyThrowBadBim(BrxBimRoom::getAssignedStory(id.m_id, rval));
    return PyBrxBimStory{ rval };
}

PyBrxBimBuilding PyBrxBimRoom::getAssignedBuildingS(const PyDbObjectId& id)
{
    BrxBimBuilding rval;
    PyThrowBadBim(BrxBimRoom::getAssignedBuilding(id.m_id, rval));
    return PyBrxBimBuilding{ rval };
}

void PyBrxBimRoom::unassignLocationS(const PyDbObjectId& id)
{
    PyThrowBadBim(BrxBimRoom::unassignLocation(id.m_id));
}

boost::python::list PyBrxBimRoom::getAllRooms1()
{
    AcDbObjectIdArray ids;
    PyThrowBadBim(BrxBimRoom::getAllRooms(ids));
    return ObjectIdArrayToPyList(ids);
}

boost::python::list PyBrxBimRoom::getAllRooms2(const PyDbDatabase& pDb)
{
    AcDbObjectIdArray ids;
    PyThrowBadBim(BrxBimRoom::getAllRooms(ids, pDb.impObj()));
    return ObjectIdArrayToPyList(ids);
}

boost::python::list PyBrxBimRoom::getAllRooms3(const PyBrxBimStory& story)
{
    AcDbObjectIdArray ids;
    PyThrowBadBim(BrxBimRoom::getAllRooms(ids, *story.impObj()));
    return ObjectIdArrayToPyList(ids);
}

boost::python::list PyBrxBimRoom::getAllRooms4(const PyBrxBimStory& story, const PyDbDatabase& pDb)
{
    AcDbObjectIdArray ids;
    PyThrowBadBim(BrxBimRoom::getAllRooms(ids, *story.impObj(), pDb.impObj()));
    return ObjectIdArrayToPyList(ids);
}

boost::python::list PyBrxBimRoom::getAllRooms5(const PyBrxBimBuilding& story)
{
    AcDbObjectIdArray ids;
    PyThrowBadBim(BrxBimRoom::getAllRooms(ids, *story.impObj()));
    return ObjectIdArrayToPyList(ids);
}

boost::python::list PyBrxBimRoom::getAllRooms6(const PyBrxBimBuilding& story, const PyDbDatabase& pDb)
{
    AcDbObjectIdArray ids;
    PyThrowBadBim(BrxBimRoom::getAllRooms(ids, *story.impObj(), pDb.impObj()));
    return ObjectIdArrayToPyList(ids);
}

bool PyBrxBimRoom::isAssociativeRoomS(const PyDbObjectId& id)
{
    return BrxBimRoom::isAssociativeRoom(id.m_id);
}

void PyBrxBimRoom::updateAssociativeRoomS(const PyDbObjectId& id)
{
    PyThrowBadBim(BrxBimRoom::updateAssociativeRoom(id.m_id));
}

boost::python::list PyBrxBimRoom::getBoundingElementsS(const PyDbObjectId& id)
{
    AcDbObjectIdArray ids;
    PyThrowBadBim(BrxBimRoom::getBoundingElements(id.m_id, ids));
    return ObjectIdArrayToPyList(ids);
}

boost::python::list PyBrxBimRoom::getOpeningsS(const PyDbObjectId& id)
{
    AcDbObjectIdArray ids;
    PyThrowBadBim(BrxBimRoom::getOpenings(id.m_id, ids));
    return ObjectIdArrayToPyList(ids);
}

PyDbObjectId PyBrxBimRoom::getRoomEntityS(const PyBrxBimRoom& bimRoom)
{
    PyDbObjectId id;
    PyThrowBadBim(BrxBimRoom::getRoomEntity(*bimRoom.impObj(), id.m_id));
    return id;
}

std::string PyBrxBimRoom::roomIdentS(const PyDbObjectId& id)
{
    return wstr_to_utf8(BrxBimRoom::roomIdent(id.m_id));
}

std::string PyBrxBimRoom::roomNameS(const PyDbObjectId& id)
{
    return wstr_to_utf8(BrxBimRoom::roomName(id.m_id));
}

void PyBrxBimRoom::setRoomNameS(const PyDbObjectId& id, const std::string& szNewName)
{
    PyThrowBadBim(BrxBimRoom::setRoomName(id.m_id, utf8_to_wstr(szNewName).c_str()));
}

std::string PyBrxBimRoom::roomNumberS(const PyDbObjectId& id)
{
    return wstr_to_utf8(BrxBimRoom::roomNumber(id.m_id));
}

void PyBrxBimRoom::setRoomNumberS(const PyDbObjectId& id, const std::string& szNewNumber)
{
    PyThrowBadBim(BrxBimRoom::setRoomNumber(id.m_id, utf8_to_wstr(szNewNumber).c_str()));
}

std::string PyBrxBimRoom::descriptionS(const PyDbObjectId& id)
{
    return wstr_to_utf8(BrxBimRoom::description(id.m_id));
}

void PyBrxBimRoom::setDescriptionS(const PyDbObjectId& id, const std::string& szInfo)
{
    PyThrowBadBim(BrxBimRoom::setDescription(id.m_id, utf8_to_wstr(szInfo).c_str()));
}

double PyBrxBimRoom::roomAreaS(const PyDbObjectId& id)
{
    double area = 0.0;
    PyThrowBadBim(BrxBimRoom::roomArea(id.m_id, area));
    return area;
}

std::string PyBrxBimRoom::getRoomRepresentationS(const PyDbObjectId& id)
{
    AcString rval;
    PyThrowBadBim(BrxBimRoom::getRoomRepresentation(id.m_id, rval));
    return wstr_to_utf8(rval);
}

void PyBrxBimRoom::setRoomRepresentationS(const PyDbObjectId& id, const std::string& representation)
{
    PyThrowBadBim(BrxBimRoom::setRoomRepresentation(id.m_id, utf8_to_wstr(representation).c_str()));
}

std::string PyBrxBimRoom::getRoomDepartmentS(const PyDbObjectId& id)
{
    AcString department;
    PyThrowBadBim(BrxBimRoom::getRoomRepresentation(id.m_id, department));
    return wstr_to_utf8(department);
}

void PyBrxBimRoom::setRoomDepartmentS(const PyDbObjectId& id, const std::string& department)
{
    PyThrowBadBim(BrxBimRoom::setRoomDepartment(id.m_id, utf8_to_wstr(department).c_str()));
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
    constexpr const std::string_view getAllSpacesOverLoads = "Overloads:\n"
        "- None: Any\n"
        "- db: PyDb.Database\n"
        "- val: PyBrxBim.BimStory\n"
        "- val: PyBrxBim.BimBuilding\n"
        "- val: PyBrxBim.BimStory, db: PyDb.Database\n"
        "- val: PyBrxBim.BimBuilding, db: PyDb.Database\n";

    PyDocString DS("BimSpace");
    class_<PyBrxBimSpace>("BimSpace")
        .def("createSpace", &PyBrxBimSpace::createSpace, DS.SARGS({ "pt: PyGe.Point3d" })).staticmethod("createSpace")
        .def("isSpaceValid", &PyBrxBimSpace::isSpaceValid, DS.SARGS({ "id: PyDb.ObjectId" })).staticmethod("isSpaceValid")
        .def("isSpaceUpdated", &PyBrxBimSpace::isSpaceUpdated, DS.SARGS({ "id: PyDb.ObjectId" })).staticmethod("isSpaceUpdated")
        .def("getSpaceEntity", &PyBrxBimSpace::getSpaceEntity1)
        .def("getSpaceEntity", &PyBrxBimSpace::getSpaceEntity2, DS.SARGS({ "spaceName: str", "db: PyDb.Database = None" })).staticmethod("getSpaceEntity")
        .def("updateSpace", &PyBrxBimSpace::updateSpace, DS.SARGS({ "id: PyDb.ObjectId" })).staticmethod("updateSpace")
        .def("getBoundingElements", &PyBrxBimSpace::getBoundingElements, DS.SARGS({ "id: PyDb.ObjectId" })).staticmethod("getBoundingElements")
        .def("getSpaceNumber", &PyBrxBimSpace::getSpaceNumber, DS.SARGS({ "id: PyDb.ObjectId" })).staticmethod("getSpaceNumber")
        .def("setSpaceNumber", &PyBrxBimSpace::setSpaceNumber, DS.SARGS({ "id: PyDb.ObjectId","val: str" })).staticmethod("setSpaceNumber")
        .def("getSpaceArea", &PyBrxBimSpace::getSpaceArea, DS.SARGS({ "id: PyDb.ObjectId" })).staticmethod("getSpaceArea")
        .def("getSpaceRepresentation", &PyBrxBimSpace::getSpaceRepresentation, DS.SARGS({ "id: PyDb.ObjectId" })).staticmethod("getSpaceRepresentation")
        .def("setSpaceRepresentation", &PyBrxBimSpace::setSpaceRepresentation, DS.SARGS({ "id: PyDb.ObjectId","val: PyBrxBim.BimSpaceRepresentation" })).staticmethod("setSpaceRepresentation")
        .def("getAllSpaces", &PyBrxBimSpace::getAllSpaces1)
        .def("getAllSpaces", &PyBrxBimSpace::getAllSpaces2)
        .def("getAllSpaces", &PyBrxBimSpace::getAllSpaces3)
        .def("getAllSpaces", &PyBrxBimSpace::getAllSpaces4)
        .def("getAllSpaces", &PyBrxBimSpace::getAllSpaces5)
        .def("getAllSpaces", &PyBrxBimSpace::getAllSpaces6, DS.SOVRL(getAllSpacesOverLoads)).staticmethod("getAllSpaces")
        .def("assignToBuilding", &PyBrxBimSpace::assignToBuilding, DS.SARGS({ "id: PyDb.ObjectId","building: PyBrxBim.BimBuilding" })).staticmethod("assignToBuilding")
        .def("assignToStory", &PyBrxBimSpace::assignToStory, DS.SARGS({ "id: PyDb.ObjectId","building: PyBrxBim.BimStory" })).staticmethod("assignToStory")
        .def("getSpaceName", &PyBrxBimSpace::getSpaceName, DS.SARGS({ "id: PyDb.ObjectId" })).staticmethod("getSpaceName")
        .def("setSpaceName", &PyBrxBimSpace::setSpaceName, DS.SARGS({ "id: PyDb.ObjectId","val: str" })).staticmethod("setSpaceName")
        .def("getAssignedSpace", &PyBrxBimSpace::getAssignedSpace, DS.SARGS({ "id: PyDb.ObjectId" })).staticmethod("getAssignedSpace")
        .def("setAssignedSpace", &PyBrxBimSpace::setAssignedSpace1)
        .def("setAssignedSpace", &PyBrxBimSpace::setAssignedSpace2, DS.SARGS({ "id: PyDb.ObjectId","val: str|PyDb.ObjectId" })).staticmethod("setAssignedSpace")
        .def("getAssignedEntities", &PyBrxBimSpace::getAssignedEntities1)
        .def("getAssignedEntities", &PyBrxBimSpace::getAssignedEntities2)
        .def("getAssignedEntities", &PyBrxBimSpace::getAssignedEntities3, DS.SARGS({ "val: str|PyDb.ObjectId","db: PyDb.Database=None" })).staticmethod("getAssignedEntities")
        .def("className", &PyBrxBimSpace::className, DS.SARGS()).staticmethod("className")
        ;
}

PyDbObjectId PyBrxBimSpace::createSpace(const AcGePoint3d& pickPt)
{
    return PyDbObjectId{ BrxBimSpace::createSpace(pickPt) };
}

bool PyBrxBimSpace::isSpaceValid(const PyDbObjectId& spaceId)
{
    return BrxBimSpace::isSpaceValid(spaceId.m_id);
}

bool PyBrxBimSpace::isSpaceUpdated(const PyDbObjectId& spaceId)
{
    return BrxBimSpace::isSpaceUpdated(spaceId.m_id);
}

PyDbObjectId PyBrxBimSpace::getSpaceEntity1(const std::string& spaceName)
{
    PyDbObjectId id;
    PyThrowBadBim(BrxBimSpace::getSpaceEntity(id.m_id, utf8_to_wstr(spaceName).c_str()));
    return id;
}

PyDbObjectId PyBrxBimSpace::getSpaceEntity2(const std::string& spaceName, const PyDbDatabase& pDb)
{
    PyDbObjectId id;
    PyThrowBadBim(BrxBimSpace::getSpaceEntity(id.m_id, utf8_to_wstr(spaceName).c_str(), pDb.impObj()));
    return id;
}

void PyBrxBimSpace::updateSpace(const PyDbObjectId& spaceId)
{
    PyThrowBadBim(BrxBimSpace::updateSpace(spaceId.m_id));
}

boost::python::list PyBrxBimSpace::getBoundingElements(const PyDbObjectId& spaceId)
{
    AcDbObjectIdArray boundaries;
    PyThrowBadBim(BrxBimSpace::getBoundingElements(spaceId.m_id, boundaries));
    return ObjectIdArrayToPyList(boundaries);
}

std::string PyBrxBimSpace::getSpaceNumber(const PyDbObjectId& spaceId)
{
    AcString numberStr;
    PyThrowBadBim(BrxBimSpace::getSpaceNumber(spaceId.m_id, numberStr));
    return wstr_to_utf8(numberStr);
}

void PyBrxBimSpace::setSpaceNumber(const PyDbObjectId& spaceId, const std::string& numberStr)
{
    PyThrowBadBim(BrxBimSpace::setSpaceNumber(spaceId.m_id, utf8_to_wstr(numberStr).c_str()));
}

double PyBrxBimSpace::getSpaceArea(const PyDbObjectId& spaceId)
{
    double area = 0.0;
    PyThrowBadBim(BrxBimSpace::getSpaceArea(spaceId.m_id, area));
    return area;
}

EBimSpaceRepresentation PyBrxBimSpace::getSpaceRepresentation(const PyDbObjectId& spaceId)
{
    EBimSpaceRepresentation representation = EBimSpaceRepresentation::eSolid;
    PyThrowBadBim(BrxBimSpace::getSpaceRepresentation(spaceId.m_id, representation));
    return representation;
}

void PyBrxBimSpace::setSpaceRepresentation(const PyDbObjectId& spaceId, EBimSpaceRepresentation representation)
{
    PyThrowBadBim(BrxBimSpace::setSpaceRepresentation(spaceId.m_id, representation));
}

boost::python::list PyBrxBimSpace::getAllSpaces1()
{
    AcDbObjectIdArray ids;
    PyThrowBadBim(BrxBimSpace::getAllSpaces(ids));
    return ObjectIdArrayToPyList(ids);
}

boost::python::list PyBrxBimSpace::getAllSpaces2(const PyDbDatabase& pDb)
{
    AcDbObjectIdArray ids;
    PyThrowBadBim(BrxBimSpace::getAllSpaces(ids, pDb.impObj()));
    return ObjectIdArrayToPyList(ids);
}

boost::python::list PyBrxBimSpace::getAllSpaces3(const PyBrxBimBuilding& building)
{
    AcDbObjectIdArray ids;
    PyThrowBadBim(BrxBimSpace::getAllSpaces(ids, *building.impObj()));
    return ObjectIdArrayToPyList(ids);
}

boost::python::list PyBrxBimSpace::getAllSpaces4(const PyBrxBimBuilding& building, const PyDbDatabase& pDb)
{
    AcDbObjectIdArray ids;
    PyThrowBadBim(BrxBimSpace::getAllSpaces(ids, *building.impObj(), pDb.impObj()));
    return ObjectIdArrayToPyList(ids);
}

boost::python::list PyBrxBimSpace::getAllSpaces5(const PyBrxBimStory& story)
{
    AcDbObjectIdArray ids;
    PyThrowBadBim(BrxBimSpace::getAllSpaces(ids, *story.impObj()));
    return ObjectIdArrayToPyList(ids);
}

boost::python::list PyBrxBimSpace::getAllSpaces6(const PyBrxBimStory& story, const PyDbDatabase& pDb)
{
    AcDbObjectIdArray ids;
    PyThrowBadBim(BrxBimSpace::getAllSpaces(ids, *story.impObj(), pDb.impObj()));
    return ObjectIdArrayToPyList(ids);
}

void PyBrxBimSpace::assignToBuilding(const PyDbObjectId& spaceId, const PyBrxBimBuilding& building)
{
    PyThrowBadBim(BrxBimSpace::assignToBuilding(spaceId.m_id, *building.impObj()));
}

void PyBrxBimSpace::assignToStory(const PyDbObjectId& spaceId, const PyBrxBimStory& story)
{
    PyThrowBadBim(BrxBimSpace::assignToStory(spaceId.m_id, *story.impObj()));
}

std::string PyBrxBimSpace::getSpaceName(const PyDbObjectId& spaceId)
{
    AcString spaceName;
    PyThrowBadBim(BrxBimSpace::getSpaceName(spaceId.m_id, spaceName));
    return wstr_to_utf8(spaceName);
}

void PyBrxBimSpace::setSpaceName(const PyDbObjectId& spaceId, const std::string& spaceName)
{
    PyThrowBadBim(BrxBimSpace::setSpaceName(spaceId.m_id, utf8_to_wstr(spaceName).c_str()));
}

boost::python::tuple PyBrxBimSpace::getAssignedSpace(const PyDbObjectId& entityId)
{
    PyDbObjectId id;
    AcString spaceName;
    PyThrowBadBim(BrxBimSpace::getAssignedSpace(entityId.m_id, id.m_id, spaceName));
    PyAutoLockGIL lock;
    return boost::python::make_tuple(id, wstr_to_utf8(spaceName));
}

void PyBrxBimSpace::setAssignedSpace1(const PyDbObjectId& entityId, const PyDbObjectId& spaceId)
{
    PyThrowBadBim(BrxBimSpace::setAssignedSpace(entityId.m_id, spaceId.m_id));
}

void PyBrxBimSpace::setAssignedSpace2(const PyDbObjectId& entityId, const std::string& spaceName)
{
    PyThrowBadBim(BrxBimSpace::setAssignedSpace(entityId.m_id, utf8_to_wstr(spaceName).c_str()));
}

boost::python::list PyBrxBimSpace::getAssignedEntities1(const PyDbObjectId& spaceId)
{
    AcDbObjectIdArray ids;
    PyThrowBadBim(BrxBimSpace::getAssignedEntities(ids, spaceId.m_id));
    return ObjectIdArrayToPyList(ids);
}

boost::python::list PyBrxBimSpace::getAssignedEntities2(const std::string& spaceName)
{
    AcDbObjectIdArray ids;
    PyThrowBadBim(BrxBimSpace::getAssignedEntities(ids, utf8_to_wstr(spaceName).c_str()));
    return ObjectIdArrayToPyList(ids);
}

boost::python::list PyBrxBimSpace::getAssignedEntities3(const std::string& spaceName, const PyDbDatabase& pDb)
{
    AcDbObjectIdArray ids;
    PyThrowBadBim(BrxBimSpace::getAssignedEntities(ids, utf8_to_wstr(spaceName).c_str(), pDb.impObj()));
    return ObjectIdArrayToPyList(ids);
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

std::string PyBrxBimMaterial::comments() const
{
    return wstr_to_utf8(impObj()->comments());
}

std::string PyBrxBimMaterial::appearance() const
{
    return wstr_to_utf8(impObj()->appearance());
}

PyBrxBimHatchPattern PyBrxBimMaterial::cutPattern() const
{
    return PyBrxBimHatchPattern{ impObj()->cutPattern() };
}

PyBrxBimHatchPattern PyBrxBimMaterial::surfacePattern() const
{
    return PyBrxBimHatchPattern{ impObj()->surfacePattern() };
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

PyBrxBimHatchPattern::PyBrxBimHatchPattern(double scaleOrSpacing, double angle, bool cross)
    : PyBrxBimHatchPattern(new BrxBimMaterial::HatchPattern(scaleOrSpacing, angle, cross), true)
{
}

PyBrxBimHatchPattern::PyBrxBimHatchPattern(BrxBimMaterial::EHatchType type, const std::string& name, double scaleOrSpacing, double angle)
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
    constexpr const std::string_view classifyAsOverloads = "Overloads:\n"
        "- id: PyDb.ObjectId, objectType: PyBrxBim.BimElementType\n"
        "- database: PyDb.database, objectType: PyBrxBim.BimElementType\n"
        "- id: PyDb.ObjectId, typeName: str\n"
        "- id: PyDb.ObjectId, typeName: str, localName: bool\n";

    constexpr const std::string_view isClassifiedAsOverloads = "Overloads:\n"
        "- id: PyDb.ObjectId, objectType: PyBrxBim.BimElementType\n"
        "- database: PyDb.database, objectType: PyBrxBim.BimElementType\n"
        "- id: PyDb.ObjectId, typeName: str\n"
        "- id: PyDb.ObjectId, typeName: str, localName: bool\n";

    constexpr const std::string_view hasPropertyOverloads = "Overloads:\n"
        "- id: PyDb.ObjectId, propertyName: str\n"
        "- id: PyDb.ObjectId, propertyName: str, category : PyBrxBim.EBimCategory\n"
        "- id: PyDb.ObjectId, propertyName: str, category: str\n";

    constexpr const std::string_view deletePropertyOverloads = "Overloads:\n"
        "- id: PyDb.ObjectId, propertyName: str\n"
        "- id: PyDb.ObjectId, propertyName: str, category : PyBrxBim.EBimCategory\n"
        "- id: PyDb.ObjectId, propertyName: str, category: str\n";

    constexpr const std::string_view getPropertyOverloads = "Overloads:\n"
        "- id: PyDb.ObjectId, propertyName: str\n"
        "- id: PyDb.ObjectId, propertyName: str, category : PyBrxBim.EBimCategory\n"
        "- id: PyDb.ObjectId, propertyName: str, category: str\n";

    constexpr const std::string_view setPropertyOverloads = "Overloads:\n"
        "- id: PyDb.ObjectId, propertyName: str, val: PyDb.AcValue\n"
        "- id: PyDb.ObjectId, propertyName: str, val: PyDb.AcValue,category : PyBrxBim.EBimCategory\n"
        "- id: PyDb.ObjectId, propertyName: str, val: PyDb.AcValue, category: str\n";


    PyDocString DS("BimClassification");
    class_<PyBrxBimClassification>("BimClassification")
        .def(init<>())
        .def("getName", &PyBrxBimClassification::getName, DS.SARGS({ "id: PyDb.ObjectId" })).staticmethod("getName")
        .def("setName", &PyBrxBimClassification::setName, DS.SARGS({ "id: PyDb.ObjectId" , "description: str" })).staticmethod("setName")
        .def("getDescription", &PyBrxBimClassification::getDescription, DS.SARGS({ "id: PyDb.ObjectId" })).staticmethod("getDescription")
        .def("setDescription", &PyBrxBimClassification::setDescription, DS.SARGS({ "id: PyDb.ObjectId" , "description: str" })).staticmethod("setDescription")
        .def("getGUID", &PyBrxBimClassification::getGUID, DS.SARGS({ "id: PyDb.ObjectId" })).staticmethod("getGUID")

        .def("classifyAs", &PyBrxBimClassification::classifyAs1)
        .def("classifyAs", &PyBrxBimClassification::classifyAs2)
        .def("classifyAs", &PyBrxBimClassification::classifyAs3)
        .def("classifyAs", &PyBrxBimClassification::classifyAs4, DS.SOVRL(classifyAsOverloads)).staticmethod("classifyAs")

        .def("unClassify", &PyBrxBimClassification::unClassify1)
        .def("unClassify", &PyBrxBimClassification::unClassify2, DS.SARGS({ "val: PyDb.ObjectId|PyDb.Database" })).staticmethod("unClassify")

        .def("isClassifiedAs", &PyBrxBimClassification::isClassifiedAs1)
        .def("isClassifiedAs", &PyBrxBimClassification::isClassifiedAs2)
        .def("isClassifiedAs", &PyBrxBimClassification::isClassifiedAs3)
        .def("isClassifiedAs", &PyBrxBimClassification::isClassifiedAs4, DS.SOVRL(isClassifiedAsOverloads)).staticmethod("isClassifiedAs")

        .def("isClassified", &PyBrxBimClassification::isClassified, DS.SARGS({ "val: PyDb.Database" })).staticmethod("isClassified")
        .def("isClassifiedAsAnyBuildingElement", &PyBrxBimClassification::isClassifiedAsAnyBuildingElement, DS.SARGS({ "id: PyDb.ObjectId" })).staticmethod("isClassifiedAsAnyBuildingElement")
        .def("isUnclassified", &PyBrxBimClassification::isUnclassified, DS.SARGS({ "id: PyDb.ObjectId" })).staticmethod("isUnclassified")
        .def("getClassification", &PyBrxBimClassification::getClassification1)
        .def("getClassification", &PyBrxBimClassification::getClassification2, DS.SARGS({ "val: PyDb.ObjectId|PyDb.Database" })).staticmethod("getClassification")

        .def("getClassificationName", &PyBrxBimClassification::getClassificationName1)
        .def("getClassificationName", &PyBrxBimClassification::getClassificationName2, DS.SARGS({ "id: PyDb.ObjectId", "localName : bool = False" })).staticmethod("getClassification")

        .def("getPropertyNames", &PyBrxBimClassification::getPropertyNames, DS.SARGS({ "id: PyDb.ObjectId" })).staticmethod("getPropertyNames")
        .def("getPropertyDict", &PyBrxBimClassification::getPropertyDict, DS.SARGS({ "id: PyDb.ObjectId" })).staticmethod("getPropertyDict")

        .def("hasProperty", &PyBrxBimClassification::hasProperty1)
        .def("hasProperty", &PyBrxBimClassification::hasProperty2)
        .def("hasProperty", &PyBrxBimClassification::hasProperty3, DS.SOVRL(hasPropertyOverloads)).staticmethod("hasProperty")

        .def("deleteProperty", &PyBrxBimClassification::deleteProperty1)
        .def("deleteProperty", &PyBrxBimClassification::deleteProperty2)
        .def("deleteProperty", &PyBrxBimClassification::deleteProperty3, DS.SOVRL(deletePropertyOverloads)).staticmethod("deleteProperty")

        .def("getProperty", &PyBrxBimClassification::getProperty1)
        .def("getProperty", &PyBrxBimClassification::getProperty2)
        .def("getProperty", &PyBrxBimClassification::getProperty3, DS.SOVRL(getPropertyOverloads)).staticmethod("getProperty")

        .def("setProperty", &PyBrxBimClassification::setProperty1)
        .def("setProperty", &PyBrxBimClassification::setProperty2)
        .def("setProperty", &PyBrxBimClassification::setProperty3, DS.SOVRL(setPropertyOverloads)).staticmethod("setProperty")

        .def("getAllClassified", &PyBrxBimClassification::getAllClassified, DS.SARGS({ "db: PyDb.Database" })).staticmethod("getAllClassified")
        .def("getAllClassifiedAs", &PyBrxBimClassification::getAllClassifiedAs, DS.SARGS({ "name: str", "db: PyDb.Database" })).staticmethod("getAllClassifiedAs")

        .def("getAllClassifiedAsName", &PyBrxBimClassification::getAllClassifiedAsName1)
        .def("getAllClassifiedAsName", &PyBrxBimClassification::getAllClassifiedAsName2, DS.SARGS({ "name: str", "db: PyDb.Database","local: bool = False" })).staticmethod("getAllClassifiedAsName")

        .def("getAllUnclassified", &PyBrxBimClassification::getAllUnclassified, DS.SARGS({ "db: PyDb.Database" })).staticmethod("getAllUnclassified")

        .def("getAllUsedClassifications", &PyBrxBimClassification::getAllUsedClassifications, DS.SARGS({ "db: PyDb.Database" })).staticmethod("getAllUsedClassifications")
        .def("getAllUsedClassificationNames", &PyBrxBimClassification::getAllUsedClassificationNames1)
        .def("getAllUsedClassificationNames", &PyBrxBimClassification::getAllUsedClassificationNames2, DS.SARGS({ "db: PyDb.Database","local: bool = False" })).staticmethod("getAllUsedClassificationNames")


        .def("getBimTypeNames", &PyBrxBimClassification::getBimTypeNames1)
        .def("getBimTypeNames", &PyBrxBimClassification::getBimTypeNames2, DS.SARGS({ "local: bool = False" })).staticmethod("getBimTypeNames")


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

std::string PyBrxBimClassification::getName(const PyDbObjectId& id)
{
    return wstr_to_utf8(BimClassification::getName(id.m_id));
}

void PyBrxBimClassification::setName(const PyDbObjectId& id, const std::string& szName)
{
    PyThrowBadBim(BimClassification::setName(id.m_id, utf8_to_wstr(szName).c_str()));
}

std::string PyBrxBimClassification::getDescription(const PyDbObjectId& id)
{
    return wstr_to_utf8(BimClassification::getDescription(id.m_id));
}

void PyBrxBimClassification::setDescription(const PyDbObjectId& id, const std::string& szDescription)
{
    PyThrowBadBim(BimClassification::setDescription(id.m_id, utf8_to_wstr(szDescription).c_str()));
}

std::string PyBrxBimClassification::getGUID(const PyDbObjectId& id)
{
    return wstr_to_utf8(BimClassification::getGUID(id.m_id));
}

void PyBrxBimClassification::classifyAs1(const PyDbObjectId& id, const BimApi::BimElementType objectType)
{
    PyThrowBadBim(BimClassification::classifyAs(id.m_id, objectType));
}

void PyBrxBimClassification::classifyAs2(const PyDbObjectId& id, const std::string& typeName)
{
    PyThrowBadBim(BimClassification::classifyAs(id.m_id, utf8_to_wstr(typeName).c_str()));
}

void PyBrxBimClassification::classifyAs3(const PyDbObjectId& id, const std::string& typeName, bool localName)
{
    PyThrowBadBim(BimClassification::classifyAs(id.m_id, utf8_to_wstr(typeName).c_str(), localName));
}

void PyBrxBimClassification::classifyAs4(const PyDbDatabase& database, const BimApi::BimElementType objectType)
{
#if defined(_BRXTARGET240)
    throw PyNotimplementedByHost();
#else
    PyThrowBadBim(BimClassification::classifyAs(database.impObj(), objectType));
#endif
}

void PyBrxBimClassification::unClassify1(const PyDbObjectId& id)
{
    PyThrowBadBim(BimClassification::unClassify(id.m_id));
}

void PyBrxBimClassification::unClassify2(const PyDbDatabase& database)
{
#if defined(_BRXTARGET240)
    throw PyNotimplementedByHost();
#else
    PyThrowBadBim(BimClassification::unClassify(database.impObj()));
#endif
}

bool PyBrxBimClassification::isClassifiedAs1(const PyDbObjectId& id, const BimApi::BimElementType objectType)
{
    return BimClassification::isClassifiedAs(id.m_id, objectType);
}

bool PyBrxBimClassification::isClassifiedAs2(const PyDbObjectId& id, const std::string& typeName)
{
    return BimClassification::isClassifiedAs(id.m_id, utf8_to_wstr(typeName).c_str());
}

bool PyBrxBimClassification::isClassifiedAs3(const PyDbObjectId& id, const std::string& typeName, bool localName)
{
    return BimClassification::isClassifiedAs(id.m_id, utf8_to_wstr(typeName).c_str(), localName);
}

bool PyBrxBimClassification::isClassifiedAs4(const PyDbDatabase& database, const BimApi::BimElementType objectType)
{
#if defined(_BRXTARGET240)
    throw PyNotimplementedByHost();
#else
    return BimClassification::isClassifiedAs(database.impObj(), objectType);
#endif
}

bool PyBrxBimClassification::isClassified(const PyDbDatabase& database)
{
#if defined(_BRXTARGET240)
    throw PyNotimplementedByHost();
#else
    return BimClassification::isClassified(database.impObj());
#endif
}

bool PyBrxBimClassification::isClassifiedAsAnyBuildingElement(const PyDbObjectId& id)
{
    return BimClassification::isClassifiedAsAnyBuildingElement(id.m_id);
}

bool PyBrxBimClassification::isUnclassified(const PyDbObjectId& id)
{
    return BimClassification::isUnclassified(id.m_id);
}

BimApi::BimElementType PyBrxBimClassification::getClassification1(const PyDbObjectId& id)
{
    BimApi::BimElementType bimtype;
    PyThrowBadBim(BimClassification::getClassification(bimtype, id.m_id));
    return bimtype;
}

BimApi::BimElementType PyBrxBimClassification::getClassification2(const PyDbDatabase& database)
{
#if defined(_BRXTARGET240)
    throw PyNotimplementedByHost();
#else
    return BimClassification::getClassification(database.impObj());
#endif
}

std::string PyBrxBimClassification::getClassificationName1(const PyDbObjectId& id)
{
    AcString typeName;
    PyThrowBadBim(BimClassification::getClassification(typeName, id.m_id));
    return wstr_to_utf8(typeName);
}

std::string PyBrxBimClassification::getClassificationName2(const PyDbObjectId& id, bool localName)
{
    AcString typeName;
    PyThrowBadBim(BimClassification::getClassification(typeName, id.m_id, localName));
    return wstr_to_utf8(typeName);
}

boost::python::list PyBrxBimClassification::getPropertyNames(const PyDbObjectId& id)
{
    AcStringArray propertyNames;
    PyThrowBadBim(BimClassification::getProperties(propertyNames, id.m_id));
    return AcStringArrayToPyList(propertyNames);
}

boost::python::dict PyBrxBimClassification::getPropertyDict(const PyDbObjectId& id)
{
    BimPropertiesMap pmap;
    PyThrowBadBim(BimClassification::getProperties(pmap, id.m_id));
    PyAutoLockGIL lock;
    boost::python::dict pydict;
    for (const auto& item : pmap)
        pydict[wstr_to_utf8(item.first)] = wstr_to_utf8(item.second);
    return pydict;
}

bool PyBrxBimClassification::hasProperty1(const PyDbObjectId& id, const std::string& szName)
{
    return BimClassification::hasProperty(id.m_id, utf8_to_wstr(szName).c_str());
}

bool PyBrxBimClassification::hasProperty2(const PyDbObjectId& id, const std::string& szName, const EBimCategory category)
{
    return BimClassification::hasProperty(id.m_id, utf8_to_wstr(szName).c_str(), category);
}

bool PyBrxBimClassification::hasProperty3(const PyDbObjectId& id, const std::string& szName, const std::string& category)
{
    return BimClassification::hasProperty(id.m_id, utf8_to_wstr(szName).c_str(), utf8_to_wstr(category).c_str());
}

bool PyBrxBimClassification::deleteProperty1(const PyDbObjectId& id, const std::string& szName)
{
    return BimClassification::deleteProperty(id.m_id, utf8_to_wstr(szName).c_str());
}

bool PyBrxBimClassification::deleteProperty2(const PyDbObjectId& id, const std::string& szName, const EBimCategory category)
{
    return BimClassification::deleteProperty(id.m_id, utf8_to_wstr(szName).c_str(), category);
}

bool PyBrxBimClassification::deleteProperty3(const PyDbObjectId& id, const std::string& szName, const std::string& category)
{
    return BimClassification::deleteProperty(id.m_id, utf8_to_wstr(szName).c_str(), utf8_to_wstr(category).c_str());
}

PyDbAcValue PyBrxBimClassification::getProperty1(const PyDbObjectId& id, const std::string& szName)
{
    AcValue propertyValue;
    PyThrowBadBim(BimClassification::getProperty(propertyValue, id.m_id, utf8_to_wstr(szName).c_str()));
    return PyDbAcValue{ propertyValue };
}

PyDbAcValue PyBrxBimClassification::getProperty2(const PyDbObjectId& id, const std::string& szName, const EBimCategory category)
{
    AcValue propertyValue;
    PyThrowBadBim(BimClassification::getProperty(propertyValue, id.m_id, utf8_to_wstr(szName).c_str(), category));
    return PyDbAcValue{ propertyValue };
}

PyDbAcValue PyBrxBimClassification::getProperty3(const PyDbObjectId& id, const std::string& szPropertyName, const std::string& category)
{
    AcValue propertyValue;
    PyThrowBadBim(BimClassification::getProperty(propertyValue, id.m_id, utf8_to_wstr(szPropertyName).c_str(), utf8_to_wstr(category).c_str()));
    return PyDbAcValue{ propertyValue };
}

void PyBrxBimClassification::setProperty1(const PyDbObjectId& id, const std::string& szName, const PyDbAcValue& val)
{
    PyThrowBadBim(BimClassification::setProperty(id.m_id, utf8_to_wstr(szName).c_str(), *val.impObj()));
}

void PyBrxBimClassification::setProperty2(const PyDbObjectId& id, const std::string& szName, const PyDbAcValue& val, const EBimCategory category)
{
    PyThrowBadBim(BimClassification::setProperty(id.m_id, utf8_to_wstr(szName).c_str(), *val.impObj(), category));
}

void PyBrxBimClassification::setProperty3(const PyDbObjectId& id, const std::string& szName, const PyDbAcValue& val, const std::string& category)
{
    PyThrowBadBim(BimClassification::setProperty(id.m_id, utf8_to_wstr(szName).c_str(), *val.impObj(), utf8_to_wstr(category).c_str()));
}

boost::python::list PyBrxBimClassification::getAllClassified(const PyDbDatabase& database)
{
    AcDbObjectIdArray ids;
    PyThrowBadBim(BimClassification::getAllClassified(ids, database.impObj()));
    return ObjectIdArrayToPyList(ids);
}

boost::python::list PyBrxBimClassification::getAllClassifiedAs(const BimApi::BimElementType objectType, const PyDbDatabase& database)
{
    AcDbObjectIdArray ids;
    PyThrowBadBim(BimClassification::getAllClassifiedAs(ids, objectType, database.impObj()));
    return ObjectIdArrayToPyList(ids);
}

boost::python::list PyBrxBimClassification::getAllClassifiedAsName1(const std::string& typeName, const PyDbDatabase& database)
{
    AcDbObjectIdArray ids;
    PyThrowBadBim(BimClassification::getAllClassifiedAs(ids, utf8_to_wstr(typeName).c_str(), database.impObj()));
    return ObjectIdArrayToPyList(ids);
}

boost::python::list PyBrxBimClassification::getAllClassifiedAsName2(const std::string& typeName, const PyDbDatabase& database, bool localName)
{
    AcDbObjectIdArray ids;
    PyThrowBadBim(BimClassification::getAllClassifiedAs(ids, utf8_to_wstr(typeName).c_str(), database.impObj(), localName));
    return ObjectIdArrayToPyList(ids);
}

boost::python::list PyBrxBimClassification::getAllUnclassified(const PyDbDatabase& database)
{
    AcDbObjectIdArray ids;
    PyThrowBadBim(BimClassification::getAllUnclassified(ids, database.impObj()));
    return ObjectIdArrayToPyList(ids);
}

boost::python::list PyBrxBimClassification::getAllUsedClassifications(const PyDbDatabase& database)
{
    BimApi::BimTypes usedTypes;
    PyThrowBadBim(BimClassification::getAllUsedClassifications(usedTypes, database.impObj()));
    PyAutoLockGIL lock;
    boost::python::list pylist;
    for (auto item : usedTypes)
        pylist.append(item);
    return pylist;
}

boost::python::list PyBrxBimClassification::getAllUsedClassificationNames1(const PyDbDatabase& database)
{
    AcStringArray usedTypes;
    PyThrowBadBim(BimClassification::getAllUsedClassifications(usedTypes, database.impObj()));
    return AcStringArrayToPyList(usedTypes);
}

boost::python::list PyBrxBimClassification::getAllUsedClassificationNames2(const PyDbDatabase& database, bool localNames)
{
    AcStringArray usedTypes;
    PyThrowBadBim(BimClassification::getAllUsedClassifications(usedTypes, database.impObj(), localNames));
    return AcStringArrayToPyList(usedTypes);
}

boost::python::list PyBrxBimClassification::getBimTypeNames1()
{
    AcStringArray names;
    PyThrowBadBim(BimClassification::getBimTypeNames(names));
    return AcStringArrayToPyList(names);
}

boost::python::list PyBrxBimClassification::getBimTypeNames2(bool localNames)
{
    AcStringArray names;
    PyThrowBadBim(BimClassification::getBimTypeNames(names, localNames));
    return AcStringArrayToPyList(names);
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
    constexpr const std::string_view createNameSpaceOverloads = "Overloads:\n"
        "- szName: str\n"
        "- szName: str, szLabel: str, visible: bool, db: PyDb.Database\n";


    PyDocString DS("BimNameSpaces");
    class_<PyBrxBimNameSpaces>("BimNameSpaces")
        .def(init<>())
        .def("listNameSpaces", &PyBrxBimNameSpaces::listNameSpaces1)
        .def("listNameSpaces", &PyBrxBimNameSpaces::listNameSpaces2, DS.SARGS({ "db: PyDb.Database=None" })).staticmethod("listNameSpaces")
        .def("hasNameSpace", &PyBrxBimNameSpaces::hasNameSpace1)
        .def("hasNameSpace", &PyBrxBimNameSpaces::hasNameSpace2, DS.SARGS({ "szNameOrLabel: str", "db: PyDb.Database=None" })).staticmethod("hasNameSpace")
        .def("getIsNameSpaceVisible", &PyBrxBimNameSpaces::getIsNameSpaceVisible1)
        .def("getIsNameSpaceVisible", &PyBrxBimNameSpaces::getIsNameSpaceVisible2, DS.SARGS({ "szNameOrLabel: str", "db: PyDb.Database=None" })).staticmethod("getIsNameSpaceVisible")
        .def("setIsNameSpaceVisible", &PyBrxBimNameSpaces::setIsNameSpaceVisible1)
        .def("setIsNameSpaceVisible", &PyBrxBimNameSpaces::setIsNameSpaceVisible2, DS.SARGS({ "visible: bool","szNameOrLabel: str", "db: PyDb.Database=None" })).staticmethod("setIsNameSpaceVisible")
        .def("createNameSpace", &PyBrxBimNameSpaces::createNameSpace1)
        .def("createNameSpace", &PyBrxBimNameSpaces::createNameSpace2, DS.SOVRL(createNameSpaceOverloads)).staticmethod("createNameSpace")
        .def("deleteNameSpace", &PyBrxBimNameSpaces::deleteNameSpace1)
        .def("deleteNameSpace", &PyBrxBimNameSpaces::deleteNameSpace2, DS.SARGS({ "szNameOrLabel: str", "db: PyDb.Database=None" })).staticmethod("deleteNameSpace")
        .def("getNameSpaceLabel", &PyBrxBimNameSpaces::getNameSpaceLabel1)
        .def("getNameSpaceLabel", &PyBrxBimNameSpaces::getNameSpaceLabel2, DS.SARGS({ "szName: str", "db: PyDb.Database=None" })).staticmethod("getNameSpaceLabel")
        .def("setNameSpaceLabel", &PyBrxBimNameSpaces::setNameSpaceLabel1)
        .def("setNameSpaceLabel", &PyBrxBimNameSpaces::setNameSpaceLabel1, DS.SARGS({ "szName: str", "szLable: str", "db: PyDb.Database=None" })).staticmethod("setNameSpaceLabel")
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

static boost::python::dict listNameSpacesImpl(AcDbDatabase *pDb)
{
    BimPropertiesMap nameSpaces;
    PyThrowBadBim(BimNameSpaces::listNameSpaces(nameSpaces, pDb));
    PyAutoLockGIL lock;
    boost::python::dict pydict;
    for (const auto& keyval : nameSpaces)
        pydict[wstr_to_utf8(keyval.first)] = wstr_to_utf8(keyval.second);
    return pydict;
}

boost::python::dict PyBrxBimNameSpaces::listNameSpaces1()
{
    return listNameSpacesImpl(nullptr);
}

boost::python::dict PyBrxBimNameSpaces::listNameSpaces2(const PyDbDatabase& pDb)
{
    return listNameSpacesImpl(pDb.impObj());
}

bool PyBrxBimNameSpaces::hasNameSpace1(const std::string& szNameOrLabel)
{
   return BimNameSpaces::hasNameSpace(utf8_to_wstr(szNameOrLabel).c_str()) == eOk;
}

bool PyBrxBimNameSpaces::hasNameSpace2(const std::string& szNameOrLabel, PyDbDatabase& pDb)
{
    return BimNameSpaces::hasNameSpace(utf8_to_wstr(szNameOrLabel).c_str(), pDb.impObj()) == eOk;
}

bool PyBrxBimNameSpaces::getIsNameSpaceVisible1(const std::string& szNameOrLabel)
{
    bool visible = false;
    PyThrowBadBim(BimNameSpaces::getIsNameSpaceVisible(visible, utf8_to_wstr(szNameOrLabel).c_str()));
    return visible;
}

bool PyBrxBimNameSpaces::getIsNameSpaceVisible2(const std::string& szNameOrLabel, PyDbDatabase& pDb)
{
    bool visible = false;
    PyThrowBadBim(BimNameSpaces::getIsNameSpaceVisible(visible, utf8_to_wstr(szNameOrLabel).c_str(), pDb.impObj()));
    return visible;
}

void PyBrxBimNameSpaces::setIsNameSpaceVisible1(bool visible, const std::string& szNameOrLabel)
{
    PyThrowBadBim(BimNameSpaces::setIsNameSpaceVisible(visible, utf8_to_wstr(szNameOrLabel).c_str()));
}

void PyBrxBimNameSpaces::setIsNameSpaceVisible2(bool visible, const std::string& szNameOrLabel, PyDbDatabase& pDb)
{
    PyThrowBadBim(BimNameSpaces::setIsNameSpaceVisible(visible, utf8_to_wstr(szNameOrLabel).c_str(), pDb.impObj()));
}

void PyBrxBimNameSpaces::createNameSpace1(const std::string& szName)
{
    PyThrowBadBim(BimNameSpaces::createNameSpace(utf8_to_wstr(szName).c_str()));
}

void PyBrxBimNameSpaces::createNameSpace2(const std::string& szName, const std::string& szLabel, bool visible, PyDbDatabase& pDb)
{
    PyThrowBadBim(BimNameSpaces::createNameSpace(utf8_to_wstr(szName).c_str(), utf8_to_wstr(szLabel).c_str(),visible,pDb.impObj()));
}

void PyBrxBimNameSpaces::deleteNameSpace1(const std::string& szNameOrLabel)
{
    PyThrowBadBim(BimNameSpaces::deleteNameSpace(utf8_to_wstr(szNameOrLabel).c_str()));
}

void PyBrxBimNameSpaces::deleteNameSpace2(const std::string& szNameOrLabel, PyDbDatabase& pDb)
{
    PyThrowBadBim(BimNameSpaces::deleteNameSpace(utf8_to_wstr(szNameOrLabel).c_str(), pDb.impObj()));
}

std::string PyBrxBimNameSpaces::getNameSpaceLabel1(const std::string szName)
{
    AcString val;
    PyThrowBadBim(BimNameSpaces::getNameSpaceLabel(val, utf8_to_wstr(szName).c_str()));
    return wstr_to_utf8(val);
}

std::string PyBrxBimNameSpaces::getNameSpaceLabel2(const std::string szName, PyDbDatabase& pDb)
{
    AcString val;
    PyThrowBadBim(BimNameSpaces::getNameSpaceLabel(val, utf8_to_wstr(szName).c_str(), pDb.impObj()));
    return wstr_to_utf8(val);
}

void PyBrxBimNameSpaces::setNameSpaceLabel1(const std::string& szName, const std::string& szLabel)
{
    PyThrowBadBim(BimNameSpaces::setNameSpaceLabel(utf8_to_wstr(szName).c_str(), utf8_to_wstr(szLabel).c_str()));
}

void PyBrxBimNameSpaces::setNameSpaceLabel2(const std::string& szName, const std::string& szLabel, PyDbDatabase& pDb)
{
    PyThrowBadBim(BimNameSpaces::setNameSpaceLabel(utf8_to_wstr(szName).c_str(), utf8_to_wstr(szLabel).c_str(),pDb.impObj()));
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
//PyBrxBimPropertySets
void makePyBrxBimPropertySetsWrapper()
{
    PyDocString DS("PyBrxBimPropertySets");
    class_<PyBrxBimPropertySets>("PyBrxBimPropertySets")
        .def(init<>())
        .def("className", &PyBrxBimPropertySets::className, DS.SARGS()).staticmethod("className")
        ;
}

PyBrxBimPropertySets::PyBrxBimPropertySets()
    : PyBrxBimPropertySets(new BimPropertySets(), true)
{
}

PyBrxBimPropertySets::PyBrxBimPropertySets(const BimPropertySets* ptr)
    :PyBrxBimPropertySets(const_cast<BimPropertySets*>(ptr), false)
{
}

PyBrxBimPropertySets::PyBrxBimPropertySets(BimPropertySets* pObject, bool autoDelete)
    : m_pyImp(pObject, PySharedObjectDeleter<BimPropertySets>(autoDelete))
{
}

std::string PyBrxBimPropertySets::className()
{
    return "PyBrxBimPropertySets";
}

BimPropertySets* PyBrxBimPropertySets::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<BimPropertySets*>(m_pyImp.get());
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
