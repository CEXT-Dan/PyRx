#include "stdafx.h"
#include "PyEdSelectionSet.h"
#include "ResultBuffer.h"
#include "PyRxObject.h"

using namespace boost::python;

void makePyEdSelectionSetWrapper()
{
    constexpr const std::string_view objectIdsOverloads = "Overloads:\n"
        "desc: PyRx.RxClass=PyDb.Entity\n"
        "descList: list[PyRx.RxClass]\n";

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
        .def("objectIds", &PyEdSelectionSet::objectIdsOfType)
        .def("objectIds", &PyEdSelectionSet::objectIdsOfTypeList, DS.OVRL(objectIdsOverloads))
        .def("objectIdArray", &PyEdSelectionSet::objectIdArray1)
        .def("objectIdArray", &PyEdSelectionSet::objectIdArray2)
        .def("objectIdArray", &PyEdSelectionSet::objectIdArray3, DS.OVRL(objectIdsOverloads))
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
    if (m_pSet == nullptr)
        return false;
    return (m_pSet->at(0) + m_pSet->at(1)) != 0;
}

size_t PyEdSelectionSet::size() const
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

void PyEdSelectionSet::add(const PyDbObjectId& objId) const
{
    if (!isInitialized())
        throw PyErrorStatusException(Acad::eNotInitializedYet);
    ads_name ent = { 0 };
    PyThrowBadEs(acdbGetAdsName(ent, objId.m_id));
    PyThrowBadRt(acedSSAdd(ent, impObj()->data(), impObj()->data()));
}

void PyEdSelectionSet::remove(const PyDbObjectId& objId) const
{
    if (!isInitialized())
        throw PyErrorStatusException(Acad::eNotInitializedYet);
    ads_name ent = { 0 };
    PyThrowBadEs(acdbGetAdsName(ent, objId.m_id));
    PyThrowBadRt(acedSSDel(ent, impObj()->data()));
}

bool PyEdSelectionSet::hasMember(const PyDbObjectId& objId) const
{
    if (!isInitialized())
        throw PyErrorStatusException(Acad::eNotInitializedYet);
    ads_name ent = { 0 };
    PyThrowBadEs(acdbGetAdsName(ent, objId.m_id));
    return acedSSMemb(ent, impObj()->data()) == RTNORM;
}

AdsName PyEdSelectionSet::adsname() const
{
    if (!isInitialized())
        throw PyErrorStatusException(Acad::eNotInitializedYet);
    AdsName _name = { 0L };
    memcpy(&_name, m_pSet->data(), sizeof(_name));
    return _name;
}

bool PyEdSelectionSet::ssSetFirst() const
{
    if (!isInitialized())
        throw PyErrorStatusException(Acad::eNotInitializedYet);
    ads_name dummy = { 0 };
    return acedSSSetFirst(m_pSet->data(), dummy) == RTNORM;
}

Acad::PromptStatus PyEdSelectionSet::ssXform(const AcGeMatrix3d& xform) const
{
    if (!isInitialized())
        throw PyErrorStatusException(Acad::eNotInitializedYet);
    ads_matrix adsXform;
    memcpy(adsXform, xform.entry, sizeof(ads_matrix));
    return static_cast<Acad::PromptStatus>(acedXformSS(m_pSet->data(), adsXform));
}

boost::python::list PyEdSelectionSet::ssNameX1() const
{
    return ssNameX2(0);
}

boost::python::list PyEdSelectionSet::ssNameX2(int idx) const
{
    if (!isInitialized())
        throw PyErrorStatusException(Acad::eNotInitializedYet);
    resbuf* rb = nullptr;
    PyThrowBadRt(acedSSNameX(&rb, m_pSet->data(), idx));
    AcResBufPtr ptr(rb);
    return resbufToList(rb);
}

boost::python::list PyEdSelectionSet::objectIds() const
{
    PyAutoLockGIL lock;
    if (!isInitialized())
        throw PyErrorStatusException(Acad::eNotInitializedYet);
    return ObjectIdArrayToPyList(objectIdsImpl());
}

boost::python::list PyEdSelectionSet::objectIdsOfType(const PyRxClass& _class) const
{
    PyAutoLockGIL lock;
    if (!isInitialized())
        throw PyErrorStatusException(Acad::eNotInitializedYet);
    boost::python::list idList;
    const auto _desc = _class.impObj();
    for (const auto& id : objectIdsImpl())
    {
        if (id.objectClass()->isDerivedFrom(_desc))
            idList.append(PyDbObjectId{ id });
    }
    return idList;
}

boost::python::list PyEdSelectionSet::objectIdsOfTypeList(const boost::python::list& _classes) const
{
    PyAutoLockGIL lock;
    if (!isInitialized())
        throw PyErrorStatusException(Acad::eNotInitializedYet);
    boost::python::list idList;
    std::unordered_set<AcRxClass*> _set;
    for (auto& item : py_list_to_std_vector<PyRxClass>(_classes))
        _set.insert(item.impObj());
    for (const auto& id : objectIdsImpl())
    {
        if (_set.contains(id.objectClass()))
            idList.append(PyDbObjectId{ id });
    }
    return idList;
}

PyDbObjectIdArray PyEdSelectionSet::objectIdArray1() const
{
    const auto& m_ids = objectIdsImpl();
    PyDbObjectIdArray ids;
    ids.reserve(m_ids.length());
    for (const auto& id : objectIdsImpl())
        ids.push_back(PyDbObjectId{ id });
    return ids;
}

PyDbObjectIdArray PyEdSelectionSet::objectIdArray2(const PyRxClass& _class) const
{
    if (!isInitialized())
        throw PyErrorStatusException(Acad::eNotInitializedYet);
    PyDbObjectIdArray idList;
    const auto _desc = _class.impObj();
    for (const auto& id : objectIdsImpl())
    {
        if (id.objectClass()->isDerivedFrom(_desc))
            idList.push_back(PyDbObjectId{ id });
    }
    return idList;
}

PyDbObjectIdArray PyEdSelectionSet::objectIdArray3(const boost::python::list& _classes) const
{
    if (!isInitialized())
        throw PyErrorStatusException(Acad::eNotInitializedYet);
    PyDbObjectIdArray idList;
    std::unordered_set<AcRxClass*> _set;
    for (auto& item : py_list_to_std_vector<PyRxClass>(_classes))
        _set.insert(item.impObj());
    for (const auto& id : objectIdsImpl())
    {
        if (_set.contains(id.objectClass()))
            idList.push_back(PyDbObjectId{ id });
    }
    return idList;
}

void PyEdSelectionSet::forceKeepAlive(bool keepIt) const
{
    auto del_p = std::get_deleter<PyEdSSDeleter>(m_pSet);
    if (del_p == nullptr)
        PyThrowBadEs(Acad::eNotApplicable);
    del_p->m_autoDelete = !keepIt;
}

AcDbObjectIdArray PyEdSelectionSet::objectIdsImpl() const
{
    AcDbObjectId id;
    ads_name ename = { 0 };
    const auto nsize = size();
    AcDbObjectIdArray idList;
    idList.setPhysicalLength(nsize);
    for (size_t i = 0; i < nsize; i++)
    {
        if (acedSSName(impObj()->data(), i, ename) == RTNORM) [[likely]]
        {
            if (acdbGetObjectId(id, ename) == eOk) [[likely]]
                idList.append(id);
        }
    }
    return idList;
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
        throw PyErrorStatusException(Acad::eNotInitializedYet);
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
