#pragma once
#include "PyDbCurve.h"
#include "dbmleader.h"

class PyDbObjectId;
class PyDbHardPointerId;
class PyDbAttribute;
class PyDbMText;

//----------------------------------------------------------------------------------
//PyDbLeader
void makePyDbLeaderWrapper();

class PyDbLeader : public PyDbCurve
{
public:
    PyDbLeader();
    virtual ~PyDbLeader() override = default;
    PyDbLeader(AcDbLeader* ptr, bool autoDelete);
    PyDbLeader(const PyDbObjectId& id, AcDb::OpenMode mode);
    void                setPlane(const PyGePlane& plane);
    AcGeVector3d        normal() const;
    int numVertices() const;
    Adesk::Boolean      appendVertex(const AcGePoint3d& val);
    void                removeLastVertex();
    AcGePoint3d         firstVertex() const;
    AcGePoint3d         lastVertex() const;
    AcGePoint3d         vertexAt(int idx) const;
    Adesk::Boolean      setVertexAt(int idx, const AcGePoint3d& val);
    Adesk::Boolean      hasArrowHead() const;
    void                enableArrowHead();
    void                disableArrowHead();
    void                setHasArrowHead(Adesk::Boolean bEnable);
    Adesk::Boolean      hasHookLine() const;
    void                setToSplineLeader();
    void                setToStraightLeader();
    Adesk::Boolean      isSplined() const;
    void                setSplined(Adesk::Boolean bSplined);
    PyDbHardPointerId   dimensionStyle() const;
    void                setDimensionStyle(const PyDbHardPointerId& val);
    Acad::ErrorStatus   setDimstyleData(const PyDbObjectId& newDataId);
    Acad::ErrorStatus   attachAnnotation(const PyDbObjectId& annoId);
    Acad::ErrorStatus   detachAnnotation();
    PyDbObjectId        annotationObjId() const;
    Acad::ErrorStatus   setAnnotationObjId(const PyDbObjectId& annoId);
    Acad::ErrorStatus   evaluateLeader();
    AcGeVector3d        annotationOffset() const;
    Acad::ErrorStatus   setAnnotationOffset(const AcGeVector3d& offset);
    AcDbLeader::AnnoType annoType()   const;
    double               annoHeight() const;
    double               annoWidth()  const;
    double               dimasz() const;
    AcCmColor            dimclrd() const;
    double               dimgap() const;
    AcDb::LineWeight     dimlwd() const;
    PyDbObjectId         dimldrblk() const;
    bool                 dimsah() const;
    double               dimscale() const;
    int                  dimtad() const;
    PyDbObjectId         dimtxsty() const;
    double               dimtxt() const;
    Acad::ErrorStatus    setDimasz(double         val);
    Acad::ErrorStatus    setDimclrd(AcCmColor& val);
    Acad::ErrorStatus    setDimgap(double         val);
    Acad::ErrorStatus    setDimldrblk1(const PyDbObjectId& val);
    Acad::ErrorStatus    setDimldrblk2(const std::string& val);
    Acad::ErrorStatus    setDimlwd(AcDb::LineWeight val);  // new to R15
    Acad::ErrorStatus    setDimsah(bool           val);
    Acad::ErrorStatus    setDimscale(double         val);
    Acad::ErrorStatus    setDimtad(int            val);
    Acad::ErrorStatus    setDimtxsty(const PyDbObjectId& val);
    Acad::ErrorStatus    setDimtxt(double         val);
    void                 modified(const PyDbObject& obj);
    void                 erased1(const PyDbObject& obj);
    void                 erased2(const PyDbObject& obj, Adesk::Boolean val);
    void                 goodbye(const PyDbObject& obj);
    void                 copied(const PyDbObject& objA, const PyDbObject& objB);
    Acad::ErrorStatus    setColorIndex1(Adesk::UInt16 val);
    Acad::ErrorStatus    setColorIndex2(Adesk::UInt16 val, Adesk::Boolean doSubents);

public:
    static std::string  className();
    static PyRxClass    desc();

public:
    AcDbLeader* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------
//PyDbMLeader
void makePyDbMLeaderWrapper();

class PyDbMLeader : public PyDbEntity
{
public:
    PyDbMLeader();
    virtual ~PyDbMLeader() override = default;
    PyDbMLeader(AcDbMLeader* ptr, bool autoDelete);
    PyDbMLeader(const PyDbObjectId& id, AcDb::OpenMode mode);
    void                objectClosed(const PyDbObjectId& dbObjId);
    void                modified(const PyDbObject& dbObj);
    Acad::ErrorStatus   setOverride1(AcDbMLeader::PropertyOverrideType propertyType);
    Acad::ErrorStatus   setOverride2(AcDbMLeader::PropertyOverrideType propertyType, bool isOverride);
    bool                isOverride(AcDbMLeader::PropertyOverrideType propertyType) const;
    Acad::ErrorStatus   setScale(double scale);
    double              scale() const;
    PyDbAttribute       getBlockAttributeValue1(const PyDbObjectId& attdefId) const;
    Acad::ErrorStatus   setBlockAttributeValue1(const PyDbObjectId& attdefId, const PyDbAttribute& pAtt);
    std::string         getBlockAttributeValue2(const PyDbObjectId& attdefId) const;
    Acad::ErrorStatus   setBlockAttributeValue2(const PyDbObjectId& attdefId, const  std::string& pAtt);
    PyGePlane           plane() const;
    void                setPlane(const PyGePlane& plane);
    AcGeVector3d        normal() const;
    Acad::ErrorStatus   moveMLeader1(const AcGeVector3d& vector, AcDbMLeader::MoveType moveType);
    Acad::ErrorStatus   moveMLeader2(const AcGeVector3d& vector, AcDbMLeader::MoveType moveType, bool bAutoSwitchDogleg);
    AcDbExtents         getContentGeomExtents() const;
    int                 numLeaders() const;
    boost::python::list getLeaderIndexes() const;
    Acad::ErrorStatus   removeLeader(int leaderIndex);
    int                 numLeaderLines() const;
    boost::python::list getLeaderLineIndexes1() const;
    boost::python::list getLeaderLineIndexes2(int leaderIndex) const;
    int                 addLeader();
    int                 addLeaderLine1(int leaderIndex);
    int                 addLeaderLine2(const AcGePoint3d& point);
    Acad::ErrorStatus   removeLeaderLine(int leaderLineIndex);
    Acad::ErrorStatus   addFirstVertex(int leaderLineIndex, const AcGePoint3d& point);
    Acad::ErrorStatus   removeFirstVertex(int leaderLineIndex);
    AcGePoint3d         getFirstVertex(int leaderLineIndex) const;
    Acad::ErrorStatus   setFirstVertex(int leaderLineIndex, const AcGePoint3d& point);
    Acad::ErrorStatus   addLastVertex(int leaderLineIndex, const AcGePoint3d& point);
    Acad::ErrorStatus   removeLastVertex(int leaderLineIndex);
    AcGePoint3d         getLastVertex(int leaderLineIndex) const;
    Acad::ErrorStatus   setLastVertex(int leaderLineIndex, const AcGePoint3d& point);
    int                 numVertices(int leaderLineIndex) const;
    Acad::ErrorStatus   setVertex(int leaderLineIndex, int index, const AcGePoint3d& point);
    AcGePoint3d         getVertex(int leaderLineIndex, int index) const;
    int                 getLeaderIndex(int leaderLineIndex) const;
    Acad::ErrorStatus   setDoglegDirection(int leaderIndex, const AcGeVector3d& vector);
    AcGeVector3d        getDoglegDirection(int leaderIndex) const;
    Acad::ErrorStatus   setLeaderLineType1(AcDbMLeaderStyle::LeaderType leaderLineType);
    AcDbMLeaderStyle::LeaderType leaderLineType() const;
    Acad::ErrorStatus   setLeaderLineType2(int leaderLineIndex, AcDbMLeaderStyle::LeaderType  leaderLineType);
    AcDbMLeaderStyle::LeaderType getLeaderLineType(int leaderLineIndex) const;
    AcCmColor           leaderLineColor() const;
    Acad::ErrorStatus   setLeaderLineColor1(const AcCmColor& leaderLineColor);
    Acad::ErrorStatus   setLeaderLineColor2(int leaderLineIndex, const AcCmColor& leaderLineColor);
    AcCmColor           getLeaderLineColor(int leaderLineIndex) const;
    PyDbObjectId        leaderLineTypeId() const;
    Acad::ErrorStatus   setLeaderLineTypeId1(const PyDbObjectId& leaderLineTypeId);
    Acad::ErrorStatus   setLeaderLineTypeId2(int leaderLineIndex, const PyDbObjectId& leaderLineTypeId);
    PyDbObjectId        getLeaderLineTypeId(int leaderLineIndex) const;
    AcDb::LineWeight    leaderLineWeight() const;
    Acad::ErrorStatus   setLeaderLineWeight1(AcDb::LineWeight leaderLineWeight);
    Acad::ErrorStatus   setLeaderLineWeight2(int leaderLineIndex, AcDb::LineWeight  leaderLineWeight);
    AcDb::LineWeight    getLeaderLineWeight(int leaderLineIndex) const;
    Acad::ErrorStatus   setLandingGap(double landingGap);
    double              landingGap() const;
    Acad::ErrorStatus   setEnableLanding(bool enableLanding);
    bool                enableLanding() const;
    Acad::ErrorStatus   setEnableDogleg(bool enableDogleg);
    bool                enableDogleg() const;
    double              doglegLength() const;
    Acad::ErrorStatus   setDoglegLength1(double doglegLength);
    Acad::ErrorStatus   setDoglegLength2(int leaderIndex, double doglegLength);
    double              getDoglegLength(int leaderIndex) const;
    PyDbObjectId        arrowSymbolId() const;
    Acad::ErrorStatus   setArrowSymbolId1(const PyDbObjectId& arrowSymbolId);
    Acad::ErrorStatus   setArrowSymbolId2(int leaderLineIndex, const PyDbObjectId& arrowSymbolId);
    PyDbObjectId        getArrowSymbolId(int leaderLineIndex) const;
    double              arrowSize() const;
    Acad::ErrorStatus   setArrowSize1(double arrowSize);
    Acad::ErrorStatus   setArrowSize2(int leaderLineIndex, double  arrowSize);
    double              getArrowSize(int leaderLineIndex) const;
    AcDbMLeaderStyle::ContentType contentType() const;
    Acad::ErrorStatus   setContentType(AcDbMLeaderStyle::ContentType contentType);
    PyDbObjectId        textStyleId() const;
    Acad::ErrorStatus   setTextStyleId(const PyDbObjectId& textStyleId);
    AcDbMLeaderStyle::TextAttachmentType  textAttachmentType1() const;
    AcDbMLeaderStyle::TextAttachmentType  textAttachmentType2(AcDbMLeaderStyle::LeaderDirectionType leaderDirection) const;
    Acad::ErrorStatus   setTextAttachmentType1(AcDbMLeaderStyle::TextAttachmentType textAttachmentType);
    Acad::ErrorStatus   setTextAttachmentType2(AcDbMLeaderStyle::TextAttachmentType textAttachmentType, AcDbMLeaderStyle::LeaderDirectionType leaderDirection);
    AcDbMLeaderStyle::TextAngleType textAngleType() const;
    Acad::ErrorStatus   setTextAngleType(AcDbMLeaderStyle::TextAngleType textAngleType);
    AcDbMLeaderStyle::TextAlignmentType   textAlignmentType() const;
    Acad::ErrorStatus   setTextAlignmentType(AcDbMLeaderStyle::TextAlignmentType textAlignmentType);
    Acad::ErrorStatus   setTextColor(const AcCmColor& textColor);
    AcCmColor           textColor() const;
    Acad::ErrorStatus   setTextHeight(double textHeight);
    double              textHeight() const;
    Acad::ErrorStatus   setEnableFrameText(bool enableFrameText);
    bool                enableFrameText() const;
    Acad::ErrorStatus   setMText(const PyDbMText& pMText);
    PyDbMText           mtext() const;
    Acad::ErrorStatus   setBlockContentId(const PyDbObjectId& blockId);
    PyDbObjectId        blockContentId() const;
    Acad::ErrorStatus   setBlockColor(const AcCmColor& blockColor);
    AcCmColor           blockColor() const;
    Acad::ErrorStatus   setBlockScale(const AcGeScale3d& scale);
    AcGeScale3d         blockScale() const;
    Acad::ErrorStatus   setBlockRotation(double rotation);
    double              blockRotation() const;
    Acad::ErrorStatus   setBlockConnectionType(AcDbMLeaderStyle::BlockConnectionType blockConnectionType);
    AcDbMLeaderStyle::BlockConnectionType blockConnectionType() const;
    Acad::ErrorStatus   setEnableAnnotationScale(bool enableAnnotationScale);
    bool                enableAnnotationScale() const;
    Acad::ErrorStatus   setMLeaderStyle(const PyDbObjectId& blockId);
    PyDbObjectId        MLeaderStyle();
    //Acad::ErrorStatus getOverridedMLeaderStyle(AcDbMLeaderStyle& mleaderStyle);
    //Acad::ErrorStatus setContextDataManager(void* pContextDataManager);
    //void* getContextDataManager() const;
    Acad::ErrorStatus   setBlockPosition(const AcGePoint3d& position);
    AcGePoint3d         getBlockPosition() const;
    Acad::ErrorStatus   setTextLocation(const AcGePoint3d& location);
    AcGePoint3d         getTextLocation() const;
    Acad::ErrorStatus   setToleranceLocation(const AcGePoint3d& location);
    AcGePoint3d         getToleranceLocation() const;
    bool                hasContent() const;
    AcGePoint3d         connectionPoint1(const AcGeVector3d& vect) const;
    AcGePoint3d         connectionPoint2(const AcGeVector3d& vect, AcDbMLeaderStyle::TextAttachmentDirection textAttachmentDirection) const;
    Acad::ErrorStatus   recomputeBreakPoints();
    Acad::ErrorStatus   postMLeaderToDb(PyDbDatabase& pDb);
    Acad::ErrorStatus   updateLeaderLinePosition();
    Acad::ErrorStatus   removeLeaderLineRefAssoc(int leaderLineIndex) const;
    //Acad::ErrorStatus updateContentScale(AcDbMLeaderObjectContextData* pContext);
    Acad::ErrorStatus   setTextAttachmentDirection(AcDbMLeaderStyle::TextAttachmentDirection textAttachmentDirection);
    AcDbMLeaderStyle::TextAttachmentDirection textAttachmentDirection() const;
    Acad::ErrorStatus   setExtendLeaderToText(bool value);
    bool                extendLeaderToText() const;

public:
    static std::string  className();
    static PyRxClass    desc();

public:
    AcDbMLeader* impObj(const std::source_location& src = std::source_location::current()) const;
};