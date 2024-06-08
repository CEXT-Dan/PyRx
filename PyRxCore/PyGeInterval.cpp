#include "stdafx.h"
#include "PyGeInterval.h"

using namespace boost::python;


void makePyGeIntervalWrapper()
{
    constexpr const std::string_view ctor = "Overloads:\n"
        "- None: Any\n"
        "- lower: float, upper: float\n"
        "- bounded:bool, upper: float\n";

    constexpr const std::string_view setOverloads = "Overloads:\n"
        "- None: Any\n"
        "- lower: float, upper: float\n"
        "- bounded:bool, upper: float\n";

    PyDocString DS("Interval");
    class_<PyGeInterval>("Interval")
        .def(init<>())
        .def(init<double, double>())
        .def(init<Adesk::Boolean, double>(DS.CTOR(ctor)))
        .def("lowerBound", &PyGeInterval::lowerBound, DS.ARGS())
        .def("upperBound", &PyGeInterval::upperBound, DS.ARGS())
        .def("element", &PyGeInterval::element, DS.ARGS())
        .def("getBounds", &PyGeInterval::getBounds, DS.ARGS())
        .def("length", &PyGeInterval::length, DS.ARGS())
        .def("tolerance", &PyGeInterval::tolerance, DS.ARGS())
        .def("set", &PyGeInterval::set1)
        .def("set", &PyGeInterval::set2)
        .def("set", &PyGeInterval::set3, DS.OVRL(setOverloads))
        .def("setUpper", &PyGeInterval::setUpper, DS.ARGS({ "val: float" }))
        .def("setLower", &PyGeInterval::setLower, DS.ARGS({ "val: float" }))
        .def("setTolerance", &PyGeInterval::setTolerance, DS.ARGS({ "val: float" }))
        .def("getMerge", &PyGeInterval::getMerge, DS.ARGS({ "val: float" }))
        .def("subtract", &PyGeInterval::subtract, DS.ARGS({ "val: PyGe.Interval" }))
        .def("intersectWith", &PyGeInterval::intersectWith, DS.ARGS({ "val: PyGe.Interval" }))
        .def("isBounded", &PyGeInterval::isBounded, DS.ARGS())
        .def("isBoundedAbove", &PyGeInterval::isBoundedAbove, DS.ARGS())
        .def("isBoundedBelow", &PyGeInterval::isBoundedBelow, DS.ARGS())
        .def("isUnBounded", &PyGeInterval::isUnBounded, DS.ARGS())
        .def("isSingleton", &PyGeInterval::isSingleton, DS.ARGS())
        .def("isDisjoint", &PyGeInterval::isDisjoint, DS.ARGS({ "val: PyGe.Interval" }))
        .def("contains", &PyGeInterval::contains1)
        .def("contains", &PyGeInterval::contains2, DS.ARGS({ "val: PyGe.Interval|float" }))
        .def("isContinuousAtUpper", &PyGeInterval::isContinuousAtUpper, DS.ARGS({ "val: PyGe.Interval" }))
        .def("isOverlapAtUpper", &PyGeInterval::isOverlapAtUpper, DS.ARGS({ "val: PyGe.Interval" }))
        .def("isEqualAtUpper", &PyGeInterval::isEqualAtUpper1)
        .def("isEqualAtUpper", &PyGeInterval::isEqualAtUpper2, DS.ARGS({ "val: PyGe.Interval|float" }))
        .def("isEqualAtLower", &PyGeInterval::isEqualAtLower1)
        .def("isEqualAtLower", &PyGeInterval::isEqualAtLower2, DS.ARGS({ "val: PyGe.Interval|float" }))
        .def("isPeriodicallyOn", &PyGeInterval::isPeriodicallyOn, DS.ARGS({ "val: float" }))
        .def("isGreater", &PyGeInterval::isGreater1)
        .def("isGreater", &PyGeInterval::isGreater2, DS.ARGS({ "val: PyGe.Interval|float" }))
        .def("isGreaterOrEqual", &PyGeInterval::isGreaterOrEqual1)
        .def("isGreaterOrEqual", &PyGeInterval::isGreaterOrEqual2, DS.ARGS({ "val: PyGe.Interval|float" }))
        .def("isLess", &PyGeInterval::isLess1)
        .def("isLess", &PyGeInterval::isLess2, DS.ARGS({ "val: PyGe.Interval|float" }))
        .def("isLessOrEqual", &PyGeInterval::isLessOrEqual1)
        .def("isLessOrEqual", &PyGeInterval::isLessOrEqual2, DS.ARGS({ "val: PyGe.Interval|float" }))

        //operators 
        .def("__eq__", &PyGeInterval::operator==, DS.ARGS({ "val: PyGe.Interval" }))
        .def("__ne__", &PyGeInterval::operator!=, DS.ARGS({ "val: PyGe.Interval" }))

        .def("__lt__", &PyGeInterval::isLess1)
        .def("__lt__", &PyGeInterval::isLess2, DS.ARGS({ "val: PyGe.Interval|float" }))
        .def("__le__", &PyGeInterval::isLessOrEqual1)
        .def("__le__", &PyGeInterval::isLessOrEqual2, DS.ARGS({ "val: PyGe.Interval|float" }))

        .def("__gt__", &PyGeInterval::isGreater1)
        .def("__gt__", &PyGeInterval::isGreater2, DS.ARGS({ "val: PyGe.Interval|float" }))
        .def("__ge__", &PyGeInterval::isGreaterOrEqual1)
        .def("__ge__", &PyGeInterval::isGreaterOrEqual2, DS.ARGS({ "val: PyGe.Interval|float" }))

        .def("className", &PyGeInterval::className, DS.SARGS()).staticmethod("className")
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

PyGeInterval PyGeInterval::getMerge(const PyGeInterval& otherInterval) const
{
    PyGeInterval result;
    imp.getMerge(otherInterval.imp, result.imp);
    return result;
}

boost::python::tuple PyGeInterval::subtract(const PyGeInterval& otherInterval) const
{
    PyAutoLockGIL lock;
    PyGeInterval lInterval;
    PyGeInterval rInterval;
    int res = imp.subtract(otherInterval.imp, lInterval.imp, rInterval.imp);
    return boost::python::make_tuple(res, lInterval, rInterval);
}

boost::python::tuple PyGeInterval::intersectWith(const PyGeInterval& otherInterval) const
{
    PyAutoLockGIL lock;
    PyGeInterval result;
    auto res = imp.intersectWith(otherInterval.imp, result.imp);
    return boost::python::make_tuple(res, result);
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

boost::python::tuple PyGeInterval::isOverlapAtUpper(const PyGeInterval& otherInterval) const
{
    PyAutoLockGIL lock;
    PyGeInterval overlap;
    auto r = imp.isOverlapAtUpper(otherInterval.imp, overlap.imp);
    return boost::python::make_tuple(r, overlap);
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
