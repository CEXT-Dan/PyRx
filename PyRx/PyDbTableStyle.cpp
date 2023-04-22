#include "stdafx.h"
#include "PyDbTableStyle.h"
#include "PyDbObjectId.h"

using namespace boost::python;
void makeAcDbTableStyleWrapper()
{
    class_<PyDbTableStyle, bases<PyDbObject>>("TableStyle")
        .def(init<>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("getName", &PyDbTableStyle::getName)
        .def("setName", &PyDbTableStyle::setName)
        .def("description", &PyDbTableStyle::description)
        .def("setDescription", &PyDbTableStyle::setDescription)
        .def("bitFlags", &PyDbTableStyle::bitFlags)
        .def("setBitFlags", &PyDbTableStyle::setBitFlags)
        .def("flowDirection", &PyDbTableStyle::flowDirection)
        .def("setFlowDirection", &PyDbTableStyle::setFlowDirection)
        .def("horzCellMargin", &PyDbTableStyle::horzCellMargin)
        .def("setHorzCellMargin", &PyDbTableStyle::setHorzCellMargin)
        .def("vertCellMargin", &PyDbTableStyle::vertCellMargin)
        .def("setVertCellMargin", &PyDbTableStyle::setVertCellMargin)
        .def("isTitleSuppressed", &PyDbTableStyle::isTitleSuppressed)
        .def("suppressTitleRow", &PyDbTableStyle::suppressTitleRow)
        .def("isHeaderSuppressed", &PyDbTableStyle::isHeaderSuppressed)
        .def("suppressHeaderRow", &PyDbTableStyle::suppressHeaderRow)
        .def("textStyle", &PyDbTableStyle::textStyle)
        .def("setTextStyle", &PyDbTableStyle::setTextStyle)
        .def("textHeight", &PyDbTableStyle::textHeight)
        .def("setTextHeight", &PyDbTableStyle::setTextHeight)
        .def("alignment", &PyDbTableStyle::alignment)
        .def("setAlignment", &PyDbTableStyle::setAlignment)
        .def("color", &PyDbTableStyle::color)
        .def("setColor", &PyDbTableStyle::setColor)
        .def("backgroundColor", &PyDbTableStyle::backgroundColor)
        .def("setBackgroundColor", &PyDbTableStyle::setBackgroundColor)
        .def("isBackgroundColorNone", &PyDbTableStyle::isBackgroundColorNone)
        .def("setBackgroundColorNone", &PyDbTableStyle::setBackgroundColorNone)
        .def("getDataType", &PyDbTableStyle::getDataType)
        .def("setDataType", &PyDbTableStyle::setDataType1)
        .def("setDataType", &PyDbTableStyle::setDataType2)
        .def("format", &PyDbTableStyle::format1)
        .def("format", &PyDbTableStyle::format2)
        .def("setFormat", &PyDbTableStyle::setFormat1)
        .def("setFormat", &PyDbTableStyle::setFormat2)
        .def("gridLineWeight", &PyDbTableStyle::gridLineWeight)
        .def("setGridLineWeight", &PyDbTableStyle::setGridLineWeight)
        .def("gridColor", &PyDbTableStyle::gridColor)
        .def("setGridColor", &PyDbTableStyle::setGridColor)
        .def("gridVisibility", &PyDbTableStyle::gridVisibility)
        .def("setGridVisibility", &PyDbTableStyle::setGridVisibility)
        .def("postTableStyleToDb", &PyDbTableStyle::postTableStyleToDb)
        .def("createCellStyle", &PyDbTableStyle::createCellStyle1)
        .def("createCellStyle", &PyDbTableStyle::createCellStyle2)
        .def("createCellStyle", &PyDbTableStyle::createCellStyle3)
        .def("renameCellStyle", &PyDbTableStyle::renameCellStyle)
        .def("deleteCellStyle", &PyDbTableStyle::deleteCellStyle)
        .def("copyCellStyle", &PyDbTableStyle::copyCellStyle)
        .def("isCellStyleInUse", &PyDbTableStyle::isCellStyleInUse)
        .def("numCellStyles", &PyDbTableStyle::numCellStyles)
        .def("getCellStyles", &PyDbTableStyle::getCellStyles)
        .def("textStyle", &PyDbTableStyle::textStyle2)
        .def("setTextStyle", &PyDbTableStyle::setTextStyle2)
        .def("textHeight", &PyDbTableStyle::textHeight2)
        .def("setTextHeight", &PyDbTableStyle::setTextHeight2)
        .def("alignment", &PyDbTableStyle::alignment2)
        .def("setAlignment", &PyDbTableStyle::setAlignment2)
        .def("color", &PyDbTableStyle::color2)
        .def("setColor", &PyDbTableStyle::setColor2)
        .def("backgroundColor", &PyDbTableStyle::backgroundColor2)
        .def("setBackgroundColor", &PyDbTableStyle::setBackgroundColor2)
        .def("getDataType", &PyDbTableStyle::getDataType2)
        .def("setDataType", &PyDbTableStyle::setDataType3)
        .def("format", &PyDbTableStyle::format3)
        .def("setFormat", &PyDbTableStyle::setFormat3)
        .def("cellClass", &PyDbTableStyle::cellClass)
        .def("setCellClass", &PyDbTableStyle::setCellClass)
        .def("rotation", &PyDbTableStyle::rotation)
        .def("setRotation", &PyDbTableStyle::setRotation)
        .def("isMergeAllEnabled", &PyDbTableStyle::isMergeAllEnabled)
        .def("enableMergeAll", &PyDbTableStyle::enableMergeAll)
        .def("margin", &PyDbTableStyle::margin)
        .def("setMargin", &PyDbTableStyle::setMargin)
        .def("gridLineWeight", &PyDbTableStyle::gridLineWeight2)
        .def("setGridLineWeight", &PyDbTableStyle::setGridLineWeight2)
        .def("gridColor", &PyDbTableStyle::gridColor2)
        .def("setGridColor", &PyDbTableStyle::setGridColor2)
        .def("gridVisibility", &PyDbTableStyle::gridVisibility2)
        .def("setGridVisibility", &PyDbTableStyle::setGridVisibility2)
        .def("gridDoubleLineSpacing", &PyDbTableStyle::gridDoubleLineSpacing)
        .def("setGridDoubleLineSpacing", &PyDbTableStyle::setGridDoubleLineSpacing)
        .def("gridLineStyle", &PyDbTableStyle::gridLineStyle)
        .def("setGridLineStyle", &PyDbTableStyle::setGridLineStyle)
        .def("gridLinetype", &PyDbTableStyle::gridLinetype)
        .def("setGridLinetype", &PyDbTableStyle::setGridLinetype)
        .def("getGridProperty", &PyDbTableStyle::getGridProperty)
        .def("setGridProperty", &PyDbTableStyle::setGridProperty)
        .def("getTemplate", &PyDbTableStyle::getTemplate)
        .def("setTemplate", &PyDbTableStyle::setTemplate)
        .def("removeTemplate", &PyDbTableStyle::removeTemplate)
        .def("className", &PyDbTableStyle::className).staticmethod("className")
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

PyDbTableStyle::PyDbTableStyle(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbObject(nullptr, false)
{
    AcDbTableStyle* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbTableStyle>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    this->resetImp(pobj, false, true);
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
}

std::string PyDbTableStyle::getName()
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    AcString name;
    if (auto es = impObj()->getName(name); es != eOk)
        throw PyAcadErrorStatus(es);
    return wstr_to_utf8(name);
#endif
}

Acad::ErrorStatus PyDbTableStyle::setName(const std::string& pszName)
{
    return impObj()->setName(utf8_to_wstr(pszName).c_str());
}

std::string PyDbTableStyle::description(void) const
{
    return wstr_to_utf8(impObj()->description());
}

Acad::ErrorStatus PyDbTableStyle::setDescription(const std::string& pszDescription)
{
    return impObj()->setName(utf8_to_wstr(pszDescription).c_str());
}

Adesk::UInt32 PyDbTableStyle::bitFlags() const
{
    return impObj()->bitFlags();
}

Acad::ErrorStatus PyDbTableStyle::setBitFlags(Adesk::UInt32 flags)
{
    return impObj()->setBitFlags(flags);
}

AcDb::FlowDirection PyDbTableStyle::flowDirection(void) const
{
    return impObj()->flowDirection();
}

Acad::ErrorStatus PyDbTableStyle::setFlowDirection(AcDb::FlowDirection flow)
{
    return  impObj()->setFlowDirection(flow);
}

double PyDbTableStyle::horzCellMargin(void) const
{
    return  impObj()->horzCellMargin();
}

Acad::ErrorStatus PyDbTableStyle::setHorzCellMargin(double dCellMargin)
{
    return impObj()->setHorzCellMargin(dCellMargin);
}

double PyDbTableStyle::vertCellMargin(void) const
{
    return impObj()->vertCellMargin();
}

Acad::ErrorStatus PyDbTableStyle::setVertCellMargin(double dCellMargin)
{
    return impObj()->setVertCellMargin(dCellMargin);
}

bool PyDbTableStyle::isTitleSuppressed(void) const
{
    return impObj()->isTitleSuppressed();
}

Acad::ErrorStatus PyDbTableStyle::suppressTitleRow(bool bValue)
{
    return impObj()->suppressTitleRow(bValue);
}

bool PyDbTableStyle::isHeaderSuppressed(void) const
{
    return impObj()->isHeaderSuppressed();
}

Acad::ErrorStatus PyDbTableStyle::suppressHeaderRow(bool bValue)
{
    return impObj()->suppressHeaderRow(bValue);
}

PyDbObjectId PyDbTableStyle::textStyle(AcDb::RowType rowType) const
{
    return PyDbObjectId(impObj()->textStyle(rowType));
}

PyDbObjectId PyDbTableStyle::textStyle2(const std::string& pszCellStyle) const
{
    return PyDbObjectId(impObj()->textStyle(utf8_to_wstr(pszCellStyle).c_str()));
}

Acad::ErrorStatus PyDbTableStyle::setTextStyle(const PyDbObjectId& id, AcDb::RowType rowType)
{
    return impObj()->setTextStyle(id.m_id, rowType);
}

Acad::ErrorStatus PyDbTableStyle::setTextStyle2(const PyDbObjectId& id, const std::string& pszCellStyle)
{
    return impObj()->setTextStyle(id.m_id, utf8_to_wstr(pszCellStyle).c_str());
}

double PyDbTableStyle::textHeight(AcDb::RowType rowType) const
{
    return impObj()->textHeight(rowType);
}

double PyDbTableStyle::textHeight2(const std::string& pszCellStyle) const
{
    return impObj()->textHeight(utf8_to_wstr(pszCellStyle).c_str());
}

Acad::ErrorStatus PyDbTableStyle::setTextHeight(double dHeight, AcDb::RowType rowType)
{
    return impObj()->setTextHeight(dHeight, rowType);
}

Acad::ErrorStatus PyDbTableStyle::setTextHeight2(double dHeight, const std::string& pszCellStyle)
{
    return impObj()->setTextHeight(dHeight, utf8_to_wstr(pszCellStyle).c_str());
}

AcDb::CellAlignment PyDbTableStyle::alignment(AcDb::RowType rowType) const
{
    return impObj()->alignment(rowType);
}

AcDb::CellAlignment PyDbTableStyle::alignment2(const std::string& pszCellStyle) const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->alignment(utf8_to_wstr(pszCellStyle).c_str());
#endif
}

Acad::ErrorStatus PyDbTableStyle::setAlignment(AcDb::CellAlignment alignment, AcDb::RowType rowType)
{
    return impObj()->setAlignment(alignment, rowType);
}

Acad::ErrorStatus PyDbTableStyle::setAlignment2(AcDb::CellAlignment alignment, const std::string& pszCellStyle)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setAlignment(alignment, utf8_to_wstr(pszCellStyle).c_str());
#endif
}

