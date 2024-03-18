#include "stdafx.h"
#include "PyDbMline.h"
#include "PyDbObjectId.h"
#include "PyGeEntity3d.h"
#include "PyGePlane.h"

using namespace boost::python;

void makePyDbMlineWrapper()
{
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
        .def(init<const PyDbObjectId&, AcDb::OpenMode,bool>(DS.ARGS({ "id: ObjectId", "mode: OpenMode=kForRead", "erased: bool=False" })))
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
        .def("desc", &PyDbMline::desc, DS.SARGS()).staticmethod("desc")
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

void PyDbMline::setStyle(const PyDbObjectId& newStyleId)
{
    return PyThrowBadEs(impObj()->setStyle(newStyleId.m_id));
}

PyDbObjectId PyDbMline::style() const
{
    return PyDbObjectId(impObj()->style());
}

void PyDbMline::setJustification(Mline::MlineJustification newJust)
{
    return PyThrowBadEs(impObj()->setJustification(newJust));
}

Mline::MlineJustification PyDbMline::justification() const
{
    return impObj()->justification();
}

void PyDbMline::setScale(double newScale)
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

void PyDbMline::setNormal(const AcGeVector3d& newNormal)
{
    return PyThrowBadEs(impObj()->setNormal(newNormal));
}

void PyDbMline::appendSeg(const AcGePoint3d& newVertex)
{
    return PyThrowBadEs(impObj()->appendSeg(newVertex));
}

void PyDbMline::removeLastSeg(AcGePoint3d& lastVertex)
{
    return PyThrowBadEs(impObj()->removeLastSeg(lastVertex));
}

void PyDbMline::moveVertexAt(int index, const AcGePoint3d& newPosition)
{
    return PyThrowBadEs(impObj()->moveVertexAt(index, newPosition));
}

void PyDbMline::setClosedMline(bool closed)
{
    return PyThrowBadEs(impObj()->setClosedMline(closed));
}

bool PyDbMline::closedMline() const
{
    return impObj()->closedMline();
}

void PyDbMline::setSupressStartCaps(bool supressIt)
{
    return impObj()->setSupressStartCaps(supressIt);
}

bool PyDbMline::supressStartCaps() const
{
    return impObj()->supressStartCaps();
}

void PyDbMline::setSupressEndCaps(bool supressIt)
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
#if defined(_BRXTARGET) && _BRXTARGET <= 240
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
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return impObj()->axisAt(index);
#endif
}

AcGeVector3d PyDbMline::miterAt(int index) const
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return impObj()->miterAt(index);
#endif
}

AcGePoint3d PyDbMline::getClosestPointTo1(const AcGePoint3d& givenPoint, bool extend) const
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    AcGePoint3d pnt;
    PyThrowBadEs(impObj()->getClosestPointTo(givenPoint, pnt, extend));
    return pnt;
#endif
}

AcGePoint3d PyDbMline::getClosestPointTo2(const AcGePoint3d& givenPoint, bool extend, bool excludeCaps) const
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    AcGePoint3d pnt;
    PyThrowBadEs(impObj()->getClosestPointTo(givenPoint, pnt, extend, excludeCaps));
    return pnt;
#endif
}

AcGePoint3d PyDbMline::getClosestPointTo3(const AcGePoint3d& givenPoint, const AcGeVector3d& normal, bool extend) const
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    AcGePoint3d pnt;
    PyThrowBadEs(impObj()->getClosestPointTo(givenPoint, normal, pnt, extend));
    return pnt;
#endif
}

