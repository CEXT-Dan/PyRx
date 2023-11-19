#include "stdafx.h"
#include "PyGeSplineEnt3d.h"
#include "PyGeKnotVector.h"
#include "PyGeLinearEnt3d.h"

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

PyGeNurbCurve3d::PyGeNurbCurve3d(const AcGeNurbCurve3d& src)
    : PyGeSplineEnt3d(new AcGeNurbCurve3d(src))
{
}

PyGeNurbCurve3d::PyGeNurbCurve3d(int degree, const PyGeKnotVector& knots, const boost::python::list& cntrlPnts, Adesk::Boolean isPeriodic)
    : PyGeSplineEnt3d(new AcGeNurbCurve3d(degree, knots.m_imp, PyListToPoint3dArray(cntrlPnts), isPeriodic))
{
}

PyGeNurbCurve3d::PyGeNurbCurve3d(int degree, const PyGePolyline3d& fitPolyline, Adesk::Boolean isPeriodic)
    : PyGeSplineEnt3d(new AcGeNurbCurve3d(degree, *fitPolyline.impObj(), isPeriodic))
{
}

PyGeNurbCurve3d::PyGeNurbCurve3d(const boost::python::list& fitPoints, const AcGeVector3d& startTangent, const AcGeVector3d& endTangent,
    Adesk::Boolean startTangentDefined, Adesk::Boolean endTangentDefined, const AcGeTol& fitTolerance)
    : PyGeSplineEnt3d(new AcGeNurbCurve3d(PyListToPoint3dArray(fitPoints), startTangent, endTangent, endTangentDefined, endTangentDefined, fitTolerance))
{
}

PyGeNurbCurve3d::PyGeNurbCurve3d(const boost::python::list& fitPoints, const AcGeVector3d& startTangent, const AcGeVector3d& endTangent,
    Adesk::Boolean startTangentDefined, Adesk::Boolean endTangentDefined, AcGe::KnotParameterization knotParam, const AcGeTol& fitTolerance)
    : PyGeSplineEnt3d(new AcGeNurbCurve3d(PyListToPoint3dArray(fitPoints), startTangent, endTangent, endTangentDefined, endTangentDefined, knotParam, fitTolerance))
{
}

PyGeNurbCurve3d::PyGeNurbCurve3d(const boost::python::list& fitPoints, const AcGeTol& fitTolerance)
    : PyGeSplineEnt3d(new AcGeNurbCurve3d(PyListToPoint3dArray(fitPoints), fitTolerance))
{
}

PyGeNurbCurve3d::PyGeNurbCurve3d(const boost::python::list& fitPoints, const boost::python::list& fitTangents, const AcGeTol& fitTolerance, Adesk::Boolean isPeriodic)
    : PyGeSplineEnt3d(new AcGeNurbCurve3d(PyListToPoint3dArray(fitPoints), PyListToVector3dArray(fitPoints), fitTolerance, isPeriodic))
{
}

PyGeNurbCurve3d::PyGeNurbCurve3d(const PyGeCurve3d& curve, double epsilon)
    : PyGeSplineEnt3d(new AcGeNurbCurve3d(*curve.impObj(), epsilon))
{
}

PyGeNurbCurve3d::PyGeNurbCurve3d(const PyGeEllipArc3d& ellipse)
    : PyGeSplineEnt3d(new AcGeNurbCurve3d(*ellipse.impObj()))
{
}

PyGeNurbCurve3d::PyGeNurbCurve3d(const PyGeLineSeg3d& linSeg)
    : PyGeSplineEnt3d(new AcGeNurbCurve3d(*linSeg.impObj()))
{
}

int PyGeNurbCurve3d::numFitPoints() const
{
    return impObj()->numFitPoints();
}

boost::python::tuple PyGeNurbCurve3d::getFitPointAt(int index) const
{
    AcGePoint3d point;
    auto res = impObj()->getFitPointAt(index, point);
    return boost::python::make_tuple(res, point);
}

boost::python::tuple PyGeNurbCurve3d::getFitTolerance() const
{
    AcGeTol fitTolerance;
    auto res = impObj()->getFitTolerance(fitTolerance);
    return boost::python::make_tuple(res, fitTolerance);
}

boost::python::tuple PyGeNurbCurve3d::getFitTangents() const
{
    AcGeVector3d startTangent;
    AcGeVector3d endTangent;
    Adesk::Boolean startTangentDefined;
    Adesk::Boolean endTangentDefine;
    auto res = impObj()->getFitTangents(startTangent, endTangent, startTangentDefined, endTangentDefine);
    return boost::python::make_tuple(res, startTangent, endTangent, startTangentDefined, endTangentDefine);
}

boost::python::tuple PyGeNurbCurve3d::getFitData() const
{
    AcGePoint3dArray fitPoints;
    AcGeTol fitTolerance;
    Adesk::Boolean tangentsExist;
    AcGeVector3d startTangent;
    AcGeVector3d endTangent;
    KnotParameterization knotParam;
    auto res = impObj()->getFitData(fitPoints, fitTolerance, tangentsExist, startTangent, endTangent, knotParam);
    return boost::python::make_tuple(res, Point3dArrayToPyList(fitPoints), fitTolerance, tangentsExist, startTangent, endTangent, knotParam);
}

boost::python::tuple PyGeNurbCurve3d::getDefinitionData() const
{
    int degree;
    Adesk::Boolean rational;
    Adesk::Boolean periodic;
    AcGeKnotVector knots;
    AcGePoint3dArray controlPoints;
    AcGeDoubleArray weights;
    impObj()->getDefinitionData(degree, rational, periodic, knots, controlPoints, weights);
    return boost::python::make_tuple(degree, rational, periodic, PyGeKnotVector(knots), Point3dArrayToPyList(controlPoints), DoubleArrayToPyList(weights));
}

int PyGeNurbCurve3d::numWeights() const
{
    return impObj()->numWeights();
}

double PyGeNurbCurve3d::weightAt(int idx) const
{
    return impObj()->weightAt(idx);
}

Adesk::Boolean PyGeNurbCurve3d::evalMode() const
{
    return impObj()->evalMode();
}

boost::python::tuple PyGeNurbCurve3d::getParamsOfC1Discontinuity(const AcGeTol& tol)
{
    AcGeDoubleArray params;
    auto res = impObj()->getParamsOfC1Discontinuity(params, tol);
    return boost::python::make_tuple(res, DoubleArrayToPyList(params));
}

boost::python::tuple PyGeNurbCurve3d::getParamsOfG1Discontinuity(const AcGeTol& tol)
{
    AcGeDoubleArray params;
    auto res = impObj()->getParamsOfG1Discontinuity(params, tol);
    return boost::python::make_tuple(res, DoubleArrayToPyList(params));
}

Adesk::Boolean PyGeNurbCurve3d::setFitPointAt(int index, const AcGePoint3d& point)
{
    return impObj()->setFitPointAt(index, point);
}

Adesk::Boolean PyGeNurbCurve3d::addFitPointAt(int index, const AcGePoint3d& point)
{
    return impObj()->addFitPointAt(index, point);
}

Adesk::Boolean PyGeNurbCurve3d::deleteFitPointAt(int index)
{
    return impObj()->deleteFitPointAt(index);
}

Adesk::Boolean PyGeNurbCurve3d::setFitTolerance(const AcGeTol& fitTol)
{
    return impObj()->setFitTolerance(fitTol);
}

Adesk::Boolean PyGeNurbCurve3d::setFitTangents(const AcGeVector3d& startTangent, const AcGeVector3d& endTangent)
{
    return impObj()->setFitTangents(startTangent, endTangent);
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
