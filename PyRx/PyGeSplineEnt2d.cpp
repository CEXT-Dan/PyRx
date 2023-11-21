#include "stdafx.h"
#include "PyGeSplineEnt2d.h"
#include "PyGeKnotVector.h"
#include "PyGeLinearEnt2d.h"

using namespace boost::python;
//-----------------------------------------------------------------------------------------
//PyGeSplineEnt2d wrapper
void makePyGeSplineEnt2dWrapper()
{
#if !defined(_BRXTARGET) || (_BRXTARGET > 240)
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
        .def("setKnotAt", &PyGeSplineEnt2d::setKnotAt)
        .def("controlPointAt", &PyGeSplineEnt2d::controlPointAt)
        .def("setControlPointAt", &PyGeSplineEnt2d::setControlPointAt)
        .def("cast", &PyGeSplineEnt2d::cast).staticmethod("cast")
        .def("copycast", &PyGeSplineEnt2d::copycast).staticmethod("copycast")
        .def("className", &PyGeSplineEnt2d::className).staticmethod("className")
        ;
#endif
}


#if !defined(_BRXTARGET) || (_BRXTARGET > 240)
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
    return PyGeKnotVector(impObj()->knots());
}

int PyGeSplineEnt2d::numControlPoints() const
{
    return impObj()->numControlPoints();
}

int PyGeSplineEnt2d::continuityAtKnot1(int idx) const
{
    return impObj()->continuityAtKnot(idx);
}

int PyGeSplineEnt2d::continuityAtKnot2(int idx, const AcGeTol& tol) const
{
    return impObj()->continuityAtKnot(idx, tol);
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

void PyGeSplineEnt2d::setKnotAt(int idx, double val)
{
    impObj()->setKnotAt(idx, val);
}

AcGePoint2d PyGeSplineEnt2d::controlPointAt(int idx) const
{
    return impObj()->controlPointAt(idx);
}

void PyGeSplineEnt2d::setControlPointAt(int idx, const AcGePoint2d& pnt)
{
    impObj()->setControlPointAt(idx, pnt);
}

PyGeSplineEnt2d PyGeSplineEnt2d::cast(const PyGeEntity2d& src)
{
    if (!src.impObj()->isKindOf(AcGe::EntityId::kSplineEnt2d))
        PyThrowBadEs(Acad::eNotThatKindOfClass);
    return PyGeEntity2dCast<PyGeSplineEnt2d>(src);
}

PyGeSplineEnt2d PyGeSplineEnt2d::copycast(const PyGeEntity2d& src)
{
    if (!src.impObj()->isKindOf(AcGe::EntityId::kSplineEnt2d))
        PyThrowBadEs(Acad::eNotThatKindOfClass);
    return PyGeSplineEnt2d(src.impObj()->copy());
}

std::string PyGeSplineEnt2d::className()
{
    return "AcGeSplineEnt2d";
}

AcGeSplineEnt2d* PyGeSplineEnt2d::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_imp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcGeSplineEnt2d*>(m_imp.get());
}
#endif

//-----------------------------------------------------------------------------------------
//AcGeCubicSplineCurve2d wrapper
void makePyGeCubicSplineCurve2dWrapper()
{
#if !defined(_BRXTARGET) || (_BRXTARGET > 240)
    class_<PyGeCubicSplineCurve2d, bases<PyGeSplineEnt2d>>("CubicSplineCurve2d")
        .def(init<>())
        .def(init<const PyGeCurve2d&, double>())
        .def(init<const boost::python::list&, const AcGeTol&>())
        .def(init<const boost::python::list&, const AcGeVector2d&, const AcGeVector2d&, const AcGeTol&>())
        .def(init<const PyGeKnotVector&, const boost::python::list&, const boost::python::list&, Adesk::Boolean>())
        .def("numFitPoints", &PyGeCubicSplineCurve2d::numFitPoints)
        .def("fitPointAt", &PyGeCubicSplineCurve2d::fitPointAt)
        .def("setFitPointAt", &PyGeCubicSplineCurve2d::setFitPointAt)
        .def("firstDerivAt", &PyGeCubicSplineCurve2d::firstDerivAt)
        .def("setFirstDerivAt", &PyGeCubicSplineCurve2d::setFirstDerivAt)
        .def("cast", &PyGeCubicSplineCurve2d::cast).staticmethod("cast")
        .def("copycast", &PyGeCubicSplineCurve2d::copycast).staticmethod("copycast")
        .def("className", &PyGeCubicSplineCurve2d::className).staticmethod("className")
        ;
#endif
}

