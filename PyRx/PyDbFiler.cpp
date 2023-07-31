#include "stdafx.h"
#include "PyDbFiler.h"
#include "PyDbObjectId.h"

using namespace boost::python;
//-----------------------------------------------------------------------------------------
//PyDbDwgFilerImpl
void makePyDbSnoopDwgFilerWrapper()
{
    PyDocString DS("SnoopDwgFiler");
    class_<PyDbSnoopDwgFiler>("SnoopDwgFiler")
        .def(init<>())
        .def(init<AcDb::FilerType>(DS.ARGS({ "filerType: PyDb.FilerType" })))
        .def("buffer", &PyDbSnoopDwgFiler::buffer, DS.ARGS())
        ;
}

PyDbSnoopDwgFiler::PyDbSnoopDwgFiler()
{
}

PyDbSnoopDwgFiler::PyDbSnoopDwgFiler(AcDb::FilerType ft)
    :m_filerType(ft)
{
}

Acad::ErrorStatus PyDbSnoopDwgFiler::filerStatus() const
{
    return m_stat;
}

AcDb::FilerType PyDbSnoopDwgFiler::filerType() const
{
    return m_filerType;
}

void PyDbSnoopDwgFiler::setFilerStatus(Acad::ErrorStatus es)
{
    m_stat = es;
}

void PyDbSnoopDwgFiler::resetFilerStatus()
{
    m_stat = eOk;
}

Acad::ErrorStatus PyDbSnoopDwgFiler::readHardOwnershipId(AcDbHardOwnershipId* pVal)
{
    return eOk;
}

Acad::ErrorStatus PyDbSnoopDwgFiler::writeHardOwnershipId(const AcDbHardOwnershipId& val)
{
    PyAutoLockGIL m_lock;
    m_list.append(boost::python::make_tuple("AcDbHardOwnershipId", PyDbObjectId(val)));
    return eOk;
}

Acad::ErrorStatus PyDbSnoopDwgFiler::readSoftOwnershipId(AcDbSoftOwnershipId* pVal)
{
    return eOk;
}

Acad::ErrorStatus PyDbSnoopDwgFiler::writeSoftOwnershipId(const AcDbSoftOwnershipId& val)
{
    PyAutoLockGIL m_lock;
    m_list.append(boost::python::make_tuple("AcDbSoftOwnershipId", PyDbObjectId(val)));
    return eOk;
}

Acad::ErrorStatus PyDbSnoopDwgFiler::readHardPointerId(AcDbHardPointerId* pVal)
{
    return eOk;
}

Acad::ErrorStatus PyDbSnoopDwgFiler::writeHardPointerId(const AcDbHardPointerId& val)
{
    PyAutoLockGIL m_lock;
    m_list.append(boost::python::make_tuple("AcDbHardPointerId", PyDbObjectId(val)));
    return eOk;
}

Acad::ErrorStatus PyDbSnoopDwgFiler::readSoftPointerId(AcDbSoftPointerId* pVal)
{
    return eOk;
}

Acad::ErrorStatus PyDbSnoopDwgFiler::writeSoftPointerId(const AcDbSoftPointerId& val)
{
    PyAutoLockGIL m_lock;
    m_list.append(boost::python::make_tuple("AcDbSoftPointerId", PyDbObjectId(val)));
    return eOk;
}

Acad::ErrorStatus PyDbSnoopDwgFiler::readInt8(Adesk::Int8* pVal)
{
    return eOk;
}

Acad::ErrorStatus PyDbSnoopDwgFiler::writeInt8(Adesk::Int8 val)
{
    PyAutoLockGIL m_lock;
    m_list.append(boost::python::make_tuple("Adesk::Int8", val));
    return eOk;
}

Acad::ErrorStatus PyDbSnoopDwgFiler::readString(ACHAR** pVal)
{
    return eOk;
}

Acad::ErrorStatus PyDbSnoopDwgFiler::readString(AcString& val)
{
    return eOk;
}

Acad::ErrorStatus PyDbSnoopDwgFiler::writeString(const ACHAR* pVal)
{
    PyAutoLockGIL m_lock;
    m_list.append(boost::python::make_tuple("ACHAR*", wstr_to_utf8(pVal)));
    return eOk;
}

Acad::ErrorStatus PyDbSnoopDwgFiler::writeString(const AcString& pVal)
{
    PyAutoLockGIL m_lock;
    m_list.append(boost::python::make_tuple("AcString", wstr_to_utf8(pVal)));
    return eOk;
}

Acad::ErrorStatus PyDbSnoopDwgFiler::readBChunk(ads_binary* pVal)
{
    return eOk;
}

