#include "stdafx.h"
#include "PyRxModuleLoader.h"
#include "PyRxModule.h"
#include "PyRxApp.h"
#include "PyCmd.h"

static void loadPyAppReactors(PyRxMethod& method)
{
    method.OnPyInitApp = PyDict_GetItemString(method.mdict, "OnPyInitApp");
    method.OnPyUnloadApp = PyDict_GetItemString(method.mdict, "OnPyUnloadApp");
    method.OnPyLoadDwg = PyDict_GetItemString(method.mdict, "OnPyLoadDwg");
    method.OnPyUnloadDwg = PyDict_GetItemString(method.mdict, "OnPyUnloadDwg");
    method.OnPyReload = PyDict_GetItemString(method.mdict, "OnPyReload");
}

static CString formatFileNameforCommandGroup(const TCHAR* modulename)
{
    CString _modulename = _T("PY_");
    _modulename.Append(modulename);
    _modulename.Replace(' ', '_');
    towupper(_modulename);
    return _modulename;
}

static AcString moduleNameFromPath(const std::filesystem::path& path)
{
    std::filesystem::path tmp = path;
    tmp.replace_extension();
    AcString val = tmp.filename().c_str();
    towupper(val);
    return val;
}

static int getFileDia()
{
    resbuf rb;
    if (acedGetVar(_T("FILEDIA"), &rb) == RTNORM)
        return rb.resval.rint;
    return 1;
}

bool showNavFileDialog(PyModulePath& path)
{
    static wxString lastPath;
    if (getFileDia() == 1)
    {
        CAcModuleResourceOverride resourceOverride;

        wxFileDialog OpenDialog(
            nullptr,
            _T("Select Python File"), lastPath, wxEmptyString,
            _T("Python Files (*.py;*.pyc)|*.py;*.pyc"),
            wxFD_OPEN | wxFD_FILE_MUST_EXIST, wxDefaultPosition);

        switch (OpenDialog.ShowModal())
        {
            case wxID_OK:
            {
                std::filesystem::path _path = (const TCHAR*)OpenDialog.GetPath();
                path.fullPath = _path;
                path.moduleName = moduleNameFromPath(_path);
                path.modulePath = _path.remove_filename();
                lastPath = path.modulePath.c_str();
                return true;
            }
            case wxID_CANCEL:
            {
                acutPrintf(_T("\nCanceled: "));
                return false;
            }
            default:
            {
                acutPrintf(_T("\nFailed to open file: "));
                return false;
            }
        }
    }
    else
    {
        RxAutoOutStr outstr;
        if (acedGetFullString(0, _T("Select Python File: "), outstr.buf) != RTNORM)
            return false;
        std::filesystem::path _path{ outstr.buf };
        path.fullPath = outstr.buf;
        path.moduleName = moduleNameFromPath(_path);
        path.modulePath = _path.remove_filename();
        return true;
    }
    return false;
}

boost::python::object PyUsingDecorator()
{
    struct UsingObject
    {
        static void usingfunc(const boost::python::object& _pyfunc)
        {
            PyAutoLockGIL lock;
            boost::python::call<void>(_pyfunc.ptr());
        }
    };
    return boost::python::make_function(UsingObject::usingfunc);
}

boost::python::object PyCommandDecorator1(int flags /*= kMODAL*/)
{
    return PyCommandDecorator2("", flags);
}

boost::python::object PyCommandDecorator2(const std::string& name, int flags)
{
    static AcString m_cmdname;
    static int m_cmdflags;
    {
        if (!name.empty())
            m_cmdname = utf8_to_wstr(name).c_str();
        else
            m_cmdname.setEmpty();
        m_cmdflags = flags;
    }
    struct CommandObject
    {
        static boost::python::object cmdfunc(const boost::python::object& _pyfunc)
        {
            if (m_cmdname.isEmpty())
            {
                PyObjectPtr funcName(PyObject_GetAttrString(_pyfunc.ptr(), "__name__"));
                if (funcName == nullptr)
                    return _pyfunc;
                m_cmdname = PyUnicode_AsWideCharString(funcName.get(), nullptr);
            }
            towupper(m_cmdname);
            PyObjectPtr moduleName(PyObject_GetAttrString(_pyfunc.ptr(), "__module__"));
            if (moduleName == nullptr)
                return _pyfunc;
            AcString acmodulename = PyUnicode_AsWideCharString(moduleName.get(), nullptr);
            auto path = std::filesystem::current_path() / static_cast<const wchar_t*>(acmodulename);
            path.replace_extension(_T(".py"));
            if (AcString foundPath; acdbHostApplicationServices()->findFile(foundPath, path.c_str()) == eOk)
            {
                auto& rxApp = PyRxApp::instance();
                if (rxApp.commands.contains(m_cmdname))
                    rxApp.commands.at(m_cmdname) = _pyfunc.ptr();
                else
                    rxApp.commands.emplace(m_cmdname, _pyfunc.ptr());

                if (rxApp.pathForCommand.contains(m_cmdname))
                    rxApp.pathForCommand.at(m_cmdname) = std::filesystem::current_path();
                else
                    rxApp.pathForCommand.emplace(m_cmdname, std::filesystem::current_path());
                PyRxModule::regCommand(formatFileNameforCommandGroup(acmodulename), m_cmdname, m_cmdflags);
            }
            return _pyfunc;
        }
    };
    return boost::python::make_function(CommandObject::cmdfunc);
}

