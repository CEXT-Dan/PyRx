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

#endif//BRXAPP
