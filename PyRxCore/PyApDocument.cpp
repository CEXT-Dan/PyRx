#include "stdafx.h"
#include "PyApDocument.h"
#include "PyAcEditor.h"
#include "PyDbTransactionManager.h"
#include "PyEdInput.h"
#include "PyApDocManager.h"

using namespace boost::python;

class wxDocWin : public wxWindow
{
public:
    explicit wxDocWin(HWND hwnd)
    {
        this->SetHWND(hwnd);
        this->SetParent(wxTheApp->GetMainTopWindow());
        this->AdoptAttributesFromHWND();
    }
};

//-----------------------------------------------------------------------------------------
//PyApDocument Wrapper
void makePyApDocumentWrapper()
{
    PyDocString DS("Document");
    class_<PyApDocument, bases<PyRxObject>>("Document", boost::python::no_init)
        .def("database", &PyApDocument::database, DS.ARGS(141))
        .def("editor", &PyApDocument::editor, DS.ARGS())
        .def("fileName", &PyApDocument::fileName, DS.ARGS(145))
        .def("formatForSave", &PyApDocument::formatForSave, DS.ARGS(146))
        .def("lockMode", &PyApDocument::lockMode1)
        .def("lockMode", &PyApDocument::lockMode2, DS.ARGS({ "bIncludeMyLocks : bool=False" }, 156))
        .def("myLockMode", &PyApDocument::myLockMode, DS.ARGS(157))
        .def("isQuiescent", &PyApDocument::isQuiescent, DS.ARGS(154))
        .def("docTitle", &PyApDocument::docTitle, DS.ARGS(142))
        .def("setDocTitle", &PyApDocument::setDocTitle, DS.ARGS({ "title : str" }, 161))
        .def("getCountOfLispList", &PyApDocument::getCountOfLispList, DS.ARGS(147))
        .def("getItemOfLispList", &PyApDocument::getItemOfLispList, DS.ARGS({ "index : int" }, 150))
        .def("isCommandInputInactive", &PyApDocument::isCommandInputInactive, DS.ARGS(152))
        .def("pushDbmod", &PyApDocument::pushDbmod, DS.ARGS(159))
        .def("popDbmod", &PyApDocument::popDbmod, DS.ARGS(158))
        .def("upgradeDocOpen", &PyApDocument::upgradeDocOpen, DS.ARGS(163))
        .def("downgradeDocOpen", &PyApDocument::downgradeDocOpen, DS.ARGS({ "promptForSave : bool" }, 143))
        .def("transactionManager", &PyApDocument::transactionManager, DS.ARGS(162))
        .def("inputPointManager", &PyApDocument::inputPointManager, DS.ARGS(151))
        .def("getUserData", &PyApDocument::getUserData, DS.ARGS())
        .def("setUserData", &PyApDocument::setUserData, DS.ARGS({ "data : object" }))
        .def("autoLock", &PyApDocument::autoLock, DS.ARGS(120))
        //static
        .def("getWxWindow", &PyApDocument::getWxWindow, DS.SARGS()).staticmethod("getWxWindow")
        .def("docWnd", &PyApDocument::docWnd, DS.SARGS()).staticmethod("docWnd")
        .def("className", &PyApDocument::className, DS.SARGS()).staticmethod("className")
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
PyApDocument::PyApDocument(const AcApDocument* ptr)
: PyApDocument(const_cast<AcApDocument*>(ptr),false)
{
}

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
        return wstr_to_utf8(title);
    return std::string{};
}

void PyApDocument::setDocTitle(const std::string& title) const
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
        throw PyErrorStatusException(eNullPtr);
    return boost::python::make_tuple(wstr_to_utf8(info->appFileName), info->bUnloadable);
}

bool PyApDocument::isCommandInputInactive() const
{
    return impObj()->isCommandInputInactive();
}

void PyApDocument::pushDbmod() const
{
    return impObj()->pushDbmod();
}

void PyApDocument::popDbmod() const
{
    return PyThrowBadEs(impObj()->popDbmod());
}

void PyApDocument::upgradeDocOpen() const
{
    return PyThrowBadEs(impObj()->upgradeDocOpen());
}

void PyApDocument::downgradeDocOpen(bool bPromptForSave) const
{
    return PyThrowBadEs(impObj()->downgradeDocOpen(bPromptForSave));
}

PyTransactionManager PyApDocument::transactionManager() const
{
    return PyTransactionManager(impObj()->transactionManager());
}

PyEdInputPointManager PyApDocument::inputPointManager() const
{
    return PyEdInputPointManager(impObj()->inputPointManager());
}

boost::python::object PyApDocument::getUserData()
{
    return DocVars.docData().m_userdata;
}

PyObject* PyApDocument::getWxWindow()
{
    PyAutoLockGIL lock;
    static wxDocWin* win = nullptr;//oof
    if (win == nullptr)
        win = new wxDocWin(adsw_acadDocWnd());
    return wxPyConstructObject(win, wxT("wxWindow"), false);
}

void PyApDocument::setUserData(const boost::python::object& data)
{
    DocVars.docData().m_userdata = data;
}

PyAutoDocLock PyApDocument::autoLock() const
{
    return PyAutoDocLock(*this);
}

UINT_PTR PyApDocument::docWnd()
{
    return reinterpret_cast<UINT_PTR>(adsw_acadDocWnd());
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
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcApDocument*>(m_pyImp.get());
}
