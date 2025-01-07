#pragma once

#ifdef PYRXDEBUG

#include "PyAcad.h" 
//------------------------------------------------------------------------------------
//PyIAcadAcCmColorImpl
class PyIAcadAcCmColorImpl
{
public:
    explicit PyIAcadAcCmColorImpl(IAcadAcCmColor* ptr);
    virtual ~PyIAcadAcCmColorImpl() = default;
    void            SetEntityColor(long val);
    long            GetEntityColor() const;
    CString         GetColorName() const;
    CString         GetBookName() const;
    void            SetNames(const CString& colorName, const CString& bookName);
    void            Delete();
    long            GetRed() const;
    long            GetGreen() const;
    long            GetBlue() const;
    void            SetRGB(long Red, long Green, long Blue);
    AcColorMethod   GetColorMethod() const;
    void            SetColorMethod(AcColorMethod flags);
    AcColor         GetColorIndex() const;
    void            SetColorIndex(AcColor val);
    void            SetColorBookColor(const CString& colorName, const CString& bookName);
    IAcadAcCmColor* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    IAcadAcCmColorPtr m_pimpl;
};

//------------------------------------------------------------------------------------
//PyIAcadHyperlinkImpl
class PyIAcadHyperlinkImpl
{
public:
    explicit PyIAcadHyperlinkImpl(IAcadHyperlink* ptr);
    virtual ~PyIAcadHyperlinkImpl() = default;
    CString         GetURL() const;
    void            SetURL(const CString& val);
    CString         GetURLDescription() const;
    void            SetURLDescription(const CString& val);
    void            Delete();
    CString         GetURLNamedLocation() const;
    void            SetURLNamedLocation(const CString& val);
    IAcadHyperlink* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    IAcadHyperlinkPtr m_pimpl;
};

//------------------------------------------------------------------------------------
//PyIAcadHyperlinksImpl
class PyIAcadHyperlinksImpl
{
public:
    explicit PyIAcadHyperlinksImpl(IAcadHyperlinks* ptr);
    virtual ~PyIAcadHyperlinksImpl() = default;
    PyIAcadHyperlinkImpl    GetItem(long val);
    long                    GetCount() const;
    PyIAcadHyperlinkImpl    Add(const CString& name, const CString& description, const CString& namedLocation);
    IAcadHyperlinks* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    IAcadHyperlinksPtr m_pimpl;
};

//------------------------------------------------------------------------------------
//PyIAcadSectionTypeSettingsImpl
class PyIAcadSectionTypeSettingsImpl
{
public:
    explicit PyIAcadSectionTypeSettingsImpl(IAcadSectionTypeSettings* ptr);
    virtual ~PyIAcadSectionTypeSettingsImpl() = default;

    AcSectionGeneration     GetGenerationOptions() const;
    void                    SetGenerationOptions(AcSectionGeneration val);
    IAcadSectionTypeSettings* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    IAcadSectionTypeSettingsPtr m_pimpl;
    //IAcadSectionTypeSettings2
};

//------------------------------------------------------------------------------------
//PyIAcadDatabasePreferencesImpl
class PyIAcadDatabasePreferences
{
public:
    explicit PyIAcadDatabasePreferences(IAcadDatabasePreferences* ptr);
    virtual ~PyIAcadDatabasePreferences() = default;
    IAcadDatabasePreferences* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    IAcadDatabasePreferencesPtr m_pimpl;
};

//------------------------------------------------------------------------------------
//PyIAcadSummaryInfoImpl
class PyIAcadSummaryInfo
{
public:
    explicit PyIAcadSummaryInfo(IAcadSummaryInfo* ptr);
    virtual ~PyIAcadSummaryInfo() = default;
    IAcadSummaryInfo* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    IAcadSummaryInfoPtr m_pimpl;
};

