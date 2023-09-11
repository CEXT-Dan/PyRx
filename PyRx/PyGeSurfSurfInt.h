#pragma once
#include "PyGeEntity3d.h"

class PyAcGeSurface;

void makePyGeSurfSurfIntWrapper();

class PyGeSurfSurfInt :public PyGeEntity3d
{
public:
    PyGeSurfSurfInt();
    PyGeSurfSurfInt(const PyAcGeSurface& srf1, const PyAcGeSurface& srf2);
    PyGeSurfSurfInt(const PyAcGeSurface& srf1,  const PyAcGeSurface& srf2, const AcGeTol& tol);

    PyGeSurfSurfInt(AcGeEntity3d* pEnt);
    static std::string className();
public:
    AcGeSurfSurfInt* impObj(const std::source_location& src = std::source_location::current()) const;
};

