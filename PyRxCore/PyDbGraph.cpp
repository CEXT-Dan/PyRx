#include "stdafx.h"
#include "PyDbGraph.h"

using namespace boost::python;

//-----------------------------------------------------------------------------------------
//PyDbGraphNode
void makePyDbGraphNodeWrapper()
{
    PyDocString DS("GraphNode");
    class_<PyDbGraphNode>("GraphNode", boost::python::no_init)
        .def("numOut", &PyDbGraphNode::numOut,DS.ARGS())
        .def("numIn", &PyDbGraphNode::numIn, DS.ARGS())
        .def("in", &PyDbGraphNode::in, DS.ARGS({ "val:int" }))
        .def("out", &PyDbGraphNode::out, DS.ARGS({ "val:int" }))
        .def("addRefTo", &PyDbGraphNode::addRefTo, DS.ARGS({ "val:PyDb.GraphNode" }))
        .def("removeRefTo", &PyDbGraphNode::removeRefTo, DS.ARGS({ "val:PyDb.GraphNode" }))
        .def("disconnectAll", &PyDbGraphNode::disconnectAll, DS.ARGS())
        .def("owner", &PyDbGraphNode::owner, DS.ARGS())
        .def("isMarkedAs", &PyDbGraphNode::isMarkedAs, DS.ARGS({ "val:int" }))
        .def("markAs", &PyDbGraphNode::markAs, DS.ARGS({ "val:int" }))
        .def("clear", &PyDbGraphNode::clear, DS.ARGS({ "val:int" }))
        .def("numCycleOut", &PyDbGraphNode::numCycleOut, DS.ARGS())
        .def("numCycleIn", &PyDbGraphNode::numCycleIn, DS.ARGS())
        .def("cycleIn", &PyDbGraphNode::cycleIn, DS.ARGS({ "val:int" }))
        .def("cycleOut", &PyDbGraphNode::cycleOut, DS.ARGS({ "val:int" }))
        .def("nextCycleNode", &PyDbGraphNode::nextCycleNode, DS.ARGS())
        .def("isCycleNode", &PyDbGraphNode::isCycleNode, DS.ARGS({ "val:int" }))
        .def("setEdgeGrowthRate", &PyDbGraphNode::setEdgeGrowthRate, DS.ARGS({ "outEdgeRate:int","inEdgeRate:int" }))
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

int PyDbGraphNode::numOut() const
{
    return impObj()->numOut();
}

int PyDbGraphNode::numIn() const
{
    return impObj()->numIn();
}

PyDbGraphNode PyDbGraphNode::in(int idx) const
{
    return PyDbGraphNode(impObj()->in(idx), false);
}

PyDbGraphNode PyDbGraphNode::out(int idx) const
{
    return PyDbGraphNode(impObj()->out(idx), false);
}

void PyDbGraphNode::addRefTo(const PyDbGraphNode& node)
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost{};
#else
    PyThrowBadEs(impObj()->addRefTo(node.impObj()));
#endif
}

void PyDbGraphNode::removeRefTo(const PyDbGraphNode& node)
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost{};
#else
    PyThrowBadEs(impObj()->removeRefTo(node.impObj()));
#endif
}

void PyDbGraphNode::disconnectAll()
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost{};
#else
    impObj()->disconnectAll();
#endif
}

PyDbGraph PyDbGraphNode::owner() const
{
    return PyDbGraph{ impObj()->owner(), false };
}

bool PyDbGraphNode::isMarkedAs(Adesk::UInt8 flags) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost{};
#else
    return impObj()->isMarkedAs(flags);
#endif
}

void PyDbGraphNode::markAs(Adesk::UInt8 flags)
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost{};
#else
    PyThrowBadEs(impObj()->markAs(flags));
#endif
}

void PyDbGraphNode::clear(Adesk::UInt8 flags)
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost{};
#else
    PyThrowBadEs(impObj()->clear(flags));
#endif
}

int PyDbGraphNode::numCycleOut() const
{
    return impObj()->numCycleOut();
}

int PyDbGraphNode::numCycleIn() const
{
    return impObj()->numCycleIn();
}

PyDbGraphNode PyDbGraphNode::cycleIn(int idx) const
{
    return PyDbGraphNode{ impObj()->cycleIn(idx),false };
}

PyDbGraphNode PyDbGraphNode::cycleOut(int idx) const
{
    return PyDbGraphNode{ impObj()->cycleOut(idx),false };
}

PyDbGraphNode PyDbGraphNode::nextCycleNode() const
{
    return PyDbGraphNode{ impObj()->nextCycleNode(),false };
}

bool PyDbGraphNode::isCycleNode() const
{
    return impObj()->isCycleNode();
}

void PyDbGraphNode::setEdgeGrowthRate(int outEdgeRate, int inEdgeRate)
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost{};
#else
    impObj()->setEdgeGrowthRate(outEdgeRate, inEdgeRate);
#endif
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
        .def("node", &PyDbGraph::node, DS.ARGS({ "val:int" }))
        .def("rootNode", &PyDbGraph::rootNode, DS.ARGS())
        .def("numNodes", &PyDbGraph::numNodes, DS.ARGS())
        .def("isEmpty", &PyDbGraph::isEmpty, DS.ARGS())
        .def("addNode", &PyDbGraph::addNode, DS.ARGS({ "val:PyDb.GraphNode" }))
        .def("addEdge", &PyDbGraph::addEdge, DS.ARGS({ "pfrom:PyDb.GraphNode","pto:PyDb.GraphNode"  }))
        .def("delNode", &PyDbGraph::delNode, DS.ARGS({ "val:PyDb.GraphNode" }))
        .def("reset", &PyDbGraph::reset, DS.ARGS())
        .def("clearAll", &PyDbGraph::clearAll, DS.ARGS({ "flags:int" }))
        .def("findCycles", &PyDbGraph::findCycles, DS.ARGS({ "start:PyDb.GraphNode" }))
        .def("breakCycleEdge", &PyDbGraph::breakCycleEdge, DS.ARGS({ "pfrom:PyDb.GraphNode","pto:PyDb.GraphNode" }))
        .def("setNodeGrowthRate", &PyDbGraph::setNodeGrowthRate, DS.ARGS({ "val:int" }))
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
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost{};
#else
    PyThrowBadEs(impObj()->delNode(node.impObj()));
    auto del_p = std::get_deleter< PySharedObjectDeleter<AcDbGraphNode>>(m_pyImp);
    if (del_p == nullptr)
        PyThrowBadEs(Acad::eNotApplicable);
    del_p->m_autoDelete = false;
#endif
}

void PyDbGraph::reset()
{
    impObj()->reset();
}

void PyDbGraph::clearAll(Adesk::UInt8 flags)
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost{};
#else
    impObj()->clearAll(flags);
#endif
}

bool PyDbGraph::findCycles(const PyDbGraphNode& start)
{
    return impObj()->findCycles(start.impObj());
}

void PyDbGraph::breakCycleEdge(const PyDbGraphNode& pfrom, const PyDbGraphNode& pto)
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost{};
#else
    PyThrowBadEs(impObj()->breakCycleEdge(pfrom.impObj(), pto.impObj()));
#endif
}

void PyDbGraph::setNodeGrowthRate(int rate)
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost{};
#else
    impObj()->setNodeGrowthRate(rate);
#endif
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
