#include "stdafx.h"
#include "PyBrxIfc.h"
#include "ifc/EntitiesList.h"

#ifdef BRXAPP
using namespace boost::python;

//---------------------------------------------------------------------------------------- -
//PyIfcGuid
void makePyIfcGuidWrapper()
{
    PyDocString DS("IfcGuid");
    class_<PyIfcGuid>("IfcGuid")
        .def("getText", &PyIfcGuid::getText, DS.ARGS())
        .def("getBase64", &PyIfcGuid::getBase64, DS.ARGS())
        .def("create", &PyIfcGuid::create, DS.SARGS()).staticmethod("create")
        .def("createFromBase64", &PyIfcGuid::createFromBase64, DS.SARGS({ "val: str" })).staticmethod("createFromBase64")
        .def("createFromText", &PyIfcGuid::createFromText, DS.SARGS({ "val: str" })).staticmethod("createFromText")
        .def("className", &PyIfcGuid::className, DS.SARGS()).staticmethod("className")
        ;
}

PyIfcGuid::PyIfcGuid()
    : PyIfcGuid(new Ice::IfcApi::Guid(), true)
{
}

PyIfcGuid::PyIfcGuid(Ice::IfcApi::Guid* pObject, bool autoDelete)
    : m_pyImp(pObject, PySharedObjectDeleter<Ice::IfcApi::Guid>(autoDelete))
{
}

PyIfcGuid::PyIfcGuid(const Ice::IfcApi::Guid& pObject)
    : PyIfcGuid(new Ice::IfcApi::Guid(pObject), true)
{
}

const std::string PyIfcGuid::getBase64() const
{
    return std::string{ impObj()->getBase64() };
}

const std::string PyIfcGuid::getText() const
{
    return std::string{ impObj()->getText() };
}

PyIfcGuid PyIfcGuid::create()
{
    return PyIfcGuid(Ice::IfcApi::Guid::create());
}

PyIfcGuid PyIfcGuid::createFromBase64(const std::string& base64)
{
    return PyIfcGuid(Ice::IfcApi::Guid::createFromBase64(base64.c_str()));
}

PyIfcGuid PyIfcGuid::createFromText(const std::string& text)
{
    return PyIfcGuid(Ice::IfcApi::Guid::createFromText(text.c_str()));
}

std::string PyIfcGuid::className()
{
    return "IfcGuid";
}

Ice::IfcApi::Guid* PyIfcGuid::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<Ice::IfcApi::Guid*>(m_pyImp.get());
}


//---------------------------------------------------------------------------------------- -
//PyIfcString
void makePyIfcStringWrapper()
{
    PyDocString DS("IfcString");
    class_<PyIfcString>("IfcString")
        .def("getEncoded", &PyIfcString::getEncoded, DS.ARGS())
        .def("c_str", &PyIfcString::c_str, DS.ARGS())
        .def("isEmpty", &PyIfcString::isEmpty, DS.ARGS())
        .def("setEmpty", &PyIfcString::setEmpty, DS.ARGS())
        .def("decode", &PyIfcString::decode, DS.SARGS({ "val: str" })).staticmethod("decode")
        .def("className", &PyIfcString::className, DS.SARGS()).staticmethod("className")
        ;
}

PyIfcString::PyIfcString()
    : PyIfcString(new Ice::IfcApi::String(), true)
{
}

PyIfcString::PyIfcString(Ice::IfcApi::String* pObject, bool autoDelete)
    : m_pyImp(pObject, PySharedObjectDeleter<Ice::IfcApi::String>(autoDelete))
{
}

PyIfcString::PyIfcString(const Ice::IfcApi::String& pObject)
    : PyIfcString(new Ice::IfcApi::String(pObject), true)
{
}

const std::string PyIfcString::getEncoded() const
{
    return std::string{ impObj()->getEncoded() };
}

const std::string PyIfcString::c_str() const
{
    return  wstr_to_utf8(impObj()->c_str());
}

bool PyIfcString::isEmpty() const
{
    return impObj()->isEmpty();
}

void PyIfcString::setEmpty()
{
    impObj()->setEmpty();
}

PyIfcString PyIfcString::decode(const std::string& encoded)
{
    return PyIfcString(Ice::IfcApi::String::decode(encoded.c_str()));
}

std::string PyIfcString::className()
{
    return "IfcString";
}

