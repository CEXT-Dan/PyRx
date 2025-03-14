#pragma once
#include "PyAcadObjectImpl.h"


#pragma pack (push, 8)
//------------------------------------------------------------------------------------
//PyIAcad helpers
IAcadObject* GetIAcadObjectFromAcDbObjectId(const AcDbObjectId& eid);
IAcadObject* GetIAcadObjectFromAcDbObject(AcDbObject* pSrcObject);
IAcadDatabase* GetIAcadDatabaseFromAcDbDatabse(AcDbDatabase* pSrcObject);

class PyAcadApplicationImpl;
using PyAcadApplicationPtr = std::unique_ptr<PyAcadApplicationImpl>;
class PyIAcadDictionaryImpl;
using PyIAcadDictionaryPtr = std::unique_ptr<PyIAcadDictionaryImpl>;
class PyIAcadDocumentImpl;
using PyIAcadDocumentPtr = std::unique_ptr<PyIAcadDocumentImpl>;
class PyIAcadDatabaseImpl;
using PyIAcadDatabasePtr = std::unique_ptr<PyIAcadDatabaseImpl>;
class PyIAcadSectionTypeSettingsImpl;
using PyIAcadSectionTypeSettingsPtr = std::unique_ptr<PyIAcadSectionTypeSettingsImpl>;

//------------------------------------------------------------------------------------
//PyIAcadObjectImpl
class PyIAcadObjectImpl
{
public:
    explicit PyIAcadObjectImpl(IAcadObject* ptr);
    virtual ~PyIAcadObjectImpl() = default;
    CString                 GetHandle() const;
    CString                 GetObjectName() const;
    TypedVariants           GetXData(const CString& appName) const;
    void                    SetXData(const TypedVariants& typedVariants);
    void                    Delete();
    LONG_PTR                GetObjectId() const;
    LONG_PTR                GetOwnerId() const;
    PyIAcadDatabasePtr      GetDatabase() const;
    bool                    GetHasExtensionDictionary() const;
    PyIAcadDictionaryPtr    GetExtensionDictionary() const;
    PyIAcadDocumentPtr      GetDocument() const;
    void                    Erase();
    bool                    IsEqualTo(const PyIAcadObjectImpl& other);
    bool                    IsNull();
    std::size_t             hash() const;
    AcDbObjectId            id() const;
public:
    IAcadObject* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    IAcadObjectPtr m_pimpl;
};
using PyIAcadObjectPtr = std::unique_ptr<PyIAcadObjectImpl>;
using PyIAcadObjectPtrArray = std::vector<std::shared_ptr<PyIAcadObjectImpl>>;

//------------------------------------------------------------------------------------
//PyIAcadPlotConfigurationImpl
class PyIAcadPlotConfigurationImpl : public PyIAcadObjectImpl
{
public:
    explicit PyIAcadPlotConfigurationImpl(IAcadPlotConfiguration* ptr);
    virtual ~PyIAcadPlotConfigurationImpl() = default;

