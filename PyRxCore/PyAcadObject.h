#pragma once

#include "PyAcAxCommon.h"

#pragma pack (push, 8)

class PyDbObjectId;
class PyDbEvalVariant;

class PyIAcadAcCmColorImpl;
class PyIAcadHyperlinkImpl;
class PyIAcadHyperlinksImpl;
class PyIAcadSectionTypeSettingsImpl;
class PyIAcadDatabasePreferencesImpl;
class PyIAcadPreferencesFilesImpl;
class PyIAcadPreferencesDisplayImpl;
class PyIAcadPreferencesOpenSaveImpl;
class PyIAcadPreferencesOutputImpl;
class PyIAcadPreferencesSystemImpl;
class PyIAcadPreferencesUserImpl;
class PyIAcadPreferencesDraftingImpl;
class PyIAcadPreferencesSelectionImpl;
class PyIAcadPreferencesProfilesImpl;
class PyIAcadPreferencesImpl;
class PyIAcadSummaryInfoImpl;
class PyIAcadDynamicBlockReferencePropertyImpl;
class PyIAcadIdPairImpl;
#ifndef _BRXTARGET
class PyIAcadShadowDisplayImpl;
#endif
class PyIAcadPlotImpl;
class PyIAcadMenuBarImpl;
class PyIAcadMenuGroupImpl;
class PyIAcadMenuGroupsImpl;
class PyIAcadPopupMenuItemImpl;
class PyIAcadPopupMenuImpl;
class PyIAcadPopupMenusImpl;
class PyIAcadToolbarItemImpl;
class PyIAcadToolbarImpl;
class PyIAcadToolbarsImpl;

class PyAcadPopupMenu;
class PyAcadPopupMenus;
class PyAcadMenuGroups;
class PyAcadToolbars;
class PyAcadToolbar;
class PyAcadBlock;

//----------------------------------------------------------------------------------------
//PyAcadAcCmColor
void makePyAcadAcCmColorWrapper();

class PyAcadAcCmColor
{
public:
    PyAcadAcCmColor();
    PyAcadAcCmColor(PyAcColor colorindex);
    PyAcadAcCmColor(const std::string& val);
    PyAcadAcCmColor(Adesk::UInt8 r, Adesk::UInt8 g, Adesk::UInt8 b);
    PyAcadAcCmColor(std::shared_ptr<PyIAcadAcCmColorImpl> ptr);
    virtual ~PyAcadAcCmColor() = default;
    void            setEntityColor(long val) const;
    long            entityColor() const;
    std::string     colorName() const;
    std::string     bookName() const;
    std::string     toHTMLColor() const;
    void            fromHTMLColor(const std::string& code) const;
    void            setNames(const std::string& colorName, const std::string& bookName) const;
    void            clear() const;
    long            red() const;
    long            green() const;
    long            blue() const;
    void            setRGB(long red, long green, long blue) const;
    PyAcColorMethod colorMethod() const;
    void            setColorMethod(PyAcColorMethod flags) const;
    PyAcColor       colorIndex() const;
    void            setColorIndex(PyAcColor val) const;
    void            setColorBookColor(const std::string& colorName, const std::string& bookName) const;
    static std::string  className();
public:
    PyIAcadAcCmColorImpl* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    std::shared_ptr<PyIAcadAcCmColorImpl> m_pyImp;
};

//----------------------------------------------------------------------------------------
//PyAcadHyperlink
void makePyAcadHyperlinkWrapper();

class PyAcadHyperlink
{
public:
    PyAcadHyperlink(std::shared_ptr<PyIAcadHyperlinkImpl> ptr);
    virtual ~PyAcadHyperlink() = default;

    std::string     url() const;
    void            setURL(const std::string& val) const;
    std::string     urlDescription() const;
    void            setURLDescription(const std::string& val) const;
    void            clear() const;
    std::string     urlNamedLocation() const;
    void            setURLNamedLocation(const std::string& val) const;

    static std::string  className();
public:
    PyIAcadHyperlinkImpl* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    std::shared_ptr<PyIAcadHyperlinkImpl> m_pyImp;
};

//----------------------------------------------------------------------------------------
//PyAcadHyperlinks
void makePyAcadHyperlinksWrapper();

class PyAcadHyperlinks
{
public:
    PyAcadHyperlinks(std::shared_ptr<PyIAcadHyperlinksImpl> ptr);
    virtual ~PyAcadHyperlinks() = default;
    PyAcadHyperlink    item(long val) const;
    long               count() const;
    PyAcadHyperlink    add(const std::string& name, const std::string& description, const std::string& namedLocation) const;
    static std::string className();
public:
    PyIAcadHyperlinksImpl* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    std::shared_ptr<PyIAcadHyperlinksImpl> m_pyImp;
};

//----------------------------------------------------------------------------------------
//PyAcadSectionTypeSettings
void makePyAcadSectionTypeSettingsWrapper();

class PyAcadSectionTypeSettings
{
public:
    PyAcadSectionTypeSettings(std::shared_ptr<PyIAcadSectionTypeSettingsImpl> ptr);
    virtual ~PyAcadSectionTypeSettings() = default;

