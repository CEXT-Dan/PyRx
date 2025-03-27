#pragma once
#include "PyAcadEntityImpl.h"

//------------------------------------------------------------------------------------
//PyIAcadTableImpl
class PyIAcadTableImpl : public PyIAcadEntityImpl
{
public:
    explicit PyIAcadTableImpl(IAcadTable* ptr);
    virtual ~PyIAcadTableImpl() override = default;

    CString             GetStyleName() const;
    void                SetStyleName(const CString val) const;
    int                 GetRows() const;
    void                SetRows(int val) const;
    int                 GetColumns() const;
    void                SetColumns(int val) const;
    PyAcTableDirection  GetFlowDirection() const;
    void                SetFlowDirection(int val) const;
    double              GetWidth() const;
    void                SetWidth(double val) const;
    double              GetHeight() const;
    void                SetHeight(double val) const;
    double              GetVertCellMargin() const;
    void                SetVertCellMargin(double val) const;
    double              GetHorzCellMargin() const;
    void                SetHorzCellMargin(double val) const;
    AcGePoint3d         GetInsertionPoint() const;
    void                SetInsertionPoint(const AcGePoint3d val) const;
    double              GetColumnWidth(int col) const;
    void                SetColumnWidth(double val) const;
    void                SetColumnWidth(int col, double val) const;
    double              GetRowHeight(int row) const;
    void                SetRowHeight(double val) const;
    void                SetRowHeight(int row, double val) const;
    double              GetMinimumColumnWidth(int col) const;
    double              GetMinimumRowHeight(int row) const;
    double              GetMinimumTableWidth() const;
    double              GetMinimumTableHeight() const;
    AcGeVector3d        GetDirection() const;
    void                SetDirection(const AcGeVector3d val) const;
    bool                GetTitleSuppressed() const;
    void                SetTitleSuppressed(bool val) const;
    bool                GetHeaderSuppressed() const;
    void                SetHeaderSuppressed(bool val) const;
    Int32s              GetTableStyleOverrides() const;
    void                ClearTableStyleOverrides(int flag) const;
    PyAcCellType        GetCellType(int row, int col) const;
    void                SetCellType(int row, int col, PyAcCellType val) const;
    Point3dCoordinates  GetCellExtents(int row, int col, bool bOuterCell) const;
    AcGePoint3d         GetAttachmentPoint(int row, int col) const;
    PyAcCellAlignment   GetCellAlignment(int row, int col) const;
    void                SetCellAlignment(int row, int col, PyAcCellAlignment val) const;
    bool                GetCellBackgroundColorNone(int row, int col) const;
    void                SetCellBackgroundColorNone(int row, int col, bool val) const;
    PyIAcadAcCmColorPtr GetCellBackgroundColor(int row, int col) const;
    void                SetCellBackgroundColor(int row, int col, const PyIAcadAcCmColorImpl& val) const;
    PyIAcadAcCmColorPtr GetCellContentColor(int row, int col) const;
    void                SetCellContentColor(int row, int col, const PyIAcadAcCmColorImpl& val) const;
    Int32s              GetCellStyleOverrides(int row, int col) const;
    void                DeleteCellContent(int row, int col) const;
    PyAcRowType         GetRowType(int row) const;
    CString             GetText(int row, int col) const;
    void                SetText(int row, int col, const CString& val) const;
    CString             GetCellTextStyle(int row, int col) const;
    void                SetCellTextStyle(int row, int col, const CString& val) const;
    double              GetCellTextHeight(int row, int col) const;
    void                SetCellTextHeight(int row, int col, double val) const;
    PyAcRotationAngle   GetTextRotation(int row, int col) const;
    void                SetTextRotation(int row, int col, PyAcRotationAngle val) const;
    bool                GetAutoScale(int row, int col) const;
    void                SetAutoScale(int row, int col, bool val) const;
    AcDbObjectId        GetBlockTableRecordId(int row, int col) const;
    void                SetBlockTableRecordId(int row, int col, const AcDbObjectId& val, bool autoScale) const;
    double              GetBlockScale(int row, int col) const;
    void                SetBlockScale(int row, int col, double val) const;
    double              GetBlockRotation(int row, int col) const;
    void                SetBlockRotation(int row, int col, double val) const;
    CString             GetBlockAttributeValue(int row, int col, const AcDbObjectId& val) const;
    void                SetBlockAttributeValue(int row, int col, const AcDbObjectId& id, const CString& val) const;
    PyAcLineWeight      GetCellGridLineWeight(int row, int col, PyAcCellEdgeMask mask) const;
    void                SetCellGridLineWeight(int row, int col, PyAcCellEdgeMask mask, PyAcLineWeight lw) const;
    PyIAcadAcCmColorPtr GetCellGridColor(int row, int col, PyAcCellEdgeMask mask) const;
    void                SetCellGridColor(int row, int col, PyAcCellEdgeMask mask, const PyIAcadAcCmColorImpl& val) const;
    bool                GetCellGridVisibility(int row, int col, PyAcCellEdgeMask mask) const;
    void                SetCellGridVisibility(int row, int col, PyAcCellEdgeMask mask, bool val) const;
    void                InsertColumns(int col, double width, int cols) const;
    void                DeleteColumns(int col, int cols) const;
    void                InsertRows(int row, double width, int rows) const;
    void                DeleteRows(int row, int rows) const;
    void                MergeCells(int minRow, int maxRow, int minCol, int maxCol) const;
    void                UnmergeCells(int minRow, int maxRow, int minCol, int maxCol) const;
    bool                IsMergedCell(int row, int col, int& minRow, int& maxRow, int& minCol, int& maxCol) const;
    AcDbObjectId        GetFieldId(int row, int col) const;
    void                SetFieldId(int row, int col, const AcDbObjectId& id) const;
    void                GenerateLayout() const;
    void                RecomputeTableBlock(bool bForceUpdate) const;
    boost::python::tuple HitTest(const AcGePoint3d& wpt, const AcGeVector3d& wviewVec) const;
    boost::python::tuple Select(const AcGePoint3d& wpt, const AcGeVector3d& wvwVec, const AcGeVector3d& wvwxVec, double wxaper, double wyaper, bool allowOutside) const;
    boost::python::tuple SelectSubRegion(const AcGePoint3d& wpt1, const AcGePoint3d& wpt2, const AcGeVector3d& wvwVec, const AcGeVector3d& wvwxVec, PyAcSelectType seltype, bool bIncludeCurrent) const;
    boost::python::tuple GetSubSelection() const;
    void                SetSubSelection(int minRow, int maxRow, int minCol, int maxCol) const;
    void                ReselectSubRegion() const;
    void                ClearSubSelection() const;
    bool                GetHasSubSelection() const;
    bool                GetRegenerateTableSuppressed() const;
    void                SetRegenerateTableSuppressed(bool val) const;
    CString             FormatValue(int row, int col, PyAcFormatOption fmt) const;
    boost::python::tuple GetCellDataType(int row, int col) const;
    void                SetCellDataType(int row, int col, PyAcValueDataType dataType, PyAcValueUnitType unitType) const;
    CString             GetCellFormat(int row, int col) const;
    void                SetCellFormat(int row, int col, const CString& val) const;
    AcValue             GetCellValue(int row, int col) const;
    void                SetCellValue(int row, int col, const AcValue& val) const;
    void                SetCellValueFromText(int row, int col, const CString& val, PyAcParseOption nOption) const;
    void                ResetCellValue(int row, int col) const;
    bool                IsEmpty(int row, int col) const;
    int                 CreateContent(int row, int col, int nIndex) const;
    void                MoveContent(int row, int col, int nFromIndex, int nToIndex) const;
    void                DeleteContent(int row, int col) const;
    AcValue             GetValue(int row, int col, int nContent) const;
    void                SetValue(int row, int col, int nContent, const AcValue& val) const;
    void                SetValueFromText(int row, int col, int nContent, const CString& val, PyAcParseOption nOption) const;


