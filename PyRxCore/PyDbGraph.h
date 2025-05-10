#pragma once

//-----------------------------------------------------------------------------------------
//PyDbGraphNode
void makePyDbGraphNodeWrapper();

class PyDbGraphNode
{
public:
    PyDbGraphNode(const AcDbGraphNode* ptr);
    PyDbGraphNode(AcDbGraphNode* ptr, bool autoDelete);
    virtual ~PyDbGraphNode() = default;

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