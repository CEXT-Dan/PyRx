#pragma once

class PyDbObject;
class PyDbObjectId;
class PyDbEntity;
class PyGeCurve3d;
class PyDbCurve;
class PyDbDatabase;
class PyDbDatabaseSummaryInfo;
class PyDbSymUtilServices;

void makeDbCoreWrapper();

class DbCore
{
public:
    static boost::python::list  activeDatabaseArray();
    static double               angToF(const std::string& str, int unit);
    static std::string          angToS(double, int unit, int prec);
    static void                 assignGelibCurveToAcDbCurve1(const PyGeCurve3d& geCurve, PyDbCurve& pDbCurve);
    static void                 assignGelibCurveToAcDbCurve2(const PyGeCurve3d& geCurve, PyDbCurve& pDbCurve, AcGeVector3d& normal);
    static void                 assignGelibCurveToAcDbCurve3(const PyGeCurve3d& geCurve, PyDbCurve& pDbCurve, AcGeVector3d& normal, const AcGeTol& tol);
    static void                 attachXref(PyDbDatabase& pHostDb, const std::string& pFilename, const std::string& pBlockName, PyDbObjectId& xrefBlkId);
    static void                 bindXrefs1(PyDbDatabase& pHostDb, const boost::python::list& xrefBlkIds, const bool bInsertBind);
    static void                 bindXrefs2(PyDbDatabase& pHostDb, const boost::python::list& xrefBlkIds, const bool bInsertBind, const bool bAllowUnresolved, const bool bQuiet);
    static void                 clearSetupForLayouts(UINT_PTR contextHandle);
    static PyGeCurve3d          convertAcDbCurveToGelibCurve1(const PyDbCurve& dbCurve);
    static PyGeCurve3d          convertAcDbCurveToGelibCurve2(const PyDbCurve& dbCurve, const AcGeTol& tol);
    static PyDbCurve            convertGelibCurveToAcDbCurve1(const PyGeCurve3d& geCurve);
    static PyDbCurve            convertGelibCurveToAcDbCurve2(const PyGeCurve3d& geCurve, AcGeVector3d& normal);
    static PyDbCurve            convertGelibCurveToAcDbCurve3(const PyGeCurve3d& geCurve, AcGeVector3d& normal, const AcGeTol& tol);
    static PyDbObjectId         createViewByViewport(PyDbDatabase& pDb, const PyDbObjectId& viewportId, const std::string& name, const std::string& categoryName, const PyDbObjectId& labelBlockId);
    static void                 detachXref(PyDbDatabase& pHostDb, const PyDbObjectId& xrefBlkId);
    static bool                 dictAdd(const PyDbObjectId& dictname, const std::string& symname, const PyDbObjectId& newobj);
    static boost::python::list  dictNext(const PyDbObjectId& dictname, int rewind);
    static bool                 dictRemove(const PyDbObjectId& dictname, const std::string& symname);
    static bool                 dictRename(const PyDbObjectId& dictname, const std::string& symname, const std::string& newsym);
    static boost::python::list  dictSearch(const PyDbObjectId& dictname, const std::string& symname, int setnext);
    static bool                 displayPreviewFromDwg(const std::string& pszDwgfilename, UINT_PTR hwnd);
    static double               disToF(const std::string& str, int unit);
    static UINT_PTR             doSetupForLayouts(PyDbDatabase& pDatabase);
    static bool                 dwkFileExists(const std::string& pszDwgfilename);
    static void                 dxfOutAs2000(PyDbDatabase& pDb, const std::string& fileName, int precision);
    static void                 dxfOutAs2004(PyDbDatabase& pDb, const std::string& fileName, int precision);
    static void                 dxfOutAsR12(PyDbDatabase& pDb, const std::string& fileName, int precision);
    static bool                 entMake(const boost::python::list& rb);
    static PyDbObjectId         entMakeX(const boost::python::list& rb);

