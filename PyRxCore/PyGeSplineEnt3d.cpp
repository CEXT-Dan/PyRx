#include "stdafx.h"
#include "PyGeSplineEnt3d.h"
#include "PyGeKnotVector.h"
#include "PyGeLinearEnt3d.h"

using namespace boost::python;

//-----------------------------------------------------------------------------------------
//PyGeSplineEnt3d wrapper
void makePyGeSplineEnt3dWrapper()
{
    PyDocString DS("SplineEnt3d");
    class_<PyGeSplineEnt3d, bases<PyGeCurve3d>>("SplineEnt3d", boost::python::no_init)
        .def("isRational", &PyGeSplineEnt3d::isRational, DS.ARGS())
        .def("degree", &PyGeSplineEnt3d::degree, DS.ARGS())
        .def("order", &PyGeSplineEnt3d::order, DS.ARGS())
        .def("numKnots", &PyGeSplineEnt3d::numKnots, DS.ARGS())
        .def("knots", &PyGeSplineEnt3d::knots, DS.ARGS())
        .def("numControlPoints", &PyGeSplineEnt3d::numControlPoints, DS.ARGS())
        .def("continuityAtKnot", &PyGeSplineEnt3d::continuityAtKnot1)
        .def("continuityAtKnot", &PyGeSplineEnt3d::continuityAtKnot2, DS.ARGS({ "idx: int", "tol: PyGe.Tol = ..." }))
        .def("startParam", &PyGeSplineEnt3d::startParam, DS.ARGS())
        .def("endParam", &PyGeSplineEnt3d::endParam, DS.ARGS())
        .def("startPoint", &PyGeSplineEnt3d::startPoint, DS.ARGS())
        .def("endPoint", &PyGeSplineEnt3d::endPoint, DS.ARGS())
        .def("hasFitData", &PyGeSplineEnt3d::hasFitData, DS.ARGS())
        .def("knotAt", &PyGeSplineEnt3d::knotAt, DS.ARGS({ "idx: int" }))
        .def("setKnotAt", &PyGeSplineEnt3d::setKnotAt, DS.ARGS({ "idx: int", "val: float" }))
        .def("controlPointAt", &PyGeSplineEnt3d::controlPointAt, DS.ARGS({ "idx: int" }))
        .def("setControlPointAt", &PyGeSplineEnt3d::setControlPointAt, DS.ARGS({ "idx: int", "val: PyGe.Point3d" }))
        .def("cast", &PyGeSplineEnt3d::cast, DS.SARGS({ "otherObject: PyGe.Entity3d" })).staticmethod("cast")
        .def("copycast", &PyGeSplineEnt3d::copycast, DS.SARGS({ "otherObject: PyGe.Entity3d" })).staticmethod("copycast")
        .def("className", &PyGeSplineEnt3d::className, DS.SARGS()).staticmethod("className")
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
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    return PyGeKnotVector(impObj()->knots());
#endif
}

int PyGeSplineEnt3d::numControlPoints() const
{
    return impObj()->numControlPoints();
}

int PyGeSplineEnt3d::continuityAtKnot1(int idx) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    return impObj()->continuityAtKnot(idx);
#endif
}

int PyGeSplineEnt3d::continuityAtKnot2(int idx, const AcGeTol& tol) const
{
#if defined(_BRXTARGET260)
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

void PyGeSplineEnt3d::setKnotAt(int idx, double val) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    impObj()->setKnotAt(idx, val);
#endif
}

AcGePoint3d PyGeSplineEnt3d::controlPointAt(int idx) const
{
    return impObj()->controlPointAt(idx);
}

void PyGeSplineEnt3d::setControlPointAt(int idx, const AcGePoint3d& pnt) const
{
    impObj()->setControlPointAt(idx, pnt);
}

PyGeSplineEnt3d PyGeSplineEnt3d::cast(const PyGeEntity3d& src)
{
    return PyGeEntity3dCast<PyGeSplineEnt3d, AcGeSplineEnt3d>(src);
}

