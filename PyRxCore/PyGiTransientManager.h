#pragma once

#pragma pack (push, 8)
class PyGiDrawable;

void makePyGiTransientManagerWrapper();

class PyGiTransientManager
{
public:
    PyGiTransientManager();
    PyGiTransientManager(AcGiTransientManager* ptr);
    ~PyGiTransientManager() = default;

    bool        addTransient(PyGiDrawable& pDrawable, AcGiTransientDrawingMode mode, int subDrawingMode, const boost::python::list& viewportNumbers) const;
    bool        eraseTransient(PyGiDrawable& pDrawable, const boost::python::list& viewportNumbers) const;
    bool        eraseTransients(AcGiTransientDrawingMode mode, int subDrawingMode, const boost::python::list& viewportNumbers) const;
    void        updateTransient(PyGiDrawable& pDrawable, const boost::python::list& viewportNumbers) const;
    bool        addChildTransient(PyGiDrawable& pDrawable, PyGiDrawable& pParentDrawable) const;
    bool        eraseChildTransient(PyGiDrawable& pDrawable, PyGiDrawable& pParentDrawable) const;
    void        updateChildTransient(PyGiDrawable& pDrawable, PyGiDrawable& pParentDrawable) const;
    boost::python::tuple getFreeSubDrawingMode(AcGiTransientDrawingMode mode,int subDrawingMode, const boost::python::list& viewportNumbers) const;
    static  PyGiTransientManager current();
public:
    AcGiTransientManager* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    AcGiTransientManager* m_pyImp = nullptr;
};
#pragma pack (pop)