AcCmColor PyDbTableStyle::color(AcDb::RowType rowType) const
{
    return impObj()->color(rowType);
}

AcCmColor PyDbTableStyle::color2(const std::string& pszCellStyle) const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->color(utf8_to_wstr(pszCellStyle).c_str());
#endif
}

Acad::ErrorStatus PyDbTableStyle::setColor(const AcCmColor& color, AcDb::RowType rowType)
{
    return impObj()->setColor(color, rowType);
}

Acad::ErrorStatus PyDbTableStyle::setColor2(const AcCmColor& color, const std::string& pszCellStyle)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setColor(color, utf8_to_wstr(pszCellStyle).c_str());
#endif
}

AcCmColor PyDbTableStyle::backgroundColor(AcDb::RowType rowType) const
{
    return impObj()->backgroundColor(rowType);
}

AcCmColor PyDbTableStyle::backgroundColor2(const std::string& pszCellStyle) const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->backgroundColor(utf8_to_wstr(pszCellStyle).c_str());
#endif
}

Acad::ErrorStatus PyDbTableStyle::setBackgroundColor(const AcCmColor& color, AcDb::RowType rowType)
{
    return impObj()->setBackgroundColor(color, rowType);
}

Acad::ErrorStatus PyDbTableStyle::setBackgroundColor2(const AcCmColor& color, const std::string& pszCellStyle)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setBackgroundColor(color, utf8_to_wstr(pszCellStyle).c_str());
#endif
}