    //virtual /* [helpstringcontext][helpcontext][id] */ HRESULT STDMETHODCALLTYPE GetDataFormat(
    //    /* [in] */ int nRow,
    //    /* [in] */ int nCol,
    //    /* [in] */ int nContent,
    //    /* [retval][out] */ BSTR* pValue) = 0;

    //virtual /* [helpstringcontext][helpcontext][id] */ HRESULT STDMETHODCALLTYPE SetDataFormat(
    //    /* [in] */ int nRow,
    //    /* [in] */ int nCol,
    //    /* [in] */ int nContent,
    //    /* [in] */ BSTR szFormat) = 0;

    //virtual /* [helpstringcontext][helpcontext][id] */ HRESULT STDMETHODCALLTYPE GetTextString(
    //    /* [in] */ int nRow,
    //    /* [in] */ int nCol,
    //    /* [in] */ int nContent,
    //    /* [retval][out] */ BSTR* pTextString) = 0;

    //virtual /* [helpstringcontext][helpcontext][id] */ HRESULT STDMETHODCALLTYPE SetTextString(
    //    /* [in] */ int nRow,
    //    /* [in] */ int nCol,
    //    /* [in] */ int nContent,
    //    /* [in] */ BSTR text) = 0;

    //virtual /* [helpstringcontext][helpcontext][id] */ HRESULT STDMETHODCALLTYPE GetFieldId2(
    //    /* [in] */ int nRow,
    //    /* [in] */ int nCol,
    //    /* [in] */ int nContent,
    //    /* [retval][out] */ LONG_PTR* pAcDbObjectId) = 0;

