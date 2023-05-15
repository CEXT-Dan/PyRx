#pragma once
class PyCmd
{
public:
    static int getCommandFlags(AcString& str);
    static int getCommandFlags(PyObject* pCommand);
};

