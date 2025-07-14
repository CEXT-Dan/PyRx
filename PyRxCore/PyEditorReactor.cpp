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
    constexpr const std::string_view beginInsertOverloads = "Overloads:\n"
        "- dbTo: PyDb.Database, pBlockName: str, dbFrom: PyDb.Database\n"
        "- dbTo: PyDb.Database, xform: PyGe.Matrix3d, dbFrom: PyDb.Database\n\n";

    PyDocString DS("EditorReactor");
    class_<PyEditorReactor, boost::noncopyable>("EditorReactor")
        .def(init<>(DS.ARGS()))
        .def("addReactor", &PyEditorReactor::addReactor, DS.ARGS())
        .def("removeReactor", &PyEditorReactor::removeReactor, DS.ARGS())
        .def("veto", &PyEditorReactor::pyveto, DS.ARGS())
        .def("commandWillStart", &PyEditorReactor::commandWillStartWr, DS.ARGS({ "cmdStr: str" }))
        .def("commandEnded", &PyEditorReactor::commandEndedWr, DS.ARGS({ "cmdStr: str" }))
        .def("commandCancelled", &PyEditorReactor::commandCancelledWr, DS.ARGS({ "cmdStr: str" }))
        .def("commandFailed", &PyEditorReactor::commandFailedWr, DS.ARGS({ "cmdStr: str" }))
        .def("lispWillStart", &PyEditorReactor::lispWillStartWr, DS.ARGS({ "val: str" }))
        .def("lispEnded", &PyEditorReactor::lispEndedWr, DS.ARGS())
        .def("lispCancelled", &PyEditorReactor::lispCancelledWr, DS.ARGS())
        .def("beginDxfIn", &PyEditorReactor::beginDxfInWr, DS.ARGS({ "db: PyDb.Database" }))
        .def("abortDxfIn", &PyEditorReactor::abortDxfInWr, DS.ARGS({ "db: PyDb.Database" }))
        .def("dxfInComplete", &PyEditorReactor::dxfInCompleteWr, DS.ARGS({ "db: PyDb.Database" }))
        .def("beginDxfOut", &PyEditorReactor::beginDxfOutWr, DS.ARGS({ "db: PyDb.Database" }))
        .def("abortDxfOut", &PyEditorReactor::abortDxfOutWr, DS.ARGS({ "db: PyDb.Database" }))
        .def("dxfOutComplete", &PyEditorReactor::dxfOutCompleteWr, DS.ARGS({ "db: PyDb.Database" }))
        .def("beginDwgOpen", &PyEditorReactor::beginDwgOpenWr, DS.ARGS({ "fineName: str" }))
        .def("endDwgOpen", &PyEditorReactor::endDwgOpenWr, DS.ARGS({ "fineName: str","db: PyDb.Database" }))
        .def("initialDwgFileOpenComplete", &PyEditorReactor::initialDwgFileOpenCompleteWr, DS.ARGS({ "db: PyDb.Database" }))
        .def("databaseConstructed", &PyEditorReactor::databaseConstructedWr, DS.ARGS({ "db: PyDb.Database" }))
        .def("databaseToBeDestroyed", &PyEditorReactor::databaseToBeDestroyedWr, DS.ARGS({ "db: PyDb.Database" }))
        .def("beginSave", &PyEditorReactor::beginSaveWr, DS.ARGS({ "db: PyDb.Database","fname: str" }))
        .def("saveComplete", &PyEditorReactor::saveCompleteWr, DS.ARGS({ "db: PyDb.Database","fname: str" }))
        .def("abortSave", &PyEditorReactor::abortSaveWr, DS.ARGS({ "db: PyDb.Database" }))
        .def("beginInsert", &PyEditorReactor::beginInsertWr1)
        .def("beginInsert", &PyEditorReactor::beginInsertWr2, DS.OVRL(beginInsertOverloads))
        .def("otherInsert", &PyEditorReactor::otherInsertWr, DS.ARGS({ "dbTo: PyDb.Database", "idMap: PyDb.IdMapping","dbFrom: PyDb.Database" }))
        .def("abortInsert", &PyEditorReactor::abortInsertWr, DS.ARGS({ "db: PyDb.Database" }))
        .def("endInsert", &PyEditorReactor::endInsertWr, DS.ARGS({ "db: PyDb.Database" }))
        .def("wblockNotice", &PyEditorReactor::wblockNoticeWr, DS.ARGS({ "db: PyDb.Database" }))
        .def("beginWblock", &PyEditorReactor::beginWblockWr, DS.ARGS({ "dbTo: PyDb.Database", "dbFrom: PyDb.Database","id: PyDb.ObjectId" }))
        .def("otherWblock", &PyEditorReactor::otherWblockWr, DS.ARGS({ "dbTo: PyDb.Database", "idMap: PyDb.IdMapping","dbFrom: PyDb.Database" }))
        .def("abortWblock", &PyEditorReactor::abortWblockWr, DS.ARGS({ "db: PyDb.Database" }))
        .def("endWblock", &PyEditorReactor::endWblockWr, DS.ARGS({ "db: PyDb.Database" }))
        .def("beginDeepClone", &PyEditorReactor::beginDeepCloneWr, DS.ARGS({ "db: PyDb.Database", "idMap: PyDb.IdMapping" }))
        .def("beginDeepCloneXlation", &PyEditorReactor::beginDeepCloneXlationWr, DS.ARGS({ "idMap: PyDb.IdMapping" }))
        .def("abortDeepClone", &PyEditorReactor::abortDeepCloneWr, DS.ARGS({ "idMap: PyDb.IdMapping" }))
        .def("endDeepClone", &PyEditorReactor::endDeepCloneWr, DS.ARGS({ "idMap: PyDb.IdMapping" }))
        .def("sysVarChanged", &PyEditorReactor::sysVarChangedWr, DS.ARGS({ "varName: str","success: bool" }))
        .def("sysVarWillChange", &PyEditorReactor::sysVarWillChangeWr, DS.ARGS({ "varName: str" }))
        .def("beginAttach", &PyEditorReactor::beginAttachWr, DS.ARGS({ "dbTo: PyDb.Database", "val: str" ,"dbFrom: PyDb.Database" }))
        .def("otherAttach", &PyEditorReactor::otherAttachWr, DS.ARGS({ "dbTo: PyDb.Database","dbFrom: PyDb.Database" }))
        .def("abortAttach", &PyEditorReactor::abortAttachWr, DS.ARGS({ "dbFrom: PyDb.Database" }))
        .def("endAttach", &PyEditorReactor::endAttachWr, DS.ARGS({ "db: PyDb.Database" }))
        .def("redirected", &PyEditorReactor::redirectedWr, DS.ARGS({ "newId: PyDb.ObjectId","oldId: PyDb.ObjectId" }))
        .def("comandeered", &PyEditorReactor::comandeeredWr, DS.ARGS({ "dbTo: PyDb.Database", "id: PyDb.ObjectId","dbFrom: PyDb.Database" }))
        .def("beginRestore", &PyEditorReactor::beginRestoreWr, DS.ARGS({ "dbTo: PyDb.Database", "val: str" ,"dbFrom: PyDb.Database" }))
        .def("abortRestore", &PyEditorReactor::abortRestoreWr, DS.ARGS({ "dbTo: PyDb.Database" }))
        .def("endRestore", &PyEditorReactor::endRestoreWr, DS.ARGS({ "dbTo: PyDb.Database" }))
        .def("xrefSubcommandBindItem", &PyEditorReactor::xrefSubcommandBindItemWr, DS.ARGS({ "db: PyDb.Database","activity: int", "blockId: PyDb.ObjectId" }))
        .def("xrefSubcommandAttachItem", &PyEditorReactor::xrefSubcommandAttachItemWr, DS.ARGS({ "db: PyDb.Database","activity: int", "path: str" }))
        .def("xrefSubcommandOverlayItem", &PyEditorReactor::xrefSubcommandOverlayItemWr, DS.ARGS({ "db: PyDb.Database","activity: int", "path: str" }))
        .def("xrefSubcommandDetachItem", &PyEditorReactor::xrefSubcommandDetachItemWr, DS.ARGS({ "db: PyDb.Database","activity: int", "blockId: PyDb.ObjectId" }))
        .def("xrefSubcommandPathItem", &PyEditorReactor::xrefSubcommandPathItemWr, DS.ARGS({ "activity: int", "blockId: PyDb.ObjectId" ,"path: str" }))
        .def("xrefSubcommandReloadItem", &PyEditorReactor::xrefSubcommandReloadItemWr, DS.ARGS({ "db: PyDb.Database","activity: int", "blockId: PyDb.ObjectId" }))
        .def("xrefSubcommandUnloadItem", &PyEditorReactor::xrefSubcommandUnloadItemWr, DS.ARGS({ "db: PyDb.Database","activity: int", "blockId: PyDb.ObjectId" }))
        .def("undoSubcommandAuto", &PyEditorReactor::undoSubcommandAutoWr, DS.ARGS({ "activity: int","state: bool" }))
        .def("undoSubcommandControl", &PyEditorReactor::undoSubcommandControlWr, DS.ARGS({ "activity: int","option: int" }))
        .def("undoSubcommandBegin", &PyEditorReactor::undoSubcommandBeginWr, DS.ARGS({ "activity: int" }))
        .def("undoSubcommandEnd", &PyEditorReactor::undoSubcommandEndWr, DS.ARGS({ "activity: int" }))
        .def("undoSubcommandMark", &PyEditorReactor::undoSubcommandMarkWr, DS.ARGS({ "activity: int" }))
        .def("undoSubcommandBack", &PyEditorReactor::undoSubcommandBackWr, DS.ARGS({ "activity: int" }))
        .def("undoSubcommandNumber", &PyEditorReactor::undoSubcommandNumberWr, DS.ARGS({ "activity: int", "num: int" }))
        .def("pickfirstModified", &PyEditorReactor::pickfirstModifiedWr, DS.ARGS())
        .def("layoutSwitched", &PyEditorReactor::layoutSwitchedWr, DS.ARGS({ "layoutName: str" }))
        .def("layoutToBeSwitched", &PyEditorReactor::layoutToBeSwitchedWr, DS.ARGS({ "oldLayoutName: str","newLayoutName: str" }))
        .def("dwgViewResized", &PyEditorReactor::dwgViewResizedWr, DS.ARGS({ "hwndDwgView: int" }))
        .def("fullRegenEnded", &PyEditorReactor::fullRegenEndedWr, DS.ARGS({ "db: PyDb.Database", "regenedViewports: list[int]" }))
        .def("docFrameMovedOrResized", &PyEditorReactor::docFrameMovedOrResizedWr, DS.ARGS({ "hwndDocFrame: int", "moved: bool" }))
        .def("mainFrameMovedOrResized", &PyEditorReactor::mainFrameMovedOrResizedWr, DS.ARGS({ "hwndDocFrame: int", "moved: bool" }))
        .def("beginDoubleClick", &PyEditorReactor::beginDoubleClickWr, DS.ARGS({ "pt: PyGe.Point3d" }))
        .def("beginRightClick", &PyEditorReactor::beginRightClickWr, DS.ARGS({ "pt: PyGe.Point3d" }))
        .def("toolbarBitmapSizeWillChange", &PyEditorReactor::toolbarBitmapSizeWillChangeWr, DS.ARGS({ "large: bool" }))
        .def("toolbarBitmapSizeChanged", &PyEditorReactor::toolbarBitmapSizeChangedWr, DS.ARGS({ "large: bool" }))
        .def("beginWblockObjects", &PyEditorReactor::beginWblockObjectsWr, DS.ARGS({ "dbTo: PyDb.Database", "idMap: PyDb.IdMapping" }))
        .def("partialOpenNotice", &PyEditorReactor::partialOpenNoticeWr, DS.ARGS({ "db: PyDb.Database" }))
        .def("objectsLazyLoaded", &PyEditorReactor::objectsLazyLoadedWr, DS.ARGS({ "ids: list[PyDb.ObjectId]" }))
        .def("beginDocClose", &PyEditorReactor::beginDocCloseWr, DS.ARGS({ "db: PyDb.Database" }))
        .def("docCloseAborted", &PyEditorReactor::docCloseAbortedWr, DS.ARGS({ "db: PyDb.Database" }))
        .def("docCloseWillStart", &PyEditorReactor::docCloseWillStartWr, DS.ARGS({ "db: PyDb.Database" }))
        .def("beginCloseAll", &PyEditorReactor::beginCloseAllWr, DS.ARGS())
        .def("beginQuit", &PyEditorReactor::beginQuitWr, DS.ARGS())
        .def("quitAborted", &PyEditorReactor::quitAbortedWr, DS.ARGS())
        .def("quitWillStart", &PyEditorReactor::quitWillStartWr, DS.ARGS())
        .def("modelessOperationWillStart", &PyEditorReactor::modelessOperationWillStartWr, DS.ARGS({ "context: str" }))
        .def("modelessOperationEnded", &PyEditorReactor::modelessOperationEndedWr, DS.ARGS({ "context: str" }))
        .def("cmdIUnkModified", &PyEditorReactor::cmdIUnkModifiedWr, DS.ARGS({ "command: str" }))
        .def("preXrefLockFile", &PyEditorReactor::preXrefLockFileWr, DS.ARGS({ "id: PyDb.ObjectId" }))
        .def("viewChanged", &PyEditorReactor::viewChangedWr, DS.ARGS())
        .def("fullRegenWillStart", &PyEditorReactor::fullRegenWillStartWr, DS.ARGS({ "db: PyDb.Database" }))
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
    if (m_isActive == true)
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
    if (reg_commandWillStart == false)
        return;
    PyAutoLockGIL lock;
    commandWillStartWr(wstr_to_utf8(cmdStr));
}

