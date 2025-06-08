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
        .def(init<>(DS.ARGS(14645)))
        .def("name", &PyLyLayerFilter::name, DS.ARGS(14666))
        .def("setName", &PyLyLayerFilter::setName, DS.ARGS({ "val : str" }, 14671))
        .def("allowRename", &PyLyLayerFilter::allowRename, DS.ARGS(14654))
        .def("parent", &PyLyLayerFilter::parent, DS.ARGS(14667))
        .def("getNestedFilters", &PyLyLayerFilter::getNestedFilters, DS.ARGS(14663))
        .def("addNested", &PyLyLayerFilter::addNested, DS.ARGS({ "val : PyAp.LayerFilter" }, 14651))
        .def("removeNested", &PyLyLayerFilter::removeNested, DS.ARGS({ "val : PyAp.LayerFilter" }, 14669))
        .def("generateNested", &PyLyLayerFilter::generateNested, DS.ARGS(14661))
        .def("dynamicallyGenerated", &PyLyLayerFilter::dynamicallyGenerated, DS.ARGS(14657))
        .def("allowNested", &PyLyLayerFilter::allowNested, DS.ARGS(14653))
        .def("allowDelete", &PyLyLayerFilter::allowDelete, DS.ARGS(14652))
        .def("isProxy", &PyLyLayerFilter::isProxy, DS.ARGS(14665))
        .def("isIdFilter", &PyLyLayerFilter::isIdFilter, DS.ARGS(14664))
        .def("filter", &PyLyLayerFilter::filter, DS.ARGS({ "val : PyDb.LayerTableRecord" }, 14658))
        .def("showEditor", &PyLyLayerFilter::showEditor, DS.ARGS(14672))
        .def("filterExpression", &PyLyLayerFilter::filterExpression, DS.ARGS(14659))
        .def("setFilterExpression", &PyLyLayerFilter::setFilterExpression, DS.ARGS({ "val : str" }, 14670))
        .def("compareTo", &PyLyLayerFilter::compareTo, DS.ARGS({ "other : PyAp.LayerFilter" }, 14655))
        .def("desc", &PyLyLayerFilter::desc, DS.SARGS(15560)).staticmethod("desc")
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

void PyLyLayerFilter::setName(const std::string& name) const
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
    for (auto filter : impObj()->getNestedFilters())
        pyFilters.append(PyLyLayerFilter(filter, false));
    return pyFilters;
}

void PyLyLayerFilter::addNested(PyLyLayerFilter& filter) const
{
    PyThrowBadEs(impObj()->addNested(filter.impObj()));
}

void PyLyLayerFilter::removeNested(PyLyLayerFilter& filter) const
{
    PyThrowBadEs(impObj()->removeNested(filter.impObj()));
}

void PyLyLayerFilter::generateNested() const
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

int PyLyLayerFilter::showEditor() const
{
    return impObj()->showEditor();
}

const std::string PyLyLayerFilter::filterExpression() const
{
    return wstr_to_utf8(impObj()->filterExpression());
}

void PyLyLayerFilter::setFilterExpression(const std::string& expr) const
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
    PyDocString DS("LayerGroup");
    class_<PyLyLayerGroup, bases<PyLyLayerFilter>>("LayerGroup")
        .def(init<>(DS.ARGS()))
        .def("addLayerId", &PyLyLayerGroup::addLayerId, DS.ARGS({ "id: PyDb.ObjectId" }))
        .def("removeLayerId", &PyLyLayerGroup::removeLayerId, DS.ARGS({ "id: PyDb.ObjectId" }))
        .def("layerIds", &PyLyLayerGroup::layerIds, DS.ARGS())
        .def("desc", &PyLyLayerGroup::desc, DS.SARGS(15560)).staticmethod("desc")
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

void PyLyLayerGroup::addLayerId(const PyDbObjectId& id) const
{
    PyThrowBadEs(impObj()->addLayerId(id.m_id));
}

void PyLyLayerGroup::removeLayerId(const PyDbObjectId& id) const
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
    constexpr const std::string_view setFiltersOverloads = "Overloads:\n"
        "- root: PyAp.LayerFilter, current: PyAp.LayerFilter\n"
        "- rootCurrent : tuple[PyAp.LayerFilter,PyAp.LayerFilter]\n";

    PyDocString DS("LayerFilterManager");
    class_<PyLayerFilterManager>("LayerFilterManager")
        .def(init<>())
        .def(init<PyDbDatabase&>(DS.ARGS({ "db: PyDb.Database = ..." })))
        .def("getFilters", &PyLayerFilterManager::getFilters, DS.ARGS())
        .def("setFilters", &PyLayerFilterManager::setFilters1)
        .def("setFilters", &PyLayerFilterManager::setFilters2, DS.OVRL(setFiltersOverloads))
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

