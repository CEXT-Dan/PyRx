#pragma once

#include "PyRxObject.h"

class PyApDocument;
class PyDbDatabase;

void makeAcApDocManagerWrapper();
//-----------------------------------------------------------------------------------------
//PyApDocManager
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

    //void addReactor(PyApDocManagerReactor&);
    //void removeReactor(PyApDocManagerReactor&);

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

    Acad::ErrorStatus appContextOpenPackage(const std::string& pszPackageName);

    Acad::ErrorStatus appContextPromptNewDocument();
    Acad::ErrorStatus appContextPromptOpenDocument();
    Acad::ErrorStatus appContextCloseDocument(PyApDocument& pDoc);

    Acad::ErrorStatus newDocument();
    Acad::ErrorStatus openDocument();
    Acad::ErrorStatus closeDocument(PyApDocument& pAcTargetDocument);

    int   inputPending(PyApDocument& pAcTargetDocument);

    static std::string className();

public:
    AcApDocManager* impObj() const;
};

