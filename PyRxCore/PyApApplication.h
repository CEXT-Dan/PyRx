#pragma once

#pragma pack (push, 8)
class PyApDocManager;
class PyAcadApplication;
enum class PyRxTestFlags : __int64;

void makePyApApplictionWrapper();

//-----------------------------------------------------------------------------------------
//PyApApplication  Wrapper
class PyApApplication
{
public:
    static PyObject* getwxApp();
    static PyApDocManager       docManager();
    static PyAcadApplication    acadApplication();
    static void                 applyHostIcon(UINT_PTR hwnd);
    static void                 setTitleThemeDark(UINT_PTR hwnd);
    static UINT_PTR             mainWnd();
    static std::string          className();
    static UINT_PTR             acadGetIDispatch();
    static std::string          hostAPI();
    static std::string          hostAPIVER();
    static std::string          hostFileInfo();
    static std::string          pyrxVersion();
    static void                 registerOnIdleWinMsg(const boost::python::object& obj);
    static void                 removeOnIdleWinMsg(const boost::python::object& obj);
    static bool                 registerWatchWinMsg(const boost::python::object& winmsg_pfn);
    static bool                 removeWatchWinMsg(const boost::python::object& winmsg_pfn);
    static void                 PyOnIdleMsgFn();
    static boost::python::object loadPythonModule(const std::string& fullpath);
    static boost::python::object reloadPythonModule(const std::string& fullpath);
    static std::string          getPyRxModulePath();
    static std::string          getPyRxModuleName();
    static std::string          getLocalAppDataPath1();
    static std::string          getLocalAppDataPath2(bool createIfNotFound);
    static std::string          getAppDataPath1();
    static std::string          getAppDataPath2(bool createIfNotFound);
    static boost::python::list  getLoadedModules();
    static boost::python::list  getLoadedModuleNames();
    static void                 acedWatchWinMsgFn(const MSG* message);
    static int                  showModalDialog1(const boost::python::object& window);
    static void                 appregcommand(const std::string& fullpath, const std::string& modulename, const std::string& name, const boost::python::object& func, int flags);
    static void                 apremovecommand(const std::string& modulename, const std::string& name);
    static int                  getInvisibleBorderWidth(UINT_PTR hwnd);
    static void                 refreshMainWindow();

    static boost::python::list  listFilesInPath(const std::string& spath, const std::string& ext);
    static boost::python::list  listFilesInPathRecursive(const std::string& spath, const std::string& ext);
    static std::string          testFlags(PyRxTestFlags flags);

public:
    inline static std::vector<std::pair<PyObject*, boost::python::object>> onidleFuncs;
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
    std::shared_ptr<CAcModuleResourceOverride> myResources{ new CAcModuleResourceOverride() };
};

//-----------------------------------------------------------------------------------------
//Internal
void makeInternalWrapper();

class Internal
{
public:
    static boost::python::list  resbufTest(const boost::python::list& list);
    static boost::python::list  roundTripStringTest(const boost::python::list& list);
    static std::string          stringTest(const std::string& val);
    static std::string          stringUtf8ToWcharTest(const std::string& val);
    static std::string          stringtolower(const std::string& val);
    static std::string          stringtoupper(const std::string& val);
    static bool                 icompare(const std::string& left, const std::string& right);
    static std::string          exceptionTest();
};


//-----------------------------------------------------------------------------------------
//AppSettings
void makeAppSettingsWrapper();

class AppSettings
{
public:
  
};
#pragma pack (pop)