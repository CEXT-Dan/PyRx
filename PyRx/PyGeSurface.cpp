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
        .def("reverseNormal", &PyGeSurface::reverseNormal)
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

void PyGeSurface::reverseNormal()
{
    impObj()->reverseNormal();
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
    if (m_imp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcGeSurface*>(m_imp.get());
}

//-----------------------------------------------------------------------------------------
//AcGeCone wrapper
void makePyGeConeWrapper()
{
    class_<PyGeCone, bases<PyGeSurface>>("Cone")
        .def("className", &PyGeCone::className).staticmethod("className")
        ;
}

PyGeCone::PyGeCone()
    : PyGeSurface(new AcGeCone(), true)
{
}

PyGeCone::PyGeCone(const AcGeCone& src)
    : PyGeSurface(new AcGeCone(src), true)
{
}

std::string PyGeCone::className()
{
    return "AcGeCone";
}

AcGeCone* PyGeCone::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_imp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcGeCone*>(m_imp.get());
}

//-----------------------------------------------------------------------------------------
//AcGeCylinder wrapper
void makePyGeCylinderWrapper()
{
    class_<PyGeCylinder, bases<PyGeSurface>>("Cylinder")
        .def("className", &PyGeCylinder::className).staticmethod("className")
        ;
}

PyGeCylinder::PyGeCylinder()
    : PyGeSurface(new AcGeCylinder(), true)
{
}

PyGeCylinder::PyGeCylinder(const AcGeCylinder& src)
    : PyGeSurface(new AcGeCylinder(src), true)
{
}

std::string PyGeCylinder::className()
{
    return "AcGeCylinder";
}

AcGeCylinder* PyGeCylinder::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_imp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcGeCylinder*>(m_imp.get());
}

//-----------------------------------------------------------------------------------------
//AcGeExternalBoundedSurface wrapper
void makePyGeExternalBoundedSurfaceWrapper()
{
    class_<PyGeExternalBoundedSurface, bases<PyGeSurface>>("ExternalBoundedSurface")
        .def("className", &PyGeExternalBoundedSurface::className).staticmethod("className")
        ;
}

PyGeExternalBoundedSurface::PyGeExternalBoundedSurface()
    : PyGeSurface(new AcGeExternalBoundedSurface(), true)
{
}

PyGeExternalBoundedSurface::PyGeExternalBoundedSurface(const AcGeExternalBoundedSurface& src)
    : PyGeSurface(new AcGeExternalBoundedSurface(src), true)
{
}

std::string PyGeExternalBoundedSurface::className()
{
    return "AcGeExternalBoundedSurface";
}

AcGeExternalBoundedSurface* PyGeExternalBoundedSurface::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_imp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcGeExternalBoundedSurface*>(m_imp.get());
}

//-----------------------------------------------------------------------------------------
//AcGeExternalSurface wrapper
void makePyGeExternalSurfaceWrapper()
{
    class_<PyGeExternalSurface, bases<PyGeSurface>>("ExternalSurface")
        .def("className", &PyGeExternalSurface::className).staticmethod("className")
        ;
}

PyGeExternalSurface::PyGeExternalSurface()
    : PyGeSurface(new AcGeExternalSurface(), true)
{
}

PyGeExternalSurface::PyGeExternalSurface(const AcGeExternalSurface& src)
    : PyGeSurface(new AcGeExternalSurface(src), true)
{
}

std::string PyGeExternalSurface::className()
{
    return "AcGeExternalSurface";
}

AcGeExternalSurface* PyGeExternalSurface::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_imp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcGeExternalSurface*>(m_imp.get());
}

//-----------------------------------------------------------------------------------------
//AcGeNurbSurface wrapper
void makePyGeNurbSurfaceWrapper()
{
    class_<PyGeNurbSurface, bases<PyGeSurface>>("NurbSurface")
        .def("className", &PyGeNurbSurface::className).staticmethod("className")
        ;
}

PyGeNurbSurface::PyGeNurbSurface()
    : PyGeSurface(new AcGeNurbSurface(), true)
{
}

PyGeNurbSurface::PyGeNurbSurface(const AcGeNurbSurface& src)
    : PyGeSurface(new AcGeNurbSurface(src), true)
{
}

std::string PyGeNurbSurface::className()
{
    return "AcGeNurbSurface";
}

AcGeNurbSurface* PyGeNurbSurface::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_imp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcGeNurbSurface*>(m_imp.get());
}

//-----------------------------------------------------------------------------------------
//AcGeOffsetSurface wrapper
void makePyGeOffsetSurfaceWrapper()
{
    class_<PyGeOffsetSurface, bases<PyGeSurface>>("OffsetSurface")
        .def("className", &PyGeOffsetSurface::className).staticmethod("className")
        ;
}

PyGeOffsetSurface::PyGeOffsetSurface()
    : PyGeSurface(new AcGeOffsetSurface(), true)
{
}

PyGeOffsetSurface::PyGeOffsetSurface(const AcGeOffsetSurface& src)
    : PyGeSurface(new AcGeOffsetSurface(src), true)
{
}

std::string PyGeOffsetSurface::className()
{
    return "AcGeOffsetSurface";
}

AcGeOffsetSurface* PyGeOffsetSurface::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_imp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcGeOffsetSurface*>(m_imp.get());
}

//-----------------------------------------------------------------------------------------
//AcGeSphere wrapper
void makePyGeSphereWrapper()
{
    class_<PyGeSphere, bases<PyGeSurface>>("Sphere")
        .def("className", &PyGeSphere::className).staticmethod("className")
        ;
}

PyGeSphere::PyGeSphere()
    : PyGeSurface(new AcGeSphere(), true)
{
}

PyGeSphere::PyGeSphere(const AcGeSphere& src)
    : PyGeSurface(new AcGeSphere(src), true)
{
}

std::string PyGeSphere::className()
{
    return "AcGeSphere";
}

AcGeSphere* PyGeSphere::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_imp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcGeSphere*>(m_imp.get());
}

//-----------------------------------------------------------------------------------------
//AcGeTorus wrapper
void makePyGeTorusWrapper()
{
    class_<PyGeTorus, bases<PyGeSurface>>("Torus")
        .def("className", &PyGeTorus::className).staticmethod("className")
        ;
}

PyGeTorus::PyGeTorus()
    : PyGeSurface(new AcGeTorus(), true)
{
}

PyGeTorus::PyGeTorus(const AcGeTorus& src)
    : PyGeSurface(new AcGeTorus(src), true)
{
}

std::string PyGeTorus::className()
{
    return "AcGeTorus";
}

AcGeTorus* PyGeTorus::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_imp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcGeTorus*>(m_imp.get());
}
