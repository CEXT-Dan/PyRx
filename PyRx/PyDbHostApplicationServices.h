#pragma once
#include "PyRxObject.h"

class PyDbObjectId;
class PyDbDatabase;
class PyDbLayoutManager;
class PyDbPlotSettings;
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
    std::string product() const;
    PyDbLayoutManager dbLayoutManager();

protected:
    AcDbHostApplicationServices* pDbHostApp = acdbHostApplicationServices();
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
    std::string         getTitle() const;
    void                setTitle(const std::string& title);
    std::string         getSubject() const;
    void                setSubject(const std::string& subject);
    std::string         getAuthor() const;
    void                setAuthor(const std::string& author);
    std::string         getKeywords() const;
    void                setKeywords(const std::string& keywordlist);
    std::string         getComments() const;
    void                setComments(const std::string& comments);
    std::string         getLastSavedBy() const;
    void                setLastSavedBy(const std::string& lastSavedBy);
    std::string         getRevisionNumber() const;
    void                setRevisionNumber(const std::string& revisionNumber);
    std::string         getHyperlinkBase() const;
    void                setHyperlinkBase(const std::string& HyperlinkBase);
    int                 numCustomInfo() const;
    void                addCustomSummaryInfo(const std::string& key, const std::string& value);
    void                deleteCustomSummaryInfo1(int index);
    void                deleteCustomSummaryInfo2(const std::string& key);
    boost::python::tuple getCustomSummaryInfo1(const std::string& customInfoKey) const;
    boost::python::tuple getCustomSummaryInfo2(int index) const;
    void                setCustomSummaryInfo1(const std::string& customInfoKey, const std::string& value);
    void                setCustomSummaryInfo2(int index, const std::string& key, const std::string& value);
    void                setCustomSummaryFromDict(boost::python::dict& pydict);
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
    ~PyDbPlotSettingsValidator() = default;

    void                setPlotCfgName1(PyDbPlotSettings& settings, const std::string& plotDeviceName);
    void                setPlotCfgName2(PyDbPlotSettings& settings, const std::string& plotDeviceName, const std::string& mediaName);
    void                setCanonicalMediaName(PyDbPlotSettings& settings, const std::string& mediaName);
    void                setPlotOrigin(PyDbPlotSettings& settings, const double xCoordinate, const double yCoordinate);
    void                setPlotPaperUnits(PyDbPlotSettings& pPlotSet, const PlotPaperUnits units);
    void                setPlotRotation(PyDbPlotSettings& pPlotSet, const PlotRotation rotationType);
    void                setPlotCentered(PyDbPlotSettings& pPlotSet, Adesk::Boolean isCentered);
    void                setPlotType(PyDbPlotSettings& pPlotSet, const PlotType plotAreaType);
    void                setPlotWindowArea1(PyDbPlotSettings& pPlotSet, const double xmin, const double ymin, const double xmax, const double ymax);
    void                setPlotWindowArea2(PyDbPlotSettings& pPlotSet, AcDbExtents2d& ex);
    void                setPlotViewName(PyDbPlotSettings& pPlotSet, const std::string& viewName);
    void                setUseStandardScale(PyDbPlotSettings& pPlotSet, Adesk::Boolean useStandard);
    void                setCustomPrintScale(PyDbPlotSettings& pPlotSet, const double numerator, const double denominator);
    void                setCurrentStyleSheet(PyDbPlotSettings& pPlotSet, const std::string& styleSheetName);
    void                setStdScaleType(PyDbPlotSettings& pPlotSet, const StdScaleType scaleType);
    void                setStdScale(PyDbPlotSettings& pPlotSet, const double standardScale);
    boost::python::list plotDeviceList();
    boost::python::list canonicalMediaNameList(PyDbPlotSettings& pPlotSet);
    std::string         getLocaleMediaName1(PyDbPlotSettings& pPlotSet, const std::string& canonicalName);
    std::string         getLocaleMediaName2(PyDbPlotSettings& pPlotSet,int index);
    void                setClosestMediaName(PyDbPlotSettings& pPlotSet, double paperWidth, double paperHeight, PlotPaperUnits units, Adesk::Boolean matchPrintableArea);
    boost::python::list plotStyleSheetList();
    void                refreshLists(PyDbPlotSettings& pPlotSet);
    void                setZoomToPaperOnUpdate(PyDbPlotSettings& pPlotSet,Adesk::Boolean doZoom);
    void                setDefaultPlotConfig(PyDbPlotSettings& pPlotSet);
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
    static std::string dictionaryNameAt1(const PyDbObjectId& itemId);
    static std::string dictionaryNameAt2(const PyDbObjectId& itemId, const PyDbObjectId& ownerDictId);
    static PyDbObjectId dictionaryGetAt(const std::string& name, const PyDbObjectId& ownerDictId);
    static std::string getColorName(const PyDbObjectId& itemId);
};