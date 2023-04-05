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

    Acad::ErrorStatus   convertFieldToText();
    bool hitTest(const AcGePoint3d& ptHit) const;
    boost::python::list getBoundingPoints() const;

    AcDbText::AcTextAlignment  justification() const;
    Acad::ErrorStatus          setJustification(AcDbText::AcTextAlignment val);

    static std::string className();

public:
    AcDbText* impObj() const;
};

//-----------------------------------------------------------------------------------
//PyDbAttributeDefinition
void makePyDbAttributeDefinitionWrapper();
class PyDbAttributeDefinition : public PyDbText
{
public:
    PyDbAttributeDefinition();
    PyDbAttributeDefinition(const AcGePoint3d& position,const std::string& text, const std::string& tag, const std::string& prompt, const PyDbObjectId& style);
    PyDbAttributeDefinition(AcDbAttributeDefinition* ptr, bool autoDelete);
    PyDbAttributeDefinition(const PyDbObjectId& id, AcDb::OpenMode mode);
    virtual ~PyDbAttributeDefinition() override = default;

    std::string         prompt() const;
    Acad::ErrorStatus   setPrompt(const std::string& val);

    std::string          tag() const;
    Acad::ErrorStatus    setTag(const std::string& val);

    Adesk::Boolean      isInvisible() const;
    Acad::ErrorStatus   setInvisible(Adesk::Boolean val);

    Adesk::Boolean      isConstant() const;
    Acad::ErrorStatus   setConstant(Adesk::Boolean val);

    Adesk::Boolean      isVerifiable() const;
    Acad::ErrorStatus   setVerifiable(Adesk::Boolean val);

    Adesk::Boolean      isPreset() const;
    Acad::ErrorStatus   setPreset(Adesk::Boolean val);

    Adesk::UInt16       fieldLength() const;
    Acad::ErrorStatus   setFieldLength(Adesk::UInt16 val);

    Acad::ErrorStatus   adjustAlignment(const PyDbDatabase& pDb) override;

    bool lockPositionInBlock() const;
    Acad::ErrorStatus setLockPositionInBlock(bool bValue);

    // multiline attribute definition support
    bool isMTextAttributeDefinition() const;
    //AcDbMText* getMTextAttributeDefinition() const;
    //const AcDbMText* getMTextAttributeDefinitionConst() const;
    //Acad::ErrorStatus setMTextAttributeDefinition(AcDbMText*);
    //ACDBCORE2D_PORT Acad::ErrorStatus setMTextAttributeDefinitionConst(const AcDbMText*);
    Acad::ErrorStatus convertIntoMTextAttributeDefinition(Adesk::Boolean val);
    Acad::ErrorStatus updateMTextAttributeDefinition();

    static std::string className();
public:
    AcDbAttributeDefinition* impObj() const;
};

//-----------------------------------------------------------------------------------
//PyDbAttribute
void makePyDbAttributeWrapper();
class PyDbAttribute : public PyDbText
{
public:
    PyDbAttribute();
    PyDbAttribute(const AcGePoint3d& position, const std::string& text, const std::string& tag,const PyDbObjectId& style);
    PyDbAttribute(AcDbAttributeDefinition* ptr, bool autoDelete);
    PyDbAttribute(const PyDbObjectId& id, AcDb::OpenMode mode);
    virtual ~PyDbAttribute() override = default;

    std::string tag() const;
    Acad::ErrorStatus setTag(const std::string& val);

    Adesk::Boolean isInvisible() const;
    Acad::ErrorStatus setInvisible(Adesk::Boolean val);

    Adesk::Boolean      isConstant() const;
    Adesk::Boolean      isVerifiable() const;
    Adesk::Boolean      isPreset() const;

    Adesk::UInt16       fieldLength() const;
    Acad::ErrorStatus   setFieldLength(Adesk::UInt16);

    Acad::ErrorStatus setAttributeFromBlock(const AcGeMatrix3d& blkXform);
    Acad::ErrorStatus setAttributeFromBlock(const PyDbAttributeDefinition& pAttdef,const AcGeMatrix3d& blkXform);

    bool lockPositionInBlock() const;
    Acad::ErrorStatus setLockPositionInBlock(bool bValue);

    bool              isMTextAttribute() const;
    //AcDbMText*        getMTextAttribute() const;
    //const AcDbMText*  getMTextAttributeConst() const;
    //Acad::ErrorStatus setMTextAttribute(AcDbMText*);
    //Acad::ErrorStatus setMTextAttributeConst(const AcDbMText*);
    Acad::ErrorStatus convertIntoMTextAttribute(Adesk::Boolean val);
    Acad::ErrorStatus updateMTextAttribute();
    bool              isReallyLocked() const;


    static std::string className();
public:
    AcDbAttribute* impObj() const;
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

