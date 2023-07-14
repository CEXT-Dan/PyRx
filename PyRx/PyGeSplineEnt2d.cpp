#include "stdafx.h"
#include "PyGeSplineEnt2d.h"
#include "PyGeKnotVector.h"

using namespace boost::python;
//-----------------------------------------------------------------------------------------
//PyGeSplineEnt2d wrapper
void makePyGeSplineEnt2dWrapper()
{
    class_<PyGeSplineEnt2d, bases<PyGeCurve2d>>("SplineEnt2d", boost::python::no_init)
        .def("isRational", &PyGeSplineEnt2d::isRational)
        .def("degree", &PyGeSplineEnt2d::degree)
        .def("order", &PyGeSplineEnt2d::order)
        .def("numKnots", &PyGeSplineEnt2d::numKnots)
        .def("knots", &PyGeSplineEnt2d::knots)
        .def("numControlPoints", &PyGeSplineEnt2d::numControlPoints)
        .def("continuityAtKnot", &PyGeSplineEnt2d::continuityAtKnot1)
        .def("continuityAtKnot", &PyGeSplineEnt2d::continuityAtKnot2)
        .def("startParam", &PyGeSplineEnt2d::startParam)
        .def("endParam", &PyGeSplineEnt2d::endParam)
        .def("startPoint", &PyGeSplineEnt2d::startPoint)
        .def("endPoint", &PyGeSplineEnt2d::endPoint)
        .def("hasFitData", &PyGeSplineEnt2d::hasFitData)
        .def("knotAt", &PyGeSplineEnt2d::knotAt)
        .def("setKnotAt", &PyGeSplineEnt2d::setKnotAt, return_self<>())
        .def("controlPointAt", &PyGeSplineEnt2d::controlPointAt)
        .def("setControlPointAt", &PyGeSplineEnt2d::setControlPointAt, return_self<>())
        .def("className", &PyGeSplineEnt2d::className).staticmethod("className")
        ;
}

PyGeSplineEnt2d::PyGeSplineEnt2d(AcGeEntity2d* pEnt)
    : PyGeCurve2d(pEnt)
{
}

Adesk::Boolean PyGeSplineEnt2d::isRational() const
{
    return impObj()->isRational();
}

int PyGeSplineEnt2d::degree() const
{
    return impObj()->degree();
}

int PyGeSplineEnt2d::order() const
{
    return impObj()->order();
}

int PyGeSplineEnt2d::numKnots() const
{
    return impObj()->numKnots();
}

PyGeKnotVector PyGeSplineEnt2d::knots() const
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return PyGeKnotVector(impObj()->knots());
#endif
}

int PyGeSplineEnt2d::numControlPoints() const
{
    return impObj()->numControlPoints();
}

int PyGeSplineEnt2d::continuityAtKnot1(int idx) const
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return impObj()->continuityAtKnot(idx);
#endif
}

int PyGeSplineEnt2d::continuityAtKnot2(int idx, const AcGeTol& tol) const
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return impObj()->continuityAtKnot(idx, tol);
#endif
}

double PyGeSplineEnt2d::startParam() const
{
    return impObj()->startParam();
}

double PyGeSplineEnt2d::endParam() const
{
    return impObj()->endParam();
}

AcGePoint2d PyGeSplineEnt2d::startPoint() const
{
    return impObj()->startPoint();
}

AcGePoint2d PyGeSplineEnt2d::endPoint() const
{
    return impObj()->endPoint();
}

Adesk::Boolean PyGeSplineEnt2d::hasFitData() const
{
    return impObj()->hasFitData();
}

double PyGeSplineEnt2d::knotAt(int idx) const
{
    return impObj()->knotAt(idx);
}

PyGeSplineEnt2d& PyGeSplineEnt2d::setKnotAt(int idx, double val)
{
    impObj()->setKnotAt(idx, val);
    return *this;
}

AcGePoint2d PyGeSplineEnt2d::controlPointAt(int idx) const
{
    return impObj()->controlPointAt(idx);
}

PyGeSplineEnt2d& PyGeSplineEnt2d::setControlPointAt(int idx, const AcGePoint2d& pnt)
{
    impObj()->setControlPointAt(idx, pnt);
    return *this;
}

std::string PyGeSplineEnt2d::className()
{
    return "AcGeSplineEnt2d";
}

AcGeSplineEnt2d* PyGeSplineEnt2d::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_imp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcGeSplineEnt2d*>(m_imp.get());
}

