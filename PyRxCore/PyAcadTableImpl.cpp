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

void PyIAcadTableImpl::SetFlowDirection(PyAcTableDirection val) const
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

void PyIAcadTableImpl::SetDirection(const AcGeVector3d& val) const
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
#ifdef _BRXTARGET260
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
#ifdef _BRXTARGET260
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
#ifdef _BRXTARGET260
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
#ifdef _BRXTARGET260
    _variant_t paths; //ignore?
    PyThrowBadHr(impObj()->SelectSubRegion(vtwpt1, vtwpt2, vtwvwVec, vtwvwxVec, (AcSelectType)seltype, bIncludeCurrent ? VARIANT_TRUE : VARIANT_FALSE, &rowMin, &rowMax, &colMin, &colMax, &paths.GetVARIANT()));
#else
    PyThrowBadHr(impObj()->SelectSubRegion(vtwpt1, vtwpt2, vtwvwVec, vtwvwxVec, (AcSelectType)seltype, bIncludeCurrent ? VARIANT_TRUE : VARIANT_FALSE, &rowMin, &rowMax, &colMin, &colMax));
#endif
    return boost::python::make_tuple(rowMin, rowMax, colMin, colMax);
}

void PyIAcadTableImpl::ReselectSubRegion() const
{
#ifdef _BRXTARGET260
    _variant_t paths; //ignore?
    PyThrowBadHr(impObj()->ReselectSubRegion(&paths.GetVARIANT()));
#else
    PyThrowBadHr(impObj()->ReselectSubRegion());
#endif
}

void PyIAcadTableImpl::ClearSubSelection() const
{
    PyThrowBadHr(impObj()->ClearSubSelection());
}

bool PyIAcadTableImpl::GetHasSubSelection() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_HasSubSelection(&rtVal));
    return rtVal != VARIANT_FALSE;
}

bool PyIAcadTableImpl::GetRegenerateTableSuppressed() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_RegenerateTableSuppressed(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadTableImpl::SetRegenerateTableSuppressed(bool val) const
{
    PyThrowBadHr(impObj()->put_RegenerateTableSuppressed(val ? VARIANT_TRUE : VARIANT_FALSE));
}

CString PyIAcadTableImpl::FormatValue(int row, int col, PyAcFormatOption fmt) const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->FormatValue(row, col, (AcFormatOption)fmt, &bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

boost::python::tuple PyIAcadTableImpl::GetCellDataType(int row, int col) const
{
    PyAutoLockGIL lock;
    AcValueDataType rtVal = (AcValueDataType)PyAcValueDataType::pyacUnknownDataType;
    AcValueUnitType rtUnit = (AcValueUnitType)PyAcValueUnitType::pyacUnitless;
    PyThrowBadHr(impObj()->GetCellDataType(row, col, &rtVal, &rtUnit));
    return boost::python::make_tuple((PyAcValueDataType)rtVal, (PyAcValueUnitType)rtUnit);
}

void PyIAcadTableImpl::SetCellDataType(int row, int col, PyAcValueDataType dataType, PyAcValueUnitType unitType) const
{
    PyThrowBadHr(impObj()->SetCellDataType(row, col, (AcValueDataType)dataType, (AcValueUnitType)unitType));
}

CString PyIAcadTableImpl::GetCellFormat(int row, int col) const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->GetCellFormat(row, col, &bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadTableImpl::SetCellFormat(int row, int col, const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->SetCellFormat(row, row, bstrval));
}

AcValue PyIAcadTableImpl::GetCellValue(int row, int col) const
{
    _variant_t varVal;
    PyThrowBadHr(impObj()->GetCellValue(row, col, &varVal.GetVARIANT()));
#ifdef _ARXTARGET
    return AcValue(varVal);
#else
    switch (varVal.vt)
    {
        case VT_I2:
            return AcValue(Adesk::Int32(varVal.iVal));
        case VT_I4:
            return AcValue(Adesk::Int32(varVal.lVal));
        case VT_R4:
            return AcValue(varVal.fltVal);
        case VT_R8:
            return AcValue(varVal.dblVal);
        case VT_BSTR:
            return AcValue(varVal.bstrVal);
        default:
            break;
    }
    return AcValue();
#endif 
}

void PyIAcadTableImpl::SetCellValue(int row, int col, const AcValue& acVal) const
{
    //TODO: TEST
    _variant_t varVal = {};
#ifdef _ARXTARGET
    if (!acVal.get(varVal.GetVARIANT()))
        PyThrowBadEs(eInvalidInput);
#else
    switch (acVal.dataType())
    {
        case AcValue::kLong:
        {
            Adesk::Int32 val = acVal;
            varVal = _variant_t(int32_t(val));
        }
        break;
        case AcValue::kDouble:
        {
            double val = acVal;
            varVal = _variant_t(val);
        }
        break;
        case AcValue::kString:
        {
            const wchar_t* val = acVal;
            varVal = _variant_t(val);
        }
        break;
        default:
            PyThrowBadEs(eInvalidInput);
    }
#endif 
    PyThrowBadHr(impObj()->SetCellValue(row, col, varVal));
}

void PyIAcadTableImpl::SetCellValueFromText(int row, int col, const CString& val, PyAcParseOption nOption) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->SetCellValueFromText(row, col, bstrval, (AcParseOption)nOption));
}

