#include "stdafx.h"
#include "PyGiCommonDraw.h"
#include "PyGiDrawable.h"
#include "PyDbEnts.h"
#include "PyGeCurve2d.h"
#include "PyGiSubEntityTraits.h"

using namespace boost::python;
void makePyGiCommonDrawWrapper()
{
    class_<PyGiCommonDraw, bases<PyRxObject>>("CommonDraw", boost::python::no_init)
        .def("regenType", &PyGiCommonDraw::regenType)
        .def("regenAbort", &PyGiCommonDraw::regenAbort)
        .def("isDragging", &PyGiCommonDraw::isDragging)
        .def("subEntityTraits", &PyGiCommonDraw::subEntityTraits)
        .def("className", &PyGiCommonDraw::className).staticmethod("className")
        .def("desc", &PyGiCommonDraw::desc).staticmethod("desc")
        ;
}

PyGiCommonDraw::PyGiCommonDraw(AcGiCommonDraw* ptr, bool autoDelete)
    : PyRxObject(ptr, autoDelete, false)
{
}

PyGiSubEntityTraits PyGiCommonDraw::subEntityTraits() const
{
    return PyGiSubEntityTraits(std::addressof(impObj()->subEntityTraits()), false);
}

AcGiRegenType PyGiCommonDraw::regenType() const
{
    return impObj()->regenType();
}

Adesk::Boolean PyGiCommonDraw::regenAbort() const
{
    return impObj()->regenAbort();
}

Adesk::Boolean PyGiCommonDraw::isDragging() const
{
    return impObj()->isDragging();
}

std::string PyGiCommonDraw::className()
{
    return "AcGiCommonDraw";
}

PyRxClass PyGiCommonDraw::desc()
{
    return PyRxClass(AcGiCommonDraw::desc(), false);
}

AcGiCommonDraw* PyGiCommonDraw::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcGiCommonDraw*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
//PyGiWorldDraw 
void makePyGiWorldDrawWrapper()
{
    class_<PyGiWorldDraw, bases<PyGiCommonDraw>>("WorldDraw", boost::python::no_init)
        .def("geometry", &PyGiWorldDraw::geometry)
        .def("className", &PyGiWorldDraw::className).staticmethod("className")
        .def("desc", &PyGiWorldDraw::desc).staticmethod("desc")
        ;
}

PyGiWorldDraw::PyGiWorldDraw(AcGiWorldDraw* ptr, bool autoDelete)
    : PyGiCommonDraw(ptr, autoDelete)
{
}

PyGiWorldGeometry PyGiWorldDraw::geometry() const
{
    return PyGiWorldGeometry(std::addressof(impObj()->geometry()), false);
}

std::string PyGiWorldDraw::className()
{
    return "AcGiWorldDraw";
}

PyRxClass PyGiWorldDraw::desc()
{
    return PyRxClass(AcGiWorldDraw::desc(), false);
}

AcGiWorldDraw* PyGiWorldDraw::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcGiWorldDraw*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
//PyGiViewportDraw
void makeAcGiViewportDrawWrapper()
{
    class_<PyGiViewportDraw, bases<PyGiCommonDraw>>("ViewportDraw", boost::python::no_init)
        .def("geometry", &PyGiViewportDraw::geometry)
        .def("className", &PyGiViewportDraw::className).staticmethod("className")
        .def("desc", &PyGiViewportDraw::desc).staticmethod("desc")
        ;
}

PyGiViewportDraw::PyGiViewportDraw(AcGiViewportDraw* ptr, bool autoDelete)
    : PyGiCommonDraw(ptr, autoDelete)
{
}

PyGiViewportGeometry PyGiViewportDraw::geometry() const
{
    return PyGiViewportGeometry(std::addressof(impObj()->geometry()), false);
}

std::string PyGiViewportDraw::className()
{
    return "AcGiViewportDraw";
}

PyRxClass PyGiViewportDraw::desc()
{
    return PyRxClass(AcGiViewportDraw::desc(), false);
}

