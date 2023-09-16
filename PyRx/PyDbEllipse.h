#pragma once

#include "PyDbCurve.h"

class PyGeEllipArc3d;

//-----------------------------------------------------------------------------------
//PyDbCurve
void makePyDbEllipseWrapper();

class PyDbEllipse : public PyDbCurve
{
public:
    PyDbEllipse();

    PyDbEllipse(const AcGePoint3d& center,
        const AcGeVector3d& unitNormal,
        const AcGeVector3d& majorAxis,
        double              radiusRatio);

    PyDbEllipse(const AcGePoint3d& center,
        const AcGeVector3d& unitNormal,
        const AcGeVector3d& majorAxis,
        double              radiusRatio,
        double              startAngle,
        double              endAngle);

    PyDbEllipse(const PyDbObjectId& id);
    PyDbEllipse(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbEllipse(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);

    PyDbEllipse(AcDbEllipse* ptr, bool autoDelete);
    virtual ~PyDbEllipse() override = default;

    AcGePoint3d         center() const;
    void                setCenter(const AcGePoint3d& center);
    AcGeVector3d        normal() const;
    AcGeVector3d        majorAxis() const;
    AcGeVector3d        minorAxis() const;
    double              majorRadius() const;
    double              minorRadius() const;
    void                setMajorRadius(double val);
    void                setMinorRadius(double val);
    double              radiusRatio() const;
    void                setRadiusRatio(double ratio);
    double              startAngle() const;
    void                setStartAngle(double startAngle);
    double              endAngle() const;
    void                setEndAngle(double endAngle);
    void                setStartParam(double startParam);
    void                setEndParam(double endParam);
    double              paramAtAngle(double angle) const;
    double              angleAtParam(double param) const;
    boost::python::tuple get() const;
    void                set1(const AcGePoint3d& center, const AcGeVector3d& unitNormal, const AcGeVector3d& majorAxis, double radiusRatio);
    void                set2(const AcGePoint3d& center, const AcGeVector3d& unitNormal, const AcGeVector3d& majorAxis, double radiusRatio, double startAngle, double endAngle);
    Adesk::Boolean      isNull() const;
    PyGeEllipArc3d      getAcGeCurve1() const;
    PyGeEllipArc3d      getAcGeCurve2(const AcGeTol& tol) const;
    static std::string  className();
    static PyRxClass    desc();
    static PyDbEllipse  cloneFrom(const PyRxObject& src);
    static PyDbEllipse  cast(const PyRxObject& src);
public:
    inline AcDbEllipse* impObj(const std::source_location& src = std::source_location::current()) const;
};

