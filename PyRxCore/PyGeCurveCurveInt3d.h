#pragma once
#include "PyGeEntity3d.h"

#pragma pack (push, 8)
class PyGeInterval;
class PyGeCurve3d;
class PyGePointOnCurve3d;

//-----------------------------------------------------------------------------------------
//PyGeCurveCurveInt3d wrapper
void makePyGeCurveCurveInt3dWrapper();

class PyGeCurveCurveInt3d : public PyGeEntity3d
{
#if !defined(_BRXTARGET250)
public:
    PyGeCurveCurveInt3d();
    PyGeCurveCurveInt3d(const AcGeCurveCurveInt3d& src);
    PyGeCurveCurveInt3d(const PyGeCurve3d& curve1, const PyGeCurve3d& curve2);
    PyGeCurveCurveInt3d(const PyGeCurve3d& curve1, const PyGeCurve3d& curve2, const AcGeVector3d& planeNormal, const AcGeTol& tol);
    PyGeCurveCurveInt3d(const PyGeCurve3d& curve1, const PyGeCurve3d& curve2, const PyGeInterval& range1, const PyGeInterval& range2);
    PyGeCurveCurveInt3d(const PyGeCurve3d& curve1, const PyGeCurve3d& curve2, const PyGeInterval& range1, const PyGeInterval& range2, const AcGeVector3d& planeNormal, const AcGeTol& tol);
    PyGeCurveCurveInt3d(AcGeEntity3d* pEnt);
    virtual ~PyGeCurveCurveInt3d() override = default;

    PyGeCurve3d             curve1() const;
    PyGeCurve3d             curve2() const;
    boost::python::tuple    getIntRanges() const;
    AcGeVector3d	        planeNormal() const;
    AcGeTol                 tolerance() const;
    int                     numIntPoints() const;
    AcGePoint3d             intPoint(int intNum) const;
    boost::python::tuple    getIntParams(int intNum) const;
    PyGePointOnCurve3d      getPointOnCurve1(int intNum) const;
    PyGePointOnCurve3d      getPointOnCurve2(int intNum) const;

    boost::python::tuple    getIntConfigs(int intNum) const;
    Adesk::Boolean          isTangential(int intNum) const;
    Adesk::Boolean          isTransversal(int intNum) const;
    double                  intPointTol(int intNum) const;
    int                     overlapCount() const;
    Adesk::Boolean	        overlapDirection() const;
    boost::python::tuple    getOverlapRanges(int overlapNum) const;
    void                    changeCurveOrder() const;
    PyGeCurveCurveInt3d     orderWrt1() const;
    PyGeCurveCurveInt3d     orderWrt2() const;
    void                    set1(const PyGeCurve3d& curve1, const PyGeCurve3d& curve2);

    static PyGeCurveCurveInt3d cast(const PyGeEntity3d& src);
    static PyGeCurveCurveInt3d copycast(const PyGeEntity3d& src);
    static std::string className();
public:
    AcGeCurveCurveInt3d* impObj(const std::source_location& src = std::source_location::current()) const;
#endif
};
#pragma pack (pop)