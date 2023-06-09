#include "stdafx.h"
#include "PyEdSelectionSet.h"
#include "PyDbObjectId.h"
#include "ResultBuffer.h"

using namespace boost::python;

void makePyEdSelectionSetWrapper()
{
    class_<PyEdSelectionSet>("SelectionSet", boost::python::no_init)
        .def("isInitialized", &PyEdSelectionSet::isInitialized)
        .def("size", &PyEdSelectionSet::size)
        .def("clear", &PyEdSelectionSet::clear)
        .def("add", &PyEdSelectionSet::add)
        .def("remove", &PyEdSelectionSet::remove)
        .def("hasMember", &PyEdSelectionSet::hasMember)
        .def("toList", &PyEdSelectionSet::toList)
        .def("adsname", &PyEdSelectionSet::adsname)
        .def("ssNameX", &PyEdSelectionSet::ssNameX1)
        .def("ssNameX", &PyEdSelectionSet::ssNameX2)
        .def("ssSetFirst", &PyEdSelectionSet::ssSetFirst)
        .def("ssXform", &PyEdSelectionSet::ssXform)
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
    m_pSet.reset(new PySSName());
}

void PyEdSelectionSet::add(const PyDbObjectId& objId)
{
    ads_name ent = { 0 };
    if (auto es = acdbGetAdsName(ent, objId.m_id); es != eOk)
        throw PyAcadErrorStatus(es);
    acedSSAdd(ent, impObj()->data(), impObj()->data());
}

void PyEdSelectionSet::remove(const PyDbObjectId& objId)
{
    ads_name ent = { 0 };
    if (auto es = acdbGetAdsName(ent, objId.m_id); es != eOk)
        throw PyAcadErrorStatus(es);
    acedSSDel(ent, impObj()->data());
}

bool PyEdSelectionSet::hasMember(const PyDbObjectId& objId)
{
    ads_name ent = { 0 };
    if (auto es = acdbGetAdsName(ent, objId.m_id); es != eOk)
        throw PyAcadErrorStatus(es);
    if (acedSSMemb(ent, impObj()->data()) == RTNORM)
        return true;
    else
        return false;
}

AdsName PyEdSelectionSet::adsname() const
{
    AdsName _name;
    if (m_pSet != nullptr)
    {
        _name.m_data[0] = m_pSet->at(0);
        _name.m_data[1] = m_pSet->at(1);
    }
    return _name;
}

bool PyEdSelectionSet::ssSetFirst()
{
    if (m_pSet == nullptr)
        throw PyAcadErrorStatus(eInvalidInput);
    ads_name dummy = { 0 };
    return acedSSSetFirst(m_pSet->data(), dummy) == RTNORM;
}

Acad::PromptStatus PyEdSelectionSet::ssXform(const AcGeMatrix3d& xform)
{
    ads_matrix adsXform;
    memcpy(adsXform, xform.entry, sizeof(ads_matrix));
    return static_cast<Acad::PromptStatus>(acedXformSS(m_pSet->data(), adsXform));
}

boost::python::list PyEdSelectionSet::ssNameX1()
{
    return ssNameX2(0);
}

boost::python::list PyEdSelectionSet::ssNameX2(int idx)
{
    PyAutoLockGIL lock;
    if (m_pSet == nullptr)
        throw PyAcadErrorStatus(eInvalidInput);
    resbuf* rb = nullptr;
    if (RTNORM != acedSSNameX(&rb, m_pSet->data(), idx))
        throw PyAcadErrorStatus(eInvalidInput);
    AcResBufPtr ptr(rb);
    return resbufToList(rb);
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

PySSName* PyEdSelectionSet::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pSet == nullptr)
        throw PyNullObject(src);
    return m_pSet.get();
}
