#include "stdafx.h"
#include "PyDbProtocolExtensions.h"


#include "dbJoinEntityPE.h"
#include "PyDbEntity.h"

using namespace boost::python;
void makePyDbJoinEntityPEWrapper()
{
#if _ZRXTARGET > 240 || _GRXTARGET > 240
    PyDocString DS("JoinEntityPE");
    class_<PyDbJoinEntityPE, bases<PyRxObject>>("JoinEntityPE", boost::python::no_init)
        .def(init<const PyRxObject&>())
        .def("joinEntity", &PyDbJoinEntityPE::joinEntity1)
        .def("joinEntity", &PyDbJoinEntityPE::joinEntity2, DS.ARGS({ "primaryEntity : PyDb.Entity" , "secondaryEntity : PyDb.Entity", "tol : PyGe.Tol=default" }))
        .def("joinEntities", &PyDbJoinEntityPE::joinEntities1)
        .def("joinEntities", &PyDbJoinEntityPE::joinEntities2, DS.ARGS({ "primaryEntity : PyDb.Entity" , "secondaryEntities : list[PyDb.Entity]", "tol : PyGe.Tol=default" }))
        .def("desc", &PyDbJoinEntityPE::desc, DS.SARGS()).staticmethod("desc")
        .def("className", &PyDbJoinEntityPE::className, DS.SARGS()).staticmethod("className")
        ;
#endif
}

#if _ZRXTARGET > 240 || _GRXTARGET > 240
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
    return impObj()->joinEntity(pPrimaryEntity.impObj(), pSecondaryEntity.impObj(), tol) == eOk;
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
    for (auto item : pyents)
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