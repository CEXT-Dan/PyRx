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

//for testing
#include "PyRxAppSettings.h"

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

    virtual AcRx::AppRetCode On_kInitAppMsg(void* pkt) override
    {
        AcRx::AppRetCode retCode = AcRxArxApp::On_kInitAppMsg(pkt);
        acdbModelerStart();
        loadDBXModules();
        acrxLockApplication(pkt);
        PyRxApp::instance().appPkt = pkt;
        initPyRx();
        acedRegisterOnIdleWinMsg(PyRxOnIdleMsgFn);
        return (retCode);
    }

    virtual AcRx::AppRetCode On_kUnloadAppMsg(void* pkt) override
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
            internalLoad_onloadpy();
            sendOnLoadCmdArgInDocContext();
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

    virtual void RegisterServerComponents() override
    {
    }

    static void loadDBXModules()
    {
#if defined(_ARXTARGET)
        const int version = acdbHostApplicationServices()->releaseMajorVersion();
        const auto acismobj = std::format(_T("acismobj{}.dbx"), version);
        const auto acMPolygonObj = std::format(_T("AcMPolygonObj{}.dbx"), version);
        if (const auto result = acrxLoadModule(acismobj.c_str(), false, false); !result)
            acutPrintf(_T("Faled to load %ls: "), acismobj.c_str());
        if (const auto result = acrxLoadModule(acMPolygonObj.c_str(), false, false); !result)
            acutPrintf(_T("Faled to load %ls: "), acismobj.c_str());
#endif
    }

    static void initPyRx()
    {
        static bool doneOnce = false;
        if (!doneOnce)
        {
            printPyRxBuldVersion();
            if (!PyRxApp::instance().init())
                acutPrintf(_T("\nPyInit Failed"));
            doneOnce = true;
        }
    }

    static void PyRxOnIdleMsgFn()
    {
        PyApApplication::PyOnIdleMsgFn();
    }

    static void printPyRxBuldVersion()
    {
        acutPrintf(_T("\nPyRx version <%ls> loaded:\n"), getPyRxBuldVersion().constPtr());
    }

    static void sendOnLoadCmdArgInDocContext()
    {
        static bool parseld = false;
        if (parseld == false && PyRxApp::instance().isLoaded && curDoc() != nullptr)
        {
            parseld = true;
            const auto& v = PyRxAppSettings::getCommandLineArgs();
            for (auto iter = v.begin(); iter != v.end(); ++iter)
            {
                if (_wcsicmp(iter->c_str(), _T("/ld")) == 0)
                {
                    auto nx = std::next(iter, 1);
                    if (nx != v.end())
                    {
                        if (AcString foundPath; acdbHostApplicationServices()->findFile(foundPath, nx->c_str()) == eOk)
                        {
                            if (ads_loadPythonModule((const wchar_t*)foundPath) == false)
                                acutPrintf(_T("\nFailed to load module %ls: "), (const wchar_t*)foundPath);
                        }
                        return;
                    }
                }
            }
        }
    }

    static void internalLoad_onloadpy()
    {
        try
        {
            static bool loaded = false;
            if (!loaded)
            {
                loaded = true;
                PyRxApp::instance().load_pyrx_onload();
            }
        }
        catch (...)
        {
            acutPrintf(_T("\nException %ls: "), __FUNCTIONW__);
        }
    }

    static void AcRxPyApp_pyload(void)
    {
        try
        {
            PyAutoLockGIL lock;
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
            PyAutoLockGIL lock;
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
        printPyRxBuldVersion();
    }

    static void AcRxPyApp_pycmdprompt(void)
    {
        //TODO, this should be replaced with Python REPL #91
        //maybe a separate auto-load?
        try
        {
            AcString cmd;
            PyAutoLockGIL lock;
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

    static int ADSPREFIX(adspyload(void))
    {
        PyAutoLockGIL lock;
        AcResBufPtr pArgs(acedGetArgs());

        if (pArgs != nullptr && pArgs->restype == RTSTR)
        {
            std::filesystem::path pypath = pArgs->resval.rstring;
            bool flag = ads_loadPythonModule(pypath);
            flag ? acedRetT() : acedRetNil();
        }
        return RSRSLT;
    }

    static int ADSPREFIX(adspyreload(void))
    {
        PyAutoLockGIL lock;
        AcResBufPtr pArgs(acedGetArgs());

        if (pArgs != nullptr && pArgs->restype == RTSTR)
        {
            std::filesystem::path pypath = pArgs->resval.rstring;
            bool flag = ads_reloadPythonModule(pypath);
            flag ? acedRetT() : acedRetNil();
        }
        return RSRSLT;
    }

    static int ADSPREFIX(adspyloaded(void))
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

    static int ADSPREFIX(pyload(void))
    {
        static bool show = true;
        if (show)
        {
            acutPrintf(_T("\ndepreciated, use adspyload instead"));
            show = false;
        }
        return ADSPREFIX(adspyload());
    }

    static int ADSPREFIX(pyreload(void))
    {
        static bool show = true;
        if (show)
        {
            acutPrintf(_T("\ndepreciated, use adspyreload instead"));
            show = false;
        }
        return ADSPREFIX(adspyreload());
    }

    static int ADSPREFIX(pyloaded(void))
    {
        static bool show = true;
        if (show)
        {
            acutPrintf(_T("\ndepreciated, use adspyloaded instead"));
            show = false;
        }
        return ADSPREFIX(adspyloaded());
    }

    // These are for unit tests
    static int ADSPREFIX(pyrxlispsstest(void))
    {
        AcResBufPtr pArgs(acedGetArgs());
        if (pArgs != nullptr && pArgs->restype == RTPICKS)
        {
            Adesk::Int32 len = 0;
            if (auto rt = acedSSLength(pArgs->resval.rlname, &len); rt == RTNORM && len > 0)
            {
                acedRetT();
                return RSRSLT;
            }
        }
        acedRetNil();
        return RSRSLT;
    }

    static int ADSPREFIX(pyrxlisprttest(void))
    {
        AcResBufPtr pArgs(acedGetArgs());
        acedRetList(pArgs.get());
        return RSRSLT;
    }

#ifdef PYPERFPROFILER
    static void AcRxPyApp_pyprofiler(void)
    {
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
    //-- utilities 
    static auto entsel()
    {
        AcDbObjectId id;
        AcGePoint3d pnt;
        ads_name name = { 0L };
        int res = acedEntSel(L"\nSelect it: ", name, asDblArray(pnt));
        if (auto es = acdbGetObjectId(id, name); es != eOk)
            return std::make_tuple(Acad::PromptStatus::eError, id, pnt);
        return std::make_tuple(Acad::PromptStatus(res), id, pnt);
    }

    static auto ssget()
    {
        AcDbObjectIdArray ids;
        ads_name ssname = { 0L };
        AcResBufPtr pfilter/*(acutBuildList(RTDXF0, _T("LWPOLYLINE"), NULL))*/;
        int res = acedSSGet(NULL, NULL, NULL, pfilter.get(), ssname);
        if (res != RTNORM)
            return std::make_tuple(Acad::PromptStatus::eError, ids);
        if (acedGetCurrentSelectionSet(ids) != eOk)
            return std::make_tuple(Acad::PromptStatus::eError, ids);
        return std::make_tuple(Acad::PromptStatus(res), ids);
    }

    static auto postToModelSpace(AcDbEntity* pEnt)
    {
        AcDbObjectId id;
        AcDbDatabase* pDb = acdbHostApplicationServices()->workingDatabase();
        AcDbBlockTableRecordPointer model(acdbSymUtil()->blockModelSpaceId(pDb), AcDb::OpenMode::kForWrite);
        Acad::ErrorStatus es = model->appendAcDbEntity(id, pEnt);
        return std::make_tuple(es, id);
    }
    //--

    static void AcRxPyApp_idoit(void)
    {

    }
#endif
};

//-----------------------------------------------------------------------------
#pragma warning ( push )
#pragma warning( disable: 4838 )
IMPLEMENT_ARX_ENTRYPOINT(AcRxPyApp)
ACED_ARXCOMMAND_ENTRY_AUTO(AcRxPyApp, AcRxPyApp, _pyload, pyload, ACRX_CMD_SESSION, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(AcRxPyApp, AcRxPyApp, _pyreload, pyreload, ACRX_CMD_SESSION, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(AcRxPyApp, AcRxPyApp, _pyrxver, pyrxver, ACRX_CMD_TRANSPARENT, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(AcRxPyApp, AcRxPyApp, _pycmdprompt, pycmdprompt, ACRX_CMD_TRANSPARENT, NULL)
// lisp
ACED_ADSSYMBOL_ENTRY_AUTO(AcRxPyApp, adspyload, false)
ACED_ADSSYMBOL_ENTRY_AUTO(AcRxPyApp, adspyreload, false)
ACED_ADSSYMBOL_ENTRY_AUTO(AcRxPyApp, adspyloaded, false)
// to be depreciated
ACED_ADSSYMBOL_ENTRY_AUTO(AcRxPyApp, pyload, false)
ACED_ADSSYMBOL_ENTRY_AUTO(AcRxPyApp, pyreload, false)
ACED_ADSSYMBOL_ENTRY_AUTO(AcRxPyApp, pyloaded, false)

ACED_ADSSYMBOL_ENTRY_AUTO(AcRxPyApp, pyrxlispsstest, false)
ACED_ADSSYMBOL_ENTRY_AUTO(AcRxPyApp, pyrxlisprttest, false)
#ifdef PYPERFPROFILER
ACED_ARXCOMMAND_ENTRY_AUTO(AcRxPyApp, AcRxPyApp, _pyprofiler, pyprofiler, ACRX_CMD_MODAL, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(AcRxPyApp, AcRxPyApp, _pyprofilerend, pyprofilerend, ACRX_CMD_MODAL, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(AcRxPyApp, AcRxPyApp, _pyprofilerreset, pyprofilerreset, ACRX_CMD_MODAL, NULL)
#endif
#ifdef PYRXDEBUG
ACED_ARXCOMMAND_ENTRY_AUTO(AcRxPyApp, AcRxPyApp, _idoit, idoit, ACRX_CMD_MODAL, NULL)
#endif //PYRXDEBUG
#pragma warning( pop )