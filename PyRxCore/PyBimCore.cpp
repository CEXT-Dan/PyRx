#include "stdafx.h"
#include "PyBimCore.h"

#ifdef BRXAPP
#include "AnchorFeature.h"
#include "PyDbDatabase.h"
#include "PyDbObjectId.h"
#include "PyDbEntity.h"


using namespace boost::python;
//---------------------------------------------------------------------------------------- -
//PyBimCore
void makePyPyBimCoreWrapper()
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
    PyThrowBadEs(BimApi::createAnchoredBlockReference(blockRefId.m_id, faceSubentPath.m_pyImp, pointOnFace, keepOrientation, id.m_id));
    return id;
}

void PyBimCore::unAnchorBlockReference(const PyDbObjectId& blockRefId)
{
    PyThrowBadEs(BimApi::unAnchorBlockReference(blockRefId.m_id));
}

#endif
