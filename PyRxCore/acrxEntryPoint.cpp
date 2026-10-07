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
        return (retCode);
    }

    virtual AcRx::AppRetCode On_kUnloadAppMsg(void* pkt) override
    {
        AcRx::AppRetCode retCode = AcRxArxApp::On_kUnloadAppMsg(pkt);
        acdbModelerEnd();
        acedRemoveOnIdleWinMsg(PyRxOnIdleMsgFn);
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

#ifdef NEVER
    static const ACHAR* fragmentText(const AcDbMTextFragment& fragment) noexcept
    {
        return fragment.msText.constPtr();
    }

    static const ACHAR* fragmentFont(const AcDbMTextFragment& fragment) noexcept
    {
        return fragment.msFont.constPtr();
    }

    static const ACHAR* fragmentBigFont(const AcDbMTextFragment& fragment) noexcept
    {
        return fragment.msBigFont.constPtr();
    }

    // Unicode? 
    static size_t nextUtf16CodePoint(const std::wstring& text, size_t offset) noexcept
    {
        if (offset + 1 < text.size()
            && text[offset] >= 0xD800 && text[offset] <= 0xDBFF
            && text[offset + 1] >= 0xDC00 && text[offset + 1] <= 0xDFFF)
        {
            return offset + 2;
        }
        return offset + 1;
    }

    static AcGePoint3d fragmentPointToWcs(
        const AcDbMTextFragment& fragment,
        const AcGeVector3d& xAxis,
        const AcGeVector3d& yAxis,
        const AcGePoint2d& point) noexcept
    {
        return fragment.location + xAxis * point.x + yAxis * point.y;
    }

    struct MTextCharacterBoxReporter
    {
        int fragmentIndex = 0;

        static int callback(AcDbMTextFragment* fragment, void* parameter)
        {
            auto* reporter = static_cast<MTextCharacterBoxReporter*>(parameter);
            if (fragment == nullptr || reporter == nullptr)
                return 1;

            const ACHAR* rawText = fragmentText(*fragment);
            if (rawText == nullptr || *rawText == L'\0')
            {
                acutPrintf(L"\nFragment %d is empty (usually a hard return).", reporter->fragmentIndex++);
                return 1;
            }

            const ACHAR* font = fragmentFont(*fragment);
            const ACHAR* bigFont = fragmentBigFont(*fragment);
            AcGiTextStyle style(
                font != nullptr ? font : L"",
                bigFont != nullptr ? bigFont : L"",
                fragment->capsHeight,
                fragment->widthFactor,
                fragment->obliqueAngle,
                fragment->trackingFactor,
                Adesk::kFalse, Adesk::kFalse, Adesk::kFalse,
                fragment->overlined, fragment->underlined, fragment->strikethrough);

            if ((style.loadStyleRec() & 1) == 0)
            {
                acutPrintf(L"\nFragment %d: cannot load font \"%ls\".",
                    reporter->fragmentIndex++, font != nullptr ? font : L"<default>");
                return 1;
            }

            if (fragment->direction.isZeroLength() || fragment->normal.isZeroLength())
            {
                acutPrintf(L"\nFragment %d: invalid text coordinate system.", reporter->fragmentIndex++);
                return 1;
            }

            AcGeVector3d xAxis = fragment->direction.normal();
            AcGeVector3d zAxis = fragment->normal.normal();
            AcGeVector3d yAxis = zAxis.crossProduct(xAxis);
            if (yAxis.isZeroLength())
            {
                acutPrintf(L"\nFragment %d: invalid text coordinate system.", reporter->fragmentIndex++);
                return 1;
            }
            yAxis.normalize();

            const std::wstring text(rawText);
            for (size_t first = 0, characterIndex = 0; first < text.size(); ++characterIndex)
            {
                const size_t last = nextUtf16CodePoint(text, first);
                const std::wstring glyph = text.substr(first, last - first);
                const std::wstring prefix = text.substr(0, first);

                const double advance = style.extents(
                    prefix.c_str(), Adesk::kTrue, static_cast<int>(prefix.size()), Adesk::kFalse).x;

                AcGePoint2d localMin;
                AcGePoint2d localMax;
                const Acad::ErrorStatus es = style.extentsBox(
                    glyph.c_str(), Adesk::kTrue, static_cast<int>(glyph.size()), Adesk::kFalse,
                    localMin, localMax);
                if (es != Acad::eOk)
                {
                    acutPrintf(L"\nFragment %d, character %d (\"%ls\"): extentsBox failed (%d).",
                        reporter->fragmentIndex, static_cast<int>(characterIndex), glyph.c_str(), es);
                    first = last;
                    continue;
                }

                localMin.x += advance;
                localMax.x += advance;
                const AcGePoint3d p0 = fragmentPointToWcs(*fragment, xAxis, yAxis, localMin);
                const AcGePoint3d p1 = fragmentPointToWcs(*fragment, xAxis, yAxis, AcGePoint2d(localMax.x, localMin.y));
                const AcGePoint3d p2 = fragmentPointToWcs(*fragment, xAxis, yAxis, localMax);
                const AcGePoint3d p3 = fragmentPointToWcs(*fragment, xAxis, yAxis, AcGePoint2d(localMin.x, localMax.y));

                if (glyph == L"C")
                    acedGrDraw(asDblArray(p0), asDblArray(p1), 3, 0);

                acutPrintf(L"\nF%d C%d \"%ls\" local[(%.8g, %.8g)-(%.8g, %.8g)] WCS[(%.8g, %.8g, %.8g), (%.8g, %.8g, %.8g), (%.8g, %.8g, %.8g), (%.8g, %.8g, %.8g)]",
                    reporter->fragmentIndex, static_cast<int>(characterIndex), glyph.c_str(),
                    localMin.x, localMin.y, localMax.x, localMax.y,
                    p0.x, p0.y, p0.z, p1.x, p1.y, p1.z, p2.x, p2.y, p2.z, p3.x, p3.y, p3.z);
                first = last;
            }

            ++reporter->fragmentIndex;
            return 1;
        }
    };
#endif

    static void AcRxPyApp_idoit1(void)
    {
#ifdef NEVER
        const auto selection = entsel(L"\nSelect MText: ", AcDbMText::desc());
        const auto status = std::get<0>(selection);
        if (status != Acad::eNormal)
            return;
        const auto id = std::get<1>(selection);
        AcDbObjectPointer<AcDbMText> mtext(id, AcDb::kForRead);
        if (mtext.openStatus() != Acad::eOk)
        {
            acutPrintf(L"\nUnable to open selected MText.");
            return;
        }
        acutPrintf(L"\n--- MText character boxes (oriented WCS rectangles) ---");
        MTextCharacterBoxReporter reporter;
        mtext->explodeFragments(MTextCharacterBoxReporter::callback, &reporter, nullptr);
        acutPrintf(L"\nNote: surrogate pairs are kept together. Combining marks and font ligatures may require a shaping engine for true ink bounds.");
#endif
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
