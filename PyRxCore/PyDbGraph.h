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
    void                keepAlive() const;

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

//-----------------------------------------------------------------------------------------
//PyObjectIdGraph
void makePyObjectIdGraphWrapper();

class PyObjectIdGraph : public PyDbGraph
{
public:
    PyObjectIdGraph();
    PyObjectIdGraph(const AcDbObjectIdGraph* ptr);
    PyObjectIdGraph(AcDbObjectIdGraph* ptr, bool autoDelete);
    virtual ~PyObjectIdGraph() = default;
    void                    addNode(const PyDbObjectIdGraphNode& node);
    void                    delNode(const PyDbObjectIdGraphNode& node);
    PyDbObjectIdGraphNode   findNode(const PyDbObjectId& id) const;
    PyDbObjectIdGraphNode   idNode(int idx) const;
    static std::string      className();
public:
    AcDbObjectIdGraph* impObj(const std::source_location& src = std::source_location::current()) const;
};


//-----------------------------------------------------------------------------------------
//PyAcDbXrefGraph
void makePyAcDbXrefGraphWrapper();

class PyDbXrefGraph : public PyDbGraph
{
public:
    PyDbXrefGraph();
    PyDbXrefGraph(const AcDbXrefGraph* ptr);
    PyDbXrefGraph(AcDbXrefGraph* ptr, bool autoDelete);
    virtual ~PyDbXrefGraph() = default;

    PyDbXrefGraphNode   xrefNode1(const std::string& pName) const;
    PyDbXrefGraphNode   xrefNode2(const PyDbObjectId& btrId) const;
    PyDbXrefGraphNode   xrefNode3(const PyDbDatabase& pDb) const;
    PyDbXrefGraphNode   xrefNode4(int idx) const;
    PyDbXrefGraphNode   hostDwg() const;
    Adesk::Boolean      markUnresolvedTrees();
    static std::string  className();
public:
    AcDbXrefGraph* impObj(const std::source_location& src = std::source_location::current()) const;

};