#include "stdafx.h"
#include "PyGePlane.h"
#include "PyGeLinearEnt3d.h"

using namespace boost::python;

//-----------------------------------------------------------------------------------------
//PyGePlane wrapper
void makePyGePlaneWrapper()
{
    class_<PyGePlane, bases<PyGePlanarEnt>>("Plane")
        .def(init<>())
        .def(init<const AcGePoint3d&, const AcGeVector3d&>())
        .def(init<const AcGePoint3d&, const AcGeVector3d&, const AcGeVector3d&>())
        .def(init<const AcGePoint3d&, const AcGePoint3d&, const AcGePoint3d&>())
        .def(init<double, double, double, double>())
        .def("signedDistanceTo", &PyGePlane::signedDistanceTo)
        .def("intersectWith", &PyGePlane::intersectWith1)
        .def("intersectWith", &PyGePlane::intersectWith2)
        .def("intersectWith", &PyGePlane::intersectWith3)
        .def("intersectWith", &PyGePlane::intersectWith4)
        .def("intersectWith", &PyGePlane::intersectWith5)
        .def("intersectWith", &PyGePlane::intersectWith6)
        .def("set", &PyGePlane::set1)
        .def("set", &PyGePlane::set2)
        .def("set", &PyGePlane::set3)
        .def("set", &PyGePlane::set4)
        .def("cast", &PyGePlane::cast).staticmethod("cast")
        .def("copycast", &PyGePlane::cast).staticmethod("copycast")
        .def("className", &PyGePlane::className).staticmethod("className")
        ;
}

PyGePlane::PyGePlane()
    : PyGePlanarEnt(new AcGePlane())
{
}

PyGePlane::PyGePlane(AcGePlane* pEnt)
    : PyGePlanarEnt(pEnt)
{
}

PyGePlane::PyGePlane(AcGeEntity3d* pEnt)
    : PyGePlanarEnt(pEnt)
{
    //TODO check type
}

PyGePlane::PyGePlane(const AcGePlane& ent)
    : PyGePlanarEnt(new AcGePlane(ent))
{
}

PyGePlane::PyGePlane(const AcGePoint3d& origin, const AcGeVector3d& normal)
    : PyGePlanarEnt(new AcGePlane(origin, normal))
{
}

PyGePlane::PyGePlane(const AcGePoint3d& pntU, const AcGePoint3d& org, const AcGePoint3d& pntV)
    : PyGePlanarEnt(new AcGePlane(pntU, org, pntV))
{
}

PyGePlane::PyGePlane(const AcGePoint3d& org, const AcGeVector3d& uAxis, const AcGeVector3d& vAxis)
    : PyGePlanarEnt(new AcGePlane(org, uAxis, vAxis))
{
}

PyGePlane::PyGePlane(double a, double b, double c, double d)
    : PyGePlanarEnt(new AcGePlane(a, b, c, d))
{
}

double PyGePlane::signedDistanceTo(const AcGePoint3d& pnt) const
{
    return impObj()->distanceTo(pnt);
}

boost::python::tuple PyGePlane::intersectWith1(const PyGeLinearEnt3d& linEnt) const
{
    PyAutoLockGIL lock;
    AcGePoint3d resultPnt;
    auto res = impObj()->intersectWith(*linEnt.impObj(), resultPnt);
    return boost::python::make_tuple(res, resultPnt);
}

boost::python::tuple PyGePlane::intersectWith2(const PyGeLinearEnt3d& linEnt, const AcGeTol& tol) const
{
    PyAutoLockGIL lock;
    AcGePoint3d resultPnt;
    auto res = impObj()->intersectWith(*linEnt.impObj(), resultPnt, tol);
    return boost::python::make_tuple(res, resultPnt);
}

boost::python::tuple PyGePlane::intersectWith3(const PyGePlane& otherPln) const
{
    PyAutoLockGIL lock;
    AcGeLine3d resultLine;
    auto res = impObj()->intersectWith(*otherPln.impObj(), resultLine);
    return boost::python::make_tuple(res, PyGeLine3d(resultLine));
}

boost::python::tuple PyGePlane::intersectWith4(const PyGePlane& otherPln, const AcGeTol& tol) const
{
    PyAutoLockGIL lock;
    AcGeLine3d resultLine;
    auto res = impObj()->intersectWith(*otherPln.impObj(), resultLine, tol);
    return boost::python::make_tuple(res, PyGeLine3d(resultLine));
}

