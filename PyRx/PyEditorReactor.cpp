#include "stdafx.h"
#include "PyEditorReactor.h"
#include "PyDbDatabase.h"
#include "PyDbIdMapping.h"
#include "PyDbObjectId.h"

using namespace boost::python;
//-----------------------------------------------------------------------------------------
//PyEditorReactor
void makePyEditorReactorWrapper()
{
    class_<PyEditorReactor, boost::noncopyable>("EditorReactor")
        .def("addReactor", &PyEditorReactor::addReactor)
        .def("removeReactor", &PyEditorReactor::removeReactor)
        .def("veto", &PyEditorReactor::pyveto)
        .def("commandWillStart", &PyEditorReactor::commandWillStartWr)
        .def("commandEnded", &PyEditorReactor::commandEndedWr)
        .def("commandCancelled", &PyEditorReactor::commandCancelledWr)
        .def("commandFailed", &PyEditorReactor::commandFailedWr)
        .def("lispWillStart", &PyEditorReactor::lispWillStartWr)
        .def("lispEnded", &PyEditorReactor::lispEndedWr)
        .def("lispCancelled", &PyEditorReactor::lispCancelledWr)
        .def("beginDxfIn", &PyEditorReactor::beginDxfInWr)
        .def("abortDxfIn", &PyEditorReactor::abortDxfInWr)
        .def("dxfInComplete", &PyEditorReactor::dxfInCompleteWr)
        .def("beginDxfOut", &PyEditorReactor::beginDxfOutWr)
        .def("abortDxfOut", &PyEditorReactor::abortDxfOutWr)
        .def("dxfOutComplete", &PyEditorReactor::dxfOutCompleteWr)
        .def("beginDwgOpen", &PyEditorReactor::beginDwgOpenWr)
        .def("endDwgOpen", &PyEditorReactor::endDwgOpenWr)
        .def("initialDwgFileOpenComplete", &PyEditorReactor::initialDwgFileOpenCompleteWr)
        .def("databaseConstructed", &PyEditorReactor::databaseConstructedWr)
        .def("databaseToBeDestroyed", &PyEditorReactor::databaseToBeDestroyedWr)
        .def("beginSave", &PyEditorReactor::beginSaveWr)
        .def("saveComplete", &PyEditorReactor::saveCompleteWr)
        .def("abortSave", &PyEditorReactor::abortSaveWr)
        .def("beginInsert", &PyEditorReactor::beginInsertWr1)
        .def("beginInsert", &PyEditorReactor::beginInsertWr2)
        .def("otherInsert", &PyEditorReactor::otherInsertWr)
        .def("abortInsert", &PyEditorReactor::abortInsertWr)
        .def("endInsert", &PyEditorReactor::endInsertWr)
        .def("wblockNotice", &PyEditorReactor::wblockNoticeWr)
        .def("beginWblock", &PyEditorReactor::beginWblockWr)
        .def("otherWblock", &PyEditorReactor::otherWblockWr)
        .def("abortWblock", &PyEditorReactor::abortWblockWr)
        .def("endWblock", &PyEditorReactor::endWblockWr)
        .def("beginDeepClone", &PyEditorReactor::beginDeepCloneWr)
        .def("beginDeepCloneXlation", &PyEditorReactor::beginDeepCloneXlationWr)
        .def("abortDeepClone", &PyEditorReactor::abortDeepCloneWr)
        .def("endDeepClone", &PyEditorReactor::endDeepCloneWr)
        .def("sysVarChanged", &PyEditorReactor::sysVarChangedWr)
        .def("sysVarWillChange", &PyEditorReactor::sysVarWillChangeWr)
        .def("beginAttach", &PyEditorReactor::beginAttachWr)
        .def("otherAttach", &PyEditorReactor::otherAttachWr)
        .def("abortAttach", &PyEditorReactor::abortAttachWr)
        .def("endAttach", &PyEditorReactor::endAttachWr)
        .def("redirected", &PyEditorReactor::redirectedWr)
        .def("comandeered", &PyEditorReactor::comandeeredWr)
        .def("beginRestore", &PyEditorReactor::beginRestoreWr)
        .def("abortRestore", &PyEditorReactor::abortRestoreWr)
        .def("endRestore", &PyEditorReactor::endRestoreWr)
        .def("xrefSubcommandBindItem", &PyEditorReactor::xrefSubcommandBindItemWr)
        .def("xrefSubcommandAttachItem", &PyEditorReactor::xrefSubcommandAttachItemWr)
        .def("xrefSubcommandOverlayItem", &PyEditorReactor::xrefSubcommandOverlayItemWr)
        .def("xrefSubcommandDetachItem", &PyEditorReactor::xrefSubcommandDetachItemWr)
        .def("xrefSubcommandPathItem", &PyEditorReactor::xrefSubcommandPathItemWr)
        .def("xrefSubcommandReloadItem", &PyEditorReactor::xrefSubcommandReloadItemWr)
        .def("xrefSubcommandUnloadItem", &PyEditorReactor::xrefSubcommandUnloadItemWr)
        .def("undoSubcommandAuto", &PyEditorReactor::undoSubcommandAutoWr)
        .def("undoSubcommandControl", &PyEditorReactor::undoSubcommandControlWr)
        .def("undoSubcommandBegin", &PyEditorReactor::undoSubcommandBeginWr)
        .def("undoSubcommandEnd", &PyEditorReactor::undoSubcommandEndWr)
        .def("undoSubcommandMark", &PyEditorReactor::undoSubcommandMarkWr)
        .def("undoSubcommandBack", &PyEditorReactor::undoSubcommandBackWr)
        .def("undoSubcommandNumber", &PyEditorReactor::undoSubcommandNumberWr)
        .def("pickfirstModified", &PyEditorReactor::pickfirstModifiedWr)
        .def("layoutSwitched", &PyEditorReactor::layoutSwitchedWr)
        .def("layoutToBeSwitched", &PyEditorReactor::layoutToBeSwitchedWr)
        .def("dwgViewResized", &PyEditorReactor::dwgViewResizedWr)
        .def("fullRegenEnded", &PyEditorReactor::fullRegenEndedWr)
        .def("docFrameMovedOrResized", &PyEditorReactor::docFrameMovedOrResizedWr)
        .def("mainFrameMovedOrResized", &PyEditorReactor::mainFrameMovedOrResizedWr)
        .def("beginDoubleClick", &PyEditorReactor::beginDoubleClickWr)
        .def("beginRightClick", &PyEditorReactor::beginRightClickWr)
        .def("toolbarBitmapSizeWillChange", &PyEditorReactor::toolbarBitmapSizeWillChangeWr)
        .def("toolbarBitmapSizeChanged", &PyEditorReactor::toolbarBitmapSizeChangedWr)
        .def("beginWblockObjects", &PyEditorReactor::beginWblockObjectsWr)
        .def("partialOpenNotice", &PyEditorReactor::partialOpenNoticeWr)
        .def("objectsLazyLoaded", &PyEditorReactor::objectsLazyLoadedWr)
        .def("beginDocClose", &PyEditorReactor::beginDocCloseWr)
        .def("docCloseAborted", &PyEditorReactor::docCloseAbortedWr)
        .def("docCloseWillStart", &PyEditorReactor::docCloseWillStartWr)
        .def("beginCloseAll", &PyEditorReactor::beginCloseAllWr)
        .def("beginQuit", &PyEditorReactor::beginQuitWr)
        .def("quitAborted", &PyEditorReactor::quitAbortedWr)
        .def("quitWillStart", &PyEditorReactor::quitWillStartWr)
        .def("modelessOperationWillStart", &PyEditorReactor::modelessOperationWillStartWr)
        .def("modelessOperationEnded", &PyEditorReactor::modelessOperationEndedWr)
        .def("cmdIUnkModified", &PyEditorReactor::cmdIUnkModifiedWr)
        .def("preXrefLockFile", &PyEditorReactor::preXrefLockFileWr)
        .def("viewChanged", &PyEditorReactor::viewChangedWr)
        .def("fullRegenWillStart", &PyEditorReactor::fullRegenWillStartWr)
        ;
}

