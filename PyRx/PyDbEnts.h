#pragma once
#include "PyDbEntity.h"
#include "PyDbCurve.h"
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

//-------------------------------------------------------------------------------------------------------------
//AcDb3dPolylineVertex
void makePyAcDb3dPolylineVertexWrapper();
class PyDb3dPolylineVertex : public PyDbVertex
{
public:
    PyDb3dPolylineVertex();
    PyDb3dPolylineVertex(const AcGePoint3d& pos);
    PyDb3dPolylineVertex(AcDb3dPolylineVertex* ptr, bool autoDelete);
    PyDb3dPolylineVertex(const PyDbObjectId& id, AcDb::OpenMode mode);
    virtual ~PyDb3dPolylineVertex() = default;

    AcDb::Vertex3dType  vertexType() const;

    AcGePoint3d         position() const;
    Acad::ErrorStatus   setPosition(const AcGePoint3d&);

    static std::string className();
public:
    AcDb3dPolylineVertex* impObj() const;
};

//-------------------------------------------------------------------------------------------------------------
//AcDbPolygonMeshVertex
void makePyAcDbPolygonMeshVertexWrapper();
class PyDbPolygonMeshVertex : public PyDbVertex
{
public:
    PyDbPolygonMeshVertex();
    PyDbPolygonMeshVertex(const AcGePoint3d& pos);
    PyDbPolygonMeshVertex(AcDbPolygonMeshVertex* ptr, bool autoDelete);
    PyDbPolygonMeshVertex(const PyDbObjectId& id, AcDb::OpenMode mode);
    virtual ~PyDbPolygonMeshVertex() = default;

    AcDb::Vertex3dType  vertexType() const;

    AcGePoint3d         position() const;
    Acad::ErrorStatus   setPosition(const AcGePoint3d&);

    static std::string className();
public:
    AcDbPolygonMeshVertex* impObj() const;
};

//-------------------------------------------------------------------------------------------------------------
//AcDbPolygonMeshVertex
void makePyDbPolyFaceMeshVertexWrapper();
class PyDbPolyFaceMeshVertex : public PyDbVertex
{
public:
    PyDbPolyFaceMeshVertex();
    PyDbPolyFaceMeshVertex(const AcGePoint3d& pos);
    PyDbPolyFaceMeshVertex(AcDbPolyFaceMeshVertex* ptr, bool autoDelete);
    PyDbPolyFaceMeshVertex(const PyDbObjectId& id, AcDb::OpenMode mode);
    virtual ~PyDbPolyFaceMeshVertex() = default;

    AcGePoint3d         position() const;
    Acad::ErrorStatus   setPosition(const AcGePoint3d&);

    static std::string className();
public:
    AcDbPolyFaceMeshVertex* impObj() const;
};


//-------------------------------------------------------------------------------------------------------------
//AcDbFaceRecord
void makePyAcDbFaceRecordWrapper();
class PyDbFaceRecord : public PyDbVertex
{
public:
    PyDbFaceRecord();
    PyDbFaceRecord(Adesk::Int16 vtx0, Adesk::Int16 vtx1, Adesk::Int16 vtx2, Adesk::Int16 vtx3);
    PyDbFaceRecord(AcDbFaceRecord* ptr, bool autoDelete);
    PyDbFaceRecord(const PyDbObjectId& id, AcDb::OpenMode mode);
    virtual ~PyDbFaceRecord() = default;

    Adesk::Int16 getVertexAt(Adesk::UInt16 faceIdx) const;
    Acad::ErrorStatus setVertexAt(Adesk::UInt16 faceIdx, Adesk::Int16 vtxIdx);

    Adesk::Boolean isEdgeVisibleAt(Adesk::UInt16 faceIndex) const;

    Acad::ErrorStatus makeEdgeVisibleAt(Adesk::UInt16 faceIndex);
    Acad::ErrorStatus makeEdgeInvisibleAt(Adesk::UInt16 faceIndex);

