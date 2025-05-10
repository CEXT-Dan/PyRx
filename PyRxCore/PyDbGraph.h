#pragma once

class PyDbGraph;

//-----------------------------------------------------------------------------------------
//PyDbGraphNode
void makePyDbGraphNodeWrapper();

class PyDbGraphNode
{
public:
    PyDbGraphNode(const AcDbGraphNode* ptr);
    PyDbGraphNode(AcDbGraphNode* ptr, bool autoDelete);
    virtual ~PyDbGraphNode() = default;

    int                 numOut() const;
    int                 numIn() const;
    PyDbGraphNode       nodeIn(int idx) const;
    PyDbGraphNode       nodeOut(int idx) const;
    void                addRefTo(const PyDbGraphNode& node);
    void                removeRefTo(const PyDbGraphNode& node);
    void                disconnectAll();
    PyDbGraph           owner() const;
    bool                isMarkedAs(Adesk::UInt8 flags) const;
    void                markAs(Adesk::UInt8 flags);
    void                clear(Adesk::UInt8 flags);
    int                 numCycleOut() const;
    int                 numCycleIn() const;
    PyDbGraphNode       cycleIn(int) const;
    PyDbGraphNode       cycleOut(int) const;
    PyDbGraphNode       nextCycleNode() const;
    bool                isCycleNode() const;
    void                setEdgeGrowthRate(int outEdgeRate, int inEdgeRate);

    static std::string  className();
public:
    AcDbGraphNode* impObj(const std::source_location& src = std::source_location::current()) const;

public:
    std::shared_ptr<AcDbGraphNode> m_pyImp;
};

//-----------------------------------------------------------------------------------------
//PyDbGraph
void makePyDbGraphWrapper();

class PyDbGraph
{
public:
    PyDbGraph(const AcDbGraph* ptr);
    PyDbGraph(AcDbGraph* ptr, bool autoDelete);
    virtual ~PyDbGraph() = default;

    PyDbGraphNode   node(int index) const;
    PyDbGraphNode   rootNode() const;
    int             numNodes() const;
    bool            isEmpty() const;
    void            addNode(const PyDbGraphNode& node);
    void            addEdge(const PyDbGraphNode& pfrom, const PyDbGraphNode& pto);
    void            delNode(const PyDbGraphNode& node);
    void            reset();
    void            clearAll(Adesk::UInt8 flags);
    bool            findCycles(const PyDbGraphNode& start);
    void            breakCycleEdge(const PyDbGraphNode& pfrom, const PyDbGraphNode& pto);
    void            setNodeGrowthRate(int rate);
    static std::string  className();
public:
    AcDbGraph* impObj(const std::source_location& src = std::source_location::current()) const;

public:
    std::shared_ptr<AcDbGraph> m_pyImp;
};