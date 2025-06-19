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
        .def("osnapType", &PyDbOsnapPointRef::osnapType, DS.ARGS(7358))
        .def("setOsnapType", &PyDbOsnapPointRef::setOsnapType, DS.ARGS({ "val: PyDb.OsnapType" }, 7363))
        .def("setIdPath", &PyDbOsnapPointRef::setIdPath, DS.ARGS({ "id: PyDb.ObjectId", "sub: PyDb.SubentType","gsMarker: int" }, 7360))
        .def("setIntIdPath", &PyDbOsnapPointRef::setIntIdPath, DS.ARGS({ "id: PyDb.ObjectId", "sub: PyDb.SubentType","gsMarker: int" }, 7361))
        .def("setPoint", &PyDbOsnapPointRef::setPoint, DS.ARGS({ "pt: PyGe.Point3d" }, 7364))
        .def("point", &PyDbOsnapPointRef::point, DS.ARGS(7359))
        .def("nearPointParam", &PyDbOsnapPointRef::nearPointParam, DS.ARGS(7357))
        .def("setNearPointParam", &PyDbOsnapPointRef::setNearPointParam, DS.ARGS({ "val: float" }))
        .def("desc", &PyDbOsnapPointRef::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("className", &PyDbOsnapPointRef::className, DS.SARGS()).staticmethod("className")
        ;
}

PyDbOsnapPointRef::PyDbOsnapPointRef()
    : PyDbOsnapPointRef(new AcDbOsnapPointRef(), true)
{
}

#if defined(_BRXTARGET250)
PyDbOsnapPointRef::PyDbOsnapPointRef(const AcGePoint3d& refPt)
    : PyDbOsnapPointRef(new AcDbOsnapPointRef(), true)
{
    impObj()->setPoint(refPt);
}
#else
PyDbOsnapPointRef::PyDbOsnapPointRef(const AcGePoint3d& refPt)
    : PyDbOsnapPointRef(new AcDbOsnapPointRef(refPt), true)
{
}
#endif

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

void PyDbOsnapPointRef::setIntIdPath(PyDbObjectId& id, AcDb::SubentType type, Adesk::GsMarker gsMarker) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost{};
#else
    AcDbFullSubentPath idPath(id.m_id, AcDbSubentId(type, gsMarker));
    PyThrowBadEs(impObj()->setIntIdPath(idPath));
#endif
}

void PyDbOsnapPointRef::setPoint(const AcGePoint3d& pt) const
{
    PyThrowBadEs(impObj()->setPoint(pt));
}

AcGePoint3d PyDbOsnapPointRef::point() const
{
    return impObj()->point();
}

double PyDbOsnapPointRef::nearPointParam() const
{
    return impObj()->nearPointParam();
}

void PyDbOsnapPointRef::setNearPointParam(double newVal) const
{
    PyThrowBadEs(impObj()->setNearPointParam(newVal));
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
