#include "stdafx.h"
#include "PyRxApp.h"
#include "PyRxAcut.h"
#include "PyRxAced.h"


#include "PyAcGe.h"
#include "PyAcDb.h"
#include "PyAcRx.h"
#include "PyAcGi.h"
#include "PyAcAp.h"
#include "PyAcEd.h"


std::filesystem::path PyRxApp::modulePath()
{
    wchar_t buffer[MAX_PATH];
    GetModuleFileName(_hdllInstance, buffer, MAX_PATH);
    std::filesystem::path path = buffer;
    path.remove_filename();
    return path;
}

PyRxApp& PyRxApp::instance()
{
    static PyRxApp mthis;
    return mthis;
}

bool PyRxApp::init()
{
    initPyRxModule();//first
    initPyGeModule();
    initPyGiModule();
    initPyDbModule();
    initPyApModule();
    initPyEdModule();

    //TODO: might not keep this
    if (PyImport_AppendInittab(PyAppNamespace, PyInitPyRxModule) == -1)
        acutPrintf(_T("\nPyImport Failed"));

    Py_Initialize();
    if (Py_IsInitialized() && setPyConfig())
    {
        isLoaded = true;
        acutPrintf(_T("Python Interpreter Loaded successfully!\n"));
    }
    else
    {
        if (PyErr_Occurred())
            PyErr_Clear();
        acutPrintf(_T("Failed to load Python Interpreter!"));
    }
    return isLoaded;
}

bool PyRxApp::uninit()
{
    fnm.clear();
    if (Py_IsInitialized())
        Py_Finalize();
    isLoaded = false;
    return !isLoaded;
}

bool PyRxApp::setPyConfig()
{
    AcString _modulePath = modulePath().c_str();
    _modulePath.makeLower();

    PyObjectPtr sys(PyImport_ImportModule("sys"));
    if (sys == nullptr)
        return false;
    PyObjectPtr path(PyObject_GetAttrString(sys.get(), "path"));
    if (path == nullptr)
        return false;
    PyObjectPtr pyString(wstr_to_py((const TCHAR*)_modulePath));
    if (pyString == nullptr)
        return false;
    if (PyList_Append(path.get(), pyString.get()) < 0)
        return false;
    PyRxApp::instance().loadedModulePaths.insert((const TCHAR*)_modulePath);
    return true;
}

bool PyRxApp::pyRxAppendSearchPath(const TCHAR* pModulePath)
{
    AcString _modulePath = pModulePath;
    _modulePath.makeLower();

    if (PyRxApp::instance().loadedModulePaths.contains((const TCHAR*)_modulePath))
        return true;
    PyRxApp::instance().loadedModulePaths.insert((const TCHAR*)_modulePath);
    PyObjectPtr sys(PyImport_ImportModule("sys"));
    if (sys == nullptr)
        return false;
    PyObjectPtr path(PyObject_GetAttrString(sys.get(), "path"));
    if (path == nullptr)
        return false;
    PyObjectPtr pyString(wstr_to_py((const TCHAR*)_modulePath));
    if (pyString == nullptr)
        return false;
    if (PyList_Append(path.get(), pyString.get()) < 0)
        return false;
    return true;
}

PyMODINIT_FUNC PyInitPyRxModule(void)
{
    static PyMethodDef PyRxMethods[] =
    {
        {"Printf", PyRxAcut::Printf, METH_VARARGS, PyRxAcut::PrintfDoc()},
        {"GetString", PyRxAced::GetString, METH_VARARGS, PyRxAced::GetStringDoc()},
        {"GetVar", PyRxAced::GetVar, METH_VARARGS, PyRxAced::GetVarDoc()},
        {"SetVar", PyRxAced::SetVar, METH_VARARGS, PyRxAced::SetVarDoc()},
        {NULL, NULL, 0 , NULL}
    };
    static PyModuleDef pyRxModuleDef =
    {
        PyModuleDef_HEAD_INIT,  "PyRxApp", "ObjectArx wrappers", -1,  PyRxMethods
    };
    PyObject* m = PyModule_Create(&pyRxModuleDef);
    if (m == NULL)
        return NULL;
    return m;
}

std::wstring PyRxApp::the_error()
{
    if (PyErr_Occurred())
    {
        PyObject* error_type, * the_error, * the_traceback, * py_error_string, * py_error_unicode;
        PyErr_Fetch(&error_type, &the_error, &the_traceback);
        PyErr_NormalizeException(&error_type, &the_error, &the_traceback);
        if ((error_type != NULL))
        {
            std::wstring the_error_string, the_traceback_string;
            if (the_error != NULL)
                the_error_string = PyUnicode_AsWideCharString(PyObject_Str(the_error), nullptr);
            if (the_traceback != NULL)
            {
                if (PyTraceBack_Check(the_traceback))
                {
                    PyTracebackObject* traceRoot = (PyTracebackObject*)the_traceback;
                    PyTracebackObject* pTrace = traceRoot;

                    while (pTrace != NULL)
                    {
                        PyFrameObject* frame = pTrace->tb_frame;
                        PyCodeObject* code = PyFrame_GetCode(frame);

                        int lineNr = PyFrame_GetLineNumber(frame);
                        const char* sCodeName = PyUnicode_AsUTF8(code->co_name);
                        const char* sFileName = PyUnicode_AsUTF8(code->co_filename);
                        the_traceback_string += std::format(_T("\nAt {} ({}:{})"), utf8_to_wstr(sCodeName), utf8_to_wstr(sFileName), lineNr);
                        pTrace = pTrace->tb_next;
                    }
                }
            }
            std::wstring str_error(the_error_string);
            std::wstring str_traceback(the_traceback_string);
            std::wstring message(str_error + L" ,Traceback - " + the_traceback_string);
            Py_XDECREF(error_type);
            Py_XDECREF(the_error);
            Py_XDECREF(the_traceback);
            return message;
        }
    }
    return std::wstring{ };
}