#include "stdafx.h"
#include "PyGeCurve3d.h"
#include "PyGeInterval.h"
#include "PyGePointEnt3d.h"
#include "PyGeBoundBlock3d.h"
#include "PyGePlane.h"
#include "PyGeLinearEnt3d.h"
#include "PyGePlanarEnt.h"
#include "PyGeLinearEnt3d.h"

using namespace boost::python;
//-----------------------------------------------------------------------------------
//PyGeCurve3d
void makePyGeCurve3dWrapper()
{
    constexpr const std::string_view  getSamplePointsOverloads = "Overloads:\n"
        "- numSample: int\n"
        "- fromParam: float, toParam: float, approxEps: float\n";

    PyDocString DS("Curve3d");
    class_<PyGeCurve3d, bases<PyGeEntity3d>>("Curve3d", boost::python::no_init)
        .def("getInterval", &PyGeCurve3d::getInterval, DS.ARGS(11854))
        .def("getStartPoint", &PyGeCurve3d::getStartPoint, DS.ARGS())
        .def("getEndPoint", &PyGeCurve3d::getEndPoint, DS.ARGS())
        .def("reverseParam", &PyGeCurve3d::reverseParam, DS.ARGS(11842))
        .def("setInterval", &PyGeCurve3d::setInterval1)
        .def("setInterval", &PyGeCurve3d::setInterval2, DS.ARGS({ "val : PyGe.Interval = ..." }, 11843))
        .def("distanceTo", &PyGeCurve3d::distanceTo1)
        .def("distanceTo", &PyGeCurve3d::distanceTo2)
        .def("distanceTo", &PyGeCurve3d::distanceTo3)
        .def("distanceTo", &PyGeCurve3d::distanceTo4, DS.ARGS({ "pt : PyGe.Point3d | PyGe.Curve3d","tol : PyGe.Tol = ..." }, 11850))
        .def("closestPointTo", &PyGeCurve3d::closestPointTo1)
        .def("closestPointTo", &PyGeCurve3d::closestPointTo2)
        .def("closestPointTo", &PyGeCurve3d::closestPointTo3)
        .def("closestPointTo", &PyGeCurve3d::closestPointTo4, DS.ARGS({ "other : PyGe.Point3d | PyGe.Curve3d","tol : PyGe.Tol = ..." }, 11853))
        .def("getClosestPointTo", &PyGeCurve3d::getClosestPointTo1)
        .def("getClosestPointTo", &PyGeCurve3d::getClosestPointTo2, DS.ARGS({ "other : PyGe.Point3d","tol : PyGe.Tol = ..." }, 11853))
        .def("getClosestPointsTo", &PyGeCurve3d::getClosestPointsTo1)
        .def("getClosestPointsTo", &PyGeCurve3d::getClosestPointsTo2, DS.ARGS({ "other : PyGe.Curve3d","tol : PyGe.Tol = ..." }, 11857))
        .def("projClosestPointTo", &PyGeCurve3d::projClosestPointTo1)
        .def("projClosestPointTo", &PyGeCurve3d::projClosestPointTo2, DS.ARGS({ "pt : PyGe.Point3d","projDir : PyGe.Vector3d","tol : PyGe.Tol = ..." }, 11857))
        .def("projClosestPointsTo", &PyGeCurve3d::projClosestPointsTo1)
        .def("projClosestPointsTo", &PyGeCurve3d::projClosestPointsTo2, DS.ARGS({ "pt : PyGe.Curve3d","projDir : PyGe.Vector3d","tol : PyGe.Tol = ..." }, 11857))
        .def("getProjClosestPointTo", &PyGeCurve3d::getProjClosestPointTo1)
        .def("getProjClosestPointTo", &PyGeCurve3d::getProjClosestPointTo2, DS.ARGS({ "pt : PyGe.Point3d","projDir : PyGe.Vector3d","tol : PyGe.Tol = ..." }, 11857))
        .def("getProjClosestPointsTo", &PyGeCurve3d::getProjClosestPointsTo1)
        .def("getProjClosestPointsTo", &PyGeCurve3d::getProjClosestPointsTo2, DS.ARGS({ "pt : PyGe.Curve3d","projDir : PyGe.Vector3d","tol : PyGe.Tol = ..." }, 11857))
        .def("getNormalPoint", &PyGeCurve3d::getNormalPoint1)
        .def("getNormalPoint", &PyGeCurve3d::getNormalPoint2, DS.ARGS({ "pnt : PyGe.Point3d","tol : PyGe.Tol = ..." }, 11856))
        .def("boundBlock", &PyGeCurve3d::boundBlock1)
        .def("boundBlock", &PyGeCurve3d::boundBlock2, DS.ARGS({ "range : PyGe.Interval = ..." }, 11848))
        .def("orthoBoundBlock", &PyGeCurve3d::orthoBoundBlock1)
        .def("orthoBoundBlock", &PyGeCurve3d::orthoBoundBlock2, DS.ARGS({ "range : PyGe.Interval = ..." }, 11871))
        .def("project", &PyGeCurve3d::project1)
        .def("project", &PyGeCurve3d::project2, DS.ARGS({ "projectionPlane : PyGe.Plane","projDir : PyGe.Vector3d","tol : PyGe.Tol = ..." }, 11876))
        .def("orthoProject", &PyGeCurve3d::orthoProject1)
        .def("orthoProject", &PyGeCurve3d::orthoProject2, DS.ARGS({ "projectionPlane : PyGe.Plane","tol : PyGe.Tol = ..." }, 11872))
        .def("isOn", &PyGeCurve3d::isOn1)
        .def("isOn", &PyGeCurve3d::isOn2)
        .def("isOn", &PyGeCurve3d::isOn3)
        .def("isOn", &PyGeCurve3d::isOn4, DS.ARGS({ "pt : float | PyGe.Point3d","tol : PyGe.Tol = ..." }, 11867))
        .def("paramOf", &PyGeCurve3d::paramOf1)
        .def("paramOf", &PyGeCurve3d::paramOf2, DS.ARGS({ "pt : PyGe.Point3d","tol : PyGe.Tol = ..." }, 11874))
        .def("getTrimmedOffset", &PyGeCurve3d::getTrimmedOffset1)
        .def("getTrimmedOffset", &PyGeCurve3d::getTrimmedOffset2, DS.ARGS({ "dist : float", "planeNormal : PyGe.Vector3d","extensionType : PyGe.OffsetCrvExtType","tol : PyGe.Tol = ..." }, 11860))
        .def("isClosed", &PyGeCurve3d::isClosed1)
        .def("isClosed", &PyGeCurve3d::isClosed2, DS.ARGS({ "tol : PyGe.Tol = ..." }, 11863))
        .def("isPlanar", &PyGeCurve3d::isPlanar1)
        .def("isPlanar", &PyGeCurve3d::isPlanar2, DS.ARGS({ "tol : PyGe.Tol = ..." }, 11869))
        .def("isLinear", &PyGeCurve3d::isLinear1)
        .def("isLinear", &PyGeCurve3d::isLinear2, DS.ARGS({ "tol : PyGe.Tol = ..." }, 11866))
        .def("isCoplanarWith", &PyGeCurve3d::isCoplanarWith1)
        .def("isCoplanarWith", &PyGeCurve3d::isCoplanarWith2, DS.ARGS({ "curve : PyGe.Curve3d","tol : PyGe.Tol = ..." }, 11864))
        .def("isPeriodic", &PyGeCurve3d::isPeriodic, DS.ARGS(11868))
        .def("length", &PyGeCurve3d::length1)
        .def("length", &PyGeCurve3d::length2, DS.ARGS({ "frm : float", "to : float", "tol : float = ..." }, 11870))
        .def("paramAtLength", &PyGeCurve3d::paramAtLength1)
        .def("paramAtLength", &PyGeCurve3d::paramAtLength2, DS.ARGS({ "datumParam : float", "length : float","posParamDir : bool=True", "tol : float = ..." }, 11873))
        .def("area", &PyGeCurve3d::area1)
        .def("area", &PyGeCurve3d::area2, DS.ARGS({ "startParam : float", "endParam : float", "tol : float = ..." }, 11847))
        .def("isDegenerate", &PyGeCurve3d::isDegenerate1)
        .def("isDegenerate", &PyGeCurve3d::isDegenerate2, DS.ARGS({ "tol : PyGe.Tol = ..." }, 11865))
        .def("getSplitCurves", &PyGeCurve3d::getSplitCurves, DS.ARGS({ "param : float" }, 11859))
        .def("explode", &PyGeCurve3d::explode1)
        .def("explode", &PyGeCurve3d::explode2, DS.ARGS({ "val : PyGe.Interval = ..." }, 11852))
        .def("hasStartPoint", &PyGeCurve3d::hasStartPoint, DS.ARGS(11862))
        .def("hasEndPoint", &PyGeCurve3d::hasEndPoint, DS.ARGS(11861))
        .def("evalPoint", &PyGeCurve3d::evalPoint1)
        .def("evalPoint", &PyGeCurve3d::evalPoint2, DS.ARGS({ "param : float","numDeriv : int = 1" }, 11851))
        .def("getSamplePoints", &PyGeCurve3d::getSamplePoints1)
        .def("getSamplePoints", &PyGeCurve3d::getSamplePoints2, DS.OVRL(getSamplePointsOverloads, 11858))
        .def("cast", &PyGeCurve3d::cast, DS.SARGS({ "otherObject: PyGe.Curve3d" })).staticmethod("cast")
        .def("copycast", &PyGeCurve3d::copycast, DS.SARGS({ "otherObject: PyGe.Curve3d" })).staticmethod("copycast")
        .def("className", &PyGeCurve3d::className, DS.SARGS()).staticmethod("className")
        ;
}

