#include "stdafx.h"
#include "PyDbOverrule.h"
#include "PyDbObjectId.h"
#include "PyDbDimension.h"
#include "PyDbSymbolTableRecord.h"
#include "PyDbIdMapping.h"
#include "PyDbEntity.h"

using namespace boost::python;

static std::mutex PyDbObjectOverruleMutex;
void makePyDbObjectOverruleWrapper()
{
    PyDocString DS("DbObjectOverrule");
    class_<PyDbObjectOverrule, bases<PyRxOverrule>, boost::noncopyable>("DbObjectOverrule")
        .def(init<>(DS.ARGS(7101)))
        .def("isApplicable", &PyDbObjectOverrule::isApplicableWr, DS.ARGS({ "object: PyRx.RxObject" }))
        .def("open", &PyDbObjectOverrule::openWr, DS.ARGS({ "object: PyDb.DbObject","mode: OpenMode" }))
        .def("close", &PyDbObjectOverrule::closeWr, DS.ARGS({ "object: PyDb.DbObject" }))
        .def("cancel", &PyDbObjectOverrule::cancelWr, DS.ARGS({ "object: PyDb.DbObject" }))
        .def("erase", &PyDbObjectOverrule::eraseWr, DS.ARGS({ "object: PyDb.DbObject","erased : bool" }))
        .def("deepClone", &PyDbObjectOverrule::baseDeepClone, DS.ARGS({ "subject: PyDb.DbObject","owner: PyDb.DbObject","mapping: PyDb.IdMapping","isPrimary : bool" }))
        .def("wblockClone", &PyDbObjectOverrule::baseWblockClone, DS.ARGS({ "subject: PyDb.DbObject","owner: PyRx.RxObject","mapping: PyDb.IdMapping","isPrimary : bool" }))
        .def("baseOpen", &PyDbObjectOverrule::baseOpen, DS.ARGS({ "object: PyDb.DbObject","mode: OpenMode" }))
        .def("baseClose", &PyDbObjectOverrule::baseClose, DS.ARGS({ "object: PyDb.DbObject" }))
        .def("baseCancel", &PyDbObjectOverrule::baseCancel, DS.ARGS({ "object: PyDb.DbObject" }))
        .def("baseErase", &PyDbObjectOverrule::baseErase, DS.ARGS({ "object: PyDb.DbObject","erased : bool" }))
        .def("baseDeepClone", &PyDbObjectOverrule::baseDeepClone, DS.ARGS({ "subject: PyDb.DbObject","owner: PyDb.DbObject","mapping: PyDb.IdMapping","isPrimary : bool" }))
        .def("baseWblockClone", &PyDbObjectOverrule::baseWblockClone, DS.ARGS({ "subject: PyDb.DbObject","owner: PyRx.RxObject","mapping: PyDb.IdMapping","isPrimary : bool" }))
        .def("className", &PyDbObjectOverrule::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbObjectOverrule::desc, DS.SARGS(15560)).staticmethod("desc")
        ;
}

PyDbObjectOverrule::PyDbObjectOverrule()
    : PyRxOverrule(this)
{
}

bool PyDbObjectOverrule::isApplicable(const AcRxObject* pOverruledSubject) const
{
#ifdef BRXAPP
    std::lock_guard<std::mutex> lk(PyDbObjectOverruleMutex);
#endif // BRXAPP
    if (!reg_isApplicable)
        return false;
    PyRxObject obj(pOverruledSubject);
    return this->isApplicableWr(obj);
}

Acad::ErrorStatus PyDbObjectOverrule::open(AcDbObject* pSubject, AcDb::OpenMode mode)
{
    if (!reg_open)
        return AcDbObjectOverrule::open(pSubject, mode);
    PyDbObject obj(pSubject, false);
    obj.forceKeepAlive(true);
    return this->openWr(obj, mode);
}

Acad::ErrorStatus PyDbObjectOverrule::close(AcDbObject* pSubject)
{
    if (!reg_close)
        return AcDbObjectOverrule::close(pSubject);
    PyDbObject obj(pSubject, false);
    obj.forceKeepAlive(true);
    return this->closeWr(obj);
}

