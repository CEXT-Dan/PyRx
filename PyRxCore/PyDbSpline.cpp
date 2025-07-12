#include "stdafx.h"
#include "PyDbSpline.h"
#include "PyDbObjectId.h"
#include "PyGeSplineEnt3d.h"
#include "PyDbEnts.h"
using namespace boost::python;

//-----------------------------------------------------------------------------------
//AcDbSpline
void makePyDbSplineWrapper()
{
    constexpr const std::string_view ctor = "Overloads:\n"
        "- None: Any\n"
        "- id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode, erased: bool\n"
        "- idfitPoints: list[PyGe.Point3d]\n"
        "- idfitPoints: list[PyGe.Point3d], order: int, fitTolerance: float\n"
        "- idfitPoints: list[PyGe.Point3d], startTangent: PyGe.Vector3d, endTangent: PyGe.Vector3d\n"
        "- idfitPoints: list[PyGe.Point3d], startTangent: PyGe.Vector3d, endTangent: PyGe.Vector3d, order: int, fitTolerance: float\n"
        "- idfitPoints: list[PyGe.Point3d], periodic: bool\n"
        "- idfitPoints: list[PyGe.Point3d], periodic: bool, knotParam: PyGe.KnotParameterization, order: int, fitTolerance: float\n"
        "- idfitPoints: list[PyGe.Point3d], startTangent: PyGe.Vector3d, endTangent: PyGe.Vector3d, knotParam: PyGe.KnotParameterization\n"
        "- idfitPoints: list[PyGe.Point3d], startTangent: PyGe.Vector3d, endTangent: PyGe.Vector3d, knotParam: PyGe.KnotParameterization, order: int, fitTolerance: float\n"
        "- degree: int, rational: bool, closed: bool, periodic: bool, controlPoints: list[PyGe.Point3d], knots: list[float], weights: list[float]\n"
        "- degree: int, rational: bool, closed: bool, periodic: bool, controlPoints: list[PyGe.Point3d], knots: list[float], weights: list[float], controlPtTol: float, knotTol: float\n"
        "- center: PyGe.Point3d, unitNormal: PyGe.Vector3d, majorAxis: PyGe.Vector3d, radiusRatioL: float\n"
        "- center: PyGe.Point3d, unitNormal: PyGe.Vector3d, majorAxis: PyGe.Vector3d, radiusRatioL: float, startAngle: float, endAngle: float\n";

    constexpr const std::string_view setFitDataKnotOverloads = "Overloads:\n"
        "- idfitPoints: list[PyGe.Point3d], periodic: bool, knotParam: PyGe.KnotParameterization\n"
        "- idfitPoints: list[PyGe.Point3d], periodic: bool, knotParam: PyGe.KnotParameterization, degree: int, fitTolerance: float\n"
        "- idfitPoints: list[PyGe.Point3d], startTangent: PyGe.Vector3d, endTangent: PyGe.Vector3d, knotParam: PyGe.KnotParameterization\n"
        "- idfitPoints: list[PyGe.Point3d], startTangent: PyGe.Vector3d, endTangent: PyGe.Vector3d, knotParam: PyGe.KnotParameterization, order: int, fitTolerance: float\n";

    constexpr const std::string_view setNurbsDataOverloads = "Overloads:\n"
        "- degree: int, rational: bool, closed: bool, periodic: bool, controlPoints: list[PyGe.Point3d], knots: list[float], weights: list[float]\n"
        "- degree: int, rational: bool, closed: bool, periodic: bool, controlPoints: list[PyGe.Point3d], knots: list[float], weights: list[float], controlPtTol: float, knotTol: float\n";

    constexpr const std::string_view insertControlPointAtOverloads = "Overloads:\n"
        "- knotParam: int, ctrlPt: PyGe.Point3d\n"
        "- knotParam: int, ctrlPt: PyGe.Point3d,weight: float\n";

    PyDocString DS("Spline");
    class_<PyDbSpline, bases<PyDbCurve>>("Spline")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>())
        .def(init<const boost::python::list&>())
        .def(init<const boost::python::list&, int, double>())
        .def(init<const boost::python::list&, const AcGeVector3d&, const AcGeVector3d&>())
        .def(init<const boost::python::list&, const AcGeVector3d&, const AcGeVector3d&, int, double>())
        .def(init<const boost::python::list&, bool>())
        .def(init<const boost::python::list&, bool, AcGe::KnotParameterization, int, double>())
        .def(init<const boost::python::list&, AcGe::KnotParameterization>())
        .def(init<const boost::python::list&, AcGe::KnotParameterization, int, double>())
        .def(init<const boost::python::list&, const AcGeVector3d&, const AcGeVector3d&, AcGe::KnotParameterization>())
        .def(init<const boost::python::list&, const AcGeVector3d&, const AcGeVector3d&, AcGe::KnotParameterization, int, double>())
        .def(init<int, Adesk::Boolean, Adesk::Boolean, Adesk::Boolean, const boost::python::list&, const boost::python::list&, const boost::python::list&>())
        .def(init<int, Adesk::Boolean, Adesk::Boolean, Adesk::Boolean, const boost::python::list&, const boost::python::list&, const boost::python::list&, double, double>())
        .def(init<const AcGePoint3d&, const AcGeVector3d&, const AcGeVector3d&, double>())
        .def(init<const AcGePoint3d&, const AcGeVector3d&, const AcGeVector3d&, double, double, double>(DS.CTOR(ctor, 8731)))
        .def("isNull", &PyDbSpline::isNull, DS.ARGS(8746))
        .def("isRational", &PyDbSpline::isRational, DS.ARGS(8747))
        .def("degree", &PyDbSpline::degree, DS.ARGS(8733))
        .def("elevateDegree", &PyDbSpline::elevateDegree, DS.ARGS({ "val : int" }, 8734))
        .def("numControlPoints", &PyDbSpline::numControlPoints, DS.ARGS(8749))
        .def("getControlPointAt", &PyDbSpline::getControlPointAt, DS.ARGS({ "idx:int" }, 8736))
        .def("setControlPointAt", &PyDbSpline::setControlPointAt, DS.ARGS({ "idx:int","pnt:PyGe.Point3d" }, 8755))
        .def("numFitPoints", &PyDbSpline::numFitPoints, DS.ARGS(8750))
        .def("getFitPointAt", &PyDbSpline::getFitPointAt, DS.ARGS({ "idx:int" }, 8738))
        .def("setFitPointAt", &PyDbSpline::setFitPointAt, DS.ARGS({ "idx:int","pnt:PyGe.Point3d" }, 8757))
        .def("insertFitPointAt", &PyDbSpline::insertFitPointAt, DS.ARGS({ "idx:int","pnt:PyGe.Point3d" }, 8744))
        .def("removeFitPointAt", &PyDbSpline::removeFitPointAt, DS.ARGS({ "idx:int" }, 8754))
        .def("fitTolerance", &PyDbSpline::fitTolerance, DS.ARGS(8735))
        .def("setFitTol", &PyDbSpline::setFitTol, DS.ARGS({ "val : float" }, 8759))
        .def("getFitTangents", &PyDbSpline::getFitTangents, DS.ARGS(8739))
        .def("setFitTangents", &PyDbSpline::setFitTangents, DS.ARGS({ "start : PyGe.Vector3d","end : PyGe.Vector3d" }, 8758))
        .def("hasFitData", &PyDbSpline::hasFitData, DS.ARGS(8742))
        .def("getFitData", &PyDbSpline::getFitData, DS.ARGS(8737))
        .def("setFitData", &PyDbSpline::setFitData, DS.ARGS({ "fitPoints: list[PyGe.Point3d]","degree: int","fitTolerance: float","startTan : PyGe.Vector3d","endTan : PyGe.Vector3d" }, 8756))
        .def("getFitDataKnot", &PyDbSpline::getFitDataKnot, DS.ARGS())
        .def("setFitDataKnot", &PyDbSpline::setFitDataKnot1)
        .def("setFitDataKnot", &PyDbSpline::setFitDataKnot2)
        .def("setFitDataKnot", &PyDbSpline::setFitDataKnot3)
        .def("setFitDataKnot", &PyDbSpline::setFitDataKnot4, DS.OVRL(setFitDataKnotOverloads))
        .def("purgeFitData", &PyDbSpline::purgeFitData, DS.ARGS(8751))
        .def("updateFitData", &PyDbSpline::updateFitData, DS.ARGS(8766))
        .def("getNurbsData", &PyDbSpline::getNurbsData, DS.ARGS(8740))
        .def("setNurbsData", &PyDbSpline::setNurbsData1)
        .def("setNurbsData", &PyDbSpline::setNurbsData2, DS.OVRL(setNurbsDataOverloads, 8760))
        .def("weightAt", &PyDbSpline::weightAt, DS.ARGS({ "val : int" }, 8767))
        .def("insertKnot", &PyDbSpline::insertKnot, DS.ARGS({ "val : float" }, 8745))
        .def("getOffsetCurvesGivenPlaneNormal", &PyDbSpline::getOffsetCurvesGivenPlaneNormal, DS.ARGS({ "normal: PyGe.Vector3d", "dist: float" }, 8741))
        .def("toPolyline", &PyDbSpline::toPolyline, DS.ARGS(8764))
        .def("insertControlPointAt", &PyDbSpline::insertControlPointAt1)
        .def("insertControlPointAt", &PyDbSpline::insertControlPointAt2, DS.OVRL(insertControlPointAtOverloads, 8743))
        .def("removeControlPointAt", &PyDbSpline::removeControlPointAt, DS.ARGS({ "val : int" }, 8753))
        .def("type", &PyDbSpline::type, DS.ARGS(8765))
        .def("setType", &PyDbSpline::setType, DS.ARGS({ "val: PyDb.SplineType" }, 8761))
        .def("rebuild", &PyDbSpline::rebuild, DS.ARGS({ "degree: int","numPnts: int" }, 8752))
        .def("className", &PyDbSpline::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbSpline::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyDbSpline::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbSpline::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyDbSpline::PyDbSpline()
    : PyDbCurve(new AcDbSpline(), true)
{
}

PyDbSpline::PyDbSpline(AcDbSpline* ptr, bool autoDelete)
    : PyDbCurve(ptr, autoDelete)
{
}

PyDbSpline::PyDbSpline(const PyDbObjectId& id)
    : PyDbCurve(openAcDbObject<AcDbSpline>(id, AcDb::kForRead), false)
{
}

PyDbSpline::PyDbSpline(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbCurve(openAcDbObject<AcDbSpline>(id, mode), false)
{
}

PyDbSpline::PyDbSpline(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbCurve(openAcDbObject<AcDbSpline>(id, mode, erased), false)
{
}

PyDbSpline::PyDbSpline(const boost::python::list& fitPoints)
    : PyDbSpline(new AcDbSpline(PyListToPoint3dArray(fitPoints)), true)
{
}

PyDbSpline::PyDbSpline(const boost::python::list& fitPoints,
    int order, double fitTolerance)
    : PyDbSpline(new AcDbSpline(PyListToPoint3dArray(fitPoints),
        order, fitTolerance), true)
{
}

PyDbSpline::PyDbSpline(const boost::python::list& fitPoints,
    const AcGeVector3d& startTangent, const AcGeVector3d& endTangent)
    : PyDbSpline(new AcDbSpline(PyListToPoint3dArray(fitPoints),
        startTangent, endTangent), true)
{
}

PyDbSpline::PyDbSpline(const boost::python::list& fitPoints,
    const AcGeVector3d& startTangent, const AcGeVector3d& endTangent, int order, double fitTolerance)
    : PyDbSpline(new AcDbSpline(PyListToPoint3dArray(fitPoints),
        startTangent, endTangent, order, fitTolerance), true)
{
}
PyDbSpline::PyDbSpline(const boost::python::list& fitPoints, bool periodic)
    : PyDbSpline(new AcDbSpline(PyListToPoint3dArray(fitPoints), periodic), true)
{
}

PyDbSpline::PyDbSpline(const boost::python::list& fitPoints, bool periodic, AcGe::KnotParameterization knotParam, int degree, double fitTolerance)
#if !defined(_BRXTARGET260)
    : PyDbSpline(new AcDbSpline(PyListToPoint3dArray(fitPoints), periodic, knotParam, degree, fitTolerance), true)
#else
    : PyDbSpline(nullptr, true)
#endif
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#endif
}

PyDbSpline::PyDbSpline(const boost::python::list& fitPoints, AcGe::KnotParameterization knotParam)
    : PyDbSpline(new AcDbSpline(PyListToPoint3dArray(fitPoints), knotParam), true)
{
}

PyDbSpline::PyDbSpline(const boost::python::list& fitPoints,
    AcGe::KnotParameterization knotParam, int degree, double fitTolerance)
    : PyDbSpline(new AcDbSpline(PyListToPoint3dArray(fitPoints), knotParam,
        degree, fitTolerance), true)
{
}

PyDbSpline::PyDbSpline(const boost::python::list& fitPoints, const AcGeVector3d& startTangent,
    const AcGeVector3d& endTangent, AcGe::KnotParameterization knotParam)
    : PyDbSpline(new AcDbSpline(PyListToPoint3dArray(fitPoints), startTangent,
        endTangent, knotParam), true)
{
}

PyDbSpline::PyDbSpline(const boost::python::list& fitPoints, const AcGeVector3d& startTangent,
    const AcGeVector3d& endTangent, AcGe::KnotParameterization knotParam, int degree, double fitTolerance)
    : PyDbSpline(new AcDbSpline(PyListToPoint3dArray(fitPoints), startTangent,
        endTangent, knotParam, degree, fitTolerance), true)
{
}

PyDbSpline::PyDbSpline(int degree, Adesk::Boolean rational, Adesk::Boolean closed, Adesk::Boolean periodic,
    const boost::python::list& controlPoints, const boost::python::list& knots, const boost::python::list& weights)
    : PyDbSpline(new AcDbSpline(degree, rational, closed, periodic,
        PyListToPoint3dArray(controlPoints), PyListToDoubleArray(knots), PyListToDoubleArray(weights)), true)
{
}

PyDbSpline::PyDbSpline(int degree, Adesk::Boolean rational, Adesk::Boolean closed, Adesk::Boolean periodic,
    const boost::python::list& controlPoints, const boost::python::list& knots, const boost::python::list& weights, double controlPtTol, double knotTol)
    : PyDbSpline(new AcDbSpline(degree, rational, closed, periodic,
        PyListToPoint3dArray(controlPoints), PyListToDoubleArray(knots), PyListToDoubleArray(weights), controlPtTol, knotTol), true)
{
}

PyDbSpline::PyDbSpline(const AcGePoint3d& center, const AcGeVector3d& unitNormal,
    const AcGeVector3d& majorAxis, double radiusRatio)
    : PyDbSpline(new AcDbSpline(center, unitNormal,
        majorAxis, radiusRatio), true)
{
}

PyDbSpline::PyDbSpline(const AcGePoint3d& center, const AcGeVector3d& unitNormal,
    const AcGeVector3d& majorAxis, double radiusRatio, double startAngle, double endAngle)
    : PyDbSpline(new AcDbSpline(center, unitNormal,
        majorAxis, radiusRatio, startAngle, endAngle), true)
{
}

Adesk::Boolean PyDbSpline::isNull() const
{
    return impObj()->isNull();
}

Adesk::Boolean PyDbSpline::isRational() const
{
    return impObj()->isRational();
}

int PyDbSpline::degree() const
{
    return impObj()->degree();
}

void PyDbSpline::elevateDegree(int newDegree) const
{
    PyThrowBadEs(impObj()->elevateDegree(newDegree));
}

int PyDbSpline::numControlPoints() const
{
    return impObj()->numControlPoints();
}

AcGePoint3d PyDbSpline::getControlPointAt(int index) const
{
    AcGePoint3d point;
    PyThrowBadEs(impObj()->getControlPointAt(index, point));
    return point;
}

void PyDbSpline::setControlPointAt(int index, const AcGePoint3d& point) const
{
    PyThrowBadEs(impObj()->setControlPointAt(index, point));
}

int PyDbSpline::numFitPoints() const
{
    return impObj()->numFitPoints();
}

AcGePoint3d PyDbSpline::getFitPointAt(int index) const
{
    AcGePoint3d point;
    PyThrowBadEs(impObj()->getFitPointAt(index, point));
    return point;
}

void PyDbSpline::setFitPointAt(int index, const AcGePoint3d& point) const
{
    PyThrowBadEs(impObj()->setFitPointAt(index, point));
}

void PyDbSpline::insertFitPointAt(int index, const AcGePoint3d& point) const
{
    PyThrowBadEs(impObj()->insertFitPointAt(index, point));
}

void PyDbSpline::removeFitPointAt(int index) const
{
    PyThrowBadEs(impObj()->removeFitPointAt(index));
}

double PyDbSpline::fitTolerance() const
{
    return impObj()->fitTolerance();
}

void PyDbSpline::setFitTol(double tol) const
{
    PyThrowBadEs(impObj()->setFitTol(tol));
}

boost::python::tuple PyDbSpline::getFitTangents() const
{
    PyAutoLockGIL lock;
    AcGeVector3d startTangent;
    AcGeVector3d endTangent;
    PyThrowBadEs(impObj()->getFitTangents(startTangent, endTangent));
    return boost::python::make_tuple(startTangent, endTangent);
}

void PyDbSpline::setFitTangents(const AcGeVector3d& startTangent, const AcGeVector3d& endTangent) const
{
    PyThrowBadEs(impObj()->setFitTangents(startTangent, endTangent));
}

Adesk::Boolean PyDbSpline::hasFitData() const
{
    return impObj()->hasFitData();
}

boost::python::tuple PyDbSpline::getFitData() const
{
    PyAutoLockGIL lock;
    AcGePoint3dArray fitPoints;
    int degree;
    double fitTolerance;
    Adesk::Boolean tangentsExist;
    AcGeVector3d startTangent;
    AcGeVector3d endTangent;
    PyThrowBadEs(impObj()->getFitData(fitPoints, degree, fitTolerance, tangentsExist, startTangent, endTangent));
    return boost::python::make_tuple(Point3dArrayToPyList(fitPoints), degree, fitTolerance, tangentsExist, startTangent, endTangent);
}

void PyDbSpline::setFitData(const boost::python::list& fitPoints, int degree, double fitTolerance, const AcGeVector3d& startTangent, const AcGeVector3d& endTangent) const
{
    PyThrowBadEs(impObj()->setFitData(PyListToPoint3dArray(fitPoints), degree, fitTolerance, startTangent, endTangent));
}

boost::python::tuple PyDbSpline::getFitDataKnot() const
{
    AcGePoint3dArray fitPoints;
    Adesk::Boolean tangentsExist;
    AcGeVector3d startTangent;
    AcGeVector3d endTangent;
    AcGe::KnotParameterization knotParam;
    int degree;
    double fitTolerance;
    PyThrowBadEs(impObj()->getFitData(fitPoints, tangentsExist, startTangent, endTangent, knotParam, degree, fitTolerance));
    return boost::python::make_tuple(Point3dArrayToPyList(fitPoints), tangentsExist, startTangent, endTangent, knotParam, degree, fitTolerance);
}

void PyDbSpline::setFitDataKnot1(const boost::python::list& fitPoints, const AcGeVector3d& startTangent, const AcGeVector3d& endTangent, AcGe::KnotParameterization knotParam) const
{
    PyThrowBadEs(impObj()->setFitData(PyListToPoint3dArray(fitPoints), startTangent, endTangent, knotParam));
}

void PyDbSpline::setFitDataKnot2(const boost::python::list& fitPoints, const AcGeVector3d& startTangent, const AcGeVector3d& endTangent, AcGe::KnotParameterization knotParam, int degree, double fitTolerance) const
{
    PyThrowBadEs(impObj()->setFitData(PyListToPoint3dArray(fitPoints), startTangent, endTangent, knotParam, degree, fitTolerance));
}

void PyDbSpline::setFitDataKnot3(const boost::python::list& fitPoints, bool isPeriodic, AcGe::KnotParameterization knotParam) const
{
    PyThrowBadEs(impObj()->setFitData(PyListToPoint3dArray(fitPoints), isPeriodic, knotParam));
}

void PyDbSpline::setFitDataKnot4(const boost::python::list& fitPoints, bool isPeriodic, AcGe::KnotParameterization knotParam, int degree, double fitTolerance) const
{
    PyThrowBadEs(impObj()->setFitData(PyListToPoint3dArray(fitPoints), isPeriodic, knotParam, degree, fitTolerance));
}

void PyDbSpline::purgeFitData() const
{
    PyThrowBadEs(impObj()->purgeFitData());
}

void PyDbSpline::updateFitData() const
{
    PyThrowBadEs(impObj()->updateFitData());
}

boost::python::tuple PyDbSpline::getNurbsData() const
{
    int degree;
    Adesk::Boolean rational;
    Adesk::Boolean closed;
    Adesk::Boolean periodic;
    AcGePoint3dArray controlPoints;
    AcGeDoubleArray knots;
    AcGeDoubleArray weights;
    double controlPtTol;
    double knotTol;
    PyThrowBadEs(impObj()->getNurbsData(degree, rational, closed, periodic, controlPoints, knots, weights, controlPtTol, knotTol));
    return boost::python::make_tuple(
        degree,
        rational,
        closed,
        periodic,
        Point3dArrayToPyList(controlPoints),
        DoubleArrayToPyList(knots),
        DoubleArrayToPyList(weights),
        controlPtTol,
        knotTol);
}

void PyDbSpline::setNurbsData1(int degree, Adesk::Boolean rational, Adesk::Boolean closed, Adesk::Boolean periodic,
    const boost::python::list& controlPoints, const boost::python::list& knots, const boost::python::list& weights) const
{
    auto _controlPoints = PyListToPoint3dArray(controlPoints);
    auto _knots = PyListToDoubleArray(knots);
    auto _weights = PyListToDoubleArray(knots);
    PyThrowBadEs(impObj()->setNurbsData(degree, rational, closed, periodic, _controlPoints, _knots, _weights));
}

void PyDbSpline::setNurbsData2(int degree, Adesk::Boolean rational, Adesk::Boolean closed, Adesk::Boolean periodic,
    const boost::python::list& controlPoints, const boost::python::list& knots, const boost::python::list& weights, double controlPtTol, double knotTol) const
{
    auto _controlPoints = PyListToPoint3dArray(controlPoints);
    auto _knots = PyListToDoubleArray(knots);
    auto _weights = PyListToDoubleArray(knots);
    PyThrowBadEs(impObj()->setNurbsData(degree, rational, closed, periodic, _controlPoints, _knots, _weights, controlPtTol, knotTol));
}

double PyDbSpline::weightAt(int index) const
{
    return impObj()->weightAt(index);
}

void PyDbSpline::setWeightAt(int index, double weight) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(impObj()->setWeightAt(index, weight));
#endif
}

void PyDbSpline::insertKnot(double param) const
{
    PyThrowBadEs(impObj()->insertKnot(param));
}

boost::python::list PyDbSpline::getOffsetCurvesGivenPlaneNormal(const AcGeVector3d& normal, double offsetDist) const
{
    PyAutoLockGIL lock;
    boost::python::list pylist;
    AcDbVoidPtrArray offsetCurves;
    PyThrowBadEs(impObj()->getOffsetCurvesGivenPlaneNormal(normal, offsetDist, offsetCurves));
    for (auto item : offsetCurves)
        pylist.append(PyDbCurve((AcDbCurve*)item, true));
    return pylist;
}

PyDbPolyline PyDbSpline::toPolyline() const
{
    AcDbCurve* pCurve = nullptr;
    PyThrowBadEs(impObj()->toPolyline(pCurve));
    return PyDbPolyline(static_cast<AcDbPolyline*>(pCurve), true);
}

void PyDbSpline::insertControlPointAt1(double knotParam, const AcGePoint3d& ctrlPt) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(impObj()->insertControlPointAt(knotParam, ctrlPt));
#endif
}

