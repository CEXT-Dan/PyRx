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
    PyDbAttributeDefinition(const AcGePoint3d& position, const std::string& text, const std::string& tag, const std::string& prompt, const PyDbObjectId& style);
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
    PyDbAttribute(const AcGePoint3d& position, const std::string& text, const std::string& tag, const PyDbObjectId& style);
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
    Acad::ErrorStatus setAttributeFromBlock(const PyDbAttributeDefinition& pAttdef, const AcGeMatrix3d& blkXform);

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
//PyDbBlockReference
void makeDbBlockReferenceWrapper();
class PyDbBlockReference : public PyDbEntity
{
public:
    PyDbBlockReference();
    PyDbBlockReference(const AcGePoint3d& position, const PyDbObjectId& blockTableRec);
    PyDbBlockReference(AcDbBlockReference* ptr, bool autoDelete);
    PyDbBlockReference(const PyDbObjectId& id, AcDb::OpenMode mode);
    virtual ~PyDbBlockReference() override = default;

    PyDbObjectId      blockTableRecord() const;
    virtual Acad::ErrorStatus setBlockTableRecord(const PyDbObjectId& val);

    virtual AcGePoint3d       position() const;
    virtual Acad::ErrorStatus setPosition(const AcGePoint3d& val);

    AcGeScale3d       scaleFactors() const;
    AcGeScale3d       nonAnnotationScaleFactors() const;
    virtual Acad::ErrorStatus setScaleFactors(const AcGeScale3d& scale);

    double            rotation() const;
    virtual Acad::ErrorStatus setRotation(double newVal);

    AcGeVector3d      normal() const;
    virtual Acad::ErrorStatus setNormal(const AcGeVector3d& newVal);

    Adesk::Boolean    isPlanar() const override { return Adesk::kTrue; }
    //Acad::ErrorStatus getPlane(AcGePlane&, AcDb::Planarity&) const override;

    AcGeMatrix3d      blockTransform() const;
    AcGeMatrix3d      nonAnnotationBlockTransform() const;
    virtual Acad::ErrorStatus setBlockTransform(const AcGeMatrix3d& val);

    PyDbObjectId  appendAttribute(PyDbAttribute& att);
    boost::python::list attributeIds() const;

    virtual Adesk::Boolean treatAsAcDbBlockRefForExplode() const;

    Acad::ErrorStatus geomExtentsBestFit(AcDbExtents& extents, const AcGeMatrix3d& parentXform) const;

    virtual Acad::ErrorStatus explodeToOwnerSpace() const;


    static std::string className();
public:
    AcDbBlockReference* impObj() const;
};

//-----------------------------------------------------------------------------------
//PyDbBlockReference
void makeDbMInsertBlockeWrapper();
class PyDbMInsertBlock : public  PyDbBlockReference
{
public:
    PyDbMInsertBlock();
    PyDbMInsertBlock(const AcGePoint3d& position, const PyDbObjectId& blockTableRec, Adesk::UInt16 columns, Adesk::UInt16 rows, double colSpacing, double rowSpacing);
    PyDbMInsertBlock(AcDbMInsertBlock* ptr, bool autoDelete);
    PyDbMInsertBlock(const PyDbObjectId& id, AcDb::OpenMode mode);
    virtual ~PyDbMInsertBlock() override = default;

    Adesk::UInt16      columns() const;
    Acad::ErrorStatus  setColumns(Adesk::UInt16 val);

    Adesk::UInt16      rows() const;
    Acad::ErrorStatus  setRows(Adesk::UInt16 val);

    double             columnSpacing() const;
    Acad::ErrorStatus  setColumnSpacing(double val);

    double             rowSpacing() const;
    Acad::ErrorStatus  setRowSpacing(double val);


    static std::string className();
public:
    AcDbMInsertBlock* impObj() const;
};

//-------------------------------------------------------------------------------------------------------------
//PyDbVertex
void makeAcDbVertexWrapper();
class PyDbVertex : public PyDbEntity
{
public:
    PyDbVertex(AcDbVertex* ptr, bool autoDelete);
    PyDbVertex(const PyDbObjectId& id, AcDb::OpenMode mode);
    virtual ~PyDbVertex() = default;
    static std::string className();
public:
    AcDbVertex* impObj() const;
};


//-------------------------------------------------------------------------------------------------------------
//PyDb2dVertex
void makePyDb2dVertexWrapper();
class PyDb2dVertex : public PyDbVertex
{
public:
    PyDb2dVertex();
    PyDb2dVertex(const AcGePoint3d& pos);
    PyDb2dVertex(const AcGePoint3d& pos, double bulge, double startWidth, double endWidth, double tangent, Adesk::Int32 vertexIdentifier);
    PyDb2dVertex(AcDb2dVertex* ptr, bool autoDelete);
    PyDb2dVertex(const PyDbObjectId& id, AcDb::OpenMode mode);
    virtual ~PyDb2dVertex() = default;

    AcDb::Vertex2dType vertexType() const;

    AcGePoint3d         position() const;
    Acad::ErrorStatus   setPosition(const AcGePoint3d& val);

    double              startWidth() const;
    Acad::ErrorStatus   setStartWidth(double newVal);

    double              endWidth() const;
    Acad::ErrorStatus   setEndWidth(double newVal);

    double              bulge() const;
    Acad::ErrorStatus   setBulge(double newVal);

    Adesk::Boolean      isTangentUsed() const;
    Acad::ErrorStatus   useTangent();
    Acad::ErrorStatus   ignoreTangent();
    Acad::ErrorStatus   setTangentUsed(Adesk::Boolean val);

    double              tangent() const;
    Acad::ErrorStatus   setTangent(double newVal);

    Acad::ErrorStatus  setVertexIdentifier(Adesk::Int32 suggestedValue);
    int                vertexIdentifier() const;



    static std::string className();
public:
    AcDb2dVertex* impObj() const;
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

