#pragma once

#ifdef PYRXDEBUG

#include <atlbase.h>
#include <atlsafe.h>

#pragma comment( lib , "propsys.lib" )

#if defined(_BRXTARGET) && (_BRXTARGET <= 250)
#import "axbricscaddb1.tlb" raw_interfaces_only, raw_native_types, no_namespace, named_guids
#import "axbricscadapp1.tlb" raw_interfaces_only, raw_native_types, no_namespace, named_guids
#endif

#if defined(_ARXTARGET) && (_ARXTARGET <= 243)
#import "acax24ENU.tlb"  raw_interfaces_only, raw_native_types, no_namespace, named_guids
#endif

#if defined(_ARXTARGET) && (_ARXTARGET == 250)
#import "acax25ENU.tlb"  raw_interfaces_only, raw_native_types, no_namespace, named_guids
#endif

#if defined(_ZRXTARGET) && (_ZRXTARGET == 240)
#import "zwcad21.tlb"  raw_interfaces_only, raw_native_types, no_namespace, named_guids
#endif

#if defined(_ZRXTARGET) && (_ZRXTARGET == 250)
#import "zwcad25.tlb"  raw_interfaces_only, raw_native_types, no_namespace, named_guids
#endif

#if defined(_GRXTARGET) && (_GRXTARGET == 240)
#import "acax.tlb"  raw_interfaces_only, raw_native_types, no_namespace, named_guids
#endif

#if defined(_GRXTARGET) && (_GRXTARGET == 250)
#import "acax.tlb"  raw_interfaces_only, raw_native_types, no_namespace, named_guids
#endif

#if defined(_ZRXTARGET)
// enums
#define AcZoomScaleType ZcZoomScaleType
#define AcWindowState   ZcWindowState
#define AcColorMethod   ZcColorMethod
#define AcColor         ZcColor
#define AcSectionGeneration ZcSectionGeneration
//

