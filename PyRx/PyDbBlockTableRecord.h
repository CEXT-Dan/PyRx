#pragma once
#include "PyDbSymbolTableRecord.h"
#include "PyDbObjectId.h"

class PyDbEntity;

void makeAcDbBlockTableRecordWrapper();

class PyDbBlockTableRecord : public PyDbSymbolTableRecord
{
public:
    PyDbBlockTableRecord (AcDbBlockTableRecord* ptr, bool autoDelete);
    virtual ~PyDbBlockTableRecord() override = default;

    PyDbObjectId appendAcDbEntity(const PyDbEntity& ent);
    boost::python::list objectIds();

    static PyDbBlockTableRecord fromDbObject(const PyDbObject& obj);
    static std::string className();

public:
    AcDbBlockTableRecord* impObj() const;

};

