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

double PyIAcadDimensionImpl::GeRotation() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_Rotation(&rtval));
    return rtval;
}

void PyIAcadDimensionImpl::SeRotation(double val) const
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
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_DimTxtDirection(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadDimensionImpl::SetDimTxtDirection(bool val) const
{
    PyThrowBadHr(impObj()->put_DimTxtDirection(val ? VARIANT_TRUE : VARIANT_FALSE));
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
