#include "stdafx.h"
#include "PyGeCurve3d.h"
#include "PyGeInterval.h"
#include "PyGePointEnt3d.h"
#include "PyGeBoundBlock3d.h"
#include "PyGePlane.h"
#include "PyGeLinearEnt3d.h"
using namespace boost::python;
//-----------------------------------------------------------------------------------
//PyGeCurve3d
void makPyGeCurve3dWrapper()
{
    static auto wrapper = class_<PyGeCurve3d, bases<PyGeEntity3d>>("Curve3d", boost::python::no_init)
        .def("getInterval", &PyGeCurve3d::getInterval)
        .def("getStartPoint", &PyGeCurve3d::getStartPoint)
        .def("getEndPoint", &PyGeCurve3d::getEndPoint)
        .def("reverseParam", &PyGeCurve3d::reverseParam, return_self<>())
        .def("setInterval", &PyGeCurve3d::setInterval1, return_self<>())
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
        .def("isOn", &PyGeCurve3d::isOn5)
        .def("isOn", &PyGeCurve3d::isOn6)
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
        .def("isPeriodic", &PyGeCurve3d::isPeriodic)
        .def("length", &PyGeCurve3d::length1)
        .def("length", &PyGeCurve3d::length2)
        .def("paramAtLength", &PyGeCurve3d::paramAtLength1)
        .def("paramAtLength", &PyGeCurve3d::paramAtLength2)
        .def("area", &PyGeCurve3d::area1)
        .def("area", &PyGeCurve3d::area2)
        .def("isDegenerate", &PyGeCurve3d::isDegenerate1)
        .def("isDegenerate", &PyGeCurve3d::isDegenerate2)
        .def("getSplitCurves", &PyGeCurve3d::getSplitCurves)
        .def("explode", &PyGeCurve3d::explode1)
        .def("explode", &PyGeCurve3d::explode2)
        .def("hasStartPoint", &PyGeCurve3d::hasStartPoint)
        .def("hasEndPoint", &PyGeCurve3d::hasEndPoint)
        .def("evalPoint", &PyGeCurve3d::evalPoint1)
        .def("evalPoint", &PyGeCurve3d::evalPoint2)
        .def("getSamplePoints", &PyGeCurve3d::getSamplePoints1)
        .def("getSamplePoints", &PyGeCurve3d::getSamplePoints2)
        .def("className", &PyGeCurve3d::className).staticmethod("className")
        ;
}

PyGeCurve3d::PyGeCurve3d(AcGeEntity3d* pEnt)
    :PyGeEntity3d(pEnt)
{
}

PyGeInterval PyGeCurve3d::getInterval() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    AcGeInterval iv;
    imp->getInterval(iv);
    return PyGeInterval(iv);
}

AcGePoint3d PyGeCurve3d::getStartPoint() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    AcGeInterval iv;
    AcGePoint3d s, e;
    imp->getInterval(iv, s, e);
    return s;
}

AcGePoint3d PyGeCurve3d::getEndPoint() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    AcGeInterval iv;
    AcGePoint3d s, e;
    imp->getInterval(iv, s, e);
    return e;
}

PyGeCurve3d& PyGeCurve3d::reverseParam()
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    imp->reverseParam();
    return *this;
}

PyGeCurve3d& PyGeCurve3d::setInterval1()
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    imp->setInterval();
    return *this;
}

bool PyGeCurve3d::setInterval2(const PyGeInterval& intrvl)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setInterval(intrvl.imp);
}

double PyGeCurve3d::distanceTo1(const AcGePoint3d& pnt) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->distanceTo(pnt);
}

double PyGeCurve3d::distanceTo2(const AcGePoint3d& pnt, const AcGeTol& tol) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->distanceTo(pnt, tol);
}

double PyGeCurve3d::distanceTo3(const PyGeCurve3d& c) const
{
    auto imp = impObj();
    if (imp == nullptr || c.isNull())
        throw PyNullObject();
    return imp->distanceTo(*c.impObj());
}

double PyGeCurve3d::distanceTo4(const PyGeCurve3d& c, const AcGeTol& tol) const
{
    auto imp = impObj();
    if (imp == nullptr || c.isNull())
        throw PyNullObject();
    return imp->distanceTo(*c.impObj(), tol);
}

