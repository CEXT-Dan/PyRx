#include "stdafx.h"
#include "PyGeLinearEnt2d.h"

using namespace boost::python;
//-----------------------------------------------------------------------------------------
//AcGeLinearEnt2d wrapper
void makePyGeLinearEnt2dWrapper()
{
    PyDocString DS("LinearEnt2d");
    class_<PyGeLinearEnt2d, bases<PyGeCurve2d>>("LinearEnt2d", boost::python::no_init)
        .def("intersectWith", &PyGeLinearEnt2d::intersectWith1)
        .def("intersectWith", &PyGeLinearEnt2d::intersectWith2, DS.ARGS({ "other: PyGe.LinearEnt2d","tol: PyGe.Tol = ..." }))
        .def("overlap", &PyGeLinearEnt2d::overlap1)
        .def("overlap", &PyGeLinearEnt2d::overlap2, DS.ARGS({ "other: PyGe.LinearEnt2d","tol: PyGe.Tol = ..." }))
        .def("isParallelTo", &PyGeLinearEnt2d::isParallelTo1)
        .def("isParallelTo", &PyGeLinearEnt2d::isParallelTo2, DS.ARGS({ "other: PyGe.LinearEnt2d","tol: PyGe.Tol = ..." }))
        .def("isPerpendicularTo", &PyGeLinearEnt2d::isPerpendicularTo1)
        .def("isPerpendicularTo", &PyGeLinearEnt2d::isPerpendicularTo2, DS.ARGS({ "other: PyGe.LinearEnt2d","tol: PyGe.Tol = ..." }))
        .def("isColinearTo", &PyGeLinearEnt2d::isColinearTo1)
        .def("isColinearTo", &PyGeLinearEnt2d::isColinearTo2, DS.ARGS({ "other: PyGe.LinearEnt2d","tol: PyGe.Tol = ..." }))
        .def("getPerpLine", &PyGeLinearEnt2d::getPerpLine, DS.ARGS({ "pt: PyGe.Point2d" }))
        .def("getLine", &PyGeLinearEnt2d::getLine, DS.ARGS())
        .def("pointOnLine", &PyGeLinearEnt2d::pointOnLine, DS.ARGS())
        .def("direction", &PyGeLinearEnt2d::direction, DS.ARGS())
        .def("cast", &PyGeLinearEnt2d::cast, DS.SARGS({ "otherObject: PyGe.Entity2d" })).staticmethod("cast")
        .def("copycast", &PyGeLinearEnt2d::copycast, DS.SARGS({ "otherObject: PyGe.Entity2d" })).staticmethod("copycast")
        .def("className", &PyGeLinearEnt2d::className, DS.SARGS()).staticmethod("className")
        ;
}

PyGeLinearEnt2d::PyGeLinearEnt2d(AcGeEntity2d* pEnt)
    : PyGeCurve2d(pEnt)
{
}

boost::python::tuple PyGeLinearEnt2d::intersectWith1(const PyGeLinearEnt2d& line) const
{
    PyAutoLockGIL lock;
    AcGePoint2d p1;
    bool flag = impObj()->intersectWith(*line.impObj(), p1);
    return make_tuple(flag, p1);
}

boost::python::tuple PyGeLinearEnt2d::intersectWith2(const PyGeLinearEnt2d& line, const AcGeTol& tol) const
{
    PyAutoLockGIL lock;
    AcGePoint2d p1;
    bool flag = impObj()->intersectWith(*line.impObj(), p1, tol);
    return make_tuple(flag, p1);
}

boost::python::tuple PyGeLinearEnt2d::overlap1(const PyGeLinearEnt2d& line) const
{
    PyAutoLockGIL lock;
    AcGeLinearEnt2d* poverlap = nullptr;
    bool flag = impObj()->overlap(*line.impObj(), poverlap);
    return make_tuple(flag, PyGeLinearEnt2d(poverlap));
}

