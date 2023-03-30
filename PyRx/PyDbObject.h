#pragma once

#include "PyGiDrawable.h"


class PyDbObjectId;
class PyDbDatabase;

void makeAcDbObjectWrapper();
//---------------------------------------------------------------------------------------- -
//PyDbObject
class PyDbObject : public PyGiDrawable
{
public:
    PyDbObject(AcDbObject* ptr, bool autoDelete);
    PyDbObject(const PyDbObjectId& id, AcDb::OpenMode mode);
    virtual ~PyDbObject() override;

    PyDbObjectId objectId() const;
    PyDbObjectId ownerId() const;
    PyDbDatabase database() const;
    Acad::ErrorStatus close();

    Acad::ErrorStatus upgradeOpen();
    Acad::ErrorStatus downgradeOpen();
    Acad::ErrorStatus erase();

    static std::string className();

public:
    AcDbObject* impObj() const;
};
