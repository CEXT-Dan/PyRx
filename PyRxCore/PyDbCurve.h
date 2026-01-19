#pragma once
#include "PyDbEntity.h"

#pragma pack (push, 8)

class PyGeCurve3d;
class PyDbSpline;
class PyGePlane;

//-----------------------------------------------------------------------------------
//PyDbCurve
void makePyDbCurveWrapper();
class PyDbCurve : public PyDbEntity
{
protected:
    inline PyDbCurve() = default;
public:
    PyDbCurve(AcDbCurve* ptr, bool autoDelete);
    PyDbCurve(const PyDbObjectId& id);
    PyDbCurve(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbCurve(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    virtual ~PyDbCurve() override = default;
    bool            isClosed() const;
    bool            isPeriodic() const;
    bool            isOn1(const AcGePoint3d& pnt) const;
    bool            isOn2(const AcGePoint3d& pnt, const AcGeTol& tol) const;
    bool            isOn3(double param) const;
    bool            isOn4(double param, const AcGeTol& tol) const;
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
    AcGePoint3d         getClosestPointTo2(const AcGePoint3d& givenPnt, bool extend) const;
    AcGePoint3d         getClosestPointTo3(const AcGePoint3d& givenPnt, const AcGeVector3d& direction, bool extend) const;

    boost::python::list getOffsetCurves(double offsetDist) const;
    boost::python::list getOffsetCurvesGivenPlaneNormal(const AcGeVector3d& normal, double offsetDist) const;
    boost::python::list getSplitCurves(const boost::python::list& params) const;
    boost::python::list getSplitCurvesAtParam(double param) const;
    boost::python::list getSplitCurvesAtParams(const boost::python::object& params) const;
    boost::python::list getSplitCurvesAtPoint(const AcGePoint3d& givenPnt) const;
    boost::python::list getSplitCurvesAtPoints(const boost::python::object& params) const;

    PyDbCurve           getOrthoProjectedCurve(const PyGePlane& plane) const;
    PyDbCurve           getProjectedCurve(const PyGePlane& plane, const AcGeVector3d& projDir) const;

    PyDbSpline          getSpline() const;
    void                extend1(double newParam) const;
    void                extend2(bool extendStart, const AcGePoint3d& toPoint) const;
    double              getArea() const;
    void                reverseCurve() const;
    PyGeCurve3d         getAcGeCurve1() const;
    PyGeCurve3d         getAcGeCurve2(const AcGeTol& tol) const;
    void                setFromAcGeCurve1(const PyGeCurve3d& geCurve) const;
    void                setFromAcGeCurve2(const PyGeCurve3d& geCurve, AcGeVector3d& normal) const;
    void                setFromAcGeCurve3(const PyGeCurve3d& geCurve, AcGeVector3d& normal, const AcGeTol& tol) const;
    static PyDbCurve    createFromAcGeCurve1(const PyGeCurve3d& geCurve);
    static PyDbCurve    createFromAcGeCurve2(const PyGeCurve3d& geCurve, AcGeVector3d& normal);
    static PyDbCurve    createFromAcGeCurve3(const PyGeCurve3d& geCurve, AcGeVector3d& normal, const AcGeTol& tol);
    static std::string  className();
    static PyRxClass    desc();
    static PyDbCurve    cloneFrom(const PyRxObject& src);
    static PyDbCurve    cast(const PyRxObject& src);
public:
    AcDbCurve* impObj(const std::source_location& src = std::source_location::current()) const;
};
#pragma pack (pop)
