#include "stdafx.h"
#include "PyApDocManager.h"
#include "PyApDocument.h"
#include "PyDbDatabase.h"

using namespace boost::python;

//-----------------------------------------------------------------------------------------
//PyApDocManagerReactor
void makePyApDocManagerReactorWrapper()
{
    PyDocString DS("DocManagerReactor");
    class_<PyApDocManagerReactor, boost::noncopyable>("DocManagerReactor")
        .def(init<>(DS.ARGS(78)))
        .def("documentCreateStarted", &PyApDocManagerReactor::documentCreateStartedWr, DS.ARGS({ "doc : Document" }, 85))
        .def("documentCreated", &PyApDocManagerReactor::documentCreatedWr, DS.ARGS({ "doc : Document" }, 84))
        .def("documentToBeDestroyed", &PyApDocManagerReactor::documentToBeDestroyedWr, DS.ARGS({ "doc : Document" }, 93))
        .def("documentDestroyed", &PyApDocManagerReactor::documentDestroyedWr, DS.ARGS({ "doc : str" }, 86))
        .def("documentCreateCanceled", &PyApDocManagerReactor::documentCreateCanceledWr, DS.ARGS({ "doc : Document" }, 83))
        .def("documentLockModeWillChange", &PyApDocManagerReactor::documentLockModeWillChangeWr, DS.ARGS({ "myCurMode : DocLockMode","myNewMode : DocLockMode" ,"curMode : DocLockMode","globalCmdName : str" }, 89))
        .def("documentLockModeChangeVetoed", &PyApDocManagerReactor::documentLockModeChangeVetoedWr, DS.ARGS({ "doc : Document", "globalCmdName : str" }, 88))
        .def("documentLockModeChanged", &PyApDocManagerReactor::documentLockModeChangedWr, DS.ARGS({ "doc : Document","myPrevMode : DocLockMode" ,"myCurMode : DocLockMode","currentMode : DocLockMode","globalCmdName : str" }, 87))
        .def("documentBecameCurrent", &PyApDocManagerReactor::documentBecameCurrentWr, DS.ARGS({ "doc : Document" }, 82))
        .def("documentToBeActivated", &PyApDocManagerReactor::documentToBeActivatedWr, DS.ARGS({ "doc : Document" }, 91))
        .def("documentToBeDeactivated", &PyApDocManagerReactor::documentToBeDeactivatedWr, DS.ARGS({ "doc : Document" }, 92))
        .def("documentActivationModified", &PyApDocManagerReactor::documentActivationModifiedWr, DS.ARGS({ "doc : bool" }, 81))
        .def("documentActivated", &PyApDocManagerReactor::documentActivatedWr, DS.ARGS({ "doc : Document" }, 80))
        .def("addReactor", &PyApDocManagerReactor::addReactor, DS.ARGS(97))
        .def("removeReactor", &PyApDocManagerReactor::removeReactor, DS.ARGS(127))
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
        if (const override& pyFunc = this->get_override("documentCreateStarted"))
            pyFunc(pDocCreating);
        else
            reg_documentCreateStarted = false;
    }
    catch (...)
    {
        reg_documentCreateStarted = false;
        printExceptionMsg();
    }
}

void PyApDocManagerReactor::documentCreatedWr(PyApDocument& pDocCreating)
{
    PyAutoLockGIL lock;
    try
    {
        if (const override& pyFunc = this->get_override("documentCreated"))
            pyFunc(pDocCreating);
        else
            reg_documentCreated = false;
    }
    catch (...)
    {
        reg_documentCreated = false;
        printExceptionMsg();
    }
}

void PyApDocManagerReactor::documentToBeDestroyedWr(PyApDocument& pDocToDestroy)
{
    PyAutoLockGIL lock;
    try
    {
        if (const override& pyFunc = this->get_override("documentToBeDestroyed"))
            pyFunc(pDocToDestroy);
        else
            reg_documentToBeDestroyed = false;
    }
    catch (...)
    {
        reg_documentToBeDestroyed = false;
        printExceptionMsg();
    }
}

