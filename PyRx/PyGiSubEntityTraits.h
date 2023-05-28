#pragma once
#include "PyRxObject.h"
class PyDbObjectId;

//-----------------------------------------------------------------------------------------
//PyGiSubEntityTraits
void makePyGiSubEntityTraitsWrapper();

class PyGiSubEntityTraits : public PyRxObject
{
public:
    PyGiSubEntityTraits(AcGiSubEntityTraits* ptr, bool autoDelete);
    virtual ~PyGiSubEntityTraits() override = default;

    void                setColor(const Adesk::UInt16 color);
    void                setTrueColor(const AcCmEntityColor& color);
    void                setLayer(const PyDbObjectId& layerId);
    void                setLineType(const PyDbObjectId& linetypeId);
    void                setSelectionMarker(const Adesk::LongPtr markerId);
    void                setFillType(const AcGiFillType val);
    void                setLineWeight(const AcDb::LineWeight lw);
    void                setLineTypeScale1();
    void                setLineTypeScale2(double dScale);
    void                setThickness(double dThickness);
    void                setVisualStyle(const PyDbObjectId& visualStyleId);
    void                setPlotStyleName1(AcDb::PlotStyleNameType val);
    void                setPlotStyleName2(AcDb::PlotStyleNameType val, const PyDbObjectId& id);
    void                setMaterial(const PyDbObjectId& materialId);
    void                setSectionable(bool bSectionable);
    Acad::ErrorStatus   setDrawFlags(Adesk::UInt32 flags);
    Acad::ErrorStatus   setShadowFlags(AcGiSubEntityTraits::ShadowFlags flags);
    void                setSelectionGeom(bool bSelectionflag);
    void                setTransparency(const AcCmTransparency& transparency);

    Adesk::UInt16       color(void) const;
    AcCmEntityColor     trueColor(void) const;
    PyDbObjectId        layerId(void) const;
    PyDbObjectId        lineTypeId(void) const;
    AcGiFillType        fillType(void) const;
    AcDb::LineWeight    lineWeight(void) const;
    double              lineTypeScale(void) const;
    double              thickness(void) const;
    PyDbObjectId        visualStyle(void) const;
    PyDbObjectId        getPlotStyleNameId() const;
    PyDbObjectId        materialId(void) const;
    bool                sectionable(void) const;
    Adesk::UInt32       drawFlags(void) const;
    AcGiSubEntityTraits::ShadowFlags shadowFlags(void) const;
    bool                selectionGeom(void) const;
    AcCmTransparency    transparency(void) const;

    static std::string	className();
    static PyRxClass	desc();
public:
    AcGiSubEntityTraits* impObj(const std::source_location& src = std::source_location::current()) const;
};



//-----------------------------------------------------------------------------------------
//PyGiDrawableTraits
void makePyGiDrawableTraitsWrapper();

class PyGiDrawableTraits : public PyGiSubEntityTraits
{
public:
    PyGiDrawableTraits(AcGiDrawableTraits* ptr, bool autoDelete);
    virtual ~PyGiDrawableTraits() override = default;
    static std::string	className();
    static PyRxClass	desc();
public:
    AcGiDrawableTraits* impObj(const std::source_location& src = std::source_location::current()) const;
};

