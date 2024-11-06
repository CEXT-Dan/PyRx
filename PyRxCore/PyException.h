#pragma once
#pragma pack (push, 8)

#include <exception>
#include <system_error>

#if defined(_BRXTARGET)
#include "BimDefs.h"
const char* brxBimStatusText(const BimApi::ResultStatus stat) noexcept;
#endif

consteval const char* appHostName()
{
#ifdef _ZRXTARGET 
    return "ZRX";
#endif
#ifdef _GRXTARGET 
    return "GRX";
#endif
#ifdef _BRXTARGET 
    return "BRX";
#endif
    return "ARX";
}

//TODO:
CStringA    formatfname(const char* pname);
void        printExceptionMsg(const std::source_location& src = std::source_location::current());

//-----------------------------------------------------------------------------------
// PyNullObject
struct PyNullObject
{
    const std::source_location& m_src;

    PyNullObject(const std::source_location& src = std::source_location::current());
    std::string format() const;
    static void translator(const PyNullObject& x);
};

//-----------------------------------------------------------------------------------
// PyAcadHrError
struct PyAcadHrError
{
    HRESULT m_hr;
    const std::source_location& m_src;

    PyAcadHrError(const HRESULT hr, const std::source_location& src = std::source_location::current());
    std::string format() const;
    static void translator(const PyAcadHrError& x);
};

//-----------------------------------------------------------------------------------
// PyNotimplementedByHost
struct PyNotimplementedByHost
{
    const std::source_location& m_src;

    PyNotimplementedByHost(const std::source_location& src = std::source_location::current());
    std::string format() const;
    static void translator(const PyNotimplementedByHost& x);
};

#if defined(_BRXTARGET)

//-----------------------------------------------------------------------------------
// PyBrxBimError
struct PyBrxBimError
{
    BimApi::ResultStatus m_rs;
    const std::source_location& m_src;

    PyBrxBimError(const BimApi::ResultStatus rs, const std::source_location& src = std::source_location::current());
    std::string format() const;
    static void translator(const PyBrxBimError& x);
};

inline void PyThrowBadBim(BimApi::ResultStatus hr, const std::source_location& src = std::source_location::current())
{
    if (FAILED(hr)) [[unlikely]]
        throw PyAcadHrError(hr, src);
}

#endif

//-----------------------------------------------------------------------------------
// PyErrorStatusException
class PyErrorStatusException : public std::exception
{
public:
    PyErrorStatusException(Acad::ErrorStatus es, const std::source_location& src = std::source_location::current());
    virtual ~PyErrorStatusException() noexcept override = default;
    virtual const char* what() const noexcept override;
    std::string         fullmessage() const;
    std::string         message() const;
    std::string         format() const;
    Acad::ErrorStatus   code() const;

    static PyObject*    createPyErrorStatusExceptionClass(const char* name, PyObject* baseTypeObj = PyExc_RuntimeError);
    static void         translatePyErrorStatusException(const PyErrorStatusException& e);
    static void         makePyErrorStatusExceptionWrapper();

private:
    // TODO: This will block unloading if we ever get that working?
    inline static PyObject* PyErrorStatusExceptionType = nullptr;
private:
    Acad::ErrorStatus m_es = Acad::eNotImplemented;
    const std::source_location& m_src;
    std::string m_fmt;
};


//-----------------------------------------------------------------------------------
// function helpers
inline void PyThrowBadHr(HRESULT hr, const std::source_location& src = std::source_location::current())
{
    if (FAILED(hr)) [[unlikely]]
        throw PyAcadHrError(hr, src);
}

inline void PyThrowBadEs(Acad::ErrorStatus es, const std::source_location& src = std::source_location::current())
{
    if (es != eOk) [[unlikely]]
        throw PyErrorStatusException(es, src);
}

inline void PyThrowBadRt(int es, const std::source_location& src = std::source_location::current())
{
    if (es != RTNORM) [[unlikely]]
        throw PyErrorStatusException(eInvalidInput, src);
}

inline void PyThrowFalse(bool es, const std::source_location& src = std::source_location::current())
{
    if (es == false) [[unlikely]]
        throw PyErrorStatusException(eInvalidInput, src);
}
#pragma pack (pop)