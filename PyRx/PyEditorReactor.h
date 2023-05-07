#pragma once

class PyDbDatabase;
class PyDbIdMapping;
class PyDbObjectId;

//-----------------------------------------------------------------------------------------
//PyEditorReactor
void makePyEditorReactorWrapper();

class PyEditorReactor : public AcEditorReactor, public boost::python::wrapper<PyEditorReactor>
{
public:
    PyEditorReactor();
    ~PyEditorReactor() override;
    void addReactor();
    void removeReactor();
    Acad::ErrorStatus pyveto();
    //CAD
    virtual void commandWillStart(const ACHAR* cmdStr) override;
    virtual void commandEnded(const ACHAR* cmdStr)  override;
    virtual void commandCancelled(const ACHAR* cmdStr) override;
    virtual void commandFailed(const ACHAR* cmdStr)  override;
    virtual void lispWillStart(const ACHAR* firstLine) override;
    virtual void lispEnded() override;
    virtual void lispCancelled() override;
    virtual void beginDxfIn(AcDbDatabase* pDb) override;
    virtual void abortDxfIn(AcDbDatabase* pDb) override;
    virtual void dxfInComplete(AcDbDatabase* pDb) override;
    virtual void beginDxfOut(AcDbDatabase* pDb) override;
    virtual void abortDxfOut(AcDbDatabase* pDb) override;
    virtual void dxfOutComplete(AcDbDatabase* pDb) override;
    virtual void beginDwgOpen(const ACHAR* filename) override;
    virtual void endDwgOpen(const ACHAR* filename, AcDbDatabase* pDb) override;
    virtual void initialDwgFileOpenComplete(AcDbDatabase* pDwg) override;
    virtual void databaseConstructed(AcDbDatabase* pDb) override;
    virtual void databaseToBeDestroyed(AcDbDatabase* pDb) override;
    virtual void beginSave(AcDbDatabase* pDb, const ACHAR* pIntendedName) override;
    virtual void saveComplete(AcDbDatabase*, const ACHAR* pActualName) override;
    virtual void abortSave(AcDbDatabase*) override;
    virtual void beginInsert(AcDbDatabase* pTo, const ACHAR* pBlockName, AcDbDatabase* pFrom) override;
    virtual void beginInsert(AcDbDatabase* pTo, const AcGeMatrix3d& xform, AcDbDatabase* pFrom) override;
    virtual void otherInsert(AcDbDatabase* pTo, AcDbIdMapping& idMap, AcDbDatabase* pFrom) override;
    virtual void abortInsert(AcDbDatabase* pTo) override;
    virtual void endInsert(AcDbDatabase* pTo) override;
    virtual void wblockNotice(AcDbDatabase* pDb) override;
    virtual void beginWblock(AcDbDatabase* pTo, AcDbDatabase* pFrom, AcDbObjectId blockId) override;
    virtual void otherWblock(AcDbDatabase* pTo, AcDbIdMapping& mapping, AcDbDatabase* pFrom) override;
    virtual void abortWblock(AcDbDatabase* pTo) override;
    virtual void endWblock(AcDbDatabase* pTo) override;
    virtual void beginDeepClone(AcDbDatabase* pTo, AcDbIdMapping& mapping) override;
    virtual void beginDeepCloneXlation(AcDbIdMapping& mapping, Acad::ErrorStatus*) override;
    virtual void abortDeepClone(AcDbIdMapping& mapping) override;
    virtual void endDeepClone(AcDbIdMapping& mapping) override;
    virtual void sysVarChanged(const ACHAR* varName, bool success);
    virtual void sysVarWillChange(const ACHAR* varName);
    virtual void beginAttach(AcDbDatabase* pTo, const ACHAR*, AcDbDatabase* pFrom) override;
    virtual void otherAttach(AcDbDatabase* pTo, AcDbDatabase* pFrom) override;
    virtual void abortAttach(AcDbDatabase* pFrom) override;
    virtual void endAttach(AcDbDatabase* pTo) override;
    virtual void redirected(AcDbObjectId  newId, AcDbObjectId oldId) override;
    virtual void comandeered(AcDbDatabase* pTo, AcDbObjectId id, AcDbDatabase* pFrom) override;
    virtual void beginRestore(AcDbDatabase* pTo, const ACHAR*, AcDbDatabase* pFrom) override;
    virtual void abortRestore(AcDbDatabase* pTo) override;
    virtual void endRestore(AcDbDatabase* pTo) override;
    virtual void xrefSubcommandBindItem(AcDbDatabase* pHost, int activity, AcDbObjectId blockId) override;
    virtual void xrefSubcommandAttachItem(AcDbDatabase* pHost, int activity, const ACHAR* pPath) override;
    virtual void xrefSubcommandOverlayItem(AcDbDatabase* pHost, int activity, const ACHAR* pPath) override;
    virtual void xrefSubcommandDetachItem(AcDbDatabase* pHost, int activity, AcDbObjectId blockId) override;
    virtual void xrefSubcommandPathItem(int activity, AcDbObjectId blockId, const ACHAR* pNewPath) override;
    virtual void xrefSubcommandReloadItem(AcDbDatabase* pHost, int activity, AcDbObjectId blockId) override;
    virtual void xrefSubcommandUnloadItem(AcDbDatabase* pHost, int activity, AcDbObjectId blockId) override;
#ifndef BRXAPP
    virtual void undoSubcommandAuto(int activity, bool state) override;
#endif
    virtual void undoSubcommandControl(int activity, int option) override;
    virtual void undoSubcommandBegin(int activity)override;
    virtual void undoSubcommandEnd(int activity)override;
    virtual void undoSubcommandMark(int activity) override;
    virtual void undoSubcommandBack(int activity) override;
    virtual void undoSubcommandNumber(int activity, int num) override;
    virtual void pickfirstModified() override;
    virtual void layoutSwitched(const ACHAR* newLayoutName) override;
    virtual void layoutToBeSwitched(const ACHAR* oldLayoutName, const ACHAR* newLayoutName) override;
    virtual void dwgViewResized(Adesk::LongPtr hwndDwgView) override;
#ifndef BRXAPP
    virtual void fullRegenEnded(AcDbDatabase* pDb, const AcDbIntArray& regenedViewports)override;
#endif
    virtual void docFrameMovedOrResized(Adesk::LongPtr hwndDocFrame, bool bMoved) override;
    virtual void mainFrameMovedOrResized(Adesk::LongPtr hwndMainFrame, bool bMoved) override;
    virtual void beginDoubleClick(const AcGePoint3d& clickPoint) override;
    virtual void beginRightClick(const AcGePoint3d& clickPoint) override;
#ifndef BRXAPP
    virtual void toolbarBitmapSizeWillChange(bool bLarge) override;
#endif
#ifndef BRXAPP
    virtual void toolbarBitmapSizeChanged(bool bLarge) override;
#endif
    virtual void beginWblockObjects(AcDbDatabase* pFrom, AcDbIdMapping& mapping) override;
    virtual void partialOpenNotice(AcDbDatabase* pDb) override;
    virtual void objectsLazyLoaded(const AcDbObjectIdArray& idArray) override;
    virtual void beginDocClose(AcDbDatabase* pDwg) override;
    virtual void docCloseAborted(AcDbDatabase* pDwg) override;
    virtual void docCloseWillStart(AcDbDatabase* pDwg) override;
#ifndef BRXAPP
    virtual void beginCloseAll() override;
#endif
    virtual void beginQuit() override;
    virtual void quitAborted() override;
    virtual void quitWillStart() override;
    virtual void modelessOperationWillStart(const ACHAR* contextStr)override;
    virtual void modelessOperationEnded(const ACHAR* contextStr) override;
    virtual void cmdIUnkModified(const ACHAR* strCommand) override;
    virtual void preXrefLockFile(AcDbObjectId btrId) override;
    virtual void viewChanged() override;
#ifndef BRXAPP
    virtual void fullRegenWillStart(AcDbDatabase* pDb) override;
#endif

