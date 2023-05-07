#include "stdafx.h"
#include "PyEditorReactor.h"
#include "PyDbDatabase.h"
#include "PyDbIdMapping.h"
#include "PyDbObjectId.h"
#define PYEDREACTOR_DEBUG
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
#ifdef PYEDREACTOR_DEBUG
    acutPrintf(_T("\n%ls"), __FUNCTIONW__);
#endif // PYEDREACTOR_DEBUG
    PyAutoLockGIL lock;
    commandWillStartWr(wstr_to_utf8(cmdStr));
}

void PyEditorReactor::commandEnded(const ACHAR* cmdStr)
{
#ifdef PYEDREACTOR_DEBUG
    acutPrintf(_T("\n%ls"), __FUNCTIONW__);
#endif // PYEDREACTOR_DEBUG
    PyAutoLockGIL lock;
    commandEndedWr(wstr_to_utf8(cmdStr));
}

void PyEditorReactor::commandCancelled(const ACHAR* cmdStr)
{
#ifdef PYEDREACTOR_DEBUG
    acutPrintf(_T("\n%ls"), __FUNCTIONW__);
#endif // PYEDREACTOR_DEBUG
    PyAutoLockGIL lock;
    commandCancelledWr(wstr_to_utf8(cmdStr));
}

void PyEditorReactor::commandFailed(const ACHAR* cmdStr)
{
#ifdef PYEDREACTOR_DEBUG
    acutPrintf(_T("\n%ls"), __FUNCTIONW__);
#endif // PYEDREACTOR_DEBUG
    PyAutoLockGIL lock;
    commandFailedWr(wstr_to_utf8(cmdStr));
}

void PyEditorReactor::lispWillStart(const ACHAR* firstLine)
{
#ifdef PYEDREACTOR_DEBUG
    acutPrintf(_T("\n%ls"), __FUNCTIONW__);
#endif // PYEDREACTOR_DEBUG
    PyAutoLockGIL lock;
    lispWillStartWr(wstr_to_utf8(firstLine));
}

void PyEditorReactor::lispEnded()
{
#ifdef PYEDREACTOR_DEBUG
    acutPrintf(_T("\n%ls"), __FUNCTIONW__);
#endif // PYEDREACTOR_DEBUG
    PyAutoLockGIL lock;
    lispEndedWr();
}

void PyEditorReactor::lispCancelled()
{
#ifdef PYEDREACTOR_DEBUG
    acutPrintf(_T("\n%ls"), __FUNCTIONW__);
#endif // PYEDREACTOR_DEBUG
    PyAutoLockGIL lock;
    lispCancelledWr();
}

void PyEditorReactor::beginDxfIn(AcDbDatabase* pDb)
{
#ifdef PYEDREACTOR_DEBUG
    acutPrintf(_T("\n%ls"), __FUNCTIONW__);
#endif // PYEDREACTOR_DEBUG
    PyAutoLockGIL lock;
    PyDbDatabase db(pDb);
    beginDxfInWr(db);
}

void PyEditorReactor::abortDxfIn(AcDbDatabase* pDb)
{
#ifdef PYEDREACTOR_DEBUG
    acutPrintf(_T("\n%ls"), __FUNCTIONW__);
#endif // PYEDREACTOR_DEBUG
    PyAutoLockGIL lock;
    PyDbDatabase db(pDb);
    abortDxfInWr(db);
}

void PyEditorReactor::dxfInComplete(AcDbDatabase* pDb)
{
#ifdef PYEDREACTOR_DEBUG
    acutPrintf(_T("\n%ls"), __FUNCTIONW__);
#endif // PYEDREACTOR_DEBUG
    PyAutoLockGIL lock;
    PyDbDatabase db(pDb);
    dxfInCompleteWr(db);
}

void PyEditorReactor::beginDxfOut(AcDbDatabase* pDb)
{
#ifdef PYEDREACTOR_DEBUG
    acutPrintf(_T("\n%ls"), __FUNCTIONW__);
#endif // PYEDREACTOR_DEBUG
    PyAutoLockGIL lock;
    PyDbDatabase db(pDb);
    beginDxfOutWr(db);
}

void PyEditorReactor::abortDxfOut(AcDbDatabase* pDb)
{
#ifdef PYEDREACTOR_DEBUG
    acutPrintf(_T("\n%ls"), __FUNCTIONW__);
#endif // PYEDREACTOR_DEBUG
    PyAutoLockGIL lock;
    PyDbDatabase db(pDb);
    abortDxfOutWr(db);
}

void PyEditorReactor::dxfOutComplete(AcDbDatabase* pDb)
{
#ifdef PYEDREACTOR_DEBUG
    acutPrintf(_T("\n%ls"), __FUNCTIONW__);
#endif // PYEDREACTOR_DEBUG
    PyAutoLockGIL lock;
    PyDbDatabase db(pDb);
    dxfOutCompleteWr(db);
}

void PyEditorReactor::beginDwgOpen(const ACHAR* filename)
{
#ifdef PYEDREACTOR_DEBUG
    acutPrintf(_T("\n%ls"), __FUNCTIONW__);
#endif // PYEDREACTOR_DEBUG
    PyAutoLockGIL lock;
    beginDwgOpenWr(wstr_to_utf8(filename));
}

void PyEditorReactor::endDwgOpen(const ACHAR* filename, AcDbDatabase* pDb)
{
#ifdef PYEDREACTOR_DEBUG
    acutPrintf(_T("\n%ls"), __FUNCTIONW__);
#endif // PYEDREACTOR_DEBUG
    PyAutoLockGIL lock;
    PyDbDatabase db(pDb);
    endDwgOpenWr(wstr_to_utf8(filename), db);
}

void PyEditorReactor::initialDwgFileOpenComplete(AcDbDatabase* pDwg)
{
#ifdef PYEDREACTOR_DEBUG
    acutPrintf(_T("\n%ls"), __FUNCTIONW__);
#endif // PYEDREACTOR_DEBUG
    PyAutoLockGIL lock;
    PyDbDatabase db(pDwg);
    initialDwgFileOpenCompleteWr(db);
}

void PyEditorReactor::databaseConstructed(AcDbDatabase* pDb)
{
#ifdef PYEDREACTOR_DEBUG
    acutPrintf(_T("\n%ls"), __FUNCTIONW__);
#endif // PYEDREACTOR_DEBUG
    PyAutoLockGIL lock;
    PyDbDatabase db(pDb);
    databaseConstructedWr(db);
}

