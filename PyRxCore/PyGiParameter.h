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
    int loadStyleRec1() const;
    int loadStyleRec2(PyDbDatabase& pDb) const;
    void setTextSize(const double size) const;
    void setXScale(const double xScale) const;
    void setObliquingAngle(const double obliquingAngle) const;
    void setTrackingPercent(const double trPercent) const;
    void setBackward(const Adesk::Boolean isBackward) const;
    void setUpsideDown(const Adesk::Boolean isUpsideDown) const;
    void setVertical(const Adesk::Boolean isVertical) const;
    void setUnderlined(const Adesk::Boolean isUnderlined) const;
    void setOverlined(const Adesk::Boolean isOverlined) const;
    void setStrikethrough(const Adesk::Boolean isStrikethrough) const;
    void setFileName(const std::string& fontName) const;
    void setBigFontFileName(const std::string& bigFontFileName) const;
    void setStyleName(const std::string& val) const;
    void setPreLoaded(bool val) const;
    void setTrackKerning(double trackPercent) const;

    double textSize() const;
    double xScale() const;
    double obliquingAngle() const;
    double trackingPercent() const;
    Adesk::Boolean isBackward() const;
    Adesk::Boolean isUpsideDown() const;
    Adesk::Boolean isVertical() const;
    Adesk::Boolean isUnderlined() const;
    Adesk::Boolean isOverlined() const;
    Adesk::Boolean isStrikethrough() const;
    bool preLoaded() const;
    std::string fileName() const;
    std::string bigFontFileName() const;
    std::string styleName() const;

    AcGePoint2d extents1(const std::string& pStr, const Adesk::Boolean penups, const int len, const Adesk::Boolean raw) const;
    AcGePoint2d extents2(const std::string& pStr, const Adesk::Boolean penups, const int len, const Adesk::Boolean raw, const PyGiWorldDraw& ctxt) const;

    void setFont(const std::string& pTypeface,
        Adesk::Boolean bold,
        Adesk::Boolean italic,
        Charset charset,
        Autodesk::AutoCAD::PAL::FontUtils::FontPitch pitch,
        Autodesk::AutoCAD::PAL::FontUtils::FontFamily family) const;

    boost::python::tuple font() const;

    boost::python::tuple extentsBox1(const std::string& pStr,
        const Adesk::Boolean penups,
        const int len,
        const Adesk::Boolean raw) const;

    boost::python::tuple extentsBox2(const std::string& pStr,
        const Adesk::Boolean penups,
        const int len,
        const Adesk::Boolean raw,
        PyGiWorldDraw& ctxt) const;

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
