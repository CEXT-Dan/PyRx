#include "stdafx.h"
#include "PyGeCurve2d.h"

using namespace boost::python;


void makePyGeCurve2dWrapper()
{
    static auto wrapper = class_<PyGeCurve2d, bases<PyGeEntity2d>>("Curve2d", boost::python::no_init)
        .def("className", &PyGeEntity2d::className).staticmethod("className")
        ;
}

PyGeCurve2d::PyGeCurve2d(AcGeEntity2d* pEnt)
    : PyGeEntity2d(pEnt)
{
}

std::string PyGeCurve2d::className()
{
    return "AcGeCurve2d";
}

AcGeCurve2d* PyGeCurve2d::impObj() const
{
    return static_cast<AcGeCurve2d*>(m_imp.get());
}
