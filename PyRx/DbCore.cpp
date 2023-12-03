#include "stdafx.h"
#include "DbCore.h"
#include "PyDbObjectId.h"
#include "PyDbEntity.h"
#include "dbdimassoc.h"
#include "ResultBuffer.h"
#include "PyDbDatabase.h"
#include "PyGeCurve3d.h"
#include "PyDbCurve.h"
#include "PyDbHostApplicationServices.h"
#include "PyDbTransactionManager.h"
#include "PyDbDimAssoc.h"
#include "AcPointCloud.h"

using namespace boost::python;

void makeDbCoreWrapper()
{
    PyDocString DS("Core");
    class_<DbCore>("Core")
        .def("attachPointCloudExEntity", &DbCore::attachPointCloudExEntity, DS.ARGS({ "path: str","pos: PyGe.Point3d","scale: real","rotation: real","db: PyDb.Database" })).staticmethod("attachPointCloudExEntity")
        .def("activeDatabaseArray", &DbCore::activeDatabaseArray, DS.SARGS()).staticmethod("activeDatabaseArray")
        .def("angToF", &DbCore::angToF, DS.SARGS({ "value:str","unit:int" })).staticmethod("angToF")
        .def("angToS", &DbCore::angToS, DS.SARGS({ "value:float","unit:int","prec:int" })).staticmethod("angToS")
        .def("assignGelibCurveToAcDbCurve", &DbCore::assignGelibCurveToAcDbCurve1)
        .def("assignGelibCurveToAcDbCurve", &DbCore::assignGelibCurveToAcDbCurve2)
        .def("assignGelibCurveToAcDbCurve", &DbCore::assignGelibCurveToAcDbCurve3,
            DS.SARGS({ "geCurve:PyGe.Curve3d","dbCurve:PyDb.Curve","norm:PyGe.Vector3d=kZAxis","tol:PyGe.Tol=tol" })).staticmethod("assignGelibCurveToAcDbCurve")

        .def("attachXref", &DbCore::attachXref).staticmethod("attachXref")
        .def("bindXrefs", &DbCore::bindXrefs1)
        .def("bindXrefs", &DbCore::bindXrefs2).staticmethod("bindXrefs")
        .def("clearSetupForLayouts", &DbCore::clearSetupForLayouts).staticmethod("clearSetupForLayouts")
        .def("convertAcDbCurveToGelibCurve", &DbCore::convertAcDbCurveToGelibCurve1)
        .def("convertAcDbCurveToGelibCurve", &DbCore::convertAcDbCurveToGelibCurve2,
            DS.SARGS({ "geCurve:PyGe.Curve2d","tol:PyGe.Tol=tol" })).staticmethod("convertAcDbCurveToGelibCurve")

        .def("convertGelibCurveToAcDbCurve", &DbCore::convertGelibCurveToAcDbCurve1)
        .def("convertGelibCurveToAcDbCurve", &DbCore::convertGelibCurveToAcDbCurve2)
        .def("convertGelibCurveToAcDbCurve", &DbCore::convertGelibCurveToAcDbCurve3,
            DS.SARGS({ "geCurve:PyGe.Curve3d","norm:PyGe.Vector3d=kZAxis","tol:PyGe.Tol=tol" })).staticmethod("convertGelibCurveToAcDbCurve")

        .def("createViewByViewport", &DbCore::createViewByViewport).staticmethod("createViewByViewport")
        .def("canonicalToSystemRange", &DbCore::canonicalToSystemRange).staticmethod("canonicalToSystemRange")

        .def("detachXref", &DbCore::detachXref).staticmethod("detachXref")
        .def("dictAdd", &DbCore::dictAdd).staticmethod("dictAdd")
        .def("dictNext", &DbCore::dictNext).staticmethod("dictNext")
        .def("dictRemove", &DbCore::dictRemove).staticmethod("dictRemove")
        .def("dictRename", &DbCore::dictRename).staticmethod("dictRename")
        .def("dictSearch", &DbCore::dictSearch).staticmethod("dictSearch")
        .def("displayPreviewFromDwg", &DbCore::displayPreviewFromDwg).staticmethod("displayPreviewFromDwg")
        .def("disToF", &DbCore::disToF).staticmethod("disToF")
        .def("doSetupForLayouts", &DbCore::doSetupForLayouts).staticmethod("doSetupForLayouts")
        .def("dwkFileExists", &DbCore::dwkFileExists).staticmethod("dwkFileExists")
        .def("dxfOutAs2000", &DbCore::dxfOutAs2000).staticmethod("dxfOutAs2000")
        .def("dxfOutAs2004", &DbCore::dxfOutAs2004).staticmethod("dxfOutAs2004")
        .def("dxfOutAsR12", &DbCore::dxfOutAsR12).staticmethod("dxfOutAsR12")
        .def("entGet", &DbCore::entGet, DS.SARGS({ "id : PyDb.ObjectId" })).staticmethod("entGet")
        .def("entGetX", &DbCore::entGetX1)
        .def("entGetX", &DbCore::entGetX2, DS.SARGS({ "id : PyDb.ObjectId","xdata : list" })).staticmethod("entGetX")
        .def("entDel", &DbCore::entDel, DS.SARGS({ "id : PyDb.ObjectId" })).staticmethod("entDel")
        .def("entLast", &DbCore::entLast, DS.SARGS()).staticmethod("entLast")
        .def("entMod", &DbCore::entMod, DS.SARGS({ "resultBuffer : list" })).staticmethod("entMod")
        .def("entNext", &DbCore::entNext, DS.SARGS({ "id : PyDb.ObjectId" })).staticmethod("entNext")
        .def("entUpd", &DbCore::entUpd, DS.SARGS({ "id : PyDb.ObjectId" })).staticmethod("entUpd")
        .def("entMake", &DbCore::entMake, DS.SARGS({ "resultBuffer : list" })).staticmethod("entMake")
        .def("entMakeX", &DbCore::entMakeX, DS.SARGS({ "resultBuffer : list" })).staticmethod("entMakeX")
        .def("fail", &DbCore::fail).staticmethod("fail")
        .def("findField", &DbCore::findField).staticmethod("findField")
        .def("forceTextAdjust", &DbCore::forceTextAdjust).staticmethod("forceTextAdjust")
        .def("getCurUserViewportId", &DbCore::getCurUserViewportId).staticmethod("getCurUserViewportId")
        .def("getCurVportId", &DbCore::getCurVportId).staticmethod("getCurVportId")
        .def("getCurVportTableRecordId", &DbCore::getCurVportTableRecordId).staticmethod("getCurVportTableRecordId")
        .def("getDimAssocId", &DbCore::getDimAssocId).staticmethod("getDimAssocId")
        .def("getDimAssocIds", &DbCore::getDimAssocIds).staticmethod("getDimAssocIds")
        .def("getDimStyleId", &DbCore::getDimStyleId).staticmethod("getDimStyleId")
        .def("getDynDimStyleId", &DbCore::getDynDimStyleId).staticmethod("getDynDimStyleId")
        .def("getProxyInfo", &DbCore::getProxyInfo).staticmethod("getProxyInfo")
        .def("getMappedFontName", &DbCore::getMappedFontName).staticmethod("getMappedFontName")
        .def("getReservedString", &DbCore::getReservedString).staticmethod("getReservedString")
        .def("getUnitsConversion", &DbCore::getUnitsConversion).staticmethod("getUnitsConversion")
        .def("getViewportVisualStyle", &DbCore::getViewportVisualStyle).staticmethod("getViewportVisualStyle")
        .def("handEnt", &DbCore::handEnt).staticmethod("handEnt")
        .def("isReservedString", &DbCore::isReservedString).staticmethod("isReservedString")
        .def("inters", &DbCore::inters).staticmethod("inters")
        .def("loadLineTypeFile", &DbCore::loadLineTypeFile).staticmethod("loadLineTypeFile")
        .def("loadMlineStyleFile", &DbCore::loadMlineStyleFile).staticmethod("loadMlineStyleFile")
        .def("namedObjDict", &DbCore::namedObjDict).staticmethod("namedObjDict")
        .def("openDbObject", &DbCore::openDbObject).staticmethod("openDbObject")
        .def("openDbObjects", &DbCore::openDbObjects1)
        .def("openDbObjects", &DbCore::openDbObjects2)
        .def("openDbObjects", &DbCore::openDbObjects3, DS.SARGS({ "ids: list[PyDb.ObjectId]", "mode: OpenMode=kForRead", "erased: bool=False" })).staticmethod("openDbObjects")
        .def("openDbEntity", &DbCore::openDbEntity).staticmethod("openDbEntity")
        .def("openDbEntities", &DbCore::openDbEntities1)
        .def("openDbEntities", &DbCore::openDbEntities2)
        .def("openDbEntities", &DbCore::openDbEntities3, DS.SARGS({ "ids: list[PyDb.ObjectId]", "mode: OpenMode=kForRead", "erased: bool=False" })).staticmethod("openDbEntities")
        .def("postDimAssoc", &DbCore::postDimAssoc1)
        .def("postDimAssoc", &DbCore::postDimAssoc2).staticmethod("postDimAssoc")
        .def("queueAnnotationEntitiesForRegen", &DbCore::queueAnnotationEntitiesForRegen).staticmethod("queueAnnotationEntitiesForRegen")
        .def("queueForRegen", &DbCore::queueForRegen).staticmethod("queueForRegen")
        .def("regApp", &DbCore::regApp).staticmethod("regApp")
        .def("reloadXrefs", &DbCore::reloadXrefs1)
        .def("reloadXrefs", &DbCore::reloadXrefs2).staticmethod("reloadXrefs")
        .def("rtos", &DbCore::rtos).staticmethod("rtos")
        .def("resbufTest", &DbCore::resbufTest).staticmethod("resbufTest")
        .def("snValid", &DbCore::snValid).staticmethod("snValid")
        .def("symUtil", &DbCore::symUtil).staticmethod("symUtil")
        .def("tblNext", &DbCore::tblNext).staticmethod("tblNext")
        .def("tblObjName", &DbCore::tblObjName).staticmethod("tblObjName")
        .def("tblSearch", &DbCore::tblSearch).staticmethod("tblSearch")
        .def("textFind", &DbCore::textFind1)
        .def("textFind", &DbCore::textFind2).staticmethod("textFind")
        .def("transactionManager", &DbCore::transactionManager).staticmethod("transactionManager")
        .def("ucsMatrix", &DbCore::ucsMatrix).staticmethod("ucsMatrix")
        .def("unloadXrefs", &DbCore::unloadXrefs1)
        .def("unloadXrefs", &DbCore::unloadXrefs2).staticmethod("unloadXrefs")
        .def("getSummaryInfo", &DbCore::getSummaryInfo).staticmethod("getSummaryInfo")
        .def("putSummaryInfo", &DbCore::putSummaryInfo).staticmethod("putSummaryInfo")
        .def("updateDimension", &DbCore::updateDimension).staticmethod("updateDimension")
        .def("validateCustomSummaryInfoKey", &DbCore::validateCustomSummaryInfoKey).staticmethod("validateCustomSummaryInfoKey")
        .def("ucs2Wcs", &DbCore::ucs2Wcs1)
        .def("ucs2Wcs", &DbCore::ucs2Wcs2).staticmethod("ucs2Wcs")
        .def("wcs2Ecs", &DbCore::wcs2Ecs1)
        .def("wcs2Ecs", &DbCore::wcs2Ecs2).staticmethod("wcs2Ecs")
        .def("wcs2Ucs", &DbCore::wcs2Ucs1)
        .def("wcs2Ucs", &DbCore::wcs2Ucs2).staticmethod("wcs2Ucs")
        .def("ecs2Wcs", &DbCore::ecs2Wcs1)
        .def("ecs2Wcs", &DbCore::ecs2Wcs2).staticmethod("ecs2Wcs")
        ;
}