//-----------------------------------------------------------------------------------------
//AcGeCubicSplineCurve2d wrapper
void makAcGeCubicSplineCurve2dWrapper()
{
    class_<PyGeCubicSplineCurve2d, bases<PyGeSplineEnt2d>>("CubicSplineCurve2d")
        .def("className", &PyGeCubicSplineCurve2d::className).staticmethod("className")
        ;
}

PyGeCubicSplineCurve2d::PyGeCubicSplineCurve2d()
    : PyGeSplineEnt2d(new AcGeCubicSplineCurve2d())
{
}

PyGeCubicSplineCurve2d::PyGeCubicSplineCurve2d(AcGeEntity2d* pEnt)
    : PyGeSplineEnt2d(pEnt)
{
}

std::string PyGeCubicSplineCurve2d::className()
{
    return "AcGeCubicSplineCurve2d";
}

AcGeCubicSplineCurve2d* PyGeCubicSplineCurve2d::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_imp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcGeCubicSplineCurve2d*>(m_imp.get());
}

//-----------------------------------------------------------------------------------------
//AcGeNurbCurve2d  wrapper
void makAcGeNurbCurve2dWrapper()
{
    class_<PyGeNurbCurve2d, bases<PyGeSplineEnt2d>>("NurbCurve2d")
        .def("className", &PyGeNurbCurve2d::className).staticmethod("className")
        ;
}

PyGeNurbCurve2d::PyGeNurbCurve2d()
    : PyGeSplineEnt2d(new AcGeNurbCurve2d())
{
}

PyGeNurbCurve2d::PyGeNurbCurve2d(AcGeEntity2d* pEnt)
    : PyGeSplineEnt2d(pEnt)
{
}

std::string PyGeNurbCurve2d::className()
{
    return "AcGeNurbCurve2d";
}

AcGeNurbCurve2d* PyGeNurbCurve2d::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_imp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcGeNurbCurve2d*>(m_imp.get());
}

//-----------------------------------------------------------------------------------------
//AcGeNurbCurve2d  wrapper
void makAcGePolyline2dWrapper()
{
    class_<PyGePolyline2d, bases<PyGeSplineEnt2d>>("Polyline2d")
        .def(init<>())
        .def(init<const boost::python::list&>())
        .def(init<const PyGeKnotVector&, const boost::python::list&>())
        .def(init<const PyGeCurve2d&, double>())
        .def("numFitPoints", &PyGePolyline2d::numFitPoints)
        .def("fitPointAt", &PyGePolyline2d::fitPointAt)
        .def("setFitPointAt", &PyGePolyline2d::setFitPointAt, return_self<>())
        .def("className", &PyGePolyline2d::className).staticmethod("className")
        ;
}

PyGePolyline2d::PyGePolyline2d()
    : PyGeSplineEnt2d(new AcGePolyline2d())
{
}

PyGePolyline2d::PyGePolyline2d(AcGeEntity2d* pEnt)
    : PyGeSplineEnt2d(pEnt)
{
}

PyGePolyline2d::PyGePolyline2d(const AcGePolyline2d& src)
    : PyGeSplineEnt2d(new AcGePolyline2d(src))
{
}

PyGePolyline2d::PyGePolyline2d(const boost::python::list& points)
    : PyGeSplineEnt2d(new AcGePolyline2d(PyListToPoint2dArray(points)))
{
}

PyGePolyline2d::PyGePolyline2d(const PyGeKnotVector& knots, const boost::python::list& points)
    : PyGeSplineEnt2d(new AcGePolyline2d(knots.m_imp, PyListToPoint2dArray(points)))
{
}

PyGePolyline2d::PyGePolyline2d(const PyGeCurve2d& crv, double apprEps)
    : PyGeSplineEnt2d(new AcGePolyline2d(*crv.impObj(), apprEps))
{
}

int PyGePolyline2d::numFitPoints() const
{
    return impObj()->numFitPoints();
}

AcGePoint2d PyGePolyline2d::fitPointAt(int idx) const
{
    return impObj()->fitPointAt(idx);
}

PyGeSplineEnt2d& PyGePolyline2d::setFitPointAt(int idx, const AcGePoint2d& point)
{
    impObj()->setFitPointAt(idx, point);
    return *this;
}

std::string PyGePolyline2d::className()
{
    return "AcGePolyline2d";
}

AcGePolyline2d* PyGePolyline2d::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_imp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcGePolyline2d*>(m_imp.get());
}
