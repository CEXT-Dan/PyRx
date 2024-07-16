#include "stdafx.h"
#include "PyBrxIFC.h"

#ifdef BRXAPP
using namespace boost::python;

//---------------------------------------------------------------------------------------- -
//PyIFCGuid
void makePyIFCGuidWrapper()
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
    return "IFCGuid";
}

Ice::IfcApi::Guid* PyIFCGuid::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<Ice::IfcApi::Guid*>(m_pyImp.get());
}


//---------------------------------------------------------------------------------------- -
//PyIFCString
void makePyIFCStringWrapper()
{
    PyDocString DS("IFCString");
    class_<PyIFCString>("IFCString")
        .def("className", &PyIFCString::className, DS.SARGS()).staticmethod("className")
        ;
}

PyIFCString::PyIFCString()
    : PyIFCString(new Ice::IfcApi::String(), true)
{
}

PyIFCString::PyIFCString(Ice::IfcApi::String* pObject, bool autoDelete)
    : m_pyImp(pObject, PySharedObjectDeleter<Ice::IfcApi::String>(autoDelete))
{
}

std::string PyIFCString::className()
{
    return "IFCString";
}

Ice::IfcApi::String* PyIFCString::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<Ice::IfcApi::String*>(m_pyImp.get());
}

//---------------------------------------------------------------------------------------- -
//PyIFCBinary
void makePyIFCBinaryWrapper()
{
    PyDocString DS("IFCBinary");
    class_<PyIFCBinary>("IFCBinary")
        .def("className", &PyIFCBinary::className, DS.SARGS()).staticmethod("className")
        ;
}

PyIFCBinary::PyIFCBinary()
    : PyIFCBinary(new Ice::IfcApi::Binary(), true)
{
}

PyIFCBinary::PyIFCBinary(Ice::IfcApi::Binary* pObject, bool autoDelete)
    : m_pyImp(pObject, PySharedObjectDeleter<Ice::IfcApi::Binary>(autoDelete))
{
}

std::string PyIFCBinary::className()
{
    return "IFCBinary";
}

Ice::IfcApi::Binary* PyIFCBinary::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<Ice::IfcApi::Binary*>(m_pyImp.get());
}

//---------------------------------------------------------------------------------------- -
//PyIFCLogical
void makePyIFCLogicalWrapper()
{
    PyDocString DS("IFCLogical");
    class_<PyIFCLogical>("IFCLogical")
        .def("className", &PyIFCLogical::className, DS.SARGS()).staticmethod("className")
        ;
}

PyIFCLogical::PyIFCLogical()
    : PyIFCLogical(new Ice::IfcApi::Logical(), true)
{
}

PyIFCLogical::PyIFCLogical(Ice::IfcApi::Logical* pObject, bool autoDelete)
    : m_pyImp(pObject, PySharedObjectDeleter<Ice::IfcApi::Logical>(autoDelete))
{
}

std::string PyIFCLogical::className()
{
    return "IFCLogical";
}

Ice::IfcApi::Logical* PyIFCLogical::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<Ice::IfcApi::Logical*>(m_pyImp.get());
}

//---------------------------------------------------------------------------------------- -
//PyIFCVectorDesc
void makePyIFCVectorDescWrapper()
{
    PyDocString DS("IFCVectorDesc");
    class_<PyIFCVectorDesc>("IFCVectorDesc")
        .def("className", &PyIFCVectorDesc::className, DS.SARGS()).staticmethod("className")
        ;
}

PyIFCVectorDesc::PyIFCVectorDesc()
    : PyIFCVectorDesc(new Ice::IfcApi::VectorDesc(), true)
{
}

PyIFCVectorDesc::PyIFCVectorDesc(Ice::IfcApi::VectorDesc* pObject, bool autoDelete)
    : m_pyImp(pObject, PySharedObjectDeleter<Ice::IfcApi::VectorDesc>(autoDelete))
{
}

std::string PyIFCVectorDesc::className()
{
    return "IFCVectorDesc";
}

Ice::IfcApi::VectorDesc* PyIFCVectorDesc::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<Ice::IfcApi::VectorDesc*>(m_pyImp.get());
}

#endif
