#pragma once
#include "PyDbEntity.h"

class PyDbObjectId;
//-----------------------------------------------------------------------------------
//PyDb3dSolid
void makePyDb3dSolidWrapper();

class PyDb3dSolid : public PyDbEntity
{
public:
    PyDb3dSolid();
    PyDb3dSolid(AcDb3dSolid* ptr, bool autoDelete);
    PyDb3dSolid(const PyDbObjectId& id);
    PyDb3dSolid(const PyDbObjectId& id, AcDb::OpenMode mode);
    Acad::ErrorStatus   createBox(double xLen, double yLen, double zLen);
    Acad::ErrorStatus   createFrustum(double height, double xRadius, double yRadius, double topXRadius);
    Acad::ErrorStatus   createSphere(double radius);
    Acad::ErrorStatus   createTorus(double majorRadius, double minorRadius);
    Acad::ErrorStatus   createPyramid1(double height, int sides, double radius);
    Acad::ErrorStatus   createPyramid2(double height, int sides, double radius, double topRadius);
    Acad::ErrorStatus   createWedge(double xLen, double yLen, double zLen);
    static std::string  className();
    static PyRxClass    desc();
    static PyDb3dSolid  cloneFrom(const PyRxObject& src);
    static PyDb3dSolid  cast(const PyRxObject& src);
public:
    AcDb3dSolid* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//PyDbRegion
void makePyDbRegionWrapper();

class PyDbRegion : public PyDbEntity
{
public:
    PyDbRegion();
    PyDbRegion(AcDbRegion* ptr, bool autoDelete);
    PyDbRegion(const PyDbObjectId& id);
    PyDbRegion(const PyDbObjectId& id, AcDb::OpenMode mode);
    static std::string  className();
    static PyRxClass    desc();
    static PyDbRegion   cloneFrom(const PyRxObject& src);
    static PyDbRegion   cast(const PyRxObject& src);
public:
    AcDbRegion* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//PyDbBody
void makeAcDbBodyWrapper();

class PyDbBody : public PyDbEntity
{
public:
    PyDbBody();
    PyDbBody(AcDbBody* ptr, bool autoDelete);
    PyDbBody(const PyDbObjectId& id);
    PyDbBody(const PyDbObjectId& id, AcDb::OpenMode mode);
    static std::string  className();
    static PyRxClass    desc();
    static PyDbBody     cloneFrom(const PyRxObject& src);
    static PyDbBody     cast(const PyRxObject& src);
public:
    AcDbBody* impObj(const std::source_location& src = std::source_location::current()) const;
};
