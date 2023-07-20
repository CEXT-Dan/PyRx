#include "stdafx.h"
#include "PyGsManager.h"
#include "AcGsManager.h"

using namespace boost::python;

void makePyGsManagerWrapper()
{
    PyDocString DS("GsManager");
    class_<PyGsManager>("GsManager")
        .def("testfunc", &PyGsManager::testfunc, DS.CLASSARGSSTATIC({ "val : int","val2 : int" })).staticmethod("testfunc")
        .def("className", &PyGsManager::className).staticmethod("className")
        ;
}

PyGsManager::PyGsManager()
    : m_pyImp(acgsGetGsManager())
{
}

void PyGsManager::testfunc(int val, int val2)
{

}

std::string PyGsManager::className()
{
    return "AcGsManager";
}

AcGsManager* PyGsManager::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr)
        throw PyNullObject(src);
    return m_pyImp;
}
