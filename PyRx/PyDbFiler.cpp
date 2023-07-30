#include "stdafx.h"
#include "PyDbFiler.h"
#include "PyDbObjectId.h"

//TODO

void makePyDbDwgFilerWrapper()
{

}

PyDbDwgFiler::PyDbDwgFiler(AcDbDwgFiler* ptr, bool autoDelete)
    : PyRxObject(ptr, autoDelete,false)
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

AcDb::MaintenanceReleaseVersion PyDbDwgFiler::extendedDwgMaintenanceReleaseVersion() const
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    AcDb::MaintenanceReleaseVersion val;
    PyThrowBadEs(impObj()->extendedDwgMaintenanceReleaseVersion(val));
    return val;
#endif // !BRXAPP
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
    if(PyObject_GetBuffer(val.ptr(), &view, PyBUF_ANY_CONTIGUOUS) == -1)
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
