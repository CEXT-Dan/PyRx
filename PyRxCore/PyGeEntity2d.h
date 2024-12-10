#pragma once

#pragma pack (push, 8)
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
    PyGeEntity2d(const AcGeEntity2d* pEnt);
    virtual ~PyGeEntity2d() = default;
    bool operator==(PyGeEntity2d const& rhs) const;
    bool operator!=(PyGeEntity2d const& rhs) const;
    Adesk::Boolean      isKindOf(AcGe::EntityId entType) const;
    AcGe::EntityId      type() const;
    PyGeEntity2d        copy() const;
    Adesk::Boolean      isEqualTo1(const PyGeEntity2d& ent) const;
    Adesk::Boolean      isEqualTo2(const PyGeEntity2d& ent, const AcGeTol& tol) const;
    void                transformBy(const AcGeMatrix2d& xfm);
    void                translateBy(const AcGeVector2d& translateVec);
    void                rotateBy1(double angle);
    void                rotateBy2(double angle, const AcGePoint2d& origin);
    void                mirror(const PyGeLine2d& plane);
    void                scaleBy1(double scaleFactor);
    void                scaleBy2(double scaleFactor, const AcGePoint2d& wrtPoint);
    Adesk::Boolean      isOn1(const AcGePoint2d& pnt) const;
    Adesk::Boolean      isOn2(const AcGePoint2d& pnt, const AcGeTol& tol) const;
    bool                isNull()const;
    std::size_t         hash() const;
    static PyGeEntity2d copycast(const PyGeEntity2d& src);
    static std::string  className();
public:
    AcGeEntity2d* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<AcGeEntity2d> m_imp;
};

inline AcGeVoidPointerArray PyListToGe2dVoidPointerArray(const boost::python::object& iterable)
{
    const auto& vec = py_list_to_std_vector<PyGeEntity2d>(iterable);
    AcGeVoidPointerArray arr;
    arr.setPhysicalLength(vec.size());
    for (const auto& item : vec)
        arr.append(item.impObj());
    return arr;
}

template<typename T, typename CT>
inline T PyGeEntity2dCast(const PyGeEntity2d& src)
{
    PyGeEntity2d tmp = src;
    AcGeEntity2d* ptr = nullptr;
    T dst(static_cast<CT*>(ptr));
    std::swap(dst.m_imp, tmp.m_imp);
    return dst;
}
#pragma pack (pop)