void PyIAcadTableImpl::ResetCellValue(int row, int col) const
{
    PyThrowBadHr(impObj()->ResetCellValue(row, col));
}

bool PyIAcadTableImpl::IsEmpty(int row, int col) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->IsEmpty(row, col, &rtVal));
    return rtVal != VARIANT_FALSE;
#endif 
}

int PyIAcadTableImpl::CreateContent(int row, int col, int nIndex) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    int rtval = 0;
    PyThrowBadHr(impObj()->CreateContent(row, col, nIndex, &rtval));
    return rtval;
#endif 
}

void PyIAcadTableImpl::MoveContent(int row, int col, int nFromIndex, int nToIndex) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    PyThrowBadHr(impObj()->MoveContent(row, col, nFromIndex, nToIndex));
#endif 
}

void PyIAcadTableImpl::DeleteContent(int row, int col) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    PyThrowBadHr(impObj()->DeleteContent(row, col));
#endif 
}

boost::python::tuple PyIAcadTableImpl::GetSubSelection() const
{
    int rowMin = -1;
    int rowMax = -1;
    int colMin = -1;
    int colMax = -1;
    PyThrowBadHr(impObj()->GetSubSelection(&rowMin, &rowMax, &colMin, &colMax));
    return boost::python::make_tuple(rowMin, rowMax, colMin, colMax);
}

void PyIAcadTableImpl::SetSubSelection(int minRow, int maxRow, int minCol, int maxCol) const
{
    PyThrowBadHr(impObj()->SetSubSelection(minRow, maxRow, minCol, maxCol));
}

AcValue PyIAcadTableImpl::GetValue(int row, int col, int nContent) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    _variant_t varVal;
    PyThrowBadHr(impObj()->GetValue(row, col, nContent, &varVal.GetVARIANT()));
#ifdef _ARXTARGET
    return AcValue(varVal);
#else
    switch (varVal.vt)
    {
        case VT_I2:
            return AcValue(Adesk::Int32(varVal.iVal));
        case VT_I4:
            return AcValue(Adesk::Int32(varVal.lVal));
        case VT_R4:
            return AcValue(varVal.fltVal);
        case VT_R8:
            return AcValue(varVal.dblVal);
        case VT_BSTR:
            return AcValue(varVal.bstrVal);
        default:
            break;
    }
    return AcValue();
#endif 
#endif 
}

void PyIAcadTableImpl::SetValue(int row, int col, int nContent, const AcValue& acVal) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    //TODO: TEST
    _variant_t varVal = {};
#ifdef _ARXTARGET
    if (!acVal.get(varVal.GetVARIANT()))
        PyThrowBadEs(eInvalidInput);
#else
    switch (acVal.dataType())
    {
        case AcValue::kLong:
        {
            Adesk::Int32 val = acVal;
            varVal = _variant_t(int32_t(val));
        }
        break;
        case AcValue::kDouble:
        {
            double val = acVal;
            varVal = _variant_t(val);
        }
        break;
        case AcValue::kString:
        {
            const wchar_t* val = acVal;
            varVal = _variant_t(val);
        }
        break;
        default:
            PyThrowBadEs(eInvalidInput);
    }
#endif 
    PyThrowBadHr(impObj()->SetValue(row, col, nContent, varVal));
