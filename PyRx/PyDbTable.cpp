#include "stdafx.h"
#include "PyDbTable.h"
#include "PyDbObjectId.h"
using namespace boost::python;

//-----------------------------------------------------------------------------------
// AcCell helpers
static boost::shared_ptr<AcCell> AcCellInit1()
{
    return boost::shared_ptr<AcCell>(new AcCell{ -1 , -1 });
}

static boost::shared_ptr<AcCell> AcCellInit2(int r, int c)
{
    return boost::shared_ptr<AcCell>(new AcCell{ r, c });
}

static std::string AcCellToString(const AcCell& cell)
{
    return std::format("({},{})", cell.mnRow, cell.mnColumn);
}

static bool AcCellEquals(const AcCell& cell, const AcCell& other)
{
    return cell.mnRow == other.mnRow && cell.mnColumn == other.mnColumn;
}

static bool AcCellNotEquals(const AcCell& cell, const AcCell& other)
{
    return !AcCellEquals(cell, other);
}

int AcCellGetItem(const AcCell& cell, int idx)
{
    switch (idx)
    {
    case 0:
        return cell.mnRow;
    case 1:
        return cell.mnColumn;
    default:
        throw PyAcadErrorStatus(eOutOfRange);
    }
}

void AcCellSetItem(AcCell& cell, int idx, int val)
{
    switch (idx)
    {
    case 0:
        cell.mnRow = val;
        break;
    case 1:
        cell.mnColumn = val;
        break;
    default:
        throw PyAcadErrorStatus(eOutOfRange);
    }
}

//-----------------------------------------------------------------------------------
//  AcCellRange helpers
static boost::shared_ptr<AcCellRange> AcCellRangeInit1()
{
#ifdef _ARXTARGET
    return boost::shared_ptr<AcCellRange>(new AcCellRange{ -1 , -1, -1, -1 });
#endif

#if _BRXTARGET == 240
    return boost::shared_ptr<AcCellRange>(new AcCellRange{ -1 , -1, -1, -1 });
#endif

#if _GRXTARGET == 240
    return boost::shared_ptr<AcCellRange>(new AcCellRange{ -1 , -1, -1, -1 });
#endif

#if _ZRXTARGET == 240
    return boost::shared_ptr<AcCellRange>(new AcCellRange());
#endif
}

static boost::shared_ptr<AcCellRange> AcCellRangeInit2(int tr, int lc, int br, int rc)
{
#ifdef _ARXTARGET
    return boost::shared_ptr<AcCellRange>(new AcCellRange{ tr , lc, br, rc });
#endif

#if _BRXTARGET == 240
    return boost::shared_ptr<AcCellRange>(new AcCellRange{ tr , lc, br, rc });
#endif

#if _GRXTARGET == 240
    return boost::shared_ptr<AcCellRange>(new AcCellRange{ tr , lc, br, rc });
#endif

#if _ZRXTARGET == 240
    AcCellRange range;
    range.mnTopRow = tr;
    range.mnLeftColumn = lc;
    range.mnBottomRow = br;
    range.mnRightColumn = rc;
    return boost::shared_ptr<AcCellRange>(new AcCellRange(range));
#endif
}

static std::string AcCellRangeToString(const AcCellRange& range)
{
    return std::format("({},{},{},{})", range.mnTopRow, range.mnLeftColumn, range.mnBottomRow, range.mnRightColumn);
}

static bool AcCellRangeEquals(const AcCellRange& range, const AcCellRange& other)
{
    return  range.mnTopRow == other.mnTopRow &&
        range.mnLeftColumn == other.mnLeftColumn &&
        range.mnBottomRow == other.mnBottomRow &&
        range.mnRightColumn == other.mnRightColumn;
}

static bool AcCellRangeNotEquals(const AcCellRange& range, const AcCellRange& other)
{
    return !AcCellRangeEquals(range, other);
}

int AcCellRangeGetItem(const AcCellRange& range, int idx)
{
    switch (idx)
    {
    case 0:
        return range.mnTopRow;
    case 1:
        return range.mnLeftColumn;
    case 2:
        return range.mnBottomRow;
    case 3:
        return range.mnRightColumn;
    default:
        throw PyAcadErrorStatus(eOutOfRange);
    }
}

void AcCellRangeSetItem(AcCellRange& range, int idx, int val)
{
    switch (idx)
    {
    case 0:
        range.mnTopRow = val;
        break;
    case 1:
        range.mnLeftColumn = val;
        break;
    case 2:
        range.mnBottomRow = val;
        break;
    case 3:
        range.mnRightColumn = val;
        break;
    default:
        throw PyAcadErrorStatus(eOutOfRange);
    }
}


