#pragma once

#include "PyRxObject.h"

class PyApDocument;
class PyDbDatabase;

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
    virtual void        documentCreateStartedWr(PyApDocument& pDocCreating);
    virtual void        documentCreatedWr(PyApDocument& pDocCreating);
    virtual void        documentToBeDestroyedWr(PyApDocument& pDocToDestroy);
    virtual void        documentDestroyedWr(const std::string& fileName);
    virtual void        documentCreateCanceledWr(PyApDocument& pDocCreateCancelled);

    virtual void        documentLockModeWillChangeWr(PyApDocument& doc,
        AcAp::DocLockMode myCurrentMode,
        AcAp::DocLockMode myNewMode,
        AcAp::DocLockMode currentMode,
        const std::string& pGlobalCmdName);
    virtual void        documentLockModeChangeVetoedWr(PyApDocument& doc, const std::string& pGlobalCmdName);

    virtual void        documentLockModeChangedWr(PyApDocument& doc,
        AcAp::DocLockMode myPreviousMode,
        AcAp::DocLockMode myCurrentMode,
        AcAp::DocLockMode currentMode,
        const std::string& pGlobalCmdName);

    virtual void        documentBecameCurrentWr(PyApDocument& doc);
    virtual void        documentToBeActivatedWr(PyApDocument& pActivatingDoc);
    virtual void        documentToBeDeactivatedWr(PyApDocument& pDeActivatedDoc);
    virtual void        documentActivationModifiedWr(bool bActivation);
    virtual void        documentActivatedWr(PyApDocument& pActivatedDoc);

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
void makeAcApDocManagerWrapper();

class PyApDocManager : public PyRxObject
{
public:
    PyApDocManager();
    PyApDocManager(AcApDocManager* ptr, bool autoDelete);
    virtual ~PyApDocManager() override = default;

    PyApDocument curDocument();
    PyApDocument mdiActiveDocument();
    bool  isApplicationContext() const;
    PyApDocument document(const PyDbDatabase& db);

    Acad::ErrorStatus lockDocument1(PyApDocument& pDoc);
    Acad::ErrorStatus lockDocument2(PyApDocument& pDoc, AcAp::DocLockMode mode);
    Acad::ErrorStatus lockDocument3(PyApDocument& pDoc, AcAp::DocLockMode mode, const std::string& pGlobalCmdName, const std::string pLocalCmdName, bool prompt);
    Acad::ErrorStatus unlockDocument(PyApDocument& pDoc);

    boost::python::list newAcApDocumentIterator();

    Acad::ErrorStatus setDefaultFormatForSave(AcApDocument::SaveFormat format);
    AcApDocument::SaveFormat defaultFormatForSave() const;

    Acad::ErrorStatus setCurDocument1(PyApDocument& pDoc);
    Acad::ErrorStatus setCurDocument2(PyApDocument& pDoc, AcAp::DocLockMode, bool activate);

    Acad::ErrorStatus activateDocument1(PyApDocument& pAcTargetDocument);
    Acad::ErrorStatus activateDocument2(PyApDocument& pAcTargetDocument, bool bPassScript);

    Acad::ErrorStatus sendStringToExecute1(PyApDocument& pAcTargetDocument, const std::string& pszExecute);
    Acad::ErrorStatus sendStringToExecute2(PyApDocument& pAcTargetDocument, const std::string& pszExecute, bool bActivate, bool bWrapUpInactiveDoc, bool bEchoString);

    Acad::ErrorStatus appContextNewDocument(const std::string& pszTemplateName);
    Acad::ErrorStatus appContextOpenDocument(const std::string& pszDrawingName);
    Acad::ErrorStatus appContextRecoverDocument(const std::string& pszDrawingName);

    Acad::ErrorStatus appContextPromptNewDocument();
    Acad::ErrorStatus appContextPromptOpenDocument();
    Acad::ErrorStatus appContextCloseDocument(PyApDocument& pDoc);

    Acad::ErrorStatus newDocument();
    Acad::ErrorStatus openDocument();
    Acad::ErrorStatus closeDocument(PyApDocument& pAcTargetDocument);

    int   inputPending(PyApDocument& pAcTargetDocument);

    Acad::ErrorStatus disableDocumentActivation();
    Acad::ErrorStatus enableDocumentActivation();
    bool isDocumentActivationEnabled();

    int documentCount() const;
    void pushAcadResourceHandle();
    void popResourceHandle();
    Acad::ErrorStatus sendModelessInterrupt(PyApDocument& pAcTargetDocument);

    static std::string className();

public:
    AcApDocManager* impObj(const std::source_location& src = std::source_location::current()) const;
};