void PyApDocManagerReactor::documentDestroyedWr(const std::string& fileName)
{
    PyAutoLockGIL lock;
    try
    {
        if (const override& pyFunc = this->get_override("documentDestroyed"))
            pyFunc(fileName);
        else
            reg_documentDestroyed = false;
    }
    catch (...)
    {
        reg_documentDestroyed = false;
        printExceptionMsg();
    }
}

void PyApDocManagerReactor::documentCreateCanceledWr(PyApDocument& pDocCreateCancelled)
{
    PyAutoLockGIL lock;
    try
    {
        if (const override& pyFunc = this->get_override("documentCreateCanceled"))
            pyFunc(pDocCreateCancelled);
        else
            reg_documentCreateCanceled = false;
    }
    catch (...)
    {
        reg_documentCreateCanceled = false;
        printExceptionMsg();
    }
}

void PyApDocManagerReactor::documentLockModeWillChangeWr(PyApDocument& doc, AcAp::DocLockMode myCurrentMode, AcAp::DocLockMode myNewMode, AcAp::DocLockMode currentMode, const std::string& pGlobalCmdName)
{
    PyAutoLockGIL lock;
    try
    {
        if (const override& pyFunc = this->get_override("documentLockModeWillChange"))
            pyFunc(doc, myCurrentMode, myNewMode, currentMode, pGlobalCmdName);
        else
            reg_documentLockModeWillChange = false;
    }
    catch (...)
    {
        reg_documentLockModeWillChange = false;
        printExceptionMsg();
    }
}

void PyApDocManagerReactor::documentLockModeChangeVetoedWr(PyApDocument& doc, const std::string& pGlobalCmdName)
{
    PyAutoLockGIL lock;
    try
    {
        if (const override& pyFunc = this->get_override("documentLockModeChangeVetoed"))
            pyFunc(doc, pGlobalCmdName);
        else
            reg_documentLockModeChangeVetoed = false;
    }
    catch (...)
    {
        reg_documentLockModeChangeVetoed = false;
        printExceptionMsg();
    }
}

void PyApDocManagerReactor::documentLockModeChangedWr(PyApDocument& doc, AcAp::DocLockMode myPreviousMode, AcAp::DocLockMode myCurrentMode, AcAp::DocLockMode currentMode, const std::string& pGlobalCmdName)
{
    PyAutoLockGIL lock;
    try
    {
        if (const override& pyFunc = this->get_override("documentLockModeChanged"))
            pyFunc(doc, myPreviousMode, myCurrentMode, currentMode, pGlobalCmdName);
        else
            reg_documentLockModeChanged = false;
    }
    catch (...)
    {
        reg_documentLockModeChanged = false;
        printExceptionMsg();
    }
}

void PyApDocManagerReactor::documentBecameCurrentWr(PyApDocument& doc)
{
    PyAutoLockGIL lock;
    try
    {
        if (const override& pyFunc = this->get_override("documentBecameCurrent"))
            pyFunc(doc);
        else
            reg_documentBecameCurrent = false;
    }
    catch (...)
    {
        reg_documentBecameCurrent = false;
        printExceptionMsg();
    }
}

void PyApDocManagerReactor::documentToBeActivatedWr(PyApDocument& pActivatingDoc)
{
    PyAutoLockGIL lock;
    try
    {
        if (const override& pyFunc = this->get_override("documentToBeActivated"))
            pyFunc(pActivatingDoc);
        else
            reg_documentToBeActivated = false;
    }
    catch (...)
    {
        reg_documentToBeActivated = false;
        printExceptionMsg();
    }
}

void PyApDocManagerReactor::documentToBeDeactivatedWr(PyApDocument& pDeActivatedDoc)
{
    PyAutoLockGIL lock;
    try
    {
        if (const override& pyFunc = this->get_override("documentToBeDeactivated"))
            pyFunc(pDeActivatedDoc);
        else
            reg_documentToBeDeactivated = false;
    }
    catch (...)
    {
        reg_documentToBeDeactivated = false;
        printExceptionMsg();
    }
}