AcGePoint3d PyGeCurve3d::closestPointTo1(const AcGePoint3d& pnt) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->closestPointTo(pnt);
}

AcGePoint3d PyGeCurve3d::closestPointTo2(const AcGePoint3d& pnt, const AcGeTol& tol) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->closestPointTo(pnt, tol);
}

boost::python::tuple PyGeCurve3d::closestPointTo3(const PyGeCurve3d& curve2d) const
{
    auto imp = impObj();
    if (imp == nullptr || curve2d.isNull())
        throw PyNullObject();
    AcGePoint3d pntOnOtherCrv;
    auto pnt = imp->closestPointTo(*curve2d.impObj(), pntOnOtherCrv);
    return make_tuple(pnt, pntOnOtherCrv);
}

boost::python::tuple PyGeCurve3d::closestPointTo4(const PyGeCurve3d& curve2d, const AcGeTol& tol) const
{
    auto imp = impObj();
    if (imp == nullptr || curve2d.isNull())
        throw PyNullObject();
    AcGePoint3d pntOnOtherCrv;
    auto pnt = imp->closestPointTo(*curve2d.impObj(), pntOnOtherCrv, tol);
    return make_tuple(pnt, pntOnOtherCrv);
}

PyGePointOnCurve3d PyGeCurve3d::getClosestPointTo1(const AcGePoint3d& pnt)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    AcGePointOnCurve3d curve;
    imp->getClosestPointTo(pnt, curve);
    return PyGePointOnCurve3d(curve);
}

PyGePointOnCurve3d PyGeCurve3d::getClosestPointTo2(const AcGePoint3d& pnt, const AcGeTol& tol)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    AcGePointOnCurve3d curve;
    imp->getClosestPointTo(pnt, curve, tol);
    return PyGePointOnCurve3d(curve);
}

boost::python::tuple PyGeCurve3d::getClosestPointsTo1(const PyGeCurve3d& curve)
{
    auto imp = impObj();
    if (imp == nullptr && curve.isNull())
        throw PyNullObject();
    AcGePointOnCurve3d curvea, curveb;
    imp->getClosestPointTo(*curve.impObj(), curvea, curveb);
    return make_tuple(PyGePointOnCurve3d(curvea), PyGePointOnCurve3d(curveb));
}

boost::python::tuple PyGeCurve3d::getClosestPointsTo2(const PyGeCurve3d& curve, const AcGeTol& tol)
{
    auto imp = impObj();
    if (imp == nullptr && curve.isNull())
        throw PyNullObject();
    AcGePointOnCurve3d curvea, curveb;
    imp->getClosestPointTo(*curve.impObj(), curvea, curveb, tol);
    return make_tuple(PyGePointOnCurve3d(curvea), PyGePointOnCurve3d(curveb));
}

AcGePoint3d PyGeCurve3d::projClosestPointTo1(const AcGePoint3d& pnt, const AcGeVector3d& projectDirection) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->projClosestPointTo(pnt, projectDirection);
}

AcGePoint3d PyGeCurve3d::projClosestPointTo2(const AcGePoint3d& pnt, const AcGeVector3d& projectDirection, const AcGeTol& tol) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->projClosestPointTo(pnt, projectDirection, tol);
}

boost::python::tuple PyGeCurve3d::projClosestPointsTo1(const PyGeCurve3d& curve3d, const AcGeVector3d& projectDirection) const
{
    auto imp = impObj();
    if (imp == nullptr || curve3d.isNull())
        throw PyNullObject();
    AcGePoint3d pntOnOtherCrv;
    auto pnt = imp->projClosestPointTo(*curve3d.impObj(), projectDirection, pntOnOtherCrv);
    return make_tuple(pnt, pntOnOtherCrv);
}

boost::python::tuple PyGeCurve3d::projClosestPointsTo2(const PyGeCurve3d& curve3d, const AcGeVector3d& projectDirection, const AcGeTol& tol) const
{
    auto imp = impObj();
    if (imp == nullptr || curve3d.isNull())
        throw PyNullObject();
    AcGePoint3d pntOnOtherCrv;
    auto pnt = imp->projClosestPointTo(*curve3d.impObj(), projectDirection, pntOnOtherCrv, tol);
    return make_tuple(pnt, pntOnOtherCrv);
}

