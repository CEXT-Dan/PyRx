#pragma once
#include "PyRxObject.h"

class PyEdInputPointFilter;
class PyEdInputPointMonitor;
class PyEdInputPoint;
class PyEdInputPointFilterResult;
class PyEdInputPointMonitorResult;
class PyGiViewportDraw;
class PyApDocument;

//---------------------------------------------------------------------------------
//PyEdInputPointManager
void makePyEdInputPointManagerWrapper();
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
void makePyEdInputPointFilterWrapper();
class PyEdInputPointFilter : public PyRxObject, public boost::python::wrapper<PyEdInputPointFilter>
{
public:
    PyEdInputPointFilter();
    Acad::ErrorStatus processInputPoint(const PyEdInputPoint& input, PyEdInputPointFilterResult& output);
public:
    PyEdInputPointFilterImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};


//---------------------------------------------------------------------------------
//PyEdInputPointMonitor
void makePyEdInputPointMonitorWrapper();
class PyEdInputPointMonitor : public PyRxObject, public boost::python::wrapper<PyEdInputPointMonitor>
{
public:
    PyEdInputPointMonitor();
    Acad::ErrorStatus monitorInputPoint(const PyEdInputPoint& input, PyEdInputPointMonitorResult& output);

public:
    PyEdInputPointMonitorImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//---------------------------------------------------------------------------------
//PyEdInputPoint
void makePyEdInputPointWrapper();
class PyEdInputPoint
{
public:
    PyEdInputPoint(const AcEdInputPoint& inp);
    PyApDocument        document() const;
    bool                pointComputed() const;
    int                 history() const;
    AcGePoint3d         lastPoint() const;
    AcGePoint3d         rawPoint() const;
    AcGePoint3d         grippedPoint() const;
    AcGePoint3d         cartesianSnappedPoint() const;
    AcGePoint3d         osnappedPoint() const;
    AcDb::OsnapMask     osnapMask() const;
    AcDb::OsnapMask     osnapOverrides() const;
    boost::python::list pickedEntities() const;
    boost::python::list nestedPickedEntities() const;
    boost::python::list gsSelectionMark() const;
    boost::python::list keyPointEntities() const;
    boost::python::list nestedKeyPointEntities() const;
    boost::python::list keyPointGsSelectionMark() const;
    boost::python::list alignmentPaths() const;
    AcGePoint3d         computedPoint() const;
    std::string         tooltipString() const;
    PyGiViewportDraw    drawContext() const;

public:
    const AcEdInputPoint& rpyimp;
};

//---------------------------------------------------------------------------------
//PyEdInputPointFilterResult
void makePyEdInputPointFilterResultWrapper();
class PyEdInputPointFilterResult
{
public:
    PyEdInputPointFilterResult(AcEdInputPointFilterResult& inpr);
    void        setNewPoint(const AcGePoint3d& newValue);
    void        setDisplayOsnapGlyph(bool newValue);
    void        setNewTooltipString(const std::string& newValue);
    void        setRetry(bool newValue);
    AcGePoint3d newPoint() const;
    bool        displayOsnapGlyph() const;
    std::string newTooltipString() const;
    bool        retry() const;

public:
    AcEdInputPointFilterResult& rpyimp;
};

//---------------------------------------------------------------------------------
//PyEdInputPointMonitorResult
void makePyEdInputPointMonitorResultWrapper();
class PyEdInputPointMonitorResult
{
public:
    PyEdInputPointMonitorResult(AcEdInputPointMonitorResult& inpr);
    void        setAdditionalTooltipString(const std::string& newValue);
    bool        appendToTooltipStr() const;
    std::string additionalTooltipString() const;

public:
    AcEdInputPointMonitorResult& rpyimp;
};