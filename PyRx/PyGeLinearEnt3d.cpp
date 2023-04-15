#include "stdafx.h"
#include "PyGeLinearEnt3d.h"

using namespace boost::python;
//-----------------------------------------------------------------------------------
//PyGeLinearEnt3d
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
//AcGeLine3d
void makAcGeLine3dWrapper()
{
    static auto wrapper = class_<PyGeLine3d, bases<PyGeCurve3d>>("Line3d")
        .def("className", &PyGeLine3d::className).staticmethod("className")
        ;
}

PyGeLine3d::PyGeLine3d()
  : PyGeLinearEnt3d(new AcGeLine3d())
{
}

PyGeLine3d::PyGeLine3d(AcGeEntity3d* pEnt)
    : PyGeLinearEnt3d(pEnt)
{
}

std::string PyGeLine3d::className()
{
    return "AcGeLine3d";
}

AcGeLine3d* PyGeLine3d::impObj() const
{
    return static_cast<AcGeLine3d*>(m_imp.get());
}

//-----------------------------------------------------------------------------------
//PyGeLineSeg3d
void makPyGeLineSeg3dWrapper()
{
    static auto wrapper = class_<PyGeLineSeg3d, bases<PyGeLinearEnt3d>>("LineSeg3d")
        .def("className", &PyGeLineSeg3d::className).staticmethod("className")
        ;
}

PyGeLineSeg3d::PyGeLineSeg3d(AcGeEntity3d* pEnt)
    :PyGeLinearEnt3d(pEnt)
{
}

PyGeLineSeg3d::PyGeLineSeg3d()
    : PyGeLinearEnt3d(new AcGeLineSeg3d())
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

//-----------------------------------------------------------------------------------
//AcGeRay3d
void makAcGeRay3ddWrapper()
{
    static auto wrapper = class_<PyGeRay3d, bases<PyGeLinearEnt3d>>("Ray3d")
        .def("className", &PyGeRay3d::className).staticmethod("className")
        ;
}

PyGeRay3d::PyGeRay3d()
    :PyGeLinearEnt3d(new AcGeRay3d())
{
}

PyGeRay3d::PyGeRay3d(AcGeEntity3d* pEnt)
    :PyGeLinearEnt3d(pEnt)
{
}

std::string PyGeRay3d::className()
{
    return "AcGeRay3d";
}

AcGeRay3d* PyGeRay3d::impObj() const
{
    return static_cast<AcGeRay3d*>(m_imp.get());
}
