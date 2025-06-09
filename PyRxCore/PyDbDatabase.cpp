#include "stdafx.h"
#include "PyDbDatabase.h"
#include "PyDbObjectId.h"
#include "PyDbObject.h"
#include "PyDbEntity.h"
#include "PyDbTransactionManager.h"
#include "PyDbObjectContext.h"
#include "PyDbSymbolTableRecord.h"
#include "PyDbIdMapping.h"
#include "PyDbDatabaseReactor.h"
#include "PyDbDate.h"
#include "PyDbDbLayerStateManager.h"
#include "PyAcadApplication.h"
#include "PyDbGraph.h"

using namespace boost::python;
//---------------------------------------------------------------------------------------------------
// makeAcDbDatabaseWrapper
void makePyDbDatabaseWrapper()
{
    constexpr const std::string_view objectIdsOverloads = "Overloads:\n"
        "desc: PyRx.RxClass=PyDb.DbObject\n"
        "descList: list[PyRx.RxClass]\n";

    constexpr const std::string_view wblockOverloads = "Overloads:\n"
        "- None: Any\n"
        "- blockId : PyDb.ObjectId\n"
        "- blockIds : list[PyDb.ObjectId], basePoint : PyGe.Point3d\n";

    constexpr const std::string_view insertOverloads = "Overloads:\n"
        "- blockId: PyDb.ObjectId, pBlockName: str, db:PyDb.Database, preserveSourceDatabase: bool\n"
        "- blockId: PyDb.ObjectId, pBlockName: str, pDestinationBlockName: str, db:PyDb.Database, preserveSourceDatabase: bool\n"
        "- xform: PyGe.Matrix3d, db: PyDb.Database, preserveSourceDatabase: bool\n";

    PyDocString DS("PyDb.Database");
    class_<PyDbDatabase, bases<PyRxObject>>("Database")
        .def(init<>())
        .def(init<bool, bool>(DS.ARGS({ "buildDefaultDrawing : bool=True", "noDocument: bool=False" }, 19135)))
        .def("acadDatabase", &PyDbDatabase::acadDatabase)
        .def("addToBlock", &PyDbDatabase::addToBlock1)
        .def("addToBlock", &PyDbDatabase::addToBlock2, DS.ARGS({ "btrid : PyDb.ObjectId", "entity : PyDb.Entity | list[PyDb.Entity]" }))
        .def("addToModelspace", &PyDbDatabase::addToModelspace1)
        .def("addToModelspace", &PyDbDatabase::addToModelspace2, DS.ARGS({ "entity : PyDb.Entity | list[PyDb.Entity]" }, 19133))
        .def("addToCurrentspace", &PyDbDatabase::addToCurrentspace1)
        .def("addToCurrentspace", &PyDbDatabase::addToCurrentspace2, DS.ARGS({ "entity : PyDb.Entity | list[PyDb.Entity]" }, 19134))
        .def("addObject", &PyDbDatabase::addAcDbObject, DS.ARGS({ "object : PyDb.DbObject" }, 2863))
        .def("addReactor", &PyDbDatabase::addReactor, DS.ARGS({ "reactor : PyDb.DatabaseReactor" }, 2864))
        .def("angbase", &PyDbDatabase::angbase, DS.ARGS(2865))
        .def("angdir", &PyDbDatabase::angdir, DS.ARGS(2866))
        .def("annoAllVisible", &PyDbDatabase::annoAllVisible, DS.ARGS(2867))
        .def("annotativeDwg", &PyDbDatabase::annotativeDwg, DS.ARGS(2868))
        .def("approxNumObjects", &PyDbDatabase::approxNumObjects, DS.ARGS(2870))
        .def("attmode", &PyDbDatabase::attmode, DS.ARGS(2872))
        .def("aunits", &PyDbDatabase::aunits, DS.ARGS(2875))
        .def("auprec", &PyDbDatabase::auprec, DS.ARGS(2876))
        .def("blipmode", &PyDbDatabase::blipmode, DS.ARGS(2877))
        .def("byBlockLinetype", &PyDbDatabase::byBlockLinetype, DS.ARGS(2879))
        .def("byBlockMaterial", &PyDbDatabase::byBlockMaterial, DS.ARGS(2880))
        .def("byLayerLinetype", &PyDbDatabase::byLayerLinetype, DS.ARGS(2881))
        .def("byLayerMaterial", &PyDbDatabase::byLayerMaterial, DS.ARGS(2882))
        .def("cameraDisplay", &PyDbDatabase::cameraDisplay, DS.ARGS(2883))
        .def("cameraHeight", &PyDbDatabase::cameraHeight, DS.ARGS(2884))
        .def("cDynDisplayMode", &PyDbDatabase::cDynDisplayMode, DS.ARGS(2886))
        .def("celtscale", &PyDbDatabase::celtscale, DS.ARGS(2888))
        .def("celtype", &PyDbDatabase::celtype, DS.ARGS(2889))
        .def("celweight", &PyDbDatabase::celweight, DS.ARGS(2890))
        .def("chamfera", &PyDbDatabase::chamfera, DS.ARGS(2892))
        .def("chamferb", &PyDbDatabase::chamferb, DS.ARGS(2893))
        .def("chamferc", &PyDbDatabase::chamferc, DS.ARGS(2894))
        .def("chamferd", &PyDbDatabase::chamferd, DS.ARGS(2895))
        .def("classDxfName", &PyDbDatabase::classDxfName, DS.ARGS({ "pClass : PyRx.RxClass" }, 2896))
        .def("clayer", &PyDbDatabase::clayer, DS.ARGS(2897))
        .def("closeInput", &PyDbDatabase::closeInput, DS.ARGS({ "close : bool" }, 2899))
        .def("cmaterial", &PyDbDatabase::cmaterial, DS.ARGS(2900))
        .def("cmljust", &PyDbDatabase::cmljust, DS.ARGS(2901))
        .def("cmlscale", &PyDbDatabase::cmlscale, DS.ARGS(2902))
        .def("cmlstyleID", &PyDbDatabase::cmlstyleID, DS.ARGS(2903))
        .def("colorDictionaryId", &PyDbDatabase::colorDictionaryId, DS.ARGS(2904))
        .def("continuousLinetype", &PyDbDatabase::continuousLinetype, DS.ARGS(2905))
        .def("coords", &PyDbDatabase::coords, DS.ARGS(2906))
        .def("countEmptyObjects", &PyDbDatabase::countEmptyObjects, DS.ARGS({ "flag : int" }, 2907))
        .def("countHardReferences", &PyDbDatabase::countHardReferences, DS.ARGS({ "ids : list[PyDb.ObjectId]" }, 2908))
        .def("detailViewStyle", &PyDbDatabase::detailViewStyle, DS.ARGS(2915))
        .def("detailViewStyleDictionaryId", &PyDbDatabase::detailViewStyleDictionaryId, DS.ARGS(2916))
        .def("dimaso", &PyDbDatabase::dimaso, DS.ARGS(2918))
        .def("dimAssoc", &PyDbDatabase::dimAssoc, DS.ARGS(2919))
        .def("dimfit", &PyDbDatabase::dimfit, DS.ARGS(2920))
        .def("dimsho", &PyDbDatabase::dimsho, DS.ARGS(2921))
        .def("dimstyle", &PyDbDatabase::dimstyle, DS.ARGS(2922))
        .def("dimStyleTableId", &PyDbDatabase::dimStyleTableId, DS.ARGS(2923))
        .def("dimunit", &PyDbDatabase::dimunit, DS.ARGS(2924))
        .def("dimapost", &PyDbDatabase::dimapost, DS.ARGS(2957))
        .def("dimblk", &PyDbDatabase::dimblk, DS.ARGS(2960))
        .def("dimblk1", &PyDbDatabase::dimblk1, DS.ARGS(2958))
        .def("dimblk2", &PyDbDatabase::dimblk2, DS.ARGS(2959))
        .def("dimpost", &PyDbDatabase::dimpost, DS.ARGS(2961))
        .def("disablePartialOpen", &PyDbDatabase::disablePartialOpen, DS.ARGS(2925))
        .def("disableUndoRecording", &PyDbDatabase::disableUndoRecording, DS.ARGS({ "disable : bool" }, 2926))
        .def("dispSilh", &PyDbDatabase::dispSilh, DS.ARGS(2928))
        .def("dragmode", &PyDbDatabase::dragmode, DS.ARGS(2929))
        .def("dragVisStyle", &PyDbDatabase::dragVisStyle, DS.ARGS(2930))
        .def("drawOrderCtl", &PyDbDatabase::drawOrderCtl, DS.ARGS(2931))
        .def("dwfframe", &PyDbDatabase::dwfframe, DS.ARGS(2932))
        .def("dwgFileWasSavedByAutodeskSoftware", &PyDbDatabase::dwgFileWasSavedByAutodeskSoftware, DS.ARGS(2933))
        .def("dxfIn", &PyDbDatabase::dxfIn, DS.ARGS({ "filename : str" }, 2934))
        .def("dxfOut", &PyDbDatabase::dxfOut1)
        .def("dxfOut", &PyDbDatabase::dxfOut2, DS.ARGS({ "filename : str","precision : int=16, dwgVer:PyDb.DwgVersion=PyDb.DwgVersion.kDHL_CURRENT,saveThumbnailImage: bool=False" }, 2935))
        .def("elevation", &PyDbDatabase::elevation, DS.ARGS(2937))
        .def("eraseEmptyObjects", &PyDbDatabase::eraseEmptyObjects, DS.ARGS({ "flag : int" }, 2939))
        .def("extmax", &PyDbDatabase::extmax, DS.ARGS(2941))
        .def("extmin", &PyDbDatabase::extmin, DS.ARGS(2942))
        .def("facetres", &PyDbDatabase::facetres, DS.ARGS(2943))
        .def("filletrad", &PyDbDatabase::filletrad, DS.ARGS(2944))
        .def("fillmode", &PyDbDatabase::fillmode, DS.ARGS(2945))
        .def("forceWblockDatabaseCopy", &PyDbDatabase::forceWblockDatabaseCopy, DS.ARGS(2946))
        .def("geoCoordinateSystemId", &PyDbDatabase::geoCoordinateSystemId, DS.ARGS(2947))
        .def("geoMarkerVisibility", &PyDbDatabase::geoMarkerVisibility, DS.ARGS(2948))
        .def("getLayerStateManager", &PyDbDatabase::getLayerStateManager, DS.ARGS(2972))
        .def("get3dDwfPrec", &PyDbDatabase::get3dDwfPrec, DS.ARGS(2949))
        .def("objectIds", &PyDbDatabase::objectIds)
        .def("objectIds", &PyDbDatabase::objectIdsOfType)
        .def("objectIds", &PyDbDatabase::objectIdsOfTypeList, DS.OVRL(objectIdsOverloads))
        .def("objectIdArray", &PyDbDatabase::objectIdArray1)
        .def("objectIdArray", &PyDbDatabase::objectIdArray2)
        .def("objectIdArray", &PyDbDatabase::objectIdArray3, DS.OVRL(objectIdsOverloads))
        .def("getObjectId", &PyDbDatabase::getAcDbObjectId1)
        .def("getObjectId", &PyDbDatabase::getAcDbObjectId2, DS.ARGS({ "createIfNotFound : bool","objHandle : Handle","xRefId : int=0" }, 2950))
        .def("tryGetObjectId", &PyDbDatabase::tryGetAcDbObjectId1)
        .def("tryGetObjectId", &PyDbDatabase::tryGetAcDbObjectId2, DS.ARGS({ "createIfNotFound : bool","objHandle : Handle","xRefId : int=0" }))
        .def("getCePlotStyleNameId", &PyDbDatabase::getCePlotStyleNameId, DS.ARGS(2952))
        .def("getDimstyleParentId", &PyDbDatabase::getDimstyleParentId, DS.ARGS(2966))
        .def("getNearestLineWeight", &PyDbDatabase::getNearestLineWeight, DS.SARGS({ "weight : int" }, 2981)).staticmethod("getNearestLineWeight")//static
        .def("getSectionManagerId", &PyDbDatabase::getSectionManagerId, DS.ARGS(2987))
        .def("getViewportArray", &PyDbDatabase::getViewportArray1)
        .def("getViewportArray", &PyDbDatabase::getViewportArray2, DS.ARGS({ "val: bool=True" }, 2997))
        .def("getVisualStyleList", &PyDbDatabase::getVisualStyleList, DS.ARGS(3001))
        .def("globalMaterial", &PyDbDatabase::globalMaterial, DS.ARGS(3002))
        .def("groupDictionaryId", &PyDbDatabase::groupDictionaryId, DS.ARGS(3003))
        .def("haloGap", &PyDbDatabase::haloGap, DS.ARGS(3004))
        .def("handseed", &PyDbDatabase::handseed, DS.ARGS(3005))
        .def("hasClass", &PyDbDatabase::hasClass, DS.ARGS({ "pClass : PyRx.RxClass" }, 3006))
        .def("hideText", &PyDbDatabase::hideText, DS.ARGS(3007))
        .def("hpInherit", &PyDbDatabase::hpInherit, DS.ARGS(3008))
        .def("hpOrigin", &PyDbDatabase::hpOrigin, DS.ARGS(3009))
        .def("insert", &PyDbDatabase::insert1)
        .def("insert", &PyDbDatabase::insert2)
        .def("insert", &PyDbDatabase::insert3, DS.OVRL(insertOverloads), 3013)
        .def("indexctl", &PyDbDatabase::indexctl, DS.ARGS(3010))
        .def("isAppRegistered", &PyDbDatabase::isAppRegistered, DS.ARGS({ "pszAppName : str" }, 3020))
        .def("insunits", &PyDbDatabase::insunits, DS.ARGS(3014))
        .def("interfereVpVisStyle", &PyDbDatabase::interfereVpVisStyle, DS.ARGS(3017))
        .def("intersectColor", &PyDbDatabase::intersectColor, DS.ARGS(3018))
        .def("intersectDisplay", &PyDbDatabase::intersectDisplay, DS.ARGS(3019))
        .def("isBeingDestroyed", &PyDbDatabase::isBeingDestroyed, DS.ARGS(3021))
        .def("isEMR", &PyDbDatabase::isEMR, DS.ARGS(3022))
        .def("isObjectNonPersistent", &PyDbDatabase::isObjectNonPersistent, DS.SARGS({ "id : ObjectId" }, 3023)).staticmethod("isObjectNonPersistent")//static
        .def("isolines", &PyDbDatabase::isolines, DS.ARGS(3024))
        .def("isPartiallyOpened", &PyDbDatabase::isPartiallyOpened, DS.ARGS(3025))
        .def("isPucsOrthographic", &PyDbDatabase::isPucsOrthographic, DS.ARGS({ "orthoView : OrthographicView" }, 3026))
        .def("isUcsOrthographic", &PyDbDatabase::isUcsOrthographic, DS.ARGS({ "orthoView : OrthographicView" }, 3027))
        .def("isValidLineWeight", &PyDbDatabase::isValidLineWeight, DS.SARGS({ "weight : int" }, 3028)).staticmethod("isValidLineWeight")//static
        .def("joinStyle", &PyDbDatabase::joinStyle, DS.ARGS(3030))
        .def("lastSavedAsMaintenanceVersion", &PyDbDatabase::lastSavedAsMaintenanceVersion, DS.ARGS(3031))
        .def("lastSavedAsVersion", &PyDbDatabase::lastSavedAsVersion, DS.ARGS(3032))
        .def("latitude", &PyDbDatabase::latitude, DS.ARGS(3033))
        .def("layerEval", &PyDbDatabase::layerEval, DS.ARGS(3034))
        .def("layerNotify", &PyDbDatabase::layerNotify, DS.ARGS(3035))
        .def("layerTableId", &PyDbDatabase::layerTableId, DS.ARGS(3036))
        .def("layerZero", &PyDbDatabase::layerZero, DS.ARGS(3037))
        .def("layoutDictionaryId", &PyDbDatabase::layoutDictionaryId, DS.ARGS(3038))
        .def("lensLength", &PyDbDatabase::lensLength, DS.ARGS(3039))
        .def("lightGlyphDisplay", &PyDbDatabase::lightGlyphDisplay, DS.ARGS(3040))
        .def("lightingUnits", &PyDbDatabase::lightingUnits, DS.ARGS(3041))
        .def("lightsInBlocks", &PyDbDatabase::lightsInBlocks, DS.ARGS(3042))
        .def("limcheck", &PyDbDatabase::limcheck, DS.ARGS(3043))
        .def("limmax", &PyDbDatabase::limmax, DS.ARGS(3044))
        .def("limmin", &PyDbDatabase::limmin, DS.ARGS(3045))
        .def("linetypeTableId", &PyDbDatabase::linetypeTableId, DS.ARGS(3046))
        .def("lineWeightDisplay", &PyDbDatabase::lineWeightDisplay, DS.ARGS(3047))
        .def("loadLineTypeFile", &PyDbDatabase::loadLineTypeFile, DS.ARGS({ "ltn : str","filename : str" }, 3048))
        .def("loftAng1", &PyDbDatabase::loftAng1, DS.ARGS(3049))
        .def("loftAng2", &PyDbDatabase::loftAng2, DS.ARGS(3050))
        .def("loftMag1", &PyDbDatabase::loftMag1, DS.ARGS(3051))
        .def("loftMag2", &PyDbDatabase::loftMag2, DS.ARGS(3052))
        .def("loftNormals", &PyDbDatabase::loftNormals, DS.ARGS(3053))
        .def("loftParam", &PyDbDatabase::loftParam, DS.ARGS(3054))
        .def("longitude", &PyDbDatabase::longitude, DS.ARGS(3055))
        .def("ltscale", &PyDbDatabase::ltscale, DS.ARGS(3056))
        .def("lunits", &PyDbDatabase::lunits, DS.ARGS(3057))
        .def("luprec", &PyDbDatabase::luprec, DS.ARGS(3058))
        .def("maintenanceReleaseVersion", &PyDbDatabase::maintenanceReleaseVersion, DS.ARGS(3059))
        .def("markObjectNonPersistent", &PyDbDatabase::markObjectNonPersistent, DS.SARGS({ "id : ObjectId","value : bool" }, 3060)).staticmethod("markObjectNonPersistent")//static
        .def("materialDictionaryId", &PyDbDatabase::materialDictionaryId, DS.ARGS(3061))
        .def("maxactvp", &PyDbDatabase::maxactvp, DS.ARGS(3062))
        .def("measurement", &PyDbDatabase::measurement, DS.ARGS(3063))
        .def("mirrtext", &PyDbDatabase::mirrtext, DS.ARGS(3064))
        .def("mleaderscale", &PyDbDatabase::mleaderscale, DS.ARGS(3065))
        .def("mleaderstyle", &PyDbDatabase::mleaderstyle, DS.ARGS(3066))
        .def("mleaderStyleDictionaryId", &PyDbDatabase::mleaderStyleDictionaryId, DS.ARGS(3067))
        .def("mLStyleDictionaryId", &PyDbDatabase::mLStyleDictionaryId, DS.ARGS(3068))
        .def("msltscale", &PyDbDatabase::msltscale, DS.ARGS(3069))
        .def("msOleScale", &PyDbDatabase::msOleScale, DS.ARGS(3070))
        .def("namedObjectsDictionaryId", &PyDbDatabase::namedObjectsDictionaryId, DS.ARGS(3071))
        .def("needsRecovery", &PyDbDatabase::needsRecovery, DS.ARGS(3072))
        .def("northDirection", &PyDbDatabase::northDirection, DS.ARGS(3073))
        .def("numberOfSaves", &PyDbDatabase::numberOfSaves, DS.ARGS(3074))
        .def("objectContextManager", &PyDbDatabase::objectContextManager, DS.ARGS(3075))
        .def("obscuredColor", &PyDbDatabase::obscuredColor, DS.ARGS(3076))
        .def("obscuredLineType", &PyDbDatabase::obscuredLineType, DS.ARGS(3077))
        .def("oleStartUp", &PyDbDatabase::oleStartUp, DS.ARGS(3078))
        .def("originalFileMaintenanceVersion", &PyDbDatabase::originalFileMaintenanceVersion, DS.ARGS(3080))
        .def("originalFileName", &PyDbDatabase::originalFileName, DS.ARGS(3081))
        .def("originalFileSavedByMaintenanceVersion", &PyDbDatabase::originalFileSavedByMaintenanceVersion, DS.ARGS(3082))
        .def("originalFileSavedByVersion", &PyDbDatabase::originalFileSavedByVersion, DS.ARGS(3083))
        .def("originalFileVersion", &PyDbDatabase::originalFileVersion, DS.ARGS(3084))
        .def("orthomode", &PyDbDatabase::orthomode, DS.ARGS(3085))
        .def("paperSpaceVportId", &PyDbDatabase::paperSpaceVportId, DS.ARGS(3087))
        .def("pdfframe", &PyDbDatabase::pdfframe, DS.ARGS(3088))
        .def("pdmode", &PyDbDatabase::pdmode, DS.ARGS(3089))
        .def("pdsize", &PyDbDatabase::pdsize, DS.ARGS(3090))
        .def("pextmax", &PyDbDatabase::pextmax, DS.ARGS(3092))
        .def("pextmin", &PyDbDatabase::pextmin, DS.ARGS(3093))
        .def("pickstyle", &PyDbDatabase::pickstyle, DS.ARGS(3094))
        .def("pinsbase", &PyDbDatabase::pinsbase, DS.ARGS(3095))
        .def("plimcheck", &PyDbDatabase::plimcheck, DS.ARGS(3096))
        .def("plimmax", &PyDbDatabase::plimmax, DS.ARGS(3097))
        .def("plimmin", &PyDbDatabase::plimmin, DS.ARGS(3098))
        .def("plineEllipse", &PyDbDatabase::plineEllipse, DS.ARGS(3099))
        .def("plinegen", &PyDbDatabase::plinegen, DS.ARGS(3100))
        .def("plinewid", &PyDbDatabase::plinewid, DS.ARGS(3101))
        .def("plotSettingsDictionaryId", &PyDbDatabase::plotSettingsDictionaryId, DS.ARGS(3102))
        .def("plotStyleMode", &PyDbDatabase::plotStyleMode, DS.ARGS(3103))
        .def("plotStyleNameDictionaryId", &PyDbDatabase::plotStyleNameDictionaryId, DS.ARGS(3104))
        .def("previewType", &PyDbDatabase::previewType, DS.ARGS(3105))
        .def("psltscale", &PyDbDatabase::psltscale, DS.ARGS(3106))
        .def("psolHeight", &PyDbDatabase::psolHeight, DS.ARGS(3107))
        .def("psolWidth", &PyDbDatabase::psolWidth, DS.ARGS(3108))
        .def("pucsBase", &PyDbDatabase::pucsBase, DS.ARGS(3109))
        .def("pucsname", &PyDbDatabase::pucsname, DS.ARGS(3110))
        .def("pucsorg", &PyDbDatabase::pucsorg, DS.ARGS(3111))
        .def("pucsxdir", &PyDbDatabase::pucsxdir, DS.ARGS(3112))
        .def("pucsydir", &PyDbDatabase::pucsydir, DS.ARGS(3113))
        .def("qtextmode", &PyDbDatabase::qtextmode, DS.ARGS(3115))
        .def("reclaimMemoryFromErasedObjects", &PyDbDatabase::reclaimMemoryFromErasedObjects, DS.ARGS({ "ids : list[PyDb.ObjectId]" }, 3117))
        .def("regAppTableId", &PyDbDatabase::regAppTableId, DS.ARGS(3118))
        .def("regenmode", &PyDbDatabase::regenmode, DS.ARGS(3119))
        .def("registerApp", &PyDbDatabase::registerApp, DS.ARGS({ "appName : str" }, 3120))
        .def("removeReactor", &PyDbDatabase::removeReactor, DS.ARGS({ "reactor : PyDb.DatabaseReactor" }, 3121))
        .def("resetTimes", &PyDbDatabase::resetTimes, DS.ARGS(3122))
        .def("restoreForwardingXrefSymbols", &PyDbDatabase::restoreForwardingXrefSymbols, DS.ARGS(3123))
        .def("restoreOriginalXrefSymbols", &PyDbDatabase::restoreOriginalXrefSymbols, DS.ARGS(3124))
        .def("retainOriginalThumbnailBitmap", &PyDbDatabase::retainOriginalThumbnailBitmap, DS.ARGS(3125))
        .def("saveproxygraphics", &PyDbDatabase::saveproxygraphics, DS.ARGS(3128))
        .def("scaleListDictionaryId", &PyDbDatabase::scaleListDictionaryId, DS.ARGS(3129))
        .def("sectionViewStyle", &PyDbDatabase::sectionViewStyle, DS.ARGS(3130))
        .def("sectionViewStyleDictionaryId", &PyDbDatabase::sectionViewStyleDictionaryId, DS.ARGS(3131))
        .def("set3dDwfPrec", &PyDbDatabase::set3dDwfPrec, DS.ARGS({ "dwfPrec : float" }, 3132))
        .def("setAngbase", &PyDbDatabase::setAngbase, DS.ARGS({ "angle : float" }, 3133))
        .def("setAngdir", &PyDbDatabase::setAngdir, DS.ARGS({ "dir : bool" }, 3134))
        .def("setAnnoAllVisible", &PyDbDatabase::setAnnoAllVisible, DS.ARGS({ "allvis : bool" }, 3135))
        .def("setAttdia", &PyDbDatabase::setAttdia, DS.ARGS({ "val : bool" }, 3136))
        .def("setAttmode", &PyDbDatabase::setAttmode, DS.ARGS({ "val : int" }, 3137))
        .def("setAttreq", &PyDbDatabase::setAttreq, DS.ARGS({ "val : bool" }, 3138))
        .def("setAunits", &PyDbDatabase::setAunits, DS.ARGS({ "val : int" }, 3139))
        .def("setAuprec", &PyDbDatabase::setAuprec, DS.ARGS({ "val : int" }, 3140))
        .def("setBlipmode", &PyDbDatabase::setBlipmode, DS.ARGS({ "val : bool" }, 3141))
        .def("setCameraDisplay", &PyDbDatabase::setCameraDisplay, DS.ARGS({ "val : bool" }, 3142))
        .def("setCameraHeight", &PyDbDatabase::setCameraHeight, DS.ARGS({ "val : float" }, 3143))
        .def("setCDynDisplayMode", &PyDbDatabase::setCDynDisplayMode, DS.ARGS({ "val : int" }, 3145))
        .def("setCeltscale", &PyDbDatabase::setCeltscale, DS.ARGS({ "val : float" }, 3147))
        .def("setCeltype", &PyDbDatabase::setCeltype, DS.ARGS({ "val : ObjectId" }, 3148))
        .def("setCelweight", &PyDbDatabase::setCelweight, DS.ARGS({ "val : LineWeight" }, 3149))
        .def("setCePlotStyleName", &PyDbDatabase::setCePlotStyleName, DS.ARGS({ "val : PyDb.PlotStyleNameType", "id : PyDb.ObjectId" }, 3150))
        .def("setChamfera", &PyDbDatabase::setChamfera, DS.ARGS({ "val : float" }, 3152))
        .def("setChamferb", &PyDbDatabase::setChamferb, DS.ARGS({ "val : float" }, 3153))
        .def("setChamferc", &PyDbDatabase::setChamferc, DS.ARGS({ "val : float" }, 3154))
        .def("setChamferd", &PyDbDatabase::setChamferd, DS.ARGS({ "val : float" }, 3155))
        .def("setClayer", &PyDbDatabase::setClayer, DS.ARGS({ "val : ObjectId" }, 3156))
        .def("setCmaterial", &PyDbDatabase::setCmaterial, DS.ARGS({ "val : ObjectId" }, 3157))
        .def("setCmljust", &PyDbDatabase::setCmljust, DS.ARGS({ "val : int" }, 3158))
        .def("setCmlscale", &PyDbDatabase::setCmlscale, DS.ARGS({ "val : float" }, 3159))
        .def("setCmlstyleID", &PyDbDatabase::setCmlstyleID, DS.ARGS({ "val : ObjectId" }, 3160))
        .def("setCoords", &PyDbDatabase::setCoords, DS.ARGS({ "val : int" }, 3161))
        .def("setCshadow", &PyDbDatabase::setCshadow, DS.ARGS({ "val : int" }, 3162))
        .def("setDelUsedObj", &PyDbDatabase::setDelUsedObj, DS.ARGS({ "val : int" }, 3163))
        .def("setDgnframe", &PyDbDatabase::setDgnframe, DS.ARGS({ "val : int" }, 3165))
        .def("setDimaso", &PyDbDatabase::setDimaso, DS.ARGS({ "val : bool" }, 3166))
        .def("setDimAssoc", &PyDbDatabase::setDimAssoc, DS.ARGS({ "val : int" }, 3167))
        .def("setDimfit", &PyDbDatabase::setDimfit, DS.ARGS({ "val : int" }, 3168))
        .def("setDimsho", &PyDbDatabase::setDimsho, DS.ARGS({ "val : bool" }, 3169))
        .def("setDimstyle", &PyDbDatabase::setDimstyle, DS.ARGS({ "val : ObjectId" }, 3170))
        .def("setDimstyleData", &PyDbDatabase::setDimstyleData1)
        .def("setDimstyleData", &PyDbDatabase::setDimstyleData2, DS.ARGS({ "val : PyDb.DimStyleTableRecord | PyDb.ObjectId" }, 3171))
        .def("setDimunit", &PyDbDatabase::setDimunit, DS.ARGS({ "val : int" }, 3172))
        .def("setDispSilh", &PyDbDatabase::setDispSilh, DS.ARGS({ "val : bool" }, 3173))
        .def("setDragmode", &PyDbDatabase::setDragmode, DS.ARGS({ "val : int" }, 3174))
        .def("setDragVisStyle", &PyDbDatabase::setDragVisStyle, DS.ARGS({ "val : ObjectId" }, 3175))
        .def("setDrawOrderCtl", &PyDbDatabase::setDrawOrderCtl, DS.ARGS({ "val : int" }, 3176))
        .def("setDwfframe", &PyDbDatabase::setDwfframe, DS.ARGS({ "val : int" }, 3177))
        .def("setElevation", &PyDbDatabase::setElevation, DS.ARGS({ "val : float" }, 3178))
        .def("setEndCaps", &PyDbDatabase::setEndCaps, DS.ARGS({ "val : EndCaps" }, 3179))
        .def("setExtmax", &PyDbDatabase::setExtmax, DS.ARGS({ "val : PyGe.Point3d" }, 3180))
        .def("setExtmin", &PyDbDatabase::setExtmin, DS.ARGS({ "val : PyGe.Point3d" }, 3181))
        .def("setFacetres", &PyDbDatabase::setFacetres, DS.ARGS({ "val : float" }, 3182))
        .def("setFilletrad", &PyDbDatabase::setFilletrad, DS.ARGS({ "val : float" }, 3183))
        .def("setFillmode", &PyDbDatabase::setFillmode, DS.ARGS({ "val : bool" }, 3184))
        .def("saveAs", &PyDbDatabase::saveAs1)
        .def("saveAs", &PyDbDatabase::saveAs2, DS.ARGS({ "filename: str", "bBakAndRename: bool = False","dwgVer: PyDb.DwgVersion = PyDb.DwgVersion.kDHL_CURRENT" }, 3127))
        .def("setFingerprintGuid", &PyDbDatabase::setFingerprintGuid, DS.ARGS({ "guid : str" }, 3185))
        .def("setFullSaveRequired", &PyDbDatabase::setFullSaveRequired, DS.ARGS(3186))
        .def("setGeoMarkerVisibility", &PyDbDatabase::setGeoMarkerVisibility, DS.ARGS({ "val : bool" }, 3187))
        .def("setHaloGap", &PyDbDatabase::setHaloGap, DS.ARGS({ "val : int" }, 3188))
        .def("setHandseed", &PyDbDatabase::setHandseed, DS.ARGS({ "val : Handle" }, 3189))
        .def("setHideText", &PyDbDatabase::setHideText, DS.ARGS({ "val : int" }, 3190))
        .def("setHpInherit", &PyDbDatabase::setHpInherit, DS.ARGS({ "val : bool" }, 3191))
        .def("setHpOrigin", &PyDbDatabase::setHpOrigin, DS.ARGS({ "val : PyGe.Point2d" }, 3192))
        .def("setHyperlinkBase", &PyDbDatabase::setHyperlinkBase, DS.ARGS({ "val : str" }, 3193))
        .def("setIndexctl", &PyDbDatabase::setIndexctl, DS.ARGS({ "val : int" }, 3194))
        .def("setInsbase", &PyDbDatabase::setInsbase, DS.ARGS({ "val : PyGe.Point3d" }, 3195))
        .def("setInsunits", &PyDbDatabase::setInsunits, DS.ARGS({ "val : UnitsValue" }, 3196))
        .def("setInterfereObjVisStyle", &PyDbDatabase::setInterfereObjVisStyle, DS.ARGS({ "val : PyDb.ObjectId" }, 3198))
        .def("setInterfereVpVisStyle", &PyDbDatabase::setInterfereVpVisStyle, DS.ARGS({ "val : PyDb.ObjectId" }, 3199))
        .def("setIntersectColor", &PyDbDatabase::setIntersectColor, DS.ARGS({ "val : int" }, 3200))
        .def("setIntersectDisplay", &PyDbDatabase::setIntersectDisplay, DS.ARGS({ "val : int" }, 3201))
        .def("setIsolines", &PyDbDatabase::setIsolines, DS.ARGS({ "val : int" }, 3202))
        .def("setJoinStyle", &PyDbDatabase::setJoinStyle, DS.ARGS({ "val : JoinStyle" }, 3203))
        .def("setLatitude", &PyDbDatabase::setLatitude, DS.ARGS({ "val : float" }, 3204))
        .def("setLayerEval", &PyDbDatabase::setLayerEval, DS.ARGS({ "val : int" }, 3205))
        .def("setLayerNotify", &PyDbDatabase::setLayerNotify, DS.ARGS({ "val : int" }, 3206))
        .def("setLensLength", &PyDbDatabase::setLensLength, DS.ARGS({ "val : float" }, 3207))
        .def("setLightGlyphDisplay", &PyDbDatabase::setLightGlyphDisplay, DS.ARGS({ "val : int" }, 3208))
        .def("setLightingUnits", &PyDbDatabase::setLightingUnits, DS.ARGS({ "val : int" }, 3209))
        .def("setLightsInBlocks", &PyDbDatabase::setLightsInBlocks, DS.ARGS({ "val : bool" }, 3210))
        .def("setLimcheck", &PyDbDatabase::setLimcheck, DS.ARGS({ "val : bool" }, 3210))
        .def("setLimmax", &PyDbDatabase::setLimmax, DS.ARGS({ "val : PyGe.Point2d" }, 3212))
        .def("setLimmin", &PyDbDatabase::setLimmin, DS.ARGS({ "val : PyGe.Point2d" }, 3213))
        .def("setLineWeightDisplay", &PyDbDatabase::setLineWeightDisplay, DS.ARGS({ "val : bool" }, 3214))
        .def("setLoftAng1", &PyDbDatabase::setLoftAng1, DS.ARGS({ "val : float" }, 3215))
        .def("setLoftAng2", &PyDbDatabase::setLoftAng2, DS.ARGS({ "val : float" }, 3216))
        .def("setLoftMag1", &PyDbDatabase::setLoftMag1, DS.ARGS({ "val : float" }, 3217))
        .def("setLoftMag2", &PyDbDatabase::setLoftMag2, DS.ARGS({ "val : float" }, 3218))
        .def("setLoftNormals", &PyDbDatabase::setLoftNormals, DS.ARGS({ "val : int" }, 3219))
        .def("setLoftParam", &PyDbDatabase::setLoftParam, DS.ARGS({ "flags : int" }, 3220))
        .def("setLongitude", &PyDbDatabase::setLongitude, DS.ARGS({ "val : float" }, 3221))
        .def("setLtscale", &PyDbDatabase::setLtscale, DS.ARGS({ "val : float" }, 3222))
        .def("setLunits", &PyDbDatabase::setLunits, DS.ARGS({ "val : int" }, 3223))
        .def("setLuprec", &PyDbDatabase::setLuprec, DS.ARGS({ "val : int" }, 3224))
        .def("setMaxactvp", &PyDbDatabase::setMaxactvp, DS.ARGS({ "val : int" }, 3225))
        .def("setMeasurement", &PyDbDatabase::setMeasurement, DS.ARGS({ "val : MeasurementValue" }, 3226))
        .def("setMirrtext", &PyDbDatabase::setMirrtext, DS.ARGS({ "val : bool" }, 3227))
        .def("setMLeaderscale", &PyDbDatabase::setMLeaderscale, DS.ARGS({ "val : float" }, 3228))
        .def("setMLeaderstyle", &PyDbDatabase::setMLeaderstyle, DS.ARGS({ "val : ObjectId" }, 3229))
        .def("setMsltscale", &PyDbDatabase::setMsltscale, DS.ARGS({ "val : bool" }, 3230))
        .def("setMsOleScale", &PyDbDatabase::setMsOleScale, DS.ARGS({ "val : float" }, 3231))
        .def("setNorthDirection", &PyDbDatabase::setNorthDirection, DS.ARGS({ "val : float" }, 3232))
        .def("setObscuredColor", &PyDbDatabase::setObscuredColor, DS.ARGS({ "val : int" }, 3233))
        .def("setObscuredLineType", &PyDbDatabase::setObscuredLineType, DS.ARGS({ "val : int" }, 3234))
        .def("setOleStartUp", &PyDbDatabase::setOleStartUp, DS.ARGS({ "val : bool" }, 3235))
        .def("setOrthomode", &PyDbDatabase::setOrthomode, DS.ARGS({ "val : bool" }, 3236))
        .def("setPdfframe", &PyDbDatabase::setPdfframe, DS.ARGS({ "val : int" }, 3237))
        .def("setPdmode", &PyDbDatabase::setPdmode, DS.ARGS({ "val : int" }, 3238))
        .def("setPdsize", &PyDbDatabase::setPdsize, DS.ARGS({ "val : float" }, 3239))
        .def("setPelevation", &PyDbDatabase::setPelevation, DS.ARGS({ "val : float" }, 3240))
        .def("setPextmax", &PyDbDatabase::setPextmax, DS.ARGS({ "val : PyGe.Point3d" }, 3241))
        .def("setPextmin", &PyDbDatabase::setPextmin, DS.ARGS({ "val : PyGe.Point3d" }, 3242))
        .def("setPickstyle", &PyDbDatabase::setPickstyle, DS.ARGS({ "val : int" }, 3243))
        .def("setPinsbase", &PyDbDatabase::setPinsbase, DS.ARGS({ "val : PyGe.Point3d" }, 3244))
        .def("setPlimcheck", &PyDbDatabase::setPlimcheck, DS.ARGS({ "val : bool" }, 3245))
        .def("setPlimmax", &PyDbDatabase::setPlimmax, DS.ARGS({ "val : PyGe.Point2d" }, 3246))
        .def("setPlimmin", &PyDbDatabase::setPlimmin, DS.ARGS({ "val : PyGe.Point2d" }, 3247))
        .def("setPlineEllipse", &PyDbDatabase::setPlineEllipse, DS.ARGS({ "val : bool" }, 3248))
        .def("setPlinegen", &PyDbDatabase::setPlinegen, DS.ARGS({ "val : bool" }, 3248))
        .def("setPlinewid", &PyDbDatabase::setPlinewid, DS.ARGS({ "val : float" }, 3250))
        .def("setPreviewType", &PyDbDatabase::setPreviewType, DS.ARGS({ "val : int" }, 3251))
        .def("setProjectName", &PyDbDatabase::setProjectName, DS.ARGS({ "val : str" }, 3252))
        .def("setPsltscale", &PyDbDatabase::setPsltscale, DS.ARGS({ "val : bool" }, 3253))
        .def("setPsolHeight", &PyDbDatabase::setPsolHeight, DS.ARGS({ "val : float" }, 3254))
        .def("setPsolWidth", &PyDbDatabase::setPsolWidth, DS.ARGS({ "val : float" }, 3255))
        .def("setPucs", &PyDbDatabase::setPucs, DS.ARGS({ "ucsOrigin : PyGe.Point3d","ucsXDir : PyGe.Vector3d" ,"ucsYDir : PyGe.Vector3d" }, 3256))
        .def("setPucsBase", &PyDbDatabase::setPucsBase, DS.ARGS({ "ucsid : ObjectId" }, 3257))
        .def("setPucsname", &PyDbDatabase::setPucsname, DS.ARGS({ "ucsrec : ObjectId" }, 3258))
        .def("setQtextmode", &PyDbDatabase::setQtextmode, DS.ARGS({ "val : bool" }, 3259))
        .def("setRealWorldScale", &PyDbDatabase::setRealWorldScale, DS.ARGS({ "val : float" }, 3260))
        .def("setRegenmode", &PyDbDatabase::setRegenmode, DS.ARGS({ "val : bool" }, 3261))
        .def("setRetainOriginalThumbnailBitmap", &PyDbDatabase::setRetainOriginalThumbnailBitmap, DS.ARGS({ "val : bool" }, 3262))
        .def("setSaveproxygraphics", &PyDbDatabase::setSaveproxygraphics, DS.ARGS({ "val : int" }, 3263))
        .def("setSectionViewStyle", &PyDbDatabase::setSectionViewStyle, DS.ARGS({ "val : ObjectId" }, 3264))
        .def("setShadedge", &PyDbDatabase::setShadedge, DS.ARGS({ "val : int" }, 3266))
        .def("setShadedif", &PyDbDatabase::setShadedif, DS.ARGS({ "val : int" }, 3267))
        .def("setShadowPlaneLocation", &PyDbDatabase::setShadowPlaneLocation, DS.ARGS({ "val : float" }, 3268))
        .def("setShowHist", &PyDbDatabase::setShowHist, DS.ARGS({ "val : int" }, 3269))
        .def("setSketchinc", &PyDbDatabase::setSketchinc, DS.ARGS({ "val : float" }, 3270))
        .def("setSkpoly", &PyDbDatabase::setSkpoly, DS.ARGS({ "val : bool" }, 3271))
        .def("setSolidHist", &PyDbDatabase::setSolidHist, DS.ARGS({ "val : int" }, 3272))
        .def("setSortEnts", &PyDbDatabase::setSortEnts, DS.ARGS({ "val : int" }, 3273))
        .def("setSplframe", &PyDbDatabase::setSplframe, DS.ARGS({ "val : bool" }, 3274))
        .def("setSplinesegs", &PyDbDatabase::setSplinesegs, DS.ARGS({ "val : int" }, 3275))
        .def("setSplinetype", &PyDbDatabase::setSplinetype, DS.ARGS({ "val : int" }, 3276))
        .def("setStepSize", &PyDbDatabase::setStepSize, DS.ARGS({ "val : float" }, 3277))
        .def("setStepsPerSec", &PyDbDatabase::setStepsPerSec, DS.ARGS({ "val : float" }, 3278))
        .def("setStyleSheet", &PyDbDatabase::setStyleSheet, DS.ARGS({ "val : str" }, 3279))
        .def("setSurftab1", &PyDbDatabase::setSurftab1, DS.ARGS({ "val : int" }, 3280))
        .def("setSurftab2", &PyDbDatabase::setSurftab2, DS.ARGS({ "val : int" }, 3281))
        .def("setSurftype", &PyDbDatabase::setSurftype, DS.ARGS({ "val : int" }, 3282))
        .def("setSurfu", &PyDbDatabase::setSurfu, DS.ARGS({ "val : int" }, 3283))
        .def("setSurfv", &PyDbDatabase::setSurfv, DS.ARGS({ "val : int" }, 3284))
        .def("setTablestyle", &PyDbDatabase::setTablestyle, DS.ARGS({ "val : ObjectId" }, 3285))
        .def("setTextsize", &PyDbDatabase::setTextsize, DS.ARGS({ "val : float" }, 3286))
        .def("setTextstyle", &PyDbDatabase::setTextstyle, DS.ARGS({ "val : ObjectId" }, 3287))
        .def("setThickness", &PyDbDatabase::setThickness, DS.ARGS({ "val : float" }, 3288))
        .def("setTilemode", &PyDbDatabase::setTilemode, DS.ARGS({ "val : bool" }, 3291))
        .def("setTimeZone", &PyDbDatabase::setTimeZone, DS.ARGS({ "val : TimeZone" }, 3292))
        .def("setTimeZoneAsUtcOffset", &PyDbDatabase::setTimeZoneAsUtcOffset, DS.ARGS({ "val : float" }, 3293))
        .def("setTracewid", &PyDbDatabase::setTracewid, DS.ARGS({ "val : float" }, 3294))
        .def("setTreedepth", &PyDbDatabase::setTreedepth, DS.ARGS({ "val : int" }, 3295))
        .def("setTStackAlign", &PyDbDatabase::setTStackAlign, DS.ARGS({ "val : int" }, 3296))
        .def("setTStackSize", &PyDbDatabase::setTStackSize, DS.ARGS({ "val : int" }, 3297))
        .def("setUcs", &PyDbDatabase::setUcs, DS.ARGS({ "ucsOrigin : PyGe.Point3d","ucsXDir : PyGe.Vector3d" ,"ucsYDir : PyGe.Vector3d" }, 3298))
        .def("setUcsBase", &PyDbDatabase::setUcsBase, DS.ARGS({ "ucsid : ObjectId" }, 3299))
        .def("setUcsname", &PyDbDatabase::setUcsname, DS.ARGS({ "ucsrecId : ObjectId" }, 3300))
        .def("setUnitmode", &PyDbDatabase::setUnitmode, DS.ARGS({ "val : int" }, 3301))
        .def("setUpdateThumbnail", &PyDbDatabase::setUpdateThumbnail, DS.ARGS({ "val : int" }, 3302))
        .def("setUseri1", &PyDbDatabase::setUseri1, DS.ARGS({ "val : int" }, 3303))
        .def("setUseri2", &PyDbDatabase::setUseri2, DS.ARGS({ "val : int" }, 3304))
        .def("setUseri3", &PyDbDatabase::setUseri3, DS.ARGS({ "val : int" }, 3305))
        .def("setUseri4", &PyDbDatabase::setUseri4, DS.ARGS({ "val : int" }, 3306))
        .def("setUseri5", &PyDbDatabase::setUseri5, DS.ARGS({ "val : int" }, 3307))
        .def("setUserr1", &PyDbDatabase::setUserr1, DS.ARGS({ "val : float" }, 3308))
        .def("setUserr2", &PyDbDatabase::setUserr2, DS.ARGS({ "val : float" }, 3309))
        .def("setUserr3", &PyDbDatabase::setUserr3, DS.ARGS({ "val : float" }, 3310))
        .def("setUserr4", &PyDbDatabase::setUserr4, DS.ARGS({ "val : float" }, 3311))
        .def("setUserr5", &PyDbDatabase::setUserr5, DS.ARGS({ "val : float" }, 3312))
        .def("setUsrtimer", &PyDbDatabase::setUsrtimer, DS.ARGS({ "val : bool" }, 3313))
        .def("setVersionGuid", &PyDbDatabase::setVersionGuid, DS.ARGS({ "val : str" }, 3314))
        .def("setViewportScaleDefault", &PyDbDatabase::setViewportScaleDefault, DS.ARGS({ "val : float" }, 3315))
        .def("setVisretain", &PyDbDatabase::setVisretain, DS.ARGS({ "val : bool" }, 3316))
        .def("setWorldPucsBaseOrigin", &PyDbDatabase::setWorldPucsBaseOrigin, DS.ARGS({ "ucsOrigin : PyGe.Point3d","orthoView : OrthographicView" }, 3317))
        .def("setWorldUcsBaseOrigin", &PyDbDatabase::setWorldUcsBaseOrigin, DS.ARGS({ "ucsOrigin : PyGe.Point3d","orthoView : OrthographicView" }, 3318))
        .def("setWorldview", &PyDbDatabase::setWorldview, DS.ARGS({ "val : bool" }, 3319))
        .def("setXclipFrame", &PyDbDatabase::setXclipFrame, DS.ARGS({ "val : int" }, 3320))
        .def("setXrefEditEnabled", &PyDbDatabase::setXrefEditEnabled, DS.ARGS({ "val : bool" }, 3321))
        .def("shadedge", &PyDbDatabase::shadedge, DS.ARGS(3322))
        .def("shadedif", &PyDbDatabase::shadedif, DS.ARGS(3323))
        .def("shadowPlaneLocation", &PyDbDatabase::shadowPlaneLocation, DS.ARGS(3324))
        .def("showHist", &PyDbDatabase::showHist, DS.ARGS(3325))
        .def("sketchinc", &PyDbDatabase::sketchinc, DS.ARGS(3326))
        .def("skpoly", &PyDbDatabase::skpoly, DS.ARGS(3327))
        .def("solidHist", &PyDbDatabase::solidHist, DS.ARGS(3328))
        .def("sortEnts", &PyDbDatabase::sortEnts, DS.ARGS(3329))
        .def("splframe", &PyDbDatabase::splframe, DS.ARGS(3330))
        .def("splinesegs", &PyDbDatabase::splinesegs, DS.ARGS(3331))
        .def("splinetype", &PyDbDatabase::splinetype, DS.ARGS(3332))
        .def("stepSize", &PyDbDatabase::stepSize, DS.ARGS(3333))
        .def("stepsPerSec", &PyDbDatabase::stepsPerSec, DS.ARGS(3334))
        .def("surftab1", &PyDbDatabase::surftab1, DS.ARGS(3335))
        .def("surftab2", &PyDbDatabase::surftab2, DS.ARGS(3336))
        .def("surftype", &PyDbDatabase::surftype, DS.ARGS(3337))
        .def("surfu", &PyDbDatabase::surfu, DS.ARGS(3338))
        .def("surfv", &PyDbDatabase::surfv, DS.ARGS(3339))
        .def("tablestyle", &PyDbDatabase::tablestyle, DS.ARGS(3340))
        .def("tableStyleDictionaryId", &PyDbDatabase::tableStyleDictionaryId, DS.ARGS(3341))
        .def("tdcreate", &PyDbDatabase::tdcreate, DS.ARGS(3342))
        .def("tdindwg", &PyDbDatabase::tdindwg, DS.ARGS(3343))
        .def("tducreate", &PyDbDatabase::tducreate, DS.ARGS(3344))
        .def("tdupdate", &PyDbDatabase::tdupdate, DS.ARGS(3345))
        .def("tdusrtimer", &PyDbDatabase::tdusrtimer, DS.ARGS(3346))
        .def("tduupdate", &PyDbDatabase::tduupdate, DS.ARGS(3347))
        .def("textsize", &PyDbDatabase::textsize, DS.ARGS(3348))
        .def("textstyle", &PyDbDatabase::textstyle, DS.ARGS(3349))
        .def("textStyleTableId", &PyDbDatabase::textStyleTableId, DS.ARGS(3350))
        .def("thickness", &PyDbDatabase::thickness, DS.ARGS(3351))
        .def("tilemode", &PyDbDatabase::tilemode, DS.ARGS(3354))
        .def("tileModeLightSynch", &PyDbDatabase::tileModeLightSynch, DS.ARGS(3355))
        .def("timeZone", &PyDbDatabase::timeZone, DS.ARGS(3356))
        .def("tracewid", &PyDbDatabase::tracewid, DS.ARGS(3357))
        .def("treedepth", &PyDbDatabase::treedepth, DS.ARGS(3359))
        .def("transactionManager", &PyDbDatabase::transactionManager, DS.ARGS(3358))
        .def("tstackalign", &PyDbDatabase::tstackalign, DS.ARGS(3360))
        .def("tstacksize", &PyDbDatabase::tstacksize, DS.ARGS(3361))
        .def("ucsBase", &PyDbDatabase::ucsBase, DS.ARGS(3362))
        .def("ucsname", &PyDbDatabase::ucsname, DS.ARGS(3363))
        .def("ucsorg", &PyDbDatabase::ucsorg, DS.ARGS(3364))
        .def("UCSTableId", &PyDbDatabase::UCSTableId, DS.ARGS(3365))
        .def("ucsxdir", &PyDbDatabase::ucsxdir, DS.ARGS(3366))
        .def("ucsydir", &PyDbDatabase::ucsydir, DS.ARGS(3367))
        .def("undoRecording", &PyDbDatabase::undoRecording, DS.ARGS(3368))
        .def("unitmode", &PyDbDatabase::unitmode, DS.ARGS(3369))
        .def("updateDataLink", &PyDbDatabase::updateDataLink, DS.ARGS({ "nDir : UpdateDirection", "opt : UpdateOption" }, 3370))
        .def("updateExt", &PyDbDatabase::updateExt, DS.ARGS({ "val : bool" }, 3371))
        .def("updateThumbnail", &PyDbDatabase::updateThumbnail, DS.ARGS(3372))
        .def("useri1", &PyDbDatabase::useri1, DS.ARGS(3373))
        .def("useri2", &PyDbDatabase::useri2, DS.ARGS(3374))
        .def("useri3", &PyDbDatabase::useri3, DS.ARGS(3375))
        .def("useri4", &PyDbDatabase::useri4, DS.ARGS(3376))
        .def("useri5", &PyDbDatabase::useri5, DS.ARGS(3377))
        .def("userr1", &PyDbDatabase::userr1, DS.ARGS(3378))
        .def("userr2", &PyDbDatabase::userr2, DS.ARGS(3379))
        .def("userr3", &PyDbDatabase::userr3, DS.ARGS(3380))
        .def("userr4", &PyDbDatabase::userr4, DS.ARGS(3381))
        .def("userr5", &PyDbDatabase::userr5, DS.ARGS(3382))
        .def("usrtimer", &PyDbDatabase::usrtimer, DS.ARGS(3383))
        .def("viewportScaleDefault", &PyDbDatabase::viewportScaleDefault, DS.ARGS(3384))
        .def("viewportTableId", &PyDbDatabase::viewportTableId, DS.ARGS(3385))
        .def("viewTableId", &PyDbDatabase::viewTableId, DS.ARGS(3386))
        .def("visretain", &PyDbDatabase::visretain, DS.ARGS(3387))
        .def("visualStyleDictionaryId", &PyDbDatabase::visualStyleDictionaryId, DS.ARGS(3388))
        .def("worldPucsBaseOrigin", &PyDbDatabase::worldPucsBaseOrigin, DS.ARGS({ "view : OrthographicView" }, 3391))
        .def("worldUcsBaseOrigin", &PyDbDatabase::worldUcsBaseOrigin, DS.ARGS({ "view : OrthographicView" }, 3392))
        .def("worldview", &PyDbDatabase::worldview, DS.ARGS(3393))
        .def("xclipFrame", &PyDbDatabase::xclipFrame, DS.ARGS(3394))
        .def("xrefBlockId", &PyDbDatabase::xrefBlockId, DS.ARGS(3395))
        .def("xrefEditEnabled", &PyDbDatabase::xrefEditEnabled, DS.ARGS(3396))
        .def("wblockByRef", &PyDbDatabase::wblock1, DS.ARGS({ "dbByRef: PyDb.Database","ids: list[PyDb.ObjectId]"," basePoint : PyGe.Point3d","drc : PyDb.DuplicateRecordCloning" }, 19136))
        .def("wblock", &PyDbDatabase::wblock2)
        .def("wblock", &PyDbDatabase::wblock3)
        .def("wblock", &PyDbDatabase::wblock4, DS.OVRL(wblockOverloads, 3389))
        .def("abortDeepClone", &PyDbDatabase::abortDeepClone, DS.ARGS({ "idmap: PyDb.IdMapping" }, 2861))

        .def("deepCloneObjects", &PyDbDatabase::deepCloneObjects1)
        .def("deepCloneObjects", &PyDbDatabase::deepCloneObjects2,
            DS.ARGS({ "ids:list[PyDb.ObjectId]","owner:PyDb.ObjectId","idmap: PyDb.IdMapping","deferXlation:bool=False" }, 2913))

        .def("wblockCloneObjects", &PyDbDatabase::wblockCloneObjects1)
        .def("wblockCloneObjects", &PyDbDatabase::wblockCloneObjects2,
            DS.ARGS({ "ids:list[PyDb.ObjectId]","owner:PyDb.ObjectId","idmap: PyDb.IdMapping","drc: PyDb.DuplicateRecordCloning","deferXlation:bool=False" }, 3390))

        .def("getFilename", &PyDbDatabase::getFilename, DS.ARGS(2968))
        .def("readDwgFile", &PyDbDatabase::readDwgFile1)
        .def("readDwgFile", &PyDbDatabase::readDwgFile2,
            DS.ARGS({ "fileName: str", "mode: PyDb.DatabaseOpenMode=PyDb.DatabaseOpenMode.kForReadAndReadShare", "bAllowCPConversion:bool=False","password:str='empty'" }, 3116))

        .def("blockTableId", &PyDbDatabase::blockTableId, DS.ARGS(2878))
        .def("modelSpaceId", &PyDbDatabase::modelSpaceId, DS.ARGS())
        .def("currentSpaceId", &PyDbDatabase::currentSpaceId, DS.ARGS(2910))
        .def("purge", &PyDbDatabase::purge, DS.ARGS({ "ids: list[PyDb.ObjectId]" }, 3114))
        .def("purgeGraph", &PyDbDatabase::purgeGraph, DS.ARGS({ "ids: PyDb.ObjectIdGraph" }, 3114))
        .def("setCannoscale", &PyDbDatabase::setCannoscale, DS.ARGS({ "val : AnnotationScale" }, 3144))
        .def("setCecolor", &PyDbDatabase::setCecolor, DS.ARGS({ "val : Color" }, 3146))
        .def("setCetransparency", &PyDbDatabase::setCetransparency, DS.ARGS({ "val : Transparency" }, 3151))
        .def("setInterfereColor", &PyDbDatabase::setInterfereColor, DS.ARGS({ "val : Color" }, 3197))
        .def("className", &PyDbDatabase::className, DS.SARGS()).staticmethod("className")
        ;
}

