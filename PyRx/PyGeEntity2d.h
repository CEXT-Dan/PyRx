#pragma once

class PyGeLine2d;
//-----------------------------------------------------------------------------------------
//PyGeEntity2d wrapper
void makePyGeEntity2dWrapper();

class PyGeEntity2d
{
protected:
    PyGeEntity2d() = default;
public:
    PyGeEntity2d(AcGeEntity2d* pEnt);

    bool operator==(PyGeEntity2d const& rhs) const;
    bool operator!=(PyGeEntity2d const& rhs) const;

    Adesk::Boolean isKindOf(AcGe::EntityId entType) const;
    AcGe::EntityId type() const;
    PyGeEntity2d copy() const;
    Adesk::Boolean isEqualTo1(const PyGeEntity2d& ent) const;
    Adesk::Boolean isEqualTo2(const PyGeEntity2d& ent, const AcGeTol& tol) const;

    PyGeEntity2d& transformBy(const AcGeMatrix2d& xfm);
    PyGeEntity2d& translateBy(const AcGeVector2d& translateVec);

    PyGeEntity2d& rotateBy1(double angle);
    PyGeEntity2d& rotateBy2(double angle, const AcGePoint2d& origin);

    PyGeEntity2d& mirror(const PyGeLine2d& plane);

    PyGeEntity2d& scaleBy1(double scaleFactor);
    PyGeEntity2d& scaleBy2(double scaleFactor, const AcGePoint2d& wrtPoint);

    Adesk::Boolean isOn1(const AcGePoint2d& pnt) const;
    Adesk::Boolean isOn2(const AcGePoint2d& pnt, const AcGeTol& tol) const;

    bool isNull()const;
    static std::string className();
public:
    AcGeEntity2d* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<AcGeEntity2d> m_imp;
};

