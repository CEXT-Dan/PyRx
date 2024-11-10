#pragma once
#include "dbents.h"
#include "PyDbEntity.h"
#include "PyDbCurve.h"
#include "PyDbSymbolTableRecord.h"

#pragma pack(push, 8)

class PyDbObjectId;
class PyGeLineSeg2d;
class PyGeLineSeg3d;
class PyGeCircArc2d;
class PyGeCircArc3d;
class PyDbMText;
class PyDbHardPointerId;
class PyGeCompositeCurve3d;
class PyGeCompositeCurve2d;
class PyDbAttribute;


//-----------------------------------------------------------------------------------
//PyDbBlockReference
void makePyDbBlockReferenceWrapper();
class PyDbBlockReference : public PyDbEntity
{
public:
    PyDbBlockReference();
    PyDbBlockReference(const PyDbObjectId& id);
    PyDbBlockReference(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbBlockReference(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    PyDbBlockReference(const AcGePoint3d& position, const PyDbObjectId& blockTableRec);
    PyDbBlockReference(AcDbBlockReference* ptr, bool autoDelete);
    virtual ~PyDbBlockReference() override = default;
    PyDbObjectId        blockTableRecord() const;
    void                setBlockTableRecord(const PyDbObjectId& val);
    AcGePoint3d         position() const;
    void                setPosition(const AcGePoint3d& val);
    AcGeScale3d         scaleFactors() const;
    AcGeScale3d         nonAnnotationScaleFactors() const;
    void                setScaleFactors(const AcGeScale3d& scale);
    double              rotation() const;
    void                setRotation(double newVal);
    AcGeVector3d        normal() const;
    void                setNormal(const AcGeVector3d& newVal);
    AcGeMatrix3d        blockTransform() const;
    AcGeMatrix3d        nonAnnotationBlockTransform() const;
    void                setBlockTransform(const AcGeMatrix3d& val);
    PyDbObjectId        appendAttribute(PyDbAttribute& att);
    boost::python::list attributeIds() const;
    Adesk::Boolean      treatAsAcDbBlockRefForExplode() const;
    AcDbExtents         geomExtentsBestFit1() const;
    AcDbExtents         geomExtentsBestFit2(const AcGeMatrix3d& parentXform) const;
    void                explodeToOwnerSpace() const;
    std::string         getBlockName() const;
    static std::string  className();
    static PyRxClass    desc();
    static PyDbBlockReference cloneFrom(const PyRxObject& src);
    static PyDbBlockReference cast(const PyRxObject& src);
public:
    inline AcDbBlockReference* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//PyDbDynBlockReference
void makePyDbDynBlockReferenceWrapper();
class PyDbDynBlockReference
{
public:
    PyDbDynBlockReference(const PyDbObjectId& id);
    ~PyDbDynBlockReference() = default;
    bool                isDynamicBlock1() const;
    PyDbObjectId        blockId() const;
    void                resetBlock();
    void                convertToStaticBlock1();
    void                convertToStaticBlock2(const std::string& newBlockName);
    PyDbObjectId        dynamicBlockTableRecord() const;
    PyDbObjectId        anonymousBlockTableRecord() const;
    boost::python::list getBlockProperties() const;
    static bool         isDynamicBlock2(const PyDbObjectId& blockTableRecordId);
    static std::string  className();
public:
    inline AcDbDynBlockReference* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<AcDbDynBlockReference> m_imp;
};

//-----------------------------------------------------------------------------------
//PyDbMInsertBlock
void makePyDbMInsertBlockeWrapper();
class PyDbMInsertBlock : public  PyDbBlockReference
{
public:
    PyDbMInsertBlock();
    PyDbMInsertBlock(const AcGePoint3d& position, const PyDbObjectId& blockTableRec, Adesk::UInt16 columns, Adesk::UInt16 rows, double colSpacing, double rowSpacing);
    PyDbMInsertBlock(AcDbMInsertBlock* ptr, bool autoDelete);
    PyDbMInsertBlock(const PyDbObjectId& id);
    PyDbMInsertBlock(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbMInsertBlock(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    virtual ~PyDbMInsertBlock() override = default;
    Adesk::UInt16       columns() const;
    void                setColumns(Adesk::UInt16 val);
    Adesk::UInt16       rows() const;
    void                setRows(Adesk::UInt16 val);
    double              columnSpacing() const;
    void                setColumnSpacing(double val);
    double              rowSpacing() const;
    void                setRowSpacing(double val);
    static std::string className();
    static PyRxClass   desc();
    static PyDbMInsertBlock cloneFrom(const PyRxObject& src);
    static PyDbMInsertBlock cast(const PyRxObject& src);
public:
    inline AcDbMInsertBlock* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-------------------------------------------------------------------------------------------------------------
//PyDbVertex
void makePyDbVertexWrapper();
class PyDbVertex : public PyDbEntity
{
public:
    PyDbVertex();
    PyDbVertex(AcDbVertex* ptr, bool autoDelete);
    PyDbVertex(const PyDbObjectId& id);
    PyDbVertex(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbVertex(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    virtual ~PyDbVertex() = default;
    static std::string  className();
    static PyRxClass    desc();
    static PyDbVertex   cloneFrom(const PyRxObject& src);
    static PyDbVertex   cast(const PyRxObject& src);
public:
    inline AcDbVertex* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-------------------------------------------------------------------------------------------------------------
//PyDb2dVertex
void makePyDb2dVertexWrapper();
class PyDb2dVertex : public PyDbVertex
{
public:
    PyDb2dVertex();
    PyDb2dVertex(const AcGePoint3d& pos);
#if !defined(_BRXTARGET250)
    PyDb2dVertex(const AcGePoint3d& pos, double bulge, double startWidth, double endWidth, double tangent, Adesk::Int32 vertexIdentifier);
#endif
    PyDb2dVertex(AcDb2dVertex* ptr, bool autoDelete);
    PyDb2dVertex(const PyDbObjectId& id);
    PyDb2dVertex(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDb2dVertex(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    virtual ~PyDb2dVertex() = default;
    AcDb::Vertex2dType vertexType() const;
    AcGePoint3d         position() const;
    void                setPosition(const AcGePoint3d& val);
    double              startWidth() const;
    void                setStartWidth(double newVal);
    double              endWidth() const;
    void                setEndWidth(double newVal);
    double              bulge() const;
    void                setBulge(double newVal);
    Adesk::Boolean      isTangentUsed() const;
    void                useTangent();
    void                ignoreTangent();
    void                setTangentUsed(Adesk::Boolean val);
    double              tangent() const;
    void                setTangent(double newVal);
    void                setVertexIdentifier(Adesk::Int32 suggestedValue);
    int                 vertexIdentifier() const;
    static std::string  className();
    static PyRxClass    desc();
    static PyDb2dVertex cloneFrom(const PyRxObject& src);
    static PyDb2dVertex cast(const PyRxObject& src);
public:
    inline AcDb2dVertex* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-------------------------------------------------------------------------------------------------------------
//AcDb3dPolylineVertex
void makePyDb3dPolylineVertexWrapper();
class PyDb3dPolylineVertex : public PyDbVertex
{
public:
    PyDb3dPolylineVertex();
    PyDb3dPolylineVertex(const AcGePoint3d& pos);
    PyDb3dPolylineVertex(AcDb3dPolylineVertex* ptr, bool autoDelete);
    PyDb3dPolylineVertex(const PyDbObjectId& id);
    PyDb3dPolylineVertex(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDb3dPolylineVertex(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    virtual ~PyDb3dPolylineVertex() = default;
    AcDb::Vertex3dType  vertexType() const;
    AcGePoint3d         position() const;
    void                setPosition(const AcGePoint3d&);
    static std::string  className();
    static PyRxClass    desc();
    static PyDb3dPolylineVertex cloneFrom(const PyRxObject& src);
    static PyDb3dPolylineVertex cast(const PyRxObject& src);
public:
    inline AcDb3dPolylineVertex* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-------------------------------------------------------------------------------------------------------------
//AcDbPolygonMeshVertex
void makePyDbPolygonMeshVertexWrapper();
class PyDbPolygonMeshVertex : public PyDbVertex
{
public:
    PyDbPolygonMeshVertex();
    PyDbPolygonMeshVertex(const AcGePoint3d& pos);
    PyDbPolygonMeshVertex(AcDbPolygonMeshVertex* ptr, bool autoDelete);
    PyDbPolygonMeshVertex(const PyDbObjectId& id);
    PyDbPolygonMeshVertex(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbPolygonMeshVertex(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    virtual ~PyDbPolygonMeshVertex() = default;
    AcDb::Vertex3dType  vertexType() const;
    AcGePoint3d         position() const;
    void                setPosition(const AcGePoint3d&);
    static std::string  className();
    static PyRxClass    desc();
    static PyDbPolygonMeshVertex cloneFrom(const PyRxObject& src);
    static PyDbPolygonMeshVertex cast(const PyRxObject& src);
public:
    inline AcDbPolygonMeshVertex* impObj(const std::source_location& src = std::source_location::current()) const;
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
    PyDbPolyFaceMeshVertex(const PyDbObjectId& id);
    PyDbPolyFaceMeshVertex(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbPolyFaceMeshVertex(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    virtual ~PyDbPolyFaceMeshVertex() = default;
    AcGePoint3d         position() const;
    void                setPosition(const AcGePoint3d&);
    static std::string  className();
    static PyRxClass    desc();
    static PyDbPolyFaceMeshVertex cloneFrom(const PyRxObject& src);
    static PyDbPolyFaceMeshVertex cast(const PyRxObject& src);
public:
    inline AcDbPolyFaceMeshVertex* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-------------------------------------------------------------------------------------------------------------
//AcDbFaceRecord
void makePyDbFaceRecordWrapper();
class PyDbFaceRecord : public PyDbVertex
{
public:
    PyDbFaceRecord();
    PyDbFaceRecord(Adesk::Int16 vtx0, Adesk::Int16 vtx1, Adesk::Int16 vtx2, Adesk::Int16 vtx3);
    PyDbFaceRecord(AcDbFaceRecord* ptr, bool autoDelete);
    PyDbFaceRecord(const PyDbObjectId& id);
    PyDbFaceRecord(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbFaceRecord(const PyDbObjectId& id, AcDb::OpenMode mode, bool);
    virtual ~PyDbFaceRecord() = default;
    Adesk::Int16        getVertexAt(Adesk::UInt16 faceIdx) const;
    void                setVertexAt(Adesk::UInt16 faceIdx, Adesk::Int16 vtxIdx);
    Adesk::Boolean      isEdgeVisibleAt(Adesk::UInt16 faceIndex) const;
    void                makeEdgeVisibleAt(Adesk::UInt16 faceIndex);
    void                makeEdgeInvisibleAt(Adesk::UInt16 faceIndex);
    static std::string  className();
    static PyRxClass    desc();
    static PyDbFaceRecord cloneFrom(const PyRxObject& src);
    static PyDbFaceRecord cast(const PyRxObject& src);
public:
    inline AcDbFaceRecord* impObj(const std::source_location& src = std::source_location::current()) const;
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
    PyDbPoint(const PyDbObjectId& id);
    PyDbPoint(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbPoint(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    virtual ~PyDbPoint() override = default;
    AcGePoint3d         position() const;
    void                setPosition(const AcGePoint3d&);
    double              thickness() const;
    void                setThickness(double val);
    AcGeVector3d        normal() const;
    void                setNormal(const AcGeVector3d& val);
    double              ecsRotation() const;
    void                setEcsRotation(double);
    static std::string  className();
    static PyRxClass    desc();
    static PyDbPoint	cloneFrom(const PyRxObject& src);
    static PyDbPoint    cast(const PyRxObject& src);
public:
    inline AcDbPoint* impObj(const std::source_location& src = std::source_location::current()) const;
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
    PyDb2dPolyline(const PyDbObjectId& id);
    PyDb2dPolyline(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDb2dPolyline(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    PyDb2dPolyline(AcDb::Poly2dType type, const boost::python::list& vertices, Adesk::Boolean closed);
    AcDb::Poly2dType    polyType() const;
    void                setPolyType(AcDb::Poly2dType val);
    void                convertToPolyType(AcDb::Poly2dType val);
    void                makeClosed();
    void                makeOpen();
    void                setClosed(Adesk::Boolean val);
    double              constantWidth() const;
    void                setConstantWidth(double val);
    double              length() const;
    double              defaultStartWidth() const;
    void                setDefaultStartWidth(double val);
    double              defaultEndWidth() const;
    void                setDefaultEndWidth(double);
    double              thickness() const;
    void                setThickness(double val);
    AcGeVector3d        normal() const;
    void                setNormal(const AcGeVector3d& val);
    double              elevation() const;
    void                setElevation(double);
    Adesk::Boolean      isLinetypeGenerationOn() const;
    void                setLinetypeGenerationOn();
    void                setLinetypeGenerationOff();
    void                straighten();
    void                splineFit1();
    void                splineFit2(AcDb::Poly2dType splineType, Adesk::Int16 splineSegs);
    void                appendVertex1(const PyDb2dVertex& vt);
    void                appendVertex2(PyDbObjectId& id, const PyDb2dVertex& vt);
    void                insertVertexAt1(const PyDb2dVertex& pIndexVert, PyDb2dVertex& pNewVertex);
    void                insertVertexAt2(PyDbObjectId& newVertId, const PyDbObjectId& indexVertId, PyDb2dVertex& pNewVertex);
    PyDb2dVertex        openVertex(const PyDbObjectId& vertId, AcDb::OpenMode mode) const;
    PyDbSequenceEnd     openSequenceEnd(AcDb::OpenMode mode);
    boost::python::list vertexIds() const;
    AcGePoint3d         vertexPosition(const AcDb2dVertex& vert) const;
    void                makeClosedIfStartAndEndVertexCoincide(double distTol);
    static std::string  className();
    static PyRxClass    desc();
    static PyDb2dPolyline	cloneFrom(const PyRxObject& src);
    static PyDb2dPolyline   cast(const PyRxObject& src);
public:
    inline AcDb2dPolyline* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//PyDb3dPolyline
void makePyDb3dPolylineWrapper();
class PyDb3dPolyline : public PyDbCurve
{
public:
    PyDb3dPolyline();
    PyDb3dPolyline(AcDb3dPolyline* ptr, bool autoDelete);
    PyDb3dPolyline(const PyDbObjectId& id);
    PyDb3dPolyline(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDb3dPolyline(const PyDbObjectId& id, AcDb::OpenMode mode, bool openErased);
    PyDb3dPolyline(AcDb::Poly3dType, const boost::python::list& vertices, Adesk::Boolean closed);
    virtual ~PyDb3dPolyline() override = default;
    double              length() const;
    void                setClosed(Adesk::Boolean val);
    void                makeClosed();
    void                makeOpen();
    AcDb::Poly3dType    polyType() const;
    void                setPolyType(AcDb::Poly3dType val);
    void                convertToPolyType(AcDb::Poly3dType val);
    void                straighten();
    void                splineFit1();
    void                splineFit2(AcDb::Poly3dType splineType, Adesk::Int16 splineSegs);
    void                appendVertex1(const PyDb3dPolylineVertex& vt);
    void                appendVertex2(PyDbObjectId& id, const PyDb3dPolylineVertex& vt);
    void                insertVertexAt1(const PyDb3dPolylineVertex& pIndexVert, PyDb3dPolylineVertex& pNewVertex);
    void                insertVertexAt2(PyDbObjectId& newVertId, const PyDbObjectId& indexVertId, PyDb3dPolylineVertex& pNewVertex);
    PyDb3dPolylineVertex openVertex(const PyDbObjectId& vertId, AcDb::OpenMode mode) const;
    PyDbSequenceEnd      openSequenceEnd(AcDb::OpenMode);
    PyGeCompositeCurve3d  getAcGeCurve1() const;
    PyGeCompositeCurve3d  getAcGeCurve2(const AcGeTol& tol) const;
    boost::python::list vertexIds() const;
    static std::string  className();
    static PyRxClass    desc();
    static PyDb3dPolyline cloneFrom(const PyRxObject& src);
    static PyDb3dPolyline cast(const PyRxObject& src);
public:
    inline AcDb3dPolyline* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//PyDbArc
void makePyDbArcWrapper();
class PyDbArc : public PyDbCurve
{
public:
    PyDbArc();
    PyDbArc(AcDbArc* ptr, bool autoDelete);
    PyDbArc(const PyDbObjectId& id);
    PyDbArc(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbArc(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    PyDbArc(const AcGePoint3d& center, double radius, double startAngle, double endAngle);
    PyDbArc(const AcGePoint3d& center, const AcGeVector3d& normal, double radius, double startAngle, double endAngle);
    virtual ~PyDbArc() override = default;
    AcGePoint3d         center() const;
    void                setCenter(const AcGePoint3d& val);
    double              radius() const;
    void                setRadius(double);
    double              startAngle() const;
    void                setStartAngle(double val);
    double              endAngle() const;
    void                setEndAngle(double val);
    double              totalAngle() const;
    double              length() const;
    double              thickness() const;
    void                setThickness(double);
    AcGeVector3d        normal() const;
    void                setNormal(const AcGeVector3d&);
    PyGeCircArc3d       getAcGeCurve1() const;
    PyGeCircArc3d       getAcGeCurve2(const AcGeTol& tol) const;
    static std::string  className();
    static PyRxClass    desc();
    static PyDbArc		cloneFrom(const PyRxObject& src);
    static PyDbArc      cast(const PyRxObject& src);
public:
    inline AcDbArc* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//PyDbCircle
void makePyDbCircleWrapper();
class PyDbCircle : public PyDbCurve
{
public:
    PyDbCircle();
    PyDbCircle(AcDbCircle* ptr, bool autoDelete);
    PyDbCircle(const PyDbObjectId& id);
    PyDbCircle(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbCircle(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    PyDbCircle(const AcGePoint3d& cntr, const AcGeVector3d& nrm, double radius);
    virtual ~PyDbCircle() override = default;
    AcGePoint3d         center() const;
    void                setCenter(const AcGePoint3d& val);
    double              radius() const;
    void                setRadius(double val);
    double              thickness() const;
    void                setThickness(double val);
    AcGeVector3d        normal() const;
    void                setNormal(const AcGeVector3d& val);
    double              circumference() const;
    void                setCircumference(double val);
    double              diameter() const;
    void                setDiameter(double val);
    PyGeCircArc3d       getAcGeCurve1() const;
    PyGeCircArc3d       getAcGeCurve2(const AcGeTol& tol) const;
    static std::string  className();
    static PyRxClass    desc();
    static PyDbCircle	cloneFrom(const PyRxObject& src);
    static PyDbCircle   cast(const PyRxObject& src);
public:
    inline AcDbCircle* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//PyDbLine
void makePyDbLineWrapper();
class PyDbLine : public PyDbCurve
{
public:
    PyDbLine();
    PyDbLine(AcDbLine* ptr, bool autoDelete);
    PyDbLine(const PyDbObjectId& id);
    PyDbLine(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbLine(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    PyDbLine(const AcGePoint3d& start, const AcGePoint3d& end);
    virtual ~PyDbLine() override = default;
    AcGePoint3d         startPoint() const;
    void                setStartPoint(const AcGePoint3d& val);
    AcGePoint3d         endPoint() const;
    AcGePoint3d         midPoint() const;
    void                setEndPoint(const AcGePoint3d& val);
    double              thickness() const;
    void                setThickness(double val);
    AcGeVector3d        normal() const;
    void                setNormal(const AcGeVector3d& val);
    PyGeLineSeg3d       getAcGeCurve1() const;
    PyGeLineSeg3d       getAcGeCurve2(const AcGeTol& tol) const;
    AcGeVector3d        direction() const;
    static std::string  className();
    static PyRxClass    desc();
    static PyDbLine		cloneFrom(const PyRxObject& src);
    static PyDbLine     cast(const PyRxObject& src);
public:
    inline AcDbLine* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//PyDbPolyline
void makePyDbPolylineWrapper();
class PyDbPolyline : public PyDbCurve
{
public:
    PyDbPolyline();
    PyDbPolyline(unsigned int num_verts);
    PyDbPolyline(const boost::python::list& pnts);
    PyDbPolyline(AcDbPolyline* ptr, bool autoDelete);
    PyDbPolyline(const PyDbObjectId& id);
    PyDbPolyline(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbPolyline(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    virtual ~PyDbPolyline() override = default;
    AcGePoint3d         getPoint3dAt(unsigned int) const;
    AcGePoint2d         getPoint2dAt(unsigned int) const;
    AcDbPolyline::SegType segType(unsigned int index) const;
    Adesk::Boolean      onSegAt(unsigned int index, const AcGePoint2d& pt2d, double param) const;
    PyGeLineSeg2d       getLineSeg2dAt(unsigned int index);
    PyGeLineSeg3d       getLineSeg3dAt(unsigned int index);
    PyGeCircArc2d       getArcSeg2dAt(unsigned int index);
    PyGeCircArc3d       getArcSeg3dAt(unsigned int index);
    void                setClosed(Adesk::Boolean val);
    void                setPlinegen(Adesk::Boolean val);
    void                setElevation(double val);
    void                setThickness(double val);
    void                setConstantWidth(double val);
    void                setNormal(const AcGeVector3d& val);
    Adesk::Boolean      isOnlyLines() const;
    Adesk::Boolean      hasPlinegen() const;
    double              elevation() const;
    double              thickness() const;
    double              getConstantWidth() const;
    AcGeVector3d        normal() const;
    void                addVertexAt1(unsigned int index, const AcGePoint2d&);
    void                addVertexAt2(unsigned int index, const AcGePoint2d&, double bulge, double startWidth, double endWidth);
    void                removeVertexAt(unsigned int index);
    unsigned int        numVerts()const;
    double              getBulgeAt(unsigned int index) const;
    double              getStartWidthAt(unsigned int index) const;
    double              getEndWidthAt(unsigned int index) const;
    void                setPointAt(unsigned int index, const AcGePoint2d& pt);
    void                setBulgeAt(unsigned int index, double bulge);
    void                setWidthsAt(unsigned int index, double startWidth, double endWidth);
    void                minimizeMemory();
    void                maximizeMemory();
    void                reset(Adesk::Boolean reuse, unsigned int numVerts);
    Adesk::Boolean      hasBulges()        const;
    Adesk::Boolean      hasVertexIdentifiers()    const;
    Adesk::Boolean      hasWidth()        const;
    void                makeClosedIfStartAndEndVertexCoincide(double distTol);
    PyGeCompositeCurve3d  getAcGeCurve1() const;
    PyGeCompositeCurve3d  getAcGeCurve2(const AcGeTol& tol) const;
    PyGeCompositeCurve2d  getAcGeCurve2d() const;
    boost::python::list   toPoint2dList();
    boost::python::list   toPoint3dList();
    boost::python::list   toList();
    static std::string  className();
    static PyRxClass    desc();
    static PyDbPolyline	cloneFrom(const PyRxObject& src);
    static PyDbPolyline cast(const PyRxObject& src);
public:
    inline AcDbPolyline* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//PyDbDace
void makePyDbFaceWrapper();
class PyDbFace : public PyDbEntity
{
public:
    PyDbFace();
    PyDbFace(const AcGePoint3d& pt0,
        const AcGePoint3d& pt1,
        const AcGePoint3d& pt2);
    PyDbFace(const AcGePoint3d& pt0,
        const AcGePoint3d& pt1,
        const AcGePoint3d& pt2,
        const AcGePoint3d& pt3);
    PyDbFace(const AcGePoint3d& pt0,
        const AcGePoint3d& pt1,
        const AcGePoint3d& pt2,
        Adesk::Boolean e0vis,
        Adesk::Boolean e1vis,
        Adesk::Boolean e2vis,
        Adesk::Boolean e3vis);
    PyDbFace(const AcGePoint3d& pt0,
        const AcGePoint3d& pt1,
        const AcGePoint3d& pt2,
        const AcGePoint3d& pt3,
        Adesk::Boolean e0vis,
        Adesk::Boolean e1vis,
        Adesk::Boolean e2vis,
        Adesk::Boolean e3vis);
    PyDbFace(AcDbFace* ptr, bool autoDelete);
    PyDbFace(const PyDbObjectId& id);
    PyDbFace(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbFace(const PyDbObjectId& id, AcDb::OpenMode mode, bool);
    virtual ~PyDbFace() override = default;
    AcGePoint3d         getVertexAt(Adesk::UInt16) const;
    void                setVertexAt(Adesk::UInt16, const AcGePoint3d&);
    Adesk::Boolean      isEdgeVisibleAt(Adesk::UInt16) const;
    void                makeEdgeVisibleAt(Adesk::UInt16);
    void                makeEdgeInvisibleAt(Adesk::UInt16);
    static std::string  className();
    static PyRxClass    desc();
    static PyDbFace		cloneFrom(const PyRxObject& src);
    static PyDbFace     cast(const PyRxObject& src);
public:
    inline AcDbFace* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//AcDbFcf
void makePyDbFcfWrapper();
class PyDbFcf : public PyDbEntity
{
public:
    PyDbFcf();
    PyDbFcf(AcDbFcf* ptr, bool autoDelete);
    PyDbFcf(const PyDbObjectId& id);
    PyDbFcf(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbFcf(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    PyDbFcf(const std::string&, const AcGePoint3d& pnt, const AcGeVector3d& normal, const AcGeVector3d& direction);
    virtual ~PyDbFcf() override = default;
    void				setText(const std::string& val);
    std::string			text(int lineNo) const;
    std::string			textAll() const;
    void				setLocation(const AcGePoint3d& val);
    AcGePoint3d			location() const;
    void				setOrientation(const AcGeVector3d& norm, const AcGeVector3d& dir);
    AcGeVector3d		normal()    const;
    AcGeVector3d		direction() const;
    boost::python::list getBoundingPoints() const;
    boost::python::list getBoundingPline()  const;
    void                setDimensionStyle(const PyDbHardPointerId& id);
    PyDbHardPointerId	dimensionStyle() const;
    PyDbDimStyleTableRecord getDimstyleData() const;
    void                setDimstyleData2(const PyDbDimStyleTableRecord& pNewData);
    void                setDimstyleData1(const PyDbObjectId& newDataId);
    void				setDimVars();
    AcCmColor			dimclrd() const;
    AcCmColor			dimclrt() const;
    double				dimgap() const;
    double				dimscale() const;
    PyDbObjectId		dimtxsty() const;
    double				dimtxt() const;
    void	            setDimclrd(AcCmColor& val);
    void	            setDimclrt(AcCmColor& val);
    void	            setDimgap(double val);
    void	            setDimscale(double val);
    void	            setDimtxsty(PyDbObjectId& val);
    void	            setDimtxt(double val);

public:
    static std::string  className();
    static PyRxClass    desc();
    static PyDbFcf		cloneFrom(const PyRxObject& src);
    static PyDbFcf      cast(const PyRxObject& src);
public:
    inline AcDbFcf* impObj(const std::source_location& src = std::source_location::current()) const;
};


//-----------------------------------------------------------------------------------
//AcDbSolid
void makePyDbSolidWrapper();

class PyDbSolid : public PyDbEntity
{
public:
    PyDbSolid();
    PyDbSolid(AcDbSolid* ptr, bool autoDelete);
    PyDbSolid(const PyDbObjectId& id);
    PyDbSolid(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbSolid(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    PyDbSolid(const AcGePoint3d& pnt0, const AcGePoint3d& pnt1, const AcGePoint3d& pnt2);
    PyDbSolid(const AcGePoint3d& pnt0, const AcGePoint3d& pnt1, const AcGePoint3d& pnt2, const AcGePoint3d& pnt3);
    virtual ~PyDbSolid() override = default;
    AcGePoint3d         getPointAt(Adesk::UInt16 idx);
    void                setPointAt(Adesk::UInt16 idx, const AcGePoint3d& val);
    double              thickness() const;
    void                setThickness(double);
    AcGeVector3d        normal() const;
    void                setNormal(const AcGeVector3d& val);
public:
    static std::string  className();
    static PyRxClass    desc();
    static PyDbSolid	cloneFrom(const PyRxObject& src);
    static PyDbSolid    cast(const PyRxObject& src);
public:
    inline AcDbSolid* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//AcDbTrace
void makePyDbTraceWrapper();

class PyDbTrace : public PyDbEntity
{
public:
    PyDbTrace();
    PyDbTrace(const PyDbObjectId& id);
    PyDbTrace(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbTrace(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    PyDbTrace(const AcGePoint3d& pnt0, const AcGePoint3d& pnt1, const AcGePoint3d& pnt2, const AcGePoint3d& pnt3);
    PyDbTrace(AcDbTrace* ptr, bool autoDelete);
    virtual ~PyDbTrace() override = default;
    AcGePoint3d         getPointAt(Adesk::UInt16 idx);
    void                setPointAt(Adesk::UInt16 idx, const AcGePoint3d& val);
    double              thickness() const;
    void                setThickness(double val);
    AcGeVector3d        normal() const;
    void                setNormal(const AcGeVector3d& val);
public:
    static std::string  className();
    static PyRxClass    desc();
    static PyDbTrace	cloneFrom(const PyRxObject& src);
    static PyDbTrace    cast(const PyRxObject& src);
public:
    inline AcDbTrace* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//AcDbShape
void makePyDbShapeWrapper();

class PyDbShape : public PyDbEntity
{
public:
    PyDbShape();
    PyDbShape(const PyDbObjectId& id);
    PyDbShape(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbShape(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    PyDbShape(const AcGePoint3d& position, double size, double rotation, double widthFactor);
    PyDbShape(AcDbShape* ptr, bool autoDelete);
    virtual ~PyDbShape() override = default;

    AcGePoint3d     position() const;
    void            setPosition(const AcGePoint3d& val);
    double          size() const;
    void            setSize(double val);
    std::string     name() const;
    void            setName(const std::string& val);
    double          rotation() const;
    void            setRotation(double val);
    double          widthFactor() const;
    void            setWidthFactor(double val);
    double          oblique() const;
    void            setOblique(double val);
    double          thickness() const;
    void            setThickness(double val);
    AcGeVector3d    normal() const;
    void            setNormal(const AcGeVector3d& val);
    Adesk::Int16    shapeNumber() const;
    void            setShapeNumber(Adesk::Int16 idx);
    PyDbObjectId    styleId() const;
    void            setStyleId(const PyDbObjectId& id);

public:
    static std::string  className();
    static PyRxClass    desc();
    static PyDbShape	cloneFrom(const PyRxObject& src);
    static PyDbShape    cast(const PyRxObject& src);
public:
    inline AcDbShape* impObj(const std::source_location& src = std::source_location::current()) const;
};



#pragma pack (pop)