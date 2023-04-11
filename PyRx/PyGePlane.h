#pragma once

#include "PyGePlanarEnt.h"
//-----------------------------------------------------------------------------------------
//PyGePlane wrapper
void makePyGePlaneWrapper();
class PyGePlane : public PyGePlanarEnt
{
public:
    PyGePlane();
    PyGePlane(AcGePlane* pEnt);
    PyGePlane(const AcGePlane& ent);//TODO: which ctor? from AcGeEntity3d::copy() or copy ctor
    PyGePlane(AcGeEntity3d* pEnt);
    ~PyGePlane() = default;
    static std::string className();
public:
    AcGePlane* impObj() const;
};

