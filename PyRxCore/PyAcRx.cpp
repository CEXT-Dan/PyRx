#include "stdafx.h"
#include "PyAcRx.h"
#include "PyRxObject.h"
#include <boost/function.hpp>
#include "PyRxOverrule.h"
#include "PyRxApp.h"
#include <queue>
#include <condition_variable>

using namespace boost::python;

//-----------------------------------------------------------------------------------------------------------
//LispType
enum class LispType
{
    kAngle = 5004,
    kDottedPair = 5018,
    kDouble = 5001,
    kInt16 = 5003,
    kInt32 = 5010,
    kListBegin = 5016,
    kListEnd = 5017,
    kNil = 5019,
    kNone = 5000,
    kObjectId = 5006,
    kOrientation = 5008,
    kPoint2d = 5002,
    kVector2d = kPoint2d,
    kPoint3d = 5009,
    kVector3d = kPoint3d,
    kSelectionSet = 5007,
    kT_atom = 5021,
    kText = 5005,
    kVoid = 5014,
};

//-----------------------------------------------------------------------------------------------------------
//redirect stdout
enum eDirection_type
{
    eStdin,
    eStdout,
    eStderr
};

//https://forums.codeguru.com/showthread.php?562679-Thread-safe-deque-implementation
template<typename T>
class Lockqueue
{
    using Mutex = std::mutex;

public:
    void push(T value)
    { // push
        std::lock_guard<Mutex> lock(mutex);
        queue.push(std::move(value));
        condition.notify_one();
    }

    bool try_pop(T& value)
    { // non-blocking pop
        std::lock_guard<Mutex> lock(mutex);
        if (queue.empty()) return false;
        value = std::move(queue.front());
        queue.pop();
        return true;
    }

    T wait_pop()
    { // blocking pop
        std::unique_lock<Mutex> lock(mutex);
        condition.wait(lock, [this] {return !queue.empty(); });
        T const value = std::move(queue.front());
        queue.pop();
        return value;
    }

    int size() const
    { // queue size
        std::lock_guard<Mutex> lock(mutex);
        return static_cast<int>(queue.size());
    }

private:
    mutable Mutex mutex;
    std::queue<T> queue;
    std::condition_variable condition;
};

static Lockqueue<std::string>& LockqueueFunc()
{
    static Lockqueue<std::string> lq;
    return lq;
}

static std::string expandPercents(const std::string& input)
{
    std::string result;
    result.reserve(size_t(input.size() * 1.25));
    for (char c : input)
    {
        result += c;
        if (c == '%')
            result += '%';
    }
    return result;
}

static void doWrite(const std::string& input)
{
    if (input.size() != 0)
        acutPrintf(utf8_to_wstr(expandPercents(input)).c_str());
}

void flushPromptBuffer()
{
    while (LockqueueFunc().size() > 0)
    {
        if (std::string buffer; LockqueueFunc().try_pop(buffer))
            doWrite(buffer);
    }
}

template<eDirection_type>
class py_redirector
{
public:

    void write(const std::string& text)
    {
        if (text.size() != 0)
        {
            if (std::this_thread::get_id() != PyRxApp::instance().MAIN_THREAD_ID)
                LockqueueFunc().push(text);
            else
                acutPrintf(utf8_to_wstr(expandPercents(text)).c_str());
        }
    }

    void flush()
    {
        doWrite("\n");
    }
};

typedef py_redirector<eStdout>	stdout_redirector;
typedef py_redirector<eStderr>	stderr_redirector;

static boost::shared_ptr<stdout_redirector> make_stdout_redirector()
{
    return boost::shared_ptr<stdout_redirector>(new stdout_redirector);
}

static boost::shared_ptr<stderr_redirector> make_stderr_redirector()
{
    return boost::shared_ptr<stderr_redirector>(new stderr_redirector);
}

//-----------------------------------------------------------------------------------------------------------
//PyRx Module
BOOST_PYTHON_MODULE(PyRx)
{
    docstring_options local_docstring_options(py_show_user_defined, py_show_py_signatures, py_show_cpp_signatures);

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

    makePyRxObjectWrapper();
    makePyRxClassWrapper();
    makePyRxOverruleWrapper();

    enum_<LispType>("LispType")
        .value("kAngle", LispType::kAngle)
        .value("kDottedPair", LispType::kDottedPair)
        .value("kDouble", LispType::kDouble)
        .value("kInt16", LispType::kInt16)
        .value("kInt32", LispType::kInt32)
        .value("kListBegin", LispType::kListBegin)
        .value("kListEnd", LispType::kListEnd)
        .value("kNil", LispType::kNil)
        .value("kNone", LispType::kNone)
        .value("kObjectId", LispType::kObjectId)
        .value("kOrientation", LispType::kOrientation)
        .value("kPoint2d", LispType::kPoint2d)
        .value("kVector2d", LispType::kVector2d)
        .value("kPoint3d", LispType::kPoint3d)
        .value("kVector3d", LispType::kVector3d)
        .value("kT_atom", LispType::kT_atom)
        .value("kText", LispType::kText)
        .value("kVoid", LispType::kVoid)
        .value("kSelectionSet", LispType::kSelectionSet)
        .export_values()
        ;

    enum_<AcRx::Ordering>("Ordering")
        .value("kLessThan", AcRx::kLessThan)
        .value("kEqual", AcRx::kEqual)
        .value("kGreaterThan", AcRx::kGreaterThan)
        .value("kNotOrderable", AcRx::kNotOrderable)
        .export_values()
        ;
};

void initPyRxModule()
{
    PyImport_AppendInittab(PyRxNamespace, &PyInit_PyRx);
}
