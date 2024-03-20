#include "stdafx.h"
#include "PyDbGroup.h"
#include "PyDbObjectId.h"
#include "PyDbEntity.h"

using namespace boost::python;

void makePyDbGroupWrapper()
{
    constexpr const std::string_view ctords = "Overloads:\n"
        "- None: Any\n"
        "- grpDesc: str\n"
        "- grpDesc: str, selectable: bool\n"
        "- id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode, erased: bool\n";

    PyDocString DS("PyDb.Group");
    class_<PyDbGroup, bases<PyDbObject>>("Group")
        .def(init<>())
        .def(init<const std::string&>())
        .def(init<const std::string&, bool>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode,bool>(DS.CTOR(ctords)))
        .def("objectIds", &PyDbGroup::objectIds, DS.ARGS())
        .def("description", &PyDbGroup::description, DS.ARGS())
        .def("setDescription", &PyDbGroup::setDescription, DS.ARGS({ "grpDesc : str" }))
        .def("isSelectable", &PyDbGroup::isSelectable, DS.ARGS())
        .def("setSelectable", &PyDbGroup::setSelectable, DS.ARGS({ "val : bool" }))
        .def("getName", &PyDbGroup::getName, DS.ARGS())
        .def("setName", &PyDbGroup::setName, DS.ARGS({ "val : str" }))
        .def("isNotAccessible", &PyDbGroup::isNotAccessible, DS.ARGS())
        .def("isAnonymous", &PyDbGroup::isAnonymous, DS.ARGS())
        .def("setAnonymous", &PyDbGroup::setAnonymous, DS.ARGS())
        .def("append", &PyDbGroup::append1)
        .def("append", &PyDbGroup::append2, DS.ARGS({ "id : PyDb.ObjectId|list[PyDb.ObjectId]" }))
        .def("prepend", &PyDbGroup::prepend1)
        .def("prepend", &PyDbGroup::prepend2, DS.ARGS({ "id : PyDb.ObjectId|list[PyDb.ObjectId]" }))
        .def("insertAt", &PyDbGroup::insertAt1)
        .def("insertAt", &PyDbGroup::insertAt2, DS.ARGS({ "index : int","id: PyDb.ObjectId|list[PyDb.ObjectId]" }))
        .def("remove", &PyDbGroup::remove1)
        .def("remove", &PyDbGroup::remove2, DS.ARGS({ "id : PyDb.ObjectId|list[PyDb.ObjectId]" }))
        .def("removeAt", &PyDbGroup::removeAt1)
        .def("removeAt", &PyDbGroup::removeAt2, DS.ARGS({ "index : int","id: PyDb.ObjectId|list[PyDb.ObjectId]" }))
        .def("replace", &PyDbGroup::replace, DS.ARGS({ "oldid: PyDb.ObjectId","newid: PyDb.ObjectId" }))
        .def("transfer", &PyDbGroup::transfer, DS.ARGS({ "fromIndex: int" ,"valtoIndex: int" ,"numItems: int" }))
        .def("clear", &PyDbGroup::clear, DS.ARGS())
        .def("numEntities", &PyDbGroup::numEntities, DS.ARGS())
        .def("has", &PyDbGroup::has, DS.ARGS({ "entity: PyDb.Entity" }))
        .def("allEntityIds", &PyDbGroup::allEntityIds, DS.ARGS())
        .def("getIndex", &PyDbGroup::getIndex, DS.ARGS({ "id: PyDb.ObjectId" }))
        .def("reverse", &PyDbGroup::reverse, DS.ARGS())
        .def("setColor", &PyDbGroup::setColor, DS.ARGS({ "clr: PyDb.AcCmColor" }))
        .def("setColorIndex", &PyDbGroup::setColorIndex, DS.ARGS({ "clr: int" }))
        .def("setLayer", &PyDbGroup::setLayer1)
        .def("setLayer", &PyDbGroup::setLayer2, DS.ARGS({ "id: str|PyDb.ObjectId" }))
        .def("setLinetype", &PyDbGroup::setLinetype1)
        .def("setLinetype", &PyDbGroup::setLinetype2, DS.ARGS({ "id: str|PyDb.ObjectId" }))
        .def("setLinetypeScale", &PyDbGroup::setLinetypeScale, DS.ARGS({ "val: float" }))
        .def("setVisibility", &PyDbGroup::setVisibility, DS.ARGS({ "val: PyDb.Visibility" }))
        .def("setHighlight", &PyDbGroup::setHighlight, DS.ARGS({ "val: bool" }))
        .def("setMaterial", &PyDbGroup::setMaterial1)
        .def("setMaterial", &PyDbGroup::setMaterial2, DS.ARGS({ "id: str|PyDb.ObjectId" }))
        .def("desc", &PyDbGroup::desc, DS.SARGS()).staticmethod("desc")
        .def("className", &PyDbGroup::className, DS.SARGS()).staticmethod("className")
        .def("cloneFrom", &PyDbGroup::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbGroup::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyDbGroup::PyDbGroup()
    : PyDbGroup(new AcDbGroup(), true)
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

PyDbGroup::PyDbGroup(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbGroup(openAcDbObject<AcDbGroup>(id, mode, erased), false)
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
#if defined(_BRXTARGET) && _BRXTARGET <= 240
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
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(impObj()->removeAt(idx));
#endif
}

void PyDbGroup::removeAt2(Adesk::UInt32 idx, const boost::python::list& ids)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
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

void PyDbGroup::clear()
{
    PyThrowBadEs(impObj()->clear());
}

Adesk::UInt32 PyDbGroup::numEntities() const
{
    return impObj()->numEntities();
}

bool PyDbGroup::has(const PyDbEntity& pEntity) const
{
    return impObj()->has(pEntity.impObj());
}

boost::python::list PyDbGroup::allEntityIds() const
{
    AcDbObjectIdArray ids;
    impObj()->allEntityIds(ids);
    return ObjectIdArrayToPyList(ids);
}

Adesk::UInt32 PyDbGroup::getIndex(const PyDbObjectId& id) const
{
    Adesk::UInt32 idx;
    PyThrowBadEs(impObj()->getIndex(id.m_id, idx));
    return idx;
}

void PyDbGroup::reverse()
{
    PyThrowBadEs(impObj()->reverse());
}

void PyDbGroup::setColor(const AcCmColor& color)
{
    PyThrowBadEs(impObj()->setColor(color));
}

void PyDbGroup::setColorIndex(Adesk::UInt16 color)
{
    PyThrowBadEs(impObj()->setColorIndex(color));
}

void PyDbGroup::setLayer1(const std::string& newVal)
{
    PyThrowBadEs(impObj()->setLayer(utf8_to_wstr(newVal).c_str()));
}

void PyDbGroup::setLayer2(const PyDbObjectId& newVal)
{
    PyThrowBadEs(impObj()->setLayer(newVal.m_id));
}

void PyDbGroup::setLinetype1(const std::string& newVal)
{
    PyThrowBadEs(impObj()->setLinetype(utf8_to_wstr(newVal).c_str()));
}

void PyDbGroup::setLinetype2(const PyDbObjectId& newVal)
{
    PyThrowBadEs(impObj()->setLinetype(newVal.m_id));
}

void PyDbGroup::setLinetypeScale(double newval)
{
    PyThrowBadEs(impObj()->setLinetypeScale(newval));
}

void PyDbGroup::setVisibility(AcDb::Visibility newVal)
{
    PyThrowBadEs(impObj()->setVisibility(newVal));
}

void PyDbGroup::setHighlight(bool newVal)
{
    PyThrowBadEs(impObj()->setHighlight(newVal));
}

void PyDbGroup::setMaterial1(const std::string& newVal)
{
    PyThrowBadEs(impObj()->setMaterial(utf8_to_wstr(newVal).c_str()));
}

void PyDbGroup::setMaterial2(const PyDbObjectId& newVal)
{
    PyThrowBadEs(impObj()->setMaterial(newVal.m_id));
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
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbGroup*>(m_pyImp.get());
}
