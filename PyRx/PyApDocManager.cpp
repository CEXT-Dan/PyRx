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
    if (reg_documentCreateStarted == false)
        return;
    PyApDocument doc(pDocCreating, false);
    documentCreateStartedWr(doc);
}

void PyApDocManagerReactor::documentCreated(AcApDocument* pDocCreating)
{
    if (reg_documentCreated == false)
        return;
    PyApDocument doc(pDocCreating, false);
    documentCreatedWr(doc);
}

void PyApDocManagerReactor::documentToBeDestroyed(AcApDocument* pDocToDestroy)
{
    if (reg_documentToBeDestroyed == false)
        return;
    PyApDocument doc(pDocToDestroy, false);
    documentToBeDestroyedWr(doc);
}

void PyApDocManagerReactor::documentDestroyed(const ACHAR* fileName)
{
    if (reg_documentDestroyed == false)
        return;
    documentDestroyedWr(wstr_to_utf8(fileName));
}

void PyApDocManagerReactor::documentCreateCanceled(AcApDocument* pDocCreateCancelled)
{
    if (reg_documentCreateCanceled == false)
        return;
    PyApDocument doc(pDocCreateCancelled, false);
    documentCreateCanceledWr(doc);
}

void PyApDocManagerReactor::documentLockModeWillChange(AcApDocument* pDoc, AcAp::DocLockMode myCurrentMode, AcAp::DocLockMode myNewMode, AcAp::DocLockMode currentMode, const ACHAR* pGlobalCmdName)
{
    if (reg_documentLockModeWillChange == false)
        return;
    PyApDocument doc(pDoc, false);
    documentLockModeWillChangeWr(doc, myCurrentMode, myNewMode, currentMode, wstr_to_utf8(pGlobalCmdName));
}

void PyApDocManagerReactor::documentLockModeChangeVetoed(AcApDocument* pdoc, const ACHAR* pGlobalCmdName)
{
    if (reg_documentLockModeChangeVetoed == false)
        return;
    PyApDocument doc(pdoc, false);
    documentLockModeChangeVetoedWr(doc, wstr_to_utf8(pGlobalCmdName));
}

void PyApDocManagerReactor::documentLockModeChanged(AcApDocument* pdoc, AcAp::DocLockMode myPreviousMode, AcAp::DocLockMode myCurrentMode, AcAp::DocLockMode currentMode, const ACHAR* pGlobalCmdName)
{
    if (reg_documentLockModeChanged == false)
        return;
    PyApDocument doc(pdoc, false);
    documentLockModeChangedWr(doc, myPreviousMode, myCurrentMode, currentMode, wstr_to_utf8(pGlobalCmdName));
}

void PyApDocManagerReactor::documentBecameCurrent(AcApDocument* pdoc)
{
    if (reg_documentBecameCurrent == false)
        return;
    PyApDocument doc(pdoc, false);
    documentBecameCurrentWr(doc);
}

void PyApDocManagerReactor::documentToBeActivated(AcApDocument* pActivatingDoc)
{
    if (reg_documentToBeActivated == false)
        return;
    PyApDocument doc(pActivatingDoc, false);
    documentToBeActivatedWr(doc);
}

void PyApDocManagerReactor::documentToBeDeactivated(AcApDocument* pDeActivatedDoc)
{
    if (reg_documentToBeDeactivated == false)
        return;
    PyApDocument doc(pDeActivatedDoc, false);
    documentToBeDeactivatedWr(doc);
}

void PyApDocManagerReactor::documentActivationModified(bool bActivation)
{
    if (reg_documentActivationModified == false)
        return;
    documentActivationModifiedWr(bActivation);
}

void PyApDocManagerReactor::documentActivated(AcApDocument* pActivatedDoc)
{
    if (reg_documentActivated == false)
        return;
    PyApDocument doc(pActivatedDoc, false);
    documentActivatedWr(doc);
}

