#pragma once

class PyDbObject;
class PyDbObjectId;
class PyDbEntity;
class PyGeCurve3d;
class PyDbCurve;
class PyDbDatabase;

void makeDbCoreWrapper();

class DbCore
{
public:
    static boost::python::list  activeDatabaseArray();
    static double               angToF(const std::string& str, int unit);
    static std::string          angToS(double, int unit, int prec);
    static Acad::ErrorStatus    assignGelibCurveToAcDbCurve1(const PyGeCurve3d& geCurve, PyDbCurve& pDbCurve);
    static Acad::ErrorStatus    assignGelibCurveToAcDbCurve2(const PyGeCurve3d& geCurve, PyDbCurve& pDbCurve, AcGeVector3d& normal);
    static Acad::ErrorStatus    assignGelibCurveToAcDbCurve3(const PyGeCurve3d& geCurve, PyDbCurve& pDbCurve, AcGeVector3d& normal, const AcGeTol& tol);
    static Acad::ErrorStatus    attachXref(PyDbDatabase& pHostDb, const std::string& pFilename, const std::string& pBlockName, PyDbObjectId& xrefBlkId);
    static Acad::ErrorStatus    bindXrefs1(PyDbDatabase& pHostDb, const boost::python::list xrefBlkIds, const bool bInsertBind);
    static Acad::ErrorStatus    bindXrefs2(PyDbDatabase& pHostDb, const boost::python::list xrefBlkIds, const bool bInsertBind, const bool bAllowUnresolved, const bool bQuiet);
    static PyGeCurve3d          convertAcDbCurveToGelibCurve1(const PyDbCurve& dbCurve);
    static PyGeCurve3d          convertAcDbCurveToGelibCurve2(const PyDbCurve& dbCurve, const AcGeTol& tol);
    static PyDbCurve            convertGelibCurveToAcDbCurve1(const PyGeCurve3d& geCurve);
    static PyDbCurve            convertGelibCurveToAcDbCurve2(const PyGeCurve3d& geCurve, AcGeVector3d& normal);
    static PyDbCurve            convertGelibCurveToAcDbCurve3(const PyGeCurve3d& geCurve, AcGeVector3d& normal, const AcGeTol& tol);
    static PyDbObjectId         createViewByViewport(PyDbDatabase& pDb,const PyDbObjectId& viewportId, const std::string& name,const std::string& categoryName,const PyDbObjectId& labelBlockId);
    static Acad::ErrorStatus    detachXref(PyDbDatabase& pHostDb, const PyDbObjectId& xrefBlkId);
    static int                  dictAdd(const PyDbObjectId& dictname, const std::string& symname, const PyDbObjectId& newobj);
    static boost::python::list  dictNext(const PyDbObjectId& dictname, int rewind);
    static int                  dictRemove(const PyDbObjectId& dictname,const std::string& symname);
    static int                  dictRename(const PyDbObjectId& dictname, const std::string& symname, const std::string& newsym);
    static boost::python::list  dictSearch(const PyDbObjectId& dictname, const std::string& symname, int setnext);
    static bool                 displayPreviewFromDwg(const std::string& pszDwgfilename, HWND hwnd);


    static bool                 entDel(const PyDbObjectId& id);
    static boost::python::list  entGet(const PyDbObjectId& id);
    static PyDbObjectId         entLast();
    static bool                 entMod(const boost::python::list& list);
    static PyDbObjectId         entNext(const PyDbObjectId& id);
    static bool                 entUpd(const PyDbObjectId& id);
    static PyDbObject           openDbObject(const PyDbObjectId& id, AcDb::OpenMode mode);
    static PyDbEntity           openDbEntity(const PyDbObjectId& id, AcDb::OpenMode mode);
    static bool                 regApp(const std::string& app);
    static Acad::ErrorStatus    updateDimension(const PyDbObjectId& id);
    static boost::python::list  resbufTest(const boost::python::list& list);
    static bool                 ucs2Wcs1(const AcGePoint3d& p, AcGePoint3d& q);
    static bool                 ucs2Wcs2(const AcGeVector3d& p, AcGeVector3d& q);
    static bool                 wcs2Ecs1(const AcGePoint3d& p, const AcGeVector3d& normal, AcGePoint3d& q);
    static bool                 wcs2Ecs2(const AcGeVector3d& p, const AcGeVector3d& normal, AcGeVector3d& q);
    static bool                 ucs2Ucs1(const AcGePoint3d& p, AcGePoint3d& q);
    static bool                 ucs2Ucs2(const AcGeVector3d& p, AcGeVector3d& q);
    static bool                 ecs2Wcs1(const AcGePoint3d& p, const AcGeVector3d& normal, AcGePoint3d& q);
    static bool                 ecs2Wcs2(const AcGeVector3d& p, const AcGeVector3d& normal, AcGeVector3d& q);
};

