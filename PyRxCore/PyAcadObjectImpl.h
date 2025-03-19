#pragma once
#include "PyAcad.h" 
#include "atlsafe.h"

#pragma pack (push, 8)
class PyIAcadMenuGroupsImpl;
using PyIAcadMenuGroupsPtr = std::unique_ptr<PyIAcadMenuGroupsImpl>;
class PyIAcadPopupMenuImpl;
using PyIAcadPopupMenuPtr = std::unique_ptr<PyIAcadPopupMenuImpl>;
class PyIAcadPopupMenusImpl;
using PyIAcadPopupMenusPtr = std::unique_ptr<PyIAcadPopupMenusImpl>;
class PyIAcadToolbarsImpl;
using PyIAcadToolbarsPtr = std::unique_ptr<PyIAcadToolbarsImpl>;
class PyIAcadToolbarImpl;
using PyIAcadToolbarPtr = std::unique_ptr<PyIAcadToolbarImpl>;
class PyIAcadBlockImpl;
using PyIAcadBlockPtr = std::unique_ptr<PyIAcadBlockImpl>;


//------------------------------------------------------------------------------------
//PyIAcadAcCmColorImpl
class PyIAcadAcCmColorImpl
{
public:
    explicit PyIAcadAcCmColorImpl(IAcadAcCmColor* ptr);
    virtual ~PyIAcadAcCmColorImpl() = default;
    void            SetEntityColor(long val) const;
    long            GetEntityColor() const;
    CString         GetColorName() const;
    CString         GetBookName() const;
    void            SetNames(const CString& colorName, const CString& bookName) const;
    void            Delete() const;
    long            GetRed() const;
    long            GetGreen() const;
    long            GetBlue() const;
    void            SetRGB(long Red, long Green, long Blue) const;
    PyAcColorMethod GetColorMethod() const;
    void            SetColorMethod(PyAcColorMethod flags) const;
    PyAcColor       GetColorIndex() const;
    void            SetColorIndex(PyAcColor val) const;
    void            SetColorBookColor(const CString& colorName, const CString& bookName) const;
    IAcadAcCmColor* impObj(const std::source_location& src = std::source_location::current()) const;

    static          std::unique_ptr<PyIAcadAcCmColorImpl> CreateInstance();
protected:
    IAcadAcCmColorPtr m_pimpl;
};
using PyIAcadAcCmColorPtr = std::unique_ptr<PyIAcadAcCmColorImpl>;

//------------------------------------------------------------------------------------
//PyIAcadHyperlinkImpl
class PyIAcadHyperlinkImpl
{
public:
    explicit PyIAcadHyperlinkImpl(IAcadHyperlink* ptr);
    virtual ~PyIAcadHyperlinkImpl() = default;
    CString         GetURL() const;
    void            SetURL(const CString& val) const;
    CString         GetURLDescription() const;
    void            SetURLDescription(const CString& val) const;
    void            Delete() const;
    CString         GetURLNamedLocation() const;
    void            SetURLNamedLocation(const CString& val) const;
    IAcadHyperlink* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    IAcadHyperlinkPtr m_pimpl;
};
using PyIAcadHyperlinkPtr = std::unique_ptr<PyIAcadHyperlinkImpl>;

//------------------------------------------------------------------------------------
//PyIAcadHyperlinksImpl
class PyIAcadHyperlinksImpl
{
public:
    explicit PyIAcadHyperlinksImpl(IAcadHyperlinks* ptr);
    virtual ~PyIAcadHyperlinksImpl() = default;
    PyIAcadHyperlinkPtr    GetItem(long val) const;
    long                   GetCount() const;
    PyIAcadHyperlinkPtr    Add(const CString& name, const CString& description, const CString& namedLocation) const;
    IAcadHyperlinks* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    IAcadHyperlinksPtr m_pimpl;
};
using PyIAcadHyperlinksPtr = std::unique_ptr<PyIAcadHyperlinksImpl>;

//------------------------------------------------------------------------------------
//PyIAcadSectionTypeSettingsImpl
class PyIAcadSectionTypeSettingsImpl
{
public:
    explicit PyIAcadSectionTypeSettingsImpl(IAcadSectionTypeSettings* ptr);
    virtual ~PyIAcadSectionTypeSettingsImpl() = default;

