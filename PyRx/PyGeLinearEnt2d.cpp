#include "stdafx.h"
#include "PyGeLinearEnt2d.h"

using namespace boost::python;
//-----------------------------------------------------------------------------------------
//AcGeLinearEnt2d wrapper
void makeAcGeLinearEnt2dWrapper()
{
    static auto wrapper = class_<PyGeLinearEnt2d, bases<PyGeCurve2d>>("LinearEnt2d", boost::python::no_init)
        .def("className", &PyGeEntity2d::className).staticmethod("className")
        ;
}

PyGeLinearEnt2d::PyGeLinearEnt2d(AcGeEntity2d* pEnt)
    : PyGeCurve2d(pEnt)
{
}

std::string PyGeLinearEnt2d::className()
{
    return "AcGeLinearEnt2d";
}

AcGeLinearEnt2d* PyGeLinearEnt2d::impObj() const
{
    return static_cast<AcGeLinearEnt2d*>(m_imp.get());
}