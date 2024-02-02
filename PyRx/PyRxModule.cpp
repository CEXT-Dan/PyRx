#include "stdafx.h"
#include "PyRxModule.h"
#include "PyRxApp.h"

AcString PyRxModule::commandForCurDocument()
{
#ifdef _ZRXTARGET240
    RxAutoOutStr cmd;
    AcString pGlobalCmdName;
    if (auto es = acedGetCommandForDocument(curDoc(), cmd.buf); es != eOk)
        return pGlobalCmdName;
    pGlobalCmdName = cmd.buf;
    return pGlobalCmdName.makeUpper();
#else
    AcString pGlobalCmdName;
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
        const AcString cmdName = commandForCurDocument();
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
    acedRegCmds->addCommand(moduleName, name, name, context, callPyFunction);
}