void PyEditorReactor::databaseToBeDestroyed(AcDbDatabase* pDb)
{
#ifdef PYEDREACTOR_DEBUG
    acutPrintf(_T("\n%ls"), __FUNCTIONW__);
#endif // PYEDREACTOR_DEBUG
    PyAutoLockGIL lock;
    PyDbDatabase db(pDb);
    databaseToBeDestroyedWr(db);
}

void PyEditorReactor::beginSave(AcDbDatabase* pDb, const ACHAR* pIntendedName)
{
#ifdef PYEDREACTOR_DEBUG
    acutPrintf(_T("\n%ls"), __FUNCTIONW__);
#endif // PYEDREACTOR_DEBUG
    PyAutoLockGIL lock;
    PyDbDatabase db(pDb);
    beginSaveWr(db, wstr_to_utf8(pIntendedName));
}

void PyEditorReactor::saveComplete(AcDbDatabase* pDb, const ACHAR* pActualName)
{
#ifdef PYEDREACTOR_DEBUG
    acutPrintf(_T("\n%ls"), __FUNCTIONW__);
#endif // PYEDREACTOR_DEBUG
    PyAutoLockGIL lock;
    PyDbDatabase db(pDb);
    saveCompleteWr(db, wstr_to_utf8(pActualName));
}

void PyEditorReactor::abortSave(AcDbDatabase* pDb)
{
#ifdef PYEDREACTOR_DEBUG
    acutPrintf(_T("\n%ls"), __FUNCTIONW__);
#endif // PYEDREACTOR_DEBUG
    PyAutoLockGIL lock;
    PyDbDatabase db(pDb);
    abortSaveWr(db);
}

void PyEditorReactor::beginInsert(AcDbDatabase* pTo, const ACHAR* pBlockName, AcDbDatabase* pFrom)
{
#ifdef PYEDREACTOR_DEBUG
    acutPrintf(_T("\n%ls"), __FUNCTIONW__);
#endif // PYEDREACTOR_DEBUG
    PyAutoLockGIL lock;
    PyDbDatabase to(pTo);
    PyDbDatabase from(pFrom);
    beginInsertWr1(to, wstr_to_utf8(pBlockName), from);
}

void PyEditorReactor::beginInsert(AcDbDatabase* pTo, const AcGeMatrix3d& xform, AcDbDatabase* pFrom)
{
#ifdef PYEDREACTOR_DEBUG
    acutPrintf(_T("\n%ls"), __FUNCTIONW__);
#endif // PYEDREACTOR_DEBUG
    PyAutoLockGIL lock;
    PyDbDatabase to(pTo);
    PyDbDatabase from(pFrom);
    beginInsertWr2(to, xform, from);
}

void PyEditorReactor::otherInsert(AcDbDatabase* pTo, AcDbIdMapping& idMap, AcDbDatabase* pFrom)
{
#ifdef PYEDREACTOR_DEBUG
    acutPrintf(_T("\n%ls"), __FUNCTIONW__);
#endif // PYEDREACTOR_DEBUG
    PyAutoLockGIL lock;
    PyDbDatabase to(pTo);
    PyDbDatabase from(pFrom);
    PyDbIdMapping maping(idMap);
    otherInsertWr(to, maping, from);
}

void PyEditorReactor::abortInsert(AcDbDatabase* pTo)
{
#ifdef PYEDREACTOR_DEBUG
    acutPrintf(_T("\n%ls"), __FUNCTIONW__);
#endif // PYEDREACTOR_DEBUG
    PyAutoLockGIL lock;
    PyDbDatabase to(pTo);
    abortInsertWr(to);
}

void PyEditorReactor::endInsert(AcDbDatabase* pTo)
{
#ifdef PYEDREACTOR_DEBUG
    acutPrintf(_T("\n%ls"), __FUNCTIONW__);
#endif // PYEDREACTOR_DEBUG
    PyAutoLockGIL lock;
    PyDbDatabase to(pTo);
    abortInsertWr(to);
}

void PyEditorReactor::wblockNotice(AcDbDatabase* pDb)
{
#ifdef PYEDREACTOR_DEBUG
    acutPrintf(_T("\n%ls"), __FUNCTIONW__);
#endif // PYEDREACTOR_DEBUG
    PyAutoLockGIL lock;
    PyDbDatabase db(pDb);
    wblockNoticeWr(db);
}

void PyEditorReactor::beginWblock(AcDbDatabase* pTo, AcDbDatabase* pFrom, AcDbObjectId blockId)
{
#ifdef PYEDREACTOR_DEBUG
    acutPrintf(_T("\n%ls"), __FUNCTIONW__);
#endif // PYEDREACTOR_DEBUG
    PyAutoLockGIL lock;
    PyDbDatabase to(pTo);
    PyDbDatabase from(pFrom);
    PyDbObjectId id(blockId);
    beginWblockWr(to, from, id);
}

void PyEditorReactor::otherWblock(AcDbDatabase* pTo, AcDbIdMapping& idMap, AcDbDatabase* pFrom)
{
#ifdef PYEDREACTOR_DEBUG
    acutPrintf(_T("\n%ls"), __FUNCTIONW__);
#endif // PYEDREACTOR_DEBUG
    PyAutoLockGIL lock;
    PyDbDatabase to(pTo);
    PyDbDatabase from(pFrom);
    PyDbIdMapping maping(idMap);
    otherWblockWr(to, maping, from);
}

void PyEditorReactor::abortWblock(AcDbDatabase* pTo)
{
#ifdef PYEDREACTOR_DEBUG
    acutPrintf(_T("\n%ls"), __FUNCTIONW__);
#endif // PYEDREACTOR_DEBUG
    PyAutoLockGIL lock;
    PyDbDatabase to(pTo);
    abortWblockWr(to);
}

void PyEditorReactor::endWblock(AcDbDatabase* pTo)
{
#ifdef PYEDREACTOR_DEBUG
    acutPrintf(_T("\n%ls"), __FUNCTIONW__);
#endif // PYEDREACTOR_DEBUG
    PyAutoLockGIL lock;
    PyDbDatabase to(pTo);
    endWblockWr(to);
}

void PyEditorReactor::beginDeepClone(AcDbDatabase* pTo, AcDbIdMapping& idMap)
{
#ifdef PYEDREACTOR_DEBUG
    acutPrintf(_T("\n%ls"), __FUNCTIONW__);
#endif // PYEDREACTOR_DEBUG
    PyAutoLockGIL lock;
    PyDbDatabase to(pTo);
    PyDbIdMapping mapping(idMap);
    beginDeepCloneWr(to, mapping);
}