    static std::string className();
public:
    AcDbFaceRecord* impObj() const;
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


//-----------------------------------------------------------------------------------
//PyDb2dPolyline
void makePyDb2dPolylineWrapper();
class PyDb2dPolyline : public PyDbCurve
{
public:
    PyDb2dPolyline();
    virtual ~PyDb2dPolyline() override = default;
    PyDb2dPolyline(AcDb2dPolyline* ptr, bool autoDelete);
    PyDb2dPolyline(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDb2dPolyline(AcDb::Poly2dType type, const boost::python::list& vertices, Adesk::Boolean closed);

    AcDb::Poly2dType    polyType() const;
    Acad::ErrorStatus   setPolyType(AcDb::Poly2dType val);
    Acad::ErrorStatus   convertToPolyType(AcDb::Poly2dType val);

    Acad::ErrorStatus makeClosed();
    Acad::ErrorStatus makeOpen();
    Acad::ErrorStatus setClosed(Adesk::Boolean val);

    double constantWidth() const;
    Acad::ErrorStatus setConstantWidth(double val);
    double  length() const;

    double              defaultStartWidth() const;
    Acad::ErrorStatus   setDefaultStartWidth(double val);

    double              defaultEndWidth() const;
    Acad::ErrorStatus   setDefaultEndWidth(double);

    double              thickness() const;
    Acad::ErrorStatus   setThickness(double val);

    AcGeVector3d        normal() const;
    Acad::ErrorStatus   setNormal(const AcGeVector3d& val);

    double              elevation() const;
    Acad::ErrorStatus   setElevation(double);

    Adesk::Boolean      isLinetypeGenerationOn() const;
    Acad::ErrorStatus   setLinetypeGenerationOn();
    Acad::ErrorStatus   setLinetypeGenerationOff();

    Acad::ErrorStatus   straighten();
    Acad::ErrorStatus   splineFit();
    Acad::ErrorStatus   splineFit(AcDb::Poly2dType splineType, Adesk::Int16 splineSegs);

    Acad::ErrorStatus appendVertex(const PyDb2dVertex& vt);
    Acad::ErrorStatus appendVertex(PyDbObjectId& id, const PyDb2dVertex& vt);

    Acad::ErrorStatus insertVertexAt(const PyDb2dVertex& pIndexVert, PyDb2dVertex& pNewVertex);
    Acad::ErrorStatus insertVertexAt(PyDbObjectId& newVertId, const PyDbObjectId& indexVertId, PyDb2dVertex& pNewVertex);

    Acad::ErrorStatus openVertex(PyDb2dVertex& vt, const PyDbObjectId& vertId, AcDb::OpenMode mode) const;

    Acad::ErrorStatus openSequenceEnd(PyDbSequenceEnd& end, AcDb::OpenMode mode);

    boost::python::list vertexIds() const;

    AcGePoint3d  vertexPosition(const AcDb2dVertex& vert) const;

    Acad::ErrorStatus makeClosedIfStartAndEndVertexCoincide(double distTol);

    static std::string className();
public:
    AcDb2dPolyline* impObj() const;
};

//-----------------------------------------------------------------------------------
//PyDb3dPolyline
void makePyDb3dPolylineWrapper();
class PyDb3dPolyline : public PyDbCurve
{
public:
    PyDb3dPolyline();
    PyDb3dPolyline(AcDb3dPolyline* ptr, bool autoDelete);
    PyDb3dPolyline(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDb3dPolyline(AcDb::Poly3dType, const boost::python::list& vertices, Adesk::Boolean closed);
    virtual ~PyDb3dPolyline() override = default;
    double  length() const;
    Acad::ErrorStatus  setClosed(Adesk::Boolean val);

    Acad::ErrorStatus makeClosed();
    Acad::ErrorStatus makeOpen();

    AcDb::Poly3dType    polyType() const;
    Acad::ErrorStatus   setPolyType(AcDb::Poly3dType val);
    Acad::ErrorStatus   convertToPolyType(AcDb::Poly3dType val);

    Acad::ErrorStatus   straighten();
    Acad::ErrorStatus   splineFit();
    Acad::ErrorStatus   splineFit(AcDb::Poly3dType splineType, Adesk::Int16   splineSegs);

    Acad::ErrorStatus appendVertex(const PyDb3dPolylineVertex& vt);
    Acad::ErrorStatus appendVertex(PyDbObjectId& id, const PyDb3dPolylineVertex& vt);

    Acad::ErrorStatus insertVertexAt(const PyDb3dPolylineVertex& pIndexVert, PyDb3dPolylineVertex& pNewVertex);
    Acad::ErrorStatus insertVertexAt(PyDbObjectId& newVertId, const PyDbObjectId& indexVertId, PyDb3dPolylineVertex& pNewVertex);

    Acad::ErrorStatus openVertex(PyDb3dPolylineVertex& vt, const PyDbObjectId& vertId, AcDb::OpenMode mode) const;
    Acad::ErrorStatus openSequenceEnd(PyDbSequenceEnd&, AcDb::OpenMode);

    boost::python::list vertexIds() const;

    static std::string className();
public:
    AcDb3dPolyline* impObj() const;
};

//-----------------------------------------------------------------------------------
//PyDbArc
void makePyDbArcWrapper();
class PyDbArc : public PyDbCurve
{
public:
    PyDbArc();
    PyDbArc(AcDbArc* ptr, bool autoDelete);
    PyDbArc(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbArc(const AcGePoint3d& center, double radius, double startAngle, double endAngle);
    PyDbArc(const AcGePoint3d& center, const AcGeVector3d& normal, double radius, double startAngle, double endAngle);
    virtual ~PyDbArc() override = default;

    AcGePoint3d         center() const;
    Acad::ErrorStatus   setCenter(const AcGePoint3d& val);

    double              radius() const;
    Acad::ErrorStatus   setRadius(double);

    double              startAngle() const;
    Acad::ErrorStatus   setStartAngle(double val);

    double              endAngle() const;
    Acad::ErrorStatus   setEndAngle(double val);

    double    totalAngle() const;
    double    length() const;

    double              thickness() const;
    Acad::ErrorStatus   setThickness(double);

    AcGeVector3d        normal() const;
    Acad::ErrorStatus   setNormal(const AcGeVector3d&);

    static std::string className();
public:
    AcDbArc* impObj() const;
};

//-----------------------------------------------------------------------------------
//PyDbCircle
void makPyDbCircleWrapper();
class PyDbCircle : public PyDbCurve
{
public:
    PyDbCircle();
    PyDbCircle(AcDbCircle* ptr, bool autoDelete);
    PyDbCircle(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbCircle(const AcGePoint3d& cntr, const AcGeVector3d& nrm, double radius);
    virtual ~PyDbCircle() override = default;

    AcGePoint3d         center() const;
    Acad::ErrorStatus   setCenter(const AcGePoint3d& val);

    double              radius() const;
    Acad::ErrorStatus   setRadius(double val);

    double              thickness() const;
    Acad::ErrorStatus   setThickness(double val);

    AcGeVector3d        normal() const;
    Acad::ErrorStatus   setNormal(const AcGeVector3d& val);

    double              circumference() const;
    Acad::ErrorStatus   setCircumference(double val);

    double              diameter() const;
    Acad::ErrorStatus   setDiameter(double val);

    static std::string className();
public:
    AcDbCircle* impObj() const;
};

//-----------------------------------------------------------------------------------
//PyDbLine
void makPyDbLineWrapper();
class PyDbLine : public PyDbCurve
{
public:
    PyDbLine();
    PyDbLine(AcDbLine* ptr, bool autoDelete);
    PyDbLine(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbLine(const AcGePoint3d& start, const AcGePoint3d& end);
    virtual ~PyDbLine() override = default;

    AcGePoint3d         startPoint() const;
    Acad::ErrorStatus   setStartPoint(const AcGePoint3d& val);

    AcGePoint3d         endPoint() const;
    Acad::ErrorStatus   setEndPoint(const AcGePoint3d& val);

    double              thickness() const;
    Acad::ErrorStatus   setThickness(double val);

    AcGeVector3d        normal() const;
    Acad::ErrorStatus   setNormal(const AcGeVector3d& val);

    boost::python::list getOffsetCurvesGivenPlaneNormal(const AcGeVector3d& normal, double offsetDist) const override;

    static std::string className();
public:
    AcDbLine* impObj() const;
};

//-----------------------------------------------------------------------------------
//PyDbPolyline
void makPyDbPolylineWrapper();
class PyDbPolyline : public PyDbCurve
{
public:
    PyDbPolyline();
    PyDbPolyline(unsigned int num_verts);
    PyDbPolyline(AcDbPolyline* ptr, bool autoDelete);
    PyDbPolyline(const PyDbObjectId& id, AcDb::OpenMode mode);
    virtual ~PyDbPolyline() override = default;

