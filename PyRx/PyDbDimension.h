#pragma once
#include "PyDbEntity.h"

class PyDbObjectId;
class PyDbMText;

//-----------------------------------------------------------------------------------
//PyDbRegion
void makePyDbDimensionWrapper();

class PyDbDimension : public PyDbEntity
{
public:
    PyDbDimension(AcDbDimension* ptr, bool autoDelete);
    PyDbDimension(const PyDbObjectId& id, AcDb::OpenMode mode);
    virtual ~PyDbDimension() override = default;
    boost::python::tuple textDefinedSize() const;
    void setTextDefinedSize(double width, double height);
    void resetTextDefinedSize();

    AcGePoint3d textPosition() const;
    Acad::ErrorStatus setTextPosition(const AcGePoint3d& val);

    Adesk::Boolean isUsingDefaultTextPosition() const;

    Acad::ErrorStatus   useSetTextPosition();
    Acad::ErrorStatus   useDefaultTextPosition();
    Acad::ErrorStatus   setUsingDefaultTextPosition(bool);

    AcGeVector3d        normal() const;
    Acad::ErrorStatus   setNormal(const AcGeVector3d&);

    double              elevation() const;
    Acad::ErrorStatus   setElevation(double val);

    std::string          dimensionText() const;
    Acad::ErrorStatus    setDimensionText(const  std::string& val);

    double              textRotation() const;
    Acad::ErrorStatus   setTextRotation(double val);

    PyDbObjectId        dimensionStyle() const;
    Acad::ErrorStatus   setDimensionStyle(const PyDbObjectId& val);

    AcDbMText::AttachmentPoint textAttachment() const;
    Acad::ErrorStatus   setTextAttachment(AcDbMText::AttachmentPoint eAtt);

    AcDb::LineSpacingStyle textLineSpacingStyle() const;
    Acad::ErrorStatus   setTextLineSpacingStyle(AcDb::LineSpacingStyle eStyle);

    double              textLineSpacingFactor() const;
    Acad::ErrorStatus   setTextLineSpacingFactor(double dFactor);

    //Acad::ErrorStatus   getDimstyleData(AcDbDimStyleTableRecord*& pRecord) const;
    //Acad::ErrorStatus   setDimstyleData(AcDbDimStyleTableRecord* pNewData);
    Acad::ErrorStatus   setDimstyleData(const PyDbObjectId& newDataId);

    double              horizontalRotation() const;
    Acad::ErrorStatus   setHorizontalRotation(double newVal);

    PyDbObjectId        dimBlockId() const;
    Acad::ErrorStatus   setDimBlockId(const PyDbObjectId& val);
    AcGePoint3d         dimBlockPosition() const;
    Acad::ErrorStatus   setDimBlockPosition(const AcGePoint3d& val);
    Acad::ErrorStatus   recomputeDimBlock1();
    Acad::ErrorStatus   recomputeDimBlock2(bool forceUpdate);
    Acad::ErrorStatus   generateLayout();
    double              measurement();

    std::string         formatMeasurement1(double measurement);
    std::string         formatMeasurement2(double measurement, const std::string& dimensionText);

    bool                isDynamicDimension() const;
    Acad::ErrorStatus   setDynamicDimension(bool newVal);

    PyDbObjectId dimLineLinetype() const;
    Acad::ErrorStatus setDimLineLinetype(const PyDbObjectId& linetype);

    PyDbObjectId dimExt1Linetype() const;
    Acad::ErrorStatus setDimExt1Linetype(const PyDbObjectId& linetype);

    PyDbObjectId dimExt2Linetype() const;
    Acad::ErrorStatus setDimExt2Linetype(const PyDbObjectId& linetype);

    Acad::ErrorStatus   removeTextField();
    Acad::ErrorStatus   fieldToMText(PyDbMText& pDimMText);
    Acad::ErrorStatus   fieldFromMText(PyDbMText& pDimMText);

    bool                isHorizontalRefTextRotation() const;
    Acad::ErrorStatus   setHorizontalRefTextRotation(bool newVal);

