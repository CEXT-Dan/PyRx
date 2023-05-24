#include "stdafx.h"
#include "PyAcRx.h"
#include "PyRxObject.h"
#include <boost/function.hpp>
#include "PyRxOverrule.h"

using namespace boost::python;

enum eDirection_type
{
    eStdin,
    eStdout,
    eStderr
};

template<eDirection_type>
class py_redirector
{
public:
    void write(const std::string& text)
    {
        if (text.size() != 0)
            acutPrintf(utf8_to_wstr(text).c_str());
    }
    void flush()
    {
        acutPrintf(_T("\n"));
    }
};

typedef py_redirector<eStdin>	stdout_redirector;
typedef py_redirector<eStderr>	stderr_redirector;

static boost::shared_ptr<stdout_redirector> make_stdout_redirector()
{
    return boost::shared_ptr<stdout_redirector>(new stdout_redirector);
}

static boost::shared_ptr<stderr_redirector> make_stderr_redirector()
{
    return boost::shared_ptr<stderr_redirector>(new stderr_redirector);
}

//
BOOST_PYTHON_MODULE(PyRx)
{
#ifndef  PyRxDebug
    docstring_options local_docstring_options(false, true, true);
#endif // ! PyRxDebug

    class_<stdout_redirector>("stdout", init<>())
        .def("__init__", make_constructor(make_stdout_redirector))
        .def("write", &stdout_redirector::write)
        .def("flush", &stdout_redirector::flush)
        ;
    class_<stderr_redirector>("stderr", init<>())
        .def("__init__", make_constructor(make_stderr_redirector))
        .def("write", &stderr_redirector::write)
        .def("flush", &stderr_redirector::flush)
        ;
    boost::python::import("sys").attr("stdout") = make_stdout_redirector().get();
    boost::python::import("sys").attr("stderr") = make_stderr_redirector().get();

    makeAcRxObjectWrapper();
    makeAcRxClassWrapper();
    makePyRxOverruleWrapper();

    enum_<LispDataType>("LispDataType")
        .value("kAngle", LispDataType::kAngle)
        .value("kDottedPair", LispDataType::kDottedPair)
        .value("kDouble", LispDataType::kDouble)
        .value("kInt16", LispDataType::kInt16)
        .value("kInt32", LispDataType::kInt32)
        .value("kListBegin", LispDataType::kListBegin)
        .value("kListEnd", LispDataType::kListEnd)
        .value("kNil", LispDataType::kNil)
        .value("kNone", LispDataType::kNone)
        .value("kObjectId", LispDataType::kObjectId)
        .value("kOrientation", LispDataType::kOrientation)
        .value("kPoint2d", LispDataType::kPoint2d)
        .value("kPoint3d", LispDataType::kPoint3d)
        .value("kT_atom", LispDataType::kT_atom)
        .value("kText", LispDataType::kText)
        .value("kVoid", LispDataType::kVoid)
        .export_values()
        ;
};

void initPyRxModule()
{
    PyImport_AppendInittab(PyRxNamespace, &PyInit_PyRx);
}