PyEditorReactor::PyEditorReactor()
{
}

PyEditorReactor::~PyEditorReactor()
{
    if (m_isActive)
        removeReactor();
}

void PyEditorReactor::addReactor()
{
    if (m_isActive)
    {
        acutPrintf(_T("\nReactor already rigistered"));
        return;
    }
    else
    {
        acedEditor->addReactor(this);
        m_isActive = true;
    }
}

void PyEditorReactor::removeReactor()
{
    if (m_isActive = true)
    {
        acedEditor->removeReactor(this);
        m_isActive = false;
    }
}

Acad::ErrorStatus PyEditorReactor::pyveto()
{
    return __super::veto();
}

void PyEditorReactor::commandWillStart(const ACHAR* cmdStr)
{
    commandWillStartWr(wstr_to_utf8(cmdStr));
}

void PyEditorReactor::commandEnded(const ACHAR* cmdStr)
{
    commandEndedWr(wstr_to_utf8(cmdStr));
}

void PyEditorReactor::commandCancelled(const ACHAR* cmdStr)
{
    commandCancelledWr(wstr_to_utf8(cmdStr));
}

void PyEditorReactor::commandFailed(const ACHAR* cmdStr)
{
    commandFailedWr(wstr_to_utf8(cmdStr));
}

void PyEditorReactor::lispWillStart(const ACHAR* firstLine)
{
    lispWillStartWr(wstr_to_utf8(firstLine));
}

void PyEditorReactor::lispEnded()
{
    lispEndedWr();
}

void PyEditorReactor::lispCancelled()
{
    lispCancelledWr();
}

void PyEditorReactor::beginDxfIn(AcDbDatabase* pDb)
{
    PyDbDatabase db(pDb);
    beginDxfInWr(db);
}

void PyEditorReactor::abortDxfIn(AcDbDatabase* pDb)
{
    PyDbDatabase db(pDb);
    abortDxfInWr(db);
}

void PyEditorReactor::dxfInComplete(AcDbDatabase* pDb)
{
    PyDbDatabase db(pDb);
    dxfInCompleteWr(db);
}

void PyEditorReactor::beginDxfOut(AcDbDatabase* pDb)
{
    PyDbDatabase db(pDb);
    beginDxfOutWr(db);
}

void PyEditorReactor::abortDxfOut(AcDbDatabase* pDb)
{
    PyDbDatabase db(pDb);
    abortDxfOutWr(db);
}

void PyEditorReactor::dxfOutComplete(AcDbDatabase* pDb)
{
    PyDbDatabase db(pDb);
    dxfOutCompleteWr(db);
}

void PyEditorReactor::beginDwgOpen(const ACHAR* filename)
{
    beginDwgOpenWr(wstr_to_utf8(filename));
}

void PyEditorReactor::endDwgOpen(const ACHAR* filename, AcDbDatabase* pDb)
{
    PyDbDatabase db(pDb);
    endDwgOpenWr(wstr_to_utf8(filename), db);
}

void PyEditorReactor::initialDwgFileOpenComplete(AcDbDatabase* pDwg)
{
    PyDbDatabase db(pDwg);
    initialDwgFileOpenCompleteWr(db);
}

void PyEditorReactor::databaseConstructed(AcDbDatabase* pDb)
{
    PyDbDatabase db(pDb);
    databaseConstructedWr(db);
}

void PyEditorReactor::databaseToBeDestroyed(AcDbDatabase* pDb)
{
    PyDbDatabase db(pDb);
    databaseToBeDestroyedWr(db);
}