//---------------------------------------------------------------------------------------------------
// PyDbDatabase
PyDbDatabase::PyDbDatabase()
    :PyDbDatabase(new AcDbDatabase(), true)
{
}

PyDbDatabase::PyDbDatabase(AcDbDatabase* _pDb)
    : PyDbDatabase(_pDb, false)
{
}

PyDbDatabase::PyDbDatabase(bool buildDefaultDrawing, bool noDocument)
    : PyDbDatabase(new AcDbDatabase(buildDefaultDrawing, noDocument), true)
{
}

PyDbDatabase::PyDbDatabase(AcDbDatabase* _pDb, bool autoDelete)
    : PyRxObject(_pDb, autoDelete, false)
{
}

PyAcadDatabase PyDbDatabase::acadDatabase() const
{
    return PyAcadDatabase{ impObj() };
}

PyDbObjectId PyDbDatabase::addToBlock1(const PyDbObjectId& id, PyDbEntity& ent) const
{
    AcDbBlockTableRecordPointer btr(id.m_id, AcDb::kForWrite);
    PyThrowBadEs(btr.openStatus());
    PyDbObjectId outid;
    PyThrowBadEs(btr->appendAcDbEntity(outid.m_id, ent.impObj()));
    return outid;
}

boost::python::list PyDbDatabase::addToBlock2(const PyDbObjectId& id, const boost::python::list& ents) const
{
    PyAutoLockGIL lock;
    boost::python::list ids;
    auto vec = std::vector<PyDbEntity>(boost::python::stl_input_iterator<PyDbEntity>(ents),
        boost::python::stl_input_iterator<PyDbEntity>());

    AcDbBlockTableRecordPointer btr(id.m_id, AcDb::kForWrite);
    PyThrowBadEs(btr.openStatus());

    for (const auto& ent : vec)
    {
        PyDbObjectId outid;
        PyThrowBadEs(btr->appendAcDbEntity(outid.m_id, ent.impObj()));
        ids.append(outid);
    }
    return ids;
}