    AcGePoint3d getPoint3dAt(unsigned int) const;
    AcGePoint2d getPoint2dAt(unsigned int) const;

    AcDbPolyline::SegType segType(unsigned int index) const;
    virtual Adesk::Boolean onSegAt(unsigned int index, const AcGePoint2d& pt2d, double param) const;

    virtual void setClosed(Adesk::Boolean val);
    void         setPlinegen(Adesk::Boolean val);
    virtual void setElevation(double val);

    virtual Acad::ErrorStatus setThickness(double val);
    virtual Acad::ErrorStatus setConstantWidth(double val);
    virtual Acad::ErrorStatus setNormal(const AcGeVector3d& val);

    Adesk::Boolean    isOnlyLines() const;
    Adesk::Boolean    hasPlinegen() const;
    double            elevation() const;
    double            thickness() const;

    double getConstantWidth() const;
    AcGeVector3d      normal() const;
    virtual Acad::ErrorStatus addVertexAt(unsigned int index,const AcGePoint2d&,double bulge,double startWidth, double endWidth);

    virtual Acad::ErrorStatus removeVertexAt(unsigned int index);
    unsigned int      numVerts()const;

    double getBulgeAt(unsigned int index) const;
    double getStartWidthAt(unsigned int index) const;
    double getEndWidthAt(unsigned int index) const;

