#pragma once
#include "PyRxObject.h"

#pragma pack (push, 8)

#if defined(_BRXTARGET260)
//
#else

class PyDbObjectId;
class PyPlDSDEntry;
class PyDbPlotSettings;
class PyPlPlotConfig;
class PyPlPlotEngine;
class PyPlPlotInfo;
class PyPlPlotPageInfo;
class PyPlPlotProgressDialog;
class PyGeBoundBlock2d;

//-----------------------------------------------------------------------------------------
//AcPlPlotFactory
void makeAcPlPlotFactoryWrapper();
class PyPlPlotFactory
{
public:
    static PyPlPlotEngine createPreviewEngine1();
    static PyPlPlotEngine createPreviewEngine2(long flags);
    static PyPlPlotEngine createPublishEngine();
    static ProcessPlotState processPlotState();
    static std::string  className();
};

//-----------------------------------------------------------------------------------------
//PyPlPlotEngine
void makePyPlPlotEngineWrapper();
class PyPlPlotEngine
{
public:
    PyPlPlotEngine(AcPlPlotEngine* ptr);
    ~PyPlPlotEngine() = default;
    void beginPlot(PyPlPlotProgressDialog& pPlotProgress) const;
    void endPlot() const;
    void beginDocument(PyPlPlotInfo& plotInfo, const std::string& pDocname, Adesk::Int32 nCopies, bool bPlotToFile, const std::string& pFileName) const;
    void endDocument() const;
    void beginPage(PyPlPlotPageInfo& pageInfo, PyPlPlotInfo& plotInfo, bool bLastPage) const;
    void endPage() const;
    void beginGenerateGraphics() const;
    void endGenerateGraphics() const;
    void destroy();
    bool isBackgroundPackaging() const;
    static std::string className();
public:
    inline AcPlPlotEngine* impObj(const std::source_location& src = std::source_location::current()) const;
    std::shared_ptr<AcPlPlotEngine> m_imp = nullptr;
};