void PyApDocManagerReactor::documentActivationModifiedWr(bool bActivation)
{
    PyAutoLockGIL lock;
    try
    {
        if (const override& pyFunc = this->get_override("documentActivationModified"))
            pyFunc(bActivation);
        else
            reg_documentActivationModified = false;
    }
    catch (...)
    {
        reg_documentActivationModified = false;
        printExceptionMsg();
    }
}

void PyApDocManagerReactor::documentActivatedWr(PyApDocument& pActivatedDoc)
{
    PyAutoLockGIL lock;
    try
    {
        if (const override& pyFunc = this->get_override("documentActivated"))
            pyFunc(pActivatedDoc);
        else
            reg_documentActivated = false;
    }
    catch (...)
    {
        reg_documentActivated = false;
        printExceptionMsg();
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
    if (m_isActive == true)
    {
        acDocManagerPtr()->removeReactor(this);
        m_isActive = false;
    }
}

//-----------------------------------------------------------------------------------------
//PyApDocManager Wrapper
void makePyApDocManagerWrapper()
{
    PyDocString DS("DocManager");
    class_<PyApDocManager, bases<PyRxObject>>("DocManager")
        .def(init<>(DS.ARGS(77)))
        .def("curDocument", &PyApDocManager::curDocument, DS.ARGS(107))
        .def("mdiActiveDocument", &PyApDocManager::mdiActiveDocument, DS.ARGS(121))
        .def("isApplicationContext", &PyApDocManager::isApplicationContext, DS.ARGS(118))
        .def("document", &PyApDocManager::document, DS.ARGS({ "db: PyDb.Database" }, 112))
        .def("lockDocument", &PyApDocManager::lockDocument1)
        .def("lockDocument", &PyApDocManager::lockDocument2)
        .def("lockDocument", &PyApDocManager::lockDocument3, DS.ARGS({ "doc: PyAp.Document", "mode: PyAp.DocLockMode = kWrite","gcmd: str = ...","lcmd: str = ...","prmt: bool = True" }, 120))
        .def("unlockDocument", &PyApDocManager::unlockDocument, DS.ARGS({ "doc: PyAp.Document" }, 132))
        .def("documents", &PyApDocManager::newAcApDocumentIterator, DS.ARGS())
        .def("setDefaultFormatForSave", &PyApDocManager::setDefaultFormatForSave, DS.ARGS({ "fmt : PyAp.SaveFormat" }, 131))
        .def("defaultFormatForSave", &PyApDocManager::defaultFormatForSave, DS.ARGS(108))
        .def("setCurDocument", &PyApDocManager::setCurDocument1)
        .def("setCurDocument", &PyApDocManager::setCurDocument2, DS.ARGS({ "doc: PyAp.Document", "mode: PyAp.DocLockMode = kNone","activate: bool = False" }, 130))
        .def("activateDocument", &PyApDocManager::activateDocument1)
        .def("activateDocument", &PyApDocManager::activateDocument2, DS.ARGS({ "doc: PyAp.Document","bPassScript: bool = False" }, 96))
        .def("sendStringToExecute", &PyApDocManager::sendStringToExecute1)
        .def("sendStringToExecute", &PyApDocManager::sendStringToExecute2, DS.ARGS({ "doc: PyAp.Document","script: str","bActivate: bool = True","bWrapUpInactiveDoc: bool = False","bEchoString: bool = True" }, 129))
        .def("appContextNewDocument", &PyApDocManager::appContextNewDocument, DS.ARGS({ "templateName : str" }, 99))
        .def("appContextOpenDocument", &PyApDocManager::appContextOpenDocument, DS.ARGS({ "dwgName : str" }, 100))
        .def("appContextRecoverDocument", &PyApDocManager::appContextRecoverDocument, DS.ARGS({ "dwgName : str" }, 103))
        .def("appContextPromptOpenDocument", &PyApDocManager::appContextPromptOpenDocument, DS.ARGS(102))
        .def("appContextCloseDocument", &PyApDocManager::appContextCloseDocument, DS.ARGS({ "doc: PyAp.Document" }, 98))
        .def("newDocument", &PyApDocManager::newDocument, DS.ARGS(123))
        .def("openDocument", &PyApDocManager::openDocument, DS.ARGS(124))
        .def("closeDocument", &PyApDocManager::closeDocument, DS.ARGS({ "doc: PyAp.Document" }, 106))
        .def("inputPending", &PyApDocManager::inputPending, DS.ARGS({ "doc: PyAp.Document" }, 117))
        .def("disableDocumentActivation", &PyApDocManager::disableDocumentActivation, DS.ARGS(109))
        .def("enableDocumentActivation", &PyApDocManager::enableDocumentActivation, DS.ARGS(114))
        .def("isDocumentActivationEnabled", &PyApDocManager::isDocumentActivationEnabled, DS.ARGS(119))
        .def("documentCount", &PyApDocManager::documentCount, DS.ARGS(113))
        .def("pushAcadResourceHandle", &PyApDocManager::pushAcadResourceHandle, DS.ARGS(126))
        .def("popResourceHandle", &PyApDocManager::popResourceHandle, DS.ARGS(125))
        .def("sendModelessInterrupt", &PyApDocManager::sendModelessInterrupt, DS.ARGS({ "doc: PyAp.Document" }, 128))
        .def("executeInApplicationContext", &PyApDocManager::executeInApplicationContext, DS.ARGS({ "func: Any","data: Any" }, 115))
        .def("beginExecuteInCommandContext", &PyApDocManager::beginExecuteInCommandContext, DS.ARGS({ "func: Any","data: Any" }, 105))
        .def("beginExecuteInApplicationContext", &PyApDocManager::beginExecuteInApplicationContext, DS.ARGS({ "func: Any","data: Any" }, 104))
        .def("autoLock", &PyApDocManager::autoLock1)
        .def("autoLock", &PyApDocManager::autoLock2, DS.SARGS({ "docToLock: PyAp.Document = ..." }, 120)).staticmethod("autoLock")
        .def("className", &PyApDocManager::className, DS.SARGS()).staticmethod("className")
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

PyApDocument PyApDocManager::curDocument() const
{
    return PyApDocument(impObj()->curDocument(), false);
}

PyApDocument PyApDocManager::mdiActiveDocument() const
{
    return PyApDocument(impObj()->mdiActiveDocument(), false);
}

bool PyApDocManager::isApplicationContext() const
{
    return impObj()->isApplicationContext();
}

PyApDocument PyApDocManager::document(const PyDbDatabase& db) const
{
    return PyApDocument(impObj()->document(db.impObj()), false);
}

void PyApDocManager::lockDocument1(PyApDocument& pDoc) const
{
    return PyThrowBadEs(impObj()->lockDocument(pDoc.impObj()));
}

void PyApDocManager::lockDocument2(PyApDocument& pDoc, AcAp::DocLockMode mode) const
{
    return PyThrowBadEs(impObj()->lockDocument(pDoc.impObj(), mode));
}

void PyApDocManager::lockDocument3(PyApDocument& pDoc, AcAp::DocLockMode mode, const std::string& pGlobalCmdName, const std::string& pLocalCmdName, bool prompt) const
{
    return PyThrowBadEs(impObj()->lockDocument(pDoc.impObj(), mode, utf8_to_wstr(pGlobalCmdName).c_str(), utf8_to_wstr(pLocalCmdName).c_str(), prompt));
}

void PyApDocManager::unlockDocument(PyApDocument& pDoc) const
{
    return PyThrowBadEs(impObj()->unlockDocument(pDoc.impObj()));
}

boost::python::list PyApDocManager::newAcApDocumentIterator() const
{
    PyAutoLockGIL lock;
    boost::python::list _list;
    for (std::unique_ptr<AcApDocumentIterator> iter(impObj()->newAcApDocumentIterator()); !iter->done(); iter->step())
        _list.append(PyApDocument(iter->document(), false));
    return _list;
}

void PyApDocManager::setDefaultFormatForSave(AcApDocument::SaveFormat format) const
{
    return PyThrowBadEs(impObj()->setDefaultFormatForSave(format));
}

AcApDocument::SaveFormat PyApDocManager::defaultFormatForSave() const
{
    return impObj()->defaultFormatForSave();
}

void PyApDocManager::setCurDocument1(PyApDocument& pDoc) const
{
    return PyThrowBadEs(impObj()->setCurDocument(pDoc.impObj()));
}

void PyApDocManager::setCurDocument2(PyApDocument& pDoc, AcAp::DocLockMode mode, bool activate) const
{
    return PyThrowBadEs(impObj()->setCurDocument(pDoc.impObj(), mode, activate));
}

void PyApDocManager::activateDocument1(PyApDocument& pAcTargetDocument) const
{
    return PyThrowBadEs(impObj()->activateDocument(pAcTargetDocument.impObj()));
}

void PyApDocManager::activateDocument2(PyApDocument& pAcTargetDocument, bool bPassScript) const
{
    return PyThrowBadEs(impObj()->activateDocument(pAcTargetDocument.impObj(), bPassScript));
}

void PyApDocManager::sendStringToExecute1(PyApDocument& pAcTargetDocument, const std::string& pszExecute) const
{
    return PyThrowBadEs(impObj()->sendStringToExecute(pAcTargetDocument.impObj(), utf8_to_wstr(pszExecute).c_str()));
}

void PyApDocManager::sendStringToExecute2(PyApDocument& pAcTargetDocument, const std::string& pszExecute, bool bActivate, bool bWrapUpInactiveDoc, bool bEchoString) const
{
    return PyThrowBadEs(impObj()->sendStringToExecute(pAcTargetDocument.impObj(), utf8_to_wstr(pszExecute).c_str(), bActivate, bWrapUpInactiveDoc, bEchoString));
}

void PyApDocManager::appContextNewDocument(const std::string& pszTemplateName) const
{
    return PyThrowBadEs(impObj()->appContextNewDocument(utf8_to_wstr(pszTemplateName).c_str()));
}

void PyApDocManager::appContextOpenDocument(const std::string& pszDrawingName) const
{
    return PyThrowBadEs(impObj()->appContextOpenDocument(utf8_to_wstr(pszDrawingName).c_str()));
}

void PyApDocManager::appContextRecoverDocument(const std::string& pszDrawingName) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->appContextRecoverDocument(utf8_to_wstr(pszDrawingName).c_str()));
#endif
}

