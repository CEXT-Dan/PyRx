#include "stdafx.h"
#include "PyGeCurve2d.h"
#include "PyGeInterval.h"
#include "PyGePointEnt2d.h"
#include "PyGeLinearEnt2d.h"
#include "PyGeBoundBlock2d.h"
using namespace boost::python;
//-----------------------------------------------------------------------------------------
//PyGeCurve2d wrapper
void makePyGeCurve2dWrapper()
{
    constexpr const std::string_view  getSamplePointsOverloads = "Overloads:\n"
        "- numSample: int\n"
        "- fromParam: float, toParam: float, approxEps: float\n";

    PyDocString DS("Curve2d");
    class_<PyGeCurve2d, bases<PyGeEntity2d>>("Curve2d", boost::python::no_init)
        .def("getInterval", &PyGeCurve2d::getInterval, DS.ARGS())
        .def("getStartPoint", &PyGeCurve2d::getStartPoint, DS.ARGS())
        .def("getEndPoint", &PyGeCurve2d::getEndPoint, DS.ARGS())
        .def("reverseParam", &PyGeCurve2d::reverseParam, DS.ARGS())
        .def("setInterval", &PyGeCurve2d::setInterval1)
        .def("setInterval", &PyGeCurve2d::setInterval2, DS.ARGS({ "val : PyGe.Interval = ..." }))
        .def("distanceTo", &PyGeCurve2d::distanceTo1)
        .def("distanceTo", &PyGeCurve2d::distanceTo2)
        .def("distanceTo", &PyGeCurve2d::distanceTo3)
        .def("distanceTo", &PyGeCurve2d::distanceTo4, DS.ARGS({ "pt : PyGe.Point2d | PyGe.Curve2d","tol : PyGe.Tol = ..." }))
        .def("closestPointTo", &PyGeCurve2d::closestPointTo1)
        .def("closestPointTo", &PyGeCurve2d::closestPointTo2)
        .def("closestPointTo", &PyGeCurve2d::closestPointTo3)
        .def("closestPointTo", &PyGeCurve2d::closestPointTo4, DS.ARGS({ "other : PyGe.Point2d | PyGe.Curve2d","tol : PyGe.Tol = ..." }))
        .def("getClosestPointTo", &PyGeCurve2d::getClosestPointTo1)
        .def("getClosestPointTo", &PyGeCurve2d::getClosestPointTo2, DS.ARGS({ "other : PyGe.Point2d","tol : PyGe.Tol = ..." }))
        .def("getClosestPointsTo", &PyGeCurve2d::getClosestPointsTo1)
        .def("getClosestPointsTo", &PyGeCurve2d::getClosestPointsTo2, DS.ARGS({ "other : PyGe.Curve2d","tol : PyGe.Tol = ..." }))
        .def("getNormalPoint", &PyGeCurve2d::getNormalPoint1)
        .def("getNormalPoint", &PyGeCurve2d::getNormalPoint2, DS.ARGS({ "pnt : PyGe.Point2d","tol : PyGe.Tol = ..." }))
        .def("isOn", &PyGeCurve2d::isOn1)
        .def("isOn", &PyGeCurve2d::isOn2)
        .def("isOn", &PyGeCurve2d::isOn3)
        .def("isOn", &PyGeCurve2d::isOn4, DS.ARGS({ "pt : float | PyGe.Point2d","tol : PyGe.Tol = ..." }))
        .def("paramOf", &PyGeCurve2d::paramOf1)
        .def("paramOf", &PyGeCurve2d::paramOf2, DS.ARGS({ "pt : PyGe.Point2d","tol : PyGe.Tol = ..." }))
        .def("getTrimmedOffset", &PyGeCurve2d::getTrimmedOffset1)
        .def("getTrimmedOffset", &PyGeCurve2d::getTrimmedOffset2, DS.ARGS({ "dist : float","extensionType : PyGe.OffsetCrvExtType","tol : PyGe.Tol = ..." }))
        .def("isClosed", &PyGeCurve2d::isClosed1)
        .def("isClosed", &PyGeCurve2d::isClosed2, DS.ARGS({ "tol : PyGe.Tol = ..." }))
        .def("isPeriodic", &PyGeCurve2d::isPeriodic, DS.ARGS())
        .def("isLinear", &PyGeCurve2d::isLinear1)
        .def("isLinear", &PyGeCurve2d::isLinear2, DS.ARGS({ "tol : PyGe.Tol = ..." }))
        .def("length", &PyGeCurve2d::length1)
        .def("length", &PyGeCurve2d::length2, DS.ARGS({ "frm : float", "to : float", "tol : float = ..." }))
        .def("paramAtLength", &PyGeCurve2d::paramAtLength1)
        .def("paramAtLength", &PyGeCurve2d::paramAtLength2, DS.ARGS({ "datumParam: float", "length: float","posParamDir: bool=True", "tol: float = ..." }))
        .def("area", &PyGeCurve2d::area1)
        .def("area", &PyGeCurve2d::area2, DS.ARGS({ "startParam : float", "endParam : float", "tol : float = ..." }))
        .def("isDegenerate", &PyGeCurve2d::isDegenerate1)
        .def("isDegenerate", &PyGeCurve2d::isDegenerate2, DS.ARGS({ "tol : PyGe.Tol = ..." }))
        .def("explode", &PyGeCurve2d::explode1)
        .def("explode", &PyGeCurve2d::explode2, DS.ARGS({ "val : PyGe.Interval = ..." }))
        .def("boundBlock", &PyGeCurve2d::boundBlock1)
        .def("boundBlock", &PyGeCurve2d::boundBlock2, DS.ARGS({ "range : PyGe.Interval = ..." }))
        .def("orthoBoundBlock", &PyGeCurve2d::orthoBoundBlock1)
        .def("orthoBoundBlock", &PyGeCurve2d::orthoBoundBlock2, DS.ARGS({ "range : PyGe.Interval = ..." }))
        .def("hasStartPoint", &PyGeCurve2d::hasStartPoint, DS.ARGS())
        .def("hasEndPoint", &PyGeCurve2d::hasEndPoint, DS.ARGS())
        .def("evalPoint", &PyGeCurve2d::evalPoint1)
        .def("evalPoint", &PyGeCurve2d::evalPoint2, DS.ARGS({ "param : float","numDeriv : int = 1" }))
        .def("getSamplePoints", &PyGeCurve2d::getSamplePoints1)
        .def("getSamplePoints", &PyGeCurve2d::getSamplePoints2, DS.OVRL(getSamplePointsOverloads))
        .def("getSplitCurves", &PyGeCurve2d::getSplitCurves, DS.ARGS({ "param : float" }))
        .def("cast", &PyGeCurve2d::cast, DS.SARGS({ "otherObject: PyGe.Curve2d" })).staticmethod("cast")
        .def("copycast", &PyGeCurve2d::copycast, DS.SARGS({ "otherObject: PyGe.Curve2d" })).staticmethod("copycast")
        .def("className", &PyGeCurve2d::className, DS.SARGS()).staticmethod("className")
        ;
}

