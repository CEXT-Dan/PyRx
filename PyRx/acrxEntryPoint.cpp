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
#include "rxvar.h"
#include "PyRxModule.h"
#include "PyRxModuleLoader.h"
#include "PyApApplication.h"

//-----------------------------------------------------------------------------
#define szRDS _RXST("")

#if defined(_ZRXTARGET)
#define ADSPREFIX(x) zds_ ## x
#elif defined(_GRXTARGET)
#define ADSPREFIX(x) gds_ ## x
#else
#define ADSPREFIX(x) ads_ ## x
#endif

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
        acdbModelerStart();
        loadDBXModules();
        acedRegisterOnIdleWinMsg(PyRxOnIdleMsgFn);
        acrxLockApplication(pkt);
        PyRxApp::instance().appPkt = pkt;
        return (retCode);
    }

    virtual AcRx::AppRetCode On_kUnloadAppMsg(void* pkt)
    {
        AcRx::AppRetCode retCode = AcRxArxApp::On_kUnloadAppMsg(pkt);
        acdbModelerEnd();
        try
        {
            if (PyRxApp::instance().funcNameMap.size() != 0)
            {
                PyAutoLockGIL lock;
                for (auto& method : PyRxApp::instance().funcNameMap)
                {
                    if (method.second.OnPyUnloadApp != nullptr)
                    {
                        if (PyCallable_Check(method.second.OnPyUnloadApp))
                            method.second.rslt.reset(PyObject_CallFunction(method.second.OnPyUnloadApp, NULL));
                    }
                }
            }
        }
        catch (...) { /*@exit*/ }
        return (retCode);
    }

    virtual AcRx::AppRetCode On_kLoadDwgMsg(void* pkt) override
    {
        AcRx::AppRetCode retCode = AcRxArxApp::On_kLoadDwgMsg(pkt);
        try
        {
            if (PyRxApp::instance().funcNameMap.size() != 0)
            {
                PyAutoLockGIL lock;
                for (auto& method : PyRxApp::instance().funcNameMap)
                {
                    if (method.second.OnPyLoadDwg != nullptr)
                    {
                        if (PyCallable_Check(method.second.OnPyLoadDwg))
                            method.second.rslt.reset(PyObject_CallFunction(method.second.OnPyLoadDwg, NULL));
                    }
                }
            }
            PyRxApp::instance().lispService.On_kLoadDwgMsg();
        }
        catch (...) { acutPrintf(_T("\nException %ls: "), __FUNCTIONW__); }
        return retCode;
    }

    virtual AcRx::AppRetCode On_kUnloadDwgMsg(void* pkt) override
    {
        AcRx::AppRetCode retCode = AcRxArxApp::On_kUnloadDwgMsg(pkt);
        try
        {
            if (PyRxApp::instance().funcNameMap.size() != 0)
            {
                PyAutoLockGIL lock;
                for (auto& method : PyRxApp::instance().funcNameMap)
                {
                    if (method.second.OnPyUnloadDwg != nullptr)
                    {
                        if (PyCallable_Check(method.second.OnPyUnloadDwg))
                            method.second.rslt.reset(PyObject_CallFunction(method.second.OnPyUnloadDwg, NULL));
                    }
                }
            }
        }
        catch (...) { acutPrintf(_T("\nException %ls: "), __FUNCTIONW__); }
        return retCode;
    }

    static void loadDBXModules()
    {
#if defined(_ARXTARGET)
        const int version = acdbHostApplicationServices()->releaseMajorVersion();
        const auto acismobj = std::format(_T("acismobj{}.dbx"), version);
        if (const auto result = acrxLoadModule(acismobj.c_str(), false, false); !result)
            acutPrintf(_T("Faled to load %ls: "), acismobj);
        const auto acMPolygonObj = std::format(_T("AcMPolygonObj{}.dbx"), version);
        if (const auto result = acrxLoadModule(acMPolygonObj.c_str(), false, false); !result)
            acutPrintf(_T("Faled to load %ls: "), acismobj);
#endif
    }

    virtual void RegisterServerComponents()
    {
    }

    static void PyRxOnIdleMsgFn()
    {
        static bool doneOnce = false;
        if (!doneOnce)
        {
            PRINTVER();
            if (!PyRxApp::instance().init())
                acutPrintf(_T("\nPyInit Failed"));
            doneOnce = true;
        }
        PyApApplication::PyOnIdleMsgFn();
    }

    static const AcString GETVER()
    {
        constexpr TCHAR MAJOR1 = '1';
        constexpr TCHAR MINOR1 = '3';
        constexpr TCHAR REVISION1 = '0', REVISION2 = '1', REVISION3 = '2';

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
        return AcString(IsoDate);
    }

    static void PRINTVER()
    {
        acutPrintf(_T("\nPyRx version <%ls> loaded:\n"), GETVER().constPtr());
    }

    static void AcRxPyApp_pyload(void)
    {
        try
        {
            WxPyAutoLock lock;
            if (PyRxApp::instance().isLoaded)
            {
                PyModulePath pypath;
                if (showNavFileDialog(pypath))
                {
                    if (loadPythonModule(pypath, false))
                        return;
                }
            }
        }
        catch (...)
        {
            acutPrintf(_T("\nException %ls: "), __FUNCTIONW__);
        }
        acutPrintf(_T("\npyload failed: "));
    }

    static void AcRxPyApp_pyreload(void)
    {
        try
        {
            WxPyAutoLock lock;
            if (PyRxApp::instance().isLoaded)
            {
                PyModulePath pypath;
                if (showNavFileDialog(pypath))
                {
                    if (reloadPythonModule(pypath, false))
                        return;
                }
            }
        }
        catch (...)
        {
            acutPrintf(_T("\nException %ls: "), __FUNCTIONW__);
        }
        acutPrintf(_T("\npyreload failed: "));
    }

    static void AcRxPyApp_pyrxver(void)
    {
        PRINTVER();
    }

    static void AcRxPyApp_pycmdprompt(void)
    {
        try
        {
            AcString cmd;
            WxPyAutoLock lock;
            PyObjectPtr PyRx_ForStdOut(PyImport_ImportModule("PyRx"));

            while (acedGetString(1, _T(">>>: "), cmd) == RTNORM)
            {
                //issue #13, quit, or exit terminates the process
                AcString cmdcpy = (const TCHAR*)cmd;
                cmdcpy.makeLower();
                if (cmdcpy.find(L"quit") != -1)
                    break;
                if (cmdcpy.find(L"exit") != -1)
                    break;
                PyRun_SimpleString(wstr_to_utf8((const TCHAR*)cmd).c_str());
            }
        }
        catch (...)
        {
            acutPrintf(_T("\nOops, something went wrong: "));
        }
    }

    static int ADSPREFIX(pyload(void))
    {
        WxPyAutoLock lock;
        AcResBufPtr pArgs(acedGetArgs());

        if (pArgs != nullptr && pArgs->restype == RTSTR)
        {
            std::filesystem::path pypath = pArgs->resval.rstring;
            bool flag = ads_loadPythonModule(pypath);
            flag ? acedRetT() : acedRetNil();
        }
        return RSRSLT;
    }

    static int ADSPREFIX(pyloaded(void))
    {
        AcResBufPtr pArgs(acutNewRb(RTSTR));
        resbuf* pTail = pArgs.get();
        for (auto& item : PyRxApp::instance().funcNameMap)
        {
            acutNewString(item.first, pTail->resval.rstring);
            pTail = pTail->rbnext = acutNewRb(RTSTR);
        }
        acutNewString(_T("PyRx"), pTail->resval.rstring);
        acedRetList(pArgs.get());
        return RSRSLT;
    }

