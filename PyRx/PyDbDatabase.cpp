#include "stdafx.h"
#include "PyDbDatabase.h"
#include "PyDbObjectId.h"
#include "PyDbObject.h"
#include "PyDbTransactionManager.h"
#include "PyDbObjectContext.h"
#include "PyDbSymbolTableRecord.h"

using namespace boost::python;
//---------------------------------------------------------------------------------------------------
// makeAcDbDatabaseWrapper
void makePyDbDatabaseWrapper()
{
    PyDocString DS("Database");
    class_<PyDbDatabase, bases<PyRxObject>>("Database")
        .def(init<>())
        .def(init<bool, bool>(DS.ARGS({ "buildDefaultDrawing : bool=True", "noDocument: bool=False" })))
        .def("addObject", &PyDbDatabase::addAcDbObject, DS.ARGS({ "object : DbObject" }))
        .def("angbase", &PyDbDatabase::angbase, DS.ARGS())
        .def("angdir", &PyDbDatabase::angdir, DS.ARGS())
        .def("annoAllVisible", &PyDbDatabase::annoAllVisible, DS.ARGS())
        .def("annotativeDwg", &PyDbDatabase::annotativeDwg, DS.ARGS())
        .def("approxNumObjects", &PyDbDatabase::approxNumObjects, DS.ARGS())
        .def("attmode", &PyDbDatabase::attmode, DS.ARGS())
        .def("aunits", &PyDbDatabase::aunits, DS.ARGS())
        .def("auprec", &PyDbDatabase::auprec, DS.ARGS())
        .def("blipmode", &PyDbDatabase::blipmode, DS.ARGS())
        .def("byBlockLinetype", &PyDbDatabase::byBlockLinetype, DS.ARGS())
        .def("byBlockMaterial", &PyDbDatabase::byBlockMaterial, DS.ARGS())
        .def("byLayerLinetype", &PyDbDatabase::byLayerLinetype, DS.ARGS())
        .def("byLayerMaterial", &PyDbDatabase::byLayerMaterial, DS.ARGS())
        .def("cameraDisplay", &PyDbDatabase::cameraDisplay, DS.ARGS())
        .def("cameraHeight", &PyDbDatabase::cameraHeight, DS.ARGS())
        .def("cDynDisplayMode", &PyDbDatabase::cDynDisplayMode, DS.ARGS())
        .def("celtscale", &PyDbDatabase::celtscale, DS.ARGS())
        .def("celtype", &PyDbDatabase::celtype, DS.ARGS())
        .def("celweight", &PyDbDatabase::celweight, DS.ARGS())
        .def("chamfera", &PyDbDatabase::chamfera, DS.ARGS())
        .def("chamferb", &PyDbDatabase::chamferb, DS.ARGS())
        .def("chamferc", &PyDbDatabase::chamferc, DS.ARGS())
        .def("chamferd", &PyDbDatabase::chamferd, DS.ARGS())
        .def("classDxfName", &PyDbDatabase::classDxfName, DS.ARGS({ "pClass : PyRx.RxClass" }))
        .def("clayer", &PyDbDatabase::clayer, DS.ARGS())
        .def("closeInput", &PyDbDatabase::closeInput, DS.ARGS({ "close : bool" }))
        .def("cmaterial", &PyDbDatabase::cmaterial, DS.ARGS())
        .def("cmljust", &PyDbDatabase::cmljust, DS.ARGS())
        .def("cmlscale", &PyDbDatabase::cmlscale, DS.ARGS())
        .def("cmlstyleID", &PyDbDatabase::cmlstyleID, DS.ARGS())
        .def("colorDictionaryId", &PyDbDatabase::colorDictionaryId, DS.ARGS())
        .def("continuousLinetype", &PyDbDatabase::continuousLinetype, DS.ARGS())
        .def("coords", &PyDbDatabase::coords, DS.ARGS())
        .def("countEmptyObjects", &PyDbDatabase::countEmptyObjects, DS.ARGS({ "flag : int" }))
        .def("detailViewStyle", &PyDbDatabase::detailViewStyle, DS.ARGS())
        .def("detailViewStyleDictionaryId", &PyDbDatabase::detailViewStyleDictionaryId, DS.ARGS())
        .def("dimaso", &PyDbDatabase::dimaso, DS.ARGS())
        .def("dimAssoc", &PyDbDatabase::dimAssoc, DS.ARGS())
        .def("dimfit", &PyDbDatabase::dimfit, DS.ARGS())
        .def("dimsho", &PyDbDatabase::dimsho, DS.ARGS())
        .def("dimstyle", &PyDbDatabase::dimstyle, DS.ARGS())
        .def("dimStyleTableId", &PyDbDatabase::dimStyleTableId, DS.ARGS())
        .def("dimunit", &PyDbDatabase::dimunit, DS.ARGS())
        .def("dimapost", &PyDbDatabase::dimapost, DS.ARGS())
        .def("dimblk", &PyDbDatabase::dimblk, DS.ARGS())
        .def("dimblk1", &PyDbDatabase::dimblk1, DS.ARGS())
        .def("dimblk2", &PyDbDatabase::dimblk2, DS.ARGS())
        .def("dimpost", &PyDbDatabase::dimblk2, DS.ARGS())
        .def("disablePartialOpen", &PyDbDatabase::disablePartialOpen, DS.ARGS())
        .def("disableUndoRecording", &PyDbDatabase::disableUndoRecording, DS.ARGS({ "disable : bool" }))
        .def("dispSilh", &PyDbDatabase::dispSilh, DS.ARGS())
        .def("dragmode", &PyDbDatabase::dragmode, DS.ARGS())
        .def("dragVisStyle", &PyDbDatabase::dragVisStyle, DS.ARGS())
        .def("drawOrderCtl", &PyDbDatabase::drawOrderCtl, DS.ARGS())
        .def("dwfframe", &PyDbDatabase::dwfframe, DS.ARGS())
        .def("dwgFileWasSavedByAutodeskSoftware", &PyDbDatabase::dwgFileWasSavedByAutodeskSoftware, DS.ARGS())
        .def("dxfIn", &PyDbDatabase::dxfIn, DS.ARGS({ "filename : str" }))
        .def("dxfOut", &PyDbDatabase::dxfOut, DS.ARGS({ "filename : str" }))
        .def("elevation", &PyDbDatabase::elevation, DS.ARGS())
        .def("eraseEmptyObjects", &PyDbDatabase::eraseEmptyObjects, DS.ARGS({ "flag : int" }))
        .def("extmax", &PyDbDatabase::extmax, DS.ARGS())
        .def("extmin", &PyDbDatabase::extmin, DS.ARGS())
        .def("facetres", &PyDbDatabase::facetres, DS.ARGS())
        .def("filletrad", &PyDbDatabase::filletrad, DS.ARGS())
        .def("fillmode", &PyDbDatabase::fillmode, DS.ARGS())
        .def("forceWblockDatabaseCopy", &PyDbDatabase::forceWblockDatabaseCopy, DS.ARGS())
        .def("geoCoordinateSystemId", &PyDbDatabase::geoCoordinateSystemId, DS.ARGS())
        .def("geoMarkerVisibility", &PyDbDatabase::geoMarkerVisibility, DS.ARGS())
        .def("get3dDwfPrec", &PyDbDatabase::get3dDwfPrec, DS.ARGS())
        .def("getObjectId", &PyDbDatabase::getAcDbObjectId1)
        .def("getObjectId", &PyDbDatabase::getAcDbObjectId2, DS.ARGS({ "createIfNotFound : bool","objHandle : Handle","xRefId : int=0" }))
        .def("getCePlotStyleNameId", &PyDbDatabase::getCePlotStyleNameId, DS.ARGS())
        .def("getDimstyleParentId", &PyDbDatabase::getDimstyleParentId, DS.ARGS())
        .def("getNearestLineWeight", &PyDbDatabase::getNearestLineWeight, DS.SARGS({ "weight : int" })).staticmethod("getNearestLineWeight")//static
        .def("getViewportArray", &PyDbDatabase::getViewportArray, DS.ARGS())
        .def("getVisualStyleList", &PyDbDatabase::getVisualStyleList, DS.ARGS())
        .def("globalMaterial", &PyDbDatabase::globalMaterial, DS.ARGS())
        .def("groupDictionaryId", &PyDbDatabase::groupDictionaryId, DS.ARGS())
        .def("haloGap", &PyDbDatabase::haloGap, DS.ARGS())
        .def("handseed", &PyDbDatabase::handseed, DS.ARGS())
        .def("hasClass", &PyDbDatabase::hasClass, DS.ARGS({ "pClass : PyRx.RxClass" }))
        .def("hideText", &PyDbDatabase::hideText, DS.ARGS())
        .def("hpInherit", &PyDbDatabase::hpInherit, DS.ARGS())
        .def("hpOrigin", &PyDbDatabase::hpOrigin, DS.ARGS())
        //TODO: TEST and DOCSTRING
        .def("insert", &PyDbDatabase::insert1)
        .def("insert", &PyDbDatabase::insert2)
        .def("insert", &PyDbDatabase::insert3)
        .def("hpOrigin", &PyDbDatabase::indexctl, DS.ARGS())
        .def("isAppRegistered", &PyDbDatabase::isAppRegistered, DS.ARGS({ "pszAppName : str" }))
        .def("insunits", &PyDbDatabase::insunits, DS.ARGS())
        .def("interfereVpVisStyle", &PyDbDatabase::interfereVpVisStyle, DS.ARGS())
        .def("intersectColor", &PyDbDatabase::intersectColor, DS.ARGS())
        .def("intersectDisplay", &PyDbDatabase::intersectDisplay, DS.ARGS())
        .def("isBeingDestroyed", &PyDbDatabase::isBeingDestroyed, DS.ARGS())
        .def("isEMR", &PyDbDatabase::isEMR, DS.ARGS())
        .def("isObjectNonPersistent", &PyDbDatabase::isObjectNonPersistent, DS.SARGS({ "id : ObjectId" })).staticmethod("isObjectNonPersistent")//static
        .def("isolines", &PyDbDatabase::isolines, DS.ARGS())
        .def("isPartiallyOpened", &PyDbDatabase::isPartiallyOpened, DS.ARGS())
        .def("isPucsOrthographic", &PyDbDatabase::isPucsOrthographic, DS.ARGS({ "orthoView : OrthographicView" }))
        .def("isUcsOrthographic", &PyDbDatabase::isUcsOrthographic, DS.ARGS({ "orthoView : OrthographicView" }))
        .def("isValidLineWeight", &PyDbDatabase::isValidLineWeight, DS.SARGS({ "weight : int" })).staticmethod("isValidLineWeight")//static
        .def("joinStyle", &PyDbDatabase::joinStyle, DS.ARGS())
        .def("lastSavedAsMaintenanceVersion", &PyDbDatabase::lastSavedAsMaintenanceVersion, DS.ARGS())
        .def("lastSavedAsVersion", &PyDbDatabase::lastSavedAsVersion, DS.ARGS())
        .def("latitude", &PyDbDatabase::latitude, DS.ARGS())
        .def("layerEval", &PyDbDatabase::layerEval, DS.ARGS())
        .def("layerNotify", &PyDbDatabase::layerNotify, DS.ARGS())
        .def("layerTableId", &PyDbDatabase::layerTableId, DS.ARGS())
        .def("layerZero", &PyDbDatabase::layerZero, DS.ARGS())
        .def("layoutDictionaryId", &PyDbDatabase::layoutDictionaryId, DS.ARGS())
        .def("lensLength", &PyDbDatabase::lensLength, DS.ARGS())
        .def("lightGlyphDisplay", &PyDbDatabase::lightGlyphDisplay, DS.ARGS())
        .def("lightingUnits", &PyDbDatabase::lightingUnits, DS.ARGS())
        .def("lightsInBlocks", &PyDbDatabase::lightsInBlocks, DS.ARGS())
        .def("limcheck", &PyDbDatabase::limcheck, DS.ARGS())
        .def("limmax", &PyDbDatabase::limmax, DS.ARGS())
        .def("limmin", &PyDbDatabase::limmin, DS.ARGS())
        .def("linetypeTableId", &PyDbDatabase::linetypeTableId, DS.ARGS())
        .def("lineWeightDisplay", &PyDbDatabase::lineWeightDisplay, DS.ARGS())
        .def("loadLineTypeFile", &PyDbDatabase::loadLineTypeFile, DS.ARGS({ "ltn : str","filename : str" }))
        .def("loftAng1", &PyDbDatabase::loftAng1, DS.ARGS())
        .def("loftAng2", &PyDbDatabase::loftAng2, DS.ARGS())
        .def("loftMag1", &PyDbDatabase::loftMag1, DS.ARGS())
        .def("loftMag2", &PyDbDatabase::loftMag2, DS.ARGS())
        .def("loftNormals", &PyDbDatabase::loftNormals, DS.ARGS())
        .def("loftParam", &PyDbDatabase::loftParam, DS.ARGS())
        .def("longitude", &PyDbDatabase::longitude, DS.ARGS())
        .def("ltscale", &PyDbDatabase::ltscale, DS.ARGS())
        .def("lunits", &PyDbDatabase::lunits, DS.ARGS())
        .def("luprec", &PyDbDatabase::luprec, DS.ARGS())
        .def("maintenanceReleaseVersion", &PyDbDatabase::maintenanceReleaseVersion, DS.ARGS())
        .def("markObjectNonPersistent", &PyDbDatabase::markObjectNonPersistent, DS.SARGS({ "id : ObjectId","value : bool" })).staticmethod("markObjectNonPersistent")//static
        .def("materialDictionaryId", &PyDbDatabase::materialDictionaryId, DS.ARGS())
        .def("maxactvp", &PyDbDatabase::maxactvp, DS.ARGS())
        .def("measurement", &PyDbDatabase::measurement, DS.ARGS())
        .def("mirrtext", &PyDbDatabase::mirrtext, DS.ARGS())
        .def("mleaderscale", &PyDbDatabase::mleaderscale, DS.ARGS())
        .def("mleaderstyle", &PyDbDatabase::mleaderstyle, DS.ARGS())
        .def("mleaderStyleDictionaryId", &PyDbDatabase::mleaderStyleDictionaryId, DS.ARGS())
        .def("mLStyleDictionaryId", &PyDbDatabase::mLStyleDictionaryId, DS.ARGS())
        .def("msltscale", &PyDbDatabase::msltscale, DS.ARGS())
        .def("msOleScale", &PyDbDatabase::msOleScale, DS.ARGS())
        .def("namedObjectsDictionaryId", &PyDbDatabase::namedObjectsDictionaryId, DS.ARGS())
        .def("needsRecovery", &PyDbDatabase::needsRecovery, DS.ARGS())
        .def("northDirection", &PyDbDatabase::northDirection, DS.ARGS())
        .def("numberOfSaves", &PyDbDatabase::numberOfSaves, DS.ARGS())
        .def("obscuredColor", &PyDbDatabase::obscuredColor, DS.ARGS())
        .def("obscuredLineType", &PyDbDatabase::obscuredLineType, DS.ARGS())
        .def("oleStartUp", &PyDbDatabase::oleStartUp, DS.ARGS())
        .def("originalFileMaintenanceVersion", &PyDbDatabase::originalFileMaintenanceVersion, DS.ARGS())
        .def("originalFileName", &PyDbDatabase::originalFileName, DS.ARGS())
        .def("originalFileSavedByMaintenanceVersion", &PyDbDatabase::originalFileSavedByMaintenanceVersion, DS.ARGS())
        .def("originalFileSavedByVersion", &PyDbDatabase::originalFileSavedByVersion, DS.ARGS())
        .def("originalFileVersion", &PyDbDatabase::originalFileVersion, DS.ARGS())
        .def("orthomode", &PyDbDatabase::orthomode, DS.ARGS())
        .def("paperSpaceVportId", &PyDbDatabase::paperSpaceVportId, DS.ARGS())
        .def("pdfframe", &PyDbDatabase::pdfframe, DS.ARGS())
        .def("pdmode", &PyDbDatabase::pdmode, DS.ARGS())
        .def("pdsize", &PyDbDatabase::pdsize, DS.ARGS())
        .def("pextmax", &PyDbDatabase::pextmax, DS.ARGS())
        .def("pextmin", &PyDbDatabase::pextmin, DS.ARGS())
        .def("pickstyle", &PyDbDatabase::pickstyle, DS.ARGS())
        .def("pinsbase", &PyDbDatabase::pinsbase, DS.ARGS())
        .def("plimcheck", &PyDbDatabase::plimcheck, DS.ARGS())
        .def("plimmax", &PyDbDatabase::plimmax, DS.ARGS())
        .def("plimmin", &PyDbDatabase::plimmin, DS.ARGS())
        .def("plineEllipse", &PyDbDatabase::plineEllipse, DS.ARGS())
        .def("plinegen", &PyDbDatabase::plinegen, DS.ARGS())
        .def("plinewid", &PyDbDatabase::plinewid, DS.ARGS())
        .def("plotSettingsDictionaryId", &PyDbDatabase::plotSettingsDictionaryId, DS.ARGS())
        .def("plotStyleMode", &PyDbDatabase::plotStyleMode, DS.ARGS())
        .def("plotStyleNameDictionaryId", &PyDbDatabase::plotStyleNameDictionaryId, DS.ARGS())
        .def("previewType", &PyDbDatabase::previewType, DS.ARGS())
        .def("psltscale", &PyDbDatabase::psltscale, DS.ARGS())
        .def("psolHeight", &PyDbDatabase::psolHeight, DS.ARGS())
        .def("psolWidth", &PyDbDatabase::psolWidth, DS.ARGS())
        .def("pucsBase", &PyDbDatabase::pucsBase, DS.ARGS())
        .def("pucsname", &PyDbDatabase::pucsname, DS.ARGS())
        .def("pucsorg", &PyDbDatabase::pucsorg, DS.ARGS())
        .def("pucsxdir", &PyDbDatabase::pucsxdir, DS.ARGS())
        .def("pucsydir", &PyDbDatabase::pucsydir, DS.ARGS())
        .def("qtextmode", &PyDbDatabase::qtextmode, DS.ARGS())
        .def("reclaimMemoryFromErasedObjects", &PyDbDatabase::reclaimMemoryFromErasedObjects, DS.ARGS({ "ids : list[ObjectId]" }))
        .def("regAppTableId", &PyDbDatabase::regAppTableId, DS.ARGS())
        .def("regenmode", &PyDbDatabase::regenmode, DS.ARGS())
        .def("registerApp", &PyDbDatabase::registerApp, DS.ARGS({ "appName : str" }))
        .def("resetTimes", &PyDbDatabase::resetTimes, DS.ARGS())
        .def("restoreForwardingXrefSymbols", &PyDbDatabase::restoreForwardingXrefSymbols, DS.ARGS())
        .def("restoreOriginalXrefSymbols", &PyDbDatabase::restoreOriginalXrefSymbols, DS.ARGS())
        .def("retainOriginalThumbnailBitmap", &PyDbDatabase::retainOriginalThumbnailBitmap, DS.ARGS())
        .def("saveproxygraphics", &PyDbDatabase::saveproxygraphics, DS.ARGS())
        .def("scaleListDictionaryId", &PyDbDatabase::scaleListDictionaryId, DS.ARGS())
        .def("sectionViewStyle", &PyDbDatabase::sectionViewStyle, DS.ARGS())
        .def("sectionViewStyleDictionaryId", &PyDbDatabase::sectionViewStyleDictionaryId, DS.ARGS())
        .def("set3dDwfPrec", &PyDbDatabase::set3dDwfPrec, DS.ARGS({ "dwfPrec : float" }))
        .def("setAngbase", &PyDbDatabase::setAngbase, DS.ARGS({ "angle : float" }))
        .def("setAngdir", &PyDbDatabase::setAngdir, DS.ARGS({ "dir : bool" }))
        .def("setAnnoAllVisible", &PyDbDatabase::setAnnoAllVisible, DS.ARGS({ "allvis : bool" }))
        .def("setAttdia", &PyDbDatabase::setAttdia, DS.ARGS({ "val : bool" }))
        .def("setAttmode", &PyDbDatabase::setAttmode, DS.ARGS({ "val : int" }))
        .def("setAttreq", &PyDbDatabase::setAttreq, DS.ARGS({ "val : bool" }))
        .def("setAunits", &PyDbDatabase::setAunits, DS.ARGS({ "val : int" }))
        .def("setAuprec", &PyDbDatabase::setAuprec, DS.ARGS({ "val : int" }))
        .def("setBlipmode", &PyDbDatabase::setBlipmode, DS.ARGS({ "val : bool" }))
        .def("setCameraDisplay", &PyDbDatabase::setCameraDisplay, DS.ARGS({ "val : bool" }))
        .def("setCameraHeight", &PyDbDatabase::setCameraHeight, DS.ARGS({ "val : float" }))
        .def("setCDynDisplayMode", &PyDbDatabase::setCDynDisplayMode, DS.ARGS({ "val : int" }))
        .def("setCeltscale", &PyDbDatabase::setCeltscale, DS.ARGS({ "val : float" }))
        .def("setCeltype", &PyDbDatabase::setCeltype, DS.ARGS({ "val : ObjectId" }))
        .def("setCelweight", &PyDbDatabase::setCelweight, DS.ARGS({ "val : LineWeight" }))
        .def("setCePlotStyleName", &PyDbDatabase::setCePlotStyleName, DS.ARGS({ "val : PlotStyleNameType", "id : ObjectId" }))
        .def("setChamfera", &PyDbDatabase::setChamfera, DS.ARGS({ "val : float" }))
        .def("setChamferb", &PyDbDatabase::setChamferb, DS.ARGS({ "val : float" }))
        .def("setChamferc", &PyDbDatabase::setChamferc, DS.ARGS({ "val : float" }))
        .def("setChamferd", &PyDbDatabase::setChamferd, DS.ARGS({ "val : float" }))
        .def("setClayer", &PyDbDatabase::setClayer, DS.ARGS({ "val : ObjectId" }))
        .def("setCmaterial", &PyDbDatabase::setCmaterial, DS.ARGS({ "val : ObjectId" }))
        .def("setCmljust", &PyDbDatabase::setCmljust, DS.ARGS({ "val : int" }))
        .def("setCmlscale", &PyDbDatabase::setCmlscale, DS.ARGS({ "val : float" }))
        .def("setCmlstyleID", &PyDbDatabase::setCmlstyleID, DS.ARGS({ "val : ObjectId" }))
        .def("setCoords", &PyDbDatabase::setCoords, DS.ARGS({ "val : int" }))
        .def("setCshadow", &PyDbDatabase::setCshadow, DS.ARGS({ "val : int" }))
        .def("setDelUsedObj", &PyDbDatabase::setDelUsedObj, DS.ARGS({ "val : int" }))
        .def("setDgnframe", &PyDbDatabase::setDgnframe, DS.ARGS({ "val : int" }))
        .def("setDimaso", &PyDbDatabase::setDimaso, DS.ARGS({ "val : bool" }))
        .def("setDimAssoc", &PyDbDatabase::setDimAssoc, DS.ARGS({ "val : int" }))
        .def("setDimfit", &PyDbDatabase::setDimfit, DS.ARGS({ "val : int" }))
        .def("setDimsho", &PyDbDatabase::setDimsho, DS.ARGS({ "val : bool" }))
        .def("setDimstyle", &PyDbDatabase::setDimstyle, DS.ARGS({ "val : ObjectId" }))
        .def("setDimstyleData", &PyDbDatabase::setDimstyleData1)
        .def("setDimstyleData", &PyDbDatabase::setDimstyleData2, DS.ARGS({ "val : DimStyleTableRecord | ObjectId" }))
        .def("setDimunit", &PyDbDatabase::setDimunit, DS.ARGS({ "val : int" }))
        .def("setDispSilh", &PyDbDatabase::setDispSilh, DS.ARGS({ "val : bool" }))
        .def("setDragmode", &PyDbDatabase::setDragmode, DS.ARGS({ "val : int" }))
        .def("setDragVisStyle", &PyDbDatabase::setDragVisStyle, DS.ARGS({ "val : ObjectId" }))
        .def("setDrawOrderCtl", &PyDbDatabase::setDrawOrderCtl, DS.ARGS({ "val : int" }))
        .def("setDwfframe", &PyDbDatabase::setDwfframe, DS.ARGS({ "val : int" }))
        .def("setElevation", &PyDbDatabase::setElevation, DS.ARGS({ "val : float" }))
        .def("setEndCaps", &PyDbDatabase::setEndCaps, DS.ARGS({ "val : EndCaps" }))
        .def("setExtmax", &PyDbDatabase::setExtmax, DS.ARGS({ "val : PyGe.Point3d" }))
        .def("setExtmin", &PyDbDatabase::setExtmin, DS.ARGS({ "val : PyGe.Point3d" }))
        .def("setFacetres", &PyDbDatabase::setFacetres, DS.ARGS({ "val : float" }))
        .def("setFilletrad", &PyDbDatabase::setFilletrad, DS.ARGS({ "val : float" }))
        .def("setFillmode", &PyDbDatabase::setFillmode, DS.ARGS({ "val : bool" }))
        .def("saveAs", &PyDbDatabase::saveAs, DS.ARGS({ "filename : str" }))
        .def("setFingerprintGuid", &PyDbDatabase::setFingerprintGuid, DS.ARGS({ "guid : str" }))
        .def("setFullSaveRequired", &PyDbDatabase::setFullSaveRequired, DS.ARGS())
        .def("setGeoMarkerVisibility", &PyDbDatabase::setGeoMarkerVisibility, DS.ARGS({ "val : bool" }))
        .def("setHaloGap", &PyDbDatabase::setHaloGap, DS.ARGS({ "val : int" }))
        .def("setHandseed", &PyDbDatabase::setHandseed, DS.ARGS({ "val : Handle" }))
        .def("setHideText", &PyDbDatabase::setHideText, DS.ARGS({ "val : int" }))
        .def("setHpInherit", &PyDbDatabase::setHpInherit, DS.ARGS({ "val : bool" }))
        .def("setHpOrigin", &PyDbDatabase::setHpOrigin, DS.ARGS({ "val : PyGe.Point2d" }))
        .def("setHyperlinkBase", &PyDbDatabase::setHyperlinkBase, DS.ARGS({ "val : str" }))
        .def("setIndexctl", &PyDbDatabase::setIndexctl, DS.ARGS({ "val : int" }))
        .def("setInsbase", &PyDbDatabase::setInsbase, DS.ARGS({ "val : PyGe.Point3d" }))
        .def("setInsunits", &PyDbDatabase::setInsunits, DS.ARGS({ "val : UnitsValue" }))
        .def("setInterfereObjVisStyle", &PyDbDatabase::setInterfereObjVisStyle, DS.ARGS({ "val : ObjectId" }))
        .def("setInterfereVpVisStyle", &PyDbDatabase::setInterfereVpVisStyle, DS.ARGS({ "val : ObjectId" }))
        .def("setIntersectColor", &PyDbDatabase::setIntersectColor, DS.ARGS({ "val : int" }))
        .def("setIntersectDisplay", &PyDbDatabase::setIntersectDisplay, DS.ARGS({ "val : int" }))
        .def("setIsolines", &PyDbDatabase::setIsolines, DS.ARGS({ "val : int" }))
        .def("setJoinStyle", &PyDbDatabase::setJoinStyle, DS.ARGS({ "val : JoinStyle" }))
        .def("setLatitude", &PyDbDatabase::setLatitude, DS.ARGS({ "val : float" }))
        .def("setLayerEval", &PyDbDatabase::setLayerEval, DS.ARGS({ "val : int" }))
        .def("setLayerNotify", &PyDbDatabase::setLayerNotify, DS.ARGS({ "val : int" }))
        .def("setLensLength", &PyDbDatabase::setLensLength, DS.ARGS({ "val : float" }))
        .def("setLightGlyphDisplay", &PyDbDatabase::setLightGlyphDisplay, DS.ARGS({ "val : int" }))
        .def("setLightingUnits", &PyDbDatabase::setLightingUnits, DS.ARGS({ "val : int" }))
        .def("setLightsInBlocks", &PyDbDatabase::setLightsInBlocks, DS.ARGS({ "val : bool" }))
        .def("setLimcheck", &PyDbDatabase::setLimcheck, DS.ARGS({ "val : bool" }))
        .def("setLimmax", &PyDbDatabase::setLimmax, DS.ARGS({ "val : PyGe.Point2d" }))
        .def("setLimmin", &PyDbDatabase::setLimmin, DS.ARGS({ "val : PyGe.Point2d" }))
        .def("setLineWeightDisplay", &PyDbDatabase::setLineWeightDisplay, DS.ARGS({ "val : bool" }))
        .def("setLoftAng1", &PyDbDatabase::setLoftAng1, DS.ARGS({ "val : float" }))
        .def("setLoftAng2", &PyDbDatabase::setLoftAng2, DS.ARGS({ "val : float" }))
        .def("setLoftMag1", &PyDbDatabase::setLoftMag1, DS.ARGS({ "val : float" }))
        .def("setLoftMag2", &PyDbDatabase::setLoftMag2, DS.ARGS({ "val : float" }))
        .def("setLoftNormals", &PyDbDatabase::setLoftNormals, DS.ARGS({ "val : int" }))
        .def("setLoftParam", &PyDbDatabase::setLoftParam, DS.ARGS({ "flags : int" }))
        .def("setLongitude", &PyDbDatabase::setLongitude, DS.ARGS({ "val : float" }))
        .def("setLtscale", &PyDbDatabase::setLtscale, DS.ARGS({ "val : float" }))
        .def("setLunits", &PyDbDatabase::setLunits, DS.ARGS({ "val : int" }))
        .def("setLuprec", &PyDbDatabase::setLuprec, DS.ARGS({ "val : int" }))
        .def("setMaxactvp", &PyDbDatabase::setMaxactvp, DS.ARGS({ "val : int" }))
        .def("setMeasurement", &PyDbDatabase::setMeasurement, DS.ARGS({ "val : MeasurementValue" }))
        .def("setMirrtext", &PyDbDatabase::setMirrtext, DS.ARGS({ "val : bool" }))
        .def("setMLeaderscale", &PyDbDatabase::setMLeaderscale, DS.ARGS({ "val : float" }))
        .def("setMLeaderstyle", &PyDbDatabase::setMLeaderstyle, DS.ARGS({ "val : ObjectId" }))
        .def("setMsltscale", &PyDbDatabase::setMsltscale, DS.ARGS({ "val : bool" }))
        .def("setMsOleScale", &PyDbDatabase::setMsOleScale, DS.ARGS({ "val : float" }))
        .def("setNorthDirection", &PyDbDatabase::setNorthDirection, DS.ARGS({ "val : float" }))
        .def("setObscuredColor", &PyDbDatabase::setObscuredColor, DS.ARGS({ "val : int" }))
        .def("setObscuredLineType", &PyDbDatabase::setObscuredLineType, DS.ARGS({ "val : int" }))
        .def("setOleStartUp", &PyDbDatabase::setOleStartUp, DS.ARGS({ "val : bool" }))
        .def("setOrthomode", &PyDbDatabase::setOrthomode, DS.ARGS({ "val : bool" }))
        .def("setPdfframe", &PyDbDatabase::setPdfframe, DS.ARGS({ "val : int" }))
        .def("setPdmode", &PyDbDatabase::setPdmode, DS.ARGS({ "val : int" }))
        .def("setPdsize", &PyDbDatabase::setPdsize, DS.ARGS({ "val : float" }))
        .def("setPelevation", &PyDbDatabase::setPelevation, DS.ARGS({ "val : float" }))
        .def("setPextmax", &PyDbDatabase::setPextmax, DS.ARGS({ "val : PyGe.Point3d" }))
        .def("setPextmin", &PyDbDatabase::setPextmin, DS.ARGS({ "val : PyGe.Point3d" }))
        .def("setPickstyle", &PyDbDatabase::setPickstyle, DS.ARGS({ "val : int" }))
        .def("setPinsbase", &PyDbDatabase::setPinsbase, DS.ARGS({ "val : PyGe.Point3d" }))
        .def("setPlimcheck", &PyDbDatabase::setPlimcheck, DS.ARGS({ "val : bool" }))
        .def("setPlimmax", &PyDbDatabase::setPlimmax, DS.ARGS({ "val : PyGe.Point2d" }))
        .def("setPlimmin", &PyDbDatabase::setPlimmin, DS.ARGS({ "val : PyGe.Point2d" }))
        .def("setPlineEllipse", &PyDbDatabase::setPlineEllipse, DS.ARGS({ "val : bool" }))
        .def("setPlinegen", &PyDbDatabase::setPlinegen, DS.ARGS({ "val : bool" }))
        .def("setPlinewid", &PyDbDatabase::setPlinewid, DS.ARGS({ "val : float" }))
        .def("setPreviewType", &PyDbDatabase::setPreviewType, DS.ARGS({ "val : int" }))
        .def("setProjectName", &PyDbDatabase::setProjectName, DS.ARGS({ "val : str" }))
        .def("setPsltscale", &PyDbDatabase::setPsltscale, DS.ARGS({ "val : bool" }))
        .def("setPsolHeight", &PyDbDatabase::setPsolHeight, DS.ARGS({ "val : float" }))
        .def("setPsolWidth", &PyDbDatabase::setPsolWidth, DS.ARGS({ "val : float" }))
        .def("setPucs", &PyDbDatabase::setPucs, DS.ARGS({ "ucsOrigin : PyGe.Point3d","ucsXDir : PyGe.Vector3d" ,"ucsYDir : PyGe.Vector3d" }))
        .def("setPucsBase", &PyDbDatabase::setPucsBase, DS.ARGS({ "ucsid : ObjectId" }))
        .def("setPucsname", &PyDbDatabase::setPucsname, DS.ARGS({ "ucsrec : ObjectId" }))
        .def("setQtextmode", &PyDbDatabase::setQtextmode, DS.ARGS({ "val : bool" }))
        .def("setRealWorldScale", &PyDbDatabase::setRealWorldScale, DS.ARGS({ "val : float" }))
        .def("setRegenmode", &PyDbDatabase::setRegenmode, DS.ARGS({ "val : bool" }))
        .def("setRetainOriginalThumbnailBitmap", &PyDbDatabase::setRetainOriginalThumbnailBitmap, DS.ARGS({ "val : bool" }))
        .def("setSaveproxygraphics", &PyDbDatabase::setSaveproxygraphics, DS.ARGS({ "val : int" }))
        .def("setSectionViewStyle", &PyDbDatabase::setSectionViewStyle, DS.ARGS({ "val : ObjectId" }))
        .def("setShadedge", &PyDbDatabase::setShadedge, DS.ARGS({ "val : int" }))
        .def("setShadedif", &PyDbDatabase::setShadedif, DS.ARGS({ "val : int" }))
        .def("setShadowPlaneLocation", &PyDbDatabase::setShadowPlaneLocation, DS.ARGS({ "val : float" }))
        .def("setShowHist", &PyDbDatabase::setShowHist, DS.ARGS({ "val : int" }))
        .def("setSketchinc", &PyDbDatabase::setSketchinc, DS.ARGS({ "val : float" }))
        .def("setSkpoly", &PyDbDatabase::setSkpoly, DS.ARGS({ "val : bool" }))
        .def("setSolidHist", &PyDbDatabase::setSolidHist, DS.ARGS({ "val : int" }))
        .def("setSortEnts", &PyDbDatabase::setSortEnts, DS.ARGS({ "val : int" }))
        .def("setSplframe", &PyDbDatabase::setSplframe, DS.ARGS({ "val : bool" }))
        .def("setSplinesegs", &PyDbDatabase::setSplinesegs, DS.ARGS({ "val : int" }))
        .def("setSplinetype", &PyDbDatabase::setSplinetype, DS.ARGS({ "val : int" }))
        .def("setStepSize", &PyDbDatabase::setStepSize, DS.ARGS({ "val : float" }))
        .def("setStepsPerSec", &PyDbDatabase::setStepsPerSec, DS.ARGS({ "val : float" }))
        .def("setStyleSheet", &PyDbDatabase::setStyleSheet, DS.ARGS({ "val : str" }))
        .def("setSurftab1", &PyDbDatabase::setSurftab1, DS.ARGS({ "val : int" }))
        .def("setSurftab2", &PyDbDatabase::setSurftab2, DS.ARGS({ "val : int" }))
        .def("setSurftype", &PyDbDatabase::setSurftype, DS.ARGS({ "val : int" }))
        .def("setSurfu", &PyDbDatabase::setSurfu, DS.ARGS({ "val : int" }))
        .def("setSurfv", &PyDbDatabase::setSurfv, DS.ARGS({ "val : int" }))
        .def("setTablestyle", &PyDbDatabase::setTablestyle, DS.ARGS({ "val : ObjectId" }))
        .def("setTextsize", &PyDbDatabase::setTextsize, DS.ARGS({ "val : float" }))
        .def("setTextstyle", &PyDbDatabase::setTextstyle, DS.ARGS({ "val : ObjectId" }))
        .def("setThickness", &PyDbDatabase::setThickness, DS.ARGS({ "val : float" }))
        .def("setTilemode", &PyDbDatabase::setTilemode, DS.ARGS({ "val : bool" }))
        .def("setTimeZone", &PyDbDatabase::setTimeZone, DS.ARGS({ "val : TimeZone" }))
        .def("setTimeZoneAsUtcOffset", &PyDbDatabase::setTimeZoneAsUtcOffset, DS.ARGS({ "val : float" }))
        .def("setTracewid", &PyDbDatabase::setTracewid, DS.ARGS({ "val : float" }))
        .def("setTreedepth", &PyDbDatabase::setTreedepth, DS.ARGS({ "val : int" }))
        .def("setTStackAlign", &PyDbDatabase::setTStackAlign, DS.ARGS({ "val : int" }))
        .def("setTStackSize", &PyDbDatabase::setTStackSize, DS.ARGS({ "val : int" }))
        .def("setUcs", &PyDbDatabase::setUcs, DS.ARGS({ "ucsOrigin : PyGe.Point3d","ucsXDir : PyGe.Vector3d" ,"ucsYDir : PyGe.Vector3d" }))
        .def("setUcsBase", &PyDbDatabase::setUcsBase, DS.ARGS({ "ucsid : ObjectId" }))
        .def("setUcsname", &PyDbDatabase::setUcsname, DS.ARGS({ "ucsrecId : ObjectId" }))
        .def("setUnitmode", &PyDbDatabase::setUnitmode, DS.ARGS({ "val : int" }))
        .def("setUpdateThumbnail", &PyDbDatabase::setUpdateThumbnail, DS.ARGS({ "val : int" }))
        .def("setUseri1", &PyDbDatabase::setUseri1, DS.ARGS({ "val : int" }))
        .def("setUseri2", &PyDbDatabase::setUseri2, DS.ARGS({ "val : int" }))
        .def("setUseri3", &PyDbDatabase::setUseri3, DS.ARGS({ "val : int" }))
        .def("setUseri4", &PyDbDatabase::setUseri4, DS.ARGS({ "val : int" }))
        .def("setUseri5", &PyDbDatabase::setUseri5, DS.ARGS({ "val : int" }))
        .def("setUserr1", &PyDbDatabase::setUserr1, DS.ARGS({ "val : float" }))
        .def("setUserr2", &PyDbDatabase::setUserr2, DS.ARGS({ "val : float" }))
        .def("setUserr3", &PyDbDatabase::setUserr3, DS.ARGS({ "val : float" }))
        .def("setUserr4", &PyDbDatabase::setUserr4, DS.ARGS({ "val : float" }))
        .def("setUserr5", &PyDbDatabase::setUserr5, DS.ARGS({ "val : float" }))
        .def("setUsrtimer", &PyDbDatabase::setUsrtimer, DS.ARGS({ "val : bool" }))
        .def("setVersionGuid", &PyDbDatabase::setVersionGuid, DS.ARGS({ "val : str" }))
        .def("setViewportScaleDefault", &PyDbDatabase::setViewportScaleDefault, DS.ARGS({ "val : float" }))
        .def("setVisretain", &PyDbDatabase::setVisretain, DS.ARGS({ "val : bool" }))
        .def("setWorldPucsBaseOrigin", &PyDbDatabase::setWorldPucsBaseOrigin, DS.ARGS({ "ucsOrigin : PyGe.Point3d","orthoView : OrthographicView" }))
        .def("setWorldUcsBaseOrigin", &PyDbDatabase::setWorldUcsBaseOrigin, DS.ARGS({ "ucsOrigin : PyGe.Point3d","orthoView : OrthographicView" }))
        .def("setWorldview", &PyDbDatabase::setWorldview, DS.ARGS({ "val : bool" }))
        .def("setXclipFrame", &PyDbDatabase::setXclipFrame, DS.ARGS({ "val : int" }))
        .def("setXrefEditEnabled", &PyDbDatabase::setXrefEditEnabled, DS.ARGS({ "val : bool" }))
        .def("shadedge", &PyDbDatabase::shadedge, DS.ARGS())
        .def("shadedif", &PyDbDatabase::shadedif, DS.ARGS())
        .def("shadowPlaneLocation", &PyDbDatabase::shadowPlaneLocation, DS.ARGS())
        .def("showHist", &PyDbDatabase::showHist, DS.ARGS())
        .def("sketchinc", &PyDbDatabase::sketchinc, DS.ARGS())
        .def("skpoly", &PyDbDatabase::skpoly, DS.ARGS())
        .def("solidHist", &PyDbDatabase::solidHist, DS.ARGS())
        .def("sortEnts", &PyDbDatabase::sortEnts, DS.ARGS())
        .def("splframe", &PyDbDatabase::splframe, DS.ARGS())
        .def("splinesegs", &PyDbDatabase::splinesegs, DS.ARGS())
        .def("splinetype", &PyDbDatabase::splinetype, DS.ARGS())
        .def("stepSize", &PyDbDatabase::stepSize, DS.ARGS())
        .def("stepsPerSec", &PyDbDatabase::stepsPerSec, DS.ARGS())
        .def("surftab1", &PyDbDatabase::surftab1, DS.ARGS())
        .def("surftab2", &PyDbDatabase::surftab2, DS.ARGS())
        .def("surftype", &PyDbDatabase::surftype, DS.ARGS())
        .def("surfu", &PyDbDatabase::surfu, DS.ARGS())
        .def("surfv", &PyDbDatabase::surfv, DS.ARGS())
        .def("tablestyle", &PyDbDatabase::tablestyle, DS.ARGS())
        .def("tableStyleDictionaryId", &PyDbDatabase::tableStyleDictionaryId, DS.ARGS())
        .def("textsize", &PyDbDatabase::textsize, DS.ARGS())
        .def("textstyle", &PyDbDatabase::textstyle, DS.ARGS())
        .def("textStyleTableId", &PyDbDatabase::textStyleTableId, DS.ARGS())
        .def("thickness", &PyDbDatabase::thickness, DS.ARGS())
        .def("tilemode", &PyDbDatabase::tilemode, DS.ARGS())
        .def("tileModeLightSynch", &PyDbDatabase::tileModeLightSynch, DS.ARGS())
        .def("timeZone", &PyDbDatabase::timeZone, DS.ARGS())
        .def("tracewid", &PyDbDatabase::tracewid, DS.ARGS())
        .def("treedepth", &PyDbDatabase::treedepth, DS.ARGS())
        .def("transactionManager", &PyDbDatabase::transactionManager, DS.ARGS())
        .def("tstackalign", &PyDbDatabase::tstackalign, DS.ARGS())
        .def("tstacksize", &PyDbDatabase::tstacksize, DS.ARGS())
        .def("ucsBase", &PyDbDatabase::ucsBase, DS.ARGS())
        .def("ucsname", &PyDbDatabase::ucsname, DS.ARGS())
        .def("ucsorg", &PyDbDatabase::ucsorg, DS.ARGS())
        .def("UCSTableId", &PyDbDatabase::UCSTableId, DS.ARGS())
        .def("ucsxdir", &PyDbDatabase::ucsxdir, DS.ARGS())
        .def("ucsydir", &PyDbDatabase::ucsydir, DS.ARGS())
        .def("undoRecording", &PyDbDatabase::undoRecording, DS.ARGS())
        .def("unitmode", &PyDbDatabase::unitmode, DS.ARGS())
        .def("updateDataLink", &PyDbDatabase::updateDataLink, DS.ARGS({ "nDir : UpdateDirection", "opt : UpdateOption" }))
        .def("updateExt", &PyDbDatabase::updateExt, DS.ARGS({ "val : bool" }))
        .def("updateThumbnail", &PyDbDatabase::updateThumbnail, DS.ARGS())
        .def("useri1", &PyDbDatabase::useri1, DS.ARGS())
        .def("useri2", &PyDbDatabase::useri2, DS.ARGS())
        .def("useri3", &PyDbDatabase::useri3, DS.ARGS())
        .def("useri4", &PyDbDatabase::useri4, DS.ARGS())
        .def("useri5", &PyDbDatabase::useri5, DS.ARGS())
        .def("userr1", &PyDbDatabase::userr1, DS.ARGS())
        .def("userr2", &PyDbDatabase::userr2, DS.ARGS())
        .def("userr3", &PyDbDatabase::userr3, DS.ARGS())
        .def("userr4", &PyDbDatabase::userr4, DS.ARGS())
        .def("userr5", &PyDbDatabase::userr5, DS.ARGS())
        .def("usrtimer", &PyDbDatabase::usrtimer, DS.ARGS())
        .def("viewportScaleDefault", &PyDbDatabase::viewportScaleDefault, DS.ARGS())
        .def("viewportTableId", &PyDbDatabase::viewportTableId, DS.ARGS())
        .def("viewTableId", &PyDbDatabase::viewTableId, DS.ARGS())
        .def("visretain", &PyDbDatabase::visretain, DS.ARGS())
        .def("visualStyleDictionaryId", &PyDbDatabase::visualStyleDictionaryId, DS.ARGS())
        .def("worldPucsBaseOrigin", &PyDbDatabase::worldPucsBaseOrigin, DS.ARGS({ "view : OrthographicView" }))
        .def("worldUcsBaseOrigin", &PyDbDatabase::worldUcsBaseOrigin, DS.ARGS({ "view : OrthographicView" }))
        .def("worldview", &PyDbDatabase::worldview, DS.ARGS())
        .def("xclipFrame", &PyDbDatabase::xclipFrame, DS.ARGS())
        .def("xrefBlockId", &PyDbDatabase::xrefBlockId, DS.ARGS())
        .def("xrefEditEnabled", &PyDbDatabase::xrefEditEnabled, DS.ARGS())
        //TODO: TEST
        .def("wblock", &PyDbDatabase::wblock1)
        .def("wblock", &PyDbDatabase::wblock2)
        .def("wblock", &PyDbDatabase::wblock3)
        .def("wblock", &PyDbDatabase::wblock4)
        .def("getFilename", &PyDbDatabase::getFilename, DS.ARGS())
        .def("readDwgFile", &PyDbDatabase::readDwgFile)
        .def("readDwgFile", &PyDbDatabase::readDwgFile2, DS.ARGS({ "fileName : str", "mode : int=kForReadAndReadShare", "bAllowCPConversion : bool=False","password : str=empty" }))
        .def("blockTableId", &PyDbDatabase::blockTableId, DS.ARGS())
        .def("modelSpaceId", &PyDbDatabase::modelSpaceId, DS.ARGS())
        .def("currentSpaceId", &PyDbDatabase::currentSpaceId, DS.ARGS())
        .def("purge", &PyDbDatabase::purge, DS.ARGS())
        .def("setCannoscale", &PyDbDatabase::setCannoscale, DS.ARGS({ "val : AnnotationScale" }))
        .def("setCecolor", &PyDbDatabase::setCecolor, DS.ARGS({ "val : Color" }))
        .def("setCetransparency", &PyDbDatabase::setCetransparency, DS.ARGS({ "val : Transparency" }))
        .def("setInterfereColor", &PyDbDatabase::setInterfereColor, DS.ARGS({ "val : Color" }))
        .def("className", &PyDbDatabase::className, DS.SARGS()).staticmethod("className")
        ;
}

