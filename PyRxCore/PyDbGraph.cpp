#include "stdafx.h"
#include "PyDbGraph.h"

using namespace boost::python;

//-----------------------------------------------------------------------------------------
//PyDbGraphNode
void makePyDbGraphNodeWrapper()
{
    PyDocString DS("GraphNode");
    class_<PyDbGraphNode>("GraphNode", boost::python::no_init)
        .def("numOut", &PyDbGraphNode::numOut, DS.ARGS())
        .def("numIn", &PyDbGraphNode::numIn, DS.ARGS())
        .def("nodeIn", &PyDbGraphNode::nodeIn, DS.ARGS({ "val:int" }))
        .def("nodeOut", &PyDbGraphNode::nodeOut, DS.ARGS({ "val:int" }))
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

PyDbGraphNode PyDbGraphNode::nodeIn(int idx) const
{
    return PyDbGraphNode(impObj()->in(idx), false);
}

PyDbGraphNode PyDbGraphNode::nodeOut(int idx) const
{
    return PyDbGraphNode(impObj()->out(idx), false);
}

void PyDbGraphNode::addRefTo(const PyDbGraphNode& node) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost{};
#else
    PyThrowBadEs(impObj()->addRefTo(node.impObj()));
#endif
}

void PyDbGraphNode::removeRefTo(const PyDbGraphNode& node) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost{};
#else
    PyThrowBadEs(impObj()->removeRefTo(node.impObj()));
#endif
}

void PyDbGraphNode::disconnectAll() const
{
#if defined(_BRXTARGET260)
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
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost{};
#else
    return impObj()->isMarkedAs(flags);
#endif
}

void PyDbGraphNode::markAs(Adesk::UInt8 flags) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost{};
#else
    PyThrowBadEs(impObj()->markAs(flags));
#endif
}

void PyDbGraphNode::clear(Adesk::UInt8 flags) const
{
#if defined(_BRXTARGET260)
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

void PyDbGraphNode::setEdgeGrowthRate(int outEdgeRate, int inEdgeRate) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost{};
#else
    impObj()->setEdgeGrowthRate(outEdgeRate, inEdgeRate);
#endif
}

void PyDbGraphNode::keepAlive() const
{
    auto del_p = std::get_deleter< PySharedObjectDeleter<AcDbGraphNode>>(m_pyImp);
    if (del_p == nullptr)
        PyThrowBadEs(Acad::eNotApplicable);
    del_p->m_autoDelete = false;
}

std::string PyDbGraphNode::className()
{
    return "AcDbGraphNode";
}

AcDbGraphNode* PyDbGraphNode::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return m_pyImp.get();
}

//-----------------------------------------------------------------------------------------
//PyDbObjectIdGraphNode
void makePyDbObjectIdGraphNodeWrapper()
{
    PyDocString DS("ObjectIdGraphNode");
    class_<PyDbObjectIdGraphNode, bases<PyDbGraphNode>>("ObjectIdGraphNode", boost::python::no_init)
        .def(init<const PyDbObjectId&>(DS.ARGS({ "val:PyDb.ObjectId" }, 7060)))
        .def("id", &PyDbObjectIdGraphNode::id, DS.ARGS())
        .def("className", &PyDbObjectIdGraphNode::className).staticmethod("className")
        ;
}

#if defined(_BRXTARGET260)
PyDbObjectIdGraphNode::PyDbObjectIdGraphNode(const PyDbObjectId& id)
    : PyDbObjectIdGraphNode(nullptr, false)
{
    throw PyNotimplementedByHost{};
}
#else
PyDbObjectIdGraphNode::PyDbObjectIdGraphNode(const PyDbObjectId& id)
    : PyDbObjectIdGraphNode(new AcDbObjectIdGraphNode(id.m_id), true)
{
}
#endif

PyDbObjectIdGraphNode::PyDbObjectIdGraphNode(const AcDbObjectIdGraphNode* ptr)
    : PyDbGraphNode(ptr)
{
}

