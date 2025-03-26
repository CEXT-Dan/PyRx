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

Int32s PyIAcadTableImpl::GetTableStyleOverrides() const
{
    Int32s rtval;
    _variant_t vtval;
    PyThrowBadHr(impObj()->get_TableStyleOverrides(&vtval.GetVARIANT()));
    PyThrowBadHr(VariantToInt32Array(vtval, rtval));
    return rtval;
}

void PyIAcadTableImpl::ClearTableStyleOverrides(int flag) const
{
    PyThrowBadHr(impObj()->ClearTableStyleOverrides(flag));
}

PyAcCellType PyIAcadTableImpl::GetCellType(int row, int col) const
{
    AcCellType rtVal = (AcCellType)PyAcCellType::pyacTextCell;
    PyThrowBadHr(impObj()->GetCellType(row, col, &rtVal));
    return (PyAcCellType)rtVal;
}

void PyIAcadTableImpl::SetCellType(int row, int col, PyAcCellType val) const
{
    PyThrowBadHr(impObj()->SetCellType(row, col, (AcCellType)val));
}

Point3dCoordinates PyIAcadTableImpl::GetCellExtents(int row, int col, bool bOuterCell) const
{
    _variant_t vtval;
    Point3dCoordinates coords;
    PyThrowBadHr(impObj()->GetCellExtents(row, col, bOuterCell ? VARIANT_TRUE : VARIANT_FALSE, &vtval.GetVARIANT()));
    PyThrowBadHr(VariantToAcGePoint3ds(vtval, coords));
    return coords;
}

AcGePoint3d PyIAcadTableImpl::GetAttachmentPoint(int row, int col) const
{
    _variant_t vtval;
    AcGePoint3d rtVal;
    PyThrowBadHr(impObj()->GetAttachmentPoint(row, col, &vtval));
    PyThrowBadHr(VariantToAcGePoint3d(vtval, rtVal));
    return rtVal;
}

PyAcCellAlignment PyIAcadTableImpl::GetCellAlignment(int row, int col) const
{
    AcCellAlignment rtVal = (AcCellAlignment)PyAcCellAlignment::pyacTopLeft;
    PyThrowBadHr(impObj()->GetCellAlignment(row, col, &rtVal));
    return (PyAcCellAlignment)rtVal;
}

void PyIAcadTableImpl::SetCellAlignment(int row, int col, PyAcCellAlignment val) const
{
    PyThrowBadHr(impObj()->SetCellAlignment(row, col, (AcCellAlignment)val));
}

bool PyIAcadTableImpl::GetCellBackgroundColorNone(int row, int col) const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->GetCellBackgroundColorNone(row, col, &rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadTableImpl::SetCellBackgroundColorNone(int row, int col, bool val) const
{
#ifdef _BRXTARGET250
    PyThrowBadHr(impObj()->SetCellBackgroundColorNone(row, col, val ? VARIANT_TRUE : VARIANT_FALSE));
#else
    VARIANT_BOOL vtval = val ? VARIANT_TRUE : VARIANT_FALSE;
    PyThrowBadHr(impObj()->SetCellBackgroundColorNone(row, col, &vtval));
#endif
}

PyIAcadAcCmColorPtr PyIAcadTableImpl::GetCellBackgroundColor(int row, int col) const
{
    IAcadAcCmColor* pColor = nullptr;
    PyThrowBadHr(impObj()->GetCellBackgroundColor(row, col, &pColor));
    return std::make_unique<PyIAcadAcCmColorImpl>(pColor);
}

void PyIAcadTableImpl::SetCellBackgroundColor(int row, int col, const PyIAcadAcCmColorImpl& val) const
{
    PyThrowBadHr(impObj()->SetCellBackgroundColor(row, col, val.impObj()));
}

PyIAcadAcCmColorPtr PyIAcadTableImpl::GetCellContentColor(int row, int col) const
{
    IAcadAcCmColor* pColor = nullptr;
    PyThrowBadHr(impObj()->GetCellContentColor(row, col, &pColor));
    return std::make_unique<PyIAcadAcCmColorImpl>(pColor);
}

void PyIAcadTableImpl::SetCellContentColor(int row, int col, const PyIAcadAcCmColorImpl& val) const
{
    PyThrowBadHr(impObj()->SetCellContentColor(row, col, val.impObj()));
}

Int32s PyIAcadTableImpl::GetCellStyleOverrides(int row, int col) const
{
    Int32s rtval;
    _variant_t vtval;
    PyThrowBadHr(impObj()->GetCellStyleOverrides(row, col, &vtval.GetVARIANT()));
    PyThrowBadHr(VariantToInt32Array(vtval, rtval));
    return rtval;
}

void PyIAcadTableImpl::DeleteCellContent(int row, int col) const
{
    PyThrowBadHr(impObj()->DeleteCellContent(row, col));
}

PyAcRowType PyIAcadTableImpl::GetRowType(int row) const
{
    AcRowType rtVal = (AcRowType)PyAcRowType::pyacUnknownRow;
    PyThrowBadHr(impObj()->GetRowType(row, &rtVal));
    return (PyAcRowType)rtVal;
}

CString PyIAcadTableImpl::GetText(int row, int col) const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->GetText(row, col, &bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadTableImpl::SetText(int row, int col, const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->SetText(row, col, bstrval));
}

CString PyIAcadTableImpl::GetCellTextStyle(int row, int col) const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->GetCellTextStyle(row, col, &bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadTableImpl::SetCellTextStyle(int row, int col, const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->SetCellTextStyle(row, col, bstrval));
}

double PyIAcadTableImpl::GetCellTextHeight(int row, int col) const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->GetCellTextHeight(row, col, &rtval));
    return rtval;
}