#endif 
}

void PyIAcadTableImpl::SetValueFromText(int row, int col, int nContent, const CString& val, PyAcParseOption nOption) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->SetValueFromText(row, col, nContent, bstrval, (AcParseOption)nOption));
#endif 
}

CString PyIAcadTableImpl::GetDataFormat(int row, int col, int nContent) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->GetDataFormat(row, col, nContent, &bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
#endif 
}

void PyIAcadTableImpl::SetDataFormat(int row, int col, int nContent, const CString& val) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->SetDataFormat(row, col, nContent, bstrval));
#endif 
}

CString PyIAcadTableImpl::GetTextString(int row, int col, int nContent) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->GetTextString(row, col, nContent, &bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
#endif 
}

void PyIAcadTableImpl::SetTextString(int row, int col, int nContent, const CString& val) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->SetTextString(row, col, nContent, bstrval));
#endif 
}

AcDbObjectId PyIAcadTableImpl::GetFieldId2(int row, int col, int nContent) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    LONG_PTR rtval = 0;
    AcDbObjectId id;
    PyThrowBadHr(impObj()->GetFieldId2(row, col, nContent, &rtval));
    return id.setFromOldId(rtval);
#endif 
}

void PyIAcadTableImpl::SetFieldId2(int row, int col, int nContent, const AcDbObjectId& val, PyAcCellOption nflag) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    PyThrowBadHr(impObj()->SetFieldId2(row, col, nContent, val.asOldId(), (AcCellOption)nflag));
#endif 
}

AcDbObjectId PyIAcadTableImpl::GetBlockTableRecordId2(int row, int col, int nContent) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    LONG_PTR rtval = 0;
    AcDbObjectId id;
    PyThrowBadHr(impObj()->GetBlockTableRecordId2(row, col, nContent, &rtval));
    return id.setFromOldId(rtval);
#endif 
}

void PyIAcadTableImpl::SetBlockTableRecordId2(int row, int col, int nContent, const AcDbObjectId& val, bool autoScale) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    PyThrowBadHr(impObj()->SetBlockTableRecordId2(row, col, nContent, val.asOldId(), autoScale ? VARIANT_TRUE : VARIANT_FALSE));
#endif 
}

CString PyIAcadTableImpl::GetBlockAttributeValue2(int row, int col, int nContent, const AcDbObjectId& val) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->GetBlockAttributeValue2(row, col, nContent, val.asOldId(), &bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
#endif 
}

void PyIAcadTableImpl::SetBlockAttributeValue2(int row, int col, int nContent, const AcDbObjectId& id, const CString& val) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->SetBlockAttributeValue2(row, col, nContent, id.asOldId(), bstrval));
#endif 
}

AcValue PyIAcadTableImpl::GetCustomData(int row, int col, const CString& key) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    _variant_t varVal;
    _bstr_t bstkey{ key };
    PyThrowBadHr(impObj()->GetCustomData(row, col, bstkey, &varVal.GetVARIANT()));
#ifdef _ARXTARGET
    return AcValue(varVal);
#else
    switch (varVal.vt)
    {
        case VT_I2:
            return AcValue(Adesk::Int32(varVal.iVal));
        case VT_I4:
            return AcValue(Adesk::Int32(varVal.lVal));
        case VT_R4:
            return AcValue(varVal.fltVal);
        case VT_R8:
            return AcValue(varVal.dblVal);
        case VT_BSTR:
            return AcValue(varVal.bstrVal);
        default:
            break;
    }
    return AcValue();
#endif 
#endif 
}

void PyIAcadTableImpl::SetCustomData(int row, int col, const CString& key, const AcValue& acVal) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    _variant_t varVal = {};
    _bstr_t bstkey{ key };
#ifdef _ARXTARGET
    if (!acVal.get(varVal.GetVARIANT()))
        PyThrowBadEs(eInvalidInput);
#else
    switch (acVal.dataType())
    {
        case AcValue::kLong:
        {
            Adesk::Int32 val = acVal;
            varVal = _variant_t(int32_t(val));
        }
        break;
        case AcValue::kDouble:
        {
            double val = acVal;
            varVal = _variant_t(val);
        }
        break;
        case AcValue::kString:
        {
            const wchar_t* val = acVal;
            varVal = _variant_t(val);
        }
        break;
        default:
            PyThrowBadEs(eInvalidInput);
    }
