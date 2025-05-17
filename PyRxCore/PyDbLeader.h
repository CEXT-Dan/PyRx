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
    void                setPlane(const PyGePlane& plane) const;
    AcGeVector3d        normal() const;
    int numVertices() const;
    Adesk::Boolean      appendVertex(const AcGePoint3d& val) const;
    void                removeLastVertex() const;
    AcGePoint3d         firstVertex() const;
    AcGePoint3d         lastVertex() const;
    AcGePoint3d         vertexAt(int idx) const;
    Adesk::Boolean      setVertexAt(int idx, const AcGePoint3d& val) const;
    Adesk::Boolean      hasArrowHead() const;
    void                enableArrowHead() const;
    void                disableArrowHead() const;
    void                setHasArrowHead(Adesk::Boolean bEnable) const;
    Adesk::Boolean      hasHookLine() const;
    void                setToSplineLeader() const;
    void                setToStraightLeader() const;
    Adesk::Boolean      isSplined() const;
    void                setSplined(Adesk::Boolean bSplined) const;
    PyDbHardPointerId   dimensionStyle() const;
    void                setDimensionStyle(const PyDbHardPointerId& val) const;
    void                setDimstyleData(const PyDbObjectId& newDataId) const;
    void                attachAnnotation(const PyDbObjectId& annoId) const;
    void                detachAnnotation() const;
    PyDbObjectId        annotationObjId() const;
    void                setAnnotationObjId(const PyDbObjectId& annoId) const;
    void                evaluateLeader() const;
    AcGeVector3d        annotationOffset() const;
    void                setAnnotationOffset(const AcGeVector3d& offset) const;
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
    void                setDimasz(double         val) const;
    void                setDimclrd(AcCmColor& val) const;
    void                setDimgap(double         val) const;
    void                setDimldrblk1(const PyDbObjectId& val) const;
    void                setDimldrblk2(const std::string& val) const;
    void                setDimlwd(AcDb::LineWeight val) const;  // new to R15
    void                setDimsah(bool           val) const;
    void                setDimscale(double         val) const;
    void                setDimtad(int            val) const;
    void                setDimtxsty(const PyDbObjectId& val) const;
    void                setDimtxt(double         val) const;
    void                modified(const PyDbObject& obj) const;
    void                erased1(const PyDbObject& obj) const;
    void                erased2(const PyDbObject& obj, Adesk::Boolean val) const;
    void                goodbye(const PyDbObject& obj) const;
    void                copied(const PyDbObject& objA, const PyDbObject& objB) const;
    void                setColorIndex1(Adesk::UInt16 val) const;
    void                setColorIndex2(Adesk::UInt16 val, Adesk::Boolean doSubents) const;

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
    void                objectClosed(const PyDbObjectId& dbObjId) const;
    void                modified(const PyDbObject& dbObj) const;
    void                setOverride1(AcDbMLeader::PropertyOverrideType propertyType) const;
    void                setOverride2(AcDbMLeader::PropertyOverrideType propertyType, bool isOverride) const;
    bool                isOverride(AcDbMLeader::PropertyOverrideType propertyType) const;
    void                setScale(double scale) const;
    double              scale() const;
    PyDbAttribute       getBlockAttribute(const PyDbObjectId& attdefId) const;
    void                setBlockAttribute(const PyDbObjectId& attdefId, const PyDbAttribute& pAtt) const;
    std::string         getBlockAttributeValue(const PyDbObjectId& attdefId) const;
    void                setBlockAttributeValue(const PyDbObjectId& attdefId, const  std::string& pAtt) const;
    PyGePlane           plane() const;
    void                setPlane(const PyGePlane& plane) const;
    AcGeVector3d        normal() const;
    void                moveMLeader1(const AcGeVector3d& vector, AcDbMLeader::MoveType moveType) const;
    void                moveMLeader2(const AcGeVector3d& vector, AcDbMLeader::MoveType moveType, bool bAutoSwitchDogleg) const;
    AcDbExtents         getContentGeomExtents() const;
    int                 numLeaders() const;
    boost::python::list getLeaderIndexes() const;
    void                removeLeader(int leaderIndex) const;
    int                 numLeaderLines() const;
    boost::python::list getLeaderLineIndexes1() const;
    boost::python::list getLeaderLineIndexes2(int leaderIndex) const;
    int                 addLeader() const;
    int                 addLeaderLine1(int leaderIndex) const;
    int                 addLeaderLine2(const AcGePoint3d& point) const;
    void                removeLeaderLine(int leaderLineIndex) const;
    void                addFirstVertex(int leaderLineIndex, const AcGePoint3d& point) const;
    void                removeFirstVertex(int leaderLineIndex) const;
    AcGePoint3d         getFirstVertex(int leaderLineIndex) const;
    void                setFirstVertex(int leaderLineIndex, const AcGePoint3d& point) const;
    void                addLastVertex(int leaderLineIndex, const AcGePoint3d& point) const;
    void                removeLastVertex(int leaderLineIndex) const;
    AcGePoint3d         getLastVertex(int leaderLineIndex) const;
    void                setLastVertex(int leaderLineIndex, const AcGePoint3d& point) const;
    int                 numVertices(int leaderLineIndex) const;
    void                setVertex(int leaderLineIndex, int index, const AcGePoint3d& point) const;
    AcGePoint3d         getVertex(int leaderLineIndex, int index) const;
    int                 getLeaderIndex(int leaderLineIndex) const;
    void                setDoglegDirection(int leaderIndex, const AcGeVector3d& vector) const;
    AcGeVector3d        getDoglegDirection(int leaderIndex) const;
    void                setLeaderLineType1(AcDbMLeaderStyle::LeaderType leaderLineType) const;
    AcDbMLeaderStyle::LeaderType leaderLineType() const;
    void                setLeaderLineType2(int leaderLineIndex, AcDbMLeaderStyle::LeaderType  leaderLineType) const;
    AcDbMLeaderStyle::LeaderType getLeaderLineType(int leaderLineIndex) const;
    AcCmColor           leaderLineColor() const;
    void                setLeaderLineColor1(const AcCmColor& leaderLineColor) const;
    void                setLeaderLineColor2(int leaderLineIndex, const AcCmColor& leaderLineColor) const;
    AcCmColor           getLeaderLineColor(int leaderLineIndex) const;
    PyDbObjectId        leaderLineTypeId() const;
    void                setLeaderLineTypeId1(const PyDbObjectId& leaderLineTypeId) const;
    void                setLeaderLineTypeId2(int leaderLineIndex, const PyDbObjectId& leaderLineTypeId) const;
    PyDbObjectId        getLeaderLineTypeId(int leaderLineIndex) const;
    AcDb::LineWeight    leaderLineWeight() const;
    void                setLeaderLineWeight1(AcDb::LineWeight leaderLineWeight) const;
    void                setLeaderLineWeight2(int leaderLineIndex, AcDb::LineWeight  leaderLineWeight) const;
    AcDb::LineWeight    getLeaderLineWeight(int leaderLineIndex) const;
    void                setLandingGap(double landingGap) const;
    double              landingGap() const;
    void                setEnableLanding(bool enableLanding) const;
    bool                enableLanding() const;
    void                setEnableDogleg(bool enableDogleg) const;
    bool                enableDogleg() const;
    double              doglegLength() const;
    void                setDoglegLength1(double doglegLength) const;
    void                setDoglegLength2(int leaderIndex, double doglegLength) const;
    double              getDoglegLength(int leaderIndex) const;
    PyDbObjectId        arrowSymbolId() const;
    void                setArrowSymbolId1(const PyDbObjectId& arrowSymbolId) const;
    void                setArrowSymbolId2(int leaderLineIndex, const PyDbObjectId& arrowSymbolId) const;
    PyDbObjectId        getArrowSymbolId(int leaderLineIndex) const;
    double              arrowSize() const;
    void                setArrowSize1(double arrowSize) const;
    void                setArrowSize2(int leaderLineIndex, double  arrowSize) const;
    double              getArrowSize(int leaderLineIndex) const;
    AcDbMLeaderStyle::ContentType contentType() const;
    void                setContentType(AcDbMLeaderStyle::ContentType contentType) const;
    PyDbObjectId        textStyleId() const;
    void                setTextStyleId(const PyDbObjectId& textStyleId) const;
    AcDbMLeaderStyle::TextAttachmentType  textAttachmentType1() const;
    AcDbMLeaderStyle::TextAttachmentType  textAttachmentType2(AcDbMLeaderStyle::LeaderDirectionType leaderDirection) const;
    void                setTextAttachmentType1(AcDbMLeaderStyle::TextAttachmentType textAttachmentType) const;
    void                setTextAttachmentType2(AcDbMLeaderStyle::TextAttachmentType textAttachmentType, AcDbMLeaderStyle::LeaderDirectionType leaderDirection) const;
    AcDbMLeaderStyle::TextAngleType textAngleType() const;
    void                setTextAngleType(AcDbMLeaderStyle::TextAngleType textAngleType) const;
    AcDbMLeaderStyle::TextAlignmentType   textAlignmentType() const;
    void                setTextAlignmentType(AcDbMLeaderStyle::TextAlignmentType textAlignmentType) const;
    void                setTextColor(const AcCmColor& textColor) const;
    AcCmColor           textColor() const;
    void                setTextHeight(double textHeight) const;
    double              textHeight() const;
    void                setEnableFrameText(bool enableFrameText) const;
    bool                enableFrameText() const;
    void                setMText(const PyDbMText& pMText) const;
    PyDbMText           mtext() const;
    void                setBlockContentId(const PyDbObjectId& blockId) const;
    PyDbObjectId        blockContentId() const;
    void                setBlockColor(const AcCmColor& blockColor) const;
    AcCmColor           blockColor() const;
    void                setBlockScale(const AcGeScale3d& scale) const;
    AcGeScale3d         blockScale() const;
    void                setBlockRotation(double rotation) const;
    double              blockRotation() const;
    void                setBlockConnectionType(AcDbMLeaderStyle::BlockConnectionType blockConnectionType) const;
    AcDbMLeaderStyle::BlockConnectionType blockConnectionType() const;
    void                setEnableAnnotationScale(bool enableAnnotationScale) const;
    bool                enableAnnotationScale() const;
    void                setMLeaderStyle(const PyDbObjectId& blockId) const;
    PyDbObjectId        MLeaderStyle() const;
    void                getOverridedMLeaderStyle(PyDbMLeaderStyle& mleaderStyle) const;
    //void setContextDataManager(void* pContextDataManager) const;
    //void* getContextDataManager() const;
    void                setBlockPosition(const AcGePoint3d& position) const;
    AcGePoint3d         getBlockPosition() const;
    void                setTextLocation(const AcGePoint3d& location) const;
    AcGePoint3d         getTextLocation() const;
    void                setToleranceLocation(const AcGePoint3d& location) const;
    AcGePoint3d         getToleranceLocation() const;
    bool                hasContent() const;
    AcGePoint3d         connectionPoint1(const AcGeVector3d& vect) const;
    AcGePoint3d         connectionPoint2(const AcGeVector3d& vect, AcDbMLeaderStyle::TextAttachmentDirection textAttachmentDirection) const;
    void                recomputeBreakPoints() const;
    void                postMLeaderToDb(const PyDbDatabase& pDb) const;
    void                updateLeaderLinePosition() const;
    void                removeLeaderLineRefAssoc(int leaderLineIndex) const;
    //void updateContentScale(AcDbMLeaderObjectContextData* pContext) const;
    void                setTextAttachmentDirection(AcDbMLeaderStyle::TextAttachmentDirection textAttachmentDirection) const;
    AcDbMLeaderStyle::TextAttachmentDirection textAttachmentDirection() const;
    void                setExtendLeaderToText(bool value) const;
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
    void                    setName(const std::string& pszName) const;
    bool                    isRenamable() const;
    const  std::string      description(void) const;
    void                    setDescription(const std::string& pszDescription) const;
    Adesk::UInt32           bitFlags() const;
    void                    setBitFlags(Adesk::UInt32 flags) const;
    AcDbMLeaderStyle::ContentType contentType() const;
    void                    setContentType(AcDbMLeaderStyle::ContentType contentType) const;
    void                    setDrawMLeaderOrderType(AcDbMLeaderStyle::DrawMLeaderOrderType drawMLeaderOrderType) const;
    AcDbMLeaderStyle::DrawMLeaderOrderType drawMLeaderOrderType() const;
    void                    setDrawLeaderOrderType(AcDbMLeaderStyle::DrawLeaderOrderType drawLeaderOrderType) const;
    AcDbMLeaderStyle::DrawLeaderOrderType drawLeaderOrderType() const;
    void                    setMaxLeaderSegmentsPoints(int maxLeaderSegmentsPoints) const;
    int                     maxLeaderSegmentsPoints() const;
    void                    setFirstSegmentAngleConstraint(AcDbMLeaderStyle::SegmentAngleType angle) const;
    AcDbMLeaderStyle::SegmentAngleType firstSegmentAngleConstraint() const;
    void                    setSecondSegmentAngleConstraint(AcDbMLeaderStyle::SegmentAngleType angle) const;
    AcDbMLeaderStyle::SegmentAngleType secondSegmentAngleConstraint() const;
    void                    setLeaderLineType(AcDbMLeaderStyle::LeaderType leaderLineType) const;
    AcDbMLeaderStyle::LeaderType leaderLineType() const;
    void                    setLeaderLineColor(const AcCmColor& leaderLineColor) const;
    AcCmColor               leaderLineColor() const;
    void                    setLeaderLineTypeId(const PyDbObjectId& leaderLineTypeId) const;
    PyDbObjectId            leaderLineTypeId() const;
    void                    setLeaderLineWeight(AcDb::LineWeight leaderLineWeight) const;
    AcDb::LineWeight        leaderLineWeight() const;
    void                    setEnableLanding(bool enableLanding) const;
    bool                    enableLanding() const;
    void                    setLandingGap(double landingGap) const;
    double                  landingGap() const;
    void                    setEnableDogleg(bool enableDogleg) const;
    bool                    enableDogleg() const;
    void                    setDoglegLength(double doglegLength) const;
    double                  doglegLength() const;
    void                    setArrowSymbolId1(const std::string& name) const;
    void                    setArrowSymbolId2(const PyDbObjectId& arrowSymbolId) const;
    PyDbObjectId            arrowSymbolId() const;
    void                    setArrowSize(double arrowSize) const;
    double                  arrowSize() const;
    void                    setDefaultMText(const PyDbMText& defaultMText) const;
    PyDbMText               defaultMText() const;
    void                    setTextStyleId(const PyDbObjectId& textStyleId) const;
    PyDbObjectId            textStyleId() const;
    void                    setTextAttachmentType1(AcDbMLeaderStyle::TextAttachmentType textAttachmentType, AcDbMLeaderStyle::LeaderDirectionType leaderDirection) const;
    AcDbMLeaderStyle::TextAttachmentType   textAttachmentType1(AcDbMLeaderStyle::LeaderDirectionType leaderDirection) const;
    void                    setTextAttachmentType2(AcDbMLeaderStyle::TextAttachmentType textAttachmentType) const;
    AcDbMLeaderStyle::TextAttachmentType   textAttachmentType2() const;
    void                    setTextAngleType(AcDbMLeaderStyle::TextAngleType textAngleType) const;
    AcDbMLeaderStyle::TextAngleType textAngleType() const;
    void                    setTextAlignmentType(AcDbMLeaderStyle::TextAlignmentType textAlignmentType) const;
    AcDbMLeaderStyle::TextAlignmentType textAlignmentType() const;
    void                    setTextAlignAlwaysLeft(bool bAlwaysLeft) const;
    bool                    textAlignAlwaysLeft() const;
    void                    setTextColor(const AcCmColor& textColor) const;
    AcCmColor               textColor() const;
    void                    setTextHeight(double textHeight) const;
    double                  textHeight() const;
    void                    setEnableFrameText(bool enableFrameText) const;
    bool                    enableFrameText() const;
    void                    setAlignSpace(double alignSpace) const;
    double                  alignSpace() const;
    void                    setBlockId1(const std::string& name) const;
    void                    setBlockId2(const PyDbObjectId& blockId) const;
    PyDbObjectId            blockId() const;
    void                    setBlockColor(const AcCmColor& blockColor) const;
    AcCmColor               blockColor() const;
    void                    setBlockScale(const AcGeScale3d& scale) const;
    AcGeScale3d             blockScale() const;
    void                    setEnableBlockScale(bool enableBlockScale) const;
    bool                    enableBlockScale() const;
    void                    setBlockRotation(double rotation) const;
    double                  blockRotation() const;
    void                    setEnableBlockRotation(bool enableBlockRotation) const;
    bool                    enableBlockRotation() const;
    void                    setBlockConnectionType(AcDbMLeaderStyle::BlockConnectionType blockConnectionType) const;
    AcDbMLeaderStyle::BlockConnectionType blockConnectionType() const;
    void                    setScale(double scale) const;
    double                  scale() const;
    bool                    overwritePropChanged() const;
    PyDbObjectId            postMLeaderStyleToDb(PyDbDatabase& pDb, const std::string& styleName) const;
    void                    setAnnotative(bool isAnnotative) const;
    bool                    annotative() const;
    void                    setBreakSize(double size) const;
    double                  breakSize() const;
    void                    setTextAttachmentDirection(AcDbMLeaderStyle::TextAttachmentDirection textAttachmentDirection) const;
    AcDbMLeaderStyle::TextAttachmentDirection   textAttachmentDirection() const;
    void                    setExtendLeaderToText(bool value) const;
    bool                    extendLeaderToText() const;

public:
    static std::string  className();
    static PyRxClass    desc();

public:
    AcDbMLeaderStyle* impObj(const std::source_location& src = std::source_location::current()) const;
};

#pragma pack (pop)
