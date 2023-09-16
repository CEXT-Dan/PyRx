#pragma once
#include "PyGeEntity3d.h"

class PyGeInterval;

//-----------------------------------------------------------------------------------------
//PyGeCurveCurveInt3d wrapper
void makePyGeCurveCurveInt3dWrapper();

class PyGeCurveCurveInt3d : public PyGeEntity3d
{
public:
    PyGeCurveCurveInt3d();
    PyGeCurveCurveInt3d(AcGeEntity3d* pEnt);
    static PyGeCurveCurveInt3d copycast(const PyGeEntity3d& src);
    static std::string className();
public:
    AcGeCurveCurveInt3d* impObj(const std::source_location& src = std::source_location::current()) const;
};

