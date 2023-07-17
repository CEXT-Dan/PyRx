#pragma once

class PyDbObjectId;
class PyDbDatabase;
class PyDbLayoutManager;

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
    //bool            splitDependentName(size_t& numLeftBytes, const ACHAR*& pRight, const ACHAR* symbolName) const = 0;//TODO:
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
