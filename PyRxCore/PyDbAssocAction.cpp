#include "stdafx.h"
#include "PyDbAssocAction.h"
#include "PyDbIdMapping.h"
#include "PyDbEval.h"

using namespace boost::python;

//-----------------------------------------------------------------------------------
//PyDbActionsToEvaluateCallback
void makePyDbActionsToEvaluateCallbackWrapper()
{
    PyDocString DS("ActionsToEvaluateCallback");
    class_<PyDbActionsToEvaluateCallback>("ActionsToEvaluateCallback")
        .def(init<>())
        .def("needsToEvaluate", &PyDbActionsToEvaluateCallback::needsToEvaluateWr, DS.ARGS({ "objectId: PyDb.ObjectId","newStatus: PyDb.AssocStatus", "ownedActionsAlso: bool" }))
        .def("className", &PyDbActionsToEvaluateCallback::className, DS.SARGS()).staticmethod("className")
        ;
}

#if defined(_BRXTARGET260)
void PyDbActionsToEvaluateCallback::needsToEvaluate(const AcDbObjectId objectId, AcDbAssocStatus newStatus, bool ownedActionsAlso /*= true*/)
{
    if (reg_needsToEvaluate)
    {
        PyDbObjectId pyid(objectId);
        needsToEvaluateWr(pyid, newStatus, ownedActionsAlso);
    }
}
#else
void PyDbActionsToEvaluateCallback::needsToEvaluate(const AcDbObjectId& objectId, AcDbAssocStatus newStatus, bool ownedActionsAlso /*= true*/)
{
    if (reg_needsToEvaluate)
    {
        PyDbObjectId pyid(objectId);
        needsToEvaluateWr(pyid, newStatus, ownedActionsAlso);
    }
}
#endif

void PyDbActionsToEvaluateCallback::needsToEvaluateWr(const PyDbObjectId& objectId, AcDbAssocStatus newStatus, bool ownedActionsAlso)
{
    PyAutoLockGIL lock;
    try
    {
        if (const override& f = get_override("needsToEvaluate"))
            f(objectId, newStatus, ownedActionsAlso);
        else
            reg_needsToEvaluate = false;
    }
    catch (...)
    {
        reg_needsToEvaluate = false;
        printExceptionMsg();
    }
}

std::string PyDbActionsToEvaluateCallback::className()
{
    return "AcDbActionsToEvaluateCallback";
}

//-----------------------------------------------------------------------------------
//PyDbAssocEvaluationCallback
void makePyDbAssocEvaluationCallbackWrapper()
{
    PyDocString DS("AssocEvaluationCallback");
    class_<PyDbAssocEvaluationCallback>("AssocEvaluationCallback")
        .def(init<>())
        .def("beginActionEvaluation", &PyDbAssocEvaluationCallback::beginActionEvaluation, DS.ARGS({ "action: PyDb.AssocAction" }))
        .def("endActionEvaluation", &PyDbAssocEvaluationCallback::endActionEvaluation, DS.ARGS({ "action: PyDb.AssocAction" }))
        .def("className", &PyDbAssocEvaluationCallback::className, DS.SARGS()).staticmethod("className")
        ;
}

AcDbAssocEvaluationMode PyDbAssocEvaluationCallback::evaluationMode() const
{
    return AcDbAssocEvaluationCallback::evaluationMode();
}

void PyDbAssocEvaluationCallback::beginActionEvaluation(AcDbAssocAction* pAction)
{
    if (reg_beginActionEvaluation)
    {
        PyDbAssocAction pyAction(pAction, false);
        beginActionEvaluationWr(pyAction);
    }
}

void PyDbAssocEvaluationCallback::endActionEvaluation(AcDbAssocAction* pAction)
{
    if (reg_endActionEvaluation)
    {
        PyDbAssocAction pyAction(pAction, false);
        endActionEvaluationWr(pyAction);
    }
}

void PyDbAssocEvaluationCallback::setActionEvaluationErrorStatus(AcDbAssocAction* pAction, Acad::ErrorStatus errorStatus, const AcDbObjectId& objectId /*= AcDbObjectId::kNull*/, AcDbObject* pObject /*= NULL*/, void* pErrorInfo /*= NULL*/)
{
    PyThrowBadEs(eNotImplementedYet);
}

void PyDbAssocEvaluationCallback::beginActionEvaluationUsingObject(AcDbAssocAction* pAction, const AcDbObjectId& objectId, bool objectIsGoingToBeUsed, bool objectIsGoingToBeModified, AcDbObject*& pSubstituteObject)
{
    PyThrowBadEs(eNotImplementedYet);
}

void PyDbAssocEvaluationCallback::endActionEvaluationUsingObject(AcDbAssocAction* pAction, const AcDbObjectId& objectId, AcDbObject* pObject)
{
    PyThrowBadEs(eNotImplementedYet);
}

void PyDbAssocEvaluationCallback::allDependentActionsMarkedToEvaluate(AcDbAssocNetwork* /*pNetwork*/)
{
    PyThrowBadEs(eNotImplementedYet);
}

AcDbAssocDraggingState PyDbAssocEvaluationCallback::draggingState() const
{
    return AcDbAssocEvaluationCallback::draggingState();
}

bool PyDbAssocEvaluationCallback::cancelActionEvaluation()
{
    return AcDbAssocEvaluationCallback::cancelActionEvaluation();
}

AcDbEvalContext* PyDbAssocEvaluationCallback::getAdditionalData() const
{
    return AcDbAssocEvaluationCallback::getAdditionalData();
}

AcDbAssocTransformationType PyDbAssocEvaluationCallback::getTransformationType() const
{
    return AcDbAssocEvaluationCallback::getTransformationType();
}

void PyDbAssocEvaluationCallback::beginActionEvaluationWr(const PyDbAssocAction& pAction)
{
    PyAutoLockGIL lock;
    try
    {
        if (const override& f = get_override("beginActionEvaluation"))
            f(pAction);
        else
            reg_beginActionEvaluation = false;
    }
    catch (...)
    {
        reg_beginActionEvaluation = false;
        printExceptionMsg();
    }
}

void PyDbAssocEvaluationCallback::endActionEvaluationWr(const PyDbAssocAction& pAction)
{
    PyAutoLockGIL lock;
    try
    {
        if (const override& f = get_override("endActionEvaluation"))
            f(pAction);
        else
            reg_endActionEvaluation = false;
    }
    catch (...)
    {
        reg_endActionEvaluation = false;
        printExceptionMsg();
    }
}