//------------------------------------------------------------------------------------
//PyIAcadDynamicBlockReferencePropertyImpl
class PyIAcadDynamicBlockReferenceProperty
{
public:
    explicit PyIAcadDynamicBlockReferenceProperty(IAcadDynamicBlockReferenceProperty* ptr);
    virtual ~PyIAcadDynamicBlockReferenceProperty() = default;
    IAcadDynamicBlockReferenceProperty* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    IAcadDynamicBlockReferencePropertyPtr m_pimpl;
};

//------------------------------------------------------------------------------------
//PyIAcadIdPairImpl
class PyIAcadIdPair
{
public:
    explicit PyIAcadIdPair(IAcadIdPair* ptr);
    virtual ~PyIAcadIdPair() = default;
    IAcadIdPair* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    IAcadIdPairPtr m_pimpl;
};

//------------------------------------------------------------------------------------
//PyIAcadShadowDisplayImpl
#ifndef _BRXTARGET
class PyIAcadShadowDisplay
{
public:
    explicit PyIAcadShadowDisplay(IAcadShadowDisplay* ptr);
    virtual ~PyIAcadShadowDisplay() = default;
    IAcadShadowDisplay* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    IAcadShadowDisplayPtr m_pimpl;
};
#endif

//------------------------------------------------------------------------------------
//PyIAcadSubEntityImpl
#ifndef _GRXTARGET
class PyIAcadSubEntity
{
public:
    explicit PyIAcadSubEntity(IAcadSubEntity* ptr);
    virtual ~PyIAcadSubEntity() = default;
    IAcadSubEntity* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    IAcadSubEntityPtr m_pimpl;
};
#endif

//------------------------------------------------------------------------------------
//PyIAcadMLeaderLeader
#ifndef _GRXTARGET
class PyIAcadMLeaderLeader : public PyIAcadSubEntity
{
public:
    explicit PyIAcadMLeaderLeader(IAcadMLeaderLeader* ptr);
    virtual ~PyIAcadMLeaderLeader() = default;
    IAcadMLeaderLeader* impObj(const std::source_location& src = std::source_location::current()) const;
};
#endif

//------------------------------------------------------------------------------------
//PyIAcadSubEntSolidFaceImpl
#ifndef _GRXTARGET
class PyIAcadSubEntSolidFace : public PyIAcadSubEntity
{
public:
    explicit PyIAcadSubEntSolidFace(IAcadSubEntSolidFace* ptr);
    virtual ~PyIAcadSubEntSolidFace() = default;
    IAcadSubEntSolidFace* impObj(const std::source_location& src = std::source_location::current()) const;
};
#endif

//------------------------------------------------------------------------------------
//PyIAcadSubDMeshFaceImpl
#ifndef _GRXTARGET
#ifndef _BRXTARGET
class PyIAcadSubDMeshFace : public PyIAcadSubEntity
{
public:
    explicit PyIAcadSubDMeshFace(IAcadSubDMeshFace* ptr);
    virtual ~PyIAcadSubDMeshFace() = default;
    IAcadSubDMeshFace* impObj(const std::source_location& src = std::source_location::current()) const;
};
#endif
#endif

//------------------------------------------------------------------------------------
//PyIAcadSubDMeshEdgeImpl
#ifndef _GRXTARGET
#ifndef _BRXTARGET
class PyIAcadSubDMeshEdge : public PyIAcadSubEntity
{
public:
    explicit PyIAcadSubDMeshEdge(IAcadSubDMeshEdge* ptr);
    virtual ~PyIAcadSubDMeshEdge() = default;
    IAcadSubDMeshEdge* impObj(const std::source_location& src = std::source_location::current()) const;
};
#endif
#endif

//------------------------------------------------------------------------------------
//PyIAcadSubDMeshVertexImpl
#ifndef _GRXTARGET
#ifndef _BRXTARGET
class PyIAcadSubDMeshVertex : public PyIAcadSubEntity
{
public:
    explicit PyIAcadSubDMeshVertex(IAcadSubDMeshVertex* ptr);
    virtual ~PyIAcadSubDMeshVertex() = default;
    IAcadSubDMeshVertex* impObj(const std::source_location& src = std::source_location::current()) const;
};
#endif
#endif

