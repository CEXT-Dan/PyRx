#include "stdafx.h"
#include "PyAcadApplication.h"

#ifdef PYRX_IN_PROGRESS_PYAX

#include "PyAcadApplicationImpl.h"

using namespace boost::python;
//----------------------------------------------------------------------------------------
//PyAcadEntity
void makePyAcadApplicationWrapper()
{
    PyDocString DS("AcadApplication");
    class_<PyAcadApplication>("AcadApplication")
        .def("eval", &PyAcadApplication::eval, DS.ARGS({ "sval: str" }))
        .def("listArx", &PyAcadApplication::listArx, DS.ARGS())
        .def("loadArx", &PyAcadApplication::loadArx, DS.ARGS({ "arx: str" }))
        .def("loadDVB", &PyAcadApplication::loadDVB, DS.ARGS({ "dvb: str" }))
        .def("quit", &PyAcadApplication::quit, DS.ARGS())
        .def("runMacro", &PyAcadApplication::runMacro, DS.ARGS({ "macro: str" }))
        .def("unloadArx", &PyAcadApplication::unloadArx, DS.ARGS({ "arx: str" }))
        .def("unloadDVB", &PyAcadApplication::unloadDVB, DS.ARGS({ "dvb: str" }))
        .def("update", &PyAcadApplication::update, DS.ARGS())
        .def("zoomAll", &PyAcadApplication::zoomAll, DS.ARGS())
        .def("zoomCenter", &PyAcadApplication::zoomCenter, DS.ARGS({ "pt: PyGe.Point3d", "magnify: float" }))
        .def("zoomExtents", &PyAcadApplication::zoomExtents, DS.ARGS())
        .def("zoomPickWindow", &PyAcadApplication::zoomPickWindow, DS.ARGS())
        .def("zoomPrevious", &PyAcadApplication::zoomPrevious, DS.ARGS())
        .def("caption", &PyAcadApplication::caption, DS.ARGS())
        .def("documents", &PyAcadApplication::documents, DS.ARGS())
        .def("fullName", &PyAcadApplication::fullName, DS.ARGS())
        .def("getHeight", &PyAcadApplication::getHeight, DS.ARGS())
        .def("setHeight", &PyAcadApplication::setHeight, DS.ARGS({ "height: int" }))
        .def("getHWND", &PyAcadApplication::getHWND, DS.ARGS())
        .def("localeId", &PyAcadApplication::localeId, DS.ARGS())
        .def("getName", &PyAcadApplication::getName, DS.ARGS())
        .def("getPath", &PyAcadApplication::getPath, DS.ARGS())
        .def("version", &PyAcadApplication::version, DS.ARGS())
        .def("isVisible", &PyAcadApplication::isVisible, DS.ARGS())
        .def("setVisible", &PyAcadApplication::setVisible, DS.ARGS({ "visible: bool" }))
        .def("getWidth", &PyAcadApplication::getWidth, DS.ARGS())
        .def("setWidth", &PyAcadApplication::setWidth, DS.ARGS({ "width: int" }))
        .def("getWindowLeft", &PyAcadApplication::getWindowLeft, DS.ARGS())
        .def("setWindowLeft", &PyAcadApplication::setWindowLeft, DS.ARGS({ "left: int" }))
        .def("getWindowTop", &PyAcadApplication::getWindowTop, DS.ARGS())
        .def("setWindowTop", &PyAcadApplication::setWindowTop, DS.ARGS({ "top: int" }))
        .def("className", &PyAcadApplication::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadApplication::PyAcadApplication()
    : m_pyImp(new PyAcadApplicationImpl())
{
}

void PyAcadApplication::eval(const std::string& sval) const
{
    impObj()->Eval(utf8_to_wstr(sval).c_str());
}

boost::python::list PyAcadApplication::listArx() const
{
    PyAutoLockGIL lock;
    boost::python::list _pylist;
    for (const auto& arx : impObj()->ListArx())
        _pylist.append(wstr_to_utf8(arx));
    return _pylist;
}

void PyAcadApplication::loadArx(const std::string& sval)
{
    impObj()->LoadArx(utf8_to_wstr(sval).c_str());
}

void PyAcadApplication::loadDVB(const std::string& sval)
{
    impObj()->LoadDVB(utf8_to_wstr(sval).c_str());
}

void PyAcadApplication::quit()
{
    impObj()->Quit();
}

void PyAcadApplication::runMacro(const std::string& sval)
{
    impObj()->RunMacro(utf8_to_wstr(sval).c_str());
}

void PyAcadApplication::unloadArx(const std::string& sval)
{
    impObj()->UnloadArx(utf8_to_wstr(sval).c_str());
}

void PyAcadApplication::unloadDVB(const std::string& sval)
{
    impObj()->UnloadDVB(utf8_to_wstr(sval).c_str());
}

void PyAcadApplication::update()
{
    impObj()->Update();
}

void PyAcadApplication::zoomAll()
{
    impObj()->ZoomAll();
}

void PyAcadApplication::zoomCenter(const AcGePoint3d& pnt, double magnify)
{
    impObj()->ZoomCenter(pnt, magnify);
}

void PyAcadApplication::zoomExtents()
{
    impObj()->ZoomExtents();
}

void PyAcadApplication::zoomPickWindow()
{
    impObj()->ZoomPickWindow();
}

void PyAcadApplication::zoomPrevious()
{
    impObj()->ZoomPrevious();
}

std::string PyAcadApplication::caption() const
{
    return wstr_to_utf8(impObj()->GetCaption());
}

PyAcadDocuments PyAcadApplication::documents() const
{
   return PyAcadDocuments(impObj()->GetDocuments().release());
}

std::string PyAcadApplication::fullName() const
{
    return wstr_to_utf8(impObj()->GetFullName());
}

int PyAcadApplication::getHeight() const
{
    return impObj()->GetHeight();
}

void PyAcadApplication::setHeight(int val)
{
    impObj()->SetHeight(val);
}

LONG_PTR PyAcadApplication::getHWND() const
{
    return impObj()->GetHWND();
}

long PyAcadApplication::localeId() const
{
    return impObj()->GetLocaleId();
}

std::string PyAcadApplication::getName() const
{
    return wstr_to_utf8(impObj()->GetName());
}

std::string PyAcadApplication::getPath() const
{
    return wstr_to_utf8(impObj()->GetPath());
}

std::string PyAcadApplication::version() const
{
    return wstr_to_utf8(impObj()->GetVersion());
}

bool PyAcadApplication::isVisible() const
{
    return impObj()->GetVisible();
}

void PyAcadApplication::setVisible(bool val)
{
    impObj()->SetVisible(val);
}

int PyAcadApplication::getWidth() const
{
    return impObj()->GetWidth();
}

void PyAcadApplication::setWidth(int val)
{
    impObj()->SetWidth(val);
}

int PyAcadApplication::getWindowLeft() const
{
    return impObj()->GetWindowLeft();
}

void PyAcadApplication::setWindowLeft(int val)
{
    impObj()->SetWindowLeft(val);
}

int PyAcadApplication::getWindowTop() const
{
    return impObj()->GetWindowTop();
}

void PyAcadApplication::setWindowTop(int val)
{
    impObj()->SetWindowTop(val);
}

std::string PyAcadApplication::className()
{
    return "AcadApplication";
}

bool PyAcadApplication::runTest(const AcDbObjectId& id)
{
    return PyAcadApplicationImpl::runTest(id);
}

PyAcadApplicationImpl* PyAcadApplication::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyAcadApplicationImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadDocuments
void makePyAcadDocumentsWrapper()
{
    PyDocString DS("AcadDocuments");
    class_<PyAcadDocuments>("AcadDocuments", no_init)
        .def("count", &PyAcadDocuments::count, DS.ARGS())
        .def("className", &PyAcadDocuments::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadDocuments::PyAcadDocuments(PyIAcadDocumentsImpl* ptr)
    : m_pyImp(ptr)
{
}

long PyAcadDocuments::count() const
{
    return impObj()->GetCount();
}

std::string PyAcadDocuments::className()
{
    return "AcadDocuments";
}

PyIAcadDocumentsImpl* PyAcadDocuments::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadDocumentsImpl*>(m_pyImp.get());
}

#endif

