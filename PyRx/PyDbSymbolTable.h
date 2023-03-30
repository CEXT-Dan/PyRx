#pragma once

#include "PyDbObject.h"

void makeAcDbSymbolTableWrapper();

//---------------------------------------------------------------------------------------- -
//PyDbSymbolTable
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

public:
    AcDbSymbolTable* impObj() const;
};


