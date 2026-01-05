#include "stdafx.h"
#include "PyApApplication.h"
#include "PyApDocManager.h"
#include "PyRxModule.h"
#include "PyRxModuleLoader.h"
#include "PyAcadApplication.h"

#include "PyRxApp.h"
#include "dwmapi.h"
#pragma comment( lib, "dwmapi.lib")

using namespace boost::python;

static const TCHAR* getComAPIVer()
{
#if defined(_ARXTARGET) && _ARXTARGET == 240
    return L"ARX24";
#elif defined(_ARXTARGET) && _ARXTARGET == 241
    return L"ARX24";
#elif defined(_ARXTARGET) && _ARXTARGET == 242
    return L"ARX24";
#elif defined(_ARXTARGET) && _ARXTARGET == 243
    return L"ARX24";
#elif defined(_ARXTARGET) && _ARXTARGET == 250
    return L"ARX25";
#elif defined(_ARXTARGET) && _ARXTARGET == 251
    return L"ARX25";
#elif defined(_ARXTARGET) && _ARXTARGET == 260
    return L"ARX26";
#elif defined(_BRXTARGET) && _BRXTARGET == 240
    return L"BRX24";
#elif defined(_BRXTARGET) && _BRXTARGET == 250
    return L"BRX25";
#elif defined(_BRXTARGET) && _BRXTARGET == 260
    return L"BRX26";
#elif defined(_GRXTARGET) && _GRXTARGET == 240
    return L"GRX24";
#elif defined(_GRXTARGET) && _GRXTARGET == 250
    return L"GRX25";
#elif defined(_GRXTARGET) && _GRXTARGET == 260
    return L"GRX26";
#elif defined(_IRXTARGET) && _IRXTARGET == 140
    return L"IRX14";
#elif defined(_ZRXTARGET) && _ZRXTARGET == 240
    return L"ZRX24";
#elif defined(_ZRXTARGET) && _ZRXTARGET == 250
    return L"ZRX25";
#elif defined(_ZRXTARGET) && _ZRXTARGET == 260
    return L"ZRX26";
#endif
    return L"!ERROR!";
}

