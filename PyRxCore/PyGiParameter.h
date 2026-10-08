#pragma once
#include "PyRxObject.h"

#pragma pack(push, 8)

//-----------------------------------------------------------------------------------------
// PyGiParameter
void makePyGiParameterWrapper();
class PyGiParameter : public PyRxCopyOnWriteObject
{
public:
    PyGiParameter(AcGiParameter* ptr, bool autoDelete);
    virtual ~PyGiParameter() override = default;

    static PyRxClass desc();
    static std::string className();
    static PyGiParameter cast(const PyRxObject& src);

public:
    AcGiParameter* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
// PyGiEdgeData
void makePyGiEdgeDataWrapper();
class PyGiEdgeData : public PyGiParameter
{
public:
    PyGiEdgeData();
    PyGiEdgeData(AcGiEdgeData* ptr, bool autoDelete);
    virtual ~PyGiEdgeData() override = default;

    static PyRxClass desc();
    static std::string className();
    static PyGiEdgeData cast(const PyRxObject& src);

public:
    AcGiEdgeData* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
// PyGiFaceData
void makePyGiFaceDataWrapper();
class PyGiFaceData : public PyGiParameter
{
public:
    PyGiFaceData();
    PyGiFaceData(AcGiFaceData* ptr, bool autoDelete);
    virtual ~PyGiFaceData() override = default;

    static PyRxClass desc();
    static std::string className();
    static PyGiFaceData cast(const PyRxObject& src);

public:
    AcGiFaceData* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
// PyGiMapper
void makePyGiMapperWrapper();
class PyGiMapper : public PyGiParameter
{
public:
    PyGiMapper();
    PyGiMapper(AcGiMapper* ptr, bool autoDelete);
    virtual ~PyGiMapper() override = default;

    static PyRxClass desc();
    static std::string className();
    static PyGiMapper cast(const PyRxObject& src);

public:
    AcGiMapper* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
// PyGiPolyline
void makePyGiPolylineWrapper();
#if defined(_BRXTARGET270)
class PyGiPolyline : public PyRxObject
#else
class PyGiPolyline : public PyGiParameter
#endif
{
public:
    PyGiPolyline();
    PyGiPolyline(AcGiPolyline* ptr, bool autoDelete);
    virtual ~PyGiPolyline() override = default;

    static PyRxClass desc();
    static std::string className();
    static PyGiPolyline cast(const PyRxObject& src);

public:
    AcGiPolyline* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
// PyGiTextStyle
void makePyGiTextStyleWrapper();
class PyGiTextStyle : public PyGiParameter
{
public:
    PyGiTextStyle();
    PyGiTextStyle(const PyDbDatabase& db);

    PyGiTextStyle(
        const std::string& fontName,
        const std::string& bigFontName,
        const double textSize,
        const double xScale,
        const double obliqueAngle,
        const double trPercent,

        const Adesk::Boolean isBackward,
        const Adesk::Boolean isUpsideDown,
        const Adesk::Boolean isVertical,

        const Adesk::Boolean isOverlined,
        const Adesk::Boolean isUnderlined);


    PyGiTextStyle(
        const std::string& fontName,
        const std::string& bigFontName,
        const double textSize,
        const double xScale,
        const double obliqueAngle,
        const double trPercent,

        const Adesk::Boolean isBackward,
        const Adesk::Boolean isUpsideDown,
        const Adesk::Boolean isVertical,

        const Adesk::Boolean isOverlined,
        const Adesk::Boolean isUnderlined,
        const Adesk::Boolean isStrikethrough,

        const std::string& styleName);


    PyGiTextStyle(AcGiTextStyle* ptr, bool autoDelete);
    virtual ~PyGiTextStyle() override = default;

    static PyRxClass desc();
    static std::string className();
    static PyGiTextStyle cast(const PyRxObject& src);

public:
    AcGiTextStyle* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
// PyGiVertexData
void makePyGiVertexDataWrapper();
class PyGiVertexData : public PyGiParameter
{
public:
    PyGiVertexData();
    PyGiVertexData(AcGiVertexData* ptr, bool autoDelete);
    virtual ~PyGiVertexData() override = default;

    static PyRxClass desc();
    static std::string className();
    static PyGiVertexData cast(const PyRxObject& src);

public:
    AcGiVertexData* impObj(const std::source_location& src = std::source_location::current()) const;
};

#pragma pack(pop)
