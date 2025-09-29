#pragma once

#pragma pack (push, 8)
#include "PyDbObject.h"
#include "AcDbAssocAction.h"
#include "AcDbAssocDependency.h"

//AcDbAssocGeomDependency
//AcDbAssocGeomDependency
//AcDbAssocNotificationData
//AcDbAssocEvaluationCallback

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