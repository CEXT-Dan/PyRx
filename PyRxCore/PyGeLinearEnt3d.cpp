#include "stdafx.h"
#include "PyGeLinearEnt3d.h"
#include "PyGePlanarEnt.h"
#include "PyGePlane.h"

using namespace boost::python;
//-----------------------------------------------------------------------------------
//PyGeLinearEnt3d
void makePyGeLinearEnt3dWrapper()
{
    constexpr const std::string_view isOnOverloads = "Overloads:\n"
        "- pnt: PyGe.Point3d\n"
        "- pnt: PyGe.Point3d, tol: PyGe.Tol\n"
        "- param: float\n"
        "- param: float, tol: PyGe.Tol\n"
        "- plane: PyGe.Plane\n"
        "- plane: PyGe.Plane, tol: PyGe.Tol\n";

    constexpr const std::string_view isParallelToOverloads = "Overloads:\n"
        "- line: PyGe.LinearEnt3d\n"
        "- line: PyGe.LinearEnt3d, tol: PyGe.Tol\n"
        "- line: PyGe.PlanarEnt\n"
        "- line: PyGe.PlanarEnt, tol: PyGe.Tol\n";

    constexpr const std::string_view isPerpendicularToOverloads = "Overloads:\n"
        "- line: PyGe.LinearEnt3d\n"
        "- line: PyGe.LinearEnt3d, tol: PyGe.Tol\n"
        "- line: PyGe.PlanarEnt\n"
        "- line: PyGe.PlanarEnt, tol: PyGe.Tol\n";

    PyDocString DS("LinearEnt3d");
    class_<PyGeLinearEnt3d, bases<PyGeCurve3d>>("LinearEnt3d", boost::python::no_init)
        .def("intersectWith", &PyGeLinearEnt3d::intersectWith1)
        .def("intersectWith", &PyGeLinearEnt3d::intersectWith2)
        .def("intersectWith", &PyGeLinearEnt3d::intersectWith3)
        .def("intersectWith", &PyGeLinearEnt3d::intersectWith4, DS.ARGS({ "other: PyGe.LinearEnt3d | PyGe.PlanarEnt", "tol: PyGe.Tol=None" }))
        .def("projIntersectWith", &PyGeLinearEnt3d::projIntersectWith1)
        .def("projIntersectWith", &PyGeLinearEnt3d::projIntersectWith2, DS.ARGS({ "other: PyGe.LinearEnt3d", "projDir: PyGe.Vector3d", "tol: PyGe.Tol=None" }))
        .def("overlap", &PyGeLinearEnt3d::overlap1)
        .def("overlap", &PyGeLinearEnt3d::overlap2, DS.ARGS({ "other: PyGe.LinearEnt3d", "tol: PyGe.Tol=None" }))
        .def("isOn", &PyGeLinearEnt3d::isOn1)
        .def("isOn", &PyGeLinearEnt3d::isOn2)
        .def("isOn", &PyGeLinearEnt3d::isOn3)
        .def("isOn", &PyGeLinearEnt3d::isOn4)
        .def("isOn", &PyGeLinearEnt3d::isOn5)
        .def("isOn", &PyGeLinearEnt3d::isOn6, DS.OVRL(isOnOverloads))
        .def("isParallelTo", &PyGeLinearEnt3d::isParallelTo1)
        .def("isParallelTo", &PyGeLinearEnt3d::isParallelTo2)
        .def("isParallelTo", &PyGeLinearEnt3d::isParallelTo3)
        .def("isParallelTo", &PyGeLinearEnt3d::isParallelTo4, DS.OVRL(isParallelToOverloads))
        .def("isPerpendicularTo", &PyGeLinearEnt3d::isPerpendicularTo1)
        .def("isPerpendicularTo", &PyGeLinearEnt3d::isPerpendicularTo2)
        .def("isPerpendicularTo", &PyGeLinearEnt3d::isPerpendicularTo3)
        .def("isPerpendicularTo", &PyGeLinearEnt3d::isPerpendicularTo4, DS.OVRL(isPerpendicularToOverloads))
        .def("isColinearTo", &PyGeLinearEnt3d::isColinearTo1)
        .def("isColinearTo", &PyGeLinearEnt3d::isColinearTo2, DS.ARGS({ "pt: PyGe.LinearEnt3d" ,"tol: PyGe.Tol=None" }))
        .def("getPerpPlane", &PyGeLinearEnt3d::getPerpPlane, DS.ARGS({ "pt: PyGe.Point3d" }))
        .def("pointOnLine", &PyGeLinearEnt3d::pointOnLine, DS.ARGS())
        .def("direction", &PyGeLinearEnt3d::direction, DS.ARGS())
        .def("getLine", &PyGeLinearEnt3d::getLine, DS.ARGS())
        .def("cast", &PyGeLinearEnt3d::cast, DS.SARGS({ "otherObject: PyGe.Entity3d" })).staticmethod("cast")
        .def("copycast", &PyGeLinearEnt3d::copycast, DS.SARGS({ "otherObject: PyGe.Entity3d" })).staticmethod("copycast")
        .def("className", &PyGeLinearEnt3d::className, DS.SARGS()).staticmethod("className")
        ;
}

