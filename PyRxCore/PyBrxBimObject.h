#pragma once

#ifdef BRXAPP
class PyDbDatabase;
class PyDbObjectId;

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

    static PyBrxBimRoom  cast(const PyBrxBimObject& src);
    static std::string   className();

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
//PyPyBrxBimAssets
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


#endif//BRXAPP
