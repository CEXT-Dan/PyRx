#pragma once
#include "PyDbEntity.h"

class PyDbObjectId;

void makePyDbMTextWrapper();
class PyDbMtext : public PyDbEntity
{
public:
    PyDbMtext();
    PyDbMtext(AcDbMText* ptr, bool autoDelete);
    PyDbMtext(const PyDbObjectId& id, AcDb::OpenMode mode);
    virtual ~PyDbMtext() override = default;

    AcGePoint3d     location() const;
    Acad::ErrorStatus   setLocation(const AcGePoint3d& val);
    AcGeVector3d    normal() const;
    Acad::ErrorStatus   setNormal(const AcGeVector3d& val);
    AcGeVector3d    direction() const;
    Acad::ErrorStatus   setDirection(const AcGeVector3d&);
    double      rotation() const;
    Acad::ErrorStatus   setRotation(double val);
    double      width() const;
    Acad::ErrorStatus   setWidth(double);
    double      ascent() const;
    double      descent() const;
    PyDbObjectId        textStyle() const;
    Acad::ErrorStatus   setTextStyle(const PyDbObjectId& val);
    double      textHeight() const;
    Acad::ErrorStatus   setTextHeight(double val);
    AcDbMText::AttachmentPoint attachment() const;
    Acad::ErrorStatus   setAttachment(AcDbMText::AttachmentPoint val);
    Acad::ErrorStatus   setAttachmentMovingLocation(AcDbMText::AttachmentPoint val);
    static std::string className();
public:
    AcDbMText* impObj() const;
};