#if !defined(_BRXTARGET) || (_BRXTARGET > 240)
PyGeCubicSplineCurve2d::PyGeCubicSplineCurve2d()
    : PyGeSplineEnt2d(new AcGeCubicSplineCurve2d())
{
}

PyGeCubicSplineCurve2d::PyGeCubicSplineCurve2d(const PyGeCurve2d& curve, double epsilon)
    : PyGeSplineEnt2d(new AcGeCubicSplineCurve2d(*curve.impObj(), epsilon))
{
}

PyGeCubicSplineCurve2d::PyGeCubicSplineCurve2d(const boost::python::list& fitPnts, const AcGeTol& tol)
    : PyGeSplineEnt2d(new AcGeCubicSplineCurve2d(PyListToPoint2dArray(fitPnts), tol))
{
}

PyGeCubicSplineCurve2d::PyGeCubicSplineCurve2d(const boost::python::list& fitPnts, const AcGeVector2d& startDeriv, const AcGeVector2d& endDeriv, const AcGeTol& tol)
    : PyGeSplineEnt2d(new AcGeCubicSplineCurve2d(PyListToPoint2dArray(fitPnts), startDeriv, endDeriv, tol))
{
}

PyGeCubicSplineCurve2d::PyGeCubicSplineCurve2d(const PyGeKnotVector& knots, const boost::python::list& fitPnts, const boost::python::list& firstDerivs, Adesk::Boolean isPeriodic)
    : PyGeSplineEnt2d(new AcGeCubicSplineCurve2d(knots.m_imp, PyListToPoint2dArray(fitPnts), PyListToVector2dArray(firstDerivs), isPeriodic))
{
}

int PyGeCubicSplineCurve2d::numFitPoints() const
{
    return impObj()->numFitPoints();
}

AcGePoint2d PyGeCubicSplineCurve2d::fitPointAt(int idx) const
{
    return impObj()->fitPointAt(idx);
}

void PyGeCubicSplineCurve2d::setFitPointAt(int idx, const AcGePoint2d& point)
{
    impObj()->setFitPointAt(idx, point);
}

AcGeVector2d PyGeCubicSplineCurve2d::firstDerivAt(int idx) const
{
    return impObj()->firstDerivAt(idx);
}

void PyGeCubicSplineCurve2d::setFirstDerivAt(int idx, const AcGeVector2d& deriv)
{
    impObj()->setFirstDerivAt(idx, deriv);
}

PyGeCubicSplineCurve2d::PyGeCubicSplineCurve2d(AcGeEntity2d* pEnt)
    : PyGeSplineEnt2d(pEnt)
{
}