std::string PyDbAssocEvaluationCallback::className()
{
    return "AcDbAssocEvaluationCallback";
}

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

    PyDocString DS("AssocDependency");
    class_<PyDbAssocDependency, bases<PyDbObject>>("AssocDependency")
        .def(init<>())
        .def(init<bool>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.CTOR(ctords)))
        .def("dependencyBody", &PyDbAssocDependency::dependencyBody, DS.ARGS())
        .def("setDependencyBody", &PyDbAssocDependency::setDependencyBody, DS.ARGS({"dependencyBodyId: PyDb.ObjectId"}))
        .def("status", &PyDbAssocDependency::status, DS.ARGS())
        .def("setStatus", &PyDbAssocDependency::setStatus, DS.ARGS({ "newStatus: PyDb.AssocStatus", "notifyOwningAction: bool"}))
        .def("isReadDependency", &PyDbAssocDependency::isReadDependency, DS.ARGS())
        .def("isWriteDependency", &PyDbAssocDependency::isWriteDependency, DS.ARGS())
        .def("setIsReadDependency", &PyDbAssocDependency::setIsReadDependency, DS.ARGS({ "yesNo: bool" }))
        .def("setIsWriteDependency", &PyDbAssocDependency::setIsWriteDependency, DS.ARGS({ "yesNo: bool" }))
        .def("isObjectStateDependent", &PyDbAssocDependency::isObjectStateDependent, DS.ARGS())
        .def("setIsObjectStateDependent", &PyDbAssocDependency::setIsObjectStateDependent, DS.ARGS({ "yesNo: bool" }))
        .def("order", &PyDbAssocDependency::order, DS.ARGS())
        .def("setOrder", &PyDbAssocDependency::setOrder, DS.ARGS({ "newOrder: int" }))
        .def("owningAction", &PyDbAssocDependency::owningAction, DS.ARGS())
        .def("setOwningAction", &PyDbAssocDependency::setOwningAction, DS.ARGS({ "actionId: PyDb.ObjectId" }))
        .def("isDependentOnCompoundObject", &PyDbAssocDependency::isDependentOnCompoundObject, DS.ARGS())
        .def("prevDependencyOnObject", &PyDbAssocDependency::prevDependencyOnObject, DS.ARGS())
        .def("nextDependencyOnObject", &PyDbAssocDependency::nextDependencyOnObject, DS.ARGS())
        .def("isAttachedToObject", &PyDbAssocDependency::isAttachedToObject, DS.ARGS())
        .def("dependentOnObjectStatus", &PyDbAssocDependency::dependentOnObjectStatus, DS.ARGS())
        .def("detachFromObject", &PyDbAssocDependency::detachFromObject, DS.ARGS())
        .def("updateDependentOnObject", &PyDbAssocDependency::updateDependentOnObject, DS.ARGS())
        .def("isDelegatingToOwningAction", &PyDbAssocDependency::isDelegatingToOwningAction, DS.ARGS())
        .def("setIsDelegatingToOwningAction", &PyDbAssocDependency::setIsDelegatingToOwningAction, DS.ARGS({ "yesNo: bool" }))
        .def("hasCachedValue", &PyDbAssocDependency::hasCachedValue, DS.ARGS())
        .def("isRelevantChange", &PyDbAssocDependency::isRelevantChange, DS.ARGS())
        .def("isDependentOnTheSameThingAs", &PyDbAssocDependency::isDependentOnTheSameThingAs, DS.ARGS({"otherDependency: PyDb.AssocDependency"}))
        .def("isDependentOnObjectReadOnly", &PyDbAssocDependency::isDependentOnObjectReadOnly, DS.ARGS())
        .def("isEqualTo", &PyDbAssocDependency::isEqualTo, DS.ARGS({ "otherDependency: PyDb.AssocDependency" }))
        .def("isActionEvaluationInProgress", &PyDbAssocDependency::isActionEvaluationInProgress, DS.ARGS())
        .def("evaluate", &PyDbAssocDependency::evaluate, DS.ARGS())
        .def("erased", &PyDbAssocDependency::erased, DS.ARGS({"dbObj: PyDb.DbObject", "isErasing: bool"}))
        .def("modified", &PyDbAssocDependency::modified, DS.ARGS({ "dbObj: PyDb.DbObject" }))
        .def("copied", &PyDbAssocDependency::copied, DS.ARGS({ "dbObj: PyDb.DbObject", "pNewObj: PyDb.DbObject" }))
        .def("setPrevDependencyOnObject", &PyDbAssocDependency::setPrevDependencyOnObject, DS.ARGS({ "depId: PyDb.ObjectId" }))
        .def("setNextDependencyOnObject", &PyDbAssocDependency::setNextDependencyOnObject, DS.ARGS({ "depId: PyDb.ObjectId" }))
        .def("getFirstDependencyOnObject", &PyDbAssocDependency::getFirstDependencyOnObject, DS.SARGS({ "pObject: PyRx.DbObject" })).staticmethod("getFirstDependencyOnObject")
        .def("getDependenciesOnObject", &PyDbAssocDependency::getDependenciesOnObject, DS.SARGS({ "pObject: PyRx.DbObject","readDependenciesWanted: bool", "writeDependenciesWanted: bool"})).staticmethod("getDependenciesOnObject")
        .def("notifyDependenciesOnObject", &PyDbAssocDependency::notifyDependenciesOnObject, DS.SARGS({ "pObject: PyRx.DbObject","newStatus: PyDb.AssocStatus"})).staticmethod("notifyDependenciesOnObject")
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

PyDbObjectId PyDbAssocDependency::dependencyBody() const
{
    return PyDbObjectId(impObj()->dependencyBody());
}

void PyDbAssocDependency::setDependencyBody(const PyDbObjectId& dependencyBodyId) const
{
    PyThrowBadEs(impObj()->setDependencyBody(dependencyBodyId.m_id));
}

AcDbAssocStatus PyDbAssocDependency::status() const
{
    return impObj()->status();
}

void PyDbAssocDependency::setStatus(AcDbAssocStatus newStatus, bool notifyOwningAction) const
{
    PyThrowBadEs(impObj()->setStatus(newStatus, notifyOwningAction));
}

bool PyDbAssocDependency::isReadDependency() const
{
    return impObj()->isReadDependency();
}

bool PyDbAssocDependency::isWriteDependency() const
{
    return impObj()->isWriteDependency();
}

void PyDbAssocDependency::setIsReadDependency(bool yesNo) const
{
    impObj()->setIsReadDependency(yesNo);
}

void PyDbAssocDependency::setIsWriteDependency(bool yesNo) const
{
    impObj()->setIsWriteDependency(yesNo);
}

bool PyDbAssocDependency::isObjectStateDependent() const
{
    return impObj()->isObjectStateDependent();
}

void PyDbAssocDependency::setIsObjectStateDependent(bool yesNo) const
{
    impObj()->setIsObjectStateDependent(yesNo);
}

int PyDbAssocDependency::order() const
{
    return impObj()->order();
}

void PyDbAssocDependency::setOrder(int newOrder) const
{
    impObj()->setOrder(newOrder);
}

PyDbObjectId PyDbAssocDependency::owningAction() const
{
    return PyDbObjectId(impObj()->owningAction());
}

void PyDbAssocDependency::setOwningAction(const PyDbObjectId& actionId) const
{
    impObj()->setOwningAction(actionId.m_id);
}

PyDbObjectId PyDbAssocDependency::dependentOnObject() const
{
    return PyDbObjectId(impObj()->dependentOnObject());
}

bool PyDbAssocDependency::isDependentOnCompoundObject() const
{
    return impObj()->isDependentOnCompoundObject();
}

PyDbObjectId PyDbAssocDependency::prevDependencyOnObject() const
{
    return PyDbObjectId(impObj()->prevDependencyOnObject());
}

PyDbObjectId PyDbAssocDependency::nextDependencyOnObject() const
{
    return PyDbObjectId(impObj()->nextDependencyOnObject());
}

bool PyDbAssocDependency::isAttachedToObject() const
{
    return impObj()->isAttachedToObject();
}

Acad::ErrorStatus PyDbAssocDependency::dependentOnObjectStatus() const
{
    return impObj()->dependentOnObjectStatus();
}

void PyDbAssocDependency::detachFromObject() const
{
    PyThrowBadEs(impObj()->detachFromObject());
}

void PyDbAssocDependency::updateDependentOnObject() const
{
    PyThrowBadEs(impObj()->updateDependentOnObject());
}

bool PyDbAssocDependency::isDelegatingToOwningAction() const
{
    return impObj()->isDelegatingToOwningAction();
}

void PyDbAssocDependency::setIsDelegatingToOwningAction(bool yesNo)
{
    impObj()->setIsDelegatingToOwningAction(yesNo);
}

bool PyDbAssocDependency::hasCachedValue() const
{
    return impObj()->hasCachedValue();
}

bool PyDbAssocDependency::isRelevantChange() const
{
    return impObj()->isRelevantChange();
}

bool PyDbAssocDependency::isDependentOnTheSameThingAs(const PyDbAssocDependency& pOtherDependency) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost{};
#else
    return impObj()->isDependentOnTheSameThingAs(pOtherDependency.impObj());
#endif
}

bool PyDbAssocDependency::isDependentOnObjectReadOnly() const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost{};
#else
    return impObj()->isDependentOnObjectReadOnly();
#endif
}

bool PyDbAssocDependency::isEqualTo(const PyDbAssocDependency& pOtherDependency) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost{};
#else
    return impObj()->isEqualTo(pOtherDependency.impObj());
#endif
}

bool PyDbAssocDependency::isActionEvaluationInProgress() const
{
    return impObj()->isActionEvaluationInProgress();
}

void PyDbAssocDependency::evaluate() const
{
    impObj()->evaluate();
}

void PyDbAssocDependency::erased(const PyDbObject& dbObj, Adesk::Boolean isErasing) const
{
    impObj()->erased(dbObj.impObj(), isErasing);
}

void PyDbAssocDependency::modified(const PyDbObject& dbObj) const
{
    impObj()->modified(dbObj.impObj());
}

void PyDbAssocDependency::copied(const PyDbObject& dbObj, const PyDbObject& pNewObj) const
{
    impObj()->copied(dbObj.impObj(), pNewObj.impObj());
}

