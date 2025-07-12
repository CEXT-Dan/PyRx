#pragma once
#include "PyRxObject.h"

#pragma pack (push, 8)
class PyDbObjectId;
class PyDbDatabase;
class PyDbLayoutManager;
class PyDbPlotSettings;
class PyDbPlotSettingsValidator;
class AcadInternalServices;

//---------------------------------------------------------------------------------------- -
//OutputDisplayServiceImpl
class OutputDisplayServiceImpl : public AcDbHostApplicationServices
{
public:
    OutputDisplayServiceImpl();
    virtual ~OutputDisplayServiceImpl() override;
    virtual Acad::ErrorStatus findFile(ACHAR* pthOut,int nBufLength,const ACHAR* pcFname,AcDbDatabase* pDb = NULL,AcDbHostApplicationServices::FindFileHint hint = kDefault) override;
#if !defined(_BRXTARGET260)
    virtual AcadInternalServices* acadInternalServices() override;
#endif
    virtual const ProdIdCode prodcode() override;
    virtual void displayChar(ACHAR c) const override;
    virtual void displayString(const ACHAR* string, int count) const override;
    std::wstring getOutput() const;
    bool getMuteCmdLine() const { return m_muteCmdLine; }
    void setMuteCmdLine(bool val) { m_muteCmdLine = val; }
private:
    inline static std::wstring ms_buffer;
    AcDbHostApplicationServices* m_pOldHostServices = acdbHostApplicationServices();
    bool m_muteCmdLine = true;
};

//---------------------------------------------------------------------------------------- -
//PyOutputDisplayService
void makePyOutputDisplayServiceWrapper();
class PyOutputDisplayService
{
public:
    PyOutputDisplayService();
    ~PyOutputDisplayService() = default;
    std::string         output() const;
    bool                getMuteCmdLine() const;
    void                setMuteCmdLine(bool val) const;
    static std::string  className();
public:
    OutputDisplayServiceImpl* impObj(const std::source_location& src = std::source_location::current()) const;
private:
    std::shared_ptr<OutputDisplayServiceImpl> m_pyImp;
};


//---------------------------------------------------------------------------------------- -
//PyDbHostApplicationServices
void makePyDbHostApplicationServicesWrapper();

class PyDbHostApplicationServices
{
public:
    PyDbDatabase workingDatabase() const;
    void setWorkingDatabase(PyDbDatabase& pDatabase);
    std::string findFile1(const std::string& fileName);
    std::string findFile2(const std::string& fileName, const PyDbDatabase& db);
    std::string findFile3(const std::string& fileName, const PyDbDatabase& db, AcDbHostApplicationServices::FindFileHint hint);

    std::string getRoamableRootFolder();
    std::string getLocalRootFolder();
    std::string getAllUsersRootFolder();

    int         releaseMajorVersion();
    int         releaseMinorVersion();

    std::string product() const;
    std::string program();
    std::string companyName();

    std::string releaseMajorMinorString();
    std::string versionString();
    std::string getMachineRegistryProductRootKey();
    std::string getUserRegistryProductRootKey();
    std::string releaseMarketVersion();

    PyDbPlotSettingsValidator   plotSettingsValidator();
    PyDbLayoutManager           dbLayoutManager();
    static PyOutputDisplayService createOutputCapture();


protected:
    AcDbHostApplicationServices* pDbHostApp = acdbHostApplicationServices();
};

//---------------------------------------------------------------------------------------- -
//makePyAutoWorkingDatabase
void makePyAutoWorkingDatabase();

class PyAutoWorkingDatabase
{
public:
    explicit PyAutoWorkingDatabase(const PyDbDatabase& db);
    ~PyAutoWorkingDatabase() = default;
    PyDbDatabase  wdb();
public:
    std::shared_ptr<AutoWorkingDatabase> m_pyImp;
};


//---------------------------------------------------------------------------------------- -
//PyDbSymUtilServices
void makePyDbSymUtilServicesWrapper();

class PyDbSymUtilServices
{
public:
    bool isBlockLayoutName(const std::string& name) const;
    bool isBlockModelSpaceName(const std::string& name) const;
    bool isBlockPaperSpaceName(const std::string& name) const;;
    bool isLayerDefpointsName(const std::string& name) const;
    bool isLayerZeroName(const std::string& name) const;
    bool isLinetypeByBlockName(const std::string& name) const;
    bool isLinetypeByLayerName(const std::string& name) const;
    bool isLinetypeContinuousName(const std::string& name) const;
    bool isRegAppAcadName(const std::string& name) const;
    bool isTextStyleStandardName(const std::string& name) const;
    bool isViewportActiveName(const std::string& name) const;

    PyDbObjectId blockModelSpaceId(PyDbDatabase& pDb) const;
    PyDbObjectId blockPaperSpaceId(PyDbDatabase& pDb) const;
    PyDbObjectId layerDefpointsId(PyDbDatabase& pDb) const;
    PyDbObjectId layerZeroId(PyDbDatabase& pDb) const;
    PyDbObjectId linetypeByBlockId(PyDbDatabase& pDb) const;
    PyDbObjectId linetypeByLayerId(PyDbDatabase& pDb) const;
    PyDbObjectId linetypeContinuousId(PyDbDatabase& pDb) const;
    PyDbObjectId regAppAcadId(PyDbDatabase& pDb) const;
    PyDbObjectId textStyleStandardId(PyDbDatabase& pDb) const;

