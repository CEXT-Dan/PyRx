#include "stdafx.h"
#include "PyGeInterval.h"

using namespace boost::python;


void makePyGeIntervalWrapper()
{
    class_<PyGeInterval>("Interval")
        .def(init<>())
        .def(init<double, double>())
        .def(init<Adesk::Boolean, double>())
        .def("lowerBound", &PyGeInterval::lowerBound)
        .def("upperBound", &PyGeInterval::upperBound)
        .def("element", &PyGeInterval::element)
        .def("getBounds", &PyGeInterval::getBounds)
        .def("length", &PyGeInterval::length)
        .def("tolerance", &PyGeInterval::tolerance)
        .def("set", &PyGeInterval::set1)
        .def("set", &PyGeInterval::set2)
        .def("set", &PyGeInterval::set3)
        .def("setUpper", &PyGeInterval::setUpper)
        .def("setLower", &PyGeInterval::setLower)
        .def("setTolerance", &PyGeInterval::setTolerance)
        .def("getMerge", &PyGeInterval::getMerge)
        .def("subtract", &PyGeInterval::subtract)
        .def("intersectWith", &PyGeInterval::intersectWith)
        .def("isBounded", &PyGeInterval::isBounded)
        .def("isBoundedAbove", &PyGeInterval::isBoundedAbove)
        .def("isBoundedBelow", &PyGeInterval::isBoundedBelow)
        .def("isUnBounded", &PyGeInterval::isUnBounded)
        .def("isSingleton", &PyGeInterval::isSingleton)
        .def("isDisjoint", &PyGeInterval::isDisjoint)
        .def("contains", &PyGeInterval::contains1)
        .def("contains", &PyGeInterval::contains2)
        .def("isContinuousAtUpper", &PyGeInterval::isContinuousAtUpper)
        .def("isOverlapAtUpper", &PyGeInterval::isOverlapAtUpper)
        .def("isEqualAtUpper", &PyGeInterval::isEqualAtUpper1)
        .def("isEqualAtUpper", &PyGeInterval::isEqualAtUpper2)
        .def("isEqualAtLower", &PyGeInterval::isEqualAtLower1)
        .def("isEqualAtLower", &PyGeInterval::isEqualAtLower2)
        .def("isPeriodicallyOn", &PyGeInterval::isPeriodicallyOn)
        .def("isGreater", &PyGeInterval::isGreater1)
        .def("isGreater", &PyGeInterval::isGreater2)
        .def("isGreaterOrEqual", &PyGeInterval::isGreaterOrEqual1)
        .def("isGreaterOrEqual", &PyGeInterval::isGreaterOrEqual2)
        .def("isLess", &PyGeInterval::isLess1)
        .def("isLess", &PyGeInterval::isLess2)
        .def("isLessOrEqual", &PyGeInterval::isLessOrEqual1)
        .def("isLessOrEqual", &PyGeInterval::isLessOrEqual2)

        //operators 
        .def("__eq__", &PyGeInterval::operator==)
        .def("__ne__", &PyGeInterval::operator!=)

        .def("__lt__", &PyGeInterval::isLess1)
        .def("__lt__", &PyGeInterval::isLess2)
        .def("__le__", &PyGeInterval::isLessOrEqual1)
        .def("__le__", &PyGeInterval::isLessOrEqual2)

        .def("__gt__", &PyGeInterval::isGreater1)
        .def("__gt__", &PyGeInterval::isGreater2)
        .def("__ge__", &PyGeInterval::isGreaterOrEqual1)
        .def("__ge__", &PyGeInterval::isGreaterOrEqual2)

        .def("className", &PyGeInterval::className).staticmethod("className")
        ;
}

PyGeInterval::PyGeInterval()
{
}

PyGeInterval::PyGeInterval(const AcGeInterval& src)
    : imp(src)
{
}

PyGeInterval::PyGeInterval(double lower, double upper)
    : imp(lower, upper)
{

}

PyGeInterval::PyGeInterval(Adesk::Boolean boundedBelow, double bound)
    : imp(boundedBelow, bound)
{
}

std::string PyGeInterval::className()
{
    return "AcGeInterval";
}

double PyGeInterval::lowerBound() const
{
    return imp.lowerBound();
}

double PyGeInterval::upperBound() const
{
    return imp.upperBound();
}

double PyGeInterval::element() const
{
    return imp.element();
}

boost::python::tuple PyGeInterval::getBounds() const
{
    PyAutoLockGIL lock;
    double lower = 0;
    double upper = 0;
    imp.getBounds(lower, upper);
    return boost::python::make_tuple(lower, upper);
}

double PyGeInterval::length() const
{
    return imp.length();
}

