#pragma once

#include "PyDbObject.h"

class PyDbObjectId;
class PyDbDimStyleTableRecord;
class PyDbBlockTableRecord;

//AcDbAbstractViewTable
//AcDbLayerTable
//AcDbLinetypeTable
//AcDbRegAppTable
//AcDbTextStyleTable
//AcDbUCSTable

//---------------------------------------------------------------------------------------- -
//PyDbSymbolTable
void makeAcDbSymbolTableWrapper();

class PyDbSymbolTable : public PyDbObject
{
public:
    PyDbSymbolTable(AcDbSymbolTable* ptr, bool autoDelete);
    PyDbSymbolTable(const PyDbObjectId& id, AcDb::OpenMode mode);
    virtual ~PyDbSymbolTable() override = default;
    PyDbObjectId getAt(const std::string& entryName);
    bool has(const std::string& entryName);
    bool has(const PyDbObjectId& entryid);
    boost::python::list recordIds();

    static std::string className();
    static PyRxClass desc();

public:
    AcDbSymbolTable* impObj(const std::source_location& src = std::source_location::current()) const;
};


//---------------------------------------------------------------------------------------- -
//AcDbDimStyleTable
void makePyDbDimStyleTableWrapper();

class PyDbDimStyleTable : public PyDbSymbolTable
{
public:
    PyDbDimStyleTable(AcDbDimStyleTable* ptr, bool autoDelete);
    PyDbDimStyleTable(const PyDbObjectId& id, AcDb::OpenMode mode);
    virtual ~PyDbDimStyleTable() override = default;
    PyDbObjectId getAt(const std::string& entryName);
    PyDbObjectId add(const PyDbDimStyleTableRecord& entry);
    boost::python::list recordIds();
    static std::string className();
    static PyRxClass desc();

public:
    AcDbDimStyleTable* impObj(const std::source_location& src = std::source_location::current()) const;
};

//---------------------------------------------------------------------------------------- -
//PyDbBlockTable
void makePyDbBlockTableWrapper();

class PyDbBlockTable : public PyDbSymbolTable
{
public:
    PyDbBlockTable(AcDbBlockTable* ptr, bool autoDelete);
    PyDbBlockTable(const PyDbObjectId& id, AcDb::OpenMode mode);
    virtual ~PyDbBlockTable() override = default;
    PyDbObjectId getAt(const std::string& entryName);
    PyDbObjectId add(const PyDbBlockTableRecord& entry);
    boost::python::list recordIds();
    static std::string className();
    static PyRxClass desc();

public:
    AcDbBlockTable* impObj(const std::source_location& src = std::source_location::current()) const;
};