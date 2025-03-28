#include "stdafx.h"
#include "PyAcadTable.h"
#include "PyAcadTableImpl.h"
#include "PyAcadEntityImpl.h"
#include "PyAcadObject.h"
#include "PyAcadObjectImpl.h"
#include "PyDbEval.h"

using namespace boost::python;


//----------------------------------------------------------------------------------------
//PyAcadTable
void makePyAcadTableWrapper()
{
    PyDocString DS("AcadTable");
    class_<PyAcadTable, bases<PyAcadEntity>>("AcadTable", boost::python::no_init)
        .def("cast", &PyAcadTable::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadTable::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadTable::PyAcadTable(std::shared_ptr<PyIAcadTableImpl> ptr)
    : PyAcadEntity(ptr)
{
}

std::string PyAcadTable::styleName() const
{
    return wstr_to_utf8(impObj()->GetStyleName());
}

void PyAcadTable::setStyleName(const std::string val) const
{
    impObj()->SetStyleName(utf8_to_wstr(val).c_str());
}

int PyAcadTable::rows() const
{
    return impObj()->GetRows();
}

void PyAcadTable::setRows(int val) const
{
    impObj()->SetRows(val);
}

int PyAcadTable::columns() const
{
    return impObj()->GetColumns();
}

void PyAcadTable::setColumns(int val) const
{
    impObj()->SetColumns(val);
}

PyAcTableDirection PyAcadTable::flowDirection() const
{
    return impObj()->GetFlowDirection();
}

void PyAcadTable::setFlowDirection(PyAcTableDirection val) const
{
    impObj()->SetFlowDirection(val);
}

double PyAcadTable::width() const
{
    return impObj()->GetWidth();
}

void PyAcadTable::setWidth(double val) const
{
    impObj()->SetWidth(val);
}

double PyAcadTable::height() const
{
    return impObj()->GetHeight();
}

void PyAcadTable::setHeight(double val) const
{
    impObj()->SetHeight(val);
}

double PyAcadTable::vertCellMargin() const
{
    return impObj()->GetVertCellMargin();
}

void PyAcadTable::setVertCellMargin(double val) const
{
    impObj()->SetVertCellMargin(val);
}

double PyAcadTable::horzCellMargin() const
{
    return impObj()->GetHorzCellMargin();
}

void PyAcadTable::setHorzCellMargin(double val) const
{
    impObj()->SetHorzCellMargin(val);
}

AcGePoint3d PyAcadTable::insertionPoint() const
{
    return impObj()->GetInsertionPoint();
}

void PyAcadTable::setInsertionPoint(const AcGePoint3d val) const
{
    impObj()->SetInsertionPoint(val);
}

double PyAcadTable::columnWidth(int col) const
{
    return impObj()->GetColumnWidth(col);
}

void PyAcadTable::setColumnWidth1(double val) const
{
    impObj()->SetColumnWidth(val);
}

void PyAcadTable::setColumnWidth2(int col, double val) const
{
    impObj()->SetColumnWidth(col, val);
}

double PyAcadTable::rowHeight(int row) const
{
    return impObj()->GetRowHeight(row);
}

void PyAcadTable::setRowHeight1(double val) const
{
    impObj()->SetRowHeight(val);
}

void PyAcadTable::setRowHeight2(int row, double val) const
{
    impObj()->SetRowHeight(row, val);
}

double PyAcadTable::minimumColumnWidth(int col) const
{
    return impObj()->GetMinimumColumnWidth(col);
}

double PyAcadTable::minimumRowHeight(int row) const
{
    return impObj()->GetMinimumRowHeight(row);
}

double PyAcadTable::minimumTableWidth() const
{
    return impObj()->GetMinimumTableWidth();
}

double PyAcadTable::minimumTableHeight() const
{
    return impObj()->GetMinimumTableHeight();
}

AcGeVector3d PyAcadTable::direction() const
{
    return impObj()->GetDirection();
}

void PyAcadTable::setDirection(const AcGeVector3d val) const
{
    impObj()->SetDirection(val);
}

bool PyAcadTable::titleSuppressed() const
{
    return impObj()->GetTitleSuppressed();
}

void PyAcadTable::setTitleSuppressed(bool val) const
{
    impObj()->SetTitleSuppressed(val);
}

bool PyAcadTable::headerSuppressed() const
{
    return impObj()->GetHeaderSuppressed();
}

void PyAcadTable::setHeaderSuppressed(bool val) const
{
    impObj()->SetHeaderSuppressed(val);
}

boost::python::list PyAcadTable::tableStyleOverrides() const
{
    PyAutoLockGIL lock;
    boost::python::list pylist;
    for (const auto val : impObj()->GetTableStyleOverrides())
        pylist(val);
    return pylist;
}

void PyAcadTable::clearTableStyleOverrides(int flag) const
{
    impObj()->ClearTableStyleOverrides(flag);
}

PyAcCellType PyAcadTable::cellType(int row, int col) const
{
    return impObj()->GetCellType(row, col);
}

void PyAcadTable::setCellType(int row, int col, PyAcCellType val) const
{
    impObj()->SetCellType(row, col, val);
}

boost::python::list PyAcadTable::cellExtents(int row, int col, bool bOuterCell) const
{
    PyAutoLockGIL lock;
    boost::python::list pylist;
    for (const auto& val : impObj()->GetCellExtents(row, col, bOuterCell))
        pylist(val);
    return pylist;
}

AcGePoint3d PyAcadTable::attachmentPoint(int row, int col) const
{
    return impObj()->GetAttachmentPoint(row, col);
}

PyAcCellAlignment PyAcadTable::cellAlignment(int row, int col) const
{
    return impObj()->GetCellAlignment(row, col);
}

void PyAcadTable::setCellAlignment(int row, int col, PyAcCellAlignment val) const
{
    impObj()->SetCellAlignment(row, col, val);
}

bool PyAcadTable::cellBackgroundColorNone(int row, int col) const
{
    return impObj()->GetCellBackgroundColorNone(row, col);
}

void PyAcadTable::setCellBackgroundColorNone(int row, int col, bool val) const
{
    impObj()->SetCellBackgroundColorNone(row, col, val);
}

PyAcadAcCmColor PyAcadTable::cellBackgroundColor(int row, int col) const
{
    return PyAcadAcCmColor{ impObj()->GetCellBackgroundColor(row,col) };
}

void PyAcadTable::setCellBackgroundColor(int row, int col, const PyAcadAcCmColor& val) const
{
    impObj()->SetCellBackgroundColor(row, col, *val.impObj());
}

PyAcadAcCmColor PyAcadTable::cellContentColor(int row, int col) const
{
    return PyAcadAcCmColor{ impObj()->GetCellContentColor(row,col) };
}

void PyAcadTable::setCellContentColor(int row, int col, const PyAcadAcCmColor& val) const
{
    impObj()->SetCellContentColor(row, col, *val.impObj());
}

boost::python::list PyAcadTable::cellStyleOverrides(int row, int col) const
{
    PyAutoLockGIL lock;
    boost::python::list pylist;
    for (const auto val : impObj()->GetCellStyleOverrides(row, col))
        pylist(val);
    return pylist;
}

void PyAcadTable::deleteCellContent(int row, int col) const
{
    impObj()->DeleteCellContent(row, col);
}

PyAcRowType PyAcadTable::rowType(int row) const
{
    return impObj()->GetRowType(row);
}

std::string PyAcadTable::text(int row, int col) const
{
    return wstr_to_utf8(impObj()->GetText(row, col));
}

void PyAcadTable::setText(int row, int col, const std::string& val) const
{
    impObj()->SetText(row, col, utf8_to_wstr(val).c_str());
}

std::string PyAcadTable::cellTextStyle(int row, int col) const
{
    return wstr_to_utf8(impObj()->GetCellTextStyle(row, col));
}

void PyAcadTable::setCellTextStyle(int row, int col, const std::string& val) const
{
    impObj()->SetCellTextStyle(row, col, utf8_to_wstr(val).c_str());
}

double PyAcadTable::cellTextHeight(int row, int col) const
{
    return impObj()->GetCellTextHeight(row, col);
}

void PyAcadTable::setCellTextHeight(int row, int col, double val) const
{
    impObj()->SetCellTextHeight(row, col, val);
}

PyAcRotationAngle PyAcadTable::textRotation(int row, int col) const
{
    return impObj()->GetTextRotation(row, col);
}

void PyAcadTable::setTextRotation(int row, int col, PyAcRotationAngle val) const
{
    impObj()->SetTextRotation(row, col, val);
}

bool PyAcadTable::autoScale(int row, int col) const
{
    return impObj()->GetAutoScale(row, col);
}

void PyAcadTable::setAutoScale(int row, int col, bool val) const
{
    impObj()->SetAutoScale(row, col, val);
}

PyDbObjectId PyAcadTable::blockTableRecordId(int row, int col) const
{
    return PyDbObjectId{ impObj()->GetBlockTableRecordId(row, col) };
}

void PyAcadTable::setBlockTableRecordId(int row, int col, const PyDbObjectId& val, bool autoScale) const
{
    impObj()->SetBlockTableRecordId(row, col, val.m_id, autoScale);
}

double PyAcadTable::blockScale(int row, int col) const
{
    return impObj()->GetBlockScale(row, col);
}

void PyAcadTable::setBlockScale(int row, int col, double val) const
{
    impObj()->SetBlockScale(row, col, val);
}

double PyAcadTable::blockRotation(int row, int col) const
{
    return impObj()->GetBlockRotation(row, col);
}

void PyAcadTable::setBlockRotation(int row, int col, double val) const
{
    impObj()->SetBlockRotation(row, col, val);
}

std::string PyAcadTable::blockAttributeValue(int row, int col, const PyDbObjectId& val) const
{
    return wstr_to_utf8(impObj()->GetBlockAttributeValue(row, col, val.m_id));
}

void PyAcadTable::setBlockAttributeValue(int row, int col, const PyDbObjectId& id, const std::string& val) const
{
    impObj()->SetBlockAttributeValue(row, col, id.m_id, utf8_to_wstr(val).c_str());
}

PyAcLineWeight PyAcadTable::cellGridLineWeight(int row, int col, PyAcCellEdgeMask mask) const
{
    return impObj()->GetCellGridLineWeight(row, col, mask);
}

void PyAcadTable::setCellGridLineWeight(int row, int col, PyAcCellEdgeMask mask, PyAcLineWeight lw) const
{
    impObj()->SetCellGridLineWeight(row, col, mask, lw);
}

PyAcadAcCmColor PyAcadTable::cellGridColor(int row, int col, PyAcCellEdgeMask mask) const
{
    return PyAcadAcCmColor{ impObj()->GetCellGridColor(row, col, mask) };
}

void PyAcadTable::setCellGridColor(int row, int col, PyAcCellEdgeMask mask, const PyAcadAcCmColor& val) const
{
    impObj()->SetCellGridColor(row, col, mask, *val.impObj());
}

bool PyAcadTable::cellGridVisibility(int row, int col, PyAcCellEdgeMask mask) const
{
    return impObj()->GetCellGridVisibility(row, col, mask);
}

void PyAcadTable::setCellGridVisibility(int row, int col, PyAcCellEdgeMask mask, bool val) const
{
    return impObj()->SetCellGridVisibility(row, col, mask, val);
}

void PyAcadTable::insertColumns(int col, double width, int cols) const
{
    impObj()->InsertColumns(col, width, cols);
}

void PyAcadTable::deleteColumns(int col, int cols) const
{
    impObj()->DeleteColumns(col, cols);
}

void PyAcadTable::insertRows(int row, double width, int rows) const
{
    impObj()->InsertRows(row, width, rows);
}

void PyAcadTable::deleteRows(int row, int rows) const
{
    impObj()->DeleteRows(row, rows);
}

void PyAcadTable::mergeCells(int minRow, int maxRow, int minCol, int maxCol) const
{
    impObj()->MergeCells(minRow, maxRow, minCol, maxCol);
}

void PyAcadTable::unmergeCells(int minRow, int maxRow, int minCol, int maxCol) const
{
    impObj()->UnmergeCells(minRow, maxRow, minCol, maxCol);
}

boost::python::tuple PyAcadTable::isMergedCell(int row, int col) const
{
    int minRow = -1;
    int maxRow = -1;
    int minCol = -1;
    int maxCol = -1;
    PyAutoLockGIL lock;
    auto flag = impObj()->IsMergedCell(row, col, minRow, maxRow, minCol, maxCol);
    return boost::python::make_tuple(flag, minRow, maxRow, minCol, maxCol);
}

PyDbObjectId PyAcadTable::fieldId(int row, int col) const
{
    return impObj()->GetFieldId(col, row);
}

void PyAcadTable::setFieldId(int row, int col, const PyDbObjectId& id) const
{
    impObj()->SetFieldId(col, row, id.m_id);
}

void PyAcadTable::generateLayout() const
{
    impObj()->GenerateLayout();
}

void PyAcadTable::recomputeTableBlock(bool bForceUpdate) const
{
    impObj()->RecomputeTableBlock(bForceUpdate);
}

boost::python::tuple PyAcadTable::hitTest(const AcGePoint3d& wpt, const AcGeVector3d& wviewVec) const
{
    return impObj()->HitTest(wpt, wviewVec);
}

boost::python::tuple PyAcadTable::select(const AcGePoint3d& wpt, const AcGeVector3d& wvwVec, const AcGeVector3d& wvwxVec, double wxaper, double wyaper, bool allowOutside) const
{
    return impObj()->Select(wpt, wvwVec, wvwxVec, wxaper, wyaper, allowOutside);
}

boost::python::tuple PyAcadTable::selectSubRegion(const AcGePoint3d& wpt1, const AcGePoint3d& wpt2, const AcGeVector3d& wvwVec, const AcGeVector3d& wvwxVec, PyAcSelectType seltype, bool bIncludeCurrent) const
{
    return impObj()->SelectSubRegion(wpt1, wpt2, wvwVec, wvwxVec, seltype, bIncludeCurrent);
}

boost::python::tuple PyAcadTable::subSelection() const
{
    return impObj()->GetSubSelection();
}

void PyAcadTable::setSubSelection(int minRow, int maxRow, int minCol, int maxCol) const
{
    impObj()->SetSubSelection(minRow, maxRow, minCol, maxCol);
}

void PyAcadTable::reselectSubRegion() const
{
    impObj()->ReselectSubRegion();
}

void PyAcadTable::clearSubSelection() const
{
    impObj()->ClearSubSelection();
}

bool PyAcadTable::hasSubSelection() const
{
    return impObj()->GetHasSubSelection();
}

bool PyAcadTable::regenerateTableSuppressed() const
{
    return impObj()->GetRegenerateTableSuppressed();
}

void PyAcadTable::setRegenerateTableSuppressed(bool val) const
{
    impObj()->SetRegenerateTableSuppressed(val);
}

std::string PyAcadTable::formatValue(int row, int col, PyAcFormatOption fmt) const
{
    return wstr_to_utf8(impObj()->FormatValue(row, col, fmt));
}

boost::python::tuple PyAcadTable::cellDataType(int row, int col) const
{
    return impObj()->GetCellDataType(row, col);
}

void PyAcadTable::setCellDataType(int row, int col, PyAcValueDataType dataType, PyAcValueUnitType unitType) const
{
    impObj()->SetCellDataType(row, col, dataType, unitType);
}

std::string PyAcadTable::cellFormat(int row, int col) const
{
    return wstr_to_utf8(impObj()->GetCellFormat(row, col));
}

void PyAcadTable::setCellFormat(int row, int col, const std::string& val) const
{
    impObj()->SetCellFormat(row, col, utf8_to_wstr(val).c_str());
}

PyDbAcValue PyAcadTable::cellValue(int row, int col) const
{
    return PyDbAcValue{ impObj()->GetCellValue(row, col) };
}

void PyAcadTable::setCellValue(int row, int col, const PyDbAcValue& val) const
{
    impObj()->SetCellValue(row, col, *val.impObj());
}

void PyAcadTable::setCellValueFromText(int row, int col, const std::string& val, PyAcParseOption nOption) const
{
    impObj()->SetCellValueFromText(row, col, utf8_to_wstr(val).c_str(), nOption);
}

void PyAcadTable::resetCellValue(int row, int col) const
{
    impObj()->ResetCellValue(row, col);
}

bool PyAcadTable::isEmpty(int row, int col) const
{
    return impObj()->IsEmpty(row, col);
}

int PyAcadTable::createContent(int row, int col, int nIndex) const
{
    return impObj()->CreateContent(row, col, nIndex);
}

void PyAcadTable::moveContent(int row, int col, int nFromIndex, int nToIndex) const
{
    impObj()->MoveContent(row, col, nFromIndex, nToIndex);
}

void PyAcadTable::deleteContent(int row, int col) const
{
    impObj()->DeleteContent(row, col);
}

PyDbAcValue PyAcadTable::value(int row, int col, int nContent) const
{
    return PyDbAcValue{ impObj()->GetValue(row, col, nContent) };
}

void PyAcadTable::setValue(int row, int col, int nContent, const PyDbAcValue& val) const
{
    impObj()->SetValue(row, col, nContent, *val.impObj());
}

void PyAcadTable::setValueFromText(int row, int col, int nContent, const std::string& val, PyAcParseOption nOption) const
{
    impObj()->SetValueFromText(row, col, nContent, utf8_to_wstr(val).c_str(), nOption);
}

std::string PyAcadTable::dataFormat(int row, int col, int nContent) const
{
    return wstr_to_utf8(impObj()->GetDataFormat(row, col, nContent));
}

void PyAcadTable::setDataFormat(int row, int col, int nContent, const std::string& val) const
{
    impObj()->SetDataFormat(row, col, nContent, utf8_to_wstr(val).c_str());
}

std::string PyAcadTable::textString(int row, int col, int nContent) const
{
    return wstr_to_utf8(impObj()->GetTextString(row, col, nContent));
}

void PyAcadTable::setTextString(int row, int col, int nContent, const std::string& val) const
{
    impObj()->SetTextString(row, col, nContent, utf8_to_wstr(val).c_str());
}

PyDbObjectId PyAcadTable::fieldId2(int row, int col, int nContent) const
{
    return PyDbObjectId{ impObj()->GetFieldId2(row, col, nContent) };
}

void PyAcadTable::setFieldId2(int row, int col, int nContent, const PyDbObjectId& val, PyAcCellOption nflag) const
{
    impObj()->SetFieldId2(row, col, nContent, val.m_id, nflag);
}

PyDbObjectId PyAcadTable::blockTableRecordId2(int row, int col, int nContent) const
{
    return PyDbObjectId{ impObj()->GetBlockTableRecordId2(row, col, nContent) };
}

void PyAcadTable::setBlockTableRecordId2(int row, int col, int nContent, const PyDbObjectId& val, bool autoScale) const
{
    impObj()->SetBlockTableRecordId2(row, col, nContent, val.m_id, autoScale);
}

std::string PyAcadTable::blockAttributeValue2(int row, int col, int nContent, const PyDbObjectId& val) const
{
    return wstr_to_utf8(impObj()->GetBlockAttributeValue2(row, col, nContent, val.m_id));
}

void PyAcadTable::setBlockAttributeValue2(int row, int col, int nContent, const PyDbObjectId& id, const std::string& val) const
{
    impObj()->SetBlockAttributeValue2(row, col, nContent, id.m_id, utf8_to_wstr(val).c_str());
}

PyDbAcValue PyAcadTable::customData(int row, int col, const std::string& key) const
{
    return PyDbAcValue{ impObj()->GetCustomData(row, col,  utf8_to_wstr(key).c_str()) };
}

void PyAcadTable::setCustomData(int row, int col, const std::string& key, const PyDbAcValue& val) const
{
    impObj()->SetCustomData(row, col, utf8_to_wstr(key).c_str(), *val.impObj());
}

std::string PyAcadTable::cellStyle(int row, int col) const
{
    return wstr_to_utf8(impObj()->GetCellStyle(row, col));
}

void PyAcadTable::setCellStyle(int row, int col, const std::string& val) const
{
    impObj()->SetCellStyle(row, col, utf8_to_wstr(val).c_str());
}

PyAcadAcCmColor PyAcadTable::contentColor2(int row, int col, int nContent) const
{
    return PyAcadAcCmColor{ impObj()->GetContentColor2(row, col, nContent) };
}

void PyAcadTable::setContentColor2(int row, int col, int nContent, const PyAcadAcCmColor& val) const
{
    impObj()->SetContentColor2(row, col, nContent, *val.impObj());
}

boost::python::tuple PyAcadTable::dataType2(int row, int col, int nContent) const
{
    return impObj()->GetDataType2(row, col, nContent);
}

void PyAcadTable::setDataType2(int row, int col, int nContent, PyAcValueDataType dataType, PyAcValueUnitType unitType) const
{
    impObj()->SetDataType2(row, col, nContent, dataType, unitType);
}

std::string PyAcadTable::textStyle2(int row, int col, int nContent) const
{
    return wstr_to_utf8(impObj()->GetTextStyle2(row, col, nContent));
}

void PyAcadTable::setTextStyle2(int row, int col, int nContent, const std::string& val) const
{
    impObj()->SetTextStyle2(row, col, nContent, utf8_to_wstr(val).c_str());
}

double PyAcadTable::textHeight2(int row, int col, int nContent) const
{
    return impObj()->GetTextHeight2(row, col, nContent);
}

void PyAcadTable::setTextHeight2(int row, int col, int nContent, double val) const
{
    impObj()->SetTextHeight2(row, col, nContent, val);
}

double PyAcadTable::rotation(int row, int col, int nContent) const
{
    return impObj()->GetRotation(row, col, nContent);
}

void PyAcadTable::setRotation(int row, int col, int nContent, double val) const
{
    impObj()->SetRotation(row, col, nContent, val);
}

bool PyAcadTable::autoScale2(int row, int col, int nContent) const
{
    return impObj()->GetAutoScale2(row, col, nContent);
}

void PyAcadTable::setAutoScale2(int row, int col, int nContent, bool val) const
{
    impObj()->SetAutoScale2(row, col, nContent, val);
}

double PyAcadTable::scale(int row, int col, int nContent) const
{
    return impObj()->GetScale(row, col, nContent);
}

void PyAcadTable::setScale(int row, int col, int nContent, double val) const
{
    impObj()->SetScale(row, col, nContent, val);
}

void PyAcadTable::removeAllOverrides(int row, int col) const
{
    impObj()->RemoveAllOverrides(row, col);
}

PyAcLineWeight PyAcadTable::gridLineWeight2(int row, int col, PyAcGridLineType lt) const
{
    return impObj()->GetGridLineWeight2(row, col, lt);
}

void PyAcadTable::setGridLineWeight2(int row, int col, PyAcGridLineType lt, PyAcLineWeight lw) const
{
    impObj()->SetGridLineWeight2(row, col, lt, lw);
}

PyDbObjectId PyAcadTable::gridLinetype(int row, int col, PyAcGridLineType lt) const
{
    return PyDbObjectId{ impObj()->GetGridLinetype(row, col, lt) };
}

void PyAcadTable::setGridLinetype(int row, int col, PyAcGridLineType lt, const PyDbObjectId& val) const
{
    impObj()->SetGridLinetype(row, col, lt, val.m_id);
}

PyAcadAcCmColor PyAcadTable::gridColor2(int row, int col, PyAcGridLineType lt) const
{
    return PyAcadAcCmColor{ impObj()->GetGridColor2(row, col, lt) };
}

void PyAcadTable::setGridColor2(int row, int col, PyAcGridLineType lt, const PyAcadAcCmColor& val) const
{
    impObj()->SetGridColor2(row, col, lt, *val.impObj());
}

bool PyAcadTable::gridVisibility2(int row, int col, PyAcGridLineType lt) const
{
    return impObj()->GetGridVisibility2(row, col, lt);
}

void PyAcadTable::setGridVisibility2(int row, int col, PyAcGridLineType lt, bool val) const
{
    impObj()->SetGridVisibility2(row, col, lt, val);
}

double PyAcadTable::gridDoubleLineSpacing(int row, int col, PyAcGridLineType lt) const
{
    return impObj()->GetGridDoubleLineSpacing(row, col, lt);
}

void PyAcadTable::setGridDoubleLineSpacing(int row, int col, PyAcGridLineType lt, double val) const
{
    impObj()->SetGridDoubleLineSpacing(row, col, lt, val);
}

void PyAcadTable::setEnableBreak(bool val) const
{
    impObj()->SetEnableBreak(val);
}

double PyAcadTable::breakHeight(int nIndex) const
{
    return impObj()->GetBreakHeight(nIndex);
}

void PyAcadTable::setBreakHeight(int nIndex, double val) const
{
    impObj()->SetBreakHeight(nIndex, val);
}

PyAcCellContentType PyAcadTable::contentType(int row, int col) const
{
    return impObj()->GetContentType(row, col);
}

double PyAcadTable::margin(int row, int col, PyAcCellMargin margin) const
{
    return impObj()->GetMargin(row, col, margin);
}

void PyAcadTable::setMargin(int row, int col, PyAcCellMargin margin, double val) const
{
    impObj()->SetMargin(row, col, margin, val);
}

PyAcCellContentLayout PyAcadTable::contentLayout(int row, int col) const
{
    return impObj()->GetContentLayout(row, col);
}

void PyAcadTable::setContentLayout(int row, int col, PyAcCellContentLayout val) const
{
    impObj()->SetContentLayout(row, col, val);
}

PyAcCellProperty PyAcadTable::_override(int row, int col, int nContent) const
{
    return impObj()->GetOverride(row, col, nContent);
}

void PyAcadTable::setOverride(int row, int col, int nContent, PyAcCellProperty val) const
{
    impObj()->SetOverride(row, col, nContent, val);
}

PyAcGridLineStyle PyAcadTable::gridLineStyle(int row, int col, PyAcGridLineType lt) const
{
    return impObj()->GetGridLineStyle(row, col, lt);
}

void PyAcadTable::setGridLineStyle(int row, int col, PyAcGridLineType lt, PyAcGridLineStyle val) const
{
    impObj()->SetGridLineStyle(row, col, lt, val);
}

void PyAcadTable::insertRowsAndInherit(int nIndex, int nInheritFrom, int nNumRows) const
{
    impObj()->InsertRowsAndInherit(nIndex, nInheritFrom, nNumRows);
}

void PyAcadTable::insertColumnsAndInherit(int nIndex, int nInheritFrom, int nNumCols) const
{
    impObj()->InsertColumnsAndInherit(nIndex, nInheritFrom, nNumCols);
}

bool PyAcadTable::hasFormula(int row, int col, int nContent) const
{
    return impObj()->GetHasFormula(row, col, nContent);
}

std::string PyAcadTable::formula(int row, int col, int nContent) const
{
    return wstr_to_utf8(impObj()->GetFormula(row, col, nContent));
}

void PyAcadTable::setFormula(int row, int col, int nContent, const std::string& val) const
{
    impObj()->SetFormula(row, col, nContent, utf8_to_wstr(val).c_str());
}

bool PyAcadTable::isContentEditable(int row, int col) const
{
    return impObj()->IsContentEditable(row, col);
}

bool PyAcadTable::isFormatEditable(int row, int col) const
{
    return impObj()->IsFormatEditable(row, col);
}

PyAcCellState PyAcadTable::cellState(int row, int col) const
{
    return impObj()->GetCellState(row, col);
}

void PyAcadTable::setCellState(int row, int col, PyAcCellState val) const
{
    impObj()->SetCellState(row, col, val);
}

void PyAcadTable::enableMergeAll(int row, int col, bool val) const
{
    impObj()->EnableMergeAll(row, col, val);
}

bool PyAcadTable::isMergeAllEnabled(int row, int col) const
{
    return impObj()->IsMergeAllEnabled(row, col);
}

bool PyAcadTable::breaksEnabled() const
{
    return impObj()->GetBreaksEnabled();
}

void PyAcadTable::setBreaksEnabled(bool val) const
{
    impObj()->SetBreaksEnabled(val);
}

bool PyAcadTable::repeatTopLabels() const
{
    return impObj()->GetRepeatTopLabels();
}

void PyAcadTable::setRepeatTopLabels(bool val) const
{
    impObj()->SetRepeatTopLabels(val);
}

bool PyAcadTable::repeatBottomLabels() const
{
    return impObj()->GetRepeatBottomLabels();
}

void PyAcadTable::setRepeatBottomLabels(bool val) const
{
    impObj()->SetRepeatBottomLabels(val);
}

PyAcTableFlowDirection PyAcadTable::tableBreakFlowDirection() const
{
    return impObj()->GetTableBreakFlowDirection();
}

void PyAcadTable::setTableBreakFlowDirection(PyAcTableFlowDirection val) const
{
    impObj()->SetTableBreakFlowDirection(val);
}

bool PyAcadTable::allowManualPositions() const
{
    return impObj()->GetAllowManualPositions();
}

void PyAcadTable::setAllowManualPositions(bool val) const
{
    impObj()->SetAllowManualPositions(val);
}

bool PyAcadTable::allowManualHeights() const
{
    return impObj()->GetAllowManualHeights();
}

void PyAcadTable::setAllowManualHeights(bool val) const
{
    impObj()->SetAllowManualHeights(val);
}

double PyAcadTable::tableBreakHeight() const
{
    return impObj()->GetTableBreakHeight();
}

void PyAcadTable::setTableBreakHeight(double val) const
{
    impObj()->SetTableBreakHeight(val);
}

double PyAcadTable::breakSpacing() const
{
    return impObj()->GetBreakSpacing();
}

void PyAcadTable::setBreakSpacing(double val) const
{
    impObj()->SetBreakSpacing(val);
}

std::string PyAcadTable::columnName(int col) const
{
    return  wstr_to_utf8(impObj()->GetColumnName(col));
}

void PyAcadTable::setColumnName(int col, const std::string& val) const
{
    impObj()->SetColumnName(col, utf8_to_wstr(val).c_str());
}

void PyAcadTable::setToolTip(int row, int col, const std::string& val) const
{
    impObj()->SetToolTip(row, col, utf8_to_wstr(val).c_str());
}

PyAcadTable PyAcadTable::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadTable>(src);
}

std::string PyAcadTable::className()
{
    return "AcadTable";
}

PyIAcadTableImpl* PyAcadTable::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadTableImpl*>(m_pyImp.get());
}