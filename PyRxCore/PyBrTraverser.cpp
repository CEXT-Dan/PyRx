#include "stdafx.h"
#include "PyBrTraverser.h"
#include "PyBrEntity.h"
#include "PyGeCurve2d.h"
#include "PyGeCurve3d.h"

using namespace boost::python;

//-----------------------------------------------------------------------------------------
// PyBrTraverser
void makePyBrTraverserWrapper()
{
    PyDocString DS("Traverser");
    class_<PyBrTraverser, bases<PyRxObject>>("Traverser", no_init)
        .def("isEqualTo", &PyBrTraverser::isEqualTo, DS.ARGS({ "otherObject: PyRx.RxObject" }))
        .def("isNull", &PyBrTraverser::isNull, DS.ARGS())
        .def("done", &PyBrTraverser::done, DS.ARGS())
        .def("next", &PyBrTraverser::next, DS.ARGS())
        .def("restart", &PyBrTraverser::restart, DS.ARGS())
        .def("getValidationLevel", &PyBrTraverser::getValidationLevel, DS.ARGS())
        .def("setValidationLevel", &PyBrTraverser::setValidationLevel, DS.ARGS({ "val: PyBr.ValidationLevel" }))
        .def("brepChanged", &PyBrTraverser::brepChanged, DS.ARGS())
        .def("className", &PyBrTraverser::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrTraverser::desc, DS.SARGS(15560)).staticmethod("desc")
        ;
}

PyBrTraverser::PyBrTraverser(const AcRxObject* ptr)
    :PyRxObject(ptr)
{
}

PyBrTraverser::PyBrTraverser(AcRxObject* ptr, bool autoDelete)
    :PyRxObject(ptr, autoDelete, false)
{
}

Adesk::Boolean PyBrTraverser::isEqualTo(const PyRxObject& other) const
{
    return impObj()->isEqualTo(other.impObj());
}

Adesk::Boolean PyBrTraverser::isNull() const
{
    return impObj()->isNull();
}

bool PyBrTraverser::done() const
{
    return impObj()->done();
}

void PyBrTraverser::next() const
{
    PyThrowBadBr(impObj()->next());
}

void PyBrTraverser::restart() const
{
    PyThrowBadBr(impObj()->restart());
}

void PyBrTraverser::setValidationLevel(const AcBr::ValidationLevel& validationLevel) const
{
    PyThrowBadBr(impObj()->setValidationLevel(validationLevel));
}

AcBr::ValidationLevel PyBrTraverser::getValidationLevel() const
{
    AcBr::ValidationLevel val;
    PyThrowBadBr(impObj()->getValidationLevel(val));
    return val;
}

Adesk::Boolean PyBrTraverser::brepChanged() const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    return impObj()->brepChanged();
#endif
}

PyRxClass PyBrTraverser::desc()
{
    return PyRxClass(AcBrTraverser::desc(), false);
}

std::string  PyBrTraverser::className()
{
    return std::string{ "AcBrTraverser" };
}

AcBrTraverser* PyBrTraverser::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcBrTraverser*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
// PyBrepComplexTraverser
void makePyBrepComplexTraverserWrapper()
{
    PyDocString DS("ComplexTraverser");
    class_<PyBrepComplexTraverser, bases<PyBrTraverser>>("ComplexTraverser")
        .def(init<>())
        .def(init<const PyBrBrep&>(DS.ARGS({ "val: PyBr.Brep = ..." })))
        .def("setBrepAndComplex", &PyBrepComplexTraverser::setBrepAndComplex, DS.ARGS({ "val: PyBr.Complex" }))
        .def("setBrep", &PyBrepComplexTraverser::setBrep, DS.ARGS({ "val: PyBr.Brep" }))
        .def("getBrep", &PyBrepComplexTraverser::getBrep, DS.ARGS())
        .def("getComplex", &PyBrepComplexTraverser::getComplex, DS.ARGS())
        .def("getComplexs", &PyBrepComplexTraverser::getComplexs, DS.ARGS())
        .def("setComplex", &PyBrepComplexTraverser::setComplex, DS.ARGS({ "val: PyBr.Complex" }))
        .def("className", &PyBrepComplexTraverser::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrepComplexTraverser::desc, DS.SARGS(15560)).staticmethod("desc")
        ;
}

PyBrepComplexTraverser::PyBrepComplexTraverser()
    :PyBrepComplexTraverser(new AcBrBrepComplexTraverser(), true)
{
}

PyBrepComplexTraverser::PyBrepComplexTraverser(const AcBrBrepComplexTraverser& src)
    :PyBrepComplexTraverser(new AcBrBrepComplexTraverser(src), true)
{
}

PyBrepComplexTraverser::PyBrepComplexTraverser(const PyBrBrep& brep)
    :PyBrepComplexTraverser(new AcBrBrepComplexTraverser(), true)
{
    setBrep(brep);
}

PyBrepComplexTraverser::PyBrepComplexTraverser(const AcRxObject* ptr)
    :PyBrTraverser(ptr)
{
}

PyBrepComplexTraverser::PyBrepComplexTraverser(AcRxObject* ptr, bool autoDelete)
    :PyBrTraverser(ptr, autoDelete)
{
}

void PyBrepComplexTraverser::setBrepAndComplex(const PyBrComplex& complex) const
{
    PyThrowBadBr(impObj()->setBrepAndComplex(*complex.impObj()));
}

void PyBrepComplexTraverser::setBrep(const PyBrBrep& brep) const
{
    PyThrowBadBr(impObj()->setBrep(*brep.impObj()));
}

PyBrBrep PyBrepComplexTraverser::getBrep() const
{
    AcBrBrep val;
    PyThrowBadBr(impObj()->getBrep(val));
    return PyBrBrep{ val };
}

void PyBrepComplexTraverser::setComplex(const PyBrComplex& complex) const
{
    PyThrowBadBr(impObj()->setComplex(*complex.impObj()));
}

PyBrComplex PyBrepComplexTraverser::getComplex() const
{
    AcBrComplex val;
    PyThrowBadBr(impObj()->getComplex(val));
    return PyBrComplex{ val };
}

boost::python::list PyBrepComplexTraverser::getComplexs()
{
    PyAutoLockGIL lock;
    boost::python::list pylist;
    for (restart(); !done(); next())
        pylist.append(getComplex());
    return pylist;
}

PyRxClass PyBrepComplexTraverser::desc()
{
    return PyRxClass(AcBrBrepComplexTraverser::desc(), false);
}

std::string  PyBrepComplexTraverser::className()
{
    return std::string{ "AcBrBrepComplexTraverser" };
}

