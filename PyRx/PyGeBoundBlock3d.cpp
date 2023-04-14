#include "stdafx.h"
#include "PyGeBoundBlock3d.h"
using namespace boost::python;

//-----------------------------------------------------------------------------------
//PyGeBoundBlock3d
void makPyGeBoundBlock3dWrapper()
{
    static auto wrapper = class_<PyGeBoundBlock3d, bases<PyGeEntity3d>>("PyGeEntity3d", boost::python::no_init)
        .def("className", &PyGeBoundBlock3d::className).staticmethod("className")
        ;
}

PyGeBoundBlock3d::PyGeBoundBlock3d()
    :PyGeEntity3d(new AcGeBoundBlock3d())
{
}

PyGeBoundBlock3d::PyGeBoundBlock3d(AcGeEntity3d* pEnt)
    :PyGeEntity3d(pEnt)
{

}

std::string PyGeBoundBlock3d::className()
{
    return "AcGeBoundBlock3d";
}

AcGeBoundBlock3d* PyGeBoundBlock3d::impObj() const
{
    return static_cast<AcGeBoundBlock3d*>(m_imp.get());
}
