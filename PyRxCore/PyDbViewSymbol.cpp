#include "stdafx.h"
#include "PyDbViewSymbol.h"
#include "PyDbObjectId.h"

using namespace boost::python;

//-------------------------------------------------------------------------------------------------------------
// PyDbViewSymbol wrapper
void makePyDbViewSymbolWrapper()
{
#if defined(_ARXTARGET) || defined(_BRXTARGET) && (_BRXTARGET > 240)
    constexpr const std::string_view ctords = "Overloads:\n"
        "- id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode, erased: bool\n";

    PyDocString DS("ViewSymbol");
    class_<PyDbViewSymbol, bases<PyDbEntity>>("ViewSymbol", no_init)
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.CTOR(ctords, 0)))

        .def("symbolStyleId", &PyDbViewSymbol::symbolStyleId, DS.ARGS())
        .def("setSymbolStyleId", &PyDbViewSymbol::setSymbolStyleId, DS.ARGS({ "styleId: PyDb.ObjectId" }))
        .def("scale", &PyDbViewSymbol::scale, DS.ARGS())
        .def("setScale", &PyDbViewSymbol::setScale, DS.ARGS({ "val: float" }))
        .def("getIdentifier", &PyDbViewSymbol::getIdentifier, DS.ARGS())
        .def("setIdentifier", &PyDbViewSymbol::setIdentifier, DS.ARGS({ "sName: str" }))
        .def("owningViewRep", &PyDbViewSymbol::owningViewRep, DS.ARGS())
        .def("setOwningViewRep", &PyDbViewSymbol::setOwningViewRep, DS.ARGS({ "owner: PyDb.ObjectId" }))
        .def("exportSymbolGeometry", &PyDbViewSymbol::exportSymbolGeometry, DS.ARGS({ "viewRepId: PyDb.ObjectId" }))
        .def("setSymbolGeometry", &PyDbViewSymbol::setSymbolGeometry, DS.ARGS({ "entIds: list[PyDb.ObjectId]" }))
        .def("setSymbolGeometryEntities", &PyDbViewSymbol::setSymbolGeometryEntities, DS.ARGS({ "entities: list[PyDb.DbObject]" }))
        .def("updateDefinition", &PyDbViewSymbol::updateDefinition, DS.ARGS())

        .def("className", &PyDbViewSymbol::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbViewSymbol::desc, DS.SARGS()).staticmethod("desc")
        .def("cloneFrom", &PyDbViewSymbol::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbViewSymbol::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
#endif
}

//-------------------------------------------------------------------------------------------------------------
// PyDbViewSymbol
#if defined(_ARXTARGET) || defined(_BRXTARGET) && (_BRXTARGET > 240)
PyDbViewSymbol::PyDbViewSymbol(AcDbViewSymbol* ptr, bool autoDelete)
    : PyDbEntity(ptr, autoDelete)
{
}

PyDbViewSymbol::PyDbViewSymbol(const PyDbObjectId& id)
    : PyDbEntity(openAcDbObject<AcDbViewSymbol>(id, AcDb::OpenMode::kForRead), false)
{
}

