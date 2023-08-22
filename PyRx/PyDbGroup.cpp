#include "stdafx.h"
#include "PyDbGroup.h"
#include "PyDbObjectId.h"

using namespace boost::python;

void makePyDbGroupWrapper()
{
    PyDocString DS("Group");
    class_<PyDbGroup, bases<PyDbObject>>("Group")
        .def(init<>())
        .def(init<const std::string&>())
        .def(init<const std::string&, bool>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        
        .def("desc", &PyDbGroup::desc, DS.SARGS()).staticmethod("desc")
        .def("className", &PyDbGroup::className, DS.SARGS()).staticmethod("className")
        .def("cloneFrom", &PyDbGroup::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbGroup::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyDbGroup::PyDbGroup()
    : PyDbGroup(new AcDbGroup(),true)
{
}

PyDbGroup::PyDbGroup(const std::string& grpDesc)
    : PyDbGroup(new AcDbGroup(utf8_to_wstr(grpDesc).c_str()), true)
{
}

PyDbGroup::PyDbGroup(const std::string& grpDesc, bool selectable)
    : PyDbGroup(new AcDbGroup(utf8_to_wstr(grpDesc).c_str(), selectable), true)
{
}

PyDbGroup::PyDbGroup(AcDbGroup* ptr, bool autoDelete)
    : PyDbObject(ptr, autoDelete)
{
}

PyDbGroup::PyDbGroup(const PyDbObjectId& id)
    : PyDbGroup(id, AcDb::OpenMode::kForRead)
{
}

PyDbGroup::PyDbGroup(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbGroup(openAcDbObject<AcDbGroup>(id, mode), false)
{
}

boost::python::list PyDbGroup::objectIds() const
{
    PyAutoLockGIL lock;
    boost::python::list pyList;
    for (std::unique_ptr<AcDbGroupIterator> iter(impObj()->newIterator()); !iter->done(); iter->next())
        pyList(PyDbObjectId(iter->objectId()));
    return pyList;
}

std::string PyDbGroup::description() const
{
    return wstr_to_utf8(impObj()->description());
}

void PyDbGroup::setDescription(const std::string& grpDesc)
{
    PyThrowBadEs(impObj()->setDescription(utf8_to_wstr(grpDesc).c_str()));
}

bool PyDbGroup::isSelectable() const
{
    return impObj()->isSelectable();
}

void PyDbGroup::setSelectable(bool selectable)
{
    PyThrowBadEs(impObj()->setSelectable(selectable));
}

std::string PyDbGroup::getName() const
{
    RxAutoOutStr str;
    PyThrowBadEs(impObj()->getName(str.buf));
    return wstr_to_utf8(str.buf);
}

void PyDbGroup::setName(const std::string& name)
{
    PyThrowBadEs(impObj()->setName(utf8_to_wstr(name).c_str()));
}

bool PyDbGroup::isNotAccessible() const
{
    return impObj()->isNotAccessible();
}

bool PyDbGroup::isAnonymous() const
{
    return impObj()->isAnonymous();
}

void PyDbGroup::setAnonymous()
{
    PyThrowBadEs(impObj()->setAnonymous());
}

void PyDbGroup::append1(const PyDbObjectId& id)
{
    PyThrowBadEs(impObj()->append(id.m_id));
}

void PyDbGroup::append2(const boost::python::list& ids)
{
    PyThrowBadEs(impObj()->append(PyListToObjectIdArray(ids)));
}

void PyDbGroup::prepend1(const PyDbObjectId& id)
{
    PyThrowBadEs(impObj()->prepend(id.m_id));
}

void PyDbGroup::prepend2(const boost::python::list& ids)
{
    PyThrowBadEs(impObj()->prepend(PyListToObjectIdArray(ids)));
}

void PyDbGroup::insertAt1(Adesk::UInt32 idx, const PyDbObjectId& id)
{
    PyThrowBadEs(impObj()->insertAt(idx, id.m_id));
}

void PyDbGroup::insertAt2(Adesk::UInt32 idx, const boost::python::list& ids)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(impObj()->insertAt(idx, PyListToObjectIdArray(ids)));
#endif
}

void PyDbGroup::remove1(const PyDbObjectId& id)
{
    PyThrowBadEs(impObj()->remove(id.m_id));
}

void PyDbGroup::remove2(const boost::python::list& ids)
{
    PyThrowBadEs(impObj()->remove(PyListToObjectIdArray(ids)));
}

void PyDbGroup::removeAt1(Adesk::UInt32 idx)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(impObj()->removeAt(idx));
#endif
}

void PyDbGroup::removeAt2(Adesk::UInt32 idx, const boost::python::list& ids)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(impObj()->removeAt(idx, PyListToObjectIdArray(ids)));
#endif
}

void PyDbGroup::replace(const AcDbObjectId& oldId, const AcDbObjectId& newId)
{
    PyThrowBadEs(impObj()->replace(oldId, newId));
}

void PyDbGroup::transfer(Adesk::UInt32 fromIndex, Adesk::UInt32 toIndex, Adesk::UInt32 numItems)
{
    PyThrowBadEs(impObj()->transfer(fromIndex, toIndex, numItems));
}

PyRxClass PyDbGroup::desc()
{
    return PyRxClass(AcDbGroup::desc(), false);
}

std::string PyDbGroup::className()
{
    return "AcDbGroup";
}

PyDbGroup PyDbGroup::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(AcDbGroup::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbGroup(static_cast<AcDbGroup*>(src.impObj()->clone()), true);
}

PyDbGroup PyDbGroup::cast(const PyRxObject& src)
{
    PyDbGroup dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

AcDbGroup* PyDbGroup::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]]
        throw PyNullObject(src);
        return static_cast<AcDbGroup*>(m_pyImp.get());
}
