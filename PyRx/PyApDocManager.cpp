#include "stdafx.h"
#include "PyApDocManager.h"
#include "PyApDocument.h"

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
