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
//----- AcDbOverrulableEntity.h : Declaration of the AcDbOverrulableEntity
//-----------------------------------------------------------------------------
#pragma once

#ifdef PYRX_IN_PROGRESS_OVERULE

#ifdef PYRX_MODULE
#define DLLIMPEXP __declspec(dllexport)
#else
//----- Note: we don't use __declspec(dllimport) here, because of the
//----- "local vtable" problem with msvc. If you use __declspec(dllimport),
//----- then, when a client dll does a new on the class, the object's
//----- vtable pointer points to a vtable allocated in that client
//----- dll. If the client dll then passes the object to another dll,
//----- and the client dll is then unloaded, the vtable becomes invalid
//----- and any virtual calls on the object will access invalid memory.
//-----
//----- By not using __declspec(dllimport), we guarantee that the
//----- vtable is allocated in the server dll during the ctor and the
//----- client dll does not overwrite the vtable pointer after calling
//----- the ctor. And, since we expect the server dll to remain in
//----- memory indefinitely, there is no problem with vtables unexpectedly
//----- going away.
#define DLLIMPEXP
#endif

//-----------------------------------------------------------------------------
#include "dbmain.h"

//-----------------------------------------------------------------------------
class DLLIMPEXP AcDbOverrulableEntity : public AcDbEntity
{

public:
    ACRX_DECLARE_MEMBERS(AcDbOverrulableEntity);

protected:
    static Adesk::UInt32 kCurrentVersionNumber;

public:
    AcDbOverrulableEntity();
    virtual ~AcDbOverrulableEntity() override;

    //----- AcDbObject protocols
    //- Dwg Filing protocol
    virtual Acad::ErrorStatus dwgOutFields(AcDbDwgFiler* pFiler) const override;
    virtual Acad::ErrorStatus dwgInFields(AcDbDwgFiler* pFiler) override;

    //- Dxf Filing protocol
    virtual Acad::ErrorStatus dxfOutFields(AcDbDxfFiler* pFiler) const override;
    virtual Acad::ErrorStatus dxfInFields(AcDbDxfFiler* pFiler) override;

    //- SubXXX() methods (self notification)
    virtual Acad::ErrorStatus subOpen(AcDb::OpenMode mode) override;
    virtual Acad::ErrorStatus subErase(Adesk::Boolean erasing) override;
    virtual Acad::ErrorStatus subCancel() override;
    virtual Acad::ErrorStatus subClose() override;

    //- Persistent reactor callbacks
    virtual void openedForModify(const AcDbObject* pDbObj) override;
    virtual void cancelled(const AcDbObject* pDbObj) override;
    virtual void objectClosed(const AcDbObjectId objId) override;
    virtual void goodbye(const AcDbObject* pDbObj) override;
    virtual void copied(const AcDbObject* pDbObj, const AcDbObject* pNewObj) override;
    virtual void erased(const AcDbObject* pDbObj, Adesk::Boolean bErasing = true) override;
    virtual void modified(const AcDbObject* pDbObj) override;
    virtual void modifiedGraphics(const AcDbEntity* pDbEnt) override;
    virtual void modifiedXData(const AcDbObject* pDbObj) override;
    virtual void subObjModified(const AcDbObject* pMainbObj, const AcDbObject* pSubObj) override;
    virtual void modifyUndone(const AcDbObject* pDbObj) override;
    virtual void reappended(const AcDbObject* pDbObj)override;
    virtual void unappended(const AcDbObject* pDbObj) override;

    //- members
    AcGePoint3d  position() const;
    void         setPosition(const AcGePoint3d& val);
    AcGeVector3d direction() const;
    void         setDirection(const AcGeVector3d& val);
    AcGeVector3d normal() const;
    void         setNormal(const AcGeVector3d& val);
    AcString     guid() const;
    void         setGuid(const AcString& val);
    AcString     name() const;
    void         setName(const AcString& val);
    Adesk::Int64 entType() const;
    void         setEntType(Adesk::Int64 val);
    Adesk::Int64 mask() const;
    void         setMask(Adesk::Int64 val);
    std::vector<Adesk::Int32> ints() const;
    void         setInts(const std::vector<Adesk::Int32>& vals);
    std::vector<double> doubles() const;
    void         setDoubles(const std::vector<double>& vals);
    std::vector<AcString> strings() const;
    void         setStrings(const std::vector<AcString>& vals);
    std::vector<AcGePoint3d> points() const;
    void         setPoints(const std::vector<AcGePoint3d>& vals);

    //----- AcDbEntity protocols
protected:
    virtual Adesk::Boolean      subWorldDraw(AcGiWorldDraw* mode) override;
    virtual Adesk::UInt32       subSetAttributes(AcGiDrawableTraits* traits) override;
    virtual Acad::ErrorStatus   subGetGripPoints(AcGePoint3dArray& gripPoints, AcDbIntArray& osnapModes, AcDbIntArray& geomIds) const;
    virtual Acad::ErrorStatus   subTransformBy(const AcGeMatrix3d& xform) override;

private:
    AcGePoint3d m_pos = AcGePoint3d::kOrigin;   // Transformed
    AcGeVector3d m_dir = AcGeVector3d::kXAxis;  // Transformed
    AcGeVector3d m_normal = AcGeVector3d::kZAxis;// Transformed

    AcString m_guid; // a developer key?
    AcString m_name; // anything
    AcString m_descr;// anything

    Adesk::Int64 m_type = 0; // anything
    Adesk::Int64 m_mask = 0; // anything

    std::vector<Adesk::Int32> m_ints; // data
    std::vector<double> m_reals;      // " "
    std::vector<AcString> m_strings;  // " "
    std::vector<AcGePoint3d> m_points;//Transformed
};

using AcDbOverrulableEntityPointer = AcDbObjectPointer<AcDbOverrulableEntity>;

#ifdef PYRX_MODULE
ACDB_REGISTER_OBJECT_ENTRY_AUTO(AcDbOverrulableEntity)
#endif

#endif //PYRX_IN_PROGRESS_OVERULE