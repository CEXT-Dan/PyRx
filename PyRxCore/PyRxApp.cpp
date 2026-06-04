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
#include <wx/xrc/xmlres.h>
#include <wx/dynlib.h>
#include <wx/msw/darkmode.h>

//------------------------------------------------------------------------------------------------
//  PyRxDarkModeSettings
class PyRxDarkModeSettings : public wxDarkModeSettings
{
public:

    static COLORREF getPaletteBackground()
    {
#ifndef _ARXTARGET
        return RGB(49, 56, 66);
#else
        auto mgr = CAdUiThemeManager{};
        auto theme = mgr.GetTheme(PALETTE_SET_THEME);
        if (theme == nullptr)
            return RGB(49, 56, 66);
        COLORREF clr = theme->GetColor(kPaletteBackground);
        mgr.ReleaseTheme(theme);
        return clr;
#endif
    }

    wxColour GetColour(wxSystemColour index) override
    {
        if (!PyRxApp::instance().useCustomDarkmode)
            return wxDarkModeSettings::GetColour(index);

        static COLORREF clr = getPaletteBackground();
        switch (index)
        {
            case wxSYS_COLOUR_APPWORKSPACE:
            case wxSYS_COLOUR_INFOBK:
            case wxSYS_COLOUR_LISTBOX:
            case wxSYS_COLOUR_WINDOW:
            case wxSYS_COLOUR_BTNFACE: //TODO: does not stick
                return wxColour(clr);
            default:
                return wxDarkModeSettings::GetColour(index);
        }
    }
};

static bool isAcadDark()
{
    resbuf rb;
    const auto rt = acedGetVar(_T("COLORTHEME"), &rb);
    return rt == RTNORM && rb.restype == RTSHORT && rb.resval.rint == 0;
}

//------------------------------------------------------------------------------------------------
//  this is AutoCAD's main frame
ArxTopLevelWindow::ArxTopLevelWindow()
{
    this->SetHWND(adsw_acadMainWnd());
    this->AdoptAttributesFromHWND();
    this->m_isShown = true;
    wxTopLevelWindows.Append(this);
}

//------------------------------------------------------------------------------------------------
// the wxApp
bool WxRxApp::OnInit()
{
    if (isAcadDark() && PyRxAppSettings::useDarkMode())
    {
        if (!wxTheApp->MSWEnableDarkMode(wxApp::DarkMode_Always, new PyRxDarkModeSettings()))
            acutPrintf(_T("MSWEnableDarkMode failed"));
    }
    wxTheApp->SetTopWindow(new ArxTopLevelWindow());
    if (wxTheApp->GetTopWindow() == nullptr)
        return false;
    wxTheApp->SetExitOnFrameDelete(false);
    if (Init_wxPython() == false)
        return false;
    {
        PyAutoLockGIL lock;
        m_wxpyApp = wxPyConstructObject(wxTheApp, wxT("wxPyApp"), true);
    }
    return true;
}

int WxRxApp::OnExit()
{
    auto top = wxTheApp->GetTopWindow();
    if (top != nullptr)
        top->SetHWND(0);
    wxTopLevelWindows.clear();
    wxPyEndAllowThreads(m_mainTState);
    return 0;
}

void WxRxApp::WakeUpIdle()
{
    if (auto hwnd = adsw_acadMainWnd(); ::IsWindow(hwnd))
    {
        ::PostMessage(hwnd, WM_NULL, 0, 0);
    }
}

