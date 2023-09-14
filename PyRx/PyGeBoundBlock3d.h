#pragma once
#include "PyGeEntity3d.h"

//-----------------------------------------------------------------------------------
//PyGeBoundBlock3d
void makePyGeBoundBlock3dWrapper();
class PyGeBoundBlock3d : public PyGeEntity3d
{
public:
    PyGeBoundBlock3d();
    PyGeBoundBlock3d(const AcGePoint3d& base, const AcGeVector3d& dir1, const AcGeVector3d& dir2, const AcGeVector3d& dir3);
    PyGeBoundBlock3d(AcGeEntity3d* pEnt);
    AcGePoint3d       getMinPoint() const;
    AcGePoint3d       getMaxPoint() const;
    AcGePoint3d       getBasePoint() const;
    AcGeVector3d      getDirection1() const;
    AcGeVector3d      getDirection2() const;
    AcGeVector3d      getDirection3() const;
    void              set1(const AcGePoint3d& point1, const AcGePoint3d& point2);
    void              set2(const AcGePoint3d& base, const AcGeVector3d& dir1, const AcGeVector3d& dir2, const AcGeVector3d& dir3);
    void              extend(const AcGePoint3d& point);
    void              swell(double distance);
    Adesk::Boolean    contains(const AcGePoint3d& point) const;
    Adesk::Boolean    isDisjoint(const PyGeBoundBlock3d& block) const;
    Adesk::Boolean    isBox() const;
    void              setToBox(Adesk::Boolean);
    static std::string className();
public:
    AcGeBoundBlock3d* impObj(const std::source_location& src = std::source_location::current()) const;
};