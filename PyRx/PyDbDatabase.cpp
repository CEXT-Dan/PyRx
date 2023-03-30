#include "stdafx.h"
#include "PyDbDatabase.h"
#include "PyDbObjectId.h"

using namespace boost::python;

//---------------------------------------------------------------------------------------------------
// makeAcDbDatabaseWrapper
void makeAcDbDatabaseWrapper()
{
    static auto wrapper = class_<PyDbDatabase, bases<PyRxObject>>("DbDatabase")
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
        .def("getNearestLineWeight", &PyDbDatabase::getNearestLineWeight)//static
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
        .def("isValidLineWeight", &PyDbDatabase::isValidLineWeight)//static
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
        .def("markObjectNonPersistent", &PyDbDatabase::markObjectNonPersistent)//static
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

        .def("className", &PyDbDatabase::className)
        .def("getFilename", &PyDbDatabase::getFilename)
        .def("readDwgFile", &PyDbDatabase::readDwgFile)
        .def("blockTableId", &PyDbDatabase::blockTableId)
        .def("modelspaceId", &PyDbDatabase::modelspaceId)
        .def("currentSpaceId", &PyDbDatabase::currentSpaceId)
        ;
}

//---------------------------------------------------------------------------------------------------
// PyDbDatabase
PyDbDatabase::PyDbDatabase()
    :PyRxObject(nullptr, false)
{
}

PyDbDatabase::PyDbDatabase(AcDbDatabase* _pDb)
    : PyRxObject(_pDb, false)
{
}

PyDbDatabase::PyDbDatabase(AcDbDatabase* _pDb, bool autoDelete)
    : PyRxObject(_pDb, false)
{
}

PyDbDatabase::PyDbDatabase(bool buildDefaultDrawing, bool noDocument)
    : PyRxObject(new AcDbDatabase(buildDefaultDrawing, noDocument), true)
{
}

double PyDbDatabase::angbase() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->angbase();
    throw PyNullObject();
}

bool PyDbDatabase::angdir() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->angdir();
    throw PyNullObject();
}

bool PyDbDatabase::annoAllVisible() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->annoAllVisible();
    throw PyNullObject();
}

bool PyDbDatabase::annotativeDwg() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->annotativeDwg();
    throw PyNullObject();
}

int PyDbDatabase::approxNumObjects() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->approxNumObjects();
    throw PyNullObject();
}

Adesk::Int16 PyDbDatabase::attmode() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->attmode();
    throw PyNullObject();
}

Adesk::Int16 PyDbDatabase::aunits() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->aunits();
    throw PyNullObject();
}

Adesk::Int16 PyDbDatabase::auprec() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->auprec();
    throw PyNullObject();
}

bool PyDbDatabase::blipmode() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->blipmode();
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::byBlockLinetype() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(impObj()->byBlockLinetype());
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::byBlockMaterial() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(impObj()->byBlockMaterial());
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::byLayerLinetype() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(impObj()->byLayerLinetype());
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::byLayerMaterial() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(impObj()->byLayerMaterial());
    throw PyNullObject();
}

bool PyDbDatabase::cameraDisplay() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->cameraDisplay();
    throw PyNullObject();
#endif
}

double PyDbDatabase::cameraHeight() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->cameraHeight();
    throw PyNullObject();
#endif
}

Adesk::Int16 PyDbDatabase::cDynDisplayMode() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->cDynDisplayMode();
    throw PyNullObject();
#endif // BRXAPP
}

double PyDbDatabase::celtscale() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->celtscale();
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::celtype() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(impObj()->celtype());
    throw PyNullObject();
}

AcDb::LineWeight PyDbDatabase::celweight() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->celweight();
    throw PyNullObject();
}

double PyDbDatabase::chamfera() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->chamfera();
    throw PyNullObject();
}

double PyDbDatabase::chamferb() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->chamferb();
    throw PyNullObject();
}

double PyDbDatabase::chamferc() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->chamferc();
    throw PyNullObject();
}

double PyDbDatabase::chamferd() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->chamferd();
    throw PyNullObject();
}

std::string PyDbDatabase::classDxfName(const PyRxClass& pClass)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return wstr_to_utf8(imp->classDxfName(pClass.impObj()));
    throw PyNullObject();
#endif
}

PyDbObjectId PyDbDatabase::clayer() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(impObj()->clayer());
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::closeInput(bool bCloseFile)
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->closeInput(bCloseFile);
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::cmaterial() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(impObj()->cmaterial());
    throw PyNullObject();
}

Adesk::Int16 PyDbDatabase::cmljust() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->cmljust();
    throw PyNullObject();
}

double PyDbDatabase::cmlscale() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->cmlscale();
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::cmlstyleID() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(impObj()->cmlstyleID());
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::colorDictionaryId() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(impObj()->colorDictionaryId());
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::continuousLinetype() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(impObj()->continuousLinetype());
    throw PyNullObject();
}

Adesk::Int16 PyDbDatabase::coords() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->coords();
    throw PyNullObject();
}

Adesk::UInt32 PyDbDatabase::countEmptyObjects(const Adesk::UInt32 flags)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->countEmptyObjects(flags);
    throw PyNullObject();
#endif
}

PyDbObjectId PyDbDatabase::detailViewStyle() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(impObj()->detailViewStyle());
    throw PyNullObject();
#endif
}

PyDbObjectId PyDbDatabase::detailViewStyleDictionaryId() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(impObj()->detailViewStyleDictionaryId());
    throw PyNullObject();
}

bool PyDbDatabase::dimaso() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->dimaso();
    throw PyNullObject();
}

Adesk::UInt8 PyDbDatabase::dimAssoc() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->dimAssoc();
    throw PyNullObject();
}

int PyDbDatabase::dimfit() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->dimfit();
    throw PyNullObject();
}

bool PyDbDatabase::dimsho() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->dimsho();
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::dimstyle() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(impObj()->dimstyle());
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::dimStyleTableId() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(impObj()->dimStyleTableId());
    throw PyNullObject();
}

int PyDbDatabase::dimunit() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->dimunit();
    throw PyNullObject();
}

void PyDbDatabase::disablePartialOpen()
{
    auto imp = impObj();
    if (imp != nullptr)
        impObj()->disablePartialOpen();
    throw PyNullObject();
}

void PyDbDatabase::disableUndoRecording(bool disable)
{
    auto imp = impObj();
    if (imp != nullptr)
        impObj()->disableUndoRecording(disable);
    throw PyNullObject();
}

bool PyDbDatabase::dispSilh() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->dispSilh();
    throw PyNullObject();
}