static bool initializeFromInitConfig()
{
    // 1. Create the opaque initialization configuration instance (PEP 741)
    PyInitConfig* config = PyInitConfig_Create();
    if (config == nullptr)
    {
        acutPrintf(_T("\nPyInitConfig_Create failed in %ls"), __FUNCTIONW__);
        return false;
    }

    PyInitConfig_SetInt(config, "utf8_mode", 1);
    int optLevel = PyRxAppSettings::optimizationLevel();

    const auto& app = PyRxApp::instance();
    if (GETBIT(app.testflags, size_t(PyRxTestFlags::kPyTfWaitForDebug)))
    {
        acedAlert(_T("Waiting for debugger! "));
    }
    if (GETBIT(app.testflags, size_t(PyRxTestFlags::kPyTfNoOptimize)))
    {
        optLevel = 0;
    }
    PyInitConfig_SetInt(config, "optimization_level", optLevel);

    const auto& args = PyRxAppSettings::getCommandLineArgs();
    if (args.empty())
    {
        PyInitConfig_SetInt(config, "parse_argv", FALSE);
    }
    else
    {
        PyInitConfig_SetInt(config, "parse_argv", TRUE);
        std::vector<std::string> utf8Args;
        utf8Args.reserve(args.size());
        for (const auto& item : args)
            utf8Args.push_back(wstr_to_utf8(item.c_str()));
        std::vector<char*> argvPointers;
        argvPointers.reserve(utf8Args.size());
        for (auto& str : utf8Args)
            argvPointers.push_back(str.data());
        if (PyInitConfig_SetStrList(config, "argv", argvPointers.size(), argvPointers.data()) < 0)
        {
            const char* err_msg = nullptr;
            PyInitConfig_GetError(config, &err_msg);
            PyInitConfig_Free(config);
            acutPrintf(_T("\nPyInitConfig_SetStrList failed %ls, msg=%ls: "),
                __FUNCTIONW__,
                utf8_to_wstr(err_msg ? err_msg : "Unknown error").c_str());
            return false;
        }
    }

    if (const auto [es, pyexecutable] = PyRxAppSettings::pyexecutable_path(); es == true)
    {
        std::string utf8Path = wstr_to_utf8(pyexecutable.c_str());
        if (PyInitConfig_SetStr(config, "executable", utf8Path.c_str()) < 0)
        {
            const char* err_msg = nullptr;
            PyInitConfig_GetError(config, &err_msg);
            PyInitConfig_Free(config);
            acutPrintf(_T("\nPyInitConfig_SetStr failed for 'executable' %ls, msg=%ls: "),
                __FUNCTIONW__,
                utf8_to_wstr(err_msg ? err_msg : "Unknown error").c_str());
            return false;
        }
    }

    if (Py_InitializeFromInitConfig(config) < 0)
    {
        const char* err_msg = nullptr;
        PyInitConfig_GetError(config, &err_msg); //
        PyInitConfig_Free(config);
        acutPrintf(_T("\nPy_InitializeFromInitConfig failed %ls, msg=%ls: "),
            __FUNCTIONW__,
            utf8_to_wstr(err_msg ? err_msg : "Unknown initialization error").c_str());
        return false;
    }

    PyInitConfig_Free(config);
    return true;
}

bool WxRxApp::Init_wxPython()
{
    if (!initializeFromInitConfig())
    {
        acutPrintf(_T("\ninitializeFromInitConfig failed, trying Py_InitializeEx %ls: "), __FUNCTIONW__);
        Py_InitializeEx(0);
    }

    if (wxPyGetAPIPtr() == NULL || !wxPyCheckForApp(false))
    {
        acutPrintf(_T("\n*****Error importing the wxPython API!*****: \n"));
        return false;
    }

    m_mainTState = wxPyBeginAllowThreads();
    PyAutoLockGIL::canLock = true;
    return true;
}

//------------------------------------------------------------------------------------------------
// initWxApp
static bool initWxApp()
{
#ifdef BRXAPP
    HINSTANCE hInst = _hdllInstance;
#else
    HINSTANCE hInst = AfxGetInstanceHandle();
#endif // BRXAP
    wxApp::SetInstance(new WxRxApp());
    if (hInst == nullptr || !wxEntryStart(hInst))
        return false;
    if (wxTheApp && wxTheApp->CallOnInit())
        return true;
    return false;
}

static bool uninitWxApp()
{
    wxTheApp->OnExit();
    wxEntryCleanup();
    return true;
}

//------------------------------------------------------------------------------------------------
// the PyRxApp, holds the command objects
const std::filesystem::path& PyRxApp::modulePath()
{
    static std::filesystem::path path;
    if (path.empty())
    {
        path = PyRxApp::moduleName();
        path.remove_filename();
    }
    return path;
}

const std::filesystem::path& PyRxApp::moduleName()
{
    static std::filesystem::path path;
    if (path.empty())
    {
        DWORD bufferSize = MAX_PATH;
        std::wstring buffer(bufferSize, L'\0');
        DWORD result = GetModuleFileName(_hdllInstance, buffer.data(), bufferSize);
        if (result > 0 && result < bufferSize)
        {
            buffer.resize(result);
            path = std::filesystem::path(buffer);
        }
    }
    return path;
}