PyGeLinearEnt3d::PyGeLinearEnt3d(AcGeEntity3d* pEnt)
    :PyGeCurve3d(pEnt)
{
}

boost::python::tuple PyGeLinearEnt3d::intersectWith1(const PyGeLinearEnt3d& line) const
{
    PyAutoLockGIL lock;
    AcGePoint3d intPt;
    auto res = impObj()->intersectWith(*line.impObj(), intPt);
    return boost::python::make_tuple(res, intPt);
}

boost::python::tuple PyGeLinearEnt3d::intersectWith2(const PyGeLinearEnt3d& line, const AcGeTol& tol) const
{
    PyAutoLockGIL lock;
    AcGePoint3d intPt;
    auto res = impObj()->intersectWith(*line.impObj(), intPt, tol);
    return boost::python::make_tuple(res, intPt);
}

boost::python::tuple PyGeLinearEnt3d::intersectWith3(const PyGePlanarEnt& line) const
{
    PyAutoLockGIL lock;
    AcGePoint3d intPt;
    auto res = impObj()->intersectWith(*line.impObj(), intPt);
    return boost::python::make_tuple(res, intPt);
}

boost::python::tuple PyGeLinearEnt3d::intersectWith4(const PyGePlanarEnt& line, const AcGeTol& tol) const
{
    PyAutoLockGIL lock;
    AcGePoint3d intPt;
    auto res = impObj()->intersectWith(*line.impObj(), intPt, tol);
    return boost::python::make_tuple(res, intPt);
}

boost::python::tuple PyGeLinearEnt3d::projIntersectWith1(const PyGeLinearEnt3d& line, const AcGeVector3d& projDir) const
{
    PyAutoLockGIL lock;
    AcGePoint3d pntOnThisLine;
    AcGePoint3d pntOnOtherLine;
    auto res = impObj()->projIntersectWith(*line.impObj(), projDir, pntOnThisLine, pntOnOtherLine);
    return boost::python::make_tuple(res, pntOnThisLine, pntOnOtherLine);
}

boost::python::tuple PyGeLinearEnt3d::projIntersectWith2(const PyGeLinearEnt3d& line, const AcGeVector3d& projDir, const AcGeTol& tol) const
{
    PyAutoLockGIL lock;
    AcGePoint3d pntOnThisLine;
    AcGePoint3d pntOnOtherLine;
    auto res = impObj()->projIntersectWith(*line.impObj(), projDir, pntOnThisLine, pntOnOtherLine, tol);
    return boost::python::make_tuple(res, pntOnThisLine, pntOnOtherLine);
}

boost::python::tuple PyGeLinearEnt3d::overlap1(const PyGeLinearEnt3d& line) const
{
    PyAutoLockGIL lock;
    AcGeLinearEnt3d* pEnt = nullptr;
    auto res = impObj()->overlap(*line.impObj(), pEnt);
    return boost::python::make_tuple(res, PyGeLinearEnt3d(pEnt));
}

boost::python::tuple PyGeLinearEnt3d::overlap2(const PyGeLinearEnt3d& line, const AcGeTol& tol) const
{
    PyAutoLockGIL lock;
    AcGeLinearEnt3d* pEnt = nullptr;
    auto res = impObj()->overlap(*line.impObj(), pEnt, tol);
    return boost::python::make_tuple(res, PyGeLinearEnt3d(pEnt));
}

boost::python::tuple PyGeLinearEnt3d::isOn1(const AcGePoint3d& pnt) const
{
    PyAutoLockGIL lock;
    double param = 0;
    auto res = impObj()->isOn(pnt, param);
    return boost::python::make_tuple(res, param);
}