void PyEditorReactor::commandEnded(const ACHAR* cmdStr)
{
    if (reg_commandEnded == false)
        return;
    PyAutoLockGIL lock;
    commandEndedWr(wstr_to_utf8(cmdStr));
}

void PyEditorReactor::commandCancelled(const ACHAR* cmdStr)
{
    if (reg_commandCancelled == false)
        return;
    PyAutoLockGIL lock;
    commandCancelledWr(wstr_to_utf8(cmdStr));
}

void PyEditorReactor::commandFailed(const ACHAR* cmdStr)
{
    if (reg_commandFailed == false)
        return;
    PyAutoLockGIL lock;
    commandFailedWr(wstr_to_utf8(cmdStr));
}

void PyEditorReactor::lispWillStart(const ACHAR* firstLine)
{
    if (reg_lispWillStart == false)
        return;
    PyAutoLockGIL lock;
    lispWillStartWr(wstr_to_utf8(firstLine));
}

void PyEditorReactor::lispEnded()
{
    if (reg_lispEnded == false)
        return;
    PyAutoLockGIL lock;
    lispEndedWr();
}

void PyEditorReactor::lispCancelled()
{
    if (reg_lispCancelled == false)
        return;
    PyAutoLockGIL lock;
    lispCancelledWr();
}

void PyEditorReactor::beginDxfIn(AcDbDatabase* pDb)
{
    if (reg_beginDxfIn == false)
        return;
    PyAutoLockGIL lock;
    PyDbDatabase db(pDb);
    beginDxfInWr(db);
}

void PyEditorReactor::abortDxfIn(AcDbDatabase* pDb)
{
    if (reg_abortDxfIn == false)
        return;
    PyAutoLockGIL lock;
    PyDbDatabase db(pDb);
    abortDxfInWr(db);
}

void PyEditorReactor::dxfInComplete(AcDbDatabase* pDb)
{
    if (reg_dxfInComplete == false)
        return;
    PyAutoLockGIL lock;
    PyDbDatabase db(pDb);
    dxfInCompleteWr(db);
}

void PyEditorReactor::beginDxfOut(AcDbDatabase* pDb)
{
    if (reg_beginDxfOut == false)
        return;
    PyAutoLockGIL lock;
    PyDbDatabase db(pDb);
    beginDxfOutWr(db);
}

void PyEditorReactor::abortDxfOut(AcDbDatabase* pDb)
{
    if (reg_abortDxfOut == false)
        return;
    PyAutoLockGIL lock;
    PyDbDatabase db(pDb);
    abortDxfOutWr(db);
}

void PyEditorReactor::dxfOutComplete(AcDbDatabase* pDb)
{
    if (reg_dxfOutComplete == false)
        return;
    PyAutoLockGIL lock;
    PyDbDatabase db(pDb);
    dxfOutCompleteWr(db);
}

void PyEditorReactor::beginDwgOpen(const ACHAR* filename)
{
    if (reg_beginDwgOpen == false)
        return;
    PyAutoLockGIL lock;
    beginDwgOpenWr(wstr_to_utf8(filename));
}

void PyEditorReactor::endDwgOpen(const ACHAR* filename, AcDbDatabase* pDb)
{
    if (reg_endDwgOpen == false)
        return;
    PyAutoLockGIL lock;
    PyDbDatabase db(pDb);
    endDwgOpenWr(wstr_to_utf8(filename), db);
}

void PyEditorReactor::initialDwgFileOpenComplete(AcDbDatabase* pDwg)
{
    if (reg_initialDwgFileOpenComplete == false)
        return;
    PyAutoLockGIL lock;
    PyDbDatabase db(pDwg);
    initialDwgFileOpenCompleteWr(db);
}

