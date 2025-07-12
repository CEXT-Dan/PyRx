#include "stdafx.h"
#include "PyGeSplineEnt2d.h"
#include "PyGeKnotVector.h"
#include "PyGeLinearEnt2d.h"

using namespace boost::python;
//-----------------------------------------------------------------------------------------
//PyGeSplineEnt2d wrapper
void makePyGeSplineEnt2dWrapper()
{
#if !defined(_BRXTARGET260)
    PyDocString DS("SplineEnt2d");
    class_<PyGeSplineEnt2d, bases<PyGeCurve2d>>("SplineEnt2d", boost::python::no_init)
        .def("isRational", &PyGeSplineEnt2d::isRational, DS.ARGS())
        .def("degree", &PyGeSplineEnt2d::degree, DS.ARGS())
        .def("order", &PyGeSplineEnt2d::order, DS.ARGS())
        .def("numKnots", &PyGeSplineEnt2d::numKnots, DS.ARGS())
        .def("knots", &PyGeSplineEnt2d::knots, DS.ARGS())
        .def("numControlPoints", &PyGeSplineEnt2d::numControlPoints, DS.ARGS())
        .def("continuityAtKnot", &PyGeSplineEnt2d::continuityAtKnot1)
        .def("continuityAtKnot", &PyGeSplineEnt2d::continuityAtKnot2, DS.ARGS({ "idx: int","tol: PyGe.Tol = ..." }))
        .def("startParam", &PyGeSplineEnt2d::startParam, DS.ARGS())
        .def("endParam", &PyGeSplineEnt2d::endParam, DS.ARGS())
        .def("startPoint", &PyGeSplineEnt2d::startPoint, DS.ARGS())
        .def("endPoint", &PyGeSplineEnt2d::endPoint, DS.ARGS())
        .def("hasFitData", &PyGeSplineEnt2d::hasFitData, DS.ARGS())
        .def("knotAt", &PyGeSplineEnt2d::knotAt, DS.ARGS({ "idx: int" }))
        .def("setKnotAt", &PyGeSplineEnt2d::setKnotAt, DS.ARGS({ "idx: int","val: float" }))
        .def("controlPointAt", &PyGeSplineEnt2d::controlPointAt, DS.ARGS({ "idx: int" }))
        .def("setControlPointAt", &PyGeSplineEnt2d::setControlPointAt, DS.ARGS({ "idx: int","val: PyGe.Point2d" }))
        .def("cast", &PyGeSplineEnt2d::cast, DS.SARGS({ "otherObject: PyGe.Entity2d" })).staticmethod("cast")
        .def("copycast", &PyGeSplineEnt2d::copycast, DS.SARGS({ "otherObject: PyGe.Entity2d" })).staticmethod("copycast")
        .def("className", &PyGeSplineEnt2d::className, DS.SARGS()).staticmethod("className")
        ;
#endif
}

#if !defined(_BRXTARGET260)
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

void PyGeSplineEnt2d::setKnotAt(int idx, double val) const
{
    impObj()->setKnotAt(idx, val);
}

AcGePoint2d PyGeSplineEnt2d::controlPointAt(int idx) const
{
    return impObj()->controlPointAt(idx);
}

void PyGeSplineEnt2d::setControlPointAt(int idx, const AcGePoint2d& pnt) const
{
    impObj()->setControlPointAt(idx, pnt);
}

PyGeSplineEnt2d PyGeSplineEnt2d::cast(const PyGeEntity2d& src)
{
    return PyGeEntity2dCast<PyGeSplineEnt2d, AcGeSplineEnt2d>(src);
}

