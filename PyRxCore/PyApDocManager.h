#pragma once

#include "PyRxObject.h"

#pragma pack (push, 8)
class PyApDocument;
class PyDbDatabase;
class PyAutoDocLock;

//-----------------------------------------------------------------------------------------
//PyApDocManagerReactor
void makePyApDocManagerReactorWrapper();

class PyApDocManagerReactor :public AcApDocManagerReactor, public boost::python::wrapper<PyApDocManagerReactor>
{
public:
    PyApDocManagerReactor();
    virtual ~PyApDocManagerReactor() override;
    virtual void    documentCreateStarted(AcApDocument* pDocCreating) override;
    virtual void    documentCreated(AcApDocument* pDocCreating) override;
    virtual void    documentToBeDestroyed(AcApDocument* pDocToDestroy) override;
    virtual void    documentDestroyed(const ACHAR* fileName) override;
    virtual void    documentCreateCanceled(AcApDocument* pDocCreateCancelled) override;
    virtual void    documentLockModeWillChange(AcApDocument*,
        AcAp::DocLockMode myCurrentMode,
        AcAp::DocLockMode myNewMode,
        AcAp::DocLockMode currentMode,
        const  ACHAR* pGlobalCmdName) override;

    virtual void    documentLockModeChangeVetoed(AcApDocument* doc, const ACHAR* pGlobalCmdName) override;
    virtual void    documentLockModeChanged(AcApDocument* doc,
        AcAp::DocLockMode myPreviousMode,
        AcAp::DocLockMode myCurrentMode,
        AcAp::DocLockMode currentMode,
        const ACHAR* pGlobalCmdName)override;

    virtual void    documentBecameCurrent(AcApDocument* doc) override;
    virtual void    documentToBeActivated(AcApDocument* pActivatingDoc) override;
    virtual void    documentToBeDeactivated(AcApDocument* pDeActivatedDoc) override;
    virtual void    documentActivationModified(bool bActivation) override;
    virtual void    documentActivated(AcApDocument* pActivatedDoc) override;

    ///forwards
    void    documentCreateStartedWr(PyApDocument& pDocCreating);
    void    documentCreatedWr(PyApDocument& pDocCreating);
    void    documentToBeDestroyedWr(PyApDocument& pDocToDestroy);
    void    documentDestroyedWr(const std::string& fileName);
    void    documentCreateCanceledWr(PyApDocument& pDocCreateCancelled);
    void    documentLockModeWillChangeWr(PyApDocument& doc,
        AcAp::DocLockMode myCurrentMode,
        AcAp::DocLockMode myNewMode,
        AcAp::DocLockMode currentMode,
        const std::string& pGlobalCmdName);

    void        documentLockModeChangeVetoedWr(PyApDocument& doc, const std::string& pGlobalCmdName);
    void        documentLockModeChangedWr(PyApDocument& doc,
        AcAp::DocLockMode myPreviousMode,
        AcAp::DocLockMode myCurrentMode,
        AcAp::DocLockMode currentMode,
        const std::string& pGlobalCmdName);

    void    documentBecameCurrentWr(PyApDocument& doc);
    void    documentToBeActivatedWr(PyApDocument& pActivatingDoc);
    void    documentToBeDeactivatedWr(PyApDocument& pDeActivatedDoc);
    void    documentActivationModifiedWr(bool bActivation);
    void    documentActivatedWr(PyApDocument& pActivatedDoc);

    void    addReactor();
    void    removeReactor();

public:
    //
    bool reg_documentCreateStarted = true;
    bool reg_documentCreated = true;
    bool reg_documentDestroyed = true;
    bool reg_documentToBeDestroyed = true;
    bool reg_documentCreateCanceled = true;
    bool reg_documentLockModeWillChange = true;
    bool reg_documentLockModeChangeVetoed = true;
    bool reg_documentLockModeChanged = true;
    bool reg_documentBecameCurrent = true;
    bool reg_documentToBeActivated = true;
    bool reg_documentToBeDeactivated = true;
    bool reg_documentActivationModified = true;
    bool reg_documentActivated = true;

public:
    bool m_isActive = false;
};

