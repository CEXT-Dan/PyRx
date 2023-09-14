#pragma once
#include "PyGeEntity3d.h"

class PyGeCurve3d;
class PyGeSurface;

void makePyGeCurveSurfIntWrapper();
class PyGeCurveSurfInt : public PyGeEntity3d
{
public:
    PyGeCurveSurfInt();
    PyGeCurveSurfInt(const AcGeCurveSurfInt& src);
    PyGeCurveSurfInt(const PyGeCurve3d& crv, const PyGeSurface& srf);
    PyGeCurveSurfInt(const PyGeCurve3d& crv, const PyGeSurface& srf, const AcGeTol& tol);
    PyGeCurveSurfInt(AcGeEntity3d* pEnt);
    static std::string className();
public:
    AcGeCurveSurfInt* impObj() const;
};

