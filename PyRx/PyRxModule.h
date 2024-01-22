#pragma once

class PyRxModule
{
public:
    static AcString commandForCurDocument();
    static void callPyFunction();
    static void regCommand(const AcString& moduleName, const AcString& name, int context);
};

