#include "stdafx.h"
#include "PyGeSplineEnt3d.h"

using namespace boost::python;

//-----------------------------------------------------------------------------------------
//PyGeSplineEnt3d wrapper
void makePyGeSplineEnt3dWrapper()
{
    static auto wrapper = class_<PyGeSplineEnt3d, bases<PyGeCurve3d>>("SplineEnt3d", boost::python::no_init)
        .def("className", &PyGeSplineEnt3d::className).staticmethod("className")
        ;
}

PyGeSplineEnt3d::PyGeSplineEnt3d(AcGeEntity3d* pEnt)
    : PyGeCurve3d(pEnt)
{
}

std::string PyGeSplineEnt3d::className()
{
    return "AcGeSplineEnt3d";
}

AcGeSplineEnt3d* PyGeSplineEnt3d::impObj() const
{
    return static_cast<AcGeSplineEnt3d*>(m_imp.get());
}

//-----------------------------------------------------------------------------------------
//AcGeCubicSplineCurve3d wrapper
void makAcGeCubicSplineCurve3dWrapper()
{
    static auto wrapper = class_<PyGeCubicSplineCurve3d, bases<PyGeSplineEnt3d>>("CubicSplineCurve3d")
        .def("className", &PyGeCubicSplineCurve3d::className).staticmethod("className")
        ;
}

PyGeCubicSplineCurve3d::PyGeCubicSplineCurve3d()
    : PyGeSplineEnt3d(new AcGeCubicSplineCurve3d())
{
}

PyGeCubicSplineCurve3d::PyGeCubicSplineCurve3d(AcGeEntity3d* pEnt)
    : PyGeSplineEnt3d(pEnt)
{
}

std::string PyGeCubicSplineCurve3d::className()
{
    return "AcGeCubicSplineCurve3d";
}

AcGeCubicSplineCurve3d* PyGeCubicSplineCurve3d::impObj() const
{
    return static_cast<AcGeCubicSplineCurve3d*>(m_imp.get());
}

//-----------------------------------------------------------------------------------------
//AcGeNurbCurve3d  wrapper
void makAcGeNurbCurve3dWrapper()
{
    static auto wrapper = class_<PyGeNurbCurve3d, bases<PyGeSplineEnt3d>>("NurbCurve3d")
        .def("className", &PyGeNurbCurve3d::className).staticmethod("className")
        ;
}

PyGeNurbCurve3d::PyGeNurbCurve3d()
    : PyGeSplineEnt3d(new AcGeNurbCurve3d())
{

}

PyGeNurbCurve3d::PyGeNurbCurve3d(AcGeEntity3d* pEnt)
    : PyGeSplineEnt3d(pEnt)
{

}

std::string PyGeNurbCurve3d::className()
{
    return "AcGeNurbCurve3d";
}

AcGeNurbCurve3d* PyGeNurbCurve3d::impObj() const
{
    return static_cast<AcGeNurbCurve3d*>(m_imp.get());
}

//-----------------------------------------------------------------------------------------
//AcGeNurbCurve3d  wrapper
void makAcGePolyline3dWrapper()
{
    static auto wrapper = class_<PyGePolyline3d, bases<PyGeSplineEnt3d>>("Polyline3d")
        .def("className", &PyGeNurbCurve3d::className).staticmethod("className")
        ;
}

PyGePolyline3d::PyGePolyline3d()
    : PyGeSplineEnt3d(new AcGePolyline3d())
{
}

PyGePolyline3d::PyGePolyline3d(AcGeEntity3d* pEnt)
    : PyGeSplineEnt3d(pEnt)
{
}

std::string PyGePolyline3d::className()
{
    return "AcGePolyline3d";
}

AcGePolyline3d* PyGePolyline3d::impObj() const
{
    return static_cast<AcGePolyline3d*>(m_imp.get());
}
