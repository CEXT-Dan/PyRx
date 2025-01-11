#pragma once

#ifdef PYRX_IN_PROGRESS_PYAX

class PyIAcadObjectImpl;
class PyDbObjectId;
//----------------------------------------------------------------------------------------
//PyAcadObject
void makePyAcadObjectWrapper();

class PyAcadObject
{
public:
    PyAcadObject(PyIAcadObjectImpl* ptr);
    PyAcadObject(const AcDbObjectId& id);
    virtual ~PyAcadObject() = default;

    PyDbHandle          handle() const;
    std::string         objectName() const;
    PyDbObjectId        objectId() const;
    boost::python::list getXData(const std::string& appName);
    void                setXdata(const boost::python::list& pylist);

    static PyAcadObject cast(const PyAcadObject& src);
    static std::string  className();
public:
    PyIAcadObjectImpl* impObj(const std::source_location& src = std::source_location::current()) const;

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