PyGePointOnCurve3d PyGeCurve3d::getProjClosestPointTo1(const AcGePoint3d& pnt, const AcGeVector3d& projectDirection) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    AcGePointOnCurve3d curve;
    imp->getProjClosestPointTo(pnt, projectDirection, curve);
    return PyGePointOnCurve3d(curve);
}

PyGePointOnCurve3d PyGeCurve3d::getProjClosestPointTo2(const AcGePoint3d& pnt, const AcGeVector3d& projectDirection, const AcGeTol& tol) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    AcGePointOnCurve3d curve;
    imp->getProjClosestPointTo(pnt, projectDirection, curve, tol);
    return PyGePointOnCurve3d(curve);
}

boost::python::tuple PyGeCurve3d::getProjClosestPointsTo1(const PyGeCurve3d& curve3d, const AcGeVector3d& projectDirection) const
{
    auto imp = impObj();
    if (imp == nullptr && curve3d.isNull())
        throw PyNullObject();
    AcGePointOnCurve3d curvea, curveb;
    imp->getProjClosestPointTo(*curve3d.impObj(), projectDirection, curvea, curveb);
    return make_tuple(PyGePointOnCurve3d(curvea), PyGePointOnCurve3d(curveb));
}

boost::python::tuple PyGeCurve3d::getProjClosestPointsTo2(const PyGeCurve3d& curve3d, const AcGeVector3d& projectDirection, const AcGeTol& tol) const
{
    auto imp = impObj();
    if (imp == nullptr && curve3d.isNull())
        throw PyNullObject();
    AcGePointOnCurve3d curvea, curveb;
    imp->getProjClosestPointTo(*curve3d.impObj(), projectDirection, curvea, curveb);
    return make_tuple(PyGePointOnCurve3d(curvea), PyGePointOnCurve3d(curveb), tol);
}

PyGePointOnCurve3d PyGeCurve3d::getNormalPoint1(const AcGePoint3d& pnt)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    AcGePointOnCurve3d curve;
    if (auto flag = imp->getNormalPoint(pnt, curve); flag == false)
        throw PyAcadErrorStatus(eInvalidInput);
    return PyGePointOnCurve3d(curve);
}

PyGePointOnCurve3d PyGeCurve3d::getNormalPoint2(const AcGePoint3d& pnt, const AcGeTol& tol)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    AcGePointOnCurve3d curve;
    if (auto flag = imp->getNormalPoint(pnt, curve, tol); flag == false)
        throw PyAcadErrorStatus(eInvalidInput);
    return PyGePointOnCurve3d(curve);
}

PyGeBoundBlock3d PyGeCurve3d::boundBlock1() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return PyGeBoundBlock3d(imp->boundBlock().copy());
}

PyGeBoundBlock3d PyGeCurve3d::boundBlock2(const PyGeInterval& range) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return PyGeBoundBlock3d(imp->boundBlock(range.imp).copy());
}

PyGeBoundBlock3d PyGeCurve3d::orthoBoundBlock1() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return PyGeBoundBlock3d(imp->orthoBoundBlock().copy());
}

PyGeBoundBlock3d PyGeCurve3d::orthoBoundBlock2(const PyGeInterval& range) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return PyGeBoundBlock3d(imp->orthoBoundBlock(range.imp).copy());
}

PyGeEntity3d PyGeCurve3d::project1(const PyGePlane& projectionPlane, const AcGeVector3d& projectDirection) const
{
    auto imp = impObj();
    if (imp == nullptr || projectionPlane.isNull())
        throw PyNullObject();
    return PyGeEntity3d(imp->project(*projectionPlane.impObj(), projectDirection));
}

PyGeEntity3d PyGeCurve3d::project2(const PyGePlane& projectionPlane, const AcGeVector3d& projectDirection, const AcGeTol& tol) const
{
    auto imp = impObj();
    if (imp == nullptr || projectionPlane.isNull())
        throw PyNullObject();
    return PyGeEntity3d(imp->project(*projectionPlane.impObj(), projectDirection, tol));
}

