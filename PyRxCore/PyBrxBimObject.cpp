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
        .def("deleteStory", &PyBrxBimBuilding::typeDesc, DS.ARGS())
        .def("typeName", &PyBrxBimBuilding::typeName, DS.ARGS())
        .def("createBuilding", &PyBrxBimBuilding::createBuilding, DS.ARGS({ "name: str", "db: PyDb.Database" }))
        .def("createBuilding", &PyBrxBimBuilding::deleteBuilding, DS.ARGS({ "db: PyDb.Database" }))
        .def("isNull", &PyBrxBimBuilding::isNull, DS.ARGS())
        .def("setNull", &PyBrxBimBuilding::setNull, DS.ARGS())
        .def("createStory", &PyBrxBimBuilding::createBuilding, DS.ARGS({ "name: str" }))
        .def("deleteStory", &PyBrxBimBuilding::deleteStory1, DS.ARGS({ "story: str | PyBrxBim.BimStory" }))
        .def("deleteStory", &PyBrxBimBuilding::deleteStory2, DS.ARGS({ "story: str | PyBrxBim.BimStory" }))
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
        .def("allObjectStoriesFromDb", &PyBrxBimBuilding::allObjectStoriesFromDb1)
        .def("allObjectStoriesFromDb", &PyBrxBimBuilding::allObjectStoriesFromDb2, DS.SARGS({ "db: PyDb.Database","building: str = None" })).staticmethod("allObjectStoriesFromDb")
        .def("allStringStoriesFromDb", &PyBrxBimBuilding::allStringStoriesFromDb1)
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
        "- id: PyDb.Database\n";
    "- val: PyBrxBim.BimStory";
    "- val: PyBrxBim.BimStory", "id: PyDb.Database\n";
    "- val: PyBrxBim.BimBuilding";
    "- val: PyBrxBim.BimBuilding", "id: PyDb.Database\n";

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
    PyDocString DS("BimSpace");
    class_<PyBrxBimSpace>("BimSpace")
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
    PyThrowBadBim(BrxBimSpace::getSpaceEntity(id.m_id,utf8_to_wstr(spaceName).c_str()));
    return id;
}

PyDbObjectId PyBrxBimSpace::getSpaceEntity2(const std::string& spaceName, const PyDbDatabase& pDb)
{
    PyDbObjectId id;
    PyThrowBadBim(BrxBimSpace::getSpaceEntity(id.m_id, utf8_to_wstr(spaceName).c_str(), pDb.impObj()));
    return id;
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
    PyDocString DS("BimClassification");
    class_<PyBrxBimClassification>("BimClassification")
        .def(init<>())
        .def("getName", &PyBrxBimClassification::getName).staticmethod("getName")
        .def("isClassifiedAsAnyBuildingElement", &PyBrxBimClassification::isClassifiedAsAnyBuildingElement).staticmethod("isClassifiedAsAnyBuildingElement")
        .def("getClassification", &PyBrxBimClassification::getClassification).staticmethod("getClassification")
        .def("getPropertyNames", &PyBrxBimClassification::getPropertyNames).staticmethod("getPropertyNames")
        .def("getPropertyDict", &PyBrxBimClassification::getPropertyDict).staticmethod("getPropertyDict")
        .def("getProperty", &PyBrxBimClassification::getProperty).staticmethod("getProperty")
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

bool PyBrxBimClassification::isClassifiedAsAnyBuildingElement(const PyDbObjectId& id)
{
    return BimClassification::isClassifiedAsAnyBuildingElement(id.m_id);
}

BimApi::BimElementType PyBrxBimClassification::getClassification(const PyDbObjectId& id)
{
    BimApi::BimElementType bimtype;
    PyThrowBadBim(BimClassification::getClassification(bimtype, id.m_id));
    return bimtype;
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

PyDbAcValue PyBrxBimClassification::getProperty(const PyDbObjectId& id, const std::string& szPropertyName, const std::string& category)
{
    AcValue propertyValue;
    PyThrowBadBim(BimClassification::getProperty(propertyValue, id.m_id, utf8_to_wstr(szPropertyName).c_str(), utf8_to_wstr(category).c_str()));
    return PyDbAcValue{ propertyValue };
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