PyDbObjectId DbCore::attachPointCloudExEntity(const std::string& pointCloudFile, AcGePoint3d& location, double scale, double rotation, PyDbDatabase& pDb)
{
    PyDbObjectId newPointCloudExId;
    AcString str = utf8_to_wstr(pointCloudFile).c_str();
    PyThrowBadEs(acdbAttachPointCloudExEntity(newPointCloudExId.m_id, str, location, scale, rotation, pDb.impObj()));
    return newPointCloudExId;
}

boost::python::list DbCore::activeDatabaseArray()
{
    PyAutoLockGIL lock;
    boost::python::list pyList;
    const AcArray<AcDbDatabase*>& dbs = acdbActiveDatabaseArray();
    for (auto db : dbs)
        pyList.append(PyDbDatabase(db));
    return pyList;
}

double DbCore::angToF(const std::string& str, int unit)
{
    double result = 0;
    PyThrowBadRt(acdbAngToF(utf8_to_wstr(str).c_str(), unit, &result));
    return result;
}

std::string DbCore::angToS(double val, int unit, int prec)
{
    std::array<wchar_t, 64> buf = { 0 };
    PyThrowBadRt(acdbAngToS(val, unit, prec, buf.data(), buf.size()));
    return wstr_to_utf8(buf.data());
}

