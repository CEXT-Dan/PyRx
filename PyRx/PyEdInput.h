#pragma once
#include "PyRxObject.h"

class PyEdInputPointFilter;
class PyEdInputPointMonitor;
class PyEdInputPoint;
class PyEdInputPointFilterResult;
class PyEdInputPointMonitorResult;
//---------------------------------------------------------------------------------
//AcEdInputPointManager
class PyEdInputPointManager
{
public:
    PyEdInputPointManager(AcEdInputPointManager* src);
    virtual ~PyEdInputPointManager();
    void        registerPointFilter(PyEdInputPointFilter& pFilter);
    void        revokePointFilter();
    bool        hasFilter();
    void        addPointMonitor(PyEdInputPointMonitor& pMonitor);
    void        removePointMonitor(PyEdInputPointMonitor& pMonitor);
    bool        disableSystemCursorGraphics();
    bool        enableSystemCursorGraphics();
    int         systemCursorDisableCount() const;
    bool        turnOffForcedPick();
    int         forcedPickCount() const;
    int         mouseHasMoved() const;
    bool        turnOnSubentityWindowSelection();
    bool        turnOffSubentityWindowSelection();
    void        enableMultiSubentPathSelection(bool bEnable);

public:
    AcEdInputPointManager* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    AcEdInputPointManager* m_pyImp = nullptr;
};

//---------------------------------------------------------------------------------
//PyEdInputPointFilterImpl
class PyEdInputPointFilterImpl : public AcEdInputPointFilter
{
public:
    PyEdInputPointFilterImpl(PyEdInputPointFilter* bckPtr);
    virtual Acad::ErrorStatus processInputPoint(const AcEdInputPoint& input, AcEdInputPointFilterResult& output) override;

public:
    PyEdInputPointFilter* backPtr(const std::source_location& src = std::source_location::current()) const;
public:
    PyEdInputPointFilter* m_bckPtr = nullptr;
};

//---------------------------------------------------------------------------------
//PyEdInputPointMonitorImpl
class PyEdInputPointMonitorImpl : public  AcEdInputPointMonitor
{
public:
    PyEdInputPointMonitorImpl(PyEdInputPointMonitor* bckPtr);
    virtual Acad::ErrorStatus monitorInputPoint(const AcEdInputPoint& input, AcEdInputPointMonitorResult& output) override;

public:
    PyEdInputPointMonitor* backPtr(const std::source_location& src = std::source_location::current()) const;
public:
    PyEdInputPointMonitor* m_bckPtr = nullptr;
};

//---------------------------------------------------------------------------------
//PyEdInputPointFilter
class PyEdInputPointFilter : public PyRxObject
{
public:
    PyEdInputPointFilter();
    Acad::ErrorStatus monitorInputPoint(const PyEdInputPoint& input, PyEdInputPointFilterResult& output);
public:
    PyEdInputPointFilterImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};


//---------------------------------------------------------------------------------
//PyEdInputPointMonitor
class PyEdInputPointMonitor : public PyRxObject
{
public:
    PyEdInputPointMonitor();
    Acad::ErrorStatus monitorInputPoint(const PyEdInputPoint& input, PyEdInputPointMonitorResult& output);

public:
    PyEdInputPointMonitorImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//---------------------------------------------------------------------------------
//PyEdInputPoint
class PyEdInputPoint
{
public:
    PyEdInputPoint(const AcEdInputPoint& inp);
    const AcEdInputPoint& rpyimp;
};

//---------------------------------------------------------------------------------
//PyEdInputPointFilterResult
class PyEdInputPointFilterResult
{
public:
    PyEdInputPointFilterResult(AcEdInputPointFilterResult& inpr);


    AcEdInputPointFilterResult& rpyimp;
};

//---------------------------------------------------------------------------------
//PyEdInputPointMonitorResult
class PyEdInputPointMonitorResult
{
public:
    PyEdInputPointMonitorResult(AcEdInputPointMonitorResult& inpr);


    AcEdInputPointMonitorResult& rpyimp;
};