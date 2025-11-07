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
#include "AcDbOverrulableEntity.h"

#ifdef PYRX_IN_PROGRESS_OVERULE

//-----------------------------------------------------------------------------
Adesk::UInt32 AcDbOverrulableEntity::kCurrentVersionNumber = 1;

//-----------------------------------------------------------------------------
ACRX_DXF_DEFINE_MEMBERS(
    AcDbOverrulableEntity, AcDbEntity,
    AcDb::kDHL_CURRENT, AcDb::kMReleaseCurrent,
    AcDbProxyEntity::kAllAllowedBits, ACDBOVERRULABLEENTITY,
    PYRXAPP
    | Product Desc : AcDbOverrulableEntity
    | Company : CAD_PyRx
    | WEB Address : github.com/CEXT-Dan/PyRx
)

//-----------------------------------------------------------------------------
AcDbOverrulableEntity::AcDbOverrulableEntity() : AcDbEntity()
{
}

AcDbOverrulableEntity::~AcDbOverrulableEntity()
{
}

//-----------------------------------------------------------------------------
//----- AcDbObject protocols
//- Dwg Filing protocol
Acad::ErrorStatus AcDbOverrulableEntity::dwgOutFields(AcDbDwgFiler* pFiler) const
{
    assertReadEnabled();
    Acad::ErrorStatus es = AcDbEntity::dwgOutFields(pFiler);
    if (es != Acad::eOk)
        return (es);
    if ((es = pFiler->writeUInt32(AcDbOverrulableEntity::kCurrentVersionNumber)) != Acad::eOk)
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

Acad::ErrorStatus AcDbOverrulableEntity::dwgInFields(AcDbDwgFiler* pFiler)
{
    assertWriteEnabled();
    Acad::ErrorStatus es = AcDbEntity::dwgInFields(pFiler);
    if (es != Acad::eOk)
        return (es);
    Adesk::UInt32 version = 0;
    if ((es = pFiler->readUInt32(&version)) != Acad::eOk)
        return (es);
    if (version != AcDbOverrulableEntity::kCurrentVersionNumber)
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

//- Dxf Filing protocol
Acad::ErrorStatus AcDbOverrulableEntity::dxfOutFields(AcDbDxfFiler* pFiler) const
{
    assertReadEnabled();
    //----- Save parent class information first.
    Acad::ErrorStatus es = AcDbEntity::dxfOutFields(pFiler);
    if (es != Acad::eOk)
        return (es);
    es = pFiler->writeItem(AcDb::kDxfSubclass, _RXST("AcDbOverrulableEntity"));
    if (es != Acad::eOk)
        return (es);
    //----- Object version number needs to be saved first
    if ((es = pFiler->writeUInt32(kDxfInt32, AcDbOverrulableEntity::kCurrentVersionNumber)) != Acad::eOk)
        return (es);
    //----- Output params
    //.....

    return (pFiler->filerStatus());
}

Acad::ErrorStatus AcDbOverrulableEntity::dxfInFields(AcDbDxfFiler* pFiler)
{
    assertWriteEnabled();
    //----- Read parent class information first.
    Acad::ErrorStatus es = AcDbEntity::dxfInFields(pFiler);
    if (es != Acad::eOk || !pFiler->atSubclassData(_RXST("AcDbOverrulableEntity")))
        return (pFiler->filerStatus());
    //----- Object version number needs to be read first
    struct resbuf rb;
    pFiler->readItem(&rb);
    if (rb.restype != AcDb::kDxfInt32)
    {
        pFiler->pushBackItem();
        pFiler->setError(Acad::eInvalidDxfCode, _RXST("\nError: expected group code %d (version #)"), AcDb::kDxfInt32);
        return (pFiler->filerStatus());
    }
    Adesk::UInt32 version = (Adesk::UInt32)rb.resval.rlong;
    if (version > AcDbOverrulableEntity::kCurrentVersionNumber)
        return (Acad::eMakeMeProxy);
    //- Uncomment the 2 following lines if your current object implementation cannot
    //- support previous version of that object.
    //if ( version < AcDbOverrulableEntity::kCurrentVersionNumber )
    //	return (Acad::eMakeMeProxy) ;
    //----- Read params in non order dependant manner
    while (es == Acad::eOk && (es = pFiler->readResBuf(&rb)) == Acad::eOk)
    {
        switch (rb.restype) {
            //----- Read params by looking at their DXF code (example below)
            //case AcDb::kDxfXCoord:
            //	if ( version == 1 )
            //		cen3d =asPnt3d (rb.resval.rpoint) ;
            //	else 
            //		cen2d =asPnt2d (rb.resval.rpoint) ;
            //	break ;
            //.....

            default:
                //----- An unrecognized group. Push it back so that the subclass can read it again.
                pFiler->pushBackItem();
                es = Acad::eEndOfFile;
                break;
        }
    }
    //----- At this point the es variable must contain eEndOfFile
    //----- - either from readResBuf() or from pushback. If not,
    //----- it indicates that an error happened and we should
    //----- return immediately.
    if (es != Acad::eEndOfFile)
        return (Acad::eInvalidResBuf);

    return (pFiler->filerStatus());
}

//- SubXXX() methods (self notification)
Acad::ErrorStatus AcDbOverrulableEntity::subOpen(AcDb::OpenMode mode)
{
    return (AcDbEntity::subOpen(mode));
}

Acad::ErrorStatus AcDbOverrulableEntity::subErase(Adesk::Boolean erasing)
{
    return (AcDbEntity::subErase(erasing));
}

Acad::ErrorStatus AcDbOverrulableEntity::subCancel()
{
    return (AcDbEntity::subCancel());
}

Acad::ErrorStatus AcDbOverrulableEntity::subClose()
{
    return (AcDbEntity::subClose());
}

//- Persistent reactor callbacks
void AcDbOverrulableEntity::openedForModify(const AcDbObject* pDbObj)
{
    assertReadEnabled();
    AcDbEntity::openedForModify(pDbObj);
}

void AcDbOverrulableEntity::cancelled(const AcDbObject* pDbObj)
{
    assertReadEnabled();
    AcDbEntity::cancelled(pDbObj);
}

void AcDbOverrulableEntity::objectClosed(const AcDbObjectId objId)
{
    assertReadEnabled();
    AcDbEntity::objectClosed(objId);
}

void AcDbOverrulableEntity::goodbye(const AcDbObject* pDbObj)
{
    assertReadEnabled();
    AcDbEntity::goodbye(pDbObj);
}

void AcDbOverrulableEntity::copied(const AcDbObject* pDbObj, const AcDbObject* pNewObj)
{
    assertReadEnabled();
    AcDbEntity::copied(pDbObj, pNewObj);
}

void AcDbOverrulableEntity::erased(const AcDbObject* pDbObj, Adesk::Boolean bErasing)
{
    assertReadEnabled();
    AcDbEntity::erased(pDbObj, bErasing);
}

void AcDbOverrulableEntity::modified(const AcDbObject* pDbObj)
{
    assertReadEnabled();
    AcDbEntity::modified(pDbObj);
}

void AcDbOverrulableEntity::modifiedGraphics(const AcDbEntity* pDbEnt)
{
    assertReadEnabled();
    AcDbEntity::modifiedGraphics(pDbEnt);
}

void AcDbOverrulableEntity::modifiedXData(const AcDbObject* pDbObj)
{
    assertReadEnabled();
    AcDbEntity::modifiedXData(pDbObj);
}

void AcDbOverrulableEntity::subObjModified(const AcDbObject* pMainbObj, const AcDbObject* pSubObj)
{
    assertReadEnabled();
    AcDbEntity::subObjModified(pMainbObj, pSubObj);
}

void AcDbOverrulableEntity::modifyUndone(const AcDbObject* pDbObj)
{
    assertReadEnabled();
    AcDbEntity::modifyUndone(pDbObj);
}

void AcDbOverrulableEntity::reappended(const AcDbObject* pDbObj)
{
    assertReadEnabled();
    AcDbEntity::reappended(pDbObj);
}

void AcDbOverrulableEntity::unappended(const AcDbObject* pDbObj)
{
    assertReadEnabled();
    AcDbEntity::unappended(pDbObj);
}

AcGePoint3d AcDbOverrulableEntity::position() const
{
    assertReadEnabled();
    return m_pos;
}

void AcDbOverrulableEntity::setPosition(const AcGePoint3d& val)
{
    assertWriteEnabled();
    m_pos = val;
}

AcGeVector3d AcDbOverrulableEntity::direction() const
{
    assertReadEnabled();
    return m_dir;
}

void AcDbOverrulableEntity::setDirection(const AcGeVector3d& val)
{
    assertWriteEnabled();
    m_dir = val;
}

AcGeVector3d AcDbOverrulableEntity::normal() const
{
    assertReadEnabled();
    return m_normal;
}

void AcDbOverrulableEntity::setNormal(const AcGeVector3d& val)
{
    assertWriteEnabled();
    m_normal = val;
}

AcString AcDbOverrulableEntity::guid() const
{
    assertReadEnabled();
    return m_guid;
}

void AcDbOverrulableEntity::setGuid(const AcString& val)
{
    assertWriteEnabled();
    m_guid = val;
}

AcString AcDbOverrulableEntity::name() const
{
    assertReadEnabled();
    return m_name;
}

void AcDbOverrulableEntity::setName(const AcString& val)
{
    assertWriteEnabled();
    m_name = val;
}

Adesk::Int64 AcDbOverrulableEntity::entType() const
{
    assertReadEnabled();
    return m_type;
}

void AcDbOverrulableEntity::setEntType(Adesk::Int64 val)
{
    assertWriteEnabled();
    m_type = val;
}

Adesk::Int64 AcDbOverrulableEntity::mask() const
{
    assertReadEnabled();
    return m_mask;
}

void AcDbOverrulableEntity::setMask(Adesk::Int64 val)
{
    assertWriteEnabled();
    m_mask = val;
}

std::vector<Adesk::Int32> AcDbOverrulableEntity::ints() const
{
    assertReadEnabled();
    return m_ints;
}

void AcDbOverrulableEntity::setInts(const std::vector<Adesk::Int32>& vals)
{
    assertWriteEnabled();
    m_ints = vals;
}

std::vector<double> AcDbOverrulableEntity::doubles() const
{
    assertReadEnabled();
    return m_reals;
}

void AcDbOverrulableEntity::setDoubles(const std::vector<double>& vals)
{
    assertWriteEnabled();
    m_reals = vals;
}

std::vector<AcString> AcDbOverrulableEntity::strings() const
{
    assertReadEnabled();
    return m_strings;
}

void AcDbOverrulableEntity::setStrings(const std::vector<AcString>& vals)
{
    assertWriteEnabled();
    m_strings = vals;
}

std::vector<AcGePoint3d> AcDbOverrulableEntity::points() const
{
    assertReadEnabled();
    return m_points;
}

void AcDbOverrulableEntity::setPoints(const std::vector<AcGePoint3d>& vals)
{
    assertWriteEnabled();
    m_points = vals;
}

//-----------------------------------------------------------------------------
//----- AcDbEntity protocols
Adesk::Boolean AcDbOverrulableEntity::subWorldDraw(AcGiWorldDraw* mode)
{
    assertReadEnabled();
    auto& geo = mode->geometry();
    return geo.polypoint(1, &m_pos);
}

Adesk::UInt32 AcDbOverrulableEntity::subSetAttributes(AcGiDrawableTraits* traits)
{
    assertReadEnabled();
    return (AcDbEntity::subSetAttributes(traits));
}

Acad::ErrorStatus AcDbOverrulableEntity::subGetGripPoints(AcGePoint3dArray& gripPoints, AcDbIntArray& osnapModes, AcDbIntArray& geomIds) const
{
    assertReadEnabled();
    gripPoints.append(m_pos);
    return eOk;
}

Acad::ErrorStatus AcDbOverrulableEntity::subTransformBy(const AcGeMatrix3d& xform)
{
    assertWriteEnabled();
    m_pos.transformBy(xform);
    m_dir.transformBy(xform);
    m_normal.transformBy(xform);
    for (auto& pnt : m_points)
        pnt.transformBy(xform);
    return xDataTransformBy(xform);
}

#endif //PYRX_IN_PROGRESS_OVERULE