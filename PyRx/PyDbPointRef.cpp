#include "stdafx.h"
#include "PyDbPointRef.h"

using namespace boost::python;

void makePyDbPointRefWrapper()
{
    PyDocString DS("PointRef");
    class_<PyDbPointRef, bases<PyRxObject>>("PointRef", boost::python::no_init)
        .def("desc", &PyDbPointRef::desc, DS.SARGS()).staticmethod("desc")
        .def("className", &PyDbPointRef::className, DS.SARGS()).staticmethod("className")
        ;
}

PyDbPointRef::PyDbPointRef(const AcDbPointRef* ptr)
    : PyDbPointRef(const_cast<AcDbPointRef*>(ptr), false)
{
}

PyDbPointRef::PyDbPointRef(AcDbPointRef* ptr, bool autoDelete)
    :PyRxObject(ptr, autoDelete, false)
{
}

PyRxClass PyDbPointRef::desc()
{
    return PyRxClass(AcDbPointRef::desc(), false);
}

std::string PyDbPointRef::className()
{
    return std::string{ "AcDbPointRef" };
}

AcDbPointRef* PyDbPointRef::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbPointRef*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
//PyDbOsnapPointRef
void makePyDbOsnapPointRefWrapper()
{
    PyDocString DS("OsnapPointRef");
    class_<PyDbOsnapPointRef, bases<PyDbPointRef>>("OsnapPointRef")
        .def(init<>())
        .def(init<const AcGePoint3d&>())
        .def("desc", &PyDbOsnapPointRef::desc, DS.SARGS()).staticmethod("desc")
        .def("className", &PyDbOsnapPointRef::className, DS.SARGS()).staticmethod("className")
        ;
}

PyDbOsnapPointRef::PyDbOsnapPointRef()
    : PyDbOsnapPointRef(new AcDbOsnapPointRef(), true)
{
}

PyDbOsnapPointRef::PyDbOsnapPointRef(const AcGePoint3d& refPt)
    : PyDbOsnapPointRef(new AcDbOsnapPointRef(refPt), true)
{
}

PyDbOsnapPointRef::PyDbOsnapPointRef(const AcDbOsnapPointRef* ptr)
    : PyDbOsnapPointRef(const_cast<AcDbOsnapPointRef*>(ptr), false)
{
}

PyDbOsnapPointRef::PyDbOsnapPointRef(AcDbOsnapPointRef* ptr, bool autoDelete)
    :PyDbPointRef(ptr, autoDelete)
{
}

PyRxClass PyDbOsnapPointRef::desc()
{
    return PyRxClass(AcDbOsnapPointRef::desc(), false);
}

std::string PyDbOsnapPointRef::className()
{
    return std::string{ "AcDbOsnapPointRef" };
}

AcDbOsnapPointRef* PyDbOsnapPointRef::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbOsnapPointRef*>(m_pyImp.get());
}