//---------------------------------------------------------------------------------------------------
// PyDbDatabase
PyDbDatabase::PyDbDatabase()
    :PyRxObject(nullptr, false, false)
{
}

PyDbDatabase::PyDbDatabase(AcDbDatabase* _pDb)
    : PyRxObject(_pDb, false, false)
{
}

PyDbDatabase::PyDbDatabase(AcDbDatabase* _pDb, bool autoDelete)
    : PyRxObject(_pDb, false, false)
{
}

PyDbDatabase::PyDbDatabase(bool buildDefaultDrawing, bool noDocument)
    : PyRxObject(new AcDbDatabase(buildDefaultDrawing, noDocument), true, false)
{
}

PyDbObjectId PyDbDatabase::addAcDbObject(PyDbObject& obj)
{
    PyDbObjectId id;
    if (auto es = impObj()->addAcDbObject(id.m_id, obj.impObj()); es != eOk)
        throw PyAcadErrorStatus(es);
    return id;
}

double PyDbDatabase::angbase() const
{
    return impObj()->angbase();
}

bool PyDbDatabase::angdir() const
{
    return impObj()->angdir();
}

bool PyDbDatabase::annoAllVisible() const
{
    return impObj()->annoAllVisible();
}

bool PyDbDatabase::annotativeDwg() const
{
    return impObj()->annotativeDwg();
}