AcGiViewportDraw* PyGiViewportDraw::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcGiViewportDraw*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
//PyGiGeometry
void makeAcGiGeometryWrapper()
{
    class_<PyGiGeometry, bases<PyRxObject>>("Geometry", boost::python::no_init)
        .def("getModelToWorldTransform", &PyGiGeometry::getModelToWorldTransform)
        .def("getWorldToModelTransform", &PyGiGeometry::getWorldToModelTransform)
        .def("pushModelTransform", &PyGiGeometry::pushModelTransform1)
        .def("pushModelTransform", &PyGiGeometry::pushModelTransform2)
        .def("popModelTransform", &PyGiGeometry::popModelTransform)
        .def("pushPositionTransform", &PyGiGeometry::pushPositionTransform1)
        .def("pushPositionTransform", &PyGiGeometry::pushPositionTransform2)
        .def("pushScaleTransform", &PyGiGeometry::pushScaleTransform1)
        .def("pushScaleTransform", &PyGiGeometry::pushScaleTransform2)
        .def("pushOrientationTransform", &PyGiGeometry::pushOrientationTransform)
        .def("circle", &PyGiGeometry::circle1)
        .def("circle", &PyGiGeometry::circle2)
        .def("circularArc", &PyGiGeometry::circularArc1)
        .def("circularArc", &PyGiGeometry::circularArc2)
        .def("circularArc", &PyGiGeometry::circularArc3)
        .def("circularArc", &PyGiGeometry::circularArc4)
        .def("polyline", &PyGiGeometry::polyline1)
        .def("polyline", &PyGiGeometry::polyline2)
        .def("polygon", &PyGiGeometry::polygon)
        .def("text", &PyGiGeometry::text1)
        .def("xline", &PyGiGeometry::xline)
        .def("ray", &PyGiGeometry::ray)
        .def("pline", &PyGiGeometry::pline1)
        .def("pline", &PyGiGeometry::pline2)
        .def("rowOfDots", &PyGiGeometry::rowOfDots)
        .def("ellipticalArc", &PyGiGeometry::ellipticalArc1)
        .def("ellipticalArc", &PyGiGeometry::ellipticalArc2)
        .def("worldLine", &PyGiGeometry::worldLine)
        .def("edge", &PyGiGeometry::edge)
        .def("draw", &PyGiGeometry::draw)
        .def("className", &PyGiGeometry::className).staticmethod("className")
        .def("desc", &PyGiGeometry::desc).staticmethod("desc")
        ;
}

PyGiGeometry::PyGiGeometry(AcGiGeometry* ptr, bool autoDelete)
    : PyRxObject(ptr, autoDelete, false)
{
}

AcGeMatrix3d PyGiGeometry::getModelToWorldTransform() const
{
    AcGeMatrix3d mat;
    impObj()->getModelToWorldTransform(mat);
    return mat;
}

AcGeMatrix3d PyGiGeometry::getWorldToModelTransform() const
{
    AcGeMatrix3d mat;
    impObj()->getWorldToModelTransform(mat);
    return mat;
}

Adesk::Boolean PyGiGeometry::pushModelTransform1(const AcGeVector3d& vNormal)
{
    return impObj()->pushModelTransform(vNormal);
}

Adesk::Boolean PyGiGeometry::pushModelTransform2(const AcGeMatrix3d& xMat)
{
    return impObj()->pushModelTransform(xMat);
}

Adesk::Boolean PyGiGeometry::popModelTransform()
{
    return impObj()->popModelTransform();
}

AcGeMatrix3d PyGiGeometry::pushPositionTransform1(AcGiPositionTransformBehavior behavior, const AcGePoint3d& offset)
{
    return impObj()->pushPositionTransform(behavior, offset);
}

AcGeMatrix3d PyGiGeometry::pushPositionTransform2(AcGiPositionTransformBehavior behavior, const AcGePoint2d& offset)
{
    return impObj()->pushPositionTransform(behavior, offset);
}

AcGeMatrix3d PyGiGeometry::pushScaleTransform1(AcGiScaleTransformBehavior behavior, const AcGePoint3d& extents)
{
    return impObj()->pushScaleTransform(behavior, extents);
}

