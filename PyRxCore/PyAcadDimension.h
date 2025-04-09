#pragma once
#include "PyAcadEntity.h"

//----------------------------------------------------------------------------------------
//PyAcadDimension
void makePyAcadDimensionWrapper();

class PyAcadDimension : public PyAcadEntity
{
public:
    PyAcadDimension() = default;
    PyAcadDimension(std::shared_ptr<PyIAcadDimensionImpl> ptr);
    virtual ~PyAcadDimension() override = default;

    AcGeVector3d                    normal() const;
    void                            setNormal(const AcGeVector3d& val) const;
    double                          rotation() const;
    void                            setRotation(double val) const;
    AcGePoint3d                     textPosition() const;
    void                            setTextPosition(const AcGePoint3d& val) const;
    double                          textRotation() const;
    void                            setTextRotation(double val) const;
    std::string                     textOverride() const;
    void                            setTextOverride(const std::string& val) const;
    std::string                     styleName() const;
    void                            setStyleName(const std::string& val) const;
    PyAcColor                       textColor() const;
    void                            setTextColor(PyAcColor val) const;
    std::string                     decimalSeparator() const;
    void                            setDecimalSeparator(const std::string& val) const;
    double                          textGap() const;
    void                            setTextGap(double val) const;
    std::string                     textPrefix() const;
    void                            setTextPrefix(const std::string& val) const;
    std::string                     textSuffix() const;
    void                            setTextSuffix(const std::string& val) const;
    double                          scaleFactor() const;
    void                            setScaleFactor(double val) const;
    PyAcDimVerticalJustification    verticalTextPosition() const;
    void                            setVerticalTextPosition(PyAcDimVerticalJustification val) const;
    PyAcDimPrecision                tolerancePrecision() const;
    void                            setTolerancePrecision(PyAcDimPrecision val) const;
    double                          toleranceHeightScale() const;
    void                            setToleranceHeightScale(double val) const;
    double                          toleranceLowerLimit() const;
    void                            setToleranceLowerLimit(double val) const;
    PyAcDimTextMovement             textMovement() const;
    void                            setTextMovement(PyAcDimTextMovement val) const;
    PyAcDimToleranceMethod          toleranceDisplay() const;
    void                            setToleranceDisplay(PyAcDimToleranceMethod val) const;
    PyAcDimToleranceJustify         toleranceJustification() const;
    void                            setToleranceJustification(PyAcDimToleranceJustify val) const;
    double                          toleranceUpperLimit() const;
    void                            setToleranceUpperLimit(double val) const;
    std::string                     textStyle() const;
    void                            setTextStyle(const std::string& val) const;
    double                          textHeight() const;
    void                            setTextHeight(double val) const;
    bool                            suppressLeadingZeros() const;
    void                            setSuppressLeadingZeros(bool val) const;
    bool                            suppressTrailingZeros() const;
    void                            setSuppressTrailingZeros(bool val) const;
    bool                            toleranceSuppressLeadingZeros() const;
    void                            setToleranceSuppressLeadingZeros(bool val) const;
    bool                            toleranceSuppressTrailingZeros() const;
    void                            setToleranceSuppressTrailingZeros(bool val) const;
    bool                            textFill() const;
    void                            setTextFill(bool val) const;
    PyAcColor                       textFillColor() const;
    void                            setTextFillColor(PyAcColor val) const;
    bool                            dimTxtDirection() const;
    void                            setDimTxtDirection(bool val) const;

    static PyAcadDimension cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadDimensionImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyAcadDimAligned
void makePyAcadDimAlignedWrapper();

class PyAcadDimAligned : public PyAcadDimension
{
public:
    PyAcadDimAligned() = default;
    PyAcadDimAligned(std::shared_ptr<PyIAcadDimAlignedImpl> ptr);
    virtual ~PyAcadDimAligned() override = default;

