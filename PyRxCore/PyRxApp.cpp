#include "stdafx.h"
#include "PyRxApp.h"
#include "PyAcGe.h"
#include "PyAcDb.h"
#include "PyAcRx.h"
#include "PyAcGi.h"
#include "PyAcGs.h"
#include "PyAcAp.h"
#include "PyAcAx.h"
#include "PyAcEd.h"
#include "PyAcPl.h"
#include "PyAcSm.h"
#include "PyAcBr.h"
#include "PyBrx.h"
#include "PyBrxCv.h"
#include "PyBrxBim.h"
#include "PyRxModule.h"
#include "PyRxModuleLoader.h"
#include "PyRxAppSettings.h"

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

static bool initializeFromConfig()
{
    PyConfig config;
    PyConfig_InitPythonConfig(&config);

    {//args
        const auto& args = PyRxAppSettings::getCommandLineArgs();
        config.parse_argv = args.size() == 0 ? 0 : 1;
        for (const auto& item : args)
            PyWideStringList_Append(&config.argv, item.c_str());
    }

#ifdef NEVER //wait for enum
    const auto& app = PyRxApp::instance();
    if (GETBIT(app.testflags, 1))
        acedAlert(_T("Waiting for debugger! "));
#endif // NEVER

    const auto [es, venv_executable] = PyRxAppSettings::pythonvenv_path();
    if (es == true)
    {
        auto status = PyConfig_SetString(&config, &config.executable, venv_executable.c_str());
        if (PyStatus_Exception(status))
        {
            PyConfig_Clear(&config);
            acutPrintf(_T("\nPyConfig_SetString failed %ls, msg=%ls: "), __FUNCTIONW__, utf8_to_wstr(status.err_msg).c_str());
            return false;
        }
    }

    auto status = Py_InitializeFromConfig(&config);
    PyConfig_Clear(&config);

    if (PyStatus_Exception(status))
    {
        acutPrintf(_T("\nInitializeFromConfig failed %ls, msg=%ls: "), __FUNCTIONW__, utf8_to_wstr(status.err_msg).c_str());
        return false;
    }
    return true;
}

bool WxRxApp::Init_wxPython()
{
    PyPreConfig preConfig;
    PyPreConfig_InitPythonConfig(&preConfig);
    auto status = Py_PreInitialize(&preConfig);

    if (PyStatus_Exception(status))
    {
        acutPrintf(_T("\nPreInitialize failed %ls, msg=%ls: "), __FUNCTIONW__, utf8_to_wstr(status.err_msg).c_str());
        return false;
    }

    if (!initializeFromConfig())
    {
        acutPrintf(_T("\ninitializeFromConfig failed, trying Py_InitializeEx %ls: "), __FUNCTIONW__);
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
// initWxApp
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
        if (hInst == nullptr || !wxEntryStart(hInst))
            return false;
        wxSetInstance(hInst);
        if (wxTheApp && wxTheApp->CallOnInit())
            return true;
    }
    return false;
}

//------------------------------------------------------------------------------------------------
// the PyRxApp, holds the command objects
const std::filesystem::path& PyRxApp::modulePath()
{
    static std::filesystem::path path;
    if (path.empty())
    {
        std::wstring buffer(MAX_PATH, 0);
        GetModuleFileName(_hdllInstance, buffer.data(), buffer.size());
        path = buffer.c_str();
        path.remove_filename();
    }
    return path;
}

void PyRxApp::applyDevelopmentSettings()
{
    std::error_code ec;
    const auto& settingsPath = PyRxAppSettings::iniPath();
    if (std::filesystem::exists(settingsPath, ec) == false)
        return;
    std::wstring stubPath(MAX_PATH, 0);
    if (GetPrivateProfileStringW(_T("PYRXSETTINGS"), _T("PYRXSTUBPATH"), _T(""), stubPath.data(), stubPath.size(), settingsPath.c_str()))
        PyRxApp::appendSearchPath(stubPath.c_str());
}

bool PyRxApp::load_pyrx_onload()
{
    const auto [bfound, spath] = PyRxAppSettings::pyonload_path();
    if (bfound)
    {
        PyAutoLockGIL lock;
        return ads_loadPythonModule(spath.c_str());
    }
    return false;
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
        initPySmModule();
        initPyBrModule();
        initPyAxModule();
#ifdef BRXAPP
        initPyBrxModule();
        initPyBrxCvModule();
        initPyBrxBimModule();
#endif
        initTestFlags();
        initWxApp();
        applyDevelopmentSettings();

        if (Py_IsInitialized() && setPyConfig())
        {
            isLoaded = true;
            acutPrintf(_T("Python Interpreter Loaded successfully!\n"));
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

void PyRxApp::initTestFlags()
{
    try
    {
        std::error_code ec;
        const auto& args = PyRxAppSettings::getCommandLineArgs();
        for (const auto& item : args)
        {
            CString csArgs = item.c_str();
            const auto posPyinit = csArgs.Find(_T("--pyinit"));
            if (posPyinit != -1)
            {
                const auto posFlags = csArgs.Find(_T("0x"));
                if (posFlags != -1)
                    testflags = std::stoull((const wchar_t*)csArgs.Mid(posFlags), nullptr, 16);
            }
        }
    }
    catch (...)
    {
        acutPrintf(_T("exception in initTestFlags"));
        testflags = 0;
    }
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
    }
    catch (...)
    {
        acutPrintf(_T("exception in uninit"));
    }
    return false;
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
    PyAutoLockGIL lock;
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
    PyAutoLockGIL lock;
    if (PyErr_Occurred())
    {
        PyObject* error_type = nullptr;
        PyObject* the_error = nullptr;
        PyObject* the_traceback = nullptr;
        PyErr_Fetch(&error_type, &the_error, &the_traceback);
        PyErr_NormalizeException(&error_type, &the_error, &the_traceback);
        if ((error_type != NULL))
        {
            std::string the_error_string, the_traceback_string;
            if (the_error != NULL)
                the_error_string = PyUnicode_AsUTF8(PyObject_Str(the_error));
            if (the_traceback != NULL && PyTraceBack_Check(the_traceback))
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
                    the_traceback_string += std::format("\nAt {} ({}:{})", sCodeName, sFileName, lineNr);
                    pTrace = pTrace->tb_next;
                }
            }
            std::string message(the_error_string + " ,Traceback - " + the_traceback_string);
            Py_XDECREF(error_type);
            Py_XDECREF(the_error);
            Py_XDECREF(the_traceback);
            return utf8_to_wstr(message);
        }
    }
    return std::wstring{ __FUNCTIONW__ };
}
IMPLEMENT_APP_NO_MAIN(WxRxApp)


