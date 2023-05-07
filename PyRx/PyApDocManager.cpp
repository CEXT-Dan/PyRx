#include "stdafx.h"
#include "PyApDocManager.h"
#include "PyApDocument.h"
#include "PyDbDatabase.h"

using namespace boost::python;

//-----------------------------------------------------------------------------------------
//PyApDocManagerReactor
void makePyApDocManagerReactorWrapper()
{
    class_<PyApDocManagerReactor, boost::noncopyable>("DocManagerReactor")
        .def("documentCreateStarted", &PyApDocManagerReactor::documentCreateStartedWr)
        .def("documentCreated", &PyApDocManagerReactor::documentCreatedWr)
        .def("documentToBeDestroyed", &PyApDocManagerReactor::documentToBeDestroyedWr)
        .def("documentDestroyed", &PyApDocManagerReactor::documentDestroyedWr)
        .def("documentCreateCanceled", &PyApDocManagerReactor::documentCreateCanceledWr)
        .def("documentLockModeWillChange", &PyApDocManagerReactor::documentLockModeWillChangeWr)
        .def("documentLockModeChangeVetoed", &PyApDocManagerReactor::documentLockModeChangeVetoedWr)
        .def("documentLockModeChanged", &PyApDocManagerReactor::documentLockModeChangedWr)
        .def("documentBecameCurrent", &PyApDocManagerReactor::documentBecameCurrentWr)
        .def("documentToBeActivated", &PyApDocManagerReactor::documentToBeActivatedWr)
        .def("documentToBeDeactivated", &PyApDocManagerReactor::documentToBeDeactivatedWr)
        .def("documentActivationModified", &PyApDocManagerReactor::documentActivationModifiedWr)
        .def("documentActivated", &PyApDocManagerReactor::documentActivatedWr)
        .def("addReactor", &PyApDocManagerReactor::addReactor)
        .def("removeReactor", &PyApDocManagerReactor::removeReactor)
        ;
}

PyApDocManagerReactor::PyApDocManagerReactor()
{
}

PyApDocManagerReactor::~PyApDocManagerReactor()
{
    if (m_isActive)
        removeReactor();
}

void PyApDocManagerReactor::documentCreateStarted(AcApDocument* pDocCreating)
{
    PyApDocument doc(pDocCreating, false);
    documentCreateStartedWr(doc);
}

void PyApDocManagerReactor::documentCreated(AcApDocument* pDocCreating)
{
    PyApDocument doc(pDocCreating, false);
    documentCreatedWr(doc);
}

void PyApDocManagerReactor::documentToBeDestroyed(AcApDocument* pDocToDestroy)
{
    PyApDocument doc(pDocToDestroy, false);
    documentToBeDestroyedWr(doc);
}

void PyApDocManagerReactor::documentDestroyed(const ACHAR* fileName)
{
    documentDestroyedWr(wstr_to_utf8(fileName));
}

void PyApDocManagerReactor::documentCreateCanceled(AcApDocument* pDocCreateCancelled)
{
    PyApDocument doc(pDocCreateCancelled, false);
    documentCreateCanceledWr(doc);
}

void PyApDocManagerReactor::documentLockModeWillChange(AcApDocument* pDoc, AcAp::DocLockMode myCurrentMode, AcAp::DocLockMode myNewMode, AcAp::DocLockMode currentMode, const ACHAR* pGlobalCmdName)
{
    PyApDocument doc(pDoc, false);
    documentLockModeWillChangeWr(doc, myCurrentMode, myNewMode, currentMode, wstr_to_utf8(pGlobalCmdName));
}

void PyApDocManagerReactor::documentLockModeChangeVetoed(AcApDocument* pdoc, const ACHAR* pGlobalCmdName)
{
    PyApDocument doc(pdoc, false);
    documentLockModeChangeVetoedWr(doc, wstr_to_utf8(pGlobalCmdName));
}

void PyApDocManagerReactor::documentLockModeChanged(AcApDocument* pdoc, AcAp::DocLockMode myPreviousMode, AcAp::DocLockMode myCurrentMode, AcAp::DocLockMode currentMode, const ACHAR* pGlobalCmdName)
{
    PyApDocument doc(pdoc, false);
    documentLockModeChangedWr(doc, myPreviousMode, myCurrentMode, currentMode, wstr_to_utf8(pGlobalCmdName));
}

void PyApDocManagerReactor::documentBecameCurrent(AcApDocument* pdoc)
{
    PyApDocument doc(pdoc, false);
    documentBecameCurrentWr(doc);
}

void PyApDocManagerReactor::documentToBeActivated(AcApDocument* pActivatingDoc)
{
    PyApDocument doc(pActivatingDoc, false);
    documentToBeActivatedWr(doc);
}

