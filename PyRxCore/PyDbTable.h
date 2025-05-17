#pragma once
#include "PyDbEnts.h"

#pragma pack (push, 8)

class PyDbAcValue;
//-----------------------------------------------------------------------------------
//PyDbTable
void makePyDbTableWrapper();
class PyDbTable : public PyDbBlockReference
{
public:
    PyDbTable();
    PyDbTable(AcDbTable* ptr, bool autoDelete);
    PyDbTable(const PyDbObjectId& id);
    PyDbTable(const PyDbObjectId& id, AcDb::OpenMode mode);
    virtual ~PyDbTable() override = default;
    PyDbObjectId        tableStyle() const;
    void                setTableStyle(const PyDbObjectId& id) const;
    AcGeVector3d        direction() const;
    void                setDirection(const AcGeVector3d& horzVec) const;
    Adesk::UInt32       numRows() const;
    Adesk::UInt32       numColumns() const;
    double              width() const;
    void                setWidth(double width) const;
    double              columnWidth(int col) const;

    void                setColumnWidth1(int col, double width) const;
    void                setColumnWidth2(double width) const;

    double              height() const;
    void                setHeight(double height) const;
    double              rowHeight(int row) const;

    void                setRowHeight1(int row, double height) const;
    void                setRowHeight2(double height) const;

    double              minimumColumnWidth(int col) const;
    double              minimumRowHeight(int row) const;
    double              minimumTableWidth() const;
    double              minimumTableHeight() const;
    double              horzCellMargin() const;
    void                setHorzCellMargin(double gap) const;
    virtual double      vertCellMargin() const;
    virtual void        setVertCellMargin(double gap) const;
    AcDb::FlowDirection flowDirection() const;
    void                setFlowDirection(AcDb::FlowDirection flow) const;
    bool                isTitleSuppressed() const;
    void                suppressTitleRow(bool value) const;
    bool                isHeaderSuppressed() const;
    void                suppressHeaderRow(bool value) const;

    AcDb::CellAlignment alignment(AcDb::RowType type) const;
    AcDb::CellAlignment alignment2(int row, int col) const;

    void                setAlignment(AcDb::CellAlignment align, AcDb::RowType rowTypes) const;
    void                setAlignment2(int row, int col, AcDb::CellAlignment align) const;

    bool                isBackgroundColorNone(AcDb::RowType type) const;
    void                setBackgroundColorNone(bool value, AcDb::RowType type) const;

    AcCmColor           backgroundColor(AcDb::RowType type) const;
    AcCmColor           backgroundColor2(int row, int col) const;

    void                setBackgroundColor(const AcCmColor& color, AcDb::RowType type) const;
    void                setBackgroundColor2(int row, int col, const AcCmColor& color) const;

    AcCmColor           contentColor(AcDb::RowType type) const;
    AcCmColor           contentColor2(int row, int col) const;

    void                setContentColor(const AcCmColor& color, AcDb::RowType type) const;
    void                setContentColor2(int row, int col, const AcCmColor& color) const;

    boost::python::tuple getDataType(AcDb::RowType type) const;
    boost::python::tuple getDataType2(int row, int col) const;
    boost::python::tuple getDataType3(int row, int col, int nContent) const;

    void                setDataType1(AcValue::DataType nDataType, AcValue::UnitType nUnitType) const;
    void                setDataType2(AcValue::DataType nDataType, AcValue::UnitType nUnitType, AcDb::RowType type) const;
    void                setDataType3(int row, int col, AcValue::DataType nDataType, AcValue::UnitType nUnitType) const;
    void                setDataType4(int row, int col, int nContent, AcValue::DataType nDataType, AcValue::UnitType nUnitType) const;

    PyDbObjectId        textStyle(AcDb::RowType type) const;
    PyDbObjectId        textStyle2(int row, int col) const;
    PyDbObjectId        textStyle3(int row, int col, int nContent) const;

