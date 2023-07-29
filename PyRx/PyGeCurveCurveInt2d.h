#pragma once

#include "PyGeEntity2d.h"
class PyGeInterval;

//-----------------------------------------------------------------------------------------
//PyGeCurveCurveInt2d wrapper
void makePyGeCurveCurveInt2dWrapper();

class PyGeCurveCurveInt2d : public PyGeEntity2d
{
public:
    PyGeCurveCurveInt2d();
#if !defined(_BRXTARGET) && (_BRXTARGET <= 23)
    PyGeCurveCurveInt2d(const AcGeCurve2d& curve1, const AcGeCurve2d& curve2);
    PyGeCurveCurveInt2d(const AcGeCurve2d& curve1, const AcGeCurve2d& curve2, const AcGeTol& tol);
    PyGeCurveCurveInt2d(const AcGeCurve2d& curve1, const AcGeCurve2d& curve2, const PyGeInterval& range1, const PyGeInterval& range2);
    PyGeCurveCurveInt2d(const AcGeCurve2d& curve1, const AcGeCurve2d& curve2, const PyGeInterval& range1, const PyGeInterval& range2, const AcGeTol& tol);
    PyGeCurveCurveInt2d(const AcGeCurveCurveInt2d& src);
#endif // !BRXAPP
    PyGeCurveCurveInt2d(AcGeEntity2d* pEnt);
    static std::string className();
public:
    AcGeCurveCurveInt2d* impObj() const;
};

