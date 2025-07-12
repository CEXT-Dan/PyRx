#include "stdafx.h"
#include "PyGeCurveSurfInt.h"
#include "PyGeCurve3d.h"
#include "PyGeSurface.h"
#include "PyGePointEnt3d.h"

using namespace boost::python;

void makePyGeCurveSurfIntWrapper()
{
#if !defined(_BRXTARGET260)
    constexpr const std::string_view ctor = "Overloads:\n"
        "- None: Any\n"
        "- curve: PyGe.Curve3d, surf: PyGe.Surface\n"
        "- curve: PyGe.Curve3d, surf: PyGe.Surface, tol: PyGe.Tol\n";

    constexpr const std::string_view setOverloads = "Overloads:\n"
        "- curve: PyGe.Curve3d, surf: PyGe.Surface\n"
        "- curve: PyGe.Curve3d, surf: PyGe.Surface, tol: PyGe.Tol\n";

    PyDocString DS("CurveSurfInt");
    class_<PyGeCurveSurfInt, bases<PyGeEntity3d>>("CurveSurfInt")
        .def(init<>())
        .def(init<const PyGeCurve3d&, const PyGeSurface&>())
        .def(init<const PyGeCurve3d&, const PyGeSurface&, const AcGeTol&>(DS.CTOR(ctor, 11936)))
        .def("curve", &PyGeCurveSurfInt::curve, DS.ARGS())
        .def("surface", &PyGeCurveSurfInt::surface, DS.ARGS())
        .def("tolerance", &PyGeCurveSurfInt::tolerance, DS.ARGS())
        .def("numIntPoints", &PyGeCurveSurfInt::numIntPoints, DS.ARGS())
        .def("intPoint", &PyGeCurveSurfInt::intPoint, DS.ARGS({ "intNum: int" }))
        .def("getIntParams", &PyGeCurveSurfInt::getIntParams, DS.ARGS({ "intNum: int" }))
        .def("getPointOnCurve", &PyGeCurveSurfInt::getPointOnCurve, DS.ARGS({ "intNum: int" }))
        .def("getPointOnSurface", &PyGeCurveSurfInt::getPointOnSurface, DS.ARGS({ "intNum: int" }))
        .def("getIntConfigs", &PyGeCurveSurfInt::getIntConfigs, DS.ARGS({ "intNum: int" }))
        .def("set", &PyGeCurveSurfInt::set1)
        .def("set", &PyGeCurveSurfInt::set2, DS.OVRL(setOverloads))
        .def("cast", &PyGeCurveSurfInt::cast, DS.SARGS({ "otherObject: PyGe.Entity3d" })).staticmethod("cast")
        .def("copycast", &PyGeCurveSurfInt::copycast, DS.SARGS({ "otherObject: PyGe.Entity3d" })).staticmethod("copycast")
        .def("className", &PyGeCurveSurfInt::className, DS.SARGS()).staticmethod("className")
        ;
#endif
}

#if !defined(_BRXTARGET260)
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
        throw PyErrorStatusException(static_cast<Acad::ErrorStatus>(err));
    return res;
}

AcGePoint3d PyGeCurveSurfInt::intPoint(int intNum) const
{
    AcGeIntersectError err = AcGe::kXXOk;
    auto res = impObj()->intPoint(intNum, err);
    if (err != AcGe::kXXOk)
        throw PyErrorStatusException(static_cast<Acad::ErrorStatus>(err));
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
        throw PyErrorStatusException(static_cast<Acad::ErrorStatus>(err));
    return boost::python::make_tuple(param, pnt);
}

PyGePointOnCurve3d PyGeCurveSurfInt::getPointOnCurve(int intNum) const
{
    PyAutoLockGIL lock;
    AcGePointOnCurve3d curve;
    AcGeIntersectError err = AcGe::kXXOk;
    impObj()->getPointOnCurve(intNum, curve, err);
    if (err != AcGe::kXXOk)
        throw PyErrorStatusException(static_cast<Acad::ErrorStatus>(err));
    return PyGePointOnCurve3d(curve.copy());
}

PyGePointOnSurface PyGeCurveSurfInt::getPointOnSurface(int intNum) const
{
    PyAutoLockGIL lock;
    AcGePointOnSurface curve;
    AcGeIntersectError err = AcGe::kXXOk;
    impObj()->getPointOnSurface(intNum, curve, err);
    if (err != AcGe::kXXOk)
        throw PyErrorStatusException(static_cast<Acad::ErrorStatus>(err));
    return PyGePointOnSurface(curve.copy());
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
        throw PyErrorStatusException(static_cast<Acad::ErrorStatus>(err));
    return boost::python::make_tuple(lower, higher, smallAngle);
}

void PyGeCurveSurfInt::set1(const PyGeCurve3d& cvr, const PyGeSurface& srf) const
{
    impObj()->set(*cvr.impObj(), *srf.impObj());
}

void PyGeCurveSurfInt::set2(const PyGeCurve3d& cvr, const PyGeSurface& srf, const AcGeTol& tol) const
{
    impObj()->set(*cvr.impObj(), *srf.impObj(), tol);
}

PyGeCurveSurfInt PyGeCurveSurfInt::cast(const PyGeEntity3d& src)
{
    return PyGeEntity3dCast<PyGeCurveSurfInt, AcGeCurveSurfInt>(src);
}

PyGeCurveSurfInt PyGeCurveSurfInt::copycast(const PyGeEntity3d& src)
{
    return PyGeCurveSurfInt(static_cast<AcGeCurveSurfInt*>(src.impObj()->copy()));
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
