// (C) Copyright 2002-2007 by Autodesk, Inc. 
//
// Permission to use, copy, modify, and distribute this software in
// object code form for any purpose and without fee is hereby granted, 
// provided that the above copyright notice appears in all copies and 
// that both that copyright notice and the limited warranty and
// restricted rights notice below appear in all supporting 
// documentation.
//
// AUTODESK PROVIDES THIS PROGRAM "AS IS" AND WITH ALL FAULTS. 
// AUTODESK SPECIFICALLY DISCLAIMS ANY IMPLIED WARRANTY OF
// MERCHANTABILITY OR FITNESS FOR A PARTICULAR USE.  AUTODESK, INC. 
// DOES NOT WARRANT THAT THE OPERATION OF THE PROGRAM WILL BE
// UNINTERRUPTED OR ERROR FREE.
//
// Use, duplication, or disclosure by the U.S. Government is subject to 
// restrictions set forth in FAR 52.227-19 (Commercial Computer
// Software - Restricted Rights) and DFAR 252.227-7013(c)(1)(ii)
// (Rights in Technical Data and Computer Software), as applicable.
//

//-----------------------------------------------------------------------------
//----- AcDbOverrulableEntity.cpp : Implementation of AcDbOverrulableEntity
//-----------------------------------------------------------------------------
#include "StdAfx.h"
#include "PyRxOverrulableEntity.h"

#ifdef PYRXDEBUG
//-----------------------------------------------------------------------------
// TestOverrule
bool TestOverrule::isApplicable(const AcRxObject*) const
{
    return true;
}

Adesk::Boolean TestOverrule::worldDraw(AcGiDrawable* pSubject, AcGiWorldDraw* wd)
{
    PyRxOverrulableEntity* ptr = static_cast<PyRxOverrulableEntity*>(pSubject);
    auto& geo = wd->geometry();
    for (const auto& pnt : ptr->points())
        geo.circle(pnt, 0.5, ptr->normal());
    return true;
}

TestOverrule& TestOverrule::instance()
{
    static TestOverrule m_this{};
    return m_this;
}

Acad::ErrorStatus TestOverrule::start()
{
    return TestOverrule::addOverrule(PyRxOverrulableEntity::desc(), &TestOverrule::instance());
}

Acad::ErrorStatus TestOverrule::stop()
{
    return TestOverrule::removeOverrule(PyRxOverrulableEntity::desc(), &TestOverrule::instance());
}

#endif

//-----------------------------------------------------------------------------
// AcDbOverrulableEntity
//-----------------------------------------------------------------------------
Adesk::UInt32 PyRxOverrulableEntity::kCurrentVersionNumber = 1;

//-----------------------------------------------------------------------------
ACRX_DXF_DEFINE_MEMBERS(
    PyRxOverrulableEntity, AcDbEntity,
    AcDb::kDHL_CURRENT, AcDb::kMReleaseCurrent,
    AcDbProxyEntity::kAllAllowedBits, PYRXOVERRULABLEENTITY,
    PYRXAPP
    | Product Desc : PyRxOverrulableEntity
    | Company : CAD_PyRx
    | WEB Address : github.com / CEXT - Dan / PyRx
)

//-----------------------------------------------------------------------------
PyRxOverrulableEntity::PyRxOverrulableEntity() : AcDbEntity()
{
}

PyRxOverrulableEntity::~PyRxOverrulableEntity()
{
}

