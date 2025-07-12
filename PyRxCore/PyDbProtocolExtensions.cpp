#include "stdafx.h"
#include "PyDbProtocolExtensions.h"
#include "AcDbAssocPersSubentIdPE.h"

#include "dbJoinEntityPE.h"
#include "PyDbEntity.h"
#include "PyGeEntity3d.h"
#include "PyGeCurve3d.h"
#include "PyGeSurface.h"

using namespace boost::python;
void makePyDbJoinEntityPEWrapper()
{
#if defined (_ARXTARGET) || defined (_BRXTARGET)
    PyDocString DS("JoinEntityPE");
    class_<PyDbJoinEntityPE, bases<PyRxObject>>("JoinEntityPE", boost::python::no_init)
        .def(init<const PyRxObject&>(DS.ARGS({ "obj: PyRx.RxObject" })))
        .def("joinEntity", &PyDbJoinEntityPE::joinEntity1)
        .def("joinEntity", &PyDbJoinEntityPE::joinEntity2, DS.ARGS({ "primaryEntity : PyDb.Entity" , "secondaryEntity : PyDb.Entity", "tol : PyGe.Tol = ..." }))
        .def("joinEntities", &PyDbJoinEntityPE::joinEntities1)
        .def("joinEntities", &PyDbJoinEntityPE::joinEntities2, DS.ARGS({ "primaryEntity : PyDb.Entity" , "secondaryEntities : list[PyDb.Entity]", "tol : PyGe.Tol = ..." }))
        .def("desc", &PyDbJoinEntityPE::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("className", &PyDbJoinEntityPE::className, DS.SARGS()).staticmethod("className")
        ;
#endif
}

#if defined (_ARXTARGET) || defined (_BRXTARGET)
PyDbJoinEntityPE::PyDbJoinEntityPE(const PyRxObject& PE)
    :PyDbJoinEntityPE((AcDbJoinEntityPE*)PE.impObj(), false)
{
}

PyDbJoinEntityPE::PyDbJoinEntityPE(AcDbJoinEntityPE* ptr, bool autoDelete)
    :PyRxObject(ptr, autoDelete, false)
{
}

bool PyDbJoinEntityPE::joinEntity1(PyDbEntity& pPrimaryEntity, PyDbEntity& pSecondaryEntity) const
{
    return impObj()->joinEntity(pPrimaryEntity.impObj(), pSecondaryEntity.impObj()) == eOk;
}

bool PyDbJoinEntityPE::joinEntity2(PyDbEntity& pPrimaryEntity, PyDbEntity& pSecondaryEntity, const AcGeTol& tol) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    return impObj()->joinEntity(pPrimaryEntity.impObj(), pSecondaryEntity.impObj(), tol) == eOk;
#endif
}

boost::python::list PyDbJoinEntityPE::joinEntities1(PyDbEntity& pPrimaryEntity, const boost::python::list& otherEntities) const
{
    return this->joinEntities2(pPrimaryEntity, otherEntities, AcGeContext::gTol);
}

boost::python::list PyDbJoinEntityPE::joinEntities2(PyDbEntity& pPrimaryEntity, const boost::python::list& otherEntities, const AcGeTol& tol) const
{
    PyAutoLockGIL lock;
    AcArray<AcDbEntity*> _otherEntities;
    auto pyents = py_list_to_std_vector<PyDbEntity>(otherEntities);
    for (const auto& item : pyents)
        _otherEntities.append(item.impObj());
    AcGeIntArray _joinedEntityIndices;
    boost::python::list joinedEntityIndices;
    if (impObj()->joinEntities(pPrimaryEntity.impObj(), _otherEntities, _joinedEntityIndices) == eOk)
    {
        for (auto item : _joinedEntityIndices)
            joinedEntityIndices.append(item);
    }
    return joinedEntityIndices;
}

PyRxClass PyDbJoinEntityPE::desc()
{
    return PyRxClass(AcDbJoinEntityPE::desc(), false);
}

std::string PyDbJoinEntityPE::className()
{
    return "AcDbJoinEntityPE";
}

