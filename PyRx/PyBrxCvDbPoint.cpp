#include "stdafx.h"
#include "PyBrxCvDbPoint.h"
#include "PyDbObjectId.h"

#ifdef BRXAPP

#include "BrxCvDbPoint.h"

using namespace boost::python;
void makePyBrxCvDbPointWrapper()
{
    PyDocString DS("CvDbPoint");
    class_<PyBrxCvDbPoint, bases<PyBrxCvDbEntity>>("CvDbPoint")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.ARGS({ "id: ObjectId", "mode: PyDb.OpenMode=kForRead", "erased: bool=False" })))

        .def("number", &PyBrxCvDbPoint::number)
        .def("setNumber", &PyBrxCvDbPoint::setNumber)
        .def("rawDescription", &PyBrxCvDbPoint::rawDescription)
        .def("setRawDescription", &PyBrxCvDbPoint::setRawDescription)
        .def("fullDescription", &PyBrxCvDbPoint::fullDescription)
        .def("easting", &PyBrxCvDbPoint::easting)
        .def("setEasting", &PyBrxCvDbPoint::setEasting)
        .def("northing", &PyBrxCvDbPoint::northing)
        .def("setNorthing", &PyBrxCvDbPoint::setNorthing)
        .def("elevation", &PyBrxCvDbPoint::elevation)
        .def("setElevation", &PyBrxCvDbPoint::setElevation)
        .def("position", &PyBrxCvDbPoint::position)
        .def("setPosition", &PyBrxCvDbPoint::setPosition)
        .def("pointGroupsIds", &PyBrxCvDbPoint::pointGroupsIds)
        .def("pointGroupsNames", &PyBrxCvDbPoint::pointGroupsNames)
        .def("symbolId", &PyBrxCvDbPoint::symbolId)
        .def("setSymbolId", &PyBrxCvDbPoint::setSymbolId)
        .def("labelId", &PyBrxCvDbPoint::labelId)
        .def("setLabelId", &PyBrxCvDbPoint::setLabelId)
        .def("labelPosition", &PyBrxCvDbPoint::labelPosition)
        .def("setLabelPosition", &PyBrxCvDbPoint::setLabelPosition)
        .def("symbolRotation", &PyBrxCvDbPoint::symbolRotation)
        .def("setSymbolRotation", &PyBrxCvDbPoint::setSymbolRotation)
        .def("labelRotation", &PyBrxCvDbPoint::labelRotation)
        .def("setLabelRotation", &PyBrxCvDbPoint::setLabelRotation)
        .def("isLabelPinned", &PyBrxCvDbPoint::isLabelPinned)
        .def("setLabelPinned", &PyBrxCvDbPoint::setLabelPinned)
        .def("isLabelDragged", &PyBrxCvDbPoint::isLabelDragged)
        .def("labelLeaderVertices", &PyBrxCvDbPoint::labelLeaderVertices)
        .def("setLabelLeaderVertices", &PyBrxCvDbPoint::setLabelLeaderVertices)
        .def("resetLabel", &PyBrxCvDbPoint::resetLabel)
        .def("referencedEntityCount", &PyBrxCvDbPoint::referencedEntityCount)
        //.def("referencedEntityAt", &PyBrxCvDbPoint::referencedEntityAt)
        .def("update", &PyBrxCvDbPoint::update)
       
        .def("className", &PyBrxCvDbPoint::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrxCvDbPoint::desc, DS.SARGS()).staticmethod("desc")
        .def("cloneFrom", &PyBrxCvDbPoint::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyBrxCvDbPoint::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyBrxCvDbPoint::PyBrxCvDbPoint()
    : PyBrxCvDbPoint(new BrxCvDbPoint(),true)
{
}

PyBrxCvDbPoint::PyBrxCvDbPoint(const PyDbObjectId& id)
    : PyBrxCvDbPoint(openAcDbObject<BrxCvDbPoint>(id), false)
{
}

PyBrxCvDbPoint::PyBrxCvDbPoint(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyBrxCvDbPoint(openAcDbObject<BrxCvDbPoint>(id, mode), false)
{
}

PyBrxCvDbPoint::PyBrxCvDbPoint(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyBrxCvDbPoint(openAcDbObject<BrxCvDbPoint>(id, mode, erased), false)
{
}

PyBrxCvDbPoint::PyBrxCvDbPoint(BrxCvDbPoint* ptr, bool autoDelete)
    :PyBrxCvDbEntity(ptr, autoDelete)
{
}

Adesk::UInt32 PyBrxCvDbPoint::number() const
{
    return impObj()->number();
}

bool PyBrxCvDbPoint::setNumber(const Adesk::UInt32 number)
{
    return impObj()->setNumber(number);
}

const std::string PyBrxCvDbPoint::rawDescription() const
{
    return wstr_to_utf8(impObj()->rawDescription());
}

bool PyBrxCvDbPoint::setRawDescription(const std::string& szDescription)
{
    return impObj()->setRawDescription(utf8_to_wstr(szDescription).c_str());
}

const std::string PyBrxCvDbPoint::fullDescription() const
{
    return wstr_to_utf8(impObj()->fullDescription());
}

double PyBrxCvDbPoint::easting() const
{
    return impObj()->easting();
}

bool PyBrxCvDbPoint::setEasting(double easting)
{
    return impObj()->setEasting(easting);
}

double PyBrxCvDbPoint::northing() const
{
    return impObj()->northing();
}

bool PyBrxCvDbPoint::setNorthing(double northing)
{
    return impObj()->setNorthing(northing);
}

double PyBrxCvDbPoint::elevation() const
{
    return impObj()->elevation();
}

bool PyBrxCvDbPoint::setElevation(double elevation)
{
    return impObj()->setElevation(elevation);
}

AcGePoint3d PyBrxCvDbPoint::position() const
{
    return impObj()->position();
}

bool PyBrxCvDbPoint::setPosition(const AcGePoint3d& value)
{
    return impObj()->setPosition(value);
}

boost::python::list PyBrxCvDbPoint::pointGroupsIds() const
{
    return ObjectIdArrayToPyList(impObj()->pointGroupsIds());
}

boost::python::list PyBrxCvDbPoint::pointGroupsNames() const
{
    return AcStringArrayToPyList(impObj()->pointGroupsNames());
}

PyDbObjectId PyBrxCvDbPoint::symbolId() const
{
    return PyDbObjectId(impObj()->symbolId());
}

bool PyBrxCvDbPoint::setSymbolId(const PyDbObjectId& symbolId)
{
    return impObj()->setSymbolId(symbolId.m_id);
}

PyDbObjectId PyBrxCvDbPoint::labelId() const
{
    return PyDbObjectId(impObj()->labelId());
}

bool PyBrxCvDbPoint::setLabelId(const PyDbObjectId& labelId)
{
    return impObj()->setLabelId(labelId.m_id);
}

AcGePoint3d PyBrxCvDbPoint::labelPosition() const
{
    return impObj()->labelPosition();
}

bool PyBrxCvDbPoint::setLabelPosition(const AcGePoint3d& position)
{
    return impObj()->setLabelPosition(position);
}

double PyBrxCvDbPoint::symbolRotation() const
{
    return impObj()->symbolRotation();
}

bool PyBrxCvDbPoint::setSymbolRotation(double rotation)
{
    return impObj()->setSymbolRotation(rotation);
}

double PyBrxCvDbPoint::labelRotation() const
{
    return impObj()->labelRotation();
}

bool PyBrxCvDbPoint::setLabelRotation(double rotation)
{
    return impObj()->setLabelRotation(rotation);
}

bool PyBrxCvDbPoint::isLabelPinned() const
{
    return impObj()->isLabelPinned();
}

bool PyBrxCvDbPoint::setLabelPinned(bool value)
{
    return impObj()->setLabelPinned(value);
}

bool PyBrxCvDbPoint::isLabelDragged() const
{
    return impObj()->isLabelDragged();
}

boost::python::list PyBrxCvDbPoint::labelLeaderVertices() const
{
  return Point3dArrayToPyList(impObj()->labelLeaderVertices());
}

bool PyBrxCvDbPoint::setLabelLeaderVertices(const boost::python::list& vertices)
{
    return impObj()->setLabelLeaderVertices(PyListToPoint3dArray(vertices));
}

bool PyBrxCvDbPoint::resetLabel()
{
    return impObj()->resetLabel();
}

Adesk::UInt32 PyBrxCvDbPoint::referencedEntityCount() const
{
    return impObj()->referencedEntityCount();
}

bool PyBrxCvDbPoint::update()
{
    return impObj()->update();
}

std::string PyBrxCvDbPoint::className()
{
    return "BrxCvDbPoint";
}

PyRxClass PyBrxCvDbPoint::desc()
{
    return PyRxClass(BrxCvDbPoint::desc(), false);
}

PyBrxCvDbPoint PyBrxCvDbPoint::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(BrxCvDbPoint::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyBrxCvDbPoint(static_cast<BrxCvDbPoint*>(src.impObj()->clone()), true);
}

PyBrxCvDbPoint PyBrxCvDbPoint::cast(const PyRxObject& src)
{
    PyBrxCvDbPoint dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

BrxCvDbPoint* PyBrxCvDbPoint::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<BrxCvDbPoint*>(m_pyImp.get());
}
#endif //BRXAPP