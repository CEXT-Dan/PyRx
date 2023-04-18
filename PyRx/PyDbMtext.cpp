#include "stdafx.h"
#include "PyDbMtext.h"
#include "PyDbObjectId.h"

using namespace boost::python;

void makePyDbMTextWrapper()
{
    scope MText = class_<PyDbMtext, bases<PyDbEntity>>("MText")
        .def(init<>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("location", &PyDbMtext::location)
        .def("setLocation", &PyDbMtext::setLocation)
        .def("normal", &PyDbMtext::normal)
        .def("setNormal", &PyDbMtext::setNormal)
        .def("direction", &PyDbMtext::direction)
        .def("setDirection", &PyDbMtext::setDirection)
        .def("rotation", &PyDbMtext::rotation)
        .def("setRotation", &PyDbMtext::setRotation)
        .def("width", &PyDbMtext::width)
        .def("setWidth", &PyDbMtext::setWidth)
        .def("ascent", &PyDbMtext::ascent)
        .def("descent", &PyDbMtext::descent)
        .def("textStyle", &PyDbMtext::textStyle)
        .def("setTextStyle", &PyDbMtext::setTextStyle)
        .def("textHeight", &PyDbMtext::textHeight)
        .def("setTextHeight", &PyDbMtext::setTextHeight)
        .def("attachment", &PyDbMtext::attachment)
        .def("setAttachment", &PyDbMtext::setAttachment)
        .def("setAttachmentMovingLocation", &PyDbMtext::setAttachmentMovingLocation)
        .def("flowDirection", &PyDbMtext::flowDirection)
        .def("setFlowDirection", &PyDbMtext::setFlowDirection)
        .def("contents", &PyDbMtext::contents)
        .def("setContents", &PyDbMtext::setContents)
        .def("contentsRTF", &PyDbMtext::contentsRTF)
        .def("setContentsRTF", &PyDbMtext::setContentsRTF)
        .def("text", &PyDbMtext::text)
        .def("actualHeight", &PyDbMtext::actualHeight)
        .def("actualWidth", &PyDbMtext::actualWidth)
        .def("correctSpelling", &PyDbMtext::correctSpelling)
        .def("getBoundingPoints", &PyDbMtext::getBoundingPoints)
        .def("hitTest", &PyDbMtext::hitTest)
        .def("setLineSpacingStyle", &PyDbMtext::setLineSpacingStyle)
        .def("lineSpacingStyle", &PyDbMtext::lineSpacingStyle)
        .def("setLineSpacingFactor", &PyDbMtext::setLineSpacingFactor)
        .def("lineSpacingFactor", &PyDbMtext::lineSpacingFactor)
        .def("backgroundFillOn", &PyDbMtext::backgroundFillOn)
        .def("setBackgroundFill", &PyDbMtext::setBackgroundFill)
        .def("getBackgroundFillColor", &PyDbMtext::getBackgroundFillColor)
        .def("setBackgroundFillColor", &PyDbMtext::setBackgroundFillColor)
        .def("getBackgroundScaleFactor", &PyDbMtext::getBackgroundScaleFactor)
        .def("setBackgroundScaleFactor", &PyDbMtext::setBackgroundScaleFactor)
        .def("getBackgroundTransparency", &PyDbMtext::getBackgroundTransparency)
        .def("setBackgroundTransparency", &PyDbMtext::setBackgroundTransparency)
        .def("useBackgroundColorOn", &PyDbMtext::useBackgroundColorOn)
        .def("setUseBackgroundColor", &PyDbMtext::setUseBackgroundColor)
        .def("setDynamicColumns", &PyDbMtext::setDynamicColumns)
        .def("setStaticColumns", &PyDbMtext::setStaticColumns)
        .def("getColumnType", &PyDbMtext::getColumnType)
        .def("setColumnType", &PyDbMtext::setColumnType)
        .def("getColumnAutoHeight", &PyDbMtext::getColumnAutoHeight)
        .def("setColumnAutoHeight", &PyDbMtext::setColumnAutoHeight)
        .def("getColumnCount", &PyDbMtext::getColumnCount)
        .def("setColumnCount", &PyDbMtext::setColumnCount)
        .def("getColumnWidth", &PyDbMtext::getColumnWidth)
        .def("setColumnWidth", &PyDbMtext::setColumnWidth)
        .def("getColumnGutterWidth", &PyDbMtext::getColumnGutterWidth)
        .def("setColumnGutterWidth", &PyDbMtext::setColumnGutterWidth)
        .def("getColumnFlowReversed", &PyDbMtext::getColumnFlowReversed)
        .def("setColumnFlowReversed", &PyDbMtext::setColumnFlowReversed)
        .def("getColumnHeight", &PyDbMtext::getColumnHeight)
        .def("setColumnHeight", &PyDbMtext::setColumnHeight)
        .def("convertFieldToText", &PyDbMtext::convertFieldToText)
        .def("height", &PyDbMtext::height)
        .def("setHeight", &PyDbMtext::setHeight)
        .def("className", &PyDbMtext::className).staticmethod("className")
        ;
    enum_<AcDbMText::AttachmentPoint>("MTextAttachmentPoint")
        .value("kTopLeft", AcDbMText::AttachmentPoint::kTopLeft)
        .value("kTopCenter", AcDbMText::AttachmentPoint::kTopCenter)
        .value("kTopRight", AcDbMText::AttachmentPoint::kTopRight)
        .value("kMiddleLeft", AcDbMText::AttachmentPoint::kMiddleLeft)
        .value("kMiddleCenter", AcDbMText::AttachmentPoint::kMiddleCenter)
        .value("kMiddleRight", AcDbMText::AttachmentPoint::kMiddleRight)
        .value("kBottomLeft", AcDbMText::AttachmentPoint::kBottomLeft)
        .value("kBottomCenter", AcDbMText::AttachmentPoint::kBottomCenter)
        .value("kBottomRight", AcDbMText::AttachmentPoint::kBottomRight)
        .value("kBaseLeft", AcDbMText::AttachmentPoint::kBaseLeft)
        .value("kBaseCenter", AcDbMText::AttachmentPoint::kBaseCenter)
        .value("kBaseRight", AcDbMText::AttachmentPoint::kBaseRight)
        .value("kBaseAlign", AcDbMText::AttachmentPoint::kBaseAlign)
        .value("kBottomAlign", AcDbMText::AttachmentPoint::kBottomAlign)
        .value("kMiddleAlign", AcDbMText::AttachmentPoint::kMiddleAlign)
        .value("kTopAlign", AcDbMText::AttachmentPoint::kTopAlign)
        .value("kBaseFit", AcDbMText::AttachmentPoint::kBaseFit)
        .value("kBottomFit", AcDbMText::AttachmentPoint::kBottomFit)
        .value("kMiddleFit", AcDbMText::AttachmentPoint::kMiddleFit)
        .value("kTopFit", AcDbMText::AttachmentPoint::kTopFit)
        .value("kBaseMid", AcDbMText::AttachmentPoint::kBaseMid)
        .value("kBottomMid", AcDbMText::AttachmentPoint::kBottomMid)
        .value("kMiddleMid", AcDbMText::AttachmentPoint::kMiddleMid)
        .value("kTopMid", AcDbMText::AttachmentPoint::kTopMid)
        .export_values()
        ;
    enum_<AcDbMText::FlowDirection>("MTextFlowDirection")
        .value("kLtoR", AcDbMText::FlowDirection::kLtoR)
        .value("kRtoL", AcDbMText::FlowDirection::kRtoL)
        .value("kTtoB", AcDbMText::FlowDirection::kTtoB)
        .value("kBtoT", AcDbMText::FlowDirection::kBtoT)
        .value("kByStyle", AcDbMText::FlowDirection::kByStyle)
        .export_values()
        ;
    enum_<AcDbMText::ColumnType>("MtextColumnType")
        .value("kLtoR", AcDbMText::ColumnType::kNoColumns)
        .value("kStaticColumns", AcDbMText::ColumnType::kStaticColumns)
        .value("kDynamicColumns", AcDbMText::ColumnType::kDynamicColumns)
        .export_values()
        ;
}

PyDbMtext::PyDbMtext()
    : PyDbMtext::PyDbMtext(new AcDbMText(), true)
{
}

PyDbMtext::PyDbMtext(AcDbMText* ptr, bool autoDelete)
    : PyDbEntity(ptr, autoDelete)
{
}

PyDbMtext::PyDbMtext(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbEntity(nullptr, false)
{
    AcDbMText* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbMText>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    this->resetImp(pobj, false, true);
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
}

AcGePoint3d PyDbMtext::location() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->location();
}

Acad::ErrorStatus PyDbMtext::setLocation(const AcGePoint3d& val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setLocation(val);
}

AcGeVector3d PyDbMtext::normal() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->normal();
}

