#include "stdafx.h"
#include "PyAcRx.h"
#include "PyRxObject.h"
#include <boost/function.hpp>

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
    docstring_options local_docstring_options(false, true, false);
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


    enum_<LispDataType>("LispDataType")
        .value("Angle", LispDataType::kAngle)
        .value("DottedPair", LispDataType::kDottedPair)
        .value("Double", LispDataType::kDouble)
        .value("Int16", LispDataType::kInt16)
        .value("Int32", LispDataType::kInt32)
        .value("ListBegin", LispDataType::kListBegin)
        .value("ListEnd", LispDataType::kListEnd)
        .value("Nil", LispDataType::kNil)
        .value("None", LispDataType::kNone)
        .value("ObjectId", LispDataType::kObjectId)
        .value("Orientation", LispDataType::kOrientation)
        .value("Point2d", LispDataType::kPoint2d)
        .value("Point3d", LispDataType::kPoint3d)
        .value("T_atom", LispDataType::kT_atom)
        .value("Text", LispDataType::kText)
        .value("Void", LispDataType::kVoid)
        ;
};

void initPyRxModule()
{
    PyImport_AppendInittab(PyRxNamespace, &PyInit_PyRx);
}
