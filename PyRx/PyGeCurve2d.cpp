#include "stdafx.h"
#include "PyGeCurve2d.h"
#include "PyGeInterval.h"
#include "PyGePointEnt2d.h"
#include "PyGeLinearEnt2d.h"

using namespace boost::python;

//-----------------------------------------------------------------------------------------
//PyGeCurve2d wrapper
void makePyGeCurve2dWrapper()
{
    static auto wrapper = class_<PyGeCurve2d, bases<PyGeEntity2d>>("Curve2d", boost::python::no_init)
        .def("className", &PyGeCurve2d::className).staticmethod("className")
        ;
}

PyGeCurve2d::PyGeCurve2d(AcGeEntity2d* pEnt)
    : PyGeEntity2d(pEnt)
{
}

PyGeInterval PyGeCurve2d::getInterval() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    AcGeInterval iv;
    imp->getInterval(iv);
    return PyGeInterval(iv);
}

AcGePoint2d PyGeCurve2d::getStartPoint() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    AcGeInterval iv;
    AcGePoint2d s, e;
    imp->getInterval(iv, s, e);
    return s;
}

AcGePoint2d PyGeCurve2d::getEndPoint() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    AcGeInterval iv;
    AcGePoint2d s, e;
    imp->getInterval(iv, s, e);
    return e;
}

PyGeCurve2d& PyGeCurve2d::reverseParam()
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    imp->reverseParam();
    return *this;
}

PyGeCurve2d& PyGeCurve2d::setInterval1()
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    imp->setInterval();
    return *this;
}

Adesk::Boolean PyGeCurve2d::setInterval2(const PyGeInterval& intrvl)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setInterval(intrvl.imp);
}

double PyGeCurve2d::distanceTo1(const AcGePoint2d& pnt) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->distanceTo(pnt);
}

double PyGeCurve2d::distanceTo2(const AcGePoint2d& pnt, const AcGeTol& tol) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->distanceTo(pnt, tol);
}

double PyGeCurve2d::distanceTo3(const PyGeCurve2d& c) const
{
    auto imp = impObj();
    if (imp == nullptr || c.isNull())
        throw PyNullObject();
    return imp->distanceTo(*c.impObj());
}

double PyGeCurve2d::distanceTo4(const PyGeCurve2d& c, const AcGeTol& tol) const
{
    auto imp = impObj();
    if (imp == nullptr || c.isNull())
        throw PyNullObject();
    return imp->distanceTo(*c.impObj(), tol);
}

AcGePoint2d PyGeCurve2d::closestPointTo1(const AcGePoint2d& pnt) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->closestPointTo(pnt);
}

AcGePoint2d PyGeCurve2d::closestPointTo2(const AcGePoint2d& pnt, const AcGeTol& tol) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->closestPointTo(pnt, tol);
}

AcGePoint2d PyGeCurve2d::closestPointTo3(const PyGeCurve2d& curve2d, AcGePoint2d& pntOnOtherCrv) const
{
    auto imp = impObj();
    if (imp == nullptr || curve2d.isNull())
        throw PyNullObject();
    return imp->closestPointTo(*curve2d.impObj(), pntOnOtherCrv);
}

AcGePoint2d PyGeCurve2d::closestPointTo4(const PyGeCurve2d& curve2d, AcGePoint2d& pntOnOtherCrv, const AcGeTol& tol) const
{
    auto imp = impObj();
    if (imp == nullptr || curve2d.isNull())
        throw PyNullObject();
    return imp->closestPointTo(*curve2d.impObj(), pntOnOtherCrv, tol);
}

PyGePointOnCurve2d PyGeCurve2d::getClosestPointTo1(const AcGePoint2d& pnt)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    AcGePointOnCurve2d curve;
    imp->getClosestPointTo(pnt, curve);
    return PyGePointOnCurve2d(curve);
}

PyGePointOnCurve2d PyGeCurve2d::getClosestPointTo2(const AcGePoint2d& pnt, const AcGeTol& tol)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    AcGePointOnCurve2d curve;
    imp->getClosestPointTo(pnt, curve, tol);
    return PyGePointOnCurve2d(curve);
}

boost::python::tuple PyGeCurve2d::getClosestPointsTo1(const PyGeCurve2d& curve)
{
    auto imp = impObj();
    if (imp == nullptr && curve.isNull())
        throw PyNullObject();
    AcGePointOnCurve2d curvea, curveb;
    imp->getClosestPointTo(*curve.impObj(), curvea, curveb);
    return make_tuple(PyGePointOnCurve2d(curvea), PyGePointOnCurve2d(curveb));
}

boost::python::tuple PyGeCurve2d::getClosestPointsTo2(const PyGeCurve2d& curve, const AcGeTol& tol)
{
    auto imp = impObj();
    if (imp == nullptr && curve.isNull())
        throw PyNullObject();
    AcGePointOnCurve2d curvea, curveb;
    imp->getClosestPointTo(*curve.impObj(), curvea, curveb, tol);
    return make_tuple(PyGePointOnCurve2d(curvea), PyGePointOnCurve2d(curveb));
}