AcBrBrepComplexTraverser* PyBrepComplexTraverser::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcBrBrepComplexTraverser*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
// PyBrepEdgeTraverser
void makePyBrepEdgeTraverserWrapper()
{
    PyDocString DS("EdgeTraverser");
    class_<PyBrepEdgeTraverser, bases<PyBrTraverser>>("EdgeTraverser")
        .def(init<>())
        .def(init<const PyBrBrep&>(DS.ARGS({ "val: PyBr.Brep = ..." })))
        .def("setBrepAndEdge", &PyBrepEdgeTraverser::setBrepAndEdge, DS.ARGS({ "val: PyBr.Edge" }))
        .def("setBrep", &PyBrepEdgeTraverser::setBrep, DS.ARGS({ "val: PyBr.Brep" }))
        .def("setEdge", &PyBrepEdgeTraverser::setEdge, DS.ARGS({ "val: PyBr.Edge" }))
        .def("getBrep", &PyBrepEdgeTraverser::getBrep, DS.ARGS())
        .def("getEdge", &PyBrepEdgeTraverser::getEdge, DS.ARGS())
        .def("getEdges", &PyBrepEdgeTraverser::getEdges, DS.ARGS())
        .def("className", &PyBrepEdgeTraverser::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrepEdgeTraverser::desc, DS.SARGS(15560)).staticmethod("desc")
        ;
}

PyBrepEdgeTraverser::PyBrepEdgeTraverser()
    :PyBrepEdgeTraverser(new AcBrBrepEdgeTraverser(), true)
{
}

PyBrepEdgeTraverser::PyBrepEdgeTraverser(const PyBrBrep& brep)
    :PyBrepEdgeTraverser(new AcBrBrepEdgeTraverser(), true)
{
    setBrep(brep);
}

PyBrepEdgeTraverser::PyBrepEdgeTraverser(const AcBrBrepEdgeTraverser& src)
    :PyBrepEdgeTraverser(new AcBrBrepEdgeTraverser(src), true)
{
}

PyBrepEdgeTraverser::PyBrepEdgeTraverser(const AcRxObject* ptr)
    :PyBrTraverser(ptr)
{
}

PyBrepEdgeTraverser::PyBrepEdgeTraverser(AcRxObject* ptr, bool autoDelete)
    :PyBrTraverser(ptr, autoDelete)
{
}

void PyBrepEdgeTraverser::setBrepAndEdge(const PyBrEdge& edge) const
{
    PyThrowBadBr(impObj()->setBrepAndEdge(*edge.impObj()));
}

void PyBrepEdgeTraverser::setBrep(const PyBrBrep& brep) const
{
    PyThrowBadBr(impObj()->setBrep(*brep.impObj()));
}

PyBrBrep PyBrepEdgeTraverser::getBrep() const
{
    AcBrBrep val;
    PyThrowBadBr(impObj()->getBrep(val));
    return PyBrBrep{ val };
}

void PyBrepEdgeTraverser::setEdge(const PyBrEdge& edge) const
{
    PyThrowBadBr(impObj()->setEdge(*edge.impObj()));
}

PyBrEdge PyBrepEdgeTraverser::getEdge() const
{
    AcBrEdge val;
    PyThrowBadBr(impObj()->getEdge(val));
    return PyBrEdge{ val };
}

boost::python::list PyBrepEdgeTraverser::getEdges()
{
    PyAutoLockGIL lock;
    boost::python::list pylist;
    for (restart(); !done(); next())
        pylist.append(getEdge());
    return pylist;
}

PyRxClass PyBrepEdgeTraverser::desc()
{
    return PyRxClass(AcBrBrepEdgeTraverser::desc(), false);
}

std::string  PyBrepEdgeTraverser::className()
{
    return std::string{ "AcBrBrepEdgeTraverser" };
}

AcBrBrepEdgeTraverser* PyBrepEdgeTraverser::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcBrBrepEdgeTraverser*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
// PyBrepFaceTraverser
void makePyBrepFaceTraverserWrapper()
{
    PyDocString DS("FaceTraverser");
    class_<PyBrepFaceTraverser, bases<PyBrTraverser>>("FaceTraverser")
        .def(init<>())
        .def(init<const PyBrBrep&>(DS.ARGS({ "val: PyBr.Brep = ..." })))
        .def("setBrep", &PyBrepFaceTraverser::setBrep, DS.ARGS({ "val: PyBr.Brep" }))
        .def("setFace", &PyBrepFaceTraverser::setFace, DS.ARGS({ "val: PyBr.Face" }))
        .def("getBrep", &PyBrepFaceTraverser::getBrep, DS.ARGS())
        .def("getFace", &PyBrepFaceTraverser::getFace, DS.ARGS())
        .def("getFaces", &PyBrepFaceTraverser::getFaces, DS.ARGS())
        .def("setBrepAndFace", &PyBrepFaceTraverser::setBrepAndFace, DS.ARGS({ "val: PyBr.Face" }))
        .def("className", &PyBrepFaceTraverser::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrepFaceTraverser::desc, DS.SARGS(15560)).staticmethod("desc")
        ;
}

PyBrepFaceTraverser::PyBrepFaceTraverser()
    : PyBrepFaceTraverser(new AcBrBrepFaceTraverser(), true)
{
}

PyBrepFaceTraverser::PyBrepFaceTraverser(const PyBrBrep& brep)
    : PyBrepFaceTraverser(new AcBrBrepFaceTraverser(), true)
{
    setBrep(brep);
}

PyBrepFaceTraverser::PyBrepFaceTraverser(const AcBrBrepFaceTraverser& src)
    : PyBrepFaceTraverser(new AcBrBrepFaceTraverser(src), true)
{
}

PyBrepFaceTraverser::PyBrepFaceTraverser(const AcRxObject* ptr)
    :PyBrTraverser(ptr)
{
}

PyBrepFaceTraverser::PyBrepFaceTraverser(AcRxObject* ptr, bool autoDelete)
    :PyBrTraverser(ptr, autoDelete)
{
}

PyBrBrep PyBrepFaceTraverser::getBrep() const
{
    AcBrBrep val;
    PyThrowBadBr(impObj()->getBrep(val));
    return PyBrBrep{ val };
}

void PyBrepFaceTraverser::setBrep(const PyBrBrep& brep) const
{
    PyThrowBadBr(impObj()->setBrep(*brep.impObj()));
}

PyBrFace PyBrepFaceTraverser::getFace() const
{
    AcBrFace val;
    PyThrowBadBr(impObj()->getFace(val));
    return PyBrFace{ val };
}

void PyBrepFaceTraverser::setFace(const PyBrFace& face) const
{
    PyThrowBadBr(impObj()->setFace(*face.impObj()));
}

void PyBrepFaceTraverser::setBrepAndFace(const PyBrFace& face) const
{
    PyThrowBadBr(impObj()->setFace(*face.impObj()));
}

boost::python::list PyBrepFaceTraverser::getFaces()
{
    PyAutoLockGIL lock;
    boost::python::list pylist;
    for (restart(); !done(); next())
        pylist.append(getFace());
    return pylist;
}

PyRxClass PyBrepFaceTraverser::desc()
{
    return PyRxClass(AcBrBrepFaceTraverser::desc(), false);
}

std::string  PyBrepFaceTraverser::className()
{
    return std::string{ "AcBrBrepFaceTraverser" };
}