PyGeCubicSplineCurve2d PyGeCubicSplineCurve2d::copycast(const PyGeEntity2d& src)
{
    if (!src.impObj()->isKindOf(AcGe::EntityId::kCubicSplineCurve2d))
        PyThrowBadEs(Acad::eInvalidInput);
    return PyGeCubicSplineCurve2d(src.impObj()->copy());
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
#endif
//-----------------------------------------------------------------------------------------
//AcGeNurbCurve2d  wrapper
void makePyGeNurbCurve2dWrapper()
{
#if !defined(_BRXTARGET) || (_BRXTARGET > 240)
   class_<PyGeNurbCurve2d, bases<PyGeSplineEnt2d>>("NurbCurve2d")
        .def(init<>())
        .def(init<const PyGeEllipArc2d&>())
        .def(init<const PyGeLineSeg2d&>())
        .def(init<const PyGeCurve2d&, double>())
        .def(init<const boost::python::list&, const AcGeTol&>())
        .def(init<int, const PyGePolyline2d&, Adesk::Boolean>())
        .def(init<int, const PyGeKnotVector&, const boost::python::list&, Adesk::Boolean>())
        .def(init<const boost::python::list&, const boost::python::list&, const AcGeTol&, Adesk::Boolean>())
        .def(init<const boost::python::list&, const AcGeVector2d&, const AcGeVector2d&, Adesk::Boolean, Adesk::Boolean, const AcGeTol&>())
        .def(init<const boost::python::list&, const AcGeVector2d&, const AcGeVector2d&, Adesk::Boolean, Adesk::Boolean, AcGe::KnotParameterization, const AcGeTol&>())
        .def("numFitPoints", &PyGeNurbCurve2d::numFitPoints)
        .def("getFitPointAt", &PyGeNurbCurve2d::getFitPointAt)
        .def("getFitTolerance", &PyGeNurbCurve2d::getFitTolerance)
        .def("getFitTangents", &PyGeNurbCurve2d::getFitTangents)
        .def("getFitData", &PyGeNurbCurve2d::getFitData)
        .def("getDefinitionData", &PyGeNurbCurve2d::getDefinitionData)
        .def("numWeights", &PyGeNurbCurve2d::numWeights)
        .def("weightAt", &PyGeNurbCurve2d::weightAt)
        .def("evalMode", &PyGeNurbCurve2d::evalMode)
        .def("getParamsOfC1Discontinuity", &PyGeNurbCurve2d::getParamsOfC1Discontinuity)
        .def("getParamsOfG1Discontinuity", &PyGeNurbCurve2d::getParamsOfG1Discontinuity)
        .def("setFitPointAt", &PyGeNurbCurve2d::setFitPointAt)
        .def("addFitPointAt", &PyGeNurbCurve2d::addFitPointAt)
        .def("deleteFitPointAt", &PyGeNurbCurve2d::deleteFitPointAt)
        .def("setFitTolerance", &PyGeNurbCurve2d::setFitTolerance)
        .def("setFitTangents", &PyGeNurbCurve2d::setFitTangents)
        .def("setFitKnotParameterization", &PyGeNurbCurve2d::setFitKnotParameterization)
        .def("setFitData", &PyGeNurbCurve2d::setFitData1)
        .def("setFitData", &PyGeNurbCurve2d::setFitData2)
        .def("setFitData", &PyGeNurbCurve2d::setFitData3)
        .def("setFitData", &PyGeNurbCurve2d::setFitData4)
        .def("purgeFitData", &PyGeNurbCurve2d::purgeFitData)
        .def("buildFitData", &PyGeNurbCurve2d::buildFitData1)
        .def("buildFitData", &PyGeNurbCurve2d::buildFitData2)
        .def("addKnot", &PyGeNurbCurve2d::addKnot)
        .def("insertKnot", &PyGeNurbCurve2d::insertKnot)
        .def("setWeightAt", &PyGeNurbCurve2d::setWeightAt)
        .def("setEvalMode", &PyGeNurbCurve2d::setEvalMode)
        .def("joinWith", &PyGeNurbCurve2d::joinWith)
        .def("hardTrimByParams", &PyGeNurbCurve2d::hardTrimByParams)
        .def("makeRational", &PyGeNurbCurve2d::makeRational)
        .def("makeClosed", &PyGeNurbCurve2d::makeClosed)
        .def("makePeriodic", &PyGeNurbCurve2d::makePeriodic)
        .def("makeNonPeriodic", &PyGeNurbCurve2d::makeNonPeriodic)
        .def("makeOpen", &PyGeNurbCurve2d::makeOpen)
        .def("elevateDegree", &PyGeNurbCurve2d::elevateDegree)
        .def("addControlPointAt", &PyGeNurbCurve2d::addControlPointAt)
        .def("deleteControlPointAt", &PyGeNurbCurve2d::deleteControlPointAt)
        .def("cast", &PyGeNurbCurve2d::cast).staticmethod("cast")
        .def("copycast", &PyGeNurbCurve2d::copycast).staticmethod("copycast")
        .def("className", &PyGeNurbCurve2d::className).staticmethod("className")
        ;
#endif
}

#if !defined(_BRXTARGET) || (_BRXTARGET > 240)
PyGeNurbCurve2d::PyGeNurbCurve2d()
    : PyGeSplineEnt2d(new AcGeNurbCurve2d())
{
}

PyGeNurbCurve2d::PyGeNurbCurve2d(AcGeEntity2d* pEnt)
    : PyGeSplineEnt2d(pEnt)
{
}

PyGeNurbCurve2d::PyGeNurbCurve2d(const AcGeNurbCurve2d& src)
    : PyGeSplineEnt2d(new AcGeNurbCurve2d(src))
{
}

PyGeNurbCurve2d::PyGeNurbCurve2d(int degree, const PyGeKnotVector& knots, const boost::python::list& cntrlPnts, Adesk::Boolean isPeriodic)
    : PyGeSplineEnt2d(new AcGeNurbCurve2d(degree, knots.m_imp, PyListToPoint2dArray(cntrlPnts), isPeriodic))
{
}

PyGeNurbCurve2d::PyGeNurbCurve2d(int degree, const PyGePolyline2d& fitPolyline, Adesk::Boolean isPeriodic)
    : PyGeSplineEnt2d(new AcGeNurbCurve2d(degree, *fitPolyline.impObj(), isPeriodic))
{
}

PyGeNurbCurve2d::PyGeNurbCurve2d(const boost::python::list& fitPoints, const AcGeVector2d& startTangent, const AcGeVector2d& endTangent,
    Adesk::Boolean startTangentDefined, Adesk::Boolean endTangentDefined, const AcGeTol& fitTolerance)
    : PyGeSplineEnt2d(new AcGeNurbCurve2d(PyListToPoint2dArray(fitPoints), startTangent, endTangent, endTangentDefined, endTangentDefined, fitTolerance))
{
}

PyGeNurbCurve2d::PyGeNurbCurve2d(const boost::python::list& fitPoints, const AcGeVector2d& startTangent, const AcGeVector2d& endTangent,
    Adesk::Boolean startTangentDefined, Adesk::Boolean endTangentDefined, AcGe::KnotParameterization knotParam, const AcGeTol& fitTolerance)
    : PyGeSplineEnt2d(new AcGeNurbCurve2d(PyListToPoint2dArray(fitPoints), startTangent, endTangent, endTangentDefined, endTangentDefined, knotParam, fitTolerance))
{
}

PyGeNurbCurve2d::PyGeNurbCurve2d(const boost::python::list& fitPoints, const AcGeTol& fitTolerance)
    : PyGeSplineEnt2d(new AcGeNurbCurve2d(PyListToPoint2dArray(fitPoints), fitTolerance))
{
}

PyGeNurbCurve2d::PyGeNurbCurve2d(const boost::python::list& fitPoints, const boost::python::list& fitTangents, const AcGeTol& fitTolerance, Adesk::Boolean isPeriodic)
    : PyGeSplineEnt2d(new AcGeNurbCurve2d(PyListToPoint2dArray(fitPoints), PyListToVector2dArray(fitPoints), fitTolerance, isPeriodic))
{
}

PyGeNurbCurve2d::PyGeNurbCurve2d(const PyGeCurve2d& curve, double epsilon)
    : PyGeSplineEnt2d(new AcGeNurbCurve2d(*curve.impObj(), epsilon))
{
}

PyGeNurbCurve2d::PyGeNurbCurve2d(const PyGeEllipArc2d& ellipse)
    : PyGeSplineEnt2d(new AcGeNurbCurve2d(*ellipse.impObj()))
{
}

PyGeNurbCurve2d::PyGeNurbCurve2d(const PyGeLineSeg2d& linSeg)
    : PyGeSplineEnt2d(new AcGeNurbCurve2d(*linSeg.impObj()))
{
}

int PyGeNurbCurve2d::numFitPoints() const
{
    return impObj()->numFitPoints();
}

boost::python::tuple PyGeNurbCurve2d::getFitPointAt(int index) const
{
    AcGePoint2d point;
    auto res = impObj()->getFitPointAt(index, point);
    return boost::python::make_tuple(res, point);
}

boost::python::tuple PyGeNurbCurve2d::getFitTolerance() const
{
    AcGeTol fitTolerance;
    auto res = impObj()->getFitTolerance(fitTolerance);
    return boost::python::make_tuple(res, fitTolerance);
}

boost::python::tuple PyGeNurbCurve2d::getFitTangents() const
{
    AcGeVector2d startTangent;
    AcGeVector2d endTangent;
    auto res = impObj()->getFitTangents(startTangent, endTangent);
    return boost::python::make_tuple(res, startTangent, endTangent);
}

boost::python::tuple PyGeNurbCurve2d::getFitData() const
{
    AcGePoint2dArray fitPoints;
    AcGeTol fitTolerance;
    Adesk::Boolean tangentsExist;
    AcGeVector2d startTangent;
    AcGeVector2d endTangent;
    KnotParameterization knotParam;
    auto res = impObj()->getFitData(fitPoints, fitTolerance, tangentsExist, startTangent, endTangent, knotParam);
    return boost::python::make_tuple(res, Point2dArrayToPyList(fitPoints), fitTolerance, tangentsExist, startTangent, endTangent, knotParam);
}

boost::python::tuple PyGeNurbCurve2d::getDefinitionData() const
{
    int degree;
    Adesk::Boolean rational;
    Adesk::Boolean periodic;
    AcGeKnotVector knots;
    AcGePoint2dArray controlPoints;
    AcGeDoubleArray weights;
    impObj()->getDefinitionData(degree, rational, periodic, knots, controlPoints, weights);
    return boost::python::make_tuple(degree, rational, periodic, PyGeKnotVector(knots), Point2dArrayToPyList(controlPoints), DoubleArrayToPyList(weights));
}

int PyGeNurbCurve2d::numWeights() const
{
    return impObj()->numWeights();
}

double PyGeNurbCurve2d::weightAt(int idx) const
{
    return impObj()->weightAt(idx);
}

Adesk::Boolean PyGeNurbCurve2d::evalMode() const
{
    return impObj()->evalMode();
}

boost::python::tuple PyGeNurbCurve2d::getParamsOfC1Discontinuity(const AcGeTol& tol)
{
    AcGeDoubleArray params;
    auto res = impObj()->getParamsOfC1Discontinuity(params, tol);
    return boost::python::make_tuple(res, DoubleArrayToPyList(params));
}

boost::python::tuple PyGeNurbCurve2d::getParamsOfG1Discontinuity(const AcGeTol& tol)
{
    AcGeDoubleArray params;
    auto res = impObj()->getParamsOfG1Discontinuity(params, tol);
    return boost::python::make_tuple(res, DoubleArrayToPyList(params));
}

Adesk::Boolean PyGeNurbCurve2d::setFitPointAt(int index, const AcGePoint2d& point)
{
    return impObj()->setFitPointAt(index, point);
}

Adesk::Boolean PyGeNurbCurve2d::addFitPointAt(int index, const AcGePoint2d& point)
{
    return impObj()->addFitPointAt(index, point);
}

Adesk::Boolean PyGeNurbCurve2d::deleteFitPointAt(int index)
{
    return impObj()->deleteFitPointAt(index);
}

Adesk::Boolean PyGeNurbCurve2d::setFitTolerance(const AcGeTol& fitTol)
{
    return impObj()->setFitTolerance(fitTol);
}

Adesk::Boolean PyGeNurbCurve2d::setFitTangents(const AcGeVector2d& startTangent, const AcGeVector2d& endTangent)
{
    return impObj()->setFitTangents(startTangent, endTangent);
}

Adesk::Boolean PyGeNurbCurve2d::setFitKnotParameterization(KnotParameterization knotParam)
{
    return impObj()->setFitKnotParameterization(knotParam);
}

void PyGeNurbCurve2d::setFitData1(const boost::python::list& fitPoints, const AcGeVector2d& startTangent,
    const AcGeVector2d& endTangent, const AcGeTol& fitTol)
{
    impObj()->setFitData(PyListToPoint2dArray(fitPoints), startTangent, endTangent, fitTol);
}

void PyGeNurbCurve2d::setFitData2(const boost::python::list& fitPoints, const AcGeVector2d& startTangent,
    const AcGeVector2d& endTangent, KnotParameterization knotParam, const AcGeTol& fitTol)
{
    impObj()->setFitData(PyListToPoint2dArray(fitPoints), startTangent, endTangent, knotParam, fitTol);
}

void PyGeNurbCurve2d::setFitData3(const PyGeKnotVector& fitKnots, const boost::python::list& fitPoints, const AcGeVector2d& startTangent,
    const AcGeVector2d& endTangent, const AcGeTol& fitTol, Adesk::Boolean isPeriodic)
{
    impObj()->setFitData(fitKnots.m_imp, PyListToPoint2dArray(fitPoints), startTangent, endTangent, fitTol, isPeriodic);
}

void PyGeNurbCurve2d::setFitData4(int degree, const boost::python::list& fitPoints, const AcGeTol& fitTol)
{
    impObj()->setFitData(degree, PyListToPoint2dArray(fitPoints), fitTol);
}

Adesk::Boolean PyGeNurbCurve2d::purgeFitData()
{
    return impObj()->purgeFitData();
}

Adesk::Boolean PyGeNurbCurve2d::buildFitData1()
{
    return impObj()->buildFitData();
}

Adesk::Boolean PyGeNurbCurve2d::buildFitData2(KnotParameterization kp)
{
    return impObj()->buildFitData(kp);
}

void PyGeNurbCurve2d::addKnot(double newKnot)
{
    impObj()->addKnot(newKnot);
}

void PyGeNurbCurve2d::insertKnot(double newKnot)
{
    impObj()->insertKnot(newKnot);
}

void PyGeNurbCurve2d::setWeightAt(int idx, double val)
{
    impObj()->setWeightAt(idx, val);
}

void PyGeNurbCurve2d::setEvalMode(Adesk::Boolean evalMode)
{
    impObj()->setEvalMode(evalMode);
}

void PyGeNurbCurve2d::joinWith(const PyGeNurbCurve2d& curve)
{
    impObj()->joinWith(*curve.impObj());
}

void PyGeNurbCurve2d::hardTrimByParams(double newStartParam, double newEndParam)
{
    impObj()->hardTrimByParams(newStartParam, newEndParam);
}

void PyGeNurbCurve2d::makeRational(double weight)
{
    impObj()->makeRational(weight);
}

void PyGeNurbCurve2d::makeClosed()
{
    impObj()->makeClosed();
}

void PyGeNurbCurve2d::makePeriodic()
{
    impObj()->makePeriodic();
}

void PyGeNurbCurve2d::makeNonPeriodic()
{
    impObj()->makeNonPeriodic();
}

void PyGeNurbCurve2d::makeOpen()
{
    impObj()->makeOpen();
}

void PyGeNurbCurve2d::elevateDegree(int plusDegree)
{
    impObj()->elevateDegree(plusDegree);
}

Adesk::Boolean PyGeNurbCurve2d::addControlPointAt(double newKnot, const AcGePoint2d& point, double weight)
{
    return impObj()->addControlPointAt(newKnot, point, weight);
}

Adesk::Boolean PyGeNurbCurve2d::deleteControlPointAt(int index)
{
    return impObj()->deleteControlPointAt(index);
}

PyGeNurbCurve2d PyGeNurbCurve2d::copycast(const PyGeEntity2d& src)
{
    if (!src.impObj()->isKindOf(AcGe::EntityId::kNurbCurve2d))
        PyThrowBadEs(Acad::eInvalidInput);
    return PyGeNurbCurve2d(src.impObj()->copy());
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
#endif

//-----------------------------------------------------------------------------------------
//AcGeNurbCurve2d  wrapper
void makePyGePolyline2dWrapper()
{
#if !defined(_BRXTARGET) || (_BRXTARGET > 240)
    class_<PyGePolyline2d, bases<PyGeSplineEnt2d>>("Polyline2d")
        .def(init<>())
        .def(init<const boost::python::list&>())
        .def(init<const PyGeKnotVector&, const boost::python::list&>())
        .def(init<const PyGeCurve2d&, double>())
        .def("numFitPoints", &PyGePolyline2d::numFitPoints)
        .def("fitPointAt", &PyGePolyline2d::fitPointAt)
        .def("setFitPointAt", &PyGePolyline2d::setFitPointAt)
        .def("cast", &PyGePolyline2d::cast).staticmethod("cast")
        .def("copycast", &PyGePolyline2d::copycast).staticmethod("copycast")
        .def("className", &PyGePolyline2d::className).staticmethod("className")
        ;
#endif
}

#if !defined(_BRXTARGET) || (_BRXTARGET > 240)
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

void PyGePolyline2d::setFitPointAt(int idx, const AcGePoint2d& point)
{
    impObj()->setFitPointAt(idx, point);
}

PyGePolyline2d PyGePolyline2d::copycast(const PyGeEntity2d& src)
{
    if (!src.impObj()->isKindOf(AcGe::EntityId::kPolyline2d))
        PyThrowBadEs(Acad::eInvalidInput);
    return PyGePolyline2d(src.impObj()->copy());
}

std::string PyGePolyline2d::className()
{
    return "AcGePolyline2d";
}

AcGePolyline2d* PyGePolyline2d::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_imp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcGePolyline2d*>(m_imp.get());
}
#endif