Adesk::Int16 PyDbDatabase::dragmode() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->dragmode();
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::dragVisStyle() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(impObj()->dragVisStyle());
    throw PyNullObject();
#endif
}

Adesk::UInt8 PyDbDatabase::drawOrderCtl() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->drawOrderCtl();
    throw PyNullObject();
}

Adesk::UInt8 PyDbDatabase::dwfframe() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->dwfframe();
    throw PyNullObject();
}

bool PyDbDatabase::dwgFileWasSavedByAutodeskSoftware() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->dwgFileWasSavedByAutodeskSoftware();
    throw PyNullObject();
#endif
}

Acad::ErrorStatus PyDbDatabase::dxfIn(const std::string& dxfFilename)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->dxfIn(utf8_to_wstr(dxfFilename).c_str());
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::dxfOut(const std::string& dxfFilename)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->dxfOut(utf8_to_wstr(dxfFilename).c_str());
    throw PyNullObject();
}

double PyDbDatabase::elevation() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->elevation();
    throw PyNullObject();
}

Adesk::UInt32 PyDbDatabase::eraseEmptyObjects(const Adesk::UInt32 flags)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->eraseEmptyObjects(flags);
    throw PyNullObject();
#endif
}

AcGePoint3d PyDbDatabase::extmax() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->extmax();
    throw PyNullObject();
}

AcGePoint3d PyDbDatabase::extmin() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->extmin();
    throw PyNullObject();
}

double PyDbDatabase::facetres() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->facetres();
    throw PyNullObject();
}

double PyDbDatabase::filletrad() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->filletrad();
    throw PyNullObject();
}

bool PyDbDatabase::fillmode() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->fillmode();
    throw PyNullObject();
}

void PyDbDatabase::forceWblockDatabaseCopy()
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        impObj()->forceWblockDatabaseCopy();
    throw PyNullObject();
#endif
}

std::string PyDbDatabase::geoCoordinateSystemId() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return wstr_to_utf8(impObj()->geoCoordinateSystemId());
    throw PyNullObject();
#endif
}

bool PyDbDatabase::geoMarkerVisibility() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->geoMarkerVisibility();
    throw PyNullObject();
#endif
}

double PyDbDatabase::get3dDwfPrec() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->get3dDwfPrec();
    throw PyNullObject();
#endif
}

AcDb::PlotStyleNameType PyDbDatabase::getCePlotStyleNameId(PyDbObjectId& id) const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->getCePlotStyleNameId(id.m_id);
    throw PyNullObject();
}

bool PyDbDatabase::isAppRegistered(const std::string& pszAppName) const
{
#ifdef ARX2023
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->isAppRegistered(utf8_to_wstr(pszAppName).c_str());
    throw PyNullObject();
#else
    throw PyNotimplementedByHost();
#endif // 
}

std::string PyDbDatabase::dimapost() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return wstr_to_utf8(impObj()->dimapost());
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::dimblk() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(impObj()->dimblk());
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::dimblk1() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(impObj()->dimblk1());
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::dimblk2() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(impObj()->dimblk2());
    throw PyNullObject();
}

std::string PyDbDatabase::dimpost() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return wstr_to_utf8(impObj()->dimpost());
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::getDimstyleParentId(PyDbObjectId& childStyle) const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(impObj()->getDimstyleParentId(childStyle.m_id));
    throw PyNullObject();
}

AcDb::LineWeight PyDbDatabase::getNearestLineWeight(int weight)
{
    return AcDbDatabase::getNearestLineWeight(weight);
}

boost::python::list PyDbDatabase::getViewportArray() const
{
    AcDbObjectIdArray vportIds;
    boost::python::list pyvportIds;
    auto imp = impObj();
    if (imp != nullptr)
    {
        if (eOk == imp->getViewportArray(vportIds))
        {
            for (auto& item : vportIds)
                pyvportIds.append(PyDbObjectId(item));
        }
    }
    return pyvportIds;
}

boost::python::list PyDbDatabase::getVisualStyleList()
{
    boost::python::list pyvstyleList;
    AcArray<const ACHAR*> vstyleList;
    auto imp = impObj();
    if (imp != nullptr)
    {
        if (eOk == imp->getVisualStyleList(vstyleList))
        {
            for (const auto& item : vstyleList)
                pyvstyleList(wstr_to_utf8(item));
        }
    }
    return pyvstyleList;
}

PyDbObjectId PyDbDatabase::globalMaterial() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(impObj()->globalMaterial());
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::groupDictionaryId() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(impObj()->groupDictionaryId());
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::insert(PyDbObjectId& blockId, const std::string& pBlockName, PyDbDatabase& db, bool preserveSourceDatabase)
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->insert(blockId.m_id, utf8_to_wstr(pBlockName).c_str(), db.impObj(), preserveSourceDatabase);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::insert(PyDbObjectId& blockId, const std::string& pSourceBlockName, const std::string& pDestinationBlockName, PyDbDatabase& db, bool preserveSourceDatabase)
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->insert(blockId.m_id, utf8_to_wstr(pSourceBlockName).c_str(), utf8_to_wstr(pDestinationBlockName).c_str(), db.impObj(), preserveSourceDatabase);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::insert(const AcGeMatrix3d& xform, PyDbDatabase& db, bool preserveSourceDatabase)
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->insert(xform, db.impObj(), preserveSourceDatabase);
    throw PyNullObject();
}

Adesk::UInt8 PyDbDatabase::haloGap() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return imp->haloGap();
    throw PyNullObject();
#endif
}

bool PyDbDatabase::hasClass(const PyRxClass& pClass) const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return imp->hasClass(pClass.impObj());
    throw PyNullObject();
#endif
}

Adesk::UInt8 PyDbDatabase::hideText() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return imp->hideText();
    throw PyNullObject();
#endif
}

bool PyDbDatabase::hpInherit() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->hpInherit();
    throw PyNullObject();
}

AcGePoint2d PyDbDatabase::hpOrigin() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->hpOrigin();
    throw PyNullObject();
}

Adesk::UInt8 PyDbDatabase::indexctl() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return imp->indexctl();
    throw PyNullObject();
#endif
}

AcDb::UnitsValue PyDbDatabase::insunits() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->insunits();
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::interfereVpVisStyle() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(imp->interfereVpVisStyle());
    throw PyNullObject();
#endif
}

Adesk::UInt16 PyDbDatabase::intersectColor() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return imp->intersectDisplay();
    throw PyNullObject();
#endif
}

Adesk::UInt8 PyDbDatabase::intersectDisplay() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return imp->intersectDisplay();
    throw PyNullObject();