boost::python::tuple PyGePlane::intersectWith5(const PyGeBoundedPlane& bndPln) const
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    PyAutoLockGIL lock;
    AcGeLineSeg3d resultLine;
    auto res = impObj()->intersectWith(*bndPln.impObj(), resultLine);
    return boost::python::make_tuple(res, PyGeLineSeg3d(resultLine));
#endif
}

boost::python::tuple PyGePlane::intersectWith6(const PyGeBoundedPlane& bndPln, const AcGeTol& tol) const
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    PyAutoLockGIL lock;
    AcGeLineSeg3d resultLine;
    auto res = impObj()->intersectWith(*bndPln.impObj(), resultLine, tol);
    return boost::python::make_tuple(res, PyGeLineSeg3d(resultLine));
#endif
}

void PyGePlane::set1(const AcGePoint3d& pnt, const AcGeVector3d& normal)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    impObj()->set(pnt, normal);
#endif
}

void PyGePlane::set2(const AcGePoint3d& pntU, const AcGePoint3d& org, const AcGePoint3d& pntV)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    impObj()->set(pntU, org, pntV);
#endif
}

void PyGePlane::set3(double a, double b, double c, double d)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    impObj()->set(a, b, c, d);
#endif
}

void PyGePlane::set4(const AcGePoint3d& org, const AcGeVector3d& uAxis, const AcGeVector3d& vAxis)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    impObj()->set(org, uAxis, vAxis);
#endif
}

PyGePlane PyGePlane::cast(const PyGeEntity3d& src)
{
    if (!src.impObj()->isKindOf(AcGe::EntityId::kPlane))
        PyThrowBadEs(Acad::eInvalidInput);
    return PyGeEntity3dCast<PyGePlane>(src);
}

PyGePlane PyGePlane::copycast(const PyGeEntity3d& src)
{
    if (!src.impObj()->isKindOf(AcGe::EntityId::kPlane))
        PyThrowBadEs(Acad::eInvalidInput);
    return PyGePlane(src.impObj()->copy());
}

std::string PyGePlane::className()
{
    return "AcGePlane";
}

AcGePlane* PyGePlane::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_imp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcGePlane*>(m_imp.get());
}

//-----------------------------------------------------------------------------------------
//PyGeBoundedPlane wrapper
void makePyGeBoundedPlaneWrapper()
{
    class_<PyGeBoundedPlane, bases<PyGePlanarEnt>>("BoundedPlane")
        .def(init<>())
        .def(init<const AcGePoint3d&, const AcGeVector3d&, const AcGeVector3d&>())
        .def(init<const AcGePoint3d&, const AcGePoint3d&, const AcGePoint3d&>())
        .def("intersectWith", &PyGeBoundedPlane::intersectWith1)
        .def("intersectWith", &PyGeBoundedPlane::intersectWith2)
        .def("intersectWith", &PyGeBoundedPlane::intersectWith3)
        .def("intersectWith", &PyGeBoundedPlane::intersectWith4)
        .def("intersectWith", &PyGeBoundedPlane::intersectWith5)
        .def("intersectWith", &PyGeBoundedPlane::intersectWith6)
        .def("set", &PyGeBoundedPlane::set1)
        .def("set", &PyGeBoundedPlane::set2)
        .def("cast", &PyGeBoundedPlane::cast).staticmethod("cast")
        .def("copycast", &PyGeBoundedPlane::cast).staticmethod("copycast")
        .def("className", &PyGeBoundedPlane::className).staticmethod("className")
        ;
}

PyGeBoundedPlane::PyGeBoundedPlane()
    : PyGePlanarEnt(new AcGeBoundedPlane())
{
}

PyGeBoundedPlane::PyGeBoundedPlane(AcGeBoundedPlane* pEnt)
    : PyGePlanarEnt(pEnt)
{
}

PyGeBoundedPlane::PyGeBoundedPlane(const AcGeBoundedPlane& plane)
    : PyGePlanarEnt(new AcGeBoundedPlane(plane))
{
}