    PyAcSectionGeneration   generationOptions() const;
    void                    setGenerationOptions(PyAcSectionGeneration val) const;
    boost::python::list     sourceObjects() const;
    void                    setSourceObjects(const boost::python::list& ids) const;
    PyAcadBlock             destinationBlock() const;
    void                    setDestinationBlock(const PyAcadBlock& val) const;
    std::string             destinationFile() const;
    void                    setDestinationFile(const std::string& val) const;
    PyAcadAcCmColor         intersectionBoundaryColor() const;
    void                    setIntersectionBoundaryColor(const PyAcadAcCmColor& val) const;
    std::string             intersectionBoundaryLayer() const;
    void                    setIntersectionBoundaryLayer(const std::string& val) const;
    std::string             intersectionBoundaryLinetype() const;
    void                    setIntersectionBoundaryLinetype(const std::string& val) const;
    double                  intersectionBoundaryLinetypeScale() const;
    void                    setIntersectionBoundaryLinetypeScale(double val) const;
    std::string             intersectionBoundaryPlotStyleName() const;
    void                    setIntersectionBoundaryPlotStyleName(const std::string& val) const;
    PyAcLineWeight          intersectionBoundaryLineweight() const;
    void                    setIntersectionBoundaryLineweight(PyAcLineWeight val) const;
    bool                    intersectionBoundaryDivisionLines() const;
    void                    setIntersectionBoundaryDivisionLines(bool val) const;
    bool                    intersectionFillVisible() const;
    void                    setIntersectionFillVisible(bool val) const;
    PyAcPatternType         intersectionFillHatchPatternType() const;
    void                    setIntersectionFillHatchPatternType(PyAcPatternType val) const;
    std::string             intersectionFillHatchPatternName() const;
    void                    setIntersectionFillHatchPatternName(const std::string& val) const;
    double                  intersectionFillHatchAngle() const;
    void                    setIntersectionFillHatchAngle(double val) const;
    double                  intersectionFillHatchScale() const;
    void                    setIntersectionFillHatchScale(double val) const;
    double                  intersectionFillHatchSpacing() const;
    void                    setIntersectionFillHatchSpacing(double val) const;
    PyAcadAcCmColor         intersectionFillColor() const;
    void                    setIntersectionFillColor(const PyAcadAcCmColor& val) const;
    std::string             intersectionFillLayer() const;
    void                    setIntersectionFillLayer(const std::string& val) const;
    std::string             intersectionFillLinetype() const;
    void                    setIntersectionFillLinetype(const std::string& val) const;
    double                  intersectionFillLinetypeScale() const;
    void                    setIntersectionFillLinetypeScale(double val) const;
    void                    setIntersectionFillPlotStyleName(const std::string& val) const;
    std::string             intersectionFillPlotStyleName() const;
    PyAcLineWeight          intersectionFillLineweight() const;
    void                    setIntersectionFillLineweight(PyAcLineWeight val) const;
    long                    intersectionFillFaceTransparency() const;
    void                    setIntersectionFillFaceTransparency(long val) const;
    bool                    backgroundLinesVisible() const;
    void                    setBackgroundLinesVisible(bool val) const;
    bool                    backgroundLinesHiddenLine() const;
    void                    setBackgroundLinesHiddenLine(bool val) const;
    PyAcadAcCmColor         backgroundLinesColor() const;
    void                    setBackgroundLinesColor(const PyAcadAcCmColor& val) const;
    std::string             backgroundLinesLayer() const;
    void                    setBackgroundLinesLayer(const std::string& val) const;
    std::string             backgroundLinesLinetype() const;
    void                    setBackgroundLinesLinetype(const std::string& val) const;
    double                  backgroundLinesLinetypeScale() const;
    void                    setBackgroundLinesLinetypeScale(double val) const;
    std::string             backgroundLinesPlotStyleName() const;
    void                    setBackgroundLinesPlotStyleName(const std::string& val) const;
    PyAcLineWeight          backgroundLinesLineweight() const;
    void                    setBackgroundLinesLineweight(PyAcLineWeight val) const;
    bool                    foregroundLinesVisible() const;
    void                    setForegroundLinesVisible(bool val) const;
    bool                    foregroundLinesHiddenLine() const;
    void                    setForegroundLinesHiddenLine(bool val) const;
    PyAcadAcCmColor         foregroundLinesColor() const;
    void                    setForegroundLinesColor(const PyAcadAcCmColor& val) const;
    std::string             foregroundLinesLayer() const;
    void                    setForegroundLinesLayer(const std::string& val) const;
    std::string             foregroundLinesLinetype() const;
    void                    setForegroundLinesLinetype(const std::string& val) const;
    double                  foregroundLinesLinetypeScale() const;
    void                    setForegroundLinesLinetypeScale(double val) const;
    std::string             foregroundLinesPlotStyleName() const;
    void                    setForegroundLinesPlotStyleName(const std::string& val) const;
    PyAcLineWeight          foregroundLinesLineweight() const;
    void                    setForegroundLinesLineweight(PyAcLineWeight val) const;
    long                    foregroundLinesFaceTransparency() const;
    void                    setForegroundLinesFaceTransparency(long val) const;
    long                    foregroundLinesEdgeTransparency() const;
    void                    setForegroundLinesEdgeTransparency(long val) const;
    bool                    curveTangencyLinesVisible() const;
    void                    setCurveTangencyLinesVisible(bool val) const;
    PyAcadAcCmColor         curveTangencyLinesColor() const;
    void                    setCurveTangencyLinesColor(const PyAcadAcCmColor& val) const;
    std::string             curveTangencyLinesLayer() const;
    void                    setCurveTangencyLinesLayer(const std::string& val) const;
    std::string             curveTangencyLinesLinetype() const;
    void                    setCurveTangencyLinesLinetype(const std::string& val) const;
    double                  curveTangencyLinesLinetypeScale() const;
    void                    setCurveTangencyLinesLinetypeScale(double val) const;
    std::string             curveTangencyLinesPlotStyleName() const;
    void                    setCurveTangencyLinesPlotStyleName(const std::string& val) const;
    PyAcLineWeight          curveTangencyLinesLineweight() const;
    void                    setCurveTangencyLinesLineweight(PyAcLineWeight val) const;

    static std::string  className();
public:
    PyIAcadSectionTypeSettingsImpl* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    std::shared_ptr<PyIAcadSectionTypeSettingsImpl> m_pyImp;
};

//----------------------------------------------------------------------------------------
//PyAcadDatabasePreferences
void makePyAcadDatabasePreferencesWrapper();