void PyApDocManagerReactor::documentCreateStartedWr(PyApDocument& pDocCreating)
{
    PyAutoLockGIL lock;
    try
    {
        if (override pyFunc = this->get_override("documentCreateStarted"))
            pyFunc(pDocCreating);
        else
            reg_documentCreateStarted = false;
    }
    catch (...)
    {
        reg_documentCreateStarted = false;
    }
}

void PyApDocManagerReactor::documentCreatedWr(PyApDocument& pDocCreating)
{
    PyAutoLockGIL lock;
    try
    {
        if (override pyFunc = this->get_override("documentCreated"))
            pyFunc(pDocCreating);
        else
            reg_documentCreated = false;
    }
    catch (...)
    {
        reg_documentCreated = false;
    }
}

void PyApDocManagerReactor::documentToBeDestroyedWr(PyApDocument& pDocToDestroy)
{
    PyAutoLockGIL lock;
    try
    {
        if (override pyFunc = this->get_override("documentToBeDestroyed"))
            pyFunc(pDocToDestroy);
        else
            reg_documentToBeDestroyed = false;
    }
    catch (...)
    {
        reg_documentToBeDestroyed = false;
    }
}

void PyApDocManagerReactor::documentDestroyedWr(const std::string& fileName)
{
    PyAutoLockGIL lock;
    try
    {
        if (override pyFunc = this->get_override("documentDestroyed"))
            pyFunc(fileName);
        else
            reg_documentDestroyed = false;
    }
    catch (...)
    {
        reg_documentDestroyed = false;
    }
}

void PyApDocManagerReactor::documentCreateCanceledWr(PyApDocument& pDocCreateCancelled)
{
    PyAutoLockGIL lock;
    try
    {
        if (override pyFunc = this->get_override("documentCreateCanceled"))
            pyFunc(pDocCreateCancelled);
        else
            reg_documentCreateCanceled = false;
    }
    catch (...)
    {
        reg_documentCreateCanceled = false;
    }
}

void PyApDocManagerReactor::documentLockModeWillChangeWr(PyApDocument& doc, AcAp::DocLockMode myCurrentMode, AcAp::DocLockMode myNewMode, AcAp::DocLockMode currentMode, const std::string& pGlobalCmdName)
{
    PyAutoLockGIL lock;
    try
    {
        if (override pyFunc = this->get_override("documentLockModeWillChange"))
            pyFunc(doc, myCurrentMode, myNewMode, currentMode, pGlobalCmdName);
        else
            reg_documentLockModeWillChange = false;
    }
    catch (...)
    {
        reg_documentLockModeWillChange = false;
    }
}

void PyApDocManagerReactor::documentLockModeChangeVetoedWr(PyApDocument& doc, const std::string& pGlobalCmdName)
{
    PyAutoLockGIL lock;
    try
    {
        if (override pyFunc = this->get_override("documentLockModeChangeVetoed"))
            pyFunc(doc, pGlobalCmdName);
        else
            reg_documentLockModeChangeVetoed = false;
    }
    catch (...)
    {
        reg_documentLockModeChangeVetoed = false;
    }
}

void PyApDocManagerReactor::documentLockModeChangedWr(PyApDocument& doc, AcAp::DocLockMode myPreviousMode, AcAp::DocLockMode myCurrentMode, AcAp::DocLockMode currentMode, const std::string& pGlobalCmdName)
{
    PyAutoLockGIL lock;
    try
    {
        if (override pyFunc = this->get_override("documentLockModeChanged"))
            pyFunc(doc, myPreviousMode, myCurrentMode, currentMode, pGlobalCmdName);
        else
            reg_documentLockModeChanged = false;
    }
    catch (...)
    {
        reg_documentLockModeChanged = false;
    }
}

void PyApDocManagerReactor::documentBecameCurrentWr(PyApDocument& doc)
{
    PyAutoLockGIL lock;
    try
    {
        if (override pyFunc = this->get_override("documentBecameCurrent"))
            pyFunc(doc);
        else
            reg_documentBecameCurrent = false;
    }
    catch (...)
    {
        reg_documentBecameCurrent = false;
    }
}