PyGeSplineEnt2d PyGeSplineEnt2d::copycast(const PyGeEntity2d& src)
{
    return PyGeSplineEnt2d(static_cast<AcGeSplineEnt2d*>(src.impObj()->copy()));
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

#if !defined(_BRXTARGET260)
    constexpr const std::string_view ctor = "Overloads:\n"
        "- None: Any\n"
        "- curve: PyGe.Curve2d, epsilon: float\n"
        "- fitPnts: list[PyGe.Point2d], tol: PyGe.Tol\n"
        "- fitPnts: list[PyGe.Point2d], startDeriv: PyGe.Vector2d, endDeriv: PyGe.Vector2d,tol: PyGe.Tol\n"
        "- knots: PyGe.KnotVector, fitPnts: list[PyGe.Point2d], firstDerivs: list[PyGe.Point2d], isPeriodic: bool\n";

    PyDocString DS("CubicSplineCurve2d");
    class_<PyGeCubicSplineCurve2d, bases<PyGeSplineEnt2d>>("CubicSplineCurve2d")
        .def(init<>())
        .def(init<const PyGeCurve2d&, double>())
        .def(init<const boost::python::list&, const AcGeTol&>())
        .def(init<const boost::python::list&, const AcGeVector2d&, const AcGeVector2d&, const AcGeTol&>())
        .def(init<const PyGeKnotVector&, const boost::python::list&, const boost::python::list&, Adesk::Boolean>(DS.CTOR(ctor, 11799)))
        .def("numFitPoints", &PyGeCubicSplineCurve2d::numFitPoints, DS.ARGS())
        .def("fitPointAt", &PyGeCubicSplineCurve2d::fitPointAt, DS.ARGS({ "val: int" }))
        .def("setFitPointAt", &PyGeCubicSplineCurve2d::setFitPointAt, DS.ARGS({ "val: int","pt: PyGe.Point2d" }))
        .def("firstDerivAt", &PyGeCubicSplineCurve2d::firstDerivAt, DS.ARGS({ "val: int" }))
        .def("setFirstDerivAt", &PyGeCubicSplineCurve2d::setFirstDerivAt, DS.ARGS({ "val: int","pt: PyGe.Vector2d" }))
        .def("cast", &PyGeCubicSplineCurve2d::cast, DS.SARGS({ "otherObject: PyGe.Entity2d" })).staticmethod("cast")
        .def("copycast", &PyGeCubicSplineCurve2d::copycast, DS.SARGS({ "otherObject: PyGe.Entity2d" })).staticmethod("copycast")
        .def("className", &PyGeCubicSplineCurve2d::className, DS.SARGS()).staticmethod("className")
        ;
#endif
}

#if !defined(_BRXTARGET260)
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

void PyGeCubicSplineCurve2d::setFitPointAt(int idx, const AcGePoint2d& point) const
{
    impObj()->setFitPointAt(idx, point);
}

AcGeVector2d PyGeCubicSplineCurve2d::firstDerivAt(int idx) const
{
    return impObj()->firstDerivAt(idx);
}

void PyGeCubicSplineCurve2d::setFirstDerivAt(int idx, const AcGeVector2d& deriv) const
{
    impObj()->setFirstDerivAt(idx, deriv);
}


PyGeCubicSplineCurve2d::PyGeCubicSplineCurve2d(AcGeEntity2d* pEnt)
    : PyGeSplineEnt2d(pEnt)
{
}

PyGeCubicSplineCurve2d PyGeCubicSplineCurve2d::cast(const PyGeEntity2d& src)
{
    return PyGeEntity2dCast<PyGeCubicSplineCurve2d, AcGeCubicSplineCurve2d>(src);
}

