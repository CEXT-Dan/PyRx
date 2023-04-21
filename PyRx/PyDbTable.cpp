#include "stdafx.h"
#include "PyDbTable.h"
#include "PyDbObjectId.h"

using namespace boost::python;


//-----------------------------------------------------------------------------------
//PyDbTable
void makeyDbTableWrapper()
{
    class_<PyDbTable, bases<PyDbBlockReference>>("Table")
        .def(init<>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("tableStyle", &PyDbTable::tableStyle)
        .def("setTableStyle", &PyDbTable::setTableStyle)
        .def("direction", &PyDbTable::direction)
        .def("setDirection", &PyDbTable::setDirection)
        .def("numRows", &PyDbTable::numRows)
        .def("numColumns", &PyDbTable::numColumns)
        .def("width", &PyDbTable::width)
        .def("setWidth", &PyDbTable::setWidth)
        .def("columnWidth", &PyDbTable::columnWidth)
        .def("setColumnWidth", &PyDbTable::setColumnWidth1)
        .def("setColumnWidth", &PyDbTable::setColumnWidth2)
        .def("height", &PyDbTable::height)
        .def("setHeight", &PyDbTable::setHeight)
        .def("rowHeight", &PyDbTable::rowHeight)
        .def("setRowHeight", &PyDbTable::setRowHeight1)
        .def("setRowHeight", &PyDbTable::setRowHeight2)
        .def("minimumColumnWidth", &PyDbTable::minimumColumnWidth)
        .def("minimumRowHeight", &PyDbTable::minimumRowHeight)
        .def("minimumTableWidth", &PyDbTable::minimumTableWidth)
        .def("minimumTableHeight", &PyDbTable::minimumTableHeight)
        .def("horzCellMargin", &PyDbTable::horzCellMargin)
        .def("setHorzCellMargin", &PyDbTable::setHorzCellMargin)
        .def("vertCellMargin", &PyDbTable::vertCellMargin)
        .def("setVertCellMargin", &PyDbTable::setVertCellMargin)
        .def("flowDirection", &PyDbTable::flowDirection)
        .def("setFlowDirection", &PyDbTable::setFlowDirection)
        .def("isTitleSuppressed", &PyDbTable::isTitleSuppressed)
        .def("suppressTitleRow", &PyDbTable::suppressTitleRow)
        .def("isHeaderSuppressed", &PyDbTable::isHeaderSuppressed)
        .def("suppressHeaderRow", &PyDbTable::suppressHeaderRow)
        .def("alignment", &PyDbTable::alignment)
        .def("setAlignment", &PyDbTable::setAlignment)
        .def("isBackgroundColorNone", &PyDbTable::isBackgroundColorNone)
        .def("setBackgroundColorNone", &PyDbTable::setBackgroundColorNone)
        .def("backgroundColor", &PyDbTable::backgroundColor)
        .def("setBackgroundColor", &PyDbTable::setBackgroundColor)
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
        .def("setFormat", &PyDbTable::setFormat)
        .def("textString", &PyDbTable::textString)
        .def("textString", &PyDbTable::textString3)
        .def("setTextString", &PyDbTable::setTextString)
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
        .def("blockScale", &PyDbTable::blockScale)
        .def("setBlockScale", &PyDbTable::setBlockScale)
        .def("blockRotation", &PyDbTable::blockRotation)
        .def("setBlockRotation", &PyDbTable::setBlockRotation)
        .def("gridColor", &PyDbTable::gridColor2)
        .def("setGridColor", &PyDbTable::setGridColor2)
        .def("gridVisibility", &PyDbTable::gridVisibility2)
        .def("setGridVisibility", &PyDbTable::setGridVisibility2)
        .def("gridLineWeight", &PyDbTable::gridLineWeight2)
        .def("setGridLineWeight", &PyDbTable::setGridLineWeight2)
        .def("insertColumns", &PyDbTable::insertColumns)
        .def("deleteColumns", &PyDbTable::deleteColumns)
        .def("insertRows", &PyDbTable::insertRows)
        .def("deleteRows", &PyDbTable::deleteRows)
        .def("mergeCells", &PyDbTable::mergeCells)
        .def("unmergeCells", &PyDbTable::unmergeCells)
        .def("isMergedCell", &PyDbTable::isMergedCell)
        .def("generateLayout", &PyDbTable::generateLayout)
        .def("recomputeTableBlock", &PyDbTable::recomputeTableBlock)
        .def("hitTest", &PyDbTable::hitTest)
        .def("getSubSelection", &PyDbTable::getSubSelection)
        .def("setSubSelection", &PyDbTable::setSubSelection)
        .def("clearSubSelection", &PyDbTable::clearSubSelection)
        .def("hasSubSelection", &PyDbTable::hasSubSelection)
        .def("setPosition", &PyDbTable::setPosition)
        .def("setNormal", &PyDbTable::setNormal)
        .def("setRegen", &PyDbTable::setRegen)
        .def("suppressInvisibleGrid", &PyDbTable::suppressInvisibleGrid)
        .def("isRegenerateTableSuppressed", &PyDbTable::isRegenerateTableSuppressed)
        .def("suppressRegenerateTable", &PyDbTable::suppressRegenerateTable)
        .def("setRecomputeTableBlock", &PyDbTable::setRecomputeTableBlock)
        .def("setSize", &PyDbTable::setSize)
        .def("canInsert", &PyDbTable::canInsert)
        .def("insertRowsAndInherit", &PyDbTable::insertRowsAndInherit)
        .def("insertColumnsAndInherit", &PyDbTable::insertColumnsAndInherit)
        .def("canDelete", &PyDbTable::canDelete)
        .def("isEmpty", &PyDbTable::isEmpty)
        .def("getMergeRange", &PyDbTable::getMergeRange)
        .def("isContentEditable", &PyDbTable::isContentEditable)
        .def("isFormatEditable", &PyDbTable::isFormatEditable)
        .def("cellState", &PyDbTable::cellState)
        .def("setCellState", &PyDbTable::setCellState)
        .def("numContents", &PyDbTable::numContents)
        .def("createContent", &PyDbTable::createContent)
        .def("moveContent", &PyDbTable::moveContent)
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
        .def("textString", &PyDbTable::textString4)
        .def("setTextString", &PyDbTable::setTextString2)
        .def("hasFormula", &PyDbTable::hasFormula)
        .def("getFormula", &PyDbTable::getFormula)
        .def("setFormula", &PyDbTable::setFormula)
        .def("fieldId", &PyDbTable::fieldId2)
        .def("setFieldId", &PyDbTable::setFieldId2)
        .def("blockTableRecordId", &PyDbTable::blockTableRecordId2)
        .def("setBlockTableRecordId", &PyDbTable::setBlockTableRecordId2)
        .def("getBlockAttributeValue", &PyDbTable::getBlockAttributeValue1)
        .def("getBlockAttributeValue", &PyDbTable::getBlockAttributeValue2)
        .def("setBlockAttributeValue", &PyDbTable::setBlockAttributeValue1)
        .def("setBlockAttributeValue", &PyDbTable::setBlockAttributeValue2)
        .def("cellStyle", &PyDbTable::cellStyle)
        .def("setCellStyle", &PyDbTable::setCellStyle)
        .def("margin", &PyDbTable::margin)
        .def("setMargin", &PyDbTable::setMargin)
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
        .def("scale", &PyDbTable::scale)
        .def("setScale", &PyDbTable::setScale)
        .def("contentLayout", &PyDbTable::contentLayout)
        .def("setContentLayout", &PyDbTable::setContentLayout)
        .def("isMergeAllEnabled", &PyDbTable::isMergeAllEnabled)
        .def("enableMergeAll", &PyDbTable::enableMergeAll)
        .def("getOverride", &PyDbTable::getOverride1)
        .def("getOverride", &PyDbTable::getOverride2)
        .def("setOverride", &PyDbTable::setOverride1)
        .def("setOverride", &PyDbTable::setOverride2)
        .def("removeAllOverrides", &PyDbTable::removeAllOverrides)
        .def("gridLineStyle", &PyDbTable::gridLineStyle)
        .def("setGridLineStyle", &PyDbTable::setGridLineStyle)
        .def("gridLineWeight", &PyDbTable::gridLineWeight3)
        .def("setGridLineWeight", &PyDbTable::setGridLineWeight3)
        .def("gridLinetype", &PyDbTable::gridLinetype)
        .def("setGridLinetype", &PyDbTable::setGridLinetype)
        .def("gridColor", &PyDbTable::gridColor3)
        .def("setGridColor", &PyDbTable::setGridColor3)
        .def("gridVisibility", &PyDbTable::gridVisibility3)
        .def("setGridVisibility3", &PyDbTable::setGridVisibility3)
        .def("gridDoubleLineSpacing", &PyDbTable::gridDoubleLineSpacing)
        .def("setGridDoubleLineSpacing", &PyDbTable::setGridDoubleLineSpacing)
        .def("getGridProperty", &PyDbTable::getGridProperty)
        .def("setGridProperty", &PyDbTable::setGridProperty1)
        .def("setGridProperty", &PyDbTable::setGridProperty2)
        .def("isLinked", &PyDbTable::isLinked)
        .def("getDataLink", &PyDbTable::getDataLink)
        .def("setDataLink", &PyDbTable::setDataLink)
        .def("getDataLinkRange", &PyDbTable::getDataLinkRange)
        .def("removeDataLink", &PyDbTable::removeDataLink1)
        .def("removeDataLink", &PyDbTable::removeDataLink2)
        .def("updateDataLink", &PyDbTable::updateDataLink1)
        .def("updateDataLink", &PyDbTable::updateDataLink2)
        .def("isBreakEnabled", &PyDbTable::isBreakEnabled)
        .def("enableBreak", &PyDbTable::enableBreak)
        .def("breakFlowDirection", &PyDbTable::breakFlowDirection)
        .def("setBreakFlowDirection", &PyDbTable::setBreakFlowDirection)
        .def("breakHeight", &PyDbTable::breakHeight)
        .def("setBreakHeight", &PyDbTable::setBreakHeight)
        .def("breakOffset", &PyDbTable::breakOffset)
        .def("setBreakOffset", &PyDbTable::setBreakOffset)
        .def("breakOption", &PyDbTable::breakOption)
        .def("setBreakOption", &PyDbTable::setBreakOption)
        .def("breakSpacing", &PyDbTable::breakSpacing)
        .def("setBreakSpacing", &PyDbTable::setBreakSpacing)
        .def("cellRange", &PyDbTable::cellRange)
        .def("className", &PyDbTable::className).staticmethod("className")
        ;
    class_ <AcCell>("Cell")
        .def_readwrite("row", &AcCell::mnRow)
        .def_readwrite("column", &AcCell::mnColumn)
        ;
    class_ <AcCellRange>("CellRange")
        .def_readwrite("topRow", &AcCellRange::mnTopRow)
        .def_readwrite("leftColumn", &AcCellRange::mnLeftColumn)
        .def_readwrite("bottomRow", &AcCellRange::mnBottomRow)
        .def_readwrite("rightColumn", &AcCellRange::mnRightColumn)
        ;
    enum_<AcDb::FlowDirection>("FlowDirection")
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
#ifndef BRXAPP
        .value("kAllRowTypes", AcDb::RowType::kAllRowTypes)
#endif // !BRXAPP
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
}

PyDbTable::PyDbTable()
    : PyDbTable(new AcDbTable(), true)
{
}

PyDbTable::PyDbTable(AcDbTable* ptr, bool autoDelete)
    : PyDbBlockReference(ptr, autoDelete)
{
}

PyDbTable::PyDbTable(const PyDbObjectId& id, AcDb::OpenMode mode)
{
    AcDbTable* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbTable>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    this->resetImp(pobj, false, true);
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
}

PyDbObjectId PyDbTable::tableStyle() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return PyDbObjectId(imp->tableStyle());
}

