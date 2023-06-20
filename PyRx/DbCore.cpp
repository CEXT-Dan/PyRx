#include "stdafx.h"
#include "DbCore.h"
#include "PyDbObjectId.h"
#include "PyDbEntity.h"
#include "dbdimassoc.h"
#include "ResultBuffer.h"


using namespace boost::python;

struct DbCoreDocStrings
{
    static constexpr const char* DbCoreopenDbObject = "\
Args :\
\n    \n\
\t1, PyDb.ObjectId : object id for the object to open.  \n\
\t2, PyDb.OpenMode : kForRead, kForWrite or kForNotify. \n\
\n    \n\
Returns :\
\n    \n\
\tThe PyDb.DbObject or PyAp.PyAcadErrorStatus exception";
};

void makeDbCoreWrapper()
{
    class_<DbCore>("Core")
        .def("entGet", &DbCore::entGet).staticmethod("entGet")
        .def("entDel", &DbCore::entDel).staticmethod("entDel")
        .def("entLast", &DbCore::entLast).staticmethod("entLast")
        .def("entMod", &DbCore::entMod).staticmethod("entMod")
        .def("entNext", &DbCore::entNext).staticmethod("entNext")
        .def("entUpd", &DbCore::entUpd).staticmethod("entUpd")
        .def("openDbObject", &DbCore::openDbObject, DbCoreDocStrings::DbCoreopenDbObject).staticmethod("openDbObject")
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

bool DbCore::entDel(const PyDbObjectId& id)
{
    ads_name name = { 0L };
    if (auto es = acdbGetAdsName(name, id.m_id); es != eOk)
        throw PyAcadErrorStatus(es);
    return acdbEntDel(name) == RTNORM;
}

boost::python::list DbCore::entGet(const PyDbObjectId& id)
{
    ads_name name = { 0L };
    if (auto es = acdbGetAdsName(name, id.m_id); es != eOk)
        throw PyAcadErrorStatus(es);
    AcResBufPtr ptr(acdbEntGet(name));
    if (ptr == nullptr)
        throw PyAcadErrorStatus(eInvalidInput);
    return resbufToList(ptr.get());
}

PyDbObjectId DbCore::entLast()
{
    ads_name name = { 0L };
    if (auto es = acdbEntLast(name); es != RTNORM)
        throw PyAcadErrorStatus(eInvalidInput);
    AcDbObjectId id;
    if (auto es = acdbGetObjectId(id, name); es != eOk)
        throw PyAcadErrorStatus(es);
    return PyDbObjectId(id);
}

bool DbCore::entMod(const boost::python::list& list)
{
    AcResBufPtr ptr(listToResbuf(list));
    return acdbEntMod(ptr.get()) == RTNORM;
}

PyDbObjectId DbCore::entNext(const PyDbObjectId& id)
{
    AcDbObjectId idOut;
    ads_name nameIn = { 0L };
    ads_name nameOut = { 0L };
    if (auto es = acdbGetAdsName(nameIn, id.m_id); es != eOk)
        throw PyAcadErrorStatus(es);
    if (auto es = acdbEntNext(nameIn, nameOut); es != RTNORM)
        throw PyAcadErrorStatus(eInvalidInput);
    if (auto es = acdbGetObjectId(idOut, nameOut); es != eOk)
        throw PyAcadErrorStatus(es);
    return PyDbObjectId(idOut);
}

bool DbCore::entUpd(const PyDbObjectId& id)
{
    ads_name name = { 0L };
    if (auto es = acdbGetAdsName(name, id.m_id); es != eOk)
        throw PyAcadErrorStatus(es);
    return acdbEntUpd(name) == RTNORM;
}

PyDbObject DbCore::openDbObject(const PyDbObjectId& id, AcDb::OpenMode mode)
{
    AcDbObject* pObj = nullptr;
    if (acdbOpenAcDbObject(pObj, id.m_id, mode) == eOk)
        return PyDbObject{ pObj, true };
    throw PyNullObject(std::source_location::current());
}

PyDbEntity DbCore::openDbEntity(const PyDbObjectId& id, AcDb::OpenMode mode)
{
    if (id.m_id.objectClass()->isDerivedFrom(AcDbEntity::desc()))
    {
        AcDbEntity* pObj = nullptr;
        if (acdbOpenAcDbEntity(pObj, id.m_id, mode) == eOk)
            return PyDbEntity(pObj, true);
    }
    throw PyNullObject(std::source_location::current());
}

bool DbCore::regApp(const std::string& app)
{
    return acdbRegApp(utf8_to_wstr(app).c_str()) == RTNORM;
}

Acad::ErrorStatus DbCore::updateDimension(const PyDbObjectId& id)
{
    return acdbUpdateDimension(id.m_id);
}

boost::python::list DbCore::resbufTest(const boost::python::list& list)
{
    AcResBufPtr ptr(listToResbuf(list));
    return resbufToList(ptr.get());
}

bool DbCore::ucs2Wcs1(const AcGePoint3d& p, AcGePoint3d& q)
{
    ads_point pnt;
    bool flag = acdbUcs2Wcs(asDblArray(p), pnt,false);
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
    bool flag = acdbWcs2Ecs(asDblArray(p), pnt, asDblArray(normal), true);
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
    bool flag = acdbWcs2Ucs(asDblArray(p), pnt, false);
    q = asVec3d(pnt);
    return flag;
}

bool DbCore::ecs2Wcs1(const AcGePoint3d& p, const AcGeVector3d& normal, AcGePoint3d& q)
{
    ads_point pnt;
    bool flag = acdbEcs2Wcs(asDblArray(p), pnt, asDblArray(normal), true);
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
