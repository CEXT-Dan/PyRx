#pragma once

#include "PyGeCurve3d.h"

class PyGeKnotVector;
class PyGePolyline3d;
class PyGeEllipArc3d;
class PyGeLineSeg3d;

//-----------------------------------------------------------------------------------------
//PyGeSplineEnt3d wrapper
void makePyGeSplineEnt3dWrapper();
class PyGeSplineEnt3d : public PyGeCurve3d
{
public:
    PyGeSplineEnt3d(AcGeEntity3d* pEnt);
    Adesk::Boolean    isRational() const;
    int               degree() const;
    int               order() const;
    int               numKnots() const;
    PyGeKnotVector    knots() const;
    int               numControlPoints() const;
    int               continuityAtKnot1(int idx) const;
    int               continuityAtKnot2(int idx, const AcGeTol& tol) const;
    double            startParam() const;
    double            endParam() const;
    AcGePoint3d       startPoint() const;
    AcGePoint3d       endPoint() const;
    Adesk::Boolean    hasFitData() const;
    double            knotAt(int idx) const;
    void              setKnotAt(int idx, double val);
    AcGePoint3d       controlPointAt(int idx) const;
    void              setControlPointAt(int idx, const AcGePoint3d& pnt);
    static PyGeSplineEnt3d cast(const PyGeEntity3d& src);
    static PyGeSplineEnt3d copycast(const PyGeEntity3d& src);
    static std::string className();
public:
    AcGeSplineEnt3d* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//AcGeCubicSplineCurve3d wrapper
void makePyGeCubicSplineCurve3dWrapper();
class PyGeCubicSplineCurve3d : public PyGeSplineEnt3d
{
#if !defined(_BRXTARGET240)
public:
    PyGeCubicSplineCurve3d();
    PyGeCubicSplineCurve3d(const PyGeCurve3d& curve, double epsilon);
    PyGeCubicSplineCurve3d(const boost::python::list& fitPnts, const AcGeTol& tol);
    PyGeCubicSplineCurve3d(const boost::python::list& fitPnts, const AcGeVector3d& startDeriv, const AcGeVector3d& endDeriv, const AcGeTol& tol);
    PyGeCubicSplineCurve3d(const PyGeKnotVector& knots, const boost::python::list& fitPnts, const boost::python::list& firstDerivs, Adesk::Boolean isPeriodic);
    PyGeCubicSplineCurve3d(AcGeEntity3d* pEnt);

    int                     numFitPoints() const;
    AcGePoint3d             fitPointAt(int idx) const;
    void                    setFitPointAt(int idx, const AcGePoint3d& point);
    AcGeVector3d            firstDerivAt(int idx) const;
    void                    setFirstDerivAt(int idx, const AcGeVector3d& deriv);

    static PyGeCubicSplineCurve3d cast(const PyGeEntity3d& src);
    static PyGeCubicSplineCurve3d copycast(const PyGeEntity3d& src);
    static std::string className();
public:
    AcGeCubicSplineCurve3d* impObj(const std::source_location& src = std::source_location::current()) const;
#endif
};

//-----------------------------------------------------------------------------------------
//AcGeNurbCurve3d  wrapper
void makePyGeNurbCurve3dWrapper();
class PyGeNurbCurve3d : public PyGeSplineEnt3d
{
#if !defined(_BRXTARGET240)
public:
    PyGeNurbCurve3d();
    PyGeNurbCurve3d(const AcGeNurbCurve3d& src);
    PyGeNurbCurve3d(int degree, const PyGeKnotVector& knots, const boost::python::list& cntrlPnts, Adesk::Boolean isPeriodic);
    PyGeNurbCurve3d(int degree, const PyGePolyline3d& fitPolyline, Adesk::Boolean isPeriodic);
    PyGeNurbCurve3d(const boost::python::list& fitPoints, const AcGeVector3d& startTangent,
        const AcGeVector3d& endTangent, Adesk::Boolean startTangentDefined, Adesk::Boolean endTangentDefined, const AcGeTol& fitTolerance);
    PyGeNurbCurve3d(const boost::python::list& fitPoints, const AcGeVector3d& startTangent, const AcGeVector3d& endTangent,
        Adesk::Boolean startTangentDefined, Adesk::Boolean endTangentDefined, AcGe::KnotParameterization knotParam, const AcGeTol& fitTolerance);
    PyGeNurbCurve3d(const boost::python::list& fitPoints, const AcGeTol& fitTolerance);
    PyGeNurbCurve3d(const boost::python::list& fitPoints, const boost::python::list& fitTangents, const AcGeTol& fitTolerance, Adesk::Boolean isPeriodic);
    PyGeNurbCurve3d(const PyGeCurve3d& curve, double epsilon);
    PyGeNurbCurve3d(const PyGeEllipArc3d& ellipse);
    PyGeNurbCurve3d(const PyGeLineSeg3d& linSeg);
    PyGeNurbCurve3d(AcGeEntity3d* pEnt);