Acad::ErrorStatus PyDbTable::setTableStyle(const PyDbObjectId& id)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setTableStyle(id.m_id);
}

AcGeVector3d PyDbTable::direction() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->direction();
}

Acad::ErrorStatus PyDbTable::setDirection(const AcGeVector3d& horzVec)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setDirection(horzVec);
}

Adesk::UInt32 PyDbTable::numRows() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->numRows();
}

Adesk::UInt32 PyDbTable::numColumns() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->numColumns();
}

double PyDbTable::width() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->width();
}

Acad::ErrorStatus PyDbTable::setWidth(double width)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setWidth(width);
}

double PyDbTable::columnWidth(int col) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->columnWidth(col);
}

Acad::ErrorStatus PyDbTable::setColumnWidth1(int col, double width)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setColumnWidth(col, width);
}

Acad::ErrorStatus PyDbTable::setColumnWidth2(double width)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setColumnWidth(width);
}

double PyDbTable::height() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->height();
}

Acad::ErrorStatus PyDbTable::setHeight(double height)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setHeight(height);
}

double PyDbTable::rowHeight(int row) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->rowHeight(row);
}

Acad::ErrorStatus PyDbTable::setRowHeight1(int row, double height)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setRowHeight(row, height);
}

Acad::ErrorStatus PyDbTable::setRowHeight2(double height)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setRowHeight(height);
}