AcBrBrepFaceTraverser* PyBrepFaceTraverser::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcBrBrepFaceTraverser*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
// PyBrepShellTraverser
void makePyBrepShellTraverserWrapper()
{
    PyDocString DS("ShellTraverser");
    class_<PyBrepShellTraverser, bases<PyBrTraverser>>("ShellTraverser")
        .def(init<>())
        .def(init<const PyBrBrep&>(DS.ARGS({ "val: PyBr.Brep = ..." })))
        .def("setBrep", &PyBrepShellTraverser::setBrep, DS.ARGS({ "val: PyBr.Brep" }))
        .def("setShell", &PyBrepShellTraverser::setShell, DS.ARGS({ "val: PyBr.Shell" }))
        .def("getBrep", &PyBrepShellTraverser::getBrep, DS.ARGS())
        .def("getShell", &PyBrepShellTraverser::getShell, DS.ARGS())
        .def("getShells", &PyBrepShellTraverser::getShells, DS.ARGS())
        .def("setBrepAndShell", &PyBrepShellTraverser::setBrepAndShell, DS.ARGS({ "val: PyBr.Shell" }))
        .def("className", &PyBrepShellTraverser::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrepShellTraverser::desc, DS.SARGS(15560)).staticmethod("desc")
        ;
}

PyBrepShellTraverser::PyBrepShellTraverser()
    : PyBrepShellTraverser(new AcBrBrepShellTraverser(), true)
{
}

PyBrepShellTraverser::PyBrepShellTraverser(const PyBrBrep& brep)
    : PyBrepShellTraverser(new AcBrBrepShellTraverser(), true)
{
    setBrep(brep);
}

PyBrepShellTraverser::PyBrepShellTraverser(const AcBrBrepShellTraverser& src)
    : PyBrepShellTraverser(new AcBrBrepShellTraverser(src), true)
{
}

PyBrepShellTraverser::PyBrepShellTraverser(const AcRxObject* ptr)
    :PyBrTraverser(ptr)
{
}

PyBrepShellTraverser::PyBrepShellTraverser(AcRxObject* ptr, bool autoDelete)
    :PyBrTraverser(ptr, autoDelete)
{
}

void PyBrepShellTraverser::setBrepAndShell(const PyBrShell& shell) const
{
    PyThrowBadBr(impObj()->setBrepAndShell(*shell.impObj()));
}

void PyBrepShellTraverser::setBrep(const PyBrBrep& brep) const
{
    PyThrowBadBr(impObj()->setBrep(*brep.impObj()));
}

void PyBrepShellTraverser::setShell(const PyBrShell& shell) const
{
    PyThrowBadBr(impObj()->setShell(*shell.impObj()));
}

PyBrBrep PyBrepShellTraverser::getBrep() const
{
    AcBrBrep val;
    PyThrowBadBr(impObj()->getBrep(val));
    return PyBrBrep{ val };
}

PyBrShell PyBrepShellTraverser::getShell() const
{
    AcBrShell val;
    PyThrowBadBr(impObj()->getShell(val));
    return PyBrShell{ val };
}

boost::python::list PyBrepShellTraverser::getShells()
{
    PyAutoLockGIL lock;
    boost::python::list pylist;
    for (restart(); !done(); next())
        pylist.append(getShell());
    return pylist;
}

PyRxClass PyBrepShellTraverser::desc()
{
    return PyRxClass(AcBrBrepShellTraverser::desc(), false);
}

std::string  PyBrepShellTraverser::className()
{
    return std::string{ "AcBrBrepShellTraverser" };
}

AcBrBrepShellTraverser* PyBrepShellTraverser::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcBrBrepShellTraverser*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
// PyBrepVertexTraverser
void makePyBrepVertexTraverserWrapper()
{
    PyDocString DS("VertexTraverser");
    class_<PyBrepVertexTraverser, bases<PyBrTraverser>>("VertexTraverser")
        .def(init<>())
        .def(init<const PyBrBrep&>(DS.ARGS({ "val: PyBr.Brep = ..." })))
        .def("setBrep", &PyBrepVertexTraverser::setBrep, DS.ARGS({ "val: PyBr.Brep" }))
        .def("setVertex", &PyBrepVertexTraverser::setVertex, DS.ARGS({ "val: PyBr.Vertex" }))
        .def("getBrep", &PyBrepVertexTraverser::getBrep, DS.ARGS())
        .def("getVertex", &PyBrepVertexTraverser::getVertex, DS.ARGS())
        .def("getVertexs", &PyBrepVertexTraverser::getVertexs, DS.ARGS())
        .def("setBrepAndVertex", &PyBrepVertexTraverser::setBrepAndVertex, DS.ARGS({ "val: PyBr.Vertex" }))
        .def("className", &PyBrepVertexTraverser::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrepVertexTraverser::desc, DS.SARGS(15560)).staticmethod("desc")
        ;
}

PyBrepVertexTraverser::PyBrepVertexTraverser()
    : PyBrepVertexTraverser(new AcBrBrepVertexTraverser(), true)
{
}

PyBrepVertexTraverser::PyBrepVertexTraverser(const PyBrBrep& brep)
    : PyBrepVertexTraverser(new AcBrBrepVertexTraverser(), true)
{
    setBrep(brep);
}

PyBrepVertexTraverser::PyBrepVertexTraverser(const AcBrBrepVertexTraverser& src)
    : PyBrepVertexTraverser(new AcBrBrepVertexTraverser(src), true)
{
}

PyBrepVertexTraverser::PyBrepVertexTraverser(const AcRxObject* ptr)
    :PyBrTraverser(ptr)
{
}

PyBrepVertexTraverser::PyBrepVertexTraverser(AcRxObject* ptr, bool autoDelete)
    :PyBrTraverser(ptr, autoDelete)
{
}

PyBrBrep PyBrepVertexTraverser::getBrep() const
{
    AcBrBrep val;
    PyThrowBadBr(impObj()->getBrep(val));
    return PyBrBrep{ val };
}

PyBrVertex PyBrepVertexTraverser::getVertex() const
{
    AcBrVertex val;
    PyThrowBadBr(impObj()->getVertex(val));
    return PyBrVertex{ val };
}

boost::python::list PyBrepVertexTraverser::getVertexs()
{
    PyAutoLockGIL lock;
    boost::python::list pylist;
    for (restart(); !done(); next())
        pylist.append(getVertex());
    return pylist;
}

void PyBrepVertexTraverser::setBrepAndVertex(const PyBrVertex& vertex) const
{
    PyThrowBadBr(impObj()->setBrepAndVertex(*vertex.impObj()));
}

void PyBrepVertexTraverser::setBrep(const PyBrBrep& brep) const
{
    PyThrowBadBr(impObj()->setBrep(*brep.impObj()));
}

void PyBrepVertexTraverser::setVertex(const PyBrVertex& vertex) const
{
    PyThrowBadBr(impObj()->setVertex(*vertex.impObj()));
}

PyRxClass PyBrepVertexTraverser::desc()
{
    return PyRxClass(AcBrBrepVertexTraverser::desc(), false);
}

std::string  PyBrepVertexTraverser::className()
{
    return std::string{ "AcBrBrepVertexTraverser" };
}