Acad::ErrorStatus PyDbSnoopDwgFiler::writeBChunk(const ads_binary& adsval)
{
    PyAutoLockGIL lock;
    PyObject* py_buf = PyMemoryView_FromMemory(adsval.buf, (size_t)adsval.clen, PyBUF_WRITE);
    m_list.append(boost::python::make_tuple("ads_binary", boost::python::object(boost::python::handle<>(py_buf))));
    return eOk;
}

Acad::ErrorStatus PyDbSnoopDwgFiler::readAcDbHandle(AcDbHandle* pVal)
{
    return eOk;
}

Acad::ErrorStatus PyDbSnoopDwgFiler::writeAcDbHandle(const AcDbHandle& val)
{
    PyAutoLockGIL m_lock;
    m_list.append(boost::python::make_tuple("AcDbHandle", PyDbHandle(val)));
    return eOk;
}

Acad::ErrorStatus PyDbSnoopDwgFiler::readInt64(Adesk::Int64* pVal)
{
    return eOk;
}

Acad::ErrorStatus PyDbSnoopDwgFiler::writeInt64(Adesk::Int64 val)
{
    PyAutoLockGIL m_lock;
    m_list.append(boost::python::make_tuple("Adesk::Int64", val));
    return eOk;
}

Acad::ErrorStatus PyDbSnoopDwgFiler::readInt32(Adesk::Int32* pVal)
{
    return eOk;
}

Acad::ErrorStatus PyDbSnoopDwgFiler::writeInt32(Adesk::Int32 val)
{
    PyAutoLockGIL m_lock;
    m_list.append(boost::python::make_tuple("Adesk::Int32", val));
    return eOk;
}

Acad::ErrorStatus PyDbSnoopDwgFiler::readInt16(Adesk::Int16* pVal)
{
    return eOk;
}

Acad::ErrorStatus PyDbSnoopDwgFiler::writeInt16(Adesk::Int16 val)
{
    PyAutoLockGIL m_lock;
    m_list.append(boost::python::make_tuple("Adesk::Int16", val));
    return eOk;
}

Acad::ErrorStatus PyDbSnoopDwgFiler::readUInt64(Adesk::UInt64* pVal)
{
    return eOk;
}

Acad::ErrorStatus PyDbSnoopDwgFiler::writeUInt64(Adesk::UInt64 val)
{
    PyAutoLockGIL m_lock;
    m_list.append(boost::python::make_tuple("Adesk::UInt64", val));
    return eOk;
}

Acad::ErrorStatus PyDbSnoopDwgFiler::readUInt32(Adesk::UInt32* pVal)
{
    return eOk;
}

Acad::ErrorStatus PyDbSnoopDwgFiler::writeUInt32(Adesk::UInt32 val)
{
    PyAutoLockGIL m_lock;
    m_list.append(boost::python::make_tuple("Adesk::UInt32", val));
    return eOk;
}

Acad::ErrorStatus PyDbSnoopDwgFiler::readUInt16(Adesk::UInt16* pVal)
{
    return eOk;
}

Acad::ErrorStatus PyDbSnoopDwgFiler::writeUInt16(Adesk::UInt16 val)
{
    PyAutoLockGIL m_lock;
    m_list.append(boost::python::make_tuple("Adesk::UInt16", val));
    return eOk;
}

Acad::ErrorStatus PyDbSnoopDwgFiler::readUInt8(Adesk::UInt8* pVal)
{
    return eOk;
}

Acad::ErrorStatus PyDbSnoopDwgFiler::writeUInt8(Adesk::UInt8 val)
{
    PyAutoLockGIL m_lock;
    m_list.append(boost::python::make_tuple("Adesk::UInt8", val));
    return eOk;
}

Acad::ErrorStatus PyDbSnoopDwgFiler::readBoolean(Adesk::Boolean* pVal)
{
    return eOk;
}

Acad::ErrorStatus PyDbSnoopDwgFiler::writeBoolean(Adesk::Boolean val)
{
    PyAutoLockGIL m_lock;
    m_list.append(boost::python::make_tuple("Adesk::Boolean", val));
    return eOk;
}

Acad::ErrorStatus PyDbSnoopDwgFiler::readBool(bool* pVal)
{
    return eOk;
}

Acad::ErrorStatus PyDbSnoopDwgFiler::writeBool(bool val)
{
    PyAutoLockGIL m_lock;
    m_list.append(boost::python::make_tuple("bool", val));
    return eOk;
}

Acad::ErrorStatus PyDbSnoopDwgFiler::readDouble(double* pVal)
{
    return eOk;
}

