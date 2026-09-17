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
    class_<PyDbSnoopDwgFiler, boost::noncopyable>("SnoopDwgFiler")
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

#if defined(_ARXTARGET) && (_ARXTARGET >= 260)
//depreciated
#else
Acad::ErrorStatus PyDbSnoopDwgFiler::readString(ACHAR** pVal)
{
    return eOk;
}
#endif
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
    class_<PyDbSnoopDxfFiler, boost::noncopyable>("SnoopDxfFiler")
        .def(init<>())
        .def("buffer", &PyDbSnoopDxfFiler::buffer, DS.ARGS())
        .def("__getitem__", &PyDbSnoopDwgFiler::getitem, DS.ARGS())
        ;
}

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


//-----------------------------------------------------------------------------------------
//CMemoryDwgFiler
// 
CMemoryDwgFiler::CMemoryDwgFiler()
    : m_stat(Acad::eOk), m_filerType(AcDb::kCopyFiler), m_index(0)
{
}

bool CMemoryDwgFiler::peekType(FilerToken::Type expectedType) const
{
    if (m_index >= m_tokens.size()) {
        return false;
    }
    const auto curtype = m_tokens[m_index].type;
    return curtype == expectedType;
}

size_t CMemoryDwgFiler::size() const
{
    return m_tokens.size();
}

Adesk::Int64 CMemoryDwgFiler::tell() const
{
    return static_cast<Adesk::Int64>(m_index);
}

Acad::ErrorStatus CMemoryDwgFiler::seek(Adesk::Int64 nOffset, int nMethod)
{
    constexpr Adesk::Int64 kMaxIndex = (std::numeric_limits<Adesk::Int64>::max)();
    if (m_index > static_cast<size_t>(kMaxIndex) || m_tokens.size() > static_cast<size_t>(kMaxIndex)) {
        m_stat = Acad::eInvalidInput;
        return m_stat;
    }

    Adesk::Int64 baseIndex = 0;
    if (nMethod == SEEK_SET) {
        baseIndex = 0;
    }
    else if (nMethod == SEEK_CUR) {
        baseIndex = static_cast<Adesk::Int64>(m_index);
    }
    else if (nMethod == SEEK_END) {
        baseIndex = static_cast<Adesk::Int64>(m_tokens.size());
    }
    else {
        m_stat = Acad::eInvalidInput;
        return m_stat;
    }

    if (nOffset == (std::numeric_limits<Adesk::Int64>::min)()
        || (nOffset < 0 && baseIndex < -nOffset)
        || (nOffset > 0 && baseIndex > kMaxIndex - nOffset)) {
        m_stat = Acad::eEndOfFile;
        return m_stat;
    }

    const Adesk::Int64 targetIndex = baseIndex + nOffset;
    if (targetIndex > static_cast<Adesk::Int64>(m_tokens.size())) {
        m_stat = Acad::eEndOfFile;
        return m_stat;
    }

    m_index = static_cast<size_t>(targetIndex);
    return Acad::eOk;
}

Acad::ErrorStatus CMemoryDwgFiler::readHardOwnershipId(AcDbHardOwnershipId* pVal) { return readToken(FilerToken::Type::kHardOwnershipId, pVal); }
Acad::ErrorStatus CMemoryDwgFiler::writeHardOwnershipId(const AcDbHardOwnershipId& val) { return writeToken(FilerToken::Type::kHardOwnershipId, val); }
Acad::ErrorStatus CMemoryDwgFiler::readSoftOwnershipId(AcDbSoftOwnershipId* pVal) { return readToken(FilerToken::Type::kSoftOwnershipId, pVal); }
Acad::ErrorStatus CMemoryDwgFiler::writeSoftOwnershipId(const AcDbSoftOwnershipId& val) { return writeToken(FilerToken::Type::kSoftOwnershipId, val); }
Acad::ErrorStatus CMemoryDwgFiler::readHardPointerId(AcDbHardPointerId* pVal) { return readToken(FilerToken::Type::kHardPointerId, pVal); }
Acad::ErrorStatus CMemoryDwgFiler::writeHardPointerId(const AcDbHardPointerId& val) { return writeToken(FilerToken::Type::kHardPointerId, val); }
Acad::ErrorStatus CMemoryDwgFiler::readSoftPointerId(AcDbSoftPointerId* pVal) { return readToken(FilerToken::Type::kSoftPointerId, pVal); }
Acad::ErrorStatus CMemoryDwgFiler::writeSoftPointerId(const AcDbSoftPointerId& val) { return writeToken(FilerToken::Type::kSoftPointerId, val); }

