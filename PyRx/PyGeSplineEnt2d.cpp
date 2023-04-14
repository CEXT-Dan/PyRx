#include "stdafx.h"
#include "PyGeSplineEnt2d.h"

using namespace boost::python;
//-----------------------------------------------------------------------------------------
//PyGeSplineEnt2d wrapper
void makePyGeSplineEnt2dWrapper()
{
    static auto wrapper = class_<PyGeSplineEnt2d, bases<PyGeCurve2d>>("SplineEnt2d", boost::python::no_init)
        .def("className", &PyGeSplineEnt2d::className).staticmethod("className")
        ;
}

PyGeSplineEnt2d::PyGeSplineEnt2d(AcGeEntity2d* pEnt)
    : PyGeCurve2d(pEnt)
{
}

std::string PyGeSplineEnt2d::className()
{
    return "AcGeSplineEnt2d";
}

AcGeSplineEnt2d* PyGeSplineEnt2d::impObj() const
{
    return static_cast<AcGeSplineEnt2d*>(m_imp.get());
}

//-----------------------------------------------------------------------------------------
//AcGeCubicSplineCurve2d wrapper
void makAcGeCubicSplineCurve2dWrapper()
{
    static auto wrapper = class_<PyGeCubicSplineCurve2d, bases<PyGeSplineEnt2d>>("CubicSplineCurve2d")
        .def("className", &PyGeCubicSplineCurve2d::className).staticmethod("className")
        ;
}

PyGeCubicSplineCurve2d::PyGeCubicSplineCurve2d()
    : PyGeSplineEnt2d(new AcGeCubicSplineCurve2d())
{
}

PyGeCubicSplineCurve2d::PyGeCubicSplineCurve2d(AcGeEntity2d* pEnt)
 : PyGeSplineEnt2d(pEnt)
{
}

std::string PyGeCubicSplineCurve2d::className()
{
    return "AcGeCubicSplineCurve2d";
}

AcGeCubicSplineCurve2d* PyGeCubicSplineCurve2d::impObj() const
{
    return static_cast<AcGeCubicSplineCurve2d*>(m_imp.get());
}

//-----------------------------------------------------------------------------------------
//AcGeNurbCurve2d  wrapper
void makAcGeNurbCurve2dWrapper()
{
    static auto wrapper = class_<PyGeNurbCurve2d, bases<PyGeSplineEnt2d>>("NurbCurve2d")
        .def("className", &PyGeNurbCurve2d::className).staticmethod("className")
        ;
}

PyGeNurbCurve2d::PyGeNurbCurve2d()
    : PyGeSplineEnt2d(new AcGeNurbCurve2d())
{
}

PyGeNurbCurve2d::PyGeNurbCurve2d(AcGeEntity2d* pEnt)
    : PyGeSplineEnt2d(pEnt)
{
}

std::string PyGeNurbCurve2d::className()
{
    return "AcGeNurbCurve2d";
}

AcGeNurbCurve2d* PyGeNurbCurve2d::impObj() const
{
    return static_cast<AcGeNurbCurve2d*>(m_imp.get());
}

//-----------------------------------------------------------------------------------------
//AcGeNurbCurve2d  wrapper
void makAcGePolyline2dWrapper()
{
    static auto wrapper = class_<PyGePolyline2d, bases<PyGeSplineEnt2d>>("Polyline2d")
        .def("className", &PyGePolyline2d::className).staticmethod("className")
        ;
}

PyGePolyline2d::PyGePolyline2d()
    : PyGeSplineEnt2d(new AcGePolyline2d())
{
}

PyGePolyline2d::PyGePolyline2d(AcGeEntity2d* pEnt)
    : PyGeSplineEnt2d(pEnt)
{
}

std::string PyGePolyline2d::className()
{
    return "AcGePolyline2d";
}

AcGePolyline2d* PyGePolyline2d::impObj() const
{
    return static_cast<AcGePolyline2d*>(m_imp.get());
}