//-----------------------------------------------------------------------------------
//PyDbTable
void makePyDbTableWrapper()
{
    PyDocString DS("Table");
    class_<PyDbTable, bases<PyDbBlockReference>>("Table")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("tableStyle", &PyDbTable::tableStyle, DS.ARGS())
        .def("setTableStyle", &PyDbTable::setTableStyle, DS.ARGS({ "val : PyDb.ObjectId" }))
        .def("direction", &PyDbTable::direction, DS.ARGS())
        .def("setDirection", &PyDbTable::setDirection, DS.ARGS({ "val : PyGe.Vector3d" }))
        .def("numRows", &PyDbTable::numRows, DS.ARGS())
        .def("numColumns", &PyDbTable::numColumns, DS.ARGS())
        .def("width", &PyDbTable::width, DS.ARGS())
        .def("setWidth", &PyDbTable::setWidth, DS.ARGS({ "val : float" }))
        .def("columnWidth", &PyDbTable::columnWidth, DS.ARGS({ "col : int" }))
        .def("setColumnWidth", &PyDbTable::setColumnWidth1)
        .def("setColumnWidth", &PyDbTable::setColumnWidth2)
        .def("height", &PyDbTable::height)
        .def("setHeight", &PyDbTable::setHeight, DS.ARGS({ "val : float" }))
        .def("rowHeight", &PyDbTable::rowHeight, DS.ARGS({ "row : int" }))
        .def("setRowHeight", &PyDbTable::setRowHeight1)
        .def("setRowHeight", &PyDbTable::setRowHeight2)
        .def("minimumColumnWidth", &PyDbTable::minimumColumnWidth, DS.ARGS({ "col: int" }))
        .def("minimumRowHeight", &PyDbTable::minimumRowHeight, DS.ARGS({ "row: int" }))
        .def("minimumTableWidth", &PyDbTable::minimumTableWidth, DS.ARGS())
        .def("minimumTableHeight", &PyDbTable::minimumTableHeight, DS.ARGS())
        .def("horzCellMargin", &PyDbTable::horzCellMargin, DS.ARGS())
        .def("setHorzCellMargin", &PyDbTable::setHorzCellMargin, DS.ARGS({ "val : float" }))
        .def("vertCellMargin", &PyDbTable::vertCellMargin, DS.ARGS())
        .def("setVertCellMargin", &PyDbTable::setVertCellMargin, DS.ARGS({ "val : float" }))
        .def("flowDirection", &PyDbTable::flowDirection, DS.ARGS())
        .def("setFlowDirection", &PyDbTable::setFlowDirection, DS.ARGS({ "val : PyDb.TableFlowDirection" }))
        .def("isTitleSuppressed", &PyDbTable::isTitleSuppressed, DS.ARGS())
        .def("suppressTitleRow", &PyDbTable::suppressTitleRow, DS.ARGS({ "val : bool" }))
        .def("isHeaderSuppressed", &PyDbTable::isHeaderSuppressed, DS.ARGS())
        .def("suppressHeaderRow", &PyDbTable::suppressHeaderRow, DS.ARGS({ "val : bool" }))
        .def("alignment", &PyDbTable::alignment)
        .def("setAlignment", &PyDbTable::setAlignment)
        .def("isBackgroundColorNone", &PyDbTable::isBackgroundColorNone)
        .def("setBackgroundColorNone", &PyDbTable::setBackgroundColorNone)
        .def("backgroundColor", &PyDbTable::backgroundColor)
        .def("backgroundColor", &PyDbTable::backgroundColor2)
        .def("setBackgroundColor", &PyDbTable::setBackgroundColor)
        .def("setBackgroundColor", &PyDbTable::setBackgroundColor2)
        .def("contentColor", &PyDbTable::contentColor)
        .def("setContentColor", &PyDbTable::setContentColor)
        .def("getDataType", &PyDbTable::getDataType)
        .def("setDataType", &PyDbTable::setDataType1)
        .def("setDataType", &PyDbTable::setDataType2)
        .def("textStyle", &PyDbTable::textStyle)
        .def("setTextStyle", &PyDbTable::setTextStyle)
        .def("textHeight", &PyDbTable::textHeight)
        .def("setTextHeight", &PyDbTable::setTextHeight)
        .def("gridLineWeight", &PyDbTable::gridLineWeight)
        .def("setGridLineWeight", &PyDbTable::setGridLineWeight)
        .def("gridColor", &PyDbTable::gridColor)
        .def("setGridColor", &PyDbTable::setGridColor)
        .def("gridVisibility", &PyDbTable::gridVisibility)
        .def("setGridVisibility", &PyDbTable::setGridVisibility)
        .def("tableStyleOverrides", &PyDbTable::tableStyleOverrides)
        .def("clearTableStyleOverrides", &PyDbTable::clearTableStyleOverrides)
        .def("cellType", &PyDbTable::cellType)
        .def("setCellType", &PyDbTable::setCellType)
        .def("getCellExtents", &PyDbTable::getCellExtents)
        .def("attachmentPoint", &PyDbTable::attachmentPoint)
        .def("alignment", &PyDbTable::alignment2)
        .def("setAlignment", &PyDbTable::setAlignment2)
        .def("isBackgroundColorNone", &PyDbTable::isBackgroundColorNone2)
        .def("setBackgroundColorNone", &PyDbTable::setBackgroundColorNone2)
        .def("contentColor", &PyDbTable::contentColor2)
        .def("setContentColor", &PyDbTable::setContentColor2)
        .def("cellStyleOverrides", &PyDbTable::cellStyleOverrides)
        .def("clearCellOverrides", &PyDbTable::clearCellOverrides)
        .def("deleteCellContent", &PyDbTable::deleteCellContent)
        .def("rowType", &PyDbTable::rowType)
        .def("getDataType", &PyDbTable::getDataType2)
        .def("setDataType", &PyDbTable::setDataType3)
        .def("setFormat", &PyDbTable::setFormat, DS.ARGS({ "row: int", "col: int", "format : str"}))
        .def("textString", &PyDbTable::textString)
        .def("textString", &PyDbTable::textString3)
        .def("textStringFmt", &PyDbTable::textStringFmt1)
        .def("textStringFmt", &PyDbTable::textStringFmt3)
        .def("setTextString", &PyDbTable::setTextString)
        .def("setTextString", &PyDbTable::setTextString3)
        .def("fieldId", &PyDbTable::fieldId)
        .def("setFieldId", &PyDbTable::setFieldId)
        .def("textStyle", &PyDbTable::textStyle2)
        .def("setTextStyle", &PyDbTable::setTextStyle2)
        .def("textHeight", &PyDbTable::textHeight2)
        .def("setTextHeight", &PyDbTable::setTextHeight2)
        .def("textRotation", &PyDbTable::textRotation)
        .def("setTextRotation", &PyDbTable::setTextRotation)
        .def("isAutoScale", &PyDbTable::isAutoScale)
        .def("setAutoScale", &PyDbTable::setAutoScale)
        .def("blockTableRecordId", &PyDbTable::blockTableRecordId)
        .def("setBlockTableRecordId", &PyDbTable::setBlockTableRecordId)
        .def("blockScale", &PyDbTable::blockScale, DS.ARGS({ "row: int", "col: int" }))
        .def("setBlockScale", &PyDbTable::setBlockScale, DS.ARGS({ "row: int", "col: int","scale : float" }))
        .def("blockRotation", &PyDbTable::blockRotation, DS.ARGS({ "row: int", "col: int" }))
        .def("setBlockRotation", &PyDbTable::setBlockRotation, DS.ARGS({ "row: int", "col: int","rotAng : float" }))
        .def("gridEdgeColor", &PyDbTable::gridEdgeColor)
        .def("setGridEdgeColor", &PyDbTable::setGridEdgeColor)
        .def("gridEdgeVisibility", &PyDbTable::gridEdgeVisibility)
        .def("setGridEdgeVisibility", &PyDbTable::setGridEdgeVisibility)
        .def("gridEdgeLineWeight", &PyDbTable::gridEdgeLineWeight)
        .def("setGridEdgeLineWeight", &PyDbTable::setGridEdgeLineWeight)
        .def("insertColumns", &PyDbTable::insertColumns, DS.ARGS({ "row: int","width : float", "nCols: int" }))
        .def("deleteColumns", &PyDbTable::deleteColumns, DS.ARGS({ "row: int", "nCols: int" }))
        .def("insertRows", &PyDbTable::insertRows, DS.ARGS({ "row: int","height : float", "nRows: int" }))
        .def("deleteRows", &PyDbTable::deleteRows, DS.ARGS({ "row: int", "nRows: int" }))
        .def("mergeCells", &PyDbTable::mergeCells, DS.ARGS({ "minRow: int", "maxRow: int","minCol: int", "maxCol: int" }))
        .def("unmergeCells", &PyDbTable::unmergeCells, DS.ARGS({ "minRow: int", "maxRow: int","minCol: int", "maxCol: int" }))
        .def("isMergedCell", &PyDbTable::isMergedCell, DS.ARGS({ "row: int", "col: int" }))
        .def("generateLayout", &PyDbTable::generateLayout, DS.ARGS())
        .def("recomputeTableBlock", &PyDbTable::recomputeTableBlock, DS.ARGS({ "val : bool" }))
        .def("hitTest", &PyDbTable::hitTest)
        .def("hitTest", &PyDbTable::hitTest2, DS.ARGS({ "wpt: PyGe.Point3d","viewvec: PyGe.Vector3d","wx: float=0.0","wy: float=0.0" }))
        .def("getSubSelection", &PyDbTable::getSubSelection, DS.ARGS())
        .def("setSubSelection", &PyDbTable::setSubSelection, DS.ARGS({ "val : PyDb.CellRange" }))
        .def("clearSubSelection", &PyDbTable::clearSubSelection, DS.ARGS())
        .def("hasSubSelection", &PyDbTable::hasSubSelection, DS.ARGS())
        .def("setPosition", &PyDbTable::setPosition, DS.ARGS({ "val : PyGe.Point3d" }))
        .def("setNormal", &PyDbTable::setNormal, DS.ARGS({ "val : PyGe.Vector3d" }))
        .def("setRegen", &PyDbTable::setRegen, DS.ARGS())
        .def("suppressInvisibleGrid", &PyDbTable::suppressInvisibleGrid, DS.ARGS({ "val : bool" }))
        .def("isRegenerateTableSuppressed", &PyDbTable::isRegenerateTableSuppressed, DS.ARGS())
        .def("suppressRegenerateTable", &PyDbTable::suppressRegenerateTable, DS.ARGS({ "val : bool" }))
        .def("setRecomputeTableBlock", &PyDbTable::setRecomputeTableBlock, DS.ARGS({ "val : bool" }))
        .def("setSize", &PyDbTable::setSize, DS.ARGS({ "rows: int", "cols: int" }))
        .def("canInsert", &PyDbTable::canInsert, DS.ARGS({ "index: int", "brow: bool" }))
        .def("insertRowsAndInherit", &PyDbTable::insertRowsAndInherit, DS.ARGS({ "nIndex: int", "nInheritFrom: int", "nNumRows: int" }))
        .def("insertColumnsAndInherit", &PyDbTable::insertColumnsAndInherit, DS.ARGS({ "nIndex: int", "nInheritFrom: int", "nNumCols: int" }))
        .def("canDelete", &PyDbTable::canDelete, DS.ARGS({ "row: int", "col: int", "brow : bool" }))
        .def("isEmpty", &PyDbTable::isEmpty, DS.ARGS({ "row: int", "col: int" }))
        .def("getMergeRange", &PyDbTable::getMergeRange, DS.ARGS({ "row: int", "col: int" }))
        .def("isContentEditable", &PyDbTable::isContentEditable, DS.ARGS({ "row: int", "col: int" }))
        .def("isFormatEditable", &PyDbTable::isFormatEditable, DS.ARGS({ "row: int", "col: int" }))
        .def("cellState", &PyDbTable::cellState, DS.ARGS({ "row: int", "col: int" }))
        .def("setCellState", &PyDbTable::setCellState, DS.ARGS({ "row: int", "col: int","val : PyDb.CellState" }))
        .def("numContents", &PyDbTable::numContents, DS.ARGS({ "row: int", "col: int" }))
        .def("createContent", &PyDbTable::createContent, DS.ARGS({ "row: int", "col: int", "idx: int" }))
        .def("moveContent", &PyDbTable::moveContent, DS.ARGS({ "row: int", "col: int", "frm: int","to: int" }))
        .def("deleteContent", &PyDbTable::deleteContent1)
        .def("deleteContent", &PyDbTable::deleteContent2)
        .def("deleteContent", &PyDbTable::deleteContent3)
        .def("contentType", &PyDbTable::contentType1)
        .def("contentType", &PyDbTable::contentType2)
        .def("dataFormat", &PyDbTable::dataFormat1)
        .def("dataFormat", &PyDbTable::dataFormat2)
        .def("setDataFormat", &PyDbTable::setDataFormat1)
        .def("setDataFormat", &PyDbTable::setDataFormat2)
        .def("textString", &PyDbTable::textString2)
        .def("textStringFmt", &PyDbTable::textStringFmt2)
        .def("setTextString", &PyDbTable::setTextString2)
        .def("hasFormula", &PyDbTable::hasFormula, DS.ARGS({ "row: int", "col: int", "content: int" }))
        .def("getFormula", &PyDbTable::getFormula, DS.ARGS({ "row: int", "col: int", "content: int" }))
        .def("setFormula", &PyDbTable::setFormula, DS.ARGS({ "row: int", "col: int", "content: int", "val: str" }))
        .def("fieldId", &PyDbTable::fieldId2)
        .def("setFieldId", &PyDbTable::setFieldId2)
        .def("blockTableRecordId", &PyDbTable::blockTableRecordId2)
        .def("setBlockTableRecordId", &PyDbTable::setBlockTableRecordId2)
        .def("getBlockAttributeValue", &PyDbTable::getBlockAttributeValue1)
        .def("getBlockAttributeValue", &PyDbTable::getBlockAttributeValue2)
        .def("setBlockAttributeValue", &PyDbTable::setBlockAttributeValue1)
        .def("setBlockAttributeValue", &PyDbTable::setBlockAttributeValue2)
        .def("cellStyle", &PyDbTable::cellStyle, DS.ARGS({ "row: int", "col: int" }))
        .def("setCellStyle", &PyDbTable::setCellStyle, DS.ARGS({ "row: int", "col: int", "style: str" }))
        .def("margin", &PyDbTable::margin, DS.ARGS({ "row: int", "col: int", "nMargin: PyDb.CellMargin" }))
        .def("setMargin", &PyDbTable::setMargin, DS.ARGS({ "row: int", "col: int", "nMargin: PyDb.CellMargin","val : float" }))
        .def("attachmentPoint", &PyDbTable::attachmentPoint2)
        .def("contentColor", &PyDbTable::contentColor3)
        .def("setContentColor", &PyDbTable::setContentColor3)
        .def("getDataType", &PyDbTable::getDataType3)
        .def("setDataType", &PyDbTable::setDataType4)
        .def("textStyle", &PyDbTable::textStyle3)
        .def("setTextStyle", &PyDbTable::setTextStyle3)
        .def("textHeight", &PyDbTable::textHeight3)
        .def("setTextHeight", &PyDbTable::setTextHeight3)
        .def("rotation", &PyDbTable::rotation)
        .def("rotation", &PyDbTable::rotation2)
        .def("setRotation", &PyDbTable::setRotation)
        .def("setRotation", &PyDbTable::setRotation2)
        .def("isAutoScale", &PyDbTable::isAutoScale2)
        .def("setAutoScale", &PyDbTable::setAutoScale2)
        .def("scale", &PyDbTable::scale, DS.ARGS({ "row: int", "col: int", "content: int" }))
        .def("setScale", &PyDbTable::setScale, DS.ARGS({ "row: int", "col: int", "content: int","val : float" }))
        .def("contentLayout", &PyDbTable::contentLayout, DS.ARGS({ "row: int", "col: int" }))
        .def("setContentLayout", &PyDbTable::setContentLayout, DS.ARGS({ "row: int", "col: int" , "val: PyDb.CellContentLayout" }))
        .def("isMergeAllEnabled", &PyDbTable::isMergeAllEnabled, DS.ARGS({ "row: int", "col: int" }))
        .def("enableMergeAll", &PyDbTable::enableMergeAll, DS.ARGS({ "row: int", "col: int","val : bool" }))
        .def("getCellOverride", &PyDbTable::getCellOverride, DS.ARGS({ "row: int", "col: int", "content: int" }))
        .def("getGridOverride", &PyDbTable::getGridOverride, DS.ARGS({ "row: int", "col: int", "nGridLineType: PyDb.GridLineType" }))
        .def("setCellOverride", &PyDbTable::setCellOverride, DS.ARGS({ "row: int", "col: int", "content: int", "nOverride: PyDb.CellProperty" }))
        .def("setGridOverride", &PyDbTable::setGridOverride, DS.ARGS({ "row: int", "col: int", "nGridLineType: PyDb.GridLineType","nOverride: PyDb.GridProperty" }))
        .def("removeAllOverrides", &PyDbTable::removeAllOverrides, DS.ARGS({ "row: int", "col: int" }))
        .def("gridLineStyle", &PyDbTable::gridLineStyle, DS.ARGS({ "row: int", "col: int", "nGridLineType: PyDb.GridLineType" }))
        .def("setGridLineStyle", &PyDbTable::setGridLineStyle, DS.ARGS({ "row: int", "col: int", "nGridLineType: PyDb.GridLineTypes","nLineStyle: PyDb.GridLineStyle" }))
        .def("gridLineWeight", &PyDbTable::gridLineWeight2)
        .def("setGridLineWeight", &PyDbTable::setGridLineWeight2)
        .def("gridLinetype", &PyDbTable::gridLinetype, DS.ARGS({ "row: int", "col: int", "nGridLineType: PyDb.GridLineType" }))
        .def("setGridLinetype", &PyDbTable::setGridLinetype, DS.ARGS({ "row: int", "col: int", "nGridLineType: PyDb.GridLineTypes","idLinetype: PyDb.ObjectId" }))
        .def("gridColor", &PyDbTable::gridColor2)
        .def("setGridColor", &PyDbTable::setGridColor2)
        .def("gridVisibility", &PyDbTable::gridVisibility2)
        .def("setGridVisibility3", &PyDbTable::setGridVisibility2)
        .def("gridDoubleLineSpacing", &PyDbTable::gridDoubleLineSpacing)
        .def("setGridDoubleLineSpacing", &PyDbTable::setGridDoubleLineSpacing)
        .def("getGridProperty", &PyDbTable::getGridProperty)
        .def("setGridProperty", &PyDbTable::setGridProperty1)
        .def("setGridProperty", &PyDbTable::setGridProperty2)
        .def("isLinked", &PyDbTable::isLinked, DS.ARGS({ "row: int", "col: int" }))
        .def("getDataLink", &PyDbTable::getDataLink, DS.ARGS({ "row: int", "col: int" }))
        .def("setDataLink", &PyDbTable::setDataLink, DS.ARGS({ "row: int", "col: int","id : PyDb.ObjectId","update : bool" }))
        .def("getDataLinkRange", &PyDbTable::getDataLinkRange, DS.ARGS({ "row: int", "col: int" }))
        .def("removeDataLink", &PyDbTable::removeDataLink1)
        .def("removeDataLink", &PyDbTable::removeDataLink2)
        .def("updateDataLink", &PyDbTable::updateDataLink1)
        .def("updateDataLink", &PyDbTable::updateDataLink2)
        .def("isBreakEnabled", &PyDbTable::isBreakEnabled, DS.ARGS())
        .def("enableBreak", &PyDbTable::enableBreak, DS.ARGS({ "val : bool" }))
        .def("breakFlowDirection", &PyDbTable::breakFlowDirection)
        .def("setBreakFlowDirection", &PyDbTable::setBreakFlowDirection)
        .def("breakHeight", &PyDbTable::breakHeight, DS.ARGS({ "val : int" }))
        .def("setBreakHeight", &PyDbTable::setBreakHeight, DS.ARGS({ "val : int","height : float" }))
        .def("breakOffset", &PyDbTable::breakOffset)
        .def("setBreakOffset", &PyDbTable::setBreakOffset)
        .def("breakOption", &PyDbTable::breakOption, DS.ARGS())
        .def("setBreakOption", &PyDbTable::setBreakOption)
        .def("breakSpacing", &PyDbTable::breakSpacing, DS.ARGS())
        .def("setBreakSpacing", &PyDbTable::setBreakSpacing, DS.ARGS({ "val : float" }))
        .def("cellRange", &PyDbTable::cellRange, DS.ARGS())
        .def("getIterator", &PyDbTable::getIterator1)
        .def("getIterator", &PyDbTable::getIterator2)
        .def("getIterator", &PyDbTable::getIterator3)
        .def("getIterator", &PyDbTable::getIterator4)
        .def("className", &PyDbTable::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbTable::desc, DS.SARGS()).staticmethod("desc")
        .def("cloneFrom", &PyDbTable::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbTable::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
    PyDocString DSCELL("Cell");
    class_ <AcCell>("Cell")
        .def_readwrite("row", &AcCell::mnRow)
        .def_readwrite("column", &AcCell::mnColumn)
        .def("__str__", &AcCellToString)
        .def("__repr__", &AcCellToString)
        .def("__getitem__", &AcCellGetItem)
        .def("__setitem__", &AcCellSetItem)
        .def("__eq__", &AcCellEquals)
        .def("__ne__", &AcCellNotEquals)
        .def("__init__", make_constructor(&AcCellInit1))
        .def("__init__", make_constructor(&AcCellInit2), DSCELL.ARGS({ "row : int=-1","column : int=-1" }))
        ;
    PyDocString DSCR("CellRange");
    class_ <AcCellRange>("CellRange")
        .def_readwrite("topRow", &AcCellRange::mnTopRow)
        .def_readwrite("leftColumn", &AcCellRange::mnLeftColumn)
        .def_readwrite("bottomRow", &AcCellRange::mnBottomRow)
        .def_readwrite("rightColumn", &AcCellRange::mnRightColumn)
        .def("__str__", &AcCellRangeToString)
        .def("__repr__", &AcCellRangeToString)
        .def("__getitem__", &AcCellRangeGetItem)
        .def("__setitem__", &AcCellRangeSetItem)
        .def("__eq__", &AcCellRangeEquals)
        .def("__ne__", &AcCellRangeNotEquals)
        .def("__init__", make_constructor(&AcCellRangeInit1))
        .def("__init__", make_constructor(&AcCellRangeInit2), DSCR.ARGS({ "topRow : int=-1","leftColumn : int=-1","bottomRow : int=-1","rightColumn : int=-1" }))
        ;
    enum_<AcDb::FlowDirection>("TableFlowDirection")
        .value("kTtoB", AcDb::FlowDirection::kTtoB)
        .value("kExactly", AcDb::FlowDirection::kBtoT)
        .export_values()
        ;
    enum_<AcDb::CellAlignment>("CellAlignment")
        .value("kTopLeft", AcDb::CellAlignment::kTopLeft)
        .value("kTopCenter", AcDb::CellAlignment::kTopCenter)
        .value("kTopRight", AcDb::CellAlignment::kTopRight)
        .value("kMiddleLeft", AcDb::CellAlignment::kMiddleLeft)
        .value("kMiddleCenter", AcDb::CellAlignment::kMiddleCenter)
        .value("kMiddleRight", AcDb::CellAlignment::kMiddleRight)
        .value("kBottomLeft", AcDb::CellAlignment::kBottomLeft)
        .value("kBottomCenter", AcDb::CellAlignment::kBottomCenter)
        .value("kBottomRight", AcDb::CellAlignment::kBottomRight)
        .export_values()
        ;
    enum_<AcDb::RowType>("RowType")
        .value("kUnknownRow", AcDb::RowType::kUnknownRow)
        .value("kDataRow", AcDb::RowType::kDataRow)
        .value("kTitleRow", AcDb::RowType::kTitleRow)
        .value("kHeaderRow", AcDb::RowType::kHeaderRow)
#if !defined(_BRXTARGET240)
        .value("kAllRowTypes", AcDb::RowType::kAllRowTypes)
#endif
        .export_values()
        ;
    enum_<AcDb::TableHitItem>("TableHitItem")
        .value("kTableHitNone", AcDb::TableHitItem::kTableHitNone)
        .value("kTableHitCell", AcDb::TableHitItem::kTableHitCell)
        .value("kTableHitRowIndicator", AcDb::TableHitItem::kTableHitRowIndicator)
        .value("kTableHitColumnIndicator", AcDb::TableHitItem::kTableHitColumnIndicator)
        .value("kTableHitGridLine", AcDb::TableHitItem::kTableHitGridLine)
        .export_values()
        ;
    enum_<AcDb::MergeCellStyleOption>("MergeCellStyleOption")
        .value("kMergeCellStyleNone", AcDb::MergeCellStyleOption::kMergeCellStyleNone)
        .value("kMergeCellStyleCopyDuplicates", AcDb::MergeCellStyleOption::kMergeCellStyleCopyDuplicates)
        .value("kMergeCellStyleOverwriteDuplicates", AcDb::MergeCellStyleOption::kMergeCellStyleOverwriteDuplicates)
        .value("kMergeCellStyleConvertDuplicatesToOverrides", AcDb::MergeCellStyleOption::kMergeCellStyleConvertDuplicatesToOverrides)
        .value("kMergeCellStyleIgnoreNewStyles", AcDb::MergeCellStyleOption::kMergeCellStyleIgnoreNewStyles)
        .export_values()
        ;
    enum_<AcDb::TableIteratorOption>("TableIteratorOption")
        .value("kTableIteratorNone", AcDb::TableIteratorOption::kTableIteratorNone)
        .value("kTableIteratorIterateSelection", AcDb::TableIteratorOption::kTableIteratorIterateSelection)
        .value("kTableIteratorIterateRows", AcDb::TableIteratorOption::kTableIteratorIterateRows)
        .value("kTableIteratorIterateColumns", AcDb::TableIteratorOption::kTableIteratorIterateColumns)
        .value("kTableIteratorIterateDataLinks", AcDb::TableIteratorOption::kTableIteratorIterateDataLinks)
        .value("kTableIteratorReverseOrder", AcDb::TableIteratorOption::kTableIteratorReverseOrder)
        .value("kTableIteratorSkipReadOnlyContent", AcDb::TableIteratorOption::kTableIteratorSkipReadOnlyContent)
        .value("kTableIteratorSkipReadOnlyFormat", AcDb::TableIteratorOption::kTableIteratorSkipReadOnlyFormat)
        .value("kTableIteratorSkipMerged", AcDb::TableIteratorOption::kTableIteratorSkipMerged)
        .export_values()
        ;
    enum_<AcDb::TableBreakFlowDirection>("TableBreakFlowDirection")
        .value("kTableIteratorNone", AcDb::TableBreakFlowDirection::kTableBreakFlowRight)
        .value("kTableBreakFlowDownOrUp", AcDb::TableBreakFlowDirection::kTableBreakFlowDownOrUp)
        .value("kTableBreakFlowLeft", AcDb::TableBreakFlowDirection::kTableBreakFlowLeft)
        .export_values()
        ;
    enum_<AcDb::TableBreakOption>("TableBreakOption")
        .value("kTableBreakNone", AcDb::TableBreakOption::kTableBreakNone)
        .value("kTableBreakEnableBreaking", AcDb::TableBreakOption::kTableBreakEnableBreaking)
        .value("kTableBreakRepeatTopLabels", AcDb::TableBreakOption::kTableBreakRepeatTopLabels)
        .value("kTableBreakRepeatBottomLabels", AcDb::TableBreakOption::kTableBreakRepeatBottomLabels)
        .value("kTableBreakAllowManualPositions", AcDb::TableBreakOption::kTableBreakAllowManualPositions)
        .value("kTableBreakAllowManualHeights", AcDb::TableBreakOption::kTableBreakAllowManualHeights)
        .export_values()
        ;
    enum_<AcDb::RotationAngle>("RotationAngle")
        .value("kDegreesUnknown", AcDb::RotationAngle::kDegreesUnknown)
        .value("kDegrees000", AcDb::RotationAngle::kDegrees000)
        .value("kDegrees090", AcDb::RotationAngle::kDegrees090)
        .value("kDegrees180", AcDb::RotationAngle::kDegrees180)
        .value("kDegrees270", AcDb::RotationAngle::kDegrees270)
        .export_values()
        ;
    enum_<AcDb::GridLineStyle>("GridLineStyle")
        .value("kGridLineStyleSingle", AcDb::GridLineStyle::kGridLineStyleSingle)
        .value("kGridLineStyleDouble", AcDb::GridLineStyle::kGridLineStyleDouble)
        .export_values()
        ;
    enum_<AcDb::GridLineType>("GridLineType")
        .value("kInvalidGridLine", AcDb::GridLineType::kInvalidGridLine)
        .value("kHorzTop", AcDb::GridLineType::kHorzTop)
        .value("kHorzInside", AcDb::GridLineType::kHorzInside)
        .value("kHorzBottom", AcDb::GridLineType::kHorzBottom)
        .value("kVertLeft", AcDb::GridLineType::kVertLeft)
        .value("kVertInside", AcDb::GridLineType::kVertInside)
        .value("kVertRight", AcDb::GridLineType::kVertRight)
        .value("kHorzGridLineTypes", AcDb::GridLineType::kHorzGridLineTypes)
        .value("kVertGridLineTypes", AcDb::GridLineType::kVertGridLineTypes)
        .value("kOuterGridLineTypes", AcDb::GridLineType::kOuterGridLineTypes)
        .value("kInnerGridLineTypes", AcDb::GridLineType::kInnerGridLineTypes)
        .value("kAllGridLineTypes", AcDb::GridLineType::kAllGridLineTypes)
        .export_values()
        ;
    enum_<AcDb::GridProperty>("GridProperty")
        .value("kGridPropInvalid", AcDb::GridProperty::kGridPropInvalid)
        .value("kGridPropLineStyle", AcDb::GridProperty::kGridPropLineStyle)
        .value("kGridPropLineWeight", AcDb::GridProperty::kGridPropLineWeight)
        .value("kGridPropLinetype", AcDb::GridProperty::kGridPropLinetype)
        .value("kGridPropColor", AcDb::GridProperty::kGridPropColor)
        .value("kGridPropVisibility", AcDb::GridProperty::kGridPropVisibility)
        .value("kGridPropDoubleLineSpacing", AcDb::GridProperty::kGridPropDoubleLineSpacing)
        .value("kGridPropAll", AcDb::GridProperty::kGridPropAll)
        .export_values()
        ;
    enum_<AcDb::CellProperty>("CellProperty")
        .value("kCellPropInvalid", AcDb::CellProperty::kCellPropInvalid)
        .value("kCellPropDataType", AcDb::CellProperty::kCellPropDataType)
        .value("kCellPropDataFormat", AcDb::CellProperty::kCellPropDataFormat)
        .value("kCellPropRotation", AcDb::CellProperty::kCellPropRotation)
        .value("kCellPropScale", AcDb::CellProperty::kCellPropScale)
        .value("kCellPropAlignment", AcDb::CellProperty::kCellPropAlignment)
        .value("kCellPropContentColor", AcDb::CellProperty::kCellPropContentColor)
        .value("kCellPropTextStyle", AcDb::CellProperty::kCellPropTextStyle)
        .value("kCellPropTextHeight", AcDb::CellProperty::kCellPropTextHeight)
        .value("kCellPropAutoScale", AcDb::CellProperty::kCellPropAutoScale)
        .value("kCellPropBackgroundColor", AcDb::CellProperty::kCellPropBackgroundColor)
        .value("kCellPropMarginLeft", AcDb::CellProperty::kCellPropMarginLeft)
        .value("kCellPropMarginTop", AcDb::CellProperty::kCellPropMarginTop)
        .value("kCellPropMarginRight", AcDb::CellProperty::kCellPropMarginRight)
        .value("kCellPropMarginBottom", AcDb::CellProperty::kCellPropMarginBottom)
        .value("kCellPropMarginHorzSpacing", AcDb::CellProperty::kCellPropMarginHorzSpacing)
        .value("kCellPropMarginVertSpacing", AcDb::CellProperty::kCellPropMarginVertSpacing)
        .value("kCellPropContentLayout", AcDb::CellProperty::kCellPropContentLayout)
        .value("kCellPropMergeAll", AcDb::CellProperty::kCellPropMergeAll)
        .value("kCellPropFlowDirBtoT", AcDb::CellProperty::kCellPropFlowDirBtoT)
        .value("kCellPropDataTypeAndFormat", AcDb::CellProperty::kCellPropDataTypeAndFormat)
        .value("kCellPropContent", AcDb::CellProperty::kCellPropContent)
        .value("kCellPropBitProperties", AcDb::CellProperty::kCellPropBitProperties)
        .value("kCellPropAll", AcDb::CellProperty::kCellPropAll)
        .export_values()
        ;
    enum_<AcDb::CellState>("CellState")
        .value("kCellStateNone", AcDb::CellState::kCellStateNone)
        .value("kCellStateContentLocked", AcDb::CellState::kCellStateContentLocked)
        .value("kCellStateContentReadOnly", AcDb::CellState::kCellStateContentReadOnly)
        .value("kCellStateLinked", AcDb::CellState::kCellStateLinked)
        .value("kCellStateContentModifiedAfterUpdate", AcDb::CellState::kCellStateContentModifiedAfterUpdate)
        .value("kCellStateFormatLocked", AcDb::CellState::kCellStateFormatLocked)
        .value("kCellStateFormatReadOnly", AcDb::CellState::kCellStateFormatReadOnly)
        .value("kCellStateFormatModifiedAfterUpdate", AcDb::CellState::kCellStateFormatModifiedAfterUpdate)
        .value("kAllCellStates", AcDb::CellState::kAllCellStates)
        .export_values()
        ;
    enum_<AcDb::CellContentLayout>("CellContentLayout")
        .value("kCellStateNone", AcDb::CellContentLayout::kCellContentLayoutFlow)
        .value("kCellContentLayoutStackedHorizontal", AcDb::CellContentLayout::kCellContentLayoutStackedHorizontal)
        .value("kCellContentLayoutStackedVertical", AcDb::CellContentLayout::kCellContentLayoutStackedVertical)
        .export_values()
        ;
    enum_<AcDb::CellMargin>("CellMargin")
        .value("kCellMarginTop", AcDb::CellMargin::kCellMarginTop)
        .value("kCellMarginLeft", AcDb::CellMargin::kCellMarginLeft)
        .value("kCellMarginBottom", AcDb::CellMargin::kCellMarginBottom)
        .value("kCellMarginRight", AcDb::CellMargin::kCellMarginRight)
        .value("kCellMarginHorzSpacing", AcDb::CellMargin::kCellMarginHorzSpacing)
        .value("kCellMarginVertSpacing", AcDb::CellMargin::kCellMarginVertSpacing)
        .export_values()
        ;
    enum_<AcDb::CellEdgeMask>("CellEdgeMask")
        .value("kTopMask", AcDb::CellEdgeMask::kTopMask)
        .value("kRightMask", AcDb::CellEdgeMask::kRightMask)
        .value("kBottomMask", AcDb::CellEdgeMask::kBottomMask)
        .value("kLeftMask", AcDb::CellEdgeMask::kLeftMask)
        .export_values()
        ;
    enum_<AcDb::CellContentType>("CellContentType")
        .value("kCellContentTypeUnknown", AcDb::CellContentType::kCellContentTypeUnknown)
        .value("kCellContentTypeValue", AcDb::CellContentType::kCellContentTypeValue)
        .value("kCellContentTypeField", AcDb::CellContentType::kCellContentTypeField)
        .value("kCellContentTypeBlock", AcDb::CellContentType::kCellContentTypeBlock)
        .export_values()
        ;
    enum_<AcDb::CellType>("CellType")
        .value("kUnknownCell", AcDb::CellType::kUnknownCell)
        .value("kTextCell", AcDb::CellType::kTextCell)
        .value("kBlockCell", AcDb::CellType::kBlockCell)
        .value("kMultipleContentCell", AcDb::CellType::kMultipleContentCell)
        .export_values()
        ;
    enum_<AcValue::FormatOption>("FormatOption")
        .value("kFormatOptionNone", AcValue::FormatOption::kFormatOptionNone)
        .value("kForEditing", AcValue::FormatOption::kForEditing)
        .value("kForExpression", AcValue::FormatOption::kForExpression)
        .value("kUseMaximumPrecision", AcValue::FormatOption::kUseMaximumPrecision)
        .value("kIgnoreMtextFormat", AcValue::FormatOption::kIgnoreMtextFormat)
        .export_values()
        ;
}

PyDbTable::PyDbTable()
    : PyDbTable(new AcDbTable(), true)
{
}

PyDbTable::PyDbTable(AcDbTable* ptr, bool autoDelete)
    : PyDbBlockReference(ptr, autoDelete)
{
}

PyDbTable::PyDbTable(const PyDbObjectId& id)
    : PyDbTable(id, AcDb::OpenMode::kForRead)
{
}

PyDbTable::PyDbTable(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbBlockReference(openAcDbObject<AcDbTable>(id, mode), false)
{
}

PyDbObjectId PyDbTable::tableStyle() const
{
    return PyDbObjectId(impObj()->tableStyle());
}

void PyDbTable::setTableStyle(const PyDbObjectId& id)
{
    return PyThrowBadEs(impObj()->setTableStyle(id.m_id));
}

AcGeVector3d PyDbTable::direction() const
{
    return impObj()->direction();
}

void PyDbTable::setDirection(const AcGeVector3d& horzVec)
{
    return PyThrowBadEs(impObj()->setDirection(horzVec));
}

Adesk::UInt32 PyDbTable::numRows() const
{
    return impObj()->numRows();
}

Adesk::UInt32 PyDbTable::numColumns() const
{
    return impObj()->numColumns();
}

double PyDbTable::width() const
{
    return impObj()->width();
}

void PyDbTable::setWidth(double width)
{
    return PyThrowBadEs(impObj()->setWidth(width));
}

double PyDbTable::columnWidth(int col) const
{
    return impObj()->columnWidth(col);
}

void PyDbTable::setColumnWidth1(int col, double width)
{
    return PyThrowBadEs(impObj()->setColumnWidth(col, width));
}

void PyDbTable::setColumnWidth2(double width)
{
    return PyThrowBadEs(impObj()->setColumnWidth(width));
}

double PyDbTable::height() const
{
    return impObj()->height();
}

void PyDbTable::setHeight(double height)
{
    return PyThrowBadEs(impObj()->setHeight(height));
}

double PyDbTable::rowHeight(int row) const
{
    return impObj()->rowHeight(row);
}

void PyDbTable::setRowHeight1(int row, double height)
{
    return PyThrowBadEs(impObj()->setRowHeight(row, height));
}

void PyDbTable::setRowHeight2(double height)
{
    return PyThrowBadEs(impObj()->setRowHeight(height));
}

double PyDbTable::minimumColumnWidth(int col) const
{
    return impObj()->minimumColumnWidth(col);
}

double PyDbTable::minimumRowHeight(int row) const
{
    return impObj()->minimumColumnWidth(row);
}

double PyDbTable::minimumTableWidth() const
{
    return impObj()->minimumTableWidth();
}

double PyDbTable::minimumTableHeight() const
{
    return impObj()->minimumTableHeight();
}

double PyDbTable::horzCellMargin() const
{
    return impObj()->horzCellMargin();
}

void PyDbTable::setHorzCellMargin(double gap)
{
    return PyThrowBadEs(impObj()->setHorzCellMargin(gap));
}

double PyDbTable::vertCellMargin() const
{
    return impObj()->vertCellMargin();
}

void PyDbTable::setVertCellMargin(double gap)
{
    return PyThrowBadEs(impObj()->setVertCellMargin(gap));
}

AcDb::FlowDirection PyDbTable::flowDirection() const
{
    return impObj()->flowDirection();
}

void PyDbTable::setFlowDirection(AcDb::FlowDirection flow)
{
    return PyThrowBadEs(impObj()->setFlowDirection(flow));
}

bool PyDbTable::isTitleSuppressed() const
{
    return impObj()->isTitleSuppressed();
}

void PyDbTable::suppressTitleRow(bool value)
{
    return PyThrowBadEs(impObj()->suppressTitleRow(value));
}

bool PyDbTable::isHeaderSuppressed() const
{
    return impObj()->isHeaderSuppressed();
}

void PyDbTable::suppressHeaderRow(bool value)
{
    return PyThrowBadEs(impObj()->suppressHeaderRow(value));
}

AcDb::CellAlignment PyDbTable::alignment(AcDb::RowType type) const
{
    return impObj()->alignment(type);
}

AcDb::CellAlignment PyDbTable::alignment2(int row, int col) const
{
    return impObj()->alignment(row, col);
}

void PyDbTable::setAlignment(AcDb::CellAlignment align, AcDb::RowType rowTypes)
{
    return PyThrowBadEs(impObj()->setAlignment(align, rowTypes));
}

void PyDbTable::setAlignment2(int row, int col, AcDb::CellAlignment align)
{
    return PyThrowBadEs(impObj()->setAlignment(row, col, align));
}

bool PyDbTable::isBackgroundColorNone(AcDb::RowType type) const
{
    return impObj()->isBackgroundColorNone(type);
}

bool PyDbTable::isBackgroundColorNone2(int row, int col) const
{
    return impObj()->isBackgroundColorNone(row, col);
}

void PyDbTable::setBackgroundColorNone(bool value, AcDb::RowType type)
{
    return PyThrowBadEs(impObj()->setBackgroundColorNone(value, type));
}

void PyDbTable::setBackgroundColorNone2(int row, int col, bool value)
{
    return PyThrowBadEs(impObj()->setBackgroundColorNone(row, col, value));
}

AcCmColor PyDbTable::backgroundColor(AcDb::RowType type) const
{
    return impObj()->backgroundColor(type);
}

AcCmColor PyDbTable::backgroundColor2(int row, int col) const
{
    return impObj()->backgroundColor(row, col);
}

void PyDbTable::setBackgroundColor(const AcCmColor& color, AcDb::RowType type)
{
    return PyThrowBadEs(impObj()->setBackgroundColor(color, type));
}

void PyDbTable::setBackgroundColor2(int row, int col, const AcCmColor& color)
{
    return PyThrowBadEs(impObj()->setBackgroundColor(row, col, color));
}

AcCmColor PyDbTable::contentColor(AcDb::RowType type) const
{
    return impObj()->contentColor(type);
}

AcCmColor PyDbTable::contentColor2(int row, int col) const
{
    return impObj()->contentColor(row, col);
}

AcCmColor PyDbTable::contentColor3(int row, int col, int nContent) const
{
    return impObj()->contentColor(row, col, nContent);
}

void PyDbTable::setContentColor(const AcCmColor& color, AcDb::RowType type)
{
    return PyThrowBadEs(impObj()->setContentColor(color, type));
}

void PyDbTable::setContentColor2(int row, int col, const AcCmColor& color)
{
    return PyThrowBadEs(impObj()->setContentColor(row, col, color));
}

void PyDbTable::setContentColor3(int row, int col, int nContent, const AcCmColor& color)
{
    return PyThrowBadEs(impObj()->setContentColor(row, col, nContent, color));
}

boost::python::list PyDbTable::cellStyleOverrides(int row, int col) const
{
    AcDbIntArray overrides;
    impObj()->cellStyleOverrides(row, col, overrides);
    return IntArrayToPyList(overrides);
}

void PyDbTable::clearCellOverrides(int row, int column)
{
    return impObj()->clearCellOverrides(row, column);
}

void PyDbTable::deleteCellContent(int row, int col)
{
    return PyThrowBadEs(impObj()->deleteCellContent(row, col));
}

AcDb::RowType PyDbTable::rowType(int row) const
{
    return impObj()->rowType(row);
}

boost::python::tuple PyDbTable::getDataType(AcDb::RowType type) const
{
    PyAutoLockGIL lock;
    AcValue::DataType nDataType = AcValue::kUnknown;
    AcValue::UnitType nUnitType = AcValue::kUnitless;
    PyThrowBadEs(impObj()->getDataType(nDataType, nUnitType, type));
    return boost::python::make_tuple(nDataType, nUnitType);
}

boost::python::tuple PyDbTable::getDataType2(int row, int col) const
{
    PyAutoLockGIL lock;
    AcValue::DataType nDataType;
    AcValue::UnitType nUnitType;
    PyThrowBadEs(impObj()->getDataType(row, col, nDataType, nUnitType));
    return boost::python::make_tuple(nDataType, nUnitType);
}

boost::python::tuple PyDbTable::getDataType3(int row, int col, int nContent) const
{
    PyAutoLockGIL lock;
    AcValue::DataType nDataType;
    AcValue::UnitType nUnitType;
    PyThrowBadEs(impObj()->getDataType(row, col, nContent, nDataType, nUnitType));
    return boost::python::make_tuple(nDataType, nUnitType);
}

void PyDbTable::setDataType1(AcValue::DataType nDataType, AcValue::UnitType nUnitType)
{
    return PyThrowBadEs(impObj()->setDataType(nDataType, nUnitType));
}

void PyDbTable::setDataType2(AcValue::DataType nDataType, AcValue::UnitType nUnitType, AcDb::RowType type)
{
    return PyThrowBadEs(impObj()->setDataType(nDataType, nUnitType, type));
}

void PyDbTable::setDataType3(int row, int col, AcValue::DataType nDataType, AcValue::UnitType nUnitType)
{
    return PyThrowBadEs(impObj()->setDataType(row, col, nDataType, nUnitType));
}

void PyDbTable::setDataType4(int row, int col, int nContent, AcValue::DataType nDataType, AcValue::UnitType nUnitType)
{
    return PyThrowBadEs(impObj()->setDataType(row, col, nContent, nDataType, nUnitType));
}

void PyDbTable::setFormat(int row, int col, const std::string& pszFormat)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setFormat(row, col, utf8_to_wstr(pszFormat).c_str()));
#endif
}

