#include "stdafx.h"
#include "PyAcadTable.h"
#include "PyAcadTableImpl.h"
#include "PyAcadEntityImpl.h"
#include "PyAcadObject.h"
#include "PyAcadObjectImpl.h"

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