//-----------------------------------------------------------------------------------------
//PyApApplication  Wrapper
void makePyApApplictionWrapper()
{
    PyDocString DS("Application");
    class_<PyApApplication>("Application")
        .def("docManager", &PyApApplication::docManager, DS.SARGS(77)).staticmethod("docManager")
        .def("acadApplication", &PyApApplication::acadApplication, DS.SARGS(19139)).staticmethod("acadApplication")
        .def("mainWnd", &PyApApplication::mainWnd, DS.SARGS()).staticmethod("mainWnd")
        .def("setTitleThemeDark", &PyApApplication::setTitleThemeDark, DS.SARGS({ "wnd : int" })).staticmethod("setTitleThemeDark")
        .def("applyHostIcon", &PyApApplication::applyHostIcon, DS.SARGS({ "wnd : int" })).staticmethod("applyHostIcon")
        .def("acadGetIDispatch", &PyApApplication::acadGetIDispatch, DS.SARGS()).staticmethod("acadGetIDispatch")
        .def("loadPythonModule", &PyApApplication::loadPythonModule, DS.SARGS({ "fullpath: str" })).staticmethod("loadPythonModule")
        .def("reloadPythonModule", &PyApApplication::reloadPythonModule, DS.SARGS({ "fullpath: str" })).staticmethod("reloadPythonModule")
        .def("getLoadedModules", &PyApApplication::getLoadedModules, DS.SARGS()).staticmethod("getLoadedModules")
        .def("getLoadedModuleNames", &PyApApplication::getLoadedModuleNames, DS.SARGS()).staticmethod("getLoadedModuleNames")
        .def("getPyRxModulePath", &PyApApplication::getPyRxModulePath, DS.SARGS()).staticmethod("getPyRxModulePath")
        .def("getPyRxModuleName", &PyApApplication::getPyRxModuleName, DS.SARGS()).staticmethod("getPyRxModuleName")
        .def("getLocalAppDataPath", &PyApApplication::getLocalAppDataPath1)
        .def("getLocalAppDataPath", &PyApApplication::getLocalAppDataPath2, DS.SARGS({ "createIfNotFound:bool=True" })).staticmethod("getLocalAppDataPath")
        .def("getAppDataPath", &PyApApplication::getAppDataPath1)
        .def("getAppDataPath", &PyApApplication::getAppDataPath2, DS.SARGS({ "createIfNotFound:bool=True" })).staticmethod("getAppDataPath")
        .def("wxApp", &PyApApplication::getwxApp, DS.SARGS()).staticmethod("wxApp")
        .def("hostAPI", &PyApApplication::hostAPI, DS.SARGS()).staticmethod("hostAPI")
        .def("hostAPIVER", &PyApApplication::hostAPIVER, DS.SARGS()).staticmethod("hostAPIVER")
        .def("hostFileInfo", &PyApApplication::hostFileInfo, DS.SARGS()).staticmethod("hostFileInfo")
        .def("pyrxVersion", &PyApApplication::pyrxVersion, DS.SARGS()).staticmethod("pyrxVersion")
        .def("regCommand", &PyApApplication::appregcommand, DS.SARGS({ "fullpath: str", "modulename: str", "name: str", "defFunc: Any","flags: PyAp.CmdFlags" })).staticmethod("regCommand")
        .def("removeCommand", &PyApApplication::apremovecommand, DS.SARGS({ "modulename: str", "name: str" })).staticmethod("removeCommand")
        .def("registerOnIdleWinMsg", &PyApApplication::registerOnIdleWinMsg, DS.SARGS({ "func: Any" })).staticmethod("registerOnIdleWinMsg")
        .def("removeOnIdleWinMsg", &PyApApplication::removeOnIdleWinMsg, DS.SARGS({ "func: Any" })).staticmethod("removeOnIdleWinMsg")
        .def("registerWatchWinMsg", &PyApApplication::registerWatchWinMsg, DS.SARGS({ "func: Any" })).staticmethod("registerWatchWinMsg")
        .def("removeWatchWinMsg", &PyApApplication::removeWatchWinMsg, DS.SARGS({ "func: Any" })).staticmethod("removeWatchWinMsg")
        .def("showModalDialog", &PyApApplication::showModalDialog1, DS.SARGS({ "window: wx.Dialog" })).staticmethod("showModalDialog")
        .def("listFilesInPath", &PyApApplication::listFilesInPath, DS.SARGS({ "path: str", "ext: str"})).staticmethod("listFilesInPath")
        .def("listFilesInPathRecursive", &PyApApplication::listFilesInPathRecursive, DS.SARGS({ "path: str", "ext: str" })).staticmethod("listFilesInPathRecursive")
        .def("testFlags", &PyApApplication::testFlags, DS.SARGS({ "flags: PyAp.PyRxTestFlags" })).staticmethod("testFlags")
        .def("className", &PyApApplication::className, DS.SARGS()).staticmethod("className")
        ;
}

PyApDocManager PyApApplication::docManager()
{
    return PyApDocManager(acDocManager, false);
}

void PyApApplication::applyHostIcon(UINT_PTR _hwnd)
{
    HICON hIcon = 0;
#if defined(_BRXTARGET260)
    hIcon = LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(31233));
#elif defined(_ZRXTARGET260)
    hIcon = LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(20001));
#elif defined(_GRXTARGET260)
    hIcon = LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(1017));
#elif defined(_IRXTARGET140)
    hIcon = LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(31233));
#elif defined(_ARXTARGET)
    auto main = CWnd::FromHandle(adsw_acadMainWnd());
    if (main == nullptr)
        return;
    hIcon = main->GetIcon(TRUE);
#else
    acutPrintf(_T("\nError in %ls"), __FUNCTIONW__);