    //virtual /* [helpstringcontext][helpcontext][id] */ HRESULT STDMETHODCALLTYPE SetFieldId2(
    //    /* [in] */ int nRow,
    //    /* [in] */ int nCol,
    //    /* [in] */ int nContent,
    //    /* [in] */ LONG_PTR acDbObjectId,
    //    /* [in] */ AcCellOption nflag) = 0;

    //virtual /* [helpstringcontext][helpcontext][id] */ HRESULT STDMETHODCALLTYPE GetBlockTableRecordId2(
    //    /* [in] */ int nRow,
    //    /* [in] */ int nCol,
    //    /* [in] */ int nContent,
    //    /* [retval][out] */ LONG_PTR* pAcDbObjectId) = 0;

    //virtual /* [helpstringcontext][helpcontext][id] */ HRESULT STDMETHODCALLTYPE SetBlockTableRecordId2(
    //    /* [in] */ int nRow,
    //    /* [in] */ int nCol,
    //    /* [in] */ int nContent,
    //    /* [in] */ LONG_PTR blkId,
    //    /* [in] */ VARIANT_BOOL autoFit) = 0;

    //virtual /* [helpstringcontext][helpcontext][id] */ HRESULT STDMETHODCALLTYPE GetBlockAttributeValue2(
    //    /* [in] */ int nRow,
    //    /* [in] */ int nCol,
    //    /* [in] */ int nContent,
    //    /* [in] */ LONG_PTR blkId,
    //    /* [retval][out] */ BSTR* value) = 0;

    //virtual /* [helpstringcontext][helpcontext][id] */ HRESULT STDMETHODCALLTYPE SetBlockAttributeValue2(
    //    /* [in] */ int nRow,
    //    /* [in] */ int nCol,
    //    /* [in] */ int nContent,
    //    /* [in] */ LONG_PTR blkId,
    //    /* [in] */ BSTR value) = 0;

    //virtual /* [helpstringcontext][helpcontext][id] */ HRESULT STDMETHODCALLTYPE GetCustomData(
    //    /* [in] */ int nRow,
    //    /* [in] */ int nCol,
    //    /* [in] */ BSTR szKey,
    //    /* [out] */ VARIANT* pData) = 0;

