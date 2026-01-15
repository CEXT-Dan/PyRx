#include "stdafx.h"
#include "PyDbDatabaseReactor.h"
#include "PyDbObject.h"
#include "PyDbDatabase.h"
#include "PyDbObjectId.h"

using namespace boost::python;
void makePyDbDatabaseReactorWrapper()
{
    PyDocString DS("DatabaseReactor");
    class_<PyDbDatabaseReactor, bases<PyRxObject>>("DatabaseReactor")
        .def(init<>(DS.ARGS(2824)))
        .def("objectAppended", &PyDbDatabaseReactor::objectAppended, DS.ARGS({ "db: PyDb.Database", "obj: PyDb.DbObject" }, 2828))
        .def("objectUnAppended", &PyDbDatabaseReactor::objectUnAppended, DS.ARGS({ "db: PyDb.Database", "obj: PyDb.DbObject" }, 2833))
        .def("objectReAppended", &PyDbDatabaseReactor::objectReAppended, DS.ARGS({ "db: PyDb.Database", "obj: PyDb.DbObject" }, 2832))
        .def("objectOpenedForModify", &PyDbDatabaseReactor::objectOpenedForModify, DS.ARGS({ "db: PyDb.Database", "obj: PyDb.DbObject" }, 2831))
        .def("objectModified", &PyDbDatabaseReactor::objectModified, DS.ARGS({ "db: PyDb.Database", "obj: PyDb.DbObject" }, 2830))
        .def("objectErased", &PyDbDatabaseReactor::objectErased, DS.ARGS({ "db: PyDb.Database", "obj: PyDb.DbObject", "erased: bool" }, 2829))
        .def("headerSysVarWillChange", &PyDbDatabaseReactor::headerSysVarWillChange, DS.ARGS({ "db: PyDb.Database", "name: str" }, 2827))
        .def("headerSysVarChanged", &PyDbDatabaseReactor::headerSysVarChanged, DS.ARGS({ "db: PyDb.Database", "name: str", "success: bool" }, 2826))
        .def("proxyResurrectionCompleted", &PyDbDatabaseReactor::proxyResurrectionCompleted, DS.ARGS({ "db: PyDb.Database", "name: str", "ids: list[PyDb.ObjectId]" }, 2834))
        .def("goodbye", &PyDbDatabaseReactor::goodbye, DS.ARGS({ "db: PyDb.Database" }, 2825))
        .def("desc", &PyDbDatabaseReactor::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("className", &PyDbDatabaseReactor::className, DS.SARGS()).staticmethod("className")
        ;
}
PyDbDatabaseReactorImpl::PyDbDatabaseReactorImpl(PyDbDatabaseReactor* backPtr)
    : m_backPtr(backPtr)
{
}

void PyDbDatabaseReactorImpl::objectAppended(const AcDbDatabase* pDb, const AcDbObject* pObj)
{
    const auto imp = impObj();
    if (imp->reg_objectAppended)
    {
        PyDbDatabase db(const_cast<AcDbDatabase*>(pDb));
        PyDbObject obj(const_cast<AcDbObject*>(pObj), false);
        obj.forceKeepAlive(true);
        imp->objectAppended(db, obj);
    }
}

void PyDbDatabaseReactorImpl::objectUnAppended(const AcDbDatabase* pDb, const AcDbObject* pObj)
{
    const auto imp = impObj();
    if (imp->reg_objectUnAppended)
    {
        PyDbDatabase db(const_cast<AcDbDatabase*>(pDb));
        PyDbObject obj(const_cast<AcDbObject*>(pObj), false);
        obj.forceKeepAlive(true);
        imp->objectUnAppended(db, obj);
    }
}

void PyDbDatabaseReactorImpl::objectReAppended(const AcDbDatabase* pDb, const AcDbObject* pObj)
{
    const auto imp = impObj();
    if (imp->reg_objectReAppended)
    {
        PyDbDatabase db(const_cast<AcDbDatabase*>(pDb));
        PyDbObject obj(const_cast<AcDbObject*>(pObj), false);
        obj.forceKeepAlive(true);
        imp->objectReAppended(db, obj);
    }
}

void PyDbDatabaseReactorImpl::objectOpenedForModify(const AcDbDatabase* pDb, const AcDbObject* pObj)
{
    const auto imp = impObj();
    if (imp->reg_objectOpenedForModify)
    {
        PyDbDatabase db(const_cast<AcDbDatabase*>(pDb));
        PyDbObject obj(const_cast<AcDbObject*>(pObj), false);
        obj.forceKeepAlive(true);
        imp->objectOpenedForModify(db, obj);
    }
}

void PyDbDatabaseReactorImpl::objectModified(const AcDbDatabase* pDb, const AcDbObject* pObj)
{
    const auto imp = impObj();
    if (imp->reg_objectModified)
    {
        PyDbDatabase db(const_cast<AcDbDatabase*>(pDb));
        PyDbObject obj(const_cast<AcDbObject*>(pObj), false);
        obj.forceKeepAlive(true);
        imp->objectModified(db, obj);
    }
}

void PyDbDatabaseReactorImpl::objectErased(const AcDbDatabase* pDb, const AcDbObject* pObj, Adesk::Boolean bErased)
{
    const auto imp = impObj();
    if (imp->reg_objectErased)
    {
        PyDbDatabase db(const_cast<AcDbDatabase*>(pDb));
        PyDbObject obj(const_cast<AcDbObject*>(pObj), false);
        obj.forceKeepAlive(true);
        imp->objectErased(db, obj, bErased);
    }
}

void PyDbDatabaseReactorImpl::headerSysVarWillChange(const AcDbDatabase* pDb, const ACHAR* name)
{
    const auto imp = impObj();
    if (imp->reg_headerSysVarWillChange)
    {
        PyDbDatabase db(const_cast<AcDbDatabase*>(pDb));
        imp->headerSysVarWillChange(db, wstr_to_utf8(name).c_str());
    }
}

void PyDbDatabaseReactorImpl::headerSysVarChanged(const AcDbDatabase* pDb, const ACHAR* name, Adesk::Boolean bSuccess)
{
    const auto imp = impObj();
    if (imp->reg_headerSysVarChanged)
    {
        PyDbDatabase db(const_cast<AcDbDatabase*>(pDb));
        imp->headerSysVarChanged(db, wstr_to_utf8(name).c_str(), bSuccess);
    }
}

void PyDbDatabaseReactorImpl::proxyResurrectionCompleted(const AcDbDatabase* pDb, const ACHAR* appname, AcDbObjectIdArray& objects)
{
    const auto imp = impObj();
    if (imp->reg_proxyResurrectionCompleted)
    {
        PyDbDatabase db(const_cast<AcDbDatabase*>(pDb));
        auto ids = ObjectIdArrayToPyList(objects);
        imp->proxyResurrectionCompleted(db, wstr_to_utf8(appname).c_str(), ids);
    }
}

void PyDbDatabaseReactorImpl::goodbye(const AcDbDatabase* pDb)
{
    const auto imp = impObj();
    if (imp->reg_goodbye)
    {
        PyDbDatabase db(const_cast<AcDbDatabase*>(pDb));
        imp->goodbye(db);
    }
}

PyDbDatabaseReactor* PyDbDatabaseReactorImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_backPtr == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return m_backPtr;
}

