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
    constexpr const std::string_view setColumnWidthOverloads = "Overloads:\n"
        "- val: float\n"
        "- col: int, val: float\n";

    constexpr const std::string_view setRowHeightOverloads = "Overloads:\n"
        "- val: float\n"
        "- row: int, val: float\n";

    constexpr const std::string_view blockTableRecordIdOverloads = "Overloads:\n"
        "- row: int, col: int\n"
        "- row: int, col: int, nContent:int\n";

    constexpr const std::string_view setBlockTableRecordIdOverloads = "Overloads:\n"
        "- row: int, col: int, id:PyDb.ObjectId, autoScale:bool\n"
        "- row: int, col: int, nContent:int, id:PyDb.ObjectId, autoScale:bool\n";


    constexpr const std::string_view blockAttributeValueOverloads = "Overloads:\n"
        "- row: int, col: int, id:PyDb.ObjectId\n"
        "- row: int, col: int, nContent:int, id:PyDb.ObjectId\n";

    constexpr const std::string_view setBlockAttributeValueOverloads = "Overloads:\n"
        "- row: int, col: int, id:PyDb.ObjectId, val:str\n"
        "- row: int, col: int, nContent:int, id:PyDb.ObjectId, val:str\n";

    constexpr const std::string_view fieldIdOverloads = "Overloads:\n"
        "- row: int, col: int\n"
        "- row: int, col: int, nContent:int\n";

    constexpr const std::string_view setFieldIdOverloads = "Overloads:\n"
        "- row: int, col: int, id:PyDb.ObjectId\n"
        "- row: int, col: int, nContent:int, id:PyDb.ObjectId, nflag:PyAx.AcCellOption\n";


    PyDocString DS("AcadTable");
    class_<PyAcadTable, bases<PyAcadEntity>>("AcadTable", boost::python::no_init)
        .def("styleName", &PyAcadTable::styleName, DS.ARGS())
        .def("setStyleName", &PyAcadTable::setStyleName, DS.ARGS({ "val:str" }))
        .def("rows", &PyAcadTable::rows, DS.ARGS())
        .def("setRows", &PyAcadTable::setRows, DS.ARGS({ "val:int" }))
        .def("columns", &PyAcadTable::columns, DS.ARGS())
        .def("setColumns", &PyAcadTable::setColumns, DS.ARGS({ "val:int" }))
        .def("flowDirection", &PyAcadTable::flowDirection, DS.ARGS())
        .def("setFlowDirection", &PyAcadTable::setFlowDirection, DS.ARGS({ "val:PyAx.AcTableDirection" }))
        .def("width", &PyAcadTable::width, DS.ARGS())
        .def("setWidth", &PyAcadTable::setWidth, DS.ARGS({ "val:float" }))
        .def("height", &PyAcadTable::height, DS.ARGS())
        .def("setHeight", &PyAcadTable::setHeight, DS.ARGS({ "val:float" }))
        .def("vertCellMargin", &PyAcadTable::vertCellMargin, DS.ARGS())
        .def("setVertCellMargin", &PyAcadTable::setVertCellMargin, DS.ARGS({ "val:float" }))
        .def("horzCellMargin", &PyAcadTable::horzCellMargin, DS.ARGS())
        .def("setHorzCellMargin", &PyAcadTable::setHorzCellMargin, DS.ARGS({ "val:float" }))
        .def("insertionPoint", &PyAcadTable::insertionPoint, DS.ARGS())
        .def("setInsertionPoint", &PyAcadTable::setInsertionPoint, DS.ARGS({ "val:float" }))
        .def("columnWidth", &PyAcadTable::columnWidth, DS.ARGS())
        .def("setColumnWidth", &PyAcadTable::setColumnWidth1)
        .def("setColumnWidth", &PyAcadTable::setColumnWidth2, DS.OVRL(setColumnWidthOverloads))
        .def("rowHeight", &PyAcadTable::rowHeight, DS.ARGS())
        .def("setRowHeight", &PyAcadTable::setColumnWidth1)
        .def("setRowHeight", &PyAcadTable::setColumnWidth2, DS.OVRL(setRowHeightOverloads))
        .def("minimumColumnWidth", &PyAcadTable::minimumColumnWidth, DS.ARGS({ "val:int" }))
        .def("minimumRowHeight", &PyAcadTable::minimumRowHeight, DS.ARGS({ "val:int" }))
        .def("minimumTableWidth", &PyAcadTable::minimumTableWidth, DS.ARGS())
        .def("minimumTableHeight", &PyAcadTable::minimumTableHeight, DS.ARGS())
        .def("direction", &PyAcadTable::direction, DS.ARGS())
        .def("setDirection", &PyAcadTable::setDirection, DS.ARGS({ "val:PyGe.Vector3d" }))
        .def("titleSuppressed", &PyAcadTable::titleSuppressed, DS.ARGS())
        .def("setTitleSuppressed", &PyAcadTable::setTitleSuppressed, DS.ARGS({ "val:bool" }))
        .def("headerSuppressed", &PyAcadTable::headerSuppressed, DS.ARGS())
        .def("setHeaderSuppressed", &PyAcadTable::setHeaderSuppressed, DS.ARGS({ "val:bool" }))
        .def("tableStyleOverrides", &PyAcadTable::tableStyleOverrides, DS.ARGS())
        .def("clearTableStyleOverrides", &PyAcadTable::clearTableStyleOverrides, DS.ARGS({ "val:int" }))
        .def("cellType", &PyAcadTable::cellType, DS.ARGS({ "row:int","col:int" }))
        .def("clearTableStyleOverrides", &PyAcadTable::clearTableStyleOverrides, DS.ARGS({ "row:int","col:int","val:PyAx.AcCellType" }))
        .def("cellExtents", &PyAcadTable::cellExtents, DS.ARGS({ "row:int","col:int","bOuterCell:bool" }))
        .def("attachmentPoint", &PyAcadTable::attachmentPoint, DS.ARGS({ "row:int","col:int" }))
        .def("cellAlignment", &PyAcadTable::cellAlignment, DS.ARGS({ "row:int","col:int" }))
        .def("setCellAlignment", &PyAcadTable::setCellAlignment, DS.ARGS({ "row:int","col:int","val:PyAx.AcCellAlignment" }))
        .def("cellBackgroundColorNone", &PyAcadTable::cellBackgroundColorNone, DS.ARGS({ "row:int","col:int" }))
        .def("setCellBackgroundColorNone", &PyAcadTable::setCellBackgroundColorNone, DS.ARGS({ "row:int","col:int","val:bool" }))
        .def("cellBackgroundColor", &PyAcadTable::cellBackgroundColor, DS.ARGS({ "row:int","col:int" }))
        .def("setCellBackgroundColor", &PyAcadTable::setCellBackgroundColor, DS.ARGS({ "row:int","col:int","val:PyAx.AcadAcCmColor" }))
        .def("cellContentColor", &PyAcadTable::cellContentColor, DS.ARGS({ "row:int","col:int" }))
        .def("setCellContentColor", &PyAcadTable::setCellContentColor, DS.ARGS({ "row:int","col:int","val:PyAx.AcadAcCmColor" }))
        .def("cellStyleOverrides", &PyAcadTable::cellStyleOverrides, DS.ARGS({ "row:int","col:int" }))
        .def("deleteCellContent", &PyAcadTable::deleteCellContent, DS.ARGS({ "row:int","col:int" }))
        .def("rowType", &PyAcadTable::rowType, DS.ARGS({ "row:int" }))
        .def("text", &PyAcadTable::text, DS.ARGS({ "row:int","col:int" }))
        .def("setText", &PyAcadTable::setText, DS.ARGS({ "row:int","col:int","val:str" }))
        .def("cellTextStyle", &PyAcadTable::cellTextStyle, DS.ARGS({ "row:int","col:int" }))
        .def("setCellTextStyle", &PyAcadTable::setCellTextStyle, DS.ARGS({ "row:int","col:int","val:str" }))
        .def("cellTextHeight", &PyAcadTable::cellTextHeight, DS.ARGS({ "row:int","col:int" }))
        .def("setCellTextHeight", &PyAcadTable::setCellTextHeight, DS.ARGS({ "row:int","col:int","val:float" }))
        .def("textRotation", &PyAcadTable::textRotation, DS.ARGS({ "row:int","col:int" }))
        .def("setTextRotation", &PyAcadTable::setTextRotation, DS.ARGS({ "row:int","col:int","val:PyAx.AcRotationAngle" }))
        .def("autoScale", &PyAcadTable::autoScale, DS.ARGS({ "row:int","col:int" }))
        .def("setAutoScale", &PyAcadTable::setAutoScale, DS.ARGS({ "row:int","col:int","val:bool" }))
        .def("blockTableRecordId", &PyAcadTable::blockTableRecordId1)
        .def("blockTableRecordId", &PyAcadTable::blockTableRecordId2, DS.OVRL(blockTableRecordIdOverloads))
        .def("setBlockTableRecordId", &PyAcadTable::setBlockTableRecordId1)
        .def("setBlockTableRecordId", &PyAcadTable::setBlockTableRecordId2, DS.OVRL(setBlockTableRecordIdOverloads))
        .def("blockScale", &PyAcadTable::blockScale, DS.ARGS({ "row:int","col:int" }))
        .def("setBlockScale", &PyAcadTable::setBlockScale, DS.ARGS({ "row:int","col:int","val:float" }))
        .def("blockRotation", &PyAcadTable::blockRotation, DS.ARGS({ "row:int","col:int" }))
        .def("setBlockRotation", &PyAcadTable::setBlockRotation, DS.ARGS({ "row:int","col:int","val:float" }))
        .def("blockAttributeValue", &PyAcadTable::blockAttributeValue1)
        .def("blockAttributeValue", &PyAcadTable::blockAttributeValue2, DS.OVRL(blockAttributeValueOverloads))
        .def("setBlockAttributeValue", &PyAcadTable::setBlockAttributeValue1)
        .def("setBlockAttributeValue", &PyAcadTable::setBlockAttributeValue2, DS.OVRL(setBlockAttributeValueOverloads))
        .def("cellGridLineWeight", &PyAcadTable::cellGridLineWeight, DS.ARGS({ "row:int","col:int","mask:PyAx.AcCellEdgeMask" }))
        .def("setCellGridLineWeight", &PyAcadTable::setCellGridLineWeight, DS.ARGS({ "row:int","col:int","mask:PyAx.AcCellEdgeMask","lw:PyAx.AcLineWeight" }))
        .def("cellGridColor", &PyAcadTable::cellGridColor, DS.ARGS({ "row:int","col:int","mask:PyAx.AcCellEdgeMask" }))
        .def("setCellGridColor", &PyAcadTable::setCellGridColor, DS.ARGS({ "row:int","col:int","mask:PyAx.AcCellEdgeMask","val:PyAx.AcadAcCmColor" }))
        .def("cellGridVisibility", &PyAcadTable::cellGridVisibility, DS.ARGS({ "row:int","col:int","mask:PyAx.AcCellEdgeMask" }))
        .def("setCellGridVisibility", &PyAcadTable::setCellGridVisibility, DS.ARGS({ "row:int","col:int","mask:PyAx.AcCellEdgeMask","val:bool" }))
        .def("insertColumns", &PyAcadTable::insertColumns, DS.ARGS({ "col:int","width:float","rows:int" }))
        .def("deleteColumns", &PyAcadTable::deleteColumns, DS.ARGS({ "col:int","cols:int" }))
        .def("insertRows", &PyAcadTable::insertRows, DS.ARGS({ "row:int","width:float","rows:int" }))
        .def("deleteRows", &PyAcadTable::deleteRows, DS.ARGS({ "row:int","rows:int" }))
        .def("mergeCells", &PyAcadTable::deleteRows, DS.ARGS({ "minRow:int","maxRow:int", "minCol:int","maxCol:int" }))
        .def("unmergeCells", &PyAcadTable::unmergeCells, DS.ARGS({ "minRow:int","maxRow:int", "minCol:int","maxCol:int" }))
        .def("isMergedCell", &PyAcadTable::isMergedCell, DS.ARGS({ "row:int","col:int" }))
        .def("fieldId", &PyAcadTable::fieldId1)
        .def("fieldId", &PyAcadTable::fieldId2, DS.OVRL(fieldIdOverloads))
        .def("setFieldId", &PyAcadTable::setFieldId1)
        .def("setFieldId", &PyAcadTable::setFieldId2, DS.OVRL(setFieldIdOverloads))
        .def("generateLayout", &PyAcadTable::generateLayout, DS.ARGS())
        .def("recomputeTableBlock", &PyAcadTable::recomputeTableBlock, DS.ARGS({ "bForceUpdate:bool" }))
        .def("hitTest", &PyAcadTable::hitTest, DS.ARGS({ "wpt:PyGe.Point3d","wviewVec:PyGe.Vector3d" }))
        .def("select", &PyAcadTable::hitTest, DS.ARGS({ "wpt:PyGe.Point3d","wvwVec:PyGe.Vector3d","wvwxVec:PyGe.Vector3d","wxaper:float" ,"wyaper:float" ,"allowOutside:bool" }))
        .def("selectSubRegion", &PyAcadTable::selectSubRegion, DS.ARGS({ "wpt1:PyGe.Point3d", "wpt2:PyGe.Point3d","wvwVec:PyGe.Vector3d","wvwxVec:PyGe.Vector3d","seltype:PyAx.AcSelectType","bIncludeCurrent:bool" }))
        .def("subSelection", &PyAcadTable::subSelection, DS.ARGS())
        .def("setSubSelection", &PyAcadTable::setSubSelection, DS.ARGS({ "minRow:int","maxRow:int", "minCol:int","maxCol:int" }))
        .def("reselectSubRegion", &PyAcadTable::reselectSubRegion, DS.ARGS())
        .def("clearSubSelection", &PyAcadTable::clearSubSelection, DS.ARGS())
        .def("hasSubSelection", &PyAcadTable::hasSubSelection, DS.ARGS())
        .def("regenerateTableSuppressed", &PyAcadTable::regenerateTableSuppressed, DS.ARGS())
        .def("setRegenerateTableSuppressed", &PyAcadTable::setRegenerateTableSuppressed, DS.ARGS({ "val:bool" }))
        .def("formatValue", &PyAcadTable::formatValue, DS.ARGS({ "row:int","col:int","val:PyAx.AcFormatOption" }))
        .def("cellDataType", &PyAcadTable::cellDataType, DS.ARGS({ "row:int","col:int" }))
        .def("setCellDataType", &PyAcadTable::setCellDataType, DS.ARGS({ "row:int","col:int","dataType:PyAx.AcValueDataType","unitType:PyAx.AcValueUnitType" }))
        .def("cellFormat", &PyAcadTable::cellFormat, DS.ARGS({ "row:int","col:int" }))
        .def("setCellFormat", &PyAcadTable::setCellFormat, DS.ARGS({ "row:int","col:int","fmt:str" }))
        .def("cellValue", &PyAcadTable::cellValue, DS.ARGS({ "row:int","col:int" }))
        .def("setCellValue", &PyAcadTable::setCellValue, DS.ARGS({ "row:int","col:int","val:PyDb.AcValue" }))
        .def("value", &PyAcadTable::value, DS.ARGS({ "row:int","col:int","nContent:int" }))
        .def("setValue", &PyAcadTable::setValue, DS.ARGS({ "row:int","col:int","nContent:int","val:PyDb.AcValue" }))
        .def("setCellValueFromText", &PyAcadTable::setCellValueFromText, DS.ARGS({ "row:int","col:int","val:str","nOption:PyAx.AcParseOption" }))
        .def("dataFormat", &PyAcadTable::dataFormat, DS.ARGS({ "row:int","col:int","nContent:int" }))
        .def("setDataFormat", &PyAcadTable::setDataFormat, DS.ARGS({ "row:int","col:int","nContent:int","val:str" }))
        .def("textString", &PyAcadTable::textString, DS.ARGS({ "row:int","col:int","nContent:int" }))
        .def("setTextString", &PyAcadTable::setTextString, DS.ARGS({ "row:int","col:int","nContent:int","val:str" }))
        .def("customData", &PyAcadTable::textString, DS.ARGS({ "row:int","col:int","key:str" }))
        .def("setCustomData", &PyAcadTable::setCustomData, DS.ARGS({ "row:int","col:int","key:str","val:PyDb.AcValue" }))
        .def("cellStyle", &PyAcadTable::cellStyle, DS.ARGS({ "row:int","col:int" }))
        .def("setCellStyle", &PyAcadTable::setCellStyle, DS.ARGS({ "row:int","col:int","style:str" }))
        .def("contentColor", &PyAcadTable::contentColor2, DS.ARGS({ "row:int","col:int","nContent:int" }))
        .def("setContentColor", &PyAcadTable::setContentColor2, DS.ARGS({ "row:int","col:int","nContent:int","val:PyAx.AcadAcCmColor" }))
        .def("dataType", &PyAcadTable::dataType2, DS.ARGS({ "row:int","col:int","nContent:int" }))
        .def("setDataType", &PyAcadTable::setDataType2, DS.ARGS({ "row:int","col:int","nContent:int","dataType:PyAx.AcValueDataType","unitType:PyAx.AcValueUnitType" }))
        .def("textStyle", &PyAcadTable::textStyle2, DS.ARGS({ "row:int","col:int","nContent:int" }))
        .def("setTextStyle", &PyAcadTable::setTextStyle2, DS.ARGS({ "row:int","col:int","nContent:int","style:str" }))
        .def("textHeight", &PyAcadTable::textHeight2, DS.ARGS({ "row:int","col:int","nContent:int" }))
        .def("setTextHeight", &PyAcadTable::setTextHeight2, DS.ARGS({ "row:int","col:int","nContent:int","val:float" }))
        .def("rotation", &PyAcadTable::rotation, DS.ARGS({ "row:int","col:int","nContent:int" }))
        .def("setRotation", &PyAcadTable::setRotation, DS.ARGS({ "row:int","col:int","nContent:int","val:float" }))
        .def("autoScale", &PyAcadTable::autoScale, DS.ARGS({ "row:int","col:int","nContent:int" }))
        .def("setAutoScale", &PyAcadTable::setAutoScale2, DS.ARGS({ "row:int","col:int","nContent:int","val:bool" }))
        .def("scale", &PyAcadTable::scale, DS.ARGS({ "row:int","col:int","nContent:int" }))
        .def("setScale", &PyAcadTable::setScale, DS.ARGS({ "row:int","col:int","nContent:int","val:float" }))
        .def("removeAllOverrides", &PyAcadTable::removeAllOverrides, DS.ARGS({ "row:int","col:int" }))
        .def("gridLineWeight", &PyAcadTable::gridLineWeight2, DS.ARGS({ "row:int","col:int","lt:PyAx.AcGridLineType" }))
        .def("setGridLineWeight", &PyAcadTable::setGridLineWeight2, DS.ARGS({ "row:int","col:int","lt:PyAx.AcGridLineType","lw:PyAx.AcLineWeight" }))
        .def("gridLinetype", &PyAcadTable::gridLinetype, DS.ARGS({ "row:int","col:int","lt:PyAx.AcGridLineType" }))
        .def("setGridLinetype", &PyAcadTable::setGridLinetype, DS.ARGS({ "row:int","col:int","lt:PyAx.AcGridLineType","val:PyDb.ObjectId" }))
        .def("gridColor", &PyAcadTable::gridColor2, DS.ARGS({ "row:int","col:int","lt:PyAx.AcGridLineType" }))
        .def("setGridColor", &PyAcadTable::setGridColor2, DS.ARGS({ "row:int","col:int","lt:PyAx.AcGridLineType","val:PyAx.AcadAcCmColor" }))
        .def("gridVisibility", &PyAcadTable::gridVisibility2, DS.ARGS({ "row:int","col:int","lt:PyAx.AcGridLineType" }))
        .def("setGridVisibility", &PyAcadTable::setGridVisibility2, DS.ARGS({ "row:int","col:int","lt:PyAx.AcGridLineType","val:bool" }))
        .def("gridDoubleLineSpacing", &PyAcadTable::gridDoubleLineSpacing, DS.ARGS({ "row:int","col:int","lt:PyAx.AcGridLineType" }))
        .def("setGridDoubleLineSpacing", &PyAcadTable::setGridDoubleLineSpacing, DS.ARGS({ "row:int","col:int","lt:PyAx.AcGridLineType","val:float" }))
        .def("setEnableBreak", &PyAcadTable::setEnableBreak, DS.ARGS({ "val:bool" }))
        .def("breakHeight", &PyAcadTable::breakHeight, DS.ARGS({ "idx:int" }))
        .def("setBreakHeight", &PyAcadTable::setBreakHeight, DS.ARGS({ "idx:int","val:float" }))
        .def("contentType", &PyAcadTable::contentType, DS.ARGS({ "row:int","col:int" }))
        .def("margin", &PyAcadTable::margin, DS.ARGS({ "row:int","col:int","margin:PyAx.AcCellMargin" }))
        .def("setMargin", &PyAcadTable::setMargin, DS.ARGS({ "row:int","col:int","margin:PyAx.AcCellMargin", "val:float" }))
        .def("contentLayout", &PyAcadTable::contentLayout, DS.ARGS({ "row:int","col:int" }))
        .def("setContentLayout", &PyAcadTable::setContentLayout, DS.ARGS({ "row:int","col:int","val:PyAx.AcCellContentLayout" }))
        .def("override", &PyAcadTable::_override, DS.ARGS({ "row:int","col:int","nContent:int" }))
        .def("setOverride", &PyAcadTable::setOverride, DS.ARGS({ "row:int","col:int","nContent:int","val:PyAx.AcCellProperty" }))
        .def("gridLineStyle", &PyAcadTable::gridLineStyle, DS.ARGS({ "row:int","col:int","lt:PyAx.AcGridLineType" }))
        .def("setGridLineStyle", &PyAcadTable::setGridLineStyle, DS.ARGS({ "row:int","col:int","lt:PyAx.AcGridLineType" ,"val:PyAx.AcGridLineStyle" }))
        .def("insertRowsAndInherit", &PyAcadTable::insertRowsAndInherit, DS.ARGS({ "nIndex:int","nInheritFrom:int","nNumRows:int" }))
        .def("insertColumnsAndInherit", &PyAcadTable::insertColumnsAndInherit, DS.ARGS({ "nIndex:int","nInheritFrom:int","nNumCols:int" }))
        .def("hasFormula", &PyAcadTable::hasFormula, DS.ARGS({ "row:int","col:int","nContent:int" }))
        .def("formula", &PyAcadTable::formula, DS.ARGS({ "row:int","col:int","nContent:int" }))
        .def("setFormula", &PyAcadTable::setFormula, DS.ARGS({ "row:int","col:int","nContent:int","val:str" }))
        .def("isContentEditable", &PyAcadTable::isContentEditable, DS.ARGS({ "row:int","col:int" }))
        .def("isFormatEditable", &PyAcadTable::isFormatEditable, DS.ARGS({ "row:int","col:int" }))
        .def("cellState", &PyAcadTable::cellState, DS.ARGS({ "row:int","col:int" }))
        .def("setCellState", &PyAcadTable::setCellState, DS.ARGS({ "row:int","col:int","val:PyAx.AcCellState" }))
        .def("enableMergeAll", &PyAcadTable::enableMergeAll, DS.ARGS({ "row:int","col:int","val:bool" }))
        .def("isMergeAllEnabled", &PyAcadTable::isMergeAllEnabled, DS.ARGS({ "row:int","col:int" }))
        .def("breaksEnabled", &PyAcadTable::breaksEnabled, DS.ARGS())
        .def("setBreaksEnabled", &PyAcadTable::setBreaksEnabled, DS.ARGS({ "val:bool" }))
        .def("repeatTopLabels", &PyAcadTable::repeatTopLabels, DS.ARGS())
        .def("setRepeatTopLabels", &PyAcadTable::setRepeatTopLabels, DS.ARGS({ "val:bool" }))
        .def("repeatBottomLabels", &PyAcadTable::repeatBottomLabels, DS.ARGS())
        .def("setRepeatBottomLabels", &PyAcadTable::setRepeatBottomLabels, DS.ARGS({ "val:bool" }))
        .def("tableBreakFlowDirection", &PyAcadTable::tableBreakFlowDirection, DS.ARGS())
        .def("setTableBreakFlowDirection", &PyAcadTable::setTableBreakFlowDirection, DS.ARGS({ "val:PyAx.AcTableFlowDirection" }))
        .def("allowManualPositions", &PyAcadTable::allowManualPositions, DS.ARGS())
        .def("setAllowManualPositions", &PyAcadTable::setAllowManualPositions, DS.ARGS({ "val:bool" }))
        .def("allowManualHeights", &PyAcadTable::allowManualHeights, DS.ARGS())
        .def("setAllowManualHeights", &PyAcadTable::setAllowManualHeights, DS.ARGS({ "val:bool" }))
        .def("tableBreakHeight", &PyAcadTable::tableBreakHeight, DS.ARGS())
        .def("setTableBreakHeight", &PyAcadTable::setTableBreakHeight, DS.ARGS({ "val:float" }))
        .def("breakSpacing", &PyAcadTable::breakSpacing, DS.ARGS())
        .def("setBreakSpacing", &PyAcadTable::setBreakSpacing, DS.ARGS({ "val:float" }))
        .def("columnName", &PyAcadTable::breakSpacing, DS.ARGS({ "col:int" }))
        .def("setColumnName", &PyAcadTable::setColumnName, DS.ARGS({ "col:int" ,"val:str" }))
        .def("setToolTip", &PyAcadTable::setToolTip, DS.ARGS({ "row:int", "col:int" ,"val:str" }))
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
        pylist.append(val);
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
        pylist.append(val);
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
        pylist.append(val);
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

PyDbObjectId PyAcadTable::blockTableRecordId1(int row, int col) const
{
    return PyDbObjectId{ impObj()->GetBlockTableRecordId(row, col) };
}

void PyAcadTable::setBlockTableRecordId1(int row, int col, const PyDbObjectId& val, bool autoScale) const
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

std::string PyAcadTable::blockAttributeValue1(int row, int col, const PyDbObjectId& val) const
{
    return wstr_to_utf8(impObj()->GetBlockAttributeValue(row, col, val.m_id));
}

void PyAcadTable::setBlockAttributeValue1(int row, int col, const PyDbObjectId& id, const std::string& val) const
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

PyDbObjectId PyAcadTable::fieldId1(int row, int col) const
{
    return impObj()->GetFieldId(col, row);
}

void PyAcadTable::setFieldId1(int row, int col, const PyDbObjectId& id) const
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