#endif
}

bool PyDbDatabase::isBeingDestroyed() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return imp->isBeingDestroyed();
    throw PyNullObject();
#endif
}

bool PyDbDatabase::isEMR() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->isEMR();
    throw PyNullObject();
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
    auto imp = impObj();
    if (imp != nullptr)
        return imp->isolines();
    throw PyNullObject();
}

bool PyDbDatabase::isPartiallyOpened() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->isPartiallyOpened();
    throw PyNullObject();
}

bool PyDbDatabase::isPucsOrthographic(AcDb::OrthographicView& orthoView) const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->isPucsOrthographic(orthoView);
    throw PyNullObject();
}

bool PyDbDatabase::isUcsOrthographic(AcDb::OrthographicView& orthoView) const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->isUcsOrthographic(orthoView);
    throw PyNullObject();
}

bool PyDbDatabase::isValidLineWeight(int weight)
{
    return AcDbDatabase::isValidLineWeight(weight);
}

AcDb::JoinStyle PyDbDatabase::joinStyle() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->joinStyle();
    throw PyNullObject();
}

int PyDbDatabase::lastSavedAsMaintenanceVersion() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->lastSavedAsMaintenanceVersion();
    throw PyNullObject();
}

int PyDbDatabase::lastSavedAsVersion() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->lastSavedAsVersion();
    throw PyNullObject();
}

double PyDbDatabase::latitude() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->latitude();
    throw PyNullObject();
}

Adesk::UInt8 PyDbDatabase::layerEval() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return imp->layerEval();
    throw PyNullObject();
#endif
}

Adesk::Int16 PyDbDatabase::layerNotify() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return imp->layerNotify();
    throw PyNullObject();
#endif
}

PyDbObjectId PyDbDatabase::layerTableId() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(imp->layerTableId());
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::layerZero() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(imp->layerZero());
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::layoutDictionaryId() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(imp->layoutDictionaryId());
    throw PyNullObject();
}

double PyDbDatabase::lensLength() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return imp->lensLength();
    throw PyNullObject();
#endif
}

Adesk::UInt8 PyDbDatabase::lightGlyphDisplay() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return imp->lightGlyphDisplay();
    throw PyNullObject();
#endif
}

Adesk::UInt8 PyDbDatabase::lightingUnits() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return imp->lightingUnits();
    throw PyNullObject();
#endif
}

bool PyDbDatabase::lightsInBlocks() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return imp->lightsInBlocks();
    throw PyNullObject();
#endif
}

bool PyDbDatabase::limcheck() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->limcheck();
    throw PyNullObject();
}

AcGePoint2d PyDbDatabase::limmax() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->limmax();
    throw PyNullObject();
}

AcGePoint2d PyDbDatabase::limmin() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->limmin();
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::linetypeTableId() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(imp->linetypeTableId());
    throw PyNullObject();
}

bool PyDbDatabase::lineWeightDisplay() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->lineWeightDisplay();
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::loadLineTypeFile(const std::string& ltn, const std::string& filename)
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->loadLineTypeFile(utf8_to_wstr(ltn).c_str(), utf8_to_wstr(filename).c_str());
    throw PyNullObject();
}

double PyDbDatabase::loftAng1() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->loftAng1();
    throw PyNullObject();
}

double PyDbDatabase::loftAng2() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->loftAng2();
    throw PyNullObject();
}

double PyDbDatabase::loftMag1() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->loftMag1();
    throw PyNullObject();
}

double PyDbDatabase::loftMag2() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->loftMag2();
    throw PyNullObject();
}

Adesk::UInt8 PyDbDatabase::loftNormals() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->loftNormals();
    throw PyNullObject();
}

Adesk::UInt16 PyDbDatabase::loftParam() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->loftParam();
    throw PyNullObject();
}

double PyDbDatabase::longitude() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->longitude();
    throw PyNullObject();
}

double PyDbDatabase::ltscale() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->ltscale();
    throw PyNullObject();
}

Adesk::Int16 PyDbDatabase::lunits() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->lunits();
    throw PyNullObject();
}

Adesk::Int16 PyDbDatabase::luprec() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->luprec();
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::registerApp(const std::string& pszAppName)
{
#ifdef ARX2023
    auto imp = impObj();
    if (imp != nullptr)
        return imp->registerApp(utf8_to_wstr(pszAppName).c_str());
#else
    throw PyNotimplementedByHost();
#endif
}

int PyDbDatabase::maintenanceReleaseVersion() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return imp->maintenanceReleaseVersion();
    throw PyNullObject();
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
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(imp->materialDictionaryId());
    throw PyNullObject();
}

Adesk::Int16 PyDbDatabase::maxactvp() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->maxactvp();
    throw PyNullObject();
}

AcDb::MeasurementValue PyDbDatabase::measurement() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->measurement();
    throw PyNullObject();
}

bool PyDbDatabase::mirrtext() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->mirrtext();
    throw PyNullObject();
}

double PyDbDatabase::mleaderscale() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->mleaderscale();
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::mleaderstyle() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(imp->mleaderstyle());
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::mleaderStyleDictionaryId() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(imp->mleaderStyleDictionaryId());
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::mLStyleDictionaryId() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(imp->mLStyleDictionaryId());
    throw PyNullObject();
}

bool PyDbDatabase::msltscale() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->msltscale();
    throw PyNullObject();
}

double PyDbDatabase::msOleScale() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return imp->msOleScale();
    throw PyNullObject();
#endif
}

PyDbObjectId PyDbDatabase::namedObjectsDictionaryId() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(imp->namedObjectsDictionaryId());
    throw PyNullObject();
}

bool PyDbDatabase::needsRecovery() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return imp->needsRecovery();
    throw PyNullObject();
#endif
}

double PyDbDatabase::northDirection() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->northDirection();
    throw PyNullObject();
}

Adesk::Int32 PyDbDatabase::numberOfSaves() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->numberOfSaves();
    throw PyNullObject();
}

Adesk::UInt16 PyDbDatabase::obscuredColor() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return imp->obscuredColor();
    throw PyNullObject();
#endif
}

Adesk::UInt8 PyDbDatabase::obscuredLineType() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return imp->obscuredLineType();
    throw PyNullObject();
#endif
}

bool PyDbDatabase::oleStartUp() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->oleStartUp();
    throw PyNullObject();
}

int PyDbDatabase::originalFileMaintenanceVersion() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->originalFileMaintenanceVersion();
    throw PyNullObject();
}

