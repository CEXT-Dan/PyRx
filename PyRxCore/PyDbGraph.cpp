#include "stdafx.h"
#include "PyDbGraph.h"

using namespace boost::python;

//-----------------------------------------------------------------------------------------
//PyDbGraphNode
void makePyDbGraphNodeWrapper()
{
    PyDocString DS("GraphNode");
    class_<PyDbGraphNode>("GraphNode", boost::python::no_init)
        .def("className", &PyDbGraphNode::className).staticmethod("className")
        ;

    enum_<AcDbGraphNode::Flags>("GraphNodeFlags")
        .value("kNone", AcDbGraphNode::Flags::kNone)
        .value("kVisited", AcDbGraphNode::Flags::kVisited)
        .value("kOutsideRefed", AcDbGraphNode::Flags::kOutsideRefed)
        .value("kSelected", AcDbGraphNode::Flags::kSelected)
        .value("kInList", AcDbGraphNode::Flags::kInList)
        .value("kListAll", AcDbGraphNode::Flags::kListAll)
        .value("kFirstLevel", AcDbGraphNode::Flags::kFirstLevel)
        .value("kUnresTree", AcDbGraphNode::Flags::kUnresTree)
        .value("kAll", AcDbGraphNode::Flags::kAll)
        .export_values()
        ;
}

PyDbGraphNode::PyDbGraphNode(const AcDbGraphNode* ptr)
    : m_pyImp(const_cast<AcDbGraphNode*>(ptr), PySharedObjectDeleter<AcDbGraphNode>(false))
{
}

PyDbGraphNode::PyDbGraphNode(AcDbGraphNode* ptr, bool autoDelete)
    : m_pyImp(ptr, PySharedObjectDeleter<AcDbGraphNode>(autoDelete))
{
}

std::string PyDbGraphNode::className()
{
    return "GraphNode";
}

AcDbGraphNode* PyDbGraphNode::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return m_pyImp.get();
}

//-----------------------------------------------------------------------------------------
//PyDbGraph
void makePyDbGraphWrapper()
{
    PyDocString DS("Graph");
    class_<PyDbGraph>("Graph", boost::python::no_init)
        .def("className", &PyDbGraph::className).staticmethod("className")
        ;
}

PyDbGraph::PyDbGraph(const AcDbGraph* ptr)
    : m_pyImp(const_cast<AcDbGraph*>(ptr), PySharedObjectDeleter<AcDbGraph>(false))
{
}

PyDbGraph::PyDbGraph(AcDbGraph* ptr, bool autoDelete)
    : m_pyImp(ptr, PySharedObjectDeleter<AcDbGraph>(autoDelete))
{
}

std::string PyDbGraph::className()
{
    return "AcDbGraph";
}

AcDbGraph* PyDbGraph::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return m_pyImp.get();
}
