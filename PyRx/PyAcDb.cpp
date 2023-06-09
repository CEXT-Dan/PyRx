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


using namespace boost::python;

static PyDbDatabase curPyDb()
{
    return PyDbDatabase(acdbHostApplicationServices()->workingDatabase(), false);
}

std::string AcDbExtents2dToString(const AcDbExtents2d& p)
{
    auto mi = p.minPoint();
    auto ma = p.maxPoint();
    return std::format("(({:.14f},{:.14f}),({:.14f},{:.14f}))", mi.x, mi.y, ma.x, ma.y);
}

std::string AcDbExtents2dToStringRepr(const AcDbExtents2d& p)
{
    auto mi = p.minPoint();
    auto ma = p.maxPoint();
    return std::format("<{}.Extents2d(({:.14f},{:.14f}),({:.14f},{:.14f}))>", PyGeNamespace, mi.x, mi.y, ma.x, ma.y);
}


void makeAcDbExtents2dWrapper()
{
    class_<AcDbExtents2d>("Extents2d")
        .def(init<>())
        .def(init<const AcDbExtents2d&>())
        .def(init<const AcGePoint2d&, const AcGePoint2d&>())
        .def("minPoint", &AcDbExtents2d::minPoint)
        .def("maxPoint", &AcDbExtents2d::maxPoint)
        .def("set", &AcDbExtents2d::set)
#ifndef BRXAPP
        .def("addPoint", &AcDbExtents2d::addPoint)
        .def("addExt", &AcDbExtents2d::addExt)
        .def("expandBy", &AcDbExtents2d::expandBy)
        .def("transformBy", &AcDbExtents2d::transformBy)
#endif // !BRXAPP
        .def("__str__", &AcDbExtents2dToString)
        .def("__repr__", &AcDbExtents2dToStringRepr)
        ;
}

std::string AcDbExtentsToString(const AcDbExtents& p)
{
    auto mi = p.minPoint();
    auto ma = p.maxPoint();
    return std::format("(({:.14f},{:.14f},{:.14f}),({:.14f},{:.14f},{:.14f}))", mi.x, mi.y, mi.z, ma.x, ma.y, ma.z);
}

std::string AcDbExtentsToStringRepr(const AcDbExtents& p)
{
    auto mi = p.minPoint();
    auto ma = p.maxPoint();
    return std::format("<{}.Extents(({:.14f},{:.14f},{:.14f}),({:.14f},{:.14f},{:.14f}))>", PyGeNamespace, mi.x, mi.y, mi.z, ma.x, ma.y, ma.z);
}

void makeAcDbExtentsWrapper()
{
    class_<AcDbExtents>("Extents")
        .def(init<>())
        .def(init<const AcDbExtents&>())
        .def(init<const AcGePoint3d&, const AcGePoint3d&>())
        .def("minPoint", &AcDbExtents::minPoint)
        .def("maxPoint", &AcDbExtents::maxPoint)
        .def("set", &AcDbExtents::set)
        .def("addPoint", &AcDbExtents::addPoint)
        .def("addExt", &AcDbExtents::addExt)
        .def("expandBy", &AcDbExtents::expandBy)
        .def("transformBy", &AcDbExtents::transformBy)
        .def("__str__", &AcDbExtentsToString)
        .def("__repr__", &AcDbExtentsToStringRepr)
        //.def("addBlockExt", &AcDbExtents::addBlockExt) //TODO
        ;
}

