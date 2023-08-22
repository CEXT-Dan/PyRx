#include "stdafx.h"
#include "PyGiTransientManager.h"
#include "PyGiDrawable.h"

using namespace boost::python;

void makePyGiTransientManagerWrapper()
{
    class_<PyGiTransientManager>("TransientManager")
        .def("addTransient", &PyGiTransientManager::addTransient)
        .def("eraseTransient", &PyGiTransientManager::eraseTransient)
        .def("eraseTransients", &PyGiTransientManager::eraseTransients)
        .def("updateTransient", &PyGiTransientManager::updateTransient)
        .def("addChildTransient", &PyGiTransientManager::addChildTransient)
        .def("eraseChildTransient", &PyGiTransientManager::eraseChildTransient)
        .def("updateChildTransient", &PyGiTransientManager::updateChildTransient)
        .def("getFreeSubDrawingMode", &PyGiTransientManager::getFreeSubDrawingMode)
        .def("current", &PyGiTransientManager::current).staticmethod("current")
        ;
}

PyGiTransientManager::PyGiTransientManager()
    : PyGiTransientManager(acgiGetTransientManager())
{
}

PyGiTransientManager::PyGiTransientManager(AcGiTransientManager* ptr)
    : m_pyImp(ptr)
{
}

bool PyGiTransientManager::addTransient(PyGiDrawable& pDrawable, AcGiTransientDrawingMode mode, int subDrawingMode, const boost::python::list& viewportNumbers)
{
    return impObj()->addTransient(pDrawable.impObj(), mode, subDrawingMode, PyListToIntArray(viewportNumbers));
}

bool PyGiTransientManager::eraseTransient(PyGiDrawable& pDrawable, const boost::python::list& viewportNumbers)
{
    return impObj()->eraseTransient(pDrawable.impObj(), PyListToIntArray(viewportNumbers));
}

bool PyGiTransientManager::eraseTransients(AcGiTransientDrawingMode mode, int subDrawingMode, const boost::python::list& viewportNumbers)
{
    return impObj()->eraseTransients(mode, subDrawingMode, PyListToIntArray(viewportNumbers));
}

void PyGiTransientManager::updateTransient(PyGiDrawable& pDrawable, const boost::python::list& viewportNumbers)
{
    return impObj()->updateTransient(pDrawable.impObj(), PyListToIntArray(viewportNumbers));
}

bool PyGiTransientManager::addChildTransient(PyGiDrawable& pDrawable, PyGiDrawable& pParentDrawable)
{
    return impObj()->addChildTransient(pDrawable.impObj(), pParentDrawable.impObj());
}

bool PyGiTransientManager::eraseChildTransient(PyGiDrawable& pDrawable, PyGiDrawable& pParentDrawable)
{
    return impObj()->eraseChildTransient(pDrawable.impObj(), pParentDrawable.impObj());
}

void PyGiTransientManager::updateChildTransient(PyGiDrawable& pDrawable, PyGiDrawable& pParentDrawable)
{
    return impObj()->updateChildTransient(pDrawable.impObj(), pParentDrawable.impObj());
}

boost::python::tuple PyGiTransientManager::getFreeSubDrawingMode(AcGiTransientDrawingMode mode, int subDrawingMode, const boost::python::list& viewportNumbers)
{
    PyAutoLockGIL lock;
    int _subDrawingMode = subDrawingMode;
    int res = impObj()->getFreeSubDrawingMode(mode, _subDrawingMode, PyListToIntArray(viewportNumbers));
    return boost::python::make_tuple(res, _subDrawingMode);
}

PyGiTransientManager PyGiTransientManager::current()
{
    return PyGiTransientManager(acgiGetTransientManager());
}

AcGiTransientManager* PyGiTransientManager::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]]
        throw PyNullObject(src);
    return m_pyImp;
}
