#include "stdafx.h"
#include "PyGeKnotVector.h"

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

PyGeKnotVector::PyGeKnotVector(const AcGeKnotVector& src)
    : m_imp(src)
{
}

int PyGeKnotVector::append(double val)
{
    return m_imp.append(val);
}

std::string PyGeKnotVector::className()
{
    return "AcGeKnotVector";
}