//-----------------------------------------------------------------------------------------
//PyApDocManager
void makePyApDocManagerWrapper();

class PyApDocManager : public PyRxObject
{
public:
    PyApDocManager();
    PyApDocManager(AcApDocManager* ptr, bool autoDelete);
    virtual ~PyApDocManager() override = default;

    PyApDocument    curDocument() const;
    PyApDocument    mdiActiveDocument() const;
    bool            isApplicationContext() const;
    PyApDocument    document(const PyDbDatabase& db) const;

    void            lockDocument1(PyApDocument& pDoc) const;
    void            lockDocument2(PyApDocument& pDoc, AcAp::DocLockMode mode) const;
    void            lockDocument3(PyApDocument& pDoc, AcAp::DocLockMode mode, const std::string& pGlobalCmdName, const std::string& pLocalCmdName, bool prompt) const;
    void            unlockDocument(PyApDocument& pDoc) const;

    boost::python::list newAcApDocumentIterator() const;
    void                setDefaultFormatForSave(AcApDocument::SaveFormat format) const;
    AcApDocument::SaveFormat defaultFormatForSave() const;

    void            setCurDocument1(PyApDocument& pDoc) const;
    void            setCurDocument2(PyApDocument& pDoc, AcAp::DocLockMode, bool activate) const;

    void            activateDocument1(PyApDocument& pAcTargetDocument) const;
    void            activateDocument2(PyApDocument& pAcTargetDocument, bool bPassScript) const;

    void            sendStringToExecute1(PyApDocument& pAcTargetDocument, const std::string& pszExecute) const;
    void            sendStringToExecute2(PyApDocument& pAcTargetDocument, const std::string& pszExecute, bool bActivate, bool bWrapUpInactiveDoc, bool bEchoString) const;

    void            appContextNewDocument(const std::string& pszTemplateName) const;
    void            appContextOpenDocument(const std::string& pszDrawingName) const;
    void            appContextRecoverDocument(const std::string& pszDrawingName) const;

    void            appContextPromptNewDocument() const;
    void            appContextPromptOpenDocument() const;
    void            appContextCloseDocument(PyApDocument& pDoc) const;

    void            newDocument() const;
    void            openDocument() const;
    void            closeDocument(PyApDocument& pAcTargetDocument) const;

    int             inputPending(PyApDocument& pAcTargetDocument) const;

    void            disableDocumentActivation() const;
    void            enableDocumentActivation() const;
    bool            isDocumentActivationEnabled() const;

    int             documentCount() const;
    void            pushAcadResourceHandle() const;
    void            popResourceHandle() const;
    void            sendModelessInterrupt(PyApDocument& pAcTargetDocument) const;

    void                executeInApplicationContext(const boost::python::object& func, const boost::python::object& data) const;
    Acad::ErrorStatus   beginExecuteInCommandContext(const boost::python::object& func, const boost::python::object& data) const;
    Acad::ErrorStatus   beginExecuteInApplicationContext(const boost::python::object& func, const boost::python::object& data) const;

    static PyAutoDocLock autoLock1();
    static PyAutoDocLock autoLock2(const PyApDocument& doc);
    static std::string  className();

    using ExecData = std::pair<const boost::python::object, const boost::python::object>;
    inline static std::unique_ptr<ExecData> mspExecData; //deleted in executeFunc

public:
    AcApDocManager* impObj(const std::source_location& src = std::source_location::current()) const;
};


//-----------------------------------------------------------------------------------------
//PyAutoDocLock
void makePyAutoDocLockWrapper();

class PyAutoDocLockImp
{
public:
    PyAutoDocLockImp();
    ~PyAutoDocLockImp();
    PyAutoDocLockImp(AcApDocument* doc);
    AcApDocument* pDoc = nullptr;
};

class PyAutoDocLock
{
public:
    PyAutoDocLock();
    PyAutoDocLock(const PyApDocument& doc);
    ~PyAutoDocLock() = default;
    PyApDocument doc() const;
    static std::string className();
public:
    AcApDocument* impObj(const std::source_location& src = std::source_location::current()) const;
    std::shared_ptr<PyAutoDocLockImp> m_pyImp;
};

#pragma pack (pop)