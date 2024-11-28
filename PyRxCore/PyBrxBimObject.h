#pragma once

#ifdef BRXAPP
class PyDbDatabase;
class PyDbObjectId;
class PyBrxBimBuilding;
class PyBrxBimHatchPattern;
class PyGePlane;
class PyDbAcValue;
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

    BimApi::BimObjectType   typeDesc() const;
    std::string             typeName() const;
    bool                    isNull() const;
    void                    setNull();
    std::string             name() const;
    void                    setName(const std::string& szNewName) const;
    std::string             description() const;
    void                    setDescription(const std::string& szInfo) const;

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
void makeBrxBimStoryWrapper();
class PyBrxBimStory : public PyBrxBimSpatialLocation
{
public:
    PyBrxBimStory();
    PyBrxBimStory(const BrxBimStory* ptr);
    PyBrxBimStory(const BrxBimStory& r);
    PyBrxBimStory(BrxBimStory* pObject, bool autoDelete);
    virtual ~PyBrxBimStory() override = default;

    bool                isNull() const;
    void                setNull();
    std::string         name() const;
    std::string         longName() const;
    void                setName(const std::string& szNewName) const;
    void                setLongName(const std::string& szLongName) const;
    std::string         description() const;
    void                setDescription(const std::string& szInfo) const;
    boost::python::list assignedObjects(const PyDbDatabase& database) const;
    void                assignToEntity(const PyDbObjectId& id) const;

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
    void                    setName(const std::string& szNewName) const;
    void                    setRoomName(const std::string& szNewName) const;
    void                    setRoomNumber(const std::string& szNewNumber) const;
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

    static void                 unassignLocationS(const PyDbObjectId& id);

    static boost::python::list  getAllRooms1();
    static boost::python::list  getAllRooms2(const PyDbDatabase& pDb);
    static boost::python::list  getAllRooms3(const PyBrxBimStory& story);
    static boost::python::list  getAllRooms4(const PyBrxBimStory& story, const PyDbDatabase& pDb);
    static boost::python::list  getAllRooms5(const PyBrxBimBuilding& story);
    static boost::python::list  getAllRooms6(const PyBrxBimBuilding& story, const PyDbDatabase& pDb);

    static bool                 isAssociativeRoomS(const PyDbObjectId& id);
    static void                 updateAssociativeRoomS(const PyDbObjectId& id);
    static boost::python::list  getBoundingElementsS(const PyDbObjectId& id);
    static boost::python::list  getOpeningsS(const PyDbObjectId& id);
    static PyDbObjectId         getRoomEntityS(const PyBrxBimRoom& bimRoom);
    static std::string          roomIdentS(const PyDbObjectId& id);
    static std::string          roomNameS(const PyDbObjectId& id);
    static void                 setRoomNameS(const PyDbObjectId& id, const std::string& szNewName);
    static std::string          roomNumberS(const PyDbObjectId& id);
    static void                 setRoomNumberS(const PyDbObjectId& id, const std::string& szNewNumber);
    static std::string          descriptionS(const PyDbObjectId& id);
    static void                 setDescriptionS(const PyDbObjectId& id, const std::string& szInfo);
    static double               roomAreaS(const PyDbObjectId& id);
    static std::string          getRoomRepresentationS(const PyDbObjectId& id);
    static void                 setRoomRepresentationS(const PyDbObjectId& id, const std::string& representation);
    static std::string          getRoomDepartmentS(const PyDbObjectId& id);
    static void                 setRoomDepartmentS(const PyDbObjectId& id, const std::string& department);

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
    static PyDbObjectId         createSpace(const AcGePoint3d& pickPt);
    static bool                 isSpaceValid(const PyDbObjectId& spaceId);
    static bool                 isSpaceUpdated(const PyDbObjectId& spaceId);
    static PyDbObjectId         getSpaceEntity1(const std::string& spaceName);
    static PyDbObjectId         getSpaceEntity2(const std::string& spaceName, const PyDbDatabase& pDb);
    static void                 updateSpace(const PyDbObjectId& spaceId);
    static boost::python::list  getBoundingElements(const PyDbObjectId& spaceId);
    static std::string          getSpaceNumber(const PyDbObjectId& spaceId);
    static void                 setSpaceNumber(const PyDbObjectId& spaceId, const std::string& numberStr);
    static double               getSpaceArea(const PyDbObjectId& spaceId);

    static EBimSpaceRepresentation  getSpaceRepresentation(const PyDbObjectId& spaceId);
    static void                     setSpaceRepresentation(const PyDbObjectId& spaceId, EBimSpaceRepresentation  representation);

    static boost::python::list  getAllSpaces1();
    static boost::python::list  getAllSpaces2(const PyDbDatabase& pDb);
    static boost::python::list  getAllSpaces3(const PyBrxBimBuilding& building);
    static boost::python::list  getAllSpaces4(const PyBrxBimBuilding& building, const PyDbDatabase& pDb);
    static boost::python::list  getAllSpaces5(const PyBrxBimStory& story);
    static boost::python::list  getAllSpaces6(const PyBrxBimStory& story, const PyDbDatabase& pDb);
    static void                 assignToBuilding(const PyDbObjectId& spaceId, const PyBrxBimBuilding& building);
    static void                 assignToStory(const PyDbObjectId& spaceId, const PyBrxBimStory& story);


    static std::string          getSpaceName(const PyDbObjectId& spaceId);
    static void                 setSpaceName(const PyDbObjectId& spaceId, const std::string& spaceName);

