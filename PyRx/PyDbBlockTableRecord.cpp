#include "stdafx.h"
#include "PyDbBlockTableRecord.h"
#include "PyDbEntity.h"


using namespace boost::python;
//---------------------------------------------------------------------------------------- -
//PyDbBlockTableRecord wrapper
void makeAcDbBlockTableRecordWrapper()
{
    static auto wrapper = class_<PyDbBlockTableRecord, bases<PyDbSymbolTableRecord>>("DbBlockTableRecord", boost::python::no_init)
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
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
}

PyDbObjectId PyDbBlockTableRecord::appendAcDbEntity(const PyDbEntity& ent)
{
    AcDbObjectId _id;
    auto imp = impObj();
    if (imp != nullptr && ent.impObj() != nullptr)
    {
        if (auto es = imp->appendAcDbEntity(_id, ent.impObj()); es != eOk)
            throw PyAcadErrorStatus(es);
    }
    return PyDbObjectId(_id);
}

boost::python::list PyDbBlockTableRecord::objectIds()
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();

    boost::python::list pyList;
    auto [es, iter] = makeBlockTableRecordIterator(*imp);
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
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    AcString str;
    imp->comments(str);
    return wstr_to_utf8(str);
#endif
}

Acad::ErrorStatus PyDbBlockTableRecord::setComments(const std::string& pString)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setComments(utf8_to_wstr(pString).c_str());
}

std::string PyDbBlockTableRecord::pathName()
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    AcString str;
    imp->pathName(str);
    return wstr_to_utf8(str);
#endif
}

Acad::ErrorStatus PyDbBlockTableRecord::setPathName(const std::string& pString)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setPathName(utf8_to_wstr(pString).c_str());
}

AcGePoint3d PyDbBlockTableRecord::origin() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->origin();
}

Acad::ErrorStatus PyDbBlockTableRecord::setOrigin(const AcGePoint3d& pt)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setOrigin(pt);
}

//TODO: wrong
Acad::ErrorStatus PyDbBlockTableRecord::openBlockBegin(PyDbBlockBegin& pBlockBegin, AcDb::OpenMode openMode)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    AcDbBlockBegin* pObj = nullptr;
    auto stat = imp->openBlockBegin(pObj, openMode);
    if (stat == eOk)
        pBlockBegin = PyDbBlockBegin(pObj, false);
    return stat;
}

Acad::ErrorStatus PyDbBlockTableRecord::openBlockEnd(PyDbBlockEnd& pBlockBegin, AcDb::OpenMode openMode)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    AcDbBlockEnd* pObj = nullptr;
    auto stat = imp->openBlockEnd(pObj, openMode);
    if (stat == eOk)
        pBlockBegin = PyDbBlockEnd(pObj, false);
    return stat;
}

bool PyDbBlockTableRecord::hasAttributeDefinitions() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->hasAttributeDefinitions();
}

bool PyDbBlockTableRecord::isAnonymous() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isAnonymous();
}

bool PyDbBlockTableRecord::isFromExternalReference() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isFromExternalReference();
}

bool PyDbBlockTableRecord::isFromOverlayReference() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isFromOverlayReference();
}

Acad::ErrorStatus PyDbBlockTableRecord::setIsFromOverlayReference(bool bIsOverlay)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setIsFromOverlayReference(bIsOverlay);
#endif
}

bool PyDbBlockTableRecord::isLayout() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isLayout();
}

PyDbObjectId PyDbBlockTableRecord::getLayoutId() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return PyDbObjectId(imp->getLayoutId());
}

Acad::ErrorStatus PyDbBlockTableRecord::setLayoutId(const PyDbObjectId& id)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setLayoutId(id.m_id);
}

boost::python::list PyDbBlockTableRecord::getBlockReferenceIds(bool bDirectOnly, bool bForceValidity)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();

    AcDbObjectIdArray ids;
    boost::python::list lids;
    imp->getBlockReferenceIds(ids, bDirectOnly, bForceValidity);
    for (const auto& item : ids)
        lids.append(PyDbObjectId(item));
    return lids;
}

boost::python::list PyDbBlockTableRecord::getErasedBlockReferenceIds()
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();

    AcDbObjectIdArray ids;
    boost::python::list lids;
    imp->getErasedBlockReferenceIds(ids);
    for (const auto& item : ids)
        lids.append(PyDbObjectId(item));
    return lids;
}

PyDbDatabase PyDbBlockTableRecord::xrefDatabase(bool incUnres) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return PyDbDatabase(imp->xrefDatabase(incUnres));
}

bool PyDbBlockTableRecord::isUnloaded() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isUnloaded();
}

Acad::ErrorStatus PyDbBlockTableRecord::setIsUnloaded(bool isUnloaded)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setIsUnloaded(isUnloaded);
}

AcDb::XrefStatus PyDbBlockTableRecord::xrefStatus() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->xrefStatus();
}

Acad::ErrorStatus PyDbBlockTableRecord::assumeOwnershipOf(const boost::python::list& entitiesToMove)
{
    try
    {
        auto imp = impObj();
        if (imp == nullptr)
            throw PyNullObject();
        const auto PyDbObjectIds = py_list_to_std_vector<PyDbObjectId>(entitiesToMove);
        AcDbObjectIdArray ids;
        for (const auto& pyId : PyDbObjectIds)
            ids.append(pyId.m_id);
        return imp->assumeOwnershipOf(ids);
    }
    catch(...)
    {
        throw PyAcadErrorStatus(eInvalidInput);
    }
}

AcDbBlockTableRecord::BlockScaling PyDbBlockTableRecord::blockScaling() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->blockScaling();
}

Acad::ErrorStatus PyDbBlockTableRecord::setBlockScaling(AcDbBlockTableRecord::BlockScaling _blockScaling)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setBlockScaling(_blockScaling);
}

Acad::ErrorStatus PyDbBlockTableRecord::setExplodable(bool bExplodable)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setExplodable(bExplodable);
}

bool PyDbBlockTableRecord::explodable() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->explodable();
}

Acad::ErrorStatus PyDbBlockTableRecord::setBlockInsertUnits(AcDb::UnitsValue insunits)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setBlockInsertUnits(insunits);
}

AcDb::UnitsValue PyDbBlockTableRecord::blockInsertUnits() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->blockInsertUnits();
}

int PyDbBlockTableRecord::postProcessAnnotativeBTR(bool bqueryOnly, bool bScale)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    int stripCnt = 0;
    if (auto stat = imp->postProcessAnnotativeBTR(stripCnt, bqueryOnly, bScale); stat != eOk)
        throw PyAcadErrorStatus(stat);
    return stripCnt;
}

Acad::ErrorStatus PyDbBlockTableRecord::addAnnoScalestoBlkRefs(bool bScale /*= false*/)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->addAnnoScalestoBlkRefs(bScale);
}

std::string PyDbBlockTableRecord::className()
{
    return  "AcDbBlockTableRecord";
}

AcDbBlockTableRecord* PyDbBlockTableRecord::impObj() const
{
    return static_cast<AcDbBlockTableRecord*>(m_pImp.get());
}