void DbCore::assignGelibCurveToAcDbCurve1(const PyGeCurve3d& geCurve, PyDbCurve& pDbCurve)
{
    return PyThrowBadEs(acdbAssignGelibCurveToAcDbCurve(*geCurve.impObj(), pDbCurve.impObj()));
}

void DbCore::assignGelibCurveToAcDbCurve2(const PyGeCurve3d& geCurve, PyDbCurve& pDbCurve, AcGeVector3d& normal)
{
    return PyThrowBadEs(acdbAssignGelibCurveToAcDbCurve(*geCurve.impObj(), pDbCurve.impObj(), std::addressof(normal)));
}

void DbCore::assignGelibCurveToAcDbCurve3(const PyGeCurve3d& geCurve, PyDbCurve& pDbCurve, AcGeVector3d& normal, const AcGeTol& tol)
{
    return PyThrowBadEs(acdbAssignGelibCurveToAcDbCurve(*geCurve.impObj(), pDbCurve.impObj(), std::addressof(normal), tol));
}

void DbCore::attachXref(PyDbDatabase& pHostDb, const std::string& pFilename, const std::string& pBlockName, PyDbObjectId& xrefBlkId)
{
    return PyThrowBadEs(acdbAttachXref(pHostDb.impObj(), utf8_to_wstr(pFilename).c_str(), utf8_to_wstr(pBlockName).c_str(), xrefBlkId.m_id));
}

void DbCore::bindXrefs1(PyDbDatabase& pHostDb, const boost::python::list& xrefBlkIds, const bool bInsertBind)
{
    auto ids = PyListToObjectIdArray(xrefBlkIds);
    return PyThrowBadEs(acdbBindXrefs(pHostDb.impObj(), ids, bInsertBind));
}

void DbCore::bindXrefs2(PyDbDatabase& pHostDb, const boost::python::list& xrefBlkIds, const bool bInsertBind, const bool bAllowUnresolved, const bool bQuiet)
{
    auto ids = PyListToObjectIdArray(xrefBlkIds);
    return PyThrowBadEs(acdbBindXrefs(pHostDb.impObj(), ids, bInsertBind, bAllowUnresolved, bQuiet));
}

void DbCore::clearSetupForLayouts(UINT_PTR contextHandle)
{
    return PyThrowBadEs(acdbClearSetupForLayouts(contextHandle));
}

PyGeCurve3d DbCore::convertAcDbCurveToGelibCurve1(const PyDbCurve& dbCurve)
{
    AcGeCurve3d* pcurve;
    PyThrowBadEs(acdbConvertAcDbCurveToGelibCurve(dbCurve.impObj(), pcurve));
    return PyGeCurve3d(pcurve);
}