Acad::ErrorStatus PyDbObjectOverrule::cancel(AcDbObject* pSubject)
{
    if (!reg_cancel)
        return AcDbObjectOverrule::cancel(pSubject);
    PyDbObject obj(pSubject, false);
    obj.forceKeepAlive(true);
    return this->cancelWr(obj);
}

Acad::ErrorStatus PyDbObjectOverrule::erase(AcDbObject* pSubject, Adesk::Boolean erasing)
{
    if (!reg_erase)
        return AcDbObjectOverrule::erase(pSubject, erasing);
    PyDbObject obj(pSubject, false);
    obj.forceKeepAlive(true);
    return this->eraseWr(obj, erasing);
}

Acad::ErrorStatus PyDbObjectOverrule::deepClone(const AcDbObject* pSubject, AcDbObject* pOwnerObject, AcDbObject*& pClonedObject, AcDbIdMapping& idMap, Adesk::Boolean isPrimary)
{
    if (!reg_deepClone)
        return AcDbObjectOverrule::deepClone(pSubject, pOwnerObject, pClonedObject, idMap, isPrimary);
    auto es = deepCloneWr(pSubject, pOwnerObject, pClonedObject, idMap, isPrimary);
    if (es == eNotImplemented)
        return AcDbObjectOverrule::deepClone(pSubject, pOwnerObject, pClonedObject, idMap, isPrimary);;
    return es;
}

Acad::ErrorStatus PyDbObjectOverrule::wblockClone(const AcDbObject* pSubject, AcRxObject* pOwnerObject, AcDbObject*& pClonedObject, AcDbIdMapping& idMap, Adesk::Boolean isPrimary)
{
    if (!reg_deepClone)
        return AcDbObjectOverrule::wblockClone(pSubject, pOwnerObject, pClonedObject, idMap, isPrimary);
    auto es = wblockCloneWr(pSubject, pOwnerObject, pClonedObject, idMap, isPrimary);
    if (es == eNotImplemented)
        return AcDbObjectOverrule::wblockClone(pSubject, pOwnerObject, pClonedObject, idMap, isPrimary);
    return es;
}

bool PyDbObjectOverrule::isApplicableWr(const PyRxObject& pOverruledSubject) const
{
    PyAutoLockGIL lock;
    try
    {
        if (const override& f = get_override("isApplicable"))
            return f(pOverruledSubject);
        reg_isApplicable = false;
        return false;
    }
    catch (...)
    {
        printExceptionMsg();
        reg_isApplicable = false;
    }
    return false;
}

Acad::ErrorStatus PyDbObjectOverrule::openWr(PyDbObject& pSubject, AcDb::OpenMode mode)
{
    PyAutoLockGIL lock;
    try
    {
        if (const override& f = get_override("open"))
            return f(pSubject, mode);
        reg_open = false;
        return baseOpen(pSubject, mode);
    }
    catch (...)
    {
        printExceptionMsg();
        reg_open = false;
    }
    return eInvalidInput;
}

Acad::ErrorStatus PyDbObjectOverrule::closeWr(PyDbObject& pSubject)
{
    PyAutoLockGIL lock;
    try
    {
        if (const override& f = get_override("close"))
            return f(pSubject);
        reg_close = false;
        return baseClose(pSubject);
    }
    catch (...)
    {
        printExceptionMsg();
        reg_close = false;
    }
    return eInvalidInput;
}

Acad::ErrorStatus PyDbObjectOverrule::cancelWr(PyDbObject& pSubject)
{
    PyAutoLockGIL lock;
    try
    {
        if (const override& f = get_override("cancel"))
            return f(pSubject);
        reg_cancel = false;
        return baseCancel(pSubject);
    }
    catch (...)
    {
        printExceptionMsg();
        reg_cancel = false;
    }
    return eInvalidInput;
}

Acad::ErrorStatus PyDbObjectOverrule::eraseWr(PyDbObject& pSubject, Adesk::Boolean erasing)
{
    PyAutoLockGIL lock;
    try
    {
        if (const override& f = get_override("erase"))
            return f(pSubject, erasing);
        reg_erase = false;
        return baseErase(pSubject, erasing);
    }
    catch (...)
    {
        printExceptionMsg();
        reg_erase = false;
    }
    return eInvalidInput;
}

