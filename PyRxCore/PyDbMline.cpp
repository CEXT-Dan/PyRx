#include "stdafx.h"
#include "PyDbMline.h"
#include "PyDbObjectId.h"
#include "PyGeEntity3d.h"
#include "PyGePlane.h"

using namespace boost::python;

void makePyDbMlineWrapper()
{
    constexpr const std::string_view ctords = "Overloads:\n"
        "- None: Any\n"
        "- id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode, erased: bool\n";

    constexpr const std::string_view getClosestPointToOverloads = "Overloads:\n"
        "- givenPoint: PyGe.Point3d, extend: bool\n"
        "- givenPoint: PyGe.Point3d, extend: bool, excludeCaps: bool\n"
        "- givenPoint: PyGe.Point3d, normal: PyGe.Vector3d, extend: bool\n"
        "- givenPoint: PyGe.Point3d, normal: PyGe.Vector3d, extend: bool, excludeCaps: bool\n";

    PyDocString DS("Mline");
    class_<PyDbMline, bases<PyDbEntity>>("Mline")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.CTOR(ctords, 6645)))
        .def("setStyle", &PyDbMline::setStyle, DS.ARGS({ "val : PyDb.ObjectId" }))
        .def("style", &PyDbMline::style, DS.ARGS())
        .def("setJustification", &PyDbMline::setJustification, DS.ARGS({ "val : MlineJustification" }))
        .def("justification", &PyDbMline::justification, DS.ARGS())
        .def("setScale", &PyDbMline::setScale, DS.ARGS({ "val : float" }))
        .def("scale", &PyDbMline::scale, DS.ARGS())
        .def("normal", &PyDbMline::normal, DS.ARGS())
        .def("setNormal", &PyDbMline::setNormal, DS.ARGS({ "val : PyGe.Vector3d" }))
        .def("appendSeg", &PyDbMline::appendSeg, DS.ARGS({ "val : PyGe.Point3d" }))
        .def("removeLastSeg", &PyDbMline::removeLastSeg, DS.ARGS({ "val : PyGe.Point3d" }))
        .def("moveVertexAt", &PyDbMline::moveVertexAt, DS.ARGS({ "index : int","val : PyGe.Point3d" }))
        .def("setClosedMline", &PyDbMline::setClosedMline, DS.ARGS({ "val : bool" }))
        .def("closedMline", &PyDbMline::closedMline, DS.ARGS())
        .def("setSupressStartCaps", &PyDbMline::setSupressStartCaps, DS.ARGS({ "val : bool" }))
        .def("supressStartCaps", &PyDbMline::supressStartCaps, DS.ARGS())
        .def("setSupressEndCaps", &PyDbMline::setSupressEndCaps, DS.ARGS({ "val : bool" }))
        .def("supressEndCaps", &PyDbMline::supressEndCaps, DS.ARGS())
        .def("numVertices", &PyDbMline::numVertices, DS.ARGS())
        .def("element", &PyDbMline::element, DS.ARGS({ "val : PyGe.Point3d" }))
        .def("vertexAt", &PyDbMline::vertexAt, DS.ARGS({ "val : int" }))
        .def("axisAt", &PyDbMline::axisAt, DS.ARGS({ "val : int" }))
        .def("miterAt", &PyDbMline::miterAt, DS.ARGS({ "val : int" }))
        .def("getClosestPointTo", &PyDbMline::getClosestPointTo1)
        .def("getClosestPointTo", &PyDbMline::getClosestPointTo2)
        .def("getClosestPointTo", &PyDbMline::getClosestPointTo3)
        .def("getClosestPointTo", &PyDbMline::getClosestPointTo4, DS.OVRL(getClosestPointToOverloads))
        .def("getPlane", &PyDbMline::getPlane, DS.ARGS())
        .def("className", &PyDbMline::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbMline::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyDbMline::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbMline::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;

    enum_<Mline::MlineJustification>("MlineJustification")
        .value("kTop", Mline::kTop)
        .value("kZero", Mline::kZero)
        .value("kBottom", Mline::kBottom)
        .value("kOpen", Mline::kOpen)
        .value("kClosed", Mline::kClosed)
        .value("kMerged", Mline::kMerged)
        .export_values()
        ;
}

