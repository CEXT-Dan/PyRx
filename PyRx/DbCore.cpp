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