void PyEditorReactor::beginDeepCloneXlation(AcDbIdMapping& idMap, Acad::ErrorStatus* es)
{
#ifdef PYEDREACTOR_DEBUG
    acutPrintf(_T("\n%ls"), __FUNCTIONW__);
#endif // PYEDREACTOR_DEBUG
    PyAutoLockGIL lock;
    PyDbIdMapping mapping(idMap);
    auto stat = beginDeepCloneXlationWr(mapping);
    if (es != nullptr)
        *es = stat;
}

void PyEditorReactor::abortDeepClone(AcDbIdMapping& idMap)
{
#ifdef PYEDREACTOR_DEBUG
    acutPrintf(_T("\n%ls"), __FUNCTIONW__);
#endif // PYEDREACTOR_DEBUG
    PyAutoLockGIL lock;
    PyDbIdMapping mapping(idMap);
    abortDeepCloneWr(mapping);
}

void PyEditorReactor::endDeepClone(AcDbIdMapping& idMap)
{
#ifdef PYEDREACTOR_DEBUG
    acutPrintf(_T("\n%ls"), __FUNCTIONW__);
#endif // PYEDREACTOR_DEBUG
    PyAutoLockGIL lock;
    PyDbIdMapping mapping(idMap);
    endDeepCloneWr(mapping);
}

void PyEditorReactor::sysVarChanged(const ACHAR* varName, bool success)
{
#ifdef PYEDREACTOR_DEBUG
    acutPrintf(_T("\n%ls"), __FUNCTIONW__);
#endif // PYEDREACTOR_DEBUG
    PyAutoLockGIL lock;
    sysVarChangedWr(wstr_to_utf8(varName), success);
}

void PyEditorReactor::sysVarWillChange(const ACHAR* varName)
{
#ifdef PYEDREACTOR_DEBUG
    acutPrintf(_T("\n%ls"), __FUNCTIONW__);
#endif // PYEDREACTOR_DEBUG
    PyAutoLockGIL lock;
    sysVarWillChangeWr(wstr_to_utf8(varName));
}

void PyEditorReactor::beginAttach(AcDbDatabase* pTo, const ACHAR* name, AcDbDatabase* pFrom)
{
#ifdef PYEDREACTOR_DEBUG
    acutPrintf(_T("\n%ls"), __FUNCTIONW__);
#endif // PYEDREACTOR_DEBUG
    PyAutoLockGIL lock;
    PyDbDatabase to(pTo);
    PyDbDatabase from(pFrom);
    beginAttachWr(to, wstr_to_utf8(name), from);
}

void PyEditorReactor::otherAttach(AcDbDatabase* pTo, AcDbDatabase* pFrom)
{
#ifdef PYEDREACTOR_DEBUG
    acutPrintf(_T("\n%ls"), __FUNCTIONW__);
#endif // PYEDREACTOR_DEBUG
    PyAutoLockGIL lock;
    PyDbDatabase to(pTo);
    PyDbDatabase from(pFrom);
    otherAttachWr(to, from);
}

void PyEditorReactor::abortAttach(AcDbDatabase* pFrom)
{
#ifdef PYEDREACTOR_DEBUG
    acutPrintf(_T("\n%ls"), __FUNCTIONW__);
#endif // PYEDREACTOR_DEBUG
    PyAutoLockGIL lock;
    PyDbDatabase from(pFrom);
    abortAttachWr(from);
}

void PyEditorReactor::endAttach(AcDbDatabase* pTo)
{
#ifdef PYEDREACTOR_DEBUG
    acutPrintf(_T("\n%ls"), __FUNCTIONW__);
#endif // PYEDREACTOR_DEBUG
    PyAutoLockGIL lock;
    PyDbDatabase to(pTo);
    endAttachWr(to);
}

void PyEditorReactor::redirected(AcDbObjectId newId, AcDbObjectId oldId)
{
#ifdef PYEDREACTOR_DEBUG
    acutPrintf(_T("\n%ls"), __FUNCTIONW__);
#endif // PYEDREACTOR_DEBUG
    PyAutoLockGIL lock;
    PyDbObjectId nid(newId);
    PyDbObjectId oid(oldId);
    redirectedWr(nid, oid);
}

void PyEditorReactor::comandeered(AcDbDatabase* pTo, AcDbObjectId id, AcDbDatabase* pFrom)
{
#ifdef PYEDREACTOR_DEBUG
    acutPrintf(_T("\n%ls"), __FUNCTIONW__);
#endif // PYEDREACTOR_DEBUG
    PyAutoLockGIL lock;
    PyDbDatabase to(pTo);
    PyDbObjectId nid(id);
    PyDbDatabase from(pFrom);
    comandeeredWr(to, nid, from);
}

void PyEditorReactor::beginRestore(AcDbDatabase* pTo, const ACHAR* str, AcDbDatabase* pFrom)
{
#ifdef PYEDREACTOR_DEBUG
    acutPrintf(_T("\n%ls"), __FUNCTIONW__);
#endif // PYEDREACTOR_DEBUG
    PyAutoLockGIL lock;
    PyDbDatabase to(pTo);
    PyDbDatabase from(pFrom);
    beginRestoreWr(to, wstr_to_utf8(str), from);
}

void PyEditorReactor::abortRestore(AcDbDatabase* pTo)
{
#ifdef PYEDREACTOR_DEBUG
    acutPrintf(_T("\n%ls"), __FUNCTIONW__);
#endif // PYEDREACTOR_DEBUG
    PyAutoLockGIL lock;
    PyDbDatabase to(pTo);
    abortRestoreWr(to);
}

void PyEditorReactor::endRestore(AcDbDatabase* pTo)
{
#ifdef PYEDREACTOR_DEBUG
    acutPrintf(_T("\n%ls"), __FUNCTIONW__);
#endif // PYEDREACTOR_DEBUG
    PyAutoLockGIL lock;
    PyDbDatabase to(pTo);
    endRestoreWr(to);
}

void PyEditorReactor::xrefSubcommandBindItem(AcDbDatabase* pHost, int activity, AcDbObjectId blockId)
{
#ifdef PYEDREACTOR_DEBUG
    acutPrintf(_T("\n%ls"), __FUNCTIONW__);
#endif // PYEDREACTOR_DEBUG
    PyAutoLockGIL lock;
    PyDbDatabase host(pHost);
    PyDbObjectId id(blockId);
    xrefSubcommandBindItemWr(host, activity, id);
}

void PyEditorReactor::xrefSubcommandAttachItem(AcDbDatabase* pHost, int activity, const ACHAR* pPath)
{
#ifdef PYEDREACTOR_DEBUG
    acutPrintf(_T("\n%ls"), __FUNCTIONW__);
#endif // PYEDREACTOR_DEBUG
    PyAutoLockGIL lock;
    PyDbDatabase host(pHost);
    xrefSubcommandAttachItemWr(host, activity, wstr_to_utf8(pPath));
}