PyGePointOnCurve2d PyGeCurve2d::getNormalPoint1(const AcGePoint2d& pnt)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    AcGePointOnCurve2d curve;
    if (auto flag = imp->getNormalPoint(pnt, curve); flag == false)
        throw PyAcadErrorStatus(eInvalidInput);
    return PyGePointOnCurve2d(curve);
}

PyGePointOnCurve2d PyGeCurve2d::getNormalPoint2(const AcGePoint2d& pnt, const AcGeTol& tol)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    AcGePointOnCurve2d curve;
    if (auto flag = imp->getNormalPoint(pnt, curve, tol); flag == false)
        throw PyAcadErrorStatus(eInvalidInput);
    return PyGePointOnCurve2d(curve);
}

Adesk::Boolean PyGeCurve2d::isOn1(const AcGePoint2d& pnt) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isOn(pnt);
}

Adesk::Boolean PyGeCurve2d::isOn2(const AcGePoint2d& pnt, const AcGeTol& tol) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isOn(pnt, tol);
}

Adesk::Boolean PyGeCurve2d::isOn3(const AcGePoint2d& pnt, double& param) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isOn(pnt, param);
}

Adesk::Boolean PyGeCurve2d::isOn4(const AcGePoint2d& pnt, double& param, const AcGeTol& tol) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isOn(pnt, param, tol);
}

Adesk::Boolean PyGeCurve2d::isOn5(double param) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isOn(param);
}

Adesk::Boolean PyGeCurve2d::isOn6(double param, const AcGeTol& tol) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isOn(param, tol);
}

double PyGeCurve2d::paramOf1(const AcGePoint2d& pnt) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->paramOf(pnt);
}

double PyGeCurve2d::paramOf2(const AcGePoint2d& pnt, const AcGeTol& tol) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->paramOf(pnt, tol);
}

boost::python::list PyGeCurve2d::getTrimmedOffset1(double distance, AcGe::OffsetCrvExtType extensionType) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    boost::python::list curves;
    AcGeVoidPointerArray offsetCurveList;
    imp->getTrimmedOffset(distance, offsetCurveList, extensionType);
    for (const auto& item : offsetCurveList)
        curves.append(PyGeCurve2d(reinterpret_cast<AcGeCurve2d*>(item)));
    return curves;
}

boost::python::list PyGeCurve2d::getTrimmedOffset2(double distance, AcGe::OffsetCrvExtType extensionType, const AcGeTol& tol) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject(); 
    boost::python::list curves;
    AcGeVoidPointerArray offsetCurveList;
    imp->getTrimmedOffset(distance, offsetCurveList, extensionType, tol);
    for (const auto& item : offsetCurveList)
        curves.append(PyGeCurve2d(reinterpret_cast<AcGeCurve2d*>(item)));
    return curves;
}

Adesk::Boolean PyGeCurve2d::isClosed1() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isClosed();
}

Adesk::Boolean PyGeCurve2d::isClosed2(const AcGeTol& tol) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isClosed(tol);
}

boost::python::tuple PyGeCurve2d::isPeriodic() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    double val = 0;
    bool flag = imp->isPeriodic(val);
    return boost::python::make_tuple(flag, val);
}

boost::python::tuple PyGeCurve2d::isLinear1() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    AcGeLine2d line;
    bool flag = imp->isLinear(line);
    return boost::python::make_tuple(flag, PyGeLine2d(line));
}

boost::python::tuple PyGeCurve2d::isLinear2(const AcGeTol& tol) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    AcGeLine2d line;
    bool flag = imp->isLinear(line,tol);
    return boost::python::make_tuple(flag, PyGeLine2d(line));
}

double PyGeCurve2d::length1(double fromParam, double toParam) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
     return imp->length(fromParam, fromParam);
}

double PyGeCurve2d::length2(double fromParam, double toParam, double tol) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->length(fromParam, fromParam,tol);
}

double PyGeCurve2d::paramAtLength1(double datumParam, double length) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->paramAtLength(datumParam, length);
}

double PyGeCurve2d::paramAtLength2(double datumParam, double length, Adesk::Boolean posParamDir, double tol) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->paramAtLength(datumParam, length, posParamDir, tol);
}

double PyGeCurve2d::area1(double startParam, double endParam) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    double length = 0;
    if (bool flag = imp->area(startParam, endParam, length); flag = false)
        throw PyAcadErrorStatus(eInvalidInput);
    return length;
}

double PyGeCurve2d::area2(double startParam, double endParam, const AcGeTol& tol) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    double length = 0;
    if (bool flag = imp->area(startParam, endParam, length, tol); flag = false)
        throw PyAcadErrorStatus(eInvalidInput);
    return length;
}