PyGeCurve3d DbCore::convertAcDbCurveToGelibCurve2(const PyDbCurve& dbCurve, const AcGeTol& tol)
{
    AcGeCurve3d* pcurve = nullptr;
    PyThrowBadEs(acdbConvertAcDbCurveToGelibCurve(dbCurve.impObj(), pcurve, tol));
    return PyGeCurve3d(pcurve);
}

PyDbCurve DbCore::convertGelibCurveToAcDbCurve1(const PyGeCurve3d& geCurve)
{
    AcDbCurve* pcurve = nullptr;
    PyThrowBadEs(acdbConvertGelibCurveToAcDbCurve(*geCurve.impObj(), pcurve));
    return PyDbCurve(pcurve, true);
}

PyDbCurve DbCore::convertGelibCurveToAcDbCurve2(const PyGeCurve3d& geCurve, AcGeVector3d& normal)
{
    AcDbCurve* pcurve = nullptr;
    PyThrowBadEs(acdbConvertGelibCurveToAcDbCurve(*geCurve.impObj(), pcurve, std::addressof(normal)));
    return PyDbCurve(pcurve, true);
}

PyDbCurve DbCore::convertGelibCurveToAcDbCurve3(const PyGeCurve3d& geCurve, AcGeVector3d& normal, const AcGeTol& tol)
{
    AcDbCurve* pcurve = nullptr;
    PyThrowBadEs(acdbConvertGelibCurveToAcDbCurve(*geCurve.impObj(), pcurve, std::addressof(normal), tol));
    return PyDbCurve(pcurve, true);
}

PyDbObjectId DbCore::createViewByViewport(PyDbDatabase& pDb, const PyDbObjectId& viewportId, const std::string& name, const std::string& categoryName, const PyDbObjectId& labelBlockId)
{
    PyDbObjectId view;
    PyThrowBadEs(acdbCreateViewByViewport(pDb.impObj(), viewportId.m_id, utf8_to_wstr(name).c_str(), utf8_to_wstr(categoryName).c_str(), labelBlockId.m_id, view.m_id));
    return view;
}

std::string DbCore::canonicalToSystemRange(int eUnits, const std::string& strIn)
{
    AcString strOut;
    acdbCanonicalToSystemRange(eUnits, utf8_to_wstr(strIn).c_str(), strOut);
    return wstr_to_utf8(strOut);
}

void DbCore::detachXref(PyDbDatabase& pHostDb, const PyDbObjectId& xrefBlkId)
{
    return PyThrowBadEs(acdbDetachXref(pHostDb.impObj(), xrefBlkId.m_id));
}

bool DbCore::dictAdd(const PyDbObjectId& dictname, const std::string& symname, const PyDbObjectId& newobj)
{
    ads_name ads_dictname = { 0 };
    PyThrowBadEs(acdbGetAdsName(ads_dictname, dictname.m_id));
    ads_name ads_newobj = { 0 };
    acdbGetAdsName(ads_newobj, dictname.m_id);
    return acdbDictAdd(ads_dictname, utf8_to_wstr(symname).c_str(), ads_newobj) == RTNORM;
}

boost::python::list DbCore::dictNext(const PyDbObjectId& dictname, int rewind)
{
    ads_name ads_dictname = { 0 };
    PyThrowBadEs(acdbGetAdsName(ads_dictname, dictname.m_id));
    AcResBufPtr pBuf(acdbDictNext(ads_dictname, rewind));
    return resbufToList(pBuf.get());
}

bool DbCore::dictRemove(const PyDbObjectId& dictname, const std::string& symname)
{
    ads_name ads_dictname = { 0 };
    PyThrowBadEs(acdbGetAdsName(ads_dictname, dictname.m_id));
    return acdbDictRemove(ads_dictname, utf8_to_wstr(symname).c_str()) == RTNORM;
}

bool DbCore::dictRename(const PyDbObjectId& dictname, const std::string& symname, const std::string& newsym)
{
    ads_name ads_dictname = { 0 };
    PyThrowBadEs(acdbGetAdsName(ads_dictname, dictname.m_id));
    return acdbDictRename(ads_dictname, utf8_to_wstr(symname).c_str(), utf8_to_wstr(newsym).c_str()) == RTNORM;
}

boost::python::list DbCore::dictSearch(const PyDbObjectId& dictname, const std::string& symname, int setnext)
{
    ads_name ads_dictname = { 0 };
    PyThrowBadEs(acdbGetAdsName(ads_dictname, dictname.m_id));
    AcResBufPtr pBuf(acdbDictSearch(ads_dictname, utf8_to_wstr(symname).c_str(), setnext));
    return resbufToList(pBuf.get());
}

bool DbCore::displayPreviewFromDwg(const std::string& pszDwgfilename, UINT_PTR hwnd)
{
    CWnd* wnd = CWnd::FromHandle((HWND)hwnd);
    if (wnd != nullptr)
        return acdbDisplayPreviewFromDwg(utf8_to_wstr(pszDwgfilename).c_str(), wnd->GetSafeHwnd());
    return false;
}

double DbCore::disToF(const std::string& str, int unit)
{
    double result = 0;
    PyThrowBadRt(acdbDisToF(utf8_to_wstr(str).c_str(), unit, &result));
    return result;
}