PyDbObjectId PyDbDatabase::addToModelspace1(PyDbEntity& ent) const
{
    return addToBlock1(PyDbObjectId(acdbSymUtil()->blockModelSpaceId(impObj())), ent);
}

boost::python::list PyDbDatabase::addToModelspace2(const boost::python::list& ents) const
{
    return addToBlock2(PyDbObjectId(acdbSymUtil()->blockModelSpaceId(impObj())), ents);
}

PyDbObjectId PyDbDatabase::addToCurrentspace1(PyDbEntity& ent) const
{
    return addToBlock1(impObj()->currentSpaceId(), ent);
}

boost::python::list PyDbDatabase::addToCurrentspace2(const boost::python::list& ent) const
{
    return addToBlock2(impObj()->currentSpaceId(), ent);
}

PyDbObjectId PyDbDatabase::addAcDbObject(PyDbObject& obj) const
{
    PyDbObjectId id;
    PyThrowBadEs(impObj()->addAcDbObject(id.m_id, obj.impObj()));
    return id;
}

void PyDbDatabase::addReactor(PyDbDatabaseReactor& pReactor) const
{
    PyThrowBadEs(impObj()->addReactor(pReactor.impObj()));
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
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return impObj()->cameraDisplay();
#endif
}

double PyDbDatabase::cameraHeight() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return impObj()->cameraHeight();
#endif
}

