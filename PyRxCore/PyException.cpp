#include "stdafx.h"
#include "PyException.h"

using namespace boost::python;

//-----------------------------------------------------------------------------------
//PyErrorStatusExeption
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

PyObject* PyErrorStatusException::createPyErrorStatusExeptionClass(const char* name, PyObject* baseTypeObj /*= PyExc_Exception*/)
{
    const std::string scopeName = extract<std::string>(scope().attr("__name__"));
    const std::string qualifiedName0 = scopeName + "." + name;
    PyObject* typeObj = PyErr_NewException(qualifiedName0.c_str(), baseTypeObj, 0);
    if (!typeObj)
        throw_error_already_set();
    scope().attr(name) = handle<>(borrowed(typeObj));
    return typeObj;
}

void PyErrorStatusException::translatePyErrorStatusExeption(const PyErrorStatusException& e)
{
    using namespace boost;
    python::object exc_t(python::handle<>(borrowed(PyErrorStatusException::PyErrorStatusExceptionType)));
    exc_t.attr("ctx") = python::object(e);
    PyErr_SetString(PyErrorStatusException::PyErrorStatusExceptionType, e.fullmessage().c_str());
}

std::string PyErrorStatusException::message() const
{
    return wstr_to_utf8(acadErrorStatusText(m_es));
}

std::string PyErrorStatusException::format() const
{
    constexpr std::string_view fmtstr("\nException!({}), function {}, Line {}, File {}: ");
    const std::filesystem::path file = m_src.file_name();
    const auto& fname = formatfname(m_src.function_name());
    return std::format(fmtstr, wstr_to_utf8(acadErrorStatusText(m_es)), (const char*)fname, m_src.line(), file.filename().string());
}

void makePyErrorStatusExeptionWrapper()
{
    PyDocString DS("ErrorStatusExeption");
    class_<PyErrorStatusException> PyErrorStatusExceptionClass("ErrorStatusExeption", init<Acad::ErrorStatus>());
    PyErrorStatusExceptionClass.add_property("fullmessage", &PyErrorStatusException::fullmessage, DS.ARGS());
    PyErrorStatusExceptionClass.add_property("message", &PyErrorStatusException::message, DS.ARGS());
    PyErrorStatusExceptionClass.add_property("code", &PyErrorStatusException::code, DS.ARGS());
    PyErrorStatusException::PyErrorStatusExceptionType = PyErrorStatusException::createPyErrorStatusExeptionClass("ErrorStatusException");
    register_exception_translator<PyErrorStatusException>(&PyErrorStatusException::translatePyErrorStatusExeption);
}
