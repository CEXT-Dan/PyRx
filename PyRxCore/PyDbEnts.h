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
class PyRxOverrulableEntity;


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
    void                setBlockTableRecord(const PyDbObjectId& val) const;
    AcGePoint3d         position() const;
    void                setPosition(const AcGePoint3d& val) const;
    AcGeScale3d         scaleFactors() const;
    AcGeScale3d         nonAnnotationScaleFactors() const;
    void                setScaleFactors(const AcGeScale3d& scale) const;
    double              rotation() const;
    void                setRotation(double newVal) const;
    AcGeVector3d        normal() const;
    void                setNormal(const AcGeVector3d& newVal) const;
    AcGeMatrix3d        blockTransform() const;
    AcGeMatrix3d        nonAnnotationBlockTransform() const;
    void                setBlockTransform(const AcGeMatrix3d& val) const;
    PyDbObjectId        appendAttribute(PyDbAttribute& att) const;
    boost::python::list attributeIds() const;
    boost::python::dict attdict() const;
    boost::python::list attlist() const;
    Adesk::Boolean      treatAsAcDbBlockRefForExplode() const;
    AcDbExtents         geomExtentsBestFit1() const;
    AcDbExtents         geomExtentsBestFit2(const AcGeMatrix3d& parentXform) const;
    void                explodeToOwnerSpace() const;
    std::string         getBlockName() const;
public:
    static std::string  className();
    static PyRxClass    desc();
    static PyDbBlockReference cloneFrom(const PyRxObject& src);
    static PyDbBlockReference cast(const PyRxObject& src);
public:
    AcDbBlockReference* impObj(const std::source_location& src = std::source_location::current()) const;
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
    void                resetBlock() const;
    void                convertToStaticBlock1() const;
    void                convertToStaticBlock2(const std::string& newBlockName) const;
    PyDbObjectId        dynamicBlockTableRecord() const;
    PyDbObjectId        anonymousBlockTableRecord() const;
    boost::python::list getBlockProperties() const;
public:
    static bool         isDynamicBlock2(const PyDbObjectId& blockTableRecordId);
    static std::string  className();
public:
    AcDbDynBlockReference* impObj(const std::source_location& src = std::source_location::current()) const;
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
    void                setColumns(Adesk::UInt16 val) const;
    Adesk::UInt16       rows() const;
    void                setRows(Adesk::UInt16 val) const;
    double              columnSpacing() const;
    void                setColumnSpacing(double val) const;
    double              rowSpacing() const;
    void                setRowSpacing(double val) const;
public:
    static std::string  className();
    static PyRxClass    desc();
    static PyDbMInsertBlock cloneFrom(const PyRxObject& src);
    static PyDbMInsertBlock cast(const PyRxObject& src);
public:
    AcDbMInsertBlock* impObj(const std::source_location& src = std::source_location::current()) const;
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
public:
    static std::string  className();
    static PyRxClass    desc();
    static PyDbVertex   cloneFrom(const PyRxObject& src);
    static PyDbVertex   cast(const PyRxObject& src);
public:
    AcDbVertex* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-------------------------------------------------------------------------------------------------------------
