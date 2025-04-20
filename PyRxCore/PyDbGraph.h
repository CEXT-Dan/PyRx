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

    static std::string  className();
public:
    AcDbGraph* impObj(const std::source_location& src = std::source_location::current()) const;

public:
    std::shared_ptr<AcDbGraph> m_pyImp;
};