class PyAcadDatabasePreferences
{
public:
    PyAcadDatabasePreferences(std::shared_ptr<PyIAcadDatabasePreferencesImpl> ptr);
    virtual ~PyAcadDatabasePreferences() = default;
    bool            solidFill() const;
    void            setSolidFill(bool val) const;
    bool            xrefEdit() const;
    void            setXRefEdit(bool val) const;
    bool            xrefLayerVisibility() const;
    void            setXRefLayerVisibility(bool val) const;
    bool            oleLaunch() const;
    void            setOLELaunch(bool val) const;
    bool            allowLongSymbolNames() const;
    void            setAllowLongSymbolNames(bool val) const;
    bool            objectSortBySelection() const;
    void            setObjectSortBySelection(bool val) const;
    bool            objectSortBySnap() const;
    void            setObjectSortBySnap(bool val) const;
    bool            objectSortByRedraws() const;
    void            setObjectSortByRedraws(bool val) const;
    bool            objectSortByRegens() const;
    void            setObjectSortByRegens(bool val) const;
    bool            objectSortByPlotting() const;
    void            setObjectSortByPlotting(bool val) const;
    bool            objectSortByPSOutput() const;
    void            setObjectSortByPSOutput(bool val) const;
    void            setContourLinesPerSurface(long val) const;
    long            contourLinesPerSurface() const;
    void            setDisplaySilhouette(bool val) const;
    bool            displaySilhouette() const;
    void            setMaxActiveViewports(long val) const;
    long            maxActiveViewports() const;
    void            setRenderSmoothness(double val) const;
    double          renderSmoothness() const;
    void            setSegmentPerPolyline(long val) const;
    long            segmentPerPolyline() const;
    void            setTextFrameDisplay(bool val) const;
    bool            textFrameDisplay() const;
    void            setLineweight(PyAcLineWeight val) const;
    PyAcLineWeight  lineweight() const;
    void            setLineWeightDisplay(bool val) const;
    bool            lineWeightDisplay() const;
    static std::string  className();
public:
    PyIAcadDatabasePreferencesImpl* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    std::shared_ptr<PyIAcadDatabasePreferencesImpl> m_pyImp;
};

//----------------------------------------------------------------------------------------
//PyAcadPreferencesFiles
void makePyAcadPreferencesFilesWrapper();

class PyAcadPreferencesFiles
{
public:
    PyAcadPreferencesFiles(std::shared_ptr<PyIAcadPreferencesFilesImpl> ptr);
    virtual ~PyAcadPreferencesFiles() = default;
    void            setSupportPath(const std::string& val) const;
    std::string     supportPath() const;
    void            setDriversPath(const std::string& val) const;
    std::string     driversPath() const;
    void            setMenuFile(const std::string& val) const;
    std::string     menuFile() const;
    void            setEnterpriseMenuFile(const std::string& val) const;
    std::string     enterpriseMenuFile() const;
    void            setCustomIconPath(const std::string& val) const;
    std::string     customIconPath() const;
    void            setHelpFilePath(const std::string& val) const;
    std::string     helpFilePath() const;
    void            setDefaultInternetURL(const std::string& val) const;
    std::string     defaultInternetURL() const;
    std::string     configFile() const;
    std::string     licenseServer() const;
    void            setTextEditor(const std::string& val) const;
    std::string     textEditor() const;
    void            setMainDictionary(const std::string& val) const;
    std::string     mainDictionary() const;
    void            setCustomDictionary(const std::string& val) const;
    std::string     customDictionary() const;
    void            setAltFontFile(const std::string& val) const;
    std::string     altFontFile() const;
    void            setFontFileMap(const std::string& val) const;
    std::string     fontFileMap() const;
    void            setPrintFile(const std::string& val) const;
    std::string     printFile() const;
    void            setPrintSpoolExecutable(const std::string& val) const;
    std::string     printSpoolExecutable() const;
    void            setPostScriptPrologFile(const std::string& val) const;
    std::string     postScriptPrologFile() const;
    void            setPrintSpoolerPath(const std::string& val) const;
    std::string     printSpoolerPath() const;
    void            setAutoSavePath(const std::string& val) const;
    std::string     autoSavePath() const;
    void            setTemplateDwgPath(const std::string& val) const;
    std::string     templateDwgPath() const;
    void            setLogFilePath(const std::string& val) const;
    std::string     logFilePath() const;
    void            setTempFilePath(const std::string& val) const;
    std::string     tempFilePath() const;
    void            setTempXrefPath(const std::string& val) const;
    std::string     tempXrefPath() const;
    void            setTextureMapPath(const std::string& val) const;
    std::string     textureMapPath() const;
    void            setAltTabletMenuFile(const std::string& val) const;
    std::string     altTabletMenuFile() const;
    void            setProjectFilePath(const std::string& projectName, const std::string& projectFilePath) const;
    std::string     projectFilePath(const std::string& projectName) const;
    void            setPrinterConfigPath(const std::string& val) const;
    std::string     printerConfigPath() const;
    void            setPrinterDescPath(const std::string& val) const;
    std::string     printerDescPath() const;
    void            setPrinterStyleSheetPath(const std::string& val) const;
    std::string     printerStyleSheetPath() const;
    void            setWorkspacePath(const std::string& val) const;
    std::string     workspacePath() const;
    void            setObjectARXPath(const std::string& val) const;
    std::string     objectARXPath() const;
    void            setColorBookPath(const std::string& val) const;
    std::string     colorBookPath() const;
    void            setToolPalettePath(const std::string& val) const;
    std::string     toolPalettePath() const;
    void            setQNewTemplateFile(const std::string& val) const;
    std::string     qnewTemplateFile() const;
    void            setPlotLogFilePath(const std::string& val) const;
    std::string     plotLogFilePath() const;
    void            setPageSetupOverridesTemplateFile(const std::string& val) const;
    std::string     pageSetupOverridesTemplateFile() const;
    void            setActiveInvProject(const std::string& val) const;
    std::string     activeInvProject() const;
    static std::string  className();
public:
    PyIAcadPreferencesFilesImpl* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    std::shared_ptr<PyIAcadPreferencesFilesImpl> m_pyImp;
};

