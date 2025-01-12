#pragma once

#ifdef PYRX_IN_PROGRESS_PYAX

class PyAcadApplicationImpl;


//----------------------------------------------------------------------------------------
//PyAcadApplication
void makePyAcadApplicationWrapper();

class PyAcadApplication
{
public:
    PyAcadApplication();
    virtual ~PyAcadApplication() = default;

    void                    eval(const std::string& sval) const;
    //PyAcadStateImpl         GetAcadState();
    boost::python::list     listArx() const;;
  
    static std::string      className();

    //internal 
    static bool             runTest(const AcDbObjectId& id);
public:

    PyAcadApplicationImpl*  impObj(const std::source_location& src = std::source_location::current()) const;

public:
    std::shared_ptr<PyAcadApplicationImpl> m_pyImp;
};


#endif
