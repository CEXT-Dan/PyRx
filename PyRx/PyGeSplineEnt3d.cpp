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
        .def(init<>())
        .def(init<int, const PyGeKnotVector&, const boost::python::list&, Adesk::Boolean>())
        .def(init<int, const PyGePolyline3d&, Adesk::Boolean>())
        .def(init<const boost::python::list&, const AcGeVector3d&, const AcGeVector3d&, Adesk::Boolean, Adesk::Boolean, const AcGeTol&>())
        .def(init<const boost::python::list&, const AcGeVector3d&, const AcGeVector3d&, Adesk::Boolean, Adesk::Boolean, AcGe::KnotParameterization, const AcGeTol&>())
        .def(init<const boost::python::list&, const AcGeTol&>())
        .def(init<const boost::python::list&, const boost::python::list&, const AcGeTol&, Adesk::Boolean>())
        .def(init<const PyGeCurve3d&, double>())
        .def(init<const PyGeEllipArc3d&>())
        .def(init<const PyGeLineSeg3d&>())
        .def("numFitPoints", &PyGeNurbCurve3d::numFitPoints)
        .def("getFitPointAt", &PyGeNurbCurve3d::getFitPointAt)
        .def("getFitTolerance", &PyGeNurbCurve3d::getFitTolerance)
        .def("getFitTangents", &PyGeNurbCurve3d::getFitTangents)
        .def("getFitData", &PyGeNurbCurve3d::getFitData)
        .def("getDefinitionData", &PyGeNurbCurve3d::getDefinitionData)
        .def("numWeights", &PyGeNurbCurve3d::numWeights)
        .def("weightAt", &PyGeNurbCurve3d::weightAt)
        .def("evalMode", &PyGeNurbCurve3d::evalMode)
        .def("getParamsOfC1Discontinuity", &PyGeNurbCurve3d::getParamsOfC1Discontinuity)
        .def("getParamsOfG1Discontinuity", &PyGeNurbCurve3d::getParamsOfG1Discontinuity)
        .def("setFitPointAt", &PyGeNurbCurve3d::setFitPointAt)
        .def("addFitPointAt", &PyGeNurbCurve3d::addFitPointAt)
        .def("deleteFitPointAt", &PyGeNurbCurve3d::deleteFitPointAt)
        .def("setFitTolerance", &PyGeNurbCurve3d::setFitTolerance)
        .def("setFitTangents", &PyGeNurbCurve3d::setFitTangents1)
        .def("setFitTangents", &PyGeNurbCurve3d::setFitTangents2)
        .def("setFitKnotParameterization", &PyGeNurbCurve3d::setFitKnotParameterization)
        .def("setFitData", &PyGeNurbCurve3d::setFitData1)
        .def("setFitData", &PyGeNurbCurve3d::setFitData2)
        .def("setFitData", &PyGeNurbCurve3d::setFitData3)
        .def("setFitData", &PyGeNurbCurve3d::setFitData4)
        .def("purgeFitData", &PyGeNurbCurve3d::purgeFitData)
        .def("buildFitData", &PyGeNurbCurve3d::buildFitData1)
        .def("buildFitData", &PyGeNurbCurve3d::buildFitData2)
        .def("addKnot", &PyGeNurbCurve3d::addKnot)
        .def("insertKnot", &PyGeNurbCurve3d::insertKnot)
        .def("setWeightAt", &PyGeNurbCurve3d::setWeightAt)
        .def("setEvalMode", &PyGeNurbCurve3d::setEvalMode)
        .def("joinWith", &PyGeNurbCurve3d::joinWith)
        .def("hardTrimByParams", &PyGeNurbCurve3d::hardTrimByParams)
        .def("makeRational", &PyGeNurbCurve3d::makeRational)
        .def("makeClosed", &PyGeNurbCurve3d::makeClosed)
        .def("makePeriodic", &PyGeNurbCurve3d::makePeriodic)
        .def("makeNonPeriodic", &PyGeNurbCurve3d::makeNonPeriodic)
        .def("makeOpen", &PyGeNurbCurve3d::makeOpen)
        .def("elevateDegree", &PyGeNurbCurve3d::elevateDegree)
        .def("addControlPointAt", &PyGeNurbCurve3d::addControlPointAt)
        .def("deleteControlPointAt", &PyGeNurbCurve3d::deleteControlPointAt)
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

