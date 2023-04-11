#include "stdafx.h"
#include "PyGeInterval.h"

using namespace boost::python;


void makePyGeIntervalWrapper()
{
    static auto wrapper = class_<PyGeInterval>("GeInterval")
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

std::string PyGeInterval::className()
{
    return "AcGeInterval";
}
