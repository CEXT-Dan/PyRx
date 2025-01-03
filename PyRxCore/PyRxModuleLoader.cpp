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
    return _modulename;
}

static AcString moduleNameFromPath(const std::filesystem::path& path)
{
    std::filesystem::path tmp = path;
    tmp.replace_extension();
    AcString val = tmp.filename().c_str();
    val.makeUpper();
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
    if (getFileDia() == 1)
    {
        struct resbuf* pResBuf = nullptr;
        int ret = acedGetFileNavDialog(_T("Select Python File"), _T(""), _T("py;pyc"), _T("Browse Python File"), 0, &pResBuf);
        if (ret != RTNORM || pResBuf == nullptr)
        {
            acutPrintf(_T("\nFailed to read file: "));
            return false;
        }
        std::filesystem::path _path{ pResBuf->resval.rstring };
        path.fullPath = _path;
        path.moduleName = moduleNameFromPath(_path);
        path.modulePath = _path.remove_filename();
        acutRelRb(pResBuf);
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
    }
    return true;
}

boost::python::object PyCommandDecorator1(InternalCmdFlags flags /*= kMODAL*/)
{
    return PyCommandDecorator2("", flags);
}

boost::python::object PyCommandDecorator2(const std::string& name, InternalCmdFlags flags)
{
    static AcString m_name;
    static InternalCmdFlags m_flags;
    {
        if (!name.empty())
            m_name = utf8_to_wstr(name).c_str();
        else
            m_name.setEmpty();
        m_flags = flags;
    }
    struct CommandObject
    {
        static boost::python::object func(const boost::python::object& _pyfunc)
        {
            if (m_name.isEmpty())
            {
                PyObjectPtr funcName(PyObject_GetAttrString(_pyfunc.ptr(), "__name__"));
                if (funcName == nullptr)
                    return _pyfunc;
                m_name = PyUnicode_AsWideCharString(funcName.get(), nullptr);
            }
            m_name.makeUpper();
            PyObjectPtr moduleName(PyObject_GetAttrString(_pyfunc.ptr(), "__module__"));
            if (moduleName == nullptr)
                return _pyfunc;
            AcString acmodulename = PyUnicode_AsWideCharString(moduleName.get(), nullptr);
            auto path = std::filesystem::current_path() / static_cast<const wchar_t*>(acmodulename);
            path.replace_extension(_T(".py"));
            if (AcString foundPath; acdbHostApplicationServices()->findFile(foundPath, path.c_str()) == eOk)
            {
                auto& rxApp = PyRxApp::instance();
                if (rxApp.commands.contains(m_name))
                    rxApp.commands.at(m_name) = _pyfunc.ptr();
                else
                    rxApp.commands.emplace(m_name, _pyfunc.ptr());

                if (rxApp.pathForCommand.contains(m_name))
                    rxApp.pathForCommand.at(m_name) = std::filesystem::current_path();
                else
                    rxApp.pathForCommand.emplace(m_name, std::filesystem::current_path());
                PyRxModule::regCommand(formatFileNameforCommandGroup(acmodulename), m_name, m_flags);
            }
            return _pyfunc;
        }
    };
    return boost::python::make_function(CommandObject::func);
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

void regcommand(const std::string& fullpath, const std::string& modulename, const std::string& name, const boost::python::object& func, InternalCmdFlags flags)
{
    AcString m_name = utf8_to_wstr(name).c_str();
    std::filesystem::path modulePath = utf8_to_wstr(fullpath).c_str();
    m_name.makeUpper();
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

static void loadCommands(PyRxMethod& method, const PyModulePath& path)
{
    auto& rxApp = PyRxApp::instance();
    PyObject* pKey = nullptr, * pValue = nullptr;
    for (Py_ssize_t i = 0; PyDict_Next(method.mdict, &i, &pKey, &pValue);)
    {
        const AcString key = utf8_to_wstr(PyUnicode_AsUTF8(pKey)).c_str();
        if (key.find(PyCommandPrefix) != -1)
        {
            const AcString commandName = key.substr(PyCommandPrefix.length(), key.length() - 1).makeUpper();
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
            rxApp.lispService.tryAddFunc(key, pValue);
        }
    }
}

static void reloadCommands(PyRxMethod& method, const PyModulePath& path)
{
    auto& rxApp = PyRxApp::instance();
    PyObject* pKey = nullptr, * pValue = nullptr;
    for (Py_ssize_t i = 0; PyDict_Next(method.mdict, &i, &pKey, &pValue);)
    {
        AcString key = utf8_to_wstr(PyUnicode_AsUTF8(pKey)).c_str();
        if (key.find(PyCommandPrefix) != -1)
        {
            const AcString commandName = key.substr(PyCommandPrefix.length(), key.length() - 1).makeUpper();
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
            rxApp.lispService.tryAddFunc(key, pValue);
        }
    }
}

bool loadPythonModule(const PyModulePath& path, bool silent)
{
    std::error_code ec;
    auto& rxApp = PyRxApp::instance();
    const auto oldpath = std::filesystem::current_path(ec);
    std::filesystem::current_path(path.modulePath, ec);

    if (rxApp.funcNameMap.contains(path.moduleName))
    {
        acutPrintf(_T("\nModule %ls Already loaded, use pyreload"), (const TCHAR*)path.moduleName);
        return true;
    }
    PyRxMethod method; // wants the file name, no extension, in the same case as existing
    PyRxApp::appendSearchPath(path.modulePath);
    method.modname.reset(wstr_to_py(path.fullPath.filename().replace_extension()));
    method.mod.reset(PyImport_Import(method.modname.get()));
    if (method.mod != nullptr)
    {
        std::filesystem::path actual = PyModule_GetFilename(method.mod.get());
        if (!std::filesystem::equivalent(actual, path.fullPath, ec))
        {
            acutPrintf(_T("\nFailed, paths do not match!: "));
            return false;
        }
        method.mdict = PyModule_GetDict(method.mod.get());
        loadPyAppReactors(method);
        loadCommands(method, path);
        rxApp.funcNameMap.emplace(path.moduleName, std::move(method));
        if (!silent)
        {
            acutPrintf(_T("\nSuccess module %ls is loaded: "), (const TCHAR*)path.moduleName);
        }
        onLoadPyModule(path.moduleName);
        rxApp.loadedModuleNames.insert(towlower(path.fullPath.wstring()));
        return true;
    }
    else
    {
        if (PyErr_Occurred() != NULL)
        {
            acutPrintf(_T("\nPyErr %ls: "), PyRxApp::the_error().c_str());
            return false;
        }
        acutPrintf(_T("\nFailed to import %ls module: "), (const TCHAR*)path.moduleName);
        rxApp.funcNameMap.erase(path.moduleName);
    }
    std::filesystem::current_path(oldpath, ec);
    return false;
}

bool reloadPythonModule(const PyModulePath& path, bool silent)
{
    auto& rxApp = PyRxApp::instance();
    if (rxApp.funcNameMap.contains(path.moduleName))
    {
        PyRxMethod& method = rxApp.funcNameMap.at(path.moduleName);
        method.mod.reset(PyImport_ReloadModule(method.mod.get()));
        if (method.mod != nullptr)
        {
            method.mdict = PyModule_GetDict(method.mod.get());
            loadPyAppReactors(method);
            reloadCommands(method, path);
            rxApp.funcNameMap.emplace(path.moduleName, std::move(method));
            if (!silent)
            {
                acutPrintf(_T("\nSuccess module %ls is reloaded: "), (const TCHAR*)path.moduleName);
            }
            onLoadPyModule(path.moduleName);
            onPyReload(path.moduleName);
            rxApp.loadedModuleNames.insert(towlower(path.fullPath.wstring()));
            return true;
        }
        else
        {
            rxApp.funcNameMap.erase(path.moduleName);
            if (PyErr_Occurred() != NULL)
            {
                acutPrintf(_T("\nPyErr %ls: "), PyRxApp::the_error().c_str());
                return false;
            }
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

bool ads_loadPythonModule(const std::filesystem::path& pypath)
{
    try
    {
        PyAutoLockGIL lock;
        PyModulePath modulePath;
        std::filesystem::path _path = pypath;
        modulePath.fullPath = pypath;
        modulePath.moduleName = moduleNameFromPath(_path);
        modulePath.modulePath = _path.remove_filename();
        return loadPythonModule(modulePath, true);
    }
    catch (...)
    {
        acutPrintf(_T("\nException in %ls: \n"), __FUNCTIONW__);
    }
    return false;
}

bool ads_reloadPythonModule(const std::filesystem::path& pypath)
{
    try
    {
        PyAutoLockGIL lock;
        PyModulePath modulePath;
        std::filesystem::path _path = pypath;
        modulePath.fullPath = pypath;
        modulePath.moduleName = moduleNameFromPath(_path);
        modulePath.modulePath = _path.remove_filename();
        return reloadPythonModule(modulePath, true);
    }
    catch (...)
    {
        acutPrintf(_T("\nException in %ls: \n"), __FUNCTIONW__);
    }
    return false;
}