int PyDbDatabase::approxNumObjects() const
{
    return impObj()->approxNumObjects();
}

Adesk::Int16 PyDbDatabase::attmode() const
{
    return impObj()->attmode();
}

Adesk::Int16 PyDbDatabase::aunits() const
{
    return impObj()->aunits();
}

Adesk::Int16 PyDbDatabase::auprec() const
{
    return impObj()->auprec();
}

bool PyDbDatabase::blipmode() const
{
    return impObj()->blipmode();
}

PyDbObjectId PyDbDatabase::byBlockLinetype() const
{
    return PyDbObjectId(impObj()->byBlockLinetype());
}

PyDbObjectId PyDbDatabase::byBlockMaterial() const
{
    return PyDbObjectId(impObj()->byBlockMaterial());
}

PyDbObjectId PyDbDatabase::byLayerLinetype() const
{
    return PyDbObjectId(impObj()->byLayerLinetype());
}

PyDbObjectId PyDbDatabase::byLayerMaterial() const
{
    return PyDbObjectId(impObj()->byLayerMaterial());
}

bool PyDbDatabase::cameraDisplay() const
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return impObj()->cameraDisplay();
#endif
}

double PyDbDatabase::cameraHeight() const
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return impObj()->cameraHeight();
#endif
}

Adesk::Int16 PyDbDatabase::cDynDisplayMode() const
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return impObj()->cDynDisplayMode();
#endif // BRXAPP
}

