#include "stdafx.h"
#include "PySmSheetSetMgr.h"

#if defined(_ARXTARGET) || defined(_BRXTARGET) 
#include "PySmSheetSetMgrImpl.h"
#include "PyDbObject.h"

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

PySmPersist::PySmPersist(const PySmPersistImpl& other)
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
        .def("getName", &PySmComponent::getName)
        .def("setName", &PySmComponent::setName)
        .def("getDesc", &PySmComponent::getDesc)
        .def("setDesc", &PySmComponent::setDesc)
        .def("className", &PySmComponent::className, DS.SARGS()).staticmethod("className")
        ;
}

PySmComponent::PySmComponent(PySmComponentImpl* ptr)
  : PySmPersist(ptr)
{
}

PySmComponent::PySmComponent(const PySmComponentImpl& other)
    : PySmPersist(other)
{
}

std::string PySmComponent::getName() const
{
    return wstr_to_utf8(impObj()->GetName());
}

void PySmComponent::setName(const std::string& csName)
{
    impObj()->SetName(utf8_to_wstr(csName).c_str());
}

std::string PySmComponent::getDesc() const
{
    return wstr_to_utf8(impObj()->GetDesc());
}

void PySmComponent::setDesc(const std::string& csDesc)
{
    impObj()->SetDesc(utf8_to_wstr(csDesc).c_str());
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
        .def("smObjects", &PySmDatabase::smObjects)
        .def("className", &PySmDatabase::className, DS.SARGS()).staticmethod("className")
        ;
}

PySmDatabase::PySmDatabase(PySmDatabaseImpl* ptr)
    : PySmComponent(ptr)
{
}

PySmDatabase::PySmDatabase(const PySmDatabaseImpl& other)
    : PySmComponent(other)
{
}

boost::python::list PySmDatabase::smObjects()
{
    PyAutoLockGIL lock;
    boost::python::list pylist;
    const auto& v = impObj()->GetEnumerator();
    for (const auto& i : v)
        pylist.append(PySmPersist(i));
    return pylist;
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

        .def("createDatabase", &PySmSheetSetMgr::createDatabase1)
        .def("createDatabase", &PySmSheetSetMgr::createDatabase2)
        .def("openDatabase", &PySmSheetSetMgr::openDatabase)
        .def("findOpenDatabase", &PySmSheetSetMgr::findOpenDatabase)
        .def("closeAll", &PySmSheetSetMgr::closeAll)
        .def("close", &PySmSheetSetMgr::close)
        .def("getParentSheetSet", &PySmSheetSetMgr::getParentSheetSet)
        .def("getSheetFromLayout", &PySmSheetSetMgr::getSheetFromLayout)
        .def("databases", &PySmSheetSetMgr::databases)
        .def("className", &PySmSheetSetMgr::className, DS.SARGS()).staticmethod("className")
        ;
}

PySmSheetSetMgr::PySmSheetSetMgr()
    : m_pyImp (new PySmSheetSetMgrImpl())
{
}

PySmDatabase PySmSheetSetMgr::createDatabase1(const std::string& filename)
{
    return PySmDatabase(impObj()->CreateDatabase(utf8_to_wstr(filename).c_str()));
}

PySmDatabase PySmSheetSetMgr::createDatabase2(const std::string& filename, const std::string& templatefilename, bool bAlwaysCreate)
{
    return PySmDatabase(impObj()->CreateDatabase(utf8_to_wstr(filename).c_str(), utf8_to_wstr(templatefilename).c_str(), bAlwaysCreate));
}

PySmDatabase PySmSheetSetMgr::openDatabase(const std::string& filename)
{
    return PySmDatabase(impObj()->OpenDatabase(utf8_to_wstr(filename).c_str()));
}

PySmDatabase PySmSheetSetMgr::findOpenDatabase(const std::string& filename)
{
    return PySmDatabase(impObj()->FindOpenDatabase(utf8_to_wstr(filename).c_str()));
}

void PySmSheetSetMgr::closeAll()
{
    impObj()->CloseAll();
}

void PySmSheetSetMgr::close(PySmDatabase& db)
{
    impObj()->Close(*db.impObj());
}

boost::python::tuple PySmSheetSetMgr::getParentSheetSet(const std::string& dwg, const std::string& layout)
{
    PyAutoLockGIL lock;
    const auto& val = impObj()->GetParentSheetSet(utf8_to_wstr(dwg).c_str(), utf8_to_wstr(layout).c_str());
    //
    return boost::python::make_tuple();
}

boost::python::tuple PySmSheetSetMgr::getSheetFromLayout(PyDbObject& pAcDbLayout)
{
    PyAutoLockGIL lock;
    const auto& val = impObj()->GetSheetFromLayout(pAcDbLayout.impObj());
    //
    return boost::python::make_tuple();
}

boost::python::list PySmSheetSetMgr::databases() const
{
    PyAutoLockGIL lock;
    boost::python::list pylist;
    const auto& v = impObj()->GetDatabaseEnumerator();
    for (const auto& i : v)
        pylist.append(PySmDatabase(i));
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