//------------------------------------------------------------------------------------
//PyIAcadObjectImpl
class PyIAcadObjectImpl
{
public:
    explicit PyIAcadObjectImpl(IAcadObject* ptr);
    virtual ~PyIAcadObjectImpl() = default;
    IAcadObject* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    IAcadObjectPtr m_pimpl;
};

//------------------------------------------------------------------------------------
//PyIAcadEntityImpl
class PyIAcadEntityImpl : public PyIAcadObjectImpl
{
public:
    explicit PyIAcadEntityImpl(IAcadEntity* ptr);
    virtual ~PyIAcadEntityImpl() override = default;
    IAcadEntity* impObj(const std::source_location& src = std::source_location::current()) const;
};

//------------------------------------------------------------------------------------
//PyIAcad3DFaceImpl
class PyIAcad3DFaceImpl : public PyIAcadEntityImpl
{
public:
    explicit PyIAcad3DFaceImpl(IAcad3DFace* ptr);
    virtual ~PyIAcad3DFaceImpl() override = default;
    IAcad3DFace* impObj(const std::source_location& src = std::source_location::current()) const;
};

//------------------------------------------------------------------------------------
//PyIAcadPolygonMeshImpl
class PyIAcadPolygonMeshImpl : public PyIAcadEntityImpl
{
public:
    explicit PyIAcadPolygonMeshImpl(IAcadPolygonMesh* ptr);
    virtual ~PyIAcadPolygonMeshImpl() override = default;
    IAcadPolygonMesh* impObj(const std::source_location& src = std::source_location::current()) const;
};

//------------------------------------------------------------------------------------
//PyIAcad3DPolylineImpl
class PyIAcad3DPolylineImpl : public PyIAcadEntityImpl
{
public:
    explicit PyIAcad3DPolylineImpl(IAcad3DPolyline* ptr);
    virtual ~PyIAcad3DPolylineImpl() override = default;
    IAcad3DPolyline* impObj(const std::source_location& src = std::source_location::current()) const;
};

//------------------------------------------------------------------------------------
//PyIAcadArcImpl
class PyIAcadArcImpl : public PyIAcadEntityImpl
{
public:
    explicit PyIAcadArcImpl(IAcadArc* ptr);
    virtual ~PyIAcadArcImpl() override = default;
    IAcadArc* impObj(const std::source_location& src = std::source_location::current()) const;
};

//------------------------------------------------------------------------------------
//PyIAcadAttributeImpl
class PyIAcadAttributeImpl : public PyIAcadEntityImpl
{
public:
    explicit PyIAcadAttributeImpl(IAcadAttribute* ptr);
    virtual ~PyIAcadAttributeImpl() override = default;
    IAcadAttribute* impObj(const std::source_location& src = std::source_location::current()) const;
};

//------------------------------------------------------------------------------------
//PyIAcadRegionImpl
class PyIAcadRegionImpl : public PyIAcadEntityImpl
{
public:
    explicit PyIAcadRegionImpl(IAcadRegion* ptr);
    virtual ~PyIAcadRegionImpl() override = default;
    IAcadRegion* impObj(const std::source_location& src = std::source_location::current()) const;
};

//------------------------------------------------------------------------------------
//PyIAcad3DSolidImpl
class PyIAcad3DSolidImpl : public PyIAcadEntityImpl
{
public:
    explicit PyIAcad3DSolidImpl(IAcad3DSolid* ptr);
    virtual ~PyIAcad3DSolidImpl() override = default;
    IAcad3DSolid* impObj(const std::source_location& src = std::source_location::current()) const;
};