Adesk::Int16 PyDbDatabase::cDynDisplayMode() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return impObj()->cDynDisplayMode();
#endif
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

std::string PyDbDatabase::classDxfName(const PyRxClass& pClass) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return wstr_to_utf8(impObj()->classDxfName(pClass.impObj()));
#endif
}

PyDbObjectId PyDbDatabase::clayer() const
{
    return PyDbObjectId(impObj()->clayer());
}

void PyDbDatabase::closeInput(bool bCloseFile) const
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

Adesk::UInt32 PyDbDatabase::countEmptyObjects(const Adesk::Int32 flags) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return impObj()->countEmptyObjects(flags);
#endif
}

Adesk::UInt32 PyDbDatabase::countHardReferences(const boost::python::list& pyids) const
{
    Adesk::UInt32 cnt = 0;
    PyThrowBadEs(impObj()->countHardReferences(PyListToObjectIdArray(pyids), &cnt));
    return cnt;
}

PyDbObjectId PyDbDatabase::detailViewStyle() const
{
#if defined(_BRXTARGET250)
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

void PyDbDatabase::disablePartialOpen() const
{
    impObj()->disablePartialOpen();
}

void PyDbDatabase::disableUndoRecording(bool disable) const
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
#if defined(_BRXTARGET250)
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
    return impObj()->dwgFileWasSavedByAutodeskSoftware();
}