PyGeCurve3d::PyGeCurve3d(AcGeEntity3d* pEnt)
    :PyGeEntity3d(pEnt)
{
}

PyGeCurve3d::PyGeCurve3d(const AcGeEntity3d* pEnt)
    :PyGeEntity3d(pEnt)
{
}

PyGeInterval PyGeCurve3d::getInterval() const
{
    AcGeInterval iv;
    impObj()->getInterval(iv);
    return PyGeInterval(iv);
}

AcGePoint3d PyGeCurve3d::getStartPoint() const
{
    AcGeInterval iv;
    AcGePoint3d s, e;
    impObj()->getInterval(iv, s, e);
    return s;
}

AcGePoint3d PyGeCurve3d::getEndPoint() const
{
    AcGeInterval iv;
    AcGePoint3d s, e;
    impObj()->getInterval(iv, s, e);
    return e;
}

void PyGeCurve3d::reverseParam() const
{
    impObj()->reverseParam();
}

void PyGeCurve3d::setInterval1() const
{
    impObj()->setInterval();
}

bool PyGeCurve3d::setInterval2(const PyGeInterval& intrvl) const
{
    return impObj()->setInterval(intrvl.imp);
}

double PyGeCurve3d::distanceTo1(const AcGePoint3d& pnt) const
{
    return impObj()->distanceTo(pnt);
}

double PyGeCurve3d::distanceTo2(const AcGePoint3d& pnt, const AcGeTol& tol) const
{
    return impObj()->distanceTo(pnt, tol);
}

double PyGeCurve3d::distanceTo3(const PyGeCurve3d& c) const
{
    return impObj()->distanceTo(*c.impObj());
}

double PyGeCurve3d::distanceTo4(const PyGeCurve3d& c, const AcGeTol& tol) const
{
    return impObj()->distanceTo(*c.impObj(), tol);
}

AcGePoint3d PyGeCurve3d::closestPointTo1(const AcGePoint3d& pnt) const
{
    return impObj()->closestPointTo(pnt);
}

AcGePoint3d PyGeCurve3d::closestPointTo2(const AcGePoint3d& pnt, const AcGeTol& tol) const
{
    return impObj()->closestPointTo(pnt, tol);
}

boost::python::tuple PyGeCurve3d::closestPointTo3(const PyGeCurve3d& curve3d) const
{
    PyAutoLockGIL lock;
    AcGePoint3d pntOnOtherCrv;
    auto pnt = impObj()->closestPointTo(*curve3d.impObj(), pntOnOtherCrv);
    return make_tuple(pnt, pntOnOtherCrv);
}

boost::python::tuple PyGeCurve3d::closestPointTo4(const PyGeCurve3d& curve3d, const AcGeTol& tol) const
{
    PyAutoLockGIL lock;
    AcGePoint3d pntOnOtherCrv;
    auto pnt = impObj()->closestPointTo(*curve3d.impObj(), pntOnOtherCrv, tol);
    return make_tuple(pnt, pntOnOtherCrv);
}

PyGePointOnCurve3d PyGeCurve3d::getClosestPointTo1(const AcGePoint3d& pnt) const
{
    AcGePointOnCurve3d curve;
    impObj()->getClosestPointTo(pnt, curve);
    return PyGePointOnCurve3d(curve);
}

PyGePointOnCurve3d PyGeCurve3d::getClosestPointTo2(const AcGePoint3d& pnt, const AcGeTol& tol) const
{
    AcGePointOnCurve3d curve;
    impObj()->getClosestPointTo(pnt, curve, tol);
    return PyGePointOnCurve3d(curve);
}

boost::python::tuple PyGeCurve3d::getClosestPointsTo1(const PyGeCurve3d& curve) const
{
    PyAutoLockGIL lock;
    AcGePointOnCurve3d curvea, curveb;
    impObj()->getClosestPointTo(*curve.impObj(), curvea, curveb);
    return make_tuple(PyGePointOnCurve3d(curvea), PyGePointOnCurve3d(curveb));
}

boost::python::tuple PyGeCurve3d::getClosestPointsTo2(const PyGeCurve3d& curve, const AcGeTol& tol) const
{
    PyAutoLockGIL lock;
    AcGePointOnCurve3d curvea, curveb;
    impObj()->getClosestPointTo(*curve.impObj(), curvea, curveb, tol);
    return make_tuple(PyGePointOnCurve3d(curvea), PyGePointOnCurve3d(curveb));
}

AcGePoint3d PyGeCurve3d::projClosestPointTo1(const AcGePoint3d& pnt, const AcGeVector3d& projectDirection) const
{
    return impObj()->projClosestPointTo(pnt, projectDirection);
}

AcGePoint3d PyGeCurve3d::projClosestPointTo2(const AcGePoint3d& pnt, const AcGeVector3d& projectDirection, const AcGeTol& tol) const
{
    return impObj()->projClosestPointTo(pnt, projectDirection, tol);
}

boost::python::tuple PyGeCurve3d::projClosestPointsTo1(const PyGeCurve3d& curve3d, const AcGeVector3d& projectDirection) const
{
    PyAutoLockGIL lock;
    AcGePoint3d pntOnOtherCrv;
    auto pnt = impObj()->projClosestPointTo(*curve3d.impObj(), projectDirection, pntOnOtherCrv);
    return make_tuple(pnt, pntOnOtherCrv);
}

boost::python::tuple PyGeCurve3d::projClosestPointsTo2(const PyGeCurve3d& curve3d, const AcGeVector3d& projectDirection, const AcGeTol& tol) const
{
    PyAutoLockGIL lock;
    AcGePoint3d pntOnOtherCrv;
    auto pnt = impObj()->projClosestPointTo(*curve3d.impObj(), projectDirection, pntOnOtherCrv, tol);
    return make_tuple(pnt, pntOnOtherCrv);
}

PyGePointOnCurve3d PyGeCurve3d::getProjClosestPointTo1(const AcGePoint3d& pnt, const AcGeVector3d& projectDirection) const
{
    AcGePointOnCurve3d curve;
    impObj()->getProjClosestPointTo(pnt, projectDirection, curve);
    return PyGePointOnCurve3d(curve);
}

PyGePointOnCurve3d PyGeCurve3d::getProjClosestPointTo2(const AcGePoint3d& pnt, const AcGeVector3d& projectDirection, const AcGeTol& tol) const
{
    AcGePointOnCurve3d curve;
    impObj()->getProjClosestPointTo(pnt, projectDirection, curve, tol);
    return PyGePointOnCurve3d(curve);
}

boost::python::tuple PyGeCurve3d::getProjClosestPointsTo1(const PyGeCurve3d& curve3d, const AcGeVector3d& projectDirection) const
{
    PyAutoLockGIL lock;
    AcGePointOnCurve3d curvea, curveb;
    impObj()->getProjClosestPointTo(*curve3d.impObj(), projectDirection, curvea, curveb);
    return make_tuple(PyGePointOnCurve3d(curvea), PyGePointOnCurve3d(curveb));
}

boost::python::tuple PyGeCurve3d::getProjClosestPointsTo2(const PyGeCurve3d& curve3d, const AcGeVector3d& projectDirection, const AcGeTol& tol) const
{
    PyAutoLockGIL lock;
    AcGePointOnCurve3d curvea, curveb;
    impObj()->getProjClosestPointTo(*curve3d.impObj(), projectDirection, curvea, curveb);
    return make_tuple(PyGePointOnCurve3d(curvea), PyGePointOnCurve3d(curveb), tol);
}

PyGePointOnCurve3d PyGeCurve3d::getNormalPoint1(const AcGePoint3d& pnt) const
{
    AcGePointOnCurve3d curve;
    if (auto flag = impObj()->getNormalPoint(pnt, curve); flag == false)
        throw PyErrorStatusException(eInvalidInput);
    return PyGePointOnCurve3d(curve);
}

PyGePointOnCurve3d PyGeCurve3d::getNormalPoint2(const AcGePoint3d& pnt, const AcGeTol& tol) const
{
    AcGePointOnCurve3d curve;
    if (auto flag = impObj()->getNormalPoint(pnt, curve, tol); flag == false)
        throw PyErrorStatusException(eInvalidInput);
    return PyGePointOnCurve3d(curve);
}

PyGeBoundBlock3d PyGeCurve3d::boundBlock1() const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    return PyGeBoundBlock3d(impObj()->boundBlock().copy());
#endif

}

PyGeBoundBlock3d PyGeCurve3d::boundBlock2(const PyGeInterval& range) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    return PyGeBoundBlock3d(impObj()->boundBlock(range.imp).copy());
#endif
}

PyGeBoundBlock3d PyGeCurve3d::orthoBoundBlock1() const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    return PyGeBoundBlock3d(impObj()->orthoBoundBlock().copy());
#endif
}

PyGeBoundBlock3d PyGeCurve3d::orthoBoundBlock2(const PyGeInterval& range) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    return PyGeBoundBlock3d(impObj()->orthoBoundBlock(range.imp).copy());
#endif
}

PyGeEntity3d PyGeCurve3d::project1(const PyGePlane& projectionPlane, const AcGeVector3d& projectDirection) const
{
    return PyGeEntity3d(impObj()->project(*projectionPlane.impObj(), projectDirection));
}

PyGeEntity3d PyGeCurve3d::project2(const PyGePlane& projectionPlane, const AcGeVector3d& projectDirection, const AcGeTol& tol) const
{
    return PyGeEntity3d(impObj()->project(*projectionPlane.impObj(), projectDirection, tol));
}

PyGeEntity3d PyGeCurve3d::orthoProject1(const PyGePlane& projectionPlane) const
{
    return PyGeEntity3d(impObj()->orthoProject(*projectionPlane.impObj()));
}

