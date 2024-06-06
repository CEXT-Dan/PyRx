#pragma once

#include "PyRxObject.h"

#pragma pack (push, 8)
class PyDbObjectId;
class PyDbDatabase;

//---------------------------------------------------------------------------------------- -
//PyDbDbLayerStateManager
void makePyDbDbLayerStateManagerWrapper();

class PyDbDbLayerStateManager : public PyRxObject
{
public:
    PyDbDbLayerStateManager();
    PyDbDbLayerStateManager(const PyDbDatabase& db);
    PyDbDbLayerStateManager(AcDbLayerStateManager* ptr, bool autoDelete);
    virtual ~PyDbDbLayerStateManager() override = default;
    //bool              addReactor(AcDbLayerStateManagerReactor* pReactor);
    //bool              removeReactor(AcDbLayerStateManagerReactor* pReactor);

    PyDbObjectId        layerStatesDictionaryId1();
    PyDbObjectId        layerStatesDictionaryId2(bool bCreateIfNotPresent);
    bool                hasLayerState(const std::string& sName);
    void                saveLayerState1(const std::string& sName, AcDbLayerStateManager::LayerStateMask mask);
    void                saveLayerState2(const std::string& sName, AcDbLayerStateManager::LayerStateMask mask, const PyDbObjectId& idVp);
    void                restoreLayerState1(const std::string& sName);
    void                restoreLayerState2(const std::string& sName, const PyDbObjectId& idVp, int nRestoreFlags, AcDbLayerStateManager::LayerStateMask pClientMask);

    void                setLayerStateMask(const std::string& sName, AcDbLayerStateManager::LayerStateMask mask);
    AcDbLayerStateManager::LayerStateMask getLayerStateMask(const std::string& sName);

    void                deleteLayerState(const std::string& sName);
    void                renameLayerState(const std::string& sName, const std::string& sNewName);
    std::string         importLayerState(const std::string& sFilename);
    void                exportLayerState(const std::string& sNameToExport, const std::string& sFilename);

    void                setLayerStateDescription(const std::string& sName, const std::string& sDesc);
    std::string         getLayerStateDescription(const std::string& sName);

    bool                layerStateHasViewportData(const std::string& sName);
    void                importLayerStateFromDb(const std::string& pStateName, PyDbDatabase& pDb);

    boost::python::list  getLayerStateNames(bool bIncludeHidden, bool bIncludeXref);

    boost::python::tuple getLastRestoredLayerState();
    boost::python::list  getLayerStateLayers(const std::string& sName, bool bInvert);

    bool                compareLayerStateToDb(const std::string& sName, const PyDbObjectId& idVp);
    void                addLayerStateLayers(const std::string& sName, const boost::python::list& layerIds);
    void                removeLayerStateLayers(const std::string& sName, const boost::python::list& layerNames);

    bool                isDependentLayerState(const std::string& sName);
    PyDbDatabase        getDatabase() const;

    static PyRxClass    desc();
    static std::string  className();
public:
    AcDbLayerStateManager* impObj(const std::source_location& src = std::source_location::current()) const;
};

#pragma pack (pop)
