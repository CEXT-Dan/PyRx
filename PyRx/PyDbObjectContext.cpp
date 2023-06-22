#include "stdafx.h"
#include "PyDbObjectContext.h"

using namespace boost::python;

//-----------------------------------------------------------------------------------------
//PyDbObjectContext
void makePyDbObjectContextWrapper()
{
    class_<PyDbObjectContext, bases<PyRxObject>>("PyDbObjectContext", boost::python::no_init)
        .def("getName", &PyDbObjectContext::getName)
        .def("setName", &PyDbObjectContext::setName)
        .def("uniqueIdentifier", &PyDbObjectContext::uniqueIdentifier)
        .def("collectionName", &PyDbObjectContext::collectionName)
        .def("desc", &PyDbObjectContext::desc).staticmethod("desc")
        .def("className", &PyRxClass::className).staticmethod("className")
        ;
}


PyDbObjectContext::PyDbObjectContext(AcDbObjectContext* pt)
    : PyRxObject(pt)
{
}

std::string PyDbObjectContext::getName() const
{
    AcString str;
    if (auto es = impObj()->getName(str); es != eOk)
        throw PyAcadErrorStatus(es);
    return wstr_to_utf8(str);
}

Acad::ErrorStatus PyDbObjectContext::setName(std::string& name)
{
    return impObj()->setName(utf8_to_wstr(name).c_str());
}

Adesk::LongPtr PyDbObjectContext::uniqueIdentifier() const
{
    return impObj()->uniqueIdentifier();
}

std::string PyDbObjectContext::collectionName() const
{
    return wstr_to_utf8(impObj()->collectionName());
}

PyRxClass PyDbObjectContext::desc()
{
    return PyRxClass(AcDbObjectContext::desc(), false);
}

std::string PyDbObjectContext::className()
{
    return std::string{ "AcDbObjectContext" };
}

AcDbObjectContext* PyDbObjectContext::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcDbObjectContext*>(m_pyImp.get());
}