boost::python::tuple PyGeLinearEnt2d::overlap2(const PyGeLinearEnt2d& line, const AcGeTol& tol) const
{
    PyAutoLockGIL lock;
    AcGeLinearEnt2d* poverlap = nullptr;
    bool flag = impObj()->overlap(*line.impObj(), poverlap, tol);
    return make_tuple(flag, PyGeLinearEnt2d(poverlap));
}

Adesk::Boolean PyGeLinearEnt2d::isParallelTo1(const PyGeLinearEnt2d& line) const
{
    return impObj()->isParallelTo(*line.impObj());
}

Adesk::Boolean PyGeLinearEnt2d::isParallelTo2(const PyGeLinearEnt2d& line, const AcGeTol& tol) const
{
    return impObj()->isParallelTo(*line.impObj(), tol);
}

Adesk::Boolean PyGeLinearEnt2d::isPerpendicularTo1(const PyGeLinearEnt2d& line) const
{
    return impObj()->isPerpendicularTo(*line.impObj());
}

Adesk::Boolean PyGeLinearEnt2d::isPerpendicularTo2(const PyGeLinearEnt2d& line, const AcGeTol& tol) const
{
    return impObj()->isPerpendicularTo(*line.impObj(), tol);
}

Adesk::Boolean PyGeLinearEnt2d::isColinearTo1(const PyGeLinearEnt2d& line) const
{
    return impObj()->isColinearTo(*line.impObj());
}

Adesk::Boolean PyGeLinearEnt2d::isColinearTo2(const PyGeLinearEnt2d& line, const AcGeTol& tol) const
{
    return impObj()->isColinearTo(*line.impObj(), tol);
}

PyGeLine2d PyGeLinearEnt2d::getPerpLine(const AcGePoint2d& pnt) const
{
    AcGeLine2d perpLine;
    impObj()->getPerpLine(pnt, perpLine);
    return PyGeLine2d(perpLine);
}

PyGeLine2d PyGeLinearEnt2d::getLine() const
{
    AcGeLine2d perpLine;
    impObj()->getLine(perpLine);
    return PyGeLine2d(perpLine);
}

AcGePoint2d PyGeLinearEnt2d::pointOnLine() const
{
    return impObj()->pointOnLine();
}

AcGeVector2d PyGeLinearEnt2d::direction() const
{
    return impObj()->direction();
}

PyGeLinearEnt2d PyGeLinearEnt2d::cast(const PyGeEntity2d& src)
{
    return PyGeEntity2dCast<PyGeLinearEnt2d, AcGeLinearEnt2d>(src);
}

PyGeLinearEnt2d PyGeLinearEnt2d::copycast(const PyGeEntity2d& src)
{
    return PyGeLinearEnt2d(static_cast<AcGeLinearEnt2d*>(src.impObj()->copy()));
}

std::string PyGeLinearEnt2d::className()
{
    return "AcGeLinearEnt2d";
}

AcGeLinearEnt2d* PyGeLinearEnt2d::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_imp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcGeLinearEnt2d*>(m_imp.get());
}

//-----------------------------------------------------------------------------------------
//AcGeLine2d  wrapper
void makePyGeLine2dWrapper()
{
    constexpr const std::string_view ctor = "Overloads:\n"
        "- None: Any\n"
        "- start: PyGe.Point3d, direction: PyGe.Vector2d\n"
        "- start: PyGe.Point3d, end: PyGe.Point3d\n";

    constexpr const std::string_view setOverloads = "Overloads:\n"
        "- start: PyGe.Point3d, direction: PyGe.Vector2d\n"
        "- start: PyGe.Point3d, end: PyGe.Point3d\n";

    PyDocString DS("Line2d");
    class_<PyGeLine2d, bases<PyGeLinearEnt2d>>("Line2d")
        .def(init<>())
        .def(init<const AcGePoint2d&, const AcGeVector2d&>())
        .def(init<const AcGePoint2d&, const AcGePoint2d&>(DS.CTOR(ctor, 12239)))
        .add_static_property("kXAxis", PyGeLine2d::kXAxis)
        .add_static_property("kYAxis", PyGeLine2d::kYAxis)
        .def("set", &PyGeLine2d::set1)
        .def("set", &PyGeLine2d::set2, DS.OVRL(setOverloads))
        .def("cast", &PyGeLine2d::cast, DS.SARGS({ "otherObject: PyGe.Entity2d" })).staticmethod("cast")
        .def("copycast", &PyGeLine2d::copycast, DS.SARGS({ "otherObject: PyGe.Entity2d" })).staticmethod("copycast")
        .def("className", &PyGeLine2d::className, DS.SARGS()).staticmethod("className")
        ;
}