PyGeBoundedPlane::PyGeBoundedPlane(const AcGePoint3d& origin, const AcGeVector3d& uVec, const AcGeVector3d& vVec)
    : PyGePlanarEnt(new AcGeBoundedPlane(origin, uVec, vVec))
{
}

PyGeBoundedPlane::PyGeBoundedPlane(const AcGePoint3d& p1, const AcGePoint3d& origin, const AcGePoint3d& p2)
    : PyGePlanarEnt(new AcGeBoundedPlane(p1, origin, p2))
{
}

PyGeBoundedPlane::PyGeBoundedPlane(AcGeEntity3d* pEnt)
    : PyGePlanarEnt(pEnt)
{
}

boost::python::tuple PyGeBoundedPlane::intersectWith1(const PyGeLinearEnt3d& linEnt) const
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    PyAutoLockGIL lock;
    AcGePoint3d resultPnt;
    auto res = impObj()->intersectWith(*linEnt.impObj(), resultPnt);
    return boost::python::make_tuple(res, resultPnt);
#endif
}

boost::python::tuple PyGeBoundedPlane::intersectWith2(const PyGeLinearEnt3d& linEnt, const AcGeTol& tol) const
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    PyAutoLockGIL lock;
    AcGePoint3d resultPnt;
    auto res = impObj()->intersectWith(*linEnt.impObj(), resultPnt, tol);
    return boost::python::make_tuple(res, resultPnt);
#endif
}

boost::python::tuple PyGeBoundedPlane::intersectWith3(const PyGePlane& otherPln) const
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    PyAutoLockGIL lock;
    AcGeLineSeg3d resultLine;
    auto res = impObj()->intersectWith(*otherPln.impObj(), resultLine);
    return boost::python::make_tuple(res, PyGeLineSeg3d(resultLine));
#endif
}

boost::python::tuple PyGeBoundedPlane::intersectWith4(const PyGePlane& otherPln, const AcGeTol& tol) const
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    PyAutoLockGIL lock;
    AcGeLineSeg3d resultLine;
    auto res = impObj()->intersectWith(*otherPln.impObj(), resultLine, tol);
    return boost::python::make_tuple(res, PyGeLineSeg3d(resultLine));
#endif
}

boost::python::tuple PyGeBoundedPlane::intersectWith5(const PyGeBoundedPlane& bndPln) const
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    PyAutoLockGIL lock;
    AcGeLineSeg3d resultLine;
    auto res = impObj()->intersectWith(*bndPln.impObj(), resultLine);
    return boost::python::make_tuple(res, PyGeLineSeg3d(resultLine));
#endif
}

boost::python::tuple PyGeBoundedPlane::intersectWith6(const PyGeBoundedPlane& bndPln, const AcGeTol& tol) const
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    PyAutoLockGIL lock;
    AcGeLineSeg3d resultLine;
    auto res = impObj()->intersectWith(*bndPln.impObj(), resultLine, tol);
    return boost::python::make_tuple(res, PyGeLineSeg3d(resultLine));
#endif
}

void PyGeBoundedPlane::set1(const AcGePoint3d& origin, const AcGeVector3d& uVec, const AcGeVector3d& vVec)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    impObj()->set(origin, uVec, vVec);
#endif
}

void PyGeBoundedPlane::set2(const AcGePoint3d& p1, const AcGePoint3d& origin, const AcGePoint3d& p2)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    impObj()->set(p1, origin, p2);
#endif
}

PyGeBoundedPlane PyGeBoundedPlane::cast(const PyGeEntity3d& src)
{
    if (!src.impObj()->isKindOf(AcGe::EntityId::kBoundedPlane))
        PyThrowBadEs(Acad::eInvalidInput);
    return PyGeEntity3dCast<PyGeBoundedPlane>(src);
}

PyGeBoundedPlane PyGeBoundedPlane::copycast(const PyGeEntity3d& src)
{
    if (!src.impObj()->isKindOf(AcGe::EntityId::kBoundedPlane))
        PyThrowBadEs(Acad::eInvalidInput);
    return PyGeBoundedPlane(src.impObj()->copy());
}

std::string PyGeBoundedPlane::className()
{
    return "AcGeBoundedPlane";
}

AcGeBoundedPlane* PyGeBoundedPlane::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_imp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcGeBoundedPlane*>(m_imp.get());
}
