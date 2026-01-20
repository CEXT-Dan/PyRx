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
        .def("setNormal", &PyAcadDimension::setNormal, DS.ARGS({ "normal_vector: PyGe.Vector3d" }))
        .def("rotation", &PyAcadDimension::rotation, DS.ARGS())
        .def("setRotation", &PyAcadDimension::setRotation, DS.ARGS({ "rotation_angle: float" }))
        .def("textPosition", &PyAcadDimension::textPosition, DS.ARGS())
        .def("setTextPosition", &PyAcadDimension::setTextPosition, DS.ARGS({ "text_point: PyGe.Point3d" }))
        .def("textRotation", &PyAcadDimension::textRotation, DS.ARGS())
        .def("setTextRotation", &PyAcadDimension::setTextRotation, DS.ARGS({ "text_rotation_angle: float" }))
        .def("textOverride", &PyAcadDimension::textOverride, DS.ARGS())
        .def("setTextOverride", &PyAcadDimension::setTextOverride, DS.ARGS({ "override_text: str" }))
        .def("styleName", &PyAcadDimension::styleName, DS.ARGS())
        .def("setStyleName", &PyAcadDimension::setStyleName, DS.ARGS({ "style_name: str" }))
        .def("textColor", &PyAcadDimension::textColor, DS.ARGS())
        .def("setTextColor", &PyAcadDimension::setTextColor, DS.ARGS({ "text_color: PyAx.AcColor" }))
        .def("decimalSeparator", &PyAcadDimension::decimalSeparator, DS.ARGS())
        .def("setDecimalSeparator", &PyAcadDimension::setDecimalSeparator, DS.ARGS({ "separator_char: str" }))
        .def("textGap", &PyAcadDimension::textGap, DS.ARGS())
        .def("setTextGap", &PyAcadDimension::setTextGap, DS.ARGS({ "gap_distance: float" }))
        .def("textPrefix", &PyAcadDimension::textPrefix, DS.ARGS())
        .def("setTextPrefix", &PyAcadDimension::setTextPrefix, DS.ARGS({ "prefix_text: str" }))
        .def("textSuffix", &PyAcadDimension::textSuffix, DS.ARGS())
        .def("setTextSuffix", &PyAcadDimension::setTextSuffix, DS.ARGS({ "suffix_text: str" }))
        .def("scaleFactor", &PyAcadDimension::scaleFactor, DS.ARGS())
        .def("setScaleFactor", &PyAcadDimension::setScaleFactor, DS.ARGS({ "scale_factor: float" }))
        .def("verticalTextPosition", &PyAcadDimension::verticalTextPosition, DS.ARGS())
        .def("setVerticalTextPosition", &PyAcadDimension::setVerticalTextPosition, DS.ARGS({ "justification: PyAx.AcDimVerticalJustification" }))
        .def("tolerancePrecision", &PyAcadDimension::tolerancePrecision, DS.ARGS())
        .def("setTolerancePrecision", &PyAcadDimension::setTolerancePrecision, DS.ARGS({ "precision_level: PyAx.AcDimPrecision" }))
        .def("toleranceHeightScale", &PyAcadDimension::toleranceHeightScale, DS.ARGS())
        .def("setToleranceHeightScale", &PyAcadDimension::setToleranceHeightScale, DS.ARGS({ "height_scale: float" }))
        .def("toleranceLowerLimit", &PyAcadDimension::toleranceLowerLimit, DS.ARGS())
        .def("setToleranceLowerLimit", &PyAcadDimension::setToleranceLowerLimit, DS.ARGS({ "lower_limit: float" }))
        .def("textMovement", &PyAcadDimension::textMovement, DS.ARGS())
        .def("setTextMovement", &PyAcadDimension::setTextMovement, DS.ARGS({ "movement_type: PyAx.AcDimTextMovement" }))
        .def("toleranceDisplay", &PyAcadDimension::toleranceDisplay, DS.ARGS())
        .def("setToleranceDisplay", &PyAcadDimension::setToleranceDisplay, DS.ARGS({ "display_method: PyAx.AcDimToleranceMethod" }))
        .def("toleranceJustification", &PyAcadDimension::toleranceJustification, DS.ARGS())
        .def("setToleranceJustification", &PyAcadDimension::setToleranceJustification, DS.ARGS({ "justification: PyAx.AcDimToleranceJustify" }))
        .def("toleranceUpperLimit", &PyAcadDimension::toleranceUpperLimit, DS.ARGS())
        .def("setToleranceUpperLimit", &PyAcadDimension::setToleranceUpperLimit, DS.ARGS({ "upper_limit: float" }))
        .def("textStyle", &PyAcadDimension::textStyle, DS.ARGS())
        .def("setTextStyle", &PyAcadDimension::setTextStyle, DS.ARGS({ "style_name: str" }))
        .def("textHeight", &PyAcadDimension::textHeight, DS.ARGS())
        .def("setTextHeight", &PyAcadDimension::setTextHeight, DS.ARGS({ "height_value: float" }))
        .def("suppressLeadingZeros", &PyAcadDimension::suppressLeadingZeros, DS.ARGS())
        .def("setSuppressLeadingZeros", &PyAcadDimension::setSuppressLeadingZeros, DS.ARGS({ "suppress_flag: bool" }))
        .def("suppressTrailingZeros", &PyAcadDimension::suppressTrailingZeros, DS.ARGS())
        .def("setSuppressTrailingZeros", &PyAcadDimension::setSuppressTrailingZeros, DS.ARGS({ "suppress_flag: bool" }))
        .def("toleranceSuppressLeadingZeros", &PyAcadDimension::toleranceSuppressLeadingZeros, DS.ARGS())
        .def("setToleranceSuppressLeadingZeros", &PyAcadDimension::setToleranceSuppressLeadingZeros, DS.ARGS({ "suppress_flag: bool" }))
        .def("toleranceSuppressTrailingZeros", &PyAcadDimension::toleranceSuppressTrailingZeros, DS.ARGS())
        .def("setToleranceSuppressTrailingZeros", &PyAcadDimension::setToleranceSuppressTrailingZeros, DS.ARGS({ "suppress_flag: bool" }))
        .def("textFill", &PyAcadDimension::textFill, DS.ARGS())
        .def("setTextFill", &PyAcadDimension::setTextFill, DS.ARGS({ "fill_enabled: bool" }))
        .def("textFillColor", &PyAcadDimension::textFillColor, DS.ARGS())
        .def("setTextFillColor", &PyAcadDimension::setTextFillColor, DS.ARGS({ "fill_color: PyAx.AcColor" }))
        .def("dimTxtDirection", &PyAcadDimension::dimTxtDirection, DS.ARGS())
        .def("setDimTxtDirection", &PyAcadDimension::setDimTxtDirection, DS.ARGS({ "direction_enabled: bool" }))
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
        .def("setExtLine1Point", &PyAcadDimAligned::setExtLine1Point, DS.ARGS({ "extension_point1: PyGe.Point3d" }))
        .def("extLine2Point", &PyAcadDimAligned::extLine2Point, DS.ARGS())
        .def("setExtLine2Point", &PyAcadDimAligned::setExtLine2Point, DS.ARGS({ "extension_point2: PyGe.Point3d" }))
        .def("altUnits", &PyAcadDimAligned::altUnits, DS.ARGS())
        .def("setAltUnits", &PyAcadDimAligned::setAltUnits, DS.ARGS({ "alternate_units: bool" }))
        .def("altUnitsPrecision", &PyAcadDimAligned::altUnitsPrecision, DS.ARGS())
        .def("setAltUnitsPrecision", &PyAcadDimAligned::setAltUnitsPrecision, DS.ARGS({ "precision: PyAx.AcDimPrecision" }))
        .def("altUnitsFormat", &PyAcadDimAligned::altUnitsFormat, DS.ARGS())
        .def("setAltUnitsFormat", &PyAcadDimAligned::setAltUnitsFormat, DS.ARGS({ "format: PyAx.AcDimUnits" }))
        .def("altTextPrefix", &PyAcadDimAligned::altTextPrefix, DS.ARGS())
        .def("setAltTextPrefix", &PyAcadDimAligned::setAltTextPrefix, DS.ARGS({ "prefix: str" }))
        .def("altTextSuffix", &PyAcadDimAligned::altTextSuffix, DS.ARGS())
        .def("setAltTextSuffix", &PyAcadDimAligned::setAltTextSuffix, DS.ARGS({ "suffix: str" }))
        .def("dimensionLineColor", &PyAcadDimAligned::dimensionLineColor, DS.ARGS())
        .def("setDimensionLineColor", &PyAcadDimAligned::setDimensionLineColor, DS.ARGS({ "color: PyAx.AcColor" }))
        .def("extensionLineColor", &PyAcadDimAligned::extensionLineColor, DS.ARGS())
        .def("setExtensionLineColor", &PyAcadDimAligned::setExtensionLineColor, DS.ARGS({ "color: PyAx.AcColor" }))
        .def("primaryUnitsPrecision", &PyAcadDimAligned::primaryUnitsPrecision, DS.ARGS())
        .def("setPrimaryUnitsPrecision", &PyAcadDimAligned::setPrimaryUnitsPrecision, DS.ARGS({ "precision: PyAx.AcDimPrecision" }))
        .def("dimensionLineExtend", &PyAcadDimAligned::dimensionLineExtend, DS.ARGS())
        .def("setDimensionLineExtend", &PyAcadDimAligned::setDimensionLineExtend, DS.ARGS({ "extend_distance: float" }))
        .def("extensionLineExtend", &PyAcadDimAligned::extensionLineExtend, DS.ARGS())
        .def("setExtensionLineExtend", &PyAcadDimAligned::setExtensionLineExtend, DS.ARGS({ "extend_distance: float" }))
        .def("fit", &PyAcadDimAligned::fit, DS.ARGS())
        .def("setFit", &PyAcadDimAligned::setFit, DS.ARGS({ "fit_type: PyAx.AcDimFit" }))
        .def("fractionFormat", &PyAcadDimAligned::fractionFormat, DS.ARGS())
        .def("setFractionFormat", &PyAcadDimAligned::setFractionFormat, DS.ARGS({ "format: PyAx.AcDimFractionType" }))
        .def("horizontalTextPosition", &PyAcadDimAligned::horizontalTextPosition, DS.ARGS())
        .def("setHorizontalTextPosition", &PyAcadDimAligned::setHorizontalTextPosition, DS.ARGS({ "position: PyAx.AcDimHorizontalJustification" }))
        .def("linearScaleFactor", &PyAcadDimAligned::linearScaleFactor, DS.ARGS())
        .def("setLinearScaleFactor", &PyAcadDimAligned::setLinearScaleFactor, DS.ARGS({ "scale_factor: float" }))
        .def("unitsFormat", &PyAcadDimAligned::unitsFormat, DS.ARGS())
        .def("setUnitsFormat", &PyAcadDimAligned::setUnitsFormat, DS.ARGS({ "format: PyAx.AcDimLUnits" }))
        .def("extensionLineWeight", &PyAcadDimAligned::extensionLineWeight, DS.ARGS())
        .def("setExtensionLineWeight", &PyAcadDimAligned::setExtensionLineWeight, DS.ARGS({ "weight: PyAx.AcLineWeight" }))
        .def("roundDistance", &PyAcadDimAligned::roundDistance, DS.ARGS())
        .def("setRoundDistance", &PyAcadDimAligned::setRoundDistance, DS.ARGS({ "distance: float" }))
        .def("dimLine1Suppress", &PyAcadDimAligned::dimLine1Suppress, DS.ARGS())
        .def("setDimLine1Suppress", &PyAcadDimAligned::setDimLine1Suppress, DS.ARGS({ "suppress: bool" }))
        .def("dimLine2Suppress", &PyAcadDimAligned::dimLine2Suppress, DS.ARGS())
        .def("setDimLine2Suppress", &PyAcadDimAligned::setDimLine2Suppress, DS.ARGS({ "suppress: bool" }))
        .def("extLine1Suppress", &PyAcadDimAligned::extLine1Suppress, DS.ARGS())
        .def("setExtLine1Suppress", &PyAcadDimAligned::setExtLine1Suppress, DS.ARGS({ "suppress: bool" }))
        .def("extLine2Suppress", &PyAcadDimAligned::extLine2Suppress, DS.ARGS())
        .def("setExtLine2Suppress", &PyAcadDimAligned::setExtLine2Suppress, DS.ARGS({ "suppress: bool" }))
        .def("dimLineInside", &PyAcadDimAligned::dimLineInside, DS.ARGS())
        .def("setDimLineInside", &PyAcadDimAligned::setDimLineInside, DS.ARGS({ "inside: bool" }))
        .def("textInsideAlign", &PyAcadDimAligned::textInsideAlign, DS.ARGS())
        .def("setTextInsideAlign", &PyAcadDimAligned::setTextInsideAlign, DS.ARGS({ "align: bool" }))
        .def("textInside", &PyAcadDimAligned::textInside, DS.ARGS())
        .def("setTextInside", &PyAcadDimAligned::setTextInside, DS.ARGS({ "inside: bool" }))
        .def("forceLineInside", &PyAcadDimAligned::forceLineInside, DS.ARGS())
        .def("setForceLineInside", &PyAcadDimAligned::setForceLineInside, DS.ARGS({ "force: bool" }))
        .def("textOutsideAlign", &PyAcadDimAligned::textOutsideAlign, DS.ARGS())
        .def("setTextOutsideAlign", &PyAcadDimAligned::setTextOutsideAlign, DS.ARGS({ "align: bool" }))
        .def("extensionLineOffset", &PyAcadDimAligned::extensionLineOffset, DS.ARGS())
        .def("setExtensionLineOffset", &PyAcadDimAligned::setExtensionLineOffset, DS.ARGS({ "offset_distance: float" }))
        .def("altSuppressLeadingZeros", &PyAcadDimAligned::altSuppressLeadingZeros, DS.ARGS())
        .def("setAltSuppressLeadingZeros", &PyAcadDimAligned::setAltSuppressLeadingZeros, DS.ARGS({ "suppress: bool" }))
        .def("altSuppressTrailingZeros", &PyAcadDimAligned::altSuppressTrailingZeros, DS.ARGS())
        .def("setAltSuppressTrailingZeros", &PyAcadDimAligned::setAltSuppressTrailingZeros, DS.ARGS({ "suppress: bool" }))
        .def("altSuppressZeroFeet", &PyAcadDimAligned::altSuppressZeroFeet, DS.ARGS())
        .def("setAltSuppressZeroFeet", &PyAcadDimAligned::setAltSuppressZeroFeet, DS.ARGS({ "suppress: bool" }))
        .def("altSuppressZeroInches", &PyAcadDimAligned::altSuppressZeroInches, DS.ARGS())
        .def("setAltSuppressZeroInches", &PyAcadDimAligned::setAltSuppressZeroInches, DS.ARGS({ "suppress: bool" }))
        .def("altToleranceSuppressLeadingZeros", &PyAcadDimAligned::altToleranceSuppressLeadingZeros, DS.ARGS())
        .def("setAltToleranceSuppressLeadingZeros", &PyAcadDimAligned::setAltToleranceSuppressLeadingZeros, DS.ARGS({ "suppress: bool" }))
        .def("altToleranceSuppressTrailingZeros", &PyAcadDimAligned::altToleranceSuppressTrailingZeros, DS.ARGS())
        .def("setAltToleranceSuppressTrailingZeros", &PyAcadDimAligned::setAltToleranceSuppressTrailingZeros, DS.ARGS({ "suppress: bool" }))
        .def("altToleranceSuppressZeroFeet", &PyAcadDimAligned::altToleranceSuppressZeroFeet, DS.ARGS())
        .def("setAltToleranceSuppressZeroFeet", &PyAcadDimAligned::setAltToleranceSuppressZeroFeet, DS.ARGS({ "suppress: bool" }))
        .def("altToleranceSuppressZeroInches", &PyAcadDimAligned::altToleranceSuppressZeroInches, DS.ARGS())
        .def("setAltToleranceSuppressZeroInches", &PyAcadDimAligned::setAltToleranceSuppressZeroInches, DS.ARGS({ "suppress: bool" }))
        .def("suppressZeroFeet", &PyAcadDimAligned::suppressZeroFeet, DS.ARGS())
        .def("setSuppressZeroFeet", &PyAcadDimAligned::setSuppressZeroFeet, DS.ARGS({ "suppress: bool" }))
        .def("suppressZeroInches", &PyAcadDimAligned::suppressZeroInches, DS.ARGS())
        .def("setSuppressZeroInches", &PyAcadDimAligned::setSuppressZeroInches, DS.ARGS({ "suppress: bool" }))
        .def("toleranceSuppressZeroFeet", &PyAcadDimAligned::toleranceSuppressZeroFeet, DS.ARGS())
        .def("setToleranceSuppressZeroFeet", &PyAcadDimAligned::setToleranceSuppressZeroFeet, DS.ARGS({ "suppress: bool" }))
        .def("toleranceSuppressZeroInches", &PyAcadDimAligned::toleranceSuppressZeroInches, DS.ARGS())
        .def("setToleranceSuppressZeroInches", &PyAcadDimAligned::setToleranceSuppressZeroInches, DS.ARGS({ "suppress: bool" }))
        .def("dimensionLineWeight", &PyAcadDimAligned::dimensionLineWeight, DS.ARGS())
        .def("setDimensionLineWeight", &PyAcadDimAligned::setDimensionLineWeight, DS.ARGS({ "weight: PyAx.AcLineWeight" }))
        .def("arrowheadSize", &PyAcadDimAligned::arrowheadSize, DS.ARGS())
        .def("setArrowheadSize", &PyAcadDimAligned::setArrowheadSize, DS.ARGS({ "size: float" }))
        .def("arrowhead1Type", &PyAcadDimAligned::arrowhead1Type, DS.ARGS())
        .def("setArrowhead1Type", &PyAcadDimAligned::setArrowhead1Type, DS.ARGS({ "arrowhead_type: PyAx.AcDimArrowheadType" }))
        .def("arrowhead2Type", &PyAcadDimAligned::arrowhead2Type, DS.ARGS())
        .def("setArrowhead2Type", &PyAcadDimAligned::setArrowhead2Type, DS.ARGS({ "arrowhead_type: PyAx.AcDimArrowheadType" }))
        .def("measurement", &PyAcadDimAligned::measurement, DS.ARGS())
        .def("arrowhead1Block", &PyAcadDimAligned::arrowhead1Block, DS.ARGS())
        .def("setArrowhead1Block", &PyAcadDimAligned::setArrowhead1Block, DS.ARGS({ "block_name: str" }))
        .def("arrowhead2Block", &PyAcadDimAligned::arrowhead2Block, DS.ARGS())
        .def("setArrowhead2Block", &PyAcadDimAligned::setArrowhead2Block, DS.ARGS({ "block_name: str" }))
        .def("dimensionLinetype", &PyAcadDimAligned::dimensionLinetype, DS.ARGS())
        .def("setDimensionLinetype", &PyAcadDimAligned::setDimensionLinetype, DS.ARGS({ "linetype_name: str" }))
        .def("extLine1Linetype", &PyAcadDimAligned::extLine1Linetype, DS.ARGS())
        .def("setExtLine1Linetype", &PyAcadDimAligned::setExtLine1Linetype, DS.ARGS({ "linetype_name: str" }))
        .def("extLine2Linetype", &PyAcadDimAligned::extLine2Linetype, DS.ARGS())
        .def("setExtLine2Linetype", &PyAcadDimAligned::setExtLine2Linetype, DS.ARGS({ "linetype_name: str" }))
        .def("extLineFixedLenSuppress", &PyAcadDimAligned::extLineFixedLenSuppress, DS.ARGS())
        .def("setExtLineFixedLenSuppress", &PyAcadDimAligned::setExtLineFixedLenSuppress, DS.ARGS({ "suppress: bool" }))
        .def("extLineFixedLen", &PyAcadDimAligned::extLineFixedLen, DS.ARGS())
        .def("setExtLineFixedLen", &PyAcadDimAligned::setExtLineFixedLen, DS.ARGS({ "fixed_length: bool" }))
        .def("dimConstrForm", &PyAcadDimAligned::dimConstrForm, DS.ARGS())
        .def("setDimConstrForm", &PyAcadDimAligned::setDimConstrForm, DS.ARGS({ "constrained_form: bool" }))
        .def("dimConstrReference", &PyAcadDimAligned::dimConstrReference, DS.ARGS())
        .def("setDimConstrReference", &PyAcadDimAligned::setDimConstrReference, DS.ARGS({ "reference: bool" }))
        .def("dimConstrName", &PyAcadDimAligned::dimConstrName, DS.ARGS())
        .def("setDimConstrName", &PyAcadDimAligned::setDimConstrName, DS.ARGS({ "constraint_name: str" }))
        .def("dimConstrExpression", &PyAcadDimAligned::dimConstrExpression, DS.ARGS())
        .def("setDimConstrExpression", &PyAcadDimAligned::setDimConstrExpression, DS.ARGS({ "expression: str" }))
        .def("dimConstrValue", &PyAcadDimAligned::dimConstrValue, DS.ARGS())
        .def("setDimConstrValue", &PyAcadDimAligned::setDimConstrValue, DS.ARGS({ "value: str" }))
        .def("dimConstrDesc", &PyAcadDimAligned::dimConstrDesc, DS.ARGS())
        .def("setDimConstrDesc", &PyAcadDimAligned::setDimConstrDesc, DS.ARGS({ "description: str" }))
        .def("subUnitsSuffix", &PyAcadDimAligned::subUnitsSuffix, DS.ARGS())
        .def("setSubUnitsSuffix", &PyAcadDimAligned::setSubUnitsSuffix, DS.ARGS({ "suffix: str" }))
        .def("subUnitsFactor", &PyAcadDimAligned::subUnitsFactor, DS.ARGS())
        .def("setSubUnitsFactor", &PyAcadDimAligned::setSubUnitsFactor, DS.ARGS({ "factor: float" }))
        .def("altSubUnitsSuffix", &PyAcadDimAligned::altSubUnitsSuffix, DS.ARGS())
        .def("setAltSubUnitsSuffix", &PyAcadDimAligned::setAltSubUnitsSuffix, DS.ARGS({ "suffix: str" }))
        .def("altSubUnitsFactor", &PyAcadDimAligned::altSubUnitsFactor, DS.ARGS())
        .def("setAltSubUnitsFactor", &PyAcadDimAligned::setAltSubUnitsFactor, DS.ARGS({ "factor: float" }))
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
        .def("extLine1StartPoint", &PyAcadDimAngular::extLine1StartPoint, DS.ARGS())
        .def("setExtLine1StartPoint", &PyAcadDimAngular::setExtLine1StartPoint, DS.ARGS({ "start_point: PyGe.GePoint3d" }))
        .def("extLine1EndPoint", &PyAcadDimAngular::extLine1EndPoint, DS.ARGS())
        .def("setExtLine1EndPoint", &PyAcadDimAngular::setExtLine1EndPoint, DS.ARGS({ "end_point: PyGe.GePoint3d" }))
        .def("extLine2StartPoint", &PyAcadDimAngular::extLine2StartPoint, DS.ARGS())
        .def("setExtLine2StartPoint", &PyAcadDimAngular::setExtLine2StartPoint, DS.ARGS({ "start_point: PyGe.GePoint3d" }))
        .def("extLine2EndPoint", &PyAcadDimAngular::extLine2EndPoint, DS.ARGS())
        .def("setExtLine2EndPoint", &PyAcadDimAngular::setExtLine2EndPoint, DS.ARGS({ "end_point: PyGe.GePoint3d" }))
        .def("angleFormat", &PyAcadDimAngular::angleFormat, DS.ARGS())
        .def("setAngleFormat", &PyAcadDimAngular::setAngleFormat, DS.ARGS({ "format_type: PyAx.AcAngleUnits" }))
        .def("dimensionLineColor", &PyAcadDimAngular::dimensionLineColor, DS.ARGS())
        .def("setDimensionLineColor", &PyAcadDimAngular::setDimensionLineColor, DS.ARGS({ "color: PyAx.AcColor" }))
        .def("extensionLineColor", &PyAcadDimAngular::extensionLineColor, DS.ARGS())
        .def("setExtensionLineColor", &PyAcadDimAngular::setExtensionLineColor, DS.ARGS({ "color: PyAx.AcColor" }))
        .def("extensionLineExtend", &PyAcadDimAngular::extensionLineExtend, DS.ARGS())
        .def("setExtensionLineExtend", &PyAcadDimAngular::setExtensionLineExtend, DS.ARGS({ "extend_distance: float" }))
        .def("fit", &PyAcadDimAngular::fit, DS.ARGS())
        .def("setFit", &PyAcadDimAngular::setFit, DS.ARGS({ "fit_type: PyAx.AcDimFit" }))
        .def("horizontalTextPosition", &PyAcadDimAngular::horizontalTextPosition, DS.ARGS())
        .def("setHorizontalTextPosition", &PyAcadDimAngular::setHorizontalTextPosition, DS.ARGS({ "justification: PyAx.AcDimHorizontalJustification" }))
        .def("extensionLineWeight", &PyAcadDimAngular::extensionLineWeight, DS.ARGS())
        .def("setExtensionLineWeight", &PyAcadDimAngular::setExtensionLineWeight, DS.ARGS({ "weight: PyAx.AcLineWeight" }))
        .def("dimLine1Suppress", &PyAcadDimAngular::dimLine1Suppress, DS.ARGS())
        .def("setDimLine1Suppress", &PyAcadDimAngular::setDimLine1Suppress, DS.ARGS({ "suppress_flag: bool" }))
        .def("dimLine2Suppress", &PyAcadDimAngular::dimLine2Suppress, DS.ARGS())
        .def("setDimLine2Suppress", &PyAcadDimAngular::setDimLine2Suppress, DS.ARGS({ "suppress_flag: bool" }))
        .def("extLine1Suppress", &PyAcadDimAngular::extLine1Suppress, DS.ARGS())
        .def("setExtLine1Suppress", &PyAcadDimAngular::setExtLine1Suppress, DS.ARGS({ "suppress_flag: bool" }))
        .def("extLine2Suppress", &PyAcadDimAngular::extLine2Suppress, DS.ARGS())
        .def("setExtLine2Suppress", &PyAcadDimAngular::setExtLine2Suppress, DS.ARGS({ "suppress_flag: bool" }))
        .def("dimLineInside", &PyAcadDimAngular::dimLineInside, DS.ARGS())
        .def("setDimLineInside", &PyAcadDimAngular::setDimLineInside, DS.ARGS({ "inside_flag: bool" }))
        .def("textInsideAlign", &PyAcadDimAngular::textInsideAlign, DS.ARGS())
        .def("setTextInsideAlign", &PyAcadDimAngular::setTextInsideAlign, DS.ARGS({ "align_flag: bool" }))
        .def("textInside", &PyAcadDimAngular::textInside, DS.ARGS())
        .def("setTextInside", &PyAcadDimAngular::setTextInside, DS.ARGS({ "inside_flag: bool" }))
        .def("forceLineInside", &PyAcadDimAngular::forceLineInside, DS.ARGS())
        .def("setForceLineInside", &PyAcadDimAngular::setForceLineInside, DS.ARGS({ "force_flag: bool" }))
        .def("textOutsideAlign", &PyAcadDimAngular::textOutsideAlign, DS.ARGS())
        .def("setTextOutsideAlign", &PyAcadDimAngular::setTextOutsideAlign, DS.ARGS({ "align_flag: bool" }))
        .def("textPrecision", &PyAcadDimAngular::textPrecision, DS.ARGS())
        .def("setTextPrecision", &PyAcadDimAngular::setTextPrecision, DS.ARGS({ "precision: PyAx.AcDimPrecision" }))
        .def("extensionLineOffset", &PyAcadDimAngular::extensionLineOffset, DS.ARGS())
        .def("setExtensionLineOffset", &PyAcadDimAngular::setExtensionLineOffset, DS.ARGS({ "offset_distance: float" }))
        .def("dimensionLineWeight", &PyAcadDimAngular::dimensionLineWeight, DS.ARGS())
        .def("setDimensionLineWeight", &PyAcadDimAngular::setDimensionLineWeight, DS.ARGS({ "weight: PyAx.AcLineWeight" }))
        .def("arrowheadSize", &PyAcadDimAngular::arrowheadSize, DS.ARGS())
        .def("setArrowheadSize", &PyAcadDimAngular::setArrowheadSize, DS.ARGS({ "size_value: float" }))
        .def("arrowhead1Type", &PyAcadDimAngular::arrowhead1Type, DS.ARGS())
        .def("setArrowhead1Type", &PyAcadDimAngular::setArrowhead1Type, DS.ARGS({ "arrowhead_type: PyAx.AcDimArrowheadType" }))
        .def("arrowhead2Type", &PyAcadDimAngular::arrowhead2Type, DS.ARGS())
        .def("setArrowhead2Type", &PyAcadDimAngular::setArrowhead2Type, DS.ARGS({ "arrowhead_type: PyAx.AcDimArrowheadType" }))
        .def("measurement", &PyAcadDimAngular::measurement, DS.ARGS())
        .def("arrowhead1Block", &PyAcadDimAngular::arrowhead1Block, DS.ARGS())
        .def("setArrowhead1Block", &PyAcadDimAngular::setArrowhead1Block, DS.ARGS({ "block_name: str" }))
        .def("arrowhead2Block", &PyAcadDimAngular::arrowhead2Block, DS.ARGS())
        .def("setArrowhead2Block", &PyAcadDimAngular::setArrowhead2Block, DS.ARGS({ "block_name: str" }))
        .def("dimensionLinetype", &PyAcadDimAngular::dimensionLinetype, DS.ARGS())
        .def("setDimensionLinetype", &PyAcadDimAngular::setDimensionLinetype, DS.ARGS({ "linetype_name: str" }))
        .def("extLine1Linetype", &PyAcadDimAngular::extLine1Linetype, DS.ARGS())
        .def("setExtLine1Linetype", &PyAcadDimAngular::setExtLine1Linetype, DS.ARGS({ "linetype_name: str" }))
        .def("extLine2Linetype", &PyAcadDimAngular::extLine2Linetype, DS.ARGS())
        .def("setExtLine2Linetype", &PyAcadDimAngular::setExtLine2Linetype, DS.ARGS({ "linetype_name: str" }))
        .def("extLineFixedLenSuppress", &PyAcadDimAngular::extLineFixedLenSuppress, DS.ARGS())
        .def("setExtLineFixedLenSuppress", &PyAcadDimAngular::setExtLineFixedLenSuppress, DS.ARGS({ "suppress_flag: bool" }))
        .def("extLineFixedLen", &PyAcadDimAngular::extLineFixedLen, DS.ARGS())
        .def("setExtLineFixedLen", &PyAcadDimAngular::setExtLineFixedLen, DS.ARGS({ "length_value: float" }))
        .def("dimConstrForm", &PyAcadDimAngular::dimConstrForm, DS.ARGS())
        .def("setDimConstrForm", &PyAcadDimAngular::setDimConstrForm, DS.ARGS({ "form_flag: bool" }))
        .def("dimConstrReference", &PyAcadDimAngular::dimConstrReference, DS.ARGS())
        .def("setDimConstrReference", &PyAcadDimAngular::setDimConstrReference, DS.ARGS({ "reference_flag: bool" }))
        .def("dimConstrName", &PyAcadDimAngular::dimConstrName, DS.ARGS())
        .def("setDimConstrName", &PyAcadDimAngular::setDimConstrName, DS.ARGS({ "constraint_name: str" }))
        .def("dimConstrExpression", &PyAcadDimAngular::dimConstrExpression, DS.ARGS())
        .def("setDimConstrExpression", &PyAcadDimAngular::setDimConstrExpression, DS.ARGS({ "expression_string: str" }))
        .def("dimConstrValue", &PyAcadDimAngular::dimConstrValue, DS.ARGS())
        .def("setDimConstrValue", &PyAcadDimAngular::setDimConstrValue, DS.ARGS({ "value_string: str" }))
        .def("dimConstrDesc", &PyAcadDimAngular::dimConstrDesc, DS.ARGS())
        .def("setDimConstrDesc", &PyAcadDimAngular::setDimConstrDesc, DS.ARGS({ "description_string: str" }))
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
        .def("setLeaderLength", &PyAcadDimDiametric::setLeaderLength, DS.ARGS({ "leader_length: float" }))
        .def("altUnits", &PyAcadDimDiametric::altUnits, DS.ARGS())
        .def("setAltUnits", &PyAcadDimDiametric::setAltUnits, DS.ARGS({ "alternate_units_flag: bool" }))
        .def("altUnitsPrecision", &PyAcadDimDiametric::altUnitsPrecision, DS.ARGS())
        .def("setAltUnitsPrecision", &PyAcadDimDiametric::setAltUnitsPrecision, DS.ARGS({ "precision_type: PyAx.AcDimPrecision" }))
        .def("altUnitsScale", &PyAcadDimDiametric::altUnitsScale, DS.ARGS())
        .def("setAltUnitsScale", &PyAcadDimDiametric::setAltUnitsScale, DS.ARGS({ "scale_flag: bool" }))
        .def("altTolerancePrecision", &PyAcadDimDiametric::altTolerancePrecision, DS.ARGS())
        .def("setAltTolerancePrecision", &PyAcadDimDiametric::setAltTolerancePrecision, DS.ARGS({ "tolerance_precision: PyAx.AcDimPrecision" }))
        .def("altUnitsFormat", &PyAcadDimDiametric::altUnitsFormat, DS.ARGS())
        .def("setAltUnitsFormat", &PyAcadDimDiametric::setAltUnitsFormat, DS.ARGS({ "format_type: PyAx.AcDimUnits" }))
        .def("altTextPrefix", &PyAcadDimDiametric::altTextPrefix, DS.ARGS())
        .def("setAltTextPrefix", &PyAcadDimDiametric::setAltTextPrefix, DS.ARGS({ "prefix_text: str" }))
        .def("altTextSuffix", &PyAcadDimDiametric::altTextSuffix, DS.ARGS())
        .def("setAltTextSuffix", &PyAcadDimDiametric::setAltTextSuffix, DS.ARGS({ "suffix_text: str" }))
        .def("dimensionLineColor", &PyAcadDimDiametric::dimensionLineColor, DS.ARGS())
        .def("setDimensionLineColor", &PyAcadDimDiametric::setDimensionLineColor, DS.ARGS({ "line_color: PyAx.AcColor" }))
        .def("primaryUnitsPrecision", &PyAcadDimDiametric::primaryUnitsPrecision, DS.ARGS())
        .def("setPrimaryUnitsPrecision", &PyAcadDimDiametric::setPrimaryUnitsPrecision, DS.ARGS({ "precision_type: PyAx.AcDimPrecision" }))
        .def("fractionFormat", &PyAcadDimDiametric::fractionFormat, DS.ARGS())
        .def("setFractionFormat", &PyAcadDimDiametric::setFractionFormat, DS.ARGS({ "fraction_format: PyAx.AcDimFractionType" }))
        .def("fit", &PyAcadDimDiametric::fit, DS.ARGS())
        .def("setFit", &PyAcadDimDiametric::setFit, DS.ARGS({ "fit_type: PyAx.AcDimFit" }))
        .def("linearScaleFactor", &PyAcadDimDiametric::linearScaleFactor, DS.ARGS())
        .def("setLinearScaleFactor", &PyAcadDimDiametric::setLinearScaleFactor, DS.ARGS({ "scale_factor: float" }))
        .def("unitsFormat", &PyAcadDimDiametric::unitsFormat, DS.ARGS())
        .def("setUnitsFormat", &PyAcadDimDiametric::setUnitsFormat, DS.ARGS({ "units_format: AcDimLUnits" }))
        .def("roundDistance", &PyAcadDimDiametric::roundDistance, DS.ARGS())
        .def("setRoundDistance", &PyAcadDimDiametric::setRoundDistance, DS.ARGS({ "rounding_distance: float" }))
        .def("dimLine1Suppress", &PyAcadDimDiametric::dimLine1Suppress, DS.ARGS())
        .def("setDimLine1Suppress", &PyAcadDimDiametric::setDimLine1Suppress, DS.ARGS({ "suppress_flag: bool" }))
        .def("dimLine2Suppress", &PyAcadDimDiametric::dimLine2Suppress, DS.ARGS())
        .def("setDimLine2Suppress", &PyAcadDimDiametric::setDimLine2Suppress, DS.ARGS({ "suppress_flag: bool" }))
        .def("textInsideAlign", &PyAcadDimDiametric::textInsideAlign, DS.ARGS())
        .def("setTextInsideAlign", &PyAcadDimDiametric::setTextInsideAlign, DS.ARGS({ "align_flag: bool" }))
        .def("textInside", &PyAcadDimDiametric::textInside, DS.ARGS())
        .def("setTextInside", &PyAcadDimDiametric::setTextInside, DS.ARGS({ "inside_flag: bool" }))
        .def("forceLineInside", &PyAcadDimDiametric::forceLineInside, DS.ARGS())
        .def("setForceLineInside", &PyAcadDimDiametric::setForceLineInside, DS.ARGS({ "force_flag: bool" }))
        .def("textOutsideAlign", &PyAcadDimDiametric::textOutsideAlign, DS.ARGS())
        .def("setTextOutsideAlign", &PyAcadDimDiametric::setTextOutsideAlign, DS.ARGS({ "align_flag: bool" }))
        .def("centerType", &PyAcadDimDiametric::centerType, DS.ARGS())
        .def("setCenterType", &PyAcadDimDiametric::setCenterType, DS.ARGS({ "center_type: PyAx.AcDimCenterType" }))
        .def("centerMarkSize", &PyAcadDimDiametric::centerMarkSize, DS.ARGS())
        .def("setCenterMarkSize", &PyAcadDimDiametric::setCenterMarkSize, DS.ARGS({ "mark_size: float" }))
        .def("altSuppressLeadingZeros", &PyAcadDimDiametric::altSuppressLeadingZeros, DS.ARGS())
        .def("setAltSuppressLeadingZeros", &PyAcadDimDiametric::setAltSuppressLeadingZeros, DS.ARGS({ "suppress_flag: bool" }))
        .def("altSuppressTrailingZeros", &PyAcadDimDiametric::altSuppressTrailingZeros, DS.ARGS())
        .def("setAltSuppressTrailingZeros", &PyAcadDimDiametric::setAltSuppressTrailingZeros, DS.ARGS({ "suppress_flag: bool" }))
        .def("altSuppressZeroFeet", &PyAcadDimDiametric::altSuppressZeroFeet, DS.ARGS())
        .def("setAltSuppressZeroFeet", &PyAcadDimDiametric::setAltSuppressZeroFeet, DS.ARGS({ "suppress_flag: bool" }))
        .def("altSuppressZeroInches", &PyAcadDimDiametric::altSuppressZeroInches, DS.ARGS())
        .def("setAltSuppressZeroInches", &PyAcadDimDiametric::setAltSuppressZeroInches, DS.ARGS({ "suppress_flag: bool" }))
        .def("altToleranceSuppressLeadingZeros", &PyAcadDimDiametric::altToleranceSuppressLeadingZeros, DS.ARGS())
        .def("setAltToleranceSuppressLeadingZeros", &PyAcadDimDiametric::setAltToleranceSuppressLeadingZeros, DS.ARGS({ "suppress_flag: bool" }))
        .def("altToleranceSuppressTrailingZeros", &PyAcadDimDiametric::altToleranceSuppressTrailingZeros, DS.ARGS())
        .def("setAltToleranceSuppressTrailingZeros", &PyAcadDimDiametric::setAltToleranceSuppressTrailingZeros, DS.ARGS({ "suppress_flag: bool" }))
        .def("altToleranceSuppressZeroFeet", &PyAcadDimDiametric::altToleranceSuppressZeroFeet, DS.ARGS())
        .def("setAltToleranceSuppressZeroFeet", &PyAcadDimDiametric::setAltToleranceSuppressZeroFeet, DS.ARGS({ "suppress_flag: bool" }))
        .def("altToleranceSuppressZeroInches", &PyAcadDimDiametric::altToleranceSuppressZeroInches, DS.ARGS())
        .def("setAltToleranceSuppressZeroInches", &PyAcadDimDiametric::setAltToleranceSuppressZeroInches, DS.ARGS({ "suppress_flag: bool" }))
        .def("suppressZeroFeet", &PyAcadDimDiametric::suppressZeroFeet, DS.ARGS())
        .def("setSuppressZeroFeet", &PyAcadDimDiametric::setSuppressZeroFeet, DS.ARGS({ "suppress_flag: bool" }))
        .def("suppressZeroInches", &PyAcadDimDiametric::suppressZeroInches, DS.ARGS())
        .def("setSuppressZeroInches", &PyAcadDimDiametric::setSuppressZeroInches, DS.ARGS({ "suppress_flag: bool" }))
        .def("toleranceSuppressZeroFeet", &PyAcadDimDiametric::toleranceSuppressZeroFeet, DS.ARGS())
        .def("setToleranceSuppressZeroFeet", &PyAcadDimDiametric::setToleranceSuppressZeroFeet, DS.ARGS({ "suppress_flag: bool" }))
        .def("toleranceSuppressZeroInches", &PyAcadDimDiametric::toleranceSuppressZeroInches, DS.ARGS())
        .def("setToleranceSuppressZeroInches", &PyAcadDimDiametric::setToleranceSuppressZeroInches, DS.ARGS({ "suppress_flag: bool" }))
        .def("dimensionLineWeight", &PyAcadDimDiametric::dimensionLineWeight, DS.ARGS())
        .def("setDimensionLineWeight", &PyAcadDimDiametric::setDimensionLineWeight, DS.ARGS({ "line_weight: PyAx.AcLineWeight" }))
        .def("arrowheadSize", &PyAcadDimDiametric::arrowheadSize, DS.ARGS())
        .def("setArrowheadSize", &PyAcadDimDiametric::setArrowheadSize, DS.ARGS({ "arrow_size: float" }))
        .def("arrowhead1Type", &PyAcadDimDiametric::arrowhead1Type, DS.ARGS())
        .def("setArrowhead1Type", &PyAcadDimDiametric::setArrowhead1Type, DS.ARGS({ "arrow_type: PyAx.AcDimArrowheadType" }))
        .def("arrowhead2Type", &PyAcadDimDiametric::arrowhead2Type, DS.ARGS())
        .def("setArrowhead2Type", &PyAcadDimDiametric::setArrowhead2Type, DS.ARGS({ "arrow_type: PyAx.AcDimArrowheadType" }))
        .def("measurement", &PyAcadDimDiametric::measurement, DS.ARGS())
        .def("arrowhead1Block", &PyAcadDimDiametric::arrowhead1Block, DS.ARGS())
        .def("setArrowhead1Block", &PyAcadDimDiametric::setArrowhead1Block, DS.ARGS({ "block_name: str" }))
        .def("arrowhead2Block", &PyAcadDimDiametric::arrowhead2Block, DS.ARGS())
        .def("setArrowhead2Block", &PyAcadDimDiametric::setArrowhead2Block, DS.ARGS({ "block_name: str" }))
        .def("dimensionLinetype", &PyAcadDimDiametric::dimensionLinetype, DS.ARGS())
        .def("setDimensionLinetype", &PyAcadDimDiametric::setDimensionLinetype, DS.ARGS({ "linetype_name: str" }))
        .def("dimConstrForm", &PyAcadDimDiametric::dimConstrForm, DS.ARGS())
        .def("setDimConstrForm", &PyAcadDimDiametric::setDimConstrForm, DS.ARGS({ "constraint_form_flag: bool" }))
        .def("dimConstrReference", &PyAcadDimDiametric::dimConstrReference, DS.ARGS())
        .def("setDimConstrReference", &PyAcadDimDiametric::setDimConstrReference, DS.ARGS({ "reference_flag: bool" }))
        .def("dimConstrName", &PyAcadDimDiametric::dimConstrName, DS.ARGS())
        .def("setDimConstrName", &PyAcadDimDiametric::setDimConstrName, DS.ARGS({ "constraint_name: str" }))
        .def("dimConstrExpression", &PyAcadDimDiametric::dimConstrExpression, DS.ARGS())
        .def("setDimConstrExpression", &PyAcadDimDiametric::setDimConstrExpression, DS.ARGS({ "expression_text: str" }))
        .def("dimConstrValue", &PyAcadDimDiametric::dimConstrValue, DS.ARGS())
        .def("setDimConstrValue", &PyAcadDimDiametric::setDimConstrValue, DS.ARGS({ "value_text: str" }))
        .def("dimConstrDesc", &PyAcadDimDiametric::dimConstrDesc, DS.ARGS())
        .def("setDimConstrDesc", &PyAcadDimDiametric::setDimConstrDesc, DS.ARGS({ "description_text: str" }))
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
        .def("altUnits", &PyAcadDimRotated::altUnits, DS.ARGS())
        .def("setAltUnits", &PyAcadDimRotated::setAltUnits, DS.ARGS({ "enable: bool" }))
        .def("altUnitsPrecision", &PyAcadDimRotated::altUnitsPrecision, DS.ARGS())
        .def("setAltUnitsPrecision", &PyAcadDimRotated::setAltUnitsPrecision, DS.ARGS({ "precision: PyAx.AcDimPrecision" }))
        .def("altUnitsScale", &PyAcadDimRotated::altUnitsScale, DS.ARGS())
        .def("setAltUnitsScale", &PyAcadDimRotated::setAltUnitsScale, DS.ARGS({ "scale_factor: float" }))
        .def("altRoundDistance", &PyAcadDimRotated::altRoundDistance, DS.ARGS())
        .def("setAltRoundDistance", &PyAcadDimRotated::setAltRoundDistance, DS.ARGS({ "distance: float" }))
        .def("altTolerancePrecision", &PyAcadDimRotated::altTolerancePrecision, DS.ARGS())
        .def("setAltTolerancePrecision", &PyAcadDimRotated::setAltTolerancePrecision, DS.ARGS({ "precision: PyAx.AcDimPrecision" }))
        .def("altUnitsFormat", &PyAcadDimRotated::altUnitsFormat, DS.ARGS())
        .def("setAltUnitsFormat", &PyAcadDimRotated::setAltUnitsFormat, DS.ARGS({ "format: PyAx.AcDimUnits" }))
        .def("altTextPrefix", &PyAcadDimRotated::altTextPrefix, DS.ARGS())
        .def("setAltTextPrefix", &PyAcadDimRotated::setAltTextPrefix, DS.ARGS({ "prefix: str" }))
        .def("altTextSuffix", &PyAcadDimRotated::altTextSuffix, DS.ARGS())
        .def("setAltTextSuffix", &PyAcadDimRotated::setAltTextSuffix, DS.ARGS({ "suffix: str" }))
        .def("dimensionLineColor", &PyAcadDimRotated::dimensionLineColor, DS.ARGS())
        .def("setDimensionLineColor", &PyAcadDimRotated::setDimensionLineColor, DS.ARGS({ "color: PyAx.AcColor" }))
        .def("extensionLineColor", &PyAcadDimRotated::extensionLineColor, DS.ARGS())
        .def("setExtensionLineColor", &PyAcadDimRotated::setExtensionLineColor, DS.ARGS({ "color: PyAx.AcColor" }))
        .def("primaryUnitsPrecision", &PyAcadDimRotated::primaryUnitsPrecision, DS.ARGS())
        .def("setPrimaryUnitsPrecision", &PyAcadDimRotated::setPrimaryUnitsPrecision, DS.ARGS({ "precision: PyAx.AcDimPrecision" }))
        .def("dimensionLineExtend", &PyAcadDimRotated::dimensionLineExtend, DS.ARGS())
        .def("setDimensionLineExtend", &PyAcadDimRotated::setDimensionLineExtend, DS.ARGS({ "extension: float" }))
        .def("extensionLineExtend", &PyAcadDimRotated::extensionLineExtend, DS.ARGS())
        .def("setExtensionLineExtend", &PyAcadDimRotated::setExtensionLineExtend, DS.ARGS({ "extension: float" }))
        .def("fit", &PyAcadDimRotated::fit, DS.ARGS())
        .def("setFit", &PyAcadDimRotated::setFit, DS.ARGS({ "fit_type: PyAx.AcDimFit" }))
        .def("fractionFormat", &PyAcadDimRotated::fractionFormat, DS.ARGS())
        .def("setFractionFormat", &PyAcadDimRotated::setFractionFormat, DS.ARGS({ "format: PyAx.AcDimFractionType" }))
        .def("horizontalTextPosition", &PyAcadDimRotated::horizontalTextPosition, DS.ARGS())
        .def("setHorizontalTextPosition", &PyAcadDimRotated::setHorizontalTextPosition, DS.ARGS({ "position: PyAx.AcDimHorizontalJustification" }))
        .def("linearScaleFactor", &PyAcadDimRotated::linearScaleFactor, DS.ARGS())
        .def("setLinearScaleFactor", &PyAcadDimRotated::setLinearScaleFactor, DS.ARGS({ "scale_factor: float" }))
        .def("unitsFormat", &PyAcadDimRotated::unitsFormat, DS.ARGS())
        .def("setUnitsFormat", &PyAcadDimRotated::setUnitsFormat, DS.ARGS({ "format: PyAx.AcDimLUnits" }))
        .def("extensionLineWeight", &PyAcadDimRotated::extensionLineWeight, DS.ARGS())
        .def("setExtensionLineWeight", &PyAcadDimRotated::setExtensionLineWeight, DS.ARGS({ "weight: PyAx.AcLineWeight" }))
        .def("roundDistance", &PyAcadDimRotated::roundDistance, DS.ARGS())
        .def("setRoundDistance", &PyAcadDimRotated::setRoundDistance, DS.ARGS({ "distance: float" }))
        .def("dimLine1Suppress", &PyAcadDimRotated::dimLine1Suppress, DS.ARGS())
        .def("setDimLine1Suppress", &PyAcadDimRotated::setDimLine1Suppress, DS.ARGS({ "suppress: bool" }))
        .def("dimLine2Suppress", &PyAcadDimRotated::dimLine2Suppress, DS.ARGS())
        .def("setDimLine2Suppress", &PyAcadDimRotated::setDimLine2Suppress, DS.ARGS({ "suppress: bool" }))
        .def("extLine1Suppress", &PyAcadDimRotated::extLine1Suppress, DS.ARGS())
        .def("setExtLine1Suppress", &PyAcadDimRotated::setExtLine1Suppress, DS.ARGS({ "suppress: bool" }))
        .def("extLine2Suppress", &PyAcadDimRotated::extLine2Suppress, DS.ARGS())
        .def("setExtLine2Suppress", &PyAcadDimRotated::setExtLine2Suppress, DS.ARGS({ "suppress: bool" }))
        .def("dimLineInside", &PyAcadDimRotated::dimLineInside, DS.ARGS())
        .def("setDimLineInside", &PyAcadDimRotated::setDimLineInside, DS.ARGS({ "inside: bool" }))
        .def("textInsideAlign", &PyAcadDimRotated::textInsideAlign, DS.ARGS())
        .def("setTextInsideAlign", &PyAcadDimRotated::setTextInsideAlign, DS.ARGS({ "align: bool" }))
        .def("textInside", &PyAcadDimRotated::textInside, DS.ARGS())
        .def("setTextInside", &PyAcadDimRotated::setTextInside, DS.ARGS({ "inside: bool" }))
        .def("forceLineInside", &PyAcadDimRotated::forceLineInside, DS.ARGS())
        .def("setForceLineInside", &PyAcadDimRotated::setForceLineInside, DS.ARGS({ "force: bool" }))
        .def("textOutsideAlign", &PyAcadDimRotated::textOutsideAlign, DS.ARGS())
        .def("setTextOutsideAlign", &PyAcadDimRotated::setTextOutsideAlign, DS.ARGS({ "align: bool" }))
        .def("extensionLineOffset", &PyAcadDimRotated::extensionLineOffset, DS.ARGS())
        .def("setExtensionLineOffset", &PyAcadDimRotated::setExtensionLineOffset, DS.ARGS({ "offset: float" }))
        .def("altSuppressLeadingZeros", &PyAcadDimRotated::altSuppressLeadingZeros, DS.ARGS())
        .def("setAltSuppressLeadingZeros", &PyAcadDimRotated::setAltSuppressLeadingZeros, DS.ARGS({ "suppress: bool" }))
        .def("altSuppressTrailingZeros", &PyAcadDimRotated::altSuppressTrailingZeros, DS.ARGS())
        .def("setAltSuppressTrailingZeros", &PyAcadDimRotated::setAltSuppressTrailingZeros, DS.ARGS({ "suppress: bool" }))
        .def("altSuppressZeroFeet", &PyAcadDimRotated::altSuppressZeroFeet, DS.ARGS())
        .def("setAltSuppressZeroFeet", &PyAcadDimRotated::setAltSuppressZeroFeet, DS.ARGS({ "suppress: bool" }))
        .def("altSuppressZeroInches", &PyAcadDimRotated::altSuppressZeroInches, DS.ARGS())
        .def("setAltSuppressZeroInches", &PyAcadDimRotated::setAltSuppressZeroInches, DS.ARGS({ "suppress: bool" }))
        .def("altToleranceSuppressLeadingZeros", &PyAcadDimRotated::altToleranceSuppressLeadingZeros, DS.ARGS())
        .def("setAltToleranceSuppressLeadingZeros", &PyAcadDimRotated::setAltToleranceSuppressLeadingZeros, DS.ARGS({ "suppress: bool" }))
        .def("altToleranceSuppressTrailingZeros", &PyAcadDimRotated::altToleranceSuppressTrailingZeros, DS.ARGS())
        .def("setAltToleranceSuppressTrailingZeros", &PyAcadDimRotated::setAltToleranceSuppressTrailingZeros, DS.ARGS({ "suppress: bool" }))
        .def("altToleranceSuppressZeroFeet", &PyAcadDimRotated::altToleranceSuppressZeroFeet, DS.ARGS())
        .def("setAltToleranceSuppressZeroFeet", &PyAcadDimRotated::setAltToleranceSuppressZeroFeet, DS.ARGS({ "suppress: bool" }))
        .def("altToleranceSuppressZeroInches", &PyAcadDimRotated::altToleranceSuppressZeroInches, DS.ARGS())
        .def("setAltToleranceSuppressZeroInches", &PyAcadDimRotated::setAltToleranceSuppressZeroInches, DS.ARGS({ "suppress: bool" }))
        .def("suppressZeroFeet", &PyAcadDimRotated::suppressZeroFeet, DS.ARGS())
        .def("setSuppressZeroFeet", &PyAcadDimRotated::setSuppressZeroFeet, DS.ARGS({ "suppress: bool" }))
        .def("suppressZeroInches", &PyAcadDimRotated::suppressZeroInches, DS.ARGS())
        .def("setSuppressZeroInches", &PyAcadDimRotated::setSuppressZeroInches, DS.ARGS({ "suppress: bool" }))
        .def("toleranceSuppressZeroFeet", &PyAcadDimRotated::toleranceSuppressZeroFeet, DS.ARGS())
        .def("setToleranceSuppressZeroFeet", &PyAcadDimRotated::setToleranceSuppressZeroFeet, DS.ARGS({ "suppress: bool" }))
        .def("toleranceSuppressZeroInches", &PyAcadDimRotated::toleranceSuppressZeroInches, DS.ARGS())
        .def("setToleranceSuppressZeroInches", &PyAcadDimRotated::setToleranceSuppressZeroInches, DS.ARGS({ "suppress: bool" }))
        .def("dimensionLineWeight", &PyAcadDimRotated::dimensionLineWeight, DS.ARGS())
        .def("setDimensionLineWeight", &PyAcadDimRotated::setDimensionLineWeight, DS.ARGS({ "weight: PyAx.AcLineWeight" }))
        .def("arrowheadSize", &PyAcadDimRotated::arrowheadSize, DS.ARGS())
        .def("setArrowheadSize", &PyAcadDimRotated::setArrowheadSize, DS.ARGS({ "size: float" }))
        .def("arrowhead1Type", &PyAcadDimRotated::arrowhead1Type, DS.ARGS())
        .def("setArrowhead1Type", &PyAcadDimRotated::setArrowhead1Type, DS.ARGS({ "type: PyAx.AcDimArrowheadType" }))
        .def("arrowhead2Type", &PyAcadDimRotated::arrowhead2Type, DS.ARGS())
        .def("setArrowhead2Type", &PyAcadDimRotated::setArrowhead2Type, DS.ARGS({ "type: PyAx.AcDimArrowheadType" }))
        .def("measurement", &PyAcadDimRotated::measurement, DS.ARGS())
        .def("arrowhead1Block", &PyAcadDimRotated::arrowhead1Block, DS.ARGS())
        .def("setArrowhead1Block", &PyAcadDimRotated::setArrowhead1Block, DS.ARGS({ "block_name: str" }))
        .def("arrowhead2Block", &PyAcadDimRotated::arrowhead2Block, DS.ARGS())
        .def("setArrowhead2Block", &PyAcadDimRotated::setArrowhead2Block, DS.ARGS({ "block_name: str" }))
        .def("dimensionLinetype", &PyAcadDimRotated::dimensionLinetype, DS.ARGS())
        .def("setDimensionLinetype", &PyAcadDimRotated::setDimensionLinetype, DS.ARGS({ "linetype_name: str" }))
        .def("extLine1Linetype", &PyAcadDimRotated::extLine1Linetype, DS.ARGS())
        .def("setExtLine1Linetype", &PyAcadDimRotated::setExtLine1Linetype, DS.ARGS({ "linetype_name: str" }))
        .def("extLine2Linetype", &PyAcadDimRotated::extLine2Linetype, DS.ARGS())
        .def("setExtLine2Linetype", &PyAcadDimRotated::setExtLine2Linetype, DS.ARGS({ "linetype_name: str" }))
        .def("extLineFixedLenSuppress", &PyAcadDimRotated::extLineFixedLenSuppress, DS.ARGS())
        .def("setExtLineFixedLenSuppress", &PyAcadDimRotated::setExtLineFixedLenSuppress, DS.ARGS({ "suppress: bool" }))
        .def("extLineFixedLen", &PyAcadDimRotated::extLineFixedLen, DS.ARGS())
        .def("setExtLineFixedLen", &PyAcadDimRotated::setExtLineFixedLen, DS.ARGS({ "length: float" }))
        .def("dimConstrForm", &PyAcadDimRotated::dimConstrForm, DS.ARGS())
        .def("setDimConstrForm", &PyAcadDimRotated::setDimConstrForm, DS.ARGS({ "form: bool" }))
        .def("dimConstrReference", &PyAcadDimRotated::dimConstrReference, DS.ARGS())
        .def("setDimConstrReference", &PyAcadDimRotated::setDimConstrReference, DS.ARGS({ "reference: bool" }))
        .def("dimConstrName", &PyAcadDimRotated::dimConstrName, DS.ARGS())
        .def("setDimConstrName", &PyAcadDimRotated::setDimConstrName, DS.ARGS({ "name: str" }))
        .def("dimConstrExpression", &PyAcadDimRotated::dimConstrExpression, DS.ARGS())
        .def("setDimConstrExpression", &PyAcadDimRotated::setDimConstrExpression, DS.ARGS({ "expression: str" }))
        .def("dimConstrDesc", &PyAcadDimRotated::dimConstrDesc, DS.ARGS())
        .def("setDimConstrValue", &PyAcadDimRotated::setDimConstrValue, DS.ARGS({ "value: str" }))
        .def("dimConstrValue", &PyAcadDimRotated::dimConstrValue, DS.ARGS())
        .def("setDimConstrDesc", &PyAcadDimRotated::setDimConstrDesc, DS.ARGS({ "description: str" }))
        .def("subUnitsSuffix", &PyAcadDimRotated::subUnitsSuffix, DS.ARGS())
        .def("setSubUnitsSuffix", &PyAcadDimRotated::setSubUnitsSuffix, DS.ARGS({ "suffix: str" }))
        .def("subUnitsFactor", &PyAcadDimRotated::subUnitsFactor, DS.ARGS())
        .def("setSubUnitsFactor", &PyAcadDimRotated::setSubUnitsFactor, DS.ARGS({ "factor: float" }))
        .def("altSubUnitsSuffix", &PyAcadDimRotated::altSubUnitsSuffix, DS.ARGS())
        .def("setAltSubUnitsSuffix", &PyAcadDimRotated::setAltSubUnitsSuffix, DS.ARGS({ "suffix: str" }))
        .def("altSubUnitsFactor", &PyAcadDimRotated::altSubUnitsFactor, DS.ARGS())
        .def("setAltSubUnitsFactor", &PyAcadDimRotated::setAltSubUnitsFactor, DS.ARGS({ "factor: float" }))
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
        .def("altUnits", &PyAcadDimOrdinate::altUnits, DS.ARGS())
        .def("setAltUnits", &PyAcadDimOrdinate::setAltUnits, DS.ARGS({ "use_alternate_units: bool" }))
        .def("altUnitsPrecision", &PyAcadDimOrdinate::altUnitsPrecision, DS.ARGS())
        .def("setAltUnitsPrecision", &PyAcadDimOrdinate::setAltUnitsPrecision, DS.ARGS({ "precision_type: PyAx.AcDimPrecision" }))
        .def("altUnitsScale", &PyAcadDimOrdinate::altUnitsScale, DS.ARGS())
        .def("setAltUnitsScale", &PyAcadDimOrdinate::setAltUnitsScale, DS.ARGS({ "scale_factor: float" }))
        .def("altRoundDistance", &PyAcadDimOrdinate::altRoundDistance, DS.ARGS())
        .def("setAltRoundDistance", &PyAcadDimOrdinate::setAltRoundDistance, DS.ARGS({ "round_distance: float" }))
        .def("altTolerancePrecision", &PyAcadDimOrdinate::altTolerancePrecision, DS.ARGS())
        .def("setAltTolerancePrecision", &PyAcadDimOrdinate::setAltTolerancePrecision, DS.ARGS({ "tolerance_precision: PyAx.AcDimPrecision" }))
        .def("altUnitsFormat", &PyAcadDimOrdinate::altUnitsFormat, DS.ARGS())
        .def("setAltUnitsFormat", &PyAcadDimOrdinate::setAltUnitsFormat, DS.ARGS({ "units_format: PyAx.AcDimUnits" }))
        .def("altTextPrefix", &PyAcadDimOrdinate::altTextPrefix, DS.ARGS())
        .def("setAltTextPrefix", &PyAcadDimOrdinate::setAltTextPrefix, DS.ARGS({ "prefix_text: str" }))
        .def("altTextSuffix", &PyAcadDimOrdinate::altTextSuffix, DS.ARGS())
        .def("setAltTextSuffix", &PyAcadDimOrdinate::setAltTextSuffix, DS.ARGS({ "suffix_text: str" }))
        .def("extensionLineColor", &PyAcadDimOrdinate::extensionLineColor, DS.ARGS())
        .def("setExtensionLineColor", &PyAcadDimOrdinate::setExtensionLineColor, DS.ARGS({ "color: PyAx.AcColor" }))
        .def("primaryUnitsPrecision", &PyAcadDimOrdinate::primaryUnitsPrecision, DS.ARGS())
        .def("setPrimaryUnitsPrecision", &PyAcadDimOrdinate::setPrimaryUnitsPrecision, DS.ARGS({ "precision_type: PyAx.AcDimPrecision" }))
        .def("fractionFormat", &PyAcadDimOrdinate::fractionFormat, DS.ARGS())
        .def("setFractionFormat", &PyAcadDimOrdinate::setFractionFormat, DS.ARGS({ "fraction_type: PyAx.AcDimFractionType" }))
        .def("linearScaleFactor", &PyAcadDimOrdinate::linearScaleFactor, DS.ARGS())
        .def("setLinearScaleFactor", &PyAcadDimOrdinate::setLinearScaleFactor, DS.ARGS({ "scale_factor: float" }))
        .def("unitsFormat", &PyAcadDimOrdinate::unitsFormat, DS.ARGS())
        .def("setUnitsFormat", &PyAcadDimOrdinate::setUnitsFormat, DS.ARGS({ "units_format: PyAx.AcDimLUnits" }))
        .def("extensionLineWeight", &PyAcadDimOrdinate::extensionLineWeight, DS.ARGS())
        .def("setExtensionLineWeight", &PyAcadDimOrdinate::setExtensionLineWeight, DS.ARGS({ "weight: PyAx.AcLineWeight" }))
        .def("roundDistance", &PyAcadDimOrdinate::roundDistance, DS.ARGS())
        .def("setRoundDistance", &PyAcadDimOrdinate::setRoundDistance, DS.ARGS({ "round_distance: float" }))
        .def("extensionLineOffset", &PyAcadDimOrdinate::extensionLineOffset, DS.ARGS())
        .def("setExtensionLineOffset", &PyAcadDimOrdinate::setExtensionLineOffset, DS.ARGS({ "offset_distance: float" }))
        .def("altSuppressLeadingZeros", &PyAcadDimOrdinate::altSuppressLeadingZeros, DS.ARGS())
        .def("setAltSuppressLeadingZeros", &PyAcadDimOrdinate::setAltSuppressLeadingZeros, DS.ARGS({ "suppress_leading_zeros: bool" }))
        .def("altSuppressTrailingZeros", &PyAcadDimOrdinate::altSuppressTrailingZeros, DS.ARGS())
        .def("setAltSuppressTrailingZeros", &PyAcadDimOrdinate::setAltSuppressTrailingZeros, DS.ARGS({ "suppress_trailing_zeros: bool" }))
        .def("altSuppressZeroFeet", &PyAcadDimOrdinate::altSuppressZeroFeet, DS.ARGS())
        .def("setAltSuppressZeroFeet", &PyAcadDimOrdinate::setAltSuppressZeroFeet, DS.ARGS({ "suppress_zero_feet: bool" }))
        .def("altSuppressZeroInches", &PyAcadDimOrdinate::altSuppressZeroInches, DS.ARGS())
        .def("setAltSuppressZeroInches", &PyAcadDimOrdinate::setAltSuppressZeroInches, DS.ARGS({ "suppress_zero_inches: bool" }))
        .def("altToleranceSuppressLeadingZeros", &PyAcadDimOrdinate::altToleranceSuppressLeadingZeros, DS.ARGS())
        .def("setAltToleranceSuppressLeadingZeros", &PyAcadDimOrdinate::setAltToleranceSuppressLeadingZeros, DS.ARGS({ "suppress_leading_zeros: bool" }))
        .def("altToleranceSuppressTrailingZeros", &PyAcadDimOrdinate::altToleranceSuppressTrailingZeros, DS.ARGS())
        .def("setAltToleranceSuppressTrailingZeros", &PyAcadDimOrdinate::setAltToleranceSuppressTrailingZeros, DS.ARGS({ "suppress_trailing_zeros: bool" }))
        .def("altToleranceSuppressZeroFeet", &PyAcadDimOrdinate::altToleranceSuppressZeroFeet, DS.ARGS())
        .def("setAltToleranceSuppressZeroFeet", &PyAcadDimOrdinate::setAltToleranceSuppressZeroFeet, DS.ARGS({ "suppress_zero_feet: bool" }))
        .def("altToleranceSuppressZeroInches", &PyAcadDimOrdinate::altToleranceSuppressZeroInches, DS.ARGS())
        .def("setAltToleranceSuppressZeroInches", &PyAcadDimOrdinate::setAltToleranceSuppressZeroInches, DS.ARGS({ "suppress_zero_inches: bool" }))
        .def("suppressZeroFeet", &PyAcadDimOrdinate::suppressZeroFeet, DS.ARGS())
        .def("setSuppressZeroFeet", &PyAcadDimOrdinate::setSuppressZeroFeet, DS.ARGS({ "suppress_zero_feet: bool" }))
        .def("suppressZeroInches", &PyAcadDimOrdinate::suppressZeroInches, DS.ARGS())
        .def("setSuppressZeroInches", &PyAcadDimOrdinate::setSuppressZeroInches, DS.ARGS({ "suppress_zero_inches: bool" }))
        .def("toleranceSuppressZeroFeet", &PyAcadDimOrdinate::toleranceSuppressZeroFeet, DS.ARGS())
        .def("setToleranceSuppressZeroFeet", &PyAcadDimOrdinate::setToleranceSuppressZeroFeet, DS.ARGS({ "suppress_zero_feet: bool" }))
        .def("toleranceSuppressZeroInches", &PyAcadDimOrdinate::toleranceSuppressZeroInches, DS.ARGS())
        .def("setToleranceSuppressZeroInches", &PyAcadDimOrdinate::setToleranceSuppressZeroInches, DS.ARGS({ "suppress_zero_inches: bool" }))
        .def("arrowheadSize", &PyAcadDimOrdinate::arrowheadSize, DS.ARGS())
        .def("setArrowheadSize", &PyAcadDimOrdinate::setArrowheadSize, DS.ARGS({ "size: float" }))
        .def("measurement", &PyAcadDimOrdinate::measurement, DS.ARGS())
        .def("extLineFixedLenSuppress", &PyAcadDimOrdinate::extLineFixedLenSuppress, DS.ARGS())
        .def("setExtLineFixedLenSuppress", &PyAcadDimOrdinate::setExtLineFixedLenSuppress, DS.ARGS({ "suppress: bool" }))
        .def("extLineFixedLen", &PyAcadDimOrdinate::extLineFixedLen, DS.ARGS())
        .def("setExtLineFixedLen", &PyAcadDimOrdinate::setExtLineFixedLen, DS.ARGS({ "fixed_length: bool" }))
        .def("subUnitsSuffix", &PyAcadDimOrdinate::subUnitsSuffix, DS.ARGS())
        .def("setSubUnitsSuffix", &PyAcadDimOrdinate::setSubUnitsSuffix, DS.ARGS({ "suffix: str" }))
        .def("subUnitsFactor", &PyAcadDimOrdinate::subUnitsFactor, DS.ARGS())
        .def("setSubUnitsFactor", &PyAcadDimOrdinate::setSubUnitsFactor, DS.ARGS({ "factor: float" }))
        .def("altSubUnitsSuffix", &PyAcadDimOrdinate::altSubUnitsSuffix, DS.ARGS())
        .def("setAltSubUnitsSuffix", &PyAcadDimOrdinate::setAltSubUnitsSuffix, DS.ARGS({ "suffix: str" }))
        .def("altSubUnitsFactor", &PyAcadDimOrdinate::altSubUnitsFactor, DS.ARGS())
        .def("setAltSubUnitsFactor", &PyAcadDimOrdinate::setAltSubUnitsFactor, DS.ARGS({ "factor: float" }))
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
        .def("setLeaderLength", &PyAcadDimRadial::setLeaderLength, DS.ARGS({ "leader_length: float" }))
        .def("altUnits", &PyAcadDimRadial::altUnits, DS.ARGS())
        .def("setAltUnits", &PyAcadDimRadial::setAltUnits, DS.ARGS({ "use_alternate_units: bool" }))
        .def("altUnitsPrecision", &PyAcadDimRadial::altUnitsPrecision, DS.ARGS())
        .def("setAltUnitsPrecision", &PyAcadDimRadial::setAltUnitsPrecision, DS.ARGS({ "precision: PyAx.AcDimPrecision" }))
        .def("altUnitsScale", &PyAcadDimRadial::altUnitsScale, DS.ARGS())
        .def("setAltUnitsScale", &PyAcadDimRadial::setAltUnitsScale, DS.ARGS({ "scale_factor: float" }))
        .def("altRoundDistance", &PyAcadDimRadial::altRoundDistance, DS.ARGS())
        .def("setAltRoundDistance", &PyAcadDimRadial::setAltRoundDistance, DS.ARGS({ "round_distance: float" }))
        .def("altTolerancePrecision", &PyAcadDimRadial::altTolerancePrecision, DS.ARGS())
        .def("setAltTolerancePrecision", &PyAcadDimRadial::setAltTolerancePrecision, DS.ARGS({ "tolerance_precision: PyAx.AcDimPrecision" }))
        .def("altUnitsFormat", &PyAcadDimRadial::altUnitsFormat, DS.ARGS())
        .def("setAltUnitsFormat", &PyAcadDimRadial::setAltUnitsFormat, DS.ARGS({ "format: PyAx.AcDimUnits" }))
        .def("altTextPrefix", &PyAcadDimRadial::altTextPrefix, DS.ARGS())
        .def("setAltTextPrefix", &PyAcadDimRadial::setAltTextPrefix, DS.ARGS({ "prefix_text: str" }))
        .def("altTextSuffix", &PyAcadDimRadial::altTextSuffix, DS.ARGS())
        .def("setAltTextSuffix", &PyAcadDimRadial::setAltTextSuffix, DS.ARGS({ "suffix_text: str" }))
        .def("centerType", &PyAcadDimRadial::centerType, DS.ARGS())
        .def("setCenterType", &PyAcadDimRadial::setCenterType, DS.ARGS({ "center_type: PyAx.AcDimCenterType" }))
        .def("centerMarkSize", &PyAcadDimRadial::centerMarkSize, DS.ARGS())
        .def("setCenterMarkSize", &PyAcadDimRadial::setCenterMarkSize, DS.ARGS({ "mark_size: float" }))
        .def("dimensionLineColor", &PyAcadDimRadial::dimensionLineColor, DS.ARGS())
        .def("setDimensionLineColor", &PyAcadDimRadial::setDimensionLineColor, DS.ARGS({ "color: PyAx.AcColor" }))
        .def("primaryUnitsPrecision", &PyAcadDimRadial::primaryUnitsPrecision, DS.ARGS())
        .def("setPrimaryUnitsPrecision", &PyAcadDimRadial::setPrimaryUnitsPrecision, DS.ARGS({ "precision: PyAx.AcDimPrecision" }))
        .def("fractionFormat", &PyAcadDimRadial::fractionFormat, DS.ARGS())
        .def("setFractionFormat", &PyAcadDimRadial::setFractionFormat, DS.ARGS({ "format_type: PyAx.AcDimFractionType" }))
        .def("fit", &PyAcadDimRadial::fit, DS.ARGS())
        .def("setFit", &PyAcadDimRadial::setFit, DS.ARGS({ "fit_type: PyAx.AcDimFit" }))
        .def("linearScaleFactor", &PyAcadDimRadial::linearScaleFactor, DS.ARGS())
        .def("setLinearScaleFactor", &PyAcadDimRadial::setLinearScaleFactor, DS.ARGS({ "scale_factor: float" }))
        .def("unitsFormat", &PyAcadDimRadial::unitsFormat, DS.ARGS())
        .def("setUnitsFormat", &PyAcadDimRadial::setUnitsFormat, DS.ARGS({ "format: PyAx.AcDimLUnits" }))
        .def("roundDistance", &PyAcadDimRadial::roundDistance, DS.ARGS())
        .def("setRoundDistance", &PyAcadDimRadial::setRoundDistance, DS.ARGS({ "round_distance: float" }))
        .def("dimLineSuppress", &PyAcadDimRadial::dimLineSuppress, DS.ARGS())
        .def("setDimLineSuppress", &PyAcadDimRadial::setDimLineSuppress, DS.ARGS({ "suppress_dim_line: bool" }))
        .def("textInsideAlign", &PyAcadDimRadial::textInsideAlign, DS.ARGS())
        .def("setTextInsideAlign", &PyAcadDimRadial::setTextInsideAlign, DS.ARGS({ "align_inside_text: bool" }))
        .def("textInside", &PyAcadDimRadial::textInside, DS.ARGS())
        .def("setTextInside", &PyAcadDimRadial::setTextInside, DS.ARGS({ "inside_text: bool" }))
        .def("forceLineInside", &PyAcadDimRadial::forceLineInside, DS.ARGS())
        .def("setForceLineInside", &PyAcadDimRadial::setForceLineInside, DS.ARGS({ "force_line_inside: bool" }))
        .def("textOutsideAlign", &PyAcadDimRadial::textOutsideAlign, DS.ARGS())
        .def("setTextOutsideAlign", &PyAcadDimRadial::setTextOutsideAlign, DS.ARGS({ "align_outside_text: bool" }))
        .def("altSuppressLeadingZeros", &PyAcadDimRadial::altSuppressLeadingZeros, DS.ARGS())
        .def("setAltSuppressLeadingZeros", &PyAcadDimRadial::setAltSuppressLeadingZeros, DS.ARGS({ "suppress_leading_zeros: bool" }))
        .def("altSuppressTrailingZeros", &PyAcadDimRadial::altSuppressTrailingZeros, DS.ARGS())
        .def("setAltSuppressTrailingZeros", &PyAcadDimRadial::setAltSuppressTrailingZeros, DS.ARGS({ "suppress_trailing_zeros: bool" }))
        .def("altSuppressZeroFeet", &PyAcadDimRadial::altSuppressZeroFeet, DS.ARGS())
        .def("setAltSuppressZeroFeet", &PyAcadDimRadial::setAltSuppressZeroFeet, DS.ARGS({ "suppress_zero_feet: bool" }))
        .def("altSuppressZeroInches", &PyAcadDimRadial::altSuppressZeroInches, DS.ARGS())
        .def("setAltSuppressZeroInches", &PyAcadDimRadial::setAltSuppressZeroInches, DS.ARGS({ "suppress_zero_inches: bool" }))
        .def("altToleranceSuppressLeadingZeros", &PyAcadDimRadial::altToleranceSuppressLeadingZeros, DS.ARGS())
        .def("setAltToleranceSuppressLeadingZeros", &PyAcadDimRadial::setAltToleranceSuppressLeadingZeros, DS.ARGS({ "suppress_tolerance_leading_zeros: bool" }))
        .def("altToleranceSuppressTrailingZeros", &PyAcadDimRadial::altToleranceSuppressTrailingZeros, DS.ARGS())
        .def("setAltToleranceSuppressTrailingZeros", &PyAcadDimRadial::setAltToleranceSuppressTrailingZeros, DS.ARGS({ "suppress_tolerance_trailing_zeros: bool" }))
        .def("altToleranceSuppressZeroFeet", &PyAcadDimRadial::altToleranceSuppressZeroFeet, DS.ARGS())
        .def("setAltToleranceSuppressZeroFeet", &PyAcadDimRadial::setAltToleranceSuppressZeroFeet, DS.ARGS({ "suppress_tolerance_zero_feet: bool" }))
        .def("altToleranceSuppressZeroInches", &PyAcadDimRadial::altToleranceSuppressZeroInches, DS.ARGS())
        .def("setAltToleranceSuppressZeroInches", &PyAcadDimRadial::setAltToleranceSuppressZeroInches, DS.ARGS({ "suppress_tolerance_zero_inches: bool" }))
        .def("suppressZeroFeet", &PyAcadDimRadial::suppressZeroFeet, DS.ARGS())
        .def("setSuppressZeroFeet", &PyAcadDimRadial::setSuppressZeroFeet, DS.ARGS({ "suppress_zero_feet: bool" }))
        .def("suppressZeroInches", &PyAcadDimRadial::suppressZeroInches, DS.ARGS())
        .def("setSuppressZeroInches", &PyAcadDimRadial::setSuppressZeroInches, DS.ARGS({ "suppress_zero_inches: bool" }))
        .def("toleranceSuppressZeroFeet", &PyAcadDimRadial::toleranceSuppressZeroFeet, DS.ARGS())
        .def("setToleranceSuppressZeroFeet", &PyAcadDimRadial::setToleranceSuppressZeroFeet, DS.ARGS({ "suppress_tolerance_zero_feet: bool" }))
        .def("toleranceSuppressZeroInches", &PyAcadDimRadial::toleranceSuppressZeroInches, DS.ARGS())
        .def("setToleranceSuppressZeroInches", &PyAcadDimRadial::setToleranceSuppressZeroInches, DS.ARGS({ "suppress_tolerance_zero_inches: bool" }))
        .def("dimensionLineWeight", &PyAcadDimRadial::dimensionLineWeight, DS.ARGS())
        .def("setDimensionLineWeight", &PyAcadDimRadial::setDimensionLineWeight, DS.ARGS({ "line_weight: PyAx.AcLineWeight" }))
        .def("arrowheadSize", &PyAcadDimRadial::arrowheadSize, DS.ARGS())
        .def("setArrowheadSize", &PyAcadDimRadial::setArrowheadSize, DS.ARGS({ "size: float" }))
        .def("arrowheadType", &PyAcadDimRadial::arrowheadType, DS.ARGS())
        .def("setArrowheadType", &PyAcadDimRadial::setArrowheadType, DS.ARGS({ "arrowhead_type: PyAx.AcDimArrowheadType" }))
        .def("measurement", &PyAcadDimRadial::measurement, DS.ARGS())
        .def("arrowheadBlock", &PyAcadDimRadial::arrowheadBlock, DS.ARGS())
        .def("setArrowheadBlock", &PyAcadDimRadial::setArrowheadBlock, DS.ARGS({ "block_name: str" }))
        .def("dimensionLinetype", &PyAcadDimRadial::dimensionLinetype, DS.ARGS())
        .def("setDimensionLinetype", &PyAcadDimRadial::setDimensionLinetype, DS.ARGS({ "linetype_name: str" }))
        .def("dimConstrForm", &PyAcadDimRadial::dimConstrForm, DS.ARGS())
        .def("setDimConstrForm", &PyAcadDimRadial::setDimConstrForm, DS.ARGS({ "constrained_form: bool" }))
        .def("dimConstrReference", &PyAcadDimRadial::dimConstrReference, DS.ARGS())
        .def("setDimConstrReference", &PyAcadDimRadial::setDimConstrReference, DS.ARGS({ "reference_constrained: bool" }))
        .def("dimConstrName", &PyAcadDimRadial::dimConstrName, DS.ARGS())
        .def("setDimConstrName", &PyAcadDimRadial::setDimConstrName, DS.ARGS({ "constraint_name: str" }))
        .def("dimConstrExpression", &PyAcadDimRadial::dimConstrExpression, DS.ARGS())
        .def("setDimConstrExpression", &PyAcadDimRadial::setDimConstrExpression, DS.ARGS({ "expression_text: str" }))
        .def("dimConstrValue", &PyAcadDimRadial::dimConstrValue, DS.ARGS())
        .def("setDimConstrValue", &PyAcadDimRadial::setDimConstrValue, DS.ARGS({ "constraint_value: str" }))
        .def("dimConstrDesc", &PyAcadDimRadial::dimConstrDesc, DS.ARGS())
        .def("setDimConstrDesc", &PyAcadDimRadial::setDimConstrDesc, DS.ARGS({ "description: str" }))
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
        .def("extLine1EndPoint", &PyAcadDim3PointAngular::extLine1EndPoint, DS.ARGS())
        .def("setExtLine1EndPoint", &PyAcadDim3PointAngular::setExtLine1EndPoint, DS.ARGS({ "endpoint: PyGe.Point3d" }))
        .def("extLine2EndPoint", &PyAcadDim3PointAngular::extLine2EndPoint, DS.ARGS())
        .def("setExtLine2EndPoint", &PyAcadDim3PointAngular::setExtLine2EndPoint, DS.ARGS({ "endpoint: PyGe.Point3d" }))
        .def("angleVertex", &PyAcadDim3PointAngular::angleVertex, DS.ARGS())
        .def("setAngleVertex", &PyAcadDim3PointAngular::setAngleVertex, DS.ARGS({ "vertex_point: PyGe.Point3d" }))
        .def("textPrecision", &PyAcadDim3PointAngular::textPrecision, DS.ARGS())
        .def("setTextPrecision", &PyAcadDim3PointAngular::setTextPrecision, DS.ARGS({ "precision_value: PyAx.AcDimPrecisionint3d" }))
        .def("angleFormat", &PyAcadDim3PointAngular::angleFormat, DS.ARGS())
        .def("setAngleFormat", &PyAcadDim3PointAngular::setAngleFormat, DS.ARGS({ "format_type: PyAx.AngleUnits" }))
        .def("dimensionLineColor", &PyAcadDim3PointAngular::dimensionLineColor, DS.ARGS())
        .def("setDimensionLineColor", &PyAcadDim3PointAngular::setDimensionLineColor, DS.ARGS({ "color: PyAx.AcColor" }))
        .def("extensionLineColor", &PyAcadDim3PointAngular::extensionLineColor, DS.ARGS())
        .def("setExtensionLineColor", &PyAcadDim3PointAngular::setExtensionLineColor, DS.ARGS({ "color: PyAx.AcColor" }))
        .def("extensionLineExtend", &PyAcadDim3PointAngular::extensionLineExtend, DS.ARGS())
        .def("setExtensionLineExtend", &PyAcadDim3PointAngular::setExtensionLineExtend, DS.ARGS({ "extend_value: PyAx.AcColor" }))
        .def("fit", &PyAcadDim3PointAngular::fit, DS.ARGS())
        .def("setFit", &PyAcadDim3PointAngular::setFit, DS.ARGS({ "fit_type: PyAx.AcDimFit" }))
        .def("horizontalTextPosition", &PyAcadDim3PointAngular::horizontalTextPosition, DS.ARGS())
        .def("setHorizontalTextPosition", &PyAcadDim3PointAngular::setHorizontalTextPosition, DS.ARGS({ "justification: PyAx.AcDimHorizontalJustification" }))
        .def("extensionLineWeight", &PyAcadDim3PointAngular::extensionLineWeight, DS.ARGS())
        .def("setExtensionLineWeight", &PyAcadDim3PointAngular::setExtensionLineWeight, DS.ARGS({ "weight: PyAx.AcLineWeight" }))
        .def("dimLine1Suppress", &PyAcadDim3PointAngular::dimLine1Suppress, DS.ARGS())
        .def("setDimLine1Suppress", &PyAcadDim3PointAngular::setDimLine1Suppress, DS.ARGS({ "suppress: bool" }))
        .def("dimLine2Suppress", &PyAcadDim3PointAngular::dimLine2Suppress, DS.ARGS())
        .def("setDimLine2Suppress", &PyAcadDim3PointAngular::setDimLine2Suppress, DS.ARGS({ "suppress: bool" }))
        .def("extLine1Suppress", &PyAcadDim3PointAngular::extLine1Suppress, DS.ARGS())
        .def("setExtLine1Suppress", &PyAcadDim3PointAngular::setExtLine1Suppress, DS.ARGS({ "suppress: bool" }))
        .def("extLine2Suppress", &PyAcadDim3PointAngular::extLine2Suppress, DS.ARGS())
        .def("setExtLine2Suppress", &PyAcadDim3PointAngular::setExtLine2Suppress, DS.ARGS({ "suppress: bool" }))
        .def("dimLineInside", &PyAcadDim3PointAngular::dimLineInside, DS.ARGS())
        .def("setDimLineInside", &PyAcadDim3PointAngular::setDimLineInside, DS.ARGS({ "inside_flag: bool" }))
        .def("textInsideAlign", &PyAcadDim3PointAngular::textInsideAlign, DS.ARGS())
        .def("setTextInsideAlign", &PyAcadDim3PointAngular::setTextInsideAlign, DS.ARGS({ "align_flag: bool" }))
        .def("textInside", &PyAcadDim3PointAngular::textInside, DS.ARGS())
        .def("setTextInside", &PyAcadDim3PointAngular::setTextInside, DS.ARGS({ "inside_flag: bool" }))
        .def("forceLineInside", &PyAcadDim3PointAngular::forceLineInside, DS.ARGS())
        .def("setForceLineInside", &PyAcadDim3PointAngular::setForceLineInside, DS.ARGS({ "force_flag: bool" }))
        .def("textOutsideAlign", &PyAcadDim3PointAngular::textOutsideAlign, DS.ARGS())
        .def("setTextOutsideAlign", &PyAcadDim3PointAngular::setTextOutsideAlign, DS.ARGS({ "align_flag: bool" }))
        .def("extensionLineOffset", &PyAcadDim3PointAngular::extensionLineOffset, DS.ARGS())
        .def("setExtensionLineOffset", &PyAcadDim3PointAngular::setExtensionLineOffset, DS.ARGS({ "offset_value: float" }))
        .def("dimensionLineWeight", &PyAcadDim3PointAngular::dimensionLineWeight, DS.ARGS())
        .def("setDimensionLineWeight", &PyAcadDim3PointAngular::setDimensionLineWeight, DS.ARGS({ "weight: PyAx.AcLineWeight" }))
        .def("arrowheadSize", &PyAcadDim3PointAngular::arrowheadSize, DS.ARGS())
        .def("setArrowheadSize", &PyAcadDim3PointAngular::setArrowheadSize, DS.ARGS({ "size_value: float" }))
        .def("arrowhead1Type", &PyAcadDim3PointAngular::arrowhead1Type, DS.ARGS())
        .def("setArrowhead1Type", &PyAcadDim3PointAngular::setArrowhead1Type, DS.ARGS({ "type_value: PyAx.AcDimArrowheadType" }))
        .def("arrowhead2Type", &PyAcadDim3PointAngular::arrowhead2Type, DS.ARGS())
        .def("setArrowhead2Type", &PyAcadDim3PointAngular::setArrowhead2Type, DS.ARGS({ "type_value: PyAx.AcDimArrowheadType" }))
        .def("measurement", &PyAcadDim3PointAngular::measurement, DS.ARGS())
        .def("arrowhead1Block", &PyAcadDim3PointAngular::arrowhead1Block, DS.ARGS())
        .def("setArrowhead1Block", &PyAcadDim3PointAngular::setArrowhead1Block, DS.ARGS({ "block_name: str" }))
        .def("arrowhead2Block", &PyAcadDim3PointAngular::arrowhead2Block, DS.ARGS())
        .def("setArrowhead2Block", &PyAcadDim3PointAngular::setArrowhead2Block, DS.ARGS({ "block_name: str" }))
        .def("dimensionLinetype", &PyAcadDim3PointAngular::dimensionLinetype, DS.ARGS())
        .def("setDimensionLinetype", &PyAcadDim3PointAngular::setDimensionLinetype, DS.ARGS({ "linetype_name: str" }))
        .def("extLine1Linetype", &PyAcadDim3PointAngular::extLine1Linetype, DS.ARGS())
        .def("setExtLine1Linetype", &PyAcadDim3PointAngular::setExtLine1Linetype, DS.ARGS({ "linetype_name: str" }))
        .def("extLine2Linetype", &PyAcadDim3PointAngular::extLine2Linetype, DS.ARGS())
        .def("setExtLine2Linetype", &PyAcadDim3PointAngular::setExtLine2Linetype, DS.ARGS({ "linetype_name: str" }))
        .def("dimConstrName", &PyAcadDim3PointAngular::dimConstrName, DS.ARGS())
        .def("setDimConstrName", &PyAcadDim3PointAngular::setDimConstrName, DS.ARGS({ "constraint_name: str" }))
        .def("dimConstrExpression", &PyAcadDim3PointAngular::dimConstrExpression, DS.ARGS())
        .def("setDimConstrExpression", &PyAcadDim3PointAngular::setDimConstrExpression, DS.ARGS({ "expression_str: str" }))
        .def("dimConstrValue", &PyAcadDim3PointAngular::dimConstrValue, DS.ARGS())
        .def("setDimConstrValue", &PyAcadDim3PointAngular::setDimConstrValue, DS.ARGS({ "value_str: str" }))
        .def("dimConstrDesc", &PyAcadDim3PointAngular::dimConstrDesc, DS.ARGS())
        .def("setDimConstrDesc", &PyAcadDim3PointAngular::setDimConstrDesc, DS.ARGS({ "description_str: str" }))
        .def("extLineFixedLenSuppress", &PyAcadDim3PointAngular::extLineFixedLenSuppress, DS.ARGS())
        .def("setExtLineFixedLenSuppress", &PyAcadDim3PointAngular::setExtLineFixedLenSuppress, DS.ARGS({ "suppress_flag: bool" }))
        .def("extLineFixedLen", &PyAcadDim3PointAngular::extLineFixedLen, DS.ARGS())
        .def("setExtLineFixedLen", &PyAcadDim3PointAngular::setExtLineFixedLen, DS.ARGS({ "length_value: float" }))
        .def("dimConstrForm", &PyAcadDim3PointAngular::dimConstrForm, DS.ARGS())
        .def("setDimConstrForm", &PyAcadDim3PointAngular::setDimConstrForm, DS.ARGS({ "form_flag: bool" }))
        .def("dimConstrReference", &PyAcadDim3PointAngular::dimConstrReference, DS.ARGS())
        .def("setDimConstrReference", &PyAcadDim3PointAngular::setDimConstrReference, DS.ARGS({ "reference_flag: bool" }))
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
        .def("altUnits", &PyAcadDimArcLength::altUnits, DS.ARGS())
        .def("setAltUnits", &PyAcadDimArcLength::setAltUnits, DS.ARGS({ "enabled:bool" }))
        .def("altUnitsPrecision", &PyAcadDimArcLength::altUnitsPrecision, DS.ARGS())
        .def("setAltUnitsPrecision", &PyAcadDimArcLength::setAltUnitsPrecision, DS.ARGS({ "precision:PyAx.AcDimPrecision" }))
        .def("altUnitsScale", &PyAcadDimArcLength::altUnitsScale, DS.ARGS())
        .def("setAltUnitsScale", &PyAcadDimArcLength::setAltUnitsScale, DS.ARGS({ "scale_factor:float" }))
        .def("altRoundDistance", &PyAcadDimArcLength::altRoundDistance, DS.ARGS())
        .def("setAltRoundDistance", &PyAcadDimArcLength::setAltRoundDistance, DS.ARGS({ "round_distance:float" }))
        .def("altTolerancePrecision", &PyAcadDimArcLength::altTolerancePrecision, DS.ARGS())
        .def("setAltTolerancePrecision", &PyAcadDimArcLength::setAltTolerancePrecision, DS.ARGS({ "precision:PyAx.AcDimPrecision" }))
        .def("altUnitsFormat", &PyAcadDimArcLength::altUnitsFormat, DS.ARGS())
        .def("setAltUnitsFormat", &PyAcadDimArcLength::setAltUnitsFormat, DS.ARGS({ "format_type:PyAx.AcDimUnits" }))
        .def("altTextPrefix", &PyAcadDimArcLength::altTextPrefix, DS.ARGS())
        .def("setAltTextPrefix", &PyAcadDimArcLength::setAltTextPrefix, DS.ARGS({ "prefix:str" }))
        .def("altTextSuffix", &PyAcadDimArcLength::altTextSuffix, DS.ARGS())
        .def("setAltTextSuffix", &PyAcadDimArcLength::setAltTextSuffix, DS.ARGS({ "suffix:str" }))
        .def("dimensionLineColor", &PyAcadDimArcLength::dimensionLineColor, DS.ARGS())
        .def("setDimensionLineColor", &PyAcadDimArcLength::setDimensionLineColor, DS.ARGS({ "color:PyAx.AcColor" }))
        .def("extensionLineColor", &PyAcadDimArcLength::extensionLineColor, DS.ARGS())
        .def("setExtensionLineColor", &PyAcadDimArcLength::setExtensionLineColor, DS.ARGS({ "color:PyAx.AcColor" }))
        .def("primaryUnitsPrecision", &PyAcadDimArcLength::primaryUnitsPrecision, DS.ARGS())
        .def("setPrimaryUnitsPrecision", &PyAcadDimArcLength::setPrimaryUnitsPrecision, DS.ARGS({ "precision:PyAx.AcDimPrecision" }))
        .def("dimensionLineExtend", &PyAcadDimArcLength::dimensionLineExtend, DS.ARGS())
        .def("setDimensionLineExtend", &PyAcadDimArcLength::setDimensionLineExtend, DS.ARGS({ "extend_distance: float" }))
        .def("extensionLineExtend", &PyAcadDimArcLength::extensionLineExtend, DS.ARGS())
        .def("setExtensionLineExtend", &PyAcadDimArcLength::setExtensionLineExtend, DS.ARGS({ "extend_distance: float" }))
        .def("fit", &PyAcadDimArcLength::fit, DS.ARGS())
        .def("setFit", &PyAcadDimArcLength::setFit, DS.ARGS({ "fit_type: PyAx.AcDimFit" }))
        .def("fractionFormat", &PyAcadDimArcLength::fractionFormat, DS.ARGS())
        .def("setFractionFormat", &PyAcadDimArcLength::setFractionFormat, DS.ARGS({ "format_type: PyAx.AcDimFractionType" }))
        .def("horizontalTextPosition", &PyAcadDimArcLength::horizontalTextPosition, DS.ARGS())
        .def("setHorizontalTextPosition", &PyAcadDimArcLength::setHorizontalTextPosition, DS.ARGS({ "position: PyAx.AcDimHorizontalJustification" }))
        .def("linearScaleFactor", &PyAcadDimArcLength::linearScaleFactor, DS.ARGS())
        .def("setLinearScaleFactor", &PyAcadDimArcLength::setLinearScaleFactor, DS.ARGS({ "scale_factor:float" }))
        .def("unitsFormat", &PyAcadDimArcLength::unitsFormat, DS.ARGS())
        .def("setUnitsFormat", &PyAcadDimArcLength::setUnitsFormat, DS.ARGS({ "format_type:PyAx.AcDimLUnits" }))
        .def("extensionLineWeight", &PyAcadDimArcLength::extensionLineWeight, DS.ARGS())
        .def("setExtensionLineWeight", &PyAcadDimArcLength::setExtensionLineWeight, DS.ARGS({ "weight:PyAx.AcLineWeight" }))
        .def("roundDistance", &PyAcadDimArcLength::roundDistance, DS.ARGS())
        .def("setRoundDistance", &PyAcadDimArcLength::setRoundDistance, DS.ARGS({ "round_distance:float" }))
        .def("dimLine1Suppress", &PyAcadDimArcLength::dimLine1Suppress, DS.ARGS())
        .def("setDimLine1Suppress", &PyAcadDimArcLength::setDimLine1Suppress, DS.ARGS({ "suppress:bool" }))
        .def("dimLine2Suppress", &PyAcadDimArcLength::dimLine2Suppress, DS.ARGS())
        .def("setDimLine2Suppress", &PyAcadDimArcLength::setDimLine2Suppress, DS.ARGS({ "suppress:bool" }))
        .def("extLine1Suppress", &PyAcadDimArcLength::extLine1Suppress, DS.ARGS())
        .def("setExtLine1Suppress", &PyAcadDimArcLength::setExtLine1Suppress, DS.ARGS({ "suppress:bool" }))
        .def("extLine2Suppress", &PyAcadDimArcLength::extLine2Suppress, DS.ARGS())
        .def("setExtLine2Suppress", &PyAcadDimArcLength::setExtLine2Suppress, DS.ARGS({ "suppress:bool" }))
        .def("dimLineInside", &PyAcadDimArcLength::dimLineInside, DS.ARGS())
        .def("setDimLineInside", &PyAcadDimArcLength::setDimLineInside, DS.ARGS({ "inside:bool" }))
        .def("textInsideAlign", &PyAcadDimArcLength::textInsideAlign, DS.ARGS())
        .def("setTextInsideAlign", &PyAcadDimArcLength::setTextInsideAlign, DS.ARGS({ "align:bool" }))
        .def("textInside", &PyAcadDimArcLength::textInside, DS.ARGS())
        .def("setTextInside", &PyAcadDimArcLength::setTextInside, DS.ARGS({ "inside:bool" }))
        .def("forceLineInside", &PyAcadDimArcLength::forceLineInside, DS.ARGS())
        .def("setForceLineInside", &PyAcadDimArcLength::setForceLineInside, DS.ARGS({ "force:bool" }))
        .def("textOutsideAlign", &PyAcadDimArcLength::textOutsideAlign, DS.ARGS())
        .def("setTextOutsideAlign", &PyAcadDimArcLength::setTextOutsideAlign, DS.ARGS({ "align:bool" }))
        .def("extensionLineOffset", &PyAcadDimArcLength::extensionLineOffset, DS.ARGS())
        .def("setExtensionLineOffset", &PyAcadDimArcLength::setExtensionLineOffset, DS.ARGS({ "offset_distance:float" }))
        .def("altSuppressLeadingZeros", &PyAcadDimArcLength::altSuppressLeadingZeros, DS.ARGS())
        .def("setAltSuppressLeadingZeros", &PyAcadDimArcLength::setAltSuppressLeadingZeros, DS.ARGS({ "suppress:bool" }))
        .def("altSuppressTrailingZeros", &PyAcadDimArcLength::altSuppressTrailingZeros, DS.ARGS())
        .def("setAltSuppressTrailingZeros", &PyAcadDimArcLength::setAltSuppressTrailingZeros, DS.ARGS({ "suppress:bool" }))
        .def("altSuppressZeroFeet", &PyAcadDimArcLength::altSuppressZeroFeet, DS.ARGS())
        .def("setAltSuppressZeroFeet", &PyAcadDimArcLength::setAltSuppressZeroFeet, DS.ARGS({ "suppress:bool" }))
        .def("altSuppressZeroInches", &PyAcadDimArcLength::altSuppressZeroInches, DS.ARGS())
        .def("setAltSuppressZeroInches", &PyAcadDimArcLength::setAltSuppressZeroInches, DS.ARGS({ "suppress:bool" }))
        .def("altToleranceSuppressLeadingZeros", &PyAcadDimArcLength::altToleranceSuppressLeadingZeros, DS.ARGS())
        .def("setAltToleranceSuppressLeadingZeros", &PyAcadDimArcLength::setAltToleranceSuppressLeadingZeros, DS.ARGS({ "suppress:bool" }))
        .def("altToleranceSuppressTrailingZeros", &PyAcadDimArcLength::altToleranceSuppressTrailingZeros, DS.ARGS())
        .def("setAltToleranceSuppressTrailingZeros", &PyAcadDimArcLength::setAltToleranceSuppressTrailingZeros, DS.ARGS({ "suppress:bool" }))
        .def("altToleranceSuppressZeroFeet", &PyAcadDimArcLength::altToleranceSuppressZeroFeet, DS.ARGS())
        .def("setAltToleranceSuppressZeroFeet", &PyAcadDimArcLength::setAltToleranceSuppressZeroFeet, DS.ARGS({ "suppress:bool" }))
        .def("altToleranceSuppressZeroInches", &PyAcadDimArcLength::altToleranceSuppressZeroInches, DS.ARGS())
        .def("setAltToleranceSuppressZeroInches", &PyAcadDimArcLength::setAltToleranceSuppressZeroInches, DS.ARGS({ "suppress:bool" }))
        .def("suppressZeroFeet", &PyAcadDimArcLength::suppressZeroFeet, DS.ARGS())
        .def("setSuppressZeroFeet", &PyAcadDimArcLength::setSuppressZeroFeet, DS.ARGS({ "suppress:bool" }))
        .def("suppressZeroInches", &PyAcadDimArcLength::suppressZeroInches, DS.ARGS())
        .def("setSuppressZeroInches", &PyAcadDimArcLength::setSuppressZeroInches, DS.ARGS({ "suppress:bool" }))
        .def("toleranceSuppressZeroFeet", &PyAcadDimArcLength::toleranceSuppressZeroFeet, DS.ARGS())
        .def("setToleranceSuppressZeroFeet", &PyAcadDimArcLength::setToleranceSuppressZeroFeet, DS.ARGS({ "suppress:bool" }))
        .def("toleranceSuppressZeroInches", &PyAcadDimArcLength::toleranceSuppressZeroInches, DS.ARGS())
        .def("setToleranceSuppressZeroInches", &PyAcadDimArcLength::setToleranceSuppressZeroInches, DS.ARGS({ "suppress:bool" }))
        .def("dimensionLineWeight", &PyAcadDimArcLength::dimensionLineWeight, DS.ARGS())
        .def("setDimensionLineWeight", &PyAcadDimArcLength::setDimensionLineWeight, DS.ARGS({ "weight:PyAx.AcLineWeight" }))
        .def("arrowheadSize", &PyAcadDimArcLength::arrowheadSize, DS.ARGS())
        .def("setArrowheadSize", &PyAcadDimArcLength::setArrowheadSize, DS.ARGS({ "size:float" }))
        .def("arrowhead1Type", &PyAcadDimArcLength::arrowhead1Type, DS.ARGS())
        .def("setArrowhead1Type", &PyAcadDimArcLength::setArrowhead1Type, DS.ARGS({ "type:PyAx.AcDimArrowheadType" }))
        .def("arrowhead2Type", &PyAcadDimArcLength::arrowhead2Type, DS.ARGS())
        .def("setArrowhead2Type", &PyAcadDimArcLength::setArrowhead2Type, DS.ARGS({ "type:PyAx.AcDimArrowheadType" }))
        .def("measurement", &PyAcadDimArcLength::measurement, DS.ARGS())
        .def("arrowhead1Block", &PyAcadDimArcLength::arrowhead1Block, DS.ARGS())
        .def("setArrowhead1Block", &PyAcadDimArcLength::setArrowhead1Block, DS.ARGS({ "block_name:str" }))
        .def("arrowhead2Block", &PyAcadDimArcLength::arrowhead2Block, DS.ARGS())
        .def("setArrowhead2Block", &PyAcadDimArcLength::setArrowhead2Block, DS.ARGS({ "block_name:str" }))
        .def("dimensionLinetype", &PyAcadDimArcLength::dimensionLinetype, DS.ARGS())
        .def("setDimensionLinetype", &PyAcadDimArcLength::setDimensionLinetype, DS.ARGS({ "linetype_name:str" }))
        .def("extLine1Linetype", &PyAcadDimArcLength::extLine1Linetype, DS.ARGS())
        .def("setExtLine1Linetype", &PyAcadDimArcLength::setExtLine1Linetype, DS.ARGS({ "linetype_name:str" }))
        .def("extLine2Linetype", &PyAcadDimArcLength::extLine2Linetype, DS.ARGS())
        .def("setExtLine2Linetype", &PyAcadDimArcLength::setExtLine2Linetype, DS.ARGS({ "linetype_name:str" }))
        .def("subUnitsSuffix", &PyAcadDimArcLength::subUnitsSuffix, DS.ARGS())
        .def("setSubUnitsSuffix", &PyAcadDimArcLength::setSubUnitsSuffix, DS.ARGS({ "suffix:str" }))
        .def("altSubUnitsSuffix", &PyAcadDimArcLength::altSubUnitsSuffix, DS.ARGS())
        .def("setAltSubUnitsSuffix", &PyAcadDimArcLength::setAltSubUnitsSuffix, DS.ARGS({ "suffix:str" }))
        .def("extLineFixedLenSuppress", &PyAcadDimArcLength::extLineFixedLenSuppress, DS.ARGS())
        .def("setExtLineFixedLenSuppress", &PyAcadDimArcLength::setExtLineFixedLenSuppress, DS.ARGS({ "suppress:bool" }))
        .def("extLineFixedLen", &PyAcadDimArcLength::extLineFixedLen, DS.ARGS())
        .def("setExtLineFixedLen", &PyAcadDimArcLength::setExtLineFixedLen, DS.ARGS({ "length:float" }))
        .def("subUnitsFactor", &PyAcadDimArcLength::subUnitsFactor, DS.ARGS())
        .def("setSubUnitsFactor", &PyAcadDimArcLength::setSubUnitsFactor, DS.ARGS({ "factor:float" }))
        .def("altSubUnitsFactor", &PyAcadDimArcLength::altSubUnitsFactor, DS.ARGS())
        .def("setAltSubUnitsFactor", &PyAcadDimArcLength::setAltSubUnitsFactor, DS.ARGS({ "factor:float" }))
        .def("arcPoint", &PyAcadDimArcLength::arcPoint, DS.ARGS())
        .def("setArcPoint", &PyAcadDimArcLength::setArcPoint, DS.ARGS({ "point:PyGe.Point3d" }))
        .def("extLine1Point", &PyAcadDimArcLength::extLine1Point, DS.ARGS())
        .def("setExtLine1Point", &PyAcadDimArcLength::setExtLine1Point, DS.ARGS({ "point:PyGe.Point3d" }))
        .def("extLine2Point", &PyAcadDimArcLength::extLine2Point, DS.ARGS())
        .def("setExtLine2Point", &PyAcadDimArcLength::setExtLine2Point, DS.ARGS({ "point:PyGe.Point3d" }))
        .def("centerPoint", &PyAcadDimArcLength::centerPoint, DS.ARGS())
        .def("setCenterPoint", &PyAcadDimArcLength::setCenterPoint, DS.ARGS({ "point:PyGe.Point3d" }))
        .def("leader1Point", &PyAcadDimArcLength::leader1Point, DS.ARGS())
        .def("setLeader1Point", &PyAcadDimArcLength::setLeader1Point, DS.ARGS({ "point:PyGe.Point3d" }))
        .def("leader2Point", &PyAcadDimArcLength::leader2Point, DS.ARGS())
        .def("setLeader2Point", &PyAcadDimArcLength::setLeader2Point, DS.ARGS({ "point:PyGe.Point3d" }))
        .def("isPartial", &PyAcadDimArcLength::isPartial, DS.ARGS())
        .def("setIsPartial", &PyAcadDimArcLength::setIsPartial, DS.ARGS({ "partial:bool" }))
        .def("arcStartParam", &PyAcadDimArcLength::arcStartParam, DS.ARGS())
        .def("setArcStartParam", &PyAcadDimArcLength::setArcStartParam, DS.ARGS({ "param:float" }))
        .def("arcEndParam", &PyAcadDimArcLength::arcEndParam, DS.ARGS())
        .def("setArcEndParam", &PyAcadDimArcLength::setArcEndParam, DS.ARGS({ "param:float" }))
        .def("hasLeader", &PyAcadDimArcLength::hasLeader, DS.ARGS())
        .def("setHasLeader", &PyAcadDimArcLength::setHasLeader, DS.ARGS({ "has_leader:bool" }))
        .def("symbolPosition", &PyAcadDimArcLength::symbolPosition, DS.ARGS())
        .def("setSymbolPosition", &PyAcadDimArcLength::setSymbolPosition, DS.ARGS({ "position:PyAx.AcDimArcLengthSymbol" }))
        .def("cast", &PyAcadDimArcLength::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadDimArcLength::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadDimArcLength::PyAcadDimArcLength(std::shared_ptr<PyIAcadDimArcLengthImpl> ptr)
    : PyAcadDimension(ptr)
{
}

bool PyAcadDimArcLength::altUnits() const
{
    return impObj()->GetAltUnits();
}

void PyAcadDimArcLength::setAltUnits(bool val) const
{
    impObj()->SetAltUnits(val);
}

PyAcDimPrecision PyAcadDimArcLength::altUnitsPrecision() const
{
    return impObj()->GetAltUnitsPrecision();
}

void PyAcadDimArcLength::setAltUnitsPrecision(PyAcDimPrecision val) const
{
    impObj()->SetAltUnitsPrecision(val);
}

double PyAcadDimArcLength::altUnitsScale() const
{
    return impObj()->GetAltUnitsScale();
}

void PyAcadDimArcLength::setAltUnitsScale(double val) const
{
    impObj()->SetAltUnitsScale(val);
}

double PyAcadDimArcLength::altRoundDistance() const
{
    return impObj()->GetAltRoundDistance();
}

void PyAcadDimArcLength::setAltRoundDistance(double val) const
{
    impObj()->SetAltRoundDistance(val);
}

PyAcDimPrecision PyAcadDimArcLength::altTolerancePrecision() const
{
    return impObj()->GetAltTolerancePrecision();
}

void PyAcadDimArcLength::setAltTolerancePrecision(PyAcDimPrecision val) const
{
    impObj()->SetAltTolerancePrecision(val);
}

PyAcDimUnits PyAcadDimArcLength::altUnitsFormat() const
{
    return impObj()->GetAltUnitsFormat();
}

void PyAcadDimArcLength::setAltUnitsFormat(PyAcDimUnits val) const
{
    impObj()->SetAltUnitsFormat(val);
}

std::string PyAcadDimArcLength::altTextPrefix() const
{
    return wstr_to_utf8(impObj()->GetAltTextPrefix());
}

void PyAcadDimArcLength::setAltTextPrefix(const std::string& val) const
{
    impObj()->SetAltTextPrefix(utf8_to_wstr(val).c_str());
}

std::string PyAcadDimArcLength::altTextSuffix() const
{
    return wstr_to_utf8(impObj()->GetAltTextSuffix());
}

void PyAcadDimArcLength::setAltTextSuffix(const std::string& val) const
{
    impObj()->SetAltTextSuffix(utf8_to_wstr(val).c_str());
}

PyAcColor PyAcadDimArcLength::dimensionLineColor() const
{
    return impObj()->GetDimensionLineColor();
}

void PyAcadDimArcLength::setDimensionLineColor(PyAcColor val) const
{
    impObj()->SetDimensionLineColor(val);
}

PyAcColor PyAcadDimArcLength::extensionLineColor() const
{
    return impObj()->GetExtensionLineColor();
}

void PyAcadDimArcLength::setExtensionLineColor(PyAcColor val) const
{
    impObj()->SetExtensionLineColor(val);
}

PyAcDimPrecision PyAcadDimArcLength::primaryUnitsPrecision() const
{
    return impObj()->GetPrimaryUnitsPrecision();
}

void PyAcadDimArcLength::setPrimaryUnitsPrecision(PyAcDimPrecision val) const
{
    impObj()->SetPrimaryUnitsPrecision(val);
}

double PyAcadDimArcLength::dimensionLineExtend() const
{
    return impObj()->GetDimensionLineExtend();
}

void PyAcadDimArcLength::setDimensionLineExtend(double val) const
{
    impObj()->SetDimensionLineExtend(val);
}

double PyAcadDimArcLength::extensionLineExtend() const
{
    return impObj()->GetExtensionLineExtend();
}

void PyAcadDimArcLength::setExtensionLineExtend(double val) const
{
    impObj()->SetExtensionLineExtend(val);
}

PyAcDimFit PyAcadDimArcLength::fit() const
{
    return impObj()->GetFit();
}

void PyAcadDimArcLength::setFit(PyAcDimFit val) const
{
    impObj()->SetFit(val);
}

PyAcDimFractionType PyAcadDimArcLength::fractionFormat() const
{
    return impObj()->GetFractionFormat();
}

void PyAcadDimArcLength::setFractionFormat(PyAcDimFractionType val) const
{
    impObj()->SetFractionFormat(val);
}

PyAcDimHorizontalJustification PyAcadDimArcLength::horizontalTextPosition() const
{
    return impObj()->GetHorizontalTextPosition();
}

void PyAcadDimArcLength::setHorizontalTextPosition(PyAcDimHorizontalJustification val) const
{
    impObj()->SetHorizontalTextPosition(val);
}

double PyAcadDimArcLength::linearScaleFactor() const
{
    return impObj()->GetLinearScaleFactor();
}

void PyAcadDimArcLength::setLinearScaleFactor(double val) const
{
    impObj()->SetLinearScaleFactor(val);
}

PyAcDimLUnits PyAcadDimArcLength::unitsFormat() const
{
    return impObj()->GetUnitsFormat();
}

void PyAcadDimArcLength::setUnitsFormat(PyAcDimLUnits val) const
{
    impObj()->SetUnitsFormat(val);
}

PyAcLineWeight PyAcadDimArcLength::extensionLineWeight() const
{
    return impObj()->GetExtensionLineWeight();
}

void PyAcadDimArcLength::setExtensionLineWeight(PyAcLineWeight val) const
{
    impObj()->SetExtensionLineWeight(val);
}

double PyAcadDimArcLength::roundDistance() const
{
    return impObj()->GetRoundDistance();
}

void PyAcadDimArcLength::setRoundDistance(double val) const
{
    impObj()->SetRoundDistance(val);
}

bool PyAcadDimArcLength::dimLine1Suppress() const
{
    return impObj()->GetDimLine1Suppress();
}

void PyAcadDimArcLength::setDimLine1Suppress(bool val) const
{
    impObj()->SetDimLine1Suppress(val);
}

bool PyAcadDimArcLength::dimLine2Suppress() const
{
    return impObj()->GetDimLine2Suppress();
}

void PyAcadDimArcLength::setDimLine2Suppress(bool val) const
{
    impObj()->SetDimLine2Suppress(val);
}

bool PyAcadDimArcLength::extLine1Suppress() const
{
    return impObj()->GetExtLine1Suppress();
}

void PyAcadDimArcLength::setExtLine1Suppress(bool val) const
{
    impObj()->SetExtLine1Suppress(val);
}

bool PyAcadDimArcLength::extLine2Suppress() const
{
    return impObj()->GetExtLine2Suppress();
}

void PyAcadDimArcLength::setExtLine2Suppress(bool val) const
{
    impObj()->SetExtLine2Suppress(val);
}

bool PyAcadDimArcLength::dimLineInside() const
{
    return impObj()->GetDimLineInside();
}

void PyAcadDimArcLength::setDimLineInside(bool val) const
{
    impObj()->SetDimLineInside(val);
}

bool PyAcadDimArcLength::textInsideAlign() const
{
    return impObj()->GetTextInsideAlign();
}

void PyAcadDimArcLength::setTextInsideAlign(bool val) const
{
    impObj()->SetTextInsideAlign(val);
}

bool PyAcadDimArcLength::textInside() const
{
    return impObj()->GetTextInside();
}

void PyAcadDimArcLength::setTextInside(bool val) const
{
    impObj()->SetTextInside(val);
}

bool PyAcadDimArcLength::forceLineInside() const
{
    return impObj()->GetForceLineInside();
}

void PyAcadDimArcLength::setForceLineInside(bool val) const
{
    impObj()->SetForceLineInside(val);
}

bool PyAcadDimArcLength::textOutsideAlign() const
{
    return impObj()->GetTextOutsideAlign();
}

void PyAcadDimArcLength::setTextOutsideAlign(bool val) const
{
    impObj()->SetTextOutsideAlign(val);
}

double PyAcadDimArcLength::extensionLineOffset() const
{
    return impObj()->GetExtensionLineOffset();
}

void PyAcadDimArcLength::setExtensionLineOffset(double val) const
{
    impObj()->SetExtensionLineOffset(val);
}

bool PyAcadDimArcLength::altSuppressLeadingZeros() const
{
    return impObj()->GetAltSuppressLeadingZeros();
}

void PyAcadDimArcLength::setAltSuppressLeadingZeros(bool val) const
{
    impObj()->SetAltSuppressLeadingZeros(val);
}

bool PyAcadDimArcLength::altSuppressTrailingZeros() const
{
    return impObj()->GetAltSuppressTrailingZeros();
}

void PyAcadDimArcLength::setAltSuppressTrailingZeros(bool val) const
{
    impObj()->SetAltSuppressTrailingZeros(val);
}

bool PyAcadDimArcLength::altSuppressZeroFeet() const
{
    return impObj()->GetAltSuppressZeroFeet();
}

void PyAcadDimArcLength::setAltSuppressZeroFeet(bool val) const
{
    impObj()->SetAltSuppressZeroFeet(val);
}

bool PyAcadDimArcLength::altSuppressZeroInches() const
{
    return impObj()->GetAltSuppressZeroInches();
}

void PyAcadDimArcLength::setAltSuppressZeroInches(bool val) const
{
    impObj()->SetAltSuppressZeroInches(val);
}

bool PyAcadDimArcLength::altToleranceSuppressLeadingZeros() const
{
    return impObj()->GetAltToleranceSuppressLeadingZeros();
}

void PyAcadDimArcLength::setAltToleranceSuppressLeadingZeros(bool val) const
{
    impObj()->SetAltToleranceSuppressLeadingZeros(val);
}

bool PyAcadDimArcLength::altToleranceSuppressTrailingZeros() const
{
    return impObj()->GetAltToleranceSuppressTrailingZeros();
}

void PyAcadDimArcLength::setAltToleranceSuppressTrailingZeros(bool val) const
{
    impObj()->SetAltToleranceSuppressTrailingZeros(val);
}

bool PyAcadDimArcLength::altToleranceSuppressZeroFeet() const
{
    return impObj()->GetAltToleranceSuppressZeroFeet();
}

void PyAcadDimArcLength::setAltToleranceSuppressZeroFeet(bool val) const
{
    impObj()->SetAltToleranceSuppressZeroFeet(val);
}

bool PyAcadDimArcLength::altToleranceSuppressZeroInches() const
{
    return impObj()->GetAltToleranceSuppressZeroInches();
}

void PyAcadDimArcLength::setAltToleranceSuppressZeroInches(bool val) const
{
    impObj()->SetAltToleranceSuppressZeroInches(val);
}

bool PyAcadDimArcLength::suppressZeroFeet() const
{
    return impObj()->GetSuppressZeroFeet();
}

void PyAcadDimArcLength::setSuppressZeroFeet(bool val) const
{
    impObj()->SetSuppressZeroFeet(val);
}

bool PyAcadDimArcLength::suppressZeroInches() const
{
    return impObj()->GetSuppressZeroInches();
}

void PyAcadDimArcLength::setSuppressZeroInches(bool val) const
{
    impObj()->SetSuppressZeroInches(val);
}

bool PyAcadDimArcLength::toleranceSuppressZeroFeet() const
{
    return impObj()->GetToleranceSuppressZeroFeet();
}

void PyAcadDimArcLength::setToleranceSuppressZeroFeet(bool val) const
{
    impObj()->SetToleranceSuppressZeroFeet(val);
}

bool PyAcadDimArcLength::toleranceSuppressZeroInches() const
{
    return impObj()->GetToleranceSuppressZeroInches();
}

void PyAcadDimArcLength::setToleranceSuppressZeroInches(bool val) const
{
    impObj()->SetToleranceSuppressZeroInches(val);
}

PyAcLineWeight PyAcadDimArcLength::dimensionLineWeight() const
{
    return impObj()->GetDimensionLineWeight();
}

void PyAcadDimArcLength::setDimensionLineWeight(PyAcLineWeight val) const
{
    impObj()->SetDimensionLineWeight(val);
}

double PyAcadDimArcLength::arrowheadSize() const
{
    return impObj()->GetArrowheadSize();
}

void PyAcadDimArcLength::setArrowheadSize(double val) const
{
    impObj()->SetArrowheadSize(val);
}

PyAcDimArrowheadType PyAcadDimArcLength::arrowhead1Type() const
{
    return impObj()->GetArrowhead1Type();
}

void PyAcadDimArcLength::setArrowhead1Type(PyAcDimArrowheadType val) const
{
    impObj()->SetArrowhead1Type(val);
}

PyAcDimArrowheadType PyAcadDimArcLength::arrowhead2Type() const
{
    return impObj()->GetArrowhead2Type();
}

void PyAcadDimArcLength::setArrowhead2Type(PyAcDimArrowheadType val) const
{
    impObj()->SetArrowhead2Type(val);
}

double PyAcadDimArcLength::measurement() const
{
    return impObj()->GetMeasurement();
}

std::string PyAcadDimArcLength::arrowhead1Block() const
{
    return wstr_to_utf8(impObj()->GetArrowhead1Block());
}

void PyAcadDimArcLength::setArrowhead1Block(const std::string& val) const
{
    impObj()->SetArrowhead1Block(utf8_to_wstr(val).c_str());
}

std::string PyAcadDimArcLength::arrowhead2Block() const
{
    return wstr_to_utf8(impObj()->GetArrowhead2Block());
}

void PyAcadDimArcLength::setArrowhead2Block(const std::string& val) const
{
    impObj()->SetArrowhead2Block(utf8_to_wstr(val).c_str());
}

std::string PyAcadDimArcLength::dimensionLinetype() const
{
    return wstr_to_utf8(impObj()->GetDimensionLinetype());
}

void PyAcadDimArcLength::setDimensionLinetype(const std::string& val) const
{
    impObj()->SetDimensionLinetype(utf8_to_wstr(val).c_str());
}

std::string PyAcadDimArcLength::extLine1Linetype() const
{
    return wstr_to_utf8(impObj()->GetExtLine1Linetype());
}

void PyAcadDimArcLength::setExtLine1Linetype(const std::string& val) const
{
    impObj()->SetExtLine1Linetype(utf8_to_wstr(val).c_str());
}

std::string PyAcadDimArcLength::extLine2Linetype() const
{
    return wstr_to_utf8(impObj()->GetExtLine2Linetype());
}

void PyAcadDimArcLength::setExtLine2Linetype(const std::string& val) const
{
    impObj()->SetExtLine2Linetype(utf8_to_wstr(val).c_str());
}

std::string PyAcadDimArcLength::subUnitsSuffix() const
{
    return wstr_to_utf8(impObj()->GetSubUnitsSuffix());
}

void PyAcadDimArcLength::setSubUnitsSuffix(const std::string& val) const
{
    impObj()->SetSubUnitsSuffix(utf8_to_wstr(val).c_str());
}

std::string PyAcadDimArcLength::altSubUnitsSuffix() const
{
    return wstr_to_utf8(impObj()->GetAltSubUnitsSuffix());
}

void PyAcadDimArcLength::setAltSubUnitsSuffix(const std::string& val) const
{
    impObj()->SetAltSubUnitsSuffix(utf8_to_wstr(val).c_str());
}

bool PyAcadDimArcLength::extLineFixedLenSuppress() const
{
    return impObj()->GetExtLineFixedLenSuppress();
}

void PyAcadDimArcLength::setExtLineFixedLenSuppress(bool val) const
{
    impObj()->SetExtLineFixedLenSuppress(val);
}

double PyAcadDimArcLength::extLineFixedLen() const
{
    return impObj()->GetExtLineFixedLen();
}

void PyAcadDimArcLength::setExtLineFixedLen(double val) const
{
    impObj()->SetExtLineFixedLen(val);
}

double PyAcadDimArcLength::subUnitsFactor() const
{
    return impObj()->GetSubUnitsFactor();
}

void PyAcadDimArcLength::setSubUnitsFactor(double val) const
{
    impObj()->SetSubUnitsFactor(val);
}

double PyAcadDimArcLength::altSubUnitsFactor() const
{
    return impObj()->GetAltSubUnitsFactor();
}

void PyAcadDimArcLength::setAltSubUnitsFactor(double val) const
{
    impObj()->SetAltSubUnitsFactor(val);
}

AcGePoint3d PyAcadDimArcLength::arcPoint() const
{
    return impObj()->GetArcPoint();
}

void PyAcadDimArcLength::setArcPoint(const AcGePoint3d& val) const
{
    impObj()->SetArcPoint(val);
}

AcGePoint3d PyAcadDimArcLength::extLine1Point() const
{
    return impObj()->GetExtLine1Point();
}

void PyAcadDimArcLength::setExtLine1Point(const AcGePoint3d& val) const
{
    impObj()->SetExtLine1Point(val);
}

AcGePoint3d PyAcadDimArcLength::extLine2Point() const
{
    return impObj()->GetExtLine2Point();
}

void PyAcadDimArcLength::setExtLine2Point(const AcGePoint3d& val) const
{
    impObj()->SetExtLine2Point(val);
}

AcGePoint3d PyAcadDimArcLength::centerPoint() const
{
    return impObj()->GetCenterPoint();
}

void PyAcadDimArcLength::setCenterPoint(const AcGePoint3d& val) const
{
    impObj()->SetCenterPoint(val);
}

AcGePoint3d PyAcadDimArcLength::leader1Point() const
{
    return impObj()->GetLeader1Point();
}

void PyAcadDimArcLength::setLeader1Point(const AcGePoint3d& val) const
{
    impObj()->SetLeader1Point(val);
}

AcGePoint3d PyAcadDimArcLength::leader2Point() const
{
    return impObj()->GetLeader2Point();
}

void PyAcadDimArcLength::setLeader2Point(const AcGePoint3d& val) const
{
    impObj()->SetLeader2Point(val);
}

bool PyAcadDimArcLength::isPartial() const
{
    return impObj()->GetIsPartial();
}

void PyAcadDimArcLength::setIsPartial(bool val) const
{
    impObj()->SetIsPartial(val);
}

double PyAcadDimArcLength::arcStartParam() const
{
    return impObj()->GetArcStartParam();
}

void PyAcadDimArcLength::setArcStartParam(double val) const
{
    impObj()->SetArcStartParam(val);
}

double PyAcadDimArcLength::arcEndParam() const
{
    return impObj()->GetArcEndParam();
}

void PyAcadDimArcLength::setArcEndParam(double val) const
{
    impObj()->SetArcEndParam(val);
}

bool PyAcadDimArcLength::hasLeader() const
{
    return impObj()->GetHasLeader();
}

void PyAcadDimArcLength::setHasLeader(bool val) const
{
    impObj()->SetHasLeader(val);
}

PyAcDimArcLengthSymbol PyAcadDimArcLength::symbolPosition() const
{
    return impObj()->GetSymbolPosition();
}

void PyAcadDimArcLength::setSymbolPosition(const PyAcDimArcLengthSymbol& val) const
{
    impObj()->SetSymbolPosition(val);
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
        .def("altUnits", &PyAcadDimRadialLarge::altUnits, DS.ARGS())
        .def("setAltUnits", &PyAcadDimRadialLarge::setAltUnits, DS.ARGS({ "alternate_units:bool" }))
        .def("altUnitsPrecision", &PyAcadDimRadialLarge::altUnitsPrecision, DS.ARGS())
        .def("setAltUnitsPrecision", &PyAcadDimRadialLarge::setAltUnitsPrecision, DS.ARGS({ "precision:PyAx.AcDimPrecision" }))
        .def("altUnitsScale", &PyAcadDimRadialLarge::altUnitsScale, DS.ARGS())
        .def("setAltUnitsScale", &PyAcadDimRadialLarge::setAltUnitsScale, DS.ARGS({ "scale_factor:float" }))
        .def("altRoundDistance", &PyAcadDimRadialLarge::altRoundDistance, DS.ARGS())
        .def("setAltRoundDistance", &PyAcadDimRadialLarge::setAltRoundDistance, DS.ARGS({ "round_distance:float" }))
        .def("altTolerancePrecision", &PyAcadDimRadialLarge::altTolerancePrecision, DS.ARGS())
        .def("setAltTolerancePrecision", &PyAcadDimRadialLarge::setAltTolerancePrecision, DS.ARGS({ "tolerance_precision:PyAx.AcDimPrecision" }))
        .def("altUnitsFormat", &PyAcadDimRadialLarge::altUnitsFormat, DS.ARGS())
        .def("setAltUnitsFormat", &PyAcadDimRadialLarge::setAltUnitsFormat, DS.ARGS({ "format:PyAx.AcDimUnits" }))
        .def("altTextPrefix", &PyAcadDimRadialLarge::altTextPrefix, DS.ARGS())
        .def("setAltTextPrefix", &PyAcadDimRadialLarge::setAltTextPrefix, DS.ARGS({ "prefix:str" }))
        .def("altTextSuffix", &PyAcadDimRadialLarge::altTextSuffix, DS.ARGS())
        .def("setAltTextSuffix", &PyAcadDimRadialLarge::setAltTextSuffix, DS.ARGS({ "suffix:str" }))
        .def("centerType", &PyAcadDimRadialLarge::centerType, DS.ARGS())
        .def("setCenterType", &PyAcadDimRadialLarge::setCenterType, DS.ARGS({ "type:PyAx.AcDimCenterType" }))
        .def("centerMarkSize", &PyAcadDimRadialLarge::centerMarkSize, DS.ARGS())
        .def("setCenterMarkSize", &PyAcadDimRadialLarge::setCenterMarkSize, DS.ARGS({ "size:float" }))
        .def("dimensionLineColor", &PyAcadDimRadialLarge::dimensionLineColor, DS.ARGS())
        .def("setDimensionLineColor", &PyAcadDimRadialLarge::setDimensionLineColor, DS.ARGS({ "color:PyAx.AcColor" }))
        .def("primaryUnitsPrecision", &PyAcadDimRadialLarge::primaryUnitsPrecision, DS.ARGS())
        .def("setPrimaryUnitsPrecision", &PyAcadDimRadialLarge::setPrimaryUnitsPrecision, DS.ARGS({ "precision:PyAx.AcDimPrecision" }))
        .def("fractionFormat", &PyAcadDimRadialLarge::fractionFormat, DS.ARGS())
        .def("setFractionFormat", &PyAcadDimRadialLarge::setFractionFormat, DS.ARGS({ "format:PyAx.AcDimFractionType" }))
        .def("fit", &PyAcadDimRadialLarge::fit, DS.ARGS())
        .def("setFit", &PyAcadDimRadialLarge::setFit, DS.ARGS({ "fit_type:PyAx.AcDimFit" }))
        .def("linearScaleFactor", &PyAcadDimRadialLarge::linearScaleFactor, DS.ARGS())
        .def("setLinearScaleFactor", &PyAcadDimRadialLarge::setLinearScaleFactor, DS.ARGS({ "scale_factor:float" }))
        .def("unitsFormat", &PyAcadDimRadialLarge::unitsFormat, DS.ARGS())
        .def("setUnitsFormat", &PyAcadDimRadialLarge::setUnitsFormat, DS.ARGS({ "format:PyAx.AcDimLUnits" }))
        .def("roundDistance", &PyAcadDimRadialLarge::roundDistance, DS.ARGS())
        .def("setRoundDistance", &PyAcadDimRadialLarge::setRoundDistance, DS.ARGS({ "round_distance:float" }))
        .def("dimLineSuppress", &PyAcadDimRadialLarge::dimLineSuppress, DS.ARGS())
        .def("setDimLineSuppress", &PyAcadDimRadialLarge::setDimLineSuppress, DS.ARGS({ "suppress:bool" }))
        .def("textInsideAlign", &PyAcadDimRadialLarge::textInsideAlign, DS.ARGS())
        .def("setTextInsideAlign", &PyAcadDimRadialLarge::setTextInsideAlign, DS.ARGS({ "align:bool" }))
        .def("textInside", &PyAcadDimRadialLarge::textInside, DS.ARGS())
        .def("setTextInside", &PyAcadDimRadialLarge::setTextInside, DS.ARGS({ "inside:bool" }))
        .def("forceLineInside", &PyAcadDimRadialLarge::forceLineInside, DS.ARGS())
        .def("setForceLineInside", &PyAcadDimRadialLarge::setForceLineInside, DS.ARGS({ "force:bool" }))
        .def("textOutsideAlign", &PyAcadDimRadialLarge::textOutsideAlign, DS.ARGS())
        .def("setTextOutsideAlign", &PyAcadDimRadialLarge::setTextOutsideAlign, DS.ARGS({ "align:bool" }))
        .def("altSuppressLeadingZeros", &PyAcadDimRadialLarge::altSuppressLeadingZeros, DS.ARGS())
        .def("setAltSuppressLeadingZeros", &PyAcadDimRadialLarge::setAltSuppressLeadingZeros, DS.ARGS({ "suppress:bool" }))
        .def("altSuppressTrailingZeros", &PyAcadDimRadialLarge::altSuppressTrailingZeros, DS.ARGS())
        .def("setAltSuppressTrailingZeros", &PyAcadDimRadialLarge::setAltSuppressTrailingZeros, DS.ARGS({ "suppress:bool" }))
        .def("altSuppressZeroFeet", &PyAcadDimRadialLarge::altSuppressZeroFeet, DS.ARGS())
        .def("setAltSuppressZeroFeet", &PyAcadDimRadialLarge::setAltSuppressZeroFeet, DS.ARGS({ "suppress:bool" }))
        .def("altSuppressZeroInches", &PyAcadDimRadialLarge::altSuppressZeroInches, DS.ARGS())
        .def("setAltSuppressZeroInches", &PyAcadDimRadialLarge::setAltSuppressZeroInches, DS.ARGS({ "suppress:bool" }))
        .def("altToleranceSuppressLeadingZeros", &PyAcadDimRadialLarge::altToleranceSuppressLeadingZeros, DS.ARGS())
        .def("setAltToleranceSuppressLeadingZeros", &PyAcadDimRadialLarge::setAltToleranceSuppressLeadingZeros, DS.ARGS({ "suppress:bool" }))
        .def("altToleranceSuppressTrailingZeros", &PyAcadDimRadialLarge::altToleranceSuppressTrailingZeros, DS.ARGS())
        .def("setAltToleranceSuppressTrailingZeros", &PyAcadDimRadialLarge::setAltToleranceSuppressTrailingZeros, DS.ARGS({ "suppress:bool" }))
        .def("altToleranceSuppressZeroFeet", &PyAcadDimRadialLarge::altToleranceSuppressZeroFeet, DS.ARGS())
        .def("setAltToleranceSuppressZeroFeet", &PyAcadDimRadialLarge::setAltToleranceSuppressZeroFeet, DS.ARGS({ "suppress:bool" }))
        .def("altToleranceSuppressZeroInches", &PyAcadDimRadialLarge::altToleranceSuppressZeroInches, DS.ARGS())
        .def("setAltToleranceSuppressZeroInches", &PyAcadDimRadialLarge::setAltToleranceSuppressZeroInches, DS.ARGS({ "suppress:bool" }))
        .def("suppressZeroFeet", &PyAcadDimRadialLarge::suppressZeroFeet, DS.ARGS())
        .def("setSuppressZeroFeet", &PyAcadDimRadialLarge::setSuppressZeroFeet, DS.ARGS({ "suppress:bool" }))
        .def("suppressZeroInches", &PyAcadDimRadialLarge::suppressZeroInches, DS.ARGS())
        .def("setSuppressZeroInches", &PyAcadDimRadialLarge::setSuppressZeroInches, DS.ARGS({ "suppress:bool" }))
        .def("toleranceSuppressZeroFeet", &PyAcadDimRadialLarge::toleranceSuppressZeroFeet, DS.ARGS())
        .def("setToleranceSuppressZeroFeet", &PyAcadDimRadialLarge::setToleranceSuppressZeroFeet, DS.ARGS({ "suppress:bool" }))
        .def("toleranceSuppressZeroInches", &PyAcadDimRadialLarge::toleranceSuppressZeroInches, DS.ARGS())
        .def("setToleranceSuppressZeroInches", &PyAcadDimRadialLarge::setToleranceSuppressZeroInches, DS.ARGS({ "suppress:bool" }))
        .def("dimensionLineWeight", &PyAcadDimRadialLarge::dimensionLineWeight, DS.ARGS())
        .def("setDimensionLineWeight", &PyAcadDimRadialLarge::setDimensionLineWeight, DS.ARGS({ "weight:PyAx.AcLineWeight" }))
        .def("arrowheadSize", &PyAcadDimRadialLarge::arrowheadSize, DS.ARGS())
        .def("setArrowheadSize", &PyAcadDimRadialLarge::setArrowheadSize, DS.ARGS({ "size:float" }))
        .def("arrowheadType", &PyAcadDimRadialLarge::arrowheadType, DS.ARGS())
        .def("setArrowheadType", &PyAcadDimRadialLarge::setArrowheadType, DS.ARGS({ "arrowhead_type:PyAx.AcDimArrowheadType" }))
        .def("measurement", &PyAcadDimRadialLarge::measurement, DS.ARGS())
        .def("arrowheadBlock", &PyAcadDimRadialLarge::arrowheadBlock, DS.ARGS())
        .def("setArrowheadBlock", &PyAcadDimRadialLarge::setArrowheadBlock, DS.ARGS({ "block_type:PyAx.AcDimArrowheadType" }))
        .def("overrideCenter", &PyAcadDimRadialLarge::overrideCenter, DS.ARGS())
        .def("setOverrideCenter", &PyAcadDimRadialLarge::setOverrideCenter, DS.ARGS({ "center_point:PyGe.Point3d" }))
        .def("jogLocation", &PyAcadDimRadialLarge::jogLocation, DS.ARGS())
        .def("setJogLocation", &PyAcadDimRadialLarge::setJogLocation, DS.ARGS({ "location:PyGe.Point3d" }))
        .def("jogAngle", &PyAcadDimRadialLarge::jogAngle, DS.ARGS())
        .def("setJogAngle", &PyAcadDimRadialLarge::setJogAngle, DS.ARGS({ "angle:float" }))
        .def("center", &PyAcadDimRadialLarge::center, DS.ARGS())
        .def("setCenter", &PyAcadDimRadialLarge::setCenter, DS.ARGS({ "center_point:PyGe.Point3d" }))
        .def("chordPoint", &PyAcadDimRadialLarge::chordPoint, DS.ARGS())
        .def("setChordPoint", &PyAcadDimRadialLarge::setChordPoint, DS.ARGS({ "chord_point:PyGe.Point3d" }))
        .def("dimensionLinetype", &PyAcadDimRadialLarge::dimensionLinetype, DS.ARGS())
        .def("setDimensionLinetype", &PyAcadDimRadialLarge::setDimensionLinetype, DS.ARGS({ "linetype_name:str" }))
        .def("cast", &PyAcadDimRadialLarge::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadDimRadialLarge::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadDimRadialLarge::PyAcadDimRadialLarge(std::shared_ptr<PyIAcadDimRadialLargeImpl> ptr)
    : PyAcadDimension(ptr)
{
}

bool PyAcadDimRadialLarge::altUnits() const
{
    return impObj()->GetAltUnits();
}

void PyAcadDimRadialLarge::setAltUnits(bool val) const
{
    impObj()->SetAltUnits(val);
}

PyAcDimPrecision PyAcadDimRadialLarge::altUnitsPrecision() const
{
    return impObj()->GetAltUnitsPrecision();
}

void PyAcadDimRadialLarge::setAltUnitsPrecision(PyAcDimPrecision val) const
{
    impObj()->SetAltUnitsPrecision(val);
}

double PyAcadDimRadialLarge::altUnitsScale() const
{
    return impObj()->GetAltUnitsScale();
}

void PyAcadDimRadialLarge::setAltUnitsScale(double val) const
{
    impObj()->SetAltUnitsScale(val);
}

double PyAcadDimRadialLarge::altRoundDistance() const
{
    return impObj()->GetAltRoundDistance();
}

void PyAcadDimRadialLarge::setAltRoundDistance(double val) const
{
    impObj()->SetAltRoundDistance(val);
}

PyAcDimPrecision PyAcadDimRadialLarge::altTolerancePrecision() const
{
    return impObj()->GetAltTolerancePrecision();
}

void PyAcadDimRadialLarge::setAltTolerancePrecision(PyAcDimPrecision val) const
{
    impObj()->SetAltTolerancePrecision(val);
}

PyAcDimUnits PyAcadDimRadialLarge::altUnitsFormat() const
{
    return impObj()->GetAltUnitsFormat();
}

void PyAcadDimRadialLarge::setAltUnitsFormat(PyAcDimUnits val) const
{
    impObj()->SetAltUnitsFormat(val);
}

std::string PyAcadDimRadialLarge::altTextPrefix() const
{
    return wstr_to_utf8(impObj()->GetAltTextPrefix());
}

void PyAcadDimRadialLarge::setAltTextPrefix(const std::string& val) const
{
    impObj()->SetAltTextPrefix(utf8_to_wstr(val).c_str());
}

std::string PyAcadDimRadialLarge::altTextSuffix() const
{
    return wstr_to_utf8(impObj()->GetAltTextSuffix());
}

void PyAcadDimRadialLarge::setAltTextSuffix(const std::string& val) const
{
    impObj()->SetAltTextSuffix(utf8_to_wstr(val).c_str());
}

PyAcDimCenterType PyAcadDimRadialLarge::centerType() const
{
    return impObj()->GetCenterType();
}

void PyAcadDimRadialLarge::setCenterType(PyAcDimCenterType val) const
{
    impObj()->SetCenterType(val);
}

double PyAcadDimRadialLarge::centerMarkSize() const
{
    return impObj()->GetCenterMarkSize();
}

void PyAcadDimRadialLarge::setCenterMarkSize(double val) const
{
    impObj()->SetCenterMarkSize(val);
}

PyAcColor PyAcadDimRadialLarge::dimensionLineColor() const
{
    return impObj()->GetDimensionLineColor();
}

void PyAcadDimRadialLarge::setDimensionLineColor(PyAcColor val) const
{
    impObj()->SetDimensionLineColor(val);
}

PyAcDimPrecision PyAcadDimRadialLarge::primaryUnitsPrecision() const
{
    return impObj()->GetPrimaryUnitsPrecision();
}

void PyAcadDimRadialLarge::setPrimaryUnitsPrecision(PyAcDimPrecision val) const
{
    impObj()->SetPrimaryUnitsPrecision(val);
}

PyAcDimFractionType PyAcadDimRadialLarge::fractionFormat() const
{
    return impObj()->GetFractionFormat();
}

void PyAcadDimRadialLarge::setFractionFormat(PyAcDimFractionType val) const
{
    impObj()->SetFractionFormat(val);
}

PyAcDimFit PyAcadDimRadialLarge::fit() const
{
    return impObj()->GetFit();
}

void PyAcadDimRadialLarge::setFit(PyAcDimFit val) const
{
    impObj()->SetFit(val);
}

double PyAcadDimRadialLarge::linearScaleFactor() const
{
    return impObj()->GetLinearScaleFactor();
}

void PyAcadDimRadialLarge::setLinearScaleFactor(double val) const
{
    impObj()->SetLinearScaleFactor(val);
}

PyAcDimLUnits PyAcadDimRadialLarge::unitsFormat() const
{
    return impObj()->GetUnitsFormat();
}

void PyAcadDimRadialLarge::setUnitsFormat(PyAcDimLUnits val) const
{
    impObj()->SetUnitsFormat(val);
}

double PyAcadDimRadialLarge::roundDistance() const
{
    return impObj()->GetRoundDistance();
}

void PyAcadDimRadialLarge::setRoundDistance(double val) const
{
    impObj()->SetRoundDistance(val);
}

bool PyAcadDimRadialLarge::dimLineSuppress() const
{
    return impObj()->GetDimLineSuppress();
}

void PyAcadDimRadialLarge::setDimLineSuppress(bool val) const
{
    impObj()->SetDimLineSuppress(val);
}

bool PyAcadDimRadialLarge::textInsideAlign() const
{
    return impObj()->GetTextInsideAlign();
}

void PyAcadDimRadialLarge::setTextInsideAlign(bool val) const
{
    impObj()->SetTextInsideAlign(val);
}

bool PyAcadDimRadialLarge::textInside() const
{
    return impObj()->GetTextInside();
}

void PyAcadDimRadialLarge::setTextInside(bool val) const
{
    impObj()->SetTextInside(val);
}

bool PyAcadDimRadialLarge::forceLineInside() const
{
    return impObj()->GetForceLineInside();
}

void PyAcadDimRadialLarge::setForceLineInside(bool val) const
{
    impObj()->SetForceLineInside(val);
}

bool PyAcadDimRadialLarge::textOutsideAlign() const
{
    return impObj()->GetTextOutsideAlign();
}

void PyAcadDimRadialLarge::setTextOutsideAlign(bool val) const
{
    impObj()->SetTextOutsideAlign(val);
}

bool PyAcadDimRadialLarge::altSuppressLeadingZeros() const
{
    return impObj()->GetAltSuppressLeadingZeros();
}

void PyAcadDimRadialLarge::setAltSuppressLeadingZeros(bool val) const
{
    impObj()->SetAltSuppressLeadingZeros(val);
}

bool PyAcadDimRadialLarge::altSuppressTrailingZeros() const
{
    return impObj()->GetAltSuppressTrailingZeros();
}

void PyAcadDimRadialLarge::setAltSuppressTrailingZeros(bool val) const
{
    impObj()->SetAltSuppressTrailingZeros(val);
}

bool PyAcadDimRadialLarge::altSuppressZeroFeet() const
{
    return impObj()->GetAltSuppressZeroFeet();
}

void PyAcadDimRadialLarge::setAltSuppressZeroFeet(bool val) const
{
    impObj()->SetAltSuppressZeroFeet(val);
}

bool PyAcadDimRadialLarge::altSuppressZeroInches() const
{
    return impObj()->GetAltSuppressZeroInches();
}

void PyAcadDimRadialLarge::setAltSuppressZeroInches(bool val) const
{
    impObj()->SetAltSuppressZeroInches(val);
}

bool PyAcadDimRadialLarge::altToleranceSuppressLeadingZeros() const
{
    return impObj()->GetAltToleranceSuppressLeadingZeros();
}

void PyAcadDimRadialLarge::setAltToleranceSuppressLeadingZeros(bool val) const
{
    impObj()->SetAltToleranceSuppressLeadingZeros(val);
}

bool PyAcadDimRadialLarge::altToleranceSuppressTrailingZeros() const
{
    return impObj()->GetAltToleranceSuppressTrailingZeros();
}

void PyAcadDimRadialLarge::setAltToleranceSuppressTrailingZeros(bool val) const
{
    impObj()->SetAltToleranceSuppressTrailingZeros(val);
}

bool PyAcadDimRadialLarge::altToleranceSuppressZeroFeet() const
{
    return impObj()->GetAltToleranceSuppressZeroFeet();
}

void PyAcadDimRadialLarge::setAltToleranceSuppressZeroFeet(bool val) const
{
    impObj()->SetAltToleranceSuppressZeroFeet(val);
}

bool PyAcadDimRadialLarge::altToleranceSuppressZeroInches() const
{
    return impObj()->GetAltToleranceSuppressZeroInches();
}

void PyAcadDimRadialLarge::setAltToleranceSuppressZeroInches(bool val) const
{
    impObj()->SetAltToleranceSuppressZeroInches(val);
}

bool PyAcadDimRadialLarge::suppressZeroFeet() const
{
    return impObj()->GetSuppressZeroFeet();
}

void PyAcadDimRadialLarge::setSuppressZeroFeet(bool val) const
{
    impObj()->SetSuppressZeroFeet(val);
}

bool PyAcadDimRadialLarge::suppressZeroInches() const
{
    return impObj()->GetSuppressZeroInches();
}

void PyAcadDimRadialLarge::setSuppressZeroInches(bool val) const
{
    impObj()->SetSuppressZeroInches(val);
}

bool PyAcadDimRadialLarge::toleranceSuppressZeroFeet() const
{
    return impObj()->GetToleranceSuppressZeroFeet();
}

void PyAcadDimRadialLarge::setToleranceSuppressZeroFeet(bool val) const
{
    impObj()->SetToleranceSuppressZeroFeet(val);
}

bool PyAcadDimRadialLarge::toleranceSuppressZeroInches() const
{
    return impObj()->GetToleranceSuppressZeroInches();
}

void PyAcadDimRadialLarge::setToleranceSuppressZeroInches(bool val) const
{
    impObj()->SetToleranceSuppressZeroInches(val);
}

PyAcLineWeight PyAcadDimRadialLarge::dimensionLineWeight() const
{
    return impObj()->GetDimensionLineWeight();
}

void PyAcadDimRadialLarge::setDimensionLineWeight(PyAcLineWeight val) const
{
    impObj()->SetDimensionLineWeight(val);
}

double PyAcadDimRadialLarge::arrowheadSize() const
{
    return impObj()->GetArrowheadSize();
}

void PyAcadDimRadialLarge::setArrowheadSize(double val) const
{
    impObj()->SetArrowheadSize(val);
}

PyAcDimArrowheadType PyAcadDimRadialLarge::arrowheadType() const
{
    return impObj()->GetArrowheadType();
}

void PyAcadDimRadialLarge::setArrowheadType(PyAcDimArrowheadType val) const
{
    impObj()->SetArrowheadType(val);
}

double PyAcadDimRadialLarge::measurement() const
{
    return impObj()->GetMeasurement();
}

std::string PyAcadDimRadialLarge::arrowheadBlock() const
{
    return wstr_to_utf8(impObj()->GetArrowheadBlock());
}

void PyAcadDimRadialLarge::setArrowheadBlock(const std::string& val) const
{
    impObj()->SetArrowheadBlock(utf8_to_wstr(val).c_str());
}

AcGePoint3d PyAcadDimRadialLarge::overrideCenter() const
{
    return impObj()->GetOverrideCenter();
}

void PyAcadDimRadialLarge::setOverrideCenter(const AcGePoint3d& val) const
{
    impObj()->SetOverrideCenter(val);
}

AcGePoint3d PyAcadDimRadialLarge::jogLocation() const
{
    return impObj()->GetJogLocation();
}

void PyAcadDimRadialLarge::setJogLocation(const AcGePoint3d& val) const
{
    impObj()->SetJogLocation(val);
}

double PyAcadDimRadialLarge::jogAngle() const
{
    return impObj()->GetJogAngle();
}

void PyAcadDimRadialLarge::setJogAngle(double val) const
{
    impObj()->SetJogAngle(val);
}

AcGePoint3d PyAcadDimRadialLarge::center() const
{
    return impObj()->GetCenter();
}

void PyAcadDimRadialLarge::setCenter(const AcGePoint3d& val) const
{
    impObj()->SetCenter(val);
}

AcGePoint3d PyAcadDimRadialLarge::chordPoint() const
{
    return impObj()->GetChordPoint();
}

void PyAcadDimRadialLarge::setChordPoint(const AcGePoint3d& val) const
{
    impObj()->SetChordPoint(val);
}

std::string PyAcadDimRadialLarge::dimensionLinetype() const
{
    return wstr_to_utf8(impObj()->GetDimensionLinetype());
}

void PyAcadDimRadialLarge::setDimensionLinetype(const std::string& val) const
{
    impObj()->SetDimensionLinetype(utf8_to_wstr(val).c_str());
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