#include "stdafx.h"
#include "PyDbOverrule.h"
#include "PyDbObjectId.h"
#include "PyDbDimension.h"
#include "PyDbSymbolTableRecord.h"

#ifdef PYRXDEBUG

using namespace boost::python;

PyDbDimensionStyleOverruleImpl::PyDbDimensionStyleOverruleImpl(PyDbDimensionStyleOverrule* backPtr)
    : m_backPtr(backPtr)
{
}

bool PyDbDimensionStyleOverruleImpl::isApplicable(const AcRxObject* pOverruledSubject) const
{
    if (impObj()->reg_isApplicableOverride)
    {
        PyRxObject rxo(pOverruledSubject);
        return impObj()->isApplicable(rxo);
    }
    return false;
}

AcDbObjectId PyDbDimensionStyleOverruleImpl::dimensionStyle(const AcDbDimension* pSubject)
{
    if (impObj()->reg_dimensionStyle)
    {
        PyDbDimension pydimp(const_cast<AcDbDimension*>(pSubject), false);
        PyDbObjectId id = impObj()->dimensionStyle(pydimp);
        return id.m_id;
    }
    return AcDbObjectId();
}

Acad::ErrorStatus PyDbDimensionStyleOverruleImpl::setDimensionStyle(AcDbDimension* pSubject, AcDbObjectId dimStyleId)
{
    return eOk;
}

Acad::ErrorStatus PyDbDimensionStyleOverruleImpl::getDimstyleData(const AcDbDimension* pSubject, AcDbDimStyleTableRecord*& pRecord)
{
    return eOk;
}

Acad::ErrorStatus PyDbDimensionStyleOverruleImpl::setDimstyleData(AcDbDimension* pSubject, AcDbDimStyleTableRecord* pRecord)
{
    return eOk;
}

Acad::ErrorStatus PyDbDimensionStyleOverruleImpl::setDimstyleData(AcDbDimension* pSubject, AcDbObjectId dimstyleId)
{
    return eOk;
}

PyDbDimensionStyleOverrule* PyDbDimensionStyleOverruleImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_backPtr == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return m_backPtr;
}

PyDbDimensionStyleOverrule::PyDbDimensionStyleOverrule()
    : PyRxOverrule(new PyDbDimensionStyleOverruleImpl(this), false)
{
}

PyDbDimensionStyleOverrule::PyDbDimensionStyleOverrule(PyDbDimensionStyleOverruleImpl* ptr, bool autoDelete)
    : PyRxOverrule(ptr, false)
{
}

bool PyDbDimensionStyleOverrule::isApplicable(PyRxObject& pOverruledSubject) const
{
    PyAutoLockGIL lock;
    try
    {
        if (override f = get_override("isApplicable"))
        {
            return f(pOverruledSubject);
        }
        else
        {
            reg_isApplicableOverride = false;
            return false;
        }
    }
    catch (...)
    {
        reg_isApplicableOverride = false;
    }
    return false;
}

PyDbObjectId PyDbDimensionStyleOverrule::dimensionStyle(PyDbDimension& pSubject)
{
    PyAutoLockGIL lock;
    try
    {
        if (override f = get_override("dimensionStyle"))
        {
            return f(pSubject);
        }
        else
        {
            reg_dimensionStyle = false;
            return PyDbObjectId();
        }
    }
    catch (...)
    {
        reg_dimensionStyle = false;
    }
    return PyDbObjectId();
}

void PyDbDimensionStyleOverrule::setDimensionStyle(PyDbDimension& pSubject, const PyDbObjectId& dimStyleId)
{
    PyAutoLockGIL lock;
    try
    {
        if (override f = get_override("setDimensionStyle"))
        {
           f(pSubject, dimStyleId);
        }
        else
        {
            reg_setDimensionStyle = false;
        }
    }
    catch (...)
    {
        reg_setDimensionStyle = false;
    }
}

PyDbDimStyleTableRecord PyDbDimensionStyleOverrule::getDimstyleData(const PyDbDimension& pSubject)
{
    PyAutoLockGIL lock;
    try
    {
        if (override f = get_override("getDimstyleData"))
        {
            return f(pSubject);
        }
        else
        {
            reg_getDimstyleData = false;
            return PyDbDimStyleTableRecord(pSubject.dimensionStyle());
        }
    }
    catch (...)
    {
        reg_getDimstyleData = false;
    }
    return PyDbDimStyleTableRecord(pSubject.dimensionStyle());
}

void PyDbDimensionStyleOverrule::setDimstyleData(PyDbDimension& pSubject, const PyDbDimStyleTableRecord& pRecord)
{
    PyAutoLockGIL lock;
    try
    {
        if (override f = get_override("setDimstyleData"))
        {
            f(pSubject, pRecord);
        }
        else
        {
            reg_setDimstyleData = false;
        }
    }
    catch (...)
    {
        reg_setDimstyleData = false;
    }
}

void PyDbDimensionStyleOverrule::setDimstyleDataId(PyDbDimension& pSubject, const PyDbObjectId& dimstyleId)
{
    PyAutoLockGIL lock;
    try
    {
        if (override f = get_override("setDimstyleDataId"))
        {
            f(pSubject, dimstyleId);
        }
        else
        {
            reg_setDimstyleDataId = false;
        }
    }
    catch (...)
    {
        reg_setDimstyleDataId = false;
    }
}

PyDbDimensionStyleOverruleImpl* PyDbDimensionStyleOverrule::impObj(const std::source_location& src /*= std::source_location::current()*/)
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyDbDimensionStyleOverruleImpl*>(m_pyImp.get());
}

#endif