void PyDbDatabase::dxfIn(const std::string& dxfFilename) const
{
    return PyThrowBadEs(impObj()->dxfIn(utf8_to_wstr(dxfFilename).c_str()));
}

void PyDbDatabase::dxfOut1(const std::string& dxfFilename) const
{
    return PyThrowBadEs(impObj()->dxfOut(utf8_to_wstr(dxfFilename).c_str()));
}

void PyDbDatabase::dxfOut2(const std::string& dxfFilename, int precision, AcDb::AcDbDwgVersion dwgVer, bool saveThumbnailImage) const
{
    return PyThrowBadEs(impObj()->dxfOut(utf8_to_wstr(dxfFilename).c_str(), precision, dwgVer, saveThumbnailImage));
}

double PyDbDatabase::elevation() const
{
    return impObj()->elevation();
}

Adesk::UInt32 PyDbDatabase::eraseEmptyObjects(const Adesk::Int32 flags) const
{
#if defined(_BRXTARGET250)
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

void PyDbDatabase::forceWblockDatabaseCopy() const
{
    impObj()->forceWblockDatabaseCopy();
}

PyDbDbLayerStateManager PyDbDatabase::getLayerStateManager() const
{
    return  PyDbDbLayerStateManager(impObj()->getLayerStateManager(), false);
}

std::string PyDbDatabase::geoCoordinateSystemId() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return wstr_to_utf8(impObj()->geoCoordinateSystemId());
#endif
}

bool PyDbDatabase::geoMarkerVisibility() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return impObj()->geoMarkerVisibility();
#endif
}

double PyDbDatabase::get3dDwfPrec() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return impObj()->get3dDwfPrec();
#endif
}

static std::vector<AcDbObjectId> getAllIdsFromDatabase(AcDbDatabase* pDb)
{
    std::vector<AcDbObjectId> ids;
    if (pDb == nullptr)
        return ids;
    ids.reserve(pDb->approxNumObjects());
    AcDbHandle hnd{ pDb->handseed() };
    AcDbHandle hndzero{ Adesk::UInt64(0) };
    while (hnd > hndzero)
    {
        AcDbObjectId id;
        if (pDb->getAcDbObjectId(id, false, hnd) == eOk)
        {
            if (id.isValid() && !id.isErased() && !id.isEffectivelyErased())
                ids.emplace_back(id);
        }
        hnd.decrement();
    }
    return ids;
}

static boost::python::list PyDbDatabaseObjectIds(AcDbDatabase* pDb, AcRxClass* pClass)
{
    PyAutoLockGIL lock;
    boost::python::list pyList;
    if (pClass == nullptr)
        return pyList;
    for (const auto& id : getAllIdsFromDatabase(pDb))
    {
        if (id.objectClass()->isDerivedFrom(pClass))
            pyList.append(PyDbObjectId{ id });
    }
    return pyList;
}

boost::python::list PyDbDatabase::objectIds() const
{
    return PyDbDatabaseObjectIds(impObj(), AcDbObject::desc());
}

boost::python::list PyDbDatabase::objectIdsOfType(const PyRxClass& _class) const
{
    PyAutoLockGIL lock;
    boost::python::list pyList;
    auto _desc = _class.impObj();
    for (const auto& id : getAllIdsFromDatabase(impObj()))
    {
        if (id.objectClass()->isDerivedFrom(_desc))
            pyList.append(PyDbObjectId{ id });
    }
    return pyList;
}

boost::python::list PyDbDatabase::objectIdsOfTypeList(const boost::python::list& _classes) const
{
    PyAutoLockGIL lock;
    boost::python::list pyList;
    std::unordered_set<AcRxClass*> _set;
    for (auto& item : py_list_to_std_vector<PyRxClass>(_classes))
    {
        _set.insert(item.impObj());
    }
    for (const auto& id : getAllIdsFromDatabase(impObj()))
    {
        if (_set.contains(id.objectClass()))
            pyList.append(PyDbObjectId{ id });
    }
    return pyList;
}

static PyDbObjectIdArray PyDbDatabaseObjectArray(AcDbDatabase* pDb, AcRxClass* pClass)
{
    PyDbObjectIdArray pyList;
    if (pClass == nullptr)
        return pyList;
    for (const auto& id : getAllIdsFromDatabase(pDb))
    {
        if (id.objectClass()->isDerivedFrom(pClass))
            pyList.push_back(PyDbObjectId{ id });
    }
    return pyList;
}

PyDbObjectIdArray PyDbDatabase::objectIdArray1() const
{
    return PyDbDatabaseObjectArray(impObj(), AcDbObject::desc());
}

PyDbObjectIdArray PyDbDatabase::objectIdArray2(const PyRxClass& _class) const
{
    PyDbObjectIdArray pyList;
    auto _desc = _class.impObj();
    for (const auto& id : getAllIdsFromDatabase(impObj()))
    {
        if (id.objectClass()->isDerivedFrom(_desc))
            pyList.push_back(PyDbObjectId{ id });
    }
    return pyList;
}

PyDbObjectIdArray PyDbDatabase::objectIdArray3(const boost::python::list& _classes) const
{
    PyDbObjectIdArray pyList;
    std::unordered_set<AcRxClass*> _set;
    for (auto& item : py_list_to_std_vector<PyRxClass>(_classes))
    {
        _set.insert(item.impObj());
    }
    for (const auto& id : getAllIdsFromDatabase(impObj()))
    {
        if (_set.contains(id.objectClass()))
            pyList.push_back(PyDbObjectId{ id });
    }
    return pyList;
}