    CString             GetName() const;
    void                SetName(const CString& val);
    CString             GetConfigName() const;
    void                SetConfigName(const CString& val);
    CString             GetCanonicalMediaName() const;
    void                SetCanonicalMediaName(const CString& val);
    PyAcPlotPaperUnits  GetPaperUnits() const;
    void                SetPaperUnits(PyAcPlotPaperUnits val);
    bool                GetPlotViewportBorders() const;
    void                SetPlotViewportBorders(bool val);
    bool                GetShowPlotStyles() const;
    void                SetShowPlotStyles(bool val);
    PyAcPlotRotation    GetPlotRotation() const;
    void                SetPlotRotation(PyAcPlotRotation val);
    bool                GetCenterPlot() const;
    void                SetCenterPlot(bool val);
    bool                GetPlotHidden() const;
    void                SetPlotHidden(bool val);
    PyAcPlotType        GetPlotType() const;
    void                SetPlotType(PyAcPlotType val);
    CString             GetViewToPlot() const;
    void                SetViewToPlot(const CString& val);
    bool                GetUseStandardScale() const;
    void                SetUseStandardScale(bool val);
    PyAcPlotScale       GetStandardScale() const;
    void                SetStandardScale(PyAcPlotScale val);
    void                GetCustomScale(double& numerator, double& denominator);
    void                SetCustomScale(double numerator, double denominator);
    bool                GetScaleLineweights() const;
    void                SetScaleLineweights(bool val);
    bool                GetPlotWithLineweights() const;
    void                SetPlotWithLineweights(bool val);
    bool                GetPlotViewportsFirst() const;
    void                SetPlotViewportsFirst(bool val);
    CString             GetStyleSheet() const;
    void                SetStyleSheet(const CString& val);
    void                GetPaperMargins(AcGePoint2d& lowerLeft, AcGePoint2d& upperRight);
    void                GetPaperSize(double& width, double& height);
    AcGePoint2d         GetPlotOrigin();
    void                SetPlotOrigin(const AcGePoint2d& orgin);
    void                GetWindowToPlot(AcGePoint2d& lowerLeft, AcGePoint2d& upperRight);
    void                SetWindowToPlot(const AcGePoint2d& lowerLeft,const AcGePoint2d& upperRight);
    bool                GetPlotWithPlotStyles() const;
    void                SetPlotWithPlotStyles(bool val);
    bool                GetModelType() const;
    void                CopyFrom(const PyIAcadPlotConfigurationImpl& val);
    wstringArray        GetCanonicalMediaNames() const;
    wstringArray        GetPlotDeviceNames() const;
    wstringArray        GetPlotStyleTableNames() const;
    void                RefreshPlotDeviceInfo();
    CString             GetLocaleMediaName(const CString& name) const;

    IAcadPlotConfiguration* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadPlotConfigurationPtr = std::unique_ptr<PyIAcadPlotConfigurationImpl>;

//------------------------------------------------------------------------------------
//PyIAcadLayoutImpl
class PyIAcadLayoutImpl : public PyIAcadPlotConfigurationImpl
{
public:
    explicit PyIAcadLayoutImpl(IAcadLayout* ptr);
    virtual ~PyIAcadLayoutImpl() = default;

    PyIAcadBlockPtr GetBlock() const;
    long            GetTabOrder() const;
    void            SetTabOrder(long val);

    IAcadLayout* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadLayoutPtr = std::unique_ptr<PyIAcadLayoutImpl>;

//------------------------------------------------------------------------------------
//PyIAcadSectionSettingsImpl
class PyIAcadSectionSettingsImpl : public PyIAcadObjectImpl
{
public:
    explicit PyIAcadSectionSettingsImpl(IAcadSectionSettings* ptr);
    virtual ~PyIAcadSectionSettingsImpl() = default;

    PyAcSectionType                 GetCurrentSectionType() const;
    void                            SetCurrentSectionType(PyAcSectionType val) const;
    PyIAcadSectionTypeSettingsPtr   GetSectionTypeSettings(PyAcSectionType secType) const;

    IAcadSectionSettings* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadSectionSettingsPtr = std::unique_ptr<PyIAcadSectionSettingsImpl>;

//------------------------------------------------------------------------------------
//PyIAcadViewImpl
class PyIAcadViewImpl : public PyIAcadObjectImpl
{
public:
    explicit PyIAcadViewImpl(IAcadView* ptr);
    virtual ~PyIAcadViewImpl() = default;

    AcGePoint3d             GetCenter() const;
    void                    SetCenter(const AcGePoint3d& val);
    double                  GetHeight() const;
    void                    SetHeight(double val);
    double                  GetWidth() const;
    void                    SetWidth(double val);
    AcGePoint3d             GetTarget() const;
    void                    SetTarget(const AcGePoint3d& val);
    AcGeVector3d            GetDirection() const;
    void                    SetDirection(const AcGeVector3d& val);
    CString                 GetName() const;
    void                    SetName(const CString& val);
    CString                 GetCategoryName() const;
    void                    SetCategoryName(const CString& val);
    AcDbObjectId            GetLayoutId() const;
    void                    SetLayoutId(const AcDbObjectId& val);
    CString                 GetLayerState() const;
    void                    SetLayerState(const CString& val);
    bool                    GetHasVpAssociation() const;
    void                    SetHasVpAssociation(bool val);

