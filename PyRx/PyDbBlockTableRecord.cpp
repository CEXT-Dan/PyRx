#include "stdafx.h"
#include "PyDbBlockTableRecord.h"
#include "PyDbEntity.h"


using namespace boost::python;
//---------------------------------------------------------------------------------------- -
//PyDbBlockTableRecord wrapper
void makeAcDbBlockTableRecordWrapper()
{
    class_<PyDbBlockTableRecord, bases<PyDbSymbolTableRecord>>("BlockTableRecord", boost::python::no_init)
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("className", &PyDbBlockTableRecord::className).staticmethod("className")
        .def("appendAcDbEntity", &PyDbBlockTableRecord::appendAcDbEntity)
        .def("objectIds", &PyDbBlockTableRecord::objectIds)
        .def("comments", &PyDbBlockTableRecord::comments)
        .def("setComments", &PyDbBlockTableRecord::setComments)
        .def("pathName", &PyDbBlockTableRecord::pathName)
        .def("setPathName", &PyDbBlockTableRecord::setPathName)
        .def("origin", &PyDbBlockTableRecord::origin)
        .def("setOrigin", &PyDbBlockTableRecord::setOrigin)
        .def("openBlockBegin", &PyDbBlockTableRecord::openBlockBegin)
        .def("openBlockEnd", &PyDbBlockTableRecord::openBlockEnd)
        .def("hasAttributeDefinitions", &PyDbBlockTableRecord::hasAttributeDefinitions)
        .def("isAnonymous", &PyDbBlockTableRecord::isAnonymous)
        .def("isFromExternalReference", &PyDbBlockTableRecord::isFromExternalReference)
        .def("isFromOverlayReference", &PyDbBlockTableRecord::isFromOverlayReference)
        .def("setIsFromOverlayReference", &PyDbBlockTableRecord::setIsFromOverlayReference)
        .def("isLayout", &PyDbBlockTableRecord::isLayout)
        .def("getLayoutId", &PyDbBlockTableRecord::getLayoutId)
        .def("setLayoutId", &PyDbBlockTableRecord::setLayoutId)
        .def("getBlockReferenceIds", &PyDbBlockTableRecord::getBlockReferenceIds)
        .def("getErasedBlockReferenceIds", &PyDbBlockTableRecord::getErasedBlockReferenceIds)
        .def("xrefDatabase", &PyDbBlockTableRecord::xrefDatabase)
        .def("isUnloaded", &PyDbBlockTableRecord::isUnloaded)
        .def("setIsUnloaded", &PyDbBlockTableRecord::setIsUnloaded)
        .def("xrefStatus", &PyDbBlockTableRecord::xrefStatus)
        .def("assumeOwnershipOf", &PyDbBlockTableRecord::assumeOwnershipOf)
        .def("blockScaling", &PyDbBlockTableRecord::blockScaling)
        .def("setBlockScaling", &PyDbBlockTableRecord::setBlockScaling)
        .def("setExplodable", &PyDbBlockTableRecord::setExplodable)
        .def("explodable", &PyDbBlockTableRecord::explodable)
        .def("setBlockInsertUnits", &PyDbBlockTableRecord::setBlockInsertUnits)
        .def("blockInsertUnits", &PyDbBlockTableRecord::blockInsertUnits)
        .def("postProcessAnnotativeBTR", &PyDbBlockTableRecord::postProcessAnnotativeBTR)
        .def("addAnnoScalestoBlkRefs", &PyDbBlockTableRecord::addAnnoScalestoBlkRefs)
        .def("aslist", &PyDbBlockTableRecord::objectIds)
        ;
}

//---------------------------------------------------------------------------------------- -
//PyDbBlockTableRecord
PyDbBlockTableRecord::PyDbBlockTableRecord(AcDbBlockTableRecord* ptr, bool autoDelete)
    : PyDbSymbolTableRecord(ptr, autoDelete)
{

}

PyDbBlockTableRecord::PyDbBlockTableRecord(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbSymbolTableRecord(nullptr, false)
{
    AcDbBlockTableRecord* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbBlockTableRecord>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    this->resetImp(pobj, false, true);
}

PyDbObjectId PyDbBlockTableRecord::appendAcDbEntity(const PyDbEntity& ent)
{
    AcDbObjectId _id;
    if (auto es = impObj()->appendAcDbEntity(_id, ent.impObj()); es != eOk)
        throw PyAcadErrorStatus(es);
    return PyDbObjectId(_id);
}

boost::python::list PyDbBlockTableRecord::objectIds()
{
    boost::python::list pyList;
    auto [es, iter] = makeBlockTableRecordIterator(*impObj());
    if (es == eOk)
    {
        for (iter->start(); !iter->done(); iter->step())
        {
            PyDbObjectId id;
            if (iter->getEntityId(id.m_id) == eOk)
                pyList.append(id);
        }
    }
    return pyList;
}

std::string PyDbBlockTableRecord::comments()
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    AcString str;
    impObj()->comments(str);
    return wstr_to_utf8(str);
#endif
}

Acad::ErrorStatus PyDbBlockTableRecord::setComments(const std::string& pString)
{
    return impObj()->setComments(utf8_to_wstr(pString).c_str());
}

std::string PyDbBlockTableRecord::pathName()
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    AcString str;
    impObj()->pathName(str);
    return wstr_to_utf8(str);
#endif
}

Acad::ErrorStatus PyDbBlockTableRecord::setPathName(const std::string& pString)
{
    return impObj()->setPathName(utf8_to_wstr(pString).c_str());
}

AcGePoint3d PyDbBlockTableRecord::origin() const
{
    return impObj()->origin();
}

