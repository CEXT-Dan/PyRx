#include "stdafx.h"
#include "PyDbAssocAction.h"

using namespace boost::python;

//-----------------------------------------------------------------------------------
//PyDbAssocDependency
void makePyDbAssocDependencyWrapper()
{
    constexpr const std::string_view ctords = "Overloads:\n"
        "- None: Any\n"
        "- createImpObject: bool\n"
        "- id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode, erased: bool\n";


    PyDocString DS("PyDb.AssocDependency");
    class_<PyDbAssocDependency, bases<PyDbObject>>("AssocDependency")
        .def(init<>())
        .def(init<bool>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.CTOR(ctords, 2501)))

        .def("className", &PyDbAssocDependency::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbAssocDependency::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyDbAssocDependency::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbAssocDependency::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyDbAssocDependency::PyDbAssocDependency()
    : PyDbAssocDependency(new AcDbAssocDependency(), true)
{
}

PyDbAssocDependency::PyDbAssocDependency(bool createImpObject)
#if defined(_BRXTARGET)
    : PyDbAssocDependency(new AcDbAssocDependency(), true)
#else
    : PyDbAssocDependency(new AcDbAssocDependency(createImpObject ? AcDbAssocCreateImpObject::kAcDbAssocCreateImpObject : AcDbAssocCreateImpObject::kAcDbAssocDoNotCreateImpObject), true)
#endif
{
#if defined(_BRXTARGET)
    throw PyNotimplementedByHost();
#endif
}

PyDbAssocDependency::PyDbAssocDependency(const PyDbObjectId& id)
    : PyDbAssocDependency(openAcDbObject<AcDbAssocDependency>(id), false)
{
}

PyDbAssocDependency::PyDbAssocDependency(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbAssocDependency(openAcDbObject<AcDbAssocDependency>(id, mode), false)
{

}

PyDbAssocDependency::PyDbAssocDependency(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbAssocDependency(openAcDbObject<AcDbAssocDependency>(id, mode, erased), false)
{
}

PyDbAssocDependency::PyDbAssocDependency(AcDbAssocDependency* ptr, bool autoDelete)
    : PyDbObject(ptr, autoDelete)
{
}

PyRxClass PyDbAssocDependency::desc()
{
    return PyRxClass(AcDbAssocAction::desc(), false);
}

std::string PyDbAssocDependency::className()
{
    return "AcDbAssocAction";
}

PyDbAssocDependency PyDbAssocDependency::cloneFrom(const PyRxObject& src)
{
    return PyDbObjectCloneFrom<PyDbAssocDependency, AcDbAssocDependency>(src);
}

PyDbAssocDependency PyDbAssocDependency::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbAssocDependency>(src);
}

AcDbAssocDependency* PyDbAssocDependency::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbAssocDependency*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//PyDbAssocAction
void makePyDbAssocActionWrapper()
{
    constexpr const std::string_view ctords = "Overloads:\n"
        "- None: Any\n"
        "- createImpObject: bool\n"
        "- id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode, erased: bool\n";


    PyDocString DS("PyDb.AssocAction");
    class_<PyDbAssocAction, bases<PyDbObject>>("AssocAction")
        .def(init<>())
        .def(init<bool>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.CTOR(ctords, 2501)))

        .def("className", &PyDbAssocAction::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbAssocAction::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyDbAssocAction::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbAssocAction::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyDbAssocAction::PyDbAssocAction()
    : PyDbAssocAction(new AcDbAssocAction(), true)
{
}

PyDbAssocAction::PyDbAssocAction(bool createImpObject)
#if defined(_BRXTARGET)
    : PyDbAssocAction(new AcDbAssocAction(), true)
#else
    : PyDbAssocAction(new AcDbAssocAction(createImpObject ? AcDbAssocCreateImpObject::kAcDbAssocCreateImpObject : AcDbAssocCreateImpObject::kAcDbAssocDoNotCreateImpObject), true)
#endif
{
#if defined(_BRXTARGET)
    throw PyNotimplementedByHost();
#endif
}

PyDbAssocAction::PyDbAssocAction(const PyDbObjectId& id)
    : PyDbAssocAction(openAcDbObject<AcDbAssocAction>(id), false)
{
}

PyDbAssocAction::PyDbAssocAction(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbAssocAction(openAcDbObject<AcDbAssocAction>(id, mode), false)
{

}

PyDbAssocAction::PyDbAssocAction(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbAssocAction(openAcDbObject<AcDbAssocAction>(id, mode, erased), false)
{
}

PyDbAssocAction::PyDbAssocAction(AcDbAssocAction* ptr, bool autoDelete)
    : PyDbObject(ptr, autoDelete)
{
}

PyDbObjectId PyDbAssocAction::actionBody() const
{
    return PyDbObjectId(impObj()->actionBody());
}

void PyDbAssocAction::setActionBody(const PyDbObjectId& actionBodyId) const
{
    PyThrowBadEs(impObj()->setActionBody(actionBodyId.m_id));
}

bool PyDbAssocAction::isActionBodyAProxy() const
{
    return impObj()->isActionBodyAProxy();
}

AcDbAssocStatus PyDbAssocAction::status() const
{
    return impObj()->status();
}

void PyDbAssocAction::setStatus1(AcDbAssocStatus newStatus) const
{
    PyThrowBadEs(impObj()->setStatus(newStatus));
}

void PyDbAssocAction::setStatus2(AcDbAssocStatus newStatus, bool notifyOwningNetwork, bool setInOwnedActions) const
{
    PyThrowBadEs(impObj()->setStatus(newStatus, notifyOwningNetwork, setInOwnedActions));
}

PyDbObjectId PyDbAssocAction::owningNetwork() const
{
    return PyDbObjectId(impObj()->owningNetwork());
}

void PyDbAssocAction::setOwningNetwork(const PyDbObjectId& networkId, bool alsoSetAsDatabaseOwner) const
{
    PyThrowBadEs(impObj()->setOwningNetwork(networkId.m_id, alsoSetAsDatabaseOwner));
}

boost::python::list PyDbAssocAction::getDependencies(bool readDependenciesWanted, bool writeDependenciesWanted) const
{
    PyAutoLockGIL lock;
    AcDbObjectIdArray ids;
    PyThrowBadEs(impObj()->getDependencies(readDependenciesWanted, writeDependenciesWanted,ids));
    return ObjectIdArrayToPyList(ids);
}

void PyDbAssocAction::addDependency(const PyDbObjectId& actionBodyId, bool setThisActionAsOwningAction) const
{
    PyThrowBadEs(impObj()->addDependency(actionBodyId.m_id, setThisActionAsOwningAction));
}

PyDbObjectId PyDbAssocAction::appendDependency(const PyRxClass& pDependencyClass, const PyRxClass& pDependencyBodyClass, bool isReadDep, bool isWriteDep, int order) const
{
    PyDbObjectId id;
    PyThrowBadEs(impObj()->addDependency(pDependencyClass.impObj(), pDependencyBodyClass.impObj(), isReadDep, isWriteDep, order, id.m_id));
    return id;
}

void PyDbAssocAction::removeDependency(const PyDbObjectId& dependencyId, bool alsoEraseIt) const
{
    PyThrowBadEs(impObj()->removeDependency(dependencyId.m_id, alsoEraseIt));
}

void PyDbAssocAction::removeAllDependencies(bool alsoEraseThem) const
{
    PyThrowBadEs(impObj()->removeAllDependencies(alsoEraseThem));
}

boost::python::list PyDbAssocAction::getDependentObjects(bool readDependenciesWanted, bool writeDependenciesWanted) const
{
    PyAutoLockGIL lock;
    AcDbObjectIdArray ids;
    PyThrowBadEs(impObj()->getDependentObjects(readDependenciesWanted, writeDependenciesWanted, ids));
    return ObjectIdArrayToPyList(ids);
}

PyDbObjectId PyDbAssocAction::getActionBody(const PyDbObjectId& actionId)
{
    return PyDbObjectId(AcDbAssocAction::actionBody(actionId.m_id));
}

PyRxClass PyDbAssocAction::desc()
{
    return PyRxClass(AcDbAssocAction::desc(), false);
}

std::string PyDbAssocAction::className()
{
    return "AcDbAssocAction";
}

PyDbAssocAction PyDbAssocAction::cloneFrom(const PyRxObject& src)
{
    return PyDbObjectCloneFrom<PyDbAssocAction, AcDbAssocAction>(src);
}

PyDbAssocAction PyDbAssocAction::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbAssocAction>(src);
}

AcDbAssocAction* PyDbAssocAction::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbAssocAction*>(m_pyImp.get());
}
