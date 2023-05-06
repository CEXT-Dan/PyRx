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
        .def("fileName", &PyApDocument::fileName)
        .def("formatForSave", &PyApDocument::formatForSave)
        .def("lockMode", &PyApDocument::lockMode1)
        .def("lockMode", &PyApDocument::lockMode2)
        .def("myLockMode", &PyApDocument::myLockMode)
        .def("isQuiescent", &PyApDocument::isQuiescent)
        .def("docTitle", &PyApDocument::docTitle)
        .def("setDocTitle", &PyApDocument::setDocTitle)
        .def("getCountOfLispList", &PyApDocument::getCountOfLispList)
        .def("getItemOfLispList", &PyApDocument::getItemOfLispList)
        .def("isCommandInputInactive", &PyApDocument::isCommandInputInactive)
        .def("pushDbmod", &PyApDocument::pushDbmod)
        .def("popDbmod", &PyApDocument::popDbmod)
        .def("upgradeDocOpen", &PyApDocument::upgradeDocOpen)
        .def("downgradeDocOpen", &PyApDocument::downgradeDocOpen)
        ;
}

//-----------------------------------------------------------------------------------------
//PyApDocument
PyApDocument::PyApDocument(AcApDocument* ptr, bool autoDelete)
    : PyRxObject(ptr, autoDelete,false)
{
}

std::string PyApDocument::fileName() const
{
   return wstr_to_utf8(impObj()->fileName());
}

PyDbDatabase PyApDocument::database() const
{
    return PyDbDatabase(impObj()->database());
}

AcApDocument::SaveFormat PyApDocument::formatForSave() const
{
   return impObj()->formatForSave();
}

AcAp::DocLockMode PyApDocument::lockMode1() const
{
    return impObj()->lockMode();
}

AcAp::DocLockMode PyApDocument::lockMode2(bool bIncludeMyLocks) const
{
    return impObj()->lockMode(bIncludeMyLocks);
}

AcAp::DocLockMode PyApDocument::myLockMode() const
{
    return impObj()->myLockMode();
}

bool PyApDocument::isQuiescent() const
{
    return impObj()->isQuiescent();
}

std::string PyApDocument::docTitle() const
{
    return wstr_to_utf8(impObj()->docTitle());
}

void PyApDocument::setDocTitle(const std::string& title)
{
    impObj()->setDocTitle(utf8_to_wstr(title).c_str());
}

bool PyApDocument::isReadOnly() const
{
    return impObj()->isReadOnly();
}

int PyApDocument::getCountOfLispList() const
{
    return impObj()->GetCountOfLispList();
}

boost::python::tuple PyApDocument::getItemOfLispList(int nIndex) const
{
    AcLispAppInfo* info = impObj()->GetItemOfLispList(nIndex);
    if (info == nullptr)
        throw PyAcadErrorStatus(eNullPtr);
    return boost::python::make_tuple(wstr_to_utf8(info->appFileName), info->bUnloadable);
}

bool PyApDocument::isCommandInputInactive() const
{
    return impObj()->isCommandInputInactive();
}

void PyApDocument::pushDbmod()
{
    return impObj()->pushDbmod();
}

Acad::ErrorStatus PyApDocument::popDbmod()
{
    return impObj()->popDbmod();
}

Acad::ErrorStatus PyApDocument::upgradeDocOpen()
{
    return impObj()->upgradeDocOpen();
}

Acad::ErrorStatus PyApDocument::downgradeDocOpen(bool bPromptForSave)
{
    return impObj()->downgradeDocOpen(bPromptForSave);
}

PyAcEditor PyApDocument::editor()
{
    return PyAcEditor{};
}

std::string PyApDocument::className()
{
    return std::string{ "AcApDocument" };
}

AcApDocument* PyApDocument::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcApDocument*>(m_pImp.get());
}
