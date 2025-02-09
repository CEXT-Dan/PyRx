#pragma once

#pragma pack (push, 8)

#include <atlbase.h>
#include <atlsafe.h>
#include "propvarutil.h"
#include "PyAcAxCommon.h"

#pragma comment( lib , "propsys.lib" )

#if defined(_BRXTARGET) && (_BRXTARGET <= 250)
#import "axbricscaddb1.tlb" raw_interfaces_only, raw_native_types, no_namespace, named_guids
#import "axbricscadapp1.tlb" raw_interfaces_only, raw_native_types, no_namespace, named_guids
#endif

#if defined(_ARXTARGET) && (_ARXTARGET <= 243)
#import "acax24ENU.tlb"  raw_interfaces_only, raw_native_types, no_namespace, named_guids
#endif

#if defined(_ARXTARGET) && (_ARXTARGET >= 250) && (_ARXTARGET <= 251)
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
//enums
#define AcZoomScaleType ZcZoomScaleType
#define AcWindowState   ZcWindowState
#define AcColorMethod   ZcColorMethod
#define AcColor         ZcColor
#define AcSectionGeneration ZcSectionGeneration
#define AcActiveSpace ZcActiveSpace
#define AcRegenType ZcRegenType
#define AcMenuGroupType ZcMenuGroupType
#define AcMenuFileType ZcMenuFileType
#define AcToolbarDockStatus ZcToolbarDockStatus
#define AcToolbarItemType ZcToolbarItemType
#define AcMenuItemTypePtr ZcMenuItemTypePtr
#define AcMenuItemType ZcMenuItemType
#define AcPreviewModePtr ZcPreviewModePtr
#define AcPreviewMode ZcPreviewMode
#define AcShadowDisplayTypePtr ZcShadowDisplayTypePtr
#define AcShadowDisplayType ZcShadowDisplayType
#define AcAlignmentPointAcquisition ZcAlignmentPointAcquisition
#define AcKeyboardAccelerator ZcKeyboardAccelerator
#define AcKeyboardPriority ZcKeyboardPriority
#define AcInsertUnits ZcInsertUnits
#define AcDrawingAreaSCMDefault ZcDrawingAreaSCMDefault
#define AcDrawingAreaSCMEdit ZcDrawingAreaSCMEdit
#define AcDrawingAreaSCMCommand ZcDrawingAreaSCMCommand
#define AcPrinterSpoolAlert ZcPrinterSpoolAlert
#define AcOleQuality ZcOleQuality
#define AcPlotPolicy ZcPlotPolicy
#define AcXRefDemandLoad ZcXRefDemandLoad
#define AcARXDemandLoad ZcZRXDemandLoad
#define AcProxyImage ZcProxyImage
#define AcSaveAsType ZcSaveAsType
#define AcTextFontStyle ZcTextFontStyle
#define AcLineWeight ZcLineWeight
#define AcPatternType ZcPatternType
#define AcDynamicBlockReferencePropertyUnitsType ZcDynamicBlockReferencePropertyUnitsType
#define AcAttributeMode ZcAttributeMode
#define AcLeaderType ZcLeaderType
#define AcBlockScaling ZcBlockScaling

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
#define IAcadGroupsPtr IZcadGroupsPtr
#define IAcadGroups IZcadGroups
#define IAcadDimStylePtr IZcadDimStylePtr
#define IAcadDimStyle IZcadDimStyle
#define IAcadDimStylesPtr IZcadDimStylesPtr
#define IAcadDimStyles IZcadDimStyles
#define IAcadLayerPtr IZcadLayerPtr
#define IAcadLayer IZcadLayer
#define IAcadLayersPtr IZcadLayersPtr
#define IAcadLayers IZcadLayers
#define IAcadLineTypePtr IZcadLineTypePtr
#define IAcadLineType IZcadLineType
#define IAcadLineTypesPtr IZcadLineTypesPtr
#define IAcadLineTypes IZcadLineTypes
#define IAcadXRecordPtr IZcadXRecordPtr
#define IAcadXRecord IZcadXRecord
#define IAcadDictionaryPtr IZcadDictionaryPtr
#define IAcadDictionary IZcadDictionary
#define IAcadDictionariesPtr IZcadDictionariesPtr
#define IAcadDictionaries IZcadDictionaries
#define IAcadRegisteredApplicationPtr IZcadRegisteredApplicationPtr
#define IAcadRegisteredApplication IZcadRegisteredApplication
#define IAcadRegisteredApplicationsPtr IZcadRegisteredApplicationsPtr
#define IAcadRegisteredApplications IZcadRegisteredApplications
#define IAcadTextStylePtr IZcadTextStylePtr
#define IAcadTextStyle IZcadTextStyle
#define IAcadTextStylesPtr IZcadTextStylesPtr
#define IAcadTextStyles IZcadTextStyles
#define IAcadUCSPtr IZcadUCSPtr
#define IAcadUCS IZcadUCS
#define IAcadUCSsPtr IZcadUCSsPtr
#define IAcadUCSs IZcadUCSs
#define IAcadObjectEventsPtr IZcadObjectEventsPtr
#define IAcadObjectEvents IZcadObjectEvents
#define IAcadViewsPtr IZcadViewsPtr
#define IAcadViews IZcadViews
#define IAcadViewportPtr IZcadViewportPtr
#define IAcadViewport IZcadViewport
#define IAcadViewportsPtr IZcadViewportsPtr
#define IAcadViewports IZcadViewports
#define IAcadPlotConfigurationsPtr IZcadPlotConfigurationsPtr
#define IAcadPlotConfigurations IZcadPlotConfigurations
#define IAcadSectionManagerPtr IZcadSectionManagerPtr
#define IAcadSectionManager IZcadSectionManager
#define IAcadMaterialPtr IZcadMaterialPtr
#define IAcadMaterial IZcadMaterial
#define IAcadMaterialsPtr IZcadMaterialsPtr
#define IAcadMaterials IZcadMaterials
#define IAcadTableStylePtr IZcadTableStylePtr
#define IAcadTableStyle IZcadTableStyle
#define IAcadMLeaderStylePtr IZcadMLeaderStylePtr
#define IAcadMLeaderStyle IZcadMLeaderStyle
#define IAcadBlockPtr IZcadBlockPtr
#define IAcadBlock IZcadBlock
#define IAcadBlocksPtr IZcadBlocksPtr
#define IAcadBlocks IZcadBlocks
#define IAcadLayoutsPtr IZcadLayoutsPtr
#define IAcadLayouts IZcadLayouts
#define IAcadSortentsTablePtr IZcadSortentsTablePtr
#define IAcadSortentsTable IZcadSortentsTable
#define IAcadPlotPtr IZcadPlotPtr
#define IAcadPlot IZcadPlot
#define IAcadPViewportPtr IZcadPViewportPtr
#define IAcadPViewport IZcadPViewport
#define IAcadSelectionSetsPtr IZcadSelectionSetsPtr
#define IAcadSelectionSets IZcadSelectionSets
#define IAcadSelectionSetPtr IZcadSelectionSetPtr
#define IAcadSelectionSet IZcadSelectionSet
#define IAcadLayoutPtr IZcadLayoutPtr
#define IAcadLayout IZcadLayout
#define IAcadMenuBarPtr IZcadMenuBarPtr
#define IAcadMenuBar IZcadMenuBar
#define IAcadMenuGroupsPtr IZcadMenuGroupsPtr
#define IAcadMenuGroups IZcadMenuGroups
#define IAcadPreferencesPtr IZcadPreferencesPtr
#define IAcadPreferences IZcadPreferences
#define IAcadPreferencesFilesPtr IZcadPreferencesFilesPtr
#define IAcadPreferencesFiles IZcadPreferencesFiles
#define IAcadPreferencesDisplayPtr IZcadPreferencesDisplayPtr
#define IAcadPreferencesDisplay IZcadPreferencesDisplay
#define IAcadPreferencesOpenSavePtr IZcadPreferencesOpenSavePtr
#define IAcadPreferencesOpenSave IZcadPreferencesOpenSave
#define IAcadPreferencesOutputPtr IZcadPreferencesOutputPtr
#define IAcadPreferencesOutput IZcadPreferencesOutput
#define IAcadPreferencesSystemPtr IZcadPreferencesSystemPtr
#define IAcadPreferencesSystem IZcadPreferencesSystem
#define IAcadPreferencesUserPtr IZcadPreferencesUserPtr
#define IAcadPreferencesUser IZcadPreferencesUser
#define IAcadPreferencesDraftingPtr IZcadPreferencesDraftingPtr
#define IAcadPreferencesDrafting IZcadPreferencesDrafting
#define IAcadPreferencesSelectionPtr IZcadPreferencesSelectionPtr
#define IAcadPreferencesSelection IZcadPreferencesSelection
#define IAcadPreferencesProfilesPtr IZcadPreferencesProfilesPtr
#define IAcadPreferencesProfiles IZcadPreferencesProfiles
#define IAcadMenuGroupPtr IZcadMenuGroupPtr
#define IAcadMenuGroup IZcadMenuGroup
#define IAcadPopupMenusPtr IZcadPopupMenusPtr
#define IAcadPopupMenus IZcadPopupMenus
#define IAcadPopupMenuPtr IZcadPopupMenuPtr
#define IAcadPopupMenu IZcadPopupMenu
#define IAcadToolbarsPtr IZcadToolbarsPtr
#define IAcadToolbars IZcadToolbars
#define IAcadToolbarPtr IZcadToolbarPtr
#define IAcadToolbar IZcadToolbar
#define IAcadToolbarItemPtr IZcadToolbarItemPtr
#define IAcadToolbarItem IZcadToolbarItem
#define IAcadPopupMenuItemPtr IZcadPopupMenuItemPtr
#define IAcadPopupMenuItem IZcadPopupMenuItem
#define IAcadModelSpacePtr IZcadModelSpacePtr
#define IAcadModelSpace IZcadModelSpace
#define IAcadPaperSpacePtr IZcadPaperSpacePtr
#define IAcadPaperSpace IZcadPaperSpace
#define IAcadMInsertBlockPtr IZcadMInsertBlockPtr
#define IAcadMInsertBlock IZcadMInsertBlock
#define IAcadPolyfaceMeshPtr IZcadPolyfaceMeshPtr
#define IAcadPolyfaceMesh IZcadPolyfaceMesh
#define IAcadMLinePtr IZcadMLinePtr
#define IAcadMLine IZcadMLine
#define IAcadExternalReferencePtr IZcadExternalReferencePtr
#define IAcadExternalReference IZcadExternalReference
#define IAcadTablePtr IZcadTablePtr
#define IAcadTable IZcadTable
#define IAcadSectionPtr IZcadSectionPtr
#define IAcadSection IZcadSection
#define IAcadMLeaderPtr IZcadMLeaderPtr
#define IAcadMLeader IZcadMLeader


