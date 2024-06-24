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

PySmPersist::PySmPersist(PySmPersistImpl& other)
    : m_pyImp(new PySmPersistImpl(other))
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

//-----------------------------------------------------------------------------------------
//PySmComponent
void makePySmComponentWrapper()
{
    PyDocString DS("SmComponent");
    class_<PySmComponent,bases<PySmPersist>>("SmComponent", boost::python::no_init)
        .def("className", &PySmComponent::className, DS.SARGS()).staticmethod("className")
        ;
}

PySmComponent::PySmComponent(PySmComponentImpl* ptr)
  : PySmPersist(ptr)
{
}

PySmComponent::PySmComponent(PySmComponentImpl& other)
    : PySmPersist(other)
{
}

std::string PySmComponent::className()
{
    return "IAcSmPersist";
}

PySmComponentImpl* PySmComponent::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<PySmComponentImpl*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
//PySmSmDatabase
void makePySmDatabaseWrapper()
{
    PyDocString DS("PySmDatabase");
    class_<PySmDatabase, bases<PySmComponent>>("PySmDatabase", boost::python::no_init)
        .def("className", &PySmDatabase::className, DS.SARGS()).staticmethod("className")
        ;
}

PySmDatabase::PySmDatabase(PySmDatabaseImpl* ptr)
    : PySmComponent(ptr)
{
}

PySmDatabase::PySmDatabase(PySmDatabaseImpl& other)
    : PySmComponent(other)
{
}

std::string PySmDatabase::className()
{
    return "IAcSmDatabase";
}

PySmDatabaseImpl* PySmDatabase::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<PySmDatabaseImpl*>(m_pyImp.get());
}


//-----------------------------------------------------------------------------------------
//PySmSheetSetMgr
void makePySmSheetSetMgrWrapper()
{
    PyDocString DS("SmSheetSetMgr");
    class_<PySmSheetSetMgr>("SmSheetSetMgr")
        .def("className", &PySmSheetSetMgr::className, DS.SARGS()).staticmethod("className")
        ;
}

PySmSheetSetMgr::PySmSheetSetMgr()
    : m_pyImp (new PySmSheetSetMgrImpl())
{
}

boost::python::list PySmSheetSetMgr::databases() const
{
    PyAutoLockGIL lock;
    boost::python::list pylist;
    const auto& v = impObj()->GetDatabaseEnumerator();
    //for (const auto i : v)
        //pylist.append(i);
    return pylist;
}

std::string PySmSheetSetMgr::className()
{
    return "IAcSmSheetSetMgr";
}

PySmSheetSetMgrImpl* PySmSheetSetMgr::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return m_pyImp.get();
}
#endif

