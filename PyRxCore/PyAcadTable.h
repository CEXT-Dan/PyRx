#pragma once
#include "PyAcadEntity.h"

//----------------------------------------------------------------------------------------
//PyAcadTable
void makePyAcadTableWrapper();

class PyAcadTable : public PyAcadEntity
{
public:
    PyAcadTable() = default;
    PyAcadTable(std::shared_ptr<PyIAcadTableImpl> ptr);
    virtual ~PyAcadTable() override = default;
    static PyAcadTable cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadTableImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

