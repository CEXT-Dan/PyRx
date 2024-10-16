#pragma once

#ifdef BRXAPP
class PyDbDatabase;
class PyDbObjectId;
class PyBrxBimBuilding;
class PyGePlane;
#include "BuildingElements.h"

//---------------------------------------------------------------------------------------- -
//PyBrxBimPolicies
void makePyBrxBimPoliciesWrapper();
class PyBrxBimPolicies
{
public:
    static void setPolicy(BrxBimPolicies::EPolicyOptions option, bool enable);
    static bool getPolicy(BrxBimPolicies::EPolicyOptions option);
    static std::string className();
};

//---------------------------------------------------------------------------------------- -
//PyBrxBimObject
void makePyBrxBimObjectWrapper();
class PyBrxBimObject
{
public:
    PyBrxBimObject(const BrxBimObject* pObject);
    PyBrxBimObject(BrxBimObject* pObject, bool autoDelete);
    virtual ~PyBrxBimObject() = default;

    BimApi::BimObjectType   typeDesc();
    std::string             typeName();
    bool                    isNull() const;
    void                    setNull();
    std::string             name() const;
    std::string             description() const;
    void                    setName(const std::string& szNewName) const;
    void                    setDescription(const std::string& szInfo) const;
    static PyBrxBimObject   cast(const PyBrxBimObject& src);
    static std::string      className();

public:
    BrxBimObject* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<BrxBimObject> m_pyImp;
};