void PyApDocManager::appContextPromptNewDocument() const
{
    return PyThrowBadEs(impObj()->appContextPromptNewDocument());
}

void PyApDocManager::appContextPromptOpenDocument() const
{
    return PyThrowBadEs(impObj()->appContextPromptOpenDocument());
}

void PyApDocManager::appContextCloseDocument(PyApDocument& pDoc) const
{
    return PyThrowBadEs(impObj()->appContextCloseDocument(pDoc.impObj()));
}

void PyApDocManager::newDocument() const
{
    return PyThrowBadEs(impObj()->newDocument());
}

void PyApDocManager::openDocument() const
{
    return PyThrowBadEs(impObj()->openDocument());
}

void PyApDocManager::closeDocument(PyApDocument& pAcTargetDocument) const
{
    return PyThrowBadEs(impObj()->closeDocument(pAcTargetDocument.impObj()));
}

int PyApDocManager::inputPending(PyApDocument& pAcTargetDocument) const
{
    return impObj()->inputPending(pAcTargetDocument.impObj());
}

void PyApDocManager::disableDocumentActivation() const
{
    return PyThrowBadEs(impObj()->disableDocumentActivation());
}

void PyApDocManager::enableDocumentActivation() const
{
    return PyThrowBadEs(impObj()->enableDocumentActivation());
}

