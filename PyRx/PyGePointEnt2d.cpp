#include "stdafx.h"
#include "PyGePointEnt2d.h"
#include "PyGeCurve2d.h"

using namespace boost::python;

//-----------------------------------------------------------------------------------------
//PyGePointEnt2d wrapper
void makePyGePointEnt2dWrapper()
{
    class_<PyGePointEnt2d, bases<PyGeEntity2d>>("PointEnt2d", boost::python::no_init)
        .def("point2d", &PyGePointEnt2d::point2d)
        .def("className", &PyGePointEnt2d::className).staticmethod("className")
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

std::string PyGePointEnt2d::className()
{
    return "AcGePointEnt2d";
}

AcGePointEnt2d* PyGePointEnt2d::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_imp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcGePointEnt2d*>(m_imp.get());
}

//-----------------------------------------------------------------------------------------
//PyGePointOnCurve2d wrapper
void makePyGePointOnCurve2dWrapper()
{
    class_<PyGePointOnCurve2d, bases<PyGePointEnt2d>>("PointOnCurve2d")
        .def(init<>())
        .def(init<const PyGeCurve2d&>())
        .def(init<const PyGeCurve2d&, double>())
        .def("curve", &PyGePointOnCurve2d::curve)
        .def("parameter", &PyGePointOnCurve2d::parameter)
        .def("point", &PyGePointOnCurve2d::point1)
        .def("point", &PyGePointOnCurve2d::point2)
        .def("point", &PyGePointOnCurve2d::point3)
        .def("deriv", &PyGePointOnCurve2d::deriv1)
        .def("deriv", &PyGePointOnCurve2d::deriv2)
        .def("deriv", &PyGePointOnCurve2d::deriv3)
        .def("setCurve", &PyGePointOnCurve2d::setCurve, return_self<>())
        .def("setParameter", &PyGePointOnCurve2d::setParameter, return_self<>())
        .def("className", &PyGePointOnCurve2d::className).staticmethod("className")
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
    if(result == nullptr)
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

AcGePoint2d PyGePointOnCurve2d::point2(double param)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->point(param);
#endif
}

AcGePoint2d PyGePointOnCurve2d::point3(const PyGeCurve2d& crv, double param)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->point(*crv.impObj(), param);
#endif
}

AcGeVector2d PyGePointOnCurve2d::deriv1(int order) const
{
    return impObj()->deriv(order);
}

AcGeVector2d PyGePointOnCurve2d::deriv2(int order, double param)
{
    return impObj()->deriv(order, param);
}

AcGeVector2d PyGePointOnCurve2d::deriv3(int order, const PyGeCurve2d& crv, double param)
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
    auto flag = imp->curvature(param,res);
    return make_tuple(flag, res);
}
#endif

PyGePointOnCurve2d& PyGePointOnCurve2d::setCurve(const PyGeCurve2d& crv)
{
    impObj()->setCurve(*crv.impObj());
    return *this;
}

PyGePointOnCurve2d& PyGePointOnCurve2d::setParameter(double param)
{
    impObj()->setParameter(param);
    return *this;
}

std::string PyGePointOnCurve2d::className()
{
    return "AcGePointOnCurve2d";
}

AcGePointOnCurve2d* PyGePointOnCurve2d::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_imp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcGePointOnCurve2d*>(m_imp.get());
}

//-----------------------------------------------------------------------------------------
//AcGePosition2d wrapper
void makeAcGePosition2dWrapper()
{
    class_<PyGePosition2d, bases<PyGePointEnt2d>>("Position2d")
        .def(init<>())
        .def(init<const AcGePoint2d&>())
        .def(init<double, double>())
        .def("set", &PyGePosition2d::set1, return_self<>())
        .def("set", &PyGePosition2d::set2, return_self<>())
        .def("className", &PyGePosition2d::className).staticmethod("className")
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
    : PyGePointEnt2d(new AcGePosition2d(x,y))
{
}
#ifndef BRXAPP
PyGePosition2d::PyGePosition2d(const AcGePosition2d& pos)
    : PyGePointEnt2d(new AcGePosition2d(pos))
{
}
#endif

PyGePosition2d& PyGePosition2d::set1(const AcGePoint2d& pnt)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    impObj()->set(pnt);
    return *this;
#endif
}

PyGePosition2d& PyGePosition2d::set2(double x, double y)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    impObj()->set(x,y);
    return *this;
#endif
}

std::string PyGePosition2d::className()
{
    return "AcGePosition2d";
}

AcGePosition2d* PyGePosition2d::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    return static_cast<AcGePosition2d*>(m_imp.get());
}