double PyDbDatabase::celtscale() const
{
    return impObj()->celtscale();
}

PyDbObjectId PyDbDatabase::celtype() const
{
    return PyDbObjectId(impObj()->celtype());
}

AcDb::LineWeight PyDbDatabase::celweight() const
{
    return impObj()->celweight();
}

double PyDbDatabase::chamfera() const
{
    return impObj()->chamfera();
}

double PyDbDatabase::chamferb() const
{
    return impObj()->chamferb();
}

double PyDbDatabase::chamferc() const
{
    return impObj()->chamferc();
}

double PyDbDatabase::chamferd() const
{
    return impObj()->chamferd();
}

std::string PyDbDatabase::classDxfName(const PyRxClass& pClass)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return wstr_to_utf8(impObj()->classDxfName(pClass.impObj()));
#endif
}

PyDbObjectId PyDbDatabase::clayer() const
{
    return PyDbObjectId(impObj()->clayer());
}

void PyDbDatabase::closeInput(bool bCloseFile)
{
    return PyThrowBadEs(impObj()->closeInput(bCloseFile));
}

PyDbObjectId PyDbDatabase::cmaterial() const
{
    return PyDbObjectId(impObj()->cmaterial());
}

Adesk::Int16 PyDbDatabase::cmljust() const
{
    return impObj()->cmljust();
}

double PyDbDatabase::cmlscale() const
{
    return impObj()->cmlscale();
}

PyDbObjectId PyDbDatabase::cmlstyleID() const
{
    return PyDbObjectId(impObj()->cmlstyleID());
}

PyDbObjectId PyDbDatabase::colorDictionaryId() const
{
    return PyDbObjectId(impObj()->colorDictionaryId());
}

PyDbObjectId PyDbDatabase::continuousLinetype() const
{
    return PyDbObjectId(impObj()->continuousLinetype());
}

Adesk::Int16 PyDbDatabase::coords() const
{
    return impObj()->coords();
}

Adesk::UInt32 PyDbDatabase::countEmptyObjects(const Adesk::Int32 flags)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return impObj()->countEmptyObjects(flags);
#endif
}

PyDbObjectId PyDbDatabase::detailViewStyle() const
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return PyDbObjectId(impObj()->detailViewStyle());
#endif
}

PyDbObjectId PyDbDatabase::detailViewStyleDictionaryId() const
{
    return PyDbObjectId(impObj()->detailViewStyleDictionaryId());
}

bool PyDbDatabase::dimaso() const
{
    return impObj()->dimaso();
}

Adesk::UInt8 PyDbDatabase::dimAssoc() const
{
    return impObj()->dimAssoc();
}

int PyDbDatabase::dimfit() const
{
    return impObj()->dimfit();
}

bool PyDbDatabase::dimsho() const
{
    return impObj()->dimsho();
}

PyDbObjectId PyDbDatabase::dimstyle() const
{
    return PyDbObjectId(impObj()->dimstyle());
}

PyDbObjectId PyDbDatabase::dimStyleTableId() const
{
    return PyDbObjectId(impObj()->dimStyleTableId());
}

int PyDbDatabase::dimunit() const
{
    return impObj()->dimunit();
}

void PyDbDatabase::disablePartialOpen()
{
    impObj()->disablePartialOpen();
}

void PyDbDatabase::disableUndoRecording(bool disable)
{
    impObj()->disableUndoRecording(disable);
}

bool PyDbDatabase::dispSilh() const
{
    return impObj()->dispSilh();
}

Adesk::Int16 PyDbDatabase::dragmode() const
{
    return impObj()->dragmode();
}

PyDbObjectId PyDbDatabase::dragVisStyle() const
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return PyDbObjectId(impObj()->dragVisStyle());
#endif
}

Adesk::UInt8 PyDbDatabase::drawOrderCtl() const
{
    return impObj()->drawOrderCtl();
}

Adesk::UInt8 PyDbDatabase::dwfframe() const
{
    return impObj()->dwfframe();
}

bool PyDbDatabase::dwgFileWasSavedByAutodeskSoftware() const
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return impObj()->dwgFileWasSavedByAutodeskSoftware();
#endif
}

void PyDbDatabase::dxfIn(const std::string& dxfFilename)
{
    return PyThrowBadEs(impObj()->dxfIn(utf8_to_wstr(dxfFilename).c_str()));
}

void PyDbDatabase::dxfOut(const std::string& dxfFilename)
{
    return PyThrowBadEs(impObj()->dxfOut(utf8_to_wstr(dxfFilename).c_str()));
}

double PyDbDatabase::elevation() const
{
    return impObj()->elevation();
}

