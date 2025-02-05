#include "stdafx.h"
#include "PyAcadApplication.h"
#include "PyAcadApplicationImpl.h"
#include "PyAcadDbObjectImpl.h"
#include "PyAcadEntityImpl.h"



using namespace boost::python;

//----------------------------------------------------------------------------------------
//PyAcadBlock
void makePyAcadBlockWrapper()
{
    PyDocString DS("AcadBlock");
    class_<PyAcadBlock, bases<PyAcadObject>>("AcadBlock", boost::python::no_init)
        .def("count", &PyAcadBlock::count, DS.ARGS())
        .def("item", &PyAcadBlock::item, DS.SARGS({ "index: int" }))
        .def("entities", &PyAcadBlock::entities, DS.ARGS())
        .def("name", &PyAcadBlock::name, DS.ARGS())
        .def("setName", &PyAcadBlock::setName, DS.ARGS({ "name:str" }))
        .def("origin", &PyAcadBlock::origin, DS.ARGS())
        .def("setOrigin", &PyAcadBlock::setOrigin, DS.ARGS({ "origin:PyGe.Point3d" }))
        .def("addCustomObject", &PyAcadBlock::addCustomObject, DS.ARGS({ "name:str" }))
        .def("add3DFace", &PyAcadBlock::add3DFace, DS.ARGS({ "p1:PyGe.Point3d","p2:PyGe.Point3d","p3:PyGe.Point3d","p4:PyGe.Point3d" }))
        .def("add3DMesh", &PyAcadBlock::add3DMesh, DS.ARGS({ "M:int","N:int","points:list[PyGe.Point3d]" }))
        .def("add3DPoly", &PyAcadBlock::add3DPoly, DS.ARGS({ "points:list[PyGe.Point3d]" }))
        .def("addArc", &PyAcadBlock::addArc, DS.ARGS({ "canter:PyGe.Point3d","radius:float","startAngle:float","endAngle:float" }))
        .def("addAttribute", &PyAcadBlock::addAttribute, DS.ARGS({ "height:float","mode:PyAx.AcAttributeMode","prompt:str","insertionPoint:PyGe.Point3d","tag:str", "value:str" }))
        .def("addBox", &PyAcadBlock::addBox, DS.ARGS({ "origin:PyGe.Point3d","length:float","width:float","height:float" }))
        .def("addCircle", &PyAcadBlock::addCircle, DS.ARGS({ "canter:PyGe.Point3d","radius:float" }))
        .def("addCone", &PyAcadBlock::addCone, DS.ARGS({ "canter:PyGe.Point3d","baseRadius:float","height:float" }))
        .def("addCylinder", &PyAcadBlock::addCylinder, DS.ARGS({ "canter:PyGe.Point3d","radius:float","height:float" }))
        .def("addDimAligned", &PyAcadBlock::addDimAligned, DS.ARGS({ "extLine1Point:PyGe.Point3d","extLine2Point:PyGe.Point3d","textPosition:PyGe.Point3d" }))
        .def("addDimAngular", &PyAcadBlock::addDimAngular, DS.ARGS({ "angleVertex:PyGe.Point3d","firstEndPoint:PyGe.Point3d","secondEndPoint:PyGe.Point3d","textPosition:PyGe.Point3d" }))

        .def("__getitem__", &PyAcadBlock::item, DS.ARGS({ "index: int" }))
        .def("__iter__", range(&PyAcadBlock::begin, &PyAcadBlock::end))
        .def("cast", &PyAcadBlock::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadBlock::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadBlock::PyAcadBlock(std::shared_ptr<PyIAcadBlockImpl> ptr)
    : PyAcadObject(ptr)
{
}

long PyAcadBlock::count() const
{
    return impObj()->GetCount();
}

PyAcadEntity PyAcadBlock::item(long ind) const
{
    if (ind >= count())
        throw std::out_of_range{ "IndexError " };
    return PyAcadEntity{ impObj()->GetItem(ind) };
}

boost::python::list PyAcadBlock::entities() const
{
    PyAutoLockGIL lock;
    boost::python::list _pylist;
    for (const auto& item : impObj()->GetIter())
        _pylist.append(PyAcadEntity{ item });
    return _pylist;
}

std::string PyAcadBlock::name() const
{
    return wstr_to_utf8(impObj()->GetName());
}

void PyAcadBlock::setName(const std::string& val)
{
    impObj()->SetName(utf8_to_wstr(val).c_str());
}

AcGePoint3d PyAcadBlock::origin() const
{
    return impObj()->GetOrigin();
}

void PyAcadBlock::setOrigin(const AcGePoint3d& val) const
{
    impObj()->SetOrigin(val);
}

PyAcadObject PyAcadBlock::addCustomObject(const std::string& val)
{
    return PyAcadObject{ impObj()->AddCustomObject(utf8_to_wstr(val).c_str()) };
}

PyAcad3DFace PyAcadBlock::add3DFace(const AcGePoint3d& p1, const AcGePoint3d& p2, const AcGePoint3d& p3, const AcGePoint3d& p4)
{
    return PyAcad3DFace{ impObj()->Add3DFace(p1,p2,p3,p4) };
}

PyAcadPolygonMesh PyAcadBlock::add3DMesh(int M, int N, const boost::python::object& iterable)
{
    return PyAcadPolygonMesh{ impObj()->Add3DMesh(M,N,py_list_to_std_vector<AcGePoint3d>(iterable)) };
}

PyAcad3DPolyline PyAcadBlock::add3DPoly(const boost::python::object& iterable)
{
    return PyAcad3DPolyline{ impObj()->Add3DPoly(py_list_to_std_vector<AcGePoint3d>(iterable)) };
}

PyAcadArc PyAcadBlock::addArc(const AcGePoint3d& center, double radius, double startAngle, double endAngle)
{
    return PyAcadArc{ impObj()->AddArc(center, radius, startAngle, endAngle) };
}

PyAcadAttribute PyAcadBlock::addAttribute(double Height, PyAcAttributeMode mode, const std::string& prompt, const AcGePoint3d& insertionPoint, const std::string& tag, const std::string& value)
{
    return PyAcadAttribute{ impObj()->AddAttribute(Height, mode, utf8_to_wstr(prompt).c_str(), insertionPoint,utf8_to_wstr(tag).c_str(),utf8_to_wstr(value).c_str()) };
}

PyAcad3DSolid PyAcadBlock::addBox(const AcGePoint3d& origin, double length, double width, double height)
{
    return PyAcad3DSolid(impObj()->AddBox(origin, length, width, height));
}

PyAcadCircle PyAcadBlock::addCircle(const AcGePoint3d& center, double radius)
{
    return PyAcadCircle(impObj()->AddCircle(center, radius));
}

PyAcad3DSolid PyAcadBlock::addCone(const AcGePoint3d& center, double baseRadius, double height)
{
    return PyAcad3DSolid{ impObj()->AddCone(center,baseRadius,height) };
}

PyAcad3DSolid PyAcadBlock::addCylinder(const AcGePoint3d& center, double radius, double height)
{
    return PyAcad3DSolid{ impObj()->AddCylinder(center,radius,height) };
}

PyAcadDimAligned PyAcadBlock::addDimAligned(const AcGePoint3d& extLine1Point, const AcGePoint3d& extLine2Point, const AcGePoint3d& textPosition)
{
    return PyAcadDimAligned{ impObj()->AddDimAligned(extLine1Point, extLine2Point, textPosition) };
}

PyAcadDimAngular PyAcadBlock::addDimAngular(const AcGePoint3d& angleVertex, const AcGePoint3d& firstEndPoint, const AcGePoint3d& secondEndPoint, const AcGePoint3d& textPosition)
{
    return PyAcadDimAngular{ impObj()->AddDimAngular(angleVertex, firstEndPoint, secondEndPoint, textPosition) };
}

PyAcadBlock PyAcadBlock::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadBlock>(src);
}

std::string PyAcadBlock::className()
{
    return "AcadBlock";
}

PyIAcadBlockImpl* PyAcadBlock::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadBlockImpl*>(m_pyImp.get());
}

