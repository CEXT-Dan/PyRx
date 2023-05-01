#pragma once
#include "PyGeEntity3d.h"

//TODO LINK ERROR @CTOR
void makePyGeSurfSurfIntWrapper();

class PyGeSurfSurfInt :public PyGeEntity3d
{
public:
    PyGeSurfSurfInt(AcGeEntity3d* pEnt);
    static std::string className();
public:
    AcGeSurfSurfInt* impObj() const;
};

