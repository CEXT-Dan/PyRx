#pragma once

#ifdef BRXAPP
#include "IfcDefs.h"

class PyIfcVariant;
class PyIfcModel;
enum class Ice::IfcApi::Result;


//---------------------------------------------------------------------------------------- -
//PyIfcGuid
void makePyIfcGuidWrapper();
class PyIfcGuid
{
public:
    PyIfcGuid();
    PyIfcGuid(Ice::IfcApi::Guid* pObject, bool autoDelete);
    PyIfcGuid(const Ice::IfcApi::Guid& pObject);
    ~PyIfcGuid() = default;
    const std::string   getBase64() const;
    const std::string   getText() const;

    static PyIfcGuid    create();
    static PyIfcGuid    createFromBase64(const std::string& base64);
    static PyIfcGuid    createFromText(const std::string& text);

    static std::string  className();
public:
    Ice::IfcApi::Guid* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<Ice::IfcApi::Guid> m_pyImp;
};

//---------------------------------------------------------------------------------------- -
//PyIfcString
void makePyIfcStringWrapper();
class PyIfcString
{
public:
    PyIfcString();
    PyIfcString(const Ice::IfcApi::String& pObject);
    PyIfcString(Ice::IfcApi::String* pObject, bool autoDelete);
    ~PyIfcString() = default;

    const std::string   getEncoded() const;
    const std::string   c_str() const;
    bool                isEmpty() const;
    void                setEmpty();
    static PyIfcString  decode(const std::string& encoded);

    static std::string  className();
public:
    Ice::IfcApi::String* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<Ice::IfcApi::String> m_pyImp;
};

//---------------------------------------------------------------------------------------- -
//PyIfcBinary
void makePyIfcBinaryWrapper();
class PyIfcBinary
{
public:
    PyIfcBinary();
    PyIfcBinary(const Ice::IfcApi::Binary& other);
    PyIfcBinary(Ice::IfcApi::Binary* pObject, bool autoDelete);
    ~PyIfcBinary() = default;

    std::string     getEncodedString() const;
    void            reset(const std::string& encodedStr);
    size_t          numBits() const;
    bool            getBit(size_t i) const;
    bool            isEmpty() const;
    void            resize(size_t nBits);
    void            clear();

    static std::string  className();
public:
    Ice::IfcApi::Binary* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<Ice::IfcApi::Binary> m_pyImp;
};

//---------------------------------------------------------------------------------------- -
//PyIfcLogical
void makePyIfcLogicalWrapper();
class PyIfcLogical
{
public:
    PyIfcLogical();
    PyIfcLogical(const Ice::IfcApi::Logical& other);
    PyIfcLogical(Ice::IfcApi::Logical* pObject, bool autoDelete);
    ~PyIfcLogical() = default;

    bool        isKnown() const;
    bool        isUnknown() const;

    static std::string  className();
public:
    Ice::IfcApi::Logical* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<Ice::IfcApi::Logical> m_pyImp;
};

//---------------------------------------------------------------------------------------- -
//PyIfcVectorDesc
void makePyIfcVectorDescWrapper();
class PyIfcVectorDesc
{
public:
    PyIfcVectorDesc();
    PyIfcVectorDesc(Ice::IfcApi::VectorDesc* pObject, bool autoDelete);
    ~PyIfcVectorDesc() = default;

    static std::string  className();
public:
    Ice::IfcApi::VectorDesc* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<Ice::IfcApi::VectorDesc> m_pyImp;
};

//---------------------------------------------------------------------------------------- -
//PyIfcVectorValue
void makePyIfcVectorValueWrapper();
class PyIfcVectorValue
{
public:
    PyIfcVectorValue(const Ice::IfcApi::VectorValue& src);
    PyIfcVectorValue(Ice::IfcApi::VectorValue* pObject, bool autoDelete);
    ~PyIfcVectorValue() = default;