bool PyApDocManager::isDocumentActivationEnabled() const
{
    return impObj()->isDocumentActivationEnabled();
}

int PyApDocManager::documentCount() const
{
    return impObj()->documentCount();
}

void PyApDocManager::pushAcadResourceHandle() const
{
    return impObj()->pushAcadResourceHandle();
}

void PyApDocManager::popResourceHandle() const
{
    return impObj()->popResourceHandle();
}

void PyApDocManager::sendModelessInterrupt(PyApDocument& pAcTargetDocument) const
{
    return PyThrowBadEs(impObj()->sendModelessInterrupt(pAcTargetDocument.impObj()));
}

static void executePyFunc(const boost::python::object& func, const boost::python::object& data)
{
    try
    {
        if (PyCallable_Check(func.ptr()))
        {
            PyErr_Clear();
            boost::python::call<void>(func.ptr(), data);
            return;
        }
    }
    catch (...)
    {
        PyThrowBadEs(eInvalidInput);
    }
    acutPrintf(_T("\nexecuteFunc failed"));
}

static void executeFunc(void* ptr /*not used*/)
{
    PyAutoLockGIL lock;
    if (PyApDocManager::mspExecData)
    {
        executePyFunc(PyApDocManager::mspExecData->first, PyApDocManager::mspExecData->second);
        PyApDocManager::mspExecData.reset();
    }
}