void PyEditorReactor::beginSave(AcDbDatabase* pDb, const ACHAR* pIntendedName)
{
    PyDbDatabase db(pDb);
    beginSaveWr(db, wstr_to_utf8(pIntendedName));
}

void PyEditorReactor::saveComplete(AcDbDatabase* pDb, const ACHAR* pActualName)
{
    PyDbDatabase db(pDb);
    saveCompleteWr(db, wstr_to_utf8(pActualName));
}

void PyEditorReactor::abortSave(AcDbDatabase* pDb)
{
    PyDbDatabase db(pDb);
    abortSaveWr(db);
}

void PyEditorReactor::beginInsert(AcDbDatabase* pTo, const ACHAR* pBlockName, AcDbDatabase* pFrom)
{
    PyDbDatabase to(pTo);
    PyDbDatabase from(pFrom);
    beginInsertWr1(to, wstr_to_utf8(pBlockName), from);
}

void PyEditorReactor::beginInsert(AcDbDatabase* pTo, const AcGeMatrix3d& xform, AcDbDatabase* pFrom)
{
    PyDbDatabase to(pTo);
    PyDbDatabase from(pFrom);
    beginInsertWr2(to, xform, from);
}

void PyEditorReactor::otherInsert(AcDbDatabase* pTo, AcDbIdMapping& idMap, AcDbDatabase* pFrom)
{
    PyDbDatabase to(pTo);
    PyDbDatabase from(pFrom);
    PyDbIdMapping maping(idMap);
    otherInsertWr(to, maping, from);
}

void PyEditorReactor::abortInsert(AcDbDatabase* pTo)
{
    PyDbDatabase to(pTo);
    abortInsertWr(to);
}

void PyEditorReactor::endInsert(AcDbDatabase* pTo)
{
    PyDbDatabase to(pTo);
    abortInsertWr(to);
}

void PyEditorReactor::wblockNotice(AcDbDatabase* pDb)
{
    PyDbDatabase db(pDb);
    wblockNoticeWr(db);
}

void PyEditorReactor::beginWblock(AcDbDatabase* pTo, AcDbDatabase* pFrom, AcDbObjectId blockId)
{
    PyDbDatabase to(pTo);
    PyDbDatabase from(pFrom);
    PyDbObjectId id(blockId);
    beginWblockWr(to, from, id);
}

void PyEditorReactor::otherWblock(AcDbDatabase* pTo, AcDbIdMapping& idMap, AcDbDatabase* pFrom)
{
    PyDbDatabase to(pTo);
    PyDbDatabase from(pFrom);
    PyDbIdMapping maping(idMap);
    otherWblockWr(to, maping, from);
}

void PyEditorReactor::abortWblock(AcDbDatabase* pTo)
{
    PyDbDatabase to(pTo);
    abortWblockWr(to);
}

void PyEditorReactor::endWblock(AcDbDatabase* pTo)
{
    PyDbDatabase to(pTo);
    endWblockWr(to);
}

void PyEditorReactor::beginDeepClone(AcDbDatabase* pTo, AcDbIdMapping& idMap)
{
    PyDbDatabase to(pTo);
    PyDbIdMapping mapping(idMap);
    beginDeepCloneWr(to, mapping);
}

void PyEditorReactor::beginDeepCloneXlation(AcDbIdMapping& idMap, Acad::ErrorStatus* es)
{
    PyDbIdMapping mapping(idMap);
    auto stat = beginDeepCloneXlationWr(mapping);
    if (es != nullptr)
        *es = stat;
}

void PyEditorReactor::abortDeepClone(AcDbIdMapping& idMap)
{
    PyDbIdMapping mapping(idMap);
    abortDeepCloneWr(mapping);
}

void PyEditorReactor::endDeepClone(AcDbIdMapping& idMap)
{
    PyDbIdMapping mapping(idMap);
    endDeepCloneWr(mapping);
}

void PyEditorReactor::sysVarChanged(const ACHAR* varName, bool success)
{
    sysVarChangedWr(wstr_to_utf8(varName), success);
}

void PyEditorReactor::sysVarWillChange(const ACHAR* varName)
{
    sysVarWillChangeWr(wstr_to_utf8(varName));
}

void PyEditorReactor::beginAttach(AcDbDatabase* pTo, const ACHAR* name, AcDbDatabase* pFrom)
{
    PyDbDatabase to(pTo);
    PyDbDatabase from(pFrom);
    beginAttachWr(to, wstr_to_utf8(name), from);
}

void PyEditorReactor::otherAttach(AcDbDatabase* pTo, AcDbDatabase* pFrom)
{
    PyDbDatabase to(pTo);
    PyDbDatabase from(pFrom);
    otherAttachWr(to, from);
}

void PyEditorReactor::abortAttach(AcDbDatabase* pFrom)
{
    PyDbDatabase from(pFrom);
    abortAttachWr(from);
}

void PyEditorReactor::endAttach(AcDbDatabase* pTo)
{
    PyDbDatabase to(pTo);
    endAttachWr(to);
}

void PyEditorReactor::redirected(AcDbObjectId newId, AcDbObjectId oldId)
{
    PyDbObjectId nid(newId);
    PyDbObjectId oid(oldId);
    redirectedWr(nid, oid);
}

void PyEditorReactor::comandeered(AcDbDatabase* pTo, AcDbObjectId id, AcDbDatabase* pFrom)
{
    PyDbDatabase to(pTo);
    PyDbObjectId nid(id);
    PyDbDatabase from(pFrom);
    comandeeredWr(to, nid, from);
}

void PyEditorReactor::beginRestore(AcDbDatabase* pTo, const ACHAR* str, AcDbDatabase* pFrom)
{
    PyDbDatabase to(pTo);
    PyDbDatabase from(pFrom);
    beginRestoreWr(to, wstr_to_utf8(str), from);
}

