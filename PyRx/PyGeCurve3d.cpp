#include "stdafx.h"
#include "PyGeCurve3d.h"

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

std::string PyGeCurve3d::className()
{
    return "AcGeCurve3d";
}

AcGeCurve3d* PyGeCurve3d::impObj() const
{
    return static_cast<AcGeCurve3d*>(m_imp.get());
}