    //virtual /* [helpstringcontext][helpcontext][id] */ HRESULT STDMETHODCALLTYPE SetCustomData(
    //    /* [in] */ int nRow,
    //    /* [in] */ int nCol,
    //    /* [in] */ BSTR szKey,
    //    /* [in] */ VARIANT data) = 0;

    //virtual /* [helpstringcontext][helpcontext][id] */ HRESULT STDMETHODCALLTYPE GetCellStyle(
    //    /* [in] */ int nRow,
    //    /* [in] */ int nCol,
    //    /* [retval][out] */ BSTR* pCellStyle) = 0;

    //virtual /* [helpstringcontext][helpcontext][id] */ HRESULT STDMETHODCALLTYPE SetCellStyle(
    //    /* [in] */ int nRow,
    //    /* [in] */ int nCol,
    //    /* [in] */ BSTR szCellStyle) = 0;

    //virtual /* [helpstringcontext][helpcontext][id] */ HRESULT STDMETHODCALLTYPE GetContentColor2(
    //    /* [in] */ int nRow,
    //    /* [in] */ int nCol,
    //    /* [in] */ int nContent,
    //    /* [retval][out] */ IAcadAcCmColor** pColor) = 0;

    //virtual /* [helpstringcontext][helpcontext][id] */ HRESULT STDMETHODCALLTYPE SetContentColor2(
    //    /* [in] */ int nRow,
    //    /* [in] */ int nCol,
    //    /* [in] */ int nContent,
    //    /* [in] */ IAcadAcCmColor* pColor) = 0;

    //virtual /* [helpstringcontext][helpcontext][id] */ HRESULT STDMETHODCALLTYPE GetDataType2(
    //    /* [in] */ int nRow,
    //    /* [in] */ int nCol,
    //    /* [in] */ int nContent,
    //    /* [out] */ AcValueDataType* pDataType,
    //    /* [out] */ AcValueUnitType* pUnitType) = 0;

    //virtual /* [helpstringcontext][helpcontext][id] */ HRESULT STDMETHODCALLTYPE SetDataType2(
    //    /* [in] */ int nRow,
    //    /* [in] */ int nCol,
    //    /* [in] */ int nContent,
    //    /* [in] */ AcValueDataType dataType,
    //    /* [in] */ AcValueUnitType unitType) = 0;

    //virtual /* [helpstringcontext][helpcontext][id] */ HRESULT STDMETHODCALLTYPE GetTextStyle2(
    //    /* [in] */ int nRow,
    //    /* [in] */ int nCol,
    //    /* [in] */ int nContent,
    //    /* [retval][out] */ BSTR* pbstrStyleName) = 0;

    //virtual /* [helpstringcontext][helpcontext][id] */ HRESULT STDMETHODCALLTYPE SetTextStyle2(
    //    /* [in] */ int nRow,
    //    /* [in] */ int nCol,
    //    /* [in] */ int nContent,
    //    /* [in] */ BSTR bstrStyleName) = 0;

    //virtual /* [helpstringcontext][helpcontext][id] */ HRESULT STDMETHODCALLTYPE GetTextHeight2(
    //    /* [in] */ int nRow,
    //    /* [in] */ int nCol,
    //    /* [in] */ int nContent,
    //    /* [retval][out] */ double* pHeight) = 0;

    //virtual /* [helpstringcontext][helpcontext][id] */ HRESULT STDMETHODCALLTYPE SetTextHeight2(
    //    /* [in] */ int nRow,
    //    /* [in] */ int nCol,
    //    /* [in] */ int nContent,
    //    /* [in] */ double height) = 0;

    //virtual /* [helpstringcontext][helpcontext][id] */ HRESULT STDMETHODCALLTYPE GetRotation(
    //    /* [in] */ int nRow,
    //    /* [in] */ int nCol,
    //    /* [in] */ int nContent,
    //    /* [retval][out] */ double* pValue) = 0;

    //virtual /* [helpstringcontext][helpcontext][id] */ HRESULT STDMETHODCALLTYPE SetRotation(
    //    /* [in] */ int nRow,
    //    /* [in] */ int nCol,
    //    /* [in] */ int nContent,
    //    /* [in] */ double value) = 0;

