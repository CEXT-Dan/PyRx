#include "stdafx.h"
#include "PyDbObjectContext.h"
#include "dbObjectContextManager.h"
using namespace boost::python;

//-----------------------------------------------------------------------------------------
//PyDbObjectContextCollection
void makePyDbObjectContextCollectionWrapper()
{
    class_<PyDbObjectContextCollection, bases<PyRxObject>>("ObjectContextCollection", boost::python::no_init)
        .def("desc", &PyDbObjectContextCollection::desc).staticmethod("desc")
        .def("className", &PyDbObjectContextCollection::className).staticmethod("className")
        ;
}

PyDbObjectContextCollection::PyDbObjectContextCollection(AcDbObjectContextCollection* pt)
    : PyRxObject(pt)
{
}

PyRxClass PyDbObjectContextCollection::desc()
{
    return PyRxClass(AcDbObjectContextCollection::desc(), false);
}

std::string PyDbObjectContextCollection::className()
{
    return "AcDbObjectContextCollection";
}

AcDbObjectContextCollection* PyDbObjectContextCollection::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<AcDbObjectContextCollection*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
//PyDbObjectContextManager
void makePyDbObjectContextManagerWrapper()
{
    class_<PyDbObjectContextManager, bases<PyRxObject>>("ObjectContextManager", boost::python::no_init)
        .def("registerContextCollection", &PyDbObjectContextManager::registerContextCollection)
        .def("unregisterContextCollection", &PyDbObjectContextManager::unregisterContextCollection)
        .def("contextCollection", &PyDbObjectContextManager::contextCollection)
        .def("desc", &PyDbObjectContextManager::desc).staticmethod("desc")
        .def("className", &PyDbObjectContextManager::className).staticmethod("className")
        ;
}

PyDbObjectContextManager::PyDbObjectContextManager(AcDbObjectContextManager* pt)
    : PyRxObject(pt)
{
}

void PyDbObjectContextManager::registerContextCollection(const std::string& collectionName, const PyDbObjectContextCollection& pCollection)
{
   PyThrowBadEs(impObj()->registerContextCollection(utf8_to_wstr(collectionName).c_str(), pCollection.impObj()));
}

void PyDbObjectContextManager::unregisterContextCollection(const std::string& collectionName)
{
    PyThrowBadEs(impObj()->unregisterContextCollection(utf8_to_wstr(collectionName).c_str()));
}

PyDbObjectContextCollection PyDbObjectContextManager::contextCollection(const std::string& collectionName) const
{
    return PyDbObjectContextCollection(impObj()->contextCollection(utf8_to_wstr(collectionName).c_str()));
}

PyRxClass PyDbObjectContextManager::desc()
{
    return PyRxClass(AcDbObjectContextManager::desc(), false);
}

std::string PyDbObjectContextManager::className()
{
    return "AcDbObjectContextManager";
}

AcDbObjectContextManager* PyDbObjectContextManager::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<AcDbObjectContextManager*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
//PyDbObjectContext
void makePyDbObjectContextWrapper()
{
    class_<PyDbObjectContext, bases<PyRxObject>>("ObjectContext", boost::python::no_init)
        .def("getName", &PyDbObjectContext::getName)
        .def("setName", &PyDbObjectContext::setName)
        .def("uniqueIdentifier", &PyDbObjectContext::uniqueIdentifier)
        .def("collectionName", &PyDbObjectContext::collectionName)
        .def("desc", &PyDbObjectContext::desc).staticmethod("desc")
        .def("className", &PyDbObjectContext::className).staticmethod("className")
        ;
}

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
    PyThrowBadEs(impObj()->getName(str));
    return wstr_to_utf8(str);
}

void PyDbObjectContext::setName(const std::string& name)
{
    return PyThrowBadEs(impObj()->setName(utf8_to_wstr(name).c_str()));
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
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbObjectContext*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
// PyDbAnnotationScale
void makePyDbAnnotationScaleWrapper()
{
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
}

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
    PyThrowBadEs(impObj()->copyFrom(val.impObj()));
}

double PyDbAnnotationScale::getPaperUnits() const
{
    double val;
    PyThrowBadEs(impObj()->getPaperUnits(val));
    return val;
}

double PyDbAnnotationScale::getDrawingUnits() const
{
    double val;
    PyThrowBadEs(impObj()->getDrawingUnits(val));
    return val;
}

double PyDbAnnotationScale::getScale() const
{
    double val;
    PyThrowBadEs(impObj()->getScale(val));
    return val;
}

bool PyDbAnnotationScale::getIsTemporaryScale() const
{
    bool val;
    PyThrowBadEs(impObj()->getIsTemporaryScale(val));
    return val;
}

void PyDbAnnotationScale::setPaperUnits(double val)
{
    PyThrowBadEs(impObj()->setPaperUnits(val));
}

void PyDbAnnotationScale::setDrawingUnits(double val)
{
    PyThrowBadEs(impObj()->setDrawingUnits(val));
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
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbAnnotationScale*>(m_pyImp.get());
}
