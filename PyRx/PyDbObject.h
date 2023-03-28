#pragma once

#include "PyGiDrawable.h"

void makeAcDbObjectWrapper();
//---------------------------------------------------------------------------------------- -
//PyDbObject
class PyDbObject : public PyGiDrawable
{
public:
    PyDbObject(AcDbObject* ptr, bool autoDelete);
    virtual ~PyDbObject() override;
    virtual Acad::ErrorStatus close();
    static std::string className();

public:
    AcDbObject* impObj() const;
};