//----------------------------------------------------------------------------------------
//PyAcadPreferencesDisplay
void makePyAcadPreferencesDisplayWrapper();

class PyAcadPreferencesDisplay
{
public:
    PyAcadPreferencesDisplay(std::shared_ptr<PyIAcadPreferencesDisplayImpl> ptr);
    virtual ~PyAcadPreferencesDisplay() = default;
    void                    setLayoutDisplayMargins(bool val) const;
    bool                    layoutDisplayMargins() const;
    void                    setLayoutDisplayPaper(bool val) const;
    bool                    layoutDisplayPaper() const;
    void                    setLayoutDisplayPaperShadow(bool val) const;
    bool                    layoutDisplayPaperShadow() const;
    void                    setLayoutShowPlotSetup(bool val) const;
    bool                    layoutShowPlotSetup() const;
    void                    setLayoutCreateViewport(bool val) const;
    bool                    layoutCreateViewport() const;
    void                    setDisplayScrollBars(bool val) const;
    bool                    displayScrollBars() const;
    void                    setDisplayScreenMenu(bool val) const;
    bool                    displayScreenMenu() const;
    void                    setCursorSize(int val) const;
    int                     cursorSize() const;
    void                    setDockedVisibleLines(int val) const;
    int                     dockedVisibleLines() const;
    void                    setShowRasterImage(bool val) const;
    bool                    showRasterImage() const;
    void                    setGraphicsWinModelBackgrndColor(const boost::python::tuple& val) const;
    boost::python::tuple    graphicsWinModelBackgrndColor() const;
    void                    setModelCrosshairColor(const boost::python::tuple& val) const;
    boost::python::tuple    modelCrosshairColor() const;
    void                    setGraphicsWinLayoutBackgrndColor(const boost::python::tuple& val) const;
    boost::python::tuple    graphicsWinLayoutBackgrndColor() const;
    void                    setTextWinBackgrndColor(const boost::python::tuple& val) const;
    boost::python::tuple    textWinBackgrndColor() const;
    void                    setTextWinTextColor(const boost::python::tuple& val) const;
    boost::python::tuple    textWinTextColor() const;
    void                    setLayoutCrosshairColor(const boost::python::tuple& val) const;
    boost::python::tuple    layoutCrosshairColor() const;
    void                    setAutoTrackingVecColor(const boost::python::tuple& val) const;
    boost::python::tuple    autoTrackingVecColor() const;
    void                    setTextFont(const std::string& val) const;
    std::string             textFont() const;
    void                    setTextFontStyle(const PyAcTextFontStyle& val) const;
    PyAcTextFontStyle       textFontStyle() const;
    void                    setTextFontSize(int val) const;
    int                     textFontSize() const;
    void                    setHistoryLines(int val) const;
    int                     historyLines() const;
    void                    setMaxAutoCADWindow(bool val) const;
    bool                    maxAutoCADWindow() const;
    void                    setDisplayLayoutTabs(bool val) const;
    bool                    displayLayoutTabs() const;
    void                    setImageFrameHighlight(bool val) const;
    bool                    imageFrameHighlight() const;
    void                    setTrueColorImages(bool val) const;
    bool                    trueColorImages() const;
    void                    setXRefFadeIntensity(long val) const;
    long                    xrefFadeIntensity() const;
    static std::string      className();
public:
    PyIAcadPreferencesDisplayImpl* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    std::shared_ptr<PyIAcadPreferencesDisplayImpl> m_pyImp;
};

//----------------------------------------------------------------------------------------
//PyAcadPreferencesOpenSave
void makePyAcadPreferencesOpenSaveWrapper();

class PyAcadPreferencesOpenSave
{
public:
    PyAcadPreferencesOpenSave(std::shared_ptr<PyIAcadPreferencesOpenSaveImpl> ptr);
    virtual ~PyAcadPreferencesOpenSave() = default;
    void                setSavePreviewThumbnail(bool val) const;
    bool                savePreviewThumbnail() const;
    void                setIncrementalSavePercent(int val) const;
    int                 incrementalSavePercent() const;
    void                setAutoSaveInterval(int val) const;
    int                 autoSaveInterval() const;
    void                setCreateBackup(bool val) const;
    bool                createBackup() const;
    void                setFullCRCValidation(bool val) const;
    bool                fullCRCValidation() const;
    void                setLogFileOn(bool val) const;
    bool                logFileOn() const;
    void                setTempFileExtension(const std::string& val) const;
    std::string         tempFileExtension() const;
    void                setXrefDemandLoad(PyAcXRefDemandLoad val) const;
    PyAcXRefDemandLoad  xrefDemandLoad() const;
    void                setDemandLoadARXApp(PyAcARXDemandLoad val) const;
    PyAcARXDemandLoad   demandLoadARXApp() const;
    void                setProxyImage(PyAcProxyImage val) const;
    PyAcProxyImage      proxyImage() const;
    void                setShowProxyDialogBox(bool val) const;
    bool                showProxyDialogBox() const;
    void                setAutoAudit(bool val) const;
    bool                autoAudit() const;
    void                setSaveAsType(PyAcSaveAsType val) const;
    PyAcSaveAsType      saveAsType() const;
    long                mruNumber() const;
    static std::string  className();
public:
    PyIAcadPreferencesOpenSaveImpl* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    std::shared_ptr<PyIAcadPreferencesOpenSaveImpl> m_pyImp;
};

//----------------------------------------------------------------------------------------
//PyAcadPreferencesOutput
void makePyAcadPreferencesOutputWrapper();

