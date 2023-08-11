#pragma once
#include "PyDbCurve.h"
#include "dbhelix.h"
//-----------------------------------------------------------------------------------
//AcDbSpline
void makePyDbSplineWrapper();
class PyDbSpline : public PyDbCurve
{
public:
    PyDbSpline();
    PyDbSpline(AcDbSpline* ptr, bool autoDelete);
    PyDbSpline(const PyDbObjectId& id);
    PyDbSpline(const PyDbObjectId& id, AcDb::OpenMode mode);

    PyDbSpline(const boost::python::list& fitPoints);
    PyDbSpline(const boost::python::list& fitPoints, int order, double  fitTolerance);

    PyDbSpline(const boost::python::list& fitPoints, const AcGeVector3d& startTangent, const AcGeVector3d& endTangent);
    PyDbSpline(const boost::python::list& fitPoints, const AcGeVector3d& startTangent, const AcGeVector3d& endTangent, int order, double fitTolerance);

#if !defined(_BRXTARGET) && (_BRXTARGET <= 23)
    PyDbSpline(const boost::python::list& fitPoints, bool periodic);
#endif

#if !defined(_BRXTARGET) && (_BRXTARGET <= 23)
    PyDbSpline(const boost::python::list& fitPoints, bool periodic, AcGe::KnotParameterization knotParam, int degree, double fitTolerance);
#endif

#if !defined(_BRXTARGET) && (_BRXTARGET <= 23)
    PyDbSpline(const boost::python::list& fitPoints, AcGe::KnotParameterization knotParam);
#endif

#if !defined(_BRXTARGET) && (_BRXTARGET <= 23)
    PyDbSpline(const boost::python::list& fitPoints, AcGe::KnotParameterization knotParam, int degree, double fitTolerance);
#endif

#if !defined(_BRXTARGET) && (_BRXTARGET <= 23)
    PyDbSpline(const boost::python::list& fitPoints, const AcGeVector3d& startTangent, const AcGeVector3d& endTangent, AcGe::KnotParameterization knotParam);
#endif

#if !defined(_BRXTARGET) && (_BRXTARGET <= 23)
    PyDbSpline(const boost::python::list& fitPoints, const AcGeVector3d& startTangent, const AcGeVector3d& endTangent, AcGe::KnotParameterization knotParam, int degree, double fitTolerance);
#endif

#if !defined(_BRXTARGET) && (_BRXTARGET <= 23)
    PyDbSpline(int degree, Adesk::Boolean rational, Adesk::Boolean closed, Adesk::Boolean periodic, const boost::python::list& controlPoints,
        const boost::python::list& knots, const boost::python::list& weights);
#endif

#if !defined(_BRXTARGET) && (_BRXTARGET <= 23)
    PyDbSpline(int degree, Adesk::Boolean rational, Adesk::Boolean closed, Adesk::Boolean periodic, const boost::python::list& controlPoints,
        const boost::python::list& knots, const boost::python::list& weights, double controlPtTol, double knotTol);
#endif

    PyDbSpline(const AcGePoint3d& center, const AcGeVector3d& unitNormal, const AcGeVector3d& majorAxis, double radiusRatio);
    PyDbSpline(const AcGePoint3d& center, const AcGeVector3d& unitNormal, const AcGeVector3d& majorAxis, double radiusRatio, double startAngle, double endAngle);
    virtual ~PyDbSpline() override = default;

