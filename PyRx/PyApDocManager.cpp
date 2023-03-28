#include "stdafx.h"
#include "PyApDocManager.h"
#include "PyApDocument.h"

using namespace boost::python;
//-----------------------------------------------------------------------------------------
//PyApDocManager Wrapper
void makeAcApDocManagerWrapper()
{
    static auto wrapper = class_<PyApDocManager, bases<PyRxObject>>("ApDocManager", boost::python::no_init)
        .def("className", &PyApDocManager::className)
        .def("curDocument", &PyApDocManager::curDocument)
        ;
}

//-----------------------------------------------------------------------------------------
//PyApDocManager

PyApDocManager::PyApDocManager(AcApDocManager* ptr, bool autoDelete)
    : PyRxObject(ptr, autoDelete)
{
}

PyApDocument PyApDocManager::curDocument()
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyApDocument(imp->curDocument(),false);
    throw PyNullObject();
}

std::string PyApDocManager::className()
{
    return std::string{ "AcApDocManager" };
}

AcApDocManager* PyApDocManager::impObj() const
{
    return static_cast<AcApDocManager*>(m_pImp);
}
