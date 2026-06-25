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

#if wxCHECK_VERSION(3, 3, 0)
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

static bool useColorThemeOverride()
{
    std::array<wchar_t, 8> buffer = { 0 };
    if (acedGetEnv(_T("PYRX_COLORTHEME_OVERRIDE"), buffer.data(), buffer.size()) == RTNORM)
    {
        if (_wtoi(buffer.data()) == 0)
            return false;
    }
    return true;
}

static bool useColorTheme()
{
    std::array<wchar_t, 8> buffer = { 0 };
    if (acedGetEnv(_T("PYRX_COLORTHEME"), buffer.data(), buffer.size()) == RTNORM)
    {
        if (_wtoi(buffer.data()) == 0)
            return false;
    }
    return true;
}
#endif //wxVERSION_33

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
    // TODO: support wxWidgets with dark mode
#if wxCHECK_VERSION(3, 3, 0)
    if (isAcadDark() && useColorTheme())
    {
        if (!wxTheApp->MSWEnableDarkMode(wxApp::DarkMode_Always, useColorThemeOverride() ? new PyRxDarkModeSettings() : nullptr))
            acutPrintf(_T("MSWEnableDarkMode failed"));
    }
#endif //wxVERSION_33
    wxTheApp->SetTopWindow(new ArxTopLevelWindow());
    if (wxTheApp->GetTopWindow() == nullptr)
        return false;
    wxTheApp->SetExitOnFrameDelete(false);
    if (Init_wxPython() == false)
        return false;
    {
        // Hold a ref so wxPython wx.App.Get() returns our app 
        PyAutoLockGIL lock;
        wxPyConstructObject(wxTheApp, wxT("wxPyApp"), true);
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

static bool initializeFromConfig()
{
    PyConfig config;
    PyConfig_InitPythonConfig(&config);

    config.optimization_level = PyRxAppSettings::optimizationLevel();

    {// command line args
        const auto& args = PyRxAppSettings::getCommandLineArgs();
        config.parse_argv = args.size() == 0 ? FALSE : TRUE;
        for (const auto& item : args)
            PyWideStringList_Append(&config.argv, item.c_str());
    }

    const auto& app = PyRxApp::instance();
    if (GETBIT(app.testflags, size_t(PyRxTestFlags::kPyTfWaitForDebug)))
        acedAlert(_T("Waiting for debugger! "));
    if (GETBIT(app.testflags, size_t(PyRxTestFlags::kPyTfNoOptimize)))
        config.optimization_level = 0;

    if (const auto [es, pyexecutable] = PyRxAppSettings::pyexecutable_path(); es == true)
    {
        auto status = PyConfig_SetString(&config, &config.executable, pyexecutable.c_str());
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
    PyStatus status;
    PyPreConfig preConfig;
    PyPreConfig_InitPythonConfig(&preConfig);
    const auto& args = PyRxAppSettings::getCommandLineArgs();

    preConfig.utf8_mode = 1;

    if (args.empty())
    {
        status = Py_PreInitialize(&preConfig);
    }
    else
    {
        std::vector<const wchar_t*> argvPtrs;
        for (const auto& arg : args)
            argvPtrs.push_back(arg.c_str());
        status = Py_PreInitializeFromArgs(&preConfig, (Py_ssize_t)argvPtrs.size(), (wchar_t**)argvPtrs.data());
    }

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
    m_mainTState = wxPyBeginAllowThreads();
    PyAutoLockGIL::canLock = true;
    return true;
}

//------------------------------------------------------------------------------------------------
// hasWxXmlResourceModule helper [#422]
#if !wxCHECK_VERSION(3, 3, 0)
static bool hasWxXmlResourceModule()
{
    int found = 0;
    wxDynamicLibraryDetailsArray modules = wxDynamicLibrary::ListLoaded();
    for (size_t i = 0, len = modules.GetCount(); i < len; ++i)
    {
        const auto& name = modules[i].GetName();
        if (name.Contains(_T("_xrc.cp")))
            found++;
        if (name.Contains(_T("_xml.cp")))
            found++;
        if (found == 2)
            return true;
    }
    return false;
}
#endif //wxVERSION_33

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
#if !wxCHECK_VERSION(3, 3, 0)
#if defined(_GRXTARGET) && (_GRXTARGET >= 260)
    if (hasWxXmlResourceModule())
        wxExit();
#elif defined(_GRXTARGET) && (_GRXTARGET < 260)
    if (hasWxXmlResourceModule())
        std::quick_exit(EXIT_SUCCESS);
#endif //_GRXTARGET
#endif //wxVERSION_33
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
            acutPrintf(_T("\nFailed to load Python Interpreter!: \n"));
            if (PyErr_Occurred())
                PyErr_Print();
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
        if (m_pathList && pyPath && PyList_Size(m_pathList) > 0)
        {
            if (PyList_Insert(m_pathList, 0, pyPath) == 0)
            {
                m_insertedValue = PyUnicode_AsStringView(pyPath);
                m_inserted = true;
            }
        }
    }

    ~PySysPathFrontGuard()
    {
        if (m_inserted && m_pathList && PyList_Size(m_pathList) > 0)
        {
            std::string_view currentFront = PyUnicode_AsStringView(PyList_GetItem(m_pathList, 0));
            if (m_insertedValue == currentFront)
                PySequence_DelItem(m_pathList, 0);
            else
                acutPrintf(_T("\nWarning: PySysPathFrontGuard mismatch!."));
        }
    }

    bool isSuccess() const { return m_inserted; }

private:
    PyObject* m_pathList = nullptr;
    std::string m_insertedValue;
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
        if (!loadedModule || PyErr_Occurred())
        {
            acutPrintf(_T("\nPyImport_ImportModule Error: \n"));
            PyErr_Print();
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

wxIMPLEMENT_APP_NO_MAIN(WxRxApp);