    bool getArrowFirstIsFlipped() const;
    bool getArrowSecondIsFlipped() const;
    Acad::ErrorStatus setArrowFirstIsFlipped(bool bIsFlipped);
    Acad::ErrorStatus setArrowSecondIsFlipped(bool bIsFlipped);

    AcGeMatrix3d blockTransform() const;

    bool inspection() const;
    Acad::ErrorStatus setInspection(bool val);

    int inspectionFrame() const;
    Acad::ErrorStatus setInspectionFrame(int frame);

    const std::string inspectionLabel() const;
    Acad::ErrorStatus setInspectionLabel(const std::string& label);

    boost::python::tuple isConstraintObject() const;

    bool  isConstraintDynamic(void) const;
    Acad::ErrorStatus  setConstraintDynamic(bool bDynamic);

    bool  shouldParticipateInOPM(void) const;
    void  setShouldParticipateInOPM(bool bShouldParticipate);

    double                centerMarkSize() const;

    std::string           prefix() const;
    Acad::ErrorStatus     setPrefix(const std::string& val);

    std::string           suffix() const;
    Acad::ErrorStatus     setSuffix(const std::string& val);

    std::string           alternateSuffix() const;
    Acad::ErrorStatus     setAlternateSuffix(const std::string& val);

    std::string           alternatePrefix() const;
    Acad::ErrorStatus     setAlternatePrefix(const std::string& val);

    bool                  suppressAngularLeadingZeros() const;
    Acad::ErrorStatus     setSuppressAngularLeadingZeros(bool val);

    bool                  suppressAngularTrailingZeros() const;
    Acad::ErrorStatus     setSuppressAngularTrailingZeros(bool val);

    bool                  altSuppressZeroInches() const;
    Acad::ErrorStatus     setAltSuppressZeroInches(bool val);
    bool                  altSuppressZeroFeet() const;
    Acad::ErrorStatus     setAltSuppressZeroFeet(bool val);
    bool                  altSuppressTrailingZeros() const;
    Acad::ErrorStatus     setAltSuppressTrailingZeros(bool val);

    bool                  altToleranceSuppressLeadingZeros() const;
    Acad::ErrorStatus     setAltToleranceSuppressLeadingZeros(bool val);
    bool                  altToleranceSuppressZeroInches() const;
    Acad::ErrorStatus     setAltToleranceSuppressZeroInches(bool val);

    bool                  altToleranceSuppressZeroFeet() const;
    Acad::ErrorStatus     setAltToleranceSuppressZeroFeet(bool val);
    bool                  altToleranceSuppressTrailingZeros() const;
    Acad::ErrorStatus     setAltToleranceSuppressTrailingZeros(bool val);

    bool                  suppressZeroFeet() const;
    Acad::ErrorStatus     setSuppressZeroFeet(bool val);
    bool                  suppressTrailingZeros() const;
    Acad::ErrorStatus     setSuppressTrailingZeros(bool val);
    bool                  suppressLeadingZeros() const;
    Acad::ErrorStatus     setSuppressLeadingZeros(bool val);
    bool                  suppressZeroInches() const;
    Acad::ErrorStatus     setSuppressZeroInches(bool val);

    bool                  altSuppressLeadingZeros() const;
    Acad::ErrorStatus     setAltSuppressLeadingZeros(bool val);
    bool                  toleranceSuppressZeroFeet() const;
    Acad::ErrorStatus     setToleranceSuppressZeroFeet(bool val);

    bool                  toleranceSuppressTrailingZeros() const;
    Acad::ErrorStatus     setToleranceSuppressTrailingZeros(bool val);
    bool                  toleranceSuppressLeadingZeros() const;
    Acad::ErrorStatus     setToleranceSuppressLeadingZeros(bool val);

    bool                  toleranceSuppressZeroInches() const;
    Acad::ErrorStatus     setToleranceSuppressZeroInches(bool val);

#ifndef BRXAPP
    AcDbDimension::CenterMarkType centerMarkType() const;
#endif