void PyDbAssocDependency::setPrevDependencyOnObject(const PyDbObjectId& depId) const
{
#if defined(_BRXTARGET260) || defined(_GRXTARGET260) || defined(_IRXTARGET140) || defined(_ZRXTARGET260) || defined(_ARXTARGET240)
    throw PyNotimplementedByHost{};
#else
    impObj()->setPrevDependencyOnObject(depId.m_id);
#endif
}

void PyDbAssocDependency::setNextDependencyOnObject(const PyDbObjectId& depId) const
{
#if defined(_BRXTARGET260) || defined(_GRXTARGET260) || defined(_IRXTARGET140) || defined(_ZRXTARGET260) || defined(_ARXTARGET240)
    throw PyNotimplementedByHost{};
#else
    impObj()->setNextDependencyOnObject(depId.m_id);
#endif
}

PyDbObjectId PyDbAssocDependency::getFirstDependencyOnObject(const PyDbObject& pObject)
{
    PyDbObjectId id;
    PyThrowBadEs(AcDbAssocDependency::getFirstDependencyOnObject(pObject.impObj(), id.m_id));
    return id;
}

boost::python::list PyDbAssocDependency::getDependenciesOnObject(const PyDbObject& pObject, bool readDependenciesWanted, bool writeDependenciesWanted)
{
    AcDbObjectIdArray dependencyIds;
    PyThrowBadEs(AcDbAssocDependency::getDependenciesOnObject(pObject.impObj(), readDependenciesWanted, writeDependenciesWanted,dependencyIds));
    return ObjectIdArrayToPyList(dependencyIds);
}