    Ice::IfcApi::Result add(const PyIfcVariant& value);
    unsigned int        size() const;
    bool                remove(unsigned int index);
    void                clear();
    bool                isNull() const;
    boost::python::list values() const;

    static std::string  className();
public:
    Ice::IfcApi::VectorValue* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<Ice::IfcApi::VectorValue> m_pyImp;
};

//---------------------------------------------------------------------------------------- -
//PyIfcSelectorDesc
void makePyIfcSelectorDescWrapper();
class PyIfcSelectorDesc
{
public:
    PyIfcSelectorDesc();
    PyIfcSelectorDesc(Ice::IfcApi::SelectorDesc* pObject, bool autoDelete);
    ~PyIfcSelectorDesc() = default;

    static std::string  className();
public:
    Ice::IfcApi::SelectorDesc* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<Ice::IfcApi::SelectorDesc> m_pyImp;
};

//---------------------------------------------------------------------------------------- -
//PyIfcSelectValue
void makePyIfcSelectValueWrapper();
class PyIfcSelectValue
{
public:
    PyIfcSelectValue(const Ice::IfcApi::SelectValue& src);
    PyIfcSelectValue(Ice::IfcApi::SelectValue* pObject, bool autoDelete);
    ~PyIfcSelectValue() = default;

    PyIfcVariant        getValue() const;
    std::string         tag() const;
    Ice::IfcApi::Result setValue(const std::string& tag, const PyIfcVariant& val);
    bool                isNull() const;

    static std::string  className();
public:
    Ice::IfcApi::SelectValue* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<Ice::IfcApi::SelectValue> m_pyImp;
};

//---------------------------------------------------------------------------------------- -
//PyIfcEnumValue
void makePyIfcEnumValueWrapper();
class PyIfcEnumValue
{
public:
    PyIfcEnumValue(const Ice::IfcApi::EnumValue& src);
    PyIfcEnumValue(Ice::IfcApi::EnumValue* pObject, bool autoDelete);
    ~PyIfcEnumValue() = default;

    std::string  getValue() const;
    void         setValue(const std::string& stringValue);

    static std::string  className();
public:
    Ice::IfcApi::EnumValue* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<Ice::IfcApi::EnumValue> m_pyImp;
};

//---------------------------------------------------------------------------------------- -
//PyIfcEntityDesc
void makePyIfcEntityDescWrapper();
class PyIfcEntityDesc
{
public:
    PyIfcEntityDesc();
    PyIfcEntityDesc(const Ice::IfcApi::EntityDesc* pObject);
    PyIfcEntityDesc(Ice::IfcApi::EntityDesc* pObject, bool autoDelete);
    ~PyIfcEntityDesc() = default;
    bool isDerivedFrom(const PyIfcEntityDesc& obj, Ice::EIfcSchemaId eSchema) const;

    static PyIfcEntityDesc _IfcWindow();

    static std::string  className();
public:
    Ice::IfcApi::EntityDesc* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<Ice::IfcApi::EntityDesc> m_pyImp;
};

//---------------------------------------------------------------------------------------- -
//PyIfcEntity
void makePyIfcEntityWrapper();
class PyIfcEntity
{
public:
    PyIfcEntity();
    PyIfcEntity(const Ice::IfcApi::Entity& src);
    PyIfcEntity(const Ice::IfcApi::Entity* src);
    PyIfcEntity(Ice::IfcApi::Entity* pObject, bool autoDelete);
    ~PyIfcEntity() = default;

    int             ifcId() const;
    PyIfcVariant    getAttribute(const std::string& attbName) const;
    void            setAttribute(const std::string& attribName, const PyIfcVariant& attribValue);
    PyIfcEntityDesc isA() const;
    bool            isKindOf(const PyIfcEntityDesc& ent) const;
    bool            isNull() const;
    boost::python::list getInverseRefs() const;

    static PyIfcEntity  create(const PyIfcModel& model, const PyIfcEntityDesc& entityDesc);

