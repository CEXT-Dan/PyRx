#pragma once

#pragma pack (push, 8)
class PyApDocManager;
class PyAcadApplication;
enum class InternalCmdFlags;
enum class PyRxTestFlags: __int64;

void makePyApApplictionWrapper();

//-----------------------------------------------------------------------------------------
//PyApApplication  Wrapper
class PyApApplication
{
public:
    static PyApDocManager       docManager();
    static PyAcadApplication    acadApplication();
    static void                 applyHostIcon(UINT_PTR hwnd);
    static void                 setTitleThemeDark(UINT_PTR hwnd);
    static UINT_PTR             mainWnd();
    static std::string          className();
    static UINT_PTR             acadGetIDispatch();
    static PyObject*            getwxApp();
    static std::string          hostAPI();
    static std::string          hostAPIVER();
    static void                 registerOnIdleWinMsg(const boost::python::object& obj);
    static void                 removeOnIdleWinMsg(const boost::python::object& obj);
    static bool                 registerWatchWinMsg(const boost::python::object& winmsg_pfn);
    static bool                 removeWatchWinMsg(const boost::python::object& winmsg_pfn);
    static void                 PyOnIdleMsgFn();
    static bool                 loadPythonModule(const std::string& fullpath);
    static bool                 reloadPythonModule(const std::string& fullpath);
    static std::string          getPyRxModulePath();
    static boost::python::list  getLoadedModules();
    static boost::python::list  getLoadedModuleNames();
    static void                 acedWatchWinMsgFn(const MSG* message);
    static int                  showModalDialog1(const boost::python::object& window);
    static void                 apregcommand(const std::string& fullpath, const std::string& modulename, const std::string& name, const boost::python::object& func, InternalCmdFlags flags);
    static void                 apremovecommand(const std::string& modulename, const std::string& name);
    static std::string          testFlags(PyRxTestFlags flags);

public:
    inline static std::map<PyObject*, boost::python::object> onidleFuncs;
    inline static std::set<PyObject*> winmsgFuncs;
};

//-----------------------------------------------------------------------------------------
//PyApApplication  Wrapper
void makePyApResourceOverrideWrapper();

class PyApResourceOverride
{
public:
    PyApResourceOverride() = default;
    ~PyApResourceOverride() = default;
    static std::string className();
public:
    CAcModuleResourceOverride myResources;
};

#pragma pack (pop)