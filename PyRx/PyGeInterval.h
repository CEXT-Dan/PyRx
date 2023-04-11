#pragma once

//-------------------------------------------------------------------------------------------------------
//PyGeInterval
void makePyGeIntervalWrapper();

class PyGeInterval
{
public:
    PyGeInterval();
    PyGeInterval(const AcGeInterval& src);
    static std::string className();
public:
    AcGeInterval imp;
};

