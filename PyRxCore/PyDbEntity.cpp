#include "stdafx.h"
#include "PyDbEntity.h"
#include "PyDbObjectId.h"
#include "PyCmColorBase.h"
#include "PyGePlane.h"
#include "PyDbGripData.h"

using namespace boost::python;
//----------------------------------------------------------------------------------------------------
//wrapper
void makePyDbEntityWrapper()
{
    constexpr const std::string_view intersectOverloads = "Overloads:\n"
        "- entity: PyDb.Entity, intType : PyDb.Intersect\n"
        "- entity: PyDb.Entity, intType : PyDb.Intersect, thisGsMarker : int, otherGsMarker : int\n"
        "- entity: PyDb.Entity, intType : PyDb.Intersect, plane : PyGe.Plane\n"
        "- entity: PyDb.Entity, intType : PyDb.Intersect, plane : PyGe.Plane, thisGsMarker : int, otherGsMarker : int\n";

    constexpr const std::string_view getGripPointsOverloads = "Overloads:\n"
        "- None: Any\n"
        "- curViewUnitSize: float, gripSize: int, curViewDir: PyGe.Vector3d, bitflags: int\n";

    constexpr const std::string_view setPlotStyleNameOverloads = "Overloads:\n"
        "- None: Any\n"
        "- nameType: PyDb.PlotStyleNameType, doSubents: bool\n"
        "- nameType: PyDb.PlotStyleNameType, newId: PyDb.ObjectId, doSubents: bool\n";

    PyDocString DS("PyDb.Entity");
    class_<PyDbEntity, bases<PyDbObject>>("Entity", boost::python::no_init)
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.ARGS({ "id: PyDb.ObjectId", "mode: PyDb.OpenMode=PyDb.OpenMode.kForRead", "erased: bool=False" }, 4270)))
        .def("blockId", &PyDbEntity::blockId, DS.ARGS(4286))
        .def("color", &PyDbEntity::color, DS.ARGS(4292))
        .def("setColor", &PyDbEntity::setColor1)
        .def("setColor", &PyDbEntity::setColor2)
        .def("setColor", &PyDbEntity::setColor3, DS.ARGS({ "clr: PyDb.AcCmColor", "dosubents : bool=True","db : PyDb.Database='current'" }, 4349))
        .def("colorIndex", &PyDbEntity::colorIndex, DS.ARGS())
        .def("setColorIndex", &PyDbEntity::setColorIndex1)
        .def("setColorIndex", &PyDbEntity::setColorIndex2, DS.ARGS({ "clr: int",  "dosubents : bool=True" }, 4350))
        .def("entityColor", &PyDbEntity::entityColor, DS.ARGS(4302))
        .def("transparency", &PyDbEntity::transparency, DS.ARGS())
        .def("setTransparency", &PyDbEntity::setTransparency1)
        .def("setTransparency", &PyDbEntity::setTransparency2, DS.ARGS({ "transparency: PyDb.Transparency",  "dosubents : bool=True" }, 4361))
        .def("layer", &PyDbEntity::layer, DS.ARGS(4327))
        .def("layerId", &PyDbEntity::layerId, DS.ARGS(4328))
        .def("setLayer", &PyDbEntity::setLayer1)
        .def("setLayer", &PyDbEntity::setLayer2)
        .def("setLayer", &PyDbEntity::setLayer3)
        .def("setLayer", &PyDbEntity::setLayer4)
        .def("setLayer", &PyDbEntity::setLayer5)
        .def("setLayer", &PyDbEntity::setLayer6, DS.ARGS({ "val: str|PyDb.ObjectId", "dosubents : bool=True","allowHiddenLayer : bool=False" }, 4352))
        .def("plotStyleName", &PyDbEntity::plotStyleName, DS.ARGS(4342))
        .def("getPlotStyleNameId", &PyDbEntity::getPlotStyleNameId, DS.ARGS(4314))
        .def("setPlotStyleName", &PyDbEntity::setPlotStyleName1)
        .def("setPlotStyleName", &PyDbEntity::setPlotStyleName2)
        .def("setPlotStyleName", &PyDbEntity::setPlotStyleName3, DS.OVRL(setPlotStyleNameOverloads, 4358))
        .def("linetype", &PyDbEntity::linetype, DS.ARGS(4330))
        .def("linetypeId", &PyDbEntity::linetypeId, DS.ARGS(4331))
        .def("setLinetype", &PyDbEntity::setLinetype1)
        .def("setLinetype", &PyDbEntity::setLinetype2)
        .def("setLinetype", &PyDbEntity::setLinetype3)
        .def("setLinetype", &PyDbEntity::setLinetype4, DS.ARGS({ "val: str|PyDb.ObjectId", "dosubents : bool=True" }, 4353))
        .def("material", &PyDbEntity::material, DS.ARGS(4336))
        .def("materialId", &PyDbEntity::materialId, DS.ARGS(4337))
        .def("setMaterial", &PyDbEntity::setMaterial1)
        .def("setMaterial", &PyDbEntity::setMaterial2)
        .def("setMaterial", &PyDbEntity::setMaterial3)
        .def("setMaterial", &PyDbEntity::setMaterial4, DS.ARGS({ "val: str|PyDb.ObjectId",  "dosubents : bool=True" }, 4356))
        .def("linetypeScale", &PyDbEntity::linetypeScale, DS.ARGS(4333))
        .def("setLinetypeScale", &PyDbEntity::setLinetypeScale1)
        .def("setLinetypeScale", &PyDbEntity::setLinetypeScale2, DS.ARGS({ "val: float",  "dosubents : bool=True" }, 4354))
        .def("visibility", &PyDbEntity::visibility, DS.ARGS(4402))
        .def("setVisibility", &PyDbEntity::setVisibility1)
        .def("setVisibility", &PyDbEntity::setVisibility2, DS.ARGS({ "val: PyDb.Visibility",  "dosubents : bool=True" }, 4362))
        .def("lineWeight", &PyDbEntity::lineWeight, DS.ARGS(4334))
        .def("setLineWeight", &PyDbEntity::setLineWeight1)
        .def("setLineWeight", &PyDbEntity::setLineWeight2, DS.ARGS({ "val: PyDb.LineWeight",  "dosubents : bool=True" }, 4355))
        .def("collisionType", &PyDbEntity::collisionType, DS.ARGS(4291))
        .def("castShadows", &PyDbEntity::castShadows, DS.ARGS(4289))
        .def("setCastShadows", &PyDbEntity::setCastShadows, DS.ARGS({ "val: bool" }, 4348))
        .def("receiveShadows", &PyDbEntity::receiveShadows, DS.ARGS(4345))
        .def("setReceiveShadows", &PyDbEntity::setReceiveShadows, DS.ARGS({ "val: bool" }, 4360))
        .def("setPropertiesFrom", &PyDbEntity::setPropertiesFrom1)
        .def("setPropertiesFrom", &PyDbEntity::setPropertiesFrom2, DS.ARGS({ "entity: PyDb.Entity",  "dosubents : bool=True" }, 4359))
        .def("isPlanar", &PyDbEntity::isPlanar, DS.ARGS(4326))
        .def("getPlane", &PyDbEntity::getPlane, DS.ARGS(4313))
        .def("getEcs", &PyDbEntity::getEcs, DS.ARGS(4305))
        .def("list", &PyDbEntity::list, DS.ARGS(4335))
        .def("intersectWith", &PyDbEntity::intersectWith1)
        .def("intersectWith", &PyDbEntity::intersectWith2)
        .def("intersectWith", &PyDbEntity::intersectWith3)
        .def("intersectWith", &PyDbEntity::intersectWith4, DS.OVRL(intersectOverloads, 4324))
        .def("transformBy", &PyDbEntity::transformBy, DS.ARGS({ "matrix3d: PyGe.Matrix3d" }, 4398))
        .def("recordGraphicsModified", &PyDbEntity::recordGraphicsModified, DS.ARGS(4346))
        .def("setDatabaseDefaults", &PyDbEntity::setDatabaseDefaults1)
        .def("setDatabaseDefaults", &PyDbEntity::setDatabaseDefaults2, DS.ARGS({ "db: PyDb.Database = 'current'" }, 4351))
        .def("getCompoundObjectTransform", &PyDbEntity::getCompoundObjectTransform, DS.ARGS(4304))
        .def("getGeomExtents", &PyDbEntity::getGeomExtents, DS.ARGS(4306))
        .def("getGeomExtents2d", &PyDbEntity::getGeomExtents2d, DS.ARGS())
        .def("draw", &PyDbEntity::draw, DS.ARGS(4296))
        .def("explode", &PyDbEntity::explode, DS.ARGS(4303))
        .def("getTransformedCopy", &PyDbEntity::getTransformedCopy, DS.ARGS({ "matrix3d: PyGe.Matrix3d" }, 4319))
        .def("addReactor", &PyDbEntity::addReactor, DS.ARGS({ "reactor: PyDb.EntityReactor" }))
        .def("removeReactor", &PyDbEntity::removeReactor, DS.ARGS({ "reactor: PyDb.EntityReactor" }))
        .def("getStretchPoints", &PyDbEntity::getStretchPoints, DS.ARGS(4315))
        .def("getGripPoints", &PyDbEntity::getGripPoints1)
        .def("getGripPoints", &PyDbEntity::getGripPoints2, DS.OVRL(getGripPointsOverloads, 4308))
        .def("addSubentPaths", &PyDbEntity::addSubentPaths, DS.ARGS({ "paths: list[PyDb.FullSubentPath]" }, 4283))
        .def("getSubentPathsAtGsMarker", &PyDbEntity::getSubentPathsAtGsMarker1, DS.ARGS({ "type: PyDb.SubentType","gsMark: int","pickPoint: PyGe.Point3d","viewXform: PyGe.Matrix3d" }, 4318))
        .def("highlight", &PyDbEntity::highlight1)
        .def("highlight", &PyDbEntity::highlight2, DS.ARGS({ "path: PyDb.FullSubentPath = ...","highlightAll : bool = False" }, 4322))
        .def("subent", &PyDbEntity::subentPtr, DS.ARGS({ "path: PyDb.FullSubentPath" }))
        .def("className", &PyDbEntity::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbEntity::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyDbEntity::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbEntity::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

//----------------------------------------------------------------------------------------------------
//PyDbEntity
PyDbEntity::PyDbEntity(AcDbEntity* ptr, bool autoDelete)
    : PyDbObject(ptr, autoDelete)
{
}

PyDbEntity::PyDbEntity(const PyDbObjectId& id)
    : PyDbObject(openAcDbObject<AcDbEntity>(id, AcDb::OpenMode::kForRead), false)
{
}

PyDbEntity::PyDbEntity(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbObject(openAcDbObject<AcDbEntity>(id, mode), false)
{
}

PyDbEntity::PyDbEntity(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbObject(openAcDbObject<AcDbEntity>(id, mode, erased), false)
{
}

PyDbObjectId PyDbEntity::blockId() const
{
    return PyDbObjectId(impObj()->blockId());
}

AcCmColor PyDbEntity::color() const
{
    return impObj()->color();
}

void PyDbEntity::setLayer1(const std::string& newVal) const
{
    return this->setLayer3(newVal, true, false);
}

void PyDbEntity::setLayer2(const std::string& newVal, bool doSubents) const
{
    return this->setLayer3(newVal, doSubents, false);
}

void PyDbEntity::setLayer3(const std::string& newVal, bool doSubents, bool allowHiddenLayer) const
{
    return PyThrowBadEs(impObj()->setLayer(utf8_to_wstr(newVal).c_str(), doSubents, allowHiddenLayer));
}

void PyDbEntity::setLayer4(const PyDbObjectId& newVal) const
{
    return this->setLayer6(newVal, true, false);
}

void PyDbEntity::setLayer5(const PyDbObjectId& newVal, bool doSubents) const
{
    return this->setLayer6(newVal, true, false);
}

void PyDbEntity::setLayer6(const PyDbObjectId& newVal, bool doSubents, bool allowHiddenLayer) const
{
    return PyThrowBadEs(impObj()->setLayer(newVal.m_id, doSubents, allowHiddenLayer));
}

std::string PyDbEntity::plotStyleName() const
{
#if defined(_BRXTARGET250)
    return wstr_to_utf8(impObj()->plotStyleName());
#else
    AcString str;
    PyThrowBadEs(impObj()->plotStyleName(str));
    return wstr_to_utf8(str);
#endif
}

PyDbObjectId PyDbEntity::getPlotStyleNameId() const
{
    AcDbObjectId id;
    impObj()->getPlotStyleNameId(id);
    return PyDbObjectId(id);
}

void PyDbEntity::setColor1(const AcCmColor& color) const
{
    return PyThrowBadEs(impObj()->setColor(color));
}

void PyDbEntity::setColor2(const AcCmColor& color, bool doSubents) const
{
    return PyThrowBadEs(impObj()->setColor(color, doSubents));
}

void PyDbEntity::setColor3(const AcCmColor& color, bool doSubents, PyDbDatabase& db) const
{
    return PyThrowBadEs(impObj()->setColor(color, doSubents, db.impObj()));
}

Adesk::UInt16 PyDbEntity::colorIndex() const
{
    return impObj()->colorIndex();
}

void PyDbEntity::setColorIndex1(Adesk::UInt16 color) const
{
    return PyThrowBadEs(impObj()->setColorIndex(color));
}

void PyDbEntity::setColorIndex2(Adesk::UInt16 color, Adesk::Boolean doSubents) const
{
    return PyThrowBadEs(impObj()->setColorIndex(color, doSubents));
}

AcCmEntityColor PyDbEntity::entityColor() const
{
    return impObj()->entityColor();
}

AcCmTransparency PyDbEntity::transparency() const
{
    return impObj()->transparency();
}

void PyDbEntity::setTransparency1(const AcCmTransparency& trans) const
{
    return PyThrowBadEs(impObj()->setTransparency(trans, true));
}

void PyDbEntity::setTransparency2(const AcCmTransparency& trans, Adesk::Boolean doSubents) const
{
    return PyThrowBadEs(impObj()->setTransparency(trans, doSubents));
}

std::string PyDbEntity::layer() const
{
    return  wstr_to_utf8(impObj()->layer());
}

PyDbObjectId PyDbEntity::layerId() const
{
    return  PyDbObjectId(impObj()->layerId());
}

void PyDbEntity::setPlotStyleName1(const std::string& str, Adesk::Boolean doSubents) const
{
    return PyThrowBadEs(impObj()->setPlotStyleName(utf8_to_wstr(str).c_str(), doSubents));
}

void PyDbEntity::setPlotStyleName2(AcDb::PlotStyleNameType tp, Adesk::Boolean doSubents) const
{
    return PyThrowBadEs(impObj()->setPlotStyleName(tp, AcDbObjectId::kNull, doSubents));
}

void PyDbEntity::setPlotStyleName3(AcDb::PlotStyleNameType tp, const PyDbObjectId& newId, Adesk::Boolean doSubents) const
{
    return PyThrowBadEs(impObj()->setPlotStyleName(tp, newId.m_id, doSubents));
}

std::string PyDbEntity::linetype() const
{
    return  wstr_to_utf8(impObj()->linetype());
}

PyDbObjectId PyDbEntity::linetypeId() const
{
    return  PyDbObjectId(impObj()->linetypeId());
}

void PyDbEntity::setLinetype1(const std::string& newVal) const
{
    return PyThrowBadEs(impObj()->setLinetype(utf8_to_wstr(newVal).c_str()));
}

void PyDbEntity::setLinetype2(const std::string& newVal, Adesk::Boolean doSubents) const
{
    return PyThrowBadEs(impObj()->setLinetype(utf8_to_wstr(newVal).c_str(), doSubents));
}

void PyDbEntity::setLinetype3(const PyDbObjectId& newVal) const
{
    return PyThrowBadEs(impObj()->setLinetype(newVal.m_id));
}

void PyDbEntity::setLinetype4(const PyDbObjectId& newVal, Adesk::Boolean doSubents) const
{
    return PyThrowBadEs(impObj()->setLinetype(newVal.m_id, doSubents));
}

std::string PyDbEntity::material() const
{
    return wstr_to_utf8(impObj()->material());
}

PyDbObjectId PyDbEntity::materialId() const
{
    return PyDbObjectId(impObj()->materialId());
}

void PyDbEntity::setMaterial1(const std::string& newVal) const
{
    return PyThrowBadEs(impObj()->setMaterial(utf8_to_wstr(newVal).c_str()));
}

void PyDbEntity::setMaterial2(const std::string& newVal, Adesk::Boolean doSubents) const
{
    return PyThrowBadEs(impObj()->setMaterial(utf8_to_wstr(newVal).c_str(), doSubents));
}

void PyDbEntity::setMaterial3(const PyDbObjectId& newVal) const
{
    return PyThrowBadEs(impObj()->setLinetype(newVal.m_id));
}

void PyDbEntity::setMaterial4(const PyDbObjectId& newVal, Adesk::Boolean doSubents) const
{
    return PyThrowBadEs(impObj()->setLinetype(newVal.m_id, doSubents));
}

double PyDbEntity::linetypeScale() const
{
    return impObj()->linetypeScale();
}

void PyDbEntity::setLinetypeScale1(double newval) const
{
    return PyThrowBadEs(impObj()->setLinetypeScale(newval));
}

void PyDbEntity::setLinetypeScale2(double newval, Adesk::Boolean doSubents) const
{
    return PyThrowBadEs(impObj()->setLinetypeScale(newval, doSubents));
}

AcDb::Visibility PyDbEntity::visibility() const
{
    return impObj()->visibility();
}

void PyDbEntity::setVisibility1(AcDb::Visibility newVal) const
{
    return PyThrowBadEs(impObj()->setVisibility(newVal));
}

void PyDbEntity::setVisibility2(AcDb::Visibility newVal, Adesk::Boolean doSubents /*= true*/) const
{
    return PyThrowBadEs(impObj()->setVisibility(newVal, doSubents));
}

AcDb::LineWeight PyDbEntity::lineWeight() const
{
    return impObj()->lineWeight();
}

void PyDbEntity::setLineWeight1(AcDb::LineWeight newVal) const
{
    return PyThrowBadEs(impObj()->setLineWeight(newVal));
}

void PyDbEntity::setLineWeight2(AcDb::LineWeight newVal, Adesk::Boolean doSubents) const
{
    return PyThrowBadEs(impObj()->setLineWeight(newVal, doSubents));
}

AcDb::CollisionType PyDbEntity::collisionType() const
{
    return impObj()->collisionType();
}

bool PyDbEntity::castShadows() const
{
    return impObj()->castShadows();
}

void PyDbEntity::setCastShadows(bool newVal) const
{
    impObj()->setCastShadows(newVal);
}

bool PyDbEntity::receiveShadows() const
{
    return impObj()->receiveShadows();
}

void PyDbEntity::setReceiveShadows(bool newVal) const
{
    impObj()->setReceiveShadows(newVal);
}

void PyDbEntity::setPropertiesFrom1(const PyDbEntity& pEntity) const
{
    return PyThrowBadEs(impObj()->setPropertiesFrom(pEntity.impObj()));
}

void PyDbEntity::setPropertiesFrom2(const PyDbEntity& pEntity, Adesk::Boolean doSubents) const
{
    return PyThrowBadEs(impObj()->setPropertiesFrom(pEntity.impObj(), doSubents));
}

Adesk::Boolean PyDbEntity::isPlanar() const
{
    return impObj()->isPlanar();
}

PyGePlane PyDbEntity::getPlane() const
{
    AcGePlane plane;
    AcDb::Planarity val;
    PyThrowBadEs(impObj()->getPlane(plane, val));
    if (val == AcDb::kNonPlanar)
        throw PyErrorStatusException(Acad::eNotApplicable);
    return PyGePlane(plane);
}

AcGeMatrix3d PyDbEntity::getEcs() const
{
    AcGeMatrix3d retVal;
    impObj()->getEcs(retVal);
    return retVal;
}

void PyDbEntity::list() const
{
    impObj()->list();
}

void PyDbEntity::transformBy(const AcGeMatrix3d& xform) const
{
    return PyThrowBadEs(impObj()->transformBy(xform));
}

void PyDbEntity::recordGraphicsModified() const
{
    impObj()->recordGraphicsModified();
}

void PyDbEntity::draw() const
{
    return PyThrowBadEs(impObj()->draw());
}

void PyDbEntity::setDatabaseDefaults1() const
{
    impObj()->setDatabaseDefaults();
}

void PyDbEntity::setDatabaseDefaults2(const PyDbDatabase& db) const
{
    impObj()->setDatabaseDefaults(db.impObj());
}

AcGeMatrix3d PyDbEntity::getCompoundObjectTransform() const
{
    AcGeMatrix3d xMat;
    PyThrowBadEs(impObj()->getCompoundObjectTransform(xMat));
    return xMat;
}

AcDbExtents PyDbEntity::getGeomExtents() const
{
    AcDbExtents extents;
    PyThrowBadEs(impObj()->getGeomExtents(extents));
    return extents;
}

AcDbExtents2d PyDbEntity::getGeomExtents2d() const
{
    AcDbExtents extents;
    PyThrowBadEs(impObj()->getGeomExtents(extents));
    return AcDbExtents2d(extents.minPoint().convert2d(AcGePlane::kXYPlane), extents.maxPoint().convert2d(AcGePlane::kXYPlane));
}

boost::python::list PyDbEntity::intersectWith1(const PyDbEntity& pEnt, AcDb::Intersect intType) const
{
    return intersectWith2(pEnt, intType, 0, 0);
}

boost::python::list PyDbEntity::intersectWith2(const PyDbEntity& pEnt, AcDb::Intersect intType, Adesk::GsMarker thisGsMarker, Adesk::GsMarker otherGsMarker) const
{
    AcGePoint3dArray pnts;
    PyThrowBadEs(impObj()->intersectWith(pEnt.impObj(), intType, pnts, thisGsMarker, otherGsMarker));
    return Point3dArrayToPyList(pnts);
}

boost::python::list PyDbEntity::intersectWith3(const PyDbEntity& pEnt, AcDb::Intersect intType, const PyGePlane& projPlane) const
{
    return intersectWith4(pEnt, intType, projPlane, 0, 0);
}

boost::python::list PyDbEntity::intersectWith4(const PyDbEntity& pEnt, AcDb::Intersect intType, const PyGePlane& projPlane, Adesk::GsMarker thisGsMarker, Adesk::GsMarker otherGsMarker) const
{
    AcGePoint3dArray pnts;
    PyThrowBadEs(impObj()->intersectWith(pEnt.impObj(), intType, *projPlane.impObj(), pnts, thisGsMarker, otherGsMarker));
    return Point3dArrayToPyList(pnts);
}

boost::python::list PyDbEntity::explode() const
{
    PyAutoLockGIL lock;
    AcDbVoidPtrArray _ents;
    boost::python::list ents;
    PyThrowBadEs(impObj()->explode(_ents));
    for (auto item : _ents)
        ents.append(PyDbEntity(static_cast<AcDbEntity*>(item), true));
    return ents;
}

PyDbEntity PyDbEntity::getTransformedCopy(const AcGeMatrix3d& xform) const
{
    AcDbEntity* pEnt = nullptr;
    PyThrowBadEs(impObj()->getTransformedCopy(xform, pEnt));
    return PyDbEntity(pEnt, true);
}

void PyDbEntity::addReactor(PyDbEntityReactor& pReactor) const
{
    return PyThrowBadEs(impObj()->addReactor(pReactor.impObj()));
}

void PyDbEntity::removeReactor(PyDbEntityReactor& pReactor) const
{
    return PyThrowBadEs(impObj()->removeReactor(pReactor.impObj()));
}

boost::python::list PyDbEntity::getStretchPoints() const
{
    AcGePoint3dArray points;
    PyThrowBadEs(impObj()->getStretchPoints(points));
    return Point3dArrayToPyList(points);
}

boost::python::tuple PyDbEntity::getGripPoints1() const
{
    AcGePoint3dArray _gripPoints;
    AcDbIntArray _osnapModes;
    AcDbIntArray _geomIds;
    PyThrowBadEs(impObj()->getGripPoints(_gripPoints, _osnapModes, _geomIds));
    PyAutoLockGIL lock;

    boost::python::list gripPoints;
    boost::python::list osnapModes;
    boost::python::list geomIds;

    for (auto& item : _gripPoints)
        gripPoints.append(item);
    for (auto& item : _osnapModes)
        osnapModes.append(item);
    for (auto& item : _geomIds)
        geomIds.append(item);
    return boost::python::make_tuple(gripPoints, osnapModes, geomIds);
}

boost::python::list PyDbEntity::getGripPoints2(double curViewUnitSize, int gripSize, const AcGeVector3d& curViewDir, int bitflags) const
{
    PyAutoLockGIL lock;
    AcDbGripDataPtrArray ptrs;
    boost::python::list pylist;
    PyThrowBadEs(impObj()->getGripPoints(ptrs, curViewUnitSize, gripSize, curViewDir, bitflags));
    for (auto& item : ptrs)
        pylist.append(PyDbGripData(item));
    return pylist;
}

void PyDbEntity::addSubentPaths(const boost::python::list& newPaths) const
{
    PyThrowBadEs(impObj()->addSubentPaths(PyListToPyDbFullSubentPathArray(newPaths)));
}

boost::python::list PyDbEntity::getSubentPathsAtGsMarker1(AcDb::SubentType type, Adesk::GsMarker gsMark, const AcGePoint3d& pickPoint, const AcGeMatrix3d& viewXform) const
{
    int numIds = 0;
    AcDbFullSubentPath* subentIds = nullptr;
    PyThrowBadEs(impObj()->getSubentPathsAtGsMarker(type, gsMark, pickPoint, viewXform, numIds, subentIds));

    PyAutoLockGIL lock;
    boost::python::list pyList;
    for (int idx = 0; idx < numIds; idx++)
        pyList.append(PyDbFullSubentPath(subentIds[idx]));
    return pyList;
}

boost::python::list PyDbEntity::getSubentPathsAtGsMarker2(AcDb::SubentType type, Adesk::GsMarker gsMark, const AcGePoint3d& pickPoint, const AcGeMatrix3d& viewXform, int numInserts, PyDbObjectId& entAndInsertStack) const
{
    int numIds = 0;
    AcDbFullSubentPath* subentIds = nullptr;
    PyThrowBadEs(impObj()->getSubentPathsAtGsMarker(type, gsMark, pickPoint, viewXform, numIds, subentIds, numInserts, &entAndInsertStack.m_id));

    PyAutoLockGIL lock;
    boost::python::list pyList;
    for (int idx = 0; idx < numIds; idx++)
        pyList.append(PyDbFullSubentPath(subentIds[idx]));
    return pyList;
}

void PyDbEntity::highlight1() const
{
    PyThrowBadEs(impObj()->highlight());
}

void PyDbEntity::highlight2(const PyDbFullSubentPath& subId, const Adesk::Boolean highlightAll) const
{
    PyThrowBadEs(impObj()->highlight(subId.pyImp, highlightAll));
}

PyDbEntity PyDbEntity::subentPtr(const PyDbFullSubentPath& subId) const
{
    return PyDbEntity(impObj()->subentPtr(subId.pyImp), true);
}

std::string PyDbEntity::className()
{
    return "AcDbEntity";
}

PyRxClass PyDbEntity::desc()
{
    return PyRxClass(AcDbEntity::desc(), false);
}

PyDbEntity PyDbEntity::cloneFrom(const PyRxObject& src)
{
    return PyDbObjectCloneFrom<PyDbEntity, AcDbEntity>(src);
}

PyDbEntity PyDbEntity::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbEntity>(src);
}

AcDbEntity* PyDbEntity::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbEntity*>(m_pyImp.get());
}

//-------------------------------------------------------------------------------------------------------------
//PyDbBlockBegin
void makePyDbBlockBeginWrapper()
{
    PyDocString DS("BlockBegin");
    class_<PyDbBlockBegin, bases<PyDbEntity>>("BlockBegin", boost::python::no_init)
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>(DS.ARGS({ "id: PyDb.ObjectId", "mode: PyDb.OpenMode=PyDb.OpenMode.kForRead" })))
        .def("className", &PyDbBlockBegin::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbBlockBegin::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyDbBlockBegin::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbBlockBegin::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyDbBlockBegin::PyDbBlockBegin(AcDbBlockBegin* ptr, bool autoDelete)
    : PyDbEntity(ptr, autoDelete)
{
}

PyDbBlockBegin::PyDbBlockBegin(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbEntity(openAcDbObject<AcDbBlockBegin>(id, mode), false)
{
}

PyDbBlockBegin::PyDbBlockBegin(const PyDbObjectId& id)
    : PyDbBlockBegin(id, AcDb::OpenMode::kForRead)
{
}

std::string PyDbBlockBegin::className()
{
    return "AcDbBlockBegin";
}

PyRxClass PyDbBlockBegin::desc()
{
    return PyRxClass(AcDbBlockBegin::desc(), false);
}

PyDbBlockBegin PyDbBlockBegin::cloneFrom(const PyRxObject& src)
{
    return PyDbObjectCloneFrom<PyDbBlockBegin, AcDbBlockBegin>(src);
}

PyDbBlockBegin PyDbBlockBegin::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbBlockBegin>(src);
}

AcDbBlockBegin* PyDbBlockBegin::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbBlockBegin*>(m_pyImp.get());
}

//-------------------------------------------------------------------------------------------------------------
//PyDbBlockEnd
void makePyDbBlockEndWrapper()
{
    PyDocString DS("BlockEnd");
    class_<PyDbBlockEnd, bases<PyDbEntity>>("BlockEnd", boost::python::no_init)
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>(DS.ARGS({ "id: PyDb.ObjectId", "mode: PyDb.OpenMode=PyDb.OpenMode.kForRead" })))
        .def("className", &PyDbBlockEnd::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbBlockEnd::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyDbBlockEnd::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbBlockEnd::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyDbBlockEnd::PyDbBlockEnd(AcDbBlockEnd* ptr, bool autoDelete)
    : PyDbEntity(ptr, autoDelete)
{
}

PyDbBlockEnd::PyDbBlockEnd(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbEntity(openAcDbObject<AcDbBlockEnd>(id, mode), false)
{
}

PyDbBlockEnd::PyDbBlockEnd(const PyDbObjectId& id)
    : PyDbBlockEnd(id, AcDb::OpenMode::kForRead)
{
}

std::string PyDbBlockEnd::className()
{
    return "AcDbBlockEnd";
}

PyRxClass PyDbBlockEnd::desc()
{
    return PyRxClass(AcDbBlockEnd::desc(), false);
}

PyDbBlockEnd PyDbBlockEnd::cloneFrom(const PyRxObject& src)
{
    return PyDbObjectCloneFrom<PyDbBlockEnd, AcDbBlockEnd>(src);
}

PyDbBlockEnd PyDbBlockEnd::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbBlockEnd>(src);
}

AcDbBlockEnd* PyDbBlockEnd::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbBlockEnd*>(m_pyImp.get());
}

//-------------------------------------------------------------------------------------------------------------
//PyDbSequenceEnd
void makePyDbSequenceEndWrapper()
{
    PyDocString DS("SequenceEnd");
    class_<PyDbSequenceEnd, bases<PyDbEntity>>("SequenceEnd", boost::python::no_init)
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>(DS.ARGS({ "id: PyDb.ObjectId", "mode: PyDb.OpenMode=PyDb.OpenMode.kForRead" })))
        .def("className", &PyDbSequenceEnd::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbSequenceEnd::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyDbSequenceEnd::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbSequenceEnd::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyDbSequenceEnd::PyDbSequenceEnd(AcDbSequenceEnd* ptr, bool autoDelete)
    : PyDbEntity(ptr, autoDelete)
{
}

PyDbSequenceEnd::PyDbSequenceEnd(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbEntity(openAcDbObject<AcDbSequenceEnd>(id, mode), false)
{
}

PyDbSequenceEnd::PyDbSequenceEnd(const PyDbObjectId& id)
    : PyDbSequenceEnd(id, AcDb::OpenMode::kForRead)
{
}

std::string PyDbSequenceEnd::className()
{
    return "AcDbSequenceEnd";
}

PyRxClass PyDbSequenceEnd::desc()
{
    return PyRxClass(AcDbSequenceEnd::desc(), false);
}

PyDbSequenceEnd PyDbSequenceEnd::cloneFrom(const PyRxObject& src)
{
    return PyDbObjectCloneFrom<PyDbSequenceEnd, AcDbSequenceEnd>(src);
}

PyDbSequenceEnd PyDbSequenceEnd::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbSequenceEnd>(src);
}

AcDbSequenceEnd* PyDbSequenceEnd::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbSequenceEnd*>(m_pyImp.get());
}

//-------------------------------------------------------------------------------------------------------------
//PyDbSubentId
void makePyDbSubentIdWrapper()
{
    constexpr const std::string_view ctor = "Overloads:\n"
        "- None: Any\n"
        "- type: PyDb.SubentType, indexMarker: int\n"
        "- pTypeClass: PyRx.RxClass, indexMarker: int\n";

    PyDocString DS("PyDb.SubentId");
    class_<PyDbSubentId>("SubentId")
        .def(init<>())
        .def(init<AcDb::SubentType, Adesk::GsMarker>())
        .def(init<PyRxClass&, Adesk::GsMarker>(DS.CTOR(ctor)))
        .def("type", &PyDbSubentId::type, DS.ARGS(8845))
        .def("setType", &PyDbSubentId::setType, DS.ARGS({ "val: PyDb.SubentType" }, 8843))
        .def("typeClass", &PyDbSubentId::typeClass, DS.ARGS(8846))
        .def("setTypeClass", &PyDbSubentId::setTypeClass, DS.SARGS({ "val: PyRx.RxClass" }, 8844))
        .def("index", &PyDbSubentId::index, DS.ARGS(8841))
        .def("setIndex", &PyDbSubentId::setIndex, DS.ARGS({ "indexMarker: int" }, 8842))
        .add_static_property("kNull", &PyDbSubentId::kNull, DS.SARGS())
        //operators
        .def("__eq__", &PyDbSubentId::operator==)
        .def("__ne__", &PyDbSubentId::operator!=)
        ;
}

PyDbSubentId::PyDbSubentId()
    :m_pyImp(new AcDbSubentId())
{
}

PyDbSubentId::PyDbSubentId(AcDb::SubentType type, Adesk::GsMarker index)
    :m_pyImp(new AcDbSubentId(type, index))
{
}

PyDbSubentId::PyDbSubentId(PyRxClass& pTypeClass, Adesk::GsMarker index)
    :m_pyImp(new AcDbSubentId(pTypeClass.impObj(), index))
{
}

PyDbSubentId::PyDbSubentId(const AcDbSubentId& src)
    :m_pyImp(new AcDbSubentId(src))
{
}

AcDb::SubentType PyDbSubentId::type() const
{
    return impObj()->type();
}

void PyDbSubentId::setType(AcDb::SubentType et) const
{
    return impObj()->setType(et);
}

PyRxClass PyDbSubentId::typeClass() const
{
    return PyRxClass(impObj()->typeClass(), false);
}

void PyDbSubentId::setTypeClass(PyRxClass& pClass) const
{
    return impObj()->setTypeClass(pClass.impObj());
}

Adesk::GsMarker PyDbSubentId::index() const
{
    return impObj()->index();
}

void PyDbSubentId::setIndex(Adesk::GsMarker ind) const
{
    return impObj()->setIndex(ind);
}

const PyDbSubentId PyDbSubentId::kNull()
{
    return PyDbSubentId();
}

bool PyDbSubentId::operator!=(const PyDbSubentId& id) const
{
    return *impObj() != *id.impObj();
}

bool PyDbSubentId::operator==(const PyDbSubentId& id) const
{
    return *impObj() == *id.impObj();
}

AcDbSubentId* PyDbSubentId::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbSubentId*>(m_pyImp.get());
}