    static bool                 entDel(const PyDbObjectId& id);
    static boost::python::list  entGet(const PyDbObjectId& id);
    static boost::python::list  entGetX1(const PyDbObjectId& id);
    static boost::python::list  entGetX2(const PyDbObjectId& id, const boost::python::list& rb);
    static PyDbObjectId         entLast();
    static bool                 entMod(const boost::python::list& list);
    static PyDbObjectId         entNext(const PyDbObjectId& id);
    static bool                 entUpd(const PyDbObjectId& id);
    static void                 fail(const std::string& msg);
    static boost::python::tuple findField(const std::string& pszText, int iSearchFrom);
    static void                 forceTextAdjust(const boost::python::list& ids);
    static PyDbObjectId         getCurUserViewportId(PyDbDatabase& db);
    static PyDbObjectId         getCurVportId(PyDbDatabase& db);
    static PyDbObjectId         getCurVportTableRecordId(PyDbDatabase& db);
    static PyDbObjectId         getDimAssocId(const PyDbObjectId& dimId);
    static boost::python::list  getDimAssocIds(const PyDbObjectId& id);
    static std::string          getMappedFontName(const std::string& fontName);
    static std::string          getReservedString(AcDb::reservedStringEnumType reservedType, bool bGetLocalized);
    static double               getUnitsConversion(AcDb::UnitsValue from, AcDb::UnitsValue to);
    static PyDbObjectId         getViewportVisualStyle();
    static PyDbObjectId         handEnt(const std::string& handle);

    static bool                 isReservedString(const std::string& strString, AcDb::reservedStringEnumType reservedType);
    static AcGePoint3d          inters(const AcGePoint3d& from1, const AcGePoint3d& to1, const AcGePoint3d& from2, const AcGePoint3d& to2, int teston);
    static void                 loadLineTypeFile(const std::string& ltname, const std::string& fname, PyDbDatabase& db);
    static void                 loadMlineStyleFile(const std::string& ltname, const std::string& fname);
    static PyDbObjectId         namedObjDict();

    static PyDbObject           openDbObject(const PyDbObjectId& id, AcDb::OpenMode mode);
    static PyDbEntity           openDbEntity(const PyDbObjectId& id, AcDb::OpenMode mode);

    static void                 queueAnnotationEntitiesForRegen(PyDbDatabase& db);
    static int                  queueForRegen(const boost::python::list& pyids);

    static bool                 regApp(const std::string& app);
    static std::string          rtos(double, int unit, int prec);

    static void                 updateDimension(const PyDbObjectId& id);
    static boost::python::list  resbufTest(const boost::python::list& list);

    static bool                 snValid(const std::string& tbstr, int pipeTest);
    static PyDbSymUtilServices  symUtil();

    static boost::python::list  tblNext(const std::string& tblname, int rewind);
    static PyDbObjectId         tblObjName(const std::string& tblname, const std::string& sym);
    static boost::python::list  tblSearch(const std::string& tblname, const std::string& sym, int setnext);

    static boost::python::list  textFind1(PyDbDatabase& db, const std::string& findString);
    static boost::python::list  textFind2(PyDbDatabase& db, const std::string& findString, const std::string& replaceString, Adesk::UInt8 searchOptions, const boost::python::list& selSet);

    static PyDbDatabaseSummaryInfo getSummaryInfo(PyDbDatabase& db);
    static void                 putSummaryInfo(PyDbDatabaseSummaryInfo& info, PyDbDatabase& db);
    static bool                 validateCustomSummaryInfoKey(const std::string& key, PyDbDatabaseSummaryInfo& info);
    static bool                 ucs2Wcs1(const AcGePoint3d& p, AcGePoint3d& q);
    static bool                 ucs2Wcs2(const AcGeVector3d& p, AcGeVector3d& q);
    static bool                 wcs2Ecs1(const AcGePoint3d& p, const AcGeVector3d& normal, AcGePoint3d& q);
    static bool                 wcs2Ecs2(const AcGeVector3d& p, const AcGeVector3d& normal, AcGeVector3d& q);
    static bool                 ucs2Ucs1(const AcGePoint3d& p, AcGePoint3d& q);
    static bool                 ucs2Ucs2(const AcGeVector3d& p, AcGeVector3d& q);
    static bool                 ecs2Wcs1(const AcGePoint3d& p, const AcGeVector3d& normal, AcGePoint3d& q);
    static bool                 ecs2Wcs2(const AcGeVector3d& p, const AcGeVector3d& normal, AcGeVector3d& q);
};

