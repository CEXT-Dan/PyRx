#include "stdafx.h"
#include "PyBrxCvDbTinSurface.h"

#ifdef BRXAPP
using namespace boost::python;
//-----------------------------------------------------------------------------------
//PyBrxCvDbTinSurfaceDefinition
void makePyBrxCvDbTinSurfaceDefinitionWrapper()
{
    PyDocString DS("CvDbSubObject");
    class_<PyBrxCvDbTinSurfaceDefinition, bases<PyBrxCvDbSubObject>>("CvDbTinSurfaceDefinition", boost::python::no_init)

        .def("name", &PyBrxCvDbTinSurfaceDefinition::name, DS.ARGS())
        .def("setName", &PyBrxCvDbTinSurfaceDefinition::setName, DS.ARGS({ "val : str" }))
        .def("description", &PyBrxCvDbTinSurfaceDefinition::description, DS.ARGS())
        .def("setDescription", &PyBrxCvDbTinSurfaceDefinition::setDescription, DS.ARGS({ "val : str" }))
        .def("type", &PyBrxCvDbTinSurfaceDefinition::type, DS.ARGS())
        .def("isUpdateNeeded", &PyBrxCvDbTinSurfaceDefinition::isUpdateNeeded, DS.ARGS())
        .def("isSubDefinition", &PyBrxCvDbTinSurfaceDefinition::isSubDefinition, DS.ARGS())
        .def("isValid", &PyBrxCvDbTinSurfaceDefinition::isValid, DS.ARGS())
        .def("isEnabled", &PyBrxCvDbTinSurfaceDefinition::isEnabled, DS.ARGS())
        .def("setEnabled", &PyBrxCvDbTinSurfaceDefinition::setEnabled, DS.ARGS({ "val : bool" }))
        .def("isReadOnly", &PyBrxCvDbTinSurfaceDefinition::isReadOnly, DS.ARGS())
        .def("setReadOnly", &PyBrxCvDbTinSurfaceDefinition::setReadOnly, DS.ARGS({ "val : bool" }))
        .def("id", &PyBrxCvDbTinSurfaceDefinition::id, DS.ARGS())
      
        .def("className", &PyBrxCvDbTinSurfaceDefinition::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrxCvDbTinSurfaceDefinition::desc, DS.SARGS()).staticmethod("desc")
        .def("cast", &PyBrxCvDbTinSurfaceDefinition::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyBrxCvDbTinSurfaceDefinition::PyBrxCvDbTinSurfaceDefinition(BrxCvDbTinSurfaceDefinition* ptr, bool autoDelete)
    :PyBrxCvDbSubObject(ptr, autoDelete)
{
}

std::string PyBrxCvDbTinSurfaceDefinition::name() const
{
    return wstr_to_utf8(impObj()->name());
}

bool PyBrxCvDbTinSurfaceDefinition::setName(const std::string& szName)
{
    return impObj()->setName(utf8_to_wstr(szName).c_str());
}

std::string PyBrxCvDbTinSurfaceDefinition::description() const
{
    return wstr_to_utf8(impObj()->description());
}

bool PyBrxCvDbTinSurfaceDefinition::setDescription(const std::string& szDescription)
{
    return impObj()->setDescription(utf8_to_wstr(szDescription).c_str());
}

PyBrxCvDbTinSurfaceDefinition::EType PyBrxCvDbTinSurfaceDefinition::type() const
{
    return impObj()->type();
}

bool PyBrxCvDbTinSurfaceDefinition::isUpdateNeeded() const
{
    return impObj()->isUpdateNeeded();
}

bool PyBrxCvDbTinSurfaceDefinition::isSubDefinition() const
{
    return impObj()->isSubDefinition();
}

bool PyBrxCvDbTinSurfaceDefinition::isValid() const
{
    return impObj()->isValid();
}

bool PyBrxCvDbTinSurfaceDefinition::isEnabled() const
{
    return impObj()->isEnabled();
}

bool PyBrxCvDbTinSurfaceDefinition::setEnabled(const bool enabled)
{
    return impObj()->setEnabled(enabled);
}

bool PyBrxCvDbTinSurfaceDefinition::isReadOnly() const
{
    return impObj()->isReadOnly();
}

bool PyBrxCvDbTinSurfaceDefinition::setReadOnly(const bool readOnly)
{
    return impObj()->setReadOnly(readOnly);
}

Adesk::UInt64 PyBrxCvDbTinSurfaceDefinition::id() const
{
    return impObj()->id();
}

std::string PyBrxCvDbTinSurfaceDefinition::className()
{
    return "BrxCvDbTinSurfaceDefinition";
}

PyRxClass PyBrxCvDbTinSurfaceDefinition::desc()
{
    return PyRxClass(BrxCvDbTinSurfaceDefinition::desc(), false);
}

PyBrxCvDbTinSurfaceDefinition PyBrxCvDbTinSurfaceDefinition::cast(const PyRxObject& src)
{
    PyBrxCvDbTinSurfaceDefinition dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

BrxCvDbTinSurfaceDefinition* PyBrxCvDbTinSurfaceDefinition::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<BrxCvDbTinSurfaceDefinition*>(m_pyImp.get());
}

#endif //BRXAPP
