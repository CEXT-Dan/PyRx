#pragma once
#include "PyGeCurve2d.h"
//-----------------------------------------------------------------------------------------
//AcGeLinearEnt2d wrapper
void makeAcGeLinearEnt2dWrapper();
class PyGeLinearEnt2d : public PyGeCurve2d
{
public:
    PyGeLinearEnt2d(AcGeEntity2d* pEnt);
    static std::string className();
public:
    AcGeLinearEnt2d* impObj() const;
};

