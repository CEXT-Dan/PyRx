#pragma once

#ifdef BRXAPP
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
    PyBrxBimObject(const BrxBimObject* ptr);
    PyBrxBimObject(BrxBimObject* pObject, bool autoDelete);
    virtual ~PyBrxBimObject() = default;

    BimApi::BimObjectType   typeDesc();
    std::string             typeName();
    bool                    isNull() const;
    void                    setNull();
    std::string             name() const;
    std::string             description() const;
    BimApi::ResultStatus    setName(const std::string& szNewName) const;
    BimApi::ResultStatus    setDescription(const std::string& szInfo) const;
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


#endif//BRXAPP
