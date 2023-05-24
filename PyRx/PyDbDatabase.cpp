#include "stdafx.h"
#include "PyDbDatabase.h"
#include "PyDbObjectId.h"
using namespace boost::python;
//---------------------------------------------------------------------------------------------------
// makeAcDbDatabaseWrapper
void makeAcDbDatabaseWrapper()
{
    class_<PyDbDatabase, bases<PyRxObject>>("Database")
        .def(init<>())
        .def(init<bool, bool>())
        .def("angbase", &PyDbDatabase::angbase)
        .def("angdir", &PyDbDatabase::angdir)
        .def("annoAllVisible", &PyDbDatabase::annoAllVisible)
        .def("annotativeDwg", &PyDbDatabase::annotativeDwg)
        .def("approxNumObjects", &PyDbDatabase::approxNumObjects)
        .def("attmode", &PyDbDatabase::attmode)
        .def("aunits", &PyDbDatabase::aunits)
        .def("auprec", &PyDbDatabase::auprec)
        .def("blipmode", &PyDbDatabase::blipmode)
        .def("byBlockLinetype", &PyDbDatabase::byBlockLinetype)
        .def("byBlockMaterial", &PyDbDatabase::byBlockMaterial)
        .def("byLayerLinetype", &PyDbDatabase::byLayerLinetype)
        .def("byLayerMaterial", &PyDbDatabase::byLayerMaterial)
        .def("cameraDisplay", &PyDbDatabase::cameraDisplay)
        .def("cameraHeight", &PyDbDatabase::cameraHeight)
        .def("cDynDisplayMode", &PyDbDatabase::cDynDisplayMode)
        .def("celtscale", &PyDbDatabase::celtscale)
        .def("celtype", &PyDbDatabase::celtype)
        .def("celweight", &PyDbDatabase::celweight)
        .def("chamfera", &PyDbDatabase::chamfera)
        .def("chamferb", &PyDbDatabase::chamferb)
        .def("chamferc", &PyDbDatabase::chamferc)
        .def("chamferd", &PyDbDatabase::chamferd)
        .def("classDxfName", &PyDbDatabase::classDxfName)//TODO: add test
        .def("clayer", &PyDbDatabase::clayer)
        .def("closeInput", &PyDbDatabase::closeInput)//TODO: add test
        .def("cmaterial", &PyDbDatabase::cmaterial)
        .def("cmljust", &PyDbDatabase::cmljust)
        .def("cmlscale", &PyDbDatabase::cmlscale)
        .def("cmlstyleID", &PyDbDatabase::cmlstyleID)
        .def("colorDictionaryId", &PyDbDatabase::colorDictionaryId)
        .def("continuousLinetype", &PyDbDatabase::continuousLinetype)
        .def("coords", &PyDbDatabase::coords)
        .def("countEmptyObjects", &PyDbDatabase::countEmptyObjects)
        .def("detailViewStyle", &PyDbDatabase::detailViewStyle)
        .def("detailViewStyleDictionaryId", &PyDbDatabase::detailViewStyleDictionaryId)
        .def("dimaso", &PyDbDatabase::dimaso)
        .def("dimAssoc", &PyDbDatabase::dimAssoc)
        .def("dimfit", &PyDbDatabase::dimfit)
        .def("dimsho", &PyDbDatabase::dimsho)
        .def("dimstyle", &PyDbDatabase::dimstyle)
        .def("dimStyleTableId", &PyDbDatabase::dimStyleTableId)
        .def("dimunit", &PyDbDatabase::dimunit)
        .def("dimapost", &PyDbDatabase::dimapost)
        .def("dimblk", &PyDbDatabase::dimblk)
        .def("dimblk1", &PyDbDatabase::dimblk1)
        .def("dimblk2", &PyDbDatabase::dimblk2)
        .def("dimpost", &PyDbDatabase::dimblk2)
        .def("disablePartialOpen", &PyDbDatabase::disablePartialOpen)
        .def("disableUndoRecording", &PyDbDatabase::disableUndoRecording)
        .def("dispSilh", &PyDbDatabase::dispSilh)
        .def("dragmode", &PyDbDatabase::dragmode)
        .def("dragVisStyle", &PyDbDatabase::dragVisStyle)
        .def("drawOrderCtl", &PyDbDatabase::drawOrderCtl)
        .def("dwfframe", &PyDbDatabase::dwfframe)
        .def("dwgFileWasSavedByAutodeskSoftware", &PyDbDatabase::dwgFileWasSavedByAutodeskSoftware)
        .def("dxfIn", &PyDbDatabase::dxfIn)
        .def("dxfOut", &PyDbDatabase::dxfOut)
        .def("elevation", &PyDbDatabase::elevation)
        .def("eraseEmptyObjects", &PyDbDatabase::eraseEmptyObjects)
        .def("extmax", &PyDbDatabase::extmax)
        .def("extmin", &PyDbDatabase::extmin)
        .def("facetres", &PyDbDatabase::facetres)
        .def("filletrad", &PyDbDatabase::filletrad)
        .def("fillmode", &PyDbDatabase::fillmode)
        .def("forceWblockDatabaseCopy", &PyDbDatabase::forceWblockDatabaseCopy)
        .def("geoCoordinateSystemId", &PyDbDatabase::geoCoordinateSystemId)
        .def("geoMarkerVisibility", &PyDbDatabase::geoMarkerVisibility)
        .def("get3dDwfPrec", &PyDbDatabase::get3dDwfPrec)
        .def("getCePlotStyleNameId", &PyDbDatabase::getCePlotStyleNameId)
        .def("getDimstyleParentId", &PyDbDatabase::getDimstyleParentId)
        .def("getNearestLineWeight", &PyDbDatabase::getNearestLineWeight).staticmethod("getNearestLineWeight")//static
        .def("getViewportArray", &PyDbDatabase::getViewportArray)//TODO: TEST
        .def("getVisualStyleList", &PyDbDatabase::getVisualStyleList)
        .def("globalMaterial", &PyDbDatabase::globalMaterial)
        .def("groupDictionaryId", &PyDbDatabase::groupDictionaryId)
        .def("haloGap", &PyDbDatabase::haloGap)
        .def("hasClass", &PyDbDatabase::hasClass)
        .def("hideText", &PyDbDatabase::hideText)
        .def("hpInherit", &PyDbDatabase::hpInherit)
        .def("hpOrigin", &PyDbDatabase::hpOrigin)
        .def("hpOrigin", &PyDbDatabase::hpOrigin)
        //TODO: TEST
        .def<Acad::ErrorStatus(PyDbDatabase::*)(PyDbObjectId&, const std::string&, PyDbDatabase&, bool)>("insert", &PyDbDatabase::insert)
        .def<Acad::ErrorStatus(PyDbDatabase::*)(PyDbObjectId&, const std::string&, const std::string&, PyDbDatabase&, bool)>("insert", &PyDbDatabase::insert)
        .def<Acad::ErrorStatus(PyDbDatabase::*)(const AcGeMatrix3d&, PyDbDatabase&, bool)>("insert", &PyDbDatabase::insert)
        .def("hpOrigin", &PyDbDatabase::indexctl)
        .def("isAppRegistered", &PyDbDatabase::isAppRegistered)
        .def("insunits", &PyDbDatabase::insunits)
        .def("interfereVpVisStyle", &PyDbDatabase::interfereVpVisStyle)
        .def("intersectColor", &PyDbDatabase::intersectColor)
        .def("intersectDisplay", &PyDbDatabase::intersectDisplay)
        .def("isBeingDestroyed", &PyDbDatabase::isBeingDestroyed)
        .def("isEMR", &PyDbDatabase::isEMR)
        .def("isObjectNonPersistent", &PyDbDatabase::isObjectNonPersistent)
        .def("isolines", &PyDbDatabase::isolines)
        .def("isPartiallyOpened", &PyDbDatabase::isPartiallyOpened)
        .def("isPucsOrthographic", &PyDbDatabase::isPucsOrthographic)
        .def("isUcsOrthographic", &PyDbDatabase::isUcsOrthographic)
        .def("isValidLineWeight", &PyDbDatabase::isValidLineWeight).staticmethod("isValidLineWeight")//static
        .def("joinStyle", &PyDbDatabase::joinStyle)
        .def("lastSavedAsMaintenanceVersion", &PyDbDatabase::lastSavedAsMaintenanceVersion)
        .def("lastSavedAsVersion", &PyDbDatabase::lastSavedAsVersion)
        .def("latitude", &PyDbDatabase::latitude)
        .def("layerEval", &PyDbDatabase::layerEval)
        .def("layerNotify", &PyDbDatabase::layerNotify)
        .def("layerTableId", &PyDbDatabase::layerTableId)
        .def("layerZero", &PyDbDatabase::layerZero)
        .def("layoutDictionaryId", &PyDbDatabase::layoutDictionaryId)
        .def("lensLength", &PyDbDatabase::lensLength)
        .def("lightGlyphDisplay", &PyDbDatabase::lightGlyphDisplay)
        .def("lightingUnits", &PyDbDatabase::lightingUnits)
        .def("lightsInBlocks", &PyDbDatabase::lightsInBlocks)
        .def("limcheck", &PyDbDatabase::limcheck)
        .def("limmax", &PyDbDatabase::limmax)
        .def("limmin", &PyDbDatabase::limmin)
        .def("linetypeTableId", &PyDbDatabase::linetypeTableId)
        .def("lineWeightDisplay", &PyDbDatabase::lineWeightDisplay)
        .def("loadLineTypeFile", &PyDbDatabase::loadLineTypeFile)
        .def("loftAng1", &PyDbDatabase::loftAng1)
        .def("loftAng2", &PyDbDatabase::loftAng2)
        .def("loftMag1", &PyDbDatabase::loftMag1)
        .def("loftMag2", &PyDbDatabase::loftMag2)
        .def("loftNormals", &PyDbDatabase::loftNormals)
        .def("loftParam", &PyDbDatabase::loftParam)
        .def("longitude", &PyDbDatabase::longitude)
        .def("ltscale", &PyDbDatabase::ltscale)
        .def("lunits", &PyDbDatabase::lunits)
        .def("luprec", &PyDbDatabase::luprec)
        .def("maintenanceReleaseVersion", &PyDbDatabase::maintenanceReleaseVersion)
        .def("markObjectNonPersistent", &PyDbDatabase::markObjectNonPersistent).staticmethod("markObjectNonPersistent")//static
        .def("materialDictionaryId", &PyDbDatabase::materialDictionaryId)
        .def("maxactvp", &PyDbDatabase::maxactvp)
        .def("measurement", &PyDbDatabase::measurement)
        .def("mirrtext", &PyDbDatabase::mirrtext)
        .def("mleaderscale", &PyDbDatabase::mleaderscale)
        .def("mleaderstyle", &PyDbDatabase::mleaderstyle)
        .def("mleaderStyleDictionaryId", &PyDbDatabase::mleaderStyleDictionaryId)
        .def("mLStyleDictionaryId", &PyDbDatabase::mLStyleDictionaryId)
        .def("msltscale", &PyDbDatabase::msltscale)
        .def("msOleScale", &PyDbDatabase::msOleScale)
        .def("namedObjectsDictionaryId", &PyDbDatabase::namedObjectsDictionaryId)
        .def("needsRecovery", &PyDbDatabase::needsRecovery)
        .def("northDirection", &PyDbDatabase::northDirection)
        .def("numberOfSaves", &PyDbDatabase::numberOfSaves)
        .def("obscuredColor", &PyDbDatabase::obscuredColor)
        .def("obscuredLineType", &PyDbDatabase::obscuredLineType)
        .def("oleStartUp", &PyDbDatabase::oleStartUp)
        .def("originalFileMaintenanceVersion", &PyDbDatabase::originalFileMaintenanceVersion)
        .def("originalFileName", &PyDbDatabase::originalFileName)
        .def("originalFileSavedByMaintenanceVersion", &PyDbDatabase::originalFileSavedByMaintenanceVersion)
        .def("originalFileSavedByVersion", &PyDbDatabase::originalFileSavedByVersion)
        .def("originalFileVersion", &PyDbDatabase::originalFileVersion)
        .def("orthomode", &PyDbDatabase::orthomode)
        .def("paperSpaceVportId", &PyDbDatabase::paperSpaceVportId)
        .def("pdfframe", &PyDbDatabase::pdfframe)
        .def("pdmode", &PyDbDatabase::pdmode)
        .def("pdsize", &PyDbDatabase::pdsize)
        .def("pextmax", &PyDbDatabase::pextmax)
        .def("pextmin", &PyDbDatabase::pextmin)
        .def("pickstyle", &PyDbDatabase::pickstyle)
        .def("pinsbase", &PyDbDatabase::pinsbase)
        .def("plimcheck", &PyDbDatabase::plimcheck)
        .def("plimmax", &PyDbDatabase::plimmax)
        .def("plimmin", &PyDbDatabase::plimmin)
        .def("plineEllipse", &PyDbDatabase::plineEllipse)
        .def("plinegen", &PyDbDatabase::plinegen)
        .def("plinewid", &PyDbDatabase::plinewid)
        .def("plotSettingsDictionaryId", &PyDbDatabase::plotSettingsDictionaryId)
        .def("plotStyleMode", &PyDbDatabase::plotStyleMode)
        .def("plotStyleNameDictionaryId", &PyDbDatabase::plotStyleNameDictionaryId)
        .def("previewType", &PyDbDatabase::previewType)
        .def("psltscale", &PyDbDatabase::psltscale)
        .def("psolHeight", &PyDbDatabase::psolHeight)
        .def("psolWidth", &PyDbDatabase::psolWidth)
        .def("pucsBase", &PyDbDatabase::pucsBase)
        .def("pucsname", &PyDbDatabase::pucsname)
        .def("pucsorg", &PyDbDatabase::pucsorg)
        .def("pucsxdir", &PyDbDatabase::pucsxdir)
        .def("pucsydir", &PyDbDatabase::pucsydir)
        .def("qtextmode", &PyDbDatabase::qtextmode)
        .def("reclaimMemoryFromErasedObjects", &PyDbDatabase::reclaimMemoryFromErasedObjects)
        .def("regAppTableId", &PyDbDatabase::regAppTableId)
        .def("regenmode", &PyDbDatabase::regenmode)
        .def("registerApp", &PyDbDatabase::registerApp)
        .def("resetTimes", &PyDbDatabase::resetTimes)
        .def("restoreForwardingXrefSymbols", &PyDbDatabase::restoreForwardingXrefSymbols)
        .def("restoreOriginalXrefSymbols", &PyDbDatabase::restoreOriginalXrefSymbols)
        .def("retainOriginalThumbnailBitmap", &PyDbDatabase::retainOriginalThumbnailBitmap)
        .def("saveproxygraphics", &PyDbDatabase::saveproxygraphics)
        .def("scaleListDictionaryId", &PyDbDatabase::scaleListDictionaryId)
        .def("sectionViewStyle", &PyDbDatabase::sectionViewStyle)
        .def("sectionViewStyleDictionaryId", &PyDbDatabase::sectionViewStyleDictionaryId)
        .def("set3dDwfPrec", &PyDbDatabase::set3dDwfPrec)
        .def("setAngbase", &PyDbDatabase::setAngbase)
        .def("setAngdir", &PyDbDatabase::setAngdir)
        .def("setAnnoAllVisible", &PyDbDatabase::setAnnoAllVisible)
        .def("setAttdia", &PyDbDatabase::setAttdia)
        .def("setAttmode", &PyDbDatabase::setAttmode)
        .def("setAttreq", &PyDbDatabase::setAttreq)
        .def("setAunits", &PyDbDatabase::setAunits)
        .def("setAuprec", &PyDbDatabase::setAuprec)
        .def("setBlipmode", &PyDbDatabase::setBlipmode)
        .def("setCameraDisplay", &PyDbDatabase::setCameraDisplay)
        .def("setCameraHeight", &PyDbDatabase::setCameraHeight)
        .def("setCDynDisplayMode", &PyDbDatabase::setCDynDisplayMode)
        .def("setCeltscale", &PyDbDatabase::setCeltscale)
        .def("setCeltype", &PyDbDatabase::setCeltype)
        .def("setCelweight", &PyDbDatabase::setCelweight)
        .def("setCePlotStyleName", &PyDbDatabase::setCePlotStyleName)
        .def("setChamfera", &PyDbDatabase::setChamfera)
        .def("setChamferb", &PyDbDatabase::setChamferb)
        .def("setChamferc", &PyDbDatabase::setChamferc)
        .def("setChamferd", &PyDbDatabase::setChamferd)
        .def("setClayer", &PyDbDatabase::setClayer)
        .def("setCmaterial", &PyDbDatabase::setCmaterial)
        .def("setCmljust", &PyDbDatabase::setCmljust)
        .def("setCmlscale", &PyDbDatabase::setCmlscale)
        .def("setCmlstyleID", &PyDbDatabase::setCmlstyleID)
        .def("setCoords", &PyDbDatabase::setCoords)
        .def("setCshadow", &PyDbDatabase::setCshadow)
        .def("setDelUsedObj", &PyDbDatabase::setDelUsedObj)
        .def("setDgnframe", &PyDbDatabase::setDgnframe)
        .def("setDimaso", &PyDbDatabase::setDimaso)
        .def("setDimAssoc", &PyDbDatabase::setDimAssoc)
        .def("setDimfit", &PyDbDatabase::setDimfit)
        .def("setDimsho", &PyDbDatabase::setDimsho)
        .def("setDimstyle", &PyDbDatabase::setDimstyle)
        .def("setDimstyleData", &PyDbDatabase::setDimstyleData)
        .def("setDimunit", &PyDbDatabase::setDimunit)
        .def("setDispSilh", &PyDbDatabase::setDispSilh)
        .def("setDragmode", &PyDbDatabase::setDragmode)
        .def("setDragVisStyle", &PyDbDatabase::setDragVisStyle)
        .def("setDrawOrderCtl", &PyDbDatabase::setDrawOrderCtl)
        .def("setDwfframe", &PyDbDatabase::setDwfframe)
        .def("setElevation", &PyDbDatabase::setElevation)
        .def("setEndCaps", &PyDbDatabase::setEndCaps)
        .def("setExtmax", &PyDbDatabase::setExtmax)
        .def("setExtmin", &PyDbDatabase::setExtmin)
        .def("setFacetres", &PyDbDatabase::setFacetres)
        .def("setFilletrad", &PyDbDatabase::setFilletrad)
        .def("setFillmode", &PyDbDatabase::setFillmode)
        .def("saveAs", &PyDbDatabase::saveAs)
        .def("setFingerprintGuid", &PyDbDatabase::setFingerprintGuid)
        .def("setFullSaveRequired", &PyDbDatabase::setFullSaveRequired)
        .def("setGeoMarkerVisibility", &PyDbDatabase::setGeoMarkerVisibility)
        .def("setHaloGap", &PyDbDatabase::setHaloGap)
        .def("setHideText", &PyDbDatabase::setHideText)
        .def("setHpInherit", &PyDbDatabase::setHpInherit)
        .def("setHpOrigin", &PyDbDatabase::setHpOrigin)
        .def("setHyperlinkBase", &PyDbDatabase::setHyperlinkBase)
        .def("setIndexctl", &PyDbDatabase::setIndexctl)
        .def("setInsbase", &PyDbDatabase::setInsbase)
        .def("setInsunits", &PyDbDatabase::setInsunits)
        .def("setInterfereObjVisStyle", &PyDbDatabase::setInterfereObjVisStyle)
        .def("setInterfereVpVisStyle", &PyDbDatabase::setInterfereVpVisStyle)
        .def("setIntersectColor", &PyDbDatabase::setIntersectColor)
        .def("setIntersectDisplay", &PyDbDatabase::setIntersectDisplay)
        .def("setIsolines", &PyDbDatabase::setIsolines)
        .def("setJoinStyle", &PyDbDatabase::setJoinStyle)
        .def("setLatitude", &PyDbDatabase::setLatitude)
        .def("setLayerEval", &PyDbDatabase::setLayerEval)
        .def("setLayerNotify", &PyDbDatabase::setLayerNotify)
        .def("setLensLength", &PyDbDatabase::setLensLength)
        .def("setLightGlyphDisplay", &PyDbDatabase::setLightGlyphDisplay)
        .def("setLightingUnits", &PyDbDatabase::setLightingUnits)
        .def("setLightsInBlocks", &PyDbDatabase::setLightsInBlocks)
        .def("setLimcheck", &PyDbDatabase::setLimcheck)
        .def("setLimmax", &PyDbDatabase::setLimmax)
        .def(" setLimmin", &PyDbDatabase::setLimmin)
        .def("setLineWeightDisplay", &PyDbDatabase::setLineWeightDisplay)
        .def("setLoftAng1", &PyDbDatabase::setLoftAng1)
        .def("setLoftAng2", &PyDbDatabase::setLoftAng2)
        .def("setLoftMag1", &PyDbDatabase::setLoftMag1)
        .def("setLoftMag2", &PyDbDatabase::setLoftMag2)
        .def("setLoftNormals", &PyDbDatabase::setLoftNormals)
        .def("setLoftParam", &PyDbDatabase::setLoftParam)
        .def("setLongitude", &PyDbDatabase::setLongitude)
        .def("setLtscale", &PyDbDatabase::setLtscale)
        .def("setLunits", &PyDbDatabase::setLunits)
        .def("setLuprec", &PyDbDatabase::setLuprec)
        .def("setMaxactvp", &PyDbDatabase::setMaxactvp)
        .def("setMeasurement", &PyDbDatabase::setMeasurement)
        .def("setMirrtext", &PyDbDatabase::setMirrtext)
        .def("setMLeaderscale", &PyDbDatabase::setMLeaderscale)
        .def("setMLeaderstyle", &PyDbDatabase::setMLeaderstyle)
        .def("setMsltscale", &PyDbDatabase::setMsltscale)
        .def("setMsOleScale", &PyDbDatabase::setMsOleScale)
        .def("setNorthDirection", &PyDbDatabase::setNorthDirection)
        .def("setObscuredColor", &PyDbDatabase::setObscuredColor)
        .def("setObscuredLineType", &PyDbDatabase::setObscuredLineType)
        .def("setOleStartUp", &PyDbDatabase::setOleStartUp)
        .def("setOrthomode", &PyDbDatabase::setOrthomode)
        .def("setPdfframe", &PyDbDatabase::setPdfframe)
        .def("setPdmode", &PyDbDatabase::setPdmode)
        .def("setPdsize", &PyDbDatabase::setPdsize)
        .def("setPelevation", &PyDbDatabase::setPelevation)
        .def("setPextmax", &PyDbDatabase::setPextmax)
        .def("setPextmin", &PyDbDatabase::setPextmin)
        .def("setPickstyle", &PyDbDatabase::setPickstyle)
        .def("setPinsbase", &PyDbDatabase::setPinsbase)
        .def("setPlimcheck", &PyDbDatabase::setPlimcheck)
        .def("setPlimmax", &PyDbDatabase::setPlimmax)
        .def("setPlimmin", &PyDbDatabase::setPlimmin)
        .def("setPlineEllipse", &PyDbDatabase::setPlineEllipse)
        .def("setPlinegen", &PyDbDatabase::setPlinegen)
        .def("setPlinewid", &PyDbDatabase::setPlinewid)
        .def("setPreviewType", &PyDbDatabase::setPreviewType)
        .def("setProjectName", &PyDbDatabase::setProjectName)
        .def("setPsltscale", &PyDbDatabase::setPsltscale)
        .def("setPsolHeight", &PyDbDatabase::setPsolHeight)
        .def("setPsolWidth", &PyDbDatabase::setPsolWidth)
        .def("setPucs", &PyDbDatabase::setPucs)
        .def("setPucsBase", &PyDbDatabase::setPucsBase)
        .def("setPucsname", &PyDbDatabase::setPucsname)
        .def("setQtextmode", &PyDbDatabase::setQtextmode)
        .def("setRealWorldScale", &PyDbDatabase::setRealWorldScale)
        .def("setRegenmode", &PyDbDatabase::setRegenmode)
        .def("setRetainOriginalThumbnailBitmap", &PyDbDatabase::setRetainOriginalThumbnailBitmap)
        .def("setSaveproxygraphics", &PyDbDatabase::setSaveproxygraphics)
        .def("setSectionViewStyle", &PyDbDatabase::setSectionViewStyle)
        .def("setShadedge", &PyDbDatabase::setShadedge)
        .def("setShadedif", &PyDbDatabase::setShadedif)
        .def("setShadowPlaneLocation", &PyDbDatabase::setShadowPlaneLocation)
        .def("setShowHist", &PyDbDatabase::setShowHist)
        .def("setSketchinc", &PyDbDatabase::setSketchinc)
        .def("setSkpoly", &PyDbDatabase::setSkpoly)
        .def("setSolidHist", &PyDbDatabase::setSolidHist)
        .def("setSortEnts", &PyDbDatabase::setSortEnts)
        .def("setSplframe", &PyDbDatabase::setSplframe)
        .def("setSplinesegs", &PyDbDatabase::setSplinesegs)
        .def("setSplinetype", &PyDbDatabase::setSplinetype)
        .def("setStepSize", &PyDbDatabase::setStepSize)
        .def("setStepsPerSec", &PyDbDatabase::setStepsPerSec)
        .def("setStyleSheet", &PyDbDatabase::setStyleSheet)
        .def("setSurftab1", &PyDbDatabase::setSurftab1)
        .def("setSurftab2", &PyDbDatabase::setSurftab2)
        .def("setSurftype", &PyDbDatabase::setSurftype)
        .def("setSurfu", &PyDbDatabase::setSurfu)
        .def("setSurfv", &PyDbDatabase::setSurfv)
        .def("setTablestyle", &PyDbDatabase::setTablestyle)
        .def("setTextsize", &PyDbDatabase::setTextsize)
        .def("setTextstyle", &PyDbDatabase::setTextstyle)
        .def("setThickness", &PyDbDatabase::setThickness)
        .def("setTilemode", &PyDbDatabase::setTilemode)
        .def("setTimeZone", &PyDbDatabase::setTimeZone)
        .def("setTimeZoneAsUtcOffset", &PyDbDatabase::setTimeZoneAsUtcOffset)
        .def("setTracewid", &PyDbDatabase::setTracewid)
        .def("setTreedepth", &PyDbDatabase::setTreedepth)
        .def("setTStackAlign", &PyDbDatabase::setTStackAlign)
        .def("setTStackSize", &PyDbDatabase::setTStackSize)
        .def("setUcs", &PyDbDatabase::setUcs)
        .def("setUcsBase", &PyDbDatabase::setUcsBase)
        .def("setUcsname", &PyDbDatabase::setUcsname)
        .def("setUnitmode", &PyDbDatabase::setUnitmode)
        .def("setUpdateThumbnail", &PyDbDatabase::setUpdateThumbnail)
        .def("setUseri1", &PyDbDatabase::setUseri1)
        .def("setUseri2", &PyDbDatabase::setUseri2)
        .def("setUseri3", &PyDbDatabase::setUseri3)
        .def("setUseri4", &PyDbDatabase::setUseri4)
        .def("setUseri5", &PyDbDatabase::setUseri5)
        .def("setUserr1", &PyDbDatabase::setUserr1)
        .def("setUserr2", &PyDbDatabase::setUserr2)
        .def("setUserr3", &PyDbDatabase::setUserr3)
        .def("setUserr4", &PyDbDatabase::setUserr4)
        .def("setUserr5", &PyDbDatabase::setUserr5)
        .def("setUsrtimer", &PyDbDatabase::setUsrtimer)
        .def("setVersionGuid", &PyDbDatabase::setVersionGuid)
        .def("setViewportScaleDefault", &PyDbDatabase::setViewportScaleDefault)
        .def("setVisretain", &PyDbDatabase::setVisretain)
        .def("setWorldPucsBaseOrigin", &PyDbDatabase::setWorldPucsBaseOrigin)
        .def("setWorldUcsBaseOrigin", &PyDbDatabase::setWorldUcsBaseOrigin)
        .def("setWorldview", &PyDbDatabase::setWorldview)
        .def("setXclipFrame", &PyDbDatabase::setXclipFrame)
        .def("setXrefEditEnabled", &PyDbDatabase::setXrefEditEnabled)
        .def("shadedge", &PyDbDatabase::shadedge)
        .def("shadedif", &PyDbDatabase::shadedif)
        .def("shadowPlaneLocation", &PyDbDatabase::shadowPlaneLocation)
        .def("showHist", &PyDbDatabase::showHist)
        .def("sketchinc", &PyDbDatabase::sketchinc)
        .def("skpoly", &PyDbDatabase::skpoly)
        .def("solidHist", &PyDbDatabase::solidHist)
        .def("sortEnts", &PyDbDatabase::sortEnts)
        .def("splframe", &PyDbDatabase::splframe)
        .def("splinesegs", &PyDbDatabase::splinesegs)
        .def("splinetype", &PyDbDatabase::splinetype)
        .def("stepSize", &PyDbDatabase::stepSize)
        .def("stepsPerSec", &PyDbDatabase::stepsPerSec)
        .def("surftab1", &PyDbDatabase::surftab1)
        .def("surftab2", &PyDbDatabase::surftab2)
        .def("surftype", &PyDbDatabase::surftype)
        .def("surfu", &PyDbDatabase::surfu)
        .def("surfv", &PyDbDatabase::surfv)
        .def("tablestyle", &PyDbDatabase::tablestyle)
        .def("tableStyleDictionaryId", &PyDbDatabase::tableStyleDictionaryId)
        .def("textsize", &PyDbDatabase::textsize)
        .def("textstyle", &PyDbDatabase::textstyle)
        .def("textStyleTableId", &PyDbDatabase::textStyleTableId)
        .def("thickness", &PyDbDatabase::thickness)
        .def("tilemode", &PyDbDatabase::tilemode)
        .def("tileModeLightSynch", &PyDbDatabase::tileModeLightSynch)
        .def("timeZone", &PyDbDatabase::timeZone)
        .def("tracewid", &PyDbDatabase::tracewid)
        .def("treedepth", &PyDbDatabase::treedepth)
        .def("tstackalign", &PyDbDatabase::tstackalign)
        .def("tstacksize", &PyDbDatabase::tstacksize)
        .def("ucsBase", &PyDbDatabase::ucsBase)
        .def("ucsname", &PyDbDatabase::ucsname)
        .def("ucsorg", &PyDbDatabase::ucsorg)
        .def("UCSTableId", &PyDbDatabase::UCSTableId)
        .def("ucsxdir", &PyDbDatabase::ucsxdir)
        .def("ucsydir", &PyDbDatabase::ucsydir)
        .def("undoRecording", &PyDbDatabase::undoRecording)
        .def("unitmode", &PyDbDatabase::unitmode)
        .def("updateDataLink", &PyDbDatabase::updateDataLink)
        .def("updateExt", &PyDbDatabase::updateExt)
        .def("updateThumbnail", &PyDbDatabase::updateThumbnail)
        .def("useri1", &PyDbDatabase::useri1)
        .def("useri2", &PyDbDatabase::useri2)
        .def("useri3", &PyDbDatabase::useri3)
        .def("useri4", &PyDbDatabase::useri4)
        .def("useri5", &PyDbDatabase::useri5)
        .def("userr1", &PyDbDatabase::userr1)
        .def("userr2", &PyDbDatabase::userr2)
        .def("userr3", &PyDbDatabase::userr3)
        .def("userr4", &PyDbDatabase::userr4)
        .def("userr5", &PyDbDatabase::userr5)
        .def("usrtimer", &PyDbDatabase::usrtimer)
        .def("viewportScaleDefault", &PyDbDatabase::viewportScaleDefault)
        .def("viewportTableId", &PyDbDatabase::viewportTableId)
        .def("viewTableId", &PyDbDatabase::viewTableId)
        .def("visretain", &PyDbDatabase::visretain)
        .def("visualStyleDictionaryId", &PyDbDatabase::visualStyleDictionaryId)
        .def("worldPucsBaseOrigin", &PyDbDatabase::worldPucsBaseOrigin)
        .def("worldUcsBaseOrigin", &PyDbDatabase::worldUcsBaseOrigin)
        .def("worldview", &PyDbDatabase::worldview)
        .def("xclipFrame", &PyDbDatabase::xclipFrame)
        .def("xrefBlockId", &PyDbDatabase::xrefBlockId)
        .def("xrefEditEnabled", &PyDbDatabase::xrefEditEnabled)
        //TODO: TEST
        .def<Acad::ErrorStatus(PyDbDatabase::*)(PyDbDatabase&, const boost::python::list&, const AcGePoint3d&, AcDb::DuplicateRecordCloning drc)>("wblock", &PyDbDatabase::wblock)
        .def<Acad::ErrorStatus(PyDbDatabase::*)(PyDbDatabase&, const boost::python::list&, const AcGePoint3d&)>("wblock", &PyDbDatabase::wblock)
        .def<Acad::ErrorStatus(PyDbDatabase::*)(PyDbDatabase&, const PyDbObjectId& blockId)>("wblock", &PyDbDatabase::wblock)
        .def<Acad::ErrorStatus(PyDbDatabase::*)(PyDbDatabase&)>("wblock", &PyDbDatabase::wblock)
        .def("getFilename", &PyDbDatabase::getFilename)
        .def("readDwgFile", &PyDbDatabase::readDwgFile)
        .def("blockTableId", &PyDbDatabase::blockTableId)
        .def("modelSpaceId", &PyDbDatabase::modelSpaceId)
        .def("currentSpaceId", &PyDbDatabase::currentSpaceId)
        .def("className", &PyDbDatabase::className).staticmethod("className")
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
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->cameraDisplay();
#endif
}

