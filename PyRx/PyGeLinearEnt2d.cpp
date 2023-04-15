#include "stdafx.h"
#include "PyGeLinearEnt2d.h"

using namespace boost::python;
//-----------------------------------------------------------------------------------------
//AcGeLinearEnt2d wrapper
void makeAcGeLinearEnt2dWrapper()
{
    static auto wrapper = class_<PyGeLinearEnt2d, bases<PyGeCurve2d>>("LinearEnt2d", boost::python::no_init)
        .def("className", &PyGeLinearEnt2d::className).staticmethod("className")
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


//-----------------------------------------------------------------------------------------
//AcGeLine2d  wrapper
void makeAcGeLine2dWrapper()
{
    static auto wrapper = class_<PyGeLine2d, bases<PyGeLinearEnt2d>>("Line2d")
        .def("className", &PyGeLine2d::className).staticmethod("className")
        ;
}

PyGeLine2d::PyGeLine2d()
    : PyGeLinearEnt2d(new AcGeLine2d())
{
}


PyGeLine2d::PyGeLine2d(AcGeEntity2d* pEnt)
    : PyGeLinearEnt2d(pEnt)
{
}

std::string PyGeLine2d::className()
{
    return "AcGeLine2d";
}

AcGeLine2d* PyGeLine2d::impObj() const
{
    return static_cast<AcGeLine2d*>(m_imp.get());
}

//-----------------------------------------------------------------------------------------
//AcGeLine2d  wrapper
void makePyGeLineSeg2dWrapper()
{
    static auto wrapper = class_<PyGeLineSeg2d, bases<PyGeLinearEnt2d>>("LineSeg2d")
        .def("className", &PyGeLineSeg2d::className).staticmethod("className")
        ;
}

PyGeLineSeg2d::PyGeLineSeg2d()
    : PyGeLinearEnt2d(new AcGeLineSeg2d())
{
}

PyGeLineSeg2d::PyGeLineSeg2d(AcGeEntity2d* pEnt)
    : PyGeLinearEnt2d(pEnt)
{
}

std::string PyGeLineSeg2d::className()
{
    return "AcGeLineSeg2d";
}

AcGeLineSeg2d* PyGeLineSeg2d::impObj() const
{
    return static_cast<AcGeLineSeg2d*>(m_imp.get());
}

//-----------------------------------------------------------------------------------------
//AcGeRay2d  wrapper
void makeAcGeRay2dWrapper()
{
    static auto wrapper = class_<PyGeRay2d, bases<PyGeLinearEnt2d>>("Ray2d")
        .def("className", &PyGeRay2d::className).staticmethod("className")
        ;
}

PyGeRay2d::PyGeRay2d()
    : PyGeLinearEnt2d(new AcGeRay2d())
{
}

PyGeRay2d::PyGeRay2d(AcGeEntity2d* pEnt)
    : PyGeLinearEnt2d(pEnt)
{
}

std::string PyGeRay2d::className()
{
    return "AcGeRay2d";
}

AcGeRay2d* PyGeRay2d::impObj() const
{
    return static_cast<AcGeRay2d*>(m_imp.get());
} 