PyGeEntity3d PyGeCurve3d::orthoProject2(const PyGePlane& projectionPlane, const AcGeTol& tol) const
{
    return PyGeEntity3d(impObj()->orthoProject(*projectionPlane.impObj(), tol));
}

boost::python::tuple PyGeCurve3d::isOn1(const AcGePoint3d& pnt) const
{
    PyAutoLockGIL lock;
    double param = 0;
    auto res = impObj()->isOn(pnt, param);
    return boost::python::make_tuple(res, param);
}

boost::python::tuple PyGeCurve3d::isOn2(const AcGePoint3d& pnt, const AcGeTol& tol) const
{
    PyAutoLockGIL lock;
    double param = 0;
    auto res = impObj()->isOn(pnt, param, tol);
    return boost::python::make_tuple(res, param);
}

boost::python::tuple PyGeCurve3d::isOn3(double param) const
{
    PyAutoLockGIL lock;
    return boost::python::make_tuple(impObj()->isOn(param));
}

boost::python::tuple PyGeCurve3d::isOn4(double param, const AcGeTol& tol) const
{
    PyAutoLockGIL lock;
    return boost::python::make_tuple(impObj()->isOn(param, tol));
}

double PyGeCurve3d::paramOf1(const AcGePoint3d& pnt) const
{
    return impObj()->paramOf(pnt);
}

double PyGeCurve3d::paramOf2(const AcGePoint3d& pnt, const AcGeTol& tol) const
{
    return impObj()->paramOf(pnt, tol);
}

boost::python::list PyGeCurve3d::getTrimmedOffset1(double distance, const AcGeVector3d& planeNormal, AcGe::OffsetCrvExtType extensionType) const
{
    PyAutoLockGIL lock;
    boost::python::list curves;
    AcGeVoidPointerArray offsetCurveList;
    impObj()->getTrimmedOffset(distance, planeNormal, offsetCurveList, extensionType);
    for (const auto& item : offsetCurveList)
        curves.append(PyGeCurve3d(reinterpret_cast<AcGeCurve3d*>(item)));
    return curves;
}

boost::python::list PyGeCurve3d::getTrimmedOffset2(double distance, const AcGeVector3d& planeNormal, AcGe::OffsetCrvExtType extensionType, const AcGeTol& tol) const
{
    PyAutoLockGIL lock;
    boost::python::list curves;
    AcGeVoidPointerArray offsetCurveList;
    impObj()->getTrimmedOffset(distance, planeNormal, offsetCurveList, extensionType, tol);
    for (const auto& item : offsetCurveList)
        curves.append(PyGeCurve3d(reinterpret_cast<AcGeCurve3d*>(item)));
    return curves;
}

Adesk::Boolean PyGeCurve3d::isClosed1() const
{
    return impObj()->isClosed();
}

Adesk::Boolean PyGeCurve3d::isClosed2(const AcGeTol& tol) const
{
    return impObj()->isClosed(tol);
}

boost::python::tuple PyGeCurve3d::isPlanar1() const
{
    PyAutoLockGIL lock;
    AcGePlane plane;
    bool flag = impObj()->isPlanar(plane);
    return make_tuple(flag, PyGePlane(plane));
}

boost::python::tuple PyGeCurve3d::isPlanar2(const AcGeTol& tol) const
{
    PyAutoLockGIL lock;
    AcGePlane plane;
    bool flag = impObj()->isPlanar(plane, tol);
    return make_tuple(flag, PyGePlane(plane));
}

boost::python::tuple PyGeCurve3d::isLinear1() const
{
    PyAutoLockGIL lock;
    AcGeLine3d plane;
    bool flag = impObj()->isLinear(plane);
    return make_tuple(flag, PyGeLine3d(plane));
}

boost::python::tuple PyGeCurve3d::isLinear2(const AcGeTol& tol) const
{
    PyAutoLockGIL lock;
    AcGeLine3d plane;
    bool flag = impObj()->isLinear(plane, tol);
    return make_tuple(flag, PyGeLine3d(plane));
}

boost::python::tuple PyGeCurve3d::isCoplanarWith1(const PyGeCurve3d& curve3d) const
{
    PyAutoLockGIL lock;
    AcGePlane plane;
    bool flag = impObj()->isCoplanarWith(*curve3d.impObj(), plane);
    return make_tuple(flag, PyGePlane(plane));
}

boost::python::tuple PyGeCurve3d::isCoplanarWith2(const PyGeCurve3d& curve3d, const AcGeTol& tol) const
{
    PyAutoLockGIL lock;
    AcGePlane plane;
    bool flag = impObj()->isCoplanarWith(*curve3d.impObj(), plane, tol);
    return make_tuple(flag, PyGePlane(plane));
}

boost::python::tuple PyGeCurve3d::isPeriodic() const
{
    PyAutoLockGIL lock;
    double val = 0;
    bool flag = impObj()->isPeriodic(val);
    return boost::python::make_tuple(flag, val);
}

double PyGeCurve3d::length1(double fromParam, double toParam) const
{
    return impObj()->length(fromParam, toParam);
}

double PyGeCurve3d::length2(double fromParam, double toParam, double tol) const
{
    return impObj()->length(fromParam, toParam, tol);
}

double PyGeCurve3d::paramAtLength1(double datumParam, double length) const
{
    return impObj()->paramAtLength(datumParam, length);
}

double PyGeCurve3d::paramAtLength2(double datumParam, double length, Adesk::Boolean posParamDir, double tol) const
{
    return impObj()->paramAtLength(datumParam, length, posParamDir, tol);
}

double PyGeCurve3d::area1(double startParam, double endParam) const
{
    double length = 0;
    if (bool flag = impObj()->area(startParam, endParam, length); flag == false)
        throw PyErrorStatusException(eInvalidInput);
    return length;
}

double PyGeCurve3d::area2(double startParam, double endParam, const AcGeTol& tol) const
{
    double length = 0;
    if (bool flag = impObj()->area(startParam, endParam, length, tol); flag == false)
        throw PyErrorStatusException(eInvalidInput);
    return length;
}

boost::python::tuple PyGeCurve3d::isDegenerate1() const
{
    PyAutoLockGIL lock;
    AcGeEntity3d* pEnt = nullptr;
    bool flag = impObj()->isDegenerate(pEnt);
    return boost::python::make_tuple(flag, PyGeEntity3d(pEnt));
}

boost::python::tuple PyGeCurve3d::isDegenerate2(const AcGeTol& tol) const
{
    PyAutoLockGIL lock;
    AcGeEntity3d* pEnt = nullptr;
    bool flag = impObj()->isDegenerate(pEnt, tol);
    return boost::python::make_tuple(flag, PyGeEntity3d(pEnt));
}

boost::python::tuple PyGeCurve3d::getSplitCurves(double param) const
{
    PyAutoLockGIL lock;
    AcGeCurve3d* p1 = nullptr;
    AcGeCurve3d* p2 = nullptr;
    impObj()->getSplitCurves(param, p1, p2);
    return make_tuple(PyGeCurve3d(p1), PyGeCurve3d(p2));
}

//TODO: Test ... leak... looks wonky?
boost::python::list PyGeCurve3d::explode1() const
{
    PyAutoLockGIL lock;
    boost::python::list curves;
    AcGeIntArray newExplodedCurve;
    AcGeVoidPointerArray explodedCurves;
    impObj()->explode(explodedCurves, newExplodedCurve);
    for (size_t idx = 0; idx < explodedCurves.length(); idx++)
    {
        AcGeCurve3d* pCurve = reinterpret_cast<AcGeCurve3d*>(explodedCurves[idx]);
        curves.append(PyGeCurve3d(pCurve->copy()));
        if (newExplodedCurve[idx] == 1)
            delete pCurve;
    }
    return curves;
}

//TODO: Test ... leak... looks wonky?
boost::python::list PyGeCurve3d::explode2(const PyGeInterval& interval) const
{
    PyAutoLockGIL lock;
    boost::python::list curves;
    AcGeIntArray newExplodedCurve;
    AcGeVoidPointerArray explodedCurves;
    impObj()->explode(explodedCurves, newExplodedCurve, &interval.imp);
    for (size_t idx = 0; idx < explodedCurves.length(); idx++)
    {
        AcGeCurve3d* pCurve = reinterpret_cast<AcGeCurve3d*>(explodedCurves[idx]);
        curves.append(PyGeCurve3d(pCurve->copy()));
        if (newExplodedCurve[idx] == 1)
            delete pCurve;
    }
    return curves;
}

bool PyGeCurve3d::hasStartPoint() const
{
    AcGePoint3d pnt;
    return impObj()->hasStartPoint(pnt);
}

bool PyGeCurve3d::hasEndPoint() const
{
    AcGePoint3d pnt;
    return impObj()->hasEndPoint(pnt);
}

AcGePoint3d PyGeCurve3d::evalPoint1(double param) const
{
    return impObj()->evalPoint(param);
}

boost::python::tuple PyGeCurve3d::evalPoint2(double param, int numDeriv) const
{
    PyAutoLockGIL lock;
    boost::python::list vecs;
    AcGeVector3dArray derivArray;
    AcGePoint3d pnt = impObj()->evalPoint(param, numDeriv, derivArray);
    for (const auto& item : derivArray)
        vecs.append(item);
    return boost::python::make_tuple(pnt, vecs);
}

boost::python::tuple PyGeCurve3d::getSamplePoints1(int numSample) const
{
    PyAutoLockGIL lock;
    AcGeDoubleArray paramArray;
    AcGePoint3dArray pointArray;
#if defined(_BRXTARGET260)
    impObj()->getSamplePoints(numSample, pointArray);
#else
    impObj()->getSamplePoints(numSample, pointArray, paramArray);
#endif
    return boost::python::make_tuple(Point3dArrayToPyList(pointArray), DoubleArrayToPyList(paramArray));
}

