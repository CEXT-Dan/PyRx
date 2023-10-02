#include "stdafx.h"
#include "PyEdSelectionSet.h"
#include "PyDbObjectId.h"
#include "ResultBuffer.h"
#include "PyRxObject.h"

using namespace boost::python;

void makePyEdSelectionSetWrapper()
{
    PyDocString DS("SelectionSet");
    class_<PyEdSelectionSet>("SelectionSet")
        .def(init<>())
        .def("isInitialized", &PyEdSelectionSet::isInitialized, DS.ARGS())
        .def("size", &PyEdSelectionSet::size, DS.ARGS())
        .def("clear", &PyEdSelectionSet::clear, DS.ARGS())
        .def("add", &PyEdSelectionSet::add, DS.ARGS({ "id:PyDb.ObjectId" }))
        .def("remove", &PyEdSelectionSet::remove, DS.ARGS({ "id:PyDb.ObjectId" }))
        .def("hasMember", &PyEdSelectionSet::hasMember, DS.ARGS({ "id:PyDb.ObjectId" }))
        .def("toList", &PyEdSelectionSet::objectIds, DS.ARGS())
        .def("toList", &PyEdSelectionSet::objectIdsOfType, DS.ARGS({ "desc:PyRx.RxClass=AcDbEntity" }))
        .def("objectIds", &PyEdSelectionSet::objectIds)
        .def("objectIds", &PyEdSelectionSet::objectIdsOfType, DS.ARGS({ "desc:PyRx.RxClass=AcDbEntity" }))
        .def("adsname", &PyEdSelectionSet::adsname, DS.ARGS())
        .def("ssNameX", &PyEdSelectionSet::ssNameX1)
        .def("ssNameX", &PyEdSelectionSet::ssNameX2, DS.ARGS({ "val:int = 0" }))
        .def("ssSetFirst", &PyEdSelectionSet::ssSetFirst, DS.ARGS())
        .def("ssXform", &PyEdSelectionSet::ssXform, DS.ARGS({ "xform:PyGe.Matrix3d" }))
        ;
}

PyEdSelectionSet::PyEdSelectionSet()
    : m_pSet(new PySSName(), PyEdSSDeleter())
{
    ads_name result = { 0L,0L };
    PyThrowBadRt(acedSSAdd(nullptr, nullptr, result));
    memcpy(m_pSet->data(), result, sizeof(result));
}

PyEdSelectionSet::PyEdSelectionSet(const ads_name& ss)
    : m_pSet(new PySSName(), PyEdSSDeleter())
{
    memcpy(m_pSet->data(), ss, sizeof(ss));
}

bool PyEdSelectionSet::isInitialized() const
{
    return (m_pSet->at(0) + m_pSet->at(1)) != 0;
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
    if (!isInitialized())
        throw PyAcadErrorStatus(Acad::eNotInitializedYet);
    ads_name ent = { 0 };
    PyThrowBadEs(acdbGetAdsName(ent, objId.m_id));
    PyThrowBadRt(acedSSAdd(ent, impObj()->data(), impObj()->data()));
}

void PyEdSelectionSet::remove(const PyDbObjectId& objId)
{
    if (!isInitialized())
        throw PyAcadErrorStatus(Acad::eNotInitializedYet);
    ads_name ent = { 0 };
    PyThrowBadEs(acdbGetAdsName(ent, objId.m_id));
    PyThrowBadRt(acedSSDel(ent, impObj()->data()));
}

bool PyEdSelectionSet::hasMember(const PyDbObjectId& objId)
{
    if (!isInitialized())
        throw PyAcadErrorStatus(Acad::eNotInitializedYet);
    ads_name ent = { 0 };
    PyThrowBadEs(acdbGetAdsName(ent, objId.m_id));
    return acedSSMemb(ent, impObj()->data()) == RTNORM;
}

AdsName PyEdSelectionSet::adsname() const
{
    if (!isInitialized())
        throw PyAcadErrorStatus(Acad::eNotInitializedYet);
    AdsName _name = { 0L };
    memcpy(&_name, m_pSet->data(), sizeof(_name));
    return _name;
}

bool PyEdSelectionSet::ssSetFirst()
{
    if (!isInitialized())
        throw PyAcadErrorStatus(Acad::eNotInitializedYet);
    ads_name dummy = { 0 };
    return acedSSSetFirst(m_pSet->data(), dummy) == RTNORM;
}

Acad::PromptStatus PyEdSelectionSet::ssXform(const AcGeMatrix3d& xform)
{
    if (!isInitialized())
        throw PyAcadErrorStatus(Acad::eNotInitializedYet);
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
    if (!isInitialized())
        throw PyAcadErrorStatus(Acad::eNotInitializedYet);
    resbuf* rb = nullptr;
    PyThrowBadRt(acedSSNameX(&rb, m_pSet->data(), idx));
    AcResBufPtr ptr(rb);
    return resbufToList(rb);
}

boost::python::list PyEdSelectionSet::objectIds()
{
    if (!isInitialized())
        throw PyAcadErrorStatus(Acad::eNotInitializedYet);
    PyAutoLockGIL lock;
    PyDbObjectId objId;
    ads_name ent = { 0 };
    boost::python::list idList;
    for (size_t i = 0, len = size(); i < len; i++)
    {
        if (acedSSName(impObj()->data(), i, ent) == RTNORM)
        {
            if (acdbGetObjectId(objId.m_id, ent) == eOk)
                idList.append(objId);
        }
    }
    return idList;
}

boost::python::list PyEdSelectionSet::objectIdsOfType(const PyRxClass& _class)
{
    if (!isInitialized())
        throw PyAcadErrorStatus(Acad::eNotInitializedYet);
    PyAutoLockGIL lock;
    AcDbObjectId objId;
    ads_name ent = { 0 };
    boost::python::list idList;
    const auto _desc = _class.impObj();
    for (size_t i = 0, len = size(); i < len; i++)
    {
        if (acedSSName(impObj()->data(), i, ent) == RTNORM)
        {
            if (acdbGetObjectId(objId, ent) == eOk)
            {
                if (objId.objectClass()->isDerivedFrom(_desc))
                    idList.append(PyDbObjectId{ objId });
            }
        }
    }
    return idList;
}

PySSName* PyEdSelectionSet::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pSet == nullptr) [[unlikely]]
        throw PyNullObject(src);
        return m_pSet.get();
}
