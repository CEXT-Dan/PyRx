#pragma once
#include "PyDbEntity.h"

class PyGeCurve3d;

//-----------------------------------------------------------------------------------
//PyDbCurve
void makePyDbCurveWrapper();
class PyDbCurve : public PyDbEntity
{
public:
    PyDbCurve(AcDbCurve* ptr, bool autoDelete);
    PyDbCurve(const PyDbObjectId& id);
    PyDbCurve(const PyDbObjectId& id, AcDb::OpenMode mode);
    virtual ~PyDbCurve() override = default;
    Adesk::Boolean      isClosed() const;
    Adesk::Boolean      isPeriodic() const;
    double              getStartParam() const;
    double              getEndParam() const;
    AcGePoint3d         getStartPoint() const;
    AcGePoint3d         getEndPoint() const;
    AcGePoint3d         getPointAtParam(double) const;
    double              getParamAtPoint(const AcGePoint3d& pnt)const;
    double              getDistAtParam(double param) const;
    double              getParamAtDist(double dist) const;
    double              getDistAtPoint(const AcGePoint3d& pnt)const;
    AcGePoint3d         getPointAtDist(double) const;

    AcGeVector3d        getFirstDeriv1(double param) const;
    AcGeVector3d        getFirstDeriv2(const AcGePoint3d& pnt) const;

    AcGeVector3d        getSecondDeriv1(double param) const;
    AcGeVector3d        getSecondDeriv2(const AcGePoint3d& pnt) const;

    AcGePoint3d         getClosestPointTo1(const AcGePoint3d& givenPnt) const;
    AcGePoint3d         getClosestPointTo2(const AcGePoint3d& givenPnt, Adesk::Boolean extend) const;
    AcGePoint3d         getClosestPointTo3(const AcGePoint3d& givenPnt, const AcGeVector3d& direction, Adesk::Boolean extend) const;

    boost::python::list getOffsetCurves(double offsetDist) const;
    boost::python::list getOffsetCurvesGivenPlaneNormal(const AcGeVector3d& normal, double offsetDist) const;
    boost::python::list getSplitCurves(const boost::python::list& params) const;
    boost::python::list getSplitCurvesAtParam(double param) const;
    boost::python::list getSplitCurvesAtParams(const boost::python::list& params) const;
    boost::python::list getSplitCurvesAtPoint(const AcGePoint3d& givenPnt) const;
    boost::python::list getSplitCurvesAtPoints(const boost::python::list& params) const;
    void                extend1(double newParam);
    void                extend2(Adesk::Boolean extendStart, const AcGePoint3d& toPoint);
    double              getArea() const;
    void                reverseCurve();
    PyGeCurve3d         getAcGeCurve1() const;
    PyGeCurve3d         getAcGeCurve2(const AcGeTol& tol) const;
    void                setFromAcGeCurve1(const PyGeCurve3d& geCurve);
    void                setFromAcGeCurve2(const PyGeCurve3d& geCurve, AcGeVector3d& normal);
    void                setFromAcGeCurve3(const PyGeCurve3d& geCurve, AcGeVector3d& normal, const AcGeTol& tol);
    static PyDbCurve    createFromAcGeCurve1(const PyGeCurve3d& geCurve);
    static PyDbCurve    createFromAcGeCurve2(const PyGeCurve3d& geCurve, AcGeVector3d& normal);
    static PyDbCurve    createFromAcGeCurve3(const PyGeCurve3d& geCurve, AcGeVector3d& normal, const AcGeTol& tol);
    static std::string          className();
    static PyRxClass            desc();
    static PyDbCurve            cloneFrom(const PyRxObject& src);
    static PyDbCurve            cast(const PyRxObject& src);
public:
    AcDbCurve* impObj(const std::source_location& src = std::source_location::current()) const;
};
