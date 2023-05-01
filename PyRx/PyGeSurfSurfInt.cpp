#include "stdafx.h"
#include "PyGeSurfSurfInt.h"

using namespace boost::python;

//TODO LINK ERROR @CTOR
void makePyGeSurfSurfIntWrapper()
{
    static auto wrapper = class_<PyGeSurfSurfInt, bases<PyGeEntity3d>>("SurfSurfInt", boost::python::no_init)
        .def("className", &PyGeSurfSurfInt::className).staticmethod("className")
        ;
}

PyGeSurfSurfInt::PyGeSurfSurfInt(AcGeEntity3d* pEnt)
    : PyGeEntity3d(pEnt)
{
}

std::string PyGeSurfSurfInt::className()
{
    return "AcGeSurfSurfInt";
}

AcGeSurfSurfInt* PyGeSurfSurfInt::impObj() const
{
    return static_cast<AcGeSurfSurfInt*>(m_imp.get());
}