Acad::ErrorStatus PyDbObjectOverrule::deepCloneWr(const AcDbObject* pSubject, AcDbObject* pOwnerObject, AcDbObject*& pClonedObject, AcDbIdMapping& idMap, Adesk::Boolean isPrimary)
{
    PyAutoLockGIL lock;
    try
    {
        PyDbObject pySubject(const_cast<AcDbObject*>(pSubject), false);
        pySubject.forceKeepAlive(true);
        PyDbObject pyOwnerObject(const_cast<AcDbObject*>(pOwnerObject), false);
        pyOwnerObject.forceKeepAlive(true);
        PyDbIdMapping pyMapping(idMap, true);

        if (const override& f = get_override("deepClone"))
        {
            PyDbObject result = f(pySubject, pyOwnerObject, pyMapping, isPrimary);
            if (result.isNullObj())
                return eNotApplicable;
            pClonedObject = result.impObj();
            return eOk;
        }
        reg_deepClone = false;
        return eNotImplemented;
    }
    catch (...)
    {
        printExceptionMsg();
        reg_deepClone = false;
    }
    return eInvalidInput;
}

Acad::ErrorStatus PyDbObjectOverrule::wblockCloneWr(const AcDbObject* pSubject, AcRxObject* pOwnerObject, AcDbObject*& pClonedObject, AcDbIdMapping& idMap, Adesk::Boolean isPrimary)
{
    PyAutoLockGIL lock;
    try
    {
        PyDbObject pySubject(const_cast<AcDbObject*>(pSubject), false);
        pySubject.forceKeepAlive(true);
        PyRxObject pyOwnerObject(pOwnerObject, false, false);
        pyOwnerObject.forceKeepAlive(true);
        PyDbIdMapping pyMapping(idMap, true);

        if (const override& f = get_override("wblockClone"))
        {
            PyDbObject result = f(pySubject, pyOwnerObject, pyMapping, isPrimary);
            if (result.isNullObj())
                return eNotApplicable;
            pClonedObject = result.impObj();
            return eOk;
        }
        reg_wblockClone = false;
        return eNotImplemented;
    }
    catch (...)
    {
        printExceptionMsg();
        reg_wblockClone = false;
    }
    return eInvalidInput;
}

Acad::ErrorStatus PyDbObjectOverrule::baseOpen(PyDbObject& pSubject, AcDb::OpenMode mode)
{
    return AcDbObjectOverrule::open(pSubject.impObj(), mode);
}

Acad::ErrorStatus PyDbObjectOverrule::baseClose(PyDbObject& pSubject)
{
    return AcDbObjectOverrule::close(pSubject.impObj());
}

Acad::ErrorStatus PyDbObjectOverrule::baseCancel(PyDbObject& pSubject)
{
    return AcDbObjectOverrule::cancel(pSubject.impObj());
}

Acad::ErrorStatus PyDbObjectOverrule::baseErase(PyDbObject& pSubject, Adesk::Boolean erasing)
{
    return AcDbObjectOverrule::erase(pSubject.impObj(), erasing);
}

PyDbObject PyDbObjectOverrule::baseDeepClone(const PyDbObject& pSubject, PyDbObject& pOwnerObject, PyDbIdMapping& idMap, Adesk::Boolean isPrimary)
{
    AcDbObject* pClone = nullptr;
    PyThrowBadEs(AcDbObjectOverrule::deepClone(pSubject.impObj(), pOwnerObject.impObj(), pClone, *idMap.impObj(), isPrimary));
    PyDbObject pyClonedObject(const_cast<AcDbObject*>(pClone), false);
    pyClonedObject.forceKeepAlive(true);
    return pyClonedObject;
}