#endif 
    PyThrowBadHr(impObj()->SetCustomData(row, col, bstkey, varVal));
#endif 
}

CString PyIAcadTableImpl::GetCellStyle(int row, int col) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->GetCellStyle(row, col, &bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
#endif 
}

void PyIAcadTableImpl::SetCellStyle(int row, int col, const CString& val) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->SetCellStyle(row, col, bstrval));
#endif 
}

PyIAcadAcCmColorPtr PyIAcadTableImpl::GetContentColor2(int row, int col, int nContent) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    IAcadAcCmColor* pColor = nullptr;
    PyThrowBadHr(impObj()->GetContentColor2(row, col, nContent, &pColor));
    return std::make_unique<PyIAcadAcCmColorImpl>(pColor);
#endif 
}

void PyIAcadTableImpl::SetContentColor2(int row, int col, int nContent, const PyIAcadAcCmColorImpl& val) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    PyThrowBadHr(impObj()->SetContentColor2(row, col, nContent, val.impObj()));
#endif 
}

boost::python::tuple PyIAcadTableImpl::GetDataType2(int row, int col, int nContent) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    PyAutoLockGIL lock;
    AcValueDataType rtVal = (AcValueDataType)PyAcValueDataType::pyacUnknownDataType;
    AcValueUnitType rtUnit = (AcValueUnitType)PyAcValueUnitType::pyacUnitless;
    PyThrowBadHr(impObj()->GetDataType2(row, col, nContent, &rtVal, &rtUnit));
    return boost::python::make_tuple((PyAcValueDataType)rtVal, (PyAcValueUnitType)rtUnit);
#endif 
}

void PyIAcadTableImpl::SetDataType2(int row, int col, int nContent, PyAcValueDataType dataType, PyAcValueUnitType unitType) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    PyThrowBadHr(impObj()->SetDataType2(row, col, nContent, (AcValueDataType)dataType, (AcValueUnitType)unitType));
#endif 
}

CString PyIAcadTableImpl::GetTextStyle2(int row, int col, int nContent) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->GetTextStyle2(row, col, nContent, &bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
#endif 
}

void PyIAcadTableImpl::SetTextStyle2(int row, int col, int nContent, const CString& val) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->SetTextStyle2(row, col, nContent, bstrval));
#endif 
}

double PyIAcadTableImpl::GetTextHeight2(int row, int col, int nContent) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    double rtval = 0.0;
    PyThrowBadHr(impObj()->GetTextHeight2(row, col, nContent, &rtval));
    return rtval;
#endif 
}

void PyIAcadTableImpl::SetTextHeight2(int row, int col, int nContent, double val) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    PyThrowBadHr(impObj()->SetTextHeight2(row, col, nContent, val));
#endif 
}

double PyIAcadTableImpl::GetRotation(int row, int col, int nContent) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    double rtval = 0.0;
    PyThrowBadHr(impObj()->GetRotation(row, col, nContent, &rtval));
    return rtval;
#endif 
}

void PyIAcadTableImpl::SetRotation(int row, int col, int nContent, double val) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    PyThrowBadHr(impObj()->SetRotation(row, col, nContent, val));
#endif 
}

bool PyIAcadTableImpl::GetAutoScale2(int row, int col, int nContent) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->GetAutoScale2(row, col, nContent, &rtVal));
    return rtVal != VARIANT_FALSE;
#endif 
}

void PyIAcadTableImpl::SetAutoScale2(int row, int col, int nContent, bool val) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    PyThrowBadHr(impObj()->SetAutoScale2(row, col, nContent, val ? VARIANT_TRUE : VARIANT_FALSE));
#endif 
}

double PyIAcadTableImpl::GetScale(int row, int col, int nContent) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    double rtval = 0.0;
    PyThrowBadHr(impObj()->GetScale(row, col, nContent, &rtval));
    return rtval;
#endif 
}

void PyIAcadTableImpl::SetScale(int row, int col, int nContent, double val) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    PyThrowBadHr(impObj()->SetScale(row, col, nContent, val));
#endif 
}

void PyIAcadTableImpl::RemoveAllOverrides(int row, int col) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    PyThrowBadHr(impObj()->RemoveAllOverrides(row, col));
#endif 
}

