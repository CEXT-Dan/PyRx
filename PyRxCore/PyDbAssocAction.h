#pragma once

#pragma pack (push, 8)

#include "PyDbObject.h"
#include "AcDbAssocAction.h"
#include "AcDbAssocDependency.h"
#include "AcDbAssocNetwork.h"
#include "AcDbAssocVariable.h"
#if !defined(_BRXTARGET240)
#include "AcDbAssocValueDependency.h"
#endif

class PyDbEvalVariant;
class PyDbAssocAction;

//-----------------------------------------------------------------------------------
//PyDbActionsToEvaluateCallback
void makePyDbActionsToEvaluateCallbackWrapper();

class PyDbActionsToEvaluateCallback : public AcDbActionsToEvaluateCallback, public boost::python::wrapper<PyDbActionsToEvaluateCallback>
{
public:
    PyDbActionsToEvaluateCallback() = default;
    virtual ~PyDbActionsToEvaluateCallback() override = default;
#if defined(_BRXTARGET260)
    virtual void needsToEvaluate(const AcDbObjectId objectId, AcDbAssocStatus newStatus, bool ownedActionsAlso = true) override;
#else
    virtual void needsToEvaluate(const AcDbObjectId& objectId, AcDbAssocStatus newStatus, bool ownedActionsAlso = true) override;
#endif
    void needsToEvaluateWr(const PyDbObjectId& objectId, AcDbAssocStatus newStatus, bool ownedActionsAlso);

public:
    static std::string  className();

public:
    bool reg_needsToEvaluate = true;
};

//-----------------------------------------------------------------------------------
//PyDbAssocEvaluationCallback
void makePyDbAssocEvaluationCallbackWrapper();

class PyDbAssocEvaluationCallback : public AcDbAssocEvaluationCallback, public boost::python::wrapper<PyDbAssocEvaluationCallback>
{
public:
    PyDbAssocEvaluationCallback() = default;
    virtual ~PyDbAssocEvaluationCallback() override = default;

    virtual AcDbAssocEvaluationMode evaluationMode() const override;
    virtual void beginActionEvaluation(AcDbAssocAction* pAction) override;
    virtual void endActionEvaluation(AcDbAssocAction* pAction) override;
    virtual void setActionEvaluationErrorStatus(AcDbAssocAction* pAction, Acad::ErrorStatus errorStatus, const AcDbObjectId& objectId = AcDbObjectId::kNull, AcDbObject* pObject = NULL, void* pErrorInfo = NULL)  override;
    virtual void beginActionEvaluationUsingObject(AcDbAssocAction* pAction, const AcDbObjectId& objectId, bool objectIsGoingToBeUsed, bool objectIsGoingToBeModified, AcDbObject*& pSubstituteObject) override;
    virtual void endActionEvaluationUsingObject(AcDbAssocAction* pAction, const AcDbObjectId& objectId, AcDbObject* pObject) override;
    virtual void allDependentActionsMarkedToEvaluate(AcDbAssocNetwork* /*pNetwork*/) override;
    virtual AcDbAssocDraggingState draggingState() const override;
    virtual bool cancelActionEvaluation() override;
    virtual AcDbEvalContext* getAdditionalData() const override;
    virtual AcDbAssocTransformationType getTransformationType() const override;

    //
    void beginActionEvaluationWr(const PyDbAssocAction& pAction);
    void endActionEvaluationWr(const PyDbAssocAction& pAction);

    static std::string      className();

public:
    bool reg_beginActionEvaluation = true;
    bool reg_endActionEvaluation = true;
};

//-----------------------------------------------------------------------------------
//PyDbAssocDependency
void makePyDbAssocDependencyWrapper();

