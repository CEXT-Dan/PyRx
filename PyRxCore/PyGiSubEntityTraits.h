#pragma once
#include "PyRxObject.h"

#pragma pack (push, 8)
class PyDbObjectId;
class PyDbEntity;

//-----------------------------------------------------------------------------------------
//PyGiSubEntityTraits
void makePyGiSubEntityTraitsWrapper();

class PyGiSubEntityTraits : public PyRxObject
{
public:
    PyGiSubEntityTraits(AcGiSubEntityTraits* ptr, bool autoDelete);
    virtual ~PyGiSubEntityTraits() override = default;

    void                setColor(const Adesk::UInt16 color) const;
    void                setTrueColor(const AcCmEntityColor& color) const;
    void                setLayer(const PyDbObjectId& layerId) const;
    void                setLineType(const PyDbObjectId& linetypeId) const;
    void                setSelectionMarker(const Adesk::LongPtr markerId) const;
    void                setFillType(const AcGiFillType val) const;
    void                setLineWeight(const AcDb::LineWeight lw) const;
    void                setLineTypeScale1() const;
    void                setLineTypeScale2(double dScale) const;
    void                setThickness(double dThickness) const;
    void                setVisualStyle(const PyDbObjectId& visualStyleId) const;
    void                setPlotStyleName1(AcDb::PlotStyleNameType val) const;
    void                setPlotStyleName2(AcDb::PlotStyleNameType val, const PyDbObjectId& id) const;
    void                setMaterial(const PyDbObjectId& materialId) const;
    void                setSectionable(bool bSectionable) const;
    void                setDrawFlags(Adesk::UInt32 flags) const;
    void                setShadowFlags(AcGiSubEntityTraits::ShadowFlags flags) const;
    void                setSelectionGeom(bool bSelectionflag) const;
    void                setTransparency(const AcCmTransparency& transparency) const;

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
    void                setupForEntity(PyDbEntity& pEntity) const;
    static std::string	className();
    static PyRxClass	desc();
public:
    AcGiDrawableTraits* impObj(const std::source_location& src = std::source_location::current()) const;
};

#pragma pack (pop)