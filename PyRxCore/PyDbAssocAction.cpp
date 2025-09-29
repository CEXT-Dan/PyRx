#include "stdafx.h"
#include "PyDbAssocAction.h"
#include "PyDbIdMapping.h"
#include "PyDbEval.h"

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