void PyApDocManagerReactor::documentToBeDeactivated(AcApDocument* pDeActivatedDoc)
{
    PyApDocument doc(pDeActivatedDoc, false);
    documentToBeDeactivatedWr(doc);
}

void PyApDocManagerReactor::documentActivationModified(bool bActivation)
{
    documentActivationModifiedWr(bActivation);
}

void PyApDocManagerReactor::documentActivated(AcApDocument* pActivatedDoc)
{
    PyApDocument doc(pActivatedDoc, false);
    documentActivatedWr(doc);
}

void PyApDocManagerReactor::documentCreateStartedWr(PyApDocument& pDocCreating)
{
    PyAutoLockGIL lock;
    if (override pyFunc = this->get_override("documentCreateStarted"))
       pyFunc(pDocCreating);
}

void PyApDocManagerReactor::documentCreatedWr(PyApDocument& pDocCreating)
{
    PyAutoLockGIL lock;
   if (override pyFunc = this->get_override("documentCreated"))
        pyFunc(pDocCreating);
}

void PyApDocManagerReactor::documentToBeDestroyedWr(PyApDocument& pDocToDestroy)
{
    PyAutoLockGIL lock;
    if (override pyFunc = this->get_override("documentToBeDestroyed"))
        pyFunc(pDocToDestroy);
}

void PyApDocManagerReactor::documentDestroyedWr(const std::string& fileName)
{
    PyAutoLockGIL lock;
    if (override pyFunc = this->get_override("documentDestroyed"))
        pyFunc(fileName);
}

void PyApDocManagerReactor::documentCreateCanceledWr(PyApDocument& pDocCreateCancelled)
{
    PyAutoLockGIL lock;
    if (override pyFunc = this->get_override("documentCreateCanceled"))
        pyFunc(pDocCreateCancelled);
}

void PyApDocManagerReactor::documentLockModeWillChangeWr(PyApDocument& doc, AcAp::DocLockMode myCurrentMode, AcAp::DocLockMode myNewMode, AcAp::DocLockMode currentMode, const std::string& pGlobalCmdName)
{
    PyAutoLockGIL lock;
    if (override pyFunc = this->get_override("documentLockModeWillChange"))
        pyFunc(doc, myCurrentMode, myNewMode, currentMode, pGlobalCmdName);
}

void PyApDocManagerReactor::documentLockModeChangeVetoedWr(PyApDocument& doc, const std::string& pGlobalCmdName)
{
    PyAutoLockGIL lock;
    if (override pyFunc = this->get_override("documentLockModeChangeVetoed"))
        pyFunc(doc, pGlobalCmdName);
}

void PyApDocManagerReactor::documentLockModeChangedWr(PyApDocument& doc, AcAp::DocLockMode myPreviousMode, AcAp::DocLockMode myCurrentMode, AcAp::DocLockMode currentMode, const std::string& pGlobalCmdName)
{
    PyAutoLockGIL lock;
    if (override pyFunc = this->get_override("documentLockModeChanged"))
        pyFunc(doc, myPreviousMode, myCurrentMode, currentMode, pGlobalCmdName);
}

void PyApDocManagerReactor::documentBecameCurrentWr(PyApDocument& doc)
{
    PyAutoLockGIL lock;
    if (override pyFunc = this->get_override("documentBecameCurrent"))
        pyFunc(doc);
}

void PyApDocManagerReactor::documentToBeActivatedWr(PyApDocument& pActivatingDoc)
{
    PyAutoLockGIL lock;
    if (override pyFunc = this->get_override("documentToBeActivated"))
        pyFunc(pActivatingDoc);
}

void PyApDocManagerReactor::documentToBeDeactivatedWr(PyApDocument& pDeActivatedDoc)
{
    PyAutoLockGIL lock;
    if (override pyFunc = this->get_override("documentToBeDeactivated"))
        pyFunc(pDeActivatedDoc);
}

void PyApDocManagerReactor::documentActivationModifiedWr(bool bActivation)
{
    PyAutoLockGIL lock;
    if (override pyFunc = this->get_override("documentActivationModified"))
        pyFunc(bActivation);
}

void PyApDocManagerReactor::documentActivatedWr(PyApDocument& pActivatedDoc)
{
    PyAutoLockGIL lock;
    if (override pyFunc = this->get_override("documentActivated"))
        pyFunc(pActivatedDoc);
}

void PyApDocManagerReactor::addReactor()
{
    if (m_isActive)
    {
        acutPrintf(_T("\nReactor already rigistered"));
        return;
    }
    else
    {
        acDocManagerPtr()->addReactor(this);
        m_isActive = true;
    }
}

void PyApDocManagerReactor::removeReactor()
{
    acDocManagerPtr()->removeReactor(this);
    m_isActive = false;
   
}

