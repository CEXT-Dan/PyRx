#pragma once
#include "stdafx.h"
#include "PyLispService.h"
#include "PyRxContainers.h"

enum class PyRxTestFlags : __int64
{
    kPyTfNone = 0,
    kPyTfNoOptimize = (1 << 0),
    kPyTfReserved1 = (1 << 1),
    kPyTfReserved2 = (1 << 2),
    kPyTfReserved3 = (1 << 3),
    kPyTfReserved4 = (1 << 4),
    kPyTfReserved5 = (1 << 5),
    kPyTfReserved6 = (1 << 6),
    kPyTfReserved7 = (1 << 7),
    kPyTfWaitForDebug = (1 << 8),
};

struct PyRxMethod;

//------------------------------------------------------------------------------------------------
//  this is AutoCAD's main frame
class ArxTopLevelWindow : public wxTopLevelWindow
{
public:
    ArxTopLevelWindow();
    ~ArxTopLevelWindow() override = default;
};

//------------------------------------------------------------------------------------------------
// the wxApp
class WxRxApp : public wxApp
{
public:
    WxRxApp() = default;
    virtual ~WxRxApp() override = default;
    virtual bool    OnInit() override;
    virtual int     OnExit() override;
    virtual void    WakeUpIdle() override;
    bool            Init_wxPython();
private:
    PyThreadState* m_mainTState = nullptr;
    PyObjectPtr m_wxapp;
};
wxDECLARE_APP(WxRxApp);

//------------------------------------------------------------------------------------------------
// the PyRxApp, holds the command objects
class PyRxApp
{
public:
    PyRxApp() = default;
    ~PyRxApp() = default;
    PyRxApp(const PyRxApp&) = delete;
    PyRxApp& operator=(const PyRxApp&) = delete;

    bool                init();
    void                initTestFlags();
    bool                uninit();

    static bool         setPyConfig();
    static bool         appendSearchPath(const std::filesystem::path& pModulePath, bool pyload = false);
    static bool         popFrontSearchPath(const std::filesystem::path& pModulePath);
    static std::wstring the_error();
    static const std::filesystem::path& modulePath();
    static const std::filesystem::path& moduleName();
    static const std::filesystem::path& getLocalAppDataPath(bool createIfNotFound = true);
    static const std::filesystem::path& getAppDataPath(bool createIfNotFound = true);
    static bool         load_host_init();

    static PyRxApp& instance();
public:

    using FuncNameMap = std::unordered_map<AcString, PyRxMethod>;
    using CmdNameMap = std::unordered_map<AcString, PyObject*>;
    using CmdLispMap = std::unordered_map<int, AcString>;
    using PathForCommand = std::unordered_map<AcString, std::filesystem::path>;
    using PathForLispFunc = std::unordered_map<int, std::filesystem::path>;

    LoadedPaths loadedModulePaths;
    FuncNameMap funcNameMap;
    CmdNameMap commands;
    PyLispService lispService;
    PathForCommand pathForCommand;
    PathForLispFunc pathForLispFunc;
    std::set<std::wstring> loadedModuleNames;

    inline static std::thread::id MAIN_THREAD_ID;

#ifdef _ZRXTARGET260
    //ID SUP - 79158
    AcString commandForDocOverride;
#endif

    void* appPkt = nullptr;
    size_t testflags = 0;
    bool isLoaded = false;

};