    void                setTextStyle(const PyDbObjectId& id, AcDb::RowType rowTypes) const;
    void                setTextStyle2(int row, int col, const PyDbObjectId& id) const;
    void                setTextStyle3(int row, int col, int nContent, const PyDbObjectId& id) const;

    double              textHeight(AcDb::RowType type) const;
    double              textHeight2(int row, int col) const;
    double              textHeight3(int row, int col, int nContent) const;

    void                setTextHeight(double height, AcDb::RowType rowTypes) const;
    void                setTextHeight2(int row, int col, double height) const;
    void                setTextHeight3(int row, int col, int nContent, double height) const;

    AcDb::LineWeight    gridLineWeight(AcDb::GridLineType gridlineType, AcDb::RowType type) const;
    AcDb::LineWeight    gridLineWeight2(int nRow, int nCol, AcDb::GridLineType nGridLineType) const;
    AcDb::LineWeight    gridEdgeLineWeight(int row, int col, AcDb::CellEdgeMask iEdge) const;

    void                setGridLineWeight(AcDb::LineWeight lwt, int nBorders, int nRows) const;
    void                setGridLineWeight2(int nRow, int nCol, AcDb::GridLineType nGridLineTypes, AcDb::LineWeight nLineWeight) const;
    void                setGridEdgeLineWeight(int row, int col, AcDb::CellEdgeMask nEdges, AcDb::LineWeight value) const;

    AcCmColor           gridColor(AcDb::GridLineType gridlineType, AcDb::RowType type) const;
    AcCmColor           gridColor2(int nRow, int nCol, AcDb::GridLineType nGridLineType) const;
    AcCmColor           gridEdgeColor(int row, int col, AcDb::CellEdgeMask iEdge) const;

    void                setGridColor(const AcCmColor& color, int nBorders, int nRows) const;
    void                setGridColor2(int nRow, int nCol, AcDb::GridLineType nGridlineTypes, const AcCmColor& color) const;
    void                setGridEdgeColor(int row, int col, AcDb::CellEdgeMask nEdges, const AcCmColor& color) const;

    AcDb::Visibility    gridVisibility(AcDb::GridLineType gridlineType, AcDb::RowType type) const;
    AcDb::Visibility    gridVisibility2(int nRow, int nCol, AcDb::GridLineType nGridLineType) const;
    AcDb::Visibility    gridEdgeVisibility(int row, int col, AcDb::CellEdgeMask iEdge) const;

    void                setGridVisibility(AcDb::Visibility visible, int nBorders, int nRows) const;
    void                setGridVisibility2(int nRow, int nCol, AcDb::GridLineType nGridLineTypes, AcDb::Visibility nVisibility) const;
    void                setGridEdgeVisibility(int row, int col, AcDb::CellEdgeMask iEdge, AcDb::Visibility value) const;

    boost::python::list tableStyleOverrides() const;
    void                clearTableStyleOverrides() const;
    AcDb::CellType      cellType(int row, int col) const;
    void                setCellType(int row, int col, AcDb::CellType type) const;
    boost::python::list getCellExtents(int row, int col, bool isOuterCell) const;
    AcGePoint3d         attachmentPoint(int row, int col) const;

    bool                isBackgroundColorNone2(int row, int col) const;
    void                setBackgroundColorNone2(int row, int col, bool value) const;

    boost::python::list cellStyleOverrides(int row, int col) const;
    void                clearCellOverrides(int row, int column) const;
    void                deleteCellContent(int row, int col) const;
    AcDb::RowType       rowType(int row) const;
    void                setFormat(int row, int col, const std::string& pszFormat) const;

    std::string         textString(int row, int col) const;
    std::string         textString2(int row, int col, int nContent) const;
    std::string         textString3(const AcCell& cell) const;//

    std::string         textStringFmt1(int row, int col, AcValue::FormatOption nOption) const;
    std::string         textStringFmt2(int row, int col, int nContent, AcValue::FormatOption nOption) const;
    std::string         textStringFmt3(const AcCell& cell, AcValue::FormatOption nOption) const;//

