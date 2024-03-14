#include "stdafx.h"
#include "PyDbObjectContext.h"
#include "dbObjectContextManager.h"
#include "PyDbObject.h"

using namespace boost::python;

//-----------------------------------------------------------------------------------------
//PyDbObjectContextCollection
void makePyDbObjectContextCollectionWrapper()
{
    PyDocString DS("ObjectContextCollection");
    class_<PyDbObjectContextCollection, bases<PyRxObject>>("ObjectContextCollection", boost::python::no_init)
        .def("name", &PyDbObjectContextCollection::name, DS.ARGS())
        .def("currentContext", &PyDbObjectContextCollection::currentContext, DS.ARGS({ "obj : PyDb.Object" }))
        .def("setCurrentContext", &PyDbObjectContextCollection::setCurrentContext, DS.ARGS({ "obj : PyDb.ObjectContext" }))
        .def("addContext", &PyDbObjectContextCollection::addContext, DS.ARGS({ "obj : PyDb.ObjectContext" }))
        .def("removeContext", &PyDbObjectContextCollection::removeContext, DS.ARGS({ "name : str" }))
        .def("lockContext", &PyDbObjectContextCollection::lockContext, DS.ARGS({ "obj : PyDb.ObjectContext" }))
        .def("unlockContext", &PyDbObjectContextCollection::unlockContext, DS.ARGS())
        .def("locked", &PyDbObjectContextCollection::locked, DS.ARGS())
        .def("getContext", &PyDbObjectContextCollection::getContext, DS.ARGS({ "name : str" }))
        .def("hasContext", &PyDbObjectContextCollection::hasContext, DS.ARGS({ "name : str" }))
        .def("toList", &PyDbObjectContextCollection::toList1)
        .def("toList", &PyDbObjectContextCollection::toList2, DS.ARGS({ "desc:PyRx.RxClass=PyDb.ObjectContext" }))
        .def("desc", &PyDbObjectContextCollection::desc, DS.SARGS()).staticmethod("desc")
        .def("className", &PyDbObjectContextCollection::className, DS.SARGS()).staticmethod("className")
        ;
}

PyDbObjectContextCollection::PyDbObjectContextCollection(AcDbObjectContextCollection* pt)
    : PyRxObject(pt)
{
}

std::string PyDbObjectContextCollection::name() const
{
    return wstr_to_utf8(impObj()->name());
}

PyDbObjectContext PyDbObjectContextCollection::currentContext(const PyDbObject& obj)
{
   return PyDbObjectContext(impObj()->currentContext(obj.impObj()),true);
}

void PyDbObjectContextCollection::setCurrentContext(const PyDbObjectContext& pContext)
{
    PyThrowBadEs(impObj()->setCurrentContext(pContext.impObj()));
}

void PyDbObjectContextCollection::addContext(const PyDbObjectContext& pContext)
{
    PyThrowBadEs(impObj()->addContext(pContext.impObj()));
}

void PyDbObjectContextCollection::removeContext(const std::string& contextName)
{
    PyThrowBadEs(impObj()->removeContext(utf8_to_wstr(contextName).c_str()));
}

void PyDbObjectContextCollection::lockContext(const PyDbObjectContext& pContext)
{
    PyThrowBadEs(impObj()->lockContext(pContext.impObj()));
}

void PyDbObjectContextCollection::unlockContext()
{
    PyThrowBadEs(impObj()->unlockContext());
}

bool PyDbObjectContextCollection::locked() const
{
    return impObj()->locked();
}

PyDbObjectContext PyDbObjectContextCollection::getContext(const std::string& contextName)
{
    return PyDbObjectContext(impObj()->getContext(utf8_to_wstr(contextName).c_str()), true);
}

bool PyDbObjectContextCollection::hasContext(const std::string& contextName)
{
    return impObj()->hasContext(utf8_to_wstr(contextName).c_str());
}

boost::python::list PyDbObjectContextCollection::toList1()
{
    PyAutoLockGIL lock;
    boost::python::list pylist;
    using Iter = std::unique_ptr<AcDbObjectContextCollectionIterator>;

    for (Iter iter(impObj()->newIterator()); !iter->done(); iter->next())
    {
        AcDbObjectContext* pObjectContext = nullptr;
        PyThrowBadEs(iter->getContext(pObjectContext));
        pylist.append(PyDbObjectContext(pObjectContext, true));
    }
    return pylist;
}