#define IAcadApplicationPtr IZcadApplicationPtr
#define IAcadApplication IZcadApplication
#define IAcadDocumentsPtr IZcadDocumentsPtr
#define IAcadDocuments IZcadDocuments
#define IAcadDatabasePtr IZcadDatabasePtr
#define IAcadDatabase IZcadDatabase
#define IAcadDocumentPtr IZcadDocumentPtr
#define IAcadDocument IZcadDocument
#define IAcadStatePtr IZcadStatePtr
#define IAcadState IZcadState
#define IAcadObjectPtr IZcadObjectPtr
#define IAcadObject IZcadObject
#define IAcadEntityPtr IZcadEntityPtr
#define IAcadEntity IZcadEntity
#define IAcadAcCmColorPtr IZcadZcCmColorPtr
#define IAcadAcCmColor IZcadZcCmColor
#define IAcadHyperlinkPtr IZcadHyperlinkPtr
#define IAcadHyperlink IZcadHyperlink
#define IAcadHyperlinksPtr IZcadHyperlinksPtr
#define IAcadHyperlinks IZcadHyperlinks
#define IAcadSectionTypeSettingsPtr IZcadSectionTypeSettingsPtr
#define IAcadSectionTypeSettings IZcadSectionTypeSettings
#define IAcadDatabasePreferencesPtr IZcadDatabasePreferencesPtr
#define IAcadDatabasePreferences IZcadDatabasePreferences
#define IAcadSummaryInfoPtr IZcadSummaryInfoPtr
#define IAcadSummaryInfo IZcadSummaryInfo
#define IAcadDynamicBlockReferencePropertyPtr IZcadDynamicBlockReferencePropertyPtr
#define IAcadDynamicBlockReferenceProperty IZcadDynamicBlockReferenceProperty
#define IAcadIdPairPtr IZcadIdPairPtr
#define IAcadIdPair IZcadIdPair
#define IAcadShadowDisplayPtr IZcadShadowDisplayPtr
#define IAcadShadowDisplay IZcadShadowDisplay
#define IAcadSubEntityPtr IZcadSubEntityPtr
#define IAcadSubEntity IZcadSubEntity
#define IAcadMLeaderLeaderPtr IZcadMLeaderLeaderPtr
#define IAcadMLeaderLeader IZcadMLeaderLeader
#define IAcadSubEntSolidFacePtr IZcadSubEntSolidFacePtr
#define IAcadSubEntSolidFace IZcadSubEntSolidFace
#define IAcadSubDMeshFacePtr IZcadSubDMeshFacePtr
#define IAcadSubDMeshFace IZcadSubDMeshFace
#define IAcadSubDMeshEdgePtr IZcadSubDMeshEdgePtr
#define IAcadSubDMeshEdge IZcadSubDMeshEdge
#define IAcadSubDMeshVertexPtr IZcadSubDMeshVertexPtr
#define IAcadSubDMeshVertex IZcadSubDMeshVertex
#define IAcadSecurityParamsPtr IZcadSecurityParamsPtr
#define IAcadSecurityParams IZcadSecurityParams
#define IAcadUtilityPtr IZcadUtilityPtr
#define IAcadUtility IZcadUtility
#define IAcad3DFacePtr IZcad3DFacePtr
#define IAcad3DFace IZcad3DFace
#define IAcadPolygonMeshPtr IZcadPolygonMeshPtr
#define IAcadPolygonMesh IZcadPolygonMesh
#define IAcad3DPolylinePtr IZcad3DPolylinePtr
#define IAcad3DPolyline IZcad3DPolyline
#define IAcadArcPtr IZcadArcPtr
#define IAcadArc IZcadArc
#define IAcadAttributePtr IZcadAttributePtr
#define IAcadAttribute IZcadAttribute
#define IAcadRegionPtr IZcadRegionPtr
#define IAcadRegion IZcadRegion
#define IAcad3DSolidPtr IZcad3DSolidPtr
#define IAcad3DSolid IZcad3DSolid
#define IAcadCirclePtr IZcadCirclePtr
#define IAcadCircle IZcadCircle
#define IAcadDimensionPtr IZcadDimensionPtr
#define IAcadDimension IZcadDimension
#define IAcadDimAlignedPtr IZcadDimAlignedPtr
#define IAcadDimAligned IZcadDimAligned
#define IAcadDimAngularPtr IZcadDimAngularPtr
#define IAcadDimAngular IZcadDimAngular
#define IAcadDimDiametricPtr IZcadDimDiametricPtr
#define IAcadDimDiametric IZcadDimDiametric
#define IAcadDimRotatedPtr IZcadDimRotatedPtr
#define IAcadDimRotated IZcadDimRotated
#define IAcadDimOrdinatePtr IZcadDimOrdinatePtr
#define IAcadDimOrdinate IZcadDimOrdinate
#define IAcadDimRadialPtr IZcadDimRadialPtr
#define IAcadDimRadial IZcadDimRadial
#define IAcadDim3PointAngularPtr IZcadDim3PointAngularPtr
#define IAcadDim3PointAngular IZcadDim3PointAngular
#define IAcadDimArcLengthPtr IZcadDimArcLengthPtr
#define IAcadDimArcLength IZcadDimArcLength
#define IAcadDimRadialLargePtr IZcadDimRadialLargePtr
#define IAcadDimRadialLarge IZcadDimRadialLarge
#define IAcadEllipsePtr IZcadEllipsePtr
#define IAcadEllipse IZcadEllipse
#define IAcadLeaderPtr IZcadLeaderPtr
#define IAcadLeader IZcadLeader
#define IAcadMTextPtr IZcadMTextPtr
#define IAcadMText IZcadMText
#define IAcadPointPtr IZcadPointPtr
#define IAcadPoint IZcadPoint
#define IAcadLWPolylinePtr IZcadLWPolylinePtr
#define IAcadLWPolyline IZcadLWPolyline
#define IAcadPolylinePtr IZcadPolylinePtr
#define IAcadPolyline IZcadPolyline
#define IAcadRayPtr IZcadRayPtr
#define IAcadRay IZcadRay
#define IAcadShapePtr IZcadShapePtr
#define IAcadShape IZcadShape
#define IAcadSolidPtr IZcadSolidPtr
#define IAcadSolid IZcadSolid
#define IAcadSplinePtr IZcadSplinePtr
#define IAcadSpline IZcadSpline
#define IAcadTextPtr IZcadTextPtr
#define IAcadText IZcadText
#define IAcadTolerancetPtr IZcadTolerancetPtr
#define IAcadTolerance IZcadTolerance
#define IAcadTracePtr IZcadTracePtr
#define IAcadTrace IZcadTrace
#define IAcadXlinePtr IZcadXlinePtr
#define IAcadXline IZcadXline
#define IAcadBlockReferencePtr IZcadBlockReferencePtr
#define IAcadBlockReference IZcadBlockReference
#define IAcadHatchPtr IZcadHatchPtr
#define IAcadHatch IZcadHatch
#define IAcadRasterImagePtr IZcadRasterImagePtr
#define IAcadRasterImage IZcadRasterImage
#define IAcadLinePtr IZcadLinePtr
#define IAcadLine IZcadLine
#define IAcadPlotConfigurationPtr IZcadPlotConfigurationPtr
#define IAcadPlotConfiguration IZcadPlotConfiguration
#define IAcadSectionSettingsPtr IZcadSectionSettingsPtr
#define IAcadSectionSettings IZcadSectionSettings
#define IAcadViewPtr IZcadViewPtr
#define IAcadView IZcadView
#define IAcadGroupPtr IZcadGroupPtr
#define IAcadGroup IZcadGroup