PyGeSplineEnt3d PyGeSplineEnt3d::copycast(const PyGeEntity3d& src)
{
    return PyGeSplineEnt3d(static_cast<AcGeSplineEnt3d*>(src.impObj()->copy()));
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
#if !defined(_BRXTARGET260)
    constexpr const std::string_view ctor = "Overloads:\n"
        "- None: Any\n"
        "- curve: PyGe.Curve3d, epsilon: float\n"
        "- fitPnts: list[PyGe.Point3d], tol: PyGe.Tol\n"
        "- fitPnts: list[PyGe.Point3d], startDeriv: PyGe.Vector3d, endDeriv: PyGe.Vector3d, tol: PyGe.Tol\n"
        "- knots: PyGe.KnotVector, fitPnts: list[PyGe.Point3d], firstDerivs: list[PyGe.Vector3d], isPeriodic: bool\n";

    PyDocString DS("CubicSplineCurve3d");
    class_<PyGeCubicSplineCurve3d, bases<PyGeSplineEnt3d>>("CubicSplineCurve3d")
        .def(init<>())
        .def(init<const PyGeCurve3d&, double>())
        .def(init<const boost::python::list&, const AcGeTol&>())
        .def(init<const boost::python::list&, const AcGeVector3d&, const AcGeVector3d&, const AcGeTol&>())
        .def(init<const PyGeKnotVector&, const boost::python::list&, const boost::python::list&, Adesk::Boolean>(DS.CTOR(ctor, 11807)))
        .def("numFitPoints", &PyGeCubicSplineCurve3d::numFitPoints, DS.ARGS())
        .def("fitPointAt", &PyGeCubicSplineCurve3d::fitPointAt, DS.ARGS({ "idx: int" }))
        .def("setFitPointAt", &PyGeCubicSplineCurve3d::setFitPointAt, DS.ARGS({ "idx: int" ,"pt: PyGe.Point3d" }))
        .def("firstDerivAt", &PyGeCubicSplineCurve3d::firstDerivAt, DS.ARGS({ "idx: int" }))
        .def("setFirstDerivAt", &PyGeCubicSplineCurve3d::setFirstDerivAt, DS.ARGS({ "idx: int" ,"vec: PyGe.Vector3d" }))
        .def("cast", &PyGeCubicSplineCurve3d::cast, DS.SARGS({ "otherObject: PyGe.Entity3d" })).staticmethod("cast")
        .def("copycast", &PyGeCubicSplineCurve3d::copycast, DS.SARGS({ "otherObject: PyGe.Entity3d" })).staticmethod("copycast")
        .def("className", &PyGeCubicSplineCurve3d::className, DS.SARGS()).staticmethod("className")
        ;
#endif
}

#if !defined(_BRXTARGET260)
PyGeCubicSplineCurve3d::PyGeCubicSplineCurve3d()
    : PyGeSplineEnt3d(new AcGeCubicSplineCurve3d())
{
}

PyGeCubicSplineCurve3d::PyGeCubicSplineCurve3d(const PyGeCurve3d& curve, double epsilon)
    : PyGeSplineEnt3d(new AcGeCubicSplineCurve3d(*curve.impObj(), epsilon))
{
}

PyGeCubicSplineCurve3d::PyGeCubicSplineCurve3d(const boost::python::list& fitPnts, const AcGeTol& tol)
    : PyGeSplineEnt3d(new AcGeCubicSplineCurve3d(PyListToPoint3dArray(fitPnts), tol))
{
}

PyGeCubicSplineCurve3d::PyGeCubicSplineCurve3d(const boost::python::list& fitPnts, const AcGeVector3d& startDeriv, const AcGeVector3d& endDeriv, const AcGeTol& tol)
    : PyGeSplineEnt3d(new AcGeCubicSplineCurve3d(PyListToPoint3dArray(fitPnts), startDeriv, endDeriv, tol))
{
}

