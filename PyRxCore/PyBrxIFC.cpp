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
        .def("getText", &PyIFCGuid::getText, DS.ARGS())
        .def("getBase64", &PyIFCGuid::getBase64, DS.ARGS())
        .def("create", &PyIFCGuid::create, DS.SARGS()).staticmethod("create")
        .def("createFromBase64", &PyIFCGuid::createFromBase64, DS.SARGS({ "val: str" })).staticmethod("createFromBase64")
        .def("createFromText", &PyIFCGuid::createFromText, DS.SARGS({ "val: str" })).staticmethod("createFromText")
        .def("className", &PyIFCGuid::className, DS.SARGS()).staticmethod("className")
        ;
}

PyIFCGuid::PyIFCGuid()
    : PyIFCGuid(new Ice::IfcApi::Guid(), true)
{
}

PyIFCGuid::PyIFCGuid(Ice::IfcApi::Guid* pObject, bool autoDelete)
    : m_pyImp(pObject, PySharedObjectDeleter<Ice::IfcApi::Guid>(autoDelete))
{
}

PyIFCGuid::PyIFCGuid(const Ice::IfcApi::Guid& pObject)
    : PyIFCGuid(new Ice::IfcApi::Guid(pObject), true)
{
}

const std::string PyIFCGuid::getBase64() const
{
    return std::string{ impObj()->getBase64() };
}

const std::string PyIFCGuid::getText() const
{
    return std::string{ impObj()->getText() };
}

PyIFCGuid PyIFCGuid::create()
{
    return PyIFCGuid(Ice::IfcApi::Guid::create());
}

PyIFCGuid PyIFCGuid::createFromBase64(const std::string& base64)
{
   return PyIFCGuid(Ice::IfcApi::Guid::createFromBase64(base64.c_str()));
}