    static std::string  className();
public:
    Ice::IfcApi::Entity* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<Ice::IfcApi::Entity> m_pyImp;
};

//---------------------------------------------------------------------------------------- -
//PyIfcHeader
void makePyIfcHeaderWrapper();
class PyIfcHeader
{
public:
    PyIfcHeader();
    PyIfcHeader(Ice::IfcApi::Header* pObject, bool autoDelete);
    ~PyIfcHeader() = default;

    PyIfcString fileDescription() const;
    PyIfcString implementationLevel() const;
    PyIfcString fileName() const;
    PyIfcString timeStamp() const;
    PyIfcString author() const;
    PyIfcString organization() const;
    PyIfcString preprocessorVersion() const;
    PyIfcString originatingSystem() const;
    PyIfcString authorization() const;
    PyIfcString fileSchema() const;

    void setFileDescription(const PyIfcString& str);
    void setFileName(const PyIfcString& str);
    void setTimeStamp(const PyIfcString& str);
    void setAuthor(const PyIfcString& str);
    void setOrganization(const PyIfcString& str);
    void setPreprocessorVersion(const PyIfcString& str);
    void setOriginatingSystem(const PyIfcString& str);
    void setAuthorization(const PyIfcString& str);
    void setFileSchema(const PyIfcString& str);

    static std::string  className();
public:
    Ice::IfcApi::Header* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<Ice::IfcApi::Header> m_pyImp;
};


//---------------------------------------------------------------------------------------- -
//PyIfcModel
void makePyIfcModelWrapper();
class PyIfcModel
{
public:

    PyIfcModel(Ice::IfcApi::Model* pObject, bool autoDelete);
    ~PyIfcModel() = default;

    void                release();
    size_t              getNumEntities() const;
    PyIfcEntity         get(size_t index) const;
    Ice::EIfcSchemaId   schemaId() const;
    bool                write(const std::string& fileName, const PyIfcHeader& header);

    static PyIfcModel   create(Ice::EIfcSchemaId schemaId);
    static PyIfcModel   read(const std::string& fileName);

    static std::string  className();
public:
    Ice::IfcApi::Model* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<Ice::IfcApi::Model> m_pyImp;
};


//---------------------------------------------------------------------------------------- -
//PyIfcVariant
void makePyIfcVariantWrapper();
class PyIfcVariant
{
public:
    PyIfcVariant();
    PyIfcVariant(const Ice::IfcApi::Variant& pObject);
    PyIfcVariant(Ice::IfcApi::Variant* pObject, bool autoDelete);
    ~PyIfcVariant() = default;

    int                     getInt() const;
    void                    setInt(int val);

    bool                    getBool() const;
    void                    setBool(bool val);

    unsigned                getUInt() const;
    void                    setUInt(unsigned val);

    double                  getReal() const;
    void                    setReal(double val);

    PyIfcString             getString() const;
    void                    setString(const PyIfcString& val);

    PyIfcEntity             getEntity() const;
    void                    setEntity(const PyIfcEntity& val);

    PyIfcLogical            getLogical() const;
    void                    setLogical(const PyIfcLogical& val);

    PyIfcBinary             getBinary() const;
    void                    setBinary(const PyIfcBinary& val);

    PyIfcGuid               getGuid() const;
    void                    setGuid(const PyIfcGuid& val);

    PyIfcVectorValue        getVector() const;
    void                    setVector(const PyIfcVectorValue& val);

    PyIfcSelectValue        getSelect() const;
    void                    setSelect(const PyIfcSelectValue& val);

    PyIfcEnumValue          getEnum() const;
    void                    setEnum(const PyIfcEnumValue& val);

    Ice::IfcApi::ValueType  type() const;

    static std::string  className();
public:
    Ice::IfcApi::Variant* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<Ice::IfcApi::Variant> m_pyImp;
};

#endif