    AcGePoint3d             extLine1Point() const;
    void                    setExtLine1Point(const AcGePoint3d& val) const;
    AcGePoint3d             extLine2Point() const;
    void                    setExtLine2Point(const AcGePoint3d& val) const;
    bool                    altUnits() const;
    void                    setAltUnits(bool val) const;
    PyAcDimPrecision        altUnitsPrecision() const;
    void                    setAltUnitsPrecision(PyAcDimPrecision val) const;
    double                  altUnitsScale() const;
    void                    setAltUnitsScale(double val) const;
    double                  altRoundDistance() const;
    void                    setAltRoundDistance(double val) const;
    PyAcDimPrecision        altTolerancePrecision() const;
    void                    setAltTolerancePrecision(PyAcDimPrecision val) const;
    PyAcDimUnits            altUnitsFormat() const;
    void                    setAltUnitsFormat(PyAcDimUnits val) const;
    std::string             altTextPrefix() const;
    void                    setAltTextPrefix(const std::string& val) const;
    std::string             altTextSuffix() const;
    void                    setAltTextSuffix(const std::string& val) const;
    PyAcColor               dimensionLineColor() const;
    void                    setDimensionLineColor(PyAcColor val) const;
    PyAcColor               extensionLineColor() const;
    void                    setExtensionLineColor(PyAcColor val) const;
    PyAcDimPrecision        primaryUnitsPrecision() const;
    void                    setPrimaryUnitsPrecision(PyAcDimPrecision val) const;
    double                  dimensionLineExtend() const;
    void                    setDimensionLineExtend(double val) const;
    double                  extensionLineExtend() const;
    void                    setExtensionLineExtend(double val) const;
    PyAcDimFit              fit() const;
    void                    setFit(PyAcDimFit val) const;
    PyAcDimFractionType     fractionFormat() const;
    void                    setFractionFormat(PyAcDimFractionType val) const;
    PyAcDimHorizontalJustification     horizontalTextPosition() const;
    void                               setHorizontalTextPosition(PyAcDimHorizontalJustification val) const;
    double                  linearScaleFactor() const;
    void                    setLinearScaleFactor(double val) const;
    PyAcDimLUnits           unitsFormat() const;
    void                    setUnitsFormat(PyAcDimLUnits val) const;
    PyAcLineWeight          extensionLineWeight() const;
    void                    setExtensionLineWeight(PyAcLineWeight val) const;
    double                  roundDistance() const;
    void                    setRoundDistance(double val) const;
    bool                    dimLine1Suppress() const;
    void                    setDimLine1Suppress(bool val) const;
    bool                    dimLine2Suppress() const;
    void                    setDimLine2Suppress(bool val) const;
    bool                    extLine1Suppress() const;
    void                    setExtLine1Suppress(bool val) const;
    bool                    extLine2Suppress() const;
    void                    setExtLine2Suppress(bool val) const;
    bool                    dimLineInside() const;
    void                    setDimLineInside(bool val) const;
    bool                    textInsideAlign() const;
    void                    setTextInsideAlign(bool val) const;
    bool                    textInside() const;
    void                    setTextInside(bool val) const;
    bool                    forceLineInside() const;
    void                    setForceLineInside(bool val) const;
    bool                    textOutsideAlign() const;
    void                    setTextOutsideAlign(bool val) const;
    double                  extensionLineOffset() const;
    void                    setExtensionLineOffset(double val) const;
    bool                    altSuppressLeadingZeros() const;
    void                    setAltSuppressLeadingZeros(bool val) const;
    bool                    altSuppressTrailingZeros() const;
    void                    setAltSuppressTrailingZeros(bool val) const;
    bool                    altSuppressZeroFeet() const;
    void                    setAltSuppressZeroFeet(bool val) const;
    bool                    altSuppressZeroInches() const;
    void                    setAltSuppressZeroInches(bool val) const;
    bool                    altToleranceSuppressLeadingZeros() const;
    void                    setAltToleranceSuppressLeadingZeros(bool val) const;
    bool                    altToleranceSuppressTrailingZeros() const;
    void                    setAltToleranceSuppressTrailingZeros(bool val) const;
    bool                    altToleranceSuppressZeroFeet() const;
    void                    setAltToleranceSuppressZeroFeet(bool val) const;
    bool                    altToleranceSuppressZeroInches() const;
    void                    setAltToleranceSuppressZeroInches(bool val) const;
    bool                    suppressZeroFeet() const;
    void                    setSuppressZeroFeet(bool val) const;
    bool                    suppressZeroInches() const;
    void                    setSuppressZeroInches(bool val) const;
    bool                    toleranceSuppressZeroFeet() const;
    void                    setToleranceSuppressZeroFeet(bool val) const;
    bool                    toleranceSuppressZeroInches() const;
    void                    setToleranceSuppressZeroInches(bool val) const;
    PyAcLineWeight          dimensionLineWeight() const;
    void                    setDimensionLineWeight(PyAcLineWeight val) const;
    double                  arrowheadSize() const;
    void                    setArrowheadSize(double val) const;
    PyAcDimArrowheadType    arrowhead1Type() const;
    void                    setArrowhead1Type(PyAcDimArrowheadType val) const;
    PyAcDimArrowheadType    arrowhead2Type() const;
    void                    setArrowhead2Type(PyAcDimArrowheadType val) const;
    double                  measurement() const;
    std::string             arrowhead1Block() const;
    void                    setArrowhead1Block(const std::string& val) const;
    std::string             arrowhead2Block() const;
    void                    setArrowhead2Block(const std::string& val) const;
    std::string             dimensionLinetype() const;
    void                    setDimensionLinetype(const std::string& val) const;
    std::string             extLine1Linetype() const;
    void                    setExtLine1Linetype(const std::string& val) const;
    std::string             extLine2Linetype() const;
    void                    setExtLine2Linetype(const std::string& val) const;
    bool                    extLineFixedLenSuppress() const;
    void                    setExtLineFixedLenSuppress(bool val) const;
    double                  extLineFixedLen() const;
    void                    setExtLineFixedLen(double val) const;
    bool                    dimConstrForm() const;
    void                    setDimConstrForm(bool val) const;
    bool                    dimConstrReference() const;
    void                    setDimConstrReference(bool val) const;
    std::string             dimConstrName() const;
    void                    setDimConstrName(const std::string& val) const;
    std::string             dimConstrExpression() const;
    void                    setDimConstrExpression(const std::string& val) const;
    std::string             dimConstrValue() const;
    void                    setDimConstrValue(const std::string& val) const;
    std::string             dimConstrDesc() const;
    void                    setDimConstrDesc(const std::string& val) const;
    std::string             subUnitsSuffix() const;
    void                    setSubUnitsSuffix(const std::string& val) const;
    double                  subUnitsFactor() const;
    void                    setSubUnitsFactor(double val) const;
    std::string             altSubUnitsSuffix() const;
    void                    setAltSubUnitsSuffix(const std::string& val) const;
    double                  altSubUnitsFactor() const;
    void                    setAltSubUnitsFactor(double val) const;


