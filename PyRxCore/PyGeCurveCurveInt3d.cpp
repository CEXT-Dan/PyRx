#include "stdafx.h"
#include "PyGeCurveCurveInt3d.h"
#include "PyGeCurve3d.h"
#include "PyGeInterval.h"
#include "PyGePointEnt3d.h"

using namespace boost::python;

//NOTE curve1, curve2 are not overloads
void makePyGeCurveCurveInt3dWrapper()
{
#if !defined(_BRXTARGET240)
    class_<PyGeCurveCurveInt3d, bases<PyGeEntity3d>>("CurveCurveInt3d")
        .def(init<>())
        .def(init<const PyGeCurve3d&, const PyGeCurve3d&>())
        .def(init<const PyGeCurve3d&, const PyGeCurve3d&, const AcGeVector3d&, const AcGeTol&>())
        .def(init<const PyGeCurve3d&, const PyGeCurve3d&, const PyGeInterval&, const PyGeInterval&>())
        .def(init<const PyGeCurve3d&, const PyGeCurve3d&, const PyGeInterval&, const PyGeInterval&, const AcGeVector3d&, const AcGeTol&>())
        .def("curve1", &PyGeCurveCurveInt3d::curve1)//not overload
        .def("curve2", &PyGeCurveCurveInt3d::curve2)//not overload
        .def("getIntRanges", &PyGeCurveCurveInt3d::getIntRanges)
        .def("planeNormal", &PyGeCurveCurveInt3d::planeNormal)
        .def("tolerance", &PyGeCurveCurveInt3d::tolerance)
        .def("numIntPoints", &PyGeCurveCurveInt3d::numIntPoints)
        .def("intPoint", &PyGeCurveCurveInt3d::intPoint)
        .def("getIntParams", &PyGeCurveCurveInt3d::getIntParams)
        .def("getPointOnCurve1", &PyGeCurveCurveInt3d::getPointOnCurve1)
        .def("getPointOnCurve2", &PyGeCurveCurveInt3d::getPointOnCurve2)
        .def("getIntConfigs", &PyGeCurveCurveInt3d::getIntConfigs)
        .def("isTangential", &PyGeCurveCurveInt3d::isTangential)
        .def("isTransversal", &PyGeCurveCurveInt3d::isTransversal)
        .def("intPointTol", &PyGeCurveCurveInt3d::intPointTol)
        .def("overlapCount", &PyGeCurveCurveInt3d::overlapCount)
        .def("overlapDirection", &PyGeCurveCurveInt3d::overlapDirection)
        .def("getOverlapRanges", &PyGeCurveCurveInt3d::getOverlapRanges)
        .def("changeCurveOrder", &PyGeCurveCurveInt3d::changeCurveOrder)
        .def("orderWrt1", &PyGeCurveCurveInt3d::orderWrt1)//not overload
        .def("orderWrt2", &PyGeCurveCurveInt3d::orderWrt2)//not overload
        .def("cast", &PyGeCurveCurveInt3d::cast).staticmethod("cast")
        .def("copycast", &PyGeCurveCurveInt3d::copycast).staticmethod("copycast")
        .def("className", &PyGeCurveCurveInt3d::className).staticmethod("className")
        ;
#endif
}

#if !defined(_BRXTARGET240)
PyGeCurveCurveInt3d::PyGeCurveCurveInt3d()
    : PyGeEntity3d(new AcGeCurveCurveInt3d())
{
}

PyGeCurveCurveInt3d::PyGeCurveCurveInt3d(const PyGeCurve3d& curve1, const PyGeCurve3d& curve2)
    : PyGeEntity3d(new AcGeCurveCurveInt3d(*curve1.impObj(), *curve2.impObj()))
{
}

PyGeCurveCurveInt3d::PyGeCurveCurveInt3d(const PyGeCurve3d& curve1, const PyGeCurve3d& curve2, const AcGeVector3d& planeNormal, const AcGeTol& tol)
    : PyGeEntity3d(new AcGeCurveCurveInt3d(*curve1.impObj(), *curve2.impObj(), planeNormal, tol))
{
}

PyGeCurveCurveInt3d::PyGeCurveCurveInt3d(const PyGeCurve3d& curve1, const PyGeCurve3d& curve2, const PyGeInterval& range1, const PyGeInterval& range2)
    : PyGeEntity3d(new AcGeCurveCurveInt3d(*curve1.impObj(), *curve2.impObj(), range1.imp, range2.imp))
{

}

PyGeCurveCurveInt3d::PyGeCurveCurveInt3d(const PyGeCurve3d& curve1, const PyGeCurve3d& curve2, const PyGeInterval& range1, const PyGeInterval& range2, const AcGeVector3d& planeNormal, const AcGeTol& tol)
    : PyGeEntity3d(new AcGeCurveCurveInt3d(*curve1.impObj(), *curve2.impObj(), range1.imp, range2.imp, planeNormal, tol))
{
}

PyGeCurveCurveInt3d::PyGeCurveCurveInt3d(AcGeEntity3d* pEnt)
    : PyGeEntity3d(pEnt)
{
}

