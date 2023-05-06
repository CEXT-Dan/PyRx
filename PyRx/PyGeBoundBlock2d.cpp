#include "stdafx.h"
#include "PyGeBoundBlock2d.h"

using namespace boost::python;

//-----------------------------------------------------------------------------------------
//PyGeBoundBlock2d wrapper
void makePyGeBoundBlock2dWrapper()
{
    static auto wrapper = class_<PyGeBoundBlock2d, bases<PyGeEntity2d>>("BoundBlock2d")
        .def(init<>())
        .def(init<const AcGePoint2d&, const AcGePoint2d&>())
        .def(init<const AcGePoint2d&, const AcGeVector2d&, const AcGeVector2d&>())
        .def("getMinPoint", &PyGeBoundBlock2d::getMinPoint)
        .def("getMaxPoint", &PyGeBoundBlock2d::getMaxPoint)
        .def("getBasePoint", &PyGeBoundBlock2d::getBasePoint)
        .def("getDirection1", &PyGeBoundBlock2d::getDirection1)
        .def("getDirection2", &PyGeBoundBlock2d::getDirection2)
        .def("set", &PyGeBoundBlock2d::set1, return_self<>())
        .def("set", &PyGeBoundBlock2d::set2, return_self<>())
        .def("extend", &PyGeBoundBlock2d::extend, return_self<>())
        .def("swell", &PyGeBoundBlock2d::swell, return_self<>())
        .def("contains", &PyGeBoundBlock2d::contains)
        .def("isDisjoint", &PyGeBoundBlock2d::isDisjoint)
        .def("isBox", &PyGeBoundBlock2d::isBox)
        .def("setToBox", &PyGeBoundBlock2d::setToBox,return_self<>())
        .def("className", &PyGeBoundBlock2d::className).staticmethod("className")
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

PyGeBoundBlock2d& PyGeBoundBlock2d::set1(const AcGePoint2d& point1, const AcGePoint2d& point2)
{
    impObj()->set(point1, point2);
    return *this;
}

PyGeBoundBlock2d& PyGeBoundBlock2d::set2(const AcGePoint2d& base, const AcGeVector2d& dir1, const AcGeVector2d& dir2)
{
    impObj()->set(base, dir1, dir2);
    return *this;
}

PyGeBoundBlock2d& PyGeBoundBlock2d::extend(const AcGePoint2d& point)
{
    impObj()->extend(point);
    return *this;
}

PyGeBoundBlock2d& PyGeBoundBlock2d::swell(double distance)
{
    impObj()->swell(distance);
    return *this;
}

Adesk::Boolean PyGeBoundBlock2d::contains(const AcGePoint2d& point) const
{
    return impObj()->contains(point);
}

Adesk::Boolean PyGeBoundBlock2d::isDisjoint(const PyGeBoundBlock2d& block)
{
    return impObj()->isDisjoint(*block.impObj());
}

Adesk::Boolean PyGeBoundBlock2d::isBox() const
{
    return impObj()->isBox();
}

AcGeBoundBlock2d& PyGeBoundBlock2d::setToBox(Adesk::Boolean val)
{
    return impObj()->setToBox(val);
}

std::string PyGeBoundBlock2d::className()
{
    return "AcGeBoundBlock2d";
}

AcGeBoundBlock2d* PyGeBoundBlock2d::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_imp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcGeBoundBlock2d*>(m_imp.get());
}
