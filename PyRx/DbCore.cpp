#include "stdafx.h"
#include "DbCore.h"
#include "PyDbObjectId.h"
#include "PyDbEntity.h"

using namespace boost::python;

void makeDbCoreWrapper()
{
    class_<DbCore>("Core")
        .def("regApp", &DbCore::regApp).staticmethod("regApp")
        .def("openDbObject", &DbCore::openDbObject).staticmethod("openDbObject")
        .def("openDbEntity", &DbCore::openDbEntity).staticmethod("openDbEntity")
        ;
}

int DbCore::regApp(const std::string& app)
{
    return acdbRegApp(utf8_to_wstr(app).c_str());
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
