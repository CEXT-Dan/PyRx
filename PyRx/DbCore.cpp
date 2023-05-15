#include "stdafx.h"
#include "DbCore.h"
#include "PyDbObjectId.h"
#include "PyDbEntity.h"
#include "dbdimassoc.h"
#include "ResultBuffer.h"

using namespace boost::python;

void makeDbCoreWrapper()
{
    class_<DbCore>("Core")
        .def("entGet", &DbCore::entGet).staticmethod("entGet")
        .def("entMod", &DbCore::entMod).staticmethod("entMod")
        .def("openDbObject", &DbCore::openDbObject).staticmethod("openDbObject")
        .def("openDbEntity", &DbCore::openDbEntity).staticmethod("openDbEntity")
        .def("regApp", &DbCore::regApp).staticmethod("regApp")
        .def("updateDimension", &DbCore::updateDimension).staticmethod("updateDimension")
        ;
}

boost::python::list DbCore::entGet(const PyDbObjectId& id)
{
    ads_name name = { 0L };
    if (auto es = acdbGetAdsName(name, id.m_id); es != eOk)
        throw PyAcadErrorStatus(es);
    AcResBufPtr ptr(acdbEntGet(name));
    if(ptr == nullptr)
        throw PyAcadErrorStatus(eInvalidInput);
    return resbufToList(ptr.get());
}

int DbCore::entMod(const boost::python::list& list)
{
    AcResBufPtr ptr(listToResbuf(list));
    return acdbEntMod(ptr.get());
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

int DbCore::regApp(const std::string& app)
{
    return acdbRegApp(utf8_to_wstr(app).c_str());
}

Acad::ErrorStatus DbCore::updateDimension(const PyDbObjectId& id)
{
    return acdbUpdateDimension(id.m_id);
}