std::string PyDbDatabase::originalFileName() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return wstr_to_utf8(imp->originalFileName());
    throw PyNullObject();
}

int PyDbDatabase::originalFileSavedByMaintenanceVersion() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->originalFileSavedByMaintenanceVersion();
    throw PyNullObject();
}

int PyDbDatabase::originalFileSavedByVersion() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->originalFileSavedByVersion();
    throw PyNullObject();
}

int PyDbDatabase::originalFileVersion() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->originalFileVersion();
    throw PyNullObject();
}

bool PyDbDatabase::orthomode() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->orthomode();
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::paperSpaceVportId() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(imp->paperSpaceVportId());
    throw PyNullObject();
}

Adesk::Int8 PyDbDatabase::pdfframe() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return imp->pdfframe();
    throw PyNullObject();
#endif
}

Adesk::Int16 PyDbDatabase::pdmode() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->pdmode();
    throw PyNullObject();
}

double PyDbDatabase::pdsize() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->pdsize();
    throw PyNullObject();
}

double PyDbDatabase::pelevation() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->pelevation();
    throw PyNullObject();
}

AcGePoint3d PyDbDatabase::pextmax() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->pextmax();
    throw PyNullObject();
}

AcGePoint3d PyDbDatabase::pextmin() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->pextmin();
    throw PyNullObject();
}

Adesk::Int16 PyDbDatabase::pickstyle() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->pickstyle();
    throw PyNullObject();
}

AcGePoint3d PyDbDatabase::pinsbase() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->pinsbase();
    throw PyNullObject();
}

bool PyDbDatabase::plimcheck() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->plimcheck();
    throw PyNullObject();
}

AcGePoint2d PyDbDatabase::plimmax() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->plimmax();
    throw PyNullObject();
}

AcGePoint2d PyDbDatabase::plimmin() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->plimmin();
    throw PyNullObject();
}

bool PyDbDatabase::plineEllipse() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->plineEllipse();
    throw PyNullObject();
}

bool PyDbDatabase::plinegen() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->plinegen();
    throw PyNullObject();
}

double PyDbDatabase::plinewid() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->plinewid();
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::plotSettingsDictionaryId() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(imp->plotSettingsDictionaryId());
    throw PyNullObject();
}

bool PyDbDatabase::plotStyleMode() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->plotStyleMode();
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::plotStyleNameDictionaryId() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(imp->plotStyleNameDictionaryId());
    throw PyNullObject();
}

Adesk::Int16 PyDbDatabase::previewType() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->previewType();
    throw PyNullObject();
#endif
}

bool PyDbDatabase::psltscale() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->psltscale();
    throw PyNullObject();
}

double PyDbDatabase::psolHeight() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->psolHeight();
    throw PyNullObject();
#endif
}

double PyDbDatabase::psolWidth() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->psolWidth();
    throw PyNullObject();
#endif
}

PyDbObjectId PyDbDatabase::pucsBase() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(imp->pucsBase());
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::pucsname() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(imp->pucsname());
    throw PyNullObject();
}

AcGePoint3d PyDbDatabase::pucsorg() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->pucsorg();
    throw PyNullObject();
}

AcGeVector3d PyDbDatabase::pucsxdir() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->pucsxdir();
    throw PyNullObject();
}

AcGeVector3d PyDbDatabase::pucsydir() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->pucsydir();
    throw PyNullObject();
}

bool PyDbDatabase::qtextmode() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->qtextmode();
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::reclaimMemoryFromErasedObjects(const boost::python::list& erasedObjects)
{
    const auto PyDbObjectIds = py_list_to_std_vector<PyDbObjectId>(erasedObjects);
    AcDbObjectIdArray ids;
    for (const auto& pyId : PyDbObjectIds)
        ids.append(pyId.m_id);
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->reclaimMemoryFromErasedObjects(ids);
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::regAppTableId() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(imp->regAppTableId());
    throw PyNullObject();
}

bool PyDbDatabase::regenmode() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->regenmode();
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::resetTimes()
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return imp->resetTimes();
    throw PyNullObject();
#endif
}

Acad::ErrorStatus PyDbDatabase::restoreForwardingXrefSymbols()
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->restoreForwardingXrefSymbols();
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::restoreOriginalXrefSymbols()
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->restoreOriginalXrefSymbols();
    throw PyNullObject();
}


bool PyDbDatabase::retainOriginalThumbnailBitmap() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->retainOriginalThumbnailBitmap();
    throw PyNullObject();
}

Adesk::Int16 PyDbDatabase::saveproxygraphics() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->saveproxygraphics();
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::scaleListDictionaryId() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(imp->scaleListDictionaryId());
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::sectionViewStyle() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(imp->sectionViewStyle());
    throw PyNullObject();
#endif
}

PyDbObjectId PyDbDatabase::sectionViewStyleDictionaryId() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(imp->sectionViewStyleDictionaryId());
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::set3dDwfPrec(double DwfPrec)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return imp->set3dDwfPrec(DwfPrec);
    throw PyNullObject();
#endif
}

Acad::ErrorStatus PyDbDatabase::setAngbase(double angle)
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->setAngbase(angle);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setAngdir(bool dir)
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->setAngdir(dir);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setAnnoAllVisible(bool allvis)
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->setAnnoAllVisible(allvis);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setAttdia(bool dia)
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->setAttdia(dia);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setAttmode(Adesk::Int16 mode)
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->setAttmode(mode);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setAttreq(bool req)
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->setAttreq(req);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setAunits(Adesk::Int16 aunits)
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->setAunits(aunits);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setAuprec(Adesk::Int16 auprec)
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->setAuprec(auprec);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setBlipmode(bool mode)
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->setBlipmode(mode);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setCameraDisplay(bool cameraDisplay)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return imp->setCameraDisplay(cameraDisplay);
    throw PyNullObject();
#endif
}

Acad::ErrorStatus PyDbDatabase::setCameraHeight(double cameraHeight)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return imp->setCameraHeight(cameraHeight);
    throw PyNullObject();
#endif
}

Acad::ErrorStatus PyDbDatabase::setCDynDisplayMode(Adesk::Int16 val)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return imp->setCDynDisplayMode(val);
    throw PyNullObject();
#endif
}

