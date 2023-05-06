#include "stdafx.h"
#include "PyGiDrawable.h"

using namespace boost::python;

void makeAcGiObjectWrapper()
{
    class_<PyGiDrawable, bases<PyRxObject>>("Drawable", boost::python::no_init)
        .def("isA", &PyRxObject::isA)
        .def("className", &PyGiDrawable::className).staticmethod("className")
        ;
}

//-----------------------------------------------------------------------------------------
//PyGiDrawable
PyGiDrawable::PyGiDrawable(AcGiDrawable* ptr, bool autoDelete, bool isDbObject )
    : PyRxObject(ptr, autoDelete, isDbObject)
{
}

std::string PyGiDrawable::className()
{
    return "AcGiDrawable";
}

AcGiDrawable* PyGiDrawable::impObj() const
{
    return static_cast<AcGiDrawable*>(m_pImp.get());
}