double PyDbDatabase::cameraHeight() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->cameraHeight();
#endif
}

Adesk::Int16 PyDbDatabase::cDynDisplayMode() const
{
#ifdef BRXAPP
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
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return wstr_to_utf8(impObj()->classDxfName(pClass.impObj()));
#endif
}

PyDbObjectId PyDbDatabase::clayer() const
{
    return PyDbObjectId(impObj()->clayer());
}

Acad::ErrorStatus PyDbDatabase::closeInput(bool bCloseFile)
{
    return impObj()->closeInput(bCloseFile);
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

Adesk::UInt32 PyDbDatabase::countEmptyObjects(const Adesk::UInt32 flags)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->countEmptyObjects(flags);
#endif
}

PyDbObjectId PyDbDatabase::detailViewStyle() const
{
#ifdef BRXAPP
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
#ifdef BRXAPP
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
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->dwgFileWasSavedByAutodeskSoftware();
#endif
}

Acad::ErrorStatus PyDbDatabase::dxfIn(const std::string& dxfFilename)
{
    return impObj()->dxfIn(utf8_to_wstr(dxfFilename).c_str());
}

Acad::ErrorStatus PyDbDatabase::dxfOut(const std::string& dxfFilename)
{
    return impObj()->dxfOut(utf8_to_wstr(dxfFilename).c_str());
}