    //virtual /* [helpstringcontext][helpcontext][id] */ HRESULT STDMETHODCALLTYPE GetAutoScale2(
    //    /* [in] */ int nRow,
    //    /* [in] */ int nCol,
    //    /* [in] */ int nContent,
    //    /* [retval][out] */ VARIANT_BOOL* bAutoScale) = 0;

    //virtual /* [helpstringcontext][helpcontext][id] */ HRESULT STDMETHODCALLTYPE SetAutoScale2(
    //    /* [in] */ int nRow,
    //    /* [in] */ int nCol,
    //    /* [in] */ int nContent,
    //    /* [in] */ VARIANT_BOOL bAutoFit) = 0;

    //virtual /* [helpstringcontext][helpcontext][id] */ HRESULT STDMETHODCALLTYPE GetScale(
    //    /* [in] */ int nRow,
    //    /* [in] */ int nCol,
    //    /* [in] */ int nContent,
    //    /* [retval][out] */ double* pScale) = 0;

    //virtual /* [helpstringcontext][helpcontext][id] */ HRESULT STDMETHODCALLTYPE SetScale(
    //    /* [in] */ int nRow,
    //    /* [in] */ int nCol,
    //    /* [in] */ int nContent,
    //    /* [in] */ double scale) = 0;

    //virtual /* [helpstringcontext][helpcontext][id] */ HRESULT STDMETHODCALLTYPE RemoveAllOverrides(
    //    /* [in] */ int nRow,
    //    /* [in] */ int nCol) = 0;

    //virtual /* [helpstringcontext][helpcontext][id] */ HRESULT STDMETHODCALLTYPE GetGridLineWeight2(
    //    /* [in] */ int nRow,
    //    /* [in] */ int nCol,
    //    /* [in] */ AcGridLineType nGridLineType,
    //    /* [retval][out] */ ACAD_LWEIGHT* pLineWeight) = 0;

    //virtual /* [helpstringcontext][helpcontext][id] */ HRESULT STDMETHODCALLTYPE SetGridLineWeight2(
    //    /* [in] */ int nRow,
    //    /* [in] */ int nCol,
    //    /* [in] */ AcGridLineType nGridLineType,
    //    /* [in] */ ACAD_LWEIGHT lineWeight) = 0;

    //virtual /* [helpstringcontext][helpcontext][id] */ HRESULT STDMETHODCALLTYPE GetGridLinetype(
    //    /* [in] */ int nRow,
    //    /* [in] */ int nCol,
    //    /* [in] */ AcGridLineType nGridLineType,
    //    /* [retval][out] */ LONG_PTR* pacDbObjId) = 0;

    //virtual /* [helpstringcontext][helpcontext][id] */ HRESULT STDMETHODCALLTYPE SetGridLinetype(
    //    /* [in] */ int nRow,
    //    /* [in] */ int nCol,
    //    /* [in] */ AcGridLineType nGridLineType,
    //    /* [in] */ LONG_PTR idLinetype) = 0;

    //virtual /* [helpstringcontext][helpcontext][id] */ HRESULT STDMETHODCALLTYPE GetGridColor2(
    //    /* [in] */ int nRow,
    //    /* [in] */ int nCol,
    //    /* [in] */ AcGridLineType nGridLineType,
    //    /* [retval][out] */ IAcadAcCmColor** pColor) = 0;

    //virtual /* [helpstringcontext][helpcontext][id] */ HRESULT STDMETHODCALLTYPE SetGridColor2(
    //    /* [in] */ int nRow,
    //    /* [in] */ int nCol,
    //    /* [in] */ AcGridLineType nGridLineType,
    //    /* [in] */ IAcadAcCmColor* pColor) = 0;

    //virtual /* [helpstringcontext][helpcontext][id] */ HRESULT STDMETHODCALLTYPE GetGridVisibility2(
    //    /* [in] */ int nRow,
    //    /* [in] */ int nCol,
    //    /* [in] */ AcGridLineType nGridLineType,
    //    /* [retval][out] */ VARIANT_BOOL* bVisible) = 0;

