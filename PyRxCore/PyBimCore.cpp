#include "stdafx.h"
#include "PyBimCore.h"

#ifdef BRXAPP
#include "AnchorFeature.h"
#include "Blockify.h"
#include "PyDbDatabase.h"
#include "PyDbObjectId.h"
#include "PyDbEntity.h"


using namespace boost::python;

static BimApi::ObjectIds py_list_ObjectIds(const boost::python::list& pyids)
{
    const auto& vpyids = py_list_to_std_vector<PyDbObjectId>(pyids);
    BimApi::ObjectIds ids(vpyids.size());
    for (const auto& id : vpyids)
        ids.push_back(id.m_id);
    return ids;
}

static boost::python::tuple geomObjectIdsToTupleNoLock(const BimApi::GeomObjectIds& item)
{
    boost::python::list pylist;
    for (const auto& id : item.first)
        pylist.append(PyDbObjectId(id));
    return boost::python::make_tuple(pylist, item.second);
}

static BimApi::GeomObjectIds tupleToGeomObjectIdsNoLock(const boost::python::tuple& item)
{
    return BimApi::GeomObjectIds{ py_list_ObjectIds(extract<boost::python::list>(item[0])) ,extract<AcGeMatrix3d>(item[0]) };
}

//---------------------------------------------------------------------------------------- -
//PyBimCore
void makePyBimCoreWrapper()
{
    PyDocString DS("Core");
    class_<PyBimCore>("Core", boost::python::no_init)
        .def("getAnchoredBlockReferences", &PyBimCore::getAnchoredBlockReferences, DS.SARGS({ "db: PyDb.Database" })).staticmethod("getAnchoredBlockReferences")
        .def("isAnchoredBlockRef", &PyBimCore::isAnchoredBlockRef, DS.SARGS({ "id: PyDb.ObjectId" })).staticmethod("isAnchoredBlockRef")
        .def("getAnchorFace", &PyBimCore::getAnchorFace, DS.SARGS({ "id: PyDb.ObjectId" })).staticmethod("getAnchorFace")
        .def("queryValidAnchorPt", &PyBimCore::queryValidAnchorPt, DS.SARGS({ "pt: PyGe.Point3d","db: PyDb.Database" })).staticmethod("queryValidAnchorPt")
        .def("createAnchoredBlockReference", &PyBimCore::createAnchoredBlockReference, 
            DS.SARGS({ "blockRefId: PyDb.ObjectId","faceSubentPath: PyDb.FullSubentPath", "pt: PyGe.Point3d","keepOrientation: bool" })).staticmethod("createAnchoredBlockReference")
        .def("unAnchorBlockReference", &PyBimCore::unAnchorBlockReference, DS.SARGS({ "id: PyDb.ObjectId" })).staticmethod("unAnchorBlockReference")
        .def("isSimilarGeometry", &PyBimCore::isSimilarGeometry, DS.SARGS({ "firstSet: list[PyDb.ObjectId]", "secondSet: list[PyDb.ObjectId]" })).staticmethod("isSimilarGeometry")
        .def("findSimilarGeometry", &PyBimCore::findSimilarGeometry, DS.SARGS({ "matchSet: list[PyDb.ObjectId]", "searchSet: list[PyDb.ObjectId]" })).staticmethod("findSimilarGeometry")
        .def("findSimilar3dSolids", &PyBimCore::findSimilar3dSolids, DS.SARGS({ "entitySet: list[PyDb.ObjectId]" })).staticmethod("findSimilar3dSolids")
        .def("findMatchingBlockDefinition", &PyBimCore::findMatchingBlockDefinition, DS.SARGS({ "entitySet: list[PyDb.ObjectId]" })).staticmethod("findMatchingBlockDefinition")
        .def("matchEntitiesToBlockDefinitions", &PyBimCore::matchEntitiesToBlockDefinitions, DS.SARGS({ "entitySet: list[PyDb.ObjectId]" })).staticmethod("matchEntitiesToBlockDefinitions")
        .def("replaceGeometryByBlocks", &PyBimCore::replaceGeometryByBlocks, DS.SARGS({ "similarGroups: tuple" })).staticmethod("replaceGeometryByBlocks")
        ;
}

boost::python::list PyBimCore::getAnchoredBlockReferences(const PyDbDatabase& db)
{
    AcArray<AcDbObjectId> blockRefIds;
    PyThrowBadEs(BimApi::getAnchoredBlockReferences(db.impObj(), blockRefIds));
    return ObjectIdArrayToPyList(blockRefIds);
}

bool PyBimCore::isAnchoredBlockRef(const PyDbObjectId& blockRefId)
{
   return BimApi::isAnchoredBlockRef(blockRefId.m_id);
}

PyDbFullSubentPath PyBimCore::getAnchorFace(const PyDbObjectId& anchoredBlockRefId)
{
    AcDbFullSubentPath path;
    PyThrowBadEs(BimApi::getAnchorFace(anchoredBlockRefId.m_id, path));
    return PyDbFullSubentPath{ path };
}