    std::string blockModelSpaceName() const;
    std::string blockPaperSpaceName() const;
    std::string layerDefpointsName() const;
    std::string layerZeroName() const;
    std::string linetypeByBlockName() const;
    std::string linetypeByLayerName() const;
    std::string linetypeContinuousName() const;
    std::string regAppAcadName() const;
    std::string textStyleStandardName() const;
    std::string viewportActiveName() const;

    int                 compareSymbolName(const std::string& thisName, const std::string& otherName) const;
    bool                hasVerticalBar(const std::string& name) const;
    std::string         makeDependentName(const std::string& dwgName, const std::string& symbolName) const;
    std::string         repairPreExtendedSymbolName(const std::string& oldName, bool allowVerticalBar) const;
    std::string         repairSymbolName(const std::string& oldName, bool allowVerticalBar) const;
    Acad::ErrorStatus   validatePreExtendedSymbolName(const std::string& name, bool allowVerticalBar) const;
    Acad::ErrorStatus   validateSymbolName(const std::string& name, bool allowVerticalBar) const;
    bool                compatibilityMode(PyDbDatabase& pDb) const;
    std::string         getBlockNameFromInsertPathName(const std::string& pathName) const;
    std::string         getInsertPathNameFromBlockName(const std::string& pathName) const;
    std::string         getPathNameFromSymbolName(const std::string& symbolName, const std::string& extensions) const;
    std::string         getSymbolNameFromPathName(const std::string& symbolName, const std::string& extensions) const;
    Acad::ErrorStatus   validateCompatibleSymbolName(const std::string& name, bool isNewName, bool allowVerticalBar, bool compatibilityMode) const;

public:
    const AcDbSymUtilServices* imp = acdbSymUtil();
};

//---------------------------------------------------------------------------------------- -
//PyDbDatabaseSummaryInfo
void makePyDbDatabaseSummaryInfoWrapper();

class PyDbDatabaseSummaryInfo : public PyRxObject
{
public:
    PyDbDatabaseSummaryInfo(AcDbDatabaseSummaryInfo* ptr);
    virtual ~PyDbDatabaseSummaryInfo() override = default;
    std::string         getTitle() const;
    void                setTitle(const std::string& title) const;
    std::string         getSubject() const;
    void                setSubject(const std::string& subject) const;
    std::string         getAuthor() const;
    void                setAuthor(const std::string& author) const;
    std::string         getKeywords() const;
    void                setKeywords(const std::string& keywordlist) const;
    std::string         getComments() const;
    void                setComments(const std::string& comments) const;
    std::string         getLastSavedBy() const;
    void                setLastSavedBy(const std::string& lastSavedBy) const;
    std::string         getRevisionNumber() const;
    void                setRevisionNumber(const std::string& revisionNumber) const;
    std::string         getHyperlinkBase() const;
    void                setHyperlinkBase(const std::string& HyperlinkBase) const;
    int                 numCustomInfo() const;
    void                addCustomSummaryInfo(const std::string& key, const std::string& value) const;
    void                deleteCustomSummaryInfo1(int index) const;
    void                deleteCustomSummaryInfo2(const std::string& key) const;
    boost::python::tuple getCustomSummaryInfo1(const std::string& customInfoKey) const;
    boost::python::tuple getCustomSummaryInfo2(int index) const;
    void                setCustomSummaryInfo1(const std::string& customInfoKey, const std::string& value) const;
    void                setCustomSummaryInfo2(int index, const std::string& key, const std::string& value) const;
    void                setCustomSummaryFromDict(boost::python::dict& pydict) const;
    boost::python::dict asDict() const;
    static std::string  className();
public:
    AcDbDatabaseSummaryInfo* impObj(const std::source_location& src = std::source_location::current()) const;
};

//---------------------------------------------------------------------------------------- -
//PyDbPlotSettingsValidator
void makePyDbPlotSettingsValidatorWrapper();
class PyDbPlotSettingsValidator
{
public:
    PyDbPlotSettingsValidator() = default;
    PyDbPlotSettingsValidator(AcDbPlotSettingsValidator* ptr);