PyGeCubicSplineCurve2d PyGeCubicSplineCurve2d::copycast(const PyGeEntity2d& src)
{
    return PyGeCubicSplineCurve2d(static_cast<AcGeCubicSplineCurve2d*>(src.impObj()->copy()));
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
#if !defined(_BRXTARGET260)
    constexpr const std::string_view ctor = "Overloads:\n"
        "- None: Any\n"
        "- src: PyGe.Curve2d\n"
        "- src: PyGe.LineSeg2d\n"
        "- src: PyGe.EllipArc2d\n"
        "- curve: PyGe.Curve2d, epsilon: float\n"
        "- fitPnts: list[PyGe.Point2d], tol: PyGe.Tol\n"
        "- degree: int, fitPolyline: PyGe.Polyline2d, isPeriodic: bool\n"
        "- degree: int, knots: PyGe.KnotVector, cntrlPnts: list[PyGe.Point2d], isPeriodic: bool\n"
        "- fitPoints: list[PyGe.Point2d], fitTangents: list[PyGe.Vector2d], fitTolerance: PyGe.Tol,isPeriodic: bool\n"
        "- fitPoints: list[PyGe.Point2d], startTangent: PyGe.Vector2d, endTangent: PyGe.Vector2d, startTangentDefined: bool, endTangentDefined: bool, fitTolerance: PyGe.Tol\n"
        "- fitPoints: list[PyGe.Point2d], startTangent: PyGe.Vector2d, endTangent: PyGe.Vector2d, startTangentDefined: bool, endTangentDefined: bool, knotParam: PyGe.KnotParameterization, fitTolerance: PyGe.Tol\n";

    constexpr const std::string_view setFitDatas = "Overloads:\n"
        "- degree: int, fitPoints: list[PyGe.Point2d], fitTolerance: PyGe.Tol\n"
        "- fitPoints: list[PyGe.Point2d], startTangent: PyGe.Vector2d, endTangent: PyGe.Vector2d, fitTolerance: PyGe.Tol\n"
        "- fitPoints: list[PyGe.Point2d], startTangent: PyGe.Vector2d, endTangent: PyGe.Vector2d, knotParam: PyGe.KnotParameterization, fitTolerance: PyGe.Tol\n"
        "- knots: PyGe.KnotVector, fitPoints: list[PyGe.Point2d], startTangent: PyGe.Vector2d, endTangent: PyGe.Vector2d, fitTolerance: PyGe.Tol, isPeriodic: bool \n";


    PyDocString DS("NurbCurve2d");
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
        .def(init<const boost::python::list&, const AcGeVector2d&, const AcGeVector2d&, Adesk::Boolean, Adesk::Boolean, AcGe::KnotParameterization, const AcGeTol&>(DS.CTOR(ctor, 12379)))
        .def("numFitPoints", &PyGeNurbCurve2d::numFitPoints, DS.ARGS())
        .def("getFitPointAt", &PyGeNurbCurve2d::getFitPointAt, DS.ARGS({ "idx: int" }))
        .def("getFitTolerance", &PyGeNurbCurve2d::getFitTolerance, DS.ARGS())
        .def("getFitTangents", &PyGeNurbCurve2d::getFitTangents, DS.ARGS())
        .def("getFitData", &PyGeNurbCurve2d::getFitData, DS.ARGS())
        .def("getDefinitionData", &PyGeNurbCurve2d::getDefinitionData, DS.ARGS())
        .def("numWeights", &PyGeNurbCurve2d::numWeights, DS.ARGS())
        .def("weightAt", &PyGeNurbCurve2d::weightAt, DS.ARGS({ "idx: int" }))
        .def("evalMode", &PyGeNurbCurve2d::evalMode, DS.ARGS())
        .def("getParamsOfC1Discontinuity", &PyGeNurbCurve2d::getParamsOfC1Discontinuity, DS.ARGS({ "tol: PyGe.Tol" }))
        .def("getParamsOfG1Discontinuity", &PyGeNurbCurve2d::getParamsOfG1Discontinuity, DS.ARGS({ "tol: PyGe.Tol" }))
        .def("setFitPointAt", &PyGeNurbCurve2d::setFitPointAt, DS.ARGS({ "idx: int", "pt: PyGe.Point2d" }))
        .def("addFitPointAt", &PyGeNurbCurve2d::addFitPointAt, DS.ARGS({ "idx: int", "pt: PyGe.Point2d" }))
        .def("deleteFitPointAt", &PyGeNurbCurve2d::deleteFitPointAt, DS.ARGS({ "idx: int" }))
        .def("setFitTolerance", &PyGeNurbCurve2d::setFitTolerance, DS.ARGS({ "tol: PyGe.Tol" }))
        .def("setFitTangents", &PyGeNurbCurve2d::setFitTangents, DS.ARGS({ "startTangent: PyGe.Vector2d" , "endTangent: PyGe.Vector2d" }))
        .def("setFitKnotParameterization", &PyGeNurbCurve2d::setFitKnotParameterization, DS.ARGS({ "val: PyGe.KnotParameterization" }))
        .def("setFitData", &PyGeNurbCurve2d::setFitData1)
        .def("setFitData", &PyGeNurbCurve2d::setFitData2)
        .def("setFitData", &PyGeNurbCurve2d::setFitData3)
        .def("setFitData", &PyGeNurbCurve2d::setFitData4, DS.OVRL(setFitDatas))
        .def("purgeFitData", &PyGeNurbCurve2d::purgeFitData, DS.ARGS())
        .def("buildFitData", &PyGeNurbCurve2d::buildFitData1)
        .def("buildFitData", &PyGeNurbCurve2d::buildFitData2, DS.ARGS({ "val: PyGe.KnotParameterization = ..." }))
        .def("addKnot", &PyGeNurbCurve2d::addKnot, DS.ARGS({ "val: float" }))
        .def("insertKnot", &PyGeNurbCurve2d::insertKnot, DS.ARGS({ "val: float" }))
        .def("setWeightAt", &PyGeNurbCurve2d::setWeightAt, DS.ARGS({ "idx: int","val: float" }))
        .def("setEvalMode", &PyGeNurbCurve2d::setEvalMode, DS.ARGS({ "val: bool" }))
        .def("joinWith", &PyGeNurbCurve2d::joinWith, DS.ARGS({ "val: PyGe.NurbCurve2d" }))
        .def("hardTrimByParams", &PyGeNurbCurve2d::hardTrimByParams, DS.ARGS({ "newStartParam: float","newEndParam: float" }))
        .def("makeRational", &PyGeNurbCurve2d::makeRational, DS.ARGS({ "val: float" }))
        .def("makeClosed", &PyGeNurbCurve2d::makeClosed, DS.ARGS())
        .def("makePeriodic", &PyGeNurbCurve2d::makePeriodic, DS.ARGS())
        .def("makeNonPeriodic", &PyGeNurbCurve2d::makeNonPeriodic, DS.ARGS())
        .def("makeOpen", &PyGeNurbCurve2d::makeOpen, DS.ARGS())
        .def("elevateDegree", &PyGeNurbCurve2d::elevateDegree, DS.ARGS({ "val: int" }))
        .def("addControlPointAt", &PyGeNurbCurve2d::addControlPointAt, DS.ARGS({ "newKnot: float","pt: PyGe.Point2d","weight: float" }))
        .def("deleteControlPointAt", &PyGeNurbCurve2d::deleteControlPointAt, DS.ARGS({ "val: int" }))
        .def("cast", &PyGeNurbCurve2d::cast, DS.SARGS({ "otherObject: PyGe.Entity2d" })).staticmethod("cast")
        .def("copycast", &PyGeNurbCurve2d::copycast, DS.SARGS({ "otherObject: PyGe.Entity2d" })).staticmethod("copycast")
        .def("className", &PyGeNurbCurve2d::className, DS.SARGS()).staticmethod("className")
        ;
#endif
}