PyDbObjectId PyDbDatabase::getAcDbObjectId1(bool createIfNotFound, const PyDbHandle& objHandle) const
{
    PyDbObjectId retId;
    PyThrowBadEs(impObj()->getAcDbObjectId(retId.m_id, createIfNotFound, objHandle.m_hnd));
    return retId;
}

PyDbObjectId PyDbDatabase::getAcDbObjectId2(bool createIfNotFound, const PyDbHandle& objHandle, Adesk::UInt32 xRefId) const
{
    PyDbObjectId retId;
    PyThrowBadEs(impObj()->getAcDbObjectId(retId.m_id, createIfNotFound, objHandle.m_hnd, xRefId));
    return retId;
}

PyDbObjectId PyDbDatabase::tryGetAcDbObjectId1(bool createIfNotFound, const PyDbHandle& objHandle) const
{
    PyDbObjectId retId;
    impObj()->getAcDbObjectId(retId.m_id, createIfNotFound, objHandle.m_hnd);
    return retId;
}

PyDbObjectId PyDbDatabase::tryGetAcDbObjectId2(bool createIfNotFound, const PyDbHandle& objHandle, Adesk::UInt32 xRefId) const
{
    PyDbObjectId retId;
    impObj()->getAcDbObjectId(retId.m_id, createIfNotFound, objHandle.m_hnd, xRefId);
    return retId;
}

AcDb::PlotStyleNameType PyDbDatabase::getCePlotStyleNameId(PyDbObjectId& id) const
{
    return impObj()->getCePlotStyleNameId(id.m_id);
}

bool PyDbDatabase::isAppRegistered(const std::string& pszAppName) const
{
#if defined(_ARXTARGET) && (_ARXTARGET >= 242)
    return impObj()->isAppRegistered(utf8_to_wstr(pszAppName).c_str());
#else
    AcDbObjectPointer<AcDbRegAppTable> pTable(impObj()->regAppTableId());
    PyThrowBadEs(pTable.openStatus());
    return pTable->has(utf8_to_wstr(pszAppName).c_str());
#endif
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

PyDbObjectId PyDbDatabase::getSectionManagerId() const
{
    return PyDbObjectId(impObj()->getSectionManager());
}

boost::python::list PyDbDatabase::getViewportArray1() const
{
    return getViewportArray2(true);
}

boost::python::list PyDbDatabase::getViewportArray2(bool bGetPaperspaceVports) const
{
    AcDbObjectIdArray vportIds;
    PyThrowBadEs(impObj()->getViewportArray(vportIds, bGetPaperspaceVports));
    return ObjectIdArrayToPyList(vportIds);
}

boost::python::list PyDbDatabase::getVisualStyleList() const
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

void PyDbDatabase::insert1(PyDbObjectId& blockId, const std::string& pBlockName, PyDbDatabase& db, bool preserveSourceDatabase) const
{
    return PyThrowBadEs(impObj()->insert(blockId.m_id, utf8_to_wstr(pBlockName).c_str(), db.impObj(), preserveSourceDatabase));
}

void PyDbDatabase::insert2(PyDbObjectId& blockId, const std::string& pSourceBlockName, const std::string& pDestinationBlockName, PyDbDatabase& db, bool preserveSourceDatabase) const
{
    return PyThrowBadEs(impObj()->insert(blockId.m_id, utf8_to_wstr(pSourceBlockName).c_str(), utf8_to_wstr(pDestinationBlockName).c_str(), db.impObj(), preserveSourceDatabase));
}

void PyDbDatabase::insert3(const AcGeMatrix3d& xform, PyDbDatabase& db, bool preserveSourceDatabase) const
{
    return PyThrowBadEs(impObj()->insert(xform, db.impObj(), preserveSourceDatabase));
}

Adesk::UInt8 PyDbDatabase::haloGap() const
{
#if defined(_BRXTARGET250)
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
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return impObj()->hasClass(pClass.impObj());
#endif
}

Adesk::UInt8 PyDbDatabase::hideText() const
{
#if defined(_BRXTARGET250)
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
#if defined(_BRXTARGET250)
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
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyDbObjectId(impObj()->interfereVpVisStyle());
#endif
}

Adesk::UInt16 PyDbDatabase::intersectColor() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return impObj()->intersectColor();
#endif
}

Adesk::UInt8 PyDbDatabase::intersectDisplay() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return impObj()->intersectDisplay();
#endif
}

bool PyDbDatabase::isBeingDestroyed() const
{
#if defined(_BRXTARGET250)
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
#if defined(_BRXTARGET250)
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
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return impObj()->layerEval();
#endif
}

Adesk::Int16 PyDbDatabase::layerNotify() const
{
#if defined(_BRXTARGET250)
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
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return impObj()->lensLength();
#endif
}

Adesk::UInt8 PyDbDatabase::lightGlyphDisplay() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return impObj()->lightGlyphDisplay();
#endif
}

Adesk::UInt8 PyDbDatabase::lightingUnits() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return impObj()->lightingUnits();
#endif
}

bool PyDbDatabase::lightsInBlocks() const
{
#if defined(_BRXTARGET250)
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

void PyDbDatabase::loadLineTypeFile(const std::string& ltn, const std::string& filename) const
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

void PyDbDatabase::registerApp(const std::string& pszAppName) const
{
#if defined(_ARXTARGET) && (_ARXTARGET >= 242)
    return PyThrowBadEs(impObj()->registerApp(utf8_to_wstr(pszAppName).c_str()));
#else
    PyThrowBadRt(acdbRegApp(utf8_to_wstr(pszAppName).c_str()));
#endif
}

int PyDbDatabase::maintenanceReleaseVersion() const
{
    return impObj()->maintenanceReleaseVersion();
}

void PyDbDatabase::markObjectNonPersistent(const PyDbObjectId& id, bool value)
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(AcDbDatabase::markObjectNonPersistent(id.m_id, value));
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
#if defined(_BRXTARGET250)
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
#if defined(_BRXTARGET250)
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

PyDbObjectContextManager PyDbDatabase::objectContextManager() const
{
    return PyDbObjectContextManager(impObj()->objectContextManager());
}

Adesk::UInt16 PyDbDatabase::obscuredColor() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return impObj()->obscuredColor();
#endif
}

Adesk::UInt8 PyDbDatabase::obscuredLineType() const
{
#if defined(_BRXTARGET250)
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
#if defined(_BRXTARGET250)
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
#if defined(_BRXTARGET250)
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
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return impObj()->psolHeight();
#endif
}

double PyDbDatabase::psolWidth() const
{
#if defined(_BRXTARGET250)
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

void PyDbDatabase::purgeGraph(PyObjectIdGraph& graph) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(impObj()->purge(*graph.impObj()));
#endif
}

boost::python::list PyDbDatabase::purge(const boost::python::list& pyids) const
{
    AcDbObjectIdArray ids = PyListToObjectIdArray(pyids);
    PyThrowBadEs(impObj()->purge(ids));
    return ObjectIdArrayToPyList(ids);
}

bool PyDbDatabase::qtextmode() const
{
    return impObj()->qtextmode();
}

void PyDbDatabase::reclaimMemoryFromErasedObjects(const boost::python::list& erasedObjects) const
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

void PyDbDatabase::removeReactor(PyDbDatabaseReactor& pReactor) const
{
    PyThrowBadEs(impObj()->removeReactor(pReactor.impObj()));
}

void PyDbDatabase::resetTimes() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->resetTimes());
#endif
}

void PyDbDatabase::restoreForwardingXrefSymbols() const
{
    return PyThrowBadEs(impObj()->restoreForwardingXrefSymbols());
}

void PyDbDatabase::restoreOriginalXrefSymbols() const
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
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyDbObjectId(impObj()->sectionViewStyle());
#endif
}

PyDbObjectId PyDbDatabase::sectionViewStyleDictionaryId() const
{
    return PyDbObjectId(impObj()->sectionViewStyleDictionaryId());
}

void PyDbDatabase::set3dDwfPrec(double DwfPrec) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->set3dDwfPrec(DwfPrec));
#endif
}

void PyDbDatabase::setAngbase(double angle) const
{
    return PyThrowBadEs(impObj()->setAngbase(angle));
}

void PyDbDatabase::setAngdir(bool dir) const
{
    return PyThrowBadEs(impObj()->setAngdir(dir));
}

void PyDbDatabase::setAnnoAllVisible(bool allvis) const
{
    return PyThrowBadEs(impObj()->setAnnoAllVisible(allvis));
}

void PyDbDatabase::setAttdia(bool dia) const
{
    return PyThrowBadEs(impObj()->setAttdia(dia));
}

void PyDbDatabase::setAttmode(Adesk::Int16 mode) const
{
    return PyThrowBadEs(impObj()->setAttmode(mode));
}

void PyDbDatabase::setAttreq(bool req) const
{
    return PyThrowBadEs(impObj()->setAttreq(req));
}

void PyDbDatabase::setAunits(Adesk::Int16 aunits) const
{
    return PyThrowBadEs(impObj()->setAunits(aunits));
}

void PyDbDatabase::setAuprec(Adesk::Int16 auprec) const
{
    return PyThrowBadEs(impObj()->setAuprec(auprec));
}

void PyDbDatabase::setBlipmode(bool mode) const
{
    return PyThrowBadEs(impObj()->setBlipmode(mode));
}

void PyDbDatabase::setCameraDisplay(bool cameraDisplay) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setCameraDisplay(cameraDisplay));
#endif
}

void PyDbDatabase::setCameraHeight(double cameraHeight) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setCameraHeight(cameraHeight));
#endif
}

void PyDbDatabase::setCannoscale(PyDbAnnotationScale& val) const
{
    return PyThrowBadEs(impObj()->setCannoscale(val.impObj()));
}

void PyDbDatabase::setCDynDisplayMode(Adesk::Int16 val) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setCDynDisplayMode(val));
#endif
}

void PyDbDatabase::setCecolor(const AcCmColor& color) const
{
    return PyThrowBadEs(impObj()->setCecolor(color));
}

void PyDbDatabase::setCeltscale(double scale) const
{
    return PyThrowBadEs(impObj()->setCeltscale(scale));
}

void PyDbDatabase::setCeltype(const PyDbObjectId& id) const
{
    return PyThrowBadEs(impObj()->setCeltype(id.m_id));
}

void PyDbDatabase::setCelweight(AcDb::LineWeight weight) const
{
    return PyThrowBadEs(impObj()->setCelweight(weight));
}

void PyDbDatabase::setCePlotStyleName(AcDb::PlotStyleNameType type, const PyDbObjectId& id) const
{
    return PyThrowBadEs(impObj()->setCePlotStyleName(type, id.m_id));
}

void PyDbDatabase::setCetransparency(const AcCmTransparency& transparency) const
{
    return PyThrowBadEs(impObj()->setCetransparency(transparency));
}

void PyDbDatabase::setChamfera(double val) const
{
    return PyThrowBadEs(impObj()->setChamfera(val));
}

void PyDbDatabase::setChamferb(double val) const
{
    return PyThrowBadEs(impObj()->setChamferb(val));
}

void PyDbDatabase::setChamferc(double val) const
{
    return PyThrowBadEs(impObj()->setChamferc(val));
}

void PyDbDatabase::setChamferd(double val) const
{
    return PyThrowBadEs(impObj()->setChamferd(val));
}

void PyDbDatabase::setClayer(const PyDbObjectId& id) const
{
    return PyThrowBadEs(impObj()->setClayer(id.m_id));
}

void PyDbDatabase::setCmaterial(const PyDbObjectId& id) const
{
    return PyThrowBadEs(impObj()->setCmaterial(id.m_id));
}

void PyDbDatabase::setCmljust(Adesk::Int16 just) const
{
    return PyThrowBadEs(impObj()->setCmljust(just));
}

void PyDbDatabase::setCmlscale(double scale) const
{
    return PyThrowBadEs(impObj()->setCmlscale(scale));
}

void PyDbDatabase::setCmlstyleID(const PyDbObjectId& id) const
{
    return PyThrowBadEs(impObj()->setCmlstyleID(id.m_id));
}

void PyDbDatabase::setCoords(Adesk::Int16 _coords) const
{
    return PyThrowBadEs(impObj()->setCoords(_coords));
}

void PyDbDatabase::setCshadow(Adesk::UInt8 val) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setCshadow(val));
#endif
}

void PyDbDatabase::setDelUsedObj(Adesk::Int16 deleteObj) const
{
    return PyThrowBadEs(impObj()->setDelUsedObj(deleteObj));
}

void PyDbDatabase::setDgnframe(Adesk::UInt8 val) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setDgnframe(val));
#endif
}

void PyDbDatabase::setDimaso(bool aso) const
{
    return PyThrowBadEs(impObj()->setDimaso(aso));
}

void PyDbDatabase::setDimAssoc(Adesk::UInt8 val) const
{
    return PyThrowBadEs(impObj()->setDimAssoc(val));
}

void PyDbDatabase::setDimfit(int fit) const
{
    return PyThrowBadEs(impObj()->setDimfit(fit));
}

void PyDbDatabase::setDimsho(bool sho) const
{
    return PyThrowBadEs(impObj()->setDimsho(sho));
}

void PyDbDatabase::setDimstyle(const PyDbObjectId& id) const
{
    return PyThrowBadEs(impObj()->setDimstyle(id.m_id));
}

void PyDbDatabase::setDimstyleData1(PyDbDimStyleTableRecord& pRec) const
{
    return PyThrowBadEs(impObj()->setDimstyleData(pRec.impObj()));
}