PyDbFullSubentPath PyBimCore::queryValidAnchorPt(const AcGePoint3d& point, const PyDbDatabase& pDb)
{
    AcDbFullSubentPath path;
    PyThrowBadEs(BimApi::queryValidAnchorPt(point, pDb.impObj(), path));
    return PyDbFullSubentPath{ path };
}

PyDbObjectId PyBimCore::createAnchoredBlockReference(const PyDbObjectId& blockRefId, const PyDbFullSubentPath& faceSubentPath, const AcGePoint3d& pointOnFace, bool keepOrientation)
{
    PyDbObjectId id;
    PyThrowBadEs(BimApi::createAnchoredBlockReference(blockRefId.m_id, faceSubentPath.pyImp, pointOnFace, keepOrientation, id.m_id));
    return id;
}

void PyBimCore::unAnchorBlockReference(const PyDbObjectId& blockRefId)
{
    PyThrowBadEs(BimApi::unAnchorBlockReference(blockRefId.m_id));
}

boost::python::tuple PyBimCore::isSimilarGeometry(const boost::python::list& firstSet, const boost::python::list& secondSet)
{
    PyAutoLockGIL lock;
    AcGeMatrix3d transform;
    const auto& vfirstSet = py_list_ObjectIds(firstSet);
    const auto& vsecondSet = py_list_ObjectIds(secondSet);
    auto flag = BimApi::isSimilarGeometry(transform, vfirstSet, vsecondSet);
    return boost::python::make_tuple(bool(flag == eOk), transform);
}

boost::python::tuple PyBimCore::findSimilarGeometry(const boost::python::list& matchSet, const boost::python::list& searchSet)
{
    PyAutoLockGIL lock;
    BimApi::MatchingGeomSets sets;
    const auto& vfirstSet = py_list_ObjectIds(matchSet);
    const auto& vsecondSet = py_list_ObjectIds(searchSet);
    auto flag = BimApi::findSimilarGeometry(sets, vfirstSet, vsecondSet);
    boost::python::list pylist;
    for (const auto& item : sets.m_entitySets)
        pylist.append(geomObjectIdsToTupleNoLock(item));
    return boost::python::make_tuple(bool(flag == eOk), pylist, sets.m_insertionPoint);
}

boost::python::tuple PyBimCore::findSimilar3dSolids(const boost::python::list& entitySet)
{
    PyAutoLockGIL lock;
    std::vector< BimApi::MatchingGeomSets> matchingSolids;
    const auto& ventitySet = py_list_ObjectIds(entitySet);
    auto flag = BimApi::findSimilar3dSolids(matchingSolids, ventitySet);
    boost::python::list pyresult;
    for (const auto& i : matchingSolids)
    {
        boost::python::list pylist;
        for (const auto& j : i.m_entitySets)
            pylist.append(geomObjectIdsToTupleNoLock(j));
        pyresult.append(boost::python::make_tuple(pylist, i.m_insertionPoint));
    }
    return boost::python::make_tuple(bool(flag == eOk), pyresult);
}

boost::python::tuple PyBimCore::findMatchingBlockDefinition(const boost::python::list& entitySet)
{
    PyAutoLockGIL lock;
    AcGeMatrix3d transform;
    PyDbObjectId matchingBtr;
    const auto& ventitySet = py_list_ObjectIds(entitySet);
    auto flag = BimApi::findMatchingBlockDefinition(matchingBtr.m_id, transform, ventitySet);
    return boost::python::make_tuple(bool(flag == eOk), matchingBtr, transform);
}

boost::python::tuple PyBimCore::matchEntitiesToBlockDefinitions(const boost::python::list& entitySet)
{
    PyAutoLockGIL lock;
    std::vector<BimApi::BlockifyResult> resultRefs;
    const auto& ventitySet = py_list_ObjectIds(entitySet);
    auto flag = BimApi::matchEntitiesToBlockDefinitions(resultRefs,ventitySet);
    boost::python::list py_i;
    for (const auto& i : resultRefs)
    {
        boost::python::list py_j;
        for (const auto& j : i)
            py_j.append(PyDbObjectId(j));
        py_i.append(py_j);
    }
    return boost::python::make_tuple(bool(flag == eOk), py_i);
}

boost::python::tuple PyBimCore::replaceGeometryByBlocks(const boost::python::tuple& similarGroups)
{
    PyAutoLockGIL lock;
    boost::python::list geomObjectIds = extract<boost::python::list>(similarGroups[0]);
    AcGePoint3d pnt = extract<AcGePoint3d>(similarGroups[0]);
    BimApi::MatchingGeomSets sets;
    size_t nsize = len(geomObjectIds);
    for (int idx = 0; idx < nsize; idx++)
    {
        const auto& t = extract<boost::python::tuple>(geomObjectIds[0]);
        sets.m_entitySets.push_back(tupleToGeomObjectIdsNoLock(t));
    }
    sets.m_insertionPoint = pnt;
    BimApi::BlockifyResult createdRefs;
    auto flag = BimApi::replaceGeometryByBlocks(createdRefs, sets);
    boost::python::list pyids;
    for (const auto& id : createdRefs)
        pyids(PyDbObjectId(id));
    return boost::python::make_tuple(bool(flag == eOk), pyids);
}

#endif
