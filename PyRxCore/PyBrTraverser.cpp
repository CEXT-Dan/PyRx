#include "stdafx.h"
#include "PyBrTraverser.h"


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

bool PyBrTraverser::done()
{
    return impObj()->done();
}

void PyBrTraverser::next()
{
    PyThrowBadBr(impObj()->next());
}

void PyBrTraverser::restart()
{
    PyThrowBadBr(impObj()->restart());
}

void PyBrTraverser::setValidationLevel(const AcBr::ValidationLevel& validationLevel)
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
#if defined(_BRXTARGET250)
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
    PyDocString DS("BrepComplexTraverser");
    class_<PyBrepComplexTraverser, bases<PyBrTraverser>>("BrepComplexTraverser", no_init)
        .def("className", &PyBrepComplexTraverser::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrepComplexTraverser::desc, DS.SARGS(15560)).staticmethod("desc")
        ;
}

PyBrepComplexTraverser::PyBrepComplexTraverser(const AcRxObject* ptr)
    :PyBrTraverser(ptr)
{
}

PyBrepComplexTraverser::PyBrepComplexTraverser(AcRxObject* ptr, bool autoDelete)
    :PyBrTraverser(ptr, autoDelete)
{
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
    PyDocString DS("BrepEdgeTraverser");
    class_<PyBrepEdgeTraverser, bases<PyBrTraverser>>("BrepEdgeTraverser", no_init)
        .def("className", &PyBrepEdgeTraverser::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrepEdgeTraverser::desc, DS.SARGS(15560)).staticmethod("desc")
        ;
}

PyBrepEdgeTraverser::PyBrepEdgeTraverser(const AcRxObject* ptr)
    :PyBrTraverser(ptr)
{
}

PyBrepEdgeTraverser::PyBrepEdgeTraverser(AcRxObject* ptr, bool autoDelete)
    :PyBrTraverser(ptr, autoDelete)
{
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
    PyDocString DS("BrepFaceTraverser");
    class_<PyBrepFaceTraverser, bases<PyBrTraverser>>("BrepFaceTraverser", no_init)
        .def("className", &PyBrepFaceTraverser::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrepFaceTraverser::desc, DS.SARGS(15560)).staticmethod("desc")
        ;
}

PyBrepFaceTraverser::PyBrepFaceTraverser(const AcRxObject* ptr)
    :PyBrTraverser(ptr)
{
}

PyBrepFaceTraverser::PyBrepFaceTraverser(AcRxObject* ptr, bool autoDelete)
    :PyBrTraverser(ptr, autoDelete)
{
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
    PyDocString DS("BrepShellTraverser");
    class_<PyBrepShellTraverser, bases<PyBrTraverser>>("BrepShellTraverser", no_init)
        .def("className", &PyBrepShellTraverser::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrepShellTraverser::desc, DS.SARGS(15560)).staticmethod("desc")
        ;
}

PyBrepShellTraverser::PyBrepShellTraverser(const AcRxObject* ptr)
    :PyBrTraverser(ptr)
{
}

PyBrepShellTraverser::PyBrepShellTraverser(AcRxObject* ptr, bool autoDelete)
    :PyBrTraverser(ptr, autoDelete)
{
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
    PyDocString DS("BrepVertexTraverser");
    class_<PyBrepVertexTraverser, bases<PyBrTraverser>>("BrepVertexTraverser", no_init)
        .def("className", &PyBrepVertexTraverser::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrepVertexTraverser::desc, DS.SARGS(15560)).staticmethod("desc")
        ;
}

PyBrepVertexTraverser::PyBrepVertexTraverser(const AcRxObject* ptr)
    :PyBrTraverser(ptr)
{
}

PyBrepVertexTraverser::PyBrepVertexTraverser(AcRxObject* ptr, bool autoDelete)
    :PyBrTraverser(ptr, autoDelete)
{
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
    PyDocString DS("BrComplexShellTraverser");
    class_<PyBrComplexShellTraverser, bases<PyBrTraverser>>("BrComplexShellTraverser", no_init)
        .def("className", &PyBrComplexShellTraverser::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrComplexShellTraverser::desc, DS.SARGS(15560)).staticmethod("desc")
        ;
}

