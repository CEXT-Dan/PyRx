#include "stdafx.h"
#include "PyDbDimAssoc.h"
#include "PyDbObjectId.h"
#include "PyDbIdMapping.h"
#include "PyDbPointRef.h"

using namespace boost::python;

void makePyDbDimAssocWrapper()
{
    PyDocString DS("DimAssoc");
    class_<PyDbDimAssoc, bases<PyDbObject>>("DimAssoc")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>())
        .def("dimObjId", &PyDbDimAssoc::dimObjId)
        .def("setDimObjId", &PyDbDimAssoc::setDimObjId)
        .def("setAssocFlag", &PyDbDimAssoc::setAssocFlag1)
        .def("setAssocFlag", &PyDbDimAssoc::setAssocFlag2)
        .def("assocFlag", &PyDbDimAssoc::assocFlag1)
        .def("assocFlag", &PyDbDimAssoc::assocFlag2)
        .def("setPointRef", &PyDbDimAssoc::setPointRef)
        .def("pointRef", &PyDbDimAssoc::pointRef)
        .def("osnapPointRef", &PyDbDimAssoc::osnapPointRef)
        .def("setRotatedDimType", &PyDbDimAssoc::setRotatedDimType)
        .def("rotatedDimType", &PyDbDimAssoc::rotatedDimType)
        .def("addToPointRefReactor", &PyDbDimAssoc::addToPointRefReactor)
        .def("addToDimensionReactor", &PyDbDimAssoc::addToDimensionReactor1)
        .def("addToDimensionReactor", &PyDbDimAssoc::addToDimensionReactor2)
        .def("removePointRef", &PyDbDimAssoc::removePointRef)
        .def("updateDimension", &PyDbDimAssoc::updateDimension1)
        .def("updateDimension", &PyDbDimAssoc::updateDimension2)
        .def("updateDimension", &PyDbDimAssoc::updateDimension3)
        .def("removeAssociativity", &PyDbDimAssoc::removeAssociativity1)
        .def("removeAssociativity", &PyDbDimAssoc::removeAssociativity2)
        .def("isTransSpatial", &PyDbDimAssoc::isTransSpatial)
        .def("setTransSpatial", &PyDbDimAssoc::setTransSpatial)
        .def("startCmdWatcher", &PyDbDimAssoc::startCmdWatcher)
        .def("startOopsWatcher", &PyDbDimAssoc::startOopsWatcher1)
        .def("startOopsWatcher", &PyDbDimAssoc::startOopsWatcher2)
        .def("removeOopsWatcher", &PyDbDimAssoc::removeOopsWatcher)
        .def("restoreAssocFromOopsWatcher", &PyDbDimAssoc::restoreAssocFromOopsWatcher)
        .def("hasOopsWatcher", &PyDbDimAssoc::hasOopsWatcher)
        .def("post", &PyDbDimAssoc::post1)
        .def("post", &PyDbDimAssoc::post2)
        .def("getDimAssocGeomIds", &PyDbDimAssoc::getDimAssocGeomIds)
        .def("isAllGeomErased", &PyDbDimAssoc::isAllGeomErased)
        .def("swapReferences", &PyDbDimAssoc::swapReferences)
        .def("updateFillet", &PyDbDimAssoc::updateFillet)
        .def("updateAssociativity", &PyDbDimAssoc::updateAssociativity)
        .def("updateXrefSubentPath", &PyDbDimAssoc::updateXrefSubentPath)
        .def("updateSubentPath", &PyDbDimAssoc::updateSubentPath)
        .def("updateDueToMirror", &PyDbDimAssoc::updateDueToMirror)
        .def("className", &PyDbDimAssoc::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbDimAssoc::desc, DS.SARGS()).staticmethod("desc")
        .def("cloneFrom", &PyDbDimAssoc::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbDimAssoc::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}


PyDbDimAssoc::PyDbDimAssoc()
    : PyDbDimAssoc(new AcDbDimAssoc(), true)
{
}

PyDbDimAssoc::PyDbDimAssoc(const PyDbObjectId& id)
    : PyDbDimAssoc(openAcDbObject<AcDbDimAssoc>(id, AcDb::OpenMode::kForRead), false)
{
}

PyDbDimAssoc::PyDbDimAssoc(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbDimAssoc(openAcDbObject<AcDbDimAssoc>(id, mode), false)
{
}

PyDbDimAssoc::PyDbDimAssoc(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbDimAssoc(openAcDbObject<AcDbDimAssoc>(id, mode, erased), false)
{
}

PyDbDimAssoc::PyDbDimAssoc(AcDbDimAssoc* ptr, bool autoDelete)
    : PyDbObject(ptr, autoDelete)
{
}

PyDbObjectId PyDbDimAssoc::dimObjId() const
{
    return PyDbObjectId(impObj()->dimObjId());
}

void PyDbDimAssoc::setDimObjId(const PyDbObjectId& dimId)
{
    PyThrowBadEs(impObj()->setDimObjId(dimId.m_id));
}

void PyDbDimAssoc::setAssocFlag1(int ptType, bool value)
{
    PyThrowBadEs(impObj()->setAssocFlag(ptType, value));
}

void PyDbDimAssoc::setAssocFlag2(int assocFlg)
{
    impObj()->setAssocFlag(assocFlg);
}

bool PyDbDimAssoc::assocFlag2(int ptType) const
{
    return impObj()->assocFlag(ptType);
}

int PyDbDimAssoc::assocFlag1(void)
{
    return impObj()->assocFlag();
}

void PyDbDimAssoc::setPointRef(int ptType, PyDbPointRef& ptRef)
{
    PyThrowBadEs(impObj()->setPointRef(ptType, ptRef.impObj()));
    ptRef.forceKeepAlive(true);
}

PyDbPointRef PyDbDimAssoc::pointRef(int ptType) const
{
    return PyDbPointRef(impObj()->pointRef(ptType));
}

PyDbOsnapPointRef PyDbDimAssoc::osnapPointRef(int ptType) const
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    const AcDbPointRef* ref = impObj()->pointRef(ptType);
    if (ref == nullptr)
        throw PyNullObject();
    if (!ref->isKindOf(AcDbOsnapPointRef::desc()))
        PyThrowBadEs(eNotThatKindOfClass);
    return PyDbOsnapPointRef(static_cast<const AcDbOsnapPointRef*>(impObj()->pointRef(ptType)));
#endif
}

void PyDbDimAssoc::setRotatedDimType(AcDbDimAssoc::RotatedDimType dimType)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(impObj()->setRotatedDimType(dimType));
#endif
}

