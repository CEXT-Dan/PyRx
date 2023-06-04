#pragma once
#include "PyDbEntity.h"

class PyDbObjectId;

//-----------------------------------------------------------------------------------
//PyDbImage
void makePyDbImageWrapper();
class PyDbImage : public PyDbEntity
{
public:
    PyDbImage(AcDbImage* ptr, bool autoDelete);
    PyDbImage(const PyDbObjectId& id, AcDb::OpenMode mode);
    virtual ~PyDbImage() override = default;
    
public:
    static std::string  className();
    static PyRxClass    desc();
    static PyDbImage	cloneFrom(const PyRxObject & src);
    static PyDbImage    cast(const PyRxObject & src);
public:
    AcDbImage* impObj(const std::source_location & src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//PyDbRasterImageDef
void makePyDbRasterImageDefWrapper();

class PyDbRasterImageDef : public PyDbObject
{
public:
    PyDbRasterImageDef();
    PyDbRasterImageDef(AcDbRasterImageDef* ptr, bool autoDelete);
    PyDbRasterImageDef(const PyDbObjectId& id, AcDb::OpenMode mode);
    virtual ~PyDbRasterImageDef() override = default;
public:
    static std::string  className();
    static PyRxClass    desc();
    static PyDbRasterImageDef   cloneFrom(const PyRxObject & src);
    static PyDbRasterImageDef   cast(const PyRxObject & src);
public:
    AcDbRasterImageDef* impObj(const std::source_location & src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//AcDbRasterImage
void makePyDbRasterImageWrapper();

class PyDbRasterImage : public PyDbImage
{
public:
    PyDbRasterImage();
    PyDbRasterImage(AcDbRasterImage* ptr, bool autoDelete);
    PyDbRasterImage(const PyDbObjectId& id, AcDb::OpenMode mode);
    virtual ~PyDbRasterImage() override = default;

public:
    static std::string  className();
    static PyRxClass    desc();
    static PyDbRasterImage	  cloneFrom(const PyRxObject & src);
    static PyDbRasterImage    cast(const PyRxObject & src);
public:
    AcDbRasterImage* impObj(const std::source_location & src = std::source_location::current()) const;
};

