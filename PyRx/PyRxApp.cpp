#include "stdafx.h"
#include "PyRxApp.h"
#include "PyAcGe.h"
#include "PyAcDb.h"
#include "PyAcRx.h"
#include "PyAcGi.h"
#include "PyAcGs.h"
#include "PyAcAp.h"
#include "PyAcEd.h"
#include "PyAcPl.h"
#include "PyBrxCv.h"
#include "PyRxModule.h"
#include "PyRxModuleLoader.h"
#include "PyRxINI.h"

#include "wx/setup.h"
#include "wx/wx.h"

WXDLLIMPEXP_BASE void wxSetInstance(HINSTANCE hInst);

//------------------------------------------------------------------------------------------------
//  this is AutoCAD's main frame
WinFrame::WinFrame(HWND hwnd)
{
    this->SetHWND(hwnd);
    this->AdoptAttributesFromHWND();
    this->m_isShown = true;
    wxTopLevelWindows.Append(this);
}

//------------------------------------------------------------------------------------------------
// the wxApp
WxRxApp& WxRxApp::instance()
{
    static WxRxApp mthis;
    return mthis;
}

bool WxRxApp::OnInit()
{
    frame.reset(new WinFrame(adsw_acadMainWnd()));
    wxTheApp->SetTopWindow(frame.get());
    if (wxTheApp->GetMainTopWindow() == nullptr)
        return false;
    if (Init_wxPython() == false)
        return false;
    return true;
}

int WxRxApp::OnExit()
{
#ifdef NEVER //TODO!
    wxPyEndAllowThreads(wxPyBeginAllowThreads());
    wxTheApp->GetMainTopWindow()->SetHWND(0);
    wxTheApp->SetTopWindow(nullptr);
    wxTheApp->CleanUp();
    frame.release();
    wxUninitialize();
#endif
    return 0;
}

void WxRxApp::WakeUpIdle()
{
    const CWinApp* mfcApp = AfxGetApp();
    if (mfcApp != nullptr && mfcApp->m_pMainWnd)
    {
        ::PostMessage(mfcApp->m_pMainWnd->m_hWnd, WM_NULL, 0, 0);
    }
}

void WxRxApp::ExitMainLoop()
{
    ::PostQuitMessage(0);
}

static bool initIsolated()
{
    PyConfig config;
    PyConfig_InitIsolatedConfig(&config);

    auto [es, venv_executable] = PyRxINI::pythonvenv_path();
    if (es == false)
        return false;

    auto status = PyConfig_SetString(&config, &config.executable, venv_executable.c_str());
    if (PyStatus_Exception(status))
    {
        PyConfig_Clear(&config);
        acutPrintf(_T("\nPyConfig_SetString failed %ls: "), __FUNCTIONW__);
        return false;
    }

    status = Py_InitializeFromConfig(&config);
    PyConfig_Clear(&config);
    if (PyStatus_Exception(status))
    {
        acutPrintf(_T("\nInitializeFromConfig failed %ls: "), __FUNCTIONW__);
        return false;
    }
    return true;
}

static bool initNonIsolated()
{
    PyConfig config;
    PyConfig_InitPythonConfig(&config);

    //TODO: read params from .INI
    auto status = Py_InitializeFromConfig(&config);
    PyConfig_Clear(&config);

    if (PyStatus_Exception(status))
    {
        acutPrintf(_T("\nInitializeFromConfig failed %ls: "), __FUNCTIONW__);
        return false;
    }
    return true;
}


bool WxRxApp::Init_wxPython()
{

    PyPreConfig preConfig;
    PyPreConfig_InitPythonConfig(&preConfig);

    //TODO: read params from .INI
    auto status = Py_PreInitialize(&preConfig);
    if (PyStatus_Exception(status))
    {
        acutPrintf(_T("\nPreInitialize failed  %ls: "), __FUNCTIONW__);
        return false;
    }

    const auto [res, isolated] = PyRxINI::pythonIsolated();
    if (res && isolated)
    {
        if (!initIsolated())
            Py_InitializeEx(0);
    }
    else
    {
        if (!initNonIsolated())
            Py_InitializeEx(0);
    }
    if (wxPyGetAPIPtr() == NULL || !wxPyCheckForApp(false))
    {
        acutPrintf(_T("\n*****Error importing the wxPython API!*****: \n"));
        return false;
    }
    wxPyBeginAllowThreads();
    PyAutoLockGIL::canLock = true;
    return true;
}

