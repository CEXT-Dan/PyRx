#include "stdafx.h"

using namespace boost::python;


//----------------------------------------------------------------------------------------------------
//wrapper
std::string AcCmColorToString(const AcCmColor& s)
{
    return std::format("({},{},{})", s.red(), s.green(), s.blue());
}

std::string AcCmColorToStringRepr(const AcCmColor& s)
{
    return std::format("<{}.Color({},{},{})>", PyDbNamespace, s.red(), s.green(), s.blue());
}

static bool AcCmColorEqualsOperator(const AcCmColor& left, const AcCmColor& right)
{
    return left == right;
}
static bool AcCmColorNotEqualsOperator(const AcCmColor& left, const AcCmColor& right)
{
    return left != right;
}

void makePyCmColorWrapper()
{
    PyDocString DS("Color");
    class_<AcCmColor>("Color")
 #ifndef _ZRXTARGET
        .def("setNone", &AcCmColor::setNone, DS.ARGS())
        .def("setByBlock", &AcCmColor::setByBlock, DS.ARGS())
        .def("setForeground", &AcCmColor::setForeground, DS.ARGS())
        .def("setLayerOff", &AcCmColor::setLayerOff, DS.ARGS())
        .def("setByLayer", &AcCmColor::setByLayer, DS.ARGS())
#endif
        .def("isByColor", &AcCmColor::isByColor, DS.ARGS())
        .def("isByLayer", &AcCmColor::isByLayer, DS.ARGS())
        .def("isByBlock", &AcCmColor::isByBlock, DS.ARGS())
        .def("isByACI", &AcCmColor::isByACI, DS.ARGS())
        .def("isByPen", &AcCmColor::isByPen, DS.ARGS())
        .def("isForeground", &AcCmColor::isForeground, DS.ARGS())
        .def("isNone", &AcCmColor::isNone, DS.ARGS())
#ifndef _ZRXTARGET
        .def<Acad::ErrorStatus(AcCmColor::*)(Adesk::RGBQuad)>("setRGB", &AcCmColor::setRGB, DS.ARGS({ "val : int" }))
#endif
        .def<Acad::ErrorStatus(AcCmColor::*)(Adesk::UInt8, Adesk::UInt8, Adesk::UInt8)>("setRGB", &AcCmColor::setRGB, DS.ARGS({ "red : int","green : int","blue : int" }))
        .def("red", &AcCmColor::red, DS.ARGS())
        .def("green", &AcCmColor::green, DS.ARGS())
        .def("blue", &AcCmColor::blue, DS.ARGS())
#ifndef _ZRXTARGET
        .def("setCOLORREF", &AcCmColor::setCOLORREF, DS.ARGS({ "val : int" }))
        .def("getCOLORREF", &AcCmColor::getCOLORREF, DS.ARGS())
        .def("getRGB", &AcCmColor::getRGB, DS.ARGS())
        .def("setRGBM", &AcCmColor::setRGBM, DS.ARGS({ "val : int" }))
        .def("getRGBM", &AcCmColor::getRGBM, DS.ARGS())
#endif
        .def("colorIndex", &AcCmColor::colorIndex, DS.ARGS())
        .def("setColorIndex", &AcCmColor::setColorIndex, DS.ARGS({ "val : int" }))
        .def("penIndex", &AcCmColor::penIndex, DS.ARGS())
        .def("setPenIndex", &AcCmColor::setPenIndex, DS.ARGS({ "val : int" }))
        .def("entityColor", &AcCmColor::entityColor, DS.ARGS())
        //operators
        .def("__eq__", &AcCmColorEqualsOperator)
        .def("__ne__", &AcCmColorNotEqualsOperator)
        .def("__str__", &AcCmColorToString)
        .def("__repr__", &AcCmColorToStringRepr)
        ;
}