#if !defined(_BRXTARGET260)
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

boost::python::tuple PyGeNurbCurve2d::getParamsOfC1Discontinuity(const AcGeTol& tol) const
{
    AcGeDoubleArray params;
    auto res = impObj()->getParamsOfC1Discontinuity(params, tol);
    return boost::python::make_tuple(res, DoubleArrayToPyList(params));
}

boost::python::tuple PyGeNurbCurve2d::getParamsOfG1Discontinuity(const AcGeTol& tol) const
{
    AcGeDoubleArray params;
    auto res = impObj()->getParamsOfG1Discontinuity(params, tol);
    return boost::python::make_tuple(res, DoubleArrayToPyList(params));
}

Adesk::Boolean PyGeNurbCurve2d::setFitPointAt(int index, const AcGePoint2d& point) const
{
    return impObj()->setFitPointAt(index, point);
}

Adesk::Boolean PyGeNurbCurve2d::addFitPointAt(int index, const AcGePoint2d& point) const
{
    return impObj()->addFitPointAt(index, point);
}

Adesk::Boolean PyGeNurbCurve2d::deleteFitPointAt(int index) const
{
    return impObj()->deleteFitPointAt(index);
}

Adesk::Boolean PyGeNurbCurve2d::setFitTolerance(const AcGeTol& fitTol) const
{
    return impObj()->setFitTolerance(fitTol);
}