std::string PyDbTable::textString(int row, int col) const
{
    return wstr_to_utf8(impObj()->textString(row, col));
}

std::string PyDbTable::textString2(int row, int col, int nContent) const
{
    return wstr_to_utf8(impObj()->textString(row, col, nContent));
}

std::string PyDbTable::textString3(const AcCell& cell) const
{
    return wstr_to_utf8(impObj()->textString(cell.mnRow, cell.mnColumn));
}

std::string PyDbTable::textStringFmt1(int row, int col, AcValue::FormatOption nOption) const
{
    AcString str;
    PyThrowBadEs(impObj()->textString(row, col, nOption, str));
    return wstr_to_utf8(str);
}

std::string PyDbTable::textStringFmt2(int row, int col, int nContent, AcValue::FormatOption nOption) const
{
    AcString str;
    PyThrowBadEs(impObj()->textString(row, col, nContent, nOption, str));
    return wstr_to_utf8(str);
}

std::string PyDbTable::textStringFmt3(const AcCell& cell, AcValue::FormatOption nOption) const
{
    AcString str;
    PyThrowBadEs(impObj()->textString(cell.mnRow, cell.mnColumn, nOption, str));
    return wstr_to_utf8(str);
}

void PyDbTable::setTextString(int row, int col, const std::string& text)
{
    return PyThrowBadEs(impObj()->setTextString(row, col, utf8_to_wstr(text).c_str()));
}

