#include "stdafx.h"
#include "PyGeSurface.h"
#include "PyGePointEnt3d.h"
#include "PyGeInterval.h"

using namespace boost::python;
// ---------------------------------------------------------------------------------------- -
//AcGeSurface wrapper
void makePyGeSurfaceWrapper()
{
    class_<PyGeSurface, bases<PyGeEntity3d>>("Surface", boost::python::no_init)
        .def("paramOf", &PyGeSurface::paramOf)
        .def("paramOf", &PyGeSurface::paramOfTol)
        .def("isOn", &PyGeSurface::isOn1)
        .def("isOn", &PyGeSurface::isOn2)
        .def("isOn", &PyGeSurface::isOn3)
        .def("isOn", &PyGeSurface::isOn4)
        .def("closestPointTo", &PyGeSurface::closestPointTo1)
        .def("closestPointTo", &PyGeSurface::closestPointTo2)
        .def("distanceTo", &PyGeSurface::distanceTo1)
        .def("distanceTo", &PyGeSurface::distanceTo2)
        .def("isNormalReversed", &PyGeSurface::isNormalReversed)
        .def("reverseNormal", &PyGeSurface::reverseNormal, return_self<>())
        .def("isClosedInU", &PyGeSurface::isClosedInU1)
        .def("isClosedInU", &PyGeSurface::isClosedInU2)
        .def("isClosedInV", &PyGeSurface::isClosedInV1)
        .def("isClosedInV", &PyGeSurface::isClosedInV2)
        .def("evalPoint", &PyGeSurface::evalPoint1)
        .def("evalPoint", &PyGeSurface::evalPoint2)
        .def("evalPoint", &PyGeSurface::evalPoint3)
        .def("className", &PyGeSurface::className).staticmethod("className")
        ;
}


PyGeSurface::PyGeSurface(AcGeEntity3d* pEnt)
    : PyGeEntity3d(pEnt)
{
}

PyGeSurface::PyGeSurface(AcGeSurface* pEnt, bool autoDelete /*= true*/)
    :PyGeEntity3d(pEnt, autoDelete)
{
}

PyGeSurface::PyGeSurface(const AcGeSurface* pEnt)
    :PyGeEntity3d(const_cast<AcGeSurface*>(pEnt), false)
{
}

AcGePoint2d PyGeSurface::paramOf(const AcGePoint3d& pnt) const
{
    return impObj()->paramOf(pnt);
}

AcGePoint2d PyGeSurface::paramOfTol(const AcGePoint3d& pnt, const AcGeTol& tol) const
{
    return impObj()->paramOf(pnt, tol);
}

Adesk::Boolean PyGeSurface::isOn1(const AcGePoint3d& pnt) const
{
    return impObj()->isOn(pnt);
}

Adesk::Boolean PyGeSurface::isOn2(const AcGePoint3d& pnt, const AcGeTol& tol) const
{
    return impObj()->isOn(pnt, tol);
}

Adesk::Boolean PyGeSurface::isOn3(const AcGePoint3d& pnt, AcGePoint2d& paramPoint) const
{
    return impObj()->isOn(pnt, paramPoint);
}

Adesk::Boolean PyGeSurface::isOn4(const AcGePoint3d& pnt, AcGePoint2d& paramPoint, const AcGeTol& tol) const
{
    return impObj()->isOn(pnt, paramPoint, tol);
}

AcGePoint3d PyGeSurface::closestPointTo1(const AcGePoint3d& pnt) const
{
    return impObj()->closestPointTo(pnt);
}

AcGePoint3d PyGeSurface::closestPointTo2(const AcGePoint3d& pnt, const AcGeTol& tol) const
{
    return impObj()->closestPointTo(pnt, tol);
}

PyGePointOnSurface PyGeSurface::getClosestPointTo1(const AcGePoint3d& pnt) const
{
    AcGePointOnSurface pos;
    impObj()->getClosestPointTo(pnt, pos);
    return PyGePointOnSurface(pos.copy());
}

PyGePointOnSurface PyGeSurface::getClosestPointTo2(const AcGePoint3d& pnt, const AcGeTol& tol) const
{
    AcGePointOnSurface pos;
    impObj()->getClosestPointTo(pnt, pos, tol);
    return PyGePointOnSurface(pos.copy());
}

double PyGeSurface::distanceTo1(const AcGePoint3d& pnt) const
{
    return impObj()->distanceTo(pnt);
}

double PyGeSurface::distanceTo2(const AcGePoint3d& pnt, const AcGeTol& tol) const
{
    return impObj()->distanceTo(pnt, tol);
}

Adesk::Boolean PyGeSurface::isNormalReversed() const
{
    return impObj()->isNormalReversed();
}

PyGeSurface& PyGeSurface::reverseNormal()
{
    impObj()->reverseNormal();
    return *this;
}

void PyGeSurface::getEnvelope(PyGeInterval& intrvlX, PyGeInterval& intrvlY) const
{
    impObj()->getEnvelope(intrvlX.imp, intrvlY.imp);
}

Adesk::Boolean PyGeSurface::isClosedInU1() const
{
    return impObj()->isClosedInU();
}

Adesk::Boolean PyGeSurface::isClosedInU2(const AcGeTol& tol) const
{
    return impObj()->isClosedInU(tol);
}

Adesk::Boolean PyGeSurface::isClosedInV1() const
{
    return impObj()->isClosedInV();
}

Adesk::Boolean PyGeSurface::isClosedInV2(const AcGeTol& tol) const
{
    return impObj()->isClosedInV(tol);
}

AcGePoint3d PyGeSurface::evalPoint1(const AcGePoint2d& param) const
{
    return impObj()->evalPoint(param);
}

AcGePoint3d PyGeSurface::evalPoint2(const AcGePoint2d& param, int derivOrd, boost::python::list& derivatives) const
{
    PyAutoLockGIL lock;
    AcGeVector3dArray vecs;
    auto pnt = impObj()->evalPoint(param, derivOrd, vecs);
    for (auto& vec : vecs)
        derivatives.append(vec);
    return pnt;
}

AcGePoint3d PyGeSurface::evalPoint3(const AcGePoint2d& param, int derivOrd, boost::python::list& derivatives, AcGeVector3d& normal) const
{
    PyAutoLockGIL lock;
    AcGeVector3dArray vecs;
    auto pnt = impObj()->evalPoint(param, derivOrd, vecs, normal);
    for (auto& vec : vecs)
        derivatives.append(vec);
    return pnt;
}

std::string PyGeSurface::className()
{
    return "AcGeSurface";
}

AcGeSurface* PyGeSurface::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_imp == nullptr) [[unlikely]]
        throw PyNullObject(src);
    return static_cast<AcGeSurface*>(m_imp.get());
}