    Adesk::Boolean      isNull() const;
    Adesk::Boolean      isRational() const;
    int                 degree() const;
    void                elevateDegree(int newDegree);
    int                 numControlPoints() const;
    AcGePoint3d         getControlPointAt(int index) const;
    void                setControlPointAt(int index, const AcGePoint3d& point);
    int                 numFitPoints() const;
    AcGePoint3d         getFitPointAt(int index) const;
    void                setFitPointAt(int index, const AcGePoint3d& point);
    void                insertFitPointAt(int index, const AcGePoint3d& point);
    void                removeFitPointAt(int index);
    double              fitTolerance() const;
    void                setFitTol(double tol);
    boost::python::tuple getFitTangents() const;
    void                setFitTangents(const AcGeVector3d& startTangent, const AcGeVector3d& endTangent);
    Adesk::Boolean      hasFitData() const;
    boost::python::tuple getFitData() const;
    void                setFitData(const boost::python::list& fitPoints, int degree, double fitTolerance, const AcGeVector3d& startTangent, const AcGeVector3d& endTangent);
    boost::python::tuple getFitDataKnot() const;
    void                setFitDataKnot1(const boost::python::list& fitPoints, const AcGeVector3d& startTangent, const AcGeVector3d& endTangent, AcGe::KnotParameterization  knotParam);
    void                setFitDataKnot2(const boost::python::list& fitPoints, const AcGeVector3d& startTangent, const AcGeVector3d& endTangent, AcGe::KnotParameterization  knotParam, int degree, double fitTolerance);
    void                setFitDataKnot3(const boost::python::list& fitPoints, bool isPeriodic, AcGe::KnotParameterization  knotParam);
    void                setFitDataKnot4(const boost::python::list& fitPoints, bool isPeriodic, AcGe::KnotParameterization  knotParam, int degree, double fitTolerance);
    void                purgeFitData();
    void                updateFitData();
    boost::python::tuple getNurbsData();
    void                setNurbsData1(int degree, Adesk::Boolean rational, Adesk::Boolean closed, Adesk::Boolean periodic,
        const  boost::python::list& controlPoints, const  boost::python::list& knots, const  boost::python::list& weights);
    void                setNurbsData2(int degree, Adesk::Boolean rational, Adesk::Boolean closed, Adesk::Boolean periodic,
        const  boost::python::list& controlPoints, const  boost::python::list& knots, const  boost::python::list& weights, double controlPtTol, double knotTol);
    double              weightAt(int index) const;
    void                setWeightAt(int index, double weight);
    void                insertKnot(double param);
    boost::python::list getOffsetCurvesGivenPlaneNormal(const AcGeVector3d& normal, double offsetDist);
    PyDbCurve           toPolyline();
    void                insertControlPointAt1(double knotParam, const AcGePoint3d& ctrlPt);
    void                insertControlPointAt2(double knotParam, const AcGePoint3d& ctrlPt, double weight);
    void                removeControlPointAt(int index);
    SplineType          type() const;
    void                setType(SplineType type);
    void                rebuild(int degree, int numCtrlPts);

public:
    static std::string  className();
    static PyRxClass    desc();
    static PyDbSpline	cloneFrom(const PyRxObject& src);
    static PyDbSpline   cast(const PyRxObject& src);
public:
    inline AcDbSpline* impObj(const std::source_location& src = std::source_location::current()) const;
};


//-----------------------------------------------------------------------------------
//PyDbHelix
void makePyDbHelixWrapper();
class PyDbHelix : public PyDbSpline
{
public:
    PyDbHelix();
    PyDbHelix(AcDbHelix* ptr, bool autoDelete);
    PyDbHelix(const PyDbObjectId& id);
    PyDbHelix(const PyDbObjectId& id, AcDb::OpenMode mode);
    virtual ~PyDbHelix() override = default;
    void            createHelix();
    AcGePoint3d     axisPoint() const;
    void            setAxisPoint1(const AcGePoint3d& axisPoint);
    void            setAxisPoint2(const AcGePoint3d& axisPoint, const bool bMoveStartPoint);
    AcGePoint3d     startPoint() const;
    void            setStartPoint(const AcGePoint3d& startPoint);
    AcGeVector3d    axisVector() const;
    void            setAxisVector(const AcGeVector3d& axisVector);
    double          height() const;
    void            setHeight(double dHeight);
    double          baseRadius() const;
    void            setBaseRadius(double dRadius);
    double          topRadius() const;
    void            setTopRadius(double dRadius);
    double          turns() const;
    void            setTurns(double dTurns);
    double          turnHeight() const;
    void            setTurnHeight(double dTurnHeight);
    Adesk::Boolean  twist() const;
    void            setTwist(Adesk::Boolean bTwist);
    AcDbHelix::ConstrainType   constrain() const;
    void                       setConstrain(AcDbHelix::ConstrainType constrain);
    double          turnSlope() const;
    double          totalLength() const;
    void            reverseCurve();

public:
    static std::string  className();
    static PyRxClass    desc();
    static PyDbHelix	cloneFrom(const PyRxObject& src);
    static PyDbHelix    cast(const PyRxObject& src);
public:
    inline AcDbHelix* impObj(const std::source_location& src = std::source_location::current()) const;
};