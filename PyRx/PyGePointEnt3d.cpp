#include "stdafx.h"
#include "PyGePointEnt3d.h"

using namespace boost::python;

//-------------------------------------------------------------------------------------------------------
//PyGePointEnt3d
void makePyGePointEnt3dWrapper()
{
    class_<PyGePointEnt3d, bases<PyGeEntity3d>>("PointEnt3d", boost::python::no_init)
        .def("className", &PyGePointEnt3d::className).staticmethod("className")
        ;
}

PyGePointEnt3d::PyGePointEnt3d(AcGeEntity3d* src)
    : PyGeEntity3d(src)
{
}

std::string PyGePointEnt3d::className()
{
    return "AcGePointEnt3d";
}

AcGePointEnt3d* PyGePointEnt3d::impObj() const
{
    return static_cast<AcGePointEnt3d*>(m_imp.get());
}

//-------------------------------------------------------------------------------------------------------
//PyGePointOnCurve3d
void makePyGePointOnCurve3dWrapper()
{
    class_<PyGePointOnCurve3d, bases<PyGePointEnt3d>>("PointOnCurve3d")
        .def("className", &PyGePointEnt3d::className).staticmethod("className")
        ;
}

PyGePointOnCurve3d::PyGePointOnCurve3d()
    : PyGePointEnt3d(new AcGePointOnCurve3d())
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

std::string PyGePointOnCurve3d::className()
{
    return "AcGePointOnCurve3d";
}

AcGePointOnCurve3d* PyGePointOnCurve3d::impObj() const
{
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
