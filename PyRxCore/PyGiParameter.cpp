#include "stdafx.h"
#include "PyGiParameter.h"

using namespace boost::python;

void makePyGiParameterWrapper()
{
    class_<PyRxCopyOnWriteObject, bases<PyRxObject>>("RxCopyOnWriteObject", no_init)
        .def("className", &PyRxCopyOnWriteObject::className).staticmethod("className")
        .def("desc", &PyRxCopyOnWriteObject::desc).staticmethod("desc")
        ;

    class_<PyGiParameter, bases<PyRxCopyOnWriteObject>>("GiParameter", no_init)
        .def("className", &PyGiParameter::className).staticmethod("className")
        .def("desc", &PyGiParameter::desc).staticmethod("desc")
        ;

    class_<PyGiEdgeData, bases<PyGiParameter>>("GiEdgeData")
        .def("className", &PyGiEdgeData::className).staticmethod("className")
        .def("desc", &PyGiEdgeData::desc).staticmethod("desc")
        ;

    class_<PyGiFaceData, bases<PyGiParameter>>("GiFaceData")
        .def("className", &PyGiFaceData::className).staticmethod("className")
        .def("desc", &PyGiFaceData::desc).staticmethod("desc")
        ;

    class_<PyGiMapper, bases<PyGiParameter>>("GiMapper")
        .def("className", &PyGiMapper::className).staticmethod("className")
        .def("desc", &PyGiMapper::desc).staticmethod("desc")
        ;

    class_<PyGiPolyline, bases<PyGiParameter>>("GiPolyline")
        .def("className", &PyGiPolyline::className).staticmethod("className")
        .def("desc", &PyGiPolyline::desc).staticmethod("desc")
        ;

    class_<PyGiTextStyle, bases<PyGiParameter>>("GiTextStyle")
        .def("className", &PyGiTextStyle::className).staticmethod("className")
        .def("desc", &PyGiTextStyle::desc).staticmethod("desc")
        ;

    class_<PyGiVertexData, bases<PyGiParameter>>("GiVertexData")
        .def("className", &PyGiVertexData::className).staticmethod("className")
        .def("desc", &PyGiVertexData::desc).staticmethod("desc")
        ;
}

PyRxCopyOnWriteObject::PyRxCopyOnWriteObject(AcRxCopyOnWriteObject* ptr, bool autoDelete)
    : PyRxObject(ptr, autoDelete, false)
{
}

PyRxClass PyRxCopyOnWriteObject::desc()
{
    return PyRxClass(AcRxCopyOnWriteObject::desc(), false);
}

std::string PyRxCopyOnWriteObject::className()
{
    return "AcRxCopyOnWriteObject";
}

PyRxCopyOnWriteObject PyRxCopyOnWriteObject::cast(const PyRxObject& src)
{
    return PyRxObjectCast<PyRxCopyOnWriteObject>(src);
}

AcRxCopyOnWriteObject* PyRxCopyOnWriteObject::impObj(const std::source_location& src) const
{
    if (m_pyImp == nullptr) [[unlikely]]
        throw PyNullObject(src);
    return static_cast<AcRxCopyOnWriteObject*>(m_pyImp.get());
}

PyGiParameter::PyGiParameter(AcGiParameter* ptr, bool autoDelete)
    : PyRxCopyOnWriteObject(ptr, autoDelete)
{
}

PyRxClass PyGiParameter::desc()
{
    return PyRxClass(AcGiParameter::desc(), false);
}

std::string PyGiParameter::className()
{
    return "AcGiParameter";
}

PyGiParameter PyGiParameter::cast(const PyRxObject& src)
{
    return PyRxObjectCast<PyGiParameter>(src);
}

AcGiParameter* PyGiParameter::impObj(const std::source_location& src) const
{
    if (m_pyImp == nullptr) [[unlikely]]
        throw PyNullObject(src);
    return static_cast<AcGiParameter*>(m_pyImp.get());
}

#define PYGI_PARAMETER_IMPLEMENTATION(PY_CLASS, AC_CLASS) \
    PY_CLASS::PY_CLASS() \
        : PyGiParameter(new AC_CLASS(), true) \
    { \
    } \
    PY_CLASS::PY_CLASS(AC_CLASS* ptr, bool autoDelete) \
        : PyGiParameter(ptr, autoDelete) \
    { \
    } \
    PyRxClass PY_CLASS::desc() \
    { \
        return PyRxClass(AC_CLASS::desc(), false); \
    } \
    std::string PY_CLASS::className() \
    { \
        return #AC_CLASS; \
    } \
    PY_CLASS PY_CLASS::cast(const PyRxObject& src) \
    { \
        return PyRxObjectCast<PY_CLASS>(src); \
    } \
    AC_CLASS* PY_CLASS::impObj(const std::source_location& src) const \
    { \
        if (m_pyImp == nullptr) [[unlikely]] \
            throw PyNullObject(src); \
        return static_cast<AC_CLASS*>(m_pyImp.get()); \
    }

PYGI_PARAMETER_IMPLEMENTATION(PyGiEdgeData, AcGiEdgeData)
PYGI_PARAMETER_IMPLEMENTATION(PyGiFaceData, AcGiFaceData)
PYGI_PARAMETER_IMPLEMENTATION(PyGiMapper, AcGiMapper)
PYGI_PARAMETER_IMPLEMENTATION(PyGiPolyline, AcGiPolyline)
PYGI_PARAMETER_IMPLEMENTATION(PyGiTextStyle, AcGiTextStyle)
PYGI_PARAMETER_IMPLEMENTATION(PyGiVertexData, AcGiVertexData)

#undef PYGI_PARAMETER_IMPLEMENTATION
