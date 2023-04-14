#include "stdafx.h"
#include "PyGeSplineEnt2d.h"

using namespace boost::python;

void makePyGeSplineEnt2dWrapper()
{
    static auto wrapper = class_<PyGeSplineEnt2d, bases<PyGeCurve2d>>("SplineEnt2d", boost::python::no_init)
        .def("className", &PyGeEntity2d::className).staticmethod("className")
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
