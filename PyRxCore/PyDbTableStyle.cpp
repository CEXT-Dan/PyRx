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
        .def("getName", &PyDbTableStyle::getName, DS.ARGS())
        .def("setName", &PyDbTableStyle::setName, DS.ARGS({ "val: str" }))
        .def("description", &PyDbTableStyle::description, DS.ARGS())
        .def("setDescription", &PyDbTableStyle::setDescription, DS.ARGS({ "val: str" }))
        .def("bitFlags", &PyDbTableStyle::bitFlags, DS.ARGS())
        .def("setBitFlags", &PyDbTableStyle::setBitFlags, DS.ARGS({ "flags: int" }))
        .def("flowDirection", &PyDbTableStyle::flowDirection, DS.ARGS())
        .def("setFlowDirection", &PyDbTableStyle::setFlowDirection, DS.ARGS({ "val: PyDb.TableFlowDirection" }))
        .def("horzCellMargin", &PyDbTableStyle::horzCellMargin, DS.ARGS())
        .def("setHorzCellMargin", &PyDbTableStyle::setHorzCellMargin, DS.ARGS({ "val: float" }))
        .def("vertCellMargin", &PyDbTableStyle::vertCellMargin, DS.ARGS())
        .def("setVertCellMargin", &PyDbTableStyle::setVertCellMargin, DS.ARGS({ "val: float" }))
        .def("isTitleSuppressed", &PyDbTableStyle::isTitleSuppressed, DS.ARGS())
        .def("suppressTitleRow", &PyDbTableStyle::suppressTitleRow, DS.ARGS({ "val: bool" }))
        .def("isHeaderSuppressed", &PyDbTableStyle::isHeaderSuppressed, DS.ARGS())
        .def("suppressHeaderRow", &PyDbTableStyle::suppressHeaderRow, DS.ARGS({ "val: bool" }))
        .def("textStyle", &PyDbTableStyle::textStyle)
        .def("textStyle", &PyDbTableStyle::textStyle2, DS.OVRL(textStyleOverloads))
        .def("setTextStyle", &PyDbTableStyle::setTextStyle)
        .def("setTextStyle", &PyDbTableStyle::setTextStyle2, DS.OVRL(setTextStyleOverloads))
        .def("textHeight", &PyDbTableStyle::textHeight)
        .def("textHeight", &PyDbTableStyle::textHeight2, DS.OVRL(textHeightOverloads))
        .def("setTextHeight", &PyDbTableStyle::setTextHeight)
        .def("setTextHeight", &PyDbTableStyle::setTextHeight2, DS.OVRL(setTextHeightOverloads))
        .def("alignment", &PyDbTableStyle::alignment)
        .def("alignment", &PyDbTableStyle::alignment2, DS.OVRL(alignmenttOverloads))
        .def("setAlignment", &PyDbTableStyle::setAlignment)
        .def("setAlignment", &PyDbTableStyle::setAlignment2, DS.OVRL(setAlignmenttOverloads))
        .def("color", &PyDbTableStyle::color)
        .def("color", &PyDbTableStyle::color2, DS.OVRL(colorOverloads))
        .def("setColor", &PyDbTableStyle::setColor)
        .def("setColor", &PyDbTableStyle::setColor2, DS.OVRL(setColorOverloads))
        .def("backgroundColor", &PyDbTableStyle::backgroundColor)
        .def("backgroundColor", &PyDbTableStyle::backgroundColor2, DS.OVRL(colorOverloads))
        .def("setBackgroundColor", &PyDbTableStyle::setBackgroundColor)
        .def("setBackgroundColor", &PyDbTableStyle::setBackgroundColor2, DS.OVRL(setColorOverloads))
        .def("isBackgroundColorNone", &PyDbTableStyle::isBackgroundColorNone, DS.ARGS({ "rowType: PyDb.RowType" }))
        .def("setBackgroundColorNone", &PyDbTableStyle::setBackgroundColorNone, DS.ARGS({ "val: bool","rowType: PyDb.RowType" }))
        .def("getDataType", &PyDbTableStyle::getDataType)
        .def("getDataType", &PyDbTableStyle::getDataType2, DS.OVRL(getDataTypeOverloads))
        .def("setDataType", &PyDbTableStyle::setDataType1)
        .def("setDataType", &PyDbTableStyle::setDataType2)
        .def("setDataType", &PyDbTableStyle::setDataType3, DS.OVRL(setDataTypeOverloads))
        .def("format", &PyDbTableStyle::format1)
        .def("format", &PyDbTableStyle::format2)
        .def("format", &PyDbTableStyle::format3, DS.OVRL(formatOverloads))
        .def("setFormat", &PyDbTableStyle::setFormat1)
        .def("setFormat", &PyDbTableStyle::setFormat2)
        .def("setFormat", &PyDbTableStyle::setFormat3, DS.OVRL(setFormatOverloads))
        .def("gridLineWeight", &PyDbTableStyle::gridLineWeight)
        .def("gridLineWeight", &PyDbTableStyle::gridLineWeight2, DS.OVRL(gridLineWeightOverloads))
        .def("setGridLineWeight", &PyDbTableStyle::setGridLineWeight)
        .def("setGridLineWeight", &PyDbTableStyle::setGridLineWeight2, DS.OVRL(setGridLineWeighOverloads))
        .def("gridColor", &PyDbTableStyle::gridColor)
        .def("gridColor", &PyDbTableStyle::gridColor2, DS.OVRL(gridColorOverloads))
        .def("setGridColor", &PyDbTableStyle::setGridColor)
        .def("setGridColor", &PyDbTableStyle::setGridColor2, DS.OVRL(setGridColorOverloads))
        .def("gridVisibility", &PyDbTableStyle::gridVisibility)
        .def("gridVisibility", &PyDbTableStyle::gridVisibility2, DS.OVRL(gridVisibilityOverloads))
        .def("setGridVisibility", &PyDbTableStyle::setGridVisibility)
        .def("setGridVisibility", &PyDbTableStyle::setGridVisibility2, DS.OVRL(setGridVisibilityOverloads))
        .def("postTableStyleToDb", &PyDbTableStyle::postTableStyleToDb, DS.ARGS({ "db: PyDb.Database","styleName: str" }))
        .def("createCellStyle", &PyDbTableStyle::createCellStyle1)
        .def("createCellStyle", &PyDbTableStyle::createCellStyle2)
        .def("createCellStyle", &PyDbTableStyle::createCellStyle3, DS.OVRL(createCellStyleOverloads))
        .def("renameCellStyle", &PyDbTableStyle::renameCellStyle, DS.ARGS({ "pszOldName: str", "pszNewName: str" }))
        .def("deleteCellStyle", &PyDbTableStyle::deleteCellStyle, DS.ARGS({ "pszCellStyle: str" }))
        .def("copyCellStyle", &PyDbTableStyle::copyCellStyle, DS.ARGS({ "pszSrcCellStyle: str", "pszTargetCellStyle: str" }))
        .def("isCellStyleInUse", &PyDbTableStyle::isCellStyleInUse, DS.ARGS({ "pszCellStyle: str" }))
        .def("numCellStyles", &PyDbTableStyle::numCellStyles, DS.ARGS())
        .def("getCellStyles", &PyDbTableStyle::getCellStyles, DS.ARGS())
        .def("cellClass", &PyDbTableStyle::cellClass, DS.ARGS({ "pszCellStyle: str" }))
        .def("setCellClass", &PyDbTableStyle::setCellClass, DS.ARGS({ "val: int","pszCellStyle: str" }))
        .def("rotation", &PyDbTableStyle::rotation, DS.ARGS({ "pszCellStyle: str" }))
        .def("setRotation", &PyDbTableStyle::setRotation, DS.ARGS({ "val: float", "pszCellStyle: str" }))
        .def("isMergeAllEnabled", &PyDbTableStyle::isMergeAllEnabled, DS.ARGS({ "pszCellStyle: str" }))
        .def("enableMergeAll", &PyDbTableStyle::enableMergeAll, DS.ARGS({ "val: bool", "pszCellStyle: str" }))
        .def("margin", &PyDbTableStyle::margin, DS.ARGS({ "nMargin: PyDb.CellMargin", "pszCellStyle: str" }))
        .def("setMargin", &PyDbTableStyle::setMargin, DS.ARGS({ "nMargins: PyDb.CellMargin","val: float", "pszCellStyle: str" }))
        .def("gridDoubleLineSpacing", &PyDbTableStyle::gridDoubleLineSpacing, DS.ARGS({ "gridLineType: PyDb.GridLineType", "pszCellStyle: str" }))
        .def("setGridDoubleLineSpacing", &PyDbTableStyle::setGridDoubleLineSpacing, DS.ARGS({ "val: float","gridLineTypes: PyDb.GridLineType", "pszCellStyle: str" }))
        .def("gridLineStyle", &PyDbTableStyle::gridLineStyle, DS.ARGS({ "gridLineType: PyDb.GridLineType", "pszCellStyle: str" }))
        .def("setGridLineStyle", &PyDbTableStyle::setGridLineStyle, DS.ARGS({ "nLineStyle: PyDb.GridLineStyle","gridLineType: PyDb.GridLineType", "pszCellStyle: str" }))
        .def("gridLinetype", &PyDbTableStyle::gridLinetype, DS.ARGS({ "gridLineType: PyDb.GridLineType", "pszCellStyle: str" }))
        .def("setGridLinetype", &PyDbTableStyle::setGridLinetype, DS.ARGS({ "id: PyDb.ObjectId", "gridLineType: PyDb.GridLineType", "pszCellStyle: str" }))
        .def("getGridProperty", &PyDbTableStyle::getGridProperty, DS.ARGS({ "gridLineType: PyDb.GridLineType", "pszCellStyle: str" }))
        .def("setGridProperty", &PyDbTableStyle::setGridProperty, DS.ARGS({ "gridProp: PyDb.GridProperty", "gridLineType: PyDb.GridLineType", "pszCellStyle: str" }))
        .def("getTemplate", &PyDbTableStyle::getTemplate, DS.ARGS())
        .def("setTemplate", &PyDbTableStyle::setTemplate, DS.ARGS({ "id: PyDb.ObjectId" , "nOption: PyDb.MergeCellStyleOption" }))
        .def("removeTemplate", &PyDbTableStyle::removeTemplate, DS.ARGS())
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
#if defined(_BRXTARGET250)
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
    return PyThrowBadEs(impObj()->setName(utf8_to_wstr(pszName).c_str()));
}

