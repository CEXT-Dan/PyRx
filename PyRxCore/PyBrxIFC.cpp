#include "stdafx.h"
#include "PyBrxIFC.h"

#ifdef BRXAPP
using namespace boost::python;

//---------------------------------------------------------------------------------------- -
//PyIFCGuid
void makePyIFCGuidrapper()
{
    PyDocString DS("IFCGuid");
    class_<PyIFCGuid>("IFCGuid")
        .def("className", &PyIFCGuid::className, DS.SARGS()).staticmethod("className")
        ;
}

PyIFCGuid::PyIFCGuid()
  : PyIFCGuid(new Ice::IfcApi::Guid(),true)
{
}

PyIFCGuid::PyIFCGuid(Ice::IfcApi::Guid* pObject, bool autoDelete)
    : m_pyImp(pObject, PySharedObjectDeleter<Ice::IfcApi::Guid>(autoDelete))
{
}

std::string PyIFCGuid::className()
{
    return "Guid";
}

Ice::IfcApi::Guid* PyIFCGuid::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<Ice::IfcApi::Guid*>(m_pyImp.get());
}

#endif