PyGeCurveCurveInt3d::PyGeCurveCurveInt3d(const AcGeCurveCurveInt3d& src)
    : PyGeEntity3d(new AcGeCurveCurveInt3d(src))
{
}

PyGeCurve3d PyGeCurveCurveInt3d::curve1() const
{
    return PyGeCurve3d(impObj()->curve1());
}

PyGeCurve3d PyGeCurveCurveInt3d::curve2() const
{
    return PyGeCurve3d(impObj()->curve2());
}

boost::python::tuple PyGeCurveCurveInt3d::getIntRanges()
{
    PyAutoLockGIL lock;
    PyGeInterval range1;
    PyGeInterval range2;
    impObj()->getIntRanges(range1.imp, range2.imp);
    return boost::python::make_tuple(range1, range2);
}

AcGeVector3d PyGeCurveCurveInt3d::planeNormal() const
{
    return impObj()->planeNormal();
}

AcGeTol PyGeCurveCurveInt3d::tolerance() const
{
    return impObj()->tolerance();
}

int PyGeCurveCurveInt3d::numIntPoints() const
{
    return  impObj()->numIntPoints();
}

AcGePoint3d PyGeCurveCurveInt3d::intPoint(int intNum) const
{
    return  impObj()->intPoint(intNum);
}

boost::python::tuple PyGeCurveCurveInt3d::getIntParams(int intNum) const
{
    double param1 = 0; 
    double param2 = 0;
    PyAutoLockGIL lock;
    impObj()->getIntParams(intNum, param1, param2);
    return boost::python::make_tuple(param1, param2);
}

PyGePointOnCurve3d PyGeCurveCurveInt3d::getPointOnCurve1(int intNum) const
{
    AcGePointOnCurve3d pntOnCrv;
    impObj()->getPointOnCurve1(intNum, pntOnCrv);
    return PyGePointOnCurve3d(pntOnCrv);
}

PyGePointOnCurve3d PyGeCurveCurveInt3d::getPointOnCurve2(int intNum) const
{
    AcGePointOnCurve3d pntOnCrv;
    impObj()->getPointOnCurve2(intNum, pntOnCrv);
    return PyGePointOnCurve3d(pntOnCrv);
}

boost::python::tuple PyGeCurveCurveInt3d::getIntConfigs(int intNum) const
{
    PyAutoLockGIL lock;
    AcGe::AcGeXConfig config1wrt2;
    AcGe::AcGeXConfig config2wrt1;
    impObj()->getIntConfigs(intNum, config1wrt2, config2wrt1);
    return boost::python::make_tuple(config1wrt2, config2wrt1);
}

Adesk::Boolean PyGeCurveCurveInt3d::isTangential(int intNum) const
{
    return impObj()->isTangential(intNum);
}

Adesk::Boolean PyGeCurveCurveInt3d::isTransversal(int intNum) const
{
    return impObj()->isTransversal(intNum);
}

double PyGeCurveCurveInt3d::intPointTol(int intNum) const
{
    return impObj()->intPointTol(intNum);
}

int PyGeCurveCurveInt3d::overlapCount() const
{
    return impObj()->overlapCount();
}

Adesk::Boolean PyGeCurveCurveInt3d::overlapDirection() const
{
    return impObj()->overlapDirection();
}

boost::python::tuple PyGeCurveCurveInt3d::getOverlapRanges(int overlapNum) const
{
    PyAutoLockGIL lock;
    PyGeInterval range1;
    PyGeInterval range2;
    impObj()->getOverlapRanges(overlapNum,range1.imp, range2.imp);
    return boost::python::make_tuple(range1, range2);
}

void PyGeCurveCurveInt3d::changeCurveOrder()
{
    impObj()->changeCurveOrder();
}

PyGeCurveCurveInt3d PyGeCurveCurveInt3d::orderWrt1()
{
    return PyGeCurveCurveInt3d(impObj()->orderWrt1());
}

PyGeCurveCurveInt3d PyGeCurveCurveInt3d::orderWrt2()
{
    return PyGeCurveCurveInt3d(impObj()->orderWrt2());
}

PyGeCurveCurveInt3d PyGeCurveCurveInt3d::cast(const PyGeEntity3d& src)
{
    if (!src.impObj()->isKindOf(AcGe::EntityId::kCurveCurveInt3d))
        PyThrowBadEs(Acad::eNotThatKindOfClass);
    return PyGeEntity3dCast<PyGeCurveCurveInt3d>(src);
}

PyGeCurveCurveInt3d PyGeCurveCurveInt3d::copycast(const PyGeEntity3d& src)
{
    if (!src.impObj()->isKindOf(AcGe::EntityId::kCurveCurveInt3d))
        PyThrowBadEs(Acad::eNotThatKindOfClass);
    return PyGeCurveCurveInt3d(src.impObj()->copy());
}

std::string PyGeCurveCurveInt3d::className()
{
    return "AcGeCurveCurveInt3d";
}

AcGeCurveCurveInt3d* PyGeCurveCurveInt3d::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_imp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcGeCurveCurveInt3d*>(m_imp.get());
}
#endif
