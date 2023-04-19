#pragma once
#include "PyDbEntity.h"

class PyDbObjectId;

void makePyDbMTextWrapper();
class PyDbMText : public PyDbEntity
{
public:
    PyDbMText();
    PyDbMText(AcDbMText* ptr, bool autoDelete);
    PyDbMText(const PyDbObjectId& id, AcDb::OpenMode mode);
    virtual ~PyDbMText() override = default;
    AcGePoint3d     location() const;
    Acad::ErrorStatus   setLocation(const AcGePoint3d& val);
    AcGeVector3d    normal() const;
    Acad::ErrorStatus   setNormal(const AcGeVector3d& val);
    AcGeVector3d    direction() const;
    Acad::ErrorStatus   setDirection(const AcGeVector3d&);
    double      rotation() const;
    Acad::ErrorStatus   setRotation(double val);
    double      width() const;
    Acad::ErrorStatus   setWidth(double);
    double      ascent() const;
    double      descent() const;
    PyDbObjectId        textStyle() const;
    Acad::ErrorStatus   setTextStyle(const PyDbObjectId& val);
    double      textHeight() const;
    Acad::ErrorStatus   setTextHeight(double val);
    AcDbMText::AttachmentPoint attachment() const;
    Acad::ErrorStatus   setAttachment(AcDbMText::AttachmentPoint val);
    Acad::ErrorStatus   setAttachmentMovingLocation(AcDbMText::AttachmentPoint val);

    AcDbMText::FlowDirection       flowDirection() const;
    Acad::ErrorStatus   setFlowDirection(AcDbMText::FlowDirection);

    std::string contents() const;
    int         setContents(const std::string& str);

    std::string contentsRTF() const;
    int         setContentsRTF(const std::string& str);

    std::string text() const;

    double      actualHeight() const;
    double      actualWidth() const;

    int         correctSpelling();

    boost::python::list getBoundingPoints() const;
    bool hitTest(const AcGePoint3d& ptHit) const;

    Acad::ErrorStatus   setLineSpacingStyle(AcDb::LineSpacingStyle eStyle);
    AcDb::LineSpacingStyle lineSpacingStyle() const;

    Acad::ErrorStatus   setLineSpacingFactor(double dFactor);
    double              lineSpacingFactor() const;

    bool backgroundFillOn() const;
    Acad::ErrorStatus setBackgroundFill(bool enable);

    AcCmColor getBackgroundFillColor() const;
    Acad::ErrorStatus setBackgroundFillColor(const AcCmColor& color);

    double getBackgroundScaleFactor() const;
    Acad::ErrorStatus setBackgroundScaleFactor(const double scale);

    AcCmTransparency getBackgroundTransparency() const;
    Acad::ErrorStatus setBackgroundTransparency(const AcCmTransparency& transp);

    bool useBackgroundColorOn() const;
    Acad::ErrorStatus setUseBackgroundColor(bool enable);

    Acad::ErrorStatus setDynamicColumns(double width, double gutter, bool auto_height);
    Acad::ErrorStatus setStaticColumns(double width, double gutter, int count);
    AcDbMText::ColumnType getColumnType() const;
    Acad::ErrorStatus setColumnType(AcDbMText::ColumnType val);

    bool getColumnAutoHeight() const;
    Acad::ErrorStatus setColumnAutoHeight(bool val);

    int getColumnCount() const;
    Acad::ErrorStatus setColumnCount(int val);

    double getColumnWidth() const;
    Acad::ErrorStatus setColumnWidth(double val);

    double getColumnGutterWidth() const;
    Acad::ErrorStatus setColumnGutterWidth(double val);
    bool getColumnFlowReversed() const;
    Acad::ErrorStatus setColumnFlowReversed(bool val);
    double getColumnHeight(int val) const;
    Acad::ErrorStatus setColumnHeight(int, double val);

    Acad::ErrorStatus   convertFieldToText();

    double      height() const;
    Acad::ErrorStatus   setHeight(double val);

    static std::string className();
public:
    AcDbMText* impObj() const;
};

