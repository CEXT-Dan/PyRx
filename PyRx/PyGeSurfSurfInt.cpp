#include "stdafx.h"
#include "PyGeSurfSurfInt.h"
#include "PyAcGeSurface.h"

using namespace boost::python;

void makePyGeSurfSurfIntWrapper()
{
    class_<PyGeSurfSurfInt, bases<PyGeEntity3d>>("SurfSurfInt")
        .def(init<>())
        .def(init<const PyAcGeSurface&, const PyAcGeSurface&>())
        .def(init<const PyAcGeSurface&, const PyAcGeSurface&, const AcGeTol&>())
        .def("className", &PyGeSurfSurfInt::className).staticmethod("className")
        ;
}

PyGeSurfSurfInt::PyGeSurfSurfInt()
    : PyGeEntity3d(new AcGeSurfSurfInt())
{
}

PyGeSurfSurfInt::PyGeSurfSurfInt(AcGeEntity3d* pEnt)
    : PyGeEntity3d(pEnt)
{
}

PyGeSurfSurfInt::PyGeSurfSurfInt(const PyAcGeSurface& srf1, const PyAcGeSurface& srf2)
    : PyGeEntity3d(new AcGeSurfSurfInt(*srf1.impObj(), *srf2.impObj()))
{
}

PyGeSurfSurfInt::PyGeSurfSurfInt(const PyAcGeSurface& srf1, const PyAcGeSurface& srf2, const AcGeTol& tol)
    : PyGeEntity3d(new AcGeSurfSurfInt(*srf1.impObj(), *srf2.impObj(), tol))
{
}

std::string PyGeSurfSurfInt::className()
{
    return "AcGeSurfSurfInt";
}

AcGeSurfSurfInt* PyGeSurfSurfInt::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_imp == nullptr) [[unlikely]]
        throw PyNullObject(src);
        return static_cast<AcGeSurfSurfInt*>(m_imp.get());
}
