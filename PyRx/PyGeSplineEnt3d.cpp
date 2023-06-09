#include "stdafx.h"
#include "PyGeSplineEnt3d.h"
#include "PyGeKnotVector.h"
using namespace boost::python;

//-----------------------------------------------------------------------------------------
//PyGeSplineEnt3d wrapper
void makePyGeSplineEnt3dWrapper()
{
    class_<PyGeSplineEnt3d, bases<PyGeCurve3d>>("SplineEnt3d", boost::python::no_init)
        .def("isRational", &PyGeSplineEnt3d::isRational)
        .def("degree", &PyGeSplineEnt3d::degree)
        .def("order", &PyGeSplineEnt3d::order)
        .def("numKnots", &PyGeSplineEnt3d::numKnots)
        .def("knots", &PyGeSplineEnt3d::knots)
        .def("numControlPoints", &PyGeSplineEnt3d::numControlPoints)
        .def("continuityAtKnot", &PyGeSplineEnt3d::continuityAtKnot1)
        .def("continuityAtKnot", &PyGeSplineEnt3d::continuityAtKnot2)
        .def("startParam", &PyGeSplineEnt3d::startParam)
        .def("endParam", &PyGeSplineEnt3d::endParam)
        .def("startPoint", &PyGeSplineEnt3d::startPoint)
        .def("endPoint", &PyGeSplineEnt3d::endPoint)
        .def("hasFitData", &PyGeSplineEnt3d::hasFitData)
        .def("knotAt", &PyGeSplineEnt3d::knotAt)
        .def("setKnotAt", &PyGeSplineEnt3d::setKnotAt, return_self<>())
        .def("controlPointAt", &PyGeSplineEnt3d::controlPointAt)
        .def("setControlPointAt", &PyGeSplineEnt3d::setControlPointAt, return_self<>())
        .def("className", &PyGeSplineEnt3d::className).staticmethod("className")
        ;
}

PyGeSplineEnt3d::PyGeSplineEnt3d(AcGeEntity3d* pEnt)
    : PyGeCurve3d(pEnt)
{
}

Adesk::Boolean PyGeSplineEnt3d::isRational() const
{
    return impObj()->isRational();
}

int PyGeSplineEnt3d::degree() const
{
    return impObj()->degree();
}

int PyGeSplineEnt3d::order() const
{
    return impObj()->order();
}

int PyGeSplineEnt3d::numKnots() const
{
    return impObj()->numKnots();
}

PyGeKnotVector PyGeSplineEnt3d::knots() const
{
    return PyGeKnotVector(impObj()->knots());
}

int PyGeSplineEnt3d::numControlPoints() const
{
    return impObj()->numControlPoints();
}

int PyGeSplineEnt3d::continuityAtKnot1(int idx) const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->continuityAtKnot(idx);
#endif
}

int PyGeSplineEnt3d::continuityAtKnot2(int idx, const AcGeTol& tol) const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->continuityAtKnot(idx, tol);
#endif
}

double PyGeSplineEnt3d::startParam() const
{
    return impObj()->startParam();
}

double PyGeSplineEnt3d::endParam() const
{
    return impObj()->endParam();
}

AcGePoint3d PyGeSplineEnt3d::startPoint() const
{
    return impObj()->startPoint();
}

AcGePoint3d PyGeSplineEnt3d::endPoint() const
{
    return impObj()->endPoint();
}

Adesk::Boolean PyGeSplineEnt3d::hasFitData() const
{
    return impObj()->hasFitData();
}

double PyGeSplineEnt3d::knotAt(int idx) const
{
    return impObj()->knotAt(idx);
}

PyGeSplineEnt3d& PyGeSplineEnt3d::setKnotAt(int idx, double val)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    impObj()->setKnotAt(idx, val);
    return *this;
#endif
}

AcGePoint3d PyGeSplineEnt3d::controlPointAt(int idx) const
{
    return impObj()->controlPointAt(idx);
}

PyGeSplineEnt3d& PyGeSplineEnt3d::setControlPointAt(int idx, const AcGePoint3d& pnt)
{
    impObj()->setControlPointAt(idx, pnt);
    return *this;
}

std::string PyGeSplineEnt3d::className()
{
    return "AcGeSplineEnt3d";
}

AcGeSplineEnt3d* PyGeSplineEnt3d::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_imp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcGeSplineEnt3d*>(m_imp.get());
}