boost::python::tuple PyGeLinearEnt3d::isOn2(const AcGePoint3d& pnt, const AcGeTol& tol) const
{
    PyAutoLockGIL lock;
    double param = 0;
    auto res = impObj()->isOn(pnt, param, tol);
    return boost::python::make_tuple(res, param);
}

Adesk::Boolean PyGeLinearEnt3d::isOn3(const double param) const
{
    return impObj()->isOn(param);
}

Adesk::Boolean PyGeLinearEnt3d::isOn4(const double param, const AcGeTol& tol) const
{
    return impObj()->isOn(param, tol);
}

Adesk::Boolean PyGeLinearEnt3d::isOn5(const PyGePlane& plane) const
{
    return impObj()->isOn(*plane.impObj());
}

Adesk::Boolean PyGeLinearEnt3d::isOn6(const PyGePlane& plane, const AcGeTol& tol) const
{
    return impObj()->isOn(*plane.impObj(), tol);
}

Adesk::Boolean PyGeLinearEnt3d::isParallelTo1(const PyGeLinearEnt3d& line) const
{
    return impObj()->isParallelTo(*line.impObj());
}

Adesk::Boolean PyGeLinearEnt3d::isParallelTo2(const PyGeLinearEnt3d& line, const AcGeTol& tol) const
{
    return impObj()->isParallelTo(*line.impObj(), tol);
}

Adesk::Boolean PyGeLinearEnt3d::isParallelTo3(const PyGePlanarEnt& plane) const
{
    return impObj()->isParallelTo(*plane.impObj());
}

Adesk::Boolean PyGeLinearEnt3d::isParallelTo4(const PyGePlanarEnt& plane, const AcGeTol& tol) const
{
    return impObj()->isParallelTo(*plane.impObj(), tol);
}

Adesk::Boolean PyGeLinearEnt3d::isPerpendicularTo1(const PyGeLinearEnt3d& line) const
{
    return impObj()->isPerpendicularTo(*line.impObj());
}

Adesk::Boolean PyGeLinearEnt3d::isPerpendicularTo2(const PyGeLinearEnt3d& line, const AcGeTol& tol) const
{
    return impObj()->isPerpendicularTo(*line.impObj(), tol);
}

Adesk::Boolean PyGeLinearEnt3d::isPerpendicularTo3(const PyGePlanarEnt& plane) const
{
    return impObj()->isPerpendicularTo(*plane.impObj());
}

Adesk::Boolean PyGeLinearEnt3d::isPerpendicularTo4(const PyGePlanarEnt& plane, const AcGeTol& tol) const
{
    return impObj()->isPerpendicularTo(*plane.impObj(), tol);
}

Adesk::Boolean PyGeLinearEnt3d::isColinearTo1(const PyGeLinearEnt3d& line) const
{
    return impObj()->isColinearTo(*line.impObj());
}

Adesk::Boolean PyGeLinearEnt3d::isColinearTo2(const PyGeLinearEnt3d& line, const AcGeTol& tol) const
{
    return impObj()->isColinearTo(*line.impObj(), tol);
}

PyGePlane PyGeLinearEnt3d::getPerpPlane(const AcGePoint3d& pnt) const
{
    AcGePlane plane;
    impObj()->getPerpPlane(pnt, plane);
    return PyGePlane(plane);
}

AcGePoint3d PyGeLinearEnt3d::pointOnLine() const
{
    return impObj()->pointOnLine();
}

AcGeVector3d PyGeLinearEnt3d::direction() const
{
    return impObj()->direction();
}

PyGeLine3d PyGeLinearEnt3d::getLine() const
{
    AcGeLine3d line;
    impObj()->getLine(line);
    return PyGeLine3d(line);
}

PyGeLinearEnt3d PyGeLinearEnt3d::cast(const PyGeEntity3d& src)
{
    if (!src.impObj()->isKindOf(AcGe::EntityId::kLinearEnt3d))
        PyThrowBadEs(Acad::eNotThatKindOfClass);
    return PyGeEntity3dCast<PyGeLinearEnt3d>(src);
}

PyGeLinearEnt3d PyGeLinearEnt3d::copycast(const PyGeEntity3d& src)
{
    if (!src.impObj()->isKindOf(AcGe::EntityId::kLinearEnt3d))
        PyThrowBadEs(Acad::eNotThatKindOfClass);
    return PyGeLinearEnt3d(src.impObj()->copy());
}

std::string PyGeLinearEnt3d::className()
{
    return "AcGeLinearEnt2d";
}

