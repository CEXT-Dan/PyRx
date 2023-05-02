#include "stdafx.h"
#include "PyApDocument.h"
#include "PyAcEditor.h"

using namespace boost::python;
//-----------------------------------------------------------------------------------------
//PyApDocument Wrapper
void makeAcApDocumentWrapper()
{
    static auto wrapper = class_<PyApDocument, bases<PyRxObject>>("Document", boost::python::no_init)
        .def("className", &PyApDocument::className).staticmethod("className")
        .def("database", &PyApDocument::database)
        .def("editor", &PyApDocument::editor)
        ;
}

//-----------------------------------------------------------------------------------------
//PyApDocument
PyApDocument::PyApDocument(AcApDocument* ptr, bool autoDelete)
    : PyRxObject(ptr, autoDelete,false)
{
}

PyDbDatabase PyApDocument::database() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbDatabase(imp->database());
    throw PyNullObject();
}

PyAcEditor PyApDocument::editor()
{
    return PyAcEditor{};
}

std::string PyApDocument::className()
{
    return std::string{ "AcApDocument" };
}

AcApDocument* PyApDocument::impObj() const
{
    if (m_pImp != nullptr)
        throw PyNullObject();
    return static_cast<AcApDocument*>(m_pImp.get());
}