void PyDbTable::setTextString2(int row, int col, int nContent, const std::string& text)
{
    return PyThrowBadEs(impObj()->setTextString(row, col, nContent, utf8_to_wstr(text).c_str()));
}

void PyDbTable::setTextString3(const AcCell& cell, const std::string& text)
{
    return PyThrowBadEs(impObj()->setTextString(cell.mnRow, cell.mnColumn, utf8_to_wstr(text).c_str()));
}

PyDbObjectId PyDbTable::textStyle(AcDb::RowType type) const
{
    return PyDbObjectId(impObj()->textStyle(type));
}

PyDbObjectId PyDbTable::textStyle2(int row, int col) const
{
    return PyDbObjectId(impObj()->textStyle(row, col));
}

PyDbObjectId PyDbTable::textStyle3(int row, int col, int nContent) const
{
    return PyDbObjectId(impObj()->textStyle(row, col, nContent));
}

void PyDbTable::setTextStyle(const PyDbObjectId& id, AcDb::RowType rowTypes)
{
    return PyThrowBadEs(impObj()->setTextStyle(id.m_id, rowTypes));
}

void PyDbTable::setTextStyle2(int row, int col, const PyDbObjectId& id)
{
    return PyThrowBadEs(impObj()->setTextStyle(row, col, id.m_id));
}

