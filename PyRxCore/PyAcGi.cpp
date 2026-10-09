#include "stdafx.h"
#include "PyAcGi.h"
#include "PyGiDrawable.h"
#include "PyGiCommonDraw.h"
#include "PyGiSubEntityTraits.h"
#include "PyGiTransientManager.h"
#include "PyGiGraphicsKernel.h"
#include "PyGiParameter.h"

#include <boost/python/suite/indexing/vector_indexing_suite.hpp>


using namespace boost::python;

//---------------------------------------------------------------------------------
// PyGiPixelBGRA32Array::createFromWxImage
static PyGiPixelBGRA32Array createFromWxImage2(const boost::python::object& image, Adesk::UInt8 alpha)
{
    PyGiPixelBGRA32Array arr;
    wxImage* wximage = nullptr;// we are NOT the owner!
    if (!wxPyConvertWrappedPtr(image.ptr(), (void**)&wximage, wxT("wxImage")))
        return arr;
    if (!wximage->IsOk())
        return arr;
    AcGiImageBGRA32Package _image(*wximage, alpha);
    std::swap(arr, _image._pixelData);
    return std::move(arr);
}

static PyGiPixelBGRA32Array createFromWxImage1(const boost::python::object& image)
{
    return createFromWxImage2(image, 255);
}