//-----------------------------------------------------------------------------------------
//PyApDocManager Wrapper
void makeAcApDocManagerWrapper()
{
    class_<PyApDocManager, bases<PyRxObject>>("DocManager")
        .def("curDocument", &PyApDocManager::curDocument)
        .def("mdiActiveDocument", &PyApDocManager::mdiActiveDocument)
        .def("isApplicationContext", &PyApDocManager::isApplicationContext)
        .def("document", &PyApDocManager::document)
        .def("lockDocument", &PyApDocManager::lockDocument1)
        .def("lockDocument", &PyApDocManager::lockDocument2)
        .def("lockDocument", &PyApDocManager::lockDocument3)
        .def("unlockDocument", &PyApDocManager::unlockDocument)
        .def("newAcApDocumentIterator", &PyApDocManager::newAcApDocumentIterator)
        .def("setDefaultFormatForSave", &PyApDocManager::setDefaultFormatForSave)
        .def("defaultFormatForSave", &PyApDocManager::defaultFormatForSave)
        .def("setCurDocument", &PyApDocManager::setCurDocument1)
        .def("setCurDocument", &PyApDocManager::setCurDocument2)
        .def("activateDocument", &PyApDocManager::activateDocument1)
        .def("activateDocument", &PyApDocManager::activateDocument2)
        .def("sendStringToExecute", &PyApDocManager::sendStringToExecute1)
        .def("sendStringToExecute", &PyApDocManager::sendStringToExecute2)
        .def("appContextNewDocument", &PyApDocManager::appContextNewDocument)
        .def("appContextOpenDocument", &PyApDocManager::appContextOpenDocument)
        .def("appContextRecoverDocument", &PyApDocManager::appContextRecoverDocument)
        .def("appContextPromptOpenDocument", &PyApDocManager::appContextPromptOpenDocument)
        .def("appContextCloseDocument", &PyApDocManager::appContextCloseDocument)
        .def("newDocument", &PyApDocManager::newDocument)
        .def("openDocument", &PyApDocManager::openDocument)
        .def("closeDocument", &PyApDocManager::closeDocument)
        .def("inputPending", &PyApDocManager::inputPending)
        .def("disableDocumentActivation", &PyApDocManager::disableDocumentActivation)
        .def("enableDocumentActivation", &PyApDocManager::enableDocumentActivation)
        .def("isDocumentActivationEnabled", &PyApDocManager::isDocumentActivationEnabled)
        .def("documentCount", &PyApDocManager::documentCount)
        .def("pushAcadResourceHandle", &PyApDocManager::pushAcadResourceHandle)
        .def("popResourceHandle", &PyApDocManager::popResourceHandle)
        .def("sendModelessInterrupt", &PyApDocManager::sendModelessInterrupt)
        .def("className", &PyApDocManager::className).staticmethod("className")
        ;
}

//-----------------------------------------------------------------------------------------
//PyApDocManager

PyApDocManager::PyApDocManager(AcApDocManager* ptr, bool autoDelete)
    : PyRxObject(ptr, autoDelete, false)
{
}

PyApDocManager::PyApDocManager()
    : PyRxObject(acDocManagerPtr(), false, false)
{
}

PyApDocument PyApDocManager::curDocument()
{
    return PyApDocument(impObj()->curDocument(), false);
}

PyApDocument PyApDocManager::mdiActiveDocument()
{
    return PyApDocument(impObj()->mdiActiveDocument(), false);
}

bool PyApDocManager::isApplicationContext() const
{
    return impObj()->isApplicationContext();
}

PyApDocument PyApDocManager::document(const PyDbDatabase& db)
{
    return PyApDocument(impObj()->document(db.impObj()), false);
}

Acad::ErrorStatus PyApDocManager::lockDocument1(PyApDocument& pDoc)
{
    return impObj()->lockDocument(pDoc.impObj());
}

Acad::ErrorStatus PyApDocManager::lockDocument2(PyApDocument& pDoc, AcAp::DocLockMode mode)
{
    return impObj()->lockDocument(pDoc.impObj(), mode);
}

Acad::ErrorStatus PyApDocManager::lockDocument3(PyApDocument& pDoc, AcAp::DocLockMode mode, const std::string& pGlobalCmdName, const std::string pLocalCmdName, bool prompt)
{
    return impObj()->lockDocument(pDoc.impObj(), mode, utf8_to_wstr(pGlobalCmdName).c_str(), utf8_to_wstr(pLocalCmdName).c_str(), prompt);
}

Acad::ErrorStatus PyApDocManager::unlockDocument(PyApDocument& pDoc)
{
    return impObj()->unlockDocument(pDoc.impObj());
}