AcGeMatrix3d PyGiGeometry::pushScaleTransform2(AcGiScaleTransformBehavior behavior, const AcGePoint2d& extents)
{
    return impObj()->pushScaleTransform(behavior, extents);
}

AcGeMatrix3d PyGiGeometry::pushOrientationTransform(AcGiOrientationTransformBehavior behavior)
{
    return impObj()->pushOrientationTransform(behavior);
}

Adesk::Boolean PyGiGeometry::circle1(const AcGePoint3d& center, const double radius, const AcGeVector3d& normal) const
{
    return impObj()->circle(center, radius, normal);
}

Adesk::Boolean PyGiGeometry::circle2(const AcGePoint3d& p1, const AcGePoint3d& p2, const AcGePoint3d& p3) const
{
    return impObj()->circle(p1, p2, p3);
}

Adesk::Boolean PyGiGeometry::circularArc1(const AcGePoint3d& center, const double radius, const AcGeVector3d& normal,
    const AcGeVector3d& startVector, const double sweepAngle) const
{
    return impObj()->circularArc(center, radius, normal, startVector, sweepAngle);
}

Adesk::Boolean PyGiGeometry::circularArc2(const AcGePoint3d& center, const double radius, const AcGeVector3d& normal,
    const AcGeVector3d& startVector, const double sweepAngle, const AcGiArcType arcType) const
{
    return impObj()->circularArc(center, radius, normal, startVector, sweepAngle, arcType);
}

Adesk::Boolean PyGiGeometry::circularArc3(const AcGePoint3d& start, const AcGePoint3d& point, const AcGePoint3d& end) const
{
    return impObj()->circularArc(start, point, end);
}

Adesk::Boolean PyGiGeometry::circularArc4(const AcGePoint3d& start, const AcGePoint3d& point, const AcGePoint3d& end, const AcGiArcType arcType) const
{
    return impObj()->circularArc(start, point, end, arcType);
}

Adesk::Boolean PyGiGeometry::polyline1(const boost::python::list& vertexList)
{
    std::vector<AcGePoint3d> pnts = py_list_to_std_vector<AcGePoint3d>(vertexList);
    return impObj()->polyline(pnts.size(), pnts.data());
}

Adesk::Boolean PyGiGeometry::polyline2(const boost::python::list& vertexList, const AcGeVector3d& normal, Adesk::LongPtr marker)
{
    std::vector<AcGePoint3d> pnts = py_list_to_std_vector<AcGePoint3d>(vertexList);
    return impObj()->polyline(pnts.size(), pnts.data(), &normal, marker);
}

Adesk::Boolean PyGiGeometry::polygon(const boost::python::list& vertexList) const
{
    std::vector<AcGePoint3d> pnts = py_list_to_std_vector<AcGePoint3d>(vertexList);
    return impObj()->polygon(pnts.size(), pnts.data());
}

Adesk::Boolean PyGiGeometry::text1(const AcGePoint3d& position, const AcGeVector3d& normal, const AcGeVector3d& direction, const double height, const double width, 
    const double oblique, const std::string& pMsg) const
{
    return impObj()->text(position, normal, direction, height, width, oblique, utf8_to_wstr(pMsg).c_str());
}

Adesk::Boolean PyGiGeometry::xline(const AcGePoint3d& p1, const AcGePoint3d& p2) const
{
    return impObj()->xline(p1, p2);
}

Adesk::Boolean PyGiGeometry::ray(const AcGePoint3d& p1, const AcGePoint3d& p2) const
{
    return impObj()->ray(p1, p2);
}

Adesk::Boolean PyGiGeometry::pline1(const PyDbPolyline& lwBuf) const
{
    return impObj()->pline(*lwBuf.impObj());
}

Adesk::Boolean PyGiGeometry::pline2(const PyDbPolyline& lwBuf, Adesk::UInt32 fromIndex, Adesk::UInt32 numSegs) const
{
    return impObj()->pline(*lwBuf.impObj(), fromIndex, numSegs);
}