void PyAcadBlock::filliterator()
{
    const auto& items = impObj()->GetIter();
    m_iterable.clear();
    m_iterable.reserve(items.size());
    for (const auto& item : items)
        m_iterable.emplace_back(PyAcadEntity{ item });
}

std::vector<PyAcadEntity>::iterator PyAcadBlock::begin()
{
    return m_iterable.begin();
}

std::vector<PyAcadEntity>::iterator PyAcadBlock::end()
{
    filliterator();
    return m_iterable.end();
}

//----------------------------------------------------------------------------------------
//PyModelSpace
void makePyModelSpaceWrapper()
{
    PyDocString DS("ModelSpace");
    class_<PyAcadModelSpace, bases<PyAcadBlock>>("ModelSpace", boost::python::no_init)
        .def("cast", &PyAcadModelSpace::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadModelSpace::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadModelSpace::PyAcadModelSpace(std::shared_ptr<PyIAcadModelSpaceImpl> ptr)
    : PyAcadBlock(ptr)
{
}

PyAcadModelSpace PyAcadModelSpace::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadModelSpace>(src);
}

std::string PyAcadModelSpace::className()
{
    return "AcadModelSpace";
}

PyIAcadModelSpaceImpl* PyAcadModelSpace::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadModelSpaceImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyPaperSpace
void makePyPaperSpaceWrapper()
{
    PyDocString DS("PaperSpace");
    class_<PyAcadPaperSpace, bases<PyAcadBlock>>("PaperSpace", boost::python::no_init)
        .def("cast", &PyAcadPaperSpace::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadPaperSpace::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadPaperSpace::PyAcadPaperSpace(std::shared_ptr<PyIAcadPaperSpaceImpl> ptr)
    : PyAcadBlock(ptr)
{
}

PyAcadPaperSpace PyAcadPaperSpace::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadPaperSpace>(src);
}

std::string PyAcadPaperSpace::className()
{
    return "AcadPaperSpace";
}

PyIAcadPaperSpaceImpl* PyAcadPaperSpace::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadPaperSpaceImpl*>(m_pyImp.get());
}

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
        .def("zoomScaled", &PyAcadApplication::zoomScaled, DS.ARGS({ "magnify: float","scaletype: PyAx.AcZoomScaleType" }))
        .def("activeDocument", &PyAcadApplication::activeDocument, DS.ARGS())
        .def("setActiveDocument", &PyAcadApplication::setActiveDocument, DS.ARGS({ "doc : PyAx.AcadDocument" }))
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
        .def("preferences", &PyAcadApplication::preferences, DS.ARGS())
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

PyAcadPreferences PyAcadApplication::preferences()
{
    return PyAcadPreferences(impObj()->GetPreferences());
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
        .def("modelSpace", &PyAcadDatabase::modelSpace, DS.ARGS())
        .def("paperSpace", &PyAcadDatabase::paperSpace, DS.ARGS())
        .def("summaryInfo", &PyAcadDatabase::summaryInfo, DS.ARGS())
        .def("className", &PyAcadDatabase::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadDatabase::PyAcadDatabase(std::shared_ptr<PyIAcadDatabaseImpl> ptr) noexcept
    : m_pyImp(ptr)
{
}

PyAcadModelSpace PyAcadDatabase::modelSpace() const
{
    return PyAcadModelSpace{ impObj()->GetModelSpace() };
}

PyAcadPaperSpace PyAcadDatabase::paperSpace() const
{
    return PyAcadPaperSpace{ impObj()->GetPaperSpace() };
}

PyAcadSummaryInfo PyAcadDatabase::summaryInfo() const
{
    return PyAcadSummaryInfo{ impObj()->GetSummaryInfo() };
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
    class_<PyAcadDocument, bases<PyAcadDatabase>>("AcadDocument", no_init)
        .def("name", &PyAcadDocument::name, DS.ARGS())
        .def("database", &PyAcadDocument::database, DS.ARGS())
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

PyAcadDatabase PyAcadDocument::database()
{
    return PyAcadDatabase{ impObj()->GetDatabase() };
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
