#include "stdafx.h"
#include "PyLayerFilter.h"
#include "PyDbObjectId.h"
#include "PyDbDatabase.h"
#include "PyDbSymbolTableRecord.h"

using namespace boost::python;

//------------------------------------------------------------------------------------
//PyLyLayerFilter
void makePyLyLayerFilterWrapper()
{
    PyDocString DS("LayerFilter");
    class_<PyLyLayerFilter, bases<PyRxObject>>("LayerFilter")
        .def(init<>())
        .def("name", &PyLyLayerFilter::name, DS.ARGS())
        .def("setName", &PyLyLayerFilter::setName, DS.ARGS({ "val : str" }))
        .def("allowRename", &PyLyLayerFilter::allowRename, DS.ARGS())
        .def("parent", &PyLyLayerFilter::parent, DS.ARGS())
        .def("getNestedFilters", &PyLyLayerFilter::getNestedFilters, DS.ARGS())
        .def("addNested", &PyLyLayerFilter::addNested, DS.ARGS({ "val : PyLy.LayerFilter" }))
        .def("removeNested", &PyLyLayerFilter::removeNested, DS.ARGS({ "val : PyLy.LayerFilter" }))
        .def("generateNested", &PyLyLayerFilter::generateNested, DS.ARGS())
        .def("dynamicallyGenerated", &PyLyLayerFilter::dynamicallyGenerated, DS.ARGS())
        .def("allowNested", &PyLyLayerFilter::allowNested, DS.ARGS())
        .def("allowDelete", &PyLyLayerFilter::allowDelete, DS.ARGS())
        .def("isProxy", &PyLyLayerFilter::isProxy, DS.ARGS())
        .def("isIdFilter", &PyLyLayerFilter::isIdFilter, DS.ARGS())
        .def("filter", &PyLyLayerFilter::filter, DS.ARGS({ "val : PyDb.LayerTableRecord" }))
        .def("showEditor", &PyLyLayerFilter::showEditor, DS.ARGS())
        .def("filterExpression", &PyLyLayerFilter::filterExpression, DS.ARGS())
        .def("setFilterExpression", &PyLyLayerFilter::setFilterExpression, DS.ARGS({ "val : str" }))
        .def("compareTo", &PyLyLayerFilter::compareTo, DS.ARGS({ "other : PyLy.LayerFilter" }))
        .def("desc", &PyLyLayerFilter::desc, DS.SARGS()).staticmethod("desc")
        .def("className", &PyLyLayerFilter::className, DS.SARGS()).staticmethod("className")
        ;
}

PyLyLayerFilter::PyLyLayerFilter()
    : PyRxObject(new AcLyLayerFilter(), true, false)
{
}

PyLyLayerFilter::PyLyLayerFilter(AcLyLayerFilter* pt, bool autoDelete)
    : PyRxObject(pt, autoDelete, false)
{
}

const std::string PyLyLayerFilter::name() const
{
    return wstr_to_utf8(impObj()->name());
}

void PyLyLayerFilter::setName(const std::string& name)
{
    PyThrowBadEs(impObj()->setName(utf8_to_wstr(name).c_str()));
}

bool PyLyLayerFilter::allowRename() const
{
    return impObj()->allowRename();
}

PyLyLayerFilter PyLyLayerFilter::parent() const
{
    return PyLyLayerFilter(impObj()->parent(), false);
}

boost::python::list PyLyLayerFilter::getNestedFilters() const
{
    PyAutoLockGIL lock;
    boost::python::list pyFilters;
    const auto& filters = impObj()->getNestedFilters();
    for (auto filter : filters)
        pyFilters.append(PyLyLayerFilter(filter, false));
    return pyFilters;
}

void PyLyLayerFilter::addNested(PyLyLayerFilter& filter)
{
    PyThrowBadEs(impObj()->addNested(filter.impObj()));
}

void PyLyLayerFilter::removeNested(PyLyLayerFilter& filter)
{
    PyThrowBadEs(impObj()->removeNested(filter.impObj()));
}

void PyLyLayerFilter::generateNested()
{
    PyThrowBadEs(impObj()->generateNested());
}

bool PyLyLayerFilter::dynamicallyGenerated() const
{
    return impObj()->dynamicallyGenerated();
}

bool PyLyLayerFilter::allowNested() const
{
    return impObj()->allowNested();
}

bool PyLyLayerFilter::allowDelete() const
{
    return impObj()->allowDelete();
}

bool PyLyLayerFilter::isProxy() const
{
    return impObj()->isProxy();
}

bool PyLyLayerFilter::isIdFilter() const
{
    return impObj()->isIdFilter();
}

bool PyLyLayerFilter::filter(PyDbLayerTableRecord& layer) const
{
    return impObj()->filter(layer.impObj());
}