void PyEditorReactor::abortRestore(AcDbDatabase* pTo)
{
    PyDbDatabase to(pTo);
    abortRestoreWr(to);
}

void PyEditorReactor::endRestore(AcDbDatabase* pTo)
{
    PyDbDatabase to(pTo);
    endRestoreWr(to);
}

void PyEditorReactor::xrefSubcommandBindItem(AcDbDatabase* pHost, int activity, AcDbObjectId blockId)
{
    PyDbDatabase host(pHost);
    PyDbObjectId id(blockId);
    xrefSubcommandBindItemWr(host, activity, id);
}

void PyEditorReactor::xrefSubcommandAttachItem(AcDbDatabase* pHost, int activity, const ACHAR* pPath)
{
    PyDbDatabase host(pHost);
    xrefSubcommandAttachItemWr(host, activity, wstr_to_utf8(pPath));
}

void PyEditorReactor::xrefSubcommandOverlayItem(AcDbDatabase* pHost, int activity, const ACHAR* pPath)
{
    PyDbDatabase host(pHost);
    xrefSubcommandOverlayItemWr(host, activity, wstr_to_utf8(pPath));
}

void PyEditorReactor::xrefSubcommandDetachItem(AcDbDatabase* pHost, int activity, AcDbObjectId blockId)
{
    PyDbDatabase host(pHost);
    PyDbObjectId id(blockId);
    xrefSubcommandDetachItemWr(host, activity, id);
}

void PyEditorReactor::xrefSubcommandPathItem(int activity, AcDbObjectId blockId, const ACHAR* pNewPath)
{
    PyDbObjectId id(blockId);
    xrefSubcommandPathItemWr(activity, id, wstr_to_utf8(pNewPath));
}

void PyEditorReactor::xrefSubcommandReloadItem(AcDbDatabase* pHost, int activity, AcDbObjectId blockId)
{
    PyDbDatabase host(pHost);
    PyDbObjectId id(blockId);
    xrefSubcommandReloadItemWr(host, activity, id);
}

void PyEditorReactor::xrefSubcommandUnloadItem(AcDbDatabase* pHost, int activity, AcDbObjectId blockId)
{
    PyDbDatabase host(pHost);
    PyDbObjectId id(blockId);
    xrefSubcommandUnloadItemWr(host, activity, id);
}

#ifndef BRXAPP
void PyEditorReactor::undoSubcommandAuto(int activity, bool state)
{
    undoSubcommandAutoWr(activity, state);
}
#endif
void PyEditorReactor::undoSubcommandControl(int activity, int option)
{
    undoSubcommandControlWr(activity, option);
}

void PyEditorReactor::undoSubcommandBegin(int activity)
{
    undoSubcommandBeginWr(activity);
}

void PyEditorReactor::undoSubcommandEnd(int activity)
{
    undoSubcommandEndWr(activity);
}

void PyEditorReactor::undoSubcommandMark(int activity)
{
    undoSubcommandMarkWr(activity);
}

void PyEditorReactor::undoSubcommandBack(int activity)
{
    undoSubcommandBackWr(activity);
}

void PyEditorReactor::undoSubcommandNumber(int activity, int num)
{
    undoSubcommandNumberWr(activity, num);
}

void PyEditorReactor::pickfirstModified()
{
    pickfirstModifiedWr();
}

void PyEditorReactor::layoutSwitched(const ACHAR* newLayoutName)
{
    layoutSwitchedWr(wstr_to_utf8(newLayoutName));
}

void PyEditorReactor::layoutToBeSwitched(const ACHAR* oldLayoutName, const ACHAR* newLayoutName)
{
    layoutToBeSwitchedWr(wstr_to_utf8(oldLayoutName), wstr_to_utf8(newLayoutName));
}

void PyEditorReactor::dwgViewResized(Adesk::LongPtr hwndDwgView)
{
    dwgViewResizedWr(hwndDwgView);
}

#ifndef BRXAPP
void PyEditorReactor::fullRegenEnded(AcDbDatabase* pDb, const AcDbIntArray& regenedViewports)
{
    boost::python::list _list;
    for (auto item : regenedViewports)
        _list.append(item);
    PyDbDatabase host(pDb);
    fullRegenEndedWr(host, _list);
}
#endif

void PyEditorReactor::docFrameMovedOrResized(Adesk::LongPtr hwndDocFrame, bool bMoved)
{
    docFrameMovedOrResizedWr(hwndDocFrame, bMoved);
}

void PyEditorReactor::mainFrameMovedOrResized(Adesk::LongPtr hwndMainFrame, bool bMoved)
{
    mainFrameMovedOrResizedWr(hwndMainFrame, bMoved);
}

void PyEditorReactor::beginDoubleClick(const AcGePoint3d& clickPoint)
{
    beginDoubleClickWr(clickPoint);
}

void PyEditorReactor::beginRightClick(const AcGePoint3d& clickPoint)
{
    beginRightClickWr(clickPoint);
}

#ifndef BRXAPP
void PyEditorReactor::toolbarBitmapSizeWillChange(bool bLarge)
{
    toolbarBitmapSizeWillChangeWr(bLarge);
}
#endif
#ifndef BRXAPP
void PyEditorReactor::toolbarBitmapSizeChanged(bool bLarge)
{
    toolbarBitmapSizeChangedWr(bLarge);
}
#endif
void PyEditorReactor::beginWblockObjects(AcDbDatabase* pFrom, AcDbIdMapping& idMap)
{
    PyDbDatabase from(pFrom);
    PyDbIdMapping mapping(idMap);
    beginWblockObjectsWr(from, mapping);
}

void PyEditorReactor::partialOpenNotice(AcDbDatabase* pDb)
{
    PyDbDatabase from(pDb);
    partialOpenNoticeWr(from);
}