PyDbObject PyDbObjectOverrule::baseWblockClone(const PyDbObject& pSubject, PyRxObject& pOwnerObject, PyDbIdMapping& idMap, Adesk::Boolean isPrimary)
{
    AcDbObject* pClone = nullptr;
    PyThrowBadEs(AcDbObjectOverrule::wblockClone(pSubject.impObj(), pOwnerObject.impObj(), pClone, *idMap.impObj(), isPrimary));
    PyDbObject pyClonedObject(const_cast<AcDbObject*>(pClone), false);
    pyClonedObject.forceKeepAlive(true);
    return pyClonedObject;
}

std::string PyDbObjectOverrule::className()
{
    return "AcDbObjectOverrule";
}

PyRxClass PyDbObjectOverrule::desc()
{
    return PyRxClass(AcDbObjectOverrule::desc(), false);
}

AcDbObjectOverrule* PyDbObjectOverrule::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbObjectOverrule*>(m_pyImp.get());
}


//-----------------------------------------------------------------------------------------
//PyDbOsnapOverrule
void makePyDbOsnapOverruleWrapper()
{
    PyDocString DS("OsnapOverrule");
    class_<PyDbOsnapOverrule, bases<PyRxOverrule>, boost::noncopyable>("OsnapOverrule")
        .def(init<>(DS.ARGS()))

        .def("isApplicable", &PyDbOsnapOverrule::isApplicableWr, DS.ARGS({ "object: PyRx.RxObject" }))
        .def("isContentSnappable", &PyDbOsnapOverrule::isContentSnappableWr, DS.ARGS({ "object: PyDb.Entity" }))

        .def("getOsnapPoints", &PyDbOsnapOverrule::getOsnapPointsWr,
            DS.ARGS({ "pSubject: PyDb.Entity", "osMode: PyDb.OsnapMode", "gsMark: int","pickPnt: PyGe.Point3d","lastPnt: PyGe.Point3d","viewXform: PyGe.Matrix3d" }))
        .def("getOsnapPointsX", &PyDbOsnapOverrule::getOsnapPointsXWr,
            DS.ARGS({ "pSubject: PyDb.Entity", "osMode: PyDb.OsnapMode", "gsMark: int","pickPnt: PyGe.Point3d","lastPnt: PyGe.Point3d","viewXform: PyGe.Matrix3d","insertionMat: PyGe.Matrix3d" }))

        .def("baseIsContentSnappable", &PyDbOsnapOverrule::baseIsContentSnappable, DS.ARGS({ "object: PyDb.Entity" }))

        .def("baseGetOsnapPoints", &PyDbOsnapOverrule::baseGetOsnapPoints,
            DS.ARGS({ "pSubject: PyDb.Entity", "osMode: PyDb.OsnapMode", "gsMark: int","pickPnt: PyGe.Point3d","lastPnt: PyGe.Point3d","viewXform: PyGe.Matrix3d" }))

        .def("baseGetOsnapPointsX", &PyDbOsnapOverrule::baseGetOsnapPointsX,
            DS.ARGS({ "pSubject: PyDb.Entity", "osMode: PyDb.OsnapMode", "gsMark: int","pickPnt: PyGe.Point3d","lastPnt: PyGe.Point3d","viewXform: PyGe.Matrix3d","insertionMat: PyGe.Matrix3d" }))

        .def("className", &PyDbOsnapOverrule::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbOsnapOverrule::desc, DS.SARGS(15560)).staticmethod("desc")
        ;
}

static std::mutex PyDbOsnapOverruleMutex;

static auto tupletotuple(const boost::python::tuple& pytuple)
{
    Acad::ErrorStatus es = eInvalidInput;
    AcGePoint3dArray pts;
    if (PyTuple_Check(pytuple.ptr()) && boost::python::len(pytuple) == 2)
    {
        if (extract<int>(pytuple[0]).check())
            es = extract<Acad::ErrorStatus>(pytuple[0]);

        if (extract<list>(pytuple[1]).check())
            pts = PyListToPoint3dArray(pytuple[1]);
    }
    return std::make_tuple(es, pts);
}

PyDbOsnapOverrule::PyDbOsnapOverrule()
    : PyRxOverrule(this)
{
}

bool PyDbOsnapOverrule::isApplicable(const AcRxObject* pOverruledSubject) const
{
#ifdef BRXAPP
    std::lock_guard<std::mutex> lk(PyDbOsnapOverruleMutex);
#endif // BRXAPP
    if (!reg_isApplicable)
        return false;
    PyRxObject obj(pOverruledSubject);
    return this->isApplicableWr(obj);
}

