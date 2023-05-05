#pragma once

#include "PyDbObject.h"

class PyDbObjectId;
class PyDbDimStyleTableRecord;

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
public:
    AcDbSymbolTable* impObj() const;
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
public:
    AcDbDimStyleTable* impObj() const;

};