#include "stdafx.h"
#include "PyGeCurve3d.h"
#include "PyGeInterval.h"
#include "PyGePointEnt3d.h"
using namespace boost::python;
//-----------------------------------------------------------------------------------
//PyGeCurve3d
void makPyGeCurve3dWrapper()
{
    static auto wrapper = class_<PyGeCurve3d, bases<PyGeEntity3d>>("Curve3d", boost::python::no_init)
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

boost::python::tuple PyGeCurve3d::projClosestPointsTo1(const AcGeCurve3d& curve3d, const AcGeVector3d& projectDirection) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    AcGePoint3d pntOnOtherCrv;
    auto pnt = imp->projClosestPointTo(curve3d, projectDirection, pntOnOtherCrv);
    return make_tuple(pnt, pntOnOtherCrv);
}

boost::python::tuple PyGeCurve3d::projClosestPointsTo1(const AcGeCurve3d& curve3d, const AcGeVector3d& projectDirection, const AcGeTol& tol) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    AcGePoint3d pntOnOtherCrv;
    auto pnt = imp->projClosestPointTo(curve3d, projectDirection, pntOnOtherCrv, tol);
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