boost::python::tuple PyGeCurve3d::getSamplePoints2(double fromParam, double toParam, double approxEps) const
{
    PyAutoLockGIL lock;
    AcGeDoubleArray paramArray;
    AcGePoint3dArray pointArray;
    boost::python::list pointList;
    impObj()->getSamplePoints(fromParam, toParam, approxEps, pointArray, paramArray);
    return boost::python::make_tuple(Point3dArrayToPyList(pointArray), DoubleArrayToPyList(paramArray));
}

PyGeCurve3d PyGeCurve3d::cast(const PyGeEntity3d& src)
{
    return PyGeEntity3dCast<PyGeCurve3d, AcGeCurve3d>(src);
}

PyGeCurve3d PyGeCurve3d::copycast(const PyGeEntity3d& src)
{
    return PyGeCurve3d(static_cast<AcGeCurve3d*>(src.impObj()->copy()));
}

std::string PyGeCurve3d::className()
{
    return "AcGeCurve3d";
}

AcGeCurve3d* PyGeCurve3d::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_imp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcGeCurve3d*>(m_imp.get());
}

//-----------------------------------------------------------------------------------
//AcGeCircArc3d
void makePyGeCircArc3dWrapper()
{
    constexpr const std::string_view ctor = "Overloads:\n"
        "- None: Any\n"
        "- cent: PyGe.Point3d, nrm: PyGe.Vector3d, radius: float\n"
        "- cent: PyGe.Point3d, nrm: PyGe.Vector3d, refVec: PyGe.Vector3d, radius: float, startAngle: float, endAngle: float\n"
        "- startPoint: PyGe.Point3d, pnt: PyGe.Point3d, endPoint: PyGe.Point3d\n";

    constexpr const std::string_view setOverloads = "Overloads:\n"
        "- cent: PyGe.Point3d, nrm: PyGe.Vector3d, radius: float\n"
        "- cent: PyGe.Point3d, nrm: PyGe.Vector3d, refVec: PyGe.Vector3d, radius: float, startAngle: float, endAngle: float\n"
        "- startPoint: PyGe.Point3d, pnt: PyGe.Point3d, endPoint: PyGe.Point3d\n"
        "- curve1: PyGe.Curve3d, curve2: PyGe.Curve3d, radius: float\n"
        "- curve1: PyGe.Curve3d, curve2: PyGe.Curve3d, curve3: PyGe.Curve3d\n";


    PyDocString DS("CircArc3d");
    class_<PyGeCircArc3d, bases<PyGeCurve3d>>("CircArc3d")
        .def(init<>())
        .def(init<const AcGePoint3d&, const AcGeVector3d&, double>())
        .def(init<const AcGePoint3d&, const AcGeVector3d&, const AcGeVector3d&, double, double, double>())
        .def(init<const AcGePoint3d&, const AcGePoint3d&, const AcGePoint3d&>(DS.CTOR(ctor, 11736)))
        .def("closestPointToPlane", &PyGeCircArc3d::closestPointToPlane1)
        .def("closestPointToPlane", &PyGeCircArc3d::closestPointToPlane2, DS.ARGS({ "plane: PyGe.PlanarEnt", "tol: PyGe.Tol = ..." }))
        .def("intersectWith", &PyGeCircArc3d::intersectWith1)
        .def("intersectWith", &PyGeCircArc3d::intersectWith2)
        .def("intersectWith", &PyGeCircArc3d::intersectWith3)
        .def("intersectWith", &PyGeCircArc3d::intersectWith4)
        .def("intersectWith", &PyGeCircArc3d::intersectWith5)
        .def("intersectWith", &PyGeCircArc3d::intersectWith6, DS.ARGS({ "other: PyGe.CircArc3d|PyGe.LinearEnt3d|PyGe.PlanarEnt", "tol: PyGe.Tol = ..." }))
        .def("projIntersectWith", &PyGeCircArc3d::projIntersectWith1)
        .def("projIntersectWith", &PyGeCircArc3d::projIntersectWith2, DS.ARGS({ "other: PyGe.LinearEnt3d", "projDir: PyGe.Vector3d","tol: PyGe.Tol = ..." }))
        .def("tangent", &PyGeCircArc3d::tangent1)
        .def("tangent", &PyGeCircArc3d::tangent2, DS.ARGS({ "pt: PyGe.Point3d","tol: PyGe.Tol = ..." }))
        .def("getPlane", &PyGeCircArc3d::getPlane, DS.ARGS())
        .def("isInside", &PyGeCircArc3d::isInside1)
        .def("isInside", &PyGeCircArc3d::isInside2, DS.ARGS({ "pt: PyGe.Point3d","tol: PyGe.Tol = ..." }))
        .def("center", &PyGeCircArc3d::center, DS.ARGS())
        .def("normal", &PyGeCircArc3d::normal, DS.ARGS())
        .def("refVec", &PyGeCircArc3d::refVec, DS.ARGS())
        .def("radius", &PyGeCircArc3d::radius, DS.ARGS())
        .def("startAng", &PyGeCircArc3d::startAng, DS.ARGS())
        .def("endAng", &PyGeCircArc3d::endAng, DS.ARGS())
        .def("startPoint", &PyGeCircArc3d::startPoint, DS.ARGS())
        .def("endPoint", &PyGeCircArc3d::endPoint, DS.ARGS())
        .def("setCenter", &PyGeCircArc3d::setCenter, DS.ARGS({ "pt: PyGe.Point3d" }))
        .def("setAxes", &PyGeCircArc3d::setAxes, DS.ARGS({ "vec: PyGe.Vector3d","refvec: PyGe.Vector3d" }))
        .def("setRadius", &PyGeCircArc3d::setRadius, DS.ARGS({ "val: float" }))
        .def("setAngles", &PyGeCircArc3d::setAngles, DS.ARGS({ "val: float" }))
        .def("set", &PyGeCircArc3d::set1)
        .def("set", &PyGeCircArc3d::set2)
        .def("set", &PyGeCircArc3d::set3)
        .def("set", &PyGeCircArc3d::set4)
        .def("set", &PyGeCircArc3d::set5, DS.OVRL(setOverloads))
        .def("cast", &PyGeCircArc3d::cast, DS.SARGS({ "otherObject: PyGe.Entity3d" })).staticmethod("cast")
        .def("copycast", &PyGeCircArc3d::copycast, DS.SARGS({ "otherObject: PyGe.Entity3d" })).staticmethod("copycast")
        .def("className", &PyGeCircArc3d::className, DS.SARGS()).staticmethod("className")
        ;
}

PyGeCircArc3d::PyGeCircArc3d()
    :PyGeCurve3d(new AcGeCircArc3d())
{
}

PyGeCircArc3d::PyGeCircArc3d(AcGeEntity3d* pEnt)
    : PyGeCurve3d(pEnt)
{
}

PyGeCircArc3d::PyGeCircArc3d(const AcGeCircArc3d& arc)
    : PyGeCurve3d(new AcGeCircArc3d(arc))
{
}

PyGeCircArc3d::PyGeCircArc3d(const AcGePoint3d& cent, const AcGeVector3d& nrm, double radius)
    : PyGeCurve3d(new AcGeCircArc3d(cent, nrm, radius))
{
}

PyGeCircArc3d::PyGeCircArc3d(const AcGePoint3d& cent, const AcGeVector3d& nrm, const AcGeVector3d& refVec, double radius, double startAngle, double endAngle)
    : PyGeCurve3d(new AcGeCircArc3d(cent, nrm, refVec, radius, startAngle, endAngle))
{
}

PyGeCircArc3d::PyGeCircArc3d(const AcGePoint3d& startPoint, const AcGePoint3d& pnt, const AcGePoint3d& endPoint)
    : PyGeCurve3d(new AcGeCircArc3d(startPoint, pnt, endPoint))
{
}

boost::python::tuple PyGeCircArc3d::closestPointToPlane1(const PyGePlanarEnt& plane) const
{
    PyAutoLockGIL lock;
    AcGePoint3d pointOnPlane;
    auto result = impObj()->closestPointToPlane(*plane.impObj(), pointOnPlane);
    return boost::python::make_tuple(result, pointOnPlane);
}

boost::python::tuple PyGeCircArc3d::closestPointToPlane2(const PyGePlanarEnt& plane, const AcGeTol& tol) const
{
    PyAutoLockGIL lock;
    AcGePoint3d pointOnPlane;
    auto result = impObj()->closestPointToPlane(*plane.impObj(), pointOnPlane, tol);
    return boost::python::make_tuple(result, pointOnPlane);
}

boost::python::tuple PyGeCircArc3d::intersectWith1(const PyGeLinearEnt3d& line) const
{
    PyAutoLockGIL lock;
    int intn = 0;
    AcGePoint3d p1, p2;
    auto result = impObj()->intersectWith(*line.impObj(), intn, p1, p2);
    return boost::python::make_tuple(result, intn, p1, p2);
}

boost::python::tuple PyGeCircArc3d::intersectWith2(const PyGeLinearEnt3d& line, const AcGeTol& tol) const
{
    PyAutoLockGIL lock;
    int intn = 0;
    AcGePoint3d p1, p2;
    auto result = impObj()->intersectWith(*line.impObj(), intn, p1, p2, tol);
    return boost::python::make_tuple(result, intn, p1, p2);
}

boost::python::tuple PyGeCircArc3d::intersectWith3(const PyGeCircArc3d& line) const
{
    PyAutoLockGIL lock;
    int intn = 0;
    AcGePoint3d p1, p2;
    auto result = impObj()->intersectWith(*line.impObj(), intn, p1, p2);
    return boost::python::make_tuple(result, intn, p1, p2);
}

