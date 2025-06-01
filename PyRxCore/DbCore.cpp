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
#include "dbGeoData.h"

//todo acdbMakeFieldCode

using namespace boost::python;

void makeDbCoreWrapper()
{
    constexpr const std::string_view textFindOverloads = "Overloads:\n"
        "- db: PyDb.Database, findString: str\n"
        "- db: PyDb.Database, findString: str,replaceString: str,searchOptions: int,ids: list[PyDb.ObjectId]\n";

    constexpr const std::string_view evaluateFieldsOverloads = "Overloads:\n"
        "- None: Any\n"
        "- ids: list[PyDb.ObjectId], context: int\n";

    PyDocString DS("Core");
    class_<DbCore>("Core")
        .def(init<>(DS.ARGS()))
        .def("attachPointCloudExEntity", &DbCore::attachPointCloudExEntity,
            DS.SARGS({ "path: str","pos: PyGe.Point3d","scale: float","rotation: float","db: PyDb.Database" }, 2379)).staticmethod("attachPointCloudExEntity")
        .def("activeDatabaseArray", &DbCore::activeDatabaseArray, DS.SARGS(1411)).staticmethod("activeDatabaseArray")
        .def("angToF", &DbCore::angToF, DS.SARGS({ "value:str","unit:int" }, 1432)).staticmethod("angToF")
        .def("angToS", &DbCore::angToS, DS.SARGS({ "value:float","unit:int","prec:int" }, 1433)).staticmethod("angToS")
        .def("assignGelibCurveToAcDbCurve", &DbCore::assignGelibCurveToAcDbCurve1)
        .def("assignGelibCurveToAcDbCurve", &DbCore::assignGelibCurveToAcDbCurve2)
        .def("assignGelibCurveToAcDbCurve", &DbCore::assignGelibCurveToAcDbCurve3,
            DS.SARGS({ "geCurve:PyGe.Curve3d","dbCurve:PyDb.Curve","norm: PyGe.Vector3d=PyGe.Vector3d.kZAxis","tol:PyGe.Tol='tol'" }, 1552)).staticmethod("assignGelibCurveToAcDbCurve")
        .def("attachXref", &DbCore::attachXref, DS.SARGS({ "db: PyDb.Database","fname: str","blkname: str" }, 2380)).staticmethod("attachXref")
        .def("bindXrefs", &DbCore::bindXrefs1)
        .def("bindXrefs", &DbCore::bindXrefs2,
            DS.SARGS({ "db: PyDb.Database","ids: list[PyDb.ObjectId]","bInsertBind: bool","bAllowUnresolved: bool=False","bequite: bool=True" }, 2466)).staticmethod("bindXrefs")
        .def("clearSetupForLayouts", &DbCore::clearSetupForLayouts, DS.SARGS({ "ctxhandle: int" }, 2714)).staticmethod("clearSetupForLayouts")
        .def("convertAcDbCurveToGelibCurve", &DbCore::convertAcDbCurveToGelibCurve1)
        .def("convertAcDbCurveToGelibCurve", &DbCore::convertAcDbCurveToGelibCurve2,
            DS.SARGS({ "geCurve:PyGe.Curve2d","tol:PyGe.Tol='tol'" }, 2752)).staticmethod("convertAcDbCurveToGelibCurve")
        .def("convertGelibCurveToAcDbCurve", &DbCore::convertGelibCurveToAcDbCurve1)
        .def("convertGelibCurveToAcDbCurve", &DbCore::convertGelibCurveToAcDbCurve2)
        .def("convertGelibCurveToAcDbCurve", &DbCore::convertGelibCurveToAcDbCurve3,
            DS.SARGS({ "geCurve:PyGe.Curve3d","norm:PyGe.Vector3d=PyGe.Vector3d.kZAxis","tol:PyGe.Tol='tol'" }, 2754)).staticmethod("convertGelibCurveToAcDbCurve")
        .def("createViewByViewport", &DbCore::createViewByViewport,
            DS.SARGS({ "db: PyDb.Database","vpid: PyDb.ObjectId","name: str","cat: str","labelblock: PyDb.ObjectId" }, 2758)).staticmethod("createViewByViewport")
        .def("canonicalToSystemRange", &DbCore::canonicalToSystemRange, DS.SARGS({ "units: int","val: str" }, 2682)).staticmethod("canonicalToSystemRange")
        .def("detachXref", &DbCore::detachXref, DS.SARGS({ "db: PyDb.Database","xrefid: PyDb.ObjectId" }, 3622)).staticmethod("detachXref")
        .def("dictAdd", &DbCore::dictAdd, DS.SARGS({ "dictname: PyDb.ObjectId","symname: str","newid: PyDb.ObjectId" }, 3736)).staticmethod("dictAdd")
        .def("dictNext", &DbCore::dictNext, DS.SARGS({ "dictname: PyDb.ObjectId","rewind: int" }, 3778)).staticmethod("dictNext")
        .def("dictRemove", &DbCore::dictRemove, DS.SARGS({ "id: PyDb.ObjectId","name: str" }, 3779)).staticmethod("dictRemove")
        .def("dictRename", &DbCore::dictRename, DS.SARGS({ "id: PyDb.ObjectId","name: str","newname: str" }, 3780)).staticmethod("dictRename")
        .def("dictSearch", &DbCore::dictSearch, DS.SARGS({ "id: PyDb.ObjectId","name: str","next: int" }, 3781)).staticmethod("dictSearch")
        .def("displayPreviewFromDwg", &DbCore::displayPreviewFromDwg, DS.SARGS({ "name: str","handle: int" }, 4056)).staticmethod("displayPreviewFromDwg")
        .def("disToF", &DbCore::disToF, DS.SARGS({ "val: str","unit: int" }, 4057)).staticmethod("disToF")
        .def("doSetupForLayouts", &DbCore::doSetupForLayouts, DS.SARGS({ "db: PyDb.Database" }, 4058)).staticmethod("doSetupForLayouts")
        .def("dxfOutAs2000", &DbCore::dxfOutAs2000, DS.SARGS({ "db: PyDb.Database","name: str","precision: int" }, 4187)).staticmethod("dxfOutAs2000")
        .def("dxfOutAs2004", &DbCore::dxfOutAs2004, DS.SARGS({ "db: PyDb.Database","name: str","precision: int" }, 4188)).staticmethod("dxfOutAs2004")
        .def("dxfOutAsR12", &DbCore::dxfOutAsR12, DS.SARGS({ "db: PyDb.Database","name: str","precision: int" }, 4189)).staticmethod("dxfOutAsR12")
        .def("entGet", &DbCore::entGet, DS.SARGS({ "id : PyDb.ObjectId" }, 4268)).staticmethod("entGet")
        .def("entGetX", &DbCore::entGetX1)
        .def("entGetX", &DbCore::entGetX2, DS.SARGS({ "id : PyDb.ObjectId","xdata: list" }, 4269)).staticmethod("entGetX")
        .def("entDel", &DbCore::entDel, DS.SARGS({ "id : PyDb.ObjectId" }, 4267)).staticmethod("entDel")
        .def("entLast", &DbCore::entLast, DS.SARGS(4406)).staticmethod("entLast")
        .def("entMod", &DbCore::entMod, DS.SARGS({ "resultBuffer : list" }, 4409)).staticmethod("entMod")
        .def("entNext", &DbCore::entNext, DS.SARGS({ "id : PyDb.ObjectId" }, 4410)).staticmethod("entNext")
        .def("entUpd", &DbCore::entUpd, DS.SARGS({ "id : PyDb.ObjectId" }, 4411)).staticmethod("entUpd")
        .def("entMake", &DbCore::entMake, DS.SARGS({ "resultBuffer : Collection[tuple[int,Any]]" }, 4407)).staticmethod("entMake")
        .def("entMakeX", &DbCore::entMakeX, DS.SARGS({ "resultBuffer : Collection[tuple[int,Any]]" }, 4408)).staticmethod("entMakeX")
        .def("fail", &DbCore::fail, DS.SARGS({ "msg: str" }, 4584)).staticmethod("fail")
        .def("findField", &DbCore::findField, DS.SARGS({ "val: str","idxfrom: int" }, 4672)).staticmethod("findField")
        .def("forceTextAdjust", &DbCore::forceTextAdjust, DS.SARGS({ "ids: list[PyDb.ObjectId]" }, 4673)).staticmethod("forceTextAdjust")
        .def("getCurUserViewportId", &DbCore::getCurUserViewportId, DS.SARGS({ "db: PyDb.Database" }, 4969)).staticmethod("getCurUserViewportId")
        .def("getCurVportId", &DbCore::getCurVportId, DS.SARGS({ "db: PyDb.Database" }, 4970)).staticmethod("getCurVportId")
        .def("getCurVportTableRecordId", &DbCore::getCurVportTableRecordId, DS.SARGS({ "db: PyDb.Database" }, 4971)).staticmethod("getCurVportTableRecordId")
        .def("getDimAssocId", &DbCore::getDimAssocId, DS.SARGS({ "id: PyDb.ObjectId" }, 4972)).staticmethod("getDimAssocId")
        .def("getDimAssocIds", &DbCore::getDimAssocIds, DS.SARGS({ "id: PyDb.ObjectId" }, 4973)).staticmethod("getDimAssocIds")
        .def("getDimStyleId", &DbCore::getDimStyleId, DS.SARGS({ "db: PyDb.Database","name: str","lockname: str" }, 4982)).staticmethod("getDimStyleId")
        .def("getDynDimStyleId", &DbCore::getDynDimStyleId, DS.SARGS({ "db: PyDb.Database" }, 4985)).staticmethod("getDynDimStyleId")
        .def("getGeoDataObjId", &DbCore::getGeoDataObjId, DS.SARGS({ "db: PyDb.Database" }, 4991)).staticmethod("getGeoDataObjId")
        .def("getProxyInfo", &DbCore::getProxyInfo, DS.SARGS({ "id: PyDb.DbObject" }, 5004)).staticmethod("getProxyInfo")
        .def("getMappedFontName", &DbCore::getMappedFontName, DS.SARGS({ "name: str" }, 4997)).staticmethod("getMappedFontName")
        .def("getReservedString", &DbCore::getReservedString, DS.SARGS({ "reservedType: PyDb.ReservedStringEnumType","bGetLocalized: bool" }, 5005)).staticmethod("getReservedString")
        .def("getUnitsConversion", &DbCore::getUnitsConversion, DS.SARGS({ "ufrom: PyDb.UnitsValue","to: PyDb.UnitsValue" }, 5009)).staticmethod("getUnitsConversion")
        .def("getViewportVisualStyle", &DbCore::getViewportVisualStyle, DS.SARGS(5010)).staticmethod("getViewportVisualStyle")
        .def("hasGeoData", &DbCore::hasGeoData, DS.SARGS({ "db: PyDb.Database" })).staticmethod("hasGeoData")
        .def("handEnt", &DbCore::handEnt, DS.SARGS({ "handle: str" }, 5233)).staticmethod("handEnt")
        .def("isEnabledTightExtents", &DbCore::isEnabledTightExtents, DS.SARGS(5677)).staticmethod("isEnabledTightExtents")
        .def("isReservedString", &DbCore::isReservedString, DS.SARGS({ "val: str","reservedType: PyDb.ReservedStringEnumType" }, 5683)).staticmethod("isReservedString")
        .def("inters", &DbCore::inters, DS.SARGS({ "from1: PyGe.Point3d", "to1: PyGe.Point3d","from2: PyGe.Point3d", "to2: PyGe.Point3d","teston: int" }, 5674)).staticmethod("inters")
        .def("loadLineTypeFile", &DbCore::loadLineTypeFile, DS.SARGS({ "ltname: str","fname: str","db: PyDb.Database" }, 6158)).staticmethod("loadLineTypeFile")
        .def("loadMlineStyleFile", &DbCore::loadMlineStyleFile, DS.SARGS({ "ltname: str","fname: str" }, 6159)).staticmethod("loadMlineStyleFile")
        .def("namedObjDict", &DbCore::namedObjDict, DS.SARGS(6963)).staticmethod("namedObjDict")
        .def("openDbObject", &DbCore::openDbObject,
            DS.SARGS({ "id: PyDb.ObjectId", "mode: PyDb.OpenMode = PyDb.OpenMode.kForRead", "erased: bool=False" }, 7322)).staticmethod("openDbObject")
        .def("openDbObjects", &DbCore::openDbObjects1)
        .def("openDbObjects", &DbCore::openDbObjects2)
        .def("openDbObjects", &DbCore::openDbObjects3,
            DS.SARGS({ "ids: list[PyDb.ObjectId]", "mode: PyDb.OpenMode = PyDb.OpenMode.kForRead", "erased: bool=False" }, 7322)).staticmethod("openDbObjects")
        .def("openDbEntity", &DbCore::openDbEntity,
            DS.SARGS({ "id: PyDb.ObjectId", "mode: PyDb.OpenMode = PyDb.OpenMode.kForRead", "erased: bool=False" }, 7321)).staticmethod("openDbEntity")
        .def("openDbEntities", &DbCore::openDbEntities1)
        .def("openDbEntities", &DbCore::openDbEntities2)
        .def("openDbEntities", &DbCore::openDbEntities3,
            DS.SARGS({ "ids: list[PyDb.ObjectId]", "mode: PyDb.OpenMode = PyDb.OpenMode.kForRead", "erased: bool=False" }, 7321)).staticmethod("openDbEntities")
        .def("postDimAssoc", &DbCore::postDimAssoc1)
        .def("postDimAssoc", &DbCore::postDimAssoc2,
            DS.SARGS({ "dimId: PyDb.ObjectId","assoc: PyDb.DimAssoc","isActive: bool=True" }, 7867)).staticmethod("postDimAssoc")
        .def("queueAnnotationEntitiesForRegen", &DbCore::queueAnnotationEntitiesForRegen, DS.SARGS({ "db: PyDb.Database" }, 7894)).staticmethod("queueAnnotationEntitiesForRegen")
        .def("queueForRegen", &DbCore::queueForRegen, DS.SARGS({ "ids: list[PyDb.ObjectId]" }, 7895)).staticmethod("queueForRegen")
        .def("regApp", &DbCore::regApp, DS.SARGS({ "val: str" }, 8140)).staticmethod("regApp")
        .def("reloadXrefs", &DbCore::reloadXrefs1)
        .def("reloadXrefs", &DbCore::reloadXrefs2, DS.SARGS({ "db: PyDb.Database","ids: list[PyDb.ObjectId]","bQuiet: bool=True" }, 8177)).staticmethod("reloadXrefs")
        .def("rtos", &DbCore::rtos, DS.SARGS({ "val: float","unit: int","prec: int" }, 8318)).staticmethod("rtos")
        .def("setEnableTightExtents", &DbCore::setEnableTightExtents, DS.SARGS({ "val: bool" }, 8572)).staticmethod("setEnableTightExtents")
        .def("snValid", &DbCore::snValid, DS.SARGS({ "val: str","pipetest: int" }, 8640)).staticmethod("snValid")
        .def("symUtil", &DbCore::symUtil, DS.SARGS(9145)).staticmethod("symUtil")
        .def("tblNext", &DbCore::tblNext, DS.SARGS({ "name: str","rewind: int" }, 9450)).staticmethod("tblNext")
        .def("tblObjName", &DbCore::tblObjName, DS.SARGS({ "tblname: str","sym: str" }, 9451)).staticmethod("tblObjName")
        .def("tblSearch", &DbCore::tblSearch, DS.SARGS({ "tblname: str","sym: str","setnext: int" }, 9452)).staticmethod("tblSearch")
        .def("textFind", &DbCore::textFind1)
        .def("textFind", &DbCore::textFind2, DS.SOVRL(textFindOverloads, 9686)).staticmethod("textFind")
        .def("transactionManager", &DbCore::transactionManager, DS.SARGS(9784)).staticmethod("transactionManager")
        .def("ucsMatrix", &DbCore::ucsMatrix1)
        .def("ucsMatrix", &DbCore::ucsMatrix2, DS.SARGS({ "db: PyDb.Database = ..." }, 9808)).staticmethod("ucsMatrix")
        .def("unloadXrefs", &DbCore::unloadXrefs1)
        .def("unloadXrefs", &DbCore::unloadXrefs2,
            DS.SARGS({ "db: PyDb.Database","ids: list[PyDb.ObjectId]","bequiet: bool=True" }, 9915)).staticmethod("unloadXrefs")
        .def("getSummaryInfo", &DbCore::getSummaryInfo,
            DS.SARGS({ "db: PyDb.Database" }, 5007)).staticmethod("getSummaryInfo")
        .def("putSummaryInfo", &DbCore::putSummaryInfo,
            DS.SARGS({ "info: PyDb.DatabaseSummaryInfo","db: PyDb.Database" }, 7893)).staticmethod("putSummaryInfo")
        .def("updateDimension", &DbCore::updateDimension,
            DS.SARGS({ "id: PyDb.ObjectId" }, 9916)).staticmethod("updateDimension")
        .def("validateCustomSummaryInfoKey", &DbCore::validateCustomSummaryInfoKey
            , DS.SARGS({ "val: str","info: PyDb.DatabaseSummaryInfo" }, 9917)).staticmethod("validateCustomSummaryInfoKey")
        .def("ucs2Wcs", &DbCore::ucs2Wcs1)
        .def("ucs2Wcs", &DbCore::ucs2Wcs2,
            DS.SARGS({ "p: PyGe.Point3d|PyGe.Vector3d","qout: PyGe.Point3d|PyGe.Vector3d" }, 9807)).staticmethod("ucs2Wcs")
        .def("wcs2Ecs", &DbCore::wcs2Ecs1)
        .def("wcs2Ecs", &DbCore::wcs2Ecs2,
            DS.SARGS({ "p: PyGe.Point3d|PyGe.Vector3d", "normal: PyGe.Vector3d","qout: PyGe.Point3d|PyGe.Vector3d" }, 10296)).staticmethod("wcs2Ecs")
        .def("wcs2Ucs", &DbCore::wcs2Ucs1)
        .def("wcs2Ucs", &DbCore::wcs2Ucs2,
            DS.SARGS({ "p: PyGe.Point3d|PyGe.Vector3d","qout: PyGe.Point3d|PyGe.Vector3d" }, 10297)).staticmethod("wcs2Ucs")
        .def("ecs2Wcs", &DbCore::ecs2Wcs1)
        .def("ecs2Wcs", &DbCore::ecs2Wcs2,
            DS.SARGS({ "p: PyGe.Point3d|PyGe.Vector3d", "normal: PyGe.Vector3d","qout: PyGe.Point3d|PyGe.Vector3d" }, 4227)).staticmethod("ecs2Wcs")
        .def("evaluateFields", &DbCore::evaluateFields1)
        .def("evaluateFields", &DbCore::evaluateFields2, DS.SOVRL(evaluateFieldsOverloads, 4505)).staticmethod("evaluateFields")
        .def("resolveCurrentXRefs", &DbCore::resolveCurrentXRefs, DS.SARGS({ "db: PyDb.Database","useThreadEngine: bool","doNewOnly: bool" })).staticmethod("resolveCurrentXRefs")
        .def("resbufTest", &DbCore::resbufTest, DS.SARGS({ "resultBuffer: list" })).staticmethod("resbufTest")
        .def("stringTest", &DbCore::stringTest, DS.SARGS({ "val: str" })).staticmethod("stringTest")
        .def("stringtolower", &DbCore::stringtolower, DS.SARGS({ "val: str" })).staticmethod("stringtolower")
        .def("stringtoupper", &DbCore::stringtoupper, DS.SARGS({ "val: str" })).staticmethod("stringtoupper")
        .def("icompare", &DbCore::icompare, DS.SARGS({ "left: str","right: str" })).staticmethod("icompare")
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
#if defined(_ARXTARGET) && _ARXTARGET >= 243
    AcString buf;
    PyThrowBadRt(acdbAngToS(val, buf, unit, prec));
    return wstr_to_utf8(buf);
#else
    std::wstring buf(64, 0);
    PyThrowBadRt(acdbAngToS(val, unit, prec, buf.data(), buf.size()));
    return wstr_to_utf8(buf.data());
#endif
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

PyDbObjectId DbCore::attachXref(PyDbDatabase& pHostDb, const std::string& pFilename, const std::string& pBlockName)
{
    PyDbObjectId xrefBlkId;
    PyThrowBadEs(acdbAttachXref(pHostDb.impObj(), utf8_to_wstr(pFilename).c_str(), utf8_to_wstr(pBlockName).c_str(), xrefBlkId.m_id));
    return xrefBlkId;
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
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(acdbClearSetupForLayouts(contextHandle));
#endif
}

PyGeCurve3d DbCore::convertAcDbCurveToGelibCurve1(const PyDbCurve& dbCurve)
{
    AcGeCurve3d* pcurve = nullptr;
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
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    PyDbObjectId view;
    PyThrowBadEs(acdbCreateViewByViewport(pDb.impObj(), viewportId.m_id, utf8_to_wstr(name).c_str(), utf8_to_wstr(categoryName).c_str(), labelBlockId.m_id, view.m_id));
    return view;
#endif
}

std::string DbCore::canonicalToSystemRange(int eUnits, const std::string& strIn)
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    AcString strOut;
    acdbCanonicalToSystemRange(eUnits, utf8_to_wstr(strIn).c_str(), strOut);
    return wstr_to_utf8(strOut);
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
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    Adesk::ULongPtr contextHandle = 0;
    PyThrowBadEs(acdbDoSetupForLayouts(pDatabase.impObj(), contextHandle));
    return contextHandle;
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

bool DbCore::entMake(const boost::python::object& rb)
{
    AcResBufPtr pBuf(listToResbuf(rb));
    return acdbEntMake(pBuf.get()) == RTNORM;
}

PyDbObjectId DbCore::entMakeX(const boost::python::object& rb)
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
        throw PyErrorStatusException(eInvalidInput);
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
        throw PyErrorStatusException(eInvalidInput);
    return resbufToList(ptr.get());
}