void PyDbDatabase::setDimstyleData2(const PyDbObjectId& id) const
{
    return PyThrowBadEs(impObj()->setDimstyleData(id.m_id));
}

void PyDbDatabase::setDimunit(int unit) const
{
    return PyThrowBadEs(impObj()->setDimunit(unit));
}

void PyDbDatabase::setDispSilh(bool silh) const
{
    return PyThrowBadEs(impObj()->setDispSilh(silh));
}

void PyDbDatabase::setDragmode(Adesk::Int16 mode) const
{
    return PyThrowBadEs(impObj()->setDragmode(mode));
}

void PyDbDatabase::setDragVisStyle(const PyDbObjectId& id) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setDragVisStyle(id.m_id));
#endif
}

void PyDbDatabase::setDrawOrderCtl(Adesk::UInt8 val) const
{
    return PyThrowBadEs(impObj()->setDrawOrderCtl(val));
}

void PyDbDatabase::setDwfframe(Adesk::UInt8 val) const
{
    return PyThrowBadEs(impObj()->setDwfframe(val));
}

void PyDbDatabase::setElevation(double elev) const
{
    return PyThrowBadEs(impObj()->setElevation(elev));
}

void PyDbDatabase::setEndCaps(AcDb::EndCaps type) const
{
    return PyThrowBadEs(impObj()->setEndCaps(type));
}

void PyDbDatabase::setExtmax(const AcGePoint3d& max) const
{
    return PyThrowBadEs(impObj()->setExtmax(max));
}

void PyDbDatabase::setExtmin(const AcGePoint3d& min) const
{
    return PyThrowBadEs(impObj()->setExtmin(min));
}

void PyDbDatabase::setFacetres(double _facetres) const
{
    return PyThrowBadEs(impObj()->setFacetres(_facetres));
}

void PyDbDatabase::setFilletrad(double radius) const
{
    return PyThrowBadEs(impObj()->setFilletrad(radius));
}

void PyDbDatabase::setFillmode(bool mode) const
{
    return PyThrowBadEs(impObj()->setFillmode(mode));
}

void PyDbDatabase::saveAs1(const std::string& fileName) const
{
    return PyThrowBadEs(impObj()->saveAs(utf8_to_wstr(fileName).c_str()));
}

void PyDbDatabase::saveAs2(const std::string& fileName, const bool bBakAndRename, const AcDb::AcDbDwgVersion dwgVer) const
{
    return PyThrowBadEs(impObj()->saveAs(utf8_to_wstr(fileName).c_str(), bBakAndRename, dwgVer));
}

void PyDbDatabase::setFingerprintGuid(const std::string& newGuid) const
{
    return PyThrowBadEs(impObj()->setFingerprintGuid(utf8_to_wstr(newGuid).c_str()));
}

void PyDbDatabase::setFullSaveRequired() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    impObj()->setFullSaveRequired();
#endif
}

void PyDbDatabase::readDwgFile1(const char* fileName) const
{
    std::wstring wsfileName{ utf8_to_wstr(fileName) };
    return PyThrowBadEs(impObj()->readDwgFile(wsfileName.c_str()));
}

void PyDbDatabase::readDwgFile2(const char* fileName, int mode, bool bAllowCPConversion, const std::string& password) const
{
    std::wstring wsfileName{ utf8_to_wstr(fileName) };
    std::wstring wspassword{ utf8_to_wstr(password) };
    return PyThrowBadEs(impObj()->readDwgFile(wsfileName.c_str(), (AcDbDatabase::OpenMode)mode, bAllowCPConversion, wspassword.c_str()));
}

std::string PyDbDatabase::getFilename() const
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

void PyDbDatabase::setGeoMarkerVisibility(bool value) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setGeoMarkerVisibility(value));
#endif
}

void PyDbDatabase::setHaloGap(Adesk::UInt8 val) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setHaloGap(val));
#endif
}

void PyDbDatabase::setHandseed(const PyDbHandle& handle) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setHandseed(handle.m_hnd));
#endif
}

void PyDbDatabase::setHideText(Adesk::UInt8 val) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setHideText(val));
#endif
}

void PyDbDatabase::setHpInherit(const bool inherit) const
{
    return PyThrowBadEs(impObj()->setHpInherit(inherit));
}

void PyDbDatabase::setHpOrigin(const AcGePoint2d& origin) const
{
    return PyThrowBadEs(impObj()->setHpOrigin(origin));
}

void PyDbDatabase::setHyperlinkBase(const std::string& val) const
{
    return PyThrowBadEs(impObj()->setHyperlinkBase(utf8_to_wstr(val).c_str()));
}

void PyDbDatabase::setIndexctl(Adesk::UInt8 val) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setIndexctl(val));
#endif
}

void PyDbDatabase::setInsbase(const AcGePoint3d& base) const
{
    return PyThrowBadEs(impObj()->setInsbase(base));
}

void PyDbDatabase::setInsunits(const AcDb::UnitsValue units) const
{
    return PyThrowBadEs(impObj()->setInsunits(units));
}

void PyDbDatabase::setInterfereColor(const AcCmColor& color) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setInterfereColor(color));
#endif
}

void PyDbDatabase::setInterfereObjVisStyle(const PyDbObjectId& id) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setInterfereObjVisStyle(id.m_id));
#endif
}

void PyDbDatabase::setInterfereVpVisStyle(const PyDbObjectId& id) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setInterfereVpVisStyle(id.m_id));
#endif
}

void PyDbDatabase::setIntersectColor(Adesk::UInt16 val) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setIntersectColor(val));
#endif
}

void PyDbDatabase::setIntersectDisplay(Adesk::UInt8 val) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setIntersectDisplay(val));
#endif
}

void PyDbDatabase::setIsolines(Adesk::Int16 isolines) const
{
    return PyThrowBadEs(impObj()->setIsolines(isolines));
}

void PyDbDatabase::setJoinStyle(AcDb::JoinStyle style) const
{
    return PyThrowBadEs(impObj()->setJoinStyle(style));
}

void PyDbDatabase::setLatitude(double lat) const
{
    return PyThrowBadEs(impObj()->setLatitude(lat));
}

void PyDbDatabase::setLayerEval(Adesk::UInt8 val) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setLayerEval(val));
#endif
}

void PyDbDatabase::setLayerNotify(Adesk::Int16 val) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setLayerNotify(val));
#endif
}

void PyDbDatabase::setLensLength(const double _lensLength) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setLensLength(_lensLength));
#endif
}

void PyDbDatabase::setLightGlyphDisplay(Adesk::UInt8 val) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setLightGlyphDisplay(val));
#endif
}

void PyDbDatabase::setLightingUnits(Adesk::UInt8 val) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setLightingUnits(val));
#endif
}

void PyDbDatabase::setLightsInBlocks(bool val) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setLightsInBlocks(val));
#endif
}

void PyDbDatabase::setLimcheck(bool check) const
{
    return PyThrowBadEs(impObj()->setLimcheck(check));
}

void PyDbDatabase::setLimmax(const AcGePoint2d& max) const
{
    return PyThrowBadEs(impObj()->setLimmax(max));
}

void PyDbDatabase::setLimmin(const AcGePoint2d& min) const
{
    return PyThrowBadEs(impObj()->setLimmin(min));
}

void PyDbDatabase::setLineWeightDisplay(bool display) const
{
    return PyThrowBadEs(impObj()->setLineWeightDisplay(display));
}

void PyDbDatabase::setLoftAng1(double ang1) const
{
    return PyThrowBadEs(impObj()->setLoftAng1(ang1));
}

void PyDbDatabase::setLoftAng2(double ang2) const
{
    return PyThrowBadEs(impObj()->setLoftAng2(ang2));
}

void PyDbDatabase::setLoftMag1(double mag1) const
{
    return PyThrowBadEs(impObj()->setLoftMag1(mag1));
}

void PyDbDatabase::setLoftMag2(double mag2) const
{
    return PyThrowBadEs(impObj()->setLoftMag2(mag2));
}

void PyDbDatabase::setLoftNormals(Adesk::UInt8 value) const
{
    return PyThrowBadEs(impObj()->setLoftNormals(value));
}

void PyDbDatabase::setLoftParam(Adesk::UInt16 flags) const
{
    return PyThrowBadEs(impObj()->setLoftParam(flags));
}

void PyDbDatabase::setLongitude(double lng) const
{
    return PyThrowBadEs(impObj()->setLongitude(lng));
}

void PyDbDatabase::setLtscale(double scale) const
{
    return PyThrowBadEs(impObj()->setLtscale(scale));
}

void PyDbDatabase::setLunits(Adesk::Int16 lunits) const
{
    return PyThrowBadEs(impObj()->setLunits(lunits));
}

void PyDbDatabase::setLuprec(Adesk::Int16 prec) const
{
    return PyThrowBadEs(impObj()->setLuprec(prec));
}

void PyDbDatabase::setMaxactvp(Adesk::Int16 max) const
{
    return PyThrowBadEs(impObj()->setMaxactvp(max));
}

void PyDbDatabase::setMeasurement(AcDb::MeasurementValue type) const
{
    return PyThrowBadEs(impObj()->setMeasurement(type));
}

void PyDbDatabase::setMirrtext(bool mirror) const
{
    return PyThrowBadEs(impObj()->setMirrtext(mirror));
}

void PyDbDatabase::setMLeaderscale(double scale) const
{
    return PyThrowBadEs(impObj()->setMLeaderscale(scale));
}

void PyDbDatabase::setMLeaderstyle(const PyDbObjectId& objId) const
{
    return PyThrowBadEs(impObj()->setMLeaderstyle(objId.m_id));
}

void PyDbDatabase::setMsltscale(bool val) const
{
    return PyThrowBadEs(impObj()->setMsltscale(val));
}

void PyDbDatabase::setMsOleScale(double val) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setMsOleScale(val));
#endif
}

void PyDbDatabase::setNorthDirection(double northdir) const
{
    return PyThrowBadEs(impObj()->setNorthDirection(northdir));
}

void PyDbDatabase::setObscuredColor(Adesk::UInt16 val) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setObscuredColor(val));
#endif
}

void PyDbDatabase::setObscuredLineType(Adesk::UInt8 val) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setObscuredLineType(val));
#endif
}

void PyDbDatabase::setOleStartUp(bool val) const
{
    return PyThrowBadEs(impObj()->setOleStartUp(val));
}

void PyDbDatabase::setOrthomode(bool mode) const
{
    return PyThrowBadEs(impObj()->setOrthomode(mode));
}

void PyDbDatabase::setPdfframe(Adesk::Int8 val) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setPdfframe(val));
#endif
}

void PyDbDatabase::setPdmode(Adesk::Int16 mode) const
{
    return PyThrowBadEs(impObj()->setPdmode(mode));
}

void PyDbDatabase::setPdsize(double size) const
{
    return PyThrowBadEs(impObj()->setPdsize(size));
}

void PyDbDatabase::setPelevation(double elev) const
{
    return PyThrowBadEs(impObj()->setPelevation(elev));
}

void PyDbDatabase::setPextmax(const AcGePoint3d& max) const
{
    return PyThrowBadEs(impObj()->setPextmax(max));
}

void PyDbDatabase::setPextmin(const AcGePoint3d& min) const
{
    return PyThrowBadEs(impObj()->setPextmin(min));
}

void PyDbDatabase::setPickstyle(Adesk::Int16 style) const
{
    return PyThrowBadEs(impObj()->setPickstyle(style));
}

void PyDbDatabase::setPinsbase(const AcGePoint3d& base) const
{
    return PyThrowBadEs(impObj()->setPinsbase(base));
}

void PyDbDatabase::setPlimcheck(bool check) const
{
    return PyThrowBadEs(impObj()->setPlimcheck(check));
}

void PyDbDatabase::setPlimmax(const AcGePoint2d& max) const
{
    return PyThrowBadEs(impObj()->setPlimmax(max));
}

void PyDbDatabase::setPlimmin(const AcGePoint2d& min) const
{
    return PyThrowBadEs(impObj()->setPlimmin(min));
}

void PyDbDatabase::setPlineEllipse(bool pline) const
{
    return PyThrowBadEs(impObj()->setPlineEllipse(pline));
}

void PyDbDatabase::setPlinegen(bool gen) const
{
    return PyThrowBadEs(impObj()->setPlinegen(gen));
}

void PyDbDatabase::setPlinewid(double width) const
{
    return PyThrowBadEs(impObj()->setPlinewid(width));
}

void PyDbDatabase::setPreviewType(Adesk::Int16 val) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setPreviewType(val));
#endif
}

void PyDbDatabase::setProjectName(const std::string& val) const
{
    return PyThrowBadEs(impObj()->setProjectName(utf8_to_wstr(val).c_str()));
}

void PyDbDatabase::setPsltscale(bool scale) const
{
    return PyThrowBadEs(impObj()->setPsltscale(scale));
}

void PyDbDatabase::setPsolHeight(double height) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setPsolHeight(height));
#endif
}

void PyDbDatabase::setPsolWidth(double width) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setPsolWidth(width));
#endif
}

void PyDbDatabase::setPucs(const AcGePoint3d& ucsOrigin, const AcGeVector3d& ucsXDir, const AcGeVector3d& ucsYDir) const
{
    return PyThrowBadEs(impObj()->setPucs(ucsOrigin, ucsXDir, ucsYDir));
}

void PyDbDatabase::setPucsBase(const PyDbObjectId& ucsid) const
{
    return PyThrowBadEs(impObj()->setPucsBase(ucsid.m_id));
}

void PyDbDatabase::setPucsname(const PyDbObjectId& ucsRecId) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setPucsname(ucsRecId.m_id));
#endif
}

void PyDbDatabase::setQtextmode(bool mode) const
{
    return PyThrowBadEs(impObj()->setQtextmode(mode));
}

