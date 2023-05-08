// (C) Copyright 2002-2007 by Autodesk, Inc. 
//
// Permission to use, copy, modify, and distribute this software in
// object code form for any purpose and without fee is hereby granted, 
// provided that the above copyright notice appears in all copies and 
// that both that copyright notice and the limited warranty and
// restricted rights notice below appear in all supporting 
// documentation.
//
// AUTODESK PROVIDES THIS PROGRAM "AS IS" AND WITH ALL FAULTS. 
// AUTODESK SPECIFICALLY DISCLAIMS ANY IMPLIED WARRANTY OF
// MERCHANTABILITY OR FITNESS FOR A PARTICULAR USE.  AUTODESK, INC. 
// DOES NOT WARRANT THAT THE OPERATION OF THE PROGRAM WILL BE
// UNINTERRUPTED OR ERROR FREE.
//
// Use, duplication, or disclosure by the U.S. Government is subject to 
// restrictions set forth in FAR 52.227-19 (Commercial Computer
// Software - Restricted Rights) and DFAR 252.227-7013(c)(1)(ii)
// (Rights in Technical Data and Computer Software), as applicable.
//

//-----------------------------------------------------------------------------
//----- acrxEntryPoint.cpp
//-----------------------------------------------------------------------------
#include "StdAfx.h"
#include "resource.h"
#include "PyLispService.h"
#include "PyRxApp.h"

//-----------------------------------------------------------------------------
#define szRDS _RXST("")

//-----------------------------------------------------------------------------
//----- ObjectARX EntryPoint
class AcRxPyApp : public AcRxArxApp
{
public:
    AcRxPyApp() : AcRxArxApp()
    {
    }

    virtual AcRx::AppRetCode On_kInitAppMsg(void* pkt)
    {
        AcRx::AppRetCode retCode = AcRxArxApp::On_kInitAppMsg(pkt);
        acedRegisterOnIdleWinMsg(AcedOnIdleMsgFn);
        acrxLockApplication(pkt);
        return (retCode);
    }

    virtual AcRx::AppRetCode On_kUnloadAppMsg(void* pkt)
    {
        AcRx::AppRetCode retCode = AcRxArxApp::On_kUnloadAppMsg(pkt);
        try
        {
            WxPyAutoLock lock;
            PyRxApp::instance().uninit();
            acedRegCmds->removeGroup(_T("PYCOMMANDS"));
        }
        catch (...) {}
        return (retCode);
    }

    virtual AcRx::AppRetCode On_kLoadDwgMsg(void* pkt) override
    {
        AcRx::AppRetCode retCode = AcRxArxApp::On_kLoadDwgMsg(pkt);
        try
        {
            for (auto& method : PyRxApp::instance().fnm)
            {
                if (method.second.OnPyLoadDwg != nullptr)
                {
                    WxPyAutoLock lock;
                    if (PyCallable_Check(method.second.OnPyLoadDwg))
                        method.second.rslt.reset(PyObject_CallFunction(method.second.OnPyLoadDwg, NULL));
                }
            }
            PyRxApp::instance().lispService.On_kLoadDwgMsg();
        }
        catch (...) {}
        return retCode;
    }

    virtual AcRx::AppRetCode On_kUnloadDwgMsg(void* pkt) override
    {
        AcRx::AppRetCode retCode = AcRxArxApp::On_kUnloadDwgMsg(pkt);
        try
        {
            for (auto& method : PyRxApp::instance().fnm)
            {
                if (method.second.OnPyUnloadDwg != nullptr)
                {
                    WxPyAutoLock lock;
                    if (PyCallable_Check(method.second.OnPyUnloadDwg))
                        method.second.rslt.reset(PyObject_CallFunction(method.second.OnPyUnloadDwg, NULL));
                }
            }
        }
        catch (...) {}
        return retCode;
    }

    virtual void RegisterServerComponents()
    {
    }

    static void AcedOnIdleMsgFn()
    {
        PRINTVER();
        if (!PyRxApp::instance().init())
            acutPrintf(_T("\nPyInit Failed"));
        acedRemoveOnIdleWinMsg(AcedOnIdleMsgFn);
    }

