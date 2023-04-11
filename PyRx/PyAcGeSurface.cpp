#include "stdafx.h"
#include "PyAcGeSurface.h"
#include "PyGePointEnt3d.h"
#include "PyGeInterval.h"

using namespace boost::python;
// ---------------------------------------------------------------------------------------- -
//AcGeSurface wrapper
void makeAcGeSurfaceWrapper()
{
    static auto wrapper = class_<PyAcGeSurface, bases<PyGeEntity3d>>("GeSurface", boost::python::no_init)
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
        .def("reverseNormal", &PyAcGeSurface::reverseNormal, return_value_policy<reference_existing_object>())
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
    //TODO check type
}

AcGePoint2d PyAcGeSurface::paramOf(const AcGePoint3d& pnt) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->paramOf(pnt);
}

AcGePoint2d PyAcGeSurface::paramOfTol(const AcGePoint3d& pnt, const AcGeTol& tol) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->paramOf(pnt, tol);
}

Adesk::Boolean PyAcGeSurface::isOn1(const AcGePoint3d& pnt) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isOn(pnt);
}

Adesk::Boolean PyAcGeSurface::isOn2(const AcGePoint3d& pnt, const AcGeTol& tol) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isOn(pnt, tol);
}

Adesk::Boolean PyAcGeSurface::isOn3(const AcGePoint3d& pnt, AcGePoint2d& paramPoint) const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isOn(pnt, paramPoint);
#endif
}

Adesk::Boolean PyAcGeSurface::isOn4(const AcGePoint3d& pnt, AcGePoint2d& paramPoint, const AcGeTol& tol) const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isOn(pnt, paramPoint, tol);
#endif
}

AcGePoint3d PyAcGeSurface::closestPointTo1(const AcGePoint3d& pnt) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->closestPointTo(pnt);
}

AcGePoint3d PyAcGeSurface::closestPointTo2(const AcGePoint3d& pnt, const AcGeTol& tol) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->closestPointTo(pnt, tol);
}

PyGePointOnSurface PyAcGeSurface::getClosestPointTo1(const AcGePoint3d& pnt) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    AcGePointOnSurface pos;
    imp->getClosestPointTo(pnt, pos);
    return PyGePointOnSurface(pos.copy());
}

PyGePointOnSurface PyAcGeSurface::getClosestPointTo2(const AcGePoint3d& pnt, const AcGeTol& tol) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    AcGePointOnSurface pos;
    imp->getClosestPointTo(pnt, pos, tol);
    return PyGePointOnSurface(pos.copy());
}

double PyAcGeSurface::distanceTo1(const AcGePoint3d& pnt) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->distanceTo(pnt);
}

double PyAcGeSurface::distanceTo2(const AcGePoint3d& pnt, const AcGeTol& tol) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->distanceTo(pnt, tol);
}

Adesk::Boolean PyAcGeSurface::isNormalReversed() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isNormalReversed();
}

PyAcGeSurface& PyAcGeSurface::reverseNormal()
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    imp->reverseNormal();
    return *this;
}

void PyAcGeSurface::getEnvelope(PyGeInterval& intrvlX, PyGeInterval& intrvlY) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    imp->getEnvelope(intrvlX.imp, intrvlY.imp);
}

Adesk::Boolean PyAcGeSurface::isClosedInU1() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isClosedInU();
}

Adesk::Boolean PyAcGeSurface::isClosedInU2(const AcGeTol& tol) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isClosedInU(tol);
}

Adesk::Boolean PyAcGeSurface::isClosedInV1() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isClosedInV();
}

Adesk::Boolean PyAcGeSurface::isClosedInV2(const AcGeTol& tol) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isClosedInV(tol);
}

AcGePoint3d PyAcGeSurface::evalPoint1(const AcGePoint2d& param) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->evalPoint(param);
}

AcGePoint3d PyAcGeSurface::evalPoint2(const AcGePoint2d& param, int derivOrd, boost::python::list& derivatives) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    AcGeVector3dArray vecs;
    auto pnt = imp->evalPoint(param, derivOrd, vecs);
    for (auto& vec : vecs)
        derivatives.append(vec);
    return pnt;
}

AcGePoint3d PyAcGeSurface::evalPoint3(const AcGePoint2d& param, int derivOrd, boost::python::list& derivatives, AcGeVector3d& normal) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    AcGeVector3dArray vecs;
    auto pnt = imp->evalPoint(param, derivOrd, vecs, normal);
    for (auto& vec : vecs)
        derivatives.append(vec);
    return pnt;
}

std::string PyAcGeSurface::className()
{
    return "AcGeSurface";
}

AcGeSurface* PyAcGeSurface::impObj() const
{
    return static_cast<AcGeSurface*>(m_imp.get());
}