    //virtual /* [helpstringcontext][helpcontext][id] */ HRESULT STDMETHODCALLTYPE SetGridVisibility2(
    //    /* [in] */ int nRow,
    //    /* [in] */ int nCol,
    //    /* [in] */ AcGridLineType nGridLineType,
    //    /* [in] */ VARIANT_BOOL bVisible) = 0;

    //virtual /* [helpstringcontext][helpcontext][id] */ HRESULT STDMETHODCALLTYPE GetGridDoubleLineSpacing(
    //    /* [in] */ int nRow,
    //    /* [in] */ int nCol,
    //    /* [in] */ AcGridLineType nGridLineType,
    //    /* [retval][out] */ double* pValue) = 0;

    //virtual /* [helpstringcontext][helpcontext][id] */ HRESULT STDMETHODCALLTYPE SetGridDoubleLineSpacing(
    //    /* [in] */ int nRow,
    //    /* [in] */ int nCol,
    //    /* [in] */ AcGridLineType nGridLineType,
    //    /* [in] */ double fSpacing) = 0;

    //virtual /* [helpstringcontext][helpcontext][id][propput] */ HRESULT STDMETHODCALLTYPE put_EnableBreak(
    //    /* [in] */ VARIANT_BOOL bEnable) = 0;

    //virtual /* [helpstringcontext][helpcontext][id] */ HRESULT STDMETHODCALLTYPE GetBreakHeight(
    //    /* [in] */ int nIndex,
    //    /* [retval][out] */ double* pHeight) = 0;

    //virtual /* [helpstringcontext][helpcontext][id] */ HRESULT STDMETHODCALLTYPE SetBreakHeight(
    //    /* [in] */ int nIndex,
    //    /* [in] */ double height) = 0;

    //virtual /* [helpstringcontext][helpcontext][id] */ HRESULT STDMETHODCALLTYPE GetContentType(
    //    /* [in] */ int nRow,
    //    /* [in] */ int nCol,
    //    /* [retval][out] */ AcCellContentType* pType) = 0;

    //virtual /* [helpstringcontext][helpcontext][id] */ HRESULT STDMETHODCALLTYPE GetMargin(
    //    /* [in] */ int nRow,
    //    /* [in] */ int nCol,
    //    /* [in] */ AcCellMargin nMargin,
    //    /* [retval][out] */ double* pValue) = 0;

    //virtual /* [helpstringcontext][helpcontext][id] */ HRESULT STDMETHODCALLTYPE SetMargin(
    //    /* [in] */ int nRow,
    //    /* [in] */ int nCol,
    //    /* [in] */ AcCellMargin nMargins,
    //    /* [in] */ double fMargin) = 0;

    //virtual /* [helpstringcontext][helpcontext][id] */ HRESULT STDMETHODCALLTYPE GetContentLayout(
    //    /* [in] */ int row,
    //    /* [in] */ int col,
    //    /* [retval][out] */ AcCellContentLayout* pLayout) = 0;

    //virtual /* [helpstringcontext][helpcontext][id] */ HRESULT STDMETHODCALLTYPE SetContentLayout(
    //    /* [in] */ int row,
    //    /* [in] */ int col,
    //    /* [in] */ AcCellContentLayout nLayout) = 0;

    //virtual /* [helpstringcontext][helpcontext][id] */ HRESULT STDMETHODCALLTYPE GetOverride(
    //    /* [in] */ int nRow,
    //    /* [in] */ int nCol,
    //    /* [in] */ int nContent,
    //    /* [retval][out] */ AcCellProperty* pValue) = 0;

    //virtual /* [helpstringcontext][helpcontext][id] */ HRESULT STDMETHODCALLTYPE SetOverride(
    //    /* [in] */ int nRow,
    //    /* [in] */ int nCol,
    //    /* [in] */ int nContent,
    //    /* [in] */ AcCellProperty nProp) = 0;