//------------------------------------------------------------------------------------------------
// helper function to initWxApp

// TODO: Find out why BricsCAD is wonky, with AfxGetInstanceHandle
// BricsCAD uses wxWidgets, so it's using another instance
bool initWxApp()
{
    wxApp::SetInstance(&WxRxApp::instance());
    if (wxInitialize())
    {
#ifdef BRXAPP
        HINSTANCE hInst = _hdllInstance;
#else
        HINSTANCE hInst = AfxGetInstanceHandle();
#endif // BRXAP
        if (hInst == nullptr)
            return false;
        if (!wxEntryStart(hInst))
            return FALSE;
        wxSetInstance(hInst);
        if (wxTheApp && wxTheApp->CallOnInit())
            return true;
    }
    return false;
}

//------------------------------------------------------------------------------------------------
// the PyRxApp, holds the command objects
std::filesystem::path PyRxApp::modulePath()
{
    std::wstring buffer(MAX_PATH, 0);
    GetModuleFileName(_hdllInstance, buffer.data(), buffer.size());
    std::filesystem::path path = buffer.c_str();
    path.remove_filename();
    return path;
}

static auto getInstallPath()
{
    std::wstring buffer(MAX_PATH, 0);
    GetEnvironmentVariable(_T("localappdata"), buffer.data(), buffer.size());
    std::filesystem::path path = buffer.c_str();
    path /= _T("Programs\\PyRx");
    std::error_code ec;
    return std::tuple(std::filesystem::is_directory(path, ec), path);
}

static void validateINIStubPath(const std::wstring& inipath, const std::wstring& stubPath)
{
    std::error_code ec;
    if (std::filesystem::is_directory(stubPath, ec) == false)
    {
        const auto [installPathFound, installPath] = getInstallPath();
        {
            std::filesystem::path newstubPath = installPath / _T("Stubs");
            WritePrivateProfileString(_T("PYRXSETTINGS"), _T("PYRXSTUBPATH"), newstubPath.c_str(), inipath.c_str());
            PyRxApp::appendSearchPath(newstubPath);
        }
    }
    PyRxApp::appendSearchPath(stubPath);
}

void PyRxApp::appendINISettings()
{
    constexpr const wchar_t* ininame = _T("PyRx.INI");
    const auto settingsPath = modulePath() / ininame;

    std::error_code ec;
    if (std::filesystem::exists(settingsPath, ec) == false)
    {
        acutPrintf(_T("\nFailed find %ls: "), ininame);
        return;
    }

    std::wstring stubPath(MAX_PATH, 0);
    if (GetPrivateProfileStringW(_T("PYRXSETTINGS"), _T("PYRXSTUBPATH"), _T(""), stubPath.data(), stubPath.size(), settingsPath.c_str()))
    {
        validateINIStubPath(settingsPath, stubPath.c_str());
    }
    else
    {
        acutPrintf(_T("\nFailed to read setting %ls: \n"), _T("PYRXSTUBPATH"));
    }
}

void PyRxApp::load_pyrx_onload()
{
    const auto pyrx_onloadPath = modulePath() / _T("pyrx_onload.py");
    if (AcString foundPath; acdbHostApplicationServices()->findFile(foundPath, pyrx_onloadPath.c_str()) == eOk && foundPath.length() != 0)
    {
        std::error_code ec;
        if (std::filesystem::exists((const wchar_t*)foundPath, ec))
        {
            PyAutoLockGIL lock;
            ads_loadPythonModule(pyrx_onloadPath);
        }
    }
}

PyRxApp& PyRxApp::instance()
{
    static PyRxApp mthis;
    return mthis;
}

bool PyRxApp::init()
{
    try
    {
        initPyRxModule();
        initPyGeModule();
        initPyGiModule();
        initPyGsModule();
        initPyDbModule();
        initPyApModule();
        initPyEdModule();
        initPyPlModule();
#ifdef BRXAPP
        initPyBrxCvModule();
#endif
        initWxApp();
        appendINISettings();

        if (Py_IsInitialized() && setPyConfig())
        {
            isLoaded = true;
            acutPrintf(_T("Python Interpreter Loaded successfully!\n"));
            load_pyrx_onload();
        }
        else
        {
            if (PyErr_Occurred())
                PyErr_Clear();
            acutPrintf(_T("Failed to load Python Interpreter!"));
            isLoaded = false;
        }
    }
    catch (...)
    {
        acutPrintf(_T("exception in init"));
        isLoaded = false;
    }
    return isLoaded;
}

