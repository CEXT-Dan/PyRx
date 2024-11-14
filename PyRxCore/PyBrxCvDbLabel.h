#pragma once

#ifdef BRXAPP
#if !defined(_BRXTARGET240)

#include "PyBrxCvObject.h"
#include "PyDbDate.h"

#include "BrxCvDbStylePartDisplaySettings.h" 
#include "BrxCvDbStyle.h"
#include "BrxCvDbLabelStyleComponent.h"
#include "BrxCvDbLabelStyle.h"
#include "BrxCvDbLabelStyleArrow.h"
#include "BrxCvDbLabelStyleBlock.h"
#include "BrxCvDbLabelStyleLine.h"
#include "BrxCvDbLabelStyleText.h"

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
    BrxCvDbStylePartDisplaySettings* impObj(const std::source_location& src = std::source_location::current()) const;
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
    BrxCvDbStyle* impObj(const std::source_location& src = std::source_location::current()) const;
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
    BrxCvDbLabelStyleComponent* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//makeBrxCvDbLabelStyleWrapper
void makeBrxCvDbLabelStyleWrapper();

class PyBrxCvDbLabelStyle : public PyBrxCvDbStyle
{
    using LeaderType = BrxCvDbLabelStyle::LeaderType;
    using BorderType = BrxCvDbLabelStyle::BorderType;
    using LeaderAttachment = BrxCvDbLabelStyle::LeaderAttachment;
    using DisplayMode = BrxCvDbLabelStyle::DisplayMode;
    using ForcedInsertion = BrxCvDbLabelStyle::ForcedInsertion;
public:
    PyBrxCvDbLabelStyle();
    PyBrxCvDbLabelStyle(bool metric);
    PyBrxCvDbLabelStyle(const PyDbObjectId& id);
    PyBrxCvDbLabelStyle(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyBrxCvDbLabelStyle(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);

    PyBrxCvDbLabelStyle(BrxCvDbLabelStyle* ptr, bool autoDelete);
    virtual ~PyBrxCvDbLabelStyle() override = default;

    boost::python::list components() const;
    PyBrxCvDbLabelStyleComponent componentAt(Adesk::UInt32 index) const;
    PyBrxCvDbLabelStyleComponent component(const std::string& name) const;

    Adesk::UInt32     componentCount() const;

    void              addComponent(const PyBrxCvDbLabelStyleComponent& pComponent);
    void              removeComponent_1(const PyBrxCvDbLabelStyleComponent& pComponent);
    void              removeComponent_2(Adesk::UInt32 index); 
    void              moveComponent(Adesk::UInt32 fromIndex, Adesk::UInt32 toIndex);

    PyDbObjectId      textStyle() const;
    void              setTextStyle(const PyDbObjectId& objId);

    bool              isVisible() const;
    void              setVisibility(bool isVisible);

    PyDbObjectId      layer() const;
    void              setLayer(const PyDbObjectId& objId);

    BrxCvDbStyle::OrientationRef    orientationReference() const;
    void              setOrientationReference(BrxCvDbStyle::OrientationRef ref);

    ForcedInsertion   forcedInsertion() const;
    void              setForcedInsertion(ForcedInsertion value);

    double            readabilityBias() const;
    void              setReadabilityBias(double radAngle);

    bool              planReadable() const;
    void              setPlanReadable(bool isPlanReadable);

    bool              flipAnchorsWithText() const;
    void              setFlipAnchorsWithText(bool flipAnchors);

    bool              forceInsideCurve() const;
    void              setForceInsideCurve(bool forceInside);

    Adesk::UInt32     expressionCount() const;
    boost::python::tuple  expressionAt(Adesk::UInt32 index) const;
    void              setExpressionAt(Adesk::UInt32 index, const std::string& name, const std::string& expr, BrxCvDataType type);

    PyDbObjectId      draggedStateLeaderArrowHeadStyle() const;
    void              setDraggedStateLeaderArrowHeadStyle(const PyDbObjectId& objId);

    double            draggedStateLeaderArrowHeadSize() const;
    void              setDraggedStateLeaderArrowHeadSize(double size);
    Adesk::UInt32     draggedStateLeaderArrowHeadSizeExprIndex() const;
    void              setDraggedStateLeaderArrowHeadSizeExprIndex(Adesk::UInt32 index);

    bool              draggedStateLeaderIsVisible() const;
    void              setDraggedStateLeaderVisibility(bool isVisible);

    LeaderType        draggedStateLeaderType() const;
    void              setDraggedStateLeaderType(LeaderType type);

    AcCmColor         draggedStateLeaderColor() const;
    void              setDraggedStateLeaderColor(const AcCmColor& color);

    PyDbObjectId      draggedStateLeaderLinetype() const;
    void              setDraggedStateLeaderLinetype(const PyDbObjectId& objId);

    AcDb::LineWeight  draggedStateLeaderLineweight() const;
    void              setDraggedStateLeaderLineweight(AcDb::LineWeight lineweight);

    LeaderAttachment  draggedStateLeaderAttachment() const;
    void              setDraggedStateLeaderAttachment(LeaderAttachment value);

    bool              draggedStateLeaderJustification() const;
    void              setDraggedStateLeaderJustification(bool justifyLeader);

    bool              draggedStateLeaderTail() const;
    void              setDraggedStateLeaderTail(bool useTail);

    DisplayMode       draggedStateDisplayMode() const;
    void              setDraggedStateDisplayMode(DisplayMode mode);

    bool              draggedStateBorderIsVisible() const;
    void              setDraggedStateBorderVisibility(bool isVisible);

    BorderType        draggedStateBorderType() const;
    void              setDraggedStateBorderType(BorderType type);

    bool              draggedStateBackgroundMask() const;
    void              setDraggedStateBackgroundMask(bool useMask);

    double            draggedStateBorderAndLeaderGap() const;
    void              setDraggedStateBorderAndLeaderGap(double value);
    Adesk::UInt32     draggedStateBorderAndLeaderGapExprIndex() const;
    void              setDraggedStateBorderAndLeaderGapExprIndex(Adesk::UInt32 index);

    double            draggedStateTextHeight() const;
    void              setDraggedStateTextHeight(double height);
    Adesk::UInt32     draggedStateTextHeightExprIndex() const;
    void              setDraggedStateTextHeightExprIndex(Adesk::UInt32 index);

    bool              draggedStateTagDisplayMode() const;
    void              setDraggedStateTagDisplayMode(bool displayTag);

    AcCmColor         draggedStateColor() const;
    void              setDraggedStateColor(const AcCmColor& color);

    PyDbObjectId      draggedStateLinetype() const;
    void              setDraggedStateLinetype(const PyDbObjectId& objId);

    AcDb::LineWeight  draggedStateLineweight() const;
    void              setDraggedStateLineweight(AcDb::LineWeight lineweight);

    double            draggedStateMaximumTextWidth() const;
    void              setDraggedStateMaximumTextWidth(double maxWidth);
    Adesk::UInt32     draggedStateMaximumTextWidthExprIndex() const;
    void              setDraggedStateMaximumTextWidthExprIndex(Adesk::UInt32 index);

public:
    BrxCvDbLabelStyle* impObj(const std::source_location& src = std::source_location::current()) const;
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
    BrxCvDbLabelStyleArrow* impObj(const std::source_location& src = std::source_location::current()) const;
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
    BrxCvDbLabelStyleBlock* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//makeBrxCvDbLabelStyleLineWrapper
void makeBrxCvDbLabelStyleLineWrapper();

class PyBrxCvDbLabelStyleLine : public PyBrxCvDbLabelStyleComponent
{
    using LengthType = BrxCvDbLabelStyleLine::LengthType;
public:
    PyBrxCvDbLabelStyleLine(BrxCvDbLabelStyleLine* ptr, bool autoDelete);
    virtual ~PyBrxCvDbLabelStyleLine() override = default;

    bool              useEndPointAnchor() const;
    void              setUseEndPointAnchor(bool useEndPoint);

    Adesk::UInt32     endPointAnchorIndex() const;
    void              setEndPointAnchorIndex(Adesk::Int32 index);

    BrxCvDbLabelStyleLine::LabelAnchor       endPointAnchorPoint() const;
    void              setEndPointAnchorPoint(BrxCvDbLabelStyleLine::LabelAnchor anchor);

    double            angle() const;
    void              setAngle(double radAngle);
    Adesk::UInt32     angleExprIndex() const;
    void              setAngleExprIndex(Adesk::Int32 index);

    double            length() const;
    void              setLength(double length);
    Adesk::UInt32     lengthExprIndex() const;
    void              setLengthExprIndex(Adesk::Int32 index);

    AcGeVector2d      startPointOffset() const;
    void              setStartPointOffset(const AcGeVector2d& offset);

    AcGeVector2d      endPointOffset() const;
    void              setEndPointOffset(const AcGeVector2d& offset);

    LengthType        lengthType() const;
    void              setLengthType(BrxCvDbLabelStyleLine::LengthType type);

    double            lengthPercentage() const;
    void              setLengthPercentage(double pct);
    Adesk::UInt32     lengthPercentageExprIndex() const;
    void              setLengthPercentageExprIndex(Adesk::Int32 index);

    PyDbObjectId      linetype() const;
    void              setLinetype(const PyDbObjectId& objId);

    AcDb::LineWeight  lineweight() const;
    void              setLineweight(AcDb::LineWeight lineweight);

public:
    BrxCvDbLabelStyleLine* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//makeBrxCvDbLabelStyleTextWrapper
void makeBrxCvDbLabelStyleTextWrapper();

class PyBrxCvDbLabelStyleText : public PyBrxCvDbLabelStyleComponent
{
public:
    PyBrxCvDbLabelStyleText(BrxCvDbLabelStyleText* ptr, bool autoDelete);
    virtual ~PyBrxCvDbLabelStyleText() override = default;

    std::string                   contents() const;
    void                          setContents(const std::string& contents);

    double                        textHeight() const;
    void                          setTextHeight(double height);
    Adesk::UInt32                 textHeightExprIndex() const;
    void                          setTextHeightExprIndex(Adesk::UInt32 index);

    double                        textAngle() const;
    void                          setTextAngle(double radAngle);
    Adesk::UInt32                 textAngleExprIndex() const;
    void                          setTextAngleExprIndex(Adesk::UInt32 index);

    AcDbMText::AttachmentPoint    textAttachment() const;
    void                          setTextAttachment(AcDbMText::AttachmentPoint attachment);

    AcGeVector2d                  textOffset() const;
    void                          setTextOffset(const AcGeVector2d& offset);

    PyDbObjectId                  textLinetype() const;
    void                          setTextLinetype(const PyDbObjectId& objId);

    AcDb::LineWeight              textLineweight() const;
    void                          setTextLineweight(AcDb::LineWeight lineweight);

    double                        textMaximumWidth() const;
    void                          setTextMaximumWidth(double maxWidth);
    Adesk::UInt32                 textMaximumWidthExprIndex() const;
    void                          setTextMaximumWidthExprIndex(Adesk::UInt32 index);

    bool                          allowCurvedText() const;
    void                          setAllowCurvedText(bool allowCurved);

    bool                          borderIsVisible() const;
    void                          setBorderVisibility(bool isVisible);

    BrxCvDbLabelStyle::BorderType borderType() const;
    void                          setBorderType(BrxCvDbLabelStyle::BorderType type);

    bool                          borderBackgroudMask() const;
    void                          setBorderBackgroudMask(bool useMask);

    double                        borderGap() const;
    void                          setBorderGap(double value);
    Adesk::UInt32                 borderGapExprIndex() const;
    void                          setBorderGapExprIndex(Adesk::UInt32 index);

    AcCmColor                     borderColor() const;
    void                          setBorderColor(const AcCmColor& color);

    PyDbObjectId                  borderLinetype() const;
    void                          setBorderLinetype(const PyDbObjectId& objId);

    AcDb::LineWeight              borderLineweight() const;
    void                          setBorderLineweight(AcDb::LineWeight lineweight);

    AcDb::TextHorzMode            textHorizontalAlignment() const;
    void                          setTextHorizontalAlignment(AcDb::TextHorzMode alignment);

public:
    BrxCvDbLabelStyleText* impObj(const std::source_location& src = std::source_location::current()) const;
};

#endif

#endif//BRXAPP
