#include "stdafx.h"
#include "PyApDocManager.h"
#include "PyApDocument.h"
#include "PyDbDatabase.h"

using namespace boost::python;
//-----------------------------------------------------------------------------------------
//PyApDocManager Wrapper
void makeAcApDocManagerWrapper()
{
    static auto wrapper = class_<PyApDocManager, bases<PyRxObject>>("DocManager", boost::python::no_init)
        .def("lockDocument", &PyApDocManager::lockDocument1)
        .def("lockDocument", &PyApDocManager::lockDocument2)
        .def("lockDocument", &PyApDocManager::lockDocument3)
        .def("unlockDocument", &PyApDocManager::unlockDocument)
        .def("curDocument", &PyApDocManager::curDocument)
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

Acad::ErrorStatus PyApDocManager::appContextOpenPackage(const std::string& pszPackageName)
{
#ifndef ARXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->appContextOpenPackage(utf8_to_wstr(pszPackageName).c_str());
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

std::string PyApDocManager::className()
{
    return std::string{ "AcApDocManager" };
}

AcApDocManager* PyApDocManager::impObj() const
{
    if (m_pImp != nullptr)
        throw PyNullObject();
    return static_cast<AcApDocManager*>(m_pImp.get());
}
