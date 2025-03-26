#include "stdafx.h"
#include "PyRxModule.h"
#include "PyRxApp.h"

AcString PyRxModule::commandForCurDocument()
{
#ifdef _ZRXTARGET260
    //[#204] ID SUP - 79158
    // hack acedCmdS does not set CommandForDocument
    // we attemt to set this in bool EdCore::cmdS
    AcString pGlobalCmdName = PyRxApp::instance().commandForDocOverride;
    PyRxApp::instance().commandForDocOverride.setEmpty();
    if (!pGlobalCmdName.isEmpty())
        return pGlobalCmdName.makeUpper();
#else
    AcString pGlobalCmdName;
#endif
#ifdef _ZRXTARGET240
    RxAutoOutStr cmd;
    if (auto es = acedGetCommandForDocument(curDoc(), cmd.buf); es != eOk)
        return pGlobalCmdName;
    pGlobalCmdName = cmd.buf;
    return pGlobalCmdName.makeUpper();
#else
    if (auto es = acedGetCommandForDocument(curDoc(), pGlobalCmdName); es != eOk)
        return pGlobalCmdName;
    return pGlobalCmdName.makeUpper();
#endif
}

void PyRxModule::callPyFunction()
{
    if (curDoc() == nullptr)
    {
        acutPrintf(_T("\nCommand called with No Document: "));
        return;
    }

    auto& rxApp = PyRxApp::instance();
    const AcString cmdName{ commandForCurDocument() };
    if (!rxApp.commands.contains(cmdName))
    {
        acutPrintf(_T("\nCommand (%ls) not found: "), (const TCHAR*)cmdName);
        return;
    }
    try
    {
        std::unique_ptr<AutoCWD> pAutoCWD;
        if (rxApp.pathForCommand.contains(cmdName))
            pAutoCWD.reset(new AutoCWD(rxApp.pathForCommand.at(cmdName)));

        PyObject* pMethod = rxApp.commands.at(cmdName);
        if (pMethod == nullptr)
        {
            acutPrintf(_T("\nCommand (%ls) is NULL: "), (const TCHAR*)cmdName);
            return;
        }

        PyAutoLockGIL lock;
        if (!PyCallable_Check(pMethod))
        {
            acutPrintf(_T("\nPyCallable_Check failed: "));
            return;
        }

        PyErr_Clear();
        PyObjectPtr rslt(PyObject_CallNoArgs(pMethod));
        if (rslt != nullptr)
            return;
        else
            acutPrintf(_T("\nPyCallable_Check failed: "));

    }
    catch (...)
    {
        acutPrintf(_T("\npyfunc failed with exception: "));
    }

    acutPrintf(_T("\npyfunc failed: "));
    {
        PyAutoLockGIL lock;
        PyErr_Clear();
    }
}

void PyRxModule::regCommand(const AcString& moduleName, const AcString& name, int context)
{
#ifdef PYRXDEBUG_FULL
    acutPrintf(_T("\nregCommand = %ls"), (LPCTSTR)name);
#endif
    if (auto es = acedRegCmds->addCommand(moduleName, name, name, context, callPyFunction); es != eOk)
    {
        if (es == Acad::eDuplicateKey)
            return;
        acutPrintf(_T("\naddCommand failed %ls , %ls: "), acadErrorStatusText(es), static_cast<const wchar_t*>(name));
    }
}