PyDbObjectIdGraphNode::PyDbObjectIdGraphNode(AcDbObjectIdGraphNode* ptr, bool autoDelete)
    : PyDbGraphNode(ptr, autoDelete)
{
}

PyDbObjectId PyDbObjectIdGraphNode::id() const
{
    return PyDbObjectId{ impObj()->id() };
}

std::string PyDbObjectIdGraphNode::className()
{
    return "AcDbObjectIdGraphNode";
}

AcDbObjectIdGraphNode* PyDbObjectIdGraphNode::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbObjectIdGraphNode*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
//PyDbXrefGraphNode
void makePyDbXrefGraphNodeWrapper()
{
    PyDocString DS("XrefGraphNode");
    class_<PyDbXrefGraphNode, bases<PyDbGraphNode>>("XrefGraphNode")
        .def(init<>(DS.ARGS(10375)))
        .def("name", &PyDbXrefGraphNode::name, DS.ARGS())
        .def("btrId", &PyDbXrefGraphNode::btrId, DS.ARGS())
        .def("database", &PyDbXrefGraphNode::database, DS.ARGS())
        .def("setName", &PyDbXrefGraphNode::setName, DS.ARGS({ "val:str" }))
        .def("setBtrId", &PyDbXrefGraphNode::setBtrId, DS.ARGS({ "val:PyDb.ObjectId" }))
        .def("setDatabase", &PyDbXrefGraphNode::setDatabase, DS.ARGS({ "val:PyDb.Database" }))
        .def("isNested", &PyDbXrefGraphNode::isNested, DS.ARGS())
        .def("xrefStatus", &PyDbXrefGraphNode::xrefStatus, DS.ARGS())
        .def("setXrefStatus", &PyDbXrefGraphNode::setXrefStatus, DS.ARGS({ "val:PyDb.XrefStatus" }))
        .def("xrefNotificationStatus", &PyDbXrefGraphNode::xrefNotificationStatus, DS.ARGS())
        .def("setXrefNotificationStatus", &PyDbXrefGraphNode::setXrefNotificationStatus, DS.ARGS({ "val:PyDb.XrefNotificationStatus" }))
        .def("xrefReadSubstatus", &PyDbXrefGraphNode::xrefReadSubstatus, DS.ARGS())
        .def("className", &PyDbXrefGraphNode::className).staticmethod("className")
        ;
}

PyDbXrefGraphNode::PyDbXrefGraphNode()
    : PyDbXrefGraphNode(new AcDbXrefGraphNode(), true)
{
}

PyDbXrefGraphNode::PyDbXrefGraphNode(const AcDbXrefGraphNode* ptr)
    : PyDbGraphNode(ptr)
{
}

PyDbXrefGraphNode::PyDbXrefGraphNode(AcDbXrefGraphNode* ptr, bool autoDelete)
    : PyDbGraphNode(ptr, autoDelete)
{
}

std::string PyDbXrefGraphNode::name() const
{
    return wstr_to_utf8(impObj()->name());
}

PyDbObjectId PyDbXrefGraphNode::btrId() const
{
    return PyDbObjectId{ impObj()->btrId() };
}

PyDbDatabase PyDbXrefGraphNode::database() const
{
    return PyDbDatabase{ impObj()->database() };
}

void PyDbXrefGraphNode::setName(const std::string& pName) const
{
    PyThrowBadEs(impObj()->setName(utf8_to_wstr(pName).c_str()));
}

void PyDbXrefGraphNode::setBtrId(const PyDbObjectId& id) const
{
    impObj()->setBtrId(id.m_id);
}

void PyDbXrefGraphNode::setDatabase(const PyDbDatabase& pDb) const
{
    impObj()->setDatabase(pDb.impObj());
}

bool PyDbXrefGraphNode::isNested() const
{
    return impObj()->isNested();
}

AcDb::XrefStatus PyDbXrefGraphNode::xrefStatus() const
{
    return impObj()->xrefStatus();
}

void PyDbXrefGraphNode::setXrefStatus(AcDb::XrefStatus stat) const
{
    impObj()->setXrefStatus(stat);
}