Ice::IfcApi::String* PyIfcString::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<Ice::IfcApi::String*>(m_pyImp.get());
}

//---------------------------------------------------------------------------------------- -
//PyIfcBinary
void makePyIfcBinaryWrapper()
{
    PyDocString DS("IfcBinary");
    class_<PyIfcBinary>("IfcBinary")
        .def("getEncodedString", &PyIfcBinary::getEncodedString)
        .def("reset", &PyIfcBinary::reset, DS.ARGS({ "val: str" }))
        .def("numBits", &PyIfcBinary::numBits, DS.ARGS())
        .def("getBit", &PyIfcBinary::getBit, DS.ARGS({ "val: int" }))
        .def("isEmpty", &PyIfcBinary::isEmpty, DS.ARGS())
        .def("resize", &PyIfcBinary::resize, DS.ARGS({ "val: int" }))
        .def("clear", &PyIfcBinary::clear, DS.ARGS())
        .def("className", &PyIfcBinary::className, DS.SARGS()).staticmethod("className")
        ;
}

PyIfcBinary::PyIfcBinary()
    : PyIfcBinary(new Ice::IfcApi::Binary(), true)
{
}

PyIfcBinary::PyIfcBinary(Ice::IfcApi::Binary* pObject, bool autoDelete)
    : m_pyImp(pObject, PySharedObjectDeleter<Ice::IfcApi::Binary>(autoDelete))
{
}

std::string PyIfcBinary::getEncodedString() const
{
    return std::string{ impObj()->getEncodedString() };
}

void PyIfcBinary::reset(const std::string& encodedStr)
{
    impObj()->reset(encodedStr.c_str());
}

size_t PyIfcBinary::numBits() const
{
    return impObj()->numBits();
}

bool PyIfcBinary::getBit(size_t i) const
{
    return impObj()->getBit(i);
}

bool PyIfcBinary::isEmpty() const
{
    return impObj()->isEmpty();
}

void PyIfcBinary::resize(size_t nBits)
{
    impObj()->resize(nBits);
}

void PyIfcBinary::clear()
{
    impObj()->clear();
}

std::string PyIfcBinary::className()
{
    return "IfcBinary";
}

Ice::IfcApi::Binary* PyIfcBinary::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<Ice::IfcApi::Binary*>(m_pyImp.get());
}

//---------------------------------------------------------------------------------------- -
//PyIfcLogical
void makePyIfcLogicalWrapper()
{
    PyDocString DS("IfcLogical");
    class_<PyIfcLogical>("IfcLogical")
        .def("isKnown", &PyIfcLogical::isKnown, DS.ARGS())
        .def("isUnknown", &PyIfcLogical::isUnknown, DS.ARGS())
        .def("className", &PyIfcLogical::className, DS.SARGS()).staticmethod("className")
        ;
}

PyIfcLogical::PyIfcLogical()
    : PyIfcLogical(new Ice::IfcApi::Logical(), true)
{
}

PyIfcLogical::PyIfcLogical(Ice::IfcApi::Logical* pObject, bool autoDelete)
    : m_pyImp(pObject, PySharedObjectDeleter<Ice::IfcApi::Logical>(autoDelete))
{
}

bool PyIfcLogical::isKnown() const
{
    return impObj()->isKnown();
}

bool PyIfcLogical::isUnknown() const
{
    return impObj()->isUnknown();
}

std::string PyIfcLogical::className()
{
    return "IfcLogical";
}

Ice::IfcApi::Logical* PyIfcLogical::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<Ice::IfcApi::Logical*>(m_pyImp.get());
}

//---------------------------------------------------------------------------------------- -
//PyIfcVectorDesc
void makePyIfcVectorDescWrapper()
{
    PyDocString DS("IfcVectorDesc");
    class_<PyIfcVectorDesc>("IfcVectorDesc")
        .def("className", &PyIfcVectorDesc::className, DS.SARGS()).staticmethod("className")
        ;
}

PyIfcVectorDesc::PyIfcVectorDesc()
    : PyIfcVectorDesc(new Ice::IfcApi::VectorDesc(), true)
{
}

PyIfcVectorDesc::PyIfcVectorDesc(Ice::IfcApi::VectorDesc* pObject, bool autoDelete)
    : m_pyImp(pObject, PySharedObjectDeleter<Ice::IfcApi::VectorDesc>(autoDelete))
{
}

