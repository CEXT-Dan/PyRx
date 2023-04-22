#include "stdafx.h"
#include "PyDbTableStyle.h"
#include "PyDbObjectId.h"


void makeAcDbTableStyleWrapper()
{
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

Acad::ErrorStatus PyDbTableStyle::setTextStyle(const PyDbObjectId& id, AcDb::RowType rowType)
{
    return impObj()->setTextStyle(id.m_id, rowType);
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
