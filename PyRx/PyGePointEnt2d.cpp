#include "stdafx.h"
#include "PyGePointEnt2d.h"

using namespace boost::python;

//-----------------------------------------------------------------------------------------
//PyGePointEnt2d wrapper
void makePyGePointEnt2dWrapper()
{
    static auto wrapper = class_<PyGePointEnt2d, bases<PyGeEntity2d>>("PointEnt2d", boost::python::no_init)
        .def("className", &PyGePointEnt2d::className).staticmethod("className")
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

//-----------------------------------------------------------------------------------------
//PyGePointOnCurve2d wrapper
void makePyGePointOnCurve2dWrapper()
{
    static auto wrapper = class_<PyGePointOnCurve2d, bases<PyGePointEnt2d>>("PyGePointOnCurve2d")
        .def("className", &PyGePointOnCurve2d::className).staticmethod("className")
        ;
}

PyGePointOnCurve2d::PyGePointOnCurve2d()
    : PyGePointEnt2d(new AcGePointOnCurve2d())
{

}

PyGePointOnCurve2d::PyGePointOnCurve2d(AcGeEntity2d* pEnt)
    : PyGePointEnt2d(pEnt)
{

}

std::string PyGePointOnCurve2d::className()
{
    return "AcGePointOnCurve2d";
}

AcGePointOnCurve2d* PyGePointOnCurve2d::impObj() const
{
    return static_cast<AcGePointOnCurve2d*>(m_imp.get());
}

//-----------------------------------------------------------------------------------------
//AcGePosition2d wrapper
void makeAcGePosition2dWrapper()
{
    static auto wrapper = class_<PyGePosition2d, bases<PyGePointEnt2d>>("Position2d")
        .def("className", &PyGePosition2d::className).staticmethod("className")
        ;
}

PyGePosition2d::PyGePosition2d()
    : PyGePointEnt2d(new AcGePosition2d())
{

}

PyGePosition2d::PyGePosition2d(AcGeEntity2d* pEnt)
    : PyGePointEnt2d(pEnt)
{

}

std::string PyGePosition2d::className()
{
    return "AcGePosition2d";
}

AcGePosition2d* PyGePosition2d::impObj() const
{
    return static_cast<AcGePosition2d*>(m_imp.get());
}
