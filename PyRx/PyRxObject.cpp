#include "stdafx.h"
#include "PyRxObject.h"

using namespace boost::python;

//-----------------------------------------------------------------------------------------
//PyRxObject wrapper
void makeAcRxObjectWrapper()
{
    PyDocString DS("RxObject");
    class_<PyRxObject>("RxObject", boost::python::no_init)
        .def("isA", &PyRxObject::isA, DS.CLASSARGS())
        .def("isNullObj", &PyRxObject::isNullObj, DS.CLASSARGS())
        .def("implRefCount", &PyRxObject::implRefCount, DS.CLASSARGS())
        .def("queryX", &PyRxObject::queryX, DS.CLASSARGS({ "rhs :  PyRx.RxClass" }))
        .def("__eq__", &PyRxObject::operator==, DS.CLASSARGS({ "rhs :  PyRx.RxObject" }))
        .def("__ne__", &PyRxObject::operator!=, DS.CLASSARGS({ "rhs :  PyRx.RxObject" }))
        .def("className", &PyRxObject::className, DS.CLASSARGSSTATIC()).staticmethod("className")
        ;
}

//-----------------------------------------------------------------------------------------
//PyRxObject
PyRxObject::PyRxObject(const AcRxObject* ptr)
    : m_pyImp(const_cast<AcRxObject*>(ptr), PyRxObjectDeleter(false, false))
{
}

PyRxObject::PyRxObject(AcRxObject* ptr, bool autoDelete, bool isDbOject)
    : m_pyImp(ptr, PyRxObjectDeleter(autoDelete, isDbOject))
{
}

PyRxObject::~PyRxObject()
{
}

bool PyRxObject::operator==(const PyRxObject& rhs) const
{
    return impObj() == rhs.impObj();
}

bool PyRxObject::operator!=(const PyRxObject& rhs) const
{
    return impObj() != rhs.impObj();
}

PyRxClass PyRxObject::isA() const
{
    return PyRxClass(m_pyImp->isA(), false);
}

void PyRxObject::resetImp(AcRxObject* ptr, bool autoDelete, bool isDbObject)
{
    m_pyImp.reset(ptr, PyRxObjectDeleter(autoDelete, isDbObject));
}

bool PyRxObject::isNullObj()
{
    return m_pyImp == nullptr;
}

int PyRxObject::implRefCount()
{
    return m_pyImp.use_count();
}

PyRxObject PyRxObject::queryX(const PyRxClass& protocolClass) const
{
    AcRxObject* ptr = impObj()->queryX(protocolClass.impObj());
    if (ptr == nullptr)
        throw PyAcadErrorStatus(eInvalidInput);
    return PyRxObject(ptr, false, false);
}

PyRxClass PyRxObject::desc()
{
    return PyRxClass(AcRxObject::desc(), false);
}

std::string PyRxObject::className()
{
    return "AcRxObject";
}

AcRxObject* PyRxObject::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr)
        throw PyNullObject(src);
    return m_pyImp.get();
}

//-----------------------------------------------------------------------------------------
//PyRxClass Wrapper
void makeAcRxClassWrapper()
{
    PyDocString DS("RxClass");
    class_<PyRxClass, bases<PyRxObject>>("RxClass", boost::python::no_init)
        .def("isDerivedFrom", &PyRxClass::isDerivedFrom, DS.CLASSARGS({ "other : PyRx.RxClass" }))
        .def("appName", &PyRxClass::appName, DS.CLASSARGS())
        .def("dxfName", &PyRxClass::dxfName, DS.CLASSARGS())
        .def("name", &PyRxClass::name, DS.CLASSARGS())
        .def("queryX", &PyRxObject::queryX, DS.CLASSARGS({ "rhs :  PyRx.RxClass" }))
        .def("desc", &PyRxClass::desc, DS.CLASSARGSSTATIC()).staticmethod("desc")
        .def("className", &PyRxClass::className, DS.CLASSARGSSTATIC()).staticmethod("className")
        ;
}

//-----------------------------------------------------------------------------------------
//PrRxClass
PyRxClass::PyRxClass(AcRxClass* ptr, bool autoDelete)
    :PyRxObject(ptr, autoDelete, false)
{
}

bool PyRxClass::isDerivedFrom(const PyRxClass& other) const
{
    return impObj()->isDerivedFrom(other.impObj());
}

std::string PyRxClass::name()
{
    return wstr_to_utf8(impObj()->name());
}

std::string PyRxClass::appName() const
{
    return wstr_to_utf8(impObj()->appName());
}

std::string PyRxClass::dxfName() const
{
    return wstr_to_utf8(impObj()->dxfName());
}

PyRxObject PyRxClass::queryX(const PyRxClass& protocolClass) const
{
    AcRxObject* ptr = impObj()->queryX(protocolClass.impObj());
    if (ptr == nullptr)
        throw PyAcadErrorStatus(eInvalidInput);
    return PyRxObject(ptr, false, false);
}

PyRxClass PyRxClass::desc()
{
    return PyRxClass(AcRxClass::desc(), false);
}

std::string PyRxClass::className()
{
    return std::string{ "AcRxClass" };
}

AcRxClass* PyRxClass::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcRxClass*>(m_pyImp.get());
}