PyGeCurve2d::PyGeCurve2d(AcGeEntity2d* pEnt)
    : PyGeEntity2d(pEnt)
{
}

PyGeCurve2d::PyGeCurve2d(const AcGeEntity2d* pEnt)
    : PyGeEntity2d(pEnt)
{
}

PyGeInterval PyGeCurve2d::getInterval() const
{
    AcGeInterval iv;
    impObj()->getInterval(iv);
    return PyGeInterval(iv);
}

AcGePoint2d PyGeCurve2d::getStartPoint() const
{
    AcGeInterval iv;
    AcGePoint2d s, e;
    impObj()->getInterval(iv, s, e);
    return s;
}

AcGePoint2d PyGeCurve2d::getEndPoint() const
{
    AcGeInterval iv;
    AcGePoint2d s, e;
    impObj()->getInterval(iv, s, e);
    return e;
}

void PyGeCurve2d::reverseParam() const
{
    impObj()->reverseParam();
}

void PyGeCurve2d::setInterval1() const
{
    impObj()->setInterval();
}

Adesk::Boolean PyGeCurve2d::setInterval2(const PyGeInterval& intrvl) const
{
    return impObj()->setInterval(intrvl.imp);
}

double PyGeCurve2d::distanceTo1(const AcGePoint2d& pnt) const
{
    return impObj()->distanceTo(pnt);
}

double PyGeCurve2d::distanceTo2(const AcGePoint2d& pnt, const AcGeTol& tol) const
{
    return impObj()->distanceTo(pnt, tol);
}

double PyGeCurve2d::distanceTo3(const PyGeCurve2d& c) const
{
    return impObj()->distanceTo(*c.impObj());
}

double PyGeCurve2d::distanceTo4(const PyGeCurve2d& c, const AcGeTol& tol) const
{
    return impObj()->distanceTo(*c.impObj(), tol);
}

AcGePoint2d PyGeCurve2d::closestPointTo1(const AcGePoint2d& pnt) const
{
    return impObj()->closestPointTo(pnt);
}

AcGePoint2d PyGeCurve2d::closestPointTo2(const AcGePoint2d& pnt, const AcGeTol& tol) const
{
    return impObj()->closestPointTo(pnt, tol);
}

boost::python::tuple  PyGeCurve2d::closestPointTo3(const PyGeCurve2d& curve2d) const
{
    PyAutoLockGIL lock;
    AcGePoint2d pntOnOtherCrv;
    auto pnt = impObj()->closestPointTo(*curve2d.impObj(), pntOnOtherCrv);
    return make_tuple(pnt, pntOnOtherCrv);
}

boost::python::tuple  PyGeCurve2d::closestPointTo4(const PyGeCurve2d& curve2d, const AcGeTol& tol) const
{
    PyAutoLockGIL lock;
    AcGePoint2d pntOnOtherCrv;
    auto pnt = impObj()->closestPointTo(*curve2d.impObj(), pntOnOtherCrv, tol);
    return make_tuple(pnt, pntOnOtherCrv);
}

PyGePointOnCurve2d PyGeCurve2d::getClosestPointTo1(const AcGePoint2d& pnt) const
{
    AcGePointOnCurve2d curve;
    impObj()->getClosestPointTo(pnt, curve);
    return PyGePointOnCurve2d(curve);
}

PyGePointOnCurve2d PyGeCurve2d::getClosestPointTo2(const AcGePoint2d& pnt, const AcGeTol& tol) const
{
    AcGePointOnCurve2d curve;
    impObj()->getClosestPointTo(pnt, curve, tol);
    return PyGePointOnCurve2d(curve);
}

boost::python::tuple PyGeCurve2d::getClosestPointsTo1(const PyGeCurve2d& curve) const
{
    PyAutoLockGIL lock;
    AcGePointOnCurve2d curvea, curveb;
    impObj()->getClosestPointTo(*curve.impObj(), curvea, curveb);
    return make_tuple(PyGePointOnCurve2d(curvea), PyGePointOnCurve2d(curveb));
}

boost::python::tuple PyGeCurve2d::getClosestPointsTo2(const PyGeCurve2d& curve, const AcGeTol& tol) const
{
    PyAutoLockGIL lock;
    AcGePointOnCurve2d curvea, curveb;
    impObj()->getClosestPointTo(*curve.impObj(), curvea, curveb, tol);
    return make_tuple(PyGePointOnCurve2d(curvea), PyGePointOnCurve2d(curveb));
}

PyGePointOnCurve2d PyGeCurve2d::getNormalPoint1(const AcGePoint2d& pnt) const
{
    AcGePointOnCurve2d curve;
    if (auto flag = impObj()->getNormalPoint(pnt, curve); flag == false)
        throw PyErrorStatusException(eInvalidInput);
    return PyGePointOnCurve2d(curve);
}

PyGePointOnCurve2d PyGeCurve2d::getNormalPoint2(const AcGePoint2d& pnt, const AcGeTol& tol) const
{
    AcGePointOnCurve2d curve;
    if (auto flag = impObj()->getNormalPoint(pnt, curve, tol); flag == false)
        throw PyErrorStatusException(eInvalidInput);
    return PyGePointOnCurve2d(curve);
}

boost::python::tuple PyGeCurve2d::isOn1(const AcGePoint2d& pnt) const
{
    PyAutoLockGIL lock;
    double param = 0.0;
    auto res = impObj()->isOn(pnt, param);
    return boost::python::make_tuple(res, param);
}

boost::python::tuple PyGeCurve2d::isOn2(const AcGePoint2d& pnt, const AcGeTol& tol) const
{
    PyAutoLockGIL lock;
    double param = 0.0;
    auto res = impObj()->isOn(pnt, param, tol);
    return boost::python::make_tuple(res, param);
}

boost::python::tuple PyGeCurve2d::isOn3(double param) const
{
    return boost::python::make_tuple(impObj()->isOn(param));
}

boost::python::tuple PyGeCurve2d::isOn4(double param, const AcGeTol& tol) const
{
    return boost::python::make_tuple(impObj()->isOn(param, tol));
}

double PyGeCurve2d::paramOf1(const AcGePoint2d& pnt) const
{
    return impObj()->paramOf(pnt);
}

double PyGeCurve2d::paramOf2(const AcGePoint2d& pnt, const AcGeTol& tol) const
{
    return impObj()->paramOf(pnt, tol);
}

boost::python::list PyGeCurve2d::getTrimmedOffset1(double distance, AcGe::OffsetCrvExtType extensionType) const
{
    PyAutoLockGIL lock;
    boost::python::list curves;
    AcGeVoidPointerArray offsetCurveList;
    impObj()->getTrimmedOffset(distance, offsetCurveList, extensionType);
    for (const auto& item : offsetCurveList)
        curves.append(PyGeCurve2d(reinterpret_cast<AcGeCurve2d*>(item)));
    return curves;
}