void PyDbTable::setTextStyle3(int row, int col, int nContent, const PyDbObjectId& id)
{
    return PyThrowBadEs(impObj()->setTextStyle(row, col, nContent, id.m_id));
}

double PyDbTable::textHeight(AcDb::RowType type) const
{
    return impObj()->textHeight(type);
}

double PyDbTable::textHeight2(int row, int col) const
{
    return impObj()->textHeight(row, col);
}

double PyDbTable::textHeight3(int row, int col, int nContent) const
{
    return impObj()->textHeight(row, col, nContent);
}

void PyDbTable::setTextHeight(double height, AcDb::RowType rowTypes)
{
    return PyThrowBadEs(impObj()->setTextHeight(height, rowTypes));
}

void PyDbTable::setTextHeight2(int row, int col, double height)
{
    return PyThrowBadEs(impObj()->setTextHeight(row, col, height));
}

void PyDbTable::setTextHeight3(int row, int col, int nContent, double height)
{
    return PyThrowBadEs(impObj()->setTextHeight(row, col, nContent, height));
}

AcDb::LineWeight PyDbTable::gridLineWeight(AcDb::GridLineType gridlineType, AcDb::RowType type) const
{
    return impObj()->gridLineWeight(gridlineType, type);
}

AcDb::LineWeight PyDbTable::gridEdgeLineWeight(int row, int col, AcDb::CellEdgeMask iEdge) const
{
    return impObj()->gridLineWeight(row, col, iEdge);
}

