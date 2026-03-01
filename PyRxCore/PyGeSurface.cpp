#include "stdafx.h"
#include "PyGeSurface.h"
#include "PyGePointEnt3d.h"
#include "PyGeInterval.h"
#include "PyGeLinearEnt3d.h"

using namespace boost::python;
// ---------------------------------------------------------------------------------------- -
//AcGeSurface wrapper
void makePyGeSurfaceWrapper()
{
    constexpr const std::string_view isOnOverloads = "Overloads:\n"
        "- pnt: PyGe.Point3d\n"
        "- pnt: PyGe.Point3d, tol: PyGe.Tol = ...\n"
        "- pnt: PyGe.Point3d, paramPoint: PyGe.Point2d\n"
        "- pnt: PyGe.Point3d, paramPoint: PyGe.Point2d, tol: PyGe.Tol = ...\n";

    constexpr const std::string_view evalPointOverloads = "Overloads:\n"
        "- param: PyGe.Point2d\n"
        "- param: PyGe.Point3d, derivOrd: int, vecs: list[PyGe.Vector3d]\n"
        "- param: PyGe.Point3d, derivOrd: int, vecs: list[PyGe.Vector3d], normal: PyGe.Vector3d\n";

    PyDocString DS("Surface");
    class_<PyGeSurface, bases<PyGeEntity3d>>("Surface", boost::python::no_init)
        .def("paramOf", &PyGeSurface::paramOf)
        .def("paramOf", &PyGeSurface::paramOfTol, DS.ARGS({ "pt: PyGe.Point3d","tol: PyGe.Tol = ..." }))
        .def("isOn", &PyGeSurface::isOn1)
        .def("isOn", &PyGeSurface::isOn2)
        .def("isOn", &PyGeSurface::isOn3)
        .def("isOn", &PyGeSurface::isOn4, DS.OVRL(isOnOverloads))
        .def("closestPointTo", &PyGeSurface::closestPointTo1)
        .def("closestPointTo", &PyGeSurface::closestPointTo2, DS.ARGS({ "pt: PyGe.Point3d","tol: PyGe.Tol = ..." }))
        .def("distanceTo", &PyGeSurface::distanceTo1)
        .def("distanceTo", &PyGeSurface::distanceTo2, DS.ARGS({ "pt: PyGe.Point3d","tol: PyGe.Tol = ..." }))
        .def("isNormalReversed", &PyGeSurface::isNormalReversed, DS.ARGS())
        .def("reverseNormal", &PyGeSurface::reverseNormal, DS.ARGS())
        .def("isClosedInU", &PyGeSurface::isClosedInU1)
        .def("isClosedInU", &PyGeSurface::isClosedInU2, DS.ARGS({ "tol: PyGe.Tol = ..." }))
        .def("isClosedInV", &PyGeSurface::isClosedInV1)
        .def("isClosedInV", &PyGeSurface::isClosedInV2, DS.ARGS({ "tol: PyGe.Tol = ..." }))
        .def("evalPoint", &PyGeSurface::evalPoint1)
        .def("evalPoint", &PyGeSurface::evalPoint2)
        .def("evalPoint", &PyGeSurface::evalPoint3, DS.OVRL(evalPointOverloads))
        .def("cast", &PyGeSurface::cast, DS.SARGS({ "otherObject: PyGe.Entity3d" })).staticmethod("cast")
        .def("copycast", &PyGeSurface::copycast, DS.SARGS({ "otherObject: PyGe.Entity3d" })).staticmethod("copycast")
        .def("className", &PyGeSurface::className, DS.SARGS()).staticmethod("className")
        ;
}

PyGeSurface::PyGeSurface(AcGeEntity3d* pEnt)
    : PyGeEntity3d(pEnt)
{
}

PyGeSurface::PyGeSurface(AcGeSurface* pEnt)
    : PyGeEntity3d(pEnt)
{
}

PyGeSurface::PyGeSurface(const AcGeSurface* pEnt)
    : PyGeEntity3d(pEnt)
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
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    return impObj()->isOn(pnt);
#endif
}

Adesk::Boolean PyGeSurface::isOn2(const AcGePoint3d& pnt, const AcGeTol& tol) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    return impObj()->isOn(pnt, tol);
#endif
}

Adesk::Boolean PyGeSurface::isOn3(const AcGePoint3d& pnt, AcGePoint2d& paramPoint) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    return impObj()->isOn(pnt, paramPoint);
#endif
}

