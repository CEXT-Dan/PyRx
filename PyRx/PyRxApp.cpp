#include "stdafx.h"
#include "PyRxApp.h"
#include "PyRxAcut.h"
#include "PyRxAced.h"

#include "PyAcGe.h"
#include "PyAcDb.h"
#include "PyAcRx.h"
#include "PyAcGi.h"
#include "PyAcAp.h"
#include "PyAcEd.h"

#include "wx/setup.h"
#include "wx/wx.h"
WXDLLIMPEXP_BASE void wxSetInstance(HINSTANCE hInst);


class WinFrame : public wxFrame
{
public:
    WinFrame(HWND hwnd)
    {
        this->SetHWND(hwnd);
        this->AdoptAttributesFromHWND();
        this->m_isShown = true;
        wxTopLevelWindows.Append(this);
    }

    virtual bool Destroy() override
    {
        return true;
    }
};

class WxRxApp : public wxApp
{
public:
    WxRxApp() = default;
    virtual ~WxRxApp() override = default;
    virtual bool OnInit();
    virtual int  OnExit();
    bool Init_wxPython();
    static WxRxApp& get();
public:
    PyThreadState* m_mainTState;
    std::unique_ptr<WinFrame> frame;
};


WxRxApp& WxRxApp::get()
{
    static WxRxApp mthis;
    return mthis;
}

bool WxRxApp::OnInit()
{
    frame.reset(new WinFrame(adsw_acadMainWnd()));
    wxSetInstance(acrxGetApp()->GetModuleInstance());
    wxTheApp->SetTopWindow(frame.get());
    if (wxTheApp->GetMainTopWindow() == nullptr)
        return false;
    if (Init_wxPython() == false)
        return false;
    return true;
}

int WxRxApp::OnExit()
{
    m_mainTState = wxPyBeginAllowThreads();
    wxPyEndAllowThreads(m_mainTState);
    frame.release();
    wxTheApp->GetMainTopWindow()->SetHWND(0);
    wxTheApp->SetTopWindow(nullptr);
    wxTheApp->CleanUp();
#ifdef NEVER //TODO!
    wxUninitialize();
#endif
    return 0;
}

bool WxRxApp::Init_wxPython()
{
    Py_InitializeEx(0);
    PyEval_InitThreads();
    if (wxPyGetAPIPtr() == NULL)
    {
        acutPrintf(_T("\n*****Error importing the wxPython API!*****"));
        return false;
    }
    m_mainTState = wxPyBeginAllowThreads();
    WxPyAutoLock::canLock = true;
    return true;
}

bool initWxApp()
{
    if (wxInitialize())
    {
        wxApp::SetInstance(&WxRxApp::get());
        if (wxTheApp && wxTheApp->CallOnInit())
            return true;
    }
    return false;
}

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
        initPyDbModule();
        initPyApModule();
        initPyEdModule();

        //TODO: might not keep this
        if (PyImport_AppendInittab(PyAppNamespace, PyInitPyRxModule) == -1)
            acutPrintf(_T("\nPyImport Failed"));

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
        acutPrintf(_T("exception in uninit"));
        isLoaded = false;
    }
    return isLoaded;
}

bool PyRxApp::uninit()
{
    isLoaded = false;
    fnm.clear();
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

bool PyRxApp::pyRxAppendSearchPath(const TCHAR* pModulePath)
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

PyMODINIT_FUNC PyInitPyRxModule(void)
{
    static PyMethodDef PyRxMethods[] =
    {
        {"Printf", PyRxAcut::Printf, METH_VARARGS, PyRxAcut::PrintfDoc()},
        {"GetString", PyRxAced::GetString, METH_VARARGS, PyRxAced::GetStringDoc()},
        {"GetVar", PyRxAced::GetVar, METH_VARARGS, PyRxAced::GetVarDoc()},
        {"SetVar", PyRxAced::SetVar, METH_VARARGS, PyRxAced::SetVarDoc()},
        {NULL, NULL, 0 , NULL}
    };
    static PyModuleDef pyRxModuleDef =
    {
        PyModuleDef_HEAD_INIT,  "PyRxApp", "ObjectArx wrappers", -1,  PyRxMethods
    };
    WxPyAutoLock lock;
    PyObject* m = PyModule_Create(&pyRxModuleDef);
    if (m == NULL)
        return NULL;
    return m;
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