BOOST_PYTHON_MODULE(PyGi)
{
    docstring_options local_docstring_options(py_show_user_defined, py_show_py_signatures, py_show_cpp_signatures);

    makePyGiObjectWrapper();
    makePyGiCommonDrawWrapper();
    makePyGiWorldDrawWrapper();
    makePyGiViewportDrawWrapper();
    makePyGiDrawableOverruleWrapper();
    makePyGiSubEntityTraitsWrapper();
    makePyGiDrawableTraitsWrapper();
    makePyGiGeometryWrapper();
    makePyGiWorldGeometryWrapper();
    makePyGiViewportGeometryWrapper();
    makePyGiTransientManagerWrapper();
    makePyGiParameterWrapper();
    makePyGiEdgeDataWrapper();
    makePyGiFaceDataWrapper();
    makePyGiMapperWrapper();
    makePyGiPolylineWrapper();
    makePyGiTextStyleWrapper();
    makePyGiVertexDataWrapper();


#ifdef PYRX_IN_PROGRESS_GS_GI
    makePyGiKernelDescriptorWrapper();
    makePyGiGraphicsKernelWrapper();
#endif

    PyDocString DS("PyGi.PixelBGRA32Array");
    class_<PyGiPixelBGRA32Array>("PixelBGRA32Array")
        .def(boost::python::vector_indexing_suite<PyGiPixelBGRA32Array>())
        .def("createFromWxImage", &createFromWxImage1)
        .def("createFromWxImage", &createFromWxImage2, DS.SARGS({ "image: wx.Image", "alpha: int=255" })).staticmethod("createFromWxImage")
        ;

    enum_<AcGiTransientDrawingMode>("TransientDrawingMode")
        .value("kAcGiMain", AcGiTransientDrawingMode::kAcGiMain)
        .value("kAcGiSprite", AcGiTransientDrawingMode::kAcGiSprite)
        .value("kAcGiDirectShortTerm", AcGiTransientDrawingMode::kAcGiDirectShortTerm)
        .value("kAcGiHighlight", AcGiTransientDrawingMode::kAcGiHighlight)
        .value("kAcGiDirectTopmost", AcGiTransientDrawingMode::kAcGiDirectTopmost)
        .value("kAcGiContrast", AcGiTransientDrawingMode::kAcGiContrast)
        .value("kAcGiDrawingModeCount", AcGiTransientDrawingMode::kAcGiDrawingModeCount)
        .export_values()
        ;

    enum_<AcGiPositionTransformBehavior>("PositionTransformBehavior")
        .value("kAcGiWorldPosition", AcGiPositionTransformBehavior::kAcGiWorldPosition)
        .value("kAcGiViewportPosition", AcGiPositionTransformBehavior::kAcGiViewportPosition)
        .value("kAcGiScreenPosition", AcGiPositionTransformBehavior::kAcGiScreenPosition)
        .value("kAcGiScreenLocalOriginPosition", AcGiPositionTransformBehavior::kAcGiScreenLocalOriginPosition)
        .value("kAcGiWorldWithScreenOffsetPosition", AcGiPositionTransformBehavior::kAcGiWorldWithScreenOffsetPosition)
        .export_values()
        ;
    enum_<AcGiScaleTransformBehavior>("ScaleTransformBehavior")
        .value("kAcGiWorldScale", AcGiScaleTransformBehavior::kAcGiWorldScale)
        .value("kAcGiViewportScale", AcGiScaleTransformBehavior::kAcGiViewportScale)
        .value("kAcGiScreenScale", AcGiScaleTransformBehavior::kAcGiScreenScale)
        .value("kAcGiViewportLocalOriginScale", AcGiScaleTransformBehavior::kAcGiViewportLocalOriginScale)
        .value("kAcGiScreenLocalOriginScale", AcGiScaleTransformBehavior::kAcGiScreenLocalOriginScale)
        .export_values()
        ;
    enum_<AcGiOrientationTransformBehavior>("OrientationTransformBehavior")
        .value("kAcGiWorldOrientation", AcGiOrientationTransformBehavior::kAcGiWorldOrientation)
        .value("kAcGiScreenOrientation", AcGiOrientationTransformBehavior::kAcGiScreenOrientation)
        .value("kAcGiZAxisOrientation", AcGiOrientationTransformBehavior::kAcGiZAxisOrientation)
        .export_values()
        ;
    enum_<AcGiGeometry::TransparencyMode>("TransparencyMode")
        .value("kTransparencyOff", AcGiGeometry::TransparencyMode::kTransparencyOff)
        .value("kTransparency1Bit", AcGiGeometry::TransparencyMode::kTransparency1Bit)
        .value("kTransparency8Bit", AcGiGeometry::TransparencyMode::kTransparency8Bit)
        .export_values()
        ;
    enum_<AcGiArcType>("ArcType")
        .value("kAcGiArcSimple", AcGiArcType::kAcGiArcSimple)
        .value("kAcGiArcSector", AcGiArcType::kAcGiArcSector)
        .value("kAcGiArcChord", AcGiArcType::kAcGiArcChord)
        .export_values()
        ;
    enum_<AcGiOrientationType>("OrientationType")
        .value("kAcGiCounterClockwise", AcGiOrientationType::kAcGiCounterClockwise)
        .value("kAcGiNoOrientation", AcGiOrientationType::kAcGiNoOrientation)
        .value("kAcGiClockwise", AcGiOrientationType::kAcGiClockwise)
        .export_values()
        ;
    enum_<AcGiFillType>("FillType")
        .value("kAcGiFillAlways", AcGiFillType::kAcGiFillAlways)
        .value("kAcGiFillNever", AcGiFillType::kAcGiFillNever)
        .export_values()
        ;
    enum_<AcGiVisibility>("Visibility")
        .value("kAcGiInvisible", AcGiVisibility::kAcGiInvisible)
        .value("kAcGiVisible", AcGiVisibility::kAcGiVisible)
        .value("kAcGiSilhouette", AcGiVisibility::kAcGiSilhouette)
        .export_values()
        ;
    enum_<AcGiRegenType>("RegenType")
        .value("eAcGiRegenTypeInvalid", AcGiRegenType::eAcGiRegenTypeInvalid)
        .value("kAcGiStandardDisplay", AcGiRegenType::kAcGiStandardDisplay)
        .value("kAcGiHideOrShadeCommand", AcGiRegenType::kAcGiHideOrShadeCommand)
        .value("kAcGiShadedDisplay", AcGiRegenType::kAcGiShadedDisplay)
        .value("kAcGiForExplode", AcGiRegenType::kAcGiForExplode)
        .value("kAcGiSaveWorldDrawForProxy", AcGiRegenType::kAcGiSaveWorldDrawForProxy)
        .export_values()
        ;

    enum_<AcGiViewportTraits::DefaultLightingType>("DefaultLightingType")
        .value("kOneDistantLight", AcGiViewportTraits::DefaultLightingType::kOneDistantLight)
        .value("kTwoDistantLights", AcGiViewportTraits::DefaultLightingType::kTwoDistantLights)
#if !defined (_BRXTARGET270)
        .value("kBackLighting", AcGiViewportTraits::DefaultLightingType::kBackLighting)
#endif
        .export_values()
        ;

#if !defined (_BRXTARGET270)
    enum_<AcGiHighlightStyle>("HighlightStyle")
        .value("kAcGiHighlightNone", AcGiHighlightStyle::kAcGiHighlightNone)
        .value("kAcGiHighlightCustom", AcGiHighlightStyle::kAcGiHighlightCustom)
        .value("kAcGiHighlightDashedAndThicken", AcGiHighlightStyle::kAcGiHighlightDashedAndThicken)
        .value("kAcGiHighlightDim", AcGiHighlightStyle::kAcGiHighlightDim)
        .value("kAcGiHighlightThickDim", AcGiHighlightStyle::kAcGiHighlightThickDim)
        .value("kAcGiHighlightGlow", AcGiHighlightStyle::kAcGiHighlightGlow)
        .export_values()
        ;
#endif
    enum_<Autodesk::AutoCAD::PAL::FontUtils::FontPitch>("FontPitch")
        .value("kDefault", Autodesk::AutoCAD::PAL::FontUtils::FontPitch::kDefault)
        .value("kFixed", Autodesk::AutoCAD::PAL::FontUtils::FontPitch::kFixed)
        .value("kVariable", Autodesk::AutoCAD::PAL::FontUtils::FontPitch::kVariable)
        .export_values()
        ;

    enum_<Autodesk::AutoCAD::PAL::FontUtils::FontFamily>("FontFamily")
        .value("kDefault", Autodesk::AutoCAD::PAL::FontUtils::FontFamily::kDoNotCare)
        .value("kDoNotCare", Autodesk::AutoCAD::PAL::FontUtils::FontFamily::kDoNotCare)
        .value("kRoman", Autodesk::AutoCAD::PAL::FontUtils::FontFamily::kRoman)
        .value("kSwiss", Autodesk::AutoCAD::PAL::FontUtils::FontFamily::kSwiss)
        .value("kModern", Autodesk::AutoCAD::PAL::FontUtils::FontFamily::kModern)
        .value("kScript", Autodesk::AutoCAD::PAL::FontUtils::FontFamily::kScript)
        .value("kDecorative", Autodesk::AutoCAD::PAL::FontUtils::FontFamily::kDecorative)
        .export_values()
        ;

    enum_<Charset>("Charset")
        .value("kUndefinedCharset", Charset::kUndefinedCharset)
        .value("kAnsiCharset", Charset::kAnsiCharset)
        .value("kUnicodeCharset", Charset::kUnicodeCharset)
        .value("kSymbolCharset", Charset::kSymbolCharset)
        .value("kJapaneseCharset", Charset::kJapaneseCharset)
        .value("kKoreanCharset", Charset::kKoreanCharset)
        .value("kChineseSimpCharset", Charset::kChineseSimpCharset)
        .value("kChineseTradCharset", Charset::kChineseTradCharset)
        .value("kJohabCharset", Charset::kJohabCharset)
        .value("kHebrewCharset", Charset::kHebrewCharset)
        .value("kArabicCharset", Charset::kArabicCharset)
        .value("kGreekCharset", Charset::kGreekCharset)
        .value("kTurkishCharset", Charset::kTurkishCharset)
        .value("kVietnameseCharset", Charset::kVietnameseCharset)
        .value("kThaiCharset", Charset::kThaiCharset)
        .value("kEastEuropeCharset", Charset::kEastEuropeCharset)
        .value("kRussianCharset", Charset::kRussianCharset)
        .value("kBalticCharset", Charset::kBalticCharset)
        .value("kDefaultCharset", Charset::kDefaultCharset)
        .value("kINTERNALCHARSET", Charset::kINTERNALCHARSET)
        .value("kBengaliCharset", Charset::kBengaliCharset)
        .value("kGurmukhiCharset", Charset::kGurmukhiCharset)
        .value("kGujaratiCharset", Charset::kGujaratiCharset)
        .value("kTamilCharset", Charset::kTamilCharset)
        .value("kTeluguCharset", Charset::kTeluguCharset)
        .value("kKannadaCharset", Charset::kKannadaCharset)
        .value("kMalayalamCharset", Charset::kMalayalamCharset)
        .value("kDevanagariCharset", Charset::kDevanagariCharset)
        .value("kOriyaCharset", Charset::kOriyaCharset)
        .value("kMarathiCharset", Charset::kMarathiCharset)
        .value("kHindiCharset", Charset::kHindiCharset)
        .value("kKonkaniCharset", Charset::kKonkaniCharset)
        .value("kSanskritCharset", Charset::kSanskritCharset)
        .value("kPunjabiharset", Charset::kPunjabiharset)
        .value("kAssameseCharset", Charset::kAssameseCharset)
        .value("kFinnishCharset", Charset::kFinnishCharset)
        .value("kBelgianCharset", Charset::kBelgianCharset)
        .value("kGeorgianCharset", Charset::kGeorgianCharset)
        .export_values()
        ;
}

void initPyGiModule()
{
    PyImport_AppendInittab(PyGiNamespace, &PyInit_PyGi);
}
