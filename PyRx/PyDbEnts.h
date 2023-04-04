#pragma once
#include "PyDbEntity.h"

//-----------------------------------------------------------------------------------
//PyDbPoint
void makePyDbPointWrapper();
class PyDbPoint : public PyDbEntity
{
public:
    PyDbPoint();
    PyDbPoint(const AcGePoint3d& point);
    PyDbPoint(AcDbPoint* ptr, bool autoDelete);
    PyDbPoint(const PyDbObjectId& id, AcDb::OpenMode mode);
    virtual ~PyDbPoint() override = default;

    AcGePoint3d         position() const;
    Acad::ErrorStatus   setPosition(const AcGePoint3d&);

    double              thickness() const;
    Acad::ErrorStatus   setThickness(double val);

    AcGeVector3d        normal() const;
    Acad::ErrorStatus   setNormal(const AcGeVector3d& val);

    double              ecsRotation() const;
    Acad::ErrorStatus   setEcsRotation(double);

    Adesk::Boolean    isPlanar() const override;
    //Acad::ErrorStatus getPlane(AcGePlane&, AcDb::Planarity&) const override; //TODO:

    static std::string className();

public:
    AcDbPoint* impObj() const;
};