Adesk::Boolean PyGeNurbCurve3d::setFitTangents1(const AcGeVector3d& startTangent, const AcGeVector3d& endTangent)
{
    return impObj()->setFitTangents(startTangent, endTangent);
}

Adesk::Boolean PyGeNurbCurve3d::setFitTangents2(const AcGeVector3d& startTangent,
    const AcGeVector3d& endTangent, Adesk::Boolean startTangentDefined, Adesk::Boolean endTangentDefined)
{
    return impObj()->setFitTangents(startTangent, endTangent, startTangentDefined, endTangentDefined);
}

Adesk::Boolean PyGeNurbCurve3d::setFitKnotParameterization(KnotParameterization knotParam)
{
    return impObj()->setFitKnotParameterization(knotParam);
}

void PyGeNurbCurve3d::setFitData1(const boost::python::list& fitPoints, const AcGeVector3d& startTangent,
    const AcGeVector3d& endTangent, const AcGeTol& fitTol)
{
    impObj()->setFitData(PyListToPoint3dArray(fitPoints), startTangent, endTangent, fitTol);
}

void PyGeNurbCurve3d::setFitData2(const boost::python::list& fitPoints, const AcGeVector3d& startTangent,
    const AcGeVector3d& endTangent, KnotParameterization knotParam, const AcGeTol& fitTol)
{
    impObj()->setFitData(PyListToPoint3dArray(fitPoints), startTangent, endTangent, knotParam, fitTol);
}

void PyGeNurbCurve3d::setFitData3(const PyGeKnotVector& fitKnots, const boost::python::list& fitPoints, const AcGeVector3d& startTangent,
    const AcGeVector3d& endTangent, const AcGeTol& fitTol, Adesk::Boolean isPeriodic)
{
    impObj()->setFitData(fitKnots.m_imp, PyListToPoint3dArray(fitPoints), startTangent, endTangent, fitTol, isPeriodic);
}

void PyGeNurbCurve3d::setFitData4(int degree, const boost::python::list& fitPoints, const AcGeTol& fitTol)
{
    impObj()->setFitData(degree, PyListToPoint3dArray(fitPoints), fitTol);
}

Adesk::Boolean PyGeNurbCurve3d::purgeFitData()
{
    return impObj()->purgeFitData();
}

Adesk::Boolean PyGeNurbCurve3d::buildFitData1()
{
    return impObj()->buildFitData();
}

Adesk::Boolean PyGeNurbCurve3d::buildFitData2(KnotParameterization kp)
{
    return impObj()->buildFitData(kp);
}

void PyGeNurbCurve3d::addKnot(double newKnot)
{
    impObj()->addKnot(newKnot);
}

void PyGeNurbCurve3d::insertKnot(double newKnot)
{
    impObj()->insertKnot(newKnot);
}

void PyGeNurbCurve3d::setWeightAt(int idx, double val)
{
    impObj()->setWeightAt(idx, val);
}

void PyGeNurbCurve3d::setEvalMode(Adesk::Boolean evalMode)
{
    impObj()->setEvalMode(evalMode);
}

void PyGeNurbCurve3d::joinWith(const PyGeNurbCurve3d& curve)
{
    impObj()->joinWith(*curve.impObj());
}

void PyGeNurbCurve3d::hardTrimByParams(double newStartParam, double newEndParam)
{
    impObj()->hardTrimByParams(newStartParam, newEndParam);
}

void PyGeNurbCurve3d::makeRational(double weight)
{
    impObj()->makeRational(weight);
}

void PyGeNurbCurve3d::makeClosed()
{
    impObj()->makeClosed();
}

void PyGeNurbCurve3d::makePeriodic()
{
    impObj()->makePeriodic();
}

void PyGeNurbCurve3d::makeNonPeriodic()
{
    impObj()->makeNonPeriodic();
}

void PyGeNurbCurve3d::makeOpen()
{
    impObj()->makeOpen();
}

void PyGeNurbCurve3d::elevateDegree(int plusDegree)
{
    impObj()->elevateDegree(plusDegree);
}

Adesk::Boolean PyGeNurbCurve3d::addControlPointAt(double newKnot, const AcGePoint3d& point, double weight)
{
    return impObj()->addControlPointAt(newKnot, point, weight);
}

Adesk::Boolean PyGeNurbCurve3d::deleteControlPointAt(int index)
{
   return impObj()->deleteControlPointAt(index);
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
