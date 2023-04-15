#include "stdafx.h"
#include "PyGeCurve2d.h"
#include "PyGeInterval.h"
#include "PyGePointEnt2d.h"

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
    imp->getInterval(iv,s,e);
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
    return imp->distanceTo(*c.impObj(),tol);
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
    return imp->closestPointTo(pnt,tol);
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
    return imp->closestPointTo(*curve2d.impObj(), pntOnOtherCrv,tol);
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
    imp->getClosestPointTo(pnt, curve,tol);
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
    if (auto flag = imp->getNormalPoint(pnt, curve,tol); flag == false)
        throw PyAcadErrorStatus(eInvalidInput);
    return PyGePointOnCurve2d(curve);
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
    static auto wrapper = class_<PyGeOffsetCurve2d, bases<PyGeCurve2d>>("OffsetCurve2d",boost::python::no_init)
        .def(init<const PyGeCurve2d&,double>())
        .def("className", &PyGeOffsetCurve2d::className).staticmethod("className")
        ;
}

PyGeOffsetCurve2d::PyGeOffsetCurve2d(const PyGeCurve2d& baseCurve, double offsetDistance)
    : PyGeCurve2d(new AcGeOffsetCurve2d(*baseCurve.impObj(),offsetDistance))
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
