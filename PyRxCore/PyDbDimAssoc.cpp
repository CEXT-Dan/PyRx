#include "stdafx.h"
#include "PyDbDimAssoc.h"
#include "PyDbObjectId.h"
#include "PyDbIdMapping.h"
#include "PyDbPointRef.h"

using namespace boost::python;

void makePyDbDimAssocWrapper()
{
    constexpr const std::string_view ctords = "Overloads:\n"
        "- None: Any\n"
        "- id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode, erased: bool\n";

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
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.CTOR(ctords, 3811)))
        .def("dimObjId", &PyDbDimAssoc::dimObjId, DS.ARGS(3817))
        .def("setDimObjId", &PyDbDimAssoc::setDimObjId, DS.ARGS({ "id : PyDb.ObjectId" }, 3836))
        .def("setAssocFlag", &PyDbDimAssoc::setAssocFlag1)
        .def("setAssocFlag", &PyDbDimAssoc::setAssocFlag2, DS.OVRL(setAssocFlagOverload, 3835))
        .def("assocFlag", &PyDbDimAssoc::assocFlag1)
        .def("assocFlag", &PyDbDimAssoc::assocFlag2, DS.OVRL(assocFlagOverload, 3815))
        .def("setPointRef", &PyDbDimAssoc::setPointRef, DS.ARGS({ "_type : int", "ptRef : PyDb.PointRef" }, 3837))
        .def("pointRef", &PyDbDimAssoc::pointRef, DS.ARGS({ "_type : int" }, 3827))
        .def("osnapPointRef", &PyDbDimAssoc::osnapPointRef, DS.ARGS({ "_type : int" }))
        .def("setRotatedDimType", &PyDbDimAssoc::setRotatedDimType, DS.ARGS({ "dimType : PyDb.RotatedDimType" }, 3839))
        .def("rotatedDimType", &PyDbDimAssoc::rotatedDimType, DS.ARGS(3834))
        .def("addToPointRefReactor", &PyDbDimAssoc::addToPointRefReactor, DS.ARGS(3814))
        .def("addToDimensionReactor", &PyDbDimAssoc::addToDimensionReactor1)
        .def("addToDimensionReactor", &PyDbDimAssoc::addToDimensionReactor2, DS.ARGS({ "add : bool=True" }, 3813))
        .def("removePointRef", &PyDbDimAssoc::removePointRef, DS.ARGS({ "_type : int" }, 3832))
        .def("updateDimension", &PyDbDimAssoc::updateDimension1)
        .def("updateDimension", &PyDbDimAssoc::updateDimension2)
        .def("updateDimension", &PyDbDimAssoc::updateDimension3, DS.ARGS({ "update : bool=True", "skipReactors : bool=False" }, 3845))
        .def("removeAssociativity", &PyDbDimAssoc::removeAssociativity1)
        .def("removeAssociativity", &PyDbDimAssoc::removeAssociativity2, DS.ARGS({ "force : bool=True" }, 3830))
        .def("isTransSpatial", &PyDbDimAssoc::isTransSpatial, DS.ARGS(3825))
        .def("setTransSpatial", &PyDbDimAssoc::setTransSpatial, DS.ARGS({ "val : bool" }, 3840))
        .def("startCmdWatcher", &PyDbDimAssoc::startCmdWatcher, DS.ARGS(3841))
        .def("startOopsWatcher", &PyDbDimAssoc::startOopsWatcher1)
        .def("startOopsWatcher", &PyDbDimAssoc::startOopsWatcher2, DS.ARGS({ "val : bool=True" }, 3842))
        .def("removeOopsWatcher", &PyDbDimAssoc::removeOopsWatcher, DS.ARGS(3831))
        .def("restoreAssocFromOopsWatcher", &PyDbDimAssoc::restoreAssocFromOopsWatcher, DS.ARGS(3833))
        .def("hasOopsWatcher", &PyDbDimAssoc::hasOopsWatcher, DS.ARGS(3823))
        .def("post", &PyDbDimAssoc::post1)
        .def("post", &PyDbDimAssoc::post2, DS.ARGS({ "id : PyDb.ObjectId","isAcive : bool=True" }, 3829))
        .def("getDimAssocGeomIds", &PyDbDimAssoc::getDimAssocGeomIds, DS.ARGS(3822))
        .def("isAllGeomErased", &PyDbDimAssoc::isAllGeomErased, DS.ARGS(3824))
        .def("swapReferences", &PyDbDimAssoc::swapReferences, DS.ARGS({ "val : PyDb.IdMapping" }, 3843))
        .def("updateFillet", &PyDbDimAssoc::updateFillet, DS.ARGS({ "ids : list[PyDb.ObjectId]" }, 3848))
        .def("updateAssociativity", &PyDbDimAssoc::updateAssociativity, DS.ARGS({ "ids : list[PyDb.ObjectId]" }, 3844))
        .def("updateXrefSubentPath", &PyDbDimAssoc::updateXrefSubentPath, DS.ARGS(3850))
        .def("updateSubentPath", &PyDbDimAssoc::updateSubentPath, DS.ARGS({ "val : PyDb.IdMapping" }, 3849))
        .def("updateDueToMirror", &PyDbDimAssoc::updateDueToMirror, DS.ARGS({ "val : bool" }, 3847))
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