std::string PyIfcVectorDesc::className()
{
    return "IfcVectorDesc";
}

Ice::IfcApi::VectorDesc* PyIfcVectorDesc::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<Ice::IfcApi::VectorDesc*>(m_pyImp.get());
}

//---------------------------------------------------------------------------------------- -
//PyIfcVectorValue
void makePyIfcVectorValueWrapper()
{
    PyDocString DS("IfcVectorValue");
    class_<PyIfcVectorValue>("IfcVectorValue", no_init)
        .def("add", &PyIfcVectorValue::add, DS.ARGS({ "val: PyBrxBim.IfcVariant" }))
        .def("size", &PyIfcVectorValue::size, DS.ARGS())
        .def("remove", &PyIfcVectorValue::remove, DS.ARGS({ "val: int" }))
        .def("clear", &PyIfcVectorValue::clear, DS.ARGS())
        .def("isNull", &PyIfcVectorValue::isNull, DS.ARGS())
        .def("values", &PyIfcVectorValue::values, DS.ARGS())
        .def("className", &PyIfcVectorValue::className, DS.SARGS()).staticmethod("className")
        ;
}

PyIfcVectorValue::PyIfcVectorValue(const Ice::IfcApi::VectorValue& src)
    : PyIfcVectorValue(new Ice::IfcApi::VectorValue(src), true)
{
}

PyIfcVectorValue::PyIfcVectorValue(Ice::IfcApi::VectorValue* pObject, bool autoDelete)
    : m_pyImp(pObject, PySharedObjectDeleter<Ice::IfcApi::VectorValue>(autoDelete))
{
}

Ice::IfcApi::Result PyIfcVectorValue::add(const PyIfcVariant& value)
{
    return impObj()->add(value.impObj());
}

unsigned int PyIfcVectorValue::size() const
{
    return impObj()->size();
}

bool PyIfcVectorValue::remove(unsigned int index)
{
    return impObj()->remove(index);
}

void PyIfcVectorValue::clear()
{
    impObj()->clear();
}

bool PyIfcVectorValue::isNull() const
{
    return impObj()->isNull();
}

boost::python::list PyIfcVectorValue::values() const
{
    PyAutoLockGIL lock;
    boost::python::list pylist;
    for (auto it = impObj()->begin(); it != impObj()->end(); ++it)
        pylist.append(PyIfcVariant(*it));
    return pylist;
}

std::string PyIfcVectorValue::className()
{
    return "IfcVectorValue";
}

Ice::IfcApi::VectorValue* PyIfcVectorValue::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<Ice::IfcApi::VectorValue*>(m_pyImp.get());
}

//---------------------------------------------------------------------------------------- -
//PyIfcSelectorDesc
void makePyIfcSelectorDescWrapper()
{
    PyDocString DS("IfcSelectorDesc");
    class_<PyIfcSelectorDesc>("IfcSelectorDesc")
        .def("className", &PyIfcSelectorDesc::className, DS.SARGS()).staticmethod("className")
        ;
}

PyIfcSelectorDesc::PyIfcSelectorDesc()
    : PyIfcSelectorDesc(new Ice::IfcApi::SelectorDesc(), true)
{
}

PyIfcSelectorDesc::PyIfcSelectorDesc(Ice::IfcApi::SelectorDesc* pObject, bool autoDelete)
    : m_pyImp(pObject, PySharedObjectDeleter<Ice::IfcApi::SelectorDesc>(autoDelete))
{
}

std::string PyIfcSelectorDesc::className()
{
    return "IfcSelectorDesc";
}

Ice::IfcApi::SelectorDesc* PyIfcSelectorDesc::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<Ice::IfcApi::SelectorDesc*>(m_pyImp.get());
}

//---------------------------------------------------------------------------------------- -
//PyIfcSelectValue
void makePyIfcSelectValueWrapper()
{
    PyDocString DS("IfcSelectValue");
    class_<PyIfcSelectValue>("IfcSelectValue", no_init)
        .def("getValue", &PyIfcSelectValue::getValue, DS.ARGS())
        .def("tag", &PyIfcSelectValue::tag, DS.ARGS())
        .def("setValue", &PyIfcSelectValue::tag, DS.ARGS({ "tag: str","val: PyBrxBim.IfcVariant" }))
        .def("isNull", &PyIfcSelectValue::isNull, DS.ARGS())
        .def("className", &PyIfcSelectValue::className, DS.SARGS()).staticmethod("className")
        ;
}