//-----------------------------------------------------------------------------------------
//AcGeCubicSplineCurve3d wrapper
void makAcGeCubicSplineCurve3dWrapper()
{
    class_<PyGeCubicSplineCurve3d, bases<PyGeSplineEnt3d>>("CubicSplineCurve3d")
        .def("className", &PyGeCubicSplineCurve3d::className).staticmethod("className")
        ;
}

PyGeCubicSplineCurve3d::PyGeCubicSplineCurve3d()
    : PyGeSplineEnt3d(new AcGeCubicSplineCurve3d())
{
}

PyGeCubicSplineCurve3d::PyGeCubicSplineCurve3d(AcGeEntity3d* pEnt)
    : PyGeSplineEnt3d(pEnt)
{
}

std::string PyGeCubicSplineCurve3d::className()
{
    return "AcGeCubicSplineCurve3d";
}

AcGeCubicSplineCurve3d* PyGeCubicSplineCurve3d::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_imp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcGeCubicSplineCurve3d*>(m_imp.get());
}

//-----------------------------------------------------------------------------------------
//AcGeNurbCurve3d  wrapper
void makAcGeNurbCurve3dWrapper()
{
    class_<PyGeNurbCurve3d, bases<PyGeSplineEnt3d>>("NurbCurve3d")
        .def("className", &PyGeNurbCurve3d::className).staticmethod("className")
        ;
}

PyGeNurbCurve3d::PyGeNurbCurve3d()
    : PyGeSplineEnt3d(new AcGeNurbCurve3d())
{
}

PyGeNurbCurve3d::PyGeNurbCurve3d(AcGeEntity3d* pEnt)
    : PyGeSplineEnt3d(pEnt)
{
}

std::string PyGeNurbCurve3d::className()
{
    return "AcGeNurbCurve3d";
}

AcGeNurbCurve3d* PyGeNurbCurve3d::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_imp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcGeNurbCurve3d*>(m_imp.get());
}

//-----------------------------------------------------------------------------------------
//AcGeNurbCurve3d  wrapper
void makAcGePolyline3dWrapper()
{
    class_<PyGePolyline3d, bases<PyGeSplineEnt3d>>("Polyline3d")
        .def(init<>())
        .def(init<const boost::python::list&>())
        .def(init<const PyGeKnotVector&, const boost::python::list&>())
#ifndef BRXAPP
        .def(init<const PyGeCurve3d&, double>())
#endif // BRXAPP
        .def("numFitPoints", &PyGePolyline3d::numFitPoints)
        .def("fitPointAt", &PyGePolyline3d::fitPointAt)
        .def("setFitPointAt", &PyGePolyline3d::setFitPointAt, return_self<>())
        .def("className", &PyGePolyline3d::className).staticmethod("className")
        ;
}

PyGePolyline3d::PyGePolyline3d()
    : PyGeSplineEnt3d(new AcGePolyline3d())
{
}

PyGePolyline3d::PyGePolyline3d(AcGeEntity3d* pEnt)
    : PyGeSplineEnt3d(pEnt)
{
}

PyGePolyline3d::PyGePolyline3d(const AcGePolyline3d& src)
    : PyGeSplineEnt3d(new AcGePolyline3d(src))
{
}

PyGePolyline3d::PyGePolyline3d(const boost::python::list& points)
    : PyGeSplineEnt3d(new AcGePolyline3d(PyListToPoint3dArray(points)))
{
}

PyGePolyline3d::PyGePolyline3d(const PyGeKnotVector& knots, const boost::python::list& points)
    : PyGeSplineEnt3d(new AcGePolyline3d(knots.m_imp, PyListToPoint3dArray(points)))
{
}

#ifndef BRXAPP
PyGePolyline3d::PyGePolyline3d(const PyGeCurve3d& crv, double apprEps)
    : PyGeSplineEnt3d(new AcGePolyline3d(*crv.impObj(), apprEps))
{
}
#endif

int PyGePolyline3d::numFitPoints() const
{
    return impObj()->numFitPoints();
}

AcGePoint3d PyGePolyline3d::fitPointAt(int idx) const
{
    return impObj()->fitPointAt(idx);
}

PyGeSplineEnt3d& PyGePolyline3d::setFitPointAt(int idx, const AcGePoint3d& point)
{
    impObj()->setFitPointAt(idx, point);
    return *this;
}

std::string PyGePolyline3d::className()
{
    return "AcGePolyline3d";
}

AcGePolyline3d* PyGePolyline3d::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_imp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcGePolyline3d*>(m_imp.get());
}
