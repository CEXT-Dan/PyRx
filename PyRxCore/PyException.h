#pragma once
#include <exception>
#include <system_error>

#pragma pack (push, 8)

#if defined(_BRXTARGET)
#include "BimDefs.h"

inline constexpr const char* brxBimStatusText(const BimApi::ResultStatus stat) noexcept
{
    switch (stat)
    {
        default:
            return "Unknown";
        case BimApi::eOk:
            return "eOk";
        case BimApi::eNoDbResidentObject:
            return "eNoDbResidentObject";
        case BimApi::eDbNotAccessible:
            return "eDbNotAccessible";
        case BimApi::eDbObjectNotSupported:
            return "eDbObjectNotSupported";
        case BimApi::eDbNotOpenForWrite:
            return "eDbNotOpenForWrite";
        case BimApi::eModelSpaceNotAccessible:
            return "eModelSpaceNotAccessible";
        case BimApi::eProjectDbNotAccessible:
            return "eProjectDbNotAccessible";
        case BimApi::eAssociatedLibraryNotAccessible:
            return "eAssociatedLibraryNotAccessible";
        case BimApi::eNotApplicableForTheseParameters:
            return "eNotApplicableForTheseParameters";
        case BimApi::eInvalidSpatialLocation:
            return "eInvalidSpatialLocation";
        case BimApi::eInvalidMaterial:
            return "eInvalidMaterial";
        case BimApi::eInvalidMaterialComposition:
            return "eInvalidMaterialComposition";
        case BimApi::eObjectAlreadyExists:
            return "eObjectAlreadyExists";
        case BimApi::eObjectCouldNotBeDeleted:
            return "eObjectCouldNotBeDeleted";
        case BimApi::eXmlFileCouldNotBeParsed:
            return "eXmlFileCouldNotBeParsed";
        case BimApi::eInvalidXmlFormat:
            return "eInvalidXmlFormat";
        case BimApi::eInvalidName:
            return "eInvalidName";
        case BimApi::eNotLinearBuildingElement:
            return "eNotLinearBuildingElement";
        case BimApi::eInvalidValue:
            return "eInvalidValue";
        case BimApi::eNotAssignedToLibrary:
            return "eNotAssignedToLibrary";
        case BimApi::eNullObject:
            return "eNullObject";
        case BimApi::eNullObjectId:
            return "eNullObjectId";
        case BimApi::eNullDatabase:
            return "eNullDatabase";
        case BimApi::eNullDocument:
            return "eNullDocument";
        case BimApi::eNullString:
            return "eNullString";
        case BimApi::eObjectNotExisting:
            return "eObjectNotExisting";
        case BimApi::eObjectNotSupported:
            return "eObjectNotSupported";
        case BimApi::eNoProfileAssigned:
            return "eNoProfileAssigned";
        case BimApi::eNoData:
            return "eNoData";
        case BimApi::eUnknownData:
            return "eUnknownData";
        case BimApi::eWrongDataType:
            return "eWrongDataType";
        case BimApi::eUnassignedEntity:
            return "eUnassignedEntity";
        case BimApi::eBimNotImplementedYet:
            return "eBimNotImplementedYet";
        case BimApi::eBimNotAvailable:
            return "eBimNotAvailable";
        case BimApi::eInternalError:
            return "eInternalError";
        case BimApi::eUnknownError:
            return "eUnknownError";
        case BimApi::eInvalidIndex:
            return "eInvalidIndex";
        case BimApi::eInvalidInput:
            return "eInvalidInput";
        case BimApi::eNoNameSpace:
            return "eNoNameSpace";
        case BimApi::eNameSpaceAlreadyExists:
            return "eNameSpaceAlreadyExists";
        case BimApi::eNoPropertySet:
            return "eNoPropertySet";
        case BimApi::ePropertySetAlreadyExists:
            return "ePropertySetAlreadyExists";
        case BimApi::eNoProperty:
            return "eNoProperty";
        case BimApi::eNotImplemented:
            return "eNotImplemented";
        case BimApi::eInvalidArgument:
            return "eInvalidArgument";
        case BimApi::eNoAttributeSet:
            return "eNoAttributeSet";
        case BimApi::eAttributeSetAlreadyExists:
            return "eAttributeSetAlreadyExists";
    }
    return "Unknown";
}
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
inline CStringA formatfname(const char* pname)
{
    CStringA str = pname;
    str.Replace("class", "");
    str.Replace("__cdecl", "");
    str.Replace("const", "");
    str.Replace("&", "");
    str.Replace("std::basic_string< char,struct std::char_traits<char>, std::allocator<char> >", "std::string");
    str.Replace("std::basic_string<char,struct std::char_traits<char>, std::allocator<char> >", "std::string");
    str.Replace("std::basic_string<char,struct std::char_traits<char>, std::allocator<char>>", "std::string");
    str.Replace("ATL::CStringT< wchar_t, StrTraitMFC_DLL<wchar_t, ATL::ChTraitsCRT<wchar_t> > >", "CString");
    str.Replace("ATL::CStringT<wchar_t, StrTraitMFC_DLL<wchar_t, ATL::ChTraitsCRT<wchar_t> > >", "CString");
    str.Replace("ATL::CStringT<wchar_t, StrTraitMFC_DLL<wchar_t, ATL::ChTraitsCRT<wchar_t>>>", "CString");
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


inline void PyThrowBadHr(HRESULT hr, const std::source_location& src = std::source_location::current())
{
    if (FAILED(hr)) [[unlikely]]
        throw PyAcadHrError(hr, src);
}

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

inline void PyThrowFalse(bool es, const std::source_location& src = std::source_location::current())
{
    if (es == false) [[unlikely]]
        throw PyAcadErrorStatus(eInvalidInput, src);
}
#pragma pack (pop)