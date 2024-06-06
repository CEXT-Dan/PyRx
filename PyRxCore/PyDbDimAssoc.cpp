#include "stdafx.h"
#include "PyDbDimAssoc.h"
#include "PyDbObjectId.h"
#include "PyDbIdMapping.h"
#include "PyDbPointRef.h"

using namespace boost::python;

void makePyDbDimAssocWrapper()
{
    constexpr const std::string_view assocFlagOverload = "Overloads:\n"
        "- None: Any\n"
        "- ptType: int\n";

    constexpr const std::string_view setAssocFlagOverload = "Overloads:\n"
        "- flag: int\n"
        "- flag: int, val: bool\n";

    PyDocString DS("PyDb.DimAssoc");
    class_<PyDbDimAssoc, bases<PyDbObject>>("DimAssoc")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.ARGS({ "id: PyDb.ObjectId", "mode: PyDb.OpenMode.kForRead", "erased: bool=False" })))
        .def("dimObjId", &PyDbDimAssoc::dimObjId, DS.ARGS())
        .def("setDimObjId", &PyDbDimAssoc::setDimObjId, DS.ARGS({ "id : PyDb.ObjectId" }))
        .def("setAssocFlag", &PyDbDimAssoc::setAssocFlag1)
        .def("setAssocFlag", &PyDbDimAssoc::setAssocFlag2, DS.OVRL(setAssocFlagOverload))
        .def("assocFlag", &PyDbDimAssoc::assocFlag1)
        .def("assocFlag", &PyDbDimAssoc::assocFlag2, DS.OVRL(assocFlagOverload))
        .def("setPointRef", &PyDbDimAssoc::setPointRef, DS.ARGS({ "_type : int", "ptRef : PyDb.PointRef" }))
        .def("pointRef", &PyDbDimAssoc::pointRef, DS.ARGS({ "_type : int" }))
        .def("osnapPointRef", &PyDbDimAssoc::osnapPointRef, DS.ARGS({ "_type : int" }))
        .def("setRotatedDimType", &PyDbDimAssoc::setRotatedDimType, DS.ARGS({ "dimType : PyDb.RotatedDimType" }))
        .def("rotatedDimType", &PyDbDimAssoc::rotatedDimType, DS.ARGS())
        .def("addToPointRefReactor", &PyDbDimAssoc::addToPointRefReactor, DS.ARGS())
        .def("addToDimensionReactor", &PyDbDimAssoc::addToDimensionReactor1)
        .def("addToDimensionReactor", &PyDbDimAssoc::addToDimensionReactor2, DS.ARGS({ "add : bool=True" }))
        .def("removePointRef", &PyDbDimAssoc::removePointRef, DS.ARGS({ "_type : int" }))
        .def("updateDimension", &PyDbDimAssoc::updateDimension1)
        .def("updateDimension", &PyDbDimAssoc::updateDimension2)
        .def("updateDimension", &PyDbDimAssoc::updateDimension3, DS.ARGS({ "update : bool=True", "skipReactors : bool=False" }))
        .def("removeAssociativity", &PyDbDimAssoc::removeAssociativity1)
        .def("removeAssociativity", &PyDbDimAssoc::removeAssociativity2, DS.ARGS({ "force : bool=True" }))
        .def("isTransSpatial", &PyDbDimAssoc::isTransSpatial, DS.ARGS())
        .def("setTransSpatial", &PyDbDimAssoc::setTransSpatial, DS.ARGS({ "val : bool" }))
        .def("startCmdWatcher", &PyDbDimAssoc::startCmdWatcher, DS.ARGS())
        .def("startOopsWatcher", &PyDbDimAssoc::startOopsWatcher1)
        .def("startOopsWatcher", &PyDbDimAssoc::startOopsWatcher2, DS.ARGS({ "val : bool=True" }))
        .def("removeOopsWatcher", &PyDbDimAssoc::removeOopsWatcher, DS.ARGS())
        .def("restoreAssocFromOopsWatcher", &PyDbDimAssoc::restoreAssocFromOopsWatcher, DS.ARGS())
        .def("hasOopsWatcher", &PyDbDimAssoc::hasOopsWatcher, DS.ARGS())
        .def("post", &PyDbDimAssoc::post1)
        .def("post", &PyDbDimAssoc::post2, DS.ARGS({ "id : PyDb.ObjectId","isAcive : bool=True" }))
        .def("getDimAssocGeomIds", &PyDbDimAssoc::getDimAssocGeomIds, DS.ARGS())
        .def("isAllGeomErased", &PyDbDimAssoc::isAllGeomErased, DS.ARGS())
        .def("swapReferences", &PyDbDimAssoc::swapReferences, DS.ARGS({ "val : PyDb.IdMapping" }))
        .def("updateFillet", &PyDbDimAssoc::updateFillet, DS.ARGS({ "ids : list[PyDb.ObjectId]" }))
        .def("updateAssociativity", &PyDbDimAssoc::updateAssociativity, DS.ARGS({ "ids : list[PyDb.ObjectId]" }))
        .def("updateXrefSubentPath", &PyDbDimAssoc::updateXrefSubentPath, DS.ARGS())
        .def("updateSubentPath", &PyDbDimAssoc::updateSubentPath, DS.ARGS({ "val : PyDb.IdMapping" }))
        .def("updateDueToMirror", &PyDbDimAssoc::updateDueToMirror, DS.ARGS({ "val : bool" }))
        .def("className", &PyDbDimAssoc::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbDimAssoc::desc, DS.SARGS(15560)).staticmethod("desc")
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
    return PyDbObjectCloneFrom<PyDbDimAssoc, AcDbDimAssoc>(src);
}

PyDbDimAssoc PyDbDimAssoc::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbDimAssoc>(src);
}

AcDbDimAssoc* PyDbDimAssoc::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<AcDbDimAssoc*>(m_pyImp.get());
}
