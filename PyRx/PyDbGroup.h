#pragma once
#include "PyDbObject.h"

//----------------------------------------------------------------------------------------
//PyDbGroup
void makePyDbGroupWrapper();
class PyDbGroup : public PyDbObject
{
public:
    PyDbGroup();
    PyDbGroup(const std::string& grpDesc);
    PyDbGroup(const std::string& grpDesc, bool selectable);
    PyDbGroup(AcDbGroup* ptr, bool autoDelete);
    PyDbGroup(const PyDbObjectId&);
    PyDbGroup(const PyDbObjectId& id, AcDb::OpenMode mode);
    inline virtual ~PyDbGroup() override = default;

public:
    static PyRxClass    desc();
    static std::string  className();
    static PyDbGroup    cloneFrom(const PyRxObject& src);
    static PyDbGroup    cast(const PyRxObject& src);
public:
    inline AcDbGroup* impObj(const std::source_location& src = std::source_location::current()) const;
};