Adesk::Boolean PyGeSurface::isOn4(const AcGePoint3d& pnt, AcGePoint2d& paramPoint, const AcGeTol& tol) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    return impObj()->isOn(pnt, paramPoint, tol);
#endif
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

void PyGeSurface::reverseNormal() const
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
    return PyGeEntity3dCast<PyGeSurface, AcGeSurface>(src);
}

PyGeSurface PyGeSurface::copycast(const PyGeEntity3d& src)
{
    return PyGeSurface(static_cast<AcGeSurface*>(src.impObj()->copy()));
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
#if !defined(_BRXTARGET260)

    constexpr const std::string_view ctor = "Overloads:\n"
        "- None: Any\n"
        "- cosineAngle: float, sineAngle: float, baseOrigin: PyGe.Point3d, baseRadius: float, axisOfSymmetry: PyGe.Vector3d\n"
        "- cosineAngle: float, sineAngle: float, baseOrigin: PyGe.Point3d, baseRadius: float, axisOfSymmetry: PyGe.Vector3d, refAxis: PyGe.Vector3d, height: PyGe.Interval, startAngle: float, endAngle: float\n";

    constexpr const std::string_view setOverloads = "Overloads:\n"
        "- cosineAngle: float, sineAngle: float, baseOrigin: PyGe.Point3d, baseRadius: float, axisOfSymmetry: PyGe.Vector3d\n"
        "- cosineAngle: float, sineAngle: float, baseOrigin: PyGe.Point3d, baseRadius: float, axisOfSymmetry: PyGe.Vector3d, refAxis: PyGe.Vector3d, height: PyGe.Interval, startAngle: float, endAngle: float\n";

    PyDocString DS("Cone");
    class_<PyGeCone, bases<PyGeSurface>>("Cone")
        .def(init<>())
        .def(init<double, double, const  AcGePoint3d&, double, const AcGeVector3d&>())
        .def(init<double, double, const  AcGePoint3d&, double, const AcGeVector3d&, const AcGeVector3d&, const AcGeInterval&, double, double>(DS.CTOR(ctor, 11778)))
        .def("baseRadius", &PyGeCone::baseRadius, DS.ARGS())
        .def("baseCenter", &PyGeCone::baseCenter, DS.ARGS())
        .def("getAngles", &PyGeCone::getAngles, DS.ARGS())
        .def("halfAngle", &PyGeCone::halfAngle, DS.ARGS())
        .def("getHalfAngle", &PyGeCone::getHalfAngle, DS.ARGS())
        .def("getHeight", &PyGeCone::getHeight, DS.ARGS())
        .def("heightAt", &PyGeCone::heightAt, DS.ARGS({ "val: float" }))
        .def("axisOfSymmetry", &PyGeCone::axisOfSymmetry, DS.ARGS())
        .def("refAxis", &PyGeCone::refAxis, DS.ARGS())
        .def("apex", &PyGeCone::apex, DS.ARGS())
        .def("isClosed", &PyGeCone::isClosed1)
        .def("isClosed", &PyGeCone::isClosed2, DS.ARGS({ "tol: PyGe.Tol = ..." }))
        .def("isOuterNormal", &PyGeCone::isOuterNormal, DS.ARGS())
        .def("setBaseRadius", &PyGeCone::setBaseRadius, DS.ARGS({ "val: float" }))
        .def("setAngles", &PyGeCone::setAngles, DS.ARGS({ "startAngle: float", "endAngle: float" }))
        .def("setHeight", &PyGeCone::setHeight, DS.ARGS({ "val: PyGe.Interval" }))
        .def("set", &PyGeCone::set1)
        .def("set", &PyGeCone::set2, DS.OVRL(setOverloads))
        .def("intersectWith", &PyGeCone::intersectWith1)
        .def("intersectWith", &PyGeCone::intersectWith2, DS.ARGS({ "val: PyGe.LinearEnt3d",  "tol: PyGe.Tol = ..." }))
        .def("cast", &PyGeCone::cast, DS.SARGS({ "otherObject: PyGe.Entity3d" })).staticmethod("cast")
        .def("copycast", &PyGeCone::copycast, DS.SARGS({ "otherObject: PyGe.Entity3d" })).staticmethod("copycast")
        .def("className", &PyGeCone::className, DS.SARGS()).staticmethod("className")
        ;
#endif
}