boost::python::list PyGeCurve2d::getTrimmedOffset2(double distance, AcGe::OffsetCrvExtType extensionType, const AcGeTol& tol) const
{
    PyAutoLockGIL lock;
    boost::python::list curves;
    AcGeVoidPointerArray offsetCurveList;
    impObj()->getTrimmedOffset(distance, offsetCurveList, extensionType, tol);
    for (const auto& item : offsetCurveList)
        curves.append(PyGeCurve2d(reinterpret_cast<AcGeCurve2d*>(item)));
    return curves;
}

Adesk::Boolean PyGeCurve2d::isClosed1() const
{
    return impObj()->isClosed();
}

Adesk::Boolean PyGeCurve2d::isClosed2(const AcGeTol& tol) const
{
    return impObj()->isClosed(tol);
}

boost::python::tuple PyGeCurve2d::isPeriodic() const
{
    PyAutoLockGIL lock;
    double val = 0;
    bool flag = impObj()->isPeriodic(val);
    return boost::python::make_tuple(flag, val);
}

boost::python::tuple PyGeCurve2d::isLinear1() const
{
    PyAutoLockGIL lock;
    AcGeLine2d line;
    bool flag = impObj()->isLinear(line);
    return boost::python::make_tuple(flag, PyGeLine2d(line));
}

boost::python::tuple PyGeCurve2d::isLinear2(const AcGeTol& tol) const
{
    PyAutoLockGIL lock;
    AcGeLine2d line;
    bool flag = impObj()->isLinear(line, tol);
    return boost::python::make_tuple(flag, PyGeLine2d(line));
}

double PyGeCurve2d::length1(double fromParam, double toParam) const
{
    return impObj()->length(fromParam, toParam);
}

double PyGeCurve2d::length2(double fromParam, double toParam, double tol) const
{
    return impObj()->length(fromParam, toParam, tol);
}

double PyGeCurve2d::paramAtLength1(double datumParam, double length) const
{
    return impObj()->paramAtLength(datumParam, length);
}

double PyGeCurve2d::paramAtLength2(double datumParam, double length, Adesk::Boolean posParamDir, double tol) const
{
    return impObj()->paramAtLength(datumParam, length, posParamDir, tol);
}

double PyGeCurve2d::area1(double startParam, double endParam) const
{
    double length = 0;
    if (bool flag = impObj()->area(startParam, endParam, length); flag == false)
        throw PyErrorStatusException(eInvalidInput);
    return length;
}

double PyGeCurve2d::area2(double startParam, double endParam, const AcGeTol& tol) const
{
    double length = 0;
    if (bool flag = impObj()->area(startParam, endParam, length, tol); flag == false)
        throw PyErrorStatusException(eInvalidInput);
    return length;
}

boost::python::tuple PyGeCurve2d::isDegenerate1() const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    PyAutoLockGIL lock;
    AcGeEntity2d* pEnt = nullptr;
    bool flag = impObj()->isDegenerate(pEnt);
    return boost::python::make_tuple(flag, PyGeEntity2d(pEnt));
#endif
}

boost::python::tuple PyGeCurve2d::isDegenerate2(const AcGeTol& tol) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    PyAutoLockGIL lock;
    AcGeEntity2d* pEnt = nullptr;
    bool flag = impObj()->isDegenerate(pEnt, tol);
    return boost::python::make_tuple(flag, PyGeEntity2d(pEnt));
#endif
}

//TODO: Test ... leak... looks wonky?
boost::python::list PyGeCurve2d::explode1() const
{
    PyAutoLockGIL lock;
    boost::python::list curves;
    AcGeIntArray newExplodedCurve;
    AcGeVoidPointerArray explodedCurves;
    impObj()->explode(explodedCurves, newExplodedCurve);
    for (size_t idx = 0; idx < explodedCurves.length(); idx++)
    {
        AcGeCurve2d* pCurve = reinterpret_cast<AcGeCurve2d*>(explodedCurves[idx]);
        curves.append(PyGeCurve2d(pCurve->copy()));
        if (newExplodedCurve[idx] == 1)
            delete pCurve;
    }
    return curves;
}

//TODO: Test ... leak... looks wonky?
boost::python::list PyGeCurve2d::explode2(const PyGeInterval& interval) const
{
    PyAutoLockGIL lock;
    boost::python::list curves;
    AcGeIntArray newExplodedCurve;
    AcGeVoidPointerArray explodedCurves;
    impObj()->explode(explodedCurves, newExplodedCurve, &interval.imp);
    for (size_t idx = 0; idx < explodedCurves.length(); idx++)
    {
        AcGeCurve2d* pCurve = reinterpret_cast<AcGeCurve2d*>(explodedCurves[idx]);
        curves.append(PyGeCurve2d(pCurve->copy()));
        if (newExplodedCurve[idx] == 1)
            delete pCurve;
    }
    return curves;
}

PyGeBoundBlock2d PyGeCurve2d::boundBlock1() const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    return PyGeBoundBlock2d(impObj()->boundBlock().copy());
#endif
}

PyGeBoundBlock2d PyGeCurve2d::boundBlock2(const PyGeInterval& range) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    return PyGeBoundBlock2d(impObj()->boundBlock(range.imp).copy());
#endif
}

PyGeBoundBlock2d PyGeCurve2d::orthoBoundBlock1() const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    return PyGeBoundBlock2d(impObj()->orthoBoundBlock().copy());
#endif
}

PyGeBoundBlock2d PyGeCurve2d::orthoBoundBlock2(const PyGeInterval& range) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    return PyGeBoundBlock2d(impObj()->orthoBoundBlock(range.imp).copy());
#endif
}

bool PyGeCurve2d::hasStartPoint() const
{
    AcGePoint2d pnt;
    return impObj()->hasStartPoint(pnt);
}

bool PyGeCurve2d::hasEndPoint() const
{
    AcGePoint2d pnt;
    return impObj()->hasEndPoint(pnt);
}

AcGePoint2d PyGeCurve2d::evalPoint1(double param) const
{
    return impObj()->evalPoint(param);
}

boost::python::tuple PyGeCurve2d::evalPoint2(double param, int numDeriv) const
{
    PyAutoLockGIL lock;
    boost::python::list vecs;
    AcGeVector2dArray derivArray;
    AcGePoint2d pnt = impObj()->evalPoint(param, numDeriv, derivArray);
    for (const auto& item : derivArray)
        vecs.append(item);
    return boost::python::make_tuple(pnt, vecs);
}

boost::python::tuple PyGeCurve2d::getSamplePoints1(int numSample) const
{
    PyAutoLockGIL lock;
    AcGeDoubleArray paramArray;
    AcGePoint2dArray pointArray;
    impObj()->getSamplePoints(numSample, pointArray);

    AcGeTol tol;
    tol.setEqualPoint(0.0001);
    for (const auto& sp : pointArray)
        paramArray.append(impObj()->paramOf(sp, tol));
    return boost::python::make_tuple(Point2dArrayToPyList(pointArray), DoubleArrayToPyList(paramArray));
}

