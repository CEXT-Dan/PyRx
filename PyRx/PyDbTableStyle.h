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
    std::string         getName();
    void                setName(const std::string& pszName);
    std::string         description(void) const;
    void                setDescription(const std::string& pszDescription);
    Adesk::UInt32       bitFlags() const;
    void                setBitFlags(Adesk::UInt32 flags);
    AcDb::FlowDirection flowDirection(void) const;
    void                setFlowDirection(AcDb::FlowDirection flow);
    virtual double      horzCellMargin(void) const;
    void                setHorzCellMargin(double dCellMargin);
    double              vertCellMargin(void) const;
    void                setVertCellMargin(double dCellMargin);
    bool                isTitleSuppressed(void) const;
    void                suppressTitleRow(bool bValue);
    bool                isHeaderSuppressed(void) const;
    void                suppressHeaderRow(bool bValue);
    PyDbObjectId        textStyle(AcDb::RowType rowType) const;
    void                setTextStyle(const PyDbObjectId& id, AcDb::RowType rowType);
    double              textHeight(AcDb::RowType rowType) const;
    void                setTextHeight(double dHeight, AcDb::RowType rowType);
    AcDb::CellAlignment alignment(AcDb::RowType rowType) const;
    void                setAlignment(AcDb::CellAlignment alignment, AcDb::RowType rowType);
    AcCmColor           color(AcDb::RowType rowType) const;
    void                setColor(const AcCmColor& color,AcDb::RowType rowType);
    AcCmColor           backgroundColor(AcDb::RowType rowType) const;
    void                setBackgroundColor(const AcCmColor& color, AcDb::RowType rowType);
    bool                isBackgroundColorNone(AcDb::RowType rowType ) const;
    void                setBackgroundColorNone(bool bValue, AcDb::RowType rowType);
    boost::python::tuple getDataType(AcDb::RowType type) const;
    void                setDataType1(AcValue::DataType nDataType, AcValue::UnitType nUnitType);
    void                setDataType2(AcValue::DataType nDataType, AcValue::UnitType nUnitType, AcDb::RowType type);
    std::string         format1(void) const;
    std::string         format2(AcDb::RowType rowType) const;
    void                setFormat1(const std::string& pszFormat);
    void                setFormat2(const std::string& pszFormat, AcDb::RowType type);
    AcDb::LineWeight    gridLineWeight(AcDb::GridLineType gridLineType, AcDb::RowType rowType) const;
    void                setGridLineWeight(AcDb::LineWeight lineWeight, AcDb::GridLineType gridLineType, AcDb::RowType rowType);
    AcCmColor           gridColor(AcDb::GridLineType gridLineType, AcDb::RowType rowType) const;
    void                setGridColor(const AcCmColor& color, AcDb::GridLineType gridLineType, AcDb::RowType rowType);
    AcDb::Visibility    gridVisibility(AcDb::GridLineType gridLineType,AcDb::RowType rowType) const;
    void                setGridVisibility(AcDb::Visibility visible, AcDb::GridLineType gridLineType, AcDb::RowType rowType);
    PyDbObjectId        postTableStyleToDb(PyDbDatabase& pDb, const std::string& styleName);
    std::string         createCellStyle1(void);
    void                createCellStyle2(const std::string& pszCellStyle);
    void                createCellStyle3(const std::string& pszCellStyle, const std::string& pszFromCellStyle);
    void                renameCellStyle(const std::string& pszOldName, const std::string& pszNewName);
    void                deleteCellStyle(const std::string& pszCellStyle);
    void                copyCellStyle(const std::string& pszSrcCellStyle, const std::string& pszTargetCellStyle);
    bool                isCellStyleInUse(const std::string& pszCellStyle) const;
    int                 numCellStyles(void) const;
    boost::python::list getCellStyles();
    PyDbObjectId        textStyle2(const std::string& pszCellStyle) const;
    void                setTextStyle2(const PyDbObjectId& id, const std::string& pszCellStyle);
    double              textHeight2(const std::string& pszCellStyle) const;
    void                setTextHeight2(double dHeight, const std::string& pszCellStyle);
    AcDb::CellAlignment alignment2(const std::string& pszCellStyle) const;
    void                setAlignment2(AcDb::CellAlignment alignment, const std::string& pszCellStyle);
    AcCmColor           color2(const std::string& pszCellStyle) const;
    void                setColor2(const AcCmColor& color, const std::string& pszCellStyle);
    AcCmColor           backgroundColor2(const std::string& pszCellStyle) const;
    void                setBackgroundColor2(const AcCmColor& color, const std::string& pszCellStyle);
    boost::python::tuple getDataType2(const std::string& pszCellStyle) const;
    void                setDataType3(AcValue::DataType nDataType, AcValue::UnitType nUnitType, const std::string& pszCellStyle);
    std::string         format3(const std::string& pszCellStyle) const;
    void                setFormat3(const std::string& pszFormat, const std::string& pszCellStyle);
    int                 cellClass(const std::string& pszCellStyle) const;
    void                setCellClass(int nClass, const std::string& pszCellStyle);
    double              rotation(const std::string& pszCellStyle) const;
    void                setRotation(double fRotation, const std::string& pszCellStyle);
    bool                isMergeAllEnabled(const std::string& pszCellStyle) const;
    void                enableMergeAll(bool bEnable, const std::string& pszCellStyle);
    double              margin(AcDb::CellMargin nMargin, const std::string& pszCellStyle) const;
    void                setMargin(AcDb::CellMargin nMargins, double fMargin, const std::string& pszCellStyle);
    AcDb::LineWeight    gridLineWeight2(AcDb::GridLineType gridLineType, const std::string& pszCellStyle) const;
    void                setGridLineWeight2(AcDb::LineWeight lineWeight, AcDb::GridLineType gridLineTypes, const std::string& pszCellStyle);
    AcCmColor           gridColor2(AcDb::GridLineType gridLineType, const std::string& pszCellStyle) const;
    void                setGridColor2(const AcCmColor& color,AcDb::GridLineType gridLineTypes, const std::string& pszCellStyle);
    AcDb::Visibility    gridVisibility2(AcDb::GridLineType gridLineType, const std::string& pszCellStyle) const;
    void                setGridVisibility2(AcDb::Visibility visible, AcDb::GridLineType gridLineTypes, const std::string& pszCellStyle);
    double              gridDoubleLineSpacing(AcDb::GridLineType gridLineType, const std::string& pszCellStyle) const;
    void                setGridDoubleLineSpacing(double fSpacing, AcDb::GridLineType gridLineTypes, const std::string& pszCellStyle);
    AcDb::GridLineStyle gridLineStyle(AcDb::GridLineType gridLineType, const std::string& pszCellStyle) const;
    void                setGridLineStyle(AcDb::GridLineStyle nLineStyle, AcDb::GridLineType gridLineTypes, const std::string& pszCellStyle);
    PyDbObjectId        gridLinetype(AcDb::GridLineType gridLineType, const std::string& pszCellStyle) const;
    void                setGridLinetype(const PyDbObjectId& id, AcDb::GridLineType gridLineTypes, const std::string& pszCellStyle);
    AcGridProperty      getGridProperty(AcDb::GridLineType nGridLineTypes, const std::string& pszCellStyle) const;
    void                setGridProperty(const AcGridProperty& gridProp, AcDb::GridLineType nGridLineTypes, const std::string& pszCellStyle);
    PyDbObjectId        getTemplate(void) const;
    void                setTemplate(const PyDbObjectId& templateId, AcDb::MergeCellStyleOption nOption);
    PyDbObjectId        removeTemplate(void);
public:
    static std::string  className();
    static PyRxClass    desc();
    static PyDbTableStyle cloneFrom(const PyRxObject& src);
    static PyDbTableStyle cast(const PyRxObject& src);
public:
    AcDbTableStyle* impObj(const std::source_location& src = std::source_location::current()) const;
};

#pragma pack (pop)