Acad::ErrorStatus PyDbSnoopDwgFiler::writeDouble(double val)
{
    PyAutoLockGIL m_lock;
    m_list.append(boost::python::make_tuple("double", val));
    return eOk;
}

Acad::ErrorStatus PyDbSnoopDwgFiler::readPoint2d(AcGePoint2d* pVal)
{
    return eOk;
}

Acad::ErrorStatus PyDbSnoopDwgFiler::writePoint2d(const AcGePoint2d& val)
{
    PyAutoLockGIL m_lock;
    m_list.append(boost::python::make_tuple("AcGePoint2d", val));
    return eOk;
}

Acad::ErrorStatus PyDbSnoopDwgFiler::readPoint3d(AcGePoint3d* pVal)
{
    return eOk;
}

Acad::ErrorStatus PyDbSnoopDwgFiler::writePoint3d(const AcGePoint3d& val)
{
    PyAutoLockGIL m_lock;
    m_list.append(boost::python::make_tuple("AcGePoint3d", val));
    return eOk;
}

Acad::ErrorStatus PyDbSnoopDwgFiler::readVector2d(AcGeVector2d* pVal)
{
    return eOk;
}

Acad::ErrorStatus PyDbSnoopDwgFiler::writeVector2d(const AcGeVector2d& val)
{
    PyAutoLockGIL m_lock;
    m_list.append(boost::python::make_tuple("AcGeVector2d", val));
    return eOk;
}

Acad::ErrorStatus PyDbSnoopDwgFiler::readVector3d(AcGeVector3d* pVal)
{
    return eOk;
}

Acad::ErrorStatus PyDbSnoopDwgFiler::writeVector3d(const AcGeVector3d& val)
{
    PyAutoLockGIL m_lock;
    m_list.append(boost::python::make_tuple("AcGeVector3d", val));
    return eOk;
}

Acad::ErrorStatus PyDbSnoopDwgFiler::readScale3d(AcGeScale3d* pVal)
{
    return eOk;
}

Acad::ErrorStatus PyDbSnoopDwgFiler::writeScale3d(const AcGeScale3d& val)
{
    PyAutoLockGIL m_lock;
    m_list.append(boost::python::make_tuple("AcGeScale3d", val));
    return eOk;
}

Acad::ErrorStatus PyDbSnoopDwgFiler::readBytes(void* pDest, Adesk::UIntPtr nBytes)
{
    return eOk;
}

Acad::ErrorStatus PyDbSnoopDwgFiler::writeBytes(const void* pSrc, Adesk::UIntPtr nBytes)
{
    PyAutoLockGIL lock;
    PyObject* py_buf = PyMemoryView_FromMemory((char*)pSrc, (size_t)nBytes, PyBUF_WRITE);
    m_list.append(boost::python::make_tuple("ByteArray", boost::python::object(boost::python::handle<>(py_buf))));
    return eOk;
}

Acad::ErrorStatus PyDbSnoopDwgFiler::readAddress(void** pVal)
{
    return eOk;
}

Acad::ErrorStatus PyDbSnoopDwgFiler::writeAddress(const void* pVal)
{
    PyAutoLockGIL m_lock;
    m_list.append(boost::python::make_tuple("AcGeScale3d", INT_PTR(pVal)));
    return eOk;
}

Acad::ErrorStatus PyDbSnoopDwgFiler::seek(Adesk::Int64 nOffset, int nMethod)
{
    return eOk;
}

Adesk::Int64 PyDbSnoopDwgFiler::tell() const
{
    return 0L;
}

boost::python::list PyDbSnoopDwgFiler::buffer() const
{
    return m_list;
}

#ifdef ENABLE_FILER
//-----------------------------------------------------------------------------------------
//PyDbDwgFilerImpl
PyDbDwgFilerImpl::PyDbDwgFilerImpl(PyDbDwgFiler* backFiler)
    : m_backFiler(backFiler)
{

}

Acad::ErrorStatus PyDbDwgFilerImpl::filerStatus() const
{
    return impObj()->filerStatus();
}

AcDb::FilerType PyDbDwgFilerImpl::filerType() const
{
    return impObj()->filerType();
}

void PyDbDwgFilerImpl::setFilerStatus(Acad::ErrorStatus es)
{
    return impObj()->setFilerStatus(es);
}

void PyDbDwgFilerImpl::resetFilerStatus()
{
    return impObj()->resetFilerStatus();
}

