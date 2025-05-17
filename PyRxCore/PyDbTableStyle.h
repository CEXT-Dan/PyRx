#pragma once
#include "PyDbObject.h"

#pragma pack (push, 8)
class PyDbObjectId;
void makePyDbTableStyleWrapper();
class PyDbTableStyle : public PyDbObject
{
public:
    PyDbTableStyle();
    PyDbTableStyle(AcDbObject* ptr, bool autoDelete);
    PyDbTableStyle(const PyDbObjectId& id);
    PyDbTableStyle(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbTableStyle(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    virtual ~PyDbTableStyle() override = default;
    std::string         getName() const;
    void                setName(const std::string& pszName) const;
    std::string         description(void) const;
    void                setDescription(const std::string& pszDescription) const;
    Adesk::UInt32       bitFlags() const;
    void                setBitFlags(Adesk::UInt32 flags) const;
    AcDb::FlowDirection flowDirection(void) const;
    void                setFlowDirection(AcDb::FlowDirection flow) const;
    virtual double      horzCellMargin(void) const;
    void                setHorzCellMargin(double dCellMargin) const;
    double              vertCellMargin(void) const;
    void                setVertCellMargin(double dCellMargin) const;
    bool                isTitleSuppressed(void) const;
    void                suppressTitleRow(bool bValue) const;
    bool                isHeaderSuppressed(void) const;
    void                suppressHeaderRow(bool bValue) const;
    PyDbObjectId        textStyle(AcDb::RowType rowType) const;
    void                setTextStyle(const PyDbObjectId& id, AcDb::RowType rowType) const;
    double              textHeight(AcDb::RowType rowType) const;
    void                setTextHeight(double dHeight, AcDb::RowType rowType) const;
    AcDb::CellAlignment alignment(AcDb::RowType rowType) const;
    void                setAlignment(AcDb::CellAlignment alignment, AcDb::RowType rowType) const;
    AcCmColor           color(AcDb::RowType rowType) const;
    void                setColor(const AcCmColor& color,AcDb::RowType rowType) const;
    AcCmColor           backgroundColor(AcDb::RowType rowType) const;
    void                setBackgroundColor(const AcCmColor& color, AcDb::RowType rowType) const;
    bool                isBackgroundColorNone(AcDb::RowType rowType ) const;
    void                setBackgroundColorNone(bool bValue, AcDb::RowType rowType) const;
    boost::python::tuple getDataType(AcDb::RowType type) const;
    void                setDataType1(AcValue::DataType nDataType, AcValue::UnitType nUnitType) const;
    void                setDataType2(AcValue::DataType nDataType, AcValue::UnitType nUnitType, AcDb::RowType type) const;
    std::string         format1(void) const;
    std::string         format2(AcDb::RowType rowType) const;
    void                setFormat1(const std::string& pszFormat) const;
    void                setFormat2(const std::string& pszFormat, AcDb::RowType type) const;
    AcDb::LineWeight    gridLineWeight(AcDb::GridLineType gridLineType, AcDb::RowType rowType) const;
    void                setGridLineWeight(AcDb::LineWeight lineWeight, AcDb::GridLineType gridLineType, AcDb::RowType rowType) const;
    AcCmColor           gridColor(AcDb::GridLineType gridLineType, AcDb::RowType rowType) const;
    void                setGridColor(const AcCmColor& color, AcDb::GridLineType gridLineType, AcDb::RowType rowType) const;
    AcDb::Visibility    gridVisibility(AcDb::GridLineType gridLineType,AcDb::RowType rowType) const;
    void                setGridVisibility(AcDb::Visibility visible, AcDb::GridLineType gridLineType, AcDb::RowType rowType) const;
    PyDbObjectId        postTableStyleToDb(PyDbDatabase& pDb, const std::string& styleName) const;
    std::string         createCellStyle1(void) const;
    void                createCellStyle2(const std::string& pszCellStyle) const;
    void                createCellStyle3(const std::string& pszCellStyle, const std::string& pszFromCellStyle) const;
    void                renameCellStyle(const std::string& pszOldName, const std::string& pszNewName) const;
    void                deleteCellStyle(const std::string& pszCellStyle) const;
    void                copyCellStyle(const std::string& pszSrcCellStyle, const std::string& pszTargetCellStyle) const;
    bool                isCellStyleInUse(const std::string& pszCellStyle) const;
    int                 numCellStyles(void) const;
    boost::python::list getCellStyles() const;
    PyDbObjectId        textStyle2(const std::string& pszCellStyle) const;
    void                setTextStyle2(const PyDbObjectId& id, const std::string& pszCellStyle) const;
    double              textHeight2(const std::string& pszCellStyle) const;
    void                setTextHeight2(double dHeight, const std::string& pszCellStyle) const;
    AcDb::CellAlignment alignment2(const std::string& pszCellStyle) const;
    void                setAlignment2(AcDb::CellAlignment alignment, const std::string& pszCellStyle) const;
    AcCmColor           color2(const std::string& pszCellStyle) const;
    void                setColor2(const AcCmColor& color, const std::string& pszCellStyle) const;
    AcCmColor           backgroundColor2(const std::string& pszCellStyle) const;
    void                setBackgroundColor2(const AcCmColor& color, const std::string& pszCellStyle) const;
    boost::python::tuple getDataType2(const std::string& pszCellStyle) const;
    void                setDataType3(AcValue::DataType nDataType, AcValue::UnitType nUnitType, const std::string& pszCellStyle) const;
    std::string         format3(const std::string& pszCellStyle) const;
    void                setFormat3(const std::string& pszFormat, const std::string& pszCellStyle) const;
    int                 cellClass(const std::string& pszCellStyle) const;
    void                setCellClass(int nClass, const std::string& pszCellStyle) const;
    double              rotation(const std::string& pszCellStyle) const;
    void                setRotation(double fRotation, const std::string& pszCellStyle) const;
    bool                isMergeAllEnabled(const std::string& pszCellStyle) const;
    void                enableMergeAll(bool bEnable, const std::string& pszCellStyle) const;
    double              margin(AcDb::CellMargin nMargin, const std::string& pszCellStyle) const;
    void                setMargin(AcDb::CellMargin nMargins, double fMargin, const std::string& pszCellStyle) const;
    AcDb::LineWeight    gridLineWeight2(AcDb::GridLineType gridLineType, const std::string& pszCellStyle) const;
    void                setGridLineWeight2(AcDb::LineWeight lineWeight, AcDb::GridLineType gridLineTypes, const std::string& pszCellStyle) const;
    AcCmColor           gridColor2(AcDb::GridLineType gridLineType, const std::string& pszCellStyle) const;
    void                setGridColor2(const AcCmColor& color,AcDb::GridLineType gridLineTypes, const std::string& pszCellStyle) const;
    AcDb::Visibility    gridVisibility2(AcDb::GridLineType gridLineType, const std::string& pszCellStyle) const;
    void                setGridVisibility2(AcDb::Visibility visible, AcDb::GridLineType gridLineTypes, const std::string& pszCellStyle) const;
    double              gridDoubleLineSpacing(AcDb::GridLineType gridLineType, const std::string& pszCellStyle) const;
    void                setGridDoubleLineSpacing(double fSpacing, AcDb::GridLineType gridLineTypes, const std::string& pszCellStyle) const;
    AcDb::GridLineStyle gridLineStyle(AcDb::GridLineType gridLineType, const std::string& pszCellStyle) const;
    void                setGridLineStyle(AcDb::GridLineStyle nLineStyle, AcDb::GridLineType gridLineTypes, const std::string& pszCellStyle) const;
    PyDbObjectId        gridLinetype(AcDb::GridLineType gridLineType, const std::string& pszCellStyle) const;
    void                setGridLinetype(const PyDbObjectId& id, AcDb::GridLineType gridLineTypes, const std::string& pszCellStyle) const;
    AcGridProperty      getGridProperty(AcDb::GridLineType nGridLineTypes, const std::string& pszCellStyle) const;
    void                setGridProperty(const AcGridProperty& gridProp, AcDb::GridLineType nGridLineTypes, const std::string& pszCellStyle) const;
    PyDbObjectId        getTemplate(void) const;
    void                setTemplate(const PyDbObjectId& templateId, AcDb::MergeCellStyleOption nOption) const;
    PyDbObjectId        removeTemplate(void) const;
public:
    static std::string  className();
    static PyRxClass    desc();
    static PyDbTableStyle cloneFrom(const PyRxObject& src);
    static PyDbTableStyle cast(const PyRxObject& src);
public:
    AcDbTableStyle* impObj(const std::source_location& src = std::source_location::current()) const;
};

#pragma pack (pop)