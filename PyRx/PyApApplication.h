#pragma once

class  PyApDocManager;

void makePyApApplictionWrapper();

//-----------------------------------------------------------------------------------------
//PyApApplication  Wrapper
class PyApApplication
{
public:
    static PyApDocManager docManager();
public:

    static void applyHostIcon(UINT_PTR hwnd);
    static void setTitleThemeDark(UINT_PTR hwnd);
    static UINT_PTR mainWnd();
    static std::string className();
    static UINT_PTR acadGetIDispatch();
    static PyObject* getwxApp();
    static std::string hostAPI();
    static std::string hostAPIVER();
    static void registerOnIdleWinMsg(const boost::python::object& obj);
    static void removeOnIdleWinMsg(const boost::python::object& obj);
    static void PyOnIdleMsgFn();
    static bool loadPythonModule(const std::string& fullpath);

public:
    inline static std::map<PyObject*, boost::python::object> onidleFuncs;
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