bool PyDbOsnapOverrule::isContentSnappable(const AcDbEntity* pSubject)
{
    if (!reg_isContentSnappable)
        return AcDbOsnapOverrule::isContentSnappable(pSubject);
    PyDbEntity obj(const_cast<AcDbEntity*>(pSubject), false);
    obj.forceKeepAlive(true);
    return this->isContentSnappableWr(obj);
}

Acad::ErrorStatus PyDbOsnapOverrule::getOsnapPoints(
    const AcDbEntity* pSubject,
    AcDb::OsnapMode osnapMode,
    Adesk::GsMarker gsSelectionMark,
    const AcGePoint3d& pickPoint,
    const AcGePoint3d& lastPoint,
    const AcGeMatrix3d& viewXform,
    AcGePoint3dArray& snapPoints,
    AcDbIntArray& geomIds)
{
    if (!reg_getOsnapPoints)
        return AcDbOsnapOverrule::getOsnapPoints(pSubject, osnapMode, gsSelectionMark, pickPoint, lastPoint, viewXform, snapPoints, geomIds);

    PyDbEntity obj(const_cast<AcDbEntity*>(pSubject), false);
    obj.forceKeepAlive(true);

    PyAutoLockGIL lock;
    if (auto [es, pts] = tupletotuple(this->getOsnapPointsWr(obj, osnapMode, gsSelectionMark, pickPoint, lastPoint, viewXform)); es == eOk)
    {
        for (const auto& item : pts)
            snapPoints.append(item);
        return eOk;
    }
    return eInvalidInput;
}

Acad::ErrorStatus PyDbOsnapOverrule::getOsnapPoints(const AcDbEntity* pSubject,
    AcDb::OsnapMode osnapMode,
    Adesk::GsMarker gsSelectionMark,
    const AcGePoint3d& pickPoint,
    const AcGePoint3d& lastPoint,
    const AcGeMatrix3d& viewXform,
    AcGePoint3dArray& snapPoints,
    AcDbIntArray& geomIds,
    const AcGeMatrix3d& insertionMat)
{
    if (!reg_getOsnapPointsXform)
        return AcDbOsnapOverrule::getOsnapPoints(pSubject, osnapMode, gsSelectionMark, pickPoint, lastPoint, viewXform, snapPoints, geomIds, insertionMat);

    PyDbEntity obj(const_cast<AcDbEntity*>(pSubject), false);
    obj.forceKeepAlive(true);

    PyAutoLockGIL lock;
    if (auto [es, pts] = tupletotuple(this->getOsnapPointsXWr(obj, osnapMode, gsSelectionMark, pickPoint, lastPoint, viewXform, insertionMat)); es == eOk)
    {
        for (const auto& item : pts)
            snapPoints.append(item);
        return eOk;
    }
    return eInvalidInput;
}

bool PyDbOsnapOverrule::isApplicableWr(const PyRxObject& pOverruledSubject) const
{
    PyAutoLockGIL lock;
    try
    {
        if (const override& f = get_override("isApplicable"))
            return f(pOverruledSubject);
        reg_isApplicable = false;
        return false;
    }
    catch (...)
    {
        printExceptionMsg();
        reg_isApplicable = false;
    }
    return false;
}

bool PyDbOsnapOverrule::isContentSnappableWr(const PyDbEntity& pSubject)
{
    PyAutoLockGIL lock;
    try
    {
        if (const override& f = get_override("isContentSnappable"))
            return f(pSubject);
        reg_isContentSnappable = false;
        return false;
    }
    catch (...)
    {
        printExceptionMsg();
        reg_isContentSnappable = false;
    }
    return false;
}

bool PyDbOsnapOverrule::baseIsContentSnappable(const PyDbEntity& pSubject)
{
    return AcDbOsnapOverrule::isContentSnappable(pSubject.impObj());
}

