#pragma once

class  PyApDocManager;

void makeAcApApplictionWrapper();

//-----------------------------------------------------------------------------------------
//PyApApplication  Wrapper
class PyApApplication
{
public:
    PyApDocManager docManager();
    static std::string className();
};

