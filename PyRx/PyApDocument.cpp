#include "stdafx.h"
#include "PyApDocument.h"
#include "PyAcEditor.h"
#include "PyDbTransactionManager.h"
#include "PyEdInput.h"

using namespace boost::python;


//-----------------------------------------------------------------------------------------
//PyApDocument Wrapper
void makePyApDocumentWrapper()
{
    class_<PyApDocument, bases<PyRxObject>>("Document", boost::python::no_init)
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
        .def("transactionManager", &PyApDocument::transactionManager)
        .def("inputPointManager", &PyApDocument::inputPointManager)
        //static
        .def("docWnd", &PyApDocument::docWnd).staticmethod("docWnd")
        .def("className", &PyApDocument::className).staticmethod("className")
        ;

    enum_<AcApDocument::SaveFormat>("SaveFormat")
        .value("kUnknown", AcApDocument::SaveFormat::kUnknown)
        .value("kR12_dxf", AcApDocument::SaveFormat::kR12_dxf)
        .value("kR13_dwg", AcApDocument::SaveFormat::kR13_dwg)
        .value("kR13_dxf", AcApDocument::SaveFormat::kR13_dxf)
        .value("kR14_dwg", AcApDocument::SaveFormat::kR14_dwg)
        .value("kR14_dxf", AcApDocument::SaveFormat::kR14_dxf)
        .value("k2000_dwg", AcApDocument::SaveFormat::k2000_dwg)
        .value("k2000_dxf", AcApDocument::SaveFormat::k2000_dxf)
        .value("k2000_Template", AcApDocument::SaveFormat::k2000_Template)
        .value("k2000_Standard", AcApDocument::SaveFormat::k2000_Standard)
        .value("k2000_xml", AcApDocument::SaveFormat::k2000_xml)
        .value("k2004_dwg", AcApDocument::SaveFormat::k2004_dwg)
        .value("k2004_dxf", AcApDocument::SaveFormat::k2004_dxf)
        .value("k2004_Template", AcApDocument::SaveFormat::k2004_Template)
        .value("k2004_Standard", AcApDocument::SaveFormat::k2004_Standard)
        .value("k2007_dwg", AcApDocument::SaveFormat::k2007_dwg)
        .value("k2007_dxf", AcApDocument::SaveFormat::k2007_dxf)
        .value("k2007_Template", AcApDocument::SaveFormat::k2007_Template)
        .value("k2007_Standard", AcApDocument::SaveFormat::k2007_Standard)
        .value("k2010_dwg", AcApDocument::SaveFormat::k2010_dwg)
        .value("k2010_dxf", AcApDocument::SaveFormat::k2010_dxf)
        .value("k2010_Template", AcApDocument::SaveFormat::k2010_Template)
        .value("k2010_Standard", AcApDocument::SaveFormat::k2010_Standard)
        .value("k2013_dwg", AcApDocument::SaveFormat::k2013_dwg)
        .value("k2013_dxf", AcApDocument::SaveFormat::k2013_dxf)
        .value("k2013_Template", AcApDocument::SaveFormat::k2013_Template)
        .value("k2013_Standard", AcApDocument::SaveFormat::k2013_Standard)
        .value("k2018_dwg", AcApDocument::SaveFormat::k2018_dwg)
        .value("k2018_dxf", AcApDocument::SaveFormat::k2018_dxf)
        .value("k2018_Template", AcApDocument::SaveFormat::k2018_Template)
        .value("k2018_Standard", AcApDocument::SaveFormat::k2018_Standard)
        .value("kNative", AcApDocument::SaveFormat::kNative)
        .value("kNative_Template", AcApDocument::SaveFormat::kNative_Template)
        .export_values()
        ;
}

//-----------------------------------------------------------------------------------------
//PyApDocument
PyApDocument::PyApDocument(AcApDocument* ptr, bool autoDelete)
    : PyRxObject(ptr, autoDelete, false)
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
    const TCHAR* title = impObj()->docTitle();
    if (title != nullptr)
        return wstr_to_utf8(impObj()->docTitle());
    return std::string{};
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
    PyAutoLockGIL lock;
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

void PyApDocument::popDbmod()
{
    return PyThrowBadEs(impObj()->popDbmod());
}

void PyApDocument::upgradeDocOpen()
{
    return PyThrowBadEs(impObj()->upgradeDocOpen());
}

void PyApDocument::downgradeDocOpen(bool bPromptForSave)
{
    return PyThrowBadEs(impObj()->downgradeDocOpen(bPromptForSave));
}

PyTransactionManager PyApDocument::transactionManager()
{
    return PyTransactionManager(impObj()->transactionManager());
}

PyEdInputPointManager PyApDocument::inputPointManager()
{
    return PyEdInputPointManager(impObj()->inputPointManager());
}

int64_t PyApDocument::docWnd()
{
    return reinterpret_cast<uint64_t>(adsw_acadDocWnd());
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
    if (m_pyImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcApDocument*>(m_pyImp.get());
}
