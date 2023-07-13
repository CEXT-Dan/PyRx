#pragma once
#include "PyDbEntity.h"
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
    virtual Adesk::Boolean      isClosed() const;
    virtual Adesk::Boolean      isPeriodic() const;
    virtual double              getStartParam() const;
    virtual double              getEndParam() const;
    virtual AcGePoint3d         getStartPoint() const;
    virtual AcGePoint3d         getEndPoint() const;
    virtual AcGePoint3d         getPointAtParam(double) const;
    virtual double              getParamAtPoint(const AcGePoint3d& pnt)const;
    virtual double              getDistAtParam(double param) const;
    virtual double              getParamAtDist(double dist) const;
    virtual double              getDistAtPoint(const AcGePoint3d& pnt)const;
    virtual AcGePoint3d         getPointAtDist(double) const;
    virtual AcGeVector3d        getFirstDeriv(double param) const;
    virtual AcGeVector3d        getFirstDeriv(const AcGePoint3d& pnt) const;
    virtual AcGeVector3d        getSecondDeriv(double param) const;
    virtual AcGeVector3d        getSecondDeriv(const AcGePoint3d& pnt) const;
    virtual AcGePoint3d         getClosestPointTo(const AcGePoint3d& givenPnt, Adesk::Boolean extend) const;
    virtual AcGePoint3d         getClosestPointTo(const AcGePoint3d& givenPnt, const AcGeVector3d& direction, Adesk::Boolean extend) const;
    virtual boost::python::list getOffsetCurves(double offsetDist) const;
    virtual boost::python::list getOffsetCurvesGivenPlaneNormal(const AcGeVector3d& normal, double offsetDist) const;
    virtual boost::python::list getSplitCurves(const boost::python::list& params) const;
    virtual boost::python::list getSplitCurvesAtParams(const boost::python::list& params) const;
    virtual boost::python::list getSplitCurvesAtPoints(const boost::python::list& params) const;
    virtual void                extend(double newParam);
    virtual void                extend(Adesk::Boolean extendStart, const AcGePoint3d& toPoint);
    virtual double              getArea() const;
    virtual void                reverseCurve();
    static std::string          className();
    static PyRxClass            desc();
    static PyDbCurve            cloneFrom(const PyRxObject& src);
    static PyDbCurve            cast(const PyRxObject& src);
public:
    AcDbCurve* impObj(const std::source_location& src = std::source_location::current()) const;
};