double PyDbTable::minimumColumnWidth(int col) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->minimumColumnWidth(col);
}

double PyDbTable::minimumRowHeight(int row) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->minimumColumnWidth(row);
}

double PyDbTable::minimumTableWidth() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->minimumTableWidth();
}

double PyDbTable::minimumTableHeight() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->minimumTableHeight();
}

double PyDbTable::horzCellMargin() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->horzCellMargin();
}

Acad::ErrorStatus PyDbTable::setHorzCellMargin(double gap)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setHorzCellMargin(gap);
}

double PyDbTable::vertCellMargin() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->vertCellMargin();
}

Acad::ErrorStatus PyDbTable::setVertCellMargin(double gap)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setVertCellMargin(gap);
}

AcDb::FlowDirection PyDbTable::flowDirection() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->flowDirection();
}

Acad::ErrorStatus PyDbTable::setFlowDirection(AcDb::FlowDirection flow)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setFlowDirection(flow);
}

bool PyDbTable::isTitleSuppressed() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isTitleSuppressed();
}

Acad::ErrorStatus PyDbTable::suppressTitleRow(bool value)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->suppressTitleRow(value);
}

bool PyDbTable::isHeaderSuppressed() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isHeaderSuppressed();
}

Acad::ErrorStatus PyDbTable::suppressHeaderRow(bool value)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->suppressHeaderRow(value);
}

AcDb::CellAlignment PyDbTable::alignment(AcDb::RowType type) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->alignment(type);
}

AcDb::CellAlignment PyDbTable::alignment2(int row, int col) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->alignment(row, col);
}

Acad::ErrorStatus PyDbTable::setAlignment(AcDb::CellAlignment align, AcDb::RowType rowTypes)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setAlignment(align, rowTypes);
}

Acad::ErrorStatus PyDbTable::setAlignment2(int row, int col, AcDb::CellAlignment align)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setAlignment(row, col, align);
}

bool PyDbTable::isBackgroundColorNone(AcDb::RowType type) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isBackgroundColorNone(type);
}

bool PyDbTable::isBackgroundColorNone2(int row, int col) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isBackgroundColorNone(row, col);
}

Acad::ErrorStatus PyDbTable::setBackgroundColorNone(bool value, AcDb::RowType type)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setBackgroundColorNone(value, type);
}

Acad::ErrorStatus PyDbTable::setBackgroundColorNone2(int row, int col, bool value)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setBackgroundColorNone(row, col, value);
}

AcCmColor PyDbTable::backgroundColor(AcDb::RowType type) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->backgroundColor(type);
}

Acad::ErrorStatus PyDbTable::setBackgroundColor(const AcCmColor& color, AcDb::RowType type)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setBackgroundColor(color, type);
}

AcCmColor PyDbTable::contentColor(AcDb::RowType type) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->contentColor(type);
}

AcCmColor PyDbTable::contentColor2(int row, int col) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->contentColor(row, col);
}

AcCmColor PyDbTable::contentColor3(int row, int col, int nContent) const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->contentColor(row, col, nContent);
#endif
}

Acad::ErrorStatus PyDbTable::setContentColor(const AcCmColor& color, AcDb::RowType type)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setContentColor(color, type);
}


Acad::ErrorStatus PyDbTable::setContentColor2(int row, int col, const AcCmColor& color)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setContentColor(row, col, color);
}

Acad::ErrorStatus PyDbTable::setContentColor3(int row, int col, int nContent, const AcCmColor& color)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setContentColor(row, col, nContent, color);
#endif
}

boost::python::list PyDbTable::cellStyleOverrides(int row, int col) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    AcDbIntArray overrides;
    boost::python::list l;
    imp->cellStyleOverrides(row, col, overrides);
    for (auto item : overrides)
        l.append(item);
    return l;
}

void PyDbTable::clearCellOverrides(int row, int column)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->clearCellOverrides(row, column);
}

Acad::ErrorStatus PyDbTable::deleteCellContent(int row, int col)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->deleteCellContent(row, col);
}

AcDb::RowType PyDbTable::rowType(int row) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->rowType(row);
}

boost::python::tuple PyDbTable::getDataType(AcDb::RowType type) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    AcValue::DataType nDataType;
    AcValue::UnitType nUnitType;
    if (auto es = imp->getDataType(nDataType, nUnitType, type); es != eOk)
        throw PyAcadErrorStatus(es);
    return boost::python::make_tuple(nDataType, nUnitType);
}

