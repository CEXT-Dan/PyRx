#include "stdafx.h"
#include "PyException.h"

using namespace boost::python;

const char* acadBrStatusText(const AcBr::ErrorStatus stat) noexcept
{
    switch (stat)
    {
        default:
            return "Unknown";
        case AcBr::eOk:
            return "eOk";
        case AcBr::eNotImplementedYet:
            return "eNotImplementedYet";
        case AcBr::eNotApplicable:
            return "eNotApplicable";
        case AcBr::eInvalidInput:
            return "eInvalidInput";
        case AcBr::eOutOfMemory:
            return "eOutOfMemory";
        case AcBr::eNullObjectPointer:
            return "eNullObjectPointer";
        case AcBr::eWrongObjectType:
            return "eWrongObjectType";
        case AcBr::eWrongSubentityType:
            return "eWrongSubentityType";
        case AcBr::eNullObjectId:
            return "eNullObjectId";
        case AcBr::eNullSubentityId:
            return "eNullSubentityId";
        case AcBr::eObjectIdMismatch:
            return "eTopologyMismatch";
        case AcBr::eUnsuitableGeometry:
            return "eUnsuitableGeometry";
        case AcBr::eMissingGeometry:
            return "eMissingGeometry";
        case AcBr::eMissingSubentity:
            return "eMissingSubentity";
        case AcBr::eBrepChanged:
            return "eBrepChanged";
        case AcBr::eUnsuitableTopology:
            return "eUnsuitableTopology";
        case AcBr::eDegenerateTopology:
            return "eDegenerateTopology";
        case AcBr::eUninitialisedObject:
            return "eUninitialisedObject";
    }
    return "Unknown";
}

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

static std::string formatfname(const char* pname)
{
    std::string val = pname;
    auto posend = val.find("(");
    if (posend == std::string::npos)
        posend = val.size();
    auto posbegin = val.rfind(" ", posend);
    if (posbegin == std::string::npos)
        posbegin = 0;
    return trim_copy(val.substr(posbegin, (posend - posbegin)), 32);
}

void printExceptionMsg(const std::source_location& src /*= std::source_location::current()*/)
{
    constexpr const char* fmtstr("\nException, line {}, in function {} {}: ");
    const auto& fname = formatfname(src.function_name());
    acutPrintf(utf8_to_wstr(std::format(fmtstr, src.line(), fname.c_str(), src.file_name())).c_str());
}

//-----------------------------------------------------------------------------------
// PyNullObject
PyNullObject::PyNullObject(const std::source_location& src /*= std::source_location::current()*/)
    :m_src(src)
{
    generateformat();
}

std::string PyNullObject::format() const
{
    return m_fmt;
}

void PyNullObject::generateformat()
{
    constexpr const char* fmtstr("\nException! Object is NULL, in function {}, Line {}, File {}: ");
    const auto& fname = formatfname(m_src.function_name());
    m_fmt = std::format(fmtstr, fname.c_str(), m_src.line(), m_src.file_name());
}

void PyNullObject::translator(const PyNullObject& x)
{
    PyErr_SetString(PyExc_RuntimeError, x.format().c_str());
}

//-----------------------------------------------------------------------------------
// PyAcadHrError
PyAcadHrError::PyAcadHrError(const HRESULT hr, const std::source_location& src /*= std::source_location::current()*/)
    : m_hr(hr), m_src(src) 
{
    generateformat();
}

std::string PyAcadHrError::format() const
{
    return m_fmt;
}

void PyAcadHrError::generateformat()
{
    constexpr const char* fmtstr("\nException!({}, function {}, Line {}, File {}: ");
    const auto& fname = formatfname(m_src.function_name());
    m_fmt = std::format(fmtstr, std::system_category().message(m_hr), fname.c_str(), m_src.line(), m_src.file_name());
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
    generateformat();
}

std::string PyNotimplementedByHost::format() const
{
    return m_fmt;
}

void PyNotimplementedByHost::generateformat()
{
    constexpr std::string_view fmtstr("\nException, Not implemented in {}!, function {}, Line {}, File {}: ");
    const auto& fname = formatfname(m_src.function_name());
    m_fmt = std::format(fmtstr, appHostName(), fname.c_str(), m_src.line(), m_src.file_name());
}

