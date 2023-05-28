#include "stdafx.h"
#include "PyGiSubEntityTraits.h"
using namespace boost::python;

//-----------------------------------------------------------------------------------------
//PyGiSubEntityTraits
void makePyGiSubEntityTraitsWrapper()
{
    class_<PyGiSubEntityTraits, bases<PyRxObject>>("SubEntityTraits", boost::python::no_init)
        .def("setColor", &PyGiSubEntityTraits::setColor)
        .def("className", &PyGiSubEntityTraits::className).staticmethod("className")
        .def("desc", &PyGiSubEntityTraits::desc).staticmethod("desc")
        ;
}

PyGiSubEntityTraits::PyGiSubEntityTraits(AcGiSubEntityTraits* ptr, bool autoDelete)
    : PyRxObject(ptr, autoDelete, false)
{
}

void PyGiSubEntityTraits::setColor(const Adesk::UInt16 color)
{
    impObj()->setColor(color);
}

std::string PyGiSubEntityTraits::className()
{
    return "AcGiSubEntityTraits";
}

PyRxClass PyGiSubEntityTraits::desc()
{
    return PyRxClass(AcGiSubEntityTraits::desc(), false);
}

AcGiSubEntityTraits* PyGiSubEntityTraits::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcGiSubEntityTraits*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
//PyGiDrawableTraits
void makePyGiDrawableTraitsWrapper()
{
    class_<PyGiDrawableTraits, bases<PyGiSubEntityTraits>>("DrawableTraits", boost::python::no_init)
        .def("className", &PyGiDrawableTraits::className).staticmethod("className")
        .def("desc", &PyGiDrawableTraits::desc).staticmethod("desc")
        ;
}

PyGiDrawableTraits::PyGiDrawableTraits(AcGiDrawableTraits* ptr, bool autoDelete)
    : PyGiSubEntityTraits(ptr, autoDelete)
{
}

std::string PyGiDrawableTraits::className()
{
    return "AcGiDrawableTraits";
}

PyRxClass PyGiDrawableTraits::desc()
{
    return PyRxClass(AcGiDrawableTraits::desc(), false);
}

AcGiDrawableTraits* PyGiDrawableTraits::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcGiDrawableTraits*>(m_pyImp.get());
}
