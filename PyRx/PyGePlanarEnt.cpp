#include "stdafx.h"
#include "PyGePlanarEnt.h"
#include "PyGeLinearEnt3d.h"
#include "PyGeCurve3d.h"
using namespace boost::python;

//-----------------------------------------------------------------------------------------
//AcGePlanarEnt wrapper
void makeAcGePlanarEntWrapper()
{
    class_<PyGePlanarEnt, bases<PyAcGeSurface>>("PlanarEnt", boost::python::no_init)
        .def("intersectWith", &PyGePlanarEnt::intersectWith1)
        .def("intersectWith", &PyGePlanarEnt::intersectWith2)
        .def("closestPointToLinearEnt", &PyGePlanarEnt::closestPointToLinearEnt1)
        .def("closestPointToLinearEnt", &PyGePlanarEnt::closestPointToLinearEnt2)
        .def("closestPointToPlanarEnt", &PyGePlanarEnt::closestPointToPlanarEnt1)
        .def("closestPointToPlanarEnt", &PyGePlanarEnt::closestPointToPlanarEnt2)
        .def("isParallelTo", &PyGePlanarEnt::isParallelTo1)
        .def("isParallelTo", &PyGePlanarEnt::isParallelTo2)
        .def("isParallelTo", &PyGePlanarEnt::isParallelTo3)
        .def("isParallelTo", &PyGePlanarEnt::isParallelTo4)
        .def("isPerpendicularTo", &PyGePlanarEnt::isPerpendicularTo1)
        .def("isPerpendicularTo", &PyGePlanarEnt::isPerpendicularTo2)
        .def("isPerpendicularTo", &PyGePlanarEnt::isPerpendicularTo3)
        .def("isPerpendicularTo", &PyGePlanarEnt::isPerpendicularTo4)
        .def("isCoplanarTo", &PyGePlanarEnt::isCoplanarTo1)
        .def("isCoplanarTo", &PyGePlanarEnt::isCoplanarTo2)
        .def("pointOnPlane", &PyGePlanarEnt::pointOnPlane)
        .def("normal", &PyGePlanarEnt::normal)
        .def("getCoefficients", &PyGePlanarEnt::getCoefficients)
        .def("getCoordSystem", &PyGePlanarEnt::getCoordSystem)
        .def("className", &PyGePlanarEnt::className).staticmethod("className")
        ;
}

PyGePlanarEnt::PyGePlanarEnt(AcGePlanarEnt* pEnt)
    : PyAcGeSurface(pEnt)
{
}

PyGePlanarEnt::PyGePlanarEnt(AcGeEntity3d* pEnt)
    : PyAcGeSurface(pEnt)
{
    //TODO check type
}

boost::python::tuple PyGePlanarEnt::intersectWith1(const PyGeLinearEnt3d& linEnt) const
{
    PyAutoLockGIL lock;
    AcGePoint3d pnt;
    auto res = impObj()->intersectWith(*linEnt.impObj(), pnt);
    return boost::python::make_tuple(res, pnt);
}

boost::python::tuple PyGePlanarEnt::intersectWith2(const PyGeLinearEnt3d& linEnt, const AcGeTol& tol) const
{
    PyAutoLockGIL lock;
    AcGePoint3d pnt;
    auto res = impObj()->intersectWith(*linEnt.impObj(), pnt, tol);
    return boost::python::make_tuple(res, pnt);
}

boost::python::tuple PyGePlanarEnt::closestPointToLinearEnt1(const PyGeLinearEnt3d& line) const
{
    PyAutoLockGIL lock;
    AcGePoint3d pnt;
    auto res = impObj()->closestPointToLinearEnt(*line.impObj(), pnt);
    return boost::python::make_tuple(res, pnt);
}

boost::python::tuple PyGePlanarEnt::closestPointToLinearEnt2(const PyGeLinearEnt3d& line, const AcGeTol& tol) const
{
    PyAutoLockGIL lock;
    AcGePoint3d pnt;
    auto res = impObj()->closestPointToLinearEnt(*line.impObj(), pnt, tol);
    return boost::python::make_tuple(res, pnt);
}