//-------------------------------------------------------------------------------------------------------------
//PyDbFullSubentPath
void makePyDbFullSubentPathWrapper()
{
    constexpr const std::string_view ctor = "Overloads:\n"
        "- None: Any\n"
        "- sub: PyDb.SubentType, gsMarker: int\n"
        "- id: PyDb.ObjectId, sub: PyDb.SubentType, gsMarker: int\n"
        "- id: PyDb.ObjectId, sub: PyDb.SubentId\n"
        "- ids: list[PyDb.ObjectId], sub: PyDb.SubentId\n";

    PyDocString DS("PyDb.FullSubentPath");
    class_<PyDbFullSubentPath>("FullSubentPath")
        .def(init<>())
        .def(init<AcDb::SubentType, Adesk::GsMarker>())
        .def(init<const PyDbObjectId&, AcDb::SubentType, Adesk::GsMarker>())
        .def(init<const PyDbObjectId&, const PyDbSubentId&>())
        .def(init<const boost::python::list&, const PyDbSubentId&>(DS.CTOR(ctor)))
        .def("setObjectIds", &PyDbFullSubentPath::setObjectIds, DS.ARGS({ "ids: list[PyDb.ObjectId]" }, 4741))
        .def("objectIds", &PyDbFullSubentPath::objectIds, DS.ARGS(4740))
        .def("setSubentId", &PyDbFullSubentPath::setSubentId, DS.ARGS({ "id: PyDb.SubentId" }, 4742))
        .def("subentId", &PyDbFullSubentPath::subentId, DS.ARGS(4744))
        .add_static_property("kNull", &PyDbSubentId::kNull, DS.SARGS())
        //operators
        .def("__eq__", &PyDbFullSubentPath::operator==)
        .def("__ne__", &PyDbFullSubentPath::operator!=)
        ;
}