std::string PyDbTableStyle::description(void) const
{
    return wstr_to_utf8(impObj()->description());
}

void PyDbTableStyle::setDescription(const std::string& pszDescription) const
{
    return PyThrowBadEs(impObj()->setName(utf8_to_wstr(pszDescription).c_str()));
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
    return PyDbObjectId(impObj()->textStyle(utf8_to_wstr(pszCellStyle).c_str()));
}

void PyDbTableStyle::setTextStyle(const PyDbObjectId& id, AcDb::RowType rowType) const
{
    return PyThrowBadEs(impObj()->setTextStyle(id.m_id, rowType));
}

void PyDbTableStyle::setTextStyle2(const PyDbObjectId& id, const std::string& pszCellStyle) const
{
    return PyThrowBadEs(impObj()->setTextStyle(id.m_id, utf8_to_wstr(pszCellStyle).c_str()));
}

double PyDbTableStyle::textHeight(AcDb::RowType rowType) const
{
    return impObj()->textHeight(rowType);
}

double PyDbTableStyle::textHeight2(const std::string& pszCellStyle) const
{
    return impObj()->textHeight(utf8_to_wstr(pszCellStyle).c_str());
}

void PyDbTableStyle::setTextHeight(double dHeight, AcDb::RowType rowType) const
{
    return PyThrowBadEs(impObj()->setTextHeight(dHeight, rowType));
}