Acad::ErrorStatus PyDbDwgFilerImpl::dwgVersion(AcDb::AcDbDwgVersion& ver, AcDb::MaintenanceReleaseVersion& maintVer) const
{
    PyAutoLockGIL lock;
    const boost::python::tuple tp = impObj()->dwgVersion();
    if (boost::python::len(tp) != 2)
        throw PyAcadErrorStatus(Acad::eInvalidInput);
    int intVer = boost::python::extract<int>(tp[0]);
    ver = static_cast<AcDb::AcDbDwgVersion>(intVer);
    int intMaintVer = boost::python::extract<int>(tp[1]);
    maintVer = static_cast<AcDb::MaintenanceReleaseVersion>(intMaintVer);
    return eOk;
}

Acad::ErrorStatus PyDbDwgFilerImpl::readHardOwnershipId(AcDbHardOwnershipId* pVal)
{
    if (pVal == nullptr)
        return eNullPtr;
    PyDbObjectId id = impObj()->readHardOwnershipId();
    *pVal = id.m_id;
    return Acad::eOk;
}

Acad::ErrorStatus PyDbDwgFilerImpl::writeHardOwnershipId(const AcDbHardOwnershipId& val)
{
    PyDbObjectId id(val);
    try
    {
        impObj()->writeHardOwnershipId(id);
    }
    catch (...)
    {
        return Acad::eInvalidInput;
    }
    return Acad::eOk;
}

Acad::ErrorStatus PyDbDwgFilerImpl::readSoftOwnershipId(AcDbSoftOwnershipId* pVal)
{
    if (pVal == nullptr)
        return eNullPtr;
    PyDbObjectId id = impObj()->readSoftOwnershipId();
    *pVal = id.m_id;
    return Acad::eOk;
}

Acad::ErrorStatus PyDbDwgFilerImpl::writeSoftOwnershipId(const AcDbSoftOwnershipId& val)
{
    PyDbObjectId id(val);
    try
    {
        impObj()->writeSoftOwnershipId(id);
    }
    catch (...)
    {
        return Acad::eInvalidInput;
    }
    return Acad::eOk;
}

Acad::ErrorStatus PyDbDwgFilerImpl::readHardPointerId(AcDbHardPointerId* pVal)
{
    if (pVal == nullptr)
        return eNullPtr;
    PyDbObjectId id = impObj()->readHardPointerId();
    *pVal = id.m_id;
    return Acad::eOk;
}

Acad::ErrorStatus PyDbDwgFilerImpl::writeHardPointerId(const AcDbHardPointerId& val)
{
    PyDbObjectId id(val);
    try
    {
        impObj()->writeHardPointerId(id);
    }
    catch (...)
    {
        return Acad::eInvalidInput;
    }
    return Acad::eOk;
}

Acad::ErrorStatus PyDbDwgFilerImpl::readSoftPointerId(AcDbSoftPointerId* pVal)
{
    if (pVal == nullptr)
        return eNullPtr;
    PyDbObjectId id = impObj()->readSoftPointerId();
    *pVal = id.m_id;
    return Acad::eOk;
}

Acad::ErrorStatus PyDbDwgFilerImpl::writeSoftPointerId(const AcDbSoftPointerId& val)
{
    PyDbObjectId id(val);
    try
    {
        impObj()->writeSoftPointerId(id);
    }
    catch (...)
    {
        return Acad::eInvalidInput;
    }
    return Acad::eOk;
}

Acad::ErrorStatus PyDbDwgFilerImpl::readInt8(Adesk::Int8* pVal)
{
    if (pVal == nullptr)
        return eNullPtr;
    *pVal = impObj()->readInt8();
    return Acad::eOk;
}

Acad::ErrorStatus PyDbDwgFilerImpl::writeInt8(Adesk::Int8 val)
{
    try
    {
        impObj()->writeInt8(val);
    }
    catch (...)
    {
        return Acad::eInvalidInput;
    }
    return Acad::eOk;
}

Acad::ErrorStatus PyDbDwgFilerImpl::readString(ACHAR** pVal)
{
    return acutNewString(utf8_to_wstr(impObj()->readString()).c_str(), *pVal);
}

Acad::ErrorStatus PyDbDwgFilerImpl::readString(AcString& val)
{
    val = utf8_to_wstr(impObj()->readString()).c_str();
    return Acad::eInvalidInput;
}

Acad::ErrorStatus PyDbDwgFilerImpl::writeString(const ACHAR* pVal)
{
    try
    {
        impObj()->writeString(wstr_to_utf8(pVal));
    }
    catch (...)
    {
        return Acad::eInvalidInput;
    }
    return Acad::eOk;
}

Acad::ErrorStatus PyDbDwgFilerImpl::writeString(const AcString& pVal)
{
    try
    {
        impObj()->writeString(wstr_to_utf8(pVal));
    }
    catch (...)
    {
        return Acad::eInvalidInput;
    }
    return Acad::eOk;
}

