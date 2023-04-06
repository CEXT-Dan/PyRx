#include "stdafx.h"

using namespace boost::python;


//----------------------------------------------------------------------------------------------------
//wrapper
void makeAcCmColorWrapper()
{
    static auto wrapper = class_<AcCmColor>("CmColor")
#if defined(GRXAPP) || defined(ZRXAPP)
#else
        .def("setNone", &AcCmColor::setNone)
        .def("setByBlock", &AcCmColor::setByBlock)
        .def("setForeground", &AcCmColor::setForeground)
        .def("setLayerOff", &AcCmColor::setLayerOff)
        .def("setByLayer", &AcCmColor::setByLayer)
#endif
        .def("isByColor", &AcCmColor::isByColor)
        .def("isByLayer", &AcCmColor::isByLayer)
        .def("isByBlock", &AcCmColor::isByBlock)
        .def("isByACI", &AcCmColor::isByACI)
        .def("isByPen", &AcCmColor::isByPen)
        .def("isForeground", &AcCmColor::isForeground)
        .def("isNone", &AcCmColor::isNone)

#if defined(GRXAPP) || defined(ZRXAPP)
#else
        .def<Acad::ErrorStatus(AcCmColor::*)(Adesk::RGBQuad)>("setRGB", &AcCmColor::setRGB)
#endif
        .def<Acad::ErrorStatus(AcCmColor::*)(Adesk::UInt8, Adesk::UInt8, Adesk::UInt8)>("setRGB", &AcCmColor::setRGB)

        .def("red", &AcCmColor::red)
        .def("green", &AcCmColor::green)
        .def("blue", &AcCmColor::blue)
#if defined(GRXAPP) || defined(ZRXAPP)
#else
        .def("setCOLORREF", &AcCmColor::setCOLORREF)
        .def("getCOLORREF", &AcCmColor::getCOLORREF)
        .def("getRGB", &AcCmColor::getRGB)
        .def("setRGBM", &AcCmColor::setRGBM)
        .def("getRGBM", &AcCmColor::getRGBM)
#endif
        ;
}

//--------------------------------------------------------------------------------------------------------
//AcCmTransparency no conversion, so we don't need a py wrapper
void makeAcCmTransparencyWrapper()
{
    static auto wrapper = class_<AcCmTransparency>("CmTransparency")
        .def(init<Adesk::UInt8>())
        .def(init<double>())
        .def("setAlpha", &AcCmTransparency::setAlpha)
        .def("setAlphaPercent", &AcCmTransparency::setAlphaPercent)
        .def("alpha", &AcCmTransparency::alpha)
        .def("alphaPercent", &AcCmTransparency::alphaPercent)
        .def("isByAlpha", &AcCmTransparency::isByAlpha)
        .def("isByBlock", &AcCmTransparency::isByBlock)
        .def("isByLayer", &AcCmTransparency::isByLayer)
#ifndef BRXAPP
        .def("isInvalid", &AcCmTransparency::isInvalid)
#endif // !BRXAPP
        .def("isClear", &AcCmTransparency::isClear)
        .def("isSolid", &AcCmTransparency::isSolid)
        ;

    enum_<AcCmTransparency::transparencyMethod>("TransparencyMethod")
        .value("ByLayer", AcCmTransparency::transparencyMethod::kByLayer)
        .value("ByBlock", AcCmTransparency::transparencyMethod::kByBlock)
        .value("ByAlpha", AcCmTransparency::transparencyMethod::kByAlpha)
        .value("ErrorValue", AcCmTransparency::transparencyMethod::kErrorValue)
        ;
}

