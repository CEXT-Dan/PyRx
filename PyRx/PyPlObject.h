#pragma once
#include "PyRxObject.h"

class PyDbObjectId;
class PyPlDSDEntry;
class PyDbPlotSettings;
class PyPlPlotConfig;
class PyPlPlotEngine;

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
    PyPlPlotEngine(const AcPlPlotEngine* ptr);
    virtual ~PyPlPlotEngine() = default;
    static std::string className();
public:
    inline const AcPlPlotEngine*   impObj(const std::source_location& src = std::source_location::current()) const;
    const AcPlPlotEngine* m_imp = nullptr;
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
    inline AcPlObject* impObj(const std::source_location& src = std::source_location::current()) const;
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
    void                    setProjectPath(const std::string& pVal);
    std::string             destinationName() const;
    void                    setDestinationName(const std::string& pVal);
    boost::python::list     getDSDEntries() const;
    void                    setDSDEntries(const  boost::python::list& val);
    boost::python::list     getPrecisionEntries() const;
    void                    setPrecisionEntries(const boost::python::list& val);
    int                     numberOfDSDEntries() const;
    PyPlDSDEntry            DSDEntryAt(int idx);
    AcPlDSDEntry::SheetType sheetType() const;
    void                    setSheetType(AcPlDSDEntry::SheetType val);
    std::string             password() const;
    void                    setPassword(const std::string& pVal);
    void                    getUnrecognizedData(boost::python::list& sectionArray, boost::python::list& dataArray) const;
    void                    setUnrecognizedData1(const std::string& pSectionName, const std::string& pSectionData);
    void                    setUnrecognizedData2(const boost::python::list& sectionArray, const  boost::python::list& dataArray);
    unsigned int            majorVersion() const;
    void                    setMajorVersion(unsigned int majorVersion);
    unsigned int            minorVersion() const;
    void                    setMinorVersion(unsigned int minorVersion);
    std::string             sheetSetName() const;
    void                    setSheetSetName(const std::string& pSheetSetName);
    unsigned int            noOfCopies() const;
    void                    setNoOfCopies(unsigned int copies);
    void                    setIsSheetSet(bool bSheetSet);
    bool                    isSheetSet() const;
    bool                    isHomogeneous() const;
    void                    setIsHomogeneous(bool bHomogeneous);
    bool                    plotStampOn() const;
    void                    setPlotStampOn(bool bOn);
    bool                    viewFile() const;
    void                    setViewFile(bool bViewFile);
    std::string             selectionSetName() const;
    void                    setSelectionSetName(const std::string& pSelSetName);
    std::string             categoryName() const;
    void                    setCategoryName(const std::string& pCategoryName);
    std::string             logFilePath() const;
    void                    setLogFilePath(const std::string& pLogFilePath);
    boost::python::tuple    get3dDwfOptions() const;
    void                    set3dDwfOptions(bool  bGroupByXrefHierarchy, bool  bPublishWithMaterials);
    bool                    includeLayerInfo() const;
    void                    setIncludeLayerInfo(bool bOn);
    bool                    lineMerge() const;
    void                    setLineMerge(bool bOn);
    std::string             currentPrecision() const;
    void                    setCurrentPrecision(const std::string& pCurrentPrecision);
    bool                    promptForDwfName() const;
    void                    setPromptForDwfName(bool bPromptForDwfName);
    bool                    pwdProtectPublishedDWF() const;
    void                    setPwdProtectPublishedDWF(bool bPwdProtectPublishedDWF);
    bool                    promptForPassword() const;
    void                    setPromptForPassword(bool bPromptForPassword);
    bool                    initializeLayouts() const;
    void                    setInitializeLayouts(bool initLayouts);
    static PyRxClass        desc();
    static std::string      className();
public:
    inline AcPlDSDData* impObj(const std::source_location& src = std::source_location::current()) const;
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
    void                    setDwgName(const std::string& pName);
    std::string             layout() const;
    void                    setLayout(std::string& pLayoutName);
    std::string             title() const;
    void                    setTitle(const std::string& pTitle);
    std::string             NPS() const;
    void                    setNPS(const std::string& pNPSName);
    std::string             NPSSourceDWG() const;
    void                    setNPSSourceDWG(const std::string& pNPWDWGName);
    bool                    has3dDwfSetup() const;
    void                    setHas3dDwfSetup(bool b3dDwfSetup);
    AcPlDSDEntry::SetupType setupType() const;
    void                    setSetupType(AcPlDSDEntry::SetupType eType);
    std::string             orgSheetPath() const;
    std::string             traceSession() const;
    void                    setTraceSession(const std::string& pTraceSession);
    static PyRxClass        desc();
    static std::string      className();
public:
    inline AcPlDSDEntry* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//PyPlPlotInfo
void makePyPlPlotInfoWrapper();
class PyPlPlotInfo : public PyPlObject
{
public:
    PyPlPlotInfo();
    PyPlPlotInfo(AcPlPlotInfo* ptr, bool autoDelete);
    PyPlPlotInfo(const AcPlPlotInfo& entry);
    virtual ~PyPlPlotInfo() override = default;

    void                    copyFrom(const PyRxObject& pOther);
    void                    setLayout(PyDbObjectId& layoutId);
    PyDbObjectId            layout() const;
    void                    setOverrideSettings(const PyDbPlotSettings& pOverrides);
    PyDbPlotSettings        overrideSettings() const;
    void                    setDeviceOverride(const PyPlPlotConfig& pconf);
    PyDbPlotSettings        validatedSettings() const;
    void                    setValidatedSettings(const PyDbPlotSettings& pValidatedSettings);
    PyPlPlotConfig          validatedConfig() const;
    void                    setValidatedConfig(const PyPlPlotConfig& pConfig);
    PyPlPlotConfig          deviceOverride() const;
    bool                    isCompatibleDocument(const PyPlPlotInfo& pOtherInfo) const;
    bool                    isValidated() const;
    unsigned long           mergeStatus() const;
    std::string             OrgFilePath();
    static PyRxClass        desc();
    static std::string      className();
public:
    inline AcPlPlotInfo* impObj(const std::source_location& src = std::source_location::current()) const;
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

    static PyRxClass        desc();
    static std::string      className();
public:
    inline AcPlPlotConfig*  impObj(const std::source_location& src = std::source_location::current()) const;
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

    static PyRxClass        desc();
    static std::string      className();
public:
    inline AcPlPlotPageInfo* impObj(const std::source_location& src = std::source_location::current()) const;
};