void PyEditorReactor::databaseConstructed(AcDbDatabase* pDb)
{
    if (reg_databaseConstructed == false)
        return;
    PyAutoLockGIL lock;
    PyDbDatabase db(pDb);
    databaseConstructedWr(db);
}

void PyEditorReactor::databaseToBeDestroyed(AcDbDatabase* pDb)
{
    if (reg_databaseToBeDestroyed == false)
        return;
    PyAutoLockGIL lock;
    PyDbDatabase db(pDb);
    databaseToBeDestroyedWr(db);
}

void PyEditorReactor::beginSave(AcDbDatabase* pDb, const ACHAR* pIntendedName)
{
    if (reg_beginSave == false)
        return;
    PyAutoLockGIL lock;
    PyDbDatabase db(pDb);
    beginSaveWr(db, wstr_to_utf8(pIntendedName));
}

void PyEditorReactor::saveComplete(AcDbDatabase* pDb, const ACHAR* pActualName)
{
    if (reg_saveComplete == false)
        return;
    PyAutoLockGIL lock;
    PyDbDatabase db(pDb);
    saveCompleteWr(db, wstr_to_utf8(pActualName));
}

void PyEditorReactor::abortSave(AcDbDatabase* pDb)
{
    if (reg_abortSave == false)
        return;
    PyAutoLockGIL lock;
    PyDbDatabase db(pDb);
    abortSaveWr(db);
}

void PyEditorReactor::beginInsert(AcDbDatabase* pTo, const ACHAR* pBlockName, AcDbDatabase* pFrom)
{
    if (reg_beginInsert1 == false)
        return;
    PyAutoLockGIL lock;
    PyDbDatabase to(pTo);
    PyDbDatabase from(pFrom);
    beginInsertWr1(to, wstr_to_utf8(pBlockName), from);
}

void PyEditorReactor::beginInsert(AcDbDatabase* pTo, const AcGeMatrix3d& xform, AcDbDatabase* pFrom)
{
    if (reg_beginInsert2 == false)
        return;
    PyAutoLockGIL lock;
    PyDbDatabase to(pTo);
    PyDbDatabase from(pFrom);
    beginInsertWr2(to, xform, from);
}

void PyEditorReactor::otherInsert(AcDbDatabase* pTo, AcDbIdMapping& idMap, AcDbDatabase* pFrom)
{
    if (reg_otherInsert == false)
        return;
    PyAutoLockGIL lock;
    PyDbDatabase to(pTo);
    PyDbDatabase from(pFrom);
    PyDbIdMapping mapping(idMap, true);
    otherInsertWr(to, mapping, from);
}

void PyEditorReactor::abortInsert(AcDbDatabase* pTo)
{
    if (reg_abortInsert == false)
        return;
    PyAutoLockGIL lock;
    PyDbDatabase to(pTo);
    abortInsertWr(to);
}

void PyEditorReactor::endInsert(AcDbDatabase* pTo)
{
    if (reg_endInsert == false)
        return;
    PyAutoLockGIL lock;
    PyDbDatabase to(pTo);
    abortInsertWr(to);
}

void PyEditorReactor::wblockNotice(AcDbDatabase* pDb)
{
    if (reg_wblockNotice == false)
        return;
    PyAutoLockGIL lock;
    PyDbDatabase db(pDb);
    wblockNoticeWr(db);
}

void PyEditorReactor::beginWblock(AcDbDatabase* pTo, AcDbDatabase* pFrom, AcDbObjectId blockId)
{
    if (reg_beginWblock == false)
        return;
    PyAutoLockGIL lock;
    PyDbDatabase to(pTo);
    PyDbDatabase from(pFrom);
    PyDbObjectId id(blockId);
    beginWblockWr(to, from, id);
}

void PyEditorReactor::otherWblock(AcDbDatabase* pTo, AcDbIdMapping& idMap, AcDbDatabase* pFrom)
{
    if (reg_otherWblock == false)
        return;
    PyAutoLockGIL lock;
    PyDbDatabase to(pTo);
    PyDbDatabase from(pFrom);
    PyDbIdMapping mapping(idMap, true);
    otherWblockWr(to, mapping, from);
}

void PyEditorReactor::abortWblock(AcDbDatabase* pTo)
{
    if (reg_abortWblock == false)
        return;
    PyAutoLockGIL lock;
    PyDbDatabase to(pTo);
    abortWblockWr(to);
}

void PyEditorReactor::endWblock(AcDbDatabase* pTo)
{
    if (reg_endWblock == false)
        return;
    PyAutoLockGIL lock;
    PyDbDatabase to(pTo);
    endWblockWr(to);
}

void PyEditorReactor::beginDeepClone(AcDbDatabase* pTo, AcDbIdMapping& idMap)
{
    if (reg_beginDeepClone == false)
        return;
    PyAutoLockGIL lock;
    PyDbDatabase to(pTo);
    PyDbIdMapping mapping(idMap, true);
    beginDeepCloneWr(to, mapping);
}

void PyEditorReactor::beginDeepCloneXlation(AcDbIdMapping& idMap, Acad::ErrorStatus* es)
{
    if (reg_beginDeepCloneXlation == false)
        return;
    PyAutoLockGIL lock;
    PyDbIdMapping mapping(idMap, true);
    auto stat = beginDeepCloneXlationWr(mapping);
    if (es != nullptr)
        *es = stat;
}

void PyEditorReactor::abortDeepClone(AcDbIdMapping& idMap)
{
    if (reg_abortDeepClone == false)
        return;
    PyAutoLockGIL lock;
    PyDbIdMapping mapping(idMap, true);
    abortDeepCloneWr(mapping);
}

void PyEditorReactor::endDeepClone(AcDbIdMapping& idMap)
{
    if (reg_endDeepClone == false)
        return;
    PyAutoLockGIL lock;
    PyDbIdMapping mapping(idMap, true);
    endDeepCloneWr(mapping);
}

void PyEditorReactor::sysVarChanged(const ACHAR* varName, bool success)
{
    if (reg_sysVarChanged == false)
        return;
    PyAutoLockGIL lock;
    sysVarChangedWr(wstr_to_utf8(varName), success);
}

void PyEditorReactor::sysVarWillChange(const ACHAR* varName)
{
    if (reg_sysVarWillChange == false)
        return;
    PyAutoLockGIL lock;
    sysVarWillChangeWr(wstr_to_utf8(varName));
}

void PyEditorReactor::beginAttach(AcDbDatabase* pTo, const ACHAR* name, AcDbDatabase* pFrom)
{
    if (reg_beginAttach == false)
        return;
    PyAutoLockGIL lock;
    PyDbDatabase to(pTo);
    PyDbDatabase from(pFrom);
    beginAttachWr(to, wstr_to_utf8(name), from);
}

void PyEditorReactor::otherAttach(AcDbDatabase* pTo, AcDbDatabase* pFrom)
{
    if (reg_otherAttach == false)
        return;
    PyAutoLockGIL lock;
    PyDbDatabase to(pTo);
    PyDbDatabase from(pFrom);
    otherAttachWr(to, from);
}

void PyEditorReactor::abortAttach(AcDbDatabase* pFrom)
{
    if (reg_abortAttach == false)
        return;
    PyAutoLockGIL lock;
    PyDbDatabase from(pFrom);
    abortAttachWr(from);
}

void PyEditorReactor::endAttach(AcDbDatabase* pTo)
{
    if (reg_endAttach == false)
        return;
    PyAutoLockGIL lock;
    PyDbDatabase to(pTo);
    endAttachWr(to);
}

void PyEditorReactor::redirected(AcDbObjectId newId, AcDbObjectId oldId)
{
    if (reg_redirected == false)
        return;
    PyAutoLockGIL lock;
    PyDbObjectId nid(newId);
    PyDbObjectId oid(oldId);
    redirectedWr(nid, oid);
}

void PyEditorReactor::comandeered(AcDbDatabase* pTo, AcDbObjectId id, AcDbDatabase* pFrom)
{
    if (reg_comandeered == false)
        return;
    PyAutoLockGIL lock;
    PyDbDatabase to(pTo);
    PyDbObjectId nid(id);
    PyDbDatabase from(pFrom);
    comandeeredWr(to, nid, from);
}

void PyEditorReactor::beginRestore(AcDbDatabase* pTo, const ACHAR* str, AcDbDatabase* pFrom)
{
    if (reg_beginRestore == false)
        return;
    PyAutoLockGIL lock;
    PyDbDatabase to(pTo);
    PyDbDatabase from(pFrom);
    beginRestoreWr(to, wstr_to_utf8(str), from);
}

void PyEditorReactor::abortRestore(AcDbDatabase* pTo)
{
    if (reg_abortRestore == false)
        return;
    PyAutoLockGIL lock;
    PyDbDatabase to(pTo);
    abortRestoreWr(to);
}

