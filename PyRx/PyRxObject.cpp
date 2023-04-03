#include "stdafx.h"
#include "PyRxObject.h"

using namespace boost::python;

//-----------------------------------------------------------------------------------------
//PyRxObject wrapper
void makeAcRxObjectWrapper()
{
    static auto wrapper = class_<PyRxObject, boost::noncopyable>("RxObject", boost::python::no_init)
        .def("isA", &PyRxObject::isA)
        .def("className", &PyRxObject::className).staticmethod("className")
        .def("deleteNativeObject", &PyRxObject::deleteNativeObject)
        .def("isNull", &PyRxObject::isNull)
        ;
}


//-----------------------------------------------------------------------------------------
//PyRxObject
PyRxObject::PyRxObject(AcRxObject* ptr, bool autoDelete)
    : m_pImp(ptr), m_bAutoDelete(autoDelete)
{
}

PyRxObject::~PyRxObject()
{
    deleteNativeObject();
}

PyRxClass PyRxObject::isA() const
{
    return PyRxClass(m_pImp->isA(), false);
}

std::string PyRxObject::className()
{
    return "AcRxObject";
}

AcRxObject* PyRxObject::impObj() const
{
    return m_pImp;
}

void PyRxObject::deleteNativeObject()
{
    try
    {
        if (m_bAutoDelete)
        {
            if (m_pImp != nullptr)
            {
                delete m_pImp;
                m_pImp = nullptr;
            }
        }
    }
    catch (...) {}
}

bool PyRxObject::isNull()
{
    return m_pImp == nullptr;
}

//-----------------------------------------------------------------------------------------
//PyRxClass Wrapper
void makeAcRxClassWrapper()
{
    static auto wrapper = class_<PyRxClass, bases<PyRxObject>>("RxClass", boost::python::no_init)
        .def("className", &PyRxClass::className).staticmethod("className")
        .def("name", &PyRxClass::name)
        ;
}

//-----------------------------------------------------------------------------------------
//PrRxClass
PyRxClass::PyRxClass(AcRxClass* ptr, bool autoDelete)
    :PyRxObject(ptr, autoDelete)
{
}

std::string PyRxClass::name()
{
    auto imp = impObj();
    if (imp != nullptr)
        return wstr_to_utf8(imp->name());
    return std::string{ "AcRxClass" };
}

std::string PyRxClass::className()
{
    return std::string{ "AcRxClass" };
}

AcRxClass* PyRxClass::impObj() const
{
    return static_cast<AcRxClass*>(m_pImp);
}
