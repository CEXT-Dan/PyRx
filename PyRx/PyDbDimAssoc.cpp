#include "stdafx.h"
#include "PyDbDimAssoc.h"
#include "PyDbObjectId.h"
#include "PyDbIdMapping.h"

void makePyDbDimAssocWrapper()
{

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

void PyDbDimAssoc::setAssocFlag(int ptType, bool value)
{
    PyThrowBadEs(impObj()->setAssocFlag(ptType, value));
}

void PyDbDimAssoc::setAssocFlag(int assocFlg)
{
    impObj()->setAssocFlag(assocFlg);
}

bool PyDbDimAssoc::assocFlag(int ptType) const
{
    return impObj()->assocFlag(ptType);
}

int PyDbDimAssoc::assocFlag(void)
{
    return impObj()->assocFlag();
}

void PyDbDimAssoc::setRotatedDimType(AcDbDimAssoc::RotatedDimType dimType)
{
    PyThrowBadEs(impObj()->setRotatedDimType(dimType));
}

AcDbDimAssoc::RotatedDimType PyDbDimAssoc::rotatedDimType() const
{
    return impObj()->rotatedDimType();
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
    PyThrowBadEs(impObj()->startOopsWatcher());
}

void PyDbDimAssoc::startOopsWatcher2(bool bAddAll)
{
    PyThrowBadEs(impObj()->startOopsWatcher(bAddAll));
}

void PyDbDimAssoc::removeOopsWatcher(void)
{
    impObj()->removeOopsWatcher();
}

void PyDbDimAssoc::restoreAssocFromOopsWatcher(void)
{
    PyThrowBadEs(impObj()->restoreAssocFromOopsWatcher());
}

bool PyDbDimAssoc::hasOopsWatcher(void) const
{
    return impObj()->hasOopsWatcher();
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
    PyThrowBadEs(impObj()->updateFillet(PyListToObjectIdArray(ids)));
}

void PyDbDimAssoc::updateAssociativity(const boost::python::list& ids)
{
    PyThrowBadEs(impObj()->updateAssociativity(PyListToObjectIdArray(ids)));
}

void PyDbDimAssoc::updateXrefSubentPath()
{
    PyThrowBadEs(impObj()->updateXrefSubentPath());
}

void PyDbDimAssoc::updateSubentPath(PyDbIdMapping& idMap)
{
    PyThrowBadEs(impObj()->updateSubentPath(*idMap.impObj()));
}

void PyDbDimAssoc::updateDueToMirror(bool wasInMirror)
{
    impObj()->updateDueToMirror(wasInMirror);
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