AcGePoint3d PyDbMline::getClosestPointTo4(const AcGePoint3d& givenPoint, const AcGeVector3d& normal, bool extend, bool excludeCaps) const
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
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
    if (!src.impObj()->isKindOf(AcDbMline::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbMline(static_cast<AcDbMline*>(src.impObj()->clone()), true);
}

PyDbMline PyDbMline::cast(const PyRxObject& src)
{
    PyDbMline dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
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
    class_<PyDbMlineStyle, bases<PyDbObject>>("MlineStyle")
        .def(init<>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("initMlineStyle", &PyDbMlineStyle::initMlineStyle)
        .def("set", &PyDbMlineStyle::set1)
        .def("set", &PyDbMlineStyle::set2)
        .def("setDescription", &PyDbMlineStyle::setDescription)
        .def("description", &PyDbMlineStyle::description)
        .def("setName", &PyDbMlineStyle::setName)
        .def("name", &PyDbMlineStyle::name)
        .def("setShowMiters", &PyDbMlineStyle::setShowMiters)
        .def("showMiters", &PyDbMlineStyle::showMiters)
        .def("setStartSquareCap", &PyDbMlineStyle::setStartSquareCap)
        .def("startSquareCap", &PyDbMlineStyle::startSquareCap)
        .def("setStartRoundCap", &PyDbMlineStyle::setStartRoundCap)
        .def("startRoundCap", &PyDbMlineStyle::startRoundCap)
        .def("setStartInnerArcs", &PyDbMlineStyle::setStartInnerArcs)
        .def("startInnerArcs", &PyDbMlineStyle::startInnerArcs)
        .def("setEndSquareCap", &PyDbMlineStyle::setEndSquareCap)
        .def("endSquareCap", &PyDbMlineStyle::endSquareCap)
        .def("setEndRoundCap", &PyDbMlineStyle::setEndRoundCap)
        .def("endRoundCap", &PyDbMlineStyle::endRoundCap)
        .def("setEndInnerArcs", &PyDbMlineStyle::setEndInnerArcs)
        .def("endInnerArcs", &PyDbMlineStyle::endInnerArcs)
        .def("setFillColor", &PyDbMlineStyle::setFillColor)
        .def("fillColor", &PyDbMlineStyle::fillColor)
        .def("setFilled", &PyDbMlineStyle::setFilled)
        .def("filled", &PyDbMlineStyle::filled)
        .def("setStartAngle", &PyDbMlineStyle::setStartAngle)
        .def("startAngle", &PyDbMlineStyle::startAngle)
        .def("setEndAngle", &PyDbMlineStyle::setEndAngle)
        .def("endAngle", &PyDbMlineStyle::endAngle)
        .def("addElement", &PyDbMlineStyle::addElement1)
        .def("addElement", &PyDbMlineStyle::addElement2)
        .def("removeElementAt", &PyDbMlineStyle::removeElementAt)
        .def("numElements", &PyDbMlineStyle::numElements)
        .def("setElement", &PyDbMlineStyle::setElement)
        .def("getElementAt", &PyDbMlineStyle::getElementAt)
        .def("className", &PyDbMlineStyle::className).staticmethod("className")
        .def("desc", &PyDbMlineStyle::desc).staticmethod("desc")
        .def("cloneFrom", &PyDbMlineStyle::cloneFrom).staticmethod("cloneFrom")
        .def("cast", &PyDbMlineStyle::cast).staticmethod("cast")
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

PyDbMlineStyle::PyDbMlineStyle(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbObject(openAcDbObject<AcDbMlineStyle>(id, mode), false)
{
}

void PyDbMlineStyle::initMlineStyle()
{
    impObj()->initMlineStyle();
}

void PyDbMlineStyle::set1(const PyDbMlineStyle& src)
{
    impObj()->set(*src.impObj());
}

void PyDbMlineStyle::set2(const PyDbMlineStyle& src, bool checkIfReferenced)
{
    impObj()->set(*src.impObj(), checkIfReferenced);
}

void PyDbMlineStyle::setDescription(const std::string& description)
{
    return PyThrowBadEs(impObj()->setDescription(utf8_to_wstr(description).c_str()));
}

std::string PyDbMlineStyle::description() const
{
    return wstr_to_utf8(impObj()->description());
}

void PyDbMlineStyle::setName(const std::string& name)
{
    return PyThrowBadEs(impObj()->setName(utf8_to_wstr(name).c_str()));
}

std::string PyDbMlineStyle::name() const
{
    return wstr_to_utf8(impObj()->name());
}

void PyDbMlineStyle::setShowMiters(bool showThem)
{
    impObj()->setShowMiters(showThem);
}

bool PyDbMlineStyle::showMiters() const
{
    return impObj()->showMiters();
}

void PyDbMlineStyle::setStartSquareCap(bool showIt)
{
    impObj()->setStartSquareCap(showIt);
}

bool PyDbMlineStyle::startSquareCap() const
{
    return impObj()->startSquareCap();
}

void PyDbMlineStyle::setStartRoundCap(bool showIt)
{
    impObj()->setStartRoundCap(showIt);
}

bool PyDbMlineStyle::startRoundCap() const
{
    return impObj()->startRoundCap();
}

void PyDbMlineStyle::setStartInnerArcs(bool showThem)
{
    impObj()->setStartInnerArcs(showThem);
}

bool PyDbMlineStyle::startInnerArcs() const
{
    return impObj()->startInnerArcs();
}

void PyDbMlineStyle::setEndSquareCap(bool showIt)
{
    impObj()->setEndSquareCap(showIt);
}

bool PyDbMlineStyle::endSquareCap() const
{
    return impObj()->endSquareCap();
}

void PyDbMlineStyle::setEndRoundCap(bool showIt)
{
    impObj()->setEndRoundCap(showIt);
}

bool PyDbMlineStyle::endRoundCap() const
{
    return impObj()->endRoundCap();
}

void PyDbMlineStyle::setEndInnerArcs(bool showThem)
{
    impObj()->setEndInnerArcs(showThem);
}

bool PyDbMlineStyle::endInnerArcs() const
{
    return impObj()->endInnerArcs();
}

void PyDbMlineStyle::setFillColor(const AcCmColor& color)
{
    return PyThrowBadEs(impObj()->setFillColor(color));
}

AcCmColor PyDbMlineStyle::fillColor() const
{
    return 	impObj()->fillColor();
}

void PyDbMlineStyle::setFilled(bool onOff)
{
    impObj()->setFilled(onOff);
}

bool PyDbMlineStyle::filled() const
{
    return impObj()->filled();
}

void PyDbMlineStyle::setStartAngle(double ang)
{
    return	PyThrowBadEs(impObj()->setStartAngle(ang));
}

double PyDbMlineStyle::startAngle() const
{
    return impObj()->startAngle();
}

void PyDbMlineStyle::setEndAngle(double ang)
{
    return PyThrowBadEs(impObj()->setEndAngle(ang));
}

double PyDbMlineStyle::endAngle() const
{
    return impObj()->startAngle();
}

int PyDbMlineStyle::addElement1(double offset, const AcCmColor& color, PyDbObjectId& linetypeId)
{
    int idx = 0;
    PyThrowBadEs(impObj()->addElement(idx, offset, color, linetypeId.m_id));
    return idx;
}

int PyDbMlineStyle::addElement2(double offset, const AcCmColor& color, PyDbObjectId& linetypeId, bool checkIfReferenced)
{
    int idx = 0;
    PyThrowBadEs(impObj()->addElement(idx, offset, color, linetypeId.m_id, checkIfReferenced));
    return idx;
}

void PyDbMlineStyle::removeElementAt(int elem)
{
    return PyThrowBadEs(impObj()->removeElementAt(elem));
}

int PyDbMlineStyle::numElements() const
{
    return impObj()->numElements();
}

int PyDbMlineStyle::setElement(double offset, const AcCmColor& color, PyDbObjectId& linetypeId)
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
    if (!src.impObj()->isKindOf(AcDbMlineStyle::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbMlineStyle(static_cast<AcDbMlineStyle*>(src.impObj()->clone()), true);
}

PyDbMlineStyle PyDbMlineStyle::cast(const PyRxObject& src)
{
    PyDbMlineStyle dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

AcDbMlineStyle* PyDbMlineStyle::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbMlineStyle*>(m_pyImp.get());
}
