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

    PyDbObjectId        layerStatesDictionaryId1() const;
    PyDbObjectId        layerStatesDictionaryId2(bool bCreateIfNotPresent) const;
    bool                hasLayerState(const std::string& sName) const;
    void                saveLayerState1(const std::string& sName, AcDbLayerStateManager::LayerStateMask mask) const;
    void                saveLayerState2(const std::string& sName, AcDbLayerStateManager::LayerStateMask mask, const PyDbObjectId& idVp) const;
    void                restoreLayerState1(const std::string& sName) const;
    void                restoreLayerState2(const std::string& sName, const PyDbObjectId& idVp, int nRestoreFlags, AcDbLayerStateManager::LayerStateMask pClientMask) const;

    void                setLayerStateMask(const std::string& sName, AcDbLayerStateManager::LayerStateMask mask) const;
    AcDbLayerStateManager::LayerStateMask getLayerStateMask(const std::string& sName) const;

    void                deleteLayerState(const std::string& sName) const;
    void                renameLayerState(const std::string& sName, const std::string& sNewName) const;
    std::string         importLayerState(const std::string& sFilename) const;
    void                exportLayerState(const std::string& sNameToExport, const std::string& sFilename) const;

    void                setLayerStateDescription(const std::string& sName, const std::string& sDesc) const;
    std::string         getLayerStateDescription(const std::string& sName) const;

    bool                layerStateHasViewportData(const std::string& sName) const;
    void                importLayerStateFromDb(const std::string& pStateName, PyDbDatabase& pDb) const;

    boost::python::list  getLayerStateNames(bool bIncludeHidden, bool bIncludeXref) const;

    boost::python::tuple getLastRestoredLayerState() const;
    boost::python::list  getLayerStateLayers(const std::string& sName, bool bInvert) const;

    bool                compareLayerStateToDb(const std::string& sName, const PyDbObjectId& idVp) const;
    void                addLayerStateLayers(const std::string& sName, const boost::python::list& layerIds) const;
    void                removeLayerStateLayers(const std::string& sName, const boost::python::list& layerNames) const;

    bool                isDependentLayerState(const std::string& sName) const;
    PyDbDatabase        getDatabase() const;

    static PyRxClass    desc();
    static std::string  className();
public:
    AcDbLayerStateManager* impObj(const std::source_location& src = std::source_location::current()) const;
};

#pragma pack (pop)
