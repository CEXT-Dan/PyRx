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
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    AcString name;
    if (auto es = imp->getName(name); es != eOk)
        throw PyAcadErrorStatus(es);
    return wstr_to_utf8(name);
#endif
}

Acad::ErrorStatus PyDbTableStyle::setName(const std::string& pszName)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setName(utf8_to_wstr(pszName).c_str());
}

std::string PyDbTableStyle::description(void) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return wstr_to_utf8(imp->description());
}

Acad::ErrorStatus PyDbTableStyle::setDescription(const std::string& pszDescription)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setName(utf8_to_wstr(pszDescription).c_str());
}

Adesk::UInt32 PyDbTableStyle::bitFlags() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->bitFlags();
}

Acad::ErrorStatus PyDbTableStyle::setBitFlags(Adesk::UInt32 flags)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setBitFlags(flags);
}

AcDb::FlowDirection PyDbTableStyle::flowDirection(void) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->flowDirection();
}

Acad::ErrorStatus PyDbTableStyle::setFlowDirection(AcDb::FlowDirection flow)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setFlowDirection(flow);
}

std::string PyDbTableStyle::className()
{
    return "AcDbTableStyle";
}

AcDbTableStyle* PyDbTableStyle::impObj() const
{
    return static_cast<AcDbTableStyle*>(m_pImp.get());
}
