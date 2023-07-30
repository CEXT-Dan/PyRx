#pragma once
#include "PyRxObject.h"

class PyDbHandle;
class PyDbObjectId;
class PyDbSoftOwnershipId;
class PyDbHardOwnershipId;

//-----------------------------------------------------------------------------------------
//PyDbDwgFiler
void makePyDbDwgFilerWrapper();
class PyDbDwgFiler : public PyRxObject
{
    PyDbDwgFiler(AcDbDwgFiler* ptr, bool autoDelete);
    virtual ~PyDbDwgFiler() = default;

    Acad::ErrorStatus   filerStatus() const;
    AcDb::FilerType     filerType() const;
    void                setFilerStatus(Acad::ErrorStatus es);
    void                resetFilerStatus();
    boost::python::tuple dwgVersion() const;
    AcDb::MaintenanceReleaseVersion extendedDwgMaintenanceReleaseVersion() const;
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

