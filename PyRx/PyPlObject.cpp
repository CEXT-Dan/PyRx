#include "stdafx.h"
#include "PyPlObject.h"

using namespace boost::python;
//-----------------------------------------------------------------------------------------
//PyRxObject
void makePyPlObjectWrapper()
{
    PyDocString DS("PlObject");
    class_<PyPlObject, bases<PyRxObject>>("PlObject", boost::python::no_init)
        .def("className", &PyRxClass::className, DS.SARGS()).staticmethod("className")
        ;
}

PyPlObject::PyPlObject(AcPlObject* ptr, bool autoDelete)
    :PyRxObject(ptr, autoDelete, false)
{
}

std::string PyPlObject::className()
{
    return std::string{ "AcPlObject" };
}

AcPlObject* PyPlObject::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]]
        throw PyNullObject(src);
        return static_cast<AcPlObject*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
//PyPlDSDData
void makePyPlDSDDataWrapper()
{

}

PyPlDSDData::PyPlDSDData()
    : PyPlDSDData(new AcPlDSDData(), true)
{
}

PyPlDSDData::PyPlDSDData(AcPlDSDData* ptr, bool autoDelete)
    : PyPlObject(ptr, autoDelete)
{
}

std::string PyPlDSDData::projectPath() const
{
    return wstr_to_utf8(impObj()->projectPath());
}

void PyPlDSDData::setProjectPath(const std::string& pVal)
{
    impObj()->setProjectPath(utf8_to_wstr(pVal).c_str());
}

std::string PyPlDSDData::destinationName() const
{
    return wstr_to_utf8(impObj()->destinationName());
}

void PyPlDSDData::setDestinationName(const std::string& pVal)
{
    impObj()->setDestinationName(utf8_to_wstr(pVal).c_str());
}

boost::python::list PyPlDSDData::getDSDEntries() const
{
    PyAutoLockGIL lock;
    boost::python::list pyList;
    //...
    return pyList;
}

void PyPlDSDData::setDSDEntries(const boost::python::list& val)
{
    //...
}

boost::python::list PyPlDSDData::getPrecisionEntries() const
{
    PyAutoLockGIL lock;
    boost::python::list pyList;
    //...
    return pyList;
}

void PyPlDSDData::setPrecisionEntries(const boost::python::list& val)
{
    //...
}

int PyPlDSDData::numberOfDSDEntries() const
{
    return impObj()->numberOfDSDEntries();
}

AcPlDSDEntry::SheetType PyPlDSDData::sheetType() const
{
    return impObj()->sheetType();
}

void PyPlDSDData::setSheetType(AcPlDSDEntry::SheetType val)
{
    return impObj()->setSheetType(val);
}

std::string PyPlDSDData::password() const
{
    return wstr_to_utf8(impObj()->password());
}

void PyPlDSDData::setPassword(const std::string& pVal)
{
    impObj()->setPassword(utf8_to_wstr(pVal).c_str());
}

void PyPlDSDData::getUnrecognizedData(boost::python::list& sectionArray, boost::python::list& dataArray) const
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    AcStringArray _sectionArray;
    AcStringArray _dataArray;
    impObj()->getUnrecognizedData(_sectionArray, _dataArray);
    for (const auto& item : _sectionArray)
        sectionArray.append(wstr_to_utf8(item));
    for (const auto& item : _dataArray)
        dataArray.append(wstr_to_utf8(item));
#endif
}

void PyPlDSDData::setUnrecognizedData1(const std::string& pSectionName, const std::string& pSectionData)
{
    impObj()->setUnrecognizedData(utf8_to_wstr(pSectionName).c_str(), utf8_to_wstr(pSectionData).c_str());
}

void PyPlDSDData::setUnrecognizedData2(const boost::python::list& sectionArray, const boost::python::list& dataArray)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    impObj()->setUnrecognizedData(PyListAcStringArray(sectionArray), PyListAcStringArray(dataArray));
#endif
}

PyRxClass PyPlDSDData::desc()
{
    return PyRxClass(AcPlDSDData::desc(), false);
}

std::string PyPlDSDData::className()
{
    return "AcPlDSDData";
}

AcPlDSDData* PyPlDSDData::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]]
        throw PyNullObject(src);
        return static_cast<AcPlDSDData*>(m_pyImp.get());
}