// --- Primitive Integer Implementations ---
Acad::ErrorStatus CMemoryDwgFiler::readInt8(Adesk::Int8* pVal)
{
    if (pVal == nullptr) return Acad::eInvalidInput;
    Adesk::UInt8 val;
    Acad::ErrorStatus es = readToken(FilerToken::Type::kUInt8, &val);
    if (es == Acad::eOk) *pVal = static_cast<Adesk::Int8>(val);
    return es;
}

Acad::ErrorStatus CMemoryDwgFiler::writeInt8(Adesk::Int8 val) { return writeToken(FilerToken::Type::kUInt8, static_cast<Adesk::UInt8>(val)); }
Acad::ErrorStatus CMemoryDwgFiler::readInt16(Adesk::Int16* pVal) { return readToken(FilerToken::Type::kInt16, pVal); }
Acad::ErrorStatus CMemoryDwgFiler::writeInt16(Adesk::Int16 val) { return writeToken(FilerToken::Type::kInt16, val); }
Acad::ErrorStatus CMemoryDwgFiler::readUInt16(Adesk::UInt16* pVal) { return readToken(FilerToken::Type::kUInt16, pVal); }
Acad::ErrorStatus CMemoryDwgFiler::writeUInt16(Adesk::UInt16 val) { return writeToken(FilerToken::Type::kUInt16, val); }
Acad::ErrorStatus CMemoryDwgFiler::readInt32(Adesk::Int32* pVal) { return readToken(FilerToken::Type::kInt32, pVal); }
Acad::ErrorStatus CMemoryDwgFiler::writeInt32(Adesk::Int32 val) { return writeToken(FilerToken::Type::kInt32, val); }
Acad::ErrorStatus CMemoryDwgFiler::readUInt32(Adesk::UInt32* pVal) { return readToken(FilerToken::Type::kUInt32, pVal); }
Acad::ErrorStatus CMemoryDwgFiler::writeUInt32(Adesk::UInt32 val) { return writeToken(FilerToken::Type::kUInt32, val); }
Acad::ErrorStatus CMemoryDwgFiler::readInt64(Adesk::Int64* pVal) { return readToken(FilerToken::Type::kInt64, pVal); }
Acad::ErrorStatus CMemoryDwgFiler::writeInt64(Adesk::Int64 val) { return writeToken(FilerToken::Type::kInt64, val); }
Acad::ErrorStatus CMemoryDwgFiler::readUInt64(Adesk::UInt64* pVal) { return readToken(FilerToken::Type::kUInt64, pVal); }
Acad::ErrorStatus CMemoryDwgFiler::writeUInt64(Adesk::UInt64 val) { return writeToken(FilerToken::Type::kUInt64, val); }
Acad::ErrorStatus CMemoryDwgFiler::readUInt8(Adesk::UInt8* pVal) { return readToken(FilerToken::Type::kUInt8, pVal); }
Acad::ErrorStatus CMemoryDwgFiler::writeUInt8(Adesk::UInt8 val) { return writeToken(FilerToken::Type::kUInt8, val); }
Acad::ErrorStatus CMemoryDwgFiler::readBool(bool* pVal) { return readToken(FilerToken::Type::kBoolean, pVal); }
Acad::ErrorStatus CMemoryDwgFiler::writeBool(bool val) { return writeToken(FilerToken::Type::kBoolean, val); }

Acad::ErrorStatus CMemoryDwgFiler::writeBoolean(Adesk::Boolean val) {
    return writeBool(val ? true : false);
}
Acad::ErrorStatus CMemoryDwgFiler::readBoolean(Adesk::Boolean* pVal) {
    if (!pVal) return Acad::eInvalidInput;
    bool val;
    Acad::ErrorStatus es = readBool(&val);
    if (es == Acad::eOk) *pVal = val ? Adesk::kTrue : Adesk::kFalse;
    return es;
}

