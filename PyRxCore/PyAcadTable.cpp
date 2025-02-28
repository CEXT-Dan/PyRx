#include "stdafx.h"
#include "PyAcadTable.h"
#include "PyAcadTableImpl.h"
#include "PyAcadEntityImpl.h"
#include "PyAcadObjectImpl.h"

using namespace boost::python;


//----------------------------------------------------------------------------------------
//PyAcadTable
void makePyAcadTableWrapper()
{
    PyDocString DS("AcadTable");
    class_<PyAcadTable, bases<PyAcadEntity>>("AcadTable", boost::python::no_init)
        .def("cast", &PyAcadTable::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadTable::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadTable::PyAcadTable(std::shared_ptr<PyIAcadTableImpl> ptr)
    : PyAcadEntity(ptr)
{
}

PyAcadTable PyAcadTable::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadTable>(src);
}

std::string PyAcadTable::className()
{
    return "AcadTable";
}

PyIAcadTableImpl* PyAcadTable::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadTableImpl*>(m_pyImp.get());
}