Acad::ErrorStatus PyDbDwgFilerImpl::readBChunk(ads_binary* pVal)
{
    return Acad::eInvalidInput;
}

Acad::ErrorStatus PyDbDwgFilerImpl::writeBChunk(const ads_binary&)
{
    return Acad::eInvalidInput;
}

Acad::ErrorStatus PyDbDwgFilerImpl::readAcDbHandle(AcDbHandle* pVal)
{
    return Acad::eInvalidInput;
}

Acad::ErrorStatus PyDbDwgFilerImpl::writeAcDbHandle(const AcDbHandle& val)
{
    return Acad::eInvalidInput;
}

Acad::ErrorStatus PyDbDwgFilerImpl::readInt64(Adesk::Int64* pVal)
{
    return Acad::eInvalidInput;
}

Acad::ErrorStatus PyDbDwgFilerImpl::writeInt64(Adesk::Int64 val)
{
    return Acad::eInvalidInput;
}

Acad::ErrorStatus PyDbDwgFilerImpl::readInt32(Adesk::Int32* pVal)
{
    return Acad::eInvalidInput;
}

Acad::ErrorStatus PyDbDwgFilerImpl::writeInt32(Adesk::Int32 val)
{
    return Acad::eInvalidInput;
}

Acad::ErrorStatus PyDbDwgFilerImpl::readInt16(Adesk::Int16* pVal)
{
    return Acad::eInvalidInput;
}

Acad::ErrorStatus PyDbDwgFilerImpl::writeInt16(Adesk::Int16 val)
{
    return Acad::eInvalidInput;
}

Acad::ErrorStatus PyDbDwgFilerImpl::readUInt64(Adesk::UInt64* pVal)
{
    return Acad::eInvalidInput;
}

Acad::ErrorStatus PyDbDwgFilerImpl::writeUInt64(Adesk::UInt64 val)
{
    return Acad::eInvalidInput;
}

Acad::ErrorStatus PyDbDwgFilerImpl::readUInt32(Adesk::UInt32* pVal)
{
    return Acad::eInvalidInput;
}

Acad::ErrorStatus PyDbDwgFilerImpl::writeUInt32(Adesk::UInt32 val)
{
    return Acad::eInvalidInput;
}

Acad::ErrorStatus PyDbDwgFilerImpl::readUInt16(Adesk::UInt16* pVal)
{
    return Acad::eInvalidInput;
}

Acad::ErrorStatus PyDbDwgFilerImpl::writeUInt16(Adesk::UInt16 val)
{
    return Acad::eInvalidInput;
}

Acad::ErrorStatus PyDbDwgFilerImpl::readUInt8(Adesk::UInt8* pVal)
{
    return Acad::eInvalidInput;
}

Acad::ErrorStatus PyDbDwgFilerImpl::writeUInt8(Adesk::UInt8 val)
{
    return Acad::eInvalidInput;
}

Acad::ErrorStatus PyDbDwgFilerImpl::readBoolean(Adesk::Boolean* pVal)
{
    return Acad::eInvalidInput;
}

Acad::ErrorStatus PyDbDwgFilerImpl::writeBoolean(Adesk::Boolean val)
{
    return Acad::eInvalidInput;
}

Acad::ErrorStatus PyDbDwgFilerImpl::readBool(bool* pVal)
{
    return Acad::eInvalidInput;
}

Acad::ErrorStatus PyDbDwgFilerImpl::writeBool(bool val)
{
    return Acad::eInvalidInput;
}

Acad::ErrorStatus PyDbDwgFilerImpl::readDouble(double* pVal)
{
    return Acad::eInvalidInput;
}

Acad::ErrorStatus PyDbDwgFilerImpl::writeDouble(double val)
{
    return Acad::eInvalidInput;
}

Acad::ErrorStatus PyDbDwgFilerImpl::readPoint2d(AcGePoint2d* pVal)
{
    return Acad::eInvalidInput;
}

Acad::ErrorStatus PyDbDwgFilerImpl::writePoint2d(const AcGePoint2d& val)
{
    return Acad::eInvalidInput;
}

Acad::ErrorStatus PyDbDwgFilerImpl::readPoint3d(AcGePoint3d* pVal)
{
    return Acad::eInvalidInput;
}

Acad::ErrorStatus PyDbDwgFilerImpl::writePoint3d(const AcGePoint3d& val)
{
    return Acad::eInvalidInput;
}

Acad::ErrorStatus PyDbDwgFilerImpl::readVector2d(AcGeVector2d* pVal)
{
    return Acad::eInvalidInput;
}