bool PyDbTableStyle::isBackgroundColorNone(AcDb::RowType rowType) const
{
    return impObj()->isBackgroundColorNone(rowType);
}

Acad::ErrorStatus PyDbTableStyle::setBackgroundColorNone(bool bValue, AcDb::RowType rowType)
{
    return impObj()->setBackgroundColorNone(bValue, rowType);
}

boost::python::tuple PyDbTableStyle::getDataType(AcDb::RowType type) const
{
    AcValue::DataType nDataType = AcValue::kUnknown;
    AcValue::UnitType nUnitType = AcValue::kUnitless;
    if (auto es = impObj()->getDataType(nDataType, nUnitType, type); es != eOk)
        throw PyAcadErrorStatus(es);
    return boost::python::make_tuple(nDataType, nUnitType);
}

boost::python::tuple PyDbTableStyle::getDataType2(const std::string& pszCellStyle) const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    AcValue::DataType nDataType = AcValue::kUnknown;
    AcValue::UnitType nUnitType = AcValue::kUnitless;
    if (auto es = impObj()->getDataType(nDataType, nUnitType, utf8_to_wstr(pszCellStyle).c_str()); es != eOk)
        throw PyAcadErrorStatus(es);
    return boost::python::make_tuple(nDataType, nUnitType);
