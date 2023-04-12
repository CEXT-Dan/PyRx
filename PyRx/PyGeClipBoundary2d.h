#pragma once
#include "PyGeEntity2d.h"

//-----------------------------------------------------------------------------------------
//PyGeClipBoundary2d wrapper
void makePyGeClipBoundary2dWrapper();

class PyGeClipBoundary2d : public PyGeEntity2d
{
public:
    PyGeClipBoundary2d();
    PyGeClipBoundary2d(AcGeEntity2d* pEnt);

#ifndef BRXAPP
    PyGeClipBoundary2d(const AcGePoint2d& cornerA, const AcGePoint2d& cornerB);
    PyGeClipBoundary2d(const boost::python::list& clipBoundary); //TODO: make test
#endif // !BRXAPP

#ifdef NEVER// link error in auto cad
    PyGeClipBoundary2d(const AcGeClipBoundary2d& src);
#endif
    static std::string className();
public:
    AcGeClipBoundary2d* impObj() const;
};

