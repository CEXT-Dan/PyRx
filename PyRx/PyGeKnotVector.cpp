#include "stdafx.h"
#include "PyGeKnotVector.h"
#include "PyGeInterval.h"

using namespace boost::python;

void makePyGeKnotVectorWrapper()
{
    class_<PyGeKnotVector>("KnotVector")
        .def("append", &PyGeKnotVector::append)
        .def("className", &PyGeKnotVector::className).staticmethod("className")
        ;
}

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

int PyGeKnotVector::append(double val)
{
    return m_imp.append(val);
}

std::string PyGeKnotVector::className()
{
    return "AcGeKnotVector";
}