void PyEditorReactor::xrefSubcommandOverlayItem(AcDbDatabase* pHost, int activity, const ACHAR* pPath)
{
#ifdef PYEDREACTOR_DEBUG
    acutPrintf(_T("\n%ls"), __FUNCTIONW__);
#endif // PYEDREACTOR_DEBUG
    PyAutoLockGIL lock;
    PyDbDatabase host(pHost);
    xrefSubcommandOverlayItemWr(host, activity, wstr_to_utf8(pPath));
}

void PyEditorReactor::xrefSubcommandDetachItem(AcDbDatabase* pHost, int activity, AcDbObjectId blockId)
{
#ifdef PYEDREACTOR_DEBUG
    acutPrintf(_T("\n%ls"), __FUNCTIONW__);
#endif // PYEDREACTOR_DEBUG
    PyAutoLockGIL lock;
    PyDbDatabase host(pHost);
    PyDbObjectId id(blockId);
    xrefSubcommandDetachItemWr(host, activity, id);
}

void PyEditorReactor::xrefSubcommandPathItem(int activity, AcDbObjectId blockId, const ACHAR* pNewPath)
{
#ifdef PYEDREACTOR_DEBUG
    acutPrintf(_T("\n%ls"), __FUNCTIONW__);
#endif // PYEDREACTOR_DEBUG
    PyAutoLockGIL lock;
    PyDbObjectId id(blockId);
    xrefSubcommandPathItemWr(activity, id, wstr_to_utf8(pNewPath));
}

void PyEditorReactor::xrefSubcommandReloadItem(AcDbDatabase* pHost, int activity, AcDbObjectId blockId)
{
#ifdef PYEDREACTOR_DEBUG
    acutPrintf(_T("\n%ls"), __FUNCTIONW__);
#endif // PYEDREACTOR_DEBUG
    PyAutoLockGIL lock;
    PyDbDatabase host(pHost);
    PyDbObjectId id(blockId);
    xrefSubcommandReloadItemWr(host, activity, id);
}

void PyEditorReactor::xrefSubcommandUnloadItem(AcDbDatabase* pHost, int activity, AcDbObjectId blockId)
{
#ifdef PYEDREACTOR_DEBUG
    acutPrintf(_T("\n%ls"), __FUNCTIONW__);
#endif // PYEDREACTOR_DEBUG
    PyAutoLockGIL lock;
    PyDbDatabase host(pHost);
    PyDbObjectId id(blockId);
    xrefSubcommandUnloadItemWr(host, activity, id);
}

#ifndef BRXAPP
void PyEditorReactor::undoSubcommandAuto(int activity, bool state)
{
#ifdef PYEDREACTOR_DEBUG
    acutPrintf(_T("\n%ls"), __FUNCTIONW__);
#endif // PYEDREACTOR_DEBUG
    PyAutoLockGIL lock;
    undoSubcommandAutoWr(activity, state);
}

#endif
void PyEditorReactor::undoSubcommandControl(int activity, int option)
{
#ifdef PYEDREACTOR_DEBUG
    acutPrintf(_T("\n%ls"), __FUNCTIONW__);
#endif // PYEDREACTOR_DEBUG
    PyAutoLockGIL lock;
    undoSubcommandControlWr(activity, option);
}

void PyEditorReactor::undoSubcommandBegin(int activity)
{
#ifdef PYEDREACTOR_DEBUG
    acutPrintf(_T("\n%ls"), __FUNCTIONW__);
#endif // PYEDREACTOR_DEBUG
    PyAutoLockGIL lock;
    undoSubcommandBeginWr(activity);
}

void PyEditorReactor::undoSubcommandEnd(int activity)
{
#ifdef PYEDREACTOR_DEBUG
    acutPrintf(_T("\n%ls"), __FUNCTIONW__);
#endif // PYEDREACTOR_DEBUG
    PyAutoLockGIL lock;
    undoSubcommandEndWr(activity);
}

void PyEditorReactor::undoSubcommandMark(int activity)
{
#ifdef PYEDREACTOR_DEBUG
    acutPrintf(_T("\n%ls"), __FUNCTIONW__);
#endif // PYEDREACTOR_DEBUG
    PyAutoLockGIL lock;
    undoSubcommandMarkWr(activity);
}

void PyEditorReactor::undoSubcommandBack(int activity)
{
#ifdef PYEDREACTOR_DEBUG
    acutPrintf(_T("\n%ls"), __FUNCTIONW__);
#endif // PYEDREACTOR_DEBUG
    PyAutoLockGIL lock;
    undoSubcommandBackWr(activity);
}

void PyEditorReactor::undoSubcommandNumber(int activity, int num)
{
#ifdef PYEDREACTOR_DEBUG
    acutPrintf(_T("\n%ls"), __FUNCTIONW__);
#endif // PYEDREACTOR_DEBUG
    PyAutoLockGIL lock;
    undoSubcommandNumberWr(activity, num);
}

void PyEditorReactor::pickfirstModified()
{
#ifdef PYEDREACTOR_DEBUG
    acutPrintf(_T("\n%ls"), __FUNCTIONW__);
#endif // PYEDREACTOR_DEBUG
    PyAutoLockGIL lock;
    pickfirstModifiedWr();
}

void PyEditorReactor::layoutSwitched(const ACHAR* newLayoutName)
{
#ifdef PYEDREACTOR_DEBUG
    acutPrintf(_T("\n%ls"), __FUNCTIONW__);
#endif // PYEDREACTOR_DEBUG
    PyAutoLockGIL lock;
    layoutSwitchedWr(wstr_to_utf8(newLayoutName));
}

void PyEditorReactor::layoutToBeSwitched(const ACHAR* oldLayoutName, const ACHAR* newLayoutName)
{
#ifdef PYEDREACTOR_DEBUG
    acutPrintf(_T("\n%ls"), __FUNCTIONW__);
#endif // PYEDREACTOR_DEBUG
    PyAutoLockGIL lock;
    layoutToBeSwitchedWr(wstr_to_utf8(oldLayoutName), wstr_to_utf8(newLayoutName));
}

void PyEditorReactor::dwgViewResized(Adesk::LongPtr hwndDwgView)
{
#ifdef PYEDREACTOR_DEBUG
    acutPrintf(_T("\n%ls"), __FUNCTIONW__);
#endif // PYEDREACTOR_DEBUG
    PyAutoLockGIL lock;
    dwgViewResizedWr(hwndDwgView);
}