class PyAcadPreferencesOutput
{
public:
    PyAcadPreferencesOutput(std::shared_ptr<PyIAcadPreferencesOutputImpl> ptr);
    virtual ~PyAcadPreferencesOutput() = default;
    void                    setDefaultOutputDevice(const std::string& val) const;
    std::string             defaultOutputDevice() const;
    void                    setPrinterSpoolAlert(PyAcPrinterSpoolAlert val) const;
    PyAcPrinterSpoolAlert   printerSpoolAlert() const;
    void                    setPrinterPaperSizeAlert(bool val) const;
    bool                    printerPaperSizeAlert() const;
    void                    setPlotLegacy(bool val) const;
    bool                    plotLegacy() const;
    void                    setOLEQuality(PyAcOleQuality val) const;
    PyAcOleQuality          oleQuality() const;
    void                    setUseLastPlotSettings(bool val) const;
    bool                    useLastPlotSettings() const;
    void                    setPlotPolicy(PyAcPlotPolicy val) const;
    PyAcPlotPolicy          plotPolicy() const;
    void                    setDefaultPlotStyleTable(const std::string& val) const;
    std::string             defaultPlotStyleTable() const;
    void                    setDefaultPlotStyleForObjects(const std::string& val) const;
    std::string             defaultPlotStyleForObjects() const;
    void                    setDefaultPlotStyleForLayer(const std::string& val) const;
    std::string             defaultPlotStyleForLayer() const;
    void                    setContinuousPlotLog(bool val) const;
    bool                    continuousPlotLog() const;
    void                    setAutomaticPlotLog(bool val) const;
    bool                    automaticPlotLog() const;
    void                    setDefaultPlotToFilePath(const std::string& val) const;
    std::string             defaultPlotToFilePath() const;
    static std::string      className();
public:
    PyIAcadPreferencesOutputImpl* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    std::shared_ptr<PyIAcadPreferencesOutputImpl> m_pyImp;
};

//----------------------------------------------------------------------------------------
//PyAcadPreferencesSystem
void makePyAcadPreferencesSystemWrapper();

class PyAcadPreferencesSystem
{
public:
    PyAcadPreferencesSystem(std::shared_ptr<PyIAcadPreferencesSystemImpl> ptr);
    virtual ~PyAcadPreferencesSystem() = default;
    void    setSingleDocumentMode(bool val) const;
    bool    singleDocumentMode() const;
    void    setDisplayOLEScale(bool val) const;
    bool    displayOLEScale() const;
    void    setStoreSQLIndex(bool val) const;
    bool    storeSQLIndex() const;
    void    setTablesReadOnly(bool val) const;
    bool    tablesReadOnly() const;
    void    setEnableStartupDialog(bool val) const;
    bool    enableStartupDialog() const;
    void    setBeepOnError(bool val) const;
    bool    beepOnError() const;
    void    setShowWarningMessages(bool val) const;
    bool    showWarningMessages() const;
    void    setLoadAcadLspInAllDocuments(bool val) const;
    bool    loadAcadLspInAllDocuments() const;
    static std::string  className();
public:
    PyIAcadPreferencesSystemImpl* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    std::shared_ptr<PyIAcadPreferencesSystemImpl> m_pyImp;
};

//----------------------------------------------------------------------------------------
//PyAcadPreferencesUser
void makePyAcadPreferencesUserWrapper();

class PyAcadPreferencesUser
{
public:
    PyAcadPreferencesUser(std::shared_ptr<PyIAcadPreferencesUserImpl> ptr);
    virtual ~PyAcadPreferencesUser() = default;
    void                        setKeyboardAccelerator(PyAcKeyboardAccelerator val) const;
    PyAcKeyboardAccelerator     keyboardAccelerator() const;
    void                        setKeyboardPriority(PyAcKeyboardPriority val) const;
    PyAcKeyboardPriority        keyboardPriority() const;
    void                        setHyperlinkDisplayCursor(bool val) const;
    bool                        hyperlinkDisplayCursor() const;
    void                        setADCInsertUnitsDefaultSource(PyAcInsertUnits val) const;
    PyAcInsertUnits             adcInsertUnitsDefaultSource() const;
    void                        setADCInsertUnitsDefaultTarget(PyAcInsertUnits val) const;
    PyAcInsertUnits             adcInsertUnitsDefaultTarget() const;
    void                        setShortCutMenuDisplay(bool val) const;
    bool                        shortCutMenuDisplay() const;
    void                        setSCMDefaultMode(PyAcDrawingAreaSCMDefault val) const;
    PyAcDrawingAreaSCMDefault   scmDefaultMode() const;
    void                        setSCMEditMode(PyAcDrawingAreaSCMEdit val) const;
    PyAcDrawingAreaSCMEdit      acmEditMode() const;
    void                        setSCMCommandMode(PyAcDrawingAreaSCMCommand val) const;
    PyAcDrawingAreaSCMCommand   scmCommandMode() const;
    void                        setSCMTimeMode(bool val) const;
    bool                        scmTimeMode() const;
    void                        setSCMTimeValue(int val) const;
    int                         scmTimeValue() const;
    static std::string          className();
public:
    PyIAcadPreferencesUserImpl* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    std::shared_ptr<PyIAcadPreferencesUserImpl> m_pyImp;
};

//----------------------------------------------------------------------------------------
//PyAcadPreferencesDrafting
void makePyAcadPreferencesDraftingWrapper();

class PyAcadPreferencesDrafting
{
public:
    PyAcadPreferencesDrafting(std::shared_ptr<PyIAcadPreferencesDraftingImpl> ptr);
    virtual ~PyAcadPreferencesDrafting() = default;
    void            setAutoSnapMarker(bool val) const;
    bool            autoSnapMarker() const;
    void            setAutoSnapMagnet(bool val) const;
    bool            autoSnapMagnet() const;
    void            setAutoSnapTooltip(bool val) const;
    bool            autoSnapTooltip() const;
    void            setAutoSnapAperture(bool val) const;
    bool            autoSnapAperture() const;
    void            setAutoSnapApertureSize(long val) const;
    long            autoSnapApertureSize() const;
    void            setAutoSnapMarkerColor(PyAcColor val) const;
    PyAcColor       autoSnapMarkerColor() const;
    void            setAutoSnapMarkerSize(long val) const;
    long            autoSnapMarkerSize() const;
    void            setPolarTrackingVector(bool val) const;
    bool            polarTrackingVector() const;
    void            setFullScreenTrackingVector(bool val) const;
    bool            fullScreenTrackingVector() const;
    void            setAutoTrackTooltip(bool val) const;
    bool            autoTrackTooltip() const;
    void            setAlignmentPointAcquisition(PyAcAlignmentPointAcquisition val) const;
    PyAcAlignmentPointAcquisition  alignmentPointAcquisition() const;
    static std::string  className();
public:
    PyIAcadPreferencesDraftingImpl* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    std::shared_ptr<PyIAcadPreferencesDraftingImpl> m_pyImp;
};

