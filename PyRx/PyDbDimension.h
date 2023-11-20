#pragma once
#include "PyDbEntity.h"
#include "PyDbSymbolTableRecord.h"

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
    virtual ~PyDbDimension() override = default;
    boost::python::tuple textDefinedSize() const;
    void                setTextDefinedSize(double width, double height);
    void                resetTextDefinedSize();
    AcGePoint3d         textPosition() const;
    void                setTextPosition(const AcGePoint3d& val);
    Adesk::Boolean      isUsingDefaultTextPosition() const;
    void                useSetTextPosition();
    void                useDefaultTextPosition();
    void                setUsingDefaultTextPosition(bool);
    AcGeVector3d        normal() const;
    void                setNormal(const AcGeVector3d&);
    double              elevation() const;
    void                setElevation(double val);
    std::string         dimensionText() const;
    void                setDimensionText(const  std::string& val);
    double              textRotation() const;
    void                setTextRotation(double val);
    PyDbObjectId        dimensionStyle() const;
    void                setDimensionStyle(const PyDbObjectId& val);
    AcDbMText::AttachmentPoint textAttachment() const;
    void                setTextAttachment(AcDbMText::AttachmentPoint eAtt);
    AcDb::LineSpacingStyle textLineSpacingStyle() const;
    void                setTextLineSpacingStyle(AcDb::LineSpacingStyle eStyle);
    double              textLineSpacingFactor() const;
    void                setTextLineSpacingFactor(double dFactor);
    PyDbDimStyleTableRecord getDimstyleData() const;
    void                setDimstyleData2(const PyDbDimStyleTableRecord& pNewData);
    void                setDimstyleData1(const PyDbObjectId& newDataId);
    double              horizontalRotation() const;
    void                setHorizontalRotation(double newVal);
    PyDbObjectId        dimBlockId() const;
    void                setDimBlockId(const PyDbObjectId& val);
    AcGePoint3d         dimBlockPosition() const;
    void                setDimBlockPosition(const AcGePoint3d& val);
    void                recomputeDimBlock1();
    void                recomputeDimBlock2(bool forceUpdate);
    void                generateLayout();
    double              measurement();
    std::string         formatMeasurement1(double measurement);
    std::string         formatMeasurement2(double measurement, const std::string& dimensionText);
    bool                isDynamicDimension() const;
    void                setDynamicDimension(bool newVal);
    PyDbObjectId        dimLineLinetype() const;
    void                setDimLineLinetype(const PyDbObjectId& linetype);
    PyDbObjectId        dimExt1Linetype() const;
    void                setDimExt1Linetype(const PyDbObjectId& linetype);
    PyDbObjectId        dimExt2Linetype() const;
    void                setDimExt2Linetype(const PyDbObjectId& linetype);
    void                removeTextField();
    void                fieldToMText(PyDbMText& pDimMText);
    void                fieldFromMText(PyDbMText& pDimMText);
    bool                isHorizontalRefTextRotation() const;
    void                setHorizontalRefTextRotation(bool newVal);
    bool                getArrowFirstIsFlipped() const;
    bool                getArrowSecondIsFlipped() const;
    void                setArrowFirstIsFlipped(bool bIsFlipped);
    void                setArrowSecondIsFlipped(bool bIsFlipped);
    AcGeMatrix3d        blockTransform() const;
    bool                inspection() const;
    void                setInspection(bool val);
    int                 inspectionFrame() const;
    void                setInspectionFrame(int frame);
    const std::string   inspectionLabel() const;
    void                setInspectionLabel(const std::string& label);
    boost::python::tuple isConstraintObject() const;
    bool                isConstraintDynamic(void) const;
    void                setConstraintDynamic(bool bDynamic);
    bool                shouldParticipateInOPM(void) const;
    void                setShouldParticipateInOPM(bool bShouldParticipate);
    double              centerMarkSize() const;
    std::string         prefix() const;
    void                setPrefix(const std::string& val);
    std::string         suffix() const;
    void                setSuffix(const std::string& val);
    std::string         alternateSuffix() const;
    void                setAlternateSuffix(const std::string& val);
    std::string         alternatePrefix() const;
    void                setAlternatePrefix(const std::string& val);
    bool                suppressAngularLeadingZeros() const;
    void                setSuppressAngularLeadingZeros(bool val);
    bool                suppressAngularTrailingZeros() const;
    void                setSuppressAngularTrailingZeros(bool val);
    bool                altSuppressZeroInches() const;
    void                setAltSuppressZeroInches(bool val);
    bool                altSuppressZeroFeet() const;
    void                setAltSuppressZeroFeet(bool val);
    bool                altSuppressTrailingZeros() const;
    void                setAltSuppressTrailingZeros(bool val);
    bool                altToleranceSuppressLeadingZeros() const;
    void                setAltToleranceSuppressLeadingZeros(bool val);
    bool                altToleranceSuppressZeroInches() const;
    void                setAltToleranceSuppressZeroInches(bool val);
    bool                altToleranceSuppressZeroFeet() const;
    void                setAltToleranceSuppressZeroFeet(bool val);
    bool                altToleranceSuppressTrailingZeros() const;
    void                setAltToleranceSuppressTrailingZeros(bool val);
    bool                suppressZeroFeet() const;
    void                setSuppressZeroFeet(bool val);
    bool                suppressTrailingZeros() const;
    void                setSuppressTrailingZeros(bool val);
    bool                suppressLeadingZeros() const;
    void                setSuppressLeadingZeros(bool val);
    bool                suppressZeroInches() const;
    void                setSuppressZeroInches(bool val);
    bool                altSuppressLeadingZeros() const;
    void                setAltSuppressLeadingZeros(bool val);
    bool                toleranceSuppressZeroFeet() const;
    void                setToleranceSuppressZeroFeet(bool val);
    bool                toleranceSuppressTrailingZeros() const;
    void                setToleranceSuppressTrailingZeros(bool val);
    bool                toleranceSuppressLeadingZeros() const;
    void                setToleranceSuppressLeadingZeros(bool val);
    bool                toleranceSuppressZeroInches() const;
    void                setToleranceSuppressZeroInches(bool val);
