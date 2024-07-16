#pragma once

#ifdef BRXAPP
#include "IfcDefs.h"

//---------------------------------------------------------------------------------------- -
//PyIFCGuid
void makePyIFCGuidrapper();
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

#endif