BOOST_PYTHON_MODULE(PyDb)
{
    docstring_options local_docstring_options(true, true, true);

    //create in class order!
    makePyDbSubentIdWrapper();
    makeAcDbExtents2dWrapper();
    makeAcDbExtentsWrapper();
    makeAcCmColorWrapper();
    makeAcCmEntityColorWrapper();
    makeAcCmTransparencyWrapper();
    makeAcDbObjectIdWrapper();
    makePyDbHandleWrapper();
    makePyDbXrefObjectIdWrapper();
    makeAdsNameWrapper();
    makeAcDbObjectWrapper();
    makeAcDbFieldtWrapper();
    makeAcDbEntityWrapper();
    makeAcDbBlockBeginWrapper();
    makeAcDbBlockEndWrapper();
    makeAcDbSequenceEndWrapper();
    makePyDbXrecordWrapper();

#ifndef ZRXAPP
    makePyDbObjectContextWrapper();
    makePyDbAnnotationScaleWrapper();
#endif

    makeAcDbTableStyleWrapper();
    makePyDbMLeaderStyleWrapper();
    makPyDbMlineStyleWrapper();

    makePyDbTextWrapper();
    makePyDbAttributeDefinitionWrapper();
    makePyDbAttributeWrapper();
    makeDbBlockReferenceWrapper();
    makePyDbDynBlockReferenceWrapper();
    makeDbMInsertBlockeWrapper();
    makePyDbMTextWrapper();
    makeyDbTableWrapper();
    makePyDbViewportWrapper();

    makeAcDbVertexWrapper();
    makePyDb2dVertexWrapper();
    makePyAcDb3dPolylineVertexWrapper();
    makePyAcDbPolygonMeshVertexWrapper();
    makePyDbPolyFaceMeshVertexWrapper();
    makePyAcDbFaceRecordWrapper();
    makePyDbCurveWrapper();
    makePyDbPointWrapper();
    makePyDb2dPolylineWrapper();
    makePyDb3dPolylineWrapper();
    makePyDbArcWrapper();
    makPyDbCircleWrapper();
    makPyDbLineWrapper();
    makPyDbPolylineWrapper();
    makPyDbFaceWrapper();
    makPyDbFcfWrapper();
    makPyDbMlineWrapper();
    makePyDbHatchWrapper();

    makeAcDbDictionaryWrapper();

    makeAcDbSymbolTableWrapper();
    makeAcDbSymbolTableRecordWrapper();
    makePyDbDimStyleTableWrapper();
    makeAcDbDimStyleTableRecordWrapper();
    makePyDbBlockTableWrapper();
    makeAcDbBlockTableRecordWrapper();
    makePyDbTextStyleTableWrapper();
    makePyDbTextStyleTableRecordWrapper();
    makePyDbUCSTableWrapper();
    makePyDbUCSTableRecordWrapper();
    makePyDbRegAppTableWrapper();
    makePyDbRegAppTableRecordWrapper();
    makePyDbLinetypeTableWrapper();
    makePyDbLinetypeTableRecordWrapper();
    makePyDbLayerTableWrapper();
    makeAcDbLayerTableRecordWrapper();
    makePyDbAbstractViewTableWrapper();
    makePyDbAbstractViewTableRecordWrapper();
    makePyDbViewportTableRecordWrapper();
    makePyDbViewTableRecordWrapper();

    makeAcDbDatabaseWrapper();
    makeAcDbHostApplicationServicesWrapper();
    makeAPyDbSymUtilServicesWrapper();

    makePyDb3dSolidWrapper();
    makePyDbRegionWrapper();
    makeAcDbBodyWrapper();
    makePyDbRevolveOptionsWrapper();
    makePyDbSweepOptionsWrapper();
    makePyDbSurfaceWrapper();
    makeAcDbExtrudedSurfaceWrapper();
    makeAcDbLoftedSurfaceWrapper();
    makePyDbNurbSurfaceWrapper();
    makePyDbPlaneSurfaceWrapper();
    makePyDbRevolvedSurfaceWrapper();
    makePyDbSweptSurfaceWrapper();

    makePyDbDimensionWrapper();
    makePyDb2LineAngularDimensionWrapper();
    makeAcDb3PointAngularDimensionWrapper();
    makeAlignedDimensionWrapper();
    makeArcDimensionWrapper();
    makeDiametricDimensionWrapper();
    makeOrdinateDimensionWrapper();
    makeRadialDimensionWrapper();
    makeRadialDimensionLargeWrapper();
    makeRotatedDimensionWrapper();

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

    makePyDbIdMappingWrapper();

    makePyDbTransactionManager();
    makePyTransaction();

    makePyDbPlotSettingsWrapper();
    makePyDbLayoutWrapper();
    makePyDbLayoutManagerWrapper();

    makePyDbEvalVariantWrapper();
    makePyDbDynBlockReferencePropertyWrapper();

    makeDbCoreWrapper();//LAST?


    def("curDb", curPyDb);

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
    enum_<AcDb::TextVertMode>("TextHorzMode")
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
#ifndef BRXAPP
        .value("kDxfVertexIdentifier", AcDb::kDxfVertexIdentifier)
#endif // !BRXAPP
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
#ifndef BRXAPP
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
#ifndef BRXAPP
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
};

void initPyDbModule()
{
    PyImport_AppendInittab(PyDbNamespace, &PyInit_PyDb);
}
