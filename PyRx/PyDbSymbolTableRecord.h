#pragma once
#include "PyDbObject.h"


void makeAcDbSymbolTableRecordWrapper();

//---------------------------------------------------------------------------------------- -
// PyDbSymbolTableRecord 
class PyDbSymbolTableRecord : public PyDbObject
{
public:
    PyDbSymbolTableRecord(AcDbSymbolTableRecord* ptr, bool autoDelete);
    PyDbSymbolTableRecord(const PyDbObjectId& id, AcDb::OpenMode mode);
    virtual ~PyDbSymbolTableRecord() override = default;
    std::string getName();
    Acad::ErrorStatus setName(const std::string name);
    bool isDependent() const;
    bool isResolved() const;
    bool isRenamable() const;
    static std::string className();

public:
    AcDbSymbolTableRecord* impObj() const;
};

