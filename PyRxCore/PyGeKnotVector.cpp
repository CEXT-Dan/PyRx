#include "stdafx.h"
#include "PyGeKnotVector.h"
#include "PyGeInterval.h"

using namespace boost::python;

void makePyGeKnotVectorWrapper()
{
#if !defined(_BRXTARGET260)
    constexpr const std::string_view ctor = "Overloads:\n"
        "- None: Any\n"
        "- size: int, growSize: int\n"
        "- data: list[float]\n"
        "- plusMult: int, other: PyGe.KnotVector\n";

    constexpr const std::string_view appendOverloads = "Overloads:\n"
        "- val:float\n"
        "- tail: PyGe.KnotVector\n"
        "- tail: PyGe.KnotVector, knotRatio: float\n";

    PyDocString DS("KnotVector");
    class_<PyGeKnotVector>("KnotVector")
        .def(init<>())
        .def(init<int, int>())
        .def(init<const boost::python::list&>())
        .def(init<int, const PyGeKnotVector&>(DS.CTOR(ctor, 12188)))
        .def("isEqualTo", &PyGeKnotVector::isEqualTo, DS.ARGS({ "other: PyGe.KnotVector" }))
        .def("startParam", &PyGeKnotVector::startParam, DS.ARGS())
        .def("endParam", &PyGeKnotVector::endParam, DS.ARGS())
        .def("multiplicityAt", &PyGeKnotVector::multiplicityAt, DS.ARGS({ "idx: int" }))
        .def("multiplicityAtParam", &PyGeKnotVector::multiplicityAtParam, DS.ARGS({ "param: float" }))
        .def("numIntervals", &PyGeKnotVector::numIntervals, DS.ARGS())
        .def("getInterval", &PyGeKnotVector::getInterval, DS.ARGS({ "ord: int","param: float" }))
        .def("getDistinctKnots", &PyGeKnotVector::getDistinctKnots, DS.ARGS())
        .def("contains", &PyGeKnotVector::contains, DS.ARGS({ "param: float" }))
        .def("isOn", &PyGeKnotVector::isOn, DS.ARGS({ "knot: float" }))
        .def("reverse", &PyGeKnotVector::reverse, DS.ARGS())
        .def("removeAt", &PyGeKnotVector::removeAt, DS.ARGS({ "idx: int" }))
        .def("removeSubVector", &PyGeKnotVector::removeSubVector, DS.ARGS({ "start: int","end: int" }))
        .def("insertAt", &PyGeKnotVector::insertAt1)
        .def("insertAt", &PyGeKnotVector::insertAt2, DS.ARGS({ "idx: int","u: float", "multiplicity: int" }))
        .def("insert", &PyGeKnotVector::insert, DS.ARGS({ "u: float" }))
        .def("append", &PyGeKnotVector::append1)
        .def("append", &PyGeKnotVector::append2)
        .def("append", &PyGeKnotVector::append3, DS.OVRL(appendOverloads))
        .def("split", &PyGeKnotVector::split, DS.ARGS({ "param: float", "multilast: int", "multifirst: int" }))
        .def("setRange", &PyGeKnotVector::setRange, DS.ARGS({ "lower: float","upper: float" }))
        .def("tolerance", &PyGeKnotVector::tolerance, DS.ARGS())
        .def("setTolerance", &PyGeKnotVector::setTolerance, DS.ARGS({ "tol: float" }))
        .def("length", &PyGeKnotVector::length, DS.ARGS())
        .def("isEmpty", &PyGeKnotVector::isEmpty, DS.ARGS())
        .def("logicalLength", &PyGeKnotVector::logicalLength, DS.ARGS())
        .def("setLogicalLength", &PyGeKnotVector::setLogicalLength, DS.ARGS({ "length: int" }))
        .def("physicalLength", &PyGeKnotVector::physicalLength, DS.ARGS())
        .def("setPhysicalLength", &PyGeKnotVector::setPhysicalLength, DS.ARGS({ "length: int" }))
        .def("growLength", &PyGeKnotVector::growLength, DS.ARGS())
        .def("setGrowLength", &PyGeKnotVector::setGrowLength, DS.ARGS({ "length: int" }))
        .def("className", &PyGeKnotVector::className, DS.SARGS()).staticmethod("className")
        ;
#endif
}

#if !defined(_BRXTARGET260)
PyGeKnotVector::PyGeKnotVector()
    : m_imp()
{
}

PyGeKnotVector::PyGeKnotVector(int size, int growSize)
    : m_imp(size, growSize)
{
}

