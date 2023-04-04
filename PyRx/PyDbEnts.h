#pragma once
#include "PyDbEntity.h"
class PyDbObjectId;


//-----------------------------------------------------------------------------------
//PyDbText
void makePyDbTextWrapper();
class PyDbText : public PyDbEntity
{
public:
    PyDbText();
    PyDbText(const AcGePoint3d& position, const std::string& text);
    PyDbText(const AcGePoint3d& position, const std::string& text, PyDbObjectId& style, double height, double rotation);
    PyDbText(AcDbText* ptr, bool autoDelete);
    PyDbText(const PyDbObjectId& id, AcDb::OpenMode mode);
    virtual ~PyDbText() override = default;

    AcGePoint3d         position() const;
    Acad::ErrorStatus   setPosition(const AcGePoint3d& val);

    AcGePoint3d         alignmentPoint() const;
    Acad::ErrorStatus   setAlignmentPoint(const AcGePoint3d& val);
    Adesk::Boolean      isDefaultAlignment() const;

    AcGeVector3d        normal() const;
    Acad::ErrorStatus   setNormal(const AcGeVector3d& val);

    Adesk::Boolean      isPlanar() const override { return Adesk::kTrue; }
    //Acad::ErrorStatus   getPlane(AcGePlane&, AcDb::Planarity&) const override;

    double              thickness() const;
    Acad::ErrorStatus   setThickness(double);

    double              oblique() const;
    Acad::ErrorStatus   setOblique(double);

    double              rotation() const;
    Acad::ErrorStatus   setRotation(double val);

    double              height() const;
    Acad::ErrorStatus   setHeight(double val);

    double              widthFactor() const;
    Acad::ErrorStatus   setWidthFactor(double val);

    std::string         textString() const;
    Acad::ErrorStatus   setTextString(std::string& val);

    PyDbObjectId        textStyle() const;
    Acad::ErrorStatus   setTextStyle(const PyDbObjectId& val);

    Adesk::Boolean      isMirroredInX() const;
    Acad::ErrorStatus   mirrorInX(Adesk::Boolean val);

    Adesk::Boolean      isMirroredInY() const;
    Acad::ErrorStatus   mirrorInY(Adesk::Boolean val);

    AcDb::TextHorzMode  horizontalMode() const;
    Acad::ErrorStatus   setHorizontalMode(AcDb::TextHorzMode val);

    AcDb::TextVertMode  verticalMode() const;
    Acad::ErrorStatus   setVerticalMode(AcDb::TextVertMode val);

    int                 correctSpelling();

    virtual Acad::ErrorStatus   adjustAlignment(const PyDbDatabase& pDb);



    static std::string className();

public:
    AcDbText* impObj() const;
};


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

