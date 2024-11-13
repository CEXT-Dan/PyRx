#pragma once
#include "PyGeCurve2d.h"

#pragma pack (push, 8)
class PyGeKnotVector;
class PyGeLineSeg2d;
class PyGePolyline2d;

//-----------------------------------------------------------------------------------------
//PyGeSplineEnt2d wrapper
void makePyGeSplineEnt2dWrapper();
class PyGeSplineEnt2d : public PyGeCurve2d
{
#if !defined(_BRXTARGET250)
public:
    PyGeSplineEnt2d(AcGeEntity2d* pEnt);
    virtual ~PyGeSplineEnt2d() override = default;

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
    AcGePoint2d       startPoint() const;
    AcGePoint2d       endPoint() const;
    Adesk::Boolean    hasFitData() const;
    double            knotAt(int idx) const;
    void              setKnotAt(int idx, double val);
    AcGePoint2d       controlPointAt(int idx) const;
    void              setControlPointAt(int idx, const AcGePoint2d& pnt);
    static PyGeSplineEnt2d cast(const PyGeEntity2d& src);
    static PyGeSplineEnt2d copycast(const PyGeEntity2d& src);
    static std::string className();
public:
    AcGeSplineEnt2d* impObj(const std::source_location& src = std::source_location::current()) const;
#endif
};

//-----------------------------------------------------------------------------------------
//AcGeCubicSplineCurve2d wrapper
void makePyGeCubicSplineCurve2dWrapper();
class PyGeCubicSplineCurve2d : public PyGeSplineEnt2d
{
#if !defined(_BRXTARGET250)
public:
    PyGeCubicSplineCurve2d();
    PyGeCubicSplineCurve2d(const PyGeCurve2d& curve, double epsilon);
    PyGeCubicSplineCurve2d(const boost::python::list& fitPnts, const AcGeTol& tol);
    PyGeCubicSplineCurve2d(const boost::python::list& fitPnts, const AcGeVector2d& startDeriv, const AcGeVector2d& endDeriv, const AcGeTol& tol);
    PyGeCubicSplineCurve2d(const PyGeKnotVector& knots, const boost::python::list& fitPnts, const boost::python::list& firstDerivs, Adesk::Boolean isPeriodic);
    PyGeCubicSplineCurve2d(AcGeEntity2d* pEnt);
    virtual ~PyGeCubicSplineCurve2d() override = default;

    int                     numFitPoints() const;
    AcGePoint2d             fitPointAt(int idx) const;
    void                    setFitPointAt(int idx, const AcGePoint2d& point);
    AcGeVector2d            firstDerivAt(int idx) const;
    void                    setFirstDerivAt(int idx, const AcGeVector2d& deriv);

    static PyGeCubicSplineCurve2d cast(const PyGeEntity2d& src);
    static PyGeCubicSplineCurve2d copycast(const PyGeEntity2d& src);
    static std::string className();
public:
    AcGeCubicSplineCurve2d* impObj(const std::source_location& src = std::source_location::current()) const;
#endif
};

//-----------------------------------------------------------------------------------------
//AcGeNurbCurve2d  wrapper
void makePyGeNurbCurve2dWrapper();
class PyGeNurbCurve2d : public PyGeSplineEnt2d
{
#if !defined(_BRXTARGET250)
public:
    PyGeNurbCurve2d();
    PyGeNurbCurve2d(const AcGeNurbCurve2d& src);
    PyGeNurbCurve2d(const PyGeLineSeg2d& linSeg);
    PyGeNurbCurve2d(const PyGeEllipArc2d& ellipse);
    PyGeNurbCurve2d(const PyGeCurve2d& curve, double epsilon);
    PyGeNurbCurve2d(const boost::python::list& fitPoints, const AcGeTol& fitTolerance);
    PyGeNurbCurve2d(int degree, const PyGePolyline2d& fitPolyline, Adesk::Boolean isPeriodic);
    PyGeNurbCurve2d(int degree, const PyGeKnotVector& knots, const boost::python::list& cntrlPnts, Adesk::Boolean isPeriodic);
    PyGeNurbCurve2d(const boost::python::list& fitPoints, const boost::python::list& fitTangents, const AcGeTol& fitTolerance, Adesk::Boolean isPeriodic);