double PyDbDatabase::elevation() const
{
    return impObj()->elevation();
}

Adesk::UInt32 PyDbDatabase::eraseEmptyObjects(const Adesk::UInt32 flags)
{
#ifdef BRXAPP
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
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    impObj()->forceWblockDatabaseCopy();
#endif
}

std::string PyDbDatabase::geoCoordinateSystemId() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return wstr_to_utf8(impObj()->geoCoordinateSystemId());
#endif
}

bool PyDbDatabase::geoMarkerVisibility() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->geoMarkerVisibility();
#endif
}

double PyDbDatabase::get3dDwfPrec() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->get3dDwfPrec();
#endif
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
    PyAutoLockGIL lock;
    AcDbObjectIdArray vportIds;
    boost::python::list pyvportIds;
    {
        if (eOk == impObj()->getViewportArray(vportIds))
        {
            for (auto& item : vportIds)
                pyvportIds.append(PyDbObjectId(item));
        }

    }
    return pyvportIds;
}

boost::python::list PyDbDatabase::getVisualStyleList()
{
    PyAutoLockGIL lock;
    boost::python::list pyvstyleList;
    AcArray<const ACHAR*> vstyleList;
    {
        if (eOk == impObj()->getVisualStyleList(vstyleList))
        {
            for (const auto& item : vstyleList)
                pyvstyleList(wstr_to_utf8(item));
        }

    }
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

Acad::ErrorStatus PyDbDatabase::insert(PyDbObjectId& blockId, const std::string& pBlockName, PyDbDatabase& db, bool preserveSourceDatabase)
{
    return impObj()->insert(blockId.m_id, utf8_to_wstr(pBlockName).c_str(), db.impObj(), preserveSourceDatabase);
}

Acad::ErrorStatus PyDbDatabase::insert(PyDbObjectId& blockId, const std::string& pSourceBlockName, const std::string& pDestinationBlockName, PyDbDatabase& db, bool preserveSourceDatabase)
{
    return impObj()->insert(blockId.m_id, utf8_to_wstr(pSourceBlockName).c_str(), utf8_to_wstr(pDestinationBlockName).c_str(), db.impObj(), preserveSourceDatabase);
}

Acad::ErrorStatus PyDbDatabase::insert(const AcGeMatrix3d& xform, PyDbDatabase& db, bool preserveSourceDatabase)
{
    return impObj()->insert(xform, db.impObj(), preserveSourceDatabase);
}

Adesk::UInt8 PyDbDatabase::haloGap() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->haloGap();
#endif
}

