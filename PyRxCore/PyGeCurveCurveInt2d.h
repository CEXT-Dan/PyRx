#pragma once
#include "PyGeEntity2d.h"
#include "PyGeCurve2d.h"

#pragma pack (push, 8)
class PyGeInterval;

//-----------------------------------------------------------------------------------------
//PyGeCurveCurveInt2d wrapper

// TODO: curve1 and curve2, must be named in python or AutoCAD will throw an access violation.
// one option is to hold a refcount here

void makePyGeCurveCurveInt2dWrapper();

class PyGeCurveCurveInt2d : public PyGeEntity2d
{
#if !defined(_BRXTARGET260)
public:
    PyGeCurveCurveInt2d();
    PyGeCurveCurveInt2d(const PyGeCurve2d& curve1, const PyGeCurve2d& curve2);
    PyGeCurveCurveInt2d(const PyGeCurve2d& curve1, const PyGeCurve2d& curve2, const AcGeTol& tol);
    PyGeCurveCurveInt2d(const PyGeCurve2d& curve1, const PyGeCurve2d& curve2, const PyGeInterval& range1, const PyGeInterval& range2);
    PyGeCurveCurveInt2d(const PyGeCurve2d& curve1, const PyGeCurve2d& curve2, const PyGeInterval& range1, const PyGeInterval& range2, const AcGeTol& tol);
    PyGeCurveCurveInt2d(const AcGeCurveCurveInt2d& src);
    PyGeCurveCurveInt2d(AcGeEntity2d* pEnt);
    virtual ~PyGeCurveCurveInt2d() override = default;


    PyGeCurve2d             curve1() const;
    PyGeCurve2d             curve2() const;
    boost::python::tuple    getIntRanges() const;
    AcGeTol                 tolerance() const;
    int                     numIntPoints() const;
    AcGePoint2d             intPoint(int intNum) const;
    boost::python::tuple    getIntParams(int intNum) const;
    PyGePointOnCurve2d      getPointOnCurve1(int intNum) const;
    PyGePointOnCurve2d      getPointOnCurve2(int intNum) const;
    boost::python::tuple    getIntConfigs(int intNum) const;
    Adesk::Boolean          isTangential(int intNum) const;
    Adesk::Boolean          isTransversal(int intNum) const;
    double                  intPointTol(int intNum) const;
    int                     overlapCount() const;
    Adesk::Boolean	        overlapDirection() const;
    boost::python::tuple    getOverlapRanges(int overlapNum) const;
    void                    changeCurveOrder() const;

    PyGeCurveCurveInt2d     orderWrt1() const;
    PyGeCurveCurveInt2d     orderWrt2() const;

    static PyGeCurveCurveInt2d cast(const PyGeEntity2d& src);
    static PyGeCurveCurveInt2d copycast(const PyGeEntity2d& src);
    static std::string className();
public:
    AcGeCurveCurveInt2d* impObj(const std::source_location& src = std::source_location::current()) const;
#endif
};
#pragma pack (pop)
