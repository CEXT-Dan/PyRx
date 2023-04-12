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

//-----------------------------------------------------------------------------------
//PyGeLinearEnt2d
void makPyGeLinearEnt3dWrapper()
{
    static auto wrapper = class_<PyGeLinearEnt3d, bases<PyGeCurve3d>>("LinearEnt3d", boost::python::no_init)
        .def("className", &PyGeLinearEnt3d::className).staticmethod("className")
        ;
}

PyGeLinearEnt3d::PyGeLinearEnt3d(AcGeEntity3d* pEnt)
    :PyGeCurve3d(pEnt)
{
}

std::string PyGeLinearEnt3d::className()
{
    return "AcGeLinearEnt2d";
}

AcGeLinearEnt3d* PyGeLinearEnt3d::impObj() const
{
    return static_cast<AcGeLinearEnt3d*>(m_imp.get());
}

//-----------------------------------------------------------------------------------
//PyGeLineSeg2d
void makPyGeLineSeg3dWrapper()
{
    static auto wrapper = class_<PyGeLineSeg3d, bases<PyGeLinearEnt3d>>("LineSeg3d", boost::python::no_init)
        .def("className", &PyGeLinearEnt3d::className).staticmethod("className")
        ;
}

PyGeLineSeg3d::PyGeLineSeg3d(AcGeEntity3d* pEnt)
    :PyGeLinearEnt3d(pEnt)
{
}

std::string PyGeLineSeg3d::className()
{
    return "AcGeLineSeg2d";
}

AcGeLineSeg3d* PyGeLineSeg3d::impObj() const
{
    return static_cast<AcGeLineSeg3d*>(m_imp.get());
}
