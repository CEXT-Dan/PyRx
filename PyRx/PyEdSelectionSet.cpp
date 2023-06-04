#include "stdafx.h"
#include "PyEdSelectionSet.h"
#include "PyDbObjectId.h"

using namespace boost::python;

void makePyEdSelectionSetWrapper()
{
    class_<PyEdSelectionSet>("SelectionSet", boost::python::no_init)
        .def("isInitialized", &PyEdSelectionSet::isInitialized)
        .def("size", &PyEdSelectionSet::size)
        .def("clear", &PyEdSelectionSet::clear)
        .def("toList", &PyEdSelectionSet::toList)
        ;
}

PyEdSelectionSet::PyEdSelectionSet(const ads_name& ss)
    : m_pSet(new PySSName(), PyEdSSDeleter())
{
    auto& a = *m_pSet;
    a[0] = ss[0];
    a[1] = ss[1];
}

bool PyEdSelectionSet::isInitialized() const
{
    if (m_pSet == nullptr)
        return false;
    else if ((m_pSet->at(0) == 0) && (m_pSet->at(1) == 0))
        return false;
    else
        return true;
}

size_t PyEdSelectionSet::size()
{
    if (!isInitialized())
        return 0;
    Adesk::Int32 sslen = 0;
    if (acedSSLength(impObj()->data(), &sslen) != RTNORM)
        return 0;
    return sslen;
}

void PyEdSelectionSet::clear()
{
    m_pSet.reset(new std::array<int64_t, 2>());
}

boost::python::list PyEdSelectionSet::toList()
{
    PyAutoLockGIL lock;

    PyDbObjectId objId;
    ads_name ent = { 0 };
    boost::python::list idList;

    const size_t len = size();
    for (size_t i = 0; i < len; i++)
    {
        if (acedSSName(impObj()->data(), i, ent) == RTNORM)
        {
            if (acdbGetObjectId(objId.m_id, ent) == eOk)
                idList.append(objId);
        }
    }
    return idList;
}

std::array<int64_t, 2>* PyEdSelectionSet::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pSet == nullptr)
        throw PyNullObject(src);
    return m_pSet.get();
}
