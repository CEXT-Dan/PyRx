#pragma once
#include "PyDbEnts.h"

class PyDbTable : public PyDbBlockReference
{
public:
    PyDbTable();
    PyDbTable(AcDbTable* ptr, bool autoDelete);
    PyDbTable(const PyDbObjectId& id, AcDb::OpenMode mode);

    PyDbObjectId        tableStyle() const;
    Acad::ErrorStatus   setTableStyle(const PyDbObjectId& id);

    AcGeVector3d        direction() const;
    Acad::ErrorStatus   setDirection(const AcGeVector3d& horzVec);

    Adesk::UInt32       numRows() const;
    Adesk::UInt32       numColumns() const;

    double              width() const;
    Acad::ErrorStatus   setWidth(double width);

    double              columnWidth(int col) const;
    Acad::ErrorStatus   setColumnWidth1(int col, double width);
    Acad::ErrorStatus   setColumnWidth2(double width);

    double              height() const;
    Acad::ErrorStatus   setHeight(double height);

    double              rowHeight(int row) const;
    Acad::ErrorStatus   setRowHeight1(int row, double height);
    Acad::ErrorStatus   setRowHeight2(double height);

    double              minimumColumnWidth(int col) const;
    double              minimumRowHeight(int row) const;
    double              minimumTableWidth() const;
    double              minimumTableHeight() const;

    double              horzCellMargin() const;
    Acad::ErrorStatus   setHorzCellMargin(double gap);

    virtual double      vertCellMargin() const;
    virtual Acad::ErrorStatus setVertCellMargin(double gap);

    AcDb::FlowDirection flowDirection() const;
    Acad::ErrorStatus   setFlowDirection(AcDb::FlowDirection flow);

    bool                isTitleSuppressed() const;
    Acad::ErrorStatus   suppressTitleRow(bool value);

    bool                isHeaderSuppressed() const;
    Acad::ErrorStatus   suppressHeaderRow(bool value);

    AcDb::CellAlignment alignment(AcDb::RowType type) const;
    Acad::ErrorStatus   setAlignment(AcDb::CellAlignment align, AcDb::RowType rowTypes);

    bool                isBackgroundColorNone(AcDb::RowType type) const;
    Acad::ErrorStatus   setBackgroundColorNone(bool value, AcDb::RowType type);

    AcCmColor           backgroundColor(AcDb::RowType type) const;
    Acad::ErrorStatus   setBackgroundColor(const AcCmColor& color, AcDb::RowType type);

    AcCmColor           contentColor(AcDb::RowType type) const;
    Acad::ErrorStatus   setContentColor(const AcCmColor& color, AcDb::RowType type);

    boost::python::tuple getDataType(AcDb::RowType type) const;
    Acad::ErrorStatus   setDataType1(AcValue::DataType nDataType, AcValue::UnitType nUnitType);
    Acad::ErrorStatus   setDataType2(AcValue::DataType nDataType, AcValue::UnitType nUnitType, AcDb::RowType type);

    PyDbObjectId        textStyle(AcDb::RowType type) const;
    Acad::ErrorStatus   setTextStyle(const PyDbObjectId& id, AcDb::RowType rowTypes);

    double              textHeight(AcDb::RowType type) const;
    Acad::ErrorStatus   setTextHeight(double height, AcDb::RowType rowTypes);

    AcDb::LineWeight    gridLineWeight(AcDb::GridLineType gridlineType,AcDb::RowType type) const;
    Acad::ErrorStatus   setGridLineWeight(AcDb::LineWeight lwt,int nBorders, int nRows);

    AcCmColor           gridColor(AcDb::GridLineType gridlineType, AcDb::RowType type) const;
    Acad::ErrorStatus   setGridColor(const AcCmColor& color, int nBorders, int nRows);

    AcDb::Visibility    gridVisibility(AcDb::GridLineType gridlineType, AcDb::RowType type) const;
    Acad::ErrorStatus   setGridVisibility(AcDb::Visibility visible, int nBorders, int nRows);

    boost::python::list tableStyleOverrides() const;
    void                clearTableStyleOverrides();

    AcDb::CellType      cellType(int row, int col) const;
    Acad::ErrorStatus   setCellType(int row, int col, AcDb::CellType type);

    boost::python::list getCellExtents(int row, int col, bool isOuterCell) const;

    AcGePoint3d         attachmentPoint(int row, int col) const;

    AcDb::CellAlignment alignment2(int row, int col) const;
    Acad::ErrorStatus   setAlignment2(int row,int col, AcDb::CellAlignment align);

    bool                isBackgroundColorNone2(int row,int col) const;
    Acad::ErrorStatus   setBackgroundColorNone2(int row,int col,bool value);

    AcCmColor           contentColor2(int row,int col) const;
    Acad::ErrorStatus   setContentColor2(int row, int col, const AcCmColor& color);

    boost::python::list cellStyleOverrides(int row,int col) const;
    void                clearCellOverrides(int row, int column);

    Acad::ErrorStatus   deleteCellContent(int row,int col);
    AcDb::RowType       rowType(int row) const;

    static std::string className();
public:
    AcDbTable* impObj() const;
};