    //virtual /* [helpstringcontext][helpcontext][id] */ HRESULT STDMETHODCALLTYPE GetGridLineStyle(
    //    /* [in] */ int nRow,
    //    /* [in] */ int nCol,
    //    /* [in] */ AcGridLineType nGridLineType,
    //    /* [retval][out] */ AcGridLineStyle* pStyle) = 0;

    //virtual /* [helpstringcontext][helpcontext][id] */ HRESULT STDMETHODCALLTYPE SetGridLineStyle(
    //    /* [in] */ int nRow,
    //    /* [in] */ int nCol,
    //    /* [in] */ AcGridLineType nGridLineTypes,
    //    /* [in] */ AcGridLineStyle nLineStyle) = 0;

    //virtual /* [helpstringcontext][helpcontext][id] */ HRESULT STDMETHODCALLTYPE InsertRowsAndInherit(
    //    /* [in] */ int nIndex,
    //    /* [in] */ int nInheritFrom,
    //    /* [in] */ int nNumRows) = 0;

    //virtual /* [helpstringcontext][helpcontext][id] */ HRESULT STDMETHODCALLTYPE InsertColumnsAndInherit(
    //    /* [in] */ int col,
    //    /* [in] */ int nInheritFrom,
    //    /* [in] */ int nNumCols) = 0;

    //virtual /* [helpstringcontext][helpcontext][id] */ HRESULT STDMETHODCALLTYPE GetHasFormula(
    //    /* [in] */ int nRow,
    //    /* [in] */ int nCol,
    //    /* [in] */ int nContent,
    //    /* [retval][out] */ VARIANT_BOOL* bValue) = 0;

    //virtual /* [helpstringcontext][helpcontext][id] */ HRESULT STDMETHODCALLTYPE GetFormula(
    //    /* [in] */ int nRow,
    //    /* [in] */ int nCol,
    //    /* [in] */ int nContent,
    //    /* [retval][out] */ BSTR* pszFormula) = 0;

    //virtual /* [helpstringcontext][helpcontext][id] */ HRESULT STDMETHODCALLTYPE SetFormula(
    //    /* [in] */ int nRow,
    //    /* [in] */ int nCol,
    //    /* [in] */ int nContent,
    //    /* [in] */ BSTR pszFormula) = 0;

    //virtual /* [helpstringcontext][helpcontext][id] */ HRESULT STDMETHODCALLTYPE IsContentEditable(
    //    /* [in] */ int nRow,
    //    /* [in] */ int nCol,
    //    /* [retval][out] */ VARIANT_BOOL* bValue) = 0;

    //virtual /* [helpstringcontext][helpcontext][id] */ HRESULT STDMETHODCALLTYPE IsFormatEditable(
    //    /* [in] */ int nRow,
    //    /* [in] */ int nCol,
    //    /* [retval][out] */ VARIANT_BOOL* bValue) = 0;

    //virtual /* [helpstringcontext][helpcontext][id] */ HRESULT STDMETHODCALLTYPE GetCellState(
    //    /* [in] */ int nRow,
    //    /* [in] */ int nCol,
    //    /* [retval][out] */ AcCellState* pCellState) = 0;

    //virtual /* [helpstringcontext][helpcontext][id] */ HRESULT STDMETHODCALLTYPE SetCellState(
    //    /* [in] */ int nRow,
    //    /* [in] */ int nCol,
    //    /* [in] */ AcCellState nLock) = 0;

    //virtual /* [helpstringcontext][helpcontext][id] */ HRESULT STDMETHODCALLTYPE EnableMergeAll(
    //    /* [in] */ int nRow,
    //    /* [in] */ int nCol,
    //    /* [in] */ VARIANT_BOOL bEnable) = 0;

    //virtual /* [helpstringcontext][helpcontext][id] */ HRESULT STDMETHODCALLTYPE IsMergeAllEnabled(
    //    /* [in] */ int nRow,
    //    /* [in] */ int nCol,
    //    /* [retval][out] */ VARIANT_BOOL* bValue) = 0;