void PyIAcadTableImpl::SetCellTextHeight(int row, int col, double val) const
{
    PyThrowBadHr(impObj()->SetCellTextHeight(row, col, val));
}

PyAcRotationAngle PyIAcadTableImpl::GetTextRotation(int row, int col) const
{
    AcRotationAngle rtVal = (AcRotationAngle)PyAcRotationAngle::pyacDegreesUnknown;
    PyThrowBadHr(impObj()->GetTextRotation(row, col, &rtVal));
    return (PyAcRotationAngle)rtVal;
}

void PyIAcadTableImpl::SetTextRotation(int row, int col, PyAcRotationAngle val) const
{
    PyThrowBadHr(impObj()->SetTextRotation(row, col, (AcRotationAngle)val));
}

bool PyIAcadTableImpl::GetAutoScale(int row, int col) const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->GetAutoScale(row, col, &rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadTableImpl::SetAutoScale(int row, int col, bool val) const
{
#ifdef _BRXTARGET250
    PyThrowBadHr(impObj()->SetAutoScale(row, col, val ? VARIANT_TRUE : VARIANT_FALSE));
#else
    VARIANT_BOOL vtval = val ? VARIANT_TRUE : VARIANT_FALSE;
    PyThrowBadHr(impObj()->SetAutoScale(row, col, &vtval));
#endif
}

AcDbObjectId PyIAcadTableImpl::GetBlockTableRecordId(int row, int col) const
{
    LONG_PTR rtval = 0;
    AcDbObjectId id;
    PyThrowBadHr(impObj()->GetBlockTableRecordId(row, col, &rtval));
    return id.setFromOldId(rtval);
}

void PyIAcadTableImpl::SetBlockTableRecordId(int row, int col, const AcDbObjectId& val, bool autoScale) const
{
    PyThrowBadHr(impObj()->SetBlockTableRecordId(row, col, val.asOldId(), autoScale ? VARIANT_TRUE : VARIANT_FALSE));
}

double PyIAcadTableImpl::GetBlockScale(int row, int col) const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->GetBlockScale(row, col, &rtval));
    return rtval;
}

void PyIAcadTableImpl::SetBlockScale(int row, int col, double val) const
{
    PyThrowBadHr(impObj()->SetBlockScale(row, col, val));
}

double PyIAcadTableImpl::GetBlockRotation(int row, int col) const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->GetBlockRotation(row, col, &rtval));
    return rtval;
}

void PyIAcadTableImpl::SetBlockRotation(int row, int col, double val) const
{
    PyThrowBadHr(impObj()->SetBlockRotation(row, col, val));
}

CString PyIAcadTableImpl::GetBlockAttributeValue(int row, int col, const AcDbObjectId& val) const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->GetBlockAttributeValue(row, col, val.asOldId(), &bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadTableImpl::SetBlockAttributeValue(int row, int col, const AcDbObjectId& id, const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->SetBlockAttributeValue(row, col, id.asOldId(), bstrval));
}

