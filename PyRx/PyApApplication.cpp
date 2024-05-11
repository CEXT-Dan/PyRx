#include "stdafx.h"
#include "PyApApplication.h"
#include "PyApDocManager.h"
#include "PyRxModule.h"
#include "PyRxModuleLoader.h"

#include "PyRxApp.h"
#include "dwmapi.h"
#pragma comment( lib, "dwmapi.lib")

using namespace boost::python;

const TCHAR* getComAPIVer()
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
#elif defined(_BRXTARGET) && _BRXTARGET == 240
    return L"BRX24";
#elif defined(_GRXTARGET) && _GRXTARGET == 240
    return L"GRX24";
#elif defined(_ZRXTARGET) && _ZRXTARGET == 240
    return L"ZRX24";
#elif defined(_ZRXTARGET) && _ZRXTARGET == 250
    return L"ZRX25";
#endif
    return L"!ERROR!";
}


//-----------------------------------------------------------------------------------------
//PyApApplication  Wrapper
void makePyApApplictionWrapper()
{
    PyDocString DS("Application");
    class_<PyApApplication>("Application")
        .def("docManager", &PyApApplication::docManager, DS.SARGS()).staticmethod("docManager")
        .def("mainWnd", &PyApApplication::mainWnd, DS.SARGS()).staticmethod("mainWnd")
        .def("setTitleThemeDark", &PyApApplication::setTitleThemeDark, DS.SARGS({ "wnd : int" })).staticmethod("setTitleThemeDark")
        .def("applyHostIcon", &PyApApplication::applyHostIcon, DS.SARGS({ "wnd : int" })).staticmethod("applyHostIcon")
        .def("acadGetIDispatch", &PyApApplication::acadGetIDispatch, DS.SARGS()).staticmethod("acadGetIDispatch")
        .def("loadPythonModule", &PyApApplication::loadPythonModule, DS.SARGS({ "fullpath: str" })).staticmethod("loadPythonModule")
        .def("reloadPythonModule", &PyApApplication::reloadPythonModule, DS.SARGS({ "fullpath: str" })).staticmethod("reloadPythonModule")
        .def("getLoadedModules", &PyApApplication::getLoadedModules, DS.SARGS()).staticmethod("getLoadedModules")
        .def("getLoadedModuleNames", &PyApApplication::getLoadedModuleNames, DS.SARGS()).staticmethod("getLoadedModuleNames")
        .def("getPyRxModulePath", &PyApApplication::getPyRxModulePath, DS.SARGS()).staticmethod("getPyRxModulePath")
        .def("wxApp", &PyApApplication::getwxApp, DS.SARGS()).staticmethod("wxApp")
        .def("hostAPI", &PyApApplication::hostAPI, DS.SARGS()).staticmethod("hostAPI")
        .def("hostAPIVER", &PyApApplication::hostAPIVER, DS.SARGS()).staticmethod("hostAPIVER")
        .def("registerOnIdleWinMsg", &PyApApplication::registerOnIdleWinMsg, DS.SARGS({ "func: Any" })).staticmethod("registerOnIdleWinMsg")
        .def("removeOnIdleWinMsg", &PyApApplication::removeOnIdleWinMsg, DS.SARGS({ "func: Any" })).staticmethod("removeOnIdleWinMsg")
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
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    hIcon = LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(31233));
#elif defined(_ZRXTARGET) && _ZRXTARGET <= 240
    hIcon = LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(20001));
#elif defined(_GRXTARGET) && _GRXTARGET <= 240
    hIcon = LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(1017));
#else
    auto main = CWnd::FromHandle(adsw_acadMainWnd());
    if (main == nullptr)
        return;
    hIcon = main->GetIcon(TRUE);
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
    BOOL SET_IMMERSIVE_DARK_MODE_SUCCESS = SUCCEEDED(DwmSetWindowAttribute(
        hwnd, DWMWA_USE_IMMERSIVE_DARK_MODE_I20, &USE_DARK_MODE, sizeof(USE_DARK_MODE)));
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
    return (UINT_PTR)acedGetIDispatch(true);
}

PyObject* PyApApplication::getwxApp()
{
    WxPyAutoLock lock;
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
    PyAutoLockGIL lock;
    onidleFuncs.erase(obj.ptr());
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

bool PyApApplication::loadPythonModule(const std::string& fullpath)
{
    PyAutoLockGIL lock;
    std::filesystem::path fp = utf8_to_wstr(fullpath);
    return ads_loadPythonModule(fp);
}

bool PyApApplication::reloadPythonModule(const std::string& fullpath)
{
    PyAutoLockGIL lock;
    std::filesystem::path fp = utf8_to_wstr(fullpath);
    return ads_reloadPythonModule(fp);
}

std::string PyApApplication::getPyRxModulePath()
{
    return wstr_to_utf8(PyRxApp::modulePath());
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
