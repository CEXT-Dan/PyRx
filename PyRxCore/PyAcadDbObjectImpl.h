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

class PyIAcadEntityImpl;
using PyIAcadEntityPtr = std::unique_ptr<PyIAcadEntityImpl>;

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
public:
    IAcadObject*            impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    IAcadObjectPtr m_pimpl;
};

//------------------------------------------------------------------------------------
//PyIAcadPlotConfigurationImpl
class PyIAcadPlotConfigurationImpl : public PyIAcadObjectImpl
{
public:
    explicit PyIAcadPlotConfigurationImpl(IAcadPlotConfiguration* ptr);
    virtual ~PyIAcadPlotConfigurationImpl() = default;
    IAcadPlotConfiguration* impObj(const std::source_location& src = std::source_location::current()) const;
};

//------------------------------------------------------------------------------------
//PyIAcadLayoutImpl
class PyIAcadLayoutImpl;
using PyIAcadLayoutPtr = std::unique_ptr<PyIAcadLayoutImpl>;
class PyIAcadLayoutImpl : public PyIAcadPlotConfigurationImpl
{
public:
    explicit PyIAcadLayoutImpl(IAcadLayout* ptr);
    virtual ~PyIAcadLayoutImpl() = default;
    IAcadLayout* impObj(const std::source_location& src = std::source_location::current()) const;
};

//------------------------------------------------------------------------------------
//PyIAcadSectionSettingsImpl
class PyIAcadSectionSettingsImpl : public PyIAcadObjectImpl
{
public:
    explicit PyIAcadSectionSettingsImpl(IAcadSectionSettings* ptr);
    virtual ~PyIAcadSectionSettingsImpl() = default;
    IAcadSectionSettings* impObj(const std::source_location& src = std::source_location::current()) const;
};

//------------------------------------------------------------------------------------
//PyIAcadViewImpl
class PyIAcadViewImpl : public PyIAcadObjectImpl
{
public:
    explicit PyIAcadViewImpl(IAcadView* ptr);
    virtual ~PyIAcadViewImpl() = default;
    IAcadView* impObj(const std::source_location& src = std::source_location::current()) const;
};

//------------------------------------------------------------------------------------
//PyIAcadGroupImpl
class PyIAcadGroupImpl : public PyIAcadObjectImpl
{
public:
    explicit PyIAcadGroupImpl(IAcadGroup* ptr);
    virtual ~PyIAcadGroupImpl() = default;
    IAcadGroup* impObj(const std::source_location& src = std::source_location::current()) const;
};

//------------------------------------------------------------------------------------
//PyIAcadGroupsImpl
class PyIAcadGroupsImpl : public PyIAcadObjectImpl
{
public:
    explicit PyIAcadGroupsImpl(IAcadGroups* ptr);
    virtual ~PyIAcadGroupsImpl() = default;
    IAcadGroups* impObj(const std::source_location& src = std::source_location::current()) const;
};

//------------------------------------------------------------------------------------
//PyIAcadDimStyleImpl
class PyIAcadDimStyleImpl;
using PyIAcadDimStylePtr = std::unique_ptr<PyIAcadDimStyleImpl>;
class PyIAcadDimStyleImpl : public PyIAcadObjectImpl
{
public:
    explicit PyIAcadDimStyleImpl(IAcadDimStyle* ptr);
    virtual ~PyIAcadDimStyleImpl() = default;
    IAcadDimStyle* impObj(const std::source_location& src = std::source_location::current()) const;
};

//------------------------------------------------------------------------------------
//PyIAcadDimStylesImpl
class PyIAcadDimStylesImpl : public PyIAcadObjectImpl
{
public:
    explicit PyIAcadDimStylesImpl(IAcadDimStyles* ptr);
    virtual ~PyIAcadDimStylesImpl() = default;
    IAcadDimStyles* impObj(const std::source_location& src = std::source_location::current()) const;
};

