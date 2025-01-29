#pragma once

#include "PyAcAxCommon.h"

#pragma pack (push, 8)

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

//----------------------------------------------------------------------------------------
//PyAcadAcCmColor
void makePyAcadAcCmColorWrapper();

class PyAcadAcCmColor
{
public:
    PyAcadAcCmColor(std::shared_ptr<PyIAcadAcCmColorImpl> ptr);
    virtual ~PyAcadAcCmColor() = default;
    void            setEntityColor(long val);
    long            entityColor() const;
    std::string     colorName() const;
    std::string     bookName() const;
    void            setNames(const std::string& colorName, const std::string& bookName);
    void            clear();
    long            red() const;
    long            green() const;
    long            blue() const;
    void            setRGB(long red, long green, long blue);
    PyAcColorMethod colorMethod() const;
    void            setColorMethod(PyAcColorMethod flags);
    PyAcColor       colorIndex() const;
    void            setColorIndex(PyAcColor val);
    void            setColorBookColor(const std::string& colorName, const std::string& bookName);
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
    void            setURL(const std::string& val);
    std::string     urlDescription() const;
    void            setURLDescription(const std::string& val);
    void            clear();
    std::string     urlNamedLocation() const;
    void            setURLNamedLocation(const std::string& val);

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
    PyAcadHyperlink    item(long val);
    long               count() const;
    PyAcadHyperlink    add(const std::string& name, const std::string& description, const std::string& namedLocation);
    static std::string  className();
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
    void            setSupportPath(const std::string& val);
    std::string     supportPath() const;
    void            setDriversPath(const std::string& val);
    std::string     driversPath() const;
    void            setMenuFile(const std::string& val);
    std::string     menuFile() const;
    void            setEnterpriseMenuFile(const std::string& val);
    std::string     enterpriseMenuFile() const;
    void            setCustomIconPath(const std::string& val);
    std::string     customIconPath() const;
    void            setHelpFilePath(const std::string& val);
    std::string     helpFilePath() const;
    void            setDefaultInternetURL(const std::string& val);
    std::string     defaultInternetURL() const;
    std::string     configFile() const;
    std::string     licenseServer() const;
    void            setTextEditor(const std::string& val);
    std::string     textEditor() const;
    void            setMainDictionary(const std::string& val);
    std::string     mainDictionary() const;
    void            setCustomDictionary(const std::string& val);
    std::string     customDictionary() const;
    void            setAltFontFile(const std::string& val);
    std::string     altFontFile() const;
    void            setFontFileMap(const std::string& val);
    std::string     fontFileMap() const;
    void            setPrintFile(const std::string& val);
    std::string     printFile() const;
    void            setPrintSpoolExecutable(const std::string& val);
    std::string     printSpoolExecutable() const;
    void            setPostScriptPrologFile(const std::string& val);
    std::string     postScriptPrologFile() const;
    void            setPrintSpoolerPath(const std::string& val);
    std::string     printSpoolerPath() const;
    void            setAutoSavePath(const std::string& val);
    std::string     autoSavePath() const;
    void            setTemplateDwgPath(const std::string& val);
    std::string     templateDwgPath() const;
    void            setLogFilePath(const std::string& val);
    std::string     logFilePath() const;
    void            setTempFilePath(const std::string& val);
    std::string     tempFilePath() const;
    void            setTempXrefPath(const std::string& val);
    std::string     tempXrefPath() const;
    void            setTextureMapPath(const std::string& val);
    std::string     textureMapPath() const;
    void            setAltTabletMenuFile(const std::string& val);
    std::string     altTabletMenuFile() const;
    void            setProjectFilePath(const std::string& projectName, const std::string& projectFilePath);
    std::string     projectFilePath(const std::string& projectName) const;
    void            setPrinterConfigPath(const std::string& val);
    std::string     printerConfigPath() const;
    void            setPrinterDescPath(const std::string& val);
    std::string     printerDescPath() const;
    void            setPrinterStyleSheetPath(const std::string& val);
    std::string     printerStyleSheetPath() const;
    void            setWorkspacePath(const std::string& val);
    std::string     workspacePath() const;
    void            setObjectARXPath(const std::string& val);
    std::string     objectARXPath() const;
    void            setColorBookPath(const std::string& val);
    std::string     colorBookPath() const;
    void            setToolPalettePath(const std::string& val);
    std::string     toolPalettePath() const;
    void            setQNewTemplateFile(const std::string& val);
    std::string     qnewTemplateFile() const;
    void            setPlotLogFilePath(const std::string& val);
    std::string     plotLogFilePath() const;
    void            setPageSetupOverridesTemplateFile(const std::string& val);
    std::string     pageSetupOverridesTemplateFile() const;
    void            setActiveInvProject(const std::string& val);
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
    void                    setLayoutDisplayMargins(bool val);
    bool                    layoutDisplayMargins() const;
    void                    setLayoutDisplayPaper(bool val);
    bool                    layoutDisplayPaper() const;
    void                    setLayoutDisplayPaperShadow(bool val);
    bool                    layoutDisplayPaperShadow() const;
    void                    setLayoutShowPlotSetup(bool val);
    bool                    layoutShowPlotSetup() const;
    void                    setLayoutCreateViewport(bool val);
    bool                    layoutCreateViewport() const;
    void                    setDisplayScrollBars(bool val);
    bool                    displayScrollBars() const;
    void                    setDisplayScreenMenu(bool val);
    bool                    displayScreenMenu() const;
    void                    setCursorSize(int val);
    int                     cursorSize() const;
    void                    setDockedVisibleLines(int val);
    int                     dockedVisibleLines() const;
    void                    setShowRasterImage(bool val);
    bool                    showRasterImage() const;
    void                    setGraphicsWinModelBackgrndColor(const boost::python::tuple& val);
    boost::python::tuple    graphicsWinModelBackgrndColor() const;
    void                    setModelCrosshairColor(const boost::python::tuple& val);
    boost::python::tuple    modelCrosshairColor() const;
    void                    setGraphicsWinLayoutBackgrndColor(const boost::python::tuple& val);
    boost::python::tuple    graphicsWinLayoutBackgrndColor() const;
    void                    setTextWinBackgrndColor(const boost::python::tuple& val);
    boost::python::tuple    textWinBackgrndColor() const;
    void                    setTextWinTextColor(const boost::python::tuple& val);
    boost::python::tuple    textWinTextColor() const;
    void                    setLayoutCrosshairColor(const boost::python::tuple& val);
    boost::python::tuple    layoutCrosshairColor() const;
    void                    setAutoTrackingVecColor(const boost::python::tuple& val);
    boost::python::tuple    autoTrackingVecColor() const;
    void                    setTextFont(const std::string& val);
    std::string             textFont() const;
    void                    setTextFontStyle(const PyAcTextFontStyle& val);
    PyAcTextFontStyle       textFontStyle() const;
    void                    setTextFontSize(int val);
    int                     textFontSize() const;
    void                    setHistoryLines(int val);
    int                     historyLines() const;
    void                    setMaxAutoCADWindow(bool val);
    bool                    maxAutoCADWindow() const;
    void                    setDisplayLayoutTabs(bool val);
    bool                    displayLayoutTabs() const;
    void                    setImageFrameHighlight(bool val);
    bool                    imageFrameHighlight() const;
    void                    setTrueColorImages(bool val);
    bool                    trueColorImages() const;
    void                    setXRefFadeIntensity(long val);
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
    void                setSavePreviewThumbnail(bool val);
    bool                savePreviewThumbnail() const;
    void                setIncrementalSavePercent(int val);
    int                 incrementalSavePercent() const;
    void                setAutoSaveInterval(int val);
    int                 autoSaveInterval() const;
    void                setCreateBackup(bool val);
    bool                createBackup() const;
    void                setFullCRCValidation(bool val);
    bool                fullCRCValidation() const;
    void                setLogFileOn(bool val);
    bool                logFileOn() const;
    void                setTempFileExtension(const std::string& val);
    std::string         tempFileExtension() const;
    void                setXrefDemandLoad(PyAcXRefDemandLoad val);
    PyAcXRefDemandLoad  xrefDemandLoad() const;
    void                setDemandLoadARXApp(PyAcARXDemandLoad val);
    PyAcARXDemandLoad   demandLoadARXApp() const;
    void                setProxyImage(PyAcProxyImage val);
    PyAcProxyImage      proxyImage() const;
    void                setShowProxyDialogBox(bool val);
    bool                showProxyDialogBox() const;
    void                setAutoAudit(bool val);
    bool                autoAudit() const;
    void                setSaveAsType(PyAcSaveAsType val);
    PyAcSaveAsType      saveAsType() const;
    long                mruNumber();
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
    void                    setDefaultOutputDevice(const std::string& val);
    std::string             defaultOutputDevice() const;
    void                    setPrinterSpoolAlert(PyAcPrinterSpoolAlert val);
    PyAcPrinterSpoolAlert   printerSpoolAlert() const;
    void                    setPrinterPaperSizeAlert(bool val);
    bool                    printerPaperSizeAlert() const;
    void                    setPlotLegacy(bool val);
    bool                    plotLegacy() const;
    void                    setOLEQuality(PyAcOleQuality val);
    PyAcOleQuality          oleQuality() const;
    void                    setUseLastPlotSettings(bool val);
    bool                    useLastPlotSettings() const;
    void                    setPlotPolicy(PyAcPlotPolicy val);
    PyAcPlotPolicy          plotPolicy() const;
    void                    setDefaultPlotStyleTable(const std::string& val);
    std::string             defaultPlotStyleTable() const;
    void                    setDefaultPlotStyleForObjects(const std::string& val);
    std::string             defaultPlotStyleForObjects() const;
    void                    setDefaultPlotStyleForLayer(const std::string& val);
    std::string             defaultPlotStyleForLayer() const;
    void                    setContinuousPlotLog(bool val);
    bool                    continuousPlotLog() const;
    void                    setAutomaticPlotLog(bool val);
    bool                    automaticPlotLog() const;
    void                    setDefaultPlotToFilePath(const std::string& val);
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
    void    setSingleDocumentMode(bool val);
    bool    singleDocumentMode() const;
    void    setDisplayOLEScale(bool val);
    bool    displayOLEScale() const;
    void    setStoreSQLIndex(bool val);
    bool    storeSQLIndex() const;
    void    setTablesReadOnly(bool val);
    bool    tablesReadOnly() const;
    void    setEnableStartupDialog(bool val);
    bool    enableStartupDialog() const;
    void    setBeepOnError(bool val);
    bool    beepOnError() const;
    void    setShowWarningMessages(bool val);
    bool    showWarningMessages() const;
    void    setLoadAcadLspInAllDocuments(bool val);
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
    void                        setKeyboardAccelerator(PyAcKeyboardAccelerator val);
    PyAcKeyboardAccelerator     keyboardAccelerator() const;
    void                        setKeyboardPriority(PyAcKeyboardPriority val);
    PyAcKeyboardPriority        keyboardPriority() const;
    void                        setHyperlinkDisplayCursor(bool val);
    bool                        hyperlinkDisplayCursor() const;
    void                        setADCInsertUnitsDefaultSource(PyAcInsertUnits val);
    PyAcInsertUnits             adcInsertUnitsDefaultSource() const;
    void                        setADCInsertUnitsDefaultTarget(PyAcInsertUnits val);
    PyAcInsertUnits             adcInsertUnitsDefaultTarget() const;
    void                        setShortCutMenuDisplay(bool val);
    bool                        shortCutMenuDisplay() const;
    void                        setSCMDefaultMode(PyAcDrawingAreaSCMDefault val);
    PyAcDrawingAreaSCMDefault   scmDefaultMode() const;
    void                        setSCMEditMode(PyAcDrawingAreaSCMEdit val);
    PyAcDrawingAreaSCMEdit      acmEditMode() const;
    void                        setSCMCommandMode(PyAcDrawingAreaSCMCommand val);
    PyAcDrawingAreaSCMCommand   scmCommandMode() const;
    void                        setSCMTimeMode(bool val);
    bool                        scmTimeMode() const;
    void                        setSCMTimeValue(int val);
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
    void            setAutoSnapMarker(bool val);
    bool            autoSnapMarker() const;
    void            setAutoSnapMagnet(bool val);
    bool            autoSnapMagnet() const;
    void            setAutoSnapTooltip(bool val);
    bool            autoSnapTooltip() const;
    void            setAutoSnapAperture(bool val);
    bool            autoSnapAperture() const;
    void            setAutoSnapApertureSize(long val);
    long            autoSnapApertureSize() const;
    void            setAutoSnapMarkerColor(PyAcColor val);
    PyAcColor       autoSnapMarkerColor() const;
    void            setAutoSnapMarkerSize(long val);
    long            autoSnapMarkerSize() const;
    void            setPolarTrackingVector(bool val);
    bool            polarTrackingVector() const;
    void            setFullScreenTrackingVector(bool val);
    bool            fullScreenTrackingVector() const;
    void            setAutoTrackTooltip(bool val);
    bool            autoTrackTooltip() const;
    void            setAlignmentPointAcquisition(PyAcAlignmentPointAcquisition val);
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
    void        setPickFirst(bool val);
    bool        pickFirst() const;
    void        setPickAdd(bool val);
    bool        pickAdd() const;
    void        setPickDrag(bool val);
    bool        pickDrag() const;
    void        setPickAuto(bool val);
    bool        pickAuto() const;
    void        setPickBoxSize(long val);
    long        pickBoxSize() const;
    void        setDisplayGrips(bool val);
    bool        displayGrips() const;
    void        setDisplayGripsWithinBlocks(bool val);
    bool        displayGripsWithinBlocks() const;
    void        setGripColorSelected(PyAcColor val);
    PyAcColor   gripColorSelected() const;
    void        setGripColorUnselected(PyAcColor val);
    PyAcColor   gripColorUnselected() const;
    void        setGripSize(long val);
    long        gripSize() const;
    void        setPickGroup(bool val);
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
    void                setActiveProfile(const std::string& str);
    void                importProfile(const std::string& ProfileName, const std::string& RegFile, bool IncludePathInfo);
    void                exportProfile(const std::string& ProfileName, const std::string& RegFile);
    void                deleteProfile(const std::string& ProfileName);
    void                resetProfile(const std::string& Profile);
    void                renameProfile(const std::string& origProfileName, const std::string& newProfileName);
    void                copyProfile(const std::string& oldProfileName, const std::string& newProfileName);
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
    PyAcadSummaryInfo(PyIAcadSummaryInfoImpl* ptr);
    virtual ~PyAcadSummaryInfo() = default;
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
    PyAcadDynamicBlockReferenceProperty(PyIAcadDynamicBlockReferencePropertyImpl* ptr);
    virtual ~PyAcadDynamicBlockReferenceProperty() = default;
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
    PyAcadIdPair(PyIAcadIdPairImpl* ptr);
    virtual ~PyAcadIdPair() = default;
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
    PyAcadShadowDisplay(PyIAcadShadowDisplayImpl* ptr);
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
    void                    save(PyAcMenuFileType menuType);
    void                    saveAs(const std::string& menuFileName, PyAcMenuFileType menuType);
    void                    unload();
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
    PyAcadMenuGroup     load1(const std::string& menuFileName);
    PyAcadMenuGroup     load2(const std::string& menuFileName, const PyAcadMenuGroup& baseMenu);
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
    void                setLabel(const std::string& val);
    std::string         tagString() const;
    void                setTagString(const std::string& val);
    bool                enable() const;
    void                setEnable(bool val);
    bool                check() const;
    void                setCheck(bool val);
    PyAcMenuItemType    getType() const;
    PyAcadPopupMenu     subMenu() const;
    std::string         macro() const;
    void                setMacro(const std::string& val);
    int                 index() const;
    std::string         caption() const;
    std::string         helpString() const;
    void                setHelpString(const std::string& val);
    void                clear();
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
    void                    setName(const std::string& val);
    std::string             nameNoMnemonic() const;
    bool                    isShortcutMenu() const;
    bool                    isOnMenuBar() const;
    PyAcadPopupMenuItem     addMenuItem(long index, const std::string& label, const std::string& macro);
    PyAcadPopupMenu         addSubMenu(long index, const std::string& label);
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
    PyAcadPopupMenu     add(const std::string& toolbarName);
    void                insertMenuInMenuBar(const std::string& menuName, long index);
    void                removeMenuFromMenuBar(long index);
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
    void                    setName(const std::string& val);
    std::string             tagString() const;
    void                    setTagString(const std::string& val);
    PyAcToolbarItemType     getType() const;
    std::string             macro() const;
    void                    setMacro(const std::string& val);
    int                     index() const;
    std::string             helpString() const;
    void                    setHelpString(const std::string& val) const;
    boost::python::tuple    bitmaps() const;
    void                    setBitmaps(const std::string& smallIconName, const std::string& largeIconName);
    void                    attachToolbarToFlyout(const std::string& menuGroupName, const std::string& toolbarName);
    void                    clear();
    std::string             commandDisplayName() const;
    void                    setCommandDisplayName(const std::string& val);
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
    void                    setName(const std::string& name);
    bool                    isVisible() const;
    void                    setVisible(bool val);
    PyAcToolbarDockStatus   dockStatus() const;
    bool                    largeButtons() const;
    int                     left() const;
    void                    setLeft(int val);
    int                     top() const;
    void                    setTop(int val);
    int                     width() const;
    int                     height() const;
    int                     floatingRows() const;
    void                    setFloatingRows(int val);
    std::string             helpString() const;
    void                    setHelpString(const std::string& val) const;
    PyAcadToolbarItem       addToolbarButton(int index, const std::string& name, const std::string& helpstr, const std::string& macro, bool flyoutButton);
    void                    dock(PyAcToolbarDockStatus val);
    void                    setFloat(int itop, int ileft, int numberFloatRows);
    void                    clear();
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
    PyAcadToolbar       add(const std::string& toolbarName);
    static std::string  className();
public:
    PyIAcadToolbarsImpl* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    std::shared_ptr<PyIAcadToolbarsImpl> m_pyImp;
};


#pragma pack (pop)