PyGeKnotVector::PyGeKnotVector(const AcGeKnotVector& src)
    : m_imp(src)
{
}

PyGeKnotVector::PyGeKnotVector(const boost::python::list& dbls)
    : m_imp(PyListToDoubleArray(dbls))
{
}

PyGeKnotVector::PyGeKnotVector(int plusMult, const PyGeKnotVector& src)
    : m_imp(plusMult, src.m_imp)
{
}

Adesk::Boolean PyGeKnotVector::isEqualTo(const PyGeKnotVector& other) const
{
    return m_imp.isEqualTo(other.m_imp);
}

double PyGeKnotVector::startParam() const
{
    return m_imp.startParam();
}

double PyGeKnotVector::endParam() const
{
    return m_imp.endParam();
}

int PyGeKnotVector::multiplicityAt(int i) const
{
    return m_imp.multiplicityAt(i);
}

int PyGeKnotVector::multiplicityAtParam(double param) const
{
    return m_imp.multiplicityAt(param);
}

int PyGeKnotVector::numIntervals() const
{
    return m_imp.numIntervals();
}

boost::python::tuple PyGeKnotVector::getInterval(int ord, double par) const
{
    PyAutoLockGIL lock;
    PyGeInterval interval;
    auto res = m_imp.getInterval(ord, par, interval.imp);
    return boost::python::make_tuple(res, interval);
}

boost::python::list PyGeKnotVector::getDistinctKnots() const
{
    PyAutoLockGIL lock;
    AcGeDoubleArray knots;
    m_imp.getDistinctKnots(knots);
    return DoubleArrayToPyList(knots);
}

Adesk::Boolean PyGeKnotVector::contains(double param) const
{
    return m_imp.contains(param);
}

Adesk::Boolean PyGeKnotVector::isOn(double knot) const
{
    return m_imp.isOn(knot);
}

void PyGeKnotVector::reverse()
{
    m_imp.reverse();
}

void PyGeKnotVector::removeAt(int index)
{
    m_imp.removeAt(index);
}

void PyGeKnotVector::removeSubVector(int startIndex, int endIndex)
{
    m_imp.removeSubVector(startIndex, endIndex);
}

void PyGeKnotVector::insertAt1(int indx, double u)
{
    m_imp.insertAt(indx, u);
}

void PyGeKnotVector::insertAt2(int indx, double u, int multiplicity)
{
    m_imp.insertAt(indx, u, multiplicity);
}

void PyGeKnotVector::insert(double u)
{
    m_imp.insert(u);
}

int PyGeKnotVector::append1(double val)
{
    return m_imp.append(val);
}

void PyGeKnotVector::append2(PyGeKnotVector& tail)
{
    m_imp.append(tail.m_imp);
}

void PyGeKnotVector::append3(PyGeKnotVector& tail, double knotRatio)
{
    m_imp.append(tail.m_imp, knotRatio);
}

boost::python::tuple PyGeKnotVector::split(double par, int multLast, int multFirst) const
{
    PyAutoLockGIL lock;
    PyGeKnotVector pKnot1;
    PyGeKnotVector pKnot2;
    m_imp.split(par, &pKnot1.m_imp, multLast, &pKnot2.m_imp, multFirst);
    return boost::python::make_tuple(pKnot1, pKnot2);
}

void PyGeKnotVector::setRange(double lower, double upper)
{
    m_imp.setRange(lower, upper);
}

double PyGeKnotVector::tolerance() const
{
    return m_imp.tolerance();
}

void PyGeKnotVector::setTolerance(double tol)
{
    m_imp.setTolerance(tol);
}

int PyGeKnotVector::length() const
{
    return m_imp.length();
}

Adesk::Boolean PyGeKnotVector::isEmpty() const
{
    return m_imp.isEmpty();
}

int PyGeKnotVector::logicalLength() const
{
    return m_imp.logicalLength();
}

void PyGeKnotVector::setLogicalLength(int len)
{
    m_imp.setLogicalLength(len);
}

int PyGeKnotVector::physicalLength() const
{
    return m_imp.physicalLength();
}

void PyGeKnotVector::setPhysicalLength(int len)
{
    m_imp.setPhysicalLength(len);
}

int PyGeKnotVector::growLength() const
{
    return m_imp.growLength();
}

void PyGeKnotVector::setGrowLength(int len)
{
    m_imp.setGrowLength(len);
}

std::string PyGeKnotVector::className()
{
    return "AcGeKnotVector";
}
#endif