boost::python::tuple PyDbTable::getDataType2(int row, int col) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    AcValue::DataType nDataType;
    AcValue::UnitType nUnitType;
    if (auto es = imp->getDataType(row, col, nDataType, nUnitType); es != eOk)
        throw PyAcadErrorStatus(es);
    return boost::python::make_tuple(nDataType, nUnitType);
}

boost::python::tuple PyDbTable::getDataType3(int row, int col, int nContent) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    AcValue::DataType nDataType;
    AcValue::UnitType nUnitType;
    if (auto es = imp->getDataType(row, col, nContent, nDataType, nUnitType); es != eOk)
        throw PyAcadErrorStatus(es);
    return boost::python::make_tuple(nDataType, nUnitType);
}

Acad::ErrorStatus PyDbTable::setDataType1(AcValue::DataType nDataType, AcValue::UnitType nUnitType)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setDataType(nDataType, nUnitType);
}

Acad::ErrorStatus PyDbTable::setDataType2(AcValue::DataType nDataType, AcValue::UnitType nUnitType, AcDb::RowType type)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setDataType(nDataType, nUnitType, type);
}

Acad::ErrorStatus PyDbTable::setDataType3(int row, int col, AcValue::DataType nDataType, AcValue::UnitType nUnitType)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setDataType(row, col, nDataType, nUnitType);
}

Acad::ErrorStatus PyDbTable::setDataType4(int row, int col, int nContent, AcValue::DataType nDataType, AcValue::UnitType nUnitType)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setDataType(row, col, nContent, nDataType, nUnitType);
}


Acad::ErrorStatus PyDbTable::setFormat(int row, int col, const std::string& pszFormat)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setFormat(row, col, utf8_to_wstr(pszFormat).c_str());
#endif

}

std::string PyDbTable::textString(int row, int col) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return wstr_to_utf8(imp->textStringConst(row, col));
}


std::string PyDbTable::textString2(int row, int col, int nContent) const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return wstr_to_utf8(imp->textString(row, col, nContent));
#endif
}

std::string PyDbTable::textString3(int row, int col, AcValue::FormatOption nOption) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    AcString str;
    if (auto es = imp->textString(row, col, nOption, str); es != eOk)
        throw PyAcadErrorStatus(es);
    return wstr_to_utf8(str);
}

std::string PyDbTable::textString4(int row, int col, int nContent, AcValue::FormatOption nOption) const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    AcString str;
    if (auto es = imp->textString(row, col, nContent, nOption, str); es != eOk)
        throw PyAcadErrorStatus(es);
    return wstr_to_utf8(str);
#endif
}

Acad::ErrorStatus PyDbTable::setTextString(int row, int col, const std::string& text)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setTextString(row, col, utf8_to_wstr(text).c_str());
}

Acad::ErrorStatus PyDbTable::setTextString2(int row, int col, int nContent, const std::string& text)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setTextString(row, col, nContent, utf8_to_wstr(text).c_str());
}

PyDbObjectId PyDbTable::textStyle(AcDb::RowType type) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return PyDbObjectId(imp->textStyle(type));
}

PyDbObjectId PyDbTable::textStyle2(int row, int col) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return PyDbObjectId(imp->textStyle(row, col));
}

PyDbObjectId PyDbTable::textStyle3(int row, int col, int nContent) const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return PyDbObjectId(imp->textStyle(row, col, nContent));
#endif
}

Acad::ErrorStatus PyDbTable::setTextStyle(const PyDbObjectId& id, AcDb::RowType rowTypes)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setTextStyle(id.m_id, rowTypes);
}

Acad::ErrorStatus PyDbTable::setTextStyle2(int row, int col, const PyDbObjectId& id)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setTextStyle(row, col, id.m_id);
}

Acad::ErrorStatus PyDbTable::setTextStyle3(int row, int col, int nContent, const PyDbObjectId& id)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setTextStyle(row, col, nContent, id.m_id);
#endif
}

double PyDbTable::textHeight(AcDb::RowType type) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->textHeight(type);
}

double PyDbTable::textHeight2(int row, int col) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->textHeight(row, col);
}

double PyDbTable::textHeight3(int row, int col, int nContent) const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->textHeight(row, col, nContent);
#endif
}

Acad::ErrorStatus PyDbTable::setTextHeight(double height, AcDb::RowType rowTypes)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setTextHeight(height, rowTypes);
}

Acad::ErrorStatus PyDbTable::setTextHeight2(int row, int col, double height)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setTextHeight(row, col, height);
}

Acad::ErrorStatus PyDbTable::setTextHeight3(int row, int col, int nContent, double height)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setTextHeight(row, col, nContent, height);
#endif
}

AcDb::LineWeight PyDbTable::gridLineWeight(AcDb::GridLineType gridlineType, AcDb::RowType type) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->gridLineWeight(gridlineType, type);
}

AcDb::LineWeight PyDbTable::gridLineWeight2(int row, int col, AcDb::CellEdgeMask iEdge) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->gridLineWeight(row, col, iEdge);
}

AcDb::LineWeight PyDbTable::gridLineWeight3(int nRow, int nCol, AcDb::GridLineType nGridLineType) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->gridLineWeight(nRow, nCol, nGridLineType);
}

Acad::ErrorStatus PyDbTable::setGridLineWeight(AcDb::LineWeight lwt, int nBorders, int nRows)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setGridLineWeight(lwt, nBorders, nRows);
}

Acad::ErrorStatus PyDbTable::setGridLineWeight2(int row, int col, AcDb::CellEdgeMask nEdges, AcDb::LineWeight value)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setGridLineWeight(row, col, nEdges, value);
}