Acad::ErrorStatus CMemoryDwgFiler::readDouble(double* pVal) { return readToken(FilerToken::Type::kDouble, pVal); }
Acad::ErrorStatus CMemoryDwgFiler::writeDouble(double val) { return writeToken(FilerToken::Type::kDouble, val); }
Acad::ErrorStatus CMemoryDwgFiler::readPoint2d(AcGePoint2d* pVal) { return readToken(FilerToken::Type::kPoint2d, pVal); }
Acad::ErrorStatus CMemoryDwgFiler::writePoint2d(const AcGePoint2d& val) { return writeToken(FilerToken::Type::kPoint2d, val); }
Acad::ErrorStatus CMemoryDwgFiler::readPoint3d(AcGePoint3d* pVal) { return readToken(FilerToken::Type::kPoint3d, pVal); }
Acad::ErrorStatus CMemoryDwgFiler::writePoint3d(const AcGePoint3d& val) { return writeToken(FilerToken::Type::kPoint3d, val); }
Acad::ErrorStatus CMemoryDwgFiler::readVector2d(AcGeVector2d* pVal) { return readToken(FilerToken::Type::kVector2d, pVal); }
Acad::ErrorStatus CMemoryDwgFiler::writeVector2d(const AcGeVector2d& val) { return writeToken(FilerToken::Type::kVector2d, val); }
Acad::ErrorStatus CMemoryDwgFiler::readVector3d(AcGeVector3d* pVal) { return readToken(FilerToken::Type::kVector3d, pVal); }
Acad::ErrorStatus CMemoryDwgFiler::writeVector3d(const AcGeVector3d& val) { return writeToken(FilerToken::Type::kVector3d, val); }

// Scale3d acts as a composite wrapper for a vector mapping
Acad::ErrorStatus CMemoryDwgFiler::writeScale3d(const AcGeScale3d& val) {
    return writeVector3d(AcGeVector3d(val.sx, val.sy, val.sz));
}
Acad::ErrorStatus CMemoryDwgFiler::readScale3d(AcGeScale3d* pVal) {
    if (!pVal) return Acad::eInvalidInput;
    AcGeVector3d vec;
    Acad::ErrorStatus es = readVector3d(&vec);
    if (es == Acad::eOk) {
        pVal->set(vec.x, vec.y, vec.z);
    }
    return es;
}

Acad::ErrorStatus CMemoryDwgFiler::readAcDbHandle(AcDbHandle* pVal) { return readToken(FilerToken::Type::kHandle, pVal); }
Acad::ErrorStatus CMemoryDwgFiler::writeAcDbHandle(const AcDbHandle& val) { return writeToken(FilerToken::Type::kHandle, val); }

// --- String Fields Handling ---
Acad::ErrorStatus CMemoryDwgFiler::readString(AcString& val) {
    return readToken(FilerToken::Type::kString, &val);
}

Acad::ErrorStatus CMemoryDwgFiler::writeString(const AcString& val) { return writeToken(FilerToken::Type::kString, val); }


Acad::ErrorStatus CMemoryDwgFiler::writeString(const ACHAR* pVal) {
    if (pVal == nullptr) return Acad::eInvalidInput;
    return writeString(AcString(pVal));
}

#if !defined(_ARXTARGET) || (_ARXTARGET < 260)
Acad::ErrorStatus CMemoryDwgFiler::readString(ACHAR** pVal) {
    if (!pVal) return Acad::eInvalidInput;
    AcString str;
    Acad::ErrorStatus es = readString(str);
    if (es == Acad::eOk) {
        size_t len = str.length() + 1;
        *pVal = static_cast<ACHAR*>(acad_malloc(len * sizeof(ACHAR)));
        if (*pVal) {
            _tcscpy_s(*pVal, len, str.constPtr());
        }
        else {
            es = Acad::eOutOfMemory;
        }
    }
    return es;
}
#endif