bool PyDbDatabase::hasClass(const PyRxClass& pClass) const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->hasClass(pClass.impObj());
#endif
}

Adesk::UInt8 PyDbDatabase::hideText() const
{
#ifdef BRXAPP
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
#ifdef BRXAPP
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
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return PyDbObjectId(impObj()->interfereVpVisStyle());
#endif
}

Adesk::UInt16 PyDbDatabase::intersectColor() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->intersectDisplay();
#endif
}

Adesk::UInt8 PyDbDatabase::intersectDisplay() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->intersectDisplay();
#endif
}

bool PyDbDatabase::isBeingDestroyed() const
{
#ifdef BRXAPP
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
#ifdef BRXAPP
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
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->layerEval();
#endif
}

Adesk::Int16 PyDbDatabase::layerNotify() const
{
#ifdef BRXAPP
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
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->lensLength();
#endif
}

Adesk::UInt8 PyDbDatabase::lightGlyphDisplay() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->lightGlyphDisplay();
#endif
}

Adesk::UInt8 PyDbDatabase::lightingUnits() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->lightingUnits();
#endif
}

bool PyDbDatabase::lightsInBlocks() const
{
#ifdef BRXAPP
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

Acad::ErrorStatus PyDbDatabase::loadLineTypeFile(const std::string& ltn, const std::string& filename)
{
    return impObj()->loadLineTypeFile(utf8_to_wstr(ltn).c_str(), utf8_to_wstr(filename).c_str());
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

Acad::ErrorStatus PyDbDatabase::registerApp(const std::string& pszAppName)
{
#ifdef ARX2023
    return impObj()->registerApp(utf8_to_wstr(pszAppName).c_str());
#else
    throw PyNotimplementedByHost();
#endif
}

int PyDbDatabase::maintenanceReleaseVersion() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->maintenanceReleaseVersion();
#endif
}

Acad::ErrorStatus PyDbDatabase::markObjectNonPersistent(const PyDbObjectId& id, bool value)
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
#ifdef BRXAPP
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
#ifdef BRXAPP
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
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->obscuredColor();
#endif
}

