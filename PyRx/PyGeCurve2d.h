#pragma once
#include "PyGeEntity2d.h"

//-----------------------------------------------------------------------------------------
//PyGeCurve2d wrapper
void makePyGeCurve2dWrapper();

class PyGeCurve2d : public PyGeEntity2d
{
    PyGeCurve2d(AcGeEntity2d* pEnt);
    static std::string className();
public:
    AcGeCurve2d* impObj() const;
};

