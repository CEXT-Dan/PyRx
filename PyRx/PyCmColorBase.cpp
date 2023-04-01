#include "stdafx.h"
#include "PyCmColorBase.h"

using namespace boost::python;


//----------------------------------------------------------------------------------------------------
//wrapper
void makePyCmColorWrapper()
{
    static auto wrapper = class_<PyCmColor>("CmColor")
        .def(init<>())
        .def("setNone", &PyCmColor::setNone)
        .def("setByBlock", &PyCmColor::setByBlock)
        .def("setForeground", &PyCmColor::setForeground)
        .def("setLayerOff", &PyCmColor::setLayerOff)
        .def("setByLayer", &PyCmColor::setByLayer)
        .def("isByColor", &PyCmColor::isByColor)
        .def("isByLayer", &PyCmColor::isByLayer)
        .def("isByBlock", &PyCmColor::isByBlock)
        .def("isByACI", &PyCmColor::isByACI)
        .def("isByPen", &PyCmColor::isByPen)
        .def("isForeground", &PyCmColor::isForeground)
        .def("isNone", &PyCmColor::isNone)

#if defined(GRXAPP) || defined(ZRXAPP)
#else
        .def<Acad::ErrorStatus(PyCmColor::*)(Adesk::RGBQuad)>("setRGB", &PyCmColor::setRGB)
#endif
        .def<Acad::ErrorStatus(PyCmColor::*)(Adesk::UInt8, Adesk::UInt8, Adesk::UInt8)>("setRGB", &PyCmColor::setRGB)

        .def("red", &PyCmColor::red)
        .def("green", &PyCmColor::green)
        .def("blue", &PyCmColor::blue)
#if defined(GRXAPP) || defined(ZRXAPP)
#else
        .def("setCOLORREF", &PyCmColor::setCOLORREF)
        .def("getCOLORREF", &PyCmColor::getCOLORREF)
        .def("getRGB", &PyCmColor::getRGB)
        .def("setRGBM", &PyCmColor::setRGBM)
        .def("getRGBM", &PyCmColor::getRGBM)
#endif
        ;
}

//----------------------------------------------------------------------------------------------------
//imp
PyCmColor::PyCmColor()
    : m_clr()
{
}

PyCmColor::PyCmColor(const AcCmColor& val)
    : m_clr(val)
{

}

void PyCmColor::setNone()
{
#if defined(GRXAPP) || defined(ZRXAPP)

#else
    m_clr.setNone();
#endif
}

void PyCmColor::setByBlock()
{
#if defined(GRXAPP) || defined(ZRXAPP)

#else
    m_clr.setByBlock();
#endif
}

void PyCmColor::setForeground()
{
#if defined(GRXAPP) || defined(ZRXAPP)

#else
    m_clr.setForeground();
#endif
}

void PyCmColor::setLayerOff()
{
#if defined(GRXAPP) || defined(ZRXAPP)

#else
    m_clr.setLayerOff();
#endif
}

void PyCmColor::setByLayer()
{
#if defined(GRXAPP) || defined(ZRXAPP)

#else
    m_clr.setLayerOff();
#endif
}

bool PyCmColor::isByColor() const
{
    return m_clr.isByColor();
}

bool PyCmColor::isByLayer() const
{
    return m_clr.isByLayer();
}

bool PyCmColor::isByBlock() const
{
    return m_clr.isByBlock();
}

bool PyCmColor::isByACI() const
{
    return m_clr.isByACI();
}

bool PyCmColor::isByPen() const
{
    return m_clr.isByPen();
}

bool PyCmColor::isForeground() const
{
    return m_clr.isForeground();
}

bool PyCmColor::isNone() const
{
    return m_clr.isNone();
}
Acad::ErrorStatus PyCmColor::setRGB(Adesk::UInt8 red, Adesk::UInt8 green, Adesk::UInt8 blue)
{
    return m_clr.setRGB(red, green, blue);
}

#if defined(GRXAPP) || defined(ZRXAPP)
#else
Acad::ErrorStatus PyCmColor::setRGB(Adesk::RGBQuad rgbquad)
{
    return m_clr.setRGB(rgbquad);
}

Adesk::RGBQuad PyCmColor::getRGB() const
{
    return m_clr.getRGB();
}
Acad::ErrorStatus PyCmColor::setRGBM(Adesk::UInt32 rgbmValue)
{
    return m_clr.setRGBM(rgbmValue);
}

Adesk::UInt32 PyCmColor::getRGBM() const
{
    return m_clr.getRGBM();
}

#endif
Adesk::UInt8 PyCmColor::red() const
{
    return m_clr.red();
}

Adesk::UInt8 PyCmColor::green() const
{
    return m_clr.green();
}

Adesk::UInt8 PyCmColor::blue() const
{
    return m_clr.blue();
}

#if defined(GRXAPP) || defined(ZRXAPP)
#else
Acad::ErrorStatus PyCmColor::setCOLORREF(Adesk::ColorRef cref)
{
    return m_clr.setCOLORREF(cref);
}

Adesk::ColorRef PyCmColor::getCOLORREF() const
{
    return m_clr.getCOLORREF();
}
#endif