    virtual Acad::ErrorStatus setPointAt(unsigned int index,const AcGePoint2d& pt);
    virtual Acad::ErrorStatus setBulgeAt(unsigned int index, double bulge);
    virtual Acad::ErrorStatus setWidthsAt(unsigned int index,double startWidth, double endWidth);

    Acad::ErrorStatus minimizeMemory();
    Acad::ErrorStatus maximizeMemory();

    virtual void reset(Adesk::Boolean reuse,unsigned int numVerts);

    Adesk::Boolean     hasBulges()        const;
    Adesk::Boolean     hasVertexIdentifiers()    const;

    Adesk::Boolean     hasWidth()        const;
    Acad::ErrorStatus makeClosedIfStartAndEndVertexCoincide(double distTol);

    void              getEcs(AcGeMatrix3d& retVal) const override;

    static std::string className();
public:
    AcDbPolyline* impObj() const;
};

//-----------------------------------------------------------------------------------
//PyDbDace
void makPyDbFaceWrapper();
class PyDbFace : public PyDbEntity
{
public:
    PyDbFace();
    PyDbFace(const AcGePoint3d& pt0,
        const AcGePoint3d& pt1,
        const AcGePoint3d& pt2,
        Adesk::Boolean e0vis = Adesk::kTrue,
        Adesk::Boolean e1vis = Adesk::kTrue,
        Adesk::Boolean e2vis = Adesk::kTrue,
        Adesk::Boolean e3vis = Adesk::kTrue);
    PyDbFace(const AcGePoint3d& pt0,
        const AcGePoint3d& pt1,
        const AcGePoint3d& pt2,
        const AcGePoint3d& pt3,
        Adesk::Boolean e0vis = Adesk::kTrue,
        Adesk::Boolean e1vis = Adesk::kTrue,
        Adesk::Boolean e2vis = Adesk::kTrue,
        Adesk::Boolean e3vis = Adesk::kTrue);
    PyDbFace(AcDbPolyline* ptr, bool autoDelete);
    PyDbFace(const PyDbObjectId& id, AcDb::OpenMode mode);
    virtual ~PyDbFace() override = default;

    AcGePoint3d getVertexAt(Adesk::UInt16) const;
    Acad::ErrorStatus setVertexAt(Adesk::UInt16, const AcGePoint3d&);

    Adesk::Boolean isEdgeVisibleAt(Adesk::UInt16) const;
    Acad::ErrorStatus makeEdgeVisibleAt(Adesk::UInt16);
    Acad::ErrorStatus makeEdgeInvisibleAt(Adesk::UInt16);

    Adesk::Boolean      isPlanar() const override;
    //Acad::ErrorStatus   getPlane(AcGePlane& plane, AcDb::Planarity& planarity) const override;


    static std::string className();
public:
    AcDbFace* impObj() const;
};