#pragma once
#include "PyRxObject.h"
//-----------------------------------------------------------------------------------------
//PyGiDrawable
void makeAcGiObjectWrapper();

class PyGiDrawable : public PyRxObject
{
public:
    PyGiDrawable(AcGiDrawable* ptr, bool autoDelete, bool isDbObject);
    virtual ~PyGiDrawable() override = default;
    static std::string className();
    static PyRxClass desc();

public:
    AcGiDrawable* impObj(const std::source_location& src = std::source_location::current()) const;
};