    static PyAcadDimAligned cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadDimAlignedImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyAcadDimAngular
void makePyAcadDimAngularWrapper();

class PyAcadDimAngular : public PyAcadDimension
{
public:
    PyAcadDimAngular() = default;
    PyAcadDimAngular(std::shared_ptr<PyIAcadDimAngularImpl> ptr);
    virtual ~PyAcadDimAngular() override = default;

    AcGePoint3d             extLine1StartPoint() const;
    void                    setExtLine1StartPoint(const AcGePoint3d& val) const;
    AcGePoint3d             extLine1EndPoint() const;
    void                    setExtLine1EndPoint(const AcGePoint3d& val) const;
    AcGePoint3d             extLine2StartPoint() const;
    void                    setExtLine2StartPoint(const AcGePoint3d& val) const;
    AcGePoint3d             extLine2EndPoint() const;
    void                    setExtLine2EndPoint(const AcGePoint3d& val) const;
    PyAcAngleUnits          angleFormat() const;
    void                    setAngleFormat(PyAcAngleUnits val) const;
    PyAcColor               dimensionLineColor() const;
    void                    setDimensionLineColor(PyAcColor val) const;
    PyAcColor               extensionLineColor() const;
    void                    setExtensionLineColor(PyAcColor val) const;
    double                  extensionLineExtend() const;
    void                    setExtensionLineExtend(double val) const;
    PyAcDimFit              fit() const;
    void                    setFit(PyAcDimFit val) const;
    PyAcDimHorizontalJustification     horizontalTextPosition() const;
    void                               setHorizontalTextPosition(PyAcDimHorizontalJustification val) const;
    PyAcLineWeight          extensionLineWeight() const;
    void                    setExtensionLineWeight(PyAcLineWeight val) const;
    bool                    dimLine1Suppress() const;
    void                    setDimLine1Suppress(bool val) const;
    bool                    dimLine2Suppress() const;
    void                    setDimLine2Suppress(bool val) const;
    bool                    extLine1Suppress() const;
    void                    setExtLine1Suppress(bool val) const;
    bool                    extLine2Suppress() const;
    void                    setExtLine2Suppress(bool val) const;
    bool                    dimLineInside() const;
    void                    setDimLineInside(bool val) const;
    bool                    textInsideAlign() const;
    void                    setTextInsideAlign(bool val) const;
    bool                    textInside() const;
    void                    setTextInside(bool val) const;
    bool                    forceLineInside() const;
    void                    setForceLineInside(bool val) const;
    bool                    textOutsideAlign() const;
    void                    setTextOutsideAlign(bool val) const;
    PyAcDimPrecision        textPrecision() const;
    void                    setTextPrecision(PyAcDimPrecision val) const;
    double                  extensionLineOffset() const;
    void                    setExtensionLineOffset(double val) const;
    PyAcLineWeight          dimensionLineWeight() const;
    void                    setDimensionLineWeight(PyAcLineWeight val) const;
    double                  arrowheadSize() const;
    void                    setArrowheadSize(double val) const;
    PyAcDimArrowheadType    arrowhead1Type() const;
    void                    setArrowhead1Type(PyAcDimArrowheadType val) const;
    PyAcDimArrowheadType    arrowhead2Type() const;
    void                    setArrowhead2Type(PyAcDimArrowheadType val) const;
    double                  measurement() const;
    std::string             arrowhead1Block() const;
    void                    setArrowhead1Block(const std::string& val) const;
    std::string             arrowhead2Block() const;
    void                    setArrowhead2Block(const std::string& val) const;
    std::string             dimensionLinetype() const;
    void                    setDimensionLinetype(const std::string& val) const;
    std::string             extLine1Linetype() const;
    void                    setExtLine1Linetype(const std::string& val) const;
    std::string             extLine2Linetype() const;
    void                    setExtLine2Linetype(const std::string& val) const;
    bool                    extLineFixedLenSuppress() const;
    void                    setExtLineFixedLenSuppress(bool val) const;
    double                  extLineFixedLen() const;
    void                    setExtLineFixedLen(double val) const;
    bool                    dimConstrForm() const;
    void                    setDimConstrForm(bool val) const;
    bool                    dimConstrReference() const;
    void                    setDimConstrReference(bool val) const;
    std::string             dimConstrName() const;
    void                    setDimConstrName(const std::string& val) const;
    std::string             dimConstrExpression() const;
    void                    setDimConstrExpression(const std::string& val) const;
    std::string             dimConstrValue() const;
    void                    setDimConstrValue(const std::string& val) const;
    std::string             dimConstrDesc() const;
    void                    setDimConstrDesc(const std::string& val) const;