Adesk::UInt8 PyDbDatabase::obscuredLineType() const
{
#ifdef BRXAPP
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
#ifdef BRXAPP
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
#ifdef BRXAPP
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
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->psolHeight();
#endif
}

double PyDbDatabase::psolWidth() const
{
#ifdef BRXAPP
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

bool PyDbDatabase::qtextmode() const
{
    return impObj()->qtextmode();
}

Acad::ErrorStatus PyDbDatabase::reclaimMemoryFromErasedObjects(const boost::python::list& erasedObjects)
{
    PyAutoLockGIL lock;
    const auto PyDbObjectIds = py_list_to_std_vector<PyDbObjectId>(erasedObjects);
    AcDbObjectIdArray ids;
    for (const auto& pyId : PyDbObjectIds)
        ids.append(pyId.m_id);
    return impObj()->reclaimMemoryFromErasedObjects(ids);
}

PyDbObjectId PyDbDatabase::regAppTableId() const
{
    return PyDbObjectId(impObj()->regAppTableId());
}

bool PyDbDatabase::regenmode() const
{
    return impObj()->regenmode();
}

Acad::ErrorStatus PyDbDatabase::resetTimes()
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->resetTimes();
#endif
}

Acad::ErrorStatus PyDbDatabase::restoreForwardingXrefSymbols()
{
    return impObj()->restoreForwardingXrefSymbols();
}

Acad::ErrorStatus PyDbDatabase::restoreOriginalXrefSymbols()
{
    return impObj()->restoreOriginalXrefSymbols();
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
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return PyDbObjectId(impObj()->sectionViewStyle());
#endif
}

PyDbObjectId PyDbDatabase::sectionViewStyleDictionaryId() const
{
    return PyDbObjectId(impObj()->sectionViewStyleDictionaryId());
}

Acad::ErrorStatus PyDbDatabase::set3dDwfPrec(double DwfPrec)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->set3dDwfPrec(DwfPrec);
#endif
}

Acad::ErrorStatus PyDbDatabase::setAngbase(double angle)
{
    return impObj()->setAngbase(angle);
}

Acad::ErrorStatus PyDbDatabase::setAngdir(bool dir)
{
    return impObj()->setAngdir(dir);
}

Acad::ErrorStatus PyDbDatabase::setAnnoAllVisible(bool allvis)
{
    return impObj()->setAnnoAllVisible(allvis);
}

Acad::ErrorStatus PyDbDatabase::setAttdia(bool dia)
{
    return impObj()->setAttdia(dia);
}

Acad::ErrorStatus PyDbDatabase::setAttmode(Adesk::Int16 mode)
{
    return impObj()->setAttmode(mode);
}

Acad::ErrorStatus PyDbDatabase::setAttreq(bool req)
{
    return impObj()->setAttreq(req);
}

Acad::ErrorStatus PyDbDatabase::setAunits(Adesk::Int16 aunits)
{
    return impObj()->setAunits(aunits);
}

Acad::ErrorStatus PyDbDatabase::setAuprec(Adesk::Int16 auprec)
{
    return impObj()->setAuprec(auprec);
}

Acad::ErrorStatus PyDbDatabase::setBlipmode(bool mode)
{
    return impObj()->setBlipmode(mode);
}

Acad::ErrorStatus PyDbDatabase::setCameraDisplay(bool cameraDisplay)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setCameraDisplay(cameraDisplay);
#endif
}

Acad::ErrorStatus PyDbDatabase::setCameraHeight(double cameraHeight)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setCameraHeight(cameraHeight);
#endif
}

Acad::ErrorStatus PyDbDatabase::setCDynDisplayMode(Adesk::Int16 val)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setCDynDisplayMode(val);
#endif
}

Acad::ErrorStatus PyDbDatabase::setCeltscale(double scale)
{
    return impObj()->setCeltscale(scale);
}

Acad::ErrorStatus PyDbDatabase::setCeltype(const PyDbObjectId& id)
{
    return impObj()->setCeltype(id.m_id);
}

Acad::ErrorStatus PyDbDatabase::setCelweight(AcDb::LineWeight weight)
{
    return impObj()->setCelweight(weight);
}

Acad::ErrorStatus PyDbDatabase::setCePlotStyleName(AcDb::PlotStyleNameType type, const PyDbObjectId& id)
{
    return impObj()->setCePlotStyleName(type, id.m_id);
}

Acad::ErrorStatus PyDbDatabase::setChamfera(double val)
{
    return impObj()->setChamfera(val);
}

Acad::ErrorStatus PyDbDatabase::setChamferb(double val)
{
    return impObj()->setChamferb(val);
}

Acad::ErrorStatus PyDbDatabase::setChamferc(double val)
{
    return impObj()->setChamferc(val);
}

Acad::ErrorStatus PyDbDatabase::setChamferd(double val)
{
    return impObj()->setChamferd(val);
}

Acad::ErrorStatus PyDbDatabase::setClayer(const PyDbObjectId& id)
{
    return impObj()->setClayer(id.m_id);
}

Acad::ErrorStatus PyDbDatabase::setCmaterial(const PyDbObjectId& id)
{
    return impObj()->setCmaterial(id.m_id);
}

Acad::ErrorStatus PyDbDatabase::setCmljust(Adesk::Int16 just)
{
    return impObj()->setCmljust(just);
}

Acad::ErrorStatus PyDbDatabase::setCmlscale(double scale)
{
    return impObj()->setCmlscale(scale);
}

Acad::ErrorStatus PyDbDatabase::setCmlstyleID(const PyDbObjectId& id)
{
    return impObj()->setCmlstyleID(id.m_id);
}

