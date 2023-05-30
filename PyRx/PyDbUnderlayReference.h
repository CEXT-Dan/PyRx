#pragma once
#include "PyDbEntity.h"
#include "dbunderlayref.h"
#include "dbunderlaydef.h"

class PyDbObjectId;

//-----------------------------------------------------------------------------------
//PyDbUnderlayReference
void makePyDbUnderlayReferenceWrapper();

class PyDbUnderlayReference : public PyDbEntity
{
public:
    PyDbUnderlayReference(AcDbUnderlayReference* ptr, bool autoDelete);
    PyDbUnderlayReference(const PyDbObjectId& id, AcDb::OpenMode mode);
    virtual ~PyDbUnderlayReference() override = default;

public:
    static std::string  className();
    static PyRxClass    desc();
    static PyDbUnderlayReference	 cloneFrom(const PyRxObject& src);
    static PyDbUnderlayReference     cast(const PyRxObject& src);
public:
    AcDbUnderlayReference* impObj(const std::source_location& src = std::source_location::current()) const;
};



//-----------------------------------------------------------------------------------
//PyDbUnderlayDefinition
void makePyDbUnderlayDefinitionWrapper();

class PyDbUnderlayDefinition : public PyDbObject
{
public:
    PyDbUnderlayDefinition(AcDbUnderlayDefinition* ptr, bool autoDelete);
    PyDbUnderlayDefinition(const PyDbObjectId& id, AcDb::OpenMode mode);
    virtual ~PyDbUnderlayDefinition() override = default;

public:
    static std::string  className();
    static PyRxClass    desc();
    static PyDbUnderlayDefinition   cloneFrom(const PyRxObject& src);
    static PyDbUnderlayDefinition   cast(const PyRxObject& src);
public:
    AcDbUnderlayDefinition* impObj(const std::source_location& src = std::source_location::current()) const;
};