const std::filesystem::path& PyRxApp::getLocalAppDataPath(bool createIfNotFound /*= true*/)
{
    static std::filesystem::path path;
    if (path.empty())
    {
        std::wstring _path(MAX_PATH, 0);
        if (SHGetFolderPath(NULL, CSIDL_LOCAL_APPDATA, NULL, 0, _path.data()) == S_OK)
        {
            path = _path.c_str();
            path /= L"PyRx";
        }
    }
    if (createIfNotFound)
    {
        if (std::error_code _Ec; !std::filesystem::exists(path, _Ec))
        {
            std::filesystem::create_directory(path, _Ec);
            if (_Ec)
            {
                acutPrintf(_T("\nError create_directory failed %ls  %ls: "), __FUNCTIONW__, utf8_to_wstr(_Ec.message()).c_str());
            }
        }
    }
    return path;
}

const std::filesystem::path& PyRxApp::getAppDataPath(bool createIfNotFound /*= true*/)
{
    static std::filesystem::path path;
    if (path.empty())
    {
        std::wstring _path(MAX_PATH, 0);
        if (SHGetFolderPath(NULL, CSIDL_APPDATA, NULL, 0, _path.data()) == S_OK)
        {
            path = _path.c_str();
            path /= L"PyRx";
        }
    }
    if (createIfNotFound)
    {
        if (std::error_code _Ec; !std::filesystem::exists(path, _Ec))
        {
            std::filesystem::create_directory(path, _Ec);
            if (_Ec)
            {
                acutPrintf(_T("\nError create_directory failed %ls  %ls: "), __FUNCTIONW__, utf8_to_wstr(_Ec.message()).c_str());
            }
        }
    }
    return path;
}