void PyApDocManager::executeInApplicationContext(const boost::python::object& func, const boost::python::object& data) const
{
    mspExecData.reset(new ExecData{ func, data });
    return impObj()->executeInApplicationContext(executeFunc, nullptr);
}

Acad::ErrorStatus PyApDocManager::beginExecuteInCommandContext(const boost::python::object& func, const boost::python::object& data) const
{
#if defined(_BRXTARGET240)
    throw PyNotimplementedByHost();
#else
    mspExecData.reset(new ExecData{ func, data });
    return impObj()->beginExecuteInCommandContext(executeFunc, nullptr);
#endif
}

Acad::ErrorStatus PyApDocManager::beginExecuteInApplicationContext(const boost::python::object& func, const boost::python::object& data) const
{
#if defined(_BRXTARGET240)
    throw PyNotimplementedByHost();
#else
    mspExecData.reset(new ExecData{ func, data });
    return impObj()->beginExecuteInApplicationContext(executeFunc, nullptr);
#endif
}

PyAutoDocLock PyApDocManager::autoLock1()
{
    return PyAutoDocLock{};
}

PyAutoDocLock PyApDocManager::autoLock2(const PyApDocument& doc)
{
    return PyAutoDocLock{ doc };
}

std::string PyApDocManager::className()
{
    return std::string{ "AcApDocManager" };
}

AcApDocManager* PyApDocManager::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcApDocManager*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
//PyAutoDocLock
void makePyAutoDocLockWrapper()
{
    PyDocString DS("AutoDocLock");
    class_<PyAutoDocLock>("AutoDocLock")
        .def(init<>())
        .def(init<const PyApDocument&>(DS.ARGS({ "docToLock: PyAp.Document = ..." }, 120)))
        .def("doc", &PyAutoDocLock::doc, DS.ARGS())
        .def("className", &PyAutoDocLock::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAutoDocLockImp::PyAutoDocLockImp()
    : pDoc(curDoc())
{
    PyThrowBadEs(acDocManagerPtr()->disableDocumentActivation());
    PyThrowBadEs(acDocManagerPtr()->lockDocument(pDoc));
}

PyAutoDocLockImp::PyAutoDocLockImp(AcApDocument* doc)
    : pDoc(doc)
{
    PyThrowBadEs(acDocManagerPtr()->disableDocumentActivation());
    PyThrowBadEs(acDocManagerPtr()->lockDocument(pDoc));
}

PyAutoDocLockImp::~PyAutoDocLockImp()
{
    PyThrowBadEs(acDocManagerPtr()->enableDocumentActivation());
    PyThrowBadEs(acDocManagerPtr()->unlockDocument(pDoc));
}

PyAutoDocLock::PyAutoDocLock()
    : m_pyImp(new PyAutoDocLockImp())
{
}

PyAutoDocLock::PyAutoDocLock(const PyApDocument& doc)
    : m_pyImp(new PyAutoDocLockImp(doc.impObj()))
{
}

PyApDocument PyAutoDocLock::doc() const
{
    return PyApDocument(impObj());
}

std::string PyAutoDocLock::className()
{
    return "AutoDocLock";
}

AcApDocument* PyAutoDocLock::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr || m_pyImp->pDoc == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcApDocument*>(m_pyImp->pDoc);
}

