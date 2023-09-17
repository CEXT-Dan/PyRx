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
        .def("cast", &PyGeSurface::cast).staticmethod("cast")
        .def("copycast", &PyGeSurface::copycast).staticmethod("copycast")
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

PyGeSurface PyGeSurface::cast(const PyGeEntity3d& src)
{
    if (!src.impObj()->isKindOf(AcGe::EntityId::kSurface))
        PyThrowBadEs(Acad::eNotThatKindOfClass);
    return PyGeEntity3dCast<PyGeSurface>(src);
}

PyGeSurface PyGeSurface::copycast(const PyGeEntity3d& src)
{
    if (!src.impObj()->isKindOf(AcGe::EntityId::kSurface))
        PyThrowBadEs(Acad::eNotThatKindOfClass);
    return PyGeSurface(src.impObj()->copy());
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
        .def("cast", &PyGeCone::cast).staticmethod("cast")
        .def("copycast", &PyGeCone::copycast).staticmethod("copycast")
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

PyGeCone::PyGeCone(AcGeCone* src)
    : PyGeSurface(src)
{
}

PyGeCone::PyGeCone(AcGeEntity3d* src)
    : PyGeSurface(src)
{
}

PyGeCone PyGeCone::cast(const PyGeEntity3d& src)
{
    if (!src.impObj()->isKindOf(AcGe::EntityId::kCone))
        PyThrowBadEs(Acad::eNotThatKindOfClass);
    return PyGeEntity3dCast<PyGeCone>(src);
}

PyGeCone PyGeCone::copycast(const PyGeEntity3d& src)
{
    if (!src.impObj()->isKindOf(AcGe::EntityId::kCone))
        PyThrowBadEs(Acad::eNotThatKindOfClass);
    return PyGeCone(static_cast<AcGeCone*>(src.impObj()->copy()));
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
        .def("cast", &PyGeCylinder::cast).staticmethod("cast")
        .def("copycast", &PyGeCylinder::copycast).staticmethod("copycast")
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

PyGeCylinder::PyGeCylinder(AcGeCylinder* src)
    : PyGeSurface(src)
{
}

PyGeCylinder::PyGeCylinder(AcGeEntity3d* src)
    : PyGeSurface(src)
{
}

PyGeCylinder PyGeCylinder::cast(const PyGeEntity3d& src)
{
    if (!src.impObj()->isKindOf(AcGe::EntityId::kCylinder))
        PyThrowBadEs(Acad::eNotThatKindOfClass);
    return PyGeEntity3dCast<PyGeCylinder>(src);
}

PyGeCylinder PyGeCylinder::copycast(const PyGeEntity3d& src)
{
    if (!src.impObj()->isKindOf(AcGe::EntityId::kCylinder))
        PyThrowBadEs(Acad::eNotThatKindOfClass);
    return PyGeCylinder(static_cast<AcGeCylinder*>(src.impObj()->copy()));
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
        .def("cast", &PyGeExternalBoundedSurface::cast).staticmethod("cast")
        .def("copycast", &PyGeExternalBoundedSurface::copycast).staticmethod("copycast")
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

PyGeExternalBoundedSurface::PyGeExternalBoundedSurface(AcGeExternalBoundedSurface* src)
    : PyGeSurface(src)
{
}

PyGeExternalBoundedSurface::PyGeExternalBoundedSurface(AcGeEntity3d* src)
    : PyGeSurface(src)
{

}

PyGeExternalBoundedSurface PyGeExternalBoundedSurface::cast(const PyGeEntity3d& src)
{
    if (!src.impObj()->isKindOf(AcGe::EntityId::kExternalBoundedSurface))
        PyThrowBadEs(Acad::eNotThatKindOfClass);
    return PyGeEntity3dCast<PyGeExternalBoundedSurface>(src);
}

PyGeExternalBoundedSurface PyGeExternalBoundedSurface::copycast(const PyGeEntity3d& src)
{
    if (!src.impObj()->isKindOf(AcGe::EntityId::kExternalBoundedSurface))
        PyThrowBadEs(Acad::eNotThatKindOfClass);
    return PyGeExternalBoundedSurface(static_cast<AcGeExternalBoundedSurface*>(src.impObj()->copy()));
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
        .def("cast", &PyGeExternalSurface::cast).staticmethod("cast")
        .def("copycast", &PyGeExternalSurface::copycast).staticmethod("copycast")
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

PyGeExternalSurface::PyGeExternalSurface(AcGeExternalSurface* src)
    : PyGeSurface(src)
{
}

PyGeExternalSurface::PyGeExternalSurface(AcGeEntity3d* src)
    : PyGeSurface(src)
{

}

PyGeExternalSurface PyGeExternalSurface::cast(const PyGeEntity3d& src)
{
    if (!src.impObj()->isKindOf(AcGe::EntityId::kExternalSurface))
        PyThrowBadEs(Acad::eInvalidInput);
    return PyGeEntity3dCast<PyGeExternalSurface>(src);
}

PyGeExternalSurface PyGeExternalSurface::copycast(const PyGeEntity3d& src)
{
    if (!src.impObj()->isKindOf(AcGe::EntityId::kExternalSurface))
        PyThrowBadEs(Acad::eInvalidInput);
    return PyGeExternalSurface(static_cast<AcGeExternalSurface*>(src.impObj()->copy()));
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
        .def("cast", &PyGeNurbSurface::cast).staticmethod("cast")
        .def("copycast", &PyGeNurbSurface::copycast).staticmethod("copycast")
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

PyGeNurbSurface::PyGeNurbSurface(AcGeNurbSurface* src)
    : PyGeSurface(src)
{
}

PyGeNurbSurface::PyGeNurbSurface(AcGeEntity3d* src)
    : PyGeSurface(src)
{
}

PyGeNurbSurface PyGeNurbSurface::cast(const PyGeEntity3d& src)
{
    if (!src.impObj()->isKindOf(AcGe::EntityId::kNurbSurface))
        PyThrowBadEs(Acad::eInvalidInput);
    return PyGeEntity3dCast<PyGeNurbSurface>(src);
}

PyGeNurbSurface PyGeNurbSurface::copycast(const PyGeEntity3d& src)
{
    if (!src.impObj()->isKindOf(AcGe::EntityId::kNurbSurface))
        PyThrowBadEs(Acad::eInvalidInput);
    return PyGeNurbSurface(static_cast<AcGeNurbSurface*>(src.impObj()->copy()));
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
        .def("cast", &PyGeOffsetSurface::cast).staticmethod("cast")
        .def("copycast", &PyGeOffsetSurface::copycast).staticmethod("copycast")
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

PyGeOffsetSurface::PyGeOffsetSurface(AcGeOffsetSurface* src)
    : PyGeSurface(src)
{
}

PyGeOffsetSurface::PyGeOffsetSurface(AcGeEntity3d* src)
    : PyGeSurface(src)
{
}

PyGeOffsetSurface PyGeOffsetSurface::cast(const PyGeEntity3d& src)
{
    if (!src.impObj()->isKindOf(AcGe::EntityId::kOffsetSurface))
        PyThrowBadEs(Acad::eInvalidInput);
    return PyGeEntity3dCast<PyGeOffsetSurface>(src);
}

PyGeOffsetSurface PyGeOffsetSurface::copycast(const PyGeEntity3d& src)
{
    if (!src.impObj()->isKindOf(AcGe::EntityId::kOffsetSurface))
        PyThrowBadEs(Acad::eInvalidInput);
    return PyGeOffsetSurface(static_cast<AcGeOffsetSurface*>(src.impObj()->copy()));
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
        .def("cast", &PyGeSphere::cast).staticmethod("cast")
        .def("copycast", &PyGeSphere::copycast).staticmethod("copycast")
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

PyGeSphere::PyGeSphere(AcGeSphere* src)
    : PyGeSurface(src)
{
}

PyGeSphere::PyGeSphere(AcGeEntity3d* src)
    : PyGeSurface(src)
{

}

PyGeSphere PyGeSphere::cast(const PyGeEntity3d& src)
{
    if (!src.impObj()->isKindOf(AcGe::EntityId::kSphere))
        PyThrowBadEs(Acad::eInvalidInput);
    return PyGeEntity3dCast<PyGeSphere>(src);
}

PyGeSphere PyGeSphere::copycast(const PyGeEntity3d& src)
{
    if (!src.impObj()->isKindOf(AcGe::EntityId::kSphere))
        PyThrowBadEs(Acad::eInvalidInput);
    return PyGeSphere(static_cast<AcGeSphere*>(src.impObj()->copy()));
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
        .def("cast", &PyGeTorus::cast).staticmethod("cast")
        .def("copycast", &PyGeTorus::copycast).staticmethod("copycast")
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

PyGeTorus::PyGeTorus(AcGeTorus* src)
    : PyGeSurface(src)
{
}

PyGeTorus::PyGeTorus(AcGeEntity3d* src)
    : PyGeSurface(src)
{
}

PyGeTorus PyGeTorus::cast(const PyGeEntity3d& src)
{
    if (!src.impObj()->isKindOf(AcGe::EntityId::kTorus))
        PyThrowBadEs(Acad::eInvalidInput);
    return PyGeEntity3dCast<PyGeTorus>(src);
}

PyGeTorus PyGeTorus::copycast(const PyGeEntity3d& src)
{
    if (!src.impObj()->isKindOf(AcGe::EntityId::kTorus))
        PyThrowBadEs(Acad::eInvalidInput);
    return PyGeTorus(static_cast<AcGeTorus*>(src.impObj()->copy()));
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
