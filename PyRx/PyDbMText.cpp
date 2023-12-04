#include "stdafx.h"
#include "PyDbMtext.h"
#include "PyDbObjectId.h"
using namespace boost::python;

int AcDbMTextFragmentCallBack(AcDbMTextFragment* frag, void* param);

enum class PyRxMTextFragmentType
{
    kLocation,
    kNormal,
    kDirection,
    kTextValue,
    kFont,
    kBigFont,
    kExtents,
    kCapsHeight,
    kWidthFactor,
    kObliqueAngle,
    kTrackingFactor,
    kColor,
    kStackTop,
    kStackBottom,
    kUnderlined,
    kOverlined,
    kStrikethrough,
    kUnderPoints,
    kOverPoints,
    kStrikePoints,
    kFontname,
    kBold,
    kItalic,
    kEndFragmentTypes,
};

void makePyDbMTextWrapper()
{
    PyDocString DS("MText");
    class_<PyDbMText, bases<PyDbEntity>>("MText")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.ARGS({ "id: ObjectId", "mode: OpenMode=kForRead", "erased: bool=False" })))
        .def("location", &PyDbMText::location, DS.ARGS())
        .def("setLocation", &PyDbMText::setLocation, DS.ARGS({ "val : PyGe.Point3d" }))
        .def("normal", &PyDbMText::normal, DS.ARGS())
        .def("setNormal", &PyDbMText::setNormal, DS.ARGS({ "val : PyGe.Vector3d" }))
        .def("direction", &PyDbMText::direction, DS.ARGS())
        .def("setDirection", &PyDbMText::setDirection, DS.ARGS({ "val : PyGe.Vector3d" }))
        .def("rotation", &PyDbMText::rotation, DS.ARGS())
        .def("setRotation", &PyDbMText::setRotation, DS.ARGS({ "val : real" }))
        .def("width", &PyDbMText::width, DS.ARGS())
        .def("setWidth", &PyDbMText::setWidth, DS.ARGS({ "val : real" }))
        .def("ascent", &PyDbMText::ascent, DS.ARGS())
        .def("descent", &PyDbMText::descent, DS.ARGS())
        .def("textStyle", &PyDbMText::textStyle, DS.ARGS())
        .def("setTextStyle", &PyDbMText::setTextStyle, DS.ARGS({ "val : PyDb.ObjectId" }))
        .def("textHeight", &PyDbMText::textHeight, DS.ARGS())
        .def("setTextHeight", &PyDbMText::setTextHeight, DS.ARGS({ "val : real" }))
        .def("attachment", &PyDbMText::attachment, DS.ARGS())
        .def("setAttachment", &PyDbMText::setAttachment, DS.ARGS({ "val : PyDb.MTextAttachmentPoint" }))
        .def("setAttachmentMovingLocation", &PyDbMText::setAttachmentMovingLocation)
        .def("flowDirection", &PyDbMText::flowDirection, DS.ARGS())
        .def("setFlowDirection", &PyDbMText::setFlowDirection, DS.ARGS({ "val : PyDb.MTextFlowDirection" }))
        .def("contents", &PyDbMText::contents, DS.ARGS())
        .def("setContents", &PyDbMText::setContents, DS.ARGS({ "val : str" }))
        .def("contentsRTF", &PyDbMText::contentsRTF, DS.ARGS())
        .def("setContentsRTF", &PyDbMText::setContentsRTF, DS.ARGS({ "val : str" }))
        .def("text", &PyDbMText::text, DS.ARGS())
        .def("actualHeight", &PyDbMText::actualHeight, DS.ARGS())
        .def("actualWidth", &PyDbMText::actualWidth, DS.ARGS())
        .def("correctSpelling", &PyDbMText::correctSpelling, DS.ARGS())
        .def("getBoundingPoints", &PyDbMText::getBoundingPoints, DS.ARGS())
        .def("getBoundingPointsByLine", &PyDbMText::getBoundingPointsByLine, DS.ARGS())
        .def("hitTest", &PyDbMText::hitTest, DS.ARGS({ "val : PyGe.Point3d" }))
        .def("setLineSpacingStyle", &PyDbMText::setLineSpacingStyle, DS.ARGS({ "val : PyDb.LineSpacingStyle" }))
        .def("lineSpacingStyle", &PyDbMText::lineSpacingStyle, DS.ARGS())
        .def("setLineSpacingFactor", &PyDbMText::setLineSpacingFactor, DS.ARGS({ "val : real" }))
        .def("lineSpacingFactor", &PyDbMText::lineSpacingFactor, DS.ARGS())
        .def("backgroundFillOn", &PyDbMText::backgroundFillOn, DS.ARGS())
        .def("setBackgroundFill", &PyDbMText::setBackgroundFill, DS.ARGS({ "val : bool" }))
        .def("getBackgroundFillColor", &PyDbMText::getBackgroundFillColor, DS.ARGS())
        .def("setBackgroundFillColor", &PyDbMText::setBackgroundFillColor, DS.ARGS({ "val : PyDb.AcCmColor" }))
        .def("getBackgroundScaleFactor", &PyDbMText::getBackgroundScaleFactor, DS.ARGS())
        .def("setBackgroundScaleFactor", &PyDbMText::setBackgroundScaleFactor, DS.ARGS({ "val : real" }))
        .def("getBackgroundTransparency", &PyDbMText::getBackgroundTransparency, DS.ARGS())
        .def("setBackgroundTransparency", &PyDbMText::setBackgroundTransparency, DS.ARGS({ "val : PyDb.AcCmTransparency" }))
        .def("useBackgroundColorOn", &PyDbMText::useBackgroundColorOn, DS.ARGS())
        .def("setUseBackgroundColor", &PyDbMText::setUseBackgroundColor, DS.ARGS({ "val : bool" }))
        .def("setDynamicColumns", &PyDbMText::setDynamicColumns, DS.ARGS({ "width : real","gutter : real","autoHeight : bool" }))
        .def("setStaticColumns", &PyDbMText::setStaticColumns, DS.ARGS({ "width : real","gutter : real","count : int" }))
        .def("getColumnType", &PyDbMText::getColumnType, DS.ARGS())
        .def("setColumnType", &PyDbMText::setColumnType, DS.ARGS({ "val : PyDb.MTextColumnType" }))
        .def("getColumnAutoHeight", &PyDbMText::getColumnAutoHeight, DS.ARGS())
        .def("setColumnAutoHeight", &PyDbMText::setColumnAutoHeight, DS.ARGS({ "val : bool" }))
        .def("getColumnCount", &PyDbMText::getColumnCount, DS.ARGS())
        .def("setColumnCount", &PyDbMText::setColumnCount, DS.ARGS({ "val : int" }))
        .def("getColumnWidth", &PyDbMText::getColumnWidth, DS.ARGS())
        .def("setColumnWidth", &PyDbMText::setColumnWidth, DS.ARGS({ "val : real" }))
        .def("getColumnGutterWidth", &PyDbMText::getColumnGutterWidth, DS.ARGS())
        .def("setColumnGutterWidth", &PyDbMText::setColumnGutterWidth, DS.ARGS({ "val : real" }))
        .def("getColumnFlowReversed", &PyDbMText::getColumnFlowReversed, DS.ARGS())
        .def("setColumnFlowReversed", &PyDbMText::setColumnFlowReversed, DS.ARGS({ "val : bool" }))
        .def("getColumnHeight", &PyDbMText::getColumnHeight, DS.ARGS({ "idx : int" }))
        .def("setColumnHeight", &PyDbMText::setColumnHeight, DS.ARGS({ "idx : int", "val : real" }))
        .def("convertFieldToText", &PyDbMText::convertFieldToText, DS.ARGS())
        .def("height", &PyDbMText::height, DS.ARGS())
        .def("setHeight", &PyDbMText::setHeight, DS.ARGS({ "val : real" }))
        .def("getFragments", &PyDbMText::getFragments, DS.ARGS())
        .def("className", &PyDbMText::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbMText::desc, DS.SARGS()).staticmethod("desc")
        .def("cloneFrom", &PyDbMText::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbMText::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
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
    enum_<AcDbMText::ColumnType>("MTextColumnType")
        .value("kNoColumns", AcDbMText::ColumnType::kNoColumns)
        .value("kStaticColumns", AcDbMText::ColumnType::kStaticColumns)
        .value("kDynamicColumns", AcDbMText::ColumnType::kDynamicColumns)
        .export_values()
        ;

    enum_<PyRxMTextFragmentType>("MTextFragmentType")
        .value("kLocation", PyRxMTextFragmentType::kLocation)
        .value("kNormal", PyRxMTextFragmentType::kNormal)
        .value("kDirection", PyRxMTextFragmentType::kDirection)
        .value("kTextValue", PyRxMTextFragmentType::kTextValue)
        .value("kFont", PyRxMTextFragmentType::kFont)
        .value("kBigFont", PyRxMTextFragmentType::kBigFont)
        .value("kExtents", PyRxMTextFragmentType::kExtents)
        .value("kCapsHeight", PyRxMTextFragmentType::kCapsHeight)
        .value("kWidthFactor", PyRxMTextFragmentType::kWidthFactor)
        .value("kObliqueAngle", PyRxMTextFragmentType::kObliqueAngle)
        .value("kTrackingFactor", PyRxMTextFragmentType::kTrackingFactor)
        .value("kColor", PyRxMTextFragmentType::kColor)
        .value("kStackTop", PyRxMTextFragmentType::kStackTop)
        .value("kStackBottom", PyRxMTextFragmentType::kStackBottom)
        .value("kUnderlined", PyRxMTextFragmentType::kUnderlined)
        .value("kOverlined", PyRxMTextFragmentType::kOverlined)
        .value("kStrikethrough", PyRxMTextFragmentType::kStrikethrough)
        .value("kUnderPoints", PyRxMTextFragmentType::kUnderPoints)
        .value("kOverPoints", PyRxMTextFragmentType::kOverPoints)
        .value("kStrikePoints", PyRxMTextFragmentType::kStrikePoints)
        .value("kFontname", PyRxMTextFragmentType::kFontname)
        .value("kBold", PyRxMTextFragmentType::kBold)
        .value("kItalic", PyRxMTextFragmentType::kItalic)
        .value("kEndFragmentTypes", PyRxMTextFragmentType::kEndFragmentTypes)
        .export_values()
        ;
}

