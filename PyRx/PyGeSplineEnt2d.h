#pragma once

#include "PyGeCurve2d.h"
//-----------------------------------------------------------------------------------------
//AcGeLinearEnt2d wrapper
void makePyGeSplineEnt2dWrapper();
class PyGeSplineEnt2d : public PyGeCurve2d
{
public:
    PyGeSplineEnt2d(AcGeEntity2d* pEnt);
    static std::string className();
public:
    AcGeSplineEnt2d* impObj() const;
};