//-- begin wrapper --
PyDbDatabaseReactor::PyDbDatabaseReactor()
    : PyRxObject(new PyDbDatabaseReactorImpl(this), true, false), boost::python::wrapper<PyDbDatabaseReactor>()
{
}

void PyDbDatabaseReactor::objectAppended(const PyDbDatabase& pDb, const PyDbObject& pObj)
{
    PyAutoLockGIL lock;
    try
    {
        if (const override& f = this->get_override("objectAppended"))
            f(pDb, pObj);
        else
            reg_objectAppended = false;
    }
    catch (...)
    {
        reg_objectAppended = false;
        printExceptionMsg();
    }
}

void PyDbDatabaseReactor::objectUnAppended(const PyDbDatabase& pDb, const PyDbObject& pObj)
{
    PyAutoLockGIL lock;
    try
    {
        if (const override& f = this->get_override("objectUnAppended"))
            f(pDb, pObj);
        else
            reg_objectUnAppended = false;
    }
    catch (...)
    {
        reg_objectUnAppended = false;
        printExceptionMsg();
    }
}

void PyDbDatabaseReactor::objectReAppended(const PyDbDatabase& pDb, const PyDbObject& pObj)
{
    PyAutoLockGIL lock;
    try
    {
        if (const override& f = this->get_override("objectReAppended"))
            f(pDb, pObj);
        else
            reg_objectReAppended = false;
    }
    catch (...)
    {
        reg_objectReAppended = false;
        printExceptionMsg();
    }
}

