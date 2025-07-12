#pragma once
#include "PyDbEntity.h"
#include "PyDbSymbolTableRecord.h"

#pragma pack (push, 8)
class PyDbObjectId;
class PyDbMText;

//-----------------------------------------------------------------------------------
//PyDbRegion
void makePyDbDimensionWrapper();
class PyDbDimension : public PyDbEntity
{
public:
    PyDbDimension(AcDbDimension* ptr, bool autoDelete);
    PyDbDimension(const PyDbObjectId& id);
    PyDbDimension(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbDimension(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    virtual ~PyDbDimension() override = default;
    boost::python::tuple textDefinedSize() const;
    void                setTextDefinedSize(double width, double height) const;
    void                resetTextDefinedSize() const;
    AcGePoint3d         textPosition() const;
    void                setTextPosition(const AcGePoint3d& val) const;
    Adesk::Boolean      isUsingDefaultTextPosition() const;
    void                useSetTextPosition() const;
    void                useDefaultTextPosition() const;
    void                setUsingDefaultTextPosition(bool) const;
    AcGeVector3d        normal() const;
    void                setNormal(const AcGeVector3d&) const;
    double              elevation() const;
    void                setElevation(double val) const;
    std::string         dimensionText() const;
    void                setDimensionText(const  std::string& val) const;
    double              textRotation() const;
    void                setTextRotation(double val) const;
    PyDbObjectId        dimensionStyle() const;
    void                setDimensionStyle(const PyDbObjectId& val) const;
    AcDbMText::AttachmentPoint textAttachment() const;
    void                setTextAttachment(AcDbMText::AttachmentPoint eAtt) const;
    AcDb::LineSpacingStyle textLineSpacingStyle() const;
    void                setTextLineSpacingStyle(AcDb::LineSpacingStyle eStyle) const;
    double              textLineSpacingFactor() const;
    void                setTextLineSpacingFactor(double dFactor) const;
    PyDbDimStyleTableRecord getDimstyleData() const;
    void                setDimstyleData2(const PyDbDimStyleTableRecord& pNewData) const;
    void                setDimstyleData1(const PyDbObjectId& newDataId) const;
    double              horizontalRotation() const;
    void                setHorizontalRotation(double newVal) const;
    PyDbObjectId        dimBlockId() const;
    void                setDimBlockId(const PyDbObjectId& val) const;
    AcGePoint3d         dimBlockPosition() const;
    void                setDimBlockPosition(const AcGePoint3d& val) const;
    void                recomputeDimBlock1() const;
    void                recomputeDimBlock2(bool forceUpdate) const;
    void                generateLayout() const;
    double              measurement() const;
    std::string         formatMeasurement1(double measurement) const;
    std::string         formatMeasurement2(double measurement, const std::string& dimensionText) const;
    bool                isDynamicDimension() const;
    void                setDynamicDimension(bool newVal) const;
    PyDbObjectId        dimLineLinetype() const;
    void                setDimLineLinetype(const PyDbObjectId& linetype) const;
    PyDbObjectId        dimExt1Linetype() const;
    void                setDimExt1Linetype(const PyDbObjectId& linetype) const;
    PyDbObjectId        dimExt2Linetype() const;
    void                setDimExt2Linetype(const PyDbObjectId& linetype) const;
    void                removeTextField() const;
    void                fieldToMText(PyDbMText& pDimMText) const;
    void                fieldFromMText(PyDbMText& pDimMText) const;
    bool                isHorizontalRefTextRotation() const;
    void                setHorizontalRefTextRotation(bool newVal) const;
    bool                getArrowFirstIsFlipped() const;
    bool                getArrowSecondIsFlipped() const;
    void                setArrowFirstIsFlipped(bool bIsFlipped) const;
    void                setArrowSecondIsFlipped(bool bIsFlipped) const;
    AcGeMatrix3d        blockTransform() const;
    bool                inspection() const;
    void                setInspection(bool val) const;
    int                 inspectionFrame() const;
    void                setInspectionFrame(int frame) const;
    const std::string   inspectionLabel() const;
    void                setInspectionLabel(const std::string& label) const;
    boost::python::tuple isConstraintObject() const;
    bool                isConstraintDynamic(void) const;
    void                setConstraintDynamic(bool bDynamic) const;
    bool                shouldParticipateInOPM(void) const;
    void                setShouldParticipateInOPM(bool bShouldParticipate) const;
    double              centerMarkSize() const;
    std::string         prefix() const;
    void                setPrefix(const std::string& val) const;
    std::string         suffix() const;
    void                setSuffix(const std::string& val) const;
    std::string         alternateSuffix() const;
    void                setAlternateSuffix(const std::string& val) const;
    std::string         alternatePrefix() const;
    void                setAlternatePrefix(const std::string& val) const;
    bool                suppressAngularLeadingZeros() const;
    void                setSuppressAngularLeadingZeros(bool val) const;
    bool                suppressAngularTrailingZeros() const;
    void                setSuppressAngularTrailingZeros(bool val) const;
    bool                altSuppressZeroInches() const;
    void                setAltSuppressZeroInches(bool val) const;
    bool                altSuppressZeroFeet() const;
    void                setAltSuppressZeroFeet(bool val) const;
    bool                altSuppressTrailingZeros() const;
    void                setAltSuppressTrailingZeros(bool val) const;
    bool                altToleranceSuppressLeadingZeros() const;
    void                setAltToleranceSuppressLeadingZeros(bool val) const;
    bool                altToleranceSuppressZeroInches() const;
    void                setAltToleranceSuppressZeroInches(bool val) const;
    bool                altToleranceSuppressZeroFeet() const;
    void                setAltToleranceSuppressZeroFeet(bool val) const;
    bool                altToleranceSuppressTrailingZeros() const;
    void                setAltToleranceSuppressTrailingZeros(bool val) const;
    bool                suppressZeroFeet() const;
    void                setSuppressZeroFeet(bool val) const;
    bool                suppressTrailingZeros() const;
    void                setSuppressTrailingZeros(bool val) const;
    bool                suppressLeadingZeros() const;
    void                setSuppressLeadingZeros(bool val) const;
    bool                suppressZeroInches() const;
    void                setSuppressZeroInches(bool val) const;
    bool                altSuppressLeadingZeros() const;
    void                setAltSuppressLeadingZeros(bool val) const;
    bool                toleranceSuppressZeroFeet() const;
    void                setToleranceSuppressZeroFeet(bool val) const;
    bool                toleranceSuppressTrailingZeros() const;
    void                setToleranceSuppressTrailingZeros(bool val) const;
    bool                toleranceSuppressLeadingZeros() const;
    void                setToleranceSuppressLeadingZeros(bool val) const;
    bool                toleranceSuppressZeroInches() const;
    void                setToleranceSuppressZeroInches(bool val) const;
#if !defined(_BRXTARGET260)
    AcDbDimension::CenterMarkType centerMarkType() const;
#endif
    static std::string className();
    static PyRxClass desc();
    static PyDbDimension cloneFrom(const PyRxObject& src);
    static PyDbDimension cast(const PyRxObject& src);
public:
    AcDbDimension* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//PyDb2LineAngularDimension
void makePyDb2LineAngularDimensionWrapper();
class PyDb2LineAngularDimension : public PyDbDimension
{
public:
    PyDb2LineAngularDimension();
    virtual ~PyDb2LineAngularDimension() override = default;
    PyDb2LineAngularDimension(AcDb2LineAngularDimension* ptr, bool autoDelete);
    PyDb2LineAngularDimension(const PyDbObjectId& id);
    PyDb2LineAngularDimension(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDb2LineAngularDimension(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    PyDb2LineAngularDimension(const AcGePoint3d& xLine1Start,
        const AcGePoint3d& xLine1End,
        const AcGePoint3d& xLine2Start,
        const AcGePoint3d& xLine2End,
        const AcGePoint3d& arcPoint);
    PyDb2LineAngularDimension(const AcGePoint3d& xLine1Start,
        const AcGePoint3d& xLine1End,
        const AcGePoint3d& xLine2Start,
        const AcGePoint3d& xLine2End,
        const AcGePoint3d& arcPoint,
        const std::string& dimText) ;
    PyDb2LineAngularDimension(const AcGePoint3d& xLine1Start,
        const AcGePoint3d& xLine1End,
        const AcGePoint3d& xLine2Start,
        const AcGePoint3d& xLine2End,
        const AcGePoint3d& arcPoint,
        const std::string& dimText,
        const PyDbObjectId& dimStyle);
    AcGePoint3d         arcPoint() const;
    void                setArcPoint(const AcGePoint3d& val) const;
    AcGePoint3d         xLine1Start() const;
    void                setXLine1Start(const AcGePoint3d& val) const;
    AcGePoint3d         xLine1End() const;
    void                setXLine1End(const AcGePoint3d& val) const;
    AcGePoint3d         xLine2Start() const;
    void                setXLine2Start(const AcGePoint3d& val) const;
    AcGePoint3d         xLine2End() const;
    void                setXLine2End(const AcGePoint3d& val) const;
    bool                extArcOn() const;
    void                setExtArcOn(bool value) const;
    static std::string  className();
    static PyRxClass    desc();
    static PyDb2LineAngularDimension cloneFrom(const PyRxObject& src);
    static PyDb2LineAngularDimension cast(const PyRxObject& src);
public:
    AcDb2LineAngularDimension* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//AcDb3PointAngularDimension
void makePyDb3PointAngularDimensionWrapper();
class PyDb3PointAngularDimension : public PyDbDimension
{
public:
    PyDb3PointAngularDimension();
    PyDb3PointAngularDimension(const AcGePoint3d& centerPoint,
        const AcGePoint3d& xLine1Point,
        const AcGePoint3d& xLine2Point,
        const AcGePoint3d& arcPoint);
    PyDb3PointAngularDimension(const AcGePoint3d& centerPoint,
        const AcGePoint3d& xLine1Point,
        const AcGePoint3d& xLine2Point,
        const AcGePoint3d& arcPoint,
        const std::string& dimText);
    PyDb3PointAngularDimension(const AcGePoint3d& centerPoint,
        const AcGePoint3d& xLine1Point,
        const AcGePoint3d& xLine2Point,
        const AcGePoint3d& arcPoint,
        const std::string& dimText,
        const PyDbObjectId& dimStyle);
    PyDb3PointAngularDimension(AcDb3PointAngularDimension* ptr, bool autoDelete);
    PyDb3PointAngularDimension(const PyDbObjectId& id, AcDb::OpenMode mode, bool);
    PyDb3PointAngularDimension(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDb3PointAngularDimension(const PyDbObjectId& id);
    virtual ~PyDb3PointAngularDimension() override = default;
    AcGePoint3d         arcPoint() const;
    void                setArcPoint(const AcGePoint3d& val) const;
    AcGePoint3d         xLine1Point() const;
    void                setXLine1Point(const AcGePoint3d& val) const;
    AcGePoint3d         xLine2Point() const;
    void                setXLine2Point(const AcGePoint3d& val) const;
    AcGePoint3d         centerPoint() const;
    void                setCenterPoint(const AcGePoint3d& val) const;
    bool                extArcOn() const;
    void                setExtArcOn(bool value) const;
    static std::string  className();
    static PyRxClass    desc();
    static PyDb3PointAngularDimension cloneFrom(const PyRxObject& src);
    static PyDb3PointAngularDimension cast(const PyRxObject& src);
public:
    AcDb3PointAngularDimension* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//AcDbAlignedDimension
void makePyDbAlignedDimensionWrapper();
class PyDbAlignedDimension : public PyDbDimension
{
public:
    PyDbAlignedDimension();
    PyDbAlignedDimension(const AcGePoint3d& xLine1Point,
        const AcGePoint3d& xLine2Point,
        const AcGePoint3d& dimLinePoint);
    PyDbAlignedDimension(const AcGePoint3d& xLine1Point,
        const AcGePoint3d& xLine2Point,
        const AcGePoint3d& dimLinePoint,
        const std::string& dimText);
    PyDbAlignedDimension(const AcGePoint3d& xLine1Point,
        const AcGePoint3d& xLine2Point,
        const AcGePoint3d& dimLinePoint,
        const std::string& dimText,
        const PyDbObjectId& dimStyle);
    PyDbAlignedDimension(AcDbAlignedDimension* ptr, bool autoDelete);
    PyDbAlignedDimension(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    PyDbAlignedDimension(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbAlignedDimension(const PyDbObjectId& id);
    virtual ~PyDbAlignedDimension() override = default;
    AcGePoint3d         xLine1Point() const;
    void                setXLine1Point(const AcGePoint3d& val) const;
    AcGePoint3d         xLine2Point() const;
    void                setXLine2Point(const AcGePoint3d& val) const;
    AcGePoint3d         dimLinePoint() const;
    void                setDimLinePoint(const AcGePoint3d& val) const;
    double              oblique() const;
    void                setOblique(double val) const;
    bool                jogSymbolOn() const;
    void                setJogSymbolOn(bool value) const;
    AcGePoint3d         jogSymbolPosition() const;
    void                setJogSymbolPosition(const AcGePoint3d& pt) const;
    static std::string  className();
    static PyRxClass    desc();
    static PyDbAlignedDimension cloneFrom(const PyRxObject& src);
    static PyDbAlignedDimension cast(const PyRxObject& src);
public:
    AcDbAlignedDimension* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//AcDbArcDimension
void makePyDbArcDimensionWrapper();
class PyDbArcDimension : public PyDbDimension
{
public:
    PyDbArcDimension();
    PyDbArcDimension(const AcGePoint3d& centerPoint,
        const AcGePoint3d& xLine1Point,
        const AcGePoint3d& xLine2Point,
        const AcGePoint3d& arcPoint);
    PyDbArcDimension(const AcGePoint3d& centerPoint,
        const AcGePoint3d& xLine1Point,
        const AcGePoint3d& xLine2Point,
        const AcGePoint3d& arcPoint,
        const std::string& dimText);
    PyDbArcDimension(const AcGePoint3d& centerPoint,
        const AcGePoint3d& xLine1Point,
        const AcGePoint3d& xLine2Point,
        const AcGePoint3d& arcPoint,
        const std::string& dimText,
        const PyDbObjectId& styleId);
    PyDbArcDimension(AcDbArcDimension* ptr, bool autoDelete);
    PyDbArcDimension(const PyDbObjectId& id, AcDb::OpenMode mode, bool);
    PyDbArcDimension(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbArcDimension(const PyDbObjectId& id);
    virtual ~PyDbArcDimension() override = default;
    AcGePoint3d         arcPoint() const;
    void                setArcPoint(const AcGePoint3d& arcPt) const;
    AcGePoint3d         xLine1Point() const;
    void                setXLine1Point(const AcGePoint3d& xLine1Pt) const;
    AcGePoint3d         xLine2Point() const;
    void                setXLine2Point(const AcGePoint3d& xLine2Pt) const;
    AcGePoint3d         centerPoint() const;
    void                setCenterPoint(const AcGePoint3d& ctrPt) const;
    bool                isPartial() const;
    void                setIsPartial(bool partial) const;
    double              arcStartParam() const;
    void                setArcStartParam(double arcParam) const;
    double              arcEndParam() const;
    void                setArcEndParam(double arcParam) const;
    bool                hasLeader() const;
    void                setHasLeader(bool leaderVal) const;
    AcGePoint3d         leader1Point() const;
    void                setLeader1Point(const AcGePoint3d& ldr1Pt) const;
    AcGePoint3d         leader2Point() const;
    void                setLeader2Point(const AcGePoint3d& ldr2Pt) const;
    int                 arcSymbolType() const;
    void                setArcSymbolType(int symbol) const;
    static std::string  className();
    static PyRxClass    desc();
    static PyDbArcDimension cloneFrom(const PyRxObject& src);
    static PyDbArcDimension cast(const PyRxObject& src);
public:
    AcDbArcDimension* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//AcDbDiametricDimension
void makePyDbDiametricDimensionWrapper();
class PyDbDiametricDimension : public PyDbDimension
{
public:
    PyDbDiametricDimension();
    PyDbDiametricDimension(AcDbDiametricDimension* ptr, bool autoDelete);
    PyDbDiametricDimension(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    PyDbDiametricDimension(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbDiametricDimension(const PyDbObjectId& id);
    PyDbDiametricDimension(const AcGePoint3d& chordPoint,
        const AcGePoint3d& farChordPoint,
        double leaderLength);
    PyDbDiametricDimension(const AcGePoint3d& chordPoint,
        const AcGePoint3d& farChordPoint,
        double leaderLength,
        const std::string& dimText);
    PyDbDiametricDimension(const AcGePoint3d& chordPoint,
        const AcGePoint3d& farChordPoint,
        double leaderLength,
        const std::string& dimText,
        const PyDbObjectId& styleId);
    virtual ~PyDbDiametricDimension() override = default;
    double              leaderLength() const;
    void                setLeaderLength(double val) const;
    AcGePoint3d         chordPoint() const;
    void                setChordPoint(const AcGePoint3d& val) const;
    AcGePoint3d         farChordPoint() const;
    void                setFarChordPoint(const AcGePoint3d& val) const;
    double              extArcStartAngle() const;
    void                setExtArcStartAngle(double newAngle) const;
    double              extArcEndAngle() const;
    void                setExtArcEndAngle(double newAngle) const;
    static std::string  className();
    static PyRxClass    desc();
    static PyDbDiametricDimension cloneFrom(const PyRxObject& src);
    static PyDbDiametricDimension cast(const PyRxObject& src);
public:
    AcDbDiametricDimension* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//AcDbOrdinateDimension
void makePyDbOrdinateDimensionWrapper();
class PyDbOrdinateDimension : public PyDbDimension
{
public:
    PyDbOrdinateDimension();
    PyDbOrdinateDimension(AcDbOrdinateDimension* ptr, bool autoDelete);
    PyDbOrdinateDimension(const PyDbObjectId& id);
    PyDbOrdinateDimension(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbOrdinateDimension(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    PyDbOrdinateDimension(
        Adesk::Boolean useXAxis,
        const AcGePoint3d& definingPoint,
        const AcGePoint3d& leaderEndPoint);
    PyDbOrdinateDimension(
        Adesk::Boolean useXAxis,
        const AcGePoint3d& definingPoint,
        const AcGePoint3d& leaderEndPoint,
        const std::string& dimText);
    PyDbOrdinateDimension(
        Adesk::Boolean useXAxis,
        const AcGePoint3d& definingPoint,
        const AcGePoint3d& leaderEndPoint,
        const std::string& dimText,
        const PyDbObjectId& styleId);
    virtual ~PyDbOrdinateDimension() override = default;
    Adesk::Boolean      isUsingXAxis() const;
    Adesk::Boolean      isUsingYAxis() const;
    void                useXAxis() const;
    void                useYAxis() const;
    void                setUsingXAxis(bool value) const;
    void                setUsingYAxis(bool value) const;
    AcGePoint3d         origin() const;
    void                setOrigin(const AcGePoint3d& val) const;
    AcGePoint3d         definingPoint() const;
    void                setDefiningPoint(const AcGePoint3d& val) const;
    AcGePoint3d         leaderEndPoint() const;
    void                setLeaderEndPoint(const AcGePoint3d& val) const;
    static std::string  className();
    static PyRxClass    desc();
    static PyDbOrdinateDimension cloneFrom(const PyRxObject& src);
    static PyDbOrdinateDimension cast(const PyRxObject& src);
public:
    AcDbOrdinateDimension* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//AcDbRadialDimension
void makePyDbRadialDimensionWrapper();
class PyDbRadialDimension : public PyDbDimension
{
public:
    PyDbRadialDimension();
    PyDbRadialDimension(AcDbRadialDimension* ptr, bool autoDelete);
    PyDbRadialDimension(const PyDbObjectId& id);
    PyDbRadialDimension(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbRadialDimension(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    PyDbRadialDimension(
        const AcGePoint3d& center,
        const AcGePoint3d& chordPoint,
        double leaderLength);
    PyDbRadialDimension(
        const AcGePoint3d& center,
        const AcGePoint3d& chordPoint,
        double leaderLength,
        const std::string& dimText);
    PyDbRadialDimension(
        const AcGePoint3d& center,
        const AcGePoint3d& chordPoint,
        double leaderLength,
        const std::string& dimText,
        const PyDbObjectId& styleId);
    virtual ~PyDbRadialDimension() override = default;
    double              leaderLength() const;
    void                setLeaderLength(double val) const;
    AcGePoint3d         center() const;
    void                setCenter(const AcGePoint3d& val) const;
    AcGePoint3d         chordPoint() const;
    void                setChordPoint(const AcGePoint3d& val) const;
    double              extArcStartAngle() const;
    void                setExtArcStartAngle(double newAngle) const;
    double              extArcEndAngle() const;
    void                setExtArcEndAngle(double newAngle) const;
    static std::string  className();
    static PyRxClass    desc();
    static PyDbRadialDimension cloneFrom(const PyRxObject& src);
    static PyDbRadialDimension cast(const PyRxObject& src);
public:
    AcDbRadialDimension* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//AcDbRadialDimensionLarge
void makePyDbRadialDimensionLargeWrapper();
class PyDbRadialDimensionLarge : public PyDbDimension
{
public:
    PyDbRadialDimensionLarge();
    PyDbRadialDimensionLarge(AcDbRadialDimensionLarge* ptr, bool autoDelete);
    PyDbRadialDimensionLarge(const PyDbObjectId& id);
    PyDbRadialDimensionLarge(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbRadialDimensionLarge(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    PyDbRadialDimensionLarge(const AcGePoint3d& center,
        const AcGePoint3d& chordPoint,
        const AcGePoint3d& overrideCenter,
        const AcGePoint3d& jogPoint,
        double jogAngle);
    PyDbRadialDimensionLarge(const AcGePoint3d& center,
        const AcGePoint3d& chordPoint,
        const AcGePoint3d& overrideCenter,
        const AcGePoint3d& jogPoint,
        double jogAngle,
        const std::string& dimText);
    PyDbRadialDimensionLarge(const AcGePoint3d& center,
        const AcGePoint3d& chordPoint,
        const AcGePoint3d& overrideCenter,
        const AcGePoint3d& jogPoint,
        double jogAngle,
        const std::string& dimText,
        const PyDbObjectId& styleId);
    virtual ~PyDbRadialDimensionLarge() override = default;
    AcGePoint3d         center() const;
    void                setCenter(const AcGePoint3d& centerPoint) const;
    AcGePoint3d         chordPoint() const;
    void                setChordPoint(const AcGePoint3d& chordPoint) const;
    AcGePoint3d         overrideCenter() const;
    void                setOverrideCenter(const AcGePoint3d& overrideCenterPoint) const;
    AcGePoint3d         jogPoint() const;
    void                setJogPoint(const AcGePoint3d& jogPoint) const;
    double              jogAngle() const;
    void                setJogAngle(double jogAngle) const;
    void                setOverrideCenterPP(const AcGePoint3d& overrideCenterPointPP) const;
    void                setJogPointPP(const AcGePoint3d& jogPointPP) const;
    void                setTextPositionPP(const AcGePoint3d& textPointPP) const;
    double              extArcStartAngle() const;
    void                setExtArcStartAngle(double newAngle) const;
    double              extArcEndAngle() const;
    void                setExtArcEndAngle(double newAngle) const;
    static std::string  className();
    static PyRxClass    desc();
    static PyDbRadialDimensionLarge cloneFrom(const PyRxObject& src);
    static PyDbRadialDimensionLarge cast(const PyRxObject& src);
public:
    AcDbRadialDimensionLarge* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//AcDbRotatedDimension
void makePyDbRotatedDimensionWrapper();
class PyDbRotatedDimension : public PyDbDimension
{
public:
    PyDbRotatedDimension();
    PyDbRotatedDimension(AcDbRotatedDimension* ptr, bool autoDelete);
    PyDbRotatedDimension(const PyDbObjectId& id);
    PyDbRotatedDimension(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbRotatedDimension(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    PyDbRotatedDimension(
        double rotation,
        const AcGePoint3d& xLine1Point,
        const AcGePoint3d& xLine2Point,
        const AcGePoint3d& dimLinePoint);
    PyDbRotatedDimension(
        double rotation,
        const AcGePoint3d& xLine1Point,
        const AcGePoint3d& xLine2Point,
        const AcGePoint3d& dimLinePoint,
        const std::string& dimText);
    PyDbRotatedDimension(
        double rotation,
        const AcGePoint3d& xLine1Point,
        const AcGePoint3d& xLine2Point,
        const AcGePoint3d& dimLinePoint,
        const std::string& dimText,
        const PyDbObjectId& styleId);
    virtual ~PyDbRotatedDimension() override = default;
    AcGePoint3d         xLine1Point() const;
    void                setXLine1Point(const AcGePoint3d& val) const;
    AcGePoint3d         xLine2Point() const;
    void                setXLine2Point(const AcGePoint3d& val) const;
    AcGePoint3d         dimLinePoint() const;
    void                setDimLinePoint(const AcGePoint3d& val) const;
    double              oblique() const;
    void                setOblique(double val) const;
    double              rotation() const;
    void                setRotation(double val) const;
    bool                jogSymbolOn() const;
    void                setJogSymbolOn(bool val) const;
    AcGePoint3d         jogSymbolPosition() const;
    void                setJogSymbolPosition(const AcGePoint3d& val) const;
    static std::string  className();
    static PyRxClass    desc();
    static PyDbRotatedDimension cloneFrom(const PyRxObject& src);
    static PyDbRotatedDimension cast(const PyRxObject& src);
public:
    AcDbRotatedDimension* impObj(const std::source_location& src = std::source_location::current()) const;
};
#pragma pack (pop)