Acad::ErrorStatus PyDbDatabase::setCoords(Adesk::Int16 _coords)
{
    return impObj()->setCoords(_coords);
}

Acad::ErrorStatus PyDbDatabase::setCshadow(Adesk::UInt8 val)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setCshadow(val);
#endif
}

Acad::ErrorStatus PyDbDatabase::setDelUsedObj(Adesk::Int16 deleteObj)
{
    return impObj()->setDelUsedObj(deleteObj);
}

Acad::ErrorStatus PyDbDatabase::setDgnframe(Adesk::UInt8 val)
{
#ifdef ARXAPP
    return impObj()->setDgnframe(val);
#else
    throw PyNotimplementedByHost();
#endif
}

Acad::ErrorStatus PyDbDatabase::setDimaso(bool aso)
{
    return impObj()->setDimaso(aso);
}

Acad::ErrorStatus PyDbDatabase::setDimAssoc(Adesk::UInt8 val)
{
    return impObj()->setDimAssoc(val);
}

Acad::ErrorStatus PyDbDatabase::setDimfit(int fit)
{
    return impObj()->setDimfit(fit);
}

Acad::ErrorStatus PyDbDatabase::setDimsho(bool sho)
{
    return impObj()->setDimsho(sho);
}

Acad::ErrorStatus PyDbDatabase::setDimstyle(const PyDbObjectId& id)
{
    return impObj()->setDimstyle(id.m_id);
}

Acad::ErrorStatus PyDbDatabase::setDimstyleData(const PyDbObjectId& id)
{
    return impObj()->setDimstyleData(id.m_id);
}

Acad::ErrorStatus PyDbDatabase::setDimunit(int unit)
{
    return impObj()->setDimunit(unit);
}

Acad::ErrorStatus PyDbDatabase::setDispSilh(bool silh)
{
    return impObj()->setDispSilh(silh);
}

Acad::ErrorStatus PyDbDatabase::setDragmode(Adesk::Int16 mode)
{
    return impObj()->setDragmode(mode);
}

Acad::ErrorStatus PyDbDatabase::setDragVisStyle(const PyDbObjectId& id)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setDragVisStyle(id.m_id);
#endif
}

Acad::ErrorStatus PyDbDatabase::setDrawOrderCtl(Adesk::UInt8 val)
{
    return impObj()->setDrawOrderCtl(val);
}

Acad::ErrorStatus PyDbDatabase::setDwfframe(Adesk::UInt8 val)
{
    return impObj()->setDwfframe(val);
}

Acad::ErrorStatus PyDbDatabase::setElevation(double elev)
{
    return impObj()->setElevation(elev);
}

Acad::ErrorStatus PyDbDatabase::setEndCaps(AcDb::EndCaps type)
{
    return impObj()->setEndCaps(type);
}

Acad::ErrorStatus PyDbDatabase::setExtmax(const AcGePoint3d& max)
{
    return impObj()->setExtmax(max);
}

Acad::ErrorStatus PyDbDatabase::setExtmin(const AcGePoint3d& min)
{
    return impObj()->setExtmin(min);
}

Acad::ErrorStatus PyDbDatabase::setFacetres(double _facetres)
{
    return impObj()->setFacetres(_facetres);
}

Acad::ErrorStatus PyDbDatabase::setFilletrad(double radius)
{
    return impObj()->setFilletrad(radius);
}

Acad::ErrorStatus PyDbDatabase::setFillmode(bool mode)
{
    return impObj()->setFillmode(mode);
}

Acad::ErrorStatus PyDbDatabase::saveAs(const std::string& fileName)
{
    return impObj()->saveAs(utf8_to_wstr(fileName).c_str());
}

Acad::ErrorStatus PyDbDatabase::setFingerprintGuid(const std::string& newGuid)
{
    return impObj()->setFingerprintGuid(utf8_to_wstr(newGuid).c_str());
}

void PyDbDatabase::setFullSaveRequired()
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    impObj()->setFullSaveRequired();
#endif
}

Acad::ErrorStatus PyDbDatabase::readDwgFile(const char* fileName)
{
    std::wstring wsfileName{ utf8_to_wstr(fileName) }
    ;
    return impObj()->readDwgFile(wsfileName.c_str());
    return eNullPtr;
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

Acad::ErrorStatus PyDbDatabase::setGeoMarkerVisibility(bool value)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setGeoMarkerVisibility(value);
#endif
}

Acad::ErrorStatus PyDbDatabase::setHaloGap(Adesk::UInt8 val)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setHaloGap(val);
#endif
}

Acad::ErrorStatus PyDbDatabase::setHideText(Adesk::UInt8 val)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setHideText(val);
#endif
}

Acad::ErrorStatus PyDbDatabase::setHpInherit(const bool inherit)
{
    return impObj()->setHpInherit(inherit);
}

Acad::ErrorStatus PyDbDatabase::setHpOrigin(const AcGePoint2d& origin)
{
    return impObj()->setHpOrigin(origin);
}

Acad::ErrorStatus PyDbDatabase::setHyperlinkBase(const std::string& val)
{
    return impObj()->setHyperlinkBase(utf8_to_wstr(val).c_str());
}

Acad::ErrorStatus PyDbDatabase::setIndexctl(Adesk::UInt8 val)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setIndexctl(val);
#endif
}

Acad::ErrorStatus PyDbDatabase::setInsbase(const AcGePoint3d& base)
{
    return impObj()->setInsbase(base);
}

Acad::ErrorStatus PyDbDatabase::setInsunits(const AcDb::UnitsValue units)
{
    return impObj()->setInsunits(units);
}

Acad::ErrorStatus PyDbDatabase::setInterfereObjVisStyle(const PyDbObjectId& id)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setInterfereObjVisStyle(id.m_id);
#endif
}

Acad::ErrorStatus PyDbDatabase::setInterfereVpVisStyle(const PyDbObjectId& id)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setInterfereVpVisStyle(id.m_id);
#endif
}

Acad::ErrorStatus PyDbDatabase::setIntersectColor(Adesk::UInt16 val)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setIntersectColor(val);
#endif
}

Acad::ErrorStatus PyDbDatabase::setIntersectDisplay(Adesk::UInt8 val)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setIntersectDisplay(val);
#endif
}

Acad::ErrorStatus PyDbDatabase::setIsolines(Adesk::Int16 isolines)
{
    return impObj()->setIsolines(isolines);
}

Acad::ErrorStatus PyDbDatabase::setJoinStyle(AcDb::JoinStyle style)
{
    return impObj()->setJoinStyle(style);
}

Acad::ErrorStatus PyDbDatabase::setLatitude(double lat)
{
    return impObj()->setLatitude(lat);
}

Acad::ErrorStatus PyDbDatabase::setLayerEval(Adesk::UInt8 val)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setLayerEval(val);
#endif
}

Acad::ErrorStatus PyDbDatabase::setLayerNotify(Adesk::Int16 val)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setLayerNotify(val);
#endif
}

Acad::ErrorStatus PyDbDatabase::setLensLength(const double _lensLength)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setLensLength(_lensLength);
#endif
}

Acad::ErrorStatus PyDbDatabase::setLightGlyphDisplay(Adesk::UInt8 val)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setLightGlyphDisplay(val);
#endif
}

Acad::ErrorStatus PyDbDatabase::setLightingUnits(Adesk::UInt8 val)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setLightingUnits(val);
#endif
}

Acad::ErrorStatus PyDbDatabase::setLightsInBlocks(bool val)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setLightsInBlocks(val);
#endif
}

Acad::ErrorStatus PyDbDatabase::setLimcheck(bool check)
{
    return impObj()->setLimcheck(check);
}

Acad::ErrorStatus PyDbDatabase::setLimmax(const AcGePoint2d& max)
{
    return impObj()->setLimmax(max);
}

Acad::ErrorStatus PyDbDatabase::setLimmin(const AcGePoint2d& min)
{
    return impObj()->setLimmin(min);
}

Acad::ErrorStatus PyDbDatabase::setLineWeightDisplay(bool display)
{
    return impObj()->setLineWeightDisplay(display);
}

Acad::ErrorStatus PyDbDatabase::setLoftAng1(double ang1)
{
    return impObj()->setLoftAng1(ang1);
}

Acad::ErrorStatus PyDbDatabase::setLoftAng2(double ang2)
{
    return impObj()->setLoftAng2(ang2);
}

Acad::ErrorStatus PyDbDatabase::setLoftMag1(double mag1)
{
    return impObj()->setLoftMag1(mag1);
}

Acad::ErrorStatus PyDbDatabase::setLoftMag2(double mag2)
{
    return impObj()->setLoftMag2(mag2);
}

Acad::ErrorStatus PyDbDatabase::setLoftNormals(Adesk::UInt8 value)
{
    return impObj()->setLoftNormals(value);
}

Acad::ErrorStatus PyDbDatabase::setLoftParam(Adesk::UInt16 flags)
{
    return impObj()->setLoftParam(flags);
}

Acad::ErrorStatus PyDbDatabase::setLongitude(double lng)
{
    return impObj()->setLongitude(lng);
}

