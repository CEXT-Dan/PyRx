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

#ifdef PYPERFPROFILE
class PerfTimerEx
{
public:
    void init(const CString& funcName);
    void tick();
    void end();
    void reset();

private:
    CString m_funcName;
    uint64_t m_ticks = 0;
    std::chrono::high_resolution_clock::time_point t_begin;
};

inline void PerfTimerEx::init(const CString& funcName)
{
    m_funcName = funcName;
    reset();
}

inline void PerfTimerEx::reset()
{
    m_ticks = 0;
    t_begin = std::chrono::high_resolution_clock::now();
}

inline void PerfTimerEx::tick()
{
    m_ticks++;
}

inline void PerfTimerEx::end()
{
    std::chrono::duration<double> elapsed;
    auto t_end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = t_end - t_begin;
    acutPrintf(_T("\nName= %ls, total = %lf, ticks %ld, per tick = %lf"),
        (const TCHAR*)m_funcName, diff.count(), m_ticks, diff.count() / m_ticks);
    reset();
}
#endif

//------------------------------------------------------------------------------------------------
//  this is AutoCAD's main frame
class WinFrame : public wxTopLevelWindow
{
public:
    WinFrame(HWND hwnd);
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
    virtual void    ExitMainLoop() override;
    bool            Init_wxPython();
    static WxRxApp& instance();
public:
    std::unique_ptr<WinFrame> frame;
};

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

#ifdef PYPERFPROFILER
    PerfTimerEx perfTimerEx;
#endif

};