boost::python::tuple PyGeCircArc3d::intersectWith4(const PyGeCircArc3d& line, const AcGeTol& tol) const
{
    PyAutoLockGIL lock;
    int intn = 0;
    AcGePoint3d p1, p2;
    auto result = impObj()->intersectWith(*line.impObj(), intn, p1, p2, tol);
    return boost::python::make_tuple(result, intn, p1, p2);
}

boost::python::tuple PyGeCircArc3d::intersectWith5(const PyGePlanarEnt& line) const
{
    PyAutoLockGIL lock;
    int intn = 0;
    AcGePoint3d p1, p2;
    auto result = impObj()->intersectWith(*line.impObj(), intn, p1, p2);
    return boost::python::make_tuple(result, intn, p1, p2);
}

boost::python::tuple PyGeCircArc3d::intersectWith6(const PyGePlanarEnt& line, const AcGeTol& tol) const
{
    PyAutoLockGIL lock;
    int intn = 0;
    AcGePoint3d p1, p2;
    auto result = impObj()->intersectWith(*line.impObj(), intn, p1, p2, tol);
    return boost::python::make_tuple(result, intn, p1, p2);
}

boost::python::tuple PyGeCircArc3d::projIntersectWith1(const PyGeLinearEnt3d& line, const AcGeVector3d& projDir) const
{
    PyAutoLockGIL lock;
    int intn = 0;
    AcGePoint3d p1, p2, p3, p4;
    auto result = impObj()->projIntersectWith(*line.impObj(), projDir, intn, p1, p2, p3, p4);
    return boost::python::make_tuple(result, intn, p1, p2, p3, p4);
}

boost::python::tuple PyGeCircArc3d::projIntersectWith2(const PyGeLinearEnt3d& line, const AcGeVector3d& projDir, const AcGeTol& tol) const
{
    PyAutoLockGIL lock;
    int intn = 0;
    AcGePoint3d p1, p2, p3, p4;
    auto result = impObj()->projIntersectWith(*line.impObj(), projDir, intn, p1, p2, p3, p4, tol);
    return boost::python::make_tuple(result, intn, p1, p2, p3, p4);
}

boost::python::tuple PyGeCircArc3d::tangent1(const AcGePoint3d& pnt) const
{
    PyAutoLockGIL lock;
    AcGeLine3d line;
    auto result = impObj()->tangent(pnt, line, AcGeContext::gTol);
    return boost::python::make_tuple(result, PyGeLine3d(line));
}

boost::python::tuple PyGeCircArc3d::tangent2(const AcGePoint3d& pnt, const AcGeTol& tol) const
{
    PyAutoLockGIL lock;
    AcGeLine3d line;
    auto result = impObj()->tangent(pnt, line, tol);
    return boost::python::make_tuple(result, PyGeLine3d(line));
}

PyGePlane PyGeCircArc3d::getPlane() const
{
    PyAutoLockGIL lock;
    AcGePlane plane;
    impObj()->getPlane(plane);
    return PyGePlane(plane);
}

Adesk::Boolean PyGeCircArc3d::isInside1(const AcGePoint3d& pnt) const
{
    return impObj()->isInside(pnt);
}

Adesk::Boolean PyGeCircArc3d::isInside2(const AcGePoint3d& pnt, const AcGeTol& tol) const
{
    return impObj()->isInside(pnt, tol);
}

AcGePoint3d PyGeCircArc3d::center() const
{
    return impObj()->center();
}

AcGeVector3d PyGeCircArc3d::normal() const
{
    return impObj()->normal();
}

AcGeVector3d PyGeCircArc3d::refVec() const
{
    return impObj()->refVec();
}

double PyGeCircArc3d::radius() const
{
    return impObj()->radius();
}

double PyGeCircArc3d::startAng() const
{
    return impObj()->startAng();
}

double PyGeCircArc3d::endAng() const
{
    return impObj()->endAng();
}

AcGePoint3d PyGeCircArc3d::startPoint() const
{
    return impObj()->startPoint();
}

AcGePoint3d PyGeCircArc3d::endPoint() const
{
    return impObj()->endPoint();
}

void PyGeCircArc3d::setCenter(const AcGePoint3d& val) const
{
    impObj()->setCenter(val);
}

void PyGeCircArc3d::setAxes(const AcGeVector3d& normal, const AcGeVector3d& refVec) const
{
    impObj()->setAxes(normal, refVec);
}

void PyGeCircArc3d::setRadius(double val) const
{
    impObj()->setRadius(val);
}

void PyGeCircArc3d::setAngles(double startAngle, double endAngle) const
{
    impObj()->setAngles(startAngle, endAngle);
}

void PyGeCircArc3d::set1(const AcGePoint3d& cent, const AcGeVector3d& nrm, double radius) const
{
    impObj()->set(cent, nrm, radius);
}

void PyGeCircArc3d::set2(const AcGePoint3d& cent, const AcGeVector3d& nrm, const AcGeVector3d& refVec, double radius, double startAngle, double endAngle) const
{
    impObj()->set(cent, nrm, refVec, radius, startAngle, endAngle);
}

void PyGeCircArc3d::set3(const AcGePoint3d& startPoint, const AcGePoint3d& pnt, const AcGePoint3d& endPoint) const
{
    impObj()->set(startPoint, pnt, endPoint);
}

void PyGeCircArc3d::set4(const PyGeCurve3d& curve1, const PyGeCurve3d& curve2, double radius) const
{
    //TODO:
    double param1;
    double param2;
    Adesk::Boolean success;
    impObj()->set(*curve1.impObj(), *curve2.impObj(), radius, param1, param2, success);
    if (success == false)
        throw PyErrorStatusException(eInvalidInput);
}

void PyGeCircArc3d::set5(const PyGeCurve3d& curve1, const PyGeCurve3d& curve2, const PyGeCurve3d& curve3) const
{
    double param1;
    double param2;
    double param3;
    Adesk::Boolean success;
    impObj()->set(*curve1.impObj(), *curve2.impObj(), *curve3.impObj(), param1, param2, param3, success);
    if (success == false)
        throw PyErrorStatusException(eInvalidInput);
}

PyGeCircArc3d PyGeCircArc3d::cast(const PyGeEntity3d& src)
{
    return PyGeEntity3dCast<PyGeCircArc3d, AcGeCircArc3d>(src);
}

PyGeCircArc3d PyGeCircArc3d::copycast(const PyGeEntity3d& src)
{
    return PyGeCircArc3d(static_cast<AcGeCircArc3d*>(src.impObj()->copy()));
}

std::string PyGeCircArc3d::className()
{
    return "AcGeCircArc3d";
}

AcGeCircArc3d* PyGeCircArc3d::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_imp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcGeCircArc3d*>(m_imp.get());
}

//-----------------------------------------------------------------------------------
//AcGeCompositeCurve3d
using Segment = std::pair<AcGePoint3d, AcGePoint3d>;
using Segments = std::vector<Segment>;

using Polyline3D = std::vector<AcGePoint3d>;
using Polyline3Ds = std::vector<Polyline3D>;

struct Point3DHash
{
    inline static double roundPointComponentToGTol(double value)
    {
        const double precision = AcGeContext::gTol.equalPoint();
        return std::round(value / precision) * precision;
    }

    inline std::size_t operator()(const AcGePoint3d& p) const
    {
        std::size_t seed = 0;
        boost::hash_combine(seed, roundPointComponentToGTol(p.x));
        boost::hash_combine(seed, roundPointComponentToGTol(p.y));
        boost::hash_combine(seed, roundPointComponentToGTol(p.z));
        return seed;
    }
};

struct SegmentPtrHash
{
    std::size_t operator()(const Segment* s) const
    {
        return std::hash<const void*>{}(static_cast<const void*>(s));
    }
};

static auto connectSegmentsIntoPolylines(const Segments& segments) -> Polyline3Ds
{
    // Map from point to all segments starting or ending at that point
    std::unordered_multimap<AcGePoint3d, const Segment*, Point3DHash> pointToSegs;
    for (const auto& seg : segments)
    {
        pointToSegs.emplace(seg.first, &seg);
        pointToSegs.emplace(seg.second, &seg);
    }

    std::unordered_set<const Segment*, SegmentPtrHash> visited;
    Polyline3Ds polylines;

    for (const auto& seg : segments)
    {
        if (visited.count(&seg))
            continue;

        Polyline3D polyline;
        polyline.push_back(seg.first);
        polyline.push_back(seg.second);
        visited.insert(&seg);

        // Extend forward
        AcGePoint3d current = seg.second;
        while (true)
        {
            bool extended = false;
            auto range = pointToSegs.equal_range(current);
            for (auto it = range.first; it != range.second; ++it)
            {
                const Segment* nextSeg = it->second;
                if (visited.count(nextSeg))
                    continue;
                // Find the next point to extend
                AcGePoint3d nextPoint;
                {
                    if (current.isEqualTo(nextSeg->first))
                        nextPoint = nextSeg->second;
                    else if (current.isEqualTo(nextSeg->second))
                        nextPoint = nextSeg->first;
                    else
                        continue;
                }
                polyline.push_back(nextPoint);
                current = nextPoint;
                visited.insert(nextSeg);
                extended = true;
                break;
            }
            if (!extended)
                break;
        }

        // Extend backward
        current = seg.first;
        while (true)
        {
            bool extended = false;
            auto range = pointToSegs.equal_range(current);
            for (auto it = range.first; it != range.second; ++it) {
                const Segment* prevSeg = it->second;
                if (visited.count(prevSeg))
                    continue;
                AcGePoint3d prevPoint;
                {
                    if (current.isEqualTo(prevSeg->first))
                        prevPoint = prevSeg->second;
                    else if (current.isEqualTo(prevSeg->second))
                        prevPoint = prevSeg->first;
                    else
                        continue;
                }
                polyline.insert(polyline.begin(), prevPoint);
                current = prevPoint;
                visited.insert(prevSeg);
                extended = true;
                break;
            }
            if (!extended)
                break;
        }
        polylines.push_back(polyline);
    }
    return polylines;
}