#endif
}

Acad::ErrorStatus PyDbTableStyle::setDataType1(AcValue::DataType nDataType, AcValue::UnitType nUnitType)
{
    return impObj()->setDataType(nDataType, nUnitType);
}

Acad::ErrorStatus PyDbTableStyle::setDataType2(AcValue::DataType nDataType, AcValue::UnitType nUnitType, AcDb::RowType type)
{
    return impObj()->setDataType(nDataType, nUnitType, type);
}

Acad::ErrorStatus PyDbTableStyle::setDataType3(AcValue::DataType nDataType, AcValue::UnitType nUnitType, const std::string& pszCellStyle)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setDataType(nDataType, nUnitType, utf8_to_wstr(pszCellStyle).c_str());
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
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return wstr_to_utf8(impObj()->format(utf8_to_wstr(pszCellStyle).c_str()));
#endif
}

Acad::ErrorStatus PyDbTableStyle::setFormat1(const std::string& pszFormat)
{
    return impObj()->setFormat(utf8_to_wstr(pszFormat).c_str());
}

Acad::ErrorStatus PyDbTableStyle::setFormat2(const std::string& pszFormat, AcDb::RowType type)
{
    return impObj()->setFormat(utf8_to_wstr(pszFormat).c_str(), type);
}

Acad::ErrorStatus PyDbTableStyle::setFormat3(const std::string& pszFormat, const std::string& pszCellStyle)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setFormat(utf8_to_wstr(pszFormat).c_str(), utf8_to_wstr(pszCellStyle).c_str());
#endif
}

AcDb::LineWeight PyDbTableStyle::gridLineWeight(AcDb::GridLineType gridLineType, AcDb::RowType rowType) const
{
    return impObj()->gridLineWeight(gridLineType, rowType);
}

AcDb::LineWeight PyDbTableStyle::gridLineWeight2(AcDb::GridLineType gridLineType, const std::string& pszCellStyle) const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->gridLineWeight(gridLineType, utf8_to_wstr(pszCellStyle).c_str());
#endif
}

Acad::ErrorStatus PyDbTableStyle::setGridLineWeight(AcDb::LineWeight lineWeight, AcDb::GridLineType gridLineType, AcDb::RowType rowType)
{
    return impObj()->setGridLineWeight(lineWeight, gridLineType, rowType);
}

Acad::ErrorStatus PyDbTableStyle::setGridLineWeight2(AcDb::LineWeight lineWeight, AcDb::GridLineType gridLineTypes, const std::string& pszCellStyle)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setGridLineWeight(lineWeight, gridLineTypes, utf8_to_wstr(pszCellStyle).c_str());
#endif
}

AcCmColor PyDbTableStyle::gridColor(AcDb::GridLineType gridLineType, AcDb::RowType rowType) const
{
    return impObj()->gridColor(gridLineType, rowType);
}

AcCmColor PyDbTableStyle::gridColor2(AcDb::GridLineType gridLineType, const std::string& pszCellStyle) const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->gridColor(gridLineType, utf8_to_wstr(pszCellStyle).c_str());
#endif
}

