#include "stdafx.h"
#include "PyRxObject.h"

using namespace boost::python;

//-----------------------------------------------------------------------------------------
//PyRxObject wrapper
void makeAcRxObjectWrapper()
{
    class_<PyRxObject>("RxObject", boost::python::no_init)
        .def("isA", &PyRxObject::isA)
        .def("className", &PyRxObject::className).staticmethod("className")
        .def("isNull", &PyRxObject::isNull)
        .def("refCount", &PyRxObject::refCount)
        .def("__eq__", &PyRxObject::operator==)
        .def("__ne__", &PyRxObject::operator!=)
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

bool PyRxObject::isNull()
{
    return m_pyImp == nullptr;
}

int PyRxObject::refCount()
{
    return m_pyImp.use_count();
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
    class_<PyRxClass, bases<PyRxObject>>("RxClass", boost::python::no_init)
        .def("isDerivedFrom", &PyRxClass::isDerivedFrom)
        .def("appName", &PyRxClass::appName)
        .def("dxfName", &PyRxClass::dxfName)
        .def("name", &PyRxClass::name)
        .def("desc", &PyRxClass::desc).staticmethod("desc")
        .def("className", &PyRxClass::className).staticmethod("className")
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