Acad::ErrorStatus PyDbDatabase::setCeltscale(double scale)
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->setCeltscale(scale);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setCeltype(const PyDbObjectId& id)
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->setCeltype(id.m_id);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setCelweight(AcDb::LineWeight weight)
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->setCelweight(weight);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setCePlotStyleName(AcDb::PlotStyleNameType type, const PyDbObjectId& id)
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->setCePlotStyleName(type, id.m_id);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setChamfera(double val)
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->setChamfera(val);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setChamferb(double val)
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->setChamferb(val);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setChamferc(double val)
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->setChamferc(val);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setChamferd(double val)
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->setChamferd(val);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setClayer(const PyDbObjectId& id)
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->setClayer(id.m_id);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setCmaterial(const PyDbObjectId& id)
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->setCmaterial(id.m_id);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setCmljust(Adesk::Int16 just)
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->setCmljust(just);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setCmlscale(double scale)
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->setCmlscale(scale);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setCmlstyleID(const PyDbObjectId& id)
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->setCmlstyleID(id.m_id);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setCoords(Adesk::Int16 _coords)
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->setCoords(_coords);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setCshadow(Adesk::UInt8 val)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return imp->setCshadow(val);
    throw PyNullObject();
#endif
}

Acad::ErrorStatus PyDbDatabase::setDelUsedObj(Adesk::Int16 deleteObj)
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->setDelUsedObj(deleteObj);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setDgnframe(Adesk::UInt8 val)
{
#ifdef ARXAPP
    auto imp = impObj();
    if (imp != nullptr)
        return imp->setDgnframe(val);
    throw PyNullObject();
#else
    throw PyNotimplementedByHost();
#endif
}

Acad::ErrorStatus PyDbDatabase::setDimaso(bool aso)
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->setDimaso(aso);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setDimAssoc(Adesk::UInt8 val)
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->setDimAssoc(val);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setDimfit(int fit)
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->setDimfit(fit);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setDimsho(bool sho)
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->setDimsho(sho);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setDimstyle(const PyDbObjectId& id)
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->setDimstyle(id.m_id);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setDimstyleData(const PyDbObjectId& id)
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->setDimstyleData(id.m_id);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setDimunit(int unit)
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->setDimunit(unit);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setDispSilh(bool silh)
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->setDispSilh(silh);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setDragmode(Adesk::Int16 mode)
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->setDragmode(mode);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setDragVisStyle(const PyDbObjectId& id)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return imp->setDragVisStyle(id.m_id);
    throw PyNullObject();
#endif
}

Acad::ErrorStatus PyDbDatabase::setDrawOrderCtl(Adesk::UInt8 val)
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->setDrawOrderCtl(val);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setDwfframe(Adesk::UInt8 val)
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->setDwfframe(val);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setElevation(double elev)
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->setElevation(elev);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setEndCaps(AcDb::EndCaps type)
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->setEndCaps(type);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setExtmax(const AcGePoint3d& max)
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->setExtmax(max);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setExtmin(const AcGePoint3d& min)
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->setExtmin(min);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setFacetres(double _facetres)
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->setFacetres(_facetres);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setFilletrad(double radius)
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->setFilletrad(radius);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setFillmode(bool mode)
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->setFillmode(mode);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::saveAs(const std::string& fileName)
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->saveAs(utf8_to_wstr(fileName).c_str());
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setFingerprintGuid(const std::string& newGuid)
{
    auto imp = impObj();
    if (imp != nullptr)
        imp->setFingerprintGuid(utf8_to_wstr(newGuid).c_str());
    throw PyNullObject();
}

void PyDbDatabase::setFullSaveRequired()
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        imp->setFullSaveRequired();
    throw PyNullObject();
#endif
}

Acad::ErrorStatus PyDbDatabase::readDwgFile(const char* fileName)
{
    std::wstring wsfileName{ utf8_to_wstr(fileName) };
    auto imp = impObj();
    if (imp != nullptr)
        return imp->readDwgFile(wsfileName.c_str());
    return eNullPtr;
}

std::string PyDbDatabase::getFilename()
{
    auto imp = impObj();
    if (imp != nullptr)
    {
        const TCHAR* path = nullptr;
        if (imp->getFilename(path) == eOk && path != nullptr)
            return std::string{ wstr_to_utf8(path) };
    }
    return std::string{ };
}

PyDbObjectId PyDbDatabase::currentSpaceId() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(impObj()->currentSpaceId());
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::blockTableId() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(impObj()->blockTableId());
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::modelspaceId() const
{
    return PyDbObjectId(acdbSymUtil()->blockModelSpaceId(impObj()));
}

Acad::ErrorStatus PyDbDatabase::setGeoMarkerVisibility(bool value)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setGeoMarkerVisibility(value);
    throw PyNullObject();
#endif
}

Acad::ErrorStatus PyDbDatabase::setHaloGap(Adesk::UInt8 val)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setHaloGap(val);
    throw PyNullObject();
#endif
}

Acad::ErrorStatus PyDbDatabase::setHideText(Adesk::UInt8 val)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setHideText(val);
    throw PyNullObject();
#endif
}

Acad::ErrorStatus PyDbDatabase::setHpInherit(const bool inherit)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setHpInherit(inherit);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setHpOrigin(const AcGePoint2d& origin)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setHpOrigin(origin);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setHyperlinkBase(const std::string& val)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setHyperlinkBase(utf8_to_wstr(val).c_str());
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setIndexctl(Adesk::UInt8 val)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setIndexctl(val);
    throw PyNullObject();
#endif
}

Acad::ErrorStatus PyDbDatabase::setInsbase(const AcGePoint3d& base)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setInsbase(base);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setInsunits(const AcDb::UnitsValue units)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setInsunits(units);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setInterfereObjVisStyle(const PyDbObjectId& id)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setInterfereObjVisStyle(id.m_id);
    throw PyNullObject();
#endif
}

Acad::ErrorStatus PyDbDatabase::setInterfereVpVisStyle(const PyDbObjectId& id)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setInterfereVpVisStyle(id.m_id);
    throw PyNullObject();
#endif
}

Acad::ErrorStatus PyDbDatabase::setIntersectColor(Adesk::UInt16 val)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setIntersectColor(val);
    throw PyNullObject();
#endif
}

Acad::ErrorStatus PyDbDatabase::setIntersectDisplay(Adesk::UInt8 val)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setIntersectDisplay(val);
    throw PyNullObject();
#endif
}

Acad::ErrorStatus PyDbDatabase::setIsolines(Adesk::Int16 isolines)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setIsolines(isolines);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setJoinStyle(AcDb::JoinStyle style)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setJoinStyle(style);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setLatitude(double lat)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setLatitude(lat);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setLayerEval(Adesk::UInt8 val)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setLayerEval(val);
    throw PyNullObject();
#endif
}

Acad::ErrorStatus PyDbDatabase::setLayerNotify(Adesk::Int16 val)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setLayerNotify(val);
    throw PyNullObject();
