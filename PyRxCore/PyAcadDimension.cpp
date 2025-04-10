#include "stdafx.h"
#include "PyAcadDimension.h"
#include "PyAcadDimensionImpl.h"
#include "PyAcadEntityImpl.h"
#include "PyAcadObjectImpl.h"

using namespace boost::python;

//----------------------------------------------------------------------------------------
//PyAcadDimension
void makePyAcadDimensionWrapper()
{
    PyDocString DS("AcadDimension");
    class_<PyAcadDimension, bases<PyAcadEntity>>("AcadDimension", boost::python::no_init)
        .def("normal", &PyAcadDimension::normal, DS.ARGS())
        .def("setNormal", &PyAcadDimension::setNormal, DS.ARGS({ "val:PyGe.Vector3d" }))
        .def("rotation", &PyAcadDimension::rotation, DS.ARGS())
        .def("setRotation", &PyAcadDimension::setRotation, DS.ARGS({ "val:float" }))
        .def("textPosition", &PyAcadDimension::textPosition, DS.ARGS())
        .def("setTextPosition", &PyAcadDimension::setTextPosition, DS.ARGS({ "val:PyGe.Point3d" }))
        .def("textRotation", &PyAcadDimension::textRotation, DS.ARGS())
        .def("setTextRotation", &PyAcadDimension::setTextRotation, DS.ARGS({ "val:float" }))
        .def("textOverride", &PyAcadDimension::textOverride, DS.ARGS())
        .def("setTextOverride", &PyAcadDimension::setTextOverride, DS.ARGS({ "val:str" }))
        .def("styleName", &PyAcadDimension::styleName, DS.ARGS())
        .def("setStyleName", &PyAcadDimension::setStyleName, DS.ARGS({ "val:str" }))
        .def("textColor", &PyAcadDimension::textColor, DS.ARGS())
        .def("setTextColor", &PyAcadDimension::setTextColor, DS.ARGS({ "val:PyAx.AcColor" }))
        .def("decimalSeparator", &PyAcadDimension::decimalSeparator, DS.ARGS())
        .def("setDecimalSeparator", &PyAcadDimension::setDecimalSeparator, DS.ARGS({ "val:str" }))
        .def("textGap", &PyAcadDimension::textGap, DS.ARGS())
        .def("setTextGap", &PyAcadDimension::setTextGap, DS.ARGS({ "val:float" }))
        .def("textPrefix", &PyAcadDimension::textPrefix, DS.ARGS())
        .def("setTextPrefix", &PyAcadDimension::setTextPrefix, DS.ARGS({ "val:str" }))
        .def("textSuffix", &PyAcadDimension::textSuffix, DS.ARGS())
        .def("setTextSuffix", &PyAcadDimension::setTextSuffix, DS.ARGS({ "val:str" }))
        .def("scaleFactor", &PyAcadDimension::scaleFactor, DS.ARGS())
        .def("setScaleFactor", &PyAcadDimension::setScaleFactor, DS.ARGS({ "val:float" }))
        .def("verticalTextPosition", &PyAcadDimension::verticalTextPosition, DS.ARGS())
        .def("setVerticalTextPosition", &PyAcadDimension::setVerticalTextPosition, DS.ARGS({ "val:PyAx.AcDimVerticalJustification" }))
        .def("tolerancePrecision", &PyAcadDimension::tolerancePrecision, DS.ARGS())
        .def("setTolerancePrecision", &PyAcadDimension::setTolerancePrecision, DS.ARGS({ "val:PyAx.AcDimPrecision" }))
        .def("toleranceHeightScale", &PyAcadDimension::toleranceHeightScale, DS.ARGS())
        .def("setToleranceHeightScale", &PyAcadDimension::setToleranceHeightScale, DS.ARGS({ "val:float" }))
        .def("toleranceLowerLimit", &PyAcadDimension::toleranceLowerLimit, DS.ARGS())
        .def("setToleranceLowerLimit", &PyAcadDimension::setToleranceLowerLimit, DS.ARGS({ "val:float" }))
        .def("textMovement", &PyAcadDimension::textMovement, DS.ARGS())
        .def("setTextMovement", &PyAcadDimension::setTextMovement, DS.ARGS({ "val:PyAx.AcDimTextMovement" }))
        .def("toleranceDisplay", &PyAcadDimension::toleranceDisplay, DS.ARGS())
        .def("setToleranceDisplay", &PyAcadDimension::setToleranceDisplay, DS.ARGS({ "val:PyAx.AcDimToleranceMethod" }))
        .def("toleranceJustification", &PyAcadDimension::toleranceJustification, DS.ARGS())
        .def("setToleranceJustification", &PyAcadDimension::setToleranceJustification, DS.ARGS({ "val:PyAx.AcDimToleranceJustify" }))
        .def("toleranceUpperLimit", &PyAcadDimension::toleranceUpperLimit, DS.ARGS())
        .def("setToleranceUpperLimit", &PyAcadDimension::setToleranceUpperLimit, DS.ARGS({ "val:float" }))
        .def("textStyle", &PyAcadDimension::textStyle, DS.ARGS())
        .def("setTextStyle", &PyAcadDimension::setTextStyle, DS.ARGS({ "val:str" }))
        .def("textHeight", &PyAcadDimension::textHeight, DS.ARGS())
        .def("setTextHeight", &PyAcadDimension::setTextHeight, DS.ARGS({ "val:float" }))
        .def("suppressLeadingZeros", &PyAcadDimension::suppressLeadingZeros, DS.ARGS())
        .def("setSuppressLeadingZeros", &PyAcadDimension::setSuppressLeadingZeros, DS.ARGS({ "val:bool" }))
        .def("suppressTrailingZeros", &PyAcadDimension::suppressTrailingZeros, DS.ARGS())
        .def("setSuppressTrailingZeros", &PyAcadDimension::setSuppressTrailingZeros, DS.ARGS({ "val:bool" }))
        .def("toleranceSuppressLeadingZeros", &PyAcadDimension::toleranceSuppressLeadingZeros, DS.ARGS())
        .def("setToleranceSuppressLeadingZeros", &PyAcadDimension::setToleranceSuppressLeadingZeros, DS.ARGS({ "val:bool" }))
        .def("toleranceSuppressTrailingZeros", &PyAcadDimension::toleranceSuppressTrailingZeros, DS.ARGS())
        .def("setToleranceSuppressTrailingZeros", &PyAcadDimension::setToleranceSuppressTrailingZeros, DS.ARGS({ "val:bool" }))
        .def("textFill", &PyAcadDimension::textFill, DS.ARGS())
        .def("setTextFill", &PyAcadDimension::setTextFill, DS.ARGS({ "val:bool" }))
        .def("textFillColor", &PyAcadDimension::textFillColor, DS.ARGS())
        .def("setTextFillColor", &PyAcadDimension::setTextFillColor, DS.ARGS({ "val:PyAx.AcColor" }))
        .def("dimTxtDirection", &PyAcadDimension::dimTxtDirection, DS.ARGS())
        .def("setDimTxtDirection", &PyAcadDimension::setDimTxtDirection, DS.ARGS({ "val:bool" }))
        .def("cast", &PyAcadDimension::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadDimension::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadDimension::PyAcadDimension(std::shared_ptr<PyIAcadDimensionImpl> ptr)
    : PyAcadEntity(ptr)
{
}

AcGeVector3d PyAcadDimension::normal() const
{
    return impObj()->GetNormal();
}

void PyAcadDimension::setNormal(const AcGeVector3d& val) const
{
    impObj()->SetNormal(val);
}

double PyAcadDimension::rotation() const
{
    return impObj()->GetRotation();
}

void PyAcadDimension::setRotation(double val) const
{
    impObj()->SetRotation(val);
}

AcGePoint3d PyAcadDimension::textPosition() const
{
    return impObj()->GetTextPosition();
}

void PyAcadDimension::setTextPosition(const AcGePoint3d& val) const
{
    impObj()->SetTextPosition(val);
}

double PyAcadDimension::textRotation() const
{
    return impObj()->GetTextRotation();
}

void PyAcadDimension::setTextRotation(double val) const
{
    impObj()->SetTextRotation(val);
}

std::string PyAcadDimension::textOverride() const
{
    return wstr_to_utf8(impObj()->GetTextOverride());
}

void PyAcadDimension::setTextOverride(const std::string& val) const
{
    impObj()->SetTextOverride(utf8_to_wstr(val).c_str());
}

std::string PyAcadDimension::styleName() const
{
    return wstr_to_utf8(impObj()->GetStyleName());
}

void PyAcadDimension::setStyleName(const std::string& val) const
{
    impObj()->SetStyleName(utf8_to_wstr(val).c_str());
}

PyAcColor PyAcadDimension::textColor() const
{
    return impObj()->GetTextColor();
}

void PyAcadDimension::setTextColor(PyAcColor val) const
{
    impObj()->SetTextColor(val);
}

std::string PyAcadDimension::decimalSeparator() const
{
    return wstr_to_utf8(impObj()->GetDecimalSeparator());
}

void PyAcadDimension::setDecimalSeparator(const std::string& val) const
{
    impObj()->SetDecimalSeparator(utf8_to_wstr(val).c_str());
}

double PyAcadDimension::textGap() const
{
    return impObj()->GetTextGap();
}

void PyAcadDimension::setTextGap(double val) const
{
    impObj()->SetTextGap(val);
}

std::string PyAcadDimension::textPrefix() const
{
    return wstr_to_utf8(impObj()->GetTextPrefix());
}

void PyAcadDimension::setTextPrefix(const std::string& val) const
{
    impObj()->SetTextPrefix(utf8_to_wstr(val).c_str());
}

std::string PyAcadDimension::textSuffix() const
{
    return wstr_to_utf8(impObj()->GetTextSuffix());
}

void PyAcadDimension::setTextSuffix(const std::string& val) const
{
    impObj()->SetTextSuffix(utf8_to_wstr(val).c_str());
}

double PyAcadDimension::scaleFactor() const
{
    return impObj()->GetScaleFactor();
}

void PyAcadDimension::setScaleFactor(double val) const
{
    impObj()->SetScaleFactor(val);
}

PyAcDimVerticalJustification PyAcadDimension::verticalTextPosition() const
{
    return impObj()->GetVerticalTextPosition();
}

void PyAcadDimension::setVerticalTextPosition(PyAcDimVerticalJustification val) const
{
    impObj()->SetVerticalTextPosition(val);
}

PyAcDimPrecision PyAcadDimension::tolerancePrecision() const
{
    return impObj()->GetTolerancePrecision();
}

void PyAcadDimension::setTolerancePrecision(PyAcDimPrecision val) const
{
    impObj()->SetTolerancePrecision(val);
}

double PyAcadDimension::toleranceHeightScale() const
{
    return impObj()->GetToleranceHeightScale();
}

void PyAcadDimension::setToleranceHeightScale(double val) const
{
    impObj()->SetToleranceHeightScale(val);
}

double PyAcadDimension::toleranceLowerLimit() const
{
    return impObj()->GetToleranceLowerLimit();
}

void PyAcadDimension::setToleranceLowerLimit(double val) const
{
    impObj()->SetToleranceLowerLimit(val);
}

PyAcDimTextMovement PyAcadDimension::textMovement() const
{
    return impObj()->GetTextMovement();
}

void PyAcadDimension::setTextMovement(PyAcDimTextMovement val) const
{
    impObj()->SetTextMovement(val);
}

PyAcDimToleranceMethod PyAcadDimension::toleranceDisplay() const
{
    return impObj()->GetToleranceDisplay();
}

void PyAcadDimension::setToleranceDisplay(PyAcDimToleranceMethod val) const
{
    impObj()->SetToleranceDisplay(val);
}

PyAcDimToleranceJustify PyAcadDimension::toleranceJustification() const
{
    return impObj()->GetToleranceJustification();
}

void PyAcadDimension::setToleranceJustification(PyAcDimToleranceJustify val) const
{
    impObj()->SetToleranceJustification(val);
}

double PyAcadDimension::toleranceUpperLimit() const
{
    return impObj()->GetToleranceUpperLimit();
}

void PyAcadDimension::setToleranceUpperLimit(double val) const
{
    impObj()->SetToleranceUpperLimit(val);
}

std::string PyAcadDimension::textStyle() const
{
    return wstr_to_utf8(impObj()->GetTextStyle());
}

void PyAcadDimension::setTextStyle(const std::string& val) const
{
    impObj()->SetTextStyle(utf8_to_wstr(val).c_str());
}

double PyAcadDimension::textHeight() const
{
    return impObj()->GetTextHeight();
}

void PyAcadDimension::setTextHeight(double val) const
{
    impObj()->SetTextHeight(val);
}

bool PyAcadDimension::suppressLeadingZeros() const
{
    return impObj()->GetSuppressLeadingZeros();
}

void PyAcadDimension::setSuppressLeadingZeros(bool val) const
{
    impObj()->SetSuppressLeadingZeros(val);
}

bool PyAcadDimension::suppressTrailingZeros() const
{
    return impObj()->GetSuppressTrailingZeros();
}

void PyAcadDimension::setSuppressTrailingZeros(bool val) const
{
    impObj()->SetSuppressTrailingZeros(val);
}

bool PyAcadDimension::toleranceSuppressLeadingZeros() const
{
    return impObj()->GetToleranceSuppressLeadingZeros();
}

void PyAcadDimension::setToleranceSuppressLeadingZeros(bool val) const
{
    impObj()->SetToleranceSuppressLeadingZeros(val);
}

bool PyAcadDimension::toleranceSuppressTrailingZeros() const
{
    return impObj()->GetToleranceSuppressTrailingZeros();
}

void PyAcadDimension::setToleranceSuppressTrailingZeros(bool val) const
{
    impObj()->SetToleranceSuppressTrailingZeros(val);
}

bool PyAcadDimension::textFill() const
{
    return impObj()->GetTextFill();
}

void PyAcadDimension::setTextFill(bool val) const
{
    impObj()->SetTextFill(val);
}

PyAcColor PyAcadDimension::textFillColor() const
{
    return impObj()->GetTextFillColor();
}

void PyAcadDimension::setTextFillColor(PyAcColor val) const
{
    impObj()->SetTextFillColor(val);
}

bool PyAcadDimension::dimTxtDirection() const
{
    return impObj()->GetDimTxtDirection();
}

void PyAcadDimension::setDimTxtDirection(bool val) const
{
    impObj()->SetDimTxtDirection(val);
}

PyAcadDimension PyAcadDimension::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadDimension>(src);
}

std::string PyAcadDimension::className()
{
    return "AcadDimension";
}

PyIAcadDimensionImpl* PyAcadDimension::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadDimensionImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadDimAligned
void makePyAcadDimAlignedWrapper()
{
    PyDocString DS("AcadDimAligned");
    class_<PyAcadDimAligned, bases<PyAcadDimension>>("AcadDimAligned", boost::python::no_init)
        .def("extLine1Point", &PyAcadDimAligned::extLine1Point, DS.ARGS())
        .def("setExtLine1Point", &PyAcadDimAligned::setExtLine1Point, DS.ARGS({ "val: PyGe.Point3d" }))
        .def("extLine2Point", &PyAcadDimAligned::extLine2Point, DS.ARGS())
        .def("setExtLine2Point", &PyAcadDimAligned::setExtLine2Point, DS.ARGS({ "val: PyGe.Point3d" }))
        .def("altUnits", &PyAcadDimAligned::altUnits, DS.ARGS())
        .def("setAltUnits", &PyAcadDimAligned::setAltUnits, DS.ARGS({ "val: bool" }))
        .def("altUnitsPrecision", &PyAcadDimAligned::altUnitsPrecision, DS.ARGS())
        .def("setAltUnitsPrecision", &PyAcadDimAligned::setAltUnitsPrecision, DS.ARGS({ "val: PyAx.AcDimPrecision" }))
        .def("altUnitsFormat", &PyAcadDimAligned::altUnitsFormat, DS.ARGS())
        .def("setAltUnitsFormat", &PyAcadDimAligned::setAltUnitsFormat, DS.ARGS({ "val: PyAx.AcDimUnits" }))
        .def("altTextPrefix", &PyAcadDimAligned::altTextPrefix, DS.ARGS())
        .def("setAltTextPrefix", &PyAcadDimAligned::setAltTextPrefix, DS.ARGS({ "val: str" }))
        .def("altTextSuffix", &PyAcadDimAligned::altTextSuffix, DS.ARGS())
        .def("setAltTextSuffix", &PyAcadDimAligned::setAltTextSuffix, DS.ARGS({ "val: str" }))
        .def("dimensionLineColor", &PyAcadDimAligned::dimensionLineColor, DS.ARGS())
        .def("setDimensionLineColor", &PyAcadDimAligned::setDimensionLineColor, DS.ARGS({ "val: PyAx.AcColor" }))
        .def("extensionLineColor", &PyAcadDimAligned::extensionLineColor, DS.ARGS())
        .def("setExtensionLineColor", &PyAcadDimAligned::setExtensionLineColor, DS.ARGS({ "val: PyAx.AcColor" }))
        .def("primaryUnitsPrecision", &PyAcadDimAligned::primaryUnitsPrecision, DS.ARGS())
        .def("setPrimaryUnitsPrecision", &PyAcadDimAligned::setPrimaryUnitsPrecision, DS.ARGS({ "val: PyAx.AcDimPrecision" }))
        .def("dimensionLineExtend", &PyAcadDimAligned::dimensionLineExtend, DS.ARGS())
        .def("setDimensionLineExtend", &PyAcadDimAligned::setDimensionLineExtend, DS.ARGS({ "val: float" }))
        .def("extensionLineExtend", &PyAcadDimAligned::extensionLineExtend, DS.ARGS())
        .def("setExtensionLineExtend", &PyAcadDimAligned::setExtensionLineExtend, DS.ARGS({ "val: float" }))
        .def("fit", &PyAcadDimAligned::fit, DS.ARGS())
        .def("setFit", &PyAcadDimAligned::setFit, DS.ARGS({ "val: PyAx.AcDimFit" }))
        .def("fractionFormat", &PyAcadDimAligned::fractionFormat, DS.ARGS())
        .def("setFractionFormat", &PyAcadDimAligned::setFractionFormat, DS.ARGS({ "val: PyAx.AcDimFractionType" }))
        .def("horizontalTextPosition", &PyAcadDimAligned::horizontalTextPosition, DS.ARGS())
        .def("setHorizontalTextPosition", &PyAcadDimAligned::setHorizontalTextPosition, DS.ARGS({ "val: PyAx.AcDimHorizontalJustification" }))
        .def("linearScaleFactor", &PyAcadDimAligned::linearScaleFactor, DS.ARGS())
        .def("setLinearScaleFactor", &PyAcadDimAligned::setLinearScaleFactor, DS.ARGS({ "val: float" }))
        .def("unitsFormat", &PyAcadDimAligned::unitsFormat, DS.ARGS())
        .def("setUnitsFormat", &PyAcadDimAligned::setUnitsFormat, DS.ARGS({ "val: PyAx.AcDimLUnits" }))
        .def("extensionLineWeight", &PyAcadDimAligned::extensionLineWeight, DS.ARGS())
        .def("setExtensionLineWeight", &PyAcadDimAligned::setExtensionLineWeight, DS.ARGS({ "val: PyAx.AcLineWeight" }))
        .def("roundDistance", &PyAcadDimAligned::roundDistance, DS.ARGS())
        .def("setRoundDistance", &PyAcadDimAligned::setRoundDistance, DS.ARGS({ "val: float" }))
        .def("dimLine1Suppress", &PyAcadDimAligned::dimLine1Suppress, DS.ARGS())
        .def("setDimLine1Suppress", &PyAcadDimAligned::setDimLine1Suppress, DS.ARGS({ "val: bool" }))
        .def("dimLine2Suppress", &PyAcadDimAligned::dimLine2Suppress, DS.ARGS())
        .def("setDimLine2Suppress", &PyAcadDimAligned::setDimLine2Suppress, DS.ARGS({ "val: bool" }))
        .def("extLine1Suppress", &PyAcadDimAligned::extLine1Suppress, DS.ARGS())
        .def("setExtLine1Suppress", &PyAcadDimAligned::setExtLine1Suppress, DS.ARGS({ "val: bool" }))
        .def("extLine2Suppress", &PyAcadDimAligned::extLine2Suppress, DS.ARGS())
        .def("setExtLine2Suppress", &PyAcadDimAligned::setExtLine2Suppress, DS.ARGS({ "val: bool" }))
        .def("dimLineInside", &PyAcadDimAligned::dimLineInside, DS.ARGS())
        .def("setDimLineInside", &PyAcadDimAligned::setDimLineInside, DS.ARGS({ "val: bool" }))
        .def("textInsideAlign", &PyAcadDimAligned::textInsideAlign, DS.ARGS())
        .def("setTextInsideAlign", &PyAcadDimAligned::setTextInsideAlign, DS.ARGS({ "val: bool" }))
        .def("textInside", &PyAcadDimAligned::textInside, DS.ARGS())
        .def("setTextInside", &PyAcadDimAligned::setTextInside, DS.ARGS({ "val: bool" }))
        .def("forceLineInside", &PyAcadDimAligned::forceLineInside, DS.ARGS())
        .def("setForceLineInside", &PyAcadDimAligned::setForceLineInside, DS.ARGS({ "val: bool" }))
        .def("textOutsideAlign", &PyAcadDimAligned::textOutsideAlign, DS.ARGS())
        .def("setTextOutsideAlign", &PyAcadDimAligned::setTextOutsideAlign, DS.ARGS({ "val: bool" }))
        .def("extensionLineOffset", &PyAcadDimAligned::extensionLineOffset, DS.ARGS())
        .def("setExtensionLineOffset", &PyAcadDimAligned::setExtensionLineOffset, DS.ARGS({ "val: float" }))
        .def("altSuppressLeadingZeros", &PyAcadDimAligned::altSuppressLeadingZeros, DS.ARGS())
        .def("setAltSuppressLeadingZeros", &PyAcadDimAligned::setAltSuppressLeadingZeros, DS.ARGS({ "val: bool" }))
        .def("altSuppressTrailingZeros", &PyAcadDimAligned::altSuppressTrailingZeros, DS.ARGS())
        .def("setAltSuppressTrailingZeros", &PyAcadDimAligned::setAltSuppressTrailingZeros, DS.ARGS({ "val: bool" }))
        .def("altSuppressZeroFeet", &PyAcadDimAligned::altSuppressZeroFeet, DS.ARGS())
        .def("setAltSuppressZeroFeet", &PyAcadDimAligned::setAltSuppressZeroFeet, DS.ARGS({ "val: bool" }))
        .def("altSuppressZeroInches", &PyAcadDimAligned::altSuppressZeroInches, DS.ARGS())
        .def("setAltSuppressZeroInches", &PyAcadDimAligned::setAltSuppressZeroInches, DS.ARGS({ "val: bool" }))
        .def("altToleranceSuppressLeadingZeros", &PyAcadDimAligned::altToleranceSuppressLeadingZeros, DS.ARGS())
        .def("setAltToleranceSuppressLeadingZeros", &PyAcadDimAligned::setAltToleranceSuppressLeadingZeros, DS.ARGS({ "val: bool" }))
        .def("altToleranceSuppressTrailingZeros", &PyAcadDimAligned::altToleranceSuppressTrailingZeros, DS.ARGS())
        .def("setAltToleranceSuppressTrailingZeros", &PyAcadDimAligned::setAltToleranceSuppressTrailingZeros, DS.ARGS({ "val: bool" }))
        .def("altToleranceSuppressZeroFeet", &PyAcadDimAligned::altToleranceSuppressZeroFeet, DS.ARGS())
        .def("setAltToleranceSuppressZeroFeet", &PyAcadDimAligned::setAltToleranceSuppressZeroFeet, DS.ARGS({ "val: bool" }))
        .def("altToleranceSuppressZeroInches", &PyAcadDimAligned::altToleranceSuppressZeroInches, DS.ARGS())
        .def("setAltToleranceSuppressZeroInches", &PyAcadDimAligned::setAltToleranceSuppressZeroInches, DS.ARGS({ "val: bool" }))
        .def("suppressZeroFeet", &PyAcadDimAligned::suppressZeroFeet, DS.ARGS())
        .def("setSuppressZeroFeet", &PyAcadDimAligned::setSuppressZeroFeet, DS.ARGS({ "val: bool" }))
        .def("suppressZeroInches", &PyAcadDimAligned::suppressZeroInches, DS.ARGS())
        .def("setSuppressZeroInches", &PyAcadDimAligned::setSuppressZeroInches, DS.ARGS({ "val: bool" }))
        .def("toleranceSuppressZeroFeet", &PyAcadDimAligned::toleranceSuppressZeroFeet, DS.ARGS())
        .def("setToleranceSuppressZeroFeet", &PyAcadDimAligned::setToleranceSuppressZeroFeet, DS.ARGS({ "val: bool" }))
        .def("toleranceSuppressZeroInches", &PyAcadDimAligned::toleranceSuppressZeroInches, DS.ARGS())
        .def("setToleranceSuppressZeroInches", &PyAcadDimAligned::setToleranceSuppressZeroInches, DS.ARGS({ "val: bool" }))
        .def("dimensionLineWeight", &PyAcadDimAligned::dimensionLineWeight, DS.ARGS())
        .def("setDimensionLineWeight", &PyAcadDimAligned::setDimensionLineWeight, DS.ARGS({ "val: PyAx.AcLineWeight" }))
        .def("arrowheadSize", &PyAcadDimAligned::arrowheadSize, DS.ARGS())
        .def("setArrowheadSize", &PyAcadDimAligned::setArrowheadSize, DS.ARGS({ "val: float" }))
        .def("arrowhead1Type", &PyAcadDimAligned::arrowhead1Type, DS.ARGS())
        .def("setArrowhead1Type", &PyAcadDimAligned::setArrowhead1Type, DS.ARGS({ "val: PyAx.AcDimArrowheadType" }))
        .def("arrowhead2Type", &PyAcadDimAligned::arrowhead2Type, DS.ARGS())
        .def("setArrowhead2Type", &PyAcadDimAligned::setArrowhead2Type, DS.ARGS({ "val: PyAx.AcDimArrowheadType" }))
        .def("measurement", &PyAcadDimAligned::measurement, DS.ARGS())
        .def("arrowhead1Block", &PyAcadDimAligned::arrowhead1Block, DS.ARGS())
        .def("setArrowhead1Block", &PyAcadDimAligned::setArrowhead1Block, DS.ARGS({ "val: str" }))
        .def("arrowhead2Block", &PyAcadDimAligned::arrowhead2Block, DS.ARGS())
        .def("setArrowhead2Block", &PyAcadDimAligned::setArrowhead2Block, DS.ARGS({ "val: str" }))
        .def("dimensionLinetype", &PyAcadDimAligned::dimensionLinetype, DS.ARGS())
        .def("setDimensionLinetype", &PyAcadDimAligned::setDimensionLinetype, DS.ARGS({ "val: str" }))
        .def("extLine1Linetype", &PyAcadDimAligned::extLine1Linetype, DS.ARGS())
        .def("setExtLine1Linetype", &PyAcadDimAligned::setExtLine1Linetype, DS.ARGS({ "val: str" }))
        .def("extLine2Linetype", &PyAcadDimAligned::extLine2Linetype, DS.ARGS())
        .def("setExtLine2Linetype", &PyAcadDimAligned::setExtLine2Linetype, DS.ARGS({ "val: str" }))
        .def("extLineFixedLenSuppress", &PyAcadDimAligned::extLineFixedLenSuppress, DS.ARGS())
        .def("setExtLineFixedLenSuppress", &PyAcadDimAligned::setExtLineFixedLenSuppress, DS.ARGS({ "val: bool" }))
        .def("extLineFixedLen", &PyAcadDimAligned::extLineFixedLen, DS.ARGS())
        .def("setExtLineFixedLen", &PyAcadDimAligned::setExtLineFixedLen, DS.ARGS({ "val: bool" }))
        .def("dimConstrForm", &PyAcadDimAligned::dimConstrForm, DS.ARGS())
        .def("setDimConstrForm", &PyAcadDimAligned::setDimConstrForm, DS.ARGS({ "val: bool" }))
        .def("dimConstrReference", &PyAcadDimAligned::dimConstrReference, DS.ARGS())
        .def("setDimConstrReference", &PyAcadDimAligned::setDimConstrReference, DS.ARGS({ "val: bool" }))
        .def("dimConstrName", &PyAcadDimAligned::dimConstrName, DS.ARGS())
        .def("setDimConstrName", &PyAcadDimAligned::setDimConstrName, DS.ARGS({ "val: str" }))
        .def("dimConstrExpression", &PyAcadDimAligned::dimConstrExpression, DS.ARGS())
        .def("setDimConstrExpression", &PyAcadDimAligned::setDimConstrExpression, DS.ARGS({ "val: str" }))
        .def("dimConstrValue", &PyAcadDimAligned::dimConstrValue, DS.ARGS())
        .def("setDimConstrValue", &PyAcadDimAligned::setDimConstrValue, DS.ARGS({ "val: str" }))
        .def("dimConstrDesc", &PyAcadDimAligned::dimConstrDesc, DS.ARGS())
        .def("setDimConstrDesc", &PyAcadDimAligned::setDimConstrDesc, DS.ARGS({ "val: str" }))
        .def("subUnitsSuffix", &PyAcadDimAligned::subUnitsSuffix, DS.ARGS())
        .def("setSubUnitsSuffix", &PyAcadDimAligned::setSubUnitsSuffix, DS.ARGS({ "val: str" }))
        .def("subUnitsFactor", &PyAcadDimAligned::subUnitsFactor, DS.ARGS())
        .def("setSubUnitsFactor", &PyAcadDimAligned::setSubUnitsFactor, DS.ARGS({ "val: float" }))
        .def("altSubUnitsSuffix", &PyAcadDimAligned::altSubUnitsSuffix, DS.ARGS())
        .def("setAltSubUnitsSuffix", &PyAcadDimAligned::setAltSubUnitsSuffix, DS.ARGS({ "val: str" }))
        .def("altSubUnitsFactor", &PyAcadDimAligned::altSubUnitsFactor, DS.ARGS())
        .def("setAltSubUnitsFactor", &PyAcadDimAligned::setAltSubUnitsFactor, DS.ARGS({ "val: float" }))
        .def("cast", &PyAcadDimAligned::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadDimAligned::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadDimAligned::PyAcadDimAligned(std::shared_ptr<PyIAcadDimAlignedImpl> ptr)
    : PyAcadDimension(ptr)
{
}

AcGePoint3d PyAcadDimAligned::extLine1Point() const
{
    return impObj()->GetExtLine1Point();
}

void PyAcadDimAligned::setExtLine1Point(const AcGePoint3d& val) const
{
    impObj()->SetExtLine1Point(val);
}

AcGePoint3d PyAcadDimAligned::extLine2Point() const
{
    return impObj()->GetExtLine2Point();
}

void PyAcadDimAligned::setExtLine2Point(const AcGePoint3d& val) const
{
    impObj()->SetExtLine2Point(val);
}

bool PyAcadDimAligned::altUnits() const
{
    return impObj()->GetAltUnits();
}

void PyAcadDimAligned::setAltUnits(bool val) const
{
    impObj()->SetAltUnits(val);
}

PyAcDimPrecision PyAcadDimAligned::altUnitsPrecision() const
{
    return impObj()->GetAltUnitsPrecision();
}

void PyAcadDimAligned::setAltUnitsPrecision(PyAcDimPrecision val) const
{
    impObj()->SetAltUnitsPrecision(val);
}

double PyAcadDimAligned::altUnitsScale() const
{
    return impObj()->GetAltUnitsScale();
}

void PyAcadDimAligned::setAltUnitsScale(double val) const
{
    impObj()->SetAltUnitsScale(val);
}

double PyAcadDimAligned::altRoundDistance() const
{
    return impObj()->GetAltRoundDistance();
}

void PyAcadDimAligned::setAltRoundDistance(double val) const
{
    impObj()->SetAltRoundDistance(val);
}

PyAcDimPrecision PyAcadDimAligned::altTolerancePrecision() const
{
    return impObj()->GetAltTolerancePrecision();
}

void PyAcadDimAligned::setAltTolerancePrecision(PyAcDimPrecision val) const
{
    impObj()->SetAltTolerancePrecision(val);
}

PyAcDimUnits PyAcadDimAligned::altUnitsFormat() const
{
    return impObj()->GetAltUnitsFormat();
}

void PyAcadDimAligned::setAltUnitsFormat(PyAcDimUnits val) const
{
    impObj()->SetAltUnitsFormat(val);
}

std::string PyAcadDimAligned::altTextPrefix() const
{
    return wstr_to_utf8(impObj()->GetAltTextPrefix());
}

void PyAcadDimAligned::setAltTextPrefix(const std::string& val) const
{
    impObj()->SetAltTextPrefix(utf8_to_wstr(val).c_str());
}

std::string PyAcadDimAligned::altTextSuffix() const
{
    return wstr_to_utf8(impObj()->GetAltTextSuffix());
}

void PyAcadDimAligned::setAltTextSuffix(const std::string& val) const
{
    impObj()->SetAltTextSuffix(utf8_to_wstr(val).c_str());
}

PyAcColor PyAcadDimAligned::dimensionLineColor() const
{
    return impObj()->GetDimensionLineColor();
}

void PyAcadDimAligned::setDimensionLineColor(PyAcColor val) const
{
    impObj()->SetDimensionLineColor(val);
}

PyAcColor PyAcadDimAligned::extensionLineColor() const
{
    return impObj()->GetExtensionLineColor();
}

void PyAcadDimAligned::setExtensionLineColor(PyAcColor val) const
{
    impObj()->SetExtensionLineColor(val);
}

PyAcDimPrecision PyAcadDimAligned::primaryUnitsPrecision() const
{
    return impObj()->GetPrimaryUnitsPrecision();
}

void PyAcadDimAligned::setPrimaryUnitsPrecision(PyAcDimPrecision val) const
{
    impObj()->SetPrimaryUnitsPrecision(val);
}

double PyAcadDimAligned::dimensionLineExtend() const
{
    return impObj()->GetDimensionLineExtend();
}

void PyAcadDimAligned::setDimensionLineExtend(double val) const
{
    impObj()->SetDimensionLineExtend(val);
}

double PyAcadDimAligned::extensionLineExtend() const
{
    return impObj()->GetExtensionLineExtend();
}

void PyAcadDimAligned::setExtensionLineExtend(double val) const
{
    impObj()->SetExtensionLineExtend(val);
}

PyAcDimFit PyAcadDimAligned::fit() const
{
    return impObj()->GetFit();
}

void PyAcadDimAligned::setFit(PyAcDimFit val) const
{
    impObj()->SetFit(val);
}

PyAcDimFractionType PyAcadDimAligned::fractionFormat() const
{
    return impObj()->GetFractionFormat();
}

void PyAcadDimAligned::setFractionFormat(PyAcDimFractionType val) const
{
    impObj()->SetFractionFormat(val);
}

PyAcDimHorizontalJustification PyAcadDimAligned::horizontalTextPosition() const
{
    return impObj()->GetHorizontalTextPosition();
}

void PyAcadDimAligned::setHorizontalTextPosition(PyAcDimHorizontalJustification val) const
{
    impObj()->SetHorizontalTextPosition(val);
}

double PyAcadDimAligned::linearScaleFactor() const
{
    return impObj()->GetLinearScaleFactor();
}

void PyAcadDimAligned::setLinearScaleFactor(double val) const
{
    impObj()->SetLinearScaleFactor(val);
}

PyAcDimLUnits PyAcadDimAligned::unitsFormat() const
{
    return impObj()->GetUnitsFormat();
}

void PyAcadDimAligned::setUnitsFormat(PyAcDimLUnits val) const
{
    impObj()->SetUnitsFormat(val);
}

PyAcLineWeight PyAcadDimAligned::extensionLineWeight() const
{
    return impObj()->GetExtensionLineWeight();
}

void PyAcadDimAligned::setExtensionLineWeight(PyAcLineWeight val) const
{
    impObj()->SetExtensionLineWeight(val);
}

double PyAcadDimAligned::roundDistance() const
{
    return impObj()->GetRoundDistance();
}

void PyAcadDimAligned::setRoundDistance(double val) const
{
    impObj()->SetRoundDistance(val);
}

bool PyAcadDimAligned::dimLine1Suppress() const
{
    return impObj()->GetDimLine1Suppress();
}

void PyAcadDimAligned::setDimLine1Suppress(bool val) const
{
    impObj()->SetDimLine1Suppress(val);
}

bool PyAcadDimAligned::dimLine2Suppress() const
{
    return impObj()->GetDimLine2Suppress();
}

void PyAcadDimAligned::setDimLine2Suppress(bool val) const
{
    impObj()->SetDimLine2Suppress(val);
}

bool PyAcadDimAligned::extLine1Suppress() const
{
    return impObj()->GetExtLine1Suppress();
}

void PyAcadDimAligned::setExtLine1Suppress(bool val) const
{
    impObj()->SetExtLine1Suppress(val);
}

bool PyAcadDimAligned::extLine2Suppress() const
{
    return impObj()->GetExtLine2Suppress();
}

void PyAcadDimAligned::setExtLine2Suppress(bool val) const
{
    impObj()->SetExtLine2Suppress(val);
}

bool PyAcadDimAligned::dimLineInside() const
{
    return impObj()->GetDimLineInside();
}

void PyAcadDimAligned::setDimLineInside(bool val) const
{
    impObj()->SetDimLineInside(val);
}

bool PyAcadDimAligned::textInsideAlign() const
{
    return impObj()->GetTextInsideAlign();
}

void PyAcadDimAligned::setTextInsideAlign(bool val) const
{
    impObj()->SetTextInsideAlign(val);
}

bool PyAcadDimAligned::textInside() const
{
    return impObj()->GetTextInside();
}

void PyAcadDimAligned::setTextInside(bool val) const
{
    impObj()->SetTextInside(val);
}

bool PyAcadDimAligned::forceLineInside() const
{
    return impObj()->GetForceLineInside();
}

void PyAcadDimAligned::setForceLineInside(bool val) const
{
    impObj()->SetForceLineInside(val);
}

bool PyAcadDimAligned::textOutsideAlign() const
{
    return impObj()->GetTextOutsideAlign();
}

void PyAcadDimAligned::setTextOutsideAlign(bool val) const
{
    impObj()->SetTextOutsideAlign(val);
}

double PyAcadDimAligned::extensionLineOffset() const
{
    return impObj()->GetExtensionLineOffset();
}

void PyAcadDimAligned::setExtensionLineOffset(double val) const
{
    impObj()->SetExtensionLineOffset(val);
}

bool PyAcadDimAligned::altSuppressLeadingZeros() const
{
    return impObj()->GetAltSuppressLeadingZeros();
}

void PyAcadDimAligned::setAltSuppressLeadingZeros(bool val) const
{
    impObj()->SetAltSuppressLeadingZeros(val);
}

bool PyAcadDimAligned::altSuppressTrailingZeros() const
{
    return impObj()->GetAltSuppressTrailingZeros();
}

void PyAcadDimAligned::setAltSuppressTrailingZeros(bool val) const
{
    impObj()->SetAltSuppressTrailingZeros(val);
}

bool PyAcadDimAligned::altSuppressZeroFeet() const
{
    return impObj()->GetAltSuppressZeroFeet();
}

void PyAcadDimAligned::setAltSuppressZeroFeet(bool val) const
{
    impObj()->SetAltSuppressZeroFeet(val);
}

bool PyAcadDimAligned::altSuppressZeroInches() const
{
    return impObj()->GetAltSuppressZeroInches();
}

void PyAcadDimAligned::setAltSuppressZeroInches(bool val) const
{
    impObj()->SetAltSuppressZeroInches(val);
}

bool PyAcadDimAligned::altToleranceSuppressLeadingZeros() const
{
    return impObj()->GetAltToleranceSuppressLeadingZeros();
}

void PyAcadDimAligned::setAltToleranceSuppressLeadingZeros(bool val) const
{
    impObj()->SetAltToleranceSuppressLeadingZeros(val);
}

bool PyAcadDimAligned::altToleranceSuppressTrailingZeros() const
{
    return impObj()->GetAltToleranceSuppressTrailingZeros();
}

void PyAcadDimAligned::setAltToleranceSuppressTrailingZeros(bool val) const
{
    impObj()->SetAltToleranceSuppressTrailingZeros(val);
}

bool PyAcadDimAligned::altToleranceSuppressZeroFeet() const
{
    return impObj()->GetAltToleranceSuppressZeroFeet();
}

void PyAcadDimAligned::setAltToleranceSuppressZeroFeet(bool val) const
{
    impObj()->SetAltToleranceSuppressZeroFeet(val);
}

bool PyAcadDimAligned::altToleranceSuppressZeroInches() const
{
    return impObj()->GetAltToleranceSuppressZeroInches();
}

void PyAcadDimAligned::setAltToleranceSuppressZeroInches(bool val) const
{
    impObj()->SetAltToleranceSuppressZeroInches(val);
}

bool PyAcadDimAligned::suppressZeroFeet() const
{
    return impObj()->GetSuppressZeroFeet();
}

void PyAcadDimAligned::setSuppressZeroFeet(bool val) const
{
    impObj()->SetSuppressZeroFeet(val);
}

bool PyAcadDimAligned::suppressZeroInches() const
{
    return impObj()->GetSuppressZeroInches();
}

void PyAcadDimAligned::setSuppressZeroInches(bool val) const
{
    impObj()->SetSuppressZeroInches(val);
}

bool PyAcadDimAligned::toleranceSuppressZeroFeet() const
{
    return impObj()->GetToleranceSuppressZeroFeet();
}

void PyAcadDimAligned::setToleranceSuppressZeroFeet(bool val) const
{
    impObj()->SetToleranceSuppressZeroFeet(val);
}

bool PyAcadDimAligned::toleranceSuppressZeroInches() const
{
    return impObj()->GetToleranceSuppressZeroInches();
}

void PyAcadDimAligned::setToleranceSuppressZeroInches(bool val) const
{
    impObj()->SetToleranceSuppressZeroInches(val);
}

PyAcLineWeight PyAcadDimAligned::dimensionLineWeight() const
{
    return impObj()->GetDimensionLineWeight();
}

void PyAcadDimAligned::setDimensionLineWeight(PyAcLineWeight val) const
{
    impObj()->SetDimensionLineWeight(val);
}

double PyAcadDimAligned::arrowheadSize() const
{
    return impObj()->GetArrowheadSize();
}

void PyAcadDimAligned::setArrowheadSize(double val) const
{
    impObj()->SetArrowheadSize(val);
}

PyAcDimArrowheadType PyAcadDimAligned::arrowhead1Type() const
{
    return impObj()->GetArrowhead1Type();
}

void PyAcadDimAligned::setArrowhead1Type(PyAcDimArrowheadType val) const
{
    impObj()->SetArrowhead1Type(val);
}

PyAcDimArrowheadType PyAcadDimAligned::arrowhead2Type() const
{
    return impObj()->GetArrowhead2Type();
}

void PyAcadDimAligned::setArrowhead2Type(PyAcDimArrowheadType val) const
{
    impObj()->SetArrowhead2Type(val);
}

double PyAcadDimAligned::measurement() const
{
    return impObj()->GetMeasurement();
}

std::string PyAcadDimAligned::arrowhead1Block() const
{
    return wstr_to_utf8(impObj()->GetArrowhead1Block());
}

void PyAcadDimAligned::setArrowhead1Block(const std::string& val) const
{
    impObj()->SetArrowhead1Block(utf8_to_wstr(val).c_str());
}

std::string PyAcadDimAligned::arrowhead2Block() const
{
    return wstr_to_utf8(impObj()->GetArrowhead2Block());
}

void PyAcadDimAligned::setArrowhead2Block(const std::string& val) const
{
    impObj()->SetArrowhead2Block(utf8_to_wstr(val).c_str());
}

std::string PyAcadDimAligned::dimensionLinetype() const
{
    return wstr_to_utf8(impObj()->GetDimensionLinetype());
}

void PyAcadDimAligned::setDimensionLinetype(const std::string& val) const
{
    impObj()->SetDimensionLinetype(utf8_to_wstr(val).c_str());
}

std::string PyAcadDimAligned::extLine1Linetype() const
{
    return wstr_to_utf8(impObj()->GetExtLine1Linetype());
}

void PyAcadDimAligned::setExtLine1Linetype(const std::string& val) const
{
    impObj()->SetExtLine1Linetype(utf8_to_wstr(val).c_str());
}

std::string PyAcadDimAligned::extLine2Linetype() const
{
    return wstr_to_utf8(impObj()->GetExtLine2Linetype());
}

void PyAcadDimAligned::setExtLine2Linetype(const std::string& val) const
{
    impObj()->SetExtLine2Linetype(utf8_to_wstr(val).c_str());
}

bool PyAcadDimAligned::extLineFixedLenSuppress() const
{
    return impObj()->GetExtLineFixedLenSuppress();
}

void PyAcadDimAligned::setExtLineFixedLenSuppress(bool val) const
{
    impObj()->SetExtLineFixedLenSuppress(val);
}

double PyAcadDimAligned::extLineFixedLen() const
{
    return impObj()->GetExtLineFixedLen();
}

void PyAcadDimAligned::setExtLineFixedLen(double val) const
{
    impObj()->SetExtLineFixedLen(val);
}

bool PyAcadDimAligned::dimConstrForm() const
{
    return impObj()->GetDimConstrForm();
}

void PyAcadDimAligned::setDimConstrForm(bool val) const
{
    impObj()->SetDimConstrForm(val);
}

bool PyAcadDimAligned::dimConstrReference() const
{
    return impObj()->GetDimConstrReference();
}

void PyAcadDimAligned::setDimConstrReference(bool val) const
{
    impObj()->SetDimConstrReference(val);
}

std::string PyAcadDimAligned::dimConstrName() const
{
    return wstr_to_utf8(impObj()->GetDimConstrName());
}

void PyAcadDimAligned::setDimConstrName(const std::string& val) const
{
    impObj()->SetDimConstrName(utf8_to_wstr(val).c_str());
}

std::string PyAcadDimAligned::dimConstrExpression() const
{
    return wstr_to_utf8(impObj()->GetDimConstrExpression());
}

void PyAcadDimAligned::setDimConstrExpression(const std::string& val) const
{
    impObj()->SetDimConstrExpression(utf8_to_wstr(val).c_str());
}

std::string PyAcadDimAligned::dimConstrValue() const
{
    return wstr_to_utf8(impObj()->GetDimConstrValue());
}

void PyAcadDimAligned::setDimConstrValue(const std::string& val) const
{
    impObj()->SetDimConstrValue(utf8_to_wstr(val).c_str());
}

std::string PyAcadDimAligned::dimConstrDesc() const
{
    return wstr_to_utf8(impObj()->GetDimConstrDesc());
}

void PyAcadDimAligned::setDimConstrDesc(const std::string& val) const
{
    impObj()->SetDimConstrDesc(utf8_to_wstr(val).c_str());
}

std::string PyAcadDimAligned::subUnitsSuffix() const
{
    return wstr_to_utf8(impObj()->GetSubUnitsSuffix());
}

void PyAcadDimAligned::setSubUnitsSuffix(const std::string& val) const
{
    impObj()->SetSubUnitsSuffix(utf8_to_wstr(val).c_str());
}

double PyAcadDimAligned::subUnitsFactor() const
{
    return impObj()->GetSubUnitsFactor();
}

void PyAcadDimAligned::setSubUnitsFactor(double val) const
{
    impObj()->SetSubUnitsFactor(val);
}

std::string PyAcadDimAligned::altSubUnitsSuffix() const
{
    return wstr_to_utf8(impObj()->GetAltSubUnitsSuffix());
}

void PyAcadDimAligned::setAltSubUnitsSuffix(const std::string& val) const
{
    impObj()->SetAltSubUnitsSuffix(utf8_to_wstr(val).c_str());
}

double PyAcadDimAligned::altSubUnitsFactor() const
{
    return impObj()->GetAltSubUnitsFactor();
}

void PyAcadDimAligned::setAltSubUnitsFactor(double val) const
{
    impObj()->SetAltSubUnitsFactor(val);
}

PyAcadDimAligned PyAcadDimAligned::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadDimAligned>(src);
}

std::string PyAcadDimAligned::className()
{
    return "AcadDimAligned";
}

PyIAcadDimAlignedImpl* PyAcadDimAligned::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadDimAlignedImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadDimAngular
void makePyAcadDimAngularWrapper()
{
    PyDocString DS("AcadDimAngular");
    class_<PyAcadDimAngular, bases<PyAcadDimension>>("AcadDimAngular", boost::python::no_init)
        .def("cast", &PyAcadDimAngular::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadDimAngular::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadDimAngular::PyAcadDimAngular(std::shared_ptr<PyIAcadDimAngularImpl> ptr)
    : PyAcadDimension(ptr)
{
}

AcGePoint3d PyAcadDimAngular::extLine1StartPoint() const
{
    return impObj()->GetExtLine1StartPoint();
}

void PyAcadDimAngular::setExtLine1StartPoint(const AcGePoint3d& val) const
{
    impObj()->SetExtLine1StartPoint(val);
}

AcGePoint3d PyAcadDimAngular::extLine1EndPoint() const
{
    return impObj()->GetExtLine1EndPoint();
}

void PyAcadDimAngular::setExtLine1EndPoint(const AcGePoint3d& val) const
{
    impObj()->SetExtLine1EndPoint(val);
}

AcGePoint3d PyAcadDimAngular::extLine2StartPoint() const
{
    return impObj()->GetExtLine2StartPoint();
}

void PyAcadDimAngular::setExtLine2StartPoint(const AcGePoint3d& val) const
{
    impObj()->SetExtLine2StartPoint(val);
}

AcGePoint3d PyAcadDimAngular::extLine2EndPoint() const
{
    return impObj()->GetExtLine2EndPoint();
}

void PyAcadDimAngular::setExtLine2EndPoint(const AcGePoint3d& val) const
{
    impObj()->SetExtLine2EndPoint(val);
}

PyAcAngleUnits PyAcadDimAngular::angleFormat() const
{
    return impObj()->GetAngleFormat();
}

void PyAcadDimAngular::setAngleFormat(PyAcAngleUnits val) const
{
    impObj()->SetAngleFormat(val);
}

PyAcColor PyAcadDimAngular::dimensionLineColor() const
{
    return impObj()->GetDimensionLineColor();
}

void PyAcadDimAngular::setDimensionLineColor(PyAcColor val) const
{
    impObj()->SetDimensionLineColor(val);
}

PyAcColor PyAcadDimAngular::extensionLineColor() const
{
    return impObj()->GetExtensionLineColor();
}

void PyAcadDimAngular::setExtensionLineColor(PyAcColor val) const
{
    impObj()->SetExtensionLineColor(val);
}

double PyAcadDimAngular::extensionLineExtend() const
{
    return impObj()->GetExtensionLineExtend();
}

void PyAcadDimAngular::setExtensionLineExtend(double val) const
{
    impObj()->SetExtensionLineExtend(val);
}

PyAcDimFit PyAcadDimAngular::fit() const
{
    return impObj()->GetFit();
}

void PyAcadDimAngular::setFit(PyAcDimFit val) const
{
    impObj()->SetFit(val);
}

PyAcDimHorizontalJustification PyAcadDimAngular::horizontalTextPosition() const
{
    return impObj()->GetHorizontalTextPosition();
}

void PyAcadDimAngular::setHorizontalTextPosition(PyAcDimHorizontalJustification val) const
{
    impObj()->SetHorizontalTextPosition(val);
}

PyAcLineWeight PyAcadDimAngular::extensionLineWeight() const
{
    return impObj()->GetExtensionLineWeight();
}

void PyAcadDimAngular::setExtensionLineWeight(PyAcLineWeight val) const
{
    impObj()->SetExtensionLineWeight(val);
}

bool PyAcadDimAngular::dimLine1Suppress() const
{
    return impObj()->GetDimLine1Suppress();
}

void PyAcadDimAngular::setDimLine1Suppress(bool val) const
{
    impObj()->SetDimLine1Suppress(val);
}

bool PyAcadDimAngular::dimLine2Suppress() const
{
    return impObj()->GetDimLine2Suppress();
}

void PyAcadDimAngular::setDimLine2Suppress(bool val) const
{
    impObj()->SetDimLine2Suppress(val);
}

bool PyAcadDimAngular::extLine1Suppress() const
{
    return impObj()->GetExtLine1Suppress();
}

void PyAcadDimAngular::setExtLine1Suppress(bool val) const
{
    impObj()->SetExtLine1Suppress(val);
}

bool PyAcadDimAngular::extLine2Suppress() const
{
    return impObj()->GetExtLine2Suppress();
}

void PyAcadDimAngular::setExtLine2Suppress(bool val) const
{
    impObj()->SetExtLine2Suppress(val);
}

bool PyAcadDimAngular::dimLineInside() const
{
    return impObj()->GetDimLineInside();
}

void PyAcadDimAngular::setDimLineInside(bool val) const
{
    impObj()->SetDimLineInside(val);
}

bool PyAcadDimAngular::textInsideAlign() const
{
    return impObj()->GetTextInsideAlign();
}

void PyAcadDimAngular::setTextInsideAlign(bool val) const
{
    impObj()->SetTextInsideAlign(val);
}

bool PyAcadDimAngular::textInside() const
{
    return impObj()->GetTextInside();
}

void PyAcadDimAngular::setTextInside(bool val) const
{
    impObj()->SetTextInside(val);
}

bool PyAcadDimAngular::forceLineInside() const
{
    return impObj()->GetForceLineInside();
}

void PyAcadDimAngular::setForceLineInside(bool val) const
{
    impObj()->SetForceLineInside(val);
}

bool PyAcadDimAngular::textOutsideAlign() const
{
    return impObj()->GetTextOutsideAlign();
}

void PyAcadDimAngular::setTextOutsideAlign(bool val) const
{
    impObj()->SetTextOutsideAlign(val);
}

PyAcDimPrecision PyAcadDimAngular::textPrecision() const
{
    return impObj()->GetTextPrecision();
}

void PyAcadDimAngular::setTextPrecision(PyAcDimPrecision val) const
{
    impObj()->SetTextPrecision(val);
}

double PyAcadDimAngular::extensionLineOffset() const
{
    return impObj()->GetExtensionLineOffset();
}

void PyAcadDimAngular::setExtensionLineOffset(double val) const
{
    impObj()->SetExtensionLineOffset(val);
}

PyAcLineWeight PyAcadDimAngular::dimensionLineWeight() const
{
    return impObj()->GetDimensionLineWeight();
}

void PyAcadDimAngular::setDimensionLineWeight(PyAcLineWeight val) const
{
    impObj()->SetDimensionLineWeight(val);
}

double PyAcadDimAngular::arrowheadSize() const
{
    return impObj()->GetArrowheadSize();
}

void PyAcadDimAngular::setArrowheadSize(double val) const
{
    impObj()->SetArrowheadSize(val);
}

PyAcDimArrowheadType PyAcadDimAngular::arrowhead1Type() const
{
    return impObj()->GetArrowhead1Type();
}

void PyAcadDimAngular::setArrowhead1Type(PyAcDimArrowheadType val) const
{
    impObj()->SetArrowhead1Type(val);
}

PyAcDimArrowheadType PyAcadDimAngular::arrowhead2Type() const
{
    return impObj()->GetArrowhead2Type();
}

void PyAcadDimAngular::setArrowhead2Type(PyAcDimArrowheadType val) const
{
    impObj()->SetArrowhead2Type(val);
}

double PyAcadDimAngular::measurement() const
{
    return impObj()->GetMeasurement();
}

std::string PyAcadDimAngular::arrowhead1Block() const
{
    return wstr_to_utf8(impObj()->GetArrowhead1Block());
}

void PyAcadDimAngular::setArrowhead1Block(const std::string& val) const
{
    impObj()->SetArrowhead1Block(utf8_to_wstr(val).c_str());
}

std::string PyAcadDimAngular::arrowhead2Block() const
{
    return wstr_to_utf8(impObj()->GetArrowhead2Block());
}

void PyAcadDimAngular::setArrowhead2Block(const std::string& val) const
{
    impObj()->SetArrowhead2Block(utf8_to_wstr(val).c_str());
}

std::string PyAcadDimAngular::dimensionLinetype() const
{
    return wstr_to_utf8(impObj()->GetDimensionLinetype());
}

void PyAcadDimAngular::setDimensionLinetype(const std::string& val) const
{
    impObj()->SetDimensionLinetype(utf8_to_wstr(val).c_str());
}

std::string PyAcadDimAngular::extLine1Linetype() const
{
    return wstr_to_utf8(impObj()->GetExtLine1Linetype());
}

void PyAcadDimAngular::setExtLine1Linetype(const std::string& val) const
{
    impObj()->SetExtLine1Linetype(utf8_to_wstr(val).c_str());
}

std::string PyAcadDimAngular::extLine2Linetype() const
{
    return wstr_to_utf8(impObj()->GetExtLine2Linetype());
}

void PyAcadDimAngular::setExtLine2Linetype(const std::string& val) const
{
    impObj()->SetExtLine2Linetype(utf8_to_wstr(val).c_str());
}

bool PyAcadDimAngular::extLineFixedLenSuppress() const
{
    return impObj()->GetExtLineFixedLenSuppress();
}

void PyAcadDimAngular::setExtLineFixedLenSuppress(bool val) const
{
    impObj()->SetExtLineFixedLenSuppress(val);
}

double PyAcadDimAngular::extLineFixedLen() const
{
    return impObj()->GetExtLineFixedLen();
}

void PyAcadDimAngular::setExtLineFixedLen(double val) const
{
    impObj()->SetExtLineFixedLen(val);
}

bool PyAcadDimAngular::dimConstrForm() const
{
    return impObj()->GetDimConstrForm();
}

void PyAcadDimAngular::setDimConstrForm(bool val) const
{
    impObj()->SetDimConstrForm(val);
}

bool PyAcadDimAngular::dimConstrReference() const
{
    return impObj()->GetDimConstrReference();
}

void PyAcadDimAngular::setDimConstrReference(bool val) const
{
    impObj()->SetDimConstrReference(val);
}

std::string PyAcadDimAngular::dimConstrName() const
{
    return wstr_to_utf8(impObj()->GetDimConstrName());
}

void PyAcadDimAngular::setDimConstrName(const std::string& val) const
{
    impObj()->SetDimConstrName(utf8_to_wstr(val).c_str());
}

std::string PyAcadDimAngular::dimConstrExpression() const
{
    return wstr_to_utf8(impObj()->GetDimConstrExpression());
}

void PyAcadDimAngular::setDimConstrExpression(const std::string& val) const
{
    impObj()->SetDimConstrExpression(utf8_to_wstr(val).c_str());
}

std::string PyAcadDimAngular::dimConstrValue() const
{
    return wstr_to_utf8(impObj()->GetDimConstrValue());
}

void PyAcadDimAngular::setDimConstrValue(const std::string& val) const
{
    impObj()->SetDimConstrValue(utf8_to_wstr(val).c_str());
}

std::string PyAcadDimAngular::dimConstrDesc() const
{
    return wstr_to_utf8(impObj()->GetDimConstrDesc());
}

void PyAcadDimAngular::setDimConstrDesc(const std::string& val) const
{
    impObj()->SetDimConstrDesc(utf8_to_wstr(val).c_str());
}

PyAcadDimAngular PyAcadDimAngular::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadDimAngular>(src);
}

std::string PyAcadDimAngular::className()
{
    return "AcadDimAngular";
}

PyIAcadDimAngularImpl* PyAcadDimAngular::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadDimAngularImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadDimDiametric
void makePyAcadDimDiametricWrapper()
{
    PyDocString DS("AcadDimDiametric");
    class_<PyAcadDimDiametric, bases<PyAcadDimension>>("AcadDimDiametric", boost::python::no_init)
        .def("cast", &PyAcadDimDiametric::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadDimDiametric::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadDimDiametric::PyAcadDimDiametric(std::shared_ptr<PyIAcadDimDiametricImpl> ptr)
    : PyAcadDimension(ptr)
{
}

void PyAcadDimDiametric::setLeaderLength(double val) const
{
    impObj()->SetLeaderLength(val);
}

bool PyAcadDimDiametric::altUnits() const
{
    return impObj()->GetAltUnits();
}

void PyAcadDimDiametric::setAltUnits(bool val) const
{
    impObj()->SetAltUnits(val);
}

PyAcDimPrecision PyAcadDimDiametric::altUnitsPrecision() const
{
    return impObj()->GetAltUnitsPrecision();
}

void PyAcadDimDiametric::setAltUnitsPrecision(PyAcDimPrecision val) const
{
    impObj()->SetAltUnitsPrecision(val);
}

double PyAcadDimDiametric::altUnitsScale() const
{
    return impObj()->GetAltUnitsScale();
}

void PyAcadDimDiametric::setAltUnitsScale(double val) const
{
    impObj()->SetAltUnitsScale(val);
}

PyAcDimPrecision PyAcadDimDiametric::altTolerancePrecision() const
{
    return impObj()->GetAltTolerancePrecision();
}

void PyAcadDimDiametric::setAltTolerancePrecision(PyAcDimPrecision val) const
{
    impObj()->SetAltTolerancePrecision(val);
}

PyAcDimUnits PyAcadDimDiametric::altUnitsFormat() const
{
    return impObj()->GetAltUnitsFormat();
}

void PyAcadDimDiametric::setAltUnitsFormat(PyAcDimUnits val) const
{
    impObj()->SetAltUnitsFormat(val);
}

std::string PyAcadDimDiametric::altTextPrefix() const
{
    return wstr_to_utf8(impObj()->GetAltTextPrefix());
}

void PyAcadDimDiametric::setAltTextPrefix(const std::string& val) const
{
    impObj()->SetAltTextPrefix(utf8_to_wstr(val).c_str());
}

std::string PyAcadDimDiametric::altTextSuffix() const
{
    return wstr_to_utf8(impObj()->GetAltTextSuffix());
}

void PyAcadDimDiametric::setAltTextSuffix(const std::string& val) const
{
    impObj()->SetAltTextSuffix(utf8_to_wstr(val).c_str());
}

PyAcColor PyAcadDimDiametric::dimensionLineColor() const
{
    return impObj()->GetDimensionLineColor();
}

void PyAcadDimDiametric::setDimensionLineColor(PyAcColor val) const
{
    impObj()->SetDimensionLineColor(val);
}

PyAcDimPrecision PyAcadDimDiametric::primaryUnitsPrecision() const
{
    return impObj()->GetPrimaryUnitsPrecision();
}

void PyAcadDimDiametric::setPrimaryUnitsPrecision(PyAcDimPrecision val) const
{
    impObj()->SetPrimaryUnitsPrecision(val);
}

PyAcDimFractionType PyAcadDimDiametric::fractionFormat() const
{
    return impObj()->GetFractionFormat();
}

void PyAcadDimDiametric::setFractionFormat(PyAcDimFractionType val) const
{
    impObj()->SetFractionFormat(val);
}

PyAcDimFit PyAcadDimDiametric::fit() const
{
    return impObj()->GetFit();
}

void PyAcadDimDiametric::setFit(PyAcDimFit val) const
{
    impObj()->SetFit(val);
}

double PyAcadDimDiametric::linearScaleFactor() const
{
    return impObj()->GetLinearScaleFactor();
}

void PyAcadDimDiametric::setLinearScaleFactor(double val) const
{
    impObj()->SetLinearScaleFactor(val);
}

PyAcDimLUnits PyAcadDimDiametric::unitsFormat() const
{
    return impObj()->GetUnitsFormat();
}

void PyAcadDimDiametric::setUnitsFormat(PyAcDimLUnits val) const
{
    impObj()->SetUnitsFormat(val);
}

double PyAcadDimDiametric::roundDistance() const
{
    return impObj()->GetRoundDistance();
}

void PyAcadDimDiametric::setRoundDistance(double val) const
{
    impObj()->SetRoundDistance(val);
}

bool PyAcadDimDiametric::dimLine1Suppress() const
{
    return impObj()->GetDimLine1Suppress();
}

void PyAcadDimDiametric::setDimLine1Suppress(bool val) const
{
    impObj()->SetDimLine1Suppress(val);
}

bool PyAcadDimDiametric::dimLine2Suppress() const
{
    return impObj()->GetDimLine2Suppress();
}

void PyAcadDimDiametric::setDimLine2Suppress(bool val) const
{
    impObj()->SetDimLine2Suppress(val);
}

bool PyAcadDimDiametric::textInsideAlign() const
{
    return impObj()->GetTextInsideAlign();
}

void PyAcadDimDiametric::setTextInsideAlign(bool val) const
{
    impObj()->SetTextInsideAlign(val);
}

bool PyAcadDimDiametric::textInside() const
{
    return impObj()->GetTextInside();
}

void PyAcadDimDiametric::setTextInside(bool val) const
{
    impObj()->SetTextInside(val);
}

bool PyAcadDimDiametric::forceLineInside() const
{
    return impObj()->GetForceLineInside();
}

void PyAcadDimDiametric::setForceLineInside(bool val) const
{
    impObj()->SetForceLineInside(val);
}

bool PyAcadDimDiametric::textOutsideAlign() const
{
    return impObj()->GetTextOutsideAlign();
}

void PyAcadDimDiametric::setTextOutsideAlign(bool val) const
{
    impObj()->SetTextOutsideAlign(val);
}

PyAcDimCenterType PyAcadDimDiametric::centerType() const
{
    return impObj()->GetCenterType();
}

void PyAcadDimDiametric::setCenterType(PyAcDimCenterType val) const
{
    impObj()->SetCenterType(val);
}

double PyAcadDimDiametric::centerMarkSize() const
{
    return impObj()->GetCenterMarkSize();
}

void PyAcadDimDiametric::setCenterMarkSize(double val) const
{
    impObj()->SetCenterMarkSize(val);
}

bool PyAcadDimDiametric::altSuppressLeadingZeros() const
{
    return impObj()->GetAltSuppressLeadingZeros();
}

void PyAcadDimDiametric::setAltSuppressLeadingZeros(bool val) const
{
    impObj()->SetAltSuppressLeadingZeros(val);
}

bool PyAcadDimDiametric::altSuppressTrailingZeros() const
{
    return impObj()->GetAltSuppressTrailingZeros();
}

void PyAcadDimDiametric::setAltSuppressTrailingZeros(bool val) const
{
    impObj()->SetAltSuppressTrailingZeros(val);
}

bool PyAcadDimDiametric::altSuppressZeroFeet() const
{
    return impObj()->GetAltSuppressZeroFeet();
}

void PyAcadDimDiametric::setAltSuppressZeroFeet(bool val) const
{
    impObj()->SetAltSuppressZeroFeet(val);
}

bool PyAcadDimDiametric::altSuppressZeroInches() const
{
    return impObj()->GetAltSuppressZeroInches();
}

void PyAcadDimDiametric::setAltSuppressZeroInches(bool val) const
{
    impObj()->SetAltSuppressZeroInches(val);
}

bool PyAcadDimDiametric::altToleranceSuppressLeadingZeros() const
{
    return impObj()->GetAltToleranceSuppressLeadingZeros();
}

void PyAcadDimDiametric::setAltToleranceSuppressLeadingZeros(bool val) const
{
    impObj()->SetAltToleranceSuppressLeadingZeros(val);
}

bool PyAcadDimDiametric::altToleranceSuppressTrailingZeros() const
{
    return impObj()->GetAltToleranceSuppressTrailingZeros();
}

void PyAcadDimDiametric::setAltToleranceSuppressTrailingZeros(bool val) const
{
    impObj()->SetAltToleranceSuppressTrailingZeros(val);
}

bool PyAcadDimDiametric::altToleranceSuppressZeroFeet() const
{
    return impObj()->GetAltToleranceSuppressZeroFeet();
}

void PyAcadDimDiametric::setAltToleranceSuppressZeroFeet(bool val) const
{
    impObj()->SetAltToleranceSuppressZeroFeet(val);
}

bool PyAcadDimDiametric::altToleranceSuppressZeroInches() const
{
    return impObj()->GetAltToleranceSuppressZeroInches();
}

void PyAcadDimDiametric::setAltToleranceSuppressZeroInches(bool val) const
{
    impObj()->SetAltToleranceSuppressZeroInches(val);
}

bool PyAcadDimDiametric::suppressZeroFeet() const
{
    return impObj()->GetSuppressZeroFeet();
}

void PyAcadDimDiametric::setSuppressZeroFeet(bool val) const
{
    impObj()->SetSuppressZeroFeet(val);
}

bool PyAcadDimDiametric::suppressZeroInches() const
{
    return impObj()->GetSuppressZeroInches();
}

void PyAcadDimDiametric::setSuppressZeroInches(bool val) const
{
    impObj()->SetSuppressZeroInches(val);
}

bool PyAcadDimDiametric::toleranceSuppressZeroFeet() const
{
    return impObj()->GetToleranceSuppressZeroFeet();
}

void PyAcadDimDiametric::setToleranceSuppressZeroFeet(bool val) const
{
    impObj()->SetToleranceSuppressZeroFeet(val);
}

bool PyAcadDimDiametric::toleranceSuppressZeroInches() const
{
    return impObj()->GetToleranceSuppressZeroInches();
}

void PyAcadDimDiametric::setToleranceSuppressZeroInches(bool val) const
{
    impObj()->SetToleranceSuppressZeroInches(val);
}

PyAcLineWeight PyAcadDimDiametric::dimensionLineWeight() const
{
    return impObj()->GetDimensionLineWeight();
}

void PyAcadDimDiametric::setDimensionLineWeight(PyAcLineWeight val) const
{
    impObj()->SetDimensionLineWeight(val);
}

double PyAcadDimDiametric::arrowheadSize() const
{
    return impObj()->GetArrowheadSize();
}

void PyAcadDimDiametric::setArrowheadSize(double val) const
{
    impObj()->SetArrowheadSize(val);
}

PyAcDimArrowheadType PyAcadDimDiametric::arrowhead1Type() const
{
    return impObj()->GetArrowhead1Type();
}

void PyAcadDimDiametric::setArrowhead1Type(PyAcDimArrowheadType val) const
{
    impObj()->SetArrowhead1Type(val);
}

PyAcDimArrowheadType PyAcadDimDiametric::arrowhead2Type() const
{
    return impObj()->GetArrowhead2Type();
}

void PyAcadDimDiametric::setArrowhead2Type(PyAcDimArrowheadType val) const
{
    impObj()->SetArrowhead2Type(val);
}

double PyAcadDimDiametric::measurement() const
{
    return impObj()->GetMeasurement();
}

std::string PyAcadDimDiametric::arrowhead1Block() const
{
    return wstr_to_utf8(impObj()->GetArrowhead1Block());
}

void PyAcadDimDiametric::setArrowhead1Block(const std::string& val) const
{
    impObj()->SetArrowhead1Block(utf8_to_wstr(val).c_str());
}

std::string PyAcadDimDiametric::arrowhead2Block() const
{
    return wstr_to_utf8(impObj()->GetArrowhead2Block());
}

void PyAcadDimDiametric::setArrowhead2Block(const std::string& val) const
{
    impObj()->SetArrowhead2Block(utf8_to_wstr(val).c_str());
}

std::string PyAcadDimDiametric::dimensionLinetype() const
{
    return wstr_to_utf8(impObj()->GetDimensionLinetype());
}

void PyAcadDimDiametric::setDimensionLinetype(const std::string& val) const
{
    impObj()->SetDimensionLinetype(utf8_to_wstr(val).c_str());
}

bool PyAcadDimDiametric::dimConstrForm() const
{
    return impObj()->GetDimConstrForm();
}

void PyAcadDimDiametric::setDimConstrForm(bool val) const
{
    impObj()->SetDimConstrForm(val);
}

bool PyAcadDimDiametric::dimConstrReference() const
{
    return impObj()->GetDimConstrReference();
}

void PyAcadDimDiametric::setDimConstrReference(bool val) const
{
    impObj()->SetDimConstrReference(val);
}

std::string PyAcadDimDiametric::dimConstrName() const
{
    return wstr_to_utf8(impObj()->GetDimConstrName());
}

void PyAcadDimDiametric::setDimConstrName(const std::string& val) const
{
    impObj()->SetDimConstrName(utf8_to_wstr(val).c_str());
}

std::string PyAcadDimDiametric::dimConstrExpression() const
{
    return wstr_to_utf8(impObj()->GetDimConstrExpression());
}

void PyAcadDimDiametric::setDimConstrExpression(const std::string& val) const
{
    impObj()->SetDimConstrExpression(utf8_to_wstr(val).c_str());
}

std::string PyAcadDimDiametric::dimConstrValue() const
{
    return wstr_to_utf8(impObj()->GetDimConstrValue());
}

void PyAcadDimDiametric::setDimConstrValue(const std::string& val) const
{
    impObj()->SetDimConstrValue(utf8_to_wstr(val).c_str());
}

std::string PyAcadDimDiametric::dimConstrDesc() const
{
    return wstr_to_utf8(impObj()->GetDimConstrDesc());
}

void PyAcadDimDiametric::setDimConstrDesc(const std::string& val) const
{
    impObj()->SetDimConstrDesc(utf8_to_wstr(val).c_str());
}

PyAcadDimDiametric PyAcadDimDiametric::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadDimDiametric>(src);
}

std::string PyAcadDimDiametric::className()
{
    return "AcadDimDiametric";
}

PyIAcadDimDiametricImpl* PyAcadDimDiametric::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadDimDiametricImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadDimRotated
void makePyAcadDimRotatedWrapper()
{
    PyDocString DS("AcadDimRotated");
    class_<PyAcadDimRotated, bases<PyAcadDimension>>("AcadDimRotated", boost::python::no_init)
        .def("cast", &PyAcadDimRotated::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadDimRotated::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadDimRotated::PyAcadDimRotated(std::shared_ptr<PyIAcadDimRotatedImpl> ptr)
    : PyAcadDimension(ptr)
{
}

bool PyAcadDimRotated::altUnits() const
{
    return impObj()->GetAltUnits();
}

void PyAcadDimRotated::setAltUnits(bool val) const
{
    impObj()->SetAltUnits(val);
}

PyAcDimPrecision PyAcadDimRotated::altUnitsPrecision() const
{
    return impObj()->GetAltUnitsPrecision();
}

void PyAcadDimRotated::setAltUnitsPrecision(PyAcDimPrecision val) const
{
    impObj()->SetAltUnitsPrecision(val);
}

double PyAcadDimRotated::altUnitsScale() const
{
    return impObj()->GetAltUnitsScale();
}

void PyAcadDimRotated::setAltUnitsScale(double val) const
{
    impObj()->SetAltUnitsScale(val);
}

double PyAcadDimRotated::altRoundDistance() const
{
    return impObj()->GetAltRoundDistance();
}

void PyAcadDimRotated::setAltRoundDistance(double val) const
{
    impObj()->SetAltRoundDistance(val);
}

PyAcDimPrecision PyAcadDimRotated::altTolerancePrecision() const
{
    return impObj()->GetAltTolerancePrecision();
}

void PyAcadDimRotated::setAltTolerancePrecision(PyAcDimPrecision val) const
{
    impObj()->SetAltTolerancePrecision(val);
}

PyAcDimUnits PyAcadDimRotated::altUnitsFormat() const
{
    return impObj()->GetAltUnitsFormat();
}

void PyAcadDimRotated::setAltUnitsFormat(PyAcDimUnits val) const
{
    impObj()->SetAltUnitsFormat(val);
}

std::string PyAcadDimRotated::altTextPrefix() const
{
    return wstr_to_utf8(impObj()->GetAltTextPrefix());
}

void PyAcadDimRotated::setAltTextPrefix(const std::string& val) const
{
    impObj()->SetAltTextPrefix(utf8_to_wstr(val).c_str());
}

std::string PyAcadDimRotated::altTextSuffix() const
{
    return wstr_to_utf8(impObj()->GetAltTextSuffix());
}

void PyAcadDimRotated::setAltTextSuffix(const std::string& val) const
{
    impObj()->SetAltTextSuffix(utf8_to_wstr(val).c_str());
}

PyAcColor PyAcadDimRotated::dimensionLineColor() const
{
    return impObj()->GetDimensionLineColor();
}

void PyAcadDimRotated::setDimensionLineColor(PyAcColor val) const
{
    impObj()->SetDimensionLineColor(val);
}

PyAcColor PyAcadDimRotated::extensionLineColor() const
{
    return impObj()->GetExtensionLineColor();
}

void PyAcadDimRotated::setExtensionLineColor(PyAcColor val) const
{
    impObj()->SetExtensionLineColor(val);
}

PyAcDimPrecision PyAcadDimRotated::primaryUnitsPrecision() const
{
    return impObj()->GetPrimaryUnitsPrecision();
}

void PyAcadDimRotated::setPrimaryUnitsPrecision(PyAcDimPrecision val) const
{
    impObj()->SetPrimaryUnitsPrecision(val);
}

double PyAcadDimRotated::dimensionLineExtend() const
{
    return impObj()->GetDimensionLineExtend();
}

void PyAcadDimRotated::setDimensionLineExtend(double val) const
{
    impObj()->SetDimensionLineExtend(val);
}

double PyAcadDimRotated::extensionLineExtend() const
{
    return impObj()->GetExtensionLineExtend();
}

void PyAcadDimRotated::setExtensionLineExtend(double val) const
{
    impObj()->SetExtensionLineExtend(val);
}

PyAcDimFit PyAcadDimRotated::fit() const
{
    return impObj()->GetFit();
}

void PyAcadDimRotated::setFit(PyAcDimFit val) const
{
    impObj()->SetFit(val);
}

PyAcDimFractionType PyAcadDimRotated::fractionFormat() const
{
    return impObj()->GetFractionFormat();
}

void PyAcadDimRotated::setFractionFormat(PyAcDimFractionType val) const
{
    impObj()->SetFractionFormat(val);
}

PyAcDimHorizontalJustification PyAcadDimRotated::horizontalTextPosition() const
{
    return impObj()->GetHorizontalTextPosition();
}

void PyAcadDimRotated::setHorizontalTextPosition(PyAcDimHorizontalJustification val) const
{
    impObj()->SetHorizontalTextPosition(val);
}

double PyAcadDimRotated::linearScaleFactor() const
{
    return impObj()->GetLinearScaleFactor();
}

void PyAcadDimRotated::setLinearScaleFactor(double val) const
{
    impObj()->SetLinearScaleFactor(val);
}

PyAcDimLUnits PyAcadDimRotated::unitsFormat() const
{
    return impObj()->GetUnitsFormat();
}

void PyAcadDimRotated::setUnitsFormat(PyAcDimLUnits val) const
{
    impObj()->SetUnitsFormat(val);
}

PyAcLineWeight PyAcadDimRotated::extensionLineWeight() const
{
    return impObj()->GetExtensionLineWeight();
}

void PyAcadDimRotated::setExtensionLineWeight(PyAcLineWeight val) const
{
    impObj()->SetExtensionLineWeight(val);
}

double PyAcadDimRotated::roundDistance() const
{
    return impObj()->GetRoundDistance();
}

void PyAcadDimRotated::setRoundDistance(double val) const
{
    impObj()->SetRoundDistance(val);
}

bool PyAcadDimRotated::dimLine1Suppress() const
{
    return impObj()->GetDimLine1Suppress();
}

void PyAcadDimRotated::setDimLine1Suppress(bool val) const
{
    impObj()->SetDimLine1Suppress(val);
}

bool PyAcadDimRotated::dimLine2Suppress() const
{
    return impObj()->GetDimLine2Suppress();
}

void PyAcadDimRotated::setDimLine2Suppress(bool val) const
{
    impObj()->SetDimLine2Suppress(val);
}

bool PyAcadDimRotated::extLine1Suppress() const
{
    return impObj()->GetExtLine1Suppress();
}

void PyAcadDimRotated::setExtLine1Suppress(bool val) const
{
    impObj()->SetExtLine1Suppress(val);
}

bool PyAcadDimRotated::extLine2Suppress() const
{
    return impObj()->GetExtLine2Suppress();
}

void PyAcadDimRotated::setExtLine2Suppress(bool val) const
{
    impObj()->SetExtLine2Suppress(val);
}

bool PyAcadDimRotated::dimLineInside() const
{
    return impObj()->GetDimLineInside();
}

void PyAcadDimRotated::setDimLineInside(bool val) const
{
    impObj()->SetDimLineInside(val);
}

bool PyAcadDimRotated::textInsideAlign() const
{
    return impObj()->GetTextInsideAlign();
}

void PyAcadDimRotated::setTextInsideAlign(bool val) const
{
    impObj()->SetTextInsideAlign(val);
}

bool PyAcadDimRotated::textInside() const
{
    return impObj()->GetTextInside();
}

void PyAcadDimRotated::setTextInside(bool val) const
{
    impObj()->SetTextInside(val);
}

bool PyAcadDimRotated::forceLineInside() const
{
    return impObj()->GetForceLineInside();
}

void PyAcadDimRotated::setForceLineInside(bool val) const
{
    impObj()->SetForceLineInside(val);
}

bool PyAcadDimRotated::textOutsideAlign() const
{
    return impObj()->GetTextOutsideAlign();
}

void PyAcadDimRotated::setTextOutsideAlign(bool val) const
{
    impObj()->SetTextOutsideAlign(val);
}

double PyAcadDimRotated::extensionLineOffset() const
{
    return impObj()->GetExtensionLineOffset();
}

void PyAcadDimRotated::setExtensionLineOffset(double val) const
{
    impObj()->SetExtensionLineOffset(val);
}

bool PyAcadDimRotated::altSuppressLeadingZeros() const
{
    return impObj()->GetAltSuppressLeadingZeros();
}

void PyAcadDimRotated::setAltSuppressLeadingZeros(bool val) const
{
    impObj()->SetAltSuppressLeadingZeros(val);
}

bool PyAcadDimRotated::altSuppressTrailingZeros() const
{
    return impObj()->GetAltSuppressTrailingZeros();
}

void PyAcadDimRotated::setAltSuppressTrailingZeros(bool val) const
{
    impObj()->SetAltSuppressTrailingZeros(val);
}

bool PyAcadDimRotated::altSuppressZeroFeet() const
{
    return impObj()->GetAltSuppressZeroFeet();
}

void PyAcadDimRotated::setAltSuppressZeroFeet(bool val) const
{
    impObj()->SetAltSuppressZeroFeet(val);
}

bool PyAcadDimRotated::altSuppressZeroInches() const
{
    return impObj()->GetAltSuppressZeroInches();
}

void PyAcadDimRotated::setAltSuppressZeroInches(bool val) const
{
    impObj()->SetAltSuppressZeroInches(val);
}

bool PyAcadDimRotated::altToleranceSuppressLeadingZeros() const
{
    return impObj()->GetAltToleranceSuppressLeadingZeros();
}

void PyAcadDimRotated::setAltToleranceSuppressLeadingZeros(bool val) const
{
    impObj()->SetAltToleranceSuppressLeadingZeros(val);
}

bool PyAcadDimRotated::altToleranceSuppressTrailingZeros() const
{
    return impObj()->GetAltToleranceSuppressTrailingZeros();
}

void PyAcadDimRotated::setAltToleranceSuppressTrailingZeros(bool val) const
{
    impObj()->SetAltToleranceSuppressTrailingZeros(val);
}

bool PyAcadDimRotated::altToleranceSuppressZeroFeet() const
{
    return impObj()->GetAltToleranceSuppressZeroFeet();
}

void PyAcadDimRotated::setAltToleranceSuppressZeroFeet(bool val) const
{
    impObj()->SetAltToleranceSuppressZeroFeet(val);
}

bool PyAcadDimRotated::altToleranceSuppressZeroInches() const
{
    return impObj()->GetAltToleranceSuppressZeroInches();
}

void PyAcadDimRotated::setAltToleranceSuppressZeroInches(bool val) const
{
    impObj()->SetAltToleranceSuppressZeroInches(val);
}

bool PyAcadDimRotated::suppressZeroFeet() const
{
    return impObj()->GetSuppressZeroFeet();
}

void PyAcadDimRotated::setSuppressZeroFeet(bool val) const
{
    impObj()->SetSuppressZeroFeet(val);
}

bool PyAcadDimRotated::suppressZeroInches() const
{
    return impObj()->GetSuppressZeroInches();
}

void PyAcadDimRotated::setSuppressZeroInches(bool val) const
{
    impObj()->SetSuppressZeroInches(val);
}

bool PyAcadDimRotated::toleranceSuppressZeroFeet() const
{
    return impObj()->GetToleranceSuppressZeroFeet();
}

void PyAcadDimRotated::setToleranceSuppressZeroFeet(bool val) const
{
    impObj()->SetToleranceSuppressZeroFeet(val);
}

bool PyAcadDimRotated::toleranceSuppressZeroInches() const
{
    return impObj()->GetToleranceSuppressZeroInches();
}

void PyAcadDimRotated::setToleranceSuppressZeroInches(bool val) const
{
    impObj()->SetToleranceSuppressZeroInches(val);
}

PyAcLineWeight PyAcadDimRotated::dimensionLineWeight() const
{
    return impObj()->GetDimensionLineWeight();
}

void PyAcadDimRotated::setDimensionLineWeight(PyAcLineWeight val) const
{
    impObj()->SetDimensionLineWeight(val);
}

double PyAcadDimRotated::arrowheadSize() const
{
    return impObj()->GetArrowheadSize();
}

void PyAcadDimRotated::setArrowheadSize(double val) const
{
    impObj()->SetArrowheadSize(val);
}

PyAcDimArrowheadType PyAcadDimRotated::arrowhead1Type() const
{
    return impObj()->GetArrowhead1Type();
}

void PyAcadDimRotated::setArrowhead1Type(PyAcDimArrowheadType val) const
{
    impObj()->SetArrowhead1Type(val);
}

PyAcDimArrowheadType PyAcadDimRotated::arrowhead2Type() const
{
    return impObj()->GetArrowhead2Type();
}

void PyAcadDimRotated::setArrowhead2Type(PyAcDimArrowheadType val) const
{
    impObj()->SetArrowhead2Type(val);
}

double PyAcadDimRotated::measurement() const
{
    return impObj()->GetMeasurement();
}

std::string PyAcadDimRotated::arrowhead1Block() const
{
    return wstr_to_utf8(impObj()->GetArrowhead1Block());
}

void PyAcadDimRotated::setArrowhead1Block(const std::string& val) const
{
    impObj()->SetArrowhead1Block(utf8_to_wstr(val).c_str());
}

std::string PyAcadDimRotated::arrowhead2Block() const
{
    return wstr_to_utf8(impObj()->GetArrowhead2Block());
}

void PyAcadDimRotated::setArrowhead2Block(const std::string& val) const
{
    impObj()->SetArrowhead2Block(utf8_to_wstr(val).c_str());
}

std::string PyAcadDimRotated::dimensionLinetype() const
{
    return wstr_to_utf8(impObj()->GetDimensionLinetype());
}

void PyAcadDimRotated::setDimensionLinetype(const std::string& val) const
{
    impObj()->SetDimensionLinetype(utf8_to_wstr(val).c_str());
}

std::string PyAcadDimRotated::extLine1Linetype() const
{
    return wstr_to_utf8(impObj()->GetExtLine1Linetype());
}

void PyAcadDimRotated::setExtLine1Linetype(const std::string& val) const
{
    impObj()->SetExtLine1Linetype(utf8_to_wstr(val).c_str());
}

std::string PyAcadDimRotated::extLine2Linetype() const
{
    return wstr_to_utf8(impObj()->GetExtLine2Linetype());
}

void PyAcadDimRotated::setExtLine2Linetype(const std::string& val) const
{
    impObj()->SetExtLine2Linetype(utf8_to_wstr(val).c_str());
}

bool PyAcadDimRotated::extLineFixedLenSuppress() const
{
    return impObj()->GetExtLineFixedLenSuppress();
}

void PyAcadDimRotated::setExtLineFixedLenSuppress(bool val) const
{
    impObj()->SetExtLineFixedLenSuppress(val);
}

double PyAcadDimRotated::extLineFixedLen() const
{
    return impObj()->GetExtLineFixedLen();
}

void PyAcadDimRotated::setExtLineFixedLen(double val) const
{
    impObj()->SetExtLineFixedLen(val);
}

bool PyAcadDimRotated::dimConstrForm() const
{
    return impObj()->GetDimConstrForm();
}

void PyAcadDimRotated::setDimConstrForm(bool val) const
{
    impObj()->SetDimConstrForm(val);
}

bool PyAcadDimRotated::dimConstrReference() const
{
    return impObj()->GetDimConstrReference();
}

void PyAcadDimRotated::setDimConstrReference(bool val) const
{
    impObj()->SetDimConstrReference(val);
}

std::string PyAcadDimRotated::dimConstrName() const
{
    return wstr_to_utf8(impObj()->GetDimConstrName());
}

void PyAcadDimRotated::setDimConstrName(const std::string& val) const
{
    impObj()->SetDimConstrName(utf8_to_wstr(val).c_str());
}

std::string PyAcadDimRotated::dimConstrExpression() const
{
    return wstr_to_utf8(impObj()->GetDimConstrExpression());
}

void PyAcadDimRotated::setDimConstrExpression(const std::string& val) const
{
    impObj()->SetDimConstrExpression(utf8_to_wstr(val).c_str());
}

std::string PyAcadDimRotated::dimConstrValue() const
{
    return wstr_to_utf8(impObj()->GetDimConstrValue());
}

void PyAcadDimRotated::setDimConstrValue(const std::string& val) const
{
    impObj()->SetDimConstrValue(utf8_to_wstr(val).c_str());
}

std::string PyAcadDimRotated::dimConstrDesc() const
{
    return wstr_to_utf8(impObj()->GetDimConstrDesc());
}

void PyAcadDimRotated::setDimConstrDesc(const std::string& val) const
{
    impObj()->SetDimConstrDesc(utf8_to_wstr(val).c_str());
}

std::string PyAcadDimRotated::subUnitsSuffix() const
{
    return wstr_to_utf8(impObj()->GetSubUnitsSuffix());
}

void PyAcadDimRotated::setSubUnitsSuffix(const std::string& val) const
{
    impObj()->SetSubUnitsSuffix(utf8_to_wstr(val).c_str());
}

double PyAcadDimRotated::subUnitsFactor() const
{
    return impObj()->GetSubUnitsFactor();
}

void PyAcadDimRotated::setSubUnitsFactor(double val) const
{
    impObj()->SetSubUnitsFactor(val);
}

std::string PyAcadDimRotated::altSubUnitsSuffix() const
{
    return wstr_to_utf8(impObj()->GetAltSubUnitsSuffix());
}

void PyAcadDimRotated::setAltSubUnitsSuffix(const std::string& val) const
{
    impObj()->SetAltSubUnitsSuffix(utf8_to_wstr(val).c_str());
}

double PyAcadDimRotated::altSubUnitsFactor() const
{
    return impObj()->GetAltSubUnitsFactor();
}

void PyAcadDimRotated::setAltSubUnitsFactor(double val) const
{
    impObj()->SetAltSubUnitsFactor(val);
}

PyAcadDimRotated PyAcadDimRotated::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadDimRotated>(src);
}

std::string PyAcadDimRotated::className()
{
    return "AcadDimRotated";
}

PyIAcadDimRotatedImpl* PyAcadDimRotated::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadDimRotatedImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadDimOrdinate
void makePyAcadDimOrdinateWrapper()
{
    PyDocString DS("AcadDimOrdinate");
    class_<PyAcadDimOrdinate, bases<PyAcadDimension>>("AcadDimOrdinate", boost::python::no_init)
        .def("cast", &PyAcadDimOrdinate::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadDimOrdinate::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadDimOrdinate::PyAcadDimOrdinate(std::shared_ptr<PyIAcadDimOrdinateImpl> ptr)
    : PyAcadDimension(ptr)
{
}

bool PyAcadDimOrdinate::altUnits() const
{
    return impObj()->GetAltUnits();
}

void PyAcadDimOrdinate::setAltUnits(bool val) const
{
    impObj()->SetAltUnits(val);
}

PyAcDimPrecision PyAcadDimOrdinate::altUnitsPrecision() const
{
    return impObj()->GetAltUnitsPrecision();
}

void PyAcadDimOrdinate::setAltUnitsPrecision(PyAcDimPrecision val) const
{
    impObj()->SetAltUnitsPrecision(val);
}

double PyAcadDimOrdinate::altUnitsScale() const
{
    return impObj()->GetAltUnitsScale();
}

void PyAcadDimOrdinate::setAltUnitsScale(double val) const
{
    impObj()->SetAltUnitsScale(val);
}

double PyAcadDimOrdinate::altRoundDistance() const
{
    return impObj()->GetAltRoundDistance();
}

void PyAcadDimOrdinate::setAltRoundDistance(double val) const
{
    impObj()->SetAltRoundDistance(val);
}

PyAcDimPrecision PyAcadDimOrdinate::altTolerancePrecision() const
{
    return impObj()->GetAltTolerancePrecision();
}

void PyAcadDimOrdinate::setAltTolerancePrecision(PyAcDimPrecision val) const
{
    impObj()->SetAltTolerancePrecision(val);
}

PyAcDimUnits PyAcadDimOrdinate::altUnitsFormat() const
{
    return impObj()->GetAltUnitsFormat();
}

void PyAcadDimOrdinate::setAltUnitsFormat(PyAcDimUnits val) const
{
    impObj()->SetAltUnitsFormat(val);
}

std::string PyAcadDimOrdinate::altTextPrefix() const
{
    return wstr_to_utf8(impObj()->GetAltTextPrefix());
}

void PyAcadDimOrdinate::setAltTextPrefix(const std::string& val) const
{
    impObj()->SetAltTextPrefix(utf8_to_wstr(val).c_str());
}

std::string PyAcadDimOrdinate::altTextSuffix() const
{
    return wstr_to_utf8(impObj()->GetAltTextSuffix());
}

void PyAcadDimOrdinate::setAltTextSuffix(const std::string& val) const
{
    impObj()->SetAltTextSuffix(utf8_to_wstr(val).c_str());
}

PyAcColor PyAcadDimOrdinate::extensionLineColor() const
{
    return impObj()->GetExtensionLineColor();
}

void PyAcadDimOrdinate::setExtensionLineColor(PyAcColor val) const
{
    impObj()->SetExtensionLineColor(val);
}

PyAcDimPrecision PyAcadDimOrdinate::primaryUnitsPrecision() const
{
    return impObj()->GetPrimaryUnitsPrecision();
}

void PyAcadDimOrdinate::setPrimaryUnitsPrecision(PyAcDimPrecision val) const
{
    impObj()->SetPrimaryUnitsPrecision(val);
}

PyAcDimFractionType PyAcadDimOrdinate::fractionFormat() const
{
    return impObj()->GetFractionFormat();
}

void PyAcadDimOrdinate::setFractionFormat(PyAcDimFractionType val) const
{
    impObj()->SetFractionFormat(val);
}

double PyAcadDimOrdinate::linearScaleFactor() const
{
    return impObj()->GetLinearScaleFactor();
}

void PyAcadDimOrdinate::setLinearScaleFactor(double val) const
{
    impObj()->SetLinearScaleFactor(val);
}

PyAcDimLUnits PyAcadDimOrdinate::unitsFormat() const
{
    return impObj()->GetUnitsFormat();
}

void PyAcadDimOrdinate::setUnitsFormat(PyAcDimLUnits val) const
{
    impObj()->SetUnitsFormat(val);
}

PyAcLineWeight PyAcadDimOrdinate::extensionLineWeight() const
{
    return impObj()->GetExtensionLineWeight();
}

void PyAcadDimOrdinate::setExtensionLineWeight(PyAcLineWeight val) const
{
    impObj()->SetExtensionLineWeight(val);
}

double PyAcadDimOrdinate::roundDistance() const
{
    return impObj()->GetRoundDistance();
}

void PyAcadDimOrdinate::setRoundDistance(double val) const
{
    impObj()->SetRoundDistance(val);
}

double PyAcadDimOrdinate::extensionLineOffset() const
{
    return impObj()->GetExtensionLineOffset();
}

void PyAcadDimOrdinate::setExtensionLineOffset(double val) const
{
    impObj()->SetExtensionLineOffset(val);
}

bool PyAcadDimOrdinate::altSuppressLeadingZeros() const
{
    return impObj()->GetAltSuppressLeadingZeros();
}

void PyAcadDimOrdinate::setAltSuppressLeadingZeros(bool val) const
{
    impObj()->SetAltSuppressLeadingZeros(val);
}

bool PyAcadDimOrdinate::altSuppressTrailingZeros() const
{
    return impObj()->GetAltSuppressTrailingZeros();
}

void PyAcadDimOrdinate::setAltSuppressTrailingZeros(bool val) const
{
    impObj()->SetAltSuppressTrailingZeros(val);
}

bool PyAcadDimOrdinate::altSuppressZeroFeet() const
{
    return impObj()->GetAltSuppressZeroFeet();
}

void PyAcadDimOrdinate::setAltSuppressZeroFeet(bool val) const
{
    impObj()->SetAltSuppressZeroFeet(val);
}

bool PyAcadDimOrdinate::altSuppressZeroInches() const
{
    return impObj()->GetAltSuppressZeroInches();
}

void PyAcadDimOrdinate::setAltSuppressZeroInches(bool val) const
{
    impObj()->SetAltSuppressZeroInches(val);
}

bool PyAcadDimOrdinate::altToleranceSuppressLeadingZeros() const
{
    return impObj()->GetAltToleranceSuppressLeadingZeros();
}

void PyAcadDimOrdinate::setAltToleranceSuppressLeadingZeros(bool val) const
{
    impObj()->SetAltToleranceSuppressLeadingZeros(val);
}

bool PyAcadDimOrdinate::altToleranceSuppressTrailingZeros() const
{
    return impObj()->GetAltToleranceSuppressTrailingZeros();
}

void PyAcadDimOrdinate::setAltToleranceSuppressTrailingZeros(bool val) const
{
    impObj()->SetAltToleranceSuppressTrailingZeros(val);
}

bool PyAcadDimOrdinate::altToleranceSuppressZeroFeet() const
{
    return impObj()->GetAltToleranceSuppressZeroFeet();
}

void PyAcadDimOrdinate::setAltToleranceSuppressZeroFeet(bool val) const
{
    impObj()->SetAltToleranceSuppressZeroFeet(val);
}

bool PyAcadDimOrdinate::altToleranceSuppressZeroInches() const
{
    return impObj()->GetAltToleranceSuppressZeroInches();
}

void PyAcadDimOrdinate::setAltToleranceSuppressZeroInches(bool val) const
{
    impObj()->SetAltToleranceSuppressZeroInches(val);
}

bool PyAcadDimOrdinate::suppressZeroFeet() const
{
    return impObj()->GetSuppressZeroFeet();
}

void PyAcadDimOrdinate::setSuppressZeroFeet(bool val) const
{
    impObj()->SetSuppressZeroFeet(val);
}

bool PyAcadDimOrdinate::suppressZeroInches() const
{
    return impObj()->GetSuppressZeroInches();
}

void PyAcadDimOrdinate::setSuppressZeroInches(bool val) const
{
    impObj()->SetSuppressZeroInches(val);
}

bool PyAcadDimOrdinate::toleranceSuppressZeroFeet() const
{
    return impObj()->GetToleranceSuppressZeroFeet();
}

void PyAcadDimOrdinate::setToleranceSuppressZeroFeet(bool val) const
{
    impObj()->SetToleranceSuppressZeroFeet(val);
}

bool PyAcadDimOrdinate::toleranceSuppressZeroInches() const
{
    return impObj()->GetToleranceSuppressZeroInches();
}

void PyAcadDimOrdinate::setToleranceSuppressZeroInches(bool val) const
{
    impObj()->SetToleranceSuppressZeroInches(val);
}

double PyAcadDimOrdinate::arrowheadSize() const
{
    return impObj()->GetArrowheadSize();
}

void PyAcadDimOrdinate::setArrowheadSize(double val) const
{
    impObj()->SetArrowheadSize(val);
}

double PyAcadDimOrdinate::measurement() const
{
    return impObj()->GetMeasurement();
}

bool PyAcadDimOrdinate::extLineFixedLenSuppress() const
{
    return impObj()->GetExtLineFixedLenSuppress();
}

void PyAcadDimOrdinate::setExtLineFixedLenSuppress(bool val) const
{
    impObj()->SetExtLineFixedLenSuppress(val);
}

double PyAcadDimOrdinate::extLineFixedLen() const
{
    return impObj()->GetExtLineFixedLen();
}

void PyAcadDimOrdinate::setExtLineFixedLen(double val) const
{
    impObj()->SetExtLineFixedLen(val);
}

std::string PyAcadDimOrdinate::subUnitsSuffix() const
{
    return wstr_to_utf8(impObj()->GetSubUnitsSuffix());
}

void PyAcadDimOrdinate::setSubUnitsSuffix(const std::string& val) const
{
    impObj()->SetSubUnitsSuffix(utf8_to_wstr(val).c_str());
}

double PyAcadDimOrdinate::subUnitsFactor() const
{
    return impObj()->GetSubUnitsFactor();
}

void PyAcadDimOrdinate::setSubUnitsFactor(double val) const
{
    impObj()->SetSubUnitsFactor(val);
}

std::string PyAcadDimOrdinate::altSubUnitsSuffix() const
{
    return wstr_to_utf8(impObj()->GetAltSubUnitsSuffix());
}

void PyAcadDimOrdinate::setAltSubUnitsSuffix(const std::string& val) const
{
    impObj()->SetAltSubUnitsSuffix(utf8_to_wstr(val).c_str());
}

double PyAcadDimOrdinate::altSubUnitsFactor() const
{
    return impObj()->GetAltSubUnitsFactor();
}

void PyAcadDimOrdinate::setAltSubUnitsFactor(double val) const
{
    impObj()->SetAltSubUnitsFactor(val);
}

PyAcadDimOrdinate PyAcadDimOrdinate::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadDimOrdinate>(src);
}

std::string PyAcadDimOrdinate::className()
{
    return "AcadDimOrdinate";
}

PyIAcadDimOrdinateImpl* PyAcadDimOrdinate::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadDimOrdinateImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadDimRadial
void makePyAcadDimRadialWrapper()
{
    PyDocString DS("AcadDimRadial");
    class_<PyAcadDimRadial, bases<PyAcadDimension>>("AcadDimRadial", boost::python::no_init)
        .def("cast", &PyAcadDimRadial::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadDimRadial::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadDimRadial::PyAcadDimRadial(std::shared_ptr<PyIAcadDimRadialImpl> ptr)
    : PyAcadDimension(ptr)
{
}

void PyAcadDimRadial::setLeaderLength(double val) const
{
    impObj()->SetLeaderLength(val);
}

bool PyAcadDimRadial::altUnits() const
{
    return impObj()->GetAltUnits();
}

void PyAcadDimRadial::setAltUnits(bool val) const
{
    impObj()->SetAltUnits(val);
}

PyAcDimPrecision PyAcadDimRadial::altUnitsPrecision() const
{
    return impObj()->GetAltUnitsPrecision();
}

void PyAcadDimRadial::setAltUnitsPrecision(PyAcDimPrecision val) const
{
    impObj()->SetAltUnitsPrecision(val);
}

double PyAcadDimRadial::altUnitsScale() const
{
    return impObj()->GetAltUnitsScale();
}

void PyAcadDimRadial::setAltUnitsScale(double val) const
{
    impObj()->SetAltUnitsScale(val);
}

double PyAcadDimRadial::altRoundDistance() const
{
    return impObj()->GetAltRoundDistance();
}

void PyAcadDimRadial::setAltRoundDistance(double val) const
{
    impObj()->SetAltRoundDistance(val);
}

PyAcDimPrecision PyAcadDimRadial::altTolerancePrecision() const
{
    return impObj()->GetAltTolerancePrecision();
}

void PyAcadDimRadial::setAltTolerancePrecision(PyAcDimPrecision val) const
{
    impObj()->SetAltTolerancePrecision(val);
}

PyAcDimUnits PyAcadDimRadial::altUnitsFormat() const
{
    return impObj()->GetAltUnitsFormat();
}

void PyAcadDimRadial::setAltUnitsFormat(PyAcDimUnits val) const
{
    impObj()->SetAltUnitsFormat(val);
}

std::string PyAcadDimRadial::altTextPrefix() const
{
    return wstr_to_utf8(impObj()->GetAltTextPrefix());
}

void PyAcadDimRadial::setAltTextPrefix(const std::string& val) const
{
    impObj()->SetAltTextPrefix(utf8_to_wstr(val).c_str());
}

std::string PyAcadDimRadial::altTextSuffix() const
{
    return wstr_to_utf8(impObj()->GetAltTextSuffix());
}

void PyAcadDimRadial::setAltTextSuffix(const std::string& val) const
{
    impObj()->SetAltTextSuffix(utf8_to_wstr(val).c_str());
}

PyAcDimCenterType PyAcadDimRadial::centerType() const
{
    return impObj()->GetCenterType();
}

void PyAcadDimRadial::setCenterType(PyAcDimCenterType val) const
{
    impObj()->SetCenterType(val);
}

double PyAcadDimRadial::centerMarkSize() const
{
    return impObj()->GetCenterMarkSize();
}

void PyAcadDimRadial::setCenterMarkSize(double val) const
{
    impObj()->SetCenterMarkSize(val);
}

PyAcColor PyAcadDimRadial::dimensionLineColor() const
{
    return impObj()->GetDimensionLineColor();
}

void PyAcadDimRadial::setDimensionLineColor(PyAcColor val) const
{
    impObj()->SetDimensionLineColor(val);
}

PyAcDimPrecision PyAcadDimRadial::primaryUnitsPrecision() const
{
    return impObj()->GetPrimaryUnitsPrecision();
}

void PyAcadDimRadial::setPrimaryUnitsPrecision(PyAcDimPrecision val) const
{
    impObj()->SetPrimaryUnitsPrecision(val);
}

PyAcDimFractionType PyAcadDimRadial::fractionFormat() const
{
    return impObj()->GetFractionFormat();
}

void PyAcadDimRadial::setFractionFormat(PyAcDimFractionType val) const
{
    impObj()->SetFractionFormat(val);
}

PyAcDimFit PyAcadDimRadial::fit() const
{
    return impObj()->GetFit();
}

void PyAcadDimRadial::setFit(PyAcDimFit val) const
{
    impObj()->SetFit(val);
}

double PyAcadDimRadial::linearScaleFactor() const
{
    return impObj()->GetLinearScaleFactor();
}

void PyAcadDimRadial::setLinearScaleFactor(double val) const
{
    impObj()->SetLinearScaleFactor(val);
}

PyAcDimLUnits PyAcadDimRadial::unitsFormat() const
{
    return impObj()->GetUnitsFormat();
}

void PyAcadDimRadial::setUnitsFormat(PyAcDimLUnits val) const
{
    impObj()->SetUnitsFormat(val);
}

double PyAcadDimRadial::roundDistance() const
{
    return impObj()->GetRoundDistance();
}

void PyAcadDimRadial::setRoundDistance(double val) const
{
    impObj()->SetRoundDistance(val);
}

bool PyAcadDimRadial::dimLineSuppress() const
{
    return impObj()->GetDimLineSuppress();
}

void PyAcadDimRadial::setDimLineSuppress(bool val) const
{
    impObj()->SetDimLineSuppress(val);
}

bool PyAcadDimRadial::textInsideAlign() const
{
    return impObj()->GetTextInsideAlign();
}

void PyAcadDimRadial::setTextInsideAlign(bool val) const
{
    impObj()->SetTextInsideAlign(val);
}

bool PyAcadDimRadial::textInside() const
{
    return impObj()->GetTextInside();
}

void PyAcadDimRadial::setTextInside(bool val) const
{
    impObj()->SetTextInside(val);
}

bool PyAcadDimRadial::forceLineInside() const
{
    return impObj()->GetForceLineInside();
}

void PyAcadDimRadial::setForceLineInside(bool val) const
{
    impObj()->SetForceLineInside(val);
}

bool PyAcadDimRadial::textOutsideAlign() const
{
    return impObj()->GetTextOutsideAlign();
}

void PyAcadDimRadial::setTextOutsideAlign(bool val) const
{
    impObj()->SetTextOutsideAlign(val);
}

bool PyAcadDimRadial::altSuppressLeadingZeros() const
{
    return impObj()->GetAltSuppressLeadingZeros();
}

void PyAcadDimRadial::setAltSuppressLeadingZeros(bool val) const
{
    impObj()->SetAltSuppressLeadingZeros(val);
}

bool PyAcadDimRadial::altSuppressTrailingZeros() const
{
    return impObj()->GetAltSuppressTrailingZeros();
}

void PyAcadDimRadial::setAltSuppressTrailingZeros(bool val) const
{
    impObj()->SetAltSuppressTrailingZeros(val);
}

bool PyAcadDimRadial::altSuppressZeroFeet() const
{
    return impObj()->GetAltSuppressZeroFeet();
}

void PyAcadDimRadial::setAltSuppressZeroFeet(bool val) const
{
    impObj()->SetAltSuppressZeroFeet(val);
}

bool PyAcadDimRadial::altSuppressZeroInches() const
{
    return impObj()->GetAltSuppressZeroInches();
}

void PyAcadDimRadial::setAltSuppressZeroInches(bool val) const
{
    impObj()->SetAltSuppressZeroInches(val);
}

bool PyAcadDimRadial::altToleranceSuppressLeadingZeros() const
{
    return impObj()->GetAltToleranceSuppressLeadingZeros();
}

void PyAcadDimRadial::setAltToleranceSuppressLeadingZeros(bool val) const
{
    impObj()->SetAltToleranceSuppressLeadingZeros(val);
}

bool PyAcadDimRadial::altToleranceSuppressTrailingZeros() const
{
    return impObj()->GetAltToleranceSuppressTrailingZeros();
}

void PyAcadDimRadial::setAltToleranceSuppressTrailingZeros(bool val) const
{
    impObj()->SetAltToleranceSuppressTrailingZeros(val);
}

bool PyAcadDimRadial::altToleranceSuppressZeroFeet() const
{
    return impObj()->GetAltToleranceSuppressZeroFeet();
}

void PyAcadDimRadial::setAltToleranceSuppressZeroFeet(bool val) const
{
    impObj()->SetAltToleranceSuppressZeroFeet(val);
}

bool PyAcadDimRadial::altToleranceSuppressZeroInches() const
{
    return impObj()->GetAltToleranceSuppressZeroInches();
}

void PyAcadDimRadial::setAltToleranceSuppressZeroInches(bool val) const
{
    impObj()->SetAltToleranceSuppressZeroInches(val);
}

bool PyAcadDimRadial::suppressZeroFeet() const
{
    return impObj()->GetSuppressZeroFeet();
}

void PyAcadDimRadial::setSuppressZeroFeet(bool val) const
{
    impObj()->SetSuppressZeroFeet(val);
}

bool PyAcadDimRadial::suppressZeroInches() const
{
    return impObj()->GetSuppressZeroInches();
}

void PyAcadDimRadial::setSuppressZeroInches(bool val) const
{
    impObj()->SetSuppressZeroInches(val);
}

bool PyAcadDimRadial::toleranceSuppressZeroFeet() const
{
    return impObj()->GetToleranceSuppressZeroFeet();
}

void PyAcadDimRadial::setToleranceSuppressZeroFeet(bool val) const
{
    impObj()->SetToleranceSuppressZeroFeet(val);
}

bool PyAcadDimRadial::toleranceSuppressZeroInches() const
{
    return impObj()->GetToleranceSuppressZeroInches();
}

void PyAcadDimRadial::setToleranceSuppressZeroInches(bool val) const
{
    impObj()->SetToleranceSuppressZeroInches(val);
}

PyAcLineWeight PyAcadDimRadial::dimensionLineWeight() const
{
    return impObj()->GetDimensionLineWeight();
}

void PyAcadDimRadial::setDimensionLineWeight(PyAcLineWeight val) const
{
    impObj()->SetDimensionLineWeight(val);
}

double PyAcadDimRadial::arrowheadSize() const
{
    return impObj()->GetArrowheadSize();
}

void PyAcadDimRadial::setArrowheadSize(double val) const
{
    impObj()->SetArrowheadSize(val);
}

PyAcDimArrowheadType PyAcadDimRadial::arrowheadType() const
{
    return impObj()->GetArrowheadType();
}

void PyAcadDimRadial::setArrowheadType(PyAcDimArrowheadType val) const
{
    impObj()->SetArrowheadType(val);
}

double PyAcadDimRadial::measurement() const
{
    return impObj()->GetMeasurement();
}

std::string PyAcadDimRadial::arrowheadBlock() const
{
    return wstr_to_utf8(impObj()->GetArrowheadBlock());
}

void PyAcadDimRadial::setArrowheadBlock(const std::string& val) const
{
    impObj()->SetArrowheadBlock(utf8_to_wstr(val).c_str());
}

std::string PyAcadDimRadial::dimensionLinetype() const
{
    return wstr_to_utf8(impObj()->GetDimensionLinetype());
}

void PyAcadDimRadial::setDimensionLinetype(const std::string& val) const
{
    impObj()->SetDimensionLinetype(utf8_to_wstr(val).c_str());
}

bool PyAcadDimRadial::dimConstrForm() const
{
    return impObj()->GetDimConstrForm();
}

void PyAcadDimRadial::setDimConstrForm(bool val) const
{
    impObj()->SetDimConstrForm(val);
}

bool PyAcadDimRadial::dimConstrReference() const
{
    return impObj()->GetDimConstrReference();
}

void PyAcadDimRadial::setDimConstrReference(bool val) const
{
    impObj()->SetDimConstrReference(val);
}

std::string PyAcadDimRadial::dimConstrName() const
{
    return wstr_to_utf8(impObj()->GetDimConstrName());
}

void PyAcadDimRadial::setDimConstrName(const std::string& val) const
{
    impObj()->SetDimConstrName(utf8_to_wstr(val).c_str());
}

std::string PyAcadDimRadial::dimConstrExpression() const
{
    return wstr_to_utf8(impObj()->GetDimConstrExpression());
}

void PyAcadDimRadial::setDimConstrExpression(const std::string& val) const
{
    impObj()->SetDimConstrExpression(utf8_to_wstr(val).c_str());
}

std::string PyAcadDimRadial::dimConstrValue() const
{
    return wstr_to_utf8(impObj()->GetDimConstrValue());
}

void PyAcadDimRadial::setDimConstrValue(const std::string& val) const
{
    impObj()->SetDimConstrValue(utf8_to_wstr(val).c_str());
}

std::string PyAcadDimRadial::dimConstrDesc() const
{
    return wstr_to_utf8(impObj()->GetDimConstrDesc());
}

void PyAcadDimRadial::setDimConstrDesc(const std::string& val) const
{
    impObj()->SetDimConstrDesc(utf8_to_wstr(val).c_str());
}

PyAcadDimRadial PyAcadDimRadial::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadDimRadial>(src);
}

std::string PyAcadDimRadial::className()
{
    return "AcadDimRadial";
}

PyIAcadDimRadialImpl* PyAcadDimRadial::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadDimRadialImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadDim3PointAngular
void makePyAcadDim3PointAngularWrapper()
{
    PyDocString DS("AcadDim3PointAngular");
    class_<PyAcadDim3PointAngular, bases<PyAcadDimension>>("AcadDim3PointAngular", boost::python::no_init)
        .def("cast", &PyAcadDim3PointAngular::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadDim3PointAngular::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadDim3PointAngular::PyAcadDim3PointAngular(std::shared_ptr<PyIAcadDim3PointAngularImpl> ptr)
    : PyAcadDimension(ptr)
{
}

AcGePoint3d PyAcadDim3PointAngular::extLine1EndPoint() const
{
    return impObj()->GetExtLine1EndPoint();
}

void PyAcadDim3PointAngular::setExtLine1EndPoint(const AcGePoint3d& val) const
{
    impObj()->SetExtLine1EndPoint(val);
}

AcGePoint3d PyAcadDim3PointAngular::extLine2EndPoint() const
{
    return impObj()->GetExtLine2EndPoint();
}

void PyAcadDim3PointAngular::setExtLine2EndPoint(const AcGePoint3d& val) const
{
    impObj()->SetExtLine2EndPoint(val);
}

AcGePoint3d PyAcadDim3PointAngular::angleVertex() const
{
    return impObj()->GetAngleVertex();
}

void PyAcadDim3PointAngular::setAngleVertex(const AcGePoint3d& val) const
{
    impObj()->SetAngleVertex(val);
}

PyAcDimPrecision PyAcadDim3PointAngular::textPrecision() const
{
    return impObj()->GetTextPrecision();
}

void PyAcadDim3PointAngular::setTextPrecision(PyAcDimPrecision val) const
{
    impObj()->SetTextPrecision(val);
}

PyAcAngleUnits PyAcadDim3PointAngular::angleFormat() const
{
    return impObj()->GetAngleFormat();
}

void PyAcadDim3PointAngular::setAngleFormat(PyAcAngleUnits val) const
{
    impObj()->SetAngleFormat(val);
}

PyAcColor PyAcadDim3PointAngular::dimensionLineColor() const
{
    return impObj()->GetDimensionLineColor();
}

void PyAcadDim3PointAngular::setDimensionLineColor(PyAcColor val) const
{
    impObj()->SetDimensionLineColor(val);
}

PyAcColor PyAcadDim3PointAngular::extensionLineColor() const
{
    return impObj()->GetExtensionLineColor();
}

void PyAcadDim3PointAngular::setExtensionLineColor(PyAcColor val) const
{
    impObj()->SetExtensionLineColor(val);
}

double PyAcadDim3PointAngular::extensionLineExtend() const
{
    return impObj()->GetExtensionLineExtend();
}

void PyAcadDim3PointAngular::setExtensionLineExtend(double val) const
{
    impObj()->SetExtensionLineExtend(val);
}

PyAcDimFit PyAcadDim3PointAngular::fit() const
{
    return impObj()->GetFit();
}

void PyAcadDim3PointAngular::setFit(PyAcDimFit val) const
{
    impObj()->SetFit(val);
}

PyAcDimHorizontalJustification PyAcadDim3PointAngular::horizontalTextPosition() const
{
    return impObj()->GetHorizontalTextPosition();
}

void PyAcadDim3PointAngular::setHorizontalTextPosition(PyAcDimHorizontalJustification val) const
{
    impObj()->SetHorizontalTextPosition(val);
}

PyAcLineWeight PyAcadDim3PointAngular::extensionLineWeight() const
{
    return impObj()->GetExtensionLineWeight();
}

void PyAcadDim3PointAngular::setExtensionLineWeight(PyAcLineWeight val) const
{
    impObj()->SetExtensionLineWeight(val);
}

bool PyAcadDim3PointAngular::dimLine1Suppress() const
{
    return impObj()->GetDimLine1Suppress();
}

void PyAcadDim3PointAngular::setDimLine1Suppress(bool val) const
{
    impObj()->SetDimLine1Suppress(val);
}

bool PyAcadDim3PointAngular::dimLine2Suppress() const
{
    return impObj()->GetDimLine2Suppress();
}

void PyAcadDim3PointAngular::setDimLine2Suppress(bool val) const
{
    impObj()->SetDimLine2Suppress(val);
}

bool PyAcadDim3PointAngular::extLine1Suppress() const
{
    return impObj()->GetExtLine1Suppress();
}

void PyAcadDim3PointAngular::setExtLine1Suppress(bool val) const
{
    impObj()->SetExtLine1Suppress(val);
}

bool PyAcadDim3PointAngular::extLine2Suppress() const
{
    return impObj()->GetExtLine2Suppress();
}

void PyAcadDim3PointAngular::setExtLine2Suppress(bool val) const
{
    impObj()->SetExtLine2Suppress(val);
}

bool PyAcadDim3PointAngular::dimLineInside() const
{
    return impObj()->GetDimLineInside();
}

void PyAcadDim3PointAngular::setDimLineInside(bool val) const
{
    impObj()->SetDimLineInside(val);
}

bool PyAcadDim3PointAngular::textInsideAlign() const
{
    return impObj()->GetTextInsideAlign();
}

void PyAcadDim3PointAngular::setTextInsideAlign(bool val) const
{
    impObj()->SetTextInsideAlign(val);
}

bool PyAcadDim3PointAngular::textInside() const
{
    return impObj()->GetTextInside();
}

void PyAcadDim3PointAngular::setTextInside(bool val) const
{
    impObj()->SetTextInside(val);
}

bool PyAcadDim3PointAngular::forceLineInside() const
{
    return impObj()->GetForceLineInside();
}

void PyAcadDim3PointAngular::setForceLineInside(bool val) const
{
    impObj()->SetForceLineInside(val);
}

bool PyAcadDim3PointAngular::textOutsideAlign() const
{
    return impObj()->GetTextOutsideAlign();
}

void PyAcadDim3PointAngular::setTextOutsideAlign(bool val) const
{
    impObj()->SetTextOutsideAlign(val);
}

double PyAcadDim3PointAngular::extensionLineOffset() const
{
    return impObj()->GetExtensionLineOffset();
}

void PyAcadDim3PointAngular::setExtensionLineOffset(double val) const
{
    impObj()->SetExtensionLineOffset(val);
}

PyAcLineWeight PyAcadDim3PointAngular::dimensionLineWeight() const
{
    return impObj()->GetDimensionLineWeight();
}

void PyAcadDim3PointAngular::setDimensionLineWeight(PyAcLineWeight val) const
{
    impObj()->SetDimensionLineWeight(val);
}

double PyAcadDim3PointAngular::arrowheadSize() const
{
    return impObj()->GetArrowheadSize();
}

void PyAcadDim3PointAngular::setArrowheadSize(double val) const
{
    impObj()->SetArrowheadSize(val);
}

PyAcDimArrowheadType PyAcadDim3PointAngular::arrowhead1Type() const
{
    return impObj()->GetArrowhead1Type();
}

void PyAcadDim3PointAngular::setArrowhead1Type(PyAcDimArrowheadType val) const
{
    impObj()->SetArrowhead1Type(val);
}

PyAcDimArrowheadType PyAcadDim3PointAngular::arrowhead2Type() const
{
    return impObj()->GetArrowhead2Type();
}

void PyAcadDim3PointAngular::setArrowhead2Type(PyAcDimArrowheadType val) const
{
    impObj()->SetArrowhead2Type(val);
}

double PyAcadDim3PointAngular::measurement() const
{
    return impObj()->GetMeasurement();
}

std::string PyAcadDim3PointAngular::arrowhead1Block() const
{
    return wstr_to_utf8(impObj()->GetArrowhead1Block());
}

void PyAcadDim3PointAngular::setArrowhead1Block(const std::string& val) const
{
    impObj()->SetArrowhead1Block(utf8_to_wstr(val).c_str());
}

std::string PyAcadDim3PointAngular::arrowhead2Block() const
{
    return wstr_to_utf8(impObj()->GetArrowhead2Block());
}

void PyAcadDim3PointAngular::setArrowhead2Block(const std::string& val) const
{
    impObj()->SetArrowhead2Block(utf8_to_wstr(val).c_str());
}

std::string PyAcadDim3PointAngular::dimensionLinetype() const
{
    return wstr_to_utf8(impObj()->GetDimensionLinetype());
}

void PyAcadDim3PointAngular::setDimensionLinetype(const std::string& val) const
{
    impObj()->SetDimensionLinetype(utf8_to_wstr(val).c_str());
}

std::string PyAcadDim3PointAngular::extLine1Linetype() const
{
    return wstr_to_utf8(impObj()->GetExtLine1Linetype());
}

void PyAcadDim3PointAngular::setExtLine1Linetype(const std::string& val) const
{
    impObj()->SetExtLine1Linetype(utf8_to_wstr(val).c_str());
}

std::string PyAcadDim3PointAngular::extLine2Linetype() const
{
    return wstr_to_utf8(impObj()->GetExtLine2Linetype());
}

void PyAcadDim3PointAngular::setExtLine2Linetype(const std::string& val) const
{
    impObj()->SetExtLine2Linetype(utf8_to_wstr(val).c_str());
}

std::string PyAcadDim3PointAngular::dimConstrName() const
{
    return wstr_to_utf8(impObj()->GetDimConstrName());
}

void PyAcadDim3PointAngular::setDimConstrName(const std::string& val) const
{
    impObj()->SetDimConstrName(utf8_to_wstr(val).c_str());
}

std::string PyAcadDim3PointAngular::dimConstrExpression() const
{
    return wstr_to_utf8(impObj()->GetDimConstrExpression());
}

void PyAcadDim3PointAngular::setDimConstrExpression(const std::string& val) const
{
    impObj()->SetDimConstrExpression(utf8_to_wstr(val).c_str());
}

std::string PyAcadDim3PointAngular::dimConstrValue() const
{
    return wstr_to_utf8(impObj()->GetDimConstrValue());
}

void PyAcadDim3PointAngular::setDimConstrValue(const std::string& val) const
{
    impObj()->SetDimConstrValue(utf8_to_wstr(val).c_str());
}

std::string PyAcadDim3PointAngular::dimConstrDesc() const
{
    return wstr_to_utf8(impObj()->GetDimConstrDesc());
}

void PyAcadDim3PointAngular::setDimConstrDesc(const std::string& val) const
{
    impObj()->SetDimConstrDesc(utf8_to_wstr(val).c_str());
}

bool PyAcadDim3PointAngular::extLineFixedLenSuppress() const
{
    return impObj()->GetExtLineFixedLenSuppress();
}

void PyAcadDim3PointAngular::setExtLineFixedLenSuppress(bool val) const
{
    impObj()->SetExtLineFixedLenSuppress(val);
}

double PyAcadDim3PointAngular::extLineFixedLen() const
{
    return impObj()->GetExtLineFixedLen();
}

void PyAcadDim3PointAngular::setExtLineFixedLen(double val) const
{
    impObj()->SetExtLineFixedLen(val);
}

bool PyAcadDim3PointAngular::dimConstrForm() const
{
    return impObj()->GetDimConstrForm();
}

void PyAcadDim3PointAngular::setDimConstrForm(bool val) const
{
    impObj()->SetDimConstrForm(val);
}

bool PyAcadDim3PointAngular::dimConstrReference() const
{
    return impObj()->GetDimConstrReference();
}

void PyAcadDim3PointAngular::setDimConstrReference(bool val) const
{
    impObj()->SetDimConstrReference(val);
}

PyAcadDim3PointAngular PyAcadDim3PointAngular::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadDim3PointAngular>(src);
}

std::string PyAcadDim3PointAngular::className()
{
    return "AcadDim3PointAngular";
}

PyIAcadDim3PointAngularImpl* PyAcadDim3PointAngular::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadDim3PointAngularImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadDimArcLength
void makePyAcadDimArcLengthWrapper()
{
    PyDocString DS("AcadDimArcLength");
    class_<PyAcadDimArcLength, bases<PyAcadDimension>>("AcadDimArcLength", boost::python::no_init)
        .def("cast", &PyAcadDimArcLength::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadDimArcLength::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadDimArcLength::PyAcadDimArcLength(std::shared_ptr<PyIAcadDimArcLengthImpl> ptr)
    : PyAcadDimension(ptr)
{
}

PyAcadDimArcLength PyAcadDimArcLength::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadDimArcLength>(src);
}

std::string PyAcadDimArcLength::className()
{
    return "AcadDimArcLength";
}

PyIAcadDimArcLengthImpl* PyAcadDimArcLength::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadDimArcLengthImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadDimRadialLarge
void makePyAcadDimRadialLargeWrapper()
{
    PyDocString DS("AcadDimRadialLarge");
    class_<PyAcadDimRadialLarge, bases<PyAcadDimension>>("AcadDimRadialLarge", boost::python::no_init)
        .def("cast", &PyAcadDimRadialLarge::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadDimRadialLarge::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadDimRadialLarge::PyAcadDimRadialLarge(std::shared_ptr<PyIAcadDimRadialLargeImpl> ptr)
    : PyAcadDimension(ptr)
{
}

PyAcadDimRadialLarge PyAcadDimRadialLarge::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadDimRadialLarge>(src);
}

std::string PyAcadDimRadialLarge::className()
{
    return "AcadDimRadialLarge";
}

PyIAcadDimRadialLargeImpl* PyAcadDimRadialLarge::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadDimRadialLargeImpl*>(m_pyImp.get());
}