//------------------------------------------------------------------------------------
//PyIAcadLayerImpl
class PyIAcadLayerImpl;
using PyIAcadLayerPtr = std::unique_ptr<PyIAcadLayerImpl>;
class PyIAcadLayerImpl : public PyIAcadObjectImpl
{
public:
    explicit PyIAcadLayerImpl(IAcadLayer* ptr);
    virtual ~PyIAcadLayerImpl() = default;
    IAcadLayer* impObj(const std::source_location& src = std::source_location::current()) const;
};

//------------------------------------------------------------------------------------
//PyIAcadLayersImpl
class PyIAcadLayersImpl : public PyIAcadObjectImpl
{
public:
    explicit PyIAcadLayersImpl(IAcadLayers* ptr);
    virtual ~PyIAcadLayersImpl() = default;
    IAcadLayers* impObj(const std::source_location& src = std::source_location::current()) const;
};

//------------------------------------------------------------------------------------
//PyIAcadLineTypeImpl
class PyIAcadLineTypeImpl;
using PyIAcadLineTypePtr = std::unique_ptr<PyIAcadLineTypeImpl>;
class PyIAcadLineTypeImpl : public PyIAcadObjectImpl
{
public:
    explicit PyIAcadLineTypeImpl(IAcadLineType* ptr);
    virtual ~PyIAcadLineTypeImpl() = default;
    IAcadLineType* impObj(const std::source_location& src = std::source_location::current()) const;
};

//------------------------------------------------------------------------------------
//PyIAcadLineTypesImpl
class PyIAcadLineTypesImpl : public PyIAcadObjectImpl
{
public:
    explicit PyIAcadLineTypesImpl(IAcadLineTypes* ptr);
    virtual ~PyIAcadLineTypesImpl() = default;
    IAcadLineTypes* impObj(const std::source_location& src = std::source_location::current()) const;
};

//------------------------------------------------------------------------------------
//PyIAcadXRecordImpl
class PyIAcadXRecordImpl : public PyIAcadObjectImpl
{
public:
    explicit PyIAcadXRecordImpl(IAcadXRecord* ptr);
    virtual ~PyIAcadXRecordImpl() = default;
    IAcadXRecord* impObj(const std::source_location& src = std::source_location::current()) const;
};

//------------------------------------------------------------------------------------
//PyIAcadDictionaryImpl
class PyIAcadDictionaryImpl : public PyIAcadObjectImpl
{
public:
    explicit PyIAcadDictionaryImpl(IAcadDictionary* ptr);
    virtual ~PyIAcadDictionaryImpl() = default;
    IAcadDictionary* impObj(const std::source_location& src = std::source_location::current()) const;
};

//------------------------------------------------------------------------------------
//PyIAcadDictionariesImpl
class PyIAcadDictionariesImpl : public PyIAcadObjectImpl
{
public:
    explicit PyIAcadDictionariesImpl(IAcadDictionaries* ptr);
    virtual ~PyIAcadDictionariesImpl() = default;
    IAcadDictionaries* impObj(const std::source_location& src = std::source_location::current()) const;
};

//------------------------------------------------------------------------------------
//PyIAcadRegisteredApplicationImpl
class PyIAcadRegisteredApplicationImpl : public PyIAcadObjectImpl
{
public:
    explicit PyIAcadRegisteredApplicationImpl(IAcadRegisteredApplication* ptr);
    virtual ~PyIAcadRegisteredApplicationImpl() = default;
    IAcadRegisteredApplication* impObj(const std::source_location& src = std::source_location::current()) const;
};

//------------------------------------------------------------------------------------
//PyIAcadRegisteredApplicationsImpl
class PyIAcadRegisteredApplicationsImpl : public PyIAcadObjectImpl
{
public:
    explicit PyIAcadRegisteredApplicationsImpl(IAcadRegisteredApplications* ptr);
    virtual ~PyIAcadRegisteredApplicationsImpl() = default;
    IAcadRegisteredApplications* impObj(const std::source_location& src = std::source_location::current()) const;
};

//------------------------------------------------------------------------------------
//PyIAcadTextStyleImpl
class PyIAcadTextStyleImpl;
using PyIAcadTextStylePtr = std::unique_ptr<PyIAcadTextStyleImpl>;
class PyIAcadTextStyleImpl : public PyIAcadObjectImpl
{
public:
    explicit PyIAcadTextStyleImpl(IAcadTextStyle* ptr);
    virtual ~PyIAcadTextStyleImpl() = default;
    IAcadTextStyle* impObj(const std::source_location& src = std::source_location::current()) const;
};