double PyGeInterval::tolerance() const
{
    return imp.tolerance();
}

void PyGeInterval::set1(double lower, double upper)
{
    imp.set(lower, upper);
}

void PyGeInterval::set2(Adesk::Boolean boundedBelow, double bound)
{
    imp.set(boundedBelow, bound);
}

void PyGeInterval::set3()
{
    imp.set();
}

void PyGeInterval::setUpper(double upper)
{
    imp.setUpper(upper);
}

void PyGeInterval::setLower(double lower)
{
    imp.setLower(lower);
}

void PyGeInterval::setTolerance(double tol)
{
    imp.setTolerance(tol);
}

void PyGeInterval::getMerge(const PyGeInterval& otherInterval, PyGeInterval& result) const
{
    imp.getMerge(otherInterval.imp, result.imp);
}

int PyGeInterval::subtract(const PyGeInterval& otherInterval, PyGeInterval& lInterval, PyGeInterval& rInterval) const
{
    return imp.subtract(otherInterval.imp, lInterval.imp, rInterval.imp);
}

Adesk::Boolean PyGeInterval::intersectWith(const PyGeInterval& otherInterval, PyGeInterval& result) const
{
    return imp.intersectWith(otherInterval.imp, result.imp);
}

Adesk::Boolean PyGeInterval::isBounded() const
{
    return imp.isBounded();
}

Adesk::Boolean PyGeInterval::isBoundedAbove() const
{
    return imp.isBoundedAbove();
}

Adesk::Boolean PyGeInterval::isBoundedBelow() const
{
    return imp.isBoundedBelow();
}

Adesk::Boolean PyGeInterval::isUnBounded() const
{
    return imp.isUnBounded();
}

Adesk::Boolean PyGeInterval::isSingleton() const
{
    return imp.isSingleton();
}

Adesk::Boolean PyGeInterval::isDisjoint(const PyGeInterval& otherInterval) const
{
    return imp.isDisjoint(otherInterval.imp);
}

Adesk::Boolean PyGeInterval::contains1(const PyGeInterval& otherInterval) const
{
    return imp.contains(otherInterval.imp);
}

Adesk::Boolean PyGeInterval::contains2(double val) const
{
    return imp.contains(val);
}

Adesk::Boolean PyGeInterval::isContinuousAtUpper(const PyGeInterval& otherInterval) const
{
    return imp.isContinuousAtUpper(otherInterval.imp);
}

Adesk::Boolean PyGeInterval::isOverlapAtUpper(const PyGeInterval& otherInterval, PyGeInterval& overlap) const
{
    return imp.isOverlapAtUpper(otherInterval.imp, overlap.imp);
}

Adesk::Boolean PyGeInterval::isEqualAtUpper1(const PyGeInterval& otherInterval) const
{
    return imp.isEqualAtUpper(otherInterval.imp);
}

Adesk::Boolean PyGeInterval::isEqualAtUpper2(double value) const
{
    return imp.isEqualAtUpper(value);
}

Adesk::Boolean PyGeInterval::isEqualAtLower1(const PyGeInterval& otherInterval) const
{
    return imp.isEqualAtLower(otherInterval.imp);
}

Adesk::Boolean PyGeInterval::isEqualAtLower2(double value) const
{
    return imp.isEqualAtLower(value);
}

boost::python::tuple PyGeInterval::isPeriodicallyOn(double period)
{
    PyAutoLockGIL lock;
    double val = 0;
    auto res = imp.isPeriodicallyOn(period, val);
    return boost::python::make_tuple(res, val);
}

bool PyGeInterval::isGreater1(double val)
{
    return imp > val;
}

bool PyGeInterval::isGreater2(const PyGeInterval& otherInterval)
{
    return imp > otherInterval.imp;
}

bool PyGeInterval::isGreaterOrEqual1(double val)
{
    return imp >= val;
}

bool PyGeInterval::isGreaterOrEqual2(const PyGeInterval& otherInterval)
{
    return imp >= otherInterval.imp;
}

bool PyGeInterval::isLess1(double val)
{
    return imp < val;
}

bool PyGeInterval::isLess2(const PyGeInterval& otherInterval)
{
    return imp < otherInterval.imp;
}

bool PyGeInterval::isLessOrEqual1(double val)
{
    return imp <= val;
}

bool PyGeInterval::isLessOrEqual2(const PyGeInterval& otherInterval)
{
    return imp <= otherInterval.imp;
}

Adesk::Boolean PyGeInterval::operator!=(const PyGeInterval& otherInterval) const
{
    return imp != otherInterval.imp;
}

Adesk::Boolean PyGeInterval::operator==(const PyGeInterval& otherInterval) const
{
    return imp == otherInterval.imp;
}