Acad::ErrorStatus PyDbBlockTableRecord::setOrigin(const AcGePoint3d& pt)
{
    return impObj()->setOrigin(pt);
}

//TODO: wrong
Acad::ErrorStatus PyDbBlockTableRecord::openBlockBegin(PyDbBlockBegin& pBlockBegin, AcDb::OpenMode openMode)
{
    AcDbBlockBegin* pObj = nullptr;
    auto stat = impObj()->openBlockBegin(pObj, openMode);
    if (stat == eOk)
        pBlockBegin = PyDbBlockBegin(pObj, false);
    return stat;
}

Acad::ErrorStatus PyDbBlockTableRecord::openBlockEnd(PyDbBlockEnd& pBlockBegin, AcDb::OpenMode openMode)
{
    AcDbBlockEnd* pObj = nullptr;
    auto stat = impObj()->openBlockEnd(pObj, openMode);
    if (stat == eOk)
        pBlockBegin = PyDbBlockEnd(pObj, false);
    return stat;
}

bool PyDbBlockTableRecord::hasAttributeDefinitions() const
{
    return impObj()->hasAttributeDefinitions();
}

bool PyDbBlockTableRecord::isAnonymous() const
{
    return impObj()->isAnonymous();
}

bool PyDbBlockTableRecord::isFromExternalReference() const
{
    return impObj()->isFromExternalReference();
}

bool PyDbBlockTableRecord::isFromOverlayReference() const
{
    return impObj()->isFromOverlayReference();
}

Acad::ErrorStatus PyDbBlockTableRecord::setIsFromOverlayReference(bool bIsOverlay)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setIsFromOverlayReference(bIsOverlay);
#endif
}

bool PyDbBlockTableRecord::isLayout() const
{
    return impObj()->isLayout();
}

PyDbObjectId PyDbBlockTableRecord::getLayoutId() const
{
    return PyDbObjectId(impObj()->getLayoutId());
}

Acad::ErrorStatus PyDbBlockTableRecord::setLayoutId(const PyDbObjectId& id)
{
    return impObj()->setLayoutId(id.m_id);
}

boost::python::list PyDbBlockTableRecord::getBlockReferenceIds(bool bDirectOnly, bool bForceValidity)
{
    AcDbObjectIdArray ids;
    boost::python::list lids;
    impObj()->getBlockReferenceIds(ids, bDirectOnly, bForceValidity);
    for (const auto& item : ids)
        lids.append(PyDbObjectId(item));
    return lids;
}

boost::python::list PyDbBlockTableRecord::getErasedBlockReferenceIds()
{
    AcDbObjectIdArray ids;
    boost::python::list lids;
    impObj()->getErasedBlockReferenceIds(ids);
    for (const auto& item : ids)
        lids.append(PyDbObjectId(item));
    return lids;
}

PyDbDatabase PyDbBlockTableRecord::xrefDatabase(bool incUnres) const
{
    return PyDbDatabase(impObj()->xrefDatabase(incUnres));
}

bool PyDbBlockTableRecord::isUnloaded() const
{
    return impObj()->isUnloaded();
}

Acad::ErrorStatus PyDbBlockTableRecord::setIsUnloaded(bool isUnloaded)
{
    return impObj()->setIsUnloaded(isUnloaded);
}

AcDb::XrefStatus PyDbBlockTableRecord::xrefStatus() const
{
    return impObj()->xrefStatus();
}

Acad::ErrorStatus PyDbBlockTableRecord::assumeOwnershipOf(const boost::python::list& entitiesToMove)
{
    try
    {
        const auto PyDbObjectIds = py_list_to_std_vector<PyDbObjectId>(entitiesToMove);
        AcDbObjectIdArray ids;
        for (const auto& pyId : PyDbObjectIds)
            ids.append(pyId.m_id);
        return impObj()->assumeOwnershipOf(ids);
    }
    catch (...)
    {
        throw PyAcadErrorStatus(eInvalidInput);
    }
}

AcDbBlockTableRecord::BlockScaling PyDbBlockTableRecord::blockScaling() const
{
    return impObj()->blockScaling();
}

Acad::ErrorStatus PyDbBlockTableRecord::setBlockScaling(AcDbBlockTableRecord::BlockScaling _blockScaling)
{
    return impObj()->setBlockScaling(_blockScaling);
}

Acad::ErrorStatus PyDbBlockTableRecord::setExplodable(bool bExplodable)
{
    return impObj()->setExplodable(bExplodable);
}

bool PyDbBlockTableRecord::explodable() const
{
    return impObj()->explodable();
}

Acad::ErrorStatus PyDbBlockTableRecord::setBlockInsertUnits(AcDb::UnitsValue insunits)
{
    return impObj()->setBlockInsertUnits(insunits);
}

AcDb::UnitsValue PyDbBlockTableRecord::blockInsertUnits() const
{
    return impObj()->blockInsertUnits();
}

int PyDbBlockTableRecord::postProcessAnnotativeBTR(bool bqueryOnly, bool bScale)
{
    int stripCnt = 0;
    if (auto stat = impObj()->postProcessAnnotativeBTR(stripCnt, bqueryOnly, bScale); stat != eOk)
        throw PyAcadErrorStatus(stat);
    return stripCnt;
}

Acad::ErrorStatus PyDbBlockTableRecord::addAnnoScalestoBlkRefs(bool bScale /*= false*/)
{
    return impObj()->addAnnoScalestoBlkRefs(bScale);
}

std::string PyDbBlockTableRecord::className()
{
    return  "AcDbBlockTableRecord";
}

AcDbBlockTableRecord* PyDbBlockTableRecord::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcDbBlockTableRecord*>(m_pImp.get());
}