#if !defined(_BRXTARGET260)
PyGeCone::PyGeCone()
    : PyGeSurface(new AcGeCone())
{
}

PyGeCone::PyGeCone(const AcGeCone& src)
    : PyGeSurface(new AcGeCone(src))
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

PyGeCone::PyGeCone(double cosineAngle, double sineAngle, const AcGePoint3d& baseOrigin, double baseRadius, const AcGeVector3d& axisOfSymmetry)
    : PyGeSurface(new AcGeCone(cosineAngle, sineAngle, baseOrigin, baseRadius, axisOfSymmetry))
{
}

PyGeCone::PyGeCone(double cosineAngle, double sineAngle, const AcGePoint3d& baseOrigin, double baseRadius, const AcGeVector3d& axisOfSymmetry,
    const AcGeVector3d& refAxis, const PyGeInterval& height, double startAngle, double endAngle)
    : PyGeSurface(new AcGeCone(cosineAngle, sineAngle, baseOrigin, baseRadius, axisOfSymmetry, refAxis, height.imp, startAngle, endAngle))
{
}

double PyGeCone::baseRadius() const
{
    return impObj()->baseRadius();
}

AcGePoint3d PyGeCone::baseCenter() const
{
    return impObj()->baseCenter();
}

boost::python::tuple PyGeCone::getAngles() const
{
    PyAutoLockGIL lock;
    double start = 0;
    double end = 0;
    impObj()->getAngles(start, end);
    return boost::python::make_tuple(start, end);
}

double PyGeCone::halfAngle() const
{
    return impObj()->halfAngle();
}

boost::python::tuple PyGeCone::getHalfAngle() const
{
    PyAutoLockGIL lock;
    double cosineAngle = 0;
    double sineAngle = 0;
    impObj()->getHalfAngle(cosineAngle, sineAngle);
    return boost::python::make_tuple(cosineAngle, sineAngle);
}

PyGeInterval PyGeCone::getHeight() const
{
    PyGeInterval val;
    impObj()->getHeight(val.imp);
    return val;
}

double PyGeCone::heightAt(double u) const
{
    return impObj()->heightAt(u);
}

AcGeVector3d PyGeCone::axisOfSymmetry() const
{
    return impObj()->axisOfSymmetry();
}

AcGeVector3d PyGeCone::refAxis() const
{
    return impObj()->refAxis();
}

AcGePoint3d PyGeCone::apex() const
{
    return impObj()->apex();
}

Adesk::Boolean PyGeCone::isClosed1() const
{
    return impObj()->isClosed();
}

Adesk::Boolean PyGeCone::isClosed2(const AcGeTol& tol) const
{
    return impObj()->isClosed(tol);
}

Adesk::Boolean PyGeCone::isOuterNormal() const
{
    return impObj()->isOuterNormal();
}

void PyGeCone::setBaseRadius(double radius) const
{
    impObj()->setBaseRadius(radius);
}

void PyGeCone::setAngles(double startAngle, double endAngle) const
{
    impObj()->setAngles(startAngle, endAngle);
}

void PyGeCone::setHeight(const PyGeInterval& height) const
{
    impObj()->setHeight(height.imp);
}

void PyGeCone::set1(double cosineAngle, double sineAngle, const AcGePoint3d& baseCenter, double baseRadius, const AcGeVector3d& axisOfSymmetry) const
{
    impObj()->set(cosineAngle, sineAngle, baseCenter, baseRadius, axisOfSymmetry);
}

void PyGeCone::set2(double cosineAngle, double sineAngle, const AcGePoint3d& baseCenter, double baseRadius,
    const AcGeVector3d& axisOfSymmetry, const AcGeVector3d& refAxis, const PyGeInterval& height, double startAngle, double endAngle) const
{
    impObj()->set(cosineAngle, sineAngle, baseCenter, baseRadius, axisOfSymmetry, refAxis, height.imp, startAngle, endAngle);
}

boost::python::tuple PyGeCone::intersectWith1(const PyGeLinearEnt3d& linEnt) const
{
    PyAutoLockGIL lock;
    int intn = 0;
    AcGePoint3d p1;
    AcGePoint3d p2;
    auto flag = impObj()->intersectWith(*linEnt.impObj(), intn, p1, p2);
    return boost::python::make_tuple(flag, intn, p1, p2);
}

