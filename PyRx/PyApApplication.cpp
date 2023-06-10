#include "stdafx.h"
#include "PyApApplication.h"
#include "PyApDocManager.h"

#include "dwmapi.h"
#pragma comment( lib, "dwmapi.lib")

using namespace boost::python;
//-----------------------------------------------------------------------------------------
//PyApApplication  Wrapper
void makeAcApApplictionWrapper()
{
    class_<PyApApplication>("Application")
        .def("docManager", &PyApApplication::docManager)
        .def("className", &PyApApplication::className).staticmethod("className")
        .def("mainWnd", &PyApApplication::mainWnd).staticmethod("mainWnd")
        .def("setTitleThemeDark", &PyApApplication::setTitleThemeDark).staticmethod("setTitleThemeDark")
        ;
}

PyApDocManager PyApApplication::docManager()
{
    return PyApDocManager(acDocManager, false);
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

int64_t PyApApplication::mainWnd()
{
    return reinterpret_cast<int64_t>(adsw_acadMainWnd());
}

std::string PyApApplication::className()
{
    return std::string{ "AcApApplication" };
}


//-----------------------------------------------------------------------------------------
//makeAPyApResourceOverrideWrapper  Wrapper
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