PyDbMText::PyDbMText()
    : PyDbMText::PyDbMText(new AcDbMText(), true)
{
}

PyDbMText::PyDbMText(AcDbMText* ptr, bool autoDelete)
    : PyDbEntity(ptr, autoDelete)
{
}

PyDbMText::PyDbMText(const PyDbObjectId& id)
    : PyDbMText(openAcDbObject<AcDbMText>(id, AcDb::OpenMode::kForRead), false)
{
}

PyDbMText::PyDbMText(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbEntity(openAcDbObject<AcDbMText>(id, mode), false)
{
}

PyDbMText::PyDbMText(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbEntity(openAcDbObject<AcDbMText>(id, mode), erased)
{
}

AcGePoint3d PyDbMText::location() const
{
    return impObj()->location();
}

void PyDbMText::setLocation(const AcGePoint3d& val)
{
    return PyThrowBadEs(impObj()->setLocation(val));
}

AcGeVector3d PyDbMText::normal() const
{
    return impObj()->normal();
}

void PyDbMText::setNormal(const AcGeVector3d& val)
{
    return PyThrowBadEs(impObj()->setNormal(val));
}

AcGeVector3d PyDbMText::direction() const
{
    return impObj()->direction();
}

void PyDbMText::setDirection(const AcGeVector3d& val)
{
    return PyThrowBadEs(impObj()->setDirection(val));
}

double PyDbMText::rotation() const
{
    return impObj()->rotation();
}

void PyDbMText::setRotation(double val)
{
    return PyThrowBadEs(impObj()->setRotation(val));
}

double PyDbMText::width() const
{
    return impObj()->width();
}

void PyDbMText::setWidth(double val)
{
    return PyThrowBadEs(impObj()->setWidth(val));
}

double PyDbMText::ascent() const
{
    return impObj()->ascent();
}

double PyDbMText::descent() const
{
    return impObj()->descent();
}

PyDbObjectId PyDbMText::textStyle() const
{
    return PyDbObjectId(impObj()->textStyle());
}

void PyDbMText::setTextStyle(const PyDbObjectId& val)
{
    return PyThrowBadEs(impObj()->setTextStyle(val.m_id));
}

double PyDbMText::textHeight() const
{
    return impObj()->textHeight();
}

void PyDbMText::setTextHeight(double val)
{
    return PyThrowBadEs(impObj()->setTextHeight(val));
}

AcDbMText::AttachmentPoint PyDbMText::attachment() const
{
    return impObj()->attachment();
}

void PyDbMText::setAttachment(AcDbMText::AttachmentPoint val)
{
    return PyThrowBadEs(impObj()->setAttachment(val));
}

void PyDbMText::setAttachmentMovingLocation(AcDbMText::AttachmentPoint val)
{
    return PyThrowBadEs(impObj()->setAttachmentMovingLocation(val));
}

AcDbMText::FlowDirection PyDbMText::flowDirection() const
{
    return impObj()->flowDirection();
}

void PyDbMText::setFlowDirection(AcDbMText::FlowDirection val)
{
    return PyThrowBadEs(impObj()->setFlowDirection(val));
}

std::string PyDbMText::contents() const
{
    AcString str;
    PyThrowBadEs(impObj()->contents(str));
    return wstr_to_utf8(str);
}

int PyDbMText::setContents(const std::string& str)
{
    return impObj()->setContents(utf8_to_wstr(str).c_str());
}

std::string PyDbMText::contentsRTF() const
{
    AcString str;
    PyThrowBadEs(impObj()->contentsRTF(str));
    return wstr_to_utf8(str);
}

int PyDbMText::setContentsRTF(const std::string& str)
{
    return impObj()->setContentsRTF(utf8_to_wstr(str).c_str());
}

std::string PyDbMText::text() const
{
    AcString str;
    PyThrowBadEs(impObj()->text(str));
    return wstr_to_utf8(str);
}

double PyDbMText::actualHeight() const
{
    return impObj()->actualHeight();
}

double PyDbMText::actualWidth() const
{
    return impObj()->actualWidth();
}

int PyDbMText::correctSpelling()
{
    return impObj()->correctSpelling();
}

boost::python::list PyDbMText::getBoundingPoints() const
{
    AcGePoint3dArray arr;
    impObj()->getBoundingPoints(arr);
    return Point3dArrayToPyList(arr);
}

boost::python::list PyDbMText::getBoundingPointsByLine() const
{
#if _ZRXTARGET == 240 || _GRXTARGET == 240 || _BRXTARGET == 240
    throw PyNotimplementedByHost();
#else
    PyAutoLockGIL lock;
    AcArray<AcGePoint3dArray> data;
    impObj()->getBoundingPointsByLine(data);
    boost::python::list pylist;
    for (const auto& item : data)
        pylist.append(Point3dArrayToPyList(item));
    return pylist;
#endif
}

bool PyDbMText::hitTest(const AcGePoint3d& ptHit) const
{
#if _ZRXTARGET == 240 || _GRXTARGET == 240 || _BRXTARGET == 240
    throw PyNotimplementedByHost();
#else
    return impObj()->hitTest(ptHit);
#endif
}

void PyDbMText::setLineSpacingStyle(AcDb::LineSpacingStyle eStyle)
{
    return PyThrowBadEs(impObj()->setLineSpacingStyle(eStyle));
}

AcDb::LineSpacingStyle PyDbMText::lineSpacingStyle() const
{
    return impObj()->lineSpacingStyle();
}

void PyDbMText::setLineSpacingFactor(double dFactor)
{
    return PyThrowBadEs(impObj()->setLineSpacingFactor(dFactor));
}

double PyDbMText::lineSpacingFactor() const
{
    return impObj()->lineSpacingFactor();
}

bool PyDbMText::backgroundFillOn() const
{
    return impObj()->backgroundFillOn();
}

void PyDbMText::setBackgroundFill(bool enable)
{
    return PyThrowBadEs(impObj()->setBackgroundFill(enable));
}

AcCmColor PyDbMText::getBackgroundFillColor() const
{
    AcCmColor clr;
    PyThrowBadEs(impObj()->getBackgroundFillColor(clr));
    return clr;
}

void PyDbMText::setBackgroundFillColor(const AcCmColor& color)
{
    return PyThrowBadEs(impObj()->setBackgroundFillColor(color));
}

double PyDbMText::getBackgroundScaleFactor() const
{
    double val;
    PyThrowBadEs(impObj()->getBackgroundScaleFactor(val));
    return val;
}

void PyDbMText::setBackgroundScaleFactor(const double scale)
{
    return PyThrowBadEs(impObj()->setBackgroundScaleFactor(scale));
}

AcCmTransparency PyDbMText::getBackgroundTransparency() const
{
    AcCmTransparency val;
    PyThrowBadEs(impObj()->getBackgroundTransparency(val));
    return val;
}

void PyDbMText::setBackgroundTransparency(const AcCmTransparency& transp)
{
    return PyThrowBadEs(impObj()->setBackgroundTransparency(transp));
}

bool PyDbMText::useBackgroundColorOn() const
{
    return impObj()->useBackgroundColorOn();
}

void PyDbMText::setUseBackgroundColor(bool enable)
{
    return PyThrowBadEs(impObj()->setUseBackgroundColor(enable));
}

void PyDbMText::setDynamicColumns(double width, double gutter, bool auto_height)
{
    return PyThrowBadEs(impObj()->setDynamicColumns(width, gutter, auto_height));
}

void PyDbMText::setStaticColumns(double width, double gutter, int count)
{
    return PyThrowBadEs(impObj()->setStaticColumns(width, gutter, count));
}

AcDbMText::ColumnType PyDbMText::getColumnType() const
{
    AcDbMText::ColumnType  val;
    PyThrowBadEs(impObj()->getColumnType(val));
    return val;
}

void PyDbMText::setColumnType(AcDbMText::ColumnType val)
{
    return PyThrowBadEs(impObj()->setUseBackgroundColor(val));
}

bool PyDbMText::getColumnAutoHeight() const
{
    bool  val;
    PyThrowBadEs(impObj()->getColumnAutoHeight(val));
    return val;
}

void PyDbMText::setColumnAutoHeight(bool val)
{
    return PyThrowBadEs(impObj()->setColumnAutoHeight(val));
}

int PyDbMText::getColumnCount() const
{
    int  val;
    PyThrowBadEs(impObj()->getColumnCount(val));
    return val;
}

void PyDbMText::setColumnCount(int val)
{
    return PyThrowBadEs(impObj()->setColumnCount(val));
}

double PyDbMText::getColumnWidth() const
{
    double  val;
    PyThrowBadEs(impObj()->getColumnWidth(val));
    return val;
}

void PyDbMText::setColumnWidth(double val)
{
    return PyThrowBadEs(impObj()->setColumnWidth(val));
}

double PyDbMText::getColumnGutterWidth() const
{
    double  val;
    PyThrowBadEs(impObj()->getColumnGutterWidth(val));
    return val;
}

void PyDbMText::setColumnGutterWidth(double val)
{
    return PyThrowBadEs(impObj()->setColumnGutterWidth(val));
}

bool PyDbMText::getColumnFlowReversed() const
{
    bool  val;
    PyThrowBadEs(impObj()->getColumnFlowReversed(val));
    return val;
}

void PyDbMText::setColumnFlowReversed(bool val)
{
    return PyThrowBadEs(impObj()->setColumnFlowReversed(val));
}

double PyDbMText::getColumnHeight(int idx) const
{
    double  val;
    PyThrowBadEs(impObj()->getColumnHeight(idx, val));
    return val;
}

void PyDbMText::setColumnHeight(int idx, double val)
{
    return PyThrowBadEs(impObj()->setColumnHeight(idx, val));
}

void PyDbMText::convertFieldToText()
{
    return PyThrowBadEs(impObj()->convertFieldToText());
}

double PyDbMText::height() const
{
    return impObj()->height();
}

void PyDbMText::setHeight(double val)
{
    return PyThrowBadEs(impObj()->setHeight(val));
}

boost::python::list PyDbMText::getFragments()
{
    PyAutoLockGIL lock;
    boost::python::list pylist;
    impObj()->explodeFragments(AcDbMTextFragmentCallBack, &pylist, nullptr);
    return pylist;
}

std::string PyDbMText::className()
{
    return "AcDbMText";
}

PyRxClass PyDbMText::desc()
{
    return PyRxClass(AcDbMText::desc(), false);
}

PyDbMText PyDbMText::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(AcDbMText::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbMText(static_cast<AcDbMText*>(src.impObj()->clone()), true);
}

PyDbMText PyDbMText::cast(const PyRxObject& src)
{
    PyDbMText dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

AcDbMText* PyDbMText::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbMText*>(m_pyImp.get());
}

// preserve order!
int AcDbMTextFragmentCallBack(AcDbMTextFragment* frag, void* param)
{
    if (frag != nullptr && param != nullptr)
    {
        PyAutoLockGIL lock;
        boost::python::list* pylist = reinterpret_cast<boost::python::list*>(param);
        boost::python::list pysublist;

        pysublist.append(frag->location);
        pysublist.append(frag->normal);
        pysublist.append(frag->direction);

#if _GRXTARGET > 0 || _ZRXTARGET  > 0 || _BRXTARGET > 0
        if (frag->text != nullptr)
            pysublist.append(wstr_to_utf8(frag->text));
        else
            pysublist.append(boost::python::object());

        if (frag->font != nullptr)
            pysublist.append(wstr_to_utf8(frag->font));
        else
            pysublist.append(boost::python::object());

        if (frag->bigfont != nullptr)
            pysublist.append(wstr_to_utf8(frag->bigfont));
        else
            pysublist.append(boost::python::object());
#else
        if(!frag->msText.isEmpty())
            pysublist.append(wstr_to_utf8(frag->msText));
        else
            pysublist.append(boost::python::object());

        if (!frag->msFont.isEmpty())
            pysublist.append(wstr_to_utf8(frag->msFont));
        else
            pysublist.append(boost::python::object());

        if (!frag->msBigFont.isEmpty())
            pysublist.append(wstr_to_utf8(frag->msBigFont));
        else
            pysublist.append(boost::python::object());
#endif

        pysublist.append(frag->extents);
        pysublist.append(frag->capsHeight);
        pysublist.append(frag->widthFactor);
        pysublist.append(frag->obliqueAngle);
        pysublist.append(frag->trackingFactor);
        pysublist.append(frag->color);
        pysublist.append(frag->stackTop);
        pysublist.append(frag->stackBottom);
        pysublist.append(frag->underlined);
        pysublist.append(frag->overlined);
        pysublist.append(frag->strikethrough);

        boost::python::list underPoints;
        underPoints.append(frag->underPoints[0]);
        underPoints.append(frag->underPoints[1]);
        pysublist.append(underPoints);

        boost::python::list overPoints;
        overPoints.append(frag->overPoints[0]);
        overPoints.append(frag->overPoints[1]);
        pysublist.append(overPoints);

        boost::python::list strikePoints;
        strikePoints.append(frag->strikePoints[0]);
        strikePoints.append(frag->strikePoints[1]);
        pysublist.append(strikePoints);

#if _GRXTARGET > 0 ||_ZRXTARGET > 0 || _BRXTARGET > 0
        if (frag->fontname != nullptr)
            pysublist.append(wstr_to_utf8(frag->fontname));
        else
            pysublist.append(boost::python::object());
#else
        if (!frag->msFontName.isEmpty())
            pysublist.append(wstr_to_utf8(frag->msFontName));
        else
            pysublist.append(boost::python::object());
#endif

        pysublist.append(frag->bold);
        pysublist.append(frag->italic);

        //
        pylist->append(pysublist);
    }
    return 1;
}