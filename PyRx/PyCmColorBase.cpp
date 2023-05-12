#include "stdafx.h"

using namespace boost::python;


//----------------------------------------------------------------------------------------------------
//wrapper
void makeAcCmColorWrapper()
{
    class_<AcCmColor>("Color")
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
    class_<AcCmTransparency>("Transparency")
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
        .value("kByLayer", AcCmTransparency::transparencyMethod::kByLayer)
        .value("kByBlock", AcCmTransparency::transparencyMethod::kByBlock)
        .value("kByAlpha", AcCmTransparency::transparencyMethod::kByAlpha)
        .value("kErrorValue", AcCmTransparency::transparencyMethod::kErrorValue)
        ;
}

//--------------------------------------------------------------------------------------------------------
//AcCmEntityColor no conversion, so we don't need a py wrapper
void makeAcCmEntityColorWrapper()
{
    class_<AcCmEntityColor>("EntityColor")
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

    //TODO: find better enum
    enum_<AcCmEntityColor::Color>("AcCmColor")
        .value("kRed", AcCmEntityColor::Color::kRed)
        .value("kGreen", AcCmEntityColor::Color::kGreen)
        .value("kBlue", AcCmEntityColor::Color::kBlue)
        ;
    enum_<AcCmEntityColor::ColorMethod>("ColorMethod")
        .value("kByLayer", AcCmEntityColor::ColorMethod::kByLayer)
        .value("kByBlock", AcCmEntityColor::ColorMethod::kByBlock)
        .value("kByColor", AcCmEntityColor::ColorMethod::kByColor)
        .value("kByACI", AcCmEntityColor::ColorMethod::kByACI)
        .value("kByPen", AcCmEntityColor::ColorMethod::kByPen)
        .value("kForeground", AcCmEntityColor::ColorMethod::kForeground)
        .value("kLayerOff", AcCmEntityColor::ColorMethod::kLayerOff)
        .value("kLayerFrozen", AcCmEntityColor::ColorMethod::kLayerFrozen)
        .value("kNone", AcCmEntityColor::ColorMethod::kNone)
        ;
    enum_<AcCmEntityColor::ACIcolorMethod>("ACIcolorMethod")
        .value("kACIbyBlock", AcCmEntityColor::ACIcolorMethod::kACIbyBlock)
        .value("kACIforeground", AcCmEntityColor::ACIcolorMethod::kACIforeground)
        .value("kACIbyLayer", AcCmEntityColor::ACIcolorMethod::kACIbyLayer)
        .value("kACIclear", AcCmEntityColor::ACIcolorMethod::kACIclear)
        .value("kACIstandard", AcCmEntityColor::ACIcolorMethod::kACIstandard)
        .value("kACImaximum", AcCmEntityColor::ACIcolorMethod::kACImaximum)
        .value("kACInone", AcCmEntityColor::ACIcolorMethod::kACInone)
        .value("kACIminimum", AcCmEntityColor::ACIcolorMethod::kACIminimum)
        .value("kACIfrozenLayer", AcCmEntityColor::ACIcolorMethod::kACIfrozenLayer)
        ;
}