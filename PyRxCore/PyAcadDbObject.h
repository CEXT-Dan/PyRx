#pragma once

#pragma pack (push, 8)
class PyDbObjectId;
class PyIAcadObjectImpl;
class PyAcadDatabase;
class PyAcadDocument;
class PyAcadDictionary;
class PyIAcadBlockImpl;
class PyAcadEntity;

//----------------------------------------------------------------------------------------
//PyAcadObject
void makePyAcadObjectWrapper();

class PyAcadObject
{
public:
    PyAcadObject() = default;
    PyAcadObject(std::shared_ptr<PyIAcadObjectImpl> ptr);
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
    PyAcadDatabase      database() const;
    bool                hasExtensionDictionary() const;
    //PyAcadDictionary    extensionDictionary() const;
    PyAcadDocument      document() const;
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
    T dest;
    PyAcadObject tdbo = src;
    std::swap(tdbo.m_pyImp, dest.m_pyImp);
    return dest;
}

//----------------------------------------------------------------------------------------
//PyAcadBlock
void makePyAcadBlockWrapper();

class PyAcadBlock : public PyAcadObject
{
public:
    PyAcadBlock() = default;
    PyAcadBlock(std::shared_ptr<PyIAcadBlockImpl> ptr);
    virtual ~PyAcadBlock() = default;
    long            count() const;
    PyAcadEntity    item(long ind) const;
    static PyAcadBlock cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadBlockImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};



#pragma pack (pop)