#ifndef BRXAPP
void PyEditorReactor::fullRegenEnded(AcDbDatabase* pDb, const AcDbIntArray& regenedViewports)
{
#ifdef PYEDREACTOR_DEBUG
    acutPrintf(_T("\n%ls"), __FUNCTIONW__);
#endif // PYEDREACTOR_DEBUG
    PyAutoLockGIL lock;
    boost::python::list _list;
    for (auto item : regenedViewports)
        _list.append(item);
    PyDbDatabase host(pDb);
    fullRegenEndedWr(host, _list);
}

#endif
void PyEditorReactor::docFrameMovedOrResized(Adesk::LongPtr hwndDocFrame, bool bMoved)
{
#ifdef PYEDREACTOR_DEBUG
    acutPrintf(_T("\n%ls"), __FUNCTIONW__);
#endif // PYEDREACTOR_DEBUG
    PyAutoLockGIL lock;
    docFrameMovedOrResizedWr(hwndDocFrame, bMoved);
}

void PyEditorReactor::mainFrameMovedOrResized(Adesk::LongPtr hwndMainFrame, bool bMoved)
{
#ifdef PYEDREACTOR_DEBUG
    acutPrintf(_T("\n%ls"), __FUNCTIONW__);
#endif // PYEDREACTOR_DEBUG
    PyAutoLockGIL lock;
    mainFrameMovedOrResizedWr(hwndMainFrame, bMoved);
}

void PyEditorReactor::beginDoubleClick(const AcGePoint3d& clickPoint)
{
#ifdef PYEDREACTOR_DEBUG
    acutPrintf(_T("\n%ls"), __FUNCTIONW__);
#endif // PYEDREACTOR_DEBUG
    PyAutoLockGIL lock;
    beginDoubleClickWr(clickPoint);
}

void PyEditorReactor::beginRightClick(const AcGePoint3d& clickPoint)
{
#ifdef PYEDREACTOR_DEBUG
    acutPrintf(_T("\n%ls"), __FUNCTIONW__);
#endif // PYEDREACTOR_DEBUG
    PyAutoLockGIL lock;
    beginRightClickWr(clickPoint);
}

#ifndef BRXAPP
void PyEditorReactor::toolbarBitmapSizeWillChange(bool bLarge)
{
#ifdef PYEDREACTOR_DEBUG
    acutPrintf(_T("\n%ls"), __FUNCTIONW__);
#endif // PYEDREACTOR_DEBUG
    PyAutoLockGIL lock;
    toolbarBitmapSizeWillChangeWr(bLarge);
}

#endif
#ifndef BRXAPP
void PyEditorReactor::toolbarBitmapSizeChanged(bool bLarge)
{
#ifdef PYEDREACTOR_DEBUG
    acutPrintf(_T("\n%ls"), __FUNCTIONW__);
#endif // PYEDREACTOR_DEBUG
    PyAutoLockGIL lock;
    toolbarBitmapSizeChangedWr(bLarge);
}

#endif
void PyEditorReactor::beginWblockObjects(AcDbDatabase* pFrom, AcDbIdMapping& idMap)
{
#ifdef PYEDREACTOR_DEBUG
    acutPrintf(_T("\n%ls"), __FUNCTIONW__);
#endif // PYEDREACTOR_DEBUG
    PyAutoLockGIL lock;
    PyDbDatabase from(pFrom);
    PyDbIdMapping mapping(idMap);
    beginWblockObjectsWr(from, mapping);
}

void PyEditorReactor::partialOpenNotice(AcDbDatabase* pDb)
{
#ifdef PYEDREACTOR_DEBUG
    acutPrintf(_T("\n%ls"), __FUNCTIONW__);
#endif // PYEDREACTOR_DEBUG
    PyAutoLockGIL lock;
    PyDbDatabase from(pDb);
    partialOpenNoticeWr(from);
}

void PyEditorReactor::objectsLazyLoaded(const AcDbObjectIdArray& idArray)
{
#ifdef PYEDREACTOR_DEBUG
    acutPrintf(_T("\n%ls"), __FUNCTIONW__);
#endif // PYEDREACTOR_DEBUG
    PyAutoLockGIL lock;
    boost::python::list _list;
    for (auto item : idArray)
        _list.append(PyDbObjectId(item));
    objectsLazyLoadedWr(_list);
}

void PyEditorReactor::beginDocClose(AcDbDatabase* pDwg)
{
#ifdef PYEDREACTOR_DEBUG
    acutPrintf(_T("\n%ls"), __FUNCTIONW__);
#endif // PYEDREACTOR_DEBUG
    PyAutoLockGIL lock;
    PyDbDatabase dwg(pDwg);
    beginDocCloseWr(dwg);
}

void PyEditorReactor::docCloseAborted(AcDbDatabase* pDwg)
{
#ifdef PYEDREACTOR_DEBUG
    acutPrintf(_T("\n%ls"), __FUNCTIONW__);
#endif // PYEDREACTOR_DEBUG
    PyAutoLockGIL lock;
    PyDbDatabase dwg(pDwg);
    docCloseAbortedWr(dwg);
}

void PyEditorReactor::docCloseWillStart(AcDbDatabase* pDwg)
{
#ifdef PYEDREACTOR_DEBUG
    acutPrintf(_T("\n%ls"), __FUNCTIONW__);
#endif // PYEDREACTOR_DEBUG
    PyAutoLockGIL lock;
    PyDbDatabase dwg(pDwg);
    docCloseWillStartWr(dwg);
}

#ifndef BRXAPP
void PyEditorReactor::beginCloseAll()
{
#ifdef PYEDREACTOR_DEBUG
    acutPrintf(_T("\n%ls"), __FUNCTIONW__);
#endif // PYEDREACTOR_DEBUG
    PyAutoLockGIL lock;
    beginCloseAllWr();
}

#endif
void PyEditorReactor::beginQuit()
{
#ifdef PYEDREACTOR_DEBUG
    acutPrintf(_T("\n%ls"), __FUNCTIONW__);
#endif // PYEDREACTOR_DEBUG
    PyAutoLockGIL lock;
    beginQuitWr();
}

void PyEditorReactor::quitAborted()
{
#ifdef PYEDREACTOR_DEBUG
    acutPrintf(_T("\n%ls"), __FUNCTIONW__);
#endif // PYEDREACTOR_DEBUG
    PyAutoLockGIL lock;
    quitAbortedWr();
}

void PyEditorReactor::quitWillStart()
{
#ifdef PYEDREACTOR_DEBUG
    acutPrintf(_T("\n%ls"), __FUNCTIONW__);
#endif // PYEDREACTOR_DEBUG
    PyAutoLockGIL lock;
    quitWillStartWr();
}