    PyGeNurbCurve2d(const boost::python::list& fitPoints, const AcGeVector2d& startTangent, const AcGeVector2d& endTangent,
        Adesk::Boolean startTangentDefined, Adesk::Boolean endTangentDefined, AcGe::KnotParameterization knotParam, const AcGeTol& fitTolerance);

    PyGeNurbCurve2d(const boost::python::list& fitPoints, const AcGeVector2d& startTangent, const AcGeVector2d& endTangent, Adesk::Boolean startTangentDefined,
        Adesk::Boolean endTangentDefined, const AcGeTol& fitTolerance);

    PyGeNurbCurve2d(AcGeEntity2d* pEnt);

    virtual ~PyGeNurbCurve2d() override = default;

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

    Adesk::Boolean          setFitPointAt(int index, const AcGePoint2d& point);
    Adesk::Boolean          addFitPointAt(int index, const AcGePoint2d& point);
    Adesk::Boolean          deleteFitPointAt(int index);
    Adesk::Boolean          setFitTolerance(const AcGeTol& fitTol);
    Adesk::Boolean          setFitTangents(const AcGeVector2d& startTangent, const AcGeVector2d& endTangent);
    Adesk::Boolean          setFitKnotParameterization(KnotParameterization knotParam);

    void                    setFitData1(const boost::python::list& fitPoints,
        const AcGeVector2d& startTangent, const AcGeVector2d& endTangent, const AcGeTol& fitTol);

    void                    setFitData2(const boost::python::list& fitPoints,
        const AcGeVector2d& startTangent, const AcGeVector2d& endTangent, KnotParameterization knotParam, const AcGeTol& fitTol);

    void                    setFitData3(const PyGeKnotVector& fitKnots, const boost::python::list& fitPoints,
        const AcGeVector2d& startTangent, const AcGeVector2d& endTangent, const AcGeTol& fitTol, Adesk::Boolean isPeriodic);

    void                    setFitData4(int degree, const boost::python::list& fitPoints, const AcGeTol& fitTol);

    Adesk::Boolean          purgeFitData();
    Adesk::Boolean          buildFitData1();
    Adesk::Boolean          buildFitData2(KnotParameterization kp);

    void                    addKnot(double newKnot);
    void                    insertKnot(double newKnot);
    void                    setWeightAt(int idx, double val);
    void                    setEvalMode(Adesk::Boolean evalMode);
    void                    joinWith(const PyGeNurbCurve2d& curve);
    void                    hardTrimByParams(double newStartParam, double newEndParam);
    void                    makeRational(double weight);
    void                    makeClosed();
    void                    makePeriodic();
    void                    makeNonPeriodic();
    void                    makeOpen();
    void                    elevateDegree(int plusDegree);

    Adesk::Boolean          addControlPointAt(double newKnot, const AcGePoint2d& point, double weight);
    Adesk::Boolean          deleteControlPointAt(int index);

    static PyGeNurbCurve2d cast(const PyGeEntity2d& src);
    static PyGeNurbCurve2d copycast(const PyGeEntity2d& src);
    static std::string className();
public:
    AcGeNurbCurve2d* impObj(const std::source_location& src = std::source_location::current()) const;
#endif
};

//-----------------------------------------------------------------------------------------
//PyGePolyline2d  wrapper
void makePyGePolyline2dWrapper();
class PyGePolyline2d : public PyGeSplineEnt2d
{
#if !defined(_BRXTARGET250)
public:
    PyGePolyline2d();
    PyGePolyline2d(const AcGePolyline2d& src);
    PyGePolyline2d(const boost::python::list& points);
    PyGePolyline2d(const PyGeKnotVector& knots, const boost::python::list& points);
    PyGePolyline2d(const PyGeCurve2d& crv, double apprEps);
    PyGePolyline2d(AcGeEntity2d* pEnt);
    virtual ~PyGePolyline2d() override = default;
    int              numFitPoints() const;
    AcGePoint2d      fitPointAt(int idx) const;
    void             setFitPointAt(int idx, const AcGePoint2d& point);
    static PyGePolyline2d cast(const PyGeEntity2d& src);
    static PyGePolyline2d copycast(const PyGeEntity2d& src);
    static std::string className();
public:
    AcGePolyline2d* impObj(const std::source_location& src = std::source_location::current()) const;
#endif
};

#pragma pack (pop)