PyBrComplexShellTraverser::PyBrComplexShellTraverser(const AcRxObject* ptr)
    :PyBrTraverser(ptr)
{
}

PyBrComplexShellTraverser::PyBrComplexShellTraverser(AcRxObject* ptr, bool autoDelete)
    :PyBrTraverser(ptr, autoDelete)
{
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
    PyDocString DS("BrEdgeLoopTraverser");
    class_<PyBrEdgeLoopTraverser, bases<PyBrTraverser>>("BrEdgeLoopTraverser", no_init)
        .def("className", &PyBrEdgeLoopTraverser::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrEdgeLoopTraverser::desc, DS.SARGS(15560)).staticmethod("desc")
        ;
}

PyBrEdgeLoopTraverser::PyBrEdgeLoopTraverser(const AcRxObject* ptr)
    :PyBrTraverser(ptr)
{
}

PyBrEdgeLoopTraverser::PyBrEdgeLoopTraverser(AcRxObject* ptr, bool autoDelete)
    :PyBrTraverser(ptr, autoDelete)
{
}

PyRxClass PyBrEdgeLoopTraverser::desc()
{
    return PyRxClass(AcBrEdgeLoopTraverser::desc(), false);
}

std::string  PyBrEdgeLoopTraverser::className()
{
    return std::string{ "AcBrBrEdgeLoopTraverser" };
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
    PyDocString DS("BrElement2dNodeTraverser");
    class_<PyBrElement2dNodeTraverser, bases<PyBrTraverser>>("BrElement2dNodeTraverser", no_init)
        .def("className", &PyBrElement2dNodeTraverser::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrElement2dNodeTraverser::desc, DS.SARGS(15560)).staticmethod("desc")
        ;
}

PyBrElement2dNodeTraverser::PyBrElement2dNodeTraverser(const AcRxObject* ptr)
    :PyBrTraverser(ptr)
{
}

PyBrElement2dNodeTraverser::PyBrElement2dNodeTraverser(AcRxObject* ptr, bool autoDelete)
    :PyBrTraverser(ptr, autoDelete)
{
}

PyRxClass PyBrElement2dNodeTraverser::desc()
{
    return PyRxClass(AcBrElement2dNodeTraverser::desc(), false);
}

std::string  PyBrElement2dNodeTraverser::className()
{
    return std::string{ "AcBrBrElement2dNodeTraverser" };
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
    PyDocString DS("BrFaceLoopTraverser");
    class_<PyBrFaceLoopTraverser, bases<PyBrTraverser>>("BrFaceLoopTraverser", no_init)
        .def("className", &PyBrFaceLoopTraverser::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrFaceLoopTraverser::desc, DS.SARGS(15560)).staticmethod("desc")
        ;
}

PyBrFaceLoopTraverser::PyBrFaceLoopTraverser(const AcRxObject* ptr)
    :PyBrTraverser(ptr)
{
}

PyBrFaceLoopTraverser::PyBrFaceLoopTraverser(AcRxObject* ptr, bool autoDelete)
    :PyBrTraverser(ptr, autoDelete)
{
}

PyRxClass PyBrFaceLoopTraverser::desc()
{
    return PyRxClass(AcBrFaceLoopTraverser::desc(), false);
}

std::string  PyBrFaceLoopTraverser::className()
{
    return std::string{ "AcBrBrFaceLoopTraverser" };
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
    PyDocString DS("BrLoopEdgeTraverser");
    class_<PyBrLoopEdgeTraverser, bases<PyBrTraverser>>("BrLoopEdgeTraverser", no_init)
        .def("className", &PyBrLoopEdgeTraverser::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrLoopEdgeTraverser::desc, DS.SARGS(15560)).staticmethod("desc")
        ;
}

PyBrLoopEdgeTraverser::PyBrLoopEdgeTraverser(const AcRxObject* ptr)
    :PyBrTraverser(ptr)
{
}

