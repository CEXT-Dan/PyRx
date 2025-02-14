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
    void            SetEntityColor(long val);
    long            GetEntityColor() const;
    CString         GetColorName() const;
    CString         GetBookName() const;
    void            SetNames(const CString& colorName, const CString& bookName);
    void            Delete();
    long            GetRed() const;
    long            GetGreen() const;
    long            GetBlue() const;
    void            SetRGB(long Red, long Green, long Blue);
    PyAcColorMethod GetColorMethod() const;
    void            SetColorMethod(PyAcColorMethod flags);
    PyAcColor       GetColorIndex() const;
    void            SetColorIndex(PyAcColor val);
    void            SetColorBookColor(const CString& colorName, const CString& bookName);
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
    void            SetURL(const CString& val);
    CString         GetURLDescription() const;
    void            SetURLDescription(const CString& val);
    void            Delete();
    CString         GetURLNamedLocation() const;
    void            SetURLNamedLocation(const CString& val);
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
    PyIAcadHyperlinkPtr    GetItem(long val);
    long                   GetCount() const;
    PyIAcadHyperlinkPtr    Add(const CString& name, const CString& description, const CString& namedLocation);
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
    void                    SetGenerationOptions(PyAcSectionGeneration val);
    AcDbObjectIdArray       GetSourceObjects() const;
    void                    SetSourceObjects(const AcDbObjectIdArray& ids);
    PyIAcadBlockPtr         GetDestinationBlock();
    void                    SetDestinationBlock(const PyIAcadBlockImpl& val);
    CString                 GetDestinationFile() const;
    void                    SetDestinationFile(const CString& val);
    PyIAcadAcCmColorPtr     GetIntersectionBoundaryColor() const;
    void                    SetIntersectionBoundaryColor(const PyIAcadAcCmColorImpl& val) const;
    CString                 GetIntersectionBoundaryLayer() const;
    void                    SetIntersectionBoundaryLayer(const CString& val);
    CString                 GetIntersectionBoundaryLinetype() const;
    void                    SetIntersectionBoundaryLinetype(const CString& val);
    double                  GetIntersectionBoundaryLinetypeScale() const;
    void                    SetIntersectionBoundaryLinetypeScale(double val);
    CString                 GetIntersectionBoundaryPlotStyleName() const;
    void                    SetIntersectionBoundaryPlotStyleName(const CString& val);
    PyAcLineWeight          GetIntersectionBoundaryLineweight() const;
    void                    SetIntersectionBoundaryLineweight(PyAcLineWeight val);
    bool                    GetIntersectionBoundaryDivisionLines() const;
    void                    SetIntersectionBoundaryDivisionLines(bool val) const;
    bool                    GetIntersectionFillVisible() const;
    void                    SetIntersectionFillVisible(bool val) const;
    PyAcPatternType         GetIntersectionFillHatchPatternType() const;
    void                    SetIntersectionFillHatchPatternType(PyAcPatternType val);
    CString                 GetIntersectionFillHatchPatternName() const;
    void                    SetIntersectionFillHatchPatternName(const CString& val);
    double                  GetIntersectionFillHatchAngle() const;
    void                    SetIntersectionFillHatchAngle(double val);
    double                  GetIntersectionFillHatchScale() const;
    void                    SetIntersectionFillHatchScale(double val);
    double                  GetIntersectionFillHatchSpacing() const;
    void                    SetIntersectionFillHatchSpacing(double val);
    PyIAcadAcCmColorPtr     GetIntersectionFillColor() const;
    void                    SetIntersectionFillColor(const PyIAcadAcCmColorImpl& val) const;
    CString                 GetIntersectionFillLayer() const;
    void                    SetIntersectionFillLayer(const CString& val);
    CString                 GetIntersectionFillLinetype() const;
    void                    SetIntersectionFillLinetype(const CString& val);
    double                  GetIntersectionFillLinetypeScale() const;
    void                    SetIntersectionFillLinetypeScale(double val);
    void                    SetIntersectionFillPlotStyleName(const CString& val);
    CString                 GetIntersectionFillPlotStyleName() const;
    PyAcLineWeight          GetIntersectionFillLineweight() const;
    void                    SetIntersectionFillLineweight(PyAcLineWeight val);
    long                    GetIntersectionFillFaceTransparency() const;
    void                    SetIntersectionFillFaceTransparency(long val);
    bool                    GetBackgroundLinesVisible() const;
    void                    SetBackgroundLinesVisible(bool val) const;
    bool                    GetBackgroundLinesHiddenLine() const;
    void                    SetBackgroundLinesHiddenLine(bool val) const;
    PyIAcadAcCmColorPtr     GetBackgroundLinesColor() const;
    void                    SetBackgroundLinesColor(const PyIAcadAcCmColorImpl& val) const;
    CString                 GetBackgroundLinesLayer() const;
    void                    SetBackgroundLinesLayer(const CString& val);
    CString                 GetBackgroundLinesLinetype() const;
    void                    SetBackgroundLinesLinetype(const CString& val);
    double                  GetBackgroundLinesLinetypeScale() const;
    void                    SetBackgroundLinesLinetypeScale(double val);
    CString                 GetBackgroundLinesPlotStyleName() const;
    void                    SetBackgroundLinesPlotStyleName(const CString& val);
    PyAcLineWeight          GetBackgroundLinesLineweight() const;
    void                    SetBackgroundLinesLineweight(PyAcLineWeight val);
    bool                    GetForegroundLinesVisible() const;
    void                    SetForegroundLinesVisible(bool val) const;
    bool                    GetForegroundLinesHiddenLine() const;
    void                    SetForegroundLinesHiddenLine(bool val) const;
    PyIAcadAcCmColorPtr     GetForegroundLinesColor() const;
    void                    SetForegroundLinesColor(const PyIAcadAcCmColorImpl& val) const;
    CString                 GetForegroundLinesLayer() const;
    void                    SetForegroundLinesLayer(const CString& val);
    CString                 GetForegroundLinesLinetype() const;
    void                    SetForegroundLinesLinetype(const CString& val);
    double                  GetForegroundLinesLinetypeScale() const;
    void                    SetForegroundLinesLinetypeScale(double val);
    CString                 GetForegroundLinesPlotStyleName() const;
    void                    SetForegroundLinesPlotStyleName(const CString& val);
    PyAcLineWeight          GetForegroundLinesLineweight() const;
    void                    SetForegroundLinesLineweight(PyAcLineWeight val);
    long                    GetForegroundLinesFaceTransparency() const;
    void                    SetForegroundLinesFaceTransparency(long val);
    long                    GetForegroundLinesEdgeTransparency() const;
    void                    SetForegroundLinesEdgeTransparency(long val);
    bool                    GetCurveTangencyLinesVisible() const;
    void                    SetCurveTangencyLinesVisible(bool val) const;
    PyIAcadAcCmColorPtr     GetCurveTangencyLinesColor() const;
    void                    SetCurveTangencyLinesColor(const PyIAcadAcCmColorImpl& val) const;
    CString                 GetCurveTangencyLinesLayer() const;
    void                    SetCurveTangencyLinesLayer(const CString& val);
    CString                 GetCurveTangencyLinesLinetype() const;
    void                    SetCurveTangencyLinesLinetype(const CString& val);
    double                  GetCurveTangencyLinesLinetypeScale() const;
    void                    SetCurveTangencyLinesLinetypeScale(double val);
    CString                 GetCurveTangencyLinesPlotStyleName() const;
    void                    SetCurveTangencyLinesPlotStyleName(const CString& val);
    PyAcLineWeight          GetCurveTangencyLinesLineweight() const;
    void                    SetCurveTangencyLinesLineweight(PyAcLineWeight val);
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
    void        SetSupportPath(const CString& val);
    CString     GetSupportPath() const;
    void        SetDriversPath(const CString& val);
    CString     GetDriversPath() const;
    void        SetMenuFile(const CString& val);
    CString     GetMenuFile() const;
    void        SetEnterpriseMenuFile(const CString& val);
    CString     GetEnterpriseMenuFile() const;
    void        SetCustomIconPath(const CString& val);
    CString     GetCustomIconPath() const;
    void        SetHelpFilePath(const CString& val);
    CString     GetHelpFilePath() const;
    void        SetDefaultInternetURL(const CString& val);
    CString     GetDefaultInternetURL() const;
    CString     GetConfigFile() const;
    CString     GetLicenseServer() const;
    void        SetTextEditor(const CString& val);
    CString     GetTextEditor() const;
    void        SetMainDictionary(const CString& val);
    CString     GetMainDictionary() const;
    void        SetCustomDictionary(const CString& val);
    CString     GetCustomDictionary() const;
    void        SetAltFontFile(const CString& val);
    CString     GetAltFontFile() const;
    void        SetFontFileMap(const CString& val);
    CString     GetFontFileMap() const;
    void        SetPrintFile(const CString& val);
    CString     GetPrintFile() const;
    void        SetPrintSpoolExecutable(const CString& val);
    CString     GetPrintSpoolExecutable() const;
    void        SetPostScriptPrologFile(const CString& val);
    CString     GetPostScriptPrologFile() const;
    void        SetPrintSpoolerPath(const CString& val);
    CString     GetPrintSpoolerPath() const;
    void        SetAutoSavePath(const CString& val);
    CString     GetAutoSavePath() const;
    void        SetTemplateDwgPath(const CString& val);
    CString     GetTemplateDwgPath() const;
    void        SetLogFilePath(const CString& val);
    CString     GetLogFilePath() const;
    void        SetTempFilePath(const CString& val);
    CString     GetTempFilePath() const;
    void        SetTempXrefPath(const CString& val);
    CString     GetTempXrefPath() const;
    void        SetTextureMapPath(const CString& val);
    CString     GetTextureMapPath() const;
    void        SetAltTabletMenuFile(const CString& val);
    CString     GetAltTabletMenuFile() const;
    void        SetProjectFilePath(const CString& projectName, const CString& projectFilePath);
    CString     GetProjectFilePath(const CString& projectName) const;
    void        SetPrinterConfigPath(const CString& val);
    CString     GetPrinterConfigPath() const;
    void        SetPrinterDescPath(const CString& val);
    CString     GetPrinterDescPath() const;
    void        SetPrinterStyleSheetPath(const CString& val);
    CString     GetPrinterStyleSheetPath() const;
    void        SetWorkspacePath(const CString& val);
    CString     GetWorkspacePath() const;
    void        SetObjectARXPath(const CString& val);
    CString     GetObjectARXPath() const;
    void        SetColorBookPath(const CString& val);
    CString     GetColorBookPath() const;
    void        SetToolPalettePath(const CString& val);
    CString     GetToolPalettePath() const;
    void        SetQNewTemplateFile(const CString& val);
    CString     GetQNewTemplateFile() const;
    void        SetPlotLogFilePath(const CString& val);
    CString     GetPlotLogFilePath() const;
    void        SetPageSetupOverridesTemplateFile(const CString& val);
    CString     GetPageSetupOverridesTemplateFile() const;
    void        SetActiveInvProject(const CString& val);
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
    void                SetLayoutDisplayMargins(bool val);
    bool                GetLayoutDisplayMargins() const;
    void                SetLayoutDisplayPaper(bool val);
    bool                GetLayoutDisplayPaper() const;
    void                SetLayoutDisplayPaperShadow(bool val);
    bool                GetLayoutDisplayPaperShadow() const;
    void                SetLayoutShowPlotSetup(bool val);
    bool                GetLayoutShowPlotSetup() const;
    void                SetLayoutCreateViewport(bool val);
    bool                GetLayoutCreateViewport() const;
    void                SetDisplayScrollBars(bool val);
    bool                GetDisplayScrollBars() const;
    void                SetDisplayScreenMenu(bool val);
    bool                GetDisplayScreenMenu() const;
    void                SetCursorSize(int val);
    int                 GetCursorSize() const;
    void                SetDockedVisibleLines(int val);
    int                 GetDockedVisibleLines() const;
    void                SetShowRasterImage(bool val);
    bool                GetShowRasterImage() const;
    void                SetGraphicsWinModelBackgrndColor(COLORREF val);
    COLORREF            GetGraphicsWinModelBackgrndColor() const;
    void                SetModelCrosshairColor(COLORREF val);
    COLORREF            GetModelCrosshairColor() const;
    void                SetGraphicsWinLayoutBackgrndColor(COLORREF val);
    COLORREF            GetGraphicsWinLayoutBackgrndColor() const;
    void                SetTextWinBackgrndColor(COLORREF val);
    COLORREF            GetTextWinBackgrndColor() const;
    void                SetTextWinTextColor(COLORREF val);
    COLORREF            GetTextWinTextColor() const;
    void                SetLayoutCrosshairColor(COLORREF val);
    COLORREF            GetLayoutCrosshairColor() const;
    void                SetAutoTrackingVecColor(COLORREF val);
    COLORREF            GetAutoTrackingVecColor() const;
    void                SetTextFont(const CString& val);
    CString             GetTextFont() const;
    void                SetTextFontStyle(const PyAcTextFontStyle& val);
    PyAcTextFontStyle   GetTextFontStyle() const;
    void                SetTextFontSize(int val);
    int                 GetTextFontSize() const;
    void                SetHistoryLines(int val);
    int                 GetHistoryLines() const;
    void                SetMaxAutoCADWindow(bool val);
    bool                GetMaxAutoCADWindow() const;
    void                SetDisplayLayoutTabs(bool val);
    bool                GetDisplayLayoutTabs() const;
    void                SetImageFrameHighlight(bool val);
    bool                GetImageFrameHighlight() const;
    void                SetTrueColorImages(bool val);
    bool                GetTrueColorImages() const;
    void                SetXRefFadeIntensity(long val);
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
    void                SetSavePreviewThumbnail(bool val);
    bool                GetSavePreviewThumbnail() const;
    void                SetIncrementalSavePercent(int val);
    int                 GetIncrementalSavePercent() const;
    void                SetAutoSaveInterval(int val);
    int                 GetAutoSaveInterval() const;
    void                SetCreateBackup(bool val);
    bool                GetCreateBackup() const;
    void                SetFullCRCValidation(bool val);
    bool                GetFullCRCValidation() const;
    void                SetLogFileOn(bool val);
    bool                GetLogFileOn() const;
    void                SetTempFileExtension(const CString& val);
    CString             GetTempFileExtension() const;
    void                SetXrefDemandLoad(PyAcXRefDemandLoad val);
    PyAcXRefDemandLoad  GetXrefDemandLoad() const;
    void                SetDemandLoadARXApp(PyAcARXDemandLoad val);
    PyAcARXDemandLoad   GetDemandLoadARXApp() const;
    void                SetProxyImage(PyAcProxyImage val);
    PyAcProxyImage      GetProxyImage() const;
    void                SetShowProxyDialogBox(bool val);
    bool                GetShowProxyDialogBox() const;
    void                SetAutoAudit(bool val);
    bool                GetAutoAudit() const;
    void                SetSaveAsType(PyAcSaveAsType val);
    PyAcSaveAsType      GetSaveAsType() const;
    long                GetMRUNumber();
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
    void                    SetDefaultOutputDevice(const CString& val);
    CString                 GetDefaultOutputDevice() const;
    void                    SetPrinterSpoolAlert(PyAcPrinterSpoolAlert val);
    PyAcPrinterSpoolAlert   GetPrinterSpoolAlert() const;
    void                    SetPrinterPaperSizeAlert(bool val);
    bool                    GetPrinterPaperSizeAlert() const;
    void                    SetPlotLegacy(bool val);
    bool                    GetPlotLegacy() const;
    void                    SetOLEQuality(PyAcOleQuality val);
    PyAcOleQuality          GetOLEQuality() const;
    void                    SetUseLastPlotSettings(bool val);
    bool                    GetUseLastPlotSettings() const;
    void                    SetPlotPolicy(PyAcPlotPolicy val);
    PyAcPlotPolicy          GetPlotPolicy() const;
    void                    SetDefaultPlotStyleTable(const CString& val);
    CString                 GetDefaultPlotStyleTable() const;
    void                    SetDefaultPlotStyleForObjects(const CString& val);
    CString                 GetDefaultPlotStyleForObjects() const;
    void                    SetDefaultPlotStyleForLayer(const CString& val);
    CString                 GetDefaultPlotStyleForLayer() const;
    void                    SetContinuousPlotLog(bool val);
    bool                    GetContinuousPlotLog() const;
    void                    SetAutomaticPlotLog(bool val);
    bool                    GetAutomaticPlotLog() const;
    void                    SetDefaultPlotToFilePath(const CString& val);
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
    void    SetSingleDocumentMode(bool val);
    bool    GetSingleDocumentMode() const;
    void    SetDisplayOLEScale(bool val);
    bool    GetDisplayOLEScale() const;
    void    SetStoreSQLIndex(bool val);
    bool    GetStoreSQLIndex() const;
    void    SetTablesReadOnly(bool val);
    bool    GetTablesReadOnly() const;
    void    SetEnableStartupDialog(bool val);
    bool    GetEnableStartupDialog() const;
    void    SetBeepOnError(bool val);
    bool    GetBeepOnError() const;
    void    SetShowWarningMessages(bool val);
    bool    GetShowWarningMessages() const;
    void    SetLoadAcadLspInAllDocuments(bool val);
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
    void                        SetKeyboardAccelerator(PyAcKeyboardAccelerator val);
    PyAcKeyboardAccelerator     GetKeyboardAccelerator() const;
    void                        SetKeyboardPriority(PyAcKeyboardPriority val);
    PyAcKeyboardPriority        GetKeyboardPriority() const;
    void                        SetHyperlinkDisplayCursor(bool val);
    bool                        GetHyperlinkDisplayCursor() const;
    void                        SetADCInsertUnitsDefaultSource(PyAcInsertUnits val);
    PyAcInsertUnits             GetADCInsertUnitsDefaultSource() const;
    void                        SetADCInsertUnitsDefaultTarget(PyAcInsertUnits val);
    PyAcInsertUnits             GetADCInsertUnitsDefaultTarget() const;
    void                        SetShortCutMenuDisplay(bool val);
    bool                        GetShortCutMenuDisplay() const;
    void                        SetSCMDefaultMode(PyAcDrawingAreaSCMDefault val);
    PyAcDrawingAreaSCMDefault   GetSCMDefaultMode() const;
    void                        SetSCMEditMode(PyAcDrawingAreaSCMEdit val);
    PyAcDrawingAreaSCMEdit      GetSCMEditMode() const;
    void                        SetSCMCommandMode(PyAcDrawingAreaSCMCommand val);
    PyAcDrawingAreaSCMCommand   GetSCMCommandMode() const;
    void                        SetSCMTimeMode(bool val);
    bool                        GetSCMTimeMode() const;
    void                        SetSCMTimeValue(int val);
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
    void        SetAutoSnapMarker(bool val);
    bool        GetAutoSnapMarker() const;
    void        SetAutoSnapMagnet(bool val);
    bool        GetAutoSnapMagnet() const;
    void        SetAutoSnapTooltip(bool val);
    bool        GetAutoSnapTooltip() const;
    void        SetAutoSnapAperture(bool val);
    bool        GetAutoSnapAperture() const;
    void        SetAutoSnapApertureSize(long val);
    long        GetAutoSnapApertureSize() const;
    void        SetAutoSnapMarkerColor(PyAcColor val);
    PyAcColor   GetAutoSnapMarkerColor() const;
    void        SetAutoSnapMarkerSize(long val);
    long        GetAutoSnapMarkerSize() const;
    void        SetPolarTrackingVector(bool val);
    bool        GetPolarTrackingVector() const;
    void        SetFullScreenTrackingVector(bool val);
    bool        GetFullScreenTrackingVector() const;
    void        SetAutoTrackTooltip(bool val);
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
    void        SetPickFirst(bool val);
    bool        GetPickFirst() const;
    void        SetPickAdd(bool val);
    bool        GetPickAdd() const;
    void        SetPickDrag(bool val);
    bool        GetPickDrag() const;
    void        SetPickAuto(bool val);
    bool        GetPickAuto() const;
    void        SetPickBoxSize(long val);
    long        GetPickBoxSize() const;
    void        SetDisplayGrips(bool val);
    bool        GetDisplayGrips() const;
    void        SetDisplayGripsWithinBlocks(bool val);
    bool        GetDisplayGripsWithinBlocks() const;
    void        SetGripColorSelected(PyAcColor val);
    PyAcColor   GetGripColorSelected() const;
    void        SetGripColorUnselected(PyAcColor val);
    PyAcColor   GetGripColorUnselected() const;
    void        SetGripSize(long val);
    long        GetGripSize() const;
    void        SetPickGroup(bool val);
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
    void            SetActiveProfile(const CString& str);
    void            ImportProfile(const CString& ProfileName, const CString& RegFile, bool IncludePathInfo);
    void            ExportProfile(const CString& ProfileName, const CString& RegFile);
    void            DeleteProfile(const CString& ProfileName);
    void            ResetProfile(const CString& Profile);
    void            RenameProfile(const CString& origProfileName, const CString& newProfileName);
    void            CopyProfile(const CString& oldProfileName, const CString& newProfileName);
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
    void            SetAuthor(const CString& str);
    CString         GetComments() const;
    void            SetComments(const CString& str);
    CString         GetHyperlinkBase() const;
    void            SetHyperlinkBase(const CString& str);
    CString         GetKeywords() const;
    void            SetKeywords(const CString& str);
    CString         GetLastSavedBy() const;
    void            SetLastSavedBy(const CString& str);
    CString         GetRevisionNumber() const;
    void            SetRevisionNumber(const CString& str);
    CString         GetSubject() const;
    void            SetSubject(const CString& str);
    CString         GetTitle() const;
    void            SetTitle(const CString& str);
    int             NumCustomInfo() const;
    CStringPair     GetCustomByIndex(int ind);
    void            SetCustomByIndex(int ind, const CString& key, const CString& val);
    CString         GetCustomByKey(const CString& str) const;
    void            SetCustomByKey(const CString& key, const CString& val) const;
    void            AddCustomInfo(const CString& key, const CString& val) const;
    void            RemoveCustomByIndex(int ind);
    void            RemoveCustomByKey(const CString& str);

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
    void                    SetValue(const AcDbEvalVariant& variant);
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
    void                        PutShadowDisplay(PyAcShadowDisplayType val);
    bool                        GetEnableShadowDisplay();
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
    void       SetQuietErrorMode(bool val);
    long       GetNumberOfCopies() const;
    void       SetNumberOfCopies(long val);
    bool       GetBatchPlotProgress() const;
    void       SetBatchPlotProgress(bool val);
    void       SetDisplayPlotPreview(PyAcPreviewMode mode);
    void       SetLayoutsToPlot(const wstringArray& layouts);
    void       StartBatchMode(long val);
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
    void                    Save(PyAcMenuFileType menuType);
    void                    SaveAs(const CString& menuFileName, PyAcMenuFileType menuType);
    void                    Unload();
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
    PyIAcadMenuGroupPtr Load(const CString& menuFileName);
    PyIAcadMenuGroupPtr Load(const CString& menuFileName, const PyIAcadMenuGroupImpl& BaseMenu);
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
    void                SetLabel(const CString& val);
    CString             GetTagString() const;
    void                SetTagString(const CString& val);
    bool                GetEnable() const;
    void                SetEnable(bool val);
    bool                GetCheck() const;
    void                SetCheck(bool val);
    PyAcMenuItemType    GetType() const;
    PyIAcadPopupMenuPtr GetSubMenu() const;
    CString             GetMacro() const;
    void                SetMacro(const CString& val);
    int                 GetIndex() const;
    CString             GetCaption() const;
    CString             GetHelpString() const;
    void                SetHelpString(const CString& val);
    void                Delete();
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
    void                    SetName(const CString& val);
    CString                 GetNameNoMnemonic() const;
    bool                    GetShortcutMenu() const;
    bool                    GetOnMenuBar() const;
    PyIAcadPopupMenuItemPtr AddMenuItem(long index, const CString& label, const CString& macro);
    PyIAcadPopupMenuPtr     AddSubMenu(long index, const CString& label);
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
    PyIAcadPopupMenuPtr     Add(const CString& toolbarName);
    void                    InsertMenuInMenuBar(const CString& menuName, long index);
    void                    RemoveMenuFromMenuBar(long index);
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
    void                    SetName(const CString& val);
    CString                 GetTagString() const;
    void                    SetTagString(const CString& val);
    PyAcToolbarItemType     GetType() const;
    CString                 GetMacro() const;
    void                    SetMacro(const CString& val);
    int                     GetIndex() const;
    CString                 GetHelpString() const;
    void                    SetHelpString(const CString& val) const;
    CStringPair             GetBitmaps() const;
    void                    SetBitmaps(const CString& smallIconName, const CString& largeIconName);
    void                    AttachToolbarToFlyout(const CString& menuGroupName, const CString& toolbarName);
    void                    Delete();
    CString                 GetCommandDisplayName() const;
    void                    SetCommandDisplayName(const CString& val);
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
    void                    SetName(const CString& name);
    bool                    GetVisible() const;
    void                    SetVisible(bool val);
    PyAcToolbarDockStatus   GetDockStatus() const;
    bool                    GetLargeButtons() const;
    int                     GetLeft() const;
    void                    SetLeft(int val);
    int                     GetTop() const;
    void                    SetTop(int val);
    int                     GetWidth() const;
    int                     GetHeight() const;
    int                     GetFloatingRows() const;
    void                    SetFloatingRows(int val);
    CString                 GetHelpString() const;
    void                    SetHelpString(const CString& val) const;
    PyIAcadToolbarItemPtr   AddToolbarButton(int index, const CString& name, const CString& helpstr, const CString& macro, bool flyoutButton);
    void                    Dock(PyAcToolbarDockStatus val);
    void                    Float(int top, int teft, int numberFloatRows);
    void                    Delete();
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
    PyIAcadToolbarPtr   Add(const CString& toolbarName);
    IAcadToolbars* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    IAcadToolbarsPtr m_pimpl;
};

#pragma pack (pop)