AcBrBrepVertexTraverser* PyBrepVertexTraverser::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcBrBrepVertexTraverser*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
// PyBrComplexShellTraverser
void makePyBrComplexShellTraverserWrapper()
{
    PyDocString DS("ComplexShellTraverser");
    class_<PyBrComplexShellTraverser, bases<PyBrTraverser>>("ComplexShellTraverser")
        .def(init<>(DS.ARGS()))
        .def("setComplexAndShell", &PyBrComplexShellTraverser::setComplexAndShell, DS.ARGS({ "val: PyBr.Shell" }))
        .def("setComplexTraverser", &PyBrComplexShellTraverser::setComplexTraverser, DS.ARGS({ "val: PyBr.BrepComplexTraverser" }))
        .def("setComplex", &PyBrComplexShellTraverser::setComplex, DS.ARGS({ "val: PyBr.Complex" }))
        .def("getComplex", &PyBrComplexShellTraverser::getComplex, DS.ARGS())
        .def("setShell", &PyBrComplexShellTraverser::setShell, DS.ARGS({ "val: PyBr.Shell" }))
        .def("getShell", &PyBrComplexShellTraverser::getShell, DS.ARGS())
        .def("className", &PyBrComplexShellTraverser::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrComplexShellTraverser::desc, DS.SARGS(15560)).staticmethod("desc")
        ;
}

PyBrComplexShellTraverser::PyBrComplexShellTraverser()
    : PyBrComplexShellTraverser(new AcBrComplexShellTraverser())
{
}

PyBrComplexShellTraverser::PyBrComplexShellTraverser(const AcBrComplexShellTraverser& src)
    : PyBrComplexShellTraverser(new AcBrComplexShellTraverser(src))
{
}

PyBrComplexShellTraverser::PyBrComplexShellTraverser(const AcRxObject* ptr)
    :PyBrTraverser(ptr)
{
}

PyBrComplexShellTraverser::PyBrComplexShellTraverser(AcRxObject* ptr, bool autoDelete)
    :PyBrTraverser(ptr, autoDelete)
{
}

void PyBrComplexShellTraverser::setComplexAndShell(const PyBrShell& shell) const
{
    PyThrowBadBr(impObj()->setComplexAndShell(*shell.impObj()));
}

void PyBrComplexShellTraverser::setComplexTraverser(const PyBrepComplexTraverser& brepcompshell) const
{
    PyThrowBadBr(impObj()->setComplex(*brepcompshell.impObj()));
}

void PyBrComplexShellTraverser::setComplex(const PyBrComplex& complex) const
{
    PyThrowBadBr(impObj()->setComplex(*complex.impObj()));
}

PyBrComplex PyBrComplexShellTraverser::getComplex() const
{
    AcBrComplex complex;
    PyThrowBadBr(impObj()->getComplex(complex));
    return PyBrComplex{ complex };
}

void PyBrComplexShellTraverser::setShell(const PyBrShell& shell) const
{
    PyThrowBadBr(impObj()->setShell(*shell.impObj()));
}

PyBrShell PyBrComplexShellTraverser::getShell() const
{
    AcBrShell shell;
    PyThrowBadBr(impObj()->getShell(shell));
    return PyBrShell{ shell };
}

PyRxClass PyBrComplexShellTraverser::desc()
{
    return PyRxClass(AcBrComplexShellTraverser::desc(), false);
}

std::string  PyBrComplexShellTraverser::className()
{
    return std::string{ "AcBrBrComplexShellTraverser" };
}

AcBrComplexShellTraverser* PyBrComplexShellTraverser::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcBrComplexShellTraverser*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
// PyBrEdgeLoopTraverser
void makePyBrEdgeLoopTraverserWrapper()
{
    PyDocString DS("EdgeLoopTraverser");
    class_<PyBrEdgeLoopTraverser, bases<PyBrTraverser>>("EdgeLoopTraverser")
        .def(init<>(DS.ARGS()))
        .def("getEdge", &PyBrEdgeLoopTraverser::getEdge, DS.ARGS())
        .def("getLoop", &PyBrEdgeLoopTraverser::getLoop, DS.ARGS())
        .def("setEdgeAndLoop", &PyBrEdgeLoopTraverser::setEdgeAndLoop, DS.ARGS({ "val: PyBr.LoopEdgeTraverser" }))
        .def("setVertexAndEdge", &PyBrEdgeLoopTraverser::setVertexAndEdge, DS.ARGS({ "val: PyBr.VertexEdgeTraverser" }))
        .def("setEdge", &PyBrEdgeLoopTraverser::setEdge, DS.ARGS({ "val: PyBr.Edge" }))
        .def("setLoop", &PyBrEdgeLoopTraverser::setLoop, DS.ARGS({ "val: PyBr.Loop" }))
        .def("className", &PyBrEdgeLoopTraverser::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrEdgeLoopTraverser::desc, DS.SARGS(15560)).staticmethod("desc")
        ;
}

PyBrEdgeLoopTraverser::PyBrEdgeLoopTraverser()
    : PyBrEdgeLoopTraverser(new AcBrEdgeLoopTraverser(), true)
{
}

PyBrEdgeLoopTraverser::PyBrEdgeLoopTraverser(const AcBrEdgeLoopTraverser& src)
    : PyBrEdgeLoopTraverser(new AcBrEdgeLoopTraverser(src), true)
{
}

PyBrEdgeLoopTraverser::PyBrEdgeLoopTraverser(const AcRxObject* ptr)
    :PyBrTraverser(ptr)
{
}

PyBrEdgeLoopTraverser::PyBrEdgeLoopTraverser(AcRxObject* ptr, bool autoDelete)
    :PyBrTraverser(ptr, autoDelete)
{
}

PyBrEdge PyBrEdgeLoopTraverser::getEdge() const
{
    AcBrEdge val;
    PyThrowBadBr(impObj()->getEdge(val));
    return PyBrEdge{ val };
}

PyBrLoop PyBrEdgeLoopTraverser::getLoop() const
{
    AcBrLoop val;
    PyThrowBadBr(impObj()->getLoop(val));
    return PyBrLoop{ val };
}

void PyBrEdgeLoopTraverser::setEdgeAndLoop(const PyBrLoopEdgeTraverser& loopEdge) const
{
    PyThrowBadBr(impObj()->setEdgeAndLoop(*loopEdge.impObj()));
}

void PyBrEdgeLoopTraverser::setVertexAndEdge(const PyBrVertexEdgeTraverser& vertexEdge) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    PyThrowBadBr(impObj()->setEdge(*vertexEdge.impObj()));
#endif
}

void PyBrEdgeLoopTraverser::setEdge(const PyBrEdge& edge) const
{
    PyThrowBadBr(impObj()->setEdge(*edge.impObj()));
}

void PyBrEdgeLoopTraverser::setLoop(const PyBrLoop& loop) const
{
    PyThrowBadBr(impObj()->setLoop(*loop.impObj()));
}

PyRxClass PyBrEdgeLoopTraverser::desc()
{
    return PyRxClass(AcBrEdgeLoopTraverser::desc(), false);
}

std::string  PyBrEdgeLoopTraverser::className()
{
    return std::string{ "AcBrEdgeLoopTraverser" };
}