//------------------------------------------------------------------------------------
//PyIAcadTextStylesImpl
class PyIAcadTextStylesImpl : public PyIAcadObjectImpl
{
public:
    explicit PyIAcadTextStylesImpl(IAcadTextStyles* ptr);
    virtual ~PyIAcadTextStylesImpl() = default;
    IAcadTextStyles* impObj(const std::source_location& src = std::source_location::current()) const;
};

//------------------------------------------------------------------------------------
//PyIAcadUCSImpl
class PyIAcadUCSImpl;
using PyIAcadUCSPtr = std::unique_ptr<PyIAcadUCSImpl>;
class PyIAcadUCSImpl : public PyIAcadObjectImpl
{
public:
    explicit PyIAcadUCSImpl(IAcadUCS* ptr);
    virtual ~PyIAcadUCSImpl() = default;
    IAcadUCS* impObj(const std::source_location& src = std::source_location::current()) const;
};

//------------------------------------------------------------------------------------
//PyIAcadUCSsImpl
class PyIAcadUCSsImpl : public PyIAcadObjectImpl
{
public:
    explicit PyIAcadUCSsImpl(IAcadUCSs* ptr);
    virtual ~PyIAcadUCSsImpl() = default;
    IAcadUCSs* impObj(const std::source_location& src = std::source_location::current()) const;
};

//------------------------------------------------------------------------------------
//PyIAcadViewsImpl
class PyIAcadViewsImpl : public PyIAcadObjectImpl
{
public:
    explicit PyIAcadViewsImpl(IAcadViews* ptr);
    virtual ~PyIAcadViewsImpl() = default;
    IAcadViews* impObj(const std::source_location& src = std::source_location::current()) const;
};

//------------------------------------------------------------------------------------
//PyIAcadViewportImpl
class PyIAcadViewportImpl;
using PyIAcadViewportPtr = std::unique_ptr<PyIAcadViewportImpl>;
class PyIAcadViewportImpl : public PyIAcadObjectImpl
{
public:
    explicit PyIAcadViewportImpl(IAcadViewport* ptr);
    virtual ~PyIAcadViewportImpl() = default;
    IAcadViewport* impObj(const std::source_location& src = std::source_location::current()) const;
};

//------------------------------------------------------------------------------------
//PyIAcadViewportsImpl
class PyIAcadViewportsImpl : public PyIAcadObjectImpl
{
public:
    explicit PyIAcadViewportsImpl(IAcadViewports* ptr);
    virtual ~PyIAcadViewportsImpl() = default;
    IAcadViewports* impObj(const std::source_location& src = std::source_location::current()) const;
};

//------------------------------------------------------------------------------------
//PyIAcadPlotConfigurationsImpl
class PyIAcadPlotConfigurationsImpl : public PyIAcadObjectImpl
{
public:
    explicit PyIAcadPlotConfigurationsImpl(IAcadPlotConfigurations* ptr);
    virtual ~PyIAcadPlotConfigurationsImpl() = default;
    IAcadPlotConfigurations* impObj(const std::source_location& src = std::source_location::current()) const;
};

//------------------------------------------------------------------------------------
//PyIAcadSectionManagerImpl
class PyIAcadSectionManagerImpl : public PyIAcadObjectImpl
{
public:
    explicit PyIAcadSectionManagerImpl(IAcadPlotConfigurations* ptr);
    virtual ~PyIAcadSectionManagerImpl() = default;
    IAcadSectionManager* impObj(const std::source_location& src = std::source_location::current()) const;
};

//------------------------------------------------------------------------------------
//PyIAcadMaterialImpl
class PyIAcadMaterialImpl;
using PyIAcadMaterialPtr = std::unique_ptr<PyIAcadMaterialImpl>;
class PyIAcadMaterialImpl : public PyIAcadObjectImpl
{
public:
    explicit PyIAcadMaterialImpl(IAcadMaterial* ptr);
    virtual ~PyIAcadMaterialImpl() = default;
    IAcadMaterial* impObj(const std::source_location& src = std::source_location::current()) const;
};