    IAcadView* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadViewPtr = std::unique_ptr<PyIAcadViewImpl>;

//------------------------------------------------------------------------------------
//PyIAcadGroupImpl
class PyIAcadGroupImpl : public PyIAcadObjectImpl
{
public:
    explicit PyIAcadGroupImpl(IAcadGroup* ptr);
    virtual ~PyIAcadGroupImpl() = default;
    IAcadGroup* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadGroupPtr = std::unique_ptr<PyIAcadGroupImpl>;

//------------------------------------------------------------------------------------
//PyIAcadGroupsImpl
class PyIAcadGroupsImpl : public PyIAcadObjectImpl
{
public:
    explicit PyIAcadGroupsImpl(IAcadGroups* ptr);
    virtual ~PyIAcadGroupsImpl() = default;
    IAcadGroups* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadGroupsPtr = std::unique_ptr<PyIAcadGroupsImpl>;

//------------------------------------------------------------------------------------
//PyIAcadDimStyleImpl
class PyIAcadDimStyleImpl : public PyIAcadObjectImpl
{
public:
    explicit PyIAcadDimStyleImpl(IAcadDimStyle* ptr);
    virtual ~PyIAcadDimStyleImpl() = default;
    IAcadDimStyle* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadDimStylePtr = std::unique_ptr<PyIAcadDimStyleImpl>;

//------------------------------------------------------------------------------------
//PyIAcadDimStylesImpl
class PyIAcadDimStylesImpl : public PyIAcadObjectImpl
{
public:
    explicit PyIAcadDimStylesImpl(IAcadDimStyles* ptr);
    virtual ~PyIAcadDimStylesImpl() = default;
    IAcadDimStyles* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadDimStylesPtr = std::unique_ptr<PyIAcadDimStylesImpl>;

//------------------------------------------------------------------------------------
//PyIAcadLayerImpl
class PyIAcadLayerImpl : public PyIAcadObjectImpl
{
public:
    explicit PyIAcadLayerImpl(IAcadLayer* ptr);
    virtual ~PyIAcadLayerImpl() = default;
    IAcadLayer* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadLayerPtr = std::unique_ptr<PyIAcadLayerImpl>;

//------------------------------------------------------------------------------------
//PyIAcadLayersImpl
class PyIAcadLayersImpl : public PyIAcadObjectImpl
{
public:
    explicit PyIAcadLayersImpl(IAcadLayers* ptr);
    virtual ~PyIAcadLayersImpl() = default;
    IAcadLayers* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadLayersPtr = std::unique_ptr<PyIAcadLayersImpl>;

//------------------------------------------------------------------------------------
//PyIAcadLineTypeImpl
class PyIAcadLineTypeImpl : public PyIAcadObjectImpl
{
public:
    explicit PyIAcadLineTypeImpl(IAcadLineType* ptr);
    virtual ~PyIAcadLineTypeImpl() = default;
    IAcadLineType* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadLineTypePtr = std::unique_ptr<PyIAcadLineTypeImpl>;

//------------------------------------------------------------------------------------
//PyIAcadLineTypesImpl
class PyIAcadLineTypesImpl : public PyIAcadObjectImpl
{
public:
    explicit PyIAcadLineTypesImpl(IAcadLineTypes* ptr);
    virtual ~PyIAcadLineTypesImpl() = default;
    IAcadLineTypes* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadLineTypesPtr = std::unique_ptr<PyIAcadLineTypesImpl>;

//------------------------------------------------------------------------------------
//PyIAcadXRecordImpl
class PyIAcadXRecordImpl : public PyIAcadObjectImpl
{
public:
    explicit PyIAcadXRecordImpl(IAcadXRecord* ptr);
    virtual ~PyIAcadXRecordImpl() = default;
    IAcadXRecord* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadXRecordPtr = std::unique_ptr<PyIAcadXRecordImpl>;

//------------------------------------------------------------------------------------
//PyIAcadDictionaryImpl
class PyIAcadDictionaryImpl : public PyIAcadObjectImpl
{
public:
    explicit PyIAcadDictionaryImpl(IAcadDictionary* ptr);
    virtual ~PyIAcadDictionaryImpl() = default;
    IAcadDictionary* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadDictionaryPtr = std::unique_ptr<PyIAcadDictionaryImpl>;

//------------------------------------------------------------------------------------
//PyIAcadDictionariesImpl
class PyIAcadDictionariesImpl : public PyIAcadObjectImpl
{
public:
    explicit PyIAcadDictionariesImpl(IAcadDictionaries* ptr);
    virtual ~PyIAcadDictionariesImpl() = default;
    IAcadDictionaries* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadDictionariesPtr = std::unique_ptr<PyIAcadDictionariesImpl>;

//------------------------------------------------------------------------------------
//PyIAcadRegisteredApplicationImpl
class PyIAcadRegisteredApplicationImpl : public PyIAcadObjectImpl
{
public:
    explicit PyIAcadRegisteredApplicationImpl(IAcadRegisteredApplication* ptr);
    virtual ~PyIAcadRegisteredApplicationImpl() = default;
    CString     GetName() const;
    void        SetName(const CString& val) const;
    IAcadRegisteredApplication* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadRegisteredApplicationPtr = std::unique_ptr<PyIAcadRegisteredApplicationImpl>;

//------------------------------------------------------------------------------------
//PyIAcadRegisteredApplicationsImpl
class PyIAcadRegisteredApplicationsImpl : public PyIAcadObjectImpl
{
public:
    explicit PyIAcadRegisteredApplicationsImpl(IAcadRegisteredApplications* ptr);
    virtual ~PyIAcadRegisteredApplicationsImpl() = default;