Adesk::UInt32 PyDbDatabase::eraseEmptyObjects(const Adesk::Int32 flags)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return impObj()->eraseEmptyObjects(flags);
#endif
}

AcGePoint3d PyDbDatabase::extmax() const
{
    return impObj()->extmax();
}

AcGePoint3d PyDbDatabase::extmin() const
{
    return impObj()->extmin();
}

double PyDbDatabase::facetres() const
{
    return impObj()->facetres();
}

double PyDbDatabase::filletrad() const
{
    return impObj()->filletrad();
}

bool PyDbDatabase::fillmode() const
{
    return impObj()->fillmode();
}

void PyDbDatabase::forceWblockDatabaseCopy()
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    impObj()->forceWblockDatabaseCopy();
#endif
}

std::string PyDbDatabase::geoCoordinateSystemId() const
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return wstr_to_utf8(impObj()->geoCoordinateSystemId());
#endif
}

bool PyDbDatabase::geoMarkerVisibility() const
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return impObj()->geoMarkerVisibility();
#endif
}

double PyDbDatabase::get3dDwfPrec() const
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return impObj()->get3dDwfPrec();
#endif
}

PyDbObjectId PyDbDatabase::getAcDbObjectId1(bool createIfNotFound, const PyDbHandle& objHandle)
{
    PyDbObjectId retId;
    PyThrowBadEs(impObj()->getAcDbObjectId(retId.m_id, createIfNotFound, objHandle.m_hnd));
    return retId;
}

PyDbObjectId PyDbDatabase::getAcDbObjectId2(bool createIfNotFound, const PyDbHandle& objHandle, Adesk::UInt32 xRefId)
{
    PyDbObjectId retId;
    PyThrowBadEs(impObj()->getAcDbObjectId(retId.m_id, createIfNotFound, objHandle.m_hnd, xRefId));
    return retId;
}

AcDb::PlotStyleNameType PyDbDatabase::getCePlotStyleNameId(PyDbObjectId& id) const
{
    return impObj()->getCePlotStyleNameId(id.m_id);
}

bool PyDbDatabase::isAppRegistered(const std::string& pszAppName) const
{
#ifdef ARX2023
    return impObj()->isAppRegistered(utf8_to_wstr(pszAppName).c_str());
#else
    throw PyNotimplementedByHost();
#endif // 
}

std::string PyDbDatabase::dimapost() const
{
    return wstr_to_utf8(impObj()->dimapost());
}

PyDbObjectId PyDbDatabase::dimblk() const
{
    return PyDbObjectId(impObj()->dimblk());
}

PyDbObjectId PyDbDatabase::dimblk1() const
{
    return PyDbObjectId(impObj()->dimblk1());
}

PyDbObjectId PyDbDatabase::dimblk2() const
{
    return PyDbObjectId(impObj()->dimblk2());
}

std::string PyDbDatabase::dimpost() const
{
    return wstr_to_utf8(impObj()->dimpost());
}

PyDbObjectId PyDbDatabase::getDimstyleParentId(PyDbObjectId& childStyle) const
{
    return PyDbObjectId(impObj()->getDimstyleParentId(childStyle.m_id));
}

AcDb::LineWeight PyDbDatabase::getNearestLineWeight(int weight)
{
    return AcDbDatabase::getNearestLineWeight(weight);
}

boost::python::list PyDbDatabase::getViewportArray() const
{
    AcDbObjectIdArray vportIds;
    PyThrowBadEs(impObj()->getViewportArray(vportIds));
    return ObjectIdArrayToPyList(vportIds);
}

boost::python::list PyDbDatabase::getVisualStyleList()
{
    AcArray<const ACHAR*> vstyleList;
    PyThrowBadEs(impObj()->getVisualStyleList(vstyleList));
    PyAutoLockGIL lock;
    boost::python::list pyvstyleList;
    for (const auto& item : vstyleList)
        pyvstyleList(wstr_to_utf8(item));
    return pyvstyleList;
}

PyDbObjectId PyDbDatabase::globalMaterial() const
{
    return PyDbObjectId(impObj()->globalMaterial());
}

PyDbObjectId PyDbDatabase::groupDictionaryId() const
{
    return PyDbObjectId(impObj()->groupDictionaryId());
}

void PyDbDatabase::insert1(PyDbObjectId& blockId, const std::string& pBlockName, PyDbDatabase& db, bool preserveSourceDatabase)
{
    return PyThrowBadEs(impObj()->insert(blockId.m_id, utf8_to_wstr(pBlockName).c_str(), db.impObj(), preserveSourceDatabase));
}

void PyDbDatabase::insert2(PyDbObjectId& blockId, const std::string& pSourceBlockName, const std::string& pDestinationBlockName, PyDbDatabase& db, bool preserveSourceDatabase)
{
    return PyThrowBadEs(impObj()->insert(blockId.m_id, utf8_to_wstr(pSourceBlockName).c_str(), utf8_to_wstr(pDestinationBlockName).c_str(), db.impObj(), preserveSourceDatabase));
}

void PyDbDatabase::insert3(const AcGeMatrix3d& xform, PyDbDatabase& db, bool preserveSourceDatabase)
{
    return PyThrowBadEs(impObj()->insert(xform, db.impObj(), preserveSourceDatabase));
}

Adesk::UInt8 PyDbDatabase::haloGap() const
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return impObj()->haloGap();
#endif
}

PyDbHandle PyDbDatabase::handseed() const
{
    PyDbHandle handle;
    handle.m_hnd = impObj()->handseed();
    return  handle;
}

bool PyDbDatabase::hasClass(const PyRxClass& pClass) const
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return impObj()->hasClass(pClass.impObj());
#endif
}

Adesk::UInt8 PyDbDatabase::hideText() const
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return impObj()->hideText();
#endif
}

bool PyDbDatabase::hpInherit() const
{
    return impObj()->hpInherit();
}

AcGePoint2d PyDbDatabase::hpOrigin() const
{
    return impObj()->hpOrigin();
}

Adesk::UInt8 PyDbDatabase::indexctl() const
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return impObj()->indexctl();
#endif
}

AcDb::UnitsValue PyDbDatabase::insunits() const
{
    return impObj()->insunits();
}

PyDbObjectId PyDbDatabase::interfereVpVisStyle() const
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return PyDbObjectId(impObj()->interfereVpVisStyle());
#endif
}

Adesk::UInt16 PyDbDatabase::intersectColor() const
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return impObj()->intersectDisplay();
#endif
}

Adesk::UInt8 PyDbDatabase::intersectDisplay() const
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return impObj()->intersectDisplay();
#endif
}

bool PyDbDatabase::isBeingDestroyed() const
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return impObj()->isBeingDestroyed();
#endif
}

bool PyDbDatabase::isEMR() const
{
    return impObj()->isEMR();
}

bool PyDbDatabase::isObjectNonPersistent(const PyDbObjectId& id)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return AcDbDatabase::isObjectNonPersistent(id.m_id);
#endif
}

Adesk::Int16 PyDbDatabase::isolines() const
{
    return impObj()->isolines();
}

bool PyDbDatabase::isPartiallyOpened() const
{
    return impObj()->isPartiallyOpened();
}

bool PyDbDatabase::isPucsOrthographic(AcDb::OrthographicView& orthoView) const
{
    return impObj()->isPucsOrthographic(orthoView);
}

bool PyDbDatabase::isUcsOrthographic(AcDb::OrthographicView& orthoView) const
{
    return impObj()->isUcsOrthographic(orthoView);
}

bool PyDbDatabase::isValidLineWeight(int weight)
{
    return AcDbDatabase::isValidLineWeight(weight);
}

AcDb::JoinStyle PyDbDatabase::joinStyle() const
{
    return impObj()->joinStyle();
}

int PyDbDatabase::lastSavedAsMaintenanceVersion() const
{
    return impObj()->lastSavedAsMaintenanceVersion();
}

int PyDbDatabase::lastSavedAsVersion() const
{
    return impObj()->lastSavedAsVersion();
}

double PyDbDatabase::latitude() const
{
    return impObj()->latitude();
}

Adesk::UInt8 PyDbDatabase::layerEval() const
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return impObj()->layerEval();
#endif
}

Adesk::Int16 PyDbDatabase::layerNotify() const
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return impObj()->layerNotify();
#endif
}

PyDbObjectId PyDbDatabase::layerTableId() const
{
    return PyDbObjectId(impObj()->layerTableId());
}

PyDbObjectId PyDbDatabase::layerZero() const
{
    return PyDbObjectId(impObj()->layerZero());
}

PyDbObjectId PyDbDatabase::layoutDictionaryId() const
{
    return PyDbObjectId(impObj()->layoutDictionaryId());
}

double PyDbDatabase::lensLength() const
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return impObj()->lensLength();
#endif
}

Adesk::UInt8 PyDbDatabase::lightGlyphDisplay() const
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return impObj()->lightGlyphDisplay();
#endif
}

Adesk::UInt8 PyDbDatabase::lightingUnits() const
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return impObj()->lightingUnits();
#endif
}

bool PyDbDatabase::lightsInBlocks() const
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return impObj()->lightsInBlocks();
#endif
}

bool PyDbDatabase::limcheck() const
{
    return impObj()->limcheck();
}

AcGePoint2d PyDbDatabase::limmax() const
{
    return impObj()->limmax();
}

AcGePoint2d PyDbDatabase::limmin() const
{
    return impObj()->limmin();
}

PyDbObjectId PyDbDatabase::linetypeTableId() const
{
    return PyDbObjectId(impObj()->linetypeTableId());
}

bool PyDbDatabase::lineWeightDisplay() const
{
    return impObj()->lineWeightDisplay();
}

void PyDbDatabase::loadLineTypeFile(const std::string& ltn, const std::string& filename)
{
    return PyThrowBadEs(impObj()->loadLineTypeFile(utf8_to_wstr(ltn).c_str(), utf8_to_wstr(filename).c_str()));
}

double PyDbDatabase::loftAng1() const
{
    return impObj()->loftAng1();
}

double PyDbDatabase::loftAng2() const
{
    return impObj()->loftAng2();
}

double PyDbDatabase::loftMag1() const
{
    return impObj()->loftMag1();
}

double PyDbDatabase::loftMag2() const
{
    return impObj()->loftMag2();
}

Adesk::UInt8 PyDbDatabase::loftNormals() const
{
    return impObj()->loftNormals();
}

Adesk::UInt16 PyDbDatabase::loftParam() const
{
    return impObj()->loftParam();
}

double PyDbDatabase::longitude() const
{
    return impObj()->longitude();
}

double PyDbDatabase::ltscale() const
{
    return impObj()->ltscale();
}

Adesk::Int16 PyDbDatabase::lunits() const
{
    return impObj()->lunits();
}

Adesk::Int16 PyDbDatabase::luprec() const
{
    return impObj()->luprec();
}

void PyDbDatabase::registerApp(const std::string& pszAppName)
{
#if defined(_ARXTARGET) && (_ARXTARGET >= 242)
    return PyThrowBadEs(impObj()->registerApp(utf8_to_wstr(pszAppName).c_str()));
#else
    throw PyNotimplementedByHost();
#endif
}

int PyDbDatabase::maintenanceReleaseVersion() const
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return impObj()->maintenanceReleaseVersion();
#endif
}

void PyDbDatabase::markObjectNonPersistent(const PyDbObjectId& id, bool value)
{
#ifndef ACADAPP
    throw PyNotimplementedByHost();
#else
    return AcDbDatabase::markObjectNonPersistent(id.m_id, value);
#endif
}

PyDbObjectId PyDbDatabase::materialDictionaryId() const
{
    return PyDbObjectId(impObj()->materialDictionaryId());
}

Adesk::Int16 PyDbDatabase::maxactvp() const
{
    return impObj()->maxactvp();
}

AcDb::MeasurementValue PyDbDatabase::measurement() const
{
    return impObj()->measurement();
}

bool PyDbDatabase::mirrtext() const
{
    return impObj()->mirrtext();
}

double PyDbDatabase::mleaderscale() const
{
    return impObj()->mleaderscale();
}

PyDbObjectId PyDbDatabase::mleaderstyle() const
{
    return PyDbObjectId(impObj()->mleaderstyle());
}

PyDbObjectId PyDbDatabase::mleaderStyleDictionaryId() const
{
    return PyDbObjectId(impObj()->mleaderStyleDictionaryId());
}

PyDbObjectId PyDbDatabase::mLStyleDictionaryId() const
{
    return PyDbObjectId(impObj()->mLStyleDictionaryId());
}

bool PyDbDatabase::msltscale() const
{
    return impObj()->msltscale();
}

double PyDbDatabase::msOleScale() const
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return impObj()->msOleScale();
#endif
}

PyDbObjectId PyDbDatabase::namedObjectsDictionaryId() const
{
    return PyDbObjectId(impObj()->namedObjectsDictionaryId());
}

bool PyDbDatabase::needsRecovery() const
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return impObj()->needsRecovery();
#endif
}

double PyDbDatabase::northDirection() const
{
    return impObj()->northDirection();
}

Adesk::Int32 PyDbDatabase::numberOfSaves() const
{
    return impObj()->numberOfSaves();
}

Adesk::UInt16 PyDbDatabase::obscuredColor() const
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return impObj()->obscuredColor();
#endif
}

Adesk::UInt8 PyDbDatabase::obscuredLineType() const
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return impObj()->obscuredLineType();
#endif
}

bool PyDbDatabase::oleStartUp() const
{
    return impObj()->oleStartUp();
}

int PyDbDatabase::originalFileMaintenanceVersion() const
{
    return impObj()->originalFileMaintenanceVersion();
}

std::string PyDbDatabase::originalFileName() const
{
    return wstr_to_utf8(impObj()->originalFileName());
}

int PyDbDatabase::originalFileSavedByMaintenanceVersion() const
{
    return impObj()->originalFileSavedByMaintenanceVersion();
}

int PyDbDatabase::originalFileSavedByVersion() const
{
    return impObj()->originalFileSavedByVersion();
}

int PyDbDatabase::originalFileVersion() const
{
    return impObj()->originalFileVersion();
}