boost::python::list PyApDocManager::newAcApDocumentIterator()
{
    boost::python::list _list;
    for (std::unique_ptr<AcApDocumentIterator> iter(impObj()->newAcApDocumentIterator()); !iter->done(); iter->step())
        _list.append(PyApDocument(iter->document(), false));
    return _list;
}

Acad::ErrorStatus PyApDocManager::setDefaultFormatForSave(AcApDocument::SaveFormat format)
{
    return impObj()->setDefaultFormatForSave(format);
}

AcApDocument::SaveFormat PyApDocManager::defaultFormatForSave() const
{
    return impObj()->defaultFormatForSave();
}

Acad::ErrorStatus PyApDocManager::setCurDocument1(PyApDocument& pDoc)
{
    return impObj()->setCurDocument(pDoc.impObj());
}

Acad::ErrorStatus PyApDocManager::setCurDocument2(PyApDocument& pDoc, AcAp::DocLockMode mode, bool activate)
{
    return impObj()->setCurDocument(pDoc.impObj(), mode, activate);
}

Acad::ErrorStatus PyApDocManager::activateDocument1(PyApDocument& pAcTargetDocument)
{
    return impObj()->activateDocument(pAcTargetDocument.impObj());
}

Acad::ErrorStatus PyApDocManager::activateDocument2(PyApDocument& pAcTargetDocument, bool bPassScript)
{
    return impObj()->activateDocument(pAcTargetDocument.impObj(), bPassScript);
}

Acad::ErrorStatus PyApDocManager::sendStringToExecute1(PyApDocument& pAcTargetDocument, const std::string& pszExecute)
{
    return impObj()->sendStringToExecute(pAcTargetDocument.impObj(), utf8_to_wstr(pszExecute).c_str());
}

Acad::ErrorStatus PyApDocManager::sendStringToExecute2(PyApDocument& pAcTargetDocument, const std::string& pszExecute, bool bActivate, bool bWrapUpInactiveDoc, bool bEchoString)
{
    return impObj()->sendStringToExecute(pAcTargetDocument.impObj(), utf8_to_wstr(pszExecute).c_str(), bActivate, bWrapUpInactiveDoc, bEchoString);
}

Acad::ErrorStatus PyApDocManager::appContextNewDocument(const std::string& pszTemplateName)
{
    return impObj()->appContextNewDocument(utf8_to_wstr(pszTemplateName).c_str());
}

Acad::ErrorStatus PyApDocManager::appContextOpenDocument(const std::string& pszDrawingName)
{
    return impObj()->appContextOpenDocument(utf8_to_wstr(pszDrawingName).c_str());
}

Acad::ErrorStatus PyApDocManager::appContextRecoverDocument(const std::string& pszDrawingName)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->appContextRecoverDocument(utf8_to_wstr(pszDrawingName).c_str());
#endif
}

Acad::ErrorStatus PyApDocManager::appContextPromptNewDocument()
{
    return impObj()->appContextPromptNewDocument();
}

Acad::ErrorStatus PyApDocManager::appContextPromptOpenDocument()
{
    return impObj()->appContextPromptOpenDocument();
}

Acad::ErrorStatus PyApDocManager::appContextCloseDocument(PyApDocument& pDoc)
{
    return impObj()->appContextCloseDocument(pDoc.impObj());
}

Acad::ErrorStatus PyApDocManager::newDocument()
{
    return impObj()->newDocument();
}

Acad::ErrorStatus PyApDocManager::openDocument()
{
    return impObj()->openDocument();
}

Acad::ErrorStatus PyApDocManager::closeDocument(PyApDocument& pAcTargetDocument)
{
    return impObj()->closeDocument(pAcTargetDocument.impObj());
}

int PyApDocManager::inputPending(PyApDocument& pAcTargetDocument)
{
    return impObj()->inputPending(pAcTargetDocument.impObj());
}

Acad::ErrorStatus PyApDocManager::disableDocumentActivation()
{
    return impObj()->disableDocumentActivation();
}

Acad::ErrorStatus PyApDocManager::enableDocumentActivation()
{
    return impObj()->enableDocumentActivation();
}

bool PyApDocManager::isDocumentActivationEnabled()
{
    return impObj()->isDocumentActivationEnabled();
}

int PyApDocManager::documentCount() const
{
    return impObj()->documentCount();
}

void PyApDocManager::pushAcadResourceHandle()
{
    return impObj()->pushAcadResourceHandle();
}

void PyApDocManager::popResourceHandle()
{
    return impObj()->popResourceHandle();
}

Acad::ErrorStatus PyApDocManager::sendModelessInterrupt(PyApDocument& pAcTargetDocument)
{
    return impObj()->sendModelessInterrupt(pAcTargetDocument.impObj());
}

std::string PyApDocManager::className()
{
    return std::string{ "AcApDocManager" };
}

AcApDocManager* PyApDocManager::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcApDocManager*>(m_pImp.get());
}
