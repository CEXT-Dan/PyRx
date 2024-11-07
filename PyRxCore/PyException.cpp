#include "stdafx.h"
#include "PyException.h"

using namespace boost::python;

#if defined(_BRXTARGET)
const char* brxBimStatusText(const BimApi::ResultStatus stat) noexcept
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
#endif //_BRXTARGET

CStringA formatfname(const char* pname)
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

void printExceptionMsg(const std::source_location& src /*= std::source_location::current()*/)
{
    constexpr std::string_view fmtstr("\nException,line {}, in function {} {}: ");
    const auto& fname = formatfname(src.function_name());
    acutPrintf(utf8_to_wstr(std::format(fmtstr, src.line(), (const char*)fname, src.file_name())).c_str());
}

//-----------------------------------------------------------------------------------
// PyNullObject
PyNullObject::PyNullObject(const std::source_location& src /*= std::source_location::current()*/)
    :m_src(src)
{
}

std::string PyNullObject::format() const
{
    constexpr std::string_view fmtstr("\nException! Object is NULL, in function {}, Line {}, File {}: ");
    const std::filesystem::path file = m_src.file_name();
    const auto& fname = formatfname(m_src.function_name());
    return std::format(fmtstr, (const char*)fname, m_src.line(), file.filename().string());
}

void PyNullObject::translator(const PyNullObject& x)
{
    PyErr_SetString(PyExc_RuntimeError, x.format().c_str());
}

//-----------------------------------------------------------------------------------
// PyAcadHrError
PyAcadHrError::PyAcadHrError(const HRESULT hr, const std::source_location& src /*= std::source_location::current()*/)
    : m_hr(hr), m_src(src) {}

std::string PyAcadHrError::format() const
{
    constexpr std::string_view fmtstr("\nException!({}), function {}, Line {}, File {}: ");
    const std::filesystem::path file = m_src.file_name();
    const auto& fname = formatfname(m_src.function_name());
    return std::format(fmtstr, std::system_category().message(m_hr), (const char*)fname, m_src.line(), file.filename().string());
}

void PyAcadHrError::translator(const PyAcadHrError& x)
{
    PyErr_SetString(PyExc_RuntimeError, x.format().c_str());
}


//-----------------------------------------------------------------------------------
// PyNotimplementedByHost
PyNotimplementedByHost::PyNotimplementedByHost(const std::source_location& src /*= std::source_location::current()*/)
    :m_src(src)
{
}

std::string PyNotimplementedByHost::format() const
{
    constexpr std::string_view fmtstr("\nException, Not implemented in {}!, function {} ,Line {}, File {}: ");
    const std::filesystem::path file = m_src.file_name();
    const auto& fname = formatfname(m_src.function_name());
    return std::format(fmtstr, appHostName(), (const char*)fname, m_src.line(), file.filename().string());
}

void PyNotimplementedByHost::translator(const PyNotimplementedByHost& x)
{
    PyErr_SetString(PyExc_RuntimeError, x.format().c_str());
}

#if defined(_BRXTARGET)

//-----------------------------------------------------------------------------------
// PyBrxBimError
PyBrxBimError::PyBrxBimError(const BimApi::ResultStatus rs, const std::source_location& src /*= std::source_location::current()*/)
    : m_rs(rs), m_src(src) {}


std::string PyBrxBimError::format() const
{
    constexpr std::string_view fmtstr("\nException!({}), function {}, Line {}, File {}: ");
    const std::filesystem::path file = m_src.file_name();
    const auto& fname = formatfname(m_src.function_name());
    return std::format(fmtstr, brxBimStatusText(m_rs), (const char*)fname, m_src.line(), file.filename().string());
}

void PyBrxBimError::translator(const PyBrxBimError& x)
{
    PyErr_SetString(PyExc_RuntimeError, x.format().c_str());
}

#endif
//-----------------------------------------------------------------------------------
// PyErrorStatusException
PyErrorStatusException::PyErrorStatusException(Acad::ErrorStatus es, const std::source_location& src /*= std::source_location::current()*/)
    : m_es(es), m_src(src)
{
    m_fmt = format();
}

const char* PyErrorStatusException::what() const noexcept
{
    return m_fmt.c_str();
}

std::string PyErrorStatusException::fullmessage() const
{
    return m_fmt;
}

Acad::ErrorStatus PyErrorStatusException::code() const
{
    return m_es;
}

PyObject* PyErrorStatusException::createPyErrorStatusExceptionClass()
{
    PyAutoLockGIL lock;
    constexpr const char* name = "ErrorStatusException";
    constexpr const char* qualifiedName = "PyDb.ErrorStatusException";
    PyObject* typeObj = PyErr_NewException(qualifiedName, PyExc_RuntimeError, 0);
    if (!typeObj)
        throw_error_already_set();
    scope().attr(name) = handle<>(borrowed(typeObj));
    return typeObj;
}

void PyErrorStatusException::translatePyErrorStatusException(const PyErrorStatusException& e)
{
    PyAutoLockGIL lock;
    boost::python::object exc_t(handle<>(borrowed(PyErrorStatusException::PyErrorStatusExceptionType)));
    exc_t.attr("code") = object(e.code());
    exc_t.attr("message") = object(e.message());
    exc_t.attr("fullmessage") = object(e.fullmessage());
    PyErr_SetString(PyErrorStatusException::PyErrorStatusExceptionType, e.what());
}

std::string PyErrorStatusException::message() const
{
    return wstr_to_utf8(acadErrorStatusText(m_es));
}

std::string PyErrorStatusException::format() const
{
    constexpr std::string_view fmtstr("Exception!({}), function {}, Line {}, File {}: ");
    const std::filesystem::path file = m_src.file_name();
    const auto& fname = formatfname(m_src.function_name());
    return std::format(fmtstr, wstr_to_utf8(acadErrorStatusText(m_es)), (const char*)fname, m_src.line(), file.filename().string());
}

void PyErrorStatusException::makePyErrorStatusExceptionWrapper()
{
    PyErrorStatusException::PyErrorStatusExceptionType = PyErrorStatusException::createPyErrorStatusExceptionClass();
    register_exception_translator<PyErrorStatusException>(&PyErrorStatusException::translatePyErrorStatusException);
}