#endif
    if (hIcon == 0)
        return;
    auto child = CWnd::FromHandle((HWND)_hwnd);
    if (child == nullptr)
        return;
    child->ModifyStyle(0, WS_POPUPWINDOW);
    child->SetIcon(hIcon, FALSE);
}

void PyApApplication::setTitleThemeDark(UINT_PTR _hwnd)
{
    HWND hwnd = (HWND)_hwnd;
    constexpr DWORD DWMWA_USE_IMMERSIVE_DARK_MODE_I20 = 20;
    BOOL USE_DARK_MODE = true;
    DwmSetWindowAttribute(hwnd, DWMWA_USE_IMMERSIVE_DARK_MODE_I20, &USE_DARK_MODE, sizeof(USE_DARK_MODE));
    const auto style = GetWindowLong(hwnd, GWL_STYLE);
    SetWindowLong(hwnd, GWL_STYLE, 0);
    SetWindowLong(hwnd, GWL_STYLE, style);
}

UINT_PTR PyApApplication::mainWnd()
{
    return reinterpret_cast<UINT_PTR>(adsw_acadMainWnd());
}

std::string PyApApplication::className()
{
    return std::string{ "AcApApplication" };
}

UINT_PTR PyApApplication::acadGetIDispatch()
{
    return (UINT_PTR)acedGetIDispatch(0);
}

PyObject* PyApApplication::getwxApp()
{
    PyAutoLockGIL lock;
    if (!wxPyCheckForApp(false))
        throw PyNullObject();
    wxApp* pApp = wxTheApp;
    if (pApp == nullptr)
        throw PyNullObject();
    PyObject* _wxapp = wxPyConstructObject(pApp, wxT("wxPyApp"));
    if (_wxapp == nullptr)
        throw PyNullObject();
    return _wxapp;
}

std::string PyApApplication::hostAPI()
{
    return wstr_to_utf8(getComAPIVer());
}

std::string PyApApplication::hostAPIVER()
{
    return std::format("{}{}", wstr_to_utf8(getappname()), acdbHostApplicationServices()->releaseMajorVersion());
}

static CString checkFileVersionInfo()
{
    HINSTANCE hInst = AfxGetInstanceHandle();
    std::wstring fpath(MAX_PATH, 0);
    GetModuleFileName(hInst, fpath.data(), fpath.size());
    const auto infoSize = GetFileVersionInfoSize(fpath.c_str(), nullptr);

    auto lpInfo = std::make_unique<BYTE[]>(infoSize);
    GetFileVersionInfo(fpath.c_str(), 0, infoSize, lpInfo.get());

    UINT valLen = MAX_PATH;
    LPVOID valPtr = NULL;
    CString valStr;

    if (::VerQueryValue(lpInfo.get(), TEXT("\\"), &valPtr, &valLen))
    {
        VS_FIXEDFILEINFO* pFinfo = (VS_FIXEDFILEINFO*)valPtr;
        valStr.Format(_T("%d.%d.%d.%d"),
            HIWORD(pFinfo->dwFileVersionMS),
            LOWORD(pFinfo->dwFileVersionMS),
            HIWORD(pFinfo->dwFileVersionLS),
            LOWORD(pFinfo->dwFileVersionLS)
        );
    }
    return valStr;
}

std::string PyApApplication::hostFileInfo()
{
    return wstr_to_utf8(checkFileVersionInfo());
}

std::string PyApApplication::pyrxVersion()
{
    return wstr_to_utf8(getPyRxBuldVersion());
}

void PyApApplication::registerOnIdleWinMsg(const boost::python::object& obj)
{
    PyAutoLockGIL lock;
    if (PyCallable_Check(obj.ptr()))
    {
        onidleFuncs[obj.ptr()] = obj;
        return;
    }
    acutPrintf(_T("parameter must be callable:"));
}

void PyApApplication::removeOnIdleWinMsg(const boost::python::object& obj)
{
    onidleFuncs.erase(obj.ptr());
}

