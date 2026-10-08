#pragma once
#include "PyRxObject.h"

#pragma pack(push, 8)

void makePyGiParameterWrapper();

//-----------------------------------------------------------------------------------------
// PyRxCopyOnWriteObject
class PyRxCopyOnWriteObject : public PyRxObject
{
public:
    PyRxCopyOnWriteObject(AcRxCopyOnWriteObject* ptr, bool autoDelete);
    virtual ~PyRxCopyOnWriteObject() override = default;

    static PyRxClass desc();
    static std::string className();
    static PyRxCopyOnWriteObject cast(const PyRxObject& src);

    AcRxCopyOnWriteObject* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
// PyGiParameter
class PyGiParameter : public PyRxCopyOnWriteObject
{
public:
    PyGiParameter(AcGiParameter* ptr, bool autoDelete);
    virtual ~PyGiParameter() override = default;

    static PyRxClass desc();
    static std::string className();
    static PyGiParameter cast(const PyRxObject& src);

    AcGiParameter* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
// PyGiEdgeData
class PyGiEdgeData : public PyGiParameter
{
public:
    PyGiEdgeData();
    PyGiEdgeData(AcGiEdgeData* ptr, bool autoDelete);
    virtual ~PyGiEdgeData() override = default;

    static PyRxClass desc();
    static std::string className();
    static PyGiEdgeData cast(const PyRxObject& src);

    AcGiEdgeData* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
// PyGiFaceData
class PyGiFaceData : public PyGiParameter
{
public:
    PyGiFaceData();
    PyGiFaceData(AcGiFaceData* ptr, bool autoDelete);
    virtual ~PyGiFaceData() override = default;

    static PyRxClass desc();
    static std::string className();
    static PyGiFaceData cast(const PyRxObject& src);

    AcGiFaceData* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
// PyGiMapper
class PyGiMapper : public PyGiParameter
{
public:
    PyGiMapper();
    PyGiMapper(AcGiMapper* ptr, bool autoDelete);
    virtual ~PyGiMapper() override = default;

    static PyRxClass desc();
    static std::string className();
    static PyGiMapper cast(const PyRxObject& src);

    AcGiMapper* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
// PyGiPolyline
class PyGiPolyline : public PyGiParameter
{
public:
    PyGiPolyline();
    PyGiPolyline(AcGiPolyline* ptr, bool autoDelete);
    virtual ~PyGiPolyline() override = default;

    static PyRxClass desc();
    static std::string className();
    static PyGiPolyline cast(const PyRxObject& src);

    AcGiPolyline* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
// PyGiTextStyle
class PyGiTextStyle : public PyGiParameter
{
public:
    PyGiTextStyle();
    PyGiTextStyle(AcGiTextStyle* ptr, bool autoDelete);
    virtual ~PyGiTextStyle() override = default;

    static PyRxClass desc();
    static std::string className();
    static PyGiTextStyle cast(const PyRxObject& src);

    AcGiTextStyle* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
// PyGiVertexData
class PyGiVertexData : public PyGiParameter
{
public:
    PyGiVertexData();
    PyGiVertexData(AcGiVertexData* ptr, bool autoDelete);
    virtual ~PyGiVertexData() override = default;

    static PyRxClass desc();
    static std::string className();
    static PyGiVertexData cast(const PyRxObject& src);

    AcGiVertexData* impObj(const std::source_location& src = std::source_location::current()) const;
};

#pragma pack(pop)
