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
    PyBrxConstraintArgument(const PyDbFullSubentPath& path,AcConstraintArgument::CoordinateSystemObject cs);

    PyDbFullSubentPath path() const;
    bool isCoordinateSystemObject() const;
    AcConstraintArgument::CoordinateSystemObject coordinateSystemObject() const;

    static std::string className();

public:
    AcConstraintArgument m_imp;
};

#endif