#pragma once
#include "PyDbEntity.h"
#include "dbViewSymbol.h"
#include "dbDetailSymbol.h"
#include "dbSectionSymbol.h"

#pragma pack (push, 8)

class PyDbObjectId;

//-------------------------------------------------------------------------------------------------------------
// PyDbViewSymbol
void makePyDbViewSymbolWrapper();

class PyDbViewSymbol : public PyDbEntity
{
public:
    PyDbViewSymbol(AcDbViewSymbol* ptr, bool autoDelete);
    PyDbViewSymbol(const PyDbObjectId& id);
    PyDbViewSymbol(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbViewSymbol(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    virtual ~PyDbViewSymbol() override = default;

    static PyRxClass    desc();
    static std::string  className();
    static PyDbViewSymbol   cloneFrom(const PyRxObject& src);
    static PyDbViewSymbol   cast(const PyRxObject& src);
public:
    AcDbViewSymbol* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-------------------------------------------------------------------------------------------------------------
// PyDbDetailSymbol
void makePyDbDetailSymbolWrapper();

class PyDbDetailSymbol : public PyDbViewSymbol
{
public:
    PyDbDetailSymbol();
    PyDbDetailSymbol(AcDbDetailSymbol* ptr, bool autoDelete);
    PyDbDetailSymbol(const PyDbObjectId& id);
    PyDbDetailSymbol(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbDetailSymbol(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    virtual ~PyDbDetailSymbol() override = default;

    static PyRxClass    desc();
    static std::string  className();
    static PyDbDetailSymbol   cloneFrom(const PyRxObject& src);
    static PyDbDetailSymbol   cast(const PyRxObject& src);
public:
    AcDbDetailSymbol* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-------------------------------------------------------------------------------------------------------------
// PyDbSectionSymbol
void makePyDbSectionSymbolWrapper();

class PyDbSectionSymbol : public PyDbViewSymbol
{
public:
    PyDbSectionSymbol();
    PyDbSectionSymbol(AcDbSectionSymbol* ptr, bool autoDelete);
    PyDbSectionSymbol(const PyDbObjectId& id);
    PyDbSectionSymbol(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbSectionSymbol(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    virtual ~PyDbSectionSymbol() override = default;


    static PyRxClass    desc();
    static std::string  className();
    static PyDbSectionSymbol   cloneFrom(const PyRxObject& src);
    static PyDbSectionSymbol   cast(const PyRxObject& src);
public:
    AcDbSectionSymbol* impObj(const std::source_location& src = std::source_location::current()) const;
};

#pragma pack (pop)