void PyEditorReactor::modelessOperationWillStart(const ACHAR* contextStr)
{
#ifdef PYEDREACTOR_DEBUG
    acutPrintf(_T("\n%ls"), __FUNCTIONW__);
#endif // PYEDREACTOR_DEBUG
    PyAutoLockGIL lock;
    modelessOperationWillStartWr(wstr_to_utf8(contextStr));
}

void PyEditorReactor::modelessOperationEnded(const ACHAR* contextStr)
{
#ifdef PYEDREACTOR_DEBUG
    acutPrintf(_T("\n%ls"), __FUNCTIONW__);
#endif // PYEDREACTOR_DEBUG
    PyAutoLockGIL lock;
    modelessOperationEndedWr(wstr_to_utf8(contextStr));
}

void PyEditorReactor::cmdIUnkModified(const ACHAR* strCommand)
{
#ifdef PYEDREACTOR_DEBUG
    acutPrintf(_T("\n%ls"), __FUNCTIONW__);
#endif // PYEDREACTOR_DEBUG
    PyAutoLockGIL lock;
    cmdIUnkModifiedWr(wstr_to_utf8(strCommand));
}

void PyEditorReactor::preXrefLockFile(AcDbObjectId btrId)
{
#ifdef PYEDREACTOR_DEBUG
    acutPrintf(_T("\n%ls"), __FUNCTIONW__);
#endif // PYEDREACTOR_DEBUG
    PyAutoLockGIL lock;
    PyDbObjectId id(btrId);
    preXrefLockFileWr(id);
}

void PyEditorReactor::viewChanged()
{
#ifdef PYEDREACTOR_DEBUG
    acutPrintf(_T("\n%ls"), __FUNCTIONW__);
#endif // PYEDREACTOR_DEBUG
    PyAutoLockGIL lock;
    viewChangedWr();
}

#ifndef BRXAPP
void PyEditorReactor::fullRegenWillStart(AcDbDatabase* pDb)
{
#ifdef PYEDREACTOR_DEBUG
    acutPrintf(_T("\n%ls"), __FUNCTIONW__);
#endif // PYEDREACTOR_DEBUG
    PyAutoLockGIL lock;
    PyDbDatabase dwg(pDb);
    fullRegenWillStartWr(dwg);
}

#endif
//begin wrapper
void PyEditorReactor::commandWillStartWr(const std::string& cmdStr)
{
    if (override pyFunc = this->get_override("commandWillStart"))
        pyFunc(cmdStr);
}

void PyEditorReactor::commandEndedWr(const std::string& cmdStr)
{
    if (override pyFunc = this->get_override("commandEnded"))
        pyFunc(cmdStr);
}

void PyEditorReactor::commandCancelledWr(const std::string& cmdStr)
{
    if (override pyFunc = this->get_override("commandCancelled"))
        pyFunc(cmdStr);
}

void PyEditorReactor::commandFailedWr(const std::string& cmdStr)
{
    if (override pyFunc = this->get_override("commandCancelled"))
        pyFunc(cmdStr);
}

void PyEditorReactor::lispWillStartWr(const std::string& firstLine)
{
    if (override pyFunc = this->get_override("lispWillStart"))
        pyFunc(firstLine);
}

void PyEditorReactor::lispEndedWr()
{
    if (override pyFunc = this->get_override("lispEnded"))
        pyFunc();
}

void PyEditorReactor::lispCancelledWr()
{
    if (override pyFunc = this->get_override("lispCancelled"))
        pyFunc();
}

void PyEditorReactor::beginDxfInWr(PyDbDatabase& db)
{
    if (override pyFunc = this->get_override("beginDxfIn"))
        pyFunc(db);
}

void PyEditorReactor::abortDxfInWr(PyDbDatabase& db)
{
    if (override pyFunc = this->get_override("abortDxfIn"))
        pyFunc(db);
}

void PyEditorReactor::dxfInCompleteWr(PyDbDatabase& db)
{
    if (override pyFunc = this->get_override("dxfInComplete"))
        pyFunc(db);
}

void PyEditorReactor::beginDxfOutWr(PyDbDatabase& db)
{
    if (override pyFunc = this->get_override("beginDxfOut"))
        pyFunc(db);
}

void PyEditorReactor::abortDxfOutWr(PyDbDatabase& db)
{
    if (override pyFunc = this->get_override("abortDxfOut"))
        pyFunc(db);
}

void PyEditorReactor::dxfOutCompleteWr(PyDbDatabase& db)
{
    if (override pyFunc = this->get_override("dxfOutComplete"))
        pyFunc(db);
}

void PyEditorReactor::beginDwgOpenWr(const std::string& filename)
{
    if (override pyFunc = this->get_override("beginDwgOpen"))
        pyFunc(filename);
}

void PyEditorReactor::endDwgOpenWr(const std::string& filename, PyDbDatabase& db)
{
    if (override pyFunc = this->get_override("endDwgOpen"))
        pyFunc(filename, db);
}

void PyEditorReactor::initialDwgFileOpenCompleteWr(PyDbDatabase& db)
{
    if (override pyFunc = this->get_override("initialDwgFileOpenComplete"))
        pyFunc(db);
}

void PyEditorReactor::databaseConstructedWr(PyDbDatabase& db)
{
    if (override pyFunc = this->get_override("databaseConstructed"))
        pyFunc(db);
}

void PyEditorReactor::databaseToBeDestroyedWr(PyDbDatabase& db)
{
    if (override pyFunc = this->get_override("databaseToBeDestroyed"))
        pyFunc(db);
}

void PyEditorReactor::beginSaveWr(PyDbDatabase& db, const std::string& pIntendedName)
{
    if (override pyFunc = this->get_override("beginSave"))
        pyFunc(db, pIntendedName);
}

void PyEditorReactor::saveCompleteWr(PyDbDatabase& db, const std::string& pActualName)
{
    if (override pyFunc = this->get_override("saveComplete"))
        pyFunc(db, pActualName);
}

void PyEditorReactor::abortSaveWr(PyDbDatabase& db)
{
    if (override pyFunc = this->get_override("abortSave"))
        pyFunc(db);
}

void PyEditorReactor::beginInsertWr1(PyDbDatabase& pTo, const std::string& pBlockName, PyDbDatabase& pFrom)
{
    if (override pyFunc = this->get_override("beginInsert"))
        pyFunc(pTo, pBlockName, pFrom);
}

void PyEditorReactor::beginInsertWr2(PyDbDatabase& pTo, const AcGeMatrix3d& xform, PyDbDatabase& pFrom)
{
    if (override pyFunc = this->get_override("beginInsert"))
        pyFunc(pTo, xform, pFrom);
}

