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
    PyDb3dSolid(const PyDbObjectId& id, AcDb::OpenMode mode);
    Acad::ErrorStatus createBox(double xLen, double yLen, double zLen);
    Acad::ErrorStatus createFrustum(double height, double xRadius,double yRadius, double topXRadius);
    Acad::ErrorStatus createSphere(double radius);
    Acad::ErrorStatus createTorus(double majorRadius, double minorRadius);
    Acad::ErrorStatus createPyramid1(double height, int sides, double radius);
    Acad::ErrorStatus createPyramid2(double height, int sides, double radius, double topRadius);
    Acad::ErrorStatus createWedge(double xLen, double yLen, double zLen);
    static std::string className();
public:
    AcDb3dSolid* impObj() const;
};