void PyEditorReactor::objectsLazyLoaded(const AcDbObjectIdArray& idArray)
{
    boost::python::list _list;
    for (auto item : idArray)
        _list.append(PyDbObjectId(item));
    objectsLazyLoadedWr(_list);
}

void PyEditorReactor::beginDocClose(AcDbDatabase* pDwg)
{
    PyDbDatabase dwg(pDwg);
    beginDocCloseWr(dwg);
}

void PyEditorReactor::docCloseAborted(AcDbDatabase* pDwg)
{
    PyDbDatabase dwg(pDwg);
    docCloseAbortedWr(dwg);
}

void PyEditorReactor::docCloseWillStart(AcDbDatabase* pDwg)
{
    PyDbDatabase dwg(pDwg);
    docCloseWillStartWr(dwg);
}

#ifndef BRXAPP
void PyEditorReactor::beginCloseAll()
{
    beginCloseAllWr();
}
#endif
void PyEditorReactor::beginQuit()
{
    beginQuitWr();
}

void PyEditorReactor::quitAborted()
{
    quitAbortedWr();
}

void PyEditorReactor::quitWillStart()
{
    quitWillStartWr();
}

void PyEditorReactor::modelessOperationWillStart(const ACHAR* contextStr)
{
    modelessOperationWillStartWr(wstr_to_utf8(contextStr));
}

void PyEditorReactor::modelessOperationEnded(const ACHAR* contextStr)
{
    modelessOperationEndedWr(wstr_to_utf8(contextStr));
}

void PyEditorReactor::cmdIUnkModified(const ACHAR* strCommand)
{
    cmdIUnkModifiedWr(wstr_to_utf8(strCommand));
}

void PyEditorReactor::preXrefLockFile(AcDbObjectId btrId)
{
    PyDbObjectId id(btrId);
    preXrefLockFileWr(id);
}

void PyEditorReactor::viewChanged()
{
    viewChangedWr();
}
#ifndef BRXAPP
void PyEditorReactor::fullRegenWillStart(AcDbDatabase* pDb)
{
    PyDbDatabase dwg(pDb);
    fullRegenWillStartWr(dwg);
}
#endif

//begin wrapper
void PyEditorReactor::commandWillStartWr(const std::string& cmdStr)
{
    PyAutoLockGIL lock;
    if (override pyFunc = this->get_override("commandWillStart"))
        pyFunc(cmdStr);
}

void PyEditorReactor::commandEndedWr(const std::string& cmdStr)
{
    PyAutoLockGIL lock;
    if (override pyFunc = this->get_override("commandEnded"))
        pyFunc(cmdStr);
}

void PyEditorReactor::commandCancelledWr(const std::string& cmdStr)
{
    PyAutoLockGIL lock;
    if (override pyFunc = this->get_override("commandCancelled"))
        pyFunc(cmdStr);
}

void PyEditorReactor::commandFailedWr(const std::string& cmdStr)
{
    PyAutoLockGIL lock;
    if (override pyFunc = this->get_override("commandCancelled"))
        pyFunc(cmdStr);
}

void PyEditorReactor::lispWillStartWr(const std::string& firstLine)
{
    PyAutoLockGIL lock;
    if (override pyFunc = this->get_override("lispWillStart"))
        pyFunc(firstLine);
}

void PyEditorReactor::lispEndedWr()
{
    PyAutoLockGIL lock;
    if (override pyFunc = this->get_override("lispEnded"))
        pyFunc();
}

void PyEditorReactor::lispCancelledWr()
{
    PyAutoLockGIL lock;
    if (override pyFunc = this->get_override("lispCancelled"))
        pyFunc();
}

void PyEditorReactor::beginDxfInWr(PyDbDatabase& db)
{
    PyAutoLockGIL lock;
    if (override pyFunc = this->get_override("beginDxfIn"))
        pyFunc(db);
}

void PyEditorReactor::abortDxfInWr(PyDbDatabase& db)
{
    PyAutoLockGIL lock;
    if (override pyFunc = this->get_override("abortDxfIn"))
        pyFunc(db);
}

void PyEditorReactor::dxfInCompleteWr(PyDbDatabase& db)
{
    PyAutoLockGIL lock;
    if (override pyFunc = this->get_override("dxfInComplete"))
        pyFunc(db);
}

void PyEditorReactor::beginDxfOutWr(PyDbDatabase& db)
{
    PyAutoLockGIL lock;
    if (override pyFunc = this->get_override("beginDxfOut"))
        pyFunc(db);
}

void PyEditorReactor::abortDxfOutWr(PyDbDatabase& db)
{
    PyAutoLockGIL lock;
    if (override pyFunc = this->get_override("abortDxfOut"))
        pyFunc(db);
}

void PyEditorReactor::dxfOutCompleteWr(PyDbDatabase& db)
{
    PyAutoLockGIL lock;
    if (override pyFunc = this->get_override("dxfOutComplete"))
        pyFunc(db);
}

void PyEditorReactor::beginDwgOpenWr(const std::string& filename)
{
    PyAutoLockGIL lock;
    if (override pyFunc = this->get_override("beginDwgOpen"))
        pyFunc(filename);
}

void PyEditorReactor::endDwgOpenWr(const std::string& filename, PyDbDatabase& db)
{
    PyAutoLockGIL lock;
    if (override pyFunc = this->get_override("endDwgOpen"))
        pyFunc(filename, db);
}

void PyEditorReactor::initialDwgFileOpenCompleteWr(PyDbDatabase& db)
{
    PyAutoLockGIL lock;
    if (override pyFunc = this->get_override("initialDwgFileOpenComplete"))
        pyFunc(db);
}

void PyEditorReactor::databaseConstructedWr(PyDbDatabase& db)
{
    PyAutoLockGIL lock;
    if (override pyFunc = this->get_override("databaseConstructed"))
        pyFunc(db);
}