boost::python::list DbCore::entGetX2(const PyDbObjectId& id, const boost::python::list& rb)
{
    ads_name name = { 0L };
    PyThrowBadEs(acdbGetAdsName(name, id.m_id));
    AcResBufPtr rbIn(listToResbuf(rb));
    AcResBufPtr ptr(acdbEntGetX(name, rbIn.get()));
    if (ptr == nullptr)
        throw PyErrorStatusException(eInvalidInput);
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
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    PyAutoLockGIL lock;
    int nStartPos = -1;
    int nEndPos = -1;
    auto flag = acdbFindField(utf8_to_wstr(pszText).c_str(), iSearchFrom, nStartPos, nEndPos);
    return boost::python::make_tuple(flag, nStartPos, nEndPos);
#endif
}

void DbCore::forceTextAdjust(const boost::python::list& ids)
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    auto _ids = PyListToObjectIdArray(ids);
    PyThrowBadEs(acdbForceTextAdjust(_ids));
#endif
}

PyDbObjectId DbCore::getCurUserViewportId(PyDbDatabase& db)
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    PyDbObjectId id;
    PyThrowBadEs(acdbGetCurUserViewportId(db.impObj(), id.m_id));
    return id;
#endif
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
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    PyAutoLockGIL lock;
    AcDbObjectIdArray dimAssocIds;
    PyThrowBadEs(acdbGetDimAssocIds(dimId.m_id, dimAssocIds));
    boost::python::list pyIds;
    for (auto item : dimAssocIds)
        pyIds.append(PyDbObjectId(item));
    return pyIds;
