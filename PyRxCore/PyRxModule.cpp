#include "stdafx.h"
#include "PyRxModule.h"
#include "PyRxApp.h"

AcString PyRxModule::commandForCurDocument()
{
    AcString pGlobalCmdName;
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
    if (curDoc() != nullptr)
    {
        auto& rxApp = PyRxApp::instance();
        const AcString cmdName{ commandForCurDocument() };
        if (rxApp.commands.contains(cmdName))
        {
            try
            {
                if (rxApp.pathForCommand.contains(cmdName))
                    std::filesystem::current_path(rxApp.pathForCommand.at(cmdName));

                PyObject* pMethod = rxApp.commands.at(cmdName);
                if (pMethod != nullptr)
                {
                    WxPyAutoLock lock;
                    if (PyCallable_Check(pMethod))
                    {
                        PyErr_Clear();
                        PyObjectPtr rslt(PyObject_CallNoArgs(pMethod));
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

void PyRxModule::regCommand(const AcString& moduleName, const AcString& name, int context)
{
    if (auto es = acedRegCmds->addCommand(moduleName, name, name, context, callPyFunction); es != eOk)
        acutPrintf(_T("\naddCommand failed %ls: "), (const TCHAR*)name);
}