#endif
}

Acad::ErrorStatus PyDbDatabase::setLensLength(const double _lensLength)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setLensLength(_lensLength);
    throw PyNullObject();
#endif
}

Acad::ErrorStatus PyDbDatabase::setLightGlyphDisplay(Adesk::UInt8 val)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setLightGlyphDisplay(val);
    throw PyNullObject();
#endif
}

Acad::ErrorStatus PyDbDatabase::setLightingUnits(Adesk::UInt8 val)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setLightingUnits(val);
    throw PyNullObject();
#endif
}

Acad::ErrorStatus PyDbDatabase::setLightsInBlocks(bool val)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setLightsInBlocks(val);
    throw PyNullObject();
#endif
}

Acad::ErrorStatus PyDbDatabase::setLimcheck(bool check)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setLimcheck(check);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setLimmax(const AcGePoint2d& max)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setLimmax(max);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setLimmin(const AcGePoint2d& min)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setLimmin(min);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setLineWeightDisplay(bool display)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setLineWeightDisplay(display);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setLoftAng1(double ang1)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setLoftAng1(ang1);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setLoftAng2(double ang2)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setLoftAng2(ang2);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setLoftMag1(double mag1)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setLoftMag1(mag1);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setLoftMag2(double mag2)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setLoftMag2(mag2);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setLoftNormals(Adesk::UInt8 value)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setLoftNormals(value);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setLoftParam(Adesk::UInt16 flags)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setLoftParam(flags);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setLongitude(double lng)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setLongitude(lng);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setLtscale(double scale)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setLtscale(scale);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setLunits(Adesk::Int16 lunits)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setLunits(lunits);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setLuprec(Adesk::Int16 prec)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setLuprec(prec);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setMaxactvp(Adesk::Int16 max)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setMaxactvp(max);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setMeasurement(AcDb::MeasurementValue type)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setMeasurement(type);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setMirrtext(bool mirror)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setMirrtext(mirror);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setMLeaderscale(double scale)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setMLeaderscale(scale);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setMLeaderstyle(const PyDbObjectId& objId)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setMLeaderstyle(objId.m_id);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setMsltscale(bool val)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setMsltscale(val);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setMsOleScale(double val)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setMsOleScale(val);
    throw PyNullObject();
#endif
}

Acad::ErrorStatus PyDbDatabase::setNorthDirection(double northdir)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setNorthDirection(northdir);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setObscuredColor(Adesk::UInt16 val)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setObscuredColor(val);
    throw PyNullObject();
#endif
}

Acad::ErrorStatus PyDbDatabase::setObscuredLineType(Adesk::UInt8 val)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setObscuredLineType(val);
    throw PyNullObject();
#endif
}

Acad::ErrorStatus PyDbDatabase::setOleStartUp(bool val)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setOleStartUp(val);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setOrthomode(bool mode)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setOrthomode(mode);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setPdfframe(Adesk::Int8 val)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setPdfframe(val);
    throw PyNullObject();
#endif
}

Acad::ErrorStatus PyDbDatabase::setPdmode(Adesk::Int16 mode)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setPdmode(mode);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setPdsize(double size)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setPdsize(size);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setPelevation(double elev)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setPelevation(elev);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setPextmax(const AcGePoint3d& max)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setPextmax(max);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setPextmin(const AcGePoint3d& min)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setPextmin(min);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setPickstyle(Adesk::Int16 style)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setPickstyle(style);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setPinsbase(const AcGePoint3d& base)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setPinsbase(base);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setPlimcheck(bool check)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setPlimcheck(check);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setPlimmax(const AcGePoint2d& max)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setPlimmax(max);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setPlimmin(const AcGePoint2d& min)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setPlimmin(min);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setPlineEllipse(bool pline)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setPlineEllipse(pline);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setPlinegen(bool gen)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setPlinegen(gen);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setPlinewid(double width)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setPlinewid(width);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setPreviewType(Adesk::Int16 val)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setPreviewType(val);
    throw PyNullObject();
#endif
}

Acad::ErrorStatus PyDbDatabase::setProjectName(const std::string& val)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setProjectName(utf8_to_wstr(val).c_str());
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setPsltscale(bool scale)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setPsltscale(scale);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setPsolHeight(double height)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setPsolHeight(height);
    throw PyNullObject();
#endif
}

Acad::ErrorStatus PyDbDatabase::setPsolWidth(double width)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setPsolWidth(width);
    throw PyNullObject();
#endif
}

Acad::ErrorStatus PyDbDatabase::setPucs(const AcGePoint3d& ucsOrigin, const AcGeVector3d& ucsXDir, const AcGeVector3d& ucsYDir)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setPucs(ucsOrigin, ucsXDir, ucsYDir);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setPucsBase(const PyDbObjectId& ucsid)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setPucsBase(ucsid.m_id);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setPucsname(const PyDbObjectId& ucsRecId)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setPucsname(ucsRecId.m_id);
    throw PyNullObject();
#endif
}

Acad::ErrorStatus PyDbDatabase::setQtextmode(bool mode)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setQtextmode(mode);
    throw PyNullObject();
#endif
}

Acad::ErrorStatus PyDbDatabase::setRealWorldScale(const bool realWorldScale)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setRealWorldScale(realWorldScale);
    throw PyNullObject();
#endif
}

Acad::ErrorStatus PyDbDatabase::setRegenmode(bool mode)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setRegenmode(mode);
    throw PyNullObject();
}

void PyDbDatabase::setRetainOriginalThumbnailBitmap(bool retain)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setRetainOriginalThumbnailBitmap(retain);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setSaveproxygraphics(Adesk::Int16 saveimg)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setSaveproxygraphics(saveimg);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setSectionViewStyle(const PyDbObjectId& objId)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setSectionViewStyle(objId.m_id);
    throw PyNullObject();
#endif
}

Acad::ErrorStatus PyDbDatabase::setShadedge(Adesk::Int16 mode)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setShadedge(mode);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setShadedif(Adesk::Int16 dif)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setShadedif(dif);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setShadowPlaneLocation(double val)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setShadowPlaneLocation(val);
    throw PyNullObject();
#endif
}

Acad::ErrorStatus PyDbDatabase::setShowHist(Adesk::UInt8 val)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setShowHist(val);
    throw PyNullObject();
#endif
}

Acad::ErrorStatus PyDbDatabase::setSketchinc(double inc)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setSketchinc(inc);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setSkpoly(bool asPoly)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setSkpoly(asPoly);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setSolidHist(Adesk::UInt8 val)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setSolidHist(val);
    throw PyNullObject();
