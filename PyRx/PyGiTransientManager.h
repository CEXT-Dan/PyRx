#pragma once

class PyGiDrawable;

void makePyGiTransientManagerWrapper();

class PyGiTransientManager
{
public:
    PyGiTransientManager();
    PyGiTransientManager(AcGiTransientManager* ptr);

    bool        addTransient(PyGiDrawable& pDrawable, AcGiTransientDrawingMode mode, int subDrawingMode, const boost::python::object& viewportNumbers);
    bool        eraseTransient(PyGiDrawable& pDrawable, const boost::python::object& viewportNumbers);
    bool        eraseTransients(AcGiTransientDrawingMode mode, int subDrawingMode, const boost::python::object& viewportNumbers);
    void        updateTransient(PyGiDrawable& pDrawable, const boost::python::object& viewportNumbers);
    bool        addChildTransient(PyGiDrawable& pDrawable, PyGiDrawable& pParentDrawable);
    bool        eraseChildTransient(PyGiDrawable& pDrawable, PyGiDrawable& pParentDrawable);
    void        updateChildTransient(PyGiDrawable& pDrawable, PyGiDrawable& pParentDrawable);
    boost::python::tuple getFreeSubDrawingMode(AcGiTransientDrawingMode mode,int subDrawingMode, const boost::python::object& viewportNumbers);
    static  PyGiTransientManager current();
public:
    AcGiTransientManager* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    AcGiTransientManager* m_pyImp = nullptr;
};

