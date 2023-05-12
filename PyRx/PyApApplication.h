#pragma once

class  PyApDocManager;

void makeAcApApplictionWrapper();

//-----------------------------------------------------------------------------------------
//PyApApplication  Wrapper
class PyApApplication
{
public:
    PyApDocManager docManager();

    static int64_t mainWnd();
    static std::string className();
};