boost::python::tuple PyGeCone::intersectWith2(const PyGeLinearEnt3d& linEnt, AcGeTol& tol) const
{
    PyAutoLockGIL lock;
    int intn = 0;
    AcGePoint3d p1;
    AcGePoint3d p2;
    auto flag = impObj()->intersectWith(*linEnt.impObj(), intn, p1, p2, tol);
    return boost::python::make_tuple(flag, intn, p1, p2);
}

PyGeCone PyGeCone::cast(const PyGeEntity3d& src)
{
    return PyGeEntity3dCast<PyGeCone, AcGeCone>(src);
}

PyGeCone PyGeCone::copycast(const PyGeEntity3d& src)
{
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
#endif

//-----------------------------------------------------------------------------------------
//AcGeCylinder wrapper
void makePyGeCylinderWrapper()
{
    constexpr const std::string_view ctor = "Overloads:\n"
        "- None: Any\n"
        "- radius: float, origin: PyGe.Point3d, axisOfSymmetry: PyGe.Vector3d\n"
        "- radius: float, origin: PyGe.Point3d, axisOfSymmetry: PyGe.Vector3d, refAxis: PyGe.Vector3d, height: PyGe.Interval, startAngle: float, endAngle: float\n";

    constexpr const std::string_view setOverloads = "Overloads:\n"
        "- radius: float, origin: PyGe.Point3d, axisOfSymmetry: PyGe.Vector3d\n"
        "- radius: float, origin: PyGe.Point3d, axisOfSymmetry: PyGe.Vector3d, refAxis: PyGe.Vector3d, height: PyGe.Interval, startAngle: float, endAngle: float\n";

    PyDocString DS("Cylinder");
    class_<PyGeCylinder, bases<PyGeSurface>>("Cylinder")
        .def(init<>())
        .def(init<double, const AcGePoint3d&, const AcGeVector3d&>())
        .def(init<double, const AcGePoint3d&, const AcGeVector3d&, const AcGeVector3d&, const PyGeInterval&, double, double>(DS.CTOR(ctor, 11949)))
        .def("radius", &PyGeCylinder::radius, DS.ARGS())
        .def("origin", &PyGeCylinder::origin, DS.ARGS())
        .def("getAngles", &PyGeCylinder::getAngles, DS.ARGS())
        .def("getHeight", &PyGeCylinder::getHeight, DS.ARGS())
        .def("heightAt", &PyGeCylinder::heightAt, DS.ARGS({ "u: float" }))
        .def("axisOfSymmetry", &PyGeCylinder::axisOfSymmetry, DS.ARGS())
        .def("refAxis", &PyGeCylinder::refAxis, DS.ARGS())
        .def("isOuterNormal", &PyGeCylinder::isOuterNormal, DS.ARGS())
        .def("isClosed", &PyGeCylinder::isClosed1)
        .def("isClosed", &PyGeCylinder::isClosed2, DS.ARGS({ "tol: PyGe.Tol = ..." }))
        .def("setRadius", &PyGeCylinder::setRadius, DS.ARGS({ "val: float" }))
        .def("setAngles", &PyGeCylinder::setAngles, DS.ARGS({ "start: float", "end: float" }))
        .def("setHeight", &PyGeCylinder::setHeight, DS.ARGS({ "val: PyGe.Interval" }))
        .def("set", &PyGeCylinder::set1)
        .def("set", &PyGeCylinder::set2, DS.OVRL(setOverloads))
        .def("intersectWith", &PyGeCylinder::intersectWith1)
        .def("intersectWith", &PyGeCylinder::intersectWith2, DS.ARGS({ "val: PyGe.LinearEnt3d",  "tol: PyGe.Tol = ..." }))
        .def("cast", &PyGeCylinder::cast, DS.SARGS({ "otherObject: PyGe.Entity3d" })).staticmethod("cast")
        .def("copycast", &PyGeCylinder::copycast, DS.SARGS({ "otherObject: PyGe.Entity3d" })).staticmethod("copycast")
        .def("className", &PyGeCylinder::className, DS.SARGS()).staticmethod("className")
        ;
}

PyGeCylinder::PyGeCylinder()
    : PyGeSurface(new AcGeCylinder())
{
}

PyGeCylinder::PyGeCylinder(double radius, const AcGePoint3d& origin, const AcGeVector3d& axisOfSymmetry)
    : PyGeSurface(new AcGeCylinder(radius, origin, axisOfSymmetry))
{
}

PyGeCylinder::PyGeCylinder(double radius, const AcGePoint3d& origin, const AcGeVector3d& axisOfSymmetry,
    const AcGeVector3d& refAxis, const PyGeInterval& height, double startAngle, double endAngle)
    : PyGeSurface(new AcGeCylinder(radius, origin, axisOfSymmetry, refAxis, height.imp, startAngle, endAngle))
{
}

PyGeCylinder::PyGeCylinder(const AcGeCylinder& src)
    : PyGeSurface(new AcGeCylinder(src))
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

double PyGeCylinder::radius() const
{
    return impObj()->radius();
}

AcGePoint3d PyGeCylinder::origin() const
{
    return impObj()->origin();
}

boost::python::tuple PyGeCylinder::getAngles() const
{
    PyAutoLockGIL lock;
    double start = 0;
    double end = 0;
    impObj()->getAngles(start, end);
    return boost::python::make_tuple(start, end);
}

PyGeInterval PyGeCylinder::getHeight() const
{
    PyGeInterval interval;
    impObj()->getHeight(interval.imp);
    return interval;
}

double PyGeCylinder::heightAt(double u) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    return impObj()->heightAt(u);
#endif
}

