#pragma once
#include "PyRxObject.h"

#pragma pack (push, 8)
class PyDbHandle;
class PyDbDwgFiler;
class PyDbObjectId;
class PyDbSoftOwnershipId;
class PyDbHardOwnershipId;


//-----------------------------------------------------------------------------------------
//PyDbSnoopDwgFiler
void makePyDbSnoopDwgFilerWrapper();

class PyDbSnoopDwgFiler : public AcDbDwgFiler
{
public:
    PyDbSnoopDwgFiler();
    PyDbSnoopDwgFiler(AcDb::FilerType ft);
    virtual ~PyDbSnoopDwgFiler() override = default;
    virtual  Acad::ErrorStatus  filerStatus() const override;
    virtual  AcDb::FilerType    filerType() const override;
    virtual void                setFilerStatus(Acad::ErrorStatus es) override;
    virtual void                resetFilerStatus() override;
    virtual Acad::ErrorStatus   readHardOwnershipId(AcDbHardOwnershipId* pVal) override;
    virtual Acad::ErrorStatus   writeHardOwnershipId(const AcDbHardOwnershipId& val)override;
    virtual Acad::ErrorStatus   readSoftOwnershipId(AcDbSoftOwnershipId* pVal) override;
    virtual Acad::ErrorStatus   writeSoftOwnershipId(const AcDbSoftOwnershipId& val) override;
    virtual Acad::ErrorStatus   readHardPointerId(AcDbHardPointerId* pVal) override;
    virtual Acad::ErrorStatus   writeHardPointerId(const AcDbHardPointerId& val) override;
    virtual Acad::ErrorStatus   readSoftPointerId(AcDbSoftPointerId* pVal) override;
    virtual Acad::ErrorStatus   writeSoftPointerId(const AcDbSoftPointerId& val) override;
    virtual Acad::ErrorStatus   readInt8(Adesk::Int8* pVal) override;
    virtual Acad::ErrorStatus   writeInt8(Adesk::Int8 val) override;
#if defined(_ARXTARGET) && (_ARXTARGET >= 260)
    //depreciated
#else
    virtual Acad::ErrorStatus   readString(ACHAR** pVal) override;
#endif
    virtual Acad::ErrorStatus   writeString(const ACHAR* pVal) override;
    virtual Acad::ErrorStatus   readString(AcString& val) override;
    virtual Acad::ErrorStatus   writeString(const AcString& pVal) override;
    virtual Acad::ErrorStatus   readBChunk(ads_binary* pVal) override;
    virtual Acad::ErrorStatus   writeBChunk(const ads_binary&) override;
    virtual Acad::ErrorStatus   readAcDbHandle(AcDbHandle* pVal) override;
    virtual Acad::ErrorStatus   writeAcDbHandle(const AcDbHandle& val) override;
    virtual Acad::ErrorStatus   readInt64(Adesk::Int64* pVal) override;
    virtual Acad::ErrorStatus   writeInt64(Adesk::Int64 val) override;
    virtual Acad::ErrorStatus   readInt32(Adesk::Int32* pVal) override;
    virtual Acad::ErrorStatus   writeInt32(Adesk::Int32 val) override;
    virtual Acad::ErrorStatus   readInt16(Adesk::Int16* pVal) override;
    virtual Acad::ErrorStatus   writeInt16(Adesk::Int16 val) override;
    virtual Acad::ErrorStatus   readUInt64(Adesk::UInt64* pVal) override;
    virtual Acad::ErrorStatus   writeUInt64(Adesk::UInt64 val) override;
    virtual Acad::ErrorStatus   readUInt32(Adesk::UInt32* pVal) override;
    virtual Acad::ErrorStatus   writeUInt32(Adesk::UInt32 val) override;
    virtual Acad::ErrorStatus   readUInt16(Adesk::UInt16* pVal) override;
    virtual Acad::ErrorStatus   writeUInt16(Adesk::UInt16 val) override;
    virtual Acad::ErrorStatus   readUInt8(Adesk::UInt8* pVal) override;
    virtual Acad::ErrorStatus   writeUInt8(Adesk::UInt8 val) override;
    virtual Acad::ErrorStatus   readBoolean(Adesk::Boolean* pVal) override;
    virtual Acad::ErrorStatus   writeBoolean(Adesk::Boolean val) override;
    virtual Acad::ErrorStatus   readBool(bool* pVal) override;
    virtual Acad::ErrorStatus   writeBool(bool val) override;
    virtual Acad::ErrorStatus   readDouble(double* pVal) override;
    virtual Acad::ErrorStatus   writeDouble(double val) override;
    virtual Acad::ErrorStatus   readPoint2d(AcGePoint2d* pVal) override;
    virtual Acad::ErrorStatus   writePoint2d(const AcGePoint2d& val) override;
    virtual Acad::ErrorStatus   readPoint3d(AcGePoint3d* pVal) override;
    virtual Acad::ErrorStatus   writePoint3d(const AcGePoint3d& val) override;
    virtual Acad::ErrorStatus   readVector2d(AcGeVector2d* pVal) override;
    virtual Acad::ErrorStatus   writeVector2d(const AcGeVector2d& val) override;
    virtual Acad::ErrorStatus   readVector3d(AcGeVector3d* pVal) override;
    virtual Acad::ErrorStatus   writeVector3d(const AcGeVector3d& val) override;
    virtual Acad::ErrorStatus   readScale3d(AcGeScale3d* pVal) override;
    virtual Acad::ErrorStatus   writeScale3d(const AcGeScale3d& val) override;
    virtual Acad::ErrorStatus   readBytes(void* pDest, Adesk::UIntPtr nBytes) override;
    virtual Acad::ErrorStatus   writeBytes(const void* pSrc, Adesk::UIntPtr nBytes) override;
    virtual Acad::ErrorStatus   readAddress(void** pVal) override;
    virtual Acad::ErrorStatus   writeAddress(const void* pVal) override;
    virtual Acad::ErrorStatus   seek(Adesk::Int64 nOffset, int nMethod) override;
    virtual Adesk::Int64        tell() const override;
    boost::python::list         buffer() const;
    boost::python::object       getitem(int idx);

public:
    Acad::ErrorStatus   m_stat = eOk;
    AcDb::FilerType     m_filerType = AcDb::kCopyFiler;
    boost::python::list m_list;
};