PyGeCubicSplineCurve3d::PyGeCubicSplineCurve3d(const PyGeKnotVector& knots, const boost::python::list& fitPnts, const boost::python::list& firstDerivs, Adesk::Boolean isPeriodic)
    : PyGeSplineEnt3d(new AcGeCubicSplineCurve3d(knots.m_imp, PyListToPoint3dArray(fitPnts), PyListToVector3dArray(firstDerivs), isPeriodic))
{
}

PyGeCubicSplineCurve3d::PyGeCubicSplineCurve3d(AcGeEntity3d* pEnt)
    : PyGeSplineEnt3d(pEnt)
{
}

int PyGeCubicSplineCurve3d::numFitPoints() const
{
    return impObj()->numFitPoints();
}

AcGePoint3d PyGeCubicSplineCurve3d::fitPointAt(int idx) const
{
    return impObj()->fitPointAt(idx);
}

void PyGeCubicSplineCurve3d::setFitPointAt(int idx, const AcGePoint3d& point) const
{
    impObj()->setFitPointAt(idx, point);
}

AcGeVector3d PyGeCubicSplineCurve3d::firstDerivAt(int idx) const
{
    return impObj()->firstDerivAt(idx);
}

void PyGeCubicSplineCurve3d::setFirstDerivAt(int idx, const AcGeVector3d& deriv) const
{
    impObj()->setFirstDerivAt(idx, deriv);
}

PyGeCubicSplineCurve3d PyGeCubicSplineCurve3d::cast(const PyGeEntity3d& src)
{
    return PyGeEntity3dCast<PyGeCubicSplineCurve3d, AcGeCubicSplineCurve3d>(src);
}