PyAcLineWeight PyIAcadTableImpl::GetGridLineWeight2(int row, int col, PyAcGridLineType lt) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    AcLineWeight rtVal = (AcLineWeight)PyAcLineWeight::pyacLnWt000;
    PyThrowBadHr(impObj()->GetGridLineWeight2(row, col, (AcGridLineType)lt, &rtVal));
    return (PyAcLineWeight)rtVal;
#endif 
}

void PyIAcadTableImpl::SetGridLineWeight2(int row, int col, PyAcGridLineType lt, PyAcLineWeight lw) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    PyThrowBadHr(impObj()->SetGridLineWeight2(row, col, (AcGridLineType)lt, (AcLineWeight)lw));
#endif 
}

AcDbObjectId PyIAcadTableImpl::GetGridLinetype(int row, int col, PyAcGridLineType lt) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    LONG_PTR rtval = 0;
    AcDbObjectId id;
    PyThrowBadHr(impObj()->GetGridLinetype(row, col, (AcGridLineType)lt, &rtval));
    return id.setFromOldId(rtval);
#endif 
}

void PyIAcadTableImpl::SetGridLinetype(int row, int col, PyAcGridLineType lt, const AcDbObjectId& val) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    PyThrowBadHr(impObj()->SetGridLinetype(row, col, (AcGridLineType)lt, val.asOldId()));
#endif 
}

PyIAcadAcCmColorPtr PyIAcadTableImpl::GetGridColor2(int row, int col, PyAcGridLineType lt) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    IAcadAcCmColor* pColor = nullptr;
    PyThrowBadHr(impObj()->GetGridColor2(row, col, (AcGridLineType)lt, &pColor));
    return std::make_unique<PyIAcadAcCmColorImpl>(pColor);
#endif 
}

void PyIAcadTableImpl::SetGridColor2(int row, int col, PyAcGridLineType lt, const PyIAcadAcCmColorImpl& val) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    PyThrowBadHr(impObj()->SetGridColor2(row, col, (AcGridLineType)lt, val.impObj()));
#endif 
}

bool PyIAcadTableImpl::GetGridVisibility2(int row, int col, PyAcGridLineType lt) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->GetGridVisibility2(row, col, (AcGridLineType)lt, &rtVal));
    return rtVal != VARIANT_FALSE;
#endif 
}

void PyIAcadTableImpl::SetGridVisibility2(int row, int col, PyAcGridLineType lt, bool val) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    PyThrowBadHr(impObj()->SetGridVisibility2(row, col, (AcGridLineType)lt, val ? VARIANT_TRUE : VARIANT_FALSE));
#endif 
}

double PyIAcadTableImpl::GetGridDoubleLineSpacing(int row, int col, PyAcGridLineType lt) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    double rtval = 0.0;
    PyThrowBadHr(impObj()->GetGridDoubleLineSpacing(row, col, (AcGridLineType)lt, &rtval));
    return rtval;
#endif 
}

void PyIAcadTableImpl::SetGridDoubleLineSpacing(int row, int col, PyAcGridLineType lt, double val) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    PyThrowBadHr(impObj()->SetGridDoubleLineSpacing(row, col, (AcGridLineType)lt, val));
#endif 
}

void PyIAcadTableImpl::SetEnableBreak(bool val) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    PyThrowBadHr(impObj()->put_EnableBreak(val ? VARIANT_TRUE : VARIANT_FALSE));
#endif 
}

double PyIAcadTableImpl::GetBreakHeight(int nIndex) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    double rtval = 0.0;
    PyThrowBadHr(impObj()->GetBreakHeight(nIndex, &rtval));
    return rtval;
#endif 
}

void PyIAcadTableImpl::SetBreakHeight(int nIndex, double val) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    PyThrowBadHr(impObj()->SetBreakHeight(nIndex, val));
#endif 
}

PyAcCellContentType PyIAcadTableImpl::GetContentType(int row, int col) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    AcCellContentType rtVal = (AcCellContentType)PyAcCellContentType::pyacCellContentTypeUnknown;
    PyThrowBadHr(impObj()->GetContentType(row, col, &rtVal));
    return (PyAcCellContentType)rtVal;
#endif 
}

