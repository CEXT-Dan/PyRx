#include "stdafx.h"
#include "PyAcGeSurface.h"
#include "PyGePointEnt3d.h"
#include "PyGeInterval.h"

using namespace boost::python;
// ---------------------------------------------------------------------------------------- -
//AcGeSurface wrapper
void makeAcGeSurfaceWrapper()
{
    class_<PyAcGeSurface, bases<PyGeEntity3d>>("Surface", boost::python::no_init)
        .def("paramOf", &PyAcGeSurface::paramOf)
        .def("paramOf", &PyAcGeSurface::paramOfTol)
        .def("isOn", &PyAcGeSurface::isOn1)
        .def("isOn", &PyAcGeSurface::isOn2)
        .def("isOn", &PyAcGeSurface::isOn3)
        .def("isOn", &PyAcGeSurface::isOn4)
        .def("closestPointTo", &PyAcGeSurface::closestPointTo1)
        .def("closestPointTo", &PyAcGeSurface::closestPointTo2)
        .def("distanceTo", &PyAcGeSurface::distanceTo1)
        .def("distanceTo", &PyAcGeSurface::distanceTo2)
        .def("isNormalReversed", &PyAcGeSurface::isNormalReversed)
        .def("reverseNormal", &PyAcGeSurface::reverseNormal, return_self<>())
        .def("isClosedInU", &PyAcGeSurface::isClosedInU1)
        .def("isClosedInU", &PyAcGeSurface::isClosedInU2)
        .def("isClosedInV", &PyAcGeSurface::isClosedInV1)
        .def("isClosedInV", &PyAcGeSurface::isClosedInV2)
        .def("evalPoint", &PyAcGeSurface::evalPoint1)
        .def("evalPoint", &PyAcGeSurface::evalPoint2)
        .def("evalPoint", &PyAcGeSurface::evalPoint3)
        .def("className", &PyAcGeSurface::className).staticmethod("className")
        ;
}

PyAcGeSurface::PyAcGeSurface(AcGeSurface* pEnt)
    :PyGeEntity3d(pEnt)
{
}

PyAcGeSurface::PyAcGeSurface(AcGeEntity3d* pEnt)
    : PyGeEntity3d(pEnt)
{
}

AcGePoint2d PyAcGeSurface::paramOf(const AcGePoint3d& pnt) const
{
    return impObj()->paramOf(pnt);
}

AcGePoint2d PyAcGeSurface::paramOfTol(const AcGePoint3d& pnt, const AcGeTol& tol) const
{
    return impObj()->paramOf(pnt, tol);
}

Adesk::Boolean PyAcGeSurface::isOn1(const AcGePoint3d& pnt) const
{
    return impObj()->isOn(pnt);
}

Adesk::Boolean PyAcGeSurface::isOn2(const AcGePoint3d& pnt, const AcGeTol& tol) const
{
    return impObj()->isOn(pnt, tol);
}

Adesk::Boolean PyAcGeSurface::isOn3(const AcGePoint3d& pnt, AcGePoint2d& paramPoint) const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->isOn(pnt, paramPoint);
#endif
}

Adesk::Boolean PyAcGeSurface::isOn4(const AcGePoint3d& pnt, AcGePoint2d& paramPoint, const AcGeTol& tol) const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->isOn(pnt, paramPoint, tol);
#endif
}

AcGePoint3d PyAcGeSurface::closestPointTo1(const AcGePoint3d& pnt) const
{
    return impObj()->closestPointTo(pnt);
}

AcGePoint3d PyAcGeSurface::closestPointTo2(const AcGePoint3d& pnt, const AcGeTol& tol) const
{
    return impObj()->closestPointTo(pnt, tol);
}

PyGePointOnSurface PyAcGeSurface::getClosestPointTo1(const AcGePoint3d& pnt) const
{
    AcGePointOnSurface pos;
    impObj()->getClosestPointTo(pnt, pos);
    return PyGePointOnSurface(pos.copy());
}

PyGePointOnSurface PyAcGeSurface::getClosestPointTo2(const AcGePoint3d& pnt, const AcGeTol& tol) const
{
    AcGePointOnSurface pos;
    impObj()->getClosestPointTo(pnt, pos, tol);
    return PyGePointOnSurface(pos.copy());
}

double PyAcGeSurface::distanceTo1(const AcGePoint3d& pnt) const
{
    return impObj()->distanceTo(pnt);
}

double PyAcGeSurface::distanceTo2(const AcGePoint3d& pnt, const AcGeTol& tol) const
{
    return impObj()->distanceTo(pnt, tol);
}

Adesk::Boolean PyAcGeSurface::isNormalReversed() const
{
    return impObj()->isNormalReversed();
}

PyAcGeSurface& PyAcGeSurface::reverseNormal()
{
    impObj()->reverseNormal();
    return *this;
}

void PyAcGeSurface::getEnvelope(PyGeInterval& intrvlX, PyGeInterval& intrvlY) const
{
    impObj()->getEnvelope(intrvlX.imp, intrvlY.imp);
}

Adesk::Boolean PyAcGeSurface::isClosedInU1() const
{
    return impObj()->isClosedInU();
}

Adesk::Boolean PyAcGeSurface::isClosedInU2(const AcGeTol& tol) const
{
    return impObj()->isClosedInU(tol);
}

Adesk::Boolean PyAcGeSurface::isClosedInV1() const
{
    return impObj()->isClosedInV();
}

Adesk::Boolean PyAcGeSurface::isClosedInV2(const AcGeTol& tol) const
{
    return impObj()->isClosedInV(tol);
}

AcGePoint3d PyAcGeSurface::evalPoint1(const AcGePoint2d& param) const
{
    return impObj()->evalPoint(param);
}

AcGePoint3d PyAcGeSurface::evalPoint2(const AcGePoint2d& param, int derivOrd, boost::python::list& derivatives) const
{
    AcGeVector3dArray vecs;
    auto pnt = impObj()->evalPoint(param, derivOrd, vecs);
    for (auto& vec : vecs)
        derivatives.append(vec);
    return pnt;
}

AcGePoint3d PyAcGeSurface::evalPoint3(const AcGePoint2d& param, int derivOrd, boost::python::list& derivatives, AcGeVector3d& normal) const
{
    AcGeVector3dArray vecs;
    auto pnt = impObj()->evalPoint(param, derivOrd, vecs, normal);
    for (auto& vec : vecs)
        derivatives.append(vec);
    return pnt;
}

std::string PyAcGeSurface::className()
{
    return "AcGeSurface";
}

AcGeSurface* PyAcGeSurface::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_imp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcGeSurface*>(m_imp.get());
}