    PyAcSectionGeneration   GetGenerationOptions() const;
    void                    SetGenerationOptions(PyAcSectionGeneration val) const;
    AcDbObjectIdArray       GetSourceObjects() const;
    void                    SetSourceObjects(const AcDbObjectIdArray& ids) const;
    PyIAcadBlockPtr         GetDestinationBlock() const;
    void                    SetDestinationBlock(const PyIAcadBlockImpl& val) const;
    CString                 GetDestinationFile() const;
    void                    SetDestinationFile(const CString& val) const;
    PyIAcadAcCmColorPtr     GetIntersectionBoundaryColor() const;
    void                    SetIntersectionBoundaryColor(const PyIAcadAcCmColorImpl& val) const;
    CString                 GetIntersectionBoundaryLayer() const;
    void                    SetIntersectionBoundaryLayer(const CString& val) const;
    CString                 GetIntersectionBoundaryLinetype() const;
    void                    SetIntersectionBoundaryLinetype(const CString& val) const;
    double                  GetIntersectionBoundaryLinetypeScale() const;
    void                    SetIntersectionBoundaryLinetypeScale(double val) const;
    CString                 GetIntersectionBoundaryPlotStyleName() const;
    void                    SetIntersectionBoundaryPlotStyleName(const CString& val) const;
    PyAcLineWeight          GetIntersectionBoundaryLineweight() const;
    void                    SetIntersectionBoundaryLineweight(PyAcLineWeight val) const;
    bool                    GetIntersectionBoundaryDivisionLines() const;
    void                    SetIntersectionBoundaryDivisionLines(bool val) const;
    bool                    GetIntersectionFillVisible() const;
    void                    SetIntersectionFillVisible(bool val) const;
    PyAcPatternType         GetIntersectionFillHatchPatternType() const;
    void                    SetIntersectionFillHatchPatternType(PyAcPatternType val) const;
    CString                 GetIntersectionFillHatchPatternName() const;
    void                    SetIntersectionFillHatchPatternName(const CString& val) const;
    double                  GetIntersectionFillHatchAngle() const;
    void                    SetIntersectionFillHatchAngle(double val) const;
    double                  GetIntersectionFillHatchScale() const;
    void                    SetIntersectionFillHatchScale(double val) const;
    double                  GetIntersectionFillHatchSpacing() const;
    void                    SetIntersectionFillHatchSpacing(double val) const;
    PyIAcadAcCmColorPtr     GetIntersectionFillColor() const;
    void                    SetIntersectionFillColor(const PyIAcadAcCmColorImpl& val) const;
    CString                 GetIntersectionFillLayer() const;
    void                    SetIntersectionFillLayer(const CString& val) const;
    CString                 GetIntersectionFillLinetype() const;
    void                    SetIntersectionFillLinetype(const CString& val) const;
    double                  GetIntersectionFillLinetypeScale() const;
    void                    SetIntersectionFillLinetypeScale(double val) const;
    void                    SetIntersectionFillPlotStyleName(const CString& val) const;
    CString                 GetIntersectionFillPlotStyleName() const;
    PyAcLineWeight          GetIntersectionFillLineweight() const;
    void                    SetIntersectionFillLineweight(PyAcLineWeight val) const;
    long                    GetIntersectionFillFaceTransparency() const;
    void                    SetIntersectionFillFaceTransparency(long val) const;
    bool                    GetBackgroundLinesVisible() const;
    void                    SetBackgroundLinesVisible(bool val) const;
    bool                    GetBackgroundLinesHiddenLine() const;
    void                    SetBackgroundLinesHiddenLine(bool val) const;
    PyIAcadAcCmColorPtr     GetBackgroundLinesColor() const;
    void                    SetBackgroundLinesColor(const PyIAcadAcCmColorImpl& val) const;
    CString                 GetBackgroundLinesLayer() const;
    void                    SetBackgroundLinesLayer(const CString& val) const;
    CString                 GetBackgroundLinesLinetype() const;
    void                    SetBackgroundLinesLinetype(const CString& val) const;
    double                  GetBackgroundLinesLinetypeScale() const;
    void                    SetBackgroundLinesLinetypeScale(double val) const;
    CString                 GetBackgroundLinesPlotStyleName() const;
    void                    SetBackgroundLinesPlotStyleName(const CString& val) const;
    PyAcLineWeight          GetBackgroundLinesLineweight() const;
    void                    SetBackgroundLinesLineweight(PyAcLineWeight val) const;
    bool                    GetForegroundLinesVisible() const;
    void                    SetForegroundLinesVisible(bool val) const;
    bool                    GetForegroundLinesHiddenLine() const;
    void                    SetForegroundLinesHiddenLine(bool val) const;
    PyIAcadAcCmColorPtr     GetForegroundLinesColor() const;
    void                    SetForegroundLinesColor(const PyIAcadAcCmColorImpl& val) const;
    CString                 GetForegroundLinesLayer() const;
    void                    SetForegroundLinesLayer(const CString& val) const;
    CString                 GetForegroundLinesLinetype() const;
    void                    SetForegroundLinesLinetype(const CString& val) const;
    double                  GetForegroundLinesLinetypeScale() const;
    void                    SetForegroundLinesLinetypeScale(double val) const;
    CString                 GetForegroundLinesPlotStyleName() const;
    void                    SetForegroundLinesPlotStyleName(const CString& val) const;
    PyAcLineWeight          GetForegroundLinesLineweight() const;
    void                    SetForegroundLinesLineweight(PyAcLineWeight val) const;
    long                    GetForegroundLinesFaceTransparency() const;
    void                    SetForegroundLinesFaceTransparency(long val) const;
    long                    GetForegroundLinesEdgeTransparency() const;
    void                    SetForegroundLinesEdgeTransparency(long val) const;
    bool                    GetCurveTangencyLinesVisible() const;
    void                    SetCurveTangencyLinesVisible(bool val) const;
    PyIAcadAcCmColorPtr     GetCurveTangencyLinesColor() const;
    void                    SetCurveTangencyLinesColor(const PyIAcadAcCmColorImpl& val) const;
    CString                 GetCurveTangencyLinesLayer() const;
    void                    SetCurveTangencyLinesLayer(const CString& val) const;
    CString                 GetCurveTangencyLinesLinetype() const;
    void                    SetCurveTangencyLinesLinetype(const CString& val) const;
    double                  GetCurveTangencyLinesLinetypeScale() const;
    void                    SetCurveTangencyLinesLinetypeScale(double val) const;
    CString                 GetCurveTangencyLinesPlotStyleName() const;
    void                    SetCurveTangencyLinesPlotStyleName(const CString& val) const;
    PyAcLineWeight          GetCurveTangencyLinesLineweight() const;
    void                    SetCurveTangencyLinesLineweight(PyAcLineWeight val) const;
    IAcadSectionTypeSettings* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    IAcadSectionTypeSettingsPtr m_pimpl;
    //IAcadSectionTypeSettings2
};

//------------------------------------------------------------------------------------
//PyIAcadDatabasePreferencesImpl
class PyIAcadDatabasePreferencesImpl
{
public:
    explicit PyIAcadDatabasePreferencesImpl(IAcadDatabasePreferences* ptr);
    virtual ~PyIAcadDatabasePreferencesImpl() = default;