    static std::string className();
public:
    AcDbDimension* impObj() const;
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
    Acad::ErrorStatus   setArcPoint(const AcGePoint3d& val);

    AcGePoint3d         xLine1Start() const;
    Acad::ErrorStatus   setXLine1Start(const AcGePoint3d& val);

    AcGePoint3d         xLine1End() const;
    Acad::ErrorStatus   setXLine1End(const AcGePoint3d& val);

    AcGePoint3d         xLine2Start() const;
    Acad::ErrorStatus   setXLine2Start(const AcGePoint3d& val);

    AcGePoint3d         xLine2End() const;
    Acad::ErrorStatus   setXLine2End(const AcGePoint3d& val);

    bool extArcOn() const;
    Acad::ErrorStatus setExtArcOn(bool value);

    static std::string className();
public:
    AcDb2LineAngularDimension* impObj() const;
};


//-----------------------------------------------------------------------------------
//AcDb3PointAngularDimension
void makeAcDb3PointAngularDimensionWrapper();

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

    AcGePoint3d         arcPoint() const;
    Acad::ErrorStatus   setArcPoint(const AcGePoint3d& val);

    AcGePoint3d         xLine1Point() const;
    Acad::ErrorStatus   setXLine1Point(const AcGePoint3d& val);

    AcGePoint3d         xLine2Point() const;
    Acad::ErrorStatus   setXLine2Point(const AcGePoint3d& val);

    AcGePoint3d         centerPoint() const;
    Acad::ErrorStatus   setCenterPoint(const AcGePoint3d& val);

    bool extArcOn() const;
    Acad::ErrorStatus setExtArcOn(bool value);

    static std::string className();
public:
    AcDb3PointAngularDimension* impObj() const;
};

//-----------------------------------------------------------------------------------
//AcDbAlignedDimension
void makeAlignedDimensionWrapper();

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

    AcGePoint3d         xLine1Point() const;
    Acad::ErrorStatus   setXLine1Point(const AcGePoint3d& val);

    AcGePoint3d         xLine2Point() const;
    Acad::ErrorStatus   setXLine2Point(const AcGePoint3d& val);

    AcGePoint3d         dimLinePoint() const;
    Acad::ErrorStatus   setDimLinePoint(const AcGePoint3d& val);

    double              oblique() const;
    Acad::ErrorStatus   setOblique(double val);

    bool jogSymbolOn() const;
    Acad::ErrorStatus setJogSymbolOn(bool value);

    AcGePoint3d jogSymbolPosition() const;
    Acad::ErrorStatus setJogSymbolPosition(const AcGePoint3d& pt);

    static std::string className();
public:
    AcDbAlignedDimension* impObj() const;
};

//-----------------------------------------------------------------------------------
//AcDbArcDimension
void makeArcDimensionWrapper();

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

    AcGePoint3d         arcPoint() const;
    Acad::ErrorStatus   setArcPoint(const AcGePoint3d& arcPt);

    AcGePoint3d         xLine1Point() const;
    Acad::ErrorStatus   setXLine1Point(const AcGePoint3d& xLine1Pt);

    AcGePoint3d         xLine2Point() const;
    Acad::ErrorStatus   setXLine2Point(const AcGePoint3d& xLine2Pt);

    AcGePoint3d         centerPoint() const;
    Acad::ErrorStatus   setCenterPoint(const AcGePoint3d& ctrPt);

    bool                isPartial() const;
    Acad::ErrorStatus   setIsPartial(bool partial);

    double              arcStartParam() const;
    Acad::ErrorStatus   setArcStartParam(double arcParam);

    double              arcEndParam() const;
    Acad::ErrorStatus   setArcEndParam(double arcParam);

    bool                hasLeader() const;
    Acad::ErrorStatus   setHasLeader(bool leaderVal);

    AcGePoint3d         leader1Point() const;
    Acad::ErrorStatus   setLeader1Point(const AcGePoint3d& ldr1Pt);

    AcGePoint3d         leader2Point() const;
    Acad::ErrorStatus   setLeader2Point(const AcGePoint3d& ldr2Pt);

    int                 arcSymbolType() const;
    Acad::ErrorStatus   setArcSymbolType(int symbol);


    static std::string className();
