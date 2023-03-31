#pragma once
#include "PyDbObject.h"

void makeAcDbEntityWrapper();

class PyDbEntity : public PyDbObject
{
public:
    PyDbEntity(AcDbEntity* ptr, bool autoDelete);
    PyDbEntity(const PyDbObjectId& id, AcDb::OpenMode mode);
    virtual ~PyDbEntity() override = default;

    PyDbObjectId blockId() const;


    virtual Acad::ErrorStatus setLayer(const std::string& newVal);
    virtual Acad::ErrorStatus setLayer(const std::string& newVal, bool doSubents);
    virtual Acad::ErrorStatus setLayer(const std::string& newVal, bool doSubents, bool allowHiddenLayer);

    virtual Acad::ErrorStatus setLayer(const PyDbObjectId& newVal);
    virtual Acad::ErrorStatus setLayer(const PyDbObjectId& newVal, bool doSubents);
    virtual Acad::ErrorStatus setLayer(const PyDbObjectId& newVal, bool doSubents, bool allowHiddenLayer);

    static std::string className();

public:
    AcDbEntity* impObj() const;
};