    bool            GetSolidFill() const;
    void            SetSolidFill(bool val) const;
    bool            GetXRefEdit() const;
    void            SetXRefEdit(bool val) const;
    bool            GetXRefLayerVisibility() const;
    void            SetXRefLayerVisibility(bool val) const;
    bool            GetOLELaunch() const;
    void            SetOLELaunch(bool val) const;
    bool            GetAllowLongSymbolNames() const;
    void            SetAllowLongSymbolNames(bool val) const;
    bool            GetObjectSortBySelection() const;
    void            SetObjectSortBySelection(bool val) const;
    bool            GetObjectSortBySnap() const;
    void            SetObjectSortBySnap(bool val) const;
    bool            GetObjectSortByRedraws() const;
    void            SetObjectSortByRedraws(bool val) const;
    bool            GetObjectSortByRegens() const;
    void            SetObjectSortByRegens(bool val) const;
    bool            GetObjectSortByPlotting() const;
    void            SetObjectSortByPlotting(bool val) const;
    bool            GetObjectSortByPSOutput() const;
    void            SetObjectSortByPSOutput(bool val) const;
    void            SetContourLinesPerSurface(long val) const;
    long            GetContourLinesPerSurface() const;
    void            SetDisplaySilhouette(bool val) const;
    bool            GetDisplaySilhouette() const;
    void            SetMaxActiveViewports(long val) const;
    long            GetMaxActiveViewports() const;
    void            SetRenderSmoothness(double val) const;
    double          GetRenderSmoothness() const;
    void            SetSegmentPerPolyline(long val) const;
    long            GetSegmentPerPolyline() const;
    void            SetTextFrameDisplay(bool val) const;
    bool            GetTextFrameDisplay() const;
    void            SetLineweight(PyAcLineWeight val) const;
    PyAcLineWeight  GetLineweight() const;
    void            SetLineWeightDisplay(bool val) const;
    bool            GetLineWeightDisplay() const;

    IAcadDatabasePreferences* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    IAcadDatabasePreferencesPtr m_pimpl;
};
using PyIAcadDatabasePreferencesPtr = std::unique_ptr<PyIAcadDatabasePreferencesImpl>;

//------------------------------------------------------------------------------------
//PyIAcadPreferencesFilesImpl
class PyIAcadPreferencesFilesImpl
{
public:
    explicit PyIAcadPreferencesFilesImpl(IAcadPreferencesFiles* ptr);
    virtual ~PyIAcadPreferencesFilesImpl() = default;
    void        SetSupportPath(const CString& val) const;
    CString     GetSupportPath() const;
    void        SetDriversPath(const CString& val) const;
    CString     GetDriversPath() const;
    void        SetMenuFile(const CString& val) const;
    CString     GetMenuFile() const;
    void        SetEnterpriseMenuFile(const CString& val) const;
    CString     GetEnterpriseMenuFile() const;
    void        SetCustomIconPath(const CString& val) const;
    CString     GetCustomIconPath() const;
    void        SetHelpFilePath(const CString& val) const;
    CString     GetHelpFilePath() const;
    void        SetDefaultInternetURL(const CString& val) const;
    CString     GetDefaultInternetURL() const;
    CString     GetConfigFile() const;
    CString     GetLicenseServer() const;
    void        SetTextEditor(const CString& val) const;
    CString     GetTextEditor() const;
    void        SetMainDictionary(const CString& val) const;
    CString     GetMainDictionary() const;
    void        SetCustomDictionary(const CString& val) const;
    CString     GetCustomDictionary() const;
    void        SetAltFontFile(const CString& val) const;
    CString     GetAltFontFile() const;
    void        SetFontFileMap(const CString& val) const;
    CString     GetFontFileMap() const;
    void        SetPrintFile(const CString& val) const;
    CString     GetPrintFile() const;
    void        SetPrintSpoolExecutable(const CString& val) const;
    CString     GetPrintSpoolExecutable() const;
    void        SetPostScriptPrologFile(const CString& val) const;
    CString     GetPostScriptPrologFile() const;
    void        SetPrintSpoolerPath(const CString& val) const;
    CString     GetPrintSpoolerPath() const;
    void        SetAutoSavePath(const CString& val) const;
    CString     GetAutoSavePath() const;
    void        SetTemplateDwgPath(const CString& val) const;
    CString     GetTemplateDwgPath() const;
    void        SetLogFilePath(const CString& val) const;
    CString     GetLogFilePath() const;
    void        SetTempFilePath(const CString& val) const;
    CString     GetTempFilePath() const;
    void        SetTempXrefPath(const CString& val) const;
    CString     GetTempXrefPath() const;
    void        SetTextureMapPath(const CString& val) const;
    CString     GetTextureMapPath() const;
    void        SetAltTabletMenuFile(const CString& val) const;
    CString     GetAltTabletMenuFile() const;
    void        SetProjectFilePath(const CString& projectName, const CString& projectFilePath) const;
    CString     GetProjectFilePath(const CString& projectName) const;
    void        SetPrinterConfigPath(const CString& val) const;
    CString     GetPrinterConfigPath() const;
    void        SetPrinterDescPath(const CString& val) const;
    CString     GetPrinterDescPath() const;
    void        SetPrinterStyleSheetPath(const CString& val) const;
    CString     GetPrinterStyleSheetPath() const;
    void        SetWorkspacePath(const CString& val) const;
    CString     GetWorkspacePath() const;
    void        SetObjectARXPath(const CString& val) const;
    CString     GetObjectARXPath() const;
    void        SetColorBookPath(const CString& val) const;
    CString     GetColorBookPath() const;
    void        SetToolPalettePath(const CString& val) const;
    CString     GetToolPalettePath() const;
    void        SetQNewTemplateFile(const CString& val) const;
    CString     GetQNewTemplateFile() const;
    void        SetPlotLogFilePath(const CString& val) const;
    CString     GetPlotLogFilePath() const;
    void        SetPageSetupOverridesTemplateFile(const CString& val) const;
    CString     GetPageSetupOverridesTemplateFile() const;
    void        SetActiveInvProject(const CString& val) const;
    CString     GetActiveInvProject() const;

    IAcadPreferencesFiles* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    IAcadPreferencesFilesPtr m_pimpl;
};
using PyIAcadPreferencesFilesPtr = std::unique_ptr<PyIAcadPreferencesFilesImpl>;

