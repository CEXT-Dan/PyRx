#pragma once

#ifdef BRXAPP
#include "AcConstraints3d.h"

class PyGePlane;

//---------------------------------------------------------------------
//PyBrxConstraintArgument
void makePyBrxConstraintArgument();

class PyBrxConstraintArgument
{
public:
    PyBrxConstraintArgument();
    PyBrxConstraintArgument(const AcConstraintArgument& other);
    explicit PyBrxConstraintArgument(const PyDbFullSubentPath& path);
    explicit PyBrxConstraintArgument(AcConstraintArgument::CoordinateSystemObject cs);
    PyBrxConstraintArgument(const PyDbFullSubentPath& path, AcConstraintArgument::CoordinateSystemObject cs);

    PyDbFullSubentPath path() const;
    bool isCoordinateSystemObject() const;
    AcConstraintArgument::CoordinateSystemObject coordinateSystemObject() const;

    static std::string className();

public:
    AcConstraintArgument m_imp;
};

//---------------------------------------------------------------------
//PyBrxVariable
void makePyBrxVariable();

class PyBrxVariable
{
public:
    PyBrxVariable(AcVariable* scr);

    PyDbObjectId    getBlockId() const;
    std::string     name() const;
    void            setName(const std::string& name) const;
    std::string     expression() const;
    void            setExpression(const std::string& expr) const;
    double          value() const;
    void            setValue(double value) const;
    bool            hasLowerBound() const;
    bool            hasUpperBound() const;
    double          lowerBound() const;
    double          upperBound() const;
    void            setLowerBound(double value) const;
    void            setUpperBound(double value) const;
    void            unsetLowerBound() const;
    void            unsetUpperBound() const;
    bool            isAnonymous() const;
    void            erase()  const;
    AcVariable::ExposeMode  exposed() const;
    void                    setExposed(AcVariable::ExposeMode) const;
    AcVariable::EGdMode     geometryDrivenMode() const;
    void                    setGeometryDrivenMode(AcVariable::EGdMode) const;

    static PyBrxVariable  getByName1(const PyDbObjectId& blockId, const std::string& name);
    static PyBrxVariable  getByName2(const PyDbObjectId& blockId, const std::string& name, bool createIfNotExist);
    static boost::python::list getFromBlock(const PyDbObjectId& blockId);

    static std::string className();
public:
    AcVariable* impObj(const std::source_location& src = std::source_location::current()) const;
    std::shared_ptr<AcVariable> m_pyImp;
};

//---------------------------------------------------------------------
//PyBrxConstraint
void makePyBrxConstraint();

class PyBrxConstraint
{
public:
    PyBrxConstraint(AcConstraint* scr);

    PyDbObjectId        getBlockId() const;
    bool                isDimensional() const;
    PyBrxVariable       parameter() const;
    PyDbObjectId        getDimension() const;
    boost::python::list arguments() const;
    boost::python::list getArguments() const;
    std::string         name() const;
    void                setName(const std::string& name) const;
    AcConstraint::ConstraintType getType() const;
    Adesk::UInt32       nodeId() const;
    bool                isEnabled() const;
    void                setEnabled(bool flag) const;
    AcConstraint::Directions getDirections() const;
    void                setDirections(AcConstraint::Directions flag) const;
    AcConstraint::MeasurementMode getMeasurementMode(unsigned int argIndex) const;
    void                setMeasurementMode(AcConstraint::MeasurementMode newMeasureMode, unsigned int argIndex) const;
    AcConstraint::Placement getPlacement(unsigned int argIndex) const;
    void                setPlacement(AcConstraint::Placement newPlacement, unsigned int argIndex) const;

    static std::string className();
public:
    AcConstraint* impObj(const std::source_location& src = std::source_location::current()) const;
    std::shared_ptr<AcConstraint> m_pyImp;
};


//---------------------------------------------------------------------
//PyBrxConstraintsGroup
void makePyBrxConstraintsGroup();

class PyBrxConstraintsGroup
{
public:
    PyBrxConstraintsGroup(AcConstraintsGroup* scr);
    PyDbObjectId        getBlockId() const;
    bool                hasSketchPlane() const;
    bool                isTransient() const;
    PyGePlane           getSketchPlane() const;
    boost::python::list constraints() const;
    PyBrxConstraint     getConstraintByNodeId(Adesk::UInt32 nodeId) const;
    PyBrxConstraint     addConstraintSubents(AcConstraint::ConstraintType type, const boost::python::list& paths) const;
    PyBrxConstraint     addConstraintArgs(AcConstraint::ConstraintType type,const boost::python::list& arguments) const;
    void                deleteConstraint(const PyBrxConstraint& pConstraint) const;
    void                evaluate() const;
    static std::string  className();
public:
    AcConstraintsGroup* impObj(const std::source_location& src = std::source_location::current()) const;
    std::shared_ptr<AcConstraintsGroup> m_pyImp;
};

#endif