boost::python::object PyLispFuncDecorator1()
{
    return PyLispFuncDecorator2("");
}

boost::python::object PyLispFuncDecorator2(const std::string& name)
{
    static AcString m_lspname;
    {
        if (!name.empty())
            m_lspname = utf8_to_wstr(name).c_str();
        else
            m_lspname.setEmpty();
    }
    struct LispFuncObject
    {
        static boost::python::object lspfunc(const boost::python::object& _pyfunc)
        {
            if (m_lspname.isEmpty())
            {
                PyObjectPtr funcName(PyObject_GetAttrString(_pyfunc.ptr(), "__name__"));
                if (funcName == nullptr)
                    return _pyfunc;
                m_lspname = PyUnicode_AsWideCharString(funcName.get(), nullptr);
            }
            towupper(m_lspname);
            PyObjectPtr moduleName(PyObject_GetAttrString(_pyfunc.ptr(), "__module__"));
            if (moduleName == nullptr)
                return _pyfunc;
            AcString acmodulename = PyUnicode_AsWideCharString(moduleName.get(), nullptr);
            auto path = std::filesystem::current_path() / static_cast<const wchar_t*>(acmodulename);
            path.replace_extension(_T(".py"));
            if (AcString foundPath; acdbHostApplicationServices()->findFile(foundPath, path.c_str()) == eOk)
            {
                auto& rxApp = PyRxApp::instance();
                rxApp.lispService.tryAddFunc(std::filesystem::current_path(), m_lspname, _pyfunc.ptr());
            }
            return _pyfunc;
        }
    };
    return boost::python::make_function(LispFuncObject::lspfunc);
}

//TODO: merge with PyCommandDecorator2
void regcommand(const std::string& fullpath, const std::string& modulename, const std::string& name, const boost::python::object& func, int flags)
{
    AcString m_name = utf8_to_wstr(name).c_str();
    std::filesystem::path modulePath = utf8_to_wstr(fullpath).c_str();
    towupper(m_name);
    auto& rxApp = PyRxApp::instance();
    if (rxApp.commands.contains(m_name))
        rxApp.commands.at(m_name) = func.ptr();
    else
        rxApp.commands.emplace(m_name, func.ptr());

    if (rxApp.pathForCommand.contains(m_name))
        rxApp.pathForCommand.at(m_name) = modulePath;
    else
        rxApp.pathForCommand.emplace(m_name, modulePath);
    PyRxModule::regCommand(formatFileNameforCommandGroup(utf8_to_wstr(modulename).c_str()), m_name, flags);
}

void removecommand(const std::string& modulename, const std::string& name)
{
    AcString m_name = utf8_to_wstr(name).c_str();
    towupper(m_name);
    auto& rxApp = PyRxApp::instance();
    if (rxApp.commands.contains(m_name))
        rxApp.commands.erase(m_name);
    if (rxApp.pathForCommand.contains(m_name))
        rxApp.pathForCommand.erase(m_name);
    acedRegCmds->removeCmd(formatFileNameforCommandGroup(utf8_to_wstr(modulename).c_str()), m_name);
}

static void onPyReload(const AcString& moduleName)
{
    try
    {
        PyAutoLockGIL lock;
        if (PyRxApp::instance().funcNameMap.contains(moduleName))
        {
            auto& method = PyRxApp::instance().funcNameMap.at(moduleName);
            if (method.OnPyReload != nullptr)
            {
                if (PyCallable_Check(method.OnPyReload))
                    method.rslt.reset(PyObject_CallNoArgs(method.OnPyReload));
            }
        }
    }
    catch (...)
    {
        acutPrintf(_T("\nOnPyReload failed: "));
    }
}