Acad::ErrorStatus PyDbDatabase::setLtscale(double scale)
{
    return impObj()->setLtscale(scale);
}

Acad::ErrorStatus PyDbDatabase::setLunits(Adesk::Int16 lunits)
{
    return impObj()->setLunits(lunits);
}

Acad::ErrorStatus PyDbDatabase::setLuprec(Adesk::Int16 prec)
{
    return impObj()->setLuprec(prec);
}

Acad::ErrorStatus PyDbDatabase::setMaxactvp(Adesk::Int16 max)
{
    return impObj()->setMaxactvp(max);
}

Acad::ErrorStatus PyDbDatabase::setMeasurement(AcDb::MeasurementValue type)
{
    return impObj()->setMeasurement(type);
}

Acad::ErrorStatus PyDbDatabase::setMirrtext(bool mirror)
{
    return impObj()->setMirrtext(mirror);
}

Acad::ErrorStatus PyDbDatabase::setMLeaderscale(double scale)
{
    return impObj()->setMLeaderscale(scale);
}

Acad::ErrorStatus PyDbDatabase::setMLeaderstyle(const PyDbObjectId& objId)
{
    return impObj()->setMLeaderstyle(objId.m_id);
}

Acad::ErrorStatus PyDbDatabase::setMsltscale(bool val)
{
    return impObj()->setMsltscale(val);
}

Acad::ErrorStatus PyDbDatabase::setMsOleScale(double val)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setMsOleScale(val);
#endif
}

Acad::ErrorStatus PyDbDatabase::setNorthDirection(double northdir)
{
    return impObj()->setNorthDirection(northdir);
}

Acad::ErrorStatus PyDbDatabase::setObscuredColor(Adesk::UInt16 val)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setObscuredColor(val);
#endif
}

Acad::ErrorStatus PyDbDatabase::setObscuredLineType(Adesk::UInt8 val)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setObscuredLineType(val);
#endif
}

Acad::ErrorStatus PyDbDatabase::setOleStartUp(bool val)
{
    return impObj()->setOleStartUp(val);
}

Acad::ErrorStatus PyDbDatabase::setOrthomode(bool mode)
{
    return impObj()->setOrthomode(mode);
}

Acad::ErrorStatus PyDbDatabase::setPdfframe(Adesk::Int8 val)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setPdfframe(val);
#endif
}

Acad::ErrorStatus PyDbDatabase::setPdmode(Adesk::Int16 mode)
{
    return impObj()->setPdmode(mode);
}

Acad::ErrorStatus PyDbDatabase::setPdsize(double size)
{
    return impObj()->setPdsize(size);
}

Acad::ErrorStatus PyDbDatabase::setPelevation(double elev)
{
    return impObj()->setPelevation(elev);
}

Acad::ErrorStatus PyDbDatabase::setPextmax(const AcGePoint3d& max)
{
    return impObj()->setPextmax(max);
}

Acad::ErrorStatus PyDbDatabase::setPextmin(const AcGePoint3d& min)
{
    return impObj()->setPextmin(min);
}

Acad::ErrorStatus PyDbDatabase::setPickstyle(Adesk::Int16 style)
{
    return impObj()->setPickstyle(style);
}

Acad::ErrorStatus PyDbDatabase::setPinsbase(const AcGePoint3d& base)
{
    return impObj()->setPinsbase(base);
}

Acad::ErrorStatus PyDbDatabase::setPlimcheck(bool check)
{
    return impObj()->setPlimcheck(check);
}

Acad::ErrorStatus PyDbDatabase::setPlimmax(const AcGePoint2d& max)
{
    return impObj()->setPlimmax(max);
}

Acad::ErrorStatus PyDbDatabase::setPlimmin(const AcGePoint2d& min)
{
    return impObj()->setPlimmin(min);
}

Acad::ErrorStatus PyDbDatabase::setPlineEllipse(bool pline)
{
    return impObj()->setPlineEllipse(pline);
}

Acad::ErrorStatus PyDbDatabase::setPlinegen(bool gen)
{
    return impObj()->setPlinegen(gen);
}

Acad::ErrorStatus PyDbDatabase::setPlinewid(double width)
{
    return impObj()->setPlinewid(width);
}

Acad::ErrorStatus PyDbDatabase::setPreviewType(Adesk::Int16 val)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setPreviewType(val);
#endif
}

Acad::ErrorStatus PyDbDatabase::setProjectName(const std::string& val)
{
    return impObj()->setProjectName(utf8_to_wstr(val).c_str());
}

Acad::ErrorStatus PyDbDatabase::setPsltscale(bool scale)
{
    return impObj()->setPsltscale(scale);
}

Acad::ErrorStatus PyDbDatabase::setPsolHeight(double height)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setPsolHeight(height);
#endif
}

Acad::ErrorStatus PyDbDatabase::setPsolWidth(double width)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setPsolWidth(width);
#endif
}

Acad::ErrorStatus PyDbDatabase::setPucs(const AcGePoint3d& ucsOrigin, const AcGeVector3d& ucsXDir, const AcGeVector3d& ucsYDir)
{
    return impObj()->setPucs(ucsOrigin, ucsXDir, ucsYDir);
}

Acad::ErrorStatus PyDbDatabase::setPucsBase(const PyDbObjectId& ucsid)
{
    return impObj()->setPucsBase(ucsid.m_id);
}

Acad::ErrorStatus PyDbDatabase::setPucsname(const PyDbObjectId& ucsRecId)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setPucsname(ucsRecId.m_id);
#endif
}

Acad::ErrorStatus PyDbDatabase::setQtextmode(bool mode)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setQtextmode(mode);
#endif
}

Acad::ErrorStatus PyDbDatabase::setRealWorldScale(const bool realWorldScale)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setRealWorldScale(realWorldScale);
#endif
}

Acad::ErrorStatus PyDbDatabase::setRegenmode(bool mode)
{
    return impObj()->setRegenmode(mode);
}

void PyDbDatabase::setRetainOriginalThumbnailBitmap(bool retain)
{
    return impObj()->setRetainOriginalThumbnailBitmap(retain);
}

Acad::ErrorStatus PyDbDatabase::setSaveproxygraphics(Adesk::Int16 saveimg)
{
    return impObj()->setSaveproxygraphics(saveimg);
}

Acad::ErrorStatus PyDbDatabase::setSectionViewStyle(const PyDbObjectId& objId)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setSectionViewStyle(objId.m_id);
#endif
}

Acad::ErrorStatus PyDbDatabase::setShadedge(Adesk::Int16 mode)
{
    return impObj()->setShadedge(mode);
}

Acad::ErrorStatus PyDbDatabase::setShadedif(Adesk::Int16 dif)
{
    return impObj()->setShadedif(dif);
}

Acad::ErrorStatus PyDbDatabase::setShadowPlaneLocation(double val)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setShadowPlaneLocation(val);
#endif
}

Acad::ErrorStatus PyDbDatabase::setShowHist(Adesk::UInt8 val)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setShowHist(val);
#endif
}

Acad::ErrorStatus PyDbDatabase::setSketchinc(double inc)
{
    return impObj()->setSketchinc(inc);
}

Acad::ErrorStatus PyDbDatabase::setSkpoly(bool asPoly)
{
    return impObj()->setSkpoly(asPoly);
}

Acad::ErrorStatus PyDbDatabase::setSolidHist(Adesk::UInt8 val)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setSolidHist(val);
#endif
}

Acad::ErrorStatus PyDbDatabase::setSortEnts(Adesk::UInt8 sortEnts)
{
    return impObj()->setSortEnts(sortEnts);
}

Acad::ErrorStatus PyDbDatabase::setSplframe(bool disp)
{
    return impObj()->setSplframe(disp);
}

Acad::ErrorStatus PyDbDatabase::setSplinesegs(Adesk::Int16 segs)
{
    return impObj()->setSplinesegs(segs);
}

Acad::ErrorStatus PyDbDatabase::setSplinetype(Adesk::Int16 type)
{
    return impObj()->setSplinetype(type);
}

Acad::ErrorStatus PyDbDatabase::setStepSize(double stepSize)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setStepSize(stepSize);
#endif
}

Acad::ErrorStatus PyDbDatabase::setStepsPerSec(double stepsPerSec)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setStepsPerSec(stepsPerSec);
#endif
}

Acad::ErrorStatus PyDbDatabase::setStyleSheet(const std::string& val)
{
    return impObj()->setStyleSheet(utf8_to_wstr(val).c_str());
}

Acad::ErrorStatus PyDbDatabase::setSurftab1(Adesk::Int16 tab1)
{
    return impObj()->setSurftab1(tab1);
}

Acad::ErrorStatus PyDbDatabase::setSurftab2(Adesk::Int16 tab2)
{
    return impObj()->setSurftab2(tab2);
}

Acad::ErrorStatus PyDbDatabase::setSurftype(Adesk::Int16 type)
{
    return impObj()->setSurftype(type);
}

Acad::ErrorStatus PyDbDatabase::setSurfu(Adesk::Int16 v)
{
    return impObj()->setSurfu(v);
}