PyIFCGuid PyIFCGuid::createFromText(const std::string& text)
{
    return PyIFCGuid(Ice::IfcApi::Guid::createFromText(text.c_str()));
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
        .def("getEncoded", &PyIFCString::getEncoded, DS.ARGS())
        .def("c_str", &PyIFCString::c_str, DS.ARGS())
        .def("isEmpty", &PyIFCString::isEmpty, DS.ARGS())
        .def("setEmpty", &PyIFCString::setEmpty, DS.ARGS())
        .def("decode", &PyIFCString::decode, DS.SARGS({ "val: str" })).staticmethod("decode")
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

PyIFCString::PyIFCString(const Ice::IfcApi::String& pObject)
    : PyIFCString(new Ice::IfcApi::String(pObject),true)
{
}

const std::string PyIFCString::getEncoded() const
{
    return std::string{ impObj()->getEncoded() };
}

const std::string PyIFCString::c_str() const
{
    return  wstr_to_utf8(impObj()->c_str());
}

bool PyIFCString::isEmpty() const
{
    return impObj()->isEmpty();
}

void PyIFCString::setEmpty()
{
    impObj()->setEmpty();
}

PyIFCString PyIFCString::decode(const std::string& encoded)
{
    return PyIFCString(Ice::IfcApi::String::decode(encoded.c_str()));
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
        .def("getEncodedString", &PyIFCBinary::getEncodedString)
        .def("reset", &PyIFCBinary::reset, DS.ARGS({ "val: str" }))
        .def("numBits", &PyIFCBinary::numBits, DS.ARGS())
        .def("getBit", &PyIFCBinary::getBit, DS.ARGS({ "val: int" }))
        .def("isEmpty", &PyIFCBinary::isEmpty, DS.ARGS())
        .def("resize", &PyIFCBinary::resize, DS.ARGS({ "val: int" }))
        .def("clear", &PyIFCBinary::clear, DS.ARGS())
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

std::string PyIFCBinary::getEncodedString() const
{
    return std::string{ impObj()->getEncodedString() };
}

void PyIFCBinary::reset(const std::string& encodedStr)
{
    impObj()->reset(encodedStr.c_str());
}

size_t PyIFCBinary::numBits() const
{
    return impObj()->numBits();
}

bool PyIFCBinary::getBit(size_t i) const
{
    return impObj()->getBit(i);
}

bool PyIFCBinary::isEmpty() const
{
    return impObj()->isEmpty();
}

void PyIFCBinary::resize(size_t nBits)
{
    impObj()->resize(nBits);
}

void PyIFCBinary::clear()
{
    impObj()->clear();
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
        .def("isKnown", &PyIFCLogical::isKnown, DS.ARGS())
        .def("isUnknown", &PyIFCLogical::isUnknown, DS.ARGS())
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

bool PyIFCLogical::isKnown() const
{
    return impObj()->isKnown();
}

bool PyIFCLogical::isUnknown() const
{
    return impObj()->isUnknown();
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

Ice::IfcApi::Result PyIFCVectorValue::add(const PyIFCVariant& value)
{
    return impObj()->add(value.impObj());
}

unsigned int PyIFCVectorValue::size() const
{
    return impObj()->size();
}

bool PyIFCVectorValue::remove(unsigned int index)
{
    return impObj()->remove(index);
}

void PyIFCVectorValue::clear()
{
    impObj()->clear();
}

bool PyIFCVectorValue::isNull() const
{
    return impObj()->isNull();
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

//---------------------------------------------------------------------------------------- -
//PyIFCEntity
void makePyIFCEntityWrapper()
{
    PyDocString DS("IFCEntity");
    class_<PyIFCEntity>("IFCEntity", no_init)
        .def("className", &PyIFCEntity::className, DS.SARGS()).staticmethod("className")
        ;
}

PyIFCEntity::PyIFCEntity(const Ice::IfcApi::Entity& src)
    : PyIFCEntity(new Ice::IfcApi::Entity(src), true)
{
}

PyIFCEntity::PyIFCEntity(Ice::IfcApi::Entity* pObject, bool autoDelete)
    : m_pyImp(pObject, PySharedObjectDeleter<Ice::IfcApi::Entity>(autoDelete))
{
}

std::string PyIFCEntity::className()
{
    return "IFCEntity";
}

Ice::IfcApi::Entity* PyIFCEntity::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<Ice::IfcApi::Entity*>(m_pyImp.get());
}

//---------------------------------------------------------------------------------------- -
//PyIFCHeader
void makePyIFCHeaderWrapper()
{
    PyDocString DS("IFCHeader");
    class_<PyIFCHeader>("IFCHeader")
        .def("className", &PyIFCHeader::className, DS.SARGS()).staticmethod("className")
        ;
}

PyIFCHeader::PyIFCHeader()
    : PyIFCHeader(new Ice::IfcApi::Header(), true)
{
}

PyIFCHeader::PyIFCHeader(Ice::IfcApi::Header* pObject, bool autoDelete)
    : m_pyImp(pObject, PySharedObjectDeleter<Ice::IfcApi::Header>(autoDelete))
{
}

std::string PyIFCHeader::className()
{
    return "IFCHeader";
}

Ice::IfcApi::Header* PyIFCHeader::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<Ice::IfcApi::Header*>(m_pyImp.get());
}

//---------------------------------------------------------------------------------------- -
//PyIFCModel
void makePyIFCModelWrapper()
{
    PyDocString DS("IFCModel");
    class_<PyIFCModel>("IFCModel", no_init)
        .def("className", &PyIFCModel::className, DS.SARGS()).staticmethod("className")
        ;
}

template<typename T>
struct PySharedModelDeleter
{
    inline PySharedModelDeleter(bool autoDelete)
        : m_autoDelete(autoDelete)
    {
    }

    inline void operator()(T* p) const
    {
        if (!m_autoDelete)
            return;
        if (p != nullptr)
            p->release();
    }
    bool m_autoDelete = true;
};

PyIFCModel::PyIFCModel(Ice::IfcApi::Model* pObject, bool autoDelete)
    : m_pyImp(pObject, PySharedModelDeleter<Ice::IfcApi::Model>(autoDelete))
{
}

std::string PyIFCModel::className()
{
    return "IFCModel";
}

Ice::IfcApi::Model* PyIFCModel::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<Ice::IfcApi::Model*>(m_pyImp.get());
}


//---------------------------------------------------------------------------------------- -
//PyIFCVariant
void makePyIFCVariantWrapper()
{

}

PyIFCVariant::PyIFCVariant()
    : PyIFCVariant(new Ice::IfcApi::Variant(), true)
{
}

PyIFCVariant::PyIFCVariant(Ice::IfcApi::Variant* pObject, bool autoDelete)
    : m_pyImp(pObject, PySharedObjectDeleter<Ice::IfcApi::Variant>(autoDelete))
{
}

std::string PyIFCVariant::className()
{
    return "IFCVariant";
}

Ice::IfcApi::Variant* PyIFCVariant::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<Ice::IfcApi::Variant*>(m_pyImp.get());
}

#endif