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

PyDbGraphNode PyDbGraph::node(int index) const
{
    return PyDbGraphNode(impObj()->node(index), false);
}

PyDbGraphNode PyDbGraph::rootNode() const
{
    return PyDbGraphNode(impObj()->rootNode(), false);
}

int PyDbGraph::numNodes() const
{
    return impObj()->numNodes();
}

bool PyDbGraph::isEmpty() const
{
    return impObj()->isEmpty();
}

void PyDbGraph::addNode(const PyDbGraphNode& node)
{
    PyThrowBadEs(impObj()->addNode(node.impObj()));
}

void PyDbGraph::addEdge(const PyDbGraphNode& pfrom, const PyDbGraphNode& pto)
{
    PyThrowBadEs(impObj()->addEdge(pfrom.impObj(), pto.impObj()));
}

void PyDbGraph::delNode(const PyDbGraphNode& node)
{
    PyThrowBadEs(impObj()->delNode(node.impObj()));
    auto del_p = std::get_deleter< PySharedObjectDeleter<AcDbGraphNode>>(m_pyImp);
    if (del_p == nullptr)
        PyThrowBadEs(Acad::eNotApplicable);
    del_p->m_autoDelete = false;
}

void PyDbGraph::reset()
{
    impObj()->reset();
}

void PyDbGraph::clearAll(Adesk::UInt8 flags)
{
    impObj()->clearAll(flags);
}

bool PyDbGraph::findCycles(const PyDbGraphNode& start)
{
    return impObj()->findCycles(start.impObj());
}

void PyDbGraph::breakCycleEdge(const PyDbGraphNode& pfrom, const PyDbGraphNode& pto)
{
    PyThrowBadEs(impObj()->breakCycleEdge(pfrom.impObj(), pto.impObj()));
}

void PyDbGraph::setNodeGrowthRate(int rate)
{
    impObj()->setNodeGrowthRate(rate);
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
