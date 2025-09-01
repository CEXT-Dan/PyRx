#pragma once
#include "PyRxObject.h"

#pragma pack (push, 8)
class PyGiDrawable;
class PyGiWorldGeometry;
class PyGiViewportGeometry;
class PyDbPolyline;
class PyGiSubEntityTraits;

//-----------------------------------------------------------------------------------------
//PyGiCommonDraw
void makePyGiCommonDrawWrapper();

class PyGiCommonDraw : public PyRxObject
{
public:
    PyGiCommonDraw(AcGiCommonDraw* ptr, bool autoDelete);
    virtual ~PyGiCommonDraw() override = default;
public:
    PyGiSubEntityTraits subEntityTraits() const;
    AcGiRegenType       regenType() const;
    Adesk::Boolean      regenAbort() const;
    Adesk::Boolean      isDragging() const;
    static std::string  className();
    static PyRxClass    desc();
public:
    AcGiCommonDraw* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//PyGiWorldDraw 
void makePyGiWorldDrawWrapper();

class PyGiWorldDraw : public PyGiCommonDraw
{
public:
    PyGiWorldDraw(AcGiWorldDraw* ptr, bool autoDelete);
    virtual ~PyGiWorldDraw() override = default;

    PyGiWorldGeometry   geometry() const;
    static std::string  className();
    static PyRxClass    desc();
public:
    AcGiWorldDraw* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//PyGiViewportDraw
void makePyGiViewportDrawWrapper();

class PyGiViewportDraw : public PyGiCommonDraw
{
public:
    PyGiViewportDraw(AcGiViewportDraw* ptr, bool autoDelete);
    virtual ~PyGiViewportDraw() override = default;

    PyGiViewportGeometry geometry() const;
    static std::string  className();
    static PyRxClass    desc();
public:
    AcGiViewportDraw* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//PyGiGeometry
void makePyGiGeometryWrapper();

class PyGiGeometry : public PyRxObject
{
public:
    PyGiGeometry(AcGiGeometry* ptr, bool autoDelete);
    virtual ~PyGiGeometry() override = default;

    AcGeMatrix3d		getModelToWorldTransform() const;
    AcGeMatrix3d		getWorldToModelTransform() const;
    Adesk::Boolean		pushModelTransform1(const AcGeVector3d& vNormal) const;
    Adesk::Boolean		pushModelTransform2(const AcGeMatrix3d& xMat) const;
    Adesk::Boolean		popModelTransform() const;
    AcGeMatrix3d        pushPositionTransform1(AcGiPositionTransformBehavior behavior, const AcGePoint3d& offset) const;
    AcGeMatrix3d        pushPositionTransform2(AcGiPositionTransformBehavior behavior, const AcGePoint2d& offset) const;
    AcGeMatrix3d        pushScaleTransform1(AcGiScaleTransformBehavior behavior, const AcGePoint3d& extents) const;
    AcGeMatrix3d        pushScaleTransform2(AcGiScaleTransformBehavior behavior, const AcGePoint2d& extents) const;
    AcGeMatrix3d        pushOrientationTransform(AcGiOrientationTransformBehavior behavior) const;
    Adesk::Boolean      circle1(const AcGePoint3d& center, const double radius, const AcGeVector3d& normal) const;
    Adesk::Boolean      circle2(const AcGePoint3d&, const AcGePoint3d&, const AcGePoint3d&) const;
    Adesk::Boolean      circularArc1(const AcGePoint3d& center, const double radius, const AcGeVector3d& normal,
        const AcGeVector3d& startVector, const double sweepAngle) const;
    Adesk::Boolean      circularArc2(const AcGePoint3d& center, const double radius, const AcGeVector3d& normal,
        const AcGeVector3d& startVector, const double sweepAngle, const AcGiArcType arcType) const;
    Adesk::Boolean      circularArc3(const AcGePoint3d& start, const AcGePoint3d& point, const AcGePoint3d& end) const;
    Adesk::Boolean      circularArc4(const AcGePoint3d& start, const AcGePoint3d& point, const AcGePoint3d& end, const AcGiArcType arcType) const;
    Adesk::Boolean      polyline1(const boost::python::object& vertexList) const;
    Adesk::Boolean      polyline2(const boost::python::object& vertexList, const AcGeVector3d& normal) const;
    Adesk::Boolean      polyline3(const boost::python::object& vertexList, const AcGeVector3d& normal, Adesk::LongPtr marker) const;
    Adesk::Boolean      polygon(const boost::python::object& vertexList) const;
    Adesk::Boolean      text1(const AcGePoint3d& position, const AcGeVector3d& normal, const AcGeVector3d& direction, const double height,
        const double width, const double oblique, const std::string& pMsg) const;
    Adesk::Boolean      xline(const AcGePoint3d& p1, const AcGePoint3d& p2) const;
    Adesk::Boolean      ray(const AcGePoint3d& p1, const AcGePoint3d& p2) const;
    Adesk::Boolean      pline1(const PyDbPolyline& lwBuf) const;
    Adesk::Boolean      pline2(const PyDbPolyline& lwBuf, Adesk::UInt32 fromIndex, Adesk::UInt32 numSegs) const;
    Adesk::Boolean      rowOfDots(int count, const AcGePoint3d& start, const AcGeVector3d& step) const;
    Adesk::Boolean      ellipticalArc1(const AcGePoint3d& center, const AcGeVector3d& normal, double majorAxisLength, double minorAxisLength,
        double startDegreeInRads, double endDegreeInRads, double tiltDegreeInRads) const;
    Adesk::Boolean      ellipticalArc2(const AcGePoint3d& center, const AcGeVector3d& normal, double majorAxisLength, double minorAxisLength,
        double startDegreeInRads, double endDegreeInRads, double tiltDegreeInRads, AcGiArcType arcType) const;
    Adesk::Boolean      worldLine(const AcGePoint3d& pnt1, const AcGePoint3d& pnt2) const;
    Adesk::Boolean      edge(const boost::python::object& edges) const;
    Adesk::Boolean		draw(PyGiDrawable& drawable) const;
    Adesk::Boolean      image1(const boost::python::object& imageSource, const AcGePoint3d& position, const AcGeVector3d& u, const AcGeVector3d& v) const;
    Adesk::Boolean      image2(const PyGiPixelBGRA32Array& imageSource, int width, int height, const AcGePoint3d& position, const AcGeVector3d& u, const AcGeVector3d& v) const;
    static std::string	className();
    static PyRxClass	desc();
public:
    AcGiGeometry* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//PyGiWorldGeometry
void makePyGiWorldGeometryWrapper();

class PyGiWorldGeometry : public PyGiGeometry
{
public:
    PyGiWorldGeometry(AcGiWorldGeometry* ptr, bool autoDelete);
    virtual ~PyGiWorldGeometry() override = default;

    static std::string className();
    static PyRxClass    desc();
public:
    AcGiWorldGeometry* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//AcGiViewportGeometry
void makePyGiViewportGeometryWrapper();

class PyGiViewportGeometry : public PyGiGeometry
{
public:
    PyGiViewportGeometry(AcGiViewportGeometry* ptr, bool autoDelete);
    virtual ~PyGiViewportGeometry() override = default;

    static std::string  className();
    static PyRxClass    desc();
public:
    AcGiViewportGeometry* impObj(const std::source_location& src = std::source_location::current()) const;
};
#pragma pack (pop)











