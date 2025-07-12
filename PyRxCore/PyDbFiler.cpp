#include "stdafx.h"
#include "PyDbFiler.h"
#include "PyDbObjectId.h"
#include "ResultBuffer.h"

using namespace boost::python;
//-----------------------------------------------------------------------------------------
//SnoopDwgFiler
void makePyDbSnoopDwgFilerWrapper()
{
    PyDocString DS("SnoopDwgFiler");
    class_<PyDbSnoopDwgFiler>("SnoopDwgFiler")
        .def(init<>())
        .def(init<AcDb::FilerType>(DS.ARGS({ "filerType: PyDb.FilerType" })))
        .def("buffer", &PyDbSnoopDwgFiler::buffer, DS.ARGS())
        .def("__getitem__", &PyDbSnoopDwgFiler::getitem, DS.ARGS())
        ;
}

PyDbSnoopDwgFiler::PyDbSnoopDwgFiler()
{
}

PyDbSnoopDwgFiler::PyDbSnoopDwgFiler(AcDb::FilerType ft)
    :m_filerType(ft)
{
}

#ifdef _BRXTARGET_COPY_CTOR
PyDbSnoopDwgFiler::PyDbSnoopDwgFiler(const PyDbSnoopDwgFiler&)
    : AcDbDwgFiler()
{
    PyThrowBadEs(eNotApplicable);
}
#endif

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
    PyObjectPtr pObj(PyMemoryView_FromMemory(adsval.buf, adsval.clen, PyBUF_READ));
    boost::python::object memoryView{ boost::python::handle<>(PyBytes_FromObject(pObj.get())) };
    m_list.append(boost::python::make_tuple("ads_binary", memoryView));
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
    PyObjectPtr pObj(PyMemoryView_FromMemory((char*)pSrc, (size_t)nBytes, PyBUF_READ));
    boost::python::object memoryView{ boost::python::handle<>(PyBytes_FromObject(pObj.get())) };
    m_list.append(boost::python::make_tuple("ByteArray", memoryView));
    return eOk;
}

Acad::ErrorStatus PyDbSnoopDwgFiler::readAddress(void** pVal)
{
    return eOk;
}

