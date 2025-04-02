#include "stdafx.h"
#include "PyAcadDimensionImpl.h" 

//------------------------------------------------------------------------------------
//PyIAcadDimensionImpl
PyIAcadDimensionImpl::PyIAcadDimensionImpl(IAcadDimension* ptr)
    : PyIAcadEntityImpl(ptr)
{
}

AcGeVector3d PyIAcadDimensionImpl::GetNormal() const
{
    AcGeVector3d val;
    _variant_t coord;
    PyThrowBadHr(impObj()->get_Normal(&coord.GetVARIANT()));
    PyThrowBadHr(VariantToAcGeVector3d(coord, val));
    return val;
}

void PyIAcadDimensionImpl::SetNormal(const AcGeVector3d& val) const
{
    _variant_t vtval;
    PyThrowBadHr(AcGeVector3dToVariant(vtval.GetVARIANT(), val));
    PyThrowBadHr(impObj()->put_Normal(vtval));
}

double PyIAcadDimensionImpl::GetRotation() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_Rotation(&rtval));
    return rtval;
}

void PyIAcadDimensionImpl::SetRotation(double val) const
{
    PyThrowBadHr(impObj()->put_Rotation(val));
}

AcGePoint3d PyIAcadDimensionImpl::GetTextPosition() const
{
    _variant_t vtval;
    AcGePoint3d rtVal;
    PyThrowBadHr(impObj()->get_TextPosition(&vtval));
    PyThrowBadHr(VariantToAcGePoint3d(vtval, rtVal));
    return rtVal;
}

void PyIAcadDimensionImpl::SetTextPosition(const AcGePoint3d& val) const
{
    _variant_t vtval;
    PyThrowBadHr(AcGePoint3dToVariant(vtval.GetVARIANT(), val));
    PyThrowBadHr(impObj()->put_TextPosition(vtval));
}

double PyIAcadDimensionImpl::GetTextRotation() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_TextRotation(&rtval));
    return rtval;
}

void PyIAcadDimensionImpl::SetTextRotation(double val) const
{
    PyThrowBadHr(impObj()->put_TextRotation(val));
}

CString PyIAcadDimensionImpl::GetTextOverride() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_TextOverride(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadDimensionImpl::SetTextOverride(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_TextOverride(bstrval));
}

CString PyIAcadDimensionImpl::GetStyleName() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_StyleName(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadDimensionImpl::SetStyleName(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_StyleName(bstrval));
}

PyAcColor PyIAcadDimensionImpl::GetTextColor() const
{
    AcColor rtVal = (AcColor)PyAcColor::pyacByLayer;
    PyThrowBadHr(impObj()->get_TextColor(&rtVal));
    return (PyAcColor)rtVal;
}

void PyIAcadDimensionImpl::SetTextColor(PyAcColor val) const
{
    PyThrowBadHr(impObj()->put_TextColor((AcColor)val));
}

CString PyIAcadDimensionImpl::GetDecimalSeparator() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_DecimalSeparator(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadDimensionImpl::SetDecimalSeparator(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_DecimalSeparator(bstrval));
}

double PyIAcadDimensionImpl::GetTextGap() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_TextGap(&rtval));
    return rtval;
}

void PyIAcadDimensionImpl::SetTextGap(double val) const
{
    PyThrowBadHr(impObj()->put_TextGap(val));
}

CString PyIAcadDimensionImpl::GetTextPrefix() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_TextPrefix(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadDimensionImpl::SetTextPrefix(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_TextPrefix(bstrval));
}

CString PyIAcadDimensionImpl::GetTextSuffix() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_TextSuffix(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadDimensionImpl::SetTextSuffix(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_TextSuffix(bstrval));
}

double PyIAcadDimensionImpl::GetScaleFactor() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_ScaleFactor(&rtval));
    return rtval;
}

void PyIAcadDimensionImpl::SetScaleFactor(double val) const
{
    PyThrowBadHr(impObj()->put_ScaleFactor(val));
}

PyAcDimVerticalJustification PyIAcadDimensionImpl::GetVerticalTextPosition() const
{
    AcDimVerticalJustification rtVal = (AcDimVerticalJustification)PyAcDimVerticalJustification::pyacVertCentered;
    PyThrowBadHr(impObj()->get_VerticalTextPosition(&rtVal));
    return (PyAcDimVerticalJustification)rtVal;
}

void PyIAcadDimensionImpl::SetVerticalTextPosition(PyAcDimVerticalJustification val) const
{
    PyThrowBadHr(impObj()->put_VerticalTextPosition((AcDimVerticalJustification)val));
}

