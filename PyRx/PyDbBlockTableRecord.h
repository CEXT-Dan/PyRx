#pragma once
#include "PyDbSymbolTableRecord.h"
#include "PyDbObjectId.h"

class PyDbEntity;

void makeAcDbBlockTableRecordWrapper();

class PyDbBlockTableRecord : public PyDbSymbolTableRecord
{
public:
    PyDbBlockTableRecord (AcDbBlockTableRecord* ptr, bool autoDelete);
    PyDbBlockTableRecord(const PyDbObjectId& id, AcDb::OpenMode mode);
    virtual ~PyDbBlockTableRecord() override = default;

    PyDbObjectId appendAcDbEntity(const PyDbEntity& ent);
    boost::python::list objectIds();

    static std::string className();

public:
    AcDbBlockTableRecord* impObj() const;
};