PyBrLoopEdgeTraverser::PyBrLoopEdgeTraverser(AcRxObject* ptr, bool autoDelete)
    :PyBrTraverser(ptr, autoDelete)
{
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
    PyDocString DS("BrLoopVertexTraverser");
    class_<PyBrLoopVertexTraverser, bases<PyBrTraverser>>("BrLoopVertexTraverser", no_init)
        .def("className", &PyBrLoopVertexTraverser::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrLoopVertexTraverser::desc, DS.SARGS(15560)).staticmethod("desc")
        ;
}

PyBrLoopVertexTraverser::PyBrLoopVertexTraverser(const AcRxObject* ptr)
    :PyBrTraverser(ptr)
{
}

PyBrLoopVertexTraverser::PyBrLoopVertexTraverser(AcRxObject* ptr, bool autoDelete)
    :PyBrTraverser(ptr, autoDelete)
{
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
    PyDocString DS("BrMesh2dElement2dTraverser");
    class_<PyBrMesh2dElement2dTraverser, bases<PyBrTraverser>>("BrMesh2dElement2dTraverser", no_init)
        .def("className", &PyBrMesh2dElement2dTraverser::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrMesh2dElement2dTraverser::desc, DS.SARGS(15560)).staticmethod("desc")
        ;
}

PyBrMesh2dElement2dTraverser::PyBrMesh2dElement2dTraverser(const AcRxObject* ptr)
    :PyBrTraverser(ptr)
{
}

PyBrMesh2dElement2dTraverser::PyBrMesh2dElement2dTraverser(AcRxObject* ptr, bool autoDelete)
    :PyBrTraverser(ptr, autoDelete)
{
}

PyRxClass PyBrMesh2dElement2dTraverser::desc()
{
    return PyRxClass(AcBrMesh2dElement2dTraverser::desc(), false);
}

std::string  PyBrMesh2dElement2dTraverser::className()
{
    return std::string{ "AcBrBrMesh2dElement2dTraverser" };
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
    PyDocString DS("BrShellFaceTraverser");
    class_<PyBrShellFaceTraverser, bases<PyBrTraverser>>("BrShellFaceTraverser", no_init)
        .def("className", &PyBrShellFaceTraverser::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrShellFaceTraverser::desc, DS.SARGS(15560)).staticmethod("desc")
        ;
}

PyBrShellFaceTraverser::PyBrShellFaceTraverser(const AcRxObject* ptr)
    :PyBrTraverser(ptr)
{
}

PyBrShellFaceTraverser::PyBrShellFaceTraverser(AcRxObject* ptr, bool autoDelete)
    :PyBrTraverser(ptr, autoDelete)
{
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
    PyDocString DS("BrVertexEdgeTraverser");
    class_<PyBrVertexEdgeTraverser, bases<PyBrTraverser>>("BrVertexEdgeTraverser", no_init)
        .def("className", &PyBrVertexEdgeTraverser::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrVertexEdgeTraverser::desc, DS.SARGS(15560)).staticmethod("desc")
        ;
}

PyBrVertexEdgeTraverser::PyBrVertexEdgeTraverser(const AcRxObject* ptr)
    :PyBrTraverser(ptr)
{
}

PyBrVertexEdgeTraverser::PyBrVertexEdgeTraverser(AcRxObject* ptr, bool autoDelete)
    :PyBrTraverser(ptr, autoDelete)
{
}

PyRxClass PyBrVertexEdgeTraverser::desc()
{
    return PyRxClass(AcBrVertexEdgeTraverser::desc(), false);
}

std::string  PyBrVertexEdgeTraverser::className()
{
    return std::string{ "AcBrBrVertexEdgeTraverser" };
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
    PyDocString DS("BrVertexLoopTraverser");
    class_<PyBrVertexLoopTraverser, bases<PyBrTraverser>>("BrVertexLoopTraverser", no_init)
        .def("className", &PyBrVertexLoopTraverser::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrVertexLoopTraverser::desc, DS.SARGS(15560)).staticmethod("desc")
        ;
}

PyBrVertexLoopTraverser::PyBrVertexLoopTraverser(const AcRxObject* ptr)
    :PyBrTraverser(ptr)
{
}

PyBrVertexLoopTraverser::PyBrVertexLoopTraverser(AcRxObject* ptr, bool autoDelete)
    :PyBrTraverser(ptr, autoDelete)
{
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
