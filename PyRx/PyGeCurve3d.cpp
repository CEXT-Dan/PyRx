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
    PyDocString DS("Curve3d");
    class_<PyGeCurve3d, bases<PyGeEntity3d>>("Curve3d", boost::python::no_init)
        .def("getInterval", &PyGeCurve3d::getInterval, DS.ARGS())
        .def("getStartPoint", &PyGeCurve3d::getStartPoint, DS.ARGS())
        .def("getEndPoint", &PyGeCurve3d::getEndPoint, DS.ARGS())
        .def("reverseParam", &PyGeCurve3d::reverseParam, DS.ARGS())
        .def("setInterval", &PyGeCurve3d::setInterval1)
        .def("setInterval", &PyGeCurve3d::setInterval2)
        .def("distanceTo", &PyGeCurve3d::distanceTo1)
        .def("distanceTo", &PyGeCurve3d::distanceTo2)
        .def("distanceTo", &PyGeCurve3d::distanceTo3)
        .def("distanceTo", &PyGeCurve3d::distanceTo4)
        .def("closestPointTo", &PyGeCurve3d::closestPointTo1)
        .def("closestPointTo", &PyGeCurve3d::closestPointTo2)
        .def("closestPointTo", &PyGeCurve3d::closestPointTo3)
        .def("closestPointTo", &PyGeCurve3d::closestPointTo4)
        .def("getClosestPointTo", &PyGeCurve3d::getClosestPointTo1)
        .def("getClosestPointTo", &PyGeCurve3d::getClosestPointTo2)
        .def("getClosestPointsTo", &PyGeCurve3d::getClosestPointsTo1)
        .def("getClosestPointsTo", &PyGeCurve3d::getClosestPointsTo2)
        .def("projClosestPointTo", &PyGeCurve3d::projClosestPointTo1)
        .def("projClosestPointTo", &PyGeCurve3d::projClosestPointTo2)
        .def("projClosestPointsTo", &PyGeCurve3d::projClosestPointsTo1)
        .def("projClosestPointsTo", &PyGeCurve3d::projClosestPointsTo2)
        .def("getProjClosestPointTo", &PyGeCurve3d::getProjClosestPointTo1)
        .def("getProjClosestPointTo", &PyGeCurve3d::getProjClosestPointTo2)
        .def("getProjClosestPointsTo", &PyGeCurve3d::getProjClosestPointsTo1)
        .def("getProjClosestPointsTo", &PyGeCurve3d::getProjClosestPointsTo2)
        .def("getNormalPoint", &PyGeCurve3d::getNormalPoint1)
        .def("getNormalPoint", &PyGeCurve3d::getNormalPoint2)
        .def("boundBlock", &PyGeCurve3d::boundBlock1)
        .def("boundBlock", &PyGeCurve3d::boundBlock2)
        .def("orthoBoundBlock", &PyGeCurve3d::orthoBoundBlock1)
        .def("orthoBoundBlock", &PyGeCurve3d::orthoBoundBlock2)
        .def("project", &PyGeCurve3d::project1)
        .def("project", &PyGeCurve3d::project2)
        .def("orthoProject", &PyGeCurve3d::orthoProject1)
        .def("orthoProject", &PyGeCurve3d::orthoProject2)
        .def("isOn", &PyGeCurve3d::isOn1)
        .def("isOn", &PyGeCurve3d::isOn2)
        .def("isOn", &PyGeCurve3d::isOn3)
        .def("isOn", &PyGeCurve3d::isOn4)
        .def("paramOf", &PyGeCurve3d::paramOf1)
        .def("paramOf", &PyGeCurve3d::paramOf2)
        .def("getTrimmedOffset", &PyGeCurve3d::getTrimmedOffset1)
        .def("getTrimmedOffset", &PyGeCurve3d::getTrimmedOffset2)
        .def("isClosed", &PyGeCurve3d::isClosed1)
        .def("isClosed", &PyGeCurve3d::isClosed2)
        .def("isPlanar", &PyGeCurve3d::isPlanar1)
        .def("isPlanar", &PyGeCurve3d::isPlanar2)
        .def("isLinear", &PyGeCurve3d::isLinear1)
        .def("isLinear", &PyGeCurve3d::isLinear2)
        .def("isCoplanarWith", &PyGeCurve3d::isCoplanarWith1)
        .def("isCoplanarWith", &PyGeCurve3d::isCoplanarWith2)
        .def("isPeriodic", &PyGeCurve3d::isPeriodic, DS.ARGS())
        .def("length", &PyGeCurve3d::length1)
        .def("length", &PyGeCurve3d::length2)
        .def("paramAtLength", &PyGeCurve3d::paramAtLength1)
        .def("paramAtLength", &PyGeCurve3d::paramAtLength2)
        .def("area", &PyGeCurve3d::area1)
        .def("area", &PyGeCurve3d::area2)
        .def("isDegenerate", &PyGeCurve3d::isDegenerate1)
        .def("isDegenerate", &PyGeCurve3d::isDegenerate2)
        .def("getSplitCurves", &PyGeCurve3d::getSplitCurves, DS.ARGS({ "param : real" }))
        .def("explode", &PyGeCurve3d::explode1)
        .def("explode", &PyGeCurve3d::explode2)
        .def("hasStartPoint", &PyGeCurve3d::hasStartPoint, DS.ARGS())
        .def("hasEndPoint", &PyGeCurve3d::hasEndPoint, DS.ARGS())
        .def("evalPoint", &PyGeCurve3d::evalPoint1)
        .def("evalPoint", &PyGeCurve3d::evalPoint2)
        .def("getSamplePoints", &PyGeCurve3d::getSamplePoints1)
        .def("getSamplePoints", &PyGeCurve3d::getSamplePoints2)
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