UINT_PTR DbCore::doSetupForLayouts(PyDbDatabase& pDatabase)
{
    Adesk::ULongPtr contextHandle = 0;
    PyThrowBadEs(acdbDoSetupForLayouts(pDatabase.impObj(), contextHandle));
    return contextHandle;
}

bool DbCore::dwkFileExists(const std::string& pszDwgfilename)
{
    return acdbDwkFileExists(utf8_to_wstr(pszDwgfilename).c_str());
}

void DbCore::dxfOutAs2000(PyDbDatabase& pDb, const std::string& fileName, int precision)
{
    return  PyThrowBadEs(acdbDxfOutAs2000(pDb.impObj(), utf8_to_wstr(fileName).c_str(), precision));
}

void DbCore::dxfOutAs2004(PyDbDatabase& pDb, const std::string& fileName, int precision)
{
    return  PyThrowBadEs(acdbDxfOutAs2004(pDb.impObj(), utf8_to_wstr(fileName).c_str(), precision));
}

void DbCore::dxfOutAsR12(PyDbDatabase& pDb, const std::string& fileName, int precision)
{
    return  PyThrowBadEs(acdbDxfOutAsR12(pDb.impObj(), utf8_to_wstr(fileName).c_str(), precision));
}

bool DbCore::entMake(const boost::python::list& rb)
{
    AcResBufPtr pBuf(listToResbuf(rb));
    return acdbEntMake(pBuf.get()) == RTNORM;
}

PyDbObjectId DbCore::entMakeX(const boost::python::list& rb)
{
    ads_name name = { 0 };
    AcResBufPtr pBuf(listToResbuf(rb));
    PyThrowBadRt(acdbEntMakeX(pBuf.get(), name));
    PyDbObjectId id;
    PyThrowBadEs(acdbGetObjectId(id.m_id, name));
    return id;
}

bool DbCore::entDel(const PyDbObjectId& id)
{
    ads_name name = { 0L };
    PyThrowBadEs(acdbGetAdsName(name, id.m_id));
    return acdbEntDel(name) == RTNORM;
}

boost::python::list DbCore::entGet(const PyDbObjectId& id)
{
    ads_name name = { 0L };
    PyThrowBadEs(acdbGetAdsName(name, id.m_id));
    AcResBufPtr ptr(acdbEntGet(name));
    if (ptr == nullptr)
        throw PyAcadErrorStatus(eInvalidInput);
    return resbufToList(ptr.get());
}

boost::python::list DbCore::entGetX1(const PyDbObjectId& id)
{
    ads_name name = { 0L };
    PyThrowBadEs(acdbGetAdsName(name, id.m_id));
    AcResBufPtr rbIn(acutNewRb(RTSTR));//stack?
    acutNewString(_T("*"), rbIn->resval.rstring);
    rbIn->rbnext = nullptr;
    AcResBufPtr ptr(acdbEntGetX(name, rbIn.get()));
    if (ptr == nullptr)
        throw PyAcadErrorStatus(eInvalidInput);
    return resbufToList(ptr.get());
}

boost::python::list DbCore::entGetX2(const PyDbObjectId& id, const boost::python::list& rb)
{
    ads_name name = { 0L };
    PyThrowBadEs(acdbGetAdsName(name, id.m_id));
    AcResBufPtr rbIn(listToResbuf(rb));
    AcResBufPtr ptr(acdbEntGetX(name, rbIn.get()));
    if (ptr == nullptr)
        throw PyAcadErrorStatus(eInvalidInput);
    return resbufToList(ptr.get());
}

PyDbObjectId DbCore::entLast()
{
    ads_name name = { 0L };
    PyThrowBadRt(acdbEntLast(name));
    PyDbObjectId id;
    PyThrowBadEs(acdbGetObjectId(id.m_id, name));
    return id;
}

bool DbCore::entMod(const boost::python::list& list)
{
    AcResBufPtr ptr(listToResbuf(list));
    return acdbEntMod(ptr.get()) == RTNORM;
}

PyDbObjectId DbCore::entNext(const PyDbObjectId& id)
{
    PyDbObjectId idOut;
    ads_name nameIn = { 0L };
    ads_name nameOut = { 0L };
    PyThrowBadEs(acdbGetAdsName(nameIn, id.m_id));
    PyThrowBadRt(acdbEntNext(nameIn, nameOut));
    PyThrowBadEs(acdbGetObjectId(idOut.m_id, nameOut));
    return idOut;
}

bool DbCore::entUpd(const PyDbObjectId& id)
{
    ads_name name = { 0L };
    PyThrowBadEs(acdbGetAdsName(name, id.m_id));
    return acdbEntUpd(name) == RTNORM;
}

void DbCore::fail(const std::string& msg)
{
    acdbFail(utf8_to_wstr(msg).c_str());
}

boost::python::tuple DbCore::findField(const std::string& pszText, int iSearchFrom)
{
    PyAutoLockGIL lock;
    int nStartPos = -1;
    int nEndPos = -1;
    auto flag = acdbFindField(utf8_to_wstr(pszText).c_str(), iSearchFrom, nStartPos, nEndPos);
    return boost::python::make_tuple(flag, nStartPos, nEndPos);
}

void DbCore::forceTextAdjust(const boost::python::list& ids)
{
    auto _ids = PyListToObjectIdArray(ids);
    PyThrowBadEs(acdbForceTextAdjust(_ids));
}