public:
    AcDbArcDimension* impObj() const;
};

//-----------------------------------------------------------------------------------
//AcDbDiametricDimension
void makeDiametricDimensionWrapper();

class PyDbDiametricDimension : public PyDbDimension
{
public:
    PyDbDiametricDimension();
    PyDbDiametricDimension(AcDbDiametricDimension* ptr, bool autoDelete);
    PyDbDiametricDimension(const PyDbObjectId& id, AcDb::OpenMode mode);

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
    Acad::ErrorStatus   setLeaderLength(double val);

    AcGePoint3d         chordPoint() const;
    Acad::ErrorStatus   setChordPoint(const AcGePoint3d& val);

    AcGePoint3d         farChordPoint() const;
    Acad::ErrorStatus   setFarChordPoint(const AcGePoint3d& val);

    double extArcStartAngle() const;
    Acad::ErrorStatus setExtArcStartAngle(double newAngle);

    double extArcEndAngle() const;
    Acad::ErrorStatus setExtArcEndAngle(double newAngle);

    static std::string className();
public:
    AcDbDiametricDimension* impObj() const;
};

//-----------------------------------------------------------------------------------
//AcDbOrdinateDimension
void makeOrdinateDimensionWrapper();

class PyDbOrdinateDimension : public PyDbDimension
{
public:
    PyDbOrdinateDimension();
    PyDbOrdinateDimension(AcDbOrdinateDimension* ptr, bool autoDelete);
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

    Acad::ErrorStatus   useXAxis();
    Acad::ErrorStatus   useYAxis();

    Acad::ErrorStatus   setUsingXAxis(bool value);
    Acad::ErrorStatus   setUsingYAxis(bool value);

    AcGePoint3d         origin() const;
    Acad::ErrorStatus   setOrigin(const AcGePoint3d& val);

    AcGePoint3d         definingPoint() const;
    Acad::ErrorStatus   setDefiningPoint(const AcGePoint3d& val);

    AcGePoint3d         leaderEndPoint() const;
    Acad::ErrorStatus   setLeaderEndPoint(const AcGePoint3d& val);

    static std::string className();
public:
    AcDbOrdinateDimension* impObj() const;
};


//-----------------------------------------------------------------------------------
//AcDbRadialDimension
void makeRadialDimensionWrapper();

class PyDbRadialDimension : public PyDbDimension
{
public:
    PyDbRadialDimension();
    PyDbRadialDimension(AcDbRadialDimension* ptr, bool autoDelete);
    PyDbRadialDimension(const PyDbObjectId& id, AcDb::OpenMode mode);
    static std::string className();
public:
    AcDbRadialDimension* impObj() const;
};

//-----------------------------------------------------------------------------------
//AcDbRadialDimensionLarge
void makeRadialDimensionLargeWrapper();

class PyDbRadialDimensionLarge : public PyDbDimension
{
public:
    PyDbRadialDimensionLarge();
    PyDbRadialDimensionLarge(AcDbRadialDimensionLarge* ptr, bool autoDelete);
    PyDbRadialDimensionLarge(const PyDbObjectId& id, AcDb::OpenMode mode);
    static std::string className();
public:
    AcDbRadialDimensionLarge* impObj() const;
};


//-----------------------------------------------------------------------------------
//AcDbRotatedDimension
void makeRotatedDimensionWrapper();

class PyDbRotatedDimension : public PyDbDimension
{
public:
    PyDbRotatedDimension();
    PyDbRotatedDimension(AcDbRotatedDimension* ptr, bool autoDelete);
    PyDbRotatedDimension(const PyDbObjectId& id, AcDb::OpenMode mode);
    static std::string className();
public:
    AcDbRotatedDimension* impObj() const;
};