void PyNotimplementedByHost::translator(const PyNotimplementedByHost& x)
{
    PyErr_SetString(PyExc_RuntimeError, x.format().c_str());
}

#if defined(_BRXTARGET)

//-----------------------------------------------------------------------------------
// PyBrxBimError
PyBrxBimError::PyBrxBimError(const BimApi::ResultStatus rs, const std::source_location& src /*= std::source_location::current()*/)
    : m_rs(rs), m_src(src) 
{
    generateformat();
}

void PyBrxBimError::generateformat()
{
    constexpr std::string_view fmtstr("\nException!({}), function {}, Line {}, File {}: ");
    const auto& fname = formatfname(m_src.function_name());
    m_fmt = std::format(fmtstr, brxBimStatusText(m_rs), fname.c_str(), m_src.line(), m_src.file_name());
}

std::string PyBrxBimError::format() const
{
    return m_fmt;
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
    generateformat();
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
    return m_fmt;
}

void PyErrorStatusException::makePyErrorStatusExceptionWrapper()
{
    PyErrorStatusException::PyErrorStatusExceptionType = PyErrorStatusException::createPyErrorStatusExceptionClass();
    register_exception_translator<PyErrorStatusException>(&PyErrorStatusException::translatePyErrorStatusException);
}

void PyErrorStatusException::generateformat()
{
    constexpr std::string_view fmtstr("Exception!({}), function {}, Line {}, File {}: ");
    const auto& fname = formatfname(m_src.function_name());
    m_fmt = std::format(fmtstr, wstr_to_utf8(acadErrorStatusText(m_es)), fname.c_str(), m_src.line(), m_src.file_name());
}

//-----------------------------------------------------------------------------------
// PyBrErrorStatusException
PyBrErrorStatusException::PyBrErrorStatusException(AcBr::ErrorStatus es, const std::source_location& src /*= std::source_location::current()*/)
    : m_es(es), m_src(src)
{
    generateformat();
}

const char* PyBrErrorStatusException::what() const noexcept
{
    return m_fmt.c_str();
}

std::string PyBrErrorStatusException::fullmessage() const
{
    return m_fmt;
}

AcBr::ErrorStatus PyBrErrorStatusException::code() const
{
    return m_es;
}

PyObject* PyBrErrorStatusException::createPyBrErrorStatusExceptionClass()
{
    PyAutoLockGIL lock;
    constexpr const char* name = "ErrorStatusException";
    constexpr const char* qualifiedName = "PyBr.ErrorStatusException";
    PyObject* typeObj = PyErr_NewException(qualifiedName, PyExc_RuntimeError, 0);
    if (!typeObj)
        throw_error_already_set();
    scope().attr(name) = handle<>(borrowed(typeObj));
    return typeObj;
}

void PyBrErrorStatusException::translatePyBrErrorStatusException(const PyBrErrorStatusException& e)
{
    PyAutoLockGIL lock;
    boost::python::object exc_t(handle<>(borrowed(PyBrErrorStatusException::PyBrErrorStatusExceptionType)));
    exc_t.attr("code") = object(e.code());
    exc_t.attr("message") = object(e.message());
    exc_t.attr("fullmessage") = object(e.fullmessage());
    PyErr_SetString(PyBrErrorStatusException::PyBrErrorStatusExceptionType, e.what());
}

std::string PyBrErrorStatusException::message() const
{
    return std::string{ acadBrStatusText(m_es) };
}

std::string PyBrErrorStatusException::format() const
{
    return m_fmt;
}

void PyBrErrorStatusException::makePyBrErrorStatusExceptionWrapper()
{
    PyBrErrorStatusException::PyBrErrorStatusExceptionType = PyBrErrorStatusException::createPyBrErrorStatusExceptionClass();
    register_exception_translator<PyBrErrorStatusException>(&PyBrErrorStatusException::translatePyBrErrorStatusException);
}

void PyBrErrorStatusException::generateformat()
{
    constexpr std::string_view fmtstr("Exception!({}), function {}, Line {}, File {}: ");
    const auto& fname = formatfname(m_src.function_name());
    m_fmt = std::format(fmtstr, acadBrStatusText(m_es), fname.c_str(), m_src.line(), m_src.file_name());
}
