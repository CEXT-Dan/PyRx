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
#include "PyRxAppSettings.h"
#include "PyAcRx.h"
#include "acedCmdNF.h"
#include "AcDbAssocAction.h"

//for testing
#ifdef PYRXDEBUG
#endif

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
        PyRxApp::instance().MAIN_THREAD_ID = std::this_thread::get_id();
        initPyRx();
        acedRegisterOnIdleWinMsg(PyRxOnIdleMsgFn);
#if !wxCHECK_VERSION(3, 3, 0)
        acedRegisterWatchWinMsg(PyWatchWinMsgFn);
#endif
        return (retCode);
    }

    virtual AcRx::AppRetCode On_kUnloadAppMsg(void* pkt) override
    {
        AcRx::AppRetCode retCode = AcRxArxApp::On_kUnloadAppMsg(pkt);
        acdbModelerEnd();
        acedRemoveOnIdleWinMsg(PyRxOnIdleMsgFn);
#if !wxCHECK_VERSION(3, 3, 0)
        acedRemoveWatchWinMsg(PyWatchWinMsgFn);
#endif
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
            PyRxApp::instance().uninit();
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
            internalLoad_host_init_py();
            handleCmdArgOnLoadInDocContext();
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
            acutPrintf(_T("Failed to load %ls: "), acismobj.c_str());
        if (const auto result = acrxLoadModule(acMPolygonObj.c_str(), false, false); !result)
            acutPrintf(_T("Failed to load %ls: "), acMPolygonObj.c_str());
#endif
    }

    static void initPyRx()
    {
        static bool doneOnce = false;
        if (!doneOnce)
        {
            printPyRxBuldVersion();
            if (!PyRxApp::instance().init())
                acedAlert(_T("\nPyInit Failed"));
            doneOnce = true;
        }
    }

    //[#254] 
    static void PyWatchWinMsgFn(const MSG* msg)
    {
#if !wxCHECK_VERSION(3, 3, 0)
        if (msg->hwnd == adsw_acadDocWnd() || msg->hwnd == adsw_acadMainWnd())
            return;
        if (msg->message == WM_MOUSEMOVE)
            wxToolTip::RelayEvent((WXMSG*)msg);
#endif
    }

    static void PyRxOnIdleMsgFn()
    {
        flushPromptBuffer();
        PyApApplication::PyOnIdleMsgFn();
    }

    static void printPyRxBuldVersion()
    {
        acutPrintf(_T("\nPyRx version <%ls> loaded:\n"), getPyRxBuldVersion().constPtr());
    }

    static void handleCmdArgOnLoadInDocContext()
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
                    if (auto nx = std::next(iter, 1); nx != v.end())
                    {
                        if (AcString foundPath; acdbHostApplicationServices()->findFile(foundPath, nx->c_str()) == eOk)
                        {
                            if (PyRxApp::isPythonModule(foundPath))
                            {
                                if (ads_loadPythonModule((const wchar_t*)foundPath) == false)
                                    acutPrintf(_T("\nFailed to load module %ls: "), (const wchar_t*)foundPath);
                            }
                        }
                        return;
                    }
                }
            }
        }
    }

    static void internalLoad_host_init_py()
    {
        try
        {
            static bool loaded = false;
            if (!loaded)
            {
                loaded = true;
                if (!PyRxApp::instance().load_host_init())
                    acutPrintf(L"\ninternalLoad_host_init_py failed: ");
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
                    else
                        acutPrintf(_T("\npyload failed: "));
                }
            }
        }
        catch (...)
        {
            acutPrintf(_T("\nException %ls: "), __FUNCTIONW__);
        }
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
                    else
                        acutPrintf(_T("\npyreload failed: "));
                }
            }
        }
        catch (...)
        {
            acutPrintf(_T("\nException %ls: "), __FUNCTIONW__);
        }
    }

    static void AcRxPyApp_pyrxver(void)
    {
        printPyRxBuldVersion();
    }

    static void AcRxPyApp_pyrxdoc(void)
    {
        printPyRxBuldVersion();
        AutoCmdEcho cmdEcho;
        acedCommandS(RTSTR, _T("_BROWSER"), RTSTR, L"https://github.com/CEXT-Dan/PyRx/blob/main/Doc/README.MD", RTNONE);
    }

    static void AcRxPyApp_pycmdprompt(void)
    {
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
            ads_loadPythonModule(pypath) ? acedRetT() : acedRetNil();
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
            ads_reloadPythonModule(pypath) ? acedRetT() : acedRetNil();
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

#ifdef PYRXDEBUG
    //-- utilities 
    static auto createDatabaseFromDWG(const AcString& path, bool closeInput = true) noexcept
        -> std::tuple<Acad::ErrorStatus, std::unique_ptr<AcDbDatabase>>
    {
        auto pDb = std::make_unique<AcDbDatabase>(false, true);
        if (Acad::ErrorStatus es = pDb->readDwgFile(path); es != eOk)
        {
            return { es, nullptr };
        }
        if (closeInput)
        {
            if (Acad::ErrorStatus es = pDb->closeInput(true); es != eOk)
                return { es, nullptr };
        }
        return { eOk, std::move(pDb) };
    }

    static auto getModelSpaceId(AcDbDatabase* pDb) noexcept
        -> AcDbObjectId
    {
        return acdbSymUtil()->blockModelSpaceId(pDb);
    }

    static auto ConvertSSToIdArray(ads_name ssname, AcDbObjectIdArray& ids) noexcept
        -> Acad::PromptStatus
    {
        Adesk::Int32 nSize = 0;
        if (acedSSLength(ssname, &nSize) != RTNORM)
            return Acad::PromptStatus::eError;
        ids.setPhysicalLength(nSize);

        for (int i = 0; i < nSize; i++)
        {
            ads_name ename = { 0 };
            if (acedSSName(ssname, i, ename) == RTNORM)
            {
                AcDbObjectId objId;
                if (acdbGetObjectId(objId, ename) == eOk)
                {
                    ids.append(objId);
                }
            }
        }
        return Acad::PromptStatus::eNormal;
    }

    static auto ssget(resbuf* pFilter = nullptr) noexcept
        -> std::tuple<Acad::PromptStatus, AcDbObjectIdArray>
    {
        AcDbObjectIdArray ids;
        ads_name ssname = { 0L };
        int res = acedSSGet(NULL, NULL, NULL, pFilter, ssname);
        if (res != RTNORM || ConvertSSToIdArray(ssname, ids) != Acad::eNormal)
            return std::make_tuple(Acad::PromptStatus::eError, ids);
        acedSSFree(ssname);
        return std::make_tuple(static_cast<Acad::PromptStatus>(res), std::move(ids));
    }

    static auto getPoint() noexcept
        -> std::tuple<Acad::PromptStatus, AcGePoint3d>
    {
        AcGePoint3d pnt;
        int res = acedGetPoint(NULL, _T("\nGet Point: "), asDblArray(pnt));;
        return std::make_tuple(Acad::PromptStatus(res), pnt);
    }

    static auto postToModelSpace(AcDbEntity* pEnt) noexcept
        -> std::tuple<Acad::ErrorStatus, AcDbObjectId>
    {
        if (pEnt == nullptr)
            return std::make_tuple(Acad::eNullEntityPointer, AcDbObjectId::kNull);
        AcDbObjectId id;
        AcDbDatabase* pDb = acdbCurDwg();
        AcDbBlockTableRecordPointer model(getModelSpaceId(pDb), AcDb::OpenMode::kForWrite);
        Acad::ErrorStatus es = model->appendAcDbEntity(id, pEnt);
        return std::make_tuple(es, id);
    }

    static auto entsel(const TCHAR* msg = L"\nSelect Entity: ", const AcRxClass* desc = AcDbEntity::desc()) noexcept
        -> std::tuple<Acad::PromptStatus, AcDbObjectId, AcGePoint3d>
    {
        AcDbObjectId id;
        AcGePoint3d pnt;
        ads_name name = { 0L };
        auto res = static_cast<Acad::PromptStatus>(acedEntSel(msg, name, asDblArray(pnt)));
        if (res != Acad::eNormal)
            return std::make_tuple(res, id, pnt);
        if (auto es = acdbGetObjectId(id, name); es != eOk)
            return std::make_tuple(Acad::PromptStatus::eError, id, pnt);
        if (!id.objectClass()->isDerivedFrom(desc))
            return std::make_tuple(Acad::PromptStatus::eRejected, id, pnt);
        return std::make_tuple(res, id, pnt);
    }

    static void setTitleThemeDark(HWND hwnd)
    {
        constexpr DWORD DWMWA_USE_IMMERSIVE_DARK_MODE_I20 = 20;
        BOOL USE_DARK_MODE = true;
        DwmSetWindowAttribute(hwnd, DWMWA_USE_IMMERSIVE_DARK_MODE_I20, &USE_DARK_MODE, sizeof(USE_DARK_MODE));
        const auto style = GetWindowLong(hwnd, GWL_STYLE);
        SetWindowLong(hwnd, GWL_STYLE, 0);
        SetWindowLong(hwnd, GWL_STYLE, style);
    }

    static void PerformDarkMenuPaint(HWND hTargetWnd, RECT* pMenuBarStripOut = nullptr)
    {
        HDC hdc = GetWindowDC(hTargetWnd);
        if (!hdc) return;

        MENUBARINFO mbi = { 0 };
        mbi.cbSize = sizeof(MENUBARINFO);

        if (GetMenuBarInfo(hTargetWnd, OBJID_MENU, 0, &mbi))
        {
            RECT rcWindow;
            GetWindowRect(hTargetWnd, &rcWindow);
            int winWidth = rcWindow.right - rcWindow.left;

            RECT rcMenuBarStrip;
            rcMenuBarStrip.left = 0;
            rcMenuBarStrip.right = winWidth;
            rcMenuBarStrip.top = mbi.rcBar.top - rcWindow.top;
            rcMenuBarStrip.bottom = mbi.rcBar.bottom - rcWindow.top;

            // Applying your perfect layout alignment offsets
            rcMenuBarStrip.top += 0;
            rcMenuBarStrip.bottom += 2;

            if (pMenuBarStripOut) {
                *pMenuBarStripOut = rcMenuBarStrip;
            }

            // 1. Draw solid dark background canvas
            HBRUSH hDarkBrush = CreateSolidBrush(RGB(30, 30, 30));
            FillRect(hdc, &rcMenuBarStrip, hDarkBrush);
            DeleteObject(hDarkBrush);

            // 2. Re-render structural strings centered over their true hit-test targets
            HMENU hMenu = GetMenu(hTargetWnd);
            if (hMenu)
            {
                int count = GetMenuItemCount(hMenu);
                SetBkMode(hdc, TRANSPARENT);
                SetTextColor(hdc, RGB(240, 240, 240)); // Clean Off-White

                HFONT hFont = (HFONT)GetStockObject(DEFAULT_GUI_FONT);
                HFONT hOldFont = (HFONT)SelectObject(hdc, hFont);

                for (int i = 0; i < count; i++)
                {
                    TCHAR szMenuText[128];
                    GetMenuString(hMenu, i, szMenuText, 128, MF_BYPOSITION);

                    if (_tcslen(szMenuText) == 0) continue;

                    RECT rcItemScreen;
                    if (GetMenuItemRect(hTargetWnd, hMenu, i, &rcItemScreen))
                    {
                        RECT rcTextSlot;
                        rcTextSlot.left = rcItemScreen.left - rcWindow.left;
                        rcTextSlot.top = rcMenuBarStrip.top;
                        rcTextSlot.right = rcItemScreen.right - rcWindow.left;
                        rcTextSlot.bottom = rcMenuBarStrip.bottom;

                        DrawText(hdc, szMenuText, -1, &rcTextSlot, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
                    }
                }
                SelectObject(hdc, hOldFont);
            }
        }
        ReleaseDC(hTargetWnd, hdc);
    }

    static LRESULT CALLBACK DarkMenuBarSubclassProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam,
        UINT_PTR uIdSubclass, DWORD_PTR dwRefData)
    {
        // Capture core draw and window focus events
        if (uMsg == WM_NCPAINT || uMsg == WM_NCACTIVATE || uMsg == WM_MENUSELECT ||
            uMsg == WM_ENTERMENULOOP || uMsg == WM_EXITMENULOOP || uMsg == WM_MOUSEMOVE)
        {
            LRESULT res = DefSubclassProc(hWnd, uMsg, wParam, lParam);
            PerformDarkMenuPaint(hWnd);
            return res;
        }

        // Intercept mouse glide globally across the bar to wipe hot-track artifacts
        if (uMsg == WM_NCMOUSEMOVE)
        {
            if (wParam == HTMENU)
            {
                PerformDarkMenuPaint(hWnd);
                return 0;
            }
        }

        // Keep background solid dark when empty bar areas are clicked
        if (uMsg == WM_NCLBUTTONDOWN || uMsg == WM_NCLBUTTONDBLCLK)
        {
            if (wParam == HTMENU)
            {
                LRESULT res = DefSubclassProc(hWnd, uMsg, wParam, lParam);
                PerformDarkMenuPaint(hWnd);
                return res;
            }
        }

        // Stop Windows from executing the default high-priority light hover overlay loop
        if (uMsg == WM_SETCURSOR)
        {
            if (LOWORD(lParam) == HTMENU)
            {
                PerformDarkMenuPaint(hWnd);
                return TRUE;
            }
        }

        if (uMsg == WM_NCHITTEST)
        {
            return DefSubclassProc(hWnd, uMsg, wParam, lParam);
        }

        if (uMsg == WM_NCDESTROY)
        {
            RemoveWindowSubclass(hWnd, DarkMenuBarSubclassProc, uIdSubclass);
        }

        return DefSubclassProc(hWnd, uMsg, wParam, lParam);
    }

    static void InitializeDarkMenuBar()
    {
        enum PreferredAppMode { Default = 0, AllowDark = 1, ForceDark = 2, ForceLight = 3, Max = 4 };
        typedef bool (WINAPI* fnAllowDarkModeForWindow)(HWND hWnd, bool allow);
        typedef PreferredAppMode(WINAPI* fnSetPreferredAppMode)(PreferredAppMode appMode);
        typedef void (WINAPI* fnFlushMenuThemes)();

        HMODULE hUxTheme = GetModuleHandle(_T("uxtheme.dll"));
        if (!hUxTheme) return;

        auto SetPreferredAppMode = (fnSetPreferredAppMode)GetProcAddress(hUxTheme, MAKEINTRESOURCEA(135));
        auto AllowDarkModeForWindow = (fnAllowDarkModeForWindow)GetProcAddress(hUxTheme, MAKEINTRESOURCEA(133));
        auto FlushMenuThemes = (fnFlushMenuThemes)GetProcAddress(hUxTheme, MAKEINTRESOURCEA(136));

        // Force dropdowns dark using the hidden Win32 APIs
        if (SetPreferredAppMode && AllowDarkModeForWindow && FlushMenuThemes)
        {
            SetPreferredAppMode(PreferredAppMode::ForceDark);

            HWND hMainWnd = adsw_acadMainWnd(); // BricsCAD MFC Frame Window
            if (hMainWnd != NULL)
            {
                AllowDarkModeForWindow(hMainWnd, true);
                FlushMenuThemes();

                // Inject the window subclass hook to fix the top horizontal menu strip
                // The parameter '1' is a unique Identifier for this specific subclass hook
                SetWindowSubclass(hMainWnd, DarkMenuBarSubclassProc, 1, 0);

                // Force a total window repaint to trigger the new paint sequence instantly
                SetWindowPos(hMainWnd, NULL, 0, 0, 0, 0,
                    SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER | SWP_FRAMECHANGED);
            }
        }
    }

    static void AcRxPyApp_idoit1(void)
    {
        setTitleThemeDark(adsw_acadMainWnd());
        InitializeDarkMenuBar();
    }
#endif
};

