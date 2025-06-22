#include "stdafx.h"
#include "PyAcDb.h"
#include "PyDbEntity.h"
#include "PyDbObjectId.h"
#include "PyDbDatabase.h"
#include "PyDbHostApplicationServices.h"
#include "PyDbSymbolTableRecord.h"
#include "PyDbDictionary.h"
#include "PyDbSymbolTable.h"
#include "PyCmColorBase.h"
#include "PyDbField.h"
#include "PyDbEnts.h"
#include "PyDbCurve.h"
#include "PyDbMText.h"
#include "PyDbTable.h"
#include "PyDbTableStyle.h"
#include "PyDb3dSolid.h"
#include "PyDbSurface.h"
#include "PyDbDimension.h"
#include "PyDbIdMapping.h"
#include "PyDbLeader.h"
#include "DbCore.h"
#include "PyDbMline.h"
#include "PyDbHatch.h"
#include "PyDbXrecord.h"
#include "PyDbUnderlayReference.h"
#include "PyDbImage.h"
#include "PyDbTransactionManager.h"
#include "PyDbEval.h"
#include "PyDbLayout.h"
#include "PyDbViewport.h"
#include "PyDbObjectContext.h"
#include "PyDbProtocolExtensions.h"
#include "PyDbFiler.h"
#include "PyDbSpline.h"
#include "PyDbGroup.h"
#include "PyDbEllipse.h"
#include "PyDbDimAssoc.h"
#include "PyDbPointRef.h"
#include "PyDbDatabaseReactor.h"
#include "PyDb3dProfile.h"
#include "PyDbOverrule.h"
#include "PyDbPointCloudEx.h"
#include "PyDbSpatialFilter.h"
#include "PyDbGeo.h"
#include "PyDbDate.h"
#include "PyDbSubDMesh.h"
#include "PyDbGripData.h"
#include "PyDbDbLayerStateManager.h"
#include "PyDbSection.h"
#include "PyDbHyperlink.h"
#include "PyDbGraph.h"
#include "PyGeLinearEnt2d.h"
#include "PyGeLinearEnt3d.h"


using namespace boost::python;

static PyDbDatabase curPyDb()
{
    if (curDoc() == nullptr)
        PyThrowBadEs(eNoDocument);
    return PyDbDatabase(curDoc()->database(), false);
}

static PyDbDatabase workingPyDb()
{
    return PyDbDatabase(acdbHostApplicationServices()->workingDatabase(), false);
}

static void setWorkingPyDb(PyDbDatabase& wpd)
{
    acdbHostApplicationServices()->setWorkingDatabase(wpd.impObj());
}

static std::string AcDbExtents2dToString(const AcDbExtents2d& p)
{
    const auto& mi = p.minPoint();
    const auto& ma = p.maxPoint();
    return std::format("(({:.14f},{:.14f}),({:.14f},{:.14f}))", mi.x, mi.y, ma.x, ma.y);
}

static std::string AcDbExtents2dToStringRepr(const AcDbExtents2d& p)
{
    const auto& mi = p.minPoint();
    const auto& ma = p.maxPoint();
    return std::format("{}.Extents2d(({:.14f},{:.14f}),({:.14f},{:.14f}))", PyGeNamespace, mi.x, mi.y, ma.x, ma.y);
}

static boost::python::tuple AcDbExtents2dCoords(const AcDbExtents2d& extents)
{
    PyAutoLockGIL lock;
    const auto& min = extents.minPoint();
    const auto& max = extents.maxPoint();
    return boost::python::make_tuple(min.x, min.y, max.x, max.y);
}

static void AcDbExtents2dAddPoints(AcDbExtents2d& extents, const boost::python::object& iterable)
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    for (const auto& point : PyListToPoint2dArray(iterable))
        extents.addPoint(point);
#endif
}

static AcGePoint2d AcDbExtents2dMidPoint(const AcDbExtents2d& extents)
{
    AcGeLineSeg2d seg(extents.minPoint(), extents.maxPoint());
    return seg.midPoint();
}

static bool AcDbExtents2dContains1(const AcDbExtents2d& extents, AcGePoint2d pnt)
{
    const auto& min = extents.minPoint();
    const auto& max = extents.maxPoint();
    return min.x <= pnt.x && min.y <= pnt.y &&
        max.x >= pnt.x && max.y >= pnt.y;
}

static bool AcDbExtents2dContains2(const AcDbExtents2d& extents, const AcDbExtents2d& other)
{
    return AcDbExtents2dContains1(extents, other.minPoint()) && AcDbExtents2dContains1(extents, other.maxPoint());
}

static bool AcDbExtents2dIntersects1(const AcDbExtents2d& extents, const AcDbExtents2d& other)
{
    if (AcDbExtents2dContains1(other, extents.minPoint()))
        return true;
    if (AcDbExtents2dContains1(other, extents.maxPoint()))
        return true;
    if (AcDbExtents2dContains1(extents, other.minPoint()))
        return true;
    if (AcDbExtents2dContains1(extents, other.maxPoint()))
        return true;
    return false;
}

static bool AcDbExtents2dIntersects2(const AcDbExtents2d& extents, const PyGeLinearEnt2d& other)
{
    auto ul = AcGePoint2d(extents.minPoint().x, extents.maxPoint().y);
    auto lr = AcGePoint2d(extents.maxPoint().x, extents.minPoint().y);
    AcGePoint2d _tmp;
    if (other.impObj()->intersectWith(AcGeLineSeg2d(ul, extents.minPoint()), _tmp))
        return true;
    if (other.impObj()->intersectWith(AcGeLineSeg2d(ul,extents.minPoint()), _tmp))
        return true;
    if (other.impObj()->intersectWith(AcGeLineSeg2d(extents.maxPoint(), lr), _tmp))
        return true;
    if (other.impObj()->intersectWith(AcGeLineSeg2d(extents.minPoint(), lr), _tmp))
        return true;
    return false;
}

static void makePyDbExtents2dWrapper()
{
    constexpr const std::string_view ctords = "Overloads:\n"
        "- None: Any\n"
        "- min: PyGe.Point2d, max: PyGe.Point2d\n";

    PyDocString DS("Extents2d");
    class_<AcDbExtents2d>("Extents2d")
        .def(init<>())
        .def(init<const AcGePoint2d&, const AcGePoint2d&>(DS.CTOR(ctords)))
        .def("minPoint", &AcDbExtents2d::minPoint, DS.ARGS(4523))
        .def("maxPoint", &AcDbExtents2d::maxPoint, DS.ARGS(4522))
        .def("midPoint", &AcDbExtents2dMidPoint, DS.ARGS())
        .def("set", &AcDbExtents2d::set, DS.ARGS({ "min: PyGe.Point2d","max: PyGe.Point2d" }, 4524))
        .def("addPoint", &AcDbExtents2d::addPoint, DS.ARGS({ "pt: PyGe.Point2d" }, 4520))
        .def("addPoints", &AcDbExtents2dAddPoints, DS.ARGS({ "pts: list[PyGe.Point2d]" }, 4520))
        .def("addExt", &AcDbExtents2d::addExt, DS.ARGS({ "ex: PyDb.Extents2d" }, 4519))
        .def("expandBy", &AcDbExtents2d::expandBy, DS.ARGS({ "vector: PyGe.Vector2d" }, 4521))
        .def("transformBy", &AcDbExtents2d::transformBy, DS.ARGS({ "xform: PyGe.Matrix2d" }, 4525))
        .def("intersectsWith", &AcDbExtents2dIntersects1)
        .def("intersectsWith", &AcDbExtents2dIntersects2, DS.ARGS({ "ex: PyDb.Extents2d | PyGe.LinearEnt2d" }))
        .def("coords", &AcDbExtents2dCoords, DS.ARGS())
        .def("contains", &AcDbExtents2dContains1)
        .def("contains", &AcDbExtents2dContains2, DS.ARGS({ "val: PyDb.Extents2d|PyGe.Point2d" }))
        .def("__str__", &AcDbExtents2dToString, DS.ARGS())
        .def("__repr__", &AcDbExtents2dToStringRepr, DS.ARGS())
        ;
}

static std::string AcDbExtentsToString(const AcDbExtents& p)
{
    const auto& mi = p.minPoint();
    const auto& ma = p.maxPoint();
    return std::format("(({:.14f},{:.14f},{:.14f}),({:.14f},{:.14f},{:.14f}))", mi.x, mi.y, mi.z, ma.x, ma.y, ma.z);
}

static std::string AcDbExtentsToStringRepr(const AcDbExtents& p)
{
    const auto& mi = p.minPoint();
    const auto& ma = p.maxPoint();
    return std::format("{}.Extents(({:.14f},{:.14f},{:.14f}),({:.14f},{:.14f},{:.14f}))", PyGeNamespace, mi.x, mi.y, mi.z, ma.x, ma.y, ma.z);
}

static boost::python::tuple AcDbExtents3dCoords(const AcDbExtents& extents)
{
    PyAutoLockGIL lock;
    const auto& min = extents.minPoint();
    const auto& max = extents.maxPoint();
    return boost::python::make_tuple(min.x, min.y, min.z, max.x, max.y, max.z);
}

static void AcDbExtents3dAddPoints(AcDbExtents& extents, const boost::python::object& iterable)
{
    for (const auto& point : PyListToPoint3dArray(iterable))
        extents.addPoint(point);
}

static AcGePoint3d AcDbExtents3dMidPoint(const AcDbExtents& extents)
{
    AcGeLineSeg3d seg(extents.minPoint(), extents.maxPoint());
    return seg.midPoint();
}

static void AcDbExtentsaddBlockExt(AcDbExtents& extents, const PyDbBlockTableRecord& rec)
{
    extents.addBlockExt(rec.impObj());
}

static bool AcDbExtentsContains1(const AcDbExtents& extents, const AcGePoint3d& pnt)
{
    const auto& min = extents.minPoint();
    const auto& max = extents.maxPoint();
    return min.x <= pnt.x && min.y <= pnt.y && min.z <= pnt.z &&
        max.x >= pnt.x && max.y >= pnt.y && max.z >= pnt.z;
}

static bool AcDbExtents3dIntersects1(const AcDbExtents& extents, const AcDbExtents& other)
{
    if (AcDbExtentsContains1(other, extents.minPoint()))
        return true;
    if (AcDbExtentsContains1(other, extents.maxPoint()))
        return true;
    if (AcDbExtentsContains1(extents, other.minPoint()))
        return true;
    if (AcDbExtentsContains1(extents, other.maxPoint()))
        return true;
    return false;
}

static bool AcDbExtents3dIntersects2(const AcDbExtents& extents, const PyGeLinearEnt3d& other)
{
    AcGePoint3d x1(extents.minPoint().x, extents.minPoint().y, extents.minPoint().z);
    AcGePoint3d x2(extents.minPoint().x, extents.minPoint().y, extents.maxPoint().z);
    AcGePoint3d x3(extents.minPoint().x, extents.maxPoint().y, extents.minPoint().z);
    AcGePoint3d x4(extents.minPoint().x, extents.maxPoint().y, extents.maxPoint().z);
    AcGePoint3d x5(extents.maxPoint().x, extents.minPoint().y, extents.minPoint().z);
    AcGePoint3d x6(extents.maxPoint().x, extents.minPoint().y, extents.maxPoint().z);
    AcGePoint3d x7(extents.maxPoint().x, extents.maxPoint().y, extents.minPoint().z);
    AcGePoint3d x8(extents.maxPoint().x, extents.maxPoint().y, extents.maxPoint().z);

    AcGePoint3d _tmp;
    {//flat?
        if (other.impObj()->intersectWith(AcGeLineSeg3d(x1, x2), _tmp))
            return true;
        if (other.impObj()->intersectWith(AcGeLineSeg3d(x2, x6), _tmp))
            return true;
        if (other.impObj()->intersectWith(AcGeLineSeg3d(x6, x4), _tmp))
            return true;
        if (other.impObj()->intersectWith(AcGeLineSeg3d(x4, x1), _tmp))
            return true;
    }
    {
        AcGeBoundedPlane front(x1, x2 - x1, x4 - x1);
        if (front.intersectWith(*other.impObj(), _tmp))
            return true;
    }
    {
        AcGeBoundedPlane left(x3, x1 - x3, x7 - x3);
        if (left.intersectWith(*other.impObj(), _tmp))
            return true;
    }
    {
        AcGeBoundedPlane back(x5, x3 - x5, x8 - x5);
        if (back.intersectWith(*other.impObj(), _tmp))
            return true;
    }
    {
        AcGeBoundedPlane right(x2, x5 - x2, x6 - x2);
        if (right.intersectWith(*other.impObj(), _tmp))
            return true;
    }
    {
        AcGeBoundedPlane top(x4, x5 - x4, x7 - x4);
        if (top.intersectWith(*other.impObj(), _tmp))
            return true;
    }
    {
        AcGeBoundedPlane bottom(x1, x2 - x1, x3 - x1);
        if (bottom.intersectWith(*other.impObj(), _tmp))
            return true;
    }
    return false;
}

static bool AcDbExtentsContains2(const AcDbExtents& extents, const AcDbExtents& other)
{
    return AcDbExtentsContains1(extents, other.minPoint()) && AcDbExtentsContains1(extents, other.maxPoint());
}

static void makePyDbExtentsWrapper()
{
    constexpr const std::string_view ctords = "Overloads:\n"
        "- None: Any\n"
        "- min: PyGe.Point3d, max: PyGe.Point3d\n";

    PyDocString DS("Extents");
    class_<AcDbExtents>("Extents")
        .def(init<>())
        .def(init<const AcGePoint3d&, const AcGePoint3d&>(DS.CTOR(ctords)))
        .def("minPoint", &AcDbExtents::minPoint, DS.ARGS(4533))
        .def("maxPoint", &AcDbExtents::maxPoint, DS.ARGS(4532))
        .def("midPoint", &AcDbExtents3dMidPoint, DS.ARGS())
        .def("set", &AcDbExtents::set, DS.ARGS({ "min: PyGe.Point3d","max: PyGe.Point3d" }, 4534))
        .def("addPoint", &AcDbExtents::addPoint, DS.ARGS({ "pt: PyGe.Point3d" }, 4530))
        .def("addPoints", &AcDbExtents3dAddPoints, DS.ARGS({ "pts: list[PyGe.Point3d]" }, 4530))
        .def("addExt", &AcDbExtents::addExt, DS.ARGS({ "extents: PyDb.Extents" }, 4529))
        .def("expandBy", &AcDbExtents::expandBy, DS.ARGS({ "vec: PyGe.Vector3d" }, 4531))
        .def("transformBy", &AcDbExtents::transformBy, DS.ARGS({ "xform: PyGe.Matrix3d" }, 4535))
        .def("intersectsWith", &AcDbExtents3dIntersects1)
        .def("intersectsWith", &AcDbExtents3dIntersects2, DS.ARGS({ "other: PyDb.Extents|PyGe.LinearEnt3d" }))
        .def("coords", &AcDbExtents3dCoords, DS.ARGS())
        .def("addBlockExt", &AcDbExtentsaddBlockExt, DS.ARGS({ "btr: PyDb.BlockTableRecord" }, 4528))
        .def("contains", &AcDbExtentsContains1)
        .def("contains", &AcDbExtentsContains2, DS.ARGS({ "val: PyDb.Extents|PyGe.Point3d" }))
        .def("__str__", &AcDbExtentsToString, DS.ARGS())
        .def("__repr__", &AcDbExtentsToStringRepr, DS.ARGS())
        ;
}

