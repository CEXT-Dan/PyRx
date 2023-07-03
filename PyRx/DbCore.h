#pragma once

class PyDbObject;
class PyDbObjectId;
class PyDbEntity;

void makeDbCoreWrapper();

class DbCore
{
public:
    static boost::python::list  activeDatabaseArray();
    static double               angToF(const std::string& str, int unit);
    static std::string          angToS(double, int unit, int prec);
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