#if !defined(_BRXTARGET) || (_BRXTARGET > 240)
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
        const std::string& dimText);
    PyDb2LineAngularDimension(const AcGePoint3d& xLine1Start,
        const AcGePoint3d& xLine1End,
        const AcGePoint3d& xLine2Start,
        const AcGePoint3d& xLine2End,
        const AcGePoint3d& arcPoint,
        const std::string& dimText,
        const PyDbObjectId& dimStyle);
    AcGePoint3d         arcPoint() const;
    void                setArcPoint(const AcGePoint3d& val);
    AcGePoint3d         xLine1Start() const;
    void                setXLine1Start(const AcGePoint3d& val);
    AcGePoint3d         xLine1End() const;
    void                setXLine1End(const AcGePoint3d& val);
    AcGePoint3d         xLine2Start() const;
    void                setXLine2Start(const AcGePoint3d& val);
    AcGePoint3d         xLine2End() const;
    void                setXLine2End(const AcGePoint3d& val);
    bool                extArcOn() const;
    void                setExtArcOn(bool value);
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
    PyDb3PointAngularDimension(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDb3PointAngularDimension(const PyDbObjectId& id);
    AcGePoint3d         arcPoint() const;
    void                setArcPoint(const AcGePoint3d& val);
    AcGePoint3d         xLine1Point() const;
    void                setXLine1Point(const AcGePoint3d& val);
    AcGePoint3d         xLine2Point() const;
    void                setXLine2Point(const AcGePoint3d& val);
    AcGePoint3d         centerPoint() const;
    void                setCenterPoint(const AcGePoint3d& val);
    bool                extArcOn() const;
    void                setExtArcOn(bool value);
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
    PyDbAlignedDimension(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbAlignedDimension(const PyDbObjectId& id);
    AcGePoint3d         xLine1Point() const;
    void                setXLine1Point(const AcGePoint3d& val);
    AcGePoint3d         xLine2Point() const;
    void                setXLine2Point(const AcGePoint3d& val);
    AcGePoint3d         dimLinePoint() const;
    void                setDimLinePoint(const AcGePoint3d& val);
    double              oblique() const;
    void                setOblique(double val);
    bool                jogSymbolOn() const;
    void                setJogSymbolOn(bool value);
    AcGePoint3d         jogSymbolPosition() const;
    void                setJogSymbolPosition(const AcGePoint3d& pt);
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
    PyDbArcDimension(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbArcDimension(const PyDbObjectId& id);
    AcGePoint3d         arcPoint() const;
    void                setArcPoint(const AcGePoint3d& arcPt);
    AcGePoint3d         xLine1Point() const;
    void                setXLine1Point(const AcGePoint3d& xLine1Pt);
    AcGePoint3d         xLine2Point() const;
    void                setXLine2Point(const AcGePoint3d& xLine2Pt);
    AcGePoint3d         centerPoint() const;
    void                setCenterPoint(const AcGePoint3d& ctrPt);
    bool                isPartial() const;
    void                setIsPartial(bool partial);
    double              arcStartParam() const;
    void                setArcStartParam(double arcParam);
    double              arcEndParam() const;
    void                setArcEndParam(double arcParam);
    bool                hasLeader() const;
    void                setHasLeader(bool leaderVal);
    AcGePoint3d         leader1Point() const;
    void                setLeader1Point(const AcGePoint3d& ldr1Pt);
    AcGePoint3d         leader2Point() const;
    void                setLeader2Point(const AcGePoint3d& ldr2Pt);
    int                 arcSymbolType() const;
    void                setArcSymbolType(int symbol);
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
    double              leaderLength() const;
    void                setLeaderLength(double val);
    AcGePoint3d         chordPoint() const;
    void                setChordPoint(const AcGePoint3d& val);
    AcGePoint3d         farChordPoint() const;
    void                setFarChordPoint(const AcGePoint3d& val);
    double              extArcStartAngle() const;
    void                setExtArcStartAngle(double newAngle);
    double              extArcEndAngle() const;
    void                setExtArcEndAngle(double newAngle);
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
    Adesk::Boolean      isUsingXAxis() const;
    Adesk::Boolean      isUsingYAxis() const;
    void                useXAxis();
    void                useYAxis();
    void                setUsingXAxis(bool value);
    void                setUsingYAxis(bool value);
    AcGePoint3d         origin() const;
    void                setOrigin(const AcGePoint3d& val);
    AcGePoint3d         definingPoint() const;
    void                setDefiningPoint(const AcGePoint3d& val);
    AcGePoint3d         leaderEndPoint() const;
    void                setLeaderEndPoint(const AcGePoint3d& val);
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
    double              leaderLength() const;
    void                setLeaderLength(double val);
    AcGePoint3d         center() const;
    void                setCenter(const AcGePoint3d& val);
    AcGePoint3d         chordPoint() const;
    void                setChordPoint(const AcGePoint3d& val);
    double              extArcStartAngle() const;
    void                setExtArcStartAngle(double newAngle);
    double              extArcEndAngle() const;
    void                setExtArcEndAngle(double newAngle);
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
    AcGePoint3d         center() const;
    void                setCenter(const AcGePoint3d& centerPoint);
    AcGePoint3d         chordPoint() const;
    void                setChordPoint(const AcGePoint3d& chordPoint);
    AcGePoint3d         overrideCenter() const;
    void                setOverrideCenter(const AcGePoint3d& overrideCenterPoint);
    AcGePoint3d         jogPoint() const;
    void                setJogPoint(const AcGePoint3d& jogPoint);
    double              jogAngle() const;
    void                setJogAngle(double jogAngle);
    void                setOverrideCenterPP(const AcGePoint3d& overrideCenterPointPP);
    void                setJogPointPP(const AcGePoint3d& jogPointPP);
    void                setTextPositionPP(const AcGePoint3d& textPointPP);
    double              extArcStartAngle() const;
    void                setExtArcStartAngle(double newAngle);
    double              extArcEndAngle() const;
    void                setExtArcEndAngle(double newAngle);
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
    AcGePoint3d         xLine1Point() const;
    void                setXLine1Point(const AcGePoint3d& val);
    AcGePoint3d         xLine2Point() const;
    void                setXLine2Point(const AcGePoint3d& val);
    AcGePoint3d         dimLinePoint() const;
    void                setDimLinePoint(const AcGePoint3d& val);
    double              oblique() const;
    void                setOblique(double val);
    double              rotation() const;
    void                setRotation(double val);
    bool                jogSymbolOn() const;
    void                setJogSymbolOn(bool val);
    AcGePoint3d         jogSymbolPosition() const;
    void                setJogSymbolPosition(const AcGePoint3d& val);
    static std::string  className();
    static PyRxClass    desc();
    static PyDbRotatedDimension cloneFrom(const PyRxObject& src);
    static PyDbRotatedDimension cast(const PyRxObject& src);
public:
    AcDbRotatedDimension* impObj(const std::source_location& src = std::source_location::current()) const;
};
