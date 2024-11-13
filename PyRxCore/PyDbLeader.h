#pragma once
#include "PyDbCurve.h"
#include "dbmleader.h"

#pragma pack (push, 8)

class PyDbObjectId;
class PyDbHardPointerId;
class PyDbAttribute;
class PyDbMText;
class PyDbMLeaderStyle;

//----------------------------------------------------------------------------------
//PyDbLeader
void makePyDbLeaderWrapper();

class PyDbLeader : public PyDbCurve
{
public:
    PyDbLeader();
    virtual ~PyDbLeader() override = default;
    PyDbLeader(AcDbLeader* ptr, bool autoDelete);
    PyDbLeader(const PyDbObjectId& id);
    PyDbLeader(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbLeader(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
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
    void                setDimstyleData(const PyDbObjectId& newDataId);
    void                attachAnnotation(const PyDbObjectId& annoId);
    void                detachAnnotation();
    PyDbObjectId        annotationObjId() const;
    void                setAnnotationObjId(const PyDbObjectId& annoId);
    void                evaluateLeader();
    AcGeVector3d        annotationOffset() const;
    void                setAnnotationOffset(const AcGeVector3d& offset);
    AcDbLeader::AnnoType annoType()   const;
    double              annoHeight() const;
    double              annoWidth()  const;
    double              dimasz() const;
    AcCmColor           dimclrd() const;
    double              dimgap() const;
    AcDb::LineWeight    dimlwd() const;
    PyDbObjectId        dimldrblk() const;
    bool                dimsah() const;
    double              dimscale() const;
    int                 dimtad() const;
    PyDbObjectId        dimtxsty() const;
    double              dimtxt() const;
    void                setDimasz(double         val);
    void                setDimclrd(AcCmColor& val);
    void                setDimgap(double         val);
    void                setDimldrblk1(const PyDbObjectId& val);
    void                setDimldrblk2(const std::string& val);
    void                setDimlwd(AcDb::LineWeight val);  // new to R15
    void                setDimsah(bool           val);
    void                setDimscale(double         val);
    void                setDimtad(int            val);
    void                setDimtxsty(const PyDbObjectId& val);
    void                setDimtxt(double         val);
    void                modified(const PyDbObject& obj);
    void                erased1(const PyDbObject& obj);
    void                erased2(const PyDbObject& obj, Adesk::Boolean val);
    void                goodbye(const PyDbObject& obj);
    void                copied(const PyDbObject& objA, const PyDbObject& objB);
    void                setColorIndex1(Adesk::UInt16 val);
    void                setColorIndex2(Adesk::UInt16 val, Adesk::Boolean doSubents);

public:
    static std::string  className();
    static PyRxClass    desc();
    static PyDbLeader   cloneFrom(const PyRxObject& src);
    static PyDbLeader   cast(const PyRxObject& src);

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
    PyDbMLeader(const PyDbObjectId& id);
    PyDbMLeader(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbMLeader(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    void                objectClosed(const PyDbObjectId& dbObjId);
    void                modified(const PyDbObject& dbObj);
    void                setOverride1(AcDbMLeader::PropertyOverrideType propertyType);
    void                setOverride2(AcDbMLeader::PropertyOverrideType propertyType, bool isOverride);
    bool                isOverride(AcDbMLeader::PropertyOverrideType propertyType) const;
    void                setScale(double scale);
    double              scale() const;
    PyDbAttribute       getBlockAttribute(const PyDbObjectId& attdefId) const;
    void                setBlockAttribute(const PyDbObjectId& attdefId, const PyDbAttribute& pAtt);
    std::string         getBlockAttributeValue(const PyDbObjectId& attdefId) const;
    void                setBlockAttributeValue(const PyDbObjectId& attdefId, const  std::string& pAtt);
    PyGePlane           plane() const;
    void                setPlane(const PyGePlane& plane);
    AcGeVector3d        normal() const;
    void                moveMLeader1(const AcGeVector3d& vector, AcDbMLeader::MoveType moveType);
    void                moveMLeader2(const AcGeVector3d& vector, AcDbMLeader::MoveType moveType, bool bAutoSwitchDogleg);
    AcDbExtents         getContentGeomExtents() const;
    int                 numLeaders() const;
    boost::python::list getLeaderIndexes() const;
    void                removeLeader(int leaderIndex);
    int                 numLeaderLines() const;
    boost::python::list getLeaderLineIndexes1() const;
    boost::python::list getLeaderLineIndexes2(int leaderIndex) const;
    int                 addLeader();
    int                 addLeaderLine1(int leaderIndex);
    int                 addLeaderLine2(const AcGePoint3d& point);
    void                removeLeaderLine(int leaderLineIndex);
    void                addFirstVertex(int leaderLineIndex, const AcGePoint3d& point);
    void                removeFirstVertex(int leaderLineIndex);
    AcGePoint3d         getFirstVertex(int leaderLineIndex) const;
    void                setFirstVertex(int leaderLineIndex, const AcGePoint3d& point);
    void                addLastVertex(int leaderLineIndex, const AcGePoint3d& point);
    void                removeLastVertex(int leaderLineIndex);
    AcGePoint3d         getLastVertex(int leaderLineIndex) const;
    void                setLastVertex(int leaderLineIndex, const AcGePoint3d& point);
    int                 numVertices(int leaderLineIndex) const;
    void                setVertex(int leaderLineIndex, int index, const AcGePoint3d& point);
    AcGePoint3d         getVertex(int leaderLineIndex, int index) const;
    int                 getLeaderIndex(int leaderLineIndex) const;
    void                setDoglegDirection(int leaderIndex, const AcGeVector3d& vector);
    AcGeVector3d        getDoglegDirection(int leaderIndex) const;
    void                setLeaderLineType1(AcDbMLeaderStyle::LeaderType leaderLineType);
    AcDbMLeaderStyle::LeaderType leaderLineType() const;
    void                setLeaderLineType2(int leaderLineIndex, AcDbMLeaderStyle::LeaderType  leaderLineType);
    AcDbMLeaderStyle::LeaderType getLeaderLineType(int leaderLineIndex) const;
    AcCmColor           leaderLineColor() const;
    void                setLeaderLineColor1(const AcCmColor& leaderLineColor);
    void                setLeaderLineColor2(int leaderLineIndex, const AcCmColor& leaderLineColor);
    AcCmColor           getLeaderLineColor(int leaderLineIndex) const;
    PyDbObjectId        leaderLineTypeId() const;
    void                setLeaderLineTypeId1(const PyDbObjectId& leaderLineTypeId);
    void                setLeaderLineTypeId2(int leaderLineIndex, const PyDbObjectId& leaderLineTypeId);
    PyDbObjectId        getLeaderLineTypeId(int leaderLineIndex) const;
    AcDb::LineWeight    leaderLineWeight() const;
    void                setLeaderLineWeight1(AcDb::LineWeight leaderLineWeight);
    void                setLeaderLineWeight2(int leaderLineIndex, AcDb::LineWeight  leaderLineWeight);
    AcDb::LineWeight    getLeaderLineWeight(int leaderLineIndex) const;
    void                setLandingGap(double landingGap);
    double              landingGap() const;
    void                setEnableLanding(bool enableLanding);
    bool                enableLanding() const;
    void                setEnableDogleg(bool enableDogleg);
    bool                enableDogleg() const;
    double              doglegLength() const;
    void                setDoglegLength1(double doglegLength);
    void                setDoglegLength2(int leaderIndex, double doglegLength);
    double              getDoglegLength(int leaderIndex) const;
    PyDbObjectId        arrowSymbolId() const;
    void                setArrowSymbolId1(const PyDbObjectId& arrowSymbolId);
    void                setArrowSymbolId2(int leaderLineIndex, const PyDbObjectId& arrowSymbolId);
    PyDbObjectId        getArrowSymbolId(int leaderLineIndex) const;
    double              arrowSize() const;
    void                setArrowSize1(double arrowSize);
    void                setArrowSize2(int leaderLineIndex, double  arrowSize);
    double              getArrowSize(int leaderLineIndex) const;
    AcDbMLeaderStyle::ContentType contentType() const;
    void                setContentType(AcDbMLeaderStyle::ContentType contentType);
    PyDbObjectId        textStyleId() const;
    void                setTextStyleId(const PyDbObjectId& textStyleId);
    AcDbMLeaderStyle::TextAttachmentType  textAttachmentType1() const;
    AcDbMLeaderStyle::TextAttachmentType  textAttachmentType2(AcDbMLeaderStyle::LeaderDirectionType leaderDirection) const;
    void                setTextAttachmentType1(AcDbMLeaderStyle::TextAttachmentType textAttachmentType);
    void                setTextAttachmentType2(AcDbMLeaderStyle::TextAttachmentType textAttachmentType, AcDbMLeaderStyle::LeaderDirectionType leaderDirection);
    AcDbMLeaderStyle::TextAngleType textAngleType() const;
    void                setTextAngleType(AcDbMLeaderStyle::TextAngleType textAngleType);
    AcDbMLeaderStyle::TextAlignmentType   textAlignmentType() const;
    void                setTextAlignmentType(AcDbMLeaderStyle::TextAlignmentType textAlignmentType);
    void                setTextColor(const AcCmColor& textColor);
    AcCmColor           textColor() const;
    void                setTextHeight(double textHeight);
    double              textHeight() const;
    void                setEnableFrameText(bool enableFrameText);
    bool                enableFrameText() const;
    void                setMText(const PyDbMText& pMText);
    PyDbMText           mtext() const;
    void                setBlockContentId(const PyDbObjectId& blockId);
    PyDbObjectId        blockContentId() const;
    void                setBlockColor(const AcCmColor& blockColor);
    AcCmColor           blockColor() const;
    void                setBlockScale(const AcGeScale3d& scale);
    AcGeScale3d         blockScale() const;
    void                setBlockRotation(double rotation);
    double              blockRotation() const;
    void                setBlockConnectionType(AcDbMLeaderStyle::BlockConnectionType blockConnectionType);
    AcDbMLeaderStyle::BlockConnectionType blockConnectionType() const;
    void                setEnableAnnotationScale(bool enableAnnotationScale);
    bool                enableAnnotationScale() const;
    void                setMLeaderStyle(const PyDbObjectId& blockId);
    PyDbObjectId        MLeaderStyle();
    void                getOverridedMLeaderStyle(PyDbMLeaderStyle& mleaderStyle);
    //void setContextDataManager(void* pContextDataManager);
    //void* getContextDataManager() const;
    void                setBlockPosition(const AcGePoint3d& position);
    AcGePoint3d         getBlockPosition() const;
    void                setTextLocation(const AcGePoint3d& location);
    AcGePoint3d         getTextLocation() const;
    void                setToleranceLocation(const AcGePoint3d& location);
    AcGePoint3d         getToleranceLocation() const;
    bool                hasContent() const;
    AcGePoint3d         connectionPoint1(const AcGeVector3d& vect) const;
    AcGePoint3d         connectionPoint2(const AcGeVector3d& vect, AcDbMLeaderStyle::TextAttachmentDirection textAttachmentDirection) const;
    void                recomputeBreakPoints();
    void                postMLeaderToDb(PyDbDatabase& pDb);
    void                updateLeaderLinePosition();
    void                removeLeaderLineRefAssoc(int leaderLineIndex) const;
    //void updateContentScale(AcDbMLeaderObjectContextData* pContext);
    void                setTextAttachmentDirection(AcDbMLeaderStyle::TextAttachmentDirection textAttachmentDirection);
    AcDbMLeaderStyle::TextAttachmentDirection textAttachmentDirection() const;
    void                setExtendLeaderToText(bool value);
    bool                extendLeaderToText() const;

public:
    static std::string  className();
    static PyRxClass    desc();
    static PyDbMLeader  cloneFrom(const PyRxObject& src);
    static PyDbMLeader  cast(const PyRxObject& src);

public:
    AcDbMLeader* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------
//PyDbMLeaderStyle
void makePyDbMLeaderStyleWrapper();

class PyDbMLeaderStyle : public PyDbObject
{
public:
    PyDbMLeaderStyle();
    virtual ~PyDbMLeaderStyle() override = default;
    PyDbMLeaderStyle(AcDbMLeaderStyle* ptr, bool autoDelete);
    PyDbMLeaderStyle(const PyDbObjectId& id);
    PyDbMLeaderStyle(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbMLeaderStyle(const PyDbObjectId& id, AcDb::OpenMode mode, bool openEdased);
    std::string             getName() const;
    void                    setName(const std::string& pszName);
    bool                    isRenamable() const;
    const  std::string      description(void) const;
    void                    setDescription(const std::string& pszDescription);
    Adesk::UInt32           bitFlags() const;
    void                    setBitFlags(Adesk::UInt32 flags);
    AcDbMLeaderStyle::ContentType contentType() const;
    void                    setContentType(AcDbMLeaderStyle::ContentType contentType);
    void                    setDrawMLeaderOrderType(AcDbMLeaderStyle::DrawMLeaderOrderType drawMLeaderOrderType);
    AcDbMLeaderStyle::DrawMLeaderOrderType drawMLeaderOrderType() const;
    void                    setDrawLeaderOrderType(AcDbMLeaderStyle::DrawLeaderOrderType drawLeaderOrderType);
    AcDbMLeaderStyle::DrawLeaderOrderType drawLeaderOrderType() const;
    void                    setMaxLeaderSegmentsPoints(int maxLeaderSegmentsPoints);
    int                     maxLeaderSegmentsPoints() const;
    void                    setFirstSegmentAngleConstraint(AcDbMLeaderStyle::SegmentAngleType angle);
    AcDbMLeaderStyle::SegmentAngleType firstSegmentAngleConstraint() const;
    void                    setSecondSegmentAngleConstraint(AcDbMLeaderStyle::SegmentAngleType angle);
    AcDbMLeaderStyle::SegmentAngleType secondSegmentAngleConstraint() const;
    void                    setLeaderLineType(AcDbMLeaderStyle::LeaderType leaderLineType);
    AcDbMLeaderStyle::LeaderType leaderLineType() const;
    void                    setLeaderLineColor(const AcCmColor& leaderLineColor);
    AcCmColor               leaderLineColor() const;
    void                    setLeaderLineTypeId(const PyDbObjectId& leaderLineTypeId);
    PyDbObjectId            leaderLineTypeId() const;
    void                    setLeaderLineWeight(AcDb::LineWeight leaderLineWeight);
    AcDb::LineWeight        leaderLineWeight() const;
    void                    setEnableLanding(bool enableLanding);
    bool                    enableLanding() const;
    void                    setLandingGap(double landingGap);
    double                  landingGap() const;
    void                    setEnableDogleg(bool enableDogleg);
    bool                    enableDogleg() const;
    void                    setDoglegLength(double doglegLength);
    double                  doglegLength() const;
    void                    setArrowSymbolId1(const std::string& name);
    void                    setArrowSymbolId2(const PyDbObjectId& arrowSymbolId);
    PyDbObjectId            arrowSymbolId() const;
    void                    setArrowSize(double arrowSize);
    double                  arrowSize() const;
    void                    setDefaultMText(const PyDbMText& defaultMText);
    PyDbMText               defaultMText() const;
    void                    setTextStyleId(const PyDbObjectId& textStyleId);
    PyDbObjectId            textStyleId() const;
    void                    setTextAttachmentType1(AcDbMLeaderStyle::TextAttachmentType textAttachmentType, AcDbMLeaderStyle::LeaderDirectionType leaderDirection);
    AcDbMLeaderStyle::TextAttachmentType   textAttachmentType1(AcDbMLeaderStyle::LeaderDirectionType leaderDirection) const;
    void                    setTextAttachmentType2(AcDbMLeaderStyle::TextAttachmentType textAttachmentType);
    AcDbMLeaderStyle::TextAttachmentType   textAttachmentType2() const;
    void                    setTextAngleType(AcDbMLeaderStyle::TextAngleType textAngleType);
    AcDbMLeaderStyle::TextAngleType textAngleType() const;
    void                    setTextAlignmentType(AcDbMLeaderStyle::TextAlignmentType textAlignmentType);
    AcDbMLeaderStyle::TextAlignmentType textAlignmentType() const;
    void                    setTextAlignAlwaysLeft(bool bAlwaysLeft);
    bool                    textAlignAlwaysLeft() const;
    void                    setTextColor(const AcCmColor& textColor);
    AcCmColor               textColor() const;
    void                    setTextHeight(double textHeight);
    double                  textHeight() const;
    void                    setEnableFrameText(bool enableFrameText);
    bool                    enableFrameText() const;
    void                    setAlignSpace(double alignSpace);
    double                  alignSpace() const;
    void                    setBlockId1(const std::string& name);
    void                    setBlockId2(const PyDbObjectId& blockId);
    PyDbObjectId            blockId() const;
    void                    setBlockColor(const AcCmColor& blockColor);
    AcCmColor               blockColor() const;
    void                    setBlockScale(const AcGeScale3d& scale);
    AcGeScale3d             blockScale() const;
    void                    setEnableBlockScale(bool enableBlockScale);
    bool                    enableBlockScale() const;
    void                    setBlockRotation(double rotation);
    double                  blockRotation() const;
    void                    setEnableBlockRotation(bool enableBlockRotation);
    bool                    enableBlockRotation() const;
    void                    setBlockConnectionType(AcDbMLeaderStyle::BlockConnectionType blockConnectionType);
    AcDbMLeaderStyle::BlockConnectionType blockConnectionType() const;
    void                    setScale(double scale);
    double                  scale() const;
    bool                    overwritePropChanged() const;
    PyDbObjectId            postMLeaderStyleToDb(PyDbDatabase& pDb, const std::string& styleName);
    void                    setAnnotative(bool isAnnotative);
    bool                    annotative() const;
    void                    setBreakSize(double size);
    double                  breakSize() const;
    void                    setTextAttachmentDirection(AcDbMLeaderStyle::TextAttachmentDirection textAttachmentDirection);
    AcDbMLeaderStyle::TextAttachmentDirection   textAttachmentDirection() const;
    void                    setExtendLeaderToText(bool value);
    bool                     extendLeaderToText() const;

public:
    static std::string  className();
    static PyRxClass    desc();

public:
    AcDbMLeaderStyle* impObj(const std::source_location& src = std::source_location::current()) const;
};

#pragma pack (pop)
