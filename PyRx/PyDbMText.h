#pragma once
#include "PyDbEntity.h"
#include "PyDbMtext.h"

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
    void                setLocation(const AcGePoint3d& val);
    AcGeVector3d        normal() const;
    void                setNormal(const AcGeVector3d& val);
    AcGeVector3d        direction() const;
    void                setDirection(const AcGeVector3d&);
    double              rotation() const;
    void                setRotation(double val);
    double              width() const;
    void                setWidth(double);
    double              ascent() const;
    double              descent() const;
    PyDbObjectId        textStyle() const;
    void                setTextStyle(const PyDbObjectId& val);
    double              textHeight() const;
    void                setTextHeight(double val);
    AcDbMText::AttachmentPoint attachment() const;
    void                setAttachment(AcDbMText::AttachmentPoint val);
    void                setAttachmentMovingLocation(AcDbMText::AttachmentPoint val);
    AcDbMText::FlowDirection       flowDirection() const;
    void                setFlowDirection(AcDbMText::FlowDirection);
    std::string         contents() const;
    int                 setContents(const std::string& str);
    std::string         contentsRTF() const;
    int                 setContentsRTF(const std::string& str);
    std::string         text() const;
    double              actualHeight() const;
    double              actualWidth() const;
    int                 correctSpelling();
    boost::python::list getBoundingPoints() const;
    boost::python::list getBoundingPointsByLine() const;
    bool                hitTest(const AcGePoint3d& ptHit) const;
    void                setLineSpacingStyle(AcDb::LineSpacingStyle eStyle);
    AcDb::LineSpacingStyle lineSpacingStyle() const;
    void                setLineSpacingFactor(double dFactor);
    double              lineSpacingFactor() const;
    bool                backgroundFillOn() const;
    void                setBackgroundFill(bool enable);
    AcCmColor           getBackgroundFillColor() const;
    void                setBackgroundFillColor(const AcCmColor& color);
    double              getBackgroundScaleFactor() const;
    void                setBackgroundScaleFactor(const double scale);
    AcCmTransparency    getBackgroundTransparency() const;
    void                setBackgroundTransparency(const AcCmTransparency& transp);
    bool                useBackgroundColorOn() const;
    void                setUseBackgroundColor(bool enable);
    void                setDynamicColumns(double width, double gutter, bool auto_height);
    void                setStaticColumns(double width, double gutter, int count);
    AcDbMText::ColumnType getColumnType() const;
    void                setColumnType(AcDbMText::ColumnType val);
    bool                getColumnAutoHeight() const;
    void                setColumnAutoHeight(bool val);
    int                 getColumnCount() const;
    void                setColumnCount(int val);
    double              getColumnWidth() const;
    void                setColumnWidth(double val);
    double              getColumnGutterWidth() const;
    void                setColumnGutterWidth(double val);
    bool                getColumnFlowReversed() const;
    void                setColumnFlowReversed(bool val);
    double              getColumnHeight(int val) const;
    void                setColumnHeight(int, double val);
    void                convertFieldToText();
    double              height() const;
    void                setHeight(double val);
    boost::python::list getFragments();
    static std::string  className();
    static PyRxClass    desc();
    static PyDbMText    cloneFrom(const PyRxObject& src);
    static PyDbMText    cast(const PyRxObject& src);
public:
    AcDbMText* impObj(const std::source_location& src = std::source_location::current()) const;
};
