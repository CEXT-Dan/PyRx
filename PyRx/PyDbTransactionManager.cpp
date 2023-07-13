#include "stdafx.h"
#include "PyDbTransactionManager.h"
#include "PyDbObject.h"
#include "PyDbObjectId.h"

using namespace boost::python;

//-----------------------------------------------------------------------------
//----- PyDbTransactionManager
void makePyDbTransactionManager()
{
    PyDocString DS("TransactionManager");
    class_<PyDbTransactionManager, bases<PyRxObject>>("TransactionManager")
        .def(init<>(DS.CLASSARGS()))
        .def("startTransaction", &PyDbTransactionManager::startTransaction, DS.CLASSARGS())
        .def("endTransaction", &PyDbTransactionManager::endTransaction, DS.CLASSARGS())
        .def("abortTransaction", &PyDbTransactionManager::abortTransaction, DS.CLASSARGS())
        .def("numActiveTransactions", &PyDbTransactionManager::numActiveTransactions, DS.CLASSARGS())
        .def("numOpenedObjects", &PyDbTransactionManager::numOpenedObjects, DS.CLASSARGS())
        .def("topTransaction", &PyDbTransactionManager::topTransaction, DS.CLASSARGS())
        .def("addNewlyCreatedDBRObject", &PyDbTransactionManager::addNewlyCreatedDBRObject1)
        .def("addNewlyCreatedDBRObject", &PyDbTransactionManager::addNewlyCreatedDBRObject2, DS.CLASSARGS({ "obj: DbObject","add: bool=True" }))
        .def("getAllObjects", &PyDbTransactionManager::getAllObjects, DS.CLASSARGS())
        .def("getObject", &PyDbTransactionManager::getObject1)
        .def("getObject", &PyDbTransactionManager::getObject2)
        .def("getObject", &PyDbTransactionManager::getObject3, DS.CLASSARGS({ "id: ObjectId","mode: OpenMode=OpenMode.kForRead","openErasedObject: bool=False" }))
        .def("queueForGraphicsFlush", &PyDbTransactionManager::queueForGraphicsFlush, DS.CLASSARGS())
        .def("desc", &PyDbTransactionManager::desc, DS.CLASSARGSSTATIC()).staticmethod("desc")
        .def("className", &PyDbTransactionManager::className, DS.CLASSARGSSTATIC()).staticmethod("className")
        ;
}

PyDbTransactionManager::PyDbTransactionManager()
    : PyRxObject(acdbTransactionManagerPtr())
{
}

PyDbTransactionManager::PyDbTransactionManager(AcDbTransactionManager* ptr)
    : PyRxObject(ptr, false, false)
{
}

PyTransaction PyDbTransactionManager::startTransaction()
{
    return PyTransaction(impObj()->startTransaction());
}

void PyDbTransactionManager::endTransaction()
{
    return PyThrowBadEs(impObj()->endTransaction());
}

void PyDbTransactionManager::abortTransaction()
{
    return PyThrowBadEs(impObj()->abortTransaction());
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

void PyDbTransactionManager::addNewlyCreatedDBRObject1(PyDbObject& obj)
{
    return PyThrowBadEs(impObj()->addNewlyCreatedDBRObject(obj.impObj()));
}

void PyDbTransactionManager::addNewlyCreatedDBRObject2(PyDbObject& obj, bool add)
{
    return PyThrowBadEs(impObj()->addNewlyCreatedDBRObject(obj.impObj(), add));
}

boost::python::list PyDbTransactionManager::getAllObjects()
{
#ifdef BRXAPPV23 // SR159573
    PyAutoLockGIL lock;
    AcDbVoidPtrArray objs;
    boost::python::list pyObjs;
    if (auto es = impObj()->getAllObjects(objs); es != eOk)
        throw PyAcadErrorStatus(es);
    for (auto item : objs)
        pyObjs.append(PyDbObject((AcDbObject*)item, true));
    return pyObjs;
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

void PyDbTransactionManager::queueForGraphicsFlush()
{
    return PyThrowBadEs(impObj()->queueForGraphicsFlush());
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
//----- AcTransactionManager
void makePyTransactionManagerManager()
{
    class_<PyTransactionManager, bases<PyDbTransactionManager>>("TransactionManager")

        .def("flushGraphics", &PyTransactionManager::flushGraphics)
        .def("enableGraphicsFlush", &PyTransactionManager::enableGraphicsFlush)
        .def("desc", &PyTransactionManager::desc).staticmethod("desc")
        .def("className", &PyTransactionManager::className).staticmethod("className")
        ;
}

PyTransactionManager::PyTransactionManager()
    : PyDbTransactionManager(acTransactionManagerPtr())
{
}

PyTransactionManager::PyTransactionManager(AcTransactionManager* ptr)
    : PyDbTransactionManager(ptr)
{
}

void PyTransactionManager::enableGraphicsFlush(bool doEnable)
{
    return PyThrowBadEs(impObj()->enableGraphicsFlush(doEnable));
}

void PyTransactionManager::flushGraphics()
{
    return impObj()->flushGraphics();
}

PyRxClass PyTransactionManager::desc()
{
    return PyRxClass(AcTransactionManager::desc(), false);
}

std::string PyTransactionManager::className()
{
    return "AcTransactionManager";
}

AcTransactionManager* PyTransactionManager::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcTransactionManager*>(m_pyImp.get());
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
#ifdef BRXAPPV23
    PyAutoLockGIL lock;
    AcDbVoidPtrArray objs;
    boost::python::list pyObjs;
    if (auto es = impObj()->getAllObjects(objs); es != eOk)
        throw PyAcadErrorStatus(es);
    for (auto item : objs)
        pyObjs.append(PyDbObject((AcDbObject*)item, true));
    return pyObjs;
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