void PyDbAssocDependency::notifyDependenciesOnObject(const PyDbObject& pObject, AcDbAssocStatus newStatus)
{
    PyThrowBadEs(AcDbAssocDependency::notifyDependenciesOnObject(pObject.impObj(), newStatus));
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
//PyDbAssocValueDependency
void makePyDbAssocValueDependencyWrapper()
{
#if !defined(_BRXTARGET240)
    constexpr const std::string_view ctords = "Overloads:\n"
        "- None: Any\n"
        "- createImpObject: bool\n"
        "- id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode, erased: bool\n";

    PyDocString DS("AssocValueDependency");
    class_<PyDbAssocValueDependency, bases<PyDbAssocDependency>>("AssocValueDependency")
        .def(init<>())
        .def(init<bool>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.CTOR(ctords)))
        .def("valueName", &PyDbAssocValueDependency::valueName, DS.ARGS())
        .def("setValueName", &PyDbAssocValueDependency::setValueName, DS.ARGS({ "val: str" }))
        .def("getDependentOnObjectValue", &PyDbAssocValueDependency::getDependentOnObjectValue, DS.ARGS())
        .def("setDependentOnObjectValue", &PyDbAssocValueDependency::setDependentOnObjectValue, DS.ARGS({ "val: PyDb.EvalVariant" }))
        .def("className", &PyDbAssocValueDependency::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbAssocValueDependency::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyDbAssocValueDependency::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbAssocValueDependency::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
#endif
}

#if !defined(_BRXTARGET240)
PyDbAssocValueDependency::PyDbAssocValueDependency()
    : PyDbAssocValueDependency(new AcDbAssocValueDependency(), true)
{
}

PyDbAssocValueDependency::PyDbAssocValueDependency(bool createImpObject)
#if defined(_BRXTARGET)
    : PyDbAssocValueDependency(new AcDbAssocValueDependency(), true)
#else
    : PyDbAssocValueDependency(new AcDbAssocValueDependency(createImpObject ? AcDbAssocCreateImpObject::kAcDbAssocCreateImpObject : AcDbAssocCreateImpObject::kAcDbAssocDoNotCreateImpObject), true)
#endif
{
#if defined(_BRXTARGET)
    throw PyNotimplementedByHost();
#endif
}

PyDbAssocValueDependency::PyDbAssocValueDependency(const PyDbObjectId& id)
    : PyDbAssocValueDependency(openAcDbObject<AcDbAssocValueDependency>(id), false)
{
}

PyDbAssocValueDependency::PyDbAssocValueDependency(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbAssocValueDependency(openAcDbObject<AcDbAssocValueDependency>(id, mode), false)
{
}

PyDbAssocValueDependency::PyDbAssocValueDependency(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbAssocValueDependency(openAcDbObject<AcDbAssocValueDependency>(id, mode, erased), false)
{
}

PyDbAssocValueDependency::PyDbAssocValueDependency(AcDbAssocValueDependency* ptr, bool autoDelete)
    : PyDbAssocDependency(ptr, autoDelete)
{
}

std::string PyDbAssocValueDependency::valueName() const
{
    return wstr_to_utf8(impObj()->valueName());
}

void PyDbAssocValueDependency::setValueName(const std::string& val) const
{
    PyThrowBadEs(impObj()->setValueName(utf8_to_wstr(val).c_str()));
}

PyDbEvalVariant PyDbAssocValueDependency::getDependentOnObjectValue() const
{
    AcDbEvalVariant objectValue;
    PyThrowBadEs(impObj()->getDependentOnObjectValue(objectValue));
    return PyDbEvalVariant(objectValue);
}

void PyDbAssocValueDependency::setDependentOnObjectValue(const PyDbEvalVariant& val) const
{
    PyThrowBadEs(impObj()->setDependentOnObjectValue(*val.impObj()));
}

PyRxClass PyDbAssocValueDependency::desc()
{
    return PyRxClass(AcDbAssocAction::desc(), false);
}

std::string PyDbAssocValueDependency::className()
{
    return "AcDbAssocAction";
}

PyDbAssocValueDependency PyDbAssocValueDependency::cloneFrom(const PyRxObject& src)
{
    return PyDbObjectCloneFrom<PyDbAssocValueDependency, AcDbAssocValueDependency>(src);
}

PyDbAssocValueDependency PyDbAssocValueDependency::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbAssocValueDependency>(src);
}

AcDbAssocValueDependency* PyDbAssocValueDependency::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbAssocValueDependency*>(m_pyImp.get());
}
#endif

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

    constexpr const std::string_view paramOverloads = "Overloads:\n"
        "- paramId: PyDb.ObjectId\n"
        "- paramName: str, paramClass: PyRx.RxClass, paramId: PyDb.ObjectId\n";

    constexpr const std::string_view removeActionsControllingObjectOverloads = "Overloads:\n"
        "- objectToRemoveActionsFrom: PyDb.ObjectId\n"
        "- objectToRemoveActionsFrom: PyDb.ObjectId, readOnlyDependencyHandling:bool, objectToRedirectReadOnlyDependenciesTo:PyDb.ObjectId\n";


    PyDocString DS("AssocAction");
    class_<PyDbAssocAction, bases<PyDbObject>>("AssocAction")
        .def(init<>())
        .def(init<bool>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.CTOR(ctords)))

        .def("actionBody", &PyDbAssocAction::actionBody, DS.ARGS())
        .def("setActionBody", &PyDbAssocAction::setActionBody, DS.ARGS({ "actionBodyId:PyDb.ObjectId" }))
        .def("isActionBodyAProxy", &PyDbAssocAction::isActionBodyAProxy, DS.ARGS())
        .def("status", &PyDbAssocAction::status, DS.ARGS())
        .def("setStatus", &PyDbAssocAction::setStatus1)
        .def("setStatus", &PyDbAssocAction::setStatus2, DS.ARGS({ "newStatus:PyDb.AssocStatus" ,"notifyOwningNetwork:bool = True","setInOwnedActions:bool = False" }))
        .def("owningNetwork", &PyDbAssocAction::owningNetwork, DS.ARGS())
        .def("setOwningNetwork", &PyDbAssocAction::setOwningNetwork, DS.ARGS({ "networkId:PyDb.ObjectId","alsoSetAsDatabaseOwner:bool" }))
        .def("getDependencies", &PyDbAssocAction::getDependencies, DS.ARGS({ "readDependenciesWanted:bool","writeDependenciesWanted:bool" }))
        .def("addDependency", &PyDbAssocAction::addDependency, DS.ARGS({ "actionBodyId:PyDb.ObjectId","setThisActionAsOwningAction:bool" }))
        .def("appendDependency", &PyDbAssocAction::appendDependency, DS.ARGS({ "dependencyClass:PyRx.RxClass","dependencyBodyClass:PyRx.RxClass","isReadDep:bool","isWriteDep:bool","order:int" }))
        .def("removeDependency", &PyDbAssocAction::removeDependency, DS.ARGS({ "dependencyId:PyDb.ObjectId","alsoEraseIt:bool" }))
        .def("removeAllDependencies", &PyDbAssocAction::removeAllDependencies, DS.ARGS({ "alsoEraseThem:bool" }))
        .def("getDependentObjects", &PyDbAssocAction::getDependentObjects, DS.ARGS({ "readDependenciesWanted:bool","writeDependenciesWanted:bool" }))
        .def("isOwnedDependency", &PyDbAssocAction::isOwnedDependency, DS.ARGS({ "dependency:PyDb.AssocDependency" }))
        .def("isExternalDependency", &PyDbAssocAction::isExternalDependency, DS.ARGS({ "dependency:PyDb.AssocDependency" }))
        .def("isRelevantDependencyChange", &PyDbAssocAction::isRelevantDependencyChange, DS.ARGS({ "dependency:PyDb.AssocDependency" }))
        .def("hasDependencyCachedValue", &PyDbAssocAction::hasDependencyCachedValue, DS.ARGS({ "dependency:PyDb.AssocDependency" }))
        .def("areDependenciesOnTheSameThing", &PyDbAssocAction::areDependenciesOnTheSameThing, DS.ARGS({ "dependency1:PyDb.AssocDependency", "dependency2:PyDb.AssocDependency" }))
        .def("areDependenciesEqual", &PyDbAssocAction::areDependenciesEqual, DS.ARGS({ "dependency1:PyDb.AssocDependency", "dependency2:PyDb.AssocDependency" }))
        .def("dependentObjectCloned", &PyDbAssocAction::dependentObjectCloned, DS.ARGS({ "dependency:PyDb.AssocDependency", "dbObj:PyDb.DbObject","newObj:PyDb.DbObject" }))
        .def("addMoreObjectsToDeepClone", &PyDbAssocAction::addMoreObjectsToDeepClone, DS.ARGS({ "idMap:PyDb.PIdMapping","additionalObjectsToClone:list[PyDb.DbObject]" }))
        .def("postProcessAfterDeepClone", &PyDbAssocAction::postProcessAfterDeepClone, DS.ARGS({ "idMap:PyDb.PIdMapping" }))
        .def("postProcessAfterDeepCloneCancel", &PyDbAssocAction::postProcessAfterDeepCloneCancel, DS.ARGS({ "idMap:PyDb.PIdMapping" }))
        .def("isActionEvaluationInProgress", &PyDbAssocAction::isActionEvaluationInProgress, DS.ARGS())
        .def("evaluateDependencies", &PyDbAssocAction::evaluateDependencies, DS.ARGS())
        .def("evaluateDependency", &PyDbAssocAction::evaluateDependency, DS.ARGS({ "dependency:PyDb.AssocDependency" }))
        .def("ownedDependencyStatusChanged", &PyDbAssocAction::ownedDependencyStatusChanged, DS.ARGS({ "ownedDependency:PyDb.AssocDependency","previousStatus:PyDb.AssocStatus" }))
        .def("transformActionBy", &PyDbAssocAction::transformActionBy, DS.ARGS({ "transform:PyGe.AcGeMatrix3d" }))
        .def("isEqualTo", &PyDbAssocAction::isEqualTo, DS.ARGS({ "otherAction:PyDb.AssocAction" }))
        .def("evaluationPriority", &PyDbAssocAction::evaluationPriority, DS.ARGS())
        .def("getDependentActionsToEvaluate", &PyDbAssocAction::getDependentActionsToEvaluate, DS.ARGS({ "refActionsToEvaluateCallback:PyDb.ActionsToEvaluateCallback" }))
        .def("evaluate", &PyDbAssocAction::evaluate, DS.ARGS({ "refEvaluate:PyDb.ActionsToEvaluateCallback" }))
        .def("objectThatOwnsNetworkInstance", &PyDbAssocAction::objectThatOwnsNetworkInstance, DS.ARGS())
        .def("dragStatus", &PyDbAssocAction::dragStatus, DS.ARGS({ "status:PyDb.DragStat" }))
        .def("removeAllParams", &PyDbAssocAction::removeAllParams, DS.ARGS({ "alsoEraseThem:bool" }))
        .def("paramCount", &PyDbAssocAction::paramCount, DS.ARGS())
        .def("ownedParams", &PyDbAssocAction::ownedParams, DS.ARGS())
        .def("addParam", &PyDbAssocAction::addParam1)
        .def("addParam", &PyDbAssocAction::addParam2, DS.OVRL(paramOverloads))
        .def("removeParam", &PyDbAssocAction::addParam2, DS.ARGS({ "paramName:str","alsoEraseIt:bool" }))
        .def("paramsAtName", &PyDbAssocAction::paramsAtName, DS.ARGS({ "paramName:str" }))
        .def("paramAtName", &PyDbAssocAction::paramAtName1)
        .def("paramAtName", &PyDbAssocAction::paramAtName2, DS.ARGS({ "paramName:str", "index:int = 0" }))
        .def("paramAtIndex", &PyDbAssocAction::paramAtIndex, DS.ARGS({ "index:int" }))
        .def("ownedValueParamNames", &PyDbAssocAction::ownedValueParamNames, DS.ARGS())
        .def("getValueParamArray", &PyDbAssocAction::getValueParamArray, DS.ARGS({ "paramName:str" }))
        .def("getValueParam", &PyDbAssocAction::getValueParam, DS.ARGS({ "paramName:str","index:int" }))
        .def("setValueParamArray", &PyDbAssocAction::setValueParamArray, DS.ARGS({ "paramName:str","values:list[PyDb.EvalVariant]","expressions:list[str]","evaluatorIds:list[str]","silentMode:bool" }))
        .def("setValueParam", &PyDbAssocAction::setValueParam, DS.ARGS({ "paramName:str","value:PyDb.EvalVariant","expression:str","evaluatorId:str","silentMode:bool","valueIndex:int" }))
        .def("valueParamUnitType", &PyDbAssocAction::valueParamUnitType, DS.ARGS({ "paramName:str" }))
        .def("setValueParamUnitType", &PyDbAssocAction::setValueParamUnitType, DS.ARGS({ "paramName:str","unitType:PyDb.ValueUnitType" }))
        .def("removeValueParam", &PyDbAssocAction::removeValueParam, DS.ARGS({ "paramName:str" }))
        .def("valueParamInputVariables", &PyDbAssocAction::valueParamInputVariables, DS.ARGS({ "paramName:str" }))
        .def("setValueParamControlledObjectDep", &PyDbAssocAction::setValueParamControlledObjectDep, DS.ARGS({ "paramName:str","controlledObjectDepId:PyDb.ObjectId" }))
        .def("updateValueParamControlledObject", &PyDbAssocAction::updateValueParamControlledObject, DS.ARGS({ "paramName:str" }))
        .def("updateValueParamFromControlledObject", &PyDbAssocAction::updateValueParamFromControlledObject, DS.ARGS({ "paramName:str" }))
        .def("updateAllObjectsControlledByValueParams", &PyDbAssocAction::updateAllObjectsControlledByValueParams, DS.ARGS())
        .def("transformAllConstantGeometryParams", &PyDbAssocAction::transformAllConstantGeometryParams, DS.ARGS({ "transform:PyGe.Matrix3d" }))
        .def("scaleAllDistanceValueParams", &PyDbAssocAction::scaleAllDistanceValueParams, DS.ARGS({ "scaleFactor:float" }))

        .def("getActionsDependentOnObject", &PyDbAssocAction::getActionsDependentOnObject, DS.SARGS({ "pObject:PyDb.DbObject","readDependenciesWanted:bool","writeDependenciesWanted:bool" })).staticmethod("getActionsDependentOnObject")
        .def("removeActionsControllingObject", &PyDbAssocAction::removeActionsControllingObject1)
        .def("removeActionsControllingObject", &PyDbAssocAction::removeActionsControllingObject2, DS.SOVRL(removeActionsControllingObjectOverloads)).staticmethod("removeActionsControllingObject")
        .def("doesObjectHaveActiveActions", &PyDbAssocAction::doesObjectHaveActiveActions, DS.SARGS({ "pObject:PyDb.DbObject" })).staticmethod("doesObjectHaveActiveActions")
        .def("getActionBody", &PyDbAssocAction::getActionBody, DS.SARGS({ "actionId:PyDb.ObjectId" })).staticmethod("getActionBody")
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
    AcDbObjectIdArray ids;
    PyThrowBadEs(impObj()->getDependencies(readDependenciesWanted, writeDependenciesWanted, ids));
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
    AcDbObjectIdArray ids;
    PyThrowBadEs(impObj()->getDependentObjects(readDependenciesWanted, writeDependenciesWanted, ids));
    return ObjectIdArrayToPyList(ids);
}