//PyDb2dVertex
void makePyDb2dVertexWrapper();
class PyDb2dVertex : public PyDbVertex
{
public:
    PyDb2dVertex();
    PyDb2dVertex(const AcGePoint3d& pos);
#if !defined(_BRXTARGET260)
    PyDb2dVertex(const AcGePoint3d& pos, double bulge, double startWidth, double endWidth, double tangent, Adesk::Int32 vertexIdentifier);
#endif
    PyDb2dVertex(AcDb2dVertex* ptr, bool autoDelete);
    PyDb2dVertex(const PyDbObjectId& id);
    PyDb2dVertex(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDb2dVertex(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    virtual ~PyDb2dVertex() = default;
    AcDb::Vertex2dType  vertexType() const;
    AcGePoint3d         position() const;
    void                setPosition(const AcGePoint3d& val) const;
    double              startWidth() const;
    void                setStartWidth(double newVal) const;
    double              endWidth() const;
    void                setEndWidth(double newVal) const;
    double              bulge() const;
    void                setBulge(double newVal) const;
    Adesk::Boolean      isTangentUsed() const;
    void                useTangent() const;
    void                ignoreTangent() const;
    void                setTangentUsed(Adesk::Boolean val) const;
    double              tangent() const;
    void                setTangent(double newVal) const;
    void                setVertexIdentifier(Adesk::Int32 suggestedValue) const;
    int                 vertexIdentifier() const;
public:
    static std::string  className();
    static PyRxClass    desc();
    static PyDb2dVertex cloneFrom(const PyRxObject& src);
    static PyDb2dVertex cast(const PyRxObject& src);
public:
    AcDb2dVertex* impObj(const std::source_location& src = std::source_location::current()) const;
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
    void                setPosition(const AcGePoint3d&) const;
public:
    static std::string  className();
    static PyRxClass    desc();
    static PyDb3dPolylineVertex cloneFrom(const PyRxObject& src);
    static PyDb3dPolylineVertex cast(const PyRxObject& src);
public:
    AcDb3dPolylineVertex* impObj(const std::source_location& src = std::source_location::current()) const;
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
    void                setPosition(const AcGePoint3d&) const;
public:
    static std::string  className();
    static PyRxClass    desc();
    static PyDbPolygonMeshVertex cloneFrom(const PyRxObject& src);
    static PyDbPolygonMeshVertex cast(const PyRxObject& src);
public:
    AcDbPolygonMeshVertex* impObj(const std::source_location& src = std::source_location::current()) const;
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
    void                setPosition(const AcGePoint3d&) const;
public:
    static std::string  className();
    static PyRxClass    desc();
    static PyDbPolyFaceMeshVertex cloneFrom(const PyRxObject& src);
    static PyDbPolyFaceMeshVertex cast(const PyRxObject& src);
public:
    AcDbPolyFaceMeshVertex* impObj(const std::source_location& src = std::source_location::current()) const;
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
    void                setVertexAt(Adesk::UInt16 faceIdx, Adesk::Int16 vtxIdx) const;
    Adesk::Boolean      isEdgeVisibleAt(Adesk::UInt16 faceIndex) const;
    void                makeEdgeVisibleAt(Adesk::UInt16 faceIndex) const;
    void                makeEdgeInvisibleAt(Adesk::UInt16 faceIndex) const;
public:
    static std::string  className();
    static PyRxClass    desc();
    static PyDbFaceRecord cloneFrom(const PyRxObject& src);
    static PyDbFaceRecord cast(const PyRxObject& src);
public:
    AcDbFaceRecord* impObj(const std::source_location& src = std::source_location::current()) const;
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
    void                setPosition(const AcGePoint3d&) const;
    double              thickness() const;
    void                setThickness(double val) const;
    AcGeVector3d        normal() const;
    void                setNormal(const AcGeVector3d& val) const;
    double              ecsRotation() const;
    void                setEcsRotation(double) const;
public:
    static std::string  className();
    static PyRxClass    desc();
    static PyDbPoint	cloneFrom(const PyRxObject& src);
    static PyDbPoint    cast(const PyRxObject& src);
public:
    AcDbPoint* impObj(const std::source_location& src = std::source_location::current()) const;
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
    PyDb2dPolyline(AcDb::Poly2dType type, const PyGePoint3dArray& vertices, Adesk::Boolean closed);
    AcDb::Poly2dType    polyType() const;
    void                setPolyType(AcDb::Poly2dType val) const;
    void                convertToPolyType(AcDb::Poly2dType val) const;
    void                makeClosed() const;
    void                makeOpen() const;
    void                setClosed(Adesk::Boolean val) const;
    double              constantWidth() const;
    void                setConstantWidth(double val) const;
    double              length() const;
    double              defaultStartWidth() const;
    void                setDefaultStartWidth(double val) const;
    double              defaultEndWidth() const;
    void                setDefaultEndWidth(double) const;
    double              thickness() const;
    void                setThickness(double val) const;
    AcGeVector3d        normal() const;
    void                setNormal(const AcGeVector3d& val) const;
    double              elevation() const;
    void                setElevation(double) const;
    Adesk::Boolean      isLinetypeGenerationOn() const;
    void                setLinetypeGenerationOn() const;
    void                setLinetypeGenerationOff() const;
    void                straighten() const;
    void                splineFit1() const;
    void                splineFit2(AcDb::Poly2dType splineType, Adesk::Int16 splineSegs) const;
    void                appendVertex1(const PyDb2dVertex& vt) const;
    void                appendVertex2(PyDbObjectId& id, const PyDb2dVertex& vt) const;
    void                insertVertexAt1(const PyDb2dVertex& pIndexVert, PyDb2dVertex& pNewVertex) const;
    void                insertVertexAt2(PyDbObjectId& newVertId, const PyDbObjectId& indexVertId, PyDb2dVertex& pNewVertex) const;
    PyDb2dVertex        openVertex(const PyDbObjectId& vertId, AcDb::OpenMode mode) const;
    PyDbSequenceEnd     openSequenceEnd(AcDb::OpenMode mode) const;
    boost::python::list vertexIds() const;
    AcGePoint3d         vertexPosition(const AcDb2dVertex& vert) const;
    void                makeClosedIfStartAndEndVertexCoincide(double distTol) const;
public:
    static std::string  className();
    static PyRxClass    desc();
    static PyDb2dPolyline	cloneFrom(const PyRxObject& src);
    static PyDb2dPolyline   cast(const PyRxObject& src);
public:
    AcDb2dPolyline* impObj(const std::source_location& src = std::source_location::current()) const;
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
    PyDb3dPolyline(AcDb::Poly3dType, const PyGePoint3dArray& vertices, Adesk::Boolean closed);

    virtual ~PyDb3dPolyline() override = default;
    double              length() const;
    void                setClosed(Adesk::Boolean val) const;
    void                makeClosed() const;
    void                makeOpen() const;
    AcDb::Poly3dType    polyType() const;
    void                setPolyType(AcDb::Poly3dType val) const;
    void                convertToPolyType(AcDb::Poly3dType val) const;
    void                straighten() const;
    void                splineFit1() const;
    void                splineFit2(AcDb::Poly3dType splineType, Adesk::Int16 splineSegs) const;
    void                appendVertex1(const PyDb3dPolylineVertex& vt) const;
    void                appendVertex2(PyDbObjectId& id, const PyDb3dPolylineVertex& vt) const;
    void                insertVertexAt1(const PyDb3dPolylineVertex& pIndexVert, PyDb3dPolylineVertex& pNewVertex) const;
    void                insertVertexAt2(PyDbObjectId& newVertId, const PyDbObjectId& indexVertId, PyDb3dPolylineVertex& pNewVertex) const;
    PyDb3dPolylineVertex    openVertex(const PyDbObjectId& vertId, AcDb::OpenMode mode) const;
    PyDbSequenceEnd         openSequenceEnd(AcDb::OpenMode) const;
    PyGeCompositeCurve3d    getAcGeCurve1() const;
    PyGeCompositeCurve3d    getAcGeCurve2(const AcGeTol& tol) const;
    boost::python::list vertexIds() const;
public:
    static std::string  className();
    static PyRxClass    desc();
    static PyDb3dPolyline cloneFrom(const PyRxObject& src);
    static PyDb3dPolyline cast(const PyRxObject& src);
public:
    AcDb3dPolyline* impObj(const std::source_location& src = std::source_location::current()) const;
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
    void                setCenter(const AcGePoint3d& val) const;
    double              radius() const;
    void                setRadius(double) const;
    double              startAngle() const;
    void                setStartAngle(double val) const;
    double              endAngle() const;
    void                setEndAngle(double val) const;
    double              totalAngle() const;
    double              length() const;
    double              thickness() const;
    void                setThickness(double) const;
    AcGeVector3d        normal() const;
    void                setNormal(const AcGeVector3d&) const;
    PyGeCircArc3d       getAcGeCurve1() const;
    PyGeCircArc3d       getAcGeCurve2(const AcGeTol& tol) const;
public:
    static std::string  className();
    static PyRxClass    desc();
    static PyDbArc		cloneFrom(const PyRxObject& src);
    static PyDbArc      cast(const PyRxObject& src);
public:
    AcDbArc* impObj(const std::source_location& src = std::source_location::current()) const;
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
    inline virtual ~PyDbCircle() override = default;
    AcGePoint3d         center() const;
    void                setCenter(const AcGePoint3d& val) const;
    double              radius() const;
    void                setRadius(double val) const;
    double              thickness() const;
    void                setThickness(double val) const;
    AcGeVector3d        normal() const;
    void                setNormal(const AcGeVector3d& val) const;
    double              circumference() const;
    void                setCircumference(double val) const;
    double              diameter() const;
    void                setDiameter(double val) const;
    PyGeCircArc3d       getAcGeCurve1() const;
    PyGeCircArc3d       getAcGeCurve2(const AcGeTol& tol) const;
public:
    static std::string  className();
    static PyRxClass    desc();
    static PyDbCircle	cloneFrom(const PyRxObject& src);
    static PyDbCircle   cast(const PyRxObject& src);
public:
    AcDbCircle* impObj(const std::source_location& src = std::source_location::current()) const;
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
    void                setStartPoint(const AcGePoint3d& val) const;
    AcGePoint3d         endPoint() const;
    AcGePoint3d         midPoint() const;
    void                setEndPoint(const AcGePoint3d& val) const;
    double              thickness() const;
    void                setThickness(double val) const;
    AcGeVector3d        normal() const;
    void                setNormal(const AcGeVector3d& val) const;
    PyGeLineSeg3d       getAcGeCurve1() const;
    PyGeLineSeg3d       getAcGeCurve2(const AcGeTol& tol) const;
    AcGeVector3d        direction() const;
public:
    static std::string  className();
    static PyRxClass    desc();
    static PyDbLine		cloneFrom(const PyRxObject& src);
    static PyDbLine     cast(const PyRxObject& src);
public:
    AcDbLine* impObj(const std::source_location& src = std::source_location::current()) const;
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
    PyDbPolyline(const PyGePoint2dArray& pnts);
    PyDbPolyline(const PyGePoint3dArray& pnts);
    PyDbPolyline(AcDbPolyline* ptr, bool autoDelete);
    PyDbPolyline(const PyDbObjectId& id);
    PyDbPolyline(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbPolyline(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    virtual ~PyDbPolyline() override = default;
    AcGePoint3d         getPoint3dAt(unsigned int) const;
    AcGePoint2d         getPoint2dAt(unsigned int) const;
    AcDbPolyline::SegType segType(unsigned int index) const;
    Adesk::Boolean      onSegAt(unsigned int index, const AcGePoint2d& pt2d, double param) const;
    PyGeLineSeg2d       getLineSeg2dAt(unsigned int index) const;
    PyGeLineSeg3d       getLineSeg3dAt(unsigned int index) const;
    PyGeCircArc2d       getArcSeg2dAt(unsigned int index) const;
    PyGeCircArc3d       getArcSeg3dAt(unsigned int index) const;
    void                setClosed(Adesk::Boolean val) const;
    void                setPlinegen(Adesk::Boolean val) const;
    void                setElevation(double val) const;
    void                setThickness(double val) const;
    void                setConstantWidth(double val) const;
    void                setNormal(const AcGeVector3d& val) const;
    Adesk::Boolean      isOnlyLines() const;
    Adesk::Boolean      hasPlinegen() const;
    double              elevation() const;
    double              thickness() const;
    double              getConstantWidth() const;
    AcGeVector3d        normal() const;
    void                addVertexAt1(unsigned int index, const AcGePoint2d&) const;
    void                addVertexAt2(unsigned int index, const AcGePoint2d&, double bulge, double startWidth, double endWidth) const;
    void                removeVertexAt(unsigned int index) const;
    unsigned int        numVerts()const;
    double              getBulgeAt(unsigned int index) const;
    double              getStartWidthAt(unsigned int index) const;
    double              getEndWidthAt(unsigned int index) const;
    void                setPointAt(unsigned int index, const AcGePoint2d& pt) const;
    void                setBulgeAt(unsigned int index, double bulge) const;
    void                setWidthsAt(unsigned int index, double startWidth, double endWidth) const;
    void                minimizeMemory() const;
    void                maximizeMemory() const;
    void                reset(Adesk::Boolean reuse, unsigned int numVerts) const;
    Adesk::Boolean      hasBulges()        const;
    Adesk::Boolean      hasVertexIdentifiers()    const;
    Adesk::Boolean      hasWidth()        const;
    void                makeClosedIfStartAndEndVertexCoincide(double distTol) const;
    PyGeCompositeCurve3d  getAcGeCurve1() const;
    PyGeCompositeCurve3d  getAcGeCurve2(const AcGeTol& tol) const;
    PyGeCompositeCurve2d  getAcGeCurve2d() const;
    boost::python::list   toPoint2dList() const;
    boost::python::list   toPoint3dList() const;
    boost::python::list   toList() const;
    bool                isPointInside(const AcGePoint3d& pnt) const;
    bool                isCCW() const;
    void                simplify(double dist) const;
public:
    static std::string  className();
    static PyRxClass    desc();
    static PyDbPolyline	cloneFrom(const PyRxObject& src);
    static PyDbPolyline cast(const PyRxObject& src);
public:
    AcDbPolyline* impObj(const std::source_location& src = std::source_location::current()) const;
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
    void                setVertexAt(Adesk::UInt16, const AcGePoint3d&) const;
    Adesk::Boolean      isEdgeVisibleAt(Adesk::UInt16) const;
    void                makeEdgeVisibleAt(Adesk::UInt16) const;
    void                makeEdgeInvisibleAt(Adesk::UInt16) const;
public:
    static std::string  className();
    static PyRxClass    desc();
    static PyDbFace		cloneFrom(const PyRxObject& src);
    static PyDbFace     cast(const PyRxObject& src);
public:
    AcDbFace* impObj(const std::source_location& src = std::source_location::current()) const;
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
    void				setText(const std::string& val) const;
    std::string			text(int lineNo) const;
    std::string			textAll() const;
    void				setLocation(const AcGePoint3d& val) const;
    AcGePoint3d			location() const;
    void				setOrientation(const AcGeVector3d& norm, const AcGeVector3d& dir) const;
    AcGeVector3d		normal()    const;
    AcGeVector3d		direction() const;
    boost::python::list getBoundingPoints() const;
    boost::python::list getBoundingPline()  const;
    void                setDimensionStyle(const PyDbHardPointerId& id) const;
    PyDbHardPointerId	dimensionStyle() const;
    PyDbDimStyleTableRecord getDimstyleData() const;
    void                setDimstyleData2(const PyDbDimStyleTableRecord& pNewData) const;
    void                setDimstyleData1(const PyDbObjectId& newDataId) const;
    void				setDimVars() const;
    AcCmColor			dimclrd() const;
    AcCmColor			dimclrt() const;
    double				dimgap() const;
    double				dimscale() const;
    PyDbObjectId		dimtxsty() const;
    double				dimtxt() const;
    void	            setDimclrd(AcCmColor& val) const;
    void	            setDimclrt(AcCmColor& val) const;
    void	            setDimgap(double val) const;
    void	            setDimscale(double val) const;
    void	            setDimtxsty(PyDbObjectId& val) const;
    void	            setDimtxt(double val) const;
public:
    static std::string  className();
    static PyRxClass    desc();
    static PyDbFcf		cloneFrom(const PyRxObject& src);
    static PyDbFcf      cast(const PyRxObject& src);
public:
    AcDbFcf* impObj(const std::source_location& src = std::source_location::current()) const;
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
    AcGePoint3d         getPointAt(Adesk::UInt16 idx) const;
    void                setPointAt(Adesk::UInt16 idx, const AcGePoint3d& val) const;
    double              thickness() const;
    void                setThickness(double) const;
    AcGeVector3d        normal() const;
    void                setNormal(const AcGeVector3d& val) const;
public:
    static std::string  className();
    static PyRxClass    desc();
    static PyDbSolid	cloneFrom(const PyRxObject& src);
    static PyDbSolid    cast(const PyRxObject& src);
public:
    AcDbSolid* impObj(const std::source_location& src = std::source_location::current()) const;
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
    AcGePoint3d         getPointAt(Adesk::UInt16 idx) const;
    void                setPointAt(Adesk::UInt16 idx, const AcGePoint3d& val) const;
    double              thickness() const;
    void                setThickness(double val) const;
    AcGeVector3d        normal() const;
    void                setNormal(const AcGeVector3d& val) const;
public:
    static std::string  className();
    static PyRxClass    desc();
    static PyDbTrace	cloneFrom(const PyRxObject& src);
    static PyDbTrace    cast(const PyRxObject& src);
public:
    AcDbTrace* impObj(const std::source_location& src = std::source_location::current()) const;
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
    void            setPosition(const AcGePoint3d& val) const;
    double          size() const;
    void            setSize(double val) const;
    std::string     name() const;
    void            setName(const std::string& val) const;
    double          rotation() const;
    void            setRotation(double val) const;
    double          widthFactor() const;
    void            setWidthFactor(double val) const;
    double          oblique() const;
    void            setOblique(double val) const;
    double          thickness() const;
    void            setThickness(double val) const;
    AcGeVector3d    normal() const;
    void            setNormal(const AcGeVector3d& val) const;
    Adesk::Int16    shapeNumber() const;
    void            setShapeNumber(Adesk::Int16 idx) const;
    PyDbObjectId    styleId() const;
    void            setStyleId(const PyDbObjectId& id) const;
public:
    static std::string  className();
    static PyRxClass    desc();
    static PyDbShape	cloneFrom(const PyRxObject& src);
    static PyDbShape    cast(const PyRxObject& src);
public:
    AcDbShape* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-------------------------------------------------------------------------------------------------------------
//PyDbOverrulableEntity
void makePyDbOverrulableEntity();

class PyDbOverrulableEntity : public PyDbEntity
{
public:
    PyDbOverrulableEntity();
    PyDbOverrulableEntity(PyRxOverrulableEntity* ptr, bool autoDelete);
    PyDbOverrulableEntity(const PyDbObjectId& id);
    PyDbOverrulableEntity(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbOverrulableEntity(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    virtual ~PyDbOverrulableEntity() override = default;
public:
    AcGePoint3d         position() const;
    void                setPosition(const AcGePoint3d& val) const;
    AcGeVector3d        direction() const;
    void                setDirection(const AcGeVector3d& val) const;
    AcGeVector3d        normal() const;
    void                setNormal(const AcGeVector3d& val) const;
    std::string         guid() const;
    void                setGuid(const std::string& val) const;
    std::string         name() const;
    void                setName(const std::string& val) const;
    std::string         description() const;
    void                setdescription(const std::string& val) const;
    Adesk::Int64        typing() const;
    void                setTyping(Adesk::Int64 val) const;
    Adesk::Int64        mask() const;
    void                setMask(Adesk::Int64 val) const;
    Adesk::Int64        index() const;
    void                setIndex(Adesk::Int64 val) const;
    boost::python::list flags() const;
    void                setFlags(const boost::python::list& vals) const;
    boost::python::list ints() const;
    void                setInts(const boost::python::list& vals) const;
    boost::python::list doubles() const;
    void                setDoubles(boost::python::list& vals) const;
    boost::python::list strings() const;
    void                setStrings(boost::python::list& vals) const;
    boost::python::list points() const;
    void                setPoints(const boost::python::list& vals) const;
    static std::string  className();
    static PyRxClass    desc();
    static PyDbOverrulableEntity   cloneFrom(const PyRxObject& src);
    static PyDbOverrulableEntity   cast(const PyRxObject& src);
public:
    PyRxOverrulableEntity* impObj(const std::source_location& src = std::source_location::current()) const;
};

#pragma pack (pop)