boost::python::tuple PyGeCurve2d::getSamplePoints2(double fromParam, double toParam, double approxEps) const
{
    PyAutoLockGIL lock;
    AcGeDoubleArray paramArray;
    AcGePoint2dArray pointArray;
    boost::python::list pointList;
    impObj()->getSamplePoints(fromParam, toParam, approxEps, pointArray, paramArray);
    return boost::python::make_tuple(Point2dArrayToPyList(pointArray), DoubleArrayToPyList(paramArray));
}

boost::python::tuple PyGeCurve2d::getSplitCurves(double param) const
{
    PyAutoLockGIL lock;
    AcGeCurve2d* p1 = nullptr;
    AcGeCurve2d* p2 = nullptr;
    impObj()->getSplitCurves(param, p1, p2);
    return make_tuple(PyGeCurve2d(p1), PyGeCurve2d(p2));
}

PyGeCurve2d PyGeCurve2d::cast(const PyGeEntity2d& src)
{
    return PyGeEntity2dCast<PyGeCurve2d, AcGeCurve2d>(src);
}

PyGeCurve2d PyGeCurve2d::copycast(const PyGeEntity2d& src)
{
    return PyGeCurve2d(static_cast<AcGeCurve2d*>(src.impObj()->copy()));
}

std::string PyGeCurve2d::className()
{
    return "AcGeCurve2d";
}

AcGeCurve2d* PyGeCurve2d::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_imp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcGeCurve2d*>(m_imp.get());
}

//-----------------------------------------------------------------------------------------
//AcGeCircArc2d wrapper
void makePyGeCircArc2dWrapper()
{
    constexpr const std::string_view ctor = "Overloads:\n"
        "- None: Any\n"
        "- cent: PyGe.Point2d, radius: float\n"
        "- cent: PyGe.Point2d, radius: float, startAngle: float, endAngle: float\n"
        "- cent: PyGe.Point2d, radius: float, startAngle: float, endAngle: float, refVec: PyGe.Vector2d, isClockWise: bool\n"
        "- startPoint: PyGe.Point2d, pnt: PyGe.Point2d, endPoint: PyGe.Point2d\n"
        "- startPoint: PyGe.Point2d, endPoint: PyGe.Point2d, bulge: float, bulgeFlag: bool\n";

    constexpr const std::string_view setOverloads = "Overloads:\n"
        "- cent: PyGe.Point2d, radius: float\n"
        "- cent: PyGe.Point2d, radius: float, startAngle: float, endAngle: float, refVec: PyGe.Vector2d, isClockWise: bool\n"
        "- startPoint: PyGe.Point2d, pnt: PyGe.Point2d, endPoint: PyGe.Point2d\n"
        "- startPoint: PyGe.Point2d, endPoint: PyGe.Point2d, bulge: float, bulgeFlag: bool\n"
        "- curve1: PyGe.Curve2d, curve2: PyGe.Curve2d, radius: float\n"
        "- curve1: PyGe.Curve2d, curve2: PyGe.Curve2d, curve3: PyGe.Curve2d\n";

    PyDocString DS("CircArc2d");
    class_<PyGeCircArc2d, bases<PyGeCurve2d>>("CircArc2d")
        .def(init<>())
        .def(init<const AcGePoint2d&, double>())
        .def(init<const AcGePoint2d&, double, double, double>())
        .def(init<const AcGePoint2d&, double, double, double, const AcGeVector2d&, bool>())
        .def(init<const AcGePoint2d&, const AcGePoint2d&, const AcGePoint2d&>())
        .def(init<const AcGePoint2d&, const AcGePoint2d&, double, bool>(DS.CTOR(ctor, 11716)))
        .def("intersectWith", &PyGeCircArc2d::intersectWith1)
        .def("intersectWith", &PyGeCircArc2d::intersectWith2)
        .def("intersectWith", &PyGeCircArc2d::intersectWith3)
        .def("intersectWith", &PyGeCircArc2d::intersectWith4, DS.ARGS({ "val: PyGe.CircArc2d | PyGe.LinearEnt2d", "tol: PyGe.Tol = ..." }))
        .def("tangent", &PyGeCircArc2d::tangent1)
        .def("tangent", &PyGeCircArc2d::tangent2, DS.ARGS({ "pt: PyGe.Point2d","tol: PyGe.Tol = ..." }))
        .def("isInside", &PyGeCircArc2d::isInside1)
        .def("isInside", &PyGeCircArc2d::isInside2, DS.ARGS({ "pt: PyGe.Point2d","tol: PyGe.Tol = ..." }))
        .def("center", &PyGeCircArc2d::center, DS.ARGS())
        .def("radius", &PyGeCircArc2d::radius, DS.ARGS())
        .def("startAng", &PyGeCircArc2d::startAng, DS.ARGS())
        .def("endAng", &PyGeCircArc2d::endAng, DS.ARGS())
        .def("isClockWise", &PyGeCircArc2d::isClockWise, DS.ARGS())
        .def("refVec", &PyGeCircArc2d::refVec, DS.ARGS())
        .def("startPoint", &PyGeCircArc2d::startPoint, DS.ARGS())
        .def("endPoint", &PyGeCircArc2d::endPoint, DS.ARGS())
        .def("setCenter", &PyGeCircArc2d::setCenter, DS.ARGS({ "pt: PyGe.Point2d" }))
        .def("setRadius", &PyGeCircArc2d::setRadius, DS.ARGS({ "val: float" }))
        .def("setAngles", &PyGeCircArc2d::setAngles, DS.ARGS({ "startAng: float","endAng: float" }))
        .def("setToComplement", &PyGeCircArc2d::setToComplement, DS.ARGS())
        .def("setRefVec", &PyGeCircArc2d::setRefVec, DS.ARGS())
        .def("set", &PyGeCircArc2d::set1)
        .def("set", &PyGeCircArc2d::set2)
        .def("set", &PyGeCircArc2d::set3)
        .def("set", &PyGeCircArc2d::set4)
        .def("set", &PyGeCircArc2d::set5)
        .def("set", &PyGeCircArc2d::set6, DS.OVRL(setOverloads))
        .def("cast", &PyGeCircArc2d::cast, DS.SARGS({ "otherObject: PyGe.Entity2d" })).staticmethod("cast")
        .def("copycast", &PyGeCircArc2d::copycast, DS.SARGS({ "otherObject: PyGe.Entity2d" })).staticmethod("copycast")
        .def("className", &PyGeCircArc2d::className, DS.SARGS()).staticmethod("className")
        ;
}

PyGeCircArc2d::PyGeCircArc2d()
    : PyGeCurve2d(new AcGeCircArc2d())
{
}