#endif
}

Acad::ErrorStatus PyDbDatabase::setSortEnts(Adesk::UInt8 sortEnts)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setSortEnts(sortEnts);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setSplframe(bool disp)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setSplframe(disp);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setSplinesegs(Adesk::Int16 segs)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setSplinesegs(segs);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setSplinetype(Adesk::Int16 type)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setSplinetype(type);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setStepSize(double stepSize)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setStepSize(stepSize);
    throw PyNullObject();
#endif
}

Acad::ErrorStatus PyDbDatabase::setStepsPerSec(double stepsPerSec)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setStepsPerSec(stepsPerSec);
    throw PyNullObject();
#endif
}

Acad::ErrorStatus PyDbDatabase::setStyleSheet(const std::string& val)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setStyleSheet(utf8_to_wstr(val).c_str());
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setSurftab1(Adesk::Int16 tab1)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setSurftab1(tab1);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setSurftab2(Adesk::Int16 tab2)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setSurftab2(tab2);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setSurftype(Adesk::Int16 type)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setSurftype(type);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setSurfu(Adesk::Int16 v)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setSurfu(v);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setSurfv(Adesk::Int16 v)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setSurfv(v);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setTablestyle(const PyDbObjectId& objId)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setTablestyle(objId.m_id);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setTextsize(double size)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setTextsize(size);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setTextstyle(const PyDbObjectId& objId)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setTextstyle(objId.m_id);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setThickness(double thickness)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setThickness(thickness);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setTilemode(bool mode)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setTilemode(mode);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setTimeZone(AcDb::TimeZone tz)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setTimeZone(tz);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setTimeZoneAsUtcOffset(double offset)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setTimeZoneAsUtcOffset(offset);
    throw PyNullObject();
#endif
}

Acad::ErrorStatus PyDbDatabase::setTracewid(double width)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setTracewid(width);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setTreedepth(Adesk::Int16 depth)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setTreedepth(depth);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setTStackAlign(int val)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setTStackAlign(val);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setTStackSize(int val)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setTStackSize(val);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setUcs(const AcGePoint3d& ucsOrigin, const AcGeVector3d& ucsXDir, const AcGeVector3d& ucsYDir)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setUcs(ucsOrigin, ucsXDir, ucsYDir);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setUcsBase(const PyDbObjectId& ucsid)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setUcsBase(ucsid.m_id);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setUcsname(const PyDbObjectId& ucsRecId)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setUcsname(ucsRecId.m_id);
    throw PyNullObject();
#endif
}

Acad::ErrorStatus PyDbDatabase::setUnitmode(Adesk::Int16 mode)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setUnitmode(mode);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setUpdateThumbnail(Adesk::UInt8 val)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setUpdateThumbnail(val);
    throw PyNullObject();
#endif
}

Acad::ErrorStatus PyDbDatabase::setUseri1(Adesk::Int16 val)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setUseri1(val);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setUseri2(Adesk::Int16 val)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setUseri2(val);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setUseri3(Adesk::Int16 val)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setUseri3(val);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setUseri4(Adesk::Int16 val)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setUseri4(val);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setUseri5(Adesk::Int16 val)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setUseri5(val);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setUserr1(double val)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setUserr1(val);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setUserr2(double val)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setUserr2(val);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setUserr3(double val)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setUserr3(val);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setUserr4(double val)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setUserr4(val);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setUserr5(double val)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setUserr5(val);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setUsrtimer(bool timer)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setUsrtimer(timer);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setVersionGuid(const std::string& pNewGuid)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setVersionGuid(utf8_to_wstr(pNewGuid).c_str());
    throw PyNullObject();
#endif
}

Acad::ErrorStatus PyDbDatabase::setViewportScaleDefault(double newDefaultVPScale)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setVisretain(newDefaultVPScale);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setVisretain(bool retain)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setVisretain(retain);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setWorldPucsBaseOrigin(const AcGePoint3d& origin, AcDb::OrthographicView orthoView)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setWorldPucsBaseOrigin(origin, orthoView);
    throw PyNullObject();
#endif
}

Acad::ErrorStatus PyDbDatabase::setWorldUcsBaseOrigin(const AcGePoint3d& origin, AcDb::OrthographicView orthoView)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setWorldUcsBaseOrigin(origin, orthoView);
    throw PyNullObject();
#endif
}

Acad::ErrorStatus PyDbDatabase::setWorldview(bool view)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setWorldview(view);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setXclipFrame(Adesk::UInt8 disp)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setXclipFrame(disp);
    throw PyNullObject();
#endif
}

Acad::ErrorStatus PyDbDatabase::setXrefEditEnabled(bool enable)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setXrefEditEnabled(enable);
    throw PyNullObject();
}

Adesk::Int16 PyDbDatabase::shadedge() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->shadedge();
    throw PyNullObject();
}

Adesk::Int16 PyDbDatabase::shadedif() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->shadedif();
    throw PyNullObject();
}

double PyDbDatabase::shadowPlaneLocation() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->shadowPlaneLocation();
    throw PyNullObject();
#endif
}

Adesk::UInt8 PyDbDatabase::showHist() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->showHist();
    throw PyNullObject();
#endif
}

double PyDbDatabase::sketchinc() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->sketchinc();
    throw PyNullObject();
}

bool PyDbDatabase::skpoly() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->skpoly();
    throw PyNullObject();
}

Adesk::UInt8 PyDbDatabase::solidHist() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->solidHist();
    throw PyNullObject();
#endif
}

Adesk::UInt8 PyDbDatabase::sortEnts() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->splframe();
    throw PyNullObject();
}

bool PyDbDatabase::splframe() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->splframe();
    throw PyNullObject();
}

Adesk::Int16 PyDbDatabase::splinesegs() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->splinesegs();
    throw PyNullObject();
}

Adesk::Int16 PyDbDatabase::splinetype() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->splinetype();
    throw PyNullObject();
}

double PyDbDatabase::stepSize() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->stepSize();
    throw PyNullObject();
#endif
}

double PyDbDatabase::stepsPerSec() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->stepsPerSec();
    throw PyNullObject();
#endif
}

Adesk::Int16 PyDbDatabase::surftab1() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->surftab1();
    throw PyNullObject();
}

Adesk::Int16 PyDbDatabase::surftab2() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->surftab2();
    throw PyNullObject();
}

Adesk::Int16 PyDbDatabase::surftype() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->surftype();
    throw PyNullObject();
}

Adesk::Int16 PyDbDatabase::surfu() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->surfu();
    throw PyNullObject();
}

