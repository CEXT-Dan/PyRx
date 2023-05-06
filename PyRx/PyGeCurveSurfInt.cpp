#include "stdafx.h"
#include "PyGeCurveSurfInt.h"
#include "PyGeCurve3d.h"
#include "PyAcGeSurface.h"

//TODO LINK ERROR @CTOR

using namespace boost::python;

void makePyGeCurveSurfIntWrapper()
{
    class_<PyGeCurveSurfInt, bases<PyGeEntity3d>>("CurveSurfInt", boost::python::no_init)
        .def("className", &PyGeCurveSurfInt::className).staticmethod("className")
        ;
}

PyGeCurveSurfInt::PyGeCurveSurfInt(AcGeEntity3d* pEnt)
    : PyGeEntity3d(pEnt)
{
}

#ifdef NEVER
PyGeCurveSurfInt::PyGeCurveSurfInt()
    : PyGeEntity3d(new AcGeCurveSurfInt())
{
}

PyGeCurveSurfInt::PyGeCurveSurfInt(const PyGeCurve3d& crv, const PyAcGeSurface& srf)
    : PyGeEntity3d(new AcGeCurveSurfInt(*crv.impObj(), *srf.impObj()))
{
}

PyGeCurveSurfInt::PyGeCurveSurfInt(const PyGeCurve3d& crv, const PyAcGeSurface& srf, const AcGeTol& tol)
    : PyGeEntity3d(new AcGeCurveSurfInt(*crv.impObj(), *srf.impObj(), tol))
{
}

PyGeCurveSurfInt::PyGeCurveSurfInt(const AcGeCurveSurfInt& src)
    : PyGeEntity3d(new AcGeCurveSurfInt(src))
{
}
#endif

std::string PyGeCurveSurfInt::className()
{
    return "AcGeCurveSurfInt";
}

AcGeCurveSurfInt* PyGeCurveSurfInt::impObj() const
{
    return static_cast<AcGeCurveSurfInt*>(m_imp.get());
}
