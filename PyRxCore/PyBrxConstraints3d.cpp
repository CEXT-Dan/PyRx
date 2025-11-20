#include "stdafx.h"
#include "PyBrxConstraints3d.h"

#ifdef BRXAPP

using namespace boost::python;

//---------------------------------------------------------------------
//PyBrxConstraintArgument
void makePyBrxConstraintArgument()
{
    constexpr const std::string_view ctords = "Overloads:\n"
        "- None: Any\n"
        "- subpath: PyDb.FullSubentPath\n"
        "- val: PyBrx.ConstraintArgCoordSysObj\n"
        "- subpath: PyDb.FullSubentPath, val: PyBrx.ConstraintArgCoordSysObj\n";

    PyDocString DS("PyBrx.ConstraintArgument");
    class_<PyBrxConstraintArgument>("ConstraintArgument")
        .def(init<>())
        .def(init<PyDbFullSubentPath>())
        .def(init<AcConstraintArgument::CoordinateSystemObject>())
        .def(init<PyDbFullSubentPath, AcConstraintArgument::CoordinateSystemObject>(DS.CTOR(ctords)))
        .def("path", &PyBrxConstraintArgument::path, DS.ARGS())
        .def("isCoordinateSystemObject", &PyBrxConstraintArgument::isCoordinateSystemObject, DS.ARGS())
        .def("coordinateSystemObject", &PyBrxConstraintArgument::coordinateSystemObject, DS.ARGS())
        .def("className", &PyBrxConstraintArgument::className, DS.SARGS()).staticmethod("className")
        ;
}

PyBrxConstraintArgument::PyBrxConstraintArgument()
    : m_imp()
{
}

PyBrxConstraintArgument::PyBrxConstraintArgument(const PyDbFullSubentPath& path)
    : m_imp(path.pyImp)
{
}

PyBrxConstraintArgument::PyBrxConstraintArgument(AcConstraintArgument::CoordinateSystemObject cs)
    : m_imp(cs)
{
}

PyBrxConstraintArgument::PyBrxConstraintArgument(const PyDbFullSubentPath& path, AcConstraintArgument::CoordinateSystemObject cs)
    : m_imp(path.pyImp, cs)
{
}

PyDbFullSubentPath PyBrxConstraintArgument::path() const
{
    return PyDbFullSubentPath(m_imp.path());
}

bool PyBrxConstraintArgument::isCoordinateSystemObject() const
{
    return m_imp.isCoordinateSystemObject();
}

AcConstraintArgument::CoordinateSystemObject PyBrxConstraintArgument::coordinateSystemObject() const
{
    return m_imp.coordinateSystemObject();
}

std::string PyBrxConstraintArgument::className()
{
    return "AcConstraintArgument";
}

//---------------------------------------------------------------------
//PyBrxVariable
void makePyBrxVariable()
{
    PyDocString DS("PyBrx.Variable");
    class_<PyBrxVariable>("Variable", no_init)
        .def("getBlockId", &PyBrxVariable::getBlockId, DS.ARGS())
        .def("name", &PyBrxVariable::name, DS.ARGS())
        .def("setName", &PyBrxVariable::setName, DS.ARGS({ "name:str" }))
        .def("expression", &PyBrxVariable::expression, DS.ARGS())
        .def("setExpression", &PyBrxVariable::setExpression, DS.ARGS({ "name:str" }))
        .def("value", &PyBrxVariable::value, DS.ARGS())
        .def("setValue", &PyBrxVariable::setValue, DS.ARGS({ "val:float" }))
        .def("hasLowerBound", &PyBrxVariable::hasLowerBound, DS.ARGS())
        .def("hasUpperBound", &PyBrxVariable::hasUpperBound, DS.ARGS())
        .def("lowerBound", &PyBrxVariable::lowerBound, DS.ARGS())
        .def("upperBound", &PyBrxVariable::upperBound, DS.ARGS())
        .def("setLowerBound", &PyBrxVariable::setLowerBound, DS.ARGS({ "val:float" }))
        .def("unsetUpperBound", &PyBrxVariable::unsetUpperBound, DS.ARGS({ "val:float" }))
        .def("isAnonymous", &PyBrxVariable::isAnonymous, DS.ARGS())
        .def("erase", &PyBrxVariable::erase, DS.ARGS())
        .def("exposed", &PyBrxVariable::exposed, DS.ARGS())
        .def("setExposed", &PyBrxVariable::setExposed, DS.ARGS({ "val:PyBrx.VariableExposeMode" }))
        .def("geometryDrivenMode", &PyBrxVariable::geometryDrivenMode, DS.ARGS())
        .def("setGeometryDrivenMode", &PyBrxVariable::setGeometryDrivenMode, DS.ARGS({ "val:PyBrx.VariableEGdMode" }))
        .def("getByName", &PyBrxVariable::getByName1)
        .def("getByName", &PyBrxVariable::getByName2, DS.SARGS({ "blockId: PyDb.ObjectId", "name:str", "createIfNotExist: bool = False" })).staticmethod("getByName")
        .def("getFromBlock", &PyBrxVariable::getFromBlock, DS.SARGS({ "blockId: PyDb.ObjectId" })).staticmethod("getFromBlock")
        .def("className", &PyBrxVariable::className, DS.SARGS()).staticmethod("className")
        ;
}

