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
    ~PyApDocManagerReactor();
    virtual void        documentCreateStarted(AcApDocument* pDocCreating) override;
    virtual void        documentCreated(AcApDocument* pDocCreating) override;
    virtual void        documentToBeDestroyed(AcApDocument* pDocToDestroy) override;
    virtual void        documentDestroyed(const ACHAR* fileName) override;
    virtual void        documentCreateCanceled(AcApDocument* pDocCreateCancelled) override;
    virtual void        documentLockModeWillChange(AcApDocument*,
        AcAp::DocLockMode myCurrentMode,
        AcAp::DocLockMode myNewMode,
        AcAp::DocLockMode currentMode,
        const  ACHAR* pGlobalCmdName) override;
    virtual void        documentLockModeChangeVetoed(AcApDocument* doc, const ACHAR* pGlobalCmdName) override;
    virtual void        documentLockModeChanged(AcApDocument* doc,
        AcAp::DocLockMode myPreviousMode,
        AcAp::DocLockMode myCurrentMode,
        AcAp::DocLockMode currentMode,
        const ACHAR* pGlobalCmdName)override;
    virtual void        documentBecameCurrent(AcApDocument* doc) override;
    virtual void        documentToBeActivated(AcApDocument* pActivatingDoc) override;
    virtual void        documentToBeDeactivated(AcApDocument* pDeActivatedDoc) override;
    virtual void        documentActivationModified(bool bActivation) override;
    virtual void        documentActivated(AcApDocument* pActivatedDoc) override;

    ///forwards
    void        documentCreateStartedWr(PyApDocument& pDocCreating);
    void        documentCreatedWr(PyApDocument& pDocCreating);
    void        documentToBeDestroyedWr(PyApDocument& pDocToDestroy);
    void        documentDestroyedWr(const std::string& fileName);
    void        documentCreateCanceledWr(PyApDocument& pDocCreateCancelled);

    void        documentLockModeWillChangeWr(PyApDocument& doc,
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

    void        documentBecameCurrentWr(PyApDocument& doc);
    void        documentToBeActivatedWr(PyApDocument& pActivatingDoc);
    void        documentToBeDeactivatedWr(PyApDocument& pDeActivatedDoc);
    void        documentActivationModifiedWr(bool bActivation);
    void        documentActivatedWr(PyApDocument& pActivatedDoc);

    void                addReactor();
    void                removeReactor();

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

    PyApDocument        curDocument();
    PyApDocument        mdiActiveDocument();
    bool                isApplicationContext() const;
    PyApDocument        document(const PyDbDatabase& db);

    void                lockDocument1(PyApDocument& pDoc);
    void                lockDocument2(PyApDocument& pDoc, AcAp::DocLockMode mode);
    void                lockDocument3(PyApDocument& pDoc, AcAp::DocLockMode mode, const std::string& pGlobalCmdName, const std::string pLocalCmdName, bool prompt);
    void                unlockDocument(PyApDocument& pDoc);
    boost::python::list newAcApDocumentIterator();
    void                setDefaultFormatForSave(AcApDocument::SaveFormat format);
    AcApDocument::SaveFormat defaultFormatForSave() const;

    void                setCurDocument1(PyApDocument& pDoc);
    void                setCurDocument2(PyApDocument& pDoc, AcAp::DocLockMode, bool activate);

    void                activateDocument1(PyApDocument& pAcTargetDocument);
    void                activateDocument2(PyApDocument& pAcTargetDocument, bool bPassScript);

    void                sendStringToExecute1(PyApDocument& pAcTargetDocument, const std::string& pszExecute);
    void                sendStringToExecute2(PyApDocument& pAcTargetDocument, const std::string& pszExecute, bool bActivate, bool bWrapUpInactiveDoc, bool bEchoString);

    void                appContextNewDocument(const std::string& pszTemplateName);
    void                appContextOpenDocument(const std::string& pszDrawingName);
    void                appContextRecoverDocument(const std::string& pszDrawingName);

    void                appContextPromptNewDocument();
    void                appContextPromptOpenDocument();
    void                appContextCloseDocument(PyApDocument& pDoc);

    void                newDocument();
    void                openDocument();
    void                closeDocument(PyApDocument& pAcTargetDocument);

    int                 inputPending(PyApDocument& pAcTargetDocument);

    void                disableDocumentActivation();
    void                enableDocumentActivation();
    bool                isDocumentActivationEnabled();

    int                 documentCount() const;
    void                pushAcadResourceHandle();
    void                popResourceHandle();
    void                sendModelessInterrupt(PyApDocument& pAcTargetDocument);

    void                executeInApplicationContext(const boost::python::object& func, const boost::python::object& data);
    Acad::ErrorStatus   beginExecuteInCommandContext(const boost::python::object& func, const boost::python::object& data);
    Acad::ErrorStatus   beginExecuteInApplicationContext(const boost::python::object& func, const boost::python::object& data);

    static PyAutoDocLock autoLock();
    static std::string  className();

    using ExecData = std::pair<const boost::python::object, const boost::python::object>;
    inline static std::unique_ptr<ExecData> mpData;

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
    AcApDocument* pDoc = nullptr;
};

class PyAutoDocLock
{
public:
    PyAutoDocLock();
    ~PyAutoDocLock() = default;
    static std::string className();
public:
    std::shared_ptr<PyAutoDocLockImp> imp;
};

#pragma pack (pop)