void PyEditorReactor::endRestore(AcDbDatabase* pTo)
{
    if (reg_endRestore == false)
        return;
    PyAutoLockGIL lock;
    PyDbDatabase to(pTo);
    endRestoreWr(to);
}

void PyEditorReactor::xrefSubcommandBindItem(AcDbDatabase* pHost, int activity, AcDbObjectId blockId)
{
    if (reg_xrefSubcommandBindItem == false)
        return;
    PyAutoLockGIL lock;
    PyDbDatabase host(pHost);
    PyDbObjectId id(blockId);
    xrefSubcommandBindItemWr(host, activity, id);
}

void PyEditorReactor::xrefSubcommandAttachItem(AcDbDatabase* pHost, int activity, const ACHAR* pPath)
{
    if (reg_xrefSubcommandAttachItem == false)
        return;
    PyAutoLockGIL lock;
    PyDbDatabase host(pHost);
    xrefSubcommandAttachItemWr(host, activity, wstr_to_utf8(pPath));
}

void PyEditorReactor::xrefSubcommandOverlayItem(AcDbDatabase* pHost, int activity, const ACHAR* pPath)
{
    if (reg_xrefSubcommandOverlayItem == false)
        return;
    PyAutoLockGIL lock;
    PyDbDatabase host(pHost);
    xrefSubcommandOverlayItemWr(host, activity, wstr_to_utf8(pPath));
}

void PyEditorReactor::xrefSubcommandDetachItem(AcDbDatabase* pHost, int activity, AcDbObjectId blockId)
{
    if (reg_xrefSubcommandDetachItem == false)
        return;
    PyAutoLockGIL lock;
    PyDbDatabase host(pHost);
    PyDbObjectId id(blockId);
    xrefSubcommandDetachItemWr(host, activity, id);
}

void PyEditorReactor::xrefSubcommandPathItem(int activity, AcDbObjectId blockId, const ACHAR* pNewPath)
{
    if (reg_xrefSubcommandPathItem == false)
        return;
    PyAutoLockGIL lock;
    PyDbObjectId id(blockId);
    xrefSubcommandPathItemWr(activity, id, wstr_to_utf8(pNewPath));
}

void PyEditorReactor::xrefSubcommandReloadItem(AcDbDatabase* pHost, int activity, AcDbObjectId blockId)
{
    if (reg_xrefSubcommandReloadItem == false)
        return;
    PyAutoLockGIL lock;
    PyDbDatabase host(pHost);
    PyDbObjectId id(blockId);
    xrefSubcommandReloadItemWr(host, activity, id);
}

void PyEditorReactor::xrefSubcommandUnloadItem(AcDbDatabase* pHost, int activity, AcDbObjectId blockId)
{
    if (reg_xrefSubcommandUnloadItem == false)
        return;
    PyAutoLockGIL lock;
    PyDbDatabase host(pHost);
    PyDbObjectId id(blockId);
    xrefSubcommandUnloadItemWr(host, activity, id);
}

#if !defined(_BRXTARGET260)
void PyEditorReactor::undoSubcommandAuto(int activity, bool state)
{
    if (reg_undoSubcommandAuto == false)
        return;
    PyAutoLockGIL lock;
    undoSubcommandAutoWr(activity, state);
}
#endif

void PyEditorReactor::undoSubcommandControl(int activity, int option)
{
    if (reg_undoSubcommandControl == false)
        return;
    PyAutoLockGIL lock;
    undoSubcommandControlWr(activity, option);
}

void PyEditorReactor::undoSubcommandBegin(int activity)
{
    if (reg_undoSubcommandBegin == false)
        return;
    PyAutoLockGIL lock;
    undoSubcommandBeginWr(activity);
}

void PyEditorReactor::undoSubcommandEnd(int activity)
{
    if (reg_undoSubcommandEnd == false)
        return;
    PyAutoLockGIL lock;
    undoSubcommandEndWr(activity);
}

void PyEditorReactor::undoSubcommandMark(int activity)
{
    if (reg_undoSubcommandMark == false)
        return;
    PyAutoLockGIL lock;
    undoSubcommandMarkWr(activity);
}

void PyEditorReactor::undoSubcommandBack(int activity)
{
    if (reg_undoSubcommandBack == false)
        return;
    PyAutoLockGIL lock;
    undoSubcommandBackWr(activity);
}

void PyEditorReactor::undoSubcommandNumber(int activity, int num)
{
    if (reg_undoSubcommandNumber == false)
        return;
    PyAutoLockGIL lock;
    undoSubcommandNumberWr(activity, num);
}

void PyEditorReactor::pickfirstModified()
{
    if (reg_pickfirstModified == false)
        return;
    PyAutoLockGIL lock;
    pickfirstModifiedWr();
}

void PyEditorReactor::layoutSwitched(const ACHAR* newLayoutName)
{
    if (reg_layoutSwitched == false)
        return;
    PyAutoLockGIL lock;
    layoutSwitchedWr(wstr_to_utf8(newLayoutName));
}

void PyEditorReactor::layoutToBeSwitched(const ACHAR* oldLayoutName, const ACHAR* newLayoutName)
{
    if (reg_layoutToBeSwitched == false)
        return;
    PyAutoLockGIL lock;
    layoutToBeSwitchedWr(wstr_to_utf8(oldLayoutName), wstr_to_utf8(newLayoutName));
}

void PyEditorReactor::dwgViewResized(Adesk::LongPtr hwndDwgView)
{
    if (reg_dwgViewResized == false)
        return;
    PyAutoLockGIL lock;
    dwgViewResizedWr(hwndDwgView);
}

#if !defined(_BRXTARGET260)
void PyEditorReactor::fullRegenEnded(AcDbDatabase* pDb, const AcDbIntArray& regenedViewports)
{
    if (reg_fullRegenEnded == false)
        return;
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
    if (reg_docFrameMovedOrResized == false)
        return;
    PyAutoLockGIL lock;
    docFrameMovedOrResizedWr(hwndDocFrame, bMoved);
}

void PyEditorReactor::mainFrameMovedOrResized(Adesk::LongPtr hwndMainFrame, bool bMoved)
{
    if (reg_mainFrameMovedOrResized == false)
        return;
    PyAutoLockGIL lock;
    mainFrameMovedOrResizedWr(hwndMainFrame, bMoved);
}

void PyEditorReactor::beginDoubleClick(const AcGePoint3d& clickPoint)
{
    if (reg_beginDoubleClick == false)
        return;
    PyAutoLockGIL lock;
    beginDoubleClickWr(clickPoint);
}

void PyEditorReactor::beginRightClick(const AcGePoint3d& clickPoint)
{
    if (reg_beginRightClick == false)
        return;
    PyAutoLockGIL lock;
    beginRightClickWr(clickPoint);
}

#if !defined(_BRXTARGET260)
void PyEditorReactor::toolbarBitmapSizeWillChange(bool bLarge)
{
    if (reg_toolbarBitmapSizeWillChange == false)
        return;
    PyAutoLockGIL lock;
    toolbarBitmapSizeWillChangeWr(bLarge);
}
#endif

#if !defined(_BRXTARGET260)
void PyEditorReactor::toolbarBitmapSizeChanged(bool bLarge)
{
    if (reg_toolbarBitmapSizeChanged == false)
        return;
    PyAutoLockGIL lock;
    toolbarBitmapSizeChangedWr(bLarge);
}
#endif

void PyEditorReactor::beginWblockObjects(AcDbDatabase* pFrom, AcDbIdMapping& idMap)
{
    if (reg_beginWblockObjects == false)
        return;
    PyAutoLockGIL lock;
    PyDbDatabase from(pFrom);
    PyDbIdMapping mapping(idMap, true);
    beginWblockObjectsWr(from, mapping);
}

void PyEditorReactor::partialOpenNotice(AcDbDatabase* pDb)
{
    if (reg_partialOpenNotice == false)
        return;
    PyAutoLockGIL lock;
    PyDbDatabase from(pDb);
    partialOpenNoticeWr(from);
}

void PyEditorReactor::objectsLazyLoaded(const AcDbObjectIdArray& idArray)
{
    if (reg_objectsLazyLoaded == false)
        return;
    PyAutoLockGIL lock;
    boost::python::list _list;
    for (auto item : idArray)
        _list.append(PyDbObjectId(item));
    objectsLazyLoadedWr(_list);
}

void PyEditorReactor::beginDocClose(AcDbDatabase* pDwg)
{
    if (reg_beginDocClose == false)
        return;
    PyAutoLockGIL lock;
    PyDbDatabase dwg(pDwg);
    beginDocCloseWr(dwg);
}

void PyEditorReactor::docCloseAborted(AcDbDatabase* pDwg)
{
    if (reg_docCloseAborted == false)
        return;
    PyAutoLockGIL lock;
    PyDbDatabase dwg(pDwg);
    docCloseAbortedWr(dwg);
}

