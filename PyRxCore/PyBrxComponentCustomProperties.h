#pragma once
#ifdef BRXAPP

#include "AcComponentCustomProperties.h"
#include "AcComponents.h"


class PyBrxMechanicalPropertyDefinition;

//---------------------------------------------------------------------
//PyBrxMechanicalPropertySet
void makePyBrxMechanicalPropertySet();

class PyBrxMechanicalPropertySet
{
public:
    PyBrxMechanicalPropertySet() = default;
    PyBrxMechanicalPropertySet(const BrxMechanicalPropertySet& other);
    ~PyBrxMechanicalPropertySet() = default;

    bool            isNull() const;
    std::string     categoryName() const;
    bool            isPerInstance() const;
    std::string     categoryLabel() const;

    boost::python::list                getAllCustomProperties() const;
    PyBrxMechanicalPropertyDefinition  getPropertyByName(const std::string& propertyName) const;
    PyBrxMechanicalPropertyDefinition  addProperty1(const std::string& propertyName, BrxMechanicalPropertyType type);
    PyBrxMechanicalPropertyDefinition  addProperty2(const std::string& propertyName, BrxMechanicalPropertyType type, const std::string& label);

    static boost::python::list         getAllCategories(const PyDbDatabase& pDb);
    static PyBrxMechanicalPropertySet  getCategoryByName(const PyDbDatabase& pDb, const std::string& categoryName);
    static PyBrxMechanicalPropertySet  createCategory1(const PyDbDatabase& pDb, const std::string& categoryName);
    static PyBrxMechanicalPropertySet  createCategory2(const PyDbDatabase& pDb, const std::string& categoryName, bool isPerInstance);
    static PyBrxMechanicalPropertySet  createCategory3(const PyDbDatabase& pDb, const std::string& categoryName, bool isPerInstance, const std::string& label);
    static std::string className();
public:
    BrxMechanicalPropertySet m_impl;
};

//---------------------------------------------------------------------
//PyBrxMechanicalPropertyDefinition
void makePyBrxMechanicalPropertyDefinition();

class PyBrxMechanicalPropertyDefinition
{
public:
    PyBrxMechanicalPropertyDefinition() = default;
    PyBrxMechanicalPropertyDefinition(const BrxMechanicalPropertyDefinition& other);
    ~PyBrxMechanicalPropertyDefinition() = default;

    bool                        isNull() const;
    bool                        doesExist() const;
    std::string                 name() const;
    std::string                 label() const;
    BrxMechanicalPropertyType   type() const;
    boost::python::list         enumValues() const;
    void                        setLabel(const std::string& newLabel);
    void                        setType(BrxMechanicalPropertyType newTypeName);
    void                        setEnumValues(const boost::python::list& aNewEnumValues);
    static std::string          className();

private:
    BrxMechanicalPropertyDefinition m_impl;
};
#endif