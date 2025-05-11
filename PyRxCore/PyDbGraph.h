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
//PyDbObjectIdGraphNode
void makePyDbObjectIdGraphNodeWrapper();

class PyDbObjectIdGraphNode : public PyDbGraphNode
{
public:
    PyDbObjectIdGraphNode(const PyDbObjectId& id);
    PyDbObjectIdGraphNode(const AcDbObjectIdGraphNode* ptr);
    PyDbObjectIdGraphNode(AcDbObjectIdGraphNode* ptr, bool autoDelete);
    virtual ~PyDbObjectIdGraphNode() = default;
    PyDbObjectId id() const;
    static std::string  className();

public:
    AcDbObjectIdGraphNode* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//PyDbXrefGraphNode
void makePyDbXrefGraphNodeWrapper();

class PyDbXrefGraphNode : public PyDbGraphNode
{
public:
    PyDbXrefGraphNode();
    PyDbXrefGraphNode(const AcDbXrefGraphNode* ptr);
    PyDbXrefGraphNode(AcDbXrefGraphNode* ptr, bool autoDelete);
    virtual ~PyDbXrefGraphNode() = default;

    std::string         name() const;
    PyDbObjectId        btrId() const;
    PyDbDatabase        database() const;
    void                setName(const std::string& pName);
    void                setBtrId(const PyDbObjectId& id);
    void                setDatabase(const PyDbDatabase& pDb);
    bool                isNested() const;
    AcDb::XrefStatus    xrefStatus() const;
    void                setXrefStatus(AcDb::XrefStatus stat);
    AcDb::XrefNotificationStatus xrefNotificationStatus() const;
    void                setXrefNotificationStatus(AcDb::XrefNotificationStatus stat);
    Acad::ErrorStatus   xrefReadSubstatus() const;
    static std::string  className();

public:
    AcDbXrefGraphNode* impObj(const std::source_location& src = std::source_location::current()) const;
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