PyGeCircArc2d::PyGeCircArc2d(AcGeEntity2d* pEnt)
    : PyGeCurve2d(pEnt)
{
}

PyGeCircArc2d::PyGeCircArc2d(const AcGeCircArc2d& src)
    : PyGeCurve2d(new AcGeCircArc2d(src))
{
}

PyGeCircArc2d::PyGeCircArc2d(const AcGePoint2d& cent, double radius)
    : PyGeCurve2d(new AcGeCircArc2d(cent, radius))
{
}

PyGeCircArc2d::PyGeCircArc2d(const AcGePoint2d& cent, double radius, double startAngle, double endAngle)
    : PyGeCurve2d(new AcGeCircArc2d(cent, radius, startAngle, endAngle))
{
}

PyGeCircArc2d::PyGeCircArc2d(const AcGePoint2d& cent, double radius, double startAngle, double endAngle, const AcGeVector2d& refVec, Adesk::Boolean isClockWise)
    : PyGeCurve2d(new AcGeCircArc2d(cent, radius, startAngle, endAngle, refVec, isClockWise))
{
}

PyGeCircArc2d::PyGeCircArc2d(const AcGePoint2d& startPoint, const AcGePoint2d& point, const AcGePoint2d& endPoint)
    : PyGeCurve2d(new AcGeCircArc2d(startPoint, point, endPoint))
{
}

PyGeCircArc2d::PyGeCircArc2d(const AcGePoint2d& startPoint, const AcGePoint2d& endPoint, double bulge, bool bulgeFlag)
    : PyGeCurve2d(new AcGeCircArc2d(startPoint, endPoint, bulge, bulgeFlag))
{
}

boost::python::tuple PyGeCircArc2d::intersectWith1(const PyGeLinearEnt2d& line) const
{
    PyAutoLockGIL lock;
    int intn;
    AcGePoint2d p1, p2;
    bool flag = impObj()->intersectWith(*line.impObj(), intn, p1, p2);
    return make_tuple(flag, intn, p1, p2);
}

boost::python::tuple PyGeCircArc2d::intersectWith2(const PyGeLinearEnt2d& line, const AcGeTol& tol) const
{
    PyAutoLockGIL lock;
    int intn;
    AcGePoint2d p1, p2;
    bool flag = impObj()->intersectWith(*line.impObj(), intn, p1, p2, tol);
    return make_tuple(flag, intn, p1, p2);
}

boost::python::tuple PyGeCircArc2d::intersectWith3(const PyGeCircArc2d& arc) const
{
    PyAutoLockGIL lock;
    int intn;
    AcGePoint2d p1, p2;
    bool flag = impObj()->intersectWith(*arc.impObj(), intn, p1, p2);
    return make_tuple(flag, intn, p1, p2);
}

boost::python::tuple PyGeCircArc2d::intersectWith4(const PyGeCircArc2d& arc, const AcGeTol& tol) const
{
    PyAutoLockGIL lock;
    int intn;
    AcGePoint2d p1, p2;
    bool flag = impObj()->intersectWith(*arc.impObj(), intn, p1, p2, tol);
    return make_tuple(flag, intn, p1, p2);
}

boost::python::tuple PyGeCircArc2d::tangent1(const AcGePoint2d& pnt) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    PyAutoLockGIL lock;
    AcGeError err;
    AcGeLine2d line;
    bool flag = impObj()->tangent(pnt, line, AcGeContext::gTol, err);
    return make_tuple(flag, PyGeLine2d(line), err);
#endif
}

boost::python::tuple PyGeCircArc2d::tangent2(const AcGePoint2d& pnt, const AcGeTol& tol) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    PyAutoLockGIL lock;
    AcGeError err;
    AcGeLine2d line;
    bool flag = impObj()->tangent(pnt, line, tol, err);
    return make_tuple(flag, PyGeLine2d(line), err);
#endif
}

Adesk::Boolean PyGeCircArc2d::isInside1(const AcGePoint2d& pnt) const
{
    return impObj()->isInside(pnt);
}

Adesk::Boolean PyGeCircArc2d::isInside2(const AcGePoint2d& pnt, const AcGeTol& tol) const
{
    return impObj()->isInside(pnt, tol);
}

AcGePoint2d PyGeCircArc2d::center() const
{
    return impObj()->center();
}

double PyGeCircArc2d::radius() const
{
    return impObj()->radius();
}

double PyGeCircArc2d::startAng() const
{
    return impObj()->startAng();
}

double PyGeCircArc2d::endAng() const
{
    return impObj()->endAng();
}

Adesk::Boolean PyGeCircArc2d::isClockWise() const
{
    return impObj()->isClockWise();
}

AcGeVector2d PyGeCircArc2d::refVec() const
{
    return impObj()->refVec();
}

AcGePoint2d PyGeCircArc2d::startPoint() const
{
    return impObj()->startPoint();
}

AcGePoint2d PyGeCircArc2d::endPoint() const
{
    return impObj()->endPoint();
}

void PyGeCircArc2d::setCenter(const AcGePoint2d& cent) const
{
    impObj()->setCenter(cent);
}

void PyGeCircArc2d::setRadius(double radius) const
{
    impObj()->setRadius(radius);
}

void  PyGeCircArc2d::setAngles(double startAng, double endAng) const
{
    impObj()->setAngles(startAng, endAng);
}

void PyGeCircArc2d::setToComplement() const
{
    impObj()->setToComplement();
}

void PyGeCircArc2d::setRefVec(const AcGeVector2d& vec) const
{
    impObj()->setRefVec(vec);
}

void PyGeCircArc2d::set1(const AcGePoint2d& cent, double radius) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    impObj()->set(cent, radius);
#endif
}

void  PyGeCircArc2d::set2(const AcGePoint2d& cent, double radius, double ang1, double ang2, const AcGeVector2d& refVec, Adesk::Boolean isClockWise) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    impObj()->set(cent, radius, ang1, ang2, refVec, isClockWise);
#endif
}

void PyGeCircArc2d::set3(const AcGePoint2d& startPoint, const AcGePoint2d& pnt, const AcGePoint2d& endPoint) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    AcGeError err;
    impObj()->set(startPoint, pnt, endPoint, err);
    if (err != AcGe::kOk)
        throw PyErrorStatusException(eInvalidInput);
#endif
}

void PyGeCircArc2d::set4(const AcGePoint2d& startPoint, const AcGePoint2d& endPoint, double bulge, Adesk::Boolean bulgeFlag) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    impObj()->set(startPoint, endPoint, bulge, bulgeFlag);
#endif
}

void  PyGeCircArc2d::set5(const PyGeCurve2d& curve1, const PyGeCurve2d& curve2, double radius) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    double param1 = 0.0;
    double param2 = 0.0;
    Adesk::Boolean success = false;
    impObj()->set(*curve1.impObj(), *curve2.impObj(), radius, param1, param2, success);
    if (success == false)
        throw PyErrorStatusException(eInvalidInput);
#endif
}