Acad::ErrorStatus PyDbDwgFilerImpl::writeVector2d(const AcGeVector2d& val)
{
    return Acad::eInvalidInput;
}

Acad::ErrorStatus PyDbDwgFilerImpl::readVector3d(AcGeVector3d* pVal)
{
    return Acad::eInvalidInput;
}

Acad::ErrorStatus PyDbDwgFilerImpl::writeVector3d(const AcGeVector3d& val)
{
    return Acad::eInvalidInput;
}

Acad::ErrorStatus PyDbDwgFilerImpl::readScale3d(AcGeScale3d* pVal)
{
    return Acad::eInvalidInput;
}

Acad::ErrorStatus PyDbDwgFilerImpl::writeScale3d(const AcGeScale3d& val)
{
    return Acad::eInvalidInput;
}

Acad::ErrorStatus PyDbDwgFilerImpl::readBytes(void* pDest, Adesk::UIntPtr nBytes)
{
    return Acad::eInvalidInput;
}

Acad::ErrorStatus PyDbDwgFilerImpl::writeBytes(const void* pSrc, Adesk::UIntPtr nBytes)
{
    return Acad::eInvalidInput;
}

Acad::ErrorStatus PyDbDwgFilerImpl::readAddress(void** pVal)
{
    return Acad::eInvalidInput;
}

Acad::ErrorStatus PyDbDwgFilerImpl::writeAddress(const void* pVal)
{
    return Acad::eInvalidInput;
}

Acad::ErrorStatus PyDbDwgFilerImpl::seek(Adesk::Int64 nOffset, int nMethod)
{
    return Acad::eInvalidInput;
}

Adesk::Int64 PyDbDwgFilerImpl::tell() const
{
    return 0;
}

PyDbDwgFiler* PyDbDwgFilerImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_backFiler == nullptr)
        throw PyNullObject(src);
    return m_backFiler;
}

//-----------------------------------------------------------------------------------------
//PyDbDwgFiler
void makePyDbDwgFilerWrapper()
{

}

PyDbDwgFiler::PyDbDwgFiler()
    : PyRxObject(new PyDbDwgFilerImpl(this), true, false)
{
}

Acad::ErrorStatus PyDbDwgFiler::filerStatus() const
{
    return impObj()->filerStatus();
}

AcDb::FilerType PyDbDwgFiler::filerType() const
{
    return impObj()->filerType();
}

void PyDbDwgFiler::setFilerStatus(Acad::ErrorStatus es)
{
    return impObj()->setFilerStatus(es);
}

void PyDbDwgFiler::resetFilerStatus()
{
    return impObj()->resetFilerStatus();
}

boost::python::tuple PyDbDwgFiler::dwgVersion() const
{
    PyAutoLockGIL lock;
    AcDb::AcDbDwgVersion ver;
    AcDb::MaintenanceReleaseVersion maintVer;
    PyThrowBadEs(impObj()->dwgVersion(ver, maintVer));
    return boost::python::make_tuple(ver, maintVer);
}

PyDbObjectId PyDbDwgFiler::readHardOwnershipId()
{
    AcDbHardOwnershipId id;
    PyThrowBadEs(impObj()->readHardOwnershipId(&id));
    return PyDbObjectId(id);
}

void PyDbDwgFiler::writeHardOwnershipId(const PyDbObjectId& id)
{
    PyThrowBadEs(impObj()->writeHardOwnershipId(id.m_id));
}

PyDbObjectId PyDbDwgFiler::readSoftOwnershipId()
{
    AcDbSoftOwnershipId id;
    PyThrowBadEs(impObj()->readSoftOwnershipId(&id));
    return PyDbObjectId(id);
}

void PyDbDwgFiler::writeSoftOwnershipId(const PyDbObjectId& id)
{
    PyThrowBadEs(impObj()->writeSoftOwnershipId(id.m_id));
}

PyDbObjectId PyDbDwgFiler::readHardPointerId()
{
    AcDbHardPointerId id;
    PyThrowBadEs(impObj()->readHardPointerId(&id));
    return PyDbObjectId(id);
}

void PyDbDwgFiler::writeHardPointerId(const PyDbObjectId& id)
{
    PyThrowBadEs(impObj()->writeHardPointerId(id.m_id));
}

PyDbObjectId PyDbDwgFiler::readSoftPointerId()
{
    AcDbSoftPointerId id;
    PyThrowBadEs(impObj()->readSoftPointerId(&id));
    return PyDbObjectId(id);
}