AcDbJoinEntityPE* PyDbJoinEntityPE::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcDbJoinEntityPE*>(m_pyImp.get());
}
#endif

//-----------------------------------------------------------------------------------------
//PyDbAssocPersSubentIdPE
void makePyDbAssocPersSubentIdPEWrapper()
{
    PyDocString DS("AssocPersSubentIdPE");
    class_<PyDbAssocPersSubentIdPE, bases<PyRxObject>>("AssocPersSubentIdPE", boost::python::no_init)
        .def(init<const PyRxObject&>(DS.ARGS({ "obj: PyRx.RxObject" })))
        .def("getAllSubentities", &PyDbAssocPersSubentIdPE::getAllSubentities1)
        .def("getAllSubentities", &PyDbAssocPersSubentIdPE::getAllSubentities2, DS.ARGS({ "primaryEntity : PyDb.Entity" , "subentType : PyDb.SubentType|PyRx.RxObject" }, 2232))
        .def("getEdgeVertexSubentities", &PyDbAssocPersSubentIdPE::getEdgeVertexSubentities, DS.ARGS({ "primaryEntity : PyDb.Entity" , "subentId: PyDb.SubentId" }, 2234))
        .def("getSplineEdgeVertexSubentities", &PyDbAssocPersSubentIdPE::getSplineEdgeVertexSubentities, DS.ARGS({ "primaryEntity : PyDb.Entity" , "subentId: PyDb.SubentId" }, 2238))
        .def("getSubentityGeometry", &PyDbAssocPersSubentIdPE::getSubentityGeometry, DS.ARGS({ "primaryEntity : PyDb.Entity" , "subentId: PyDb.SubentId" }, 2240))
        .def("getVertexSubentityGeometry", &PyDbAssocPersSubentIdPE::getVertexSubentityGeometry, DS.ARGS({ "primaryEntity : PyDb.Entity" , "subentId: PyDb.SubentId" }, 2242))
        .def("getEdgeSubentityGeometry", &PyDbAssocPersSubentIdPE::getEdgeSubentityGeometry, DS.ARGS({ "primaryEntity : PyDb.Entity" , "subentId: PyDb.SubentId" }, 2108))
        .def("getFaceSubentityGeometry", &PyDbAssocPersSubentIdPE::getFaceSubentityGeometry, DS.ARGS({ "primaryEntity : PyDb.Entity" , "subentId: PyDb.SubentId" }, 2109))
        .def("desc", &PyDbAssocPersSubentIdPE::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("className", &PyDbAssocPersSubentIdPE::className, DS.SARGS()).staticmethod("className")
        ;
}

PyDbAssocPersSubentIdPE::PyDbAssocPersSubentIdPE(const PyRxObject& PE)
    :PyDbAssocPersSubentIdPE((AcDbAssocPersSubentIdPE*)PE.impObj(), false)
{
}

PyDbAssocPersSubentIdPE::PyDbAssocPersSubentIdPE(AcDbAssocPersSubentIdPE* ptr, bool autoDelete)
    :PyRxObject(ptr, autoDelete, false)
{
}

boost::python::list PyDbAssocPersSubentIdPE::getAllSubentities1(const PyDbEntity& pEntity, AcDb::SubentType subentType) const
{
    PyAutoLockGIL lock;
    AcArray<AcDbSubentId> allSubentIds;
    PyThrowBadEs(impObj()->getAllSubentities(pEntity.impObj(), subentType, allSubentIds));
    boost::python::list pylist;
    for (const auto& item : allSubentIds)
        pylist.append(PyDbSubentId(item));
    return pylist;
}

boost::python::list PyDbAssocPersSubentIdPE::getAllSubentities2(const PyDbEntity& pEntity, PyRxClass& subentType) const
{
    PyAutoLockGIL lock;
    AcArray<AcDbSubentId> allSubentIds;
    PyThrowBadEs(impObj()->getAllSubentities(pEntity.impObj(), subentType.impObj(), allSubentIds));
    boost::python::list pylist;
    for (const auto& item : allSubentIds)
        pylist.append(PyDbSubentId(item));
    return pylist;
}

boost::python::tuple PyDbAssocPersSubentIdPE::getEdgeVertexSubentities(const PyDbEntity& pEntity, const PyDbSubentId& subentId) const
{
    PyAutoLockGIL lock;
    AcDbSubentId startVertexSubentId;
    AcDbSubentId endVertexSubentId;
    AcArray<AcDbSubentId> allSubentIds;
    PyThrowBadEs(impObj()->getEdgeVertexSubentities(pEntity.impObj(), *subentId.impObj(), startVertexSubentId, endVertexSubentId, allSubentIds));
    boost::python::list pylist;
    for (const auto& item : allSubentIds)
        pylist.append(PyDbSubentId(item));
    return boost::python::make_tuple(PyDbSubentId(startVertexSubentId), PyDbSubentId(endVertexSubentId), pylist);
}

boost::python::tuple PyDbAssocPersSubentIdPE::getSplineEdgeVertexSubentities(const PyDbEntity& pEntity, const PyDbSubentId& subentId) const
{
    PyAutoLockGIL lock;
    AcDbSubentId startVertexSubentId;
    AcDbSubentId endVertexSubentId;
    AcArray<AcDbSubentId> controlPointSubentIds;
    AcArray<AcDbSubentId> fitPointSubentIds;
    PyThrowBadEs(impObj()->getSplineEdgeVertexSubentities(pEntity.impObj(), *subentId.impObj(), startVertexSubentId, endVertexSubentId, controlPointSubentIds, fitPointSubentIds));
    boost::python::list pycontrolPointSubentIds;
    for (const auto& item : controlPointSubentIds)
        pycontrolPointSubentIds.append(PyDbSubentId(item));
    boost::python::list pyfitPointSubentIds;
    for (const auto& item : fitPointSubentIds)
        pyfitPointSubentIds.append(PyDbSubentId(item));
    return boost::python::make_tuple(PyDbSubentId(startVertexSubentId), PyDbSubentId(endVertexSubentId), pycontrolPointSubentIds, pyfitPointSubentIds);
}

PyGeEntity3d PyDbAssocPersSubentIdPE::getSubentityGeometry(const PyDbEntity& pEntity, const PyDbSubentId& subentId) const
{
    AcGeEntity3d* gent = nullptr;
    PyThrowBadEs(impObj()->getSubentityGeometry(pEntity.impObj(), *subentId.impObj(), gent));
    return PyGeEntity3d(gent);
}

AcGePoint3d PyDbAssocPersSubentIdPE::getVertexSubentityGeometry(const PyDbEntity& pEntity, const PyDbSubentId& subentId) const
{
    AcGePoint3d gent;
    PyThrowBadEs(impObj()->getVertexSubentityGeometry(pEntity.impObj(), *subentId.impObj(), gent));
    return gent;
}

PyGeCurve3d PyDbAssocPersSubentIdPE::getEdgeSubentityGeometry(const PyDbEntity& pEntity, const PyDbSubentId& subentId) const
{
    AcGeCurve3d* gent = nullptr;
    PyThrowBadEs(impObj()->getEdgeSubentityGeometry(pEntity.impObj(), *subentId.impObj(), gent));
    return PyGeCurve3d(gent);
}

PyGeSurface PyDbAssocPersSubentIdPE::getFaceSubentityGeometry(const PyDbEntity& pEntity, const PyDbSubentId& subentId) const
{
    AcGeSurface* gent = nullptr;
    PyThrowBadEs(impObj()->getFaceSubentityGeometry(pEntity.impObj(), *subentId.impObj(), gent));
    return PyGeSurface(gent);
}

PyRxClass PyDbAssocPersSubentIdPE::desc()
{
    return PyRxClass(AcDbAssocPersSubentIdPE::desc(), false);
}

std::string PyDbAssocPersSubentIdPE::className()
{
    return "AcDbAssocPersSubentIdPE";
}

AcDbAssocPersSubentIdPE* PyDbAssocPersSubentIdPE::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcDbAssocPersSubentIdPE*>(m_pyImp.get());
}
