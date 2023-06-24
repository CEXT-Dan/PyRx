#pragma once

#include "PyDbObject.h"

class PyDbObjectId;
class PyDbSymbolTableRecord;
class PyDbDimStyleTableRecord;
class PyDbBlockTableRecord;
class PyDbTextStyleTableRecord;

//AcDbLinetypeTable
//AcDbRegAppTable
//AcDbUCSTable

//---------------------------------------------------------------------------------------- -
//PyDbSymbolTable
void makeAcDbSymbolTableWrapper();

class PyDbSymbolTable : public PyDbObject
{
public:
    PyDbSymbolTable(AcDbSymbolTable* ptr, bool autoDelete);
    PyDbSymbolTable(const PyDbObjectId& id);
    PyDbSymbolTable(const PyDbObjectId& id, AcDb::OpenMode mode);
    virtual ~PyDbSymbolTable() override = default;
    PyDbObjectId        getAt(const std::string& entryName);
    bool                has(const std::string& entryName);
    bool                has(const PyDbObjectId& entryid);
    PyDbObjectId        add(const PyDbSymbolTableRecord& pRecord);
    boost::python::list ids();
    boost::python::dict toDict();
    static std::string  className();
    static PyRxClass    desc();
    static PyDbSymbolTable cloneFrom(const PyRxObject& src);
    static PyDbSymbolTable cast(const PyRxObject& src);

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
    PyDbDimStyleTable(const PyDbObjectId& id);
    PyDbDimStyleTable(const PyDbObjectId& id, AcDb::OpenMode mode);
    virtual ~PyDbDimStyleTable() override = default;
    PyDbObjectId        add(const PyDbDimStyleTableRecord& entry);
    static std::string  className();
    static PyRxClass    desc();
    static PyDbDimStyleTable cloneFrom(const PyRxObject& src);
    static PyDbDimStyleTable cast(const PyRxObject& src);

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
    PyDbBlockTable(const PyDbObjectId& id);
    PyDbBlockTable(const PyDbObjectId& id, AcDb::OpenMode mode);
    virtual ~PyDbBlockTable() override = default;
    PyDbObjectId        add(const PyDbBlockTableRecord& entry);
    static std::string  className();
    static PyRxClass    desc();
    static PyDbBlockTable cloneFrom(const PyRxObject& src);
    static PyDbBlockTable cast(const PyRxObject& src);

public:
    AcDbBlockTable* impObj(const std::source_location& src = std::source_location::current()) const;
};

//---------------------------------------------------------------------------------------- -
//PyDbTextStyleTable
void makePyDbTextStyleTableWrapper();

class PyDbTextStyleTable : public PyDbSymbolTable
{
public:
    PyDbTextStyleTable(AcDbTextStyleTable* ptr, bool autoDelete);
    PyDbTextStyleTable(const PyDbObjectId& id);
    PyDbTextStyleTable(const PyDbObjectId& id, AcDb::OpenMode mode);
    virtual ~PyDbTextStyleTable() override = default;
    PyDbObjectId        add(const PyDbTextStyleTableRecord& entry);
    static std::string  className();
    static PyRxClass    desc();
    static PyDbTextStyleTable cloneFrom(const PyRxObject& src);
    static PyDbTextStyleTable cast(const PyRxObject& src);

public:
    AcDbTextStyleTable* impObj(const std::source_location& src = std::source_location::current()) const;
};