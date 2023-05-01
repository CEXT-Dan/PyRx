#pragma once
#include "PyGeEntity3d.h"

class PyGeCurve3d;
class PyAcGeSurface;

//TODO LINK ERROR @CTOR

void makePyGeCurveSurfIntWrapper();
class PyGeCurveSurfInt : public PyGeEntity3d
{
public:
#ifdef NEVER//TODO: link error
    PyGeCurveSurfInt();
    PyGeCurveSurfInt(const AcGeCurveSurfInt& src);
    PyGeCurveSurfInt(const PyGeCurve3d& crv, const PyAcGeSurface& srf);
    PyGeCurveSurfInt(const PyGeCurve3d& crv, const PyAcGeSurface& srf, const AcGeTol& tol);
#endif
    PyGeCurveSurfInt(AcGeEntity3d* pEnt);
    static std::string className();
public:
    AcGeCurveSurfInt* impObj() const;
};