    static AcString GETVER()
    {
        constexpr TCHAR MAJOR1 = '1';
        constexpr TCHAR MINOR1 = '1';
        constexpr TCHAR REVISION1 = '1', REVISION2 = '1', REVISION3 = '5';

        constexpr unsigned int compileYear = (__DATE__[7] - '0') * 1000 + (__DATE__[8] - '0') * 100 + (__DATE__[9] - '0') * 10 + (__DATE__[10] - '0');
        constexpr unsigned int compileMonth = (__DATE__[0] == 'J') ? ((__DATE__[1] == 'a') ? 1 : ((__DATE__[2] == 'n') ? 6 : 7))    // Jan, Jun or Jul
            : (__DATE__[0] == 'F') ? 2                                                              // Feb
            : (__DATE__[0] == 'M') ? ((__DATE__[2] == 'r') ? 3 : 5)                                 // Mar or May
            : (__DATE__[0] == 'A') ? ((__DATE__[2] == 'p') ? 4 : 8)                                 // Apr or Aug
            : (__DATE__[0] == 'S') ? 9                                                              // Sep
            : (__DATE__[0] == 'O') ? 10                                                             // Oct
            : (__DATE__[0] == 'N') ? 11                                                             // Nov
            : (__DATE__[0] == 'D') ? 12                                                             // Dec
            : 0;
        constexpr unsigned int compileDay = (__DATE__[4] == ' ') ? (__DATE__[5] - '0') : (__DATE__[4] - '0') * 10 + (__DATE__[5] - '0');

        constexpr TCHAR IsoDate[] =
        {
           MAJOR1, '.' , MINOR1 , '.', REVISION1, REVISION2, REVISION3,
           '.', compileYear / 1000 + '0', (compileYear % 1000) / 100 + '0', (compileYear % 100) / 10 + '0', compileYear % 10 + '0',
           compileMonth / 10 + '0', compileMonth % 10 + '0',
           compileDay / 10 + '0', compileDay % 10 + '0', 0
        };
        AcString ver = IsoDate;
        return ver;
    }

    static void PRINTVER()
    {
        acutPrintf(_T("\nCEXT_PyRx version <%ls> loaded:\n"), GETVER().constPtr());
    }

    static void onload(AcString& moduleName)
    {
        try
        {
            WxPyAutoLock lock;
            if (PyRxApp::instance().fnm.contains(moduleName))
            {
                auto& method = PyRxApp::instance().fnm.at(moduleName);
                if (method.OnPyInitApp != nullptr)
                {
                    if (PyCallable_Check(method.OnPyInitApp))
                        method.rslt.reset(PyObject_CallFunction(method.OnPyInitApp, NULL));
                }
                if (method.OnPyLoadDwg != nullptr)
                {
                    if (PyCallable_Check(method.OnPyLoadDwg))
                        method.rslt.reset(PyObject_CallFunction(method.OnPyLoadDwg, NULL));
                }
            }
        }
        catch (...)
        {
            acutPrintf(_T("\npyload failed: "));
        }
    }

    static bool pyNavFileNavDialog(std::filesystem::path& pysyspath, AcString& pathName, AcString& moduleName)
    {
        std::filesystem::path pypath;
        struct resbuf* pResBuf = nullptr;
        int ret = acedGetFileNavDialog(_T("Select Python File"), _T(""), _T("py"), _T("Browse Python File"), 0, &pResBuf);
        if (ret != RTNORM)
        {
            acutPrintf(_T("\nacedGetFileNavDialog Failed"));
            return false;
        }
        pypath = pResBuf->resval.rstring;
        pysyspath = pResBuf->resval.rstring;
        pysyspath.remove_filename();
        PyRxApp::pyRxAppendSearchPath(pysyspath.c_str());
        pypath.replace_extension(_T(""));
        acutRelRb(pResBuf);

        pathName = pypath.filename().c_str();
        moduleName = pathName;
        moduleName.makeUpper();
        return true;
    }

