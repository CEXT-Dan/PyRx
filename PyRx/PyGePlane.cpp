#include "stdafx.h"
#include "PyGePlane.h"

using namespace boost::python;

//-----------------------------------------------------------------------------------------
//PyGePlane wrapper
void makePyGePlaneWrapper()
{
    static auto wrapper = class_<PyGePlane, bases<PyGePlanarEnt>>("Plane")
        .def(init<>())
        .def("className", &PyGePlane::className).staticmethod("className")
        ;
}

PyGePlane::PyGePlane()
    : PyGePlanarEnt(new AcGePlane())
{
}

PyGePlane::PyGePlane(AcGePlane* pEnt)
    : PyGePlanarEnt(pEnt)
{
}

PyGePlane::PyGePlane(AcGeEntity3d* pEnt)
    : PyGePlanarEnt(pEnt)
{
    //TODO check type
}

PyGePlane::PyGePlane(const AcGePlane& ent)
    : PyGePlanarEnt(new AcGePlane(ent))
{
}

std::string PyGePlane::className()
{
    return "AcGePlane";
}

AcGePlane* PyGePlane::impObj() const
{
    return static_cast<AcGePlane*>(m_imp.get());
}