bool PyDbDatabase::orthomode() const
{
    return impObj()->orthomode();
}

PyDbObjectId PyDbDatabase::paperSpaceVportId() const
{
    return PyDbObjectId(impObj()->paperSpaceVportId());
}

Adesk::Int8 PyDbDatabase::pdfframe() const
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return impObj()->pdfframe();
#endif
}

Adesk::Int16 PyDbDatabase::pdmode() const
{
    return impObj()->pdmode();
}

double PyDbDatabase::pdsize() const
{
    return impObj()->pdsize();
}

double PyDbDatabase::pelevation() const
{
    return impObj()->pelevation();
}

AcGePoint3d PyDbDatabase::pextmax() const
{
    return impObj()->pextmax();
}

AcGePoint3d PyDbDatabase::pextmin() const
{
    return impObj()->pextmin();
}

Adesk::Int16 PyDbDatabase::pickstyle() const
{
    return impObj()->pickstyle();
}

AcGePoint3d PyDbDatabase::pinsbase() const
{
    return impObj()->pinsbase();
}

bool PyDbDatabase::plimcheck() const
{
    return impObj()->plimcheck();
}

AcGePoint2d PyDbDatabase::plimmax() const
{
    return impObj()->plimmax();
}

AcGePoint2d PyDbDatabase::plimmin() const
{
    return impObj()->plimmin();
}

bool PyDbDatabase::plineEllipse() const
{
    return impObj()->plineEllipse();
}

bool PyDbDatabase::plinegen() const
{
    return impObj()->plinegen();
}

double PyDbDatabase::plinewid() const
{
    return impObj()->plinewid();
}

PyDbObjectId PyDbDatabase::plotSettingsDictionaryId() const
{
    return PyDbObjectId(impObj()->plotSettingsDictionaryId());
}

bool PyDbDatabase::plotStyleMode() const
{
    return impObj()->plotStyleMode();
}

PyDbObjectId PyDbDatabase::plotStyleNameDictionaryId() const
{
    return PyDbObjectId(impObj()->plotStyleNameDictionaryId());
}

Adesk::Int16 PyDbDatabase::previewType() const
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return impObj()->previewType();
#endif
}

bool PyDbDatabase::psltscale() const
{
    return impObj()->psltscale();
}

double PyDbDatabase::psolHeight() const
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return impObj()->psolHeight();
#endif
}

double PyDbDatabase::psolWidth() const
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return impObj()->psolWidth();
#endif
}

PyDbObjectId PyDbDatabase::pucsBase() const
{
    return PyDbObjectId(impObj()->pucsBase());
}

PyDbObjectId PyDbDatabase::pucsname() const
{
    return PyDbObjectId(impObj()->pucsname());
}

AcGePoint3d PyDbDatabase::pucsorg() const
{
    return impObj()->pucsorg();
}

AcGeVector3d PyDbDatabase::pucsxdir() const
{
    return impObj()->pucsxdir();
}

AcGeVector3d PyDbDatabase::pucsydir() const
{
    return impObj()->pucsydir();
}

boost::python::list PyDbDatabase::purge()
{
    AcDbObjectIdArray ids;
    PyThrowBadEs(impObj()->purge(ids));
    return ObjectIdArrayToPyList(ids);
}

bool PyDbDatabase::qtextmode() const
{
    return impObj()->qtextmode();
}

void PyDbDatabase::reclaimMemoryFromErasedObjects(const boost::python::list& erasedObjects)
{
    const AcDbObjectIdArray ids = PyListToObjectIdArray(erasedObjects);
    return PyThrowBadEs(impObj()->reclaimMemoryFromErasedObjects(ids));
}

PyDbObjectId PyDbDatabase::regAppTableId() const
{
    return PyDbObjectId(impObj()->regAppTableId());
}

bool PyDbDatabase::regenmode() const
{
    return impObj()->regenmode();
}

void PyDbDatabase::resetTimes()
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->resetTimes());
#endif
}

void PyDbDatabase::restoreForwardingXrefSymbols()
{
    return PyThrowBadEs(impObj()->restoreForwardingXrefSymbols());
}

void PyDbDatabase::restoreOriginalXrefSymbols()
{
    return PyThrowBadEs(impObj()->restoreOriginalXrefSymbols());
}

bool PyDbDatabase::retainOriginalThumbnailBitmap() const
{
    return impObj()->retainOriginalThumbnailBitmap();
}

Adesk::Int16 PyDbDatabase::saveproxygraphics() const
{
    return impObj()->saveproxygraphics();
}

PyDbObjectId PyDbDatabase::scaleListDictionaryId() const
{
    return PyDbObjectId(impObj()->scaleListDictionaryId());
}

PyDbObjectId PyDbDatabase::sectionViewStyle() const
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return PyDbObjectId(impObj()->sectionViewStyle());
#endif
}

PyDbObjectId PyDbDatabase::sectionViewStyleDictionaryId() const
{
    return PyDbObjectId(impObj()->sectionViewStyleDictionaryId());
}

void PyDbDatabase::set3dDwfPrec(double DwfPrec)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->set3dDwfPrec(DwfPrec));
#endif
}

void PyDbDatabase::setAngbase(double angle)
{
    return PyThrowBadEs(impObj()->setAngbase(angle));
}

void PyDbDatabase::setAngdir(bool dir)
{
    return PyThrowBadEs(impObj()->setAngdir(dir));
}

void PyDbDatabase::setAnnoAllVisible(bool allvis)
{
    return PyThrowBadEs(impObj()->setAnnoAllVisible(allvis));
}

void PyDbDatabase::setAttdia(bool dia)
{
    return PyThrowBadEs(impObj()->setAttdia(dia));
}

void PyDbDatabase::setAttmode(Adesk::Int16 mode)
{
    return PyThrowBadEs(impObj()->setAttmode(mode));
}

void PyDbDatabase::setAttreq(bool req)
{
    return PyThrowBadEs(impObj()->setAttreq(req));
}

void PyDbDatabase::setAunits(Adesk::Int16 aunits)
{
    return PyThrowBadEs(impObj()->setAunits(aunits));
}

void PyDbDatabase::setAuprec(Adesk::Int16 auprec)
{
    return PyThrowBadEs(impObj()->setAuprec(auprec));
}

void PyDbDatabase::setBlipmode(bool mode)
{
    return PyThrowBadEs(impObj()->setBlipmode(mode));
}

void PyDbDatabase::setCameraDisplay(bool cameraDisplay)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setCameraDisplay(cameraDisplay));
#endif
}

void PyDbDatabase::setCameraHeight(double cameraHeight)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setCameraHeight(cameraHeight));
#endif
}

void PyDbDatabase::setCannoscale(PyDbAnnotationScale& val)
{
#ifdef ZRXAPP
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setCannoscale(val.impObj()));
#endif
}

void PyDbDatabase::setCDynDisplayMode(Adesk::Int16 val)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setCDynDisplayMode(val));
#endif
}

void PyDbDatabase::setCecolor(const AcCmColor& color)
{
    return PyThrowBadEs(impObj()->setCecolor(color));
}

void PyDbDatabase::setCeltscale(double scale)
{
    return PyThrowBadEs(impObj()->setCeltscale(scale));
}

void PyDbDatabase::setCeltype(const PyDbObjectId& id)
{
    return PyThrowBadEs(impObj()->setCeltype(id.m_id));
}

void PyDbDatabase::setCelweight(AcDb::LineWeight weight)
{
    return PyThrowBadEs(impObj()->setCelweight(weight));
}

void PyDbDatabase::setCePlotStyleName(AcDb::PlotStyleNameType type, const PyDbObjectId& id)
{
    return PyThrowBadEs(impObj()->setCePlotStyleName(type, id.m_id));
}

void PyDbDatabase::setCetransparency(const AcCmTransparency& transparency)
{
    return PyThrowBadEs(impObj()->setCetransparency(transparency));
}

void PyDbDatabase::setChamfera(double val)
{
    return PyThrowBadEs(impObj()->setChamfera(val));
}

void PyDbDatabase::setChamferb(double val)
{
    return PyThrowBadEs(impObj()->setChamferb(val));
}

void PyDbDatabase::setChamferc(double val)
{
    return PyThrowBadEs(impObj()->setChamferc(val));
}

void PyDbDatabase::setChamferd(double val)
{
    return PyThrowBadEs(impObj()->setChamferd(val));
}

void PyDbDatabase::setClayer(const PyDbObjectId& id)
{
    return PyThrowBadEs(impObj()->setClayer(id.m_id));
}

void PyDbDatabase::setCmaterial(const PyDbObjectId& id)
{
    return PyThrowBadEs(impObj()->setCmaterial(id.m_id));
}

void PyDbDatabase::setCmljust(Adesk::Int16 just)
{
    return PyThrowBadEs(impObj()->setCmljust(just));
}

void PyDbDatabase::setCmlscale(double scale)
{
    return PyThrowBadEs(impObj()->setCmlscale(scale));
}

void PyDbDatabase::setCmlstyleID(const PyDbObjectId& id)
{
    return PyThrowBadEs(impObj()->setCmlstyleID(id.m_id));
}

void PyDbDatabase::setCoords(Adesk::Int16 _coords)
{
    return PyThrowBadEs(impObj()->setCoords(_coords));
}

void PyDbDatabase::setCshadow(Adesk::UInt8 val)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setCshadow(val));
#endif
}

void PyDbDatabase::setDelUsedObj(Adesk::Int16 deleteObj)
{
    return PyThrowBadEs(impObj()->setDelUsedObj(deleteObj));
}

void PyDbDatabase::setDgnframe(Adesk::UInt8 val)
{
#ifdef ARXAPP
    return PyThrowBadEs(impObj()->setDgnframe(val));
#else
    throw PyNotimplementedByHost();
#endif
}

void PyDbDatabase::setDimaso(bool aso)
{
    return PyThrowBadEs(impObj()->setDimaso(aso));
}

void PyDbDatabase::setDimAssoc(Adesk::UInt8 val)
{
    return PyThrowBadEs(impObj()->setDimAssoc(val));
}

void PyDbDatabase::setDimfit(int fit)
{
    return PyThrowBadEs(impObj()->setDimfit(fit));
}

void PyDbDatabase::setDimsho(bool sho)
{
    return PyThrowBadEs(impObj()->setDimsho(sho));
}

void PyDbDatabase::setDimstyle(const PyDbObjectId& id)
{
    return PyThrowBadEs(impObj()->setDimstyle(id.m_id));
}

void PyDbDatabase::setDimstyleData1(PyDbDimStyleTableRecord& pRec)
{
    return PyThrowBadEs(impObj()->setDimstyleData(pRec.impObj()));
}

void PyDbDatabase::setDimstyleData2(const PyDbObjectId& id)
{
    return PyThrowBadEs(impObj()->setDimstyleData(id.m_id));
}

void PyDbDatabase::setDimunit(int unit)
{
    return PyThrowBadEs(impObj()->setDimunit(unit));
}

void PyDbDatabase::setDispSilh(bool silh)
{
    return PyThrowBadEs(impObj()->setDispSilh(silh));
}

void PyDbDatabase::setDragmode(Adesk::Int16 mode)
{
    return PyThrowBadEs(impObj()->setDragmode(mode));
}

void PyDbDatabase::setDragVisStyle(const PyDbObjectId& id)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setDragVisStyle(id.m_id));
#endif
}

void PyDbDatabase::setDrawOrderCtl(Adesk::UInt8 val)
{
    return PyThrowBadEs(impObj()->setDrawOrderCtl(val));
}

void PyDbDatabase::setDwfframe(Adesk::UInt8 val)
{
    return PyThrowBadEs(impObj()->setDwfframe(val));
}

void PyDbDatabase::setElevation(double elev)
{
    return PyThrowBadEs(impObj()->setElevation(elev));
}

void PyDbDatabase::setEndCaps(AcDb::EndCaps type)
{
    return PyThrowBadEs(impObj()->setEndCaps(type));
}

void PyDbDatabase::setExtmax(const AcGePoint3d& max)
{
    return PyThrowBadEs(impObj()->setExtmax(max));
}

void PyDbDatabase::setExtmin(const AcGePoint3d& min)
{
    return PyThrowBadEs(impObj()->setExtmin(min));
}

void PyDbDatabase::setFacetres(double _facetres)
{
    return PyThrowBadEs(impObj()->setFacetres(_facetres));
}

void PyDbDatabase::setFilletrad(double radius)
{
    return PyThrowBadEs(impObj()->setFilletrad(radius));
}

void PyDbDatabase::setFillmode(bool mode)
{
    return PyThrowBadEs(impObj()->setFillmode(mode));
}

void PyDbDatabase::saveAs(const std::string& fileName)
{
    return PyThrowBadEs(impObj()->saveAs(utf8_to_wstr(fileName).c_str()));
}

void PyDbDatabase::setFingerprintGuid(const std::string& newGuid)
{
    return PyThrowBadEs(impObj()->setFingerprintGuid(utf8_to_wstr(newGuid).c_str()));
}

void PyDbDatabase::setFullSaveRequired()
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    impObj()->setFullSaveRequired();
#endif
}

void PyDbDatabase::readDwgFile(const char* fileName)
{
    std::wstring wsfileName{ utf8_to_wstr(fileName) };
    return PyThrowBadEs(impObj()->readDwgFile(wsfileName.c_str()));
}

void PyDbDatabase::readDwgFile2(const char* fileName, int mode, bool bAllowCPConversion, const std::string& password)
{
    std::wstring wsfileName{ utf8_to_wstr(fileName) };
    std::wstring wspassword{ utf8_to_wstr(password) };
    return PyThrowBadEs(impObj()->readDwgFile(wsfileName.c_str(), (AcDbDatabase::OpenMode)mode, bAllowCPConversion, wspassword.c_str()));
}

std::string PyDbDatabase::getFilename()
{
    const TCHAR* path = nullptr;
    if (impObj()->getFilename(path) == eOk && path != nullptr)
        return std::string{ wstr_to_utf8(path) };
    return std::string{ };
}

