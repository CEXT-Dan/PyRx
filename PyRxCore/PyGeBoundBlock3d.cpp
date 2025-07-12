#include "stdafx.h"
#include "PyGeBoundBlock3d.h"
using namespace boost::python;

//-----------------------------------------------------------------------------------
//PyGeBoundBlock3d
void makePyGeBoundBlock3dWrapper()
{
#if !defined(_BRXTARGET260)
    constexpr const std::string_view ctor = "Overloads:\n"
        "- None: Any\n"
        "- base: PyGe.Point3d, dir1: PyGe.Vector3d, dir2: PyGe.Vector3d,dir3: PyGe.Vector3d\n";

    constexpr const std::string_view setOverloads = "Overloads:\n"
        "- pt1: PyGe.Point3d, pt2: PyGe.Point3d\n"
        "- base: PyGe.Point3d, dir1: PyGe.Vector3d, dir2: PyGe.Vector3d,dir3: PyGe.Vector3d\n";

    PyDocString DS("BoundBlock3d");
    class_<PyGeBoundBlock3d, bases<PyGeEntity3d>>("BoundBlock3d")
        .def(init<>())
        .def(init<const AcGePoint3d&, const AcGeVector3d&, const AcGeVector3d&, const AcGeVector3d&>(DS.CTOR(ctor, 11699)))
        .def("getMinPoint", &PyGeBoundBlock3d::getMinPoint, DS.ARGS())
        .def("getMaxPoint", &PyGeBoundBlock3d::getMaxPoint, DS.ARGS())
        .def("getBasePoint", &PyGeBoundBlock3d::getBasePoint, DS.ARGS())
        .def("getDirection1", &PyGeBoundBlock3d::getDirection1, DS.ARGS())
        .def("getDirection3", &PyGeBoundBlock3d::getDirection3, DS.ARGS())
        .def("getDirection3", &PyGeBoundBlock3d::getDirection3, DS.ARGS())
        .def("set", &PyGeBoundBlock3d::set1)
        .def("set", &PyGeBoundBlock3d::set2, DS.OVRL(setOverloads))
        .def("extend", &PyGeBoundBlock3d::extend, DS.ARGS({ "pt: PyGe.Point3d" }))
        .def("swell", &PyGeBoundBlock3d::swell, DS.ARGS({ "val: float" }))
        .def("contains", &PyGeBoundBlock3d::contains, DS.ARGS({ "pt: PyGe.Point3d" }))
        .def("isDisjoint", &PyGeBoundBlock3d::isDisjoint, DS.ARGS({ "block: PyGe.BoundBlock3d" }))
        .def("isBox", &PyGeBoundBlock3d::isBox, DS.ARGS())
        .def("setToBox", &PyGeBoundBlock3d::setToBox, DS.ARGS({ "val: bool" }))
        .def("cast", &PyGeBoundBlock3d::cast, DS.SARGS({ "otherObject: PyGe.Entity3d" })).staticmethod("cast")
        .def("copycast", &PyGeBoundBlock3d::copycast, DS.SARGS({ "otherObject: PyGe.Entity3d" })).staticmethod("copycast")
        .def("className", &PyGeBoundBlock3d::className, DS.SARGS()).staticmethod("className")
        ;
#endif
}

#if !defined(_BRXTARGET260)
PyGeBoundBlock3d::PyGeBoundBlock3d()
    :PyGeEntity3d(new AcGeBoundBlock3d())
{
}

PyGeBoundBlock3d::PyGeBoundBlock3d(AcGeEntity3d* pEnt)
    : PyGeEntity3d(pEnt)
{
}

PyGeBoundBlock3d::PyGeBoundBlock3d(const AcGePoint3d& base, const AcGeVector3d& dir1, const AcGeVector3d& dir2, const AcGeVector3d& dir3)
    : PyGeEntity3d(new AcGeBoundBlock3d(base, dir1, dir2, dir3))
{
}

PyGeBoundBlock3d::PyGeBoundBlock3d(const AcGeBoundBlock3d& src)
    :PyGeEntity3d(new AcGeBoundBlock3d(src))
{
}

AcGePoint3d PyGeBoundBlock3d::getMinPoint() const
{
    AcGePoint3d min, max;
    impObj()->getMinMaxPoints(min, max);
    return min;
}

AcGePoint3d PyGeBoundBlock3d::getMaxPoint() const
{
    AcGePoint3d min, max;
    impObj()->getMinMaxPoints(min, max);
    return max;
}

AcGePoint3d PyGeBoundBlock3d::getBasePoint() const
{
    AcGePoint3d base;
    AcGeVector3d dir1, dir2, dir3;
    impObj()->get(base, dir1, dir2, dir3);
    return base;
}

AcGeVector3d PyGeBoundBlock3d::getDirection1() const
{
    AcGePoint3d base;
    AcGeVector3d dir1, dir2, dir3;
    impObj()->get(base, dir1, dir2, dir3);
    return dir1;
}

AcGeVector3d PyGeBoundBlock3d::getDirection2() const
{
    AcGePoint3d base;
    AcGeVector3d dir1, dir2, dir3;
    impObj()->get(base, dir1, dir2, dir3);
    return dir2;
}

AcGeVector3d PyGeBoundBlock3d::getDirection3() const
{
    AcGePoint3d base;
    AcGeVector3d dir1, dir2, dir3;
    impObj()->get(base, dir1, dir2, dir3);
    return dir3;
}

void PyGeBoundBlock3d::set1(const AcGePoint3d& point1, const AcGePoint3d& point2) const
{
    impObj()->set(point1, point2);
}

void PyGeBoundBlock3d::set2(const AcGePoint3d& base, const AcGeVector3d& dir1, const AcGeVector3d& dir2, const AcGeVector3d& dir3) const
{
    impObj()->set(base, dir1, dir2, dir3);
}

void PyGeBoundBlock3d::extend(const AcGePoint3d& point) const
{
    impObj()->extend(point);
}

void PyGeBoundBlock3d::swell(double distance) const
{
    impObj()->swell(distance);
}

Adesk::Boolean PyGeBoundBlock3d::contains(const AcGePoint3d& point) const
{
    return impObj()->contains(point);
}

Adesk::Boolean PyGeBoundBlock3d::isDisjoint(const PyGeBoundBlock3d& block) const
{
    return impObj()->isDisjoint(*block.impObj());
}

Adesk::Boolean PyGeBoundBlock3d::isBox() const
{
    return impObj()->isBox();
}

void PyGeBoundBlock3d::setToBox(Adesk::Boolean val) const
{
    impObj()->setToBox(val);
}

PyGeBoundBlock3d PyGeBoundBlock3d::cast(const PyGeEntity3d& src)
{
    return PyGeEntity3dCast<PyGeBoundBlock3d, AcGeBoundBlock3d>(src);
}

PyGeBoundBlock3d PyGeBoundBlock3d::copycast(const PyGeEntity3d& src)
{
    return PyGeBoundBlock3d(static_cast<AcGeBoundBlock3d*>(src.impObj()->copy()));
}

std::string PyGeBoundBlock3d::className()
{
    return "AcGeBoundBlock3d";
}

AcGeBoundBlock3d* PyGeBoundBlock3d::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_imp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcGeBoundBlock3d*>(m_imp.get());
}
#endif