//------------------------------------------------------------------------------------
//PyIAcadPreferencesDisplayImpl
class PyIAcadPreferencesDisplayImpl
{
public:
    explicit PyIAcadPreferencesDisplayImpl(IAcadPreferencesDisplay* ptr);
    virtual ~PyIAcadPreferencesDisplayImpl() = default;
    void                SetLayoutDisplayMargins(bool val) const;
    bool                GetLayoutDisplayMargins() const;
    void                SetLayoutDisplayPaper(bool val) const;
    bool                GetLayoutDisplayPaper() const;
    void                SetLayoutDisplayPaperShadow(bool val) const;
    bool                GetLayoutDisplayPaperShadow() const;
    void                SetLayoutShowPlotSetup(bool val) const;
    bool                GetLayoutShowPlotSetup() const;
    void                SetLayoutCreateViewport(bool val) const;
    bool                GetLayoutCreateViewport() const;
    void                SetDisplayScrollBars(bool val) const;
    bool                GetDisplayScrollBars() const;
    void                SetDisplayScreenMenu(bool val) const;
    bool                GetDisplayScreenMenu() const;
    void                SetCursorSize(int val) const;
    int                 GetCursorSize() const;
    void                SetDockedVisibleLines(int val) const;
    int                 GetDockedVisibleLines() const;
    void                SetShowRasterImage(bool val) const;
    bool                GetShowRasterImage() const;
    void                SetGraphicsWinModelBackgrndColor(COLORREF val) const;
    COLORREF            GetGraphicsWinModelBackgrndColor() const;
    void                SetModelCrosshairColor(COLORREF val) const;
    COLORREF            GetModelCrosshairColor() const;
    void                SetGraphicsWinLayoutBackgrndColor(COLORREF val) const;
    COLORREF            GetGraphicsWinLayoutBackgrndColor() const;
    void                SetTextWinBackgrndColor(COLORREF val) const;
    COLORREF            GetTextWinBackgrndColor() const;
    void                SetTextWinTextColor(COLORREF val) const;
    COLORREF            GetTextWinTextColor() const;
    void                SetLayoutCrosshairColor(COLORREF val) const;
    COLORREF            GetLayoutCrosshairColor() const;
    void                SetAutoTrackingVecColor(COLORREF val) const;
    COLORREF            GetAutoTrackingVecColor() const;
    void                SetTextFont(const CString& val) const;
    CString             GetTextFont() const;
    void                SetTextFontStyle(const PyAcTextFontStyle& val) const;
    PyAcTextFontStyle   GetTextFontStyle() const;
    void                SetTextFontSize(int val) const;
    int                 GetTextFontSize() const;
    void                SetHistoryLines(int val) const;
    int                 GetHistoryLines() const;
    void                SetMaxAutoCADWindow(bool val) const;
    bool                GetMaxAutoCADWindow() const;
    void                SetDisplayLayoutTabs(bool val) const;
    bool                GetDisplayLayoutTabs() const;
    void                SetImageFrameHighlight(bool val) const;
    bool                GetImageFrameHighlight() const;
    void                SetTrueColorImages(bool val) const;
    bool                GetTrueColorImages() const;
    void                SetXRefFadeIntensity(long val) const;
    long                GetXRefFadeIntensity() const;
    IAcadPreferencesDisplay* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    IAcadPreferencesDisplayPtr m_pimpl;
};
using PyIAcadPreferencesDisplayPtr = std::unique_ptr<PyIAcadPreferencesDisplayImpl>;

//------------------------------------------------------------------------------------
//PyIAcadPreferencesOpenSaveImpl
class PyIAcadPreferencesOpenSaveImpl
{
public:
    explicit PyIAcadPreferencesOpenSaveImpl(IAcadPreferencesOpenSave* ptr);
    virtual ~PyIAcadPreferencesOpenSaveImpl() = default;
    void                SetSavePreviewThumbnail(bool val) const;
    bool                GetSavePreviewThumbnail() const;
    void                SetIncrementalSavePercent(int val) const;
    int                 GetIncrementalSavePercent() const;
    void                SetAutoSaveInterval(int val) const;
    int                 GetAutoSaveInterval() const;
    void                SetCreateBackup(bool val) const;
    bool                GetCreateBackup() const;
    void                SetFullCRCValidation(bool val) const;
    bool                GetFullCRCValidation() const;
    void                SetLogFileOn(bool val) const;
    bool                GetLogFileOn() const;
    void                SetTempFileExtension(const CString& val) const;
    CString             GetTempFileExtension() const;
    void                SetXrefDemandLoad(PyAcXRefDemandLoad val) const;
    PyAcXRefDemandLoad  GetXrefDemandLoad() const;
    void                SetDemandLoadARXApp(PyAcARXDemandLoad val) const;
    PyAcARXDemandLoad   GetDemandLoadARXApp() const;
    void                SetProxyImage(PyAcProxyImage val) const;
    PyAcProxyImage      GetProxyImage() const;
    void                SetShowProxyDialogBox(bool val) const;
    bool                GetShowProxyDialogBox() const;
    void                SetAutoAudit(bool val) const;
    bool                GetAutoAudit() const;
    void                SetSaveAsType(PyAcSaveAsType val) const;
    PyAcSaveAsType      GetSaveAsType() const;
    long                GetMRUNumber() const;
    IAcadPreferencesOpenSave* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    IAcadPreferencesOpenSavePtr m_pimpl;
};
using PyIAcadPreferencesOpenSavePtr = std::unique_ptr<PyIAcadPreferencesOpenSaveImpl>;