void makePyGeCompositeCurve3dWrapper()
{
    constexpr const std::string_view ctor = "Overloads:\n"
        "- None: Any\n"
        "- curveList: list[PyGe.Curve3d]\n"
        "- curveList: list[PyGe.Curve3d], isOwnerOfCurves: list[int]\n";

    constexpr const std::string_view setCurveListOverloads = "Overloads:\n"
        "- curveList: list[PyGe.Curve3d]\n"
        "- curveList: list[PyGe.Curve3d], isOwnerOfCurves: list[int]\n";

    PyDocString DS("CompositeCurve3d");
    class_<PyGeCompositeCurve3d, bases<PyGeCurve3d>>("CompositeCurve3d")
        .def(init<>())
        .def(init<const boost::python::list&>())
        .def(init<const boost::python::list&, const boost::python::list&>(DS.CTOR(ctor, 11771)))
        .def("getCurveList", &PyGeCompositeCurve3d::getCurveList, DS.ARGS())
        .def("setCurveList", &PyGeCompositeCurve3d::setCurveList1)
        .def("setCurveList", &PyGeCompositeCurve3d::setCurveList2, DS.OVRL(setCurveListOverloads))
        .def("globalToLocalParam", &PyGeCompositeCurve3d::globalToLocalParam, DS.ARGS({ "param: float" }))
        .def("localToGlobalParam", &PyGeCompositeCurve3d::localToGlobalParam, DS.ARGS({ "param: float","segNum: int" }))
        .def("createFromLineSeg3dArray", &PyGeCompositeCurve3d::createFromLineSeg3dArray, DS.SARGS({ "seg: list[PyGe.LineSeg3d]" })).staticmethod("createFromLineSeg3dArray")
        .def("cast", &PyGeCompositeCurve3d::cast, DS.SARGS({ "otherObject: PyGe.Entity3d" })).staticmethod("cast")
        .def("copycast", &PyGeCompositeCurve3d::copycast, DS.SARGS({ "otherObject: PyGe.Entity3d" })).staticmethod("copycast")
        .def("className", &PyGeCompositeCurve3d::className, DS.SARGS()).staticmethod("className")
        ;
}

PyGeCompositeCurve3d::PyGeCompositeCurve3d()
    :PyGeCurve3d(new AcGeCompositeCurve3d())
{
}

PyGeCompositeCurve3d::PyGeCompositeCurve3d(AcGeEntity3d* pEnt)
    : PyGeCurve3d(pEnt)
{
}

PyGeCompositeCurve3d::PyGeCompositeCurve3d(const boost::python::list& curveList)
    :PyGeCurve3d(new AcGeCompositeCurve3d(PyListToGe3dVoidPointerArray(curveList)))
{
}

PyGeCompositeCurve3d::PyGeCompositeCurve3d(const boost::python::list& curveList, const boost::python::list& isOwnerOfCurves)
    :PyGeCurve3d(new AcGeCompositeCurve3d(PyListToGe3dVoidPointerArray(curveList), PyListToIntArray(isOwnerOfCurves)))
{
}

boost::python::list PyGeCompositeCurve3d::getCurveList() const
{
    // NOTE: don't delete these sub-curves, 
    // AcGeCompositeCurve3d is the owner
    PyAutoLockGIL lock;
    AcGeVoidPointerArray curveList;
    impObj()->getCurveList(curveList);
    boost::python::list pylist;
    for (auto item : curveList)
        pylist.append(PyGeCurve3d(static_cast<const AcGeCurve3d*>(item)));
    return pylist;
}

void PyGeCompositeCurve3d::setCurveList1(const boost::python::list& curveList) const
{
    impObj()->setCurveList(PyListToGe3dVoidPointerArray(curveList));
}

void PyGeCompositeCurve3d::setCurveList2(const boost::python::list& curveList, const boost::python::list& isOwnerOfCurves) const
{
    impObj()->setCurveList(PyListToGe3dVoidPointerArray(curveList), PyListToIntArray(isOwnerOfCurves));
}

boost::python::tuple PyGeCompositeCurve3d::globalToLocalParam(double param) const
{
    PyAutoLockGIL lock;
    int segNum = 0;
    auto result = impObj()->globalToLocalParam(param, segNum);
    return boost::python::make_tuple(result, segNum);
}

double PyGeCompositeCurve3d::localToGlobalParam(double param, int segNum) const
{
    return impObj()->localToGlobalParam(param, segNum);
}

boost::python::list PyGeCompositeCurve3d::createFromLineSeg3dArray(const boost::python::list& curveList)
{
    PyAutoLockGIL lock;
    const auto& vec = py_list_to_std_vector<PyGeLineSeg3d>(curveList);
    Segments segs;
    for(const auto& item : vec)
        segs.emplace_back(Segment{ item.startPoint(), item.endPoint() });
    const auto& plines = connectSegmentsIntoPolylines(segs);
    boost::python::list pylist;
    for (const auto& pline : plines)
    {
        AcGeVoidPointerArray arr;
        AcGeIntArray isOwnerOfCurves;
        arr.setPhysicalLength(pline.size());
        isOwnerOfCurves.setPhysicalLength(pline.size());
        for (size_t idx = 1; idx < pline.size(); idx++)
        {
            arr.append(new AcGeLineSeg3d(pline[idx - 1], pline[idx]));
            isOwnerOfCurves.append(1);
        }
        pylist.append(PyGeCompositeCurve3d(new AcGeCompositeCurve3d(arr, isOwnerOfCurves)));
    }
    return pylist;
}

PyGeCompositeCurve3d PyGeCompositeCurve3d::cast(const PyGeEntity3d& src)
{
    return PyGeEntity3dCast<PyGeCompositeCurve3d, AcGeCompositeCurve3d>(src);
}

PyGeCompositeCurve3d PyGeCompositeCurve3d::copycast(const PyGeEntity3d& src)
{
    return PyGeCompositeCurve3d(static_cast<AcGeCompositeCurve3d*>(src.impObj()->copy()));
}

std::string PyGeCompositeCurve3d::className()
{
    return "AcGeCompositeCurve3d";
}

AcGeCompositeCurve3d* PyGeCompositeCurve3d::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_imp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcGeCompositeCurve3d*>(m_imp.get());
}

//-----------------------------------------------------------------------------------------
//AcGeCircArc3d wrapper
void makePyGeEllipArc3dWrapper()
{
    constexpr const std::string_view ctor = "Overloads:\n"
        "- None: Any\n"
        "- carc: PyGe.CircArc3d\n"
        "- cent: PyGe.Point3d, majorAxis: PyGe.Vector3d, minorAxis: PyGe.Vector3d, majorRadius: float,minorRadius: float\n"
        "- cent: PyGe.Point3d, majorAxis: PyGe.Vector3d, minorAxis: PyGe.Vector3d, majorRadius: float,minorRadius: float, startAngle: float, endAngle: float\n";

    constexpr const std::string_view setOverloads = "Overloads:\n"
        "- carc: PyGe.CircArc3d,\n"
        "- cent: PyGe.Point3d, majorAxis: PyGe.Vector3d, minorAxis: PyGe.Vector3d, majorRadius: float,minorRadius: float\n"
        "- cent: PyGe.Point3d, majorAxis: PyGe.Vector3d, minorAxis: PyGe.Vector3d, majorRadius: float,minorRadius: float, startAngle: float, endAngle: float\n";


    PyDocString DS("EllipArc3d");
    class_<PyGeEllipArc3d, bases<PyGeCurve3d>>("EllipArc3d")
        .def(init<>())
#if !defined(_BRXTARGET260)
        .def(init<const PyGeCircArc3d&>())
#endif
        .def(init<const AcGePoint3d&, const AcGeVector3d&, const AcGeVector3d&, double, double>())
        .def(init<const AcGePoint3d&, const AcGeVector3d&, const AcGeVector3d&, double, double, double, double>(DS.CTOR(ctor, 11996)))
        .def("closestPointToPlane", &PyGeEllipArc3d::closestPointToPlane1)
        .def("closestPointToPlane", &PyGeEllipArc3d::closestPointToPlane2, DS.ARGS({ "plane: PyGe.PlanarEnt", "tol: PyGe.Tol = ..." }))
        .def("intersectWith", &PyGeEllipArc3d::intersectWith1)
        .def("intersectWith", &PyGeEllipArc3d::intersectWith2)
        .def("intersectWith", &PyGeEllipArc3d::intersectWith3)
        .def("intersectWith", &PyGeEllipArc3d::intersectWith4, DS.ARGS({ "other: PyGe.LinearEnt3d|PyGe.PlanarEnt", "tol: PyGe.Tol = ..." }))
        .def("projIntersectWith", &PyGeEllipArc3d::projIntersectWith1)
        .def("projIntersectWith", &PyGeEllipArc3d::projIntersectWith2, DS.ARGS({ "other: PyGe.LinearEnt3d", "projDir: PyGe.Vector3d","tol: PyGe.Tol = ..." }))
        .def("getPlane", &PyGeEllipArc3d::getPlane, DS.ARGS())
        .def("isCircular", &PyGeEllipArc3d::isCircular1)
        .def("isCircular", &PyGeEllipArc3d::isCircular2, DS.ARGS({ "tol: PyGe.Tol = ..." }))
        .def("isInside", &PyGeEllipArc3d::isInside1)
        .def("isInside", &PyGeEllipArc3d::isInside2, DS.ARGS({ "pt: PyGe.Point3d","tol: PyGe.Tol = ..." }))
        .def("center", &PyGeEllipArc3d::center, DS.ARGS())
        .def("minorRadius", &PyGeEllipArc3d::minorRadius, DS.ARGS())
        .def("majorRadius", &PyGeEllipArc3d::majorRadius, DS.ARGS())
        .def("minorAxis", &PyGeEllipArc3d::minorAxis, DS.ARGS())
        .def("majorAxis", &PyGeEllipArc3d::majorAxis, DS.ARGS())
        .def("normal", &PyGeEllipArc3d::normal, DS.ARGS())
        .def("startAng", &PyGeEllipArc3d::startAng, DS.ARGS())
        .def("endAng", &PyGeEllipArc3d::endAng, DS.ARGS())
        .def("startPoint", &PyGeEllipArc3d::startPoint, DS.ARGS())
        .def("endPoint", &PyGeEllipArc3d::endPoint, DS.ARGS())
        .def("setCenter", &PyGeEllipArc3d::setCenter, DS.ARGS({ "pt: PyGe.Point3d" }))
        .def("setMinorRadius", &PyGeEllipArc3d::setMinorRadius, DS.ARGS({ "val: float" }))
        .def("setMajorRadius", &PyGeEllipArc3d::setMajorRadius, DS.ARGS({ "val: float" }))
        .def("setAxes", &PyGeEllipArc3d::setAxes, DS.ARGS({ "majorAxis: PyGe.Vector3d","minorAxis: PyGe.Vector3d" }))
        .def("setAngles", &PyGeEllipArc3d::setAngles, DS.ARGS({ "startAngle: float","endAngle: float" }))
        .def("set", &PyGeEllipArc3d::set1)
        .def("set", &PyGeEllipArc3d::set2)
        .def("set", &PyGeEllipArc3d::set3, DS.OVRL(setOverloads))
        .def("cast", &PyGeEllipArc3d::cast, DS.SARGS({ "otherObject: PyGe.Entity3d" })).staticmethod("cast")
        .def("copycast", &PyGeEllipArc3d::copycast, DS.SARGS({ "otherObject: PyGe.Entity3d" })).staticmethod("copycast")
        .def("className", &PyGeEllipArc3d::className, DS.SARGS()).staticmethod("className")
        ;
}

