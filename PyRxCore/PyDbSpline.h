#pragma once
#include "PyDbCurve.h"
#include "dbhelix.h"

#pragma pack (push, 8)
class PyGeNurbCurve3d;
class PyDbPolyline;

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
    PyDbSpline(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);

    PyDbSpline(const boost::python::list& fitPoints);
    PyDbSpline(const boost::python::list& fitPoints, int order, double  fitTolerance);

    PyDbSpline(const boost::python::list& fitPoints, const AcGeVector3d& startTangent, const AcGeVector3d& endTangent);
    PyDbSpline(const boost::python::list& fitPoints, const AcGeVector3d& startTangent, const AcGeVector3d& endTangent, int order, double fitTolerance);

    PyDbSpline(const boost::python::list& fitPoints, bool periodic);
    PyDbSpline(const boost::python::list& fitPoints, bool periodic, AcGe::KnotParameterization knotParam, int degree, double fitTolerance);

    PyDbSpline(const boost::python::list& fitPoints, AcGe::KnotParameterization knotParam);
    PyDbSpline(const boost::python::list& fitPoints, AcGe::KnotParameterization knotParam, int degree, double fitTolerance);

    PyDbSpline(const boost::python::list& fitPoints, const AcGeVector3d& startTangent, const AcGeVector3d& endTangent, AcGe::KnotParameterization knotParam);
    PyDbSpline(const boost::python::list& fitPoints, const AcGeVector3d& startTangent, const AcGeVector3d& endTangent, AcGe::KnotParameterization knotParam, int degree, double fitTolerance);

    PyDbSpline(int degree, Adesk::Boolean rational, Adesk::Boolean closed, Adesk::Boolean periodic, const boost::python::list& controlPoints,
        const boost::python::list& knots, const boost::python::list& weights);

    PyDbSpline(int degree, Adesk::Boolean rational, Adesk::Boolean closed, Adesk::Boolean periodic, const boost::python::list& controlPoints,
        const boost::python::list& knots, const boost::python::list& weights, double controlPtTol, double knotTol);

    PyDbSpline(const AcGePoint3d& center, const AcGeVector3d& unitNormal, const AcGeVector3d& majorAxis, double radiusRatio);
    PyDbSpline(const AcGePoint3d& center, const AcGeVector3d& unitNormal, const AcGeVector3d& majorAxis, double radiusRatio, double startAngle, double endAngle);

    virtual ~PyDbSpline() override = default;

    Adesk::Boolean      isNull() const;
    Adesk::Boolean      isRational() const;
    int                 degree() const;
    void                elevateDegree(int newDegree) const;
    int                 numControlPoints() const;
    AcGePoint3d         getControlPointAt(int index) const;
    void                setControlPointAt(int index, const AcGePoint3d& point) const;
    int                 numFitPoints() const;
    AcGePoint3d         getFitPointAt(int index) const;
    void                setFitPointAt(int index, const AcGePoint3d& point) const;
    void                insertFitPointAt(int index, const AcGePoint3d& point) const;
    void                removeFitPointAt(int index) const;
    double              fitTolerance() const;
    void                setFitTol(double tol) const;
    boost::python::tuple getFitTangents() const;
    void                setFitTangents(const AcGeVector3d& startTangent, const AcGeVector3d& endTangent) const;
    Adesk::Boolean      hasFitData() const;
    boost::python::tuple getFitData() const;
    void                setFitData(const boost::python::list& fitPoints, int degree, double fitTolerance, const AcGeVector3d& startTangent, const AcGeVector3d& endTangent) const;
    boost::python::tuple getFitDataKnot() const;
    void                setFitDataKnot1(const boost::python::list& fitPoints, const AcGeVector3d& startTangent, const AcGeVector3d& endTangent, AcGe::KnotParameterization  knotParam) const;
    void                setFitDataKnot2(const boost::python::list& fitPoints, const AcGeVector3d& startTangent, const AcGeVector3d& endTangent, AcGe::KnotParameterization  knotParam, int degree, double fitTolerance) const;
    void                setFitDataKnot3(const boost::python::list& fitPoints, bool isPeriodic, AcGe::KnotParameterization  knotParam) const;
    void                setFitDataKnot4(const boost::python::list& fitPoints, bool isPeriodic, AcGe::KnotParameterization  knotParam, int degree, double fitTolerance) const;
    void                purgeFitData() const;
    void                updateFitData() const;
    boost::python::tuple getNurbsData() const;
    void                setNurbsData1(int degree, Adesk::Boolean rational, Adesk::Boolean closed, Adesk::Boolean periodic,
        const  boost::python::list& controlPoints, const  boost::python::list& knots, const  boost::python::list& weights) const;
    void                setNurbsData2(int degree, Adesk::Boolean rational, Adesk::Boolean closed, Adesk::Boolean periodic,
        const  boost::python::list& controlPoints, const  boost::python::list& knots, const  boost::python::list& weights, double controlPtTol, double knotTol) const;
    double              weightAt(int index) const;
    void                setWeightAt(int index, double weight) const;
    void                insertKnot(double param) const;
    boost::python::list getOffsetCurvesGivenPlaneNormal(const AcGeVector3d& normal, double offsetDist) const;
    PyDbPolyline        toPolyline() const;
    void                insertControlPointAt1(double knotParam, const AcGePoint3d& ctrlPt) const;
    void                insertControlPointAt2(double knotParam, const AcGePoint3d& ctrlPt, double weight) const;
    void                removeControlPointAt(int index) const;
    SplineType          type() const;
    void                setType(SplineType type) const;
    void                rebuild(int degree, int numCtrlPts) const;
    PyGeNurbCurve3d     getAcGeCurve1() const;
    PyGeNurbCurve3d     getAcGeCurve2(const AcGeTol& tol) const;

public:
    static std::string  className();
    static PyRxClass    desc();
    static PyDbSpline	cloneFrom(const PyRxObject& src);
    static PyDbSpline   cast(const PyRxObject& src);
public:
    AcDbSpline* impObj(const std::source_location& src = std::source_location::current()) const;
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
    void            createHelix() const;
    AcGePoint3d     axisPoint() const;
    void            setAxisPoint1(const AcGePoint3d& axisPoint) const;
    void            setAxisPoint2(const AcGePoint3d& axisPoint, const bool bMoveStartPoint) const;
    AcGePoint3d     startPoint() const;
    void            setStartPoint(const AcGePoint3d& startPoint) const;
    AcGeVector3d    axisVector() const;
    void            setAxisVector(const AcGeVector3d& axisVector) const;
    double          height() const;
    void            setHeight(double dHeight) const;
    double          baseRadius() const;
    void            setBaseRadius(double dRadius) const;
    double          topRadius() const;
    void            setTopRadius(double dRadius) const;
    double          turns() const;
    void            setTurns(double dTurns) const;
    double          turnHeight() const;
    void            setTurnHeight(double dTurnHeight) const;
    Adesk::Boolean  twist() const;
    void            setTwist(Adesk::Boolean bTwist) const;
    AcDbHelix::ConstrainType   constrain() const;
    void                       setConstrain(AcDbHelix::ConstrainType constrain) const;
    double          turnSlope() const;
    double          totalLength() const;
    void            reverseCurve() const;

public:
    static std::string  className();
    static PyRxClass    desc();
    static PyDbHelix	cloneFrom(const PyRxObject& src);
    static PyDbHelix    cast(const PyRxObject& src);
public:
    AcDbHelix* impObj(const std::source_location& src = std::source_location::current()) const;
};
#pragma pack (pop)