Acad::ErrorStatus PyDbMtext::setNormal(const AcGeVector3d& val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setNormal(val);
}

AcGeVector3d PyDbMtext::direction() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->direction();
}

Acad::ErrorStatus PyDbMtext::setDirection(const AcGeVector3d& val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setDirection(val);
}

double PyDbMtext::rotation() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->rotation();
}

Acad::ErrorStatus PyDbMtext::setRotation(double val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setRotation(val);
}

double PyDbMtext::width() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->width();
}

Acad::ErrorStatus PyDbMtext::setWidth(double val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setWidth(val);
}

double PyDbMtext::ascent() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->ascent();
}

double PyDbMtext::descent() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->descent();
}

PyDbObjectId PyDbMtext::textStyle() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return PyDbObjectId(imp->textStyle());
}

Acad::ErrorStatus PyDbMtext::setTextStyle(const PyDbObjectId& val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setTextStyle(val.m_id);
}

double PyDbMtext::textHeight() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->textHeight();
}

Acad::ErrorStatus PyDbMtext::setTextHeight(double val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setTextHeight(val);
}

AcDbMText::AttachmentPoint PyDbMtext::attachment() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->attachment();
}

Acad::ErrorStatus PyDbMtext::setAttachment(AcDbMText::AttachmentPoint val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setAttachment(val);
}