    //TODO: needs improvement 
    static void AcRxPyApp_pyload(void)
    {
        try
        {
            WxPyAutoLock lock;
            if (PyRxApp::instance().isLoaded)
            {
                AcString pathName;
                AcString moduleName;
                std::filesystem::path pysyspath;
                if (!pyNavFileNavDialog(pysyspath, pathName, moduleName))
                    return;
                if (PyRxApp::instance().fnm.contains(moduleName))
                {
                    acutPrintf(_T("\nModule %ls Already loaded, use pyreload"), (const TCHAR*)moduleName);
                    return;
                }
                PyRxMethod method;
                method.modname.reset(wstr_to_py((const TCHAR*)pathName));
                method.mod.reset(PyImport_Import(method.modname.get()));
                if (method.mod != nullptr)
                {
                    //module initapp
                    method.mdict = PyModule_GetDict(method.mod.get());
                    method.OnPyInitApp = PyDict_GetItemString(method.mdict, "OnPyInitApp");
                    method.OnPyUnloadApp = PyDict_GetItemString(method.mdict, "OnPyUnloadApp");
                    method.OnPyLoadDwg = PyDict_GetItemString(method.mdict, "OnPyLoadDwg");
                    method.OnPyUnloadDwg = PyDict_GetItemString(method.mdict, "OnPyUnloadDwg");

                    PyObject* pKey = nullptr, * pValue = nullptr;
                    for (Py_ssize_t i = 0; PyDict_Next(method.mdict, &i, &pKey, &pValue);)
                    {
                        const AcString key = utf8_to_wstr(PyUnicode_AsUTF8(pKey)).c_str();
                        if (key.find(PyCommandPrefix) != -1)
                        {
                            AcString commandName = key.substr(PyCommandPrefix.length(), key.length() - 1);
                            if (PyFunction_Check(pValue))
                            {
                                PyRxApp::instance().commands.emplace(commandName.makeUpper(), pValue);
                                PyRxApp::instance().pathForCommand.emplace(commandName, pysyspath);
                                acedRegCmds->addCommand(_T("PYCOMMANDS"), commandName, commandName, ACRX_CMD_TRANSPARENT, AcRxPyApp_pyfunc);
                            }
                        }
                        if (key.find(PyLispFuncPrefix) != -1)
                        {
                            PyRxApp::instance().lispService.tryAddFunc(key, pValue);
                        }
                    }
                    PyRxApp::instance().fnm.emplace(moduleName, std::move(method));
                    acutPrintf(_T("\nSuccess module %ls is loaded: "), (const TCHAR*)moduleName);
                    onload(moduleName);
                }
                else
                {
                    if (PyErr_Occurred() != NULL)
                    {
                        acutPrintf(_T("\nPyErr %ls: "), PyRxApp::the_error().c_str());
                        return;
                    }
                    acutPrintf(_T("\nFailed to import %ls module: "), (const TCHAR*)moduleName);
                    PyRxApp::instance().fnm.erase(moduleName);
                }
            }
        }
        catch (...)
        {
            acutPrintf(_T("\npyload failed: "));
        }
    }

    //TODO: needs improvement 
    static void AcRxPyApp_pyreload(void)
    {
        try
        {
            WxPyAutoLock lock;
            if (PyRxApp::instance().isLoaded)
            {
                AcString pathName;
                AcString moduleName;
                std::filesystem::path pysyspath;
                if (!pyNavFileNavDialog(pysyspath, pathName, moduleName))
                    return;
                if (PyRxApp::instance().fnm.contains(moduleName))
                {
                    PyRxMethod& method = PyRxApp::instance().fnm.at(moduleName);
                    method.mod.reset(PyImport_ReloadModule(method.mod.get()));
                    if (method.mod != nullptr)
                    {
                        method.mdict = PyModule_GetDict(method.mod.get());
                        method.OnPyInitApp = PyDict_GetItemString(method.mdict, "OnPyInitApp");
                        method.OnPyUnloadApp = PyDict_GetItemString(method.mdict, "OnPyUnloadApp");
                        method.OnPyLoadDwg = PyDict_GetItemString(method.mdict, "OnPyLoadDwg");
                        method.OnPyUnloadDwg = PyDict_GetItemString(method.mdict, "OnPyUnloadDwg");

                        PyObject* pKey = nullptr, * pValue = nullptr;
                        for (Py_ssize_t i = 0; PyDict_Next(method.mdict, &i, &pKey, &pValue);)
                        {
                            AcString key = utf8_to_wstr(PyUnicode_AsUTF8(pKey)).c_str();
                            if (key.find(PyCommandPrefix) != -1)
                            {
                                AcString commandName = key.substr(PyCommandPrefix.length(), key.length() - 1);
                                if (PyFunction_Check(pValue))
                                {
                                    if (PyRxApp::instance().commands.contains(commandName.makeUpper()))
                                    {
                                        PyRxApp::instance().commands[commandName] = pValue;
                                    }
                                    else
                                    {
                                        PyRxApp::instance().commands.emplace(commandName, pValue);
                                        PyRxApp::instance().pathForCommand.emplace(commandName, pysyspath);
                                        acedRegCmds->addCommand(_T("PYCOMMANDS"), commandName, commandName, ACRX_CMD_TRANSPARENT, AcRxPyApp_pyfunc);
                                    }
                                }
                            }
                            if (key.find(PyLispFuncPrefix) != -1)
                            {
                                PyRxApp::instance().lispService.tryAddFunc(key, pValue);
                            }
                        }
                        PyRxApp::instance().fnm.emplace(moduleName, std::move(method));
                        acutPrintf(_T("\nSuccess module %ls is reloaded: "), (const TCHAR*)moduleName);
                        onload(moduleName);
                    }
                    else
                    {
                        PyRxApp::instance().fnm.erase(moduleName);
                        if (PyErr_Occurred() != NULL)
                        {
                            acutPrintf(_T("\nPyErr %ls: "), PyRxApp::the_error().c_str());
                            return;
                        }
                        acutPrintf(_T("\nFailed to import %ls module: "), (const TCHAR*)moduleName);
                    }
                }
                else
                {
                    acutPrintf(_T("\nModule %ls was never loaded, use pyload"), (const TCHAR*)moduleName);
                }
            }
        }
        catch (...)
        {
            acutPrintf(_T("\npyreload failed: "));
        }
    }

