#pragma once
#include "PyRxObject.h"

#pragma pack (push, 8)
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
    explicit PyEdInputPointManager(AcEdInputPointManager* src);
    virtual ~PyEdInputPointManager() = default;
    void        registerPointFilter(PyEdInputPointFilter& pFilter) const;
    void        revokePointFilter() const;
    bool        hasFilter() const;
    void        addPointMonitor(PyEdInputPointMonitor& pMonitor) const;
    void        removePointMonitor(PyEdInputPointMonitor& pMonitor) const;
    bool        disableSystemCursorGraphics() const;
    bool        enableSystemCursorGraphics() const;
    int         systemCursorDisableCount() const;
    bool        turnOffForcedPick() const;
    int         forcedPickCount() const;
    int         mouseHasMoved() const;
    bool        turnOnSubentityWindowSelection() const;
    bool        turnOffSubentityWindowSelection() const;
    void        enableMultiSubentPathSelection(bool bEnable) const;

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
    ACRX_DECLARE_MEMBERS(PyEdInputPointFilterImpl);
public:
    PyEdInputPointFilterImpl() = default;
    PyEdInputPointFilterImpl(PyEdInputPointFilter* bckPtr);
    virtual ~PyEdInputPointFilterImpl() override = default;
    virtual Acad::ErrorStatus processInputPoint(const AcEdInputPoint& input, AcEdInputPointFilterResult& output) override;

public:
    PyEdInputPointFilter* backPtr(const std::source_location& src = std::source_location::current()) const;
public:
    PyEdInputPointFilter* m_bckPtr = nullptr;
};
ACDB_REGISTER_OBJECT_ENTRY_AUTO(PyEdInputPointFilterImpl)

//---------------------------------------------------------------------------------
//PyEdInputPointMonitorImpl
class PyEdInputPointMonitorImpl : public  AcEdInputPointMonitor
{
public:
    ACRX_DECLARE_MEMBERS(PyEdInputPointMonitorImpl);
public:
    PyEdInputPointMonitorImpl() = default;
    PyEdInputPointMonitorImpl(PyEdInputPointMonitor* bckPtr);
    virtual ~PyEdInputPointMonitorImpl() override = default;
    virtual Acad::ErrorStatus monitorInputPoint(const AcEdInputPoint& input, AcEdInputPointMonitorResult& output) override;

public:
    PyEdInputPointMonitor* backPtr(const std::source_location& src = std::source_location::current()) const;
public:
    PyEdInputPointMonitor* m_bckPtr = nullptr;
};
ACDB_REGISTER_OBJECT_ENTRY_AUTO(PyEdInputPointMonitorImpl)

//---------------------------------------------------------------------------------
//PyEdInputPointFilter
void makePyEdInputPointFilterWrapper();
class PyEdInputPointFilter : public PyRxObject, public boost::python::wrapper<PyEdInputPointFilter>
{
public:
    PyEdInputPointFilter();
    virtual ~PyEdInputPointFilter() override = default;
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
    virtual ~PyEdInputPointMonitor() override = default;
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
    explicit PyEdInputPoint(const AcEdInputPoint& inp);
    ~PyEdInputPoint() = default;
    PyApDocument        document() const;
    bool                pointComputed() const;
    Acad::PointHistory  history() const;
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
    explicit PyEdInputPointFilterResult(AcEdInputPointFilterResult& inpr);
    ~PyEdInputPointFilterResult() = default;
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
    explicit PyEdInputPointMonitorResult(AcEdInputPointMonitorResult& inpr);
    ~PyEdInputPointMonitorResult() = default;
    void        setAdditionalTooltipString(const std::string& newValue);
    bool        appendToTooltipStr() const;
    std::string additionalTooltipString() const;

public:
    AcEdInputPointMonitorResult& rpyimp;
};
#pragma pack (pop)
