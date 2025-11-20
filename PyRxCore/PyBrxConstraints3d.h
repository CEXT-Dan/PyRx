#pragma once

#ifdef BRXAPP
#include "AcConstraints3d.h"

//---------------------------------------------------------------------
//PyBrxConstraintArgument
void makePyBrxConstraintArgument();

class PyBrxConstraintArgument
{
public:
    PyBrxConstraintArgument();
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

#endif