    PyIAcadRegisteredApplicationPtr GetItem(long ind) const;
    long                            GetCount() const;
    PyIAcadRegisteredApplicationPtr Add(const CString& name) const;

    IAcadRegisteredApplications* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadRegisteredApplicationsPtr = std::unique_ptr<PyIAcadRegisteredApplicationsImpl>;

//------------------------------------------------------------------------------------
//PyIAcadTextStyleImpl
class PyIAcadTextStyleImpl : public PyIAcadObjectImpl
{
public:
    explicit PyIAcadTextStyleImpl(IAcadTextStyle* ptr);
    virtual ~PyIAcadTextStyleImpl() = default;
    IAcadTextStyle* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadTextStylePtr = std::unique_ptr<PyIAcadTextStyleImpl>;

//------------------------------------------------------------------------------------
//PyIAcadTextStylesImpl
class PyIAcadTextStylesImpl : public PyIAcadObjectImpl
{
public:
    explicit PyIAcadTextStylesImpl(IAcadTextStyles* ptr);
    virtual ~PyIAcadTextStylesImpl() = default;
    IAcadTextStyles* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadTextStylesPtr = std::unique_ptr<PyIAcadTextStylesImpl>;

//------------------------------------------------------------------------------------
//PyIAcadUCSImpl
class PyIAcadUCSImpl : public PyIAcadObjectImpl
{
public:
    explicit PyIAcadUCSImpl(IAcadUCS* ptr);
    virtual ~PyIAcadUCSImpl() = default;
    IAcadUCS* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadUCSPtr = std::unique_ptr<PyIAcadUCSImpl>;

//------------------------------------------------------------------------------------
//PyIAcadUCSsImpl
class PyIAcadUCSsImpl : public PyIAcadObjectImpl
{
public:
    explicit PyIAcadUCSsImpl(IAcadUCSs* ptr);
    virtual ~PyIAcadUCSsImpl() = default;
    IAcadUCSs* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadUCSsPtr = std::unique_ptr<PyIAcadUCSsImpl>;

//------------------------------------------------------------------------------------
//PyIAcadViewsImpl
class PyIAcadViewsImpl : public PyIAcadObjectImpl
{
public:
    explicit PyIAcadViewsImpl(IAcadViews* ptr);
    virtual ~PyIAcadViewsImpl() = default;
    IAcadViews* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadViewsPtr = std::unique_ptr<PyIAcadViewsImpl>;

//------------------------------------------------------------------------------------
//PyIAcadViewportImpl
class PyIAcadViewportImpl : public PyIAcadObjectImpl
{
public:
    explicit PyIAcadViewportImpl(IAcadViewport* ptr);
    virtual ~PyIAcadViewportImpl() = default;
    IAcadViewport* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadViewportPtr = std::unique_ptr<PyIAcadViewportImpl>;

//------------------------------------------------------------------------------------
//PyIAcadViewportsImpl
class PyIAcadViewportsImpl : public PyIAcadObjectImpl
{
public:
    explicit PyIAcadViewportsImpl(IAcadViewports* ptr);
    virtual ~PyIAcadViewportsImpl() = default;
    IAcadViewports* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadViewportsPtr = std::unique_ptr<PyIAcadViewportsImpl>;

//------------------------------------------------------------------------------------
//PyIAcadPlotConfigurationsImpl
class PyIAcadPlotConfigurationsImpl : public PyIAcadObjectImpl
{
public:
    explicit PyIAcadPlotConfigurationsImpl(IAcadPlotConfigurations* ptr);
    virtual ~PyIAcadPlotConfigurationsImpl() = default;
    IAcadPlotConfigurations* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadPlotConfigurationsPtr = std::unique_ptr<PyIAcadPlotConfigurationsImpl>;

//------------------------------------------------------------------------------------
//PyIAcadSectionManagerImpl
class PyIAcadSectionManagerImpl : public PyIAcadObjectImpl
{
public:
    explicit PyIAcadSectionManagerImpl(IAcadSectionManager* ptr);
    virtual ~PyIAcadSectionManagerImpl() = default;
    IAcadSectionManager* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadSectionManagerPtr = std::unique_ptr<PyIAcadSectionManagerImpl>;

//------------------------------------------------------------------------------------
//PyIAcadMaterialImpl
class PyIAcadMaterialImpl : public PyIAcadObjectImpl
{
public:
    explicit PyIAcadMaterialImpl(IAcadMaterial* ptr);
    virtual ~PyIAcadMaterialImpl() = default;
    IAcadMaterial* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadMaterialPtr = std::unique_ptr<PyIAcadMaterialImpl>;

//------------------------------------------------------------------------------------
//PyIAcadMaterialsImpl
class PyIAcadMaterialsImpl : public PyIAcadObjectImpl
{
public:
    explicit PyIAcadMaterialsImpl(IAcadMaterials* ptr);
    virtual ~PyIAcadMaterialsImpl() = default;
    IAcadMaterials* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadMaterialsPtr = std::unique_ptr<PyIAcadMaterialsImpl>;

//------------------------------------------------------------------------------------
//PyIAcadTableStyleImpl
class PyIAcadTableStyleImpl : public PyIAcadObjectImpl
{
public:
    explicit PyIAcadTableStyleImpl(IAcadTableStyle* ptr);
    virtual ~PyIAcadTableStyleImpl() = default;
    IAcadTableStyle* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadTableStylePtr = std::unique_ptr<PyIAcadTableStyleImpl>;


//------------------------------------------------------------------------------------
//PyIAcadMLeaderStyleImpl
class PyIAcadMLeaderStyleImpl : public PyIAcadObjectImpl
{
public:
    explicit PyIAcadMLeaderStyleImpl(IAcadMLeaderStyle* ptr);
    virtual ~PyIAcadMLeaderStyleImpl() = default;
    IAcadMLeaderStyle* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadMLeaderStylePtr = std::unique_ptr<PyIAcadMLeaderStyleImpl>;

//------------------------------------------------------------------------------------
//PyIAcadLayoutsImpl
class PyIAcadLayoutsImpl : public PyIAcadObjectImpl
{
public:
    explicit PyIAcadLayoutsImpl(IAcadLayouts* ptr);
    virtual ~PyIAcadLayoutsImpl() = default;

    PyIAcadLayoutPtr GetItem(long ind) const;
    long             GetCount() const;
    PyIAcadLayoutPtr Add(const CString& name) const;

    IAcadLayouts* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadLayoutsPtr = std::unique_ptr<PyIAcadLayoutsImpl>;

//------------------------------------------------------------------------------------
//PyIAcadSortentsTableImpl
class PyIAcadSortentsTableImpl : public PyIAcadObjectImpl
{
public:
    explicit PyIAcadSortentsTableImpl(IAcadSortentsTable* ptr);
    virtual ~PyIAcadSortentsTableImpl() = default;
    IAcadSortentsTable* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadSortentsTablePtr = std::unique_ptr<PyIAcadSortentsTableImpl>;

#pragma pack (pop)