void PyGeCircArc2d::set6(const PyGeCurve2d& curve1, const PyGeCurve2d& curve2, const PyGeCurve2d& curve3) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    double param1 = 0.0;
    double param2 = 0.0;
    double param3 = 0.0;
    Adesk::Boolean success = false;
    impObj()->set(*curve1.impObj(), *curve2.impObj(), *curve3.impObj(), param1, param2, param3, success);
    if (success == false)
        throw PyErrorStatusException(eInvalidInput);
#endif
}

PyGeCircArc2d PyGeCircArc2d::cast(const PyGeEntity2d& src)
{
    return PyGeEntity2dCast<PyGeCircArc2d, AcGeCircArc2d>(src);
}

PyGeCircArc2d PyGeCircArc2d::copycast(const PyGeEntity2d& src)
{
    return PyGeCircArc2d(static_cast<AcGeCircArc2d*>(src.impObj()->copy()));
}

std::string PyGeCircArc2d::className()
{
    return "AcGeCircArc2d";
}

AcGeCircArc2d* PyGeCircArc2d::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_imp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcGeCircArc2d*>(m_imp.get());
}

//----------------------------------------------------------------------------
//AcGeCircArc2d wrapper
void makePyGeEllipArc2Wrapper()
{
#if !defined(_BRXTARGET260)
    constexpr const std::string_view ctor = "Overloads:\n"
        "- None: Any\n"
        "- carc: PyGe.CircArc2d\n"
        "- cent: PyGe.Point2d, majorAxis: PyGe.Vector2d, minorAxis: PyGe.Vector2d, majorRadius: float,minorRadius: float\n"
        "- cent: PyGe.Point2d, majorAxis: PyGe.Vector2d, minorAxis: PyGe.Vector2d, majorRadius: float,minorRadius: float, startAngle: float, endAngle: float\n";

    constexpr const std::string_view setOverloads = "Overloads:\n"
        "- carc: PyGe.CircArc2d,\n"
        "- cent: PyGe.Point2d, majorAxis: PyGe.Vector2d, minorAxis: PyGe.Vector2d, majorRadius: float,minorRadius: float\n"
        "- cent: PyGe.Point2d, majorAxis: PyGe.Vector2d, minorAxis: PyGe.Vector2d, majorRadius: float,minorRadius: float, startAngle: float, endAngle: float\n";

    PyDocString DS("EllipArc2d");
    class_<PyGeEllipArc2d, bases<PyGeCurve2d>>("EllipArc2d")
        .def(init<>())
        .def(init<const PyGeCircArc2d&>())
        .def(init<const AcGePoint2d&, const AcGeVector2d&, const AcGeVector2d&, double, double>())
        .def(init<const AcGePoint2d&, const AcGeVector2d&, const AcGeVector2d&, double, double, double, double>(DS.CTOR(ctor, 11974)))
        .def("intersectWith", &PyGeEllipArc2d::intersectWith1)
        .def("intersectWith", &PyGeEllipArc2d::intersectWith2, DS.ARGS({ "val: PyGe.LinearEnt2d",  "tol: PyGe.Tol = ..." }))
        .def("isCircular", &PyGeEllipArc2d::isCircular1)
        .def("isCircular", &PyGeEllipArc2d::isCircular2, DS.ARGS({ "tol: PyGe.Tol = ..." }))
        .def("isInside", &PyGeEllipArc2d::isInside1)
        .def("isInside", &PyGeEllipArc2d::isInside2, DS.ARGS({ "pt: PyGe.Point2d","tol: PyGe.Tol = ..." }))
        .def("center", &PyGeEllipArc2d::center, DS.ARGS())
        .def("minorRadius", &PyGeEllipArc2d::minorRadius, DS.ARGS())
        .def("majorRadius", &PyGeEllipArc2d::majorRadius, DS.ARGS())
        .def("minorAxis", &PyGeEllipArc2d::minorAxis, DS.ARGS())
        .def("majorAxis", &PyGeEllipArc2d::majorAxis, DS.ARGS())
        .def("startAng", &PyGeEllipArc2d::startAng, DS.ARGS())
        .def("endAng", &PyGeEllipArc2d::endAng, DS.ARGS())
        .def("startPoint", &PyGeEllipArc2d::startPoint, DS.ARGS())
        .def("endPoint", &PyGeEllipArc2d::endPoint, DS.ARGS())
        .def("isClockWise", &PyGeEllipArc2d::isClockWise, DS.ARGS())
        .def("setCenter", &PyGeEllipArc2d::setCenter, DS.ARGS({ "pt: PyGe.Point2d" }))
        .def("setMinorRadius", &PyGeEllipArc2d::setMinorRadius, DS.ARGS({ "val: float" }))
        .def("setMajorRadius", &PyGeEllipArc2d::setMajorRadius, DS.ARGS({ "val: float" }))
        .def("setAxes", &PyGeEllipArc2d::setAxes, DS.ARGS({ "majorAxis: PyGe.Vector2d","minorAxis: PyGe.Vector2d" }))
        .def("setAngles", &PyGeEllipArc2d::setAngles, DS.ARGS({ "startAngle: float","endAngle: float" }))
        .def("set", &PyGeEllipArc2d::set1)
        .def("set", &PyGeEllipArc2d::set2)
        .def("set", &PyGeEllipArc2d::set3, DS.OVRL(setOverloads))
        .def("cast", &PyGeEllipArc2d::cast, DS.SARGS({ "otherObject: PyGe.Entity2d" })).staticmethod("cast")
        .def("copycast", &PyGeEllipArc2d::copycast, DS.SARGS({ "otherObject: PyGe.Entity2d" })).staticmethod("copycast")
        .def("className", &PyGeEllipArc2d::className, DS.SARGS()).staticmethod("className")
        ;
#endif
}

#if !defined(_BRXTARGET260)
PyGeEllipArc2d::PyGeEllipArc2d()
    : PyGeCurve2d(new AcGeEllipArc2d())
{
}

PyGeEllipArc2d::PyGeEllipArc2d(AcGeEntity2d* pEnt)
    : PyGeCurve2d(pEnt)
{
}

PyGeEllipArc2d::PyGeEllipArc2d(const AcGeEllipArc2d& ell)
    : PyGeCurve2d(new AcGeEllipArc2d(ell))
{
}

PyGeEllipArc2d::PyGeEllipArc2d(const PyGeCircArc2d& arc)
    : PyGeCurve2d(new AcGeEllipArc2d(*arc.impObj()))
{
}

PyGeEllipArc2d::PyGeEllipArc2d(const AcGePoint2d& cent, const AcGeVector2d& majorAxis, const AcGeVector2d& minorAxis, double majorRadius, double minorRadius)
    : PyGeCurve2d(new AcGeEllipArc2d(cent, majorAxis, minorAxis, majorRadius, minorRadius))
{
}

