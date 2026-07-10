#include "stdafx.h"
#include "PyDbTableStyle.h"
#include "PyDbObjectId.h"

using namespace boost::python;
void makePyDbTableStyleWrapper()
{
    constexpr const std::string_view ctords = "Overloads:\n"
        "- None: Any\n"
        "- id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode, erased: bool\n";


    constexpr const std::string_view textStyleOverloads = "Overloads:\n"
        "- rowType: PyDb.RowType\n"
        "- cellStyle: str\n";

    constexpr const std::string_view setTextStyleOverloads = "Overloads:\n"
        "- id: PyDb.ObjectId, rowType: PyDb.RowType\n"
        "- id: PyDb.ObjectId, cellStyle: str\n";

    constexpr const std::string_view textHeightOverloads = "Overloads:\n"
        "- rowType: PyDb.RowType\n"
        "- cellStyle: str\n";

    constexpr const std::string_view setTextHeightOverloads = "Overloads:\n"
        "- val: float, rowType: PyDb.RowType\n"
        "- val: float, cellStyle: str\n";

    constexpr const std::string_view alignmenttOverloads = "Overloads:\n"
        "- rowType: PyDb.RowType\n"
        "- cellStyle: str\n";

    constexpr const std::string_view setAlignmenttOverloads = "Overloads:\n"
        "- val:  PyDb.CellAlignment, rowType: PyDb.RowType\n"
        "- val:  PyDb.CellAlignment, cellStyle: str\n";

    constexpr const std::string_view colorOverloads = "Overloads:\n"
        "- rowType: PyDb.RowType\n"
        "- cellStyle: str\n";

    constexpr const std::string_view setColorOverloads = "Overloads:\n"
        "- val:  PyDb.Color, rowType: PyDb.RowType\n"
        "- val:  PyDb.Color, cellStyle: str\n";

    constexpr const std::string_view getDataTypeOverloads = "Overloads:\n"
        "- rowType: PyDb.RowType\n"
        "- cellStyle: str\n";

    constexpr const std::string_view setDataTypeOverloads = "Overloads:\n"
        "- nDataType: PyDb.ValueDataType, nUnitType: PyDb.ValueDataType\n"
        "- nDataType: PyDb.ValueDataType, nUnitType: PyDb.ValueDataType, rowType: PyDb.RowType\n"
        "- nDataType: PyDb.ValueDataType, nUnitType: PyDb.ValueDataType, cellStyle: str\n";

    constexpr const std::string_view formatOverloads = "Overloads:\n"
        "- None: Any\n"
        "- rowType: PyDb.RowType\n"
        "- cellStyle: str\n";

    constexpr const std::string_view setFormatOverloads = "Overloads:\n"
        "- sFormat: str\n"
        "- sFormat: str, rowType: PyDb.RowType\n"
        "- sFormat: str, cellStyle: str\n";

    constexpr const std::string_view gridLineWeightOverloads = "Overloads:\n"
        "- gridLineType: PyDb.GridLineType ,rowType: PyDb.RowType\n"
        "- gridLineType: PyDb.GridLineType ,cellStyle: str\n";

    constexpr const std::string_view setGridLineWeighOverloads = "Overloads:\n"
        "- lineWeight: PyDb.LineWeight, gridLineType: PyDb.GridLineType ,rowType: PyDb.RowType\n"
        "- lineWeight: PyDb.LineWeight, gridLineType: PyDb.GridLineType ,cellStyle: str\n";

    constexpr const std::string_view gridColorOverloads = "Overloads:\n"
        "- gridLineType: PyDb.GridLineType ,rowType: PyDb.RowType\n"
        "- gridLineType: PyDb.GridLineType ,cellStyle: str\n";

    constexpr const std::string_view setGridColorOverloads = "Overloads:\n"
        "- clr: PyDb.Color, gridLineType: PyDb.GridLineType ,rowType: PyDb.RowType\n"
        "- clr: PyDb.Color, gridLineType: PyDb.GridLineType ,cellStyle: str\n";

    constexpr const std::string_view gridVisibilityOverloads = "Overloads:\n"
        "- gridLineType: PyDb.GridLineType ,rowType: PyDb.RowType\n"
        "- gridLineType: PyDb.GridLineType ,cellStyle: str\n";

    constexpr const std::string_view setGridVisibilityOverloads = "Overloads:\n"
        "- vis: PyDb.Visibility, gridLineType: PyDb.GridLineType ,rowType: PyDb.RowType\n"
        "- vis: PyDb.Visibility, gridLineType: PyDb.GridLineType ,cellStyle: str\n";

    constexpr const std::string_view createCellStyleOverloads = "Overloads:\n"
        "- None: Any\n"
        "- pszCellStyle: str\n"
        "- pszCellStyle: str, fromCellStyle: str\n";


    PyDocString DS("TableStyle");
    class_<PyDbTableStyle, bases<PyDbObject>>("TableStyle")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.CTOR(ctords, 9173)))
        .def("getName", &PyDbTableStyle::getName, DS.ARGS(9195))
        .def("setName", &PyDbTableStyle::setName, DS.ARGS({ "val: str" }, 9236))
        .def("description", &PyDbTableStyle::description, DS.ARGS(9184))
        .def("setDescription", &PyDbTableStyle::setDescription, DS.ARGS({ "val: str" }, 9224))
        .def("bitFlags", &PyDbTableStyle::bitFlags, DS.ARGS(9178))
        .def("setBitFlags", &PyDbTableStyle::setBitFlags, DS.ARGS({ "flags: int" }, 9220))
        .def("flowDirection", &PyDbTableStyle::flowDirection, DS.ARGS(9190))
        .def("setFlowDirection", &PyDbTableStyle::setFlowDirection, DS.ARGS({ "val: PyDb.TableFlowDirection" }, 9225))
        .def("horzCellMargin", &PyDbTableStyle::horzCellMargin, DS.ARGS(9204))
        .def("setHorzCellMargin", &PyDbTableStyle::setHorzCellMargin, DS.ARGS({ "val: float" }, 9234))
        .def("vertCellMargin", &PyDbTableStyle::vertCellMargin, DS.ARGS(9247))
        .def("setVertCellMargin", &PyDbTableStyle::setVertCellMargin, DS.ARGS({ "val: float" }, 9241))
        .def("isTitleSuppressed", &PyDbTableStyle::isTitleSuppressed, DS.ARGS(9210))
        .def("suppressTitleRow", &PyDbTableStyle::suppressTitleRow, DS.ARGS({ "val: bool" }, 9244))
        .def("isHeaderSuppressed", &PyDbTableStyle::isHeaderSuppressed, DS.ARGS(9207))
        .def("suppressHeaderRow", &PyDbTableStyle::suppressHeaderRow, DS.ARGS({ "val: bool" }, 9243))
        .def("textStyle", &PyDbTableStyle::textStyle)
        .def("textStyle", &PyDbTableStyle::textStyle2, DS.OVRL(textStyleOverloads, 9246))
        .def("setTextStyle", &PyDbTableStyle::setTextStyle)
        .def("setTextStyle", &PyDbTableStyle::setTextStyle2, DS.OVRL(setTextStyleOverloads, 9240))
        .def("textHeight", &PyDbTableStyle::textHeight)
        .def("textHeight", &PyDbTableStyle::textHeight2, DS.OVRL(textHeightOverloads, 9245))
        .def("setTextHeight", &PyDbTableStyle::setTextHeight)
        .def("setTextHeight", &PyDbTableStyle::setTextHeight2, DS.OVRL(setTextHeightOverloads, 9239))
        .def("alignment", &PyDbTableStyle::alignment)
        .def("alignment", &PyDbTableStyle::alignment2, DS.OVRL(alignmenttOverloads, 9175))
        .def("setAlignment", &PyDbTableStyle::setAlignment)
        .def("setAlignment", &PyDbTableStyle::setAlignment2, DS.OVRL(setAlignmenttOverloads, 9217))
        .def("color", &PyDbTableStyle::color)
        .def("color", &PyDbTableStyle::color2, DS.OVRL(colorOverloads, 9180))
        .def("setColor", &PyDbTableStyle::setColor)
        .def("setColor", &PyDbTableStyle::setColor2, DS.OVRL(setColorOverloads, 9222))
        .def("backgroundColor", &PyDbTableStyle::backgroundColor)
        .def("backgroundColor", &PyDbTableStyle::backgroundColor2, DS.OVRL(colorOverloads, 9177))
        .def("setBackgroundColor", &PyDbTableStyle::setBackgroundColor)
        .def("setBackgroundColor", &PyDbTableStyle::setBackgroundColor2, DS.OVRL(setColorOverloads, 9218))
        .def("isBackgroundColorNone", &PyDbTableStyle::isBackgroundColorNone, DS.ARGS({ "rowType: PyDb.RowType" }, 9205))
        .def("setBackgroundColorNone", &PyDbTableStyle::setBackgroundColorNone, DS.ARGS({ "val: bool","rowType: PyDb.RowType" }, 9219))
        .def("getDataType", &PyDbTableStyle::getDataType)
        .def("getDataType", &PyDbTableStyle::getDataType2, DS.OVRL(getDataTypeOverloads, 9193))
        .def("setDataType", &PyDbTableStyle::setDataType1)
        .def("setDataType", &PyDbTableStyle::setDataType2)
        .def("setDataType", &PyDbTableStyle::setDataType3, DS.OVRL(setDataTypeOverloads, 9223))
        .def("format", &PyDbTableStyle::format1)
        .def("format", &PyDbTableStyle::format2)
        .def("format", &PyDbTableStyle::format3, DS.OVRL(formatOverloads, 9191))
        .def("setFormat", &PyDbTableStyle::setFormat1)
        .def("setFormat", &PyDbTableStyle::setFormat2)
        .def("setFormat", &PyDbTableStyle::setFormat3, DS.OVRL(setFormatOverloads, 9226))
        .def("gridLineWeight", &PyDbTableStyle::gridLineWeight)
        .def("gridLineWeight", &PyDbTableStyle::gridLineWeight2, DS.OVRL(gridLineWeightOverloads, 9202))
        .def("setGridLineWeight", &PyDbTableStyle::setGridLineWeight)
        .def("setGridLineWeight", &PyDbTableStyle::setGridLineWeight2, DS.OVRL(setGridLineWeighOverloads, 9231))
        .def("gridColor", &PyDbTableStyle::gridColor)
        .def("gridColor", &PyDbTableStyle::gridColor2, DS.OVRL(gridColorOverloads, 9198))
        .def("setGridColor", &PyDbTableStyle::setGridColor)
        .def("setGridColor", &PyDbTableStyle::setGridColor2, DS.OVRL(setGridColorOverloads, 9227))
        .def("gridVisibility", &PyDbTableStyle::gridVisibility)
        .def("gridVisibility", &PyDbTableStyle::gridVisibility2, DS.OVRL(gridVisibilityOverloads, 9203))
        .def("setGridVisibility", &PyDbTableStyle::setGridVisibility)
        .def("setGridVisibility", &PyDbTableStyle::setGridVisibility2, DS.OVRL(setGridVisibilityOverloads, 9233))
        .def("postTableStyleToDb", &PyDbTableStyle::postTableStyleToDb, DS.ARGS({ "db: PyDb.Database","styleName: str" }, 9213))
        .def("createCellStyle", &PyDbTableStyle::createCellStyle1)
        .def("createCellStyle", &PyDbTableStyle::createCellStyle2)
        .def("createCellStyle", &PyDbTableStyle::createCellStyle3, DS.OVRL(createCellStyleOverloads, 9182))
        .def("renameCellStyle", &PyDbTableStyle::renameCellStyle, DS.ARGS({ "pszOldName: str", "pszNewName: str" }, 9215))
        .def("deleteCellStyle", &PyDbTableStyle::deleteCellStyle, DS.ARGS({ "pszCellStyle: str" }, 9183))
        .def("copyCellStyle", &PyDbTableStyle::copyCellStyle, DS.ARGS({ "pszSrcCellStyle: str", "pszTargetCellStyle: str" },9181))
        .def("isCellStyleInUse", &PyDbTableStyle::isCellStyleInUse, DS.ARGS({ "pszCellStyle: str" }, 9206))
        .def("numCellStyles", &PyDbTableStyle::numCellStyles, DS.ARGS(9212))
        .def("getCellStyles", &PyDbTableStyle::getCellStyles, DS.ARGS(9192))
        .def("cellClass", &PyDbTableStyle::cellClass, DS.ARGS({ "pszCellStyle: str" }, 9179))
        .def("setCellClass", &PyDbTableStyle::setCellClass, DS.ARGS({ "val: int","pszCellStyle: str" }, 9221))
        .def("rotation", &PyDbTableStyle::rotation, DS.ARGS({ "pszCellStyle: str" }, 9216))
        .def("setRotation", &PyDbTableStyle::setRotation, DS.ARGS({ "val: float", "pszCellStyle: str" }, 9237))
        .def("isMergeAllEnabled", &PyDbTableStyle::isMergeAllEnabled, DS.ARGS({ "pszCellStyle: str" }, 9208))
        .def("enableMergeAll", &PyDbTableStyle::enableMergeAll, DS.ARGS({ "val: bool", "pszCellStyle: str" }, 9189))
        .def("margin", &PyDbTableStyle::margin, DS.ARGS({ "nMargin: PyDb.CellMargin", "pszCellStyle: str" }, 9211))
        .def("setMargin", &PyDbTableStyle::setMargin, DS.ARGS({ "nMargins: PyDb.CellMargin","val: float", "pszCellStyle: str" }, 9235))
        .def("gridDoubleLineSpacing", &PyDbTableStyle::gridDoubleLineSpacing, DS.ARGS({ "gridLineType: PyDb.GridLineType", "pszCellStyle: str" }, 9199))
        .def("setGridDoubleLineSpacing", &PyDbTableStyle::setGridDoubleLineSpacing, DS.ARGS({ "val: float","gridLineTypes: PyDb.GridLineType", "pszCellStyle: str" }, 9228))
        .def("gridLineStyle", &PyDbTableStyle::gridLineStyle, DS.ARGS({ "gridLineType: PyDb.GridLineType", "pszCellStyle: str" }, 9200))
        .def("setGridLineStyle", &PyDbTableStyle::setGridLineStyle, DS.ARGS({ "nLineStyle: PyDb.GridLineStyle","gridLineType: PyDb.GridLineType", "pszCellStyle: str" }, 9229))
        .def("gridLinetype", &PyDbTableStyle::gridLinetype, DS.ARGS({ "gridLineType: PyDb.GridLineType", "pszCellStyle: str" }, 9201))
        .def("setGridLinetype", &PyDbTableStyle::setGridLinetype, DS.ARGS({ "id: PyDb.ObjectId", "gridLineType: PyDb.GridLineType", "pszCellStyle: str" }, 9230))
        .def("getGridProperty", &PyDbTableStyle::getGridProperty, DS.ARGS({ "gridLineType: PyDb.GridLineType", "pszCellStyle: str" }, 9194))
        .def("setGridProperty", &PyDbTableStyle::setGridProperty, DS.ARGS({ "gridProp: PyDb.GridProperty", "gridLineType: PyDb.GridLineType", "pszCellStyle: str" }, 9232))
        .def("getTemplate", &PyDbTableStyle::getTemplate, DS.ARGS(9196))
        .def("setTemplate", &PyDbTableStyle::setTemplate, DS.ARGS({ "id: PyDb.ObjectId" , "nOption: PyDb.MergeCellStyleOption" }, 9238))
        .def("removeTemplate", &PyDbTableStyle::removeTemplate, DS.ARGS(9214))
        .def("className", &PyDbTableStyle::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbTableStyle::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyDbTableStyle::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbTableStyle::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyDbTableStyle::PyDbTableStyle()
    : PyDbObject(new AcDbTableStyle(), true)
{
}

PyDbTableStyle::PyDbTableStyle(AcDbObject* ptr, bool autoDelete)
    : PyDbObject(ptr, autoDelete)
{
}


PyDbTableStyle::PyDbTableStyle(const PyDbObjectId& id)
    : PyDbObject(openAcDbObject<AcDbTableStyle>(id, AcDb::OpenMode::kForRead, false), false)
{
}

PyDbTableStyle::PyDbTableStyle(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbObject(openAcDbObject<AcDbTableStyle>(id, mode), false)
{
}

PyDbTableStyle::PyDbTableStyle(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbObject(openAcDbObject<AcDbTableStyle>(id, mode, erased), false)
{
}

std::string PyDbTableStyle::getName() const
{
#if defined(_BRXTARGET270)
    RxAutoOutStr name;
    PyThrowBadEs(impObj()->getName(name.buf));
    return wstr_to_utf8(name.buf);
#else
    AcString name;
    PyThrowBadEs(impObj()->getName(name));
    return wstr_to_utf8(name);
#endif

}

void PyDbTableStyle::setName(const std::string& pszName) const
{
    return PyThrowBadEs(impObj()->setName(AsWStr(pszName)));
}

std::string PyDbTableStyle::description(void) const
{
    return wstr_to_utf8(impObj()->description());
}

void PyDbTableStyle::setDescription(const std::string& pszDescription) const
{
    return PyThrowBadEs(impObj()->setName(AsWStr(pszDescription)));
}

Adesk::UInt32 PyDbTableStyle::bitFlags() const
{
    return impObj()->bitFlags();
}

void PyDbTableStyle::setBitFlags(Adesk::UInt32 flags) const
{
    return PyThrowBadEs(impObj()->setBitFlags(flags));
}

AcDb::FlowDirection PyDbTableStyle::flowDirection(void) const
{
    return impObj()->flowDirection();
}

void PyDbTableStyle::setFlowDirection(AcDb::FlowDirection flow) const
{
    return  PyThrowBadEs(impObj()->setFlowDirection(flow));
}

double PyDbTableStyle::horzCellMargin(void) const
{
    return  impObj()->horzCellMargin();
}

void PyDbTableStyle::setHorzCellMargin(double dCellMargin) const
{
    return PyThrowBadEs(impObj()->setHorzCellMargin(dCellMargin));
}

double PyDbTableStyle::vertCellMargin(void) const
{
    return impObj()->vertCellMargin();
}

void PyDbTableStyle::setVertCellMargin(double dCellMargin) const
{
    return PyThrowBadEs(impObj()->setVertCellMargin(dCellMargin));
}

bool PyDbTableStyle::isTitleSuppressed(void) const
{
    return impObj()->isTitleSuppressed();
}

void PyDbTableStyle::suppressTitleRow(bool bValue) const
{
    return PyThrowBadEs(impObj()->suppressTitleRow(bValue));
}

bool PyDbTableStyle::isHeaderSuppressed(void) const
{
    return impObj()->isHeaderSuppressed();
}

void PyDbTableStyle::suppressHeaderRow(bool bValue) const
{
    return PyThrowBadEs(impObj()->suppressHeaderRow(bValue));
}

PyDbObjectId PyDbTableStyle::textStyle(AcDb::RowType rowType) const
{
    return PyDbObjectId(impObj()->textStyle(rowType));
}

PyDbObjectId PyDbTableStyle::textStyle2(const std::string& pszCellStyle) const
{
    return PyDbObjectId(impObj()->textStyle(AsWStr(pszCellStyle)));
}

void PyDbTableStyle::setTextStyle(const PyDbObjectId& id, AcDb::RowType rowType) const
{
    return PyThrowBadEs(impObj()->setTextStyle(id.m_id, rowType));
}

void PyDbTableStyle::setTextStyle2(const PyDbObjectId& id, const std::string& pszCellStyle) const
{
    return PyThrowBadEs(impObj()->setTextStyle(id.m_id, AsWStr(pszCellStyle)));
}

double PyDbTableStyle::textHeight(AcDb::RowType rowType) const
{
    return impObj()->textHeight(rowType);
}

double PyDbTableStyle::textHeight2(const std::string& pszCellStyle) const
{
    return impObj()->textHeight(AsWStr(pszCellStyle));
}

void PyDbTableStyle::setTextHeight(double dHeight, AcDb::RowType rowType) const
{
    return PyThrowBadEs(impObj()->setTextHeight(dHeight, rowType));
}

void PyDbTableStyle::setTextHeight2(double dHeight, const std::string& pszCellStyle) const
{
    return PyThrowBadEs(impObj()->setTextHeight(dHeight, AsWStr(pszCellStyle)));
}

AcDb::CellAlignment PyDbTableStyle::alignment(AcDb::RowType rowType) const
{
    return impObj()->alignment(rowType);
}

AcDb::CellAlignment PyDbTableStyle::alignment2(const std::string& pszCellStyle) const
{
#if defined(_BRXTARGET270)
    throw PyNotimplementedByHost();
#else
    return impObj()->alignment(AsWStr(pszCellStyle));
#endif
}

void PyDbTableStyle::setAlignment(AcDb::CellAlignment alignment, AcDb::RowType rowType) const
{
    return PyThrowBadEs(impObj()->setAlignment(alignment, rowType));
}

void PyDbTableStyle::setAlignment2(AcDb::CellAlignment alignment, const std::string& pszCellStyle) const
{
#if defined(_BRXTARGET270)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setAlignment(alignment, AsWStr(pszCellStyle)));
#endif
}

AcCmColor PyDbTableStyle::color(AcDb::RowType rowType) const
{
    return impObj()->color(rowType);
}

AcCmColor PyDbTableStyle::color2(const std::string& pszCellStyle) const
{
#if defined(_BRXTARGET270)
    throw PyNotimplementedByHost();
#else
    return impObj()->color(AsWStr(pszCellStyle));
#endif
}

void PyDbTableStyle::setColor(const AcCmColor& color, AcDb::RowType rowType) const
{
    return PyThrowBadEs(impObj()->setColor(color, rowType));
}

void PyDbTableStyle::setColor2(const AcCmColor& color, const std::string& pszCellStyle) const
{
#if defined(_BRXTARGET270)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setColor(color, AsWStr(pszCellStyle)));
#endif
}

AcCmColor PyDbTableStyle::backgroundColor(AcDb::RowType rowType) const
{
    return impObj()->backgroundColor(rowType);
}

AcCmColor PyDbTableStyle::backgroundColor2(const std::string& pszCellStyle) const
{
#if defined(_BRXTARGET270)
    throw PyNotimplementedByHost();
#else
    return impObj()->backgroundColor(AsWStr(pszCellStyle));
#endif
}

void PyDbTableStyle::setBackgroundColor(const AcCmColor& color, AcDb::RowType rowType) const
{
    return PyThrowBadEs(impObj()->setBackgroundColor(color, rowType));
}

void PyDbTableStyle::setBackgroundColor2(const AcCmColor& color, const std::string& pszCellStyle) const
{
#if defined(_BRXTARGET270)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setBackgroundColor(color, AsWStr(pszCellStyle)));
#endif
}

bool PyDbTableStyle::isBackgroundColorNone(AcDb::RowType rowType) const
{
    return impObj()->isBackgroundColorNone(rowType);
}

void PyDbTableStyle::setBackgroundColorNone(bool bValue, AcDb::RowType rowType) const
{
    return PyThrowBadEs(impObj()->setBackgroundColorNone(bValue, rowType));
}

boost::python::tuple PyDbTableStyle::getDataType(AcDb::RowType type) const
{
    PyAutoLockGIL lock;
    AcValue::DataType nDataType = AcValue::kUnknown;
    AcValue::UnitType nUnitType = AcValue::kUnitless;
    PyThrowBadEs(impObj()->getDataType(nDataType, nUnitType, type));
    return boost::python::make_tuple(nDataType, nUnitType);
}

boost::python::tuple PyDbTableStyle::getDataType2(const std::string& pszCellStyle) const
{
#if defined(_BRXTARGET270)
    throw PyNotimplementedByHost();
#else
    PyAutoLockGIL lock;
    AcValue::DataType nDataType = AcValue::kUnknown;
    AcValue::UnitType nUnitType = AcValue::kUnitless;
    PyThrowBadEs(impObj()->getDataType(nDataType, nUnitType, AsWStr(pszCellStyle)));
    return boost::python::make_tuple(nDataType, nUnitType);
#endif
}

void PyDbTableStyle::setDataType1(AcValue::DataType nDataType, AcValue::UnitType nUnitType) const
{
    return PyThrowBadEs(impObj()->setDataType(nDataType, nUnitType));
}

void PyDbTableStyle::setDataType2(AcValue::DataType nDataType, AcValue::UnitType nUnitType, AcDb::RowType type) const
{
    return PyThrowBadEs(impObj()->setDataType(nDataType, nUnitType, type));
}

void PyDbTableStyle::setDataType3(AcValue::DataType nDataType, AcValue::UnitType nUnitType, const std::string& pszCellStyle) const
{
#if defined(_BRXTARGET270)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setDataType(nDataType, nUnitType, AsWStr(pszCellStyle)));
#endif
}

std::string PyDbTableStyle::format1(void) const
{
    return wstr_to_utf8(impObj()->format());
}

std::string PyDbTableStyle::format2(AcDb::RowType rowType) const
{
    return wstr_to_utf8(impObj()->format(rowType));
}

std::string PyDbTableStyle::format3(const std::string& pszCellStyle) const
{
#if defined(_BRXTARGET270)
    throw PyNotimplementedByHost();
#else
    return wstr_to_utf8(impObj()->format(AsWStr(pszCellStyle)));
#endif
}

void PyDbTableStyle::setFormat1(const std::string& pszFormat) const
{
    return PyThrowBadEs(impObj()->setFormat(AsWStr(pszFormat)));
}

void PyDbTableStyle::setFormat2(const std::string& pszFormat, AcDb::RowType type) const
{
    return PyThrowBadEs(impObj()->setFormat(AsWStr(pszFormat), type));
}

void PyDbTableStyle::setFormat3(const std::string& pszFormat, const std::string& pszCellStyle) const
{
#if defined(_BRXTARGET270)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setFormat(AsWStr(pszFormat), AsWStr(pszCellStyle)));
#endif
}

AcDb::LineWeight PyDbTableStyle::gridLineWeight(AcDb::GridLineType gridLineType, AcDb::RowType rowType) const
{
    return impObj()->gridLineWeight(gridLineType, rowType);
}

AcDb::LineWeight PyDbTableStyle::gridLineWeight2(AcDb::GridLineType gridLineType, const std::string& pszCellStyle) const
{
#if defined(_BRXTARGET270)
    throw PyNotimplementedByHost();
#else
    return impObj()->gridLineWeight(gridLineType, AsWStr(pszCellStyle));
#endif
}

void PyDbTableStyle::setGridLineWeight(AcDb::LineWeight lineWeight, AcDb::GridLineType gridLineType, AcDb::RowType rowType) const
{
    return PyThrowBadEs(impObj()->setGridLineWeight(lineWeight, gridLineType, rowType));
}

void PyDbTableStyle::setGridLineWeight2(AcDb::LineWeight lineWeight, AcDb::GridLineType gridLineTypes, const std::string& pszCellStyle) const
{
#if defined(_BRXTARGET270)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setGridLineWeight(lineWeight, gridLineTypes, AsWStr(pszCellStyle)));
#endif
}

AcCmColor PyDbTableStyle::gridColor(AcDb::GridLineType gridLineType, AcDb::RowType rowType) const
{
    return impObj()->gridColor(gridLineType, rowType);
}

AcCmColor PyDbTableStyle::gridColor2(AcDb::GridLineType gridLineType, const std::string& pszCellStyle) const
{
#if defined(_BRXTARGET270)
    throw PyNotimplementedByHost();
#else
    return impObj()->gridColor(gridLineType, AsWStr(pszCellStyle));
#endif
}

void PyDbTableStyle::setGridColor(const AcCmColor& color, AcDb::GridLineType gridLineType, AcDb::RowType rowType) const
{
    return PyThrowBadEs(impObj()->setGridColor(color, gridLineType, rowType));
}

void PyDbTableStyle::setGridColor2(const AcCmColor& color, AcDb::GridLineType gridLineTypes, const std::string& pszCellStyle) const
{
#if defined(_BRXTARGET270)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setGridColor(color, gridLineTypes, AsWStr(pszCellStyle)));
#endif
}

AcDb::Visibility PyDbTableStyle::gridVisibility(AcDb::GridLineType gridLineType, AcDb::RowType rowType) const
{
    return impObj()->gridVisibility(gridLineType, rowType);
}

AcDb::Visibility PyDbTableStyle::gridVisibility2(AcDb::GridLineType gridLineType, const std::string& pszCellStyle) const
{
#if defined(_BRXTARGET270)
    throw PyNotimplementedByHost();
#else
    return impObj()->gridVisibility(gridLineType, AsWStr(pszCellStyle));
#endif
}

void PyDbTableStyle::setGridVisibility(AcDb::Visibility visible, AcDb::GridLineType gridLineType, AcDb::RowType rowType) const
{
    return PyThrowBadEs(impObj()->setGridVisibility(visible, gridLineType, rowType));
}

void PyDbTableStyle::setGridVisibility2(AcDb::Visibility visible, AcDb::GridLineType gridLineTypes, const std::string& pszCellStyle) const
{
#if defined(_BRXTARGET270)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setGridVisibility(visible, gridLineTypes, AsWStr(pszCellStyle)));
#endif
}

PyDbObjectId PyDbTableStyle::postTableStyleToDb(PyDbDatabase& pDb, const std::string& styleName) const
{
    AcDbObjectId id;
    PyThrowBadEs(impObj()->postTableStyleToDb(pDb.impObj(), AsWStr(styleName), id));
    return PyDbObjectId(id);
}

std::string PyDbTableStyle::createCellStyle1(void) const
{
#if defined(_BRXTARGET270)
    throw PyNotimplementedByHost();
#else
    return wstr_to_utf8(impObj()->createCellStyle());
#endif
}

void PyDbTableStyle::createCellStyle2(const std::string& pszCellStyle) const
{
#if defined(_BRXTARGET270)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->createCellStyle(AsWStr(pszCellStyle)));
#endif
}

void PyDbTableStyle::createCellStyle3(const std::string& pszCellStyle, const std::string& pszFromCellStyle) const
{
#if defined(_BRXTARGET270)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->createCellStyle(AsWStr(pszCellStyle), AsWStr(pszFromCellStyle)));
#endif
}

void PyDbTableStyle::renameCellStyle(const std::string& pszOldName, const std::string& pszNewName) const
{
#if defined(_BRXTARGET270)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->renameCellStyle(AsWStr(pszOldName), AsWStr(pszNewName)));
#endif
}

void PyDbTableStyle::deleteCellStyle(const std::string& pszCellStyle) const
{
#if defined(_BRXTARGET270)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->deleteCellStyle(AsWStr(pszCellStyle)));
#endif
}

void PyDbTableStyle::copyCellStyle(const std::string& pszSrcCellStyle, const std::string& pszTargetCellStyle) const
{
#if defined(_BRXTARGET270)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->copyCellStyle(AsWStr(pszSrcCellStyle), AsWStr(pszTargetCellStyle)));
#endif
}

bool PyDbTableStyle::isCellStyleInUse(const std::string& pszCellStyle) const
{
#if defined(_BRXTARGET270)
    throw PyNotimplementedByHost();
#else
    return impObj()->isCellStyleInUse(AsWStr(pszCellStyle));
#endif
}

int PyDbTableStyle::numCellStyles(void) const
{
    return impObj()->numCellStyles();
}

boost::python::list PyDbTableStyle::getCellStyles() const
{
    AcStringArray cellstyles;
    impObj()->getCellStyles(cellstyles);
    return AcStringArrayToPyList(cellstyles);
}

int PyDbTableStyle::cellClass(const std::string& pszCellStyle) const
{
#if defined(_BRXTARGET270)
    throw PyNotimplementedByHost();
#else
    return impObj()->cellClass(AsWStr(pszCellStyle));
#endif
}

void PyDbTableStyle::setCellClass(int nClass, const std::string& pszCellStyle) const
{
#if defined(_BRXTARGET270)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setCellClass(nClass, AsWStr(pszCellStyle)));
#endif
}

double PyDbTableStyle::rotation(const std::string& pszCellStyle) const
{
#if defined(_BRXTARGET270)
    throw PyNotimplementedByHost();
#else
    return impObj()->rotation(AsWStr(pszCellStyle));
#endif
}

void PyDbTableStyle::setRotation(double fRotation, const std::string& pszCellStyle) const
{
#if defined(_BRXTARGET270)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setRotation(fRotation, AsWStr(pszCellStyle)));
#endif
}

bool PyDbTableStyle::isMergeAllEnabled(const std::string& pszCellStyle) const
{
#if defined(_BRXTARGET270)
    throw PyNotimplementedByHost();
#else
    return impObj()->isMergeAllEnabled(AsWStr(pszCellStyle));
#endif
}

void PyDbTableStyle::enableMergeAll(bool bEnable, const std::string& pszCellStyle) const
{
#if defined(_BRXTARGET270)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->enableMergeAll(bEnable, AsWStr(pszCellStyle)));
#endif
}

double PyDbTableStyle::margin(AcDb::CellMargin nMargin, const std::string& pszCellStyle) const
{
    return impObj()->margin(nMargin, AsWStr(pszCellStyle));
}

void PyDbTableStyle::setMargin(AcDb::CellMargin nMargins, double fMargin, const std::string& pszCellStyle) const
{
    return PyThrowBadEs(impObj()->setMargin(nMargins, fMargin, AsWStr(pszCellStyle)));
}

double PyDbTableStyle::gridDoubleLineSpacing(AcDb::GridLineType gridLineType, const std::string& pszCellStyle) const
{
#if defined(_BRXTARGET270)
    throw PyNotimplementedByHost();
#else
    return impObj()->gridDoubleLineSpacing(gridLineType, AsWStr(pszCellStyle));
#endif
}

void PyDbTableStyle::setGridDoubleLineSpacing(double fSpacing, AcDb::GridLineType gridLineTypes, const std::string& pszCellStyle) const
{
#if defined(_BRXTARGET270)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setGridDoubleLineSpacing(fSpacing, gridLineTypes, AsWStr(pszCellStyle)));
#endif
}

AcDb::GridLineStyle PyDbTableStyle::gridLineStyle(AcDb::GridLineType gridLineType, const std::string& pszCellStyle) const
{
#if defined(_BRXTARGET270)
    throw PyNotimplementedByHost();
#else
    return impObj()->gridLineStyle(gridLineType, AsWStr(pszCellStyle));
#endif
}

void PyDbTableStyle::setGridLineStyle(AcDb::GridLineStyle nLineStyle, AcDb::GridLineType gridLineTypes, const std::string& pszCellStyle) const
{
#if defined(_BRXTARGET270)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setGridLineStyle(nLineStyle, gridLineTypes, AsWStr(pszCellStyle)));
#endif
}

PyDbObjectId PyDbTableStyle::gridLinetype(AcDb::GridLineType gridLineType, const std::string& pszCellStyle) const
{
#if defined(_BRXTARGET270)
    throw PyNotimplementedByHost();
#else
    return PyDbObjectId(impObj()->gridLinetype(gridLineType, AsWStr(pszCellStyle)));
#endif
}

void PyDbTableStyle::setGridLinetype(const PyDbObjectId& id, AcDb::GridLineType gridLineTypes, const std::string& pszCellStyle) const
{
#if defined(_BRXTARGET270)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setGridLinetype(id.m_id, gridLineTypes, AsWStr(pszCellStyle)));
#endif
}

AcGridProperty PyDbTableStyle::getGridProperty(AcDb::GridLineType nGridLineTypes, const std::string& pszCellStyle) const
{
#if defined(_BRXTARGET270)
    throw PyNotimplementedByHost();
#else
    AcGridProperty prop;
    PyThrowBadEs(impObj()->getGridProperty(prop, nGridLineTypes, AsWStr(pszCellStyle)));
    return prop;
#endif
}

void PyDbTableStyle::setGridProperty(const AcGridProperty& gridProp, AcDb::GridLineType nGridLineTypes, const std::string& pszCellStyle) const
{
#if defined(_BRXTARGET270)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setGridProperty(gridProp, nGridLineTypes, AsWStr(pszCellStyle)));
#endif
}

PyDbObjectId PyDbTableStyle::getTemplate(void) const
{
#if defined(_BRXTARGET270)
    throw PyNotimplementedByHost();
#else
    return PyDbObjectId(impObj()->getTemplate());
#endif
}

void PyDbTableStyle::setTemplate(const PyDbObjectId& templateId, AcDb::MergeCellStyleOption nOption) const
{
#if defined(_BRXTARGET270)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setTemplate(templateId.m_id, nOption));
#endif
}

PyDbObjectId PyDbTableStyle::removeTemplate(void) const
{
#if defined(_BRXTARGET270)
    throw PyNotimplementedByHost();
#else
    return PyDbObjectId(impObj()->removeTemplate());
#endif
}

std::string PyDbTableStyle::className()
{
    return "AcDbTableStyle";
}

PyRxClass PyDbTableStyle::desc()
{
    return PyRxClass(AcDbTableStyle::desc(), false);
}

PyDbTableStyle PyDbTableStyle::cloneFrom(const PyRxObject& src)
{
    return PyDbObjectCloneFrom<PyDbTableStyle, AcDbTableStyle>(src);
}

PyDbTableStyle PyDbTableStyle::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbTableStyle>(src);
}

AcDbTableStyle* PyDbTableStyle::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbTableStyle*>(m_pyImp.get());
}