AcBrEdgeLoopTraverser* PyBrEdgeLoopTraverser::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcBrEdgeLoopTraverser*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
// PyBrElement2dNodeTraverser
void makePyBrElement2dNodeTraverserWrapper()
{
    PyDocString DS("Element2dNodeTraverser");
    class_<PyBrElement2dNodeTraverser, bases<PyBrTraverser>>("Element2dNodeTraverser")
        .def(init<>(DS.ARGS()))
        .def("setElementTraverser", &PyBrElement2dNodeTraverser::setElementTraverser, DS.ARGS({ "val: PyBr.Mesh2dElement2dTraverser" }))
        .def("setElement", &PyBrElement2dNodeTraverser::setElement, DS.ARGS({ "val: PyBr.Element2d" }))
        .def("getElement", &PyBrElement2dNodeTraverser::getElement, DS.ARGS())
        .def("setNode", &PyBrElement2dNodeTraverser::setNode, DS.ARGS({ "val: PyBr.Node" }))
        .def("getNode", &PyBrElement2dNodeTraverser::getNode, DS.ARGS())
        .def("getSurfaceNormal", &PyBrElement2dNodeTraverser::getSurfaceNormal, DS.ARGS())
        .def("getParamPoint", &PyBrElement2dNodeTraverser::getParamPoint, DS.ARGS())
        .def("className", &PyBrElement2dNodeTraverser::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrElement2dNodeTraverser::desc, DS.SARGS(15560)).staticmethod("desc")
        ;
}

PyBrElement2dNodeTraverser::PyBrElement2dNodeTraverser()
    :PyBrElement2dNodeTraverser(new AcBrElement2dNodeTraverser(), true)
{
}

PyBrElement2dNodeTraverser::PyBrElement2dNodeTraverser(const AcBrElement2dNodeTraverser& src)
    :PyBrElement2dNodeTraverser(new AcBrElement2dNodeTraverser(src), true)
{
}

PyBrElement2dNodeTraverser::PyBrElement2dNodeTraverser(const AcRxObject* ptr)
    :PyBrTraverser(ptr)
{
}

PyBrElement2dNodeTraverser::PyBrElement2dNodeTraverser(AcRxObject* ptr, bool autoDelete)
    :PyBrTraverser(ptr, autoDelete)
{
}

void PyBrElement2dNodeTraverser::setElementTraverser(const PyBrMesh2dElement2dTraverser& val) const
{
    PyThrowBadBr(impObj()->setElement(*val.impObj()));
}

void PyBrElement2dNodeTraverser::setElement(const PyBrElement2d& val) const
{
    PyThrowBadBr(impObj()->setElement(*val.impObj()));
}

PyBrElement2d PyBrElement2dNodeTraverser::getElement() const
{
    AcBrElement2d val;
    PyThrowBadBr(impObj()->getElement(val));
    return PyBrElement2d{ val };
}

void PyBrElement2dNodeTraverser::setNode(const PyBrNode& val) const
{
    PyThrowBadBr(impObj()->setNode(*val.impObj()));
}

PyBrNode PyBrElement2dNodeTraverser::getNode() const
{
    AcBrNode val;
    PyThrowBadBr(impObj()->getNode(val));
    return PyBrNode{ val };
}

AcGeVector3d PyBrElement2dNodeTraverser::getSurfaceNormal() const
{
    AcGeVector3d val;
    PyThrowBadBr(impObj()->getSurfaceNormal(val));
    return val;
}

AcGePoint2d PyBrElement2dNodeTraverser::getParamPoint() const
{
    AcGePoint2d val;
    PyThrowBadBr(impObj()->getParamPoint(val));
    return val;
}

PyRxClass PyBrElement2dNodeTraverser::desc()
{
    return PyRxClass(AcBrElement2dNodeTraverser::desc(), false);
}

std::string  PyBrElement2dNodeTraverser::className()
{
    return std::string{ "AcBrElement2dNodeTraverser" };
}

AcBrElement2dNodeTraverser* PyBrElement2dNodeTraverser::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcBrElement2dNodeTraverser*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
// PyBrFaceLoopTraverser
void makePyBrFaceLoopTraverserWrapper()
{
    PyDocString DS("FaceLoopTraverser");
    class_<PyBrFaceLoopTraverser, bases<PyBrTraverser>>("FaceLoopTraverser")
        .def(init<>(DS.ARGS()))
        .def("getFace", &PyBrFaceLoopTraverser::getFace, DS.ARGS())
        .def("getLoop", &PyBrFaceLoopTraverser::getLoop, DS.ARGS())
        .def("setFaceAndLoop", &PyBrFaceLoopTraverser::setFaceAndLoop, DS.ARGS({ "val: PyBr.Loop" }))
        .def("setFace", &PyBrFaceLoopTraverser::setFace, DS.ARGS({ "val: PyBr.Face" }))
        .def("setLoop", &PyBrFaceLoopTraverser::setLoop, DS.ARGS({ "val: PyBr.Loop" }))
        .def("setFaceTraverser", &PyBrFaceLoopTraverser::setLoop, DS.ARGS({ "val: PyBr.ShellFaceTraverser" }))
        .def("className", &PyBrFaceLoopTraverser::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrFaceLoopTraverser::desc, DS.SARGS(15560)).staticmethod("desc")
        ;
}

PyBrFaceLoopTraverser::PyBrFaceLoopTraverser()
    : PyBrFaceLoopTraverser(new AcBrFaceLoopTraverser(), true)
{
}

PyBrFaceLoopTraverser::PyBrFaceLoopTraverser(const AcBrFaceLoopTraverser& src)
    : PyBrFaceLoopTraverser(new AcBrFaceLoopTraverser(src), true)
{
}

PyBrFaceLoopTraverser::PyBrFaceLoopTraverser(const AcRxObject* ptr)
    :PyBrTraverser(ptr)
{
}

PyBrFaceLoopTraverser::PyBrFaceLoopTraverser(AcRxObject* ptr, bool autoDelete)
    :PyBrTraverser(ptr, autoDelete)
{
}

PyBrFace PyBrFaceLoopTraverser::getFace() const
{
    AcBrFace val;
    PyThrowBadBr(impObj()->getFace(val));
    return PyBrFace{ val };
}

PyBrLoop PyBrFaceLoopTraverser::getLoop() const
{
    AcBrLoop val;
    PyThrowBadBr(impObj()->getLoop(val));
    return PyBrLoop{ val };
}

void PyBrFaceLoopTraverser::setFaceAndLoop(const PyBrLoop& loop) const
{
    PyThrowBadBr(impObj()->setFaceAndLoop(*loop.impObj()));
}

void PyBrFaceLoopTraverser::setFace(const PyBrFace& face) const
{
    PyThrowBadBr(impObj()->setFace(*face.impObj()));
}

void PyBrFaceLoopTraverser::setLoop(const PyBrLoop& loop) const
{
    PyThrowBadBr(impObj()->setLoop(*loop.impObj()));
}

void PyBrFaceLoopTraverser::setFaceTraverser(const PyBrShellFaceTraverser& shellFaceTrav) const
{
    PyThrowBadBr(impObj()->setFace(*shellFaceTrav.impObj()));
}

PyRxClass PyBrFaceLoopTraverser::desc()
{
    return PyRxClass(AcBrFaceLoopTraverser::desc(), false);
}

std::string  PyBrFaceLoopTraverser::className()
{
    return std::string{ "AcBrFaceLoopTraverser" };
}