void PyEditorReactor::databaseToBeDestroyedWr(PyDbDatabase& db)
{
    PyAutoLockGIL lock;
    if (override pyFunc = this->get_override("databaseToBeDestroyed"))
        pyFunc(db);
}

void PyEditorReactor::beginSaveWr(PyDbDatabase& db, const std::string& pIntendedName)
{
    PyAutoLockGIL lock;
    if (override pyFunc = this->get_override("beginSave"))
        pyFunc(db, pIntendedName);
}

void PyEditorReactor::saveCompleteWr(PyDbDatabase& db, const std::string& pActualName)
{
    PyAutoLockGIL lock;
    if (override pyFunc = this->get_override("saveComplete"))
        pyFunc(db, pActualName);
}

void PyEditorReactor::abortSaveWr(PyDbDatabase& db)
{
    PyAutoLockGIL lock;
    if (override pyFunc = this->get_override("abortSave"))
        pyFunc(db);
}

void PyEditorReactor::beginInsertWr1(PyDbDatabase& pTo, const std::string& pBlockName, PyDbDatabase& pFrom)
{
    PyAutoLockGIL lock;
    if (override pyFunc = this->get_override("beginInsert"))
        pyFunc(pTo, pBlockName, pFrom);
}

void PyEditorReactor::beginInsertWr2(PyDbDatabase& pTo, const AcGeMatrix3d& xform, PyDbDatabase& pFrom)
{
    PyAutoLockGIL lock;
    if (override pyFunc = this->get_override("beginInsert"))
        pyFunc(pTo, xform, pFrom);
}

void PyEditorReactor::otherInsertWr(PyDbDatabase& pTo, PyDbIdMapping& idMap, PyDbDatabase& pFrom)
{
    PyAutoLockGIL lock;
    if (override pyFunc = this->get_override("otherInsert"))
        pyFunc(pTo, idMap, pFrom);
}

void PyEditorReactor::abortInsertWr(PyDbDatabase& pTo)
{
    PyAutoLockGIL lock;
    if (override pyFunc = this->get_override("abortInsert"))
        pyFunc(pTo);
}

void PyEditorReactor::endInsertWr(PyDbDatabase& pTo)
{
    PyAutoLockGIL lock;
    if (override pyFunc = this->get_override("endInsert"))
        pyFunc(pTo);
}

void PyEditorReactor::wblockNoticeWr(PyDbDatabase& pDb)
{
    if (override pyFunc = this->get_override("wblockNotice"))
        pyFunc(pDb);
}

void PyEditorReactor::beginWblockWr(PyDbDatabase& pTo, PyDbDatabase& pFrom, PyDbObjectId& blockId)
{
    PyAutoLockGIL lock;
    if (override pyFunc = this->get_override("beginWblock"))
        pyFunc(pTo, pFrom, blockId);
}

void PyEditorReactor::otherWblockWr(PyDbDatabase& pTo, PyDbIdMapping& mapping, PyDbDatabase& pFrom)
{
    PyAutoLockGIL lock;
    if (override pyFunc = this->get_override("otherWblock"))
        pyFunc(pTo, mapping, pFrom);
}

void PyEditorReactor::abortWblockWr(PyDbDatabase& pTo)
{
    PyAutoLockGIL lock;
    if (override pyFunc = this->get_override("abortWblock"))
        pyFunc(pTo);
}

void PyEditorReactor::endWblockWr(PyDbDatabase& pTo)
{
    PyAutoLockGIL lock;
    if (override pyFunc = this->get_override("endWblock"))
        pyFunc(pTo);
}

void PyEditorReactor::beginDeepCloneWr(PyDbDatabase& pTo, PyDbIdMapping& mapping)
{
    PyAutoLockGIL lock;
    if (override pyFunc = this->get_override("endWblock"))
        pyFunc(pTo, mapping);
}

Acad::ErrorStatus PyEditorReactor::beginDeepCloneXlationWr(PyDbIdMapping& mapping)
{
    PyAutoLockGIL lock;
    if (override pyFunc = this->get_override("beginDeepCloneXlation"))
        return pyFunc(mapping);
    return eInvalidInput;
}

void PyEditorReactor::abortDeepCloneWr(PyDbIdMapping& mapping)
{
    PyAutoLockGIL lock;
    if (override pyFunc = this->get_override("abortDeepClone"))
        pyFunc(mapping);
}

void PyEditorReactor::endDeepCloneWr(PyDbIdMapping& mapping)
{
    PyAutoLockGIL lock;
    if (override pyFunc = this->get_override("endDeepClone"))
        pyFunc(mapping);
}

void PyEditorReactor::sysVarChangedWr(const std::string& varName, bool success)
{
    PyAutoLockGIL lock;
    if (override pyFunc = this->get_override("sysVarChanged"))
        pyFunc(varName, success);
}

void PyEditorReactor::sysVarWillChangeWr(const std::string& varName)
{
    PyAutoLockGIL lock;
    if (override pyFunc = this->get_override("sysVarWillChange"))
        pyFunc(varName);
}

void PyEditorReactor::beginAttachWr(PyDbDatabase& pTo, const std::string& str, PyDbDatabase& pFrom)
{
    PyAutoLockGIL lock;
    if (override pyFunc = this->get_override("beginAttach"))
        pyFunc(pTo, str, pFrom);
}

void PyEditorReactor::otherAttachWr(PyDbDatabase& pTo, PyDbDatabase& pFrom)
{
    PyAutoLockGIL lock;
    if (override pyFunc = this->get_override("otherAttach"))
        pyFunc(pTo, pFrom);
}

void PyEditorReactor::abortAttachWr(PyDbDatabase& pFrom)
{
    PyAutoLockGIL lock;
    if (override pyFunc = this->get_override("abortAttach"))
        pyFunc(pFrom);
}

