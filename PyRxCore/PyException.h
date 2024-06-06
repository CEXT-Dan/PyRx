#pragma once
#include <exception>

#pragma pack (push, 8)

static std::string appHostName()
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
inline CStringA formatfname(const char* pname)
{
    CStringA str = pname;
    str.Replace("class", "");
    str.Replace("__cdecl", "");
    str.Replace("const", "");
    str.Replace("&", "");
    while (str.Replace("  ", " "));
    str.Trim();
    return str;
}

inline void printExceptionMsg(const std::source_location& src = std::source_location::current())
{
    constexpr std::string_view fmtstr("\nException,line {}, in function {} {}: ");
    const auto& fname = formatfname(src.function_name());
    acutPrintf(utf8_to_wstr(std::format(fmtstr, src.line(), (const char*)fname, src.file_name())).c_str());
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

struct PyAcadErrorStatus
{
    Acad::ErrorStatus m_es;
    std::source_location m_src;

    explicit PyAcadErrorStatus(Acad::ErrorStatus es, const std::source_location& src = std::source_location::current())
        : m_es(es), m_src(src) {}

    inline std::string format() const
    {
        constexpr std::string_view fmtstr("\nException!({}), function {}, Line {}, File {}: ");
        const std::filesystem::path file = m_src.file_name();
        const auto& fname = formatfname(m_src.function_name());
        return std::format(fmtstr, wstr_to_utf8(acadErrorStatusText(m_es)), (const char*)fname, m_src.line(), file.filename().string());
    }

    inline static void translator(PyAcadErrorStatus const& x)
    {
        PyErr_SetString(PyExc_RuntimeError, x.format().c_str());
    }
};

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
#pragma pack (pop)