bool PyRxApp::load_host_init()
{
    PyAutoLockGIL lock;
#ifdef PYRXDEBUG
    const std::filesystem::path fileToFind = SOLUTION_DIR / L"pyrx" / L"_host_init.py";
    if (AcString fout; acdbHostApplicationServices()->findFile(fout, fileToFind.c_str()) == eOk)
        return ads_loadPythonModule((const wchar_t*)fout);
    return false;
#else
    std::error_code ec;
    const auto pyc = modulePath() / L"_host_init.pyc";
    if (std::filesystem::exists(pyc, ec))
        return ads_loadPythonModule(pyc);
    return ads_loadPythonModule(modulePath() / L"_host_init.py");
#endif
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

        if (Py_IsInitialized() && setPyConfig())
        {
            isLoaded = true;
            acutPrintf(_T("\nPython Interpreter Loaded successfully! :\n"));
        }
        else
        {
            if (PyErr_Occurred())
                PyErr_Clear();
            acutPrintf(_T("\nFailed to load Python Interpreter!: \n"));
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
    return uninitWxApp();
}

static void printPythonList(PyObject* pylist)
{
    acutPrintf(_T("\nPrintPythonList\n"));
    for (Py_ssize_t idx = 0; idx < PyList_Size(pylist); idx++)
    {
        PyObject* item = PyList_GET_ITEM(pylist, idx);
        if (item != nullptr)
        {
            std::wstring buffer(MAX_PATH, 0);
            PyUnicode_AsWideChar(item, buffer.data(), buffer.size());
            acutPrintf(_T("%ls;"), buffer.c_str());
        }
    }
}

bool PyRxApp::setPyConfig()
{
    // append our module path to python
    PyAutoLockGIL lock;
    const auto& _modulePath = modulePath();
#ifdef NEVER // not needed if installed 
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
#endif
    PyRxApp::instance().loadedModulePaths.insert(_modulePath);
    return true;
}

class PySysPathFrontGuard
{
public:
    PySysPathFrontGuard(PyObject* pathList, PyObject* pyPath)
        : m_pathList(pathList)
    {
        if (m_pathList && pyPath)
        {
            m_originalFront = PyUnicode_AsWString(PyList_GET_ITEM(m_pathList, 0));
            if (PyList_Insert(m_pathList, 0, pyPath) == 0)
                m_inserted = true;
        }
    }

    ~PySysPathFrontGuard()
    {
        if (m_inserted && m_pathList)
        {
            PyObjectPtr res(PyObject_CallMethod(m_pathList, "pop", "i", 0));
            auto newFront = PyUnicode_AsWString(PyList_GET_ITEM(m_pathList, 0));
            if (!icompare(m_originalFront, newFront))
                acutPrintf(_T("\nWarning, PySysPathFrontGuard mismatch! "));
        }
    }

    bool isSuccess() const { return m_inserted; }

private:
    PyObject* m_pathList = nullptr;
    std::wstring m_originalFront;
    bool m_inserted = false;
};

PyObject* PyRxApp::appendAndLoadModule(const std::filesystem::path& modulePath, const std::string& moduleName, bool pyload /*= false*/)
{
    PyObjectPtr sys(PyImport_ImportModule("sys"));
    if (sys == nullptr)
        return nullptr;
    PyObjectPtr path(PyObject_GetAttrString(sys.get(), "path"));
    if (path == nullptr)
        return nullptr;
    PyObjectPtr pyModPath(wstr_to_py(modulePath));
    if (pyModPath == nullptr)
        return nullptr;
    PyObjectPtr loadedModule(nullptr);
    if (pyload)
    {
        PySysPathFrontGuard pathGuard(path.get(), pyModPath.get());
        if (!pathGuard.isSuccess())
            return nullptr;
        loadedModule.reset(PyImport_ImportModule(moduleName.c_str()));
        if (!loadedModule || PyErr_Occurred() != NULL)
        {
            acutPrintf(_T("\nPyErr %ls: "), PyRxApp::the_error().c_str());
            return nullptr;
        }
    }
    else
    {
        loadedModule.reset(PyImport_ImportModule(moduleName.c_str()));
    }
    if (!PyRxApp::instance().loadedModulePaths.contains(modulePath))
    {
        PyRxApp::instance().loadedModulePaths.insert(modulePath);
        if (PyList_Append(path.get(), pyModPath.get()) < 0)
            return nullptr;
    }
#if defined(PYRXDEBUG) && defined(NEVER) //sanity
    printPythonList(path.get());
#endif
    return loadedModule.release();
}

bool PyRxApp::isPythonModule(const std::filesystem::path& filename)
{
    if (!filename.has_extension())
        return false;
    std::wstring ext = towlower(filename.extension().wstring());
    return (ext == L".py" || ext == L".pyc");
}

bool PyRxApp::isPythonModule(const AcString& filename)
{
    const std::filesystem::path _path = (const wchar_t*)filename;
    return PyRxApp::isPythonModule(_path.filename());
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

        std::string the_error_string = "Unknown Error";
        std::string the_traceback_string;

        if (the_error != nullptr)
        {
            PyObjectPtr pRep{ PyObject_Str(the_error) };
            if (pRep)
            {
                the_error_string = PyUnicode_AsString(pRep.get());
            }
        }

        if (the_traceback != nullptr && PyTraceBack_Check(the_traceback))
        {
            the_traceback_string = "\nTraceback (most recent call last):";
            PyTracebackObject* pTrace = reinterpret_cast<PyTracebackObject*>(the_traceback);

            while (pTrace != nullptr)
            {
                PyFrameObject* frame = pTrace->tb_frame;
                if (frame != nullptr)
                {
                    PyCodeObject* code = PyFrame_GetCode(frame);
                    if (code != nullptr)
                    {
                        int lineNr = PyFrame_GetLineNumber(frame);
                        const auto sCodeName = PyUnicode_AsStringView(code->co_name);
                        const auto sFileName = PyUnicode_AsStringView(code->co_filename);
                        the_traceback_string += std::format("\n  File \"{}\", line {}, in {}", sFileName, lineNr, sCodeName);
                        Py_DECREF(code);
                    }
                }
                pTrace = pTrace->tb_next;
            }
        }
        std::string message = the_traceback_string + "\n" + the_error_string;
        Py_XDECREF(error_type);
        Py_XDECREF(the_error);
        Py_XDECREF(the_traceback);
        return utf8_to_wstr(message);
    }
    return L"No Python Error Occurred";
}

wxIMPLEMENT_APP_NO_MAIN(WxRxApp);