AcGeVector3d PyGeCylinder::axisOfSymmetry() const
{
    return impObj()->axisOfSymmetry();
}

AcGeVector3d PyGeCylinder::refAxis() const
{
    return impObj()->refAxis();
}

Adesk::Boolean PyGeCylinder::isOuterNormal() const
{
    return impObj()->isOuterNormal();
}

Adesk::Boolean PyGeCylinder::isClosed1() const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    return impObj()->isClosed();
#endif
}

Adesk::Boolean PyGeCylinder::isClosed2(const AcGeTol& tol) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    return impObj()->isClosed(tol);
#endif
}

void PyGeCylinder::setRadius(double radius) const
{
    impObj()->setRadius(radius);
}

void PyGeCylinder::setAngles(double start, double end) const
{
    impObj()->setAngles(start, end);
}

void PyGeCylinder::setHeight(const PyGeInterval& height) const
{
    impObj()->setHeight(height.imp);
}

void PyGeCylinder::set1(double radius, const AcGePoint3d& origin, const AcGeVector3d& axisOfSym) const
{
    impObj()->set(radius, origin, axisOfSym);
}

void PyGeCylinder::set2(double radius, const AcGePoint3d& origin, const AcGeVector3d& axisOfSym,
    const AcGeVector3d& refAxis, const PyGeInterval& height, double startAngle, double endAngle) const
{
    impObj()->set(radius, origin, axisOfSym, refAxis, height.imp, startAngle, endAngle);
}

boost::python::tuple PyGeCylinder::intersectWith1(const PyGeLinearEnt3d& linEnt) const
{
    return intersectWith2(linEnt, AcGeContext::gTol);
}

boost::python::tuple PyGeCylinder::intersectWith2(const PyGeLinearEnt3d& linEnt, AcGeTol& tol) const
{
    PyAutoLockGIL lock;
#if defined(_ARXTARGET)
    AcGeInterval vInterval;
    impObj()->getHeight(vInterval);
    auto b = vInterval.isUnBounded();
    auto v = linEnt.impObj()->direction();
    auto u = impObj()->axisOfSymmetry();
    if(b && u.isParallelTo(v, tol))
        return boost::python::make_tuple(Adesk::kFalse, 0, AcGePoint3d::kOrigin, AcGePoint3d::kOrigin);
#endif
    int intn = 0;
    AcGePoint3d p1;
    AcGePoint3d p2;
    auto res = impObj()->intersectWith(*linEnt.impObj(), intn, p1, p2, tol);
    return boost::python::make_tuple(res, intn, p1, p2);
}

PyGeCylinder PyGeCylinder::cast(const PyGeEntity3d& src)
{
    return PyGeEntity3dCast<PyGeCylinder, AcGeCylinder>(src);
}

PyGeCylinder PyGeCylinder::copycast(const PyGeEntity3d& src)
{
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
#if !defined(_BRXTARGET260)
    PyDocString DS("ExternalBoundedSurface");
    class_<PyGeExternalBoundedSurface, bases<PyGeSurface>>("ExternalBoundedSurface")
        .def(init<>(DS.ARGS(12057)))
        .def("cast", &PyGeExternalBoundedSurface::cast, DS.SARGS({ "otherObject: PyGe.Entity3d" })).staticmethod("cast")
        .def("copycast", &PyGeExternalBoundedSurface::copycast, DS.SARGS({ "otherObject: PyGe.Entity3d" })).staticmethod("copycast")
        .def("className", &PyGeExternalBoundedSurface::className, DS.SARGS()).staticmethod("className")
        ;
#endif
}