Adesk::Int16 PyDbDatabase::surfv() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->surfv();
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::tablestyle() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(impObj()->tablestyle());
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::tableStyleDictionaryId() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(impObj()->tableStyleDictionaryId());
    throw PyNullObject();
}

double PyDbDatabase::textsize() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->textsize();
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::textstyle() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(impObj()->textstyle());
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::textStyleTableId() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(impObj()->textStyleTableId());
    throw PyNullObject();
}

double PyDbDatabase::thickness() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->thickness();
    throw PyNullObject();
}

bool PyDbDatabase::tilemode() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->tilemode();
    throw PyNullObject();
}

Adesk::UInt8 PyDbDatabase::tileModeLightSynch() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->tileModeLightSynch();
    throw PyNullObject();
#endif
}

int PyDbDatabase::timeZone() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->timeZone();
    throw PyNullObject();
}

double PyDbDatabase::tracewid() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->tracewid();
    throw PyNullObject();
}

Adesk::Int16 PyDbDatabase::treedepth() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->treedepth();
    throw PyNullObject();
}

int PyDbDatabase::tstackalign() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->tstackalign();
    throw PyNullObject();
}

int PyDbDatabase::tstacksize() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->tstacksize();
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::ucsBase() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(impObj()->ucsBase());
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::ucsname() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(impObj()->ucsname());
    throw PyNullObject();
}

AcGePoint3d PyDbDatabase::ucsorg() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->ucsorg();
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::UCSTableId() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(impObj()->UCSTableId());
    throw PyNullObject();
}

AcGeVector3d PyDbDatabase::ucsxdir() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->ucsxdir();
    throw PyNullObject();
}

AcGeVector3d PyDbDatabase::ucsydir() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->ucsydir();
    throw PyNullObject();
}

bool PyDbDatabase::undoRecording() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->undoRecording();
    throw PyNullObject();
}

Adesk::Int16 PyDbDatabase::unitmode() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->unitmode();
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::updateDataLink(AcDb::UpdateDirection nDir, AcDb::UpdateOption nOption)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->updateDataLink(nDir, nOption);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::updateExt(bool doBestFit)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->updateExt(doBestFit);
    throw PyNullObject();
}

Adesk::UInt8 PyDbDatabase::updateThumbnail() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->updateThumbnail();
    throw PyNullObject();
#endif
}

Adesk::Int16 PyDbDatabase::useri1() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->useri1();
    throw PyNullObject();
}

Adesk::Int16 PyDbDatabase::useri2() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->useri2();
    throw PyNullObject();
}

Adesk::Int16 PyDbDatabase::useri3() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->useri3();
    throw PyNullObject();
}

Adesk::Int16 PyDbDatabase::useri4() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->userr4();
    throw PyNullObject();
}

Adesk::Int16 PyDbDatabase::useri5() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->userr5();
    throw PyNullObject();
}

double PyDbDatabase::userr1() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->userr1();
    throw PyNullObject();
}

double PyDbDatabase::userr2() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->userr2();
    throw PyNullObject();
}

double PyDbDatabase::userr3() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->userr3();
    throw PyNullObject();
}

double PyDbDatabase::userr4() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->userr4();
    throw PyNullObject();
}

double PyDbDatabase::userr5() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->userr5();
    throw PyNullObject();
}

bool PyDbDatabase::usrtimer() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->usrtimer();
    throw PyNullObject();
}

double PyDbDatabase::viewportScaleDefault() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->viewportScaleDefault();
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::viewportTableId() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(impObj()->viewportTableId());
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::viewTableId() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(impObj()->viewTableId());
    throw PyNullObject();
}

bool PyDbDatabase::visretain() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->visretain();
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::visualStyleDictionaryId() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(impObj()->visualStyleDictionaryId());
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::wblock(PyDbDatabase& pOutputDb)
{
    auto imp = impObj();
    if (imp != nullptr)
    {
        AcDbDatabase* _pOutputDb = nullptr;
        auto stat = impObj()->wblock(_pOutputDb);
        if (stat == eOk && _pOutputDb != nullptr)
            pOutputDb = PyDbDatabase(_pOutputDb, true);
        return stat;
    }
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::wblock(PyDbDatabase& pOutputDb, const PyDbObjectId& blockId)
{
    auto imp = impObj();
    if (imp != nullptr)
    {
        AcDbDatabase* _pOutputDb = nullptr;
        auto stat = impObj()->wblock(_pOutputDb, blockId.m_id);
        if (stat == eOk && _pOutputDb != nullptr)
            pOutputDb = PyDbDatabase(_pOutputDb, true);
        return stat;
    }
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::wblock(PyDbDatabase& pOutputDb, const boost::python::list& outObjIds, const AcGePoint3d& basePoint)
{
    auto imp = impObj();
    if (imp != nullptr)
    {
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
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::wblock(PyDbDatabase& pOutputDb, const boost::python::list& outObjIds, const AcGePoint3d& basePoint, AcDb::DuplicateRecordCloning drc)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
    {
        //TODO: maybe we can do better
        const auto PyDbObjectIds = py_list_to_std_vector<PyDbObjectId>(outObjIds);
        AcDbObjectIdArray ids;
        for (const auto& pyId : PyDbObjectIds)
            ids.append(pyId.m_id);

        AcDbDatabase* pDb = pOutputDb.impObj();
        return impObj()->wblock(pDb, ids, basePoint, drc);
    }
    throw PyNullObject();
#endif
}

AcGePoint3d PyDbDatabase::worldPucsBaseOrigin(AcDb::OrthographicView orthoView) const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->worldPucsBaseOrigin(orthoView);
    throw PyNullObject();
#endif
}

AcGePoint3d PyDbDatabase::worldUcsBaseOrigin(AcDb::OrthographicView orthoView) const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->worldUcsBaseOrigin(orthoView);
    throw PyNullObject();
#endif
}

bool PyDbDatabase::worldview() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->worldview();
    throw PyNullObject();
}

Adesk::UInt8 PyDbDatabase::xclipFrame() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->xclipFrame();
    throw PyNullObject();
#endif
}

PyDbObjectId PyDbDatabase::xrefBlockId() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(impObj()->xrefBlockId());
    throw PyNullObject();
}

bool PyDbDatabase::xrefEditEnabled() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->xrefEditEnabled();
    throw PyNullObject();
}

std::string PyDbDatabase::className()
{
    return "AcDbDatabase";
}

AcDbDatabase* PyDbDatabase::impObj() const
{
    return static_cast<AcDbDatabase*>(m_pImp);
}

