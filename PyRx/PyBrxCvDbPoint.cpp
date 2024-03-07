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

        .def("number", &PyBrxCvDbPoint::number, DS.ARGS())
        .def("setNumber", &PyBrxCvDbPoint::setNumber, DS.ARGS({ "val : int" }))
        .def("rawDescription", &PyBrxCvDbPoint::rawDescription, DS.ARGS())
        .def("setRawDescription", &PyBrxCvDbPoint::setRawDescription, DS.ARGS({ "val : str" }))
        .def("fullDescription", &PyBrxCvDbPoint::fullDescription, DS.ARGS())
        .def("easting", &PyBrxCvDbPoint::easting, DS.ARGS())
        .def("setEasting", &PyBrxCvDbPoint::setEasting, DS.ARGS({ "val : float" }))
        .def("northing", &PyBrxCvDbPoint::northing, DS.ARGS())
        .def("setNorthing", &PyBrxCvDbPoint::setNorthing, DS.ARGS({ "val : float" }))
        .def("elevation", &PyBrxCvDbPoint::elevation, DS.ARGS())
        .def("setElevation", &PyBrxCvDbPoint::setElevation, DS.ARGS({ "val : float" }))
        .def("position", &PyBrxCvDbPoint::position, DS.ARGS())
        .def("setPosition", &PyBrxCvDbPoint::setPosition, DS.ARGS({ "pt : PyGe.Point3d" }))
        .def("pointGroupsIds", &PyBrxCvDbPoint::pointGroupsIds, DS.ARGS())
        .def("pointGroupsNames", &PyBrxCvDbPoint::pointGroupsNames, DS.ARGS())
        .def("symbolId", &PyBrxCvDbPoint::symbolId, DS.ARGS())
        .def("setSymbolId", &PyBrxCvDbPoint::setSymbolId, DS.ARGS({ "id : PyDb.ObjectId" }))
        .def("labelId", &PyBrxCvDbPoint::labelId, DS.ARGS())
        .def("setLabelId", &PyBrxCvDbPoint::setLabelId, DS.ARGS({ "id : PyDb.ObjectId" }))
        .def("labelPosition", &PyBrxCvDbPoint::labelPosition, DS.ARGS())
        .def("setLabelPosition", &PyBrxCvDbPoint::setLabelPosition, DS.ARGS({ "pt : PyGe.Point3d" }))
        .def("symbolRotation", &PyBrxCvDbPoint::symbolRotation, DS.ARGS())
        .def("setSymbolRotation", &PyBrxCvDbPoint::setSymbolRotation, DS.ARGS({ "val : float" }))
        .def("labelRotation", &PyBrxCvDbPoint::labelRotation, DS.ARGS())
        .def("setLabelRotation", &PyBrxCvDbPoint::setLabelRotation, DS.ARGS({ "val : float" }))
        .def("isLabelPinned", &PyBrxCvDbPoint::isLabelPinned, DS.ARGS())
        .def("setLabelPinned", &PyBrxCvDbPoint::setLabelPinned, DS.ARGS({ "val : bool" }))
        .def("isLabelDragged", &PyBrxCvDbPoint::isLabelDragged, DS.ARGS())
        .def("labelLeaderVertices", &PyBrxCvDbPoint::labelLeaderVertices, DS.ARGS())
        .def("setLabelLeaderVertices", &PyBrxCvDbPoint::setLabelLeaderVertices, DS.ARGS({ "vertices : list[PyGe.Point3d]" }))
        .def("resetLabel", &PyBrxCvDbPoint::resetLabel, DS.ARGS())
        .def("referencedEntityCount", &PyBrxCvDbPoint::referencedEntityCount, DS.ARGS())
        .def("referencedEntityAt", &PyBrxCvDbPoint::referencedEntityAt, DS.ARGS({ "val : int" }))
        .def("update", &PyBrxCvDbPoint::update, DS.ARGS())
       
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