PyGeEllipArc2d::PyGeEllipArc2d(const AcGePoint2d& cent, const AcGeVector2d& majorAxis, const AcGeVector2d& minorAxis, double majorRadius, double minorRadius, double startAngle, double endAngle)
    : PyGeCurve2d(new AcGeEllipArc2d(cent, majorAxis, minorAxis, majorRadius, minorRadius, startAngle, endAngle))
{
}

boost::python::tuple PyGeEllipArc2d::intersectWith1(const PyGeLinearEnt2d& line) const
{
    PyAutoLockGIL lock;
    int intn;
    AcGePoint2d p1, p2;
    bool flag = impObj()->intersectWith(*line.impObj(), intn, p1, p2);
    return make_tuple(flag, intn, p1, p2);
}

boost::python::tuple PyGeEllipArc2d::intersectWith2(const PyGeLinearEnt2d& line, const AcGeTol& tol) const
{
    PyAutoLockGIL lock;
    int intn;
    AcGePoint2d p1, p2;
    bool flag = impObj()->intersectWith(*line.impObj(), intn, p1, p2, tol);
    return make_tuple(flag, intn, p1, p2);
}

Adesk::Boolean PyGeEllipArc2d::isCircular1() const
{
    return impObj()->isCircular();
}

Adesk::Boolean PyGeEllipArc2d::isCircular2(const AcGeTol& tol) const
{
    return impObj()->isCircular(tol);
}

Adesk::Boolean PyGeEllipArc2d::isInside1(const AcGePoint2d& pnt) const
{
    return impObj()->isInside(pnt);
}

Adesk::Boolean PyGeEllipArc2d::isInside2(const AcGePoint2d& pnt, const AcGeTol& tol) const
{
    return impObj()->isInside(pnt, tol);
}

AcGePoint2d PyGeEllipArc2d::center() const
{
    return impObj()->center();
}

double PyGeEllipArc2d::minorRadius() const
{
    return impObj()->minorRadius();
}

double PyGeEllipArc2d::majorRadius() const
{
    return impObj()->majorRadius();
}

AcGeVector2d PyGeEllipArc2d::minorAxis() const
{
    return impObj()->minorAxis();
}

AcGeVector2d PyGeEllipArc2d::majorAxis() const
{
    return impObj()->majorAxis();
}

double PyGeEllipArc2d::startAng() const
{
    return impObj()->startAng();
}

double PyGeEllipArc2d::endAng() const
{
    return impObj()->endAng();
}

AcGePoint2d PyGeEllipArc2d::startPoint() const
{
    return impObj()->startPoint();
}

AcGePoint2d PyGeEllipArc2d::endPoint() const
{
    return impObj()->endPoint();
}

Adesk::Boolean PyGeEllipArc2d::isClockWise() const
{
    return impObj()->isClockWise();
}

void PyGeEllipArc2d::setCenter(const AcGePoint2d& cent) const
{
    impObj()->setCenter(cent);
}

void PyGeEllipArc2d::setMinorRadius(double rad) const
{
    impObj()->setMinorRadius(rad);
}

void PyGeEllipArc2d::setMajorRadius(double rad) const
{
    impObj()->setMajorRadius(rad);
}

void PyGeEllipArc2d::setAxes(const AcGeVector2d& majorAxis, const AcGeVector2d& minorAxis) const
{
    impObj()->setAxes(majorAxis, minorAxis);
}

void PyGeEllipArc2d::setAngles(double startAngle, double endAngle) const
{
    impObj()->setAngles(startAngle, endAngle);
}

void PyGeEllipArc2d::set1(const AcGePoint2d& cent, const AcGeVector2d& majorAxis, const AcGeVector2d& minorAxis, double majorRadius, double minorRadius) const
{
    impObj()->set(cent, majorAxis, minorAxis, majorRadius, minorRadius);
}

void PyGeEllipArc2d::set2(const AcGePoint2d& cent, const AcGeVector2d& majorAxis, const AcGeVector2d& minorAxis, double majorRadius, double minorRadius, double startAngle, double endAngle) const
{
    impObj()->set(cent, majorAxis, minorAxis, majorRadius, minorRadius, startAngle, endAngle);
}

void PyGeEllipArc2d::set3(const PyGeCircArc2d& arc) const
{
    impObj()->set(*arc.impObj());
}

PyGeEllipArc2d PyGeEllipArc2d::cast(const PyGeEntity2d& src)
{
    return PyGeEntity2dCast<PyGeEllipArc2d, AcGeEllipArc2d>(src);
}

PyGeEllipArc2d PyGeEllipArc2d::copycast(const PyGeEntity2d& src)
{
    return PyGeEllipArc2d(static_cast<AcGeEllipArc2d*>(src.impObj()->copy()));
}

std::string PyGeEllipArc2d::className()
{
    return "AcGeEllipArc2d";
}

AcGeEllipArc2d* PyGeEllipArc2d::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_imp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcGeEllipArc2d*>(m_imp.get());
}
#endif
//-----------------------------------------------------------------------------------------
//PyGeExternalCurve2d wrapper
void makePyGeExternalCurve2dWrapper()
{
#if !defined(_BRXTARGET260)
    PyDocString DS("ExternalCurve2d");
    class_<PyGeExternalCurve2d, bases<PyGeCurve2d>>("ExternalCurve2d", boost::python::no_init)
        .def("cast", &PyGeExternalCurve2d::cast, DS.SARGS({ "otherObject: PyGe.Entity2d" })).staticmethod("cast")
        .def("copycast", &PyGeExternalCurve2d::copycast, DS.SARGS({ "otherObject: PyGe.Entity2d" })).staticmethod("copycast")
        .def("className", &PyGeExternalCurve2d::className, DS.SARGS()).staticmethod("className")
        ;
#endif
}

#if !defined(_BRXTARGET260)
PyGeExternalCurve2d::PyGeExternalCurve2d(AcGeEntity2d* pEnt)
    : PyGeCurve2d(pEnt)
{
}

PyGeExternalCurve2d PyGeExternalCurve2d::cast(const PyGeEntity2d& src)
{
    return PyGeEntity2dCast<PyGeExternalCurve2d, AcGeExternalCurve2d>(src);
}

PyGeExternalCurve2d PyGeExternalCurve2d::copycast(const PyGeEntity2d& src)
{
    return PyGeExternalCurve2d(static_cast<AcGeExternalCurve2d*>(src.impObj()->copy()));
}

std::string PyGeExternalCurve2d::className()
{
    return "AcGeExternalCurve2d";
}

AcGeExternalCurve2d* PyGeExternalCurve2d::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_imp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcGeExternalCurve2d*>(m_imp.get());
}
#endif

