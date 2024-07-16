#pragma once

#ifdef BRXAPP
#include "IfcDefs.h"

//---------------------------------------------------------------------------------------- -
//PyIFCGuid
void makePyIFCGuidWrapper();
class PyIFCGuid
{
public:
    PyIFCGuid();
    PyIFCGuid(Ice::IfcApi::Guid* pObject, bool autoDelete);
    ~PyIFCGuid() = default;

    static std::string      className();
public:
    Ice::IfcApi::Guid*      impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<Ice::IfcApi::Guid> m_pyImp;
};

//---------------------------------------------------------------------------------------- -
//PyIFCString
void makePyIFCStringWrapper();
class PyIFCString
{
public:
    PyIFCString();
    PyIFCString(Ice::IfcApi::String* pObject, bool autoDelete);
    ~PyIFCString() = default;

    static std::string  className();
public:
    Ice::IfcApi::String*  impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<Ice::IfcApi::String> m_pyImp;
};

//---------------------------------------------------------------------------------------- -
//PyIFCBinary
void makePyIFCBinaryWrapper();
class PyIFCBinary
{
public:
    PyIFCBinary();
    PyIFCBinary(Ice::IfcApi::Binary* pObject, bool autoDelete);
    ~PyIFCBinary() = default;

    static std::string  className();
public:
    Ice::IfcApi::Binary* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<Ice::IfcApi::Binary> m_pyImp;
};

//---------------------------------------------------------------------------------------- -
//PyIFCLogical
void makePyIFCLogicalWrapper();
class PyIFCLogical
{
public:
    PyIFCLogical();
    PyIFCLogical(Ice::IfcApi::Logical* pObject, bool autoDelete);
    ~PyIFCLogical() = default;

    static std::string  className();
public:
    Ice::IfcApi::Logical* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<Ice::IfcApi::Logical> m_pyImp;
};

//---------------------------------------------------------------------------------------- -
//PyIFCVectorDesc
void makePyIFCVectorDescWrapper();
class PyIFCVectorDesc
{
public:
    PyIFCVectorDesc();
    PyIFCVectorDesc(Ice::IfcApi::VectorDesc* pObject, bool autoDelete);
    ~PyIFCVectorDesc() = default;

    static std::string  className();
public:
    Ice::IfcApi::VectorDesc* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<Ice::IfcApi::VectorDesc> m_pyImp;
};


#endif