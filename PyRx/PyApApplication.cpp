#include "stdafx.h"
#include "PyApApplication.h"
#include "PyApDocManager.h"
#include "PyRxApp.h"
#include "dwmapi.h"
#pragma comment( lib, "dwmapi.lib")

using namespace boost::python;
//-----------------------------------------------------------------------------------------
//PyApApplication  Wrapper
void makePyApApplictionWrapper()
{
    PyDocString DS("Application");
    class_<PyApApplication>("Application")
        .def("docManager", &PyApApplication::docManager, DS.SARGS())
        .def("mainWnd", &PyApApplication::mainWnd, DS.SARGS()).staticmethod("mainWnd")
        .def("setTitleThemeDark", &PyApApplication::setTitleThemeDark, DS.SARGS({ "wnd : int" })).staticmethod("setTitleThemeDark")
        .def("applyHostIcon", &PyApApplication::applyHostIcon, DS.SARGS({ "wnd : int" })).staticmethod("applyHostIcon")
        .def("acadGetIDispatch", &PyApApplication::acadGetIDispatch, DS.SARGS()).staticmethod("acadGetIDispatch")
        .def("wxApp", &PyApApplication::getwxApp, DS.SARGS()).staticmethod("wxApp")
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
    auto main = CWnd::FromHandle(adsw_acadMainWnd());
    if (main == nullptr)
        return;
    hIcon = main->GetIcon(TRUE);
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

//-----------------------------------------------------------------------------------------
//makeAPyApResourceOverrideWrapper
void makePyApResourceOverrideWrapper()
{
    class_<PyApResourceOverride>("ResourceOverride")
        .def("className", &PyApApplication::className).staticmethod("className")
        ;
}

std::string PyApResourceOverride::className()
{
    return std::string{ "CAcModuleResourceOverride" };
}
