#include "stdafx.h"
#include "PyGeBoundBlock2d.h"
#include "PyGeLinearEnt2d.h"
#include "PyGeClipBoundary2d.h"

using namespace boost::python;

//-----------------------------------------------------------------------------------------
//PyGeBoundBlock2d wrapper
void makePyGeBoundBlock2dWrapper()
{
    constexpr const std::string_view ctor = "Overloads:\n"
        "- None: Any\n"
        "- pt1: PyGe.Point2d, pt2: PyGe.Point2d\n"
        "- base: PyGe.Point2d, dir1: PyGe.Vector2d, dir2: PyGe.Vector2d\n";

    constexpr const std::string_view setOverloads = "Overloads:\n"
        "- pt1: PyGe.Point2d, pt2: PyGe.Point2d\n"
        "- base: PyGe.Point2d, dir1: PyGe.Vector2d, dir2: PyGe.Vector2d\n";

    PyDocString DS("BoundBlock2d");
    class_<PyGeBoundBlock2d, bases<PyGeEntity2d>>("BoundBlock2d")
        .def(init<>())
        .def(init<const AcGePoint2d&, const AcGePoint2d&>())
        .def(init<const AcGePoint2d&, const AcGeVector2d&, const AcGeVector2d&>(DS.CTOR(ctor, 11687)))
        .def("getMinPoint", &PyGeBoundBlock2d::getMinPoint, DS.ARGS())
        .def("getMaxPoint", &PyGeBoundBlock2d::getMaxPoint, DS.ARGS())
        .def("getBasePoint", &PyGeBoundBlock2d::getBasePoint, DS.ARGS())
        .def("getDirection1", &PyGeBoundBlock2d::getDirection1, DS.ARGS())
        .def("getDirection2", &PyGeBoundBlock2d::getDirection2, DS.ARGS())
        .def("set", &PyGeBoundBlock2d::set1)
        .def("set", &PyGeBoundBlock2d::set2, DS.OVRL(setOverloads))
        .def("extend", &PyGeBoundBlock2d::extend, DS.ARGS({ "pt: PyGe.Point2d" }))
        .def("swell", &PyGeBoundBlock2d::swell, DS.ARGS({ "val: float" }))
        .def("contains", &PyGeBoundBlock2d::contains, DS.ARGS({ "pt: PyGe.Point2d" }))
        .def("isDisjoint", &PyGeBoundBlock2d::isDisjoint, DS.ARGS({ "block: PyGe.BoundBlock2d" }))
        .def("clipLineSeg2d", &PyGeBoundBlock2d::clipLineSeg2d, DS.ARGS({ "seg2d: PyGe.LineSeg2d"}, 19140))
        .def("isBox", &PyGeBoundBlock2d::isBox, DS.ARGS())
        .def("setToBox", &PyGeBoundBlock2d::setToBox, DS.ARGS({ "val: bool" }))
        .def("cast", &PyGeBoundBlock2d::cast, DS.SARGS({ "otherObject: PyGe.Entity2d" })).staticmethod("cast")
        .def("copycast", &PyGeBoundBlock2d::copycast, DS.SARGS({ "otherObject: PyGe.Entity2d" })).staticmethod("copycast")
        .def("className", &PyGeBoundBlock2d::className, DS.SARGS()).staticmethod("className")
        ;
}

PyGeBoundBlock2d::PyGeBoundBlock2d()
    : PyGeEntity2d(new AcGeBoundBlock2d())
{
}

PyGeBoundBlock2d::PyGeBoundBlock2d(AcGeEntity2d* pEnt)
    : PyGeEntity2d(pEnt)
{
}

PyGeBoundBlock2d::PyGeBoundBlock2d(const AcGePoint2d& point1, const AcGePoint2d& point2)
    : PyGeEntity2d(new AcGeBoundBlock2d(point1, point2))
{
}

PyGeBoundBlock2d::PyGeBoundBlock2d(const AcGePoint2d& base, const AcGeVector2d& dir1, const AcGeVector2d& dir2)
    : PyGeEntity2d(new AcGeBoundBlock2d(base, dir1, dir2))
{
}

PyGeBoundBlock2d::PyGeBoundBlock2d(const AcGeBoundBlock2d& block)
    : PyGeEntity2d(new AcGeBoundBlock2d(block))
{
}

AcGePoint2d PyGeBoundBlock2d::getMinPoint() const
{
    AcGePoint2d min, max;
    impObj()->getMinMaxPoints(min, max);
    return min;
}

AcGePoint2d PyGeBoundBlock2d::getMaxPoint() const
{
    AcGePoint2d min, max;
    impObj()->getMinMaxPoints(min, max);
    return max;
}

AcGePoint2d PyGeBoundBlock2d::getBasePoint() const
{
    AcGePoint2d base;
    AcGeVector2d dir1, dir2;
    impObj()->get(base, dir1, dir2);
    return base;
}

AcGeVector2d PyGeBoundBlock2d::getDirection1() const
{
    AcGePoint2d base;
    AcGeVector2d dir1, dir2;
    impObj()->get(base, dir1, dir2);
    return dir1;
}

AcGeVector2d PyGeBoundBlock2d::getDirection2() const
{
    AcGePoint2d base;
    AcGeVector2d dir1, dir2;
    impObj()->get(base, dir1, dir2);
    return dir2;
}

void PyGeBoundBlock2d::set1(const AcGePoint2d& point1, const AcGePoint2d& point2) const
{
    impObj()->set(point1, point2);
}

void PyGeBoundBlock2d::set2(const AcGePoint2d& base, const AcGeVector2d& dir1, const AcGeVector2d& dir2) const
{
    impObj()->set(base, dir1, dir2);
}

void PyGeBoundBlock2d::extend(const AcGePoint2d& point) const
{
    impObj()->extend(point);
}

void PyGeBoundBlock2d::swell(double distance) const
{
    impObj()->swell(distance);
}

Adesk::Boolean PyGeBoundBlock2d::contains(const AcGePoint2d& point) const
{
    return impObj()->contains(point);
}

Adesk::Boolean PyGeBoundBlock2d::isDisjoint(const PyGeBoundBlock2d& block) const
{
    return impObj()->isDisjoint(*block.impObj());
}

Adesk::Boolean PyGeBoundBlock2d::isBox() const
{
    return impObj()->isBox();
}

void PyGeBoundBlock2d::setToBox(Adesk::Boolean val) const
{
    impObj()->setToBox(val);
}

boost::python::tuple PyGeBoundBlock2d::clipLineSeg2d(const PyGeLineSeg2d& seg)
{
    AcGeLineSeg2d outseg;
    bool flag = ::clipLineSeg2d(outseg, *seg.impObj(), *impObj());
    return boost::python::make_tuple(flag, PyGeLineSeg2d(outseg));
}

PyGeBoundBlock2d PyGeBoundBlock2d::cast(const PyGeEntity2d& src)
{
    return PyGeEntity2dCast<PyGeBoundBlock2d, AcGeBoundBlock2d>(src);
}

PyGeBoundBlock2d PyGeBoundBlock2d::copycast(const PyGeEntity2d& src)
{
    return PyGeBoundBlock2d(static_cast<AcGeBoundBlock2d*>(src.impObj()->copy()));
}

std::string PyGeBoundBlock2d::className()
{
    return "AcGeBoundBlock2d";
}

AcGeBoundBlock2d* PyGeBoundBlock2d::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_imp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcGeBoundBlock2d*>(m_imp.get());
}
