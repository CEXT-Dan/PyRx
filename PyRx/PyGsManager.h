#pragma once

//-----------------------------------------------------------------------------------------
//PyGsManager
void makePyGsManagerWrapper();

class PyGsManager
{
public:
    PyGsManager();
    static void testfunc(int val, int val2);
    static std::string	className();
public:
    AcGsManager* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    AcGsManager* m_pyImp = nullptr;
};
