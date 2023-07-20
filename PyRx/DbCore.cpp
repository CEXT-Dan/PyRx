#include "stdafx.h"
#include "DbCore.h"
#include "PyDbObjectId.h"
#include "PyDbEntity.h"
#include "dbdimassoc.h"
#include "ResultBuffer.h"
#include "PyDbDatabase.h"
#include "PyGeCurve3d.h"
#include "PyDbCurve.h"

using namespace boost::python;

void makeDbCoreWrapper()
{
    class_<DbCore>("Core")
        .def("activeDatabaseArray", &DbCore::activeDatabaseArray).staticmethod("activeDatabaseArray")
        .def("angToF", &DbCore::angToF).staticmethod("angToF")
        .def("angToS", &DbCore::angToS).staticmethod("angToS")
        .def("assignGelibCurveToAcDbCurve", &DbCore::assignGelibCurveToAcDbCurve1)
        .def("assignGelibCurveToAcDbCurve", &DbCore::assignGelibCurveToAcDbCurve2)
        .def("assignGelibCurveToAcDbCurve", &DbCore::assignGelibCurveToAcDbCurve3).staticmethod("assignGelibCurveToAcDbCurve")
        .def("attachXref", &DbCore::attachXref).staticmethod("attachXref")
        .def("bindXrefs", &DbCore::bindXrefs1)
        .def("bindXrefs", &DbCore::bindXrefs2).staticmethod("bindXrefs")
        .def("clearSetupForLayouts", &DbCore::clearSetupForLayouts).staticmethod("clearSetupForLayouts")
        .def("convertAcDbCurveToGelibCurve", &DbCore::convertAcDbCurveToGelibCurve1)
        .def("convertAcDbCurveToGelibCurve", &DbCore::convertAcDbCurveToGelibCurve2).staticmethod("convertAcDbCurveToGelibCurve")
        .def("convertGelibCurveToAcDbCurve", &DbCore::convertGelibCurveToAcDbCurve1)
        .def("convertGelibCurveToAcDbCurve", &DbCore::convertGelibCurveToAcDbCurve2)
        .def("convertGelibCurveToAcDbCurve", &DbCore::convertGelibCurveToAcDbCurve3).staticmethod("convertGelibCurveToAcDbCurve")
        .def("createViewByViewport", &DbCore::createViewByViewport).staticmethod("createViewByViewport")
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
        .def("entGet", &DbCore::entGet).staticmethod("entGet")
        .def("entDel", &DbCore::entDel).staticmethod("entDel")
        .def("entLast", &DbCore::entLast).staticmethod("entLast")
        .def("entMod", &DbCore::entMod).staticmethod("entMod")
        .def("entNext", &DbCore::entNext).staticmethod("entNext")
        .def("entUpd", &DbCore::entUpd).staticmethod("entUpd")
        .def("entMake", &DbCore::entMake).staticmethod("entMake")
        .def("entMakeX", &DbCore::entMakeX).staticmethod("entMakeX")


        .def("openDbObject", &DbCore::openDbObject).staticmethod("openDbObject")
        .def("openDbEntity", &DbCore::openDbEntity).staticmethod("openDbEntity")
        .def("regApp", &DbCore::regApp).staticmethod("regApp")
        .def("updateDimension", &DbCore::updateDimension).staticmethod("updateDimension")
        .def("resbufTest", &DbCore::resbufTest).staticmethod("resbufTest")
        .def("ucs2Wcs", &DbCore::ucs2Wcs1)
        .def("ucs2Wcs", &DbCore::ucs2Wcs2).staticmethod("ucs2Wcs")
        .def("wcs2Ecs", &DbCore::wcs2Ecs1)
        .def("wcs2Ecs", &DbCore::wcs2Ecs2).staticmethod("wcs2Ecs")
        .def("ucs2Ucs", &DbCore::ucs2Ucs1)
        .def("ucs2Ucs", &DbCore::ucs2Ucs2).staticmethod("ucs2Ucs")
        .def("ecs2Wcs", &DbCore::ecs2Wcs1)
        .def("ecs2Wcs", &DbCore::ecs2Wcs2).staticmethod("ecs2Wcs")
        ;
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
    std::array<wchar_t, 24> buf = { 0 };
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
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    auto ids = PyListToObjectIdArray(xrefBlkIds);
    return PyThrowBadEs(acdbBindXrefs(pHostDb.impObj(), ids, bInsertBind));
#endif
}

void DbCore::bindXrefs2(PyDbDatabase& pHostDb, const boost::python::list& xrefBlkIds, const bool bInsertBind, const bool bAllowUnresolved, const bool bQuiet)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    auto ids = PyListToObjectIdArray(xrefBlkIds);
    return PyThrowBadEs(acdbBindXrefs(pHostDb.impObj(), ids, bInsertBind, bAllowUnresolved, bQuiet));
#endif
}

void DbCore::clearSetupForLayouts(UINT_PTR contextHandle)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(acdbClearSetupForLayouts(contextHandle));
#endif
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
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    PyDbObjectId view;
    PyThrowBadEs(acdbCreateViewByViewport(pDb.impObj(), viewportId.m_id, utf8_to_wstr(name).c_str(), utf8_to_wstr(categoryName).c_str(), labelBlockId.m_id, view.m_id));
    return view;
#endif
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
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    Adesk::ULongPtr contextHandle = 0;
    PyThrowBadEs(acdbDoSetupForLayouts(pDatabase.impObj(), contextHandle));
    return contextHandle;
#endif
}

bool DbCore::dwkFileExists(const std::string& pszDwgfilename)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return acdbDwkFileExists(utf8_to_wstr(pszDwgfilename).c_str());
#endif
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

PyDbObject DbCore::openDbObject(const PyDbObjectId& id, AcDb::OpenMode mode)
{
    AcDbObject* pObj = nullptr;
    PyThrowBadEs(acdbOpenAcDbObject(pObj, id.m_id, mode));
    return PyDbObject{ pObj, true };
}

PyDbEntity DbCore::openDbEntity(const PyDbObjectId& id, AcDb::OpenMode mode)
{
    if (id.m_id.objectClass()->isDerivedFrom(AcDbEntity::desc()))
    {
        AcDbEntity* pObj = nullptr;
        PyThrowBadEs(acdbOpenAcDbEntity(pObj, id.m_id, mode));
        return PyDbEntity(pObj, true);
    }
    throw PyNotThatKindOfClass();
}

bool DbCore::regApp(const std::string& app)
{
    return acdbRegApp(utf8_to_wstr(app).c_str()) == RTNORM;
}

void DbCore::updateDimension(const PyDbObjectId& id)
{
    return PyThrowBadEs(acdbUpdateDimension(id.m_id));
}

boost::python::list DbCore::resbufTest(const boost::python::list& list)
{
    AcResBufPtr ptr(listToResbuf(list));
    return resbufToList(ptr.get());
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

bool DbCore::ucs2Ucs1(const AcGePoint3d& p, AcGePoint3d& q)
{
    ads_point pnt;
    bool flag = acdbWcs2Ucs(asDblArray(p), pnt, false);
    q = asPnt3d(pnt);
    return flag;
}

bool DbCore::ucs2Ucs2(const AcGeVector3d& p, AcGeVector3d& q)
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