void PyEditorReactor::otherInsertWr(PyDbDatabase& pTo, PyDbIdMapping& idMap, PyDbDatabase& pFrom)
{
    if (override pyFunc = this->get_override("otherInsert"))
        pyFunc(pTo, idMap, pFrom);
}

void PyEditorReactor::abortInsertWr(PyDbDatabase& pTo)
{
    if (override pyFunc = this->get_override("abortInsert"))
        pyFunc(pTo);
}

void PyEditorReactor::endInsertWr(PyDbDatabase& pTo)
{
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
    if (override pyFunc = this->get_override("beginWblock"))
        pyFunc(pTo, pFrom, blockId);
}

void PyEditorReactor::otherWblockWr(PyDbDatabase& pTo, PyDbIdMapping& mapping, PyDbDatabase& pFrom)
{
    if (override pyFunc = this->get_override("otherWblock"))
        pyFunc(pTo, mapping, pFrom);
}

void PyEditorReactor::abortWblockWr(PyDbDatabase& pTo)
{
    if (override pyFunc = this->get_override("abortWblock"))
        pyFunc(pTo);
}

void PyEditorReactor::endWblockWr(PyDbDatabase& pTo)
{
    if (override pyFunc = this->get_override("endWblock"))
        pyFunc(pTo);
}

void PyEditorReactor::beginDeepCloneWr(PyDbDatabase& pTo, PyDbIdMapping& mapping)
{
    if (override pyFunc = this->get_override("endWblock"))
        pyFunc(pTo, mapping);
}

Acad::ErrorStatus PyEditorReactor::beginDeepCloneXlationWr(PyDbIdMapping& mapping)
{
    if (override pyFunc = this->get_override("beginDeepCloneXlation"))
        return pyFunc(mapping);
    return eInvalidInput;
}

void PyEditorReactor::abortDeepCloneWr(PyDbIdMapping& mapping)
{
    if (override pyFunc = this->get_override("abortDeepClone"))
        pyFunc(mapping);
}

void PyEditorReactor::endDeepCloneWr(PyDbIdMapping& mapping)
{
    if (override pyFunc = this->get_override("endDeepClone"))
        pyFunc(mapping);
}

void PyEditorReactor::sysVarChangedWr(const std::string& varName, bool success)
{
    if (override pyFunc = this->get_override("sysVarChanged"))
        pyFunc(varName, success);
}

void PyEditorReactor::sysVarWillChangeWr(const std::string& varName)
{
    if (override pyFunc = this->get_override("sysVarWillChange"))
        pyFunc(varName);
}

void PyEditorReactor::beginAttachWr(PyDbDatabase& pTo, const std::string& str, PyDbDatabase& pFrom)
{
    if (override pyFunc = this->get_override("beginAttach"))
        pyFunc(pTo, str, pFrom);
}

void PyEditorReactor::otherAttachWr(PyDbDatabase& pTo, PyDbDatabase& pFrom)
{
    if (override pyFunc = this->get_override("otherAttach"))
        pyFunc(pTo, pFrom);
}

void PyEditorReactor::abortAttachWr(PyDbDatabase& pFrom)
{
    if (override pyFunc = this->get_override("abortAttach"))
        pyFunc(pFrom);
}

void PyEditorReactor::endAttachWr(PyDbDatabase& pTo)
{
    if (override pyFunc = this->get_override("endAttach"))
        pyFunc(pTo);
}

void PyEditorReactor::redirectedWr(PyDbObjectId& newId, PyDbObjectId& oldId)
{
    if (override pyFunc = this->get_override("redirected"))
        pyFunc(newId, oldId);
}

void PyEditorReactor::comandeeredWr(PyDbDatabase& pTo, PyDbObjectId& id, PyDbDatabase& pFrom)
{
    if (override pyFunc = this->get_override("comandeered"))
        pyFunc(pTo, id, pFrom);
}

void PyEditorReactor::beginRestoreWr(PyDbDatabase& pTo, const std::string& str, PyDbDatabase& pFrom)
{
    if (override pyFunc = this->get_override("beginRestore"))
        pyFunc(pTo, str, pFrom);
}

void PyEditorReactor::abortRestoreWr(PyDbDatabase& pTo)
{
    if (override pyFunc = this->get_override("abortRestore"))
        pyFunc(pTo);
}

void PyEditorReactor::endRestoreWr(PyDbDatabase& pTo)
{
    if (override pyFunc = this->get_override("endRestore"))
        pyFunc(pTo);
}

void PyEditorReactor::xrefSubcommandBindItemWr(PyDbDatabase& pHost, int activity, PyDbObjectId& blockId)
{
    if (override pyFunc = this->get_override("xrefSubcommandBindItem"))
        pyFunc(pHost, activity, blockId);
}

void PyEditorReactor::xrefSubcommandAttachItemWr(PyDbDatabase& pHost, int activity, const std::string& pPath)
{
    if (override pyFunc = this->get_override("xrefSubcommandAttachItem"))
        pyFunc(pHost, activity, pPath);
}

void PyEditorReactor::xrefSubcommandOverlayItemWr(PyDbDatabase& pHost, int activity, const std::string& pPath)
{
    if (override pyFunc = this->get_override("xrefSubcommandOverlayItem"))
        pyFunc(pHost, activity, pPath);
}

void PyEditorReactor::xrefSubcommandDetachItemWr(PyDbDatabase& pHost, int activity, PyDbObjectId& blockId)
{
    if (override pyFunc = this->get_override("xrefSubcommandDetachItem"))
        pyFunc(pHost, activity, blockId);
}

void PyEditorReactor::xrefSubcommandPathItemWr(int activity, PyDbObjectId& blockId, const std::string& pNewPath)
{
    if (override pyFunc = this->get_override("xrefSubcommandPathItem"))
        pyFunc(activity, blockId, pNewPath);
}

void PyEditorReactor::xrefSubcommandReloadItemWr(PyDbDatabase& pHost, int activity, PyDbObjectId& blockId)
{
    if (override pyFunc = this->get_override("xrefSubcommandReloadItem"))
        pyFunc(pHost, activity, blockId);
}

void PyEditorReactor::xrefSubcommandUnloadItemWr(PyDbDatabase& pHost, int activity, PyDbObjectId& blockId)
{
    if (override pyFunc = this->get_override("xrefSubcommandUnloadItem"))
        pyFunc(pHost, activity, blockId);
}

