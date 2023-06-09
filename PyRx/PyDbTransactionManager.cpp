#include "stdafx.h"
#include "PyDbTransactionManager.h"
#include "PyDbObject.h"
#include "PyDbObjectId.h"

using namespace boost::python;

//-----------------------------------------------------------------------------
//----- PyDbTransactionManager
void makePyDbTransactionManager()
{
    class_<PyDbTransactionManager, bases<PyRxObject>>("TransactionManager")
        .def("startTransaction", &PyDbTransactionManager::startTransaction)
        .def("endTransaction", &PyDbTransactionManager::endTransaction)
        .def("abortTransaction", &PyDbTransactionManager::abortTransaction)
        .def("numActiveTransactions", &PyDbTransactionManager::numActiveTransactions)
        .def("numOpenedObjects", &PyDbTransactionManager::numOpenedObjects)
        .def("topTransaction", &PyDbTransactionManager::topTransaction)
        .def("addNewlyCreatedDBRObject", &PyDbTransactionManager::addNewlyCreatedDBRObject1)
        .def("addNewlyCreatedDBRObject", &PyDbTransactionManager::addNewlyCreatedDBRObject2)
        .def("getAllObjects", &PyDbTransactionManager::getAllObjects)
        .def("getObject", &PyDbTransactionManager::getObject1)
        .def("getObject", &PyDbTransactionManager::getObject2)
        .def("getObject", &PyDbTransactionManager::getObject3)
        .def("queueForGraphicsFlush", &PyDbTransactionManager::queueForGraphicsFlush)
        .def("desc", &PyDbTransactionManager::desc).staticmethod("desc")
        .def("className", &PyDbTransactionManager::className).staticmethod("className")
        ;
}

PyDbTransactionManager::PyDbTransactionManager()
    : PyRxObject(acdbTransactionManagerPtr())
{
}

PyTransaction PyDbTransactionManager::startTransaction()
{
    return PyTransaction(impObj()->startTransaction());
}  

Acad::ErrorStatus PyDbTransactionManager::endTransaction()
{
    return impObj()->endTransaction();
}

Acad::ErrorStatus PyDbTransactionManager::abortTransaction()
{
    return impObj()->abortTransaction();
}

int PyDbTransactionManager::numActiveTransactions()
{
    return impObj()->numActiveTransactions();
}

int PyDbTransactionManager::numOpenedObjects()
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->numOpenedObjects();
#endif
}

PyTransaction PyDbTransactionManager::topTransaction()
{
    return PyTransaction(impObj()->topTransaction());
}

Acad::ErrorStatus PyDbTransactionManager::addNewlyCreatedDBRObject1(PyDbObject& obj)
{
    return impObj()->addNewlyCreatedDBRObject(obj.impObj());
}

Acad::ErrorStatus PyDbTransactionManager::addNewlyCreatedDBRObject2(PyDbObject& obj, bool add)
{
    return impObj()->addNewlyCreatedDBRObject(obj.impObj(), add);
}

boost::python::list PyDbTransactionManager::getAllObjects()
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    PyAutoLockGIL lock;
    AcArray<AcDbObject*> objs;
    boost::python::list pyObjs;
    if (auto es = impObj()->getAllObjects(objs); es != eOk)
        throw PyAcadErrorStatus(es);
    for (auto item : objs)
        pyObjs.append(PyDbObject(item, true));
    return pyObjs;
#endif
}

PyDbObject PyDbTransactionManager::getObject1(const PyDbObjectId& id)
{
    return getObject3(id, AcDb::kForRead, false);
}

PyDbObject PyDbTransactionManager::getObject2(const PyDbObjectId& id, AcDb::OpenMode mode)
{
    return getObject3(id, mode, false);
}

PyDbObject PyDbTransactionManager::getObject3(const PyDbObjectId& id, AcDb::OpenMode mode, bool openErasedObject)
{
    AcDbObject* obj = nullptr;
    if (auto es = impObj()->getObject(obj, id.m_id, mode, openErasedObject); es != eOk)
        throw PyAcadErrorStatus(es);
    return PyDbObject(obj, true);
}

Acad::ErrorStatus PyDbTransactionManager::queueForGraphicsFlush()
{
    return  impObj()->queueForGraphicsFlush();
}

PyRxClass PyDbTransactionManager::desc()
{
    return PyRxClass(AcDbTransactionManager::desc(), false);
}

std::string PyDbTransactionManager::className()
{
    return "AcDbTransactionManager";
}

AcDbTransactionManager* PyDbTransactionManager::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcDbTransactionManager*>(m_pyImp.get());
}


//-----------------------------------------------------------------------------
//----- PyTransaction
void makePyTransaction()
{
    class_<PyTransaction, bases<PyRxObject>>("Transaction", boost::python::no_init)
        .def("getObject", &PyTransaction::getObject1)
        .def("getObject", &PyTransaction::getObject2)
        .def("getObject", &PyTransaction::getObject3)
        .def("getAllObjects", &PyTransaction::getAllObjects)
        .def("numOpenedObjects", &PyDbTransactionManager::numOpenedObjects)
        .def("desc", &PyDbTransactionManager::desc).staticmethod("desc")
        .def("className", &PyDbTransactionManager::className).staticmethod("className")
        ;
}

PyTransaction::PyTransaction(AcTransaction* ptr)
    : PyRxObject(ptr)
{
}

PyDbObject PyTransaction::getObject1(const PyDbObjectId& id)
{
    return getObject3(id, AcDb::kForRead, false);
}

PyDbObject PyTransaction::getObject2(const PyDbObjectId& id, AcDb::OpenMode mode)
{
    return getObject3(id, mode, false);
}

PyDbObject PyTransaction::getObject3(const PyDbObjectId& id, AcDb::OpenMode mode, bool openErasedObject)
{
    AcDbObject* obj = nullptr;
    if (auto es = impObj()->getObject(obj, id.m_id, mode, openErasedObject); es != eOk)
        throw PyAcadErrorStatus(es);
    return PyDbObject(obj, true);
}

boost::python::list PyTransaction::getAllObjects()
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    PyAutoLockGIL lock;
    AcArray<AcDbObject*> objs;
    boost::python::list pyObjs;
    if (auto es = impObj()->getAllObjects(objs); es != eOk)
        throw PyAcadErrorStatus(es);
    for (auto item : objs)
        pyObjs.append(PyDbObject(item, true));
    return pyObjs;
#endif
}

int PyTransaction::numOpenedObjects()
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->numOpenedObjects();
#endif
}

PyRxClass PyTransaction::desc()
{
    return PyRxClass(AcTransaction::desc(), false);
}

std::string PyTransaction::className()
{
    return "AcTransaction";
}

AcTransaction* PyTransaction::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcTransaction*>(m_pyImp.get());
}