void PyApDocManagerReactor::documentToBeActivatedWr(PyApDocument& pActivatingDoc)
{
    PyAutoLockGIL lock;
    try
    {
        if (override pyFunc = this->get_override("documentToBeActivated"))
            pyFunc(pActivatingDoc);
        else
            reg_documentToBeActivated = false;
    }
    catch (...)
    {
        reg_documentToBeActivated = false;
    }
}

void PyApDocManagerReactor::documentToBeDeactivatedWr(PyApDocument& pDeActivatedDoc)
{
    PyAutoLockGIL lock;
    try
    {
        if (override pyFunc = this->get_override("documentToBeDeactivated"))
            pyFunc(pDeActivatedDoc);
        else
            reg_documentToBeDeactivated = false;
    }
    catch (...)
    {
        reg_documentToBeDeactivated = false;
    }
}

void PyApDocManagerReactor::documentActivationModifiedWr(bool bActivation)
{
    PyAutoLockGIL lock;
    try
    {
        if (override pyFunc = this->get_override("documentActivationModified"))
            pyFunc(bActivation);
        else
            reg_documentActivationModified = false;
    }
    catch (...)
    {
        reg_documentActivationModified = false;
    }
}

void PyApDocManagerReactor::documentActivatedWr(PyApDocument& pActivatedDoc)
{
    PyAutoLockGIL lock;
    try
    {
        if (override pyFunc = this->get_override("documentActivated"))
            pyFunc(pActivatedDoc);
        else
            reg_documentActivated = false;
    }
    catch (...)
    {
        reg_documentActivated = false;
    }
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
    if (m_isActive = true)
    {
        acDocManagerPtr()->removeReactor(this);
        m_isActive = false;
    }
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
        .def("autoLock", &PyApDocManager::autoLock).staticmethod("autoLock")
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

void PyApDocManager::lockDocument1(PyApDocument& pDoc)
{
    return PyThrowBadEs(impObj()->lockDocument(pDoc.impObj()));
}

void PyApDocManager::lockDocument2(PyApDocument& pDoc, AcAp::DocLockMode mode)
{
    return PyThrowBadEs(impObj()->lockDocument(pDoc.impObj(), mode));
}

void PyApDocManager::lockDocument3(PyApDocument& pDoc, AcAp::DocLockMode mode, const std::string& pGlobalCmdName, const std::string pLocalCmdName, bool prompt)
{
    return PyThrowBadEs(impObj()->lockDocument(pDoc.impObj(), mode, utf8_to_wstr(pGlobalCmdName).c_str(), utf8_to_wstr(pLocalCmdName).c_str(), prompt));
}

void PyApDocManager::unlockDocument(PyApDocument& pDoc)
{
    return PyThrowBadEs(impObj()->unlockDocument(pDoc.impObj()));
}

boost::python::list PyApDocManager::newAcApDocumentIterator()
{
    PyAutoLockGIL lock;
    boost::python::list _list;
    for (std::unique_ptr<AcApDocumentIterator> iter(impObj()->newAcApDocumentIterator()); !iter->done(); iter->step())
        _list.append(PyApDocument(iter->document(), false));
    return _list;
}

void PyApDocManager::setDefaultFormatForSave(AcApDocument::SaveFormat format)
{
    return PyThrowBadEs(impObj()->setDefaultFormatForSave(format));
}

AcApDocument::SaveFormat PyApDocManager::defaultFormatForSave() const
{
    return impObj()->defaultFormatForSave();
}

void PyApDocManager::setCurDocument1(PyApDocument& pDoc)
{
    return PyThrowBadEs(impObj()->setCurDocument(pDoc.impObj()));
}

void PyApDocManager::setCurDocument2(PyApDocument& pDoc, AcAp::DocLockMode mode, bool activate)
{
    return PyThrowBadEs(impObj()->setCurDocument(pDoc.impObj(), mode, activate));
}

void PyApDocManager::activateDocument1(PyApDocument& pAcTargetDocument)
{
    return PyThrowBadEs(impObj()->activateDocument(pAcTargetDocument.impObj()));
}

void PyApDocManager::activateDocument2(PyApDocument& pAcTargetDocument, bool bPassScript)
{
    return PyThrowBadEs(impObj()->activateDocument(pAcTargetDocument.impObj(), bPassScript));
}

void PyApDocManager::sendStringToExecute1(PyApDocument& pAcTargetDocument, const std::string& pszExecute)
{
    return PyThrowBadEs(impObj()->sendStringToExecute(pAcTargetDocument.impObj(), utf8_to_wstr(pszExecute).c_str()));
}

void PyApDocManager::sendStringToExecute2(PyApDocument& pAcTargetDocument, const std::string& pszExecute, bool bActivate, bool bWrapUpInactiveDoc, bool bEchoString)
{
    return PyThrowBadEs(impObj()->sendStringToExecute(pAcTargetDocument.impObj(), utf8_to_wstr(pszExecute).c_str(), bActivate, bWrapUpInactiveDoc, bEchoString));
}

void PyApDocManager::appContextNewDocument(const std::string& pszTemplateName)
{
    return PyThrowBadEs(impObj()->appContextNewDocument(utf8_to_wstr(pszTemplateName).c_str()));
}

void PyApDocManager::appContextOpenDocument(const std::string& pszDrawingName)
{
    return PyThrowBadEs(impObj()->appContextOpenDocument(utf8_to_wstr(pszDrawingName).c_str()));
}

void PyApDocManager::appContextRecoverDocument(const std::string& pszDrawingName)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->appContextRecoverDocument(utf8_to_wstr(pszDrawingName).c_str()));
#endif
}

