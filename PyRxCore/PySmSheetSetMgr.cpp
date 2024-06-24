#include "stdafx.h"
#include "PySmSheetSetMgr.h"

#if defined(_ARXTARGET) || defined(_BRXTARGET) 
#include "PySmSheetSetMgrImpl.h"

using namespace boost::python;

void makePySmPersistWrapper()
{
    PyDocString DS("SmPersist");
    class_<PySmPersist>("SmPersist", boost::python::no_init)
        .def("getTypeName", &PySmPersist::getTypeName, DS.SARGS())
        .def("className", &PySmPersist::className, DS.SARGS()).staticmethod("className")
        ;
}

PySmPersist::PySmPersist(PySmPersistImpl* ptr)
    : m_pyImp(new PySmPersistImpl(ptr->impObj()))
{
}

std::string PySmPersist::getTypeName() const
{
    return wstr_to_utf8(impObj()->GetTypeName());
}

std::string PySmPersist::className()
{
    return "IAcSmPersist";
}

PySmPersistImpl* PySmPersist::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return m_pyImp.get();
}

#endif