//-----------------------------------------------------------------------------
//----- AcDbObject protocols
//- Dwg Filing protocol
Acad::ErrorStatus PyRxOverrulableEntity::dwgOutFields(AcDbDwgFiler* pFiler) const
{
    assertReadEnabled();
    Acad::ErrorStatus es = AcDbEntity::dwgOutFields(pFiler);
    if (es != Acad::eOk)
        return (es);
    if ((es = pFiler->writeUInt32(PyRxOverrulableEntity::kCurrentVersionNumber)) != Acad::eOk)
        return (es);
    if (auto es = pFiler->writePoint3d(m_pos); es != eOk)
        return es;
    if (auto es = pFiler->writeVector3d(m_dir); es != eOk)
        return es;
    if (auto es = pFiler->writeVector3d(m_normal); es != eOk)
        return es;
    if (auto es = pFiler->writeString(m_guid); es != eOk)
        return es;
    if (auto es = pFiler->writeString(m_name); es != eOk)
        return es;
    if (auto es = pFiler->writeString(m_descr); es != eOk)
        return es;
    if (auto es = pFiler->writeInt64(m_type); es != eOk)
        return es;
    if (auto es = pFiler->writeInt64(m_mask); es != eOk)
        return es;
    if (auto es = pFiler->writeInt64(m_index); es != eOk)
        return es;
    { //m_flags
        if (auto es = pFiler->writeInt64(m_flags.size()); es != eOk)
            return es;
        for (auto v : m_flags)
        {
            if (auto es = pFiler->writeInt32(v); es != eOk)
                return es;
        }
    }
    { //m_ints
        if (auto es = pFiler->writeInt64(m_ints.size()); es != eOk)
            return es;
        for (auto v : m_ints)
        {
            if (auto es = pFiler->writeInt32(v); es != eOk)
                return es;
        }
    }
    { //m_reals
        if (auto es = pFiler->writeInt64(m_reals.size()); es != eOk)
            return es;
        for (auto v : m_reals)
        {
            if (auto es = pFiler->writeDouble(v); es != eOk)
                return es;
        }
    }
    { //m_strings
        if (auto es = pFiler->writeInt64(m_strings.size()); es != eOk)
            return es;
        for (const auto& v : m_strings)
        {
            if (auto es = pFiler->writeString(v); es != eOk)
                return es;
        }
    }
    { //m_points
        if (auto es = pFiler->writeInt64(m_points.size()); es != eOk)
            return es;
        for (const auto& v : m_points)
        {
            if (auto es = pFiler->writePoint3d(v); es != eOk)
                return es;
        }
    }
    return (pFiler->filerStatus());
}

Acad::ErrorStatus PyRxOverrulableEntity::dwgInFields(AcDbDwgFiler* pFiler)
{
    assertWriteEnabled();
    Acad::ErrorStatus es = AcDbEntity::dwgInFields(pFiler);
    if (es != Acad::eOk)
        return (es);
    
    if ((es = pFiler->readUInt32(&m_version)) != Acad::eOk)
        return (es);
    if (m_version != PyRxOverrulableEntity::kCurrentVersionNumber)
        return (Acad::eMakeMeProxy);
    if (auto es = pFiler->readPoint3d(&m_pos); es != eOk)
        return es;
    if (auto es = pFiler->readVector3d(&m_dir); es != eOk)
        return es;
    if (auto es = pFiler->readVector3d(&m_normal); es != eOk)
        return es;
    if (auto es = pFiler->readString(m_guid); es != eOk)
        return es;
    if (auto es = pFiler->readString(m_name); es != eOk)
        return es;
    if (auto es = pFiler->readString(m_descr); es != eOk)
        return es;
    if (auto es = pFiler->readInt64(&m_type); es != eOk)
        return es;
    if (auto es = pFiler->readInt64(&m_mask); es != eOk)
        return es;
    if (auto es = pFiler->readInt64(&m_index); es != eOk)
        return es;
    {// m_flags
        Adesk::UInt64 nflags = 0;
        if (es = pFiler->readUInt64(&nflags); es != eOk)
            return es;
        m_flags.clear();
        m_flags.reserve(nflags);
        for (Adesk::Int64 idx = 0; idx < nflags; idx++)
        {
            Adesk::Int32 v = 0;
            if (es = pFiler->readInt32(&v); es != eOk)
                return es;
            else
                m_flags.emplace_back(v);
        }
    }
    {// m_ints
        Adesk::UInt64 nints = 0;
        if (es = pFiler->readUInt64(&nints); es != eOk)
            return es;
        m_ints.clear();
        m_ints.reserve(nints);
        for (Adesk::Int64 idx = 0; idx < nints; idx++)
        {
            Adesk::Int32 v = 0;
            if (es = pFiler->readInt32(&v); es != eOk)
                return es;
            else
                m_ints.emplace_back(v);
        }
    }
    {// m_reals
        Adesk::UInt64 nreals = 0;
        if (es = pFiler->readUInt64(&nreals); es != eOk)
            return es;
        m_reals.clear();
        m_reals.reserve(nreals);
        for (Adesk::Int64 idx = 0; idx < nreals; idx++)
        {
            double v = 0;
            if (es = pFiler->readDouble(&v); es != eOk)
                return es;
            else
                m_reals.emplace_back(v);
        }
    }
    {// m_strings
        Adesk::UInt64 nstrings = 0;
        if (es = pFiler->readUInt64(&nstrings); es != eOk)
            return es;
        m_strings.clear();
        m_strings.reserve(nstrings);
        for (Adesk::Int64 idx = 0; idx < nstrings; idx++)
        {
            AcString v;
            if (es = pFiler->readString(v); es != eOk)
                return es;
            else
                m_strings.emplace_back(v);
        }
    }
    {// m_points
        Adesk::UInt64 npoints = 0;
        if (es = pFiler->readUInt64(&npoints); es != eOk)
            return es;
        m_points.clear();
        m_points.reserve(npoints);
        for (Adesk::Int64 idx = 0; idx < npoints; idx++)
        {
            AcGePoint3d v;
            if (es = pFiler->readPoint3d(&v); es != eOk)
                return es;
            else
                m_points.emplace_back(v);
        }
    }
    return (pFiler->filerStatus());
}

