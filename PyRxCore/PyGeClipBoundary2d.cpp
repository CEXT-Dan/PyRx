#include "stdafx.h"
#include "PyGeClipBoundary2d.h"
using namespace boost::python;

//-----------------------------------------------------------------------------------------
//PyGeClipBoundary2d wrapper
void makePyGeClipBoundary2dWrapper()
{
#if !defined(_BRXTARGET270)
    constexpr const std::string_view ctor = "Overloads:\n"
        "- None: Any\n"
        "- cornerA: PyGe.Point2d, cornerB: PyGe.Point2d\n"
        "- clipBoundary: list[PyGe.Point2d]\n";

    constexpr const std::string_view setOverloads = "Overloads:\n"
        "- cornerA: PyGe.Point2d, cornerB: PyGe.Point2d\n"
        "- clipBoundary: list[PyGe.Point2d]\n";

    PyDocString DS("ClipBoundary2d");
    class_<PyGeClipBoundary2d, bases<PyGeEntity2d>>("ClipBoundary2d")
        .def(init<>())
        .def(init<const AcGePoint2d&, const AcGePoint2d&>())
        .def(init<const boost::python::list&>(DS.CTOR(ctor, 11758)))
        .def("set", &PyGeClipBoundary2d::set1)
        .def("set", &PyGeClipBoundary2d::set2, DS.OVRL(setOverloads))
        .def("clipPolygon", &PyGeClipBoundary2d::clipPolygon, DS.ARGS({ "rawVertices: list[PyGe.Point2d]" }, 11761))
        .def("clipPolyline", &PyGeClipBoundary2d::clipPolyline, DS.ARGS({ "rawVertices: list[PyGe.Point2d]" }, 11762))
        .def("cast", &PyGeClipBoundary2d::cast, DS.SARGS({ "otherObject: PyGe.Entity2d" })).staticmethod("cast")
        .def("copycast", &PyGeClipBoundary2d::copycast, DS.SARGS({ "otherObject: PyGe.Entity2d" })).staticmethod("copycast")
        .def("className", &PyGeClipBoundary2d::className, DS.SARGS()).staticmethod("className")
        ;
#endif
}

#if !defined(_BRXTARGET270)
PyGeClipBoundary2d::PyGeClipBoundary2d()
    : PyGeEntity2d(new AcGeClipBoundary2d())
{
}

PyGeClipBoundary2d::PyGeClipBoundary2d(AcGeEntity2d* pEnt)
    : PyGeEntity2d(pEnt)
{
}

PyGeClipBoundary2d::PyGeClipBoundary2d(const AcGePoint2d& cornerA, const AcGePoint2d& cornerB)
    : PyGeEntity2d(new AcGeClipBoundary2d(cornerA, cornerB))
{
}

PyGeClipBoundary2d::PyGeClipBoundary2d(const boost::python::list& clipBoundary)
    : PyGeEntity2d()
{
    PyAutoLockGIL lock;
    auto vec = py_list_to_std_vector<AcGePoint2d>(clipBoundary);
    AcGePoint2dArray _clipBoundary;
    for (const auto& item : vec)
        _clipBoundary.append(item);
    m_imp.reset(new AcGeClipBoundary2d(_clipBoundary));
}

PyGeClipBoundary2d::PyGeClipBoundary2d(const AcGeClipBoundary2d& src)
    : PyGeEntity2d(src.copy())
{
}

void PyGeClipBoundary2d::set1(const AcGePoint2d& cornerA, const AcGePoint2d& cornerB) const
{
    if (impObj()->set(cornerA, cornerB) != AcGe::eOk)
        PyThrowBadEs(eInvalidInput);
}

void PyGeClipBoundary2d::set2(const boost::python::list& clipBoundary) const
{
    if (impObj()->set(PyListToPoint2dArray(clipBoundary)) != AcGe::eOk)
        PyThrowBadEs(eInvalidInput);
}

boost::python::tuple PyGeClipBoundary2d::clipPolygon(const boost::python::list& rawVertices) const
{
    AcGePoint2dArray clippedVertices;
    AcGe::ClipCondition clipCondition;
    AcGeIntArray pClippedSegmentSourceLabel;
    impObj()->clipPolygon(PyListToPoint2dArray(rawVertices), clippedVertices, clipCondition, &pClippedSegmentSourceLabel);
    return boost::python::make_tuple(Point2dArrayToPyList(clippedVertices), clipCondition, Int32ArrayToPyList(pClippedSegmentSourceLabel));
}

boost::python::tuple PyGeClipBoundary2d::clipPolyline(const boost::python::list& rawVertices) const
{
    AcGePoint2dArray clippedVertices;
    AcGe::ClipCondition clipCondition;
    AcGeIntArray pClippedSegmentSourceLabel;
    impObj()->clipPolyline(PyListToPoint2dArray(rawVertices), clippedVertices, clipCondition, &pClippedSegmentSourceLabel);
    return boost::python::make_tuple(Point2dArrayToPyList(clippedVertices), clipCondition, Int32ArrayToPyList(pClippedSegmentSourceLabel));
}

PyGeClipBoundary2d PyGeClipBoundary2d::cast(const PyGeEntity2d& src)
{
    return PyGeEntity2dCast<PyGeClipBoundary2d, AcGeClipBoundary2d>(src);
}

PyGeClipBoundary2d PyGeClipBoundary2d::copycast(const PyGeEntity2d& src)
{
    return PyGeClipBoundary2d(static_cast<AcGeClipBoundary2d*>(src.impObj()->copy()));
}

std::string PyGeClipBoundary2d::className()
{
    return "AcGeClipBoundary2d";
}

AcGeClipBoundary2d* PyGeClipBoundary2d::impObj() const
{
    return static_cast<AcGeClipBoundary2d*>(m_imp.get());
}
#endif