PyBrxCvDbPointReferencedEntity PyBrxCvDbPoint::referencedEntityAt(Adesk::UInt32 index) const
{
    auto ptr = impObj()->referencedEntityAt(index);
    if (ptr.refCount() == 1)
        return PyBrxCvDbPointReferencedEntity(ptr.detach(), true);
    throw PyAcadErrorStatus(Acad::eInvalidOpenState);
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

//-----------------------------------------------------------------------------------
//PyBrxCvDbPointReferencedEntity
void makePyBrxCvDbPointReferencedEntityWrapper()
{
    PyDocString DS("CvDbPointReferencedEntity");
    class_<PyBrxCvDbPointReferencedEntity, bases<PyBrxCvDbSubObject>>("CvDbPointReferencedEntity")
        .def(init<>())
        .def("id", &PyBrxCvDbPointReferencedEntity::id, DS.ARGS())
        .def("setId", &PyBrxCvDbPointReferencedEntity::setId, DS.ARGS({ "id : PyDb.ObjectId" }))
        .def("type", &PyBrxCvDbPointReferencedEntity::type, DS.ARGS())
        .def("className", &PyBrxCvDbPointReferencedEntity::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrxCvDbPointReferencedEntity::desc, DS.SARGS()).staticmethod("desc")
        .def("cast", &PyBrxCvDbPointReferencedEntity::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyBrxCvDbPointReferencedEntity::PyBrxCvDbPointReferencedEntity()
   : PyBrxCvDbPointReferencedEntity(new BrxCvDbPointReferencedEntity(), true)
{
}

PyBrxCvDbPointReferencedEntity::PyBrxCvDbPointReferencedEntity(BrxCvDbPointReferencedEntity* ptr, bool autoDelete)
    :PyBrxCvDbSubObject(ptr, autoDelete)
{
}

PyDbObjectId PyBrxCvDbPointReferencedEntity::id() const
{
    return PyDbObjectId(impObj()->id());
}

bool PyBrxCvDbPointReferencedEntity::setId(const PyDbObjectId& value)
{
    return impObj()->setId(value.m_id);
}

PyRxClass PyBrxCvDbPointReferencedEntity::type() const
{
    return PyRxClass(impObj()->type(), false);
}

std::string PyBrxCvDbPointReferencedEntity::className()
{
    return "BrxCvDbPointReferencedEntity";
}

PyRxClass PyBrxCvDbPointReferencedEntity::desc()
{
    return PyRxClass(BrxCvDbPointReferencedEntity::desc(), false);
}

PyBrxCvDbPointReferencedEntity PyBrxCvDbPointReferencedEntity::cast(const PyRxObject& src)
{
    PyBrxCvDbPointReferencedEntity dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

BrxCvDbPointReferencedEntity* PyBrxCvDbPointReferencedEntity::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<BrxCvDbPointReferencedEntity*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//PyBrxCvDbPointGroup
void makePyBrxCvDbPointGroupWrapper()
{
    PyDocString DS("CvDbPointGroup");
    class_<PyBrxCvDbPointGroup, bases<PyBrxCvDbObject>>("CvDbPointGroup")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.ARGS({ "id: ObjectId", "mode: PyDb.OpenMode=kForRead", "erased: bool=False" })))

        .def("className", &PyBrxCvDbPointGroup::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrxCvDbPointGroup::desc, DS.SARGS()).staticmethod("desc")
        .def("cloneFrom", &PyBrxCvDbPointGroup::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyBrxCvDbPointGroup::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyBrxCvDbPointGroup::PyBrxCvDbPointGroup()
    : PyBrxCvDbPointGroup(new BrxCvDbPointGroup(),true)
{
}

PyBrxCvDbPointGroup::PyBrxCvDbPointGroup(const PyDbObjectId& id)
    : PyBrxCvDbPointGroup(openAcDbObject<BrxCvDbPointGroup>(id), false)
{
}

PyBrxCvDbPointGroup::PyBrxCvDbPointGroup(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyBrxCvDbPointGroup(openAcDbObject<BrxCvDbPointGroup>(id, mode), false)
{
}

PyBrxCvDbPointGroup::PyBrxCvDbPointGroup(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyBrxCvDbPointGroup(openAcDbObject<BrxCvDbPointGroup>(id, mode, erased), false)
{
}

PyBrxCvDbPointGroup::PyBrxCvDbPointGroup(BrxCvDbPointGroup* ptr, bool autoDelete)
  : PyBrxCvDbObject(ptr, autoDelete)
{
}

std::string PyBrxCvDbPointGroup::className()
{
    return "BrxCvDbPointGroup";
}

PyRxClass PyBrxCvDbPointGroup::desc()
{
    return PyRxClass(BrxCvDbPointGroup::desc(), false);
}

PyBrxCvDbPointGroup PyBrxCvDbPointGroup::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(BrxCvDbPointGroup::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyBrxCvDbPointGroup(static_cast<BrxCvDbPointGroup*>(src.impObj()->clone()), true);
}

PyBrxCvDbPointGroup PyBrxCvDbPointGroup::cast(const PyRxObject& src)
{
    PyBrxCvDbPointGroup dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

BrxCvDbPointGroup* PyBrxCvDbPointGroup::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<BrxCvDbPointGroup*>(m_pyImp.get());
}
#endif //BRXAPP