#endif//_ZRXTARGET

#if defined(_GRXTARGET)
// enums
#define AcZoomScaleType GcZoomScaleType
//#define AcWindowState   GcWindowState
#define AcColorMethod   GcColorMethod
#define AcColor         GcColor
#define AcSectionGeneration GcSectionGeneration
//

#define IAcadApplicationPtr IGcadApplicationPtr
#define IAcadApplication IGcadApplication
#define IAcadDatabasePtr IGcadDatabasePtr
#define IAcadDatabase IGcadDatabase
#define IAcadDocumentsPtr IGcadDocumentsPtr
#define IAcadDocuments IGcadDocuments
#define IAcadDocumentPtr IGcadDocumentPtr
#define IAcadDocument IGcadDocument
#define IAcadStatePtr IGcadStatePtr
#define IAcadState IGcadState
#define IAcadObjectPtr IGcadObjectPtr
#define IAcadObject IGcadObject
#define IAcadEntityPtr IGcadEntityPtr
#define IAcadEntity IGcadEntity
#define IAcadAcCmColorPtr IGcadGcCmColorPtr
#define IAcadAcCmColor IGcadGcCmColor
#define IAcadHyperlinkPtr IGcadHyperlinkPtr
#define IAcadHyperlink IGcadHyperlink
#define IAcadHyperlinksPtr IGcadHyperlinksPtr
#define IAcadHyperlinks IGcadHyperlinks
#define IAcadSectionTypeSettingsPtr IGcadSectionTypeSettingsPtr
#define IAcadSectionTypeSettings IGcadSectionTypeSettings
#define IAcadDatabasePreferencesPtr IGcadDatabasePreferencesPtr
#define IAcadDatabasePreferences IGcadDatabasePreferences
#define IAcadSummaryInfoPtr IGcadSummaryInfoPtr
#define IAcadSummaryInfo IGcadSummaryInfo
#define IAcadDynamicBlockReferencePropertyPtr IGcadDynamicBlockReferencePropertyPtr
#define IAcadDynamicBlockReferenceProperty IGcadDynamicBlockReferenceProperty
#define IAcadIdPairPtr IGcadIdPairPtr
#define IAcadIdPair IGcadIdPair
#define IAcadShadowDisplayPtr IGcadShadowDisplayPtr
#define IAcadShadowDisplay IGcadShadowDisplay
#define IAcadSubEntityPtr IGcadSubEntityPtr
#define IAcadSubEntity IGcadSubEntity
#define IAcadMLeaderLeaderPtr IGcadMLeaderLeaderPtr
#define IAcadMLeaderLeader IGcadMLeaderLeader
#define IAcadSubEntSolidFacePtr IGcadSubEntSolidFacePtr
#define IAcadSubEntSolidFace IGcadSubEntSolidFace
#define IAcadSubDMeshFacePtr IGcadSubDMeshFacePtr
#define IAcadSubDMeshFace IGcadSubDMeshFace
#define IAcadSubDMeshEdgePtr IGcadSubDMeshEdgePtr
#define IAcadSubDMeshEdge IGcadSubDMeshEdge
#define IAcadSubDMeshVertexPtr IGcadSubDMeshVertexPtr
#define IAcadSubDMeshVertex IGcadSubDMeshVertex
#define IAcadSecurityParamsPtr IGcadSecurityParamsPtr
#define IAcadSecurityParams IGcadSecurityParams
#define IAcadUtilityPtr IGcadUtilityPtr
#define IAcadUtility IGcadUtility
#define IAcad3DFacePtr IGcad3DFacePtr
#define IAcad3DFace IGcad3DFace
#define IAcadPolygonMeshPtr IGcadPolygonMeshPtr
#define IAcadPolygonMesh IGcadPolygonMesh
#define IAcad3DPolylinePtr IGcad3DPolylinePtr
#define IAcad3DPolyline IGcad3DPolyline
#define IAcadArcPtr IGcadArcPtr
#define IAcadArc IGcadArc
#define IAcadAttributePtr IGcadAttributePtr
#define IAcadAttribute IGcadAttribute
#define IAcadRegionPtr IGcadRegionPtr
#define IAcadRegion IGcadRegion
#define IAcad3DSolidPtr IGcad3DSolidPtr
#define IAcad3DSolid IGcad3DSolid
#define IAcadCirclePtr IGcadCirclePtr
#define IAcadCircle IGcadCircle
#define IAcadDimensionPtr IGcadDimensionPtr
#define IAcadDimension IGcadDimension
#define IAcadDimAlignedPtr IGcadDimAlignedPtr
#define IAcadDimAligned IGcadDimAligned
#define IAcadDimAngularPtr IGcadDimAngularPtr
#define IAcadDimAngular IGcadDimAngular
#define IAcadDimDiametricPtr IGcadDimDiametricPtr
#define IAcadDimDiametric IGcadDimDiametric
#define IAcadDimRotatedPtr IGcadDimRotatedPtr
#define IAcadDimRotated IGcadDimRotated
#define IAcadDimOrdinatePtr IGcadDimOrdinatePtr
#define IAcadDimOrdinate IGcadDimOrdinate
#define IAcadDimRadialPtr IGcadDimRadialPtr
#define IAcadDimRadial IGcadDimRadial
#define IAcadDim3PointAngularPtr IGcadDim3PointAngularPtr
#define IAcadDim3PointAngular IGcadDim3PointAngular
#define IAcadDimArcLengthPtr IGcadDimArcLengthPtr
#define IAcadDimArcLength IGcadDimArcLength
#define IAcadDimRadialLargePtr IGcadDimRadialLargePtr
#define IAcadDimRadialLarge IGcadDimRadialLarge
#define IAcadEllipsePtr IGcadEllipsePtr
#define IAcadEllipse IGcadEllipse
#define IAcadLeaderPtr IGcadLeaderPtr
#define IAcadLeader IGcadLeader
#define IAcadMTextPtr IGcadMTextPtr
#define IAcadMText IGcadMText
#define IAcadPointPtr IGcadPointPtr
#define IAcadPoint IGcadPoint
#define IAcadLWPolylinePtr IGcadLWPolylinePtr
#define IAcadLWPolyline IGcadLWPolyline
#define IAcadPolylinePtr IGcadPolylinePtr
#define IAcadPolyline IGcadPolyline
#define IAcadRayPtr IGcadRayPtr
#define IAcadRay IGcadRay
#define IAcadShapePtr IGcadShapePtr
#define IAcadShape IGcadShape
#define IAcadSolidPtr IGcadSolidPtr
#define IAcadSolid IGcadSolid
#define IAcadSplinePtr IGcadSplinePtr
#define IAcadSpline IGcadSpline
#define IAcadTextPtr IGcadTextPtr
#define IAcadText IGcadText
#define IAcadTolerancetPtr IGcadTolerancetPtr
#define IAcadTolerance IGcadTolerance
#define IAcadTracePtr IGcadTracePtr
#define IAcadTrace IGcadTrace
#define IAcadXlinePtr IGcadXlinePtr
#define IAcadXline IGcadXline
#define IAcadBlockReferencePtr IGcadBlockReferencePtr
#define IAcadBlockReference IGcadBlockReference
#define IAcadHatchPtr IGcadHatchPtr
#define IAcadHatch IGcadHatch
#define IAcadRasterImagePtr IGcadRasterImagePtr
#define IAcadRasterImage IGcadRasterImage
#define IAcadLinePtr IGcadLinePtr
#define IAcadLine IGcadLine
#define IAcadPlotConfigurationPtr IGcadPlotConfigurationPtr
#define IAcadPlotConfiguration IGcadPlotConfiguration
#define IAcadSectionSettingsPtr IGcadSectionSettingsPtr
#define IAcadSectionSettings IGcadSectionSettings
#define IAcadViewPtr IGcadViewPtr
#define IAcadView IGcadView
#define IAcadGroupPtr IGcadGroupPtr
#define IAcadGroup IGcadGroup



#endif//_GRXTARGET

#endif