//------------------------------------------------------------------------------------
//PyIAcadMaterialsImpl
class PyIAcadMaterialsImpl : public PyIAcadObjectImpl
{
public:
    explicit PyIAcadMaterialsImpl(IAcadMaterial* ptr);
    virtual ~PyIAcadMaterialsImpl() = default;
    IAcadMaterials* impObj(const std::source_location& src = std::source_location::current()) const;
};

//------------------------------------------------------------------------------------
//PyIAcadTableStyleImpl
class PyIAcadTableStyleImpl : public PyIAcadObjectImpl
{
public:
    explicit PyIAcadTableStyleImpl(IAcadTableStyle* ptr);
    virtual ~PyIAcadTableStyleImpl() = default;
    IAcadTableStyle* impObj(const std::source_location& src = std::source_location::current()) const;
};

//------------------------------------------------------------------------------------
//PyIAcadMLeaderStyleImpl
class PyIAcadMLeaderStyleImpl : public PyIAcadObjectImpl
{
public:
    explicit PyIAcadMLeaderStyleImpl(IAcadMLeaderStyle* ptr);
    virtual ~PyIAcadMLeaderStyleImpl() = default;
    IAcadMLeaderStyle* impObj(const std::source_location& src = std::source_location::current()) const;
};

//TODO make iterator
//------------------------------------------------------------------------------------
//PyIAcadBlockImpl
class PyIAcadBlockImpl : public PyIAcadObjectImpl
{
public:
    explicit PyIAcadBlockImpl(IAcadBlock* ptr);
    virtual ~PyIAcadBlockImpl() = default;

    PyIAcadEntityPtr    GetItem(long ind) const;
    long                GetCount() const;

    IAcadBlock* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadBlockPtr = std::unique_ptr<PyIAcadBlockImpl>;

//------------------------------------------------------------------------------------
//PyIAcadModelSpaceImpl
class PyIAcadModelSpaceImpl : public PyIAcadBlockImpl
{
public:
    explicit PyIAcadModelSpaceImpl(IAcadBlock* ptr);
    virtual ~PyIAcadModelSpaceImpl() = default;
    IAcadModelSpace* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadBlockPtr = std::unique_ptr<PyIAcadBlockImpl>;

//------------------------------------------------------------------------------------
//PyIAcadPaperSpaceImpl
class PyIAcadPaperSpaceImpl : public PyIAcadBlockImpl
{
public:
    explicit PyIAcadPaperSpaceImpl(IAcadBlock* ptr);
    virtual ~PyIAcadPaperSpaceImpl() = default;
    IAcadPaperSpace* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadBlockPtr = std::unique_ptr<PyIAcadBlockImpl>;

//------------------------------------------------------------------------------------
//PyIAcadBlocksImpl
class PyIAcadBlocksImpl : public PyIAcadObjectImpl
{
public:
    explicit PyIAcadBlocksImpl(IAcadBlocks* ptr);
    virtual ~PyIAcadBlocksImpl() = default;
    IAcadBlocks* impObj(const std::source_location& src = std::source_location::current()) const;
};

//------------------------------------------------------------------------------------
//PyIAcadLayoutsImpl
class PyIAcadLayoutsImpl : public PyIAcadObjectImpl
{
public:
    explicit PyIAcadLayoutsImpl(IAcadLayouts* ptr);
    virtual ~PyIAcadLayoutsImpl() = default;
    IAcadLayouts* impObj(const std::source_location& src = std::source_location::current()) const;
};

//------------------------------------------------------------------------------------
//PyIAcadSortentsTableImpl
class PyIAcadSortentsTableImpl : public PyIAcadObjectImpl
{
public:
    explicit PyIAcadSortentsTableImpl(IAcadSortentsTable* ptr);
    virtual ~PyIAcadSortentsTableImpl() = default;
    IAcadSortentsTable* impObj(const std::source_location& src = std::source_location::current()) const;
};

#pragma pack (pop)