void PyDbTableStyle::setTextHeight2(double dHeight, const std::string& pszCellStyle) const
{
    return PyThrowBadEs(impObj()->setTextHeight(dHeight, utf8_to_wstr(pszCellStyle).c_str()));
}

AcDb::CellAlignment PyDbTableStyle::alignment(AcDb::RowType rowType) const
{
    return impObj()->alignment(rowType);
}

AcDb::CellAlignment PyDbTableStyle::alignment2(const std::string& pszCellStyle) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return impObj()->alignment(utf8_to_wstr(pszCellStyle).c_str());
#endif
}

void PyDbTableStyle::setAlignment(AcDb::CellAlignment alignment, AcDb::RowType rowType) const
{
    return PyThrowBadEs(impObj()->setAlignment(alignment, rowType));
}

void PyDbTableStyle::setAlignment2(AcDb::CellAlignment alignment, const std::string& pszCellStyle) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setAlignment(alignment, utf8_to_wstr(pszCellStyle).c_str()));
#endif
}

AcCmColor PyDbTableStyle::color(AcDb::RowType rowType) const
{
    return impObj()->color(rowType);
}

AcCmColor PyDbTableStyle::color2(const std::string& pszCellStyle) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return impObj()->color(utf8_to_wstr(pszCellStyle).c_str());
#endif
}