    void                setTextString(int row, int col, const std::string& text) const;
    void                setTextString2(int row, int col, int nContent, const  std::string& text) const;
    void                setTextString3(const AcCell& cell, const std::string& text) const;

    PyDbObjectId        fieldId(int row, int col) const;
    void                setFieldId(int row, int col, const PyDbObjectId& fieldId) const;

    AcDb::RotationAngle textRotation(int row, int col) const;
    void                setTextRotation(int row, int col, AcDb::RotationAngle rot) const;

    bool                isAutoScale(int row, int col) const;
    bool                isAutoScale2(int row, int col, int nContent) const;

    void                setAutoScale(int row, int col, bool autoFit) const;
    void                setAutoScale2(int row, int col, int nContent, bool autoFit) const;

    PyDbObjectId        blockTableRecordId(int row, int col) const;
    PyDbObjectId        blockTableRecordId2(int row, int col, int nContent) const;

    void                setBlockTableRecordId(int row, int col, const PyDbObjectId& blkId, bool autoFit) const;
    void                setBlockTableRecordId2(int row, int col, int nContent, const PyDbObjectId& blkId, bool autoFit) const;

    double              blockScale(int row, int col) const;
    void                setBlockScale(int row, int col, double scale) const;
    double              blockRotation(int row, int col) const;
    void                setBlockRotation(int row, int col, double rotAng) const;

    void                insertColumns(int col, double width, int nCols) const;
    void                deleteColumns(int col, int nCols) const;
    void                insertRows(int row, double height, int nRows) const;
    void                deleteRows(int row, int nRows) const;
    void                mergeCells(int minRow, int maxRow, int minCol, int maxCol) const;
    void                unmergeCells(int minRow, int maxRow, int minCol, int maxCol) const;
    boost::python::tuple  isMergedCell(int row, int col) const;
    void                generateLayout() const;
    void                recomputeTableBlock(bool forceUpdate) const;
    boost::python::tuple  hitTest(const AcGePoint3d& wpt, const AcGeVector3d& wviewVec) const;
    boost::python::tuple  hitTest2(const AcGePoint3d& wpt, const AcGeVector3d& wviewVec, double wxaper, double wyaper) const;
    AcCellRange         getSubSelection(void) const;
    void                setSubSelection(const AcCellRange& range) const;
    void                clearSubSelection() const;
    bool                hasSubSelection() const;
    void                setPosition(const AcGePoint3d& newVal) const;
    void                setNormal(const AcGeVector3d& newVal) const;
    void                setRegen() const;
    void                suppressInvisibleGrid(bool value) const;
    bool                isRegenerateTableSuppressed() const;
    void                suppressRegenerateTable(bool bSuppress) const;
    void                setRecomputeTableBlock(bool newVal) const;
    void                setSize(int nRows, int nCols) const;
    bool                canInsert(int nIndex, bool bRow) const;
    void                insertRowsAndInherit(int nIndex, int nInheritFrom, int nNumRows) const;
    void                insertColumnsAndInherit(int col, int nInheritFrom, int nNumCols) const;
    bool                canDelete(int nIndex, int nCount, bool bRow) const;
    bool                isEmpty(int nRow, int nCol) const;
    AcCellRange         getMergeRange(int nRow, int nCol) const;

    boost::python::list getIterator1() const;
    boost::python::list getIterator2(AcDb::TableIteratorOption nOption) const;
    boost::python::list getIterator3(const AcCellRange& pRange, AcDb::TableIteratorOption nOption) const;
    boost::python::list getIterator4(const AcCellRange& pRange) const;

    boost::python::list getStrValueIterator1() const;
    boost::python::list getStrValueIterator2(AcDb::TableIteratorOption nOption) const;
    boost::python::list getStrValueIterator3(const AcCellRange& pRange, AcDb::TableIteratorOption nOption) const;
    boost::python::list getStrValueIterator4(const AcCellRange& pRange) const;