    static PyAcadDimAngular cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadDimAngularImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyAcadDimDiametric
void makePyAcadDimDiametricWrapper();

class PyAcadDimDiametric : public PyAcadDimension
{
public:
    PyAcadDimDiametric() = default;
    PyAcadDimDiametric(std::shared_ptr<PyIAcadDimDiametricImpl> ptr);
    virtual ~PyAcadDimDiametric() override = default;

    void                    setLeaderLength(double val) const;
    bool                    altUnits() const;
    void                    setAltUnits(bool val) const;
    PyAcDimPrecision        altUnitsPrecision() const;
    void                    setAltUnitsPrecision(PyAcDimPrecision val) const;
    double                  altUnitsScale() const;
    void                    setAltUnitsScale(double val) const;
    PyAcDimPrecision        altTolerancePrecision() const;
    void                    setAltTolerancePrecision(PyAcDimPrecision val) const;
    PyAcDimUnits            altUnitsFormat() const;
    void                    setAltUnitsFormat(PyAcDimUnits val) const;
    std::string             altTextPrefix() const;
    void                    setAltTextPrefix(const std::string& val) const;
    std::string             altTextSuffix() const;
    void                    setAltTextSuffix(const std::string& val) const;
    PyAcColor               dimensionLineColor() const;
    void                    setDimensionLineColor(PyAcColor val) const;
    PyAcDimPrecision        primaryUnitsPrecision() const;
    void                    setPrimaryUnitsPrecision(PyAcDimPrecision val) const;
    PyAcDimFractionType     fractionFormat() const;
    void                    setFractionFormat(PyAcDimFractionType val) const;
    PyAcDimFit              fit() const;
    void                    setFit(PyAcDimFit val) const;
    double                  linearScaleFactor() const;
    void                    setLinearScaleFactor(double val) const;
    PyAcDimLUnits           unitsFormat() const;
    void                    setUnitsFormat(PyAcDimLUnits val) const;
    double                  roundDistance() const;
    void                    setRoundDistance(double val) const;
    bool                    dimLine1Suppress() const;
    void                    setDimLine1Suppress(bool val) const;
    bool                    dimLine2Suppress() const;
    void                    setDimLine2Suppress(bool val) const;
    bool                    textInsideAlign() const;
    void                    setTextInsideAlign(bool val) const;
    bool                    textInside() const;
    void                    setTextInside(bool val) const;
    bool                    forceLineInside() const;
    void                    setForceLineInside(bool val) const;
    bool                    textOutsideAlign() const;
    void                    setTextOutsideAlign(bool val) const;
    PyAcDimCenterType       centerType() const;
    void                    setCenterType(PyAcDimCenterType val) const;
    double                  centerMarkSize() const;
    void                    setCenterMarkSize(double val) const;
    bool                    altSuppressLeadingZeros() const;
    void                    setAltSuppressLeadingZeros(bool val) const;
    bool                    altSuppressTrailingZeros() const;
    void                    setAltSuppressTrailingZeros(bool val) const;
    bool                    altSuppressZeroFeet() const;
    void                    setAltSuppressZeroFeet(bool val) const;
    bool                    altSuppressZeroInches() const;
    void                    setAltSuppressZeroInches(bool val) const;
    bool                    altToleranceSuppressLeadingZeros() const;
    void                    setAltToleranceSuppressLeadingZeros(bool val) const;
    bool                    altToleranceSuppressTrailingZeros() const;
    void                    setAltToleranceSuppressTrailingZeros(bool val) const;
    bool                    altToleranceSuppressZeroFeet() const;
    void                    setAltToleranceSuppressZeroFeet(bool val) const;
    bool                    altToleranceSuppressZeroInches() const;
    void                    setAltToleranceSuppressZeroInches(bool val) const;
    bool                    suppressZeroFeet() const;
    void                    setSuppressZeroFeet(bool val) const;
    bool                    suppressZeroInches() const;
    void                    setSuppressZeroInches(bool val) const;
    bool                    toleranceSuppressZeroFeet() const;
    void                    setToleranceSuppressZeroFeet(bool val) const;
    bool                    toleranceSuppressZeroInches() const;
    void                    setToleranceSuppressZeroInches(bool val) const;
    PyAcLineWeight          dimensionLineWeight() const;
    void                    setDimensionLineWeight(PyAcLineWeight val) const;
    double                  arrowheadSize() const;
    void                    setArrowheadSize(double val) const;
    PyAcDimArrowheadType    arrowhead1Type() const;
    void                    setArrowhead1Type(PyAcDimArrowheadType val) const;
    PyAcDimArrowheadType    arrowhead2Type() const;
    void                    setArrowhead2Type(PyAcDimArrowheadType val) const;
    double                  measurement() const;
    std::string             arrowhead1Block() const;
    void                    setArrowhead1Block(const std::string& val) const;
    std::string             arrowhead2Block() const;
    void                    setArrowhead2Block(const std::string& val) const;
    std::string             dimensionLinetype() const;
    void                    setDimensionLinetype(const std::string& val) const;
    bool                    dimConstrForm() const;
    void                    setDimConstrForm(bool val) const;
    bool                    dimConstrReference() const;
    void                    setDimConstrReference(bool val) const;
    std::string             dimConstrName() const;
    void                    setDimConstrName(const std::string& val) const;
    std::string             dimConstrExpression() const;
    void                    setDimConstrExpression(const std::string& val) const;
    std::string             dimConstrValue() const;
    void                    setDimConstrValue(const std::string& val) const;
    std::string             dimConstrDesc() const;
    void                    setDimConstrDesc(const std::string& val) const;