void PyEditorReactor::docCloseWillStart(AcDbDatabase* pDwg)
{
    if (reg_docCloseWillStart == false)
        return;
    PyAutoLockGIL lock;
    PyDbDatabase dwg(pDwg);
    docCloseWillStartWr(dwg);
}

#if !defined(_BRXTARGET260)
void PyEditorReactor::beginCloseAll()
{
    if (reg_beginCloseAll == false)
        return;
    PyAutoLockGIL lock;
    beginCloseAllWr();
}
#endif

void PyEditorReactor::beginQuit()
{
    if (reg_beginQuit == false)
        return;
    PyAutoLockGIL lock;
    beginQuitWr();
}

void PyEditorReactor::quitAborted()
{
    if (reg_quitAborted == false)
        return;
    PyAutoLockGIL lock;
    quitAbortedWr();
}

void PyEditorReactor::quitWillStart()
{
    if (reg_quitWillStart == false)
        return;
    PyAutoLockGIL lock;
    quitWillStartWr();
}

void PyEditorReactor::modelessOperationWillStart(const ACHAR* contextStr)
{
    if (reg_modelessOperationWillStart == false)
        return;
    PyAutoLockGIL lock;
    modelessOperationWillStartWr(wstr_to_utf8(contextStr));
}

void PyEditorReactor::modelessOperationEnded(const ACHAR* contextStr)
{
    if (reg_modelessOperationEnded == false)
        return;
    PyAutoLockGIL lock;
    modelessOperationEndedWr(wstr_to_utf8(contextStr));
}

void PyEditorReactor::cmdIUnkModified(const ACHAR* strCommand)
{
    if (reg_cmdIUnkModified == false)
        return;
    PyAutoLockGIL lock;
    cmdIUnkModifiedWr(wstr_to_utf8(strCommand));
}

void PyEditorReactor::preXrefLockFile(AcDbObjectId btrId)
{
    if (reg_preXrefLockFile == false)
        return;
    PyAutoLockGIL lock;
    PyDbObjectId id(btrId);
    preXrefLockFileWr(id);
}

void PyEditorReactor::viewChanged()
{
    if (reg_viewChanged == false)
        return;
    PyAutoLockGIL lock;
    viewChangedWr();
}

#if !defined(_BRXTARGET260)
void PyEditorReactor::fullRegenWillStart(AcDbDatabase* pDb)
{
    if (reg_fullRegenWillStart == false)
        return;
    PyAutoLockGIL lock;
    PyDbDatabase dwg(pDb);
    fullRegenWillStartWr(dwg);
}
#endif

//--begin wrapper
void PyEditorReactor::commandWillStartWr(const std::string& cmdStr)
{
    try
    {
        if (const override& pyFunc = this->get_override("commandWillStart"))
            pyFunc(cmdStr);
        else
            reg_commandWillStart = false;
    }
    catch (...)
    {
        reg_commandWillStart = false;
        printExceptionMsg();
    }
}

void PyEditorReactor::commandEndedWr(const std::string& cmdStr)
{
    try
    {
        if (const override& pyFunc = this->get_override("commandEnded"))
            pyFunc(cmdStr);
        else
            reg_commandEnded = false;
    }
    catch (...)
    {
        reg_commandEnded = false;
        printExceptionMsg();
    }
}

void PyEditorReactor::commandCancelledWr(const std::string& cmdStr)
{
    try
    {
        if (const override& pyFunc = this->get_override("commandCancelled"))
            pyFunc(cmdStr);
        else
            reg_commandCancelled = false;
    }
    catch (...)
    {
        reg_commandCancelled = false;
        printExceptionMsg();
    }
}

void PyEditorReactor::commandFailedWr(const std::string& cmdStr)
{
    try
    {
        if (const override& pyFunc = this->get_override("commandFailed"))
            pyFunc(cmdStr);
        else
            reg_commandFailed = false;
    }
    catch (...)
    {
        reg_commandFailed = false;
        printExceptionMsg();
    }
}

void PyEditorReactor::lispWillStartWr(const std::string& firstLine)
{
    try
    {
        if (const override& pyFunc = this->get_override("lispWillStart"))
            pyFunc(firstLine);
        else
            reg_lispWillStart = false;
    }
    catch (...)
    {
        reg_lispWillStart = false;
        printExceptionMsg();
    }
}

void PyEditorReactor::lispEndedWr()
{
    try
    {
        if (const override& pyFunc = this->get_override("lispEnded"))
            pyFunc();
        else
            reg_lispEnded = false;
    }
    catch (...)
    {
        reg_lispEnded = false;
        printExceptionMsg();
    }
}

void PyEditorReactor::lispCancelledWr()
{
    try
    {
        if (const override& pyFunc = this->get_override("lispCancelled"))
            pyFunc();
        else
            reg_lispCancelled = false;
    }
    catch (...)
    {
        reg_lispCancelled = false;
        printExceptionMsg();
    }
}

void PyEditorReactor::beginDxfInWr(PyDbDatabase& db)
{
    try
    {
        if (const override& pyFunc = this->get_override("beginDxfIn"))
            pyFunc(db);
        else
            reg_beginDxfIn = false;
    }
    catch (...)
    {
        reg_beginDxfIn = false;
        printExceptionMsg();
    }
}

void PyEditorReactor::abortDxfInWr(PyDbDatabase& db)
{
    try
    {
        if (const override& pyFunc = this->get_override("abortDxfIn"))
            pyFunc(db);
        else
            reg_abortDxfIn = false;
    }
    catch (...)
    {
        reg_abortDxfIn = false;
        printExceptionMsg();
    }
}

void PyEditorReactor::dxfInCompleteWr(PyDbDatabase& db)
{
    try
    {
        if (const override& pyFunc = this->get_override("dxfInComplete"))
            pyFunc(db);
        else
            reg_dxfInComplete = false;
    }
    catch (...)
    {
        reg_dxfInComplete = false;
        printExceptionMsg();
    }
}

void PyEditorReactor::beginDxfOutWr(PyDbDatabase& db)
{
    try
    {
        if (const override& pyFunc = this->get_override("beginDxfOut"))
            pyFunc(db);
        else
            reg_beginDxfOut = false;
    }
    catch (...)
    {
        reg_beginDxfOut = false;
        printExceptionMsg();
    }
}

void PyEditorReactor::abortDxfOutWr(PyDbDatabase& db)
{
    try
    {
        if (const override& pyFunc = this->get_override("abortDxfOut"))
            pyFunc(db);
        else
            reg_abortDxfOut = false;
    }
    catch (...)
    {
        reg_abortDxfOut = false;
        printExceptionMsg();
    }
}

void PyEditorReactor::dxfOutCompleteWr(PyDbDatabase& db)
{
    try
    {
        if (const override& pyFunc = this->get_override("dxfOutComplete"))
            pyFunc(db);
        else
            reg_dxfOutComplete = false;
    }
    catch (...)
    {
        reg_dxfOutComplete = false;
        printExceptionMsg();
    }
}

void PyEditorReactor::beginDwgOpenWr(const std::string& filename)
{
    try
    {
        if (const override& pyFunc = this->get_override("beginDwgOpen"))
            pyFunc(filename);
        else
            reg_beginDwgOpen = false;
    }
    catch (...)
    {
        reg_beginDwgOpen = false;
        printExceptionMsg();
    }
}

void PyEditorReactor::endDwgOpenWr(const std::string& filename, PyDbDatabase& db)
{
    try
    {
        if (const override& pyFunc = this->get_override("endDwgOpen"))
            pyFunc(filename, db);
        else
            reg_endDwgOpen = false;
    }
    catch (...)
    {
        reg_endDwgOpen = false;
        printExceptionMsg();
    }
}

void PyEditorReactor::initialDwgFileOpenCompleteWr(PyDbDatabase& db)
{
    try
    {
        if (const override& pyFunc = this->get_override("initialDwgFileOpenComplete"))
            pyFunc(db);
        else
            reg_initialDwgFileOpenComplete = false;
    }
    catch (...)
    {
        reg_initialDwgFileOpenComplete = false;
        printExceptionMsg();
    }
}

void PyEditorReactor::databaseConstructedWr(PyDbDatabase& db)
{
    try
    {
        if (const override& pyFunc = this->get_override("databaseConstructed"))
            pyFunc(db);
        else
            reg_databaseConstructed = false;
    }
    catch (...)
    {
        reg_databaseConstructed = false;
        printExceptionMsg();
    }
}

void PyEditorReactor::databaseToBeDestroyedWr(PyDbDatabase& db)
{
    try
    {
        if (const override& pyFunc = this->get_override("databaseToBeDestroyed"))
            pyFunc(db);
        else
            reg_databaseToBeDestroyed = false;
    }
    catch (...)
    {
        reg_databaseToBeDestroyed = false;
        printExceptionMsg();
    }
}

