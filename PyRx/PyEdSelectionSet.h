#pragma once

class PyDbObjectId;
class AdsName;
typedef std::array<int64_t, 2> PySSName;


void makePyEdSelectionSetWrapper();

//used a shared pointer for reference counting. 
struct PyEdSSDeleter
{
    inline void operator()(PySSName* ss) const
    {
        if (ss != nullptr)
        {
            if (ss->at(0) != 0 && ss->at(1) != 0)
                acedSSFree(ss->data());
            delete ss;
        }
    }
};

class PyEdSelectionSet
{
public:
    PyEdSelectionSet();
    PyEdSelectionSet(const ads_name& ss);
    ~PyEdSelectionSet() = default;
    bool			    isInitialized() const;
    size_t              size();
    void                clear();
    void                add(const PyDbObjectId& objId);
    void                remove(const PyDbObjectId& objId);
    bool                hasMember(const PyDbObjectId& objId);
    AdsName             adsname() const;
    bool                ssSetFirst();
    Acad::PromptStatus  ssXform(const AcGeMatrix3d& xform);
    boost::python::list ssNameX1();
    boost::python::list ssNameX2(int ind);
    boost::python::list objectIds();

public:
    PySSName* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<PySSName> m_pSet;
};

