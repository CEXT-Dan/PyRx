#include "stdafx.h"
#include "PyGeCurveCurveInt2d.h"
#include "PyGeInterval.h"
#include "PyGePointEnt2d.h"

using namespace boost::python;

//-----------------------------------------------------------------------------------------
//PyGeCurveCurveInt2d wrapper

//NOTE curve1, curve2 are not overloads
void makePyGeCurveCurveInt2dWrapper()
{
#if !defined(_BRXTARGET260)
    constexpr const std::string_view ctor = "Overloads:\n"
        "- None: Any\n"
        "- curve1: PyGe.Curve2d, curve2: PyGe.Curve2d\n"
        "- curve1: PyGe.Curve2d, curve2: PyGe.Curve2d, tol: PyGe.Tol\n"
        "- curve1: PyGe.Curve2d, curve2: PyGe.Curve2d, range1: PyGe.Interval, range2: PyGe.Interval\n"
        "- curve1: PyGe.Curve2d, curve2: PyGe.Curve2d, range1: PyGe.Interval, range2: PyGe.Interval, tol: PyGe.Tol\n";

    PyDocString DS("CurveCurveInt2d");
    class_<PyGeCurveCurveInt2d, bases<PyGeEntity2d>>("CurveCurveInt2d")
        .def(init<>())
        .def(init<const PyGeCurve2d&, const PyGeCurve2d&>())
        .def(init<const PyGeCurve2d&, const PyGeCurve2d&, const AcGeTol&>())
        .def(init<const PyGeCurve2d&, const PyGeCurve2d&, const PyGeInterval&, const PyGeInterval&>())
        .def(init<const PyGeCurve2d&, const PyGeCurve2d&, const PyGeInterval&, const PyGeInterval&, const AcGeTol&>(DS.CTOR(ctor, 11889)))
        .def("curve1", &PyGeCurveCurveInt2d::curve1, DS.ARGS())//not overload
        .def("curve2", &PyGeCurveCurveInt2d::curve2, DS.ARGS())//not overload
        .def("getIntRanges", &PyGeCurveCurveInt2d::getIntRanges, DS.ARGS())
        .def("tolerance", &PyGeCurveCurveInt2d::tolerance, DS.ARGS())
        .def("numIntPoints", &PyGeCurveCurveInt2d::numIntPoints, DS.ARGS())
        .def("intPoint", &PyGeCurveCurveInt2d::intPoint, DS.ARGS({ "intNum: int" }))
        .def("getIntParams", &PyGeCurveCurveInt2d::getIntParams, DS.ARGS({ "intNum: int" }))
        .def("getPointOnCurve1", &PyGeCurveCurveInt2d::getPointOnCurve1, DS.ARGS({ "intNum: int" }))
        .def("getPointOnCurve2", &PyGeCurveCurveInt2d::getPointOnCurve2, DS.ARGS({ "intNum: int" }))
        .def("getIntConfigs", &PyGeCurveCurveInt2d::getIntConfigs, DS.ARGS({ "intNum: int" }))
        .def("isTangential", &PyGeCurveCurveInt2d::isTangential, DS.ARGS({ "intNum: int" }))
        .def("isTransversal", &PyGeCurveCurveInt2d::isTransversal, DS.ARGS({ "intNum: int" }))
        .def("intPointTol", &PyGeCurveCurveInt2d::intPointTol, DS.ARGS({ "intNum: int" }))
        .def("overlapCount", &PyGeCurveCurveInt2d::overlapCount, DS.ARGS())
        .def("overlapDirection", &PyGeCurveCurveInt2d::overlapDirection, DS.ARGS())
        .def("getOverlapRanges", &PyGeCurveCurveInt2d::getOverlapRanges, DS.ARGS({ "intNum: int" }))
        .def("changeCurveOrder", &PyGeCurveCurveInt2d::changeCurveOrder, DS.ARGS())
        .def("orderWrt1", &PyGeCurveCurveInt2d::orderWrt1, DS.ARGS())//not overload
        .def("orderWrt2", &PyGeCurveCurveInt2d::orderWrt2, DS.ARGS())//not overload
        .def("cast", &PyGeCurveCurveInt2d::cast, DS.SARGS({ "otherObject: PyGe.Entity2d" })).staticmethod("cast")
        .def("copycast", &PyGeCurveCurveInt2d::copycast, DS.SARGS({ "otherObject: PyGe.Entity2d" })).staticmethod("copycast")
        .def("className", &PyGeCurveCurveInt2d::className, DS.SARGS()).staticmethod("className")
        ;
#endif
}

#if !defined(_BRXTARGET260)
PyGeCurveCurveInt2d::PyGeCurveCurveInt2d()
    : PyGeEntity2d(new AcGeCurveCurveInt2d())
{
}

PyGeCurveCurveInt2d::PyGeCurveCurveInt2d(const PyGeCurve2d& curve1, const PyGeCurve2d& curve2)
    : PyGeEntity2d(new AcGeCurveCurveInt2d(*curve1.impObj(), *curve2.impObj()))
{
}

PyGeCurveCurveInt2d::PyGeCurveCurveInt2d(const PyGeCurve2d& curve1, const PyGeCurve2d& curve2, const AcGeTol& tol)
    : PyGeEntity2d(new AcGeCurveCurveInt2d(*curve1.impObj(), *curve2.impObj(), tol))
{
}