bool PyApApplication::registerWatchWinMsg(const boost::python::object& winmsg_pfn)
{
    PyAutoLockGIL lock;
    if (PyCallable_Check(winmsg_pfn.ptr()))
    {
        winmsgFuncs.insert(winmsg_pfn.ptr());
        if (winmsgFuncs.size() == 1)
            PyThrowFalse(acedRegisterWatchWinMsg(PyApApplication::acedWatchWinMsgFn));
        return true;
    }
    acutPrintf(_T("parameter must be callable:"));
    return false;
}

bool PyApApplication::removeWatchWinMsg(const boost::python::object& winmsg_pfn)
{
    if (winmsgFuncs.contains(winmsg_pfn.ptr()))
    {
        winmsgFuncs.erase(winmsg_pfn.ptr());
        if (winmsgFuncs.size() == 0)
            PyThrowFalse(acedRemoveWatchWinMsg(PyApApplication::acedWatchWinMsgFn));
        return true;
    }
    acutPrintf(_T("never registered :"));
    return false;
}

static bool executePyOnIdleFunc(const boost::python::object& func)
{
    try
    {
        PyErr_Clear();
        if (func.ptr() != nullptr)
        {
            boost::python::call<void>(func.ptr());
            return true;
        }
    }
    catch (...)
    {
        acutPrintf(_T("\nException in %ls:"), __FUNCTIONW__);
    }
    return false;
}

//TODO this is always spinning:
void PyApApplication::PyOnIdleMsgFn()
{
    if (onidleFuncs.size() != 0)
    {
        PyAutoLockGIL lock;
        for (const auto& func : onidleFuncs)
        {
            if (!executePyOnIdleFunc(func.second))
            {
                onidleFuncs.erase(func.first);
                return;
            }
        }
    }
}

static bool executePyWinMsgFunc(PyObject* func, const MSG* message)
{
    try
    {
        PyErr_Clear();
        if (func != nullptr)
        {
            boost::python::call<void>(func, boost::python::make_tuple(
                message->message, UINT_PTR(message->hwnd), message->lParam, message->wParam, message->pt.x, message->pt.y, message->time));
            return true;
        }
    }
    catch (...)
    {
        acutPrintf(_T("\nException in %ls:"), __FUNCTIONW__);
    }
    return false;
}

void PyApApplication::acedWatchWinMsgFn(const MSG* message)
{
    if (winmsgFuncs.size() != 0)
    {
        PyAutoLockGIL lock;
        for (const auto& func : winmsgFuncs)
        {
            if (!executePyWinMsgFunc(func, message))
            {
                winmsgFuncs.erase(func);
                return;
            }
        }
    }
}

boost::python::object PyApApplication::loadPythonModule(const std::string& fullpath)
{
    PyAutoLockGIL lock;
    std::filesystem::path fp = utf8_to_wstr(fullpath);
    if (ads_loadPythonModule(fp))
    {
        auto& rxApp = PyRxApp::instance();
        std::filesystem::path path = fullpath;
        path = path.replace_extension();
        AcString acpath = path.filename().wstring().c_str();
        towupper(acpath);
        if (rxApp.funcNameMap.contains(acpath))
        {
            boost::python::handle<> handle(rxApp.funcNameMap.at(acpath).mdict);
            return boost::python::object(handle);
        }
    }
    return boost::python::object{};
}

boost::python::object PyApApplication::reloadPythonModule(const std::string& fullpath)
{
    PyAutoLockGIL lock;
    std::filesystem::path fp = utf8_to_wstr(fullpath);
    if (ads_reloadPythonModule(fp))
    {
        auto& rxApp = PyRxApp::instance();
        std::filesystem::path path = fullpath;
        path = path.replace_extension();
        AcString acpath = path.filename().wstring().c_str();
        towupper(acpath);
        if (rxApp.funcNameMap.contains(acpath))
        {
            boost::python::handle<> handle(rxApp.funcNameMap.at(acpath).mdict);
            return boost::python::object(handle);
        }
    }
    return boost::python::object{};
}

std::string PyApApplication::getPyRxModulePath()
{
    return wstr_to_utf8(PyRxApp::modulePath());
}