boost::python::list PyDbObjectContextCollection::toList2(const PyRxClass& _class)
{
    PyAutoLockGIL lock;
    boost::python::list pylist;
    using Iter = std::unique_ptr<AcDbObjectContextCollectionIterator>;

    for (Iter iter(impObj()->newIterator()); !iter->done(); iter->next())
    {
        AcDbObjectContext* pObjectContext = nullptr;
        PyThrowBadEs(iter->getContext(pObjectContext));

        AcRxClass* pclass = _class.impObj();

        if (pObjectContext->isA() == pclass)
        {
            if(pclass == AcDbAnnotationScale::desc())
                pylist.append(PyDbAnnotationScale(static_cast<AcDbAnnotationScale*>(pObjectContext), true));
            else
                pylist.append(PyDbObjectContext(pObjectContext, true));
        }
    }
    return pylist;
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
    PyDocString DS("ObjectContextManager");
    class_<PyDbObjectContextManager, bases<PyRxObject>>("ObjectContextManager", boost::python::no_init)
        .def("registerContextCollection", &PyDbObjectContextManager::registerContextCollection, DS.ARGS({ "name : str","collection : PyDb.ObjectContextCollection" }))
        .def("unregisterContextCollection", &PyDbObjectContextManager::unregisterContextCollection, DS.ARGS({ "name : str" }))
        .def("contextCollection", &PyDbObjectContextManager::contextCollection, DS.ARGS({ "name : str" }))
        .def("desc", &PyDbObjectContextManager::desc, DS.SARGS()).staticmethod("desc")
        .def("className", &PyDbObjectContextManager::className, DS.SARGS()).staticmethod("className")
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
    PyDocString DS("ObjectContext");
    class_<PyDbObjectContext, bases<PyRxObject>>("ObjectContext", boost::python::no_init)
        .def("getName", &PyDbObjectContext::getName, DS.ARGS())
        .def("setName", &PyDbObjectContext::setName, DS.ARGS({ "name : str" }))
        .def("uniqueIdentifier", &PyDbObjectContext::uniqueIdentifier, DS.ARGS())
        .def("collectionName", &PyDbObjectContext::collectionName, DS.ARGS())
        .def("desc", &PyDbObjectContext::desc, DS.SARGS()).staticmethod("desc")
        .def("className", &PyDbObjectContext::className, DS.SARGS()).staticmethod("className")
        ;
}

PyDbObjectContext::PyDbObjectContext(AcDbObjectContext* pt)
    : PyRxObject(pt)
{
}

PyDbObjectContext::PyDbObjectContext(AcDbObjectContext* pt, bool autoDelete)
    : PyRxObject(pt, autoDelete, false)
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
    PyDocString DS("AnnotationScale");
    class_<PyDbAnnotationScale, bases<PyDbObjectContext>>("AnnotationScale")
        .def(init<>())
        .def("copyFrom", &PyDbAnnotationScale::copyFrom, DS.ARGS({ "otherObject: PyRx.RxObject" }))
        .def("getPaperUnits", &PyDbAnnotationScale::getPaperUnits, DS.ARGS())
        .def("getDrawingUnits", &PyDbAnnotationScale::getDrawingUnits, DS.ARGS())
        .def("getScale", &PyDbAnnotationScale::getScale, DS.ARGS())
        .def("getIsTemporaryScale", &PyDbAnnotationScale::getIsTemporaryScale, DS.ARGS())
        .def("setPaperUnits", &PyDbAnnotationScale::setPaperUnits, DS.ARGS({ "val : float" }))
        .def("setDrawingUnits", &PyDbAnnotationScale::setDrawingUnits, DS.ARGS({ "val : float" }))
        .def("matchScaleId", &PyDbAnnotationScale::matchScaleId, DS.ARGS({ "val : int" }))
        .def("desc", &PyDbAnnotationScale::desc, DS.SARGS()).staticmethod("desc")
        .def("className", &PyDbAnnotationScale::className, DS.SARGS()).staticmethod("className")
        .def("cast", &PyDbAnnotationScale::cast, DS.SARGS({ "otherObject: PyDb.ObjectContext" })).staticmethod("cast")
        ;
}

PyDbAnnotationScale::PyDbAnnotationScale()
    : PyDbObjectContext(new AcDbAnnotationScale(), true)
{
}

PyDbAnnotationScale::PyDbAnnotationScale(AcDbAnnotationScale* pt)
    : PyDbObjectContext(pt)
{
}

PyDbAnnotationScale::PyDbAnnotationScale(AcDbAnnotationScale* pt, bool autoDelete)
    : PyDbObjectContext(pt, autoDelete)
{
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

PyDbAnnotationScale PyDbAnnotationScale::cast(const PyDbObjectContext& other)
{
    PyDbAnnotationScale dest(nullptr, false);
    PyRxObject rxo = other;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
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