#endif
}

PyDbObjectId DbCore::getDimStyleId(PyDbDatabase& db, const std::string& styleName, const std::string& lockName)
{
#if defined (_ZRXTARGET) && _ZRXTARGET <= 250 || defined (_GRXTARGET) && _GRXTARGET <= 250  || defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyDbObjectId(acdbGetDimStyleId(db.impObj(), utf8_to_wstr(styleName).c_str(), utf8_to_wstr(lockName).c_str()));
#endif
}

PyDbObjectId DbCore::getDynDimStyleId(PyDbDatabase& db)
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyDbObjectId(acdbGetDynDimStyleId(db.impObj()));
#endif
}

PyDbObjectId DbCore::getGeoDataObjId(PyDbDatabase& db)
{
    PyDbObjectId id;
    PyThrowBadEs(acdbGetGeoDataObjId(db.impObj(), id.m_id));
    return id;
}

bool DbCore::hasGeoData(PyDbDatabase& db)
{
    PyDbObjectId id;
    return acdbGetGeoDataObjId(db.impObj(), id.m_id) == eOk;
}

boost::python::tuple DbCore::getProxyInfo(const PyDbObject& obj)
{
    PyAutoLockGIL lock;
#if defined(_ARXTARGET240) || defined(_ZRXTARGET260) || defined(_GRXTARGET250) || defined(_BRXTARGET250) 
    RxAutoOutStr dxfName;
    RxAutoOutStr className;
    RxAutoOutStr appName;
    PyThrowBadEs(acdbGetProxyInfo(obj.impObj(), dxfName.buf, className.buf, appName.buf));
    return boost::python::make_tuple(dxfName.str(), className.str(), appName.str());
#else
    AcString dxfName;
    AcString className;
    AcString appName;
    PyThrowBadEs(acdbGetProxyInfo(obj.impObj(), dxfName, className, appName));
    return boost::python::make_tuple(wstr_to_utf8(dxfName), wstr_to_utf8(className), wstr_to_utf8(appName));
#endif
}