bool PyDbAssocAction::isOwnedDependency(const PyDbAssocDependency& pDependency) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    return impObj()->isOwnedDependency(pDependency.impObj());
#endif
}

bool PyDbAssocAction::isExternalDependency(const PyDbAssocDependency& pDependency) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    return impObj()->isExternalDependency(pDependency.impObj());
#endif
}

bool PyDbAssocAction::isRelevantDependencyChange(const PyDbAssocDependency& pDependency) const
{
    return impObj()->isRelevantDependencyChange(pDependency.impObj());
}

bool PyDbAssocAction::hasDependencyCachedValue(const PyDbAssocDependency& pDependency) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    return impObj()->hasDependencyCachedValue(pDependency.impObj());
#endif
}

bool PyDbAssocAction::areDependenciesOnTheSameThing(const PyDbAssocDependency& pDependency1, const PyDbAssocDependency& pDependency2) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    return impObj()->areDependenciesOnTheSameThing(pDependency1.impObj(), pDependency2.impObj());
#endif
}

bool PyDbAssocAction::areDependenciesEqual(const PyDbAssocDependency& pDependency1, const PyDbAssocDependency& pDependency2) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    return impObj()->areDependenciesEqual(pDependency1.impObj(), pDependency2.impObj());
#endif
}

void PyDbAssocAction::dependentObjectCloned(const PyDbAssocDependency& pDependency, const PyDbObject& pDbObj, const PyDbObject& pNewObj) const
{
    impObj()->dependentObjectCloned(pDependency.impObj(), pDbObj.impObj(), pNewObj.impObj());
}

boost::python::list PyDbAssocAction::addMoreObjectsToDeepClone(const PyDbIdMapping& idMap, boost::python::list& additionalObjectsToClone) const
{
    PyAutoLockGIL lock;
    AcDbObjectIdArray ids = PyListToObjectIdArray(additionalObjectsToClone);
    PyThrowBadEs(impObj()->addMoreObjectsToDeepClone(*idMap.impObj(), ids));
    return ObjectIdArrayToPyList(ids);
}

void PyDbAssocAction::postProcessAfterDeepClone(PyDbIdMapping& idMap)
{
    PyThrowBadEs(impObj()->postProcessAfterDeepClone(*idMap.impObj()));
}

void PyDbAssocAction::postProcessAfterDeepCloneCancel(PyDbIdMapping& idMap)
{
    PyThrowBadEs(impObj()->postProcessAfterDeepCloneCancel(*idMap.impObj()));
}

bool PyDbAssocAction::isActionEvaluationInProgress() const
{
    return impObj()->isActionEvaluationInProgress();
}

void PyDbAssocAction::evaluateDependencies() const
{
    PyThrowBadEs(impObj()->evaluateDependencies());
}

void PyDbAssocAction::evaluateDependency(PyDbAssocDependency& pDependency) const
{
    impObj()->evaluateDependency(pDependency.impObj());
}

void PyDbAssocAction::ownedDependencyStatusChanged(PyDbAssocDependency& pOwnedDependency, AcDbAssocStatus previousStatus) const
{
    PyThrowBadEs(impObj()->ownedDependencyStatusChanged(pOwnedDependency.impObj(), previousStatus));
}

void PyDbAssocAction::transformActionBy(const AcGeMatrix3d& transform) const
{
    PyThrowBadEs(impObj()->transformActionBy(transform));
}

bool PyDbAssocAction::isEqualTo(const PyDbAssocAction& pOtherAction) const
{
    return impObj()->isEqualTo(pOtherAction.impObj());
}

AcDbAssocEvaluationPriority PyDbAssocAction::evaluationPriority() const
{
    return impObj()->evaluationPriority();
}

void PyDbAssocAction::getDependentActionsToEvaluate(PyDbActionsToEvaluateCallback& pActionsToEvaluateCallback) const
{
    impObj()->getDependentActionsToEvaluate(std::addressof(pActionsToEvaluateCallback));
}

void PyDbAssocAction::evaluate(PyDbAssocEvaluationCallback& pEvaluationCallback)
{
    impObj()->evaluate(std::addressof(pEvaluationCallback));
}

PyDbObjectId PyDbAssocAction::objectThatOwnsNetworkInstance() const
{
    return PyDbObjectId(impObj()->objectThatOwnsNetworkInstance());
}

void PyDbAssocAction::dragStatus(const AcDb::DragStat status) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    impObj()->dragStatus(status);
#endif
}

void PyDbAssocAction::removeAllParams(bool alsoEraseThem)
{
    PyThrowBadEs(impObj()->removeAllParams(alsoEraseThem));
}

int PyDbAssocAction::paramCount() const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    return impObj()->paramCount();
#endif
}

boost::python::list PyDbAssocAction::ownedParams() const
{
    return ObjectIdArrayToPyList(impObj()->ownedParams());
}

int PyDbAssocAction::addParam1(const PyDbObjectId& paramId) const
{
    int idx = -1;
    PyThrowBadEs(impObj()->addParam(paramId.m_id, idx));
    return idx;
}

int PyDbAssocAction::addParam2(const std::string& paramName, const PyRxClass& pParamClass, PyDbObjectId& paramId) const
{
    int idx = -1;
    PyThrowBadEs(impObj()->addParam(utf8_to_wstr(paramName).c_str(), pParamClass.impObj(), paramId.m_id, idx));
    return idx;
}

void PyDbAssocAction::removeParam(const PyDbObjectId& paramId, bool alsoEraseIt) const
{
    PyThrowBadEs(impObj()->removeParam(paramId.m_id, alsoEraseIt));
}

boost::python::list PyDbAssocAction::paramsAtName(const std::string& paramName) const
{
    return ObjectIdArrayToPyList(impObj()->paramsAtName(utf8_to_wstr(paramName).c_str()));
}

PyDbObjectId PyDbAssocAction::paramAtName1(const std::string& paramName) const
{
    return PyDbObjectId(impObj()->paramAtName(utf8_to_wstr(paramName).c_str()));
}

PyDbObjectId PyDbAssocAction::paramAtName2(const std::string& paramName, int index) const
{
    return PyDbObjectId(impObj()->paramAtName(utf8_to_wstr(paramName).c_str(), index));
}

PyDbObjectId PyDbAssocAction::paramAtIndex(int paramIndex) const
{
    return PyDbObjectId(impObj()->paramAtIndex(paramIndex));
}

boost::python::list PyDbAssocAction::ownedValueParamNames() const
{
    AcArray<AcString> paramNames;
    impObj()->ownedValueParamNames(paramNames);
    return AcStringArrayToPyList(paramNames);
}

boost::python::tuple PyDbAssocAction::getValueParamArray(const std::string& paramName) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    AcArray<AcDbEvalVariant> values;
    AcArray<AcString> expressions;
    AcArray<AcString> evaluatorIds;
    PyThrowBadEs(impObj()->getValueParamArray(utf8_to_wstr(paramName).c_str(), values, expressions, evaluatorIds));
    PyAutoLockGIL lock;
    boost::python::list pyvalues;
    for (const auto& item : values)
        pyvalues.append(PyDbEvalVariant(item));
    return boost::python::make_tuple(pyvalues, AcStringArrayToPyList(expressions), AcStringArrayToPyList(evaluatorIds));
#endif
}

boost::python::tuple PyDbAssocAction::getValueParam(const std::string& paramName, int idx) const
{
    AcDbEvalVariant value;
    AcString expression;
    AcString evaluatorId;
    PyThrowBadEs(impObj()->getValueParam(utf8_to_wstr(paramName).c_str(), value, expression, evaluatorId, idx));
    PyAutoLockGIL lock;;
    return boost::python::make_tuple(PyDbEvalVariant(value), wstr_to_utf8(expression), wstr_to_utf8(evaluatorId));
}

boost::python::list PyDbAssocAction::setValueParamArray(const std::string& paramName, const boost::python::list& values, const boost::python::list& expressions, const boost::python::list& evaluatorIds, bool silentMode) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    AcArray<AcDbEvalVariant> acvalues;
    for (const auto& item : py_list_to_std_vector<PyDbEvalVariant>(values))
        acvalues.append(*item.impObj());
    AcArray<AcString> acexpressions;
    for (const auto& item : py_list_to_std_vector<std::string>(expressions))
        acexpressions.append(utf8_to_wstr(item).c_str());
    AcArray<AcString> acevaluatorIds;
    for (const auto& item : py_list_to_std_vector<std::string>(evaluatorIds))
        acevaluatorIds.append(utf8_to_wstr(item).c_str());
    AcArray<AcString> errorMessage;
    PyThrowBadEs(impObj()->setValueParamArray(utf8_to_wstr(paramName).c_str(), acvalues, acexpressions, acevaluatorIds, errorMessage, silentMode));
    return AcStringArrayToPyList(errorMessage);