#endif//_ZRXTARGET

#if defined(_GRXTARGET)
//enums
#define AcZoomScaleType GcZoomScaleType
#define AcWindowState   GcWindowState
#define AcColorMethod   GcColorMethod
#define AcColor         GcColor
#define AcSectionGeneration GcSectionGeneration
#define AcRegenType GcRegenType
#define AcMenuGroupType GcMenuGroupType
#define AcMenuFileType GcMenuFileType
#define AcToolbarDockStatus GcToolbarDockStatus
#define AcToolbarItemType GcToolbarItemType
#define AcMenuItemTypePtr GcMenuItemTypePtr
#define AcMenuItemType GcMenuItemType
#define AcPreviewModePtr GcPreviewModePtr
#define AcPreviewMode GcPreviewMode
#define AcShadowDisplayTypePtr GcShadowDisplayTypePtr
#define AcShadowDisplayType GcShadowDisplayType
#define AcAlignmentPointAcquisition GcAlignmentPointAcquisition
#define AcKeyboardAccelerator GcKeyboardAccelerator
#define AcKeyboardPriority GcKeyboardPriority
#define AcInsertUnits GcInsertUnits
#define AcDrawingAreaSCMDefault GcDrawingAreaSCMDefault
#define AcDrawingAreaSCMEdit GcDrawingAreaSCMEdit
#define AcDrawingAreaSCMCommand GcDrawingAreaSCMCommand
#define AcPrinterSpoolAlert GcPrinterSpoolAlert
#define AcOleQuality GcOleQuality
#define AcPlotPolicy GcPlotPolicy
#define AcXRefDemandLoad GcXRefDemandLoad
#define AcARXDemandLoad GcGRXDemandLoad
#define AcProxyImage GcProxyImage
#define AcSaveAsType GcSaveAsType
#define AcTextFontStyle GcTextFontStyle
#define AcLineWeight GcLineWeight
#define AcPatternType GcPatternType
#define AcDynamicBlockReferencePropertyUnitsType GcDynamicBlockReferencePropertyUnitsType
#define AcAttributeMode GcAttributeMode
#define AcLeaderType GcLeaderType
#define AcBlockScaling GcBlockScaling

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
#define IAcadGroupsPtr IGcadGroupsPtr
#define IAcadGroups IGcadGroups
#define IAcadDimStylePtr IGcadDimStylePtr
#define IAcadDimStyle IGcadDimStyle
#define IAcadDimStylesPtr IGcadDimStylesPtr
#define IAcadDimStyles IGcadDimStyles
#define IAcadLayerPtr IGcadLayerPtr
#define IAcadLayer IGcadLayer
#define IAcadLayersPtr IGcadLayersPtr
#define IAcadLayers IGcadLayers
#define IAcadLineTypePtr IGcadLineTypePtr
#define IAcadLineType IGcadLineType
#define IAcadLineTypesPtr IGcadLineTypesPtr
#define IAcadLineTypes IGcadLineTypes
#define IAcadXRecordPtr IGcadXRecordPtr
#define IAcadXRecord IGcadXRecord
#define IAcadDictionaryPtr IGcadDictionaryPtr
#define IAcadDictionary IGcadDictionary
#define IAcadDictionariesPtr IGcadDictionariesPtr
#define IAcadDictionaries IGcadDictionaries
#define IAcadRegisteredApplicationPtr IGcadRegisteredApplicationPtr
#define IAcadRegisteredApplication IGcadRegisteredApplication
#define IAcadRegisteredApplicationsPtr IGcadRegisteredApplicationsPtr
#define IAcadRegisteredApplications IGcadRegisteredApplications
#define IAcadTextStylePtr IGcadTextStylePtr
#define IAcadTextStyle IGcadTextStyle
#define IAcadTextStylesPtr IGcadTextStylesPtr
#define IAcadTextStyles IGcadTextStyles
#define IAcadUCSPtr IGcadUCSPtr
#define IAcadUCS IGcadUCS
#define IAcadUCSsPtr IGcadUCSsPtr
#define IAcadUCSs IGcadUCSs
#define IAcadObjectEventsPtr IGcadObjectEventsPtr
#define IAcadObjectEvents IGcadObjectEvents
#define IAcadViewsPtr IGcadViewsPtr
#define IAcadViews IGcadViews
#define IAcadViewportPtr IGcadViewportPtr
#define IAcadViewport IGcadViewport
#define IAcadViewportsPtr IGcadViewportsPtr
#define IAcadViewports IGcadViewports
#define IAcadPlotConfigurationsPtr IGcadPlotConfigurationsPtr
#define IAcadPlotConfigurations IGcadPlotConfigurations
#define IAcadSectionManagerPtr IGcadSectionManagerPtr
#define IAcadSectionManager IGcadSectionManager
#define IAcadMaterialPtr IGcadMaterialPtr
#define IAcadMaterial IGcadMaterial
#define IAcadMaterialsPtr IGcadMaterialsPtr
#define IAcadMaterials IGcadMaterials
#define IAcadTableStylePtr IGcadTableStylePtr
#define IAcadTableStyle IGcadTableStyle
#define IAcadMLeaderStylePtr IGcadMLeaderStylePtr
#define IAcadMLeaderStyle IGcadMLeaderStyle
#define IAcadBlockPtr IGcadBlockPtr
#define IAcadBlock IGcadBlock
#define IAcadBlocksPtr IGcadBlocksPtr
#define IAcadBlocks IGcadBlocks
#define IAcadLayoutsPtr IGcadLayoutsPtr
#define IAcadLayouts IGcadLayouts
#define IAcadSortentsTablePtr IGcadSortentsTablePtr
#define IAcadSortentsTable IGcadSortentsTable
#define IAcadPlotPtr IGcadPlotPtr
#define IAcadPlot IGcadPlot
#define IAcadPViewportPtr IGcadPViewportPtr
#define IAcadPViewport IGcadPViewport
#define IAcadSelectionSetsPtr IGcadSelectionSetsPtr
#define IAcadSelectionSets IGcadSelectionSets
#define IAcadSelectionSetPtr IGcadSelectionSetPtr
#define IAcadSelectionSet IGcadSelectionSet
#define IAcadLayoutPtr IGcadLayoutPtr
#define IAcadLayout IGcadLayout
#define IAcadMenuBarPtr IGcadMenuBarPtr
#define IAcadMenuBar IGcadMenuBar
#define IAcadMenuGroupsPtr IGcadMenuGroupsPtr
#define IAcadMenuGroups IGcadMenuGroups
#define IAcadPreferencesPtr IGcadPreferencesPtr
#define IAcadPreferences IGcadPreferences
#define IAcadPreferencesFilesPtr IGcadPreferencesFilesPtr
#define IAcadPreferencesFiles IGcadPreferencesFiles
#define IAcadPreferencesDisplayPtr IGcadPreferencesDisplayPtr
#define IAcadPreferencesDisplay IGcadPreferencesDisplay
#define IAcadPreferencesOpenSavePtr IGcadPreferencesOpenSavePtr
#define IAcadPreferencesOpenSave IGcadPreferencesOpenSave
#define IAcadPreferencesOutputPtr IGcadPreferencesOutputPtr
#define IAcadPreferencesOutput IGcadPreferencesOutput
#define IAcadPreferencesSystemPtr IGcadPreferencesSystemPtr
#define IAcadPreferencesSystem IGcadPreferencesSystem
#define IAcadPreferencesUserPtr IGcadPreferencesUserPtr
#define IAcadPreferencesUser IGcadPreferencesUser
#define IAcadPreferencesDraftingPtr IGcadPreferencesDraftingPtr
#define IAcadPreferencesDrafting IGcadPreferencesDrafting
#define IAcadPreferencesSelectionPtr IGcadPreferencesSelectionPtr
#define IAcadPreferencesSelection IGcadPreferencesSelection
#define IAcadPreferencesProfilesPtr IGcadPreferencesProfilesPtr
#define IAcadPreferencesProfiles IGcadPreferencesProfiles
#define IAcadMenuGroupPtr IGcadMenuGroupPtr
#define IAcadMenuGroup IGcadMenuGroup
#define IAcadPopupMenusPtr IGcadPopupMenusPtr
#define IAcadPopupMenus IGcadPopupMenus
#define IAcadPopupMenuPtr IGcadPopupMenuPtr
#define IAcadPopupMenu IGcadPopupMenu
#define IAcadToolbarsPtr IGcadToolbarsPtr
#define IAcadToolbars IGcadToolbars
#define IAcadToolbarPtr IGcadToolbarPtr
#define IAcadToolbar IGcadToolbar
#define IAcadToolbarItemPtr IGcadToolbarItemPtr
#define IAcadToolbarItem IGcadToolbarItem
#define IAcadPopupMenuItemPtr IGcadPopupMenuItemPtr
#define IAcadPopupMenuItem IGcadPopupMenuItem
#define IAcadModelSpacePtr IGcadModelSpacePtr
#define IAcadModelSpace IGcadModelSpace
#define IAcadPaperSpacePtr IGcadPaperSpacePtr
#define IAcadPaperSpace IGcadPaperSpace
#define IAcadMInsertBlockPtr IGcadMInsertBlockPtr
#define IAcadMInsertBlock IGcadMInsertBlock
#define IAcadPolyfaceMeshPtr IGcadPolyfaceMeshPtr
#define IAcadPolyfaceMesh IGcadPolyfaceMesh
#define IAcadMLinePtr IGcadMLinePtr
#define IAcadMLine IGcadMLine
#define IAcadExternalReferencePtr IGcadExternalReferencePtr
#define IAcadExternalReference IGcadExternalReference
#define IAcadTablePtr IGcadTablePtr
#define IAcadTable IGcadTable
#define IAcadSectionPtr IGcadSectionPtr
#define IAcadSection IGcadSection
#define IAcadMLeaderPtr IGcadMLeaderPtr
#define IAcadMLeader IGcadMLeader