PyGeEntity3d PyGeCurve3d::orthoProject1(const PyGePlane& projectionPlane) const
{
    auto imp = impObj();
    if (imp == nullptr || projectionPlane.isNull())
        throw PyNullObject();
    return PyGeEntity3d(imp->orthoProject(*projectionPlane.impObj()));
}

PyGeEntity3d PyGeCurve3d::orthoProject2(const PyGePlane& projectionPlane, const AcGeTol& tol) const
{
    auto imp = impObj();
    if (imp == nullptr || projectionPlane.isNull())
        throw PyNullObject();
    return PyGeEntity3d(imp->orthoProject(*projectionPlane.impObj(), tol));
}

bool PyGeCurve3d::isOn1(const AcGePoint3d& pnt) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isOn(pnt);
}

bool PyGeCurve3d::isOn2(const AcGePoint3d& pnt, const AcGeTol& tol) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isOn(pnt, tol);
}

bool PyGeCurve3d::isOn3(const AcGePoint3d& pnt, double& param) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isOn(pnt, param);
}

bool PyGeCurve3d::isOn4(const AcGePoint3d& pnt, double& param, const AcGeTol& tol) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isOn(pnt, param, tol);
}

bool PyGeCurve3d::isOn5(double param) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isOn(param);
}

bool PyGeCurve3d::isOn6(double param, const AcGeTol& tol) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isOn(param, tol);
}

double PyGeCurve3d::paramOf1(const AcGePoint3d& pnt) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->paramOf(pnt);
}

double PyGeCurve3d::paramOf2(const AcGePoint3d& pnt, const AcGeTol& tol) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->paramOf(pnt, tol);
}

boost::python::list PyGeCurve3d::getTrimmedOffset1(double distance, const AcGeVector3d& planeNormal, AcGe::OffsetCrvExtType extensionType) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    boost::python::list curves;
    AcGeVoidPointerArray offsetCurveList;
    imp->getTrimmedOffset(distance, planeNormal, offsetCurveList, extensionType);
    for (const auto& item : offsetCurveList)
        curves.append(PyGeCurve3d(reinterpret_cast<AcGeCurve3d*>(item)));
    return curves;
}

boost::python::list PyGeCurve3d::getTrimmedOffset2(double distance, const AcGeVector3d& planeNormal, AcGe::OffsetCrvExtType extensionType, const AcGeTol& tol) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    boost::python::list curves;
    AcGeVoidPointerArray offsetCurveList;
    imp->getTrimmedOffset(distance, planeNormal, offsetCurveList, extensionType, tol);
    for (const auto& item : offsetCurveList)
        curves.append(PyGeCurve3d(reinterpret_cast<AcGeCurve3d*>(item)));
    return curves;
}

Adesk::Boolean PyGeCurve3d::isClosed1() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isClosed();
}

Adesk::Boolean PyGeCurve3d::isClosed2(const AcGeTol& tol) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isClosed(tol);
}

boost::python::tuple PyGeCurve3d::isPlanar1() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    AcGePlane plane;
    bool flag = imp->isPlanar(plane);
    return make_tuple(flag, PyGePlane(plane));
}

boost::python::tuple PyGeCurve3d::isPlanar2(const AcGeTol& tol) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    AcGePlane plane;
    bool flag = imp->isPlanar(plane, tol);
    return make_tuple(flag, PyGePlane(plane));
}

boost::python::tuple PyGeCurve3d::isLinear1() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    AcGeLine3d plane;
    bool flag = imp->isLinear(plane);
    return make_tuple(flag, PyGeLine3d(plane));
}

boost::python::tuple PyGeCurve3d::isLinear2(const AcGeTol& tol) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    AcGeLine3d plane;
    bool flag = imp->isLinear(plane, tol);
    return make_tuple(flag, PyGeLine3d(plane));
}

boost::python::tuple PyGeCurve3d::isCoplanarWith1(const PyGeCurve3d& curve3d) const
{
    auto imp = impObj();
    if (imp == nullptr || curve3d.isNull())
        throw PyNullObject();
    AcGePlane plane;
    bool flag = imp->isCoplanarWith(*curve3d.impObj(), plane);
    return make_tuple(flag, PyGePlane(plane));
}