void PyEditorReactor::endAttachWr(PyDbDatabase& pTo)
{
    PyAutoLockGIL lock;
    if (override pyFunc = this->get_override("endAttach"))
        pyFunc(pTo);
}

void PyEditorReactor::redirectedWr(PyDbObjectId& newId, PyDbObjectId& oldId)
{
    PyAutoLockGIL lock;
    if (override pyFunc = this->get_override("redirected"))
        pyFunc(newId, oldId);
}

void PyEditorReactor::comandeeredWr(PyDbDatabase& pTo, PyDbObjectId& id, PyDbDatabase& pFrom)
{
    PyAutoLockGIL lock;
    if (override pyFunc = this->get_override("comandeered"))
        pyFunc(pTo, id, pFrom);
}

void PyEditorReactor::beginRestoreWr(PyDbDatabase& pTo, const std::string& str, PyDbDatabase& pFrom)
{
    PyAutoLockGIL lock;
    if (override pyFunc = this->get_override("beginRestore"))
        pyFunc(pTo, str, pFrom);
}

void PyEditorReactor::abortRestoreWr(PyDbDatabase& pTo)
{
    PyAutoLockGIL lock;
    if (override pyFunc = this->get_override("abortRestore"))
        pyFunc(pTo);
}

void PyEditorReactor::endRestoreWr(PyDbDatabase& pTo)
{
    PyAutoLockGIL lock;
    if (override pyFunc = this->get_override("endRestore"))
        pyFunc(pTo);
}

void PyEditorReactor::xrefSubcommandBindItemWr(PyDbDatabase& pHost, int activity, PyDbObjectId& blockId)
{
    PyAutoLockGIL lock;
    if (override pyFunc = this->get_override("xrefSubcommandBindItem"))
        pyFunc(pHost, activity, blockId);
}

void PyEditorReactor::xrefSubcommandAttachItemWr(PyDbDatabase& pHost, int activity, const std::string& pPath)
{
    PyAutoLockGIL lock;
    if (override pyFunc = this->get_override("xrefSubcommandAttachItem"))
        pyFunc(pHost, activity, pPath);
}

void PyEditorReactor::xrefSubcommandOverlayItemWr(PyDbDatabase& pHost, int activity, const std::string& pPath)
{
    PyAutoLockGIL lock;
    if (override pyFunc = this->get_override("xrefSubcommandOverlayItem"))
        pyFunc(pHost, activity, pPath);
}

void PyEditorReactor::xrefSubcommandDetachItemWr(PyDbDatabase& pHost, int activity, PyDbObjectId& blockId)
{
    PyAutoLockGIL lock;
    if (override pyFunc = this->get_override("xrefSubcommandDetachItem"))
        pyFunc(pHost, activity, blockId);
}

void PyEditorReactor::xrefSubcommandPathItemWr(int activity, PyDbObjectId& blockId, const std::string& pNewPath)
{
    PyAutoLockGIL lock;
    if (override pyFunc = this->get_override("xrefSubcommandPathItem"))
        pyFunc(activity, blockId, pNewPath);
}

void PyEditorReactor::xrefSubcommandReloadItemWr(PyDbDatabase& pHost, int activity, PyDbObjectId& blockId)
{
    PyAutoLockGIL lock;
    if (override pyFunc = this->get_override("xrefSubcommandReloadItem"))
        pyFunc(pHost, activity, blockId);
}

void PyEditorReactor::xrefSubcommandUnloadItemWr(PyDbDatabase& pHost, int activity, PyDbObjectId& blockId)
{
    PyAutoLockGIL lock;
    if (override pyFunc = this->get_override("xrefSubcommandUnloadItem"))
        pyFunc(pHost, activity, blockId);
}

void PyEditorReactor::undoSubcommandAutoWr(int activity, bool state)
{
    PyAutoLockGIL lock;
    if (override pyFunc = this->get_override("xrefSubcommandUnloadItem"))
        pyFunc(activity, state);
}

void PyEditorReactor::undoSubcommandControlWr(int activity, int option)
{
    PyAutoLockGIL lock;
    if (override pyFunc = this->get_override("xrefSubcommandUnloadItem"))
        pyFunc(activity, option);
}

void PyEditorReactor::undoSubcommandBeginWr(int activity)
{
    PyAutoLockGIL lock;
    if (override pyFunc = this->get_override("undoSubcommandBegin"))
        pyFunc(activity);
}

void PyEditorReactor::undoSubcommandEndWr(int activity)
{
    PyAutoLockGIL lock;
    if (override pyFunc = this->get_override("undoSubcommandEnd"))
        pyFunc(activity);
}

void PyEditorReactor::undoSubcommandMarkWr(int activity)
{
    PyAutoLockGIL lock;
    if (override pyFunc = this->get_override("undoSubcommandMark"))
        pyFunc(activity);
}

void PyEditorReactor::undoSubcommandBackWr(int activity)
{
    PyAutoLockGIL lock;
    if (override pyFunc = this->get_override("undoSubcommandBack"))
        pyFunc(activity);
}

void PyEditorReactor::undoSubcommandNumberWr(int activity, int num)
{
    PyAutoLockGIL lock;
    if (override pyFunc = this->get_override("undoSubcommandNumber"))
        pyFunc(activity, num);
}

void PyEditorReactor::pickfirstModifiedWr()
{
    PyAutoLockGIL lock;
    if (override pyFunc = this->get_override("pickfirstModified"))
        pyFunc();
}

void PyEditorReactor::layoutSwitchedWr(const std::string& newLayoutName)
{
    PyAutoLockGIL lock;
    if (override pyFunc = this->get_override("layoutSwitched"))
        pyFunc(newLayoutName);
}

void PyEditorReactor::layoutToBeSwitchedWr(const std::string& oldLayoutName, const std::string& newLayoutName)
{
    PyAutoLockGIL lock;
    if (override pyFunc = this->get_override("layoutToBeSwitched"))
        pyFunc(oldLayoutName, newLayoutName);
}