Acad::ErrorStatus PyDbTable::setGridLineWeight3(int nRow, int nCol, AcDb::GridLineType nGridLineTypes, AcDb::LineWeight nLineWeight)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setGridLineWeight(nRow, nCol, nGridLineTypes, nLineWeight);
}

AcCmColor PyDbTable::gridColor(AcDb::GridLineType gridlineType, AcDb::RowType type) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->gridColor(gridlineType, type);
}

AcCmColor PyDbTable::gridColor2(int row, int col, AcDb::CellEdgeMask iEdge) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->gridColor(row, col, iEdge);
}

AcCmColor PyDbTable::gridColor3(int nRow, int nCol, AcDb::GridLineType nGridLineType) const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->gridColor(nRow, nCol, nGridLineType);
#endif
}

Acad::ErrorStatus PyDbTable::setGridColor(const AcCmColor& color, int nBorders, int nRows)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setGridColor(color, nBorders, nRows);
}

Acad::ErrorStatus PyDbTable::setGridColor2(int row, int col, AcDb::CellEdgeMask nEdges, const AcCmColor& color)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setGridColor(row, col, nEdges, color);
}

Acad::ErrorStatus PyDbTable::setGridColor3(int nRow, int nCol, AcDb::GridLineType nGridlineTypes, const AcCmColor& color)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setGridColor(nRow, nCol, nGridlineTypes, color);
#endif
}

AcDb::Visibility PyDbTable::gridVisibility(AcDb::GridLineType gridlineType, AcDb::RowType type) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->gridVisibility(gridlineType, type);
}

AcDb::Visibility PyDbTable::gridVisibility2(int row, int col, AcDb::CellEdgeMask iEdge) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->gridVisibility(row, col, iEdge);
}

AcDb::Visibility PyDbTable::gridVisibility3(int nRow, int nCol, AcDb::GridLineType nGridLineType) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->gridVisibility(nRow, nCol, nGridLineType);
}

Acad::ErrorStatus PyDbTable::setGridVisibility(AcDb::Visibility visible, int nBorders, int nRows)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setGridVisibility(visible, nBorders, nRows);
}

Acad::ErrorStatus PyDbTable::setGridVisibility2(int row, int col, AcDb::CellEdgeMask iEdge, AcDb::Visibility value)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setGridVisibility(row, col, iEdge, value);
}

Acad::ErrorStatus PyDbTable::setGridVisibility3(int nRow, int nCol, AcDb::GridLineType nGridLineTypes, AcDb::Visibility nVisibility)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setGridVisibility(nRow, nCol, nGridLineTypes, nVisibility);
}

boost::python::list PyDbTable::tableStyleOverrides() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    AcDbIntArray overrides;
    boost::python::list l;
    imp->tableStyleOverrides(overrides);
    for (auto item : overrides)
        l.append(item);
    return l;
}

void PyDbTable::clearTableStyleOverrides()
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    imp->clearTableStyleOverrides();
}

AcDb::CellType PyDbTable::cellType(int row, int col) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->cellType(row, col);
}

Acad::ErrorStatus PyDbTable::setCellType(int row, int col, AcDb::CellType type)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setCellType(row, col, type);
}

boost::python::list PyDbTable::getCellExtents(int row, int col, bool isOuterCell) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    AcGePoint3dArray pts;
    boost::python::list l;
    if (auto es = imp->getCellExtents(row, col, isOuterCell, pts); es != eOk)
        throw PyAcadErrorStatus(es);
    for (const auto& item : pts)
        l.append(item);
    return l;
}

AcGePoint3d PyDbTable::attachmentPoint(int row, int col) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->attachmentPoint(row, col);
}

AcGePoint3d PyDbTable::attachmentPoint2(int row, int col, int content) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->attachmentPoint(row, col, content);
}

PyDbObjectId PyDbTable::fieldId(int row, int col) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return PyDbObjectId(imp->fieldId(row, col));
}

PyDbObjectId PyDbTable::fieldId2(int row, int col, int nContent) const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return PyDbObjectId(imp->fieldId(row, col, nContent));
#endif
}

Acad::ErrorStatus PyDbTable::setFieldId(int row, int col, const PyDbObjectId& fieldId)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setFieldId(row, col, fieldId.m_id);
}

Acad::ErrorStatus PyDbTable::setFieldId2(int row, int col, int nContent, const PyDbObjectId& fieldId, AcDb::CellOption nFlag)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setFieldId(row, col, nContent, fieldId.m_id, nFlag);
#endif
}

AcDb::RotationAngle PyDbTable::textRotation(int row, int col) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->textRotation(row, col);
}

Acad::ErrorStatus PyDbTable::setTextRotation(int row, int col, AcDb::RotationAngle rot)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setTextRotation(row, col, rot);
}

bool PyDbTable::isAutoScale(int row, int col) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isAutoScale(row, col);
}

bool PyDbTable::isAutoScale2(int row, int col, int nContent) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isAutoScale(row, col, nContent);
}

Acad::ErrorStatus PyDbTable::setAutoScale(int row, int col, bool autoFit)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setAutoScale(row, col, autoFit);
}

Acad::ErrorStatus PyDbTable::setAutoScale2(int row, int col, int nContent, bool autoFit)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setAutoScale(row, col, nContent, autoFit);
}

PyDbObjectId PyDbTable::blockTableRecordId(int row, int col) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return PyDbObjectId(imp->blockTableRecordId(row, col));
}

PyDbObjectId PyDbTable::blockTableRecordId2(int row, int col, int nContent) const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return PyDbObjectId(imp->blockTableRecordId(row, col, nContent));
#endif
}

Acad::ErrorStatus PyDbTable::setBlockTableRecordId(int row, int col, const PyDbObjectId& blkId, bool autoFit)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setBlockTableRecordId(row, col, blkId.m_id, autoFit);
}

Acad::ErrorStatus PyDbTable::setBlockTableRecordId2(int row, int col, int nContent, const PyDbObjectId& blkId, bool autoFit)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setBlockTableRecordId(row, col, nContent, blkId.m_id, autoFit);
#endif
}

