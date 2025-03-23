#include "stdafx.h"
#include "PyAcadTableImpl.h"

//------------------------------------------------------------------------------------
//PyIAcadTableImpl
PyIAcadTableImpl::PyIAcadTableImpl(IAcadTable* ptr)
    : PyIAcadEntityImpl(ptr)
{
}

CString PyIAcadTableImpl::GetStyleName() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_StyleName(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadTableImpl::SetStyleName(const CString val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_StyleName(bstrval));
}

int PyIAcadTableImpl::GetRows() const
{
    int rtval = 0;
    PyThrowBadHr(impObj()->get_Rows(&rtval));
    return rtval;
}

void PyIAcadTableImpl::SetRows(int val) const
{
    PyThrowBadHr(impObj()->put_Rows(val));
}

int PyIAcadTableImpl::GetColumns() const
{
    int rtval = 0;
    PyThrowBadHr(impObj()->get_Columns(&rtval));
    return rtval;
}

void PyIAcadTableImpl::SetColumns(int val) const
{
    PyThrowBadHr(impObj()->put_Columns(val));
}

PyAcTableDirection PyIAcadTableImpl::GetFlowDirection() const
{
    AcTableDirection rtVal = (AcTableDirection)PyAcTableDirection::pyacTableTopToBottom;
    PyThrowBadHr(impObj()->get_FlowDirection(&rtVal));
    return (PyAcTableDirection)rtVal;
}

void PyIAcadTableImpl::SetFlowDirection(int val) const
{
    PyThrowBadHr(impObj()->put_FlowDirection((AcTableDirection)val));
}

double PyIAcadTableImpl::GetWidth() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_Width(&rtval));
    return rtval;
}

void PyIAcadTableImpl::SetWidth(double val) const
{
    PyThrowBadHr(impObj()->put_Width(val));
}

double PyIAcadTableImpl::GetHeight() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_Height(&rtval));
    return rtval;
}

void PyIAcadTableImpl::SetHeight(double val) const
{
    PyThrowBadHr(impObj()->put_Height(val));
}

double PyIAcadTableImpl::GetVertCellMargin() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_VertCellMargin(&rtval));
    return rtval;
}

void PyIAcadTableImpl::SetVertCellMargin(double val) const
{
    PyThrowBadHr(impObj()->put_VertCellMargin(val));
}

double PyIAcadTableImpl::GetHorzCellMargin() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_HorzCellMargin(&rtval));
    return rtval;
}

void PyIAcadTableImpl::SetHorzCellMargin(double val) const
{
    PyThrowBadHr(impObj()->put_HorzCellMargin(val));
}

AcGePoint3d PyIAcadTableImpl::GetInsertionPoint() const
{
    _variant_t vtval;
    AcGePoint3d rtVal;
    PyThrowBadHr(impObj()->get_InsertionPoint(&vtval));
    PyThrowBadHr(VariantToAcGePoint3d(vtval, rtVal));
    return rtVal;
}

void PyIAcadTableImpl::SetInsertionPoint(const AcGePoint3d val) const
{
    _variant_t vtval;
    PyThrowBadHr(AcGePoint3dToVariant(vtval.GetVARIANT(), val));
    PyThrowBadHr(impObj()->put_InsertionPoint(vtval));
}

double PyIAcadTableImpl::GetColumnWidth(int col) const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->GetColumnWidth(col, &rtval));
    return rtval;
}

void PyIAcadTableImpl::SetColumnWidth(int col, double val) const
{
    PyThrowBadHr(impObj()->SetColumnWidth(col, val));
}

void PyIAcadTableImpl::SetColumnWidth(double val) const
{
    PyThrowBadHr(impObj()->put_ColumnWidth(val));
}

double PyIAcadTableImpl::GetRowHeight(int row) const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->GetRowHeight(row, &rtval));
    return rtval;
}

void PyIAcadTableImpl::SetRowHeight(double val) const
{
    PyThrowBadHr(impObj()->put_RowHeight(val));
}

void PyIAcadTableImpl::SetRowHeight(int row, double val) const
{
    PyThrowBadHr(impObj()->SetRowHeight(row, val));
}

