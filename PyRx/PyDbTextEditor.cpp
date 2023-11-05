#include "stdafx.h"
#include "PyDbTextEditor.h"
using namespace boost::python;

//-----------------------------------------------------------------------------------------
//PyDbTextEditorLocation
void makePyDbTextEditorLocationWrapper()
{
    PyDocString DS("TextEditorLocation");
    class_<PyDbTextEditorLocation>("TextEditorLocation", boost::python::no_init)
        .def("className", &PyDbTextEditorLocation::className, DS.SARGS()).staticmethod("className")
        ;
}

struct PyDbTextEditorLocationDeleter
{
    inline void operator()(AcDbTextEditorLocation* p) const
    {
        if (p == nullptr) [[unlikely]]
            return;
            p->release();
    };
};

PyDbTextEditorLocation::PyDbTextEditorLocation(AcDbTextEditorLocation* ptr)
{
    m_pyImp.reset(ptr, PyDbTextEditorLocationDeleter());
}

std::string PyDbTextEditorLocation::className()
{
    return "AcDbTextEditorLocation";
}

AcDbTextEditorLocation* PyDbTextEditorLocation::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return m_pyImp.get();
}



//-----------------------------------------------------------------------------------------
//PyDbTextEditorSelectable
void makePyDbTextEditorSelectableWrapper()
{
    PyDocString DS("TextEditorSelectable");
    class_<PyDbTextEditorLocation>("TextEditorSelectable", boost::python::no_init)
        .def("startOfText", &PyDbTextEditorSelectable::startOfText, DS.ARGS())
        .def("endOfText", &PyDbTextEditorSelectable::endOfText, DS.ARGS())
        .def("className", &PyDbTextEditorSelectable::className, DS.SARGS()).staticmethod("className")
        ;
}

PyDbTextEditorLocation PyDbTextEditorSelectable::startOfText()
{
    return PyDbTextEditorLocation(impObj()->startOfText());
}

PyDbTextEditorLocation PyDbTextEditorSelectable::endOfText()
{
    return PyDbTextEditorLocation(impObj()->endOfText());
}

std::string PyDbTextEditorSelectable::className()
{
    return "AcDbTextEditorSelectable";
}

AcDbTextEditorSelectable* PyDbTextEditorSelectable::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return m_pyImp.get();
}

//-----------------------------------------------------------------------------------------
//PyDbTextEditorSelectionBase
void makePyDbTextEditorSelectionBaseWrapper()
{
    PyDocString DS("TextEditorSelectionBase");
    class_<PyDbTextEditorSelectionBase>("TextEditorSelectionBase", boost::python::no_init)
        .def("className", &PyDbTextEditorSelectionBase::className, DS.SARGS()).staticmethod("className")
        ;
}

PyDbTextEditorSelectionBase::PyDbTextEditorSelectionBase(AcDbTextEditorSelectionBase* pBase)
{
    m_pyImp = pBase;
}

std::string PyDbTextEditorSelectionBase::className()
{
    return "AcDbTextEditorSelectionBase";
}

AcDbTextEditorSelectionBase* PyDbTextEditorSelectionBase::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return m_pyImp;
}

//-----------------------------------------------------------------------------------------
//PyDbTextEditorSelection
void makePyDbTextEditorSelectionWrapper()
{
    PyDocString DS("TextEditorSelection");
    class_<PyDbTextEditorSelection>("TextEditorSelection", boost::python::no_init)
        .def("className", &PyDbTextEditorSelection::className, DS.SARGS()).staticmethod("className")
        ;
}

PyDbTextEditorSelection::PyDbTextEditorSelection(AcDbTextEditorSelection* ptr)
    : PyDbTextEditorSelectionBase(ptr)
{
}

std::string PyDbTextEditorSelection::className()
{
    return "AcDbTextEditorSelection";
}

AcDbTextEditorSelection* PyDbTextEditorSelection::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    static_cast<AcDbTextEditorSelection*>(__super::impObj());
}

//-----------------------------------------------------------------------------------------
//PyDbTextEditorCursor
void makePyDbTextEditorCursorWrapper()
{
    PyDocString DS("TextEditorSelection");
    class_<PyDbTextEditorSelection>("TextEditorSelection", boost::python::no_init)
        .def("className", &PyDbTextEditorSelection::className, DS.SARGS()).staticmethod("className")
        ;
}

PyDbTextEditorCursor::PyDbTextEditorCursor(AcDbTextEditorCursor* ptr)
    : PyDbTextEditorSelectionBase(ptr)
{
}

std::string PyDbTextEditorCursor::className()
{
    return "AcDbTextEditorCursor";
}

AcDbTextEditorCursor* PyDbTextEditorCursor::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    static_cast<AcDbTextEditorCursor*>(__super::impObj());
}
