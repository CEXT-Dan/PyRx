#pragma once
#include "PyRxObject.h"

class PyDbDatabase;

//------------------------------------------------------------------------------------
//PyLyLayerFilter
void makePyLyLayerFilterWrapper();

class PyLyLayerFilter : public PyRxObject
{
public:
    PyLyLayerFilter();
    PyLyLayerFilter(AcLyLayerFilter* pt, bool autoDelete);
    inline virtual ~PyLyLayerFilter() = default;
    static PyRxClass    desc();
    static std::string  className();
public:
    inline AcLyLayerFilter* impObj(const std::source_location& src = std::source_location::current()) const;
};

//------------------------------------------------------------------------------------
//PyLyLayerGroup
void makePyLyLayerGroupWrapper();
class PyLyLayerGroup : public PyLyLayerFilter
{
public:
    PyLyLayerGroup();
    PyLyLayerGroup(AcLyLayerGroup* pt, bool autoDelete);
    inline virtual ~PyLyLayerGroup() = default;
    static PyRxClass    desc();
    static std::string  className();
public:
    inline AcLyLayerGroup* impObj(const std::source_location& src = std::source_location::current()) const;
};

//------------------------------------------------------------------------------------
//PyLayerFilterManager
void makePyLayerFilterManagerWrapper();

class PyLayerFilterManager
{
public:
    PyLayerFilterManager();
    PyLayerFilterManager(PyDbDatabase& db);
    virtual ~PyLayerFilterManager() = default;
    boost::python::tuple getFilters();
    void setFilters(boost::python::tuple& pyList);
public:
    AcLyLayerFilterManager* imp = nullptr;
};




