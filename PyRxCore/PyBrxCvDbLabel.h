#pragma once

#ifdef BRXAPP
#if !defined(_BRXTARGET240)

#include "PyBrxCvObject.h"
#include "PyDbDate.h"

#include "BrxCvDbStylePartDisplaySettings.h" 
#include "BrxCvDbStyle.h"
#include "BrxCvDbLabelStyle.h"
#include "BrxCvDbLabelStyleArrow.h"
#include "BrxCvDbLabelStyleBlock.h"

class PyDbObjectId;

//-----------------------------------------------------------------------------------
//PyBrxCvDbStylePartDisplaySettings
void makeBrxCvDbStylePartDisplaySettingsWrapper();

class PyBrxCvDbStylePartDisplaySettings : public PyBrxCvDbSubObject
{
public:
    PyBrxCvDbStylePartDisplaySettings(BrxCvDbStylePartDisplaySettings* ptr, bool autoDelete);
    virtual ~PyBrxCvDbStylePartDisplaySettings() override = default;

    bool            isVisible() const;
    void            setVisible(bool value);
    AcCmColor       color() const;
    void            setColor(const AcCmColor& value);
    PyDbObjectId    layer() const;
    void            setLayer(const PyDbObjectId& value);
    PyDbObjectId    lineType() const;
    void            setLineType(const PyDbObjectId& value);
    double          lineTypeScale() const;
    void            setLineTypeScale(double value);
    AcDb::LineWeight lineWeight() const;
    void             setLineWeight(AcDb::LineWeight value);
    AcDb::PlotStyleNameType plotStyleNameType() const;
    void            setPlotStyleNameType(AcDb::PlotStyleNameType value);
    PyDbObjectId    plotStyleNameId() const;
    void            setPlotStyleNameId(const PyDbObjectId& value);

public:
    inline BrxCvDbStylePartDisplaySettings* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//PyBrxCvDbStyle
void makePyBrxCvDbStyleWrapper();

class PyBrxCvDbStyle : public PyBrxCvDbObject
{
    using DisplayOrientation = BrxCvDbStyle::DisplayOrientation;
    using ScalingType = BrxCvDbStyle::ScalingType;
    using OrientationRef = BrxCvDbStyle::OrientationRef;
public:
    PyBrxCvDbStyle(const PyDbObjectId& id);
    PyBrxCvDbStyle(BrxCvDbStyle* ptr, bool autoDelete);
    PyBrxCvDbStyle(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyBrxCvDbStyle(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    virtual ~PyBrxCvDbStyle() override = default;

    PyBrxCvDbStylePartDisplaySettings displaySetting(DisplayOrientation orientation, const std::string& partName) const;
    boost::python::list displaySettings(BrxCvDbLabelStyle::DisplayOrientation orientation) const;

    PyDbDate            createdDate() const;
    const std::string   createdBy() const;

    PyDbDate            lastEditedDate() const;
    const std::string   lastEditedBy() const;

    void                setCreatedBy(const std::string& value);

public:
    inline BrxCvDbStyle* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//makeBrxCvDbLabelStyleComponentWrapper
void makeBrxCvDbLabelStyleComponentWrapper();

class PyBrxCvDbLabelStyleComponent : public PyBrxCvDbSubObject
{
    using LabelAnchor = BrxCvDbLabelStyleComponent::LabelAnchor;
public:
    PyBrxCvDbLabelStyleComponent(BrxCvDbLabelStyleComponent* ptr, bool autoDelete);
    virtual ~PyBrxCvDbLabelStyleComponent() override = default;

    bool            isVisible() const;
    void            setVisible(bool isVisible);
    AcCmColor       color() const;
    void            setColor(const AcCmColor& value);
    Adesk::UInt32   anchorIndex() const;
    void            setAnchorIndex(Adesk::UInt32 index);
    LabelAnchor     anchorPoint() const;
    void            setAnchorPoint(LabelAnchor anchor);

public:
    inline BrxCvDbLabelStyleComponent* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//makeBrxCvDbLabelStyleArrowWrapper
void makeBrxCvDbLabelStyleArrowWrapper();

class PyBrxCvDbLabelStyleArrow : public PyBrxCvDbLabelStyleComponent
{
public:
    PyBrxCvDbLabelStyleArrow(BrxCvDbLabelStyleArrow* ptr, bool autoDelete);
    virtual ~PyBrxCvDbLabelStyleArrow() override = default;

    PyDbObjectId      arrowHeadStyle() const;
    void              setArrowHeadStyle(const PyDbObjectId& objId);

    double            arrowHeadSize() const;
    void              setArrowHeadSize(double size);
    Adesk::UInt32     arrowHeadSizeExprIndex() const;
    void              setArrowHeadSizeExprIndex(Adesk::UInt32 index);

    double            angle() const;
    void              setAngle(double radAngle);
    Adesk::UInt32     angleExprIndex() const;
    void              setAngleExprIndex(Adesk::UInt32 index);

    bool              isFixedLength() const;
    void              setFixedLength(bool isFixedLength);

    double            length() const;
    void              setLength(double length);
    Adesk::UInt32     lengthExprIndex() const;
    void              setLengthExprIndex(Adesk::UInt32 index);

    AcGeVector2d      offset() const;
    void              setOffset(const AcGeVector2d& offset);

    PyDbObjectId      linetype() const;
    void              setLinetype(const PyDbObjectId& objId);

    AcDb::LineWeight  lineweight() const;
    void              setLineweight(AcDb::LineWeight lineweight);

public:
    inline BrxCvDbLabelStyleArrow* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//makeBrxCvDbLabelStyleBlockWrapper
void makeBrxCvDbLabelStyleBlockWrapper();

class PyBrxCvDbLabelStyleBlock : public PyBrxCvDbLabelStyleComponent
{
public:
    PyBrxCvDbLabelStyleBlock(BrxCvDbLabelStyleBlock* ptr, bool autoDelete);
    virtual ~PyBrxCvDbLabelStyleBlock() override = default;

    PyDbObjectId      blockId() const;
    void              setBlockId(const AcDbObjectId& objId);

    double            height() const;
    void              setHeight(double height);
    Adesk::UInt32     heightExprIndex() const;
    void              setHeightExprIndex(Adesk::Int32 index);

    double            angle() const;
    void              setAngle(double radAngle);
    Adesk::UInt32     angleExprIndex() const;
    void              setAngleExprIndex(Adesk::Int32 index);

    BrxCvDbLabelStyleBlock::BlockAttachment   attachment() const;
    void              setAttachment(BrxCvDbLabelStyleBlock::BlockAttachment attachment);

    AcGeVector2d      offset() const;
    void              setOffset(const AcGeVector2d& offset);

    PyDbObjectId      linetype() const;
    void              setLinetype(const AcDbObjectId& objId);

    AcDb::LineWeight  lineweight() const;
    void              setLineweight(AcDb::LineWeight lineweight);

public:
    inline BrxCvDbLabelStyleBlock* impObj(const std::source_location& src = std::source_location::current()) const;
};

#endif

#endif//BRXAPP
