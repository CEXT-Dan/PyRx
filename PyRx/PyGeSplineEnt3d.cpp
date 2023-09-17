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
        .def("setKnotAt", &PyGeSplineEnt3d::setKnotAt)
        .def("controlPointAt", &PyGeSplineEnt3d::controlPointAt)
        .def("setControlPointAt", &PyGeSplineEnt3d::setControlPointAt)
        .def("cast", &PyGeSplineEnt3d::cast).staticmethod("cast")
        .def("copycast", &PyGeSplineEnt3d::copycast).staticmethod("copycast")
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
    return impObj()->continuityAtKnot(idx);
}

int PyGeSplineEnt3d::continuityAtKnot2(int idx, const AcGeTol& tol) const
{
    return impObj()->continuityAtKnot(idx, tol);
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

void PyGeSplineEnt3d::setKnotAt(int idx, double val)
{
    impObj()->setKnotAt(idx, val);
}

AcGePoint3d PyGeSplineEnt3d::controlPointAt(int idx) const
{
    return impObj()->controlPointAt(idx);
}

void PyGeSplineEnt3d::setControlPointAt(int idx, const AcGePoint3d& pnt)
{
    impObj()->setControlPointAt(idx, pnt);
}

PyGeSplineEnt3d PyGeSplineEnt3d::cast(const PyGeEntity3d& src)
{
    if (!src.impObj()->isKindOf(AcGe::EntityId::kSplineEnt3d))
        PyThrowBadEs(Acad::eNotThatKindOfClass);
    return PyGeEntity3dCast<PyGeSplineEnt3d>(src);
}

PyGeSplineEnt3d PyGeSplineEnt3d::copycast(const PyGeEntity3d& src)
{
    if (!src.impObj()->isKindOf(AcGe::EntityId::kSplineEnt3d))
        PyThrowBadEs(Acad::eNotThatKindOfClass);
    return PyGeSplineEnt3d(src.impObj()->copy());
}

std::string PyGeSplineEnt3d::className()
{
    return "AcGeSplineEnt3d";
}

AcGeSplineEnt3d* PyGeSplineEnt3d::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_imp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcGeSplineEnt3d*>(m_imp.get());
}

//-----------------------------------------------------------------------------------------
//AcGeCubicSplineCurve3d wrapper
void makePyGeCubicSplineCurve3dWrapper()
{
    class_<PyGeCubicSplineCurve3d, bases<PyGeSplineEnt3d>>("CubicSplineCurve3d")
        .def("cast", &PyGeCubicSplineCurve3d::cast).staticmethod("cast")
        .def("copycast", &PyGeCubicSplineCurve3d::copycast).staticmethod("copycast")
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

PyGeCubicSplineCurve3d PyGeCubicSplineCurve3d::cast(const PyGeEntity3d& src)
{
    if (!src.impObj()->isKindOf(AcGe::EntityId::kCubicSplineCurve3d))
        PyThrowBadEs(Acad::eNotThatKindOfClass);
    return PyGeEntity3dCast<PyGeCubicSplineCurve3d>(src);
}

PyGeCubicSplineCurve3d PyGeCubicSplineCurve3d::copycast(const PyGeEntity3d& src)
{
    if (!src.impObj()->isKindOf(AcGe::EntityId::kCubicSplineCurve3d))
        PyThrowBadEs(Acad::eNotThatKindOfClass);
    return PyGeCubicSplineCurve3d(src.impObj()->copy());
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
void makePyGeNurbCurve3dWrapper()
{
    class_<PyGeNurbCurve3d, bases<PyGeSplineEnt3d>>("NurbCurve3d")
        .def("cast", &PyGeNurbCurve3d::cast).staticmethod("cast")
        .def("copycast", &PyGeNurbCurve3d::copycast).staticmethod("copycast")
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

PyGeNurbCurve3d PyGeNurbCurve3d::cast(const PyGeEntity3d& src)
{
    if (!src.impObj()->isKindOf(AcGe::EntityId::kNurbCurve3d))
        PyThrowBadEs(Acad::eNotThatKindOfClass);
    return PyGeEntity3dCast<PyGeNurbCurve3d>(src);
}

PyGeNurbCurve3d PyGeNurbCurve3d::copycast(const PyGeEntity3d& src)
{
    if (!src.impObj()->isKindOf(AcGe::EntityId::kNurbCurve3d))
        PyThrowBadEs(Acad::eNotThatKindOfClass);
    return PyGeNurbCurve3d(src.impObj()->copy());
}

std::string PyGeNurbCurve3d::className()
{
    return "AcGeNurbCurve3d";
}

AcGeNurbCurve3d* PyGeNurbCurve3d::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_imp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcGeNurbCurve3d*>(m_imp.get());
}

//-----------------------------------------------------------------------------------------
//AcGeNurbCurve3d  wrapper
void makePyGePolyline3dWrapper()
{
    class_<PyGePolyline3d, bases<PyGeSplineEnt3d>>("Polyline3d")
        .def(init<>())
        .def(init<const boost::python::list&>())
        .def(init<const PyGeKnotVector&, const boost::python::list&>())
        .def(init<const PyGeCurve3d&, double>())
        .def("numFitPoints", &PyGePolyline3d::numFitPoints)
        .def("fitPointAt", &PyGePolyline3d::fitPointAt)
        .def("setFitPointAt", &PyGePolyline3d::setFitPointAt)
        .def("cast", &PyGePolyline3d::cast).staticmethod("cast")
        .def("copycast", &PyGePolyline3d::copycast).staticmethod("copycast")
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

PyGePolyline3d::PyGePolyline3d(const PyGeCurve3d& crv, double apprEps)
    : PyGeSplineEnt3d(new AcGePolyline3d(*crv.impObj(), apprEps))
{
}

int PyGePolyline3d::numFitPoints() const
{
    return impObj()->numFitPoints();
}

AcGePoint3d PyGePolyline3d::fitPointAt(int idx) const
{
    return impObj()->fitPointAt(idx);
}

void PyGePolyline3d::setFitPointAt(int idx, const AcGePoint3d& point)
{
    impObj()->setFitPointAt(idx, point);
}

PyGePolyline3d PyGePolyline3d::cast(const PyGeEntity3d& src)
{
    if (!src.impObj()->isKindOf(AcGe::EntityId::kPolyline3d))
        PyThrowBadEs(Acad::eNotThatKindOfClass);
    return PyGeEntity3dCast<PyGePolyline3d>(src);
}

PyGePolyline3d PyGePolyline3d::copycast(const PyGeEntity3d& src)
{
    if (!src.impObj()->isKindOf(AcGe::EntityId::kPolyline3d))
        PyThrowBadEs(Acad::eNotThatKindOfClass);
    return PyGePolyline3d(src.impObj()->copy());
}

std::string PyGePolyline3d::className()
{
    return "AcGePolyline3d";
}

AcGePolyline3d* PyGePolyline3d::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_imp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcGePolyline3d*>(m_imp.get());
}