void PyDbDatabase::setRealWorldScale(const bool realWorldScale) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setRealWorldScale(realWorldScale));
#endif
}

void PyDbDatabase::setRegenmode(bool mode) const
{
    return PyThrowBadEs(impObj()->setRegenmode(mode));
}

void PyDbDatabase::setRetainOriginalThumbnailBitmap(bool retain) const
{
    return impObj()->setRetainOriginalThumbnailBitmap(retain);
}

void PyDbDatabase::setSaveproxygraphics(Adesk::Int16 saveimg) const
{
    return PyThrowBadEs(impObj()->setSaveproxygraphics(saveimg));
}

void PyDbDatabase::setSectionViewStyle(const PyDbObjectId& objId) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setSectionViewStyle(objId.m_id));
#endif
}

void PyDbDatabase::setShadedge(Adesk::Int16 mode) const
{
    return PyThrowBadEs(impObj()->setShadedge(mode));
}

void PyDbDatabase::setShadedif(Adesk::Int16 dif) const
{
    return PyThrowBadEs(impObj()->setShadedif(dif));
}

void PyDbDatabase::setShadowPlaneLocation(double val) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setShadowPlaneLocation(val));
#endif
}

void PyDbDatabase::setShowHist(Adesk::UInt8 val) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setShowHist(val));
#endif
}

void PyDbDatabase::setSketchinc(double inc) const
{
    return PyThrowBadEs(impObj()->setSketchinc(inc));
}

void PyDbDatabase::setSkpoly(bool asPoly) const
{
    return PyThrowBadEs(impObj()->setSkpoly(asPoly));
}

void PyDbDatabase::setSolidHist(Adesk::UInt8 val) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setSolidHist(val));
#endif
}

void PyDbDatabase::setSortEnts(Adesk::UInt8 sortEnts) const
{
    return PyThrowBadEs(impObj()->setSortEnts(sortEnts));
}

void PyDbDatabase::setSplframe(bool disp) const
{
    return PyThrowBadEs(impObj()->setSplframe(disp));
}

void PyDbDatabase::setSplinesegs(Adesk::Int16 segs) const
{
    return PyThrowBadEs(impObj()->setSplinesegs(segs));
}

void PyDbDatabase::setSplinetype(Adesk::Int16 type) const
{
    return PyThrowBadEs(impObj()->setSplinetype(type));
}

void PyDbDatabase::setStepSize(double stepSize) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setStepSize(stepSize));
#endif
}

void PyDbDatabase::setStepsPerSec(double stepsPerSec) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setStepsPerSec(stepsPerSec));
#endif
}

void PyDbDatabase::setStyleSheet(const std::string& val) const
{
    return PyThrowBadEs(impObj()->setStyleSheet(utf8_to_wstr(val).c_str()));
}

void PyDbDatabase::setSurftab1(Adesk::Int16 tab1) const
{
    return PyThrowBadEs(impObj()->setSurftab1(tab1));
}

void PyDbDatabase::setSurftab2(Adesk::Int16 tab2) const
{
    return PyThrowBadEs(impObj()->setSurftab2(tab2));
}

void PyDbDatabase::setSurftype(Adesk::Int16 type) const
{
    return PyThrowBadEs(impObj()->setSurftype(type));
}

void PyDbDatabase::setSurfu(Adesk::Int16 v) const
{
    return PyThrowBadEs(impObj()->setSurfu(v));
}

void PyDbDatabase::setSurfv(Adesk::Int16 v) const
{
    return PyThrowBadEs(impObj()->setSurfv(v));
}

void PyDbDatabase::setTablestyle(const PyDbObjectId& objId) const
{
    return PyThrowBadEs(impObj()->setTablestyle(objId.m_id));
}

void PyDbDatabase::setTextsize(double size) const
{
    return PyThrowBadEs(impObj()->setTextsize(size));
}

void PyDbDatabase::setTextstyle(const PyDbObjectId& objId) const
{
    return PyThrowBadEs(impObj()->setTextstyle(objId.m_id));
}

void PyDbDatabase::setThickness(double thickness) const
{
    return PyThrowBadEs(impObj()->setThickness(thickness));
}

void PyDbDatabase::setTilemode(bool mode) const
{
    return PyThrowBadEs(impObj()->setTilemode(mode));
}

void PyDbDatabase::setTimeZone(AcDb::TimeZone tz) const
{
    return PyThrowBadEs(impObj()->setTimeZone(tz));
}

void PyDbDatabase::setTimeZoneAsUtcOffset(double offset) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setTimeZoneAsUtcOffset(offset));
#endif
}

void PyDbDatabase::setTracewid(double width) const
{
    return PyThrowBadEs(impObj()->setTracewid(width));
}

void PyDbDatabase::setTreedepth(Adesk::Int16 depth) const
{
    return PyThrowBadEs(impObj()->setTreedepth(depth));
}

void PyDbDatabase::setTStackAlign(int val) const
{
    return PyThrowBadEs(impObj()->setTStackAlign(val));
}

void PyDbDatabase::setTStackSize(int val) const
{
    return PyThrowBadEs(impObj()->setTStackSize(val));
}

void PyDbDatabase::setUcs(const AcGePoint3d& ucsOrigin, const AcGeVector3d& ucsXDir, const AcGeVector3d& ucsYDir) const
{
    return PyThrowBadEs(impObj()->setUcs(ucsOrigin, ucsXDir, ucsYDir));
}

void PyDbDatabase::setUcsBase(const PyDbObjectId& ucsid) const
{
    return PyThrowBadEs(impObj()->setUcsBase(ucsid.m_id));
}

void PyDbDatabase::setUcsname(const PyDbObjectId& ucsRecId) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setUcsname(ucsRecId.m_id));
#endif
}

void PyDbDatabase::setUnitmode(Adesk::Int16 mode) const
{
    return PyThrowBadEs(impObj()->setUnitmode(mode));
}

void PyDbDatabase::setUpdateThumbnail(Adesk::UInt8 val) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setUpdateThumbnail(val));
#endif
}

void PyDbDatabase::setUseri1(Adesk::Int16 val) const
{
    return PyThrowBadEs(impObj()->setUseri1(val));
}

void PyDbDatabase::setUseri2(Adesk::Int16 val) const
{
    return PyThrowBadEs(impObj()->setUseri2(val));
}

void PyDbDatabase::setUseri3(Adesk::Int16 val) const
{
    return PyThrowBadEs(impObj()->setUseri3(val));
}

void PyDbDatabase::setUseri4(Adesk::Int16 val) const
{
    return PyThrowBadEs(impObj()->setUseri4(val));
}

void PyDbDatabase::setUseri5(Adesk::Int16 val) const
{
    return PyThrowBadEs(impObj()->setUseri5(val));
}

void PyDbDatabase::setUserr1(double val) const
{
    return PyThrowBadEs(impObj()->setUserr1(val));
}

void PyDbDatabase::setUserr2(double val) const
{
    return PyThrowBadEs(impObj()->setUserr2(val));
}

void PyDbDatabase::setUserr3(double val) const
{
    return PyThrowBadEs(impObj()->setUserr3(val));
}

void PyDbDatabase::setUserr4(double val) const
{
    return PyThrowBadEs(impObj()->setUserr4(val));
}

void PyDbDatabase::setUserr5(double val) const
{
    return PyThrowBadEs(impObj()->setUserr5(val));
}

void PyDbDatabase::setUsrtimer(bool timer) const
{
    return PyThrowBadEs(impObj()->setUsrtimer(timer));
}

void PyDbDatabase::setVersionGuid(const std::string& pNewGuid) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setVersionGuid(utf8_to_wstr(pNewGuid).c_str()));
#endif
}

void PyDbDatabase::setViewportScaleDefault(double newDefaultVPScale) const
{
    return PyThrowBadEs(impObj()->setVisretain(newDefaultVPScale));
}

void PyDbDatabase::setVisretain(bool retain) const
{
    return PyThrowBadEs(impObj()->setVisretain(retain));
}

void PyDbDatabase::setWorldPucsBaseOrigin(const AcGePoint3d& origin, AcDb::OrthographicView orthoView) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setWorldPucsBaseOrigin(origin, orthoView));
#endif
}

void PyDbDatabase::setWorldUcsBaseOrigin(const AcGePoint3d& origin, AcDb::OrthographicView orthoView) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setWorldUcsBaseOrigin(origin, orthoView));
#endif
}

void PyDbDatabase::setWorldview(bool view) const
{
    return PyThrowBadEs(impObj()->setWorldview(view));
}

void PyDbDatabase::setXclipFrame(Adesk::UInt8 disp) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setXclipFrame(disp));
#endif
}

void PyDbDatabase::setXrefEditEnabled(bool enable) const
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
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return impObj()->shadowPlaneLocation();
#endif
}

Adesk::UInt8 PyDbDatabase::showHist() const
{
#if defined(_BRXTARGET250)
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
#if defined(_BRXTARGET250)
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
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return impObj()->stepSize();
#endif
}

double PyDbDatabase::stepsPerSec() const
{
#if defined(_BRXTARGET250)
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

PyDbDate PyDbDatabase::tdcreate() const
{
    return PyDbDate(impObj()->tdcreate());
}

PyDbDate PyDbDatabase::tdindwg() const
{
    return PyDbDate(impObj()->tdindwg());
}

PyDbDate PyDbDatabase::tducreate() const
{
    return PyDbDate(impObj()->tducreate());
}

PyDbDate PyDbDatabase::tdupdate() const
{
    return PyDbDate(impObj()->tdupdate());
}

PyDbDate PyDbDatabase::tdusrtimer() const
{
    return PyDbDate(impObj()->tdusrtimer());
}

PyDbDate PyDbDatabase::tduupdate() const
{
    return PyDbDate(impObj()->tduupdate());
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
#if defined(_BRXTARGET250)
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

void PyDbDatabase::updateDataLink(AcDb::UpdateDirection nDir, AcDb::UpdateOption nOption) const
{
    return PyThrowBadEs(impObj()->updateDataLink(nDir, nOption));
}

void PyDbDatabase::updateExt(bool doBestFit) const
{
    return PyThrowBadEs(impObj()->updateExt(doBestFit));
}

Adesk::UInt8 PyDbDatabase::updateThumbnail() const
{
#if defined(_BRXTARGET250)
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

void PyDbDatabase::deepCloneObjects1(const boost::python::list& objectIds, const PyDbObjectId& owner, PyDbIdMapping& idMap) const
{
    PyThrowBadEs(impObj()->deepCloneObjects(PyListToObjectIdArray(objectIds), owner.m_id, *idMap.impObj()));
}

void PyDbDatabase::deepCloneObjects2(const boost::python::list& objectIds, const PyDbObjectId& owner, PyDbIdMapping& idMap, bool deferXlation) const
{
    PyThrowBadEs(impObj()->deepCloneObjects(PyListToObjectIdArray(objectIds), owner.m_id, *idMap.impObj(), deferXlation));
}

void PyDbDatabase::wblockCloneObjects1(const boost::python::list& objectIds,
    const PyDbObjectId& owner, PyDbIdMapping& idMap, AcDb::DuplicateRecordCloning drc) const
{
    PyThrowBadEs(impObj()->wblockCloneObjects(PyListToObjectIdArray(objectIds), owner.m_id, *idMap.impObj(), drc));
}

void PyDbDatabase::wblockCloneObjects2(const boost::python::list& objectIds,
    const PyDbObjectId& owner, PyDbIdMapping& idMap, AcDb::DuplicateRecordCloning drc, bool deferXlation) const
{
    PyThrowBadEs(impObj()->wblockCloneObjects(PyListToObjectIdArray(objectIds), owner.m_id, *idMap.impObj(), drc, deferXlation));
}

void PyDbDatabase::wblock1(PyDbDatabase& pOutputDb, const boost::python::list& outObjIds, const AcGePoint3d& basePoint, AcDb::DuplicateRecordCloning drc) const
{
    AcDbObjectIdArray ids = PyListToObjectIdArray(outObjIds);
    PyThrowBadEs(impObj()->wblock(pOutputDb.impObj(), ids, basePoint, drc));
}

PyDbDatabase PyDbDatabase::wblock2(const boost::python::list& outObjIds, const AcGePoint3d& basePoint) const
{
    AcDbObjectIdArray ids = PyListToObjectIdArray(outObjIds);
    AcDbDatabase* _pOutputDb = nullptr;
    PyThrowBadEs(impObj()->wblock(_pOutputDb, ids, basePoint));
    return PyDbDatabase(_pOutputDb, true);
}

PyDbDatabase PyDbDatabase::wblock3(const PyDbObjectId& blockId) const
{
    AcDbDatabase* _pOutputDb = nullptr;
    PyThrowBadEs(impObj()->wblock(_pOutputDb, blockId.m_id));
    return PyDbDatabase(_pOutputDb, true);
}

PyDbDatabase PyDbDatabase::wblock4() const
{
    AcDbDatabase* _pOutputDb = nullptr;
    PyThrowBadEs(impObj()->wblock(_pOutputDb));
    return PyDbDatabase(_pOutputDb, true);
}

void PyDbDatabase::abortDeepClone(PyDbIdMapping& idMap) const
{
    impObj()->abortDeepClone(*idMap.impObj());
}

AcGePoint3d PyDbDatabase::worldPucsBaseOrigin(AcDb::OrthographicView orthoView) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return impObj()->worldPucsBaseOrigin(orthoView);
#endif
}

AcGePoint3d PyDbDatabase::worldUcsBaseOrigin(AcDb::OrthographicView orthoView) const
{
#if defined(_BRXTARGET250)
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
#if defined(_BRXTARGET250)
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
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbDatabase*>(m_pyImp.get());
}