AcDb::LineWeight PyDbTable::gridLineWeight2(int nRow, int nCol, AcDb::GridLineType nGridLineType) const
{
    return impObj()->gridLineWeight(nRow, nCol, nGridLineType);
}

void PyDbTable::setGridLineWeight(AcDb::LineWeight lwt, int nBorders, int nRows)
{
    return PyThrowBadEs(impObj()->setGridLineWeight(lwt, nBorders, nRows));
}

void PyDbTable::setGridEdgeLineWeight(int row, int col, AcDb::CellEdgeMask nEdges, AcDb::LineWeight value)
{
    return PyThrowBadEs(impObj()->setGridLineWeight(row, col, nEdges, value));
}

void PyDbTable::setGridLineWeight2(int nRow, int nCol, AcDb::GridLineType nGridLineTypes, AcDb::LineWeight nLineWeight)
{
    return PyThrowBadEs(impObj()->setGridLineWeight(nRow, nCol, nGridLineTypes, nLineWeight));
}

AcCmColor PyDbTable::gridColor(AcDb::GridLineType gridlineType, AcDb::RowType type) const
{
    return impObj()->gridColor(gridlineType, type);
}

AcCmColor PyDbTable::gridEdgeColor(int row, int col, AcDb::CellEdgeMask iEdge) const
{
    return impObj()->gridColor(row, col, iEdge);
}

AcCmColor PyDbTable::gridColor2(int nRow, int nCol, AcDb::GridLineType nGridLineType) const
{
    return impObj()->gridColor(nRow, nCol, nGridLineType);
}

void PyDbTable::setGridColor(const AcCmColor& color, int nBorders, int nRows)
{
    return PyThrowBadEs(impObj()->setGridColor(color, nBorders, nRows));
}

void PyDbTable::setGridEdgeColor(int row, int col, AcDb::CellEdgeMask nEdges, const AcCmColor& color)
{
    return PyThrowBadEs(impObj()->setGridColor(row, col, nEdges, color));
}

void PyDbTable::setGridColor2(int nRow, int nCol, AcDb::GridLineType nGridlineTypes, const AcCmColor& color)
{
    return PyThrowBadEs(impObj()->setGridColor(nRow, nCol, nGridlineTypes, color));
}

AcDb::Visibility PyDbTable::gridVisibility(AcDb::GridLineType gridlineType, AcDb::RowType type) const
{
    return impObj()->gridVisibility(gridlineType, type);
}

AcDb::Visibility PyDbTable::gridEdgeVisibility(int row, int col, AcDb::CellEdgeMask iEdge) const
{
    return impObj()->gridVisibility(row, col, iEdge);
}

AcDb::Visibility PyDbTable::gridVisibility2(int nRow, int nCol, AcDb::GridLineType nGridLineType) const
{
    return impObj()->gridVisibility(nRow, nCol, nGridLineType);
}

void PyDbTable::setGridVisibility(AcDb::Visibility visible, int nBorders, int nRows)
{
    return PyThrowBadEs(impObj()->setGridVisibility(visible, nBorders, nRows));
}

void PyDbTable::setGridEdgeVisibility(int row, int col, AcDb::CellEdgeMask iEdge, AcDb::Visibility value)
{
    return PyThrowBadEs(impObj()->setGridVisibility(row, col, iEdge, value));
}

void PyDbTable::setGridVisibility2(int nRow, int nCol, AcDb::GridLineType nGridLineTypes, AcDb::Visibility nVisibility)
{
    return PyThrowBadEs(impObj()->setGridVisibility(nRow, nCol, nGridLineTypes, nVisibility));
}

boost::python::list PyDbTable::tableStyleOverrides() const
{
    AcDbIntArray overrides;
    impObj()->tableStyleOverrides(overrides);
    return IntArrayToPyList(overrides);
}

void PyDbTable::clearTableStyleOverrides()
{
    impObj()->clearTableStyleOverrides();
}

AcDb::CellType PyDbTable::cellType(int row, int col) const
{
    return impObj()->cellType(row, col);
}

void PyDbTable::setCellType(int row, int col, AcDb::CellType type)
{
    return PyThrowBadEs(impObj()->setCellType(row, col, type));
}

boost::python::list PyDbTable::getCellExtents(int row, int col, bool isOuterCell) const
{
    AcGePoint3dArray pts;
    PyThrowBadEs(impObj()->getCellExtents(row, col, isOuterCell, pts));
    return Point3dArrayToPyList(pts);
}

AcGePoint3d PyDbTable::attachmentPoint(int row, int col) const
{
    return impObj()->attachmentPoint(row, col);
}

AcGePoint3d PyDbTable::attachmentPoint2(int row, int col, int content) const
{
    return impObj()->attachmentPoint(row, col, content);
}

PyDbObjectId PyDbTable::fieldId(int row, int col) const
{
    return PyDbObjectId(impObj()->fieldId(row, col));
}

PyDbObjectId PyDbTable::fieldId2(int row, int col, int nContent) const
{
    return PyDbObjectId(impObj()->fieldId(row, col, nContent));
}

void PyDbTable::setFieldId(int row, int col, const PyDbObjectId& fieldId)
{
    return PyThrowBadEs(impObj()->setFieldId(row, col, fieldId.m_id));
}

void PyDbTable::setFieldId2(int row, int col, int nContent, const PyDbObjectId& fieldId, AcDb::CellOption nFlag)
{
    return PyThrowBadEs(impObj()->setFieldId(row, col, nContent, fieldId.m_id, nFlag));
}

AcDb::RotationAngle PyDbTable::textRotation(int row, int col) const
{
    return impObj()->textRotation(row, col);
}

void PyDbTable::setTextRotation(int row, int col, AcDb::RotationAngle rot)
{
    return PyThrowBadEs(impObj()->setTextRotation(row, col, rot));
}

bool PyDbTable::isAutoScale(int row, int col) const
{
    return impObj()->isAutoScale(row, col);
}

bool PyDbTable::isAutoScale2(int row, int col, int nContent) const
{
    return impObj()->isAutoScale(row, col, nContent);
}

void PyDbTable::setAutoScale(int row, int col, bool autoFit)
{
    return PyThrowBadEs(impObj()->setAutoScale(row, col, autoFit));
}

void PyDbTable::setAutoScale2(int row, int col, int nContent, bool autoFit)
{
    return PyThrowBadEs(impObj()->setAutoScale(row, col, nContent, autoFit));
}

PyDbObjectId PyDbTable::blockTableRecordId(int row, int col) const
{
    return PyDbObjectId(impObj()->blockTableRecordId(row, col));
}

PyDbObjectId PyDbTable::blockTableRecordId2(int row, int col, int nContent) const
{
    return PyDbObjectId(impObj()->blockTableRecordId(row, col, nContent));
}

void PyDbTable::setBlockTableRecordId(int row, int col, const PyDbObjectId& blkId, bool autoFit)
{
    return PyThrowBadEs(impObj()->setBlockTableRecordId(row, col, blkId.m_id, autoFit));
}

void PyDbTable::setBlockTableRecordId2(int row, int col, int nContent, const PyDbObjectId& blkId, bool autoFit)
{
    return PyThrowBadEs(impObj()->setBlockTableRecordId(row, col, nContent, blkId.m_id, autoFit));
}

double PyDbTable::blockScale(int row, int col) const
{
    return impObj()->blockScale(row, col);
}

void PyDbTable::setBlockScale(int row, int col, double scale)
{
    return PyThrowBadEs(impObj()->setBlockScale(row, col, scale));
}

double PyDbTable::blockRotation(int row, int col) const
{
    return impObj()->blockRotation(row, col);
}

void PyDbTable::setBlockRotation(int row, int col, double rotAng)
{
    return PyThrowBadEs(impObj()->setBlockRotation(row, col, rotAng));
}

void PyDbTable::insertColumns(int col, double width, int nCols)
{
    return PyThrowBadEs(impObj()->insertColumns(col, width, nCols));
}

void PyDbTable::deleteColumns(int col, int nCols)
{
    return PyThrowBadEs(impObj()->deleteColumns(col, nCols));
}