PyAcLineWeight PyIAcadTableImpl::GetCellGridLineWeight(int row, int col, PyAcCellEdgeMask mask) const
{
    AcLineWeight rtVal = (AcLineWeight)PyAcLineWeight::pyacLnWt000;
    PyThrowBadHr(impObj()->GetCellGridLineWeight(row, col, (AcCellEdgeMask)mask, &rtVal));
    return (PyAcLineWeight)rtVal;
}

void PyIAcadTableImpl::SetCellGridLineWeight(int row, int col, PyAcCellEdgeMask mask, PyAcLineWeight lw) const
{
    PyThrowBadHr(impObj()->SetCellGridLineWeight(row, col, (AcCellEdgeMask)mask, (AcLineWeight)lw));
}

PyIAcadAcCmColorPtr PyIAcadTableImpl::GetCellGridColor(int row, int col, PyAcCellEdgeMask mask) const
{
    IAcadAcCmColor* pColor = nullptr;
    PyThrowBadHr(impObj()->GetCellGridColor(row, col, (AcCellEdgeMask)mask, &pColor));
    return std::make_unique<PyIAcadAcCmColorImpl>(pColor);
}

void PyIAcadTableImpl::SetCellGridColor(int row, int col, PyAcCellEdgeMask mask, const PyIAcadAcCmColorImpl& val) const
{
    PyThrowBadHr(impObj()->SetCellGridColor(row, col, (AcCellEdgeMask)mask, val.impObj()));
}

bool PyIAcadTableImpl::GetCellGridVisibility(int row, int col, PyAcCellEdgeMask mask) const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->GetCellGridVisibility(row, col, (AcCellEdgeMask)mask, &rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadTableImpl::SetCellGridVisibility(int row, int col, PyAcCellEdgeMask mask, bool val) const
{
    PyThrowBadHr(impObj()->SetCellGridVisibility(row, col, (AcCellEdgeMask)mask, val ? VARIANT_TRUE : VARIANT_FALSE));
}

void PyIAcadTableImpl::InsertColumns(int col, double width, int cols) const
{
    PyThrowBadHr(impObj()->InsertColumns(col, width, cols));
}

void PyIAcadTableImpl::DeleteColumns(int col, int cols) const
{
    PyThrowBadHr(impObj()->DeleteColumns(col, cols));
}

void PyIAcadTableImpl::InsertRows(int row, double width, int rows) const
{
    PyThrowBadHr(impObj()->InsertRows(row, width, rows));
}

void PyIAcadTableImpl::DeleteRows(int row, int rows) const
{
    PyThrowBadHr(impObj()->DeleteRows(row, rows));
}

void PyIAcadTableImpl::MergeCells(int minRow, int maxRow, int minCol, int maxCol) const
{
    PyThrowBadHr(impObj()->MergeCells(minRow, maxRow, minCol, maxCol));
}

void PyIAcadTableImpl::UnmergeCells(int minRow, int maxRow, int minCol, int maxCol) const
{
    PyThrowBadHr(impObj()->UnmergeCells(minRow, maxRow, minCol, maxCol));
}

bool PyIAcadTableImpl::IsMergedCell(int row, int col, int& minRow, int& maxRow, int& minCol, int& maxCol) const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->IsMergedCell(row, col, &minRow, &maxRow, &minCol, &maxCol, &rtVal));
    return rtVal != VARIANT_FALSE;
}

AcDbObjectId PyIAcadTableImpl::GetFieldId(int row, int col) const
{
    AcDbObjectId id;
    LONG_PTR rtval = 0;
    PyThrowBadHr(impObj()->GetFieldId(row, col, &rtval));
    return id.setFromOldId(rtval);
}

void PyIAcadTableImpl::SetFieldId(int row, int col, const AcDbObjectId& id) const
{
    PyThrowBadHr(impObj()->SetFieldId(row, col, id.asOldId()));
}

void PyIAcadTableImpl::GenerateLayout() const
{
    PyThrowBadHr(impObj()->GenerateLayout());
}

void PyIAcadTableImpl::RecomputeTableBlock(bool bForceUpdate) const
{
    PyThrowBadHr(impObj()->RecomputeTableBlock(bForceUpdate ? VARIANT_TRUE : VARIANT_FALSE));
}