PyGeCurveCurveInt2d::PyGeCurveCurveInt2d(const PyGeCurve2d& curve1, const PyGeCurve2d& curve2, const PyGeInterval& range1, const PyGeInterval& range2)
    : PyGeEntity2d(new AcGeCurveCurveInt2d(*curve1.impObj(), *curve2.impObj(), range1.imp, range2.imp))
{
}

PyGeCurveCurveInt2d::PyGeCurveCurveInt2d(const PyGeCurve2d& curve1, const PyGeCurve2d& curve2, const PyGeInterval& range1, const PyGeInterval& range2, const AcGeTol& tol)
    : PyGeEntity2d(new AcGeCurveCurveInt2d(*curve1.impObj(), *curve2.impObj(), range1.imp, range2.imp, tol))
{
}

PyGeCurveCurveInt2d::PyGeCurveCurveInt2d(const AcGeCurveCurveInt2d& src)
    : PyGeEntity2d(new AcGeCurveCurveInt2d(src))
{
}

PyGeCurveCurveInt2d::PyGeCurveCurveInt2d(AcGeEntity2d* pEnt)
    : PyGeEntity2d(pEnt)
{
}

PyGeCurve2d PyGeCurveCurveInt2d::curve1() const
{
    return PyGeCurve2d(impObj()->curve1());
}

PyGeCurve2d PyGeCurveCurveInt2d::curve2() const
{
    return PyGeCurve2d(impObj()->curve2());
}

boost::python::tuple PyGeCurveCurveInt2d::getIntRanges() const
{
    PyAutoLockGIL lock;
    PyGeInterval range1;
    PyGeInterval range2;
    impObj()->getIntRanges(range1.imp, range2.imp);
    return boost::python::make_tuple(range1, range2);
}

AcGeTol PyGeCurveCurveInt2d::tolerance() const
{
    return impObj()->tolerance();
}

int PyGeCurveCurveInt2d::numIntPoints() const
{
    return impObj()->numIntPoints();
}

AcGePoint2d PyGeCurveCurveInt2d::intPoint(int intNum) const
{
    return impObj()->intPoint(intNum);
}

boost::python::tuple  PyGeCurveCurveInt2d::getIntParams(int intNum) const
{
    PyAutoLockGIL lock;
    double param1 = 0;
    double param2 = 0;
    impObj()->getIntParams(intNum, param1, param2);
    return boost::python::make_tuple(param1, param2);
}

PyGePointOnCurve2d PyGeCurveCurveInt2d::getPointOnCurve1(int intNum) const
{
    AcGePointOnCurve2d pnt;
    impObj()->getPointOnCurve1(intNum, pnt);
    return PyGePointOnCurve2d(pnt);
}

PyGePointOnCurve2d PyGeCurveCurveInt2d::getPointOnCurve2(int intNum) const
{
    AcGePointOnCurve2d pnt;
    impObj()->getPointOnCurve2(intNum, pnt);
    return PyGePointOnCurve2d(pnt);
}

boost::python::tuple PyGeCurveCurveInt2d::getIntConfigs(int intNum) const
{
    PyAutoLockGIL lock;
    AcGe::AcGeXConfig config1wrt2;
    AcGe::AcGeXConfig config2wrt1;
    impObj()->getIntConfigs(intNum, config1wrt2, config2wrt1);
    return boost::python::make_tuple(config1wrt2, config2wrt1);
}

Adesk::Boolean PyGeCurveCurveInt2d::isTangential(int intNum) const
{
    return impObj()->isTangential(intNum);
}

Adesk::Boolean PyGeCurveCurveInt2d::isTransversal(int intNum) const
{
    return impObj()->isTransversal(intNum);
}

double PyGeCurveCurveInt2d::intPointTol(int intNum) const
{
    return impObj()->intPointTol(intNum);
}

int PyGeCurveCurveInt2d::overlapCount() const
{
    return impObj()->overlapCount();
}

Adesk::Boolean PyGeCurveCurveInt2d::overlapDirection() const
{
    return impObj()->overlapDirection();
}

boost::python::tuple PyGeCurveCurveInt2d::getOverlapRanges(int overlapNum) const
{
    PyAutoLockGIL lock;
    PyGeInterval range1;
    PyGeInterval range2;
    impObj()->getOverlapRanges(overlapNum, range1.imp, range2.imp);
    return boost::python::make_tuple(range1, range2);
}

void PyGeCurveCurveInt2d::changeCurveOrder() const
{
    return impObj()->changeCurveOrder();
}

PyGeCurveCurveInt2d PyGeCurveCurveInt2d::orderWrt1() const
{
    return PyGeCurveCurveInt2d(impObj()->orderWrt1());
}

PyGeCurveCurveInt2d PyGeCurveCurveInt2d::orderWrt2() const
{
    return PyGeCurveCurveInt2d(impObj()->orderWrt2());
}

PyGeCurveCurveInt2d PyGeCurveCurveInt2d::cast(const PyGeEntity2d& src)
{
    return PyGeEntity2dCast<PyGeCurveCurveInt2d, AcGeCurveCurveInt2d>(src);
}

PyGeCurveCurveInt2d PyGeCurveCurveInt2d::copycast(const PyGeEntity2d& src)
{
    return PyGeCurveCurveInt2d(static_cast<AcGeCurveCurveInt2d*>(src.impObj()->copy()));
}

std::string PyGeCurveCurveInt2d::className()
{
    return "AcGeCurveCurveInt2d";
}

AcGeCurveCurveInt2d* PyGeCurveCurveInt2d::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_imp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcGeCurveCurveInt2d*>(m_imp.get());
}
#endif