static void callOnPyUnloadAppBeforeReloading(const AcString& moduleName)
{
    PyAutoLockGIL lock;
    if (PyRxApp::instance().funcNameMap.contains(moduleName))
    {
        auto& method = PyRxApp::instance().funcNameMap.at(moduleName);
        if (method.OnPyUnloadApp != nullptr)
        {
            if (PyCallable_Check(method.OnPyUnloadApp))
                method.rslt.reset(PyObject_CallNoArgs(method.OnPyUnloadApp));
        }
    }
}

static void onLoadPyModule(const AcString& moduleName)
{
    try
    {
        PyAutoLockGIL lock;
        if (PyRxApp::instance().funcNameMap.contains(moduleName))
        {
            auto& method = PyRxApp::instance().funcNameMap.at(moduleName);
            if (method.OnPyInitApp != nullptr)
            {
                if (PyCallable_Check(method.OnPyInitApp))
                    method.rslt.reset(PyObject_CallNoArgs(method.OnPyInitApp));
            }
            if (method.OnPyLoadDwg != nullptr)
            {
                if (curDoc() == nullptr)
                    return;
                if (PyCallable_Check(method.OnPyLoadDwg))
                    method.rslt.reset(PyObject_CallNoArgs(method.OnPyLoadDwg));
            }
        }
    }
    catch (...)
    {
        acutPrintf(_T("\nOnPyInitApp failed: "));
    }
}

static void loadCommands(PyRxMethod& method, const PyModulePath& path)
{
    auto& rxApp = PyRxApp::instance();
    PyObject* pKey = nullptr, * pValue = nullptr;
    for (Py_ssize_t i = 0; PyDict_Next(method.mdict, &i, &pKey, &pValue);)
    {
        const AcString key = PyUnicode_AsAcString(pKey);
        if (key.find(PyCommandPrefix) != -1)
        {
            const AcString commandName = towupper(key.substr(PyCommandPrefix.length(), key.length() - 1));
            if (PyFunction_Check(pValue))
            {
                const int commandFlags = PyCmd::getCommandFlags(pValue);
                rxApp.commands.emplace(commandName, pValue);
                rxApp.pathForCommand.emplace(commandName, path.modulePath);
                PyRxModule::regCommand(formatFileNameforCommandGroup(path.moduleName), commandName, commandFlags);
            }
        }
        if (key.find(PyLispFuncPrefix) != -1)
        {
            rxApp.lispService.tryAddFunc(path.modulePath, key, pValue);
        }
    }
}

static void reloadCommands(PyRxMethod& method, const PyModulePath& path)
{
    auto& rxApp = PyRxApp::instance();
    PyObject* pKey = nullptr, * pValue = nullptr;
    for (Py_ssize_t i = 0; PyDict_Next(method.mdict, &i, &pKey, &pValue);)
    {
        const AcString key = PyUnicode_AsAcString(pKey);
        if (key.find(PyCommandPrefix) != -1)
        {
            const AcString commandName = towupper(key.substr(PyCommandPrefix.length(), key.length() - 1));
            if (PyFunction_Check(pValue))
            {
                if (rxApp.commands.contains(commandName))
                {
                    rxApp.commands[commandName] = pValue;
                }
                else
                {
                    const int commandFlags = PyCmd::getCommandFlags(pValue);
                    rxApp.commands.emplace(commandName, pValue);
                    rxApp.pathForCommand.emplace(commandName, path.modulePath);
                    PyRxModule::regCommand(formatFileNameforCommandGroup(path.moduleName), commandName, commandFlags);
                }
            }
        }
        if (key.find(PyLispFuncPrefix) != -1)
        {
            rxApp.lispService.tryAddFunc(path.modulePath, key, pValue);
        }
    }
}