PyDbViewSymbol::PyDbViewSymbol(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbEntity(openAcDbObject<AcDbViewSymbol>(id, mode), false)
{
}

PyDbViewSymbol::PyDbViewSymbol(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbEntity(openAcDbObject<AcDbViewSymbol>(id, mode, erased), false)
{
}

PyDbObjectId PyDbViewSymbol::symbolStyleId() const
{
    return PyDbObjectId{ impObj()->symbolStyleId() };
}

void PyDbViewSymbol::setSymbolStyleId(const PyDbObjectId& styleId) const
{
    impObj()->setSymbolStyleId(styleId.m_id);
}

double PyDbViewSymbol::scale() const
{
    return impObj()->scale();
}

void PyDbViewSymbol::setScale(double val) const
{
    impObj()->setScale(val);
}

std::string PyDbViewSymbol::getIdentifier() const
{
    AcString sName;
    PyThrowBadEs(impObj()->getIdentifier(sName));
    return wstr_to_utf8(sName);
}

void PyDbViewSymbol::setIdentifier(const std::string& sName) const
{
    PyThrowBadEs(impObj()->setIdentifier(utf8_to_wstr(sName).c_str()));
}

PyDbObjectId PyDbViewSymbol::owningViewRep() const
{
#if defined(_BRXTARGET)
    throw PyNotimplementedByHost();
#else
    return PyDbObjectId{ impObj()->owningViewRep() };
#endif
}

void PyDbViewSymbol::setOwningViewRep(const PyDbObjectId& owner) const
{
    impObj()->setSymbolStyleId(owner.m_id);
}

boost::python::list PyDbViewSymbol::exportSymbolGeometry(const PyDbObjectId& viewRepId) const
{
#if defined(_BRXTARGET)
    throw PyNotimplementedByHost();
#else
    AcArray<AcGeCurve3d*> geomArr;
    PyThrowBadEs(impObj()->exportSymbolGeometry(geomArr, viewRepId.m_id));
    PyAutoLockGIL lock;
    boost::python::list pylist;
    for (auto item : geomArr)
        pylist.append(PyGeCurve3d(item));
    return pylist;
#endif
}

void PyDbViewSymbol::setSymbolGeometry(const boost::python::list& entIds) const
{
#if defined(_BRXTARGET)
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(impObj()->setSymbolGeometry(PyListToObjectIdArray(entIds)));
#endif
}

void PyDbViewSymbol::setSymbolGeometryEntities(const boost::python::list& pyentities) const
{
#if defined(_BRXTARGET)
    throw PyNotimplementedByHost();
#else
    using Iter = boost::python::stl_input_iterator<PyDbObject>;
    AcArray<AcDbObject*> _entities;
    int length = boost::python::len(pyentities);
    _entities.setPhysicalLength(length);
    for (Iter it(pyentities), end; it != end; ++it)
        _entities.append(it->impObj());
    PyThrowBadEs(impObj()->setSymbolGeometry(_entities));
#endif
}

void PyDbViewSymbol::updateDefinition() const
{
#if defined(_BRXTARGET)
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(impObj()->updateDefinition());
#endif
}

PyRxClass PyDbViewSymbol::desc()
{
    return PyRxClass(AcDbViewSymbol::desc(), false);
}

std::string PyDbViewSymbol::className()
{
    return "AcDbViewSymbol";
}

PyDbViewSymbol PyDbViewSymbol::cloneFrom(const PyRxObject& src)
{
    return PyDbObjectCloneFrom<PyDbViewSymbol, AcDbViewSymbol>(src);
}

PyDbViewSymbol PyDbViewSymbol::cast(const PyRxObject& src)
{
    return PyDbViewSymbol(AcDbViewSymbol::cast(PyRxObject(src).impObj()), false);
}

AcDbViewSymbol* PyDbViewSymbol::impObj(const std::source_location& src) const
{
    auto res = static_cast<AcDbViewSymbol*>(PyDbObject::impObj(src));
    if (!res)
        throw PyNullObject(src);
    return res;
}
#endif

//-------------------------------------------------------------------------------------------------------------
// PyDbDetailSymbol wrapper
void makePyDbDetailSymbolWrapper()
{
#if defined(_ARXTARGET) || defined(_BRXTARGET) && (_BRXTARGET > 240)
    constexpr const std::string_view ctords = "Overloads:\n"
        "- None: Any\n"
        "- id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode, erased: bool\n";

    PyDocString DS("DetailSymbol");
    class_<PyDbDetailSymbol, bases<PyDbViewSymbol>>("DetailSymbol")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.CTOR(ctords, 0)))

        .def("boundaryType", &PyDbDetailSymbol::boundaryType, DS.ARGS())
        .def("modelEdgeType", &PyDbDetailSymbol::modelEdgeType, DS.ARGS())
        .def("isOverriddenProperty", &PyDbDetailSymbol::isOverriddenProperty, DS.ARGS({ "property: PyDb.DetailSymbolOverriddenProperty" }))
        .def("displayIdentifier", &PyDbDetailSymbol::displayIdentifier, DS.ARGS())
        .def("origin", &PyDbDetailSymbol::origin, DS.ARGS())
        .def("direction", &PyDbDetailSymbol::direction, DS.ARGS())
        .def("boundarySize", &PyDbDetailSymbol::boundarySize, DS.ARGS())
        .def("modelEdgeOrigin", &PyDbDetailSymbol::modelEdgeOrigin, DS.ARGS())
        .def("owningViewScale", &PyDbDetailSymbol::owningViewScale, DS.ARGS())
        .def("detailViewScale", &PyDbDetailSymbol::detailViewScale, DS.ARGS())
        .def("modelEdgeDirection", &PyDbDetailSymbol::modelEdgeDirection, DS.ARGS())
        .def("identifierPosition", &PyDbDetailSymbol::identifierPosition, DS.ARGS())
        .def("setBoundaryType", &PyDbDetailSymbol::setBoundaryType, DS.ARGS({ "bndType: PyDb.DetailSymbolBoundaryType" }))
        .def("setModelEdgeType", &PyDbDetailSymbol::setModelEdgeType, DS.ARGS({ "modelEdgeType: PyDb.DetailViewStyleModelEdge" }))
        .def("setPickPoints", &PyDbDetailSymbol::setPickPoints, DS.ARGS({ "pickPoints: list[PyGe.Point3d]" }))
        .def("setModelEdgeOrigin", &PyDbDetailSymbol::setModelEdgeOrigin, DS.ARGS({ "pt: PyGe.Point3d" }))
        .def("setOwningViewScale", &PyDbDetailSymbol::setOwningViewScale, DS.ARGS({ "viewScale: float" }))
        .def("setDetailViewScale", &PyDbDetailSymbol::setDetailViewScale, DS.ARGS({ "viewScale: float" }))
        .def("setModelEdgeDirection", &PyDbDetailSymbol::setModelEdgeDirection, DS.ARGS({ "dir: PyGe.Vector3d" }))
        .def("setIdentifierPosition", &PyDbDetailSymbol::setIdentifierPosition, DS.ARGS({ "pt: PyGe.Point3d" }))
        .def("initializeIdentifierPositionAt", &PyDbDetailSymbol::initializeIdentifierPositionAt, DS.ARGS({ "pt: PyGe.Point3d" }))
        .def("resetIdentifierPosition", &PyDbDetailSymbol::resetIdentifierPosition, DS.ARGS())
        .def("setDisplayIdentifier", &PyDbDetailSymbol::setDisplayIdentifier, DS.ARGS({ "displayIdentifier: bool" }))
        .def("setOrigin", &PyDbDetailSymbol::setOrigin, DS.ARGS({ "pt: PyGe.Point3d" }))
        .def("setBoundarySize", &PyDbDetailSymbol::setBoundarySize, DS.ARGS({ "size: PyGe.Vector2d" }))
        .def("modelEdgeBorderExtents", &PyDbDetailSymbol::modelEdgeBorderExtents, DS.ARGS())

        .def("className", &PyDbDetailSymbol::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbDetailSymbol::desc, DS.SARGS()).staticmethod("desc")
        .def("cloneFrom", &PyDbDetailSymbol::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbDetailSymbol::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
#endif
}

//-------------------------------------------------------------------------------------------------------------
// PyDbDetailSymbol
#if defined(_ARXTARGET) || defined(_BRXTARGET) && (_BRXTARGET > 240)
PyDbDetailSymbol::PyDbDetailSymbol()
    : PyDbViewSymbol(new AcDbDetailSymbol(), true)
{
}

PyDbDetailSymbol::PyDbDetailSymbol(AcDbDetailSymbol* ptr, bool autoDelete)
    : PyDbViewSymbol(ptr, autoDelete)
{
}

PyDbDetailSymbol::PyDbDetailSymbol(const PyDbObjectId& id)
    : PyDbViewSymbol(openAcDbObject<AcDbDetailSymbol>(id, AcDb::OpenMode::kForRead), false)
{
}

PyDbDetailSymbol::PyDbDetailSymbol(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbViewSymbol(openAcDbObject<AcDbDetailSymbol>(id, mode), false)
{
}

PyDbDetailSymbol::PyDbDetailSymbol(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbViewSymbol(openAcDbObject<AcDbDetailSymbol>(id, mode, erased), false)
{
}

AcDbDetailSymbol::BoundaryType PyDbDetailSymbol::boundaryType() const
{
    return impObj()->boundaryType();
}

AcDbDetailViewStyle::ModelEdge PyDbDetailSymbol::modelEdgeType() const
{
    return impObj()->modelEdgeType();
}

bool PyDbDetailSymbol::isOverriddenProperty(AcDbDetailSymbol::OverriddenProperty property) const
{
    return impObj()->isOverriddenProperty(property);
}

bool PyDbDetailSymbol::displayIdentifier() const
{
    return impObj()->displayIdentifier();
}

AcGePoint3d PyDbDetailSymbol::origin() const
{
    return impObj()->origin();
}

AcGeVector3d PyDbDetailSymbol::direction() const
{
    return impObj()->direction();
}

AcGeVector2d PyDbDetailSymbol::boundarySize() const
{
    return impObj()->boundarySize();
}

AcGePoint3d PyDbDetailSymbol::modelEdgeOrigin() const
{
    return impObj()->modelEdgeOrigin();
}

double PyDbDetailSymbol::owningViewScale() const
{
    return impObj()->owningViewScale();
}

double PyDbDetailSymbol::detailViewScale() const
{
    return impObj()->detailViewScale();
}

AcGeVector3d PyDbDetailSymbol::modelEdgeDirection() const
{
    return impObj()->modelEdgeDirection();
}

AcGePoint3d PyDbDetailSymbol::identifierPosition() const
{
    return impObj()->identifierPosition();
}

void PyDbDetailSymbol::setBoundaryType(AcDbDetailSymbol::BoundaryType bndType) const
{
#if defined(_BRXTARGET)
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(impObj()->setBoundaryType(bndType));
#endif
}

void PyDbDetailSymbol::setModelEdgeType(AcDbDetailViewStyle::ModelEdge modelEdgeType) const
{
#if defined(_BRXTARGET)
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(impObj()->setModelEdgeType(modelEdgeType));
#endif
}

void PyDbDetailSymbol::setPickPoints(const boost::python::list& pickPoints) const
{
#if defined(_BRXTARGET)
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(impObj()->setPickPoints(PyListToPoint3dArray(pickPoints)));
#endif
}

void PyDbDetailSymbol::setModelEdgeOrigin(const AcGePoint3d& pt) const
{
#if defined(_BRXTARGET)
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(impObj()->setModelEdgeOrigin(pt));
#endif
}

void PyDbDetailSymbol::setOwningViewScale(double viewScale) const
{
#if defined(_BRXTARGET)
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(impObj()->setOwningViewScale(viewScale));
#endif
}

void PyDbDetailSymbol::setDetailViewScale(double viewScale) const
{
#if defined(_BRXTARGET)
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(impObj()->setOwningViewScale(viewScale));
#endif
}

void PyDbDetailSymbol::setModelEdgeDirection(const AcGeVector3d& dir) const
{
#if defined(_BRXTARGET)
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(impObj()->setModelEdgeDirection(dir));
#endif
}

void PyDbDetailSymbol::setIdentifierPosition(const AcGePoint3d& pt) const
{
#if defined(_BRXTARGET)
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(impObj()->setIdentifierPosition(pt));
#endif
}

void PyDbDetailSymbol::initializeIdentifierPositionAt(const AcGePoint3d& pt) const
{
#if defined(_BRXTARGET)
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(impObj()->initializeIdentifierPositionAt(pt));
#endif
}

void PyDbDetailSymbol::resetIdentifierPosition() const
{
#if defined(_BRXTARGET)
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(impObj()->resetIdentifierPosition());
#endif
}

void PyDbDetailSymbol::setDisplayIdentifier(const bool displayIdentifier) const
{
#if defined(_BRXTARGET)
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(impObj()->setDisplayIdentifier(displayIdentifier));
#endif
}

void PyDbDetailSymbol::setOrigin(const AcGePoint3d& pt) const
{
#if defined(_BRXTARGET)
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(impObj()->setOrigin(pt));
#endif
}

void PyDbDetailSymbol::setBoundarySize(const AcGeVector2d& size) const
{
#if defined(_BRXTARGET)
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(impObj()->setBoundarySize(size));
#endif
}

AcDbExtents PyDbDetailSymbol::modelEdgeBorderExtents() const
{
#if defined(_BRXTARGET)
    throw PyNotimplementedByHost();
#else
    AcDbExtents ex;
    PyThrowBadEs(impObj()->modelEdgeBorderExtents(ex));
    return ex;
#endif
}

PyRxClass PyDbDetailSymbol::desc()
{
    return PyRxClass(AcDbDetailSymbol::desc(), false);
}

std::string PyDbDetailSymbol::className()
{
    return "AcDbDetailSymbol";
}

PyDbDetailSymbol PyDbDetailSymbol::cloneFrom(const PyRxObject& src)
{
    return PyDbObjectCloneFrom<PyDbDetailSymbol, AcDbDetailSymbol>(src);
}

PyDbDetailSymbol PyDbDetailSymbol::cast(const PyRxObject& src)
{
    return PyDbDetailSymbol(AcDbDetailSymbol::cast(PyRxObject(src).impObj()), false);
}

AcDbDetailSymbol* PyDbDetailSymbol::impObj(const std::source_location& src) const
{
    auto res = static_cast<AcDbDetailSymbol*>(PyDbObject::impObj(src));
    if (!res)
        throw PyNullObject(src);
    return res;
}
#endif

//-------------------------------------------------------------------------------------------------------------
// PyDbSectionSymbol wrapper
void makePyDbSectionSymbolWrapper()
{
#if defined(_ARXTARGET) || defined(_BRXTARGET) && (_BRXTARGET > 240)
    constexpr const std::string_view ctords = "Overloads:\n"
        "- None: Any\n"
        "- id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode, erased: bool\n";

    PyDocString DS("SectionSymbol");
    class_<PyDbSectionSymbol, bases<PyDbViewSymbol>>("SectionSymbol")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.CTOR(ctords, 0)))

        .def("sectionPointsCount", &PyDbSectionSymbol::sectionPointsCount, DS.ARGS())
        .def("getSectionPoints", &PyDbSectionSymbol::getSectionPoints, DS.ARGS())
        .def("getSectionPointAt", &PyDbSectionSymbol::getSectionPointAt, DS.ARGS({ "idx: int" }))
        .def("getBulgeAt", &PyDbSectionSymbol::getBulgeAt, DS.ARGS({ "idx: int" }))
        .def("getLabelNameAt", &PyDbSectionSymbol::getLabelNameAt, DS.ARGS({ "idx: int" }))
        .def("getLabelOffsetAt", &PyDbSectionSymbol::getLabelOffsetAt, DS.ARGS({ "idx: int" }))
        .def("getLabelOffsets", &PyDbSectionSymbol::getLabelOffsets, DS.ARGS())
        .def("isViewDirectionLeft", &PyDbSectionSymbol::isViewDirectionLeft, DS.ARGS())
        .def("isHalfSection", &PyDbSectionSymbol::isHalfSection, DS.ARGS())
        .def("setSectionPoints", &PyDbSectionSymbol::setSectionPoints1, DS.ARGS({ "pts: list[PyGe.Point3d]" }))
        .def("setSectionPoints", &PyDbSectionSymbol::setSectionPoints2, DS.ARGS({ "pts: list[PyGe.Point3d]", "bulges: list[float]" }))
        .def("addSectionPoint", &PyDbSectionSymbol::addSectionPoint, DS.ARGS({ "pt: PyGe.Point3d", "bulge: float" }))
        .def("removeSectionPointAt", &PyDbSectionSymbol::removeSectionPointAt, DS.ARGS({ "idx: int" }))
        .def("setSectionPointAt", &PyDbSectionSymbol::setSectionPointAt, DS.ARGS({ "idx: int", "pt: PyGe.Point3d", "bulge: float" }))
        .def("clearSectionPoints", &PyDbSectionSymbol::clearSectionPoints, DS.ARGS())
        .def("setLabelNameAt", &PyDbSectionSymbol::setLabelNameAt, DS.ARGS({ "idx: int", "pName: str" }))
        .def("setLabelNames", &PyDbSectionSymbol::setLabelNames, DS.ARGS({ "names: list[str]" }))
        .def("setLabelOffsetAt", &PyDbSectionSymbol::setLabelOffsetAt, DS.ARGS({ "idx: int", "offset: PyGe.Vector3d" }))
        .def("setLabelOffsets", &PyDbSectionSymbol::setLabelOffsets, DS.ARGS({ "offsets: list[PyGe.Vector3d]" }))
        .def("resetLabelOffsets", &PyDbSectionSymbol::resetLabelOffsets1, DS.ARGS())
        .def("resetLabelOffsets", &PyDbSectionSymbol::resetLabelOffsets2, DS.ARGS({ "allOffsets: bool" }))
        .def("setViewDirectionLeft", &PyDbSectionSymbol::setViewDirectionLeft, DS.ARGS({ "bLeft: bool" }))
        .def("setIsHalfSection", &PyDbSectionSymbol::setIsHalfSection, DS.ARGS({ "bHalfSection: bool" }))
        .def("flipDirection", &PyDbSectionSymbol::flipDirection, DS.ARGS())

        .def("className", &PyDbSectionSymbol::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbSectionSymbol::desc, DS.SARGS()).staticmethod("desc")
        .def("cloneFrom", &PyDbSectionSymbol::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbSectionSymbol::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
#endif
}

//-------------------------------------------------------------------------------------------------------------
// PyDbSectionSymbol
#if defined(_ARXTARGET) || defined(_BRXTARGET) && (_BRXTARGET > 240)
PyDbSectionSymbol::PyDbSectionSymbol()
    : PyDbViewSymbol(new AcDbSectionSymbol(), true)
{
}

PyDbSectionSymbol::PyDbSectionSymbol(AcDbSectionSymbol* ptr, bool autoDelete)
    : PyDbViewSymbol(ptr, autoDelete)
{
}

PyDbSectionSymbol::PyDbSectionSymbol(const PyDbObjectId& id)
    : PyDbViewSymbol(openAcDbObject<AcDbSectionSymbol>(id, AcDb::OpenMode::kForRead), false)
{
}

PyDbSectionSymbol::PyDbSectionSymbol(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbViewSymbol(openAcDbObject<AcDbSectionSymbol>(id, mode), false)
{
}

PyDbSectionSymbol::PyDbSectionSymbol(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbViewSymbol(openAcDbObject<AcDbSectionSymbol>(id, mode, erased), false)
{
}

int PyDbSectionSymbol::sectionPointsCount() const
{
    return impObj()->sectionPointsCount();
}

boost::python::list PyDbSectionSymbol::getSectionPoints() const
{
    AcGePoint3dArray pts;
    impObj()->getSectionPoints(pts);
    return Point3dArrayToPyList(pts);
}

AcGePoint3d PyDbSectionSymbol::getSectionPointAt(int idx) const
{
    AcGePoint3d pt;
    PyThrowBadEs(impObj()->getSectionPointAt(idx, pt));
    return pt;
}

double PyDbSectionSymbol::getBulgeAt(int idx) const
{
    double bulge = 0;
    PyThrowBadEs(impObj()->getBulgeAt(idx, bulge));
    return bulge;
}

std::string PyDbSectionSymbol::getLabelNameAt(int idx) const
{
    AcString sName;
    PyThrowBadEs(impObj()->getLabelNameAt(idx, sName));
    return wstr_to_utf8(sName);
}

AcGeVector3d PyDbSectionSymbol::getLabelOffsetAt(int idx) const
{
    AcGeVector3d offset;
    PyThrowBadEs(impObj()->getLabelOffsetAt(idx, offset));
    return offset;
}

boost::python::list PyDbSectionSymbol::getLabelOffsets() const
{
    AcGeVector3dArray offsets;
    impObj()->getLabelOffsets(offsets);
    return Vector3dArrayToPyList(offsets);
}

bool PyDbSectionSymbol::isViewDirectionLeft() const
{
    return impObj()->isViewDirectionLeft();
}

bool PyDbSectionSymbol::isHalfSection() const
{
    return impObj()->isHalfSection();
}

void PyDbSectionSymbol::setSectionPoints1(const boost::python::list& pts) const
{
#if defined(_BRXTARGET)
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(impObj()->setSectionPoints(PyListToPoint3dArray(pts)));
#endif
}

void PyDbSectionSymbol::setSectionPoints2(const boost::python::list& pts, const boost::python::list& bulges) const
{
#if defined(_BRXTARGET)
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(impObj()->setSectionPoints(PyListToPoint3dArray(pts), PyListToDoubleArray(bulges)));
#endif
}

void PyDbSectionSymbol::addSectionPoint(const AcGePoint3d& pt, double bulge) const
{
#if defined(_BRXTARGET)
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(impObj()->addSectionPoint(pt, bulge));
#endif
}

void PyDbSectionSymbol::removeSectionPointAt(int idx) const
{
#if defined(_BRXTARGET)
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(impObj()->removeSectionPointAt(idx));
#endif
}

void PyDbSectionSymbol::setSectionPointAt(int idx, const AcGePoint3d& pt, double bulge) const
{
#if defined(_BRXTARGET)
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(impObj()->setSectionPointAt(idx, pt, bulge));
#endif
}

void PyDbSectionSymbol::clearSectionPoints() const
{
#if defined(_BRXTARGET)
    throw PyNotimplementedByHost();
#else
    impObj()->clearSectionPoints();
#endif
}

void PyDbSectionSymbol::setLabelNameAt(int idx, const std::string& pName) const
{
#if defined(_BRXTARGET)
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(impObj()->setLabelNameAt(idx, AsWStr(pName)));
#endif
}

void PyDbSectionSymbol::setLabelNames(const boost::python::list& names) const
{
#if defined(_BRXTARGET)
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(impObj()->setLabelNames(PyListToAcStringArray(names)));
#endif
}

void PyDbSectionSymbol::setLabelOffsetAt(int idx, const AcGeVector3d& offset) const
{
#if defined(_BRXTARGET)
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(impObj()->setLabelOffsetAt(idx, offset));
#endif
}

void PyDbSectionSymbol::setLabelOffsets(const boost::python::list& offsets) const
{
#if defined(_BRXTARGET)
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(impObj()->setLabelOffsets(PyListToVector3dArray(offsets)));
#endif
}

void PyDbSectionSymbol::resetLabelOffsets1() const
{
#if defined(_BRXTARGET)
    throw PyNotimplementedByHost();
#else
    impObj()->resetLabelOffsets();
#endif
}

void PyDbSectionSymbol::resetLabelOffsets2(bool allOffsets) const
{
#if defined(_BRXTARGET)
    throw PyNotimplementedByHost();
#else
    impObj()->resetLabelOffsets(allOffsets);
#endif
}

void PyDbSectionSymbol::setViewDirectionLeft(bool bLeft) const
{
#if defined(_BRXTARGET)
    throw PyNotimplementedByHost();
#else
    impObj()->setViewDirectionLeft(bLeft);
#endif
}

void PyDbSectionSymbol::setIsHalfSection(bool bHalfSection) const
{
#if defined(_BRXTARGET)
    throw PyNotimplementedByHost();
#else
    impObj()->setIsHalfSection(bHalfSection);
#endif
}

bool PyDbSectionSymbol::flipDirection() const
{
#if defined(_BRXTARGET)
    throw PyNotimplementedByHost();
#else
    return impObj()->flipDirection();
#endif
}

PyRxClass PyDbSectionSymbol::desc()
{
    return PyRxClass(AcDbSectionSymbol::desc(), false);
}

std::string PyDbSectionSymbol::className()
{
    return "AcDbSectionSymbol";
}

PyDbSectionSymbol PyDbSectionSymbol::cloneFrom(const PyRxObject& src)
{
    return PyDbObjectCloneFrom<PyDbSectionSymbol, AcDbSectionSymbol>(src);
}

PyDbSectionSymbol PyDbSectionSymbol::cast(const PyRxObject& src)
{
    return PyDbSectionSymbol(AcDbSectionSymbol::cast(PyRxObject(src).impObj()), false);
}

AcDbSectionSymbol* PyDbSectionSymbol::impObj(const std::source_location& src) const
{
    auto res = static_cast<AcDbSectionSymbol*>(PyDbObject::impObj(src));
    if (!res)
        throw PyNullObject(src);
    return res;
}
#endif
