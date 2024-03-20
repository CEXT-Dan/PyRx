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
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.ARGS({ "id: ObjectId", "mode: PyDb.OpenMode=PyDb.OpenMode.kForRead", "erased: bool=False" })))

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
    : PyBrxCvDbPoint(new BrxCvDbPoint(), true)
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
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.ARGS({ "id: ObjectId", "mode: PyDb.OpenMode=PyDb.OpenMode.kForRead", "erased: bool=False" })))

        .def("hasPoint", &PyBrxCvDbPointGroup::hasPoint, DS.ARGS({ "val : int" }))
        .def("pointCount", &PyBrxCvDbPointGroup::pointCount, DS.ARGS())
        .def("pointIds", &PyBrxCvDbPointGroup::pointIds, DS.ARGS())
        .def("isEditable", &PyBrxCvDbPointGroup::isEditable, DS.ARGS())
        .def("isApplicable", &PyBrxCvDbPointGroup::isApplicable, DS.ARGS())
        .def("includeNumbers", &PyBrxCvDbPointGroup::includeNumbers, DS.ARGS())
        .def("excludeNumbers", &PyBrxCvDbPointGroup::excludeNumbers, DS.ARGS())
        .def("includeElevations", &PyBrxCvDbPointGroup::includeElevations, DS.ARGS())
        .def("excludeElevations", &PyBrxCvDbPointGroup::excludeElevations)
        .def("includeRawDescriptions", &PyBrxCvDbPointGroup::includeRawDescriptions, DS.ARGS())
        .def("excludeRawDescriptions", &PyBrxCvDbPointGroup::excludeRawDescriptions, DS.ARGS())
        .def("includeFullDescriptions", &PyBrxCvDbPointGroup::includeFullDescriptions, DS.ARGS())
        .def("excludeFullDescriptions", &PyBrxCvDbPointGroup::excludeFullDescriptions, DS.ARGS())
        .def("includeNames", &PyBrxCvDbPointGroup::includeNames, DS.ARGS())
        .def("excludeNames", &PyBrxCvDbPointGroup::excludeNames, DS.ARGS())
        .def("includeUserAttributesKeys", &PyBrxCvDbPointGroup::includeUserAttributesKeys, DS.ARGS())
        .def("excludeUserAttributesKeys", &PyBrxCvDbPointGroup::excludeUserAttributesKeys, DS.ARGS())
        .def("includeUserAttributesValues", &PyBrxCvDbPointGroup::includeUserAttributesValues, DS.ARGS())
        .def("excludeUserAttributesValues", &PyBrxCvDbPointGroup::excludeUserAttributesValues, DS.ARGS())
        .def("setIncludeNumbers", &PyBrxCvDbPointGroup::setIncludeNumbers, DS.ARGS({ "filter : str" }))
        .def("setExcludeNumbers", &PyBrxCvDbPointGroup::setExcludeNumbers, DS.ARGS({ "filter : str" }))
        .def("setIncludeElevations", &PyBrxCvDbPointGroup::setIncludeElevations, DS.ARGS({ "filter : str" }))
        .def("setExcludeElevations", &PyBrxCvDbPointGroup::setExcludeElevations, DS.ARGS({ "filter : str" }))
        .def("setIncludeRawDescriptions", &PyBrxCvDbPointGroup::setIncludeRawDescriptions, DS.ARGS({ "filter : str" }))
        .def("setExcludeRawDescriptions", &PyBrxCvDbPointGroup::setExcludeRawDescriptions, DS.ARGS({ "filter : str" }))
        .def("setIncludeFullDescriptions", &PyBrxCvDbPointGroup::setIncludeFullDescriptions, DS.ARGS({ "filter : str" }))
        .def("setExcludeFullDescriptions", &PyBrxCvDbPointGroup::setExcludeFullDescriptions, DS.ARGS({ "filter : str" }))
        .def("setIncludeNames", &PyBrxCvDbPointGroup::setIncludeNames, DS.ARGS({ "filter : str" }))
        .def("setExcludeNames", &PyBrxCvDbPointGroup::setExcludeNames, DS.ARGS({ "filter : str" }))
        .def("setIncludeUserAttributesKeys", &PyBrxCvDbPointGroup::setIncludeUserAttributesKeys, DS.ARGS({ "filter : str" }))
        .def("setExcludeUserAttributesKeys", &PyBrxCvDbPointGroup::setExcludeUserAttributesKeys, DS.ARGS({ "filter : str" }))
        .def("setIncludeUserAttributesValues", &PyBrxCvDbPointGroup::setIncludeUserAttributesValues, DS.ARGS({ "filter : str" }))
        .def("updateNeeded", &PyBrxCvDbPointGroup::updateNeeded, DS.ARGS())
        .def("update", &PyBrxCvDbPointGroup::update, DS.ARGS())

        .def("className", &PyBrxCvDbPointGroup::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrxCvDbPointGroup::desc, DS.SARGS()).staticmethod("desc")
        .def("cloneFrom", &PyBrxCvDbPointGroup::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyBrxCvDbPointGroup::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyBrxCvDbPointGroup::PyBrxCvDbPointGroup()
    : PyBrxCvDbPointGroup(new BrxCvDbPointGroup(), true)
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

PyDbObjectId PyBrxCvDbPointGroup::hasPoint(Adesk::UInt32 number) const
{
    PyDbObjectId id;
    impObj()->hasPoint(number, id.m_id);
    return id;
}

Adesk::UInt32 PyBrxCvDbPointGroup::pointCount() const
{
    return impObj()->pointCount();
}

boost::python::list PyBrxCvDbPointGroup::pointIds() const
{
    return ObjectIdArrayToPyList(impObj()->pointIds());
}

bool PyBrxCvDbPointGroup::isEditable() const
{
    return impObj()->isEditable();
}

bool PyBrxCvDbPointGroup::isApplicable(const PyBrxCvDbPoint& point) const
{
    return impObj()->isApplicable(point.impObj());
}

std::string PyBrxCvDbPointGroup::includeNumbers() const
{
    return wstr_to_utf8(impObj()->includeNumbers());
}

std::string PyBrxCvDbPointGroup::excludeNumbers() const
{
    return wstr_to_utf8(impObj()->excludeNumbers());
}

std::string PyBrxCvDbPointGroup::includeElevations() const
{
    return wstr_to_utf8(impObj()->includeElevations());
}

std::string PyBrxCvDbPointGroup::excludeElevations() const
{
    return wstr_to_utf8(impObj()->excludeElevations());
}

std::string PyBrxCvDbPointGroup::includeRawDescriptions() const
{
    return wstr_to_utf8(impObj()->includeRawDescriptions());
}

std::string PyBrxCvDbPointGroup::excludeRawDescriptions() const
{
    return wstr_to_utf8(impObj()->excludeRawDescriptions());
}

std::string PyBrxCvDbPointGroup::includeFullDescriptions() const
{
    return wstr_to_utf8(impObj()->includeFullDescriptions());
}

std::string PyBrxCvDbPointGroup::excludeFullDescriptions() const
{
    return wstr_to_utf8(impObj()->excludeFullDescriptions());
}

std::string PyBrxCvDbPointGroup::includeNames() const
{
    return wstr_to_utf8(impObj()->includeNames());
}

std::string PyBrxCvDbPointGroup::excludeNames() const
{
    return wstr_to_utf8(impObj()->excludeNames());
}

std::string PyBrxCvDbPointGroup::includeUserAttributesKeys() const
{
    return wstr_to_utf8(impObj()->includeUserAttributesKeys());
}

std::string PyBrxCvDbPointGroup::excludeUserAttributesKeys() const
{
    return wstr_to_utf8(impObj()->excludeUserAttributesKeys());
}

std::string PyBrxCvDbPointGroup::includeUserAttributesValues() const
{
    return wstr_to_utf8(impObj()->includeUserAttributesValues());
}

std::string PyBrxCvDbPointGroup::excludeUserAttributesValues() const
{
    return wstr_to_utf8(impObj()->excludeUserAttributesValues());
}

bool PyBrxCvDbPointGroup::setIncludeNumbers(const std::string& szFilter)
{
    return impObj()->setIncludeNumbers(utf8_to_wstr(szFilter).c_str());
}

bool PyBrxCvDbPointGroup::setExcludeNumbers(const std::string& szFilter)
{
    return impObj()->setExcludeNumbers(utf8_to_wstr(szFilter).c_str());
}

bool PyBrxCvDbPointGroup::setIncludeElevations(const std::string& szFilter)
{
    return impObj()->setIncludeElevations(utf8_to_wstr(szFilter).c_str());
}

bool PyBrxCvDbPointGroup::setExcludeElevations(const std::string& szFilter)
{
    return impObj()->setExcludeElevations(utf8_to_wstr(szFilter).c_str());
}

bool PyBrxCvDbPointGroup::setIncludeRawDescriptions(const std::string& szFilter)
{
    return impObj()->setIncludeRawDescriptions(utf8_to_wstr(szFilter).c_str());
}

bool PyBrxCvDbPointGroup::setExcludeRawDescriptions(const std::string& szFilter)
{
    return impObj()->setExcludeRawDescriptions(utf8_to_wstr(szFilter).c_str());
}

bool PyBrxCvDbPointGroup::setIncludeFullDescriptions(const std::string& szFilter)
{
    return impObj()->setIncludeFullDescriptions(utf8_to_wstr(szFilter).c_str());
}

bool PyBrxCvDbPointGroup::setExcludeFullDescriptions(const std::string& szFilter)
{
    return impObj()->setExcludeFullDescriptions(utf8_to_wstr(szFilter).c_str());
}

bool PyBrxCvDbPointGroup::setIncludeNames(const std::string& szFilter)
{
    return impObj()->setIncludeNames(utf8_to_wstr(szFilter).c_str());
}

bool PyBrxCvDbPointGroup::setExcludeNames(const std::string& szFilter)
{
    return impObj()->setExcludeNames(utf8_to_wstr(szFilter).c_str());
}

bool PyBrxCvDbPointGroup::setIncludeUserAttributesKeys(const std::string& szFilter)
{
    return impObj()->setIncludeUserAttributesKeys(utf8_to_wstr(szFilter).c_str());
}

bool PyBrxCvDbPointGroup::setExcludeUserAttributesKeys(const std::string& szFilter)
{
    return impObj()->setExcludeUserAttributesKeys(utf8_to_wstr(szFilter).c_str());
}

bool PyBrxCvDbPointGroup::setIncludeUserAttributesValues(const std::string& szFilter)
{
    return impObj()->setIncludeUserAttributesValues(utf8_to_wstr(szFilter).c_str());
}

bool PyBrxCvDbPointGroup::setExcludeUserAttributesValues(const std::string& szFilter)
{
    return impObj()->setExcludeUserAttributesValues(utf8_to_wstr(szFilter).c_str());
}

bool PyBrxCvDbPointGroup::updateNeeded() const
{
    return impObj()->updateNeeded();
}

bool PyBrxCvDbPointGroup::update()
{
    return impObj()->update();
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

