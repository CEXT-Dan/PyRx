#pragma once
#pragma pack (push, 8)

#include <exception>
#include <system_error>

struct pysource_location
{
    inline pysource_location(const std::source_location& src)
        : _func(src.function_name()), _line(src.line())
    {
        const std::filesystem::path file = src.file_name();
        _file = file.filename().string();
    }

    inline const char* file_name() const
    {
        return _file.c_str();
    }

    inline const char* function_name() const
    {
        return _func.c_str();
    }

    inline int line() const
    {
        return _line;
    }

    std::string _file;
    std::string _func;
    int _line = -1;
};

const char* acadBrStatusText(const AcBr::ErrorStatus stat) noexcept;

#if defined(_BRXTARGET)
#include "BimDefs.h"
const char* brxBimStatusText(const BimApi::ResultStatus stat) noexcept;
#endif

inline const char* appHostName()
{
#ifdef _ZRXTARGET 
    return "ZRX";
#endif
#ifdef _IRXTARGET 
    return "IRX";
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
void printExceptionMsg(const std::source_location& src = std::source_location::current());

//-----------------------------------------------------------------------------------
// PyNullObject
class PyNullObject
{
    pysource_location m_src;
    std::string m_fmt;

private:
    void generateformat();

public:
    PyNullObject(const std::source_location& src = std::source_location::current());
    std::string format() const;
    static void translator(const PyNullObject& x);
};

//-----------------------------------------------------------------------------------
// PyAcadHrError
class PyAcadHrError
{
    pysource_location m_src;
    std::string m_fmt;
    HRESULT m_hr;

private:
    void generateformat();

public:
    PyAcadHrError(const HRESULT hr, const std::source_location& src = std::source_location::current());
    std::string format() const;
    static void translator(const PyAcadHrError& x);
};

//-----------------------------------------------------------------------------------
// PyNotimplementedByHost
class PyNotimplementedByHost
{
    pysource_location m_src;
    std::string m_fmt;
private:
    void generateformat();

public:
    PyNotimplementedByHost(const std::source_location& src = std::source_location::current());
    std::string format() const;
    static void translator(const PyNotimplementedByHost& x);
};

//-----------------------------------------------------------------------------------
// PyBrxBimError
#if defined(_BRXTARGET)
class PyBrxBimError
{
    pysource_location m_src;
    std::string m_fmt;
    BimApi::ResultStatus m_rs;

private:
    void generateformat();

public:
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

    static PyObject* createPyErrorStatusExceptionClass();
    static void      translatePyErrorStatusException(const PyErrorStatusException& e);
    static void      makePyErrorStatusExceptionWrapper();

private:
    void generateformat();
    // TODO: This will block unloading if we ever get that working?
    inline static PyObject* PyErrorStatusExceptionType = nullptr;
private:
    pysource_location m_src;
    std::string m_fmt;
    Acad::ErrorStatus m_es = eNotImplementedYet;
};

//-----------------------------------------------------------------------------------
// PyBrErrorStatusException
class PyBrErrorStatusException : public std::exception
{
public:
    PyBrErrorStatusException(AcBr::ErrorStatus es, const std::source_location& src = std::source_location::current());
    virtual ~PyBrErrorStatusException() noexcept override = default;
    virtual const char* what() const noexcept override;
    std::string         fullmessage() const;
    std::string         message() const;
    std::string         format() const;
    AcBr::ErrorStatus   code() const;

    static PyObject* createPyBrErrorStatusExceptionClass();
    static void      translatePyBrErrorStatusException(const PyBrErrorStatusException& e);
    static void      makePyBrErrorStatusExceptionWrapper();

private:
    void generateformat();
    // TODO: This will block unloading if we ever get that working?
    inline static PyObject* PyBrErrorStatusExceptionType = nullptr;
private:
    pysource_location m_src;
    std::string m_fmt;
    AcBr::ErrorStatus m_es = AcBr::eNotApplicable;
};

//-----------------------------------------------------------------------------------
// PyRxEKeyError
class PyRxEKeyError : std::exception
{
public:
    explicit PyRxEKeyError(const std::string& key, const std::source_location& src = std::source_location::current());
    void        generateformat();
    const char* what() const noexcept;
    static void translate(const PyRxEKeyError& e);

private:
    std::string m_key;
    std::string m_fmt;
    pysource_location m_src;
};

//-----------------------------------------------------------------------------------
// function helpers
inline void PyThrowBadHr(HRESULT hr, const std::source_location& src = std::source_location::current())
{
    if (FAILED(hr)) [[unlikely]]
        throw PyAcadHrError(hr, src);
}

inline void PyThrowBadBr(AcBr::ErrorStatus es, const std::source_location& src = std::source_location::current())
{
    if (es != eOk) [[unlikely]]
        throw PyBrErrorStatusException(es, src);
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