boost::python::tuple PyGeCurve2d::isDegenerate1() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    AcGeEntity2d* pEnt = nullptr;
    bool flag = imp->isDegenerate(pEnt);
    return boost::python::make_tuple(flag, PyGeEntity2d(pEnt));
#endif
}

boost::python::tuple PyGeCurve2d::isDegenerate2(const AcGeTol& tol) const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    AcGeEntity2d* pEnt = nullptr;
    bool flag = imp->isDegenerate(pEnt, tol);
    return boost::python::make_tuple(flag, PyGeEntity2d(pEnt));
#endif
}

std::string PyGeCurve2d::className()
{
    return "AcGeCurve2d";
}

AcGeCurve2d* PyGeCurve2d::impObj() const
{
    return static_cast<AcGeCurve2d*>(m_imp.get());
}

//-----------------------------------------------------------------------------------------
//AcGeCircArc2d wrapper
void makeAcGeCircArc2dWrapper()
{
    static auto wrapper = class_<PyGeCircArc2d, bases<PyGeCurve2d>>("CircArc2d")
        .def(init<>())
        .def("className", &PyGeCircArc2d::className).staticmethod("className")
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

std::string PyGeCircArc2d::className()
{
    return "AcGeCircArc2d";
}

AcGeCircArc2d* PyGeCircArc2d::impObj() const
{
    return static_cast<AcGeCircArc2d*>(m_imp.get());
}

//----------------------------------------------------------------------------
//AcGeCircArc2d wrapper
void makeAcGeEllipArc2Wrapper()
{
    static auto wrapper = class_<PyGeEllipArc2d, bases<PyGeCurve2d>>("EllipArc2d")
        .def(init<>())
        .def("className", &PyGeEllipArc2d::className).staticmethod("className")
        ;
}

PyGeEllipArc2d::PyGeEllipArc2d()
    : PyGeCurve2d(new AcGeEllipArc2d())
{
}

PyGeEllipArc2d::PyGeEllipArc2d(AcGeEntity2d* pEnt)
    : PyGeCurve2d(pEnt)
{
}

std::string PyGeEllipArc2d::className()
{
    return "AcGeEllipArc2d";
}

AcGeEllipArc2d* PyGeEllipArc2d::impObj() const
{
    return static_cast<AcGeEllipArc2d*>(m_imp.get());
}

//-----------------------------------------------------------------------------------------
//PyGeExternalCurve2d wrapper
void makeAcGeExternalCurve2dWrapper()
{
    static auto wrapper = class_<PyGeExternalCurve2d, bases<PyGeCurve2d>>("ExternalCurve2d", boost::python::no_init)
        .def("className", &PyGeExternalCurve2d::className).staticmethod("className")
        ;
}

PyGeExternalCurve2d::PyGeExternalCurve2d(AcGeEntity2d* pEnt)
    : PyGeCurve2d(pEnt)
{
}

std::string PyGeExternalCurve2d::className()
{
    return "AcGeExternalCurve2d";
}

AcGeExternalCurve2d* PyGeExternalCurve2d::impObj() const
{
    return static_cast<AcGeExternalCurve2d*>(m_imp.get());
}

//-----------------------------------------------------------------------------------------
//AcGeOffsetCurve2d wrapper
void makeAcGeOffsetCurve2dWrapper()
{
    static auto wrapper = class_<PyGeOffsetCurve2d, bases<PyGeCurve2d>>("OffsetCurve2d", boost::python::no_init)
        .def(init<const PyGeCurve2d&, double>())
        .def("className", &PyGeOffsetCurve2d::className).staticmethod("className")
        ;
}

PyGeOffsetCurve2d::PyGeOffsetCurve2d(const PyGeCurve2d& baseCurve, double offsetDistance)
    : PyGeCurve2d(new AcGeOffsetCurve2d(*baseCurve.impObj(), offsetDistance))
{
}

PyGeOffsetCurve2d::PyGeOffsetCurve2d(AcGeEntity2d* pEnt)
    : PyGeCurve2d(pEnt)
{
}

std::string PyGeOffsetCurve2d::className()
{
    return "AcGeOffsetCurve2d";
}

AcGeOffsetCurve2d* PyGeOffsetCurve2d::impObj() const
{
    return static_cast<AcGeOffsetCurve2d*>(m_imp.get());
}

//-----------------------------------------------------------------------------------------
//AcGeCompositeCurve2d wrapper
void makeAcGeCompositeCurve2dWrapper()
{
    static auto wrapper = class_<PyGeCompositeCurve2d, bases<PyGeCurve2d>>("CompositeCurve2d")
        .def("className", &PyGeCompositeCurve2d::className).staticmethod("className")
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

std::string PyGeCompositeCurve2d::className()
{
    return "AcGeCompositeCurve2d";
}

AcGeCompositeCurve2d* PyGeCompositeCurve2d::impObj() const
{
    return static_cast<AcGeCompositeCurve2d*>(m_imp.get());
}