void PyDbDatabaseReactor::objectOpenedForModify(const PyDbDatabase& pDb, const PyDbObject& pObj)
{
    PyAutoLockGIL lock;
    try
    {
        if (const override& f = this->get_override("objectOpenedForModify"))
            f(pDb, pObj);
        else
            reg_objectOpenedForModify = false;
    }
    catch (...)
    {
        reg_objectOpenedForModify = false;
        printExceptionMsg();
    }
}

void PyDbDatabaseReactor::objectModified(const PyDbDatabase& pDb, const PyDbObject& pObj)
{
    PyAutoLockGIL lock;
    try
    {
        if (const override& f = this->get_override("objectModified"))
            f(pDb, pObj);
        else
            reg_objectModified = false;
    }
    catch (...)
    {
        reg_objectModified = false;
        printExceptionMsg();
    }
}

void PyDbDatabaseReactor::objectErased(const PyDbDatabase& pDb, const PyDbObject& pObj, bool bErased)
{
    PyAutoLockGIL lock;
    try
    {
        if (const override& f = this->get_override("objectErased"))
            f(pDb, pObj, bErased);
        else
            reg_objectErased = false;
    }
    catch (...)
    {
        reg_objectErased = false;
        printExceptionMsg();
    }
}

void PyDbDatabaseReactor::headerSysVarWillChange(const PyDbDatabase& pDb, const std::string& name)
{
    PyAutoLockGIL lock;
    try
    {
        if (const override& f = this->get_override("headerSysVarWillChange"))
            f(pDb, name);
        else
            reg_headerSysVarWillChange = false;
    }
    catch (...)
    {
        reg_headerSysVarWillChange = false;
        printExceptionMsg();
    }
}

void PyDbDatabaseReactor::headerSysVarChanged(const PyDbDatabase& pDb, const std::string& name, bool bSuccess)
{
    PyAutoLockGIL lock;
    try
    {
        if (const override& f = this->get_override("headerSysVarChanged"))
            f(pDb, name, bSuccess);
        else
            reg_headerSysVarChanged = false;
    }
    catch (...)
    {
        reg_headerSysVarChanged = false;
        printExceptionMsg();
    }
}

void PyDbDatabaseReactor::proxyResurrectionCompleted(const PyDbDatabase& pDb, const std::string& appname, boost::python::list& objects)
{
    PyAutoLockGIL lock;
    try
    {
        if (const override& f = this->get_override("proxyResurrectionCompleted"))
            f(pDb, appname, objects);
        else
            reg_proxyResurrectionCompleted = false;
    }
    catch (...)
    {
        reg_proxyResurrectionCompleted = false;
        printExceptionMsg();
    }
}

void PyDbDatabaseReactor::goodbye(const PyDbDatabase& pDb)
{
    PyAutoLockGIL lock;
    try
    {
        if (const override& f = this->get_override("goodbye"))
            f(pDb);
        else
            reg_goodbye = false;
    }
    catch (...)
    {
        reg_goodbye = false;
        printExceptionMsg();
    }
}

PyRxClass PyDbDatabaseReactor::desc()
{
    return PyRxClass(AcDbDatabaseReactor::desc(), false);
}

std::string PyDbDatabaseReactor::className()
{
    return "AcDbDatabaseReactor";
}

AcDbDatabaseReactor* PyDbDatabaseReactor::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbDatabaseReactor*>(m_pyImp.get());
}