int PyLyLayerFilter::showEditor()
{
    return impObj()->showEditor();
}

const std::string PyLyLayerFilter::filterExpression() const
{
    return wstr_to_utf8(impObj()->filterExpression());
}

void PyLyLayerFilter::setFilterExpression(const std::string& expr)
{
    PyThrowBadEs(impObj()->setFilterExpression(utf8_to_wstr(expr).c_str()));
}

bool PyLyLayerFilter::compareTo(const PyLyLayerFilter& pOther) const
{
    return impObj()->compareTo(pOther.impObj());
}

PyRxClass PyLyLayerFilter::desc()
{
    return PyRxClass(AcLyLayerFilter::desc(), false);
}

std::string PyLyLayerFilter::className()
{
    return "AcLyLayerFilter";
}

AcLyLayerFilter* PyLyLayerFilter::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcLyLayerFilter*>(m_pyImp.get());
}

//------------------------------------------------------------------------------------
//PyLyLayerGroup
void makePyLyLayerGroupWrapper()
{
    PyDocString DS("PyLyLayerFilter");
    class_<PyLyLayerGroup, bases<PyLyLayerFilter>>("LayerGroup")
        .def(init<>())
        .def("addLayerId", &PyLyLayerGroup::addLayerId)
        .def("removeLayerId", &PyLyLayerGroup::removeLayerId)
        .def("layerIds", &PyLyLayerGroup::layerIds)
        .def("desc", &PyLyLayerGroup::desc, DS.SARGS()).staticmethod("desc")
        .def("className", &PyLyLayerGroup::className, DS.SARGS()).staticmethod("className")
        ;
}

PyLyLayerGroup::PyLyLayerGroup()
    : PyLyLayerGroup(new AcLyLayerGroup(), true)
{
}

PyLyLayerGroup::PyLyLayerGroup(AcLyLayerGroup* pt, bool autoDelete)
    : PyLyLayerFilter(pt, autoDelete)
{
}

void PyLyLayerGroup::addLayerId(const PyDbObjectId& id)
{
    PyThrowBadEs(impObj()->addLayerId(id.m_id));
}

void PyLyLayerGroup::removeLayerId(const PyDbObjectId& id)
{
    PyThrowBadEs(impObj()->removeLayerId(id.m_id));
}

boost::python::list PyLyLayerGroup::layerIds() const
{
    return ObjectIdArrayToPyList(impObj()->layerIds());
}

PyRxClass PyLyLayerGroup::desc()
{
    return PyRxClass(AcLyLayerGroup::desc(), false);
}

std::string PyLyLayerGroup::className()
{
    return "AcLyLayerGroup";
}

AcLyLayerGroup* PyLyLayerGroup::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcLyLayerGroup*>(m_pyImp.get());
}

//------------------------------------------------------------------------------------
//PyLayerFilterManager
void makePyLayerFilterManagerWrapper()
{
    class_<PyLayerFilterManager>("LayerFilterManager")
        .def(init<>())
        .def(init<PyDbDatabase&>())
        .def("getFilters", &PyLayerFilterManager::getFilters)
        .def("setFilters", &PyLayerFilterManager::setFilters1)
        .def("setFilters", &PyLayerFilterManager::setFilters2)
        ;
}

PyLayerFilterManager::PyLayerFilterManager()
    : imp(aclyGetLayerFilterManager(acdbHostApplicationServices()->workingDatabase()))
{
}

PyLayerFilterManager::PyLayerFilterManager(PyDbDatabase& db)
    : imp(aclyGetLayerFilterManager(db.impObj()))
{
}

boost::python::tuple PyLayerFilterManager::getFilters()
{
    PyAutoLockGIL lock;
    AcLyLayerFilter* root = nullptr;
    AcLyLayerFilter* current = nullptr;
    PyThrowBadEs(imp->getFilters(root, current));
    return boost::python::make_tuple(PyLyLayerFilter(root, false), PyLyLayerFilter(current, false));//current is owned by root
}

void PyLayerFilterManager::setFilters1(boost::python::tuple& tpl)
{
    const size_t tplSize = boost::python::len(tpl);
    if (tplSize != 2)
        PyThrowBadEs(eInvalidInput);
    PyLyLayerFilter root = extract<PyLyLayerFilter>(tpl[0]);
    PyLyLayerFilter current = extract<PyLyLayerFilter>(tpl[1]);
    PyThrowBadEs(imp->setFilters(root.impObj(), current.impObj()));
    root.forceKeepAlive(true);
    current.forceKeepAlive(true);
}

void PyLayerFilterManager::setFilters2(PyLyLayerFilter& root, PyLyLayerFilter& current)
{
    PyThrowBadEs(imp->setFilters(root.impObj(), current.impObj()));
    root.forceKeepAlive(true);
    current.forceKeepAlive(true);
}