Acad::ErrorStatus PyDbSnoopDwgFiler::writeAddress(const void* pVal)
{
    PyAutoLockGIL m_lock;
    m_list.append(boost::python::make_tuple("Address", INT_PTR(pVal)));
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

boost::python::object PyDbSnoopDwgFiler::getitem(int idx)
{
    return m_list[idx];
}

//-----------------------------------------------------------------------------------------
//PyDbSnoopDxfFiler
void makePyDbSnoopDxfFilerrWrapper()
{
    PyDocString DS("SnoopDxfFiler");
    class_<PyDbSnoopDxfFiler>("SnoopDxfFiler")
        .def(init<>())
        .def("buffer", &PyDbSnoopDxfFiler::buffer, DS.ARGS())
        .def("__getitem__", &PyDbSnoopDwgFiler::getitem, DS.ARGS())
        ;
}

#ifdef _BRXTARGET_COPY_CTOR
PyDbSnoopDxfFiler::PyDbSnoopDxfFiler(const PyDbSnoopDxfFiler&)
    : AcDbDxfFiler()
{
    PyThrowBadEs(eNotApplicable);
}
#endif

int PyDbSnoopDxfFiler::rewindFiler()
{
    return 1;
}

Acad::ErrorStatus PyDbSnoopDxfFiler::filerStatus() const
{
    return eOk;
}

void PyDbSnoopDxfFiler::resetFilerStatus()
{
    //ok
}

AcDb::FilerType PyDbSnoopDxfFiler::filerType() const
{
    return AcDb::FilerType::kBagFiler;
}

AcDbDatabase* PyDbSnoopDxfFiler::database() const
{
    return mpDb;
}

Acad::ErrorStatus PyDbSnoopDxfFiler::writeResBuf(const resbuf& rb)
{
    m_list.append(boost::python::make_tuple(rb.restype, resbufToList(const_cast<resbuf*>(std::addressof(rb)))));
    return eOk;
}

Acad::ErrorStatus PyDbSnoopDxfFiler::writeObjectId(AcDb::DxfCode code, const AcDbObjectId& id)
{
    m_list.append(boost::python::make_tuple(code, PyDbObjectId(id)));
    return eOk;
}

Acad::ErrorStatus PyDbSnoopDxfFiler::writeInt8(AcDb::DxfCode code, Adesk::Int8 val)
{
    m_list.append(boost::python::make_tuple(code, val));
    return eOk;
}

Acad::ErrorStatus PyDbSnoopDxfFiler::writeString(AcDb::DxfCode code, const ACHAR* pVal)
{
    m_list.append(boost::python::make_tuple(code, wstr_to_utf8(pVal)));
    return eOk;
}

Acad::ErrorStatus PyDbSnoopDxfFiler::writeString(AcDb::DxfCode code, const AcString& pVal)
{
    m_list.append(boost::python::make_tuple(code, wstr_to_utf8(pVal)));
    return eOk;
}

Acad::ErrorStatus PyDbSnoopDxfFiler::writeBChunk(AcDb::DxfCode code, const ads_binary& val)
{
    PyAutoLockGIL lock;
    PyObjectPtr pObj(PyMemoryView_FromMemory((char*)val.buf, (size_t)val.clen, PyBUF_READ));
    boost::python::object memoryView{ boost::python::handle<>(PyBytes_FromObject(pObj.get())) };
    m_list.append(boost::python::make_tuple(code, memoryView));
    return eOk;
}

Acad::ErrorStatus PyDbSnoopDxfFiler::writeAcDbHandle(AcDb::DxfCode code, const AcDbHandle& val)
{
    m_list.append(boost::python::make_tuple(code, PyDbHandle(val)));
    return eOk;
}

Acad::ErrorStatus PyDbSnoopDxfFiler::writeInt64(AcDb::DxfCode code, Adesk::Int64 val)
{
    m_list.append(boost::python::make_tuple(code, val));
    return eOk;
}

Acad::ErrorStatus PyDbSnoopDxfFiler::writeInt32(AcDb::DxfCode code, Adesk::Int32 val)
{
    m_list.append(boost::python::make_tuple(code, val));
    return eOk;
}

Acad::ErrorStatus PyDbSnoopDxfFiler::writeInt16(AcDb::DxfCode code, Adesk::Int16 val)
{
    m_list.append(boost::python::make_tuple(code, val));
    return eOk;
}

Acad::ErrorStatus PyDbSnoopDxfFiler::writeUInt64(AcDb::DxfCode code, Adesk::UInt64 val)
{
    m_list.append(boost::python::make_tuple(code, val));
    return eOk;
}

Acad::ErrorStatus PyDbSnoopDxfFiler::writeUInt32(AcDb::DxfCode code, Adesk::UInt32 val)
{
    m_list.append(boost::python::make_tuple(code, val));
    return eOk;
}

Acad::ErrorStatus PyDbSnoopDxfFiler::writeUInt16(AcDb::DxfCode code, Adesk::UInt16 val)
{
    m_list.append(boost::python::make_tuple(code, val));
    return eOk;
}

Acad::ErrorStatus PyDbSnoopDxfFiler::writeUInt8(AcDb::DxfCode code, Adesk::UInt8 val)
{
    m_list.append(boost::python::make_tuple(code, val));
    return eOk;
}

Acad::ErrorStatus PyDbSnoopDxfFiler::writeBool(AcDb::DxfCode code, bool val)
{
    m_list.append(boost::python::make_tuple(code, val));
    return eOk;
}

Acad::ErrorStatus PyDbSnoopDxfFiler::writeBoolean(AcDb::DxfCode code, Adesk::Boolean val)
{
    m_list.append(boost::python::make_tuple(code, val));
    return eOk;
}

Acad::ErrorStatus PyDbSnoopDxfFiler::writeDouble(AcDb::DxfCode code, double val, int prec /*= kDfltPrec*/)
{
    m_list.append(boost::python::make_tuple(code, val));
    return eOk;
}

Acad::ErrorStatus PyDbSnoopDxfFiler::writePoint2d(AcDb::DxfCode code, const AcGePoint2d& val, int prec /*= kDfltPrec*/)
{
    m_list.append(boost::python::make_tuple(code, val));
    return eOk;
}

Acad::ErrorStatus PyDbSnoopDxfFiler::writePoint3d(AcDb::DxfCode code, const AcGePoint3d& val, int prec /*= kDfltPrec*/)
{
    m_list.append(boost::python::make_tuple(code, val));
    return eOk;
}

Acad::ErrorStatus PyDbSnoopDxfFiler::writeVector2d(AcDb::DxfCode code, const AcGeVector2d& val, int prec /*= kDfltPrec*/)
{
    m_list.append(boost::python::make_tuple(code, val));
    return eOk;
}

Acad::ErrorStatus PyDbSnoopDxfFiler::writeVector3d(AcDb::DxfCode code, const AcGeVector3d& val, int prec /*= kDfltPrec*/)
{
    m_list.append(boost::python::make_tuple(code, val));
    return eOk;
}

Acad::ErrorStatus PyDbSnoopDxfFiler::writeScale3d(AcDb::DxfCode code, const AcGeScale3d& val, int prec /*= kDfltPrec*/)
{
    m_list.append(boost::python::make_tuple(code, val));
    return eOk;
}

bool PyDbSnoopDxfFiler::includesDefaultValues() const
{
    return true;
}

Acad::ErrorStatus PyDbSnoopDxfFiler::setVAError(Acad::ErrorStatus, const ACHAR*, va_list)
{
    return eOk;
}

boost::python::list PyDbSnoopDxfFiler::buffer() const
{
    return m_list;
}

boost::python::object PyDbSnoopDxfFiler::getitem(int idx)
{
    return m_list[idx];
}