boost::python::tuple PyDbOsnapOverrule::getOsnapPointsWr(
    PyDbEntity& pSubject,
    AcDb::OsnapMode osnapMode,
    Adesk::GsMarker gsSelectionMark,
    const AcGePoint3d& pickPoint,
    const AcGePoint3d& lastPoint,
    const AcGeMatrix3d& viewXform)
{
    try
    {
        if (const override& f = get_override("getOsnapPoints"))
            return f(pSubject, osnapMode, gsSelectionMark, pickPoint, lastPoint, viewXform);
        reg_getOsnapPoints = false;
    }
    catch (...)
    {
        printExceptionMsg();
        reg_isApplicable = false;
    }
    return boost::python::make_tuple(eInvalidInput, boost::python::list());
}

boost::python::tuple PyDbOsnapOverrule::getOsnapPointsXWr(
    PyDbEntity& pSubject,
    AcDb::OsnapMode osnapMode,
    Adesk::GsMarker gsSelectionMark,
    const AcGePoint3d& pickPoint,
    const AcGePoint3d& lastPoint,
    const AcGeMatrix3d& viewXform,
    const AcGeMatrix3d& insertionMat)
{
    try
    {
        if (const override& f = get_override("getOsnapPointsX"))
            return f(pSubject, osnapMode, gsSelectionMark, pickPoint, lastPoint, viewXform, insertionMat);
        reg_getOsnapPointsXform = false;
    }
    catch (...)
    {
        printExceptionMsg();
        reg_isApplicable = false;
    }
    return boost::python::make_tuple(eInvalidInput, boost::python::list());
}

boost::python::tuple PyDbOsnapOverrule::baseGetOsnapPoints(
    PyDbEntity& pSubject,
    AcDb::OsnapMode osnapMode,
    Adesk::GsMarker gsSelectionMark,
    const AcGePoint3d& pickPoint,
    const AcGePoint3d& lastPoint,
    const AcGeMatrix3d& viewXform)
{
    PyAutoLockGIL lock;
    AcGePoint3dArray pts;
    AcDbIntArray geoids;
    auto es = AcDbOsnapOverrule::getOsnapPoints(pSubject.impObj(), osnapMode, gsSelectionMark, pickPoint, lastPoint, viewXform, pts, geoids);
    return boost::python::make_tuple(es, Point3dArrayToPyList(pts));
}

boost::python::tuple PyDbOsnapOverrule::baseGetOsnapPointsX(
    PyDbEntity& pSubject,
    AcDb::OsnapMode osnapMode,
    Adesk::GsMarker gsSelectionMark,
    const AcGePoint3d& pickPoint,
    const AcGePoint3d& lastPoint,
    const AcGeMatrix3d& viewXform,
    const AcGeMatrix3d& insertionMat)
{
    PyAutoLockGIL lock;
    AcGePoint3dArray pts;
    AcDbIntArray geoids;
    auto es = AcDbOsnapOverrule::getOsnapPoints(pSubject.impObj(), osnapMode, gsSelectionMark, pickPoint, lastPoint, viewXform, pts, geoids, insertionMat);
    return boost::python::make_tuple(es, Point3dArrayToPyList(pts));
}

std::string PyDbOsnapOverrule::className()
{
    return "AcDbOsnapOverrule";
}

PyRxClass PyDbOsnapOverrule::desc()
{
    return PyRxClass(AcDbOsnapOverrule::desc(), false);
}

