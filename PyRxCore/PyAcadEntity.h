#pragma once

#include "PyAcadDbObject.h"
#pragma pack (push, 8)

class PyIAcadEntityImpl;
//----------------------------------------------------------------------------------------
//PyAcadEntity
void makePyAcadEntityWrapper();

class PyAcadEntity : public PyAcadObject
{
public:
    PyAcadEntity(PyIAcadEntityImpl* ptr);
    virtual ~PyAcadEntity() override = default;

    void    transformBy(const AcGeMatrix3d& xform);
    
    static PyAcadEntity cast(const PyAcadObject& src);
    static std::string  className();
public:
    PyIAcadEntityImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

#pragma pack (pop)