PyDbMline::PyDbMline()
    : PyDbEntity(new AcDbMline(), true)
{
}

PyDbMline::PyDbMline(AcDbMline* ptr, bool autoDelete)
    : PyDbEntity(ptr, autoDelete)
{
}

PyDbMline::PyDbMline(const PyDbObjectId& id)
    : PyDbEntity(openAcDbObject<AcDbMline>(id, AcDb::kForRead), false)
{
}

PyDbMline::PyDbMline(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbEntity(openAcDbObject<AcDbMline>(id, mode), false)
{
}

PyDbMline::PyDbMline(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbEntity(openAcDbObject<AcDbMline>(id, mode, erased), false)
{
}

void PyDbMline::setStyle(const PyDbObjectId& newStyleId) const
{
    return PyThrowBadEs(impObj()->setStyle(newStyleId.m_id));
}

PyDbObjectId PyDbMline::style() const
{
    return PyDbObjectId(impObj()->style());
}

void PyDbMline::setJustification(Mline::MlineJustification newJust) const
{
    return PyThrowBadEs(impObj()->setJustification(newJust));
}

Mline::MlineJustification PyDbMline::justification() const
{
    return impObj()->justification();
}

void PyDbMline::setScale(double newScale) const
{
    return PyThrowBadEs(impObj()->setScale(newScale));
}

double PyDbMline::scale() const
{
    return impObj()->scale();
}

AcGeVector3d PyDbMline::normal() const
{
    return impObj()->normal();
}

void PyDbMline::setNormal(const AcGeVector3d& newNormal) const
{
    return PyThrowBadEs(impObj()->setNormal(newNormal));
}

void PyDbMline::appendSeg(const AcGePoint3d& newVertex) const
{
    return PyThrowBadEs(impObj()->appendSeg(newVertex));
}

void PyDbMline::removeLastSeg(AcGePoint3d& lastVertex) const
{
    return PyThrowBadEs(impObj()->removeLastSeg(lastVertex));
}

void PyDbMline::moveVertexAt(int index, const AcGePoint3d& newPosition) const
{
    return PyThrowBadEs(impObj()->moveVertexAt(index, newPosition));
}

void PyDbMline::setClosedMline(bool closed) const
{
    return PyThrowBadEs(impObj()->setClosedMline(closed));
}

bool PyDbMline::closedMline() const
{
    return impObj()->closedMline();
}

void PyDbMline::setSupressStartCaps(bool supressIt) const
{
    return impObj()->setSupressStartCaps(supressIt);
}

bool PyDbMline::supressStartCaps() const
{
    return impObj()->supressStartCaps();
}

void PyDbMline::setSupressEndCaps(bool supressIt) const
{
    return impObj()->setSupressEndCaps(supressIt);
}

bool PyDbMline::supressEndCaps() const
{
    return impObj()->supressEndCaps();
}

int PyDbMline::numVertices() const
{
    return impObj()->numVertices();
}

int PyDbMline::element(const AcGePoint3d& pt) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return impObj()->element(pt);
#endif
}

AcGePoint3d PyDbMline::vertexAt(int index) const
{
    return impObj()->vertexAt(index);
}

AcGeVector3d PyDbMline::axisAt(int index) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return impObj()->axisAt(index);
#endif
}

AcGeVector3d PyDbMline::miterAt(int index) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return impObj()->miterAt(index);
#endif
}

AcGePoint3d PyDbMline::getClosestPointTo1(const AcGePoint3d& givenPoint, bool extend) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    AcGePoint3d pnt;
    PyThrowBadEs(impObj()->getClosestPointTo(givenPoint, pnt, extend));
    return pnt;
#endif
}

AcGePoint3d PyDbMline::getClosestPointTo2(const AcGePoint3d& givenPoint, bool extend, bool excludeCaps) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    AcGePoint3d pnt;
    PyThrowBadEs(impObj()->getClosestPointTo(givenPoint, pnt, extend, excludeCaps));
    return pnt;