//-----------------------------------------------------------------------------------------
//PyRxObject
void makePyPlObjectWrapper();
class PyPlObject : public PyRxObject
{
public:
    PyPlObject(const AcPlObject* ptr);
    PyPlObject(AcPlObject* ptr, bool autoDelete);
    virtual ~PyPlObject() override = default;
    static std::string      className();
public:
    AcPlObject* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//PyPlDSDData
void makePyPlDSDDataWrapper();
class PyPlDSDData : public PyPlObject
{
public:
    PyPlDSDData();
    PyPlDSDData(AcPlDSDData* ptr, bool autoDelete);
    virtual ~PyPlDSDData() override = default;
    std::string             projectPath() const;
    void                    setProjectPath(const std::string& pVal) const;
    std::string             destinationName() const;
    void                    setDestinationName(const std::string& pVal) const;
    boost::python::list     getDSDEntries() const;
    void                    setDSDEntries(const boost::python::list& val) const;
    boost::python::list     getPrecisionEntries() const;
    void                    setPrecisionEntries(const boost::python::list& val) const;
    int                     numberOfDSDEntries() const;
    PyPlDSDEntry            DSDEntryAt(int idx) const;
    AcPlDSDEntry::SheetType sheetType() const;
    void                    setSheetType(AcPlDSDEntry::SheetType val) const;
    std::string             password() const;
    void                    setPassword(const std::string& pVal) const;
    boost::python::tuple    getUnrecognizedData() const;
    void                    setUnrecognizedData1(const std::string& pSectionName, const std::string& pSectionData) const;
    void                    setUnrecognizedData2(const boost::python::list& sectionArray, const boost::python::list& dataArray) const;
    unsigned int            majorVersion() const;
    void                    setMajorVersion(unsigned int majorVersion) const;
    unsigned int            minorVersion() const;
    void                    setMinorVersion(unsigned int minorVersion) const;
    std::string             sheetSetName() const;
    void                    setSheetSetName(const std::string& pSheetSetName) const;
    unsigned int            noOfCopies() const;
    void                    setNoOfCopies(unsigned int copies) const;
    void                    setIsSheetSet(bool bSheetSet) const;
    bool                    isSheetSet() const;
    bool                    isHomogeneous() const;
    void                    setIsHomogeneous(bool bHomogeneous) const;
    bool                    plotStampOn() const;
    void                    setPlotStampOn(bool bOn) const;
    bool                    viewFile() const;
    void                    setViewFile(bool bViewFile) const;
    std::string             selectionSetName() const;
    void                    setSelectionSetName(const std::string& pSelSetName) const;
    std::string             categoryName() const;
    void                    setCategoryName(const std::string& pCategoryName) const;
    std::string             logFilePath() const;
    void                    setLogFilePath(const std::string& pLogFilePath) const;
    boost::python::tuple    get3dDwfOptions() const;
    void                    set3dDwfOptions(bool  bGroupByXrefHierarchy, bool  bPublishWithMaterials) const;
    bool                    includeLayerInfo() const;
    void                    setIncludeLayerInfo(bool bOn) const;
    bool                    lineMerge() const;
    void                    setLineMerge(bool bOn) const;
    std::string             currentPrecision() const;
    void                    setCurrentPrecision(const std::string& pCurrentPrecision) const;
    bool                    promptForDwfName() const;
    void                    setPromptForDwfName(bool bPromptForDwfName) const;
    bool                    pwdProtectPublishedDWF() const;
    void                    setPwdProtectPublishedDWF(bool bPwdProtectPublishedDWF) const;
    bool                    promptForPassword() const;
    void                    setPromptForPassword(bool bPromptForPassword) const;
    bool                    initializeLayouts() const;
    void                    setInitializeLayouts(bool initLayouts) const;
    static PyRxClass        desc();
    static std::string      className();
public:
    AcPlDSDData* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//PyPlDSDEntry
void makePyPlDSDEntryWrapper();
class PyPlDSDEntry : public PyPlObject
{
public:
    PyPlDSDEntry();
    PyPlDSDEntry(AcPlDSDEntry* ptr, bool autoDelete);
    PyPlDSDEntry(const AcPlDSDEntry& entry);
    virtual ~PyPlDSDEntry() override = default;
    std::string             dwgName() const;
    void                    setDwgName(const std::string& pName) const;
    std::string             layout() const;
    void                    setLayout(const std::string& pLayoutName) const;
    std::string             title() const;
    void                    setTitle(const std::string& pTitle) const;
    std::string             NPS() const;
    void                    setNPS(const std::string& pNPSName) const;
    std::string             NPSSourceDWG() const;
    void                    setNPSSourceDWG(const std::string& pNPWDWGName) const;
    bool                    has3dDwfSetup() const;
    void                    setHas3dDwfSetup(bool b3dDwfSetup) const;
    AcPlDSDEntry::SetupType setupType() const;
    void                    setSetupType(AcPlDSDEntry::SetupType eType) const;
    std::string             orgSheetPath() const;
    std::string             traceSession() const;
    void                    setTraceSession(const std::string& pTraceSession) const;
    static PyRxClass        desc();
    static std::string      className();
public:
    AcPlDSDEntry* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//PyPlPlotInfo
void makePyPlPlotInfoWrapper();
class PyPlPlotInfo : public PyPlObject
{
public:
    PyPlPlotInfo();
    PyPlPlotInfo(AcPlPlotInfo* ptr, bool autoDelete);
    //PyPlPlotInfo(const AcPlPlotInfo& entry);
    virtual ~PyPlPlotInfo() override = default;
    void                    copyFrom(const PyRxObject& pOther) const;
    void                    setLayout(PyDbObjectId& layoutId) const;
    PyDbObjectId            layout() const;
    void                    setOverrideSettings(const PyDbPlotSettings& pOverrides) const;
    PyDbPlotSettings        overrideSettings() const;
    void                    setDeviceOverride(const PyPlPlotConfig& pconf) const;
    PyDbPlotSettings        validatedSettings() const;
    void                    setValidatedSettings(const PyDbPlotSettings& pValidatedSettings) const;
    PyPlPlotConfig          validatedConfig() const;
    void                    setValidatedConfig(const PyPlPlotConfig& pConfig) const;
    PyPlPlotConfig          deviceOverride() const;
    bool                    isCompatibleDocument(const PyPlPlotInfo& pOtherInfo) const;
    bool                    isValidated() const;
    unsigned long           mergeStatus() const;
    std::string             OrgFilePath() const;
    static PyRxClass        desc();
    static std::string      className();
public:
    AcPlPlotInfo* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//PyPlPlotConfig
void makePyPlPlotConfigWrapper();
class PyPlPlotConfig : public PyPlObject
{
public:
    PyPlPlotConfig(const AcPlPlotConfig* ptr);
    PyPlPlotConfig(AcPlPlotConfig* ptr, bool autoDelete);
    virtual ~PyPlPlotConfig() override = default;
    boost::python::tuple    getDescriptionFields() const;
    std::string             deviceName() const;
    std::string             fullPath() const;
    unsigned int            maxDeviceDPI() const;
    unsigned long           deviceType() const;
    boost::python::list     getCanonicalMediaNameList() const;
    std::string             getLocalMediaName(const std::string& pCanonicalMediaName) const;
    boost::python::tuple    getMediaBounds(const std::string& pCanonicalMediaName) const;
    void                    refreshMediaNameList() const;
    bool                    isPlotToFile() const;
    void                    setPlotToFile(bool bPlotToFile) const;
    std::string             getDefaultFileExtension() const;
    AcPlPlotConfig::PlotToFileCapability plotToFileCapability() const;
    bool                    saveToPC3(const std::string& pPC3Name) const;
    static PyRxClass        desc();
    static std::string      className();
public:
    AcPlPlotConfig* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//PyPlPlotPageInfo
void makePyPlPlotPageInfoWrapper();
class PyPlPlotPageInfo : public PyPlObject
{
public:
    PyPlPlotPageInfo();
    PyPlPlotPageInfo(const AcPlPlotPageInfo* ptr);
    PyPlPlotPageInfo(AcPlPlotPageInfo* ptr, bool autoDelete);
    virtual ~PyPlPlotPageInfo() override = default;
    Adesk::Int32            entityCount() const;
    Adesk::Int32            rasterCount() const;
    Adesk::Int32            oleObjectCount() const;
    Adesk::Int32            gradientCount() const;
    Adesk::Int32            shadedViewportType() const;
    static PyRxClass        desc();
    static std::string      className();
public:
    AcPlPlotPageInfo* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//PyPlPlotInfoValidator
void makePyPlPlotInfoValidatorWrapper();
class PyPlPlotInfoValidator : public PyPlObject
{
public:
    PyPlPlotInfoValidator();
    PyPlPlotInfoValidator(const AcPlPlotInfoValidator* ptr);
    PyPlPlotInfoValidator(AcPlPlotInfoValidator* ptr, bool autoDelete);
    virtual ~PyPlPlotInfoValidator() override = default;
    void                validate(PyPlPlotInfo& info) const;
    AcPlPlotInfoValidator::eCustomSizeResult isCustomPossible(PyPlPlotInfo& info) const;
    AcPlPlotInfoValidator::MatchingPolicy matchingPolicy() const;
    void                setMediaMatchingPolicy(AcPlPlotInfoValidator::MatchingPolicy policy) const;
    void                setMediaGroupWeight(unsigned int weight) const;
    void                setDefMediaGroupWeight() const;
    unsigned int        mediaGroupWeight() const;
    void                setSheetMediaGroupWeight(unsigned int weight) const;
    void                setDefSheetMediaGroupWeight() const;
    unsigned int        sheetMediaGroupWeight() const;
    void                setMediaBoundsWeight(unsigned int weight) const;
    void                setDefMediaBoundsWeight() const;
    unsigned int        mediaBoundsWeight() const;
    void                setPrintableBoundsWeight(unsigned int weight) const;
    void                setDefPrintableBoundsWeight() const;
    unsigned int        printableBoundsWeight() const;
    void                setDimensionalWeight(unsigned int weight) const;
    void                setDefDimensionalWeight() const;
    unsigned int        dimensionalWeight() const;
    void                setSheetDimensionalWeight(unsigned int weight) const;
    void                setDefSheetDimensionalWeight() const;
    unsigned int        sheetDimensionalWeight() const;
    void                setMediaMatchingThreshold(unsigned int threshold) const;
    void                setDefMediaMatchingThreshold() const;
    unsigned int        mediaMatchingThreshold() const;
    static PyRxClass    desc();
    static std::string  className();
public:
    AcPlPlotInfoValidator* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//PyPlPrecisionEntry
void makePyPlPrecisionEntryWrapper();
class PyPlPrecisionEntry : public PyPlObject
{
public:
    PyPlPrecisionEntry();
    PyPlPrecisionEntry(const AcPlPrecisionEntry& entry);
    PyPlPrecisionEntry(AcPlPrecisionEntry* ptr, bool autoDelete);
    virtual ~PyPlPrecisionEntry() override = default;
    const std::string   title() const;
    void                setTitle(const std::string& pTitle) const;
    const std::string   description() const;
    void                setDescription(const std::string& pDescription) const;
    const std::string   unitType() const;
    void                setUnitType(const std::string& pUnitType) const;
    const std::string   unitScale() const;
    void                setUnitScale(const std::string& pUnitScale) const;
    double              desiredPrecision() const;
    void                setDesiredPrecision(double dDesiredPrecision) const;
    int                 gradientResolution() const;
    void                setGradientResolution(int nGradientResolution) const;
    int                 colorResolution() const;
    void                setColorResolution(int nColorResolution) const;
    int                 monoResolution() const;
    void                setMonoResolution(int nMonoResolution) const;
    static PyRxClass    desc();
    static std::string  className();
public:
    AcPlPrecisionEntry* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//PylPlotConfigInfo
void makePyPlPlotConfigInfoWrapper();
class PyPlPlotConfigInfo : public PyPlObject
{
public:
    PyPlPlotConfigInfo();
    PyPlPlotConfigInfo(const std::string& pDevName, const std::string& pFullPath, DeviceType devType);
    PyPlPlotConfigInfo(const AcPlPlotConfigInfo& copy);
    PyPlPlotConfigInfo(AcPlPlotInfoValidator* ptr, bool autoDelete);
    virtual ~PyPlPlotConfigInfo() override = default;
    std::string         fullPath() const;
    void                setFullPath(const std::string& pPath) const;
    std::string         deviceName() const;
    void                setDeviceName(const std::string& pDevName) const;
    DeviceType          deviceType() const;
    void                setDeviceType(DeviceType devType) const;
    std::string         deviceId() const;
    void                setDeviceId(const std::string& pDevId) const;
    static PyRxClass    desc();
    static std::string  className();
public:
    AcPlPlotConfigInfo* impObj(const std::source_location& src = std::source_location::current()) const;
};

#endif
#pragma pack (pop)