AcBrFaceLoopTraverser* PyBrFaceLoopTraverser::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcBrFaceLoopTraverser*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
// PyBrLoopEdgeTraverser
void makePyBrLoopEdgeTraverserWrapper()
{
    PyDocString DS("LoopEdgeTraverser");
    class_<PyBrLoopEdgeTraverser, bases<PyBrTraverser>>("LoopEdgeTraverser")
        .def(init<>(DS.ARGS()))
        .def("getEdge", &PyBrLoopEdgeTraverser::getEdge, DS.ARGS())
        .def("getLoop", &PyBrLoopEdgeTraverser::getLoop, DS.ARGS())
        .def("getEdgeOrientToLoop", &PyBrLoopEdgeTraverser::getEdgeOrientToLoop, DS.ARGS())
        .def("getParamCurve", &PyBrLoopEdgeTraverser::getParamCurve, DS.ARGS())
        .def("getOrientedCurve", &PyBrLoopEdgeTraverser::getOrientedCurve, DS.ARGS())
        .def("setLoopAndEdge", &PyBrLoopEdgeTraverser::setLoopAndEdge, DS.ARGS({ "val: PyBr.EdgeLoopTraverser" }))
        .def("setLoopTraverser", &PyBrLoopEdgeTraverser::setLoopTraverser, DS.ARGS({ "val: PyBr.FaceLoopTraverser" }))
        .def("setLoop", &PyBrLoopEdgeTraverser::setLoop, DS.ARGS({ "val: PyBr.Loop" }))
        .def("setEdge", &PyBrLoopEdgeTraverser::setEdge, DS.ARGS({ "val: PyBr.Edge" }))
        .def("className", &PyBrLoopEdgeTraverser::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrLoopEdgeTraverser::desc, DS.SARGS(15560)).staticmethod("desc")
        ;
}

PyBrLoopEdgeTraverser::PyBrLoopEdgeTraverser()
    : PyBrLoopEdgeTraverser(new AcBrLoopEdgeTraverser(), true)
{
}

PyBrLoopEdgeTraverser::PyBrLoopEdgeTraverser(const AcBrLoopEdgeTraverser& src)
    : PyBrLoopEdgeTraverser(new AcBrLoopEdgeTraverser(src), true)
{

}

PyBrLoopEdgeTraverser::PyBrLoopEdgeTraverser(const AcRxObject* ptr)
    :PyBrTraverser(ptr)
{
}

PyBrLoopEdgeTraverser::PyBrLoopEdgeTraverser(AcRxObject* ptr, bool autoDelete)
    :PyBrTraverser(ptr, autoDelete)
{
}

PyBrEdge PyBrLoopEdgeTraverser::getEdge() const
{
    AcBrEdge val;
    PyThrowBadBr(impObj()->getEdge(val));
    return PyBrEdge{ val };
}

PyBrLoop PyBrLoopEdgeTraverser::getLoop() const
{
    AcBrLoop val;
    PyThrowBadBr(impObj()->getLoop(val));
    return PyBrLoop{ val };
}

Adesk::Boolean PyBrLoopEdgeTraverser::getEdgeOrientToLoop() const
{
    Adesk::Boolean orient = Adesk::kFalse;
    PyThrowBadBr(impObj()->getEdgeOrientToLoop(orient));
    return orient;
}

PyGeCurve2d PyBrLoopEdgeTraverser::getParamCurve() const
{
    AcGeCurve2d* pcurve = nullptr;
    PyThrowBadBr(impObj()->getParamCurve(pcurve));
    return PyGeCurve2d{ pcurve };
}

PyGeCurve3d PyBrLoopEdgeTraverser::getOrientedCurve() const
{
    AcGeCurve3d* curve = nullptr;
    PyThrowBadBr(impObj()->getOrientedCurve(curve));
    return PyGeCurve3d{ curve };
}

void PyBrLoopEdgeTraverser::setLoopAndEdge(const PyBrEdgeLoopTraverser& edgeLoop) const
{
    PyThrowBadBr(impObj()->setLoopAndEdge(*edgeLoop.impObj()));
}

void PyBrLoopEdgeTraverser::setLoopTraverser(const PyBrFaceLoopTraverser& faceLoop) const
{
    PyThrowBadBr(impObj()->setLoop(*faceLoop.impObj()));
}

void PyBrLoopEdgeTraverser::setLoop(const PyBrLoop& loop) const
{
    PyThrowBadBr(impObj()->setLoop(*loop.impObj()));
}

void PyBrLoopEdgeTraverser::setEdge(const PyBrEdge& edge) const
{
    PyThrowBadBr(impObj()->setEdge(*edge.impObj()));
}

PyRxClass PyBrLoopEdgeTraverser::desc()
{
    return PyRxClass(AcBrLoopEdgeTraverser::desc(), false);
}

std::string  PyBrLoopEdgeTraverser::className()
{
    return std::string{ "AcBrBrLoopEdgeTraverser" };
}

AcBrLoopEdgeTraverser* PyBrLoopEdgeTraverser::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcBrLoopEdgeTraverser*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
// PyBrLoopVertexTraverser
void makePyBrLoopVertexTraverserWrapper()
{
    PyDocString DS("LoopVertexTraverser");
    class_<PyBrLoopVertexTraverser, bases<PyBrTraverser>>("LoopVertexTraverser")
        .def(init<>(DS.ARGS()))
        .def("getLoop", &PyBrLoopVertexTraverser::getLoop, DS.ARGS())
        .def("getVertex", &PyBrLoopVertexTraverser::getVertex, DS.ARGS())
        .def("getParamPoint", &PyBrLoopVertexTraverser::getParamPoint, DS.ARGS())
        .def("setLoopAndVertex", &PyBrLoopVertexTraverser::setLoopAndVertex, DS.ARGS({ "val: PyBr.VertexLoopTraverser" }))
        .def("setLoopTraverser", &PyBrLoopVertexTraverser::setLoopTraverser, DS.ARGS({ "val: PyBr.FaceLoopTraverser" }))
        .def("setLoop", &PyBrLoopVertexTraverser::setLoop, DS.ARGS({ "val: PyBr.Loop" }))
        .def("setVertex", &PyBrLoopVertexTraverser::setVertex, DS.ARGS({ "val: PyBr.Vertex" }))
        .def("className", &PyBrLoopVertexTraverser::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrLoopVertexTraverser::desc, DS.SARGS(15560)).staticmethod("desc")
        ;
}

PyBrLoopVertexTraverser::PyBrLoopVertexTraverser()
    : PyBrLoopVertexTraverser(new AcBrLoopVertexTraverser(),true)
{
}

PyBrLoopVertexTraverser::PyBrLoopVertexTraverser(const AcBrLoopVertexTraverser& src)
    : PyBrLoopVertexTraverser(new AcBrLoopVertexTraverser(src), true)
{
}

PyBrLoopVertexTraverser::PyBrLoopVertexTraverser(const AcRxObject* ptr)
    :PyBrTraverser(ptr)
{
}

PyBrLoopVertexTraverser::PyBrLoopVertexTraverser(AcRxObject* ptr, bool autoDelete)
    :PyBrTraverser(ptr, autoDelete)
{
}

PyBrLoop PyBrLoopVertexTraverser::getLoop() const
{
    AcBrLoop val;
    PyThrowBadBr(impObj()->getLoop(val));
    return PyBrLoop{ val };
}

PyBrVertex PyBrLoopVertexTraverser::getVertex() const
{
    AcBrVertex val;
    PyThrowBadBr(impObj()->getVertex(val));
    return PyBrVertex{ val };
}