PyBrxVariable::PyBrxVariable(AcVariable* scr)
    : m_pyImp(scr)
{
}

PyDbObjectId PyBrxVariable::getBlockId() const
{
    return PyDbObjectId(impObj()->getBlockId());
}

std::string PyBrxVariable::name() const
{
    return wstr_to_utf8(impObj()->name());
}

void PyBrxVariable::setName(const std::string& name) const
{
    PyThrowBadEs(impObj()->setName(utf8_to_wstr(name).c_str()));
}

std::string PyBrxVariable::expression() const
{
    return wstr_to_utf8(impObj()->expression());
}

void PyBrxVariable::setExpression(const std::string& expr) const
{
    PyThrowBadEs(impObj()->setExpression(utf8_to_wstr(expr).c_str()));
}

double PyBrxVariable::value() const
{
    return impObj()->value();
}

void PyBrxVariable::setValue(double value) const
{
    PyThrowBadEs(impObj()->setValue(value));
}

bool PyBrxVariable::hasLowerBound() const
{
    return impObj()->hasLowerBound();
}

bool PyBrxVariable::hasUpperBound() const
{
    return impObj()->hasUpperBound();
}

double PyBrxVariable::lowerBound() const
{
    return impObj()->lowerBound();
}

double PyBrxVariable::upperBound() const
{
    return impObj()->lowerBound();
}

void PyBrxVariable::setLowerBound(double value) const
{
    PyThrowBadEs(impObj()->setLowerBound(value));
}

void PyBrxVariable::setUpperBound(double value) const
{
    PyThrowBadEs(impObj()->setUpperBound(value));
}

void PyBrxVariable::unsetLowerBound() const
{
    PyThrowBadEs(impObj()->unsetLowerBound());
}

void PyBrxVariable::unsetUpperBound() const
{
    PyThrowBadEs(impObj()->unsetUpperBound());
}

bool PyBrxVariable::isAnonymous() const
{
    return impObj()->isAnonymous();
}

void PyBrxVariable::erase() const
{
    PyThrowBadEs(impObj()->erase());
}

AcVariable::ExposeMode PyBrxVariable::exposed() const
{
    return impObj()->exposed();
}

void PyBrxVariable::setExposed(AcVariable::ExposeMode val) const
{
    PyThrowBadEs(impObj()->setExposed(val));
}

AcVariable::EGdMode PyBrxVariable::geometryDrivenMode() const
{
    return impObj()->geometryDrivenMode();
}

void PyBrxVariable::setGeometryDrivenMode(AcVariable::EGdMode val) const
{
    PyThrowBadEs(impObj()->setGeometryDrivenMode(val));
}

PyBrxVariable PyBrxVariable::getByName1(const PyDbObjectId& blockId, const std::string& name)
{
    return getByName2(blockId, name, false);
}

PyBrxVariable PyBrxVariable::getByName2(const PyDbObjectId& blockId, const std::string& name, bool createIfNotExist)
{
    auto result = AcVariable::getByName(blockId.m_id, utf8_to_wstr(name).c_str(), createIfNotExist);
    if (result.refCount() != 1)
        PyThrowBadEs(eInvalidInput);
    return PyBrxVariable(result.detach());
}


boost::python::list PyBrxVariable::getFromBlock(const PyDbObjectId& blockId)
{
    PyAutoLockGIL lock;
    boost::python::list pylist;
    for (auto& item : AcVariable::getFromBlock(blockId.m_id))
    {
        if (item.refCount() != 1)
            PyThrowBadEs(eInvalidInput);
        pylist.append(PyBrxVariable(item.detach()));
    }
    return pylist;
}

std::string PyBrxVariable::className()
{
    return "AcVariable";
}

AcVariable* PyBrxVariable::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcVariable*>(m_pyImp.get());
}

//---------------------------------------------------------------------
//PyBrxConstraint
void makePyBrxConstraint()
{

    PyDocString DS("PyBrx.Constraint");
    class_<PyBrxConstraint>("Constraint", no_init)
        .def("getBlockId", &PyBrxConstraint::getBlockId, DS.ARGS())
        .def("className", &PyBrxConstraint::className, DS.SARGS()).staticmethod("className")
        ;
}

PyBrxConstraint::PyBrxConstraint(AcConstraint* scr)
    : m_pyImp(scr)
{
}

PyDbObjectId PyBrxConstraint::getBlockId() const
{
    return PyDbObjectId(impObj()->getBlockId());
}

std::string PyBrxConstraint::className()
{
    return "AcConstraint";
}

AcConstraint* PyBrxConstraint::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcConstraint*>(m_pyImp.get());
}

#endif