Acad::ErrorStatus PyDbDatabase::setSurfv(Adesk::Int16 v)
{
    return impObj()->setSurfv(v);
}

Acad::ErrorStatus PyDbDatabase::setTablestyle(const PyDbObjectId& objId)
{
    return impObj()->setTablestyle(objId.m_id);
}

Acad::ErrorStatus PyDbDatabase::setTextsize(double size)
{
    return impObj()->setTextsize(size);
}

Acad::ErrorStatus PyDbDatabase::setTextstyle(const PyDbObjectId& objId)
{
    return impObj()->setTextstyle(objId.m_id);
}

Acad::ErrorStatus PyDbDatabase::setThickness(double thickness)
{
    return impObj()->setThickness(thickness);
}

Acad::ErrorStatus PyDbDatabase::setTilemode(bool mode)
{
    return impObj()->setTilemode(mode);
}

Acad::ErrorStatus PyDbDatabase::setTimeZone(AcDb::TimeZone tz)
{
    return impObj()->setTimeZone(tz);
}

Acad::ErrorStatus PyDbDatabase::setTimeZoneAsUtcOffset(double offset)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setTimeZoneAsUtcOffset(offset);
#endif
}

Acad::ErrorStatus PyDbDatabase::setTracewid(double width)
{
    return impObj()->setTracewid(width);
}

Acad::ErrorStatus PyDbDatabase::setTreedepth(Adesk::Int16 depth)
{
    return impObj()->setTreedepth(depth);
}

Acad::ErrorStatus PyDbDatabase::setTStackAlign(int val)
{
    return impObj()->setTStackAlign(val);
}

Acad::ErrorStatus PyDbDatabase::setTStackSize(int val)
{
    return impObj()->setTStackSize(val);
}

Acad::ErrorStatus PyDbDatabase::setUcs(const AcGePoint3d& ucsOrigin, const AcGeVector3d& ucsXDir, const AcGeVector3d& ucsYDir)
{
    return impObj()->setUcs(ucsOrigin, ucsXDir, ucsYDir);
}

Acad::ErrorStatus PyDbDatabase::setUcsBase(const PyDbObjectId& ucsid)
{
    return impObj()->setUcsBase(ucsid.m_id);
}

Acad::ErrorStatus PyDbDatabase::setUcsname(const PyDbObjectId& ucsRecId)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setUcsname(ucsRecId.m_id);
#endif
}

Acad::ErrorStatus PyDbDatabase::setUnitmode(Adesk::Int16 mode)
{
    return impObj()->setUnitmode(mode);
}

Acad::ErrorStatus PyDbDatabase::setUpdateThumbnail(Adesk::UInt8 val)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setUpdateThumbnail(val);
#endif
}

Acad::ErrorStatus PyDbDatabase::setUseri1(Adesk::Int16 val)
{
    return impObj()->setUseri1(val);
}

Acad::ErrorStatus PyDbDatabase::setUseri2(Adesk::Int16 val)
{
    return impObj()->setUseri2(val);
}

Acad::ErrorStatus PyDbDatabase::setUseri3(Adesk::Int16 val)
{
    return impObj()->setUseri3(val);
}

Acad::ErrorStatus PyDbDatabase::setUseri4(Adesk::Int16 val)
{
    return impObj()->setUseri4(val);
}

Acad::ErrorStatus PyDbDatabase::setUseri5(Adesk::Int16 val)
{
    return impObj()->setUseri5(val);
}

Acad::ErrorStatus PyDbDatabase::setUserr1(double val)
{
    return impObj()->setUserr1(val);
}

Acad::ErrorStatus PyDbDatabase::setUserr2(double val)
{
    return impObj()->setUserr2(val);
}

Acad::ErrorStatus PyDbDatabase::setUserr3(double val)
{
    return impObj()->setUserr3(val);
}

Acad::ErrorStatus PyDbDatabase::setUserr4(double val)
{
    return impObj()->setUserr4(val);
}

Acad::ErrorStatus PyDbDatabase::setUserr5(double val)
{
    return impObj()->setUserr5(val);
}

Acad::ErrorStatus PyDbDatabase::setUsrtimer(bool timer)
{
    return impObj()->setUsrtimer(timer);
}

Acad::ErrorStatus PyDbDatabase::setVersionGuid(const std::string& pNewGuid)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setVersionGuid(utf8_to_wstr(pNewGuid).c_str());
#endif
}

Acad::ErrorStatus PyDbDatabase::setViewportScaleDefault(double newDefaultVPScale)
{
    return impObj()->setVisretain(newDefaultVPScale);
}

Acad::ErrorStatus PyDbDatabase::setVisretain(bool retain)
{
    return impObj()->setVisretain(retain);
}

Acad::ErrorStatus PyDbDatabase::setWorldPucsBaseOrigin(const AcGePoint3d& origin, AcDb::OrthographicView orthoView)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setWorldPucsBaseOrigin(origin, orthoView);
#endif
}

Acad::ErrorStatus PyDbDatabase::setWorldUcsBaseOrigin(const AcGePoint3d& origin, AcDb::OrthographicView orthoView)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setWorldUcsBaseOrigin(origin, orthoView);
#endif
}

Acad::ErrorStatus PyDbDatabase::setWorldview(bool view)
{
    return impObj()->setWorldview(view);
}

Acad::ErrorStatus PyDbDatabase::setXclipFrame(Adesk::UInt8 disp)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setXclipFrame(disp);
#endif
}

Acad::ErrorStatus PyDbDatabase::setXrefEditEnabled(bool enable)
{
    return impObj()->setXrefEditEnabled(enable);
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
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->shadowPlaneLocation();
#endif
}

Adesk::UInt8 PyDbDatabase::showHist() const
{
#ifdef BRXAPP
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
#ifdef BRXAPP
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
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->stepSize();
#endif
}

double PyDbDatabase::stepsPerSec() const
{
#ifdef BRXAPP
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
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->tileModeLightSynch();
#endif
}

int PyDbDatabase::timeZone() const
{
    return impObj()->timeZone();
}

double PyDbDatabase::tracewid() const
{
    return impObj()->tracewid();
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

Acad::ErrorStatus PyDbDatabase::updateDataLink(AcDb::UpdateDirection nDir, AcDb::UpdateOption nOption)
{
    return impObj()->updateDataLink(nDir, nOption);
}

Acad::ErrorStatus PyDbDatabase::updateExt(bool doBestFit)
{
    return impObj()->updateExt(doBestFit);
}

Adesk::UInt8 PyDbDatabase::updateThumbnail() const
{
#ifdef BRXAPP
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

Acad::ErrorStatus PyDbDatabase::wblock(PyDbDatabase& pOutputDb)
{
    AcDbDatabase* _pOutputDb = nullptr;
    auto stat = impObj()->wblock(_pOutputDb);
    if (stat == eOk && _pOutputDb != nullptr)
        pOutputDb = PyDbDatabase(_pOutputDb, true);
    return stat;
}

Acad::ErrorStatus PyDbDatabase::wblock(PyDbDatabase& pOutputDb, const PyDbObjectId& blockId)
{
    AcDbDatabase* _pOutputDb = nullptr;
    auto stat = impObj()->wblock(_pOutputDb, blockId.m_id);
    if (stat == eOk && _pOutputDb != nullptr)
        pOutputDb = PyDbDatabase(_pOutputDb, true);
    return stat;
}

Acad::ErrorStatus PyDbDatabase::wblock(PyDbDatabase& pOutputDb, const boost::python::list& outObjIds, const AcGePoint3d& basePoint)
{
    PyAutoLockGIL lock;
    //TODO: maybe we can do better
    const auto PyDbObjectIds = py_list_to_std_vector<PyDbObjectId>(outObjIds);
    AcDbObjectIdArray ids;
    for (const auto& pyId : PyDbObjectIds)
        ids.append(pyId.m_id);
    AcDbDatabase* _pOutputDb = nullptr;
    auto stat = impObj()->wblock(_pOutputDb, ids, basePoint);
    if (stat == eOk && _pOutputDb != nullptr)
        pOutputDb = PyDbDatabase(_pOutputDb, true);
    return stat;
}

Acad::ErrorStatus PyDbDatabase::wblock(PyDbDatabase& pOutputDb, const boost::python::list& outObjIds, const AcGePoint3d& basePoint, AcDb::DuplicateRecordCloning drc)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    PyAutoLockGIL lock;
    //TODO: maybe we can do better
    const auto PyDbObjectIds = py_list_to_std_vector<PyDbObjectId>(outObjIds);
    AcDbObjectIdArray ids;
    for (const auto& pyId : PyDbObjectIds)
        ids.append(pyId.m_id);
    AcDbDatabase* pDb = pOutputDb.impObj();
    return impObj()->wblock(pDb, ids, basePoint, drc);
#endif
}

AcGePoint3d PyDbDatabase::worldPucsBaseOrigin(AcDb::OrthographicView orthoView) const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->worldPucsBaseOrigin(orthoView);
#endif
}

AcGePoint3d PyDbDatabase::worldUcsBaseOrigin(AcDb::OrthographicView orthoView) const
{
#ifdef BRXAPP
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
#ifdef BRXAPP
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