void PyDbSpline::insertControlPointAt2(double knotParam, const AcGePoint3d& ctrlPt, double weight) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(impObj()->insertControlPointAt(knotParam, ctrlPt, weight));
#endif
}

void PyDbSpline::removeControlPointAt(int index) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(impObj()->removeControlPointAt(index));
#endif
}

SplineType PyDbSpline::type() const
{
    return impObj()->type();
}

void PyDbSpline::setType(SplineType type) const
{
    PyThrowBadEs(impObj()->setType(type));
}

void PyDbSpline::rebuild(int degree, int numCtrlPts) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(impObj()->rebuild(degree, numCtrlPts));
#endif
}

PyGeNurbCurve3d PyDbSpline::getAcGeCurve1() const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    AcGeCurve3d* pGeCurve = nullptr;
    PyThrowBadEs(impObj()->getAcGeCurve(pGeCurve));
    return PyGeNurbCurve3d(pGeCurve);
#endif
}

PyGeNurbCurve3d PyDbSpline::getAcGeCurve2(const AcGeTol& tol) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    AcGeCurve3d* pGeCurve = nullptr;
    PyThrowBadEs(impObj()->getAcGeCurve(pGeCurve, tol));
    return PyGeNurbCurve3d(pGeCurve);
#endif
}