void PyGeCurve3d::reverseParam()
{
    impObj()->reverseParam();
}

void PyGeCurve3d::setInterval1()
{
    impObj()->setInterval();
}

bool PyGeCurve3d::setInterval2(const PyGeInterval& intrvl)
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

boost::python::tuple PyGeCurve3d::closestPointTo3(const PyGeCurve3d& curve2d) const
{
    PyAutoLockGIL lock;
    AcGePoint3d pntOnOtherCrv;
    auto pnt = impObj()->closestPointTo(*curve2d.impObj(), pntOnOtherCrv);
    return make_tuple(pnt, pntOnOtherCrv);
}

boost::python::tuple PyGeCurve3d::closestPointTo4(const PyGeCurve3d& curve2d, const AcGeTol& tol) const
{
    PyAutoLockGIL lock;
    AcGePoint3d pntOnOtherCrv;
    auto pnt = impObj()->closestPointTo(*curve2d.impObj(), pntOnOtherCrv, tol);
    return make_tuple(pnt, pntOnOtherCrv);
}

PyGePointOnCurve3d PyGeCurve3d::getClosestPointTo1(const AcGePoint3d& pnt)
{
    AcGePointOnCurve3d curve;
    impObj()->getClosestPointTo(pnt, curve);
    return PyGePointOnCurve3d(curve);
}

PyGePointOnCurve3d PyGeCurve3d::getClosestPointTo2(const AcGePoint3d& pnt, const AcGeTol& tol)
{
    AcGePointOnCurve3d curve;
    impObj()->getClosestPointTo(pnt, curve, tol);
    return PyGePointOnCurve3d(curve);
}

boost::python::tuple PyGeCurve3d::getClosestPointsTo1(const PyGeCurve3d& curve)
{
    PyAutoLockGIL lock;
    AcGePointOnCurve3d curvea, curveb;
    impObj()->getClosestPointTo(*curve.impObj(), curvea, curveb);
    return make_tuple(PyGePointOnCurve3d(curvea), PyGePointOnCurve3d(curveb));
}

boost::python::tuple PyGeCurve3d::getClosestPointsTo2(const PyGeCurve3d& curve, const AcGeTol& tol)
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

PyGePointOnCurve3d PyGeCurve3d::getNormalPoint1(const AcGePoint3d& pnt)
{
    AcGePointOnCurve3d curve;
    if (auto flag = impObj()->getNormalPoint(pnt, curve); flag == false)
        throw PyAcadErrorStatus(eInvalidInput);
    return PyGePointOnCurve3d(curve);
}

PyGePointOnCurve3d PyGeCurve3d::getNormalPoint2(const AcGePoint3d& pnt, const AcGeTol& tol)
{
    AcGePointOnCurve3d curve;
    if (auto flag = impObj()->getNormalPoint(pnt, curve, tol); flag == false)
        throw PyAcadErrorStatus(eInvalidInput);
    return PyGePointOnCurve3d(curve);
}

PyGeBoundBlock3d PyGeCurve3d::boundBlock1() const
{
    return PyGeBoundBlock3d(impObj()->boundBlock().copy());
}

PyGeBoundBlock3d PyGeCurve3d::boundBlock2(const PyGeInterval& range) const
{
    return PyGeBoundBlock3d(impObj()->boundBlock(range.imp).copy());
}

