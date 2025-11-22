#include "stdafx.h"
#include "PyBrxConstraints3d.h"

#ifdef BRXAPP
#include "PyGePlane.h"

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

PyBrxConstraintArgument::PyBrxConstraintArgument(const AcConstraintArgument& other)
    : m_imp()
{
    memcpy_s(&m_imp, sizeof(AcConstraintArgument), &other, sizeof(AcConstraintArgument));
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
        PyThrowBadEs(eInvalidOpenState);
    return PyBrxVariable(result.detach());
}


boost::python::list PyBrxVariable::getFromBlock(const PyDbObjectId& blockId)
{
    PyAutoLockGIL lock;
    boost::python::list pylist;
    for (auto& item : AcVariable::getFromBlock(blockId.m_id))
    {
        if (item.refCount() != 1)
            PyThrowBadEs(eInvalidOpenState);
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
        .def("isDimensional", &PyBrxConstraint::isDimensional, DS.ARGS())
        .def("parameter", &PyBrxConstraint::parameter, DS.ARGS())
        .def("getDimension", &PyBrxConstraint::getDimension, DS.ARGS())
        .def("arguments", &PyBrxConstraint::arguments, DS.ARGS())
        .def("getArguments", &PyBrxConstraint::getArguments, DS.ARGS())
        .def("name", &PyBrxConstraint::name, DS.ARGS())
        .def("setName", &PyBrxConstraint::setName, DS.ARGS({ "name:str" }))
        .def("name", &PyBrxConstraint::getType, DS.ARGS())
        .def("nodeId", &PyBrxConstraint::nodeId, DS.ARGS())
        .def("isEnabled", &PyBrxConstraint::isEnabled, DS.ARGS())
        .def("setEnabled", &PyBrxConstraint::setEnabled, DS.ARGS({ "flag:bool" }))
        .def("getDirections", &PyBrxConstraint::getDirections, DS.ARGS())
        .def("setDirections", &PyBrxConstraint::setDirections, DS.ARGS({ "flag:PyBrx.ConstraintDirections" }))
        .def("getMeasurementMode", &PyBrxConstraint::getMeasurementMode, DS.ARGS({ "argIndex:int" }))
        .def("setMeasurementMode", &PyBrxConstraint::setMeasurementMode, DS.ARGS({ "flag:PyBrx.ConstraintMeasurementMode","argIndex:int" }))
        .def("getPlacement", &PyBrxConstraint::getPlacement, DS.ARGS({ "argIndex:int" }))
        .def("setPlacement", &PyBrxConstraint::setPlacement, DS.ARGS({ "flag:PyBrx.ConstraintPlacement","argIndex:int" }))
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

bool PyBrxConstraint::isDimensional() const
{
    return impObj()->isDimensional();
}

PyBrxVariable PyBrxConstraint::parameter() const
{
    auto result = impObj()->parameter();;
    if (result.refCount() != 1)
        PyThrowBadEs(eInvalidOpenState);
    return PyBrxVariable(result.detach());
}

PyDbObjectId PyBrxConstraint::getDimension() const
{
    return PyDbObjectId(impObj()->getDimension());
}

boost::python::list PyBrxConstraint::arguments() const
{
    return FullSubentPathArrayToPyList(impObj()->arguments());
}

boost::python::list PyBrxConstraint::getArguments() const
{
    PyAutoLockGIL lock;
    boost::python::list pylist;
    for (const auto& item : impObj()->getArguments())
        pylist.append(PyBrxConstraintArgument(item));
    return pylist;
}

std::string PyBrxConstraint::name() const
{
    return wstr_to_utf8(impObj()->name());
}

void PyBrxConstraint::setName(const std::string& name) const
{
    PyThrowBadEs(impObj()->setName(utf8_to_wstr(name).c_str()));
}

AcConstraint::ConstraintType PyBrxConstraint::getType() const
{
    return impObj()->getType();
}

Adesk::UInt32 PyBrxConstraint::nodeId() const
{
    return impObj()->nodeId();
}

bool PyBrxConstraint::isEnabled() const
{
    return impObj()->isEnabled();
}

void PyBrxConstraint::setEnabled(bool flag) const
{
    PyThrowBadEs(impObj()->setEnabled(flag));
}

AcConstraint::Directions PyBrxConstraint::getDirections() const
{
    AcConstraint::Directions flag = AcConstraint::Directions::eDirectionsAny;
    PyThrowBadEs(impObj()->getDirections(flag));
    return flag;
}

void PyBrxConstraint::setDirections(AcConstraint::Directions flag) const
{
    PyThrowBadEs(impObj()->setDirections(flag));
}

AcConstraint::MeasurementMode PyBrxConstraint::getMeasurementMode(unsigned int argIndex) const
{
    AcConstraint::MeasurementMode flag = AcConstraint::MeasurementMode::eMeasurementModeCenter;
    PyThrowBadEs(impObj()->getMeasurementMode(flag, argIndex));
    return flag;
}

void PyBrxConstraint::setMeasurementMode(AcConstraint::MeasurementMode newMeasureMode, unsigned int argIndex) const
{
    PyThrowBadEs(impObj()->setMeasurementMode(newMeasureMode, argIndex));
}

AcConstraint::Placement PyBrxConstraint::getPlacement(unsigned int argIndex) const
{
    AcConstraint::Placement flag = AcConstraint::Placement::ePlacementAny;
    PyThrowBadEs(impObj()->getPlacement(flag, argIndex));
    return flag;
}

void PyBrxConstraint::setPlacement(AcConstraint::Placement newPlacement, unsigned int argIndex) const
{
    PyThrowBadEs(impObj()->setPlacement(newPlacement, argIndex));
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

//---------------------------------------------------------------------
//PyBrxConstraintsGroup
void makePyBrxConstraintsGroup()
{
    PyDocString DS("PyBrx.ConstraintsGroup");
    class_<PyBrxConstraint>("ConstraintsGroup", no_init)
        .def("getBlockId", &PyBrxConstraintsGroup::getBlockId, DS.ARGS())
        .def("hasSketchPlane", &PyBrxConstraintsGroup::hasSketchPlane, DS.ARGS())
        .def("isTransient", &PyBrxConstraintsGroup::isTransient, DS.ARGS())
        .def("getSketchPlane", &PyBrxConstraintsGroup::getSketchPlane, DS.ARGS())
        .def("constraints", &PyBrxConstraintsGroup::constraints, DS.ARGS())
        .def("getConstraintByNodeId", &PyBrxConstraintsGroup::getConstraintByNodeId, DS.ARGS({ "nodeId: int" }))
        .def("addConstraintSubents", &PyBrxConstraintsGroup::addConstraintSubents, DS.ARGS({ "type: PyBrx.ConstraintType", "paths: list[PyDb.FullSubentPath]" }))
        .def("addConstraintArgs", &PyBrxConstraintsGroup::addConstraintArgs, DS.ARGS({ "type: PyBrx.ConstraintType", "args: list[PyBrx.ConstraintArgument]" }))
        .def("deleteConstraint", &PyBrxConstraintsGroup::deleteConstraint, DS.ARGS({ "constraint: PyBrx.Constraint" }))
        .def("evaluate", &PyBrxConstraintsGroup::evaluate, DS.ARGS())
        .def("className", &PyBrxConstraintsGroup::className, DS.SARGS()).staticmethod("className")
        ;
}

PyBrxConstraintsGroup::PyBrxConstraintsGroup(AcConstraintsGroup* scr)
    : m_pyImp(scr)
{
}

PyDbObjectId PyBrxConstraintsGroup::getBlockId() const
{
    return PyDbObjectId(impObj()->getBlockId());
}

bool PyBrxConstraintsGroup::hasSketchPlane() const
{
    return impObj()->hasSketchPlane();
}

bool PyBrxConstraintsGroup::isTransient() const
{
    return impObj()->hasSketchPlane();
}

PyGePlane PyBrxConstraintsGroup::getSketchPlane() const
{
    return PyGePlane(impObj()->getSketchPlane());
}

boost::python::list PyBrxConstraintsGroup::constraints() const
{
    PyAutoLockGIL lock;
    boost::python::list pylist;
    for (auto& item : impObj()->constraints())
    {
        if (item.refCount() != 1)
            PyThrowBadEs(eInvalidOpenState);
        pylist.append(PyBrxConstraint(item.detach()));
    }
    return pylist;
}

PyBrxConstraint PyBrxConstraintsGroup::getConstraintByNodeId(Adesk::UInt32 nodeId) const
{
    auto result = impObj()->getConstraintByNodeId(nodeId);
    if (result.refCount() != 1)
        PyThrowBadEs(eInvalidOpenState);
    return PyBrxConstraint(result.detach());
}

PyBrxConstraint PyBrxConstraintsGroup::addConstraintSubents(AcConstraint::ConstraintType type, const boost::python::list& paths) const
{
    auto result = impObj()->addConstraint(type, PyListToPyDbFullSubentPathArray(paths));
    if (result.refCount() != 1)
        PyThrowBadEs(eInvalidOpenState);
    return PyBrxConstraint(result.detach());
}

PyBrxConstraint PyBrxConstraintsGroup::addConstraintArgs(AcConstraint::ConstraintType type, const boost::python::list& arguments) const
{
    AcConstraintArgumentArray arr;
    const auto& vec = py_list_to_std_vector<PyBrxConstraintArgument>(arguments);
    for (const auto& item : vec)
        arr.append(item.m_imp);
    auto result = impObj()->addConstraint(type, arr);
    if (result.refCount() != 1)
        PyThrowBadEs(eInvalidOpenState);
    return PyBrxConstraint(result.detach());
}

void PyBrxConstraintsGroup::deleteConstraint(const PyBrxConstraint& pConstraint) const
{
    PyThrowBadEs(impObj()->deleteConstraint(pConstraint.impObj()));
}

void PyBrxConstraintsGroup::evaluate() const
{
    PyThrowBadEs(impObj()->evaluate());
}

std::string PyBrxConstraintsGroup::className()
{
    return "AcConstraintsGroup";
}

AcConstraintsGroup* PyBrxConstraintsGroup::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcConstraintsGroup*>(m_pyImp.get());
}

#endif
