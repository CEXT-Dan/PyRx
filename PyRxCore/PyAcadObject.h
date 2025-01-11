#pragma once

#ifdef PYRX_IN_PROGRESS_PYAX

class PyIAcadObjectImpl;
//----------------------------------------------------------------------------------------
//PyAcadObject
void makePyAcadObjectWrapper();

class PyAcadObject
{
public:
    PyAcadObject(PyIAcadObjectImpl* ptr);
    PyAcadObject(const AcDbObjectId& id);
    virtual ~PyAcadObject() = default;

    std::string  handle() const;

    static PyAcadObject cast(const PyAcadObject& src);
    static std::string  className();
public:
    PyIAcadObjectImpl*  impObj(const std::source_location& src = std::source_location::current()) const;

public:
    std::shared_ptr<PyIAcadObjectImpl> m_pyImp;
};

template<typename T>
inline T PyAcadObjectCast(const PyAcadObject& src)
{
    T dest(nullptr);
    PyAcadObject tdbo = src;
    std::swap(tdbo.m_pyImp, dest.m_pyImp);
    return dest;
}


#endif