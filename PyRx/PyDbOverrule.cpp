#include "stdafx.h"
#include "PyDbOverrule.h"
#include "PyDbObjectId.h"
#include "PyDbDimension.h"
#include "PyDbSymbolTableRecord.h"
#include "PyDbIdMapping.h"

using namespace boost::python;

void makePyDbObjectOverrulerapper()
{
    PyDocString DS("DbObjectOverrule");
    class_<PyDbObjectOverrule, bases<PyRxOverrule>>("DbObjectOverrule")
        .def("isApplicable", &PyDbObjectOverrule::isApplicableWr, DS.ARGS({ "object: PyRx.RxObject" }))
        .def("open", &PyDbObjectOverrule::openWr, DS.ARGS({ "object: PyDb.DbObject","mode: OpenMode" }))
        .def("close", &PyDbObjectOverrule::closeWr, DS.ARGS({ "object: PyDb.DbObject" }))
        .def("cancel", &PyDbObjectOverrule::cancelWr, DS.ARGS({ "object: PyDb.DbObject" }))
        .def("erase", &PyDbObjectOverrule::eraseWr, DS.ARGS({ "object: PyDb.DbObject","erased : bool" }))
        .def("baseOpen", &PyDbObjectOverrule::baseOpen, DS.ARGS({ "object: PyDb.DbObject","mode: OpenMode" }))
        .def("baseClose", &PyDbObjectOverrule::baseClose, DS.ARGS({ "object: PyDb.DbObject" }))
        .def("baseCancel", &PyDbObjectOverrule::baseCancel, DS.ARGS({ "object: PyDb.DbObject" }))
        .def("baseErase", &PyDbObjectOverrule::baseErase, DS.ARGS({ "object: PyDb.DbObject","erased : bool" }))
        .def("className", &PyDbObjectOverrule::className).staticmethod("className")
        .def("desc", &PyDbObjectOverrule::desc).staticmethod("desc")
        ;
}

PyDbObjectOverrule::PyDbObjectOverrule()
    : PyRxOverrule(this)
{
}

bool PyDbObjectOverrule::isApplicable(const AcRxObject* pOverruledSubject) const
{
    if (!reg_isApplicable)
        return false;
    PyRxObject obj(pOverruledSubject);
    return this->isApplicableWr(obj);
}

Acad::ErrorStatus PyDbObjectOverrule::open(AcDbObject* pSubject, AcDb::OpenMode mode)
{
    if (!reg_open)
        return AcDbObjectOverrule::open(pSubject, mode);
    PyDbObject obj(pSubject,false);
    obj.forceKeepAlive(true);
    return this->openWr(obj,mode);
}

Acad::ErrorStatus PyDbObjectOverrule::close(AcDbObject* pSubject)
{
    if (!reg_close)
        return AcDbObjectOverrule::close(pSubject);
    PyDbObject obj(pSubject, false);
    obj.forceKeepAlive(true);
    return this->closeWr(obj);
}

Acad::ErrorStatus PyDbObjectOverrule::cancel(AcDbObject* pSubject)
{
    if (!reg_cancel)
        return AcDbObjectOverrule::cancel(pSubject);
    PyDbObject obj(pSubject, false);
    obj.forceKeepAlive(true);
    return this->cancelWr(obj);
}

Acad::ErrorStatus PyDbObjectOverrule::erase(AcDbObject* pSubject, Adesk::Boolean erasing)
{
    if (!reg_erase)
        return AcDbObjectOverrule::erase(pSubject, erasing);
    PyDbObject obj(pSubject, false);
    obj.forceKeepAlive(true);
    return this->eraseWr(obj, erasing);
}

bool PyDbObjectOverrule::isApplicableWr(const PyRxObject& pOverruledSubject) const
{
    PyAutoLockGIL lock;
    try
    {
        if (const override& f = get_override("isApplicable"))
        {
            return f(pOverruledSubject);
        }
        else
        {
            reg_isApplicable = false;
            return false;
        }
    }
    catch (...)
    {
        printExceptionMsg();
        reg_isApplicable = false;
    }
    return false;
}

Acad::ErrorStatus PyDbObjectOverrule::openWr(PyDbObject& pSubject, AcDb::OpenMode mode)
{
    PyAutoLockGIL lock;
    try
    {
        if (const override& f = get_override("open"))
        {
            return f(pSubject, mode);
        }
        else
        {
            reg_open = false;
            return baseOpen(pSubject, mode);
        }
    }
    catch (...)
    {
        printExceptionMsg();
        reg_open = false;
    }
    return eInvalidInput;
}

Acad::ErrorStatus PyDbObjectOverrule::closeWr(PyDbObject& pSubject)
{
    PyAutoLockGIL lock;
    try
    {
        if (const override& f = get_override("close"))
        {
            return f(pSubject);
        }
        else
        {
            reg_close = false;
            return baseClose(pSubject);
        }
    }
    catch (...)
    {
        printExceptionMsg();
        reg_close = false;
    }
    return eInvalidInput;
}

Acad::ErrorStatus PyDbObjectOverrule::cancelWr(PyDbObject& pSubject)
{
    PyAutoLockGIL lock;
    try
    {
        if (const override& f = get_override("cancel"))
        {
            return f(pSubject);
        }
        else
        {
            reg_cancel = false;
            return baseCancel(pSubject);
        }
    }
    catch (...)
    {
        printExceptionMsg();
        reg_cancel = false;
    }
    return eInvalidInput;
}

Acad::ErrorStatus PyDbObjectOverrule::eraseWr(PyDbObject& pSubject, Adesk::Boolean erasing)
{
    PyAutoLockGIL lock;
    try
    {
        if (const override& f = get_override("erase"))
        {
            return f(pSubject, erasing);
        }
        else
        {
            reg_erase = false;
            return baseErase(pSubject, erasing);
        }
    }
    catch (...)
    {
        printExceptionMsg();
        reg_erase = false;
    }
    return eInvalidInput;
}

Acad::ErrorStatus PyDbObjectOverrule::baseOpen(PyDbObject& pSubject, AcDb::OpenMode mode)
{
    return AcDbObjectOverrule::open(pSubject.impObj(), mode);
}

Acad::ErrorStatus PyDbObjectOverrule::baseClose(PyDbObject& pSubject)
{
    return AcDbObjectOverrule::close(pSubject.impObj());
}

Acad::ErrorStatus PyDbObjectOverrule::baseCancel(PyDbObject& pSubject)
{
    return AcDbObjectOverrule::cancel(pSubject.impObj());
}

Acad::ErrorStatus PyDbObjectOverrule::baseErase(PyDbObject& pSubject, Adesk::Boolean erasing)
{
    return AcDbObjectOverrule::erase(pSubject.impObj(), erasing);
}

std::string PyDbObjectOverrule::className()
{
    return "AcDbObjectOverrule";
}

PyRxClass PyDbObjectOverrule::desc()
{
    return PyRxClass(AcDbObjectOverrule::desc(), false);
}

AcDbObjectOverrule* PyDbObjectOverrule::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbObjectOverrule*>(m_pyImp.get());
}