template<typename T>
inline T PyBrxBimObjectCast(const PyBrxBimObject& src)
{
    T dest(nullptr, false);
    PyBrxBimObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

//---------------------------------------------------------------------------------------- -
//PyBrxBimSpatialLocation
void makePyBrxBimSpatialLocationWrapper();
class PyBrxBimSpatialLocation : public PyBrxBimObject
{
    //TODO check if other constructors are useful 
public:
    PyBrxBimSpatialLocation();
    PyBrxBimSpatialLocation(const BrxBimSpatialLocation* ptr);
    PyBrxBimSpatialLocation(const BrxBimSpatialLocation& r);
    PyBrxBimSpatialLocation(BrxBimSpatialLocation* pObject, bool autoDelete);
    virtual ~PyBrxBimSpatialLocation() override = default;

    std::string             longName() const;
    void                    setLongName(const std::string& szLongName) const;
    bool                    isStory()    const;
    bool                    isBuilding() const;
    bool                    hasStory()    const;
    bool                    hasBuilding() const;
    boost::python::list     assignedObjects(const PyDbDatabase& database) const;
    void                    assignToEntity(const PyDbObjectId& id) const;

    static PyBrxBimSpatialLocation  assignedSpatialLocation(const PyDbObjectId& id);
    static void                     removeSpatialLocationFrom(const PyDbObjectId& id);
    static PyBrxBimSpatialLocation  cast(const PyBrxBimObject& src);
    static std::string              className();

public:
    BrxBimSpatialLocation* impObj(const std::source_location& src = std::source_location::current()) const;
};

//---------------------------------------------------------------------------------------- -
//PyBrxBimStory
void makeBrxBimStorynWrapper();
class PyBrxBimStory : public PyBrxBimSpatialLocation
{
public:
    PyBrxBimStory();
    PyBrxBimStory(const BrxBimStory* ptr);
    PyBrxBimStory(const BrxBimStory& r);
    PyBrxBimStory(BrxBimStory* pObject, bool autoDelete);
    virtual ~PyBrxBimStory() override = default;

    void                createStory(const std::string& szName, const PyBrxBimBuilding& building);
    void                deleteStory();
    double              elevation() const;
    virtual void        setElevation(double elevation) const;
    PyBrxBimBuilding    getBuilding() const;

    static PyBrxBimStory  createNewStory(const PyDbDatabase& database, const std::string& buildingName, const std::string& storyName);
    static void           deleteStoryFromDatabase(const PyDbDatabase& database, const std::string& buildingName, const std::string& storyName);
    static PyBrxBimStory  getStory(const PyDbDatabase& database, const std::string& buildingName, const std::string& storyName);
    static PyBrxBimStory  assignedStory(const PyDbObjectId& id);

    static boost::python::list allStories(const PyDbDatabase& database);
    static boost::python::list allStoryNames(const PyDbDatabase& database);

    static PyBrxBimStory  cast(const PyBrxBimObject& src);
    static std::string    className();

public:
    BrxBimStory* impObj(const std::source_location& src = std::source_location::current()) const;
};

//---------------------------------------------------------------------------------------- -
//PyBrxBimBuilding
void makeBrxBimBuildingWrapper();
class PyBrxBimBuilding : public PyBrxBimSpatialLocation
{
public:
    PyBrxBimBuilding();
    PyBrxBimBuilding(const BrxBimBuilding* ptr);
    PyBrxBimBuilding(const BrxBimBuilding& r);
    PyBrxBimBuilding(BrxBimBuilding* pObject, bool autoDelete);
    virtual ~PyBrxBimBuilding() override = default;

    BimApi::BimObjectType   typeDesc() const;
    std::string             typeName() const;
    void                    createBuilding(const std::string& szName, const PyDbDatabase& database);
    void                    deleteBuilding(const PyDbDatabase& database);
    bool                    isNull() const;
    void                    setNull();
    PyBrxBimStory           createStory(const std::string& storyName) const;
    void                    deleteStory1(const std::string& storyName) const;
    void                    deleteStory2(PyBrxBimStory& story) const;
    std::string             name() const;
    std::string             longName() const;
    void                    setName(const std::string& szNewName) const;
    void                    setLongName(const std::string& szLongName) const;
    std::string             description() const;
    void                    setDescription(const std::string& szInfo) const;
    PyBrxBimStory           getStory(const std::string& storyName) const;
    boost::python::list     allObjectStories() const;
    boost::python::list     allStringStories() const;
    boost::python::list     assignedObjects(const PyDbDatabase& database) const;
    void                    assignToEntity(const PyDbObjectId& id) const;

    static PyBrxBimBuilding createNewBuilding(const PyDbDatabase& database, const std::string& name);
    static void             deleteBuildingFromDb(const PyDbDatabase& database, const std::string& buildingName);
    static void             assignedBuilding(PyBrxBimBuilding& building, const PyDbObjectId& id);
    static PyBrxBimBuilding getBuilding(const  PyDbDatabase& database, const std::string& buildingName);
    static boost::python::list allObjectBuildings(const PyDbDatabase& database);
    static boost::python::list allStringBuildings(const PyDbDatabase& database);
    static boost::python::list allObjectStoriesFromDb1(const PyDbDatabase& database);
    static boost::python::list allObjectStoriesFromDb2(const PyDbDatabase& database, const std::string& building);
    static boost::python::list allStringStoriesFromDb1(const PyDbDatabase& database);
    static boost::python::list allStringStoriesFromDb2(const PyDbDatabase& database, const std::string& building);
    static PyBrxBimBuilding  cast(const PyBrxBimObject& src);
    static std::string       className();

public:
    BrxBimBuilding* impObj(const std::source_location& src = std::source_location::current()) const;
};

//---------------------------------------------------------------------------------------- -
//PyBrxBimRoom
void makeBrxBimRoomWrapper();
class PyBrxBimRoom : public PyBrxBimObject
{
public:
    PyBrxBimRoom();
    PyBrxBimRoom(const PyDbObjectId& id);
    PyBrxBimRoom(const BrxBimRoom& r);
    PyBrxBimRoom(const BrxBimRoom* ptr);
    PyBrxBimRoom(BrxBimRoom* pObject, bool autoDelete);
    virtual ~PyBrxBimRoom() override = default;

    BimApi::BimObjectType   typeDesc() const;
    std::string             typeName() const;
    bool                    isRoomValid() const;
    PyDbObjectId            createAssociativeRoom(const AcGePoint3d& insidePoint, const PyGePlane& basePlane);
    PyDbObjectId            createNonAssociativeRoom(const PyDbObjectId& entityId);
    void                    updateAssociativeRoom();
    bool                    isAssociativeRoom() const;
    boost::python::list     getBoundingElements() const;
    boost::python::list     getOpenings() const;
    PyDbObjectId            getRoomEntity() const;
    PyDbObjectId            getId() const;
    void                    setId(const PyDbObjectId& id);
    bool                    isNull() const;
    void                    setNull();
    std::string             roomIdent() const;
    std::string             name() const;
    std::string             roomName() const;
    std::string             roomNumber() const;
    void                    setName(const std::string&  szNewName) const;
    void                    setRoomName(const std::string&  szNewName) const;
    void                    setRoomNumber(const std::string&  szNewNumber) const;
    std::string             description() const;
    void                    setDescription(const std::string& szInfo) const;
    double                  roomArea() const;
    std::string             getRoomRepresentation() const;
    void                    setRoomRepresentation(const std::string& representation);
    std::string             getRoomDepartment() const;
    void                    setRoomDepartment(const std::string& department);
    void                    assignToStory(const PyBrxBimStory& story);
    void                    assignToBuilding(const PyBrxBimBuilding& building);
    PyBrxBimSpatialLocation getAssignedLocation() const;
    PyBrxBimStory           getAssignedStory() const;
    PyBrxBimBuilding        getAssignedBuilding() const;
    void                    unassignLocation();

    static bool             isRoomValidS(const PyDbObjectId& id);
    static PyDbObjectId     buildAssociativeRoomS(const AcGePoint3d& insidePoint, const PyGePlane& basePlane);
    static PyDbObjectId     buildNonAssociativeRoomS(const PyDbObjectId& id);

    static void             assignToStoryS(const PyDbObjectId& id, const PyBrxBimStory& story);
    static void             assignToBuildingS(const PyDbObjectId& id, const PyBrxBimBuilding& building);

    static PyBrxBimSpatialLocation  getAssignedLocationS(const PyDbObjectId& id);
    static PyBrxBimStory            getAssignedStoryS(const PyDbObjectId& id);
    static PyBrxBimBuilding         getAssignedBuildingS(const PyDbObjectId& id);

    static void             unassignLocationS(const PyDbObjectId& id);

    static boost::python::list getAllRooms1();
    static boost::python::list getAllRooms2(const PyDbDatabase& pDb);

    static boost::python::list getAllRooms3(const PyBrxBimStory& story);
    static boost::python::list getAllRooms4(const PyBrxBimStory& story, const PyDbDatabase& pDb);

    static boost::python::list getAllRooms5(const BrxBimBuilding& story);
    static boost::python::list getAllRooms6(const BrxBimBuilding& story, const PyDbDatabase& pDb);


    static PyBrxBimRoom     cast(const PyBrxBimObject& src);
    static std::string      className();

public:
    BrxBimRoom* impObj(const std::source_location& src = std::source_location::current()) const;
};

//---------------------------------------------------------------------------------------- -
//PyBrxBimSpace
void makeBrxBimSpaceWrapper();

class PyBrxBimSpace
{
public:
    static std::string  className();
};

//---------------------------------------------------------------------------------------- -
//PyBrxBimMaterial
void makeBrxBimMaterialWrapper();
class PyBrxBimMaterial : public PyBrxBimObject
{
public:
    PyBrxBimMaterial();
    PyBrxBimMaterial(const std::string& id);
    PyBrxBimMaterial(const BrxBimMaterial& r);
    PyBrxBimMaterial(const BrxBimMaterial* ptr);
    PyBrxBimMaterial(BrxBimMaterial* pObject, bool autoDelete);
    virtual ~PyBrxBimMaterial() override = default;
    static PyBrxBimMaterial  cast(const PyBrxBimObject& src);
    static std::string       className();

public:
    BrxBimMaterial* impObj(const std::source_location& src = std::source_location::current()) const;
};

//---------------------------------------------------------------------------------------- -
//PyBrxBimHatchPattern
void makeBrxBimHatchPatternWrapper();
class PyBrxBimHatchPattern
{
public:
    PyBrxBimHatchPattern();
    PyBrxBimHatchPattern(double scaleOrSpacing, double angle = 0.0, bool cross = false);
    PyBrxBimHatchPattern(BrxBimMaterial::EHatchType type, const std::string& name, double scaleOrSpacing = 1.0, double angle = 0.0);

    PyBrxBimHatchPattern(const BrxBimMaterial::HatchPattern& r);
    PyBrxBimHatchPattern(const BrxBimMaterial::HatchPattern* ptr);
    PyBrxBimHatchPattern(BrxBimMaterial::HatchPattern* pObject, bool autoDelete);
    virtual ~PyBrxBimHatchPattern() = default;

    static std::string  className();
public:
    BrxBimMaterial::HatchPattern* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<BrxBimMaterial::HatchPattern> m_pyImp;
};

//---------------------------------------------------------------------------------------- -
//PyBrxBimInformationalAssets
void makeBrxBimInformationalAssetsWrapper();
class PyBrxBimInformationalAssets
{
public:
    PyBrxBimInformationalAssets(const BrxBimMaterial::InformationalAssets& r);
    PyBrxBimInformationalAssets(const BrxBimMaterial::InformationalAssets* ptr);
    PyBrxBimInformationalAssets(BrxBimMaterial::InformationalAssets* pObject, bool autoDelete);
    virtual ~PyBrxBimInformationalAssets() = default;
    static std::string  className();
public:
    BrxBimMaterial::InformationalAssets* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<BrxBimMaterial::InformationalAssets> m_pyImp;
};

//---------------------------------------------------------------------------------------- -
//PyBrxBimPhysicalAssets
void makeBrxBimPhysicalAssetsWrapper();
class PyBrxBimPhysicalAssets
{
public:
    PyBrxBimPhysicalAssets(const BrxBimMaterial::PhysicalAssets& r);
    PyBrxBimPhysicalAssets(const BrxBimMaterial::PhysicalAssets* ptr);
    PyBrxBimPhysicalAssets(BrxBimMaterial::PhysicalAssets* pObject, bool autoDelete);
    virtual ~PyBrxBimPhysicalAssets() = default;
    static std::string  className();
public:
    BrxBimMaterial::PhysicalAssets* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<BrxBimMaterial::PhysicalAssets> m_pyImp;
};

//---------------------------------------------------------------------------------------- -
//PyBrxBimAssets
void makeBrxBimAssetsWrapper();
class PyBrxBimAssets
{
public:
    PyBrxBimAssets(const BrxBimMaterial::BimAssets& r);
    PyBrxBimAssets(const BrxBimMaterial::BimAssets* ptr);
    PyBrxBimAssets(BrxBimMaterial::BimAssets* pObject, bool autoDelete);
    virtual ~PyBrxBimAssets() = default;
    static std::string  className();
public:
    BrxBimMaterial::BimAssets* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<BrxBimMaterial::BimAssets> m_pyImp;
};

//---------------------------------------------------------------------------------------- -
//PyBrxBimPly
void makeBrxBimPlyWrapper();
class PyBrxBimPly : public PyBrxBimObject
{
public:
    PyBrxBimPly();
    PyBrxBimPly(const PyBrxBimMaterial& material, EMaterialFunction function = eNone, double thickness = 1.0);
    PyBrxBimPly(const BrxBimPly& r);
    PyBrxBimPly(const BrxBimPly* ptr);
    PyBrxBimPly(BrxBimPly* pObject, bool autoDelete);
    virtual ~PyBrxBimPly() override = default;
    static PyBrxBimPly       cast(const PyBrxBimObject& src);
    static std::string       className();

public:
    BrxBimPly* impObj(const std::source_location& src = std::source_location::current()) const;
};

//---------------------------------------------------------------------------------------- -
//PyBrxBimComposition
void makePyBrxBimCompositionWrapper();
class PyBrxBimComposition : public PyBrxBimObject
{
public:
    PyBrxBimComposition();
    PyBrxBimComposition(const std::string& name);
    PyBrxBimComposition(const BrxBimComposition& r);
    PyBrxBimComposition(const BrxBimComposition* ptr);
    PyBrxBimComposition(BrxBimComposition* pObject, bool autoDelete);
    virtual ~PyBrxBimComposition() override = default;
    static PyBrxBimComposition  cast(const PyBrxBimObject& src);
    static std::string          className();

public:
    BrxBimComposition* impObj(const std::source_location& src = std::source_location::current()) const;
};

//---------------------------------------------------------------------------------------- -
//PyBrxBimProfile
void makePyBrxBimProfileWrapper();
class PyBrxBimProfile
{
public:
    PyBrxBimProfile();
    PyBrxBimProfile(const PyDbObjectId& id);
    PyBrxBimProfile(const BrxBimProfile& r);
    PyBrxBimProfile(const BrxBimProfile* ptr);
    PyBrxBimProfile(BrxBimProfile* pObject, bool autoDelete);
    virtual ~PyBrxBimProfile() = default;
    static std::string  className();
public:
    BrxBimProfile* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<BrxBimProfile> m_pyImp;
};

//---------------------------------------------------------------------------------------- -
//PyBrxBimLinearGeometry
void makeBrxBimLinearGeometryWrapper();
class PyBrxBimLinearGeometry
{
public:
    PyBrxBimLinearGeometry();
    PyBrxBimLinearGeometry(const PyDbObjectId& id);
    PyBrxBimLinearGeometry(const BrxBimLinearGeometry& r);
    PyBrxBimLinearGeometry(const BrxBimLinearGeometry* ptr);
    PyBrxBimLinearGeometry(BrxBimLinearGeometry* pObject, bool autoDelete);
    virtual ~PyBrxBimLinearGeometry() = default;
    static std::string  className();
public:
    BrxBimLinearGeometry* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<BrxBimLinearGeometry> m_pyImp;
};

//---------------------------------------------------------------------------------------- -
//PyBrxBimClassification
void makeBrxBimClassificationWrapper();
class PyBrxBimClassification
{
public:
    PyBrxBimClassification();
    PyBrxBimClassification(const BimClassification* ptr);
    PyBrxBimClassification(BimClassification* pObject, bool autoDelete);
    virtual ~PyBrxBimClassification() = default;
    static std::string  className();
public:
    BimClassification* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<BimClassification> m_pyImp;
};

//---------------------------------------------------------------------------------------- -
//PyBrxBimNameSpaces
void makeBrxBimNameSpacesWrapper();
class PyBrxBimNameSpaces
{
public:
    PyBrxBimNameSpaces();
    PyBrxBimNameSpaces(const BimNameSpaces* ptr);
    PyBrxBimNameSpaces(BimNameSpaces* pObject, bool autoDelete);
    virtual ~PyBrxBimNameSpaces() = default;
    static std::string  className();
public:
    BimNameSpaces* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<BimNameSpaces> m_pyImp;
};

//---------------------------------------------------------------------------------------- -
//PyBrxBimPropertyInfo
void makePyBrxBimPropertyInfoWrapper();
class PyBrxBimPropertyInfo
{
public:
    PyBrxBimPropertyInfo();
    PyBrxBimPropertyInfo(const BimPropertyInfo* ptr);
    PyBrxBimPropertyInfo(BimPropertyInfo* pObject, bool autoDelete);
    virtual ~PyBrxBimPropertyInfo() = default;
    static std::string  className();
public:
    BimPropertyInfo* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<BimPropertyInfo> m_pyImp;
};

//---------------------------------------------------------------------------------------- -
//BrxBimAttributeSet
void makePyBrxBimAttributeSetWrapper();
class PyBrxBimAttributeSet
{
public:
    PyBrxBimAttributeSet();
    PyBrxBimAttributeSet(const BrxBimAttributeSet* ptr);
    PyBrxBimAttributeSet(BrxBimAttributeSet* pObject, bool autoDelete);
    virtual ~PyBrxBimAttributeSet() = default;
    static std::string  className();
public:
    BrxBimAttributeSet* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<BrxBimAttributeSet> m_pyImp;
};

//---------------------------------------------------------------------------------------- -
//BrxBimDialogs
void makePyBrxBimDialogsWrapper();
class PyBrxBimDialogs
{
public:
    PyBrxBimDialogs();
    PyBrxBimDialogs(const BrxBimDialogs* ptr);
    PyBrxBimDialogs(BrxBimDialogs* pObject, bool autoDelete);
    virtual ~PyBrxBimDialogs() = default;
    static std::string  className();
public:
    BrxBimDialogs* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<BrxBimDialogs> m_pyImp;
};

#endif//BRXAPP