#if !defined(_BRXTARGET260)
PyGeExternalBoundedSurface::PyGeExternalBoundedSurface()
    : PyGeSurface(new AcGeExternalBoundedSurface())
{
}

PyGeExternalBoundedSurface::PyGeExternalBoundedSurface(const AcGeExternalBoundedSurface& src)
    : PyGeSurface(new AcGeExternalBoundedSurface(src))
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
    return PyGeEntity3dCast<PyGeExternalBoundedSurface, AcGeExternalBoundedSurface>(src);
}

PyGeExternalBoundedSurface PyGeExternalBoundedSurface::copycast(const PyGeEntity3d& src)
{
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
#endif

//-----------------------------------------------------------------------------------------
//AcGeExternalSurface wrapper
void makePyGeExternalSurfaceWrapper()
{
#if !defined(_BRXTARGET260)
    PyDocString DS("ExternalSurface");
    class_<PyGeExternalSurface, bases<PyGeSurface>>("ExternalSurface")
        .def(init<>(DS.ARGS(12102)))
        .def("cast", &PyGeExternalSurface::cast, DS.SARGS({ "otherObject: PyGe.Entity3d" })).staticmethod("cast")
        .def("copycast", &PyGeExternalSurface::copycast, DS.SARGS({ "otherObject: PyGe.Entity3d" })).staticmethod("copycast")
        .def("className", &PyGeExternalSurface::className, DS.SARGS()).staticmethod("className")
        ;
#endif
}

#if !defined(_BRXTARGET260)
PyGeExternalSurface::PyGeExternalSurface()
    : PyGeSurface(new AcGeExternalSurface())
{
}

PyGeExternalSurface::PyGeExternalSurface(const AcGeExternalSurface& src)
    : PyGeSurface(new AcGeExternalSurface(src))
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
    return PyGeEntity3dCast<PyGeExternalSurface, AcGeExternalSurface>(src);
}

PyGeExternalSurface PyGeExternalSurface::copycast(const PyGeEntity3d& src)
{
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
#endif

//-----------------------------------------------------------------------------------------
//AcGeNurbSurface wrapper
void makePyGeNurbSurfaceWrapper()
{
#if !defined(_BRXTARGET260)
    PyDocString DS("NurbSurface");
    class_<PyGeNurbSurface, bases<PyGeSurface>>("NurbSurface")
        .def(init<>(DS.ARGS(12455)))
        .def("cast", &PyGeNurbSurface::cast, DS.SARGS({ "otherObject: PyGe.Entity3d" })).staticmethod("cast")
        .def("copycast", &PyGeNurbSurface::copycast, DS.SARGS({ "otherObject: PyGe.Entity3d" })).staticmethod("copycast")
        .def("className", &PyGeNurbSurface::className, DS.SARGS()).staticmethod("className")
        ;
#endif
}

#if !defined(_BRXTARGET260)
PyGeNurbSurface::PyGeNurbSurface()
    : PyGeSurface(new AcGeNurbSurface())
{
}

PyGeNurbSurface::PyGeNurbSurface(const AcGeNurbSurface& src)
    : PyGeSurface(new AcGeNurbSurface(src))
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
    return PyGeEntity3dCast<PyGeNurbSurface, AcGeNurbSurface>(src);
}

PyGeNurbSurface PyGeNurbSurface::copycast(const PyGeEntity3d& src)
{
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
#endif

//-----------------------------------------------------------------------------------------
//AcGeOffsetSurface wrapper
void makePyGeOffsetSurfaceWrapper()
{
#if !defined(_BRXTARGET260)
    PyDocString DS("OffsetSurface");
    class_<PyGeOffsetSurface, bases<PyGeSurface>>("OffsetSurface")
        .def(init<>(DS.ARGS(12496)))
        .def("cast", &PyGeOffsetSurface::cast, DS.SARGS({ "otherObject: PyGe.Entity3d" })).staticmethod("cast")
        .def("copycast", &PyGeOffsetSurface::copycast, DS.SARGS({ "otherObject: PyGe.Entity3d" })).staticmethod("copycast")
        .def("className", &PyGeOffsetSurface::className, DS.SARGS()).staticmethod("className")
        ;
#endif
}

#if !defined(_BRXTARGET260)
PyGeOffsetSurface::PyGeOffsetSurface()
    : PyGeSurface(new AcGeOffsetSurface())
{
}

PyGeOffsetSurface::PyGeOffsetSurface(const AcGeOffsetSurface& src)
    : PyGeSurface(new AcGeOffsetSurface(src))
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
    return PyGeEntity3dCast<PyGeOffsetSurface, AcGeOffsetSurface>(src);
}