//-----------------------------------------------------------------------------------------
//PyDbSnoopDxfFiler
void makePyDbSnoopDxfFilerrWrapper();

class PyDbSnoopDxfFiler : public AcDbDxfFiler
{
public:
    PyDbSnoopDxfFiler() = default;
    inline virtual ~PyDbSnoopDxfFiler() override = default;
    virtual int                 rewindFiler() override;
    virtual Acad::ErrorStatus   filerStatus() const override;
    virtual void                resetFilerStatus() override;
    virtual AcDb::FilerType     filerType() const override;
    virtual AcDbDatabase* database() const override;
    virtual Acad::ErrorStatus   writeResBuf(const resbuf& rb) override;
    virtual Acad::ErrorStatus   writeObjectId(AcDb::DxfCode code, const AcDbObjectId& id) override;
    virtual Acad::ErrorStatus   writeInt8(AcDb::DxfCode code, Adesk::Int8 val) override;
    virtual Acad::ErrorStatus   writeString(AcDb::DxfCode code, const ACHAR* pVal) override;
    virtual Acad::ErrorStatus   writeString(AcDb::DxfCode code, const AcString& pVal) override;
    virtual Acad::ErrorStatus   writeBChunk(AcDb::DxfCode code, const ads_binary& val) override;
    virtual Acad::ErrorStatus   writeAcDbHandle(AcDb::DxfCode code, const AcDbHandle& val) override;
    virtual Acad::ErrorStatus   writeInt64(AcDb::DxfCode code, Adesk::Int64 val) override;
    virtual Acad::ErrorStatus   writeInt32(AcDb::DxfCode code, Adesk::Int32 val) override;
    virtual Acad::ErrorStatus   writeInt16(AcDb::DxfCode code, Adesk::Int16 val) override;
    virtual Acad::ErrorStatus   writeUInt64(AcDb::DxfCode code, Adesk::UInt64 val) override;
    virtual Acad::ErrorStatus   writeUInt32(AcDb::DxfCode code, Adesk::UInt32 val) override;
    virtual Acad::ErrorStatus   writeUInt16(AcDb::DxfCode code, Adesk::UInt16 val) override;
    virtual Acad::ErrorStatus   writeUInt8(AcDb::DxfCode code, Adesk::UInt8 val) override;
    virtual Acad::ErrorStatus   writeBool(AcDb::DxfCode code, bool val) override;
    virtual Acad::ErrorStatus   writeBoolean(AcDb::DxfCode code, Adesk::Boolean val) override;
    virtual Acad::ErrorStatus   writeDouble(AcDb::DxfCode code, double val, int prec = kDfltPrec) override;
    virtual Acad::ErrorStatus   writePoint2d(AcDb::DxfCode code, const AcGePoint2d& val, int prec = kDfltPrec) override;
    virtual Acad::ErrorStatus   writePoint3d(AcDb::DxfCode code, const AcGePoint3d& val, int prec = kDfltPrec) override;
    virtual Acad::ErrorStatus   writeVector2d(AcDb::DxfCode code, const AcGeVector2d& val, int prec = kDfltPrec) override;
    virtual Acad::ErrorStatus   writeVector3d(AcDb::DxfCode code, const AcGeVector3d& val, int prec = kDfltPrec) override;
    virtual Acad::ErrorStatus   writeScale3d(AcDb::DxfCode code, const AcGeScale3d& val, int prec = kDfltPrec) override;
    virtual bool                includesDefaultValues() const override;
    virtual Acad::ErrorStatus   setVAError(Acad::ErrorStatus, const ACHAR*, va_list);

public:
    boost::python::list         buffer() const;
    boost::python::object       getitem(int idx);

public:
    boost::python::list m_list;
    AcDbDatabase* mpDb = nullptr;
};

#pragma pack (pop)