void PyEditorReactor::dwgViewResizedWr(Adesk::LongPtr hwndDwgView)
{
    PyAutoLockGIL lock;
    if (override pyFunc = this->get_override("dwgViewResized"))
        pyFunc(hwndDwgView);
}

void PyEditorReactor::fullRegenEndedWr(PyDbDatabase& pDb, const boost::python::list& regenedViewports)
{
    PyAutoLockGIL lock;
    if (override pyFunc = this->get_override("fullRegenEnded"))
        pyFunc(pDb, regenedViewports);
}

void PyEditorReactor::docFrameMovedOrResizedWr(Adesk::LongPtr hwndDocFrame, bool bMoved)
{
    PyAutoLockGIL lock;
    if (override pyFunc = this->get_override("docFrameMovedOrResized"))
        pyFunc(hwndDocFrame, bMoved);
}

void PyEditorReactor::mainFrameMovedOrResizedWr(Adesk::LongPtr hwndMainFrame, bool bMoved)
{
    PyAutoLockGIL lock;
    if (override pyFunc = this->get_override("mainFrameMovedOrResized"))
        pyFunc(hwndMainFrame, bMoved);
}

void PyEditorReactor::beginDoubleClickWr(const AcGePoint3d& clickPoint)
{
    PyAutoLockGIL lock;
    if (override pyFunc = this->get_override("beginDoubleClick"))
        pyFunc(clickPoint);
}

void PyEditorReactor::beginRightClickWr(const AcGePoint3d& clickPoint)
{
    PyAutoLockGIL lock;
    if (override pyFunc = this->get_override("beginRightClick"))
        pyFunc(clickPoint);
}

void PyEditorReactor::toolbarBitmapSizeWillChangeWr(bool bLarge)
{
    PyAutoLockGIL lock;
    if (override pyFunc = this->get_override("toolbarBitmapSizeWillChange"))
        pyFunc(bLarge);
}

void PyEditorReactor::toolbarBitmapSizeChangedWr(bool bLarge)
{
    PyAutoLockGIL lock;
    if (override pyFunc = this->get_override("toolbarBitmapSizeChanged"))
        pyFunc(bLarge);
}

void PyEditorReactor::beginWblockObjectsWr(PyDbDatabase& pFrom, PyDbIdMapping& mapping)
{
    PyAutoLockGIL lock;
    if (override pyFunc = this->get_override("toolbarBitmapSizeChanged"))
        pyFunc(pFrom, mapping);
}

void PyEditorReactor::partialOpenNoticeWr(PyDbDatabase& pDb)
{
    PyAutoLockGIL lock;
    if (override pyFunc = this->get_override("partialOpenNotice"))
        pyFunc(pDb);
}

void PyEditorReactor::objectsLazyLoadedWr(const boost::python::list& idArray)
{
    PyAutoLockGIL lock;
    if (override pyFunc = this->get_override("objectsLazyLoaded"))
        pyFunc(idArray);
}

void PyEditorReactor::beginDocCloseWr(PyDbDatabase& pDwg)
{
    PyAutoLockGIL lock;
    if (override pyFunc = this->get_override("beginDocClose"))
        pyFunc(pDwg);
}

void PyEditorReactor::docCloseAbortedWr(PyDbDatabase& pDwg)
{
    PyAutoLockGIL lock;
    if (override pyFunc = this->get_override("docCloseAborted"))
        pyFunc(pDwg);
}

void PyEditorReactor::docCloseWillStartWr(PyDbDatabase& pDwg)
{
    PyAutoLockGIL lock;
    if (override pyFunc = this->get_override("docCloseWillStart"))
        pyFunc(pDwg);
}

void PyEditorReactor::beginCloseAllWr()
{
    PyAutoLockGIL lock;
    if (override pyFunc = this->get_override("beginCloseAll"))
        pyFunc();
}

void PyEditorReactor::beginQuitWr()
{
    PyAutoLockGIL lock;
    if (override pyFunc = this->get_override("beginQuit"))
        pyFunc();
}

void PyEditorReactor::quitAbortedWr()
{
    PyAutoLockGIL lock;
    if (override pyFunc = this->get_override("quitAborted"))
        pyFunc();
}

void PyEditorReactor::quitWillStartWr()
{
    PyAutoLockGIL lock;
    if (override pyFunc = this->get_override("quitWillStart"))
        pyFunc();
}

void PyEditorReactor::modelessOperationWillStartWr(const std::string& contextStr)
{
    PyAutoLockGIL lock;
    if (override pyFunc = this->get_override("modelessOperationWillStart"))
        pyFunc(contextStr);
}

void PyEditorReactor::modelessOperationEndedWr(const std::string& contextStr)
{
    PyAutoLockGIL lock;
    if (override pyFunc = this->get_override("modelessOperationEnded"))
        pyFunc(contextStr);
}

void PyEditorReactor::cmdIUnkModifiedWr(const std::string& strCommand)
{
    PyAutoLockGIL lock;
    if (override pyFunc = this->get_override("cmdIUnkModified"))
        pyFunc(strCommand);
}

void PyEditorReactor::preXrefLockFileWr(PyDbObjectId& btrId)
{
    PyAutoLockGIL lock;
    if (override pyFunc = this->get_override("preXrefLockFile"))
        pyFunc(btrId);
}

void PyEditorReactor::viewChangedWr()
{
    PyAutoLockGIL lock;
    if (override pyFunc = this->get_override("viewChanged"))
        pyFunc();
}

void PyEditorReactor::fullRegenWillStartWr(PyDbDatabase& pDb)
{
    PyAutoLockGIL lock;
    if (override pyFunc = this->get_override("fullRegenWillStart"))
        pyFunc(pDb);
}