PyDbObjectId PyDbDatabase::currentSpaceId() const
{
    return PyDbObjectId(impObj()->currentSpaceId());
}

PyDbObjectId PyDbDatabase::blockTableId() const
{
    return PyDbObjectId(impObj()->blockTableId());
}

PyDbObjectId PyDbDatabase::modelSpaceId() const
{
    return PyDbObjectId(acdbSymUtil()->blockModelSpaceId(impObj()));
}

void PyDbDatabase::setGeoMarkerVisibility(bool value)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setGeoMarkerVisibility(value));
#endif
}

void PyDbDatabase::setHaloGap(Adesk::UInt8 val)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setHaloGap(val));
#endif
}

void PyDbDatabase::setHandseed(const PyDbHandle& handle)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setHandseed(handle.m_hnd));
#endif
}

void PyDbDatabase::setHideText(Adesk::UInt8 val)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setHideText(val));
#endif
}

void PyDbDatabase::setHpInherit(const bool inherit)
{
    return PyThrowBadEs(impObj()->setHpInherit(inherit));
}

void PyDbDatabase::setHpOrigin(const AcGePoint2d& origin)
{
    return PyThrowBadEs(impObj()->setHpOrigin(origin));
}

void PyDbDatabase::setHyperlinkBase(const std::string& val)
{
    return PyThrowBadEs(impObj()->setHyperlinkBase(utf8_to_wstr(val).c_str()));
}

void PyDbDatabase::setIndexctl(Adesk::UInt8 val)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setIndexctl(val));
#endif
}

void PyDbDatabase::setInsbase(const AcGePoint3d& base)
{
    return PyThrowBadEs(impObj()->setInsbase(base));
}

void PyDbDatabase::setInsunits(const AcDb::UnitsValue units)
{
    return PyThrowBadEs(impObj()->setInsunits(units));
}

void PyDbDatabase::setInterfereColor(const AcCmColor& color)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setInterfereColor(color));
#endif
}

void PyDbDatabase::setInterfereObjVisStyle(const PyDbObjectId& id)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setInterfereObjVisStyle(id.m_id));
#endif
}

void PyDbDatabase::setInterfereVpVisStyle(const PyDbObjectId& id)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setInterfereVpVisStyle(id.m_id));
#endif
}

void PyDbDatabase::setIntersectColor(Adesk::UInt16 val)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setIntersectColor(val));
#endif
}

void PyDbDatabase::setIntersectDisplay(Adesk::UInt8 val)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setIntersectDisplay(val));
#endif
}

void PyDbDatabase::setIsolines(Adesk::Int16 isolines)
{
    return PyThrowBadEs(impObj()->setIsolines(isolines));
}

void PyDbDatabase::setJoinStyle(AcDb::JoinStyle style)
{
    return PyThrowBadEs(impObj()->setJoinStyle(style));
}

void PyDbDatabase::setLatitude(double lat)
{
    return PyThrowBadEs(impObj()->setLatitude(lat));
}

void PyDbDatabase::setLayerEval(Adesk::UInt8 val)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setLayerEval(val));
#endif
}

void PyDbDatabase::setLayerNotify(Adesk::Int16 val)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setLayerNotify(val));
#endif
}

void PyDbDatabase::setLensLength(const double _lensLength)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setLensLength(_lensLength));
#endif
}

void PyDbDatabase::setLightGlyphDisplay(Adesk::UInt8 val)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setLightGlyphDisplay(val));
#endif
}

void PyDbDatabase::setLightingUnits(Adesk::UInt8 val)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setLightingUnits(val));
#endif
}

void PyDbDatabase::setLightsInBlocks(bool val)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setLightsInBlocks(val));
#endif
}

void PyDbDatabase::setLimcheck(bool check)
{
    return PyThrowBadEs(impObj()->setLimcheck(check));
}

void PyDbDatabase::setLimmax(const AcGePoint2d& max)
{
    return PyThrowBadEs(impObj()->setLimmax(max));
}

void PyDbDatabase::setLimmin(const AcGePoint2d& min)
{
    return PyThrowBadEs(impObj()->setLimmin(min));
}

void PyDbDatabase::setLineWeightDisplay(bool display)
{
    return PyThrowBadEs(impObj()->setLineWeightDisplay(display));
}

void PyDbDatabase::setLoftAng1(double ang1)
{
    return PyThrowBadEs(impObj()->setLoftAng1(ang1));
}

void PyDbDatabase::setLoftAng2(double ang2)
{
    return PyThrowBadEs(impObj()->setLoftAng2(ang2));
}

void PyDbDatabase::setLoftMag1(double mag1)
{
    return PyThrowBadEs(impObj()->setLoftMag1(mag1));
}

void PyDbDatabase::setLoftMag2(double mag2)
{
    return PyThrowBadEs(impObj()->setLoftMag2(mag2));
}

void PyDbDatabase::setLoftNormals(Adesk::UInt8 value)
{
    return PyThrowBadEs(impObj()->setLoftNormals(value));
}

void PyDbDatabase::setLoftParam(Adesk::UInt16 flags)
{
    return PyThrowBadEs(impObj()->setLoftParam(flags));
}

void PyDbDatabase::setLongitude(double lng)
{
    return PyThrowBadEs(impObj()->setLongitude(lng));
}

void PyDbDatabase::setLtscale(double scale)
{
    return PyThrowBadEs(impObj()->setLtscale(scale));
}

void PyDbDatabase::setLunits(Adesk::Int16 lunits)
{
    return PyThrowBadEs(impObj()->setLunits(lunits));
}

void PyDbDatabase::setLuprec(Adesk::Int16 prec)
{
    return PyThrowBadEs(impObj()->setLuprec(prec));
}

void PyDbDatabase::setMaxactvp(Adesk::Int16 max)
{
    return PyThrowBadEs(impObj()->setMaxactvp(max));
}

void PyDbDatabase::setMeasurement(AcDb::MeasurementValue type)
{
    return PyThrowBadEs(impObj()->setMeasurement(type));
}

void PyDbDatabase::setMirrtext(bool mirror)
{
    return PyThrowBadEs(impObj()->setMirrtext(mirror));
}

void PyDbDatabase::setMLeaderscale(double scale)
{
    return PyThrowBadEs(impObj()->setMLeaderscale(scale));
}

void PyDbDatabase::setMLeaderstyle(const PyDbObjectId& objId)
{
    return PyThrowBadEs(impObj()->setMLeaderstyle(objId.m_id));
}

void PyDbDatabase::setMsltscale(bool val)
{
    return PyThrowBadEs(impObj()->setMsltscale(val));
}

void PyDbDatabase::setMsOleScale(double val)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setMsOleScale(val));
#endif
}

void PyDbDatabase::setNorthDirection(double northdir)
{
    return PyThrowBadEs(impObj()->setNorthDirection(northdir));
}

void PyDbDatabase::setObscuredColor(Adesk::UInt16 val)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setObscuredColor(val));
#endif
}

void PyDbDatabase::setObscuredLineType(Adesk::UInt8 val)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setObscuredLineType(val));
#endif
}

void PyDbDatabase::setOleStartUp(bool val)
{
    return PyThrowBadEs(impObj()->setOleStartUp(val));
}

void PyDbDatabase::setOrthomode(bool mode)
{
    return PyThrowBadEs(impObj()->setOrthomode(mode));
}

void PyDbDatabase::setPdfframe(Adesk::Int8 val)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setPdfframe(val));
#endif
}

void PyDbDatabase::setPdmode(Adesk::Int16 mode)
{
    return PyThrowBadEs(impObj()->setPdmode(mode));
}

void PyDbDatabase::setPdsize(double size)
{
    return PyThrowBadEs(impObj()->setPdsize(size));
}

void PyDbDatabase::setPelevation(double elev)
{
    return PyThrowBadEs(impObj()->setPelevation(elev));
}

void PyDbDatabase::setPextmax(const AcGePoint3d& max)
{
    return PyThrowBadEs(impObj()->setPextmax(max));
}

void PyDbDatabase::setPextmin(const AcGePoint3d& min)
{
    return PyThrowBadEs(impObj()->setPextmin(min));
}

void PyDbDatabase::setPickstyle(Adesk::Int16 style)
{
    return PyThrowBadEs(impObj()->setPickstyle(style));
}

void PyDbDatabase::setPinsbase(const AcGePoint3d& base)
{
    return PyThrowBadEs(impObj()->setPinsbase(base));
}

void PyDbDatabase::setPlimcheck(bool check)
{
    return PyThrowBadEs(impObj()->setPlimcheck(check));
}

void PyDbDatabase::setPlimmax(const AcGePoint2d& max)
{
    return PyThrowBadEs(impObj()->setPlimmax(max));
}

void PyDbDatabase::setPlimmin(const AcGePoint2d& min)
{
    return PyThrowBadEs(impObj()->setPlimmin(min));
}

void PyDbDatabase::setPlineEllipse(bool pline)
{
    return PyThrowBadEs(impObj()->setPlineEllipse(pline));
}

void PyDbDatabase::setPlinegen(bool gen)
{
    return PyThrowBadEs(impObj()->setPlinegen(gen));
}

void PyDbDatabase::setPlinewid(double width)
{
    return PyThrowBadEs(impObj()->setPlinewid(width));
}

void PyDbDatabase::setPreviewType(Adesk::Int16 val)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setPreviewType(val));
#endif
}

void PyDbDatabase::setProjectName(const std::string& val)
{
    return PyThrowBadEs(impObj()->setProjectName(utf8_to_wstr(val).c_str()));
}

void PyDbDatabase::setPsltscale(bool scale)
{
    return PyThrowBadEs(impObj()->setPsltscale(scale));
}

void PyDbDatabase::setPsolHeight(double height)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setPsolHeight(height));
#endif
}

void PyDbDatabase::setPsolWidth(double width)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setPsolWidth(width));
#endif
}

void PyDbDatabase::setPucs(const AcGePoint3d& ucsOrigin, const AcGeVector3d& ucsXDir, const AcGeVector3d& ucsYDir)
{
    return PyThrowBadEs(impObj()->setPucs(ucsOrigin, ucsXDir, ucsYDir));
}

void PyDbDatabase::setPucsBase(const PyDbObjectId& ucsid)
{
    return PyThrowBadEs(impObj()->setPucsBase(ucsid.m_id));
}

void PyDbDatabase::setPucsname(const PyDbObjectId& ucsRecId)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setPucsname(ucsRecId.m_id));
#endif
}

void PyDbDatabase::setQtextmode(bool mode)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setQtextmode(mode));
#endif
}

void PyDbDatabase::setRealWorldScale(const bool realWorldScale)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setRealWorldScale(realWorldScale));
#endif
}

void PyDbDatabase::setRegenmode(bool mode)
{
    return PyThrowBadEs(impObj()->setRegenmode(mode));
}

void PyDbDatabase::setRetainOriginalThumbnailBitmap(bool retain)
{
    return impObj()->setRetainOriginalThumbnailBitmap(retain);
}

void PyDbDatabase::setSaveproxygraphics(Adesk::Int16 saveimg)
{
    return PyThrowBadEs(impObj()->setSaveproxygraphics(saveimg));
}

void PyDbDatabase::setSectionViewStyle(const PyDbObjectId& objId)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setSectionViewStyle(objId.m_id));
#endif
}

void PyDbDatabase::setShadedge(Adesk::Int16 mode)
{
    return PyThrowBadEs(impObj()->setShadedge(mode));
}

void PyDbDatabase::setShadedif(Adesk::Int16 dif)
{
    return PyThrowBadEs(impObj()->setShadedif(dif));
}

void PyDbDatabase::setShadowPlaneLocation(double val)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setShadowPlaneLocation(val));
#endif
}

void PyDbDatabase::setShowHist(Adesk::UInt8 val)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setShowHist(val));
#endif
}

void PyDbDatabase::setSketchinc(double inc)
{
    return PyThrowBadEs(impObj()->setSketchinc(inc));
}

void PyDbDatabase::setSkpoly(bool asPoly)
{
    return PyThrowBadEs(impObj()->setSkpoly(asPoly));
}

void PyDbDatabase::setSolidHist(Adesk::UInt8 val)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setSolidHist(val));
#endif
}

void PyDbDatabase::setSortEnts(Adesk::UInt8 sortEnts)
{
    return PyThrowBadEs(impObj()->setSortEnts(sortEnts));
}

void PyDbDatabase::setSplframe(bool disp)
{
    return PyThrowBadEs(impObj()->setSplframe(disp));
}

void PyDbDatabase::setSplinesegs(Adesk::Int16 segs)
{
    return PyThrowBadEs(impObj()->setSplinesegs(segs));
}

void PyDbDatabase::setSplinetype(Adesk::Int16 type)
{
    return PyThrowBadEs(impObj()->setSplinetype(type));
}

void PyDbDatabase::setStepSize(double stepSize)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setStepSize(stepSize));
#endif
}

void PyDbDatabase::setStepsPerSec(double stepsPerSec)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setStepsPerSec(stepsPerSec));
#endif
}

void PyDbDatabase::setStyleSheet(const std::string& val)
{
    return PyThrowBadEs(impObj()->setStyleSheet(utf8_to_wstr(val).c_str()));
}

void PyDbDatabase::setSurftab1(Adesk::Int16 tab1)
{
    return PyThrowBadEs(impObj()->setSurftab1(tab1));
}

void PyDbDatabase::setSurftab2(Adesk::Int16 tab2)
{
    return PyThrowBadEs(impObj()->setSurftab2(tab2));
}

void PyDbDatabase::setSurftype(Adesk::Int16 type)
{
    return PyThrowBadEs(impObj()->setSurftype(type));
}

void PyDbDatabase::setSurfu(Adesk::Int16 v)
{
    return PyThrowBadEs(impObj()->setSurfu(v));
}

void PyDbDatabase::setSurfv(Adesk::Int16 v)
{
    return PyThrowBadEs(impObj()->setSurfv(v));
}