AcDb::XrefNotificationStatus PyDbXrefGraphNode::xrefNotificationStatus() const
{
    return impObj()->xrefNotificationStatus();
}

void PyDbXrefGraphNode::setXrefNotificationStatus(AcDb::XrefNotificationStatus stat) const
{
    impObj()->setXrefNotificationStatus(stat);
}

Acad::ErrorStatus PyDbXrefGraphNode::xrefReadSubstatus() const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost{};
#else
    return impObj()->xrefReadSubstatus();
#endif
}

std::string PyDbXrefGraphNode::className()
{
    return "AcDbXrefGraphNode";
}

AcDbXrefGraphNode* PyDbXrefGraphNode::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbXrefGraphNode*>(m_pyImp.get());
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
        .def("addEdge", &PyDbGraph::addEdge, DS.ARGS({ "pfrom:PyDb.GraphNode","pto:PyDb.GraphNode" }))
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

void PyDbGraph::addNode(const PyDbGraphNode& node) const
{
    PyThrowBadEs(impObj()->addNode(node.impObj()));
    node.keepAlive();
}

void PyDbGraph::addEdge(const PyDbGraphNode& pfrom, const PyDbGraphNode& pto) const
{
    PyThrowBadEs(impObj()->addEdge(pfrom.impObj(), pto.impObj()));
}

void PyDbGraph::delNode(const PyDbGraphNode& node) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost{};
#else
    PyThrowBadEs(impObj()->delNode(node.impObj()));
    node.keepAlive();
#endif
}

void PyDbGraph::reset() const
{
    impObj()->reset();
}

void PyDbGraph::clearAll(Adesk::UInt8 flags) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost{};
#else
    impObj()->clearAll(flags);
#endif
}

bool PyDbGraph::findCycles(const PyDbGraphNode& start) const
{
    return impObj()->findCycles(start.impObj());
}

void PyDbGraph::breakCycleEdge(const PyDbGraphNode& pfrom, const PyDbGraphNode& pto) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost{};
#else
    PyThrowBadEs(impObj()->breakCycleEdge(pfrom.impObj(), pto.impObj()));
#endif
}

void PyDbGraph::setNodeGrowthRate(int rate) const
{
#if defined(_BRXTARGET260)
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

//-----------------------------------------------------------------------------------------
//PyObjectIdGraph
void makePyObjectIdGraphWrapper()
{
    PyDocString DS("ObjectIdGraph");
    class_<PyObjectIdGraph, bases<PyDbGraph>>("ObjectIdGraph")
        .def(init<>(DS.ARGS(7059)))
        .def("addNode", &PyObjectIdGraph::addNode, DS.ARGS({ "val:PyDb.ObjectIdGraphNode" }))
        .def("delNode", &PyObjectIdGraph::delNode, DS.ARGS({ "val:PyDb.ObjectIdGraphNode" }))
        .def("findNode", &PyObjectIdGraph::findNode, DS.ARGS({ "val:PyDb.ObjectId" }))
        .def("idNode", &PyObjectIdGraph::idNode, DS.ARGS({ "val:int" }))
        .def("className", &PyObjectIdGraph::className).staticmethod("className")
        ;
}

#if defined(_BRXTARGET260)
PyObjectIdGraph::PyObjectIdGraph()
    : PyObjectIdGraph(nullptr, false)
{
    throw PyNotimplementedByHost{};
}
#else
PyObjectIdGraph::PyObjectIdGraph()
    : PyObjectIdGraph(new AcDbObjectIdGraph(), true)
{
}
#endif

PyObjectIdGraph::PyObjectIdGraph(const AcDbObjectIdGraph* ptr)
    : PyDbGraph(ptr)
{
}

PyObjectIdGraph::PyObjectIdGraph(AcDbObjectIdGraph* ptr, bool autoDelete)
    : PyDbGraph(ptr, autoDelete)
{
}

void PyObjectIdGraph::addNode(const PyDbObjectIdGraphNode& node) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost{};
#else
    PyThrowBadEs(impObj()->addNode(node.impObj()));
    node.keepAlive();
#endif
}

