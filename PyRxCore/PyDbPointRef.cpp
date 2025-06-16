#include "stdafx.h"
#include "PyDbPointRef.h"
#include "PyDbObjectId.h"

using namespace boost::python;

void makePyDbPointRefWrapper()
{
    PyDocString DS("PointRef");
    class_<PyDbPointRef, bases<PyRxObject>>("PointRef", boost::python::no_init)
        .def("desc", &PyDbPointRef::desc, DS.SARGS(15560)).staticmethod("desc")
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
    constexpr const std::string_view ctor = "Overloads:\n"
        "- None: Any\n"
        "- refPt: PyGe.Point3d\n";

    PyDocString DS("OsnapPointRef");
    class_<PyDbOsnapPointRef, bases<PyDbPointRef>>("OsnapPointRef")
        .def(init<>())
        .def(init<const AcGePoint3d&>(DS.CTOR(ctor, 7345)))
        .def("osnapType", &PyDbOsnapPointRef::osnapType, DS.ARGS())
        .def("setOsnapType", &PyDbOsnapPointRef::setOsnapType, DS.ARGS({ "val: PyDb.OsnapType" }))
        .def("setIdPath", &PyDbOsnapPointRef::setIdPath, DS.ARGS({ "id: PyDb.ObjectId", "sub: PyDb.SubentType","gsMarker: int" }))
        .def("setPoint", &PyDbOsnapPointRef::setPoint, DS.ARGS({ "pt: PyGe.Point3d" }))
        .def("point", &PyDbOsnapPointRef::point, DS.ARGS())
        .def("desc", &PyDbOsnapPointRef::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("className", &PyDbOsnapPointRef::className, DS.SARGS()).staticmethod("className")
        ;
}

PyDbOsnapPointRef::PyDbOsnapPointRef()
    : PyDbOsnapPointRef(new AcDbOsnapPointRef(), true)
{
}

PyDbOsnapPointRef::PyDbOsnapPointRef(const AcGePoint3d& refPt)
#if defined(_BRXTARGET250)
    : PyDbOsnapPointRef(new AcDbOsnapPointRef(), true)
#else
    : PyDbOsnapPointRef(new AcDbOsnapPointRef(refPt), true)
#endif
{
#if defined(_BRXTARGET250)
    impObj()->setPoint(refPt);
#endif
}

PyDbOsnapPointRef::PyDbOsnapPointRef(const AcDbOsnapPointRef* ptr)
    : PyDbOsnapPointRef(const_cast<AcDbOsnapPointRef*>(ptr), false)
{
}

PyDbOsnapPointRef::PyDbOsnapPointRef(AcDbOsnapPointRef* ptr, bool autoDelete)
    :PyDbPointRef(ptr, autoDelete)
{
}

AcDbPointRef::OsnapType PyDbOsnapPointRef::osnapType() const
{
    return impObj()->osnapType();
}

void PyDbOsnapPointRef::setOsnapType(AcDbPointRef::OsnapType osnType) const
{
    PyThrowBadEs(impObj()->setOsnapType(osnType));
}

void PyDbOsnapPointRef::setIdPath(PyDbObjectId& id, AcDb::SubentType type, Adesk::GsMarker marker) const
{
    AcDbFullSubentPath idPath(id.m_id, AcDbSubentId(type, marker));
    PyThrowBadEs(impObj()->setIdPath(idPath));
}

void PyDbOsnapPointRef::setPoint(const AcGePoint3d& pt) const
{
    PyThrowBadEs(impObj()->setPoint(pt));
}

AcGePoint3d PyDbOsnapPointRef::point() const
{
    return impObj()->point();
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
//#endif