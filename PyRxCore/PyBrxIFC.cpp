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

//---------------------------------------------------------------------------------------- -
//PyIFCVectorValue
void makePyIFCVectorValueWrapper()
{
    PyDocString DS("IFCVectorValue");
    class_<PyIFCVectorValue>("IFCVectorValue", no_init)
        .def("className", &PyIFCVectorValue::className, DS.SARGS()).staticmethod("className")
        ;
}

PyIFCVectorValue::PyIFCVectorValue(const Ice::IfcApi::VectorValue& src)
    : PyIFCVectorValue(new Ice::IfcApi::VectorValue(src), true)
{
}

PyIFCVectorValue::PyIFCVectorValue(Ice::IfcApi::VectorValue* pObject, bool autoDelete)
    : m_pyImp(pObject, PySharedObjectDeleter<Ice::IfcApi::VectorValue>(autoDelete))
{
}

std::string PyIFCVectorValue::className()
{
    return "IFCVectorValue";
}

Ice::IfcApi::VectorValue* PyIFCVectorValue::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<Ice::IfcApi::VectorValue*>(m_pyImp.get());
}

//---------------------------------------------------------------------------------------- -
//PyIFCSelectorDesc
void makePyIFCSelectorDescWrapper()
{
    PyDocString DS("IFCSelectorDesc");
    class_<PyIFCSelectorDesc>("IFCSelectorDesc")
        .def("className", &PyIFCSelectorDesc::className, DS.SARGS()).staticmethod("className")
        ;
}

PyIFCSelectorDesc::PyIFCSelectorDesc()
    : PyIFCSelectorDesc(new Ice::IfcApi::SelectorDesc(), true)
{
}

PyIFCSelectorDesc::PyIFCSelectorDesc(Ice::IfcApi::SelectorDesc* pObject, bool autoDelete)
    : m_pyImp(pObject, PySharedObjectDeleter<Ice::IfcApi::SelectorDesc>(autoDelete))
{
}

std::string PyIFCSelectorDesc::className()
{
    return "IFCSelectorDesc";
}

Ice::IfcApi::SelectorDesc* PyIFCSelectorDesc::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<Ice::IfcApi::SelectorDesc*>(m_pyImp.get());
}

//---------------------------------------------------------------------------------------- -
//PyIFCSelectValue
void makePyIFCSelectValueWrapper()
{
    PyDocString DS("IFCSelectValue");
    class_<PyIFCSelectValue>("IFCSelectValue", no_init)
        .def("className", &PyIFCSelectValue::className, DS.SARGS()).staticmethod("className")
        ;
}

PyIFCSelectValue::PyIFCSelectValue(const Ice::IfcApi::SelectValue& src)
    : PyIFCSelectValue(new Ice::IfcApi::SelectValue(src), true)
{
}

PyIFCSelectValue::PyIFCSelectValue(Ice::IfcApi::SelectValue* pObject, bool autoDelete)
    : m_pyImp(pObject, PySharedObjectDeleter<Ice::IfcApi::SelectValue>(autoDelete))
{
}

std::string PyIFCSelectValue::className()
{
    return "IFCSelectValue";
}

Ice::IfcApi::SelectValue* PyIFCSelectValue::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<Ice::IfcApi::SelectValue*>(m_pyImp.get());
}


//---------------------------------------------------------------------------------------- -
//PyIFCEnumValue
void makePyIFCEnumValueWrapper()
{
    PyDocString DS("IFCEnumValue");
    class_<PyIFCEnumValue>("IFCEnumValue", no_init)
        .def("className", &PyIFCEnumValue::className, DS.SARGS()).staticmethod("className")
        ;
}

PyIFCEnumValue::PyIFCEnumValue(const Ice::IfcApi::EnumValue& src)
    : PyIFCEnumValue(new Ice::IfcApi::EnumValue(src), true)
{
}

PyIFCEnumValue::PyIFCEnumValue(Ice::IfcApi::EnumValue* pObject, bool autoDelete)
    : m_pyImp(pObject, PySharedObjectDeleter<Ice::IfcApi::EnumValue>(autoDelete))
{
}

std::string PyIFCEnumValue::className()
{
    return "IFCEnumValue";
}

Ice::IfcApi::EnumValue* PyIFCEnumValue::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<Ice::IfcApi::EnumValue*>(m_pyImp.get());
}

//---------------------------------------------------------------------------------------- -
//PyIFCEntityDesc
void makePyIFCEntityDescWrapper()
{
    PyDocString DS("IFCEntityDesc");
    class_<PyIFCEntityDesc>("IFCEntityDesc")
        .def("className", &PyIFCEntityDesc::className, DS.SARGS()).staticmethod("className")
        ;
}

PyIFCEntityDesc::PyIFCEntityDesc()
    : PyIFCEntityDesc(new Ice::IfcApi::EntityDesc(), true)
{
}

PyIFCEntityDesc::PyIFCEntityDesc(Ice::IfcApi::EntityDesc* pObject, bool autoDelete)
    : m_pyImp(pObject, PySharedObjectDeleter<Ice::IfcApi::EntityDesc>(autoDelete))
{
}

std::string PyIFCEntityDesc::className()
{
    return "IFCEntityDesc";
}

Ice::IfcApi::EntityDesc* PyIFCEntityDesc::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<Ice::IfcApi::EntityDesc*>(m_pyImp.get());
}

#endif