double PyIAcadTableImpl::GetMargin(int row, int col, PyAcCellMargin margin) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    double rtval = 0.0;
    PyThrowBadHr(impObj()->GetMargin(row, col, (AcCellMargin)margin, &rtval));
    return rtval;
#endif 
}

void PyIAcadTableImpl::SetMargin(int row, int col, PyAcCellMargin margin, double val) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    PyThrowBadHr(impObj()->SetMargin(row, col, (AcCellMargin)margin, val));
#endif 
}

PyAcCellContentLayout PyIAcadTableImpl::GetContentLayout(int row, int col) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    AcCellContentLayout rtVal = (AcCellContentLayout)PyAcCellContentLayout::pyacCellContentLayoutFlow;
    PyThrowBadHr(impObj()->GetContentLayout(row, col, &rtVal));
    return (PyAcCellContentLayout)rtVal;
#endif 
}

void PyIAcadTableImpl::SetContentLayout(int row, int col, PyAcCellContentLayout val) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    PyThrowBadHr(impObj()->SetContentLayout(row, col, (AcCellContentLayout)val));
#endif 
}

PyAcCellProperty PyIAcadTableImpl::GetOverride(int row, int col, int nContent) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    AcCellProperty rtVal = (AcCellProperty)PyAcCellProperty::pyacInvalidCellProperty;
    PyThrowBadHr(impObj()->GetOverride(row, col, nContent, &rtVal));
    return (PyAcCellProperty)rtVal;
#endif 
}

void PyIAcadTableImpl::SetOverride(int row, int col, int nContent, PyAcCellProperty val) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    PyThrowBadHr(impObj()->SetOverride(row, col, nContent, (AcCellProperty)val));
#endif 
}

PyAcGridLineStyle PyIAcadTableImpl::GetGridLineStyle(int row, int col, PyAcGridLineType lt) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    AcGridLineStyle rtVal = (AcGridLineStyle)PyAcGridLineStyle::pyacGridLineStyleSingle;
    PyThrowBadHr(impObj()->GetGridLineStyle(row, col, (AcGridLineType)lt, &rtVal));
    return (PyAcGridLineStyle)rtVal;
#endif 
}

void PyIAcadTableImpl::SetGridLineStyle(int row, int col, PyAcGridLineType lt, PyAcGridLineStyle val) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    PyThrowBadHr(impObj()->SetGridLineStyle(row, col, (AcGridLineType)lt, (AcGridLineStyle)val));
#endif 
}

void PyIAcadTableImpl::InsertRowsAndInherit(int nIndex, int nInheritFrom, int nNumRows) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    PyThrowBadHr(impObj()->InsertRowsAndInherit(nIndex, nInheritFrom, nNumRows));
#endif 
}

void PyIAcadTableImpl::InsertColumnsAndInherit(int nIndex, int nInheritFrom, int nNumCols) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    PyThrowBadHr(impObj()->InsertColumnsAndInherit(nIndex, nInheritFrom, nNumCols));
#endif 
}

bool PyIAcadTableImpl::GetHasFormula(int row, int col, int nContent) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->GetHasFormula(row, col, nContent, &rtVal));
    return rtVal != VARIANT_FALSE;
#endif 
}

CString PyIAcadTableImpl::GetFormula(int row, int col, int nContent) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->GetFormula(row, col, nContent, &bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
#endif 
}

void PyIAcadTableImpl::SetFormula(int row, int col, int nContent, const CString& val) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->SetFormula(row, col, nContent, bstrval));
#endif 
}

bool PyIAcadTableImpl::IsContentEditable(int row, int col) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->IsContentEditable(row, col, &rtVal));
    return rtVal != VARIANT_FALSE;
#endif 
}

bool PyIAcadTableImpl::IsFormatEditable(int row, int col) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->IsFormatEditable(row, col, &rtVal));
    return rtVal != VARIANT_FALSE;
#endif 
}

PyAcCellState PyIAcadTableImpl::GetCellState(int row, int col) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    AcCellState rtVal = (AcCellState)PyAcCellState::pyacCellStateNone;
    PyThrowBadHr(impObj()->GetCellState(row, col, &rtVal));
    return (PyAcCellState)rtVal;
#endif 
}

void PyIAcadTableImpl::SetCellState(int row, int col, PyAcCellState val) const
{
    PyThrowBadHr(impObj()->SetCellState(row, col, (AcCellState)val));
}