    static PyAcadDimDiametric cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadDimDiametricImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyAcadDimRotated
void makePyAcadDimRotatedWrapper();

class PyAcadDimRotated : public PyAcadDimension
{
public:
    PyAcadDimRotated() = default;
    PyAcadDimRotated(std::shared_ptr<PyIAcadDimRotatedImpl> ptr);
    virtual ~PyAcadDimRotated() override = default;
    static PyAcadDimRotated cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadDimRotatedImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyAcadDimOrdinate
void makePyAcadDimOrdinateWrapper();

class PyAcadDimOrdinate : public PyAcadDimension
{
public:
    PyAcadDimOrdinate() = default;
    PyAcadDimOrdinate(std::shared_ptr<PyIAcadDimOrdinateImpl> ptr);
    virtual ~PyAcadDimOrdinate() override = default;
    static PyAcadDimOrdinate cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadDimOrdinateImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyAcadDimRadial
void makePyAcadDimRadialWrapper();

class PyAcadDimRadial : public PyAcadDimension
{
public:
    PyAcadDimRadial() = default;
    PyAcadDimRadial(std::shared_ptr<PyIAcadDimRadialImpl> ptr);
    virtual ~PyAcadDimRadial() override = default;
    static PyAcadDimRadial cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadDimRadialImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyAcadDim3PointAngular
void makePyAcadDim3PointAngularWrapper();

class PyAcadDim3PointAngular : public PyAcadDimension
{
public:
    PyAcadDim3PointAngular() = default;
    PyAcadDim3PointAngular(std::shared_ptr<PyIAcadDim3PointAngularImpl> ptr);
    virtual ~PyAcadDim3PointAngular() override = default;
    static PyAcadDim3PointAngular cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadDim3PointAngularImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyAcadDimArcLength
void makePyAcadDimArcLengthWrapper();

class PyAcadDimArcLength : public PyAcadDimension
{
public:
    PyAcadDimArcLength() = default;
    PyAcadDimArcLength(std::shared_ptr<PyIAcadDimArcLengthImpl> ptr);
    virtual ~PyAcadDimArcLength() override = default;
    static PyAcadDimArcLength cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadDimArcLengthImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyAcadDimRadialLarge
void makePyAcadDimRadialLargeWrapper();

class PyAcadDimRadialLarge : public PyAcadDimension
{
public:
    PyAcadDimRadialLarge() = default;
    PyAcadDimRadialLarge(std::shared_ptr<PyIAcadDimRadialLargeImpl> ptr);
    virtual ~PyAcadDimRadialLarge() override = default;
    static PyAcadDimRadialLarge cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadDimRadialLargeImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};