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
    wxPyEndAllowThreads(wxPyBeginAllowThreads());
    wxTheApp->GetMainTopWindow()->SetHWND(0);
    wxTheApp->SetTopWindow(nullptr);
    wxTheApp->CleanUp();
    frame.release();
#ifdef NEVER //TODO!
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

bool WxRxApp::Init_wxPython()
{
    constexpr const TCHAR* msg = _T("\n*****Error importing the wxPython API!*****");
    Py_InitializeEx(0);
    if (wxPyGetAPIPtr() == NULL)
    {
        acutPrintf(msg);
        return false;
    }
    if (!wxPyCheckForApp(false))
    {
        acutPrintf(msg);
        return false;
    }
    wxPyBeginAllowThreads();
    WxPyAutoLock::canLock = true;
    PyAutoLockGIL::canLock = true;
    return true;
}


//------------------------------------------------------------------------------------------------
// helper function to initWxApp

//TODO: Find out why BricsCAD is wonkey, with AfxGetInstanceHandle
bool initWxApp()
{
    wxApp::SetInstance(&WxRxApp::instance());
    if (wxInitialize())
    {
#ifdef BRXAP
        HINSTANCE hInst = _hdllInstance
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
    wchar_t buffer[MAX_PATH];
    GetModuleFileName(_hdllInstance, buffer, MAX_PATH);
    std::filesystem::path path = buffer;
    path.remove_filename();
    return path;
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
        initWxApp();

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

bool PyRxApp::uninit()
{
    isLoaded = false;
    WxPyAutoLock::canLock = false;
    PyAutoLockGIL::canLock = false;
    try
    {
        PyGILState_STATE state = PyGILState_Ensure();
        if (Py_IsInitialized())
        {
            wxTheApp->OnExit();
#ifdef NEVER //TODO!
            Py_FinalizeEx();
#endif
        }
    }
    catch (...)
    {
        acutPrintf(_T("exception in uninit"));
    }
    return !isLoaded;
}

bool PyRxApp::setPyConfig()
{
    //append our module path to python
    WxPyAutoLock lock;

    AcString _modulePath = modulePath().c_str();
    _modulePath.makeLower();

    PyObjectPtr sys(PyImport_ImportModule("sys"));
    if (sys == nullptr)
        return false;
    PyObjectPtr path(PyObject_GetAttrString(sys.get(), "path"));
    if (path == nullptr)
        return false;
    PyObjectPtr pyString(wstr_to_py((const TCHAR*)_modulePath));
    if (pyString == nullptr)
        return false;
    if (PyList_Append(path.get(), pyString.get()) < 0)
        return false;
    PyRxApp::instance().loadedModulePaths.insert((const TCHAR*)_modulePath);

    return true;
}

bool PyRxApp::appendSearchPath(const TCHAR* pModulePath)
{
    WxPyAutoLock lock;

    AcString _modulePath = pModulePath;
    _modulePath.makeLower();

    if (PyRxApp::instance().loadedModulePaths.contains((const TCHAR*)_modulePath))
        return true;
    PyRxApp::instance().loadedModulePaths.insert((const TCHAR*)_modulePath);
    PyObjectPtr sys(PyImport_ImportModule("sys"));
    if (sys == nullptr)
        return false;
    PyObjectPtr path(PyObject_GetAttrString(sys.get(), "path"));
    if (path == nullptr)
        return false;
    PyObjectPtr pyString(wstr_to_py((const TCHAR*)_modulePath));
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
        PyObject* error_type, * the_error, * the_traceback, * py_error_string, * py_error_unicode;
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


