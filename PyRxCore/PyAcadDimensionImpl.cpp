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
#ifdef _BRXTARGET260
    throw PyNotimplementedByHost{};
#else
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_DimTxtDirection(&rtval));
    return rtval != VARIANT_FALSE;
#endif
}

void PyIAcadDimensionImpl::SetDimTxtDirection(bool val) const
{
#ifdef _BRXTARGET260
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

AcGePoint3d PyIAcadDimAngularImpl::GetExtLine1StartPoint() const
{
    _variant_t vtval;
    AcGePoint3d rtval;
    PyThrowBadHr(impObj()->get_ExtLine1StartPoint(&vtval));
    PyThrowBadHr(VariantToAcGePoint3d(vtval, rtval));
    return rtval;
}

void PyIAcadDimAngularImpl::SetExtLine1StartPoint(const AcGePoint3d& val) const
{
    _variant_t vtval;
    PyThrowBadHr(AcGePoint3dToVariant(vtval.GetVARIANT(), val));
    PyThrowBadHr(impObj()->put_ExtLine1StartPoint(vtval));
}

AcGePoint3d PyIAcadDimAngularImpl::GetExtLine1EndPoint() const
{
    _variant_t vtval;
    AcGePoint3d rtval;
    PyThrowBadHr(impObj()->get_ExtLine1EndPoint(&vtval));
    PyThrowBadHr(VariantToAcGePoint3d(vtval, rtval));
    return rtval;
}

void PyIAcadDimAngularImpl::SetExtLine1EndPoint(const AcGePoint3d& val) const
{
    _variant_t vtval;
    PyThrowBadHr(AcGePoint3dToVariant(vtval.GetVARIANT(), val));
    PyThrowBadHr(impObj()->put_ExtLine1EndPoint(vtval));
}

AcGePoint3d PyIAcadDimAngularImpl::GetExtLine2StartPoint() const
{
    _variant_t vtval;
    AcGePoint3d rtval;
    PyThrowBadHr(impObj()->get_ExtLine2StartPoint(&vtval));
    PyThrowBadHr(VariantToAcGePoint3d(vtval, rtval));
    return rtval;
}

void PyIAcadDimAngularImpl::SetExtLine2StartPoint(const AcGePoint3d& val) const
{
    _variant_t vtval;
    PyThrowBadHr(AcGePoint3dToVariant(vtval.GetVARIANT(), val));
    PyThrowBadHr(impObj()->put_ExtLine2StartPoint(vtval));
}

AcGePoint3d PyIAcadDimAngularImpl::GetExtLine2EndPoint() const
{
    _variant_t vtval;
    AcGePoint3d rtval;
    PyThrowBadHr(impObj()->get_ExtLine2EndPoint(&vtval));
    PyThrowBadHr(VariantToAcGePoint3d(vtval, rtval));
    return rtval;
}

void PyIAcadDimAngularImpl::SetExtLine2EndPoint(const AcGePoint3d& val) const
{
    _variant_t vtval;
    PyThrowBadHr(AcGePoint3dToVariant(vtval.GetVARIANT(), val));
    PyThrowBadHr(impObj()->put_ExtLine2EndPoint(vtval));
}

PyAcAngleUnits PyIAcadDimAngularImpl::GetAngleFormat() const
{
    AcAngleUnits rtval = (AcAngleUnits)PyAcAngleUnits::pyacDegrees;
    PyThrowBadHr(impObj()->get_AngleFormat(&rtval));
    return (PyAcAngleUnits)rtval;
}

void PyIAcadDimAngularImpl::SetAngleFormat(PyAcAngleUnits val) const
{
    PyThrowBadHr(impObj()->put_AngleFormat((AcAngleUnits)val));
}

PyAcColor PyIAcadDimAngularImpl::GetDimensionLineColor() const
{
    AcColor rtval = (AcColor)PyAcColor::pyacByLayer;
    PyThrowBadHr(impObj()->get_DimensionLineColor(&rtval));
    return (PyAcColor)rtval;
}

void PyIAcadDimAngularImpl::SetDimensionLineColor(PyAcColor val) const
{
    PyThrowBadHr(impObj()->put_DimensionLineColor((AcColor)val));
}

PyAcColor PyIAcadDimAngularImpl::GetExtensionLineColor() const
{
    AcColor rtval = (AcColor)PyAcColor::pyacByLayer;
    PyThrowBadHr(impObj()->get_ExtensionLineColor(&rtval));
    return (PyAcColor)rtval;
}

void PyIAcadDimAngularImpl::SetExtensionLineColor(PyAcColor val) const
{
    PyThrowBadHr(impObj()->put_ExtensionLineColor((AcColor)val));
}

double PyIAcadDimAngularImpl::GetExtensionLineExtend() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_ExtensionLineExtend(&rtval));
    return rtval;
}

void PyIAcadDimAngularImpl::SetExtensionLineExtend(double val) const
{
    PyThrowBadHr(impObj()->put_ExtensionLineExtend(val));
}

PyAcDimFit PyIAcadDimAngularImpl::GetFit() const
{
    AcDimFit rtval = (AcDimFit)PyAcDimFit::pyacTextAndArrows;
    PyThrowBadHr(impObj()->get_Fit(&rtval));
    return (PyAcDimFit)rtval;
}

void PyIAcadDimAngularImpl::SetFit(PyAcDimFit val) const
{
    PyThrowBadHr(impObj()->put_Fit((AcDimFit)val));
}

PyAcDimHorizontalJustification PyIAcadDimAngularImpl::GetHorizontalTextPosition() const
{
    AcDimHorizontalJustification rtval = (AcDimHorizontalJustification)PyAcDimHorizontalJustification::pyacHorzCentered;
    PyThrowBadHr(impObj()->get_HorizontalTextPosition(&rtval));
    return (PyAcDimHorizontalJustification)rtval;
}

PyAcLineWeight PyIAcadDimAngularImpl::GetExtensionLineWeight() const
{
    AcLineWeight rtval = (AcLineWeight)PyAcLineWeight::pyacLnWt000;
    PyThrowBadHr(impObj()->get_ExtensionLineWeight(&rtval));
    return (PyAcLineWeight)rtval;
}

void PyIAcadDimAngularImpl::SetExtensionLineWeight(PyAcLineWeight val) const
{
    PyThrowBadHr(impObj()->put_ExtensionLineWeight((AcLineWeight)val));
}