    boost::python::list getValueIterator1() const;
    boost::python::list getValueIterator2(AcDb::TableIteratorOption nOption) const;
    boost::python::list getValueIterator3(const AcCellRange& pRange, AcDb::TableIteratorOption nOption) const;
    boost::python::list getValueIterator4(const AcCellRange& pRange) const;

    bool                isContentEditable(int nRow, int nCol) const;
    bool                isFormatEditable(int nRow, int nCol) const;
    AcDb::CellState     cellState(int nRow, int nCol) const;
    void                setCellState(int nRow, int nCol, AcDb::CellState nLock) const;
    int                 numContents(int nRow, int nCol) const;
    int                 createContent(int nRow, int nCol, int nIndex) const;
    void                moveContent(int nRow, int nCol, int nFromIndex, int nToIndex) const;

    void                deleteContent1(int nRow, int nCol) const;
    void                deleteContent2(int nRow, int nCol, int nIndex) const;
    void                deleteContent3(const AcCellRange& range) const;

    AcDb::CellContentType contentType1(int nRow, int nCol) const;
    AcDb::CellContentType contentType2(int nRow, int nCol, int nIndex) const;

    PyDbAcValue         value1(int row, int col) const;
    PyDbAcValue         value2(int row, int col, int nContent) const;
    PyDbAcValue         value3(int row, int col, int nContent, AcValue::FormatOption nOption) const;

    void                setValue1(int row, int col, const PyDbAcValue& val) const;
    void                setValue2(int row, int col, int nContent, const PyDbAcValue& val) const;
    void                setValue3(int row, int col, int nContent, const PyDbAcValue& val, AcValue::ParseOption nOption) const;
    void                setValue4(int row, int col, int nContent, const std::string& pszText, AcValue::ParseOption nOption) const;

    std::string         dataFormat1(int row, int col) const;
    std::string         dataFormat2(int row, int col, int nContent) const;

    void                setDataFormat1(int row, int col, const std::string& pszFormat) const;
    void                setDataFormat2(int row, int col, int nContent, const std::string& pszFormat) const;

    bool                hasFormula(int nRow, int nCol, int nContent) const;
    std::string         getFormula(int nRow, int nCol, int nContent) const;
    void                setFormula(int nRow, int nCol, int nContent, const  std::string& pszFormula) const;
    PyDbObjectId        fieldId2(int row, int col, int nContent) const;
    void                setFieldId2(int row, int col, int nContent, const PyDbObjectId& fieldId, AcDb::CellOption nFlag) const;

    std::string         getBlockAttributeValue1(int row, int col, const PyDbObjectId& attdefId) const;
    std::string         getBlockAttributeValue2(int row, int col, int nContent, const PyDbObjectId& attdefId) const;
    void                setBlockAttributeValue1(int row, int col, const PyDbObjectId& attdefId, const std::string& value) const;
    void                setBlockAttributeValue2(int row, int col, int nContent, const PyDbObjectId& attdefId, const std::string& value) const;

    const std::string   cellStyle(int nRow, int nCol) const;
    void                setCellStyle(int nRow, int nCol, const std::string& pszCellStyle) const;
    double              margin(int nRow, int nCol, AcDb::CellMargin nMargin) const;
    void                setMargin(int nRow, int nCol, AcDb::CellMargin nMargins, double fMargin) const;
    AcGePoint3d         attachmentPoint2(int row, int col, int content) const;
    AcCmColor           contentColor3(int row, int col, int nContent) const;
    void                setContentColor3(int row, int col, int nContent, const AcCmColor& color) const;

    double              rotation(void) const;
    double              rotation2(int row, int col, int nContent) const;

    void                setRotation(double fAngle) const;
    void                setRotation2(int row, int col, int nContent, double fAngle) const;