PyGeEllipArc3d::PyGeEllipArc3d()
    :PyGeCurve3d(new AcGeEllipArc3d())
{
}

PyGeEllipArc3d::PyGeEllipArc3d(AcGeEntity3d* pEnt)
    : PyGeCurve3d(pEnt)
{
}

#if !defined(_BRXTARGET260)
PyGeEllipArc3d::PyGeEllipArc3d(const AcGeEllipArc3d& ell)
    : PyGeCurve3d(new AcGeEllipArc3d(ell))
{
}

PyGeEllipArc3d::PyGeEllipArc3d(const PyGeCircArc3d& arc)
    : PyGeCurve3d(new AcGeEllipArc3d(*arc.impObj()))
{
}
#endif

PyGeEllipArc3d::PyGeEllipArc3d(const AcGePoint3d& cent, const AcGeVector3d& majorAxis, const AcGeVector3d& minorAxis, double majorRadius, double minorRadius)
    : PyGeCurve3d(new AcGeEllipArc3d(cent, majorAxis, minorAxis, majorRadius, minorRadius))
{
}

PyGeEllipArc3d::PyGeEllipArc3d(const AcGePoint3d& cent, const AcGeVector3d& majorAxis, const AcGeVector3d& minorAxis, double majorRadius, double minorRadius, double ang1, double ang2)
    : PyGeCurve3d(new AcGeEllipArc3d(cent, majorAxis, minorAxis, majorRadius, minorRadius, ang1, ang2))
{
}

boost::python::tuple PyGeEllipArc3d::closestPointToPlane1(const PyGePlanarEnt& plane) const
{
    PyAutoLockGIL lock;
    AcGePoint3d pointOnPlane;
    auto result = impObj()->closestPointToPlane(*plane.impObj(), pointOnPlane);
    return boost::python::make_tuple(result, pointOnPlane);
}

boost::python::tuple PyGeEllipArc3d::closestPointToPlane2(const PyGePlanarEnt& plane, const AcGeTol& tol) const
{
    PyAutoLockGIL lock;
    AcGePoint3d pointOnPlane;
    auto result = impObj()->closestPointToPlane(*plane.impObj(), pointOnPlane, tol);
    return boost::python::make_tuple(result, pointOnPlane);
}

boost::python::tuple PyGeEllipArc3d::intersectWith1(const PyGeLinearEnt3d& line) const
{
    PyAutoLockGIL lock;
    int intn = 0;
    AcGePoint3d p1, p2;
    auto result = impObj()->intersectWith(*line.impObj(), intn, p1, p2);
    return boost::python::make_tuple(result, intn, p1, p2);
}

boost::python::tuple PyGeEllipArc3d::intersectWith2(const PyGeLinearEnt3d& line, const AcGeTol& tol) const
{
    PyAutoLockGIL lock;
    int intn = 0;
    AcGePoint3d p1, p2;
    auto result = impObj()->intersectWith(*line.impObj(), intn, p1, p2, tol);
    return boost::python::make_tuple(result, intn, p1, p2);
}

boost::python::tuple PyGeEllipArc3d::intersectWith3(const PyGePlanarEnt& line) const
{
    PyAutoLockGIL lock;
    int intn = 0;
    AcGePoint3d p1, p2;
    auto result = impObj()->intersectWith(*line.impObj(), intn, p1, p2);
    return boost::python::make_tuple(result, intn, p1, p2);
}

boost::python::tuple PyGeEllipArc3d::intersectWith4(const PyGePlanarEnt& line, const AcGeTol& tol) const
{
    PyAutoLockGIL lock;
    int intn = 0;
    AcGePoint3d p1, p2;
    auto result = impObj()->intersectWith(*line.impObj(), intn, p1, p2, tol);
    return boost::python::make_tuple(result, intn, p1, p2);
}

boost::python::tuple PyGeEllipArc3d::projIntersectWith1(const PyGeLinearEnt3d& line, const AcGeVector3d& projDir) const
{
    PyAutoLockGIL lock;
    int intn = 0;
    AcGePoint3d p1, p2, p3, p4;
    auto result = impObj()->projIntersectWith(*line.impObj(), projDir, intn, p1, p2, p3, p4);
    return boost::python::make_tuple(result, intn, p1, p2, p3, p4);
}

boost::python::tuple PyGeEllipArc3d::projIntersectWith2(const PyGeLinearEnt3d& line, const AcGeVector3d& projDir, const AcGeTol& tol) const
{
    PyAutoLockGIL lock;
    int intn = 0;
    AcGePoint3d p1, p2, p3, p4;
    auto result = impObj()->projIntersectWith(*line.impObj(), projDir, intn, p1, p2, p3, p4, tol);
    return boost::python::make_tuple(result, intn, p1, p2, p3, p4);
}

PyGePlane PyGeEllipArc3d::getPlane() const
{
    PyAutoLockGIL lock;
    AcGePlane plane;
    impObj()->getPlane(plane);
    return PyGePlane(plane);
}

Adesk::Boolean PyGeEllipArc3d::isCircular1() const
{
    return impObj()->isCircular();
}

Adesk::Boolean PyGeEllipArc3d::isCircular2(const AcGeTol& tol) const
{
    return impObj()->isCircular(tol);
}

Adesk::Boolean PyGeEllipArc3d::isInside1(const AcGePoint3d& pnt) const
{
    return impObj()->isInside(pnt);
}

Adesk::Boolean PyGeEllipArc3d::isInside2(const AcGePoint3d& pnt, const AcGeTol& tol) const
{
    return impObj()->isInside(pnt, tol);
}

AcGePoint3d PyGeEllipArc3d::center() const
{
    return impObj()->center();
}

double PyGeEllipArc3d::minorRadius() const
{
    return impObj()->minorRadius();
}

double PyGeEllipArc3d::majorRadius() const
{
    return impObj()->majorRadius();
}

AcGeVector3d PyGeEllipArc3d::minorAxis() const
{
    return impObj()->minorAxis();
}

AcGeVector3d PyGeEllipArc3d::majorAxis() const
{
    return impObj()->majorAxis();
}

AcGeVector3d PyGeEllipArc3d::normal() const
{
    return impObj()->normal();
}

double PyGeEllipArc3d::startAng() const
{
    return impObj()->startAng();
}

double PyGeEllipArc3d::endAng() const
{
    return impObj()->endAng();
}

AcGePoint3d PyGeEllipArc3d::startPoint() const
{
    return impObj()->startPoint();
}

AcGePoint3d PyGeEllipArc3d::endPoint() const
{
    return impObj()->endPoint();
}

void PyGeEllipArc3d::setCenter(const AcGePoint3d& cent) const
{
    impObj()->setCenter(cent);
}

void PyGeEllipArc3d::setMinorRadius(double rad) const
{
    impObj()->setMinorRadius(rad);
}

void PyGeEllipArc3d::setMajorRadius(double rad) const
{
    impObj()->setMajorRadius(rad);
}

void PyGeEllipArc3d::setAxes(const AcGeVector3d& majorAxis, const AcGeVector3d& minorAxis) const
{
    impObj()->setAxes(majorAxis, minorAxis);
}

void PyGeEllipArc3d::setAngles(double startAngle, double endAngle) const
{
    impObj()->setAngles(startAngle, endAngle);
}

