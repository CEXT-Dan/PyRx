#pragma once
class PyLispService
{
public:
    static int execLispFunc();
    bool tryAddFunc(const AcString& pythonFuncName, PyObject* method);
    void On_kLoadDwgMsg();

    using funcode = int;
    using CmdNameMap = std::map<AcString, funcode>;
    using CmdLispMap = std::map<funcode, PyObject*>;

    CmdNameMap lispFuncs;
    CmdLispMap lispFuncCodes;
};