boost::python::tuple PyGePlanarEnt::closestPointToPlanarEnt1(const PyGePlanarEnt& line) const
{
    PyAutoLockGIL lock;
    AcGePoint3d pnt;
    auto res = impObj()->closestPointToPlanarEnt(*line.impObj(), pnt);
    return boost::python::make_tuple(res, pnt);
}

boost::python::tuple PyGePlanarEnt::closestPointToPlanarEnt2(const PyGePlanarEnt& line, const AcGeTol& tol) const
{
    PyAutoLockGIL lock;
    AcGePoint3d pnt;
    auto res = impObj()->closestPointToPlanarEnt(*line.impObj(), pnt, tol);
    return boost::python::make_tuple(res, pnt);
}

Adesk::Boolean PyGePlanarEnt::isParallelTo1(const PyGeLinearEnt3d& linEnt) const
{
    return impObj()->isParallelTo(*linEnt.impObj());
}

Adesk::Boolean PyGePlanarEnt::isParallelTo2(const PyGeLinearEnt3d& linEnt, const AcGeTol& tol) const
{
    return impObj()->isParallelTo(*linEnt.impObj(), tol);
}

Adesk::Boolean PyGePlanarEnt::isParallelTo3(const PyGePlanarEnt& otherPlnEnt) const
{
    return impObj()->isParallelTo(*otherPlnEnt.impObj());
}

Adesk::Boolean PyGePlanarEnt::isParallelTo4(const PyGePlanarEnt& otherPlnEnt, const AcGeTol& tol) const
{
    return impObj()->isParallelTo(*otherPlnEnt.impObj(), tol);
}

Adesk::Boolean PyGePlanarEnt::isPerpendicularTo1(const PyGeLinearEnt3d& linEnt) const
{
    return impObj()->isPerpendicularTo(*linEnt.impObj());
}

Adesk::Boolean PyGePlanarEnt::isPerpendicularTo2(const PyGeLinearEnt3d& linEnt, const AcGeTol& tol) const
{
    return impObj()->isPerpendicularTo(*linEnt.impObj(), tol);
}

Adesk::Boolean PyGePlanarEnt::isPerpendicularTo3(const PyGePlanarEnt& linEnt) const
{
    return impObj()->isPerpendicularTo(*linEnt.impObj());
}

Adesk::Boolean PyGePlanarEnt::isPerpendicularTo4(const PyGePlanarEnt& linEnt, const AcGeTol& tol) const
{
    return impObj()->isPerpendicularTo(*linEnt.impObj(), tol);
}

Adesk::Boolean PyGePlanarEnt::isCoplanarTo1(const PyGePlanarEnt& otherPlnEnt) const
{
    return impObj()->isCoplanarTo(*otherPlnEnt.impObj());
}

Adesk::Boolean PyGePlanarEnt::isCoplanarTo2(const PyGePlanarEnt& otherPlnEnt, const AcGeTol& tol) const
{
    return impObj()->isCoplanarTo(*otherPlnEnt.impObj(), tol);
}

AcGePoint3d PyGePlanarEnt::pointOnPlane() const
{
    return impObj()->pointOnPlane();
}

AcGeVector3d PyGePlanarEnt::normal() const
{
    return impObj()->normal();
}

boost::python::tuple PyGePlanarEnt::getCoefficients() const
{
    PyAutoLockGIL lock;
    double a, b, c, d;
    impObj()->getCoefficients(a, b, c, d);
    return boost::python::make_tuple(a, b, c, d);
}

boost::python::tuple PyGePlanarEnt::getCoordSystem() const
{
    PyAutoLockGIL lock;
    AcGePoint3d origin;
    AcGeVector3d axis1;
    AcGeVector3d axis2;
    impObj()->getCoordSystem(origin, axis1, axis2);
    return boost::python::make_tuple(origin, axis1, axis2);
}

std::string PyGePlanarEnt::className()
{
    return "AcGePlanarEnt";
}

AcGePlanarEnt* PyGePlanarEnt::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_imp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcGePlanarEnt*>(m_imp.get());
}