double PyDbTable::blockScale(int row, int col) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->blockScale(row, col);
}

Acad::ErrorStatus PyDbTable::setBlockScale(int row, int col, double scale)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setBlockScale(row, col, scale);
}

double PyDbTable::blockRotation(int row, int col) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->blockRotation(row, col);
}

Acad::ErrorStatus PyDbTable::setBlockRotation(int row, int col, double rotAng)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setBlockRotation(row, col, rotAng);
}

Acad::ErrorStatus PyDbTable::insertColumns(int col, double width, int nCols)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->insertColumns(col, width, nCols);
}

Acad::ErrorStatus PyDbTable::deleteColumns(int col, int nCols)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->deleteColumns(col, nCols);
}

Acad::ErrorStatus PyDbTable::insertRows(int row, double height, int nRows)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->insertRows(row, height, nRows);
}

Acad::ErrorStatus PyDbTable::deleteRows(int row, int nRows)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->deleteRows(row, nRows);
}

Acad::ErrorStatus PyDbTable::mergeCells(int minRow, int maxRow, int minCol, int maxCol)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->mergeCells(minRow, maxRow, minCol, maxCol);
}

Acad::ErrorStatus PyDbTable::unmergeCells(int minRow, int maxRow, int minCol, int maxCol)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->unmergeCells(minRow, maxRow, minCol, maxCol);
}

boost::python::tuple PyDbTable::isMergedCell(int row, int col)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    int minRow = -1;
    int maxRow = -1;
    int minCol = -1;
    int maxCol = -1;
    bool flag = imp->isMergedCell(row, col, &minRow, &maxRow, &minCol, &maxCol);
    return boost::python::make_tuple(flag, minRow, maxRow, minCol, maxCol);
}

Acad::ErrorStatus PyDbTable::generateLayout()
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->generateLayout();
}

Acad::ErrorStatus PyDbTable::recomputeTableBlock(bool forceUpdate)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->recomputeTableBlock(forceUpdate);
}

boost::python::tuple PyDbTable::hitTest(const AcGePoint3d& wpt, const AcGeVector3d& wviewVec, double wxaper, double wyaper)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    int resultRowIndex = -1;
    int resultColumnIndex = -1;
    int contentIndex = -1;
    AcDb::TableHitItem nItem = AcDb::kTableHitNone;
    bool flag = imp->hitTest(wpt, wviewVec, wxaper, wyaper, resultRowIndex, resultColumnIndex, contentIndex, nItem);
    return boost::python::make_tuple(flag, resultRowIndex, resultColumnIndex, contentIndex, nItem);
#endif
}

AcCellRange PyDbTable::getSubSelection(void) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->getSubSelection();
}

Acad::ErrorStatus PyDbTable::setSubSelection(const AcCellRange& range)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setSubSelection(range);
#endif
}

void PyDbTable::clearSubSelection()
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    imp->clearSubSelection();
}

bool PyDbTable::hasSubSelection() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->hasSubSelection();
}

Acad::ErrorStatus PyDbTable::setPosition(const AcGePoint3d& newVal)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setPosition(newVal);
}

Acad::ErrorStatus PyDbTable::setNormal(const AcGeVector3d& newVal)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setNormal(newVal);
}

void PyDbTable::setRegen()
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    imp->setRegen();
}

void PyDbTable::suppressInvisibleGrid(bool value)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    imp->suppressInvisibleGrid(value);
}

bool PyDbTable::isRegenerateTableSuppressed() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isRegenerateTableSuppressed();
}

void PyDbTable::suppressRegenerateTable(bool bSuppress)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    imp->suppressRegenerateTable(bSuppress);
}

void PyDbTable::setRecomputeTableBlock(bool newVal)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    imp->setRecomputeTableBlock(newVal);
#endif
}

Acad::ErrorStatus PyDbTable::setSize(int nRows, int nCols)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setSize(nRows, nCols);
}

bool PyDbTable::canInsert(int nIndex, bool bRow) const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->canInsert(nIndex, bRow);
#endif
}

Acad::ErrorStatus PyDbTable::insertRowsAndInherit(int nIndex, int nInheritFrom, int nNumRows)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->insertRowsAndInherit(nIndex, nInheritFrom, nNumRows);
}

Acad::ErrorStatus PyDbTable::insertColumnsAndInherit(int col, int nInheritFrom, int nNumCols)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->insertRowsAndInherit(col, nInheritFrom, nNumCols);
}

bool PyDbTable::canDelete(int nIndex, int nCount, bool bRow) const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->canDelete(nIndex, nCount, bRow);
#endif
}

bool PyDbTable::isEmpty(int nRow, int nCol) const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isEmpty(nRow, nCol);
#endif
}

AcCellRange PyDbTable::getMergeRange(int nRow, int nCol) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->getMergeRange(nRow, nCol);
}

bool PyDbTable::isContentEditable(int nRow, int nCol) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isContentEditable(nRow, nCol);
}

bool PyDbTable::isFormatEditable(int nRow, int nCol) const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isFormatEditable(nRow, nCol);
#endif
}

AcDb::CellState PyDbTable::cellState(int nRow, int nCol) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->cellState(nRow, nCol);
}

Acad::ErrorStatus PyDbTable::setCellState(int nRow, int nCol, AcDb::CellState nLock)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setCellState(nRow, nCol, nLock);
}

int PyDbTable::numContents(int nRow, int nCol) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->numContents(nRow, nCol);
}

int PyDbTable::createContent(int nRow, int nCol, int nIndex)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->createContent(nRow, nCol, nIndex);
}

Acad::ErrorStatus PyDbTable::moveContent(int nRow, int nCol, int nFromIndex, int nToIndex)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->moveContent(nRow, nCol, nFromIndex, nToIndex);
#endif
}

Acad::ErrorStatus PyDbTable::deleteContent1(int nRow, int nCol)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->deleteContent(nRow, nCol);
}