    static boost::python::tuple getAssignedSpace(const PyDbObjectId& entityId);
    static void                 setAssignedSpace1(const PyDbObjectId& entityId, const PyDbObjectId& spaceId);
    static void                 setAssignedSpace2(const PyDbObjectId& entityId, const std::string& spaceName);

    static  boost::python::list getAssignedEntities1(const PyDbObjectId& spaceId);
    static  boost::python::list getAssignedEntities2(const std::string& spaceName);
    static  boost::python::list getAssignedEntities3(const std::string& spaceName, const PyDbDatabase& pDb);

    static std::string      className();
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

    virtual std::string comments() const;
    virtual std::string appearance() const;
    virtual PyBrxBimHatchPattern cutPattern() const;
    virtual PyBrxBimHatchPattern surfacePattern() const;

    //
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
    PyBrxBimHatchPattern(double scaleOrSpacing, double angle, bool cross);
    PyBrxBimHatchPattern(BrxBimMaterial::EHatchType type, const std::string& name, double scaleOrSpacing, double angle);

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

    static std::string  getName(const PyDbObjectId& id);
    static void         setName(const PyDbObjectId& id, const std::string& szName);
    static std::string  getDescription(const PyDbObjectId& id);
    static void         setDescription(const PyDbObjectId& id, const std::string& szDescription);
    static std::string  getGUID(const PyDbObjectId& id);

    static void         classifyAs1(const PyDbObjectId& id, const BimApi::BimElementType objectType);
    static void         classifyAs2(const PyDbObjectId& id, const std::string& typeName);
    static void         classifyAs3(const PyDbObjectId& id, const std::string& typeName, bool localName);
    static void         classifyAs4(const  PyDbDatabase& database, const BimApi::BimElementType objectType);

    static void         unClassify1(const PyDbObjectId& id);
    static void         unClassify2(const PyDbDatabase& database);

    static bool         isClassifiedAs1(const PyDbObjectId& id, const BimApi::BimElementType objectType);
    static bool         isClassifiedAs2(const PyDbObjectId& id, const std::string& typeName);
    static bool         isClassifiedAs3(const PyDbObjectId& id, const std::string& typeName, bool localName);
    static bool         isClassifiedAs4(const PyDbDatabase& database, const BimApi::BimElementType objectType);

    static bool         isClassified(const PyDbDatabase& database);

    static bool         isClassifiedAsAnyBuildingElement(const PyDbObjectId& id);
    static bool         isUnclassified(const PyDbObjectId& id);

    static BimApi::BimElementType   getClassification1(const PyDbObjectId& id);
    static BimApi::BimElementType   getClassification2(const PyDbDatabase& database);

    static std::string  getClassificationName1(const PyDbObjectId& id);
    static std::string  getClassificationName2(const PyDbObjectId& id, bool localName);

    static boost::python::list getPropertyNames(const PyDbObjectId& id);
    static boost::python::dict getPropertyDict(const PyDbObjectId& id);

    static bool         hasProperty1(const PyDbObjectId& id, const std::string& szName);
    static bool         hasProperty2(const PyDbObjectId& id, const std::string& szName, const EBimCategory category);
    static bool         hasProperty3(const PyDbObjectId& id, const std::string& szPropertyName, const std::string& category);

    static bool         deleteProperty1(const PyDbObjectId& id, const std::string& szName);
    static bool         deleteProperty2(const PyDbObjectId& id, const std::string& szName, const EBimCategory category);
    static bool         deleteProperty3(const PyDbObjectId& id, const std::string& szPropertyName, const std::string& category);

    static PyDbAcValue  getProperty1(const PyDbObjectId& id, const std::string& szName);
    static PyDbAcValue  getProperty2(const PyDbObjectId& id, const std::string& szName, const EBimCategory category);
    static PyDbAcValue  getProperty3(const PyDbObjectId& id, const std::string& szPropertyName, const std::string& category);

    static void         setProperty1(const PyDbObjectId& id, const std::string& szName, const PyDbAcValue& val);
    static void         setProperty2(const PyDbObjectId& id, const std::string& szName, const PyDbAcValue& val, const EBimCategory category);
    static void         setProperty3(const PyDbObjectId& id, const std::string& szPropertyName, const PyDbAcValue& val, const std::string& category);

    static boost::python::list getAllClassified(const PyDbDatabase& database);
    static boost::python::list getAllClassifiedAs(const BimApi::BimElementType objectType, const PyDbDatabase& database);
    static boost::python::list getAllClassifiedAsName1(const std::string& typeName, const PyDbDatabase& database);
    static boost::python::list getAllClassifiedAsName2(const std::string& typeName, const PyDbDatabase& database, bool localName);
    static boost::python::list getAllUnclassified(const PyDbDatabase& database);

    static boost::python::list getAllUsedClassifications(const  PyDbDatabase& database);
    static boost::python::list getAllUsedClassificationNames1(const PyDbDatabase& database);
    static boost::python::list getAllUsedClassificationNames2(const PyDbDatabase& database, bool localNames);

    static boost::python::list getBimTypeNames1();
    static boost::python::list getBimTypeNames2(bool localNames);



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
void makePyBrxBimPropertySetsWrapper();
class PyBrxBimPropertySets
{
public:
    PyBrxBimPropertySets();
    PyBrxBimPropertySets(const BimPropertySets* ptr);
    PyBrxBimPropertySets(BimPropertySets* pObject, bool autoDelete);
    virtual ~PyBrxBimPropertySets() = default;
    static std::string  className();
public:
    BimPropertySets* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<BimPropertySets> m_pyImp;
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
