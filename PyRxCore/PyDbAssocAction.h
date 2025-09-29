#pragma once

#pragma pack (push, 8)
#include "PyDbObject.h"
#include "AcDbAssocAction.h"
#include "AcDbAssocDependency.h"

//AcDbAssocDependency
//AcDbAssocGeomDependency
//AcDbAssocGeomDependency

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
    //bool isOwnedDependency(const AcDbAssocDependency* pDependency) const;
    //bool isExternalDependency(const AcDbAssocDependency* pDependency) const;

    static PyDbObjectId     getActionBody(const PyDbObjectId& actionId);
    static PyRxClass        desc();
    static std::string      className();
    static PyDbAssocAction  cloneFrom(const PyRxObject& src);
    static PyDbAssocAction  cast(const PyRxObject& src);
public:
    AcDbAssocAction* impObj(const std::source_location& src = std::source_location::current()) const;
};


#pragma pack (pop)