//----------------------------------------------------------------------------------------
//PyAcadPreferencesSelection
void makePyAcadPreferencesSelectionWrapper();

class PyAcadPreferencesSelection
{
public:
    PyAcadPreferencesSelection(std::shared_ptr<PyIAcadPreferencesSelectionImpl> ptr);
    virtual ~PyAcadPreferencesSelection() = default;
    void        setPickFirst(bool val) const;
    bool        pickFirst() const;
    void        setPickAdd(bool val) const;
    bool        pickAdd() const;
    void        setPickDrag(bool val) const;
    bool        pickDrag() const;
    void        setPickAuto(bool val) const;
    bool        pickAuto() const;
    void        setPickBoxSize(long val) const;
    long        pickBoxSize() const;
    void        setDisplayGrips(bool val) const;
    bool        displayGrips() const;
    void        setDisplayGripsWithinBlocks(bool val) const;
    bool        displayGripsWithinBlocks() const;
    void        setGripColorSelected(PyAcColor val) const;
    PyAcColor   gripColorSelected() const;
    void        setGripColorUnselected(PyAcColor val) const;
    PyAcColor   gripColorUnselected() const;
    void        setGripSize(long val) const;
    long        gripSize() const;
    void        setPickGroup(bool val) const;
    bool        pickGroup() const;
    static std::string  className();
public:
    PyIAcadPreferencesSelectionImpl* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    std::shared_ptr<PyIAcadPreferencesSelectionImpl> m_pyImp;
};

//----------------------------------------------------------------------------------------
//PyAcadPreferencesProfiles
void makePyAcadPreferencesProfilesWrapper();

class PyAcadPreferencesProfiles
{
public:
    PyAcadPreferencesProfiles(std::shared_ptr<PyIAcadPreferencesProfilesImpl> ptr);
    virtual ~PyAcadPreferencesProfiles() = default;
    std::string         activeProfile() const;
    void                setActiveProfile(const std::string& str) const;
    void                importProfile(const std::string& ProfileName, const std::string& RegFile, bool IncludePathInfo) const;
    void                exportProfile(const std::string& ProfileName, const std::string& RegFile) const;
    void                deleteProfile(const std::string& ProfileName) const;
    void                resetProfile(const std::string& Profile) const;
    void                renameProfile(const std::string& origProfileName, const std::string& newProfileName) const;
    void                copyProfile(const std::string& oldProfileName, const std::string& newProfileName) const;
    boost::python::list getAllProfileNames() const;
    static std::string  className();
public:
    PyIAcadPreferencesProfilesImpl* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    std::shared_ptr<PyIAcadPreferencesProfilesImpl> m_pyImp;
};

//----------------------------------------------------------------------------------------
//PyAcadPreferences
void makePyAcadPreferencesWrapper();

class PyAcadPreferences
{
public:
    PyAcadPreferences(std::shared_ptr<PyIAcadPreferencesImpl> ptr);
    virtual ~PyAcadPreferences() = default;
    PyAcadPreferencesFiles      files() const;
    PyAcadPreferencesDisplay    display() const;
    PyAcadPreferencesOpenSave   openSave() const;
    PyAcadPreferencesOutput     output() const;
    PyAcadPreferencesSystem     system() const;
    PyAcadPreferencesUser       user() const;
    PyAcadPreferencesDrafting   drafting() const;
    PyAcadPreferencesSelection  selection() const;
    PyAcadPreferencesProfiles   profiles() const;
    static std::string          className();
public:
    PyIAcadPreferencesImpl* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    std::shared_ptr<PyIAcadPreferencesImpl> m_pyImp;
};

//----------------------------------------------------------------------------------------
//PyAcadSummaryInfo
void makePyAcadSummaryInfoWrapper();

class PyAcadSummaryInfo
{
public:
    PyAcadSummaryInfo(std::shared_ptr<PyIAcadSummaryInfoImpl> ptr);
    virtual ~PyAcadSummaryInfo() = default;
    std::string         author() const;
    void                setAuthor(const std::string& str) const;
    std::string         comments() const;
    void                setComments(const std::string& str) const;
    std::string         hyperlinkBase() const;
    void                setHyperlinkBase(const std::string& str) const;
    std::string         keywords() const;
    void                setKeywords(const std::string& str) const;
    std::string         lastSavedBy() const;
    void                setLastSavedBy(const std::string& str) const;
    std::string         revisionNumber() const;
    void                setRevisionNumber(const std::string& str) const;
    std::string         subject() const;
    void                setSubject(const std::string& str) const;
    std::string         title() const;
    void                setTitle(const std::string& str) const;
    int                 numCustomInfo() const;
    boost::python::tuple customByIndex(int ind) const;
    void                setCustomByIndex(int ind, const std::string& key, const std::string& val) const;
    std::string         customByKey(const std::string& str) const;
    void                setCustomByKey(const std::string& key, const std::string& val) const;
    void                addCustomInfo(const std::string& key, const std::string& val) const;
    void                removeCustomByIndex(int ind) const;
    void                removeCustomByKey(const std::string& str) const;
    static std::string  className();
public:
    PyIAcadSummaryInfoImpl* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    std::shared_ptr<PyIAcadSummaryInfoImpl> m_pyImp;
};

//----------------------------------------------------------------------------------------
//PyAcadDynamicBlockReferenceProperty
void makePyAcadDynamicBlockReferencePropertyWrapper();