Acad::ErrorStatus PyDbTableStyle::setGridColor(const AcCmColor& color, AcDb::GridLineType gridLineType, AcDb::RowType rowType)
{
    return impObj()->setGridColor(color, gridLineType, rowType);
}

Acad::ErrorStatus PyDbTableStyle::setGridColor2(const AcCmColor& color, AcDb::GridLineType gridLineTypes, const std::string& pszCellStyle)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setGridColor(color, gridLineTypes, utf8_to_wstr(pszCellStyle).c_str());
#endif
}

AcDb::Visibility PyDbTableStyle::gridVisibility(AcDb::GridLineType gridLineType, AcDb::RowType rowType) const
{
    return impObj()->gridVisibility(gridLineType, rowType);
}

AcDb::Visibility PyDbTableStyle::gridVisibility2(AcDb::GridLineType gridLineType, const std::string& pszCellStyle) const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->gridVisibility(gridLineType, utf8_to_wstr(pszCellStyle).c_str());
#endif
}

Acad::ErrorStatus PyDbTableStyle::setGridVisibility(AcDb::Visibility visible, AcDb::GridLineType gridLineType, AcDb::RowType rowType)
{
    return impObj()->setGridVisibility(visible, gridLineType, rowType);
}

Acad::ErrorStatus PyDbTableStyle::setGridVisibility2(AcDb::Visibility visible, AcDb::GridLineType gridLineTypes, const std::string& pszCellStyle)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setGridVisibility(visible, gridLineTypes, utf8_to_wstr(pszCellStyle).c_str());
#endif
}

PyDbObjectId PyDbTableStyle::postTableStyleToDb(PyDbDatabase& pDb, const std::string& styleName)
{
    AcDbObjectId id;
    if (auto es = impObj()->postTableStyleToDb(pDb.impObj(), utf8_to_wstr(styleName).c_str(), id); es != eOk)
        throw PyAcadErrorStatus(es);
    return PyDbObjectId(id);
}

std::string PyDbTableStyle::createCellStyle1(void)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return wstr_to_utf8(impObj()->createCellStyle());
#endif
}

Acad::ErrorStatus PyDbTableStyle::createCellStyle2(const std::string& pszCellStyle)
{
    return impObj()->createCellStyle(utf8_to_wstr(pszCellStyle).c_str());
}

Acad::ErrorStatus PyDbTableStyle::createCellStyle3(const std::string& pszCellStyle, const std::string& pszFromCellStyle)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->createCellStyle(utf8_to_wstr(pszCellStyle).c_str(), utf8_to_wstr(pszFromCellStyle).c_str());
#endif
}

Acad::ErrorStatus PyDbTableStyle::renameCellStyle(const std::string& pszOldName, const std::string& pszNewName)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->renameCellStyle(utf8_to_wstr(pszOldName).c_str(), utf8_to_wstr(pszNewName).c_str());
#endif
}

Acad::ErrorStatus PyDbTableStyle::deleteCellStyle(const std::string& pszCellStyle)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->deleteCellStyle(utf8_to_wstr(pszCellStyle).c_str());
#endif
}

Acad::ErrorStatus PyDbTableStyle::copyCellStyle(const std::string& pszSrcCellStyle, const std::string& pszTargetCellStyle)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->copyCellStyle(utf8_to_wstr(pszSrcCellStyle).c_str(), utf8_to_wstr(pszTargetCellStyle).c_str());
#endif
}

bool PyDbTableStyle::isCellStyleInUse(const std::string& pszCellStyle) const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->isCellStyleInUse(utf8_to_wstr(pszCellStyle).c_str());
#endif
}

int PyDbTableStyle::numCellStyles(void) const
{
    return impObj()->numCellStyles();
}

boost::python::list PyDbTableStyle::getCellStyles()
{
    AcStringArray cellstyles;
    boost::python::list outList;
    impObj()->getCellStyles(cellstyles);
    for (auto& item : cellstyles)
        outList.append(wstr_to_utf8(item));
    return outList;
}

int PyDbTableStyle::cellClass(const std::string& pszCellStyle) const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->cellClass(utf8_to_wstr(pszCellStyle).c_str());
#endif
}

Acad::ErrorStatus PyDbTableStyle::setCellClass(int nClass, const std::string& pszCellStyle)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setCellClass(nClass, utf8_to_wstr(pszCellStyle).c_str());
#endif
}

double PyDbTableStyle::rotation(const std::string& pszCellStyle) const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->rotation(utf8_to_wstr(pszCellStyle).c_str());
#endif
}