PyDbObjectId DbCore::getCurUserViewportId(PyDbDatabase& db)
{
    PyDbObjectId id;
    PyThrowBadEs(acdbGetCurUserViewportId(db.impObj(), id.m_id));
    return id;
}

PyDbObjectId DbCore::getCurVportId(PyDbDatabase& db)
{
    return PyDbObjectId(acdbGetCurVportId(db.impObj()));
}

PyDbObjectId DbCore::getCurVportTableRecordId(PyDbDatabase& db)
{
    return PyDbObjectId(acdbGetCurVportTableRecordId(db.impObj()));
}

PyDbObjectId DbCore::getDimAssocId(const PyDbObjectId& dimId)
{
    PyDbObjectId id;
    PyThrowBadEs(acdbGetDimAssocId(dimId.m_id, id.m_id));
    return id;
}

boost::python::list DbCore::getDimAssocIds(const PyDbObjectId& dimId)
{
    PyAutoLockGIL lock;
    AcDbObjectIdArray dimAssocIds;
    PyThrowBadEs(acdbGetDimAssocIds(dimId.m_id, dimAssocIds));
    boost::python::list pyIds;
    for (auto item : dimAssocIds)
        pyIds.append(PyDbObjectId(item));
    return pyIds;
}

PyDbObjectId DbCore::getDimStyleId(PyDbDatabase& db, const std::string& styleName, const std::string& lockName)
{
#if _ZRXTARGET == 240 || _GRXTARGET == 240
    throw PyNotimplementedByHost();
#else
    return PyDbObjectId(acdbGetDimStyleId(db.impObj(), utf8_to_wstr(styleName).c_str(), utf8_to_wstr(lockName).c_str()));
#endif
}

PyDbObjectId DbCore::getDynDimStyleId(PyDbDatabase& db)
{
    return PyDbObjectId(acdbGetDynDimStyleId(db.impObj()));
}

boost::python::tuple DbCore::getProxyInfo(const PyDbObject& obj)
{
#if defined(_ARXTARGET) && (_ARXTARGET < 250) || (_ZRXTARGET == 240)  || (_GRXTARGET == 240) 
    PyAutoLockGIL lock;
    RxAutoOutStr dxfName;
    RxAutoOutStr className;
    RxAutoOutStr appName;
    PyThrowBadEs(acdbGetProxyInfo(obj.impObj(), dxfName.buf, className.buf, appName.buf));
    return boost::python::make_tuple(dxfName.str(), className.str(), appName.str());
#else
    PyAutoLockGIL lock;
    AcString dxfName;
    AcString className;
    AcString appName;
    PyThrowBadEs(acdbGetProxyInfo(obj.impObj(), dxfName, className, appName));
    return boost::python::make_tuple(wstr_to_utf8(dxfName), wstr_to_utf8(className), wstr_to_utf8(appName));
#endif
}

std::string DbCore::getMappedFontName(const std::string& fontName)
{
    return wstr_to_utf8(acdbGetMappedFontName(utf8_to_wstr(fontName).c_str()));
}

std::string DbCore::getReservedString(AcDb::reservedStringEnumType reservedType, bool bGetLocalized)
{
    return wstr_to_utf8(acdbGetReservedString(reservedType, bGetLocalized));
}

double DbCore::getUnitsConversion(AcDb::UnitsValue from, AcDb::UnitsValue to)
{
    double d = 0;
    PyThrowBadEs(acdbGetUnitsConversion(from, to, d));
    return d;
}

PyDbObjectId DbCore::getViewportVisualStyle()
{
    return PyDbObjectId(acdbGetViewportVisualStyle());
}

bool DbCore::isReservedString(const std::string& strString, AcDb::reservedStringEnumType reservedType)
{
    return acdbIsReservedString(utf8_to_wstr(strString).c_str(), reservedType);
}

PyDbObjectId DbCore::handEnt(const std::string& handle)
{
    PyDbObjectId id;
    ads_name entres = { 0 };
    acdbHandEnt(utf8_to_wstr(handle).c_str(), entres);
    PyThrowBadEs(acdbGetObjectId(id.m_id, entres));
    return id;
}

AcGePoint3d DbCore::inters(const AcGePoint3d& from1, const AcGePoint3d& to1, const AcGePoint3d& from2, const AcGePoint3d& to2, int teston)
{
    AcGePoint3d result;
    PyThrowBadRt(acdbInters(asDblArray(from1), asDblArray(to1), asDblArray(from2), asDblArray(to2), teston, asDblArray(result)));
    return result;
}

void DbCore::loadLineTypeFile(const std::string& ltname, const std::string& fname, PyDbDatabase& db)
{
    PyThrowBadEs(acdbLoadLineTypeFile(utf8_to_wstr(ltname).c_str(), utf8_to_wstr(fname).c_str(), db.impObj()));
}

void DbCore::loadMlineStyleFile(const std::string& ltname, const std::string& fname)
{
    PyThrowBadEs(acdbLoadMlineStyleFile(utf8_to_wstr(ltname).c_str(), utf8_to_wstr(fname).c_str()));
}

PyDbObjectId DbCore::namedObjDict()
{
    PyDbObjectId id;
    ads_name entres = { 0 };
    PyThrowBadRt(acdbNamedObjDict(entres));
    PyThrowBadEs(acdbGetObjectId(id.m_id, entres));
    return id;
}