AcGeLinearEnt3d* PyGeLinearEnt3d::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_imp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<AcGeLinearEnt3d*>(m_imp.get());
}

//-----------------------------------------------------------------------------------
//AcGeLine3d
void makePyGeLine3dWrapper()
{
    constexpr const std::string_view ctor = "Overloads:\n"
        "- None: Any\n"
        "- startPoint: PyGe.Point3d, endPoint: PyGe.Point3d\n"
        "- startPoint: PyGe.Point3d, direction: PyGe.Vector3d\n";

    constexpr const std::string_view setOverloads = "Overloads:\n"
        "- startPoint: PyGe.Point3d, endPoint: PyGe.Point3d\n"
        "- startPoint: PyGe.Point3d, direction: PyGe.Vector3d\n";

    PyDocString DS("Line3d");
    class_<PyGeLine3d, bases<PyGeLinearEnt3d>>("Line3d")
        .def(init<>())
        .def(init<const AcGePoint3d&, const AcGeVector3d&>())
        .def(init<const AcGePoint3d&, const AcGePoint3d&>(DS.CTOR(ctor)))
        .add_static_property("kXAxis", PyGeLine3d::kXAxis)
        .add_static_property("kYAxis", PyGeLine3d::kYAxis)
        .add_static_property("kZAxis", PyGeLine3d::kZAxis)
        .def("set", &PyGeLine3d::set1)
        .def("set", &PyGeLine3d::set2, DS.OVRL(setOverloads))
        .def("cast", &PyGeLine3d::cast, DS.SARGS({ "otherObject: PyGe.Entity3d" })).staticmethod("cast")
        .def("copycast", &PyGeLine3d::copycast, DS.SARGS({ "otherObject: PyGe.Entity3d" })).staticmethod("copycast")
        .def("className", &PyGeLine3d::className, DS.SARGS()).staticmethod("className")
        ;
}

PyGeLine3d::PyGeLine3d()
    : PyGeLinearEnt3d(new AcGeLine3d())
{
}

PyGeLine3d::PyGeLine3d(AcGeEntity3d* pEnt)
    : PyGeLinearEnt3d(pEnt)
{
}

PyGeLine3d::PyGeLine3d(const AcGeLine3d& src)
    : PyGeLinearEnt3d(new AcGeLine3d(src))
{
}

PyGeLine3d::PyGeLine3d(const AcGePoint3d& pnt, const AcGeVector3d& vec)
    : PyGeLinearEnt3d(new AcGeLine3d(pnt, vec))
{
}

PyGeLine3d::PyGeLine3d(const AcGePoint3d& pnt1, const AcGePoint3d& pnt2)
    : PyGeLinearEnt3d(new AcGeLine3d(pnt1, pnt2))
{
}

PyGeLine3d PyGeLine3d::kXAxis()
{
    return PyGeLine3d(AcGeLine3d::kXAxis);
}

PyGeLine3d PyGeLine3d::kYAxis()
{
    return PyGeLine3d(AcGeLine3d::kYAxis);
}

PyGeLine3d PyGeLine3d::kZAxis()
{
    return PyGeLine3d(AcGeLine3d::kZAxis);
}

void PyGeLine3d::set1(const AcGePoint3d& pnt, const AcGeVector3d& vec)
{
    impObj()->set(pnt, vec);
}

void PyGeLine3d::set2(const AcGePoint3d& pnt1, const AcGePoint3d& pnt2)
{
    impObj()->set(pnt1, pnt2);
}

PyGeLine3d PyGeLine3d::cast(const PyGeEntity3d& src)
{
    if (!src.impObj()->isKindOf(AcGe::EntityId::kLine3d))
        PyThrowBadEs(Acad::eInvalidInput);
    return PyGeEntity3dCast<PyGeLine3d>(src);
}

PyGeLine3d PyGeLine3d::copycast(const PyGeEntity3d& src)
{
    if (!src.impObj()->isKindOf(AcGe::EntityId::kLine3d))
        PyThrowBadEs(Acad::eInvalidInput);
    return PyGeLine3d(src.impObj()->copy());
}

std::string PyGeLine3d::className()
{
    return "AcGeLine3d";
}

AcGeLine3d* PyGeLine3d::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_imp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<AcGeLine3d*>(m_imp.get());
}