    int                     numFitPoints() const;
    boost::python::tuple    getFitPointAt(int index) const;
    boost::python::tuple    getFitTolerance() const;
    boost::python::tuple    getFitTangents() const;
    boost::python::tuple    getFitData() const;
    boost::python::tuple    getDefinitionData() const;
    int                     numWeights() const;
    double                  weightAt(int idx) const;
    Adesk::Boolean          evalMode() const;

    boost::python::tuple    getParamsOfC1Discontinuity(const AcGeTol& tol);
    boost::python::tuple    getParamsOfG1Discontinuity(const AcGeTol& tol);

    Adesk::Boolean          setFitPointAt(int index, const AcGePoint3d& point);
    Adesk::Boolean          addFitPointAt(int index, const AcGePoint3d& point);
    Adesk::Boolean          deleteFitPointAt(int index);
    Adesk::Boolean          setFitTolerance(const AcGeTol& fitTol);

    Adesk::Boolean          setFitTangents1(const AcGeVector3d& startTangent, const AcGeVector3d& endTangent);
    Adesk::Boolean          setFitTangents2(const AcGeVector3d& startTangent, const AcGeVector3d& endTangent, 
        Adesk::Boolean startTangentDefined, Adesk::Boolean endTangentDefined);

    Adesk::Boolean          setFitKnotParameterization(KnotParameterization knotParam);

    void                    setFitData1(const boost::python::list& fitPoints,
        const AcGeVector3d& startTangent, const AcGeVector3d& endTangent, const AcGeTol& fitTol);

    void                    setFitData2(const boost::python::list& fitPoints,
        const AcGeVector3d& startTangent, const AcGeVector3d& endTangent, KnotParameterization knotParam, const AcGeTol& fitTol);

    void                    setFitData3(const PyGeKnotVector& fitKnots, const boost::python::list& fitPoints,
        const AcGeVector3d& startTangent, const AcGeVector3d& endTangent, const AcGeTol& fitTol, Adesk::Boolean isPeriodic);

    void                    setFitData4(int degree, const boost::python::list& fitPoints, const AcGeTol& fitTol);

    Adesk::Boolean          purgeFitData();
    Adesk::Boolean          buildFitData1();
    Adesk::Boolean          buildFitData2(KnotParameterization kp);

    void                    addKnot(double newKnot);
    void                    insertKnot(double newKnot);
    void                    setWeightAt(int idx, double val);
    void                    setEvalMode(Adesk::Boolean evalMode);
    void                    joinWith(const PyGeNurbCurve3d& curve);
    void                    hardTrimByParams(double newStartParam, double newEndParam);
    void                    makeRational(double weight);
    void                    makeClosed();
    void                    makePeriodic();
    void                    makeNonPeriodic();
    void                    makeOpen();
    void                    elevateDegree(int plusDegree);

    Adesk::Boolean          addControlPointAt(double newKnot, const AcGePoint3d& point, double weight);
    Adesk::Boolean          deleteControlPointAt(int index);

    static PyGeNurbCurve3d cast(const PyGeEntity3d& src);
    static PyGeNurbCurve3d copycast(const PyGeEntity3d& src);
    static std::string className();
public:
    AcGeNurbCurve3d* impObj(const std::source_location& src = std::source_location::current()) const;
#endif
};

//-----------------------------------------------------------------------------------------
//PyGePolyline3d  wrapper
void makePyGePolyline3dWrapper();
class PyGePolyline3d : public PyGeSplineEnt3d
{
public:
    PyGePolyline3d();
    PyGePolyline3d(AcGeEntity3d* pEnt);
    PyGePolyline3d(const AcGePolyline3d& src);
    PyGePolyline3d(const boost::python::list& points);
    PyGePolyline3d(const PyGeKnotVector& knots, const boost::python::list& points);
#if !defined(_BRXTARGET240)
    PyGePolyline3d(const PyGeCurve3d& crv, double apprEps);
#endif

    int              numFitPoints() const;
    AcGePoint3d      fitPointAt(int idx) const;
    void             setFitPointAt(int idx, const AcGePoint3d& point);

    static PyGePolyline3d cast(const PyGeEntity3d& src);
    static PyGePolyline3d copycast(const PyGeEntity3d& src);
    static std::string className();
public:
    AcGePolyline3d* impObj(const std::source_location& src = std::source_location::current()) const;
};

