#pragma once
#include "PyGeEntity2d.h"

//-----------------------------------------------------------------------------------------
//PyGeBoundBlock2d wrapper
void makePyGeBoundBlock2dWrapper();

class PyGeBoundBlock2d : public PyGeEntity2d
{

public:
    PyGeBoundBlock2d();
    PyGeBoundBlock2d(AcGeEntity2d* pEnt);
    PyGeBoundBlock2d(const AcGePoint2d& point1, const AcGePoint2d& point2);
    PyGeBoundBlock2d(const AcGePoint2d& base, const AcGeVector2d& dir1, const AcGeVector2d& dir2);
    PyGeBoundBlock2d(const AcGeBoundBlock2d& block);

    AcGePoint2d getMinPoint() const;
    AcGePoint2d getMaxPoint() const;
    AcGePoint2d getBasePoint() const;
    AcGeVector2d getDirection1() const;
    AcGeVector2d getDirection2() const;

    PyGeBoundBlock2d& set1(const AcGePoint2d& point1, const AcGePoint2d& point2);
    PyGeBoundBlock2d& set2(const AcGePoint2d& base, const AcGeVector2d& dir1, const AcGeVector2d& dir2);

    PyGeBoundBlock2d& extend(const AcGePoint2d& point);
    PyGeBoundBlock2d& swell(double distance);

    Adesk::Boolean    contains(const AcGePoint2d& point) const;
    Adesk::Boolean    isDisjoint(const PyGeBoundBlock2d& block);

    Adesk::Boolean    isBox() const;
    AcGeBoundBlock2d& setToBox(Adesk::Boolean);

    static std::string className();
public:
    AcGeBoundBlock2d* impObj() const;
};

