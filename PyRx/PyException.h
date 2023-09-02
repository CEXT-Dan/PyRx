#pragma once
#include <exception>

static std::string appHostName()
{
    return "ARX";
}

inline void printExceptionMsg(const std::source_location& src = std::source_location::current())
{
    static constexpr const char* fmtstr = "\nException,line {} in function {} {}: ";
    acutPrintf(utf8_to_wstr(std::format(fmtstr, src.line(), src.function_name(), src.file_name())).c_str());
}

struct PyNotThatKindOfClass
{
    std::source_location m_src;

    PyNotThatKindOfClass(const std::source_location& src = std::source_location::current())
        :m_src(src)
    {
    }

    inline std::string format() const
    {
        static constexpr const char* fmtstr = "\nNot that kind of class! in function {} {}: ";
        const std::filesystem::path file = m_src.file_name();
        return std::format(fmtstr, m_src.function_name(), file.filename().string());
    }

    static void translator(PyNotThatKindOfClass const& x)
    {
        PyErr_SetString(PyExc_RuntimeError, "\nNot that kind of class!");
    }
};

struct PyNullObject
{
    std::source_location m_src;

    PyNullObject(const std::source_location& src = std::source_location::current())
        :m_src(src)
    {
    }

    inline std::string format() const
    {
        static constexpr const char* fmtstr = "\nException,Object is NULL, in function {} {}: ";
        const std::filesystem::path file = m_src.file_name();
        return std::format(fmtstr, m_src.function_name(), file.filename().string());
    }

    static void translator(PyNullObject const& x)
    {
        PyErr_SetString(PyExc_RuntimeError, x.format().c_str());
    }
};

struct PyEditorError
{
    std::source_location m_src;

    PyEditorError(const std::source_location& src = std::source_location::current())
        :m_src(src)
    {
    }

    inline std::string format() const
    {
        static constexpr const char* fmtstr = "\nEditor error! function {} {}: ";
        const std::filesystem::path file = m_src.file_name();
        return std::format(fmtstr, m_src.function_name(), file.filename().string());
    }

    static void translator(PyEditorError const& x)
    {
        PyErr_SetString(PyExc_RuntimeError, x.format().c_str());
    }
};

struct PyAcadErrorStatus
{
    Acad::ErrorStatus m_es;
    std::source_location m_src;

    explicit PyAcadErrorStatus(Acad::ErrorStatus es, const std::source_location& src = std::source_location::current())
        : m_es(es), m_src(src) {}

    inline std::string format() const
    {
        static constexpr const char* fmtstr = "\nException! ({}) in function {} ,Line {}, File {}: ";
        const std::filesystem::path file = m_src.file_name();
        return std::format(fmtstr, wstr_to_utf8(acadErrorStatusText(m_es)), m_src.function_name(), m_src.line(), file.filename().string());
    }

    inline static void translator(PyAcadErrorStatus const& x)
    {
        PyErr_SetString(PyExc_RuntimeError, x.format().c_str());
    }
};

struct PyNotimplementedByHost
{
    std::source_location m_src;

    PyNotimplementedByHost(const std::source_location& src = std::source_location::current())
        :m_src(src)
    {
    }

    inline std::string format() const
    {
        static constexpr const char* fmtstr = "\nException, Not implemented in {}, in function {} {}: ";
        const std::filesystem::path file = m_src.file_name();
        return std::format(fmtstr, appHostName(), m_src.function_name(), file.filename().string());
    }

    inline static void translator(PyNotimplementedByHost const& x)
    {
        PyErr_SetString(PyExc_RuntimeError, x.format().c_str());
    }
};

inline void PyThrowBadEs(Acad::ErrorStatus es, const std::source_location& src = std::source_location::current())
{
    if (es != eOk) [[unlikely]]
        throw PyAcadErrorStatus(es, src);
}

inline void PyThrowBadRt(int es, const std::source_location& src = std::source_location::current())
{
    if (es != RTNORM) [[unlikely]]
        throw PyAcadErrorStatus(eInvalidInput, src);
}