bool PyRxApp::uninit()
{
    try
    {
        // Py_FinalizeEx throws because something is still in python 
        // I think it's wxPython since the main window was attached
        // acrxLockApplication so we just let the OS do our dirty work
#ifdef NEVER //TODO!
        PyGILState_STATE state = PyGILState_Ensure();
        if (Py_IsInitialized())
        {
            wxTheApp->OnExit();
            Py_FinalizeEx();
        }
#endif
        bool isLoaded = false;
    }
    catch (...)
    {
        acutPrintf(_T("exception in uninit"));
    }
    return !isLoaded;
}

bool PyRxApp::setPyConfig()
{
    // append our module path to python
    WxPyAutoLock lock;
    const auto _modulePath = modulePath();
    PyObjectPtr sys(PyImport_ImportModule("sys"));
    if (sys == nullptr)
        return false;
    PyObjectPtr path(PyObject_GetAttrString(sys.get(), "path"));
    if (path == nullptr)
        return false;
    PyObjectPtr pyString(wstr_to_py(_modulePath));
    if (pyString == nullptr)
        return false;
    if (PyList_Append(path.get(), pyString.get()) < 0)
        return false;
    PyRxApp::instance().loadedModulePaths.insert(_modulePath);
    return true;
}

bool PyRxApp::appendSearchPath(const std::filesystem::path& modulePath)
{
    WxPyAutoLock lock;
    if (PyRxApp::instance().loadedModulePaths.contains(modulePath))
        return true;
    PyRxApp::instance().loadedModulePaths.insert(modulePath);
    PyObjectPtr sys(PyImport_ImportModule("sys"));
    if (sys == nullptr)
        return false;
    PyObjectPtr path(PyObject_GetAttrString(sys.get(), "path"));
    if (path == nullptr)
        return false;
    PyObjectPtr pyString(wstr_to_py(modulePath));
    if (pyString == nullptr)
        return false;
    if (PyList_Append(path.get(), pyString.get()) < 0)
        return false;
    return true;
}

std::wstring PyRxApp::the_error()
{
    WxPyAutoLock lock;
    if (PyErr_Occurred())
    {
        PyObject* error_type = nullptr;
        PyObject* the_error = nullptr;
        PyObject* the_traceback = nullptr;
        PyObject* py_error_string = nullptr;
        PyObject* py_error_unicode = nullptr;
        PyErr_Fetch(&error_type, &the_error, &the_traceback);
        PyErr_NormalizeException(&error_type, &the_error, &the_traceback);
        if ((error_type != NULL))
        {
            std::wstring the_error_string, the_traceback_string;
            if (the_error != NULL)
                the_error_string = PyUnicode_AsWideCharString(PyObject_Str(the_error), nullptr);
            if (the_traceback != NULL)
            {
                if (PyTraceBack_Check(the_traceback))
                {
                    PyTracebackObject* traceRoot = (PyTracebackObject*)the_traceback;
                    PyTracebackObject* pTrace = traceRoot;

                    while (pTrace != NULL)
                    {
                        PyFrameObject* frame = pTrace->tb_frame;
                        PyCodeObject* code = PyFrame_GetCode(frame);

                        int lineNr = PyFrame_GetLineNumber(frame);
                        const char* sCodeName = PyUnicode_AsUTF8(code->co_name);
                        const char* sFileName = PyUnicode_AsUTF8(code->co_filename);
                        the_traceback_string += std::format(_T("\nAt {} ({}:{})"), utf8_to_wstr(sCodeName), utf8_to_wstr(sFileName), lineNr);
                        pTrace = pTrace->tb_next;
                    }
                }
            }
            std::wstring str_error(the_error_string);
            std::wstring str_traceback(the_traceback_string);
            std::wstring message(str_error + L" ,Traceback - " + the_traceback_string);
            Py_XDECREF(error_type);
            Py_XDECREF(the_error);
            Py_XDECREF(the_traceback);
            return message;
        }
    }
    return std::wstring{ };
}
IMPLEMENT_APP_NO_MAIN(WxRxApp)


