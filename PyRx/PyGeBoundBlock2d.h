#pragma once
#include "PyGeEntity2d.h"

//-----------------------------------------------------------------------------------------
//PyGeBoundBlock2d wrapper
void makePyGeBoundBlock2dWrapper();

class PyGeBoundBlock2d : public PyGeEntity2d
{

public:
    PyGeBoundBlock2d();
    PyGeBoundBlock2d(AcGeEntity2d* pEnt);
    PyGeBoundBlock2d(const AcGePoint2d& point1, const AcGePoint2d& point2);
    PyGeBoundBlock2d(const AcGePoint2d& base, const AcGeVector2d& dir1, const AcGeVector2d& dir2);
    PyGeBoundBlock2d(const AcGeBoundBlock2d& block);

    static std::string className();
public:
    AcGeBoundBlock2d* impObj() const;
};

