#pragma once
#include "PyGeEntity2d.h"

#pragma pack (push, 8)
//-----------------------------------------------------------------------------------------
//PyGeClipBoundary2d wrapper
void makePyGeClipBoundary2dWrapper();

class PyGeClipBoundary2d : public PyGeEntity2d
{
#if !defined(_BRXTARGET260)
public:
    PyGeClipBoundary2d();
    PyGeClipBoundary2d(AcGeEntity2d* pEnt);
    PyGeClipBoundary2d(const AcGePoint2d& cornerA, const AcGePoint2d& cornerB);
    PyGeClipBoundary2d(const boost::python::list& clipBoundary); //TODO: make test
    PyGeClipBoundary2d(const AcGeClipBoundary2d& src); //TODO test!
    virtual ~PyGeClipBoundary2d() override = default;
    static PyGeClipBoundary2d cast(const PyGeEntity2d& src);
    static PyGeClipBoundary2d copycast(const PyGeEntity2d& src);
    static std::string className();
public:
    AcGeClipBoundary2d* impObj() const;
#endif
};


bool clipLineSeg2d(AcGeLineSeg2d& outSeg, const AcGeLineSeg2d& seg, const AcDbExtents2d& extents, const AcGeTol& tol = AcGeContext::gTol);
bool clipLineSeg2d(AcGeLineSeg2d& outSeg, const AcGeLineSeg2d& seg, const AcGeBoundBlock2d& extents, const AcGeTol& tol = AcGeContext::gTol);
#pragma pack (pop)