//------------------------------------------------------------------------------------
//PyIAcadCircleImpl
class PyIAcadCircleImpl : public PyIAcadEntityImpl
{
public:
    explicit PyIAcadCircleImpl(IAcadCircle* ptr);
    virtual ~PyIAcadCircleImpl() override = default;
    IAcadCircle* impObj(const std::source_location& src = std::source_location::current()) const;
};

//------------------------------------------------------------------------------------
//PyIAcadDimensionImpl
class PyIAcadDimensionImpl : public PyIAcadEntityImpl
{
public:
    explicit PyIAcadDimensionImpl(IAcadDimension* ptr);
    virtual ~PyIAcadDimensionImpl() override = default;
    IAcadDimension* impObj(const std::source_location& src = std::source_location::current()) const;
};

//------------------------------------------------------------------------------------
//PyIAcadDimAlignedImpl
class PyIAcadDimAlignedImpl : public PyIAcadDimensionImpl
{
public:
    explicit PyIAcadDimAlignedImpl(IAcadDimAligned* ptr);
    virtual ~PyIAcadDimAlignedImpl() override = default;
    IAcadDimAligned* impObj(const std::source_location& src = std::source_location::current()) const;
};

//------------------------------------------------------------------------------------
//PyIAcadDimAngularImpl
class PyIAcadDimAngularImpl : public PyIAcadDimensionImpl
{
public:
    explicit PyIAcadDimAngularImpl(IAcadDimAngular* ptr);
    virtual ~PyIAcadDimAngularImpl() override = default;
    IAcadDimAngular* impObj(const std::source_location& src = std::source_location::current()) const;
};

//------------------------------------------------------------------------------------
//PyIAcadDimDiametricImpl
class PyIAcadDimDiametricImpl : public PyIAcadDimensionImpl
{
public:
    explicit PyIAcadDimDiametricImpl(IAcadDimDiametric* ptr);
    virtual ~PyIAcadDimDiametricImpl() override = default;
    IAcadDimDiametric* impObj(const std::source_location& src = std::source_location::current()) const;
};

//------------------------------------------------------------------------------------
//PyIAcadDimRotatedImpl
class PyIAcadDimRotatedImpl : public PyIAcadDimensionImpl
{
public:
    explicit PyIAcadDimRotatedImpl(IAcadDimRotated* ptr);
    virtual ~PyIAcadDimRotatedImpl() override = default;
    IAcadDimRotated* impObj(const std::source_location& src = std::source_location::current()) const;
};

//------------------------------------------------------------------------------------
//PyIAcadDimOrdinateImpl
class PyIAcadDimOrdinateImpl : public PyIAcadDimensionImpl
{
public:
    explicit PyIAcadDimOrdinateImpl(IAcadDimOrdinate* ptr);
    virtual ~PyIAcadDimOrdinateImpl() override = default;
    IAcadDimOrdinate* impObj(const std::source_location& src = std::source_location::current()) const;
};

//------------------------------------------------------------------------------------
//PyIAcadDimRadialImpl
class PyIAcadDimRadialImpl : public PyIAcadDimensionImpl
{
public:
    explicit PyIAcadDimRadialImpl(IAcadDimRadial* ptr);
    virtual ~PyIAcadDimRadialImpl() override = default;
    IAcadDimRadial* impObj(const std::source_location& src = std::source_location::current()) const;
};

//------------------------------------------------------------------------------------
//PyIAcadDim3PointAngularImpl
class PyIAcadDim3PointAngularImpl : public PyIAcadDimensionImpl
{
public:
    explicit PyIAcadDim3PointAngularImpl(IAcadDim3PointAngular* ptr);
    virtual ~PyIAcadDim3PointAngularImpl() override = default;
    IAcadDim3PointAngular* impObj(const std::source_location& src = std::source_location::current()) const;
};