void PyDbTableStyle::setColor(const AcCmColor& color, AcDb::RowType rowType) const
{
    return PyThrowBadEs(impObj()->setColor(color, rowType));
}

void PyDbTableStyle::setColor2(const AcCmColor& color, const std::string& pszCellStyle) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setColor(color, utf8_to_wstr(pszCellStyle).c_str()));
#endif
}

AcCmColor PyDbTableStyle::backgroundColor(AcDb::RowType rowType) const
{
    return impObj()->backgroundColor(rowType);
}

AcCmColor PyDbTableStyle::backgroundColor2(const std::string& pszCellStyle) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return impObj()->backgroundColor(utf8_to_wstr(pszCellStyle).c_str());
#endif
}

void PyDbTableStyle::setBackgroundColor(const AcCmColor& color, AcDb::RowType rowType) const
{
    return PyThrowBadEs(impObj()->setBackgroundColor(color, rowType));
}

void PyDbTableStyle::setBackgroundColor2(const AcCmColor& color, const std::string& pszCellStyle) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setBackgroundColor(color, utf8_to_wstr(pszCellStyle).c_str()));
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
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    PyAutoLockGIL lock;
    AcValue::DataType nDataType = AcValue::kUnknown;
    AcValue::UnitType nUnitType = AcValue::kUnitless;
    PyThrowBadEs(impObj()->getDataType(nDataType, nUnitType, utf8_to_wstr(pszCellStyle).c_str()));
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
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setDataType(nDataType, nUnitType, utf8_to_wstr(pszCellStyle).c_str()));
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
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return wstr_to_utf8(impObj()->format(utf8_to_wstr(pszCellStyle).c_str()));
#endif
}

void PyDbTableStyle::setFormat1(const std::string& pszFormat) const
{
    return PyThrowBadEs(impObj()->setFormat(utf8_to_wstr(pszFormat).c_str()));
}

void PyDbTableStyle::setFormat2(const std::string& pszFormat, AcDb::RowType type) const
{
    return PyThrowBadEs(impObj()->setFormat(utf8_to_wstr(pszFormat).c_str(), type));
}

void PyDbTableStyle::setFormat3(const std::string& pszFormat, const std::string& pszCellStyle) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setFormat(utf8_to_wstr(pszFormat).c_str(), utf8_to_wstr(pszCellStyle).c_str()));
#endif
}

AcDb::LineWeight PyDbTableStyle::gridLineWeight(AcDb::GridLineType gridLineType, AcDb::RowType rowType) const
{
    return impObj()->gridLineWeight(gridLineType, rowType);
}

AcDb::LineWeight PyDbTableStyle::gridLineWeight2(AcDb::GridLineType gridLineType, const std::string& pszCellStyle) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return impObj()->gridLineWeight(gridLineType, utf8_to_wstr(pszCellStyle).c_str());
#endif
}

void PyDbTableStyle::setGridLineWeight(AcDb::LineWeight lineWeight, AcDb::GridLineType gridLineType, AcDb::RowType rowType) const
{
    return PyThrowBadEs(impObj()->setGridLineWeight(lineWeight, gridLineType, rowType));
}

void PyDbTableStyle::setGridLineWeight2(AcDb::LineWeight lineWeight, AcDb::GridLineType gridLineTypes, const std::string& pszCellStyle) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setGridLineWeight(lineWeight, gridLineTypes, utf8_to_wstr(pszCellStyle).c_str()));
#endif
}