boost::python::tuple PyIAcadTableImpl::HitTest(const AcGePoint3d& wpt, const AcGeVector3d& wviewVec) const
{
    int rtRow = -1;
    int rtcol = -1;
    _variant_t vtwpt;
    _variant_t vtwviewVec;
    VARIANT_BOOL rtbool = VARIANT_FALSE;
    PyAutoLockGIL lock;
    PyThrowBadHr(AcGePoint3dToVariant(vtwpt.GetVARIANT(), wpt));
    PyThrowBadHr(AcGeVector3dToVariant(vtwviewVec.GetVARIANT(), wviewVec));
    PyThrowBadHr(impObj()->HitTest(vtwpt, vtwviewVec, &rtRow, &rtcol, &rtbool));
    return boost::python::make_tuple(rtbool != VARIANT_FALSE, rtRow, rtcol);
}

boost::python::tuple PyIAcadTableImpl::Select(const AcGePoint3d& wpt, const AcGeVector3d& wvwVec, const AcGeVector3d& wvwxVec, double wxaper, double wyaper, bool allowOutside) const
{
    int rtRow = -1;
    int rtcol = -1;
    _variant_t vtwpt;
    _variant_t vtwvwVec;
    _variant_t vtwvwxVec;
    PyAutoLockGIL lock;
    PyThrowBadHr(AcGePoint3dToVariant(vtwpt.GetVARIANT(), wpt));
    PyThrowBadHr(AcGeVector3dToVariant(vtwvwVec.GetVARIANT(), wvwVec));
    PyThrowBadHr(AcGeVector3dToVariant(vtwvwxVec.GetVARIANT(), wvwxVec));
#ifdef _BRXTARGET250
    _variant_t paths; //ignore?
    PyThrowBadHr(impObj()->Select(vtwpt, vtwvwVec, vtwvwxVec, wxaper, wyaper, allowOutside ? VARIANT_TRUE : VARIANT_FALSE, &rtRow, &rtcol, &paths.GetVARIANT()));
#else
    PyThrowBadHr(impObj()->Select(vtwpt, vtwvwVec, vtwvwxVec, wxaper, wyaper, allowOutside ? VARIANT_TRUE : VARIANT_FALSE, &rtRow, &rtcol));
#endif
    return boost::python::make_tuple(rtRow, rtcol);
}


boost::python::tuple PyIAcadTableImpl::SelectSubRegion(const AcGePoint3d& wpt1, const AcGePoint3d& wpt2, const AcGeVector3d& wvwVec, const AcGeVector3d& wvwxVec, PyAcSelectType seltype, bool bIncludeCurrent) const
{
    int rowMin = -1;
    int rowMax = -1;
    int colMin = -1;
    int colMax = -1;
    _variant_t vtwpt1;
    _variant_t vtwpt2;
    _variant_t vtwvwVec;
    _variant_t vtwvwxVec;
    PyAutoLockGIL lock;
    PyThrowBadHr(AcGePoint3dToVariant(vtwpt1.GetVARIANT(), wpt1));
    PyThrowBadHr(AcGePoint3dToVariant(vtwpt2.GetVARIANT(), wpt2));
    PyThrowBadHr(AcGeVector3dToVariant(vtwvwVec.GetVARIANT(), wvwVec));
    PyThrowBadHr(AcGeVector3dToVariant(vtwvwxVec.GetVARIANT(), wvwxVec));
#ifdef _BRXTARGET250
    _variant_t paths; //ignore?
    PyThrowBadHr(impObj()->SelectSubRegion(vtwpt2, vtwpt2, vtwvwVec, vtwvwxVec, (AcSelectType)seltype, bIncludeCurrent ? VARIANT_TRUE : VARIANT_FALSE, &rowMin, &rowMax, &colMin, &colMax, &paths.GetVARIANT()));
#else
    PyThrowBadHr(impObj()->SelectSubRegion(vtwpt2, vtwpt2, vtwvwVec, vtwvwxVec, (AcSelectType)seltype, bIncludeCurrent ? VARIANT_TRUE : VARIANT_FALSE, &rowMin, &rowMax, &colMin, &colMax));
#endif
    return boost::python::make_tuple(rowMin, rowMax, colMin, colMax);
}

IAcadTable* PyIAcadTableImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadTable*>(m_pimpl.GetInterfacePtr());
}