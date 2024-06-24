#pragma once


#if defined(_ARXTARGET) || defined(_BRXTARGET) 

class PySmPersistImpl;

//-----------------------------------------------------------------------------------------
//PySmPersist
void makePySmPersistWrapper();
class PySmPersist
{
public:
    PySmPersist(PySmPersistImpl* ptr);

    std::string        getTypeName() const;
    static std::string className();
public:
    inline PySmPersistImpl* impObj(const std::source_location& src = std::source_location::current()) const;
    std::shared_ptr<PySmPersistImpl> m_pyImp = nullptr;
};

#endif