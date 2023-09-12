#include "stdafx.h"
#include "PyGePointEnt3d.h"
#include "PyGeCurve3d.h"

using namespace boost::python;

//-------------------------------------------------------------------------------------------------------
//PyGePointEnt3d
void makePyGePointEnt3dWrapper()
{
    class_<PyGePointEnt3d, bases<PyGeEntity3d>>("PointEnt3d", boost::python::no_init)
        .def("point3d", &PyGePointEnt3d::point3d)
        .def("className", &PyGePointEnt3d::className).staticmethod("className")
        ;
}

PyGePointEnt3d::PyGePointEnt3d(AcGeEntity3d* src)
    : PyGeEntity3d(src)
{
}

AcGePoint3d PyGePointEnt3d::point3d() const
{
    return impObj()->point3d();
}

std::string PyGePointEnt3d::className()
{
    return "AcGePointEnt3d";
}

AcGePointEnt3d* PyGePointEnt3d::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_imp == nullptr) [[unlikely]]
        throw PyNullObject(src);
        return static_cast<AcGePointEnt3d*>(m_imp.get());
}

//-------------------------------------------------------------------------------------------------------
//PyGePointOnCurve3d
void makePyGePointOnCurve3dWrapper()
{
    class_<PyGePointOnCurve3d, bases<PyGePointEnt3d>>("PointOnCurve3d")
        .def(init<>())
        .def(init<const PyGeCurve3d&>())
        .def(init<const PyGeCurve3d&, double>())
        .def("curve", &PyGePointOnCurve3d::curve)
        .def("parameter", &PyGePointOnCurve3d::parameter)
        .def("point", &PyGePointOnCurve3d::point1)
        .def("point", &PyGePointOnCurve3d::point2)
        .def("point", &PyGePointOnCurve3d::point3)
        .def("deriv", &PyGePointOnCurve3d::deriv1)
        .def("deriv", &PyGePointOnCurve3d::deriv2)
        .def("deriv", &PyGePointOnCurve3d::deriv3)
        .def("isSingular", &PyGePointOnCurve3d::isSingular)
        .def("curvature", &PyGePointOnCurve3d::curvature1)
        .def("curvature", &PyGePointOnCurve3d::curvature2)
        .def("setCurve", &PyGePointOnCurve3d::setCurve)
        .def("setParameter", &PyGePointOnCurve3d::setParameter)
        .def("className", &PyGePointOnCurve3d::className).staticmethod("className")
        ;
}

PyGePointOnCurve3d::PyGePointOnCurve3d()
    : PyGePointEnt3d(new AcGePointOnCurve3d())
{
}

PyGePointOnCurve3d::PyGePointOnCurve3d(const PyGeCurve3d& crv)
    : PyGePointEnt3d(new AcGePointOnCurve3d(*crv.impObj()))
{
}

PyGePointOnCurve3d::PyGePointOnCurve3d(const PyGeCurve3d& crv, double param)
    : PyGePointEnt3d(new AcGePointOnCurve3d(*crv.impObj(), param))
{
}

PyGePointOnCurve3d::PyGePointOnCurve3d(const AcGePointOnCurve3d& src)
    : PyGePointEnt3d(new AcGePointOnCurve3d(src))
{

}

PyGePointOnCurve3d::PyGePointOnCurve3d(AcGeEntity3d* src)
    : PyGePointEnt3d(src)
{
}

PyGeCurve3d PyGePointOnCurve3d::curve() const
{
    return PyGeCurve3d(impObj()->curve());
}

double PyGePointOnCurve3d::parameter() const
{
    return impObj()->parameter();
}

AcGePoint3d PyGePointOnCurve3d::point1() const
{
    return impObj()->point();
}

AcGePoint3d PyGePointOnCurve3d::point2(double param)
{
    return impObj()->point(param);
}

AcGePoint3d PyGePointOnCurve3d::point3(const PyGeCurve3d& crv, double param)
{
    return impObj()->point(*crv.impObj(), param);
}

AcGeVector3d PyGePointOnCurve3d::deriv1(int order) const
{
    return impObj()->deriv(order);
}

AcGeVector3d PyGePointOnCurve3d::deriv2(int order, double param)
{
    return impObj()->deriv(order, param);
}

AcGeVector3d PyGePointOnCurve3d::deriv3(int order, const PyGeCurve3d& crv, double param)
{
    return impObj()->deriv(order, *crv.impObj(), param);
}

Adesk::Boolean PyGePointOnCurve3d::isSingular() const
{
    return impObj()->isSingular();
}

double PyGePointOnCurve3d::curvature1()
{
    double res = 0;
    if (!impObj()->curvature(res))
        throw PyAcadErrorStatus(Acad::eNotApplicable);
    return res;
}

double PyGePointOnCurve3d::curvature2(double param)
{
    double res = 0;
    if (!impObj()->curvature(param,res))
        throw PyAcadErrorStatus(Acad::eNotApplicable);
    return res;
}

void PyGePointOnCurve3d::setCurve(const PyGeCurve3d& crv)
{
    impObj()->setCurve(*crv.impObj());
}

void PyGePointOnCurve3d::setParameter(double param)
{
    impObj()->setParameter(param);
}

std::string PyGePointOnCurve3d::className()
{
    return "AcGePointOnCurve3d";
}

AcGePointOnCurve3d* PyGePointOnCurve3d::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_imp == nullptr) [[unlikely]]
        throw PyNullObject(src);
        return static_cast<AcGePointOnCurve3d*>(m_imp.get());
}

//-------------------------------------------------------------------------------------------------------
//PyGePointOnSurface
void makePyGePointOnSurfaceWrapper()
{
    class_<PyGePointOnSurface, bases<PyGePointEnt3d>>("PointOnCurve3d")
        .def("className", &PyGePointOnSurface::className).staticmethod("className")
        ;
}

PyGePointOnSurface::PyGePointOnSurface()
    : PyGePointEnt3d(new AcGePointOnSurface())
{
}

PyGePointOnSurface::PyGePointOnSurface(AcGeEntity3d* src)
    : PyGePointEnt3d(src)
{
}

std::string PyGePointOnSurface::className()
{
    return "AcGePointOnSurface";
}

AcGePointOnSurface* PyGePointOnSurface::impObj() const
{
    return static_cast<AcGePointOnSurface*>(m_imp.get());
}

//-------------------------------------------------------------------------------------------------------
//PyGePosition3d
void makePyGePosition3dWrapper()
{
    class_<PyGePosition3d, bases<PyGePointEnt3d>>("Position3d")
        .def("className", &PyGePosition3d::className).staticmethod("className")
        ;
}

PyGePosition3d::PyGePosition3d()
    : PyGePointEnt3d(new AcGePosition3d())
{
}


PyGePosition3d::PyGePosition3d(AcGeEntity3d* src)
    : PyGePointEnt3d(src)
{
}

std::string PyGePosition3d::className()
{
    return "AcGePosition3d";
}

AcGePosition3d* PyGePosition3d::impObj() const
{
    return static_cast<AcGePosition3d*>(m_imp.get());
}
