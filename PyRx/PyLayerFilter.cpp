#include "stdafx.h"
#include "PyLayerFilter.h"
#include "PyDbDatabase.h"

using namespace boost::python;

//------------------------------------------------------------------------------------
//PyLyLayerFilter
void makePyLyLayerFilterWrapper()
{
    PyDocString DS("PyLyLayerFilter");
    class_<PyLyLayerFilter, bases<PyRxObject>>("LayerFilter")
        .def(init<>())
        .def("desc", &PyLyLayerFilter::desc, DS.SARGS()).staticmethod("desc")
        .def("className", &PyLyLayerFilter::className, DS.SARGS()).staticmethod("className")
        ;
}

PyLyLayerFilter::PyLyLayerFilter()
    : PyRxObject(new AcLyLayerFilter(),true,false)
{
}

PyLyLayerFilter::PyLyLayerFilter(AcLyLayerFilter* pt, bool autoDelete)
    : PyRxObject(pt, autoDelete, false)
{
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
    if (m_pyImp == nullptr) [[unlikely]]
        throw PyNullObject(src);
        return static_cast<AcLyLayerFilter*>(m_pyImp.get());
}

//------------------------------------------------------------------------------------
//PyLyLayerGroup
void makePyLyLayerGroupWrapper()
{
    PyDocString DS("PyLyLayerFilter");
    class_<PyLyLayerGroup, bases<PyLyLayerFilter>>("LayerGroup")
        .def(init<>())
        .def("desc", &PyLyLayerGroup::desc, DS.SARGS()).staticmethod("desc")
        .def("className", &PyLyLayerGroup::className, DS.SARGS()).staticmethod("className")
        ;
}

PyLyLayerGroup::PyLyLayerGroup()
    : PyLyLayerGroup(new AcLyLayerGroup(),true)
{
}

PyLyLayerGroup::PyLyLayerGroup(AcLyLayerGroup* pt, bool autoDelete)
    : PyLyLayerFilter(pt, autoDelete)
{
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
    if (m_pyImp == nullptr) [[unlikely]]
        throw PyNullObject(src);
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
        .def("setFilters", &PyLayerFilterManager::setFilters)
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
    return boost::python::make_tuple(PyLyLayerFilter(root, true), PyLyLayerFilter(current, false));
}

void PyLayerFilterManager::setFilters(boost::python::tuple& tpl)
{
    const size_t tplSize = boost::python::len(tpl);
    if (tplSize != 2)
        PyThrowBadEs(eInvalidInput);
    PyLyLayerFilter root = extract<PyLyLayerFilter>(tpl[0]);
    PyLyLayerFilter current = extract<PyLyLayerFilter>(tpl[1]);
    PyThrowBadEs(imp->setFilters(root.impObj(), current.impObj()));
}