//--------------------------------------------------------------------------------------------------------
//AcCmEntityColor no conversion, so we don't need a py wrapper
void makeAcCmEntityColorWrapper()
{
    static auto wrapper = class_<AcCmEntityColor>("CmEntityColor")
        .def(init<Adesk::UInt8, Adesk::UInt8, Adesk::UInt8>())
#if defined(GRXAPP) || defined(ZRXAPP)
#else
        .def("setNone", &AcCmEntityColor::setNone)
        .def("setByBlock", &AcCmEntityColor::setByBlock)
        .def("setForeground", &AcCmEntityColor::setForeground)
        .def("setByLayer", &AcCmEntityColor::setByLayer)
        .def("setLayerOff", &AcCmEntityColor::setLayerOff)
        .def("None", &AcCmEntityColor::None)
        .def("ByBlock", &AcCmEntityColor::ByBlock)
        .def("ByLayer", &AcCmEntityColor::ByLayer)
        .def("Foreground", &AcCmEntityColor::Foreground)
        .def("white", &AcCmEntityColor::white)
        .def("black", &AcCmEntityColor::black)
#endif
#ifdef ARXAPP
        .def("colorMethod", &AcCmEntityColor::colorMethod)
        .def("setColorIndex", &AcCmEntityColor::setColorIndex)
        .def("colorIndex", &AcCmEntityColor::colorIndex)
        .def("setLayerIndex", &AcCmEntityColor::setLayerIndex)
        .def("layerIndex", &AcCmEntityColor::layerIndex)
        .def("setPenIndex", &AcCmEntityColor::setPenIndex)
        .def("penIndex", &AcCmEntityColor::penIndex)
        .def("red", &AcCmEntityColor::red)
        .def("green", &AcCmEntityColor::green)
        .def("blue", &AcCmEntityColor::blue)
#endif

#if defined(GRXAPP) || defined(ZRXAPP)
#else
        .def("setCOLORREF", &AcCmEntityColor::setCOLORREF)
        .def("getCOLORREF", &AcCmEntityColor::getCOLORREF)
#endif

#if defined(GRXAPP) || defined(ZRXAPP)
#else
        .def<Acad::ErrorStatus(AcCmEntityColor::*)(Adesk::RGBQuad)>("setRGB", &AcCmEntityColor::setRGB)
#endif
        .def<Acad::ErrorStatus(AcCmEntityColor::*)(Adesk::UInt8, Adesk::UInt8, Adesk::UInt8)>("setRGB", &AcCmEntityColor::setRGB)

#if defined(GRXAPP) || defined(ZRXAPP)
#else
        .def("getRGB", &AcCmEntityColor::getRGB)
        .def("setRGBM", &AcCmEntityColor::setRGBM)
        .def("getRGBM", &AcCmEntityColor::getRGBM)
#endif

#ifdef ARXAPP
        .def("isByColor", &AcCmEntityColor::isByColor)
        .def("isByLayer", &AcCmEntityColor::isByLayer)
        .def("isByBlock", &AcCmEntityColor::isByBlock)
        .def("isByACI", &AcCmEntityColor::isByACI)
        .def("isByPen", &AcCmEntityColor::isByPen)
        .def("isForeground", &AcCmEntityColor::isForeground)
        .def("isLayerOff", &AcCmEntityColor::isLayerOff)
        .def("isLayerFrozen", &AcCmEntityColor::isLayerFrozen)
        .def("isNone", &AcCmEntityColor::isNone)
        .def("isLayerFrozenOrOff", &AcCmEntityColor::isLayerFrozenOrOff)
#endif

#if defined(GRXAPP) || defined(ZRXAPP)
#else
        .def("canResolveRGB", &AcCmEntityColor::canResolveRGB)
        .def("makeTrueColor", &AcCmEntityColor::makeTrueColor)
#endif
        ;

  
    enum_<AcCmEntityColor::ColorMethod>("ColorMethod")
        .value("ByLayer", AcCmEntityColor::ColorMethod::kByLayer)
        .value("ByBlock", AcCmEntityColor::ColorMethod::kByBlock)
        .value("ByColor", AcCmEntityColor::ColorMethod::kByColor)
        .value("ByACI", AcCmEntityColor::ColorMethod::kByACI)
        .value("ByPen", AcCmEntityColor::ColorMethod::kByPen)
        .value("Foreground", AcCmEntityColor::ColorMethod::kForeground)
        .value("LayerOff", AcCmEntityColor::ColorMethod::kLayerOff)
        .value("LayerFrozen", AcCmEntityColor::ColorMethod::kLayerFrozen)
        .value("None", AcCmEntityColor::ColorMethod::kNone)
        ;
    enum_<AcCmEntityColor::ACIcolorMethod>("ACIcolorMethod")
        .value("ACIbyBlock", AcCmEntityColor::ACIcolorMethod::kACIbyBlock)
        .value("ACIforeground", AcCmEntityColor::ACIcolorMethod::kACIforeground)
        .value("ACIbyLayer", AcCmEntityColor::ACIcolorMethod::kACIbyLayer)
        .value("ACIclear", AcCmEntityColor::ACIcolorMethod::kACIclear)
        .value("ACIstandard", AcCmEntityColor::ACIcolorMethod::kACIstandard)
        .value("ACImaximum", AcCmEntityColor::ACIcolorMethod::kACImaximum)
        .value("ACInone", AcCmEntityColor::ACIcolorMethod::kACInone)
        .value("ACIminimum", AcCmEntityColor::ACIcolorMethod::kACIminimum)
        .value("ACIfrozenLayer", AcCmEntityColor::ACIcolorMethod::kACIfrozenLayer)
        ;
}