Acad::ErrorStatus PyDbMtext::setAttachmentMovingLocation(AcDbMText::AttachmentPoint val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setAttachmentMovingLocation(val);
}

AcDbMText::FlowDirection PyDbMtext::flowDirection() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->flowDirection();
}

Acad::ErrorStatus PyDbMtext::setFlowDirection(AcDbMText::FlowDirection val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setFlowDirection(val);
}

std::string PyDbMtext::contents() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    AcString str;
    if (auto es = imp->contents(str); es != eOk)
        throw PyAcadErrorStatus(es);
    return wstr_to_utf8(str);
}

int PyDbMtext::setContents(const std::string& str)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setContents(utf8_to_wstr(str).c_str());
}

std::string PyDbMtext::contentsRTF() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    AcString str;
    if (auto es = imp->contentsRTF(str); es != eOk)
        throw PyAcadErrorStatus(es);
    return wstr_to_utf8(str);
}

int PyDbMtext::setContentsRTF(const std::string& str)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setContentsRTF(utf8_to_wstr(str).c_str());
}

std::string PyDbMtext::text() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    AcString str;
    if (auto es = imp->text(str); es != eOk)
        throw PyAcadErrorStatus(es);
    return wstr_to_utf8(str);
}

double PyDbMtext::actualHeight() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->actualHeight();
}

double PyDbMtext::actualWidth() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->actualWidth();
}

int PyDbMtext::correctSpelling()
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->correctSpelling();
#endif
}

boost::python::list PyDbMtext::getBoundingPoints() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    boost::python::list l;
    AcGePoint3dArray arr;
    imp->getBoundingPoints(arr);
    for (const auto& item : arr)
        l.append(item);
    return l;
}

bool PyDbMtext::hitTest(const AcGePoint3d& ptHit) const
{
#ifdef ARXAPP
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->hitTest(ptHit);
#else
    throw PyNotimplementedByHost();
#endif // ARXAPP
}

Acad::ErrorStatus PyDbMtext::setLineSpacingStyle(AcDb::LineSpacingStyle eStyle)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setLineSpacingStyle(eStyle);
}

AcDb::LineSpacingStyle PyDbMtext::lineSpacingStyle() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->lineSpacingStyle();
}

Acad::ErrorStatus PyDbMtext::setLineSpacingFactor(double dFactor)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setLineSpacingFactor(dFactor);
}

double PyDbMtext::lineSpacingFactor() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->lineSpacingFactor();
}

bool PyDbMtext::backgroundFillOn() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->backgroundFillOn();
}

Acad::ErrorStatus PyDbMtext::setBackgroundFill(bool enable)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setBackgroundFill(enable);
}