void PyDbDimAssoc::setDimObjId(const PyDbObjectId& dimId) const
{
    PyThrowBadEs(impObj()->setDimObjId(dimId.m_id));
}

void PyDbDimAssoc::setAssocFlag1(int ptType, bool value) const
{
    PyThrowBadEs(impObj()->setAssocFlag(ptType, value));
}

void PyDbDimAssoc::setAssocFlag2(int assocFlg) const
{
    impObj()->setAssocFlag(assocFlg);
}

bool PyDbDimAssoc::assocFlag2(int ptType) const
{
    return impObj()->assocFlag(ptType);
}

int PyDbDimAssoc::assocFlag1(void) const
{
    return impObj()->assocFlag();
}

void PyDbDimAssoc::setPointRef(int ptType, PyDbPointRef& ptRef) const
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
#if defined(_BRXTARGET250)
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

void PyDbDimAssoc::setRotatedDimType(AcDbDimAssoc::RotatedDimType dimType) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(impObj()->setRotatedDimType(dimType));
#endif
}

AcDbDimAssoc::RotatedDimType PyDbDimAssoc::rotatedDimType() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return impObj()->rotatedDimType();
#endif
}

void PyDbDimAssoc::addToPointRefReactor() const
{
    PyThrowBadEs(impObj()->addToPointRefReactor());
}

void PyDbDimAssoc::addToDimensionReactor1() const
{
    PyThrowBadEs(impObj()->addToDimensionReactor());
}

void PyDbDimAssoc::addToDimensionReactor2(bool isAdd) const
{
    PyThrowBadEs(impObj()->addToDimensionReactor(isAdd));
}

void PyDbDimAssoc::removePointRef(int ptType) const
{
    PyThrowBadEs(impObj()->removePointRef(ptType));
}

void PyDbDimAssoc::updateDimension1() const
{
    PyThrowBadEs(impObj()->updateDimension());
}

void PyDbDimAssoc::updateDimension2(bool update) const
{
    PyThrowBadEs(impObj()->updateDimension(update));
}

void PyDbDimAssoc::updateDimension3(bool update, bool skipReactors) const
{
    PyThrowBadEs(impObj()->updateDimension(update, skipReactors));
}

void PyDbDimAssoc::removeAssociativity1() const
{
    PyThrowBadEs(impObj()->removeAssociativity());
}

void PyDbDimAssoc::removeAssociativity2(bool force) const
{
    PyThrowBadEs(impObj()->removeAssociativity(force));
}

bool PyDbDimAssoc::isTransSpatial() const
{
    return impObj()->isTransSpatial();
}

void PyDbDimAssoc::setTransSpatial(bool value) const
{
    PyThrowBadEs(impObj()->setTransSpatial(value));
}

void PyDbDimAssoc::startCmdWatcher() const
{
    PyThrowBadEs(impObj()->startCmdWatcher());
}

void PyDbDimAssoc::startOopsWatcher1() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(impObj()->startOopsWatcher());
#endif
}

void PyDbDimAssoc::startOopsWatcher2(bool bAddAll) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(impObj()->startOopsWatcher(bAddAll));
#endif
}

void PyDbDimAssoc::removeOopsWatcher(void) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    impObj()->removeOopsWatcher();
#endif
}

void PyDbDimAssoc::restoreAssocFromOopsWatcher(void) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(impObj()->restoreAssocFromOopsWatcher());
#endif
}

bool PyDbDimAssoc::hasOopsWatcher(void) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return impObj()->hasOopsWatcher();
#endif
}

PyDbObjectId PyDbDimAssoc::post1(const PyDbObjectId& dimId) const
{
    PyDbObjectId id;
    PyThrowBadEs(impObj()->post(dimId.m_id, id.m_id));
    return id;
}

PyDbObjectId PyDbDimAssoc::post2(const PyDbObjectId& dimId, bool isActive) const
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

void PyDbDimAssoc::swapReferences(const PyDbIdMapping& idMap) const
{
    PyThrowBadEs(impObj()->swapReferences(*idMap.impObj()));
}

void PyDbDimAssoc::updateFillet(const boost::python::list& ids) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(impObj()->updateFillet(PyListToObjectIdArray(ids)));
#endif
}

void PyDbDimAssoc::updateAssociativity(const boost::python::list& ids) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(impObj()->updateAssociativity(PyListToObjectIdArray(ids)));
#endif
}

void PyDbDimAssoc::updateXrefSubentPath() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(impObj()->updateXrefSubentPath());
#endif
}

void PyDbDimAssoc::updateSubentPath(PyDbIdMapping& idMap) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(impObj()->updateSubentPath(*idMap.impObj()));
#endif
}

void PyDbDimAssoc::updateDueToMirror(bool wasInMirror) const
{
#if defined(_BRXTARGET250)
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