PyGeLine2d::PyGeLine2d()
    : PyGeLinearEnt2d(new AcGeLine2d())
{
}

PyGeLine2d::PyGeLine2d(AcGeEntity2d* pEnt)
    : PyGeLinearEnt2d(pEnt)
{
}

PyGeLine2d::PyGeLine2d(const AcGeLine2d& pEnt)
    : PyGeLinearEnt2d(new AcGeLine2d(pEnt))
{
}

PyGeLine2d::PyGeLine2d(const AcGePoint2d& pnt, const AcGeVector2d& vec)
    : PyGeLinearEnt2d(new AcGeLine2d(pnt, vec))
{
}

PyGeLine2d::PyGeLine2d(const AcGePoint2d& pnt1, const AcGePoint2d& pnt2)
    : PyGeLinearEnt2d(new AcGeLine2d(pnt1, pnt2))
{
}

PyGeLine2d PyGeLine2d::kXAxis()
{
    return PyGeLine2d(AcGeLine2d::kXAxis);
}

PyGeLine2d PyGeLine2d::kYAxis()
{
    return PyGeLine2d(AcGeLine2d::kYAxis);
}

void PyGeLine2d::set1(const AcGePoint2d& pnt, const AcGeVector2d& vec) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    impObj()->set(pnt, vec);
#endif
}

void PyGeLine2d::set2(const AcGePoint2d& pnt1, const AcGePoint2d& pnt2) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    impObj()->set(pnt1, pnt2);
#endif
}

PyGeLine2d PyGeLine2d::cast(const PyGeEntity2d& src)
{
    return PyGeEntity2dCast<PyGeLine2d, AcGeLine2d>(src);
}

PyGeLine2d PyGeLine2d::copycast(const PyGeEntity2d& src)
{
    return PyGeLine2d(static_cast<AcGeLine2d*>(src.impObj()->copy()));
}

std::string PyGeLine2d::className()
{
    return "AcGeLine2d";
}

AcGeLine2d* PyGeLine2d::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_imp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcGeLine2d*>(m_imp.get());
}

//-----------------------------------------------------------------------------------------
//AcGeLine2d  wrapper
void makePyGeLineSeg2dWrapper()
{
    constexpr const std::string_view ctor = "Overloads:\n"
        "- None: Any\n"
        "- start: PyGe.Point3d, direction: PyGe.Vector2d\n"
        "- start: PyGe.Point3d, end: PyGe.Point3d\n";

    constexpr const std::string_view setOverloads = "Overloads:\n"
        "- start: PyGe.Point3d, direction: PyGe.Vector2d\n"
        "- start: PyGe.Point3d, end: PyGe.Point3d\n"
        "- curve1: PyGe.Curve2d, curve2: PyGe.Curve2d\n"
        "- curve1: PyGe.Curve2d, pnt: PyGe.Point3d\n";

    constexpr const std::string_view lengthOverloads = "Overloads:\n"
        "- None: Any\n"
        "- fromParam: float, toParam: float\n"
        "- fromParam: float, toParam: float, tol: float\n";

    PyDocString DS("LineSeg2d");
    class_<PyGeLineSeg2d, bases<PyGeLinearEnt2d>>("LineSeg2d")
        .def(init<>())
        .def(init<const AcGePoint2d&, const AcGeVector2d&>())
        .def(init<const AcGePoint2d&, const AcGePoint2d&>(DS.CTOR(ctor, 12278)))
        .def("set", &PyGeLineSeg2d::set1)
        .def("set", &PyGeLineSeg2d::set2)
        .def("set", &PyGeLineSeg2d::set3)
        .def("set", &PyGeLineSeg2d::set4, DS.OVRL(setOverloads))
        .def("getBisector", &PyGeLineSeg2d::getBisector, DS.ARGS())
        .def("baryComb", &PyGeLineSeg2d::baryComb, DS.ARGS({ "blendCoeff: float" }))
        .def("startPoint", &PyGeLineSeg2d::startPoint, DS.ARGS())
        .def("midPoint", &PyGeLineSeg2d::midPoint, DS.ARGS())
        .def("endPoint", &PyGeLineSeg2d::endPoint, DS.ARGS())
        .def("length", &PyGeLineSeg2d::length1)
        .def("length", &PyGeLineSeg2d::length2)
        .def("length", &PyGeLineSeg2d::length3, DS.OVRL(lengthOverloads))
        .def("cast", &PyGeLineSeg2d::cast, DS.SARGS({ "otherObject: PyGe.Entity2d" })).staticmethod("cast")
        .def("copycast", &PyGeLineSeg2d::copycast, DS.SARGS({ "otherObject: PyGe.Entity2d" })).staticmethod("copycast")
        .def("className", &PyGeLineSeg2d::className, DS.SARGS()).staticmethod("className")
        ;
}