Adesk::Boolean PyGiGeometry::rowOfDots(int count, const AcGePoint3d& start, const AcGeVector3d& step) const
{
    return impObj()->rowOfDots(count, start, step);
}

Adesk::Boolean PyGiGeometry::ellipticalArc1(const AcGePoint3d& center, const AcGeVector3d& normal, double majorAxisLength, double minorAxisLength, 
    double startDegreeInRads, double endDegreeInRads, double tiltDegreeInRads)
{
    return impObj()->ellipticalArc( center, normal, majorAxisLength, minorAxisLength, startDegreeInRads, endDegreeInRads, tiltDegreeInRads);
}

Adesk::Boolean PyGiGeometry::ellipticalArc2(const AcGePoint3d& center, const AcGeVector3d& normal, double majorAxisLength, double minorAxisLength, 
    double startDegreeInRads, double endDegreeInRads, double tiltDegreeInRads, AcGiArcType arcType)
{
    return impObj()->ellipticalArc(center, normal, majorAxisLength, minorAxisLength, startDegreeInRads, endDegreeInRads, tiltDegreeInRads, arcType);
}

Adesk::Boolean PyGiGeometry::worldLine(const AcGePoint3d pnt1, const AcGePoint3d pnt2)
{
    const AcGePoint3d pnts[2] = { pnt1,  pnt2 };
    return impObj()->worldLine(pnts);
}

Adesk::Boolean PyGiGeometry::edge(const boost::python::list& edges) const
{
    AcArray<AcGeCurve2d*> _edges;
    std::vector<PyGeCurve2d> _pyedges = py_list_to_std_vector<PyGeCurve2d>(edges);
    for (auto& edge : _pyedges)
        _edges.append(edge.impObj());
    return impObj()->edge(_edges);
}

Adesk::Boolean PyGiGeometry::draw(PyGiDrawable& drawable)
{
    return impObj()->draw(drawable.impObj());
}

std::string PyGiGeometry::className()
{
    return "AcGiGeometry";
}

PyRxClass PyGiGeometry::desc()
{
    return PyRxClass(AcGiGeometry::desc(), false);
}

AcGiGeometry* PyGiGeometry::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcGiGeometry*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
//PyGiWorldGeometry
void makeAcGiWorldGeometryWrapper()
{
    class_<PyGiWorldGeometry, bases<PyGiGeometry>>("WorldGeometry", boost::python::no_init)
        .def("className", &PyGiGeometry::className).staticmethod("className")
        .def("desc", &PyGiGeometry::desc).staticmethod("desc")
        ;
}

PyGiWorldGeometry::PyGiWorldGeometry(AcGiWorldGeometry* ptr, bool autoDelete)
    : PyGiGeometry(ptr, autoDelete)
{
}

std::string PyGiWorldGeometry::className()
{
    return "AcGiWorldGeometry";
}

PyRxClass PyGiWorldGeometry::desc()
{
    return PyRxClass(AcGiWorldGeometry::desc(), false);
}

AcGiWorldGeometry* PyGiWorldGeometry::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcGiWorldGeometry*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
//AcGiViewportGeometry
void makeAcGiViewportGeometryWrapper()
{
    class_<PyGiViewportGeometry, bases<PyGiGeometry>>("ViewportGeometry", boost::python::no_init)
        .def("className", &PyGiGeometry::className).staticmethod("className")
        .def("desc", &PyGiGeometry::desc).staticmethod("desc")
        ;
}

PyGiViewportGeometry::PyGiViewportGeometry(AcGiViewportGeometry* ptr, bool autoDelete)
    : PyGiGeometry(ptr, autoDelete)
{
}

std::string PyGiViewportGeometry::className()
{
    return "AcGiViewportGeometry";
}

PyRxClass PyGiViewportGeometry::desc()
{
    return PyRxClass(AcGiViewportGeometry::desc(), false);
}

AcGiViewportGeometry* PyGiViewportGeometry::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcGiViewportGeometry*>(m_pyImp.get());
}