PyDbFullSubentPath::PyDbFullSubentPath()
{
}

PyDbFullSubentPath::PyDbFullSubentPath(const AcDbFullSubentPath& src)
    : pyImp(src)
{
}

PyDbFullSubentPath::PyDbFullSubentPath(AcDb::SubentType type, Adesk::GsMarker index)
    : pyImp(type, index)
{
}

PyDbFullSubentPath::PyDbFullSubentPath(const PyDbObjectId& entId, AcDb::SubentType type, Adesk::GsMarker index)
    : pyImp(entId.m_id, type, index)
{
}

PyDbFullSubentPath::PyDbFullSubentPath(const PyDbObjectId& entId, const PyDbSubentId& subId)
    : pyImp(entId.m_id, *subId.impObj())
{
}

PyDbFullSubentPath::PyDbFullSubentPath(const boost::python::list& objectIds, const PyDbSubentId& subId)
    : pyImp(PyListToObjectIdArray(objectIds), *subId.impObj())
{
}

bool PyDbFullSubentPath::operator==(const PyDbFullSubentPath& id) const
{
    return pyImp == pyImp;
}

bool PyDbFullSubentPath::operator!=(const PyDbFullSubentPath& id) const
{
    return pyImp != pyImp;
}

void PyDbFullSubentPath::setObjectIds(const boost::python::list& objectIds)
{
#if defined (_ZRXTARGET240) || defined (_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    pyImp.setObjectIds(PyListToObjectIdArray(objectIds));
#endif
}

boost::python::list PyDbFullSubentPath::objectIds() const
{
    return ObjectIdArrayToPyList(pyImp.objectIds());
}

void PyDbFullSubentPath::setSubentId(const PyDbSubentId& subentId)
{
#if defined (_ZRXTARGET240) || defined (_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    pyImp.setSubentId(*subentId.impObj());
#endif
}

PyDbSubentId PyDbFullSubentPath::subentId() const
{
    return PyDbSubentId(pyImp.subentId());
}

PyDbFullSubentPath PyDbFullSubentPath::kNull()
{
    return PyDbFullSubentPath();
}
