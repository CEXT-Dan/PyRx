#pragma once
#include "PyGeEntity2d.h"

//-----------------------------------------------------------------------------------------
//PyGePointEnt2d wrapper
void makePyGePointEnt2dWrapper();

class PyGePointEnt2d : public PyGeEntity2d
{
public:
    PyGePointEnt2d();
    PyGePointEnt2d(const AcGePointEnt2d& src);
    PyGePointEnt2d(AcGeEntity2d* pEnt);
    static std::string className();
public:
    AcGePointEnt2d* impObj() const;
};