AcCmColor PyDbTableStyle::gridColor(AcDb::GridLineType gridLineType, AcDb::RowType rowType) const
{
    return impObj()->gridColor(gridLineType, rowType);
}

AcCmColor PyDbTableStyle::gridColor2(AcDb::GridLineType gridLineType, const std::string& pszCellStyle) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return impObj()->gridColor(gridLineType, utf8_to_wstr(pszCellStyle).c_str());
#endif
}

void PyDbTableStyle::setGridColor(const AcCmColor& color, AcDb::GridLineType gridLineType, AcDb::RowType rowType) const
{
    return PyThrowBadEs(impObj()->setGridColor(color, gridLineType, rowType));
}

void PyDbTableStyle::setGridColor2(const AcCmColor& color, AcDb::GridLineType gridLineTypes, const std::string& pszCellStyle) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setGridColor(color, gridLineTypes, utf8_to_wstr(pszCellStyle).c_str()));
#endif
}

AcDb::Visibility PyDbTableStyle::gridVisibility(AcDb::GridLineType gridLineType, AcDb::RowType rowType) const
{
    return impObj()->gridVisibility(gridLineType, rowType);
}

AcDb::Visibility PyDbTableStyle::gridVisibility2(AcDb::GridLineType gridLineType, const std::string& pszCellStyle) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return impObj()->gridVisibility(gridLineType, utf8_to_wstr(pszCellStyle).c_str());
#endif
}

void PyDbTableStyle::setGridVisibility(AcDb::Visibility visible, AcDb::GridLineType gridLineType, AcDb::RowType rowType) const
{
    return PyThrowBadEs(impObj()->setGridVisibility(visible, gridLineType, rowType));
}

void PyDbTableStyle::setGridVisibility2(AcDb::Visibility visible, AcDb::GridLineType gridLineTypes, const std::string& pszCellStyle) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setGridVisibility(visible, gridLineTypes, utf8_to_wstr(pszCellStyle).c_str()));
#endif
}

PyDbObjectId PyDbTableStyle::postTableStyleToDb(PyDbDatabase& pDb, const std::string& styleName) const
{
    AcDbObjectId id;
    PyThrowBadEs(impObj()->postTableStyleToDb(pDb.impObj(), utf8_to_wstr(styleName).c_str(), id));
    return PyDbObjectId(id);
}

std::string PyDbTableStyle::createCellStyle1(void) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return wstr_to_utf8(impObj()->createCellStyle());
#endif
}

void PyDbTableStyle::createCellStyle2(const std::string& pszCellStyle) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->createCellStyle(utf8_to_wstr(pszCellStyle).c_str()));
#endif
}

void PyDbTableStyle::createCellStyle3(const std::string& pszCellStyle, const std::string& pszFromCellStyle) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->createCellStyle(utf8_to_wstr(pszCellStyle).c_str(), utf8_to_wstr(pszFromCellStyle).c_str()));
#endif
}

void PyDbTableStyle::renameCellStyle(const std::string& pszOldName, const std::string& pszNewName) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->renameCellStyle(utf8_to_wstr(pszOldName).c_str(), utf8_to_wstr(pszNewName).c_str()));
#endif
}

void PyDbTableStyle::deleteCellStyle(const std::string& pszCellStyle) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->deleteCellStyle(utf8_to_wstr(pszCellStyle).c_str()));
#endif
}

void PyDbTableStyle::copyCellStyle(const std::string& pszSrcCellStyle, const std::string& pszTargetCellStyle) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->copyCellStyle(utf8_to_wstr(pszSrcCellStyle).c_str(), utf8_to_wstr(pszTargetCellStyle).c_str()));
#endif
}

bool PyDbTableStyle::isCellStyleInUse(const std::string& pszCellStyle) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return impObj()->isCellStyleInUse(utf8_to_wstr(pszCellStyle).c_str());
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
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return impObj()->cellClass(utf8_to_wstr(pszCellStyle).c_str());
#endif
}

void PyDbTableStyle::setCellClass(int nClass, const std::string& pszCellStyle) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setCellClass(nClass, utf8_to_wstr(pszCellStyle).c_str()));
#endif
}