Adesk::Boolean PyGeNurbCurve2d::setFitTangents(const AcGeVector2d& startTangent, const AcGeVector2d& endTangent) const
{
    return impObj()->setFitTangents(startTangent, endTangent);
}

Adesk::Boolean PyGeNurbCurve2d::setFitKnotParameterization(KnotParameterization knotParam) const
{
    return impObj()->setFitKnotParameterization(knotParam);
}

void PyGeNurbCurve2d::setFitData1(const boost::python::list& fitPoints, const AcGeVector2d& startTangent,
    const AcGeVector2d& endTangent, const AcGeTol& fitTol) const
{
    impObj()->setFitData(PyListToPoint2dArray(fitPoints), startTangent, endTangent, fitTol);
}

void PyGeNurbCurve2d::setFitData2(const boost::python::list& fitPoints, const AcGeVector2d& startTangent,
    const AcGeVector2d& endTangent, KnotParameterization knotParam, const AcGeTol& fitTol) const
{
    impObj()->setFitData(PyListToPoint2dArray(fitPoints), startTangent, endTangent, knotParam, fitTol);
}

void PyGeNurbCurve2d::setFitData3(const PyGeKnotVector& fitKnots, const boost::python::list& fitPoints, const AcGeVector2d& startTangent,
    const AcGeVector2d& endTangent, const AcGeTol& fitTol, Adesk::Boolean isPeriodic) const
{
    impObj()->setFitData(fitKnots.m_imp, PyListToPoint2dArray(fitPoints), startTangent, endTangent, fitTol, isPeriodic);
}

void PyGeNurbCurve2d::setFitData4(int degree, const boost::python::list& fitPoints, const AcGeTol& fitTol) const
{
    impObj()->setFitData(degree, PyListToPoint2dArray(fitPoints), fitTol);
}

Adesk::Boolean PyGeNurbCurve2d::purgeFitData() const
{
    return impObj()->purgeFitData();
}

Adesk::Boolean PyGeNurbCurve2d::buildFitData1() const
{
    return impObj()->buildFitData();
}

Adesk::Boolean PyGeNurbCurve2d::buildFitData2(KnotParameterization kp) const
{
    return impObj()->buildFitData(kp);
}

void PyGeNurbCurve2d::addKnot(double newKnot) const
{
    impObj()->addKnot(newKnot);
}

void PyGeNurbCurve2d::insertKnot(double newKnot) const
{
    impObj()->insertKnot(newKnot);
}

void PyGeNurbCurve2d::setWeightAt(int idx, double val) const
{
    impObj()->setWeightAt(idx, val);
}

void PyGeNurbCurve2d::setEvalMode(Adesk::Boolean evalMode) const
{
    impObj()->setEvalMode(evalMode);
}