void PyEditorReactor::beginSaveWr(PyDbDatabase& db, const std::string& pIntendedName)
{
    try
    {
        if (const override& pyFunc = this->get_override("beginSave"))
            pyFunc(db, pIntendedName);
        else
            reg_beginSave = false;
    }
    catch (...)
    {
        reg_beginSave = false;
        printExceptionMsg();
    }
}

void PyEditorReactor::saveCompleteWr(PyDbDatabase& db, const std::string& pActualName)
{
    try
    {
        if (const override& pyFunc = this->get_override("saveComplete"))
            pyFunc(db, pActualName);
        else
            reg_saveComplete = false;
    }
    catch (...)
    {
        reg_saveComplete = false;
        printExceptionMsg();
    }
}

void PyEditorReactor::abortSaveWr(PyDbDatabase& db)
{
    try
    {
        if (const override& pyFunc = this->get_override("abortSave"))
            pyFunc(db);
        else
            reg_abortSave = false;
    }
    catch (...)
    {
        reg_abortSave = false;
        printExceptionMsg();
    }
}

void PyEditorReactor::beginInsertWr1(PyDbDatabase& pTo, const std::string& pBlockName, PyDbDatabase& pFrom)
{
    try
    {
        if (const override& pyFunc = this->get_override("beginInsert"))
            pyFunc(pTo, pBlockName, pFrom);
        else
            reg_beginInsert1 = false;
    }
    catch (...)
    {
        reg_beginInsert1 = false;
        printExceptionMsg();
    }
}

void PyEditorReactor::beginInsertWr2(PyDbDatabase& pTo, const AcGeMatrix3d& xform, PyDbDatabase& pFrom)
{
    try
    {
        if (const override& pyFunc = this->get_override("beginInsert"))
            pyFunc(pTo, xform, pFrom);
        else
            reg_beginInsert2 = false;
    }
    catch (...)
    {
        reg_beginInsert2 = false;
        printExceptionMsg();
    }
}

void PyEditorReactor::otherInsertWr(PyDbDatabase& pTo, PyDbIdMapping& idMap, PyDbDatabase& pFrom)
{
    try
    {
        if (const override& pyFunc = this->get_override("otherInsert"))
            pyFunc(pTo, idMap, pFrom);
        else
            reg_otherInsert = false;
    }
    catch (...)
    {
        reg_otherInsert = false;
        printExceptionMsg();
    }
}

void PyEditorReactor::abortInsertWr(PyDbDatabase& pTo)
{
    try
    {
        if (const override& pyFunc = this->get_override("abortInsert"))
            pyFunc(pTo);
        else
            reg_otherInsert = false;
    }
    catch (...)
    {
        reg_otherInsert = false;
        printExceptionMsg();
    }
}

void PyEditorReactor::endInsertWr(PyDbDatabase& pTo)
{
    try
    {
        if (const override& pyFunc = this->get_override("endInsert"))
            pyFunc(pTo);
        else
            reg_endInsert = false;
    }
    catch (...)
    {
        reg_endInsert = false;
        printExceptionMsg();
    }
}

void PyEditorReactor::wblockNoticeWr(PyDbDatabase& pDb)
{
    try
    {
        if (const override& pyFunc = this->get_override("wblockNotice"))
            pyFunc(pDb);
        else
            reg_wblockNotice = false;
    }
    catch (...)
    {
        reg_wblockNotice = false;
        printExceptionMsg();
    }
}

void PyEditorReactor::beginWblockWr(PyDbDatabase& pTo, PyDbDatabase& pFrom, PyDbObjectId& blockId)
{
    try
    {
        if (const override& pyFunc = this->get_override("beginWblock"))
            pyFunc(pTo, pFrom, blockId);
        else
            reg_beginWblock = false;
    }
    catch (...)
    {
        reg_beginWblock = false;
        printExceptionMsg();
    }
}

void PyEditorReactor::otherWblockWr(PyDbDatabase& pTo, PyDbIdMapping& mapping, PyDbDatabase& pFrom)
{
    try
    {
        if (const override& pyFunc = this->get_override("otherWblock"))
            pyFunc(pTo, mapping, pFrom);
        else
            reg_otherWblock = false;
    }
    catch (...)
    {
        reg_otherWblock = false;
        printExceptionMsg();
    }
}

void PyEditorReactor::abortWblockWr(PyDbDatabase& pTo)
{
    try
    {
        if (const override& pyFunc = this->get_override("abortWblock"))
            pyFunc(pTo);
        else
            reg_abortWblock = false;
    }
    catch (...)
    {
        reg_abortWblock = false;
        printExceptionMsg();
    }
}

void PyEditorReactor::endWblockWr(PyDbDatabase& pTo)
{
    try
    {
        if (const override& pyFunc = this->get_override("endWblock"))
            pyFunc(pTo);
        else
            reg_endWblock = false;
    }
    catch (...)
    {
        reg_endWblock = false;
        printExceptionMsg();
    }
}

void PyEditorReactor::beginDeepCloneWr(PyDbDatabase& pTo, PyDbIdMapping& mapping)
{
    try
    {
        if (const override& pyFunc = this->get_override("beginDeepClone"))
            pyFunc(pTo, mapping);
        else
            reg_beginDeepClone = false;
    }
    catch (...)
    {
        reg_beginDeepClone = false;
        printExceptionMsg();
    }
}

Acad::ErrorStatus PyEditorReactor::beginDeepCloneXlationWr(PyDbIdMapping& mapping)
{
    try
    {
        if (const override& pyFunc = this->get_override("beginDeepCloneXlation"))
            return pyFunc(mapping);
        else
            reg_beginDeepCloneXlation = false;
    }
    catch (...)
    {
        reg_beginDeepCloneXlation = false;
        printExceptionMsg();
        return eInvalidInput;
    }
    return eOk;
}

void PyEditorReactor::abortDeepCloneWr(PyDbIdMapping& mapping)
{
    try
    {
        if (const override& pyFunc = this->get_override("abortDeepClone"))
            pyFunc(mapping);
        else
            reg_abortDeepClone = false;
    }
    catch (...)
    {
        reg_abortDeepClone = false;
        printExceptionMsg();
    }
}

void PyEditorReactor::endDeepCloneWr(PyDbIdMapping& mapping)
{
    try
    {
        if (const override& pyFunc = this->get_override("endDeepClone"))
            pyFunc(mapping);
        else
            reg_endDeepClone = false;
    }
    catch (...)
    {
        reg_endDeepClone = false;
        printExceptionMsg();
    }
}

void PyEditorReactor::sysVarChangedWr(const std::string& varName, bool success)
{
    try
    {
        if (const override& pyFunc = this->get_override("sysVarChanged"))
            pyFunc(varName, success);
        else
            reg_sysVarChanged = false;
    }
    catch (...)
    {
        reg_sysVarChanged = false;
        printExceptionMsg();
    }
}

void PyEditorReactor::sysVarWillChangeWr(const std::string& varName)
{
    try
    {
        if (const override& pyFunc = this->get_override("sysVarWillChange"))
            pyFunc(varName);
        else
            reg_sysVarWillChange = false;
    }
    catch (...)
    {
        reg_sysVarWillChange = false;
        printExceptionMsg();
    }
}

void PyEditorReactor::beginAttachWr(PyDbDatabase& pTo, const std::string& str, PyDbDatabase& pFrom)
{
    try
    {
        if (const override& pyFunc = this->get_override("beginAttach"))
            pyFunc(pTo, str, pFrom);
        else
            reg_beginAttach = false;
    }
    catch (...)
    {
        reg_beginAttach = false;
        printExceptionMsg();
    }
}

void PyEditorReactor::otherAttachWr(PyDbDatabase& pTo, PyDbDatabase& pFrom)
{
    try
    {
        if (const override& pyFunc = this->get_override("otherAttach"))
            pyFunc(pTo, pFrom);
        else
            reg_otherAttach = false;
    }
    catch (...)
    {
        reg_otherAttach = false;
        printExceptionMsg();
    }
}

void PyEditorReactor::abortAttachWr(PyDbDatabase& pFrom)
{
    try
    {
        if (const override& pyFunc = this->get_override("abortAttach"))
            pyFunc(pFrom);
        else
            reg_abortAttach = false;
    }
    catch (...)
    {
        reg_abortAttach = false;
        printExceptionMsg();
    }
}

void PyEditorReactor::endAttachWr(PyDbDatabase& pTo)
{
    try
    {
        if (const override& pyFunc = this->get_override("endAttach"))
            pyFunc(pTo);
        else
            reg_endAttach = false;
    }
    catch (...)
    {
        reg_endAttach = false;
        printExceptionMsg();
    }
}