AcCmColor PyDbMtext::getBackgroundFillColor() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    AcCmColor clr;
    if (auto es = imp->getBackgroundFillColor(clr); es != eOk)
        throw PyAcadErrorStatus(es);
    return clr;
}

Acad::ErrorStatus PyDbMtext::setBackgroundFillColor(const AcCmColor& color)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setBackgroundFillColor(color);
}

double PyDbMtext::getBackgroundScaleFactor() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    double val;
    if (auto es = imp->getBackgroundScaleFactor(val); es != eOk)
        throw PyAcadErrorStatus(es);
    return val;
}

Acad::ErrorStatus PyDbMtext::setBackgroundScaleFactor(const double scale)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setBackgroundScaleFactor(scale);
}

AcCmTransparency PyDbMtext::getBackgroundTransparency() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    AcCmTransparency val;
    if (auto es = imp->getBackgroundTransparency(val); es != eOk)
        throw PyAcadErrorStatus(es);
    return val;
}

Acad::ErrorStatus PyDbMtext::setBackgroundTransparency(const AcCmTransparency& transp)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setBackgroundTransparency(transp);
}

bool PyDbMtext::useBackgroundColorOn() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->useBackgroundColorOn();
}

Acad::ErrorStatus PyDbMtext::setUseBackgroundColor(bool enable)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setUseBackgroundColor(enable);
}

Acad::ErrorStatus PyDbMtext::setDynamicColumns(double width, double gutter, bool auto_height)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setDynamicColumns(width, gutter, auto_height);
}

Acad::ErrorStatus PyDbMtext::setStaticColumns(double width, double gutter, int count)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setStaticColumns(width, gutter, count);
}

AcDbMText::ColumnType PyDbMtext::getColumnType() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    AcDbMText::ColumnType  val;
    if (auto es = imp->getColumnType(val); es != eOk)
        throw PyAcadErrorStatus(es);
    return val;
}

Acad::ErrorStatus PyDbMtext::setColumnType(AcDbMText::ColumnType val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setUseBackgroundColor(val);
}

bool PyDbMtext::getColumnAutoHeight() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    bool  val;
    if (auto es = imp->getColumnAutoHeight(val); es != eOk)
        throw PyAcadErrorStatus(es);
    return val;
}

Acad::ErrorStatus PyDbMtext::setColumnAutoHeight(bool val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setColumnAutoHeight(val);
}

int PyDbMtext::getColumnCount() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    int  val;
    if (auto es = imp->getColumnCount(val); es != eOk)
        throw PyAcadErrorStatus(es);
    return val;
}

Acad::ErrorStatus PyDbMtext::setColumnCount(int val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setColumnCount(val);
}

double PyDbMtext::getColumnWidth() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    double  val;
    if (auto es = imp->getColumnWidth(val); es != eOk)
        throw PyAcadErrorStatus(es);
    return val;
}

Acad::ErrorStatus PyDbMtext::setColumnWidth(double val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setColumnWidth(val);
}

double PyDbMtext::getColumnGutterWidth() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    double  val;
    if (auto es = imp->getColumnGutterWidth(val); es != eOk)
        throw PyAcadErrorStatus(es);
    return val;
}

Acad::ErrorStatus PyDbMtext::setColumnGutterWidth(double val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setColumnGutterWidth(val);
}

bool PyDbMtext::getColumnFlowReversed() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    bool  val;
    if (auto es = imp->getColumnFlowReversed(val); es != eOk)
        throw PyAcadErrorStatus(es);
    return val;
}

Acad::ErrorStatus PyDbMtext::setColumnFlowReversed(bool val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setColumnFlowReversed(val);
}

double PyDbMtext::getColumnHeight(int idx) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    double  val;
    if (auto es = imp->getColumnHeight(idx, val); es != eOk)
        throw PyAcadErrorStatus(es);
    return val;
}

Acad::ErrorStatus PyDbMtext::setColumnHeight(int idx, double val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setColumnHeight(idx,val);
}

Acad::ErrorStatus PyDbMtext::convertFieldToText()
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->convertFieldToText();
#endif
}

double PyDbMtext::height() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->height();
}

Acad::ErrorStatus PyDbMtext::setHeight(double val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setHeight(val);
}

std::string PyDbMtext::className()
{
    return "AcDbMText";
}

AcDbMText* PyDbMtext::impObj() const
{
    return static_cast<AcDbMText*>(m_pImp.get());
}
