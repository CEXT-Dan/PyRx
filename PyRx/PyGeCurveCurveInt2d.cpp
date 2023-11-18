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
    class_<PyGeCurveCurveInt2d, bases<PyGeEntity2d>>("CurveCurveInt2d")
        .def(init<>())
        .def(init<const PyGeCurve2d&, const PyGeCurve2d&>())
        .def(init<const PyGeCurve2d&, const PyGeCurve2d&, const AcGeTol&>())
        .def(init<const PyGeCurve2d&, const PyGeCurve2d&, const PyGeInterval&, const PyGeInterval&>())
        .def(init<const PyGeCurve2d&, const PyGeCurve2d&, const PyGeInterval&, const PyGeInterval&, const AcGeTol&>())
        .def("curve1", &PyGeCurveCurveInt2d::curve1)//not overload
        .def("curve2", &PyGeCurveCurveInt2d::curve2)//not overload
        .def("getIntRanges", &PyGeCurveCurveInt2d::getIntRanges)
        .def("tolerance", &PyGeCurveCurveInt2d::tolerance)
        .def("numIntPoints", &PyGeCurveCurveInt2d::numIntPoints)
        .def("intPoint", &PyGeCurveCurveInt2d::intPoint)
        .def("getIntParams", &PyGeCurveCurveInt2d::getIntParams)
        .def("getPointOnCurve1", &PyGeCurveCurveInt2d::getPointOnCurve1)
        .def("getPointOnCurve2", &PyGeCurveCurveInt2d::getPointOnCurve2)
        .def("getIntConfigs", &PyGeCurveCurveInt2d::getIntConfigs)
        .def("isTangential", &PyGeCurveCurveInt2d::isTangential)
        .def("isTransversal", &PyGeCurveCurveInt2d::isTransversal)
        .def("intPointTol", &PyGeCurveCurveInt2d::intPointTol)
        .def("overlapCount", &PyGeCurveCurveInt2d::overlapCount)
        .def("overlapDirection", &PyGeCurveCurveInt2d::overlapDirection)
        .def("getOverlapRanges", &PyGeCurveCurveInt2d::getOverlapRanges)
        .def("changeCurveOrder", &PyGeCurveCurveInt2d::changeCurveOrder)
        .def("orderWrt1", &PyGeCurveCurveInt2d::orderWrt1)//not overload
        .def("orderWrt2", &PyGeCurveCurveInt2d::orderWrt2)//not overload
        .def("cast", &PyGeCurveCurveInt2d::cast).staticmethod("cast")
        .def("copycast", &PyGeCurveCurveInt2d::copycast).staticmethod("copycast")
        .def("className", &PyGeCurveCurveInt2d::className).staticmethod("className")
        ;
}

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
    return  impObj()->numIntPoints();
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

void PyGeCurveCurveInt2d::changeCurveOrder()
{
    return impObj()->changeCurveOrder();
}

PyGeCurveCurveInt2d PyGeCurveCurveInt2d::orderWrt1()
{
    return PyGeCurveCurveInt2d(impObj()->orderWrt1());
}

PyGeCurveCurveInt2d PyGeCurveCurveInt2d::orderWrt2()
{
    return PyGeCurveCurveInt2d(impObj()->orderWrt2());
}

PyGeCurveCurveInt2d PyGeCurveCurveInt2d::cast(const PyGeEntity2d& src)
{
    if (!src.impObj()->isKindOf(AcGe::EntityId::kCurveCurveInt2d))
        PyThrowBadEs(Acad::eNotThatKindOfClass);
    return PyGeEntity2dCast<PyGeCurveCurveInt2d>(src);
}

PyGeCurveCurveInt2d PyGeCurveCurveInt2d::copycast(const PyGeEntity2d& src)
{
    if (!src.impObj()->isKindOf(AcGe::EntityId::kCurveCurveInt2d))
        PyThrowBadEs(Acad::eNotThatKindOfClass);
    return PyGeCurveCurveInt2d(src.impObj()->copy());
}

std::string PyGeCurveCurveInt2d::className()
{
    return "AcGeCurveCurveInt2d";
}

AcGeCurveCurveInt2d* PyGeCurveCurveInt2d::impObj() const
{
    return static_cast<AcGeCurveCurveInt2d*>(m_imp.get());
}