PyIfcSelectValue::PyIfcSelectValue(const Ice::IfcApi::SelectValue& src)
    : PyIfcSelectValue(new Ice::IfcApi::SelectValue(src), true)
{
}

PyIfcSelectValue::PyIfcSelectValue(Ice::IfcApi::SelectValue* pObject, bool autoDelete)
    : m_pyImp(pObject, PySharedObjectDeleter<Ice::IfcApi::SelectValue>(autoDelete))
{
}

PyIfcVariant PyIfcSelectValue::getValue() const
{
    return PyIfcVariant(impObj()->getValue());
}

std::string PyIfcSelectValue::tag() const
{
    return std::string(impObj()->tag());
}

Ice::IfcApi::Result PyIfcSelectValue::setValue(const std::string& tag, const PyIfcVariant& val)
{
    return impObj()->setValue(tag.c_str(), *val.impObj());
}

bool PyIfcSelectValue::isNull() const
{
    return impObj()->isNull();
}

std::string PyIfcSelectValue::className()
{
    return "IfcSelectValue";
}

Ice::IfcApi::SelectValue* PyIfcSelectValue::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<Ice::IfcApi::SelectValue*>(m_pyImp.get());
}


//---------------------------------------------------------------------------------------- -
//PyIfcEnumValue
void makePyIfcEnumValueWrapper()
{
    PyDocString DS("IfcEnumValue");
    class_<PyIfcEnumValue>("IfcEnumValue", no_init)
        .def("getValue", &PyIfcEnumValue::getValue, DS.ARGS())
        .def("setValue", &PyIfcEnumValue::setValue, DS.ARGS({ "val: str" }))
        .def("className", &PyIfcEnumValue::className, DS.SARGS()).staticmethod("className")
        ;
}

PyIfcEnumValue::PyIfcEnumValue(const Ice::IfcApi::EnumValue& src)
    : PyIfcEnumValue(new Ice::IfcApi::EnumValue(src), true)
{
}

PyIfcEnumValue::PyIfcEnumValue(Ice::IfcApi::EnumValue* pObject, bool autoDelete)
    : m_pyImp(pObject, PySharedObjectDeleter<Ice::IfcApi::EnumValue>(autoDelete))
{
}

std::string PyIfcEnumValue::getValue() const
{
    return std::string{ impObj()->getValue() };
}

void PyIfcEnumValue::setValue(const std::string& stringValue)
{
    impObj()->setValue(stringValue.c_str());
}

std::string PyIfcEnumValue::className()
{
    return "IfcEnumValue";
}

Ice::IfcApi::EnumValue* PyIfcEnumValue::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<Ice::IfcApi::EnumValue*>(m_pyImp.get());
}

//---------------------------------------------------------------------------------------- -
//PyIfcEntityDesc
void makePyIfcEntityDescWrapper()
{
    PyDocString DS("IfcEntityDesc");
    class_<PyIfcEntityDesc>("IfcEntityDesc")
        .def("isDerivedFrom", &PyIfcEntityDesc::isDerivedFrom, DS.ARGS({ "entDesc: PyBrxBim.IfcEntityDesc","eSchema: IfcSchemaId" }))
        .def("className", &PyIfcEntityDesc::className, DS.SARGS()).staticmethod("className")

        .add_static_property("IfcWindow", &PyIfcEntityDesc::_IfcWindow)
        ;
}

PyIfcEntityDesc::PyIfcEntityDesc()
    : PyIfcEntityDesc(new Ice::IfcApi::EntityDesc(), true)
{
}

PyIfcEntityDesc::PyIfcEntityDesc(Ice::IfcApi::EntityDesc* pObject, bool autoDelete)
    : m_pyImp(pObject, PySharedObjectDeleter<Ice::IfcApi::EntityDesc>(autoDelete))
{
}

PyIfcEntityDesc::PyIfcEntityDesc(const Ice::IfcApi::EntityDesc* pObject)
    : PyIfcEntityDesc(const_cast<Ice::IfcApi::EntityDesc*>(pObject), false)
{
}

#include "BrxSpecific/bim/ifc/IfcConstants.h"

bool PyIfcEntityDesc::isDerivedFrom(const PyIfcEntityDesc& obj, Ice::EIfcSchemaId eSchema) const
{
    return impObj()->isDerivedFrom(*obj.impObj(), eSchema);
}