AcDbDimAssoc::RotatedDimType PyDbDimAssoc::rotatedDimType() const
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return impObj()->rotatedDimType();
#endif
}

void PyDbDimAssoc::addToPointRefReactor()
{
    PyThrowBadEs(impObj()->addToPointRefReactor());
}

void PyDbDimAssoc::addToDimensionReactor1()
{
    PyThrowBadEs(impObj()->addToDimensionReactor());
}

void PyDbDimAssoc::addToDimensionReactor2(bool isAdd)
{
    PyThrowBadEs(impObj()->addToDimensionReactor(isAdd));
}

void PyDbDimAssoc::removePointRef(int ptType)
{
    PyThrowBadEs(impObj()->removePointRef(ptType));
}

void PyDbDimAssoc::updateDimension1()
{
    PyThrowBadEs(impObj()->updateDimension());
}

void PyDbDimAssoc::updateDimension2(bool update)
{
    PyThrowBadEs(impObj()->updateDimension(update));
}

void PyDbDimAssoc::updateDimension3(bool update, bool skipReactors)
{
    PyThrowBadEs(impObj()->updateDimension(update, skipReactors));
}

void PyDbDimAssoc::removeAssociativity1()
{
    PyThrowBadEs(impObj()->removeAssociativity());
}

void PyDbDimAssoc::removeAssociativity2(bool force)
{
    PyThrowBadEs(impObj()->removeAssociativity(force));
}

bool PyDbDimAssoc::isTransSpatial() const
{
    return impObj()->isTransSpatial();
}

void PyDbDimAssoc::setTransSpatial(bool value)
{
    PyThrowBadEs(impObj()->setTransSpatial(value));
}

void PyDbDimAssoc::startCmdWatcher()
{
    PyThrowBadEs(impObj()->startCmdWatcher());
}

void PyDbDimAssoc::startOopsWatcher1()
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(impObj()->startOopsWatcher());
#endif
}

void PyDbDimAssoc::startOopsWatcher2(bool bAddAll)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(impObj()->startOopsWatcher(bAddAll));
#endif
}

void PyDbDimAssoc::removeOopsWatcher(void)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    impObj()->removeOopsWatcher();
#endif
}

void PyDbDimAssoc::restoreAssocFromOopsWatcher(void)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(impObj()->restoreAssocFromOopsWatcher());
#endif
}

bool PyDbDimAssoc::hasOopsWatcher(void) const
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return impObj()->hasOopsWatcher();
#endif
}

PyDbObjectId PyDbDimAssoc::post1(const PyDbObjectId& dimId)
{
    PyDbObjectId id;
    PyThrowBadEs(impObj()->post(dimId.m_id, id.m_id));
    return id;
}

PyDbObjectId PyDbDimAssoc::post2(const PyDbObjectId& dimId, bool isActive)
{
    PyDbObjectId id;
    PyThrowBadEs(impObj()->post(dimId.m_id, id.m_id, isActive));
    return id;
}

boost::python::list PyDbDimAssoc::getDimAssocGeomIds() const
{
    AcDbObjectIdArray geomIds;
    PyThrowBadEs(impObj()->getDimAssocGeomIds(geomIds));
    return ObjectIdArrayToPyList(geomIds);
}

bool PyDbDimAssoc::isAllGeomErased() const
{
    return impObj()->isAllGeomErased();
}

void PyDbDimAssoc::swapReferences(const PyDbIdMapping& idMap)
{
    PyThrowBadEs(impObj()->swapReferences(*idMap.impObj()));
}

void PyDbDimAssoc::updateFillet(const boost::python::list& ids)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(impObj()->updateFillet(PyListToObjectIdArray(ids)));
#endif
}

void PyDbDimAssoc::updateAssociativity(const boost::python::list& ids)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(impObj()->updateAssociativity(PyListToObjectIdArray(ids)));
#endif
}

void PyDbDimAssoc::updateXrefSubentPath()
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(impObj()->updateXrefSubentPath());
#endif
}

void PyDbDimAssoc::updateSubentPath(PyDbIdMapping& idMap)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(impObj()->updateSubentPath(*idMap.impObj()));
#endif
}

void PyDbDimAssoc::updateDueToMirror(bool wasInMirror)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    impObj()->updateDueToMirror(wasInMirror);
#endif
}

PyRxClass PyDbDimAssoc::desc()
{
    return PyRxClass(AcDbDimAssoc::desc(), false);
}

std::string PyDbDimAssoc::className()
{
    return "AcDbDimAssoc";
}

PyDbDimAssoc PyDbDimAssoc::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(AcDbDimAssoc::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbDimAssoc(static_cast<AcDbDimAssoc*>(src.impObj()->clone()), true);
}

PyDbDimAssoc PyDbDimAssoc::cast(const PyRxObject& src)
{
    PyDbDimAssoc dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

AcDbDimAssoc* PyDbDimAssoc::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbDimAssoc*>(m_pyImp.get());
}