AcGePoint2d PyBrLoopVertexTraverser::getParamPoint() const
{
    AcGePoint2d val;
    PyThrowBadBr(impObj()->getParamPoint(val));
    return val;
}

void PyBrLoopVertexTraverser::setLoopAndVertex(const PyBrVertexLoopTraverser& vertexLoop) const
{
    PyThrowBadBr(impObj()->setLoopAndVertex(*vertexLoop.impObj()));
}

void PyBrLoopVertexTraverser::setLoopTraverser(const PyBrFaceLoopTraverser& faceLoop) const
{
    PyThrowBadBr(impObj()->setLoop(*faceLoop.impObj()));
}

void PyBrLoopVertexTraverser::setLoop(const PyBrLoop& loop) const
{
    PyThrowBadBr(impObj()->setLoop(*loop.impObj()));
}

void PyBrLoopVertexTraverser::setVertex(const PyBrVertex& vertex) const
{
    PyThrowBadBr(impObj()->setVertex(*vertex.impObj()));
}

PyRxClass PyBrLoopVertexTraverser::desc()
{
    return PyRxClass(AcBrLoopVertexTraverser::desc(), false);
}

std::string  PyBrLoopVertexTraverser::className()
{
    return std::string{ "AcBrBrLoopVertexTraverser" };
}

AcBrLoopVertexTraverser* PyBrLoopVertexTraverser::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcBrLoopVertexTraverser*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
// PyBrMesh2dElement2dTraverser
void makePyBrMesh2dElement2dTraverserWrapper()
{
    PyDocString DS("Mesh2dElement2dTraverser");
    class_<PyBrMesh2dElement2dTraverser, bases<PyBrTraverser>>("Mesh2dElement2dTraverser")
        .def(init<>(DS.ARGS()))
        .def("getMesh", &PyBrMesh2dElement2dTraverser::getMesh, DS.ARGS())
        .def("getElement", &PyBrMesh2dElement2dTraverser::getElement, DS.ARGS())
        .def("setMeshAndElement", &PyBrMesh2dElement2dTraverser::setMeshAndElement, DS.ARGS({ "val: PyBr.Element2d" }))
        .def("setMesh", &PyBrMesh2dElement2dTraverser::setMesh, DS.ARGS({ "val: PyBr.Mesh2d" }))
        .def("setElement", &PyBrMesh2dElement2dTraverser::setElement, DS.ARGS({ "val: PyBr.Element2d" }))
        .def("className", &PyBrMesh2dElement2dTraverser::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrMesh2dElement2dTraverser::desc, DS.SARGS(15560)).staticmethod("desc")
        ;
}

PyBrMesh2dElement2dTraverser::PyBrMesh2dElement2dTraverser()
    : PyBrMesh2dElement2dTraverser(new AcBrMesh2dElement2dTraverser(), true)
{
}

PyBrMesh2dElement2dTraverser::PyBrMesh2dElement2dTraverser(const AcBrMesh2dElement2dTraverser& src)
    : PyBrMesh2dElement2dTraverser(new AcBrMesh2dElement2dTraverser(src), true)
{
}

PyBrMesh2dElement2dTraverser::PyBrMesh2dElement2dTraverser(const AcRxObject* ptr)
    :PyBrTraverser(ptr)
{
}

PyBrMesh2dElement2dTraverser::PyBrMesh2dElement2dTraverser(AcRxObject* ptr, bool autoDelete)
    :PyBrTraverser(ptr, autoDelete)
{
}

PyBrMesh2d PyBrMesh2dElement2dTraverser::getMesh() const
{
    AcBrMesh2d val;
    PyThrowBadBr(impObj()->getMesh(val));
    return PyBrMesh2d{ val };
}

PyBrElement2d PyBrMesh2dElement2dTraverser::getElement() const
{
    AcBrElement2d val;
    PyThrowBadBr(impObj()->getElement(val));
    return PyBrElement2d{ val };
}

void PyBrMesh2dElement2dTraverser::setMeshAndElement(const PyBrElement2d& element2d) const
{
    PyThrowBadBr(impObj()->setMeshAndElement(*element2d.impObj()));
}

void PyBrMesh2dElement2dTraverser::setMesh(const PyBrMesh2d& mesh2d) const
{
    PyThrowBadBr(impObj()->setMesh(*mesh2d.impObj()));
}

void PyBrMesh2dElement2dTraverser::setElement(const PyBrElement2d& element2d) const
{
    PyThrowBadBr(impObj()->setElement(*element2d.impObj()));
}

PyRxClass PyBrMesh2dElement2dTraverser::desc()
{
    return PyRxClass(AcBrMesh2dElement2dTraverser::desc(), false);
}

std::string  PyBrMesh2dElement2dTraverser::className()
{
    return std::string{ "AcBrMesh2dElement2dTraverser" };
}

AcBrMesh2dElement2dTraverser* PyBrMesh2dElement2dTraverser::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcBrMesh2dElement2dTraverser*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
// PyBrShellFaceTraverser
void makePyBrShellFaceTraverserWrapper()
{
    PyDocString DS("ShellFaceTraverser");
    class_<PyBrShellFaceTraverser, bases<PyBrTraverser>>("ShellFaceTraverser")
        .def(init<>(DS.ARGS()))
        .def("getShell", &PyBrShellFaceTraverser::getShell, DS.ARGS())
        .def("getFace", &PyBrShellFaceTraverser::getFace, DS.ARGS())
        .def("setShellAndFace", &PyBrShellFaceTraverser::setShellAndFace, DS.ARGS({ "val: PyBr.Face" }))
        .def("setShellTraverser", &PyBrShellFaceTraverser::setShellTraverser, DS.ARGS({ "val: PyBr.ComplexShellTraverser" }))
        .def("setShell", &PyBrShellFaceTraverser::setShell, DS.ARGS({ "val: PyBr.Shell" }))
        .def("setFace", &PyBrShellFaceTraverser::setFace, DS.ARGS({ "val: PyBr.Face" }))
        .def("className", &PyBrShellFaceTraverser::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrShellFaceTraverser::desc, DS.SARGS(15560)).staticmethod("desc")
        ;
}

PyBrShellFaceTraverser::PyBrShellFaceTraverser()
    : PyBrShellFaceTraverser(new AcBrShellFaceTraverser(), true)
{
}

PyBrShellFaceTraverser::PyBrShellFaceTraverser(const AcBrShellFaceTraverser& src)
    : PyBrShellFaceTraverser(new AcBrShellFaceTraverser(src), true)
{
}

PyBrShellFaceTraverser::PyBrShellFaceTraverser(const AcRxObject* ptr)
    :PyBrTraverser(ptr)
{
}

PyBrShellFaceTraverser::PyBrShellFaceTraverser(AcRxObject* ptr, bool autoDelete)
    :PyBrTraverser(ptr, autoDelete)
{
}

PyBrShell PyBrShellFaceTraverser::getShell() const
{
    AcBrShell val;
    PyThrowBadBr(impObj()->getShell(val));
    return PyBrShell{ val };
}

PyBrFace PyBrShellFaceTraverser::getFace() const
{
    AcBrFace val;
    PyThrowBadBr(impObj()->getFace(val));
    return PyBrFace{ val };
}

void PyBrShellFaceTraverser::setShellAndFace(const PyBrFace& face) const
{
    PyThrowBadBr(impObj()->setShellAndFace(*face.impObj()));
}