PyIfcEntityDesc PyIfcEntityDesc::_IfcWindow()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcWindow));
}

std::string PyIfcEntityDesc::className()
{
    return "IfcEntityDesc";
}

Ice::IfcApi::EntityDesc* PyIfcEntityDesc::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<Ice::IfcApi::EntityDesc*>(m_pyImp.get());
}

//---------------------------------------------------------------------------------------- -
//PyIfcEntity
void makePyIfcEntityWrapper()
{
    PyDocString DS("IfcEntity");
    class_<PyIfcEntity>("IfcEntity")
        .def("IfcId", &PyIfcEntity::ifcId, DS.ARGS())
        .def("getAttribute", &PyIfcEntity::getAttribute, DS.ARGS({ "val: str" }))
        .def("setAttribute", &PyIfcEntity::setAttribute, DS.ARGS({ "val: str","attribValue: PyBrxBim.IfcVariant" }))
        .def("isA", &PyIfcEntity::isA, DS.ARGS())
        .def("isKindOf", &PyIfcEntity::isKindOf, DS.ARGS({ "val: PyBrxBim.IfcEntityDesc" }))
        .def("isNull", &PyIfcEntity::isNull, DS.ARGS())
        .def("getInverseRefs", &PyIfcEntity::getInverseRefs, DS.ARGS())
        .def("create", &PyIfcEntity::create, DS.SARGS()).staticmethod("create")
        .def("className", &PyIfcEntity::className, DS.SARGS()).staticmethod("className")
        ;
}

PyIfcEntity::PyIfcEntity()
    : PyIfcEntity(new Ice::IfcApi::Entity(), true)
{
}

PyIfcEntity::PyIfcEntity(const Ice::IfcApi::Entity& src)
    : PyIfcEntity(new Ice::IfcApi::Entity(src), true)
{
}

PyIfcEntity::PyIfcEntity(Ice::IfcApi::Entity* pObject, bool autoDelete)
    : m_pyImp(pObject, PySharedObjectDeleter<Ice::IfcApi::Entity>(autoDelete))
{
}

PyIfcEntity::PyIfcEntity(const Ice::IfcApi::Entity* src)
    :PyIfcEntity(const_cast<Ice::IfcApi::Entity*>(src), false)
{
}

int PyIfcEntity::ifcId() const
{
    return impObj()->ifcId();
}

PyIfcVariant PyIfcEntity::getAttribute(const std::string& attbName) const
{
    Ice::IfcApi::Variant attribValue;
    if (impObj()->getAttribute(attbName.c_str(), attribValue) != Ice::IfcApi::Result::eOk)
        PyThrowBadEs(eInvalidInput);
    return PyIfcVariant{ attribValue };
}

void PyIfcEntity::setAttribute(const std::string& attribName, const PyIfcVariant& attribValue)
{
    if (impObj()->setAttribute(attribName.c_str(), *attribValue.impObj()) != Ice::IfcApi::Result::eOk)
        PyThrowBadEs(eInvalidInput);
}

PyIfcEntityDesc PyIfcEntity::isA() const
{
    return PyIfcEntityDesc(impObj()->isA());
}

bool PyIfcEntity::isKindOf(const PyIfcEntityDesc& ent) const
{
    return impObj()->isKindOf(*ent.impObj());
}

bool PyIfcEntity::isNull() const
{
    return impObj()->isNull();
}

boost::python::list PyIfcEntity::getInverseRefs() const
{
    PyAutoLockGIL lock;
    boost::python::list pylist;
    for (const auto& item : impObj()->getInverseRefs())
        pylist.append(PyIfcEntity(item));
    return pylist;
}

PyIfcEntity PyIfcEntity::create(const PyIfcModel& model, const PyIfcEntityDesc& entityDesc)
{
    return PyIfcEntity(Ice::IfcApi::Entity::create(*model.impObj(), *entityDesc.impObj()));
}

std::string PyIfcEntity::className()
{
    return "IfcEntity";
}

Ice::IfcApi::Entity* PyIfcEntity::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<Ice::IfcApi::Entity*>(m_pyImp.get());
}

