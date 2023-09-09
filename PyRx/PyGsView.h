#pragma once

//-----------------------------------------------------------------------------------------
//PyGsView
void makePyGsViewWrapper();

class PyGsView
{
public:
    PyGsView(AcGsView* impl);
    ~PyGsView() = default;

    static std::string className();
public:
    AcGsView* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    AcGsView* m_pyImp = nullptr;
};