#endif
}

std::string PyDbAssocAction::setValueParam(const std::string& paramName, const PyDbEvalVariant& value, const std::string& expression, const std::string& evaluatorId, bool silentMode, int valueIndex) const
{
    AcString errorMessage;
    PyThrowBadEs(impObj()->setValueParam(utf8_to_wstr(paramName).c_str(), *value.impObj(), utf8_to_wstr(expression).c_str(), utf8_to_wstr(evaluatorId).c_str(), errorMessage, silentMode, valueIndex));
    return wstr_to_utf8(errorMessage);
}

AcValue::UnitType PyDbAssocAction::valueParamUnitType(const std::string& paramName) const
{
    return impObj()->valueParamUnitType(utf8_to_wstr(paramName).c_str());
}

void PyDbAssocAction::setValueParamUnitType(const std::string& paramName, AcValue::UnitType unitType) const
{
    PyThrowBadEs(impObj()->setValueParamUnitType(utf8_to_wstr(paramName).c_str(), unitType));
}

void PyDbAssocAction::removeValueParam(const std::string& paramName) const
{
    PyThrowBadEs(impObj()->removeValueParam(utf8_to_wstr(paramName).c_str()));
}

boost::python::list PyDbAssocAction::valueParamInputVariables(const std::string& paramName) const
{
    AcDbObjectIdArray variableIds;
    PyThrowBadEs(impObj()->valueParamInputVariables(utf8_to_wstr(paramName).c_str(), variableIds));
    return ObjectIdArrayToPyList(variableIds);
}

void PyDbAssocAction::setValueParamControlledObjectDep(const std::string& paramName, const PyDbObjectId& controlledObjectDepId) const
{
    PyThrowBadEs(impObj()->setValueParamControlledObjectDep(utf8_to_wstr(paramName).c_str(), controlledObjectDepId.m_id));
}

void PyDbAssocAction::updateValueParamControlledObject(const std::string& paramName) const
{
    PyThrowBadEs(impObj()->updateValueParamControlledObject(utf8_to_wstr(paramName).c_str()));
}

void PyDbAssocAction::updateValueParamFromControlledObject(const std::string& paramName) const
{
    PyThrowBadEs(impObj()->updateValueParamFromControlledObject(utf8_to_wstr(paramName).c_str()));
}

void PyDbAssocAction::updateAllObjectsControlledByValueParams() const
{
    PyThrowBadEs(impObj()->updateAllObjectsControlledByValueParams());
}

void PyDbAssocAction::transformAllConstantGeometryParams(const AcGeMatrix3d& transform) const
{
    PyThrowBadEs(impObj()->transformAllConstantGeometryParams(transform));
}

void PyDbAssocAction::scaleAllDistanceValueParams(double scaleFactor) const
{
    PyThrowBadEs(impObj()->scaleAllDistanceValueParams(scaleFactor));
}

boost::python::list PyDbAssocAction::getActionsDependentOnObject(const PyDbObject& pObject, bool readDependenciesWanted, bool writeDependenciesWanted)
{
    PyAutoLockGIL lock;
    AcDbObjectIdArray ids;
    PyThrowBadEs(AcDbAssocAction::getActionsDependentOnObject(pObject.impObj(), readDependenciesWanted, writeDependenciesWanted, ids));
    return ObjectIdArrayToPyList(ids);
}

void PyDbAssocAction::removeActionsControllingObject1(const PyDbObjectId& objectToRemoveActionsFrom)
{
#if defined(_ZRXTARGET260)
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(AcDbAssocAction::removeActionsControllingObject(objectToRemoveActionsFrom.m_id));
#endif
}

void PyDbAssocAction::removeActionsControllingObject2(const PyDbObjectId& objectToRemoveActionsFrom, int readOnlyDependencyHandling, const PyDbObjectId& objectToRedirectReadOnlyDependenciesTo)
{
#if defined(_ZRXTARGET260)
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(AcDbAssocAction::removeActionsControllingObject(objectToRemoveActionsFrom.m_id, readOnlyDependencyHandling, objectToRedirectReadOnlyDependenciesTo.m_id));
#endif
}

void PyDbAssocAction::markDependentActionsToEvaluate(const PyDbObjectId& actionId)
{
#if defined(_ZRXTARGET260)
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(AcDbAssocAction::markDependentActionsToEvaluate(actionId.m_id));
#endif
}

