#include "stdafx.h"
#include "PyGePointEnt2d.h"

using namespace boost::python;

//-----------------------------------------------------------------------------------------
//PyGePointEnt2d wrapper
void makePyGePointEnt2dWrapper()
{
    static auto wrapper = class_<PyGePointEnt2d, bases<PyGeEntity2d>>("PointEnt2d", boost::python::no_init)
        .def("className", &PyGeEntity2d::className).staticmethod("className")
        ;
}

PyGePointEnt2d::PyGePointEnt2d(AcGeEntity2d* pEnt)
    : PyGeEntity2d(pEnt)
{
}

std::string PyGePointEnt2d::className()
{
    return "AcGePointEnt2d";
}

AcGePointEnt2d* PyGePointEnt2d::impObj() const
{
    return static_cast<AcGePointEnt2d*>(m_imp.get());
}
