#pragma once
#include "PyGeEntity3d.h"

#pragma pack (push, 8)
//-----------------------------------------------------------------------------------
//PyGeBoundBlock3d
void makePyGeBoundBlock3dWrapper();
class PyGeBoundBlock3d : public PyGeEntity3d
{
#if !defined(_BRXTARGET260)
public:
    PyGeBoundBlock3d();
    PyGeBoundBlock3d(const AcGePoint3d& base, const AcGeVector3d& dir1, const AcGeVector3d& dir2, const AcGeVector3d& dir3);
    PyGeBoundBlock3d(AcGeEntity3d* pEnt);
    PyGeBoundBlock3d(const AcGeBoundBlock3d& src);
    virtual ~PyGeBoundBlock3d() override = default;
    AcGePoint3d       getMinPoint() const;
    AcGePoint3d       getMaxPoint() const;
    AcGePoint3d       getBasePoint() const;
    AcGeVector3d      getDirection1() const;
    AcGeVector3d      getDirection2() const;
    AcGeVector3d      getDirection3() const;
    void              set1(const AcGePoint3d& point1, const AcGePoint3d& point2) const;
    void              set2(const AcGePoint3d& base, const AcGeVector3d& dir1, const AcGeVector3d& dir2, const AcGeVector3d& dir3) const;
    void              extend(const AcGePoint3d& point) const;
    void              swell(double distance) const;
    Adesk::Boolean    contains(const AcGePoint3d& point) const;
    Adesk::Boolean    isDisjoint(const PyGeBoundBlock3d& block) const;
    Adesk::Boolean    isBox() const;
    void              setToBox(Adesk::Boolean) const;
    static PyGeBoundBlock3d cast(const PyGeEntity3d& src);
    static PyGeBoundBlock3d copycast(const PyGeEntity3d& src);
    static std::string className();
public:
    AcGeBoundBlock3d* impObj(const std::source_location& src = std::source_location::current()) const;
#endif
};
#pragma pack (pop)