//- SubXXX() methods (self notification)
Acad::ErrorStatus PyRxOverrulableEntity::subOpen(AcDb::OpenMode mode)
{
    return (AcDbEntity::subOpen(mode));
}

Acad::ErrorStatus PyRxOverrulableEntity::subErase(Adesk::Boolean erasing)
{
    return (AcDbEntity::subErase(erasing));
}

Acad::ErrorStatus PyRxOverrulableEntity::subCancel()
{
    return (AcDbEntity::subCancel());
}

Acad::ErrorStatus PyRxOverrulableEntity::subClose()
{
    return (AcDbEntity::subClose());
}

//- Persistent reactor callbacks
void PyRxOverrulableEntity::openedForModify(const AcDbObject* pDbObj)
{
    assertReadEnabled();
    AcDbEntity::openedForModify(pDbObj);
}

void PyRxOverrulableEntity::cancelled(const AcDbObject* pDbObj)
{
    assertReadEnabled();
    AcDbEntity::cancelled(pDbObj);
}

void PyRxOverrulableEntity::objectClosed(const AcDbObjectId objId)
{
    assertReadEnabled();
    AcDbEntity::objectClosed(objId);
}

void PyRxOverrulableEntity::goodbye(const AcDbObject* pDbObj)
{
    assertReadEnabled();
    AcDbEntity::goodbye(pDbObj);
}

void PyRxOverrulableEntity::copied(const AcDbObject* pDbObj, const AcDbObject* pNewObj)
{
    assertReadEnabled();
    AcDbEntity::copied(pDbObj, pNewObj);
}

void PyRxOverrulableEntity::erased(const AcDbObject* pDbObj, Adesk::Boolean bErasing)
{
    assertReadEnabled();
    AcDbEntity::erased(pDbObj, bErasing);
}

void PyRxOverrulableEntity::modified(const AcDbObject* pDbObj)
{
    assertReadEnabled();
    AcDbEntity::modified(pDbObj);
}

void PyRxOverrulableEntity::modifiedGraphics(const AcDbEntity* pDbEnt)
{
    assertReadEnabled();
    AcDbEntity::modifiedGraphics(pDbEnt);
}

void PyRxOverrulableEntity::modifiedXData(const AcDbObject* pDbObj)
{
    assertReadEnabled();
    AcDbEntity::modifiedXData(pDbObj);
}

void PyRxOverrulableEntity::subObjModified(const AcDbObject* pMainbObj, const AcDbObject* pSubObj)
{
    assertReadEnabled();
    AcDbEntity::subObjModified(pMainbObj, pSubObj);
}

void PyRxOverrulableEntity::modifyUndone(const AcDbObject* pDbObj)
{
    assertReadEnabled();
    AcDbEntity::modifyUndone(pDbObj);
}

void PyRxOverrulableEntity::reappended(const AcDbObject* pDbObj)
{
    assertReadEnabled();
    AcDbEntity::reappended(pDbObj);
}

void PyRxOverrulableEntity::unappended(const AcDbObject* pDbObj)
{
    assertReadEnabled();
    AcDbEntity::unappended(pDbObj);
}

AcGePoint3d PyRxOverrulableEntity::position() const
{
    assertReadEnabled();
    return m_pos;
}

void PyRxOverrulableEntity::setPosition(const AcGePoint3d& val)
{
    assertWriteEnabled();
    m_pos = val;
}

AcGeVector3d PyRxOverrulableEntity::direction() const
{
    assertReadEnabled();
    return m_dir;
}

void PyRxOverrulableEntity::setDirection(const AcGeVector3d& val)
{
    assertWriteEnabled();
    m_dir = val;
}

AcGeVector3d PyRxOverrulableEntity::normal() const
{
    assertReadEnabled();
    return m_normal;
}

