#include "stdafx.h"
#include "PyGePointEnt2d.h"
#include "PyGeCurve2d.h"

using namespace boost::python;

//-----------------------------------------------------------------------------------------
//PyGePointEnt2d wrapper
void makePyGePointEnt2dWrapper()
{
    PyDocString DS("PointEnt2d");
    class_<PyGePointEnt2d, bases<PyGeEntity2d>>("PointEnt2d", boost::python::no_init)
        .def("point2d", &PyGePointEnt2d::point2d, DS.ARGS())
        .def("cast", &PyGePointEnt2d::cast, DS.SARGS({ "otherObject: PyGe.Entity2d" })).staticmethod("cast")
        .def("copycast", &PyGePointEnt2d::copycast, DS.SARGS({ "otherObject: PyGe.Entity2d" })).staticmethod("copycast")
        .def("className", &PyGePointEnt2d::className, DS.SARGS()).staticmethod("className")
        ;
}

PyGePointEnt2d::PyGePointEnt2d(AcGeEntity2d* pEnt)
    : PyGeEntity2d(pEnt)
{
}

AcGePoint2d PyGePointEnt2d::point2d() const
{
    return impObj()->point2d();
}

PyGePointEnt2d PyGePointEnt2d::cast(const PyGeEntity2d& src)
{
    return PyGeEntity2dCast<PyGePointEnt2d, AcGePointEnt2d>(src);
}

PyGePointEnt2d PyGePointEnt2d::copycast(const PyGeEntity2d& src)
{
    return PyGePointEnt2d(static_cast<AcGePointEnt2d*>(src.impObj()->copy()));
}

std::string PyGePointEnt2d::className()
{
    return "AcGePointEnt2d";
}

AcGePointEnt2d* PyGePointEnt2d::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_imp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcGePointEnt2d*>(m_imp.get());
}

//-----------------------------------------------------------------------------------------
//PyGePointOnCurve2d wrapper
void makePyGePointOnCurve2dWrapper()
{
    constexpr const std::string_view ctor = "Overloads:\n"
        "- None: Any\n"
        "- curve: PyGe.Curve2d\n"
        "- curve: PyGe.Curve2d, param: float\n";

    constexpr const std::string_view pointOverloads = "Overloads:\n"
        "- None: Any\n"
        "- param: float\n"
        "- curve: PyGe.Curve2d, param: float\n";

    constexpr const std::string_view derivOverloads = "Overloads:\n"
        "- order: int\n"
        "- order: int, param: float\n"
        "- order: int, curve: PyGe.Curve2d, param: float\n";

    PyDocString DS("PointOnCurve2d");
    class_<PyGePointOnCurve2d, bases<PyGePointEnt2d>>("PointOnCurve2d")
        .def(init<>())
        .def(init<const PyGeCurve2d&>())
        .def(init<const PyGeCurve2d&, double>(DS.CTOR(ctor, 12611)))
        .def("curve", &PyGePointOnCurve2d::curve, DS.ARGS())
        .def("parameter", &PyGePointOnCurve2d::parameter, DS.ARGS())
        .def("point", &PyGePointOnCurve2d::point1)
        .def("point", &PyGePointOnCurve2d::point2)
        .def("point", &PyGePointOnCurve2d::point3, DS.OVRL(pointOverloads))
        .def("deriv", &PyGePointOnCurve2d::deriv1)
        .def("deriv", &PyGePointOnCurve2d::deriv2)
        .def("deriv", &PyGePointOnCurve2d::deriv3, DS.OVRL(derivOverloads))
        .def("setCurve", &PyGePointOnCurve2d::setCurve, DS.ARGS({ "val: PyGe.Curve2d" }))
        .def("setParameter", &PyGePointOnCurve2d::setParameter, DS.ARGS({ "val: float" }))
        .def("cast", &PyGePointOnCurve2d::cast, DS.SARGS({ "otherObject: PyGe.Entity2d" })).staticmethod("cast")
        .def("copycast", &PyGePointOnCurve2d::copycast, DS.SARGS({ "otherObject: PyGe.Entity2d" })).staticmethod("copycast")
        .def("className", &PyGePointOnCurve2d::className, DS.SARGS()).staticmethod("className")
        ;
}

PyGePointOnCurve2d::PyGePointOnCurve2d()
    : PyGePointEnt2d(new AcGePointOnCurve2d())
{
}

PyGePointOnCurve2d::PyGePointOnCurve2d(AcGeEntity2d* pEnt)
    : PyGePointEnt2d(pEnt)
{
}

PyGePointOnCurve2d::PyGePointOnCurve2d(const AcGePointOnCurve2d& src)
    : PyGePointEnt2d(new AcGePointOnCurve2d(src))
{
}

PyGePointOnCurve2d::PyGePointOnCurve2d(const PyGeCurve2d& crv)
    : PyGePointEnt2d(new AcGePointOnCurve2d(*crv.impObj()))
{
}

PyGePointOnCurve2d::PyGePointOnCurve2d(const PyGeCurve2d& crv, double param)
    : PyGePointEnt2d(new AcGePointOnCurve2d(*crv.impObj(), param))
{
}

const PyGeCurve2d PyGePointOnCurve2d::curve() const
{
    auto result = impObj()->curve();
    if (result == nullptr)
        throw PyNullObject(std::source_location::current());
    return PyGeCurve2d(result->copy());
}

double PyGePointOnCurve2d::parameter() const
{
    return impObj()->parameter();
}