PyAcDimPrecision PyIAcadDimensionImpl::GetTolerancePrecision() const
{
    AcDimPrecision rtval = (AcDimPrecision)PyAcDimPrecision::pyacDimPrecisionZero;
    PyThrowBadHr(impObj()->get_TolerancePrecision(&rtval));
    return (PyAcDimPrecision)rtval;
}

void PyIAcadDimensionImpl::SetTolerancePrecision(PyAcDimPrecision val) const
{
    PyThrowBadHr(impObj()->put_TolerancePrecision((AcDimPrecision)val));
}

double PyIAcadDimensionImpl::GetToleranceHeightScale() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_ToleranceHeightScale(&rtval));
    return rtval;
}

void PyIAcadDimensionImpl::SetToleranceHeightScale(double val) const
{
    PyThrowBadHr(impObj()->put_ToleranceHeightScale(val));
}

double PyIAcadDimensionImpl::GetToleranceLowerLimit() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_ToleranceLowerLimit(&rtval));
    return rtval;
}

void PyIAcadDimensionImpl::SetToleranceLowerLimit(double val) const
{
    PyThrowBadHr(impObj()->put_ToleranceLowerLimit(val));
}

PyAcDimTextMovement PyIAcadDimensionImpl::GetTextMovement() const
{
    AcDimTextMovement rtval = (AcDimTextMovement)PyAcDimTextMovement::pyacDimLineWithText;
    PyThrowBadHr(impObj()->get_TextMovement(&rtval));
    return (PyAcDimTextMovement)rtval;
}

void PyIAcadDimensionImpl::SetTextMovement(PyAcDimTextMovement val) const
{
    PyThrowBadHr(impObj()->put_TextMovement((AcDimTextMovement)val));
}

PyAcDimToleranceMethod PyIAcadDimensionImpl::GetToleranceDisplay() const
{
    AcDimToleranceMethod rtval = (AcDimToleranceMethod)PyAcDimToleranceMethod::pyacTolNone;
    PyThrowBadHr(impObj()->get_ToleranceDisplay(&rtval));
    return (PyAcDimToleranceMethod)rtval;
}

void PyIAcadDimensionImpl::SetToleranceDisplay(PyAcDimToleranceMethod val) const
{
    PyThrowBadHr(impObj()->put_ToleranceDisplay((AcDimToleranceMethod)val));
}

PyAcDimToleranceJustify PyIAcadDimensionImpl::GetToleranceJustification() const
{
    AcDimToleranceJustify rtval = (AcDimToleranceJustify)PyAcDimToleranceJustify::pyacTolBottom;
    PyThrowBadHr(impObj()->get_ToleranceJustification(&rtval));
    return (PyAcDimToleranceJustify)rtval;
}

void PyIAcadDimensionImpl::SetToleranceJustification(PyAcDimToleranceJustify val) const
{
    PyThrowBadHr(impObj()->put_ToleranceJustification((AcDimToleranceJustify)val));
}

double PyIAcadDimensionImpl::GetToleranceUpperLimit() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_ToleranceUpperLimit(&rtval));
    return rtval;
}

void PyIAcadDimensionImpl::SetToleranceUpperLimit(double val) const
{
    PyThrowBadHr(impObj()->put_ToleranceUpperLimit(val));
}

CString PyIAcadDimensionImpl::GetTextStyle() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_TextStyle(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadDimensionImpl::SetTextStyle(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_TextStyle(bstrval));
}

double PyIAcadDimensionImpl::GetTextHeight() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_TextHeight(&rtval));
    return rtval;
}

void PyIAcadDimensionImpl::SetTextHeight(double val) const
{
    PyThrowBadHr(impObj()->put_TextHeight(val));
}