boost::python::tuple PyGeCurve3d::isCoplanarWith2(const PyGeCurve3d& curve3d, const AcGeTol& tol) const
{
    auto imp = impObj();
    if (imp == nullptr || curve3d.isNull())
        throw PyNullObject();
    AcGePlane plane;
    bool flag = imp->isCoplanarWith(*curve3d.impObj(), plane, tol);
    return make_tuple(flag, PyGePlane(plane));
}

boost::python::tuple PyGeCurve3d::isPeriodic() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    double val = 0;
    bool flag = imp->isPeriodic(val);
    return boost::python::make_tuple(flag, val);
}

double PyGeCurve3d::length1(double fromParam, double toParam) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->length(fromParam, fromParam);
}

double PyGeCurve3d::length2(double fromParam, double toParam, double tol) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->length(fromParam, fromParam, tol);
}

double PyGeCurve3d::paramAtLength1(double datumParam, double length) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->paramAtLength(datumParam, length);
}

double PyGeCurve3d::paramAtLength2(double datumParam, double length, Adesk::Boolean posParamDir, double tol) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->paramAtLength(datumParam, length, posParamDir, tol);
}

double PyGeCurve3d::area1(double startParam, double endParam) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    double length = 0;
    if (bool flag = imp->area(startParam, endParam, length); flag = false)
        throw PyAcadErrorStatus(eInvalidInput);
    return length;
}

double PyGeCurve3d::area2(double startParam, double endParam, const AcGeTol& tol) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    double length = 0;
    if (bool flag = imp->area(startParam, endParam, length, tol); flag = false)
        throw PyAcadErrorStatus(eInvalidInput);
    return length;
}

boost::python::tuple PyGeCurve3d::isDegenerate1() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    AcGeEntity3d* pEnt = nullptr;
    bool flag = imp->isDegenerate(pEnt);
    return boost::python::make_tuple(flag, PyGeEntity3d(pEnt));
}

boost::python::tuple PyGeCurve3d::isDegenerate2(const AcGeTol& tol) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    AcGeEntity3d* pEnt = nullptr;
    bool flag = imp->isDegenerate(pEnt, tol);
    return boost::python::make_tuple(flag, PyGeEntity3d(pEnt));
}

boost::python::tuple PyGeCurve3d::getSplitCurves(double param)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    AcGeCurve3d* p1 = nullptr;
    AcGeCurve3d* p2 = nullptr;
    imp->getSplitCurves(param, p1, p2);
    return make_tuple(PyGeCurve3d(p1), PyGeCurve3d(p2));
}

boost::python::list PyGeCurve3d::explode1()
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    boost::python::list curves;
    AcGeIntArray newExplodedCurve;
    AcGeVoidPointerArray explodedCurves;
    imp->explode(explodedCurves, newExplodedCurve);
    for (size_t idx = 0; idx < explodedCurves.length(); idx++)
    {
        AcGeCurve3d* pCurve = reinterpret_cast<AcGeCurve3d*>(explodedCurves[idx]);
        curves.append(PyGeCurve3d(pCurve->copy()));
        if (newExplodedCurve[idx] == 1)
            delete pCurve;
    }
    return curves;
}

boost::python::list PyGeCurve3d::explode2(const PyGeInterval& interval)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    boost::python::list curves;
    AcGeIntArray newExplodedCurve;
    AcGeVoidPointerArray explodedCurves;
    imp->explode(explodedCurves, newExplodedCurve, &interval.imp);
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
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    AcGePoint3d pnt;
    return imp->hasStartPoint(pnt);
}

bool PyGeCurve3d::hasEndPoint() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    AcGePoint3d pnt;
    return imp->hasEndPoint(pnt);
}

AcGePoint3d PyGeCurve3d::evalPoint1(double param) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->evalPoint(param);
}

boost::python::tuple PyGeCurve3d::evalPoint2(double param, int numDeriv) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    boost::python::list vecs;
    AcGeVector3dArray derivArray;
    AcGePoint3d pnt = imp->evalPoint(param, numDeriv, derivArray);
    for (const auto& item : derivArray)
        vecs.append(item);
    return boost::python::make_tuple(pnt, vecs);
}