void PyEditorReactor::redirectedWr(PyDbObjectId& newId, PyDbObjectId& oldId)
{
    try
    {
        if (const override& pyFunc = this->get_override("redirected"))
            pyFunc(newId, oldId);
        else
            reg_redirected = false;
    }
    catch (...)
    {
        reg_redirected = false;
        printExceptionMsg();
    }
}

void PyEditorReactor::comandeeredWr(PyDbDatabase& pTo, PyDbObjectId& id, PyDbDatabase& pFrom)
{
    try
    {
        if (const override& pyFunc = this->get_override("comandeered"))
            pyFunc(pTo, id, pFrom);
        else
            reg_comandeered = false;
    }
    catch (...)
    {
        reg_comandeered = false;
        printExceptionMsg();
    }
}

void PyEditorReactor::beginRestoreWr(PyDbDatabase& pTo, const std::string& str, PyDbDatabase& pFrom)
{
    try
    {
        if (const override& pyFunc = this->get_override("beginRestore"))
            pyFunc(pTo, str, pFrom);
        else
            reg_beginRestore = false;
    }
    catch (...)
    {
        reg_beginRestore = false;
        printExceptionMsg();
    }
}

void PyEditorReactor::abortRestoreWr(PyDbDatabase& pTo)
{
    try
    {
        if (const override& pyFunc = this->get_override("abortRestore"))
            pyFunc(pTo);
        else
            reg_abortRestore = false;
    }
    catch (...)
    {
        reg_endRestore = false;
        printExceptionMsg();
    }
}

void PyEditorReactor::endRestoreWr(PyDbDatabase& pTo)
{
    try
    {
        if (const override& pyFunc = this->get_override("endRestore"))
            pyFunc(pTo);
        else
            reg_endRestore = false;
    }
    catch (...)
    {
        reg_endRestore = false;
        printExceptionMsg();
    }
}

void PyEditorReactor::xrefSubcommandBindItemWr(PyDbDatabase& pHost, int activity, PyDbObjectId& blockId)
{
    try
    {
        if (const override& pyFunc = this->get_override("xrefSubcommandBindItem"))
            pyFunc(pHost, activity, blockId);
        else
            reg_xrefSubcommandBindItem = false;
    }
    catch (...)
    {
        reg_xrefSubcommandBindItem = false;
        printExceptionMsg();
    }
}

void PyEditorReactor::xrefSubcommandAttachItemWr(PyDbDatabase& pHost, int activity, const std::string& pPath)
{
    try
    {
        if (const override& pyFunc = this->get_override("xrefSubcommandAttachItem"))
            pyFunc(pHost, activity, pPath);
        else
            reg_xrefSubcommandAttachItem = false;
    }
    catch (...)
    {
        reg_xrefSubcommandAttachItem = false;
        printExceptionMsg();
    }
}

void PyEditorReactor::xrefSubcommandOverlayItemWr(PyDbDatabase& pHost, int activity, const std::string& pPath)
{
    try
    {
        if (const override& pyFunc = this->get_override("xrefSubcommandOverlayItem"))
            pyFunc(pHost, activity, pPath);
        else
            reg_xrefSubcommandOverlayItem = false;
    }
    catch (...)
    {
        reg_xrefSubcommandOverlayItem = false;
        printExceptionMsg();
    }
}

void PyEditorReactor::xrefSubcommandDetachItemWr(PyDbDatabase& pHost, int activity, PyDbObjectId& blockId)
{
    try
    {
        if (const override& pyFunc = this->get_override("xrefSubcommandDetachItem"))
            pyFunc(pHost, activity, blockId);
        else
            reg_xrefSubcommandDetachItem = false;
    }
    catch (...)
    {
        reg_xrefSubcommandDetachItem = false;
        printExceptionMsg();
    }
}

void PyEditorReactor::xrefSubcommandPathItemWr(int activity, PyDbObjectId& blockId, const std::string& pNewPath)
{
    try
    {
        if (const override& pyFunc = this->get_override("xrefSubcommandPathItem"))
            pyFunc(activity, blockId, pNewPath);
        else
            reg_xrefSubcommandPathItem = false;
    }
    catch (...)
    {
        reg_xrefSubcommandPathItem = false;
        printExceptionMsg();
    }
}

void PyEditorReactor::xrefSubcommandReloadItemWr(PyDbDatabase& pHost, int activity, PyDbObjectId& blockId)
{
    try
    {
        if (const override& pyFunc = this->get_override("xrefSubcommandReloadItem"))
            pyFunc(pHost, activity, blockId);
        else
            reg_xrefSubcommandReloadItem = false;
    }
    catch (...)
    {
        reg_xrefSubcommandReloadItem = false;
        printExceptionMsg();
    }
}

void PyEditorReactor::xrefSubcommandUnloadItemWr(PyDbDatabase& pHost, int activity, PyDbObjectId& blockId)
{
    try
    {
        if (const override& pyFunc = this->get_override("xrefSubcommandUnloadItem"))
            pyFunc(pHost, activity, blockId);
        else
            reg_xrefSubcommandUnloadItem = false;
    }
    catch (...)
    {
        reg_xrefSubcommandUnloadItem = false;
        printExceptionMsg();
    }
}

void PyEditorReactor::undoSubcommandAutoWr(int activity, bool state)
{
    try
    {
        if (const override& pyFunc = this->get_override("undoSubcommandAuto"))
            pyFunc(activity, state);
        else
            reg_undoSubcommandAuto = false;
    }
    catch (...)
    {
        reg_undoSubcommandAuto = false;
        printExceptionMsg();
    }
}

void PyEditorReactor::undoSubcommandControlWr(int activity, int option)
{
    try
    {
        if (const override& pyFunc = this->get_override("undoSubcommandControl"))
            pyFunc(activity, option);
        else
            reg_undoSubcommandControl = false;
    }
    catch (...)
    {
        reg_undoSubcommandControl = false;
        printExceptionMsg();
    }
}

void PyEditorReactor::undoSubcommandBeginWr(int activity)
{
    try
    {
        if (const override& pyFunc = this->get_override("undoSubcommandBegin"))
            pyFunc(activity);
        else
            reg_undoSubcommandBegin = false;
    }
    catch (...)
    {
        reg_undoSubcommandBegin = false;
        printExceptionMsg();
    }
}

void PyEditorReactor::undoSubcommandEndWr(int activity)
{
    try
    {
        if (const override& pyFunc = this->get_override("undoSubcommandEnd"))
            pyFunc(activity);
        else
            reg_undoSubcommandEnd = false;
    }
    catch (...)
    {
        reg_undoSubcommandEnd = false;
        printExceptionMsg();
    }
}

void PyEditorReactor::undoSubcommandMarkWr(int activity)
{
    try
    {
        if (const override& pyFunc = this->get_override("undoSubcommandMark"))
            pyFunc(activity);
        else
            reg_undoSubcommandMark = false;
    }
    catch (...)
    {
        reg_undoSubcommandMark = false;
        printExceptionMsg();
    }
}

void PyEditorReactor::undoSubcommandBackWr(int activity)
{
    try
    {
        if (const override& pyFunc = this->get_override("undoSubcommandBack"))
            pyFunc(activity);
        else
            reg_undoSubcommandBack = false;
    }
    catch (...)
    {
        reg_undoSubcommandBack = false;
        printExceptionMsg();
    }
}

void PyEditorReactor::undoSubcommandNumberWr(int activity, int num)
{
    try
    {
        if (const override& pyFunc = this->get_override("undoSubcommandNumber"))
            pyFunc(activity, num);
        else
            reg_undoSubcommandNumber = false;
    }
    catch (...)
    {
        reg_undoSubcommandNumber = false;
        printExceptionMsg();
    }
}

void PyEditorReactor::pickfirstModifiedWr()
{
    try
    {
        if (const override& pyFunc = this->get_override("pickfirstModified"))
            pyFunc();
        else
            reg_pickfirstModified = false;
    }
    catch (...)
    {
        reg_pickfirstModified = false;
        printExceptionMsg();
    }
}

void PyEditorReactor::layoutSwitchedWr(const std::string& newLayoutName)
{
    try
    {
        if (const override& pyFunc = this->get_override("layoutSwitched"))
            pyFunc(newLayoutName);
        else
            reg_layoutSwitched = false;
    }
    catch (...)
    {
        reg_layoutSwitched = false;
        printExceptionMsg();
    }
}

void PyEditorReactor::layoutToBeSwitchedWr(const std::string& oldLayoutName, const std::string& newLayoutName)
{
    try
    {
        if (const override& pyFunc = this->get_override("layoutToBeSwitched"))
            pyFunc(oldLayoutName, newLayoutName);
        else
            reg_layoutToBeSwitched = false;
    }
    catch (...)
    {
        reg_layoutToBeSwitched = false;
        printExceptionMsg();
    }
}

