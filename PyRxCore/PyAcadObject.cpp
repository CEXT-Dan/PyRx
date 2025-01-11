#include "stdafx.h"
#include "PyAcadObject.h"

#ifdef PYRX_IN_PROGRESS_PYAX
#include "PyAcadObjectImpl.h"
using namespace boost::python;

void makePyAcadObjectWrapper()
{
    PyDocString DS("AcadObject");
    class_<PyAcadObject>("AcadObject", boost::python::no_init)
        .def_readonly("handle", &PyAcadObject::handle)
        .def("className", &PyAcadObject::className, DS.SARGS()).staticmethod("className")
        .def("cast", &PyAcadObject::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        ;
}

PyAcadObject::PyAcadObject(PyIAcadObjectImpl* ptr)
: m_pyImp(ptr)
{
}

PyAcadObject::PyAcadObject(const AcDbObjectId& id)
 : PyAcadObject(new PyIAcadObjectImpl(GetIAcadObjectFromAcDbObjectId(id)))
{
}

std::string PyAcadObject::handle() const
{
    return wstr_to_utf8(impObj()->GetHandle());
}

PyAcadObject PyAcadObject::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadObject>(src);
}

std::string PyAcadObject::className()
{
    return "AcDbObject";
}

PyIAcadObjectImpl* PyAcadObject::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadObjectImpl*>(m_pyImp.get());
}

#endif