void PyDbTable::insertRows(int row, double height, int nRows)
{
    return PyThrowBadEs(impObj()->insertRows(row, height, nRows));
}

void PyDbTable::deleteRows(int row, int nRows)
{
    return PyThrowBadEs(impObj()->deleteRows(row, nRows));
}

void PyDbTable::mergeCells(int minRow, int maxRow, int minCol, int maxCol)
{
    return PyThrowBadEs(impObj()->mergeCells(minRow, maxRow, minCol, maxCol));
}

void PyDbTable::unmergeCells(int minRow, int maxRow, int minCol, int maxCol)
{
    return PyThrowBadEs(impObj()->unmergeCells(minRow, maxRow, minCol, maxCol));
}

boost::python::tuple PyDbTable::isMergedCell(int row, int col)
{
    PyAutoLockGIL lock;
    int minRow = -1;
    int maxRow = -1;
    int minCol = -1;
    int maxCol = -1;
    bool flag = impObj()->isMergedCell(row, col, &minRow, &maxRow, &minCol, &maxCol);
    return boost::python::make_tuple(flag, minRow, maxRow, minCol, maxCol);
}

void PyDbTable::generateLayout()
{
    return PyThrowBadEs(impObj()->generateLayout());
}

void PyDbTable::recomputeTableBlock(bool forceUpdate)
{
    return PyThrowBadEs(impObj()->recomputeTableBlock(forceUpdate));
}

boost::python::tuple PyDbTable::hitTest(const AcGePoint3d& wpt, const AcGeVector3d& wviewVec)
{
    PyAutoLockGIL lock;
    int resultRowIndex = -1;
    int resultColumnIndex = -1;
    int contentIndex = -1;
    AcDb::TableHitItem nItem = AcDb::kTableHitNone;
    bool flag = impObj()->hitTest(wpt, wviewVec, 0.0, 0.0, resultRowIndex, resultColumnIndex, contentIndex, nItem);
    return boost::python::make_tuple(flag, resultRowIndex, resultColumnIndex, contentIndex, nItem);
}

boost::python::tuple PyDbTable::hitTest2(const AcGePoint3d& wpt, const AcGeVector3d& wviewVec, double wxaper, double wyaper)
{
    PyAutoLockGIL lock;
    int resultRowIndex = -1;
    int resultColumnIndex = -1;
    int contentIndex = -1;
    AcDb::TableHitItem nItem = AcDb::kTableHitNone;
    bool flag = impObj()->hitTest(wpt, wviewVec, wxaper, wyaper, resultRowIndex, resultColumnIndex, contentIndex, nItem);
    return boost::python::make_tuple(flag, resultRowIndex, resultColumnIndex, contentIndex, nItem);
}

AcCellRange PyDbTable::getSubSelection(void) const
{
    return impObj()->getSubSelection();
}

void PyDbTable::setSubSelection(const AcCellRange& range)
{
    return PyThrowBadEs(impObj()->setSubSelection(range));
}

void PyDbTable::clearSubSelection()
{
    impObj()->clearSubSelection();
}

bool PyDbTable::hasSubSelection() const
{
    return impObj()->hasSubSelection();
}

void PyDbTable::setPosition(const AcGePoint3d& newVal)
{
    return PyThrowBadEs(impObj()->setPosition(newVal));
}

void PyDbTable::setNormal(const AcGeVector3d& newVal)
{
    return PyThrowBadEs(impObj()->setNormal(newVal));
}

void PyDbTable::setRegen()
{
    impObj()->setRegen();
}

void PyDbTable::suppressInvisibleGrid(bool value)
{
    impObj()->suppressInvisibleGrid(value);
}

bool PyDbTable::isRegenerateTableSuppressed() const
{
    return impObj()->isRegenerateTableSuppressed();
}

void PyDbTable::suppressRegenerateTable(bool bSuppress)
{
    impObj()->suppressRegenerateTable(bSuppress);
}

void PyDbTable::setRecomputeTableBlock(bool newVal)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    impObj()->setRecomputeTableBlock(newVal);
#endif
}

void PyDbTable::setSize(int nRows, int nCols)
{
    return PyThrowBadEs(impObj()->setSize(nRows, nCols));
}

bool PyDbTable::canInsert(int nIndex, bool bRow) const
{
    return impObj()->canInsert(nIndex, bRow);
}

void PyDbTable::insertRowsAndInherit(int nIndex, int nInheritFrom, int nNumRows)
{
    return PyThrowBadEs(impObj()->insertRowsAndInherit(nIndex, nInheritFrom, nNumRows));
}

void PyDbTable::insertColumnsAndInherit(int col, int nInheritFrom, int nNumCols)
{
    return PyThrowBadEs(impObj()->insertRowsAndInherit(col, nInheritFrom, nNumCols));
}

bool PyDbTable::canDelete(int nIndex, int nCount, bool bRow) const
{
    return impObj()->canDelete(nIndex, nCount, bRow);
}

bool PyDbTable::isEmpty(int nRow, int nCol) const
{
    return impObj()->isEmpty(nRow, nCol);
}

AcCellRange PyDbTable::getMergeRange(int nRow, int nCol) const
{
    return impObj()->getMergeRange(nRow, nCol);
}

boost::python::list PyDbTable::getIterator1()
{
    PyAutoLockGIL lock;
    boost::python::list l;
    std::unique_ptr<AcDbTableIterator> iter(impObj()->getIterator());
    for (iter->start(); !iter->done(); iter->step())
        l.append(iter->getCell());
    return l;
}

boost::python::list PyDbTable::getIterator2(AcDb::TableIteratorOption nOption) const
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    PyAutoLockGIL lock;
    boost::python::list l;
    const auto range = cellRange();
    std::unique_ptr<AcDbTableIterator> iter(impObj()->getIterator(&range, nOption));
    for (iter->start(); !iter->done(); iter->step())
        l.append(iter->getCell());
    return l;
#else
    PyAutoLockGIL lock;
    boost::python::list l;
    std::unique_ptr<AcDbTableIterator> iter(impObj()->getIterator(nullptr, nOption));
    for (iter->start(); !iter->done(); iter->step())
        l.append(iter->getCell());
    return l;
#endif
}

boost::python::list PyDbTable::getIterator3(const AcCellRange& pRange, AcDb::TableIteratorOption nOption) const
{
    PyAutoLockGIL lock;
    boost::python::list l;
    std::unique_ptr<AcDbTableIterator> iter(impObj()->getIterator(&pRange, nOption));
    for (iter->start(); !iter->done(); iter->step())
        l.append(iter->getCell());
    return l;
}

boost::python::list PyDbTable::getIterator4(const AcCellRange& pRange) const
{
    PyAutoLockGIL lock;
    boost::python::list l;
    std::unique_ptr<AcDbTableIterator> iter(impObj()->getIterator(&pRange, AcDb::kTableIteratorNone));
    for (iter->start(); !iter->done(); iter->step())
        l.append(iter->getCell());
    return l;
}

bool PyDbTable::isContentEditable(int nRow, int nCol) const
{
    return impObj()->isContentEditable(nRow, nCol);
}

bool PyDbTable::isFormatEditable(int nRow, int nCol) const
{
    return impObj()->isFormatEditable(nRow, nCol);
}

AcDb::CellState PyDbTable::cellState(int nRow, int nCol) const
{
    return impObj()->cellState(nRow, nCol);
}

void PyDbTable::setCellState(int nRow, int nCol, AcDb::CellState nLock)
{
    return PyThrowBadEs(impObj()->setCellState(nRow, nCol, nLock));
}

int PyDbTable::numContents(int nRow, int nCol) const
{
    return impObj()->numContents(nRow, nCol);
}

int PyDbTable::createContent(int nRow, int nCol, int nIndex)
{
    return impObj()->createContent(nRow, nCol, nIndex);
}

void PyDbTable::moveContent(int nRow, int nCol, int nFromIndex, int nToIndex)
{
    return PyThrowBadEs(impObj()->moveContent(nRow, nCol, nFromIndex, nToIndex));
}

void PyDbTable::deleteContent1(int nRow, int nCol)
{
    return PyThrowBadEs(impObj()->deleteContent(nRow, nCol));
}

void PyDbTable::deleteContent2(int nRow, int nCol, int nIndex)
{
    return PyThrowBadEs(impObj()->deleteContent(nRow, nCol, nIndex));
}

void PyDbTable::deleteContent3(const AcCellRange& range)
{
    return PyThrowBadEs(impObj()->deleteContent(range));
}

AcDb::CellContentType PyDbTable::contentType1(int nRow, int nCol) const
{
    return impObj()->contentType(nRow, nCol);
}

AcDb::CellContentType PyDbTable::contentType2(int nRow, int nCol, int nIndex) const
{
    return impObj()->contentType(nRow, nCol, nIndex);
}

std::string PyDbTable::dataFormat1(int row, int col) const
{
    return wstr_to_utf8(impObj()->dataFormat(row, row));
}

std::string PyDbTable::dataFormat2(int row, int col, int nContent) const
{
    return wstr_to_utf8(impObj()->dataFormat(row, row, nContent));
}

void PyDbTable::setDataFormat1(int row, int col, const std::string& pszFormat)
{
    return PyThrowBadEs(impObj()->setDataFormat(row, col, utf8_to_wstr(pszFormat).c_str()));
}

void PyDbTable::setDataFormat2(int row, int col, int nContent, const std::string& pszFormat)
{
    return PyThrowBadEs(impObj()->setDataFormat(row, col, nContent, utf8_to_wstr(pszFormat).c_str()));
}

bool PyDbTable::hasFormula(int nRow, int nCol, int nContent) const
{
    return impObj()->hasFormula(nRow, nCol, nContent);
}

std::string PyDbTable::getFormula(int nRow, int nCol, int nContent) const
{
    return wstr_to_utf8(impObj()->getFormula(nRow, nCol, nContent));
}

void PyDbTable::setFormula(int nRow, int nCol, int nContent, const std::string& pszFormula)
{
    return PyThrowBadEs(impObj()->setFormula(nRow, nCol, nContent, utf8_to_wstr(pszFormula).c_str()));
}

std::string PyDbTable::getBlockAttributeValue1(int row, int col, const PyDbObjectId& attdefId) const
{
    ACHAR* val = nullptr;
    PyThrowBadEs(impObj()->getBlockAttributeValue(row, col, attdefId.m_id, val));
    std::string sval = wstr_to_utf8(val);
    acutDelString(val);
    return sval;
}