bool loadPythonModule(const PyModulePath& path, bool silent)
{
    std::error_code ec;
    auto& rxApp = PyRxApp::instance();
    AutoCWD pAutoCWD(path.modulePath);

    if (rxApp.funcNameMap.contains(path.moduleName))
    {
        if (!silent)
            acutPrintf(_T("\nModule %ls Already loaded, use pyreload"), (const TCHAR*)path.moduleName);
        return false;
    }
    PyRxMethod method; // wants the file name, no extension, in the same case as existing
    PyRxApp::appendSearchPath(path.modulePath, true);
    method.modname.reset(wstr_to_py(path.fullPath.filename().replace_extension()));
    method.mod.reset(PyImport_Import(method.modname.get()));
    if (PyErr_Occurred() != NULL)
        acutPrintf(_T("\nPyErr %ls: "), PyRxApp::the_error().c_str());
    PyRxApp::popFrontSearchPath(path.modulePath);//(#294) 

    if (method.mod != nullptr)
    {
        // this is to ensure that the module was not loaded elsewhere, i.e. a stdLib file
        std::filesystem::path actual = PyModule_GetFilename(method.mod.get());
        if (!std::filesystem::equivalent(actual, path.fullPath, ec))
        {
            if (!silent)
            {
                acutPrintf(_T("\nWarning!, paths do not match! \nLoad = %ls \nActual = %ls: "), path.fullPath.c_str(), actual.c_str());
            }
        }
        method.mdict = PyModule_GetDict(method.mod.get());
        loadPyAppReactors(method);
        loadCommands(method, path);
        rxApp.funcNameMap.emplace(path.moduleName, std::move(method));
        if (!silent)
            acutPrintf(_T("\nSuccess module %ls is loaded: "), (const TCHAR*)path.moduleName);
        onLoadPyModule(path.moduleName);
        rxApp.loadedModuleNames.insert(towlower(path.fullPath.wstring()));
        return true;
    }
    else
    {
        if (!silent)
            acutPrintf(_T("\nFailed to import %ls module: "), (const TCHAR*)path.moduleName);
        rxApp.funcNameMap.erase(path.moduleName);
    }
    return false;
}

bool reloadPythonModule(const PyModulePath& path, bool silent)
{
    auto& rxApp = PyRxApp::instance();
    AutoCWD pAutoCWD(path.modulePath);
    if (rxApp.funcNameMap.contains(path.moduleName))
    {
        callOnPyUnloadAppBeforeReloading(path.moduleName);
        PyRxMethod& method = rxApp.funcNameMap.at(path.moduleName);
        method.mod.reset(PyImport_ReloadModule(method.mod.get()));
        if (PyErr_Occurred() != NULL)
            acutPrintf(_T("\nPyErr %ls: "), PyRxApp::the_error().c_str());
        if (method.mod != nullptr)
        {
            method.mdict = PyModule_GetDict(method.mod.get());
            loadPyAppReactors(method);
            reloadCommands(method, path);
            rxApp.funcNameMap.emplace(path.moduleName, std::move(method));
            if (!silent)
                acutPrintf(_T("\nSuccess module %ls is reloaded: "), (const TCHAR*)path.moduleName);
            onPyReload(path.moduleName);
            onLoadPyModule(path.moduleName);
            rxApp.loadedModuleNames.insert(towlower(path.fullPath.wstring()));
            return true;
        }
        else
        {
            rxApp.funcNameMap.erase(path.moduleName);
            if (!silent)
                acutPrintf(_T("\nFailed to import %ls module: "), (const TCHAR*)path.moduleName);
            return false;
        }
    }
    else
    {
        acutPrintf(_T("\nModule %ls was never loaded, use pyload"), (const TCHAR*)path.moduleName);
        return false;
    }
}

bool ads_loadPythonModule(const std::filesystem::path& pypath, bool silent)
{
    try
    {
        PyAutoLockGIL lock;
        PyModulePath modulePath;
        std::filesystem::path _path = pypath;
        modulePath.fullPath = pypath;
        modulePath.moduleName = moduleNameFromPath(_path);
        modulePath.modulePath = _path.remove_filename();
        return loadPythonModule(modulePath, silent);
    }
    catch (...)
    {
        acutPrintf(_T("\nException in %ls: \n"), __FUNCTIONW__);
    }
    return false;
}

bool ads_reloadPythonModule(const std::filesystem::path& pypath, bool silent)
{
    try
    {
        PyAutoLockGIL lock;
        PyModulePath modulePath;
        std::filesystem::path _path = pypath;
        modulePath.fullPath = pypath;
        modulePath.moduleName = moduleNameFromPath(_path);
        modulePath.modulePath = _path.remove_filename();
        return reloadPythonModule(modulePath, silent);
    }
    catch (...)
    {
        acutPrintf(_T("\nException in %ls: \n"), __FUNCTIONW__);
    }
    return false;
}