#endif
}

AcGePoint3d PyDbMline::getClosestPointTo3(const AcGePoint3d& givenPoint, const AcGeVector3d& normal, bool extend) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    AcGePoint3d pnt;
    PyThrowBadEs(impObj()->getClosestPointTo(givenPoint, normal, pnt, extend));
    return pnt;
#endif
}

AcGePoint3d PyDbMline::getClosestPointTo4(const AcGePoint3d& givenPoint, const AcGeVector3d& normal, bool extend, bool excludeCaps) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    AcGePoint3d pnt;
    PyThrowBadEs(impObj()->getClosestPointTo(givenPoint, normal, pnt, extend, excludeCaps));
    return pnt;
#endif
}

PyGePlane PyDbMline::getPlane() const
{
    AcGePlane p;
    impObj()->getPlane(p);
    return PyGePlane(p);
}

std::string PyDbMline::className()
{
    return "AcDbMline";
}

PyRxClass PyDbMline::desc()
{
    return PyRxClass(AcDbFcf::desc(), false);
}

PyDbMline PyDbMline::cloneFrom(const PyRxObject& src)
{
    return PyDbObjectCloneFrom<PyDbMline, AcDbMline>(src);
}

PyDbMline PyDbMline::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbMline>(src);
}

AcDbMline* PyDbMline::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbMline*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//PyDbMlineStyle
void makePyDbMlineStyleWrapper()
{
    PyDocString DS("MlineStyle");
    class_<PyDbMlineStyle, bases<PyDbObject>>("MlineStyle")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.ARGS({ "id: PyDb.ObjectId", "mode: PyDb.OpenMode = PyDb.OpenMode.kForRead", "erased: bool=False" })))
        .def("initMlineStyle", &PyDbMlineStyle::initMlineStyle, DS.ARGS())
        .def("set", &PyDbMlineStyle::set1)
        .def("set", &PyDbMlineStyle::set2, DS.ARGS({ "src: PyDb.MlineStyle","checkIfReferenced: bool=True" }))
        .def("setDescription", &PyDbMlineStyle::setDescription, DS.ARGS({ "val: str" }))
        .def("description", &PyDbMlineStyle::description, DS.ARGS())
        .def("setName", &PyDbMlineStyle::setName, DS.ARGS({ "val: str" }))
        .def("name", &PyDbMlineStyle::name, DS.ARGS())
        .def("setShowMiters", &PyDbMlineStyle::setShowMiters, DS.ARGS({ "val: bool" }))
        .def("showMiters", &PyDbMlineStyle::showMiters, DS.ARGS())
        .def("setStartSquareCap", &PyDbMlineStyle::setStartSquareCap, DS.ARGS({ "val: bool" }))
        .def("startSquareCap", &PyDbMlineStyle::startSquareCap, DS.ARGS())
        .def("setStartRoundCap", &PyDbMlineStyle::setStartRoundCap, DS.ARGS({ "val: bool" }))
        .def("startRoundCap", &PyDbMlineStyle::startRoundCap, DS.ARGS())
        .def("setStartInnerArcs", &PyDbMlineStyle::setStartInnerArcs, DS.ARGS({ "val: bool" }))
        .def("startInnerArcs", &PyDbMlineStyle::startInnerArcs, DS.ARGS())
        .def("setEndSquareCap", &PyDbMlineStyle::setEndSquareCap, DS.ARGS({ "val: bool" }))
        .def("endSquareCap", &PyDbMlineStyle::endSquareCap, DS.ARGS())
        .def("setEndRoundCap", &PyDbMlineStyle::setEndRoundCap, DS.ARGS({ "val: bool" }))
        .def("endRoundCap", &PyDbMlineStyle::endRoundCap, DS.ARGS())
        .def("setEndInnerArcs", &PyDbMlineStyle::setEndInnerArcs, DS.ARGS({ "val: bool" }))
        .def("endInnerArcs", &PyDbMlineStyle::endInnerArcs, DS.ARGS())
        .def("setFillColor", &PyDbMlineStyle::setFillColor, DS.ARGS({ "clr: PyDb.AcCmColor" }))
        .def("fillColor", &PyDbMlineStyle::fillColor, DS.ARGS())
        .def("setFilled", &PyDbMlineStyle::setFilled, DS.ARGS({ "val: bool" }))
        .def("filled", &PyDbMlineStyle::filled, DS.ARGS())
        .def("setStartAngle", &PyDbMlineStyle::setStartAngle, DS.ARGS({ "val: float" }))
        .def("startAngle", &PyDbMlineStyle::startAngle, DS.ARGS())
        .def("setEndAngle", &PyDbMlineStyle::setEndAngle, DS.ARGS({ "val: float" }))
        .def("endAngle", &PyDbMlineStyle::endAngle, DS.ARGS())
        .def("addElement", &PyDbMlineStyle::addElement1)
        .def("addElement", &PyDbMlineStyle::addElement2, DS.ARGS({ "offset: float","clr: PyDb.AcCmColor","ltid: PyDb.ObjectId","checkIfReferenced: bool=True" }))
        .def("removeElementAt", &PyDbMlineStyle::removeElementAt, DS.ARGS({ "val: int" }))
        .def("numElements", &PyDbMlineStyle::numElements, DS.ARGS())
        .def("setElement", &PyDbMlineStyle::setElement, DS.ARGS({ "offset: float","clr: PyDb.AcCmColor","ltid: PyDb.ObjectId" }))
        .def("getElementAt", &PyDbMlineStyle::getElementAt, DS.ARGS({ "val: int" }))
        .def("className", &PyDbMlineStyle::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbMlineStyle::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyDbMlineStyle::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbMlineStyle::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyDbMlineStyle::PyDbMlineStyle()
    : PyDbObject(new AcDbMlineStyle(), true)
{
}

PyDbMlineStyle::PyDbMlineStyle(AcDbMlineStyle* ptr, bool autoDelete)
    : PyDbObject(ptr, autoDelete)
{
}

PyDbMlineStyle::PyDbMlineStyle(const PyDbObjectId& id)
    : PyDbObject(openAcDbObject<AcDbMlineStyle>(id, AcDb::OpenMode::kForRead), false)
{
}

PyDbMlineStyle::PyDbMlineStyle(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbObject(openAcDbObject<AcDbMlineStyle>(id, mode), false)
{
}

PyDbMlineStyle::PyDbMlineStyle(const PyDbObjectId& id, AcDb::OpenMode mode, bool openErased)
    : PyDbObject(openAcDbObject<AcDbMlineStyle>(id, mode, openErased), false)
{
}

void PyDbMlineStyle::initMlineStyle() const
{
    impObj()->initMlineStyle();
}

void PyDbMlineStyle::set1(const PyDbMlineStyle& src) const
{
    impObj()->set(*src.impObj());
}

void PyDbMlineStyle::set2(const PyDbMlineStyle& src, bool checkIfReferenced) const
{
    impObj()->set(*src.impObj(), checkIfReferenced);
}

void PyDbMlineStyle::setDescription(const std::string& description) const
{
    return PyThrowBadEs(impObj()->setDescription(utf8_to_wstr(description).c_str()));
}

std::string PyDbMlineStyle::description() const
{
    return wstr_to_utf8(impObj()->description());
}

void PyDbMlineStyle::setName(const std::string& name) const
{
    return PyThrowBadEs(impObj()->setName(utf8_to_wstr(name).c_str()));
}

std::string PyDbMlineStyle::name() const
{
    return wstr_to_utf8(impObj()->name());
}

void PyDbMlineStyle::setShowMiters(bool showThem) const
{
    impObj()->setShowMiters(showThem);
}

bool PyDbMlineStyle::showMiters() const
{
    return impObj()->showMiters();
}

void PyDbMlineStyle::setStartSquareCap(bool showIt) const
{
    impObj()->setStartSquareCap(showIt);
}

bool PyDbMlineStyle::startSquareCap() const
{
    return impObj()->startSquareCap();
}

void PyDbMlineStyle::setStartRoundCap(bool showIt) const
{
    impObj()->setStartRoundCap(showIt);
}

bool PyDbMlineStyle::startRoundCap() const
{
    return impObj()->startRoundCap();
}

void PyDbMlineStyle::setStartInnerArcs(bool showThem) const
{
    impObj()->setStartInnerArcs(showThem);
}

bool PyDbMlineStyle::startInnerArcs() const
{
    return impObj()->startInnerArcs();
}

void PyDbMlineStyle::setEndSquareCap(bool showIt) const
{
    impObj()->setEndSquareCap(showIt);
}

bool PyDbMlineStyle::endSquareCap() const
{
    return impObj()->endSquareCap();
}

void PyDbMlineStyle::setEndRoundCap(bool showIt) const
{
    impObj()->setEndRoundCap(showIt);
}

bool PyDbMlineStyle::endRoundCap() const
{
    return impObj()->endRoundCap();
}

void PyDbMlineStyle::setEndInnerArcs(bool showThem) const
{
    impObj()->setEndInnerArcs(showThem);
}

bool PyDbMlineStyle::endInnerArcs() const
{
    return impObj()->endInnerArcs();
}

void PyDbMlineStyle::setFillColor(const AcCmColor& color) const
{
    return PyThrowBadEs(impObj()->setFillColor(color));
}

AcCmColor PyDbMlineStyle::fillColor() const
{
    return 	impObj()->fillColor();
}

void PyDbMlineStyle::setFilled(bool onOff) const
{
    impObj()->setFilled(onOff);
}

bool PyDbMlineStyle::filled() const
{
    return impObj()->filled();
}

void PyDbMlineStyle::setStartAngle(double ang) const
{
    return	PyThrowBadEs(impObj()->setStartAngle(ang));
}

double PyDbMlineStyle::startAngle() const
{
    return impObj()->startAngle();
}

void PyDbMlineStyle::setEndAngle(double ang) const
{
    return PyThrowBadEs(impObj()->setEndAngle(ang));
}

double PyDbMlineStyle::endAngle() const
{
    return impObj()->startAngle();
}

int PyDbMlineStyle::addElement1(double offset, const AcCmColor& color, PyDbObjectId& linetypeId) const
{
    int idx = 0;
    PyThrowBadEs(impObj()->addElement(idx, offset, color, linetypeId.m_id));
    return idx;
}

int PyDbMlineStyle::addElement2(double offset, const AcCmColor& color, PyDbObjectId& linetypeId, bool checkIfReferenced) const
{
    int idx = 0;
    PyThrowBadEs(impObj()->addElement(idx, offset, color, linetypeId.m_id, checkIfReferenced));
    return idx;
}

void PyDbMlineStyle::removeElementAt(int elem) const
{
    return PyThrowBadEs(impObj()->removeElementAt(elem));
}

int PyDbMlineStyle::numElements() const
{
    return impObj()->numElements();
}

int PyDbMlineStyle::setElement(double offset, const AcCmColor& color, PyDbObjectId& linetypeId) const
{
    int idx = 0;
    PyThrowBadEs(impObj()->setElement(idx, offset, color, linetypeId.m_id));
    return idx;
}

boost::python::tuple PyDbMlineStyle::getElementAt(int elem) const
{
    double offset;
    AcCmColor color;
    AcDbObjectId linetypeId;
    PyThrowBadEs(impObj()->getElementAt(elem, offset, color, linetypeId));
    PyAutoLockGIL lock;
    return boost::python::make_tuple(offset, color, PyDbObjectId(linetypeId));
}

std::string PyDbMlineStyle::className()
{
    return "AcDbMlineStyle";
}

PyRxClass PyDbMlineStyle::desc()
{
    return PyRxClass(AcDbMlineStyle::desc(), false);
}

PyDbMlineStyle PyDbMlineStyle::cloneFrom(const PyRxObject& src)
{
    return PyDbObjectCloneFrom<PyDbMlineStyle, AcDbMlineStyle>(src);
}

PyDbMlineStyle PyDbMlineStyle::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbMlineStyle>(src);
}

AcDbMlineStyle* PyDbMlineStyle::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbMlineStyle*>(m_pyImp.get());
}