    //wrapper
    virtual void commandWillStartWr(const std::string& cmdStr);
    virtual void commandEndedWr(const std::string& cmdStr);
    virtual void commandCancelledWr(const std::string& cmdStr);
    virtual void commandFailedWr(const std::string& cmdStr);
    virtual void lispWillStartWr(const std::string& firstLine);
    virtual void lispEndedWr();
    virtual void lispCancelledWr();
    virtual void beginDxfInWr(PyDbDatabase& db);
    virtual void abortDxfInWr(PyDbDatabase& db);
    virtual void dxfInCompleteWr(PyDbDatabase& db);
    virtual void beginDxfOutWr(PyDbDatabase& db);
    virtual void abortDxfOutWr(PyDbDatabase& db);
    virtual void dxfOutCompleteWr(PyDbDatabase& db);
    virtual void beginDwgOpenWr(const std::string& filename);
    virtual void endDwgOpenWr(const std::string& filename, PyDbDatabase& db);
    virtual void initialDwgFileOpenCompleteWr(PyDbDatabase& db);
    virtual void databaseConstructedWr(PyDbDatabase& db);
    virtual void databaseToBeDestroyedWr(PyDbDatabase& db);
    virtual void beginSaveWr(PyDbDatabase& db, const std::string& pIntendedName);
    virtual void saveCompleteWr(PyDbDatabase& db, const std::string& pActualName);
    virtual void abortSaveWr(PyDbDatabase& db);
    virtual void beginInsertWr1(PyDbDatabase& pTo, const std::string& pBlockName, PyDbDatabase& pFrom);
    virtual void beginInsertWr2(PyDbDatabase& pTo, const AcGeMatrix3d& xform, PyDbDatabase& pFrom);
    virtual void otherInsertWr(PyDbDatabase& pTo, PyDbIdMapping& idMap, PyDbDatabase& pFrom);
    virtual void abortInsertWr(PyDbDatabase& pTo);
    virtual void endInsertWr(PyDbDatabase& pTo);
    virtual void wblockNoticeWr(PyDbDatabase& pDb);
    virtual void beginWblockWr(PyDbDatabase& pTo, PyDbDatabase& pFrom, PyDbObjectId& blockId);
    virtual void otherWblockWr(PyDbDatabase& pTo, PyDbIdMapping& mapping, PyDbDatabase& pFrom);
    virtual void abortWblockWr(PyDbDatabase& pTo);
    virtual void endWblockWr(PyDbDatabase& pTo);
    virtual void beginDeepCloneWr(PyDbDatabase& pTo, PyDbIdMapping& mapping);
    virtual Acad::ErrorStatus beginDeepCloneXlationWr(PyDbIdMapping& mapping);
    virtual void abortDeepCloneWr(PyDbIdMapping& mapping);
    virtual void endDeepCloneWr(PyDbIdMapping& mapping);
    virtual void sysVarChangedWr(const std::string& varName, bool success);
    virtual void sysVarWillChangeWr(const std::string& varName);
    virtual void beginAttachWr(PyDbDatabase& pTo, const std::string&, PyDbDatabase& pFrom);
    virtual void otherAttachWr(PyDbDatabase& pTo, PyDbDatabase& pFrom);
    virtual void abortAttachWr(PyDbDatabase& pFrom);
    virtual void endAttachWr(PyDbDatabase& pTo);
    virtual void redirectedWr(PyDbObjectId& newId, PyDbObjectId& oldId);
    virtual void comandeeredWr(PyDbDatabase& pTo, PyDbObjectId& id, PyDbDatabase& pFrom);
    virtual void beginRestoreWr(PyDbDatabase& pTo, const std::string&, PyDbDatabase& pFrom);
    virtual void abortRestoreWr(PyDbDatabase& pTo);
    virtual void endRestoreWr(PyDbDatabase& pTo);
    virtual void xrefSubcommandBindItemWr(PyDbDatabase& pHost, int activity, PyDbObjectId& blockId);
    virtual void xrefSubcommandAttachItemWr(PyDbDatabase& pHost, int activity, const std::string& pPath);
    virtual void xrefSubcommandOverlayItemWr(PyDbDatabase& pHost, int activity, const std::string& pPath);
    virtual void xrefSubcommandDetachItemWr(PyDbDatabase& pHost, int activity, PyDbObjectId& blockId);
    virtual void xrefSubcommandPathItemWr(int activity, PyDbObjectId& blockId, const std::string& pNewPath);
    virtual void xrefSubcommandReloadItemWr(PyDbDatabase& pHost, int activity, PyDbObjectId& blockId);
    virtual void xrefSubcommandUnloadItemWr(PyDbDatabase& pHost, int activity, PyDbObjectId& blockId);
    virtual void undoSubcommandAutoWr(int activity, bool state);
    virtual void undoSubcommandControlWr(int activity, int option);
    virtual void undoSubcommandBeginWr(int activity);
    virtual void undoSubcommandEndWr(int activity);
    virtual void undoSubcommandMarkWr(int activity);
    virtual void undoSubcommandBackWr(int activity);
    virtual void undoSubcommandNumberWr(int activity, int num);
    virtual void pickfirstModifiedWr();
    virtual void layoutSwitchedWr(const std::string& newLayoutName);
    virtual void layoutToBeSwitchedWr(const std::string& oldLayoutName, const std::string& newLayoutName);
    virtual void dwgViewResizedWr(Adesk::LongPtr hwndDwgView);
    virtual void fullRegenEndedWr(PyDbDatabase& pDb, const boost::python::list& regenedViewports);
    virtual void docFrameMovedOrResizedWr(Adesk::LongPtr hwndDocFrame, bool bMoved);
    virtual void mainFrameMovedOrResizedWr(Adesk::LongPtr hwndMainFrame, bool bMoved);
    virtual void beginDoubleClickWr(const AcGePoint3d& clickPoint);
    virtual void beginRightClickWr(const AcGePoint3d& clickPoint);
    virtual void toolbarBitmapSizeWillChangeWr(bool bLarge);
    virtual void toolbarBitmapSizeChangedWr(bool bLarge);
    virtual void beginWblockObjectsWr(PyDbDatabase& pFrom, PyDbIdMapping& mapping);
    virtual void partialOpenNoticeWr(PyDbDatabase& pDb);
    virtual void objectsLazyLoadedWr(const boost::python::list& idArray);
    virtual void beginDocCloseWr(PyDbDatabase& pDwg);
    virtual void docCloseAbortedWr(PyDbDatabase& pDwg);
    virtual void docCloseWillStartWr(PyDbDatabase& pDwg);
    virtual void beginCloseAllWr();
    virtual void beginQuitWr();
    virtual void quitAbortedWr();
    virtual void quitWillStartWr();
    virtual void modelessOperationWillStartWr(const std::string& contextStr);
    virtual void modelessOperationEndedWr(const std::string& contextStr);
    virtual void cmdIUnkModifiedWr(const std::string& strCommand);
    virtual void preXrefLockFileWr(PyDbObjectId& btrId);
    virtual void viewChangedWr();
    virtual void fullRegenWillStartWr(PyDbDatabase& pDb);

public:
    bool m_isActive = false;
};