//------------------------------------------------------------------------------------
//PyIAcadPreferencesOutputImpl
class PyIAcadPreferencesOutputImpl
{
public:
    explicit PyIAcadPreferencesOutputImpl(IAcadPreferencesOutput* ptr);
    virtual ~PyIAcadPreferencesOutputImpl() = default;
    void                    SetDefaultOutputDevice(const CString& val) const;
    CString                 GetDefaultOutputDevice() const;
    void                    SetPrinterSpoolAlert(PyAcPrinterSpoolAlert val) const;
    PyAcPrinterSpoolAlert   GetPrinterSpoolAlert() const;
    void                    SetPrinterPaperSizeAlert(bool val) const;
    bool                    GetPrinterPaperSizeAlert() const;
    void                    SetPlotLegacy(bool val) const;
    bool                    GetPlotLegacy() const;
    void                    SetOLEQuality(PyAcOleQuality val) const;
    PyAcOleQuality          GetOLEQuality() const;
    void                    SetUseLastPlotSettings(bool val) const;
    bool                    GetUseLastPlotSettings() const;
    void                    SetPlotPolicy(PyAcPlotPolicy val) const;
    PyAcPlotPolicy          GetPlotPolicy() const;
    void                    SetDefaultPlotStyleTable(const CString& val) const;
    CString                 GetDefaultPlotStyleTable() const;
    void                    SetDefaultPlotStyleForObjects(const CString& val) const;
    CString                 GetDefaultPlotStyleForObjects() const;
    void                    SetDefaultPlotStyleForLayer(const CString& val) const;
    CString                 GetDefaultPlotStyleForLayer() const;
    void                    SetContinuousPlotLog(bool val) const;
    bool                    GetContinuousPlotLog() const;
    void                    SetAutomaticPlotLog(bool val) const;
    bool                    GetAutomaticPlotLog() const;
    void                    SetDefaultPlotToFilePath(const CString& val) const;
    CString                 GetDefaultPlotToFilePath() const;
    IAcadPreferencesOutput* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    IAcadPreferencesOutputPtr m_pimpl;
};
using PyIAcadPreferencesOutputPtr = std::unique_ptr<PyIAcadPreferencesOutputImpl>;

//------------------------------------------------------------------------------------
//PyIAcadPreferencesSystemImpl
class PyIAcadPreferencesSystemImpl
{
public:
    explicit PyIAcadPreferencesSystemImpl(IAcadPreferencesSystem* ptr);
    virtual ~PyIAcadPreferencesSystemImpl() = default;
    void    SetSingleDocumentMode(bool val) const;
    bool    GetSingleDocumentMode() const;
    void    SetDisplayOLEScale(bool val) const;
    bool    GetDisplayOLEScale() const;
    void    SetStoreSQLIndex(bool val) const;
    bool    GetStoreSQLIndex() const;
    void    SetTablesReadOnly(bool val) const;
    bool    GetTablesReadOnly() const;
    void    SetEnableStartupDialog(bool val) const;
    bool    GetEnableStartupDialog() const;
    void    SetBeepOnError(bool val) const;
    bool    GetBeepOnError() const;
    void    SetShowWarningMessages(bool val) const;
    bool    GetShowWarningMessages() const;
    void    SetLoadAcadLspInAllDocuments(bool val) const;
    bool    GetLoadAcadLspInAllDocuments() const;
    IAcadPreferencesSystem* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    IAcadPreferencesSystemPtr m_pimpl;
};
using PyIAcadPreferencesSystemPtr = std::unique_ptr<PyIAcadPreferencesSystemImpl>;

//------------------------------------------------------------------------------------
//PyIAcadPreferencesUserImpl
class PyIAcadPreferencesUserImpl
{
public:
    explicit PyIAcadPreferencesUserImpl(IAcadPreferencesUser* ptr);
    virtual ~PyIAcadPreferencesUserImpl() = default;
    void                        SetKeyboardAccelerator(PyAcKeyboardAccelerator val) const;
    PyAcKeyboardAccelerator     GetKeyboardAccelerator() const;
    void                        SetKeyboardPriority(PyAcKeyboardPriority val) const;
    PyAcKeyboardPriority        GetKeyboardPriority() const;
    void                        SetHyperlinkDisplayCursor(bool val) const;
    bool                        GetHyperlinkDisplayCursor() const;
    void                        SetADCInsertUnitsDefaultSource(PyAcInsertUnits val) const;
    PyAcInsertUnits             GetADCInsertUnitsDefaultSource() const;
    void                        SetADCInsertUnitsDefaultTarget(PyAcInsertUnits val) const;
    PyAcInsertUnits             GetADCInsertUnitsDefaultTarget() const;
    void                        SetShortCutMenuDisplay(bool val) const;
    bool                        GetShortCutMenuDisplay() const;
    void                        SetSCMDefaultMode(PyAcDrawingAreaSCMDefault val) const;
    PyAcDrawingAreaSCMDefault   GetSCMDefaultMode() const;
    void                        SetSCMEditMode(PyAcDrawingAreaSCMEdit val) const;
    PyAcDrawingAreaSCMEdit      GetSCMEditMode() const;
    void                        SetSCMCommandMode(PyAcDrawingAreaSCMCommand val) const;
    PyAcDrawingAreaSCMCommand   GetSCMCommandMode() const;
    void                        SetSCMTimeMode(bool val) const;
    bool                        GetSCMTimeMode() const;
    void                        SetSCMTimeValue(int val) const;
    int                         GetSCMTimeValue() const;
    IAcadPreferencesUser* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    IAcadPreferencesUserPtr m_pimpl;
};
using PyIAcadPreferencesUserPtr = std::unique_ptr<PyIAcadPreferencesUserImpl>;

//------------------------------------------------------------------------------------
//PyIAcadPreferencesDraftingImpl
class PyIAcadPreferencesDraftingImpl
{
public:
    explicit PyIAcadPreferencesDraftingImpl(IAcadPreferencesDrafting* ptr);
    virtual ~PyIAcadPreferencesDraftingImpl() = default;
    void        SetAutoSnapMarker(bool val) const;
    bool        GetAutoSnapMarker() const;
    void        SetAutoSnapMagnet(bool val) const;
    bool        GetAutoSnapMagnet() const;
    void        SetAutoSnapTooltip(bool val) const;
    bool        GetAutoSnapTooltip() const;
    void        SetAutoSnapAperture(bool val) const;
    bool        GetAutoSnapAperture() const;
    void        SetAutoSnapApertureSize(long val) const;
    long        GetAutoSnapApertureSize() const;
    void        SetAutoSnapMarkerColor(PyAcColor val) const;
    PyAcColor   GetAutoSnapMarkerColor() const;
    void        SetAutoSnapMarkerSize(long val) const;
    long        GetAutoSnapMarkerSize() const;
    void        SetPolarTrackingVector(bool val) const;
    bool        GetPolarTrackingVector() const;
    void        SetFullScreenTrackingVector(bool val) const;
    bool        GetFullScreenTrackingVector() const;
    void        SetAutoTrackTooltip(bool val) const;
    bool        GetAutoTrackTooltip() const;
    void        SetAlignmentPointAcquisition(PyAcAlignmentPointAcquisition val);
    PyAcAlignmentPointAcquisition GetAlignmentPointAcquisition() const;

