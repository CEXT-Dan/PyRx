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

//-----------------------------------------------------------------------------------------
//PyApApplication  Wrapper
void makeAPyApResourceOverrideWrapper();

class PyApResourceOverride
{
public:
    PyApResourceOverride() = default;
    ~PyApResourceOverride() = default;

    CAcModuleResourceOverride myResources;
};

