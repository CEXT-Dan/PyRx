#pragma once
#include "PyGeEntity3d.h"


//-----------------------------------------------------------------------------------
//PyGeCurve3d
void makPyGeCurve3dWrapper();
class PyGeCurve3d : public PyGeEntity3d
{
public:
    PyGeCurve3d(AcGeEntity3d* pEnt);
    static std::string className();
public:
    AcGeCurve3d* impObj() const;
};

