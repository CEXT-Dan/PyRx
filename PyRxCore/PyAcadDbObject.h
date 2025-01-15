#pragma once

#pragma pack (push, 8)
class PyDbObjectId;
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
    bool operator==(const PyAcadObject& rhs) const;
    bool operator!=(const PyAcadObject& rhs) const;
    std::size_t         hash() const;
    PyDbHandle          handle() const;
    std::string         objectName() const;
    PyDbObjectId        objectId() const;
    PyDbObjectId        ownerId() const;
    boost::python::list getXData(const std::string& appName);
    void                setXdata(const boost::python::list& pylist);
    void                clear();

    //PyAcadApplication   application() const;
    //PyIAcadDatabase     database() const;
    bool                hasExtensionDictionary() const;
    //PyIAcadDictionary   extensionDictionary() const;
   // PyIAcadDocument     document() const;
    void                erase();
    bool                isEqualTo(const PyAcadObject& other);
    bool                isNull();

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

#pragma pack (pop)
