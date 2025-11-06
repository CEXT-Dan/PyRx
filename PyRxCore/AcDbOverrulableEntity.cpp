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
    ARXOVERRULEOBJAPP
    | Product Desc : AcDbOverrulableEntity
    | Company : CAD_PyRx
    | WEB Address : https://github.com/CEXT-Dan/PyRx
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
    //----- Save parent class information first.
    Acad::ErrorStatus es = AcDbEntity::dwgOutFields(pFiler);
    if (es != Acad::eOk)
        return (es);
    //----- Object version number needs to be saved first
    if ((es = pFiler->writeUInt32(AcDbOverrulableEntity::kCurrentVersionNumber)) != Acad::eOk)
        return (es);
    //----- Output params
    //.....

    return (pFiler->filerStatus());
}

Acad::ErrorStatus AcDbOverrulableEntity::dwgInFields(AcDbDwgFiler* pFiler)
{
    assertWriteEnabled();
    //----- Read parent class information first.
    Acad::ErrorStatus es = AcDbEntity::dwgInFields(pFiler);
    if (es != Acad::eOk)
        return (es);
    //----- Object version number needs to be read first
    Adesk::UInt32 version = 0;
    if ((es = pFiler->readUInt32(&version)) != Acad::eOk)
        return (es);
    if (version > AcDbOverrulableEntity::kCurrentVersionNumber)
        return (Acad::eMakeMeProxy);
    //- Uncomment the 2 following lines if your current object implementation cannot
    //- support previous version of that object.
    //if ( version < AcDbOverrulableEntity::kCurrentVersionNumber )
    //	return (Acad::eMakeMeProxy) ;
    //----- Read params
    //.....

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

//-----------------------------------------------------------------------------
//----- AcDbEntity protocols
Adesk::Boolean AcDbOverrulableEntity::subWorldDraw(AcGiWorldDraw* mode) 
{
    assertReadEnabled();
    return (AcDbEntity::subWorldDraw(mode));
}

Adesk::UInt32 AcDbOverrulableEntity::subSetAttributes(AcGiDrawableTraits* traits) 
{
    assertReadEnabled();
    return (AcDbEntity::subSetAttributes(traits));
}


#endif //PYRX_IN_PROGRESS_OVERULE