//-----------------------------------------------------------------------------------
//PyGeLineSeg3d
void makePyGeLineSeg3dWrapper()
{
    constexpr const std::string_view ctor = "Overloads:\n"
        "- None: Any\n"
        "- startPoint: PyGe.Point3d, endPoint: PyGe.Point3d\n"
        "- startPoint: PyGe.Point3d, direction: PyGe.Vector3d\n";

    constexpr const std::string_view lengthOverloads = "Overloads:\n"
        "- None: Any\n"
        "- fromParam: float, toParam: float\n"
        "- fromParam: float, toParam: float, tol: float\n";

    constexpr const std::string_view setOverloads = "Overloads:\n"
        "- startPoint: PyGe.Point3d, endPoint: PyGe.Point3d\n"
        "- startPoint: PyGe.Point3d, direction: PyGe.Vector3d\n";

    PyDocString DS("LineSeg3d");
    class_<PyGeLineSeg3d, bases<PyGeLinearEnt3d>>("LineSeg3d")
        .def(init<>())
        .def(init<const AcGePoint3d&, const AcGeVector3d&>())
        .def(init<const AcGePoint3d&, const AcGePoint3d&>(DS.CTOR(ctor)))
        .def("getBisector", &PyGeLineSeg3d::getBisector, DS.ARGS())
        .def("baryComb", &PyGeLineSeg3d::baryComb)
        .def("startPoint", &PyGeLineSeg3d::startPoint, DS.ARGS())
        .def("midPoint", &PyGeLineSeg3d::midPoint, DS.ARGS())
        .def("endPoint", &PyGeLineSeg3d::endPoint, DS.ARGS())
        .def("length", &PyGeLineSeg3d::length1)
        .def("length", &PyGeLineSeg3d::length2)
        .def("length", &PyGeLineSeg3d::length3, DS.OVRL(lengthOverloads))
        .def("set", &PyGeLineSeg3d::set1)
        .def("set", &PyGeLineSeg3d::set2, DS.OVRL(setOverloads))
        .def("cast", &PyGeLineSeg3d::cast).staticmethod("cast")
        .def("copycast", &PyGeLineSeg3d::copycast).staticmethod("copycast")
        .def("className", &PyGeLineSeg3d::className).staticmethod("className")
        ;
}

PyGeLineSeg3d::PyGeLineSeg3d(AcGeEntity3d* pEnt)
    :PyGeLinearEnt3d(pEnt)
{
}

PyGeLineSeg3d::PyGeLineSeg3d()
    : PyGeLinearEnt3d(new AcGeLineSeg3d())
{
}

PyGeLineSeg3d::PyGeLineSeg3d(const AcGeLineSeg3d& src)
    : PyGeLinearEnt3d(new AcGeLineSeg3d(src))
{
}

PyGeLineSeg3d::PyGeLineSeg3d(const AcGePoint3d& pnt, const AcGeVector3d& vec)
    : PyGeLinearEnt3d(new AcGeLineSeg3d(pnt, vec))
{
}

PyGeLineSeg3d::PyGeLineSeg3d(const AcGePoint3d& pnt1, const AcGePoint3d& pnt2)
    : PyGeLinearEnt3d(new AcGeLineSeg3d(pnt1, pnt2))
{
}

PyGePlane PyGeLineSeg3d::getBisector() const
{
    AcGePlane plane;
    impObj()->getBisector(plane);
    return PyGePlane(plane);
}

AcGePoint3d PyGeLineSeg3d::baryComb(double blendCoeff) const
{
    return impObj()->baryComb(blendCoeff);
}

AcGePoint3d PyGeLineSeg3d::startPoint() const
{
    return impObj()->startPoint();
}

AcGePoint3d PyGeLineSeg3d::midPoint() const
{
    return impObj()->midPoint();
}

AcGePoint3d PyGeLineSeg3d::endPoint() const
{
    return impObj()->endPoint();
}

double PyGeLineSeg3d::length1() const
{
    return impObj()->length();
}

double PyGeLineSeg3d::length2(double fromParam, double toParam) const
{
    return impObj()->length(fromParam, toParam);
}

double PyGeLineSeg3d::length3(double fromParam, double toParam, double tol) const
{
    return impObj()->length(fromParam, toParam, tol);
}

void PyGeLineSeg3d::set1(const AcGePoint3d& pnt, const AcGeVector3d& vec)
{
    impObj()->set(pnt, vec);
}

void PyGeLineSeg3d::set2(const AcGePoint3d& pnt1, const AcGePoint3d& pnt2)
{
    impObj()->set(pnt1, pnt2);
}