Acad::ErrorStatus PyDbTable::deleteContent2(int nRow, int nCol, int nIndex)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->deleteContent(nRow, nCol, nIndex);
}

Acad::ErrorStatus PyDbTable::deleteContent3(const AcCellRange& range)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->deleteContent(range);
}

AcDb::CellContentType PyDbTable::contentType1(int nRow, int nCol) const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->contentType(nRow, nCol);
#endif
}

AcDb::CellContentType PyDbTable::contentType2(int nRow, int nCol, int nIndex) const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->contentType(nRow, nCol, nIndex);
#endif
}

std::string PyDbTable::dataFormat1(int row, int col) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return wstr_to_utf8(imp->dataFormat(row, row));
}

std::string PyDbTable::dataFormat2(int row, int col, int nContent) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return wstr_to_utf8(imp->dataFormat(row, row, nContent));
}

Acad::ErrorStatus PyDbTable::setDataFormat1(int row, int col, const std::string& pszFormat)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setDataFormat(row, col, utf8_to_wstr(pszFormat).c_str());
}

Acad::ErrorStatus PyDbTable::setDataFormat2(int row, int col, int nContent, const std::string& pszFormat)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setDataFormat(row, col, nContent, utf8_to_wstr(pszFormat).c_str());
}

bool PyDbTable::hasFormula(int nRow, int nCol, int nContent) const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->hasFormula(nRow, nCol, nContent);
#endif
}

std::string PyDbTable::getFormula(int nRow, int nCol, int nContent) const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return wstr_to_utf8(imp->getFormula(nRow, nCol, nContent));
#endif
}

Acad::ErrorStatus PyDbTable::setFormula(int nRow, int nCol, int nContent, const std::string& pszFormula)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setFormula(nRow, nCol, nContent, utf8_to_wstr(pszFormula).c_str());
#endif
}

std::string PyDbTable::getBlockAttributeValue1(int row, int col, const PyDbObjectId& attdefId) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    ACHAR* val = nullptr;
    if (auto es = imp->getBlockAttributeValue(row, col, attdefId.m_id, val); es != eOk)
        throw PyAcadErrorStatus(es);
    std::string sval = wstr_to_utf8(val);
    acutDelString(val);
    return sval;
}

std::string PyDbTable::getBlockAttributeValue2(int row, int col, int nContent, const PyDbObjectId& attdefId) const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    ACHAR* val = nullptr;
    if (auto es = imp->getBlockAttributeValue(row, col, nContent, attdefId.m_id, val); es != eOk)
        throw PyAcadErrorStatus(es);
    std::string sval = wstr_to_utf8(val);
    acutDelString(val);
    return sval;
#endif
}

Acad::ErrorStatus PyDbTable::setBlockAttributeValue1(int row, int col, const PyDbObjectId& attdefId, const std::string& value)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setBlockAttributeValue(row, col, attdefId.m_id, utf8_to_wstr(value).c_str());
}

Acad::ErrorStatus PyDbTable::setBlockAttributeValue2(int row, int col, int nContent, const PyDbObjectId& attdefId, const std::string& value)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setBlockAttributeValue(row, col, nContent, attdefId.m_id, utf8_to_wstr(value).c_str());
#endif
}

const std::string PyDbTable::cellStyle(int nRow, int nCol) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return wstr_to_utf8(imp->cellStyle(nRow, nCol));
}

Acad::ErrorStatus PyDbTable::setCellStyle(int nRow, int nCol, const std::string& pszCellStyle)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setCellStyle(nRow, nCol, utf8_to_wstr(pszCellStyle).c_str());
}

double PyDbTable::margin(int nRow, int nCol, AcDb::CellMargin nMargin) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->margin(nRow, nCol, nMargin);
}

Acad::ErrorStatus PyDbTable::setMargin(int nRow, int nCol, AcDb::CellMargin nMargins, double fMargin)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setMargin(nRow, nCol, nMargins, fMargin);
}

double PyDbTable::rotation(void) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->rotation();
}

double PyDbTable::rotation2(int row, int col, int nContent) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->rotation(row, col, nContent);
}

Acad::ErrorStatus PyDbTable::setRotation(double fAngle)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setRotation(fAngle);
}

Acad::ErrorStatus PyDbTable::setRotation2(int row, int col, int nContent, double fAngle)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setRotation(row, col, nContent, fAngle);
}

double PyDbTable::scale(int row, int col, int nContent) const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->scale(row, col, nContent);
#endif
}

Acad::ErrorStatus PyDbTable::setScale(int row, int col, int nContent, double scale)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setScale(row, col, nContent, scale);
#endif
}

AcDb::CellContentLayout PyDbTable::contentLayout(int row, int col) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->contentLayout(row, col);
}

Acad::ErrorStatus PyDbTable::setContentLayout(int row, int col, AcDb::CellContentLayout nLayout)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setContentLayout(row, col, nLayout);
}

bool PyDbTable::isMergeAllEnabled(int nRow, int nCol) const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isMergeAllEnabled(nRow, nCol);
#endif
}

Acad::ErrorStatus PyDbTable::enableMergeAll(int nRow, int nCol, bool bEnable)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->enableMergeAll(nRow, nCol, bEnable);
#endif
}

AcDb::CellProperty PyDbTable::getOverride1(int nRow, int nCol, int nContent) const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->getOverride(nRow, nCol, nContent);
#endif
}

AcDb::GridProperty PyDbTable::getOverride2(int nRow, int nCol, AcDb::GridLineType nGridLineType) const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->getOverride(nRow, nCol, nGridLineType);
#endif
}

Acad::ErrorStatus PyDbTable::setOverride1(int nRow, int nCol, int nContent, AcDb::CellProperty nOverride)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setOverride(nRow, nCol, nContent, nOverride);
#endif
}