Acad::ErrorStatus CMemoryDwgFiler::writeByteBuffer(const void* pSrc, Adesk::UIntPtr nBytes)
{
    if (nBytes > static_cast<Adesk::UIntPtr>((std::numeric_limits<size_t>::max)())
        || (pSrc == nullptr && nBytes != 0)) {
        return Acad::eInvalidInput;
    }

    const size_t byteCount = static_cast<size_t>(nBytes);
    FilerToken::ByteBuffer bytes;
    try {
        if (byteCount != 0) {
            const auto* first = static_cast<const Adesk::UInt8*>(pSrc);
            bytes.assign(first, first + byteCount);
        }
    }
    catch (const std::bad_alloc&) {
        m_stat = Acad::eOutOfMemory;
        return m_stat;
    }
    return writeToken(FilerToken::Type::kBytes, std::move(bytes));
}

Acad::ErrorStatus CMemoryDwgFiler::readByteBuffer(const FilerToken::ByteBuffer** pBytes)
{
    if (pBytes == nullptr) return Acad::eInvalidInput;
    if (m_index >= m_tokens.size()) {
        m_stat = Acad::eEndOfFile;
        return m_stat;
    }

    const FilerToken& token = m_tokens[m_index];
    const auto* bytes = std::get_if<FilerToken::ByteBuffer>(&token.value);
    if (token.type != FilerToken::Type::kBytes || bytes == nullptr) {
        m_stat = Acad::eWrongObjectType;
        return m_stat;
    }
    *pBytes = bytes;
    return Acad::eOk;
}

Acad::ErrorStatus CMemoryDwgFiler::writeBChunk(const ads_binary& val)
{
    if (val.clen < 0) return Acad::eInvalidInput;
    return writeByteBuffer(val.buf, static_cast<Adesk::UIntPtr>(val.clen));
}

Acad::ErrorStatus CMemoryDwgFiler::readBChunk(ads_binary* pVal)
{
    if (pVal == nullptr) return Acad::eInvalidInput;

    const FilerToken::ByteBuffer* bytes = nullptr;
    Acad::ErrorStatus es = readByteBuffer(&bytes);
    if (es != Acad::eOk) return es;
    if (bytes->size() > static_cast<size_t>((std::numeric_limits<Adesk::Int32>::max)())) {
        m_stat = Acad::eInvalidInput;
        return m_stat;
    }

    char* buffer = nullptr;
    if (!bytes->empty()) {
        buffer = static_cast<char*>(acad_malloc(bytes->size()));
        if (buffer == nullptr) {
            m_stat = Acad::eOutOfMemory;
            return m_stat;
        }
        std::memcpy(buffer, bytes->data(), bytes->size());
    }

    pVal->buf = buffer;
    pVal->clen = static_cast<Adesk::Int32>(bytes->size());
    ++m_index;
    return Acad::eOk;
}

Acad::ErrorStatus CMemoryDwgFiler::writeBytes(const void* pSrc, Adesk::UIntPtr nBytes)
{
    return writeByteBuffer(pSrc, nBytes);
}

Acad::ErrorStatus CMemoryDwgFiler::readBytes(void* pDest, Adesk::UIntPtr nBytes)
{
    if (nBytes > static_cast<Adesk::UIntPtr>((std::numeric_limits<size_t>::max)())
        || (pDest == nullptr && nBytes != 0)) {
        return Acad::eInvalidInput;
    }

    const FilerToken::ByteBuffer* bytes = nullptr;
    Acad::ErrorStatus es = readByteBuffer(&bytes);
    if (es != Acad::eOk) return es;

    const size_t byteCount = static_cast<size_t>(nBytes);
    if (bytes->size() != byteCount) {
        m_stat = Acad::eInvalidInput;
        return m_stat;
    }
    if (byteCount != 0) {
        std::memcpy(pDest, bytes->data(), byteCount);
    }
    ++m_index;
    return Acad::eOk;
}

// Memory pointers addresses aren't preserved natively over standard object state serializations
Acad::ErrorStatus CMemoryDwgFiler::writeAddress(const void* pVal) {
    return writeInt64(reinterpret_cast<Adesk::Int64>(pVal));
}

Acad::ErrorStatus CMemoryDwgFiler::readAddress(void** pVal) {
    if (!pVal) return Acad::eInvalidInput;
    Adesk::Int64 val;
    Acad::ErrorStatus es = readInt64(&val);
    if (es == Acad::eOk) *pVal = reinterpret_cast<void*>(val);
    return es;
}