void PyDbDatabase::setTablestyle(const PyDbObjectId& objId)
{
    return PyThrowBadEs(impObj()->setTablestyle(objId.m_id));
}

void PyDbDatabase::setTextsize(double size)
{
    return PyThrowBadEs(impObj()->setTextsize(size));
}

void PyDbDatabase::setTextstyle(const PyDbObjectId& objId)
{
    return PyThrowBadEs(impObj()->setTextstyle(objId.m_id));
}

void PyDbDatabase::setThickness(double thickness)
{
    return PyThrowBadEs(impObj()->setThickness(thickness));
}

void PyDbDatabase::setTilemode(bool mode)
{
    return PyThrowBadEs(impObj()->setTilemode(mode));
}

void PyDbDatabase::setTimeZone(AcDb::TimeZone tz)
{
    return PyThrowBadEs(impObj()->setTimeZone(tz));
}

void PyDbDatabase::setTimeZoneAsUtcOffset(double offset)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setTimeZoneAsUtcOffset(offset));
#endif
}

void PyDbDatabase::setTracewid(double width)
{
    return PyThrowBadEs(impObj()->setTracewid(width));
}

void PyDbDatabase::setTreedepth(Adesk::Int16 depth)
{
    return PyThrowBadEs(impObj()->setTreedepth(depth));
}

void PyDbDatabase::setTStackAlign(int val)
{
    return PyThrowBadEs(impObj()->setTStackAlign(val));
}

void PyDbDatabase::setTStackSize(int val)
{
    return PyThrowBadEs(impObj()->setTStackSize(val));
}

void PyDbDatabase::setUcs(const AcGePoint3d& ucsOrigin, const AcGeVector3d& ucsXDir, const AcGeVector3d& ucsYDir)
{
    return PyThrowBadEs(impObj()->setUcs(ucsOrigin, ucsXDir, ucsYDir));
}

void PyDbDatabase::setUcsBase(const PyDbObjectId& ucsid)
{
    return PyThrowBadEs(impObj()->setUcsBase(ucsid.m_id));
}

void PyDbDatabase::setUcsname(const PyDbObjectId& ucsRecId)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setUcsname(ucsRecId.m_id));
#endif
}

void PyDbDatabase::setUnitmode(Adesk::Int16 mode)
{
    return PyThrowBadEs(impObj()->setUnitmode(mode));
}

void PyDbDatabase::setUpdateThumbnail(Adesk::UInt8 val)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setUpdateThumbnail(val));
#endif
}

void PyDbDatabase::setUseri1(Adesk::Int16 val)
{
    return PyThrowBadEs(impObj()->setUseri1(val));
}

void PyDbDatabase::setUseri2(Adesk::Int16 val)
{
    return PyThrowBadEs(impObj()->setUseri2(val));
}

void PyDbDatabase::setUseri3(Adesk::Int16 val)
{
    return PyThrowBadEs(impObj()->setUseri3(val));
}

void PyDbDatabase::setUseri4(Adesk::Int16 val)
{
    return PyThrowBadEs(impObj()->setUseri4(val));
}

void PyDbDatabase::setUseri5(Adesk::Int16 val)
{
    return PyThrowBadEs(impObj()->setUseri5(val));
}

void PyDbDatabase::setUserr1(double val)
{
    return PyThrowBadEs(impObj()->setUserr1(val));
}

void PyDbDatabase::setUserr2(double val)
{
    return PyThrowBadEs(impObj()->setUserr2(val));
}

void PyDbDatabase::setUserr3(double val)
{
    return PyThrowBadEs(impObj()->setUserr3(val));
}

void PyDbDatabase::setUserr4(double val)
{
    return PyThrowBadEs(impObj()->setUserr4(val));
}

void PyDbDatabase::setUserr5(double val)
{
    return PyThrowBadEs(impObj()->setUserr5(val));
}

void PyDbDatabase::setUsrtimer(bool timer)
{
    return PyThrowBadEs(impObj()->setUsrtimer(timer));
}

void PyDbDatabase::setVersionGuid(const std::string& pNewGuid)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setVersionGuid(utf8_to_wstr(pNewGuid).c_str()));
#endif
}

void PyDbDatabase::setViewportScaleDefault(double newDefaultVPScale)
{
    return PyThrowBadEs(impObj()->setVisretain(newDefaultVPScale));
}

void PyDbDatabase::setVisretain(bool retain)
{
    return PyThrowBadEs(impObj()->setVisretain(retain));
}

void PyDbDatabase::setWorldPucsBaseOrigin(const AcGePoint3d& origin, AcDb::OrthographicView orthoView)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setWorldPucsBaseOrigin(origin, orthoView));
#endif
}

void PyDbDatabase::setWorldUcsBaseOrigin(const AcGePoint3d& origin, AcDb::OrthographicView orthoView)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setWorldUcsBaseOrigin(origin, orthoView));
#endif
}

void PyDbDatabase::setWorldview(bool view)
{
    return PyThrowBadEs(impObj()->setWorldview(view));
}

void PyDbDatabase::setXclipFrame(Adesk::UInt8 disp)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setXclipFrame(disp));
#endif
}

void PyDbDatabase::setXrefEditEnabled(bool enable)
{
    return PyThrowBadEs(impObj()->setXrefEditEnabled(enable));
}

Adesk::Int16 PyDbDatabase::shadedge() const
{
    return impObj()->shadedge();
}

Adesk::Int16 PyDbDatabase::shadedif() const
{
    return impObj()->shadedif();
}

double PyDbDatabase::shadowPlaneLocation() const
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return impObj()->shadowPlaneLocation();
#endif
}

Adesk::UInt8 PyDbDatabase::showHist() const
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return impObj()->showHist();
#endif
}

double PyDbDatabase::sketchinc() const
{
    return impObj()->sketchinc();
}

bool PyDbDatabase::skpoly() const
{
    return impObj()->skpoly();
}

Adesk::UInt8 PyDbDatabase::solidHist() const
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return impObj()->solidHist();
#endif
}

Adesk::UInt8 PyDbDatabase::sortEnts() const
{
    return impObj()->splframe();
}

bool PyDbDatabase::splframe() const
{
    return impObj()->splframe();
}

Adesk::Int16 PyDbDatabase::splinesegs() const
{
    return impObj()->splinesegs();
}

Adesk::Int16 PyDbDatabase::splinetype() const
{
    return impObj()->splinetype();
}

double PyDbDatabase::stepSize() const
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return impObj()->stepSize();
#endif
}

double PyDbDatabase::stepsPerSec() const
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return impObj()->stepsPerSec();
#endif
}

Adesk::Int16 PyDbDatabase::surftab1() const
{
    return impObj()->surftab1();
}

Adesk::Int16 PyDbDatabase::surftab2() const
{
    return impObj()->surftab2();
}

Adesk::Int16 PyDbDatabase::surftype() const
{
    return impObj()->surftype();
}

Adesk::Int16 PyDbDatabase::surfu() const
{
    return impObj()->surfu();
}

Adesk::Int16 PyDbDatabase::surfv() const
{
    return impObj()->surfv();
}

PyDbObjectId PyDbDatabase::tablestyle() const
{
    return PyDbObjectId(impObj()->tablestyle());
}

PyDbObjectId PyDbDatabase::tableStyleDictionaryId() const
{
    return PyDbObjectId(impObj()->tableStyleDictionaryId());
}

double PyDbDatabase::textsize() const
{
    return impObj()->textsize();
}

PyDbObjectId PyDbDatabase::textstyle() const
{
    return PyDbObjectId(impObj()->textstyle());
}

PyDbObjectId PyDbDatabase::textStyleTableId() const
{
    return PyDbObjectId(impObj()->textStyleTableId());
}

double PyDbDatabase::thickness() const
{
    return impObj()->thickness();
}

bool PyDbDatabase::tilemode() const
{
    return impObj()->tilemode();
}

Adesk::UInt8 PyDbDatabase::tileModeLightSynch() const
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return impObj()->tileModeLightSynch();
#endif
}

AcDb::TimeZone PyDbDatabase::timeZone() const
{
    return impObj()->timeZone();
}

double PyDbDatabase::tracewid() const
{
    return impObj()->tracewid();
}

PyDbTransactionManager PyDbDatabase::transactionManager() const
{
    return PyDbTransactionManager(impObj()->transactionManager());
}

Adesk::Int16 PyDbDatabase::treedepth() const
{
    return impObj()->treedepth();
}

int PyDbDatabase::tstackalign() const
{
    return impObj()->tstackalign();
}

int PyDbDatabase::tstacksize() const
{
    return impObj()->tstacksize();
}

PyDbObjectId PyDbDatabase::ucsBase() const
{
    return PyDbObjectId(impObj()->ucsBase());
}

PyDbObjectId PyDbDatabase::ucsname() const
{
    return PyDbObjectId(impObj()->ucsname());
}

AcGePoint3d PyDbDatabase::ucsorg() const
{
    return impObj()->ucsorg();
}

PyDbObjectId PyDbDatabase::UCSTableId() const
{
    return PyDbObjectId(impObj()->UCSTableId());
}

AcGeVector3d PyDbDatabase::ucsxdir() const
{
    return impObj()->ucsxdir();
}

AcGeVector3d PyDbDatabase::ucsydir() const
{
    return impObj()->ucsydir();
}

bool PyDbDatabase::undoRecording() const
{
    return impObj()->undoRecording();
}

Adesk::Int16 PyDbDatabase::unitmode() const
{
    return impObj()->unitmode();
}

void PyDbDatabase::updateDataLink(AcDb::UpdateDirection nDir, AcDb::UpdateOption nOption)
{
    return PyThrowBadEs(impObj()->updateDataLink(nDir, nOption));
}

void PyDbDatabase::updateExt(bool doBestFit)
{
    return PyThrowBadEs(impObj()->updateExt(doBestFit));
}

Adesk::UInt8 PyDbDatabase::updateThumbnail() const
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return impObj()->updateThumbnail();
#endif
}

Adesk::Int16 PyDbDatabase::useri1() const
{
    return impObj()->useri1();
}

Adesk::Int16 PyDbDatabase::useri2() const
{
    return impObj()->useri2();
}

Adesk::Int16 PyDbDatabase::useri3() const
{
    return impObj()->useri3();
}

Adesk::Int16 PyDbDatabase::useri4() const
{
    return impObj()->userr4();
}

Adesk::Int16 PyDbDatabase::useri5() const
{
    return impObj()->userr5();
}

double PyDbDatabase::userr1() const
{
    return impObj()->userr1();
}

double PyDbDatabase::userr2() const
{
    return impObj()->userr2();
}

double PyDbDatabase::userr3() const
{
    return impObj()->userr3();
}

double PyDbDatabase::userr4() const
{
    return impObj()->userr4();
}

double PyDbDatabase::userr5() const
{
    return impObj()->userr5();
}

bool PyDbDatabase::usrtimer() const
{
    return impObj()->usrtimer();
}

double PyDbDatabase::viewportScaleDefault() const
{
    return impObj()->viewportScaleDefault();
}

PyDbObjectId PyDbDatabase::viewportTableId() const
{
    return PyDbObjectId(impObj()->viewportTableId());
}

PyDbObjectId PyDbDatabase::viewTableId() const
{
    return PyDbObjectId(impObj()->viewTableId());
}

bool PyDbDatabase::visretain() const
{
    return impObj()->visretain();
}

PyDbObjectId PyDbDatabase::visualStyleDictionaryId() const
{
    return PyDbObjectId(impObj()->visualStyleDictionaryId());
}

void PyDbDatabase::wblock4(PyDbDatabase& pOutputDb)
{
    AcDbDatabase* _pOutputDb = nullptr;
    PyThrowBadEs(impObj()->wblock(_pOutputDb));
    pOutputDb = PyDbDatabase(_pOutputDb, true);
}

void PyDbDatabase::wblock3(PyDbDatabase& pOutputDb, const PyDbObjectId& blockId)
{
    AcDbDatabase* _pOutputDb = nullptr;
    PyThrowBadEs(impObj()->wblock(_pOutputDb, blockId.m_id));
    pOutputDb = PyDbDatabase(_pOutputDb, true);
}

void PyDbDatabase::wblock2(PyDbDatabase& pOutputDb, const boost::python::list& outObjIds, const AcGePoint3d& basePoint)
{
    AcDbObjectIdArray ids = PyListToObjectIdArray(outObjIds);
    AcDbDatabase* _pOutputDb = nullptr;
    PyThrowBadEs(impObj()->wblock(_pOutputDb, ids, basePoint));
    pOutputDb = PyDbDatabase(_pOutputDb, true);
}

void PyDbDatabase::wblock1(PyDbDatabase& pOutputDb, const boost::python::list& outObjIds, const AcGePoint3d& basePoint, AcDb::DuplicateRecordCloning drc)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    AcDbObjectIdArray ids = PyListToObjectIdArray(outObjIds);
    PyThrowBadEs(impObj()->wblock(pOutputDb.impObj(), ids, basePoint, drc));
#endif
}

AcGePoint3d PyDbDatabase::worldPucsBaseOrigin(AcDb::OrthographicView orthoView) const
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return impObj()->worldPucsBaseOrigin(orthoView);
#endif
}

AcGePoint3d PyDbDatabase::worldUcsBaseOrigin(AcDb::OrthographicView orthoView) const
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return impObj()->worldUcsBaseOrigin(orthoView);
#endif
}

bool PyDbDatabase::worldview() const
{
    return impObj()->worldview();
}

Adesk::UInt8 PyDbDatabase::xclipFrame() const
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return impObj()->xclipFrame();
#endif
}

PyDbObjectId PyDbDatabase::xrefBlockId() const
{
    return PyDbObjectId(impObj()->xrefBlockId());
}

bool PyDbDatabase::xrefEditEnabled() const
{
    return impObj()->xrefEditEnabled();
}

std::string PyDbDatabase::className()
{
    return "AcDbDatabase";
}

AcDbDatabase* PyDbDatabase::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcDbDatabase*>(m_pyImp.get());
}