//---------------------------------------------------------------------------------------- -
//PyIfcHeader
void makePyIfcHeaderWrapper()
{
    PyDocString DS("IfcHeader");
    class_<PyIfcHeader>("IfcHeader")
        .def("fileDescription", &PyIfcHeader::fileDescription, DS.ARGS())
        .def("implementationLevel", &PyIfcHeader::implementationLevel, DS.ARGS())
        .def("fileName", &PyIfcHeader::fileName, DS.ARGS())
        .def("timeStamp", &PyIfcHeader::timeStamp, DS.ARGS())
        .def("author", &PyIfcHeader::author, DS.ARGS())
        .def("organization", &PyIfcHeader::organization, DS.ARGS())
        .def("preprocessorVersion", &PyIfcHeader::preprocessorVersion, DS.ARGS())
        .def("originatingSystem", &PyIfcHeader::originatingSystem, DS.ARGS())
        .def("authorization", &PyIfcHeader::authorization, DS.ARGS())
        .def("fileSchema", &PyIfcHeader::fileSchema, DS.ARGS())

        .def("setFileDescription", &PyIfcHeader::setFileDescription, DS.ARGS({ "val: PyBrxBim.IfcString" }))
        .def("setFileName", &PyIfcHeader::setFileName, DS.ARGS({ "val: PyBrxBim.IfcString" }))
        .def("setTimeStamp", &PyIfcHeader::setTimeStamp, DS.ARGS({ "val: PyBrxBim.IfcString" }))
        .def("setAuthor", &PyIfcHeader::setAuthor, DS.ARGS({ "val: PyBrxBim.IfcString" }))
        .def("setOrganization", &PyIfcHeader::setOrganization, DS.ARGS({ "val: PyBrxBim.IfcString" }))
        .def("setPreprocessorVersion", &PyIfcHeader::setPreprocessorVersion, DS.ARGS({ "val: PyBrxBim.IfcString" }))
        .def("setOriginatingSystem", &PyIfcHeader::setOriginatingSystem, DS.ARGS({ "val: PyBrxBim.IfcString" }))
        .def("setAuthorization", &PyIfcHeader::setAuthorization, DS.ARGS({ "val: PyBrxBim.IfcString" }))
        .def("setFileSchema", &PyIfcHeader::setFileSchema, DS.ARGS({ "val: PyBrxBim.IfcString" }))

        .def("className", &PyIfcHeader::className, DS.SARGS()).staticmethod("className")
        ;
}

PyIfcHeader::PyIfcHeader()
    : PyIfcHeader(new Ice::IfcApi::Header(), true)
{
}

PyIfcHeader::PyIfcHeader(Ice::IfcApi::Header* pObject, bool autoDelete)
    : m_pyImp(pObject, PySharedObjectDeleter<Ice::IfcApi::Header>(autoDelete))
{
}

PyIfcString PyIfcHeader::fileDescription() const
{
    return PyIfcString{ impObj()->fileDescription() };
}

PyIfcString PyIfcHeader::implementationLevel() const
{
    return PyIfcString{ impObj()->implementationLevel() };
}

void PyIfcHeader::setFileDescription(const PyIfcString& str)
{
    impObj()->setFileDescription(*str.impObj());
}

PyIfcString PyIfcHeader::fileName() const
{
    return PyIfcString{ impObj()->fileName() };
}

PyIfcString PyIfcHeader::timeStamp() const
{
    return PyIfcString{ impObj()->timeStamp() };
}

PyIfcString PyIfcHeader::author() const
{
    return PyIfcString{ impObj()->author() };
}

PyIfcString PyIfcHeader::organization() const
{
    return PyIfcString{ impObj()->organization() };
}

PyIfcString PyIfcHeader::preprocessorVersion() const
{
    return PyIfcString{ impObj()->preprocessorVersion() };
}

PyIfcString PyIfcHeader::originatingSystem() const
{
    return PyIfcString{ impObj()->originatingSystem() };
}

PyIfcString PyIfcHeader::authorization() const
{
    return PyIfcString{ impObj()->authorization() };
}

void PyIfcHeader::setFileName(const PyIfcString& str)
{
    impObj()->setFileName(*str.impObj());
}

void PyIfcHeader::setTimeStamp(const PyIfcString& str)
{
    impObj()->setTimeStamp(*str.impObj());
}

void PyIfcHeader::setAuthor(const PyIfcString& str)
{
    impObj()->setAuthor(*str.impObj());
}