PyGeLineSeg2d::PyGeLineSeg2d()
    : PyGeLinearEnt2d(new AcGeLineSeg2d())
{
}

PyGeLineSeg2d::PyGeLineSeg2d(AcGeEntity2d* pEnt)
    : PyGeLinearEnt2d(pEnt)
{
}

PyGeLineSeg2d::PyGeLineSeg2d(const AcGeLineSeg2d& src)
    : PyGeLinearEnt2d(new AcGeLineSeg2d(src))
{
}

PyGeLineSeg2d::PyGeLineSeg2d(const AcGePoint2d& pnt1, const AcGePoint2d& pnt2)
    : PyGeLinearEnt2d(new AcGeLineSeg2d(pnt1, pnt2))
{
}

PyGeLineSeg2d::PyGeLineSeg2d(const AcGePoint2d& pnt, const AcGeVector2d& vec)
    : PyGeLinearEnt2d(new AcGeLineSeg2d(pnt, vec))
{
}

void PyGeLineSeg2d::set1(const AcGePoint2d& pnt, const AcGeVector2d& vec) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    impObj()->set(pnt, vec);
#endif
}

void PyGeLineSeg2d::set2(const AcGePoint2d& pnt1, const AcGePoint2d& pnt2) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    impObj()->set(pnt1, pnt2);
#endif
}

void PyGeLineSeg2d::set3(const PyGeCurve2d& curve1, const PyGeCurve2d& curve2) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    double param1, param2;
    Adesk::Boolean success;
    impObj()->set(*curve1.impObj(), *curve2.impObj(), param1, param2, success);
    if (!success)
        throw PyErrorStatusException(eInvalidInput);
#endif
}

void PyGeLineSeg2d::set4(const PyGeCurve2d& curve, const AcGePoint2d& point) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    double param1;
    Adesk::Boolean success;
    impObj()->set(*curve.impObj(), point, param1, success);
    if (!success)
        throw PyErrorStatusException(eInvalidInput);
#endif
}

PyGeLine2d PyGeLineSeg2d::getBisector() const
{
    AcGeLine2d line;
    impObj()->getBisector(line);
    return PyGeLine2d(line);
}

AcGePoint2d PyGeLineSeg2d::baryComb(double blendCoeff) const
{
    return impObj()->baryComb(blendCoeff);
}

AcGePoint2d PyGeLineSeg2d::startPoint() const
{
    return impObj()->startPoint();
}

AcGePoint2d PyGeLineSeg2d::midPoint() const
{
    return impObj()->midPoint();
}

AcGePoint2d PyGeLineSeg2d::endPoint() const
{
    return impObj()->endPoint();
}

double PyGeLineSeg2d::length1() const
{
    return impObj()->length();
}

double PyGeLineSeg2d::length2(double fromParam, double toParam) const
{
    return impObj()->length(fromParam, toParam);
}

