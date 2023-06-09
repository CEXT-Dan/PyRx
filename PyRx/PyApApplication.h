#pragma once

class  PyApDocManager;

void makeAcApApplictionWrapper();

//-----------------------------------------------------------------------------------------
//PyApApplication  Wrapper
class PyApApplication
{
public:
    PyApDocManager docManager();
public:
    static int64_t mainWnd();
    static std::string className();
};

//-----------------------------------------------------------------------------------------
//PyApApplication  Wrapper
void makePyApResourceOverrideWrapper();

class PyApResourceOverride
{
public:
    PyApResourceOverride() = default;
    ~PyApResourceOverride() = default;
    static std::string className();
public:
    CAcModuleResourceOverride myResources;
};