    //virtual /* [helpstringcontext][helpcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_BreaksEnabled(
    //    /* [retval][out] */ VARIANT_BOOL* bEnabled) = 0;

    //virtual /* [helpstringcontext][helpcontext][id][propput] */ HRESULT STDMETHODCALLTYPE put_BreaksEnabled(
    //    /* [in] */ VARIANT_BOOL bEnabled) = 0;

    //virtual /* [helpstringcontext][helpcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_RepeatTopLabels(
    //    /* [retval][out] */ VARIANT_BOOL* bEnabled) = 0;

    //virtual /* [helpstringcontext][helpcontext][id][propput] */ HRESULT STDMETHODCALLTYPE put_RepeatTopLabels(
    //    /* [in] */ VARIANT_BOOL bEnabled) = 0;

    //virtual /* [helpstringcontext][helpcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_RepeatBottomLabels(
    //    /* [retval][out] */ VARIANT_BOOL* bEnabled) = 0;

    //virtual /* [helpstringcontext][helpcontext][id][propput] */ HRESULT STDMETHODCALLTYPE put_RepeatBottomLabels(
    //    /* [in] */ VARIANT_BOOL bEnabled) = 0;

    //virtual /* [helpstringcontext][helpcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_TableBreakFlowDirection(
    //    /* [retval][out] */ AcTableFlowDirection* pDir) = 0;

    //virtual /* [helpstringcontext][helpcontext][id][propput] */ HRESULT STDMETHODCALLTYPE put_TableBreakFlowDirection(
    //    /* [in] */ AcTableFlowDirection dir) = 0;

    //virtual /* [helpstringcontext][helpcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_AllowManualPositions(
    //    /* [retval][out] */ VARIANT_BOOL* bEnabled) = 0;

    //virtual /* [helpstringcontext][helpcontext][id][propput] */ HRESULT STDMETHODCALLTYPE put_AllowManualPositions(
    //    /* [in] */ VARIANT_BOOL bEnabled) = 0;

    //virtual /* [helpstringcontext][helpcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_AllowManualHeights(
    //    /* [retval][out] */ VARIANT_BOOL* bEnabled) = 0;

    //virtual /* [helpstringcontext][helpcontext][id][propput] */ HRESULT STDMETHODCALLTYPE put_AllowManualHeights(
    //    /* [in] */ VARIANT_BOOL bEnabled) = 0;

    //virtual /* [helpstringcontext][helpcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_TableBreakHeight(
    //    /* [retval][out] */ double* pHeight) = 0;

    //virtual /* [helpstringcontext][helpcontext][id][propput] */ HRESULT STDMETHODCALLTYPE put_TableBreakHeight(
    //    /* [in] */ double height) = 0;

    //virtual /* [helpstringcontext][helpcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_BreakSpacing(
    //    /* [retval][out] */ double* pSpacing) = 0;

    //virtual /* [helpstringcontext][helpcontext][id][propput] */ HRESULT STDMETHODCALLTYPE put_BreakSpacing(
    //    /* [in] */ double spacing) = 0;

    //virtual /* [helpstringcontext][helpcontext][id] */ HRESULT STDMETHODCALLTYPE GetColumnName(
    //    /* [in] */ int nIndex,
    //    /* [retval][out] */ BSTR* name) = 0;

    //virtual /* [helpstringcontext][helpcontext][id] */ HRESULT STDMETHODCALLTYPE SetColumnName(
    //    /* [in] */ int nIndex,
    //    /* [in] */ BSTR name) = 0;

    //virtual /* [helpstringcontext][helpcontext][id] */ HRESULT STDMETHODCALLTYPE SetToolTip(
    //    /* [in] */ int nRow,
    //    /* [in] */ int nCol,
    //    /* [in] */ BSTR tip) = 0;


    IAcadTable* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadTablePtr = std::unique_ptr<PyIAcadTableImpl>;