#ifdef PYPERFPROFILER
    static void AcRxPyApp_pyprofiler(void)
    {
        ///
    }
    static void AcRxPyApp_pyprofilerend(void)
    {
        PyRxApp::instance().perfTimerEx.end();
    }
    static void AcRxPyApp_pyprofilerreset(void)
    {
        PyRxApp::instance().perfTimerEx.reset();
    }
#endif

#ifdef PYRXDEBUG
    static void AcRxPyApp_idoit(void)
    {
    }
#endif
};

//-----------------------------------------------------------------------------
#pragma warning( disable: 4838 )
IMPLEMENT_ARX_ENTRYPOINT(AcRxPyApp)
ACED_ARXCOMMAND_ENTRY_AUTO(AcRxPyApp, AcRxPyApp, _pyload, pyload, ACRX_CMD_SESSION, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(AcRxPyApp, AcRxPyApp, _pyreload, pyreload, ACRX_CMD_SESSION, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(AcRxPyApp, AcRxPyApp, _pyrxver, pyrxver, ACRX_CMD_TRANSPARENT, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(AcRxPyApp, AcRxPyApp, _pycmdprompt, pycmdprompt, ACRX_CMD_TRANSPARENT, NULL)
ACED_ADSSYMBOL_ENTRY_AUTO(AcRxPyApp, pyload, false)
ACED_ADSSYMBOL_ENTRY_AUTO(AcRxPyApp, pyloaded, false)
#ifdef PYPERFPROFILER
ACED_ARXCOMMAND_ENTRY_AUTO(AcRxPyApp, AcRxPyApp, _pyprofiler, pyprofiler, ACRX_CMD_MODAL, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(AcRxPyApp, AcRxPyApp, _pyprofilerend, pyprofilerend, ACRX_CMD_MODAL, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(AcRxPyApp, AcRxPyApp, _pyprofilerreset, pyprofilerreset, ACRX_CMD_MODAL, NULL)
#endif
#ifdef PYRXDEBUG
ACED_ARXCOMMAND_ENTRY_AUTO(AcRxPyApp, AcRxPyApp, _idoit, idoit, ACRX_CMD_MODAL, NULL)
#endif
#pragma warning( pop )