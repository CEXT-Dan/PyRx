#include "stdafx.h"
#include "PyDbEntity.h"
#include "PyDbObjectId.h"
#include "PyCmColorBase.h"
#include "PyGePlane.h"
using namespace boost::python;
//----------------------------------------------------------------------------------------------------
//wrapper

constexpr const std::string_view intersectWithComments = "Other argument options:\n"
"- PyDb.Entity, PyDb.Intersect, GsMarker, GsMarker\n"
"- PyDb.Entity, PyDb.Intersect, PyGe.Plane\n"
"- PyDb.Entity, PyDb.Intersect, PyGe.Plane, GsMarker, GsMarker";

void makePyDbEntityWrapper()
{
    PyDocString DS("Entity");
    class_<PyDbEntity, bases<PyDbObject>>("Entity", boost::python::no_init)
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.ARGS({ "id: PyDb.ObjectId", "mode:  PyDb.OpenMode=kForRead", "erased: bool=False" })))
        .def("blockId", &PyDbEntity::blockId, DS.ARGS())
        .def("color", &PyDbEntity::color, DS.ARGS())
        .def("setColor", &PyDbEntity::setColor1)
        .def("setColor", &PyDbEntity::setColor2)
        .def("setColor", &PyDbEntity::setColor3, DS.ARGS({ "clr: AcCmColor", "dosubents : bool=True","db : Database=current" }))
        .def("colorIndex", &PyDbEntity::colorIndex, DS.ARGS())
        .def("setColorIndex", &PyDbEntity::setColorIndex1)
        .def("setColorIndex", &PyDbEntity::setColorIndex2, DS.ARGS({ "clr: int",  "dosubents : bool=True" }))
        .def("entityColor", &PyDbEntity::entityColor, DS.ARGS())
        .def("layer", &PyDbEntity::layer, DS.ARGS())
        .def("layerId", &PyDbEntity::layerId, DS.ARGS())
        .def("setLayer", &PyDbEntity::setLayer1)
        .def("setLayer", &PyDbEntity::setLayer2)
        .def("setLayer", &PyDbEntity::setLayer3)
        .def("setLayer", &PyDbEntity::setLayer4)
        .def("setLayer", &PyDbEntity::setLayer5)
        .def("setLayer", &PyDbEntity::setLayer6, DS.ARGS({ "val: str|ObjectId", "dosubents : bool=True","allowHiddenLayer : bool=False" }))
        .def("plotStyleName", &PyDbEntity::plotStyleName, DS.ARGS())
        .def("getPlotStyleNameId", &PyDbEntity::getPlotStyleNameId, DS.ARGS())
        .def("setPlotStyleName", &PyDbEntity::setPlotStyleName1)
        .def("setPlotStyleName", &PyDbEntity::setPlotStyleName2)
        .def("setPlotStyleName", &PyDbEntity::setPlotStyleName3)
        .def("linetype", &PyDbEntity::linetype, DS.ARGS())
        .def("linetypeId", &PyDbEntity::linetypeId, DS.ARGS())
        .def("setLinetype", &PyDbEntity::setLinetype1)
        .def("setLinetype", &PyDbEntity::setLinetype2)
        .def("setLinetype", &PyDbEntity::setLinetype3)
        .def("setLinetype", &PyDbEntity::setLinetype4, DS.ARGS({ "val: str|ObjectId", "dosubents : bool=True" }))
        .def("material", &PyDbEntity::material, DS.ARGS())
        .def("materialId", &PyDbEntity::materialId, DS.ARGS())
        .def("setMaterial", &PyDbEntity::setMaterial1)
        .def("setMaterial", &PyDbEntity::setMaterial2)
        .def("setMaterial", &PyDbEntity::setMaterial3)
        .def("setMaterial", &PyDbEntity::setMaterial4, DS.ARGS({ "val: str|ObjectId",  "dosubents : bool=True" }))
        .def("linetypeScale", &PyDbEntity::linetypeScale, DS.ARGS())
        .def("setLinetypeScale", &PyDbEntity::setLinetypeScale1)
        .def("setLinetypeScale", &PyDbEntity::setLinetypeScale2, DS.ARGS({ "val: float",  "dosubents : bool=True" }))
        .def("visibility", &PyDbEntity::visibility, DS.ARGS())
        .def("setVisibility", &PyDbEntity::setVisibility1)
        .def("setVisibility", &PyDbEntity::setVisibility2, DS.ARGS({ "val: Visibility",  "dosubents : bool=True" }))
        .def("lineWeight", &PyDbEntity::lineWeight, DS.ARGS())
        .def("setLineWeight", &PyDbEntity::setLineWeight1)
        .def("setLineWeight", &PyDbEntity::setLineWeight2, DS.ARGS({ "val: LineWeight",  "dosubents : bool=True" }))
        .def("collisionType", &PyDbEntity::collisionType, DS.ARGS())
        .def("castShadows", &PyDbEntity::castShadows, DS.ARGS())
        .def("setCastShadows", &PyDbEntity::setCastShadows, DS.ARGS({ "val: bool" }))
        .def("receiveShadows", &PyDbEntity::receiveShadows, DS.ARGS())
        .def("setReceiveShadows", &PyDbEntity::setReceiveShadows, DS.ARGS({ "val: bool" }))
        .def("setPropertiesFrom", &PyDbEntity::setPropertiesFrom1)
        .def("setPropertiesFrom", &PyDbEntity::setPropertiesFrom2, DS.ARGS({ "entity: PyDb.Entity",  "dosubents : bool=True" }))
        .def("isPlanar", &PyDbEntity::isPlanar, DS.ARGS())
        .def("getPlane", &PyDbEntity::getPlane, DS.ARGS())
        .def("getEcs", &PyDbEntity::getEcs, DS.ARGS())
        .def("list", &PyDbEntity::list, DS.ARGS())
        .def("intersectWith", &PyDbEntity::intersectWith1)
        .def("intersectWith", &PyDbEntity::intersectWith2)
        .def("intersectWith", &PyDbEntity::intersectWith3)
        .def("intersectWith", &PyDbEntity::intersectWith4, DS.ARGS({ "entity: PyDb.Entity",  "intType : PyDb.Intersect " }, intersectWithComments))
        .def("transformBy", &PyDbEntity::transformBy, DS.ARGS({ "matrix3d: PyGe.Matrix3d" }))
        .def("recordGraphicsModified", &PyDbEntity::recordGraphicsModified, DS.ARGS())
        .def("setDatabaseDefaults", &PyDbEntity::setDatabaseDefaults1)
        .def("setDatabaseDefaults", &PyDbEntity::setDatabaseDefaults2, DS.ARGS({ "db: Database = current" }))
        .def("getCompoundObjectTransform", &PyDbEntity::getCompoundObjectTransform, DS.ARGS())
        .def("getGeomExtents", &PyDbEntity::getGeomExtents, DS.ARGS())
        .def("getGeomExtents2d", &PyDbEntity::getGeomExtents2d, DS.ARGS())
        .def("draw", &PyDbEntity::draw, DS.ARGS())
        .def("explode", &PyDbEntity::explode, DS.ARGS())
        .def("getTransformedCopy", &PyDbEntity::getTransformedCopy, DS.ARGS({ "matrix3d: PyGe.Matrix3d" }))
        .def("addReactor", &PyDbEntity::addReactor, DS.ARGS({ "reactor: EntityReactor" }))
        .def("removeReactor", &PyDbEntity::removeReactor, DS.ARGS({ "reactor: EntityReactor" }))
        .def("getStretchPoints", &PyDbEntity::getStretchPoints, DS.ARGS())
        .def("getGripPoints", &PyDbEntity::getGripPoints1)
        .def("addSubentPaths", &PyDbEntity::addSubentPaths)
        .def("getSubentPathsAtGsMarker", &PyDbEntity::getSubentPathsAtGsMarker1)
        .def("getSubentPathsAtGsMarker", &PyDbEntity::getSubentPathsAtGsMarker2)
        .def("highlight", &PyDbEntity::highlight1)
        .def("highlight", &PyDbEntity::highlight2, DS.ARGS({ "path: PyDb.FullSubentPath = None","highlightAll : bool = False" }))
        .def("className", &PyDbEntity::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbEntity::desc, DS.SARGS()).staticmethod("desc")
        .def("cloneFrom", &PyDbEntity::cloneFrom, DS.SARGS({ "otherObject: RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbEntity::cast, DS.SARGS({ "otherObject: RxObject" })).staticmethod("cast")
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

void PyDbEntity::setLayer1(const std::string& newVal)
{
    return this->setLayer3(newVal, true, false);
}

void PyDbEntity::setLayer2(const std::string& newVal, bool doSubents)
{
    return this->setLayer3(newVal, doSubents, false);
}

void PyDbEntity::setLayer3(const std::string& newVal, bool doSubents, bool allowHiddenLayer)
{
    return PyThrowBadEs(impObj()->setLayer(utf8_to_wstr(newVal).c_str(), doSubents, allowHiddenLayer));
}

void PyDbEntity::setLayer4(const PyDbObjectId& newVal)
{
    return this->setLayer6(newVal, true, false);
}

void PyDbEntity::setLayer5(const PyDbObjectId& newVal, bool doSubents)
{
    return this->setLayer6(newVal, true, false);
}

void PyDbEntity::setLayer6(const PyDbObjectId& newVal, bool doSubents, bool allowHiddenLayer)
{
    return PyThrowBadEs(impObj()->setLayer(newVal.m_id, doSubents, allowHiddenLayer));
}

std::string PyDbEntity::plotStyleName() const
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
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

void PyDbEntity::setColor1(const AcCmColor& color)
{
    return PyThrowBadEs(impObj()->setColor(color));
}

void PyDbEntity::setColor2(const AcCmColor& color, bool doSubents)
{
    return PyThrowBadEs(impObj()->setColor(color, doSubents));
}

void PyDbEntity::setColor3(const AcCmColor& color, bool doSubents, PyDbDatabase& db)
{
    return PyThrowBadEs(impObj()->setColor(color, doSubents, db.impObj()));
}

Adesk::UInt16 PyDbEntity::colorIndex() const
{
    return impObj()->colorIndex();
}

void PyDbEntity::setColorIndex1(Adesk::UInt16 color)
{
    return PyThrowBadEs(impObj()->setColorIndex(color));
}

void PyDbEntity::setColorIndex2(Adesk::UInt16 color, Adesk::Boolean doSubents)
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

void PyDbEntity::setTransparency(const AcCmTransparency& trans, Adesk::Boolean doSubents /*= true*/)
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

void PyDbEntity::setPlotStyleName1(const std::string& str, Adesk::Boolean doSubents)
{
    return PyThrowBadEs(impObj()->setPlotStyleName(utf8_to_wstr(str).c_str(), doSubents));
}

void PyDbEntity::setPlotStyleName2(AcDb::PlotStyleNameType tp, Adesk::Boolean doSubents)
{
    return PyThrowBadEs(impObj()->setPlotStyleName(tp, AcDbObjectId::kNull, doSubents));
}

void PyDbEntity::setPlotStyleName3(AcDb::PlotStyleNameType tp, const PyDbObjectId& newId, Adesk::Boolean doSubents)
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

void PyDbEntity::setLinetype1(const std::string& newVal)
{
    return PyThrowBadEs(impObj()->setLinetype(utf8_to_wstr(newVal).c_str()));
}

void PyDbEntity::setLinetype2(const std::string& newVal, Adesk::Boolean doSubents)
{
    return PyThrowBadEs(impObj()->setLinetype(utf8_to_wstr(newVal).c_str(), doSubents));
}

void PyDbEntity::setLinetype3(const PyDbObjectId& newVal)
{
    return PyThrowBadEs(impObj()->setLinetype(newVal.m_id));
}

void PyDbEntity::setLinetype4(const PyDbObjectId& newVal, Adesk::Boolean doSubents)
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

void PyDbEntity::setMaterial1(const std::string& newVal)
{
    return PyThrowBadEs(impObj()->setMaterial(utf8_to_wstr(newVal).c_str()));
}

void PyDbEntity::setMaterial2(const std::string& newVal, Adesk::Boolean doSubents)
{
    return PyThrowBadEs(impObj()->setMaterial(utf8_to_wstr(newVal).c_str(), doSubents));
}

void PyDbEntity::setMaterial3(const PyDbObjectId& newVal)
{
    return PyThrowBadEs(impObj()->setLinetype(newVal.m_id));
}

void PyDbEntity::setMaterial4(const PyDbObjectId& newVal, Adesk::Boolean doSubents)
{
    return PyThrowBadEs(impObj()->setLinetype(newVal.m_id, doSubents));
}

double PyDbEntity::linetypeScale() const
{
    return impObj()->linetypeScale();
}

void PyDbEntity::setLinetypeScale1(double newval)
{
    return PyThrowBadEs(impObj()->setLinetypeScale(newval));
}

void PyDbEntity::setLinetypeScale2(double newval, Adesk::Boolean doSubents)
{
    return PyThrowBadEs(impObj()->setLinetypeScale(newval, doSubents));
}

AcDb::Visibility PyDbEntity::visibility() const
{
    return impObj()->visibility();
}

void PyDbEntity::setVisibility1(AcDb::Visibility newVal)
{
    return PyThrowBadEs(impObj()->setVisibility(newVal));
}

void PyDbEntity::setVisibility2(AcDb::Visibility newVal, Adesk::Boolean doSubents /*= true*/)
{
    return PyThrowBadEs(impObj()->setVisibility(newVal, doSubents));
}

AcDb::LineWeight PyDbEntity::lineWeight() const
{
    return impObj()->lineWeight();
}

void PyDbEntity::setLineWeight1(AcDb::LineWeight newVal)
{
    return PyThrowBadEs(impObj()->setLineWeight(newVal));
}

void PyDbEntity::setLineWeight2(AcDb::LineWeight newVal, Adesk::Boolean doSubents)
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

void PyDbEntity::setCastShadows(bool newVal)
{
    impObj()->setCastShadows(newVal);
}

bool PyDbEntity::receiveShadows() const
{
    return impObj()->receiveShadows();
}

void PyDbEntity::setReceiveShadows(bool newVal)
{
    impObj()->setReceiveShadows(newVal);
}

void PyDbEntity::setPropertiesFrom1(const PyDbEntity& pEntity)
{
    return PyThrowBadEs(impObj()->setPropertiesFrom(pEntity.impObj()));
}

void PyDbEntity::setPropertiesFrom2(const PyDbEntity& pEntity, Adesk::Boolean doSubents)
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
        throw PyAcadErrorStatus(Acad::eNotApplicable);
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

void PyDbEntity::transformBy(const AcGeMatrix3d& xform)
{
    return PyThrowBadEs(impObj()->transformBy(xform));
}

void PyDbEntity::recordGraphicsModified()
{
    impObj()->recordGraphicsModified();
}

void PyDbEntity::draw()
{
    return PyThrowBadEs(impObj()->draw());
}

void PyDbEntity::setDatabaseDefaults1()
{
    impObj()->setDatabaseDefaults();
}

void PyDbEntity::setDatabaseDefaults2(const PyDbDatabase& db)
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

void PyDbEntity::getGripPoints1(boost::python::list& gripPoints, boost::python::list& osnapModes, boost::python::list& geomIds) const
{
    AcGePoint3dArray _gripPoints;
    AcDbIntArray _osnapModes;
    AcDbIntArray _geomIds;
    PyThrowBadEs(impObj()->getGripPoints(_gripPoints, _osnapModes, _geomIds));
    PyAutoLockGIL lock;
    for (auto& item : _gripPoints)
        gripPoints.append(item);
    for (auto& item : _osnapModes)
        osnapModes.append(item);
    for (auto& item : _geomIds)
        geomIds.append(item);
}

void PyDbEntity::addSubentPaths(const boost::python::list& newPaths)
{
    PyThrowBadEs(impObj()->addSubentPaths(PyListToPyDbFullSubentPathArray(newPaths)));
}

boost::python::list PyDbEntity::getSubentPathsAtGsMarker1(AcDb::SubentType type, Adesk::GsMarker gsMark, const AcGePoint3d& pickPoint, const AcGeMatrix3d& viewXform)
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

boost::python::list PyDbEntity::getSubentPathsAtGsMarker2(AcDb::SubentType type, Adesk::GsMarker gsMark, const AcGePoint3d& pickPoint, const AcGeMatrix3d& viewXform, int numInserts, PyDbObjectId& entAndInsertStack)
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
    PyThrowBadEs(impObj()->highlight(subId.m_pyImp, highlightAll));
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
    if (!src.impObj()->isKindOf(AcDbEntity::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbEntity(static_cast<AcDbEntity*>(src.impObj()->clone()), true);
}

PyDbEntity PyDbEntity::cast(const PyRxObject& src)
{
    PyDbEntity dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
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
    class_<PyDbBlockBegin, bases<PyDbEntity>>("BlockBegin", boost::python::no_init)
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("className", &PyDbBlockBegin::className).staticmethod("className")
        .def("desc", &PyDbBlockBegin::desc).staticmethod("desc")
        .def("cloneFrom", &PyDbBlockBegin::cloneFrom).staticmethod("cloneFrom")
        .def("cast", &PyDbBlockBegin::cast).staticmethod("cast")
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
    if (!src.impObj()->isKindOf(AcDbBlockBegin::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbBlockBegin(static_cast<AcDbBlockBegin*>(src.impObj()->clone()), true);
}

PyDbBlockBegin PyDbBlockBegin::cast(const PyRxObject& src)
{
    PyDbBlockBegin dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
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
    class_<PyDbBlockEnd, bases<PyDbEntity>>("BlockEnd", boost::python::no_init)
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("className", &PyDbBlockEnd::className).staticmethod("className")
        .def("desc", &PyDbBlockEnd::desc).staticmethod("desc")
        .def("cloneFrom", &PyDbBlockEnd::cloneFrom).staticmethod("cloneFrom")
        .def("cast", &PyDbBlockEnd::cast).staticmethod("cast")
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
    if (!src.impObj()->isKindOf(AcDbBlockEnd::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbBlockEnd(static_cast<AcDbBlockEnd*>(src.impObj()->clone()), true);
}

PyDbBlockEnd PyDbBlockEnd::cast(const PyRxObject& src)
{
    PyDbBlockEnd dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
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
    class_<PyDbSequenceEnd, bases<PyDbEntity>>("SequenceEnd", boost::python::no_init)
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("className", &PyDbSequenceEnd::className).staticmethod("className")
        .def("desc", &PyDbSequenceEnd::desc).staticmethod("desc")
        .def("cloneFrom", &PyDbSequenceEnd::cloneFrom).staticmethod("cloneFrom")
        .def("cast", &PyDbSequenceEnd::cast).staticmethod("cast")
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
    if (!src.impObj()->isKindOf(AcDbSequenceEnd::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbSequenceEnd(static_cast<AcDbSequenceEnd*>(src.impObj()->clone()), true);
}

PyDbSequenceEnd PyDbSequenceEnd::cast(const PyRxObject& src)
{
    PyDbSequenceEnd dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
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
    PyDocString DS("SubentId");
    class_<PyDbSubentId>("SubentId")
        .def(init<>())
        .def(init<AcDb::SubentType, Adesk::GsMarker>())
        .def(init<PyRxClass&, Adesk::GsMarker>())
        .def("type", &PyDbSubentId::type, DS.ARGS())
        .def("setType", &PyDbSubentId::setType)
        .def("typeClass", &PyDbSubentId::typeClass, DS.ARGS())
        .def("setTypeClass", &PyDbSubentId::setTypeClass)
        .def("index", &PyDbSubentId::index, DS.ARGS())
        .def("setIndex", &PyDbSubentId::setIndex)
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

void PyDbSubentId::setType(AcDb::SubentType et)
{
    return impObj()->setType(et);
}

PyRxClass PyDbSubentId::typeClass() const
{
    return PyRxClass(impObj()->typeClass(), false);
}

void PyDbSubentId::setTypeClass(PyRxClass& pClass)
{
    return impObj()->setTypeClass(pClass.impObj());
}

Adesk::GsMarker PyDbSubentId::index() const
{
    return impObj()->index();
}

void PyDbSubentId::setIndex(Adesk::GsMarker ind)
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
    PyDocString DS("FullSubentPath");
    class_<PyDbFullSubentPath>("FullSubentPath")
        .def(init<>())
        .def(init<AcDb::SubentType, Adesk::GsMarker>())
        .def(init<const PyDbObjectId&, AcDb::SubentType, Adesk::GsMarker>())
        .def(init<const PyDbObjectId&, const PyDbSubentId&>())
        .def(init<const boost::python::list&, const PyDbSubentId&>())
        .def("setObjectIds", &PyDbFullSubentPath::setObjectIds)
        .def("objectIds", &PyDbFullSubentPath::objectIds, DS.ARGS())
        .def("setSubentId", &PyDbFullSubentPath::setSubentId)
        .def("setSubentId", &PyDbFullSubentPath::subentId, DS.ARGS())
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
    : m_pyImp(src)
{
}

PyDbFullSubentPath::PyDbFullSubentPath(AcDb::SubentType type, Adesk::GsMarker index)
    : m_pyImp(type, index)
{
}

PyDbFullSubentPath::PyDbFullSubentPath(const PyDbObjectId& entId, AcDb::SubentType type, Adesk::GsMarker index)
    : m_pyImp(entId.m_id, type, index)
{
}

PyDbFullSubentPath::PyDbFullSubentPath(const PyDbObjectId& entId, const PyDbSubentId& subId)
    : m_pyImp(entId.m_id, *subId.impObj())
{
}

PyDbFullSubentPath::PyDbFullSubentPath(const boost::python::list& objectIds, const PyDbSubentId& subId)
    : m_pyImp(PyListToObjectIdArray(objectIds), *subId.impObj())
{
}

bool PyDbFullSubentPath::operator==(const PyDbFullSubentPath& id) const
{
    return m_pyImp == m_pyImp;
}

bool PyDbFullSubentPath::operator!=(const PyDbFullSubentPath& id) const
{
    return m_pyImp != m_pyImp;
}

void PyDbFullSubentPath::setObjectIds(const boost::python::list& objectIds)
{
#if defined (_ZRXTARGET240) || defined (_BRXTARGET240)
    throw PyNotimplementedByHost();
#else
    m_pyImp.setObjectIds(PyListToObjectIdArray(objectIds));
#endif
}

boost::python::list PyDbFullSubentPath::objectIds() const
{
    return ObjectIdArrayToPyList(m_pyImp.objectIds());
}

void PyDbFullSubentPath::setSubentId(const PyDbSubentId& subentId)
{
#if defined (_ZRXTARGET240) || defined (_BRXTARGET240)
    throw PyNotimplementedByHost();
#else
    m_pyImp.setSubentId(*subentId.impObj());
#endif
}

PyDbSubentId PyDbFullSubentPath::subentId() const
{
    return PyDbSubentId(m_pyImp.subentId());
}

PyDbFullSubentPath PyDbFullSubentPath::kNull()
{
    return PyDbFullSubentPath();
}