double PyGeLineSeg2d::length3(double fromParam, double toParam, double tol) const
{
    return impObj()->length(fromParam, toParam, tol);
}

PyGeLineSeg2d PyGeLineSeg2d::cast(const PyGeEntity2d& src)
{
    return PyGeEntity2dCast<PyGeLineSeg2d, AcGeLineSeg2d>(src);
}

PyGeLineSeg2d PyGeLineSeg2d::copycast(const PyGeEntity2d& src)
{
    return PyGeLineSeg2d(static_cast<AcGeLineSeg2d*>(src.impObj()->copy()));
}

std::string PyGeLineSeg2d::className()
{
    return "AcGeLineSeg2d";
}

AcGeLineSeg2d* PyGeLineSeg2d::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_imp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcGeLineSeg2d*>(m_imp.get());
}

//-----------------------------------------------------------------------------------------
//AcGeRay2d  wrapper
void makePyGeRay2dWrapper()
{
    constexpr const std::string_view ctor = "Overloads:\n"
        "- None: Any\n"
        "- start: PyGe.Point3d, direction: PyGe.Vector2d\n"
        "- start: PyGe.Point3d, end: PyGe.Point3d\n";

    constexpr const std::string_view setOverloads = "Overloads:\n"
        "- start: PyGe.Point3d, direction: PyGe.Vector2d\n"
        "- start: PyGe.Point3d, end: PyGe.Point3d\n";

    PyDocString DS("Ray2d");
    class_<PyGeRay2d, bases<PyGeLinearEnt2d>>("Ray2d")
        .def(init<>())
        .def(init<const AcGePoint2d&, const AcGeVector2d&>())
        .def(init<const AcGePoint2d&, const AcGePoint2d&>(DS.CTOR(ctor, 12667)))
        .def("set", &PyGeRay2d::set1)
        .def("set", &PyGeRay2d::set2, DS.OVRL(setOverloads))
        .def("cast", &PyGeRay2d::cast, DS.SARGS({ "otherObject: PyGe.Entity2d" })).staticmethod("cast")
        .def("copycast", &PyGeRay2d::copycast, DS.SARGS({ "otherObject: PyGe.Entity2d" })).staticmethod("copycast")
        .def("className", &PyGeRay2d::className, DS.SARGS()).staticmethod("className")
        ;
}

PyGeRay2d::PyGeRay2d()
    : PyGeLinearEnt2d(new AcGeRay2d())
{
}

PyGeRay2d::PyGeRay2d(AcGeEntity2d* pEnt)
    : PyGeLinearEnt2d(pEnt)
{
}

PyGeRay2d::PyGeRay2d(const AcGeRay2d& line)
    : PyGeLinearEnt2d(new AcGeRay2d(line))
{
}

PyGeRay2d::PyGeRay2d(const AcGePoint2d& pnt, const AcGeVector2d& vec)
    : PyGeLinearEnt2d(new AcGeRay2d(pnt, vec))
{
}

PyGeRay2d::PyGeRay2d(const AcGePoint2d& pnt1, const AcGePoint2d& pnt2)
    : PyGeLinearEnt2d(new AcGeRay2d(pnt1, pnt2))
{
}

void PyGeRay2d::set1(const AcGePoint2d& pnt, const AcGeVector2d& vec) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    impObj()->set(pnt, vec);
#endif
}

void PyGeRay2d::set2(const AcGePoint2d& pnt1, const AcGePoint2d& pnt2) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    impObj()->set(pnt1, pnt2);
#endif
}

PyGeRay2d PyGeRay2d::cast(const PyGeEntity2d& src)
{
    return PyGeEntity2dCast<PyGeRay2d, AcGeRay2d>(src);
}

PyGeRay2d PyGeRay2d::copycast(const PyGeEntity2d& src)
{
    return PyGeRay2d(static_cast<AcGeRay2d*>(src.impObj()->copy()));
}

std::string PyGeRay2d::className()
{
    return "AcGeRay2d";
}

AcGeRay2d* PyGeRay2d::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_imp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcGeRay2d*>(m_imp.get());
}
