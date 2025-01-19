#include "stdafx.h"
#include "PyAcadApplication.h"
#include "PyAcadApplicationImpl.h"
#include "PyAcadObject.h"

using namespace boost::python;

//------------------------------------------------------------------------------------
//PyAcadState
void makePyAcadStateWrapper()
{
    PyDocString DS("AcadState");
    class_<PyAcadState>("AcadState", no_init)
        .def("isQuiescent", &PyAcadState::isQuiescent, DS.ARGS())
        .def("className", &PyAcadState::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadState::PyAcadState(std::shared_ptr<PyIAcadStateImpl> ptr)
    : m_pyImp(ptr)
{
}

bool PyAcadState::isQuiescent() const
{
    return impObj()->getIsQuiescent();
}

std::string PyAcadState::className()
{
    return "AcadState";
}

PyIAcadStateImpl* PyAcadState::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadStateImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadEntity
void makePyAcadApplicationWrapper()
{
    PyDocString DS("AcadApplication");
    class_<PyAcadApplication>("AcadApplication")
        .def("eval", &PyAcadApplication::eval, DS.ARGS({ "sval: str" }))
        .def("listArx", &PyAcadApplication::listArx, DS.ARGS())
        .def("acadState", &PyAcadApplication::acadState, DS.ARGS())
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
        .def("zoomScaled", &PyAcadApplication::zoomScaled, DS.ARGS({"magnify: float","scaletype: PyAx.AcZoomScaleType" }))
        .def("activeDocument", &PyAcadApplication::activeDocument, DS.ARGS())
        .def("setActiveDocument", &PyAcadApplication::setActiveDocument, DS.ARGS({"doc : PyAx.AcadDocument"}))
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
        .def("getWindowState", &PyAcadApplication::getWindowState, DS.ARGS())
        .def("setWindowState", &PyAcadApplication::setWindowState, DS.ARGS({ "state: PyAx.AcWindowState" }))
        .def("menuBar", &PyAcadApplication::menuBar, DS.ARGS())
        .def("menuGroups", &PyAcadApplication::menuGroups, DS.ARGS())
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

PyAcadState PyAcadApplication::acadState()
{
   return PyAcadState{ impObj()->GetAcadState() };
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

void PyAcadApplication::zoomScaled(double magnify, PyAcZoomScaleType scaletype)
{
    impObj()->ZoomScaled(magnify, scaletype);
}

PyAcadDocument PyAcadApplication::activeDocument() const
{
    return PyAcadDocument{ impObj()->GetActiveDocument() };
}

void PyAcadApplication::setActiveDocument(const PyAcadDocument& val) const
{
    impObj()->SetActiveDocument(*val.impObj());
}

std::string PyAcadApplication::caption() const
{
    return wstr_to_utf8(impObj()->GetCaption());
}

PyAcadDocuments PyAcadApplication::documents() const
{
   return PyAcadDocuments(impObj()->GetDocuments());
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

PyAcadMenuBar PyAcadApplication::menuBar() const
{
   return PyAcadMenuBar(impObj()->GetMenuBar());
}

PyAcadMenuGroups PyAcadApplication::menuGroups() const
{
    return PyAcadMenuGroups(impObj()->GetMenuGroups());
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

PyAcWindowState PyAcadApplication::getWindowState() const
{
   return impObj()->GetWindowState();
}

void PyAcadApplication::setWindowState(PyAcWindowState val)
{
    impObj()->SetWindowState(val);
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
        .def("add", &PyAcadDocuments::add1)
        .def("add", &PyAcadDocuments::add2, DS.ARGS({ "template: str = None" }))
        .def("close", &PyAcadDocuments::close, DS.ARGS())
        .def("item", &PyAcadDocuments::item, DS.ARGS({ "index: int" }))
        .def("open", &PyAcadDocuments::open, DS.ARGS({ "path: str","readOnly: bool" }))
        .def("__getitem__", &PyAcadDocuments::item, DS.ARGS({ "index: int" }))
        .def("className", &PyAcadDocuments::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadDocuments::PyAcadDocuments(std::shared_ptr<PyIAcadDocumentsImpl> ptr) noexcept
    : m_pyImp(ptr)
{
}

long PyAcadDocuments::count() const
{
    return impObj()->GetCount();
}

PyAcadDocument PyAcadDocuments::add1()
{
   return PyAcadDocument{ impObj()->Add() };
}

PyAcadDocument PyAcadDocuments::add2(const std::string& _template)
{
    return PyAcadDocument{ impObj()->Add(utf8_to_wstr(_template).c_str()) };
}

void PyAcadDocuments::close()
{
    return impObj()->Close();
}

PyAcadDocument PyAcadDocuments::item(long index)
{
    if (index >= count())
        throw std::out_of_range{ "IndexError " };
    return PyAcadDocument{ impObj()->GetItem(index) };
}

PyAcadDocument PyAcadDocuments::open(const std::string& path, bool readOnly)
{
    return PyAcadDocument{ impObj()->Open(utf8_to_wstr(path).c_str(),readOnly) };
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
    return m_pyImp.get();
}

//----------------------------------------------------------------------------------------
//PyAcadDatabase
void makePyAcadDatabaseWrapper()
{
    PyDocString DS("AcadDatabase");
    class_<PyAcadDatabase>("AcadDatabase", no_init)
        .def("className", &PyAcadDatabase::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadDatabase::PyAcadDatabase(std::shared_ptr<PyIAcadDatabaseImpl> ptr) noexcept
 : m_pyImp(ptr)
{
}

std::string PyAcadDatabase::className()
{
    return "AcadDatabase";
}

PyIAcadDatabaseImpl* PyAcadDatabase::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return m_pyImp.get();
}

//----------------------------------------------------------------------------------------
//PyAcadDocument
void makePyAcadDocumentWrapper()
{
    PyDocString DS("AcadDocument");
    class_<PyAcadDocument>("AcadDocument", no_init)
        .def("name", &PyAcadDocument::name, DS.ARGS())
        .def("className", &PyAcadDocument::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadDocument::PyAcadDocument(std::shared_ptr<PyIAcadDocumentImpl> ptr)
    : PyAcadDatabase(ptr)
{
}

std::string PyAcadDocument::name() const
{
    return wstr_to_utf8(impObj()->GetName());
}

std::string PyAcadDocument::className()
{
    return "AcadDocument";
}

PyIAcadDocumentImpl* PyAcadDocument::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadDocumentImpl*>(m_pyImp.get());
}