void PyBrShellFaceTraverser::setShellTraverser(const PyBrComplexShellTraverser& complexShellTraverser) const
{
    PyThrowBadBr(impObj()->setShell(*complexShellTraverser.impObj()));
}

void PyBrShellFaceTraverser::setShell(const PyBrShell& shell) const
{
    PyThrowBadBr(impObj()->setShell(*shell.impObj()));
}

void PyBrShellFaceTraverser::setFace(const PyBrFace& face) const
{
    PyThrowBadBr(impObj()->setFace(*face.impObj()));
}

PyRxClass PyBrShellFaceTraverser::desc()
{
    return PyRxClass(AcBrShellFaceTraverser::desc(), false);
}

std::string  PyBrShellFaceTraverser::className()
{
    return std::string{ "AcBrBrShellFaceTraverser" };
}

AcBrShellFaceTraverser* PyBrShellFaceTraverser::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcBrShellFaceTraverser*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
// PyBrVertexEdgeTraverser
void makePyBrVertexEdgeTraverserWrapper()
{
    PyDocString DS("VertexEdgeTraverser");
    class_<PyBrVertexEdgeTraverser, bases<PyBrTraverser>>("VertexEdgeTraverser")
        .def(init<>(DS.ARGS()))
        .def("getEdge", &PyBrVertexEdgeTraverser::getEdge, DS.ARGS())
        .def("getVertex", &PyBrVertexEdgeTraverser::getVertex, DS.ARGS())
        .def("setVertex", &PyBrVertexEdgeTraverser::setVertex, DS.ARGS({ "val: PyBr.Vertex" }))
        .def("setEdge", &PyBrVertexEdgeTraverser::setEdge, DS.ARGS({ "val: PyBr.Edge" }))
        .def("className", &PyBrVertexEdgeTraverser::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrVertexEdgeTraverser::desc, DS.SARGS(15560)).staticmethod("desc")
        ;
}

PyBrVertexEdgeTraverser::PyBrVertexEdgeTraverser()
    : PyBrVertexEdgeTraverser(new AcBrVertexEdgeTraverser(),true)
{
}

PyBrVertexEdgeTraverser::PyBrVertexEdgeTraverser(const AcBrVertexEdgeTraverser& src)
    : PyBrVertexEdgeTraverser(new AcBrVertexEdgeTraverser(src), true)
{
}

PyBrVertexEdgeTraverser::PyBrVertexEdgeTraverser(const AcRxObject* ptr)
    :PyBrTraverser(ptr)
{
}

PyBrVertexEdgeTraverser::PyBrVertexEdgeTraverser(AcRxObject* ptr, bool autoDelete)
    :PyBrTraverser(ptr, autoDelete)
{
}

PyBrEdge PyBrVertexEdgeTraverser::getEdge() const
{
    AcBrEdge val;
    PyThrowBadBr(impObj()->getEdge(val));
    return PyBrEdge{ val };
}

PyBrVertex PyBrVertexEdgeTraverser::getVertex() const
{
    AcBrVertex val;
    PyThrowBadBr(impObj()->getVertex(val));
    return PyBrVertex{ val };
}

void PyBrVertexEdgeTraverser::setVertex(const PyBrVertex& vertex) const
{
    PyThrowBadBr(impObj()->setVertex(*vertex.impObj()));
}

void PyBrVertexEdgeTraverser::setEdge(const PyBrEdge& edge) const
{
    PyThrowBadBr(impObj()->setEdge(*edge.impObj()));
}

PyRxClass PyBrVertexEdgeTraverser::desc()
{
    return PyRxClass(AcBrVertexEdgeTraverser::desc(), false);
}

std::string  PyBrVertexEdgeTraverser::className()
{
    return std::string{ "AcBrVertexEdgeTraverser" };
}

AcBrVertexEdgeTraverser* PyBrVertexEdgeTraverser::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcBrVertexEdgeTraverser*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
// PyBrVertexLoopTraverser
void makePyBrVertexLoopTraverserWrapper()
{
    PyDocString DS("VertexLoopTraverser");
    class_<PyBrVertexLoopTraverser, bases<PyBrTraverser>>("VertexLoopTraverser")
        .def(init<>(DS.ARGS()))
        .def("getVertex", &PyBrVertexLoopTraverser::getVertex, DS.ARGS())
        .def("getLoop", &PyBrVertexLoopTraverser::getLoop, DS.ARGS())
        .def("setVertexAndLoop", &PyBrVertexLoopTraverser::setVertexAndLoop, DS.ARGS({ "val: PyBr.LoopVertexTraverser" }))
        .def("setVertex", &PyBrVertexLoopTraverser::setVertex, DS.ARGS({ "val: PyBr.Vertex" }))
        .def("setLoop", &PyBrVertexLoopTraverser::setLoop, DS.ARGS({ "val: PyBr.Loop" }))
        .def("className", &PyBrVertexLoopTraverser::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrVertexLoopTraverser::desc, DS.SARGS(15560)).staticmethod("desc")
        ;
}

PyBrVertexLoopTraverser::PyBrVertexLoopTraverser()
    : PyBrVertexLoopTraverser(new AcBrVertexLoopTraverser(), true)
{
}

PyBrVertexLoopTraverser::PyBrVertexLoopTraverser(const AcBrVertexLoopTraverser& src)
    : PyBrVertexLoopTraverser(new AcBrVertexLoopTraverser(src), true)
{
}

PyBrVertexLoopTraverser::PyBrVertexLoopTraverser(const AcRxObject* ptr)
    :PyBrTraverser(ptr)
{
}

PyBrVertexLoopTraverser::PyBrVertexLoopTraverser(AcRxObject* ptr, bool autoDelete)
    :PyBrTraverser(ptr, autoDelete)
{
}

PyBrVertex PyBrVertexLoopTraverser::getVertex() const
{
    AcBrVertex val;
    PyThrowBadBr(impObj()->getVertex(val));
    return PyBrVertex{ val };
}

PyBrLoop PyBrVertexLoopTraverser::getLoop() const
{
    AcBrLoop val;
    PyThrowBadBr(impObj()->getLoop(val));
    return PyBrLoop{ val };
}

void PyBrVertexLoopTraverser::setVertexAndLoop(const PyBrLoopVertexTraverser& LoopVertexTraverser) const
{
    PyThrowBadBr(impObj()->setVertexAndLoop(*LoopVertexTraverser.impObj()));
}

void PyBrVertexLoopTraverser::setVertex(const PyBrVertex& vertex) const
{
    PyThrowBadBr(impObj()->setVertex(*vertex.impObj()));
}

void PyBrVertexLoopTraverser::setLoop(const PyBrLoop& loop) const
{
    PyThrowBadBr(impObj()->setLoop(*loop.impObj()));
}

PyRxClass PyBrVertexLoopTraverser::desc()
{
    return PyRxClass(AcBrVertexLoopTraverser::desc(), false);
}

std::string  PyBrVertexLoopTraverser::className()
{
    return std::string{ "AcBrBrVertexLoopTraverser" };
}

AcBrVertexLoopTraverser* PyBrVertexLoopTraverser::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcBrVertexLoopTraverser*>(m_pyImp.get());
}