Acad::ErrorStatus PyDbTable::setOverride2(int nRow, int nCol, AcDb::GridLineType nGridLineType, AcDb::GridProperty nOverride)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setOverride(nRow, nCol, nGridLineType, nOverride);
#endif
}

Acad::ErrorStatus PyDbTable::removeAllOverrides(int nRow, int nCol)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->removeAllOverrides(nRow, nCol);
#endif
}

AcDb::GridLineStyle PyDbTable::gridLineStyle(int nRow, int nCol, AcDb::GridLineType nGridLineType) const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->gridLineStyle(nRow, nCol, nGridLineType);
#endif
}

Acad::ErrorStatus PyDbTable::setGridLineStyle(int nRow, int nCol, AcDb::GridLineType nGridLineTypes, AcDb::GridLineStyle nLineStyle)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setGridLineStyle(nRow, nCol, nGridLineTypes, nLineStyle);
#endif
}

PyDbObjectId PyDbTable::gridLinetype(int nRow, int nCol, AcDb::GridLineType nGridLineType) const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return PyDbObjectId(imp->gridLinetype(nRow, nCol, nGridLineType));
#endif
}

Acad::ErrorStatus PyDbTable::setGridLinetype(int nRow, int nCol, AcDb::GridLineType nGridLineTypes, const PyDbObjectId& idLinetype)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setGridLinetype(nRow, nCol, nGridLineTypes, idLinetype.m_id);
#endif
}

double PyDbTable::gridDoubleLineSpacing(int nRow, int nCol, AcDb::GridLineType nGridLineType) const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->gridDoubleLineSpacing(nRow, nCol, nGridLineType);
#endif
}

Acad::ErrorStatus PyDbTable::setGridDoubleLineSpacing(int nRow, int nCol, AcDb::GridLineType nGridLineTypes, double fSpacing)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setGridDoubleLineSpacing(nRow, nCol, nGridLineTypes, fSpacing);
#endif
}

AcGridProperty PyDbTable::getGridProperty(int nRow, int nCol, AcDb::GridLineType nGridLineType) const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    AcGridProperty prop;
    if (auto es = imp->getGridProperty(nRow, nCol, nGridLineType, prop); es != eOk)
        throw PyAcadErrorStatus(es);
    return prop;
#endif
}

Acad::ErrorStatus PyDbTable::setGridProperty1(int nRow, int nCol, AcDb::GridLineType nGridLineTypes, const AcGridProperty& gridProp)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setGridProperty(nRow, nCol, nGridLineTypes, gridProp);
#endif
}

Acad::ErrorStatus PyDbTable::setGridProperty2(const AcCellRange& rangeIn, AcDb::GridLineType nGridLineTypes, const AcGridProperty& gridProp)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setGridProperty(rangeIn, nGridLineTypes, gridProp);
#endif
}

bool PyDbTable::isLinked(int nRow, int nCol) const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isLinked(nRow, nCol);
#endif
}

PyDbObjectId PyDbTable::getDataLink(int nRow, int nCol) const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return  PyDbObjectId(imp->getDataLink(nRow, nCol));
#endif
}

Acad::ErrorStatus PyDbTable::setDataLink(const AcCellRange& range, const PyDbObjectId& idDataLink, bool bUpdate)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setDataLink(range, idDataLink.m_id, bUpdate);
#endif
}

AcCellRange PyDbTable::getDataLinkRange(int nRow, int nCol) const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->getDataLinkRange(nRow, nCol);
#endif
}

Acad::ErrorStatus PyDbTable::removeDataLink1(void)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->removeDataLink();
#endif
}

Acad::ErrorStatus PyDbTable::removeDataLink2(int nRow, int nCol)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->removeDataLink(nRow, nCol);
#endif
}

Acad::ErrorStatus PyDbTable::updateDataLink1(AcDb::UpdateDirection nDir, AcDb::UpdateOption nOption)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->updateDataLink(nDir, nOption);
#endif
}

Acad::ErrorStatus PyDbTable::updateDataLink2(int nRow, int nCol, AcDb::UpdateDirection nDir, AcDb::UpdateOption nOption)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->updateDataLink(nRow, nCol, nDir, nOption);
#endif
}

bool PyDbTable::isBreakEnabled(void) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isBreakEnabled();
}

Acad::ErrorStatus PyDbTable::enableBreak(bool bEnable)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->enableBreak(bEnable);
}

AcDb::TableBreakFlowDirection PyDbTable::breakFlowDirection(void) const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->breakFlowDirection();
#endif
}

Acad::ErrorStatus PyDbTable::setBreakFlowDirection(AcDb::TableBreakFlowDirection nDir)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setBreakFlowDirection(nDir);
#endif
}

double PyDbTable::breakHeight(int nIndex) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->breakHeight(nIndex);
}

Acad::ErrorStatus PyDbTable::setBreakHeight(int nIndex, double fHeight)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setBreakHeight(nIndex, fHeight);
}

AcGeVector3d PyDbTable::breakOffset(int nIndex) const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->breakOffset(nIndex);
#endif
}

Acad::ErrorStatus PyDbTable::setBreakOffset(int nIndex, const AcGeVector3d& vec)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setBreakOffset(nIndex, vec);
#endif
}

AcDb::TableBreakOption PyDbTable::breakOption(void) const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->breakOption();
#endif
}

Acad::ErrorStatus PyDbTable::setBreakOption(AcDb::TableBreakOption nOption)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setBreakOption(nOption);
#endif
}

double PyDbTable::breakSpacing(void) const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->breakSpacing();
#endif
}

Acad::ErrorStatus PyDbTable::setBreakSpacing(double fSpacing)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setBreakSpacing(fSpacing);
#endif
}

AcCellRange PyDbTable::cellRange() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->cellRange();
#endif
}

std::string PyDbTable::className()
{
    return "AcDbTable";
}

AcDbTable* PyDbTable::impObj() const
{
    return static_cast<AcDbTable*>(m_pImp.get());
}