void PyRxOverrulableEntity::setNormal(const AcGeVector3d& val)
{
    assertWriteEnabled();
    m_normal = val;
}

AcString PyRxOverrulableEntity::guid() const
{
    assertReadEnabled();
    return m_guid;
}

void PyRxOverrulableEntity::setGuid(const AcString& val)
{
    assertWriteEnabled();
    m_guid = val;
}

AcString PyRxOverrulableEntity::name() const
{
    assertReadEnabled();
    return m_name;
}

void PyRxOverrulableEntity::setName(const AcString& val)
{
    assertWriteEnabled();
    m_name = val;
}

AcString PyRxOverrulableEntity::description() const
{
    assertReadEnabled();
    return m_descr;
}

void PyRxOverrulableEntity::setdescription(const AcString& val)
{
    assertWriteEnabled();
    m_descr = val;
}

Adesk::Int64 PyRxOverrulableEntity::typing() const
{
    assertReadEnabled();
    return m_type;
}

void PyRxOverrulableEntity::setTyping(Adesk::Int64 val)
{
    assertWriteEnabled();
    m_type = val;
}

Adesk::Int64 PyRxOverrulableEntity::mask() const
{
    assertReadEnabled();
    return m_mask;
}

void PyRxOverrulableEntity::setMask(Adesk::Int64 val)
{
    assertWriteEnabled();
    m_mask = val;
}

Adesk::Int64 PyRxOverrulableEntity::index() const
{
    assertReadEnabled();
    return m_index;
}

void PyRxOverrulableEntity::setIndex(Adesk::Int64 val)
{
    assertWriteEnabled();
    m_index = val;
}

Adesk::UInt32 PyRxOverrulableEntity::version() const
{
    assertReadEnabled();
    return m_version;
}

std::vector<Adesk::Int32> PyRxOverrulableEntity::flags() const
{
    assertReadEnabled();
    return m_flags;
}

void PyRxOverrulableEntity::setFlags(const std::vector<Adesk::Int32>& vals)
{
    assertWriteEnabled();
    m_flags = vals;
}

std::vector<Adesk::Int32> PyRxOverrulableEntity::ints() const
{
    assertReadEnabled();
    return m_ints;
}

void PyRxOverrulableEntity::setInts(const std::vector<Adesk::Int32>& vals)
{
    assertWriteEnabled();
    m_ints = vals;
}

std::vector<double> PyRxOverrulableEntity::doubles() const
{
    assertReadEnabled();
    return m_reals;
}

void PyRxOverrulableEntity::setDoubles(const std::vector<double>& vals)
{
    assertWriteEnabled();
    m_reals = vals;
}

std::vector<AcString> PyRxOverrulableEntity::strings() const
{
    assertReadEnabled();
    return m_strings;
}

void PyRxOverrulableEntity::setStrings(const std::vector<AcString>& vals)
{
    assertWriteEnabled();
    m_strings = vals;
}

std::vector<AcGePoint3d> PyRxOverrulableEntity::points() const
{
    assertReadEnabled();
    return m_points;
}

void PyRxOverrulableEntity::setPoints(const std::vector<AcGePoint3d>& vals)
{
    assertWriteEnabled();
    m_points = vals;
}

//-----------------------------------------------------------------------------
//----- AcDbEntity protocols
Adesk::Boolean PyRxOverrulableEntity::subWorldDraw(AcGiWorldDraw* mode)
{
    assertReadEnabled();
    auto& geo = mode->geometry();
    return geo.polypoint(1, &m_pos);
}

Adesk::UInt32 PyRxOverrulableEntity::subSetAttributes(AcGiDrawableTraits* traits)
{
    assertReadEnabled();
    return (AcDbEntity::subSetAttributes(traits));
}

Acad::ErrorStatus PyRxOverrulableEntity::subGetGripPoints(AcGePoint3dArray& gripPoints, AcDbIntArray& osnapModes, AcDbIntArray& geomIds) const
{
    assertReadEnabled();
    gripPoints.append(m_pos);
    return eOk;
}

Acad::ErrorStatus PyRxOverrulableEntity::subTransformBy(const AcGeMatrix3d& xform)
{
    assertWriteEnabled();
    m_pos.transformBy(xform);
    m_dir.transformBy(xform);
    m_normal.transformBy(xform);
    for (auto& pnt : m_points)
        pnt.transformBy(xform);
    return xDataTransformBy(xform);
}