std::string PyDbSpline::className()
{
    return "AcDbSpline";
}

PyRxClass PyDbSpline::desc()
{
    return PyRxClass(AcDbSpline::desc(), false);
}

PyDbSpline PyDbSpline::cloneFrom(const PyRxObject& src)
{
    return PyDbObjectCloneFrom<PyDbSpline, AcDbSpline>(src);
}

PyDbSpline PyDbSpline::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbSpline>(src);
}

AcDbSpline* PyDbSpline::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbSpline*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//PyDbHelix
void makePyDbHelixWrapper()
{
    PyDocString DS("Helix");
    class_<PyDbHelix, bases<PyDbSpline>>("Helix")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>(DS.ARGS({ "id: PyDb.ObjectId", "mode: PyDb.OpenMode=PyDb.OpenMode.kForRead" })))
        .def("createHelix", &PyDbHelix::createHelix, DS.ARGS())
        .def("axisPoint", &PyDbHelix::axisPoint, DS.ARGS())
        .def("setAxisPoint", &PyDbHelix::setAxisPoint1)
        .def("setAxisPoint", &PyDbHelix::setAxisPoint2, DS.ARGS({ "axisPoint : PyGe.Point3d", "bMoveStartPoint : bool = True" }))
        .def("startPoint", &PyDbHelix::startPoint, DS.ARGS())
        .def("setStartPoint", &PyDbHelix::setStartPoint, DS.ARGS({ "val : PyGe.Point3d" }))
        .def("axisVector", &PyDbHelix::axisVector, DS.ARGS())
        .def("setAxisVector", &PyDbHelix::setAxisVector, DS.ARGS({ "val : PyGe.Vector3d" }))
        .def("height", &PyDbHelix::height, DS.ARGS())
        .def("setHeight", &PyDbHelix::setHeight, DS.ARGS({ "val : float" }))
        .def("baseRadius", &PyDbHelix::baseRadius, DS.ARGS())
        .def("setBaseRadius", &PyDbHelix::setBaseRadius, DS.ARGS({ "val : float" }))
        .def("topRadius", &PyDbHelix::topRadius, DS.ARGS())
        .def("setTopRadius", &PyDbHelix::setTopRadius, DS.ARGS({ "val : float" }))
        .def("turns", &PyDbHelix::turns, DS.ARGS())
        .def("setTurns", &PyDbHelix::setTurns, DS.ARGS({ "val : float" }))
        .def("turnHeight", &PyDbHelix::turnHeight, DS.ARGS())
        .def("setTurnHeight", &PyDbHelix::setTurnHeight, DS.ARGS({ "val : float" }))
        .def("twist", &PyDbHelix::twist, DS.ARGS())
        .def("setTwist", &PyDbHelix::setTwist, DS.ARGS({ "val : bool" }))
        .def("constrain", &PyDbHelix::constrain, DS.ARGS())
        .def("setConstrain", &PyDbHelix::setConstrain, DS.ARGS({ "val : PyDb.HelixConstrainType" }))
        .def("turnSlope", &PyDbHelix::turnSlope, DS.ARGS())
        .def("totalLength", &PyDbHelix::totalLength, DS.ARGS())
        .def("reverseCurve", &PyDbHelix::reverseCurve, DS.ARGS())
        .def("className", &PyDbHelix::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbHelix::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyDbHelix::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbHelix::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;

    enum_<AcDbHelix::ConstrainType>("HelixConstrainType")
        .value("kTurnHeight", AcDbHelix::ConstrainType::kTurnHeight)
        .value("kTurns", AcDbHelix::ConstrainType::kTurns)
        .value("kHeight", AcDbHelix::ConstrainType::kHeight)
        .export_values()
        ;
}