std::string PyDbTable::getBlockAttributeValue2(int row, int col, int nContent, const PyDbObjectId& attdefId) const
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    ACHAR* val = nullptr;
    PyThrowBadEs(impObj()->getBlockAttributeValue(row, col, nContent, attdefId.m_id, val));
    std::string sval = wstr_to_utf8(val);
    acutDelString(val);
    return sval;
#endif
}

void PyDbTable::setBlockAttributeValue1(int row, int col, const PyDbObjectId& attdefId, const std::string& value)
{
    return PyThrowBadEs(impObj()->setBlockAttributeValue(row, col, attdefId.m_id, utf8_to_wstr(value).c_str()));
}

void PyDbTable::setBlockAttributeValue2(int row, int col, int nContent, const PyDbObjectId& attdefId, const std::string& value)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setBlockAttributeValue(row, col, nContent, attdefId.m_id, utf8_to_wstr(value).c_str()));
#endif
}

const std::string PyDbTable::cellStyle(int nRow, int nCol) const
{
    return wstr_to_utf8(impObj()->cellStyle(nRow, nCol));
}

void PyDbTable::setCellStyle(int nRow, int nCol, const std::string& pszCellStyle)
{
    return PyThrowBadEs(impObj()->setCellStyle(nRow, nCol, utf8_to_wstr(pszCellStyle).c_str()));
}

double PyDbTable::margin(int nRow, int nCol, AcDb::CellMargin nMargin) const
{
    return impObj()->margin(nRow, nCol, nMargin);
}

void PyDbTable::setMargin(int nRow, int nCol, AcDb::CellMargin nMargins, double fMargin)
{
    return PyThrowBadEs(impObj()->setMargin(nRow, nCol, nMargins, fMargin));
}

double PyDbTable::rotation(void) const
{
    return impObj()->rotation();
}

double PyDbTable::rotation2(int row, int col, int nContent) const
{
    return impObj()->rotation(row, col, nContent);
}

void PyDbTable::setRotation(double fAngle)
{
    return PyThrowBadEs(impObj()->setRotation(fAngle));
}

void PyDbTable::setRotation2(int row, int col, int nContent, double fAngle)
{
    return PyThrowBadEs(impObj()->setRotation(row, col, nContent, fAngle));
}

double PyDbTable::scale(int row, int col, int nContent) const
{
    return impObj()->scale(row, col, nContent);
}

void PyDbTable::setScale(int row, int col, int nContent, double scale)
{
    return PyThrowBadEs(impObj()->setScale(row, col, nContent, scale));
}

AcDb::CellContentLayout PyDbTable::contentLayout(int row, int col) const
{
    return impObj()->contentLayout(row, col);
}

void PyDbTable::setContentLayout(int row, int col, AcDb::CellContentLayout nLayout)
{
    return PyThrowBadEs(impObj()->setContentLayout(row, col, nLayout));
}

bool PyDbTable::isMergeAllEnabled(int nRow, int nCol) const
{
    return impObj()->isMergeAllEnabled(nRow, nCol);
}

void PyDbTable::enableMergeAll(int nRow, int nCol, bool bEnable)
{
    return PyThrowBadEs(impObj()->enableMergeAll(nRow, nCol, bEnable));
}

AcDb::CellProperty PyDbTable::getCellOverride(int nRow, int nCol, int nContent) const
{
    return impObj()->getOverride(nRow, nCol, nContent);
}

AcDb::GridProperty PyDbTable::getGridOverride(int nRow, int nCol, AcDb::GridLineType nGridLineType) const
{
    return impObj()->getOverride(nRow, nCol, nGridLineType);
}

void PyDbTable::setCellOverride(int nRow, int nCol, int nContent, AcDb::CellProperty nOverride)
{
    return PyThrowBadEs(impObj()->setOverride(nRow, nCol, nContent, nOverride));
}

void PyDbTable::setGridOverride(int nRow, int nCol, AcDb::GridLineType nGridLineType, AcDb::GridProperty nOverride)
{
    return PyThrowBadEs(impObj()->setOverride(nRow, nCol, nGridLineType, nOverride));
}

void PyDbTable::removeAllOverrides(int nRow, int nCol)
{
    return PyThrowBadEs(impObj()->removeAllOverrides(nRow, nCol));
}

AcDb::GridLineStyle PyDbTable::gridLineStyle(int nRow, int nCol, AcDb::GridLineType nGridLineType) const
{
    return impObj()->gridLineStyle(nRow, nCol, nGridLineType);
}

void PyDbTable::setGridLineStyle(int nRow, int nCol, AcDb::GridLineType nGridLineTypes, AcDb::GridLineStyle nLineStyle)
{
    return PyThrowBadEs(impObj()->setGridLineStyle(nRow, nCol, nGridLineTypes, nLineStyle));
}

PyDbObjectId PyDbTable::gridLinetype(int nRow, int nCol, AcDb::GridLineType nGridLineType) const
{
    return PyDbObjectId(impObj()->gridLinetype(nRow, nCol, nGridLineType));
}

void PyDbTable::setGridLinetype(int nRow, int nCol, AcDb::GridLineType nGridLineTypes, const PyDbObjectId& idLinetype)
{
    return PyThrowBadEs(impObj()->setGridLinetype(nRow, nCol, nGridLineTypes, idLinetype.m_id));
}

double PyDbTable::gridDoubleLineSpacing(int nRow, int nCol, AcDb::GridLineType nGridLineType) const
{
    return impObj()->gridDoubleLineSpacing(nRow, nCol, nGridLineType);
}

void PyDbTable::setGridDoubleLineSpacing(int nRow, int nCol, AcDb::GridLineType nGridLineTypes, double fSpacing)
{
    return PyThrowBadEs(impObj()->setGridDoubleLineSpacing(nRow, nCol, nGridLineTypes, fSpacing));
}

AcGridProperty PyDbTable::getGridProperty(int nRow, int nCol, AcDb::GridLineType nGridLineType) const
{
    AcGridProperty prop;
    PyThrowBadEs(impObj()->getGridProperty(nRow, nCol, nGridLineType, prop));
    return prop;
}

void PyDbTable::setGridProperty1(int nRow, int nCol, AcDb::GridLineType nGridLineTypes, const AcGridProperty& gridProp)
{
    return PyThrowBadEs(impObj()->setGridProperty(nRow, nCol, nGridLineTypes, gridProp));
}

void PyDbTable::setGridProperty2(const AcCellRange& rangeIn, AcDb::GridLineType nGridLineTypes, const AcGridProperty& gridProp)
{
    return PyThrowBadEs(impObj()->setGridProperty(rangeIn, nGridLineTypes, gridProp));
}

bool PyDbTable::isLinked(int nRow, int nCol) const
{
    return impObj()->isLinked(nRow, nCol);
}

PyDbObjectId PyDbTable::getDataLink(int nRow, int nCol) const
{
    return PyDbObjectId(impObj()->getDataLink(nRow, nCol));
}

void PyDbTable::setDataLink(const AcCellRange& range, const PyDbObjectId& idDataLink, bool bUpdate)
{
    return PyThrowBadEs(impObj()->setDataLink(range, idDataLink.m_id, bUpdate));
}

AcCellRange PyDbTable::getDataLinkRange(int nRow, int nCol) const
{
    return impObj()->getDataLinkRange(nRow, nCol);
}

void PyDbTable::removeDataLink1(void)
{
    return PyThrowBadEs(impObj()->removeDataLink());
}

void PyDbTable::removeDataLink2(int nRow, int nCol)
{
    return PyThrowBadEs(impObj()->removeDataLink(nRow, nCol));
}

void PyDbTable::updateDataLink1(AcDb::UpdateDirection nDir, AcDb::UpdateOption nOption)
{
    return PyThrowBadEs(impObj()->updateDataLink(nDir, nOption));
}

void PyDbTable::updateDataLink2(int nRow, int nCol, AcDb::UpdateDirection nDir, AcDb::UpdateOption nOption)
{
    return PyThrowBadEs(impObj()->updateDataLink(nRow, nCol, nDir, nOption));
}

bool PyDbTable::isBreakEnabled(void) const
{
    return impObj()->isBreakEnabled();
}

void PyDbTable::enableBreak(bool bEnable)
{
    return PyThrowBadEs(impObj()->enableBreak(bEnable));
}

AcDb::TableBreakFlowDirection PyDbTable::breakFlowDirection(void) const
{
    return impObj()->breakFlowDirection();
}

void PyDbTable::setBreakFlowDirection(AcDb::TableBreakFlowDirection nDir)
{
    return PyThrowBadEs(impObj()->setBreakFlowDirection(nDir));
}

double PyDbTable::breakHeight(int nIndex) const
{
    return impObj()->breakHeight(nIndex);
}

void PyDbTable::setBreakHeight(int nIndex, double fHeight)
{
    return PyThrowBadEs(impObj()->setBreakHeight(nIndex, fHeight));
}

AcGeVector3d PyDbTable::breakOffset(int nIndex) const
{
    return impObj()->breakOffset(nIndex);
}

void PyDbTable::setBreakOffset(int nIndex, const AcGeVector3d& vec)
{
    return PyThrowBadEs(impObj()->setBreakOffset(nIndex, vec));
}

AcDb::TableBreakOption PyDbTable::breakOption(void) const
{
    return impObj()->breakOption();
}

void PyDbTable::setBreakOption(AcDb::TableBreakOption nOption)
{
    return PyThrowBadEs(impObj()->setBreakOption(nOption));
}

double PyDbTable::breakSpacing(void) const
{
    return impObj()->breakSpacing();
}

void PyDbTable::setBreakSpacing(double fSpacing)
{
    return PyThrowBadEs(impObj()->setBreakSpacing(fSpacing));
}

AcCellRange PyDbTable::cellRange() const
{
#if defined(_GRXTARGET240) || defined(_ZRXTARGET240) || defined(_BRXTARGET240)
    auto range = AcCellRange{};
    range.mnTopRow = 0;
    range.mnLeftColumn = 0;
    range.mnBottomRow = impObj()->numRows() - 1;
    range.mnRightColumn = impObj()->numColumns() - 1;
    return range;
#else
    return impObj()->cellRange();
#endif
}

std::string PyDbTable::className()
{
    return "AcDbTable";
}

PyRxClass PyDbTable::desc()
{
    return PyRxClass(AcDbTable::desc(), false);
}

PyDbTable PyDbTable::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(AcDbTable::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbTable(static_cast<AcDbTable*>(src.impObj()->clone()), true);
}

PyDbTable PyDbTable::cast(const PyRxObject& src)
{
    PyDbTable dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

AcDbTable* PyDbTable::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<AcDbTable*>(m_pyImp.get());
}