void PyEditorReactor::undoSubcommandAutoWr(int activity, bool state)
{
    if (override pyFunc = this->get_override("xrefSubcommandUnloadItem"))
        pyFunc(activity, state);
}

void PyEditorReactor::undoSubcommandControlWr(int activity, int option)
{
    if (override pyFunc = this->get_override("xrefSubcommandUnloadItem"))
        pyFunc(activity, option);
}

void PyEditorReactor::undoSubcommandBeginWr(int activity)
{
    if (override pyFunc = this->get_override("undoSubcommandBegin"))
        pyFunc(activity);
}

void PyEditorReactor::undoSubcommandEndWr(int activity)
{
    if (override pyFunc = this->get_override("undoSubcommandEnd"))
        pyFunc(activity);
}

void PyEditorReactor::undoSubcommandMarkWr(int activity)
{
    if (override pyFunc = this->get_override("undoSubcommandMark"))
        pyFunc(activity);
}

void PyEditorReactor::undoSubcommandBackWr(int activity)
{
    if (override pyFunc = this->get_override("undoSubcommandBack"))
        pyFunc(activity);
}

void PyEditorReactor::undoSubcommandNumberWr(int activity, int num)
{
    if (override pyFunc = this->get_override("undoSubcommandNumber"))
        pyFunc(activity, num);
}

void PyEditorReactor::pickfirstModifiedWr()
{
    if (override pyFunc = this->get_override("pickfirstModified"))
        pyFunc();
}

void PyEditorReactor::layoutSwitchedWr(const std::string& newLayoutName)
{
    if (override pyFunc = this->get_override("layoutSwitched"))
        pyFunc(newLayoutName);
}

void PyEditorReactor::layoutToBeSwitchedWr(const std::string& oldLayoutName, const std::string& newLayoutName)
{
    if (override pyFunc = this->get_override("layoutToBeSwitched"))
        pyFunc(oldLayoutName, newLayoutName);
}

void PyEditorReactor::dwgViewResizedWr(Adesk::LongPtr hwndDwgView)
{
    if (override pyFunc = this->get_override("dwgViewResized"))
        pyFunc(hwndDwgView);
}

void PyEditorReactor::fullRegenEndedWr(PyDbDatabase& pDb, const boost::python::list& regenedViewports)
{
    if (override pyFunc = this->get_override("fullRegenEnded"))
        pyFunc(pDb, regenedViewports);
}

void PyEditorReactor::docFrameMovedOrResizedWr(Adesk::LongPtr hwndDocFrame, bool bMoved)
{
    if (override pyFunc = this->get_override("docFrameMovedOrResized"))
        pyFunc(hwndDocFrame, bMoved);
}

void PyEditorReactor::mainFrameMovedOrResizedWr(Adesk::LongPtr hwndMainFrame, bool bMoved)
{
    if (override pyFunc = this->get_override("mainFrameMovedOrResized"))
        pyFunc(hwndMainFrame, bMoved);
}

void PyEditorReactor::beginDoubleClickWr(const AcGePoint3d& clickPoint)
{
    if (override pyFunc = this->get_override("beginDoubleClick"))
        pyFunc(clickPoint);
}

void PyEditorReactor::beginRightClickWr(const AcGePoint3d& clickPoint)
{
    if (override pyFunc = this->get_override("beginRightClick"))
        pyFunc(clickPoint);
}

void PyEditorReactor::toolbarBitmapSizeWillChangeWr(bool bLarge)
{
    if (override pyFunc = this->get_override("toolbarBitmapSizeWillChange"))
        pyFunc(bLarge);
}

void PyEditorReactor::toolbarBitmapSizeChangedWr(bool bLarge)
{
    if (override pyFunc = this->get_override("toolbarBitmapSizeChanged"))
        pyFunc(bLarge);
}

void PyEditorReactor::beginWblockObjectsWr(PyDbDatabase& pFrom, PyDbIdMapping& mapping)
{
    if (override pyFunc = this->get_override("toolbarBitmapSizeChanged"))
        pyFunc(pFrom, mapping);
}

void PyEditorReactor::partialOpenNoticeWr(PyDbDatabase& pDb)
{
    if (override pyFunc = this->get_override("partialOpenNotice"))
        pyFunc(pDb);
}

void PyEditorReactor::objectsLazyLoadedWr(const boost::python::list& idArray)
{
    if (override pyFunc = this->get_override("objectsLazyLoaded"))
        pyFunc(idArray);
}

void PyEditorReactor::beginDocCloseWr(PyDbDatabase& pDwg)
{
    if (override pyFunc = this->get_override("beginDocClose"))
        pyFunc(pDwg);
}

void PyEditorReactor::docCloseAbortedWr(PyDbDatabase& pDwg)
{
    if (override pyFunc = this->get_override("docCloseAborted"))
        pyFunc(pDwg);
}

void PyEditorReactor::docCloseWillStartWr(PyDbDatabase& pDwg)
{
    if (override pyFunc = this->get_override("docCloseWillStart"))
        pyFunc(pDwg);
}

void PyEditorReactor::beginCloseAllWr()
{
    if (override pyFunc = this->get_override("beginCloseAll"))
        pyFunc();
}

void PyEditorReactor::beginQuitWr()
{
    if (override pyFunc = this->get_override("beginQuit"))
        pyFunc();
}

void PyEditorReactor::quitAbortedWr()
{
    if (override pyFunc = this->get_override("quitAborted"))
        pyFunc();
}

void PyEditorReactor::quitWillStartWr()
{
    if (override pyFunc = this->get_override("quitWillStart"))
        pyFunc();
}

void PyEditorReactor::modelessOperationWillStartWr(const std::string& contextStr)
{
    if (override pyFunc = this->get_override("modelessOperationWillStart"))
        pyFunc(contextStr);
}

void PyEditorReactor::modelessOperationEndedWr(const std::string& contextStr)
{
    if (override pyFunc = this->get_override("modelessOperationEnded"))
        pyFunc(contextStr);
}

void PyEditorReactor::cmdIUnkModifiedWr(const std::string& strCommand)
{
    if (override pyFunc = this->get_override("cmdIUnkModified"))
        pyFunc(strCommand);
}

void PyEditorReactor::preXrefLockFileWr(PyDbObjectId& btrId)
{
    if (override pyFunc = this->get_override("preXrefLockFile"))
        pyFunc(btrId);
}

void PyEditorReactor::viewChangedWr()
{
    if (override pyFunc = this->get_override("viewChanged"))
        pyFunc();
}

void PyEditorReactor::fullRegenWillStartWr(PyDbDatabase& pDb)
{
    if (override pyFunc = this->get_override("fullRegenWillStart"))
        pyFunc(pDb);
}