std::string PyApApplication::getPyRxModuleName()
{
    return wstr_to_utf8(PyRxApp::moduleName());
}

std::string PyApApplication::getLocalAppDataPath1()
{
    return wstr_to_utf8(PyRxApp::getLocalAppDataPath(true));
}

std::string PyApApplication::getLocalAppDataPath2(bool createIfNotFound)
{
    return wstr_to_utf8(PyRxApp::getLocalAppDataPath(createIfNotFound));
}

std::string PyApApplication::getAppDataPath1()
{
    return wstr_to_utf8(PyRxApp::getAppDataPath(true));
}

std::string PyApApplication::getAppDataPath2(bool createIfNotFound)
{
    return wstr_to_utf8(PyRxApp::getAppDataPath(createIfNotFound));
}

boost::python::list PyApApplication::getLoadedModules()
{
    PyAutoLockGIL lock;
    auto& app = PyRxApp::instance();
    boost::python::list pylist;
    for (const auto& item : app.loadedModuleNames)
        pylist.append(wstr_to_utf8(item));
    return pylist;
}

boost::python::list PyApApplication::getLoadedModuleNames()
{
    PyAutoLockGIL lock;
    auto& app = PyRxApp::instance();
    boost::python::list pylist;

    for (const auto& item : app.loadedModuleNames)
    {
        std::filesystem::path _path = item;
        pylist.append(wstr_to_utf8(_path.filename().replace_extension()));
    }
    return pylist;
}

int PyApApplication::showModalDialog1(const boost::python::object& window)
{
    wxDialog* pDlg = nullptr;// we are NOT the owner!
    if (!wxPyConvertWrappedPtr(window.ptr(), (void**)&pDlg, wxT("wxDialog")))
        return -1;
    if (pDlg == nullptr)
        return -1;
    applyHostIcon((UINT_PTR)pDlg->GetHandle());
    return pDlg->ShowModal();
}

void PyApApplication::appregcommand(const std::string& fullpath, const std::string& modulename, const std::string& name, const boost::python::object& func, int flags)
{
    ::regcommand(fullpath, modulename, name, func, flags);
}

void PyApApplication::apremovecommand(const std::string& modulename, const std::string& name)
{
    ::removecommand(modulename, name);
}

boost::python::list PyApApplication::listFilesInPath(const std::string& spath, const std::string& ext)
{
    std::error_code ec;
    boost::python::list result;
    for (const auto& entry : std::filesystem::directory_iterator(spath, std::filesystem::directory_options::skip_permission_denied, ec))
    {
        if (!ec)
        {
            const auto& epath = entry.path();
            if (!epath.has_extension())
                continue;
            if (icompare(epath.extension().string(), ext))
                result.append(epath.string());
        }
    }
    return result;
}

boost::python::list PyApApplication::listFilesInPathRecursive(const std::string& spath, const std::string& ext)
{
    std::error_code ec;
    boost::python::list result;
    for (const auto& entry : std::filesystem::recursive_directory_iterator(spath, std::filesystem::directory_options::skip_permission_denied, ec))
    {
        if (!ec)
        {
            const auto& epath = entry.path();
            if (!epath.has_extension())
                continue;
            if (icompare(epath.extension().string(), ext))
                result.append(epath.string());
        }
    }
    return result;
}

std::string PyApApplication::testFlags(PyRxTestFlags flags)
{
    return std::format("{:#x}", size_t(flags));
}

PyAcadApplication PyApApplication::acadApplication()
{
    return PyAcadApplication{};
}

//-----------------------------------------------------------------------------------------
//makeAPyApResourceOverrideWrapper
void makePyApResourceOverrideWrapper()
{
    PyDocString DS("ResourceOverride");
    class_<PyApResourceOverride>("ResourceOverride")
        .def(init<>(DS.ARGS(16801)))
        .def("className", &PyApApplication::className).staticmethod("className")
        ;
}

std::string PyApResourceOverride::className()
{
    return std::string{ "CAcModuleResourceOverride" };
}