bool PyDbAssocAction::doesObjectHaveActiveActions(const PyDbObject& pObject)
{
#if defined(_ZRXTARGET260)
    throw PyNotimplementedByHost();
#else
    return AcDbAssocAction::doesObjectHaveActiveActions(pObject.impObj());
#endif
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

//-----------------------------------------------------------------------------------
//PyDbAssocNetwork
void makePyDbAssocNetworkWrapper()
{
    constexpr const std::string_view ctords = "Overloads:\n"
        "- None: Any\n"
        "- createImpObject: bool\n"
        "- id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode, erased: bool\n";

    PyDocString DS("AssocNetwork");
    class_<PyDbAssocNetwork, bases<PyDbAssocAction>>("AssocNetwork")
        .def(init<>())
        .def(init<bool>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.CTOR(ctords)))
        .def("getActions", &PyDbAssocNetwork::getActions, DS.ARGS())
        .def("getActionsToEvaluate", &PyDbAssocNetwork::getActionsToEvaluate, DS.ARGS())
        .def("addAction", &PyDbAssocNetwork::addAction, DS.ARGS({ "actionId: PyDb.ObjectId","alsoSetAsDatabaseOwner: bool" }))
        .def("removeAction", &PyDbAssocNetwork::removeAction, DS.ARGS({ "actionId: PyDb.ObjectId","alsoEraseIt: bool" }))
        .def("removeAllActions", &PyDbAssocNetwork::removeAllActions, DS.ARGS({ "alsoEraseThem: bool" }))
        .def("ownedActionStatusChanged", &PyDbAssocNetwork::ownedActionStatusChanged, DS.ARGS({ "pOwnedAction: PyDb.AssocAction","previousStatus: PyDb.AssocStatus" }))
        .def("getInstanceFromDatabase", &PyDbAssocNetwork::getInstanceFromDatabase, DS.SARGS({ "db: PyDb.Database","createIfDoesNotExist: bool", "dictionaryKey:str" })).staticmethod("getInstanceFromDatabase")
        .def("getInstanceFromObject", &PyDbAssocNetwork::getInstanceFromObject, DS.SARGS({ "owningId:PyDb.ObjectId","createIfDoesNotExist:bool","addToTopLevelNetwork:bool","dictionaryKey:str" })).staticmethod("getInstanceFromObject")
        .def("removeInstanceFromDatabase", &PyDbAssocNetwork::removeInstanceFromDatabase, DS.SARGS({ "db:PyDb.Database","alsoEraseIt:bool","dictionaryKey:str" })).staticmethod("removeInstanceFromDatabase")
        .def("removeInstanceFromObject", &PyDbAssocNetwork::removeInstanceFromObject, DS.SARGS({ "owningObjectId:PyDb.ObjectId","alsoEraseIt: bool","dictionaryKey:str" })).staticmethod("removeInstanceFromObject")
        .def("assocNetworkIterator", &PyDbAssocNetwork::assocNetworkIterator, DS.ARGS())
        .def("className", &PyDbAssocNetwork::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbAssocNetwork::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyDbAssocNetwork::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbAssocNetwork::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyDbAssocNetwork::PyDbAssocNetwork()
    : PyDbAssocNetwork(new AcDbAssocNetwork(), true)
{
}

PyDbAssocNetwork::PyDbAssocNetwork(bool createImpObject)
#if defined(_BRXTARGET)
    : PyDbAssocNetwork(new AcDbAssocNetwork(), true)
#else
    : PyDbAssocNetwork(new AcDbAssocNetwork(createImpObject ? kAcDbAssocCreateImpObject : kAcDbAssocDoNotCreateImpObject), true)
#endif
{
#if defined(_BRXTARGET)
    throw PyNotimplementedByHost();
#endif
}

PyDbAssocNetwork::PyDbAssocNetwork(const PyDbObjectId& id)
    : PyDbAssocNetwork(openAcDbObject<AcDbAssocNetwork>(id), false)
{
}

PyDbAssocNetwork::PyDbAssocNetwork(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbAssocNetwork(openAcDbObject<AcDbAssocNetwork>(id, mode), false)
{
}

PyDbAssocNetwork::PyDbAssocNetwork(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbAssocNetwork(openAcDbObject<AcDbAssocNetwork>(id, mode, erased), false)
{
}

PyDbAssocNetwork::PyDbAssocNetwork(AcDbAssocNetwork* ptr, bool autoDelete)
    :PyDbAssocAction(ptr, autoDelete)
{
}

boost::python::list PyDbAssocNetwork::getActions() const
{
    return ObjectIdArrayToPyList(impObj()->getActions());
}

boost::python::list PyDbAssocNetwork::getActionsToEvaluate() const
{
    return ObjectIdArrayToPyList(impObj()->getActionsToEvaluate());
}

void PyDbAssocNetwork::addAction(const PyDbObjectId& actionId, bool alsoSetAsDatabaseOwner) const
{
    PyThrowBadEs(impObj()->addAction(actionId.m_id, alsoSetAsDatabaseOwner));
}

void PyDbAssocNetwork::removeAction(const PyDbObjectId& actionId, bool alsoEraseIt) const
{
    PyThrowBadEs(impObj()->removeAction(actionId.m_id, alsoEraseIt));
}

void PyDbAssocNetwork::addActions(const boost::python::list& actionIds, bool alsoSetAsDatabaseOwner) const
{
    PyThrowBadEs(impObj()->addActions(PyListToObjectIdArray(actionIds), alsoSetAsDatabaseOwner));
}

void PyDbAssocNetwork::removeAllActions(bool alsoEraseThem) const
{
    PyThrowBadEs(impObj()->removeAllActions(alsoEraseThem));
}

void PyDbAssocNetwork::ownedActionStatusChanged(const PyDbAssocAction& pOwnedAction, AcDbAssocStatus previousStatus) const
{
    PyThrowBadEs(impObj()->ownedActionStatusChanged(pOwnedAction.impObj(), previousStatus));
}

boost::python::list PyDbAssocNetwork::assocNetworkIterator() const
{
    PyAutoLockGIL lock;
    boost::python::list pylist;
    AcDbAssocNetworkIterator iter(impObj());
    while (iter.moveNext())
        pylist.append(PyDbObjectId(iter.current()));
    return pylist;
}

PyDbObjectId PyDbAssocNetwork::getInstanceFromDatabase(const PyDbDatabase& pDatabase, bool createIfDoesNotExist, const std::string& dictionaryKey)
{
    return PyDbObjectId(AcDbAssocNetwork::getInstanceFromDatabase(pDatabase.impObj(), createIfDoesNotExist, utf8_to_wstr(dictionaryKey).c_str()));
}

PyDbObjectId PyDbAssocNetwork::getInstanceFromObject(const PyDbObjectId& owningObjectId, bool createIfDoesNotExist, bool addToTopLevelNetwork, const std::string& dictionaryKey)
{
    return PyDbObjectId(AcDbAssocNetwork::getInstanceFromObject(owningObjectId.m_id, createIfDoesNotExist, addToTopLevelNetwork, utf8_to_wstr(dictionaryKey).c_str()));
}

void PyDbAssocNetwork::removeInstanceFromDatabase(const PyDbDatabase& pDatabase, bool alsoEraseIt, const std::string& dictionaryKey)
{
    PyThrowBadEs(AcDbAssocNetwork::removeInstanceFromDatabase(pDatabase.impObj(), alsoEraseIt, utf8_to_wstr(dictionaryKey).c_str()));
}

void PyDbAssocNetwork::removeInstanceFromObject(const PyDbObjectId& owningObjectId, bool alsoEraseIt, const std::string& dictionaryKey)
{
    PyThrowBadEs(AcDbAssocNetwork::removeInstanceFromObject(owningObjectId.m_id, alsoEraseIt, utf8_to_wstr(dictionaryKey).c_str()));
}

PyRxClass PyDbAssocNetwork::desc()
{
    return PyRxClass(AcDbAssocNetwork::desc(), false);
}

std::string PyDbAssocNetwork::className()
{
    return "AcDbAssocNetwork";
}

PyDbAssocNetwork PyDbAssocNetwork::cloneFrom(const PyRxObject& src)
{
    return PyDbObjectCloneFrom<PyDbAssocNetwork, AcDbAssocNetwork>(src);
}

PyDbAssocNetwork PyDbAssocNetwork::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbAssocNetwork>(src);
}

AcDbAssocNetwork* PyDbAssocNetwork::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbAssocNetwork*>(m_pyImp.get());
}


//-----------------------------------------------------------------------------------
//PyDbAssocVariable
void makePyDbAssocVariableWrapper()
{
    constexpr const std::string_view ctords = "Overloads:\n"
        "- None: Any\n"
        "- createImpObject: bool\n"
        "- id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode, erased: bool\n";

    constexpr const std::string_view setIsMergeableOverloads = "Overloads:\n"
        "- isMerg: bool\n"
        "- isMerg: bool, mustMerg: bool, mergeableVariableName: bool\n";

    constexpr const std::string_view evaluateExpressionOverloads = "Overloads:\n"
        "- None: Any\n"
        "- expression: str, evaluatorId: str, networkId: PyDb.ObjectId\n"
        "- objectIds: list[PyDb.ObjectId], objectValues: list[PyDb.EvalVariant]\n";

    PyDocString DS("AssocVariable");
    class_<PyDbAssocVariable, bases<PyDbAssocAction>>("AssocVariable")
        .def(init<>())
        .def(init<bool>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.CTOR(ctords)))
        .def("name", &PyDbAssocVariable::name, DS.ARGS())
        .def("expression", &PyDbAssocVariable::expression1)
        .def("expression", &PyDbAssocVariable::expression2, DS.ARGS({ "convertSymbolNamesFromCanonicalForm:bool = False" }))
        .def("value", &PyDbAssocVariable::value, DS.ARGS())
        .def("setValue", &PyDbAssocVariable::setValue, DS.ARGS({ "evalId:PyDb.EvalVariant" }))
        .def("description", &PyDbAssocVariable::description, DS.ARGS())
        .def("isAnonymous", &PyDbAssocVariable::isAnonymous, DS.ARGS())
        .def("setName", &PyDbAssocVariable::isAnonymous, DS.ARGS({ "newName:str","updateReferencingExpressions:bool" }))
        .def("findObjectByName", &PyDbAssocVariable::findObjectByName, DS.ARGS({ "objectName:str","pObjectClass:PyRx.RxClass" }))
        .def("validateNameAndExpression", &PyDbAssocVariable::validateNameAndExpression, DS.ARGS({ "nameToValidate:str","expressionToValidate:str" }))
        .def("setExpression", &PyDbAssocVariable::setExpression1)
        .def("setExpression", &PyDbAssocVariable::setExpression2, DS.ARGS({ "newExpression:str","evaluatorId:str","checkForCyclicalDependencies:bool","updateDependenciesOnReferencedSymbol:bool","silentMode:bool = False" }))
        .def("evaluatorId", &PyDbAssocVariable::evaluatorId, DS.ARGS())
        .def("setEvaluatorId", &PyDbAssocVariable::setEvaluatorId, DS.ARGS({ "evalId:str" }))
        .def("setDescription", &PyDbAssocVariable::setDescription, DS.ARGS())
        .def("isMergeable", &PyDbAssocVariable::isMergeable, DS.ARGS())
        .def("mustMerge", &PyDbAssocVariable::mustMerge, DS.ARGS())
        .def("mergeableVariableName", &PyDbAssocVariable::mergeableVariableName, DS.ARGS())
        .def("setIsMergeable", &PyDbAssocVariable::setIsMergeable1)
        .def("setIsMergeable", &PyDbAssocVariable::setIsMergeable2, DS.OVRL(setIsMergeableOverloads))
        .def("evaluateExpression", &PyDbAssocVariable::evaluateExpression1)
        .def("evaluateExpression", &PyDbAssocVariable::evaluateExpression2)
        .def("evaluateExpression", &PyDbAssocVariable::evaluateExpression3, DS.OVRL(evaluateExpressionOverloads))
        .def("className", &PyDbAssocVariable::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbAssocVariable::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyDbAssocVariable::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbAssocVariable::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyDbAssocVariable::PyDbAssocVariable()
    : PyDbAssocVariable(new AcDbAssocVariable(), true)
{
}

PyDbAssocVariable::PyDbAssocVariable(bool createImpObject)
#if defined(_BRXTARGET)
    : PyDbAssocVariable(new AcDbAssocVariable(), true)
#else
    : PyDbAssocVariable(new AcDbAssocVariable(createImpObject ? kAcDbAssocCreateImpObject : kAcDbAssocDoNotCreateImpObject), true)
#endif
{
#if defined(_BRXTARGET)
    throw PyNotimplementedByHost();
#endif
}

PyDbAssocVariable::PyDbAssocVariable(const PyDbObjectId& id)
    : PyDbAssocVariable(openAcDbObject<AcDbAssocVariable>(id), false)
{
}

PyDbAssocVariable::PyDbAssocVariable(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbAssocVariable(openAcDbObject<AcDbAssocVariable>(id, mode), false)
{
}

PyDbAssocVariable::PyDbAssocVariable(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbAssocVariable(openAcDbObject<AcDbAssocVariable>(id, mode, erased), false)
{
}

PyDbAssocVariable::PyDbAssocVariable(AcDbAssocVariable* ptr, bool autoDelete)
    :PyDbAssocAction(ptr, autoDelete)
{
}

std::string PyDbAssocVariable::name() const
{
    return wstr_to_utf8(impObj()->name());
}

std::string PyDbAssocVariable::expression1() const
{
    return wstr_to_utf8(impObj()->expression());
}

std::string PyDbAssocVariable::expression2(bool convertSymbolNamesFromCanonicalForm) const
{
    return wstr_to_utf8(impObj()->expression(convertSymbolNamesFromCanonicalForm));
}

PyDbEvalVariant PyDbAssocVariable::value() const
{
    return PyDbEvalVariant(impObj()->value());
}

std::string PyDbAssocVariable::description() const
{
    return wstr_to_utf8(impObj()->description());
}

bool PyDbAssocVariable::isAnonymous() const
{
    return impObj()->isAnonymous();
}

void PyDbAssocVariable::setName(const std::string& newName, bool updateReferencingExpressions) const
{
    PyThrowBadEs(impObj()->setName(utf8_to_wstr(newName).c_str(), updateReferencingExpressions));
}

PyDbObjectId PyDbAssocVariable::findObjectByName(const std::string& objectName, const PyRxClass& pObjectClass) const
{
    return PyDbObjectId(impObj()->findObjectByName(utf8_to_wstr(objectName).c_str(), pObjectClass.impObj()));
}

boost::python::tuple PyDbAssocVariable::validateNameAndExpression(const std::string& nameToValidate, const std::string& expressionToValidate) const
{
    PyAutoLockGIL lock;
    AcString errorMessage;
    auto es = impObj()->validateNameAndExpression(utf8_to_wstr(nameToValidate).c_str(), utf8_to_wstr(expressionToValidate).c_str(), errorMessage);
    return boost::python::make_tuple(es, wstr_to_utf8(errorMessage));
}

boost::python::tuple PyDbAssocVariable::setExpression1(const std::string& newExpression, const std::string& evaluatorId, bool checkForCyclicalDependencies, bool updateDependenciesOnReferencedSymbol) const
{
    PyAutoLockGIL lock;
    AcString errorMessage;
    auto es = impObj()->setExpression(utf8_to_wstr(newExpression).c_str(), utf8_to_wstr(evaluatorId).c_str(), checkForCyclicalDependencies, updateDependenciesOnReferencedSymbol, errorMessage);
    return boost::python::make_tuple(es, wstr_to_utf8(errorMessage));
}

boost::python::tuple PyDbAssocVariable::setExpression2(const std::string& newExpression, const std::string& evaluatorId, bool checkForCyclicalDependencies, bool updateDependenciesOnReferencedSymbol, bool silentMode) const
{
    PyAutoLockGIL lock;
    AcString errorMessage;
    auto es = impObj()->setExpression(utf8_to_wstr(newExpression).c_str(), utf8_to_wstr(evaluatorId).c_str(), checkForCyclicalDependencies, updateDependenciesOnReferencedSymbol, errorMessage, silentMode);
    return boost::python::make_tuple(es, wstr_to_utf8(errorMessage));
}

std::string PyDbAssocVariable::evaluatorId() const
{
#if defined(_BRXTARGET240)
    throw PyNotimplementedByHost();
#else
    return wstr_to_utf8(impObj()->evaluatorId());
#endif
}

void PyDbAssocVariable::setEvaluatorId(const std::string& evalId) const
{
    PyThrowBadEs(impObj()->setEvaluatorId(utf8_to_wstr(evalId).c_str()));
}

void PyDbAssocVariable::setValue(const PyDbEvalVariant& evalId) const
{
    PyThrowBadEs(impObj()->setValue(*evalId.impObj()));
}

void PyDbAssocVariable::setDescription(const std::string& newDescription) const
{
    PyThrowBadEs(impObj()->setDescription(utf8_to_wstr(newDescription).c_str()));
}

bool PyDbAssocVariable::isMergeable() const
{
    return impObj()->isMergeable();
}

bool PyDbAssocVariable::mustMerge() const
{
    return impObj()->mustMerge();
}

std::string PyDbAssocVariable::mergeableVariableName() const
{
    return wstr_to_utf8(impObj()->mergeableVariableName());
}

void PyDbAssocVariable::setIsMergeable1(bool isMerg) const
{
    impObj()->setIsMergeable(isMerg);
}

void PyDbAssocVariable::setIsMergeable2(bool isMerg, bool mustMerg, const std::string& mergeableVariableName) const
{
    impObj()->setIsMergeable(isMerg, mustMerg, utf8_to_wstr(mergeableVariableName).c_str());
}

boost::python::tuple PyDbAssocVariable::evaluateExpression1() const
{
    AcString errorMessage;
    AcDbEvalVariant evaluatedExpressionValue;
    auto es = impObj()->evaluateExpression(evaluatedExpressionValue, errorMessage);
    return boost::python::make_tuple(es, wstr_to_utf8(errorMessage), PyDbEvalVariant(evaluatedExpressionValue));
}

boost::python::tuple PyDbAssocVariable::evaluateExpression2(const boost::python::list& objectIds, const boost::python::list& objectValues) const
{
    PyAutoLockGIL lock;
    AcString errorMessage;
    AcDbEvalVariant evaluatedExpressionValue;
    AcDbObjectIdArray acids = PyListToObjectIdArray(objectIds);
    AcArray<AcDbEvalVariant> acobjectValues = PyListToAcDbEvalVariantArray(objectValues);
    auto es = impObj()->evaluateExpression(acids, acobjectValues, evaluatedExpressionValue, errorMessage);
    boost::python::list outobjectValues;
    for (const auto& item : acobjectValues)
        outobjectValues.append(PyDbEvalVariant(item));
    return boost::python::make_tuple(es, wstr_to_utf8(errorMessage), ObjectIdArrayToPyList(acids), outobjectValues, PyDbEvalVariant(evaluatedExpressionValue));
}

boost::python::tuple PyDbAssocVariable::evaluateExpression3(const std::string& expression, const std::string& evaluatorId, const PyDbObjectId& networkId) const
{
    PyAutoLockGIL lock;
    AcString errorMessage;
    AcString assignedToSymbolName;
    AcDbEvalVariant evaluatedExpressionValue;
    auto es = impObj()->evaluateExpression(utf8_to_wstr(expression).c_str(), utf8_to_wstr(evaluatorId).c_str(), networkId.m_id, evaluatedExpressionValue, assignedToSymbolName, errorMessage);
    return boost::python::make_tuple(es, wstr_to_utf8(errorMessage), PyDbEvalVariant(evaluatedExpressionValue), wstr_to_utf8(assignedToSymbolName));
}

PyRxClass PyDbAssocVariable::desc()
{
    return PyRxClass(AcDbAssocVariable::desc(), false);
}

std::string PyDbAssocVariable::className()
{
    return "AcDbAssocVariable";
}

PyDbAssocVariable PyDbAssocVariable::cloneFrom(const PyRxObject& src)
{
    return PyDbObjectCloneFrom<PyDbAssocVariable, AcDbAssocVariable>(src);
}

PyDbAssocVariable PyDbAssocVariable::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbAssocVariable>(src);
}

AcDbAssocVariable* PyDbAssocVariable::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbAssocVariable*>(m_pyImp.get());
}