double PyIAcadTableImpl::GetMinimumColumnWidth(int col) const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->GetMinimumColumnWidth(col, &rtval));
    return rtval;
}

double PyIAcadTableImpl::GetMinimumRowHeight(int row) const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->GetMinimumRowHeight(row, &rtval));
    return rtval;
}

double PyIAcadTableImpl::GetMinimumTableWidth() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_MinimumTableWidth(&rtval));
    return rtval;
}

double PyIAcadTableImpl::GetMinimumTableHeight() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_MinimumTableHeight(&rtval));
    return rtval;
}

AcGeVector3d PyIAcadTableImpl::GetDirection() const
{
    AcGeVector3d val;
    _variant_t coord;
    PyThrowBadHr(impObj()->get_Direction(&coord.GetVARIANT()));
    PyThrowBadHr(VariantToAcGeVector3d(coord, val));
    return val;
}

void PyIAcadTableImpl::SetDirection(const AcGeVector3d val) const
{
    _variant_t vtval;
    PyThrowBadHr(AcGeVector3dToVariant(vtval.GetVARIANT(), val));
    PyThrowBadHr(impObj()->put_Direction(vtval));
}

bool PyIAcadTableImpl::GetTitleSuppressed() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_TitleSuppressed(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadTableImpl::SetTitleSuppressed(bool val) const
{
    PyThrowBadHr(impObj()->put_TitleSuppressed(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadTableImpl::GetHeaderSuppressed() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_HeaderSuppressed(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadTableImpl::SetHeaderSuppressed(bool val) const
{
    PyThrowBadHr(impObj()->put_HeaderSuppressed(val ? VARIANT_TRUE : VARIANT_FALSE));
}

PyAcCellAlignment PyIAcadTableImpl::GetAlignment(PyAcRowType val) const
{
    AcCellAlignment rtVal = (AcCellAlignment)PyAcCellAlignment::pyacTopLeft;
    PyThrowBadHr(impObj()->GetAlignment((AcRowType)val, &rtVal));
    return (PyAcCellAlignment)rtVal;
}

void PyIAcadTableImpl::SetAlignment(int rowTypes, PyAcCellAlignment cellAlignment) const
{
    PyThrowBadHr(impObj()->SetAlignment(rowTypes, (AcCellAlignment)cellAlignment));
}

bool PyIAcadTableImpl::GetBackgroundColorNone(PyAcRowType val) const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->GetBackgroundColorNone((AcRowType)val, &rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadTableImpl::SetBackgroundColorNone(int rowTypes, bool bValue) const
{
#ifdef _BRXTARGET250
    PyThrowBadHr(impObj()->SetBackgroundColorNone(rowTypes, bValue ? VARIANT_TRUE : VARIANT_FALSE));
#else
    VARIANT_BOOL rtVal = bValue ? VARIANT_TRUE : VARIANT_FALSE;
    PyThrowBadHr(impObj()->SetBackgroundColorNone(rowTypes, &rtVal));
#endif
}

PyIAcadAcCmColorPtr PyIAcadTableImpl::GetBackgroundColor(PyAcRowType val) const
{
    IAcadAcCmColor* pColor = nullptr;
    PyThrowBadHr(impObj()->GetBackgroundColor((AcRowType)val, &pColor));
    return std::make_unique<PyIAcadAcCmColorImpl>(pColor);
}

void PyIAcadTableImpl::SetBackgroundColor(int rowTypes, const PyIAcadAcCmColorImpl& val) const
{
    PyThrowBadHr(impObj()->SetBackgroundColor(rowTypes, val.impObj()));
}

PyIAcadAcCmColorPtr PyIAcadTableImpl::GetContentColor(PyAcRowType val) const
{
    IAcadAcCmColor* pColor = nullptr;
    PyThrowBadHr(impObj()->GetContentColor((AcRowType)val, &pColor));
    return std::make_unique<PyIAcadAcCmColorImpl>(pColor);
}

void PyIAcadTableImpl::SetContentColor(int rowTypes, const PyIAcadAcCmColorImpl& val) const
{
    PyThrowBadHr(impObj()->SetContentColor(rowTypes, val.impObj()));
}

IAcadTable* PyIAcadTableImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadTable*>(m_pimpl.GetInterfacePtr());
}