PyGeLineSeg3d PyGeLineSeg3d::cast(const PyGeEntity3d& src)
{
    if (!src.impObj()->isKindOf(AcGe::EntityId::kLineSeg3d))
        PyThrowBadEs(Acad::eNotThatKindOfClass);
    return PyGeEntity3dCast<PyGeLineSeg3d>(src);
}

PyGeLineSeg3d PyGeLineSeg3d::copycast(const PyGeEntity3d& src)
{
    if (!src.impObj()->isKindOf(AcGe::EntityId::kLineSeg3d))
        PyThrowBadEs(Acad::eNotThatKindOfClass);
    return PyGeLineSeg3d(src.impObj()->copy());
}

std::string PyGeLineSeg3d::className()
{
    return "AcGeLineSeg2d";
}

AcGeLineSeg3d* PyGeLineSeg3d::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_imp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<AcGeLineSeg3d*>(m_imp.get());
}

//-----------------------------------------------------------------------------------
//AcGeRay3d
void makePyGeRay3ddWrapper()
{
    constexpr const std::string_view ctor = "Overloads:\n"
        "- None: Any\n"
        "- startPoint: PyGe.Point3d, endPoint: PyGe.Point3d\n"
        "- startPoint: PyGe.Point3d, direction: PyGe.Vector3d\n";

    constexpr const std::string_view setOverloads = "Overloads:\n"
        "- startPoint: PyGe.Point3d, endPoint: PyGe.Point3d\n"
        "- startPoint: PyGe.Point3d, direction: PyGe.Vector3d\n";

    PyDocString DS("Ray3d");
    class_<PyGeRay3d, bases<PyGeLinearEnt3d>>("Ray3d")
        .def(init<>())
        .def(init<const AcGePoint3d&, const AcGeVector3d&>())
        .def(init<const AcGePoint3d&, const AcGePoint3d&>(DS.CTOR(ctor)))
        .def("set", &PyGeRay3d::set1)
        .def("set", &PyGeRay3d::set2, DS.OVRL(setOverloads))
        .def("cast", &PyGeRay3d::cast, DS.SARGS({ "otherObject: PyGe.Entity3d" })).staticmethod("cast")
        .def("copycast", &PyGeRay3d::copycast, DS.SARGS({ "otherObject: PyGe.Entity3d" })).staticmethod("copycast")
        .def("className", &PyGeRay3d::className, DS.SARGS()).staticmethod("className")
        ;
}

PyGeRay3d::PyGeRay3d()
    :PyGeLinearEnt3d(new AcGeRay3d())
{
}

PyGeRay3d::PyGeRay3d(AcGeEntity3d* pEnt)
    : PyGeLinearEnt3d(pEnt)
{
}

PyGeRay3d::PyGeRay3d(const AcGeRay3d& line)
    : PyGeLinearEnt3d(new AcGeRay3d(line))
{
}

PyGeRay3d::PyGeRay3d(const AcGePoint3d& pnt, const AcGeVector3d& vec)
    : PyGeLinearEnt3d(new AcGeRay3d(pnt, vec))
{
}

PyGeRay3d::PyGeRay3d(const AcGePoint3d& pnt1, const AcGePoint3d& pnt2)
    : PyGeLinearEnt3d(new AcGeRay3d(pnt1, pnt2))
{
}

void PyGeRay3d::set1(const AcGePoint3d& pnt, const AcGeVector3d& vec)
{
    impObj()->set(pnt, vec);
}

void PyGeRay3d::set2(const AcGePoint3d& pnt1, const AcGePoint3d& pnt2)
{
    impObj()->set(pnt1, pnt2);
}

PyGeRay3d PyGeRay3d::cast(const PyGeEntity3d& src)
{
    if (!src.impObj()->isKindOf(AcGe::EntityId::kRay3d))
        PyThrowBadEs(Acad::eNotThatKindOfClass);
    return PyGeEntity3dCast<PyGeRay3d>(src);
}

PyGeRay3d PyGeRay3d::copycast(const PyGeEntity3d& src)
{
    if (!src.impObj()->isKindOf(AcGe::EntityId::kRay3d))
        PyThrowBadEs(Acad::eNotThatKindOfClass);
    return PyGeRay3d(src.impObj()->copy());
}

std::string PyGeRay3d::className()
{
    return "AcGeRay3d";
}

AcGeRay3d* PyGeRay3d::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_imp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<AcGeRay3d*>(m_imp.get());
}