    IAcadPreferencesDrafting* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    IAcadPreferencesDraftingPtr m_pimpl;
};
using PyIAcadPreferencesDraftingPtr = std::unique_ptr<PyIAcadPreferencesDraftingImpl>;

//------------------------------------------------------------------------------------
//PyIAcadPreferencesSelectionImpl
class PyIAcadPreferencesSelectionImpl
{
public:
    explicit PyIAcadPreferencesSelectionImpl(IAcadPreferencesSelection* ptr);
    virtual ~PyIAcadPreferencesSelectionImpl() = default;
    void        SetPickFirst(bool val) const;
    bool        GetPickFirst() const;
    void        SetPickAdd(bool val) const;
    bool        GetPickAdd() const;
    void        SetPickDrag(bool val) const;
    bool        GetPickDrag() const;
    void        SetPickAuto(bool val) const;
    bool        GetPickAuto() const;
    void        SetPickBoxSize(long val) const;
    long        GetPickBoxSize() const;
    void        SetDisplayGrips(bool val) const;
    bool        GetDisplayGrips() const;
    void        SetDisplayGripsWithinBlocks(bool val) const;
    bool        GetDisplayGripsWithinBlocks() const;
    void        SetGripColorSelected(PyAcColor val) const;
    PyAcColor   GetGripColorSelected() const;
    void        SetGripColorUnselected(PyAcColor val) const;
    PyAcColor   GetGripColorUnselected() const;
    void        SetGripSize(long val) const;
    long        GetGripSize() const;
    void        SetPickGroup(bool val) const;
    bool        GetPickGroup() const;
    IAcadPreferencesSelection* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    IAcadPreferencesSelectionPtr m_pimpl;
};
using PyIAcadPreferencesSelectionPtr = std::unique_ptr<PyIAcadPreferencesSelectionImpl>;

//------------------------------------------------------------------------------------
//PyIAcadPreferencesProfilesImpl
class PyIAcadPreferencesProfilesImpl
{
public:
    explicit PyIAcadPreferencesProfilesImpl(IAcadPreferencesProfiles* ptr);
    virtual ~PyIAcadPreferencesProfilesImpl() = default;
    CString         GetActiveProfile() const;
    void            SetActiveProfile(const CString& str) const;
    void            ImportProfile(const CString& ProfileName, const CString& RegFile, bool IncludePathInfo) const;
    void            ExportProfile(const CString& ProfileName, const CString& RegFile) const;
    void            DeleteProfile(const CString& ProfileName) const;
    void            ResetProfile(const CString& Profile) const;
    void            RenameProfile(const CString& origProfileName, const CString& newProfileName) const;
    void            CopyProfile(const CString& oldProfileName, const CString& newProfileName) const;
    wstringArray    GetAllProfileNames() const;
    IAcadPreferencesProfiles* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    IAcadPreferencesProfilesPtr m_pimpl;
};
using PyIAcadPreferencesProfilesPtr = std::unique_ptr<PyIAcadPreferencesProfilesImpl>;


//------------------------------------------------------------------------------------
//PyIAcadPreferencesImpl
class PyIAcadPreferencesImpl
{
public:
    explicit PyIAcadPreferencesImpl(IAcadPreferences* ptr);
    virtual ~PyIAcadPreferencesImpl() = default;
    PyIAcadPreferencesFilesPtr      GetFiles() const;
    PyIAcadPreferencesDisplayPtr    GetDisplay() const;
    PyIAcadPreferencesOpenSavePtr   GetOpenSave() const;
    PyIAcadPreferencesOutputPtr     GetOutput() const;
    PyIAcadPreferencesSystemPtr     GetSystem() const;
    PyIAcadPreferencesUserPtr       GetUser() const;
    PyIAcadPreferencesDraftingPtr   GetDrafting() const;
    PyIAcadPreferencesSelectionPtr  GetSelection() const;
    PyIAcadPreferencesProfilesPtr   GetProfiles() const;
    IAcadPreferences* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    IAcadPreferencesPtr m_pimpl;
};
using PyIAcadPreferencesPtr = std::unique_ptr<PyIAcadPreferencesImpl>;

//------------------------------------------------------------------------------------
//PyIAcadSummaryInfoImpl
class PyIAcadSummaryInfoImpl
{
public:
    explicit PyIAcadSummaryInfoImpl(IAcadSummaryInfo* ptr);
    virtual ~PyIAcadSummaryInfoImpl() = default;

    CString         GetAuthor() const;
    void            SetAuthor(const CString& str) const;
    CString         GetComments() const;
    void            SetComments(const CString& str) const;
    CString         GetHyperlinkBase() const;
    void            SetHyperlinkBase(const CString& str) const;
    CString         GetKeywords() const;
    void            SetKeywords(const CString& str) const;
    CString         GetLastSavedBy() const;
    void            SetLastSavedBy(const CString& str) const;
    CString         GetRevisionNumber() const;
    void            SetRevisionNumber(const CString& str) const;
    CString         GetSubject() const;
    void            SetSubject(const CString& str) const;
    CString         GetTitle() const;
    void            SetTitle(const CString& str) const;
    int             NumCustomInfo() const;
    CStringPair     GetCustomByIndex(int ind) const;
    void            SetCustomByIndex(int ind, const CString& key, const CString& val) const;
    CString         GetCustomByKey(const CString& str) const;
    void            SetCustomByKey(const CString& key, const CString& val) const;
    void            AddCustomInfo(const CString& key, const CString& val) const;
    void            RemoveCustomByIndex(int ind) const;
    void            RemoveCustomByKey(const CString& str) const;

