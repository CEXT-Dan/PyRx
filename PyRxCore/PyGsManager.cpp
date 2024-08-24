#include "stdafx.h"
#include "PyGsManager.h"
#include "AcGsManager.h"
#include "PyDbObjectId.h"

using namespace boost::python;

void makePyGsManagerWrapper()
{
    PyDocString DS("GsManager");
    class_<PyGsManager>("GsManager")
        .def(init<>(DS.ARGS()))
        .def("className", &PyGsManager::className, DS.SARGS()).staticmethod("className")
        ;
}

PyGsManager::PyGsManager()
    : m_pyImp(acgsGetGsManager())
{
}

std::string PyGsManager::className()
{
    return "AcGsManager";
}

AcGsManager* PyGsManager::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return m_pyImp;
}
