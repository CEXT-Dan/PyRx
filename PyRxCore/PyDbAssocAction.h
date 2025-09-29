#pragma once

#pragma pack (push, 8)
#include "PyDbObject.h"
#include "AcDbAssocAction.h"
#include "AcDbAssocDependency.h"

//AcDbAssocGeomDependency
//AcDbAssocGeomDependency
//AcDbAssocNotificationData
//AcDbAssocEvaluationCallback

class PyDbEvalVariant;

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

    static PyRxClass        desc();
    static std::string      className();
    static PyDbAssocDependency  cloneFrom(const PyRxObject& src);
    static PyDbAssocDependency  cast(const PyRxObject& src);
public:
    AcDbAssocDependency* impObj(const std::source_location& src = std::source_location::current()) const;
};

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
    bool                areDependenciesOnTheSameThing(const PyDbAssocDependency& pDependency1,const PyDbAssocDependency& pDependency2) const;
    bool                areDependenciesEqual(const PyDbAssocDependency& pDependency1, const PyDbAssocDependency& pDependency2) const;
    //Acad::ErrorStatus  notification(AcDbAssocNotificationData* pNotifData);
    void                dependentObjectCloned(const PyDbAssocDependency& pDependency,const PyDbObject& pDbObj,const PyDbObject& pNewObj) const;
    boost::python::list addMoreObjectsToDeepClone(const PyDbIdMapping& idMap, boost::python::list& additionalObjectsToClone) const;
    void                postProcessAfterDeepClone(PyDbIdMapping& idMap);
    void                postProcessAfterDeepCloneCancel(PyDbIdMapping& idMap);
    bool                isActionEvaluationInProgress() const;
    //AcDbAssocEvaluationCallback* currentEvaluationCallback() const;
    void                evaluateDependencies() const;
    void                evaluateDependency(PyDbAssocDependency& pDependency) const;
    void                ownedDependencyStatusChanged(PyDbAssocDependency& pOwnedDependency, AcDbAssocStatus previousStatus) const;
    void                transformActionBy(const AcGeMatrix3d& transform) const;
    bool                isEqualTo(const PyDbAssocAction& pOtherAction) const;
    AcDbAssocEvaluationPriority evaluationPriority() const;
    //void getDependentActionsToEvaluate(AcDbActionsToEvaluateCallback* pActionsToEvaluateCallback) const;
    //void evaluate(AcDbAssocEvaluationCallback* pEvaluationCallback);
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


#pragma pack (pop)