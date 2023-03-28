#include "stdafx.h"
#include "PyGiDrawable.h"

using namespace boost::python;

void makeAcGiObjectWrapper()
{
    static auto wrapper = class_<PyGiDrawable, bases<PyRxObject>>("PyGiDrawable", boost::python::no_init)
        .def("isA", &PyRxObject::isA)
        .def("className", &PyGiDrawable::className)
        ;
}

//-----------------------------------------------------------------------------------------
//PyGiDrawable
PyGiDrawable::PyGiDrawable(AcGiDrawable* ptr, bool autoDelete)
    : PyRxObject(ptr, autoDelete)
{
}

std::string PyGiDrawable::className()
{
    return "AcGiDrawable";
}

AcGiDrawable* PyGiDrawable::impObj() const
{
    return static_cast<AcGiDrawable*>(m_pImp);
}
