#include "stdafx.h"
#include "PyEdSelectionSet.h"
#include "ResultBuffer.h"
#include "PyRxObject.h"

using namespace boost::python;

void makePyEdSelectionSetWrapper()
{
    PyDocString DS("SelectionSet");
    class_<PyEdSelectionSet>("SelectionSet")
        .def(init<>(DS.ARGS()))
        .def("isInitialized", &PyEdSelectionSet::isInitialized, DS.ARGS())
        .def("size", &PyEdSelectionSet::size, DS.ARGS())
        .def("clear", &PyEdSelectionSet::clear, DS.ARGS())
        .def("add", &PyEdSelectionSet::add, DS.ARGS({ "id: PyDb.ObjectId" }))
        .def("remove", &PyEdSelectionSet::remove, DS.ARGS({ "id: PyDb.ObjectId" }))
        .def("hasMember", &PyEdSelectionSet::hasMember, DS.ARGS({ "id: PyDb.ObjectId" }))
        .def("toList", &PyEdSelectionSet::objectIds, DS.ARGS())
        .def("toList", &PyEdSelectionSet::objectIdsOfType, DS.ARGS({ "desc: PyRx.RxClass=PyDb.Entity" }))
        .def("objectIds", &PyEdSelectionSet::objectIds)
        .def("objectIds", &PyEdSelectionSet::objectIdsOfType, DS.ARGS({ "desc: PyRx.RxClass=PyDb.Entity" }))
        .def("adsname", &PyEdSelectionSet::adsname, DS.ARGS())
        .def("ssNameX", &PyEdSelectionSet::ssNameX1)
        .def("ssNameX", &PyEdSelectionSet::ssNameX2, DS.ARGS({ "val: int = 0" }))
        .def("ssSetFirst", &PyEdSelectionSet::ssSetFirst, DS.ARGS())
        .def("ssXform", &PyEdSelectionSet::ssXform, DS.ARGS({ "xform: PyGe.Matrix3d" }))
        .def("keepAlive", &PyRxObject::forceKeepAlive, DS.ARGS({ "flag: bool" }))
        .def("__iter__", range(&PyEdSelectionSet::begin, &PyEdSelectionSet::end))
        ;
}


//used a shared pointer for reference counting. 
struct PyEdSSDeleter
{
    explicit PyEdSSDeleter(bool autoDelete)
        : m_autoDelete(autoDelete) {
    }
    ~PyEdSSDeleter() = default;

    inline void operator()(PySSName* ss) const
    {
        if (ss != nullptr)
        {
            if (m_autoDelete && ss->at(0) + ss->at(1) != 0)
                acedSSFree(ss->data());
            delete ss;
        }
    }

    bool m_autoDelete = true;
};

PyEdSelectionSet::PyEdSelectionSet()
    : m_pSet(new PySSName(), PyEdSSDeleter(true))
{
    ads_name result = { 0L,0L };
    PyThrowBadRt(acedSSAdd(nullptr, nullptr, result));
    memcpy(m_pSet->data(), result, sizeof(result));
}

PyEdSelectionSet::PyEdSelectionSet(const ads_name& ss)
    : m_pSet(new PySSName(), PyEdSSDeleter(true))
{
    memcpy(m_pSet->data(), ss, sizeof(ss));
}

PyEdSelectionSet::PyEdSelectionSet(const ads_name& ss, bool autoDelete)
    : m_pSet(new PySSName(), PyEdSSDeleter(autoDelete))
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
    PyAutoLockGIL lock;
    if (!isInitialized())
        throw PyAcadErrorStatus(Acad::eNotInitializedYet);

    PyDbObjectId objId;
    ads_name ename = { 0 };
    boost::python::list idList;

    auto nsize = size();
    for (size_t i = 0; i < nsize; i++)
    {
        if (acedSSName(impObj()->data(), i, ename) == RTNORM) [[likely]] {
            if (acdbGetObjectId(objId.m_id, ename) == eOk) [[likely]] {
                idList.append(objId);
                }
            }
    }
    return idList;
}

boost::python::list PyEdSelectionSet::objectIdsOfType(const PyRxClass& _class)
{
    PyAutoLockGIL lock;
    if (!isInitialized())
        throw PyAcadErrorStatus(Acad::eNotInitializedYet);

    AcDbObjectId objId;
    ads_name ename = { 0 };

    boost::python::list idList;
    const auto _desc = _class.impObj();

    auto nsize = size();
    for (size_t i = 0; i < nsize; i++)
    {
        if (acedSSName(impObj()->data(), i, ename) == RTNORM)
        {
            if (acdbGetObjectId(objId, ename) == eOk)
            {
                if (objId.objectClass()->isDerivedFrom(_desc))
                    idList.append(PyDbObjectId{ objId });
            }
        }
    }
    return idList;
}

void PyEdSelectionSet::forceKeepAlive(bool keepIt)
{
    auto del_p = std::get_deleter<PyEdSSDeleter>(m_pSet);
    if (del_p == nullptr)
        PyThrowBadEs(Acad::eNotApplicable);
    del_p->m_autoDelete = !keepIt;
}

PySSName* PyEdSelectionSet::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pSet == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return m_pSet.get();
}

void PyEdSelectionSet::filliterator()
{
    if (!isInitialized())
        throw PyAcadErrorStatus(Acad::eNotInitializedYet);

    PyDbObjectId objId;
    ads_name ename = { 0 };

    auto nsize = size();
    m_iterable.reserve(nsize);

    for (size_t i = 0; i < nsize; i++)
    {
        if (acedSSName(impObj()->data(), i, ename) == RTNORM) [[likely]] {
            if (acdbGetObjectId(objId.m_id, ename) == eOk) [[likely]] {
                m_iterable.push_back(objId);
                }
            }
    }
}

std::vector<PyDbObjectId>::iterator PyEdSelectionSet::begin()
{
    return m_iterable.begin();
}

std::vector<PyDbObjectId>::iterator PyEdSelectionSet::end()
{
    filliterator();
    return m_iterable.end();
}