double PyDbTableStyle::rotation(const std::string& pszCellStyle) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return impObj()->rotation(utf8_to_wstr(pszCellStyle).c_str());
#endif
}

void PyDbTableStyle::setRotation(double fRotation, const std::string& pszCellStyle) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setRotation(fRotation, utf8_to_wstr(pszCellStyle).c_str()));
#endif
}

bool PyDbTableStyle::isMergeAllEnabled(const std::string& pszCellStyle) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return impObj()->isMergeAllEnabled(utf8_to_wstr(pszCellStyle).c_str());
#endif
}

void PyDbTableStyle::enableMergeAll(bool bEnable, const std::string& pszCellStyle) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->enableMergeAll(bEnable, utf8_to_wstr(pszCellStyle).c_str()));
#endif
}

double PyDbTableStyle::margin(AcDb::CellMargin nMargin, const std::string& pszCellStyle) const
{
    return impObj()->margin(nMargin, utf8_to_wstr(pszCellStyle).c_str());
}

void PyDbTableStyle::setMargin(AcDb::CellMargin nMargins, double fMargin, const std::string& pszCellStyle) const
{
    return PyThrowBadEs(impObj()->setMargin(nMargins, fMargin, utf8_to_wstr(pszCellStyle).c_str()));
}

double PyDbTableStyle::gridDoubleLineSpacing(AcDb::GridLineType gridLineType, const std::string& pszCellStyle) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return impObj()->gridDoubleLineSpacing(gridLineType, utf8_to_wstr(pszCellStyle).c_str());
#endif
}

void PyDbTableStyle::setGridDoubleLineSpacing(double fSpacing, AcDb::GridLineType gridLineTypes, const std::string& pszCellStyle) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setGridDoubleLineSpacing(fSpacing, gridLineTypes, utf8_to_wstr(pszCellStyle).c_str()));
#endif
}

AcDb::GridLineStyle PyDbTableStyle::gridLineStyle(AcDb::GridLineType gridLineType, const std::string& pszCellStyle) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return impObj()->gridLineStyle(gridLineType, utf8_to_wstr(pszCellStyle).c_str());
#endif
}

void PyDbTableStyle::setGridLineStyle(AcDb::GridLineStyle nLineStyle, AcDb::GridLineType gridLineTypes, const std::string& pszCellStyle) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setGridLineStyle(nLineStyle, gridLineTypes, utf8_to_wstr(pszCellStyle).c_str()));
#endif
}

PyDbObjectId PyDbTableStyle::gridLinetype(AcDb::GridLineType gridLineType, const std::string& pszCellStyle) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyDbObjectId(impObj()->gridLinetype(gridLineType, utf8_to_wstr(pszCellStyle).c_str()));
#endif
}

void PyDbTableStyle::setGridLinetype(const PyDbObjectId& id, AcDb::GridLineType gridLineTypes, const std::string& pszCellStyle) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setGridLinetype(id.m_id, gridLineTypes, utf8_to_wstr(pszCellStyle).c_str()));
#endif
}

AcGridProperty PyDbTableStyle::getGridProperty(AcDb::GridLineType nGridLineTypes, const std::string& pszCellStyle) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    AcGridProperty prop;
    PyThrowBadEs(impObj()->getGridProperty(prop, nGridLineTypes, utf8_to_wstr(pszCellStyle).c_str()));
    return prop;
#endif
}

void PyDbTableStyle::setGridProperty(const AcGridProperty& gridProp, AcDb::GridLineType nGridLineTypes, const std::string& pszCellStyle) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setGridProperty(gridProp, nGridLineTypes, utf8_to_wstr(pszCellStyle).c_str()));
#endif
}

PyDbObjectId PyDbTableStyle::getTemplate(void) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyDbObjectId(impObj()->getTemplate());
#endif
}

void PyDbTableStyle::setTemplate(const PyDbObjectId& templateId, AcDb::MergeCellStyleOption nOption) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setTemplate(templateId.m_id, nOption));
#endif
}

PyDbObjectId PyDbTableStyle::removeTemplate(void) const
{
#if defined(_BRXTARGET250)
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