std::string DbCore::getMappedFontName(const std::string& fontName)
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return wstr_to_utf8(acdbGetMappedFontName(utf8_to_wstr(fontName).c_str()));
#endif
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

bool DbCore::isEnabledTightExtents()
{
#if defined(_ARXTARGET) && _ARXTARGET >= 243
    return acdbIsEnabledTightExtents();
#else
    throw PyNotimplementedByHost();
#endif
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
    throw PyErrorStatusException(eNotThatKindOfClass);
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
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(acdbQueueAnnotationEntitiesForRegen(db.impObj()));
#endif
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

//TODO make test class 
boost::python::list DbCore::resbufTest(const boost::python::list& list)
{
    AcResBufPtr ptr(listToResbuf(list));
    return resbufToList(ptr.get());
}

std::string DbCore::stringTest(const std::string& val)
{
    return wstr_to_utf8(utf8_to_wstr(val));
}

std::string DbCore::stringtolower(const std::string& val)
{
    return wstr_to_utf8(towlower(utf8_to_wstr(val)));
}

std::string DbCore::stringtoupper(const std::string& val)
{
    return wstr_to_utf8(towupper(utf8_to_wstr(val)));
}

bool DbCore::icompare(const std::string& left, const std::string& right)
{
    return iCompare(utf8_to_wstr(left), utf8_to_wstr(right));
}

void DbCore::setEnableTightExtents(bool bEnable)
{
#if defined(_ARXTARGET) && _ARXTARGET >= 243
    acdbSetEnableTightExtents(bEnable);
#else
    throw PyNotimplementedByHost();
#endif
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
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    AcDbObjectIdArray resultSet;
    acdbTextFind(db.impObj(), resultSet, utf8_to_wstr(findString).c_str());
    return ObjectIdArrayToPyList(resultSet);
#endif
}

boost::python::list DbCore::textFind2(PyDbDatabase& db, const std::string& findString, const std::string& replaceString, Adesk::UInt8 searchOptions, const boost::python::list& selSet)
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    AcDbObjectIdArray resultSet;
    auto set = PyListToObjectIdArray(selSet);
    acdbTextFind(db.impObj(), resultSet, utf8_to_wstr(findString).c_str(), utf8_to_wstr(replaceString).c_str(), searchOptions, resultSet);
    return ObjectIdArrayToPyList(resultSet);
#endif
}

