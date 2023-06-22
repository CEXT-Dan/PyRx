#include "stdafx.h"
#include "PyDbObjectContext.h"
#include "dbAnnotationScale.h"
#include "dbObjContext.h"


using namespace boost::python;

//-----------------------------------------------------------------------------------------
//PyDbObjectContext
void makePyDbObjectContextWrapper()
{
#ifndef ZRXAPP
    class_<PyDbObjectContext, bases<PyRxObject>>("ObjectContext", boost::python::no_init)
        .def("getName", &PyDbObjectContext::getName)
        .def("setName", &PyDbObjectContext::setName)
        .def("uniqueIdentifier", &PyDbObjectContext::uniqueIdentifier)
        .def("collectionName", &PyDbObjectContext::collectionName)
        .def("desc", &PyDbObjectContext::desc).staticmethod("desc")
        .def("className", &PyDbObjectContext::className).staticmethod("className")
        ;
#endif
}

#ifndef ZRXAPP
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
#endif

//-----------------------------------------------------------------------------------------
// PyDbAnnotationScale
void makePyDbAnnotationScaleWrapper()
{
#ifndef ZRXAPP
    class_<PyDbAnnotationScale, bases<PyDbObjectContext>>("AnnotationScale")
        .def(init<>())
        .def("copyFrom", &PyDbAnnotationScale::copyFrom)
        .def("collectionName", &PyDbAnnotationScale::collectionName)
        .def("uniqueIdentifier", &PyDbAnnotationScale::uniqueIdentifier)
        .def("getName", &PyDbAnnotationScale::getName)
        .def("getPaperUnits", &PyDbAnnotationScale::getPaperUnits)
        .def("getDrawingUnits", &PyDbAnnotationScale::getDrawingUnits)
        .def("getScale", &PyDbAnnotationScale::getScale)
        .def("getIsTemporaryScale", &PyDbAnnotationScale::getIsTemporaryScale)
        .def("setName", &PyDbAnnotationScale::setName)
        .def("setPaperUnits", &PyDbAnnotationScale::setPaperUnits)
        .def("setDrawingUnits", &PyDbAnnotationScale::setDrawingUnits)
        .def("matchScaleId", &PyDbAnnotationScale::matchScaleId)
        .def("desc", &PyDbAnnotationScale::desc).staticmethod("desc")
        .def("className", &PyDbAnnotationScale::className).staticmethod("className")
        ;
#endif
}

#ifndef ZRXAPP
PyDbAnnotationScale::PyDbAnnotationScale()
    : PyDbObjectContext(new AcDbAnnotationScale())
{
}

PyDbAnnotationScale::PyDbAnnotationScale(AcDbAnnotationScale* pt)
    : PyDbObjectContext(pt)
{
}

Acad::ErrorStatus PyDbAnnotationScale::copyFrom(const PyRxObject& val)
{
    return impObj()->copyFrom(val.impObj());
}

std::string PyDbAnnotationScale::collectionName() const
{
    return wstr_to_utf8(impObj()->collectionName());
}

Adesk::LongPtr PyDbAnnotationScale::uniqueIdentifier() const
{
    return impObj()->uniqueIdentifier();
}

std::string PyDbAnnotationScale::getName() const
{
    AcString str;
    if (auto es = impObj()->getName(str); es != eOk)
        throw PyAcadErrorStatus(es);
    return wstr_to_utf8(str);
}

double PyDbAnnotationScale::getPaperUnits() const
{
    double val;
    if (auto es = impObj()->getPaperUnits(val); es != eOk)
        throw PyAcadErrorStatus(es);
    return val;
}

double PyDbAnnotationScale::getDrawingUnits() const
{
    double val;
    if (auto es = impObj()->getDrawingUnits(val); es != eOk)
        throw PyAcadErrorStatus(es);
    return val;
}

double PyDbAnnotationScale::getScale() const
{
    double val;
    if (auto es = impObj()->getScale(val); es != eOk)
        throw PyAcadErrorStatus(es);
    return val;
}

bool PyDbAnnotationScale::getIsTemporaryScale() const
{
    bool val;
    if (auto es = impObj()->getIsTemporaryScale(val); es != eOk)
        throw PyAcadErrorStatus(es);
    return val;
}

Acad::ErrorStatus PyDbAnnotationScale::setName(std::string& val)
{
    return impObj()->setName(utf8_to_wstr(val).c_str());
}

Acad::ErrorStatus PyDbAnnotationScale::setPaperUnits(double val)
{
    return impObj()->setPaperUnits(val);
}

Acad::ErrorStatus PyDbAnnotationScale::setDrawingUnits(double val)
{
    return impObj()->setDrawingUnits(val);
}

bool PyDbAnnotationScale::matchScaleId(Adesk::LongPtr val) const
{
    return impObj()->matchScaleId(val);
}

PyRxClass PyDbAnnotationScale::desc()
{
    return PyRxClass(AcDbAnnotationScale::desc(), false);
}

std::string PyDbAnnotationScale::className()
{
    return std::string{ "AcDbAnnotationScale" };
}

AcDbAnnotationScale* PyDbAnnotationScale::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcDbAnnotationScale*>(m_pyImp.get());
}

#endif