void PyGeEllipArc3d::set1(const AcGePoint3d& cent, const AcGeVector3d& majorAxis, const AcGeVector3d& minorAxis, double majorRadius, double minorRadius) const
{
    impObj()->set(cent, majorAxis, minorAxis, majorRadius, minorRadius);
}

void PyGeEllipArc3d::set2(const AcGePoint3d& cent, const AcGeVector3d& majorAxis, const AcGeVector3d& minorAxis, double majorRadius, double minorRadius, double startAngle, double endAngle) const
{
    impObj()->set(cent, majorAxis, minorAxis, majorRadius, minorRadius, startAngle, endAngle);
}

void PyGeEllipArc3d::set3(const PyGeCircArc3d& arc) const
{
    impObj()->set(*arc.impObj());
}

PyGeEllipArc3d PyGeEllipArc3d::cast(const PyGeEntity3d& src)
{
    return PyGeEntity3dCast<PyGeEllipArc3d, AcGeEllipArc3d>(src);
}

PyGeEllipArc3d PyGeEllipArc3d::copycast(const PyGeEntity3d& src)
{
    return PyGeEllipArc3d(static_cast<AcGeEllipArc3d*>(src.impObj()->copy()));
}

std::string PyGeEllipArc3d::className()
{
    return "AcGeCompositeCurve3d";
}

AcGeEllipArc3d* PyGeEllipArc3d::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_imp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcGeEllipArc3d*>(m_imp.get());
}


//-----------------------------------------------------------------------------------------
//PyGeExternalCurve3d wrapper
void makePyGeExternalCurve3dWrapper()
{
    PyDocString DS("ExternalCurve3d");
    class_<PyGeExternalCurve3d, bases<PyGeCurve3d>>("ExternalCurve3d", boost::python::no_init)
        .def("isLine", &PyGeExternalCurve3d::isLine, DS.ARGS())
        .def("isRay", &PyGeExternalCurve3d::isRay, DS.ARGS())
        .def("isLineSeg", &PyGeExternalCurve3d::isLineSeg, DS.ARGS())
        .def("isCircArc", &PyGeExternalCurve3d::isCircArc, DS.ARGS())
        .def("isEllipArc", &PyGeExternalCurve3d::isEllipArc, DS.ARGS())
        .def("isNurbCurve", &PyGeExternalCurve3d::isNurbCurve, DS.ARGS())
        .def("isDefined", &PyGeExternalCurve3d::isDefined, DS.ARGS())
        .def("getNativeCurve", &PyGeExternalCurve3d::getNativeCurve, DS.ARGS())
        .def("externalCurveKind", &PyGeExternalCurve3d::externalCurveKind, DS.ARGS())
        .def("isOwnerOfCurve", &PyGeExternalCurve3d::isOwnerOfCurve, DS.ARGS())
        .def("setToOwnCurve", &PyGeExternalCurve3d::setToOwnCurve, DS.ARGS())
        .def("cast", &PyGeExternalCurve3d::cast, DS.SARGS({ "otherObject: PyGe.Entity3d" })).staticmethod("cast")
        .def("copycast", &PyGeExternalCurve3d::copycast, DS.SARGS({ "otherObject: PyGe.Entity3d" })).staticmethod("copycast")
        .def("className", &PyGeExternalCurve3d::className, DS.SARGS()).staticmethod("className")
        ;
}

PyGeExternalCurve3d::PyGeExternalCurve3d(AcGeEntity3d* pEnt)
    : PyGeCurve3d(pEnt)
{
}

Adesk::Boolean PyGeExternalCurve3d::isLine() const
{
    return impObj()->isLine();
}

Adesk::Boolean PyGeExternalCurve3d::isRay() const
{
    return impObj()->isRay();
}

Adesk::Boolean PyGeExternalCurve3d::isLineSeg() const
{
    return impObj()->isLineSeg();
}

Adesk::Boolean PyGeExternalCurve3d::isCircArc() const
{
    return impObj()->isCircArc();
}

Adesk::Boolean PyGeExternalCurve3d::isEllipArc() const
{
    return impObj()->isEllipArc();
}

Adesk::Boolean PyGeExternalCurve3d::isNurbCurve() const
{
    return impObj()->isNurbCurve();
}

Adesk::Boolean PyGeExternalCurve3d::isDefined() const
{
    return impObj()->isDefined();
}

PyGeCurve3d PyGeExternalCurve3d::getNativeCurve() const
{
    AcGeCurve3d* nativeCurve = nullptr;
    auto flag = impObj()->isNativeCurve(nativeCurve);
    if (flag == false)
        PyThrowBadEs(eInvalidInput);
    return PyGeCurve3d{ nativeCurve };
}

AcGe::ExternalEntityKind PyGeExternalCurve3d::externalCurveKind() const
{
    return impObj()->externalCurveKind();
}

Adesk::Boolean PyGeExternalCurve3d::isOwnerOfCurve() const
{
    return impObj()->isOwnerOfCurve();
}

void PyGeExternalCurve3d::setToOwnCurve() const
{
    impObj()->setToOwnCurve();
}

PyGeExternalCurve3d PyGeExternalCurve3d::cast(const PyGeEntity3d& src)
{
    return PyGeEntity3dCast<PyGeExternalCurve3d, AcGeExternalCurve3d>(src);
}

PyGeExternalCurve3d PyGeExternalCurve3d::copycast(const PyGeEntity3d& src)
{
    return PyGeExternalCurve3d(static_cast<AcGeExternalCurve3d*>(src.impObj()->copy()));
}

std::string PyGeExternalCurve3d::className()
{
    return "AcGeExternalCurve3d";
}

AcGeExternalCurve3d* PyGeExternalCurve3d::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_imp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcGeExternalCurve3d*>(m_imp.get());
}

//-----------------------------------------------------------------------------------------
//AcGeOffsetCurve3d wrapper
void makePyGeOffsetCurve3dWrapper()
{
    PyDocString DS("OffsetCurve3d");
    class_<PyGeOffsetCurve3d, bases<PyGeCurve3d>>("OffsetCurve3d", boost::python::no_init)
        .def(init<const PyGeCurve3d&, const AcGeVector3d&, double>(DS.ARGS({ "baseCurve: PyGe.Curve3d", "planeNormal: PyGe.Vector3d", "offsetDistance: float" })))
        .def("curve", &PyGeOffsetCurve3d::curve, DS.ARGS())
        .def("normal", &PyGeOffsetCurve3d::normal, DS.ARGS())
        .def("offsetDistance", &PyGeOffsetCurve3d::offsetDistance, DS.ARGS())
        .def("paramDirection", &PyGeOffsetCurve3d::paramDirection, DS.ARGS())
        .def("transformation", &PyGeOffsetCurve3d::transformation, DS.ARGS())
        .def("setCurve", &PyGeOffsetCurve3d::setCurve, DS.ARGS({ "val: PyGe.Curve3d" }))
        .def("setNormal", &PyGeOffsetCurve3d::setNormal, DS.ARGS({ "normal: PyGe.Vector3d" }))
        .def("setOffsetDistance", &PyGeOffsetCurve3d::setOffsetDistance, DS.ARGS({ "val: float" }))
        .def("cast", &PyGeOffsetCurve3d::cast, DS.SARGS({ "otherObject: PyGe.Entity3d" })).staticmethod("cast")
        .def("copycast", &PyGeOffsetCurve3d::copycast, DS.SARGS({ "otherObject: PyGe.Entity3d" })).staticmethod("copycast")
        .def("className", &PyGeOffsetCurve3d::className, DS.SARGS()).staticmethod("className")
        ;
}

PyGeOffsetCurve3d::PyGeOffsetCurve3d(const PyGeCurve3d& baseCurve, const AcGeVector3d& planeNormal, double offsetDistance)
    : PyGeCurve3d(new AcGeOffsetCurve3d(*baseCurve.impObj(), planeNormal, offsetDistance))
{
}

PyGeOffsetCurve3d::PyGeOffsetCurve3d(AcGeEntity3d* pEnt)
    : PyGeCurve3d(pEnt)
{
}

PyGeCurve3d PyGeOffsetCurve3d::curve() const
{
    return PyGeCurve3d(impObj()->curve());
}

AcGeVector3d PyGeOffsetCurve3d::normal() const
{
    return impObj()->normal();
}

double PyGeOffsetCurve3d::offsetDistance() const
{
    return impObj()->offsetDistance();
}

Adesk::Boolean PyGeOffsetCurve3d::paramDirection() const
{
    return impObj()->paramDirection();
}

AcGeMatrix3d PyGeOffsetCurve3d::transformation() const
{
    return impObj()->transformation();
}

void PyGeOffsetCurve3d::setCurve(const PyGeCurve3d& baseCurve) const
{
    impObj()->setCurve(*baseCurve.impObj());
}

void PyGeOffsetCurve3d::setNormal(const AcGeVector3d& planeNormal) const
{
    impObj()->setNormal(planeNormal);
}

void PyGeOffsetCurve3d::setOffsetDistance(double offsetDistance) const
{
    impObj()->setOffsetDistance(offsetDistance);
}

PyGeOffsetCurve3d PyGeOffsetCurve3d::cast(const PyGeEntity3d& src)
{
    return PyGeEntity3dCast<PyGeOffsetCurve3d, AcGeOffsetCurve3d>(src);
}

PyGeOffsetCurve3d PyGeOffsetCurve3d::copycast(const PyGeEntity3d& src)
{
    return PyGeOffsetCurve3d(static_cast<AcGeOffsetCurve3d*>(src.impObj()->copy()));
}

std::string PyGeOffsetCurve3d::className()
{
    return "AcGeOffsetCurve3d";
}

AcGeOffsetCurve3d* PyGeOffsetCurve3d::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_imp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcGeOffsetCurve3d*>(m_imp.get());
}