//------------------------------------------------------------------------------------
//PyIAcadDimArcLengthImpl
class PyIAcadDimArcLengthImpl : public PyIAcadDimensionImpl
{
public:
    explicit PyIAcadDimArcLengthImpl(IAcadDimArcLength* ptr);
    virtual ~PyIAcadDimArcLengthImpl() override = default;
    IAcadDimArcLength* impObj(const std::source_location& src = std::source_location::current()) const;
};

//------------------------------------------------------------------------------------
//PyIAcadDimRadialLargeImpl
class PyIAcadDimRadialLargeImpl : public PyIAcadDimensionImpl
{
public:
    explicit PyIAcadDimRadialLargeImpl(IAcadDimRadialLarge* ptr);
    virtual ~PyIAcadDimRadialLargeImpl() override = default;
    IAcadDimRadialLarge* impObj(const std::source_location& src = std::source_location::current()) const;
};

//------------------------------------------------------------------------------------
//PyIAcadEllipseImpl
class PyIAcadEllipseImpl : public PyIAcadEntityImpl
{
public:
    explicit PyIAcadEllipseImpl(IAcadEllipse* ptr);
    virtual ~PyIAcadEllipseImpl() override = default;
    IAcadEllipse* impObj(const std::source_location& src = std::source_location::current()) const;
};

//------------------------------------------------------------------------------------
//PyIAcadLeaderImpl
class PyIAcadLeaderImpl : public PyIAcadEntityImpl
{
public:
    explicit PyIAcadLeaderImpl(IAcadLeader* ptr);
    virtual ~PyIAcadLeaderImpl() override = default;
    IAcadLeader* impObj(const std::source_location& src = std::source_location::current()) const;
};

//------------------------------------------------------------------------------------
//PyIAcadMTextImpl
class PyIAcadMTextImpl : public PyIAcadEntityImpl
{
public:
    explicit PyIAcadMTextImpl(IAcadMText* ptr);
    virtual ~PyIAcadMTextImpl() override = default;
    IAcadMText* impObj(const std::source_location& src = std::source_location::current()) const;
};

//------------------------------------------------------------------------------------
//PyIAcadPointImpl
class PyIAcadPointImpl : public PyIAcadEntityImpl
{
public:
    explicit PyIAcadPointImpl(IAcadPoint* ptr);
    virtual ~PyIAcadPointImpl() override = default;
    IAcadPoint* impObj(const std::source_location& src = std::source_location::current()) const;
};

//------------------------------------------------------------------------------------
//PyIAcadLWPolylineImpl
class PyIAcadLWPolylineImpl : public PyIAcadEntityImpl
{
public:
    explicit PyIAcadLWPolylineImpl(IAcadLWPolyline* ptr);
    virtual ~PyIAcadLWPolylineImpl() override = default;
    IAcadLWPolyline* impObj(const std::source_location& src = std::source_location::current()) const;
};

//------------------------------------------------------------------------------------
//PyIAcadPolylineImpl
class PyIAcadPolylineImpl : public PyIAcadEntityImpl
{
public:
    explicit PyIAcadPolylineImpl(IAcadPolyline* ptr);
    virtual ~PyIAcadPolylineImpl() override = default;
    IAcadPolyline* impObj(const std::source_location& src = std::source_location::current()) const;
};

//------------------------------------------------------------------------------------
//PyIAcadRayImpl
class PyIAcadRayImpl : public PyIAcadEntityImpl
{
public:
    explicit PyIAcadRayImpl(IAcadRay* ptr);
    virtual ~PyIAcadRayImpl() override = default;
    IAcadRay* impObj(const std::source_location& src = std::source_location::current()) const;
};

//------------------------------------------------------------------------------------
//PyIAcadShapeImpl
class PyIAcadShapeImpl : public PyIAcadEntityImpl
{
public:
    explicit PyIAcadShapeImpl(IAcadShape* ptr);
    virtual ~PyIAcadShapeImpl() override = default;
    IAcadShape* impObj(const std::source_location& src = std::source_location::current()) const;
};

