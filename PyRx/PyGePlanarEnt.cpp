#include "stdafx.h"
#include "PyGePlanarEnt.h"

using namespace boost::python;

//-----------------------------------------------------------------------------------------
//AcGePlanarEnt wrapper
void makeAcGePlanarEntWrapper()
{
    static auto wrapper = class_<PyGePlanarEnt, bases<PyAcGeSurface>>("GePlanarEnt", boost::python::no_init)
        .def("className", &PyGePlanarEnt::className).staticmethod("className")
        ;
}

PyGePlanarEnt::PyGePlanarEnt(AcGePlanarEnt* pEnt)
    : PyAcGeSurface(pEnt)
{
}

PyGePlanarEnt::PyGePlanarEnt(AcGeEntity3d* pEnt)
    : PyAcGeSurface(pEnt)
{
    //TODO check type
}

std::string PyGePlanarEnt::className()
{
    return "AcGePlanarEnt";
}

AcGePlanarEnt* PyGePlanarEnt::impObj() const
{
    return static_cast<AcGePlanarEnt*>(m_imp.get());
}