boost::python::list PyGeCurve3d::getSamplePoints1(int numSample) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    AcGePoint3dArray pointArray;
    boost::python::list pointList;
    imp->getSamplePoints(numSample, pointArray);
    for (const auto& item : pointArray)
        pointList.append(item);
    return pointList;
}

boost::python::list PyGeCurve3d::getSamplePoints2(double fromParam, double toParam, double approxEps) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    AcGeDoubleArray paramArray;
    AcGePoint3dArray pointArray;
    boost::python::list pointList;
    imp->getSamplePoints(fromParam, toParam, approxEps, pointArray, paramArray);
    for (const auto& item : pointArray)
        pointList.append(item);
    return pointList;
}

std::string PyGeCurve3d::className()
{
    return "AcGeCurve3d";
}

AcGeCurve3d* PyGeCurve3d::impObj() const
{
    return static_cast<AcGeCurve3d*>(m_imp.get());
}

//-----------------------------------------------------------------------------------
//AcGeCircArc3d
void makAcGeCircArc3dWrapper()
{
    static auto wrapper = class_<PyGeCircArc3d, bases<PyGeCurve3d>>("CircArc3d")
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

std::string PyGeCircArc3d::className()
{
    return "AcGeCircArc3d";
}

AcGeCircArc3d* PyGeCircArc3d::impObj() const
{
    return static_cast<AcGeCircArc3d*>(m_imp.get());
}

//-----------------------------------------------------------------------------------
//AcGeCompositeCurve3d
void makAcGeCompositeCurve3dWrapper()
{
    static auto wrapper = class_<PyGeCompositeCurve3d, bases<PyGeCurve3d>>("CompositeCurve3d")
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

std::string PyGeCompositeCurve3d::className()
{
    return "AcGeCompositeCurve3d";
}

AcGeCompositeCurve3d* PyGeCompositeCurve3d::impObj() const
{
    return static_cast<AcGeCompositeCurve3d*>(m_imp.get());
}


//-----------------------------------------------------------------------------------------
//AcGeCircArc3d wrapper
void makeAcGeEllipArc3dWrapper()
{
    static auto wrapper = class_<PyGeEllipArc3d, bases<PyGeCurve3d>>("EllipArc3d")
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

std::string PyGeEllipArc3d::className()
{
    return "AcGeCompositeCurve3d";
}

AcGeEllipArc3d* PyGeEllipArc3d::impObj() const
{
    return static_cast<AcGeEllipArc3d*>(m_imp.get());
}


//-----------------------------------------------------------------------------------------
//PyGeExternalCurve3d wrapper
void makeAcGeExternalCurve3dWrapper()
{
    static auto wrapper = class_<PyGeExternalCurve3d, bases<PyGeCurve3d>>("ExternalCurve3d", boost::python::no_init)
        .def("className", &PyGeExternalCurve3d::className).staticmethod("className")
        ;
}

PyGeExternalCurve3d::PyGeExternalCurve3d(AcGeEntity3d* pEnt)
    : PyGeCurve3d(pEnt)
{
}

std::string PyGeExternalCurve3d::className()
{
    return "AcGeExternalCurve3d";
}

AcGeExternalCurve3d* PyGeExternalCurve3d::impObj() const
{
    return static_cast<AcGeExternalCurve3d*>(m_imp.get());
}

//-----------------------------------------------------------------------------------------
//AcGeOffsetCurve3d wrapper
void makeAcGeOffsetCurve3dWrapper()
{
    static auto wrapper = class_<PyGeOffsetCurve3d, bases<PyGeCurve3d>>("OffsetCurve3d", boost::python::no_init)
        .def(init<const PyGeCurve3d&, const AcGeVector3d&, double>())
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

std::string PyGeOffsetCurve3d::className()
{
    return "AcGeOffsetCurve3d";
}

AcGeOffsetCurve3d* PyGeOffsetCurve3d::impObj() const
{
    return static_cast<AcGeOffsetCurve3d*>(m_imp.get());
}