//------------------------------------------------------------------------------------
//PyIAcadSolidImpl
class PyIAcadSolidImpl : public PyIAcadEntityImpl
{
public:
    explicit PyIAcadSolidImpl(IAcadSolid* ptr);
    virtual ~PyIAcadSolidImpl() override = default;
    IAcadSolid* impObj(const std::source_location& src = std::source_location::current()) const;
};

//------------------------------------------------------------------------------------
//PyIAcadSplineImpl
class PyIAcadSplineImpl : public PyIAcadEntityImpl
{
public:
    explicit PyIAcadSplineImpl(IAcadSpline* ptr);
    virtual ~PyIAcadSplineImpl() override = default;
    IAcadSpline* impObj(const std::source_location& src = std::source_location::current()) const;
};

//------------------------------------------------------------------------------------
//PyIAcadTextImpl
class PyIAcadTextImpl : public PyIAcadEntityImpl
{
public:
    explicit PyIAcadTextImpl(IAcadText* ptr);
    virtual ~PyIAcadTextImpl() override = default;
    IAcadText* impObj(const std::source_location& src = std::source_location::current()) const;
};

//------------------------------------------------------------------------------------
//PyIAcadToleranceImpl
class PyIAcadToleranceImpl : public PyIAcadEntityImpl
{
public:
    explicit PyIAcadToleranceImpl(IAcadTolerance* ptr);
    virtual ~PyIAcadToleranceImpl() override = default;
    IAcadTolerance* impObj(const std::source_location& src = std::source_location::current()) const;
};

//------------------------------------------------------------------------------------
//PyIAcadTraceImpl
class PyIAcadTraceImpl : public PyIAcadEntityImpl
{
public:
    explicit PyIAcadTraceImpl(IAcadTrace* ptr);
    virtual ~PyIAcadTraceImpl() override = default;
    IAcadTrace* impObj(const std::source_location& src = std::source_location::current()) const;
};

//------------------------------------------------------------------------------------
//PyIAcadXlineImpl
class PyIAcadXlineImpl : public PyIAcadEntityImpl
{
public:
    explicit PyIAcadXlineImpl(IAcadXline* ptr);
    virtual ~PyIAcadXlineImpl() override = default;
    IAcadXline* impObj(const std::source_location& src = std::source_location::current()) const;
};

//------------------------------------------------------------------------------------
//PyIAcadBlockReferenceImpl
class PyIAcadBlockReferenceImpl : public PyIAcadEntityImpl
{
public:
    explicit PyIAcadBlockReferenceImpl(IAcadBlockReference* ptr);
    virtual ~PyIAcadBlockReferenceImpl() override = default;
    IAcadBlockReference* impObj(const std::source_location& src = std::source_location::current()) const;
};

//------------------------------------------------------------------------------------
//PyIAcadHatchImpl
class PyIAcadHatchImpl : public PyIAcadEntityImpl
{
public:
    explicit PyIAcadHatchImpl(IAcadHatch* ptr);
    virtual ~PyIAcadHatchImpl() override = default;
    IAcadHatch* impObj(const std::source_location& src = std::source_location::current()) const;
};

//------------------------------------------------------------------------------------
//PyIAcadRasterImageImpl
class PyIAcadRasterImageImpl : public PyIAcadEntityImpl
{
public:
    explicit PyIAcadRasterImageImpl(IAcadRasterImage* ptr);
    virtual ~PyIAcadRasterImageImpl() override = default;
    IAcadRasterImage* impObj(const std::source_location& src = std::source_location::current()) const;
};

//------------------------------------------------------------------------------------
//PyIAcadLineImpl
class PyIAcadLineImpl : public PyIAcadEntityImpl
{
public:
    explicit PyIAcadLineImpl(IAcadLine* ptr);
    virtual ~PyIAcadLineImpl() override = default;
    IAcadLine* impObj(const std::source_location& src = std::source_location::current()) const;
};









#endif