Acad::ErrorStatus PyDbTableStyle::setRotation(double fRotation, const std::string& pszCellStyle)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setRotation(fRotation, utf8_to_wstr(pszCellStyle).c_str());
#endif
}

bool PyDbTableStyle::isMergeAllEnabled(const std::string& pszCellStyle) const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->isMergeAllEnabled(utf8_to_wstr(pszCellStyle).c_str());
#endif
}

Acad::ErrorStatus PyDbTableStyle::enableMergeAll(bool bEnable, const std::string& pszCellStyle)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->enableMergeAll(bEnable, utf8_to_wstr(pszCellStyle).c_str());
#endif
}

double PyDbTableStyle::margin(AcDb::CellMargin nMargin, const std::string& pszCellStyle) const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->margin(nMargin, utf8_to_wstr(pszCellStyle).c_str());
#endif
}

Acad::ErrorStatus PyDbTableStyle::setMargin(AcDb::CellMargin nMargins, double fMargin, const std::string& pszCellStyle)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setMargin(nMargins, fMargin, utf8_to_wstr(pszCellStyle).c_str());
#endif
}

double PyDbTableStyle::gridDoubleLineSpacing(AcDb::GridLineType gridLineType, const std::string& pszCellStyle) const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->gridDoubleLineSpacing(gridLineType, utf8_to_wstr(pszCellStyle).c_str());
#endif
}

Acad::ErrorStatus PyDbTableStyle::setGridDoubleLineSpacing(double fSpacing, AcDb::GridLineType gridLineTypes, const std::string& pszCellStyle)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setGridDoubleLineSpacing(fSpacing, gridLineTypes, utf8_to_wstr(pszCellStyle).c_str());
#endif
}

AcDb::GridLineStyle PyDbTableStyle::gridLineStyle(AcDb::GridLineType gridLineType, const std::string& pszCellStyle) const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->gridLineStyle(gridLineType, utf8_to_wstr(pszCellStyle).c_str());
#endif
}

Acad::ErrorStatus PyDbTableStyle::setGridLineStyle(AcDb::GridLineStyle nLineStyle, AcDb::GridLineType gridLineTypes, const std::string& pszCellStyle)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setGridLineStyle(nLineStyle, gridLineTypes, utf8_to_wstr(pszCellStyle).c_str());
#endif
}

PyDbObjectId PyDbTableStyle::gridLinetype(AcDb::GridLineType gridLineType, const std::string& pszCellStyle) const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return PyDbObjectId(impObj()->gridLinetype(gridLineType, utf8_to_wstr(pszCellStyle).c_str()));
#endif
}

Acad::ErrorStatus PyDbTableStyle::setGridLinetype(const PyDbObjectId& id, AcDb::GridLineType gridLineTypes, const std::string& pszCellStyle)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setGridLinetype(id.m_id, gridLineTypes, utf8_to_wstr(pszCellStyle).c_str());
#endif
}

AcGridProperty PyDbTableStyle::getGridProperty(AcDb::GridLineType nGridLineTypes, const std::string& pszCellStyle) const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    AcGridProperty prop;
    if (auto es = impObj()->getGridProperty(prop, nGridLineTypes, utf8_to_wstr(pszCellStyle).c_str()); es != eOk)
        throw PyAcadErrorStatus(es);
    return prop;
#endif
}

Acad::ErrorStatus PyDbTableStyle::setGridProperty(const AcGridProperty& gridProp, AcDb::GridLineType nGridLineTypes, const std::string& pszCellStyle)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setGridProperty(gridProp, nGridLineTypes, utf8_to_wstr(pszCellStyle).c_str());
#endif
}

PyDbObjectId PyDbTableStyle::getTemplate(void) const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return PyDbObjectId(impObj()->getTemplate());
#endif
}

Acad::ErrorStatus PyDbTableStyle::setTemplate(const PyDbObjectId& templateId, AcDb::MergeCellStyleOption nOption)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setTemplate(templateId.m_id, nOption);
#endif
}

PyDbObjectId PyDbTableStyle::removeTemplate(void)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return PyDbObjectId(impObj()->removeTemplate());
#endif
}

std::string PyDbTableStyle::className()
{
    return "AcDbTableStyle";
}

AcDbTableStyle* PyDbTableStyle::impObj() const
{
    if (m_pImp == nullptr)
        throw PyNullObject();
    return static_cast<AcDbTableStyle*>(m_pImp.get());
}
