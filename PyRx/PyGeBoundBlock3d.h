#pragma once
#include "PyGeEntity3d.h"

//-----------------------------------------------------------------------------------
//PyGeBoundBlock3d
void makPyGeBoundBlock3dWrapper();
class PyGeBoundBlock3d : public PyGeEntity3d
{
public:
    PyGeBoundBlock3d();
    PyGeBoundBlock3d(AcGeEntity3d* pEnt);
    static std::string className();
public:
    AcGeBoundBlock3d* impObj() const;
};