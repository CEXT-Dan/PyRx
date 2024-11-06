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
//PyNotThatKindOfClass
struct PyNotThatKindOfClass
{
    std::source_location m_src;

    PyNotThatKindOfClass(const std::source_location& src = std::source_location::current())
        :m_src(src)
    {
    }

    inline std::string format() const
    {
        constexpr std::string_view fmtstr("\nNot that kind of class! in function {} {}: ");
        const std::filesystem::path file = m_src.file_name();
        const auto& fname = formatfname(m_src.function_name());
        return std::format(fmtstr, (const char*)fname, file.filename().string());
    }

    static void translator(PyNotThatKindOfClass const& x)
    {
        PyErr_SetString(PyExc_RuntimeError, "\nNot that kind of class!");
    }
};

//-----------------------------------------------------------------------------------
//PyNullObject
struct PyNullObject
{
    std::source_location m_src;

    PyNullObject(const std::source_location& src = std::source_location::current())
        :m_src(src)
    {
    }

    inline std::string format() const
    {
        constexpr std::string_view fmtstr("\nException! Object is NULL, in function {}, Line {}, File {}: ");
        const std::filesystem::path file = m_src.file_name();
        const auto& fname = formatfname(m_src.function_name());
        return std::format(fmtstr, (const char*)fname, m_src.line(), file.filename().string());
    }

    static void translator(PyNullObject const& x)
    {
        PyErr_SetString(PyExc_RuntimeError, x.format().c_str());
    }
};

//-----------------------------------------------------------------------------------
//PyEditorError
struct PyEditorError
{
    std::source_location m_src;

    PyEditorError(const std::source_location& src = std::source_location::current())
        :m_src(src)
    {
    }

    inline std::string format() const
    {
        constexpr std::string_view fmtstr("\nEditor error! function {} {}: ");
        const std::filesystem::path file = m_src.file_name();
        const auto& fname = formatfname(m_src.function_name());
        return std::format(fmtstr, (const char*)fname, file.filename().string());
    }

    static void translator(PyEditorError const& x)
    {
        PyErr_SetString(PyExc_RuntimeError, x.format().c_str());
    }
};

//-----------------------------------------------------------------------------------
//PyAcadHrError
struct PyAcadHrError
{
    HRESULT m_hr;
    std::source_location m_src;

    explicit PyAcadHrError(const HRESULT hr, const std::source_location& src = std::source_location::current())
        : m_hr(hr), m_src(src) {}

    inline std::string format() const
    {
        constexpr std::string_view fmtstr("\nException!({}), function {}, Line {}, File {}: ");
        const std::filesystem::path file = m_src.file_name();
        const auto& fname = formatfname(m_src.function_name());
        return std::format(fmtstr, std::system_category().message(m_hr), (const char*)fname, m_src.line(), file.filename().string());
    }

    inline static void translator(PyAcadHrError const& x)
    {
        PyErr_SetString(PyExc_RuntimeError, x.format().c_str());
    }
};

//-----------------------------------------------------------------------------------
//PyAcadHrError
struct PyNotimplementedByHost
{
    const std::source_location m_src;

    PyNotimplementedByHost(const std::source_location& src = std::source_location::current())
        :m_src(src)
    {
    }

    inline std::string format() const
    {
        constexpr std::string_view fmtstr("\nException, Not implemented in {}!, function {} ,Line {}, File {}: ");
        const std::filesystem::path file = m_src.file_name();
        const auto& fname = formatfname(m_src.function_name());
        return std::format(fmtstr, appHostName(), (const char*)fname, m_src.line(), file.filename().string());
    }

    inline static void translator(PyNotimplementedByHost const& x)
    {
        PyErr_SetString(PyExc_RuntimeError, x.format().c_str());
    }
};

#if defined(_BRXTARGET)
//-----------------------------------------------------------------------------------
//PyBrxBimError
struct PyBrxBimError
{
    BimApi::ResultStatus m_rs;
    std::source_location m_src;

    explicit PyBrxBimError(const BimApi::ResultStatus rs, const std::source_location& src = std::source_location::current())
        : m_rs(rs), m_src(src) {}

    inline std::string format() const
    {
        constexpr std::string_view fmtstr("\nException!({}), function {}, Line {}, File {}: ");
        const std::filesystem::path file = m_src.file_name();
        const auto& fname = formatfname(m_src.function_name());
        return std::format(fmtstr, brxBimStatusText(m_rs), (const char*)fname, m_src.line(), file.filename().string());
    }

    inline static void translator(PyBrxBimError const& x)
    {
        PyErr_SetString(PyExc_RuntimeError, x.format().c_str());
    }
};

inline void PyThrowBadBim(BimApi::ResultStatus hr, const std::source_location& src = std::source_location::current())
{
    if (FAILED(hr)) [[unlikely]]
        throw PyAcadHrError(hr, src);
}
#endif

//-----------------------------------------------------------------------------------
//PyErrorStatusException
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

    static PyObject*    createPyErrorStatusExceptionClass(const char* name, PyObject* baseTypeObj = PyExc_Exception);
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