PyDbHelix::PyDbHelix()
    : PyDbHelix(new AcDbHelix(), true)
{
}

PyDbHelix::PyDbHelix(AcDbHelix* ptr, bool autoDelete)
    : PyDbSpline(ptr, autoDelete)
{
}

PyDbHelix::PyDbHelix(const PyDbObjectId& id)
    : PyDbHelix(id, AcDb::kForRead)
{
}

PyDbHelix::PyDbHelix(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbHelix(openAcDbObject<AcDbHelix>(id, mode), false)
{
}

void PyDbHelix::createHelix() const
{
    PyThrowBadEs(impObj()->createHelix());
}

AcGePoint3d PyDbHelix::axisPoint() const
{
    return impObj()->axisPoint();
}

void PyDbHelix::setAxisPoint1(const AcGePoint3d& axisPoint) const
{
    PyThrowBadEs(impObj()->setAxisPoint(axisPoint));
}

void PyDbHelix::setAxisPoint2(const AcGePoint3d& axisPoint, const bool bMoveStartPoint) const
{
    PyThrowBadEs(impObj()->setAxisPoint(axisPoint, bMoveStartPoint));
}

AcGePoint3d PyDbHelix::startPoint() const
{
    return impObj()->startPoint();
}

void PyDbHelix::setStartPoint(const AcGePoint3d& startPoint) const
{
    PyThrowBadEs(impObj()->setStartPoint(startPoint));
}

AcGeVector3d PyDbHelix::axisVector() const
{
    return impObj()->axisVector();
}

void PyDbHelix::setAxisVector(const AcGeVector3d& axisVector) const
{
    PyThrowBadEs(impObj()->setAxisVector(axisVector));
}

double PyDbHelix::height() const
{
    return impObj()->height();
}

void PyDbHelix::setHeight(double dHeight) const
{
    PyThrowBadEs(impObj()->setHeight(dHeight));
}

double PyDbHelix::baseRadius() const
{
    return impObj()->baseRadius();
}

void PyDbHelix::setBaseRadius(double dRadius) const
{
    PyThrowBadEs(impObj()->setBaseRadius(dRadius));
}

double PyDbHelix::topRadius() const
{
    return impObj()->topRadius();
}

void PyDbHelix::setTopRadius(double dRadius) const
{
    PyThrowBadEs(impObj()->setTopRadius(dRadius));
}

double PyDbHelix::turns() const
{
    return impObj()->turns();
}

void PyDbHelix::setTurns(double dTurns) const
{
    PyThrowBadEs(impObj()->setTurns(dTurns));
}

double PyDbHelix::turnHeight() const
{
    return impObj()->turnHeight();
}

void PyDbHelix::setTurnHeight(double dTurnHeight) const
{
    PyThrowBadEs(impObj()->setTurnHeight(dTurnHeight));
}

Adesk::Boolean PyDbHelix::twist() const
{
    return impObj()->twist();
}

void PyDbHelix::setTwist(Adesk::Boolean bTwist) const
{
    PyThrowBadEs(impObj()->setTwist(bTwist));
}

AcDbHelix::ConstrainType PyDbHelix::constrain() const
{
    return impObj()->constrain();
}

void PyDbHelix::setConstrain(AcDbHelix::ConstrainType constrain) const
{
    PyThrowBadEs(impObj()->setConstrain(constrain));
}

double PyDbHelix::turnSlope() const
{
    return impObj()->turnSlope();
}

double PyDbHelix::totalLength() const
{
    return impObj()->totalLength();
}

void PyDbHelix::reverseCurve() const
{
    PyThrowBadEs(impObj()->reverseCurve());
}

std::string PyDbHelix::className()
{
    return "AcDbSpline";
}

PyRxClass PyDbHelix::desc()
{
    return PyRxClass(AcDbHelix::desc(), false);
}

PyDbHelix PyDbHelix::cloneFrom(const PyRxObject& src)
{
    return PyDbObjectCloneFrom<PyDbHelix, AcDbHelix>(src);
}

PyDbHelix PyDbHelix::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbHelix>(src);
}

AcDbHelix* PyDbHelix::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbHelix*>(m_pyImp.get());
}