void PyDbDwgFiler::writeSoftPointerId(const PyDbObjectId& id)
{
    PyThrowBadEs(impObj()->writeSoftPointerId(id.m_id));
}

Adesk::Int8 PyDbDwgFiler::readInt8()
{
    Adesk::Int8 val;
    PyThrowBadEs(impObj()->readInt8(&val));
    return val;
}

void PyDbDwgFiler::writeInt8(Adesk::Int8 val)
{
    PyThrowBadEs(impObj()->writeInt8(val));
}

std::string PyDbDwgFiler::readString()
{
    AcString val;
    PyThrowBadEs(impObj()->readString(val));
    return wstr_to_utf8(val);
}

void PyDbDwgFiler::writeString(const std::string& pVal)
{
    PyThrowBadEs(impObj()->writeString(utf8_to_wstr(pVal).c_str()));
}

//TODO TEST this!!!
boost::python::object PyDbDwgFiler::readBChunk()
{
    ads_binary adsval = { 0 };
    PyThrowBadEs(impObj()->readBChunk(&adsval));
    PyAutoLockGIL lock;
    PyObject* py_buf = PyMemoryView_FromMemory(adsval.buf, (size_t)adsval.clen, PyBUF_WRITE);
    return boost::python::object(boost::python::handle<>(py_buf));
}

//TODO TEST this!!!
void PyDbDwgFiler::writeBChunk(const boost::python::object& val)
{
    if (!PyObject_CheckBuffer(val.ptr()))
        PyThrowBadEs(eInvalidInput);
    Py_buffer view;
    if (PyObject_GetBuffer(val.ptr(), &view, PyBUF_ANY_CONTIGUOUS) == -1)
        PyThrowBadEs(eInvalidInput);
    ads_binary adsval = { 0 };
    adsval.clen = view.len;
    adsval.buf = static_cast<char*>(view.buf);
    PyThrowBadEs(impObj()->writeBChunk(adsval));
    PyBuffer_Release(&view);
}

PyDbHandle PyDbDwgFiler::readAcDbHandle()
{
    AcDbHandle val;
    PyThrowBadEs(impObj()->readAcDbHandle(&val));
    return PyDbHandle(val);
}

void PyDbDwgFiler::writeAcDbHandle(const PyDbHandle& val)
{
    PyThrowBadEs(impObj()->writeAcDbHandle(val.m_hnd));
}

Adesk::Int64 PyDbDwgFiler::readInt64()
{
    Adesk::Int64 val;
    PyThrowBadEs(impObj()->readInt64(&val));
    return val;
}

void PyDbDwgFiler::writeInt64(Adesk::Int64 val)
{
    PyThrowBadEs(impObj()->writeInt64(val));
}

Adesk::Int32 PyDbDwgFiler::readInt32()
{
    Adesk::Int32 val;
    PyThrowBadEs(impObj()->readInt32(&val));
    return val;
}

void PyDbDwgFiler::writeInt32(Adesk::Int32 val)
{
    PyThrowBadEs(impObj()->writeInt32(val));
}

Adesk::Int16 PyDbDwgFiler::readInt16()
{
    Adesk::Int16 val;
    PyThrowBadEs(impObj()->readInt16(&val));
    return val;
}

void PyDbDwgFiler::writeInt16(Adesk::Int16 val)
{
    PyThrowBadEs(impObj()->writeInt16(val));
}

Adesk::UInt64 PyDbDwgFiler::readUInt64()
{
    Adesk::UInt64 val;
    PyThrowBadEs(impObj()->readUInt64(&val));
    return val;
}

void PyDbDwgFiler::writeUInt64(Adesk::UInt64 val)
{
    PyThrowBadEs(impObj()->writeUInt64(val));
}

Adesk::UInt32 PyDbDwgFiler::readUInt32()
{
    Adesk::UInt32 val;
    PyThrowBadEs(impObj()->readUInt32(&val));
    return val;
}

void PyDbDwgFiler::writeUInt32(Adesk::UInt32 val)
{
    PyThrowBadEs(impObj()->writeUInt32(val));
}

Adesk::UInt16 PyDbDwgFiler::readUInt16()
{
    Adesk::UInt16 val;
    PyThrowBadEs(impObj()->readUInt16(&val));
    return val;
}

void PyDbDwgFiler::writeUInt16(Adesk::UInt16 val)
{
    PyThrowBadEs(impObj()->writeUInt16(val));
}

Adesk::UInt8 PyDbDwgFiler::readUInt8()
{
    Adesk::UInt8 val;
    PyThrowBadEs(impObj()->readUInt8(&val));
    return val;
}

void PyDbDwgFiler::writeUInt8(Adesk::UInt8 val)
{
    PyThrowBadEs(impObj()->writeUInt8(val));
}