void PyIAcadTableImpl::EnableMergeAll(int row, int col, bool val) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    PyThrowBadHr(impObj()->EnableMergeAll(row, col, val ? VARIANT_TRUE : VARIANT_FALSE));
#endif 
}

bool PyIAcadTableImpl::IsMergeAllEnabled(int row, int col) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->IsMergeAllEnabled(row, col, &rtVal));
    return rtVal != VARIANT_FALSE;
#endif 
}

bool PyIAcadTableImpl::GetBreaksEnabled() const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_BreaksEnabled(&rtVal));
    return rtVal != VARIANT_FALSE;
#endif 
}

void PyIAcadTableImpl::SetBreaksEnabled(bool val) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    PyThrowBadHr(impObj()->put_BreaksEnabled(val ? VARIANT_TRUE : VARIANT_FALSE));
#endif 
}

bool PyIAcadTableImpl::GetRepeatTopLabels() const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_RepeatTopLabels(&rtVal));
    return rtVal != VARIANT_FALSE;
#endif 
}

void PyIAcadTableImpl::SetRepeatTopLabels(bool val) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    PyThrowBadHr(impObj()->put_RepeatTopLabels(val ? VARIANT_TRUE : VARIANT_FALSE));
#endif 
}

bool PyIAcadTableImpl::GetRepeatBottomLabels() const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_RepeatBottomLabels(&rtVal));
    return rtVal != VARIANT_FALSE;
#endif 
}

void PyIAcadTableImpl::SetRepeatBottomLabels(bool val) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    PyThrowBadHr(impObj()->put_RepeatBottomLabels(val ? VARIANT_TRUE : VARIANT_FALSE));
#endif 
}

PyAcTableFlowDirection PyIAcadTableImpl::GetTableBreakFlowDirection() const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    AcTableFlowDirection rtVal = (AcTableFlowDirection)PyAcTableFlowDirection::pyacTableFlowDownOrUp;
    PyThrowBadHr(impObj()->get_TableBreakFlowDirection(&rtVal));
    return (PyAcTableFlowDirection)rtVal;
#endif 
}

void PyIAcadTableImpl::SetTableBreakFlowDirection(PyAcTableFlowDirection val) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    PyThrowBadHr(impObj()->put_TableBreakFlowDirection((AcTableFlowDirection)val));
#endif 
}

bool PyIAcadTableImpl::GetAllowManualPositions() const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_AllowManualPositions(&rtVal));
    return rtVal != VARIANT_FALSE;
#endif 
}

void PyIAcadTableImpl::SetAllowManualPositions(bool val) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    PyThrowBadHr(impObj()->put_AllowManualPositions(val ? VARIANT_TRUE : VARIANT_FALSE));
#endif 
}

bool PyIAcadTableImpl::GetAllowManualHeights() const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_AllowManualHeights(&rtVal));
    return rtVal != VARIANT_FALSE;
#endif 
}

void PyIAcadTableImpl::SetAllowManualHeights(bool val) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    PyThrowBadHr(impObj()->put_AllowManualHeights(val ? VARIANT_TRUE : VARIANT_FALSE));
#endif 
}

double PyIAcadTableImpl::GetTableBreakHeight() const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_TableBreakHeight(&rtval));
    return rtval;
#endif 
}

void PyIAcadTableImpl::SetTableBreakHeight(double val) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    PyThrowBadHr(impObj()->put_TableBreakHeight(val));
#endif 
}

double PyIAcadTableImpl::GetBreakSpacing() const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_BreakSpacing(&rtval));
    return rtval;
#endif 
}

void PyIAcadTableImpl::SetBreakSpacing(double val) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    PyThrowBadHr(impObj()->put_BreakSpacing(val));
#endif 
}

CString PyIAcadTableImpl::GetColumnName(int col) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->GetColumnName(col, &bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
#endif 
}

void PyIAcadTableImpl::SetColumnName(int col, const CString& val) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->SetColumnName(col, bstrval));
#endif 
}

void PyIAcadTableImpl::SetToolTip(int row, int col, const CString& val) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->SetToolTip(row, col, bstrval));
#endif 
}

IAcadTable* PyIAcadTableImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadTable*>(m_pimpl.GetInterfacePtr());
}