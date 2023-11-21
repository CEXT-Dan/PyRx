#include "stdafx.h"
#include "PyGeCurveSurfInt.h"
#include "PyGeCurve3d.h"
#include "PyGeSurface.h"
#include "PyGePointEnt3d.h"

using namespace boost::python;

void makePyGeCurveSurfIntWrapper()
{
#if !defined(_BRXTARGET) || (_BRXTARGET > 240)
    class_<PyGeCurveSurfInt, bases<PyGeEntity3d>>("CurveSurfInt")
        .def(init<>())
        .def(init<const PyGeCurve3d&, const PyGeSurface&>())
        .def(init<const PyGeCurve3d&, const PyGeSurface&, const AcGeTol&>())
        .def("curve", &PyGeCurveSurfInt::curve)
        .def("surface", &PyGeCurveSurfInt::surface)
        .def("tolerance", &PyGeCurveSurfInt::tolerance)
        .def("numIntPoints", &PyGeCurveSurfInt::numIntPoints)
        .def("intPoint", &PyGeCurveSurfInt::intPoint)
        .def("getIntParams", &PyGeCurveSurfInt::getIntParams)
        .def("getPointOnCurve", &PyGeCurveSurfInt::getPointOnCurve)
        .def("getPointOnSurface", &PyGeCurveSurfInt::getPointOnSurface)
        .def("getIntConfigs", &PyGeCurveSurfInt::getIntConfigs)
        .def("set", &PyGeCurveSurfInt::set1)
        .def("set", &PyGeCurveSurfInt::set2)
        .def("cast", &PyGeCurveSurfInt::cast).staticmethod("cast")
        .def("copycast", &PyGeCurveSurfInt::copycast).staticmethod("copycast")
        .def("className", &PyGeCurveSurfInt::className).staticmethod("className")
        ;
#endif
}

#if !defined(_BRXTARGET) || (_BRXTARGET > 240)
PyGeCurveSurfInt::PyGeCurveSurfInt(AcGeEntity3d* pEnt)
    : PyGeEntity3d(pEnt)
{
}

PyGeCurveSurfInt::PyGeCurveSurfInt()
    : PyGeEntity3d(new AcGeCurveSurfInt())
{
}

PyGeCurveSurfInt::PyGeCurveSurfInt(const PyGeCurve3d& crv, const PyGeSurface& srf)
    : PyGeEntity3d(new AcGeCurveSurfInt(*crv.impObj(), *srf.impObj()))
{
}

PyGeCurveSurfInt::PyGeCurveSurfInt(const PyGeCurve3d& crv, const PyGeSurface& srf, const AcGeTol& tol)
    : PyGeEntity3d(new AcGeCurveSurfInt(*crv.impObj(), *srf.impObj(), tol))
{
}

PyGeCurveSurfInt::PyGeCurveSurfInt(const AcGeCurveSurfInt& src)
    : PyGeEntity3d(new AcGeCurveSurfInt(src))
{
}

PyGeCurve3d PyGeCurveSurfInt::curve() const
{
    return PyGeCurve3d(impObj()->curve());
}

PyGeSurface PyGeCurveSurfInt::surface() const
{
    return PyGeSurface(impObj()->surface());
}

AcGeTol PyGeCurveSurfInt::tolerance() const
{
    return impObj()->tolerance();
}

int PyGeCurveSurfInt::numIntPoints() const
{
    AcGeIntersectError err = AcGe::kXXOk;
    auto res = impObj()->numIntPoints(err);
    if (err != AcGe::kXXOk)
        throw PyAcadErrorStatus(static_cast<Acad::ErrorStatus>(err));
    return res;
}

AcGePoint3d PyGeCurveSurfInt::intPoint(int intNum) const
{
    AcGeIntersectError err = AcGe::kXXOk;
    auto res = impObj()->intPoint(intNum, err);
    if (err != AcGe::kXXOk)
        throw PyAcadErrorStatus(static_cast<Acad::ErrorStatus>(err));
    return res;
}

boost::python::tuple PyGeCurveSurfInt::getIntParams(int intNum) const
{
    PyAutoLockGIL lock;
    double param = 0;
    AcGePoint2d pnt;
    AcGeIntersectError err = AcGe::kXXOk;
    impObj()->getIntParams(intNum, param, pnt, err);
    if (err != AcGe::kXXOk)
        throw PyAcadErrorStatus(static_cast<Acad::ErrorStatus>(err));
    return boost::python::make_tuple(param, pnt);
}

boost::python::tuple PyGeCurveSurfInt::getPointOnCurve(int intNum) const
{
    PyAutoLockGIL lock;
    AcGePointOnCurve3d curve;
    AcGeIntersectError err = AcGe::kXXOk;
    impObj()->getPointOnCurve(intNum, curve, err);
    if (err != AcGe::kXXOk)
        throw PyAcadErrorStatus(static_cast<Acad::ErrorStatus>(err));
    return boost::python::make_tuple(PyGePointOnCurve3d(curve.copy()));
}

boost::python::tuple PyGeCurveSurfInt::getPointOnSurface(int intNum) const
{
    PyAutoLockGIL lock;
    AcGePointOnSurface curve;
    AcGeIntersectError err = AcGe::kXXOk;
    impObj()->getPointOnSurface(intNum, curve, err);
    if (err != AcGe::kXXOk)
        throw PyAcadErrorStatus(static_cast<Acad::ErrorStatus>(err));
    return boost::python::make_tuple(PyGePointOnSurface(curve.copy()));
}

boost::python::tuple PyGeCurveSurfInt::getIntConfigs(int intNum) const
{
    PyAutoLockGIL lock;
    AcGe::csiConfig lower;
    AcGe::csiConfig higher;
    Adesk::Boolean smallAngle;
    AcGeIntersectError err = AcGe::kXXOk;
    impObj()->getIntConfigs(intNum, lower, higher, smallAngle, err);
    if (err != AcGe::kXXOk)
        throw PyAcadErrorStatus(static_cast<Acad::ErrorStatus>(err));
    return boost::python::make_tuple((int)lower, (int)higher, smallAngle);
}

void PyGeCurveSurfInt::set1(const PyGeCurve3d& cvr, const PyGeSurface& srf)
{
    impObj()->set(*cvr.impObj(), *srf.impObj());
}

void PyGeCurveSurfInt::set2(const PyGeCurve3d& cvr, const PyGeSurface& srf, const AcGeTol& tol)
{
    impObj()->set(*cvr.impObj(), *srf.impObj(), tol);
}

PyGeCurveSurfInt PyGeCurveSurfInt::cast(const PyGeEntity3d& src)
{
    if (!src.impObj()->isKindOf(AcGe::EntityId::kCurveSurfaceInt))
        PyThrowBadEs(Acad::eNotThatKindOfClass);
    return PyGeEntity3dCast<PyGeCurveSurfInt>(src);
}

PyGeCurveSurfInt PyGeCurveSurfInt::copycast(const PyGeEntity3d& src)
{
    if (!src.impObj()->isKindOf(AcGe::EntityId::kCurveSurfaceInt))
        PyThrowBadEs(Acad::eNotThatKindOfClass);
    return PyGeCurveSurfInt(src.impObj()->copy());
}

std::string PyGeCurveSurfInt::className()
{
    return "AcGeCurveSurfInt";
}

AcGeCurveSurfInt* PyGeCurveSurfInt::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_imp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcGeCurveSurfInt*>(m_imp.get());
}
#endif