#endif//_GRXTARGET

using wstringArray = std::vector<std::wstring>;
using CStringPair = std::pair<CString, CString>;
using Point3dMatrix = std::vector<std::vector<AcGePoint3d>>;

struct TypedVariant
{
    enum ETypeCode
    {
        kInt16,
        kInt32,
        kFloat,
        kHandle,
        kObjectId,
        kPoint3d,
        kString
    };
    int16_t code = 0;
    std::variant<int16_t, int32_t, double, AcDbHandle, AcDbObjectId, AcGePoint3d, std::wstring> variant;
};
using TypedVariants = std::vector<TypedVariant>;

inline bool CHECKHR(HRESULT hr, const std::source_location& src = std::source_location::current())
{
    if (hr != S_OK) [[unlikely]] {
        acutPrintf(_T("\nError Fail HR-0x%X %ls, %ls, %ld"), hr, utf8_to_wstr(src.file_name()).c_str(), utf8_to_wstr(src.function_name()).c_str(), src.line());
    }
    return hr == S_OK;
}

//helpers impl in PyAcadObjectImpl.cpp
[[nodiscard]] HRESULT VariantToAcDbObjectIdArray(VARIANT& var, AcDbObjectIdArray& ids);
[[nodiscard]] HRESULT AcDbObjectIdArrayToVariant(VARIANT& var, const AcDbObjectIdArray& ids);
[[nodiscard]] HRESULT VariantToAcGePoint3d(VARIANT& var, AcGePoint3d& val);
[[nodiscard]] HRESULT AcGePoint3dToVariant(VARIANT& var, const AcGePoint3d& pnt);
[[nodiscard]] HRESULT VariantToAcGeVector3d(VARIANT& var, AcGeVector3d& val);
[[nodiscard]] HRESULT AcGeVector3dToVariant(VARIANT& var, const AcGeVector3d& pnt);
[[nodiscard]] HRESULT AcGePoint2dsToVariant(VARIANT& var, const std::vector<AcGePoint2d>& points);
[[nodiscard]] HRESULT AcGePoint3dsToVariant(VARIANT& var, const std::vector<AcGePoint3d>& points);

#pragma pack (pop)