class PyAcadDynamicBlockReferenceProperty
{
public:
    PyAcadDynamicBlockReferenceProperty(std::shared_ptr<PyIAcadDynamicBlockReferencePropertyImpl> ptr);
    virtual ~PyAcadDynamicBlockReferenceProperty() = default;
    std::string             propertyName() const;
    bool                    isReadOnly() const;
    bool                    isShown() const;
    std::string             description() const;
    boost::python::list     allowedValues() const;
    PyDbEvalVariant         value() const;
    void                    setValue(const PyDbEvalVariant& variant) const;
    PyAcDynamicBlockReferencePropertyUnitsType unitsType() const;

    static std::string  className();
public:
    PyIAcadDynamicBlockReferencePropertyImpl* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    std::shared_ptr<PyIAcadDynamicBlockReferencePropertyImpl> m_pyImp;
};

//----------------------------------------------------------------------------------------
//PyAcadIdPair
void makePyAcadIdPairWrapper();

class PyAcadIdPair
{
public:
    PyAcadIdPair(std::shared_ptr<PyIAcadIdPairImpl> ptr);
    virtual ~PyAcadIdPair() = default;

    bool            isCloned() const;
    bool            isOwnerXlated() const;
    bool            isPrimary() const;
    PyDbObjectId    key() const;
    PyDbObjectId    value() const;

    static std::string  className();
public:
    PyIAcadIdPairImpl* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    std::shared_ptr<PyIAcadIdPairImpl> m_pyImp;
};

//----------------------------------------------------------------------------------------
//PyAcadShadowDisplay
#ifndef _BRXTARGET
void makePyAcadShadowDisplayWrapper();

class PyAcadShadowDisplay
{
public:
    PyAcadShadowDisplay(std::shared_ptr<PyIAcadShadowDisplayImpl> ptr);
    virtual ~PyAcadShadowDisplay() = default;
    static std::string  className();
public:
    PyIAcadShadowDisplayImpl* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    std::shared_ptr<PyIAcadShadowDisplayImpl> m_pyImp;
};
#endif

//----------------------------------------------------------------------------------------
//PyAcadPlot
void makePyAcadPlotWrapper();

class PyAcadPlot
{
public:
    PyAcadPlot(std::shared_ptr<PyIAcadPlotImpl> ptr);
    virtual ~PyAcadPlot() = default;
    bool       quietErrorMode() const;
    void       setQuietErrorMode(bool val) const;
    long       numberOfCopies() const;
    void       setNumberOfCopies(long val) const;
    bool       batchPlotProgress() const;
    void       setBatchPlotProgress(bool val) const;
    void       setDisplayPlotPreview(PyAcPreviewMode mode) const;
    void       setLayoutsToPlot(const boost::python::list& layouts) const;
    void       startBatchMode(long val) const;
    static std::string  className();
public:
    PyIAcadPlotImpl* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    std::shared_ptr<PyIAcadPlotImpl> m_pyImp;
};

//----------------------------------------------------------------------------------------
//PyAcadMenuBar
void makePyAcadMenuBarWrapper();

class PyAcadMenuBar
{
public:
    PyAcadMenuBar(std::shared_ptr<PyIAcadMenuBarImpl> ptr);
    virtual ~PyAcadMenuBar() = default;
    long                count() const;
    PyAcadPopupMenu     item(long index) const;
    static std::string  className();
public:
    PyIAcadMenuBarImpl* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    std::shared_ptr<PyIAcadMenuBarImpl> m_pyImp;
};

//----------------------------------------------------------------------------------------
//PyAcadMenuGroup
void makePyAcadMenuGroupWrapper();

class PyAcadMenuGroup
{
public:
    PyAcadMenuGroup(std::shared_ptr<PyIAcadMenuGroupImpl> ptr);
    virtual ~PyAcadMenuGroup() = default;
    PyAcadMenuGroups        parent() const;
    std::string             name() const;
    PyAcMenuGroupType       menuType() const;
    std::string             fileName() const;
    PyAcadPopupMenus        menus() const;
    PyAcadToolbars          toolbars() const;
    void                    save(PyAcMenuFileType menuType) const;
    void                    saveAs(const std::string& menuFileName, PyAcMenuFileType menuType) const;
    void                    unload() const;
    static std::string      className();
public:
    PyIAcadMenuGroupImpl* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    std::shared_ptr<PyIAcadMenuGroupImpl> m_pyImp;
};

//----------------------------------------------------------------------------------------
//PyAcadMenuGroups
void makePyAcadMenuGroupsWrapper();

class PyAcadMenuGroups
{
public:
    PyAcadMenuGroups(std::shared_ptr<PyIAcadMenuGroupsImpl> ptr);
    virtual ~PyAcadMenuGroups() = default;
    long                count() const;
    PyAcadMenuGroup     item(long index) const;
    PyAcadMenuGroup     load1(const std::string& menuFileName) const;
    PyAcadMenuGroup     load2(const std::string& menuFileName, const PyAcadMenuGroup& baseMenu) const;
    static std::string  className();
public:
    PyIAcadMenuGroupsImpl* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    std::shared_ptr<PyIAcadMenuGroupsImpl> m_pyImp;
};

//----------------------------------------------------------------------------------------
//PyAcadPopupMenuItem
void makePyAcadPopupMenuItemWrapper();

class PyAcadPopupMenuItem
{
public:
    PyAcadPopupMenuItem(std::shared_ptr<PyIAcadPopupMenuItemImpl> ptr);
    virtual ~PyAcadPopupMenuItem() = default;
    PyAcadPopupMenu     parent() const;
    std::string         label() const;
    void                setLabel(const std::string& val) const;
    std::string         tagString() const;
    void                setTagString(const std::string& val) const;
    bool                enable() const;
    void                setEnable(bool val) const;
    bool                check() const;
    void                setCheck(bool val) const;
    PyAcMenuItemType    getType() const;
    PyAcadPopupMenu     subMenu() const;
    std::string         macro() const;
    void                setMacro(const std::string& val) const;
    int                 index() const;
    std::string         caption() const;
    std::string         helpString() const;
    void                setHelpString(const std::string& val) const;
    void                clear() const;
    int                 endSubMenuLevel() const;
    void                setEndSubMenuLevel(int idx) const;
    static std::string  className();
public:
    PyIAcadPopupMenuItemImpl* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    std::shared_ptr<PyIAcadPopupMenuItemImpl> m_pyImp;
};