void PyIfcHeader::setOrganization(const PyIfcString& str)
{
    impObj()->setOrganization(*str.impObj());
}

void PyIfcHeader::setPreprocessorVersion(const PyIfcString& str)
{
    impObj()->setPreprocessorVersion(*str.impObj());
}

void PyIfcHeader::setOriginatingSystem(const PyIfcString& str)
{
    impObj()->setOriginatingSystem(*str.impObj());
}

void PyIfcHeader::setAuthorization(const PyIfcString& str)
{
    impObj()->setAuthorization(*str.impObj());
}

void PyIfcHeader::setFileSchema(const PyIfcString& str)
{
    impObj()->setFileSchema(*str.impObj());
}

PyIfcString PyIfcHeader::fileSchema() const
{
    return PyIfcString{ impObj()->fileSchema() };
}

std::string PyIfcHeader::className()
{
    return "IfcHeader";
}

Ice::IfcApi::Header* PyIfcHeader::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<Ice::IfcApi::Header*>(m_pyImp.get());
}

//---------------------------------------------------------------------------------------- -
//PyIfcModel
void makePyIfcModelWrapper()
{
    PyDocString DS("IfcModel");
    class_<PyIfcModel>("IfcModel", no_init)
        .def("release", &PyIfcModel::release, DS.ARGS())
        .def("getNumEntities", &PyIfcModel::getNumEntities, DS.ARGS())
        .def("get", &PyIfcModel::get, DS.ARGS({ "val: int" }))
        .def("schemaId", &PyIfcModel::schemaId, DS.ARGS())
        .def("write", &PyIfcModel::write, DS.SARGS({ "val: str","val: PyBrxBim.IfcHeader" })).staticmethod("write")
        .def("read", &PyIfcModel::read, DS.SARGS({ "val: str" })).staticmethod("read")
        .def("className", &PyIfcModel::className, DS.SARGS()).staticmethod("className")
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

PyIfcModel::PyIfcModel(Ice::IfcApi::Model* pObject, bool autoDelete)
    : m_pyImp(pObject, PySharedModelDeleter<Ice::IfcApi::Model>(autoDelete))
{
}

void PyIfcModel::release()
{
    impObj()->release();
}

size_t PyIfcModel::getNumEntities() const
{
    return impObj()->getNumEntities();
}

PyIfcEntity PyIfcModel::get(size_t index) const
{
    return PyIfcEntity{ impObj()->get(index) };
}

Ice::EIfcSchemaId PyIfcModel::schemaId() const
{
    return impObj()->schemaId();
}

bool PyIfcModel::write(const std::string& fileName, const PyIfcHeader& header)
{
    return impObj()->write(utf8_to_wstr(fileName).c_str(), *header.impObj());
}

PyIfcModel PyIfcModel::create(Ice::EIfcSchemaId schemaId)
{
    return PyIfcModel(Ice::IfcApi::Model::create(schemaId), true);
}

PyIfcModel PyIfcModel::read(const std::string& fileName)
{
    return PyIfcModel(Ice::IfcApi::Model::read(utf8_to_wstr(fileName).c_str()), true);
}

std::string PyIfcModel::className()
{
    return "IfcModel";
}

Ice::IfcApi::Model* PyIfcModel::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<Ice::IfcApi::Model*>(m_pyImp.get());
}


//---------------------------------------------------------------------------------------- -
//PyIfcVariant
void makePyIfcVariantWrapper()
{
    PyDocString DS("IfcVariant");
    class_<PyIfcVariant>("IfcVariant")
        .def("className", &PyIfcVariant::className, DS.SARGS()).staticmethod("className")
        ;
}

PyIfcVariant::PyIfcVariant()
    : PyIfcVariant(new Ice::IfcApi::Variant(), true)
{
}

PyIfcVariant::PyIfcVariant(Ice::IfcApi::Variant* pObject, bool autoDelete)
    : m_pyImp(pObject, PySharedObjectDeleter<Ice::IfcApi::Variant>(autoDelete))
{
}

PyIfcVariant::PyIfcVariant(const Ice::IfcApi::Variant& pObject)
    : PyIfcVariant(new Ice::IfcApi::Variant(pObject), true)
{
}

std::string PyIfcVariant::className()
{
    return "IfcVariant";
}

Ice::IfcApi::Variant* PyIfcVariant::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<Ice::IfcApi::Variant*>(m_pyImp.get());
}

#endif