void PyEditorReactor::dwgViewResizedWr(Adesk::LongPtr hwndDwgView)
{
    try
    {
        if (const override& pyFunc = this->get_override("dwgViewResized"))
            pyFunc(hwndDwgView);
        else
            reg_dwgViewResized = false;
    }
    catch (...)
    {
        reg_dwgViewResized = false;
        printExceptionMsg();
    }
}

void PyEditorReactor::fullRegenEndedWr(PyDbDatabase& pDb, const boost::python::list& regenedViewports)
{
    try
    {
        if (const override& pyFunc = this->get_override("fullRegenEnded"))
            pyFunc(pDb, regenedViewports);
        else
            reg_fullRegenEnded = false;
    }
    catch (...)
    {
        reg_fullRegenEnded = false;
        printExceptionMsg();
    }
}

void PyEditorReactor::docFrameMovedOrResizedWr(Adesk::LongPtr hwndDocFrame, bool bMoved)
{
    try
    {
        if (const override& pyFunc = this->get_override("docFrameMovedOrResized"))
            pyFunc(hwndDocFrame, bMoved);
        else
            reg_docFrameMovedOrResized = false;
    }
    catch (...)
    {
        reg_docFrameMovedOrResized = false;
        printExceptionMsg();
    }
}

void PyEditorReactor::mainFrameMovedOrResizedWr(Adesk::LongPtr hwndMainFrame, bool bMoved)
{
    try
    {
        if (const override& pyFunc = this->get_override("mainFrameMovedOrResized"))
            pyFunc(hwndMainFrame, bMoved);
        else
            reg_mainFrameMovedOrResized = false;
    }
    catch (...)
    {
        reg_mainFrameMovedOrResized = false;
        printExceptionMsg();
    }
}

void PyEditorReactor::beginDoubleClickWr(const AcGePoint3d& clickPoint)
{
    try
    {
        if (const override& pyFunc = this->get_override("beginDoubleClick"))
            pyFunc(clickPoint);
        else
            reg_beginDoubleClick = false;
    }
    catch (...)
    {
        reg_beginDoubleClick = false;
        printExceptionMsg();
    }
}

void PyEditorReactor::beginRightClickWr(const AcGePoint3d& clickPoint)
{
    try
    {
        if (const override& pyFunc = this->get_override("beginRightClick"))
            pyFunc(clickPoint);
        else
            reg_beginRightClick = false;
    }
    catch (...)
    {
        reg_beginRightClick = false;
        printExceptionMsg();
    }
}

void PyEditorReactor::toolbarBitmapSizeWillChangeWr(bool bLarge)
{
    try
    {
        if (const override& pyFunc = this->get_override("toolbarBitmapSizeWillChange"))
            pyFunc(bLarge);
        else
            reg_toolbarBitmapSizeWillChange = false;
    }
    catch (...)
    {
        reg_toolbarBitmapSizeWillChange = false;
        printExceptionMsg();
    }
}

void PyEditorReactor::toolbarBitmapSizeChangedWr(bool bLarge)
{
    try
    {
        if (const override& pyFunc = this->get_override("toolbarBitmapSizeChanged"))
            pyFunc(bLarge);
        else
            reg_toolbarBitmapSizeChanged = false;
    }
    catch (...)
    {
        reg_toolbarBitmapSizeChanged = false;
        printExceptionMsg();
    }
}

void PyEditorReactor::beginWblockObjectsWr(PyDbDatabase& pFrom, PyDbIdMapping& mapping)
{
    try
    {
        if (const override& pyFunc = this->get_override("beginWblockObjects"))
            pyFunc(pFrom, mapping);
        else
            reg_beginWblockObjects = false;
    }
    catch (...)
    {
        reg_beginWblockObjects = false;
        printExceptionMsg();
    }
}

void PyEditorReactor::partialOpenNoticeWr(PyDbDatabase& pDb)
{
    try
    {
        if (const override& pyFunc = this->get_override("partialOpenNotice"))
            pyFunc(pDb);
        else
            reg_partialOpenNotice = false;
    }
    catch (...)
    {
        reg_partialOpenNotice = false;
        printExceptionMsg();
    }
}

void PyEditorReactor::objectsLazyLoadedWr(const boost::python::list& idArray)
{
    try
    {
        if (const override& pyFunc = this->get_override("objectsLazyLoaded"))
            pyFunc(idArray);
        else
            reg_objectsLazyLoaded = false;
    }
    catch (...)
    {
        reg_objectsLazyLoaded = false;
        printExceptionMsg();
    }
}

void PyEditorReactor::beginDocCloseWr(PyDbDatabase& pDwg)
{
    try
    {
        if (const override& pyFunc = this->get_override("beginDocClose"))
            pyFunc(pDwg);
        else
            reg_beginDocClose = false;
    }
    catch (...)
    {
        reg_beginDocClose = false;
        printExceptionMsg();
    }
}

void PyEditorReactor::docCloseAbortedWr(PyDbDatabase& pDwg)
{
    try
    {
        if (const override& pyFunc = this->get_override("docCloseAborted"))
            pyFunc(pDwg);
        else
            reg_docCloseAborted = false;
    }
    catch (...)
    {
        reg_docCloseAborted = false;
        printExceptionMsg();
    }
}

void PyEditorReactor::docCloseWillStartWr(PyDbDatabase& pDwg)
{
    try
    {
        if (const override& pyFunc = this->get_override("docCloseWillStart"))
            pyFunc(pDwg);
        else
            reg_docCloseWillStart = false;
    }
    catch (...)
    {
        reg_docCloseWillStart = false;
        printExceptionMsg();
    }
}

void PyEditorReactor::beginCloseAllWr()
{
    try
    {
        if (const override& pyFunc = this->get_override("beginCloseAll"))
            pyFunc();
        else
            reg_beginCloseAll = false;
    }
    catch (...)
    {
        reg_beginCloseAll = false;
        printExceptionMsg();
    }
}

void PyEditorReactor::beginQuitWr()
{
    try
    {
        if (const override& pyFunc = this->get_override("beginQuit"))
            pyFunc();
        else
            reg_beginQuit = false;
    }
    catch (...)
    {
        reg_beginQuit = false;
        printExceptionMsg();
    }
}

void PyEditorReactor::quitAbortedWr()
{
    try
    {
        if (const override& pyFunc = this->get_override("quitAborted"))
            pyFunc();
        else
            reg_quitAborted = false;
    }
    catch (...)
    {
        reg_quitAborted = false;
        printExceptionMsg();
    }
}

void PyEditorReactor::quitWillStartWr()
{
    try
    {
        if (const override& pyFunc = this->get_override("quitWillStart"))
            pyFunc();
        else
            reg_quitWillStart = false;
    }
    catch (...)
    {
        reg_quitWillStart = false;
        printExceptionMsg();
    }
}

void PyEditorReactor::modelessOperationWillStartWr(const std::string& contextStr)
{
    try
    {
        if (const override& pyFunc = this->get_override("modelessOperationWillStart"))
            pyFunc(contextStr);
        else
            reg_modelessOperationWillStart = false;
    }
    catch (...)
    {
        reg_modelessOperationWillStart = false;
        printExceptionMsg();
    }
}

void PyEditorReactor::modelessOperationEndedWr(const std::string& contextStr)
{
    try
    {
        if (const override& pyFunc = this->get_override("modelessOperationEnded"))
            pyFunc(contextStr);
        else
            reg_modelessOperationEnded = false;
    }
    catch (...)
    {
        reg_modelessOperationEnded = false;
        printExceptionMsg();
    }
}

void PyEditorReactor::cmdIUnkModifiedWr(const std::string& strCommand)
{
    try
    {
        if (const override& pyFunc = this->get_override("cmdIUnkModified"))
            pyFunc(strCommand);
        else
            reg_cmdIUnkModified = false;
    }
    catch (...)
    {
        reg_cmdIUnkModified = false;
        printExceptionMsg();
    }
}

void PyEditorReactor::preXrefLockFileWr(PyDbObjectId& btrId)
{
    try
    {
        if (const override& pyFunc = this->get_override("preXrefLockFile"))
            pyFunc(btrId);
        else
            reg_preXrefLockFile = false;
    }
    catch (...)
    {
        reg_preXrefLockFile = false;
        printExceptionMsg();
    }
}

void PyEditorReactor::viewChangedWr()
{
    try
    {
        if (const override& pyFunc = this->get_override("viewChanged"))
            pyFunc();
        else
            reg_viewChanged = false;
    }
    catch (...)
    {
        reg_viewChanged = false;
        printExceptionMsg();
    }
}

void PyEditorReactor::fullRegenWillStartWr(PyDbDatabase& pDb)
{
    try
    {
        if (const override& pyFunc = this->get_override("fullRegenWillStart"))
            pyFunc(pDb);
        else
            reg_fullRegenWillStart = false;
    }
    catch (...)
    {
        reg_fullRegenWillStart = false;
        printExceptionMsg();
    }
}
