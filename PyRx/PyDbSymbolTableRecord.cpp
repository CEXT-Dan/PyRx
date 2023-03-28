#include "stdafx.h"
#include "PyDbSymbolTableRecord.h"

using namespace boost::python;
//---------------------------------------------------------------------------------------- -
// PyDbSymbolTableRecord  wrapper
void makeAcDbSymbolTableRecordWrapper()
{
    static auto wrapper = class_<PyDbSymbolTableRecord, bases<PyDbObject>>("DbSymbolTableRecord", boost::python::no_init)
        .def("className", &PyDbSymbolTableRecord::className)
        .def("getName", &PyDbSymbolTableRecord::getName)
        .def("setName", &PyDbSymbolTableRecord::setName)
        ;
}

//---------------------------------------------------------------------------------------- -
// PyDbSymbolTableRecord 
PyDbSymbolTableRecord::PyDbSymbolTableRecord(AcDbSymbolTableRecord* ptr, bool autoDelete)
    : PyDbObject(ptr, autoDelete)
{

}

std::string PyDbSymbolTableRecord::getName()
{
    AcString arxName;
    auto imp = impObj();
    if (imp != nullptr)
        imp->getName(arxName);
    return wstr_to_utf8(arxName);
}

Acad::ErrorStatus PyDbSymbolTableRecord::setName(const std::string name)
{
    const AcString arxName = utf8_to_wstr(name).c_str();
    auto imp = impObj();
    if (imp != nullptr)
        return  imp->setName(arxName);
    return eNullPtr;
}

std::string PyDbSymbolTableRecord::className()
{
    return "AcDbSymbolTableRecord";
}

AcDbSymbolTableRecord* PyDbSymbolTableRecord::impObj() const
{
    return static_cast<AcDbSymbolTableRecord*>(m_pImp);
}
