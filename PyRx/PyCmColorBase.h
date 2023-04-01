#pragma once
void makePyCmColorWrapper();

class PyCmColor
{
public:
    PyCmColor();
    PyCmColor(const AcCmColor& val);

    void setNone();
    void setByBlock();
    void setForeground();
    void setLayerOff();
    void setByLayer();

    bool isByColor() const;
    bool isByLayer() const;
    bool isByBlock() const;
    bool isByACI()   const;
    bool isByPen() const;
    bool isForeground() const;

    bool isNone() const;
    Acad::ErrorStatus setRGB(Adesk::UInt8 red, Adesk::UInt8 green, Adesk::UInt8 blue);

    Adesk::UInt8 red() const;
    Adesk::UInt8 green() const;
    Adesk::UInt8 blue() const;

#if defined(GRXAPP) || defined(ZRXAPP)
#else
    Acad::ErrorStatus setCOLORREF(Adesk::ColorRef cref);
    Adesk::ColorRef   getCOLORREF() const;
    Acad::ErrorStatus   setRGB(Adesk::RGBQuad rgbquad);
    Adesk::RGBQuad      getRGB() const;
    Acad::ErrorStatus   setRGBM(Adesk::UInt32 rgbmValue);
    Adesk::UInt32       getRGBM() const;
#endif

public:
    AcCmColor m_clr;
};