static BOOST_PYTHON_MODULE(PyDb)
{
    docstring_options local_docstring_options(py_show_user_defined, py_show_py_signatures, py_show_cpp_signatures);

    PyErrorStatusException::makePyErrorStatusExceptionWrapper();

    makePyDbGraphNodeWrapper();
    makePyDbObjectIdGraphNodeWrapper();
    makePyDbXrefGraphNodeWrapper();
    makePyDbGraphWrapper();
    makePyObjectIdGraphWrapper();
    makePyAcDbXrefGraphWrapper();
    makePyDbDateWrapper();
    makePyDbGripDataWrapper();
    makePyDbSubentIdWrapper();
    makePyDbFullSubentPathWrapper();
    makePyDbExtents2dWrapper();
    makePyDbExtentsWrapper();
    makePyCmColorWrapper();
    makePyCmEntityColorWrapper();
    makePyCmTransparencyWrapper();
    makePyDbObjectIdWrapper();
    makePySoftPointerIdWrapper();
    makePyDbSoftOwnershipIdWrapper();
    makePyDbHardPointerIdWrapper();
    makePyDbAcDbHardOwnershipIdWrapper();
    makePyDbHandleWrapper();
    makePyDbXrefObjectIdWrapper();
    makePyAdsNameWrapper();
    makePyDbObjectWrapper();
    makePyDbSpatialFilterWrapper();
    makePyDbIndexFilterManagerWrapper();
    makePyDbLayerFilterWrapper();
    makePyDbObjectReactorWrapper();
    makePyDbEntityReactorWrapper();
    makePyDbDatabaseReactorWrapper();
    makePyDbFieldWrapper();
    makePyDdFieldEvaluatorWrapper();
    makePyDbFieldEngineWrapper();
    makePyDbEntityWrapper();
    makePyDbBlockBeginWrapper();
    makePyDbBlockEndWrapper();
    makePyDbSequenceEndWrapper();
    makePyDbXrecordWrapper();
    makePyDbObjectContextCollectionWrapper();
    makePyDbObjectContextManagerWrapper();
    makePyDbObjectContextWrapper();
    makePyDbAnnotationScaleWrapper();
    makePyDbTableStyleWrapper();
    makePyDbMLeaderStyleWrapper();
    makePyDbMlineStyleWrapper();
    makePyDbTextWrapper();
    makePyDbAttributeDefinitionWrapper();
    makePyDbAttributeWrapper();
    makePyDbBlockReferenceWrapper();
    makePyDbDynBlockReferenceWrapper();
    makePyDbMInsertBlockeWrapper();
    makePyDbMTextWrapper();
    makePyDbTableWrapper();
    makePyDbViewportWrapper();
    makePyDbVertexWrapper();
    makePyDb2dVertexWrapper();
    makePyDb3dPolylineVertexWrapper();
    makePyDbPolygonMeshVertexWrapper();
    makePyDbPolyFaceMeshVertexWrapper();
    makePyDbFaceRecordWrapper();
    makePyDbCurveWrapper();
    makePyDbPointWrapper();
    makePyDb2dPolylineWrapper();
    makePyDb3dPolylineWrapper();
    makePyDbArcWrapper();
    makePyDbCircleWrapper();
    makePyDbLineWrapper();
    makePyDbPolylineWrapper();
    makePyDbFaceWrapper();
    makePyDbFcfWrapper();
    makePyDbEllipseWrapper();
    makePyDbSplineWrapper();
    makePyDbHelixWrapper();
    makePyDbMlineWrapper();
    makePyDbHatchWrapper();
    makePyDbMPolygonWrapper();
    makePyDbDictionaryWrapper();
    makePyDbSymbolTableWrapper();
    makePyDbSymbolTableRecordWrapper();
    makePyDbDimStyleTableWrapper();
    makePyDbDimStyleTableRecordWrapper();
    makePyDbBlockTableWrapper();
    makePyDbSortentsTableWrapper();
    makePyDbBlockTableRecordWrapper();
    makePyDbTextStyleTableWrapper();
    makePyDbTextStyleTableRecordWrapper();
    makePyDbUCSTableWrapper();
    makePyDbUCSTableRecordWrapper();
    makePyDbRegAppTableWrapper();
    makePyDbRegAppTableRecordWrapper();
    makePyDbLinetypeTableWrapper();
    makePyDbLinetypeTableRecordWrapper();
    makePyDbLayerTableWrapper();
    makePyDbLayerTableRecordWrapper();
    makePyDbAbstractViewTableWrapper();
    makePyDbViewportTableWrapper();
    makePyDbViewTableWrapper();
    makePyDbAbstractViewTableRecordWrapper();
    makePyDbViewportTableRecordWrapper();
    makePyDbViewTableRecordWrapper();
    makePyDbDatabaseWrapper();
    makePyDbHostApplicationServicesWrapper();
    makePyOutputDisplayServiceWrapper();
    makePyDbSymUtilServicesWrapper();
    makePyDb3dSolidWrapper();
    makePyDbRegionWrapper();
    makePyDbBodyWrapper();
    makePyDbRevolveOptionsWrapper();
    makePyDbSweepOptionsWrapper();
    makePyDbSurfaceWrapper();
    makePyDbExtrudedSurfaceWrapper();
    makePyDbLoftedSurfaceWrapper();
    makePyDbNurbSurfaceWrapper();
    makePyDbPlaneSurfaceWrapper();
    makePyDbRevolvedSurfaceWrapper();
    makePyDbSweptSurfaceWrapper();
    makePyDbDimensionWrapper();
    makePyDb2LineAngularDimensionWrapper();
    makePyDb3PointAngularDimensionWrapper();
    makePyDbAlignedDimensionWrapper();
    makePyDbArcDimensionWrapper();
    makePyDbDiametricDimensionWrapper();
    makePyDbOrdinateDimensionWrapper();
    makePyDbRadialDimensionWrapper();
    makePyDbRadialDimensionLargeWrapper();
    makePyDbRotatedDimensionWrapper();
    makePyDbLeaderWrapper();
    makePyDbMLeaderWrapper();
    makePyUnderlayLayerWrapper();
    makePyDbUnderlayDefinitionWrapper();
    makePyDbUnderlayReferenceWrapper();
    makePyDbPdfDefinitionWrapper();
    makePyDbPdfReferenceWrapper();
    makePyDbImageWrapper();
    makePyDbRasterImageDefWrapper();
    makePyDbRasterImageDefReactorWrapper();
    makePyDbRasterImageWrapper();
    makePyDbWipeoutWrapper();
    makePyIdPairWrapper();
    makePyDbIdMappingWrapper();
    makePyDbTransactionManager();
    makePyTransaction();
    makePyDbPlotSettingsWrapper();
    makePyDbLayoutWrapper();
    makePyDbLayoutManagerWrapper();
    makePyDbEvalVariantWrapper();
    makePyDbDynBlockReferencePropertyWrapper();
    makePyDbJoinEntityPEWrapper();
    makePyDbAssocPersSubentIdPEWrapper();
    makePyDbGroupWrapper();
    makePyDbDatabaseSummaryInfoWrapper();
    makePyDbPlotSettingsValidatorWrapper();
    makePyDbDictUtilWrapper();
    makePyDbSnoopDwgFilerWrapper();
    makePyDbSnoopDxfFilerrWrapper();
    makePyDbPointRefWrapper();
    makePyDbOsnapPointRefWrapper();
    makePyDbDimAssocWrapper();
#if !defined(_BRXTARGET250)
    makePyDb3dProfileWrapper();
#endif
    makePyDbObjectOverruleWrapper();
    makePyDbOsnapOverruleWrapper();
#if !defined(_BRXTARGET250)
    makePyDbPointCloudCropWrapper();
    makePyDbPointCloudClassificationColorRampWrapper();
    makePyDbPointCloudColorRampWrapper();
    makePyDbPointCloudDefExWrapper();
    makePyDbPointCloudExWrapper();
    makePyDbPointCloudColorMapWrapper();
#endif
    makePyDbGeoDataWrapper();
    makePyDbGeoPositionMarkerWrapper();
    makePyDbGeoMapWrapper();
    makePyDbGeoCoordinateSystemWrapper();
    makePyDbGeoCoordinateSystemTransformerWrapper();
    makePyDbSectionWrapper();
    makePyDbSectionSettingsWrapper();
    makePyDbSectionManagerWrapper();
    makePyDbSolidWrapper();
    makePyDbTraceWrapper();
    makePyDbShapeWrapper();
    makePyDbDynBlockTableRecordWrapper();
    makePyDbSubDMeshWrapper();
    makePyDbDbLayerStateManagerWrapper();
    makePyDbAcValueWrapper();
    makePyAutoWorkingDatabase();
    makePyDbHyperlinkWrapper();
    makePyDbHyperlinkCollectionWrapper();
    makePyDbEntityHyperlinkPEWrapper();
    makeDbCoreWrapper();//LAST?

    //convenience 
    def("curDb", curPyDb);
    def("workingDb", workingPyDb);
    def("setWorkingDb", setWorkingPyDb);

    //enums
    enum_<AcDbLayerStateManager::LayerStateMask>("LayerStateMask")
        .value("kNone", AcDbLayerStateManager::LayerStateMask::kNone)
        .value("kOn", AcDbLayerStateManager::LayerStateMask::kOn)
        .value("kFrozen", AcDbLayerStateManager::LayerStateMask::kFrozen)
        .value("kLocked", AcDbLayerStateManager::LayerStateMask::kLocked)
        .value("kPlot", AcDbLayerStateManager::LayerStateMask::kPlot)
        .value("kNewViewport", AcDbLayerStateManager::LayerStateMask::kNewViewport)
        .value("kColor", AcDbLayerStateManager::LayerStateMask::kColor)
        .value("kLineType", AcDbLayerStateManager::LayerStateMask::kLineType)
        .value("kLineWeight", AcDbLayerStateManager::LayerStateMask::kLineWeight)
        .value("kPlotStyle", AcDbLayerStateManager::LayerStateMask::kPlotStyle)
        .value("kCurrentViewport", AcDbLayerStateManager::LayerStateMask::kCurrentViewport)
#if !defined (_BRXTARGET250)
        .value("kTransparency", AcDbLayerStateManager::LayerStateMask::kTransparency)
#endif
        .value("kAll", AcDbLayerStateManager::LayerStateMask::kAll)
        .value("kStateIsHidden", AcDbLayerStateManager::LayerStateMask::kStateIsHidden)
#if !defined (_BRXTARGET250)
        .value("kLastRestored", AcDbLayerStateManager::LayerStateMask::kLastRestored)
#endif
#if !defined (_BRXTARGET250)
        .value("kDecomposition", AcDbLayerStateManager::LayerStateMask::kDecomposition)
#endif
        .export_values()
        ;
    enum_<AcDb::CellOption>("CellOption")
        .value("kNoMap", AcDb::CellOption::kCellOptionNone)
        .value("kAerial", AcDb::CellOption::kInheritCellFormat)
        .export_values()
        ;
    enum_<AcDb::DimArrowFlags>("DimArrowFlags")
        .value("kNoMap", AcDb::DimArrowFlags::kFirstArrow)
        .value("kAerial", AcDb::DimArrowFlags::kSecondArrow)
        .export_values()
        ;
    enum_<AnnotativeStates>("AnnotativeStates")
        .value("kTrue", AnnotativeStates::kTrue)
        .value("kFalse", AnnotativeStates::kFalse)
        .value("kNotApplicable", AnnotativeStates::kNotApplicable)
        .export_values()
        ;
    enum_<AcGeoMapType>("AcGeoMapType")
        .value("kNoMap", AcGeoMapType::kNoMap)
        .value("kAerial", AcGeoMapType::kAerial)
        .value("kRoad", AcGeoMapType::kRoad)
        .value("kHybrid", AcGeoMapType::kHybrid)
#if defined(_ARXTARGET) && (_ARXTARGET >= 250)
        .value("kBingAerial", AcGeoMapType::kBingAerial)
        .value("kBingRoad", AcGeoMapType::kBingRoad)
        .value("kBingHybrid", AcGeoMapType::kBingHybrid)
        .value("kEsriImagery", AcGeoMapType::kEsriImagery)
        .value("kEsriOpenStreetMap", AcGeoMapType::kEsriOpenStreetMap)
        .value("kEsriStreets", AcGeoMapType::kEsriStreets)
        .value("kEsriLightGray", AcGeoMapType::kEsriLightGray)
        .value("kEsriDarkGray", AcGeoMapType::kEsriDarkGray)
#endif
        .export_values()
        ;
    enum_<AcGeoMapResolution>("AcGeoMapResolution")
        .value("kCoarse", AcGeoMapResolution::kCoarse)
        .value("kOptimal", AcGeoMapResolution::kOptimal)
        .value("kFine", AcGeoMapResolution::kFine)
        .value("kFiner", AcGeoMapResolution::kFiner)
        .export_values()
        ;
    enum_<AcDb::AcDbDwgVersion>("DwgVersion")
        .value("kDHL_MC0_0", AcDb::AcDbDwgVersion::kDHL_MC0_0)
        .value("kDHL_AC1_2", AcDb::AcDbDwgVersion::kDHL_AC1_2)
        .value("kDHL_AC1_40", AcDb::AcDbDwgVersion::kDHL_AC1_40)
        .value("kDHL_AC1_50", AcDb::AcDbDwgVersion::kDHL_AC1_50)
        .value("kDHL_AC2_20", AcDb::AcDbDwgVersion::kDHL_AC2_20)
        .value("kDHL_AC2_10", AcDb::AcDbDwgVersion::kDHL_AC2_10)
        .value("kDHL_AC2_21", AcDb::AcDbDwgVersion::kDHL_AC2_21)
        .value("kDHL_AC2_22", AcDb::AcDbDwgVersion::kDHL_AC2_22)
        .value("kDHL_1001", AcDb::AcDbDwgVersion::kDHL_1001)
        .value("kDHL_1002", AcDb::AcDbDwgVersion::kDHL_1002)
        .value("kDHL_1003", AcDb::AcDbDwgVersion::kDHL_1003)
        .value("kDHL_1004", AcDb::AcDbDwgVersion::kDHL_1004)
        .value("kDHL_1005", AcDb::AcDbDwgVersion::kDHL_1005)
        .value("kDHL_1006", AcDb::AcDbDwgVersion::kDHL_1006)
        .value("kDHL_1007", AcDb::AcDbDwgVersion::kDHL_1007)
        .value("kDHL_1008", AcDb::AcDbDwgVersion::kDHL_1008)
        .value("kDHL_1009", AcDb::AcDbDwgVersion::kDHL_1009)
        .value("kDHL_1010", AcDb::AcDbDwgVersion::kDHL_1010)
        .value("kDHL_1011", AcDb::AcDbDwgVersion::kDHL_1011)
        .value("kDHL_1012", AcDb::AcDbDwgVersion::kDHL_1012)
        .value("kDHL_1013", AcDb::AcDbDwgVersion::kDHL_1013)
        .value("kDHL_1014", AcDb::AcDbDwgVersion::kDHL_1014)
        .value("kDHL_1500", AcDb::AcDbDwgVersion::kDHL_1500)
        .value("kDHL_1015", AcDb::AcDbDwgVersion::kDHL_1015)
        .value("kDHL_1800a", AcDb::AcDbDwgVersion::kDHL_1800a)
        .value("kDHL_1800", AcDb::AcDbDwgVersion::kDHL_1800)
        .value("kDHL_2100a", AcDb::AcDbDwgVersion::kDHL_2100a)
        .value("kDHL_1021", AcDb::AcDbDwgVersion::kDHL_1021)
        .value("kDHL_2400a", AcDb::AcDbDwgVersion::kDHL_2400a)
        .value("kDHL_1024", AcDb::AcDbDwgVersion::kDHL_1024)
        .value("kDHL_2700a", AcDb::AcDbDwgVersion::kDHL_2700a)
        .value("kDHL_1027", AcDb::AcDbDwgVersion::kDHL_1027)
        .value("kDHL_3200a", AcDb::AcDbDwgVersion::kDHL_3200a)
        .value("kDHL_1032", AcDb::AcDbDwgVersion::kDHL_1032)
        .value("kDHL_Newest", AcDb::AcDbDwgVersion::kDHL_Newest)
        .value("kDHL_CURRENT", AcDb::AcDbDwgVersion::kDHL_CURRENT)
        .value("kDHL_Unknown", AcDb::AcDbDwgVersion::kDHL_Unknown)
        .value("kDHL_Max", AcDb::AcDbDwgVersion::kDHL_Max)
        .export_values()
        ;
    enum_<AcDbGeoData::TypeOfCoordinates>("GeoTypeOfCoordinates")
        .value("kCoordTypUnknown", AcDbGeoData::TypeOfCoordinates::kCoordTypUnknown)
        .value("kCoordTypLocal", AcDbGeoData::TypeOfCoordinates::kCoordTypLocal)
        .value("kCoordTypGrid", AcDbGeoData::TypeOfCoordinates::kCoordTypGrid)
        .value("kCoordTypGeographic", AcDbGeoData::TypeOfCoordinates::kCoordTypGeographic)
        .export_values()
        ;
    enum_<AcDbGeoData::ScaleEstimationMethod>("GeoScaleEstimationMethod")
        .value("kScaleEstMethodUnity", AcDbGeoData::ScaleEstimationMethod::kScaleEstMethodUnity)
        .value("kScaleEstMethodUserDefined", AcDbGeoData::ScaleEstimationMethod::kScaleEstMethodUserDefined)
        .value("kScaleEstMethodReferencePoint", AcDbGeoData::ScaleEstimationMethod::kScaleEstMethodReferencePoint)
        .value("kScaleEstMethodPrismoidal", AcDbGeoData::ScaleEstimationMethod::kScaleEstMethodPrismoidal)
        .export_values()
        ;
    enum_<AcDbGeoPositionMarker::TextAlignmentType>("GeoTextAlignmentType")
        .value("kLeftAlignment", AcDbGeoPositionMarker::TextAlignmentType::kLeftAlignment)
        .value("kCenterAlignment", AcDbGeoPositionMarker::TextAlignmentType::kCenterAlignment)
        .value("kRightAlignment", AcDbGeoPositionMarker::TextAlignmentType::kRightAlignment)
        .export_values()
        ;
    enum_<AcDbPointRef::OsnapType>("OsnapType")
        .value("kOsnapNone", AcDbPointRef::OsnapType::kOsnapNone)
        .value("kOsnapEnd", AcDbPointRef::OsnapType::kOsnapEnd)
        .value("kOsnapMid", AcDbPointRef::OsnapType::kOsnapMid)
        .value("kOsnapCen", AcDbPointRef::OsnapType::kOsnapCen)
        .value("kOsnapNode", AcDbPointRef::OsnapType::kOsnapNode)
        .value("kOsnapQuad", AcDbPointRef::OsnapType::kOsnapQuad)
        .value("kOsnapInt", AcDbPointRef::OsnapType::kOsnapInt)
        .value("kOsnapIns", AcDbPointRef::OsnapType::kOsnapIns)
        .value("kOsnapPerp", AcDbPointRef::OsnapType::kOsnapPerp)
        .value("kOsnapTan", AcDbPointRef::OsnapType::kOsnapTan)
        .value("kOsnapNear", AcDbPointRef::OsnapType::kOsnapNear)
        .value("kOsnapApint", AcDbPointRef::OsnapType::kOsnapApint)
        .value("kOsnapStart", AcDbPointRef::OsnapType::kOsnapStart)
#if !defined(_ZRXTARGET) || (_ZRXTARGET > 240)
        .value("kOsnapCentroid", AcDbPointRef::OsnapType::kOsnapCentroid)
#endif
        .export_values()
        ;
    enum_<AcDbDimAssoc::PointType>("DimAssocPointType")
        .value("kXline1Point", AcDbDimAssoc::PointType::kXline1Point)
        .value("kXline2Point", AcDbDimAssoc::PointType::kXline2Point)
        .value("kOriginPoint", AcDbDimAssoc::PointType::kOriginPoint)
        .value("kDefiningPoint", AcDbDimAssoc::PointType::kDefiningPoint)
        .value("kXline1Start", AcDbDimAssoc::PointType::kXline1Start)
        .value("kXline1End", AcDbDimAssoc::PointType::kXline1End)
        .value("kXline2Start", AcDbDimAssoc::PointType::kXline2Start)
        .value("kXline2End", AcDbDimAssoc::PointType::kXline2End)
        .value("kVertexPoint", AcDbDimAssoc::PointType::kVertexPoint)
        .value("kChordPoint", AcDbDimAssoc::PointType::kChordPoint)
        .value("kCenterPoint", AcDbDimAssoc::PointType::kCenterPoint)
        .value("kFarChordPoint", AcDbDimAssoc::PointType::kFarChordPoint)
        .value("kOverrideCenterPoint", AcDbDimAssoc::PointType::kOverrideCenterPoint)
        .value("kAngLineStart", AcDbDimAssoc::PointType::kAngLineStart)
        .value("kJogPoint", AcDbDimAssoc::PointType::kJogPoint)
        .value("kAngLineEnd", AcDbDimAssoc::PointType::kAngLineEnd)
        .value("kLeaderPoint", AcDbDimAssoc::PointType::kLeaderPoint)
        .export_values()
        ;
    enum_<AcDbDimAssoc::AssocFlags>("AssocFlags")
        .value("kFirstPointRef", AcDbDimAssoc::AssocFlags::kFirstPointRef)
        .value("kSecondPointRef", AcDbDimAssoc::AssocFlags::kSecondPointRef)
        .value("kThirdPointRef", AcDbDimAssoc::AssocFlags::kThirdPointRef)
        .value("kFourthPointRef", AcDbDimAssoc::AssocFlags::kFourthPointRef)
        .export_values()
        ;
    enum_<AcDbDimAssoc::RotatedDimType>("RotatedDimType")
        .value("kUnknown", AcDbDimAssoc::RotatedDimType::kUnknown)
        .value("kParallel", AcDbDimAssoc::RotatedDimType::kParallel)
        .value("kPerpendicular", AcDbDimAssoc::RotatedDimType::kPerpendicular)
        .export_values()
        ;
    enum_<AcCm::DialogTabs >("AcCmDialogTabs")
        .value("kACITab", AcCm::DialogTabs::kACITab)
        .value("kTrueColorTab", AcCm::DialogTabs::kTrueColorTab)
        .value("kColorBookTab", AcCm::DialogTabs::kColorBookTab)
        .export_values()
        ;
    enum_<SplineType >("SplineType")
        .value("kFitPoints", SplineType::kFitPoints)
        .value("kControlPoints", SplineType::kControlPoints)
        .export_values()
        ;
    enum_<AcDb::reservedStringEnumType >("ReservedStringEnumType")
        .value("kByLayer", AcDb::reservedStringEnumType::kByLayer)
        .value("kByBlock", AcDb::reservedStringEnumType::kByBlock)
        .value("kNone", AcDb::reservedStringEnumType::kNone)
        .value("kContinuous", AcDb::reservedStringEnumType::kContinuous)
        .value("kStandard", AcDb::reservedStringEnumType::kStandard)
        .value("kNormal", AcDb::reservedStringEnumType::kNormal)
        .value("kDefPoints", AcDb::reservedStringEnumType::kDefPoints)
        .value("kDefault", AcDb::reservedStringEnumType::kDefault)
        .value("kMissing", AcDb::reservedStringEnumType::kMissing)
        .value("kByColor", AcDb::reservedStringEnumType::kByColor)
        .value("kModel", AcDb::reservedStringEnumType::kModel)
        .value("kGlobal", AcDb::reservedStringEnumType::kGlobal)
        .value("kVS2DWireframe", AcDb::reservedStringEnumType::kVS2DWireframe)
        .value("kVS3DWireframe", AcDb::reservedStringEnumType::kVS3DWireframe)
        .value("kVS3DHidden", AcDb::reservedStringEnumType::kVS3DHidden)
        .value("kVSRealistic", AcDb::reservedStringEnumType::kVSRealistic)
        .value("kVSConceptual", AcDb::reservedStringEnumType::kVSConceptual)
        .value("kTitle", AcDb::reservedStringEnumType::kTitle)
        .value("kHeader", AcDb::reservedStringEnumType::kHeader)
        .value("kData", AcDb::reservedStringEnumType::kData)
        .value("kVSShadesOfGray", AcDb::reservedStringEnumType::kVSShadesOfGray)
        .value("kVSSketchy", AcDb::reservedStringEnumType::kVSSketchy)
        .value("kVSXRay", AcDb::reservedStringEnumType::kVSXRay)
        .value("kVSShadedWithEdges", AcDb::reservedStringEnumType::kVSShadedWithEdges)
        .value("kVSShaded", AcDb::reservedStringEnumType::kVSShaded)
        .value("kReservedStringCount", AcDb::reservedStringEnumType::kReservedStringCount)
        .export_values()
        ;
    enum_<AcDb::FilerType>("FilerType")
        .value("kFileFiler", AcDb::FilerType::kFileFiler)
        .value("kCopyFiler", AcDb::FilerType::kCopyFiler)
        .value("kUndoFiler", AcDb::FilerType::kUndoFiler)
        .value("kBagFiler", AcDb::FilerType::kBagFiler)
        .value("kIdXlateFiler", AcDb::FilerType::kIdXlateFiler)
        .value("kPageFiler", AcDb::FilerType::kPageFiler)
        .value("kDeepCloneFiler", AcDb::FilerType::kDeepCloneFiler)
        .value("kIdFiler", AcDb::FilerType::kIdFiler)
        .value("kPurgeFiler", AcDb::FilerType::kPurgeFiler)
        .value("kWblockCloneFiler", AcDb::FilerType::kWblockCloneFiler)
        .export_values()
        ;
    enum_<AcDb::OsnapMode>("OsnapMode")
        .value("kOsModeEnd", AcDb::OsnapMode::kOsModeEnd)
        .value("kOsModeMid", AcDb::OsnapMode::kOsModeMid)
        .value("kOsModeCen", AcDb::OsnapMode::kOsModeCen)
        .value("kOsModeNode", AcDb::OsnapMode::kOsModeNode)
        .value("kOsModeQuad", AcDb::OsnapMode::kOsModeQuad)
        .value("kOsModeIns", AcDb::OsnapMode::kOsModeIns)
        .value("kOsModePerp", AcDb::OsnapMode::kOsModePerp)
        .value("kOsModeTan", AcDb::OsnapMode::kOsModeTan)
        .value("kOsModeNear", AcDb::OsnapMode::kOsModeNear)
        .value("kOsModeCentroid", AcDb::OsnapMode::kOsModeCentroid)
        .export_values()
        ;

    enum_<AcDb::OsnapMask>("OsnapMask")
        .value("kOsMaskEnd", AcDb::OsnapMask::kOsMaskEnd)
        .value("kOsMaskMid", AcDb::OsnapMask::kOsMaskMid)
        .value("kOsMaskCen", AcDb::OsnapMask::kOsMaskCen)
        .value("kOsMaskNode", AcDb::OsnapMask::kOsMaskNode)
        .value("kOsMaskQuad", AcDb::OsnapMask::kOsMaskQuad)
        .value("kOsMaskInt", AcDb::OsnapMask::kOsMaskInt)
        .value("kOsMaskIns", AcDb::OsnapMask::kOsMaskIns)
        .value("kOsMaskPerp", AcDb::OsnapMask::kOsMaskPerp)
        .value("kOsMaskTan", AcDb::OsnapMask::kOsMaskTan)
        .value("kOsMaskNear", AcDb::OsnapMask::kOsMaskNear)
        .value("kOsMaskQuick", AcDb::OsnapMask::kOsMaskQuick)
        .value("kOsMaskCentroid", AcDb::OsnapMask::kOsMaskQuick)
        .value("kOsMaskApint", AcDb::OsnapMask::kOsMaskApint)
        .value("kOsMaskImmediate", AcDb::OsnapMask::kOsMaskImmediate)
        .value("kOsMaskAllowTan", AcDb::OsnapMask::kOsMaskAllowTan)
        .value("kOsMaskDisablePerp", AcDb::OsnapMask::kOsMaskDisablePerp)
        .value("kOsMaskRelCartesian", AcDb::OsnapMask::kOsMaskRelCartesian)
        .value("kOsMaskRelPolar", AcDb::OsnapMask::kOsMaskRelPolar)
        .value("kOsMaskNoneOverride", AcDb::OsnapMask::kOsMaskNoneOverride)
        .export_values()
        ;

    enum_<AcDb::BoolOperType>("BoolOperType")
        .value("kBoolUnite", AcDb::BoolOperType::kBoolUnite)
        .value("kBoolIntersect", AcDb::BoolOperType::kBoolIntersect)
        .value("kBoolSubtract", AcDb::BoolOperType::kBoolSubtract)
        .export_values()
        ;
    enum_<AcDb::SubentType>("SubentType")
        .value("kNullSubentType", AcDb::kNullSubentType)
        .value("kFaceSubentType", AcDb::kFaceSubentType)
        .value("kEdgeSubentType", AcDb::kEdgeSubentType)
        .value("kVertexSubentType", AcDb::kVertexSubentType)
        .value("kMlineSubentCache", AcDb::kMlineSubentCache)
        .value("kClassSubentType", AcDb::kClassSubentType)
        .value("kAxisSubentType", AcDb::kAxisSubentType)
        .value("kSilhouetteSubentType", AcDb::kSilhouetteSubentType)
        .export_values()
        ;
    enum_<AcDb::VpFreezeOps>("VpFreezeOps")
        .value("kFreeze", AcDb::VpFreezeOps::kFreeze)
        .value("kThaw", AcDb::VpFreezeOps::kThaw)
        .value("kReset", AcDb::VpFreezeOps::kReset)
        .export_values()
        ;
    enum_<AcDb::DwgDataType>("DwgDataType")
        .value("kDwgNull", AcDb::DwgDataType::kDwgNull)
        .value("kDwgReal", AcDb::DwgDataType::kDwgReal)
        .value("kDwgInt32", AcDb::DwgDataType::kDwgInt32)
        .value("kDwgInt16", AcDb::DwgDataType::kDwgInt16)
        .value("kDwgInt8", AcDb::DwgDataType::kDwgInt8)
        .value("kDwgText", AcDb::DwgDataType::kDwgText)
        .value("kDwgBChunk", AcDb::DwgDataType::kDwgBChunk)
        .value("kDwgHandle", AcDb::DwgDataType::kDwgHandle)
        .value("kDwgHardOwnershipId", AcDb::DwgDataType::kDwgHardOwnershipId)
        .value("kDwgSoftOwnershipId", AcDb::DwgDataType::kDwgSoftOwnershipId)
        .value("kDwgHardPointerId", AcDb::DwgDataType::kDwgHardPointerId)
        .value("kDwgSoftPointerId", AcDb::DwgDataType::kDwgSoftPointerId)
        .value("kDwg3Real", AcDb::DwgDataType::kDwg3Real)
        .value("kDwgInt64", AcDb::DwgDataType::kDwgInt64)
        .value("kDwgNotRecognized", AcDb::DwgDataType::kDwgNotRecognized)
        .export_values()
        ;
    enum_<AcValue::DataType>("ValueDataType")
        .value("kUnknown", AcValue::DataType::kUnknown)
        .value("kLong", AcValue::DataType::kLong)
        .value("kDouble", AcValue::DataType::kDouble)
        .value("kString", AcValue::DataType::kString)
        .value("kDate", AcValue::DataType::kDate)
        .value("kPoint", AcValue::DataType::kPoint)
        .value("k3dPoint", AcValue::DataType::k3dPoint)
        .value("kObjectId", AcValue::DataType::kObjectId)
        .value("kBuffer", AcValue::DataType::kBuffer)
        .value("kResbuf", AcValue::DataType::kResbuf)
        .value("kGeneral", AcValue::DataType::kGeneral)
        .value("kColor", AcValue::DataType::kColor)
        .export_values()
        ;
    enum_<AcValue::ParseOption>("ValueParseOption")
        .value("kParseOptionNone", AcValue::ParseOption::kParseOptionNone)
        .value("kSetDefaultFormat", AcValue::ParseOption::kSetDefaultFormat)
        .value("kPreserveMtextFormat", AcValue::ParseOption::kPreserveMtextFormat)
        .value("kConvertTextToValue", AcValue::ParseOption::kConvertTextToValue)
        .value("kChangeDataType", AcValue::ParseOption::kChangeDataType)
        .value("kParseTextForFieldCode", AcValue::ParseOption::kParseTextForFieldCode)
        .export_values()
        ;
    enum_<AcValue::FormatOption>("ValueFormatOption")
        .value("kFormatOptionNone", AcValue::FormatOption::kFormatOptionNone)
        .value("kForEditing", AcValue::FormatOption::kForEditing)
        .value("kForExpression", AcValue::FormatOption::kForExpression)
        .value("kUseMaximumPrecision", AcValue::FormatOption::kUseMaximumPrecision)
        .value("kIgnoreMtextFormat", AcValue::FormatOption::kIgnoreMtextFormat)
        .export_values()
        ;
    enum_<AcValue::UnitType>("ValueUnitType")
        .value("kUnitless", AcValue::UnitType::kUnitless)
        .value("kDistance", AcValue::UnitType::kDistance)
        .value("kAngle", AcValue::UnitType::kAngle)
        .value("kArea", AcValue::UnitType::kArea)
        .value("kVolume", AcValue::UnitType::kVolume)
        .value("kCurrency", AcValue::UnitType::kCurrency)
        .value("kPercentage", AcValue::UnitType::kPercentage)
        .value("kAngleNotTransformed", AcValue::UnitType::kAngleNotTransformed)
        .export_values()
        ;

    enum_<AcDb::Intersect>("Intersect")
        .value("kOnBothOperands", AcDb::Intersect::kOnBothOperands)
        .value("kExtendThis", AcDb::Intersect::kExtendThis)
        .value("kExtendArg", AcDb::Intersect::kExtendArg)
        .value("kExtendBoth", AcDb::Intersect::kExtendBoth)
        .export_values()
        ;
    enum_<AcDb::LineSpacingStyle>("LineSpacingStyle")
        .value("kAtLeast", AcDb::LineSpacingStyle::kAtLeast)
        .value("kExactly", AcDb::LineSpacingStyle::kExactly)
        .export_values()
        ;
    enum_<AcDb::Poly3dType>("Poly3dType")
        .value("k3dSimplePoly", AcDb::Poly3dType::k3dSimplePoly)
        .value("k3dQuadSplinePoly", AcDb::Poly3dType::k3dQuadSplinePoly)
        .value("k3dCubicSplinePoly", AcDb::Poly3dType::k3dCubicSplinePoly)
        .export_values()
        ;
    enum_<AcDb::Poly2dType>("Poly2dType")
        .value("k2dSimplePoly", AcDb::Poly2dType::k2dSimplePoly)
        .value("k2dFitCurvePoly", AcDb::Poly2dType::k2dFitCurvePoly)
        .value("k2dQuadSplinePoly", AcDb::Poly2dType::k2dQuadSplinePoly)
        .value("k2dCubicSplinePoly", AcDb::Poly2dType::k2dCubicSplinePoly)
        .export_values()
        ;
    enum_<AcDb::Vertex2dType>("Vertex2dType")//leave the k
        .value("k2dVertex", AcDb::Vertex2dType::k2dVertex)
        .value("k2dSplineCtlVertex", AcDb::Vertex2dType::k2dSplineCtlVertex)
        .value("k2dSplineFitVertex", AcDb::Vertex2dType::k2dSplineFitVertex)
        .value("k2dCurveFitVertex", AcDb::Vertex2dType::k2dCurveFitVertex)
        .export_values()
        ;
    enum_<AcDb::TextVertMode>("TextVertMode")
        .value("kTextBase", AcDb::TextVertMode::kTextBase)
        .value("kTextBottom", AcDb::TextVertMode::kTextBottom)
        .value("kTextVertMid", AcDb::TextVertMode::kTextVertMid)
        .value("kTextTop", AcDb::TextVertMode::kTextTop)
        .export_values()
        ;
    enum_<AcDb::TextHorzMode>("TextHorzMode")
        .value("kTextLeft", AcDb::TextHorzMode::kTextLeft)
        .value("kTextCenter", AcDb::TextHorzMode::kTextCenter)
        .value("kTextRight", AcDb::TextHorzMode::kTextRight)
        .value("kTextAlign", AcDb::TextHorzMode::kTextAlign)
        .value("kTextMid", AcDb::TextHorzMode::kTextMid)
        .value("kTextFit", AcDb::TextHorzMode::kTextFit)
        .export_values()
        ;
    enum_<AcDbBlockTableRecord::BlockScaling>("BlockScaling")
        .value("kAny", AcDbBlockTableRecord::BlockScaling::kAny)
        .value("kUniform", AcDbBlockTableRecord::BlockScaling::kUniform)
        .export_values()
        ;
    enum_<AcDb::XrefStatus>("XrefStatus")
        .value("kXrfNotAnXref", AcDb::XrefStatus::kXrfNotAnXref)
        .value("kXrfResolved", AcDb::XrefStatus::kXrfResolved)
        .value("kXrfUnloaded", AcDb::XrefStatus::kXrfUnloaded)
        .value("kXrfUnreferenced", AcDb::XrefStatus::kXrfUnreferenced)
        .value("kXrfFileNotFound", AcDb::XrefStatus::kXrfFileNotFound)
        .value("kXrfUnresolved", AcDb::XrefStatus::kXrfUnresolved)
        .export_values()
        ;
    enum_<AcDb::Planarity>("Planarity")
        .value("kNonPlanar", AcDb::Planarity::kNonPlanar)
        .value("kPlanar", AcDb::Planarity::kPlanar)
        .value("kLinear", AcDb::Planarity::kLinear)
        .export_values()
        ;
    enum_<AcDb::CollisionType>("CollisionType")
        .value("kCollisionTypeNone", AcDb::CollisionType::kCollisionTypeNone)
        .value("kCollisionTypeSolid", AcDb::CollisionType::kCollisionTypeSolid)
        .export_values()
        ;
    enum_<AcDb::Visibility>("Visibility")
        .value("kVisible", AcDb::Visibility::kVisible)
        .value("kInvisible", AcDb::Visibility::kInvisible)
        .export_values()
        ;
    enum_<AcDb::DxfCode>("DxfCode")
        .value("kDxfInvalid", AcDb::kDxfInvalid)
        .value("kDxfXDictionary", AcDb::kDxfXDictionary)
        .value("kDxfPReactors", AcDb::kDxfPReactors)
        .value("kDxfOperator", AcDb::kDxfOperator)
        .value("kDxfXDataStart", AcDb::kDxfXDataStart)
        .value("kDxfHeaderId", AcDb::kDxfHeaderId)
        .value("kDxfFirstEntId", AcDb::kDxfFirstEntId)
        .value("kDxfEnd", AcDb::kDxfEnd)
        .value("kDxfStart", AcDb::kDxfStart)
        .value("kDxfText", AcDb::kDxfText)
        .value("kDxfXRefPath", AcDb::kDxfXRefPath)
        .value("kDxfShapeName", AcDb::kDxfShapeName)
        .value("kDxfBlockName", AcDb::kDxfBlockName)
        .value("kDxfAttributeTag", AcDb::kDxfAttributeTag)
        .value("kDxfSymbolTableName", AcDb::kDxfSymbolTableName)
        .value("kDxfMstyleName", AcDb::kDxfMstyleName)
        .value("kDxfSymTableRecName", AcDb::kDxfSymTableRecName)
        .value("kDxfAttributePrompt", AcDb::kDxfAttributePrompt)
        .value("kDxfDimStyleName", AcDb::kDxfDimStyleName)
        .value("kDxfLinetypeProse", AcDb::kDxfLinetypeProse)
        .value("kDxfTextFontFile", AcDb::kDxfTextFontFile)
        .value("kDxfDescription", AcDb::kDxfDescription)
        .value("kDxfDimPostStr", AcDb::kDxfDimPostStr)
        .value("kDxfTextBigFontFile", AcDb::kDxfTextBigFontFile)
        .value("kDxfDimAPostStr", AcDb::kDxfDimAPostStr)
        .value("kDxfCLShapeName", AcDb::kDxfCLShapeName)
        .value("kDxfSymTableRecComments", AcDb::kDxfSymTableRecComments)
        .value("kDxfHandle", AcDb::kDxfHandle)
        .value("kDxfDimBlk", AcDb::kDxfDimBlk)
        .value("kDxfDimBlk1", AcDb::kDxfDimBlk1)
        .value("kDxfLinetypeName", AcDb::kDxfLinetypeName)
        .value("kDxfDimBlk2", AcDb::kDxfDimBlk2)
        .value("kDxfTextStyleName", AcDb::kDxfTextStyleName)
        .value("kDxfLayerName", AcDb::kDxfLayerName)
        .value("kDxfCLShapeText", AcDb::kDxfCLShapeText)
        .value("kDxfXCoord", AcDb::kDxfXCoord)
        .value("kDxfYCoord", AcDb::kDxfYCoord)
        .value("kDxfZCoord", AcDb::kDxfZCoord)
        .value("kDxfElevation", AcDb::kDxfElevation)
        .value("kDxfThickness", AcDb::kDxfThickness)
        .value("kDxfReal", AcDb::kDxfReal)
        .value("kDxfViewportHeight", AcDb::kDxfViewportHeight)
        .value("kDxfTxtSize", AcDb::kDxfTxtSize)
        .value("kDxfTxtStyleXScale", AcDb::kDxfTxtStyleXScale)
        .value("kDxfViewWidth", AcDb::kDxfViewWidth)
        .value("kDxfViewportAspect", AcDb::kDxfViewportAspect)
        .value("kDxfTxtStylePSize", AcDb::kDxfTxtStylePSize)
        .value("kDxfViewLensLength", AcDb::kDxfViewLensLength)
        .value("kDxfViewFrontClip", AcDb::kDxfViewFrontClip)
        .value("kDxfViewBackClip", AcDb::kDxfViewBackClip)
        .value("kDxfShapeXOffset", AcDb::kDxfShapeXOffset)
        .value("kDxfShapeYOffset", AcDb::kDxfShapeYOffset)
        .value("kDxfViewHeight", AcDb::kDxfViewHeight)
        .value("kDxfShapeScale", AcDb::kDxfShapeScale)
        .value("kDxfPixelScale", AcDb::kDxfPixelScale)
        .value("kDxfLinetypeScale", AcDb::kDxfLinetypeScale)
        .value("kDxfDashLength", AcDb::kDxfDashLength)
        .value("kDxfMlineOffset", AcDb::kDxfMlineOffset)
        .value("kDxfLinetypeElement", AcDb::kDxfLinetypeElement)
        .value("kDxfAngle", AcDb::kDxfAngle)
        .value("kDxfViewportSnapAngle", AcDb::kDxfViewportSnapAngle)
        .value("kDxfViewportTwist", AcDb::kDxfViewportTwist)
        .value("kDxfVisibility", AcDb::kDxfVisibility)
        .value("kDxfViewportGridDisplay", AcDb::kDxfViewportGridDisplay)
        .value("kDxfLayerLinetype", AcDb::kDxfLayerLinetype)
        .value("kDxfViewportGridMajor", AcDb::kDxfViewportGridMajor)
        .value("kDxfColor", AcDb::kDxfColor)
        .value("kDxfHasSubentities", AcDb::kDxfHasSubentities)
        .value("kDxfViewportVisibility", AcDb::kDxfViewportVisibility)
        .value("kDxfViewportActive", AcDb::kDxfViewportActive)
        .value("kDxfViewportNumber", AcDb::kDxfViewportNumber)
        .value("kDxfInt16", AcDb::kDxfInt16)
        .value("kDxfViewMode", AcDb::kDxfViewMode)
        .value("kDxfCircleSides", AcDb::kDxfCircleSides)
        .value("kDxfViewportZoom", AcDb::kDxfViewportZoom)
        .value("kDxfViewportIcon", AcDb::kDxfViewportIcon)
        .value("kDxfViewportSnap", AcDb::kDxfViewportSnap)
        .value("kDxfViewportGrid", AcDb::kDxfViewportGrid)
        .value("kDxfViewportSnapStyle", AcDb::kDxfViewportSnapStyle)
        .value("kDxfViewportSnapPair", AcDb::kDxfViewportSnapPair)
        .value("kDxfRegAppFlags", AcDb::kDxfRegAppFlags)
        .value("kDxfTxtStyleFlags", AcDb::kDxfTxtStyleFlags)
        .value("kDxfLinetypeAlign", AcDb::kDxfLinetypeAlign)
        .value("kDxfLinetypePDC", AcDb::kDxfLinetypePDC)
        .value("kDxfInt32", AcDb::kDxfInt32)
#if !defined (_BRXTARGET250)
        .value("kDxfVertexIdentifier", AcDb::kDxfVertexIdentifier)
#endif
        .value("kDxfSubclass", AcDb::kDxfSubclass)
        .value("kDxfEmbeddedObjectStart", AcDb::kDxfEmbeddedObjectStart)
        .value("kDxfControlString", AcDb::kDxfControlString)
        .value("kDxfDimVarHandle", AcDb::kDxfDimVarHandle)
        .value("kDxfUCSOrg", AcDb::kDxfUCSOrg)
        .value("kDxfUCSOriX", AcDb::kDxfUCSOriX)
        .value("kDxfUCSOriY", AcDb::kDxfUCSOriY)
        .value("kDxfXReal", AcDb::kDxfXReal)
        .value("kDxfViewBrightness", AcDb::kDxfViewBrightness)
        .value("kDxfViewContrast", AcDb::kDxfViewContrast)
        .value("kDxfInt64", AcDb::kDxfInt64)
        .value("kDxfXInt16", AcDb::kDxfXInt16)
        .value("kDxfNormalX", AcDb::kDxfNormalX)
        .value("kDxfNormalY", AcDb::kDxfNormalY)
        .value("kDxfNormalZ", AcDb::kDxfNormalZ)
        .value("kDxfXXInt16", AcDb::kDxfXXInt16)
        .value("kDxfInt8", AcDb::kDxfInt8)
        .value("kDxfRenderMode", AcDb::kDxfRenderMode)
        .value("kDxfDefaultLightingType", AcDb::kDxfDefaultLightingType)
        .value("kDxfShadowFlags", AcDb::kDxfShadowFlags)
        .value("kDxfBool", AcDb::kDxfBool)
        .value("kDxfDefaultLightingOn", AcDb::kDxfDefaultLightingOn)
        .value("kDxfXTextString", AcDb::kDxfXTextString)
        .value("kDxfBinaryChunk", AcDb::kDxfBinaryChunk)
        .value("kDxfArbHandle", AcDb::kDxfArbHandle)
        .value("kDxfSoftPointerId", AcDb::kDxfSoftPointerId)
        .value("kDxfViewBackgroundId", AcDb::kDxfViewBackgroundId)
        .value("kDxfShadePlotId", AcDb::kDxfShadePlotId)
        .value("kDxfLiveSectionId", AcDb::kDxfLiveSectionId)
        .value("kDxfLiveSectionName", AcDb::kDxfLiveSectionName)
        .value("kDxfHardPointerId", AcDb::kDxfHardPointerId)
        .value("kDxfObjVisualStyleId", AcDb::kDxfObjVisualStyleId)
        .value("kDxfVpVisualStyleId", AcDb::kDxfVpVisualStyleId)
        .value("kDxfMaterialId", AcDb::kDxfMaterialId)
        .value("kDxfVisualStyleId", AcDb::kDxfVisualStyleId)
        .value("kDxfDragVisualStyleId", AcDb::kDxfDragVisualStyleId)
        .value("kDxfSoftOwnershipId", AcDb::kDxfSoftOwnershipId)
        .value("kDxfHardOwnershipId", AcDb::kDxfHardOwnershipId)
        .value("kDxfSunId", AcDb::kDxfSunId)
        .value("kDxfLineWeight", AcDb::kDxfLineWeight)
        .value("kDxfPlotStyleNameType", AcDb::kDxfPlotStyleNameType)
        .value("kDxfPlotStyleNameId", AcDb::kDxfPlotStyleNameId)
        .value("kDxfXXXInt16", AcDb::kDxfXXXInt16)
        .value("kDxfLayoutName", AcDb::kDxfLayoutName)
        .value("kDxfColorRGB", AcDb::kDxfColorRGB)
        .value("kDxfColorName", AcDb::kDxfColorName)
        .value("kDxfAlpha", AcDb::kDxfAlpha)
        .value("kDxfGradientObjType", AcDb::kDxfGradientObjType)
        .value("kDxfGradientPatType", AcDb::kDxfGradientPatType)
        .value("kDxfGradientTintType", AcDb::kDxfGradientTintType)
        .value("kDxfGradientColCount", AcDb::kDxfGradientColCount)
        .value("kDxfGradientAngle", AcDb::kDxfGradientAngle)
        .value("kDxfGradientShift", AcDb::kDxfGradientShift)
        .value("kDxfGradientTintVal", AcDb::kDxfGradientTintVal)
        .value("kDxfGradientColVal", AcDb::kDxfGradientColVal)
        .value("kDxfGradientName", AcDb::kDxfGradientName)
#if !defined (_BRXTARGET250)
        .value("kDxfFaceStyleId", AcDb::kDxfFaceStyleId)
        .value("kDxfEdgeStyleId", AcDb::kDxfEdgeStyleId)
#endif
        .value("kDxfComment", AcDb::kDxfComment)
        .value("kDxfXdAsciiString", AcDb::kDxfXdAsciiString)
        .value("kDxfRegAppName", AcDb::kDxfRegAppName)
        .value("kDxfXdControlString", AcDb::kDxfXdControlString)
        .value("kDxfXdLayerName", AcDb::kDxfXdLayerName)
        .value("kDxfXdBinaryChunk", AcDb::kDxfXdBinaryChunk)
        .value("kDxfXdHandle", AcDb::kDxfXdHandle)
        .value("kDxfXdXCoord", AcDb::kDxfXdXCoord)
        .value("kDxfXdYCoord", AcDb::kDxfXdYCoord)
        .value("kDxfXdZCoord", AcDb::kDxfXdZCoord)
        .value("kDxfXdWorldXCoord", AcDb::kDxfXdWorldXCoord)
        .value("kDxfXdWorldYCoord", AcDb::kDxfXdWorldYCoord)
        .value("kDxfXdWorldZCoord", AcDb::kDxfXdWorldZCoord)
        .value("kDxfXdWorldXDisp", AcDb::kDxfXdWorldXDisp)
        .value("kDxfXdWorldYDisp", AcDb::kDxfXdWorldYDisp)
        .value("kDxfXdWorldZDisp", AcDb::kDxfXdWorldZDisp)
        .value("kDxfXdWorldXDir", AcDb::kDxfXdWorldXDir)
        .value("kDxfXdWorldYDir", AcDb::kDxfXdWorldYDir)
        .value("kDxfXdWorldZDir", AcDb::kDxfXdWorldZDir)
        .value("kDxfXdReal", AcDb::kDxfXdReal)
        .value("kDxfXdDist", AcDb::kDxfXdDist)
        .value("kDxfXdScale", AcDb::kDxfXdScale)
        .value("kDxfXdInteger16", AcDb::kDxfXdInteger16)
        .value("kDxfXdInteger32", AcDb::kDxfXdInteger32)
#if !defined (_BRXTARGET250)
        .value("kDxfXdMax", AcDb::kDxfXdMax)
#endif
        .export_values()
        ;
    enum_<AcDb::OpenMode>("OpenMode")
        .value("ForRead", AcDb::OpenMode::kForRead)
        .value("ForWrite", AcDb::OpenMode::kForWrite)
        .value("ForNotify", AcDb::OpenMode::kForNotify)
        .value("kForRead", AcDb::OpenMode::kForRead)
        .value("kForWrite", AcDb::OpenMode::kForWrite)
        .value("kForNotify", AcDb::OpenMode::kForNotify)
        .export_values()
        ;
    enum_<AcDb::LineWeight>("LineWeight")
        .value("kLnWt000", AcDb::LineWeight::kLnWt000)
        .value("kLnWt005", AcDb::LineWeight::kLnWt005)
        .value("kLnWt009", AcDb::LineWeight::kLnWt009)
        .value("kLnWt013", AcDb::LineWeight::kLnWt013)
        .value("kLnWt015", AcDb::LineWeight::kLnWt015)
        .value("kLnWt018", AcDb::LineWeight::kLnWt018)
        .value("kLnWt020", AcDb::LineWeight::kLnWt020)
        .value("kLnWt025", AcDb::LineWeight::kLnWt025)
        .value("kLnWt030", AcDb::LineWeight::kLnWt030)
        .value("kLnWt035", AcDb::LineWeight::kLnWt035)
        .value("kLnWt040", AcDb::LineWeight::kLnWt040)
        .value("kLnWt050", AcDb::LineWeight::kLnWt050)
        .value("kLnWt053", AcDb::LineWeight::kLnWt053)
        .value("kLnWt060", AcDb::LineWeight::kLnWt060)
        .value("kLnWt070", AcDb::LineWeight::kLnWt070)
        .value("kLnWt080", AcDb::LineWeight::kLnWt080)
        .value("kLnWt090", AcDb::LineWeight::kLnWt090)
        .value("kLnWt100", AcDb::LineWeight::kLnWt100)
        .value("kLnWt106", AcDb::LineWeight::kLnWt106)
        .value("kLnWt120", AcDb::LineWeight::kLnWt120)
        .value("kLnWt140", AcDb::LineWeight::kLnWt140)
        .value("kLnWt158", AcDb::LineWeight::kLnWt158)
        .value("kLnWt200", AcDb::LineWeight::kLnWt200)
        .value("kLnWt211", AcDb::LineWeight::kLnWt211)
        .value("kLnWtByLayer", AcDb::LineWeight::kLnWtByLayer)
        .value("kLnWtByBlock", AcDb::LineWeight::kLnWtByBlock)
        .value("kLnWtByLwDefault", AcDb::LineWeight::kLnWtByLwDefault)
        .export_values()
        ;
    enum_<AcDb::PlotStyleNameType>("PlotStyleNameType")
        .value("kPlotStyleNameByLayer", AcDb::PlotStyleNameType::kPlotStyleNameByLayer)
        .value("kPlotStyleNameByBlock", AcDb::PlotStyleNameType::kPlotStyleNameByBlock)
        .value("kPlotStyleNameIsDictDefault", AcDb::PlotStyleNameType::kPlotStyleNameIsDictDefault)
        .value("kPlotStyleNameById", AcDb::PlotStyleNameType::kPlotStyleNameById)
        .export_values()
        ;
    enum_<AcDb::EndCaps>("EndCaps")
        .value("kEndCapNone", AcDb::EndCaps::kEndCapNone)
        .value("kEndCapRound", AcDb::EndCaps::kEndCapRound)
        .value("kEndCapAngle", AcDb::EndCaps::kEndCapAngle)
        .value("kEndCapSquare", AcDb::EndCaps::kEndCapSquare)
        .export_values()
        ;
    enum_<AcDb::UnitsValue>("UnitsValue")
        .value("kUnitsUndefined", AcDb::UnitsValue::kUnitsUndefined)
        .value("kUnitsInches", AcDb::UnitsValue::kUnitsInches)
        .value("kUnitsFeet", AcDb::UnitsValue::kUnitsFeet)
        .value("kUnitsMiles", AcDb::UnitsValue::kUnitsMiles)
        .value("kUnitsMillimeters", AcDb::UnitsValue::kUnitsMillimeters)
        .value("kUnitsCentimeters", AcDb::UnitsValue::kUnitsCentimeters)
        .value("kUnitsMeters", AcDb::UnitsValue::kUnitsMeters)
        .value("kUnitsKilometers", AcDb::UnitsValue::kUnitsKilometers)
        .value("kUnitsMicroinches", AcDb::UnitsValue::kUnitsMicroinches)
        .value("kUnitsMils", AcDb::UnitsValue::kUnitsMils)
        .value("kUnitsYards", AcDb::UnitsValue::kUnitsYards)
        .value("kUnitsAngstroms", AcDb::UnitsValue::kUnitsAngstroms)
        .value("kUnitsNanometers", AcDb::UnitsValue::kUnitsNanometers)
        .value("kUnitsMicrons", AcDb::UnitsValue::kUnitsMicrons)
        .value("kUnitsDecimeters", AcDb::UnitsValue::kUnitsDecimeters)
        .value("kUnitsDekameters", AcDb::UnitsValue::kUnitsDekameters)
        .value("kUnitsHectometers", AcDb::UnitsValue::kUnitsHectometers)
        .value("kUnitsGigameters", AcDb::UnitsValue::kUnitsGigameters)
        .value("kUnitsAstronomical", AcDb::UnitsValue::kUnitsAstronomical)
        .value("kUnitsLightYears", AcDb::UnitsValue::kUnitsLightYears)
        .value("kUnitsParsecs", AcDb::UnitsValue::kUnitsParsecs)
        .value("kUnitsUSSurveyFeet", AcDb::UnitsValue::kUnitsUSSurveyFeet)
        .value("kUnitsUSSurveyInch", AcDb::UnitsValue::kUnitsUSSurveyInch)
        .value("kUnitsUSSurveyYard", AcDb::UnitsValue::kUnitsUSSurveyYard)
        .value("kUnitsUSSurveyMile", AcDb::UnitsValue::kUnitsUSSurveyMile)
        .value("kUnitsMax", AcDb::UnitsValue::kUnitsMax)
        .export_values()
        ;
    enum_<AcDb::JoinStyle>("JoinStyle")
        .value("kJnStylNone", AcDb::JoinStyle::kJnStylNone)
        .value("kJnStylRound", AcDb::JoinStyle::kJnStylRound)
        .value("kJnStylAngle", AcDb::JoinStyle::kJnStylAngle)
        .value("kJnStylFlat", AcDb::JoinStyle::kJnStylFlat)
        .export_values()
        ;
    enum_<AcDb::MeasurementValue>("MeasurementValue")
        .value("kEnglish", AcDb::MeasurementValue::kEnglish)
        .value("kMetric", AcDb::MeasurementValue::kMetric)
        .export_values()
        ;
    enum_<AcDb::UpdateOption>("UpdateOption")
        .value("kUpdateOptionNone", AcDb::UpdateOption::kUpdateOptionNone)
        .value("kUpdateOptionSkipFormat", AcDb::UpdateOption::kUpdateOptionSkipFormat)
        .value("kUpdateOptionUpdateRowHeight", AcDb::UpdateOption::kUpdateOptionUpdateRowHeight)
        .value("kUpdateOptionUpdateColumnWidth", AcDb::UpdateOption::kUpdateOptionUpdateColumnWidth)
        .value("kUpdateOptionAllowSourceUpdate", AcDb::UpdateOption::kUpdateOptionAllowSourceUpdate)
        .value("kUpdateOptionForceFullSourceUpdate", AcDb::UpdateOption::kUpdateOptionForceFullSourceUpdate)
        .value("kUpdateOptionOverwriteContentModifiedAfterUpdate", AcDb::UpdateOption::kUpdateOptionOverwriteContentModifiedAfterUpdate)
        .value("kUpdateOptionOverwriteFormatModifiedAfterUpdate", AcDb::UpdateOption::kUpdateOptionOverwriteFormatModifiedAfterUpdate)
        .value("kUpdateOptionForPreview", AcDb::UpdateOption::kUpdateOptionForPreview)
        .value("kUpdateOptionIncludeXrefs", AcDb::UpdateOption::kUpdateOptionIncludeXrefs)
        .value("kSkipFormatAfterFirstUpdate", AcDb::UpdateOption::kSkipFormatAfterFirstUpdate)
        .export_values()
        ;
    enum_<AcDb::UpdateDirection>("UpdateDirection")
        .value("kUpdateDirSourceToData", AcDb::UpdateDirection::kUpdateDirSourceToData)
        .value("kUpdateDirDataToSource", AcDb::UpdateDirection::kUpdateDirDataToSource)
        .export_values()
        ;
    enum_<AcDb::DuplicateRecordCloning>("DuplicateRecordCloning")
        .value("kDrcNotApplicable", AcDb::DuplicateRecordCloning::kDrcNotApplicable)
        .value("kDrcIgnore", AcDb::DuplicateRecordCloning::kDrcIgnore)
        .value("kDrcReplace", AcDb::DuplicateRecordCloning::kDrcReplace)
        .value("kDrcXrefMangleName", AcDb::DuplicateRecordCloning::kDrcXrefMangleName)
        .value("kDrcMangleName", AcDb::DuplicateRecordCloning::kDrcMangleName)
        .value("kDrcUnmangleName", AcDb::DuplicateRecordCloning::kDrcUnmangleName)
        .export_values()
        ;
    enum_<AcDbDatabase::OpenMode>("DatabaseOpenMode")
        .value("kForReadAndReadShare", AcDbDatabase::OpenMode::kForReadAndReadShare)
        .value("kForReadAndWriteNoShare", AcDbDatabase::OpenMode::kForReadAndWriteNoShare)
        .value("kForReadAndAllShare", AcDbDatabase::OpenMode::kForReadAndAllShare)
        .value("kTryForReadShare", AcDbDatabase::OpenMode::kTryForReadShare)
        .export_values()
        ;
    enum_<AcDb::DeepCloneType>("DeepCloneType")
        .value("kDcCopy", AcDb::DeepCloneType::kDcCopy)
        .value("kDcExplode", AcDb::DeepCloneType::kDcExplode)
        .value("kDcBlock", AcDb::DeepCloneType::kDcBlock)
        .value("kDcXrefBind", AcDb::DeepCloneType::kDcXrefBind)
        .value("kDcSymTableMerge", AcDb::DeepCloneType::kDcSymTableMerge)
        .value("kDcInsert", AcDb::DeepCloneType::kDcInsert)
        .value("kDcWblock", AcDb::DeepCloneType::kDcWblock)
        .value("kDcObjects", AcDb::DeepCloneType::kDcObjects)
        .value("kDcXrefInsert", AcDb::DeepCloneType::kDcXrefInsert)
        .value("kDcInsertCopy", AcDb::DeepCloneType::kDcInsertCopy)
        .value("kDcWblkObjects", AcDb::DeepCloneType::kDcWblkObjects)
        .export_values()
        ;
    enum_<AcDb::OrthographicView>("OrthographicView")
        .value("kNonOrthoView", AcDb::OrthographicView::kNonOrthoView)
        .value("kTopView", AcDb::OrthographicView::kTopView)
        .value("kBottomView", AcDb::OrthographicView::kBottomView)
        .value("kFrontView", AcDb::OrthographicView::kFrontView)
        .value("kBackView", AcDb::OrthographicView::kBackView)
        .value("kLeftView", AcDb::OrthographicView::kLeftView)
        .value("kRightView", AcDb::OrthographicView::kRightView)
        .export_values()
        ;
    enum_<AcDb::TimeZone>("TimeZone")
        .value("kInternationalDateLine", AcDb::TimeZone::kInternationalDateLine)
        .value("kMidwayIsland", AcDb::TimeZone::kMidwayIsland)
        .value("kHawaii", AcDb::TimeZone::kHawaii)
        .value("kAlaska", AcDb::TimeZone::kAlaska)
        .value("kPacific", AcDb::TimeZone::kPacific)
        .value("kMountain", AcDb::TimeZone::kMountain)
        .value("kArizona", AcDb::TimeZone::kArizona)
        .value("kMazatlan", AcDb::TimeZone::kMazatlan)
        .value("kCentral", AcDb::TimeZone::kCentral)
        .value("kCentralAmerica", AcDb::TimeZone::kCentralAmerica)
        .value("kMexicoCity", AcDb::TimeZone::kMexicoCity)
        .value("kSaskatchewan", AcDb::TimeZone::kSaskatchewan)
        .value("kEastern", AcDb::TimeZone::kEastern)
        .value("kIndiana", AcDb::TimeZone::kIndiana)
        .value("kBogota", AcDb::TimeZone::kBogota)
        .value("kAtlanticCanada", AcDb::TimeZone::kAtlanticCanada)
        .value("kCaracas", AcDb::TimeZone::kCaracas)
        .value("kSantiago", AcDb::TimeZone::kSantiago)
        .value("kNewfoundland", AcDb::TimeZone::kNewfoundland)
        .value("kBrasilia", AcDb::TimeZone::kBrasilia)
        .value("kBuenosAires", AcDb::TimeZone::kBuenosAires)
        .value("kGreenland", AcDb::TimeZone::kGreenland)
        .value("kMidAtlantic", AcDb::TimeZone::kMidAtlantic)
        .value("kAzores", AcDb::TimeZone::kAzores)
        .value("kCapeVerde", AcDb::TimeZone::kCapeVerde)
        .value("kUTC", AcDb::TimeZone::kUTC)
        .value("kGMT", AcDb::TimeZone::kGMT)
        .value("kMonrovia", AcDb::TimeZone::kMonrovia)
        .value("kBerlin", AcDb::TimeZone::kBerlin)
        .value("kParis", AcDb::TimeZone::kParis)
        .value("kPrague", AcDb::TimeZone::kPrague)
        .value("kSarajevo", AcDb::TimeZone::kSarajevo)
        .value("kWestCentralAfrica", AcDb::TimeZone::kWestCentralAfrica)
        .value("kAthens", AcDb::TimeZone::kAthens)
        .value("kEasternEurope", AcDb::TimeZone::kEasternEurope)
        .value("kCairo", AcDb::TimeZone::kCairo)
        .value("kHarare", AcDb::TimeZone::kHarare)
        .value("kHelsinki", AcDb::TimeZone::kHelsinki)
        .value("kJerusalem", AcDb::TimeZone::kJerusalem)
        .value("kMoscow", AcDb::TimeZone::kMoscow)
        .value("kRiyadh", AcDb::TimeZone::kRiyadh)
        .value("kBaghdad", AcDb::TimeZone::kBaghdad)
        .value("kEastAfrica", AcDb::TimeZone::kEastAfrica)
        .value("kTehran", AcDb::TimeZone::kTehran)
        .value("kAbuDhabi", AcDb::TimeZone::kAbuDhabi)
        .value("kCaucasus", AcDb::TimeZone::kCaucasus)
        .value("kKabul", AcDb::TimeZone::kKabul)
        .value("kEkaterinburg", AcDb::TimeZone::kEkaterinburg)
        .value("kIslamabad", AcDb::TimeZone::kIslamabad)
        .value("kKolkata", AcDb::TimeZone::kKolkata)
        .value("kKathmandu", AcDb::TimeZone::kKathmandu)
        .value("kAlmaty", AcDb::TimeZone::kAlmaty)
        .value("kDhaka", AcDb::TimeZone::kDhaka)
        .value("kSriLanka", AcDb::TimeZone::kSriLanka)
        .value("kRangoon", AcDb::TimeZone::kRangoon)
        .value("kBangkok", AcDb::TimeZone::kBangkok)
        .value("kKrasnoyarsk", AcDb::TimeZone::kKrasnoyarsk)
        .value("kBeijing", AcDb::TimeZone::kBeijing)
        .value("kSingapore", AcDb::TimeZone::kSingapore)
        .value("kTaipei", AcDb::TimeZone::kTaipei)
        .value("kIrkutsk", AcDb::TimeZone::kIrkutsk)
        .value("kPerth", AcDb::TimeZone::kPerth)
        .value("kTokyo", AcDb::TimeZone::kTokyo)
        .value("kSeoul", AcDb::TimeZone::kSeoul)
        .value("kYakutsk", AcDb::TimeZone::kYakutsk)
        .value("kAdelaide", AcDb::TimeZone::kAdelaide)
        .value("kDarwin", AcDb::TimeZone::kDarwin)
        .value("kSydney", AcDb::TimeZone::kSydney)
        .value("kGuam", AcDb::TimeZone::kGuam)
        .value("kBrisbane", AcDb::TimeZone::kBrisbane)
        .value("kHobart", AcDb::TimeZone::kHobart)
        .value("kVladivostock", AcDb::TimeZone::kVladivostock)
        .value("kMagadan", AcDb::TimeZone::kMagadan)
        .value("kWellington", AcDb::TimeZone::kWellington)
        .value("kFiji", AcDb::TimeZone::kFiji)
        .value("kTonga", AcDb::TimeZone::kTonga)
        .export_values()
        ;
    enum_<Acad::ErrorStatus>("ErrorStatus")
        .value("Ok", Acad::ErrorStatus::eOk)
        .value("eOk", Acad::ErrorStatus::eOk)
        .value("eNotImplementedYet", Acad::ErrorStatus::eNotImplementedYet)
        .value("eNotApplicable", Acad::ErrorStatus::eNotApplicable)
        .value("eInvalidInput", Acad::ErrorStatus::eInvalidInput)
        .value("eAmbiguousInput", Acad::ErrorStatus::eAmbiguousInput)
        .value("eAmbiguousOutput", Acad::ErrorStatus::eAmbiguousOutput)
        .value("eOutOfMemory", Acad::ErrorStatus::eOutOfMemory)
        .value("eBufferTooSmall", Acad::ErrorStatus::eBufferTooSmall)
        .value("eInvalidOpenState ", Acad::ErrorStatus::eInvalidOpenState)
        .value("eEntityInInactiveLayout", Acad::ErrorStatus::eEntityInInactiveLayout)
        .value("eHandleExists", Acad::ErrorStatus::eHandleExists)
        .value("eNullHandle", Acad::ErrorStatus::eNullHandle)
        .value("eBrokenHandle", Acad::ErrorStatus::eBrokenHandle)
        .value("eUnknownHandle", Acad::ErrorStatus::eUnknownHandle)
        .value("eHandleInUse", Acad::ErrorStatus::eHandleInUse)
        .value("eNullObjectPointer", Acad::ErrorStatus::eNullObjectPointer)
        .value("eNullObjectId", Acad::ErrorStatus::eNullObjectId)
        .value("eNullBlockName", Acad::ErrorStatus::eNullBlockName)
        .value("eContainerNotEmpty", Acad::ErrorStatus::eContainerNotEmpty)
        .value("eNullEntityPointer", Acad::ErrorStatus::eNullEntityPointer)
        .value("eIllegalEntityType", Acad::ErrorStatus::eIllegalEntityType)
        .value("eKeyNotFound", Acad::ErrorStatus::eKeyNotFound)
        .value("eDuplicateKey", Acad::ErrorStatus::eDuplicateKey)
        .value("eInvalidIndex", Acad::ErrorStatus::eInvalidIndex)
        .value("eDuplicateIndex", Acad::ErrorStatus::eDuplicateIndex)
        .value("eAlreadyInDb", Acad::ErrorStatus::eAlreadyInDb)
        .value("eOutOfDisk", Acad::ErrorStatus::eOutOfDisk)
        .value("eDeletedEntry", Acad::ErrorStatus::eDeletedEntry)
        .value("eNegativeValueNotAllowed", Acad::ErrorStatus::eNegativeValueNotAllowed)
        .value("eInvalidExtents", Acad::ErrorStatus::eInvalidExtents)
        .value("eInvalidAdsName", Acad::ErrorStatus::eInvalidAdsName)
        .value("eInvalidSymbolTableName", Acad::ErrorStatus::eInvalidSymbolTableName)
        .value("eInvalidKey", Acad::ErrorStatus::eInvalidKey)
        .value("eWrongObjectType", Acad::ErrorStatus::eWrongObjectType)
        .value("eWrongDatabase", Acad::ErrorStatus::eWrongDatabase)
        .value("eObjectToBeDeleted", Acad::ErrorStatus::eObjectToBeDeleted)
        .value("eInvalidDwgVersion", Acad::ErrorStatus::eInvalidDwgVersion)
        .value("eAnonymousEntry", Acad::ErrorStatus::eAnonymousEntry)
        .value("eIllegalReplacement", Acad::ErrorStatus::eIllegalReplacement)
        .value("eEndOfObject", Acad::ErrorStatus::eEndOfObject)
        .value("eEndOfFile", Acad::ErrorStatus::eEndOfFile)
        .value("eIsReading", Acad::ErrorStatus::eIsReading)
        .value("eIsWriting", Acad::ErrorStatus::eIsWriting)
        .value("eNotOpenForRead", Acad::ErrorStatus::eNotOpenForRead)
        .value("eNotOpenForWrite", Acad::ErrorStatus::eNotOpenForWrite)
        .value("eNotThatKindOfClass", Acad::ErrorStatus::eNotThatKindOfClass)
        .value("eInvalidBlockName", Acad::ErrorStatus::eInvalidBlockName)
        .value("eMissingDxfField", Acad::ErrorStatus::eMissingDxfField)
        .value("eDuplicateDxfField", Acad::ErrorStatus::eDuplicateDxfField)
        .value("eInvalidDxfCode", Acad::ErrorStatus::eInvalidDxfCode)
        .value("eInvalidResBuf", Acad::ErrorStatus::eInvalidResBuf)
        .value("eBadDxfSequence", Acad::ErrorStatus::eBadDxfSequence)
        .value("eFilerError", Acad::ErrorStatus::eFilerError)
        .value("eVertexAfterFace", Acad::ErrorStatus::eVertexAfterFace)
        .value("eInvalidFaceVertexIndex", Acad::ErrorStatus::eInvalidFaceVertexIndex)
        .value("eInvalidMeshVertexIndex", Acad::ErrorStatus::eInvalidMeshVertexIndex)
        .value("eOtherObjectsBusy", Acad::ErrorStatus::eOtherObjectsBusy)
        .value("eMustFirstAddBlockToDb", Acad::ErrorStatus::eMustFirstAddBlockToDb)
        .value("eCannotNestBlockDefs", Acad::ErrorStatus::eCannotNestBlockDefs)
        .value("eDwgRecoveredOK", Acad::ErrorStatus::eDwgRecoveredOK)
        .value("eDwgNotRecoverable", Acad::ErrorStatus::eDwgNotRecoverable)
        .value("eDxfPartiallyRead", Acad::ErrorStatus::eDxfPartiallyRead)
        .value("eDxfReadAborted", Acad::ErrorStatus::eDxfReadAborted)
        .value("eDxbPartiallyRead", Acad::ErrorStatus::eDxbPartiallyRead)
        .value("eDwgCRCDoesNotMatch", Acad::ErrorStatus::eDwgCRCDoesNotMatch)
        .value("eDwgSentinelDoesNotMatch", Acad::ErrorStatus::eDwgSentinelDoesNotMatch)
        .value("eDwgObjectImproperlyRead", Acad::ErrorStatus::eDwgObjectImproperlyRead)
        .value("eNoInputFiler", Acad::ErrorStatus::eNoInputFiler)
        .value("eDwgNeedsAFullSave", Acad::ErrorStatus::eDwgNeedsAFullSave)
        .value("eDxbReadAborted", Acad::ErrorStatus::eDxbReadAborted)
        .value("eFileLockedByACAD", Acad::ErrorStatus::eFileLockedByACAD)
        .value("eFileAccessErr", Acad::ErrorStatus::eFileAccessErr)
        .value("eFileSystemErr", Acad::ErrorStatus::eFileSystemErr)
        .value("eFileInternalErr", Acad::ErrorStatus::eFileInternalErr)
        .value("eFileTooManyOpen", Acad::ErrorStatus::eFileTooManyOpen)
        .value("eFileNotFound", Acad::ErrorStatus::eFileNotFound)
        .value("eDwkLockFileFound", Acad::ErrorStatus::eDwkLockFileFound)
        .value("eWasErased", Acad::ErrorStatus::eWasErased)
        .value("ePermanentlyErased", Acad::ErrorStatus::ePermanentlyErased)
        .value("eWasOpenForRead", Acad::ErrorStatus::eWasOpenForRead)
        .value("eWasOpenForWrite", Acad::ErrorStatus::eWasOpenForWrite)
        .value("eWasOpenForUndo", Acad::ErrorStatus::eWasOpenForUndo)
        .value("eWasNotifying", Acad::ErrorStatus::eWasNotifying)
        .value("eWasOpenForNotify", Acad::ErrorStatus::eWasOpenForNotify)
        .value("eOnLockedLayer", Acad::ErrorStatus::eOnLockedLayer)
        .value("eMustOpenThruOwner", Acad::ErrorStatus::eMustOpenThruOwner)
        .value("eSubentitiesStillOpen", Acad::ErrorStatus::eSubentitiesStillOpen)
        .value("eAtMaxReaders", Acad::ErrorStatus::eAtMaxReaders)
        .value("eIsWriteProtected", Acad::ErrorStatus::eIsWriteProtected)
        .value("eIsXRefObject", Acad::ErrorStatus::eIsXRefObject)
        .value("eNotAnEntity", Acad::ErrorStatus::eNotAnEntity)
        .value("eHadMultipleReaders", Acad::ErrorStatus::eHadMultipleReaders)
        .value("eDuplicateRecordName", Acad::ErrorStatus::eDuplicateRecordName)
        .value("eXRefDependent", Acad::ErrorStatus::eXRefDependent)
        .value("eSelfReference", Acad::ErrorStatus::eSelfReference)
        .value("eMissingSymbolTable", Acad::ErrorStatus::eMissingSymbolTable)
        .value("eMissingSymbolTableRec", Acad::ErrorStatus::eMissingSymbolTableRec)
        .value("eWasNotOpenForWrite", Acad::ErrorStatus::eWasNotOpenForWrite)
        .value("eCloseWasNotifying", Acad::ErrorStatus::eCloseWasNotifying)
        .value("eCloseModifyAborted", Acad::ErrorStatus::eCloseModifyAborted)
        .value("eClosePartialFailure", Acad::ErrorStatus::eClosePartialFailure)
        .value("eCloseFailObjectDamaged", Acad::ErrorStatus::eCloseFailObjectDamaged)
        .value("eCannotBeErasedByCaller", Acad::ErrorStatus::eCannotBeErasedByCaller)
        .value("eCannotBeResurrected", Acad::ErrorStatus::eCannotBeResurrected)
        .value("eWasNotErased", Acad::ErrorStatus::eWasNotErased)
        .value("eInsertAfter", Acad::ErrorStatus::eInsertAfter)
        .value("eFixedAllErrors", Acad::ErrorStatus::eFixedAllErrors)
        .value("eLeftErrorsUnfixed", Acad::ErrorStatus::eLeftErrorsUnfixed)
        .value("eUnrecoverableErrors", Acad::ErrorStatus::eUnrecoverableErrors)
        .value("eNoDatabase", Acad::ErrorStatus::eNoDatabase)
        .value("eXdataSizeExceeded", Acad::ErrorStatus::eXdataSizeExceeded)
        .value("eRegappIdNotFound", Acad::ErrorStatus::eRegappIdNotFound)
        .value("eRepeatEntity", Acad::ErrorStatus::eRepeatEntity)
        .value("eRecordNotInTable", Acad::ErrorStatus::eRecordNotInTable)
        .value("eIteratorDone", Acad::ErrorStatus::eIteratorDone)
        .value("eNullIterator", Acad::ErrorStatus::eNullIterator)
        .value("eNotInBlock", Acad::ErrorStatus::eNotInBlock)
        .value("eOwnerNotInDatabase", Acad::ErrorStatus::eOwnerNotInDatabase)
        .value("eOwnerNotOpenForRead", Acad::ErrorStatus::eOwnerNotOpenForRead)
        .value("eOwnerNotOpenForWrite", Acad::ErrorStatus::eOwnerNotOpenForWrite)
        .value("eExplodeBeforeTransform", Acad::ErrorStatus::eExplodeBeforeTransform)
        .value("eCannotScaleNonUniformly", Acad::ErrorStatus::eCannotScaleNonUniformly)
        .value("eNotInDatabase", Acad::ErrorStatus::eNotInDatabase)
        .value("eNotCurrentDatabase", Acad::ErrorStatus::eNotCurrentDatabase)
        .value("eIsAnEntity", Acad::ErrorStatus::eIsAnEntity)
        .value("eCannotChangeActiveViewport", Acad::ErrorStatus::eCannotChangeActiveViewport)
        .value("eNotInPaperspace", Acad::ErrorStatus::eNotInPaperspace)
        .value("eCommandWasInProgress", Acad::ErrorStatus::eCommandWasInProgress)
        .value("eGeneralModelingFailure", Acad::ErrorStatus::eGeneralModelingFailure)
        .value("eOutOfRange", Acad::ErrorStatus::eOutOfRange)
        .value("eNonCoplanarGeometry", Acad::ErrorStatus::eNonCoplanarGeometry)
        .value("eDegenerateGeometry", Acad::ErrorStatus::eDegenerateGeometry)
        .value("eInvalidAxis", Acad::ErrorStatus::eInvalidAxis)
        .value("ePointNotOnEntity", Acad::ErrorStatus::ePointNotOnEntity)
        .value("eSingularPoint", Acad::ErrorStatus::eSingularPoint)
        .value("eInvalidOffset", Acad::ErrorStatus::eInvalidOffset)
        .value("eNonPlanarEntity", Acad::ErrorStatus::eNonPlanarEntity)
        .value("eCannotExplodeEntity", Acad::ErrorStatus::eCannotExplodeEntity)
        .value("eStringTooLong", Acad::ErrorStatus::eStringTooLong)
        .value("eInvalidSymTableFlag", Acad::ErrorStatus::eInvalidSymTableFlag)
        .value("eUndefinedLineType", Acad::ErrorStatus::eUndefinedLineType)
        .value("eInvalidTextStyle", Acad::ErrorStatus::eInvalidTextStyle)
        .value("eTooFewLineTypeElements", Acad::ErrorStatus::eTooFewLineTypeElements)
        .value("eTooManyLineTypeElements", Acad::ErrorStatus::eTooManyLineTypeElements)
        .value("eExcessiveItemCount", Acad::ErrorStatus::eExcessiveItemCount)
        .value("eIgnoredLinetypeRedef", Acad::ErrorStatus::eIgnoredLinetypeRedef)
        .value("eBadUCS", Acad::ErrorStatus::eBadUCS)
        .value("eBadPaperspaceView", Acad::ErrorStatus::eBadPaperspaceView)
        .value("eSomeInputDataLeftUnread", Acad::ErrorStatus::eSomeInputDataLeftUnread)
        .value("eNoInternalSpace", Acad::ErrorStatus::eNoInternalSpace)
        .value("eInvalidDimStyle", Acad::ErrorStatus::eInvalidDimStyle)
        .value("eInvalidLayer", Acad::ErrorStatus::eInvalidLayer)
        .value("eUserBreak", Acad::ErrorStatus::eUserBreak)
        .value("eUserUnloaded", Acad::ErrorStatus::eUserUnloaded)
        .value("eUserUnloaded", Acad::ErrorStatus::eUserUnloaded)
        .value("eDeleteEntity", Acad::ErrorStatus::eDeleteEntity)
        .value("eInvalidFix", Acad::ErrorStatus::eInvalidFix)
        .value("eFSMError", Acad::ErrorStatus::eFSMError)
        .value("eBadLayerName", Acad::ErrorStatus::eBadLayerName)
        .value("eLayerGroupCodeMissing", Acad::ErrorStatus::eLayerGroupCodeMissing)
        .value("eBadColorIndex", Acad::ErrorStatus::eBadColorIndex)
        .value("eBadLinetypeName", Acad::ErrorStatus::eBadLinetypeName)
        .value("eBadLinetypeScale", Acad::ErrorStatus::eBadLinetypeScale)
        .value("eBadVisibilityValue", Acad::ErrorStatus::eBadVisibilityValue)
        .value("eProperClassSeparatorExpected", Acad::ErrorStatus::eProperClassSeparatorExpected)
        .value("eBadLineWeightValue", Acad::ErrorStatus::eBadLineWeightValue)
        .value("eBadColor", Acad::ErrorStatus::eBadColor)
        .value("eBadMaterialName", Acad::ErrorStatus::eBadMaterialName)
        .value("ePagerError", Acad::ErrorStatus::ePagerError)
        .value("eOutOfPagerMemory", Acad::ErrorStatus::eOutOfPagerMemory)
        .value("ePagerWriteError", Acad::ErrorStatus::ePagerWriteError)
        .value("eWasNotForwarding", Acad::ErrorStatus::eWasNotForwarding)
        .value("eInvalidIdMap", Acad::ErrorStatus::eInvalidIdMap)
        .value("eInvalidOwnerObject", Acad::ErrorStatus::eInvalidOwnerObject)
        .value("eOwnerNotSet", Acad::ErrorStatus::eOwnerNotSet)
        .value("eWrongSubentityType", Acad::ErrorStatus::eWrongSubentityType)
        .value("eTooManyVertices", Acad::ErrorStatus::eTooManyVertices)
        .value("eTooFewVertices", Acad::ErrorStatus::eTooFewVertices)
        .value("eNoActiveTransactions", Acad::ErrorStatus::eNoActiveTransactions)
        .value("eNotTopTransaction", Acad::ErrorStatus::eNotTopTransaction)
        .value("eTransactionOpenWhileCommandEnded", Acad::ErrorStatus::eTransactionOpenWhileCommandEnded)
        .value("eInProcessOfCommitting", Acad::ErrorStatus::eInProcessOfCommitting)
        .value("eNotNewlyCreated", Acad::ErrorStatus::eNotNewlyCreated)
        .value("eLongTransReferenceError", Acad::ErrorStatus::eLongTransReferenceError)
        .value("eNoWorkSet", Acad::ErrorStatus::eNoWorkSet)
        .value("eAlreadyInGroup", Acad::ErrorStatus::eAlreadyInGroup)
        .value("eNotInGroup", Acad::ErrorStatus::eNotInGroup)
        .value("eAlreadyInferred", Acad::ErrorStatus::eAlreadyInferred)
        .value("eInvalidREFIID", Acad::ErrorStatus::eInvalidREFIID)
        .value("eInvalidNormal", Acad::ErrorStatus::eInvalidNormal)
        .value("eInvalidStyle", Acad::ErrorStatus::eInvalidStyle)
        .value("eCannotRestoreFromAcisFile", Acad::ErrorStatus::eCannotRestoreFromAcisFile)
        .value("eMakeMeProxy", Acad::ErrorStatus::eMakeMeProxy)
        .value("eNLSFileNotAvailable", Acad::ErrorStatus::eNLSFileNotAvailable)
        .value("eNotAllowedForThisProxy", Acad::ErrorStatus::eNotAllowedForThisProxy)
        .value("eNotClonedPrimaryProxy", Acad::ErrorStatus::eNotClonedPrimaryProxy)
        .value("eNotSupportedInDwgApi", Acad::ErrorStatus::eNotSupportedInDwgApi)
        .value("ePolyWidthLost", Acad::ErrorStatus::ePolyWidthLost)
        .value("eNullExtents", Acad::ErrorStatus::eNullExtents)
        .value("eBadDwgHeader", Acad::ErrorStatus::eBadDwgHeader)
        .value("eLockViolation", Acad::ErrorStatus::eLockViolation)
        .value("eLockConflict", Acad::ErrorStatus::eLockConflict)
        .value("eDatabaseObjectsOpen", Acad::ErrorStatus::eDatabaseObjectsOpen)
        .value("eLockChangeInProgress", Acad::ErrorStatus::eLockChangeInProgress)
        .value("eVetoed", Acad::ErrorStatus::eVetoed)
        .value("eNoDocument", Acad::ErrorStatus::eNoDocument)
        .value("eNotFromThisDocument", Acad::ErrorStatus::eNotFromThisDocument)
        .value("eLISPActive", Acad::ErrorStatus::eLISPActive)
        .value("eTargetDocNotQuiescent", Acad::ErrorStatus::eTargetDocNotQuiescent)
        .value("eDocumentSwitchDisabled", Acad::ErrorStatus::eDocumentSwitchDisabled)
        .value("eInvalidContext", Acad::ErrorStatus::eInvalidContext)
        .value("eCreateFailed", Acad::ErrorStatus::eCreateFailed)
        .value("eCreateInvalidName", Acad::ErrorStatus::eCreateInvalidName)
        .value("eSetFailed", Acad::ErrorStatus::eSetFailed)
        .value("eDelDoesNotExist", Acad::ErrorStatus::eDelDoesNotExist)
        .value("eDelIsModelSpace", Acad::ErrorStatus::eDelIsModelSpace)
        .value("eDelLastLayout", Acad::ErrorStatus::eDelLastLayout)
        .value("eDelUnableToSetCurrent", Acad::ErrorStatus::eDelUnableToSetCurrent)
        .value("eDelUnableToFind", Acad::ErrorStatus::eDelUnableToFind)
        .value("eRenameDoesNotExist", Acad::ErrorStatus::eRenameDoesNotExist)
        .value("eRenameIsModelSpace", Acad::ErrorStatus::eRenameIsModelSpace)
        .value("eRenameInvalidLayoutName", Acad::ErrorStatus::eRenameInvalidLayoutName)
        .value("eRenameLayoutAlreadyExists", Acad::ErrorStatus::eRenameLayoutAlreadyExists)
        .value("eRenameInvalidName", Acad::ErrorStatus::eRenameInvalidName)
        .value("eCopyDoesNotExist", Acad::ErrorStatus::eCopyDoesNotExist)
        .value("eCopyIsModelSpace", Acad::ErrorStatus::eCopyIsModelSpace)
        .value("eCopyFailed", Acad::ErrorStatus::eCopyFailed)
        .value("eCopyInvalidName", Acad::ErrorStatus::eCopyInvalidName)
        .value("eCopyNameExists", Acad::ErrorStatus::eCopyNameExists)
        .value("eProfileDoesNotExist", Acad::ErrorStatus::eProfileDoesNotExist)
        .value("eInvalidFileExtension", Acad::ErrorStatus::eInvalidFileExtension)
        .value("eInvalidProfileName", Acad::ErrorStatus::eInvalidProfileName)
        .value("eFileExists", Acad::ErrorStatus::eFileExists)
        .value("eProfileIsInUse", Acad::ErrorStatus::eProfileIsInUse)
        .value("eCantOpenFile", Acad::ErrorStatus::eCantOpenFile)
        .value("eNoFileName", Acad::ErrorStatus::eNoFileName)
        .value("eRegistryAccessError", Acad::ErrorStatus::eRegistryAccessError)
        .value("eRegistryCreateError", Acad::ErrorStatus::eRegistryCreateError)
        .value("eBadDxfFile", Acad::ErrorStatus::eBadDxfFile)
        .value("eUnknownDxfFileFormat", Acad::ErrorStatus::eUnknownDxfFileFormat)
        .value("eMissingDxfSection", Acad::ErrorStatus::eMissingDxfSection)
        .value("eInvalidDxfSectionName", Acad::ErrorStatus::eInvalidDxfSectionName)
        .value("eNotDxfHeaderGroupCode", Acad::ErrorStatus::eNotDxfHeaderGroupCode)
        .value("eUndefinedDxfGroupCode", Acad::ErrorStatus::eUndefinedDxfGroupCode)
        .value("eNotInitializedYet", Acad::ErrorStatus::eNotInitializedYet)
        .value("eInvalidDxf2dPoint", Acad::ErrorStatus::eInvalidDxf2dPoint)
        .value("eInvalidDxf3dPoint", Acad::ErrorStatus::eInvalidDxf3dPoint)
        .value("eBadlyNestedAppData", Acad::ErrorStatus::eBadlyNestedAppData)
        .value("eIncompleteBlockDefinition", Acad::ErrorStatus::eIncompleteBlockDefinition)
        .value("eIncompleteComplexObject", Acad::ErrorStatus::eIncompleteComplexObject)
        .value("eBlockDefInEntitySection", Acad::ErrorStatus::eBlockDefInEntitySection)
        .value("eNoBlockBegin", Acad::ErrorStatus::eNoBlockBegin)
        .value("eDuplicateLayerName", Acad::ErrorStatus::eDuplicateLayerName)
        .value("eBadPlotStyleName", Acad::ErrorStatus::eBadPlotStyleName)
        .value("eDuplicateBlockName", Acad::ErrorStatus::eDuplicateBlockName)
        .value("eBadPlotStyleType", Acad::ErrorStatus::eBadPlotStyleType)
        .value("eBadPlotStyleNameHandle", Acad::ErrorStatus::eBadPlotStyleNameHandle)
        .value("eUndefineShapeName", Acad::ErrorStatus::eUndefineShapeName)
        .value("eDuplicateBlockDefinition", Acad::ErrorStatus::eDuplicateBlockDefinition)
        .value("eMissingBlockName", Acad::ErrorStatus::eMissingBlockName)
        .value("eBinaryDataSizeExceeded", Acad::ErrorStatus::eBinaryDataSizeExceeded)
        .value("eObjectIsReferenced", Acad::ErrorStatus::eObjectIsReferenced)
        .value("eNoThumbnailBitmap", Acad::ErrorStatus::eNoThumbnailBitmap)
        .value("eGuidNoAddress", Acad::ErrorStatus::eGuidNoAddress)
        .value("eMustBe0to2", Acad::ErrorStatus::eMustBe0to2)
        .value("eMustBe0to3", Acad::ErrorStatus::eMustBe0to3)
        .value("eMustBe0to4", Acad::ErrorStatus::eMustBe0to4)
        .value("eMustBe0to5", Acad::ErrorStatus::eMustBe0to5)
        .value("eMustBe0to8", Acad::ErrorStatus::eMustBe0to8)
        .value("eMustBe1to8", Acad::ErrorStatus::eMustBe1to8)
        .value("eMustBe1to15", Acad::ErrorStatus::eMustBe1to15)
        .value("eMustBePositive", Acad::ErrorStatus::eMustBePositive)
        .value("eMustBeNonNegative", Acad::ErrorStatus::eMustBeNonNegative)
        .value("eMustBeNonZero", Acad::ErrorStatus::eMustBeNonZero)
        .value("eMustBe1to6", Acad::ErrorStatus::eMustBe1to6)
        .value("eNoPlotStyleTranslationTable", Acad::ErrorStatus::eNoPlotStyleTranslationTable)
        .value("ePlotStyleInColorDependentMode", Acad::ErrorStatus::ePlotStyleInColorDependentMode)
        .value("eMaxLayouts", Acad::ErrorStatus::eMaxLayouts)
        .value("eNoClassId", Acad::ErrorStatus::eNoClassId)
        .value("eUndoOperationNotAvailable", Acad::ErrorStatus::eUndoOperationNotAvailable)
        .value("eUndoNoGroupBegin", Acad::ErrorStatus::eUndoNoGroupBegin)
        .value("eHatchTooDense", Acad::ErrorStatus::eHatchTooDense)
        .value("eOpenFileCancelled", Acad::ErrorStatus::eOpenFileCancelled)
        .value("eNotHandled", Acad::ErrorStatus::eNotHandled)
        .value("eMakeMeProxyAndResurrect", Acad::ErrorStatus::eMakeMeProxyAndResurrect)
        .value("eFileSharingViolation", Acad::ErrorStatus::eFileSharingViolation)
        .value("eUnsupportedFileFormat", Acad::ErrorStatus::eUnsupportedFileFormat)
        .value("eObsoleteFileFormat", Acad::ErrorStatus::eObsoleteFileFormat)
        .value("eFileMissingSections", Acad::ErrorStatus::eFileMissingSections)
        .value("eRepeatedDwgRead", Acad::ErrorStatus::eRepeatedDwgRead)
        .value("eSilentOpenFileCancelled", Acad::ErrorStatus::eSilentOpenFileCancelled)
        .value("eWrongCellType", Acad::ErrorStatus::eWrongCellType)
        .value("eCannotChangeColumnType", Acad::ErrorStatus::eCannotChangeColumnType)
        .value("eRowsMustMatchColumns", Acad::ErrorStatus::eRowsMustMatchColumns)
        .value("eNullNodeId", Acad::ErrorStatus::eNullNodeId)
        .value("eNoNodeActive", Acad::ErrorStatus::eNoNodeActive)
        .value("eGraphContainsProxies", Acad::ErrorStatus::eGraphContainsProxies)
        .value("eDwgShareDemandLoad", Acad::ErrorStatus::eDwgShareDemandLoad)
        .value("eDwgShareReadAccess", Acad::ErrorStatus::eDwgShareReadAccess)
        .value("eDwgShareWriteAccess", Acad::ErrorStatus::eDwgShareWriteAccess)
        .value("eLoadFailed", Acad::ErrorStatus::eLoadFailed)
        .value("eDeviceNotFound", Acad::ErrorStatus::eDeviceNotFound)
        .value("eNoCurrentConfig", Acad::ErrorStatus::eNoCurrentConfig)
        .value("eNullPtr", Acad::ErrorStatus::eNullPtr)
        .value("eNoLayout", Acad::ErrorStatus::eNoLayout)
        .value("eIncompatiblePlotSettings", Acad::ErrorStatus::eIncompatiblePlotSettings)
        .value("eNonePlotDevice", Acad::ErrorStatus::eNonePlotDevice)
        .value("eNoMatchingMedia", Acad::ErrorStatus::eNoMatchingMedia)
        .value("eInvalidView", Acad::ErrorStatus::eInvalidView)
        .value("eInvalidWindowArea", Acad::ErrorStatus::eInvalidWindowArea)
        .value("eInvalidPlotArea", Acad::ErrorStatus::eInvalidPlotArea)
        .value("eCustomSizeNotPossible", Acad::ErrorStatus::eCustomSizeNotPossible)
        .value("ePageCancelled", Acad::ErrorStatus::ePageCancelled)
        .value("ePlotCancelled", Acad::ErrorStatus::ePlotCancelled)
        .value("eInvalidEngineState", Acad::ErrorStatus::eInvalidEngineState)
        .value("ePlotAlreadyStarted", Acad::ErrorStatus::ePlotAlreadyStarted)
        .value("eNoErrorHandler", Acad::ErrorStatus::eNoErrorHandler)
        .value("eInvalidPlotInfo", Acad::ErrorStatus::eInvalidPlotInfo)
        .value("eNumberOfCopiesNotSupported", Acad::ErrorStatus::eNumberOfCopiesNotSupported)
        .value("eLayoutNotCurrent", Acad::ErrorStatus::eLayoutNotCurrent)
        .value("eGraphicsNotGenerated", Acad::ErrorStatus::eGraphicsNotGenerated)
        .value("eCannotPlotToFile", Acad::ErrorStatus::eCannotPlotToFile)
        .value("eMustPlotToFile", Acad::ErrorStatus::eMustPlotToFile)
        .value("eNotMultiPageCapable", Acad::ErrorStatus::eNotMultiPageCapable)
        .value("eBackgroundPlotInProgress", Acad::ErrorStatus::eBackgroundPlotInProgress)
        .value("eNotShownInPropertyPalette", Acad::ErrorStatus::eNotShownInPropertyPalette)
        .value("eSubSelectionSetEmpty", Acad::ErrorStatus::eSubSelectionSetEmpty)
        .value("eNoIntersections", Acad::ErrorStatus::eNoIntersections)
        .value("eEmbeddedIntersections", Acad::ErrorStatus::eEmbeddedIntersections)
        .value("eNoOverride", Acad::ErrorStatus::eNoOverride)
        .value("eNoStoredOverrides", Acad::ErrorStatus::eNoStoredOverrides)
        .value("eUnableToRetrieveOverrides", Acad::ErrorStatus::eUnableToRetrieveOverrides)
        .value("eUnableToStoreOverrides", Acad::ErrorStatus::eUnableToStoreOverrides)
        .value("eUnableToRemoveOverrides", Acad::ErrorStatus::eUnableToRemoveOverrides)
        .value("eNoStoredReconcileStatus", Acad::ErrorStatus::eNoStoredReconcileStatus)
        .value("eUnableToStoreReconcileStatus", Acad::ErrorStatus::eUnableToStoreReconcileStatus)
        .value("eInvalidObjectId", Acad::ErrorStatus::eInvalidObjectId)
        .value("eInvalidXrefObjectId", Acad::ErrorStatus::eInvalidXrefObjectId)
        .value("eNoViewAssociation", Acad::ErrorStatus::eNoViewAssociation)
        .value("eNoLabelBlock", Acad::ErrorStatus::eNoLabelBlock)
        .value("eUnableToSetViewAssociation", Acad::ErrorStatus::eUnableToSetViewAssociation)
        .value("eUnableToGetViewAssociation", Acad::ErrorStatus::eUnableToGetViewAssociation)
        .value("eUnableToSetLabelBlock", Acad::ErrorStatus::eUnableToSetLabelBlock)
        .value("eUnableToGetLabelBlock", Acad::ErrorStatus::eUnableToGetLabelBlock)
        .value("eUnableToRemoveAssociation ", Acad::ErrorStatus::eUnableToRemoveAssociation)
        .value("eUnableToSyncModelView", Acad::ErrorStatus::eUnableToSyncModelView)
        .value("eDataLinkAdapterNotFound", Acad::ErrorStatus::eDataLinkAdapterNotFound)
        .value("eDataLinkInvalidAdapterId", Acad::ErrorStatus::eDataLinkInvalidAdapterId)
        .value("eDataLinkNotFound", Acad::ErrorStatus::eDataLinkNotFound)
        .value("eDataLinkBadConnectionString", Acad::ErrorStatus::eDataLinkBadConnectionString)
        .value("eDataLinkNotUpdatedYet", Acad::ErrorStatus::eDataLinkNotUpdatedYet)
        .value("eDataLinkSourceNotFound", Acad::ErrorStatus::eDataLinkSourceNotFound)
        .value("eDataLinkConnectionFailed", Acad::ErrorStatus::eDataLinkConnectionFailed)
        .value("eDataLinkSourceUpdateNotAllowed", Acad::ErrorStatus::eDataLinkSourceUpdateNotAllowed)
        .value("eDataLinkSourceIsWriteProtected", Acad::ErrorStatus::eDataLinkSourceIsWriteProtected)
        .value("eDataLinkExcelNotFound", Acad::ErrorStatus::eDataLinkExcelNotFound)
        .value("eDataLinkOtherError", Acad::ErrorStatus::eDataLinkOtherError)
        .value("eXrefReloaded", Acad::ErrorStatus::eXrefReloaded)
        .value("eXrefReloadImpossibleAtThisTime", Acad::ErrorStatus::eXrefReloadImpossibleAtThisTime)
        .value("eSecInitializationFailure", Acad::ErrorStatus::eSecInitializationFailure)
        .value("eSecErrorReadingFile", Acad::ErrorStatus::eSecErrorReadingFile)
        .value("eSecErrorWritingFile", Acad::ErrorStatus::eSecErrorWritingFile)
        .value("eSecInvalidDigitalID", Acad::ErrorStatus::eSecInvalidDigitalID)
        .value("eSecErrorGeneratingTimestamp", Acad::ErrorStatus::eSecErrorGeneratingTimestamp)
        .value("eSecErrorComputingSignature", Acad::ErrorStatus::eSecErrorComputingSignature)
        .value("eSecErrorWritingSignature", Acad::ErrorStatus::eSecErrorWritingSignature)
        .value("eSecErrorEncryptingData", Acad::ErrorStatus::eSecErrorEncryptingData)
        .value("eSecErrorCipherNotSupported", Acad::ErrorStatus::eSecErrorCipherNotSupported)
        .value("eSecErrorDecryptingData", Acad::ErrorStatus::eSecErrorDecryptingData)
        .value("eNoAcDbHostApplication", Acad::ErrorStatus::eNoAcDbHostApplication)
        .value("eNoUnderlayHost", Acad::ErrorStatus::eNoUnderlayHost)
        .value("ePCUnknown", Acad::ErrorStatus::ePCUnknown)
        .value("ePCLargeData", Acad::ErrorStatus::ePCLargeData)
        .value("ePCUnknownFileType", Acad::ErrorStatus::ePCUnknownFileType)
        .value("ePCFileNotFound", Acad::ErrorStatus::ePCFileNotFound)
        .value("ePCFileNotCreated", Acad::ErrorStatus::ePCFileNotCreated)
        .value("ePCFileNotOpened", Acad::ErrorStatus::ePCFileNotOpened)
        .value("ePCFileNotClosed", Acad::ErrorStatus::ePCFileNotClosed)
        .value("ePCFileNotWritten", Acad::ErrorStatus::ePCFileNotWritten)
        .value("ePCFileWrongFormat", Acad::ErrorStatus::ePCFileWrongFormat)
        .value("ePCFileDataSelectorInvalid", Acad::ErrorStatus::ePCFileDataSelectorInvalid)
        .value("ePCCoordSysReprojectFail", Acad::ErrorStatus::ePCCoordSysReprojectFail)
        .value("ePCDiskSpaceTooSmall", Acad::ErrorStatus::ePCDiskSpaceTooSmall)
        .value("ePCThreadTerminated", Acad::ErrorStatus::ePCThreadTerminated)
        .value("ePCFileNotErased", Acad::ErrorStatus::ePCFileNotErased)
        .value("ePCCoordSysAssignFail", Acad::ErrorStatus::ePCCoordSysAssignFail)
        .value("ePCLastImporterUnfinished", Acad::ErrorStatus::ePCLastImporterUnfinished)
        .value("ePCNoEngineInfo", Acad::ErrorStatus::ePCNoEngineInfo)
        .value("ePCInProgress", Acad::ErrorStatus::ePCInProgress)
        .value("eInetBase", Acad::ErrorStatus::eInetBase)
        .value("eInetOk", Acad::ErrorStatus::eInetOk)
        .value("eInetInCache", Acad::ErrorStatus::eInetInCache)
        .value("eInetFileNotFound", Acad::ErrorStatus::eInetFileNotFound)
        .value("eInetBadPath", Acad::ErrorStatus::eInetBadPath)
        .value("eInetTooManyOpenFiles", Acad::ErrorStatus::eInetTooManyOpenFiles)
        .value("eInetFileAccessDenied", Acad::ErrorStatus::eInetFileAccessDenied)
        .value("eInetInvalidFileHandle", Acad::ErrorStatus::eInetInvalidFileHandle)
        .value("eInetDirectoryFull", Acad::ErrorStatus::eInetDirectoryFull)
        .value("eInetHardwareError", Acad::ErrorStatus::eInetHardwareError)
        .value("eInetSharingViolation", Acad::ErrorStatus::eInetSharingViolation)
        .value("eInetDiskFull", Acad::ErrorStatus::eInetDiskFull)
        .value("eInetFileGenericError", Acad::ErrorStatus::eInetFileGenericError)
        .value("eInetValidURL", Acad::ErrorStatus::eInetValidURL)
        .value("eInetNotAnURL", Acad::ErrorStatus::eInetNotAnURL)
        .value("eInetNoWinInet", Acad::ErrorStatus::eInetNoWinInet)
        .value("eInetOldWinInet", Acad::ErrorStatus::eInetOldWinInet)
        .value("eInetNoAcadInet", Acad::ErrorStatus::eInetNoAcadInet)
        .value("eInetNotImplemented", Acad::ErrorStatus::eInetNotImplemented)
        .value("eInetProtocolNotSupported", Acad::ErrorStatus::eInetProtocolNotSupported)
        .value("eInetCreateInternetSessionFailed", Acad::ErrorStatus::eInetCreateInternetSessionFailed)
        .value("eInetInternetSessionConnectFailed", Acad::ErrorStatus::eInetInternetSessionConnectFailed)
        .value("eInetInternetSessionOpenFailed", Acad::ErrorStatus::eInetInternetSessionOpenFailed)
        .value("eInetInvalidAccessType", Acad::ErrorStatus::eInetInvalidAccessType)
        .value("eInetFileOpenFailed", Acad::ErrorStatus::eInetFileOpenFailed)
        .value("eInetHttpOpenRequestFailed", Acad::ErrorStatus::eInetHttpOpenRequestFailed)
        .value("eInetUserCancelledTransfer", Acad::ErrorStatus::eInetUserCancelledTransfer)
        .value("eInetHttpBadRequest", Acad::ErrorStatus::eInetHttpBadRequest)
        .value("eInetHttpAccessDenied", Acad::ErrorStatus::eInetHttpAccessDenied)
        .value("eInetHttpPaymentRequired", Acad::ErrorStatus::eInetHttpPaymentRequired)
        .value("eInetHttpRequestForbidden", Acad::ErrorStatus::eInetHttpRequestForbidden)
        .value("eInetHttpObjectNotFound", Acad::ErrorStatus::eInetHttpObjectNotFound)
        .value("eInetHttpBadMethod", Acad::ErrorStatus::eInetHttpBadMethod)
        .value("eInetHttpNoAcceptableResponse", Acad::ErrorStatus::eInetHttpNoAcceptableResponse)
        .value("eInetHttpProxyAuthorizationRequired", Acad::ErrorStatus::eInetHttpProxyAuthorizationRequired)
        .value("eInetHttpTimedOut", Acad::ErrorStatus::eInetHttpTimedOut)
        .value("eInetHttpConflict", Acad::ErrorStatus::eInetHttpConflict)
        .value("eInetHttpResourceGone", Acad::ErrorStatus::eInetHttpResourceGone)
        .value("eInetHttpLengthRequired", Acad::ErrorStatus::eInetHttpLengthRequired)
        .value("eInetHttpPreconditionFailure", Acad::ErrorStatus::eInetHttpPreconditionFailure)
        .value("eInetHttpRequestTooLarge", Acad::ErrorStatus::eInetHttpRequestTooLarge)
        .value("eInetHttpUriTooLong", Acad::ErrorStatus::eInetHttpUriTooLong)
        .value("eInetHttpUnsupportedMedia", Acad::ErrorStatus::eInetHttpUnsupportedMedia)
        .value("eInetHttpServerError", Acad::ErrorStatus::eInetHttpServerError)
        .value("eInetHttpNotSupported", Acad::ErrorStatus::eInetHttpNotSupported)
        .value("eInetHttpBadGateway", Acad::ErrorStatus::eInetHttpBadGateway)
        .value("eInetHttpServiceUnavailable", Acad::ErrorStatus::eInetHttpServiceUnavailable)
        .value("eInetHttpGatewayTimeout", Acad::ErrorStatus::eInetHttpGatewayTimeout)
        .value("eInetHttpVersionNotSupported", Acad::ErrorStatus::eInetHttpVersionNotSupported)
        .value("eInetInternetError", Acad::ErrorStatus::eInetInternetError)
        .value("eInetGenericException", Acad::ErrorStatus::eInetGenericException)
        .value("eInetUnknownError", Acad::ErrorStatus::eInetUnknownError)
        .value("eAlreadyActive", Acad::ErrorStatus::eAlreadyActive)
        .value("eAlreadyInactive", Acad::ErrorStatus::eAlreadyInactive)
        .value("eGraphEdgeNotFound", Acad::ErrorStatus::eGraphEdgeNotFound)
        .value("eGraphNodeNotFound", Acad::ErrorStatus::eGraphNodeNotFound)
        .value("eGraphNodeAlreadyExists", Acad::ErrorStatus::eGraphNodeAlreadyExists)
        .value("eGraphEdgeAlreadyExists", Acad::ErrorStatus::eGraphEdgeAlreadyExists)
        .value("eGraphCyclesFound", Acad::ErrorStatus::eGraphCyclesFound)
        .value("eAlreadyHasRepresentation", Acad::ErrorStatus::eAlreadyHasRepresentation)
        .value("eNoRepresentation", Acad::ErrorStatus::eNoRepresentation)
        .value("eFailedToSetEdgeChamfers", Acad::ErrorStatus::eFailedToSetEdgeChamfers)
        .value("eNoConnectedBlendSet", Acad::ErrorStatus::eNoConnectedBlendSet)
        .value("eFailedToBlend", Acad::ErrorStatus::eFailedToBlend)
        .value("eFailedToSetEdgeRounds", Acad::ErrorStatus::eFailedToSetEdgeRounds)
        .value("eFailedToSetVertexRounds", Acad::ErrorStatus::eFailedToSetVertexRounds)
        .value("eVSNotFound", Acad::ErrorStatus::eVSNotFound)
        .value("eVSTrue", Acad::ErrorStatus::eVSTrue)
        .value("eVSFalse", Acad::ErrorStatus::eVSFalse)
        .value("eVSAlreadyExists", Acad::ErrorStatus::eVSAlreadyExists)
        .value("eVSOneOffCreated", Acad::ErrorStatus::eVSOneOffCreated)
        .value("eVSAPIOnlyValues", Acad::ErrorStatus::eVSAPIOnlyValues)
        .value("eVSIsInUse", Acad::ErrorStatus::eVSIsInUse)
        .value("eVSIsAcadDefault", Acad::ErrorStatus::eVSIsAcadDefault)
        .value("eEmptyOperand", Acad::ErrorStatus::eEmptyOperand)
        .value("eNoEntitiesFromPersistentIds", Acad::ErrorStatus::eNoEntitiesFromPersistentIds)
        .value("eFailedCurveCheck", Acad::ErrorStatus::eFailedCurveCheck)
        .value("eMaxNodes", Acad::ErrorStatus::eMaxNodes)
        .value("eFailedToEvaluate", Acad::ErrorStatus::eFailedToEvaluate)
        .value("eFailedToEvaluateDependents", Acad::ErrorStatus::eFailedToEvaluateDependents)
        .value("eInvalidExpression", Acad::ErrorStatus::eInvalidExpression)
        .value("eCyclicDependency", Acad::ErrorStatus::eCyclicDependency)
        .value("eInconsistentConstraint", Acad::ErrorStatus::eInconsistentConstraint)
        .value("eOverDefinedConstraint", Acad::ErrorStatus::eOverDefinedConstraint)
        .value("eAllInSameRigidSet", Acad::ErrorStatus::eAllInSameRigidSet)
        .value("eInvalidParameterName", Acad::ErrorStatus::eInvalidParameterName)
        .value("eReferencedInEquation", Acad::ErrorStatus::eReferencedInEquation)
        .value("eEntityRestricedInDOF", Acad::ErrorStatus::eEntityRestricedInDOF)
        .value("eDataTooLarge", Acad::ErrorStatus::eDataTooLarge)
        .value("eNearSizeLimit", Acad::ErrorStatus::eNearSizeLimit)
        .value("eStringNotAllowedInExpression", Acad::ErrorStatus::eStringNotAllowedInExpression)
        .value("eTooManyActiveCommands", Acad::ErrorStatus::eTooManyActiveCommands)
        .value("eUnableToTrimLastPiece", Acad::ErrorStatus::eUnableToTrimLastPiece)
        .value("eUnableToTrimSurface", Acad::ErrorStatus::eUnableToTrimSurface)
        .value("eModifyingAssociativeEntity", Acad::ErrorStatus::eModifyingAssociativeEntity)
        .value("eModifyingDimensionWithExpression", Acad::ErrorStatus::eModifyingDimensionWithExpression)
        .value("eDependentOnObjectErased", Acad::ErrorStatus::eDependentOnObjectErased)
        .value("eSelfIntersecting", Acad::ErrorStatus::eSelfIntersecting)
        .value("eNotOnBoundary", Acad::ErrorStatus::eNotOnBoundary)
        .value("eNotConnected", Acad::ErrorStatus::eNotConnected)
        .value("eNoInputPath", Acad::ErrorStatus::eNoInputPath)
        .value("eNotAssociative", Acad::ErrorStatus::eNotAssociative)
        .value("eNotG1Continuous", Acad::ErrorStatus::eNotG1Continuous)
        .value("eOwnerToBeTransformed", Acad::ErrorStatus::eOwnerToBeTransformed)
        .value("eMustBeInteger", Acad::ErrorStatus::eMustBeInteger)
        .value("eMustBePositiveInteger", Acad::ErrorStatus::eMustBePositiveInteger)
        .value("eChangedAgainstAssociativity", Acad::ErrorStatus::eChangedAgainstAssociativity)
        .value("eItemCountChanged", Acad::ErrorStatus::eItemCountChanged)
        .value("eGetAdIntImgServicesFailed", Acad::ErrorStatus::eGetAdIntImgServicesFailed)
        .value("eReadImageBufferFailed", Acad::ErrorStatus::eReadImageBufferFailed)
        .value("eWriteImageBufferFailed", Acad::ErrorStatus::eWriteImageBufferFailed)
        .value("eGetImageBytesFailed", Acad::ErrorStatus::eGetImageBytesFailed)
        .value("eGetImageDIBFailed", Acad::ErrorStatus::eGetImageDIBFailed)
        .value("eConvertImageFormatFailed", Acad::ErrorStatus::eConvertImageFormatFailed)
        .value("eGetPreviewImageFailed", Acad::ErrorStatus::eGetPreviewImageFailed)
        .value("eInvalidPreviewImage", Acad::ErrorStatus::eInvalidPreviewImage)
        .value("eDelayMore", Acad::ErrorStatus::eDelayMore)
        .value("ePreviewFailed", Acad::ErrorStatus::ePreviewFailed)
        .value("eAbortPreview", Acad::ErrorStatus::eAbortPreview)
        .value("eEndPreview", Acad::ErrorStatus::eEndPreview)
        .value("eNoPreviewContext", Acad::ErrorStatus::eNoPreviewContext)
        .value("eFileNotInCloud", Acad::ErrorStatus::eFileNotInCloud)
        .export_values()
        ;
    enum_<AcDbGeoCoordinateSystem::Type>("GeoCoordinateSystemType")
        .value("kTypeUnknown", AcDbGeoCoordinateSystem::Type::kTypeUnknown)
        .value("kTypeArbitrary", AcDbGeoCoordinateSystem::Type::kTypeArbitrary)
        .value("kTypeGeographic", AcDbGeoCoordinateSystem::Type::kTypeGeographic)
        .value("kTypeProjected", AcDbGeoCoordinateSystem::Type::kTypeProjected)
        .export_values()
        ;
    enum_<AcDbGeoCoordinateSystem::ProjectionCode>("GeoCoordinateSystemProjectionCode")
        .value("kProjectionCodeUnknown", AcDbGeoCoordinateSystem::ProjectionCode::kProjectionCodeUnknown)
        .value("kProjectionCodeAlber", AcDbGeoCoordinateSystem::ProjectionCode::kProjectionCodeAlber)
        .value("kProjectionCodeAzede", AcDbGeoCoordinateSystem::ProjectionCode::kProjectionCodeAzede)
        .value("kProjectionCodeAzmea", AcDbGeoCoordinateSystem::ProjectionCode::kProjectionCodeAzmea)
        .value("kProjectionCodeAzmed", AcDbGeoCoordinateSystem::ProjectionCode::kProjectionCodeAzmed)
        .value("kProjectionCodeBipolar", AcDbGeoCoordinateSystem::ProjectionCode::kProjectionCodeBipolar)
        .value("kProjectionCodeBonne", AcDbGeoCoordinateSystem::ProjectionCode::kProjectionCodeBonne)
        .value("kProjectionCodeCassini", AcDbGeoCoordinateSystem::ProjectionCode::kProjectionCodeCassini)
        .value("kProjectionCodeEckert4", AcDbGeoCoordinateSystem::ProjectionCode::kProjectionCodeEckert4)
        .value("kProjectionCodeEckert6", AcDbGeoCoordinateSystem::ProjectionCode::kProjectionCodeEckert6)
        .value("kProjectionCodeEdcnc", AcDbGeoCoordinateSystem::ProjectionCode::kProjectionCodeEdcnc)
        .value("kProjectionCodeEdcyl", AcDbGeoCoordinateSystem::ProjectionCode::kProjectionCodeEdcyl)
        .value("kProjectionCodeGaussK", AcDbGeoCoordinateSystem::ProjectionCode::kProjectionCodeGaussK)
        .value("kProjectionCodeGnomonic", AcDbGeoCoordinateSystem::ProjectionCode::kProjectionCodeGnomonic)
        .value("kProjectionCodeGoode", AcDbGeoCoordinateSystem::ProjectionCode::kProjectionCodeGoode)
        .value("kProjectionCodeHom1uv", AcDbGeoCoordinateSystem::ProjectionCode::kProjectionCodeHom1uv)
        .value("kProjectionCodeHom1xy", AcDbGeoCoordinateSystem::ProjectionCode::kProjectionCodeHom1xy)
        .value("kProjectionCodeHom2uv", AcDbGeoCoordinateSystem::ProjectionCode::kProjectionCodeHom2uv)
        .value("kProjectionCodeHom2xy", AcDbGeoCoordinateSystem::ProjectionCode::kProjectionCodeHom2xy)
        .value("kProjectionCodeKrovak", AcDbGeoCoordinateSystem::ProjectionCode::kProjectionCodeKrovak)
        .value("kProjectionCodeKrvk95", AcDbGeoCoordinateSystem::ProjectionCode::kProjectionCodeKrvk95)
        .value("kProjectionCodeLL", AcDbGeoCoordinateSystem::ProjectionCode::kProjectionCodeLL)
        .value("kProjectionCodeLm1sp", AcDbGeoCoordinateSystem::ProjectionCode::kProjectionCodeLm1sp)
        .value("kProjectionCodeLm2sp", AcDbGeoCoordinateSystem::ProjectionCode::kProjectionCodeLm2sp)
        .value("kProjectionCodeLmblg", AcDbGeoCoordinateSystem::ProjectionCode::kProjectionCodeLmblg)
        .value("kProjectionCodeLmtan", AcDbGeoCoordinateSystem::ProjectionCode::kProjectionCodeLmtan)
        .value("kProjectionCodeMiller", AcDbGeoCoordinateSystem::ProjectionCode::kProjectionCodeMiller)
        .value("kProjectionCodeMndotl", AcDbGeoCoordinateSystem::ProjectionCode::kProjectionCodeMndotl)
        .value("kProjectionCodeMndott", AcDbGeoCoordinateSystem::ProjectionCode::kProjectionCodeMndott)
        .value("kProjectionCodeModpc", AcDbGeoCoordinateSystem::ProjectionCode::kProjectionCodeModpc)
        .value("kProjectionCodeMollweid", AcDbGeoCoordinateSystem::ProjectionCode::kProjectionCodeMollweid)
        .value("kProjectionCodeMrcat", AcDbGeoCoordinateSystem::ProjectionCode::kProjectionCodeMrcat)
        .value("kProjectionCodeMrcatK", AcDbGeoCoordinateSystem::ProjectionCode::kProjectionCodeMrcatK)
        .value("kProjectionCodeMstero", AcDbGeoCoordinateSystem::ProjectionCode::kProjectionCodeMstero)
        .value("kProjectionCodeNeacyl", AcDbGeoCoordinateSystem::ProjectionCode::kProjectionCodeNeacyl)
        .value("kProjectionCodeNerth", AcDbGeoCoordinateSystem::ProjectionCode::kProjectionCodeNerth)
        .value("kProjectionCodeNzealand", AcDbGeoCoordinateSystem::ProjectionCode::kProjectionCodeNzealand)
        .value("kProjectionCodeOblqM", AcDbGeoCoordinateSystem::ProjectionCode::kProjectionCodeOblqM)
        .value("kProjectionCodeObqcyl", AcDbGeoCoordinateSystem::ProjectionCode::kProjectionCodeObqcyl)
        .value("kProjectionCodeOrtho", AcDbGeoCoordinateSystem::ProjectionCode::kProjectionCodeOrtho)
        .value("kProjectionCodeOstn02", AcDbGeoCoordinateSystem::ProjectionCode::kProjectionCodeOstn02)
        .value("kProjectionCodeOstn97", AcDbGeoCoordinateSystem::ProjectionCode::kProjectionCodeOstn97)
        .value("kProjectionCodeOstro", AcDbGeoCoordinateSystem::ProjectionCode::kProjectionCodeOstro)
        .value("kProjectionCodePlycn", AcDbGeoCoordinateSystem::ProjectionCode::kProjectionCodePlycn)
        .value("kProjectionCodePstro", AcDbGeoCoordinateSystem::ProjectionCode::kProjectionCodePstro)
        .value("kProjectionCodePstrosl", AcDbGeoCoordinateSystem::ProjectionCode::kProjectionCodePstrosl)
        .value("kProjectionCodeRskew", AcDbGeoCoordinateSystem::ProjectionCode::kProjectionCodeRskew)
        .value("kProjectionCodeRskewc", AcDbGeoCoordinateSystem::ProjectionCode::kProjectionCodeRskewc)
        .value("kProjectionCodeRskewo", AcDbGeoCoordinateSystem::ProjectionCode::kProjectionCodeRskewo)
        .value("kProjectionCodeRobinson", AcDbGeoCoordinateSystem::ProjectionCode::kProjectionCodeRobinson)
        .value("kProjectionCodeSinus", AcDbGeoCoordinateSystem::ProjectionCode::kProjectionCodeSinus)
        .value("kProjectionCodeSotrm", AcDbGeoCoordinateSystem::ProjectionCode::kProjectionCodeSotrm)
        .value("kProjectionCodeSstro", AcDbGeoCoordinateSystem::ProjectionCode::kProjectionCodeSstro)
        .value("kProjectionCodeSwiss", AcDbGeoCoordinateSystem::ProjectionCode::kProjectionCodeSwiss)
        .value("kProjectionCodeSys34", AcDbGeoCoordinateSystem::ProjectionCode::kProjectionCodeSys34)
        .value("kProjectionCodeSys34_99", AcDbGeoCoordinateSystem::ProjectionCode::kProjectionCodeSys34_99)
        .value("kProjectionCodeTeacyl", AcDbGeoCoordinateSystem::ProjectionCode::kProjectionCodeTeacyl)
        .value("kProjectionCodeTm", AcDbGeoCoordinateSystem::ProjectionCode::kProjectionCodeTm)
        .value("kProjectionCodeTrmeraf", AcDbGeoCoordinateSystem::ProjectionCode::kProjectionCodeTrmeraf)
        .value("kProjectionCodeTrmrkrg", AcDbGeoCoordinateSystem::ProjectionCode::kProjectionCodeTrmrkrg)
        .value("kProjectionCodeTrmrs", AcDbGeoCoordinateSystem::ProjectionCode::kProjectionCodeTrmrs)
        .value("kProjectionCodeVdgrntn", AcDbGeoCoordinateSystem::ProjectionCode::kProjectionCodeVdgrntn)
        .value("kProjectionCodeWccsl", AcDbGeoCoordinateSystem::ProjectionCode::kProjectionCodeWccsl)
        .value("kProjectionCodeWccst", AcDbGeoCoordinateSystem::ProjectionCode::kProjectionCodeWccst)
        .value("kProjectionCodeUtm", AcDbGeoCoordinateSystem::ProjectionCode::kProjectionCodeUtm)
        .value("kProjectionCodeWinkl", AcDbGeoCoordinateSystem::ProjectionCode::kProjectionCodeWinkl)
        .value("kProjectionCodeNrthsrt", AcDbGeoCoordinateSystem::ProjectionCode::kProjectionCodeNrthsrt)
        .value("kProjectionCodeLmbrtaf", AcDbGeoCoordinateSystem::ProjectionCode::kProjectionCodeLmbrtaf)
        .value("kProjectionCodeSys34_01", AcDbGeoCoordinateSystem::ProjectionCode::kProjectionCodeSys34_01)
        .value("kProjectionCodeEdcylE", AcDbGeoCoordinateSystem::ProjectionCode::kProjectionCodeEdcylE)
        .value("kProjectionCodePlateCarree", AcDbGeoCoordinateSystem::ProjectionCode::kProjectionCodePlateCarree)
        .value("kProjectionCodePvMercator", AcDbGeoCoordinateSystem::ProjectionCode::kProjectionCodePvMercator)
        .export_values()
        ;
    enum_<AcDbGeoCoordinateSystem::Unit>("GeoCoordinateSystemUnit")
        .value("kUnitUnknown", AcDbGeoCoordinateSystem::Unit::kUnitUnknown)
        .value("kUnitMeter", AcDbGeoCoordinateSystem::Unit::kUnitMeter)
        .value("kUnitFoot", AcDbGeoCoordinateSystem::Unit::kUnitFoot)
        .value("kUnitInch", AcDbGeoCoordinateSystem::Unit::kUnitInch)
        .value("kUnitIFoot", AcDbGeoCoordinateSystem::Unit::kUnitIFoot)
        .value("kUnitClarkeFoot", AcDbGeoCoordinateSystem::Unit::kUnitClarkeFoot)
        .value("kUnitIInch", AcDbGeoCoordinateSystem::Unit::kUnitIInch)
        .value("kUnitCentimeter", AcDbGeoCoordinateSystem::Unit::kUnitCentimeter)
        .value("kUnitKilometer", AcDbGeoCoordinateSystem::Unit::kUnitKilometer)
        .value("kUnitYard", AcDbGeoCoordinateSystem::Unit::kUnitYard)
        .value("kUnitSearsYard", AcDbGeoCoordinateSystem::Unit::kUnitSearsYard)
        .value("kUnitMile", AcDbGeoCoordinateSystem::Unit::kUnitMile)
        .value("kUnitIYard", AcDbGeoCoordinateSystem::Unit::kUnitIYard)
        .value("kUnitIMile", AcDbGeoCoordinateSystem::Unit::kUnitIMile)
        .value("kUnitKnot", AcDbGeoCoordinateSystem::Unit::kUnitKnot)
        .value("kUnitNautM", AcDbGeoCoordinateSystem::Unit::kUnitNautM)
        .value("kUnitLat66", AcDbGeoCoordinateSystem::Unit::kUnitLat66)
        .value("kUnitLat83", AcDbGeoCoordinateSystem::Unit::kUnitLat83)
        .value("kUnitDecimeter", AcDbGeoCoordinateSystem::Unit::kUnitDecimeter)
        .value("kUnitMillimeter", AcDbGeoCoordinateSystem::Unit::kUnitMillimeter)
        .value("kUnitDekameter", AcDbGeoCoordinateSystem::Unit::kUnitDekameter)
        .value("kUnitHectometer", AcDbGeoCoordinateSystem::Unit::kUnitHectometer)
        .value("kUnitGermanMeter", AcDbGeoCoordinateSystem::Unit::kUnitGermanMeter)
        .value("kUnitCaGrid", AcDbGeoCoordinateSystem::Unit::kUnitCaGrid)
        .value("kUnitClarkeChain", AcDbGeoCoordinateSystem::Unit::kUnitClarkeChain)
        .value("kUnitGunterChain", AcDbGeoCoordinateSystem::Unit::kUnitGunterChain)
        .value("kUnitBenoitChain", AcDbGeoCoordinateSystem::Unit::kUnitBenoitChain)
        .value("kUnitSearsChain", AcDbGeoCoordinateSystem::Unit::kUnitSearsChain)
        .value("kUnitClarkeLink", AcDbGeoCoordinateSystem::Unit::kUnitClarkeLink)
        .value("kUnitGunterLink", AcDbGeoCoordinateSystem::Unit::kUnitGunterLink)
        .value("kUnitBenoitLink", AcDbGeoCoordinateSystem::Unit::kUnitBenoitLink)
        .value("kUnitSearsLink", AcDbGeoCoordinateSystem::Unit::kUnitSearsLink)
        .value("kUnitRod", AcDbGeoCoordinateSystem::Unit::kUnitRod)
        .value("kUnitPerch", AcDbGeoCoordinateSystem::Unit::kUnitPerch)
        .value("kUnitPole", AcDbGeoCoordinateSystem::Unit::kUnitPole)
        .value("kUnitFurlong", AcDbGeoCoordinateSystem::Unit::kUnitFurlong)
        .value("kUnitRood", AcDbGeoCoordinateSystem::Unit::kUnitRood)
        .value("kUnitCapeFoot", AcDbGeoCoordinateSystem::Unit::kUnitCapeFoot)
        .value("kUnitBrealey", AcDbGeoCoordinateSystem::Unit::kUnitBrealey)
        .value("kUnitSearsFoot", AcDbGeoCoordinateSystem::Unit::kUnitSearsFoot)
        .value("kUnitGoldCoastFoot", AcDbGeoCoordinateSystem::Unit::kUnitGoldCoastFoot)
        .value("kUnitMicroInch", AcDbGeoCoordinateSystem::Unit::kUnitMicroInch)
        .value("kUnitIndianYard", AcDbGeoCoordinateSystem::Unit::kUnitIndianYard)
        .value("kUnitIndianFoot", AcDbGeoCoordinateSystem::Unit::kUnitIndianFoot)
        .value("kUnitIndianFt37", AcDbGeoCoordinateSystem::Unit::kUnitIndianFt37)
        .value("kUnitIndianFt62", AcDbGeoCoordinateSystem::Unit::kUnitIndianFt62)
        .value("kUnitIndianFt75", AcDbGeoCoordinateSystem::Unit::kUnitIndianFt75)
        .value("kUnitIndianYd37", AcDbGeoCoordinateSystem::Unit::kUnitIndianYd37)
        .value("kUnitDecameter", AcDbGeoCoordinateSystem::Unit::kUnitDecameter)
        .value("kUnitInternationalChain", AcDbGeoCoordinateSystem::Unit::kUnitInternationalChain)
        .value("kUnitInternationalLink", AcDbGeoCoordinateSystem::Unit::kUnitInternationalLink)
        .value("kUnitDegree", AcDbGeoCoordinateSystem::Unit::kUnitDegree)
        .value("kUnitGrad", AcDbGeoCoordinateSystem::Unit::kUnitGrad)
        .value("kUnitGrade", AcDbGeoCoordinateSystem::Unit::kUnitGrade)
        .value("kUnitMapInfo", AcDbGeoCoordinateSystem::Unit::kUnitMapInfo)
        .value("kUnitMil", AcDbGeoCoordinateSystem::Unit::kUnitMil)
        .value("kUnitMinute", AcDbGeoCoordinateSystem::Unit::kUnitMinute)
        .value("kUnitRadian", AcDbGeoCoordinateSystem::Unit::kUnitRadian)
        .value("kUnitSecond", AcDbGeoCoordinateSystem::Unit::kUnitSecond)
        .value("kUnitDecisec", AcDbGeoCoordinateSystem::Unit::kUnitDecisec)
        .value("kUnitCentisec", AcDbGeoCoordinateSystem::Unit::kUnitCentisec)
        .value("kUnitMillisec", AcDbGeoCoordinateSystem::Unit::kUnitMillisec)
        .export_values()
        ;
};

void initPyDbModule()
{
    PyImport_AppendInittab(PyDbNamespace, &PyInit_PyDb);
}