AcGePoint2d PyGePointOnCurve2d::point1() const
{
    return impObj()->point();
}

AcGePoint2d PyGePointOnCurve2d::point2(double param) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    return impObj()->point(param);
#endif
}

AcGePoint2d PyGePointOnCurve2d::point3(const PyGeCurve2d& crv, double param) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    return impObj()->point(*crv.impObj(), param);
#endif
}

AcGeVector2d PyGePointOnCurve2d::deriv1(int order) const
{
    return impObj()->deriv(order);
}

AcGeVector2d PyGePointOnCurve2d::deriv2(int order, double param) const
{
    return impObj()->deriv(order, param);
}

AcGeVector2d PyGePointOnCurve2d::deriv3(int order, const PyGeCurve2d& crv, double param) const
{
    return impObj()->deriv(order, *crv.impObj(), param);
}

#ifdef NEVER //acad link error
Adesk::Boolean PyGePointOnCurve2d::isSingular1() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isSingular();
}
#endif

#ifdef NEVER //acad link error
Adesk::Boolean PyGePointOnCurve2d::isSingular2(const AcGeTol& tol) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isSingular(tol);
}
#endif

#ifdef NEVER //acad link error
boost::python::tuple PyGePointOnCurve2d::curvature()
{
    PyAutoLockGIL lock;
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    double res = 0;
    auto flag = imp->curvature(res);
    return make_tuple(flag, res);
}
#endif

#ifdef NEVER //acad link error
boost::python::tuple PyGePointOnCurve2d::curvature(double param)
{
    PyAutoLockGIL lock;
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    double res = 0;
    auto flag = imp->curvature(param, res);
    return make_tuple(flag, res);
}
#endif

void PyGePointOnCurve2d::setCurve(const PyGeCurve2d& crv) const
{
    impObj()->setCurve(*crv.impObj());
}

void PyGePointOnCurve2d::setParameter(double param) const
{
    impObj()->setParameter(param);
}

PyGePointOnCurve2d PyGePointOnCurve2d::copy(const PyGeEntity2d& src)
{
    return PyGeEntity2dCast<PyGePointOnCurve2d, AcGePointOnCurve2d>(src);
}

PyGePointOnCurve2d PyGePointOnCurve2d::copycast(const PyGeEntity2d& src)
{
    return PyGePointOnCurve2d(static_cast<AcGePointOnCurve2d*>(src.impObj()->copy()));
}

std::string PyGePointOnCurve2d::className()
{
    return "AcGePointOnCurve2d";
}

AcGePointOnCurve2d* PyGePointOnCurve2d::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_imp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcGePointOnCurve2d*>(m_imp.get());
}

//-----------------------------------------------------------------------------------------
//AcGePosition2d wrapper
void makePyGePosition2dWrapper()
{
    constexpr const std::string_view ctor = "Overloads:\n"
        "- None: Any\n"
        "- pnt: PyGe.Point2d\n"
        "- x: float, y: float\n";

    constexpr const std::string_view setOverloads = "Overloads:\n"
        "- pnt: PyGe.Point2d\n"
        "- x: float, y: float\n";

    PyDocString DS("Position2d");
    class_<PyGePosition2d, bases<PyGePointEnt2d>>("Position2d")
        .def(init<>())
        .def(init<const AcGePoint2d&>())
        .def(init<double, double>(DS.CTOR(ctor, 12659)))
        .def("set", &PyGePosition2d::set1)
        .def("set", &PyGePosition2d::set2, DS.OVRL(setOverloads))
        .def("cast", &PyGePosition2d::cast, DS.SARGS({ "otherObject: PyGe.Entity2d" })).staticmethod("cast")
        .def("copycast", &PyGePosition2d::copycast, DS.SARGS({ "otherObject: PyGe.Entity2d" })).staticmethod("copycast")
        .def("className", &PyGePosition2d::className, DS.SARGS()).staticmethod("className")
        ;
}

PyGePosition2d::PyGePosition2d()
    : PyGePointEnt2d(new AcGePosition2d())
{
}

PyGePosition2d::PyGePosition2d(AcGeEntity2d* pEnt)
    : PyGePointEnt2d(pEnt)
{
}

PyGePosition2d::PyGePosition2d(const AcGePoint2d& pnt)
    : PyGePointEnt2d(new AcGePosition2d(pnt))
{
}

PyGePosition2d::PyGePosition2d(double x, double y)
    : PyGePointEnt2d(new AcGePosition2d(x, y))
{
}

#if !defined(_BRXTARGET260)
PyGePosition2d::PyGePosition2d(const AcGePosition2d& pos)
    : PyGePointEnt2d(new AcGePosition2d(pos))
{
}
#endif

void PyGePosition2d::set1(const AcGePoint2d& pnt) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    impObj()->set(pnt);
#endif
}

void PyGePosition2d::set2(double x, double y) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    impObj()->set(x, y);
#endif
}

PyGePosition2d PyGePosition2d::cast(const PyGeEntity2d& src)
{
    return PyGeEntity2dCast<PyGePosition2d, AcGePosition2d>(src);
}

PyGePosition2d PyGePosition2d::copycast(const PyGeEntity2d& src)
{
    return PyGePosition2d(static_cast<AcGePosition2d*>(src.impObj()->copy()));
}

std::string PyGePosition2d::className()
{
    return "AcGePosition2d";
}

AcGePosition2d* PyGePosition2d::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    return static_cast<AcGePosition2d*>(m_imp.get());
}