PyDbTransactionManager DbCore::transactionManager()
{
    return PyDbTransactionManager(acdbTransactionManagerPtr());
}

AcGeMatrix3d DbCore::ucsMatrix1()
{
    AcGeMatrix3d mat;
    if (acdbUcsMatrix(mat) != true)
        throw PyErrorStatusException(eInvalidInput);
    return mat;
}

AcGeMatrix3d DbCore::ucsMatrix2(PyDbDatabase& db)
{
    AcGeMatrix3d mat;
    if (acdbUcsMatrix(mat, db.impObj()) != true)
        throw PyErrorStatusException(eInvalidInput);
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
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return acdbValidateCustomSummaryInfoKey(utf8_to_wstr(key).c_str(), info.impObj()) == eOk;
#endif
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

static Acad::ErrorStatus getIdsFromAcDbFieldList(const AcDbObjectId& fieldListId, AcDbObjectIdArray& fids)
{
    ads_name fdname = { 0L, 0L };
    if (auto stat = acdbGetAdsName(fdname, fieldListId); stat != eOk)
        return stat;
    AcResBufPtr pHead(acdbEntGet(fdname));
    for (resbuf* pTail = pHead.get(); pTail != nullptr; pTail = pTail->rbnext)
    {
        if (AcDbObjectId fId; pTail->restype == AcDb::kDxfSoftPointerId &&
            acdbGetObjectId(fId, pTail->resval.rlname) == eOk)
        {
            if (fId.objectClass()->isDerivedFrom(AcDbField::desc()))
                fids.append(fId);
        }
    }
    return eOk;
}

static Acad::ErrorStatus getFieldIds(AcDbObjectIdArray& fids, AcDbDatabase* db)
{
    if (db == nullptr)
        return Acad::eNullPtr;
    if (AcDbDictionaryPointer pNod(db->namedObjectsDictionaryId()); pNod.openStatus() == eOk &&
        pNod->has(_T("ACAD_FIELDLIST")))
    {
        AcDbObjectId fieldListId;
        if (auto stat = pNod->getAt(_T("ACAD_FIELDLIST"), fieldListId); stat != eOk)
            return stat;
        return getIdsFromAcDbFieldList(fieldListId, fids);
    }
    return eInvalidInput;
}

Acad::ErrorStatus DbCore::evaluateFields1()
{
    auto db = acdbCurDwg();
    AcDbObjectIdArray ids;
    getFieldIds(ids, db);
    return acdbEvaluateFields(ids, 32);
}

Acad::ErrorStatus DbCore::evaluateFields2(const boost::python::object& ids, int context)
{
    return acdbEvaluateFields(PyListToObjectIdArray(ids), context);
}

void DbCore::resolveCurrentXRefs(const PyDbDatabase& db, bool useThreadEngine, bool doNewOnly)
{
    PyThrowBadEs(acdbResolveCurrentXRefs(db.impObj(), useThreadEngine, doNewOnly));
}