PyGeBoundBlock3d PyGeCurve3d::orthoBoundBlock1() const
{
    return PyGeBoundBlock3d(impObj()->orthoBoundBlock().copy());
}

PyGeBoundBlock3d PyGeCurve3d::orthoBoundBlock2(const PyGeInterval& range) const
{
    return PyGeBoundBlock3d(impObj()->orthoBoundBlock(range.imp).copy());
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
    return impObj()->length(fromParam, fromParam);
}

double PyGeCurve3d::length2(double fromParam, double toParam, double tol) const
{
    return impObj()->length(fromParam, fromParam, tol);
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
        throw PyAcadErrorStatus(eInvalidInput);
    return length;
}

double PyGeCurve3d::area2(double startParam, double endParam, const AcGeTol& tol) const
{
    double length = 0;
    if (bool flag = impObj()->area(startParam, endParam, length, tol); flag == false)
        throw PyAcadErrorStatus(eInvalidInput);
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

boost::python::tuple PyGeCurve3d::getSplitCurves(double param)
{
    PyAutoLockGIL lock;
    AcGeCurve3d* p1 = nullptr;
    AcGeCurve3d* p2 = nullptr;
    impObj()->getSplitCurves(param, p1, p2);
    return make_tuple(PyGeCurve3d(p1), PyGeCurve3d(p2));
}

//TODO: Test ... leak... looks wonky?
boost::python::list PyGeCurve3d::explode1()
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
boost::python::list PyGeCurve3d::explode2(const PyGeInterval& interval)
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

boost::python::list PyGeCurve3d::getSamplePoints1(int numSample) const
{
    PyAutoLockGIL lock;
    AcGePoint3dArray pointArray;
    boost::python::list pointList;
    impObj()->getSamplePoints(numSample, pointArray);
    for (const auto& item : pointArray)
        pointList.append(item);
    return pointList;
}

boost::python::list PyGeCurve3d::getSamplePoints2(double fromParam, double toParam, double approxEps) const
{
    PyAutoLockGIL lock;
    AcGeDoubleArray paramArray;
    AcGePoint3dArray pointArray;
    boost::python::list pointList;
    impObj()->getSamplePoints(fromParam, toParam, approxEps, pointArray, paramArray);
    for (const auto& item : pointArray)
        pointList.append(item);
    return pointList;
}

PyGeCurve3d PyGeCurve3d::cast(const PyGeEntity3d& src)
{
    if (!src.impObj()->isKindOf(AcGe::EntityId::kCurve3d))
        PyThrowBadEs(Acad::eNotThatKindOfClass);
    return PyGeEntity3dCast<PyGeCurve3d>(src);
}

PyGeCurve3d PyGeCurve3d::copycast(const PyGeEntity3d& src)
{
    if (!src.impObj()->isKindOf(AcGe::EntityId::kCurve3d))
        PyThrowBadEs(Acad::eNotThatKindOfClass);
    return PyGeCurve3d(src.impObj()->copy());
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
    class_<PyGeCircArc3d, bases<PyGeCurve3d>>("CircArc3d")
        .def(init<>())
        .def(init<const AcGePoint3d&, const AcGeVector3d&, double>())
        .def(init<const AcGePoint3d&, const AcGeVector3d&, const AcGeVector3d&, double, double, double>())
        .def(init<const AcGePoint3d&, const AcGePoint3d&, const AcGePoint3d&>())
        .def("closestPointToPlane", &PyGeCircArc3d::closestPointToPlane1)
        .def("closestPointToPlane", &PyGeCircArc3d::closestPointToPlane2)
        .def("intersectWith", &PyGeCircArc3d::intersectWith1)
        .def("intersectWith", &PyGeCircArc3d::intersectWith2)
        .def("intersectWith", &PyGeCircArc3d::intersectWith3)
        .def("intersectWith", &PyGeCircArc3d::intersectWith4)
        .def("intersectWith", &PyGeCircArc3d::intersectWith5)
        .def("intersectWith", &PyGeCircArc3d::intersectWith6)
        .def("projIntersectWith", &PyGeCircArc3d::projIntersectWith1)
        .def("projIntersectWith", &PyGeCircArc3d::projIntersectWith2)
        .def("tangent", &PyGeCircArc3d::tangent1)
        .def("tangent", &PyGeCircArc3d::tangent2)
        .def("getPlane", &PyGeCircArc3d::getPlane)
        .def("isInside", &PyGeCircArc3d::isInside1)
        .def("isInside", &PyGeCircArc3d::isInside2)
        .def("center", &PyGeCircArc3d::center)
        .def("normal", &PyGeCircArc3d::normal)
        .def("refVec", &PyGeCircArc3d::refVec)
        .def("radius", &PyGeCircArc3d::radius)
        .def("startAng", &PyGeCircArc3d::startAng)
        .def("endAng", &PyGeCircArc3d::endAng)
        .def("startPoint", &PyGeCircArc3d::startPoint)
        .def("endPoint", &PyGeCircArc3d::endPoint)
        .def("setCenter", &PyGeCircArc3d::setCenter)
        .def("setAxes", &PyGeCircArc3d::setAxes)
        .def("setRadius", &PyGeCircArc3d::setRadius)
        .def("setAngles", &PyGeCircArc3d::setAngles)
        .def("set", &PyGeCircArc3d::set1)
        .def("set", &PyGeCircArc3d::set2)
        .def("set", &PyGeCircArc3d::set3)
        .def("set", &PyGeCircArc3d::set4)
        .def("set", &PyGeCircArc3d::set5)
        .def("cast", &PyGeCircArc3d::cast).staticmethod("cast")
        .def("copycast", &PyGeCircArc3d::copycast).staticmethod("copycast")
        .def("className", &PyGeCircArc3d::className).staticmethod("className")
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

boost::python::tuple PyGeCircArc3d::closestPointToPlane1(const PyGePlanarEnt& plane)
{
    PyAutoLockGIL lock;
    AcGePoint3d pointOnPlane;
    auto result = impObj()->closestPointToPlane(*plane.impObj(), pointOnPlane);
    return boost::python::make_tuple(result, pointOnPlane);
}

boost::python::tuple PyGeCircArc3d::closestPointToPlane2(const PyGePlanarEnt& plane, const AcGeTol& tol)
{
    PyAutoLockGIL lock;
    AcGePoint3d pointOnPlane;
    auto result = impObj()->closestPointToPlane(*plane.impObj(), pointOnPlane, tol);
    return boost::python::make_tuple(result, pointOnPlane);
}

boost::python::tuple PyGeCircArc3d::intersectWith1(const PyGeLinearEnt3d& line)
{
    PyAutoLockGIL lock;
    int intn = 0;
    AcGePoint3d p1, p2;
    auto result = impObj()->intersectWith(*line.impObj(), intn, p1, p2);
    return boost::python::make_tuple(result, intn, p1, p2);
}

boost::python::tuple PyGeCircArc3d::intersectWith2(const PyGeLinearEnt3d& line, const AcGeTol& tol)
{
    PyAutoLockGIL lock;
    int intn = 0;
    AcGePoint3d p1, p2;
    auto result = impObj()->intersectWith(*line.impObj(), intn, p1, p2, tol);
    return boost::python::make_tuple(result, intn, p1, p2);
}

boost::python::tuple PyGeCircArc3d::intersectWith3(const PyGeCircArc3d& line)
{
    PyAutoLockGIL lock;
    int intn = 0;
    AcGePoint3d p1, p2;
    auto result = impObj()->intersectWith(*line.impObj(), intn, p1, p2);
    return boost::python::make_tuple(result, intn, p1, p2);
}

boost::python::tuple PyGeCircArc3d::intersectWith4(const PyGeCircArc3d& line, const AcGeTol& tol)
{
    PyAutoLockGIL lock;
    int intn = 0;
    AcGePoint3d p1, p2;
    auto result = impObj()->intersectWith(*line.impObj(), intn, p1, p2, tol);
    return boost::python::make_tuple(result, intn, p1, p2);
}

boost::python::tuple PyGeCircArc3d::intersectWith5(const PyGePlanarEnt& line)
{
    PyAutoLockGIL lock;
    int intn = 0;
    AcGePoint3d p1, p2;
    auto result = impObj()->intersectWith(*line.impObj(), intn, p1, p2);
    return boost::python::make_tuple(result, intn, p1, p2);
}

boost::python::tuple PyGeCircArc3d::intersectWith6(const PyGePlanarEnt& line, const AcGeTol& tol)
{
    PyAutoLockGIL lock;
    int intn = 0;
    AcGePoint3d p1, p2;
    auto result = impObj()->intersectWith(*line.impObj(), intn, p1, p2, tol);
    return boost::python::make_tuple(result, intn, p1, p2);
}

boost::python::tuple PyGeCircArc3d::projIntersectWith1(const PyGeLinearEnt3d& line, const AcGeVector3d& projDir)
{
    PyAutoLockGIL lock;
    int intn = 0;
    AcGePoint3d p1, p2, p3, p4;
    auto result = impObj()->projIntersectWith(*line.impObj(), projDir, intn, p1, p2, p3, p4);
    return boost::python::make_tuple(result, intn, p1, p2, p3, p4);
}

boost::python::tuple PyGeCircArc3d::projIntersectWith2(const PyGeLinearEnt3d& line, const AcGeVector3d& projDir, const AcGeTol& tol)
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

PyGePlane PyGeCircArc3d::getPlane()
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

void PyGeCircArc3d::setCenter(const AcGePoint3d& val)
{
    impObj()->setCenter(val);
}

void PyGeCircArc3d::setAxes(const AcGeVector3d& normal, const AcGeVector3d& refVec)
{
    impObj()->setAxes(normal, refVec);
}

void PyGeCircArc3d::setRadius(double val)
{
    impObj()->setRadius(val);
}

void PyGeCircArc3d::setAngles(double startAngle, double endAngle)
{
    impObj()->setAngles(startAngle, endAngle);
}

void PyGeCircArc3d::set1(const AcGePoint3d& cent, const AcGeVector3d& nrm, double radius)
{
    impObj()->set(cent, nrm, radius);
}

void PyGeCircArc3d::set2(const AcGePoint3d& cent, const AcGeVector3d& nrm, const AcGeVector3d& refVec, double radius, double startAngle, double endAngle)
{
    impObj()->set(cent, nrm, refVec, radius, startAngle, endAngle);
}

void PyGeCircArc3d::set3(const AcGePoint3d& startPoint, const AcGePoint3d& pnt, const AcGePoint3d& endPoint)
{
    impObj()->set(startPoint, pnt, endPoint);
}

void PyGeCircArc3d::set4(const PyGeCurve3d& curve1, const PyGeCurve3d& curve2, double radius)
{
    double param1;
    double param2;
    Adesk::Boolean success;
    impObj()->set(*curve1.impObj(), *curve2.impObj(), radius, param1, param2, success);
    if (success == false)
        throw PyAcadErrorStatus(eInvalidInput);
}

void PyGeCircArc3d::set5(const PyGeCurve3d& curve1, const PyGeCurve3d& curve2, const PyGeCurve3d& curve3)
{
    double param1;
    double param2;
    double param3;
    Adesk::Boolean success;
    impObj()->set(*curve1.impObj(), *curve2.impObj(), *curve3.impObj(), param1, param2, param3, success);
    if (success == false)
        throw PyAcadErrorStatus(eInvalidInput);
}

PyGeCircArc3d PyGeCircArc3d::cast(const PyGeEntity3d& src)
{
    if (!src.impObj()->isKindOf(AcGe::EntityId::kCircArc3d))
        PyThrowBadEs(Acad::eNotThatKindOfClass);
    return PyGeEntity3dCast<PyGeCircArc3d>(src);
}

PyGeCircArc3d PyGeCircArc3d::copycast(const PyGeEntity3d& src)
{
    if (!src.impObj()->isKindOf(AcGe::EntityId::kCircArc3d))
        PyThrowBadEs(Acad::eInvalidInput);
    return PyGeCircArc3d(src.impObj()->copy());
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
void makePyGeCompositeCurve3dWrapper()
{
    class_<PyGeCompositeCurve3d, bases<PyGeCurve3d>>("CompositeCurve3d")
        .def(init<>())
        .def(init<const boost::python::list&>())
        .def(init<const boost::python::list&, const boost::python::list&>())
        .def("getCurveList", &PyGeCompositeCurve3d::getCurveList)
        .def("setCurveList", &PyGeCompositeCurve3d::setCurveList1)
        .def("setCurveList", &PyGeCompositeCurve3d::setCurveList2)
        .def("globalToLocalParam", &PyGeCompositeCurve3d::globalToLocalParam)
        .def("localToGlobalParam", &PyGeCompositeCurve3d::localToGlobalParam)
        .def("cast", &PyGeCompositeCurve3d::cast).staticmethod("cast")
        .def("copycast", &PyGeCompositeCurve3d::copycast).staticmethod("copycast")
        .def("className", &PyGeCompositeCurve3d::className).staticmethod("className")
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

void PyGeCompositeCurve3d::setCurveList1(const boost::python::list& curveList)
{
    impObj()->setCurveList(PyListToGe3dVoidPointerArray(curveList));
}

void PyGeCompositeCurve3d::setCurveList2(const boost::python::list& curveList, const boost::python::list& isOwnerOfCurves)
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

PyGeCompositeCurve3d PyGeCompositeCurve3d::cast(const PyGeEntity3d& src)
{
    if (!src.impObj()->isKindOf(AcGe::EntityId::kCompositeCrv3d))
        PyThrowBadEs(Acad::eNotThatKindOfClass);
    return PyGeEntity3dCast<PyGeCompositeCurve3d>(src);
}

PyGeCompositeCurve3d PyGeCompositeCurve3d::copycast(const PyGeEntity3d& src)
{
    if (!src.impObj()->isKindOf(AcGe::EntityId::kCompositeCrv3d))
        PyThrowBadEs(Acad::eNotThatKindOfClass);
    return PyGeCompositeCurve3d(src.impObj()->copy());
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
    class_<PyGeEllipArc3d, bases<PyGeCurve3d>>("EllipArc3d")
        .def(init<>())
        .def(init<const PyGeCircArc3d&>())
        .def(init<const AcGePoint3d&, const AcGeVector3d&, const AcGeVector3d&, double, double>())
        .def(init<const AcGePoint3d&, const AcGeVector3d&, const AcGeVector3d&, double, double, double, double>())
        .def("closestPointToPlane", &PyGeEllipArc3d::closestPointToPlane1)
        .def("closestPointToPlane", &PyGeEllipArc3d::closestPointToPlane2)
        .def("intersectWith", &PyGeEllipArc3d::intersectWith1)
        .def("intersectWith", &PyGeEllipArc3d::intersectWith2)
        .def("intersectWith", &PyGeEllipArc3d::intersectWith3)
        .def("intersectWith", &PyGeEllipArc3d::intersectWith4)
        .def("projIntersectWith", &PyGeEllipArc3d::projIntersectWith1)
        .def("projIntersectWith", &PyGeEllipArc3d::projIntersectWith2)
        .def("getPlane", &PyGeEllipArc3d::getPlane)
        .def("isCircular", &PyGeEllipArc3d::isCircular1)
        .def("isCircular", &PyGeEllipArc3d::isCircular2)
        .def("isInside", &PyGeEllipArc3d::isInside1)
        .def("isInside", &PyGeEllipArc3d::isInside2)
        .def("center", &PyGeEllipArc3d::center)
        .def("minorRadius", &PyGeEllipArc3d::minorRadius)
        .def("majorRadius", &PyGeEllipArc3d::majorRadius)
        .def("minorAxis", &PyGeEllipArc3d::minorAxis)
        .def("majorAxis", &PyGeEllipArc3d::majorAxis)
        .def("normal", &PyGeEllipArc3d::normal)
        .def("startAng", &PyGeEllipArc3d::startAng)
        .def("endAng", &PyGeEllipArc3d::endAng)
        .def("startPoint", &PyGeEllipArc3d::startPoint)
        .def("endPoint", &PyGeEllipArc3d::endPoint)
        .def("setCenter", &PyGeEllipArc3d::setCenter)
        .def("setMinorRadius", &PyGeEllipArc3d::setMinorRadius)
        .def("setMajorRadius", &PyGeEllipArc3d::setMajorRadius)
        .def("setAxes", &PyGeEllipArc3d::setAxes)
        .def("setAngles", &PyGeEllipArc3d::setAngles)
        .def("set", &PyGeEllipArc3d::set1)
        .def("set", &PyGeEllipArc3d::set2)
        .def("set", &PyGeEllipArc3d::set3)
        .def("cast", &PyGeEllipArc3d::cast).staticmethod("cast")
        .def("copycast", &PyGeEllipArc3d::copycast).staticmethod("copycast")
        .def("className", &PyGeEllipArc3d::className).staticmethod("className")
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

PyGeEllipArc3d::PyGeEllipArc3d(const AcGeEllipArc3d& ell)
    : PyGeCurve3d(new AcGeEllipArc3d(ell))
{
}

PyGeEllipArc3d::PyGeEllipArc3d(const PyGeCircArc3d& arc)
    : PyGeCurve3d(new AcGeEllipArc3d(*arc.impObj()))
{
}

PyGeEllipArc3d::PyGeEllipArc3d(const AcGePoint3d& cent, const AcGeVector3d& majorAxis, const AcGeVector3d& minorAxis, double majorRadius, double minorRadius)
    : PyGeCurve3d(new AcGeEllipArc3d(cent, majorAxis, minorAxis, majorRadius, minorRadius))
{
}

PyGeEllipArc3d::PyGeEllipArc3d(const AcGePoint3d& cent, const AcGeVector3d& majorAxis, const AcGeVector3d& minorAxis, double majorRadius, double minorRadius, double ang1, double ang2)
    : PyGeCurve3d(new AcGeEllipArc3d(cent, majorAxis, minorAxis, majorRadius, minorRadius, ang1, ang2))
{
}

boost::python::tuple PyGeEllipArc3d::closestPointToPlane1(const PyGePlanarEnt& plane)
{
    PyAutoLockGIL lock;
    AcGePoint3d pointOnPlane;
    auto result = impObj()->closestPointToPlane(*plane.impObj(), pointOnPlane);
    return boost::python::make_tuple(result, pointOnPlane);
}

boost::python::tuple PyGeEllipArc3d::closestPointToPlane2(const PyGePlanarEnt& plane, const AcGeTol& tol)
{
    PyAutoLockGIL lock;
    AcGePoint3d pointOnPlane;
    auto result = impObj()->closestPointToPlane(*plane.impObj(), pointOnPlane, tol);
    return boost::python::make_tuple(result, pointOnPlane);
}

boost::python::tuple PyGeEllipArc3d::intersectWith1(const PyGeLinearEnt3d& line)
{
    PyAutoLockGIL lock;
    int intn = 0;
    AcGePoint3d p1, p2;
    auto result = impObj()->intersectWith(*line.impObj(), intn, p1, p2);
    return boost::python::make_tuple(result, intn, p1, p2);
}

boost::python::tuple PyGeEllipArc3d::intersectWith2(const PyGeLinearEnt3d& line, const AcGeTol& tol)
{
    PyAutoLockGIL lock;
    int intn = 0;
    AcGePoint3d p1, p2;
    auto result = impObj()->intersectWith(*line.impObj(), intn, p1, p2, tol);
    return boost::python::make_tuple(result, intn, p1, p2);
}

boost::python::tuple PyGeEllipArc3d::intersectWith3(const PyGePlanarEnt& line)
{
    PyAutoLockGIL lock;
    int intn = 0;
    AcGePoint3d p1, p2;
    auto result = impObj()->intersectWith(*line.impObj(), intn, p1, p2);
    return boost::python::make_tuple(result, intn, p1, p2);
}

boost::python::tuple PyGeEllipArc3d::intersectWith4(const PyGePlanarEnt& line, const AcGeTol& tol)
{
    PyAutoLockGIL lock;
    int intn = 0;
    AcGePoint3d p1, p2;
    auto result = impObj()->intersectWith(*line.impObj(), intn, p1, p2, tol);
    return boost::python::make_tuple(result, intn, p1, p2);
}

boost::python::tuple PyGeEllipArc3d::projIntersectWith1(const PyGeLinearEnt3d& line, const AcGeVector3d& projDir)
{
    PyAutoLockGIL lock;
    int intn = 0;
    AcGePoint3d p1, p2, p3, p4;
    auto result = impObj()->projIntersectWith(*line.impObj(), projDir, intn, p1, p2, p3, p4);
    return boost::python::make_tuple(result, intn, p1, p2, p3, p4);
}

boost::python::tuple PyGeEllipArc3d::projIntersectWith2(const PyGeLinearEnt3d& line, const AcGeVector3d& projDir, const AcGeTol& tol)
{
    PyAutoLockGIL lock;
    int intn = 0;
    AcGePoint3d p1, p2, p3, p4;
    auto result = impObj()->projIntersectWith(*line.impObj(), projDir, intn, p1, p2, p3, p4, tol);
    return boost::python::make_tuple(result, intn, p1, p2, p3, p4);
}

PyGePlane PyGeEllipArc3d::getPlane()
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

void PyGeEllipArc3d::setCenter(const AcGePoint3d& cent)
{
    impObj()->setCenter(cent);
}

void PyGeEllipArc3d::setMinorRadius(double rad)
{
    impObj()->setMinorRadius(rad);
}

void PyGeEllipArc3d::setMajorRadius(double rad)
{
    impObj()->setMajorRadius(rad);
}

void PyGeEllipArc3d::setAxes(const AcGeVector3d& majorAxis, const AcGeVector3d& minorAxis)
{
    impObj()->setAxes(majorAxis, minorAxis);
}

void PyGeEllipArc3d::setAngles(double startAngle, double endAngle)
{
    impObj()->setAngles(startAngle, endAngle);
}

void PyGeEllipArc3d::set1(const AcGePoint3d& cent, const AcGeVector3d& majorAxis, const AcGeVector3d& minorAxis, double majorRadius, double minorRadius)
{
    impObj()->set(cent, majorAxis, minorAxis, majorRadius, minorRadius);
}

void PyGeEllipArc3d::set2(const AcGePoint3d& cent, const AcGeVector3d& majorAxis, const AcGeVector3d& minorAxis, double majorRadius, double minorRadius, double startAngle, double endAngle)
{
    impObj()->set(cent, majorAxis, minorAxis, majorRadius, minorRadius, startAngle, endAngle);
}

void PyGeEllipArc3d::set3(const PyGeCircArc3d& arc)
{
    impObj()->set(*arc.impObj());
}

PyGeEllipArc3d PyGeEllipArc3d::cast(const PyGeEntity3d& src)
{
    if (!src.impObj()->isKindOf(AcGe::EntityId::kEllipArc3d))
        PyThrowBadEs(Acad::eNotThatKindOfClass);
    return PyGeEntity3dCast<PyGeEllipArc3d>(src);
}

PyGeEllipArc3d PyGeEllipArc3d::copycast(const PyGeEntity3d& src)
{
    if (!src.impObj()->isKindOf(AcGe::EntityId::kEllipArc3d))
        PyThrowBadEs(Acad::eNotThatKindOfClass);
    return PyGeEllipArc3d(src.impObj()->copy());
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
    class_<PyGeExternalCurve3d, bases<PyGeCurve3d>>("ExternalCurve3d", boost::python::no_init)
        .def("cast", &PyGeExternalCurve3d::cast).staticmethod("cast")
        .def("copycast", &PyGeExternalCurve3d::copycast).staticmethod("copycast")
        .def("className", &PyGeExternalCurve3d::className).staticmethod("className")
        ;
}

PyGeExternalCurve3d::PyGeExternalCurve3d(AcGeEntity3d* pEnt)
    : PyGeCurve3d(pEnt)
{
}

PyGeExternalCurve3d PyGeExternalCurve3d::cast(const PyGeEntity3d& src)
{
    if (!src.impObj()->isKindOf(AcGe::EntityId::kExternalCurve3d))
        PyThrowBadEs(Acad::eInvalidInput);
    return PyGeEntity3dCast<PyGeExternalCurve3d>(src);
}

PyGeExternalCurve3d PyGeExternalCurve3d::copycast(const PyGeEntity3d& src)
{
    if (!src.impObj()->isKindOf(AcGe::EntityId::kExternalCurve3d))
        PyThrowBadEs(Acad::eInvalidInput);
    return PyGeExternalCurve3d(src.impObj()->copy());
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
    class_<PyGeOffsetCurve3d, bases<PyGeCurve3d>>("OffsetCurve3d", boost::python::no_init)
        .def(init<const PyGeCurve3d&, const AcGeVector3d&, double>())
        .def("curve", &PyGeOffsetCurve3d::curve)
        .def("normal", &PyGeOffsetCurve3d::normal)
        .def("offsetDistance", &PyGeOffsetCurve3d::offsetDistance)
        .def("paramDirection", &PyGeOffsetCurve3d::paramDirection)
        .def("transformation", &PyGeOffsetCurve3d::transformation)
        .def("setCurve", &PyGeOffsetCurve3d::setCurve)
        .def("setNormal", &PyGeOffsetCurve3d::setNormal)
        .def("setOffsetDistance", &PyGeOffsetCurve3d::setOffsetDistance)
        .def("cast", &PyGeOffsetCurve3d::cast).staticmethod("cast")
        .def("copycast", &PyGeOffsetCurve3d::copycast).staticmethod("copycast")
        .def("className", &PyGeOffsetCurve3d::className).staticmethod("className")
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

void PyGeOffsetCurve3d::setCurve(const PyGeCurve3d& baseCurve)
{
    impObj()->setCurve(*baseCurve.impObj());
}

void PyGeOffsetCurve3d::setNormal(const AcGeVector3d& planeNormal)
{
    impObj()->setNormal(planeNormal);
}

void PyGeOffsetCurve3d::setOffsetDistance(double offsetDistance)
{
    impObj()->setOffsetDistance(offsetDistance);
}

PyGeOffsetCurve3d PyGeOffsetCurve3d::cast(const PyGeEntity3d& src)
{
    if (!src.impObj()->isKindOf(AcGe::EntityId::kOffsetCurve3d))
        PyThrowBadEs(Acad::eNotThatKindOfClass);
    return PyGeEntity3dCast<PyGeOffsetCurve3d>(src);
}

PyGeOffsetCurve3d PyGeOffsetCurve3d::copycast(const PyGeEntity3d& src)
{
    if (!src.impObj()->isKindOf(AcGe::EntityId::kOffsetCurve3d))
        PyThrowBadEs(Acad::eNotThatKindOfClass);
    return PyGeOffsetCurve3d(src.impObj()->copy());
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
