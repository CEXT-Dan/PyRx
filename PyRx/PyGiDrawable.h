#pragma once
#include "PyRxObject.h"

void makeAcGiObjectWrapper();
//-----------------------------------------------------------------------------------------
//PyGiDrawable
class PyGiDrawable : public PyRxObject
{
public:
    PyGiDrawable(AcGiDrawable* ptr, bool autoDelete, bool isDbObject);
    virtual ~PyGiDrawable() override = default;
    static std::string className();

public:
    AcGiDrawable* impObj() const;
};