PyGeCubicSplineCurve3d PyGeCubicSplineCurve3d::copycast(const PyGeEntity3d& src)
{
    return PyGeCubicSplineCurve3d(static_cast<AcGeCubicSplineCurve3d*>(src.impObj()->copy()));
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
#endif

//-----------------------------------------------------------------------------------------
//AcGeNurbCurve3d  wrapper
void makePyGeNurbCurve3dWrapper()
{
#if !defined(_BRXTARGET260)
    constexpr const std::string_view ctor = "Overloads:\n"
        "- None: Any\n"
        "- src: PyGe.Curve3d\n"
        "- src: PyGe.LineSeg3d\n"
        "- src: PyGe.EllipArc3d\n"
        "- curve: PyGe.Curve3d, epsilon: float\n"
        "- fitPnts: list[PyGe.Point3d], tol: PyGe.Tol\n"
        "- degree: int, fitPolyline: PyGe.Polyline3d, isPeriodic: bool\n"
        "- degree: int, knots: PyGe.KnotVector, cntrlPnts: list[PyGe.Point3d], isPeriodic: bool\n"
        "- fitPoints: list[PyGe.Point3d], fitTangents: list[PyGe.Vector3d], fitTolerance: PyGe.Tol,isPeriodic: bool\n"
        "- fitPoints: list[PyGe.Point3d], startTangent: PyGe.Vector3d, endTangent: PyGe.Vector3d, startTangentDefined: bool, endTangentDefined: bool, fitTolerance: PyGe.Tol\n"
        "- fitPoints: list[PyGe.Point3d], startTangent: PyGe.Vector3d, endTangent: PyGe.Vector3d, startTangentDefined: bool, endTangentDefined: bool, knotParam: PyGe.KnotParameterization, fitTolerance: PyGe.Tol\n";

    constexpr const std::string_view setFitTangentsOverloads = "Overloads:\n"
        "- startTangent: PyGe.Vector3d, endTangent: PyGe.Vector3d\n"
        "- startTangent: PyGe.Vector3d, endTangent: PyGe.Vector3d, startTangentDefined: bool, endTangentDefined: bool\n";

    constexpr const std::string_view setFitDatas = "Overloads:\n"
        "- degree: int, fitPoints: list[PyGe.Point3d], fitTolerance: PyGe.Tol\n"
        "- fitPoints: list[PyGe.Point3d], startTangent: PyGe.Vector3d, endTangent: PyGe.Vector3d, fitTolerance: PyGe.Tol\n"
        "- fitPoints: list[PyGe.Point3d], startTangent: PyGe.Vector3d, endTangent: PyGe.Vector3d, knotParam: PyGe.KnotParameterization, fitTolerance: PyGe.Tol\n"
        "- knots: PyGe.KnotVector, fitPoints: list[PyGe.Point3d], startTangent: PyGe.Vector3d, endTangent: PyGe.Vector3d, fitTolerance: PyGe.Tol, isPeriodic: bool \n";

    PyDocString DS("NurbCurve3d");
    class_<PyGeNurbCurve3d, bases<PyGeSplineEnt3d>>("NurbCurve3d")
        .def(init<>())
        .def(init<const PyGeEllipArc3d&>())
        .def(init<const PyGeLineSeg3d&>())
        .def(init<const PyGeCurve3d&, double>())
        .def(init<const boost::python::list&, const AcGeTol&>())
        .def(init<int, const PyGePolyline3d&, Adesk::Boolean>())
        .def(init<int, const PyGeKnotVector&, const boost::python::list&, Adesk::Boolean>())
        .def(init<const boost::python::list&, const boost::python::list&, const AcGeTol&, Adesk::Boolean>())
        .def(init<const boost::python::list&, const AcGeVector3d&, const AcGeVector3d&, Adesk::Boolean, Adesk::Boolean, const AcGeTol&>())
        .def(init<const boost::python::list&, const AcGeVector3d&, const AcGeVector3d&, Adesk::Boolean, Adesk::Boolean, AcGe::KnotParameterization, const AcGeTol&>(DS.CTOR(ctor, 12417)))
        .def("numFitPoints", &PyGeNurbCurve3d::numFitPoints, DS.ARGS())
        .def("getFitPointAt", &PyGeNurbCurve3d::getFitPointAt, DS.ARGS({ "idx: int" }))
        .def("getFitTolerance", &PyGeNurbCurve3d::getFitTolerance, DS.ARGS())
        .def("getFitTangents", &PyGeNurbCurve3d::getFitTangents, DS.ARGS())
        .def("getFitData", &PyGeNurbCurve3d::getFitData, DS.ARGS())
        .def("getDefinitionData", &PyGeNurbCurve3d::getDefinitionData, DS.ARGS())
        .def("numWeights", &PyGeNurbCurve3d::numWeights, DS.ARGS())
        .def("weightAt", &PyGeNurbCurve3d::weightAt, DS.ARGS({ "idx: int" }))
        .def("evalMode", &PyGeNurbCurve3d::evalMode, DS.ARGS())
        .def("getParamsOfC1Discontinuity", &PyGeNurbCurve3d::getParamsOfC1Discontinuity, DS.ARGS({ "tol: PyGe.Tol" }))
        .def("getParamsOfG1Discontinuity", &PyGeNurbCurve3d::getParamsOfG1Discontinuity, DS.ARGS({ "tol: PyGe.Tol" }))
        .def("setFitPointAt", &PyGeNurbCurve3d::setFitPointAt, DS.ARGS({ "idx: int","pt: PyGe.Point3d" }))
        .def("addFitPointAt", &PyGeNurbCurve3d::addFitPointAt, DS.ARGS({ "idx: int","pt: PyGe.Point3d" }))
        .def("deleteFitPointAt", &PyGeNurbCurve3d::deleteFitPointAt, DS.ARGS({ "idx: int" }))
        .def("setFitTolerance", &PyGeNurbCurve3d::setFitTolerance, DS.ARGS({ "tol: PyGe.Tol" }))
        .def("setFitTangents", &PyGeNurbCurve3d::setFitTangents1)
        .def("setFitTangents", &PyGeNurbCurve3d::setFitTangents2, DS.OVRL(setFitTangentsOverloads))
        .def("setFitKnotParameterization", &PyGeNurbCurve3d::setFitKnotParameterization, DS.ARGS({ "val: PyGe.KnotParameterization" }))
        .def("setFitData", &PyGeNurbCurve3d::setFitData1)
        .def("setFitData", &PyGeNurbCurve3d::setFitData2)
        .def("setFitData", &PyGeNurbCurve3d::setFitData3)
        .def("setFitData", &PyGeNurbCurve3d::setFitData4, DS.OVRL(setFitDatas))
        .def("purgeFitData", &PyGeNurbCurve3d::purgeFitData, DS.ARGS())
        .def("buildFitData", &PyGeNurbCurve3d::buildFitData1)
        .def("buildFitData", &PyGeNurbCurve3d::buildFitData2, DS.ARGS({ "val: PyGe.KnotParameterization = ..." }))
        .def("addKnot", &PyGeNurbCurve3d::addKnot, DS.ARGS({ "val: float" }))
        .def("insertKnot", &PyGeNurbCurve3d::insertKnot, DS.ARGS({ "val: float" }))
        .def("setWeightAt", &PyGeNurbCurve3d::setWeightAt, DS.ARGS({ "idx: int", "val: float" }))
        .def("setEvalMode", &PyGeNurbCurve3d::setEvalMode, DS.ARGS({ "val: bool" }))
        .def("joinWith", &PyGeNurbCurve3d::joinWith, DS.ARGS({ "val: PyGe.NurbCurve3d" }))
        .def("hardTrimByParams", &PyGeNurbCurve3d::hardTrimByParams, DS.ARGS({ "newStartParam: float","newEndParam: float" }))
        .def("makeRational", &PyGeNurbCurve3d::makeRational, DS.ARGS({ "val: float" }))
        .def("makeClosed", &PyGeNurbCurve3d::makeClosed, DS.ARGS())
        .def("makePeriodic", &PyGeNurbCurve3d::makePeriodic, DS.ARGS())
        .def("makeNonPeriodic", &PyGeNurbCurve3d::makeNonPeriodic, DS.ARGS())
        .def("makeOpen", &PyGeNurbCurve3d::makeOpen, DS.ARGS())
        .def("elevateDegree", &PyGeNurbCurve3d::elevateDegree, DS.ARGS({ "val: int" }))
        .def("addControlPointAt", &PyGeNurbCurve3d::addControlPointAt, DS.ARGS({ "newKnot: float","pt: PyGe.Point3d","weight: float" }))
        .def("deleteControlPointAt", &PyGeNurbCurve3d::deleteControlPointAt, DS.ARGS({ "idx: int" }))
        .def("cast", &PyGeNurbCurve3d::cast, DS.SARGS({ "otherObject: PyGe.Entity3d" })).staticmethod("cast")
        .def("copycast", &PyGeNurbCurve3d::copycast, DS.SARGS({ "otherObject: PyGe.Entity3d" })).staticmethod("copycast")
        .def("className", &PyGeNurbCurve3d::className, DS.SARGS({ "otherObject: PyGe.Entity3d" })).staticmethod("className")
        ;
#endif
}

#if !defined(_BRXTARGET260)
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

boost::python::tuple PyGeNurbCurve3d::getParamsOfC1Discontinuity(const AcGeTol& tol) const
{
    AcGeDoubleArray params;
    auto res = impObj()->getParamsOfC1Discontinuity(params, tol);
    return boost::python::make_tuple(res, DoubleArrayToPyList(params));
}

boost::python::tuple PyGeNurbCurve3d::getParamsOfG1Discontinuity(const AcGeTol& tol) const
{
    AcGeDoubleArray params;
    auto res = impObj()->getParamsOfG1Discontinuity(params, tol);
    return boost::python::make_tuple(res, DoubleArrayToPyList(params));
}

Adesk::Boolean PyGeNurbCurve3d::setFitPointAt(int index, const AcGePoint3d& point) const
{
    return impObj()->setFitPointAt(index, point);
}

Adesk::Boolean PyGeNurbCurve3d::addFitPointAt(int index, const AcGePoint3d& point) const
{
    return impObj()->addFitPointAt(index, point);
}

Adesk::Boolean PyGeNurbCurve3d::deleteFitPointAt(int index) const
{
    return impObj()->deleteFitPointAt(index);
}

Adesk::Boolean PyGeNurbCurve3d::setFitTolerance(const AcGeTol& fitTol) const
{
    return impObj()->setFitTolerance(fitTol);
}

Adesk::Boolean PyGeNurbCurve3d::setFitTangents1(const AcGeVector3d& startTangent, const AcGeVector3d& endTangent) const
{
    return impObj()->setFitTangents(startTangent, endTangent);
}

Adesk::Boolean PyGeNurbCurve3d::setFitTangents2(const AcGeVector3d& startTangent,
    const AcGeVector3d& endTangent, Adesk::Boolean startTangentDefined, Adesk::Boolean endTangentDefined) const
{
    return impObj()->setFitTangents(startTangent, endTangent, startTangentDefined, endTangentDefined);
}

Adesk::Boolean PyGeNurbCurve3d::setFitKnotParameterization(KnotParameterization knotParam) const
{
    return impObj()->setFitKnotParameterization(knotParam);
}

void PyGeNurbCurve3d::setFitData1(const boost::python::list& fitPoints, const AcGeVector3d& startTangent,
    const AcGeVector3d& endTangent, const AcGeTol& fitTol) const
{
    impObj()->setFitData(PyListToPoint3dArray(fitPoints), startTangent, endTangent, fitTol);
}

void PyGeNurbCurve3d::setFitData2(const boost::python::list& fitPoints, const AcGeVector3d& startTangent,
    const AcGeVector3d& endTangent, KnotParameterization knotParam, const AcGeTol& fitTol) const
{
    impObj()->setFitData(PyListToPoint3dArray(fitPoints), startTangent, endTangent, knotParam, fitTol);
}

void PyGeNurbCurve3d::setFitData3(const PyGeKnotVector& fitKnots, const boost::python::list& fitPoints, const AcGeVector3d& startTangent,
    const AcGeVector3d& endTangent, const AcGeTol& fitTol, Adesk::Boolean isPeriodic) const
{
    impObj()->setFitData(fitKnots.m_imp, PyListToPoint3dArray(fitPoints), startTangent, endTangent, fitTol, isPeriodic);
}

void PyGeNurbCurve3d::setFitData4(int degree, const boost::python::list& fitPoints, const AcGeTol& fitTol) const
{
    impObj()->setFitData(degree, PyListToPoint3dArray(fitPoints), fitTol);
}

Adesk::Boolean PyGeNurbCurve3d::purgeFitData() const
{
    return impObj()->purgeFitData();
}

Adesk::Boolean PyGeNurbCurve3d::buildFitData1() const
{
    return impObj()->buildFitData();
}

Adesk::Boolean PyGeNurbCurve3d::buildFitData2(KnotParameterization kp) const
{
    return impObj()->buildFitData(kp);
}

void PyGeNurbCurve3d::addKnot(double newKnot) const
{
    impObj()->addKnot(newKnot);
}

void PyGeNurbCurve3d::insertKnot(double newKnot) const
{
    impObj()->insertKnot(newKnot);
}

void PyGeNurbCurve3d::setWeightAt(int idx, double val) const
{
    impObj()->setWeightAt(idx, val);
}

void PyGeNurbCurve3d::setEvalMode(Adesk::Boolean evalMode) const
{
    impObj()->setEvalMode(evalMode);
}

void PyGeNurbCurve3d::joinWith(const PyGeNurbCurve3d& curve) const
{
    impObj()->joinWith(*curve.impObj());
}

void PyGeNurbCurve3d::hardTrimByParams(double newStartParam, double newEndParam) const
{
    impObj()->hardTrimByParams(newStartParam, newEndParam);
}

void PyGeNurbCurve3d::makeRational(double weight) const
{
    impObj()->makeRational(weight);
}

void PyGeNurbCurve3d::makeClosed() const
{
    impObj()->makeClosed();
}

void PyGeNurbCurve3d::makePeriodic() const
{
    impObj()->makePeriodic();
}

void PyGeNurbCurve3d::makeNonPeriodic() const
{
    impObj()->makeNonPeriodic();
}

void PyGeNurbCurve3d::makeOpen() const
{
    impObj()->makeOpen();
}

void PyGeNurbCurve3d::elevateDegree(int plusDegree) const
{
    impObj()->elevateDegree(plusDegree);
}

Adesk::Boolean PyGeNurbCurve3d::addControlPointAt(double newKnot, const AcGePoint3d& point, double weight) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    return impObj()->addControlPointAt(newKnot, point, weight);
#endif
}