AcDbOsnapOverrule* PyDbOsnapOverrule::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbOsnapOverrule*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
//PyDbGripOverrule
void makePyDbGripOverruleWrapper()
{
    PyDocString DS("GripOverrule");
    class_<PyDbGripOverrule, bases<PyRxOverrule>, boost::noncopyable>("GripOverrule")
        .def(init<>(DS.ARGS()))
        .def("isApplicable", &PyDbGripOverrule::isApplicableWr, DS.ARGS({ "object: PyRx.RxObject" }))
        .def("getGripPoints", &PyDbGripOverrule::getGripPointsWr, DS.ARGS({ "entity: PyDb.Entity", "gripPoints:list[PyGe.Point3d]", "osnapModes:list[int]","geomIds:list[int]" }))
        .def("moveGripPointsAts", &PyDbGripOverrule::moveGripPointsAtWr, DS.ARGS({ "entity: PyDb.Entity","indices:list[int]","offset:PyGe.Vector3d" }))
        .def("getStretchPoints", &PyDbGripOverrule::getStretchPointsWr, DS.ARGS({ "entity: PyDb.Entity", "gripPoints:list[PyGe.Point3d]" }))
        .def("moveStretchPointsAt", &PyDbGripOverrule::moveStretchPointsAtWr, DS.ARGS({ "entity: PyDb.Entity","indices:list[int]","offset:PyGe.Vector3d" }))
        .def("gripStatus", &PyDbGripOverrule::gripStatusWr, DS.ARGS({ "entity: PyDb.Entity","status: PyDb.GripStat" }))
        .def("className", &PyDbGripOverrule::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbGripOverrule::desc, DS.SARGS(15560)).staticmethod("desc")
        ;
}

static std::mutex PyDbGripOverruleMutex;

PyDbGripOverrule::PyDbGripOverrule()
    : PyRxOverrule(this)
{
}

bool PyDbGripOverrule::isApplicable(const AcRxObject* pOverruledSubject) const
{
#ifdef BRXAPP
    std::lock_guard<std::mutex> lk(PyDbGripOverruleMutex);
#endif // BRXAPP
    PyAutoLockGIL lock;
    if (!reg_isApplicable)
        return false;
    PyRxObject obj(pOverruledSubject);
    return this->isApplicableWr(obj);
}

Acad::ErrorStatus PyDbGripOverrule::getGripPoints(const AcDbEntity* pSubject, AcGePoint3dArray& gripPoints, AcDbIntArray& osnapModes, AcDbIntArray& geomIds)
{
    try
    {
        PyAutoLockGIL lock;
        if (!reg_getGripPoints)
            return eNotImplemented;
        PyDbEntity obj(const_cast<AcDbEntity*>(pSubject), false);
        obj.forceKeepAlive(true);
        boost::python::list pygripPoints;
        boost::python::list pyosnapModes;
        boost::python::list pygeomIds;
        auto es = this->getGripPointsWr(obj, pygripPoints, pyosnapModes, pygeomIds);
        if (es == eOk)
        {
            for (const auto& item : PyListToPoint3dArray(pygripPoints))
                gripPoints.append(item);
            for (const auto& item : PyListToInt32Array(pyosnapModes))
                osnapModes.append(item);
            for (const auto& item : PyListToInt32Array(pygeomIds))
                geomIds.append(item);
        }
        return es;
    }
    catch (...) 
    {
        reg_getGripPoints = false;
    }
    return eInvalidInput;
}

Acad::ErrorStatus PyDbGripOverrule::moveGripPointsAt(AcDbEntity* pSubject, const AcDbIntArray& indices, const AcGeVector3d& offset)
{
    try
    {
        PyAutoLockGIL lock;
        if (!reg_moveGripPointsAt)
            return eNotImplemented;
        PyDbEntity obj(const_cast<AcDbEntity*>(pSubject), false);
        obj.forceKeepAlive(true);
        boost::python::list pyindices;
        for (const auto& item : indices)
            pyindices.append(item);
        return this->moveGripPointsAtWr(obj, pyindices, offset);
    }
    catch (...)
    {
        reg_moveGripPointsAt = false;
    }
    return eInvalidInput;
}

Acad::ErrorStatus PyDbGripOverrule::getStretchPoints(const AcDbEntity* pSubject, AcGePoint3dArray& stretchPoints)
{
    try
    {
        PyAutoLockGIL lock;
        if (!reg_getStretchPoints)
            return eNotImplemented;
        PyDbEntity obj(const_cast<AcDbEntity*>(pSubject), false);
        obj.forceKeepAlive(true);
        boost::python::list pystretchPoints;
        auto es = this->getStretchPointsWr(obj, pystretchPoints);
        if (es == eOk)
        {
            for (const auto& item : PyListToPoint3dArray(pystretchPoints))
                stretchPoints.append(item);
        }
        return es;
    }
    catch (...)
    {
        reg_getStretchPoints = false;
    }
    return eInvalidInput;
}

