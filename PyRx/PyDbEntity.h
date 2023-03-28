#pragma once
#include "PyDbObject.h"

void makeAcDbEntityWrapper();

class PyDbEntity : public PyDbObject
{
public:
    PyDbEntity(AcDbEntity* ptr, bool autoDelete);
    virtual ~PyDbEntity() override = default;
    static std::string className();

public:
    AcDbEntity* impObj() const;
};