    double              scale(int row, int col, int nContent) const;
    void                setScale(int row, int col, int nContent, double scale) const;
    AcDb::CellContentLayout contentLayout(int row, int col) const;
    void                setContentLayout(int row, int col, AcDb::CellContentLayout nLayout) const;
    bool                isMergeAllEnabled(int nRow, int nCol) const;
    void                enableMergeAll(int nRow, int nCol, bool bEnable) const;
    AcDb::CellProperty  getCellOverride(int nRow, int nCol, int nContent) const;
    AcDb::GridProperty  getGridOverride(int nRow, int nCol, AcDb::GridLineType nGridLineType) const;
    void                setCellOverride(int nRow, int nCol, int nContent, AcDb::CellProperty nOverride) const;
    void                setGridOverride(int nRow, int nCol, AcDb::GridLineType nGridLineType, AcDb::GridProperty nOverride) const;
    void                removeAllOverrides(int nRow, int nCol) const;
    AcDb::GridLineStyle gridLineStyle(int nRow, int nCol, AcDb::GridLineType nGridLineType) const;
    void                setGridLineStyle(int nRow, int nCol, AcDb::GridLineType nGridLineTypes, AcDb::GridLineStyle nLineStyle) const;
    PyDbObjectId        gridLinetype(int nRow, int nCol, AcDb::GridLineType nGridLineType) const;
    void                setGridLinetype(int nRow, int nCol, AcDb::GridLineType nGridLineTypes, const PyDbObjectId& idLinetype) const;
    double              gridDoubleLineSpacing(int nRow, int nCol, AcDb::GridLineType nGridLineType) const;
    void                setGridDoubleLineSpacing(int nRow, int nCol, AcDb::GridLineType nGridLineTypes, double fSpacing) const;

    AcGridProperty      getGridProperty(int nRow, int nCol, AcDb::GridLineType nGridLineType) const;
    void                setGridProperty1(int nRow, int nCol, AcDb::GridLineType nGridLineTypes, const AcGridProperty& gridProp) const;
    void                setGridProperty2(const AcCellRange& rangeIn, AcDb::GridLineType nGridLineTypes, const AcGridProperty& gridProp) const;

    bool                isLinked(int nRow, int nCol) const;
    PyDbObjectId        getDataLink(int nRow, int nCol) const;
    void                setDataLink(const AcCellRange& range, const PyDbObjectId& idDataLink, bool bUpdate) const;
    AcCellRange         getDataLinkRange(int nRow, int nCol) const;

    void                removeDataLink1(void) const;
    void                removeDataLink2(int nRow, int nCol) const;

    void                updateDataLink1(AcDb::UpdateDirection nDir, AcDb::UpdateOption nOption) const;
    void                updateDataLink2(int nRow, int nCol, AcDb::UpdateDirection nDir, AcDb::UpdateOption nOption) const;

    bool                isBreakEnabled(void) const;
    void                enableBreak(bool bEnable) const;
    AcDb::TableBreakFlowDirection breakFlowDirection(void) const;
    void                setBreakFlowDirection(AcDb::TableBreakFlowDirection nDir) const;
    double              breakHeight(int nIndex) const;
    void                setBreakHeight(int nIndex, double fHeight) const;
    AcGeVector3d        breakOffset(int nIndex) const;
    void                setBreakOffset(int nIndex, const AcGeVector3d& vec) const;
    AcDb::TableBreakOption breakOption(void) const;
    void                setBreakOption(AcDb::TableBreakOption nOption) const;
    double              breakSpacing(void) const;
    void                setBreakSpacing(double fSpacing) const;
    AcCellRange         cellRange() const;

    void                clearCustomData(int nrow, int ncol, const std::string& key) const;
    PyDbAcValue         getCustomData(int nrow, int ncol, const std::string& key) const;
    void                setCustomData(int nrow, int ncol, const std::string& key, const PyDbAcValue& val) const;

public:
    static boost::python::tuple  calcTextExtents(const std::string& strval, const PyDbObjectId& textStyle);
    static std::string  className();
    static PyRxClass    desc();
    static PyDbTable    cloneFrom(const PyRxObject& src);
    static PyDbTable    cast(const PyRxObject& src);
public:
    AcDbTable* impObj(const std::source_location& src = std::source_location::current()) const;
};

#pragma pack (pop)