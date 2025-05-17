#pragma once
#include "PyDbEntity.h"
#include "PyDbMtext.h"

#pragma pack (push, 8)
class PyDbObjectId;
void makePyDbMTextWrapper();
class PyDbMText : public PyDbEntity
{
public:
    PyDbMText();
    PyDbMText(AcDbMText* ptr, bool autoDelete);
    PyDbMText(const PyDbObjectId& id);
    PyDbMText(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbMText(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    virtual ~PyDbMText() override = default;
    AcGePoint3d         location() const;
    void                setLocation(const AcGePoint3d& val) const;
    AcGeVector3d        normal() const;
    void                setNormal(const AcGeVector3d& val) const;
    AcGeVector3d        direction() const;
    void                setDirection(const AcGeVector3d&) const;
    double              rotation() const;
    void                setRotation(double val) const;
    double              width() const;
    void                setWidth(double) const;
    double              ascent() const;
    double              descent() const;
    PyDbObjectId        textStyle() const;
    void                setTextStyle(const PyDbObjectId& val) const;
    double              textHeight() const;
    void                setTextHeight(double val) const;
    AcDbMText::AttachmentPoint attachment() const;
    void                setAttachment(AcDbMText::AttachmentPoint val) const;
    void                setAttachmentMovingLocation(AcDbMText::AttachmentPoint val) const;
    AcDbMText::FlowDirection       flowDirection() const;
    void                setFlowDirection(AcDbMText::FlowDirection) const;
    std::string         contents() const;
    int                 setContents(const std::string& str) const;
    std::string         contentsRTF() const;
    int                 setContentsRTF(const std::string& str) const;
    std::string         text() const;
    double              actualHeight() const;
    double              actualWidth() const;
    int                 correctSpelling() const;
    boost::python::list getBoundingPoints() const;
    boost::python::list getBoundingPointsByLine() const;
    bool                hitTest(const AcGePoint3d& ptHit) const;
    void                setLineSpacingStyle(AcDb::LineSpacingStyle eStyle) const;
    AcDb::LineSpacingStyle lineSpacingStyle() const;
    void                setLineSpacingFactor(double dFactor) const;
    double              lineSpacingFactor() const;
    bool                backgroundFillOn() const;
    void                setBackgroundFill(bool enable) const;
    AcCmColor           getBackgroundFillColor() const;
    void                setBackgroundFillColor(const AcCmColor& color) const;
    double              getBackgroundScaleFactor() const;
    void                setBackgroundScaleFactor(const double scale) const;
    AcCmTransparency    getBackgroundTransparency() const;
    void                setBackgroundTransparency(const AcCmTransparency& transp) const;
    bool                useBackgroundColorOn() const;
    void                setUseBackgroundColor(bool enable) const;
    void                setDynamicColumns(double width, double gutter, bool auto_height) const;
    void                setStaticColumns(double width, double gutter, int count) const;
    AcDbMText::ColumnType getColumnType() const;
    void                setColumnType(AcDbMText::ColumnType val) const;
    bool                getColumnAutoHeight() const;
    void                setColumnAutoHeight(bool val) const;
    int                 getColumnCount() const;
    void                setColumnCount(int val) const;
    double              getColumnWidth() const;
    void                setColumnWidth(double val) const;
    double              getColumnGutterWidth() const;
    void                setColumnGutterWidth(double val) const;
    bool                getColumnFlowReversed() const;
    void                setColumnFlowReversed(bool val) const;
    double              getColumnHeight(int val) const;
    void                setColumnHeight(int, double val) const;
    void                convertFieldToText() const;
    double              height() const;
    void                setHeight(double val) const;
    boost::python::list getFragments() const;
    static std::string  className();
    static PyRxClass    desc();
    static PyDbMText    cloneFrom(const PyRxObject& src);
    static PyDbMText    cast(const PyRxObject& src);
public:
    AcDbMText* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//PyDbText
void makePyDbTextWrapper();
class PyDbText : public PyDbEntity
{
public:
    PyDbText();
    PyDbText(const AcGePoint3d& position, const std::string& text);
    PyDbText(const AcGePoint3d& position, const std::string& text, PyDbObjectId& style, double height, double rotation);
    PyDbText(AcDbText* ptr, bool autoDelete);
    PyDbText(const PyDbObjectId& id);
    PyDbText(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbText(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    virtual ~PyDbText() override = default;
    AcGePoint3d         position() const;
    void                setPosition(const AcGePoint3d& val) const;
    AcGePoint3d         alignmentPoint() const;
    void                setAlignmentPoint(const AcGePoint3d& val) const;
    Adesk::Boolean      isDefaultAlignment() const;
    AcGeVector3d        normal() const;
    void                setNormal(const AcGeVector3d& val) const;
    AcGeVector3d        direction() const;
    double              thickness() const;
    void                setThickness(double) const;
    double              oblique() const;
    void                setOblique(double) const;
    double              rotation() const;
    void                setRotation(double val) const;
    double              height() const;
    void                setHeight(double val) const;
    double              widthFactor() const;
    void                setWidthFactor(double val) const;
    std::string         textString() const;
    void                setTextString(const std::string& val) const;
    PyDbObjectId        textStyle() const;
    void                setTextStyle(const PyDbObjectId& val) const;
    Adesk::Boolean      isMirroredInX() const;
    void                mirrorInX(Adesk::Boolean val) const;
    Adesk::Boolean      isMirroredInY() const;
    void                mirrorInY(Adesk::Boolean val) const;
    AcDb::TextHorzMode  horizontalMode() const;
    void                setHorizontalMode(AcDb::TextHorzMode val) const;
    AcDb::TextVertMode  verticalMode() const;
    void                setVerticalMode(AcDb::TextVertMode val) const;
    int                 correctSpelling() const;
    void                adjustAlignment(const PyDbDatabase& pDb) const;
    void                convertFieldToText() const;
    bool                hitTest(const AcGePoint3d& ptHit) const;
    boost::python::list getBoundingPoints() const;
    AcDbText::AcTextAlignment  justification() const;
    void   setJustification(AcDbText::AcTextAlignment val) const;
    static std::string  className();
    static PyRxClass    desc();
    static PyDbText		cloneFrom(const PyRxObject& src);
    static PyDbText     cast(const PyRxObject& src);
public:
    AcDbText* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//PyDbAttributeDefinition
void makePyDbAttributeDefinitionWrapper();
class PyDbAttributeDefinition : public PyDbText
{
public:
    PyDbAttributeDefinition();
    PyDbAttributeDefinition(const AcGePoint3d& position, const std::string& text, const std::string& tag, const std::string& prompt, const PyDbObjectId& style);
    PyDbAttributeDefinition(AcDbAttributeDefinition* ptr, bool autoDelete);
    PyDbAttributeDefinition(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    PyDbAttributeDefinition(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbAttributeDefinition(const PyDbObjectId& id);
    virtual ~PyDbAttributeDefinition() override = default;
    std::string         prompt() const;
    void                setPrompt(const std::string& val) const;
    std::string         tag() const;
    void                setTag(const std::string& val) const;
    Adesk::Boolean      isInvisible() const;
    void                setInvisible(Adesk::Boolean val) const;
    Adesk::Boolean      isConstant() const;
    void                setConstant(Adesk::Boolean val) const;
    Adesk::Boolean      isVerifiable() const;
    void                setVerifiable(Adesk::Boolean val) const;
    Adesk::Boolean      isPreset() const;
    void                setPreset(Adesk::Boolean val) const;
    Adesk::UInt16       fieldLength() const;
    void                setFieldLength(Adesk::UInt16 val) const;
    void                adjustAlignment(const PyDbDatabase& pDb) const;
    bool                lockPositionInBlock() const;
    void                setLockPositionInBlock(bool bValue) const;
    bool                isMTextAttributeDefinition() const;
    PyDbMText           getMTextAttributeDefinition() const;
    void                setMTextAttributeDefinition(const PyDbMText& mt) const;
    void                convertIntoMTextAttributeDefinition(Adesk::Boolean val) const;
    void                updateMTextAttributeDefinition() const;
    static std::string  className();
    static PyRxClass    desc();
    static PyDbAttributeDefinition	cloneFrom(const PyRxObject& src);
    static PyDbAttributeDefinition  cast(const PyRxObject& src);
public:
    AcDbAttributeDefinition* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//PyDbAttribute
void makePyDbAttributeWrapper();
class PyDbAttribute : public PyDbText
{
public:
    PyDbAttribute();
    PyDbAttribute(const AcGePoint3d& position, const std::string& text, const std::string& tag, const PyDbObjectId& style);
    PyDbAttribute(AcDbAttribute* ptr, bool autoDelete);
    PyDbAttribute(const PyDbObjectId& id);
    PyDbAttribute(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbAttribute(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    virtual ~PyDbAttribute() override = default;
    std::string tag() const;
    void                setTag(const std::string& val) const;
    Adesk::Boolean      isInvisible() const;
    void                setInvisible(Adesk::Boolean val) const;
    Adesk::Boolean      isConstant() const;
    Adesk::Boolean      isVerifiable() const;
    Adesk::Boolean      isPreset() const;
    Adesk::UInt16       fieldLength() const;
    void                setFieldLength(Adesk::UInt16) const;
    void                setAttributeFromBlock1(const AcGeMatrix3d& blkXform) const;
    void                setAttributeFromBlock2(const PyDbAttributeDefinition& pAttdef, const AcGeMatrix3d& blkXform) const;
    bool                lockPositionInBlock() const;
    void                setLockPositionInBlock(bool bValue) const;
    bool                isMTextAttribute() const;
    PyDbMText           getMTextAttribute() const;
    void                setMTextAttribute(PyDbMText& mt) const;
    void                convertIntoMTextAttribute(Adesk::Boolean val) const;
    void                updateMTextAttribute() const;
    bool                isReallyLocked() const;
    static std::string  className();
    static PyRxClass    desc();
    static PyDbAttribute cloneFrom(const PyRxObject& src);
    static PyDbAttribute cast(const PyRxObject& src);
public:
    AcDbAttribute* impObj(const std::source_location& src = std::source_location::current()) const;
};

#pragma pack (pop)