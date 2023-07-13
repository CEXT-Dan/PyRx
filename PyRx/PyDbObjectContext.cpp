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

PyDbObjectContext::PyDbObjectContext(AcDbObjectContext* pt, bool autoDelete, bool isDbOject)
    : PyRxObject(pt, autoDelete, isDbOject)
{
}

std::string PyDbObjectContext::getName() const
{
    AcString str;
    if (auto es = impObj()->getName(str); es != eOk)
        throw PyAcadErrorStatus(es);
    return wstr_to_utf8(str);
}

void PyDbObjectContext::setName(const std::string& name)
{
    return  PyThrowBadEs(impObj()->setName(utf8_to_wstr(name).c_str()));
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
        .def("getPaperUnits", &PyDbAnnotationScale::getPaperUnits)
        .def("getDrawingUnits", &PyDbAnnotationScale::getDrawingUnits)
        .def("getScale", &PyDbAnnotationScale::getScale)
        .def("getIsTemporaryScale", &PyDbAnnotationScale::getIsTemporaryScale)
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
    : PyDbObjectContext(new AcDbAnnotationScale(), true, false)
{
}

PyDbAnnotationScale::PyDbAnnotationScale(AcDbAnnotationScale* pt)
    : PyDbObjectContext(pt)
{
}

PyDbAnnotationScale::PyDbAnnotationScale(AcDbAnnotationScale* pt, bool autoDelete, bool isDbOject)
    : PyDbObjectContext(pt, autoDelete, isDbOject)
{
}

void PyDbAnnotationScale::copyFrom(const PyRxObject& val)
{
    return  PyThrowBadEs(impObj()->copyFrom(val.impObj()));
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

void PyDbAnnotationScale::setPaperUnits(double val)
{
    return  PyThrowBadEs(impObj()->setPaperUnits(val));
}

void PyDbAnnotationScale::setDrawingUnits(double val)
{
    return  PyThrowBadEs(impObj()->setDrawingUnits(val));
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