PyDbObject DbCore::openDbObject(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
{
    AcDbObject* pObj = nullptr;
    PyThrowBadEs(acdbOpenAcDbObject(pObj, id.m_id, mode, erased));
    return PyDbObject{ pObj, true };
}

boost::python::list DbCore::openDbObjects1(const boost::python::list& ids)
{
    return openDbObjects3(ids, AcDb::kForRead, false);
}

boost::python::list DbCore::openDbObjects2(const boost::python::list& ids, AcDb::OpenMode mode)
{
    return openDbObjects3(ids, mode, false);
}

boost::python::list DbCore::openDbObjects3(const boost::python::list& ids, AcDb::OpenMode mode, bool erased)
{
    PyAutoLockGIL lock;
    boost::python::list pyList;
    for (auto& id : PyListToObjectIdArray(ids))
    {
        AcDbObject* pObj = nullptr;
        PyThrowBadEs(acdbOpenAcDbObject(pObj, id, mode, erased));
        pyList.append(PyDbObject(pObj, true));
    }
    return pyList;
}

PyDbEntity DbCore::openDbEntity(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
{
    if (id.m_id.objectClass()->isDerivedFrom(AcDbEntity::desc()))
    {
        AcDbEntity* pObj = nullptr;
        PyThrowBadEs(acdbOpenAcDbEntity(pObj, id.m_id, mode, erased));
        return PyDbEntity(pObj, true);
    }
    throw PyNotThatKindOfClass();
}

boost::python::list DbCore::openDbEntities1(const boost::python::list& ids)
{
    return openDbEntities3(ids, AcDb::kForRead, false);
}

boost::python::list DbCore::openDbEntities2(const boost::python::list& ids, AcDb::OpenMode mode)
{
    return openDbEntities3(ids, mode, false);
}

boost::python::list DbCore::openDbEntities3(const boost::python::list& ids, AcDb::OpenMode mode, bool erased)
{
    PyAutoLockGIL lock;
    boost::python::list pyList;
    for (auto& id : PyListToObjectIdArray(ids))
    {
        AcDbEntity* pObj = nullptr;
        PyThrowBadEs(acdbOpenAcDbEntity(pObj, id, mode, erased));
        pyList.append(PyDbEntity(pObj, true));
    }
    return pyList;
}

PyDbObjectId DbCore::postDimAssoc1(const PyDbObjectId& dimId, PyDbDimAssoc& assos)
{
    PyDbObjectId outId;
    PyThrowBadEs(acdbPostDimAssoc(dimId.m_id, assos.impObj(), outId.m_id));
    return outId;
}

PyDbObjectId DbCore::postDimAssoc2(const PyDbObjectId& dimId, PyDbDimAssoc& assos, bool isActive)
{
    PyDbObjectId outId;
    PyThrowBadEs(acdbPostDimAssoc(dimId.m_id, assos.impObj(), outId.m_id, isActive));
    return outId;
}

void DbCore::queueAnnotationEntitiesForRegen(PyDbDatabase& db)
{
    PyThrowBadEs(acdbQueueAnnotationEntitiesForRegen(db.impObj()));
}

int DbCore::queueForRegen(const boost::python::list& pyids)
{
    auto ids = PyListToObjectIdArray(pyids);
    return acdbQueueForRegen(ids.asArrayPtr(), ids.length());
}

bool DbCore::regApp(const std::string& app)
{
    return acdbRegApp(utf8_to_wstr(app).c_str()) == RTNORM;
}

std::string DbCore::rtos(double val, int unit, int prec)
{
    std::array<wchar_t, 64> buf = { 0 };
    PyThrowBadRt(acdbRToS(val, unit, prec, buf.data(), buf.size()));
    return wstr_to_utf8(buf.data());
}

void DbCore::updateDimension(const PyDbObjectId& id)
{
    return PyThrowBadEs(acdbUpdateDimension(id.m_id));
}

void DbCore::reloadXrefs1(PyDbDatabase& db, const boost::python::list& ids)
{
    PyThrowBadEs(acdbReloadXrefs(db.impObj(), PyListToObjectIdArray(ids)));
}

void DbCore::reloadXrefs2(PyDbDatabase& db, const boost::python::list& ids, bool bQuiet)
{
    PyThrowBadEs(acdbReloadXrefs(db.impObj(), PyListToObjectIdArray(ids), bQuiet));
}

boost::python::list DbCore::resbufTest(const boost::python::list& list)
{
    AcResBufPtr ptr(listToResbuf(list));
    return resbufToList(ptr.get());
}

bool DbCore::snValid(const std::string& tbstr, int pipeTest)
{
    return acdbSNValid(utf8_to_wstr(tbstr).c_str(), pipeTest) == RTNORM;
}

PyDbSymUtilServices DbCore::symUtil()
{
    return PyDbSymUtilServices();
}

boost::python::list DbCore::tblNext(const std::string& tblname, int rewind)
{
    AcResBufPtr ptr(acdbTblNext(utf8_to_wstr(tblname).c_str(), rewind));
    return resbufToList(ptr.get());
}

PyDbObjectId DbCore::tblObjName(const std::string& tblname, const std::string& sym)
{
    PyDbObjectId id;
    ads_name entres = { 0 };
    acdbTblObjName(utf8_to_wstr(tblname).c_str(), utf8_to_wstr(sym).c_str(), entres);
    PyThrowBadEs(acdbGetObjectId(id.m_id, entres));
    return id;
}

boost::python::list DbCore::tblSearch(const std::string& tblname, const std::string& sym, int setnext)
{
    AcResBufPtr ptr(acdbTblSearch(utf8_to_wstr(tblname).c_str(), utf8_to_wstr(sym).c_str(), setnext));
    return resbufToList(ptr.get());
}

boost::python::list DbCore::textFind1(PyDbDatabase& db, const std::string& findString)
{
    AcDbObjectIdArray resultSet;
    acdbTextFind(db.impObj(), resultSet, utf8_to_wstr(findString).c_str());
    return ObjectIdArrayToPyList(resultSet);
}

boost::python::list DbCore::textFind2(PyDbDatabase& db, const std::string& findString, const std::string& replaceString, Adesk::UInt8 searchOptions, const boost::python::list& selSet)
{
    AcDbObjectIdArray resultSet;
    auto set = PyListToObjectIdArray(selSet);
    acdbTextFind(db.impObj(), resultSet, utf8_to_wstr(findString).c_str(), utf8_to_wstr(replaceString).c_str(), searchOptions, resultSet);
    return ObjectIdArrayToPyList(resultSet);
}

PyDbTransactionManager DbCore::transactionManager()
{
    return PyDbTransactionManager(acdbTransactionManagerPtr());
}

AcGeMatrix3d DbCore::ucsMatrix(PyDbDatabase& db)
{
    AcGeMatrix3d mat;
    if (acdbUcsMatrix(mat, db.impObj()) != true)
        throw PyAcadErrorStatus(eInvalidInput);
    return mat;
}

void DbCore::unloadXrefs1(PyDbDatabase& db, const boost::python::list& xrefBlkIds)
{
    unloadXrefs2(db, xrefBlkIds, true);
}

void DbCore::unloadXrefs2(PyDbDatabase& db, const boost::python::list& xrefBlkIds, bool bQuiet)
{
    auto ids = PyListToObjectIdArray(xrefBlkIds);
    PyThrowBadEs(acdbUnloadXrefs(db.impObj(), ids, bQuiet));
}

PyDbDatabaseSummaryInfo DbCore::getSummaryInfo(PyDbDatabase& db)
{
    AcDbDatabaseSummaryInfo* info = nullptr;
    PyThrowBadEs(acdbGetSummaryInfo(db.impObj(), info));
    return PyDbDatabaseSummaryInfo(info);
}

void DbCore::putSummaryInfo(PyDbDatabaseSummaryInfo& info, PyDbDatabase& db)
{
    PyThrowBadEs(acdbPutSummaryInfo(info.impObj(), db.impObj()));
}

bool DbCore::validateCustomSummaryInfoKey(const std::string& key, PyDbDatabaseSummaryInfo& info)
{
    return acdbValidateCustomSummaryInfoKey(utf8_to_wstr(key).c_str(), info.impObj()) == eOk;
}

bool DbCore::ucs2Wcs1(const AcGePoint3d& p, AcGePoint3d& q)
{
    ads_point pnt;
    bool flag = acdbUcs2Wcs(asDblArray(p), pnt, false);
    q = asPnt3d(pnt);
    return flag;
}

bool DbCore::ucs2Wcs2(const AcGeVector3d& p, AcGeVector3d& q)
{
    ads_point pnt;
    bool flag = acdbUcs2Wcs(asDblArray(p), pnt, true);
    q = asVec3d(pnt);
    return flag;
}

bool DbCore::wcs2Ecs1(const AcGePoint3d& p, const AcGeVector3d& normal, AcGePoint3d& q)
{
    ads_point pnt;
    bool flag = acdbWcs2Ecs(asDblArray(p), pnt, asDblArray(normal), false);
    q = asPnt3d(pnt);
    return flag;
}

bool DbCore::wcs2Ecs2(const AcGeVector3d& p, const AcGeVector3d& normal, AcGeVector3d& q)
{
    ads_point pnt;
    bool flag = acdbWcs2Ecs(asDblArray(p), pnt, asDblArray(normal), true);
    q = asVec3d(pnt);
    return flag;
}

bool DbCore::wcs2Ucs1(const AcGePoint3d& p, AcGePoint3d& q)
{
    ads_point pnt;
    bool flag = acdbWcs2Ucs(asDblArray(p), pnt, false);
    q = asPnt3d(pnt);
    return flag;
}

bool DbCore::wcs2Ucs2(const AcGeVector3d& p, AcGeVector3d& q)
{
    ads_point pnt;
    bool flag = acdbWcs2Ucs(asDblArray(p), pnt, true);
    q = asVec3d(pnt);
    return flag;
}

bool DbCore::ecs2Wcs1(const AcGePoint3d& p, const AcGeVector3d& normal, AcGePoint3d& q)
{
    ads_point pnt;
    bool flag = acdbEcs2Wcs(asDblArray(p), pnt, asDblArray(normal), false);
    q = asPnt3d(pnt);
    return flag;
}

bool DbCore::ecs2Wcs2(const AcGeVector3d& p, const AcGeVector3d& normal, AcGeVector3d& q)
{
    ads_point pnt;
    bool flag = acdbEcs2Wcs(asDblArray(p), pnt, asDblArray(normal), true);
    q = asVec3d(pnt);
    return flag;
}
