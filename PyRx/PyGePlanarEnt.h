#pragma once
#include "PyAcGeSurface.h"

//-----------------------------------------------------------------------------------------
//AcGeSurface wrapper
void makeAcGePlanarEntWrapper();
class PyGePlanarEnt : public PyAcGeSurface
{
protected:
    PyGePlanarEnt() = default;
public:
    PyGePlanarEnt(AcGePlanarEnt* pEnt);
    PyGePlanarEnt(AcGeEntity3d* pEnt);
    ~PyGePlanarEnt() = default;
    static std::string className();
public:
    AcGePlanarEnt* impObj() const;
};