void PyObjectIdGraph::delNode(const PyDbObjectIdGraphNode& node) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost{};
#else
    PyThrowBadEs(impObj()->delNode(node.impObj()));
    node.keepAlive();
#endif
}

PyDbObjectIdGraphNode PyObjectIdGraph::findNode(const PyDbObjectId& id) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost{};
#else
    return PyDbObjectIdGraphNode{ impObj()->findNode(id.m_id), false };
#endif
}

PyDbObjectIdGraphNode PyObjectIdGraph::idNode(int idx) const
{
    return PyDbObjectIdGraphNode{ impObj()->idNode(idx), false };
}

std::string PyObjectIdGraph::className()
{
    return "AcDbObjectIdGraph";
}

AcDbObjectIdGraph* PyObjectIdGraph::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbObjectIdGraph*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
//PyAcDbXrefGraph
void makePyAcDbXrefGraphWrapper()
{
    constexpr const std::string_view xrefNodeOverloads = "Overloads:\n"
        "- val: str\n"
        "- val: int\n"
        "- val: PyDb.ObjectId\n"
        "- val: PyDb.Database\n";

    PyDocString DS("XrefGraph");
    class_<PyDbXrefGraph, bases<PyDbGraph>>("XrefGraph")
        .def(init<>(DS.ARGS(10374)))
        .def("xrefNode", &PyDbXrefGraph::xrefNode1)
        .def("xrefNode", &PyDbXrefGraph::xrefNode2)
        .def("xrefNode", &PyDbXrefGraph::xrefNode3)
        .def("xrefNode", &PyDbXrefGraph::xrefNode4, DS.OVRL(xrefNodeOverloads))
        .def("hostDwg", &PyDbXrefGraph::hostDwg, DS.ARGS())
        .def("markUnresolvedTrees", &PyDbXrefGraph::markUnresolvedTrees, DS.ARGS())
        .def("className", &PyDbXrefGraph::className).staticmethod("className")
        ;
}

PyDbXrefGraph::PyDbXrefGraph()
    : PyDbXrefGraph(new AcDbXrefGraph())
{
}

PyDbXrefGraph::PyDbXrefGraph(const AcDbXrefGraph* ptr)
    : PyDbGraph(ptr)
{
}

PyDbXrefGraph::PyDbXrefGraph(AcDbXrefGraph* ptr, bool autoDelete)
    : PyDbGraph(ptr, autoDelete)
{
}

PyDbXrefGraphNode PyDbXrefGraph::xrefNode1(const std::string& pName) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost{};
#else
    return PyDbXrefGraphNode{ impObj()->xrefNode(utf8_to_wstr(pName).c_str()), false };
#endif
}

PyDbXrefGraphNode PyDbXrefGraph::xrefNode2(const PyDbObjectId& btrId) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost{};
#else
    return PyDbXrefGraphNode{ impObj()->xrefNode(btrId.m_id), false };
#endif
}

PyDbXrefGraphNode PyDbXrefGraph::xrefNode3(const PyDbDatabase& pDb) const
{
    return PyDbXrefGraphNode{ impObj()->xrefNode(pDb.impObj()), false };
}

PyDbXrefGraphNode PyDbXrefGraph::xrefNode4(int idx) const
{
    return PyDbXrefGraphNode{ impObj()->xrefNode(idx), false };
}

PyDbXrefGraphNode PyDbXrefGraph::hostDwg() const
{
    return PyDbXrefGraphNode{ impObj()->hostDwg(), false };
}

Adesk::Boolean PyDbXrefGraph::markUnresolvedTrees() const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost{};
#else
    return impObj()->markUnresolvedTrees();
#endif
}

std::string PyDbXrefGraph::className()
{
    return "AcDbXrefGraph";
}

AcDbXrefGraph* PyDbXrefGraph::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbXrefGraph*>(m_pyImp.get());
}