//----------------------------------------------------------------------------------------
//PyAcadPopupMenu
void makePyAcadPopupMenuWrapper();

class PyAcadPopupMenu
{
public:
    PyAcadPopupMenu(std::shared_ptr<PyIAcadPopupMenuImpl> ptr);
    virtual ~PyAcadPopupMenu() = default;

    long                    count() const;
    PyAcadPopupMenuItem     item(long index) const;
    PyAcadPopupMenus        parent() const;
    std::string             name() const;
    void                    setName(const std::string& val) const;
    std::string             nameNoMnemonic() const;
    bool                    isShortcutMenu() const;
    bool                    isOnMenuBar() const;
    PyAcadPopupMenuItem     addMenuItem(long index, const std::string& label, const std::string& macro) const;
    PyAcadPopupMenu         addSubMenu(long index, const std::string& label) const;
    PyAcadPopupMenuItem     addSeparator(long index) const;
    void                    insertInMenuBar(long index) const;
    void                    removeFromMenuBar() const;
    std::string             tagString() const;
    static std::string      className();
public:
    PyIAcadPopupMenuImpl* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    std::shared_ptr<PyIAcadPopupMenuImpl> m_pyImp;
};

//----------------------------------------------------------------------------------------
//PyAcadPopupMenus
void makePyAcadPopupMenusWrapper();

class PyAcadPopupMenus
{
public:
    PyAcadPopupMenus(std::shared_ptr<PyIAcadPopupMenusImpl> ptr);
    virtual ~PyAcadPopupMenus() = default;
    long                count() const;
    PyAcadPopupMenu     item(long index) const;
    PyAcadMenuGroup     parent() const;
    PyAcadPopupMenu     add(const std::string& toolbarName) const;
    void                insertMenuInMenuBar(const std::string& menuName, long index) const;
    void                removeMenuFromMenuBar(long index) const;
    static std::string  className();
public:
    PyIAcadPopupMenusImpl* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    std::shared_ptr<PyIAcadPopupMenusImpl> m_pyImp;
};

//----------------------------------------------------------------------------------------
//PyAcadToolbarItem
void makePyAcadToolbarItemWrapper();

class PyAcadToolbarItem
{
public:
    PyAcadToolbarItem(std::shared_ptr<PyIAcadToolbarItemImpl> ptr);
    virtual ~PyAcadToolbarItem() = default;
    PyAcadToolbar           parent() const;
    std::string             name() const;
    void                    setName(const std::string& val) const;
    std::string             tagString() const;
    void                    setTagString(const std::string& val) const;
    PyAcToolbarItemType     getType() const;
    std::string             macro() const;
    void                    setMacro(const std::string& val) const;
    int                     index() const;
    std::string             helpString() const;
    void                    setHelpString(const std::string& val) const;
    boost::python::tuple    bitmaps() const;
    void                    setBitmaps(const std::string& smallIconName, const std::string& largeIconName) const;
    void                    attachToolbarToFlyout(const std::string& menuGroupName, const std::string& toolbarName) const;
    void                    clear() const;
    std::string             commandDisplayName() const;
    void                    setCommandDisplayName(const std::string& val) const;
    static std::string      className();
public:
    PyIAcadToolbarItemImpl* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    std::shared_ptr<PyIAcadToolbarItemImpl> m_pyImp;
};

//----------------------------------------------------------------------------------------
//PyAcadToolbar
void makePyAcadToolbarWrapper();

class PyAcadToolbar
{
public:
    PyAcadToolbar(std::shared_ptr<PyIAcadToolbarImpl> ptr);
    virtual ~PyAcadToolbar() = default;
    long                    count() const;
    PyAcadToolbarItem       item(long index) const;
    PyAcadToolbars          parent() const;
    std::string             name() const;
    void                    setName(const std::string& name) const;
    bool                    isVisible() const;
    void                    setVisible(bool val) const;
    PyAcToolbarDockStatus   dockStatus() const;
    bool                    largeButtons() const;
    int                     left() const;
    void                    setLeft(int val) const;
    int                     top() const;
    void                    setTop(int val) const;
    int                     width() const;
    int                     height() const;
    int                     floatingRows() const;
    void                    setFloatingRows(int val) const;
    std::string             helpString() const;
    void                    setHelpString(const std::string& val) const;
    PyAcadToolbarItem       addToolbarButton(int index, const std::string& name, const std::string& helpstr, const std::string& macro, bool flyoutButton) const;
    void                    dock(PyAcToolbarDockStatus val) const;
    void                    setFloat(int itop, int ileft, int numberFloatRows) const;
    void                    clear() const;
    std::string             tagString() const;
    static std::string      className();
public:
    PyIAcadToolbarImpl* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    std::shared_ptr<PyIAcadToolbarImpl> m_pyImp;
};

//----------------------------------------------------------------------------------------
//PyAcadToolbars
void makePyAcadToolbarsWrapper();

class PyAcadToolbars
{
public:
    PyAcadToolbars(std::shared_ptr<PyIAcadToolbarsImpl> ptr);
    virtual ~PyAcadToolbars() = default;
    long                count() const;
    PyAcadToolbar       item(long index) const;
    PyAcadMenuGroup     parent() const;
    bool                largeButtons() const;
    void                setLargeButtons(bool val) const;
    PyAcadToolbar       add(const std::string& toolbarName) const;
    static std::string  className();
public:
    PyIAcadToolbarsImpl* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    std::shared_ptr<PyIAcadToolbarsImpl> m_pyImp;
};


#pragma pack (pop)