Adesk::Boolean PyGeNurbCurve3d::deleteControlPointAt(int index) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    return impObj()->deleteControlPointAt(index);
#endif
}

PyGeNurbCurve3d PyGeNurbCurve3d::cast(const PyGeEntity3d& src)
{
    return PyGeEntity3dCast<PyGeNurbCurve3d, AcGeNurbCurve3d>(src);
}

PyGeNurbCurve3d PyGeNurbCurve3d::copycast(const PyGeEntity3d& src)
{
    return PyGeNurbCurve3d(static_cast<AcGeNurbCurve3d*>(src.impObj()->copy()));
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
#endif

//-----------------------------------------------------------------------------------------
//AcGeNurbCurve3d  wrapper
void makePyGePolyline3dWrapper()
{
    constexpr const std::string_view ctor = "Overloads:\n"
        "- None: Any\n"
        "- points: list[PyGe.Point3d]\n"
        "- knots: PyGe.KnotVector, points: list[PyGe.Point3d]\n"
        "- crv: PyGe.Curve3d, apprEps: float";

    PyDocString DS("Polyline3d");
    class_<PyGePolyline3d, bases<PyGeSplineEnt3d>>("Polyline3d")
        .def(init<>())
        .def(init<const boost::python::list&>())
        .def(init<const PyGeKnotVector&, const boost::python::list&>())
#if !defined(_BRXTARGET260)
        .def(init<const PyGeCurve3d&, double>(DS.CTOR(ctor, 12653)))
#endif
        .def("numFitPoints", &PyGePolyline3d::numFitPoints, DS.ARGS())
        .def("fitPointAt", &PyGePolyline3d::fitPointAt, DS.ARGS({ "idx: int" }))
        .def("setFitPointAt", &PyGePolyline3d::setFitPointAt, DS.ARGS({ "idx: int","pt: PyGe.Point3d" }))
        .def("cast", &PyGePolyline3d::cast, DS.SARGS({ "otherObject: PyGe.Entity3d" })).staticmethod("cast")
        .def("copycast", &PyGePolyline3d::copycast, DS.SARGS({ "otherObject: PyGe.Entity3d" })).staticmethod("copycast")
        .def("className", &PyGePolyline3d::className, DS.SARGS({ "otherObject: PyGe.Entity3d" })).staticmethod("className")
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

#if !defined(_BRXTARGET260)
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

void PyGePolyline3d::setFitPointAt(int idx, const AcGePoint3d& point) const
{
    impObj()->setFitPointAt(idx, point);
}

PyGePolyline3d PyGePolyline3d::cast(const PyGeEntity3d& src)
{
    return PyGeEntity3dCast<PyGePolyline3d, AcGePolyline3d>(src);
}

PyGePolyline3d PyGePolyline3d::copycast(const PyGeEntity3d& src)
{
    return PyGePolyline3d(static_cast<AcGePolyline3d*>(src.impObj()->copy()));
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