    IAcadSummaryInfo* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    IAcadSummaryInfoPtr m_pimpl;
};
using PyIAcadSummaryInfoPtr = std::unique_ptr<PyIAcadSummaryInfoImpl>;
//------------------------------------------------------------------------------------
//PyIAcadDynamicBlockReferencePropertyImpl
class PyIAcadDynamicBlockReferencePropertyImpl
{
public:
    explicit PyIAcadDynamicBlockReferencePropertyImpl(IAcadDynamicBlockReferenceProperty* ptr);
    virtual ~PyIAcadDynamicBlockReferencePropertyImpl() = default;
    CString                 GetPropertyName() const;
    bool                    GetReadOnly() const;
    bool                    GetShow() const;
    CString                 GetDescription() const;
    AcDbEvalVariantArray    GetAllowedValues() const;
    AcDbEvalVariant         GetValue() const;
    void                    SetValue(const AcDbEvalVariant& variant) const;
    PyAcDynamicBlockReferencePropertyUnitsType GetUnitsType() const;
    IAcadDynamicBlockReferenceProperty* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    IAcadDynamicBlockReferencePropertyPtr m_pimpl;
};

//------------------------------------------------------------------------------------
//PyIAcadIdPairImpl
class PyIAcadIdPairImpl
{
public:
    explicit PyIAcadIdPairImpl(IAcadIdPair* ptr);
    virtual ~PyIAcadIdPairImpl() = default;

    bool            GetIsCloned() const;
    bool            GetIsOwnerXlated() const;
    bool            GetIsPrimary() const;
    AcDbObjectId    GetKey() const;
    AcDbObjectId    GetValue() const;

    IAcadIdPair* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    IAcadIdPairPtr m_pimpl;
};

//------------------------------------------------------------------------------------
//PyIAcadShadowDisplayImpl
#ifndef _BRXTARGET
class PyIAcadShadowDisplayImpl
{
public:
    explicit PyIAcadShadowDisplayImpl(IAcadShadowDisplay* ptr);
    virtual ~PyIAcadShadowDisplayImpl() = default;
    PyAcShadowDisplayType       GetShadowDisplay() const;
    void                        PutShadowDisplay(PyAcShadowDisplayType val) const;
    bool                        GetEnableShadowDisplay() const;
    IAcadShadowDisplay* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    IAcadShadowDisplayPtr m_pimpl;
};
#endif

//------------------------------------------------------------------------------------
//PyIAcadPlotImpl
class PyIAcadPlotImpl
{
public:
    explicit PyIAcadPlotImpl(IAcadPlot* ptr);
    virtual ~PyIAcadPlotImpl() = default;
    bool       GetQuietErrorMode() const;
    void       SetQuietErrorMode(bool val) const;
    long       GetNumberOfCopies() const;
    void       SetNumberOfCopies(long val) const;
    bool       GetBatchPlotProgress() const;
    void       SetBatchPlotProgress(bool val) const;
    void       SetDisplayPlotPreview(PyAcPreviewMode mode) const;
    void       SetLayoutsToPlot(const wstringArray& layouts) const;
    void       StartBatchMode(long val) const;
    IAcadPlot* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    IAcadPlotPtr m_pimpl;
};
using PyIAcadPlotPtr = std::unique_ptr<PyIAcadPlotImpl>;

//------------------------------------------------------------------------------------
//PyIAcadMenuBarImpl
class PyIAcadMenuBarImpl
{
public:
    explicit PyIAcadMenuBarImpl(IAcadMenuBar* ptr);
    virtual ~PyIAcadMenuBarImpl() = default;
    long                GetCount() const;
    PyIAcadPopupMenuPtr GetItem(long index) const;
    IAcadMenuBar* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    IAcadMenuBarPtr m_pimpl;
};
using PyIAcadMenuBarPtr = std::unique_ptr<PyIAcadMenuBarImpl>;

//------------------------------------------------------------------------------------
//PyIAcadMenuGroupImpl
class PyIAcadMenuGroupImpl
{
public:
    explicit PyIAcadMenuGroupImpl(IAcadMenuGroup* ptr);
    virtual ~PyIAcadMenuGroupImpl() = default;
    PyIAcadMenuGroupsPtr    GetParent() const;
    CString                 GetName() const;
    PyAcMenuGroupType       GetType() const;
    CString                 GetMenuFileName() const;
    PyIAcadPopupMenusPtr    GetMenus() const;
    PyIAcadToolbarsPtr      GetToolbars() const;
    void                    Save(PyAcMenuFileType menuType) const;
    void                    SaveAs(const CString& menuFileName, PyAcMenuFileType menuType) const;
    void                    Unload() const;
    IAcadMenuGroup* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    IAcadMenuGroupPtr m_pimpl;
};
using PyIAcadMenuGroupPtr = std::unique_ptr<PyIAcadMenuGroupImpl>;

//------------------------------------------------------------------------------------
//PyIAcadMenuGroupsImpl
class PyIAcadMenuGroupsImpl
{
public:
    explicit PyIAcadMenuGroupsImpl(IAcadMenuGroups* ptr);
    virtual ~PyIAcadMenuGroupsImpl() = default;
    long                GetCount() const;
    PyIAcadMenuGroupPtr GetItem(long index) const;
    PyIAcadMenuGroupPtr Load(const CString& menuFileName) const;
    PyIAcadMenuGroupPtr Load(const CString& menuFileName, const PyIAcadMenuGroupImpl& BaseMenu) const;
    IAcadMenuGroups* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    IAcadMenuGroupsPtr m_pimpl;
};

//------------------------------------------------------------------------------------
//PyIAcadPopupMenuItemImpl
class PyIAcadPopupMenuItemImpl
{
public:
    explicit PyIAcadPopupMenuItemImpl(IAcadPopupMenuItem* ptr);
    virtual ~PyIAcadPopupMenuItemImpl() = default;
    PyIAcadPopupMenuPtr GetParent() const;
    CString             GetLabel() const;
    void                SetLabel(const CString& val) const;
    CString             GetTagString() const;
    void                SetTagString(const CString& val) const;
    bool                GetEnable() const;
    void                SetEnable(bool val) const;
    bool                GetCheck() const;
    void                SetCheck(bool val) const;
    PyAcMenuItemType    GetType() const;
    PyIAcadPopupMenuPtr GetSubMenu() const;
    CString             GetMacro() const;
    void                SetMacro(const CString& val) const;
    int                 GetIndex() const;
    CString             GetCaption() const;
    CString             GetHelpString() const;
    void                SetHelpString(const CString& val) const;
    void                Delete() const;
    int                 GetEndSubMenuLevel() const;
    void                SetEndSubMenuLevel(int idx) const;