void PyGeNurbCurve2d::joinWith(const PyGeNurbCurve2d& curve) const
{
    impObj()->joinWith(*curve.impObj());
}

void PyGeNurbCurve2d::hardTrimByParams(double newStartParam, double newEndParam) const
{
    impObj()->hardTrimByParams(newStartParam, newEndParam);
}

void PyGeNurbCurve2d::makeRational(double weight) const
{
    impObj()->makeRational(weight);
}

void PyGeNurbCurve2d::makeClosed() const
{
    impObj()->makeClosed();
}

void PyGeNurbCurve2d::makePeriodic() const
{
    impObj()->makePeriodic();
}

void PyGeNurbCurve2d::makeNonPeriodic() const
{
    impObj()->makeNonPeriodic();
}

void PyGeNurbCurve2d::makeOpen() const
{
    impObj()->makeOpen();
}

void PyGeNurbCurve2d::elevateDegree(int plusDegree) const
{
    impObj()->elevateDegree(plusDegree);
}

Adesk::Boolean PyGeNurbCurve2d::addControlPointAt(double newKnot, const AcGePoint2d& point, double weight) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    return impObj()->addControlPointAt(newKnot, point, weight);
#endif
}

Adesk::Boolean PyGeNurbCurve2d::deleteControlPointAt(int index) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    return impObj()->deleteControlPointAt(index);
#endif
}

PyGeNurbCurve2d PyGeNurbCurve2d::cast(const PyGeEntity2d& src)
{
    return PyGeEntity2dCast<PyGeNurbCurve2d, AcGeNurbCurve2d>(src);
}

PyGeNurbCurve2d PyGeNurbCurve2d::copycast(const PyGeEntity2d& src)
{
    return PyGeNurbCurve2d(static_cast<AcGeNurbCurve2d*>(src.impObj()->copy()));
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

#if !defined(_BRXTARGET260)
    constexpr const std::string_view ctor = "Overloads:\n"
        "- None: Any\n"
        "- points: list[PyGe.Point2d]\n"
        "- knots: PyGe.KnotVector, points: list[PyGe.Point2d]\n"
        "- crv: PyGe.Curve2d, apprEps: float";

    PyDocString DS("Polyline2d");
    class_<PyGePolyline2d, bases<PyGeSplineEnt2d>>("Polyline2d")
        .def(init<>())
        .def(init<const boost::python::list&>())
        .def(init<const PyGeKnotVector&, const boost::python::list&>())
        .def(init<const PyGeCurve2d&, double>(DS.CTOR(ctor, 12647)))
        .def("numFitPoints", &PyGePolyline2d::numFitPoints, DS.ARGS())
        .def("fitPointAt", &PyGePolyline2d::fitPointAt, DS.ARGS({ "idx: int" }))
        .def("setFitPointAt", &PyGePolyline2d::setFitPointAt, DS.ARGS({ "idx: int","pt: PyGe.Point2d" }))
        .def("cast", &PyGePolyline2d::cast, DS.SARGS({ "otherObject: PyGe.Entity2d" })).staticmethod("cast")
        .def("copycast", &PyGePolyline2d::copycast, DS.SARGS({ "otherObject: PyGe.Entity2d" })).staticmethod("copycast")
        .def("className", &PyGePolyline2d::className, DS.SARGS()).staticmethod("className")
        ;
#endif
}

#if !defined(_BRXTARGET260)
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

void PyGePolyline2d::setFitPointAt(int idx, const AcGePoint2d& point) const
{
    impObj()->setFitPointAt(idx, point);
}

PyGePolyline2d PyGePolyline2d::cast(const PyGeEntity2d& src)
{
    return PyGeEntity2dCast<PyGePolyline2d, AcGePolyline2d>(src);
}

PyGePolyline2d PyGePolyline2d::copycast(const PyGeEntity2d& src)
{
    return PyGePolyline2d(static_cast<AcGePolyline2d*>(src.impObj()->copy()));
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