Adesk::Boolean PyDbDwgFiler::readBoolean()
{
    Adesk::Boolean val;
    PyThrowBadEs(impObj()->readBoolean(&val));
    return val;
}

void PyDbDwgFiler::writeBoolean(Adesk::Boolean val)
{
    PyThrowBadEs(impObj()->writeBoolean(val));
}

bool PyDbDwgFiler::readBool()
{
    bool val;
    PyThrowBadEs(impObj()->readBool(&val));
    return val;
}

void PyDbDwgFiler::writeBool(bool val)
{
    PyThrowBadEs(impObj()->writeBool(val));
}

double PyDbDwgFiler::readDouble()
{
    double val;
    PyThrowBadEs(impObj()->readDouble(&val));
    return val;
}

void PyDbDwgFiler::writeDouble(double val)
{
    PyThrowBadEs(impObj()->writeDouble(val));
}

AcGePoint2d PyDbDwgFiler::readPoint2d()
{
    AcGePoint2d val;
    PyThrowBadEs(impObj()->readPoint2d(&val));
    return val;
}

void PyDbDwgFiler::writePoint2d(const AcGePoint2d& val)
{
    PyThrowBadEs(impObj()->writePoint2d(val));
}

AcGePoint3d PyDbDwgFiler::readPoint3d()
{
    AcGePoint3d val;
    PyThrowBadEs(impObj()->readPoint3d(&val));
    return val;
}

void PyDbDwgFiler::writePoint3d(const AcGePoint3d& val)
{
    PyThrowBadEs(impObj()->writePoint3d(val));
}

AcGeVector2d PyDbDwgFiler::readVector2d()
{
    AcGeVector2d val;
    PyThrowBadEs(impObj()->readVector2d(&val));
    return val;
}

void PyDbDwgFiler::writeVector2d(const AcGeVector2d& val)
{
    PyThrowBadEs(impObj()->writeVector2d(val));
}

AcGeVector3d PyDbDwgFiler::readVector3d()
{
    AcGeVector3d val;
    PyThrowBadEs(impObj()->readVector3d(&val));
    return val;
}

void PyDbDwgFiler::writeVector3d(const AcGeVector3d& val)
{
    PyThrowBadEs(impObj()->writeVector3d(val));
}

AcGeScale3d PyDbDwgFiler::readScale3d()
{
    AcGeScale3d val;
    PyThrowBadEs(impObj()->readScale3d(&val));
    return val;
}

void PyDbDwgFiler::writeScale3d(const AcGeScale3d& val)
{
    PyThrowBadEs(impObj()->writeScale3d(val));
}

boost::python::object PyDbDwgFiler::readBytes()
{
    ads_binary adsval = { 0 };
    PyThrowBadEs(impObj()->readBChunk(&adsval));
    PyAutoLockGIL lock;
    PyObject* py_buf = PyMemoryView_FromMemory(adsval.buf, (size_t)adsval.clen, PyBUF_WRITE);
    return boost::python::object(boost::python::handle<>(py_buf));
}

void PyDbDwgFiler::writeBytes(const boost::python::object& val)
{
    if (!PyObject_CheckBuffer(val.ptr()))
        PyThrowBadEs(eInvalidInput);
    Py_buffer view;
    if (PyObject_GetBuffer(val.ptr(), &view, PyBUF_ANY_CONTIGUOUS) == -1)
        PyThrowBadEs(eInvalidInput);
    PyThrowBadEs(impObj()->writeBytes(static_cast<char*>(view.buf), view.len));
    PyBuffer_Release(&view);
}

INT_PTR PyDbDwgFiler::readAddress()
{
    void* val;
    PyThrowBadEs(impObj()->readAddress(&val));
    return (INT_PTR)val;
}

void PyDbDwgFiler::writeAddress(INT_PTR val)
{
    PyThrowBadEs(impObj()->writeAddress((void*)val));
}

void PyDbDwgFiler::seek(Adesk::Int64 nOffset, int nMethod)
{
    PyThrowBadEs(impObj()->seek(nOffset, nMethod));
}

Adesk::Int64 PyDbDwgFiler::tell() const
{
    return impObj()->tell();
}

PyRxClass PyDbDwgFiler::desc()
{
    return PyRxClass(AcDbDwgFiler::desc(), false);
}

std::string PyDbDwgFiler::className()
{
    return std::string{ "AcDbDwgFiler" };
}

AcDbDwgFiler* PyDbDwgFiler::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcDbDwgFiler*>(m_pyImp.get());
}


#endif// ENABLE_FILER