//-----------------------------------------------------------------------------
#pragma warning ( push )
#pragma warning( disable: 4838 )
IMPLEMENT_ARX_ENTRYPOINT(AcRxPyApp)
ACED_ARXCOMMAND_ENTRY_AUTO(AcRxPyApp, AcRxPyApp, _pyload, pyload, ACRX_CMD_SESSION, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(AcRxPyApp, AcRxPyApp, _pyreload, pyreload, ACRX_CMD_SESSION, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(AcRxPyApp, AcRxPyApp, _pyrxdoc, pyrxdoc, ACRX_CMD_TRANSPARENT, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(AcRxPyApp, AcRxPyApp, _pyrxver, pyrxver, ACRX_CMD_TRANSPARENT, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(AcRxPyApp, AcRxPyApp, _pycmdprompt, pycmdprompt, ACRX_CMD_TRANSPARENT, NULL)
// lisp
ACED_ADSSYMBOL_ENTRY_AUTO(AcRxPyApp, adspyload, false)
ACED_ADSSYMBOL_ENTRY_AUTO(AcRxPyApp, adspyreload, false)
ACED_ADSSYMBOL_ENTRY_AUTO(AcRxPyApp, adspyloaded, false)
//test
ACED_ADSSYMBOL_ENTRY_AUTO(AcRxPyApp, pyrxlispsstest, false)
ACED_ADSSYMBOL_ENTRY_AUTO(AcRxPyApp, pyrxlisprttest, false)
#ifdef PYRXDEBUG
ACED_ARXCOMMAND_ENTRY_AUTO(AcRxPyApp, AcRxPyApp, _idoit1, idoit1, ACRX_CMD_MODAL, NULL)
#endif //PYRXDEBUG
#pragma warning( pop )