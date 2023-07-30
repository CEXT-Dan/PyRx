#pragma once
#include "PyRxObject.h"

class PyDbHandle;
class PyDbDwgFiler;
class PyDbObjectId;
class PyDbSoftOwnershipId;
class PyDbHardOwnershipId;

#define ENABLE_FILER

#ifdef ENABLE_FILER

//-----------------------------------------------------------------------------------------
//PyDbDwgFilerImpl
class PyDbDwgFilerImpl : public AcDbDwgFiler
{
public:
    PyDbDwgFilerImpl(PyDbDwgFiler* backFiler);
    virtual ~PyDbDwgFilerImpl() override = default;
    virtual  Acad::ErrorStatus  filerStatus() const override;
    virtual  AcDb::FilerType    filerType() const override;
    virtual void                setFilerStatus(Acad::ErrorStatus es) override;
    virtual void                resetFilerStatus() override;
    virtual  Acad::ErrorStatus  dwgVersion(AcDb::AcDbDwgVersion& ver,  AcDb::MaintenanceReleaseVersion& maintVer) const;

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

    virtual Acad::ErrorStatus   readString(ACHAR** pVal) override;
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


public:
    inline PyDbDwgFiler* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    PyDbDwgFiler* m_backFiler = nullptr;
};

//-----------------------------------------------------------------------------------------
//PyDbDwgFiler
void makePyDbDwgFilerWrapper();
class PyDbDwgFiler : public PyRxObject
{
public:
    PyDbDwgFiler();
    virtual ~PyDbDwgFiler() = default;

    Acad::ErrorStatus   filerStatus() const;
    AcDb::FilerType     filerType() const;
    void                setFilerStatus(Acad::ErrorStatus es);
    void                resetFilerStatus();
    boost::python::tuple dwgVersion() const;
    PyDbObjectId        readHardOwnershipId();
    void                writeHardOwnershipId(const PyDbObjectId& id);
    PyDbObjectId        readSoftOwnershipId();
    void                writeSoftOwnershipId(const PyDbObjectId& id);
    PyDbObjectId        readHardPointerId();
    void                writeHardPointerId(const PyDbObjectId& id);
    PyDbObjectId        readSoftPointerId();
    void                writeSoftPointerId(const PyDbObjectId& id);
    Adesk::Int8         readInt8();
    void                writeInt8(Adesk::Int8 val);
    std::string         readString();
    void                writeString(const std::string& pVal);
    boost::python::object   readBChunk();
    void                    writeBChunk(const boost::python::object& val);
    PyDbHandle          readAcDbHandle();
    void                writeAcDbHandle(const PyDbHandle& val);
    Adesk::Int64        readInt64();
    void                writeInt64(Adesk::Int64 val);
    Adesk::Int32        readInt32();
    void                writeInt32(Adesk::Int32 val);
    Adesk::Int16        readInt16();
    void                writeInt16(Adesk::Int16 val);
    Adesk::UInt64       readUInt64();
    void                writeUInt64(Adesk::UInt64 val);
    Adesk::UInt32       readUInt32();
    void                writeUInt32(Adesk::UInt32 val);
    Adesk::UInt16       readUInt16();
    void                writeUInt16(Adesk::UInt16 val);
    Adesk::UInt8        readUInt8();
    void                writeUInt8(Adesk::UInt8 val);
    Adesk::Boolean      readBoolean();
    void                writeBoolean(Adesk::Boolean val);
    bool                readBool();
    void                writeBool(bool val);
    double              readDouble();
    void                writeDouble(double val);
    AcGePoint2d         readPoint2d();
    void                writePoint2d(const AcGePoint2d& val);
    AcGePoint3d         readPoint3d();
    void                writePoint3d(const AcGePoint3d& val);
    AcGeVector2d        readVector2d();
    void                writeVector2d(const AcGeVector2d& val);
    AcGeVector3d        readVector3d();
    void                writeVector3d(const AcGeVector3d& val);
    AcGeScale3d         readScale3d();
    void                writeScale3d(const AcGeScale3d& val);
    boost::python::object   readBytes();
    void                    writeBytes(const boost::python::object& val);
    INT_PTR             readAddress();
    void                writeAddress(INT_PTR val);
    void                seek(Adesk::Int64 nOffset, int nMethod);
    Adesk::Int64        tell() const;
    static PyRxClass    desc();
    static std::string  className();
public:
    inline AcDbDwgFiler* impObj(const std::source_location& src = std::source_location::current()) const;
};


#endif// ENABLE_FILER