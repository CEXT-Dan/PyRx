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