bool PyIAcadDimAngularImpl::GetDimLine1Suppress() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_DimLine1Suppress(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimAngularImpl::SetDimLine1Suppress(bool val) const
{
    PyThrowBadHr(impObj()->put_DimLine1Suppress(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadDimAngularImpl::GetDimLine2Suppress() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_DimLine2Suppress(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimAngularImpl::SetDimLine2Suppress(bool val) const
{
    PyThrowBadHr(impObj()->put_DimLine2Suppress(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadDimAngularImpl::GetExtLine1Suppress() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_ExtLine1Suppress(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimAngularImpl::SetExtLine1Suppress(bool val) const
{
    PyThrowBadHr(impObj()->put_ExtLine1Suppress(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadDimAngularImpl::GetExtLine2Suppress() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_ExtLine2Suppress(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimAngularImpl::SetExtLine2Suppress(bool val) const
{
    PyThrowBadHr(impObj()->put_ExtLine2Suppress(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadDimAngularImpl::GetDimLineInside() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_DimLineInside(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimAngularImpl::SetDimLineInside(bool val) const
{
    PyThrowBadHr(impObj()->put_DimLineInside(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadDimAngularImpl::GetTextInsideAlign() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_TextInsideAlign(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimAngularImpl::SetTextInsideAlign(bool val) const
{
    PyThrowBadHr(impObj()->put_TextInsideAlign(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadDimAngularImpl::GetTextInside() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_TextInside(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimAngularImpl::SetTextInside(bool val) const
{
    PyThrowBadHr(impObj()->put_TextInside(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadDimAngularImpl::GetForceLineInside() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_ForceLineInside(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimAngularImpl::SetForceLineInside(bool val) const
{
    PyThrowBadHr(impObj()->put_ForceLineInside(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadDimAngularImpl::GetTextOutsideAlign() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_TextOutsideAlign(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimAngularImpl::SetTextOutsideAlign(bool val) const
{
    PyThrowBadHr(impObj()->put_TextOutsideAlign(val ? VARIANT_TRUE : VARIANT_FALSE));
}

PyAcDimPrecision PyIAcadDimAngularImpl::GetTextPrecision() const
{
    AcDimPrecision rtval = (AcDimPrecision)PyAcDimPrecision::pyacDimPrecisionZero;
    PyThrowBadHr(impObj()->get_TextPrecision(&rtval));
    return (PyAcDimPrecision)rtval;
}

void PyIAcadDimAngularImpl::SetTextPrecision(PyAcDimPrecision val) const
{
    PyThrowBadHr(impObj()->put_TextPrecision((AcDimPrecision)val));
}

double PyIAcadDimAngularImpl::GetExtensionLineOffset() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_ExtensionLineOffset(&rtval));
    return rtval;
}

void PyIAcadDimAngularImpl::SetExtensionLineOffset(double val) const
{
    PyThrowBadHr(impObj()->put_ExtensionLineOffset(val));
}

void PyIAcadDimAngularImpl::SetHorizontalTextPosition(PyAcDimHorizontalJustification val) const
{
    PyThrowBadHr(impObj()->put_HorizontalTextPosition((AcDimHorizontalJustification)val));
}

PyAcLineWeight PyIAcadDimAngularImpl::GetDimensionLineWeight() const
{
    AcLineWeight rtval = (AcLineWeight)PyAcLineWeight::pyacLnWt000;
    PyThrowBadHr(impObj()->get_DimensionLineWeight(&rtval));
    return (PyAcLineWeight)rtval;
}

void PyIAcadDimAngularImpl::SetDimensionLineWeight(PyAcLineWeight val) const
{
    PyThrowBadHr(impObj()->put_DimensionLineWeight((AcLineWeight)val));
}

double PyIAcadDimAngularImpl::GetArrowheadSize() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_ArrowheadSize(&rtval));
    return rtval;
}

void PyIAcadDimAngularImpl::SetArrowheadSize(double val) const
{
    PyThrowBadHr(impObj()->put_ArrowheadSize(val));
}

PyAcDimArrowheadType PyIAcadDimAngularImpl::GetArrowhead1Type() const
{
    AcDimArrowheadType rtval = (AcDimArrowheadType)PyAcDimArrowheadType::pyacArrowDefault;
    PyThrowBadHr(impObj()->get_Arrowhead1Type(&rtval));
    return (PyAcDimArrowheadType)rtval;
}

void PyIAcadDimAngularImpl::SetArrowhead1Type(PyAcDimArrowheadType val) const
{
    PyThrowBadHr(impObj()->put_Arrowhead1Type((AcDimArrowheadType)val));
}

PyAcDimArrowheadType PyIAcadDimAngularImpl::GetArrowhead2Type() const
{
    AcDimArrowheadType rtval = (AcDimArrowheadType)PyAcDimArrowheadType::pyacArrowDefault;
    PyThrowBadHr(impObj()->get_Arrowhead2Type(&rtval));
    return (PyAcDimArrowheadType)rtval;
}

void PyIAcadDimAngularImpl::SetArrowhead2Type(PyAcDimArrowheadType val) const
{
    PyThrowBadHr(impObj()->put_Arrowhead2Type((AcDimArrowheadType)val));
}
CString PyIAcadDimAngularImpl::GetArrowhead1Block() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_Arrowhead1Block(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadDimAngularImpl::SetArrowhead1Block(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_Arrowhead1Block(bstrval));
}

CString PyIAcadDimAngularImpl::GetArrowhead2Block() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_Arrowhead2Block(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadDimAngularImpl::SetArrowhead2Block(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_Arrowhead2Block(bstrval));
}

CString PyIAcadDimAngularImpl::GetDimensionLinetype() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_DimensionLinetype(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadDimAngularImpl::SetDimensionLinetype(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_DimensionLinetype(bstrval));
}

CString PyIAcadDimAngularImpl::GetExtLine1Linetype() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_ExtLine1Linetype(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadDimAngularImpl::SetExtLine1Linetype(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_ExtLine1Linetype(bstrval));
}

CString PyIAcadDimAngularImpl::GetExtLine2Linetype() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_ExtLine2Linetype(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadDimAngularImpl::SetExtLine2Linetype(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_ExtLine2Linetype(bstrval));
}

double PyIAcadDimAngularImpl::GetMeasurement() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_Measurement(&rtval));
    return rtval;
}

bool PyIAcadDimAngularImpl::GetExtLineFixedLenSuppress() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_ExtLineFixedLenSuppress(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimAngularImpl::SetExtLineFixedLenSuppress(bool val) const
{
    PyThrowBadHr(impObj()->put_ExtLineFixedLenSuppress(val ? VARIANT_TRUE : VARIANT_FALSE));
}

double PyIAcadDimAngularImpl::GetExtLineFixedLen() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_ExtLineFixedLen(&rtval));
    return rtval;
}

void PyIAcadDimAngularImpl::SetExtLineFixedLen(double val) const
{
    PyThrowBadHr(impObj()->put_ExtLineFixedLen(val));
}

bool PyIAcadDimAngularImpl::GetDimConstrForm() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_DimConstrForm(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimAngularImpl::SetDimConstrForm(bool val) const
{
    PyThrowBadHr(impObj()->put_DimConstrForm(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadDimAngularImpl::GetDimConstrReference() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_DimConstrReference(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimAngularImpl::SetDimConstrReference(bool val) const
{
    PyThrowBadHr(impObj()->put_DimConstrReference(val ? VARIANT_TRUE : VARIANT_FALSE));
}

CString PyIAcadDimAngularImpl::GetDimConstrName() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_DimConstrName(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadDimAngularImpl::SetDimConstrName(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_DimConstrName(bstrval));
}

CString PyIAcadDimAngularImpl::GetDimConstrExpression() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_DimConstrExpression(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadDimAngularImpl::SetDimConstrExpression(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_DimConstrExpression(bstrval));
}

CString PyIAcadDimAngularImpl::GetDimConstrValue() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_DimConstrValue(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadDimAngularImpl::SetDimConstrValue(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_DimConstrValue(bstrval));
}

CString PyIAcadDimAngularImpl::GetDimConstrDesc() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_DimConstrDesc(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadDimAngularImpl::SetDimConstrDesc(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_DimConstrDesc(bstrval));
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

void PyIAcadDimDiametricImpl::SetLeaderLength(double val) const
{
    PyThrowBadHr(impObj()->put_LeaderLength(val));
}

bool PyIAcadDimDiametricImpl::GetAltUnits() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_AltUnits(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimDiametricImpl::SetAltUnits(bool val) const
{
    PyThrowBadHr(impObj()->put_AltUnits(val ? VARIANT_TRUE : VARIANT_FALSE));
}

PyAcDimPrecision PyIAcadDimDiametricImpl::GetAltUnitsPrecision() const
{
    AcDimPrecision rtval = (AcDimPrecision)PyAcDimPrecision::pyacDimPrecisionOne;
    PyThrowBadHr(impObj()->get_AltUnitsPrecision(&rtval));
    return (PyAcDimPrecision)rtval;
}

void PyIAcadDimDiametricImpl::SetAltUnitsPrecision(PyAcDimPrecision val) const
{
    PyThrowBadHr(impObj()->put_AltUnitsPrecision((AcDimPrecision)val));
}

double PyIAcadDimDiametricImpl::GetAltUnitsScale() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_AltUnitsScale(&rtval));
    return rtval;
}

void PyIAcadDimDiametricImpl::SetAltUnitsScale(double val) const
{
    PyThrowBadHr(impObj()->put_AltUnitsScale(val));
}

PyAcDimPrecision PyIAcadDimDiametricImpl::GetAltTolerancePrecision() const
{
    AcDimPrecision rtval = (AcDimPrecision)PyAcDimPrecision::pyacDimPrecisionOne;
    PyThrowBadHr(impObj()->get_AltTolerancePrecision(&rtval));
    return (PyAcDimPrecision)rtval;
}

void PyIAcadDimDiametricImpl::SetAltTolerancePrecision(PyAcDimPrecision val) const
{
    PyThrowBadHr(impObj()->put_AltTolerancePrecision((AcDimPrecision)val));
}

PyAcDimUnits PyIAcadDimDiametricImpl::GetAltUnitsFormat() const
{
    AcDimUnits rtval = (AcDimUnits)PyAcDimUnits::pyacDimDecimal;
    PyThrowBadHr(impObj()->get_AltUnitsFormat(&rtval));
    return (PyAcDimUnits)rtval;
}

void PyIAcadDimDiametricImpl::SetAltUnitsFormat(PyAcDimUnits val) const
{
    PyThrowBadHr(impObj()->put_AltUnitsFormat((AcDimUnits)val));
}

CString PyIAcadDimDiametricImpl::GetAltTextPrefix() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_AltTextPrefix(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadDimDiametricImpl::SetAltTextPrefix(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_AltTextPrefix(bstrval));
}

CString PyIAcadDimDiametricImpl::GetAltTextSuffix() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_AltTextSuffix((&bstrVal.GetBSTR())));
    return (LPCTSTR)bstrVal;
}

void PyIAcadDimDiametricImpl::SetAltTextSuffix(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_AltTextSuffix(bstrval));
}

PyAcColor PyIAcadDimDiametricImpl::GetDimensionLineColor() const
{
    AcColor rtval = (AcColor)PyAcColor::pyacByLayer;
    PyThrowBadHr(impObj()->get_DimensionLineColor(&rtval));
    return (PyAcColor)rtval;
}

void PyIAcadDimDiametricImpl::SetDimensionLineColor(PyAcColor val) const
{
    PyThrowBadHr(impObj()->put_DimensionLineColor((AcColor)val));
}

PyAcDimPrecision PyIAcadDimDiametricImpl::GetPrimaryUnitsPrecision() const
{
    AcDimPrecision rtval = (AcDimPrecision)PyAcDimPrecision::pyacDimPrecisionOne;
    PyThrowBadHr(impObj()->get_PrimaryUnitsPrecision(&rtval));
    return (PyAcDimPrecision)rtval;
}

void PyIAcadDimDiametricImpl::SetPrimaryUnitsPrecision(PyAcDimPrecision val) const
{
    PyThrowBadHr(impObj()->put_PrimaryUnitsPrecision((AcDimPrecision)val));
}

PyAcDimFractionType PyIAcadDimDiametricImpl::GetFractionFormat() const
{
    AcDimFractionType rtval = (AcDimFractionType)PyAcDimFractionType::pyacHorizontal;
    PyThrowBadHr(impObj()->get_FractionFormat(&rtval));
    return (PyAcDimFractionType)rtval;
}

void PyIAcadDimDiametricImpl::SetFractionFormat(PyAcDimFractionType val) const
{
    PyThrowBadHr(impObj()->put_FractionFormat((AcDimFractionType)val));
}

PyAcDimFit PyIAcadDimDiametricImpl::GetFit() const
{
    AcDimFit rtval = (AcDimFit)PyAcDimFit::pyacTextAndArrows;
    PyThrowBadHr(impObj()->get_Fit(&rtval));
    return (PyAcDimFit)rtval;
}

void PyIAcadDimDiametricImpl::SetFit(PyAcDimFit val) const
{
    PyThrowBadHr(impObj()->put_Fit((AcDimFit)val));
}

double PyIAcadDimDiametricImpl::GetLinearScaleFactor() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_LinearScaleFactor(&rtval));
    return rtval;
}

void PyIAcadDimDiametricImpl::SetLinearScaleFactor(double val) const
{
    PyThrowBadHr(impObj()->put_LinearScaleFactor(val));
}

PyAcDimLUnits PyIAcadDimDiametricImpl::GetUnitsFormat() const
{
    AcDimLUnits rtval = (AcDimLUnits)PyAcDimLUnits::pyacDimLDecimal;
    PyThrowBadHr(impObj()->get_UnitsFormat(&rtval));
    return (PyAcDimLUnits)rtval;
}

void PyIAcadDimDiametricImpl::SetUnitsFormat(PyAcDimLUnits val) const
{
    PyThrowBadHr(impObj()->put_UnitsFormat((AcDimLUnits)val));
}

double PyIAcadDimDiametricImpl::GetRoundDistance() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_RoundDistance(&rtval));
    return rtval;
}

void PyIAcadDimDiametricImpl::SetRoundDistance(double val) const
{
    PyThrowBadHr(impObj()->put_RoundDistance(val));
}

bool PyIAcadDimDiametricImpl::GetDimLine1Suppress() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_DimLine1Suppress(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimDiametricImpl::SetDimLine1Suppress(bool val) const
{
    PyThrowBadHr(impObj()->put_DimLine1Suppress(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadDimDiametricImpl::GetDimLine2Suppress() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_DimLine2Suppress(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimDiametricImpl::SetDimLine2Suppress(bool val) const
{
    PyThrowBadHr(impObj()->put_DimLine2Suppress(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadDimDiametricImpl::GetTextInsideAlign() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_TextInsideAlign(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimDiametricImpl::SetTextInsideAlign(bool val) const
{
    PyThrowBadHr(impObj()->put_TextInsideAlign(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadDimDiametricImpl::GetTextInside() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_TextInside(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimDiametricImpl::SetTextInside(bool val) const
{
    PyThrowBadHr(impObj()->put_TextInside(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadDimDiametricImpl::GetForceLineInside() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_ForceLineInside(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimDiametricImpl::SetForceLineInside(bool val) const
{
    PyThrowBadHr(impObj()->put_ForceLineInside(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadDimDiametricImpl::GetTextOutsideAlign() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_TextOutsideAlign(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimDiametricImpl::SetTextOutsideAlign(bool val) const
{
    PyThrowBadHr(impObj()->put_TextOutsideAlign(val ? VARIANT_TRUE : VARIANT_FALSE));
}

PyAcDimCenterType PyIAcadDimDiametricImpl::GetCenterType() const
{
    AcDimCenterType rtval = (AcDimCenterType)PyAcDimCenterType::pyacCenterMark;
    PyThrowBadHr(impObj()->get_CenterType(&rtval));
    return (PyAcDimCenterType)rtval;
}

void PyIAcadDimDiametricImpl::SetCenterType(PyAcDimCenterType val) const
{
    PyThrowBadHr(impObj()->put_CenterType((AcDimCenterType)val));
}

double PyIAcadDimDiametricImpl::GetCenterMarkSize() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_CenterMarkSize(&rtval));
    return rtval;
}

void PyIAcadDimDiametricImpl::SetCenterMarkSize(double val) const
{
    PyThrowBadHr(impObj()->put_CenterMarkSize(val));
}

bool PyIAcadDimDiametricImpl::GetAltSuppressLeadingZeros() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_AltSuppressLeadingZeros(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimDiametricImpl::SetAltSuppressLeadingZeros(bool val) const
{
    PyThrowBadHr(impObj()->put_AltSuppressLeadingZeros(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadDimDiametricImpl::GetAltSuppressTrailingZeros() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_AltSuppressTrailingZeros(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimDiametricImpl::SetAltSuppressTrailingZeros(bool val) const
{
    PyThrowBadHr(impObj()->put_AltSuppressTrailingZeros(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadDimDiametricImpl::GetAltSuppressZeroFeet() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_AltSuppressZeroFeet(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimDiametricImpl::SetAltSuppressZeroFeet(bool val) const
{
    PyThrowBadHr(impObj()->put_AltSuppressZeroFeet(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadDimDiametricImpl::GetAltSuppressZeroInches() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_AltSuppressZeroInches(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimDiametricImpl::SetAltSuppressZeroInches(bool val) const
{
    PyThrowBadHr(impObj()->put_AltSuppressZeroInches(val));
}

bool PyIAcadDimDiametricImpl::GetAltToleranceSuppressLeadingZeros() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_AltToleranceSuppressLeadingZeros(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimDiametricImpl::SetAltToleranceSuppressLeadingZeros(bool val) const
{
    PyThrowBadHr(impObj()->put_AltToleranceSuppressLeadingZeros(val));
}

bool PyIAcadDimDiametricImpl::GetAltToleranceSuppressTrailingZeros() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_AltToleranceSuppressTrailingZeros(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimDiametricImpl::SetAltToleranceSuppressTrailingZeros(bool val) const
{
    PyThrowBadHr(impObj()->put_AltToleranceSuppressTrailingZeros(val));
}

bool PyIAcadDimDiametricImpl::GetAltToleranceSuppressZeroFeet() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_AltToleranceSuppressZeroFeet(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimDiametricImpl::SetAltToleranceSuppressZeroFeet(bool val) const
{
    PyThrowBadHr(impObj()->put_AltToleranceSuppressZeroFeet(val));
}

bool PyIAcadDimDiametricImpl::GetAltToleranceSuppressZeroInches() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_AltToleranceSuppressZeroInches(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimDiametricImpl::SetAltToleranceSuppressZeroInches(bool val) const
{
    PyThrowBadHr(impObj()->put_AltToleranceSuppressZeroInches(val));
}

bool PyIAcadDimDiametricImpl::GetSuppressZeroFeet() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_SuppressZeroFeet(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimDiametricImpl::SetSuppressZeroFeet(bool val) const
{
    PyThrowBadHr(impObj()->put_SuppressZeroFeet(val));
}

bool PyIAcadDimDiametricImpl::GetSuppressZeroInches() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_SuppressZeroInches(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimDiametricImpl::SetSuppressZeroInches(bool val) const
{
    PyThrowBadHr(impObj()->put_SuppressZeroInches(val));
}

bool PyIAcadDimDiametricImpl::GetToleranceSuppressZeroFeet() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_ToleranceSuppressZeroFeet(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimDiametricImpl::SetToleranceSuppressZeroFeet(bool val) const
{
    PyThrowBadHr(impObj()->put_ToleranceSuppressZeroFeet(val));
}

bool PyIAcadDimDiametricImpl::GetToleranceSuppressZeroInches() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_ToleranceSuppressZeroInches(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimDiametricImpl::SetToleranceSuppressZeroInches(bool val) const
{
    PyThrowBadHr(impObj()->put_ToleranceSuppressZeroInches(val));
}

PyAcLineWeight PyIAcadDimDiametricImpl::GetDimensionLineWeight() const
{
    AcLineWeight rtval = (AcLineWeight)PyAcLineWeight::pyacLnWt000;
    PyThrowBadHr(impObj()->get_DimensionLineWeight(&rtval));
    return (PyAcLineWeight)rtval;
}

void PyIAcadDimDiametricImpl::SetDimensionLineWeight(PyAcLineWeight val) const
{
    PyThrowBadHr(impObj()->put_DimensionLineWeight((AcLineWeight)val));
}

double PyIAcadDimDiametricImpl::GetArrowheadSize() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_ArrowheadSize(&rtval));
    return rtval;
}

void PyIAcadDimDiametricImpl::SetArrowheadSize(double val) const
{
    PyThrowBadHr(impObj()->put_ArrowheadSize(val));
}

PyAcDimArrowheadType PyIAcadDimDiametricImpl::GetArrowhead1Type() const
{
    AcDimArrowheadType rtval = (AcDimArrowheadType)PyAcDimArrowheadType::pyacArrowDefault;
    PyThrowBadHr(impObj()->get_Arrowhead1Type(&rtval));
    return (PyAcDimArrowheadType)rtval;
}

void PyIAcadDimDiametricImpl::SetArrowhead1Type(PyAcDimArrowheadType val) const
{
    PyThrowBadHr(impObj()->put_Arrowhead1Type((AcDimArrowheadType)val));
}

PyAcDimArrowheadType PyIAcadDimDiametricImpl::GetArrowhead2Type() const
{
    AcDimArrowheadType rtval = (AcDimArrowheadType)PyAcDimArrowheadType::pyacArrowDefault;
    PyThrowBadHr(impObj()->get_Arrowhead2Type(&rtval));
    return (PyAcDimArrowheadType)rtval;
}

void PyIAcadDimDiametricImpl::SetArrowhead2Type(PyAcDimArrowheadType val) const
{
    PyThrowBadHr(impObj()->put_Arrowhead2Type((AcDimArrowheadType)val));
}
CString PyIAcadDimDiametricImpl::GetArrowhead1Block() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_Arrowhead1Block(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadDimDiametricImpl::SetArrowhead1Block(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_Arrowhead1Block(bstrval));
}

CString PyIAcadDimDiametricImpl::GetArrowhead2Block() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_Arrowhead2Block(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadDimDiametricImpl::SetArrowhead2Block(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_Arrowhead2Block(bstrval));
}

CString PyIAcadDimDiametricImpl::GetDimensionLinetype() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_DimensionLinetype(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadDimDiametricImpl::SetDimensionLinetype(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_DimensionLinetype(bstrval));
}

double PyIAcadDimDiametricImpl::GetMeasurement() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_Measurement(&rtval));
    return rtval;
}

bool PyIAcadDimDiametricImpl::GetDimConstrForm() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_DimConstrForm(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimDiametricImpl::SetDimConstrForm(bool val) const
{
    PyThrowBadHr(impObj()->put_DimConstrForm(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadDimDiametricImpl::GetDimConstrReference() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_DimConstrReference(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimDiametricImpl::SetDimConstrReference(bool val) const
{
    PyThrowBadHr(impObj()->put_DimConstrReference(val ? VARIANT_TRUE : VARIANT_FALSE));
}

CString PyIAcadDimDiametricImpl::GetDimConstrName() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_DimConstrName(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadDimDiametricImpl::SetDimConstrName(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_DimConstrName(bstrval));
}

CString PyIAcadDimDiametricImpl::GetDimConstrExpression() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_DimConstrExpression(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadDimDiametricImpl::SetDimConstrExpression(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_DimConstrExpression(bstrval));
}

CString PyIAcadDimDiametricImpl::GetDimConstrValue() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_DimConstrValue(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadDimDiametricImpl::SetDimConstrValue(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_DimConstrValue(bstrval));
}

CString PyIAcadDimDiametricImpl::GetDimConstrDesc() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_DimConstrDesc(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadDimDiametricImpl::SetDimConstrDesc(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_DimConstrDesc(bstrval));
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

bool PyIAcadDimRotatedImpl::GetAltUnits() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_AltUnits(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimRotatedImpl::SetAltUnits(bool val) const
{
    PyThrowBadHr(impObj()->put_AltUnits(val ? VARIANT_TRUE : VARIANT_FALSE));
}

PyAcDimPrecision PyIAcadDimRotatedImpl::GetAltUnitsPrecision() const
{
    AcDimPrecision rtval = (AcDimPrecision)PyAcDimPrecision::pyacDimPrecisionOne;
    PyThrowBadHr(impObj()->get_AltUnitsPrecision(&rtval));
    return (PyAcDimPrecision)rtval;
}

void PyIAcadDimRotatedImpl::SetAltUnitsPrecision(PyAcDimPrecision val) const
{
    PyThrowBadHr(impObj()->put_AltUnitsPrecision((AcDimPrecision)val));
}

double PyIAcadDimRotatedImpl::GetAltUnitsScale() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_AltUnitsScale(&rtval));
    return rtval;
}

void PyIAcadDimRotatedImpl::SetAltUnitsScale(double val) const
{
    PyThrowBadHr(impObj()->put_AltUnitsScale(val));
}

double PyIAcadDimRotatedImpl::GetAltRoundDistance() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_AltRoundDistance(&rtval));
    return rtval;
}

void PyIAcadDimRotatedImpl::SetAltRoundDistance(double val) const
{
    PyThrowBadHr(impObj()->put_AltRoundDistance(val));
}

PyAcDimPrecision PyIAcadDimRotatedImpl::GetAltTolerancePrecision() const
{
    AcDimPrecision rtval = (AcDimPrecision)PyAcDimPrecision::pyacDimPrecisionOne;
    PyThrowBadHr(impObj()->get_AltTolerancePrecision(&rtval));
    return (PyAcDimPrecision)rtval;
}

void PyIAcadDimRotatedImpl::SetAltTolerancePrecision(PyAcDimPrecision val) const
{
    PyThrowBadHr(impObj()->put_AltTolerancePrecision((AcDimPrecision)val));
}

PyAcDimUnits PyIAcadDimRotatedImpl::GetAltUnitsFormat() const
{
    AcDimUnits rtval = (AcDimUnits)PyAcDimUnits::pyacDimDecimal;
    PyThrowBadHr(impObj()->get_AltUnitsFormat(&rtval));
    return (PyAcDimUnits)rtval;
}

void PyIAcadDimRotatedImpl::SetAltUnitsFormat(PyAcDimUnits val) const
{
    PyThrowBadHr(impObj()->put_AltUnitsFormat((AcDimUnits)val));
}

CString PyIAcadDimRotatedImpl::GetAltTextPrefix() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_AltTextPrefix(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadDimRotatedImpl::SetAltTextPrefix(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_AltTextPrefix(bstrval));
}

CString PyIAcadDimRotatedImpl::GetAltTextSuffix() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_AltTextSuffix((&bstrVal.GetBSTR())));
    return (LPCTSTR)bstrVal;
}

void PyIAcadDimRotatedImpl::SetAltTextSuffix(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_AltTextSuffix(bstrval));
}

PyAcColor PyIAcadDimRotatedImpl::GetDimensionLineColor() const
{
    AcColor rtval = (AcColor)PyAcColor::pyacByLayer;
    PyThrowBadHr(impObj()->get_DimensionLineColor(&rtval));
    return (PyAcColor)rtval;
}

void PyIAcadDimRotatedImpl::SetDimensionLineColor(PyAcColor val) const
{
    PyThrowBadHr(impObj()->put_DimensionLineColor((AcColor)val));
}

PyAcColor PyIAcadDimRotatedImpl::GetExtensionLineColor() const
{
    AcColor rtval = (AcColor)PyAcColor::pyacByLayer;
    PyThrowBadHr(impObj()->get_ExtensionLineColor(&rtval));
    return (PyAcColor)rtval;
}

void PyIAcadDimRotatedImpl::SetExtensionLineColor(PyAcColor val) const
{
    PyThrowBadHr(impObj()->put_ExtensionLineColor((AcColor)val));
}

PyAcDimPrecision PyIAcadDimRotatedImpl::GetPrimaryUnitsPrecision() const
{
    AcDimPrecision rtval = (AcDimPrecision)PyAcDimPrecision::pyacDimPrecisionOne;
    PyThrowBadHr(impObj()->get_PrimaryUnitsPrecision(&rtval));
    return (PyAcDimPrecision)rtval;
}

void PyIAcadDimRotatedImpl::SetPrimaryUnitsPrecision(PyAcDimPrecision val) const
{
    PyThrowBadHr(impObj()->put_PrimaryUnitsPrecision((AcDimPrecision)val));
}

double PyIAcadDimRotatedImpl::GetDimensionLineExtend() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_DimensionLineExtend(&rtval));
    return rtval;
}

void PyIAcadDimRotatedImpl::SetDimensionLineExtend(double val) const
{
    PyThrowBadHr(impObj()->put_DimensionLineExtend(val));
}

double PyIAcadDimRotatedImpl::GetExtensionLineExtend() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_ExtensionLineExtend(&rtval));
    return rtval;
}

void PyIAcadDimRotatedImpl::SetExtensionLineExtend(double val) const
{
    PyThrowBadHr(impObj()->put_ExtensionLineExtend(val));
}

PyAcDimFit PyIAcadDimRotatedImpl::GetFit() const
{
    AcDimFit rtval = (AcDimFit)PyAcDimFit::pyacTextAndArrows;
    PyThrowBadHr(impObj()->get_Fit(&rtval));
    return (PyAcDimFit)rtval;
}

void PyIAcadDimRotatedImpl::SetFit(PyAcDimFit val) const
{
    PyThrowBadHr(impObj()->put_Fit((AcDimFit)val));
}

PyAcDimFractionType PyIAcadDimRotatedImpl::GetFractionFormat() const
{
    AcDimFractionType rtval = (AcDimFractionType)PyAcDimFractionType::pyacHorizontal;
    PyThrowBadHr(impObj()->get_FractionFormat(&rtval));
    return (PyAcDimFractionType)rtval;
}

void PyIAcadDimRotatedImpl::SetFractionFormat(PyAcDimFractionType val) const
{
    PyThrowBadHr(impObj()->put_FractionFormat((AcDimFractionType)val));
}

PyAcDimHorizontalJustification PyIAcadDimRotatedImpl::GetHorizontalTextPosition() const
{
    AcDimHorizontalJustification rtval = (AcDimHorizontalJustification)PyAcDimHorizontalJustification::pyacHorzCentered;
    PyThrowBadHr(impObj()->get_HorizontalTextPosition(&rtval));
    return (PyAcDimHorizontalJustification)rtval;
}

void PyIAcadDimRotatedImpl::SetHorizontalTextPosition(PyAcDimHorizontalJustification val) const
{
    PyThrowBadHr(impObj()->put_HorizontalTextPosition((AcDimHorizontalJustification)val));
}

double PyIAcadDimRotatedImpl::GetLinearScaleFactor() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_LinearScaleFactor(&rtval));
    return rtval;
}

void PyIAcadDimRotatedImpl::SetLinearScaleFactor(double val) const
{
    PyThrowBadHr(impObj()->put_LinearScaleFactor(val));
}

PyAcDimLUnits PyIAcadDimRotatedImpl::GetUnitsFormat() const
{
    AcDimLUnits rtval = (AcDimLUnits)PyAcDimLUnits::pyacDimLDecimal;
    PyThrowBadHr(impObj()->get_UnitsFormat(&rtval));
    return (PyAcDimLUnits)rtval;
}

void PyIAcadDimRotatedImpl::SetUnitsFormat(PyAcDimLUnits val) const
{
    PyThrowBadHr(impObj()->put_UnitsFormat((AcDimLUnits)val));
}

PyAcLineWeight PyIAcadDimRotatedImpl::GetExtensionLineWeight() const
{
    AcLineWeight rtval = (AcLineWeight)PyAcLineWeight::pyacLnWt000;
    PyThrowBadHr(impObj()->get_ExtensionLineWeight(&rtval));
    return (PyAcLineWeight)rtval;
}

void PyIAcadDimRotatedImpl::SetExtensionLineWeight(PyAcLineWeight val) const
{
    PyThrowBadHr(impObj()->put_ExtensionLineWeight((AcLineWeight)val));
}

double PyIAcadDimRotatedImpl::GetRoundDistance() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_RoundDistance(&rtval));
    return rtval;
}

void PyIAcadDimRotatedImpl::SetRoundDistance(double val) const
{
    PyThrowBadHr(impObj()->put_RoundDistance(val));
}

bool PyIAcadDimRotatedImpl::GetDimLine1Suppress() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_DimLine1Suppress(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimRotatedImpl::SetDimLine1Suppress(bool val) const
{
    PyThrowBadHr(impObj()->put_DimLine1Suppress(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadDimRotatedImpl::GetDimLine2Suppress() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_DimLine2Suppress(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimRotatedImpl::SetDimLine2Suppress(bool val) const
{
    PyThrowBadHr(impObj()->put_DimLine2Suppress(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadDimRotatedImpl::GetExtLine1Suppress() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_ExtLine1Suppress(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimRotatedImpl::SetExtLine1Suppress(bool val) const
{
    PyThrowBadHr(impObj()->put_ExtLine1Suppress(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadDimRotatedImpl::GetExtLine2Suppress() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_ExtLine2Suppress(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimRotatedImpl::SetExtLine2Suppress(bool val) const
{
    PyThrowBadHr(impObj()->put_ExtLine2Suppress(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadDimRotatedImpl::GetDimLineInside() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_DimLineInside(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimRotatedImpl::SetDimLineInside(bool val) const
{
    PyThrowBadHr(impObj()->put_DimLineInside(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadDimRotatedImpl::GetTextInsideAlign() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_TextInsideAlign(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimRotatedImpl::SetTextInsideAlign(bool val) const
{
    PyThrowBadHr(impObj()->put_TextInsideAlign(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadDimRotatedImpl::GetTextInside() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_TextInside(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimRotatedImpl::SetTextInside(bool val) const
{
    PyThrowBadHr(impObj()->put_TextInside(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadDimRotatedImpl::GetForceLineInside() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_ForceLineInside(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimRotatedImpl::SetForceLineInside(bool val) const
{
    PyThrowBadHr(impObj()->put_ForceLineInside(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadDimRotatedImpl::GetTextOutsideAlign() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_TextOutsideAlign(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimRotatedImpl::SetTextOutsideAlign(bool val) const
{
    PyThrowBadHr(impObj()->put_TextOutsideAlign(val ? VARIANT_TRUE : VARIANT_FALSE));
}

double PyIAcadDimRotatedImpl::GetExtensionLineOffset() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_ExtensionLineOffset(&rtval));
    return rtval;
}

void PyIAcadDimRotatedImpl::SetExtensionLineOffset(double val) const
{
    PyThrowBadHr(impObj()->put_ExtensionLineOffset(val));
}

bool PyIAcadDimRotatedImpl::GetAltSuppressLeadingZeros() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_AltSuppressLeadingZeros(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimRotatedImpl::SetAltSuppressLeadingZeros(bool val) const
{
    PyThrowBadHr(impObj()->put_AltSuppressLeadingZeros(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadDimRotatedImpl::GetAltSuppressTrailingZeros() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_AltSuppressTrailingZeros(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimRotatedImpl::SetAltSuppressTrailingZeros(bool val) const
{
    PyThrowBadHr(impObj()->put_AltSuppressTrailingZeros(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadDimRotatedImpl::GetAltSuppressZeroFeet() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_AltSuppressZeroFeet(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimRotatedImpl::SetAltSuppressZeroFeet(bool val) const
{
    PyThrowBadHr(impObj()->put_AltSuppressZeroFeet(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadDimRotatedImpl::GetAltSuppressZeroInches() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_AltSuppressZeroInches(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimRotatedImpl::SetAltSuppressZeroInches(bool val) const
{
    PyThrowBadHr(impObj()->put_AltSuppressZeroInches(val));
}

bool PyIAcadDimRotatedImpl::GetAltToleranceSuppressLeadingZeros() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_AltToleranceSuppressLeadingZeros(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimRotatedImpl::SetAltToleranceSuppressLeadingZeros(bool val) const
{
    PyThrowBadHr(impObj()->put_AltToleranceSuppressLeadingZeros(val));
}

bool PyIAcadDimRotatedImpl::GetAltToleranceSuppressTrailingZeros() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_AltToleranceSuppressTrailingZeros(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimRotatedImpl::SetAltToleranceSuppressTrailingZeros(bool val) const
{
    PyThrowBadHr(impObj()->put_AltToleranceSuppressTrailingZeros(val));
}

bool PyIAcadDimRotatedImpl::GetAltToleranceSuppressZeroFeet() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_AltToleranceSuppressZeroFeet(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimRotatedImpl::SetAltToleranceSuppressZeroFeet(bool val) const
{
    PyThrowBadHr(impObj()->put_AltToleranceSuppressZeroFeet(val));
}

bool PyIAcadDimRotatedImpl::GetAltToleranceSuppressZeroInches() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_AltToleranceSuppressZeroInches(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimRotatedImpl::SetAltToleranceSuppressZeroInches(bool val) const
{
    PyThrowBadHr(impObj()->put_AltToleranceSuppressZeroInches(val));
}

bool PyIAcadDimRotatedImpl::GetSuppressZeroFeet() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_SuppressZeroFeet(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimRotatedImpl::SetSuppressZeroFeet(bool val) const
{
    PyThrowBadHr(impObj()->put_SuppressZeroFeet(val));
}

bool PyIAcadDimRotatedImpl::GetSuppressZeroInches() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_SuppressZeroInches(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimRotatedImpl::SetSuppressZeroInches(bool val) const
{
    PyThrowBadHr(impObj()->put_SuppressZeroInches(val));
}

bool PyIAcadDimRotatedImpl::GetToleranceSuppressZeroFeet() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_ToleranceSuppressZeroFeet(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimRotatedImpl::SetToleranceSuppressZeroFeet(bool val) const
{
    PyThrowBadHr(impObj()->put_ToleranceSuppressZeroFeet(val));
}

bool PyIAcadDimRotatedImpl::GetToleranceSuppressZeroInches() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_ToleranceSuppressZeroInches(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimRotatedImpl::SetToleranceSuppressZeroInches(bool val) const
{
    PyThrowBadHr(impObj()->put_ToleranceSuppressZeroInches(val));
}

PyAcLineWeight PyIAcadDimRotatedImpl::GetDimensionLineWeight() const
{
    AcLineWeight rtval = (AcLineWeight)PyAcLineWeight::pyacLnWt000;
    PyThrowBadHr(impObj()->get_DimensionLineWeight(&rtval));
    return (PyAcLineWeight)rtval;
}

void PyIAcadDimRotatedImpl::SetDimensionLineWeight(PyAcLineWeight val) const
{
    PyThrowBadHr(impObj()->put_DimensionLineWeight((AcLineWeight)val));
}

double PyIAcadDimRotatedImpl::GetArrowheadSize() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_ArrowheadSize(&rtval));
    return rtval;
}

void PyIAcadDimRotatedImpl::SetArrowheadSize(double val) const
{
    PyThrowBadHr(impObj()->put_ArrowheadSize(val));
}

PyAcDimArrowheadType PyIAcadDimRotatedImpl::GetArrowhead1Type() const
{
    AcDimArrowheadType rtval = (AcDimArrowheadType)PyAcDimArrowheadType::pyacArrowDefault;
    PyThrowBadHr(impObj()->get_Arrowhead1Type(&rtval));
    return (PyAcDimArrowheadType)rtval;
}

void PyIAcadDimRotatedImpl::SetArrowhead1Type(PyAcDimArrowheadType val) const
{
    PyThrowBadHr(impObj()->put_Arrowhead1Type((AcDimArrowheadType)val));
}

PyAcDimArrowheadType PyIAcadDimRotatedImpl::GetArrowhead2Type() const
{
    AcDimArrowheadType rtval = (AcDimArrowheadType)PyAcDimArrowheadType::pyacArrowDefault;
    PyThrowBadHr(impObj()->get_Arrowhead2Type(&rtval));
    return (PyAcDimArrowheadType)rtval;
}

void PyIAcadDimRotatedImpl::SetArrowhead2Type(PyAcDimArrowheadType val) const
{
    PyThrowBadHr(impObj()->put_Arrowhead2Type((AcDimArrowheadType)val));
}

double PyIAcadDimRotatedImpl::GetMeasurement() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_Measurement(&rtval));
    return rtval;
}

CString PyIAcadDimRotatedImpl::GetArrowhead1Block() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_Arrowhead1Block(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadDimRotatedImpl::SetArrowhead1Block(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_Arrowhead1Block(bstrval));
}

CString PyIAcadDimRotatedImpl::GetArrowhead2Block() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_Arrowhead2Block(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadDimRotatedImpl::SetArrowhead2Block(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_Arrowhead2Block(bstrval));
}

CString PyIAcadDimRotatedImpl::GetDimensionLinetype() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_DimensionLinetype(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadDimRotatedImpl::SetDimensionLinetype(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_DimensionLinetype(bstrval));
}

CString PyIAcadDimRotatedImpl::GetExtLine1Linetype() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_ExtLine1Linetype(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadDimRotatedImpl::SetExtLine1Linetype(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_ExtLine1Linetype(bstrval));
}

CString PyIAcadDimRotatedImpl::GetExtLine2Linetype() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_ExtLine2Linetype(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadDimRotatedImpl::SetExtLine2Linetype(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_ExtLine2Linetype(bstrval));
}

bool PyIAcadDimRotatedImpl::GetExtLineFixedLenSuppress() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_ExtLineFixedLenSuppress(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimRotatedImpl::SetExtLineFixedLenSuppress(bool val) const
{
    PyThrowBadHr(impObj()->put_ExtLineFixedLenSuppress(val ? VARIANT_TRUE : VARIANT_FALSE));
}

double PyIAcadDimRotatedImpl::GetExtLineFixedLen() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_ExtLineFixedLen(&rtval));
    return rtval;
}

void PyIAcadDimRotatedImpl::SetExtLineFixedLen(double val) const
{
    PyThrowBadHr(impObj()->put_ExtLineFixedLen(val));
}

bool PyIAcadDimRotatedImpl::GetDimConstrForm() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_DimConstrForm(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimRotatedImpl::SetDimConstrForm(bool val) const
{
    PyThrowBadHr(impObj()->put_DimConstrForm(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadDimRotatedImpl::GetDimConstrReference() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_DimConstrReference(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimRotatedImpl::SetDimConstrReference(bool val) const
{
    PyThrowBadHr(impObj()->put_DimConstrReference(val ? VARIANT_TRUE : VARIANT_FALSE));
}

CString PyIAcadDimRotatedImpl::GetDimConstrName() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_DimConstrName(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadDimRotatedImpl::SetDimConstrName(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_DimConstrName(bstrval));
}

CString PyIAcadDimRotatedImpl::GetDimConstrExpression() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_DimConstrExpression(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadDimRotatedImpl::SetDimConstrExpression(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_DimConstrExpression(bstrval));
}

CString PyIAcadDimRotatedImpl::GetDimConstrValue() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_DimConstrValue(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadDimRotatedImpl::SetDimConstrValue(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_DimConstrValue(bstrval));
}

CString PyIAcadDimRotatedImpl::GetDimConstrDesc() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_DimConstrDesc(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadDimRotatedImpl::SetDimConstrDesc(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_DimConstrDesc(bstrval));
}

CString PyIAcadDimRotatedImpl::GetSubUnitsSuffix() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_SubUnitsSuffix(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadDimRotatedImpl::SetSubUnitsSuffix(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_SubUnitsSuffix(bstrval));
}

double PyIAcadDimRotatedImpl::GetSubUnitsFactor() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_SubUnitsFactor(&rtval));
    return rtval;
}

void PyIAcadDimRotatedImpl::SetSubUnitsFactor(double val) const
{
    PyThrowBadHr(impObj()->put_SubUnitsFactor(val));
}

CString PyIAcadDimRotatedImpl::GetAltSubUnitsSuffix() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_AltSubUnitsSuffix(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadDimRotatedImpl::SetAltSubUnitsSuffix(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_AltSubUnitsSuffix(bstrval));
}

double PyIAcadDimRotatedImpl::GetAltSubUnitsFactor() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_AltSubUnitsFactor(&rtval));
    return rtval;
}

void PyIAcadDimRotatedImpl::SetAltSubUnitsFactor(double val) const
{
    PyThrowBadHr(impObj()->put_AltSubUnitsFactor(val));
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

bool PyIAcadDimOrdinateImpl::GetAltUnits() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_AltUnits(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimOrdinateImpl::SetAltUnits(bool val) const
{
    PyThrowBadHr(impObj()->put_AltUnits(val ? VARIANT_TRUE : VARIANT_FALSE));
}

PyAcDimPrecision PyIAcadDimOrdinateImpl::GetAltUnitsPrecision() const
{
    AcDimPrecision rtval = (AcDimPrecision)PyAcDimPrecision::pyacDimPrecisionOne;
    PyThrowBadHr(impObj()->get_AltUnitsPrecision(&rtval));
    return (PyAcDimPrecision)rtval;
}

void PyIAcadDimOrdinateImpl::SetAltUnitsPrecision(PyAcDimPrecision val) const
{
    PyThrowBadHr(impObj()->put_AltUnitsPrecision((AcDimPrecision)val));
}

double PyIAcadDimOrdinateImpl::GetAltUnitsScale() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_AltUnitsScale(&rtval));
    return rtval;
}

void PyIAcadDimOrdinateImpl::SetAltUnitsScale(double val) const
{
    PyThrowBadHr(impObj()->put_AltUnitsScale(val));
}

double PyIAcadDimOrdinateImpl::GetAltRoundDistance() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_AltRoundDistance(&rtval));
    return rtval;
}

void PyIAcadDimOrdinateImpl::SetAltRoundDistance(double val) const
{
    PyThrowBadHr(impObj()->put_AltRoundDistance(val));
}

PyAcDimPrecision PyIAcadDimOrdinateImpl::GetAltTolerancePrecision() const
{
    AcDimPrecision rtval = (AcDimPrecision)PyAcDimPrecision::pyacDimPrecisionOne;
    PyThrowBadHr(impObj()->get_AltTolerancePrecision(&rtval));
    return (PyAcDimPrecision)rtval;
}

void PyIAcadDimOrdinateImpl::SetAltTolerancePrecision(PyAcDimPrecision val) const
{
    PyThrowBadHr(impObj()->put_AltTolerancePrecision((AcDimPrecision)val));
}

PyAcDimUnits PyIAcadDimOrdinateImpl::GetAltUnitsFormat() const
{
    AcDimUnits rtval = (AcDimUnits)PyAcDimUnits::pyacDimDecimal;
    PyThrowBadHr(impObj()->get_AltUnitsFormat(&rtval));
    return (PyAcDimUnits)rtval;
}

void PyIAcadDimOrdinateImpl::SetAltUnitsFormat(PyAcDimUnits val) const
{
    PyThrowBadHr(impObj()->put_AltUnitsFormat((AcDimUnits)val));
}

CString PyIAcadDimOrdinateImpl::GetAltTextPrefix() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_AltTextPrefix(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadDimOrdinateImpl::SetAltTextPrefix(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_AltTextPrefix(bstrval));
}

CString PyIAcadDimOrdinateImpl::GetAltTextSuffix() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_AltTextSuffix((&bstrVal.GetBSTR())));
    return (LPCTSTR)bstrVal;
}

void PyIAcadDimOrdinateImpl::SetAltTextSuffix(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_AltTextSuffix(bstrval));
}

PyAcColor PyIAcadDimOrdinateImpl::GetExtensionLineColor() const
{
    AcColor rtval = (AcColor)PyAcColor::pyacByLayer;
    PyThrowBadHr(impObj()->get_ExtensionLineColor(&rtval));
    return (PyAcColor)rtval;
}

void PyIAcadDimOrdinateImpl::SetExtensionLineColor(PyAcColor val) const
{
    PyThrowBadHr(impObj()->put_ExtensionLineColor((AcColor)val));
}

PyAcDimPrecision PyIAcadDimOrdinateImpl::GetPrimaryUnitsPrecision() const
{
    AcDimPrecision rtval = (AcDimPrecision)PyAcDimPrecision::pyacDimPrecisionOne;
    PyThrowBadHr(impObj()->get_PrimaryUnitsPrecision(&rtval));
    return (PyAcDimPrecision)rtval;
}

void PyIAcadDimOrdinateImpl::SetPrimaryUnitsPrecision(PyAcDimPrecision val) const
{
    PyThrowBadHr(impObj()->put_PrimaryUnitsPrecision((AcDimPrecision)val));
}

PyAcDimFractionType PyIAcadDimOrdinateImpl::GetFractionFormat() const
{
    AcDimFractionType rtval = (AcDimFractionType)PyAcDimFractionType::pyacHorizontal;
    PyThrowBadHr(impObj()->get_FractionFormat(&rtval));
    return (PyAcDimFractionType)rtval;
}

void PyIAcadDimOrdinateImpl::SetFractionFormat(PyAcDimFractionType val) const
{
    PyThrowBadHr(impObj()->put_FractionFormat((AcDimFractionType)val));
}

double PyIAcadDimOrdinateImpl::GetLinearScaleFactor() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_LinearScaleFactor(&rtval));
    return rtval;
}

void PyIAcadDimOrdinateImpl::SetLinearScaleFactor(double val) const
{
    PyThrowBadHr(impObj()->put_LinearScaleFactor(val));
}
PyAcDimLUnits PyIAcadDimOrdinateImpl::GetUnitsFormat() const
{
    AcDimLUnits rtval = (AcDimLUnits)PyAcDimLUnits::pyacDimLDecimal;
    PyThrowBadHr(impObj()->get_UnitsFormat(&rtval));
    return (PyAcDimLUnits)rtval;
}

void PyIAcadDimOrdinateImpl::SetUnitsFormat(PyAcDimLUnits val) const
{
    PyThrowBadHr(impObj()->put_UnitsFormat((AcDimLUnits)val));
}

PyAcLineWeight PyIAcadDimOrdinateImpl::GetExtensionLineWeight() const
{
    AcLineWeight rtval = (AcLineWeight)PyAcLineWeight::pyacLnWt000;
    PyThrowBadHr(impObj()->get_ExtensionLineWeight(&rtval));
    return (PyAcLineWeight)rtval;
}

void PyIAcadDimOrdinateImpl::SetExtensionLineWeight(PyAcLineWeight val) const
{
    PyThrowBadHr(impObj()->put_ExtensionLineWeight((AcLineWeight)val));
}

double PyIAcadDimOrdinateImpl::GetRoundDistance() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_RoundDistance(&rtval));
    return rtval;
}

void PyIAcadDimOrdinateImpl::SetRoundDistance(double val) const
{
    PyThrowBadHr(impObj()->put_RoundDistance(val));
}

double PyIAcadDimOrdinateImpl::GetExtensionLineOffset() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_ExtensionLineOffset(&rtval));
    return rtval;
}

void PyIAcadDimOrdinateImpl::SetExtensionLineOffset(double val) const
{
    PyThrowBadHr(impObj()->put_ExtensionLineOffset(val));
}

bool PyIAcadDimOrdinateImpl::GetAltSuppressLeadingZeros() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_AltSuppressLeadingZeros(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimOrdinateImpl::SetAltSuppressLeadingZeros(bool val) const
{
    PyThrowBadHr(impObj()->put_AltSuppressLeadingZeros(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadDimOrdinateImpl::GetAltSuppressTrailingZeros() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_AltSuppressTrailingZeros(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimOrdinateImpl::SetAltSuppressTrailingZeros(bool val) const
{
    PyThrowBadHr(impObj()->put_AltSuppressTrailingZeros(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadDimOrdinateImpl::GetAltSuppressZeroFeet() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_AltSuppressZeroFeet(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimOrdinateImpl::SetAltSuppressZeroFeet(bool val) const
{
    PyThrowBadHr(impObj()->put_AltSuppressZeroFeet(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadDimOrdinateImpl::GetAltSuppressZeroInches() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_AltSuppressZeroInches(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimOrdinateImpl::SetAltSuppressZeroInches(bool val) const
{
    PyThrowBadHr(impObj()->put_AltSuppressZeroInches(val));
}

bool PyIAcadDimOrdinateImpl::GetAltToleranceSuppressLeadingZeros() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_AltToleranceSuppressLeadingZeros(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimOrdinateImpl::SetAltToleranceSuppressLeadingZeros(bool val) const
{
    PyThrowBadHr(impObj()->put_AltToleranceSuppressLeadingZeros(val));
}

bool PyIAcadDimOrdinateImpl::GetAltToleranceSuppressTrailingZeros() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_AltToleranceSuppressTrailingZeros(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimOrdinateImpl::SetAltToleranceSuppressTrailingZeros(bool val) const
{
    PyThrowBadHr(impObj()->put_AltToleranceSuppressTrailingZeros(val));
}

bool PyIAcadDimOrdinateImpl::GetAltToleranceSuppressZeroFeet() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_AltToleranceSuppressZeroFeet(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimOrdinateImpl::SetAltToleranceSuppressZeroFeet(bool val) const
{
    PyThrowBadHr(impObj()->put_AltToleranceSuppressZeroFeet(val));
}

bool PyIAcadDimOrdinateImpl::GetAltToleranceSuppressZeroInches() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_AltToleranceSuppressZeroInches(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimOrdinateImpl::SetAltToleranceSuppressZeroInches(bool val) const
{
    PyThrowBadHr(impObj()->put_AltToleranceSuppressZeroInches(val));
}

bool PyIAcadDimOrdinateImpl::GetSuppressZeroFeet() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_SuppressZeroFeet(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimOrdinateImpl::SetSuppressZeroFeet(bool val) const
{
    PyThrowBadHr(impObj()->put_SuppressZeroFeet(val));
}

bool PyIAcadDimOrdinateImpl::GetSuppressZeroInches() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_SuppressZeroInches(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimOrdinateImpl::SetSuppressZeroInches(bool val) const
{
    PyThrowBadHr(impObj()->put_SuppressZeroInches(val));
}

bool PyIAcadDimOrdinateImpl::GetToleranceSuppressZeroFeet() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_ToleranceSuppressZeroFeet(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimOrdinateImpl::SetToleranceSuppressZeroFeet(bool val) const
{
    PyThrowBadHr(impObj()->put_ToleranceSuppressZeroFeet(val));
}

bool PyIAcadDimOrdinateImpl::GetToleranceSuppressZeroInches() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_ToleranceSuppressZeroInches(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimOrdinateImpl::SetToleranceSuppressZeroInches(bool val) const
{
    PyThrowBadHr(impObj()->put_ToleranceSuppressZeroInches(val));
}

double PyIAcadDimOrdinateImpl::GetArrowheadSize() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_ArrowheadSize(&rtval));
    return rtval;
}

void PyIAcadDimOrdinateImpl::SetArrowheadSize(double val) const
{
    PyThrowBadHr(impObj()->put_ArrowheadSize(val));
}

double PyIAcadDimOrdinateImpl::GetMeasurement() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_Measurement(&rtval));
    return rtval;
}

bool PyIAcadDimOrdinateImpl::GetExtLineFixedLenSuppress() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_ExtLineFixedLenSuppress(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimOrdinateImpl::SetExtLineFixedLenSuppress(bool val) const
{
    PyThrowBadHr(impObj()->put_ExtLineFixedLenSuppress(val ? VARIANT_TRUE : VARIANT_FALSE));
}

double PyIAcadDimOrdinateImpl::GetExtLineFixedLen() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_ExtLineFixedLen(&rtval));
    return rtval;
}

void PyIAcadDimOrdinateImpl::SetExtLineFixedLen(double val) const
{
    PyThrowBadHr(impObj()->put_ExtLineFixedLen(val));
}

CString PyIAcadDimOrdinateImpl::GetSubUnitsSuffix() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_SubUnitsSuffix(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadDimOrdinateImpl::SetSubUnitsSuffix(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_SubUnitsSuffix(bstrval));
}

double PyIAcadDimOrdinateImpl::GetSubUnitsFactor() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_SubUnitsFactor(&rtval));
    return rtval;
}

void PyIAcadDimOrdinateImpl::SetSubUnitsFactor(double val) const
{
    PyThrowBadHr(impObj()->put_SubUnitsFactor(val));
}

CString PyIAcadDimOrdinateImpl::GetAltSubUnitsSuffix() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_AltSubUnitsSuffix(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadDimOrdinateImpl::SetAltSubUnitsSuffix(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_AltSubUnitsSuffix(bstrval));
}

double PyIAcadDimOrdinateImpl::GetAltSubUnitsFactor() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_AltSubUnitsFactor(&rtval));
    return rtval;
}

void PyIAcadDimOrdinateImpl::SetAltSubUnitsFactor(double val) const
{
    PyThrowBadHr(impObj()->put_AltSubUnitsFactor(val));
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

void PyIAcadDimRadialImpl::SetLeaderLength(double val) const
{
    PyThrowBadHr(impObj()->put_LeaderLength(val));
}

bool PyIAcadDimRadialImpl::GetAltUnits() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_AltUnits(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimRadialImpl::SetAltUnits(bool val) const
{
    PyThrowBadHr(impObj()->put_AltUnits(val ? VARIANT_TRUE : VARIANT_FALSE));
}

PyAcDimPrecision PyIAcadDimRadialImpl::GetAltUnitsPrecision() const
{
    AcDimPrecision rtval = (AcDimPrecision)PyAcDimPrecision::pyacDimPrecisionOne;
    PyThrowBadHr(impObj()->get_AltUnitsPrecision(&rtval));
    return (PyAcDimPrecision)rtval;
}

void PyIAcadDimRadialImpl::SetAltUnitsPrecision(PyAcDimPrecision val) const
{
    PyThrowBadHr(impObj()->put_AltUnitsPrecision((AcDimPrecision)val));
}

double PyIAcadDimRadialImpl::GetAltUnitsScale() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_AltUnitsScale(&rtval));
    return rtval;
}

void PyIAcadDimRadialImpl::SetAltUnitsScale(double val) const
{
    PyThrowBadHr(impObj()->put_AltUnitsScale(val));
}

double PyIAcadDimRadialImpl::GetAltRoundDistance() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_AltRoundDistance(&rtval));
    return rtval;
}

void PyIAcadDimRadialImpl::SetAltRoundDistance(double val) const
{
    PyThrowBadHr(impObj()->put_AltRoundDistance(val));
}

PyAcDimPrecision PyIAcadDimRadialImpl::GetAltTolerancePrecision() const
{
    AcDimPrecision rtval = (AcDimPrecision)PyAcDimPrecision::pyacDimPrecisionOne;
    PyThrowBadHr(impObj()->get_AltTolerancePrecision(&rtval));
    return (PyAcDimPrecision)rtval;
}

void PyIAcadDimRadialImpl::SetAltTolerancePrecision(PyAcDimPrecision val) const
{
    PyThrowBadHr(impObj()->put_AltTolerancePrecision((AcDimPrecision)val));
}

PyAcDimUnits PyIAcadDimRadialImpl::GetAltUnitsFormat() const
{
    AcDimUnits rtval = (AcDimUnits)PyAcDimUnits::pyacDimDecimal;
    PyThrowBadHr(impObj()->get_AltUnitsFormat(&rtval));
    return (PyAcDimUnits)rtval;
}

void PyIAcadDimRadialImpl::SetAltUnitsFormat(PyAcDimUnits val) const
{
    PyThrowBadHr(impObj()->put_AltUnitsFormat((AcDimUnits)val));
}

CString PyIAcadDimRadialImpl::GetAltTextPrefix() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_AltTextPrefix(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadDimRadialImpl::SetAltTextPrefix(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_AltTextPrefix(bstrval));
}

CString PyIAcadDimRadialImpl::GetAltTextSuffix() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_AltTextSuffix((&bstrVal.GetBSTR())));
    return (LPCTSTR)bstrVal;
}

void PyIAcadDimRadialImpl::SetAltTextSuffix(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_AltTextSuffix(bstrval));
}

PyAcDimCenterType PyIAcadDimRadialImpl::GetCenterType() const
{
    AcDimCenterType rtval = (AcDimCenterType)PyAcDimCenterType::pyacCenterMark;
    PyThrowBadHr(impObj()->get_CenterType(&rtval));
    return (PyAcDimCenterType)rtval;
}

void PyIAcadDimRadialImpl::SetCenterType(PyAcDimCenterType val) const
{
    PyThrowBadHr(impObj()->put_CenterType((AcDimCenterType)val));
}

double PyIAcadDimRadialImpl::GetCenterMarkSize() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_CenterMarkSize(&rtval));
    return rtval;
}

void PyIAcadDimRadialImpl::SetCenterMarkSize(double val) const
{
    PyThrowBadHr(impObj()->put_CenterMarkSize(val));
}

PyAcColor PyIAcadDimRadialImpl::GetDimensionLineColor() const
{
    AcColor rtval = (AcColor)PyAcColor::pyacByLayer;
    PyThrowBadHr(impObj()->get_DimensionLineColor(&rtval));
    return (PyAcColor)rtval;
}

void PyIAcadDimRadialImpl::SetDimensionLineColor(PyAcColor val) const
{
    PyThrowBadHr(impObj()->put_DimensionLineColor((AcColor)val));
}

PyAcDimPrecision PyIAcadDimRadialImpl::GetPrimaryUnitsPrecision() const
{
    AcDimPrecision rtval = (AcDimPrecision)PyAcDimPrecision::pyacDimPrecisionOne;
    PyThrowBadHr(impObj()->get_PrimaryUnitsPrecision(&rtval));
    return (PyAcDimPrecision)rtval;
}

void PyIAcadDimRadialImpl::SetPrimaryUnitsPrecision(PyAcDimPrecision val) const
{
    PyThrowBadHr(impObj()->put_PrimaryUnitsPrecision((AcDimPrecision)val));
}

PyAcDimFractionType PyIAcadDimRadialImpl::GetFractionFormat() const
{
    AcDimFractionType rtval = (AcDimFractionType)PyAcDimFractionType::pyacHorizontal;
    PyThrowBadHr(impObj()->get_FractionFormat(&rtval));
    return (PyAcDimFractionType)rtval;
}

void PyIAcadDimRadialImpl::SetFractionFormat(PyAcDimFractionType val) const
{
    PyThrowBadHr(impObj()->put_FractionFormat((AcDimFractionType)val));
}

PyAcDimFit PyIAcadDimRadialImpl::GetFit() const
{
    AcDimFit rtval = (AcDimFit)PyAcDimFit::pyacTextAndArrows;
    PyThrowBadHr(impObj()->get_Fit(&rtval));
    return (PyAcDimFit)rtval;
}

void PyIAcadDimRadialImpl::SetFit(PyAcDimFit val) const
{
    PyThrowBadHr(impObj()->put_Fit((AcDimFit)val));
}

double PyIAcadDimRadialImpl::GetLinearScaleFactor() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_LinearScaleFactor(&rtval));
    return rtval;
}

void PyIAcadDimRadialImpl::SetLinearScaleFactor(double val) const
{
    PyThrowBadHr(impObj()->put_LinearScaleFactor(val));
}
PyAcDimLUnits PyIAcadDimRadialImpl::GetUnitsFormat() const
{
    AcDimLUnits rtval = (AcDimLUnits)PyAcDimLUnits::pyacDimLDecimal;
    PyThrowBadHr(impObj()->get_UnitsFormat(&rtval));
    return (PyAcDimLUnits)rtval;
}

void PyIAcadDimRadialImpl::SetUnitsFormat(PyAcDimLUnits val) const
{
    PyThrowBadHr(impObj()->put_UnitsFormat((AcDimLUnits)val));
}

double PyIAcadDimRadialImpl::GetRoundDistance() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_RoundDistance(&rtval));
    return rtval;
}

void PyIAcadDimRadialImpl::SetRoundDistance(double val) const
{
    PyThrowBadHr(impObj()->put_RoundDistance(val));
}

bool PyIAcadDimRadialImpl::GetDimLineSuppress() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_DimLineSuppress(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimRadialImpl::SetDimLineSuppress(bool val) const
{
    PyThrowBadHr(impObj()->put_DimLineSuppress(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadDimRadialImpl::GetTextInsideAlign() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_TextInsideAlign(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimRadialImpl::SetTextInsideAlign(bool val) const
{
    PyThrowBadHr(impObj()->put_TextInsideAlign(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadDimRadialImpl::GetTextInside() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_TextInside(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimRadialImpl::SetTextInside(bool val) const
{
    PyThrowBadHr(impObj()->put_TextInside(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadDimRadialImpl::GetForceLineInside() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_ForceLineInside(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimRadialImpl::SetForceLineInside(bool val) const
{
    PyThrowBadHr(impObj()->put_ForceLineInside(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadDimRadialImpl::GetTextOutsideAlign() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_TextOutsideAlign(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimRadialImpl::SetTextOutsideAlign(bool val) const
{
    PyThrowBadHr(impObj()->put_TextOutsideAlign(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadDimRadialImpl::GetAltSuppressLeadingZeros() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_AltSuppressLeadingZeros(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimRadialImpl::SetAltSuppressLeadingZeros(bool val) const
{
    PyThrowBadHr(impObj()->put_AltSuppressLeadingZeros(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadDimRadialImpl::GetAltSuppressTrailingZeros() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_AltSuppressTrailingZeros(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimRadialImpl::SetAltSuppressTrailingZeros(bool val) const
{
    PyThrowBadHr(impObj()->put_AltSuppressTrailingZeros(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadDimRadialImpl::GetAltSuppressZeroFeet() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_AltSuppressZeroFeet(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimRadialImpl::SetAltSuppressZeroFeet(bool val) const
{
    PyThrowBadHr(impObj()->put_AltSuppressZeroFeet(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadDimRadialImpl::GetAltSuppressZeroInches() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_AltSuppressZeroInches(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimRadialImpl::SetAltSuppressZeroInches(bool val) const
{
    PyThrowBadHr(impObj()->put_AltSuppressZeroInches(val));
}

bool PyIAcadDimRadialImpl::GetAltToleranceSuppressLeadingZeros() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_AltToleranceSuppressLeadingZeros(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimRadialImpl::SetAltToleranceSuppressLeadingZeros(bool val) const
{
    PyThrowBadHr(impObj()->put_AltToleranceSuppressLeadingZeros(val));
}

bool PyIAcadDimRadialImpl::GetAltToleranceSuppressTrailingZeros() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_AltToleranceSuppressTrailingZeros(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimRadialImpl::SetAltToleranceSuppressTrailingZeros(bool val) const
{
    PyThrowBadHr(impObj()->put_AltToleranceSuppressTrailingZeros(val));
}

bool PyIAcadDimRadialImpl::GetAltToleranceSuppressZeroFeet() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_AltToleranceSuppressZeroFeet(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimRadialImpl::SetAltToleranceSuppressZeroFeet(bool val) const
{
    PyThrowBadHr(impObj()->put_AltToleranceSuppressZeroFeet(val));
}

bool PyIAcadDimRadialImpl::GetAltToleranceSuppressZeroInches() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_AltToleranceSuppressZeroInches(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimRadialImpl::SetAltToleranceSuppressZeroInches(bool val) const
{
    PyThrowBadHr(impObj()->put_AltToleranceSuppressZeroInches(val));
}

bool PyIAcadDimRadialImpl::GetSuppressZeroFeet() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_SuppressZeroFeet(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimRadialImpl::SetSuppressZeroFeet(bool val) const
{
    PyThrowBadHr(impObj()->put_SuppressZeroFeet(val));
}

bool PyIAcadDimRadialImpl::GetSuppressZeroInches() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_SuppressZeroInches(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimRadialImpl::SetSuppressZeroInches(bool val) const
{
    PyThrowBadHr(impObj()->put_SuppressZeroInches(val));
}

bool PyIAcadDimRadialImpl::GetToleranceSuppressZeroFeet() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_ToleranceSuppressZeroFeet(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimRadialImpl::SetToleranceSuppressZeroFeet(bool val) const
{
    PyThrowBadHr(impObj()->put_ToleranceSuppressZeroFeet(val));
}

bool PyIAcadDimRadialImpl::GetToleranceSuppressZeroInches() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_ToleranceSuppressZeroInches(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimRadialImpl::SetToleranceSuppressZeroInches(bool val) const
{
    PyThrowBadHr(impObj()->put_ToleranceSuppressZeroInches(val));
}

PyAcLineWeight PyIAcadDimRadialImpl::GetDimensionLineWeight() const
{
    AcLineWeight rtval = (AcLineWeight)PyAcLineWeight::pyacLnWt000;
    PyThrowBadHr(impObj()->get_DimensionLineWeight(&rtval));
    return (PyAcLineWeight)rtval;
}

void PyIAcadDimRadialImpl::SetDimensionLineWeight(PyAcLineWeight val) const
{
    PyThrowBadHr(impObj()->put_DimensionLineWeight((AcLineWeight)val));
}

double PyIAcadDimRadialImpl::GetArrowheadSize() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_ArrowheadSize(&rtval));
    return rtval;
}

void PyIAcadDimRadialImpl::SetArrowheadSize(double val) const
{
    PyThrowBadHr(impObj()->put_ArrowheadSize(val));
}

PyAcDimArrowheadType PyIAcadDimRadialImpl::GetArrowheadType() const
{
    AcDimArrowheadType rtval = (AcDimArrowheadType)PyAcDimArrowheadType::pyacArrowDefault;
    PyThrowBadHr(impObj()->get_ArrowheadType(&rtval));
    return (PyAcDimArrowheadType)rtval;
}

void PyIAcadDimRadialImpl::SetArrowheadType(PyAcDimArrowheadType val) const
{
    PyThrowBadHr(impObj()->put_ArrowheadType((AcDimArrowheadType)val));
}

double PyIAcadDimRadialImpl::GetMeasurement() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_Measurement(&rtval));
    return rtval;
}

CString PyIAcadDimRadialImpl::GetArrowheadBlock() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_ArrowheadBlock(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadDimRadialImpl::SetArrowheadBlock(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_ArrowheadBlock(bstrval));
}

CString PyIAcadDimRadialImpl::GetDimensionLinetype() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_DimensionLinetype(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadDimRadialImpl::SetDimensionLinetype(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_DimensionLinetype(bstrval));
}

bool PyIAcadDimRadialImpl::GetDimConstrForm() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_DimConstrForm(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimRadialImpl::SetDimConstrForm(bool val) const
{
    PyThrowBadHr(impObj()->put_DimConstrForm(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadDimRadialImpl::GetDimConstrReference() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_DimConstrReference(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimRadialImpl::SetDimConstrReference(bool val) const
{
    PyThrowBadHr(impObj()->put_DimConstrReference(val ? VARIANT_TRUE : VARIANT_FALSE));
}

CString PyIAcadDimRadialImpl::GetDimConstrName() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_DimConstrName(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadDimRadialImpl::SetDimConstrName(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_DimConstrName(bstrval));
}

CString PyIAcadDimRadialImpl::GetDimConstrExpression() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_DimConstrExpression(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadDimRadialImpl::SetDimConstrExpression(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_DimConstrExpression(bstrval));
}

CString PyIAcadDimRadialImpl::GetDimConstrValue() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_DimConstrValue(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadDimRadialImpl::SetDimConstrValue(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_DimConstrValue(bstrval));
}

CString PyIAcadDimRadialImpl::GetDimConstrDesc() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_DimConstrDesc(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadDimRadialImpl::SetDimConstrDesc(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_DimConstrDesc(bstrval));
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

AcGePoint3d PyIAcadDim3PointAngularImpl::GetExtLine1EndPoint() const
{
    _variant_t vtval;
    AcGePoint3d rtval;
    PyThrowBadHr(impObj()->get_ExtLine1EndPoint(&vtval));
    PyThrowBadHr(VariantToAcGePoint3d(vtval, rtval));
    return rtval;
}

void PyIAcadDim3PointAngularImpl::SetExtLine1EndPoint(const AcGePoint3d& val) const
{
    _variant_t vtval;
    PyThrowBadHr(AcGePoint3dToVariant(vtval.GetVARIANT(), val));
    PyThrowBadHr(impObj()->put_ExtLine1EndPoint(vtval));
}

AcGePoint3d PyIAcadDim3PointAngularImpl::GetExtLine2EndPoint() const
{
    _variant_t vtval;
    AcGePoint3d rtval;
    PyThrowBadHr(impObj()->get_ExtLine1EndPoint(&vtval));
    PyThrowBadHr(VariantToAcGePoint3d(vtval, rtval));
    return rtval;
}

void PyIAcadDim3PointAngularImpl::SetExtLine2EndPoint(const AcGePoint3d& val) const
{
    _variant_t vtval;
    PyThrowBadHr(AcGePoint3dToVariant(vtval.GetVARIANT(), val));
    PyThrowBadHr(impObj()->put_ExtLine1EndPoint(vtval));
}

AcGePoint3d PyIAcadDim3PointAngularImpl::GetAngleVertex() const
{
    _variant_t vtval;
    AcGePoint3d rtval;
    PyThrowBadHr(impObj()->get_AngleVertex(&vtval));
    PyThrowBadHr(VariantToAcGePoint3d(vtval, rtval));
    return rtval;
}

void PyIAcadDim3PointAngularImpl::SetAngleVertex(const AcGePoint3d& val) const
{
    _variant_t vtval;
    PyThrowBadHr(AcGePoint3dToVariant(vtval.GetVARIANT(), val));
    PyThrowBadHr(impObj()->put_AngleVertex(vtval));
}

PyAcDimPrecision PyIAcadDim3PointAngularImpl::GetTextPrecision() const
{
    AcDimPrecision rtval = (AcDimPrecision)PyAcDimPrecision::pyacDimPrecisionZero;
    PyThrowBadHr(impObj()->get_TextPrecision(&rtval));
    return (PyAcDimPrecision)rtval;
}

void PyIAcadDim3PointAngularImpl::SetTextPrecision(PyAcDimPrecision val) const
{
    PyThrowBadHr(impObj()->put_TextPrecision((AcDimPrecision)val));
}

PyAcAngleUnits PyIAcadDim3PointAngularImpl::GetAngleFormat() const
{
    AcAngleUnits rtval = (AcAngleUnits)PyAcAngleUnits::pyacDegrees;
    PyThrowBadHr(impObj()->get_AngleFormat(&rtval));
    return (PyAcAngleUnits)rtval;
}

void PyIAcadDim3PointAngularImpl::SetAngleFormat(PyAcAngleUnits val) const
{
    PyThrowBadHr(impObj()->put_AngleFormat((AcAngleUnits)val));
}

PyAcColor PyIAcadDim3PointAngularImpl::GetDimensionLineColor() const
{
    AcColor rtval = (AcColor)PyAcColor::pyacByLayer;
    PyThrowBadHr(impObj()->get_DimensionLineColor(&rtval));
    return (PyAcColor)rtval;
}

void PyIAcadDim3PointAngularImpl::SetDimensionLineColor(PyAcColor val) const
{
    PyThrowBadHr(impObj()->put_DimensionLineColor((AcColor)val));
}

PyAcColor PyIAcadDim3PointAngularImpl::GetExtensionLineColor() const
{
    AcColor rtval = (AcColor)PyAcColor::pyacByLayer;
    PyThrowBadHr(impObj()->get_ExtensionLineColor(&rtval));
    return (PyAcColor)rtval;
}

void PyIAcadDim3PointAngularImpl::SetExtensionLineColor(PyAcColor val) const
{
    PyThrowBadHr(impObj()->put_ExtensionLineColor((AcColor)val));
}

double PyIAcadDim3PointAngularImpl::GetExtensionLineExtend() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_ExtensionLineExtend(&rtval));
    return rtval;
}

void PyIAcadDim3PointAngularImpl::SetExtensionLineExtend(double val) const
{
    PyThrowBadHr(impObj()->put_ExtensionLineExtend(val));
}

PyAcDimFit PyIAcadDim3PointAngularImpl::GetFit() const
{
    AcDimFit rtval = (AcDimFit)PyAcDimFit::pyacTextAndArrows;
    PyThrowBadHr(impObj()->get_Fit(&rtval));
    return (PyAcDimFit)rtval;
}

void PyIAcadDim3PointAngularImpl::SetFit(PyAcDimFit val) const
{
    PyThrowBadHr(impObj()->put_Fit((AcDimFit)val));
}

PyAcDimHorizontalJustification PyIAcadDim3PointAngularImpl::GetHorizontalTextPosition() const
{
    AcDimHorizontalJustification rtval = (AcDimHorizontalJustification)PyAcDimHorizontalJustification::pyacHorzCentered;
    PyThrowBadHr(impObj()->get_HorizontalTextPosition(&rtval));
    return (PyAcDimHorizontalJustification)rtval;
}

void PyIAcadDim3PointAngularImpl::SetHorizontalTextPosition(PyAcDimHorizontalJustification val) const
{
    PyThrowBadHr(impObj()->put_HorizontalTextPosition((AcDimHorizontalJustification)val));
}

PyAcLineWeight PyIAcadDim3PointAngularImpl::GetExtensionLineWeight() const
{
    AcLineWeight rtval = (AcLineWeight)PyAcLineWeight::pyacLnWt000;
    PyThrowBadHr(impObj()->get_ExtensionLineWeight(&rtval));
    return (PyAcLineWeight)rtval;
}

void PyIAcadDim3PointAngularImpl::SetExtensionLineWeight(PyAcLineWeight val) const
{
    PyThrowBadHr(impObj()->put_ExtensionLineWeight((AcLineWeight)val));
}

bool PyIAcadDim3PointAngularImpl::GetDimLine1Suppress() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_DimLine1Suppress(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDim3PointAngularImpl::SetDimLine1Suppress(bool val) const
{
    PyThrowBadHr(impObj()->put_DimLine1Suppress(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadDim3PointAngularImpl::GetDimLine2Suppress() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_DimLine2Suppress(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDim3PointAngularImpl::SetDimLine2Suppress(bool val) const
{
    PyThrowBadHr(impObj()->put_DimLine2Suppress(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadDim3PointAngularImpl::GetExtLine1Suppress() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_ExtLine1Suppress(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDim3PointAngularImpl::SetExtLine1Suppress(bool val) const
{
    PyThrowBadHr(impObj()->put_ExtLine1Suppress(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadDim3PointAngularImpl::GetExtLine2Suppress() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_ExtLine2Suppress(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDim3PointAngularImpl::SetExtLine2Suppress(bool val) const
{
    PyThrowBadHr(impObj()->put_ExtLine2Suppress(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadDim3PointAngularImpl::GetDimLineInside() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_DimLineInside(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDim3PointAngularImpl::SetDimLineInside(bool val) const
{
    PyThrowBadHr(impObj()->put_DimLineInside(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadDim3PointAngularImpl::GetTextInsideAlign() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_TextInsideAlign(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDim3PointAngularImpl::SetTextInsideAlign(bool val) const
{
    PyThrowBadHr(impObj()->put_TextInsideAlign(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadDim3PointAngularImpl::GetTextInside() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_TextInside(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDim3PointAngularImpl::SetTextInside(bool val) const
{
    PyThrowBadHr(impObj()->put_TextInside(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadDim3PointAngularImpl::GetForceLineInside() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_ForceLineInside(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDim3PointAngularImpl::SetForceLineInside(bool val) const
{
    PyThrowBadHr(impObj()->put_ForceLineInside(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadDim3PointAngularImpl::GetTextOutsideAlign() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_TextOutsideAlign(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDim3PointAngularImpl::SetTextOutsideAlign(bool val) const
{
    PyThrowBadHr(impObj()->put_TextOutsideAlign(val ? VARIANT_TRUE : VARIANT_FALSE));
}

double PyIAcadDim3PointAngularImpl::GetExtensionLineOffset() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_ExtensionLineOffset(&rtval));
    return rtval;
}

void PyIAcadDim3PointAngularImpl::SetExtensionLineOffset(double val) const
{
    PyThrowBadHr(impObj()->put_ExtensionLineOffset(val));
}

PyAcLineWeight PyIAcadDim3PointAngularImpl::GetDimensionLineWeight() const
{
    AcLineWeight rtval = (AcLineWeight)PyAcLineWeight::pyacLnWt000;
    PyThrowBadHr(impObj()->get_DimensionLineWeight(&rtval));
    return (PyAcLineWeight)rtval;
}

void PyIAcadDim3PointAngularImpl::SetDimensionLineWeight(PyAcLineWeight val) const
{
    PyThrowBadHr(impObj()->put_DimensionLineWeight((AcLineWeight)val));
}

double PyIAcadDim3PointAngularImpl::GetArrowheadSize() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_ArrowheadSize(&rtval));
    return rtval;
}

void PyIAcadDim3PointAngularImpl::SetArrowheadSize(double val) const
{
    PyThrowBadHr(impObj()->put_ArrowheadSize(val));
}

PyAcDimArrowheadType PyIAcadDim3PointAngularImpl::GetArrowhead1Type() const
{
    AcDimArrowheadType rtval = (AcDimArrowheadType)PyAcDimArrowheadType::pyacArrowDefault;
    PyThrowBadHr(impObj()->get_Arrowhead1Type(&rtval));
    return (PyAcDimArrowheadType)rtval;
}

void PyIAcadDim3PointAngularImpl::SetArrowhead1Type(PyAcDimArrowheadType val) const
{
    PyThrowBadHr(impObj()->put_Arrowhead1Type((AcDimArrowheadType)val));
}

PyAcDimArrowheadType PyIAcadDim3PointAngularImpl::GetArrowhead2Type() const
{
    AcDimArrowheadType rtval = (AcDimArrowheadType)PyAcDimArrowheadType::pyacArrowDefault;
    PyThrowBadHr(impObj()->get_Arrowhead2Type(&rtval));
    return (PyAcDimArrowheadType)rtval;
}

void PyIAcadDim3PointAngularImpl::SetArrowhead2Type(PyAcDimArrowheadType val) const
{
    PyThrowBadHr(impObj()->put_Arrowhead2Type((AcDimArrowheadType)val));
}

double PyIAcadDim3PointAngularImpl::GetMeasurement() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_Measurement(&rtval));
    return rtval;
}

CString PyIAcadDim3PointAngularImpl::GetArrowhead1Block() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_Arrowhead1Block(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadDim3PointAngularImpl::SetArrowhead1Block(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_Arrowhead1Block(bstrval));
}

CString PyIAcadDim3PointAngularImpl::GetArrowhead2Block() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_Arrowhead2Block(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadDim3PointAngularImpl::SetArrowhead2Block(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_Arrowhead2Block(bstrval));
}

CString PyIAcadDim3PointAngularImpl::GetDimensionLinetype() const
{
#ifdef _BRXTARGET260
    throw PyNotimplementedByHost{};
#else
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_DimensionLinetype(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
#endif
}

void PyIAcadDim3PointAngularImpl::SetDimensionLinetype(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_DimensionLinetype(bstrval));
}

CString PyIAcadDim3PointAngularImpl::GetExtLine1Linetype() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_ExtLine1Linetype(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadDim3PointAngularImpl::SetExtLine1Linetype(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_ExtLine1Linetype(bstrval));
}

CString PyIAcadDim3PointAngularImpl::GetExtLine2Linetype() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_ExtLine2Linetype(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadDim3PointAngularImpl::SetExtLine2Linetype(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_ExtLine2Linetype(bstrval));
}

bool PyIAcadDim3PointAngularImpl::GetExtLineFixedLenSuppress() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_ExtLineFixedLenSuppress(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDim3PointAngularImpl::SetExtLineFixedLenSuppress(bool val) const
{
    PyThrowBadHr(impObj()->put_ExtLineFixedLenSuppress(val ? VARIANT_TRUE : VARIANT_FALSE));
}

double PyIAcadDim3PointAngularImpl::GetExtLineFixedLen() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_ExtLineFixedLen(&rtval));
    return rtval;
}

void PyIAcadDim3PointAngularImpl::SetExtLineFixedLen(double val) const
{
    PyThrowBadHr(impObj()->put_ExtLineFixedLen(val));
}

bool PyIAcadDim3PointAngularImpl::GetDimConstrForm() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_DimConstrForm(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDim3PointAngularImpl::SetDimConstrForm(bool val) const
{
    PyThrowBadHr(impObj()->put_DimConstrForm(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadDim3PointAngularImpl::GetDimConstrReference() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_DimConstrReference(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDim3PointAngularImpl::SetDimConstrReference(bool val) const
{
    PyThrowBadHr(impObj()->put_DimConstrReference(val ? VARIANT_TRUE : VARIANT_FALSE));
}

CString PyIAcadDim3PointAngularImpl::GetDimConstrName() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_DimConstrName(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadDim3PointAngularImpl::SetDimConstrName(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_DimConstrName(bstrval));
}

CString PyIAcadDim3PointAngularImpl::GetDimConstrExpression() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_DimConstrExpression(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadDim3PointAngularImpl::SetDimConstrExpression(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_DimConstrExpression(bstrval));
}

CString PyIAcadDim3PointAngularImpl::GetDimConstrValue() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_DimConstrValue(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadDim3PointAngularImpl::SetDimConstrValue(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_DimConstrValue(bstrval));
}

CString PyIAcadDim3PointAngularImpl::GetDimConstrDesc() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_DimConstrDesc(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadDim3PointAngularImpl::SetDimConstrDesc(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_DimConstrDesc(bstrval));
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

bool PyIAcadDimArcLengthImpl::GetAltUnits() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_AltUnits(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimArcLengthImpl::SetAltUnits(bool val) const
{
    PyThrowBadHr(impObj()->put_AltUnits(val ? VARIANT_TRUE : VARIANT_FALSE));
}

PyAcDimPrecision PyIAcadDimArcLengthImpl::GetAltUnitsPrecision() const
{
    AcDimPrecision rtval = (AcDimPrecision)PyAcDimPrecision::pyacDimPrecisionOne;
    PyThrowBadHr(impObj()->get_AltUnitsPrecision(&rtval));
    return (PyAcDimPrecision)rtval;
}

void PyIAcadDimArcLengthImpl::SetAltUnitsPrecision(PyAcDimPrecision val) const
{
    PyThrowBadHr(impObj()->put_AltUnitsPrecision((AcDimPrecision)val));
}

double PyIAcadDimArcLengthImpl::GetAltUnitsScale() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_AltUnitsScale(&rtval));
    return rtval;
}

void PyIAcadDimArcLengthImpl::SetAltUnitsScale(double val) const
{
    PyThrowBadHr(impObj()->put_AltUnitsScale(val));
}

double PyIAcadDimArcLengthImpl::GetAltRoundDistance() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_AltRoundDistance(&rtval));
    return rtval;
}

void PyIAcadDimArcLengthImpl::SetAltRoundDistance(double val) const
{
    PyThrowBadHr(impObj()->put_AltRoundDistance(val));
}

PyAcDimPrecision PyIAcadDimArcLengthImpl::GetAltTolerancePrecision() const
{
    AcDimPrecision rtval = (AcDimPrecision)PyAcDimPrecision::pyacDimPrecisionOne;
    PyThrowBadHr(impObj()->get_AltTolerancePrecision(&rtval));
    return (PyAcDimPrecision)rtval;
}

void PyIAcadDimArcLengthImpl::SetAltTolerancePrecision(PyAcDimPrecision val) const
{
    PyThrowBadHr(impObj()->put_AltTolerancePrecision((AcDimPrecision)val));
}

PyAcDimUnits PyIAcadDimArcLengthImpl::GetAltUnitsFormat() const
{
    AcDimUnits rtval = (AcDimUnits)PyAcDimUnits::pyacDimDecimal;
    PyThrowBadHr(impObj()->get_AltUnitsFormat(&rtval));
    return (PyAcDimUnits)rtval;
}

void PyIAcadDimArcLengthImpl::SetAltUnitsFormat(PyAcDimUnits val) const
{
    PyThrowBadHr(impObj()->put_AltUnitsFormat((AcDimUnits)val));
}

CString PyIAcadDimArcLengthImpl::GetAltTextPrefix() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_AltTextPrefix(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadDimArcLengthImpl::SetAltTextPrefix(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_AltTextPrefix(bstrval));
}

CString PyIAcadDimArcLengthImpl::GetAltTextSuffix() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_AltTextSuffix((&bstrVal.GetBSTR())));
    return (LPCTSTR)bstrVal;
}

void PyIAcadDimArcLengthImpl::SetAltTextSuffix(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_AltTextSuffix(bstrval));
}

PyAcColor PyIAcadDimArcLengthImpl::GetDimensionLineColor() const
{
    AcColor rtval = (AcColor)PyAcColor::pyacByLayer;
    PyThrowBadHr(impObj()->get_DimensionLineColor(&rtval));
    return (PyAcColor)rtval;
}

void PyIAcadDimArcLengthImpl::SetDimensionLineColor(PyAcColor val) const
{
    PyThrowBadHr(impObj()->put_DimensionLineColor((AcColor)val));
}

PyAcColor PyIAcadDimArcLengthImpl::GetExtensionLineColor() const
{
    AcColor rtval = (AcColor)PyAcColor::pyacByLayer;
    PyThrowBadHr(impObj()->get_ExtensionLineColor(&rtval));
    return (PyAcColor)rtval;
}

void PyIAcadDimArcLengthImpl::SetExtensionLineColor(PyAcColor val) const
{
    PyThrowBadHr(impObj()->put_ExtensionLineColor((AcColor)val));
}

PyAcDimPrecision PyIAcadDimArcLengthImpl::GetPrimaryUnitsPrecision() const
{
    AcDimPrecision rtval = (AcDimPrecision)PyAcDimPrecision::pyacDimPrecisionOne;
    PyThrowBadHr(impObj()->get_PrimaryUnitsPrecision(&rtval));
    return (PyAcDimPrecision)rtval;
}

void PyIAcadDimArcLengthImpl::SetPrimaryUnitsPrecision(PyAcDimPrecision val) const
{
    PyThrowBadHr(impObj()->put_PrimaryUnitsPrecision((AcDimPrecision)val));
}

double PyIAcadDimArcLengthImpl::GetDimensionLineExtend() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_DimensionLineExtend(&rtval));
    return rtval;
}

void PyIAcadDimArcLengthImpl::SetDimensionLineExtend(double val) const
{
    PyThrowBadHr(impObj()->put_DimensionLineExtend(val));
}

double PyIAcadDimArcLengthImpl::GetExtensionLineExtend() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_ExtensionLineExtend(&rtval));
    return rtval;
}

void PyIAcadDimArcLengthImpl::SetExtensionLineExtend(double val) const
{
    PyThrowBadHr(impObj()->put_ExtensionLineExtend(val));
}

PyAcDimFit PyIAcadDimArcLengthImpl::GetFit() const
{
    AcDimFit rtval = (AcDimFit)PyAcDimFit::pyacTextAndArrows;
    PyThrowBadHr(impObj()->get_Fit(&rtval));
    return (PyAcDimFit)rtval;
}

void PyIAcadDimArcLengthImpl::SetFit(PyAcDimFit val) const
{
    PyThrowBadHr(impObj()->put_Fit((AcDimFit)val));
}

PyAcDimFractionType PyIAcadDimArcLengthImpl::GetFractionFormat() const
{
    AcDimFractionType rtval = (AcDimFractionType)PyAcDimFractionType::pyacHorizontal;
    PyThrowBadHr(impObj()->get_FractionFormat(&rtval));
    return (PyAcDimFractionType)rtval;
}

void PyIAcadDimArcLengthImpl::SetFractionFormat(PyAcDimFractionType val) const
{
    PyThrowBadHr(impObj()->put_FractionFormat((AcDimFractionType)val));
}

PyAcDimHorizontalJustification PyIAcadDimArcLengthImpl::GetHorizontalTextPosition() const
{
    AcDimHorizontalJustification rtval = (AcDimHorizontalJustification)PyAcDimHorizontalJustification::pyacHorzCentered;
    PyThrowBadHr(impObj()->get_HorizontalTextPosition(&rtval));
    return (PyAcDimHorizontalJustification)rtval;
}

void PyIAcadDimArcLengthImpl::SetHorizontalTextPosition(PyAcDimHorizontalJustification val) const
{
    PyThrowBadHr(impObj()->put_HorizontalTextPosition((AcDimHorizontalJustification)val));
}

double PyIAcadDimArcLengthImpl::GetLinearScaleFactor() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_LinearScaleFactor(&rtval));
    return rtval;
}

void PyIAcadDimArcLengthImpl::SetLinearScaleFactor(double val) const
{
    PyThrowBadHr(impObj()->put_LinearScaleFactor(val));
}

PyAcDimLUnits PyIAcadDimArcLengthImpl::GetUnitsFormat() const
{
    AcDimLUnits rtval = (AcDimLUnits)PyAcDimLUnits::pyacDimLDecimal;
    PyThrowBadHr(impObj()->get_UnitsFormat(&rtval));
    return (PyAcDimLUnits)rtval;
}

void PyIAcadDimArcLengthImpl::SetUnitsFormat(PyAcDimLUnits val) const
{
    PyThrowBadHr(impObj()->put_UnitsFormat((AcDimLUnits)val));
}

PyAcLineWeight PyIAcadDimArcLengthImpl::GetExtensionLineWeight() const
{
    AcLineWeight rtval = (AcLineWeight)PyAcLineWeight::pyacLnWt000;
    PyThrowBadHr(impObj()->get_ExtensionLineWeight(&rtval));
    return (PyAcLineWeight)rtval;
}

void PyIAcadDimArcLengthImpl::SetExtensionLineWeight(PyAcLineWeight val) const
{
    PyThrowBadHr(impObj()->put_ExtensionLineWeight((AcLineWeight)val));
}

double PyIAcadDimArcLengthImpl::GetRoundDistance() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_RoundDistance(&rtval));
    return rtval;
}

void PyIAcadDimArcLengthImpl::SetRoundDistance(double val) const
{
    PyThrowBadHr(impObj()->put_RoundDistance(val));
}

bool PyIAcadDimArcLengthImpl::GetDimLine1Suppress() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_DimLine1Suppress(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimArcLengthImpl::SetDimLine1Suppress(bool val) const
{
    PyThrowBadHr(impObj()->put_DimLine1Suppress(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadDimArcLengthImpl::GetDimLine2Suppress() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_DimLine2Suppress(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimArcLengthImpl::SetDimLine2Suppress(bool val) const
{
    PyThrowBadHr(impObj()->put_DimLine2Suppress(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadDimArcLengthImpl::GetExtLine1Suppress() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_ExtLine1Suppress(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimArcLengthImpl::SetExtLine1Suppress(bool val) const
{
    PyThrowBadHr(impObj()->put_ExtLine1Suppress(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadDimArcLengthImpl::GetExtLine2Suppress() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_ExtLine2Suppress(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimArcLengthImpl::SetExtLine2Suppress(bool val) const
{
    PyThrowBadHr(impObj()->put_ExtLine2Suppress(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadDimArcLengthImpl::GetDimLineInside() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_DimLineInside(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimArcLengthImpl::SetDimLineInside(bool val) const
{
    PyThrowBadHr(impObj()->put_DimLineInside(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadDimArcLengthImpl::GetTextInsideAlign() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_TextInsideAlign(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimArcLengthImpl::SetTextInsideAlign(bool val) const
{
    PyThrowBadHr(impObj()->put_TextInsideAlign(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadDimArcLengthImpl::GetTextInside() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_TextInside(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimArcLengthImpl::SetTextInside(bool val) const
{
    PyThrowBadHr(impObj()->put_TextInside(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadDimArcLengthImpl::GetForceLineInside() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_ForceLineInside(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimArcLengthImpl::SetForceLineInside(bool val) const
{
    PyThrowBadHr(impObj()->put_ForceLineInside(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadDimArcLengthImpl::GetTextOutsideAlign() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_TextOutsideAlign(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimArcLengthImpl::SetTextOutsideAlign(bool val) const
{
    PyThrowBadHr(impObj()->put_TextOutsideAlign(val ? VARIANT_TRUE : VARIANT_FALSE));
}

double PyIAcadDimArcLengthImpl::GetExtensionLineOffset() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_ExtensionLineOffset(&rtval));
    return rtval;
}

void PyIAcadDimArcLengthImpl::SetExtensionLineOffset(double val) const
{
    PyThrowBadHr(impObj()->put_ExtensionLineOffset(val));
}

bool PyIAcadDimArcLengthImpl::GetAltSuppressLeadingZeros() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_AltSuppressLeadingZeros(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimArcLengthImpl::SetAltSuppressLeadingZeros(bool val) const
{
    PyThrowBadHr(impObj()->put_AltSuppressLeadingZeros(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadDimArcLengthImpl::GetAltSuppressTrailingZeros() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_AltSuppressTrailingZeros(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimArcLengthImpl::SetAltSuppressTrailingZeros(bool val) const
{
    PyThrowBadHr(impObj()->put_AltSuppressTrailingZeros(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadDimArcLengthImpl::GetAltSuppressZeroFeet() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_AltSuppressZeroFeet(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimArcLengthImpl::SetAltSuppressZeroFeet(bool val) const
{
    PyThrowBadHr(impObj()->put_AltSuppressZeroFeet(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadDimArcLengthImpl::GetAltSuppressZeroInches() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_AltSuppressZeroInches(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimArcLengthImpl::SetAltSuppressZeroInches(bool val) const
{
    PyThrowBadHr(impObj()->put_AltSuppressZeroInches(val));
}

bool PyIAcadDimArcLengthImpl::GetAltToleranceSuppressLeadingZeros() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_AltToleranceSuppressLeadingZeros(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimArcLengthImpl::SetAltToleranceSuppressLeadingZeros(bool val) const
{
    PyThrowBadHr(impObj()->put_AltToleranceSuppressLeadingZeros(val));
}

bool PyIAcadDimArcLengthImpl::GetAltToleranceSuppressTrailingZeros() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_AltToleranceSuppressTrailingZeros(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimArcLengthImpl::SetAltToleranceSuppressTrailingZeros(bool val) const
{
    PyThrowBadHr(impObj()->put_AltToleranceSuppressTrailingZeros(val));
}

bool PyIAcadDimArcLengthImpl::GetAltToleranceSuppressZeroFeet() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_AltToleranceSuppressZeroFeet(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimArcLengthImpl::SetAltToleranceSuppressZeroFeet(bool val) const
{
    PyThrowBadHr(impObj()->put_AltToleranceSuppressZeroFeet(val));
}

bool PyIAcadDimArcLengthImpl::GetAltToleranceSuppressZeroInches() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_AltToleranceSuppressZeroInches(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimArcLengthImpl::SetAltToleranceSuppressZeroInches(bool val) const
{
    PyThrowBadHr(impObj()->put_AltToleranceSuppressZeroInches(val));
}

bool PyIAcadDimArcLengthImpl::GetSuppressZeroFeet() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_SuppressZeroFeet(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimArcLengthImpl::SetSuppressZeroFeet(bool val) const
{
    PyThrowBadHr(impObj()->put_SuppressZeroFeet(val));
}

bool PyIAcadDimArcLengthImpl::GetSuppressZeroInches() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_SuppressZeroInches(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimArcLengthImpl::SetSuppressZeroInches(bool val) const
{
    PyThrowBadHr(impObj()->put_SuppressZeroInches(val));
}

bool PyIAcadDimArcLengthImpl::GetToleranceSuppressZeroFeet() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_ToleranceSuppressZeroFeet(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimArcLengthImpl::SetToleranceSuppressZeroFeet(bool val) const
{
    PyThrowBadHr(impObj()->put_ToleranceSuppressZeroFeet(val));
}

bool PyIAcadDimArcLengthImpl::GetToleranceSuppressZeroInches() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_ToleranceSuppressZeroInches(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimArcLengthImpl::SetToleranceSuppressZeroInches(bool val) const
{
    PyThrowBadHr(impObj()->put_ToleranceSuppressZeroInches(val));
}

PyAcLineWeight PyIAcadDimArcLengthImpl::GetDimensionLineWeight() const
{
    AcLineWeight rtval = (AcLineWeight)PyAcLineWeight::pyacLnWt000;
    PyThrowBadHr(impObj()->get_DimensionLineWeight(&rtval));
    return (PyAcLineWeight)rtval;
}

void PyIAcadDimArcLengthImpl::SetDimensionLineWeight(PyAcLineWeight val) const
{
    PyThrowBadHr(impObj()->put_DimensionLineWeight((AcLineWeight)val));
}

double PyIAcadDimArcLengthImpl::GetArrowheadSize() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_ArrowheadSize(&rtval));
    return rtval;
}

void PyIAcadDimArcLengthImpl::SetArrowheadSize(double val) const
{
    PyThrowBadHr(impObj()->put_ArrowheadSize(val));
}

PyAcDimArrowheadType PyIAcadDimArcLengthImpl::GetArrowhead1Type() const
{
    AcDimArrowheadType rtval = (AcDimArrowheadType)PyAcDimArrowheadType::pyacArrowDefault;
    PyThrowBadHr(impObj()->get_Arrowhead1Type(&rtval));
    return (PyAcDimArrowheadType)rtval;
}

void PyIAcadDimArcLengthImpl::SetArrowhead1Type(PyAcDimArrowheadType val) const
{
    PyThrowBadHr(impObj()->put_Arrowhead1Type((AcDimArrowheadType)val));
}

PyAcDimArrowheadType PyIAcadDimArcLengthImpl::GetArrowhead2Type() const
{
    AcDimArrowheadType rtval = (AcDimArrowheadType)PyAcDimArrowheadType::pyacArrowDefault;
    PyThrowBadHr(impObj()->get_Arrowhead2Type(&rtval));
    return (PyAcDimArrowheadType)rtval;
}

void PyIAcadDimArcLengthImpl::SetArrowhead2Type(PyAcDimArrowheadType val) const
{
    PyThrowBadHr(impObj()->put_Arrowhead2Type((AcDimArrowheadType)val));
}

double PyIAcadDimArcLengthImpl::GetMeasurement() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_Measurement(&rtval));
    return rtval;
}

CString PyIAcadDimArcLengthImpl::GetArrowhead1Block() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_Arrowhead1Block(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadDimArcLengthImpl::SetArrowhead1Block(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_Arrowhead1Block(bstrval));
}

CString PyIAcadDimArcLengthImpl::GetArrowhead2Block() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_Arrowhead2Block(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadDimArcLengthImpl::SetArrowhead2Block(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_Arrowhead2Block(bstrval));
}

CString PyIAcadDimArcLengthImpl::GetDimensionLinetype() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_DimensionLinetype(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadDimArcLengthImpl::SetDimensionLinetype(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_DimensionLinetype(bstrval));
}

CString PyIAcadDimArcLengthImpl::GetExtLine1Linetype() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_ExtLine1Linetype(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadDimArcLengthImpl::SetExtLine1Linetype(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_ExtLine1Linetype(bstrval));
}

CString PyIAcadDimArcLengthImpl::GetExtLine2Linetype() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_ExtLine2Linetype(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadDimArcLengthImpl::SetExtLine2Linetype(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_ExtLine2Linetype(bstrval));
}

bool PyIAcadDimArcLengthImpl::GetExtLineFixedLenSuppress() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_ExtLineFixedLenSuppress(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimArcLengthImpl::SetExtLineFixedLenSuppress(bool val) const
{
    PyThrowBadHr(impObj()->put_ExtLineFixedLenSuppress(val ? VARIANT_TRUE : VARIANT_FALSE));
}

double PyIAcadDimArcLengthImpl::GetExtLineFixedLen() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_ExtLineFixedLen(&rtval));
    return rtval;
}

void PyIAcadDimArcLengthImpl::SetExtLineFixedLen(double val) const
{
    PyThrowBadHr(impObj()->put_ExtLineFixedLen(val));
}

CString PyIAcadDimArcLengthImpl::GetSubUnitsSuffix() const
{
#ifdef _BRXTARGET260
    throw PyNotimplementedByHost{};
#else
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_SubUnitsSuffix(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
#endif;
}

void PyIAcadDimArcLengthImpl::SetSubUnitsSuffix(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_SubUnitsSuffix(bstrval));
}

double PyIAcadDimArcLengthImpl::GetSubUnitsFactor() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_SubUnitsFactor(&rtval));
    return rtval;
}

void PyIAcadDimArcLengthImpl::SetSubUnitsFactor(double val) const
{
    PyThrowBadHr(impObj()->put_SubUnitsFactor(val));
}

CString PyIAcadDimArcLengthImpl::GetAltSubUnitsSuffix() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_AltSubUnitsSuffix(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadDimArcLengthImpl::SetAltSubUnitsSuffix(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_AltSubUnitsSuffix(bstrval));
}

double PyIAcadDimArcLengthImpl::GetAltSubUnitsFactor() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_AltSubUnitsFactor(&rtval));
    return rtval;
}

void PyIAcadDimArcLengthImpl::SetAltSubUnitsFactor(double val) const
{
    PyThrowBadHr(impObj()->put_AltSubUnitsFactor(val));
}

AcGePoint3d PyIAcadDimArcLengthImpl::GetArcPoint() const
{
    _variant_t vtval;
    AcGePoint3d rtval;
    PyThrowBadHr(impObj()->get_ArcPoint(&vtval));
    PyThrowBadHr(VariantToAcGePoint3d(vtval, rtval));
    return rtval;
}

void PyIAcadDimArcLengthImpl::SetArcPoint(const AcGePoint3d& val) const
{
    _variant_t vtval;
    PyThrowBadHr(AcGePoint3dToVariant(vtval.GetVARIANT(), val));
    PyThrowBadHr(impObj()->put_ArcPoint(vtval));
}

AcGePoint3d PyIAcadDimArcLengthImpl::GetExtLine1Point() const
{
    _variant_t vtval;
    AcGePoint3d rtval;
    PyThrowBadHr(impObj()->get_ExtLine1Point(&vtval));
    PyThrowBadHr(VariantToAcGePoint3d(vtval, rtval));
    return rtval;
}

void PyIAcadDimArcLengthImpl::SetExtLine1Point(const AcGePoint3d& val) const
{
    _variant_t vtval;
    PyThrowBadHr(AcGePoint3dToVariant(vtval.GetVARIANT(), val));
    PyThrowBadHr(impObj()->put_ExtLine1Point(vtval));
}

AcGePoint3d PyIAcadDimArcLengthImpl::GetExtLine2Point() const
{
    _variant_t vtval;
    AcGePoint3d rtval;
    PyThrowBadHr(impObj()->get_ExtLine2Point(&vtval));
    PyThrowBadHr(VariantToAcGePoint3d(vtval, rtval));
    return rtval;
}

void PyIAcadDimArcLengthImpl::SetExtLine2Point(const AcGePoint3d& val) const
{
    _variant_t vtval;
    PyThrowBadHr(AcGePoint3dToVariant(vtval.GetVARIANT(), val));
    PyThrowBadHr(impObj()->put_ExtLine2Point(vtval));
}


AcGePoint3d PyIAcadDimArcLengthImpl::GetCenterPoint() const
{
    _variant_t vtval;
    AcGePoint3d rtval;
    PyThrowBadHr(impObj()->get_CenterPoint(&vtval));
    PyThrowBadHr(VariantToAcGePoint3d(vtval, rtval));
    return rtval;
}

void PyIAcadDimArcLengthImpl::SetCenterPoint(const AcGePoint3d& val) const
{
    _variant_t vtval;
    PyThrowBadHr(AcGePoint3dToVariant(vtval.GetVARIANT(), val));
    PyThrowBadHr(impObj()->put_CenterPoint(vtval));
}

AcGePoint3d PyIAcadDimArcLengthImpl::GetLeader1Point() const
{
    _variant_t vtval;
    AcGePoint3d rtval;
    PyThrowBadHr(impObj()->get_Leader1Point(&vtval));
    PyThrowBadHr(VariantToAcGePoint3d(vtval, rtval));
    return rtval;
}

void PyIAcadDimArcLengthImpl::SetLeader1Point(const AcGePoint3d& val) const
{
    _variant_t vtval;
    PyThrowBadHr(AcGePoint3dToVariant(vtval.GetVARIANT(), val));
    PyThrowBadHr(impObj()->put_Leader1Point(vtval));
}

AcGePoint3d PyIAcadDimArcLengthImpl::GetLeader2Point() const
{
    _variant_t vtval;
    AcGePoint3d rtval;
    PyThrowBadHr(impObj()->get_Leader2Point(&vtval));
    PyThrowBadHr(VariantToAcGePoint3d(vtval, rtval));
    return rtval;
}

void PyIAcadDimArcLengthImpl::SetLeader2Point(const AcGePoint3d& val) const
{
    _variant_t vtval;
    PyThrowBadHr(AcGePoint3dToVariant(vtval.GetVARIANT(), val));
    PyThrowBadHr(impObj()->put_Leader2Point(vtval));
}

bool PyIAcadDimArcLengthImpl::GetIsPartial() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_IsPartial(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimArcLengthImpl::SetIsPartial(bool val) const
{
    PyThrowBadHr(impObj()->put_IsPartial(val ? VARIANT_TRUE : VARIANT_FALSE));
}

double PyIAcadDimArcLengthImpl::GetArcStartParam() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_ArcStartParam(&rtval));
    return rtval;
}

void PyIAcadDimArcLengthImpl::SetArcStartParam(double val) const
{
    PyThrowBadHr(impObj()->put_ArcStartParam(val));
}

double PyIAcadDimArcLengthImpl::GetArcEndParam() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_ArcEndParam(&rtval));
    return rtval;
}

void PyIAcadDimArcLengthImpl::SetArcEndParam(double val) const
{
    PyThrowBadHr(impObj()->put_ArcEndParam(val));
}

bool PyIAcadDimArcLengthImpl::GetHasLeader() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_HasLeader(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimArcLengthImpl::SetHasLeader(bool val) const
{
    PyThrowBadHr(impObj()->put_HasLeader(val));
}

PyAcDimArcLengthSymbol PyIAcadDimArcLengthImpl::GetSymbolPosition() const
{
    AcDimArcLengthSymbol rtval = (AcDimArcLengthSymbol)PyAcDimArcLengthSymbol::pyacSymInFront;
    PyThrowBadHr(impObj()->get_SymbolPosition(&rtval));
    return (PyAcDimArcLengthSymbol)rtval;
}

void PyIAcadDimArcLengthImpl::SetSymbolPosition(const PyAcDimArcLengthSymbol& val) const
{
    PyThrowBadHr(impObj()->put_SymbolPosition((AcDimArcLengthSymbol)val));
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

bool PyIAcadDimRadialLargeImpl::GetAltUnits() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_AltUnits(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimRadialLargeImpl::SetAltUnits(bool val) const
{
    PyThrowBadHr(impObj()->put_AltUnits(val ? VARIANT_TRUE : VARIANT_FALSE));
}

PyAcDimPrecision PyIAcadDimRadialLargeImpl::GetAltUnitsPrecision() const
{
    AcDimPrecision rtval = (AcDimPrecision)PyAcDimPrecision::pyacDimPrecisionOne;
    PyThrowBadHr(impObj()->get_AltUnitsPrecision(&rtval));
    return (PyAcDimPrecision)rtval;
}

void PyIAcadDimRadialLargeImpl::SetAltUnitsPrecision(PyAcDimPrecision val) const
{
    PyThrowBadHr(impObj()->put_AltUnitsPrecision((AcDimPrecision)val));
}

double PyIAcadDimRadialLargeImpl::GetAltUnitsScale() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_AltUnitsScale(&rtval));
    return rtval;
}

void PyIAcadDimRadialLargeImpl::SetAltUnitsScale(double val) const
{
    PyThrowBadHr(impObj()->put_AltUnitsScale(val));
}

double PyIAcadDimRadialLargeImpl::GetAltRoundDistance() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_AltRoundDistance(&rtval));
    return rtval;
}

void PyIAcadDimRadialLargeImpl::SetAltRoundDistance(double val) const
{
    PyThrowBadHr(impObj()->put_AltRoundDistance(val));
}

PyAcDimPrecision PyIAcadDimRadialLargeImpl::GetAltTolerancePrecision() const
{
    AcDimPrecision rtval = (AcDimPrecision)PyAcDimPrecision::pyacDimPrecisionOne;
    PyThrowBadHr(impObj()->get_AltTolerancePrecision(&rtval));
    return (PyAcDimPrecision)rtval;
}

void PyIAcadDimRadialLargeImpl::SetAltTolerancePrecision(PyAcDimPrecision val) const
{
    PyThrowBadHr(impObj()->put_AltTolerancePrecision((AcDimPrecision)val));
}

PyAcDimUnits PyIAcadDimRadialLargeImpl::GetAltUnitsFormat() const
{
    AcDimUnits rtval = (AcDimUnits)PyAcDimUnits::pyacDimDecimal;
    PyThrowBadHr(impObj()->get_AltUnitsFormat(&rtval));
    return (PyAcDimUnits)rtval;
}

void PyIAcadDimRadialLargeImpl::SetAltUnitsFormat(PyAcDimUnits val) const
{
    PyThrowBadHr(impObj()->put_AltUnitsFormat((AcDimUnits)val));
}

CString PyIAcadDimRadialLargeImpl::GetAltTextPrefix() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_AltTextPrefix(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadDimRadialLargeImpl::SetAltTextPrefix(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_AltTextPrefix(bstrval));
}

CString PyIAcadDimRadialLargeImpl::GetAltTextSuffix() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_AltTextSuffix((&bstrVal.GetBSTR())));
    return (LPCTSTR)bstrVal;
}

void PyIAcadDimRadialLargeImpl::SetAltTextSuffix(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_AltTextSuffix(bstrval));
}

PyAcDimCenterType PyIAcadDimRadialLargeImpl::GetCenterType() const
{
    AcDimCenterType rtval = (AcDimCenterType)PyAcDimCenterType::pyacCenterMark;
    PyThrowBadHr(impObj()->get_CenterType(&rtval));
    return (PyAcDimCenterType)rtval;
}

void PyIAcadDimRadialLargeImpl::SetCenterType(PyAcDimCenterType val) const
{
    PyThrowBadHr(impObj()->put_CenterType((AcDimCenterType)val));
}

double PyIAcadDimRadialLargeImpl::GetCenterMarkSize() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_CenterMarkSize(&rtval));
    return rtval;
}

void PyIAcadDimRadialLargeImpl::SetCenterMarkSize(double val) const
{
    PyThrowBadHr(impObj()->put_CenterMarkSize(val));
}

PyAcColor PyIAcadDimRadialLargeImpl::GetDimensionLineColor() const
{
    AcColor rtval = (AcColor)PyAcColor::pyacByLayer;
    PyThrowBadHr(impObj()->get_DimensionLineColor(&rtval));
    return (PyAcColor)rtval;
}

void PyIAcadDimRadialLargeImpl::SetDimensionLineColor(PyAcColor val) const
{
    PyThrowBadHr(impObj()->put_DimensionLineColor((AcColor)val));
}

PyAcDimPrecision PyIAcadDimRadialLargeImpl::GetPrimaryUnitsPrecision() const
{
    AcDimPrecision rtval = (AcDimPrecision)PyAcDimPrecision::pyacDimPrecisionOne;
    PyThrowBadHr(impObj()->get_PrimaryUnitsPrecision(&rtval));
    return (PyAcDimPrecision)rtval;
}

void PyIAcadDimRadialLargeImpl::SetPrimaryUnitsPrecision(PyAcDimPrecision val) const
{
    PyThrowBadHr(impObj()->put_PrimaryUnitsPrecision((AcDimPrecision)val));
}

PyAcDimFractionType PyIAcadDimRadialLargeImpl::GetFractionFormat() const
{
    AcDimFractionType rtval = (AcDimFractionType)PyAcDimFractionType::pyacHorizontal;
    PyThrowBadHr(impObj()->get_FractionFormat(&rtval));
    return (PyAcDimFractionType)rtval;
}

void PyIAcadDimRadialLargeImpl::SetFractionFormat(PyAcDimFractionType val) const
{
    PyThrowBadHr(impObj()->put_FractionFormat((AcDimFractionType)val));
}

PyAcDimFit PyIAcadDimRadialLargeImpl::GetFit() const
{
    AcDimFit rtval = (AcDimFit)PyAcDimFit::pyacTextAndArrows;
    PyThrowBadHr(impObj()->get_Fit(&rtval));
    return (PyAcDimFit)rtval;
}

void PyIAcadDimRadialLargeImpl::SetFit(PyAcDimFit val) const
{
    PyThrowBadHr(impObj()->put_Fit((AcDimFit)val));
}

double PyIAcadDimRadialLargeImpl::GetLinearScaleFactor() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_LinearScaleFactor(&rtval));
    return rtval;
}

void PyIAcadDimRadialLargeImpl::SetLinearScaleFactor(double val) const
{
    PyThrowBadHr(impObj()->put_LinearScaleFactor(val));
}
PyAcDimLUnits PyIAcadDimRadialLargeImpl::GetUnitsFormat() const
{
    AcDimLUnits rtval = (AcDimLUnits)PyAcDimLUnits::pyacDimLDecimal;
    PyThrowBadHr(impObj()->get_UnitsFormat(&rtval));
    return (PyAcDimLUnits)rtval;
}

void PyIAcadDimRadialLargeImpl::SetUnitsFormat(PyAcDimLUnits val) const
{
    PyThrowBadHr(impObj()->put_UnitsFormat((AcDimLUnits)val));
}

double PyIAcadDimRadialLargeImpl::GetRoundDistance() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_RoundDistance(&rtval));
    return rtval;
}

void PyIAcadDimRadialLargeImpl::SetRoundDistance(double val) const
{
    PyThrowBadHr(impObj()->put_RoundDistance(val));
}

bool PyIAcadDimRadialLargeImpl::GetDimLineSuppress() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_DimLineSuppress(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimRadialLargeImpl::SetDimLineSuppress(bool val) const
{
    PyThrowBadHr(impObj()->put_DimLineSuppress(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadDimRadialLargeImpl::GetTextInsideAlign() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_TextInsideAlign(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimRadialLargeImpl::SetTextInsideAlign(bool val) const
{
    PyThrowBadHr(impObj()->put_TextInsideAlign(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadDimRadialLargeImpl::GetTextInside() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_TextInside(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimRadialLargeImpl::SetTextInside(bool val) const
{
    PyThrowBadHr(impObj()->put_TextInside(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadDimRadialLargeImpl::GetForceLineInside() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_ForceLineInside(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimRadialLargeImpl::SetForceLineInside(bool val) const
{
    PyThrowBadHr(impObj()->put_ForceLineInside(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadDimRadialLargeImpl::GetTextOutsideAlign() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_TextOutsideAlign(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimRadialLargeImpl::SetTextOutsideAlign(bool val) const
{
    PyThrowBadHr(impObj()->put_TextOutsideAlign(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadDimRadialLargeImpl::GetAltSuppressLeadingZeros() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_AltSuppressLeadingZeros(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimRadialLargeImpl::SetAltSuppressLeadingZeros(bool val) const
{
    PyThrowBadHr(impObj()->put_AltSuppressLeadingZeros(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadDimRadialLargeImpl::GetAltSuppressTrailingZeros() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_AltSuppressTrailingZeros(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimRadialLargeImpl::SetAltSuppressTrailingZeros(bool val) const
{
    PyThrowBadHr(impObj()->put_AltSuppressTrailingZeros(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadDimRadialLargeImpl::GetAltSuppressZeroFeet() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_AltSuppressZeroFeet(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimRadialLargeImpl::SetAltSuppressZeroFeet(bool val) const
{
    PyThrowBadHr(impObj()->put_AltSuppressZeroFeet(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadDimRadialLargeImpl::GetAltSuppressZeroInches() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_AltSuppressZeroInches(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimRadialLargeImpl::SetAltSuppressZeroInches(bool val) const
{
    PyThrowBadHr(impObj()->put_AltSuppressZeroInches(val));
}

bool PyIAcadDimRadialLargeImpl::GetAltToleranceSuppressLeadingZeros() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_AltToleranceSuppressLeadingZeros(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimRadialLargeImpl::SetAltToleranceSuppressLeadingZeros(bool val) const
{
    PyThrowBadHr(impObj()->put_AltToleranceSuppressLeadingZeros(val));
}

bool PyIAcadDimRadialLargeImpl::GetAltToleranceSuppressTrailingZeros() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_AltToleranceSuppressTrailingZeros(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimRadialLargeImpl::SetAltToleranceSuppressTrailingZeros(bool val) const
{
    PyThrowBadHr(impObj()->put_AltToleranceSuppressTrailingZeros(val));
}

bool PyIAcadDimRadialLargeImpl::GetAltToleranceSuppressZeroFeet() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_AltToleranceSuppressZeroFeet(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimRadialLargeImpl::SetAltToleranceSuppressZeroFeet(bool val) const
{
    PyThrowBadHr(impObj()->put_AltToleranceSuppressZeroFeet(val));
}

bool PyIAcadDimRadialLargeImpl::GetAltToleranceSuppressZeroInches() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_AltToleranceSuppressZeroInches(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimRadialLargeImpl::SetAltToleranceSuppressZeroInches(bool val) const
{
    PyThrowBadHr(impObj()->put_AltToleranceSuppressZeroInches(val));
}

bool PyIAcadDimRadialLargeImpl::GetSuppressZeroFeet() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_SuppressZeroFeet(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimRadialLargeImpl::SetSuppressZeroFeet(bool val) const
{
    PyThrowBadHr(impObj()->put_SuppressZeroFeet(val));
}

bool PyIAcadDimRadialLargeImpl::GetSuppressZeroInches() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_SuppressZeroInches(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimRadialLargeImpl::SetSuppressZeroInches(bool val) const
{
    PyThrowBadHr(impObj()->put_SuppressZeroInches(val));
}

bool PyIAcadDimRadialLargeImpl::GetToleranceSuppressZeroFeet() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_ToleranceSuppressZeroFeet(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimRadialLargeImpl::SetToleranceSuppressZeroFeet(bool val) const
{
    PyThrowBadHr(impObj()->put_ToleranceSuppressZeroFeet(val));
}

bool PyIAcadDimRadialLargeImpl::GetToleranceSuppressZeroInches() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_ToleranceSuppressZeroInches(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimRadialLargeImpl::SetToleranceSuppressZeroInches(bool val) const
{
    PyThrowBadHr(impObj()->put_ToleranceSuppressZeroInches(val));
}

PyAcLineWeight PyIAcadDimRadialLargeImpl::GetDimensionLineWeight() const
{
    AcLineWeight rtval = (AcLineWeight)PyAcLineWeight::pyacLnWt000;
    PyThrowBadHr(impObj()->get_DimensionLineWeight(&rtval));
    return (PyAcLineWeight)rtval;
}

void PyIAcadDimRadialLargeImpl::SetDimensionLineWeight(PyAcLineWeight val) const
{
    PyThrowBadHr(impObj()->put_DimensionLineWeight((AcLineWeight)val));
}

double PyIAcadDimRadialLargeImpl::GetArrowheadSize() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_ArrowheadSize(&rtval));
    return rtval;
}

void PyIAcadDimRadialLargeImpl::SetArrowheadSize(double val) const
{
    PyThrowBadHr(impObj()->put_ArrowheadSize(val));
}

PyAcDimArrowheadType PyIAcadDimRadialLargeImpl::GetArrowheadType() const
{
    AcDimArrowheadType rtval = (AcDimArrowheadType)PyAcDimArrowheadType::pyacArrowDefault;
    PyThrowBadHr(impObj()->get_ArrowheadType(&rtval));
    return (PyAcDimArrowheadType)rtval;
}

void PyIAcadDimRadialLargeImpl::SetArrowheadType(PyAcDimArrowheadType val) const
{
    PyThrowBadHr(impObj()->put_ArrowheadType((AcDimArrowheadType)val));
}

double PyIAcadDimRadialLargeImpl::GetMeasurement() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_Measurement(&rtval));
    return rtval;
}

CString PyIAcadDimRadialLargeImpl::GetArrowheadBlock() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_ArrowheadBlock(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadDimRadialLargeImpl::SetArrowheadBlock(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_ArrowheadBlock(bstrval));
}

AcGePoint3d PyIAcadDimRadialLargeImpl::GetOverrideCenter() const
{
    _variant_t vtval;
    AcGePoint3d rtval;
    PyThrowBadHr(impObj()->get_OverrideCenter(&vtval));
    PyThrowBadHr(VariantToAcGePoint3d(vtval, rtval));
    return rtval;
}

void PyIAcadDimRadialLargeImpl::SetOverrideCenter(const AcGePoint3d& val) const
{
    _variant_t vtval;
    PyThrowBadHr(AcGePoint3dToVariant(vtval.GetVARIANT(), val));
    PyThrowBadHr(impObj()->put_OverrideCenter(vtval));
}

AcGePoint3d PyIAcadDimRadialLargeImpl::GetJogLocation() const
{
    _variant_t vtval;
    AcGePoint3d rtval;
    PyThrowBadHr(impObj()->get_JogLocation(&vtval));
    PyThrowBadHr(VariantToAcGePoint3d(vtval, rtval));
    return rtval;
}

void PyIAcadDimRadialLargeImpl::SetJogLocation(const AcGePoint3d& val) const
{
    _variant_t vtval;
    PyThrowBadHr(AcGePoint3dToVariant(vtval.GetVARIANT(), val));
    PyThrowBadHr(impObj()->put_JogLocation(vtval));
}

double PyIAcadDimRadialLargeImpl::GetJogAngle() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_JogAngle(&rtval));
    return rtval;
}

void PyIAcadDimRadialLargeImpl::SetJogAngle(double val) const
{
    PyThrowBadHr(impObj()->put_JogAngle(val));
}

AcGePoint3d PyIAcadDimRadialLargeImpl::GetCenter() const
{
    _variant_t vtval;
    AcGePoint3d rtval;
    PyThrowBadHr(impObj()->get_Center(&vtval));
    PyThrowBadHr(VariantToAcGePoint3d(vtval, rtval));
    return rtval;
}

void PyIAcadDimRadialLargeImpl::SetCenter(const AcGePoint3d& val) const
{
    _variant_t vtval;
    PyThrowBadHr(AcGePoint3dToVariant(vtval.GetVARIANT(), val));
    PyThrowBadHr(impObj()->put_Center(vtval));
}

AcGePoint3d PyIAcadDimRadialLargeImpl::GetChordPoint() const
{
    _variant_t vtval;
    AcGePoint3d rtval;
    PyThrowBadHr(impObj()->get_ChordPoint(&vtval));
    PyThrowBadHr(VariantToAcGePoint3d(vtval, rtval));
    return rtval;
}

void PyIAcadDimRadialLargeImpl::SetChordPoint(const AcGePoint3d& val) const
{
    _variant_t vtval;
    PyThrowBadHr(AcGePoint3dToVariant(vtval.GetVARIANT(), val));
    PyThrowBadHr(impObj()->put_ChordPoint(vtval));
}

CString PyIAcadDimRadialLargeImpl::GetDimensionLinetype() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_DimensionLinetype(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadDimRadialLargeImpl::SetDimensionLinetype(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_DimensionLinetype(bstrval));
}

IAcadDimRadialLarge* PyIAcadDimRadialLargeImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadDimRadialLarge*>(m_pimpl.GetInterfacePtr());
}