bool PyIAcadDimensionImpl::GetSuppressLeadingZeros() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_SuppressLeadingZeros(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimensionImpl::SetSuppressLeadingZeros(bool val) const
{
    PyThrowBadHr(impObj()->put_SuppressLeadingZeros(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadDimensionImpl::GetSuppressTrailingZeros() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_SuppressTrailingZeros(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimensionImpl::SetSuppressTrailingZeros(bool val) const
{
    PyThrowBadHr(impObj()->put_SuppressTrailingZeros(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadDimensionImpl::GetToleranceSuppressLeadingZeros() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_ToleranceSuppressLeadingZeros(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimensionImpl::SetToleranceSuppressLeadingZeros(bool val) const
{
    PyThrowBadHr(impObj()->put_ToleranceSuppressLeadingZeros(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadDimensionImpl::GetToleranceSuppressTrailingZeros() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_ToleranceSuppressTrailingZeros(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimensionImpl::SetToleranceSuppressTrailingZeros(bool val) const
{
    PyThrowBadHr(impObj()->put_ToleranceSuppressTrailingZeros(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadDimensionImpl::GetTextFill() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_TextFill(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimensionImpl::SetTextFill(bool val) const
{
    PyThrowBadHr(impObj()->put_TextFill(val ? VARIANT_TRUE : VARIANT_FALSE));
}

PyAcColor PyIAcadDimensionImpl::GetTextFillColor() const
{
    AcColor rtval = (AcColor)PyAcColor::pyacByLayer;
    PyThrowBadHr(impObj()->get_TextFillColor(&rtval));
    return (PyAcColor)rtval;
}

void PyIAcadDimensionImpl::SetTextFillColor(PyAcColor val) const
{
    PyThrowBadHr(impObj()->put_TextFillColor((AcColor)val));
}

bool PyIAcadDimensionImpl::GetDimTxtDirection() const
{
#ifdef _BRXTARGET250
    throw PyNotimplementedByHost{};
#else
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_DimTxtDirection(&rtval));
    return rtval != VARIANT_FALSE;
#endif
}

void PyIAcadDimensionImpl::SetDimTxtDirection(bool val) const
{
#ifdef _BRXTARGET250
    throw PyNotimplementedByHost{};
#else
    PyThrowBadHr(impObj()->put_DimTxtDirection(val ? VARIANT_TRUE : VARIANT_FALSE));
#endif
}

IAcadDimension* PyIAcadDimensionImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadDimension*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadDimensionImpl
PyIAcadDimAlignedImpl::PyIAcadDimAlignedImpl(IAcadDimAligned* ptr)
    : PyIAcadDimensionImpl(ptr)
{
}

AcGePoint3d PyIAcadDimAlignedImpl::GetExtLine1Point() const
{
    _variant_t vtval;
    AcGePoint3d rtval;
    PyThrowBadHr(impObj()->get_ExtLine1Point(&vtval));
    PyThrowBadHr(VariantToAcGePoint3d(vtval, rtval));
    return rtval;
}

void PyIAcadDimAlignedImpl::SetExtLine1Point(const AcGePoint3d& val) const
{
    _variant_t vtval;
    PyThrowBadHr(AcGePoint3dToVariant(vtval.GetVARIANT(), val));
    PyThrowBadHr(impObj()->put_ExtLine1Point(vtval));
}

AcGePoint3d PyIAcadDimAlignedImpl::GetExtLine2Point() const
{
    _variant_t vtval;
    AcGePoint3d rtval;
    PyThrowBadHr(impObj()->get_ExtLine2Point(&vtval));
    PyThrowBadHr(VariantToAcGePoint3d(vtval, rtval));
    return rtval;
}

void PyIAcadDimAlignedImpl::SetExtLine2Point(const AcGePoint3d& val) const
{
    _variant_t vtval;
    PyThrowBadHr(AcGePoint3dToVariant(vtval.GetVARIANT(), val));
    PyThrowBadHr(impObj()->put_ExtLine2Point(vtval));
}

bool PyIAcadDimAlignedImpl::GetAltUnits() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_AltUnits(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimAlignedImpl::SetAltUnits(bool val) const
{
    PyThrowBadHr(impObj()->put_AltUnits(val ? VARIANT_TRUE : VARIANT_FALSE));
}

PyAcDimPrecision PyIAcadDimAlignedImpl::GetAltUnitsPrecision() const
{
    AcDimPrecision rtval = (AcDimPrecision)PyAcDimPrecision::pyacDimPrecisionOne;
    PyThrowBadHr(impObj()->get_AltUnitsPrecision(&rtval));
    return (PyAcDimPrecision)rtval;
}

void PyIAcadDimAlignedImpl::SetAltUnitsPrecision(PyAcDimPrecision val) const
{
    PyThrowBadHr(impObj()->put_AltUnitsPrecision((AcDimPrecision)val));
}

double PyIAcadDimAlignedImpl::GetAltUnitsScale() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_AltUnitsScale(&rtval));
    return rtval;
}

void PyIAcadDimAlignedImpl::SetAltUnitsScale(double val) const
{
    PyThrowBadHr(impObj()->put_AltUnitsScale(val));
}

double PyIAcadDimAlignedImpl::GetAltRoundDistance() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_AltRoundDistance(&rtval));
    return rtval;
}

void PyIAcadDimAlignedImpl::SetAltRoundDistance(double val) const
{
    PyThrowBadHr(impObj()->put_AltRoundDistance(val));
}

PyAcDimPrecision PyIAcadDimAlignedImpl::GetAltTolerancePrecision() const
{
    AcDimPrecision rtval = (AcDimPrecision)PyAcDimPrecision::pyacDimPrecisionOne;
    PyThrowBadHr(impObj()->get_AltTolerancePrecision(&rtval));
    return (PyAcDimPrecision)rtval;
}

void PyIAcadDimAlignedImpl::SetAltTolerancePrecision(PyAcDimPrecision val) const
{
    PyThrowBadHr(impObj()->put_AltTolerancePrecision((AcDimPrecision)val));
}

PyAcDimUnits PyIAcadDimAlignedImpl::GetAltUnitsFormat() const
{
    AcDimUnits rtval = (AcDimUnits)PyAcDimUnits::pyacDimDecimal;
    PyThrowBadHr(impObj()->get_AltUnitsFormat(&rtval));
    return (PyAcDimUnits)rtval;
}

void PyIAcadDimAlignedImpl::SetAltUnitsFormat(PyAcDimUnits val) const
{
    PyThrowBadHr(impObj()->put_AltUnitsFormat((AcDimUnits)val));
}

CString PyIAcadDimAlignedImpl::GetAltTextPrefix() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_AltTextPrefix(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadDimAlignedImpl::SetAltTextPrefix(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_AltTextPrefix(bstrval));
}

CString PyIAcadDimAlignedImpl::GetAltTextSuffix() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_AltTextSuffix((&bstrVal.GetBSTR())));
    return (LPCTSTR)bstrVal;
}

void PyIAcadDimAlignedImpl::SetAltTextSuffix(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_AltTextSuffix(bstrval));
}

PyAcColor PyIAcadDimAlignedImpl::GetDimensionLineColor() const
{
    AcColor rtval = (AcColor)PyAcColor::pyacByLayer;
    PyThrowBadHr(impObj()->get_DimensionLineColor(&rtval));
    return (PyAcColor)rtval;
}

void PyIAcadDimAlignedImpl::SetDimensionLineColor(PyAcColor val) const
{
    PyThrowBadHr(impObj()->put_DimensionLineColor((AcColor)val));
}

PyAcColor PyIAcadDimAlignedImpl::GetExtensionLineColor() const
{
    AcColor rtval = (AcColor)PyAcColor::pyacByLayer;
    PyThrowBadHr(impObj()->get_ExtensionLineColor(&rtval));
    return (PyAcColor)rtval;
}

void PyIAcadDimAlignedImpl::SetExtensionLineColor(PyAcColor val) const
{
    PyThrowBadHr(impObj()->put_ExtensionLineColor((AcColor)val));
}

PyAcDimPrecision PyIAcadDimAlignedImpl::GetPrimaryUnitsPrecision() const
{
    AcDimPrecision rtval = (AcDimPrecision)PyAcDimPrecision::pyacDimPrecisionOne;
    PyThrowBadHr(impObj()->get_PrimaryUnitsPrecision(&rtval));
    return (PyAcDimPrecision)rtval;
}

void PyIAcadDimAlignedImpl::SetPrimaryUnitsPrecision(PyAcDimPrecision val) const
{
    PyThrowBadHr(impObj()->put_PrimaryUnitsPrecision((AcDimPrecision)val));
}

double PyIAcadDimAlignedImpl::GetDimensionLineExtend() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_DimensionLineExtend(&rtval));
    return rtval;
}

void PyIAcadDimAlignedImpl::SetDimensionLineExtend(double val) const
{
    PyThrowBadHr(impObj()->put_DimensionLineExtend(val));
}

double PyIAcadDimAlignedImpl::GetExtensionLineExtend() const
{

    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_ExtensionLineExtend(&rtval));
    return rtval;
}

void PyIAcadDimAlignedImpl::SetExtensionLineExtend(double val) const
{
    PyThrowBadHr(impObj()->put_ExtensionLineExtend(val));
}

PyAcDimFit PyIAcadDimAlignedImpl::GetFit() const
{
    AcDimFit rtval = (AcDimFit)PyAcDimFit::pyacTextAndArrows;
    PyThrowBadHr(impObj()->get_Fit(&rtval));
    return (PyAcDimFit)rtval;
}

void PyIAcadDimAlignedImpl::SetFit(PyAcDimFit val) const
{
    PyThrowBadHr(impObj()->put_Fit((AcDimFit)val));
}

PyAcDimFractionType PyIAcadDimAlignedImpl::GetFractionFormat() const
{
    AcDimFractionType rtval = (AcDimFractionType)PyAcDimFractionType::pyacHorizontal;
    PyThrowBadHr(impObj()->get_FractionFormat(&rtval));
    return (PyAcDimFractionType)rtval;
}

void PyIAcadDimAlignedImpl::SetFractionFormat(PyAcDimFractionType val) const
{
    PyThrowBadHr(impObj()->put_FractionFormat((AcDimFractionType)val));
}

PyAcDimHorizontalJustification PyIAcadDimAlignedImpl::GetHorizontalTextPosition() const
{
    AcDimHorizontalJustification rtval = (AcDimHorizontalJustification)PyAcDimHorizontalJustification::pyacHorzCentered;
    PyThrowBadHr(impObj()->get_HorizontalTextPosition(&rtval));
    return (PyAcDimHorizontalJustification)rtval;
}

void PyIAcadDimAlignedImpl::SetHorizontalTextPosition(PyAcDimHorizontalJustification val) const
{
    PyThrowBadHr(impObj()->put_HorizontalTextPosition((AcDimHorizontalJustification)val));
}

double PyIAcadDimAlignedImpl::GetLinearScaleFactor() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_LinearScaleFactor(&rtval));
    return rtval;
}

void PyIAcadDimAlignedImpl::SetLinearScaleFactor(double val) const
{
    PyThrowBadHr(impObj()->put_LinearScaleFactor(val));
}

PyAcDimLUnits PyIAcadDimAlignedImpl::GetUnitsFormat() const
{
    AcDimLUnits rtval = (AcDimLUnits)PyAcDimLUnits::pyacDimLDecimal;
    PyThrowBadHr(impObj()->get_UnitsFormat(&rtval));
    return (PyAcDimLUnits)rtval;
}

void PyIAcadDimAlignedImpl::SetUnitsFormat(PyAcDimLUnits val) const
{
    PyThrowBadHr(impObj()->put_UnitsFormat((AcDimLUnits)val));
}

PyAcLineWeight PyIAcadDimAlignedImpl::GetExtensionLineWeight() const
{
    AcLineWeight rtval = (AcLineWeight)PyAcLineWeight::pyacLnWt000;
    PyThrowBadHr(impObj()->get_ExtensionLineWeight(&rtval));
    return (PyAcLineWeight)rtval;
}

void PyIAcadDimAlignedImpl::SetExtensionLineWeight(PyAcLineWeight val) const
{
    PyThrowBadHr(impObj()->put_ExtensionLineWeight((AcLineWeight)val));
}

double PyIAcadDimAlignedImpl::GetRoundDistance() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_RoundDistance(&rtval));
    return rtval;
}

void PyIAcadDimAlignedImpl::SetRoundDistance(double val) const
{
    PyThrowBadHr(impObj()->put_RoundDistance(val));
}

bool PyIAcadDimAlignedImpl::GetDimLine1Suppress() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_DimLine1Suppress(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimAlignedImpl::SetDimLine1Suppress(bool val) const
{
    PyThrowBadHr(impObj()->put_DimLine1Suppress(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadDimAlignedImpl::GetDimLine2Suppress() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_DimLine2Suppress(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimAlignedImpl::SetDimLine2Suppress(bool val) const
{
    PyThrowBadHr(impObj()->put_DimLine2Suppress(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadDimAlignedImpl::GetExtLine1Suppress() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_ExtLine1Suppress(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimAlignedImpl::SetExtLine1Suppress(bool val) const
{
    PyThrowBadHr(impObj()->put_ExtLine1Suppress(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadDimAlignedImpl::GetExtLine2Suppress() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_ExtLine2Suppress(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimAlignedImpl::SetExtLine2Suppress(bool val) const
{
    PyThrowBadHr(impObj()->put_ExtLine2Suppress(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadDimAlignedImpl::GetDimLineInside() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_DimLineInside(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimAlignedImpl::SetDimLineInside(bool val) const
{
    PyThrowBadHr(impObj()->put_DimLineInside(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadDimAlignedImpl::GetTextInsideAlign() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_TextInsideAlign(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimAlignedImpl::SetTextInsideAlign(bool val) const
{
    PyThrowBadHr(impObj()->put_TextInsideAlign(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadDimAlignedImpl::GetTextInside() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_TextInside(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimAlignedImpl::SetTextInside(bool val) const
{
    PyThrowBadHr(impObj()->put_TextInside(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadDimAlignedImpl::GetForceLineInside() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_ForceLineInside(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimAlignedImpl::SetForceLineInside(bool val) const
{
    PyThrowBadHr(impObj()->put_ForceLineInside(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadDimAlignedImpl::GetTextOutsideAlign() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_TextOutsideAlign(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimAlignedImpl::SetTextOutsideAlign(bool val) const
{
    PyThrowBadHr(impObj()->put_TextOutsideAlign(val ? VARIANT_TRUE : VARIANT_FALSE));
}

double PyIAcadDimAlignedImpl::GetExtensionLineOffset() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_ExtensionLineOffset(&rtval));
    return rtval;
}

void PyIAcadDimAlignedImpl::SetExtensionLineOffset(double val) const
{
    PyThrowBadHr(impObj()->put_ExtensionLineOffset(val));
}

bool PyIAcadDimAlignedImpl::GetAltSuppressLeadingZeros() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_AltSuppressLeadingZeros(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimAlignedImpl::SetAltSuppressLeadingZeros(bool val) const
{
    PyThrowBadHr(impObj()->put_AltSuppressLeadingZeros(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadDimAlignedImpl::GetAltSuppressTrailingZeros() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_AltSuppressTrailingZeros(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimAlignedImpl::SetAltSuppressTrailingZeros(bool val) const
{
    PyThrowBadHr(impObj()->put_AltSuppressTrailingZeros(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadDimAlignedImpl::GetAltSuppressZeroFeet() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_AltSuppressZeroFeet(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimAlignedImpl::SetAltSuppressZeroFeet(bool val) const
{
    PyThrowBadHr(impObj()->put_AltSuppressZeroFeet(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadDimAlignedImpl::GetAltSuppressZeroInches() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_AltSuppressZeroInches(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimAlignedImpl::SetAltSuppressZeroInches(bool val) const
{
    PyThrowBadHr(impObj()->put_AltSuppressZeroInches(val));
}

bool PyIAcadDimAlignedImpl::GetAltToleranceSuppressLeadingZeros() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_AltToleranceSuppressLeadingZeros(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimAlignedImpl::SetAltToleranceSuppressLeadingZeros(bool val) const
{
    PyThrowBadHr(impObj()->put_AltToleranceSuppressLeadingZeros(val));
}

bool PyIAcadDimAlignedImpl::GetAltToleranceSuppressTrailingZeros() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_AltToleranceSuppressTrailingZeros(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimAlignedImpl::SetAltToleranceSuppressTrailingZeros(bool val) const
{
    PyThrowBadHr(impObj()->put_AltToleranceSuppressTrailingZeros(val));
}

bool PyIAcadDimAlignedImpl::GetAltToleranceSuppressZeroFeet() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_AltToleranceSuppressZeroFeet(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimAlignedImpl::SetAltToleranceSuppressZeroFeet(bool val) const
{
    PyThrowBadHr(impObj()->put_AltToleranceSuppressZeroFeet(val));
}

bool PyIAcadDimAlignedImpl::GetAltToleranceSuppressZeroInches() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_AltToleranceSuppressZeroInches(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimAlignedImpl::SetAltToleranceSuppressZeroInches(bool val) const
{
    PyThrowBadHr(impObj()->put_AltToleranceSuppressZeroInches(val));
}

bool PyIAcadDimAlignedImpl::GetSuppressZeroFeet() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_SuppressZeroFeet(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimAlignedImpl::SetSuppressZeroFeet(bool val) const
{
    PyThrowBadHr(impObj()->put_SuppressZeroFeet(val));
}

bool PyIAcadDimAlignedImpl::GetSuppressZeroInches() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_SuppressZeroInches(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimAlignedImpl::SetSuppressZeroInches(bool val) const
{
    PyThrowBadHr(impObj()->put_SuppressZeroInches(val));
}

bool PyIAcadDimAlignedImpl::GetToleranceSuppressZeroFeet() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_ToleranceSuppressZeroFeet(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimAlignedImpl::SetToleranceSuppressZeroFeet(bool val) const
{
    PyThrowBadHr(impObj()->put_ToleranceSuppressZeroFeet(val));
}

bool PyIAcadDimAlignedImpl::GetToleranceSuppressZeroInches() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_ToleranceSuppressZeroInches(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimAlignedImpl::SetToleranceSuppressZeroInches(bool val) const
{
    PyThrowBadHr(impObj()->put_ToleranceSuppressZeroInches(val));
}

PyAcLineWeight PyIAcadDimAlignedImpl::GetDimensionLineWeight() const
{
    AcLineWeight rtval = (AcLineWeight)PyAcLineWeight::pyacLnWt000;
    PyThrowBadHr(impObj()->get_DimensionLineWeight(&rtval));
    return (PyAcLineWeight)rtval;
}

void PyIAcadDimAlignedImpl::SetDimensionLineWeight(PyAcLineWeight val) const
{
    PyThrowBadHr(impObj()->put_DimensionLineWeight((AcLineWeight)val));
}

double PyIAcadDimAlignedImpl::GetArrowheadSize() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_ArrowheadSize(&rtval));
    return rtval;
}

void PyIAcadDimAlignedImpl::SetArrowheadSize(double val) const
{
    PyThrowBadHr(impObj()->put_ArrowheadSize(val));
}

PyAcDimArrowheadType PyIAcadDimAlignedImpl::GetArrowhead1Type() const
{
    AcDimArrowheadType rtval = (AcDimArrowheadType)PyAcDimArrowheadType::pyacArrowDefault;
    PyThrowBadHr(impObj()->get_Arrowhead1Type(&rtval));
    return (PyAcDimArrowheadType)rtval;
}

void PyIAcadDimAlignedImpl::SetArrowhead1Type(PyAcDimArrowheadType val) const
{
    PyThrowBadHr(impObj()->put_Arrowhead1Type((AcDimArrowheadType)val));
}

PyAcDimArrowheadType PyIAcadDimAlignedImpl::GetArrowhead2Type() const
{
    AcDimArrowheadType rtval = (AcDimArrowheadType)PyAcDimArrowheadType::pyacArrowDefault;
    PyThrowBadHr(impObj()->get_Arrowhead2Type(&rtval));
    return (PyAcDimArrowheadType)rtval;
}

void PyIAcadDimAlignedImpl::SetArrowhead2Type(PyAcDimArrowheadType val) const
{
    PyThrowBadHr(impObj()->put_Arrowhead2Type((AcDimArrowheadType)val));
}

double PyIAcadDimAlignedImpl::GetMeasurement() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_Measurement(&rtval));
    return rtval;
}

CString PyIAcadDimAlignedImpl::GetArrowhead1Block() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_Arrowhead1Block(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadDimAlignedImpl::SetArrowhead1Block(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_Arrowhead1Block(bstrval));
}

CString PyIAcadDimAlignedImpl::GetArrowhead2Block() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_Arrowhead2Block(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadDimAlignedImpl::SetArrowhead2Block(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_Arrowhead2Block(bstrval));
}

CString PyIAcadDimAlignedImpl::GetDimensionLinetype() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_DimensionLinetype(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadDimAlignedImpl::SetDimensionLinetype(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_DimensionLinetype(bstrval));
}

CString PyIAcadDimAlignedImpl::GetExtLine1Linetype() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_ExtLine1Linetype(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadDimAlignedImpl::SetExtLine1Linetype(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_ExtLine1Linetype(bstrval));
}

CString PyIAcadDimAlignedImpl::GetExtLine2Linetype() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_ExtLine2Linetype(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadDimAlignedImpl::SetExtLine2Linetype(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_ExtLine2Linetype(bstrval));
}

bool PyIAcadDimAlignedImpl::GetExtLineFixedLenSuppress() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_ExtLineFixedLenSuppress(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimAlignedImpl::SetExtLineFixedLenSuppress(bool val) const
{
    PyThrowBadHr(impObj()->put_ExtLineFixedLenSuppress(val ? VARIANT_TRUE : VARIANT_FALSE));
}

double PyIAcadDimAlignedImpl::GetExtLineFixedLen() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_ExtLineFixedLen(&rtval));
    return rtval;
}

void PyIAcadDimAlignedImpl::SetExtLineFixedLen(double val) const
{
    PyThrowBadHr(impObj()->put_ExtLineFixedLen(val));
}

bool PyIAcadDimAlignedImpl::GetDimConstrForm() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_DimConstrForm(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimAlignedImpl::SetDimConstrForm(bool val) const
{
    PyThrowBadHr(impObj()->put_DimConstrForm(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadDimAlignedImpl::GetDimConstrReference() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_DimConstrReference(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimAlignedImpl::SetDimConstrReference(bool val) const
{
    PyThrowBadHr(impObj()->put_DimConstrReference(val ? VARIANT_TRUE : VARIANT_FALSE));
}

CString PyIAcadDimAlignedImpl::GetDimConstrName() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_DimConstrName(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadDimAlignedImpl::SetDimConstrName(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_DimConstrName(bstrval));
}

CString PyIAcadDimAlignedImpl::GetDimConstrExpression() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_DimConstrExpression(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadDimAlignedImpl::SetDimConstrExpression(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_DimConstrExpression(bstrval));
}

CString PyIAcadDimAlignedImpl::GetDimConstrValue() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_DimConstrValue(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadDimAlignedImpl::SetDimConstrValue(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_DimConstrValue(bstrval));
}

CString PyIAcadDimAlignedImpl::GetDimConstrDesc() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_DimConstrDesc(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadDimAlignedImpl::SetDimConstrDesc(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_DimConstrDesc(bstrval));
}

CString PyIAcadDimAlignedImpl::GetSubUnitsSuffix() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_SubUnitsSuffix(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadDimAlignedImpl::SetSubUnitsSuffix(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_SubUnitsSuffix(bstrval));
}

double PyIAcadDimAlignedImpl::GetSubUnitsFactor() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_SubUnitsFactor(&rtval));
    return rtval;
}

void PyIAcadDimAlignedImpl::SetSubUnitsFactor(double val) const
{
    PyThrowBadHr(impObj()->put_SubUnitsFactor(val));
}

CString PyIAcadDimAlignedImpl::GetAltSubUnitsSuffix() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_AltSubUnitsSuffix(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadDimAlignedImpl::SetAltSubUnitsSuffix(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_AltSubUnitsSuffix(bstrval));
}

double PyIAcadDimAlignedImpl::GetAltSubUnitsFactor() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_AltSubUnitsFactor(&rtval));
    return rtval;
}

void PyIAcadDimAlignedImpl::SetAltSubUnitsFactor(double val) const
{
    PyThrowBadHr(impObj()->put_AltSubUnitsFactor(val));
}

IAcadDimAligned* PyIAcadDimAlignedImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadDimAligned*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadDimAngularImpl
PyIAcadDimAngularImpl::PyIAcadDimAngularImpl(IAcadDimAngular* ptr)
    : PyIAcadDimensionImpl(ptr)
{
}

IAcadDimAngular* PyIAcadDimAngularImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadDimAngular*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadDimDiametricImpl
PyIAcadDimDiametricImpl::PyIAcadDimDiametricImpl(IAcadDimDiametric* ptr)
    : PyIAcadDimensionImpl(ptr)
{
}

IAcadDimDiametric* PyIAcadDimDiametricImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadDimDiametric*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadDimRotatedImpl
PyIAcadDimRotatedImpl::PyIAcadDimRotatedImpl(IAcadDimRotated* ptr)
    : PyIAcadDimensionImpl(ptr)
{
}

IAcadDimRotated* PyIAcadDimRotatedImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadDimRotated*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadDimOrdinateImpl
PyIAcadDimOrdinateImpl::PyIAcadDimOrdinateImpl(IAcadDimOrdinate* ptr)
    : PyIAcadDimensionImpl(ptr)
{
}

IAcadDimOrdinate* PyIAcadDimOrdinateImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadDimOrdinate*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadDimRadialImpl
PyIAcadDimRadialImpl::PyIAcadDimRadialImpl(IAcadDimRadial* ptr)
    : PyIAcadDimensionImpl(ptr)
{
}

IAcadDimRadial* PyIAcadDimRadialImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadDimRadial*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadDim3PointAngularImpl
PyIAcadDim3PointAngularImpl::PyIAcadDim3PointAngularImpl(IAcadDim3PointAngular* ptr)
    : PyIAcadDimensionImpl(ptr)
{
}

IAcadDim3PointAngular* PyIAcadDim3PointAngularImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadDim3PointAngular*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadDimArcLengthImpl
PyIAcadDimArcLengthImpl::PyIAcadDimArcLengthImpl(IAcadDimArcLength* ptr)
    : PyIAcadDimensionImpl(ptr)
{
}

IAcadDimArcLength* PyIAcadDimArcLengthImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadDimArcLength*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadDimRadialLargeImpl
PyIAcadDimRadialLargeImpl::PyIAcadDimRadialLargeImpl(IAcadDimRadialLarge* ptr)
    : PyIAcadDimensionImpl(ptr)
{
}

IAcadDimRadialLarge* PyIAcadDimRadialLargeImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadDimRadialLarge*>(m_pimpl.GetInterfacePtr());
}