    static void AcRxPyApp_pyrxver(void)
    {
        PRINTVER();
    }

    static AcString commandForCurDocument()
    {
        AcString cmdName;
        ACHAR* pGlobalCmdName = nullptr;
        if (auto es = acedGetCommandForDocument(curDoc(), pGlobalCmdName); es != eOk)
            return cmdName;
        cmdName = pGlobalCmdName;
        acutDelString(pGlobalCmdName);
        cmdName.makeUpper();
        return cmdName;
    }

    static void AcRxPyApp_pyfunc(void)
    {
        if (curDoc() != nullptr)
        {
            const AcString cmdName = commandForCurDocument();
            if (PyRxApp::instance().commands.contains(cmdName))
            {
                try
                {
                    if (PyRxApp::instance().pathForCommand.contains(cmdName))
                        std::filesystem::current_path(PyRxApp::instance().pathForCommand.at(cmdName));

                    PyObject* method = PyRxApp::instance().commands.at(cmdName);
                    if (method != nullptr)
                    {
                        WxPyAutoLock lock;
                        PyErr_Clear();
                        if (PyCallable_Check(method))
                        {
                            PyObjectPtr rslt(PyObject_CallFunction(method, NULL));
                            if (rslt != nullptr)
                                return;
                        }
                    }
                }
                catch (...)
                {
                    acutPrintf(_T("\npyfunc failed with exception: "));
                }
            }
        }
        acutPrintf(_T("\npyfunc failed: "));
    }

    static std::string findPythonPath()
    {
        std::string res;

        const std::size_t ENV_BUF_SIZE = 8096;
        std::unique_ptr<char[]> chars(new char[ENV_BUF_SIZE]);

        std::size_t bufsize = ENV_BUF_SIZE;
        int e = getenv_s(&bufsize, chars.get(), bufsize, "PATH");
        if (e)
        {
            acutPrintf(L"FAIL");
            return res;
        }
        std::vector<std::string> paths;
        splitA(chars.get(), ';', paths);

   
        for (auto& item : paths)
        {
            if (item.ends_with("python310\\") || item.ends_with("python310"))
                res = item;
        }
        return res;
    }

    static void AcRxPyApp_doit(void)
    {
        acutPrintf(utf8_to_wstr(findPythonPath()).c_str());
    }
};

//-----------------------------------------------------------------------------
IMPLEMENT_ARX_ENTRYPOINT(AcRxPyApp)
ACED_ARXCOMMAND_ENTRY_AUTO(AcRxPyApp, AcRxPyApp, _pyload, pyload, ACRX_CMD_TRANSPARENT, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(AcRxPyApp, AcRxPyApp, _pyreload, pyreload, ACRX_CMD_TRANSPARENT, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(AcRxPyApp, AcRxPyApp, _pyrxver, pyrxver, ACRX_CMD_TRANSPARENT, NULL)
//ACED_ARXCOMMAND_ENTRY_AUTO(AcRxPyApp, AcRxPyApp, _doit, doit, ACRX_CMD_TRANSPARENT, NULL)