PyGeOffsetSurface PyGeOffsetSurface::copycast(const PyGeEntity3d& src)
{
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
#endif

//-----------------------------------------------------------------------------------------
//AcGeSphere wrapper
void makePyGeSphereWrapper()
{
    constexpr const std::string_view ctor = "Overloads:\n"
        "- None: Any\n"
        "- radius: float, center: PyGe.Point3d\n"
        "- radius: float, center: PyGe.Point3d, northAxis: PyGe.Vector3d, refAxis: PyGe.Vector3d, startAngleU: float, endAngleU: float, startAngleV: float, endAngleV: float\n";

    constexpr const std::string_view setOverloads = "Overloads:\n"
        "- radius: float, center: PyGe.Point3d\n"
        "- radius: float, center: PyGe.Point3d, northAxis: PyGe.Vector3d, refAxis: PyGe.Vector3d, startAngleU: float, endAngleU: float, startAngleV: float, endAngleV: float\n";

    PyDocString DS("Sphere");
    class_<PyGeSphere, bases<PyGeSurface>>("Sphere")
        .def(init<>())
        .def(init<double, const AcGePoint3d&>())
        .def(init<double, const AcGePoint3d&, const AcGeVector3d&, const AcGeVector3d&, double, double, double, double>(DS.CTOR(ctor, 12721)))
        .def("radius", &PyGeSphere::radius, DS.ARGS())
        .def("center", &PyGeSphere::center, DS.ARGS())
        .def("getAnglesInU", &PyGeSphere::getAnglesInU, DS.ARGS())
        .def("getAnglesInV", &PyGeSphere::getAnglesInV, DS.ARGS())
        .def("northAxis", &PyGeSphere::northAxis, DS.ARGS())
        .def("refAxis", &PyGeSphere::refAxis, DS.ARGS())
        .def("northPole", &PyGeSphere::northPole, DS.ARGS())
        .def("southPole", &PyGeSphere::southPole, DS.ARGS())
        .def("isOuterNormal", &PyGeSphere::isOuterNormal, DS.ARGS())
        .def("isClosed", &PyGeSphere::isClosed1)
        .def("isClosed", &PyGeSphere::isClosed2, DS.ARGS({ "tol: PyGe.Tol = ..." }))
        .def("setRadius", &PyGeSphere::setRadius, DS.ARGS({ "val: float" }))
        .def("setAnglesInU", &PyGeSphere::setAnglesInU, DS.ARGS({ "start: float","end: float" }))
        .def("setAnglesInV", &PyGeSphere::setAnglesInV, DS.ARGS({ "start: float","end: float" }))
        .def("set", &PyGeSphere::set1)
        .def("set", &PyGeSphere::set2, DS.OVRL(setOverloads))
        .def("intersectWith", &PyGeSphere::intersectWith1)
        .def("intersectWith", &PyGeSphere::intersectWith2, DS.ARGS({ "val: PyGe.LinearEnt3d",  "tol: PyGe.Tol = ..." }))
        .def("cast", &PyGeSphere::cast, DS.SARGS({ "otherObject: PyGe.Entity3d" })).staticmethod("cast")
        .def("copycast", &PyGeSphere::copycast, DS.SARGS({ "otherObject: PyGe.Entity3d" })).staticmethod("copycast")
        .def("className", &PyGeSphere::className, DS.SARGS()).staticmethod("className")
        ;
}

PyGeSphere::PyGeSphere()
    : PyGeSurface(new AcGeSphere())
{
}

PyGeSphere::PyGeSphere(const AcGeSphere& src)
    : PyGeSurface(new AcGeSphere(src))
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

PyGeSphere::PyGeSphere(double radius, const AcGePoint3d& center)
    : PyGeSurface(new AcGeSphere(radius, center))
{
}

PyGeSphere::PyGeSphere(double radius, const AcGePoint3d& center, const AcGeVector3d& northAxis, const AcGeVector3d& refAxis,
    double startAngleU, double endAngleU, double startAngleV, double endAngleV)
    : PyGeSurface(new AcGeSphere(radius, center, northAxis, refAxis, startAngleU, endAngleU, startAngleV, endAngleV))
{
}

double PyGeSphere::radius() const
{
    return impObj()->radius();
}

AcGePoint3d PyGeSphere::center() const
{
    return impObj()->center();
}

boost::python::tuple PyGeSphere::getAnglesInU() const
{
    PyAutoLockGIL lock;
    double start;
    double end;
    impObj()->getAnglesInU(start, end);
    return boost::python::make_tuple(start, end);
}

boost::python::tuple PyGeSphere::getAnglesInV() const
{
    PyAutoLockGIL lock;
    double start;
    double end;
    impObj()->getAnglesInV(start, end);
    return boost::python::make_tuple(start, end);
}

AcGeVector3d PyGeSphere::northAxis() const
{
    return impObj()->northAxis();
}

AcGeVector3d PyGeSphere::refAxis() const
{
    return impObj()->refAxis();
}

AcGePoint3d PyGeSphere::northPole() const
{
    return impObj()->northPole();
}

AcGePoint3d PyGeSphere::southPole() const
{
    return impObj()->southPole();
}

Adesk::Boolean PyGeSphere::isOuterNormal() const
{
    return impObj()->isOuterNormal();
}

Adesk::Boolean PyGeSphere::isClosed1() const
{
    return impObj()->isClosed();
}

Adesk::Boolean PyGeSphere::isClosed2(const AcGeTol& tol) const
{
    return impObj()->isClosed(tol);
}

void PyGeSphere::setRadius(double val) const
{
    impObj()->setRadius(val);
}

void PyGeSphere::setAnglesInU(double start, double end) const
{
    impObj()->setAnglesInU(start, end);
}

void PyGeSphere::setAnglesInV(double start, double end) const
{
    impObj()->setAnglesInV(start, end);
}

void PyGeSphere::set1(double radius, const AcGePoint3d& center) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    impObj()->set(radius, center);
#endif
}

