#pragma once
#include "PyDbEnts.h"
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
    PyDbObjectId        tableStyle() const;
    void                setTableStyle(const PyDbObjectId& id);
    AcGeVector3d        direction() const;
    void                setDirection(const AcGeVector3d& horzVec);
    Adesk::UInt32       numRows() const;
    Adesk::UInt32       numColumns() const;
    double              width() const;
    void                setWidth(double width);
    double              columnWidth(int col) const;

    void                setColumnWidth1(int col, double width);
    void                setColumnWidth2(double width);

    double              height() const;
    void                setHeight(double height);
    double              rowHeight(int row) const;

    void                setRowHeight1(int row, double height);
    void                setRowHeight2(double height);

    double              minimumColumnWidth(int col) const;
    double              minimumRowHeight(int row) const;
    double              minimumTableWidth() const;
    double              minimumTableHeight() const;
    double              horzCellMargin() const;
    void                setHorzCellMargin(double gap);
    virtual double      vertCellMargin() const;
    virtual void        setVertCellMargin(double gap);
    AcDb::FlowDirection flowDirection() const;
    void                setFlowDirection(AcDb::FlowDirection flow);
    bool                isTitleSuppressed() const;
    void                suppressTitleRow(bool value);
    bool                isHeaderSuppressed() const;
    void                suppressHeaderRow(bool value);

    AcDb::CellAlignment alignment(AcDb::RowType type) const;
    AcDb::CellAlignment alignment2(int row, int col) const;

    void                setAlignment(AcDb::CellAlignment align, AcDb::RowType rowTypes);
    void                setAlignment2(int row, int col, AcDb::CellAlignment align);

    bool                isBackgroundColorNone(AcDb::RowType type) const;
    void                setBackgroundColorNone(bool value, AcDb::RowType type);

    AcCmColor           backgroundColor(AcDb::RowType type) const;
    AcCmColor           backgroundColor2(int row, int col) const;

    void                setBackgroundColor(const AcCmColor& color, AcDb::RowType type);
    void                setBackgroundColor2(int row, int col, const AcCmColor& color);

    AcCmColor           contentColor(AcDb::RowType type) const;
    AcCmColor           contentColor2(int row, int col) const;

    void                setContentColor(const AcCmColor& color, AcDb::RowType type);
    void                setContentColor2(int row, int col, const AcCmColor& color);

    boost::python::tuple getDataType(AcDb::RowType type) const;
    boost::python::tuple getDataType2(int row, int col) const;
    boost::python::tuple getDataType3(int row, int col, int nContent) const;

    void                setDataType1(AcValue::DataType nDataType, AcValue::UnitType nUnitType);
    void                setDataType2(AcValue::DataType nDataType, AcValue::UnitType nUnitType, AcDb::RowType type);
    void                setDataType3(int row, int col, AcValue::DataType nDataType, AcValue::UnitType nUnitType);
    void                setDataType4(int row, int col, int nContent, AcValue::DataType nDataType, AcValue::UnitType nUnitType);

    PyDbObjectId        textStyle(AcDb::RowType type) const;
    PyDbObjectId        textStyle2(int row, int col) const;
    PyDbObjectId        textStyle3(int row, int col, int nContent) const;

    void                setTextStyle(const PyDbObjectId& id, AcDb::RowType rowTypes);
    void                setTextStyle2(int row, int col, const PyDbObjectId& id);
    void                setTextStyle3(int row, int col, int nContent, const PyDbObjectId& id);

    double              textHeight(AcDb::RowType type) const;
    double              textHeight2(int row, int col) const;
    double              textHeight3(int row, int col, int nContent) const;

    void                setTextHeight(double height, AcDb::RowType rowTypes);
    void                setTextHeight2(int row, int col, double height);
    void                setTextHeight3(int row, int col, int nContent, double height);

    AcDb::LineWeight    gridLineWeight(AcDb::GridLineType gridlineType, AcDb::RowType type) const;
    AcDb::LineWeight    gridLineWeight2(int nRow, int nCol, AcDb::GridLineType nGridLineType) const;
    AcDb::LineWeight    gridEdgeLineWeight(int row, int col, AcDb::CellEdgeMask iEdge) const;

    void                setGridLineWeight(AcDb::LineWeight lwt, int nBorders, int nRows);
    void                setGridLineWeight2(int nRow, int nCol, AcDb::GridLineType nGridLineTypes, AcDb::LineWeight nLineWeight);
    void                setGridEdgeLineWeight(int row, int col, AcDb::CellEdgeMask nEdges, AcDb::LineWeight value);

    AcCmColor           gridColor(AcDb::GridLineType gridlineType, AcDb::RowType type) const;
    AcCmColor           gridColor2(int nRow, int nCol, AcDb::GridLineType nGridLineType) const;
    AcCmColor           gridEdgeColor(int row, int col, AcDb::CellEdgeMask iEdge) const;

    void                setGridColor(const AcCmColor& color, int nBorders, int nRows);
    void                setGridColor2(int nRow, int nCol, AcDb::GridLineType nGridlineTypes, const AcCmColor& color);
    void                setGridEdgeColor(int row, int col, AcDb::CellEdgeMask nEdges, const AcCmColor& color);

    AcDb::Visibility    gridVisibility(AcDb::GridLineType gridlineType, AcDb::RowType type) const;
    AcDb::Visibility    gridVisibility2(int nRow, int nCol, AcDb::GridLineType nGridLineType) const;
    AcDb::Visibility    gridEdgeVisibility(int row, int col, AcDb::CellEdgeMask iEdge) const;

    void                setGridVisibility(AcDb::Visibility visible, int nBorders, int nRows);
    void                setGridVisibility2(int nRow, int nCol, AcDb::GridLineType nGridLineTypes, AcDb::Visibility nVisibility);
    void                setGridEdgeVisibility(int row, int col, AcDb::CellEdgeMask iEdge, AcDb::Visibility value);

    boost::python::list tableStyleOverrides() const;
    void                clearTableStyleOverrides();
    AcDb::CellType      cellType(int row, int col) const;
    void                setCellType(int row, int col, AcDb::CellType type);
    boost::python::list getCellExtents(int row, int col, bool isOuterCell) const;
    AcGePoint3d         attachmentPoint(int row, int col) const;

    bool                isBackgroundColorNone2(int row, int col) const;
    void                setBackgroundColorNone2(int row, int col, bool value);

    boost::python::list cellStyleOverrides(int row, int col) const;
    void                clearCellOverrides(int row, int column);
    void                deleteCellContent(int row, int col);
    AcDb::RowType       rowType(int row) const;
    void                setFormat(int row, int col, const std::string& pszFormat);

    std::string         textString(int row, int col) const;
    std::string         textString2(int row, int col, int nContent) const;

    std::string         textStringFmt1(int row, int col, AcValue::FormatOption nOption) const;
    std::string         textStringFmt2(int row, int col, int nContent, AcValue::FormatOption nOption) const;

    void                setTextString(int row, int col, const std::string& text);
    void                setTextString2(int row, int col, int nContent, const  std::string& text);

    PyDbObjectId        fieldId(int row, int col) const;
    void                setFieldId(int row, int col, const PyDbObjectId& fieldId);


    AcDb::RotationAngle textRotation(int row, int col) const;
    void                setTextRotation(int row, int col, AcDb::RotationAngle rot);

    bool                isAutoScale(int row, int col) const;
    bool                isAutoScale2(int row, int col, int nContent) const;

    void                setAutoScale(int row, int col, bool autoFit);
    void                setAutoScale2(int row, int col, int nContent, bool autoFit);

    PyDbObjectId        blockTableRecordId(int row, int col) const;
    PyDbObjectId        blockTableRecordId2(int row, int col, int nContent) const;

    void                setBlockTableRecordId(int row, int col, const PyDbObjectId& blkId, bool autoFit);
    void                setBlockTableRecordId2(int row, int col, int nContent, const PyDbObjectId& blkId, bool autoFit);

    double              blockScale(int row, int col) const;
    void                setBlockScale(int row, int col, double scale);
    double              blockRotation(int row, int col) const;
    void                setBlockRotation(int row, int col, double rotAng);

    void                insertColumns(int col, double width, int nCols);
    void                deleteColumns(int col, int nCols);
    void                insertRows(int row, double height, int nRows);
    void                deleteRows(int row, int nRows);
    void                mergeCells(int minRow, int maxRow, int minCol, int maxCol);
    void                unmergeCells(int minRow, int maxRow, int minCol, int maxCol);
    boost::python::tuple  isMergedCell(int row, int col);
    void                generateLayout();
    void                recomputeTableBlock(bool forceUpdate);
    boost::python::tuple  hitTest(const AcGePoint3d& wpt, const AcGeVector3d& wviewVec, double wxaper, double wyaper);
    AcCellRange         getSubSelection(void) const;
    void                setSubSelection(const AcCellRange& range);
    void                clearSubSelection();
    bool                hasSubSelection() const;
    void                setPosition(const AcGePoint3d& newVal);
    void                setNormal(const AcGeVector3d& newVal);
    void                setRegen();
    void                suppressInvisibleGrid(bool value);
    bool                isRegenerateTableSuppressed() const;
    void                suppressRegenerateTable(bool bSuppress);
    void                setRecomputeTableBlock(bool newVal);
    void                setSize(int nRows, int nCols);
    bool                canInsert(int nIndex, bool bRow) const;
    void                insertRowsAndInherit(int nIndex, int nInheritFrom, int nNumRows);
    void                insertColumnsAndInherit(int col, int nInheritFrom, int nNumCols);
    bool                canDelete(int nIndex, int nCount, bool bRow) const;
    bool                isEmpty(int nRow, int nCol) const;
    AcCellRange         getMergeRange(int nRow, int nCol) const;

    boost::python::list getIterator1();
    boost::python::list getIterator2(AcDb::TableIteratorOption nOption) const;
    boost::python::list getIterator3(const AcCellRange& pRange, AcDb::TableIteratorOption nOption) const;
    boost::python::list getIterator4(const AcCellRange& pRange) const;

    bool                isContentEditable(int nRow, int nCol) const;
    bool                isFormatEditable(int nRow, int nCol) const;
    AcDb::CellState     cellState(int nRow, int nCol) const;
    void                setCellState(int nRow, int nCol, AcDb::CellState nLock);
    int                 numContents(int nRow, int nCol) const;
    int                 createContent(int nRow, int nCol, int nIndex);
    void                moveContent(int nRow, int nCol, int nFromIndex, int nToIndex);

    void                deleteContent1(int nRow, int nCol);
    void                deleteContent2(int nRow, int nCol, int nIndex);
    void                deleteContent3(const AcCellRange& range);

    AcDb::CellContentType contentType1(int nRow, int nCol) const;
    AcDb::CellContentType contentType2(int nRow, int nCol, int nIndex) const;

    //AcValue value(int row,int col,int nContent) const;
    //AcValue value(int row, int col, int nContent,AcValue::FormatOption nOption) const;
    //void setValue(int row,int col,int nContent, const AcValue& val);
    //void setValue(int row,int col,int nContent,const AcValue& val,AcValue::ParseOption nOption);
    //void setValue(int row,int col,int nContent,const wchar_t* pszText, AcValue::ParseOption nOption);

    std::string         dataFormat1(int row, int col) const;
    std::string         dataFormat2(int row, int col, int nContent) const;

    void                setDataFormat1(int row, int col, const std::string& pszFormat);
    void                setDataFormat2(int row, int col, int nContent, const std::string& pszFormat);


    bool                hasFormula(int nRow, int nCol, int nContent) const;
    std::string         getFormula(int nRow, int nCol, int nContent) const;
    void                setFormula(int nRow, int nCol, int nContent, const  std::string& pszFormula);
    PyDbObjectId        fieldId2(int row, int col, int nContent) const;
    void                setFieldId2(int row, int col, int nContent, const PyDbObjectId& fieldId, AcDb::CellOption nFlag);


    std::string         getBlockAttributeValue1(int row, int col, const PyDbObjectId& attdefId) const;
    std::string         getBlockAttributeValue2(int row, int col, int nContent, const PyDbObjectId& attdefId) const;
    void                setBlockAttributeValue1(int row, int col, const PyDbObjectId& attdefId, const std::string& value);
    void                setBlockAttributeValue2(int row, int col, int nContent, const PyDbObjectId& attdefId, const std::string& value);

    const std::string   cellStyle(int nRow, int nCol) const;
    void                setCellStyle(int nRow, int nCol, const std::string& pszCellStyle);
    double              margin(int nRow, int nCol, AcDb::CellMargin nMargin) const;
    void                setMargin(int nRow, int nCol, AcDb::CellMargin nMargins, double fMargin);
    AcGePoint3d         attachmentPoint2(int row, int col, int content) const;
    AcCmColor           contentColor3(int row, int col, int nContent) const;
    void                setContentColor3(int row, int col, int nContent, const AcCmColor& color);

    double              rotation(void) const;
    double              rotation2(int row, int col, int nContent) const;

    void                setRotation(double fAngle);
    void                setRotation2(int row, int col, int nContent, double fAngle);

    double              scale(int row, int col, int nContent) const;
    void                setScale(int row, int col, int nContent, double scale);
    AcDb::CellContentLayout contentLayout(int row, int col) const;
    void                setContentLayout(int row, int col, AcDb::CellContentLayout nLayout);
    bool                isMergeAllEnabled(int nRow, int nCol) const;
    void                enableMergeAll(int nRow, int nCol, bool bEnable);
    AcDb::CellProperty  getCellOverride(int nRow, int nCol, int nContent) const;
    AcDb::GridProperty  getGridOverride(int nRow, int nCol, AcDb::GridLineType nGridLineType) const;
    void                setCellOverride(int nRow, int nCol, int nContent, AcDb::CellProperty nOverride);
    void                setGridOverride(int nRow, int nCol, AcDb::GridLineType nGridLineType, AcDb::GridProperty nOverride);
    void                removeAllOverrides(int nRow, int nCol);
    AcDb::GridLineStyle gridLineStyle(int nRow, int nCol, AcDb::GridLineType nGridLineType) const;
    void                setGridLineStyle(int nRow, int nCol, AcDb::GridLineType nGridLineTypes, AcDb::GridLineStyle nLineStyle);
    PyDbObjectId        gridLinetype(int nRow, int nCol, AcDb::GridLineType nGridLineType) const;
    void                setGridLinetype(int nRow, int nCol, AcDb::GridLineType nGridLineTypes, const PyDbObjectId& idLinetype);
    double              gridDoubleLineSpacing(int nRow, int nCol, AcDb::GridLineType nGridLineType) const;
    void                setGridDoubleLineSpacing(int nRow, int nCol, AcDb::GridLineType nGridLineTypes, double fSpacing);

    AcGridProperty      getGridProperty(int nRow, int nCol, AcDb::GridLineType nGridLineType) const;
    void                setGridProperty1(int nRow, int nCol, AcDb::GridLineType nGridLineTypes, const AcGridProperty& gridProp);
    void                setGridProperty2(const AcCellRange& rangeIn, AcDb::GridLineType nGridLineTypes, const AcGridProperty& gridProp);

    bool                isLinked(int nRow, int nCol) const;
    PyDbObjectId        getDataLink(int nRow, int nCol) const;
    void                setDataLink(const AcCellRange& range, const PyDbObjectId& idDataLink, bool bUpdate);
    AcCellRange         getDataLinkRange(int nRow, int nCol) const;

    void                removeDataLink1(void);
    void                removeDataLink2(int nRow, int nCol);

    void                updateDataLink1(AcDb::UpdateDirection nDir, AcDb::UpdateOption nOption);
    void                updateDataLink2(int nRow, int nCol, AcDb::UpdateDirection nDir, AcDb::UpdateOption nOption);

    bool                isBreakEnabled(void) const;
    void                enableBreak(bool bEnable);
    AcDb::TableBreakFlowDirection breakFlowDirection(void) const;
    void                setBreakFlowDirection(AcDb::TableBreakFlowDirection nDir);
    double              breakHeight(int nIndex) const;
    void                setBreakHeight(int nIndex, double fHeight);
    AcGeVector3d        breakOffset(int nIndex) const;
    void                setBreakOffset(int nIndex, const AcGeVector3d& vec);
    AcDb::TableBreakOption breakOption(void) const;
    void                setBreakOption(AcDb::TableBreakOption nOption);
    double              breakSpacing(void) const;
    void                setBreakSpacing(double fSpacing);
    AcCellRange         cellRange() const;
    public:
    static std::string  className();
    static PyRxClass    desc();
    static PyDbTable    cloneFrom(const PyRxObject& src);
    static PyDbTable    cast(const PyRxObject& src);
public:
    AcDbTable* impObj(const std::source_location& src = std::source_location::current()) const;
};