    ~PyDbPlotSettingsValidator() = default;
    void                setPlotCfgName1(PyDbPlotSettings& settings, const std::string& plotDeviceName) const;
    void                setPlotCfgName2(PyDbPlotSettings& settings, const std::string& plotDeviceName, const std::string& mediaName) const;
    void                setCanonicalMediaName(PyDbPlotSettings& settings, const std::string& mediaName) const;
    void                setPlotOrigin(PyDbPlotSettings& settings, const double xCoordinate, const double yCoordinate) const;
    void                setPlotPaperUnits(PyDbPlotSettings& pPlotSet, const PlotPaperUnits units) const;
    void                setPlotRotation(PyDbPlotSettings& pPlotSet, const PlotRotation rotationType) const;
    void                setPlotCentered(PyDbPlotSettings& pPlotSet, Adesk::Boolean isCentered) const;
    void                setPlotType(PyDbPlotSettings& pPlotSet, const PlotType plotAreaType) const;
    void                setPlotWindowArea1(PyDbPlotSettings& pPlotSet, const double xmin, const double ymin, const double xmax, const double ymax) const;
    void                setPlotWindowArea2(PyDbPlotSettings& pPlotSet, AcDbExtents2d& ex) const;
    void                setPlotViewName(PyDbPlotSettings& pPlotSet, const std::string& viewName) const;
    void                setUseStandardScale(PyDbPlotSettings& pPlotSet, Adesk::Boolean useStandard) const;
    void                setCustomPrintScale(PyDbPlotSettings& pPlotSet, const double numerator, const double denominator) const;
    void                setCurrentStyleSheet(PyDbPlotSettings& pPlotSet, const std::string& styleSheetName) const;
    void                setStdScaleType(PyDbPlotSettings& pPlotSet, const StdScaleType scaleType) const;
    void                setStdScale(PyDbPlotSettings& pPlotSet, const double standardScale) const;
    boost::python::list plotDeviceList() const;
    boost::python::list canonicalMediaNameList(PyDbPlotSettings& pPlotSet) const;
    std::string         getLocaleMediaName1(PyDbPlotSettings& pPlotSet, const std::string& canonicalName) const;
    std::string         getLocaleMediaName2(PyDbPlotSettings& pPlotSet, int index) const;
    void                setClosestMediaName(PyDbPlotSettings& pPlotSet, double paperWidth, double paperHeight, PlotPaperUnits units, Adesk::Boolean matchPrintableArea) const;
    boost::python::list plotStyleSheetList() const;
    void                refreshLists(PyDbPlotSettings& pPlotSet) const;
    void                setZoomToPaperOnUpdate(PyDbPlotSettings& pPlotSet, Adesk::Boolean doZoom) const;
    void                setDefaultPlotConfig(PyDbPlotSettings& pPlotSet) const;
    static std::string  className();
public:
    AcDbPlotSettingsValidator* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    AcDbPlotSettingsValidator* m_impl = acdbHostApplicationServices()->plotSettingsValidator();
};

//---------------------------------------------------------------------------------------- -
//PyDbDictUtil
void makePyDbDictUtilWrapper();
class PyDbDictUtil
{
public:
    static std::string  dictionaryNameAt1(const PyDbObjectId& itemId);
    static std::string  dictionaryNameAt2(const PyDbObjectId& itemId, const PyDbObjectId& ownerDictId);
    static PyDbObjectId dictionaryGetAt(const std::string& name, const PyDbObjectId& ownerDictId);
    static std::string  getColorName(const PyDbObjectId& itemId);
    static PyDbObjectId getGroupId(const std::string& name, const PyDbDatabase& db);
    static std::string  getGroupName(const PyDbObjectId& itemId);
    static PyDbObjectId getLayoutId(const std::string& name, const PyDbDatabase& db);
    static std::string  getLayoutName(const PyDbObjectId& itemId);
    static PyDbObjectId getMaterialId(const std::string& name, const PyDbDatabase& db);
    static std::string  getMaterialName(const PyDbObjectId& itemId);
    static PyDbObjectId getMLStyleId(const std::string& name, const PyDbDatabase& db);
    static std::string  getMLStyleName(const PyDbObjectId& itemId);
    static PyDbObjectId getPlotSettingsId(const std::string& name, const PyDbDatabase& db);
    static std::string  getPlotSettingsName(const PyDbObjectId& itemId);
    static PyDbObjectId getPlotStyleNameId(const std::string& name, const PyDbDatabase& db);
    static std::string  getPlotStyleNameName(const PyDbObjectId& itemId);
    static PyDbObjectId getTableStyleId(const std::string& name, const PyDbDatabase& db);
    static std::string  getTableStyleName(const PyDbObjectId& itemId);
    static PyDbObjectId getVisualStyleId(const std::string& name, const PyDbDatabase& db);
    static std::string  getVisualStyleName(const PyDbObjectId& itemId);
    static bool         hasColor(const std::string& name, const PyDbDatabase& db);
    static bool         hasGroup(const std::string& name, const PyDbDatabase& db);
    static bool         hasLayout(const std::string& name, const PyDbDatabase& db);
    static bool         hasMaterial(const std::string& name, const PyDbDatabase& db);
    static bool         hasMLStyle(const std::string& name, const PyDbDatabase& db);
    static bool         hasPlotSettings(const std::string& name, const PyDbDatabase& db);
    static bool         hasPlotStyleName(const std::string& name, const PyDbDatabase& db);
    static bool         hasTableStyle(const std::string& name, const PyDbDatabase& db);
    static bool         hasVisualStyle(const std::string& name, const PyDbDatabase& db);
};
#pragma pack (pop)