//-----------------------------------------------------------------------------------------
//AcGeOffsetCurve2d wrapper
void makePyGeOffsetCurve2dWrapper()
{
#if !defined(_BRXTARGET260)
    PyDocString DS("OffsetCurve2d");
    class_<PyGeOffsetCurve2d, bases<PyGeCurve2d>>("OffsetCurve2d", boost::python::no_init)
        .def(init<const PyGeCurve2d&, double>(DS.ARGS({ "baseCurve: PyGe.Curve2d",  "offsetDistance: float" })))
        .def("cast", &PyGeOffsetCurve2d::cast, DS.SARGS({ "otherObject: PyGe.Entity2d" })).staticmethod("cast")
        .def("copycast", &PyGeOffsetCurve2d::copycast, DS.SARGS({ "otherObject: PyGe.Entity2d" })).staticmethod("copycast")
        .def("className", &PyGeOffsetCurve2d::className, DS.SARGS()).staticmethod("className")
        ;
#endif
}

#if !defined(_BRXTARGET260)
PyGeOffsetCurve2d::PyGeOffsetCurve2d(const PyGeCurve2d& baseCurve, double offsetDistance)
    : PyGeCurve2d(new AcGeOffsetCurve2d(*baseCurve.impObj(), offsetDistance))
{
}

PyGeOffsetCurve2d::PyGeOffsetCurve2d(AcGeEntity2d* pEnt)
    : PyGeCurve2d(pEnt)
{
}

PyGeOffsetCurve2d PyGeOffsetCurve2d::cast(const PyGeEntity2d& src)
{
    return PyGeEntity2dCast<PyGeOffsetCurve2d, AcGeOffsetCurve2d>(src);
}

PyGeOffsetCurve2d PyGeOffsetCurve2d::copycast(const PyGeEntity2d& src)
{
    return PyGeOffsetCurve2d(static_cast<AcGeOffsetCurve2d*>(src.impObj()->copy()));
}

std::string PyGeOffsetCurve2d::className()
{
    return "AcGeOffsetCurve2d";
}

AcGeOffsetCurve2d* PyGeOffsetCurve2d::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_imp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcGeOffsetCurve2d*>(m_imp.get());
}
#endif

//-----------------------------------------------------------------------------------------
//AcGeCompositeCurve2d wrapper
void makePyGeCompositeCurve2dWrapper()
{
    constexpr const std::string_view ctor = "Overloads:\n"
        "- None: Any\n"
        "- curveList: list[PyGe.Curve2d]\n"
        "- curveList: list[PyGe.Curve2d], isOwnerOfCurves: list[int]\n";

    constexpr const std::string_view setCurveListOverloads = "Overloads:\n"
        "- curveList: list[PyGe.Curve2d]\n"
        "- curveList: list[PyGe.Curve2d], isOwnerOfCurves: list[int]\n";

    PyDocString DS("CompositeCurve2d");
    class_<PyGeCompositeCurve2d, bases<PyGeCurve2d>>("CompositeCurve2d")
        .def(init<>())
        .def(init<const boost::python::list&>())
        .def(init<const boost::python::list&, const boost::python::list&>(DS.CTOR(ctor, 11764)))
        .def("getCurveList", &PyGeCompositeCurve2d::getCurveList, DS.ARGS())
        .def("setCurveList", &PyGeCompositeCurve2d::setCurveList1)
        .def("setCurveList", &PyGeCompositeCurve2d::setCurveList2, DS.OVRL(setCurveListOverloads))
        .def("globalToLocalParam", &PyGeCompositeCurve2d::globalToLocalParam, DS.ARGS({ "param: float" }))
        .def("localToGlobalParam", &PyGeCompositeCurve2d::localToGlobalParam, DS.ARGS({ "param: float","segNum: int" }))
        .def("cast", &PyGeCompositeCurve2d::cast, DS.SARGS({ "otherObject: PyGe.Entity2d" })).staticmethod("cast")
        .def("copycast", &PyGeCompositeCurve2d::copycast, DS.SARGS({ "otherObject: PyGe.Entity2d" })).staticmethod("copycast")
        .def("className", &PyGeCompositeCurve2d::className, DS.SARGS()).staticmethod("className")
        ;
}

PyGeCompositeCurve2d::PyGeCompositeCurve2d()
    : PyGeCurve2d(new AcGeCompositeCurve2d())
{
}

PyGeCompositeCurve2d::PyGeCompositeCurve2d(AcGeEntity2d* pEnt)
    : PyGeCurve2d(pEnt)
{
}

PyGeCompositeCurve2d::PyGeCompositeCurve2d(const boost::python::list& curveList)
    :PyGeCurve2d(new AcGeCompositeCurve2d(PyListToGe2dVoidPointerArray(curveList)))
{
}

PyGeCompositeCurve2d::PyGeCompositeCurve2d(const boost::python::list& curveList, const boost::python::list& isOwnerOfCurves)
    :PyGeCurve2d(new AcGeCompositeCurve2d(PyListToGe2dVoidPointerArray(curveList), PyListToIntArray(isOwnerOfCurves)))
{
}

PyGeCompositeCurve2d::PyGeCompositeCurve2d(const AcGeCompositeCurve2d& src)
    :PyGeCurve2d(new AcGeCompositeCurve2d(src))
{
}

boost::python::list PyGeCompositeCurve2d::getCurveList() const
{
    PyAutoLockGIL lock;
    AcGeVoidPointerArray curveList;
    impObj()->getCurveList(curveList);
    boost::python::list pylist;
    for (auto item : curveList)
        pylist.append(PyGeCurve2d(static_cast<const AcGeCurve2d*>(item)));
    return pylist;
}

void PyGeCompositeCurve2d::setCurveList1(const boost::python::list& curveList) const
{
    impObj()->setCurveList(PyListToGe2dVoidPointerArray(curveList));
}

void PyGeCompositeCurve2d::setCurveList2(const boost::python::list& curveList, const boost::python::list& isOwnerOfCurves) const
{
    impObj()->setCurveList(PyListToGe2dVoidPointerArray(curveList), PyListToIntArray(isOwnerOfCurves));
}

boost::python::tuple PyGeCompositeCurve2d::globalToLocalParam(double param) const
{
    PyAutoLockGIL lock;
    int segNum = 0;
    auto result = impObj()->globalToLocalParam(param, segNum);
    return boost::python::make_tuple(result, segNum);
}

double PyGeCompositeCurve2d::localToGlobalParam(double param, int segNum) const
{
    return impObj()->localToGlobalParam(param, segNum);
}

PyGeCompositeCurve2d PyGeCompositeCurve2d::cast(const PyGeEntity2d& src)
{
    return PyGeEntity2dCast<PyGeCompositeCurve2d, AcGeCompositeCurve2d>(src);
}

PyGeCompositeCurve2d PyGeCompositeCurve2d::copycast(const PyGeEntity2d& src)
{
    return PyGeCompositeCurve2d(static_cast<AcGeCompositeCurve2d*>(src.impObj()->copy()));
}

std::string PyGeCompositeCurve2d::className()
{
    return "AcGeCompositeCurve2d";
}

AcGeCompositeCurve2d* PyGeCompositeCurve2d::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_imp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcGeCompositeCurve2d*>(m_imp.get());
}