class PyDbAssocDependency : public PyDbObject
{
public:
    PyDbAssocDependency();
    PyDbAssocDependency(bool createImpObject);
    PyDbAssocDependency(const PyDbObjectId& id);
    PyDbAssocDependency(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbAssocDependency(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    PyDbAssocDependency(AcDbAssocDependency* ptr, bool autoDelete);
    virtual ~PyDbAssocDependency() override = default;

    PyDbObjectId        dependencyBody() const;
    void                setDependencyBody(const PyDbObjectId& dependencyBodyId) const;
    AcDbAssocStatus     status() const;
    void                setStatus(AcDbAssocStatus newStatus, bool notifyOwningAction) const;
    bool                isReadDependency() const;
    bool                isWriteDependency() const;
    void                setIsReadDependency(bool yesNo) const;
    void                setIsWriteDependency(bool yesNo) const;
    bool                isObjectStateDependent() const;
    void                setIsObjectStateDependent(bool yesNo) const;
    int                 order() const;
    void                setOrder(int newOrder) const;
    PyDbObjectId        owningAction() const;
    void                setOwningAction(const PyDbObjectId& actionId) const;
    PyDbObjectId        dependentOnObject() const;
    //void              getDependentOnCompoundObject(AcDbCompoundObjectId& compoundId) const;
    //void              attachToObject(const AcDbCompoundObjectId& compoundId);
    //void              transferToObject(const AcDbCompoundObjectId& compoundId);
    //void              setDependentOnObject(const AcDbCompoundObjectId& compoundId);
    bool                isDependentOnCompoundObject() const;
    PyDbObjectId        prevDependencyOnObject() const;
    PyDbObjectId        nextDependencyOnObject() const;
    bool                isAttachedToObject() const;
    Acad::ErrorStatus   dependentOnObjectStatus() const;
    void                detachFromObject() const;
    void                updateDependentOnObject() const;
    bool                isDelegatingToOwningAction() const;
    void                setIsDelegatingToOwningAction(bool yesNo);
    bool                hasCachedValue() const;
    bool                isRelevantChange() const;
    //Acad::ErrorStatus notification(AcDbAssocNotificationData* pNotifData);
    bool                isDependentOnTheSameThingAs(const PyDbAssocDependency& pOtherDependency) const;
    bool                isDependentOnObjectReadOnly() const;
    bool                isEqualTo(const PyDbAssocDependency& pOtherDependency) const;
    bool                isActionEvaluationInProgress() const;
    //AcDbAssocEvaluationCallback* currentEvaluationCallback() const;
    void                evaluate() const;
    void                erased(const PyDbObject& dbObj, Adesk::Boolean isErasing) const;
    void                modified(const PyDbObject& dbObj) const;
    void                copied(const PyDbObject& dbObj, const PyDbObject& pNewObj) const;
    void                setPrevDependencyOnObject(const PyDbObjectId& depId) const;
    void                setNextDependencyOnObject(const PyDbObjectId& depId) const;



    static PyDbObjectId getFirstDependencyOnObject(const PyDbObject& pObject);
    static boost::python::list getDependenciesOnObject(const PyDbObject& pObject, bool readDependenciesWanted, bool writeDependenciesWanted);
    static void         notifyDependenciesOnObject(const PyDbObject& pObject, AcDbAssocStatus newStatus);

    static PyRxClass            desc();
    static std::string          className();
    static PyDbAssocDependency  cloneFrom(const PyRxObject& src);
    static PyDbAssocDependency  cast(const PyRxObject& src);
public:
    AcDbAssocDependency* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//PyDbAssocValueDependency
void makePyDbAssocValueDependencyWrapper();

#if !defined(_BRXTARGET240)
class PyDbAssocValueDependency : public PyDbAssocDependency
{
public:
    PyDbAssocValueDependency();
    PyDbAssocValueDependency(bool createImpObject);
    PyDbAssocValueDependency(const PyDbObjectId& id);
    PyDbAssocValueDependency(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbAssocValueDependency(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    PyDbAssocValueDependency(AcDbAssocValueDependency* ptr, bool autoDelete);
    virtual ~PyDbAssocValueDependency() override = default;

    std::string     valueName() const;
    void            setValueName(const std::string& val) const;
    PyDbEvalVariant getDependentOnObjectValue() const;
    void            setDependentOnObjectValue(const PyDbEvalVariant& val) const;

    static PyRxClass                 desc();
    static std::string               className();
    static PyDbAssocValueDependency  cloneFrom(const PyRxObject& src);
    static PyDbAssocValueDependency  cast(const PyRxObject& src);
public:
    AcDbAssocValueDependency* impObj(const std::source_location& src = std::source_location::current()) const;
};
#endif

//-----------------------------------------------------------------------------------
//PyDbAssocAction
void makePyDbAssocActionWrapper();

class PyDbAssocAction : public PyDbObject
{
public:
    PyDbAssocAction();
    PyDbAssocAction(bool createImpObject);
    PyDbAssocAction(const PyDbObjectId& id);
    PyDbAssocAction(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbAssocAction(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    PyDbAssocAction(AcDbAssocAction* ptr, bool autoDelete);
    virtual ~PyDbAssocAction() override = default;

    PyDbObjectId        actionBody() const;
    void                setActionBody(const PyDbObjectId& actionBodyId) const;
    bool                isActionBodyAProxy() const;
    AcDbAssocStatus     status() const;
    void                setStatus1(AcDbAssocStatus newStatus) const;
    void                setStatus2(AcDbAssocStatus newStatus, bool notifyOwningNetwork, bool setInOwnedActions) const;
    PyDbObjectId        owningNetwork() const;
    void                setOwningNetwork(const PyDbObjectId& networkId, bool alsoSetAsDatabaseOwner) const;
    boost::python::list getDependencies(bool readDependenciesWanted, bool writeDependenciesWanted) const;
    void                addDependency(const PyDbObjectId& actionBodyId, bool setThisActionAsOwningAction) const;
    PyDbObjectId        appendDependency(const PyRxClass& pDependencyClass, const PyRxClass& pDependencyBodyClass, bool isReadDep, bool isWriteDep, int order) const;
    void                removeDependency(const PyDbObjectId& dependencyId, bool alsoEraseIt) const;
    void                removeAllDependencies(bool alsoEraseThem)  const;
    boost::python::list getDependentObjects(bool readDependenciesWanted, bool writeDependenciesWanted) const;
    bool                isOwnedDependency(const PyDbAssocDependency& pDependency) const;
    bool                isExternalDependency(const PyDbAssocDependency& pDependency) const;
    bool                isRelevantDependencyChange(const PyDbAssocDependency& pDependency) const;
    bool                hasDependencyCachedValue(const PyDbAssocDependency& pDependency) const;
    bool                areDependenciesOnTheSameThing(const PyDbAssocDependency& pDependency1, const PyDbAssocDependency& pDependency2) const;
    bool                areDependenciesEqual(const PyDbAssocDependency& pDependency1, const PyDbAssocDependency& pDependency2) const;
    //Acad::ErrorStatus  notification(AcDbAssocNotificationData* pNotifData);
    //AcDbAssocEvaluationCallback* currentEvaluationCallback() const;
    void                dependentObjectCloned(const PyDbAssocDependency& pDependency, const PyDbObject& pDbObj, const PyDbObject& pNewObj) const;
    boost::python::list addMoreObjectsToDeepClone(const PyDbIdMapping& idMap, boost::python::list& additionalObjectsToClone) const;
    void                postProcessAfterDeepClone(PyDbIdMapping& idMap);
    void                postProcessAfterDeepCloneCancel(PyDbIdMapping& idMap);
    bool                isActionEvaluationInProgress() const;
    void                evaluateDependencies() const;
    void                evaluateDependency(PyDbAssocDependency& pDependency) const;
    void                ownedDependencyStatusChanged(PyDbAssocDependency& pOwnedDependency, AcDbAssocStatus previousStatus) const;
    void                transformActionBy(const AcGeMatrix3d& transform) const;
    bool                isEqualTo(const PyDbAssocAction& pOtherAction) const;
    AcDbAssocEvaluationPriority evaluationPriority() const;
    void                getDependentActionsToEvaluate(PyDbActionsToEvaluateCallback& pActionsToEvaluateCallback) const;
    void                evaluate(PyDbAssocEvaluationCallback& pEvaluationCallback);
    PyDbObjectId        objectThatOwnsNetworkInstance() const;
    void                dragStatus(const AcDb::DragStat status) const;
    void                removeAllParams(bool alsoEraseThem);
    int                 paramCount() const;
    boost::python::list ownedParams() const;
    int                 addParam1(const PyDbObjectId& paramId) const;
    int                 addParam2(const std::string& paramName, const PyRxClass& pParamClass, PyDbObjectId& paramId) const;
    void                removeParam(const PyDbObjectId& paramId, bool alsoEraseIt) const;
    boost::python::list paramsAtName(const std::string& paramName) const;
    PyDbObjectId        paramAtName1(const std::string& paramName) const;
    PyDbObjectId        paramAtName2(const std::string& paramName, int index) const;
    PyDbObjectId        paramAtIndex(int paramIndex) const;
    boost::python::list ownedValueParamNames() const;
    boost::python::tuple getValueParamArray(const std::string& paramName) const;
    boost::python::tuple getValueParam(const std::string& paramName, int idx) const;
    boost::python::list setValueParamArray(const std::string& paramName, const boost::python::list& values, const boost::python::list& expressions, const boost::python::list& evaluatorIds, bool silentMode) const;
    std::string         setValueParam(const std::string& paramName, const PyDbEvalVariant& value, const std::string& expression, const std::string& evaluatorId, bool silentMode, int valueIndex) const;
    AcValue::UnitType   valueParamUnitType(const std::string& paramName) const;
    void                setValueParamUnitType(const std::string& paramName, AcValue::UnitType unitType) const;
    void                removeValueParam(const std::string& paramName) const;
    boost::python::list valueParamInputVariables(const std::string& paramName) const;
    void                setValueParamControlledObjectDep(const std::string& paramName, const PyDbObjectId& controlledObjectDepId) const;
    void                updateValueParamControlledObject(const std::string& paramName) const;
    void                updateValueParamFromControlledObject(const std::string& paramName) const;
    void                updateAllObjectsControlledByValueParams() const;
    void                transformAllConstantGeometryParams(const AcGeMatrix3d& transform) const;
    void                scaleAllDistanceValueParams(double scaleFactor) const;

    static boost::python::list getActionsDependentOnObject(const PyDbObject& pObject, bool readDependenciesWanted, bool writeDependenciesWanted);
    static void             removeActionsControllingObject1(const PyDbObjectId& objectToRemoveActionsFrom);
    static void             removeActionsControllingObject2(const PyDbObjectId& objectToRemoveActionsFrom, int readOnlyDependencyHandling, const PyDbObjectId& objectToRedirectReadOnlyDependenciesTo);
    static void             markDependentActionsToEvaluate(const PyDbObjectId& actionId);
    static bool             doesObjectHaveActiveActions(const PyDbObject& pObject);
    static PyDbObjectId     getActionBody(const PyDbObjectId& actionId);
    static PyRxClass        desc();
    static std::string      className();
    static PyDbAssocAction  cloneFrom(const PyRxObject& src);
    static PyDbAssocAction  cast(const PyRxObject& src);
public:
    AcDbAssocAction* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//PyDbAssocNetwork
void makePyDbAssocNetworkWrapper();

class PyDbAssocNetwork : public PyDbAssocAction
{
public:
    PyDbAssocNetwork();
    PyDbAssocNetwork(bool createImpObject);
    PyDbAssocNetwork(const PyDbObjectId& id);
    PyDbAssocNetwork(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbAssocNetwork(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    PyDbAssocNetwork(AcDbAssocNetwork* ptr, bool autoDelete);
    virtual ~PyDbAssocNetwork() override = default;

    boost::python::list getActions() const;
    boost::python::list getActionsToEvaluate() const;
    void                addAction(const PyDbObjectId& actionId, bool alsoSetAsDatabaseOwner) const;
    void                removeAction(const PyDbObjectId& actionId, bool alsoEraseIt) const;
    void                addActions(const boost::python::list& actionIds, bool alsoSetAsDatabaseOwner) const;
    void                removeAllActions(bool alsoEraseThem) const;
    void                ownedActionStatusChanged(const PyDbAssocAction& pOwnedAction, AcDbAssocStatus  previousStatus) const;
    boost::python::list assocNetworkIterator() const;

    static PyDbObjectId getInstanceFromDatabase(const PyDbDatabase& pDatabase, bool createIfDoesNotExist, const std::string& dictionaryKey);
    static PyDbObjectId getInstanceFromObject(const PyDbObjectId& owningObjectId, bool createIfDoesNotExist, bool addToTopLevelNetwork, const std::string& dictionaryKey);
    static void         removeInstanceFromDatabase(const PyDbDatabase& pDatabase, bool alsoEraseIt, const std::string& dictionaryKey);
    static void         removeInstanceFromObject(const PyDbObjectId& owningObjectId, bool alsoEraseIt, const std::string& dictionaryKey);

    static PyRxClass        desc();
    static std::string      className();
    static PyDbAssocNetwork cloneFrom(const PyRxObject& src);
    static PyDbAssocNetwork cast(const PyRxObject& src);
public:
    AcDbAssocNetwork* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//PyDbAssocVariable
void makePyDbAssocVariableWrapper();

class PyDbAssocVariable : public PyDbAssocAction
{
public:
    PyDbAssocVariable();
    PyDbAssocVariable(bool createImpObject);
    PyDbAssocVariable(const PyDbObjectId& id);
    PyDbAssocVariable(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbAssocVariable(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    PyDbAssocVariable(AcDbAssocVariable* ptr, bool autoDelete);
    virtual ~PyDbAssocVariable() override = default;

    std::string     name() const;
    std::string     expression1() const;
    std::string     expression2(bool convertSymbolNamesFromCanonicalForm) const;
    PyDbEvalVariant value() const;
    std::string     description() const;
    bool            isAnonymous() const;
    void            setName(const std::string& newName, bool updateReferencingExpressions) const;
    PyDbObjectId    findObjectByName(const std::string& objectName, const PyRxClass& pObjectClass) const;
    boost::python::tuple validateNameAndExpression(const std::string& nameToValidate, const std::string& expressionToValidate) const;
    boost::python::tuple setExpression1(const std::string& newExpression, const std::string& evaluatorId, bool checkForCyclicalDependencies, bool updateDependenciesOnReferencedSymbol) const;
    boost::python::tuple setExpression2(const std::string& newExpression, const std::string& evaluatorId, bool checkForCyclicalDependencies, bool updateDependenciesOnReferencedSymbol, bool silentMode) const;

    std::string     evaluatorId() const;
    void            setEvaluatorId(const std::string& evalId) const;
    void            setValue(const PyDbEvalVariant& evalId) const;
    void            setDescription(const std::string& newDescription) const;

    bool            isMergeable() const;
    bool            mustMerge() const;
    std::string     mergeableVariableName() const;
    void            setIsMergeable1(bool isMerg) const;
    void            setIsMergeable2(bool isMerg, bool mustMerg, const std::string& mergeableVariableName) const;
    boost::python::tuple  evaluateExpression1() const;
    boost::python::tuple  evaluateExpression2(const boost::python::list& objectIds, const boost::python::list& objectValues) const;
    boost::python::tuple  evaluateExpression3(const std::string& expression, const std::string& evaluatorId, const PyDbObjectId& networkId) const;

    //ACDBCORE2D_PORT static void addGlobalCallback(class AcDbAssocVariableCallback* pCallback);
    //ACDBCORE2D_PORT static void removeGlobalCallback(class AcDbAssocVariableCallback* pCallback);
    //ACDBCORE2D_PORT static class AcDbAssocVariableCallback* globalCallback();

    static PyRxClass        desc();
    static std::string      className();
    static PyDbAssocVariable cloneFrom(const PyRxObject& src);
    static PyDbAssocVariable cast(const PyRxObject& src);
public:
    AcDbAssocVariable* impObj(const std::source_location& src = std::source_location::current()) const;
};

#pragma pack (pop)