#pragma once
#include "PyDbObject.h"

class PyDbObjectId;

//---------------------------------------------------------------------------------------- -
//PyDbPlotSettings
void makePyDbPlotSettingsWrapper();

class PyDbPlotSettings : public PyDbObject
{
public:
    PyDbPlotSettings();
    PyDbPlotSettings(bool ModelType);
    PyDbPlotSettings(AcDbPlotSettings* ptr, bool autoDelete);
    PyDbPlotSettings(const PyDbObjectId& id, AcDb::OpenMode mode);
    ~PyDbPlotSettings() override = default;

public:
    static std::string          className();
    static PyRxClass            desc();
    static PyDbPlotSettings     cloneFrom(const PyRxObject& src);
    static PyDbPlotSettings     cast(const PyRxObject& src);
public:
    AcDbPlotSettings* impObj(const std::source_location& src = std::source_location::current()) const;
};


//---------------------------------------------------------------------------------------- -
//PyDbLayout
void makePyDbLayoutWrapper();

class PyDbLayout : public PyDbPlotSettings
{
public:
    PyDbLayout();
    PyDbLayout(AcDbLayout* ptr, bool autoDelete);
    PyDbLayout(const PyDbObjectId& id, AcDb::OpenMode mode);
    ~PyDbLayout() override = default;

public:
    static std::string    className();
    static PyRxClass      desc();
    static PyDbLayout     cloneFrom(const PyRxObject & src);
    static PyDbLayout     cast(const PyRxObject & src);
public:
    AcDbLayout* impObj(const std::source_location & src = std::source_location::current()) const;
};