Acad::ErrorStatus PyDbGripOverrule::moveStretchPointsAt(AcDbEntity* pSubject, const AcDbIntArray& indices, const AcGeVector3d& offset)
{
    try
    {
        PyAutoLockGIL lock;
        if (!reg_moveStretchPointsAt)
            return eNotImplemented;
        PyDbEntity obj(const_cast<AcDbEntity*>(pSubject), false);
        obj.forceKeepAlive(true);
        boost::python::list pyindices;
        for (const auto& item : indices)
            pyindices.append(item);
        return this->moveStretchPointsAtWr(obj, pyindices, offset);
    }
    catch (...)
    {
        reg_moveStretchPointsAt = false;
    }
    return eInvalidInput;
}

void PyDbGripOverrule::gripStatus(AcDbEntity* pSubject, const AcDb::GripStat status)
{
    PyAutoLockGIL lock;
    if (reg_gripStatus)
        return;
    PyDbEntity obj(const_cast<AcDbEntity*>(pSubject), false);
    obj.forceKeepAlive(true);
    this->gripStatusWr(obj, status);
}

bool PyDbGripOverrule::isApplicableWr(const PyRxObject& pOverruledSubject) const
{
    try
    {
        if (const override& f = get_override("isApplicable"))
            return f(pOverruledSubject);
        reg_isApplicable = false;
        return false;
    }
    catch (...)
    {
        printExceptionMsg();
        reg_isApplicable = false;
    }
    return false;
}

Acad::ErrorStatus PyDbGripOverrule::getGripPointsWr(const PyDbEntity& pSubject, boost::python::list& gripPoints, boost::python::list& osnapModes, boost::python::list& geomIds)
{
    try
    {
        if (const override& f = get_override("getGripPoints"))
            return f(pSubject, gripPoints, osnapModes, geomIds);
        reg_getGripPoints = false;
        return eNotImplemented;
    }
    catch (...)
    {
        printExceptionMsg();
        reg_getGripPoints = false;
    }
    return eNotImplemented;
}

Acad::ErrorStatus PyDbGripOverrule::moveGripPointsAtWr(const PyDbEntity& pSubject, const boost::python::list& indices, const AcGeVector3d& offset)
{
    try
    {
        if (const override& f = get_override("moveGripPointsAt"))
            return f(pSubject, indices, offset);
        reg_moveGripPointsAt = false;
        return eNotImplemented;
    }
    catch (...)
    {
        printExceptionMsg();
        reg_moveGripPointsAt = false;
    }
    return eNotImplemented;
}

Acad::ErrorStatus PyDbGripOverrule::getStretchPointsWr(const PyDbEntity& pSubject, boost::python::list& stretchPoints)
{
    try
    {
        if (const override& f = get_override("getStretchPoints"))
            return f(pSubject, stretchPoints);
        reg_getStretchPoints = false;
        return eNotImplemented;
    }
    catch (...)
    {
        printExceptionMsg();
        reg_getStretchPoints = false;
    }
    return eNotImplemented;
}

Acad::ErrorStatus PyDbGripOverrule::moveStretchPointsAtWr(const PyDbEntity& pSubject, const boost::python::list& indices, const AcGeVector3d& offset)
{
    try
    {
        if (const override& f = get_override("moveStretchPointsAt"))
            return f(pSubject, indices, offset);
        reg_moveStretchPointsAt = false;
        return eNotImplemented;
    }
    catch (...)
    {
        printExceptionMsg();
        reg_moveStretchPointsAt = false;
    }
    return eNotImplemented;
}

void PyDbGripOverrule::gripStatusWr(const PyDbEntity& pSubject, const AcDb::GripStat status)
{
    try
    {
        if (const override& f = get_override("gripStatus"))
            f(pSubject, status);
        reg_gripStatus = false;
    }
    catch (...)
    {
        printExceptionMsg();
        reg_gripStatus = false;
    }
}

std::string PyDbGripOverrule::className()
{
    return "AcDbOsnapOverrule";
}

PyRxClass PyDbGripOverrule::desc()
{
    return PyRxClass(AcDbGripOverrule::desc(), false);
}