//--------------------------------------------------------------------------------------------------------
//AcCmTransparency no conversion, so we don't need a py wrapper
void makePyCmTransparencyWrapper()
{
    PyDocString DS("Transparency");
    class_<AcCmTransparency>("Transparency")
        .def(init<Adesk::UInt8>())
        .def(init<double>())
        .def("setAlpha", &AcCmTransparency::setAlpha, DS.ARGS({ "alpha : int" }))
        .def("setAlphaPercent", &AcCmTransparency::setAlphaPercent, DS.ARGS({ "alphaPercent : float" }))
        .def("alpha", &AcCmTransparency::alpha, DS.ARGS())
        .def("alphaPercent", &AcCmTransparency::alphaPercent, DS.ARGS())
        .def("isByAlpha", &AcCmTransparency::isByAlpha, DS.ARGS())
        .def("isByBlock", &AcCmTransparency::isByBlock, DS.ARGS())
        .def("isByLayer", &AcCmTransparency::isByLayer, DS.ARGS())
        .def("isInvalid", &AcCmTransparency::isInvalid, DS.ARGS())
        .def("isClear", &AcCmTransparency::isClear, DS.ARGS())
        .def("isSolid", &AcCmTransparency::isSolid, DS.ARGS())
        //operators
        .def("__eq__", &AcCmTransparency::operator==)
        .def("__ne__", &AcCmTransparency::operator!=)
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
void makePyCmEntityColorWrapper()
{
    PyDocString DS("EntityColor");
    class_<AcCmEntityColor>("EntityColor")
        .def(init<Adesk::UInt8, Adesk::UInt8, Adesk::UInt8>())
#ifndef _ZRXTARGET 
        .def("setNone", &AcCmEntityColor::setNone,DS.ARGS())
        .def("setByBlock", &AcCmEntityColor::setByBlock, DS.ARGS())
        .def("setForeground", &AcCmEntityColor::setForeground, DS.ARGS())
        .def("setByLayer", &AcCmEntityColor::setByLayer, DS.ARGS())
        .def("setLayerOff", &AcCmEntityColor::setLayerOff, DS.ARGS())
        .def("None", &AcCmEntityColor::None, DS.ARGS())
        .def("ByBlock", &AcCmEntityColor::ByBlock, DS.ARGS())
        .def("ByLayer", &AcCmEntityColor::ByLayer, DS.ARGS())
        .def("Foreground", &AcCmEntityColor::Foreground, DS.ARGS())
        .def("white", &AcCmEntityColor::white, DS.ARGS())
        .def("black", &AcCmEntityColor::black, DS.ARGS())
        .def("colorMethod", &AcCmEntityColor::colorMethod, DS.ARGS())
        .def("setColorIndex", &AcCmEntityColor::setColorIndex, DS.ARGS({ "val : int" }))
        .def("colorIndex", &AcCmEntityColor::colorIndex, DS.ARGS())
        .def("setLayerIndex", &AcCmEntityColor::setLayerIndex, DS.ARGS({ "val : int" }))
        .def("layerIndex", &AcCmEntityColor::layerIndex, DS.ARGS())
        .def("setPenIndex", &AcCmEntityColor::setPenIndex, DS.ARGS({ "val : int" }))
        .def("penIndex", &AcCmEntityColor::penIndex, DS.ARGS())
        .def("red", &AcCmEntityColor::red, DS.ARGS())
        .def("green", &AcCmEntityColor::green, DS.ARGS())
        .def("blue", &AcCmEntityColor::blue, DS.ARGS())
        .def("setCOLORREF", &AcCmEntityColor::setCOLORREF, DS.ARGS({ "val : int" }))
        .def("getCOLORREF", &AcCmEntityColor::getCOLORREF, DS.ARGS())
        .def<Acad::ErrorStatus(AcCmEntityColor::*)(Adesk::RGBQuad)>("setRGB", &AcCmEntityColor::setRGB)
        .def<Acad::ErrorStatus(AcCmEntityColor::*)(Adesk::UInt8, Adesk::UInt8, Adesk::UInt8)>("setRGB", &AcCmEntityColor::setRGB)
        .def("getRGB", &AcCmEntityColor::getRGB, DS.ARGS())
        .def("setRGBM", &AcCmEntityColor::setRGBM, DS.ARGS({ "val : int" }))
        .def("getRGBM", &AcCmEntityColor::getRGBM, DS.ARGS())
        .def("isByColor", &AcCmEntityColor::isByColor, DS.ARGS())
        .def("isByLayer", &AcCmEntityColor::isByLayer, DS.ARGS())
        .def("isByBlock", &AcCmEntityColor::isByBlock, DS.ARGS())
        .def("isByACI", &AcCmEntityColor::isByACI, DS.ARGS())
        .def("isByPen", &AcCmEntityColor::isByPen, DS.ARGS())
        .def("isForeground", &AcCmEntityColor::isForeground, DS.ARGS())
        .def("isLayerOff", &AcCmEntityColor::isLayerOff, DS.ARGS())
        .def("isLayerFrozen", &AcCmEntityColor::isLayerFrozen, DS.ARGS())
        .def("isNone", &AcCmEntityColor::isNone, DS.ARGS())
        .def("isLayerFrozenOrOff", &AcCmEntityColor::isLayerFrozenOrOff, DS.ARGS())
        .def("canResolveRGB", &AcCmEntityColor::canResolveRGB, DS.ARGS())
        .def("makeTrueColor", &AcCmEntityColor::makeTrueColor, DS.ARGS())
        .def("None", &AcCmEntityColor::None, DS.SARGS()).staticmethod("None")
        .def("ByBlock", &AcCmEntityColor::ByBlock, DS.SARGS()).staticmethod("ByBlock")
        .def("ByLayer", &AcCmEntityColor::ByLayer, DS.SARGS()).staticmethod("ByLayer")
        .def("Foreground", &AcCmEntityColor::Foreground, DS.SARGS()).staticmethod("Foreground")
        .def("white", &AcCmEntityColor::white, DS.SARGS()).staticmethod("white")
        .def("black", &AcCmEntityColor::black, DS.SARGS()).staticmethod("black")
#endif
        .def("__eq__", &AcCmEntityColor::operator==)
        .def("__ne__", &AcCmEntityColor::operator!=)
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