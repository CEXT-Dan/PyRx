#include "stdafx.h"
#include "PyAcDb.h"
#include "PyDbEntity.h"
#include "PyDbObjectId.h"
#include "PyDbDatabase.h"
#include "PyDbHostApplicationServices.h"
#include "PyDbBlockTableRecord.h"
#include "PyDbSymbolTableRecord.h"

using namespace boost::python;

static PyDbObject openDbObject(const PyDbObjectId& id, bool forWrite)
{
    AcDbObject* pObj = nullptr;
    if (acdbOpenAcDbObject(pObj, id.m_id, forWrite ? AcDb::kForWrite : AcDb::kForRead) == eOk)
        return PyDbObject(pObj, true);
    return PyDbObject(nullptr, true);
}

static PyDbObject openDbEntity(const PyDbObjectId& id, bool forWrite)
{
    if (id.m_id.objectClass()->isDerivedFrom(AcDbEntity::desc()))
    {
        AcDbEntity* pObj = nullptr;
        if (acdbOpenAcDbEntity(pObj, id.m_id, forWrite ? AcDb::kForWrite : AcDb::kForRead) == eOk)
            return PyDbObject(pObj, true);
    }
    return PyDbObject(nullptr, true);
}

BOOST_PYTHON_MODULE(PyDb)
{
    def("openDbObject", openDbObject);
    def("openDbEntity", openDbEntity);

    //create in class order!
    makeAcDbObjectIdWrapper();
    makeAcDbObjectWrapper();
    makeAcDbSymbolTableRecordWrapper();
    makeAcDbBlockTableRecordWrapper();
    makeAcDbDatabaseWrapper();
    makeAcDbHostApplicationServicesWrapper();


    //TODO
    enum_<Acad::ErrorStatus>("ErrorStatus")
        .value("eOk", Acad::ErrorStatus::eOk)
        .value("eNullPtr", Acad::ErrorStatus::eNullPtr)
        ;
};

void initPyDbModule()
{
    PyImport_AppendInittab(PyDbNamespace, &PyInit_PyDb);
}
