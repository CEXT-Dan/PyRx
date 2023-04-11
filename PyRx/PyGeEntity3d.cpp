#include "stdafx.h"
#include "PyGeEntity3d.h"

using namespace boost::python;

//-----------------------------------------------------------------------------------------
//PyGeEntity3d wrapper
void makePyGeEntity3dWrapper()
{
    static auto wrapper = class_<PyGeEntity3d>("GeEntity3d", boost::python::no_init)
        .def("isKindOf", &PyGeEntity3d::isKindOf)
        .def("type", &PyGeEntity3d::type)
        .def("copy", &PyGeEntity3d::copy)
        .def("isEqualTo", &PyGeEntity3d::isEqualTo)
        .def("transformBy", &PyGeEntity3d::transformBy, return_value_policy<reference_existing_object>())
        .def("translateBy", &PyGeEntity3d::translateBy, return_value_policy<reference_existing_object>())
        .def("rotateBy", &PyGeEntity3d::rotateBy1, return_value_policy<reference_existing_object>())
        .def("rotateBy", &PyGeEntity3d::rotateBy2, return_value_policy<reference_existing_object>())
        .def("mirror", &PyGeEntity3d::mirror, return_value_policy<reference_existing_object>())
        .def("scaleBy", &PyGeEntity3d::scaleBy1, return_value_policy<reference_existing_object>())
        .def("scaleBy", &PyGeEntity3d::scaleBy2, return_value_policy<reference_existing_object>())
        .def("isOn", &PyGeEntity3d::isOn1)
        .def("isOn", &PyGeEntity3d::isOn2)
        .def("isNull", &PyGeEntity3d::isNull)
        .def("__eq__", &PyGeEntity3d::operator==)
        .def("__ne__", &PyGeEntity3d::operator!=)
        .def("className", &PyGeEntity3d::className).staticmethod("className")
        ;
}

PyGeEntity3d::PyGeEntity3d(AcGeEntity3d* pEnt)
    : m_imp(pEnt)
{
}

bool PyGeEntity3d::operator==(PyGeEntity3d const& rhs) const
{
    if (impObj() != nullptr && rhs.impObj() != nullptr)
        return *impObj() == *rhs.impObj();
    return false;
}

bool PyGeEntity3d::operator!=(PyGeEntity3d const& rhs) const
{
    if (impObj() != nullptr && rhs.impObj() != nullptr)
        return *impObj() != *rhs.impObj();
    return false;
}

Adesk::Boolean PyGeEntity3d::isKindOf(AcGe::EntityId entType) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isKindOf(entType);
}

AcGe::EntityId PyGeEntity3d::type() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->type();
}

PyGeEntity3d PyGeEntity3d::copy() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return PyGeEntity3d(imp->copy());
}

Adesk::Boolean PyGeEntity3d::isEqualTo(const PyGeEntity3d& ent, const AcGeTol& tol) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    if (ent.isNull())
        throw PyNullObject();
    return imp->isEqualTo(*ent.impObj(), tol);
}

PyGeEntity3d& PyGeEntity3d::transformBy(const AcGeMatrix3d& xfm)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    imp->transformBy(xfm);
    return *this;
}

PyGeEntity3d& PyGeEntity3d::translateBy(const AcGeVector3d& translateVec)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    imp->translateBy(translateVec);
    return *this;
}

PyGeEntity3d& PyGeEntity3d::rotateBy1(double angle, const AcGeVector3d& vec)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    imp->rotateBy(angle,vec);
    return *this;
}

PyGeEntity3d& PyGeEntity3d::rotateBy2(double angle, const AcGeVector3d& vec, const AcGePoint3d& wrtPoint)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    imp->rotateBy(angle, vec, wrtPoint);
    return *this;
}

PyGeEntity3d& PyGeEntity3d::mirror(const PyGePlane& plane)
{
    auto imp = impObj();
    if (imp == nullptr || plane.isNull())
        throw PyNullObject();
    imp->mirror(*plane.impObj());
    return *this;
}

PyGeEntity3d& PyGeEntity3d::scaleBy1(double scaleFactor)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    imp->scaleBy(scaleFactor);
    return *this;
}

PyGeEntity3d& PyGeEntity3d::scaleBy2(double scaleFactor, const AcGePoint3d& wrtPoint)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    imp->scaleBy(scaleFactor, wrtPoint);
    return *this;
}

Adesk::Boolean PyGeEntity3d::isOn1(const AcGePoint3d& pnt) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isOn(pnt);
}

Adesk::Boolean PyGeEntity3d::isOn2(const AcGePoint3d& pnt, const AcGeTol& tol) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isOn(pnt, tol);
}

bool PyGeEntity3d::isNull() const
{
    return m_imp == nullptr;
}

std::string PyGeEntity3d::className()
{
    return "AcGeEntity3d";
}

AcGeEntity3d* PyGeEntity3d::impObj() const
{
    return m_imp.get();
}

//-----------------------------------------------------------------------------------------
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
    return imp->isOn(pnt,tol);
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
    return imp->isOn(pnt, paramPoint,tol);
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
    auto pnt = imp->evalPoint(param, derivOrd, vecs,normal);
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

//-----------------------------------------------------------------------------------------
//AcGeSurface wrapper
void makeAcGePlanarEntWrapper()
{
    static auto wrapper = class_<PyGePlanarEnt, bases<PyAcGeSurface>>("GePlanarEnt", boost::python::no_init)
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

std::string PyGePlanarEnt::className()
{
    return "AcGePlanarEnt";
}

AcGePlanarEnt* PyGePlanarEnt::impObj() const
{
    return static_cast<AcGePlanarEnt*>(m_imp.get());
}

//-----------------------------------------------------------------------------------------
//PyGePlane wrapper
void makePyGePlaneWrapper()
{
    static auto wrapper = class_<PyGePlane, bases<PyGePlanarEnt>>("GePlane")
        .def(init<>())
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

std::string PyGePlane::className()
{
    return "AcGePlane";
}

AcGePlane* PyGePlane::impObj() const
{
    return static_cast<AcGePlane*>(m_imp.get());
}
