#include "stdafx.h"
#include "PyGeBoundBlock3d.h"
using namespace boost::python;

//-----------------------------------------------------------------------------------
//PyGeBoundBlock3d
void makePyGeBoundBlock3dWrapper()
{
    class_<PyGeBoundBlock3d, bases<PyGeEntity3d>>("BoundBlock3d")
        .def(init<>())
        .def(init<const AcGePoint3d&, const AcGeVector3d&, const AcGeVector3d&, const AcGeVector3d&>())
        .def("getMinPoint", &PyGeBoundBlock3d::getMinPoint)
        .def("getMaxPoint", &PyGeBoundBlock3d::getMaxPoint)
        .def("getBasePoint", &PyGeBoundBlock3d::getBasePoint)
        .def("getDirection1", &PyGeBoundBlock3d::getDirection1)
        .def("getDirection3", &PyGeBoundBlock3d::getDirection3)
        .def("getDirection3", &PyGeBoundBlock3d::getDirection3)
        .def("set", &PyGeBoundBlock3d::set1, return_self<>())
        .def("set", &PyGeBoundBlock3d::set2, return_self<>())
        .def("extend", &PyGeBoundBlock3d::extend, return_self<>())
        .def("swell", &PyGeBoundBlock3d::swell, return_self<>())
        .def("contains", &PyGeBoundBlock3d::contains)
        .def("isDisjoint", &PyGeBoundBlock3d::isDisjoint)
        .def("isBox", &PyGeBoundBlock3d::isBox)
        .def("setToBox", &PyGeBoundBlock3d::setToBox, return_self<>())
        .def("copycast", &PyGeBoundBlock3d::copycast).staticmethod("copycast")
        .def("className", &PyGeBoundBlock3d::className).staticmethod("className")
        ;
}

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

void PyGeBoundBlock3d::set1(const AcGePoint3d& point1, const AcGePoint3d& point2)
{
    impObj()->set(point1, point2);
}

void PyGeBoundBlock3d::set2(const AcGePoint3d& base, const AcGeVector3d& dir1, const AcGeVector3d& dir2, const AcGeVector3d& dir3)
{
    impObj()->set(base, dir1, dir2, dir3);
}

void PyGeBoundBlock3d::extend(const AcGePoint3d& point)
{
    impObj()->extend(point);
}

void PyGeBoundBlock3d::swell(double distance)
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

void PyGeBoundBlock3d::setToBox(Adesk::Boolean val)
{
    impObj()->setToBox(val);
}

PyGeBoundBlock3d PyGeBoundBlock3d::copycast(const PyGeEntity3d& src)
{
    if (!src.impObj()->isKindOf(AcGe::EntityId::kBoundBlock3d))
        PyThrowBadEs(Acad::eInvalidInput);
    return PyGeBoundBlock3d(src.impObj()->copy());
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