    IAcadPopupMenuItem* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    IAcadPopupMenuItemPtr m_pimpl;
};
using PyIAcadPopupMenuItemPtr = std::unique_ptr<PyIAcadPopupMenuItemImpl>;

//------------------------------------------------------------------------------------
//PyIAcadPopupMenuImpl
class PyIAcadPopupMenuImpl
{
public:
    explicit PyIAcadPopupMenuImpl(IAcadPopupMenu* ptr);
    virtual ~PyIAcadPopupMenuImpl() = default;
    long                    GetCount() const;
    PyIAcadPopupMenuItemPtr GetItem(long index) const;
    PyIAcadPopupMenusPtr    GetParent() const;
    CString                 GetName() const;
    void                    SetName(const CString& val) const;
    CString                 GetNameNoMnemonic() const;
    bool                    GetShortcutMenu() const;
    bool                    GetOnMenuBar() const;
    PyIAcadPopupMenuItemPtr AddMenuItem(long index, const CString& label, const CString& macro) const;
    PyIAcadPopupMenuPtr     AddSubMenu(long index, const CString& label) const;
    PyIAcadPopupMenuItemPtr AddSeparator(long index) const;
    void                    InsertInMenuBar(long index) const;
    void                    RemoveFromMenuBar() const;
    CString                 GetTagString() const;
    IAcadPopupMenu* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    IAcadPopupMenuPtr m_pimpl;
};

//------------------------------------------------------------------------------------
//PyIAcadPopupMenusImpl
class PyIAcadPopupMenusImpl
{
public:
    explicit PyIAcadPopupMenusImpl(IAcadPopupMenus* ptr);
    virtual ~PyIAcadPopupMenusImpl() = default;
    long                    GetCount() const;
    PyIAcadPopupMenuPtr     GetItem(long index) const;
    PyIAcadMenuGroupPtr     GetParent() const;
    PyIAcadPopupMenuPtr     Add(const CString& toolbarName) const;
    void                    InsertMenuInMenuBar(const CString& menuName, long index) const;
    void                    RemoveMenuFromMenuBar(long index) const;
    IAcadPopupMenus* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    IAcadPopupMenusPtr m_pimpl;
};

//------------------------------------------------------------------------------------
//PyIAcadToolbarItemImpl
class PyIAcadToolbarItemImpl
{
public:
    explicit PyIAcadToolbarItemImpl(IAcadToolbarItem* ptr);
    virtual ~PyIAcadToolbarItemImpl() = default;
    PyIAcadToolbarPtr       GetParent() const;
    CString                 GetName() const;
    void                    SetName(const CString& val) const;
    CString                 GetTagString() const;
    void                    SetTagString(const CString& val) const;
    PyAcToolbarItemType     GetType() const;
    CString                 GetMacro() const;
    void                    SetMacro(const CString& val) const;
    int                     GetIndex() const;
    CString                 GetHelpString() const;
    void                    SetHelpString(const CString& val) const;
    CStringPair             GetBitmaps() const;
    void                    SetBitmaps(const CString& smallIconName, const CString& largeIconName) const;
    void                    AttachToolbarToFlyout(const CString& menuGroupName, const CString& toolbarName) const;
    void                    Delete() const;
    CString                 GetCommandDisplayName() const;
    void                    SetCommandDisplayName(const CString& val) const;
    IAcadToolbarItem* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    IAcadToolbarItemPtr m_pimpl;
};
using PyIAcadToolbarItemPtr = std::unique_ptr<PyIAcadToolbarItemImpl>;

//------------------------------------------------------------------------------------
//PyIAcadToolbarImpl
class PyIAcadToolbarImpl
{
public:
    explicit PyIAcadToolbarImpl(IAcadToolbar* ptr);
    virtual ~PyIAcadToolbarImpl() = default;
    long                    GetCount() const;
    PyIAcadToolbarItemPtr   GetItem(long index) const;
    PyIAcadToolbarsPtr      GetParent() const;
    CString                 GetName() const;
    void                    SetName(const CString& name) const;
    bool                    GetVisible() const;
    void                    SetVisible(bool val) const;
    PyAcToolbarDockStatus   GetDockStatus() const;
    bool                    GetLargeButtons() const;
    int                     GetLeft() const;
    void                    SetLeft(int val) const;
    int                     GetTop() const;
    void                    SetTop(int val) const;
    int                     GetWidth() const;
    int                     GetHeight() const;
    int                     GetFloatingRows() const;
    void                    SetFloatingRows(int val) const;
    CString                 GetHelpString() const;
    void                    SetHelpString(const CString& val) const;
    PyIAcadToolbarItemPtr   AddToolbarButton(int index, const CString& name, const CString& helpstr, const CString& macro, bool flyoutButton) const;
    void                    Dock(PyAcToolbarDockStatus val) const;
    void                    Float(int top, int teft, int numberFloatRows) const;
    void                    Delete() const;
    CString                 GetTagString() const;
    IAcadToolbar* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    IAcadToolbarPtr m_pimpl;
};

//------------------------------------------------------------------------------------
//PyIAcadToolbarsImpl
class PyIAcadToolbarsImpl
{
public:
    explicit PyIAcadToolbarsImpl(IAcadToolbars* ptr);
    virtual ~PyIAcadToolbarsImpl() = default;
    long                GetCount() const;
    PyIAcadToolbarPtr   GetItem(long index) const;
    PyIAcadMenuGroupPtr GetParent() const;
    bool                GetLargeButtons() const;
    void                SetLargeButtons(bool val) const;
    PyIAcadToolbarPtr   Add(const CString& toolbarName) const;
    IAcadToolbars* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    IAcadToolbarsPtr m_pimpl;
};

#pragma pack (pop)