void PyGeSphere::set2(double radius, const AcGePoint3d& center, const AcGeVector3d& northAxis, const AcGeVector3d& refAxis,
    double startAngleU, double endAngleU, double startAngleV, double endAngleV) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    impObj()->set(radius, center, northAxis, refAxis, startAngleU, endAngleU, startAngleV, endAngleV);
#endif
}

boost::python::tuple PyGeSphere::intersectWith1(const PyGeLinearEnt3d& ent) const
{
    PyAutoLockGIL lock;
    int intn = 0;
    AcGePoint3d p1;
    AcGePoint3d p2;
    return boost::python::make_tuple(intn, p1, p2);
}

boost::python::tuple PyGeSphere::intersectWith2(const PyGeLinearEnt3d&, const AcGeTol& tol) const
{
    PyAutoLockGIL lock;
    int intn = 0;
    AcGePoint3d p1;
    AcGePoint3d p2;
    return boost::python::make_tuple(intn, p1, p2, tol);
}

PyGeSphere PyGeSphere::cast(const PyGeEntity3d& src)
{
    return PyGeEntity3dCast<PyGeSphere, AcGeSphere>(src);
}

PyGeSphere PyGeSphere::copycast(const PyGeEntity3d& src)
{
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
#if !defined(_BRXTARGET260)
    PyDocString DS("Torus");
    class_<PyGeTorus, bases<PyGeSurface>>("Torus")
        .def(init<>(DS.ARGS(12812)))
        .def("cast", &PyGeTorus::cast, DS.SARGS({ "otherObject: PyGe.Entity3d" })).staticmethod("cast")
        .def("copycast", &PyGeTorus::copycast, DS.SARGS({ "otherObject: PyGe.Entity3d" })).staticmethod("copycast")
        .def("className", &PyGeTorus::className, DS.SARGS()).staticmethod("className")
        ;
#endif
}

#if !defined(_BRXTARGET260)
PyGeTorus::PyGeTorus()
    : PyGeSurface(new AcGeTorus())
{
}

PyGeTorus::PyGeTorus(const AcGeTorus& src)
    : PyGeSurface(new AcGeTorus(src))
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
    return PyGeEntity3dCast<PyGeTorus, AcGeTorus>(src);
}

PyGeTorus PyGeTorus::copycast(const PyGeEntity3d& src)
{
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
#endif