void PyApDocManager::appContextPromptNewDocument()
{
    return PyThrowBadEs(impObj()->appContextPromptNewDocument());
}

void PyApDocManager::appContextPromptOpenDocument()
{
    return PyThrowBadEs(impObj()->appContextPromptOpenDocument());
}

void PyApDocManager::appContextCloseDocument(PyApDocument& pDoc)
{
    return PyThrowBadEs(impObj()->appContextCloseDocument(pDoc.impObj()));
}

void PyApDocManager::newDocument()
{
    return PyThrowBadEs(impObj()->newDocument());
}

void PyApDocManager::openDocument()
{
    return PyThrowBadEs(impObj()->openDocument());
}

void PyApDocManager::closeDocument(PyApDocument& pAcTargetDocument)
{
    return PyThrowBadEs(impObj()->closeDocument(pAcTargetDocument.impObj()));
}

int PyApDocManager::inputPending(PyApDocument& pAcTargetDocument)
{
    return impObj()->inputPending(pAcTargetDocument.impObj());
}

void PyApDocManager::disableDocumentActivation()
{
    return PyThrowBadEs(impObj()->disableDocumentActivation());
}

void PyApDocManager::enableDocumentActivation()
{
    return PyThrowBadEs(impObj()->enableDocumentActivation());
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

void PyApDocManager::sendModelessInterrupt(PyApDocument& pAcTargetDocument)
{
    return PyThrowBadEs(impObj()->sendModelessInterrupt(pAcTargetDocument.impObj()));
}

PyAutoDocLock PyApDocManager::autoLock()
{
    return PyAutoDocLock{};
}

std::string PyApDocManager::className()
{
    return std::string{ "AcApDocManager" };
}

AcApDocManager* PyApDocManager::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcApDocManager*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
//PyAutoDocLock
void makePyAutoDocLockWrapper()
{
    class_<PyAutoDocLock>("AutoDocLock")
        .def("className", &PyAutoDocLock::className).staticmethod("className")
        ;
}

PyAutoDocLockImp::PyAutoDocLockImp()
{
    pDoc = curDoc();
    if (pDoc != nullptr)
        acDocManagerPtr()->lockDocument(pDoc);
}

PyAutoDocLockImp::~PyAutoDocLockImp()
{
    if (pDoc != nullptr)
        acDocManagerPtr()->unlockDocument(pDoc);
}

PyAutoDocLock::PyAutoDocLock()
    : imp(new PyAutoDocLockImp())
{
}

PyAutoDocLock::~PyAutoDocLock()
{
}

std::string PyAutoDocLock::className()
{
    return "AutoDocLock";
}
